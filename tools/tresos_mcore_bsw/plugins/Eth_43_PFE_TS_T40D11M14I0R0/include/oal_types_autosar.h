/* =========================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 * 
 *  Copyright 2019-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
 * ========================================================================= */

#ifndef OAL_TYPES_AUTOSAR_H
#define OAL_TYPES_AUTOSAR_H

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#include "Platform_Types.h"
#include "Mcal.h"
#include "pfe_cfg.h"

#if defined(GCC)
#if !defined(NO_STDINT_H)
    typedef unsigned long long int uint64_t;
    typedef signed long long int int64_t;
#endif
typedef unsigned int size_t;
#endif
typedef signed int errno_t;
typedef signed int int_t;
typedef unsigned int uint_t;
typedef unsigned char bool_t;
typedef char char_t;

#if defined(NO_STDINT_H)
typedef unsigned int uintptr_t;

#ifndef TRUE
#define TRUE true
#endif /* TRUE */

#ifndef FALSE
#define FALSE false
#endif /* FALSE */

#ifndef INT8_MIN
#define INT8_MIN -128
#endif

#ifndef INT8_MAX
#define INT8_MAX 127
#endif

#ifndef UINT8_MIN
#define UINT8_MIN 0U
#endif

#ifndef UINT8_MAX
#define UINT8_MAX 255U
#endif

#ifndef INT16_MIN
#define INT16_MIN -32768
#endif

#ifndef INT16_MAX
#define INT16_MAX 32767
#endif

#ifndef UINT16_MIN
#define UINT16_MIN 0U
#endif

#ifndef UINT16_MAX
#define UINT16_MAX 65535U
#endif

#ifndef INT32_MIN
#define INT32_MIN -2147483648L
#endif

#ifndef INT32_MAX
#define INT32_MAX 2147483647L
#endif

#ifndef UINT32_MIN
#define UINT32_MIN 0U
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 4294967295UL
#endif

#ifndef SIZE_MAX
#define SIZE_MAX 0xffffffffU
#endif

#endif /*defined(NO_STDINT_H)*/

#if defined(PFE_CFG_TARGET_ARCH_i386) || defined(PFE_CFG_TARGET_ARCH_x86) || \
    defined(PFE_CFG_TARGET_ARCH_x86_64) || defined(PFE_CFG_TARGET_ARCH_MIPS_M14k)
    #error Unsupported target architecture
#elif defined(PFE_CFG_TARGET_ARCH_armv7le)
    typedef unsigned uaddr_t;
    typedef unsigned addr_t;
    #define PRINT64         "ll"
    #define PRINTADDR_T     "x"
    #define MAX_ADDR_T_VAL  0xFFFFFFFFUL
    #define UINT_MAX        0xffffffffU
#elif defined(PFE_CFG_TARGET_ARCH_aarch64le)
    typedef unsigned long addr_t;
    #define PRINT64         "ll"
    #define PRINTADDR_T     "llx"
    #define MAX_ADDR_T_VAL  0xFFFFFFFFFFFFFFFFUL
    #define UINT_MAX        0xFFFFFFFFFFFFFFFFUL
#else
    #error Unsupported or no platform defined
#endif

#ifndef EOK
#define EOK 0
#endif /* EOK */

#ifndef ENOENT
#define ENOENT 2
#endif /* ENOENT */

#ifndef EIO
#define EIO 5
#endif /* EIO */

#ifndef ENOMEM
#define ENOMEM 11
#endif /* ENOMEM */

#ifndef EACCES
#define EACCES 13
#endif /* EACCES */

#ifndef ENODEV
#define ENODEV 19
#endif /* ENODEV */

#ifndef EINVAL
#define EINVAL 22
#endif /* EINVAL */

#ifndef ETIME
#define ETIME 62
#endif /* ETIME */

#ifndef EOVERFLOW
#define EOVERFLOW 75
#endif /* EOVERFLOW */

#ifndef ETIMEDOUT
#define ETIMEDOUT 110
#endif /* ETIMEDOUT */

#ifndef EBUSY
#define EBUSY 111
#endif /* EBUSY */

#ifndef ENXIO
#define ENXIO 112
#endif /* ENXIO */

#ifndef ENOSPC
#define ENOSPC 113
#endif /* ENOSPC */

#ifndef ENOEXEC
#define ENOEXEC 114
#endif /* ENOEXEC */

#ifndef EPERM
#define EPERM 115
#endif /* EPERM */

#ifndef EEXIST
#define EEXIST 116
#endif /* EEXIST */

#ifndef EFAULT
#define EFAULT 117
#endif /* EFAULT */

#ifndef EAGAIN
#define EAGAIN 118
#endif /* EAGAIN */

#ifndef ENOCLK
#define ENOCLK 119
#endif /* ENOCLK */

#ifndef ENOLCK
#define ENOLCK 120
#endif /* ENOLCK */

#ifndef ECANCELED
#define ECANCELED 121
#endif /* ECANCELED */

#ifndef ENOTSUP
#define ENOTSUP 122
#endif /* ECANCELED */


#ifndef TRUE
#define TRUE 1
#endif /* TRUE */

#ifndef FALSE
#define FALSE 0
#endif /* FALSE */

#ifndef NULL
#define NULL NULL_PTR
#endif /* NULL */

#ifndef NULL_ADDR
#define NULL_ADDR ((addr_t)0U)
#endif /* NULL_ADDR */

#if defined(PFE_CFG_TARGET_ARCH_armv7le) || defined(PFE_CFG_TARGET_ARCH_aarch64le)
    /* Little endian */
    #define oal_htons(a) ((uint16_t)((((uint16_t)(a) & 0xFF00U) >> 8) | \
                                     (((uint16_t)(a) & 0x00FFU) << 8)))
    #define oal_htonl(a) ((((uint32_t)(a) & 0xFF000000U) >> 24) | \
                          (((uint32_t)(a) & 0x00FF0000U) >> 8 ) | \
                          (((uint32_t)(a) & 0x0000FF00U) << 8 ) | \
                          (((uint32_t)(a) & 0x000000FFU) << 24))
    
    #define oal_ntohs(x)    oal_htons(x)
    #define oal_ntohl(x)    oal_htonl(x)

    #define pu8_to_be16(PU8) ((uint16_t)(((uint16_t)(PU8)[0] << 8) & 0xFF00U)                     | (uint16_t)(PU8)[1])
    #define pu8_to_be32(PU8) ((uint32_t)(((uint32_t)pu8_to_be16(&(PU8)[0]) << 16) & 0xFFFF0000UL) | (uint32_t)pu8_to_be16(&(PU8)[2]))

    #define pu8_to_le16(PU8) ((uint16_t)(((uint16_t)(PU8)[1] << 8) & 0xFF00U)                     | (uint16_t)(PU8)[0])
    #define pu8_to_le32(PU8) ((uint32_t)(((uint32_t)pu8_to_le16(&(PU8)[2]) << 16) & 0xFFFF0000UL) | (uint32_t)pu8_to_le16(&(PU8)[0]))

    #define be32_to_cpu(val)    oal_htonl(val)
    #define cpu_to_be32(val)    oal_htonl(val)
    #define be16_to_cpu(val)    oal_htons(val)
    #define cpu_to_be16(val)    oal_htons(val)
    #define be64_to_cpu(val) \
            ( \
              ((((uint64_t)(val)) >> 56) & 0x00000000000000ffULL) | \
              ((((uint64_t)(val)) >> 40) & 0x000000000000ff00ULL) | \
              ((((uint64_t)(val)) >> 24) & 0x0000000000ff0000ULL) | \
              ((((uint64_t)(val)) >> 8 ) & 0x00000000ff000000ULL) | \
              ((uint64_t)(((uint64_t)(val)) << 8 ) & 0x000000ff00000000ULL) | \
              ((uint64_t)(((uint64_t)(val)) << 24) & 0x0000ff0000000000ULL) | \
              ((uint64_t)(((uint64_t)(val)) << 40) & 0x00ff000000000000ULL) | \
              ((uint64_t)(((uint64_t)(val)) << 56) & 0xff00000000000000ULL) \
            )
    #define cpu_to_be64(val)    be64_to_cpu(val)
#else
    #error Unknown or unsupported endian
#endif

#endif /*OAL_TYPES_AUTOSAR_H*/
