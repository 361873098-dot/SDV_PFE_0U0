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

/**
 * @addtogroup  dxgrOAL
 * @{
 *
 * @defgroup    dxgr_OAL_JOB JOB
 * @brief       Deferred job abstraction
 *
 *
 * @addtogroup  dxgr_OAL_JOB
 * @{
 *
 * @file        oal_job.h
 * @brief       The oal_job module header file.
 * @details     This file contains generic deferred job management-related API.
 *
 */

#ifndef PUBLIC_OAL_JOB_H_
#define PUBLIC_OAL_JOB_H_

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

#include "oal_sync.h"

typedef void (* oal_job_func)(void *arg);

typedef struct
{
    oal_job_func   func;
    void           *arg;
    const char_t   *name;
} oal_job_t;

/**
 * @brief   Priority enumeration type
 */
typedef enum
{
    OAL_PRIO_LOW,
    OAL_PRIO_NORMAL,
    OAL_PRIO_HIGH,
    OAL_PRIO_TOP
} oal_prio_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Create new job
 * @param[in]   func Function to be executed within the job
 * @param[in]   arg Function argument
 * @param[in]   name The job name in string form
 * @param[in]   prio Job priority
 * @param[in]   new_job New job instance to be initialized
 * @return      New job instance or NULL if failed
 */
oal_job_t *oal_job_create(oal_job_func func, void *arg, const char_t *name, oal_prio_t prio, oal_job_t *new_job);

/**
 * @brief        Trigger job execution
 * @details        Schedule the job. Can be called multiple times to enqueue multiple
 *                 triggers. Is a non-blocking call.
 * @param[in]    job The job instance
 * @return        EOK if success, error code otherwise
 */
errno_t oal_job_run(oal_job_t *job);

/**
 * @brief       Wait until job is done
 * @param[in]   job The job instance
 * @return      EOK if success, error code otherwise
 */
errno_t oal_job_drain(const oal_job_t *job);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_OAL_JOB_H_ */

/** @}*/
/** @}*/
