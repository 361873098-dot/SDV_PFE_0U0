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
#ifndef PFE_FEATURE_MGR_H
#define PFE_FEATURE_MGR_H

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

#include "pfe_class.h"
#include "pfe_util.h"
#include "pfe_tmu.h"

#define PFE_HW_FEATURE_RUN_ON_G3    "drv_run_on_g3"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

enum CAL_PACKED
{
    FW_FEATURE_TABLE_DEFAULT = 0U,
    FW_FEATURE_TABLE_CONFIG = 1U,
    FW_FEATURE_TABLE_STATS = 2U
};

errno_t pfe_feature_mgr_init(uint32_t *cbus_base);
errno_t pfe_feature_mgr_fini(void);
errno_t pfe_feature_mgr_add_modules(pfe_class_t *class, pfe_util_t *util, pfe_tmu_t *tmu);
bool_t pfe_feature_mgr_is_available(const char *feature_name);
errno_t pfe_feature_mgr_set_val(const char *feature_name, const uint8_t val);
errno_t pfe_feature_mgr_get_val(const char *feature_name, uint8_t *val);

errno_t pfe_feature_mgr_get_first(const char **feature_name);
errno_t pfe_feature_mgr_get_next(const char **feature_name);
errno_t pfe_feature_mgr_get_def_val(const char *feature_name, uint8_t *val);
errno_t pfe_feature_mgr_get_desc(const char *feature_name, const char **desc);
errno_t pfe_feature_mgr_get_variant(const char *feature_name, uint8_t *val);

errno_t pfe_feature_mgr_enable(const char *feature_name);
errno_t pfe_feature_mgr_disable(const char *feature_name);

errno_t pfe_feature_mgr_table_first(const char *feature_name, uint8_t table_type, const char **table_el_name);
errno_t pfe_feature_mgr_table_next(const char *feature_name, uint8_t table_type, const char **table_el_name);
errno_t pfe_feature_mgr_table_get_size(const char *feature_name, uint8_t table_type, const char *table_el_name, uint8_t *size);
errno_t pfe_feature_mgr_table_get_multiplicity(const char *feature_name, uint8_t table_type, const char *table_el_name, uint8_t *count);
errno_t pfe_feature_mgr_table_get_payload(const char *feature_name, uint8_t table_type, const char *table_el_name, uint8_t *payload);

errno_t pfe_feature_mgr_table_set_val(const char *feature_name, uint8_t table_type, const char *table_el_name, uint8_t index, uint8_t* val);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif
