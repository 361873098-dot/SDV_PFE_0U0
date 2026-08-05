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
 * @defgroup    dxgr_OAL_SYNC SYNC
 * @brief       Thread synchronization
 * @details     Package provides OS-independent thread synchronization primitives. All API should
 *              be implemented with performance taken into account.
 *
 *
 * @addtogroup  dxgr_OAL_SYNC
 * @{
 *
 * @file        oal_sync.h
 * @brief       The thread synchronization header file
 * @details     Use this header to include all the OS-independent thread synchronization functionality
 *
 */

#ifndef OAL_SYNC_H_
#define OAL_SYNC_H_

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

/*
 * AUTOSAR
 *
 */
#if defined(PFE_CFG_TARGET_OS_AUTOSAR)
#include "oal_mutex_autosar.h"
#include "SchM_Eth_43_PFE.h"

/*
 * BARE METAL
 *
 */
#elif defined(PFE_CFG_TARGET_OS_BARE)
#include "oal_spinlock_bare.h"
#include "oal_mutex_bare.h"

/*
 * unknown OS
 *
 */
#else
#error "PFE_CFG_TARGET_OS_xx was not set!"
#endif /* PFE_CFG_TARGET_OS_xx */

/** @}*/
/** @}*/

#endif /* OAL_SYNC_H_ */
