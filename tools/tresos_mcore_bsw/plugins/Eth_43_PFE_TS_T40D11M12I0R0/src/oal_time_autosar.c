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
 * @addtogroup  dxgr_OAL_TIME
 * @{
 *
 * @file        oal_time_autosar.c
 * @brief       The oal_time module source file (AUTOSAR variant).
 * @details     This file contains AUTOSAR-MCAL-specific time management implementation.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal_types.h"
#include "oal_time.h"
#include "Tm.h" /* AUTOSAR Time Service */

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

void oal_time_usleep(uint32_t usec)
{
    uint32_t usec_ctr = usec;

    while(usec_ctr > 250U)
    {
        (void)Tm_BusyWait1us32bit(250U);
        usec_ctr -= 250U;
    }
    (void)Tm_BusyWait1us32bit(usec_ctr);
}

void oal_time_msleep(uint32_t msec)
{
    uint32_t u32Ctr;

    for(u32Ctr=0U; u32Ctr < msec; u32Ctr++)
    {
        oal_time_usleep(1000U);
    }
}

void oal_time_udelay(uint32_t usec)
{
    oal_time_usleep(usec);
}

void oal_time_mdelay(uint32_t msec)
{
    oal_time_msleep(msec);
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
