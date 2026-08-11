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
 * @defgroup    dxgrOAL OAL
 * @brief       The OS Abstraction Layer
 * @details     OAL is intended to provide OS abstraction. To write portable SW one shall use
 *              OAL calls instead of OS-specific ones. This OAL module incorporates following
 *              functionality:
 *              
 *              - oal_irq - Interrupt management
 *              - oal_mm - Memory management
 *              - oal_types - Abstraction of standard types
 *              - oal_sync - Thread synchronization
 *              - oal_util - Simplification utility
 *              - oaj_job - Job context abstraction
 *              
 * 
 * @addtogroup  dxgrOAL
 * @{
 * 
 * @file        oal.h
 * @brief       The main OAL header file
 * @details     Use this header to include all the OAL-provided functionality
 *
 */

#ifndef OAL_H_
#define OAL_H_

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

#ifndef PFE_CFG_H
    #error Please include the pfe_cfg.h first.
#endif

#include "oal_types.h"
#include "oal_mm.h"
#include "oal_util.h"
#include "oal_sync.h"
#if !defined(PFE_CFG_DETACHED_MINIHIF)
#include "oal_master_if.h"
#include "oal_irq.h"
#include "oal_time.h"
#include "oal_job.h"
#endif /* PFE_CFG_DETACHED_MINIHIF */

#endif /* OAL_H_ */

/** @}*/
