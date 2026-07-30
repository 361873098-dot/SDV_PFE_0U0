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
#include "pfe_bus_err.h"
#include "pfe_bus_err_csr.h"

struct pfe_bus_err_tag
{
    addr_t cbus_base_va;
    addr_t bus_err_base_offset;
    addr_t bus_err_base_va;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_bus_err_t bus_err_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Create new BUS_ERR instance
 * @details     Create and initializes BUS_ERR instance. New instance is always enabled.
 *              Use mask and unmask function to control interrupts.
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   bus_err_base BUS_ERR base address offset within CBUS address space
 * @return      EOK if interrupt has been handled, error code otherwise
 * @return      The BUS_ERR instance or NULL if failed
 */
pfe_bus_err_t *pfe_bus_err_create(addr_t cbus_base_va, addr_t bus_err_base)
{
    pfe_bus_err_t *bus_err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        bus_err = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        bus_err = &bus_err_instance;
        (void)autolibc_memset(bus_err, 0, sizeof(pfe_bus_err_t));
        bus_err->cbus_base_va = cbus_base_va;
        bus_err->bus_err_base_offset = bus_err_base;
        bus_err->bus_err_base_va = (bus_err->cbus_base_va + bus_err->bus_err_base_offset);

        /* Unmask all interrupts */
        pfe_bus_err_cfg_irq_unmask_all(bus_err->bus_err_base_va);
    }

    return bus_err;
}

/**
 * @brief       Destroy BUS_ERR instance
 * @param[in]   bus_err The BUS_ERR instance
 */
void pfe_bus_err_destroy(pfe_bus_err_t *bus_err)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bus_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Mask bus_err interrupts */
        pfe_bus_err_cfg_irq_mask(bus_err->bus_err_base_va);
    }
}

/**
 * @brief       BUS_ERR ISR
 * @param[in]   bus_err The BUS_ERR instance
 * @return      EOK if interrupt has been handled
 */
errno_t pfe_bus_err_isr(const pfe_bus_err_t *bus_err)
{
    errno_t ret = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bus_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = ENOMEM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        ret = pfe_bus_err_cfg_isr(bus_err->bus_err_base_va);
    }

    return ret;
}

/**
 * @brief       Mask BUS_ERR interrupts
 * @param[in]   bus_err The BUS_ERR instance
 */
void pfe_bus_err_irq_mask(const pfe_bus_err_t *bus_err)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bus_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_bus_err_cfg_irq_mask(bus_err->bus_err_base_va);
    }
}

/**
 * @brief       Unmask BUS_ERR interrupts
 * @param[in]   bus_err The BUS_ERR instance
 */
void pfe_bus_err_irq_unmask(const pfe_bus_err_t *bus_err)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bus_err))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_bus_err_cfg_irq_unmask(bus_err->bus_err_base_va);
    }
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif
