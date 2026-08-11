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
 *  Copyright 2021-2022 NXP
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

#ifndef PFE_DRV_FEATURE_H
#define PFE_DRV_FEATURE_H

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

#include "pfe_ct.h"

typedef struct pfe_hw_feature_tag
{
    /* Similar to pfe_ct_feature_desc_t */
    const char *name;   /* Feature name */
    const char *description;    /* Feature description */
    pfe_ct_feature_flags_t flags;
    uint8_t def_val;    /* Enable/disable default value used for runtime configuration */
    uint8_t val;
} pfe_hw_feature_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_hw_feature_init_all(const uint32_t *cbus_base, pfe_hw_feature_t *hw_features, uint32_t *hw_features_count);
errno_t pfe_hw_feature_set_val(pfe_hw_feature_t *feature, uint8_t val);
void pfe_hw_feature_destroy(const pfe_hw_feature_t *feature);
errno_t pfe_hw_feature_get_name(const pfe_hw_feature_t *feature, const char **name);
errno_t pfe_hw_feature_get_desc(const pfe_hw_feature_t *feature, const char **desc);
errno_t pfe_hw_feature_get_flags(const pfe_hw_feature_t *feature, pfe_ct_feature_flags_t *flags);
errno_t pfe_hw_feature_get_def_val(const pfe_hw_feature_t *feature, uint8_t *def_val);
errno_t pfe_hw_feature_get_val(const pfe_hw_feature_t *feature, uint8_t *val);
bool_t pfe_hw_feature_enabled(const pfe_hw_feature_t *feature);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif
