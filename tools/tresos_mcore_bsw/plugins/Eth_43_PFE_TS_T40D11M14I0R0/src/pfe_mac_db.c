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
 *  Copyright 2021-2023 NXP
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#include "pfe_mac_db.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static bool_t pfe_mac_db_criterion_eval(const pfe_mac_db_list_entry_t *entry, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner);
static inline bool_t pfe_mac_db_check_crit_by_type(const pfe_mac_addr_t addr, pfe_mac_type_t type);


/**
 * @brief       Check if entry match with the rule
 * @param[in]   addr The address to check
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @return      TRUE if entry match with the rule, FALSE otherwise
 */
static inline bool_t pfe_mac_db_check_crit_by_type(const pfe_mac_addr_t addr, pfe_mac_type_t type)
{
    bool_t ret = FALSE;
    if ((type == PFE_TYPE_ANY) ||
        ((type == PFE_TYPE_MC) && (TRUE  == pfe_emac_is_multi(addr))) ||
        ((type == PFE_TYPE_BC) && (TRUE  == pfe_emac_is_broad(addr))) ||
        ((type == PFE_TYPE_UC) && (FALSE  == pfe_emac_is_multi(addr)))
       )
    {
        ret = TRUE;
    }
    return ret;
}

/**
 * @brief       Evaluate given DB entry against specified criterion
 * @param[in]   entry DB entry to evaluate
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner Required owner of MAC address
 * @return      TRUE if entry does match with criterion, FALSE otherwise
 */
static bool_t pfe_mac_db_criterion_eval(const pfe_mac_db_list_entry_t *entry, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
    bool_t ret = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (crit == MAC_DB_CRIT_BY_OWNER)
        {
            /* Return the first address where owner match */
            if (entry->owner == owner)
            {
                /* Break if entry match with the rule */
                ret = TRUE;
            }
        }
        else if (crit == MAC_DB_CRIT_BY_TYPE)
        {
            /* Break if entry match with the rule */
            ret = pfe_mac_db_check_crit_by_type(entry->addr, type);
        }
        else if (crit == MAC_DB_CRIT_BY_OWNER_AND_TYPE)
        {
            if (entry->owner == owner)
            {
                /* Break if entry match with the rule */
                ret = pfe_mac_db_check_crit_by_type(entry->addr, type);
            }
        }
        else if (crit == MAC_DB_CRIT_ALL)
        {
            /* Break if entry match with the rule */
            ret = TRUE;
        }
        else
        {
            NXP_LOG_WARNING("Unknown criterion\n");
        }
    }

    return ret;
}

/**
 * @brief       Create instance of MAC database
 * @param[in]   db Pointer to MAC database instance
 * @return      Execution status, EOK if success, error code otherwise
 */
errno_t pfe_mac_db_create(pfe_mac_db_t *db)
{
    errno_t ret;
    
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {        
        (void)autolibc_memset(db, 0, sizeof(pfe_mac_db_t));
        db->crit.crit = MAC_DB_CRIT_INVALID;
        db->next_item = 0U;

        db->isa_def.item_count = PFE_CFG_MAC_DB_ENTRIES_MAX;
        db->isa_def.item_size = sizeof(pfe_mac_db_list_entry_t);
        db->isa_def.flags.ordered = ISA_FLAG_STRICT_ORDER;
        db->isa_def.item_indexes = db->mac_list_idx;
        db->isa_def.items = db->mac_list_pool;
        db->isa_def.clear_cb = (pfe_isa_clear_cb_t)NULL_PTR;
        
        isa_init(&db->mac_list, &db->isa_def);
        ret = EOK;
    }
    return ret;
}

/**
 * @brief       Search for specific MAC address in the database and return pointer on related entry
 * @param[in]   db Pointer to MAC database instance
 * @param[in]   addr MAC address to search for
 * @param[in]       owner The identification of driver instance
 * @return      Pointer to related entry, NULL if address not found
 */
static pfe_mac_db_list_entry_t *pfe_mac_db_find_by_addr(const pfe_mac_db_t *db, const pfe_mac_addr_t addr,
                            pfe_drv_id_t owner)
{
    pfe_mac_db_list_entry_t *entry;
    const pfe_isa_t *isa = &db->mac_list;
    bool_t found = FALSE;

    for(uint32_t mac_idx = 0U; mac_idx < isa->occupied_items_count; mac_idx++)
    {
        entry = (pfe_mac_db_list_entry_t *) isa_item(isa, mac_idx);
        if ((NULL_PTR != entry) && (entry->owner == owner) && (0 == autolibc_memcmp(addr, entry->addr, sizeof(pfe_mac_addr_t))))
        {
            found = TRUE;
            break;
        }
    }
    
    if (FALSE == found)
    {
        entry = NULL_PTR;
    }

    return entry;
}

/**
 * @brief           Add new MAC address into database
 * @param[in]       db Pointer to MAC database instance
 * @param[in]       addr The MAC address to add
 * @param[in]       owner The identification of driver instance
 * @return          Execution status, EOK if success, error code otherwise
 */
errno_t pfe_mac_db_add_addr(pfe_mac_db_t *db, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret;
    pfe_mac_db_list_entry_t *entry;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Add only if the same address does not already exist in DB */
        entry = pfe_mac_db_find_by_addr(db, addr, owner);
        if (NULL_PTR == entry)
        {       
            /* Add address to local list */
            entry = (pfe_mac_db_list_entry_t *) isa_reserve(&db->mac_list);
            if (NULL_PTR == entry)
            {
                NXP_LOG_WARNING("Memory allocation failed\n");
                ret = ENOMEM;
            }
            else
            {
                (void)autolibc_memcpy(entry->addr, addr, sizeof(pfe_mac_addr_t));
                entry->owner = owner;

                ret = EOK;
            }
        }
        else
        {
            ret = EEXIST;
        }
    }

    return ret;
}

/**
 * @brief           Delete new address from database
 * @param[in]       db Pointer to MAC database instance
 * @param[in]       addr The MAC address to delete from database
 * @param[in]       owner Required owner of MAC address
 * @return          Execution status, EOK if success, error code otherwise
 */
errno_t pfe_mac_db_del_addr(pfe_mac_db_t *db, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret = ENOENT;
    pfe_mac_db_list_entry_t *entry;
    pfe_isa_t *isa = &db->mac_list;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        entry = pfe_mac_db_find_by_addr(db, addr, owner);
        if (NULL_PTR == entry)
        {
            NXP_LOG_DEBUG("MAC address was not found\n");
        }
        else
        {
            const int32_t item_index = isa_release(isa, entry);
            
            if (ISA_ITEM_NOT_FOUND != item_index)
            {
                if ((uint32_t)item_index < db->next_item)
                {
                    /*  If removed item had lower 'item_index' than 'next_item' then we need to decrease
                        'next_item' value. Adjust next_item value so we can call remove() between
                        get_first() and get_next() calls.
                    */
                    db->next_item--;
                }
                ret = EOK;
            }
        }
    }

    return ret;
}

/**
 * @brief       Flush all addresses matching with input rule
 * @param[in]   db Pointer to MAC database instance
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner Required owner of MAC address
 * @return      EOK success, error code otherwise
 */
errno_t pfe_mac_db_flush(pfe_mac_db_t *db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
    errno_t ret = EOK;
    const pfe_mac_db_list_entry_t *entry;
    pfe_isa_t *isa = &db->mac_list;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Remove associated MAC addresses due to flush mode */
        uint32_t mac_idx = 0U;
        while(mac_idx < isa->occupied_items_count)
        {
            entry = (pfe_mac_db_list_entry_t *) isa_item(isa, mac_idx);
            if (NULL_PTR != entry)
            {
                if (TRUE == pfe_mac_db_criterion_eval(entry, crit, type, owner))
                {
                    (void) isa_release_subscript(isa, mac_idx);
                    if (mac_idx < db->next_item)
                    {
                        /*  If removed item had lower 'item_index' than 'next_item' then we need to decrease
                            'next_item' value. Adjust next_item value so we can call flush() between
                            get_first() and get_next() calls.
                        */
                        db->next_item--;
                    }
                }
                else
                {
                    mac_idx++;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief       Get first MAC address from database matching by input rule. Function stores database context
 *              for following call of pfe_mac_get_next_addr(). Function should not be called internally
 *              inside this module
 * @param[in]   db Pointer to MAC database instance
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner Required owner of MAC address
 * @param[out]  addr Returned MAC address
 * @return      Execution status, EOK success, error code otherwise
 */
errno_t pfe_mac_db_get_first_addr(pfe_mac_db_t *db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner, pfe_mac_addr_t addr)
{
    errno_t ret = ENOENT;
    const pfe_mac_db_list_entry_t *entry = NULL_PTR;
    const pfe_isa_t *isa = &db->mac_list;
    bool_t found = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for(db->next_item = 0U; db->next_item < isa->occupied_items_count; db->next_item++)
        {
            entry = (pfe_mac_db_list_entry_t *) isa_item(isa, db->next_item);
            if ((NULL_PTR != entry))
            {
                if (TRUE == pfe_mac_db_criterion_eval(entry, crit, type, owner))
                {
                    found = TRUE;
                    break;
                }
            }            
        }

        if (TRUE == found)
        {
            (void) autolibc_memcpy(addr, entry->addr, sizeof(pfe_mac_addr_t));
            db->next_item++;
            db->crit.crit = crit;
            db->crit.owner = owner;
            db->crit.type = type;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Get next MAC address from database. Function expect that pfe_mac_get_first_addr() was
 *              executed before and stores database context. Function should not be called internally
 *              inside this module
 * @param[in]   db Pointer to MAC database instance
 * @param[out]  addr Returned MAC address
 * @return      Execution status, EOK success, error code otherwise
 */
errno_t pfe_mac_db_get_next_addr(pfe_mac_db_t *db, pfe_mac_addr_t addr)
{
    errno_t ret = EOK;
    const pfe_mac_db_list_entry_t *entry = NULL_PTR;
    const pfe_isa_t *isa = &db->mac_list;
    bool_t found = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        while(db->next_item < isa->occupied_items_count)
        {
            entry = (pfe_mac_db_list_entry_t *) isa_item(isa, db->next_item);
            db->next_item++;
            if ((NULL_PTR != entry))
            {
                if (TRUE == pfe_mac_db_criterion_eval(entry, db->crit.crit, db->crit.type, db->crit.owner))
                {
                    found = TRUE;
                    break;
                }
            }
        }

        if (TRUE == found)
        {
            (void) autolibc_memcpy(addr, entry->addr, sizeof(pfe_mac_addr_t));
        }
        else
        {
            ret = ENOENT;
        }
    }

    return ret;
}

/**
 * @brief       Search for specific MAC address in the database and return pointer on related entry
 * @param[in]   db Pointer to MAC database instance
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner Required owner of MAC address
 * @param[out]  match_entry Returned db entry, may be NULL if not interested
 * @return      EOK     success
 * @return      ENOENT  not found
 * @return      EINVAL  NULL argument received
 */
errno_t pfe_mac_db_find_by_crit(pfe_mac_db_t *db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner, pfe_mac_db_list_entry_t *match_entry)
{
    errno_t ret = ENOENT;
    const pfe_mac_db_list_entry_t *entry = NULL_PTR;
    const pfe_isa_t *isa = &db->mac_list;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for(uint32_t db_idx = 0U; db_idx < isa->occupied_items_count; db_idx++)
        {
            entry = (pfe_mac_db_list_entry_t *) isa_item(isa, db_idx);
            if ((NULL_PTR != entry))
            {
                if (TRUE == pfe_mac_db_criterion_eval(entry, crit, type, owner))
                {
                    if (NULL_PTR != match_entry)
                    {
                        (void) autolibc_memcpy(match_entry->addr, entry->addr, sizeof(pfe_mac_addr_t));
                        match_entry->owner = entry->owner;
                    }
                    ret = EOK;
                    break;
                }
            }            
        }
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
