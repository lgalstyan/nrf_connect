/*
 *
 *    Copyright (c) 2023 Project CHIP Authors
 *    All rights reserved.
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

#pragma once

// ---- Window App Example Config ----

#define APP_USE_EXAMPLE_START_BUTTON 0
#define APP_USE_THREAD_START_BUTTON 0
#define APP_SET_DEVICE_INFO_PROVIDER 1
#define APP_SET_NETWORK_COMM_ENDPOINT_SEC 0
#define APP_USE_IDENTIFY_PWM 1 // APP_USE_IDENTIFY_PWM must be defined before including "AppConfigCommon.h"

#include "AppConfigCommon.h"
#define LIGHTING_PWM_SPEC_RGB_BLUE PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0))

// NOTE: pwm_led1 by default DTS is used by PE0, so get an external LED connected to that pin
#define LIGHTING_PWM_SPEC_RGB_GREEN PWM_DT_SPEC_GET(DT_ALIAS(pwm_led1))
