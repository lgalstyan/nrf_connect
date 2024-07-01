/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

// Prevent multiple inclusion
#pragma once

/**** Cluster endpoint counts ****/
#define EMBER_AF_IDENTIFY_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUPS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_SCENES_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_SWITCH_CONFIGURATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_LEVEL_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BINARY_INPUT_BASIC_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_DESCRIPTOR_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BINDING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ACCESS_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ACTIONS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BASIC_INFORMATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_OTA_SOFTWARE_UPDATE_PROVIDER_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_OTA_SOFTWARE_UPDATE_REQUESTOR_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_LOCALIZATION_CONFIGURATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_TIME_FORMAT_LOCALIZATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_UNIT_LOCALIZATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_POWER_SOURCE_CONFIGURATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_POWER_SOURCE_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_GENERAL_COMMISSIONING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_NETWORK_COMMISSIONING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_DIAGNOSTIC_LOGS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_GENERAL_DIAGNOSTICS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_SOFTWARE_DIAGNOSTICS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_THREAD_NETWORK_DIAGNOSTICS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_WIFI_NETWORK_DIAGNOSTICS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ETHERNET_NETWORK_DIAGNOSTICS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BRIDGED_DEVICE_BASIC_INFORMATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_SWITCH_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ADMINISTRATOR_COMMISSIONING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_OPERATIONAL_CREDENTIALS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUP_KEY_MANAGEMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_FIXED_LABEL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_USER_LABEL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BOOLEAN_STATE_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_MODE_SELECT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_DOOR_LOCK_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_WINDOW_COVERING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BARRIER_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_PUMP_CONFIGURATION_AND_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_THERMOSTAT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_FAN_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_THERMOSTAT_USER_INTERFACE_CONFIGURATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_COLOR_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BALLAST_CONFIGURATION_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ILLUMINANCE_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_PRESSURE_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_FLOW_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_OCCUPANCY_SENSING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_WAKE_ON_LAN_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_CHANNEL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_TARGET_NAVIGATOR_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_MEDIA_PLAYBACK_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_MEDIA_INPUT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_LOW_POWER_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_KEYPAD_INPUT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_CONTENT_LAUNCHER_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_AUDIO_OUTPUT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_APPLICATION_LAUNCHER_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_APPLICATION_BASIC_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ACCOUNT_LOGIN_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ELECTRICAL_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_CLIENT_MONITORING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_UNIT_TESTING_CLUSTER_CLIENT_ENDPOINT_COUNT (1)

/**** Cluster Plugins ****/

// Use this macro to check if the client side of the Identify cluster is included
#define ZCL_USING_IDENTIFY_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_IDENTIFY_CLIENT

// Use this macro to check if the client side of the Groups cluster is included
#define ZCL_USING_GROUPS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_GROUPS_CLIENT

// Use this macro to check if the client side of the Scenes cluster is included
#define ZCL_USING_SCENES_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_SCENES_CLIENT

// Use this macro to check if the client side of the On/Off cluster is included
#define ZCL_USING_ON_OFF_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ON_OFF_CLIENT

// Use this macro to check if the client side of the On/off Switch Configuration cluster is included
#define ZCL_USING_ON_OFF_SWITCH_CONFIGURATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ON_OFF_SWITCH_CONFIGURATION_CLIENT

// Use this macro to check if the client side of the Level Control cluster is included
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_CLIENT

// Use this macro to check if the client side of the Binary Input (Basic) cluster is included
#define ZCL_USING_BINARY_INPUT_BASIC_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BINARY_INPUT_BASIC_CLIENT

// Use this macro to check if the client side of the Descriptor cluster is included
#define ZCL_USING_DESCRIPTOR_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_DESCRIPTOR_CLIENT

// Use this macro to check if the client side of the Binding cluster is included
#define ZCL_USING_BINDING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BINDING_CLIENT

// Use this macro to check if the client side of the Access Control cluster is included
#define ZCL_USING_ACCESS_CONTROL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ACCESS_CONTROL_CLIENT

// Use this macro to check if the client side of the Actions cluster is included
#define ZCL_USING_ACTIONS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ACTIONS_CLIENT

// Use this macro to check if the client side of the Basic Information cluster is included
#define ZCL_USING_BASIC_INFORMATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BASIC_INFORMATION_CLIENT

// Use this macro to check if the client side of the OTA Software Update Provider cluster is included
#define ZCL_USING_OTA_SOFTWARE_UPDATE_PROVIDER_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_OTA_SOFTWARE_UPDATE_PROVIDER_CLIENT

// Use this macro to check if the client side of the OTA Software Update Requestor cluster is included
#define ZCL_USING_OTA_SOFTWARE_UPDATE_REQUESTOR_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_OTA_SOFTWARE_UPDATE_REQUESTOR_CLIENT

// Use this macro to check if the client side of the Localization Configuration cluster is included
#define ZCL_USING_LOCALIZATION_CONFIGURATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_LOCALIZATION_CONFIGURATION_CLIENT

// Use this macro to check if the client side of the Time Format Localization cluster is included
#define ZCL_USING_TIME_FORMAT_LOCALIZATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_TIME_FORMAT_LOCALIZATION_CLIENT

// Use this macro to check if the client side of the Unit Localization cluster is included
#define ZCL_USING_UNIT_LOCALIZATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_UNIT_LOCALIZATION_CLIENT

// Use this macro to check if the client side of the Power Source Configuration cluster is included
#define ZCL_USING_POWER_SOURCE_CONFIGURATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_POWER_SOURCE_CONFIGURATION_CLIENT

// Use this macro to check if the client side of the Power Source cluster is included
#define ZCL_USING_POWER_SOURCE_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_POWER_SOURCE_CLIENT

// Use this macro to check if the client side of the General Commissioning cluster is included
#define ZCL_USING_GENERAL_COMMISSIONING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_GENERAL_COMMISSIONING_CLIENT

// Use this macro to check if the client side of the Network Commissioning cluster is included
#define ZCL_USING_NETWORK_COMMISSIONING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_NETWORK_COMMISSIONING_CLIENT

// Use this macro to check if the client side of the Diagnostic Logs cluster is included
#define ZCL_USING_DIAGNOSTIC_LOGS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_DIAGNOSTIC_LOGS_CLIENT

// Use this macro to check if the client side of the General Diagnostics cluster is included
#define ZCL_USING_GENERAL_DIAGNOSTICS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_GENERAL_DIAGNOSTICS_CLIENT

// Use this macro to check if the client side of the Software Diagnostics cluster is included
#define ZCL_USING_SOFTWARE_DIAGNOSTICS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_SOFTWARE_DIAGNOSTICS_CLIENT

// Use this macro to check if the client side of the Thread Network Diagnostics cluster is included
#define ZCL_USING_THREAD_NETWORK_DIAGNOSTICS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_THREAD_NETWORK_DIAGNOSTICS_CLIENT

// Use this macro to check if the client side of the WiFi Network Diagnostics cluster is included
#define ZCL_USING_WIFI_NETWORK_DIAGNOSTICS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_WI_FI_NETWORK_DIAGNOSTICS_CLIENT

// Use this macro to check if the client side of the Ethernet Network Diagnostics cluster is included
#define ZCL_USING_ETHERNET_NETWORK_DIAGNOSTICS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ETHERNET_NETWORK_DIAGNOSTICS_CLIENT

// Use this macro to check if the client side of the Bridged Device Basic Information cluster is included
#define ZCL_USING_BRIDGED_DEVICE_BASIC_INFORMATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BRIDGED_DEVICE_BASIC_INFORMATION_CLIENT

// Use this macro to check if the client side of the Switch cluster is included
#define ZCL_USING_SWITCH_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_SWITCH_CLIENT

// Use this macro to check if the client side of the Administrator Commissioning cluster is included
#define ZCL_USING_ADMINISTRATOR_COMMISSIONING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ADMINISTRATOR_COMMISSIONING_CLIENT

// Use this macro to check if the client side of the Operational Credentials cluster is included
#define ZCL_USING_OPERATIONAL_CREDENTIALS_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_OPERATIONAL_CREDENTIALS_CLIENT

// Use this macro to check if the client side of the Group Key Management cluster is included
#define ZCL_USING_GROUP_KEY_MANAGEMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_GROUP_KEY_MANAGEMENT_CLIENT

// Use this macro to check if the client side of the Fixed Label cluster is included
#define ZCL_USING_FIXED_LABEL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_FIXED_LABEL_CLIENT

// Use this macro to check if the client side of the User Label cluster is included
#define ZCL_USING_USER_LABEL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_USER_LABEL_CLIENT

// Use this macro to check if the client side of the Boolean State cluster is included
#define ZCL_USING_BOOLEAN_STATE_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BOOLEAN_STATE_CLIENT

// Use this macro to check if the client side of the Mode Select cluster is included
#define ZCL_USING_MODE_SELECT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_MODE_SELECT_CLIENT

// Use this macro to check if the client side of the Door Lock cluster is included
#define ZCL_USING_DOOR_LOCK_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_DOOR_LOCK_CLIENT

// Use this macro to check if the client side of the Window Covering cluster is included
#define ZCL_USING_WINDOW_COVERING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_WINDOW_COVERING_CLIENT

// Use this macro to check if the client side of the Barrier Control cluster is included
#define ZCL_USING_BARRIER_CONTROL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BARRIER_CONTROL_CLIENT

// Use this macro to check if the client side of the Pump Configuration and Control cluster is included
#define ZCL_USING_PUMP_CONFIGURATION_AND_CONTROL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_PUMP_CONFIGURATION_AND_CONTROL_CLIENT

// Use this macro to check if the client side of the Thermostat cluster is included
#define ZCL_USING_THERMOSTAT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_THERMOSTAT_CLIENT

// Use this macro to check if the client side of the Fan Control cluster is included
#define ZCL_USING_FAN_CONTROL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_FAN_CONTROL_CLIENT

// Use this macro to check if the client side of the Thermostat User Interface Configuration cluster is included
#define ZCL_USING_THERMOSTAT_USER_INTERFACE_CONFIGURATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_THERMOSTAT_USER_INTERFACE_CONFIGURATION_CLIENT

// Use this macro to check if the client side of the Color Control cluster is included
#define ZCL_USING_COLOR_CONTROL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_COLOR_CONTROL_CLIENT

// Use this macro to check if the client side of the Ballast Configuration cluster is included
#define ZCL_USING_BALLAST_CONFIGURATION_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_BALLAST_CONFIGURATION_CLIENT

// Use this macro to check if the client side of the Illuminance Measurement cluster is included
#define ZCL_USING_ILLUMINANCE_MEASUREMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ILLUMINANCE_MEASUREMENT_CLIENT

// Use this macro to check if the client side of the Temperature Measurement cluster is included
#define ZCL_USING_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_CLIENT

// Use this macro to check if the client side of the Pressure Measurement cluster is included
#define ZCL_USING_PRESSURE_MEASUREMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_PRESSURE_MEASUREMENT_CLIENT

// Use this macro to check if the client side of the Flow Measurement cluster is included
#define ZCL_USING_FLOW_MEASUREMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_FLOW_MEASUREMENT_CLIENT

// Use this macro to check if the client side of the Relative Humidity Measurement cluster is included
#define ZCL_USING_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_RELATIVE_HUMIDITY_MEASUREMENT_CLIENT

// Use this macro to check if the client side of the Occupancy Sensing cluster is included
#define ZCL_USING_OCCUPANCY_SENSING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_OCCUPANCY_SENSING_CLIENT

// Use this macro to check if the client side of the Wake on LAN cluster is included
#define ZCL_USING_WAKE_ON_LAN_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_WAKE_ON_LAN_CLIENT

// Use this macro to check if the client side of the Channel cluster is included
#define ZCL_USING_CHANNEL_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_CHANNEL_CLIENT

// Use this macro to check if the client side of the Target Navigator cluster is included
#define ZCL_USING_TARGET_NAVIGATOR_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_TARGET_NAVIGATOR_CLIENT

// Use this macro to check if the client side of the Media Playback cluster is included
#define ZCL_USING_MEDIA_PLAYBACK_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_MEDIA_PLAYBACK_CLIENT

// Use this macro to check if the client side of the Media Input cluster is included
#define ZCL_USING_MEDIA_INPUT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_MEDIA_INPUT_CLIENT

// Use this macro to check if the client side of the Low Power cluster is included
#define ZCL_USING_LOW_POWER_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_LOW_POWER_CLIENT

// Use this macro to check if the client side of the Keypad Input cluster is included
#define ZCL_USING_KEYPAD_INPUT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_KEYPAD_INPUT_CLIENT

// Use this macro to check if the client side of the Content Launcher cluster is included
#define ZCL_USING_CONTENT_LAUNCHER_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_CONTENT_LAUNCHER_CLIENT

// Use this macro to check if the client side of the Audio Output cluster is included
#define ZCL_USING_AUDIO_OUTPUT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_AUDIO_OUTPUT_CLIENT

// Use this macro to check if the client side of the Application Launcher cluster is included
#define ZCL_USING_APPLICATION_LAUNCHER_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_APPLICATION_LAUNCHER_CLIENT

// Use this macro to check if the client side of the Application Basic cluster is included
#define ZCL_USING_APPLICATION_BASIC_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_APPLICATION_BASIC_CLIENT

// Use this macro to check if the client side of the Account Login cluster is included
#define ZCL_USING_ACCOUNT_LOGIN_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ACCOUNT_LOGIN_CLIENT

// Use this macro to check if the client side of the Electrical Measurement cluster is included
#define ZCL_USING_ELECTRICAL_MEASUREMENT_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_ELECTRICAL_MEASUREMENT_CLIENT

// Use this macro to check if the client side of the Client Monitoring cluster is included
#define ZCL_USING_CLIENT_MONITORING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_CLIENT_MONITORING_CLIENT

// Use this macro to check if the client side of the Unit Testing cluster is included
#define ZCL_USING_UNIT_TESTING_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_UNIT_TESTING_CLIENT
