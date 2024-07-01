# SPDX-License-Identifier: Apache-2.0

zephyr_get(XTENSA_TOOLCHAIN_PATH)
assert(    XTENSA_TOOLCHAIN_PATH "XTENSA_TOOLCHAIN_PATH is not set")

if(NOT EXISTS ${XTENSA_TOOLCHAIN_PATH})
  message(FATAL_ERROR "Nothing found at XTENSA_TOOLCHAIN_PATH: '${XTENSA_TOOLCHAIN_PATH}'")
endif()

set(TOOLCHAIN_HOME ${XTENSA_TOOLCHAIN_PATH}/$ENV{TOOLCHAIN_VER}/XtensaTools)

set(LINKER ld)
set(BINTOOLS gnu)

set(CROSS_COMPILE_TARGET xt)
set(SYSROOT_TARGET       xtensa-elf)

set(CROSS_COMPILE  ${TOOLCHAIN_HOME}/bin/${CROSS_COMPILE_TARGET}-)
set(SYSROOT_DIR    ${TOOLCHAIN_HOME}/${SYSROOT_TARGET})

set(NOSYSDEF_CFLAG "")

list(APPEND TOOLCHAIN_C_FLAGS -fms-extensions)

set(TOOLCHAIN_HAS_NEWLIB OFF CACHE BOOL "True if toolchain supports newlib")
