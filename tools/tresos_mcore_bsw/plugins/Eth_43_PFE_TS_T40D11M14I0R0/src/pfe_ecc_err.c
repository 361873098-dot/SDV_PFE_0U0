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
#include "pfe_ecc_err.h"
#include "pfe_ecc_err_csr.h"

struct pfe_ecc_err_tag
{
    addr_t cbus_base_va;
    addr_t ecc_err_base_offset;
    addr_t ecc_err_base_va;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_ecc_err_t ecc_err_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Create new ECC_ERR instance
 * @details     Create and initializes ECC_ERR instance. New instance is always enabled.
 *              Use mask and unmask function to control interrupts.
 * @param[in]   base_va ECC_ERR register space base address (virtual)
 * @return      EOK if interrupt has been handled, error code otherwise
 * @note        Interrupt which were triggered are masked here, it is periodically unmasked again in SAFETY thread
 */
pfe_ecc_err_t *pfe_ecc_err_create(addr_t cbus_base_va, addr_t ecc_err_base)
{
    pfe_ecc_err_t *ecc_err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ecc_err = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ecc_err = &ecc_err_instance;
        (void)autolibc_memset(ecc_err, 0, sizeof(pfe_ecc_err_t));
        ecc_err->cbus_base_va = cbus_base_va;
        ecc_err->ecc_err_base_offset = ecc_err_base;
        ecc_err->ecc_err_base_va = ADDR_BASE_OFFSET(ecc_err->cbus_base_va, ecc_err->ecc_err_base_offset);

        /* Unmask all interrupts */
        pfe_ecc_err_cfg_irq_unmask_all(ecc_err->ecc_err_base_va);
    }

    return ecc_err;
}

/**
 * @brief       Destroy ECC_ERR instance
 * @param[in]   ecc_err The ECC_ERR instance
 */
void pfe_ecc_err_destroy(pfe_ecc_err_t *ecc_err)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ecc_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Mask ecc_err interrupts */
        pfe_ecc_err_cfg_irq_mask(ecc_err->ecc_err_base_va);
    }
}

/**
 * @brief       ECC_ERR ISR
 * @param[in]   ecc_err The ECC_ERR instance
 * @return      EOK if interrupt has been handled
 */
errno_t pfe_ecc_err_isr(const pfe_ecc_err_t *ecc_err)
{
    errno_t ret = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ecc_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = ENOMEM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        ret = pfe_ecc_err_cfg_isr(ecc_err->ecc_err_base_va);
    }

    return ret;
}

/**
 * @brief       Mask ECC_ERR interrupts
 * @param[in]   ecc_err The ECC_ERR instance
 */
void pfe_ecc_err_irq_mask(const pfe_ecc_err_t *ecc_err)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ecc_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_ecc_err_cfg_irq_mask(ecc_err->ecc_err_base_va);
    }
}

/**
 * @brief       Unmask ECC_ERR interrupts
 * @param[in]   ecc_err The ECC_ERR instance
 */
void pfe_ecc_err_irq_unmask(const pfe_ecc_err_t *ecc_err)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ecc_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_ecc_err_cfg_irq_unmask(ecc_err->ecc_err_base_va);
    }
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif
