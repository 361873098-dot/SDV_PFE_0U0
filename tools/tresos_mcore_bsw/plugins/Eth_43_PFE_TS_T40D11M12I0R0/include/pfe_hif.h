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

#ifndef PUBLIC_PFE_HIF_H_
#define PUBLIC_PFE_HIF_H_

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

#include "pfe_hif_ring.h"
#include "pfe_hif_chnl.h"

typedef enum
{
    HIF_CHNL_INVALID = 0,
    HIF_CHNL_0 = (1 << 0),
    HIF_CHNL_1 = (1 << 1),
    HIF_CHNL_2 = (1 << 2),
    HIF_CHNL_3 = (1 << 3)
} pfe_hif_chnl_id_t;

typedef struct pfe_hif_tag pfe_hif_t;

/* Way to translate physical interface ID to HIF channel ID... */
#include "pfe_ct.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static inline pfe_hif_chnl_id_t pfe_hif_chnl_from_phy_id(pfe_ct_phy_if_id_t phy)
{
    if (phy == PFE_PHY_IF_ID_HIF0)
    {
        return HIF_CHNL_0;
    }
    else if (phy == PFE_PHY_IF_ID_HIF1)
    {
        return HIF_CHNL_1;
    }
    else if (phy == PFE_PHY_IF_ID_HIF2)
    {
        return HIF_CHNL_2;
    }
    else if (phy == PFE_PHY_IF_ID_HIF3)
    {
        return HIF_CHNL_3;
    }
    else
    {
        return HIF_CHNL_INVALID;
    }
}

pfe_hif_t *pfe_hif_create(addr_t cbus_base_va, pfe_hif_chnl_id_t channels_mask);
pfe_hif_chnl_t *pfe_hif_get_channel(const pfe_hif_t *hif, pfe_hif_chnl_id_t channel_id);
void pfe_hif_destroy(pfe_hif_t *hif);

#ifdef PFE_CFG_PFE_MASTER
errno_t pfe_hif_isr(pfe_hif_t *hif);
void pfe_hif_irq_mask(pfe_hif_t *hif);
void pfe_hif_irq_unmask(pfe_hif_t *hif);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_hif_get_text_statistics(const pfe_hif_t *hif, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
void pfe_hif_clear_master_up(const pfe_hif_t *hif);
void pfe_hif_set_master_up(const pfe_hif_t *hif);
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
void pfe_hif_init_emac_timer_ownership(const pfe_hif_t *hif);
void pfe_hif_clear_emac_timer_ownership(const pfe_hif_t *hif);
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
void pfe_hif_set_master_detect_cfg(pfe_hif_t *hif, bool_t on);
bool_t pfe_hif_get_master_detect_cfg(const pfe_hif_t *hif);
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_HIF_H_ */
