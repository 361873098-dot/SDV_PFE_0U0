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
 *  Copyright 2018-2024 NXP
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

#ifndef PFE_CFG_PFE_SLAVE
#include "hal.h"
#include "pfe_cbus.h"
#include "pfe_ct.h"
#include "pfe_log_if.h"
#include "pfe_class.h"
#include "pfe_platform_cfg.h"
#include "isa.h"

struct pfe_log_if_tag
{
    pfe_phy_if_t *parent;                       /*!< Parent physical interface */
    pfe_class_t *class;                         /*!< Classifier */
    addr_t dmem_base;                           /*!< Place in CLASS/DMEM where HW logical interface structure is stored */
    char_t name[PFE_CFG_LOG_IF_NAME_LENGTH_MAX];/*!< Interface name */
    pfe_ct_log_if_t log_if_class;               /*!< Cached copy of the DMEM structure */
    pfe_ct_phy_if_id_t owner;
    LLIST_t phy_if_binding;                     /*!< binding to physical interface */
};

#define ETH_43_PFE_START_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"

/* logical interfaces pool initialization state */
static bool_t pfe_log_ifs_initialized = FALSE;

#define ETH_43_PFE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_ct_class_algo_stats_t pfe_class_algo_stats[PFE_CLASS_PE_COUNT];
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

static errno_t pfe_log_if_write_to_class_nostats(const pfe_log_if_t *iface, const pfe_ct_log_if_t *class_if);
static errno_t pfe_log_if_write_to_class(const pfe_log_if_t *iface, const pfe_ct_log_if_t *class_if);
static errno_t pfe_log_if_match_rule1(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len);
static errno_t pfe_log_if_match_rule2(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len);
static errno_t pfe_log_if_match_rule3(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len);
static errno_t pfe_log_if_match_rule4(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len);
static errno_t pfe_log_if_add_match_rule_validate_arg(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len);
static uint32_t pfe_log_if_strnlen(const char_t *str, uint32_t strsz);
static pfe_log_if_t* pfe_log_ifs_init_db(pfe_phy_if_t *parent, const char_t *name, pfe_log_if_t  *iface);

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

/**
 * @brief           Add match rule
 * @param[in, out]  iface The interface instance
 * @param[in]       rule Rule to be added. See pfe_ct_if_m_rules_t. Function accepts
 *                       only single rule per call.
 * @param[in]       arg Pointer to buffer containing rule argument data. The argument
 *                      data shall be in network byte order. Type of the argument can
 *                      be retrieved from the pfe_ct_if_m_args_t.
 * @param[in]       arg_len Length of the rule argument. Due to sanity check.
 * @retval          EOK Success
 * @retval          EINVAL Invalid or missing argument
 */
static errno_t pfe_log_if_match_rule1(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len)
{
    errno_t ret = EINVAL;
    pfe_ct_if_m_args_t m_args;

    switch (rule)
    {
        case IF_MATCH_VLAN:
        {
            if (arg_len == sizeof(m_args.vlan))
            {
                iface->log_if_class.m_args.vlan = *((const uint16_t *)arg);
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_PROTO:
        {
            if (arg_len == sizeof(m_args.proto))
            {
                iface->log_if_class.m_args.proto = *((uint8_t *)arg);
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_SPORT:
        {
            if (arg_len == sizeof(m_args.sport))
            {
                iface->log_if_class.m_args.sport = *((uint16_t *)arg);
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_DPORT:
        {
            if (arg_len == sizeof(m_args.dport))
            {
                iface->log_if_class.m_args.dport = *((uint16_t *)arg);
                ret = EOK;
            }

            break;
        }
        default:
        {
            /* Required by Misra */
            break;
        }
    }

    return ret;
}

/**
 * @brief           Add match rule
 * @param[in, out]  iface The interface instance
 * @param[in]       rule Rule to be added. See pfe_ct_if_m_rules_t. Function accepts
 *                       only single rule per call.
 * @param[in]       arg Pointer to buffer containing rule argument data. The argument
 *                      data shall be in network byte order. Type of the argument can
 *                      be retrieved from the pfe_ct_if_m_args_t.
 * @param[in]       arg_len Length of the rule argument. Due to sanity check.
 * @retval          EOK Success
 * @retval          EINVAL Invalid or missing argument
 */
static errno_t pfe_log_if_match_rule3(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len)
{
    errno_t ret = EINVAL;
    pfe_ct_if_m_args_t m_args;

    switch (rule)
    {
        case IF_MATCH_ETHTYPE:
        {
            if (arg_len == sizeof(m_args.ethtype))
            {
                iface->log_if_class.m_args.ethtype = *((const uint16_t *)arg);
                ret = EOK;
            }

            break;
        }
        case IF_MATCH_FP0:
        {
            if (arg_len == sizeof(m_args.fp0_table))
            {
                iface->log_if_class.m_args.fp0_table = *((PFE_PTR(pfe_ct_fp_table_t) *)arg);
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_FP1:
        {
            if (arg_len == sizeof(m_args.fp1_table))
            {
                iface->log_if_class.m_args.fp1_table = *((PFE_PTR(pfe_ct_fp_table_t) *)arg);
                ret = EOK;
            }

            break;
        }
        default:
        {
            /* Required by Misra */
            break;
        }
    }

    return ret;
}

/**
 * @brief           Add match rule
 * @param[in, out]  iface The interface instance
 * @param[in]       rule Rule to be added. See pfe_ct_if_m_rules_t. Function accepts
 *                       only single rule per call.
 * @param[in]       arg Pointer to buffer containing rule argument data. The argument
 *                      data shall be in network byte order. Type of the argument can
 *                      be retrieved from the pfe_ct_if_m_args_t.
 * @param[in]       arg_len Length of the rule argument. Due to sanity check.
 * @retval          EOK Success
 * @retval          EINVAL Invalid or missing argument
 */
static errno_t pfe_log_if_match_rule4(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len)
{
    errno_t ret = EINVAL;
    pfe_ct_if_m_args_t m_args;

    switch (rule)
    {
        case IF_MATCH_SMAC:
        {
            if (arg_len == sizeof(m_args.smac))
            {
                (void)autolibc_memcpy((void*)(iface->log_if_class.m_args.smac), (const void*)arg, sizeof(m_args.smac));
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_DMAC:
        {
            if (arg_len == sizeof(m_args.dmac))
            {
                (void)autolibc_memcpy((void*)(iface->log_if_class.m_args.dmac), (const void*)arg, sizeof(m_args.dmac));
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_HIF_COOKIE:
        {
            if (arg_len == sizeof(m_args.hif_cookie))
            {
                iface->log_if_class.m_args.hif_cookie = *((const uint32_t*)arg);
                ret = EOK;
            }

            break;
        }

        default:
        {
            /* Required by Misra */
            break;
        }
    }

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
static errno_t pfe_log_if_match_rule2(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len)
{
    errno_t ret = EINVAL;
    pfe_ct_if_m_args_t m_args;

    switch (rule)
    {
        case IF_MATCH_SIP6:
        {
            if (arg_len == sizeof(m_args.ipv.v6.sip))
            {
                (void)autolibc_memcpy((void*)(iface->log_if_class.m_args.ipv.v6.sip), (const void*)arg, sizeof(m_args.ipv.v6.sip));
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_DIP6:
        {
            if (arg_len == sizeof(m_args.ipv.v6.dip))
            {
                (void)autolibc_memcpy((void*)(iface->log_if_class.m_args.ipv.v6.dip), (const void*)arg, sizeof(m_args.ipv.v6.dip));
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_SIP:
        {
            if (arg_len == sizeof(m_args.ipv.v4.sip))
            {
                (void)autolibc_memcpy((void*)(&iface->log_if_class.m_args.ipv.v4.sip), (const void*)arg, sizeof(m_args.ipv.v4.sip));
                ret = EOK;
            }

            break;
        }

        case IF_MATCH_DIP:
        {
            if (arg_len == sizeof(m_args.ipv.v4.dip))
            {
                (void)autolibc_memcpy((void*)(&iface->log_if_class.m_args.ipv.v4.dip), (const void*)arg, sizeof(m_args.ipv.v4.dip));
                ret = EOK;
            }

            break;
        }

        default:
        {
            /* Required by Misra */
            break;
        }
    }

    return ret;
}

/**
 * @brief       Write interface structure to classifier memory skipping interface statistics
 * @param[in]   iface The interface instance
 * @param[in]   class_if Pointer to the structure to be written
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
static errno_t pfe_log_if_write_to_class_nostats(const pfe_log_if_t *iface, const pfe_ct_log_if_t *class_if)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class_if) || (NULL == iface) || (0U == iface->dmem_base)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Be sure that class_stats are at correct place */
        ct_assert_offsetof((sizeof(pfe_ct_log_if_t) - sizeof(pfe_ct_class_algo_stats_t)) == offsetof(pfe_ct_log_if_t, class_stats));
        ret = pfe_class_write_dmem(iface->class, -1, iface->dmem_base, (const  void *)class_if,
                                sizeof(pfe_ct_log_if_t) - sizeof(pfe_ct_class_algo_stats_t));
    }

    return ret;
}

/**
 * @brief       Write interface structure to classifier with statistics
 * @param[in]   iface The interface instance
 * @param[in]   class_if Pointer to the structure to be written
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
static errno_t pfe_log_if_write_to_class(const pfe_log_if_t *iface, const pfe_ct_log_if_t *class_if)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class_if) || (NULL == iface) || (0U == iface->dmem_base)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_class_write_dmem(iface->class, -1, iface->dmem_base, (const  void *)class_if, sizeof(pfe_ct_log_if_t));
    }
    return ret;
}

/**
 * @brief       Get linked list entry used for binding with PHY IF
 * @param[in]   iface The interface instance
 * @retval      NULL for invalid iface
 * @retval      Pointer to linked list entry used for binding with PHY IF
 * @note        For internal use only !
 */
LLIST_t *pfe_log_if_get_phy_if_binding_list_entry(const pfe_log_if_t *iface)
{
    LLIST_t *entry;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        entry = NULL_PTR;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
      entry = (LLIST_t *)&iface->phy_if_binding;
    }

    return entry;
}

/**
 * @brief     Obtain LOG IF from PHY IF binding linked list entry
 * @param[in] entry PHY IF list linked list entry
 * @retval    NULL for invalid entry
 * @retval    Pointer to LOF IF associated with supplied linked list entry
 */
pfe_log_if_t *pfe_log_if_from_phy_if_binding_list_entry(const LLIST_t *entry)
{
    pfe_log_if_t *log_if;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        log_if = NULL_PTR;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
      log_if = LLIST_Data(entry, pfe_log_if_t, phy_if_binding);
    }

    return log_if;
}

/**
 * @brief Initialise necessary storages and variables for all logical interfaces
 */
errno_t pfe_log_ifs_init(void)
{
  errno_t ret = EOK;

  if (FALSE == pfe_log_ifs_initialized)
  {
      /* Initialise LOG IFs ISA storage */
      isa_init(&pfe_log_ifs, &pfe_log_ifs_isa_def);
      pfe_log_ifs_initialized = TRUE;

      NXP_LOG_DEBUG("Pool configured to support %d logical interfaces\n", PFE_CFG_MAX_LOG_IFS);
  }
  else
  {
      NXP_LOG_WARNING("pfe_log_ifs_init() already called\n");
  }

  return ret;
}

/**
 * @brief Uninitialise necessary storages and variables for all logical interfaces
 */
void pfe_log_ifs_deinit(void)
{
    if (TRUE == pfe_log_ifs_initialized)
    {
        /* Invalidate LOG IFs ISA storage */
        (void)autolibc_memset(&pfe_log_ifs, 0, sizeof(pfe_log_ifs));
        pfe_log_ifs_initialized = FALSE;
    }
}

/**
 * @brief       Initialize new logical interface instance
 * @param[in]   parent The parent physical interface
 * @param[in]   name Name of the interface
 * @param[in]   iface instance of the log_if interface
 * @return      iface instance or NULL_PTR in case of failure
 */
static pfe_log_if_t* pfe_log_ifs_init_db(pfe_phy_if_t *parent, const char_t *name, pfe_log_if_t  *iface)
{
    (void)autolibc_strncpy(iface->name, name, sizeof(iface->name));

    /* Get the DMEM for logical interface */
    iface->dmem_base = pfe_class_dmem_heap_alloc(iface->class, sizeof(pfe_ct_log_if_t));
    if(0U == iface->dmem_base)
    {
        NXP_LOG_ERROR("No DMEM\n");
        (void)isa_release(&pfe_log_ifs, iface);
        iface = NULL_PTR;
    }
    else
    {
        /*  Initialize the local and CLASS logical interface structure */
        (void)autolibc_memset(&iface->log_if_class, 0, sizeof(pfe_ct_log_if_t));
        iface->log_if_class.next = 0;
        iface->log_if_class.id = (uint8_t)(iface - pfe_log_ifs_pool);
        iface->log_if_class.m_rules = (pfe_ct_if_m_rules_t)IF_MATCH_NONE;

        /* Be sure that statistics are zeroed (endianness doesn't mater for this) */
        iface->log_if_class.class_stats.accepted  = 0;
        iface->log_if_class.class_stats.rejected  = 0;
        iface->log_if_class.class_stats.discarded = 0;
        iface->log_if_class.class_stats.processed = 0;

        /* Write to class with stats (overriding the statistics with 0) */
        if (EOK != pfe_log_if_write_to_class(iface, &iface->log_if_class))
        {
            NXP_LOG_ERROR("Could not update DMEM (%s)\n", iface->name);
            pfe_class_dmem_heap_free(iface->class, iface->dmem_base);
            (void)isa_release(&pfe_log_ifs, iface);
            iface = NULL_PTR;
        }
        else
        {
            /*  Bind logical IF with physical IF */
            if (EOK != pfe_phy_if_add_log_if(parent, iface))
            {
                NXP_LOG_ERROR("Can't bind %s to %s\n", iface->name, pfe_phy_if_get_name(parent));
                pfe_class_dmem_heap_free(iface->class, iface->dmem_base);
                (void)isa_release(&pfe_log_ifs, iface);
                iface = NULL_PTR;
            }
        }
    }

    return iface;
}

/**
 * @brief       Create new logical interface instance
 * @param[in]   parent The parent physical interface
 * @param[in]   name Name of the interface
 * @return      The interface instance or NULL if failed
 */
pfe_log_if_t *pfe_log_if_create(pfe_phy_if_t *parent, const char_t *name)
{
    pfe_log_if_t  *iface;
    uint32_t      length;

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
        /* check if ISA storage is initialized */
        else if (TRUE == pfe_log_ifs_initialized)
        {
            iface = (pfe_log_if_t *)isa_reserve(&pfe_log_ifs);
            if (NULL_PTR == iface)
            {
                NXP_LOG_ERROR("Could not reserve ISA item for LOG IF\n");
            }
            else
            {
                (void)autolibc_memset(iface, 0, sizeof(*iface));
                iface->parent = parent;
                iface->class = pfe_phy_if_get_class(parent);
                iface = pfe_log_ifs_init_db(parent, name, iface);
            }
        }
        else
        {
            NXP_LOG_ERROR("LOG IF ISA pool not initialized\n");
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
    uint8_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = 0xffU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = iface->log_if_class.id;
    }

    return ret;
}

/**
 * @brief       Get parent physical interface
 * @param[in]   iface The interface instance
 * @return      Physical interface instance or NULL if failed
 */
__attribute__((pure)) pfe_phy_if_t *pfe_log_if_get_parent(const pfe_log_if_t *iface)
{
    pfe_phy_if_t *ptr;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ptr = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ptr = iface->parent;
    }
    return ptr;
}

/**
 * @brief       Set 'next' pointer of the logical interface
 * @details     The value is used to form a simple linked list of logical interface structures
 *              within the classifier memory. Classifier can then walk through the list with
 *              every packet, try to find a matching logical interface, and perform subsequent
 *              actions (for instance distribute the packet to the right destination given by
 *              the logical interface configuration). Note that last entry in the list shall
 *              have the 'next' value set to zero.
 * @param[in]   iface The interface instance
 * @param[in]   next_dmem_ptr Addr in DMEM where next logical interface is stored (lined list entry)
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_set_next_dmem_ptr(pfe_log_if_t *iface, addr_t next_dmem_ptr)
{
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
        ret = EOK;
        iface->log_if_class.next = oal_htonl((uint32_t)next_dmem_ptr);
        if (EOK != pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class))
        {
            NXP_LOG_ERROR("Interface update failed\n");
            ret = ENOEXEC;
        }
    }

    return ret;
}

/**
 * @brief       Get 'next' pointer of the logical interface (DMEM)
 * @param[in]   iface The interface instance
 * @param[in]   next_dmem_ptr Pointer where the value shall be stored
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_log_if_get_next_dmem_ptr(pfe_log_if_t *iface, addr_t *next_dmem_ptr)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == next_dmem_ptr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *next_dmem_ptr = oal_ntohl(iface->log_if_class.next);
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Get pointer to logical interface within DMEM
 * @param[in]   iface The interface instance (HOST)
 * @param[in]   dmem_base Pointer where the interface instance (DMEM) pointer will be written
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_get_dmem_base(const pfe_log_if_t *iface, addr_t *dmem_base)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == dmem_base)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *dmem_base = iface->dmem_base;
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Destroy interface instance
 * @param[in]   iface The interface instance
 */
void pfe_log_if_destroy(pfe_log_if_t *iface)
{
    errno_t ret;

    if (NULL_PTR != iface)
    {
        ret = pfe_phy_if_del_log_if(iface->parent, iface);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Could not remove %s from parent instance: %d\n", iface->name, ret);
        }

        iface->name[0] = '\0';

        (void)autolibc_memset(&iface->log_if_class, 0, sizeof(pfe_ct_log_if_t));
        if (EOK != pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class))
        {
            NXP_LOG_ERROR("Iface invalidation failed\n");
        }

        if (NULL_ADDR != iface->dmem_base)
        {
            pfe_class_dmem_heap_free(iface->class, iface->dmem_base);
        }

        (void)isa_release(&pfe_log_ifs, iface);
    }
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
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = ((uint32_t)IF_FL_MATCH_OR ==
                ((uint32_t)(oal_ntohl(iface->log_if_class.flags)) & (uint32_t)IF_FL_MATCH_OR));
    }

    return ret;
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
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_00);
        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags |= oal_htonl(IF_FL_MATCH_OR);

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }
        oal_mutex_unlock(PFE_LOG_IF_MUTEX_00);
    }

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
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_01);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags &= oal_htonl(~(uint32_t)IF_FL_MATCH_OR);

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_01);
    }

    return ret;
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
    errno_t ret;
    pfe_ct_if_m_rules_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (NULL == args)
        {
            /*  Argument is mandatory */
            ret = EINVAL;
        }
        else
        {
            oal_mutex_lock(PFE_LOG_IF_MUTEX_02);

            /*  Copy the argument */
            (void)autolibc_memcpy(&iface->log_if_class.m_args, args, sizeof(pfe_ct_if_m_args_t));

            /*  Backup current rules to temporary variable */
            tmp = iface->log_if_class.m_rules;
            iface->log_if_class.m_rules = (pfe_ct_if_m_rules_t)oal_htonl(rules);
            ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
            if (EOK != ret)
            {
                /*  Revert */
                iface->log_if_class.m_rules = tmp;
            }

            oal_mutex_unlock(PFE_LOG_IF_MUTEX_02);
        }
    }

    return ret;
}

/**
 * @brief       Validate and copy argument
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
static errno_t pfe_log_if_add_match_rule_validate_arg(pfe_log_if_t *iface, pfe_ct_if_m_rules_t rule, const void *arg, uint32_t arg_len)
{
    errno_t ret;

    ret = pfe_log_if_match_rule1(iface, rule, arg, arg_len);
    if (EINVAL == ret)
    {
        ret = pfe_log_if_match_rule2(iface, rule, arg, arg_len);
        if (EINVAL == ret)
        {
            ret = pfe_log_if_match_rule3(iface, rule, arg, arg_len);
            if (EINVAL == ret)
            {
                ret = pfe_log_if_match_rule4(iface, rule, arg, arg_len);
                if (EINVAL == ret)
                {
                    if (arg_len != 0U)
                    {
                        NXP_LOG_DEBUG("Unexpected argument\n");
                    }
                    else
                    {
                        ret = EOK;
                    }
                }
            }
        }
    }

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
    errno_t ret;
    pfe_ct_if_m_rules_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (0U == (uint32_t)rule)
        {
            ret = EINVAL;
        }

        /*  Check if only single rule is requested */
        else if (0U != ((uint32_t)rule & ((uint32_t)rule-1U)))
        {
            ret = EINVAL;
        }
        else
        {
            oal_mutex_lock(PFE_LOG_IF_MUTEX_03);

            ret = pfe_log_if_add_match_rule_validate_arg(iface, rule, arg, arg_len);

            if (EOK != ret)
            {
                NXP_LOG_DEBUG("Invalid matching rule argument\n");
            }
            else
            {
                tmp = iface->log_if_class.m_rules;
                iface->log_if_class.m_rules |= (pfe_ct_if_m_rules_t)oal_htonl(rule);
                ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
                if (EOK != ret)
                {
                    /*  Revert */
                    iface->log_if_class.m_rules = tmp;
                }
            }

            oal_mutex_unlock(PFE_LOG_IF_MUTEX_03);
        }
    }

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
    errno_t ret;
    pfe_ct_if_m_rules_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_04);

        tmp = iface->log_if_class.m_rules;
        iface->log_if_class.m_rules &= (pfe_ct_if_m_rules_t)oal_htonl(~rule);
        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.m_rules = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_04);
    }

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
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == rules)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *rules = (pfe_ct_if_m_rules_t)oal_ntohl(iface->log_if_class.m_rules);

        if (NULL != args)
        {
            (void)autolibc_memcpy(args, &iface->log_if_class.m_args, sizeof(pfe_ct_if_m_args_t));
        }
        ret = EOK;
    }

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
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == egress)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *egress = (uint32_t)oal_ntohl(iface->log_if_class.e_phy_ifs);
        ret = EOK;
    }

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
    uint32_t tmp;
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
        tmp = oal_ntohl(iface->log_if_class.e_phy_ifs);

        iface->log_if_class.e_phy_ifs = oal_htonl(egress);
        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.e_phy_ifs = oal_htonl(tmp);
        }
    }

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
    errno_t ret;
    uint32_t tmp;
    pfe_ct_phy_if_id_t phy_if_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == phy_if)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        phy_if_id = pfe_phy_if_get_id(phy_if);
        if (PFE_PHY_IF_ID_INVALID <= phy_if_id)
        {
            NXP_LOG_ERROR("Invalid PHY IF ID\n");
            ret = EINVAL;
        }
        else
        {
            tmp = oal_ntohl(iface->log_if_class.e_phy_ifs);

            iface->log_if_class.e_phy_ifs = oal_htonl(tmp | (1UL << (uint8_t)phy_if_id));
            ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
            if (EOK != ret)
            {
                /*  Revert */
                iface->log_if_class.e_phy_ifs = oal_htonl(tmp);
            }
        }
    }

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
    errno_t ret;
    uint32_t tmp;
    pfe_ct_phy_if_id_t phy_if_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == phy_if)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        phy_if_id = pfe_phy_if_get_id(phy_if);
        if (PFE_PHY_IF_ID_INVALID <= phy_if_id)
        {
            NXP_LOG_ERROR("Invalid PHY IF ID\n");
            ret = EINVAL;
        }
        else
        {
            tmp = oal_ntohl(iface->log_if_class.e_phy_ifs);

            iface->log_if_class.e_phy_ifs = oal_htonl(tmp & (uint32_t)(~(1UL << (uint8_t)phy_if_id)));
            ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
            if (EOK != ret)
            {
                /*  Revert */
                iface->log_if_class.e_phy_ifs = oal_htonl(tmp);
            }
        }
    }

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
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_05);

        NXP_LOG_DEBUG("Enabling %s\n", iface->name);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags = (pfe_ct_if_flags_t)((uint32_t)tmp | oal_htonl(IF_FL_ENABLED));

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_05);
    }

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
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_06);

        NXP_LOG_DEBUG("Disabling %s\n", iface->name);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags = (pfe_ct_if_flags_t)((uint32_t)tmp & (oal_htonl(~(uint32_t)IF_FL_ENABLED)));

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_06);

    }

    return ret;
}

/**
 * @brief       Check if interface is enabled
 * @param[in]   iface The interface instance
 * @return      TRUE if enabled, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_log_if_is_enabled(const pfe_log_if_t *iface)
{
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = (0U != ((uint32_t)(oal_ntohl(iface->log_if_class.flags)) & (uint32_t)IF_FL_ENABLED));
    }

    return ret;
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
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_09);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags |= oal_htonl(IF_FL_PROMISC);

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_09);
    }

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
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_10);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags = (pfe_ct_if_flags_t)((uint32_t)tmp & (oal_htonl(~(uint32_t)IF_FL_PROMISC)));

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_10);
    }

    return ret;
}

/**
 * @brief       Check if interface is in promiscuous mode
 * @param[in]   iface The interface instance
 * @return      TRUE if promiscuous mode is enabled, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_log_if_is_promisc(pfe_log_if_t *iface)
{
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = (0U != ((uint32_t)(oal_ntohl(iface->log_if_class.flags)) & (uint32_t)IF_FL_PROMISC));
    }

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
errno_t pfe_log_if_discard_enable(pfe_log_if_t *iface)
{
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_11);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags = (pfe_ct_if_flags_t)((uint32_t)tmp | oal_htonl(IF_FL_DISCARD));

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_11);
    }

    return ret;
}

/**
 * @brief       Disable discarding frames accepted by logical interface
 * @details     Function configures logical interface to stop to discard all accepted frames
 *              and to pass them to the configured egress interfaces.
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_log_if_discard_disable(pfe_log_if_t *iface)
{
    errno_t ret;
    pfe_ct_if_flags_t tmp;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_LOG_IF_MUTEX_12);

        tmp = iface->log_if_class.flags;
        iface->log_if_class.flags = (pfe_ct_if_flags_t)((uint32_t)tmp & oal_htonl(~(uint32_t)IF_FL_DISCARD));

        ret = pfe_log_if_write_to_class_nostats(iface, &iface->log_if_class);
        if (EOK != ret)
        {
            /*  Revert */
            iface->log_if_class.flags = tmp;
        }

        oal_mutex_unlock(PFE_LOG_IF_MUTEX_12);
    }

    return ret;
}

/**
 * @brief       Check if interface is configured to discard accepted frames
 * @param[in]   iface The interface instance
 * @return      TRUE if discarding is enabled, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_log_if_is_discard(pfe_log_if_t *iface)
{
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = (0U != ((uint32_t)(oal_ntohl(iface->log_if_class.flags)) & (uint32_t)IF_FL_DISCARD));
    }

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
 * @retval      NOMEM Not possible to allocate memory for read
 */
errno_t pfe_log_if_get_stats(const pfe_log_if_t *iface, pfe_ct_class_algo_stats_t *stat)
{
    uint32_t i;
    uint32_t u32reVal;
    errno_t ret;
    addr_t offset = 0;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == stat)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)autolibc_memset(stat, 0, sizeof(pfe_ct_class_algo_stats_t));

        /* Store offset to stats */
        offset = offsetof(pfe_ct_log_if_t, class_stats);

        /* Gather memory from all PEs*/
        ret = pfe_class_gather_read_dmem(iface->class, &pfe_class_algo_stats, ADDR_BASE_OFFSET(iface->dmem_base, offset), sizeof(pfe_class_algo_stats), sizeof(pfe_ct_class_algo_stats_t));

        /* Calculate total statistics */
        u32reVal = pfe_class_get_num_of_pes(iface->class);
        for(i = 0U; i < u32reVal; i++)
        {
            /* Store statistics */
            stat->accepted = stat->accepted + oal_ntohl(pfe_class_algo_stats[i].accepted);
            stat->discarded = stat->discarded + oal_ntohl(pfe_class_algo_stats[i].discarded);
            stat->processed = stat->processed + oal_ntohl(pfe_class_algo_stats[i].processed);
            stat->rejected = stat->rejected + oal_ntohl(pfe_class_algo_stats[i].rejected);
        }

        /* Convert statistics back to network endian */
        stat->accepted  = oal_htonl(stat->accepted);
        stat->discarded = oal_htonl(stat->discarded);
        stat->processed = oal_htonl(stat->processed);
        stat->rejected  = oal_htonl(stat->rejected);
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* ! PFE_CFG_PFE_SLAVE */
