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
 *  Copyright 2023 NXP
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
#include "pfe_hm.h"
#include "pfe_cbus.h"
#include "pfe_global_wsp.h"
#include "pfe_fail_stop_csr.h"
#include "Eth_43_PFE_Cfg.h"

#define FAIL_STOP_INT_SRC_NUMBER   6U

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       FAIL_STOP ISR
 * @details     MASK, ACK, and process triggered interrupts.
 * @param[in]   base_va FAIL_STOP register space base address (virtual)
 * @return      EOK if interrupt has been handled, error code otherwise
 */
errno_t pfe_fail_stop_cfg_isr(addr_t base_va)
{
    uint32_t reg_en, reg_src, reg_source;
    errno_t ret = ENOENT;
    uint32_t trig_en_interrupts = 0U;
    uint8_t index = 0U;
    static const pfe_hm_evt_t event_id[FAIL_STOP_INT_SRC_NUMBER] =
    {
        HM_EVT_FAIL_STOP_PARITY,
        HM_EVT_FAIL_STOP_WATCHDOG,
        HM_EVT_FAIL_STOP_BUS,
        HM_EVT_FAIL_STOP_ECC_MULTIBIT,
        HM_EVT_FAIL_STOP_FW,
        HM_EVT_FAIL_STOP_HOST,
    };

    /* Get enabled interrupts */
    reg_en = hal_read32(base_va + WSP_FAIL_STOP_MODE_INT_EN);
    /* Mask Fail Stop interrupts */
    hal_write32((reg_en & ~(FAIL_STOP_INT_EN)), base_va + WSP_FAIL_STOP_MODE_INT_EN);
    /* Get triggered interrupts */
    reg_src = hal_read32(base_va + WSP_FAIL_STOP_MODE_INT_SRC);
    if (0U != (reg_src & reg_en & FAIL_STOP_INT_ENABLE_ALL))
    {
        reg_source = hal_read32(base_va + WSP_FAILSTOP_INTERRUPT_SOURCE) & \
                     hal_read32(base_va + WSP_FAIL_STOP_MODE_EN);
    }
    else
    {
        reg_source = 0U;
    }

    /* Process interrupts which are triggered AND enabled */
    if (0U != reg_source)
    {
        trig_en_interrupts = reg_source;
        while (0U != trig_en_interrupts)
        {
            PfeDevAssert(index < FAIL_STOP_INT_SRC_NUMBER);

            if (0U != (trig_en_interrupts & 1UL))
            {
                pfe_hm_report_error(HM_SRC_FAIL_STOP, event_id[index], "");
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
               (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_FAIL_STOP_HW_ERR, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
            }
            trig_en_interrupts >>= 1U;

            index++;
        }
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Mask FAIL_STOP interrupts
 * @param[in]   base_va Base address of the FAIL_STOP register space
 */
void pfe_fail_stop_cfg_irq_mask(addr_t base_va)
{
    uint32_t reg;

    reg = hal_read32(base_va + WSP_FAIL_STOP_MODE_INT_EN) & ~(FAIL_STOP_INT_EN);
    hal_write32(reg, base_va + WSP_FAIL_STOP_MODE_INT_EN);
}

/**
 * @brief       Unmask FAIL_STOP interrupts
 * @param[in]   base_va Base address of the FAIL_STOP register space
 */
void pfe_fail_stop_cfg_irq_unmask(addr_t base_va)
{
    uint32_t reg;

    reg = hal_read32(base_va + WSP_FAIL_STOP_MODE_INT_EN) | FAIL_STOP_INT_EN;
    hal_write32(reg, base_va + WSP_FAIL_STOP_MODE_INT_EN);
}

/**
 * @brief       Unmask all FAIL_STOP interrupts
 * @param[in]   base_va Base address of the FAIL_STOP register space
 * @note        This function is called from thread.
 */
void pfe_fail_stop_cfg_irq_unmask_all(addr_t base_va)
{
    hal_write32(FAIL_STOP_INT_ENABLE_ALL, base_va + WSP_FAIL_STOP_MODE_INT_EN);     /*direct write*/
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif
