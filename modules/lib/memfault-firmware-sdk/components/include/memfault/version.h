#pragma once

//! @file
//!
//! Copyright (c) Memfault, Inc.
//! See License.txt for details
//!
//! Contains Memfault SDK version information.

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
  uint8_t major;
  uint8_t minor;
  uint8_t patch;
} sMfltSdkVersion;

#define MEMFAULT_SDK_VERSION   { .major = 1, .minor = 3, .patch = 3 }
#define MEMFAULT_SDK_VERSION_STR "1.3.3"

#ifdef __cplusplus
}
#endif
