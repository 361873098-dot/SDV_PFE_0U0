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

/**
 * @file        pfe_log_if_slave.c
 * @brief       The PFE logical interface module source file (slave)
 * @details     TThis file contains logical interface-related functionality for
 *              the slave driver variant. All logical interface instance
 *              manipulation is done via RPC in way that local driver only
 *              sends requests to master driver which performs the actual
 *              requested operations.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"

#ifdef PFE_CFG_PFE_SLAVE
#include "hal.h"
#include "pfe_platform_cfg.h"
#include "pfe_ct.h"
#include "linked_list.h"
#include "pfe_log_if.h"
#include "pfe_idex.h" /* The RPC provider */
#include "pfe_platform_rpc.h" /* The RPC codes and data structures */
#include "isa.h"

struct pfe_log_if_tag
{
    pfe_phy_if_t *parent;           /*!< Parent physical interface */
    char_t name[PFE_CFG_LOG_IF_NAME_LENGTH_MAX];/*!< Interface name */
    uint8_t id;                     /*!< Interface ID */
    pfe_mac_db_t mac_db;            /*!< MAC database */
};

#define ETH_43_PFE_START_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"
static bool_t pfe_log_ifs_initialized = FALSE;
#define ETH_43_PFE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_isa_t pfe_log_ifs;
static pfe_isa_index_t pfe_log_ifs_index[PFE_CFG_MAX_LOG_IFS];
static pfe_log_if_t pfe_log_ifs_pool[PFE_CFG_MAX_LOG_IFS];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static const pfe_isa_definition_t pfe_log_ifs_isa_def =
{
    .item_count = PFE_CFG_MAX_LOG_IFS,
    .item_size = sizeof(pfe_log_if_t),
    .flags = { .ordered = ISA_FLAG_STRICT_ORDER },
    .item_indexes = pfe_log_ifs_index,
    .items = pfe_log_ifs_pool,
    .clear_cb = (pfe_isa_clear_cb_t)NULL_PTR
};
#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
static uint32_t pfe_log_if_strnlen(const char_t *str, uint32_t strsz);

/**
 * @brief Computes length of the string.
 * @details Function searches for the null character and counts bytes until it
 *          finds it or stops after strsz characters is exhausted
 * @param[in] str String to determine the length for.
 * @param[in] strsz maximum number of characters search through
 * @return String length or strsz when null character not found
 */
static uint32_t pfe_log_if_strnlen(const char_t *str, uint32_t strsz)
{
    uint32_t length = 0U;

    if(NULL_PTR != str)
    {
        while((str[length] != '\0') && (length < strsz))
        {
            length++;
        }
    }

    return length;
}

static errno_t pfe_log_if_db_lock(void)
{
    errno_t ret;

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_IF_LOCK, NULL, 0, NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Unable to lock interface DB: %d\n", ret);
    }

    return ret;
}

static errno_t pfe_log_if_db_unlock(void)
{
    errno_t ret;

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_IF_UNLOCK, NULL, 0, NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Unable to lock interface DB: %d\n", ret);
    }

    return ret;
}

/**
 * @brief Initialise necessary storages and variables for all logical interfaces
 */
errno_t pfe_log_ifs_init(void)
{
    if (FALSE == pfe_log_ifs_initialized)
    {
        isa_init(&pfe_log_ifs, &pfe_log_ifs_isa_def);
        pfe_log_ifs_initialized = TRUE;
    }
    else
    {
        NXP_LOG_WARNING("pfe_log_ifs_init() already called\n");
    }

    return EOK;
}

/**
 * @brief Uninitialise necessary storages and variables for all logical interfaces
 */
void pfe_log_ifs_deinit(void)
{
    if (TRUE == pfe_log_ifs_initialized)
    {
        (void)autolibc_memset(&pfe_log_ifs, 0, sizeof(pfe_log_ifs));
        pfe_log_ifs_initialized = FALSE;
    }
}

/**
 * @brief       Create new logical interface instance
 * @param[in]   parent The parent physical interface
 * @param[in]   name Name of the interface
 * @return      The interface instance or NULL if failed
 */
pfe_log_if_t *pfe_log_if_create(pfe_phy_if_t *parent, const char_t *name)
{
    pfe_platform_rpc_pfe_log_if_create_arg_t  arg;
    pfe_platform_rpc_pfe_log_if_create_ret_t  rpc_ret = {0U};
    pfe_log_if_t                              *iface;
    errno_t                                   ret;
    uint32_t                                  length;


    (void)autolibc_memset(&arg, 0, sizeof(arg));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == parent) || (NULL_PTR == name)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        iface = NULL_PTR;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* check name for validity */
        length = pfe_log_if_strnlen(name, sizeof(iface->name));
        if((sizeof(iface->name) <= length) || (0U == length))
        {
            NXP_LOG_ERROR("LOG IF name string is invalid\n");
            iface = NULL_PTR;
        }
        else if(TRUE == pfe_log_ifs_initialized)
        {
            (void)pfe_log_if_db_lock();

            /*  Ask master to create new logical interface */
            arg.phy_if_id = pfe_phy_if_get_id(parent);
            (void)autolibc_strncpy(arg.name, name, sizeof(arg.name));
            ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_CREATE, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));

            (void)pfe_log_if_db_unlock();

            if (EOK != ret)
            {
                NXP_LOG_DEBUG("Can't create logical interface: %d\n", ret);
                iface = NULL_PTR;
            }
            else
            {
                iface = (pfe_log_if_t *)isa_reserve(&pfe_log_ifs);
                if (NULL_PTR == iface)
                {
                    NXP_LOG_ERROR("Malloc failed\n");
                }
                else
                {
                    (void)autolibc_memset(iface, 0, sizeof(*iface));
                    iface->parent = parent;
                    iface->id = rpc_ret.log_if_id;

                    if (EOK != pfe_mac_db_create(&iface->mac_db))
                    {
                        NXP_LOG_ERROR("Could not create MAC database\n");
                        (void)isa_release(&pfe_log_ifs, iface);
                        iface = NULL_PTR;
                    }
                    else
                    {
                        (void)autolibc_strncpy(iface->name, name, sizeof(iface->name));
                    }
                }
            }
        }
        else
        {
            NXP_LOG_ERROR("LOG IFs module not initialized\n");
            iface = NULL_PTR;
        }
    }

    return iface;
}

/**
 * @brief       Get interface ID
 * @param[in]   iface The interface instance
 * @return      The interface ID
 */
__attribute__((pure)) uint8_t pfe_log_if_get_id(const pfe_log_if_t *iface)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return 0xffU;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return iface->id;
}

/**
 * @brief       Get parent physical interface
 * @param[in]   iface The interface instance
 * @return      Physical interface instance or NULL if failed
 */
__attribute__((pure)) pfe_phy_if_t *pfe_log_if_get_parent(const pfe_log_if_t *iface)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return NULL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return iface->parent;
}

/**
 * @brief       Destroy interface instance
 * @param[in]   iface The interface instance
 */
void pfe_log_if_destroy(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_destroy_arg_t req = {0U};
    errno_t ret;

    if (NULL_PTR != iface)
    {
        (void)pfe_log_if_db_lock();

        /*  Ask the master to unbind and destroy the logical interface */
        req.log_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DESTROY, &req, (uint16_t)sizeof(req), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("Can't destroy remote instance: %d\n", ret);
        }

        iface->name[0] = '\0';

        (void)pfe_log_if_db_unlock();

        (void)isa_release(&pfe_log_ifs, iface);
    }
}

/**
 * @brief       Set match type to OR match
 * @details     Logical interface rules will be matched with OR logic
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_set_match_or(pfe_log_if_t *iface)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_set_match_and_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_SET_MATCH_OR, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't set match to OR type on interfaces: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Set match type to AND match
 * @details     Logical interface rules will be matched with AND logic
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_set_match_and(pfe_log_if_t *iface)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_set_match_and_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_SET_MATCH_AND, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't set match to AND type on interfaces: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Check if match is OR
 * @details     Set new match rules. All previously configured ones will be
 *              overwritten.
 * @param[in]   iface The interface instance
 * @retval      TRUE match is OR type
 * @retval      FALSE match is AND type
 */
bool_t pfe_log_if_is_match_or(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_is_match_or_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_is_match_or_ret_t rpc_ret = {0};
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return FALSE;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Query the master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_IS_MATCH_OR, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get match OR/AND status: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    if (EOK != ret)
    {
        return FALSE;
    }
    else
    {
        return rpc_ret.status;
    }
}

/**
 * @brief       Set match rules
 * @details     Set new match rules. All previously configured ones will be
 *              overwritten.
 * @param[in]   iface The interface instance
 * @param[in]   rules Rules to be set. See pfe_ct_if_m_rules_t.
 * @param[in]   args Pointer to the structure with arguments.
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_set_match_rules(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rules, const pfe_ct_if_m_args_t *args)
{
    pfe_platform_rpc_pfe_log_if_set_match_rules_arg_t req = {0};
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (NULL == args)
    {
        return EINVAL;
    }

    req.log_if_id = iface->id;
    req.rules = (pfe_ct_if_m_rules_t)oal_htonl(rules);
    (void)autolibc_memcpy(&req.args, args, sizeof(req.args));

    (void)pfe_log_if_db_lock();

    /*  Ask master driver to add match rules */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_SET_MATCH_RULES, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't set match rules: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Add match rule
 * @param[in]   iface The interface instance
 * @param[in]   rule Rule to be added. See pfe_ct_if_m_rules_t. Function accepts
 *                   only single rule per call.
 * @param[in]   arg Pointer to buffer containing rule argument data. The argument
 *                  data shall be in network byte order. Type of the argument can
 *                  be retrieved from the pfe_ct_if_m_args_t.
 * @param[in]   arg_len Length of the rule argument. Due to sanity check.
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_add_match_rule(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len)
{
    pfe_platform_rpc_pfe_log_if_add_match_rule_arg_t req = {0};
    errno_t ret = EINVAL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (0 == rule)
    {
        return EINVAL;
    }

    /*  Check if only single rule is requested */
    if (0 != (rule & (rule-1)))
    {
        return EINVAL;
    }

    if ((0U != arg_len) && (NULL == arg))
    {
        return EINVAL;
    }

    if (arg_len > sizeof(req.arg))
    {
        return EINVAL;
    }

    req.log_if_id = iface->id;
    req.rule = (pfe_ct_if_m_rules_t)oal_htonl(rule);
    req.arg_len = oal_htonl(arg_len);
    (void)autolibc_memcpy(&req.arg, (uint8_t*)arg, sizeof(req.arg));

    (void)pfe_log_if_db_lock();

    /*  Ask master driver to add the match rule */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_ADD_MATCH_RULE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't add match rule: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Delete match rule(s)
 * @param[in]   iface The interface instance
 * @param[in]   rule Rule or multiple rules to be deleted. See pfe_ct_if_m_rules_t.
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_del_match_rule(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule)
{
    pfe_platform_rpc_pfe_log_if_del_match_rule_arg_t req = {0};
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;
    req.rule = (pfe_ct_if_m_rules_t)oal_htonl(rule);

    (void)pfe_log_if_db_lock();

    /*  Ask master driver to delete the rule(s) */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DEL_MATCH_RULE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't delete match rule(s): %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Get match rules
 * @param[in]   iface The interface instance
 * @param[in]   rules Pointer to location where rules shall be written
 * @param[in]   args Pointer to location where rules arguments shall be written. Can be NULL.
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_get_match_rules(pfe_log_if_t *iface, pfe_ct_if_m_rules_t *rules, pfe_ct_if_m_args_t *args)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_get_match_rules_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_get_match_rules_ret_t rpc_ret = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == rules)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Query master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_GET_MATCH_RULES, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get match rule(s): %d\n", ret);
    }
    else
    {
        *rules = (pfe_ct_if_m_rules_t)oal_ntohl(rpc_ret.rules);
        if (NULL != args)
        {
            (void)autolibc_memcpy(args, &rpc_ret.args, sizeof(pfe_ct_if_m_args_t));
        }
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Add new MAC address
 * @param[in]   iface The interface instance
 * @param[in]   addr The MAC address to add
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_add_mac_addr(pfe_log_if_t *iface, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    pfe_platform_rpc_pfe_log_if_add_mac_addr_arg_t req = {0};
    errno_t ret = EOK;

    ct_assert(sizeof(req.addr) == sizeof(pfe_mac_addr_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    (void)pfe_log_if_db_lock();

    /*  Add address to local database */
    ret = pfe_mac_db_add_addr(&iface->mac_db, addr, owner);
    if(EOK == ret)
    {
        /*  Ask the master driver to add the MAC address */
        req.log_if_id = iface->id;
        (void)autolibc_memcpy(req.addr, addr, sizeof(pfe_mac_addr_t));
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_ADD_MAC_ADDR, &req, (uint16_t)sizeof(req), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("Can't set MAC address: %d\n", ret);

            /*  Remove the address from local database */
            ret = pfe_mac_db_del_addr(&iface->mac_db, addr, owner);
            if(EOK != ret)
            {
                NXP_LOG_WARNING("Unable to remove MAC address from phy_if MAC database: %d\n", ret);
            }
        }
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Delete MAC address
 * @param[in]   iface The interface instance
 * @param[in]   addr The MAC address to delete
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_del_mac_addr(pfe_log_if_t *iface, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    pfe_platform_rpc_pfe_log_if_del_mac_addr_arg_t req = {0};
    errno_t ret = EOK;

    ct_assert(sizeof(req.addr) == sizeof(pfe_mac_addr_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    (void)pfe_log_if_db_lock();

    ret = pfe_mac_db_del_addr(&iface->mac_db, addr, owner);
    if(EOK != ret)
    {
        NXP_LOG_WARNING("Unable to remove MAC address from log_if MAC database: %d\n", ret);
    }
    else
    {
        /*  Ask the master driver to del the MAC address */
        req.log_if_id = iface->id;
        (void)autolibc_memcpy(req.addr, addr, sizeof(pfe_mac_addr_t));
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DEL_MAC_ADDR, &req, (uint16_t)sizeof(req), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("Can't del MAC address: %d\n", ret);

            /* Removal of MAC address by master failed, put it back to DB */
            ret = pfe_mac_db_add_addr(&iface->mac_db, addr, owner);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Unable to put back the MAC address into log_if MAC database: %d\n", ret);
            }
        }
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Get handle of internal MAC database
 * @param[in]   iface The interface instance
 * @retval      Database handle.
 */
pfe_mac_db_t *pfe_log_if_get_mac_db(pfe_log_if_t *iface)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return NULL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return &iface->mac_db;
}

/**
 * @brief       Get associated MAC address
 * @param[in]   iface The interface instance
 * @param[out]  addr Where to copy to address
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOENT No address assigned
 */
errno_t pfe_log_if_get_mac_addr(pfe_log_if_t *iface, pfe_mac_addr_t addr)
{
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == addr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    ret = pfe_mac_db_get_first_addr(&iface->mac_db, MAC_DB_CRIT_ALL, PFE_TYPE_ANY, PFE_CFG_LOCAL_IF, addr);
    if(EOK != ret)
    {
        NXP_LOG_WARNING("unable to get MAC address: %d\n", ret);
    }

    return ret;
}

/**
* @brief        Delete MAC addresses added by owner with defined type
 * @param[in]   iface The interface instance
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner Required owner of MAC address
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_flush_mac_addrs(pfe_log_if_t *iface, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
    pfe_platform_rpc_pfe_log_if_flush_mac_addrs_arg_t req = {0};
    errno_t ret = EOK;
    (void)owner; /* Owner will be added directly to the RPC */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    /*  Pass parameters */
    req.log_if_id = iface->id;
    req.crit = crit;
    req.type = type;

    (void)pfe_log_if_db_lock();

    /*  Request the change */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_FLUSH_MAC_ADDRS, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't flush multicast MAC addresses: %d\n", ret);
    }
    else
    {
        /*  Remove MAC addresses also from local database */
        ret = pfe_mac_db_flush(&iface->mac_db, crit, type, owner);
        if(EOK != ret)
        {
            NXP_LOG_DEBUG("Unable to flush MAC address from phy_if MAC database: %d\n", ret);
        }
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief           Set mask of egress interfaces
 * @param[in]       iface The interface instance
 * @param[in]       egress mask (in host format), constructed like
 *                  egress |= 1 << phy_if_id (for each configured phy_if)
 * @retval          EOK Success
 */
errno_t pfe_log_if_set_egress_ifs(pfe_log_if_t *iface, uint32_t egress)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_set_egress_ifs_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* GLOBAL_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;
    req.phy_if_id_mask = egress;

    (void)pfe_log_if_db_lock();

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_SET_EGRESS_IFS, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't set egress interfaces: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief           Get mask of egress interfaces
 * @param[in]       iface The interface instance
 * @param[in,out]   egress mask (in host format), constructed like
 *                  egress |= 1 << phy_if_id (for each configured phy_if)
 * @retval          EOK Success
 */
errno_t pfe_log_if_get_egress_ifs(pfe_log_if_t *iface, uint32_t *egress)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_get_egress_ifs_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_get_egress_ifs_ret_t rpc_ret = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == egress)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_GET_EGRESS_IFS, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get egress interfaces: %d\n", ret);
    }
    else
    {
        *egress = rpc_ret.egress;
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Add egress physical interface
 * @details     Logical interfaces can be used to classify and route
 *              packets. When ingress packet is not classified using any
 *              other classification mechanism (L3 router, L2 bridge, ...)
 *              then matching ingress logical interface is considered
 *              to provide list of physical interfaces the packet shall be
 *              forwarded to. This function provides way to add physical
 *              interface into the list.
 * @param[in]   iface The interface instance
 * @param[in]   phy_if The physical interface to be added to the list of
 *                     egress interfaces.
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_add_egress_if(pfe_log_if_t *iface, const pfe_phy_if_t *phy_if)
{
    pfe_platform_rpc_pfe_log_if_add_egress_if_arg_t req = {0};
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == phy_if)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;
    req.phy_if_id = pfe_phy_if_get_id(phy_if);

    (void)pfe_log_if_db_lock();

    /*  Ask the master driver to add new egress interface */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_ADD_EGRESS_IF, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't add egress interface: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Remove egress physical interface
 * @details     See the pfe_log_if_add_egress_if().
 * @param[in]   iface The interface instance
 * @param[in]   phy_if The physical interface to be removed
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_del_egress_if(pfe_log_if_t *iface, const pfe_phy_if_t *phy_if)
{
    pfe_platform_rpc_pfe_log_if_del_egress_if_arg_t req = {0};
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == phy_if)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;
    req.phy_if_id = pfe_phy_if_get_id(phy_if);

    (void)pfe_log_if_db_lock();

    /*  Ask the master driver to remove egress interface */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DEL_EGRESS_IF, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't delete egress interface: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Enable the interface
 * @details     Only enabled logical interfaces will be used by firmware
 *              to match ingress frames.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_enable(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_enable_arg_t req = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Enable the interface */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_ENABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't enable interface: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Disable the interface
 * @details     Only enabled logical interfaces will be used by firmware
 *              to match ingress frames.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_disable(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_disable_arg_t req = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Enable the interface */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DISABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't disable interface: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Check if interface is enabled
 * @param[in]   iface The interface instance
 * @return      TRUE if enabled, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_log_if_is_enabled(const pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_is_enabled_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_is_enabled_ret_t rpc_ret = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return FALSE;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Query the master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_IS_ENABLED, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));

    (void)pfe_log_if_db_unlock();

    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get interface enable status: %d\n", ret);
        return FALSE;
    }
    else
    {
        return rpc_ret.status;
    }
}

/**
 * @brief       Enable promiscuous mode
 * @details     Function sets logical interface to promiscuous mode and
 *              also enables promiscuous mode on underlying physical
 *              interface.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_promisc_enable(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_promisc_enable_arg_t req = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Enable promiscuous mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_PROMISC_ENABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't enable promiscuous mode: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Disable promiscuous mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_promisc_disable(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_promisc_disable_arg_t req = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Enable promiscuous mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_PROMISC_DISABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't disable promiscuous mode: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Check if interface is in promiscuous mode
 * @param[in]   iface The interface instance
 * @return      TRUE if promiscuous mode is enabled, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_log_if_is_promisc(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_is_promisc_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_is_promisc_ret_t rpc_ret = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return FALSE;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Query the master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_IS_PROMISC, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));

    (void)pfe_log_if_db_unlock();

    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get promiscuous status: %d\n", ret);
        return FALSE;
    }
    else
    {
        return rpc_ret.status;
    }
}

/**
 * @brief               Check if interface is in loopback mode
 * @param[in]   iface The interface instance
 * @return              TRUE if loopback mode is enabled, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_log_if_is_loopback(const pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_is_loopback_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_is_loopback_ret_t rpc_ret = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return FALSE;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Query the master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_IS_LOOPBACK, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));

    (void)pfe_log_if_db_unlock();

    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get loopback status: %d\n", ret);
        return FALSE;
    }
    else
    {
        return rpc_ret.status;
    }
}

/**
 * @brief       Enable loopback mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_loopback_enable(pfe_log_if_t *iface)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_loopback_enable_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /* Enable loopback mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_LOOPBACK_ENABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't enable loopback mode: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Disable loopback mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_loopback_disable(pfe_log_if_t *iface)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_loopback_disable_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Disable loopback mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_LOOPBACK_DISABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't disable loopback mode: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Check if interface is configured to discard accepted frames
 * @param[in]   iface The interface instance
 * @return      TRUE if discarding is enabled, FALSE otherwise
 */
bool_t pfe_log_if_is_discard(pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_is_discard_arg_t req = {0};
    pfe_platform_rpc_pfe_log_if_is_discard_ret_t rpc_ret = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return FALSE;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Query the master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_IS_DISCARD, &req, (uint16_t)sizeof(req), &rpc_ret, (uint16_t)sizeof(rpc_ret));

    (void)pfe_log_if_db_unlock();

    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get discard status: %d\n", ret);
        return FALSE;
    }
    else
    {
        return rpc_ret.status;
    }
}

/**
 * @brief       Disable discarding frames accepted by logical interface
 * @details     Function configures logical interface to stop to discard all accepted frames
 *              and to pass them to the configured egress interfaces.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_discard_enable(pfe_log_if_t *iface)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_discard_enable_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /* Enable loopback mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DISCARD_ENABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't enable discard: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Enable discarding frames accepted by logical interface
 * @details     Function configures logical interface to discard all accepted frames instead of
 *              passing them to the configured egress interfaces.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_discard_disable(pfe_log_if_t *iface)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_discard_disable_arg_t req = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /* Enable loopback mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_DISCARD_DISABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't disable discard: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Enable ALLMULTI mode
 * @details     Function sets logical interface to ALLMULTI mode and
 *              also enables ALLMULTI mode on underlying physical
 *              interface.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_allmulti_enable(const pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_allmulti_enable_arg_t req = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        req.log_if_id = iface->id;

        (void)pfe_log_if_db_lock();

        /*  Enable allmulti mode */
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_ALLMULTI_ENABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("Can't enable allmulti mode: %d\n", ret);
        }

        (void)pfe_log_if_db_unlock();
    }
    return ret;
}

/**
 * @brief       Disable ALLMULTI mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_allmulti_disable(const pfe_log_if_t *iface)
{
    pfe_platform_rpc_pfe_log_if_allmulti_disable_arg_t req = {0};
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    req.log_if_id = iface->id;

    (void)pfe_log_if_db_lock();

    /*  Disable allmulti mode */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_ALLMULTI_DISABLE, &req, (uint16_t)sizeof(req), NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't disable allmulti mode: %d\n", ret);
    }

    (void)pfe_log_if_db_unlock();

    return ret;
}

/**
 * @brief       Get interface name
 * @param[in]   iface The interface instance
 * @return      Pointer to name string or "(unknown)" when called with NULL_PTR
 */
__attribute__((pure)) const char_t *pfe_log_if_get_name(const pfe_log_if_t *iface)
{
    const char_t *str;

    if (NULL_PTR != iface)
    {
        str = iface->name;
    }
    else
    {
        NXP_LOG_WARNING("NULL argument received for pfe_log_if_get_name\n");
        str = "(unknown)";
    }

    return str;
}

/**
 * @brief       Get log interface statistics
 * @param[in]   iface The interface instance
 * @param[out]  stat Statistic structure
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOMEM Not possible to allocate memory for read
 */
errno_t pfe_log_if_get_stats(const pfe_log_if_t *iface, pfe_ct_class_algo_stats_t *stat)
{
    errno_t ret = EOK;
    pfe_platform_rpc_pfe_log_if_stats_arg_t arg = {0};
    pfe_platform_rpc_pfe_log_if_stats_ret_t rpc_ret = {0};


#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    arg.log_if_id = iface->id;
    (void)pfe_log_if_db_lock();

    /*  Query the master driver */
    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_LOG_IF_STATS, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Can't get interface enable status: %d\n", ret);
    }
    else
    {
        (void)autolibc_memcpy(stat, &rpc_ret.stats, sizeof(rpc_ret.stats));
    }
    (void)pfe_log_if_db_unlock();

    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return logical interface runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   iface       The logical interface instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   size        Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_log_if_get_text_statistics(const pfe_log_if_t *iface, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return 0U;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */
    /*  Ask the master driver if interface is in promiscuous mode */
    NXP_LOG_WARNING("%s: Not supported yet\n", __func__);
    len += oal_util_snprintf(buf + len, buf_len - len, "%s: Unable to get statistics (not implemented)\n", __func__);

    (void)iface;
    (void)verb_level;

    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_PFE_SLAVE */
