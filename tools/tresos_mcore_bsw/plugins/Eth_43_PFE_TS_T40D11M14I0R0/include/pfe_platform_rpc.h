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
 *  Copyright 2019-2024 NXP
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

#ifndef SRC_PFE_PLATFORM_RPC_H_
#define SRC_PFE_PLATFORM_RPC_H_

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

#include "oal.h"
#include "pfe_ct.h"

#ifdef PFE_CFG_FCI_ENABLE
#include "fci_msg.h"
#endif /* PFE_CFG_FCI_ENABLE */

typedef uint64_t pfe_platform_rpc_ptr_t;

ct_assert(sizeof(pfe_platform_rpc_ptr_t) == sizeof(uint64_t));

typedef enum __attribute__((packed))
{
    PFE_PLATFORM_RPC_PFE_PHY_IF_CREATE = 100U,              /* Arg: pfe_platform_rpc_pfe_phy_if_create_arg_t, Ret: None */
    /* All following PHY_IF commands have first arg struct member phy_if_id */
    PFE_PLATFORM_RPC_PFE_PHY_IF_ENABLE = 101U,              /* Arg: pfe_platform_rpc_pfe_phy_if_enable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_ID_COMPATIBLE_FIRST = PFE_PLATFORM_RPC_PFE_PHY_IF_ENABLE, /* first entry compatible with generic phy_if structure for args*/
    PFE_PLATFORM_RPC_PFE_PHY_IF_DISABLE = 102U,             /* Arg: pfe_platform_rpc_pfe_phy_if_disable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_ENABLE = 103U,      /* Arg: pfe_platform_rpc_pfe_phy_if_promisc_enable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_DISABLE = 104U,     /* Arg: pfe_platform_rpc_pfe_phy_if_promisc_disable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_ADD_MAC_ADDR = 105U,            /* Arg: pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_DEL_MAC_ADDR = 106U,            /* Arg: pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_GET_OP_MODE = 109U,         /* Arg: pfe_platform_rpc_pfe_phy_if_get_op_mode_arg_t, Ret: pfe_platform_rpc_pfe_phy_if_get_op_mode_ret_t */
    PFE_PLATFORM_RPC_PFE_PHY_IF_IS_ENABLED = 110U,          /* Arg: pfe_platform_rpc_pfe_phy_if_is_enabled_arg_t, Ret: pfe_platform_rpc_pfe_phy_if_is_enabled_ret_t */
    PFE_PLATFORM_RPC_PFE_PHY_IF_IS_PROMISC = 111U,          /* Arg: pfe_platform_rpc_pfe_phy_if_is_promisc_arg_t, Ret: pfe_platform_rpc_pfe_phy_if_is_promisc_ret_t */
    PFE_PLATFORM_RPC_PFE_PHY_IF_STATS = 112U,               /* Arg: pfe_platform_rpc_pfe_phy_if_stats_arg_t, Ret: pfe_platform_rpc_pfe_phy_if_stats_ret_t */
    PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS = 113U,     /* Arg: pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_ENABLE = 114U,     /* Arg: pfe_platform_rpc_pfe_phy_if_allmulti_enable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_DISABLE = 115U,        /* Arg: pfe_platform_rpc_pfe_phy_if_allmulti_disable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_ENABLE = 116U,             /* Arg: pfe_platform_rpc_pfe_phy_if_loopback_enable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_DISABLE = 117U,            /* Arg: pfe_platform_rpc_pfe_phy_if_loopback_disable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_ENABLE = 118U,          /* Arg: pfe_platform_rpc_pfe_phy_if_loadbalance_enable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_DISABLE = 119U,         /* Arg: pfe_platform_rpc_pfe_phy_if_loadbalance_disable_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_SET_BLOCK_STATE = 120U,             /* Arg: pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t, Ret: None */
    PFE_PLATFORM_RPC_PFE_PHY_IF_GET_BLOCK_STATE = 121U,             /* Arg: pfe_platform_rpc_pfe_phy_if_get_block_state_arg_t, Ret: pfe_platform_rpc_pfe_phy_if_get_block_state_ret_t */
    PFE_PLATFORM_RPC_PFE_PHY_IF_ID_COMPATIBLE_LAST = PFE_PLATFORM_RPC_PFE_PHY_IF_GET_BLOCK_STATE, /* last entry compatible with generic phy_if structure for args*/
    PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE = 122U,              /* Arg: pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t, Ret: pfe_platform_rpc_pfe_phy_if_get_stat_value_ret_t */

    /* Lock for atomic operations */
    PFE_PLATFORM_RPC_PFE_IF_LOCK = 190U,                        /* Arg: None, Ret: None */
    PFE_PLATFORM_RPC_PFE_IF_UNLOCK = 191U,                  /* Arg: None, Ret: None */

#if defined(PFE_CFG_FCI_ENABLE)
    PFE_PLATFORM_RPC_PFE_FCI_PROXY = 300U,                  /* Arg: pfe_platform_rpc_pfe_fci_proxy_arg_t, Ret: pfe_platform_rpc_pfe_fci_proxy_ret_t */
#endif /* PFE_CFG_FCI_ENABLE */

    PFE_PLATFORM_RPC_MDIO_PROXY = 310U                      /* Arg: pfe_platform_rpc_mdio_proxy_arg_t, Ret: pfe_platform_rpc_mdio_proxy_ret_t */
} pfe_platform_rpc_code_t;

/* Generic phy if type */
typedef struct __attribute__((packed, aligned(4)))
{
    uint8_t phy_if_id;
} pfe_platform_rpc_pfe_phy_if_generic_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_generic_t, phy_if_id));

typedef struct __attribute__((packed, aligned(4)))
{
    /*  Physical interface ID */
    pfe_ct_phy_if_id_t phy_if_id;
} pfe_platform_rpc_pfe_phy_if_create_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_create_arg_t, phy_if_id));

typedef struct __attribute__((packed, aligned(4)))
{
    /*  Boolean status */
    bool_t status;
} pfe_platform_rpc_pfe_phy_if_is_promisc_ret_t;

typedef pfe_platform_rpc_pfe_phy_if_is_promisc_ret_t pfe_platform_rpc_pfe_phy_if_is_enabled_ret_t;

typedef struct __attribute__((packed, aligned(4)))
{
    /*  Physical interface ID */
    pfe_ct_phy_if_id_t phy_if_id;
} pfe_platform_rpc_pfe_phy_if_enable_arg_t;

typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_disable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_disable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_promisc_enable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_promisc_enable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_promisc_disable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_promisc_disable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_generic_t pfe_platform_rpc_pfe_phy_if_get_op_mode_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_get_op_mode_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_generic_t pfe_platform_rpc_pfe_phy_if_is_promisc_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_is_promisc_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_generic_t pfe_platform_rpc_pfe_phy_if_is_enabled_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_is_enabled_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_generic_t pfe_platform_rpc_pfe_phy_if_stats_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_stats_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_allmulti_enable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_allmulti_enable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_allmulti_disable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_allmulti_disable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_loopback_enable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_loopback_enable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_loopback_disable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_loopback_disable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_loadbalance_enable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_loadbalance_enable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_enable_arg_t pfe_platform_rpc_pfe_phy_if_loadbalance_disable_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_loadbalance_disable_arg_t, phy_if_id));
typedef pfe_platform_rpc_pfe_phy_if_generic_t pfe_platform_rpc_pfe_phy_if_get_block_state_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_get_block_state_arg_t, phy_if_id));

typedef struct __attribute__((packed, aligned(4)))
{
    pfe_ct_phy_if_id_t phy_if_id;
    pfe_mac_db_crit_t crit;
    pfe_mac_type_t type;
} pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t, phy_if_id));

typedef struct __attribute__((packed, aligned(4)))
{
    /*  Physical interface ID */
    pfe_ct_phy_if_id_t phy_if_id;
    /*  MAC address */
    uint8_t mac_addr[6];
} pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t, phy_if_id));

typedef pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t, phy_if_id));

typedef struct __attribute__((packed, aligned(4)))
{
    /* Physical interface ID */
    pfe_ct_phy_if_id_t phy_if_id;
    /* Block state */
    pfe_ct_block_state_t block_state;
} pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t, phy_if_id));

typedef struct __attribute__((packed, aligned(4)))
{
    /*  Current operation mode */
    pfe_ct_if_op_mode_t mode;
} pfe_platform_rpc_pfe_phy_if_get_op_mode_ret_t;

typedef struct __attribute__((packed, aligned(4)))
{
    /* Current block state */
    pfe_ct_block_state_t state;
} pfe_platform_rpc_pfe_phy_if_get_block_state_ret_t;

typedef struct __attribute__((packed, aligned(4)))
{
    /*  Current phy if statistics */
    pfe_ct_phy_if_stats_t stats;
}pfe_platform_rpc_pfe_phy_if_stats_ret_t;

typedef struct __attribute__((packed, aligned(4)))
{
    /*  statistic value */
    uint32_t stat_val;
} pfe_platform_rpc_pfe_phy_if_get_stat_value_ret_t;

typedef struct __attribute__((packed, aligned(4)))
{
    pfe_ct_phy_if_id_t phy_if_id;
    uint32_t stat_id;
} pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t;
ct_assert_offsetof(0U == offsetof(pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t, phy_if_id));

#if defined(PFE_CFG_FCI_ENABLE)
typedef struct __attribute__((packed, aligned(4)))
{
    /*  FCI message type */
    msg_type_t type;
    /*  FCI command data */
    fci_msg_cmd_t msg_cmd;
} pfe_platform_rpc_pfe_fci_proxy_arg_t;

typedef struct __attribute__((packed, aligned(4)))
{
    /*  FCI reply data */
    fci_msg_cmd_t msg_cmd;
} pfe_platform_rpc_pfe_fci_proxy_ret_t;

#endif /* PFE_CFG_FCI_ENABLE */

/* MDIO proxy RPC operation type */
typedef enum __attribute__((packed))
{
    /* MDIO READ operation, Clause 22 */
    PFE_PLATFORM_RPC_MDIO_OP_READ_CL22 = 101U,
    /* MDIO WRITE operation, Clause 22 */
    PFE_PLATFORM_RPC_MDIO_OP_WRITE_CL22 = 102U,
    /* MDIO READ operation, Clause 45 */
    PFE_PLATFORM_RPC_MDIO_OP_READ_CL45 = 103U,
    /* MDIO WRITE operation, Clause 45 */
    PFE_PLATFORM_RPC_MDIO_OP_WRITE_CL45 = 104U
} pfe_platform_rpc_mdio_proxy_op_t;

/* MDIO proxy operation argument structure */
typedef struct __attribute__((packed, aligned(4)))
{
    /* PFE EMAC id */
    uint8_t emac_id;
    /* Supported MDIO operation */
    pfe_platform_rpc_mdio_proxy_op_t op;
    /* MDIO Device Port Address: 0-31U */
    uint8_t pa;
    /* MDIO Device Device Address: 0-31U */
    uint8_t dev;
    /* MDIO Device Register Address: 0-65535U */
    uint16_t ra;
    /* Value for WRITE operations */
    uint16_t val;
} pfe_platform_rpc_mdio_proxy_arg_t;

/* Data returned by MDIO proxy READ operations */
typedef struct __attribute__((packed, aligned(4)))
{
    uint16_t val;
} pfe_platform_rpc_mdio_proxy_ret_t;

#endif /* SRC_PFE_PLATFORM_RPC_H_ */
