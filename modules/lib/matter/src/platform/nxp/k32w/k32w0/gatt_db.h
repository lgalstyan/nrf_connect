PRIMARY_SERVICE(service_gatt, gBleSig_GenericAttributeProfile_d)
CHARACTERISTIC(char_service_changed, gBleSig_GattServiceChanged_d, (gGattCharPropRead_c | gGattCharPropNotify_c))
VALUE(value_service_changed, gBleSig_GattServiceChanged_d, (gPermissionNone_c), 4, 0x00, 0x00, 0x00, 0x00)
CCCD(cccd_service_changed)

PRIMARY_SERVICE(service_gap, gBleSig_GenericAccessProfile_d)
CHARACTERISTIC(char_device_name, gBleSig_GapDeviceName_d, (gGattCharPropRead_c))
VALUE(value_device_name, gBleSig_GapDeviceName_d, (gPermissionFlagReadable_c), 18, "NXP_PLATFORM_DEMO")
CHARACTERISTIC(char_appearance, gBleSig_GapAppearance_d, (gGattCharPropRead_c))
VALUE(value_appearance, gBleSig_GapAppearance_d, (gPermissionFlagReadable_c), 2, 0x00, 0x00)

PRIMARY_SERVICE(service_chipoble, gChipoBleService_d)
CHARACTERISTIC_UUID128(chipoble_rx, uuid_chipoble_rx, (gGattCharPropWrite_c))
VALUE_UUID128_VARLEN(value_chipoble_rx, uuid_chipoble_rx, (gPermissionFlagWritable_c), gAttMaxMtu_c - 3, gAttMaxMtu_c - 3, 0x00)
CHARACTERISTIC_UUID128(chipoble_tx, uuid_chipoble_tx, (gGattCharPropIndicate_c | gGattCharPropRead_c))
VALUE_UUID128_VARLEN(value_chipoble_tx, uuid_chipoble_tx, (gPermissionFlagReadable_c), gAttMaxMtu_c - 3, gAttMaxMtu_c - 3, 0x00)
CCCD(cccd_chipoble_tx)
CHARACTERISTIC_UUID128(chipoble_c3, uuid_chipoble_c3, (gGattCharPropRead_c))
VALUE_UUID128_VARLEN(value_chipoble_c3, uuid_chipoble_c3, (gPermissionFlagReadable_c), gAttMaxReadDataSize_d(gAttMaxValueLength_c),
                     gAttMaxReadDataSize_d(gAttMaxValueLength_c), 0x00)

PRIMARY_SERVICE(service_device_info, gBleSig_DeviceInformationService_d)
CHARACTERISTIC(char_model_no, gBleSig_ModelNumberString_d, (gGattCharPropRead_c))
VALUE(value_model_no, gBleSig_ModelNumberString_d, (gPermissionFlagReadable_c), 16, "Chip K32W0 Demo")
CHARACTERISTIC(char_serial_no, gBleSig_SerialNumberString_d, (gGattCharPropRead_c))
VALUE(value_serial_no, gBleSig_SerialNumberString_d, (gPermissionFlagReadable_c), 7, "BLESN01")
CHARACTERISTIC(char_fw_rev, gBleSig_FirmwareRevisionString_d, (gGattCharPropRead_c))
VALUE(value_fw_rev, gBleSig_FirmwareRevisionString_d, (gPermissionFlagReadable_c), 5, "1.1.1")
CHARACTERISTIC(char_sw_rev, gBleSig_SoftwareRevisionString_d, (gGattCharPropRead_c))
VALUE(value_sw_rev, gBleSig_SoftwareRevisionString_d, (gPermissionFlagReadable_c), 5, "1.1.4")
