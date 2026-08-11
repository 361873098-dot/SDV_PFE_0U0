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
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
 *  Copyright 2022-2023 NXP
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

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#ifdef PFE_CFG_PFE_MASTER
#include "pfe_cbus.h"
#include "pfe_host_fail_stop.h"
#include "pfe_host_fail_stop_csr.h"


struct pfe_host_fail_stop_tag
{
    addr_t cbus_base_va;
    addr_t host_fail_stop_base_offset;
    addr_t host_fail_stop_base_va;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_host_fail_stop_t host_fail_stop_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Create new SAFETY_HOST_FAIL_STOP instance
 * @details     Create and initializes SAFETY_HOST_FAIL_STOP instance. New instance is always enabled.
 *              Use mask and unmask function to control interrupts.
 * @param[in]   base_va SAFETY_HOST_FAIL_STOP register space base address (virtual)
 * @return      EOK if interrupt has been handled, error code otherwise
 * @note        Interrupt which were triggered are masked here, it is periodically unmasked again in SAFETY thread
 */
pfe_host_fail_stop_t *pfe_host_fail_stop_create(addr_t cbus_base_va, addr_t host_fail_stop_base)
{
    pfe_host_fail_stop_t *host_fail_stop;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        host_fail_stop = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        host_fail_stop = &host_fail_stop_instance;
        (void)autolibc_memset(host_fail_stop, 0, sizeof(pfe_host_fail_stop_t));
        host_fail_stop->cbus_base_va = cbus_base_va;
        host_fail_stop->host_fail_stop_base_offset = host_fail_stop_base;
        host_fail_stop->host_fail_stop_base_va = (host_fail_stop->cbus_base_va + host_fail_stop->host_fail_stop_base_offset);

        /* Unmask all interrupts */
        pfe_host_fail_stop_cfg_irq_unmask_all(host_fail_stop->host_fail_stop_base_va);
    }
    return host_fail_stop;
}

/**
 * @brief       Destroy SAFETY_HOST_FAIL_STOP instance
 * @param[in]   host_fail_stop The SAFETY_HOST_FAIL_STOP instance
 */
void pfe_host_fail_stop_destroy(pfe_host_fail_stop_t *host_fail_stop)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == host_fail_stop))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Mask host_fail_stop interrupts */
        pfe_host_fail_stop_cfg_irq_mask(host_fail_stop->host_fail_stop_base_va);
    }
}

/**
 * @brief       SAFETY_HOST_FAIL_STOP ISR
 * @param[in]   host_fail_stop The SAFETY_HOST_FAIL_STOP instance
 * @return      EOK if interrupt has been handled
 */
errno_t pfe_host_fail_stop_isr(const pfe_host_fail_stop_t *host_fail_stop)
{
    errno_t ret = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == host_fail_stop))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = ENOMEM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        ret = pfe_host_fail_stop_cfg_isr(host_fail_stop->host_fail_stop_base_va);
    }

    return ret;
}

/**
 * @brief       Mask SAFETY_HOST_FAIL_STOP interrupts
 * @param[in]   host_fail_stop The SAFETY_HOST_FAIL_STOP instance
 */
void pfe_host_fail_stop_irq_mask(const pfe_host_fail_stop_t *host_fail_stop)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == host_fail_stop))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_host_fail_stop_cfg_irq_mask(host_fail_stop->host_fail_stop_base_va);
    }
}

/**
 * @brief       Unmask SAFETY_HOST_FAIL_STOP interrupts
 * @param[in]   host_fail_stop The SAFETY_HOST_FAIL_STOP instance
 */
void pfe_host_fail_stop_irq_unmask(const pfe_host_fail_stop_t *host_fail_stop)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == host_fail_stop))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_host_fail_stop_cfg_irq_unmask(host_fail_stop->host_fail_stop_base_va);
    }
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif
