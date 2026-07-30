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

#ifndef SRC_PFE_UTIL_H_
#define SRC_PFE_UTIL_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif


#include "pfe_ct.h"
#include "pfe_fw_feature.h"

typedef struct pfe_util_tag pfe_util_t;

typedef struct
{
    uint32_t pe_sys_clk_ratio;      /*  Clock mode ratio for sys_clk and pe_clk */
    bool_t on_g3;
} pfe_util_cfg_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_util_t *pfe_util_create(addr_t cbus_base_va, uint32_t pe_num, const pfe_util_cfg_t *cfg);
void pfe_util_enable(pfe_util_t *util);
void pfe_util_reset(pfe_util_t *util);
void pfe_util_disable(pfe_util_t *util);
errno_t pfe_util_default_init(pfe_util_t *util);
errno_t pfe_util_load_firmware(pfe_util_t *util, const void *elf);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_util_get_text_statistics(pfe_util_t *util, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

void pfe_util_destroy(pfe_util_t *util);
errno_t pfe_util_isr(pfe_util_t *util);
void pfe_util_irq_mask(const pfe_util_t *util);
void pfe_util_irq_unmask(const pfe_util_t *util);
errno_t pfe_util_get_fw_version(const pfe_util_t *util, pfe_ct_version_t *ver);
errno_t pfe_util_get_feature(pfe_util_t *util, pfe_fw_feature_t **feature, const char *name);
errno_t pfe_util_get_feature_first(pfe_util_t *util, pfe_fw_feature_t **feature);
errno_t pfe_util_get_feature_next(pfe_util_t *util, pfe_fw_feature_t **feature);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* SRC_PFE_UTIL_H_ */
