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
 *  Copyright 2020-2022 NXP
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
#ifndef PFE_COMPILER_H
#define PFE_COMPILER_H

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

/*------------------------------------------------------------------------------------------------*/
/* Section describing behavior of supported compilers:
*  - do no modify this section
*  - macro values are intentionally not 0 and 1 to avoid confusion with undefined macros having
*    one of these values
*/

/** 
* @brief Order of bit fields in the structure 
* @details Either bit field corresponding to the highest bits in the memory is specified as the first
*          member or the last member of the structure.
*/
#define PFE_COMPILER_BITFIELD_HIGH_FIRST 3
#define PFE_COMPILER_BITFIELD_HIGH_LAST 2

/**
* @brief Result of the compilation - either driver or firmware
*/
#define PFE_COMPILER_RESULT_DRV 4
#define PFE_COMPILER_RESULT_FW 5

/*------------------------------------------------------------------------------------------------*/
/* Section describing result of the compilation: */
#define PFE_COMPILER_RESULT PFE_COMPILER_RESULT_DRV

/*------------------------------------------------------------------------------------------------*/
/* Section describing behavior of supported compilers regarding bit-fields position in structure:
*  - when adding a new compiler, just add it and define the macro PFE_COMPILER_BITFIELD_BEHAVIOR to one
*    of the variants
*/

/* Various supported GCC variants: */
#if (defined(__GNUC__))
    #if ((__GNUC__ == 5) && (__GNUC_MINOR__ == 4) && (__GNUC_PATCHLEVEL__ == 0))
        /* GCC version 5.4.0 */
        #if (defined(PFE_CFG_TARGET_ARCH_x86))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #elif (defined(PFE_CFG_TARGET_ARCH_x86_64))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #elif (defined(PFE_CFG_TARGET_ARCH_aarch64le))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #endif
    #elif ((__GNUC__ == 6) && (__GNUC_MINOR__ == 3) && (__GNUC_PATCHLEVEL__ == 1))
        /* GCC version 6.3.1 */
        #if (defined(PFE_CFG_TARGET_ARCH_aarch64))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #elif (defined(PFE_CFG_TARGET_ARCH_armv7le))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #endif
    #elif ((__GNUC__ == 9) && (__GNUC_MINOR__ == 2) && (__GNUC_PATCHLEVEL__ == 0))
        /* GCC version 9.2.0 */
        #if (defined(PFE_CFG_TARGET_ARCH_aarch64))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #elif (defined(PFE_CFG_TARGET_ARCH_armv7le))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #endif
    #elif ((__GNUC__ == 8) && (__GNUC_MINOR__ == 3) && (__GNUC_PATCHLEVEL__ == 0))
        /* GCC version 8.3.0 */
        #if (defined(PFE_CFG_TARGET_ARCH_aarch64le))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #elif (defined(PFE_CFG_TARGET_ARCH_armv7le))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
        #endif
    #elif (defined (__KERNEL__))
        /* Linux kernel compilation for not supported compiler */
        #if (defined(PFE_CFG_TARGET_ARCH_aarch64))
            /* Compiling driver */
            #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
            #define PFE_COMPILER_BEHAVIOR_GUESSED_ONLY
        #endif
    #endif
#endif

/* Supported GHS variants */
#if (defined(__ghs__))
    #if ((__GHS_VERSION_NUMBER == 201814) || (__GHS_VERSION_NUMBER == 201914) || (__GHS_VERSION_NUMBER == 202014)) && defined(__LITTLE_ENDIAN__)
        /* Compiling MCAL driver */
        #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
    #endif
#endif

/* Supported DIAB variants */
#if (defined(__DCC__))
    #if (((__VERSION_NUMBER__ == 7020) || (__VERSION_NUMBER__ == 7030)) && defined(__ORDER_LITTLE_ENDIAN__))
        /* Compiling MCAL driver */
        #define PFE_COMPILER_BITFIELD_BEHAVIOR PFE_COMPILER_BITFIELD_HIGH_LAST
    #endif
#endif

/*------------------------------------------------------------------------------------------------*/
/* Checks for correctness: */

#if(!defined(PFE_COMPILER_BITFIELD_BEHAVIOR))
    /* Required macro not defined */
    #error Please specify your compiler behavior by defining PFE_COMPILER_BITFIELD_BEHAVIOR.
#endif

#if ((PFE_COMPILER_BITFIELD_BEHAVIOR != PFE_COMPILER_BITFIELD_HIGH_LAST) && (PFE_COMPILER_BITFIELD_BEHAVIOR != PFE_COMPILER_BITFIELD_HIGH_FIRST))
    /* Wrong macro value */
    #error PFE_COMPILER_BITFIELD_BEHAVIOR shall be either PFE_COMPILER_BITFIELD_HIGH_LAST or PFE_COMPILER_BITFIELD_HIGH_FIRST
#endif

#if(!defined(PFE_COMPILER_RESULT))
    /* Required macro not defined */
    #error Please specify your compiler output by defining PFE_COMPILER_RESULT.
#endif

#if ((PFE_COMPILER_RESULT != PFE_COMPILER_RESULT_DRV) && (PFE_COMPILER_RESULT != PFE_COMPILER_RESULT_FW))
    /* Wrong macro value */
    #error PFE_COMPILER_RESULT shall be either PFE_COMPILER_RESULT_DRV or PFE_COMPILER_RESULT_FW
#endif

#endif /* PFE_COMPILER_H */
