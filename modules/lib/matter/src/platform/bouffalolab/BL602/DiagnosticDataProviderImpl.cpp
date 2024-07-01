/*
 *
 *    Copyright (c) 2021-2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Provides an implementation of the DiagnosticDataProvider object
 *          for Bouffalolab BL602 platform.
 */

#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <DiagnosticDataProviderImpl.h>
#include <crypto/CHIPCryptoPAL.h>
#include <lib/support/CHIPMemString.h>

#include <lwip/tcpip.h>

extern "C" {
#include <bl60x_fw_api.h>
#include <bl60x_wifi_driver/bl_main.h>
#include <bl60x_wifi_driver/wifi_mgmr.h>
#include <bl_efuse.h>
#include <bl_sys.h>
#include <wifi_mgmr_ext.h>
#include <wifi_mgmr_portable.h>
}

extern uint8_t _heap_size;

namespace chip {
namespace DeviceLayer {

DiagnosticDataProviderImpl & DiagnosticDataProviderImpl::GetDefaultInstance()
{
    static DiagnosticDataProviderImpl sInstance;
    return sInstance;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapFree(uint64_t & currentHeapFree)
{
    size_t freeHeapSize;

    freeHeapSize    = xPortGetFreeHeapSize();
    currentHeapFree = static_cast<uint64_t>(freeHeapSize);
    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapUsed(uint64_t & currentHeapUsed)
{
    currentHeapUsed = (uint32_t) &_heap_size - xPortGetFreeHeapSize();

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapHighWatermark(uint64_t & currentHeapHighWatermark)
{
    currentHeapHighWatermark = (uint32_t) &_heap_size - xPortGetMinimumEverFreeHeapSize();

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetRebootCount(uint16_t & rebootCount)
{
    uint32_t count = 0;

    CHIP_ERROR err = ConfigurationMgr().GetRebootCount(count);

    if (err == CHIP_NO_ERROR)
    {
        VerifyOrReturnError(count <= UINT16_MAX, CHIP_ERROR_INVALID_INTEGER_VALUE);
        rebootCount = static_cast<uint16_t>(count);
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetUpTime(uint64_t & upTime)
{
    System::Clock::Timestamp currentTime = System::SystemClock().GetMonotonicTimestamp();
    System::Clock::Timestamp startTime   = PlatformMgrImpl().GetStartTime();

    if (currentTime >= startTime)
    {
        upTime = std::chrono::duration_cast<System::Clock::Seconds64>(currentTime - startTime).count();
        return CHIP_NO_ERROR;
    }

    return CHIP_ERROR_INVALID_TIME;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetTotalOperationalHours(uint32_t & totalOperationalHours)
{
    uint64_t upTime = 0;

    if (GetUpTime(upTime) == CHIP_NO_ERROR)
    {
        uint32_t totalHours = 0;
        if (ConfigurationMgr().GetTotalOperationalHours(totalHours) == CHIP_NO_ERROR)
        {
            VerifyOrReturnError(upTime / 3600 <= UINT32_MAX, CHIP_ERROR_INVALID_INTEGER_VALUE);
            totalOperationalHours = totalHours + static_cast<uint32_t>(upTime / 3600);
            return CHIP_NO_ERROR;
        }
    }

    return CHIP_ERROR_INVALID_TIME;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetBootReason(BootReasonType & bootReason)
{
    BL_RST_REASON_E BL_RST_REASON = bl_sys_rstinfo_get();

    bootReason = BootReasonType::kUnspecified;

    if (BL_RST_REASON == BL_RST_POWER_OFF)
    {
        bootReason = BootReasonType::kPowerOnReboot;
    }
    else if (BL_RST_REASON == BL_RST_HARDWARE_WATCHDOG)
    {
        bootReason = BootReasonType::kHardwareWatchdogReset;
    }
    else if (BL_RST_REASON == BL_RST_SOFTWARE_WATCHDOG)
    {
        bootReason = BootReasonType::kSoftwareWatchdogReset;
    }
    else if (BL_RST_REASON == BL_RST_SOFTWARE)
    {
        bootReason = BootReasonType::kSoftwareReset;
    }

    return CHIP_NO_ERROR;
}

static int bl_netif_get_all_ip6(struct netif * netif, ip6_addr_t if_ip6[])
{
    if (netif == NULL || if_ip6 == NULL)
    {
        return 0;
    }

    int addr_count = 0;
    for (int i = 0; (i < LWIP_IPV6_NUM_ADDRESSES) && (i < kMaxIPv6AddrCount); i++)
    {
        if (!ip_addr_cmp(&netif->ip6_addr[i], IP6_ADDR_ANY))
        {
            memcpy(&if_ip6[addr_count++], &netif->ip6_addr[i], sizeof(ip6_addr_t));
        }
    }

    return addr_count;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetNetworkInterfaces(NetworkInterface ** netifpp)
{
    NetworkInterface * ifp = new NetworkInterface();
    struct netif * netif;

    netif = wifi_mgmr_sta_netif_get();
    if (netif)
    {
        Platform::CopyString(ifp->Name, netif->name);
        ifp->name          = CharSpan::fromCharString(ifp->Name);
        ifp->isOperational = true;
        ifp->type          = EMBER_ZCL_INTERFACE_TYPE_ENUM_WI_FI;
        ifp->offPremiseServicesReachableIPv4.SetNull();
        ifp->offPremiseServicesReachableIPv6.SetNull();
        bl_efuse_read_mac(ifp->MacAddress);
        ifp->hardwareAddress = ByteSpan(ifp->MacAddress, 6);

        uint32_t ip, gw, mask;
        wifi_mgmr_sta_ip_get(&ip, &gw, &mask);
        memcpy(ifp->Ipv4AddressesBuffer[0], &ip, kMaxIPv4AddrSize);
        ifp->Ipv4AddressSpans[0] = ByteSpan(ifp->Ipv4AddressesBuffer[0], kMaxIPv4AddrSize);
        ifp->IPv4Addresses       = chip::app::DataModel::List<chip::ByteSpan>(ifp->Ipv4AddressSpans, 1);

        uint8_t ipv6_addr_count = 0;
        ip6_addr_t ip6_addr[kMaxIPv6AddrCount];
        ipv6_addr_count = bl_netif_get_all_ip6(netif, ip6_addr);
        for (uint8_t idx = 0; idx < ipv6_addr_count; ++idx)
        {
            memcpy(ifp->Ipv6AddressesBuffer[idx], ip6_addr[idx].addr, kMaxIPv6AddrSize);
            ifp->Ipv6AddressSpans[idx] = ByteSpan(ifp->Ipv6AddressesBuffer[idx], kMaxIPv6AddrSize);
        }
        ifp->IPv6Addresses = chip::app::DataModel::List<chip::ByteSpan>(ifp->Ipv6AddressSpans, ipv6_addr_count);
    }

    *netifpp = ifp;

    return CHIP_NO_ERROR;
}

void DiagnosticDataProviderImpl::ReleaseNetworkInterfaces(NetworkInterface * netifp)
{
    while (netifp)
    {
        NetworkInterface * del = netifp;
        netifp                 = netifp->Next;
        delete del;
    }
}

DiagnosticDataProvider & GetDiagnosticDataProviderImpl()
{
    return DiagnosticDataProviderImpl::GetDefaultInstance();
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBssId(MutableByteSpan & BssId)
{
    return CopySpanToMutableSpan(ByteSpan(wifiMgmr.wifi_mgmr_stat_info.bssid), BssId);
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiSecurityType(app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum & securityType)
{
    if (ConnectivityMgrImpl()._IsWiFiStationConnected())
    {
        if (wifi_mgmr_security_type_is_open())
        {
            securityType = app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum::kNone;
        }
        else if (wifi_mgmr_security_type_is_wpa())
        {
            securityType = app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum::kWpa;
        }
        else if (wifi_mgmr_security_type_is_wpa2())
        {
            securityType = app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum::kWpa2;
        }
        else if (wifi_mgmr_security_type_is_wpa3())
        {
            securityType = app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum::kWpa3;
        }
        else
        {
            securityType = app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum::kWep;
        }

        return CHIP_NO_ERROR;
    }

    return CHIP_ERROR_READ_FAILED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiVersion(app::Clusters::WiFiNetworkDiagnostics::WiFiVersionEnum & wifiVersion)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiChannelNumber(uint16_t & channelNumber)
{
    if (ConnectivityMgrImpl()._IsWiFiStationConnected())
    {
        channelNumber = wifiMgmr.channel;
        return CHIP_NO_ERROR;
    }

    return CHIP_ERROR_READ_FAILED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiRssi(int8_t & rssi)
{
    if (ConnectivityMgrImpl()._IsWiFiStationConnected())
    {
        rssi = wifiMgmr.wlan_sta.sta.rssi;
        return CHIP_NO_ERROR;
    }

    return CHIP_ERROR_READ_FAILED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBeaconLostCount(uint32_t & beaconLostCount)
{
    wifi_diagnosis_info_t * info;

    info = bl_diagnosis_get();
    if (info)
    {
        beaconLostCount = info->beacon_loss;
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiCurrentMaxRate(uint64_t & currentMaxRate)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketMulticastRxCount(uint32_t & packetMulticastRxCount)
{
    wifi_diagnosis_info_t * info;

    info = bl_diagnosis_get();
    if (info)
    {
        packetMulticastRxCount = info->multicast_recv;
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketMulticastTxCount(uint32_t & packetMulticastTxCount)
{
    wifi_diagnosis_info_t * info;

    info = bl_diagnosis_get();
    if (info)
    {
        packetMulticastTxCount = info->multicast_send;
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketUnicastRxCount(uint32_t & packetUnicastRxCount)
{
    wifi_diagnosis_info_t * info;

    info = bl_diagnosis_get();
    if (info)
    {
        packetUnicastRxCount = info->unicast_recv;
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketUnicastTxCount(uint32_t & packetUnicastTxCount)
{
    wifi_diagnosis_info_t * info;

    info = bl_diagnosis_get();
    if (info)
    {
        packetUnicastTxCount = info->multicast_send;
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiOverrunCount(uint64_t & overrunCount)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR DiagnosticDataProviderImpl::ResetWiFiNetworkDiagnosticsCounts()
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBeaconRxCount(uint32_t & beaconRxCount)
{
    wifi_diagnosis_info_t * info;

    info = bl_diagnosis_get();
    if (info)
    {
        beaconRxCount = info->beacon_recv;
    }

    return CHIP_NO_ERROR;
}

} // namespace DeviceLayer
wifi_diagnosis_info_t * info;
} // namespace chip