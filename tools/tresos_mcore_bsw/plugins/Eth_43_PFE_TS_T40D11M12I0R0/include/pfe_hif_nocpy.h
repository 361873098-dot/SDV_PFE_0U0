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

#ifndef PUBLIC_PFE_HIF_NOCPY_H_
#define PUBLIC_PFE_HIF_NOCPY_H_

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
#include "pfe_bmu.h"

typedef struct
{
    uint32_t nothing; /* Some compilers don't support empty structs */
} pfe_hif_nocpy_cfg_t;

typedef struct pfe_hif_nocpy_tag pfe_hif_nocpy_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_hif_nocpy_t *pfe_hif_nocpy_create(addr_t base_va, const pfe_bmu_t *bmu, uint16_t lmem_header_size);
pfe_hif_chnl_t *pfe_hif_nocpy_get_channel(const pfe_hif_nocpy_t *hif, uint32_t channel_id);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_hif_nocpy_get_text_statistics(const pfe_hif_nocpy_t *hif, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

void pfe_hif_nocpy_destroy(pfe_hif_nocpy_t *hif);
void pfe_hif_nocpy_init_emac_timer_ownership(const pfe_hif_nocpy_t *hif);
void pfe_hif_nocpy_clear_emac_timer_ownership(const pfe_hif_nocpy_t *hif);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_HIF_NOCPY_H_ */
