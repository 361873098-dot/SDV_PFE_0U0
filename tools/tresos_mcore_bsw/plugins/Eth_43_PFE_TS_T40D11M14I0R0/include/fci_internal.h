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
 * @addtogroup  dxgr_FCI
 * @{
 *
 * @file        fci_internal.c
 * @brief       Internal header distributing FCI-related artifacts not intended
 *              to be exposed to public.
 * @details
 *
 */

#ifndef SRC_FCI_INTERNAL_H_
#define SRC_FCI_INTERNAL_H_

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

#include "pfe_cfg.h"
#include "oal.h"

#include "libfci.h"
#include "fpp.h"
#include "fpp_ext.h"
#include "pfe_if_db.h"
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#include "fci_ownership_mask.h"
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#include "fci.h"
#include "fci_msg.h"   /* The IPC message format (fci_msg_t) */
#include "fci_core.h"  /* The OS-specific FCI core */
#ifdef PFE_CFG_RTABLE_ENABLE
#include "fci_rt_db.h" /* Database of routes */
#endif /* PFE_CFG_RTABLE_ENABLE */

#ifdef PFE_CFG_FCI_ENABLE

/**
 * @brief   This is the FCI endpoint representation structure.
 */
struct fci_tag
{
    fci_core_t *core;

    pfe_if_db_t *phy_if_db;         /* Pointer to platform driver phy_if DB */
    bool_t phy_if_db_initialized;   /* Logical interface DB was initialized */

    pfe_if_db_t *log_if_db;         /* Pointer to platform driver log_if DB */
    bool_t log_if_db_initialized;   /* Logical interface DB was initialized */

    uint32_t if_session_id;         /* Holds session ID for interface session */

    #ifdef PFE_CFG_PFE_MASTER
    #ifdef PFE_CFG_RTABLE_ENABLE
    fci_rt_db_t route_db;
    #endif /* PFE_CFG_RTABLE_ENABLE */
    #endif /* PFE_CFG_PFE_MASTER */
    
    #ifdef PFE_CFG_RTABLE_ENABLE
    bool_t rt_db_initialized;
    pfe_rtable_t *rtable;
    bool_t rtable_initialized;
    #endif /* PFE_CFG_RTABLE_ENABLE */

    #ifdef PFE_CFG_L2BRIDGE_ENABLE
    pfe_l2br_t *l2_bridge;
    bool_t l2_bridge_initialized;
    #endif /* PFE_CFG_L2BRIDGE_ENABLE */

    pfe_tmu_t *tmu;                 /* Pointer to platform driver tmu */
    bool_t tmu_initialized;         /* Platform TMU was initialized */

    pfe_class_t *class;

    struct
    {
        uint32_t timeout_tcp;
        uint32_t timeout_udp;
        uint32_t timeout_other;
    } default_timeouts;

    bool_t hm_cb_registered;
    bool_t is_some_client;          /* TRUE if there is at least one client registered for FCI events. */

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    bool_t fci_owner_initialized;
#endif /* #ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT */

    bool_t fci_initialized;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/* Global variable used across all fci files */
extern fci_t context;

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t fci_interfaces_session_cmd(uint32_t code, uint16_t *fci_ret);
errno_t fci_interfaces_log_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_log_if_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_interfaces_phy_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_phy_if_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_interfaces_mac_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_if_mac_cmd_t *reply_buf, uint32_t *reply_len);
#ifdef PFE_CFG_RTABLE_ENABLE
errno_t fci_routes_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_rt_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_connections_ipv4_ct_cmd(const fci_msg_t *msg, uint16_t *fci_ret, fpp_ct_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_connections_ipv6_ct_cmd(const fci_msg_t *msg, uint16_t *fci_ret, fpp_ct6_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_connections_ipv4_timeout_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_timeout_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_connections_drop_one(pfe_rtable_entry_t *entry);
errno_t fci_connections_set_default_timeout(uint8_t ip_proto, uint32_t timeout);
uint32_t fci_connections_get_default_timeout(uint8_t ip_proto);
void fci_routes_drop_all(void);
void fci_routes_drop_all_ipv4(void);
void fci_routes_drop_all_ipv6(void);
void fci_connections_drop_all(void);
#endif /* PFE_CFG_RTABLE_ENABLE */
#ifdef PFE_CFG_L2BRIDGE_ENABLE
errno_t fci_l2br_domain_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_l2_bd_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_l2br_static_entry_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_l2_static_ent_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_l2br_flush_cmd(uint32_t code, uint16_t *fci_ret);
#endif /* PFE_CFG_L2BRIDGE_ENABLE */
#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_RTABLE_ENABLE
errno_t fci_routes_drop_one(fci_rt_db_entry_t *route);
#endif /* PFE_CFG_RTABLE_ENABLE */
#endif /* PFE_CFG_PFE_MASTER */
errno_t fci_qos_queue_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_queue_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_qos_scheduler_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_scheduler_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_qos_shaper_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_shaper_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_qos_policer_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_policer_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_qos_policer_flow_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_policer_flow_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_qos_policer_wred_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_policer_wred_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_qos_policer_shp_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_qos_policer_shp_cmd_t *reply_buf, uint32_t *reply_len);
void fci_hm_send_events(void);
errno_t fci_hm_cb_register(void);
errno_t fci_hm_cb_deregister(void);
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
errno_t fci_owner_session_cmd(pfe_ct_phy_if_id_t sender, uint32_t code, uint16_t *fci_ret);
errno_t fci_owner_get_floating_lock(pfe_ct_phy_if_id_t sender, uint16_t *fci_ret, bool_t *floating_lock);
errno_t fci_owner_clear_floating_lock(void);
errno_t fci_owner_authorize(pfe_ct_phy_if_id_t sender, bool_t *auth_ret);
errno_t fci_sender_get_phy_if_id(uint32_t sender, pfe_ct_phy_if_id_t *phy_if_id);
errno_t fci_owner_mutex_lock(void);
errno_t fci_owner_mutex_unlock(void);
errno_t fci_owner_init(fci_init_info_t *info);
#endif /* #ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT */
errno_t fci_timer_owner_lock_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_timer_cmd_t *reply_buf, uint32_t *reply_len);
errno_t fci_timer_owner_unlock_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_timer_cmd_t *reply_buf, uint32_t *reply_len);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_FCI_ENABLE */
#endif /* SRC_FCI_INTERNAL_H_ */

/** @}*/
