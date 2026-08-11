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
 *  Copyright 2017-2023 NXP
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
 * @file        fci_rt_db.h
 * @brief       Route database header file
 * @details
 *
 */

#ifndef SRC_FCI_RT_DB_H_
#define SRC_FCI_RT_DB_H_

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


#ifdef PFE_CFG_FCI_ENABLE
#ifdef PFE_CFG_PFE_MASTER

#include "fpp.h"        /* Due to IFNAMSIZ */
#include "pfe_rtable.h" /* IP and MAC address type */

/* Maximum capacity of entries available in FCI route database ISA */
#define FCI_CFG_RTDB_ENTRIES_CAPACITY (PFE_CFG_RT_HASH_SIZE + PFE_CFG_RT_COLLISION_SIZE)

/**
 * @brief   Route database entry type
 */
typedef struct
{
    void *refptr;                   /*  Reference pointer storage */
    uint32_t id;                    /*  Route entry identifier */
    uint16_t mtu;
    pfe_mac_addr_t src_mac;
    pfe_mac_addr_t dst_mac;
    pfe_ip_addr_t dst_ip;           /*  Destination IP (ipv4/ipv6) */
    pfe_phy_if_t *iface;            /*  Associated interface */
} fci_rt_db_entry_t;

/**
 * @brief   Route database select criteria type
 */
typedef enum
{
    RT_DB_CRIT_ALL,             /*!< Match any entry in the DB */
    RT_DB_CRIT_BY_IF,           /*!< Match entries by interface instance */
    RT_DB_CRIT_BY_IF_NAME,      /*!< Match entries by interface name */
    RT_DB_CRIT_BY_IP,           /*!< Match entries by destination IP address */
    RT_DB_CRIT_BY_MAC,          /*!< Match entries by destination MAC address */
    RT_DB_CRIT_BY_ID            /*!< Match entries by ID */
} fci_rt_db_get_criterion_t;

/**
 * @brief   Route database instance representation type
 */
typedef struct
{
    uint32_t next_item;                 /*  Current entry to be returned. See ...get_first() and ...get_next() */
    fci_rt_db_get_criterion_t cur_crit; /*  Current criterion */
    union
    {
        char_t outif_name[IFNAMSIZ];
        pfe_ip_addr_t dst_ip;
        pfe_mac_addr_t dst_mac;
        uint32_t id;
        const pfe_phy_if_t *iface;
    } cur_crit_arg;                     /*  Current criterion argument */
    /* route database entries storage ISA definition */
    pfe_isa_definition_t rtdb_entries_isa_def;
    /* route database entries storage ISA */
    pfe_isa_t rtdb_entries;
    /* route database entries storage ISA index */
    pfe_isa_index_t rtdb_entries_index[FCI_CFG_RTDB_ENTRIES_CAPACITY];
    /* route database entries storage ISA pool */
    fci_rt_db_entry_t rtdb_entries_pool[FCI_CFG_RTDB_ENTRIES_CAPACITY];
} fci_rt_db_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

void fci_rt_db_init(fci_rt_db_t *db);
errno_t fci_rt_db_add(fci_rt_db_t *db, pfe_ip_addr_t *dst_ip,
                    pfe_mac_addr_t *src_mac, pfe_mac_addr_t *dst_mac,
                    pfe_phy_if_t *iface, uint32_t id, void *refptr, bool_t overwrite);
errno_t fci_rt_db_remove(fci_rt_db_t *db, fci_rt_db_entry_t *entry);
errno_t fci_rt_db_drop_all(fci_rt_db_t *db);
fci_rt_db_entry_t *fci_rt_db_get_first(fci_rt_db_t *db, fci_rt_db_get_criterion_t crit, const void *arg);
fci_rt_db_entry_t *fci_rt_db_get_next(fci_rt_db_t *db);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_PFE_MASTER */
#endif /* PFE_CFG_FCI_ENABLE */

#endif /* SRC_FCI_RT_DB_H_ */

/** @}*/
