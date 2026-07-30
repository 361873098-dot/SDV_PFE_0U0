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

#ifndef PUBLIC_PFE_L2BR_TABLE_H_
#define PUBLIC_PFE_L2BR_TABLE_H_

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

#include "pfe_phy_if.h"

typedef enum
{
    PFE_L2BR_TABLE_INVALID,
    PFE_L2BR_TABLE_MAC2F,
    PFE_L2BR_TABLE_VLAN
} pfe_l2br_table_type_t;

/**
 * @brief   L2 bridge table select criteria type
 */
typedef enum
{
    L2BR_TABLE_CRIT_ALL,            /*!< Match any entry in the table */
    L2BR_TABLE_CRIT_VALID           /*!< Match only valid entries */
} pfe_l2br_table_get_criterion_t;

typedef struct pfe_l2br_table_tag pfe_l2br_table_t;
typedef struct
{
    pfe_l2br_table_get_criterion_t cur_crit;    /*!< Current criterion                          */
    uint32_t cur_hash_addr;                     /*!< Current address within hash space          */
    uint32_t cur_coll_addr;                     /*!< Current address within collision space     */
    uint32_t next_coll_addr;                    /*!< Next entry address within collision space  */
    struct                                      /*!< MAC and VLAN of the current entry          */
    {
        pfe_mac_addr_t mac;
        uint16_t vlan;
    } cur_macvlan;
} pfe_l2br_table_iterator_t;

/**
 * @brief   2-field MAC table entry
 */
typedef struct __attribute__((packed, aligned(4)))
{
    pfe_mac_addr_t mac;                                     /*!< [47:0]                                             */
    uint32_t vlan                               : 13;       /*!< [60:48]                                            */
    uint32_t action_data                        : 31;       /*!< [91:61], see pfe_ct_mac_table_result_t     */
    uint32_t field_valids                       : 8;        /*!< [99:92], see pfe_mac2f_table_entry_valid_bits_t    */
    uint32_t port                               : 4;        /*!< [103:100]                                          */
    uint32_t col_ptr                            : 16;       /*!< [119:104]                                          */
    uint32_t flags                              : 4;        /*!< [123:120], see pfe_mac2f_table_entry_flags_t       */
    uint32_t padding                            : 4;        /*!< [127:124], Round up to integer number of bytes     */
} pfe_mac2f_table_entry_t;

/**
 * @brief   VLAN table entry
 */
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t vlan           : 13;   /*!< [12:0]                                         */
    uint64_t action_data    : 55;   /*!< [67:13], see pfe_vlan_table_action_entry_t     */
    uint32_t field_valids   : 8;    /*!< [75:68], see pfe_vlan_table_entry_valid_bits_t */
    uint32_t port           : 4;    /*!< [79:76]                                        */
    uint32_t col_ptr        : 16;   /*!< [95:80]                                        */
    uint32_t flags          : 4;    /*!< [99:96], see pfe_vlan_table_entry_flags_t      */
    uint32_t padding        : 28;   /*!< [127:100], Round up to integer number of bytes */
} pfe_vlan_table_entry_t;

typedef struct
{
    union
    {
        pfe_mac2f_table_entry_t mac2f_entry;
        pfe_vlan_table_entry_t vlan_entry;
    } u;

    pfe_l2br_table_type_t type;
    bool_t action_data_set;
    bool_t mac_addr_set;
    bool_t vlan_set;
} pfe_l2br_table_entry_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_l2br_table_t *pfe_l2br_table_create(addr_t cbus_base_va, pfe_l2br_table_type_t type);
errno_t pfe_l2br_table_init(pfe_l2br_table_t *l2br);
errno_t pfe_l2br_table_flush(pfe_l2br_table_t *l2br);
errno_t pfe_l2br_table_add_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_del_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_update_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_search_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
pfe_l2br_table_iterator_t *pfe_l2br_iterator_create(pfe_l2br_table_iterator_t *loop_inst);
errno_t pfe_l2br_iterator_destroy(const pfe_l2br_table_iterator_t *inst);
errno_t pfe_l2br_table_get_first(pfe_l2br_table_t *l2br, pfe_l2br_table_iterator_t *l2t_iter, pfe_l2br_table_get_criterion_t crit, pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_get_next(pfe_l2br_table_t *l2br, pfe_l2br_table_iterator_t *l2t_iter, pfe_l2br_table_entry_t *entry);

pfe_l2br_table_entry_t *pfe_l2br_table_entry_create(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_entry_destroy(const pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_entry_set_mac_addr(pfe_l2br_table_entry_t *entry, const pfe_mac_addr_t mac_addr);
errno_t pfe_l2br_table_entry_set_vlan(pfe_l2br_table_entry_t *entry, uint16_t vlan);
__attribute__((pure)) uint32_t pfe_l2br_table_entry_get_vlan(const pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_entry_set_action_data(pfe_l2br_table_entry_t *entry, uint64_t action_data);
__attribute__((pure)) uint64_t pfe_l2br_table_entry_get_action_data(const pfe_l2br_table_entry_t *entry);
errno_t pfe_l2br_table_entry_set_fresh(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry, bool_t is_fresh);
bool_t pfe_l2br_table_entry_is_fresh(const pfe_l2br_table_entry_t *entry) __attribute__((pure));
errno_t pfe_l2br_table_entry_set_static(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry, bool_t is_static);
bool_t pfe_l2br_table_entry_is_static(const pfe_l2br_table_entry_t *entry) __attribute__((pure));

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_l2br_table_entry_to_str(const pfe_l2br_table_entry_t *entry, char_t *buf, uint32_t buf_len);
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_L2BR_TABLE_H_ */
