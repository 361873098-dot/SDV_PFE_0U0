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
 * @defgroup    dxgr_OAL_TIME TIME
 * @brief       Time abstraction
 *
 *
 * @addtogroup  dxgr_OAL_TIME
 * @{
 *
 * @file        oal_time.h
 * @brief       The oal_time module header file.
 * @details     This file contains generic time management-related API.
 *
 */

#ifndef PUBLIC_OAL_TIME_H_
#define PUBLIC_OAL_TIME_H_

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

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Suspend a thread for a given number of microseconds
 * @param[in]   usec The number of microseconds that you want the process to sleep for
 */
void oal_time_usleep(uint32_t usec);

/**
 * @brief       Suspend a thread for a given number of milliseconds
 * @param[in]   msec The number of milliseconds that you want the process to sleep for
 */
void oal_time_msleep(uint32_t msec);

void oal_time_udelay(uint32_t usec);

void oal_time_mdelay(uint32_t msec);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_OAL_TIME_H_ */

/** @}*/
/** @}*/
