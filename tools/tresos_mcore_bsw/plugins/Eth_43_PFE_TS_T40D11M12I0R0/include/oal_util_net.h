/* =========================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
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

/**
 * @addtogroup  dxgrOAL_UTIL
 * @{
 *
 * @defgroup    dxgr_OAL_UTIL_NET NET
 * @brief       Advanced utilities, network subsection
 * @details     Network specific utilities
 *
 *
 * @addtogroup  dxgr_OAL_UTIL_NET
 * @{
 *
 * @file        oal_util_net.h
 * @brief       The oal_util_net module header file.
 * @details     This file contains network specific utilities API.
 *
 */

#ifndef OAL_UTIL_NET_H_
#define OAL_UTIL_NET_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43120440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43120440
#endif

#include "oal_types.h"
#include "oal_util_net_autosar.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Convert a numeric network address to a string
 * @details     Function return the pointer to the buffer containing
 * @details     the string version of network address, NULL otherwise
 * @param[in]   af The address network family
 * @param[in]   src The numeric network address
 * @param[out]  dst The buffer with string represented the netowrk address
 * @param[in]   size The size of the buffer
 *
 * @return      The pointer the to buffer, NULL if error occured
 */
char_t *oal_util_net_inet_ntop(int32_t af, const void *src, char_t *dst, uint32_t size);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* OAL_UTIL_NET_H_ */

/** @}*/
/** @}*/
