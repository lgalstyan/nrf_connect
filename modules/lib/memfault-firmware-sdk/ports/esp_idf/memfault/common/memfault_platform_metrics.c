//! @file
//!
//! Copyright (c) Memfault, Inc.
//! See License.txt for details
//!
//! A port of dependency functions for Memfault metrics subsystem using FreeRTOS.
//!
//! @note For test purposes, the heartbeat interval can be changed to a faster period
//! by using the following CFLAG:
//!   -DMEMFAULT_METRICS_HEARTBEAT_INTERVAL_SECS=15

#include "esp_event.h"
#include "esp_timer.h"
#include "esp_wifi.h"
#include "esp_wifi_types.h"
#include "memfault/core/math.h"
#include "memfault/core/reboot_tracking.h"
#include "memfault/esp_port/metrics.h"
#include "memfault/esp_port/version.h"
#include "memfault/metrics/metrics.h"
#include "memfault/metrics/platform/timer.h"
#include "sdkconfig.h"

#if CONFIG_MEMFAULT_LWIP_METRICS
  #include "memfault/ports/lwip/metrics.h"
#endif  // CONFIG_MEMFAULT_LWIP_METRICS

#if CONFIG_MEMFAULT_FREERTOS_TASK_RUNTIME_STATS
  #include "memfault/ports/freertos/metrics.h"
#endif  // CONFIG_MEMFAULT_FREERTOS_TASK_RUNTIME_STATS

#if CONFIG_MEMFAULT_MBEDTLS_METRICS
  #include "memfault/ports/mbedtls/metrics.h"
#endif  // CONFIG_MEMFAULT_MBEDTLS_METRICS

#if CONFIG_MEMFAULT_ESP_WIFI_METRICS

  #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
int32_t s_min_rssi;
  #endif  // ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)

  #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
    // This is a practical maximum RSSI value. In reality, the RSSI value is
    // will likely be much lower. A value in the mid -60s is considered very good
    // for example. An RSSI of -20 would be a device essentially on top of the AP.
    #define MAXIMUM_RSSI -10
  #endif  // ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
#endif    // CONFIG_MEMFAULT_ESP_WIFI_METRICS

MEMFAULT_WEAK
void memfault_esp_metric_timer_dispatch(MemfaultPlatformTimerCallback handler) {
  if (handler == NULL) {
    return;
  }
  handler();
}

static void prv_metric_timer_handler(void *arg) {
  memfault_reboot_tracking_reset_crash_count();

  // NOTE: This timer runs once per MEMFAULT_METRICS_HEARTBEAT_INTERVAL_SECS where the default is
  // once per hour.
  MemfaultPlatformTimerCallback *metric_timer_handler = (MemfaultPlatformTimerCallback *)arg;
  memfault_esp_metric_timer_dispatch(metric_timer_handler);
}

#if CONFIG_MEMFAULT_ESP_WIFI_METRICS
static void metric_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id,
                                 void *event_data) {
  #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
  wifi_event_bss_rssi_low_t *rssi_data;
  #endif  // ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)

  switch (event_id) {
    case WIFI_EVENT_STA_CONNECTED:
  #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
      // The RSSI threshold needs to be set when WIFI is already initialized.
      // This event is the most reliable way to know that we're already in that
      // state.
      ESP_ERROR_CHECK(esp_wifi_set_rssi_threshold(MAXIMUM_RSSI));
  #endif  // ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
      memfault_metrics_heartbeat_timer_start(MEMFAULT_METRICS_KEY(wifi_connected_time_ms));
      break;
    case WIFI_EVENT_STA_DISCONNECTED:
      memfault_metrics_heartbeat_add(MEMFAULT_METRICS_KEY(wifi_disconnect_count), 1);
      memfault_metrics_heartbeat_timer_stop(MEMFAULT_METRICS_KEY(wifi_connected_time_ms));

      break;
  #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
    case WIFI_EVENT_STA_BSS_RSSI_LOW:
      rssi_data = (wifi_event_bss_rssi_low_t *)event_data;

      s_min_rssi = MEMFAULT_MIN(rssi_data->rssi, s_min_rssi);
      esp_wifi_set_rssi_threshold(s_min_rssi);
      break;
  #endif  // ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
    default:
      break;
  }
}

static void prv_register_event_handler(void) {
  ESP_ERROR_CHECK_WITHOUT_ABORT(esp_event_loop_create_default());

  ESP_ERROR_CHECK(
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &metric_event_handler, NULL));
}

static void prv_collect_wifi_metrics(void) {
  #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
  if (s_min_rssi <= MAXIMUM_RSSI) {
    memfault_metrics_heartbeat_set_signed(MEMFAULT_METRICS_KEY(wifi_sta_min_rssi), s_min_rssi);
    // Error checking is ignored here, as it's possible that WIFI is not
    // intialized yet at time of heartbeat. In that case, the RSSI threshold
    // will be set reset on the first connection, and any errors here can be
    // safely ignored.
    (void)esp_wifi_set_rssi_threshold(MAXIMUM_RSSI);
    s_min_rssi = 0;
  }
  #endif  // ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 3, 0)
}
#endif  // CONFIG_MEMFAULT_ESP_WIFI_METRICS

bool memfault_platform_metrics_timer_boot(uint32_t period_sec,
                                          MemfaultPlatformTimerCallback callback) {
  const esp_timer_create_args_t periodic_timer_args = {
    .callback = &prv_metric_timer_handler,
    .arg = callback,
    .name = "mflt",
  };

  // Ignore return value; this function should be safe to call multiple times
  // during system init, but needs to called before we create any timers.
  // See implementation here (may change by esp-idf version!):
  // https://github.com/espressif/esp-idf/blob/master/components/esp_timer/src/esp_timer.c#L431-L460
  (void)esp_timer_init();

  esp_timer_handle_t periodic_timer;
  ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));

  const int64_t us_per_sec = 1000000;
  ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, period_sec * us_per_sec));

#if CONFIG_MEMFAULT_ESP_WIFI_METRICS
  prv_register_event_handler();
#endif  // CONFIG_MEMFAULT_ESP_WIFI_METRICS

  return true;
}

void memfault_metrics_heartbeat_collect_sdk_data(void) {
#if CONFIG_MEMFAULT_LWIP_METRICS
  memfault_lwip_heartbeat_collect_data();
#endif  // CONFIG_MEMFAULT_LWIP_METRICS

#ifdef CONFIG_MEMFAULT_FREERTOS_TASK_RUNTIME_STATS
  MEMFAULT_STATIC_ASSERT(
    MEMFAULT_METRICS_HEARTBEAT_INTERVAL_SECS <= (60 * 60),
    "Heartbeat must be an hour or less for runtime metrics to mitigate counter overflow");

  memfault_freertos_port_task_runtime_metrics();
#endif  // CONFIG_MEMFAULT_FREERTOS_TASK_RUNTIME_STATS

#if CONFIG_MEMFAULT_MBEDTLS_METRICS
  memfault_mbedtls_heartbeat_collect_data();
#endif  // CONFIG_MEMFAULT_MBEDTLS_METRICS

#if CONFIG_MEMFAULT_ESP_WIFI_METRICS
  prv_collect_wifi_metrics();
#endif  // CONFIG_MEMFAULT_ESP_WIFI_METRICS
}
