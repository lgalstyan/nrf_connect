/*
 * Copyright (c) 2021, Yonatan Schachter
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Originally this file is generated by pico-sdk, and some files
 * try to include it. Therefore, we have to provide that file,
 * with this exact name.
 * Since this file ends up included in all pico-sdk code, it's
 * used to inject workarounds to make pico-sdk compile with Zephyr.
 */

#ifndef _CONFIG_AUTOGEN_H_
#define _CONFIG_AUTOGEN_H_

/* WORKAROUNDS */

/*
 * static_assert is not supported, so BUILD_ASSERT is used instead.
 * BUILD_ASSERT is included through toolchain.h.
 */
#include <zephyr/toolchain.h>
#if !defined(__cplusplus) && !defined(static_assert)
#define static_assert(expr, msg...) BUILD_ASSERT((expr), "" msg)
#endif /* static_assert && __cplusplus__ */

/* Convert uses of asm, which is not supported in c99, to __asm */
#define asm __asm

/* Disable binary info */
#define PICO_NO_BINARY_INFO 1

/* Zephyr compatible way of forcing inline */
#ifndef __always_inline
#define __always_inline ALWAYS_INLINE
#endif /* __always_inline */

/* Two definitions required for the flash driver */
#define __STRING(x) #x

#ifndef __noinline
#define __noinline __attribute__((noinline))
#endif

#endif
