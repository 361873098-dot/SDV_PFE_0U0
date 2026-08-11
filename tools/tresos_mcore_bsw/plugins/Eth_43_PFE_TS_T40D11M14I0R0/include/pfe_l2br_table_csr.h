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

#ifndef HW_S32G_PFE_L2BR_TABLE_CSR_H_
#define HW_S32G_PFE_L2BR_TABLE_CSR_H_

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

#ifndef PFE_CBUS_H_
#error Missing cbus.h
#endif /* PFE_CBUS_H_ */

#include "pfe_class_csr.h"

#define MAC2F_TABLE_HASH_ENTRIES        256U /* Must be power-of-2 */
#define MAC2F_TABLE_COLL_ENTRIES        256U
#define MAC2F_TABLE_HASH_SPACE_START    0U
#define MAC2F_TABLE_COLL_SPACE_START    MAC2F_TABLE_HASH_ENTRIES

#define HOST_MAC2F_CMD_REG              (CLASS_DAMACHASH_HOST_CMD_REG)
#define HOST_MAC2F_MAC1_ADDR_REG        (CLASS_DAMACHASH_HOST_MAC_ADDR1_REG)
#define HOST_MAC2F_MAC2_ADDR_REG        (CLASS_DAMACHASH_HOST_MAC_ADDR2_REG)
#define HOST_MAC2F_MAC3_ADDR_REG        (CLASS_DAMACHASH_HOST_MAC_ADDR3_REG)
#define HOST_MAC2F_MAC4_ADDR_REG        (CLASS_DAMACHASH_HOST_MAC_ADDR4_REG)
#define HOST_MAC2F_MAC5_ADDR_REG        (CLASS_DAMACHASH_HOST_MAC_ADDR5_REG)
#define HOST_MAC2F_ENTRY_REG            (CLASS_DAMACHASH_HOST_ENTRY_REG)
#define HOST_MAC2F_STATUS_REG           (CLASS_DAMACHASH_HOST_STATUS_REG)
#define HOST_MAC2F_DIRECT_REG           (CLASS_DAMACHASH_HOST_DIRECT)

#define HOST_MAC2F_FREE_LIST_ENTRIES    (CLASS_DAMACHASH_FREELIST_ENTRIES)
#define HOST_MAC2F_FREE_LIST_HEAD_PTR   (CLASS_DAMACHASH_FREELIST_HEAD_PTR)
#define HOST_MAC2F_FREE_LIST_TAIL_PTR   (CLASS_DAMACHASH_FREELIST_TAIL_PTR)

#define VLAN_TABLE_HASH_ENTRIES         64U /* Must be power-of-2 */
#define VLAN_TABLE_COLL_ENTRIES         64U
#define VLAN_TABLE_HASH_SPACE_START     0U
#define VLAN_TABLE_COLL_SPACE_START     VLAN_TABLE_HASH_ENTRIES

#define HOST_VLAN_CMD_REG               (CLASS_DAVLANHASH_HOST_CMD_REG)
#define HOST_VLAN_MAC1_ADDR_REG         (CLASS_DAVLANHASH_HOST_MAC_ADDR1_REG)
#define HOST_VLAN_MAC2_ADDR_REG         (CLASS_DAVLANHASH_HOST_MAC_ADDR2_REG)
#define HOST_VLAN_MAC3_ADDR_REG         (CLASS_DAVLANHASH_HOST_MAC_ADDR3_REG)
#define HOST_VLAN_MAC4_ADDR_REG         (CLASS_DAVLANHASH_HOST_MAC_ADDR4_REG)
#define HOST_VLAN_MAC5_ADDR_REG         (CLASS_DAVLANHASH_HOST_MAC_ADDR5_REG)
#define HOST_VLAN_ENTRY_REG             (CLASS_DAVLANHASH_HOST_ENTRY_REG)
#define HOST_VLAN_STATUS_REG            (CLASS_DAVLANHASH_HOST_STATUS_REG)
#define HOST_VLAN_DIRECT_REG            (CLASS_DAVLANHASH_HOST_DIRECT)

#define HOST_VLAN_FREE_LIST_ENTRIES     (CLASS_DAVLANHASH_FREELIST_ENTRIES)
#define HOST_VLAN_FREE_LIST_HEAD_PTR    (CLASS_DAVLANHASH_FREELIST_HEAD_PTR)
#define HOST_VLAN_FREE_LIST_TAIL_PTR    (CLASS_DAVLANHASH_FREELIST_TAIL_PTR)

#define STATUS_REG_CMD_DONE             (1U << 0)
#define STATUS_REG_SIG_ENTRY_NOT_FOUND  (1U << 1)
#define STATUS_REG_SIG_INIT_DONE        (1U << 2)
#define STATUS_REG_SIG_ENTRY_ADDED      (1U << 3)
#define STATUS_REG_MATCH                (1U << 4)

typedef enum
{
    L2BR_CMD_INIT = 0x1,
    L2BR_CMD_ADD = 0x2,
    L2BR_CMD_DELETE = 0x3,
    L2BR_CMD_UPDATE = 0x4,
    L2BR_CMD_SEARCH = 0x5,
    L2BR_CMD_MEM_READ = 0x6,
    L2BR_CMD_MEM_WRITE = 0x7,
    L2BR_CMD_FLUSH = 0x8
} pfe_l2br_table_cmd_t;

#endif /* HW_S32G_PFE_L2BR_TABLE_CSR_H_ */
