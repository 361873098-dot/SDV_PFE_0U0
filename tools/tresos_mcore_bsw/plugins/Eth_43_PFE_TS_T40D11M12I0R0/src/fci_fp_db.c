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
 *  Copyright 2019-2023 NXP
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
#include "pfe_ct.h"

#include "fci_fp_db.h"
#include "pfe_fp.h"
#include "fci.h"
#include "Eth_43_PFE_Cfg.h"
#include "isa.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE

/* rule names should not exceed this length including terminating 0 */
#define FCI_FP_RULE_NAME_LENGTH 16

/**
* @brief Flexible parser rule representation
*/
typedef struct
{
    /* Maintenance */
    char_t name[FCI_FP_RULE_NAME_LENGTH];    /* Unique ID */
    pfe_isa_index_t chained_prev_rule_idx;  /* Previous rule linked to the table */
    pfe_isa_index_t chained_next_rule_idx;  /* Next rule linked to the table */
    uint8_t position;        /* Position in the table */
    fci_fp_table_t *table;   /* Link to the table the rule belongs */
    /* Data */
    char_t next_rule[FCI_FP_RULE_NAME_LENGTH]; /* Name of the next linked rule */
    uint32_t data;           /* Data to match */
    uint32_t mask;           /* Mask to match */
    uint16_t offset;         /* Data offset to get data */
    pfe_ct_fp_flags_t flags; /* Flags configuring the rule */
} fci_fp_rule_t;

/**
* @brief Criterion for rule database search
*/
typedef enum
{
    FP_RULE_CRIT_ALL,
    FP_RULE_CRIT_NAME,
} fci_fp_rule_criterion_t;

/**
* @brief Argument (requested value) for rule database
*/
typedef union
{
    char_t name[FCI_FP_RULE_NAME_LENGTH];
} fci_fp_rule_criterion_arg_t;

/**
* @brief Database of flexible parser rules
*/
typedef struct
{
    /* Rules database */
    pfe_isa_t rules;
    pfe_isa_index_t rules_pool_index[PFE_CFG_FCI_FP_MAX_RULES];
    fci_fp_rule_t rules_pool[PFE_CFG_FCI_FP_MAX_RULES];
    /* Searching */
    fci_fp_rule_criterion_t cur_crit;
    fci_fp_rule_criterion_arg_t cur_crit_arg;
    uint32_t next_item;
} fci_fp_rule_db_t;

/**
* @brief Flexible parser table representation
*/
struct fci_fp_table_tag
{
    char_t name[FCI_FP_TABLE_NAME_LENGTH]; /* Table identifier */
    uint16_t rule_count;       /* Number of rules in the table */
    uint32_t dmem_addr;        /* Address where the table was written into DMEM */
    pfe_class_t *class;
    pfe_isa_index_t rules_chain_1st_idx;  /* Chained list of rules in the table, valid only if rule_count > 0 */
    /* Searching */
    fci_fp_rule_criterion_t cur_crit;
    fci_fp_rule_criterion_arg_t cur_crit_arg;
    pfe_isa_index_t iter_next_rule_idx;    /* next rule to examine in get first / get next */
    uint16_t iter_count;              /* rules left to examine in get first / get next */
};

/**
* @brief Database of flexible parser tables
*/
typedef struct
{
    /* Tables database */
    pfe_isa_t tables;
    pfe_isa_index_t tables_pool_index[FCI_MAX_TABLES];
    fci_fp_table_t tables_pool[FCI_MAX_TABLES];
    /* Searching */
    fci_fp_table_criterion_t cur_crit;
    fci_fp_table_criterion_arg_t cur_crit_arg;
    uint32_t next_item;
} fci_fp_table_db_t;

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

static fci_fp_rule_db_t fci_fp_rule_db;
static fci_fp_table_db_t fci_fp_table_db;

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/* FCI flexible parser tables storage ISA properties definition */
static const pfe_isa_definition_t fci_fp_table_db_tables_isa_def =
{
    .item_count = FCI_MAX_TABLES,
    .item_size = (uint32_t)sizeof(fci_fp_table_t),
    .flags = { .ordered = ISA_FLAG_ANY_ORDER },
    .item_indexes = fci_fp_table_db.tables_pool_index,
    .items = fci_fp_table_db.tables_pool,
    .clear_cb = (pfe_isa_clear_cb_t)NULL_PTR
};
/* FCI flexible parser rules storage ISA properties definition */
static const pfe_isa_definition_t fci_fp_rule_db_rules_isa_def =
{
    .item_count = PFE_CFG_FCI_FP_MAX_RULES,
    .item_size = (uint8_t)sizeof(fci_fp_rule_t),
    .flags = { .ordered = ISA_FLAG_ANY_ORDER },
    .item_indexes = fci_fp_rule_db.rules_pool_index,
    .items = fci_fp_rule_db.rules_pool,
    .clear_cb = (pfe_isa_clear_cb_t)NULL_PTR
};
#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static bool_t fci_fp_match_rule_by_criterion(fci_fp_rule_criterion_t crit, const fci_fp_rule_criterion_arg_t *arg, const fci_fp_rule_t *rule);
static fci_fp_rule_t *fci_fp_rule_get_first_common(fci_fp_rule_db_t *db, fci_fp_rule_criterion_t crit, void *arg);
static fci_fp_rule_t *fci_fp_rule_get_first_table(fci_fp_table_t *fp_table, fci_fp_rule_criterion_t crit, void *arg);
static fci_fp_rule_t *fci_fp_rule_get_next_common(fci_fp_rule_db_t *db);
static fci_fp_rule_t *fci_fp_rule_get_next_table(fci_fp_table_t *fp_table);
static bool_t fci_fp_match_table_by_criterion(fci_fp_table_criterion_t crit, const fci_fp_table_criterion_arg_t *arg, const fci_fp_table_t *fp_table);
static fci_fp_table_t *fci_fp_table_get_first(fci_fp_table_db_t *db, fci_fp_table_criterion_t crit, void *arg);

#if defined(PFE_CFG_TEXT_STATS)
static uint32_t fci_fp_print_table(const fci_fp_table_t *fp_table, char_t *buf, uint32_t buf_len, uint8_t verb_level);
static errno_t fci_fp_get_rule_pos_in_table(const fci_fp_table_t *fp_table, fci_fp_rule_t *rule, uint8_t *pos);
static uint32_t fci_fp_print_rule(fci_fp_rule_t *rule, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

static fci_fp_table_t *fci_fp_table_get_next(fci_fp_table_db_t *db);
static void fci_fp_unlink_rule_from_chain(fci_fp_rule_t *fp_rule);

/**
 * @brief Get first rule for the FP table
 * @param[in] fp_table pointer to FP table
 * @return Pointer to first rule
 */
static inline fci_fp_rule_t *fci_fp_table_1st_rule(const fci_fp_table_t *fp_table)
{
    return &fci_fp_rule_db.rules_pool[fp_table->rules_chain_1st_idx];
}

/**
 * @brief Get previous sibling rule
 * @param[in] fp_rule pointer to FP rule
 * @return Pointer to previous rule
 */
static inline fci_fp_rule_t *fci_fp_rule_prev_sibling(const fci_fp_rule_t *fp_rule)
{
    return &fci_fp_rule_db.rules_pool[fp_rule->chained_prev_rule_idx];
}

/**
 * @brief Get next sibling rule
 * @param[in] fp_rule pointer to FP rule
 * @return Pointer to next rule
 */
static inline fci_fp_rule_t *fci_fp_rule_next_sibling(const fci_fp_rule_t *fp_rule)
{
    return &fci_fp_rule_db.rules_pool[fp_rule->chained_next_rule_idx];
}

/**
 * @brief Get pool index to the rule
 * @param[in] fp_rule pointer to rule in the rule pool
 * @return Index of the rule
 */
static inline pfe_isa_index_t fci_fp_get_rule_index(const fci_fp_rule_t *fp_rule)
{
    return (pfe_isa_index_t)(fp_rule - fci_fp_rule_db.rules_pool);
}

/**
 * @brief Unlink the rule from the chain
 * @param[in] fp_rule pointer to rule in the rule pool
 */
static void fci_fp_unlink_rule_from_chain(fci_fp_rule_t *fp_rule)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == fp_rule))
    {
        NXP_LOG_ERROR("fp_rule isn't expected to be NULL here !\n");
    }
    else if(unlikely(NULL_PTR == fp_rule->table))
    {
        NXP_LOG_ERROR("fp_rule->table isn't expected to be NULL here !\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_isa_index_t index = fci_fp_get_rule_index(fp_rule);
        /* next sibling rule */
        fci_fp_rule_t *fp_rule_next = fci_fp_rule_next_sibling(fp_rule);
        /* previous sibling rule */
        fci_fp_rule_t *fp_rule_prev = fci_fp_rule_prev_sibling(fp_rule);

        if(index == fp_rule->table->rules_chain_1st_idx)
        {
            /* this rule is the 1st in the table */
            fp_rule->table->rules_chain_1st_idx = fci_fp_get_rule_index(fp_rule_next);
            /* make next rule previous chain unlinked */
            fp_rule_next->chained_prev_rule_idx = fci_fp_get_rule_index(fp_rule_next);
        }
        else
        {
            if(fp_rule != fp_rule_prev)
            {
                /* the rule has previous sibling */
                if(fp_rule != fp_rule_next)
                {
                    /* the rule has next sibling */
                    fp_rule_prev->chained_next_rule_idx = fci_fp_get_rule_index(fp_rule_next);
                }
                else
                {
                    /* the rule hasn't next sibling */
                    fp_rule_prev->chained_next_rule_idx = fci_fp_get_rule_index(fp_rule_prev);
                }
            }
            if(fp_rule != fp_rule_next)
            {
                /* the rule has next sibling */
                if(fp_rule != fp_rule_prev)
                {
                    /* the rule has previous sibling */
                    fp_rule_next->chained_prev_rule_idx = fci_fp_get_rule_index(fp_rule_prev);
                }
                else
                {
                    /* the rule hasn't previous sibling */
                    fp_rule_next->chained_prev_rule_idx = fci_fp_get_rule_index(fp_rule_next);
                }
            }
        }

        /* chained values will point to ourself after unlinking */
        fp_rule->chained_next_rule_idx = index;
        fp_rule->chained_prev_rule_idx = index;

        /* decrease number rules for the table */
        fp_rule->table->rule_count--;

        /* this rule doesn't relate to any table anymore */
        fp_rule->table = NULL_PTR;
    }
}

/**
 * @brief        Match rule using given criterion
 * @param[in]    crit Selects criterion
 * @param[in]    arg Criterion argument
 * @param[in]    rule The rule to be matched
 * @retval       TRUE Rule matches the criterion
 * @retval       FALSE Rule does not match the criterion
 */
static bool_t fci_fp_match_rule_by_criterion(fci_fp_rule_criterion_t crit, const fci_fp_rule_criterion_arg_t *arg, const fci_fp_rule_t *rule)
{
    bool_t match;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == rule) || (NULL == arg)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        match = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (crit)
        {
            case FP_RULE_CRIT_ALL:
            {
                match = TRUE;
                break;
            }
            case FP_RULE_CRIT_NAME:
            {
                if(0 == autolibc_strcmp(arg->name, rule->name))
                {
                    match = TRUE;
                }
                else
                {
                    match = FALSE;
                }
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
 * @brief        Get first rule from the database matching given criterion
 * @details      Intended to be used with fci_fp_rule_get_next
 * @param[in]    db The rules database instance
 * @param[in]    crit Get criterion
 * @param[in]    arg Pointer to criterion argument. Every value shall to be in HOST endian format. Strings are copied into internal memory.
 * @return       The matching rule or NULL if not found
 */
static fci_fp_rule_t *fci_fp_rule_get_first_common(fci_fp_rule_db_t *db, fci_fp_rule_criterion_t crit, void *arg)
{
    fci_fp_rule_t *rule = NULL_PTR;
    bool_t cur_crit_remember_success = TRUE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else if (unlikely((FP_RULE_CRIT_ALL != crit) && (NULL_PTR == arg)))
    {
        /*  All criterions except FP_RULE_CRIT_ALL require non-NULL argument */
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*    Remember criterion and argument for possible subsequent fci_fp_rule_get_next() calls */
        db->cur_crit = crit;
        switch(db->cur_crit)
        {
            case FP_RULE_CRIT_ALL:
                break;

            case FP_RULE_CRIT_NAME:
            {
                (void)autolibc_strncpy(db->cur_crit_arg.name, (char_t *)arg, sizeof(db->cur_crit_arg.name));
                if(db->cur_crit_arg.name[sizeof(db->cur_crit_arg.name) - 1U] != '\0')
                {
                    /* could not copy the whole string into destination ! */
                    cur_crit_remember_success = FALSE;
                }
                break;
            }
            default:
            {
                NXP_LOG_ERROR("Unknown criterion\n");
                cur_crit_remember_success = FALSE;
                break;
            }
        }
        if (TRUE == cur_crit_remember_success)
        {
            db->next_item = 0U;
            rule = fci_fp_rule_get_next_common(db);
        }
    }

    return rule;
}

/**
 * @brief        Get first rule from the table matching given criterion
 * @details      Intended to be used with fci_fp_rule_get_next
 * @param[in]    fp_table The FP table instance
 * @param[in]    crit Get criterion
 * @param[in]    arg Pointer to criterion argument. Every value shall to be in HOST endian format. Strings are copied into internal memory.
 * @return       The matching rule or NULL if not found
 */
static fci_fp_rule_t *fci_fp_rule_get_first_table(fci_fp_table_t *fp_table, fci_fp_rule_criterion_t crit, void *arg)
{
    fci_fp_rule_t *rule = NULL_PTR;
    bool_t cur_crit_remember_success = TRUE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == fp_table))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else if (unlikely((FP_RULE_CRIT_ALL != crit) && (NULL_PTR == arg)))
    {
        /*  All criterions except FP_RULE_CRIT_ALL require non-NULL argument */
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*    Remember criterion and argument for possible subsequent fci_fp_rule_get_next() calls */
        fp_table->cur_crit = crit;
        switch(fp_table->cur_crit)
        {
            case FP_RULE_CRIT_ALL:
                break;

            case FP_RULE_CRIT_NAME:
            {
                (void)autolibc_strncpy(fp_table->cur_crit_arg.name, (char_t *)arg, sizeof(fp_table->cur_crit_arg.name));
                if(fp_table->cur_crit_arg.name[sizeof(fp_table->cur_crit_arg.name) - 1U] != '\0')
                {
                    /* could not copy the whole string into destination ! */
                    cur_crit_remember_success = FALSE;
                }
                break;
            }
            default:
            {
                NXP_LOG_ERROR("Unknown criterion\n");
                cur_crit_remember_success = FALSE;
                break;
            }
        }
        if (TRUE == cur_crit_remember_success)
        {
            fp_table->iter_count = 0U;
            fp_table->iter_next_rule_idx = fp_table->rules_chain_1st_idx;
            rule = fci_fp_rule_get_next_table(fp_table);
        }

    }

    return rule;
}

/**
 * @brief        Get next rule from the database
 * @details      Intended to be used with fci_fp_rule_get_first.
 * @param[in]    db The rules database instance
 * @return       The rule matching criterion set by fci_fp_rule_get_first or NULL if not found
 */
static fci_fp_rule_t *fci_fp_rule_get_next_common(fci_fp_rule_db_t *db)
{
    fci_fp_rule_t *rule = NULL_PTR;
    bool_t match = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* rules global database */
        while (db->next_item < fci_fp_rule_db.rules.occupied_items_count)
        {
            rule = (fci_fp_rule_t *)isa_item(&fci_fp_rule_db.rules, db->next_item);

            /* Remember current item to know where to start later */
            db->next_item++;

            if (NULL_PTR != rule)
            {
                match = fci_fp_match_rule_by_criterion(db->cur_crit, &db->cur_crit_arg, rule);
                if (TRUE == match)
                {
                    break;
                }
            }
        }

        if (FALSE == match)
        {
            rule = NULL_PTR;
        }
    }

    return rule;
}

/**
 * @brief        Get next rule from the table
 * @details      Intended to be used with fci_fp_rule_get_first.
 * @param[in]    fp_table The table instance
 * @return       The rule matching criterion set by fci_fp_rule_get_first or NULL if not found
 */
static fci_fp_rule_t *fci_fp_rule_get_next_table(fci_fp_table_t *fp_table)
{
    fci_fp_rule_t *rule = NULL_PTR;
    bool_t match = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == fp_table))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        while (fp_table->iter_count < fp_table->rule_count)
        {
            rule = &fci_fp_rule_db.rules_pool[fp_table->iter_next_rule_idx];
            fp_table->iter_next_rule_idx = rule->chained_next_rule_idx;
            /* consume this rule */
            fp_table->iter_count++;

            match = fci_fp_match_rule_by_criterion(fp_table->cur_crit, &fp_table->cur_crit_arg, rule);
            if (TRUE == match)
            {
                break;
            }
        }

        if (FALSE == match)
        {
            rule = NULL_PTR;
        }
    }

    return rule;
}

/**
 * @brief        Match table using given criterion
 * @param[in]    crit Selects criterion
 * @param[in]    arg Criterion argument
 * @param[in]    fp_table The table to be matched
 * @retval       TRUE Table matches the criterion
 * @retval       FALSE Table does not match the criterion
 */
static bool_t fci_fp_match_table_by_criterion(fci_fp_table_criterion_t crit, const fci_fp_table_criterion_arg_t *arg, const fci_fp_table_t *fp_table)
{
    bool_t match;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == fp_table) || (NULL == arg)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        match = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (crit)
        {
            case FP_TABLE_CRIT_ALL:
            {
                match = TRUE;
                break;
            }
            case FP_TABLE_CRIT_NAME:
            {
                if(0 == autolibc_strcmp(arg->name, fp_table->name))
                {
                    match = TRUE;
                }
                else
                {
                    match = FALSE;
                }
                break;
            }
            case FP_TABLE_CRIT_ADDRESS:
            {
                if(arg->address == fp_table->dmem_addr)
                {
                    match = TRUE;
                }
                else
                {
                    match = FALSE;
                }
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
 * @brief        Get first table from the database matching given criterion
 * @details      Intended to be used with fci_fp_table_get_next
 * @param[in]    db The tables database instance
 * @param[in]    crit Get criterion
 * @param[in]    arg Pointer to criterion argument. Every value shall to be in HOST endian format. Strings are copied into internal memory.
 * @return       The matching table or NULL if not found
 */
static fci_fp_table_t *fci_fp_table_get_first(fci_fp_table_db_t *db, fci_fp_table_criterion_t crit, void *arg)
{
    fci_fp_table_t *fp_table = NULL_PTR;
    bool_t cur_crit_remember_success = TRUE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else if (unlikely((FP_TABLE_CRIT_ALL != crit) && (NULL_PTR == arg)))
    {
        /*  All criterions except FP_TABLE_CRIT_ALL require non-NULL argument */
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Invalidate memory used by previous search (if any) */
        if(FP_TABLE_CRIT_NAME == db->cur_crit)
        {
            db->cur_crit_arg.name[0U] = '\0';
        }
        /*    Remember criterion and argument for possible subsequent fci_fp_table_get_next() calls */
        db->cur_crit = crit;
        switch(crit)
        {
            case FP_TABLE_CRIT_ALL:
            {
                break;
            }
            case FP_TABLE_CRIT_NAME:
            {
                /* Copy the string */
                (void)autolibc_strncpy(db->cur_crit_arg.name, (char_t *)arg, sizeof(db->cur_crit_arg.name));
                if(db->cur_crit_arg.name[sizeof(db->cur_crit_arg.name) - 1U] != '\0')
                {
                    /* count not copy the whole string into destination */
                    cur_crit_remember_success = FALSE;
                }
                break;
            }
            case FP_TABLE_CRIT_ADDRESS:
            {
                db->cur_crit_arg.address = *(uint32_t *)arg;
                break;
            }
            default:
            {
                NXP_LOG_ERROR("Unknown criterion\n");
                cur_crit_remember_success = FALSE;
                break;
            }
        }

        if (TRUE == cur_crit_remember_success)
        {
            /* Get first matching table */
            db->next_item = 0U;
            fp_table = fci_fp_table_get_next(db);
        }
    }

    return fp_table;
}


/**
 * @brief        Get next table from the database
 * @details      Intended to be used with fci_fp_rule_get_first.
 * @param[in]    db The rules database instance
 * @return       The table matching criterion set by fci_fp_rule_get_first or NULL if not found
 */
static fci_fp_table_t *fci_fp_table_get_next(fci_fp_table_db_t *db)
{
    fci_fp_table_t *fp_table = NULL_PTR;
    bool_t match;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == db))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        match = FALSE;

        while (db->next_item < db->tables.occupied_items_count)
        {
            /*  Get data */
            fp_table = (fci_fp_table_t *)isa_item(&db->tables, db->next_item);

            /*  Remember current item to know where to start later */
            db->next_item++;

            if (NULL_PTR != fp_table)
            {
                if (TRUE == fci_fp_match_table_by_criterion(db->cur_crit, &db->cur_crit_arg, fp_table))
                {
                    match = TRUE;
                    break;
                }
            }
        }

        if (TRUE != match)
        {
            fp_table = NULL_PTR;
        }
    }

    return fp_table;
}

/**
* @brief Returns the position of the rule within a table
* @param[in] fp_table Table to determine postion of the rule within
* @param[in] rule Rule which position within the table shall be determined
* @param[out] pos Determined rule position
* @return EOK on success, ENOENT if rule is not part of the table.
*/
static errno_t fci_fp_get_rule_pos_in_table(const fci_fp_table_t *fp_table, fci_fp_rule_t *rule, uint8_t *pos)
{
    uint16_t i;
    const fci_fp_rule_t *rule_item;
    errno_t ret = ENOENT;

    rule_item = fci_fp_table_1st_rule(fp_table);
    for (i = 0U; i < fp_table->rule_count; i++)
    {
        if(rule_item == rule)
        {
            *pos = i;
            ret = EOK;
            break;
        }
        rule_item = fci_fp_rule_next_sibling(rule_item);
    }
    return ret;
}

/**
* @brief Initializes the module
*/
void fci_fp_db_init(void)
{
    (void)autolibc_memset(&fci_fp_rule_db, 0, sizeof(fci_fp_rule_db_t));
    (void)autolibc_memset(&fci_fp_table_db, 0, sizeof(fci_fp_table_db_t));
    /* create rules ISA */
    isa_init(&fci_fp_rule_db.rules, &fci_fp_rule_db_rules_isa_def);
    /* create tables ISA */
    isa_init(&fci_fp_table_db.tables, &fci_fp_table_db_tables_isa_def);
}

/**
* @brief Crates a flexible parser rule
* @param[in] name Name of the rule (unique identifier)
* @param[in] data Expected value of the data (network endian)
* @param[in] mask Mask to be applied on the data (network endian)
* @param[in] offset Offset of the data to be compared (network endian)
* @param[in] flags Flags describing the rule - see pfe_ct_fp_flags_t
* @param[in] next_rule Name of the rule to be examined next if none of flags FP_FL_ACCEPT | FP_FL_REJECT is set
* @return Either EOK or an error code.
*/
errno_t fci_fp_db_create_rule(char_t *name, uint32_t data, uint32_t mask, uint16_t offset, pfe_ct_fp_flags_t flags, char_t *next_rule)
{
    fci_fp_rule_t *rule = NULL_PTR;
    bool_t ignore_next_rule = FALSE;
    errno_t ret;
    uint32_t length;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == name))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* check name for validity */
        length = autolibc_strnlen(name, sizeof(rule->name));
        if((sizeof(rule->name) <= length) || (0U == length))
        {
            NXP_LOG_ERROR("Rule name string length is invalid\n");
            ret = EINVAL;
        }
        else
        {
            length = autolibc_strnlen(next_rule, sizeof(rule->next_rule));
            if((NULL_PTR != next_rule) && ((sizeof(rule->next_rule) <= length)))
            {
                NXP_LOG_ERROR("Next rule string length is invalid\n");
                ret = EINVAL;
            }
            else
            {
                if((0U == ((uint8_t)flags & ((uint8_t)FP_FL_ACCEPT | (uint8_t)FP_FL_REJECT))) && (NULL_PTR == next_rule))
                {   /* If flags are not FP_FL_REJECT and not FP_FL_ACCEPT we need the next rule name */
                    NXP_LOG_ERROR("Flags FP_FL_ACCEPT and FP_FL_REJECT are not set but next rule is not defined (NULL)\n");
                    ret = EINVAL;
                }
                else if(((uint8_t)FP_FL_ACCEPT | (uint8_t)FP_FL_REJECT) == ((uint8_t)flags & ((uint8_t)FP_FL_ACCEPT | (uint8_t)FP_FL_REJECT)))
                {   /* Cannot do both Accept and Reject action */
                    NXP_LOG_ERROR("Both flags FP_FL_ACCEPT and FP_FL_REJECT are set\n");
                    ret = EINVAL;
                }
                else
                {
                    if((0U != ((uint8_t)flags & ((uint8_t)FP_FL_ACCEPT | (uint8_t)FP_FL_REJECT))) && (NULL_PTR != next_rule))
                    {   /* Ignored argument */
                        NXP_LOG_WARNING("Next rule is ignored with these flags: 0x%x\n", flags);
                        ignore_next_rule = TRUE;
                    }
                    /* Check that the name is unique in our database */
                    if(NULL_PTR != fci_fp_rule_get_first_common(&fci_fp_rule_db, FP_RULE_CRIT_NAME, name))
                    {   /* Rule with same name found in database */
                        NXP_LOG_ERROR("Rule with name \"%s\" already exists\n", name);
                        ret = EEXIST;
                    }
                    else
                    {
                        /* Allocate table item storage */
                        rule = (fci_fp_rule_t *)isa_reserve(&fci_fp_rule_db.rules);
                        if(NULL_PTR == rule)
                        {
                            NXP_LOG_ERROR("No ISA item for the rule\n");
                            ret = ENOMEM;
                        }
                        else
                        {
                            /* Initialize */
                            (void)autolibc_memset(rule, 0, sizeof(fci_fp_rule_t));
                            /* Store the input parameters */
                            (void)autolibc_strncpy(rule->name, name, sizeof(rule->name));
                            if((NULL_PTR != next_rule) && (FALSE == ignore_next_rule))
                            {   /* Just store the next rule name, no validation yet because rule may be added later */
                                (void)autolibc_strncpy(rule->next_rule, next_rule, sizeof(rule->next_rule));
                            }
                            else
                            {
                                rule->next_rule[0U] = '\0';
                            }
                            /* set chaining values to unchained */
                            rule->chained_next_rule_idx = fci_fp_get_rule_index(rule);
                            rule->chained_prev_rule_idx = rule->chained_next_rule_idx;
                            rule->data = data;
                            rule->mask = mask;
                            rule->offset = offset;
                            rule->flags = flags;
                            ret = EOK;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

/**
* @brief Destroys a flexible parser rule
* @param[in] name Name of the table to destroy
* @return EOK or an error code.
*/
errno_t fci_fp_db_destroy_rule(char_t *name)
{
  fci_fp_rule_t *rule = NULL;
  errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(NULL == name)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Find the rule */
        rule = fci_fp_rule_get_first_common(&fci_fp_rule_db, FP_RULE_CRIT_NAME, name);
        if(NULL == rule)
        {   /* No such rule */
            NXP_LOG_ERROR("Rule with name \"%s\" does not exist\n", name);
            ret = ENOENT;
        }
        else
        {
            /* Check that the rule is not in use */
            if(NULL != rule->table)
            {   /* Still in use */
                NXP_LOG_ERROR("Rule \"%s\" is in use in table \"%s\"\n", name, rule->table->name);
                ret = EACCES;
            }
            else
            {
                /* Remove/Free the rule instance in ISA */
                (void)isa_release(&fci_fp_rule_db.rules, rule);
                ret = EOK;
            }
        }
    }
    return ret;
}

/**
* @brief Creates a flexible parser rules table
* @param[in] name Name of the table - unique identifier
* @return EOK or an error code.
*/
errno_t fci_fp_db_create_table(char_t *name)
{
    fci_fp_table_t  *fp_table;
    errno_t         ret;
    uint32_t        length;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(NULL_PTR == name)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret =  EINVAL;
    }
    else
#endif
    {
        /* check name for validity */
        length = autolibc_strnlen(name, sizeof(fp_table->name));
        if((sizeof(fp_table->name) <= length) || (0U == length))
        {
            NXP_LOG_ERROR("Table name string is invalid\n");
            ret = EINVAL;
        }
        else
        {
            /* Check that the name is unique in our database */
            if(NULL_PTR != fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, name))
            {   /* Rule with same name found in database */
                NXP_LOG_ERROR("Table with name \"%s\" already exists\n", name);
                ret = EEXIST;
            }
            else
            {
                /* Allocate table item storage */
                fp_table = (fci_fp_table_t *)isa_reserve(&fci_fp_table_db.tables);
                if(NULL_PTR == fp_table)
                {
                    NXP_LOG_ERROR("No ISA item for the table\n");
                    ret = ENOMEM;
                }
                else
                {
                    /* Initialize */
                    (void)autolibc_memset(fp_table, 0, sizeof(fci_fp_table_t));
                    (void)autolibc_strncpy(fp_table->name, name, sizeof(fp_table->name));
                    ret = EOK;
                }
            }
        }
    }
    return ret;

}

/**
* @brief Destroys a flexible parser rules table
* @param[in] name Name of the table to destroy
* @param[in] force If set to TRUE the table is destroyed even if it is still in use.
* @return EOK or an error code.
*/
errno_t fci_fp_db_destroy_table(char_t *name, bool_t force)
{
    fci_fp_table_t *fp_table;
    fci_fp_rule_t *rule;
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(NULL_PTR == name)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Find the table */
        fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, name);
        if(NULL_PTR == fp_table)
        {
            NXP_LOG_ERROR("Table with name \"%s\" does not exist\n", name);
            ret = ENOENT;
        }
        else
        {
            /* Check that the table is not in use */
            if(0U != fp_table->dmem_addr)
            {   /* Table is still in use */
                if(FALSE == force)
                {   /* No override */
                    NXP_LOG_ERROR("Table \"%s\" is in use\n", name);
                    ret = EACCES;
                }
                else
                {   /* Override (and ride to hell) */
                    NXP_LOG_WARNING("Table \"%s\" is in use\n", name);
                    fp_table->dmem_addr = 0U;
                }
            }
            if(EOK == ret)
            {
                /* Unlink all rules in the table if there are any */
                while (0U < fp_table->rule_count)
                {
                    rule = fci_fp_table_1st_rule(fp_table);
                    fci_fp_unlink_rule_from_chain(rule);
                }

                /* Remove/Free the table instance in ISA */
                (void)isa_release(&fci_fp_table_db.tables, fp_table);
            }
        }
    }
    return ret;
}


/**
* @brief Adds a rule into a table at given position
* @param[in] table_name Table where the rule shall be added
* @param[in] rule_name Rule which shall be added into a table.
* @param[in] position Position where to place rule. Either fci_fp_RULE_POSITION_LAST, fci_fp_RULE_POSITION_FIRST,
*            or an integer in range 0 to 255 describing the position.
* @note Single rule can belong to only one table.
* @return Either EOK or an error code.
*/
errno_t fci_fp_db_add_rule_to_table(char_t *table_name, char_t *rule_name, uint16_t position)
{
    fci_fp_table_t *fp_table;
    fci_fp_rule_t *rule, *head_rule;
    uint32_t i = 0U; /* Start search from position 0 */
    errno_t ret = EINVAL; /* Invalid value */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if((NULL_PTR == table_name) || (NULL_PTR == rule_name))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Check that the rule does exist */
        rule = fci_fp_rule_get_first_common(&fci_fp_rule_db, FP_RULE_CRIT_NAME, rule_name);
        if(NULL_PTR == rule)
        {
            NXP_LOG_ERROR("Rule \"%s\" does not exist\n", rule_name);
            ret = ENOENT;
        }
        else
        {
            /* Check that the rule does not belong to any other table */
            if(NULL_PTR != rule->table)
            {
                NXP_LOG_ERROR("Rule \"%s\" is already part of the table \"%s\"\n", rule_name, rule->table->name);
                ret = EACCES;
            }
            else
            {
                /* Check that the table does exist */
                fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, table_name);
                if(NULL_PTR == fp_table)
                {
                    NXP_LOG_ERROR("Table \"%s\" does not exist\n", table_name);
                    ret = ENOENT;
                }
                else
                {
                    /* Add rule into the table */
                    if(0U == fp_table->rule_count)
                    {   /* Empty list - ignore position */
                        if((position != FCI_FP_RULE_POSITION_FIRST) && (position != FCI_FP_RULE_POSITION_LAST))
                        {
                            NXP_LOG_WARNING("Adding into an empty table position %u ignored\n", position);
                        }
                        else
                        {
                        /* Do nothing */
                        }
                        fp_table->rules_chain_1st_idx = fci_fp_get_rule_index(rule);
                    }
                    else
                    {
                        /* head_rule is at position 0 */
                        head_rule = fci_fp_table_1st_rule(fp_table);
                        if(position == FCI_FP_RULE_POSITION_FIRST)
                        {   /* Insert as the first one */
                            rule->chained_next_rule_idx = fp_table->rules_chain_1st_idx;
                            fp_table->rules_chain_1st_idx = fci_fp_get_rule_index(rule);
                            head_rule->chained_prev_rule_idx = fp_table->rules_chain_1st_idx;
                        }
                        else
                        {
                            /* position > FCI_FP_RULE_POSITION_FIRST && position <= FCI_FP_RULE_POSITION_LAST */
                            /* Table not empty - need to handle position request */
                            bool_t added = FALSE;
                            /* find desired position */
                            for (i = 1U; i < fp_table->rule_count; i++)
                            {
                                if (position == i)
                                {   /* Insert at specified position */
                                    /* next sibling of head rule */
                                    fci_fp_rule_t *head_rule_next = fci_fp_rule_next_sibling(head_rule);

                                    if (head_rule != head_rule_next)
                                    {
                                        /* head_rule has next sibling, re-link to rule being added */
                                        rule->chained_next_rule_idx = head_rule->chained_next_rule_idx;
                                        head_rule_next->chained_prev_rule_idx = fci_fp_get_rule_index(rule);
                                    }
                                    else
                                    {
                                        /* head_rule hasn't next sibling, nothing to do ! */
                                    }

                                    added = TRUE;
                                    break;
                                }
                                head_rule = fci_fp_rule_next_sibling(head_rule);
                            }

                            /* FCI_FP_RULE_POSITION_LAST or append at the end */
                            if(FALSE == added)
                            {   /* The requested position has not been found - add at the end */
                                NXP_LOG_WARNING("Position %u does not exist, adding at %u\n", (uint_t)position, (uint_t)i);
                            }

                            /* Add as the last one */
                            rule->chained_prev_rule_idx = fci_fp_get_rule_index(head_rule);
                            head_rule->chained_next_rule_idx = fci_fp_get_rule_index(rule);
                        }
                    }
                    rule->table = fp_table;
                    fp_table->rule_count += 1U;
                    ret = EOK;
                }
            }
        }
    }
    return ret;
}

/**
* @brief Removes the rule from a table
* @param[in] rule_name Rule to be removed from the table
* @details Each rule knows which table it belongs therefore the table reference is not needed.
* @return EOK or error code.
*/
errno_t fci_fp_db_remove_rule_from_table(char_t *rule_name)
{
    fci_fp_rule_t *rule;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == rule_name))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Check that the rule does exist */
        rule = fci_fp_rule_get_first_common(&fci_fp_rule_db, FP_RULE_CRIT_NAME, rule_name);
        if(NULL_PTR == rule)
        {
            NXP_LOG_ERROR("Rule \"%s\" does not exist\n", rule_name);
            ret = ENOENT;
        }
        else
        {
            /* Check that the rule is in a table */
            if(NULL_PTR != rule->table)
            {   /* Rule in a table - remove it */
                fci_fp_unlink_rule_from_chain(rule);
            }
            else
            {   /* Rule not in a table */
                NXP_LOG_WARNING("Rule \"%s\" is not part of any table\n", rule_name);
            }
            ret = EOK;
        }
    }
    return ret;
}

/**
* @brief Returns table address in the DMEM
* @param[in] table Table instance which DMEM address shall be returned.
* @return DMEM address of the table or 0 if table has not been written into DMEM yet.
*/
uint32_t fci_fp_db_get_table_dmem_addr(char_t *table_name)
{
    const fci_fp_table_t *fp_table;
    uint32_t retval;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(NULL == table_name)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        retval = 0U;
    }
    else
#endif
    {
        fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, table_name);
        if(NULL == fp_table)
        {
            NXP_LOG_WARNING("Table \"%s\" not found\n", table_name);
            retval = 0U;
        }
        else
        {
            retval = fp_table->dmem_addr;
        }
    }
    return retval;
}

/**
* @brief Writes flexible parser table into DMEM of all PEs in given Classifier
* @param[in] classifier Classifier which DMEM shall be written
* @param[in] table Table which shall be written
* @details Function allocates the DMEM to write the table and writes the table into
*          this memory. Use the function fci_fp_db_get_table_dmem_addr to obtain the
*          table address.
* @return Either EOK or an error code.
*/
errno_t fci_fp_db_push_table_to_hw(pfe_class_t *class, char_t *table_name)
{
    fci_fp_table_t *fp_table;
    fci_fp_rule_t *next_rule;
    pfe_ct_fp_rule_t rule_buf;
    fci_fp_rule_t *rule;
    uint16_t i;
    uint8_t pos;
    errno_t ret = EOK;


#if defined(PFE_CFG_NULL_ARG_CHECK)
    if((NULL_PTR == class)||(NULL_PTR == table_name))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Get the table */
        fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, table_name);
        if(NULL_PTR == fp_table)
        {
            NXP_LOG_WARNING("Table \"%s\" not found\n", table_name);
            ret = ENOENT;
        }
        else
        {

            fp_table->dmem_addr = pfe_fp_create_table(class, fp_table->rule_count);
            fp_table->class = class;
            if(0U == fp_table->dmem_addr)
            {
                NXP_LOG_ERROR("Cannot write the table");
                ret = EFAULT;
            }
            else
            {

                /* Write rules into the table */
                rule = fci_fp_table_1st_rule(fp_table);
                for (i = 0U; i < fp_table->rule_count; i++)
                {
                    rule_buf.data = rule->data;
                    rule_buf.mask = rule->mask;
                    rule_buf.offset = rule->offset;
                    rule_buf.flags = rule->flags;
                    if(rule->next_rule[0U] != '\0')
                    {   /* Next rule is specified */
                        /* Convert next_rule name to position in the table */
                        next_rule = fci_fp_rule_get_first_table(fp_table, FP_RULE_CRIT_NAME, rule->next_rule);
                        if(NULL_PTR == next_rule)
                        {   /* Failed - cannot proceed */
                            NXP_LOG_ERROR("Referenced rule \"%s\" is not part of the table \"%s\"\n", rule->next_rule, table_name);
                            pfe_fp_destroy_table(class, fp_table->dmem_addr);
                            fp_table->dmem_addr = 0U;
                            ret = ENOENT;
                        }
                        else if(EOK != fci_fp_get_rule_pos_in_table(fp_table, next_rule, &pos))
                        {   /* Failed - cannot proceed */
                            NXP_LOG_ERROR("Referenced rule \"%s\" is not part of the table \"%s\"\n", rule->next_rule, table_name);
                            pfe_fp_destroy_table(class, fp_table->dmem_addr);
                            fp_table->dmem_addr = 0U;
                            ret = ENOENT;
                        }
                        else
                        {
                            /*Do nothing - Avoid MISRA rule 15.7 */
                        }
                        if (EOK != ret)
                        {
                            break;
                        }
                        rule_buf.next_idx = pos;
                    }
                    else
                    {   /* Next rule is not used */
                        rule_buf.next_idx = 0xFFU; /* If used it will cause FW internal check to detect it */
                    }
                    (void)pfe_fp_table_write_rule(class, fp_table->dmem_addr, &rule_buf, i);

                    rule = fci_fp_rule_next_sibling(rule);
                }
            }
        }
    }
    return ret;
}

/**
* @brief Removes table from the DMEM in PEs when it is no longer in use
* @param[in] table_name Name of the table to be removed
* @warning Remove the table only if there are no references to it
* @details Removal of unused tables from the DMEM is needed to avoid depletion of the
*          DMEM memory pool.
* @return EOK or an error code.
*/
errno_t fci_fp_db_pop_table_from_hw(char_t *table_name)
{
    fci_fp_table_t *fp_table;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(NULL == table_name)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Get the table */
        fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, table_name);
        if(NULL == fp_table)
        {
            NXP_LOG_WARNING("Table \"%s\" not found\n", table_name);
            ret = ENOENT;
        }
        else
        {

            /* Free the DMEM */
            pfe_fp_destroy_table(fp_table->class, fp_table->dmem_addr);
            /* Clear the references to DMEM */
            fp_table->dmem_addr = 0U;
            fp_table->class = NULL;
            ret = EOK;
        }
    }
    return ret;
}

/**
* @brief Returns name of the table being written at given DMEM address
* @param[in] addr Address to find the table
* @param[out] table_name Returned table name
* @return EOK or an error code
*/
errno_t fci_fp_db_get_table_from_addr(uint32_t addr, char_t **table_name)
{
    const fci_fp_table_t *fp_table;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(NULL == table_name)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        if(0U == addr)
        {   /* 0 is not valid table address, used as no-address */
            ret = EINVAL;
        }
        else
        {
            fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_ADDRESS, &addr);
            if(NULL == fp_table)
            {
                NXP_LOG_WARNING("Table with address 0x%x not found\n", (uint_t)addr);
                ret = ENOENT;
            }
            else
            {
                *table_name = (char_t *)fp_table->name;
                ret = EOK;
            }
        }
    }
    return ret;
}

/**
 * @brief       Get first DB entry (table) matching the criterion
 * @param[in]   crit The criterion
 * @parma[in]   arg The criterion argument
 * @return      FP table instance or NULL if not found
 */
fci_fp_table_t *fci_fp_db_get_first(fci_fp_table_criterion_t crit, void *arg)
{
    return fci_fp_table_get_first(&fci_fp_table_db, crit, arg);
}

/**
* @brief Returns parameters of the first rule in the database
* @details Function is intended to start query of all rules in the database (by FCI).
* @param[out] rule_info the First rule data got from database
* @param[out] next_rule Name of the next rule (if any)
* @return EOK or an error code.
*/
errno_t fci_fp_db_get_first_rule(fci_fp_rule_info_t *rule_info, char_t **next_rule)
{
    fci_fp_rule_t *rule;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if((NULL_PTR == rule_info) || (NULL_PTR == next_rule))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        rule = fci_fp_rule_get_first_common(&fci_fp_rule_db, FP_RULE_CRIT_ALL, NULL_PTR);
        if(NULL_PTR == rule)
        {
            ret = ENOENT;
        }
        else
        {
            rule_info->rule_name = rule->name;
            rule_info->data = rule->data;
            rule_info->mask = rule->mask;
            rule_info->offset = rule->offset;
            rule_info->flags = rule->flags;
            *next_rule = rule->next_rule;
            ret = EOK;
        }
    }
    return ret;
}

/**
* @brief Returns parameters of the next rule in the database
* @details Function is intended to continue query of all rules in the database (by FCI).
* @param[out] rule_info the Next rule data got from database
* @param[out] next_rule Name of the next rule (if any)
* @return EOK or an error code.
*/
errno_t fci_fp_db_get_next_rule(fci_fp_rule_info_t *rule_info, char_t **next_rule)
{
    fci_fp_rule_t *rule;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if((NULL_PTR == rule_info) || (NULL_PTR == next_rule))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        rule = fci_fp_rule_get_next_common(&fci_fp_rule_db);
        if(NULL_PTR == rule)
        {
            ret = ENOENT;
        }
        else
        {
            rule_info->rule_name = rule->name;
            rule_info->data = rule->data;
            rule_info->mask = rule->mask;
            rule_info->offset = rule->offset;
            rule_info->flags = rule->flags;
            *next_rule = rule->next_rule;
            ret = EOK;
        }
    }
    return ret;
}

/**
* @brief Returns parameters of the first rule in the table
* @details Function is intended to start query of all rules in the table (by FCI).
* @param[in]  table_name Name of the table to query
* @param[out] rule_info the First rule data got from table
* @param[out] next_rule Name of the next rule (if any)
* @return EOK or an error code.
*/
errno_t fci_fp_db_get_table_first_rule(char_t *table_name, fci_fp_rule_info_t *rule_info, char_t **next_rule)
{
    fci_fp_table_t *fp_table;
    fci_fp_rule_t *rule;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if((NULL_PTR == table_name) || (NULL_PTR == rule_info) || (NULL_PTR == next_rule))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Get the table */
        fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, table_name);
        if(NULL_PTR == fp_table)
        {
            NXP_LOG_WARNING("Table \"%s\" not found\n", table_name);
            ret = ENOENT;
        }
        else
        {
            /* Get the first rule */
            rule = fci_fp_rule_get_first_table(fp_table, FP_RULE_CRIT_ALL, NULL_PTR);
            if(NULL_PTR == rule)
            {
                ret = ENOENT;
            }
            else
            {
                rule_info->rule_name = rule->name;
                rule_info->data = rule->data;
                rule_info->mask = rule->mask;
                rule_info->offset = rule->offset;
                rule_info->flags = rule->flags;
                *next_rule = rule->next_rule;
                ret = EOK;
            }
        }
    }
    return ret;
}

/**
* @brief Returns parameters of the next rule in the table
* @details Function is intended to start query of all rules in the table (by FCI).
* @param[in]  table_name Name of the table to query
* @param[out] rule_info the Next rule data got from table
* @param[out] next_rule Name of the next rule (if any)
* @return EOK or an error code.
*/
errno_t fci_fp_db_get_table_next_rule(char_t *table_name, fci_fp_rule_info_t *rule_info, char_t **next_rule)
{
    fci_fp_table_t *fp_table;
    fci_fp_rule_t *rule;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if((NULL == table_name) || (NULL == rule_info) || (NULL == next_rule))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Get the table */
        fp_table = fci_fp_table_get_first(&fci_fp_table_db, FP_TABLE_CRIT_NAME, table_name);
        if(NULL == fp_table)
        {
            NXP_LOG_WARNING("Table \"%s\" not found\n", table_name);
            ret = ENOENT;
        }
        else
        {
            /* Get the rule */
            rule = fci_fp_rule_get_next_table(fp_table);
            if(NULL == rule)
            {
                ret = ENOENT;
            }
            else
            {
                rule_info->rule_name = rule->name;
                rule_info->data = rule->data;
                rule_info->mask = rule->mask;
                rule_info->offset = rule->offset;
                rule_info->flags = rule->flags;
                *next_rule = rule->next_rule;
                ret = EOK;
            }
        }
    }
    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)

/**
* @brief Prints a rule in a human readable form
* @param[in] rule Rule to be printed
* @param[in] buf Buffer where to put the output
* @param[in] len Size of the buffer
* @param[in] verb_level Verbosity level
* @return Number of characters written into the buffer
*/
static uint32_t fci_fp_print_rule(fci_fp_rule_t *rule, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;
    (void)verb_level;

    len += oal_util_snprintf(buf + len, buf_len - len, "%s = {", rule->name);
    /* Conditions */
    if((uint8_t)FP_FL_INVERT == ((uint8_t)rule->flags & (uint8_t)FP_FL_INVERT))
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "!");
    }
    len += oal_util_snprintf(buf + len, buf_len - len, "(0x%x & 0x%x == ", rule->data, rule->mask);
    if((uint8_t)FP_FL_L4_OFFSET == ((uint8_t)rule->flags & (uint8_t)FP_FL_L4_OFFSET))
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "frame[L4 header + %u] & 0x%x)", rule->offset, rule->mask);
    }
    if((uint8_t)FP_FL_L3_OFFSET == ((uint8_t)rule->flags & (uint8_t)FP_FL_L3_OFFSET))
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "frame[L3 header + %u] & 0x%x)", rule->offset, rule->mask);
    }
    else
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "frame[%u] & 0x%x)", rule->offset, rule->mask);
    }
    /* Consequences */
    if((uint8_t)FP_FL_REJECT == ((uint8_t)rule->flags & (uint8_t)FP_FL_REJECT))
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "? REJECT : use next rule");
    }
    else if((uint8_t)FP_FL_ACCEPT == ((uint8_t)rule->flags & (uint8_t)FP_FL_ACCEPT))
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "? ACCEPT : use next rule");
    }
    else
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "? use rule %s : use next rule", rule->next_rule);
    }
    len += oal_util_snprintf(buf + len, buf_len - len, "}\n");
    return len;
}

/**
* @brief Prints table rules in a human readable form
* @param[in] table Table to be printed
* @param[in] buf Buffer where to put the output
* @param[in] len Size of the buffer
* @param[in] verb_level Verbosity level
* @return Number of characters written into the buffer
*/
static uint32_t fci_fp_print_table(const fci_fp_table_t *fp_table, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint16_t i;
    uint32_t len;
    fci_fp_rule_t *rule;

    len = oal_util_snprintf(buf, buf_len, "%s = {\n", fp_table->name);
    rule = fci_fp_table_1st_rule(fp_table);
    for (i = 0U; i < fp_table->rule_count; i++)
    {
        len += fci_fp_print_rule(rule, buf + len, buf_len - len, verb_level);
        rule = fci_fp_rule_next_sibling(rule);
    }

    len += oal_util_snprintf(buf + len, buf_len - len, "\n}\n");
    return len;
}

/**
* @brief Prints all tables in a human readable form
* @param[in] table Table to be printed
* @param[in] buf Buffer where to put the output
* @param[in] len Size of the buffer
* @param[in] verb_level Verbosity level
* @return Number of characters written into the buffer
*/
uint32_t fci_fp_print_tables(char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    const fci_fp_table_t *fp_table;
    uint32_t len = 0U;
    uint32_t ii;
    const pfe_isa_t *isa = &fci_fp_table_db.tables;

    for (ii = 0U; ii < isa->occupied_items_count; ii++)
    {
        fp_table = (fci_fp_table_t *)isa_item(isa, ii);
        len += fci_fp_print_table(fp_table, buf + len, buf_len - len, verb_level);
    }
    return len;
}

uint32_t pfe_fp_get_text_statistics(pfe_fp_t *temp, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    const fci_fp_table_t *fp_table;
    pfe_ct_class_flexi_parser_stats_t c_stats;
    pfe_ct_class_flexi_parser_stats_t c_stats_sum;
    uint32_t len = 0U;
    uint32_t pe_idx;
    uint32_t num_of_pes;
    uint32_t ii;
    const pfe_isa_t *isa = &fci_fp_table_db.tables;

    (void)temp;

    for (ii = 0U; ii < isa->occupied_items_count; ii++)
    {
        fp_table = (fci_fp_table_t *)isa_item(isa, ii);
        num_of_pes = pfe_class_get_num_of_pes(fp_table->class);
        len += oal_util_snprintf(buf + len, buf_len - len, "%s = {\n", fp_table->name);
        if (fp_table->dmem_addr != 0U)
        {
            (void)autolibc_memset(&c_stats_sum, 0, sizeof(pfe_ct_class_flexi_parser_stats_t));

            for(pe_idx = 0U; pe_idx < num_of_pes; pe_idx++)
            {
                (void)autolibc_memset(&c_stats, 0, sizeof(pfe_ct_class_flexi_parser_stats_t));
                (void)pfe_fp_table_get_statistics(fp_table->class, pe_idx, fp_table->dmem_addr, &c_stats);
                pfe_class_flexi_parser_stats_endian(&c_stats);
                pfe_class_sum_flexi_parser_stats(&c_stats_sum, &c_stats);
            }

            len += pfe_class_fp_stat_to_str(&c_stats_sum, buf + len, buf_len - len, verb_level);
        }
        else
        {
            len += oal_util_snprintf(buf + len, buf_len - len, "Table not enabled in Firmware\n");
        }

        len += oal_util_snprintf(buf + len, buf_len - len, "\n}\n");
    }

    return len;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_FCI_ENABLE */
#endif /* PFE_CFG_PFE_MASTER */
