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
 * @addtogroup  dxgrOAL
 * @{
 */
#ifndef OAL_IRQ_AUTOSAR_H_
#define OAL_IRQ_AUTOSAR_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43120440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43120440
#endif

/* Interrupt indexes */
typedef enum {
    Eth_43_PFE_IRQ_IDX_HIF0 = 0U,
    Eth_43_PFE_IRQ_IDX_HIF1 = 1U,
    Eth_43_PFE_IRQ_IDX_HIF2 = 2U,
    Eth_43_PFE_IRQ_IDX_HIF3 = 3U,
    Eth_43_PFE_IRQ_IDX_HIFNOCPY,
    Eth_43_PFE_IRQ_IDX_BMU,
    Eth_43_PFE_IRQ_COUNT
} oal_irq_idx_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/* Mapping of interrupt IDs to the indexes */
static inline oal_irq_idx_t find_irq_idx_from_id(int32_t id)
{
    oal_irq_idx_t ret_val;

    switch(id)
    {
        case 190:
            ret_val = Eth_43_PFE_IRQ_IDX_HIF0;
            break;
        case 191:
            ret_val = Eth_43_PFE_IRQ_IDX_HIF1;
            break;
        case 192:
            ret_val = Eth_43_PFE_IRQ_IDX_HIF2;
            break;
        case 193:
            ret_val = Eth_43_PFE_IRQ_IDX_HIF3;
            break;
        case 194:
            ret_val = Eth_43_PFE_IRQ_IDX_BMU;
            break;
        case 195:
            ret_val = Eth_43_PFE_IRQ_IDX_HIFNOCPY;
            break;
        default:
            ret_val = Eth_43_PFE_IRQ_COUNT; /* ERROR */
            break;
    }
    return ret_val;
}

/**
 * @brief       Handle any interrupt
 * @details     This function calls a registered interrupt handler (if any)
 *              that matches the idx argument
 * @param[in]   idx Index of registered interrupt handler to be called,
 */
extern void oal_irq_common_handler(oal_irq_idx_t idx);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* OAL_IRQ_AUTOSAR_H_ */

/** @}*/
