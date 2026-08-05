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

#ifndef PUBLIC_PFE_L2BR_H_
#define PUBLIC_PFE_L2BR_H_

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

#include "pfe_log_if.h"
#include "pfe_l2br_table.h"
#include "Eth_43_PFE.h"

#ifdef PFE_CFG_L2BRIDGE_ENABLE
typedef struct pfe_l2br_tag pfe_l2br_t;
typedef struct pfe_l2br_domain_tag pfe_l2br_domain_t;
typedef struct pfe_l2br_static_entry_tag pfe_l2br_static_entry_t;

/**
 * @brief   Bridge domain select criteria type
 */
typedef enum
{
    L2BD_CRIT_ALL,              /*!< Match any domain within the bridge (argument is NULL) */
    L2BD_CRIT_BY_VLAN,          /*!< Match entry with VLAN equal to arg (argument is uint16_t) */
    L2BD_BY_PHY_IF,             /*!< Match entries containing given physical interface (argument is pfe_phy_if_t *) */
} pfe_l2br_domain_get_crit_t;

typedef enum
{
    L2BD_IF_CRIT_ALL,           /*!< Match any interface within the domain (argument is NULL) */
    L2BD_IF_BY_PHY_IF_ID,       /*!< Match entries by physical interface id (argument is pfe_phy_if_id_t) */
    L2BD_IF_BY_PHY_IF           /*!< Match entries containing given physical interface (argument is pfe_phy_if_t *) */
} pfe_l2br_domain_if_get_crit_t;

typedef enum
{
    L2SENT_CRIT_ALL,            /*!< Match any static entry (argument is NULL) */
    L2SENT_CRIT_BY_MAC,         /*!< Match static entry by mac (arg1 is NULL and arg2 is MAC) */
    L2SENT_CRIT_BY_VLAN,        /*!< Match static entry by vlan (arg1 is VLAN and arg2 is NULL) */
    L2SENT_CRIT_BY_MAC_VLAN     /*!< Match static entry by mac+vlan (arg1 is VLAN and arg2 is MAC) */
} pfe_l2br_static_ent_get_crit_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_l2br_domain_create(pfe_l2br_t *bridge, uint16_t vlan);
errno_t pfe_l2br_domain_destroy(pfe_l2br_domain_t *domain);
errno_t pfe_l2br_domain_set_ucast_action(pfe_l2br_domain_t *domain, pfe_ct_l2br_action_t hit, pfe_ct_l2br_action_t miss);
errno_t pfe_l2br_domain_set_mcast_action(pfe_l2br_domain_t *domain, pfe_ct_l2br_action_t hit, pfe_ct_l2br_action_t miss);
errno_t pfe_l2br_domain_add_if(pfe_l2br_domain_t *domain, pfe_phy_if_t *iface, bool_t tagged);
errno_t pfe_l2br_domain_del_if(pfe_l2br_domain_t *domain, const pfe_phy_if_t *iface);
errno_t pfe_l2br_domain_flush_by_if(const pfe_l2br_domain_t *domain, const pfe_phy_if_t *iface);
pfe_phy_if_t *pfe_l2br_domain_get_first_if(pfe_l2br_domain_t *domain, pfe_l2br_domain_if_get_crit_t crit, void *arg);
pfe_phy_if_t *pfe_l2br_domain_get_next_if(pfe_l2br_domain_t *domain);
errno_t pfe_l2br_domain_get_vlan(const pfe_l2br_domain_t *domain, uint16_t *vlan);
errno_t pfe_l2br_domain_get_ucast_action(const pfe_l2br_domain_t *domain, pfe_ct_l2br_action_t *hit, pfe_ct_l2br_action_t *miss);
errno_t pfe_l2br_domain_get_mcast_action(const pfe_l2br_domain_t *domain, pfe_ct_l2br_action_t *hit, pfe_ct_l2br_action_t *miss);
bool_t pfe_l2br_domain_is_default(const pfe_l2br_domain_t *domain) __attribute__((pure));
bool_t pfe_l2br_domain_is_fallback(const pfe_l2br_domain_t *domain) __attribute__((pure));
uint32_t pfe_l2br_domain_get_if_list(const pfe_l2br_domain_t *domain); __attribute__((pure))
uint32_t pfe_l2br_domain_get_untag_if_list(const pfe_l2br_domain_t *domain) __attribute__((pure));

errno_t pfe_l2br_static_entry_create(pfe_l2br_t *bridge, uint16_t vlan, const pfe_mac_addr_t mac, uint32_t new_fw_list);
errno_t pfe_l2br_static_entry_destroy(pfe_l2br_t *bridge, pfe_l2br_static_entry_t* static_ent);
errno_t pfe_l2br_static_entry_replace_fw_list(const pfe_l2br_t *bridge, pfe_l2br_static_entry_t* static_ent, uint32_t new_fw_list);
__attribute__((pure)) uint32_t pfe_l2br_static_entry_get_fw_list(const pfe_l2br_static_entry_t* static_ent);
__attribute__((pure)) uint16_t pfe_l2br_static_entry_get_vlan(const pfe_l2br_static_entry_t *static_ent);
void pfe_l2br_static_entry_get_mac(const pfe_l2br_static_entry_t *static_ent, pfe_mac_addr_t mac);
pfe_l2br_static_entry_t *pfe_l2br_static_entry_get_first(pfe_l2br_t *bridge, pfe_l2br_static_ent_get_crit_t crit, void* arg1,const void *arg2);
pfe_l2br_static_entry_t *pfe_l2br_static_entry_get_next(pfe_l2br_t *bridge);
errno_t pfe_l2br_static_entry_get_local_flag(const pfe_l2br_t *bridge, const pfe_l2br_static_entry_t* static_ent, bool_t *local);
errno_t pfe_l2br_static_entry_get_src_discard_flag(pfe_l2br_t *bridge, const pfe_l2br_static_entry_t* static_ent, bool_t *src_discard);
errno_t pfe_l2br_static_entry_get_dst_discard_flag(const pfe_l2br_t *bridge, const pfe_l2br_static_entry_t* static_ent, bool_t *dst_discard);
errno_t pfe_l2br_static_entry_set_local_flag(const pfe_l2br_t *bridge, pfe_l2br_static_entry_t* static_ent, bool_t local);
errno_t pfe_l2br_static_entry_set_src_discard_flag(const pfe_l2br_t *bridge, pfe_l2br_static_entry_t* static_ent, bool_t src_discard);
errno_t pfe_l2br_static_entry_set_dst_discard_flag(const pfe_l2br_t * bridge, pfe_l2br_static_entry_t* static_ent, bool_t dst_discard);

pfe_l2br_t *pfe_l2br_create(pfe_class_t *class, uint16_t def_vlan, uint16_t def_aging_time, uint16_t vlan_stats_size,
                            pfe_l2br_table_t *mac_table, pfe_l2br_table_t *vlan_table);
errno_t pfe_l2br_destroy(pfe_l2br_t *bridge);
pfe_l2br_domain_t *pfe_l2br_get_default_domain(const pfe_l2br_t *bridge) __attribute__((pure));
pfe_l2br_domain_t *pfe_l2br_get_fallback_domain(const pfe_l2br_t *bridge) __attribute__((pure));
pfe_l2br_domain_t *pfe_l2br_get_first_domain(pfe_l2br_t *bridge, pfe_l2br_domain_get_crit_t crit, void *arg);
pfe_l2br_domain_t *pfe_l2br_get_next_domain(pfe_l2br_t *bridge);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_l2br_get_text_statistics(const pfe_l2br_t *bridge, char_t *buf, uint32_t buf_len, uint8_t verb_level);
uint32_t pfe_l2br_domain_get_text_statistics(pfe_l2br_t *bridge, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

errno_t pfe_l2br_get_stats(const pfe_l2br_t *bridge, Eth_43_PFE_L2BridgeStatsType* stat, uint32_t index_entry);
uint32_t pfe_l2br_get_number_entries(const pfe_l2br_t *bridge);

errno_t pfe_l2br_clear_domain_stats(const pfe_l2br_t *bridge, uint8_t vlan_index);
errno_t pfe_l2br_get_domain_stats(const pfe_l2br_t *bridge, pfe_ct_vlan_stats_t *stat, uint8_t vlan_index);
uint8_t pfe_l2br_get_vlan_stats_index(const pfe_l2br_domain_t *domain);

errno_t pfe_l2br_flush_learned(pfe_l2br_t *bridge);
errno_t pfe_l2br_flush_static(pfe_l2br_t *bridge);
errno_t pfe_l2br_flush_all(pfe_l2br_t *bridge);
pfe_l2br_table_entry_t *pfe_l2br_static_entry_get_entry(pfe_l2br_static_entry_t *static_ent);
errno_t pfe_l2br_update_vlan_hash_entry(pfe_l2br_domain_t *domain);
errno_t pfe_l2br_add_vlan_hash_entry(pfe_l2br_domain_t *domain);
errno_t pfe_l2br_delete_vlan_hash_entry(pfe_l2br_domain_t *domain);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#else
typedef void pfe_l2br_t;
typedef void pfe_l2br_domain_t;
typedef void pfe_l2br_static_entry_t;
#endif /* PFE_CFG_L2BRIDGE_ENABLE */

#endif /* PUBLIC_PFE_L2BR_H_ */
