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
 *  Copyright 2017-2024 NXP
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
 * @file        fci_rt_db.c
 * @brief       Route database
 * @details     Route database is intended to store IP routes and provide
 *              functions to select or remove particular entries.
 *
 * @warning     All API calls related to a single DB instance must be protected
 *              from being preempted by another API calls related to the same
 *              DB instance.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "isa.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE
#ifdef PFE_CFG_RTABLE_ENABLE
#include "fci_rt_db.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static bool_t fci_rt_db_match_criterion(fci_rt_db_t *db, const fci_rt_db_entry_t *entry);
#if defined(PFE_CFG_NULL_ARG_CHECK)
static bool_t rt_db_null_arg_check(fci_rt_db_t *db, fci_rt_db_get_criterion_t crit, const void *arg);


/**
 * @brief       Auxiliary function fur fci_rt_db_get_first() to check for NULL argument
 */
static bool_t rt_db_null_arg_check(fci_rt_db_t *db, fci_rt_db_get_criterion_t crit, const void *arg)
{
    bool_t ret_value = FALSE;


    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_value = TRUE;
    }
    else if (unlikely((RT_DB_CRIT_ALL != crit) && (NULL_PTR == arg)))
    {
        /*  All criterions except RT_DB_CRIT_ALL require non-NULL argument */
        NXP_LOG_ERROR("NULL argument received\n");
        ret_value = TRUE;
    }
    else
    {
        ret_value = FALSE;
    }

    return ret_value;
}
#endif /* PFE_CFG_NULL_ARG_CHECK */

/**
 * @brief       Match entry with latest criterion provided via fci_rt_db_get_first()
 * @param[in]   db The route DB instance
 * @param[in]   entry The entry to be matched
 * @retval      True Entry matches the criterion
 * @retval      False Entry does not match the criterion
 */
static bool_t fci_rt_db_match_criterion(fci_rt_db_t *db, const fci_rt_db_entry_t *entry)
{
    bool_t match = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == db) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        match = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (db->cur_crit)
        {
            case RT_DB_CRIT_ALL:
            {
                match = TRUE;
                break;
            }

            case RT_DB_CRIT_BY_IF:
            {
                match = (entry->iface == db->cur_crit_arg.iface);
                break;
            }

            case RT_DB_CRIT_BY_IF_NAME:
            {
                match = (0 == autolibc_strcmp(db->cur_crit_arg.outif_name, pfe_phy_if_get_name(entry->iface)));
                break;
            }

            case RT_DB_CRIT_BY_IP:
            {
                match = (0 == autolibc_memcmp(&db->cur_crit_arg.dst_ip, &entry->dst_ip, sizeof(pfe_ip_addr_t)));
                break;
            }

            case RT_DB_CRIT_BY_MAC:
            {
                match = (0 == autolibc_memcmp(&db->cur_crit_arg.dst_mac, &entry->dst_mac, sizeof(pfe_mac_addr_t)));
                break;
            }

            case RT_DB_CRIT_BY_ID:
            {
                match = (db->cur_crit_arg.id == entry->id);
                break;
            }

            default:
            {
                NXP_LOG_WARNING("Unknown criterion\n");
                match = FALSE;
                break;
            }
        }
    }
    return match;
}

/**
 * @brief       Initialize DB
 * @param[in]   db The route DB instance
 */
void fci_rt_db_init(fci_rt_db_t *db)
{
    pfe_isa_definition_t *rtdb_isa_def;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* initialize FCI route database entries storage ISA properties definition */
        rtdb_isa_def = &db->rtdb_entries_isa_def;
        rtdb_isa_def->item_count = FCI_CFG_RTDB_ENTRIES_CAPACITY;
        rtdb_isa_def->item_size = (uint32_t)sizeof(fci_rt_db_entry_t);
        rtdb_isa_def->flags.ordered = ISA_FLAG_STRICT_ORDER;
        rtdb_isa_def->item_indexes = db->rtdb_entries_index;
        rtdb_isa_def->items = db->rtdb_entries_pool;
        rtdb_isa_def->clear_cb = (pfe_isa_clear_cb_t)NULL_PTR;

        /* Initialize FCI route database entries ISA container */
        isa_init(&db->rtdb_entries, rtdb_isa_def);
    }
}

/**
 * @brief       Add a route to DB
 * @param[in]   db The route DB instance
 * @param[in]   src_mac Source MAC address
 * @param[in]   dst_mac Destination MAC address
 * @param[in]   iface Name of the output interface
 * @param[in]   id The route ID
 * @param[in]   refptr Reference pointer to be bound with entry
 * @param[in]   overwrite If true then if route exists, it is updated
 * @retval      EOK Success
 * @retval      ENOMEM Memory allocation failed
 * @retval      EPERM Attempt to insert already existing entry without 'overwrite' set to 'true'
 * @retval      EINVAL Input arguments check fail
 */
errno_t fci_rt_db_add(fci_rt_db_t *db,  pfe_ip_addr_t *dst_ip,
                    pfe_mac_addr_t *src_mac, pfe_mac_addr_t *dst_mac,
                    pfe_phy_if_t *iface, uint32_t id, void *refptr, bool_t overwrite)
{
    fci_rt_db_entry_t *new_entry;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == dst_ip) || (NULL_PTR == src_mac) || (NULL_PTR == dst_mac) || (NULL_PTR == iface)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Check duplicates by route ID */
        new_entry = fci_rt_db_get_first(db, RT_DB_CRIT_BY_ID, (void *)&id);
        if (NULL_PTR == new_entry)
        {
            new_entry = (fci_rt_db_entry_t *)isa_reserve(&db->rtdb_entries);
            if (NULL_PTR == new_entry)
            {
                NXP_LOG_ERROR("FCI RTDB ISA exhausted, no more entries left\n");
                ret = ENOMEM;
            }
            else
            {
                (void)autolibc_memset(new_entry, 0, sizeof(fci_rt_db_entry_t));
            }
        }
        else if (FALSE == overwrite)
        {
            ret = EPERM;
        }
        else
        {
            /*Do nothing - Avoid MISRA rule 15.7 */
        }

        if(EOK == ret)
        {
            /*  Store values */
            (void)autolibc_memcpy(&new_entry->dst_ip, dst_ip, sizeof(pfe_ip_addr_t));
            (void)autolibc_memcpy(&new_entry->src_mac, src_mac, sizeof(pfe_mac_addr_t));
            (void)autolibc_memcpy(&new_entry->dst_mac, dst_mac, sizeof(pfe_mac_addr_t));
            new_entry->iface = iface;
            new_entry->id = id;
            new_entry->mtu = 0; /* Not supported yet */
            new_entry->refptr = refptr;
        }
    }
    return ret;
}

/**
 * @brief       Remove entry from DB
 * @param[in]   db The route DB instance
 * @param[in]   entry Entry to be removed. If the call is successful the entry
 *                    becomes invalid and shall not be accessed.
 * @return      EOK if success, error code otherwise
 */
errno_t fci_rt_db_remove(fci_rt_db_t *db, fci_rt_db_entry_t *entry)
{
    int32_t entry_subscript;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        entry_subscript = isa_release(&db->rtdb_entries, entry);
        if ((entry_subscript >= 0) && (entry_subscript < (int32_t)db->next_item))
        {
            /*  Decrease the iterator so we can call destroy() between get_first()
                and get_next() calls. */
            db->next_item--;
        }
    }

    return ret;
}

/**
 * @brief       Get first record from the DB matching given criterion
 * @details     Intended to be used with fci_rt_db_get_next
 * @param[in]   db The route DB instance
 * @param[in]   crit Get criterion
 * @param[in]   art Pointer to criterion argument
 * @return      The entry or NULL if not found
 * @warning     The returned entry must not be accessed after fci_rt_db_remove(entry)
 *              or fci_rt_db_drop_all() has been called.
 */
fci_rt_db_entry_t *fci_rt_db_get_first(fci_rt_db_t *db, fci_rt_db_get_criterion_t crit, const void *arg)
{
    fci_rt_db_entry_t *entry = NULL_PTR;
    bool_t is_unknown_crit = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (likely(rt_db_null_arg_check(db, crit, arg) == FALSE))
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Remember criterion and argument for possible subsequent fci_rt_db_get_next() calls */
        db->cur_crit = crit;
        switch (db->cur_crit)
        {
            case RT_DB_CRIT_ALL:
            {
                break;
            }

            case RT_DB_CRIT_BY_IF:
            {
                db->cur_crit_arg.iface = (const pfe_phy_if_t *)arg;
                break;
            }

            case RT_DB_CRIT_BY_IF_NAME:
            {
                (void)autolibc_memset(db->cur_crit_arg.outif_name, 0, sizeof(db->cur_crit_arg.outif_name));
                (void)autolibc_strncpy(db->cur_crit_arg.outif_name, arg, sizeof(db->cur_crit_arg.outif_name)-1U);
                break;
            }

            case RT_DB_CRIT_BY_IP:
            {
                (void)autolibc_memcpy(&db->cur_crit_arg.dst_ip, arg, sizeof(db->cur_crit_arg.dst_ip));
                break;
            }

            case RT_DB_CRIT_BY_MAC:
            {
                (void)autolibc_memcpy(&db->cur_crit_arg.dst_mac, arg, sizeof(db->cur_crit_arg.dst_mac));
                break;
            }

            case RT_DB_CRIT_BY_ID:
            {
                (void)autolibc_memcpy(&db->cur_crit_arg.id, arg, sizeof(db->cur_crit_arg.id));
                break;
            }

            default:
            {
                NXP_LOG_WARNING("Unknown criterion\n");
                is_unknown_crit = TRUE;
                break;
            }
        }

        if(TRUE != is_unknown_crit)
        {
            db->next_item = 0U;
            entry = fci_rt_db_get_next(db);
        }
    }

    return entry;
}

/**
 * @brief       Get next record from the DB
 * @details     Intended to be used with fci_rt_db_get_first.
 * @param[in]   db The route DB instance
 * @return      The entry or NULL if not found
 * @warning     The returned entry must not be accessed after fci_rt_db_remove(entry)
 *              or fci_rt_db_drop_all() has been called.
 */
fci_rt_db_entry_t *fci_rt_db_get_next(fci_rt_db_t *db)
{
    fci_rt_db_entry_t *entry;
    bool_t match = FALSE;
    pfe_isa_t *isa;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        entry = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        isa = &db->rtdb_entries;

        /* traverse FCI route database */
        while (db->next_item < isa->occupied_items_count)
        {
            entry = (fci_rt_db_entry_t *)isa_item(isa, db->next_item);

            /* Remember current item to know where to start later */
            db->next_item++;

            if (NULL_PTR != entry)
            {
                match = fci_rt_db_match_criterion(db, entry);
                if (TRUE == match)
                {
                    break;
                }
            }
        }

        if (FALSE == match)
        {
            entry = NULL_PTR;
        }
    }

    return entry;
}

/**
 * @brief       Remove all entries
 * @param[in]   db The route DB instance
 * @return      EOK if success, error code otherwise
 */
errno_t fci_rt_db_drop_all(fci_rt_db_t *db)
{
    uint32_t index;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for(index = db->rtdb_entries.occupied_items_count; index > 0U; index--)
        {
            (void)isa_release_subscript(&db->rtdb_entries, index - 1U);
        }
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_RTABLE_ENABLE */
#endif /* PFE_CFG_FCI_ENABLE */
#endif /* PFE_CFG_PFE_MASTER */
/** @}*/
