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
 *  Copyright 2018-2023 NXP
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

/**
 * @addtogroup  dxgrOAL
 * @{
 *
 * @defgroup    dxgr_OAL_TYPES TYPES
 * @brief       Standard types
 * @details
 *
 *
 * @addtogroup  dxgr_OAL_TYPES
 * @{
 *
 * @file        oal_types.h
 * @brief       Header for standard types
 *
 */

#ifndef OAL_TYPES_H_
#define OAL_TYPES_H_

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

/*
 * AUTOSAR
 *
 */
#if defined(PFE_CFG_TARGET_OS_AUTOSAR)
#include "oal_types_autosar.h"

/*
 * BARE METAL
 *
 */
#elif defined(PFE_CFG_TARGET_OS_BARE)
#include "oal_types_bare.h"

/*
 * unknown OS
 *
 */
#else
#error "PFE_CFG_TARGET_OS_xx was not set!"
#endif /* PFE_CFG_TARGET_OS_xx */

#include "ct_assert.h"

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/**
 * @brief       Swap byte order in a buffer
 * @detail      Convert byte order of each 4-byte word within given buffer
 * @param[in]   data Pointer to buffer to be converted
 * @param[in]   size Number of bytes in the buffer
 */
static inline void oal_swap_endian_long(void *data, uint32_t size)
{
    uint32_t ii, words = size >> 2;
    uint32_t *word = (uint32_t *)data;

    if (0U != (size & 0x3U))
    {
        words += 1U;
    }

    for (ii=0U; ii<words; ii++)
    {
        word[ii] = oal_htonl(word[ii]);
    }
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* OAL_TYPES_H_ */

/** @}*/
/** @}*/
