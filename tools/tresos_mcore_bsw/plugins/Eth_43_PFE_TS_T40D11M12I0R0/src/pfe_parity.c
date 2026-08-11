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
 *  Copyright (c) 2019 Imagination Technologies Limited
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
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

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#ifdef PFE_CFG_PFE_MASTER
#include "pfe_cbus.h"
#include "pfe_parity.h"
#include "pfe_parity_csr.h"

struct pfe_parity_tag
{
    addr_t cbus_base_va;
    addr_t parity_base_offset;
    addr_t parity_base_va;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_parity_t parity_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Create new PARITY instance
 * @details     Create and initializes PARITY instance. New instance is always enabled.
 *              Use mask and unmask function to control interrupts.
 * @param[in]   base_va PARITY register space base address (virtual)
 * @return      EOK if interrupt has been handled, error code otherwise
 * @note        Interrupt which were triggered are masked here, it is periodically unmasked again in SAFETY thread
 */
pfe_parity_t *pfe_parity_create(addr_t cbus_base_va, addr_t parity_base)
{
    pfe_parity_t *parity;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        parity = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        parity = &parity_instance;
        (void)autolibc_memset(parity, 0, sizeof(pfe_parity_t));
        parity->cbus_base_va = cbus_base_va;
        parity->parity_base_offset = parity_base;
        parity->parity_base_va = (parity->cbus_base_va + parity->parity_base_offset);

        /* Unmask all interrupts */
        pfe_parity_cfg_irq_unmask_all(parity->parity_base_va);
    }

    return parity;
}

/**
 * @brief       Destroy PARITY instance
 * @param[in]   parity The PARITY instance
 */
void pfe_parity_destroy(pfe_parity_t *parity)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == parity))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Mask parity interrupts */
        pfe_parity_cfg_irq_mask(parity->parity_base_va);
    }
}

/**
 * @brief       PARITY ISR
 * @param[in]   parity The PARITY instance
 * @return      EOK if interrupt has been handled
 */
errno_t pfe_parity_isr(const pfe_parity_t *parity)
{
    errno_t ret = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == parity))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = ENOMEM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        ret = pfe_parity_cfg_isr(parity->parity_base_va);
    }

    return ret;
}

/**
 * @brief       Mask PARITY interrupts
 * @param[in]   parity The PARITY instance
 */
void pfe_parity_irq_mask(const pfe_parity_t *parity)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == parity))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_parity_cfg_irq_mask(parity->parity_base_va);
    }
}

/**
 * @brief       Unmask PARITY interrupts
 * @param[in]   parity The PARITY instance
 */
void pfe_parity_irq_unmask(const pfe_parity_t *parity)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == parity))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_parity_cfg_irq_unmask(parity->parity_base_va);
    }
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif
