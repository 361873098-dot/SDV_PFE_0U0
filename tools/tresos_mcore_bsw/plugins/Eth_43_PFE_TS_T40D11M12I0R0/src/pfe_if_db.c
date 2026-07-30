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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "linked_list.h"
#include "pfe_if_db.h"
#include "pfe_platform_cfg.h"
#include "isa.h"

typedef union
{
    uint8_t if_id;
    void *iface;
    char_t *name;
    pfe_ct_phy_if_id_t owner;
} crit_arg_t;   /*  Current criterion argument */

struct pfe_if_db_tag
{
    pfe_if_db_type_t type;
    uint32_t next_item;                  /*  Current entry to be returned. See ...get_first() and ...get_next() */
    pfe_if_db_get_criterion_t cur_crit; /*  Current criterion */
    crit_arg_t cur_crit_arg;    /*  Current criterion argument */
};

struct pfe_if_db_entry_tag
{
    pfe_ct_phy_if_id_t owner;

    union
    {
        pfe_log_if_t *log_if;
        pfe_phy_if_t *phy_if;
        void *iface;
    } info;
};

typedef struct
{
    uint32_t session_id;
    uint32_t seed;
    uint8_t ref_cnt;
    bool_t is_locked;
} if_db_context_t;

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_if_db_t xxx_if_db_instance[PFE_XXX_IF_DB_INSTANCES];
static pfe_isa_t pfe_if_db_log_ifs;
static pfe_if_db_entry_t pfe_if_db_phy_ifs[(uint8_t)PFE_PHY_IF_ID_MAX + 1U];
static pfe_isa_index_t pfe_if_db_log_ifs_index[PFE_CFG_MAX_LOG_IFS];
static pfe_if_db_entry_t pfe_if_db_log_ifs_pool[PFE_CFG_MAX_LOG_IFS];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static const pfe_isa_definition_t pfe_if_db_log_ifs_isa_def =
{
    .item_count = PFE_CFG_MAX_LOG_IFS,
    .item_size = (uint32_t)sizeof(pfe_if_db_entry_t),
    .flags = { .ordered = ISA_FLAG_STRICT_ORDER },
    .item_indexes = pfe_if_db_log_ifs_index,
    .items = pfe_if_db_log_ifs_pool,
    .clear_cb = (pfe_isa_clear_cb_t)NULL_PTR
};
#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief   Global intefrace DB lock. Module-local singleton.
 */
static if_db_context_t if_db_context;


#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static bool_t pfe_if_db_match_criterion(const pfe_if_db_t *db, pfe_if_db_get_criterion_t crit, const crit_arg_t *arg, const pfe_if_db_entry_t *entry);
static errno_t pfe_if_db_check_precondition(const if_db_context_t *pr_if_db_context, uint32_t session_id);
static pfe_if_db_entry_t *pfe_if_db_get_single_entry(const pfe_if_db_t *db, pfe_if_db_get_criterion_t crit, crit_arg_t argument, uint32_t *next_iter);

/**
 * @brief       Check preconditions before performing operation
 * @param[in]   pr_if_db_context
 * @retval      EOK Preconditions are fulfilled
 * @retval      PERM Preconditions are not fulfilled
 * @warning     context should be locked before call
 */
static errno_t pfe_if_db_check_precondition(const if_db_context_t *pr_if_db_context, uint32_t session_id)
{
    errno_t ret;

    if(FALSE == pr_if_db_context->is_locked)
    {
        ret = EPERM;
        NXP_LOG_DEBUG("DB access not permitted\n");
    }
    else if(session_id != pr_if_db_context->session_id)
    {
        NXP_LOG_DEBUG("Incorrect session ID\n");
        ret = EPERM;
    }
    else
    {
        ret = EOK;
    }
    return ret;
}

/**
 * @brief       Match entry with latest criterion provided via pfe_if_db_get_first()
 * @param[in]   db The interface DB instance
 * @param[in]   crit Criterion to search
 * @param[in]   arg Criterion arguments
 * @param[in]   entry The entry to be matched
 * @retval      TRUE Entry matches the criterion
 * @retval      FALSE Entry does not match the criterion
 */
static bool_t pfe_if_db_match_criterion(const pfe_if_db_t *db, pfe_if_db_get_criterion_t crit, const crit_arg_t *arg, const pfe_if_db_entry_t *entry)
{
    bool_t match;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == db) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        match = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (crit)
        {
            case IF_DB_CRIT_ALL:
            {
                match = TRUE;
                break;
            }

            case IF_DB_CRIT_BY_ID:
            {
                if (PFE_IF_DB_LOG == db->type)
                {
                    match = (arg->if_id == (uint8_t)pfe_log_if_get_id(entry->info.log_if));
                }
                else
                {
                    match = (arg->if_id == (uint8_t)pfe_phy_if_get_id(entry->info.phy_if));
                }

                break;
            }

            case IF_DB_CRIT_BY_INSTANCE:
            {
                match = (arg->iface == entry->info.iface);
                break;
            }

            case IF_DB_CRIT_BY_NAME:
            {
                if (PFE_IF_DB_LOG == db->type)
                {
                    match = (0 == autolibc_strcmp(arg->name, pfe_log_if_get_name(entry->info.log_if)));
                }
                else
                {
                    match = (0 == autolibc_strcmp(arg->name, pfe_phy_if_get_name(entry->info.phy_if)));
                }

                break;
            }

            case IF_DB_CRIT_BY_OWNER:
            {
                match = (arg->owner == entry->owner);
                break;
            }

            default:
            {
                NXP_LOG_ERROR("Unknown criterion\n");
                match = FALSE;
                break;
            }
        }
    }
    return match;
}

/**
 * @brief       Get any record from the DB matching given criterion without changing previous
 *              search criteria
 * @param[in]   db The interface DB instance
 * @param[in]   crit Get criterion
 * @param[in]   argument Pointer to criterion argument
 * @param[inout]  next_iter non NULL pointer to variable holding the iteration index
 * @return      entry The entry or NULL if not found
 */
static pfe_if_db_entry_t *pfe_if_db_get_single_entry(const pfe_if_db_t *db, pfe_if_db_get_criterion_t crit, crit_arg_t argument, uint32_t *next_iter)
{
    bool_t match = FALSE;
    pfe_if_db_entry_t *entry;
    uint32_t ii = *next_iter;

    if (PFE_IF_DB_PHY == db->type)
    {
        /*  Get first matching entry */
        for (; ii <= (uint32_t)PFE_PHY_IF_ID_MAX; ii++)
        {
            entry = &pfe_if_db_phy_ifs[ii];
            if (NULL_PTR != entry->info.iface)
            {
                if (TRUE == pfe_if_db_match_criterion(db, crit, &argument, entry))
                {
                    /* next item index where to start next lookup */
                    ii++;
                    match = TRUE;
                    break;
                }
            }
        }
    }
    else /* PFE_IF_DB_LOG */
    {
        /*  Get first matching entry */
        for (; ii < pfe_if_db_log_ifs.occupied_items_count; ii++)
        {
            /* Get data */
            entry = (pfe_if_db_entry_t *)isa_item(&pfe_if_db_log_ifs, ii);

            if (NULL_PTR != entry)
            {
                if (TRUE == pfe_if_db_match_criterion(db, crit, &argument, entry))
                {
                    /* next item index where to start next lookup */
                    ii++;
                    match = TRUE;
                    break;
                }
            }
        }
    }

    *next_iter = ii;

    if (FALSE == match)
    {
        /* No match found */
        entry = NULL_PTR;
    }

    return entry;
}

/**
 * @brief       Create DB
 * @param[in]   Database type: Logical or Physical interfaces
 * @return      The DB instance or NULL if failed
 */
pfe_if_db_t * pfe_if_db_create(pfe_if_db_type_t type)
{
    pfe_if_db_t *db;

    if (unlikely((type != PFE_IF_DB_PHY) && (type != PFE_IF_DB_LOG)))
    {
        NXP_LOG_ERROR("Unrecognized DB type\n");
        db = NULL;
    }
    else
    { 
        db = &xxx_if_db_instance[type];
        (void)autolibc_memset(db, 0, sizeof(pfe_if_db_t));
        db->next_item = 0U;
        db->type = type;
        oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_00);

        if(PFE_IF_DB_PHY == type)
        {
            (void)autolibc_memset(pfe_if_db_phy_ifs, 0, sizeof(pfe_if_db_phy_ifs));
        }
        else
        {
            /* PFE_IF_DB_LOG */
            isa_init(&pfe_if_db_log_ifs, &pfe_if_db_log_ifs_isa_def);
            (void)autolibc_memset(pfe_if_db_log_ifs_pool, 0, sizeof(pfe_if_db_log_ifs_pool));
        }

        /* Create global DB lock */
        if (0U == if_db_context.ref_cnt)
        {
            /* Initialize data to safe values */
            if_db_context.is_locked = FALSE;
            if_db_context.session_id = 0U;

            /* Initialize seed to some value */
            if_db_context.seed = 123U;
        }

        /* Increment reference counter */
        ++if_db_context.ref_cnt;

        oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_00);
    }
    return db;
}

/**
 * @brief       Destroy DB
 * @param[in]   db The DB instance
 */
void pfe_if_db_destroy(const pfe_if_db_t *db)
{
    oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_01);

    if(PFE_IF_DB_PHY == db->type)
    {
        (void)autolibc_memset(pfe_if_db_phy_ifs, 0, sizeof(pfe_if_db_phy_ifs));
    }
    else
    {
        /* PFE_IF_DB_LOG */
        isa_init(&pfe_if_db_log_ifs, &pfe_if_db_log_ifs_isa_def);
    }

    /* Decrement reference counter */
    if(0U < if_db_context.ref_cnt)
    {
        --if_db_context.ref_cnt;
    }

    oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_01);

    /* Destroy global DB lock */
    if(0U == if_db_context.ref_cnt)
    {
        if_db_context.is_locked = TRUE;
    }
}

/**
 * @brief       Get physical interface instance from database entry
 * @param[in]   entry The entry
 * @return      Physical interface instance
 */
__attribute__((pure)) pfe_phy_if_t *pfe_if_db_entry_get_phy_if(const pfe_if_db_entry_t *entry)
{
    pfe_phy_if_t *phy_if_entry;
    if (NULL != entry)
    {
        phy_if_entry = entry->info.phy_if;
    }
    else
    {
        phy_if_entry = NULL;
    }
    return phy_if_entry;
}

/**
 * @brief       Get logical interface instance from database entry
 * @param[in]   entry The entry
 * @return      Logical interface instance
 */
__attribute__((pure)) pfe_log_if_t *pfe_if_db_entry_get_log_if(const pfe_if_db_entry_t *entry)
{
    pfe_log_if_t *log_if_entry;
    if (NULL != entry)
    {
        log_if_entry = entry->info.log_if;
    }
    else
    {
        log_if_entry = NULL;
    }
    return log_if_entry;
}

/**
 * @brief       Add interface instance to DB
 * @param[in]   db The interface DB instance
 * @param[in]   session_id ID of active session
 * @param[in]   iface The interface instance
 * @param[in]   owner Owner of the entry
 * @retval      EOK Success
 * @retval      ENOMEM Memory allocation failed
 * @retval      EPERM Attempt to insert already existing entry/Incorrect session ID
 */
errno_t pfe_if_db_add(pfe_if_db_t *db, uint32_t session_id, void *iface, pfe_ct_phy_if_id_t owner)
{
    pfe_if_db_entry_t  *new_entry = NULL;
    errno_t            ret;
    pfe_ct_phy_if_id_t id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == iface)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_IF_DB_PHY == db->type)
        {
            id = pfe_phy_if_get_id((pfe_phy_if_t *)iface);

            /* check duplicates */
            if (NULL_PTR == pfe_if_db_phy_ifs[id].info.iface)
            {
                new_entry = &pfe_if_db_phy_ifs[id];
                ret = EOK;
            }
            else
            {
                /* don't allow duplicates */
                ret = EPERM;
            }
        }
        else
        {
            /* PFE_IF_DB_LOG */
            ret = pfe_if_db_get_first(db, session_id, IF_DB_CRIT_BY_INSTANCE, iface, &new_entry);

            /* Check condition if operation on DB is allowed */
            if (EOK != pfe_if_db_check_precondition(&if_db_context, session_id))
            {
                ret = EPERM;
            }
            else
            {
                if ((NULL_PTR == new_entry) && (EOK == ret))
                {
                    oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_02);
                    new_entry = (pfe_if_db_entry_t *)isa_reserve(&pfe_if_db_log_ifs);
                    if (NULL_PTR == new_entry)
                    {
                        ret = ENOMEM;
                    }
                    else
                    {
                        (void)autolibc_memset(new_entry, 0, sizeof(pfe_if_db_entry_t));
                    }
                    oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_02);
                }
                else
                {
                    /*  Don't allow duplicates */
                    ret = EPERM;
                }
            }
        }

        if (NULL_PTR != new_entry)
        {
            /*  Store values */
            new_entry->info.iface = iface;
            new_entry->owner = owner;
        }
    }
    return ret;
}

/**
 * @brief       Remove entry from DB
 * @param[in]   db The interface DB instance
 * @param[in]   session_id ID of active session
 * @param[in]   entry Entry to be removed. If the call is successful the entry
 *                    becomes invalid and shall not be accessed.
 * @return      EOK if success, error code otherwise
 * @retval      EPERM Incorrect session ID or DB not locked
 */
errno_t pfe_if_db_remove(pfe_if_db_t *db, uint32_t session_id, pfe_if_db_entry_t *entry)
{
    errno_t ret;
    int32_t item_index;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == db) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Check condition if operation on DB is allowed */
        if (EOK != pfe_if_db_check_precondition(&if_db_context, session_id))
        {
            ret = EPERM;
        }
        else
        {
            if (PFE_IF_DB_PHY == db->type)
            {
                if ((pfe_if_db_phy_ifs <= entry) && (entry < &pfe_if_db_phy_ifs[(uint8_t)PFE_PHY_IF_ID_MAX + 1U]))
                {
                    /* invalidate inteface to mark interface removed state */
                    entry->info.iface = NULL_PTR;
                    ret = EOK;
                }
                else
                {
                    ret = ENOENT;
                }
            }
            else
            {
                /* PFE_IF_DB_LOG */
                oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_03);
                item_index = isa_release(&pfe_if_db_log_ifs, entry);
                if (ISA_ITEM_NOT_FOUND != item_index)
                {
                    if ((uint32_t)item_index < db->next_item)
                    {
                        /*  If removed item had lower 'item_index' than 'next_item' then we need decrease
                            'next_item' value. Adjust next_item value so we can call remove() between
                            get_first() and get_next() calls.
                        */
                        db->next_item--;
                    }
                    ret = EOK;
                }
                else
                {
                    ret = ENOENT;
                }
                oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_03);
            }
        }
    }
    return ret;
}

/**
 * @brief       Get first record from the DB matching given criterion
 * @details     Intended to be used with pfe_if_db_get_next
 * @param[in]   db The interface DB instance
 * @param[in]   session_id ID of active session
 * @param[in]   crit Get criterion
 * @param[in]   arg Pointer to criterion argument
 * @param[out]  entry The entry or NULL if not found
 * @return      EOK entry returned is valid
 * @return      EPERM db was locked by someone else, entry returned is not valid
 * @warning     The returned entry must not be accessed after pfe_if_db_remove(entry)
 *              or pfe_if_db_drop_all() has been called.
 */
errno_t pfe_if_db_get_first(pfe_if_db_t *db, uint32_t session_id, pfe_if_db_get_criterion_t crit, void *arg, pfe_if_db_entry_t **db_entry)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == db_entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Check condition if operation on DB is allowed */
        if (EOK != pfe_if_db_check_precondition(&if_db_context, session_id))
        {
            ret = EPERM;
        }
        else
        {
            /*  Remember criterion and argument for possible subsequent pfe_log_if_db_get_next() calls */
            db->cur_crit = crit;
            switch (db->cur_crit)
            {
                case IF_DB_CRIT_ALL:
                {
                    break;
                }

                case IF_DB_CRIT_BY_ID:
                {
                    db->cur_crit_arg.if_id = (uint8_t)((addr_t)arg & 0xffU);
                    break;
                }

                case IF_DB_CRIT_BY_INSTANCE:
                {
#if defined(PFE_CFG_NULL_ARG_CHECK)
                    if (unlikely(NULL == arg))
                    {
                        NXP_LOG_ERROR("NULL argument received\n");
                        *db_entry = NULL_PTR;
                        ret = EINVAL;
                    }
                    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
                    {
                        db->cur_crit_arg.iface = arg;
                    }
                    break;
                }

                case IF_DB_CRIT_BY_NAME:
                {
#if defined(PFE_CFG_NULL_ARG_CHECK)
                    if (unlikely(NULL == arg))
                    {
                        NXP_LOG_ERROR("NULL argument received\n");
                        *db_entry = NULL_PTR;
                        ret = EINVAL;
                    }
                    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
                    {
                        db->cur_crit_arg.name = (char_t *)arg;
                    }
                    break;
                }

                case IF_DB_CRIT_BY_OWNER:
                {
                    db->cur_crit_arg.owner = (pfe_ct_phy_if_id_t)((addr_t)arg & 0xffU);
                    break;
                }

                default:
                {
                    NXP_LOG_ERROR("Unknown criterion\n");
                    ret = EPERM;
                    break;
                }
            }

            if (ret == EOK)
            {
                db->next_item = 0U;
                *db_entry = pfe_if_db_get_single_entry(db, db->cur_crit, db->cur_crit_arg, &db->next_item);
            }
        }
    }
    return ret;
}

/**
 * @brief       Get first record from the DB matching given criterion without changing previous
 *              search criteria
 * @details     Intended to be used for nested DB search where only a single match is expected (i.g. by
 *              unique ID). The function does not change saved criterion from the pfe_if_db_get_first()
 *              call thus the pfe_if_db_get_next() will be able to continue the search initiated by
 *              the pfe_if_db_get_first() call.
 * @param[in]   db The interface DB instance
 * @param[in]   session_id ID of active session
 * @param[in]   crit Get criterion
 * @param[in]   arg Pointer to criterion argument
 * @param[out]  entry The entry or NULL if not found
 * @return      EOK entry returned is valid
 * @return      EPERM db was locked by someone else, entry returned is not valid
 * @warning     The returned entry must not be accessed after pfe_if_db_remove(entry)
 *              or pfe_if_db_drop_all() has been called.
 */
errno_t pfe_if_db_get_single(const pfe_if_db_t *db, uint32_t session_id, pfe_if_db_get_criterion_t crit, void *arg, pfe_if_db_entry_t **db_entry)
{
    crit_arg_t argument = {0};
    errno_t    ret = EOK;
    uint32_t   iter;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == db_entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Convert argument to database known format */
        switch (crit)
        {
            case IF_DB_CRIT_ALL:
            {
                break;
            }

            case IF_DB_CRIT_BY_ID:
            {
                argument.if_id = (uint8_t)((addr_t)arg & 0xffU);
                break;
            }

            case IF_DB_CRIT_BY_INSTANCE:
            {
#if defined(PFE_CFG_NULL_ARG_CHECK)
                if (unlikely(NULL == arg))
                {
                    NXP_LOG_ERROR("NULL argument received\n");
                    *db_entry = NULL_PTR;
                    ret = EINVAL;
                }
                else
#endif /* PFE_CFG_NULL_ARG_CHECK */
                {
                    argument.iface = arg;
                }
                break;
            }

            case IF_DB_CRIT_BY_NAME:
            {
#if defined(PFE_CFG_NULL_ARG_CHECK)
                if (unlikely(NULL == arg))
                {
                    NXP_LOG_ERROR("NULL argument received\n");
                    *db_entry = NULL_PTR;
                    ret = EINVAL;
                }
                else
#endif /* PFE_CFG_NULL_ARG_CHECK */
                {
                    argument.name = (char_t *)arg;
                }
                break;
            }

            case IF_DB_CRIT_BY_OWNER:
            {
                argument.owner = (pfe_ct_phy_if_id_t)((addr_t)arg & 0xffU);
                break;
            }

            default:
            {
                NXP_LOG_ERROR("Unknown criterion\n");
                ret = EPERM;
                break;
            }
        }
        if (ret == EOK)
        {
            /* Check condition if operation on DB is allowed */
            if (EOK != pfe_if_db_check_precondition(&if_db_context, session_id))
            {
                ret = EPERM;
            }
            if (ret != EPERM)
            {
                iter = 0U;
                *db_entry = pfe_if_db_get_single_entry(db, crit, argument, &iter);
            }
        }
    }
    return ret;
}

/**
 * @brief       Get next record from the DB
 * @details     Intended to be used with pfe_if_db_get_first.
 * @param[in]   db The interface DB instance
 * @param[in]   session_id ID of active session
 * @param[out]  entry The entry or NULL if not found
 * @return      EOK entry returned is valid
 * @return      EPERM db was locked by someone else, entry returned is not valid
 * @warning     The returned entry must not be accessed after pfe_if_db_remove(entry)
 *              or pfe_if_db_drop_all() has been called.
 */
errno_t pfe_if_db_get_next(pfe_if_db_t *db, uint32_t session_id, pfe_if_db_entry_t **db_entry)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == db) || (NULL_PTR == db_entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Check condition if operation on DB is allowed */
        if (EOK != pfe_if_db_check_precondition(&if_db_context, session_id))
        {
            ret = EPERM;
        }
        else
        {
            *db_entry = pfe_if_db_get_single_entry(db, db->cur_crit, db->cur_crit_arg, &db->next_item);
            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Remove all entries
 * @param[in]   db The route DB instance
 * @param[in]   session_id ID of active session
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_log_if_db_drop_all(const pfe_if_db_t *db, uint32_t session_id)
{
    errno_t ret;
    int32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Check condition if operation on DB is allowed */
        if (EOK != pfe_if_db_check_precondition(&if_db_context, session_id))
        {
            ret = EPERM;
        }
        else
        {
            if (PFE_IF_DB_PHY == db->type)
            {
                for (ii = (int32_t)PFE_PHY_IF_ID_MAX; ii >= 0; ii--)
                {
                    pfe_if_db_phy_ifs[ii].info.iface = NULL_PTR;
                }
            }
            else
            {
                oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_04);
                for (ii = ((int32_t)(pfe_if_db_log_ifs.occupied_items_count) - 1); ii >= 0; ii--)
                {
                    (void)isa_release_subscript(&pfe_if_db_log_ifs, (uint32_t)ii);
                }
                oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_04);
            }
            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Lock the DB with session ID
 * @param[out]  session_id ID of locked session
 * @return      EOK if success, error if lock is already locked
 */
errno_t pfe_if_db_lock(uint32_t *session_id)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == session_id))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Lock global if DB mutex */
        oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_05);

        if (FALSE == if_db_context.is_locked)
        {
            /* Increment seed id */
            ++if_db_context.seed;

            /* Store session ID and reserve 0 - 15 for named sessions */
            if_db_context.session_id = if_db_context.seed << 4U;

            /* Pass session id to caller*/
            *session_id = if_db_context.session_id;
            if_db_context.is_locked = TRUE;

            ret = EOK;
        }
        else
        {
            ret = ENOLCK;
        }

        /* Unlock global if DB mutex */
        oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_05);
    }
    return ret;
}

/**
 * @brief       Lock the DB with owner ID
 * @param[in]   owner_id ID of owner in range 0 - 15
 * @return      EOK if success, error if lock is already locked or id is not in range
 */
errno_t pfe_if_db_lock_owned(uint32_t owner_id)
{
    errno_t ret = ENOLCK;

    oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_06);
    if((FALSE == if_db_context.is_locked) && (16U > owner_id))
    {
        /* Session ID is in ok range store it*/
        if_db_context.session_id = owner_id;
        if_db_context.is_locked = TRUE;
        ret = EOK;
    }
    oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_06);

    return ret;
}

/**
 * @brief       Unlock the DB with owner ID/session ID
 * @param[in]   owner_id ID of owner or session
 * @return      EOK if success, error if lock is already locked or id is not in range
 */
errno_t pfe_if_db_unlock(uint32_t session_id)
{
    errno_t ret = ENOLCK;

    oal_mutex_lock(PFE_IF_DB_CONTEXT_MUTEX_07);
    if((TRUE == if_db_context.is_locked) && (session_id == if_db_context.session_id))
    {
        /* Discard key and set locked to FALSE*/
        if_db_context.session_id = (~if_db_context.session_id) << 4U;

        /* Set is locked to FALSE */
        if_db_context.is_locked = FALSE;
        ret = EOK;
    }
    oal_mutex_unlock(PFE_IF_DB_CONTEXT_MUTEX_07);

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
