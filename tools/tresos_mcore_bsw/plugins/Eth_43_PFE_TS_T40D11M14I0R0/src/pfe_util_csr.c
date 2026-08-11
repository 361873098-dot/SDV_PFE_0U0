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
 *  Copyright (c) 2019 Imagination Technologies Limited
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#include "pfe_cbus.h"
#include "pfe_util_csr.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Get UTIL statistics in text form
 * @details     This is a HW-specific function providing detailed text statistics
 *              about the UTIL block.
 * @param[in]   base_va     Base address of UTIL register space (virtual)
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   size        Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_util_cfg_get_text_stat(addr_t base_va, char_t *buf, uint32_t size, uint8_t verb_level)
{
    uint32_t len = 0U, reg;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Get version */
        if(verb_level >= 9U)
        {
            reg = hal_read32(base_va + UTIL_VERSION);
            len += oal_util_snprintf(buf + len, size - len, "Revision             : 0x%x\n", (reg >> 24U) & 0xffU);
            len += oal_util_snprintf(buf + len, size - len, "Version              : 0x%x\n", (reg >> 16U) & 0xffU);
            len += oal_util_snprintf(buf + len, size - len, "ID                   : 0x%x\n", reg & 0xffffU);
        }

        len += oal_util_snprintf(buf + len, size - len, "Max buffer count\t0x%08x\n", hal_read32(base_va + UTIL_MAX_BUF_CNT));
        len += oal_util_snprintf(buf + len, size - len, "TQS max count\t\t0x%08x\n", hal_read32(base_va + UTIL_TSQ_MAX_CNT));
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Dispatch interrupt from util.
 * @details     ACK and process triggered interrupts.

 * @param[in]   base_va     Base address of UTIL register space (virtual)
 * @return      EOK if interrupt has been handled, error code otherwise
 */
errno_t pfe_util_cfg_isr(addr_t base_va)
{
    uint32_t irq_src;

    /* Get IRQ status */
    irq_src = hal_read32(base_va + UTIL_UPE_GP_REG_ADDR);
    /*ACK interrupt */
    hal_write32(irq_src, base_va + UTIL_UPE_GP_REG_ADDR);

    return EOK;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
