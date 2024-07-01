set(mcuboot_EXTRA_ZEPHYR_MODULES "${CMAKE_CURRENT_LIST_DIR}/test_module" CACHE INTERNAL "test_module directory")

if(DEFINED mcuboot_TARGET_OVERLAY_CONFIG)
  list(APPEND mcuboot_OVERLAY_CONFIG "${CMAKE_CURRENT_LIST_DIR}/sysbuild/mcuboot/${mcuboot_TARGET_OVERLAY_CONFIG}")
  list(REMOVE_DUPLICATES mcuboot_OVERLAY_CONFIG)
  set(mcuboot_OVERLAY_CONFIG "${mcuboot_OVERLAY_CONFIG}" CACHE INTERNAL "")
endif()

if(DEFINED mcuboot_TARGET_DTC_OVERLAY_FILE)
  list(APPEND mcuboot_DTC_OVERLAY_FILE "${CMAKE_CURRENT_LIST_DIR}/sysbuild/mcuboot/${mcuboot_TARGET_DTC_OVERLAY_FILE}")
  list(REMOVE_DUPLICATES mcuboot_DTC_OVERLAY_FILE)
  set(mcuboot_DTC_OVERLAY_FILE "${mcuboot_DTC_OVERLAY_FILE}" CACHE INTERNAL "")
endif()
