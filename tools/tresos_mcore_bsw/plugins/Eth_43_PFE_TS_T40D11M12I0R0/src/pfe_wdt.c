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
 *  Copyright 2020-2023 NXP
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#include "Eth_43_PFE.h"
#ifdef PFE_CFG_PFE_MASTER
#include "pfe_cbus.h"
#include "pfe_wdt.h"
#include "pfe_wdt_csr.h"

struct pfe_wdt_tag
{
    addr_t cbus_base_va;
    addr_t wdt_base_offset;
    addr_t wdt_base_va;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_wdt_t wdt_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_wdt_t *pfe_wdt_create(addr_t cbus_base_va, addr_t wdt_base)
{
    pfe_wdt_t *wdt;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        wdt = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        wdt = &wdt_instance;
        (void)autolibc_memset(wdt, 0, sizeof(pfe_wdt_t));
        wdt->cbus_base_va = cbus_base_va;
        wdt->wdt_base_offset = wdt_base;
        wdt->wdt_base_va = (wdt->cbus_base_va + wdt->wdt_base_offset);

        pfe_wdt_cfg_init(wdt->wdt_base_va);
    }
    return wdt;
}

/**
 * @brief       Destroy WDT instance
 * @param[in]   wdt The WDT instance
 */
void pfe_wdt_destroy(pfe_wdt_t *wdt)
{
    if (NULL != wdt)
    {
        pfe_wdt_cfg_fini(wdt->wdt_base_va);
    }
}

/**
 * @brief       WDT ISR
 * @param[in]   wdt The WDT instance
 * @return      EOK if interrupt has been handled
 */
errno_t pfe_wdt_isr(pfe_wdt_t *wdt)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == wdt))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        if (EOK == pfe_wdt_cfg_isr(wdt->wdt_base_va, wdt->cbus_base_va))
        {
            /*  IRQ handled */
            ret = EOK;
        }
        else
        {
            ret = EINVAL;
        }
    }
    return ret;
}

/**
 * @brief       Mask WDT interrupts
 * @param[in]   The WDT instance
 */
void pfe_wdt_irq_mask(pfe_wdt_t *wdt)
{
    pfe_wdt_cfg_irq_mask(wdt->wdt_base_va);
}

/**
 * @brief       Unmask WDT interrupts
 * @param[in]   The WDT instance
 */
void pfe_wdt_irq_unmask(pfe_wdt_t * wdt)
{
    pfe_wdt_cfg_irq_unmask(wdt->wdt_base_va);
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return WDT runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   wdt         The WDT instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_wdt_get_text_statistics(const pfe_wdt_t *wdt, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == wdt))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        len += pfe_wdt_cfg_get_text_stat(wdt->wdt_base_va, buf, buf_len, verb_level);
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Get Wdt statistic in numeric form
 * @details     This is a HW-specific function providing single statistic
 *              value from the Wdt block.
 * @param[in]   wdt        The Wdt instance
 * @param[in]   stat_id    ID of required statistic (offset of register)
 * @return      Value of requested statistic and PFE_INVALID_STAT if wdt is NULL
 */
uint32_t pfe_wdt_get_stat_value(const pfe_wdt_t* wdt, uint32_t stat_id)
{
    uint32_t stat_value;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == wdt))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        stat_value = PFE_INVALID_STAT;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        stat_value = pfe_wdt_cfg_get_stat_value(wdt->wdt_base_va, stat_id);
    }
    return stat_value;
}


#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_PFE_MASTER */
