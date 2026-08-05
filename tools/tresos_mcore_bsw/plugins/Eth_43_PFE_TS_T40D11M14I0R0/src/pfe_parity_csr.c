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
 *  Copyright 2019-2024 NXP
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
#ifdef PFE_CFG_PFE_MASTER
#include "pfe_hm.h"
#include "pfe_cbus.h"
#include "pfe_parity_csr.h"
#include "pfe_global_wsp.h"
#include "Eth_43_PFE_Cfg.h"

#define WSP_PARITY_INT_SRC_NUMBER   31U
#define TRIG_EN_INTERRUPTS_CHECK   (MASTER1_INT | MASTER2_INT | MASTER3_INT | MASTER4_INT | \
                                    EMAC_CBUS_INT | EMAC_DBUS_INT | CLASS_CBUS_INT | CLASS_DBUS_INT | \
                                    TMU_CBUS_INT | TMU_DBUS_INT | HIF_CBUS_INT | HIF_DBUS_INT | \
                                    HIF_NOCPY_CBUS_INT | HIF_NOCPY_DBUS_INT | UPE_CBUS_INT | UPE_DBUS_INT | \
                                    HRS_CBUS_INT | BRIDGE_CBUS_INT | EMAC_SLV_INT | BMU1_SLV_INT | \
                                    BMU2_SLV_INT | CLASS_SLV_INT | HIF_SLV_INT | HIF_NOCPY_SLV_INT | \
                                    LMEM_SLV_INT | TMU_SLV_INT | UPE_SLV_INT | WSP_GLOBAL_SLV_INT | \
                                    GPT1_SLV_INT | GPT2_SLV_INT | ROUTEMEM_SLV_INT \
                                   )

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       PARITY ISR
 * @details     MASK, ACK, and process triggered interrupts.
 * @param[in]   base_va PARITY register space base address (virtual)
 * @return      EOK if interrupt has been handled, error code otherwise
 */
errno_t pfe_parity_cfg_isr(addr_t base_va)
{
    uint32_t reg_en, reg_src;
    errno_t ret = ENOENT;
    uint32_t trig_en_interrupts;
    uint8_t index = 0U;
    static const pfe_hm_evt_t event_id[WSP_PARITY_INT_SRC_NUMBER] =
    {
        HM_EVT_PARITY_MASTER1,
        HM_EVT_PARITY_MASTER2,
        HM_EVT_PARITY_MASTER3,
        HM_EVT_PARITY_MASTER4,
        HM_EVT_PARITY_EMAC_CBUS,
        HM_EVT_PARITY_EMAC_DBUS,
        HM_EVT_PARITY_CLASS_CBUS,
        HM_EVT_PARITY_CLASS_DBUS,
        HM_EVT_PARITY_TMU_CBUS,
        HM_EVT_PARITY_TMU_DBUS,
        HM_EVT_PARITY_HIF_CBUS,
        HM_EVT_PARITY_HIF_DBUS,
        HM_EVT_PARITY_HIF_NOCPY_CBUS,
        HM_EVT_PARITY_HIF_NOCPY_DBUS,
        HM_EVT_PARITY_UPE_CBUS,
        HM_EVT_PARITY_UPE_DBUS,
        HM_EVT_PARITY_HRS_CBUS,
        HM_EVT_PARITY_BRIDGE_CBUS,
        HM_EVT_PARITY_EMAC_SLV,
        HM_EVT_PARITY_BMU1_SLV,
        HM_EVT_PARITY_BMU2_SLV,
        HM_EVT_PARITY_CLASS_SLV,
        HM_EVT_PARITY_HIF_SLV,
        HM_EVT_PARITY_HIF_NOCPY_SLV,
        HM_EVT_PARITY_LMEM_SLV,
        HM_EVT_PARITY_TMU_SLV,
        HM_EVT_PARITY_UPE_SLV,
        HM_EVT_PARITY_WSP_GLOBAL_SLV,
        HM_EVT_PARITY_GPT1_SLV,
        HM_EVT_PARITY_GPT2_SLV,
        HM_EVT_PARITY_ROUTE_LMEM_SLV,
    };

    /* Get enabled interrupts */
    reg_en = hal_read32(ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN));
    /* Mask parity interrupts */
    hal_write32((reg_en & ~(PARITY_INT_EN)), ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN));
    /* Get triggered interrupts */
    reg_src = hal_read32(ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_SRC));
    /* ACK triggered interrupts */
    hal_write32(reg_src, ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_SRC));

    /* Process interrupts which are triggered AND enabled */
    trig_en_interrupts = reg_src & reg_en & TRIG_EN_INTERRUPTS_CHECK;
    if (0U != trig_en_interrupts)
    {
        trig_en_interrupts >>= 1U;
        while (0U != trig_en_interrupts)
        {
            if (0U != (trig_en_interrupts & 1UL))
            {
                PfeDevAssert(index < WSP_PARITY_INT_SRC_NUMBER);
                pfe_hm_report_error(HM_SRC_PARITY, event_id[index], "");
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_PFE_PARITY_ERR, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
            }
            trig_en_interrupts >>= 1U;
            index++;
        }
        ret = EOK;
    }

    /* Enable the non-triggered ones only to prevent flooding */
    hal_write32((reg_en & ~reg_src), ADDR_BASE_OFFSET(base_va,  WSP_PARITY_INT_EN));

    return ret;
}

/**
 * @brief       Mask PARITY interrupts
 * @param[in]   base_va Base address of the PARITY register space
 */
void pfe_parity_cfg_irq_mask(addr_t base_va)
{
    uint32_t reg;

    reg = hal_read32(ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN)) & ~(PARITY_INT_EN);
    hal_write32(reg, ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN));
}

/**
 * @brief       Unmask PARITY interrupts
 * @param[in]   base_va Base address of the PARITY register space
 */
void pfe_parity_cfg_irq_unmask(addr_t base_va)
{
    uint32_t reg;

    reg = hal_read32(ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN)) | PARITY_INT_EN;
    hal_write32(reg, ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN));
}

/**
 * @brief       Unmask all PARITY interrupts
 * @param[in]   base_va Base address of the PARITY register space
 * @note        This function is called from thread.
 */
void pfe_parity_cfg_irq_unmask_all(addr_t base_va)
{
    hal_write32(PARITY_INT_ENABLE_ALL, ADDR_BASE_OFFSET(base_va, WSP_PARITY_INT_EN));
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif
