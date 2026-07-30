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

#ifndef HW_S32G_PFE_CT_COMP_H_
#define HW_S32G_PFE_CT_COMP_H_
#include "pfe_ct.h"

typedef struct __attribute__((packed,aligned(4)))
{
    const char name[16];
    PFE_PTR(uint8_t) const data;
    const uint8_t size;
    const uint8_t multiplicity;
    const uint8_t reserved[2];
} pfe_ct_feature_tbl_entry_t ;

typedef struct __attribute__((packed,aligned(4)))
{
    pfe_ct_feature_desc_t feature;
    PFE_PTR(const pfe_ct_feature_tbl_entry_t) cfg;
    PFE_PTR(const pfe_ct_feature_tbl_entry_t) stats;
}pfe_ct_feature_desc_ext_t;

ct_assert(sizeof(pfe_ct_feature_desc_ext_t) == 24);

typedef struct __attribute__((packed, aligned(4)))
{
    uint16_t vlan;                      /*!< VLAN value if applicable */
    pfe_ct_vlan_table_result_t entry;   /*!< Entry value - port map and other */
    uint8_t field_valids;               /*!< see pfe_mac2f_table_entry_valid_bits_t */
    uint8_t flags;                      /*!< see pfe_mac2f_table_entry_flags_t */
    uint16_t col_ptr;                   /*!< Collision entry pointer */
} l2br_vlan_hash_entry_t;

ct_assert(sizeof(l2br_vlan_hash_entry_t) == 16);

#endif /* HW_S32G_PFE_CT_COMP_H_ */
