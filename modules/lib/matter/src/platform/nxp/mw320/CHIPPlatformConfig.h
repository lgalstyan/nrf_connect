/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2020 Google LLC.
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

/**
 *    @file
 *          Platform-specific configuration overrides for CHIP on
 *          NXP MW320 platforms.
 */

#pragma once

#include <stdint.h>

// ==================== General Platform Adaptations ====================

#define CHIP_CONFIG_ERROR_TYPE int32_t
#define CHIP_CONFIG_ERROR_FORMAT PRId32
#define CHIP_CONFIG_NO_ERROR 0
#define CHIP_CONFIG_ERROR_MIN 4000000
#define CHIP_CONFIG_ERROR_MAX 4000999

#define ASN1_CONFIG_ERROR_TYPE int32_t
#define ASN1_CONFIG_NO_ERROR 0

#define ChipDie() abort()

#ifndef CHIP_CONFIG_PERSISTED_STORAGE_KEY_TYPE
#define CHIP_CONFIG_PERSISTED_STORAGE_KEY_TYPE const char *
#endif
#define CHIP_CONFIG_PERSISTED_STORAGE_KEY_GLOBAL_MESSAGE_COUNTER 0x2

#define CHIP_CONFIG_TIME_ENABLE_CLIENT 1
#define CHIP_CONFIG_TIME_ENABLE_SERVER 0

// ==================== Security Adaptations ====================

#define CHIP_CONFIG_USE_OPENSSL_ECC 0
#define CHIP_CONFIG_USE_MICRO_ECC 0

#define CHIP_CONFIG_HASH_IMPLEMENTATION_OPENSSL 0
#define CHIP_CONFIG_HASH_IMPLEMENTATION_MINCRYPT 1
#define CHIP_CONFIG_HASH_IMPLEMENTATION_MBEDTLS 0
#define CHIP_CONFIG_HASH_IMPLEMENTATION_PLATFORM 0

#define CHIP_CONFIG_AES_IMPLEMENTATION_OPENSSL 0
#define CHIP_CONFIG_AES_IMPLEMENTATION_AESNI 0
#define CHIP_CONFIG_AES_IMPLEMENTATION_MBEDTLS 0
#define CHIP_CONFIG_AES_IMPLEMENTATION_PLATFORM 1

#define CHIP_CONFIG_RNG_IMPLEMENTATION_OPENSSL 0
#define CHIP_CONFIG_RNG_IMPLEMENTATION_CHIPDRBG 1
#define CHIP_CONFIG_RNG_IMPLEMENTATION_PLATFORM 0

#define CHIP_CONFIG_ENABLE_PASE_INITIATOR 0
#define CHIP_CONFIG_ENABLE_PASE_RESPONDER 1
#define CHIP_CONFIG_ENABLE_CASE_INITIATOR 1

#define CHIP_CONFIG_SUPPORT_PASE_CONFIG0 0
#define CHIP_CONFIG_SUPPORT_PASE_CONFIG1 0
#define CHIP_CONFIG_SUPPORT_PASE_CONFIG2 0
#define CHIP_CONFIG_SUPPORT_PASE_CONFIG3 0
#define CHIP_CONFIG_SUPPORT_PASE_CONFIG4 1

#define CHIP_CONFIG_ENABLE_KEY_EXPORT_INITIATOR 0

#define CHIP_CONFIG_ENABLE_PROVISIONING_BUNDLE_SUPPORT 0

// ==================== General Configuration Overrides ====================

#ifndef CHIP_CONFIG_MAX_PEER_NODES
#define CHIP_CONFIG_MAX_PEER_NODES 16
#endif // CHIP_CONFIG_MAX_PEER_NODES

#ifndef CHIP_CONFIG_MAX_UNSOLICITED_MESSAGE_HANDLERS
#define CHIP_CONFIG_MAX_UNSOLICITED_MESSAGE_HANDLERS 16
#endif // CHIP_CONFIG_MAX_UNSOLICITED_MESSAGE_HANDLERS

#ifndef CHIP_CONFIG_MAX_EXCHANGE_CONTEXTS
#define CHIP_CONFIG_MAX_EXCHANGE_CONTEXTS 8
#endif // CHIP_CONFIG_MAX_EXCHANGE_CONTEXTS

#ifndef CHIP_CONFIG_RMP_TIMER_DEFAULT_PERIOD_SHIFT
#define CHIP_CONFIG_RMP_TIMER_DEFAULT_PERIOD_SHIFT 6
#endif // CHIP_CONFIG_RMP_TIMER_DEFAULT_PERIOD_SHIFT

#ifndef CHIP_LOG_FILTERING
#define CHIP_LOG_FILTERING 0
#endif // CHIP_LOG_FILTERING

#ifndef CHIP_CONFIG_BDX_MAX_NUM_TRANSFERS
#define CHIP_CONFIG_BDX_MAX_NUM_TRANSFERS 1
#endif // CHIP_CONFIG_BDX_MAX_NUM_TRANSFERS

// ==================== Security Configuration Overrides ====================

#ifndef CHIP_CONFIG_MAX_APPLICATION_GROUPS
#define CHIP_CONFIG_MAX_APPLICATION_GROUPS 4
#endif // CHIP_CONFIG_MAX_APPLICATION_GROUPS

#ifndef CHIP_CONFIG_DEBUG_CERT_VALIDATION
#define CHIP_CONFIG_DEBUG_CERT_VALIDATION 0
#endif // CHIP_CONFIG_DEBUG_CERT_VALIDATION

#ifndef CHIP_CONFIG_ENABLE_CASE_RESPONDER
#define CHIP_CONFIG_ENABLE_CASE_RESPONDER 1
#endif // CHIP_CONFIG_ENABLE_CASE_RESPONDER

// ==================== WDM Configuration Overrides ====================

#ifndef WDM_MAX_NUM_SUBSCRIPTION_CLIENTS
#define WDM_MAX_NUM_SUBSCRIPTION_CLIENTS 2
#endif // WDM_MAX_NUM_SUBSCRIPTION_CLIENTS

#ifndef WDM_MAX_NUM_SUBSCRIPTION_HANDLERS
#define WDM_MAX_NUM_SUBSCRIPTION_HANDLERS 2
#endif // WDM_MAX_NUM_SUBSCRIPTION_HANDLERS

#ifndef WDM_PUBLISHER_MAX_NOTIFIES_IN_FLIGHT
#define WDM_PUBLISHER_MAX_NOTIFIES_IN_FLIGHT 2
#endif // WDM_PUBLISHER_MAX_NOTIFIES_IN_FLIGHT
