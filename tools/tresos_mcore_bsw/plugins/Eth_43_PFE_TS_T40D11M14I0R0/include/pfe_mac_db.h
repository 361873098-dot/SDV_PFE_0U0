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

#ifndef PUBLIC_PFE_MAC_DB_H_
#define PUBLIC_PFE_MAC_DB_H_

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

#include "oal_types.h"

#include "pfe_ct.h"
#include "isa.h"

#define PFE_MAC_DB_LOCKED   TRUE
#define PFE_MAC_DB_UNLOCKED FALSE

/**
 * @brief   The MAC address type
 * @details Bytes are represented as:
 *          \code
 *              pfe_mac_addr_t mac;
 *
 *              emac[0] = 0xaa;
 *              emac[1] = 0xbb;
 *              emac[2] = 0xcc;
 *              emac[3] = 0xdd;
 *              emac[4] = 0xee;
 *              emac[5] = 0xff;
 *
 *              printf("The MAC address is: %x:%x:%x:%x:%x:%x\n",
 *                      mac[0], emac[1], mac[2], mac[3], mac[4], mac[5]);
 *          \endcode
 */
typedef uint8_t pfe_mac_addr_t[6];

/**
 * @brief   Possible types of MAC addresses used while getting or flushing
 */
typedef enum
{
    PFE_TYPE_UC,
    PFE_TYPE_MC,
    PFE_TYPE_BC,
    PFE_TYPE_ANY
} pfe_mac_type_t;

typedef struct
{
    pfe_mac_addr_t addr;        /*  The MAC address */
    pfe_drv_id_t owner;         /*  Identification of the driver that owns this entry */
} pfe_mac_db_list_entry_t;

/**
 * @brief   Possible rules to get or flush some sort of MAC addresses
 */
typedef enum __attribute__ ((packed))
{
    MAC_DB_CRIT_BY_TYPE = 0U,
    MAC_DB_CRIT_BY_OWNER,
    MAC_DB_CRIT_BY_OWNER_AND_TYPE,
    MAC_DB_CRIT_ALL,
    MAC_DB_CRIT_INVALID,
} pfe_mac_db_crit_t;

typedef struct
{
    pfe_isa_t mac_list;
    struct {
        pfe_mac_db_crit_t crit;
        pfe_drv_id_t owner;
        pfe_mac_type_t type;
    } crit;
    pfe_isa_index_t mac_list_idx[PFE_CFG_MAC_DB_ENTRIES_MAX];
    pfe_mac_db_list_entry_t mac_list_pool[PFE_CFG_MAC_DB_ENTRIES_MAX];
    pfe_isa_definition_t isa_def;
    uint32_t next_item;
} pfe_mac_db_t;


#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_mac_db_create(pfe_mac_db_t *db);
errno_t pfe_mac_db_add_addr(pfe_mac_db_t *db, const pfe_mac_addr_t addr, pfe_drv_id_t owner);
errno_t pfe_mac_db_del_addr(pfe_mac_db_t *db, const pfe_mac_addr_t addr, pfe_drv_id_t owner);
errno_t pfe_mac_db_flush(pfe_mac_db_t *db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner);
errno_t pfe_mac_db_get_first_addr(pfe_mac_db_t *db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner, pfe_mac_addr_t addr);
errno_t pfe_mac_db_get_next_addr(pfe_mac_db_t *db, pfe_mac_addr_t addr);
errno_t pfe_mac_db_find_by_crit(pfe_mac_db_t *db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner, pfe_mac_db_list_entry_t *match_entry);

/**
 * @brief       Check if given MAC address is zero
 * @param[in]   addr The address to check
 * @return      TRUE if the input address is zero
 */
static inline bool_t pfe_emac_is_zero(const pfe_mac_addr_t addr)
{
    bool_t ReVal;
    if (0x0U == ((uint32_t)addr[0] | addr[1] | addr[2] | addr[3] | addr[4] | addr[5]))
    {
        ReVal = TRUE;
    }
    else
    {
        ReVal = FALSE;
    }
    return ReVal;
}

/**
 * @brief       Check if given MAC address is broadcast
 * @param[in]   addr The address to check
 * @return      TRUE if the input address is broadcast
 */
static inline bool_t pfe_emac_is_broad(const pfe_mac_addr_t addr)
{
    bool_t ReVal;
    if (0xffU == (addr[0] & addr[1] & addr[2] & addr[3] & addr[4] & addr[5]))
    {
        ReVal = TRUE;
    }
    else
    {
        ReVal = FALSE;
    }
    return ReVal;
}

/**
 * @brief       Check if given MAC address is multicast
 * @param[in]   addr The address to check
 * @return      TRUE if the input address is multicast
 */
static inline bool_t pfe_emac_is_multi(const pfe_mac_addr_t addr)
{
    bool_t ReVal;
    if ((FALSE == pfe_emac_is_broad(addr)) && (0U != (addr[0] & 0x1U)))
    {
        ReVal = TRUE;
    }
    else
    {
        ReVal = FALSE;
    }
    return ReVal;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_MAC_DB_H_ */
