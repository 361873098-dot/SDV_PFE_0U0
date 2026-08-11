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
 * @addtogroup  dxgr_OAL_JOB
 * @{
 *
 * @file        oal_job_autosar.c
 * @brief       The oal_job module source file (AUTOSAR).
 * @details     This file contains AUTOSAR MCAL-specific (not)deferred job implementation.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "oal_mm.h"
#include "oal_job.h"
#include "hal.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t oal_job_run(oal_job_t *job)
{
    errno_t ret_val;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == job))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_val = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (0 == autolibc_strcmp("HIF TX JOB", job->name))
        {
            oal_mutex_lock(PFE_HIF_TX_JOB_MUTEX);
        }

        if(NULL == job->func)
        {
            NXP_LOG_ERROR("Job pointer was NULL\n");
            ret_val = EINVAL;
        }
        else
        {
            /* Execute the job here, no extra threads in this implementation */
            job->func(job->arg);
            ret_val = EOK;
        }

        if (0 == autolibc_strcmp("HIF TX JOB", job->name))
        {
            oal_mutex_unlock(PFE_HIF_TX_JOB_MUTEX);
        }
    }
    return ret_val;
}

/* Not needed in current implementation (no asynchronous tasks) */
errno_t oal_job_drain(const oal_job_t *job)
{
    errno_t ret_val = EOK;

    (void)job;

    return ret_val;
}

oal_job_t *oal_job_create(oal_job_func func, void *arg, const char_t *name, oal_prio_t prio, oal_job_t *new_job)
{
    /* Not used in current implementation */
    oal_job_t *job = new_job;
    (void)prio;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == func) || (NULL == new_job)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        job = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        job->func = func;
        job->arg = arg;
        job->name = name;
    }
    return job;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
