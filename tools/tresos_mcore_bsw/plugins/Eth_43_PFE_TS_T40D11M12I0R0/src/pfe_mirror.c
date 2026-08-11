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
#define PFE_SRC_VERSION_CHECK 43120440

#include "fpp.h"
#include "oal.h"
#include "hal.h"
#include "pfe_class.h"
#include "pfe_mirror.h"
#include "fpp_ext.h"
#if PFE_CFG_MIRRORS_MAX > 0
#include "isa.h"
#endif /* PFE_CFG_MIRRORS_MAX */

struct pfe_mirror_tag
{
    char name[MIRROR_NAME_SIZE];  /* String identifier */
    addr_t phys_addr;             /* Address of the DMEM representation */
    pfe_ct_mirror_t phys;         /* Physical representation */
};

typedef struct
{
    pfe_class_t *class;
#if PFE_CFG_MIRRORS_MAX > 0
    uint32_t next_item;
    pfe_isa_t mirrors;
    pfe_mirror_t mirrors_pool[PFE_CFG_MIRRORS_MAX];
    pfe_isa_index_t mirrors_index[PFE_CFG_MIRRORS_MAX];
#endif /* PFE_CFG_MIRRORS_MAX */

} pfe_mirror_db_t;

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_mirror_db_t pfe_mirror_db;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#if PFE_CFG_MIRRORS_MAX > 0
#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/* HIF TX headers storage ISA properties definition */
static const pfe_isa_definition_t pfe_mirror_db_isa_def =
{
    .item_count = PFE_CFG_MIRRORS_MAX,
    .item_size = sizeof(pfe_mirror_t),
    .flags = { .ordered = ISA_FLAG_ANY_ORDER },
    .item_indexes = pfe_mirror_db.mirrors_index,
    .items = pfe_mirror_db.mirrors_pool,
    .clear_cb = (pfe_isa_clear_cb_t)NULL_PTR
};
#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_MIRRORS_MAX */

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief Initialize the module
 * @param[in] class Reference to the classifier instance
 * @note Can be called only once unless pfe_mirror_deinit() is called.
 * @return Either EOK or error code in case of failure
 * @retval EPERM Already called, cannot be called more than once.
 * @retval EINVAL Invalid input argument (NULL).
 * @retval ENOMEM Could not allocate the needed memory.
 */
errno_t pfe_mirror_init(pfe_class_t *class)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        if(NULL_PTR != pfe_mirror_db.class)
        {
            ret = EPERM;
        }
        else
        {
            (void)autolibc_memset(&pfe_mirror_db, 0, sizeof(pfe_mirror_db));
            pfe_mirror_db.class = class;
#if PFE_CFG_MIRRORS_MAX > 0
            isa_init(&pfe_mirror_db.mirrors, &pfe_mirror_db_isa_def);
#endif /* PFE_CFG_MIRRORS_MAX */
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief Deinitialize the module - free all internally used resources
 */
void pfe_mirror_deinit(void)
{
    if(NULL_PTR != pfe_mirror_db.class)
    {
#if PFE_CFG_MIRRORS_MAX > 0
        /* Check whether the database is empty */
        if(FALSE == isa_isempty(&pfe_mirror_db.mirrors))
        {   /* Not empty */
            NXP_LOG_ERROR("There are still entries in the database\n");
        }
#endif /* PFE_CFG_MIRRORS_MAX */
        (void)autolibc_memset(&pfe_mirror_db, 0, sizeof(pfe_mirror_db));
    }
}

#if PFE_CFG_MIRRORS_MAX > 0
/**
 * @brief Queries mirrors database for the mirror instance corresponding to the search criterion
 * @param[in] crit Criterion to be used (MIRROR_ANY is used to get 1st entry)
 * @param[in] arg Criterion argument (data)
 * @return The matching mirror instance or NULL if there is no matching mirror in the database
 */
static pfe_mirror_t *pfe_mirror_db_get_by_crit(pfe_mirror_db_crit_t crit, const void *arg)
{
    pfe_mirror_t *mirror;
    bool_t match = FALSE;

    /* Iterate */
    while((pfe_mirror_db.next_item < pfe_mirror_db.mirrors.occupied_items_count) && (match == FALSE))
    {
        mirror = (pfe_mirror_t *)isa_item(&pfe_mirror_db.mirrors, pfe_mirror_db.next_item);
        if(NULL_PTR == mirror)
        {
            break;
        }
        else
        {
            pfe_mirror_db.next_item++;
            switch(crit)
            {
                case MIRROR_ANY:
                    /* Special criterion - return the 1st in the database */
                    match = TRUE;
                    break;
                case MIRROR_BY_NAME:
                    if(0 == autolibc_strcmp(mirror->name, (const char *)arg))
                    {   /* Match */
                        match = TRUE;
                    }
                    break;
                case MIRROR_BY_PHYS_ADDR:
                    if(mirror->phys_addr == (addr_t) arg)
                    {   /* Match */
                        match = TRUE;
                    }
                    break;
                default :
                    NXP_LOG_ERROR("Wrong criterion %u\n", crit);
                    pfe_mirror_db.next_item = pfe_mirror_db.mirrors.occupied_items_count;
                    break;
            }
        }
    }
    if(FALSE == match)
    {
        mirror = NULL_PTR;
    }

    return mirror;
}
#endif /* PFE_CFG_MIRRORS_MAX */

/**
 * @brief Obtain the 1st mirror matching the specified criteria
 * @param[in] crit Matching criterion for the mirrors
 * @param[in] arg Criterion specific argument (value)
 * @return Either the 1st found mirror instance or NULL if there is no matching mirror
 */
pfe_mirror_t *pfe_mirror_get_first(pfe_mirror_db_crit_t crit, const void *arg)
{
    pfe_mirror_t *mirror = NULL_PTR;
#if PFE_CFG_MIRRORS_MAX > 0
    if(NULL_PTR != pfe_mirror_db.class)
    {
        pfe_mirror_db.next_item = 0U;
        mirror = pfe_mirror_db_get_by_crit(crit, arg);
    }
#else
    (void)crit;
    (void)arg;
#endif /* PFE_CFG_MIRRORS_MAX */
    return mirror;
}

/**
 * @brief Returns the next mirror matching the criterion passed to pfe_mirror_db_get_by_crit()
 * @note  Only the MIRROR_ANY criterion is supported because mirrors are forced to have
 *        unique name and address and there are no other criteria to match. It is expected
 *        that the pfe_mirror_get_first(MIRROR_ANY, NULL) is used to obtain the 1st mirror
 *        and pfe_mirror_get_next() is used to get list of all mirrors.
 * @return Either next mirror or NULL if there are no more mirrors.
 */
pfe_mirror_t *pfe_mirror_get_next(void)
{
    pfe_mirror_t *mirror = NULL_PTR;
#if PFE_CFG_MIRRORS_MAX > 0
    if(NULL_PTR != pfe_mirror_db.class)
    {
        /* We do not support any other criteria than MIRROR_ANY. */
        mirror = pfe_mirror_db_get_by_crit(MIRROR_ANY, NULL_PTR);
    }
#endif /* PFE_CFG_MIRRORS_MAX */

    return mirror;
}

/**
 * @brief Creates a new mirror instance
 * @param[in] name Unique name (identifier)
 * @return Mirror instance or NULL in case of failure
 */
pfe_mirror_t *pfe_mirror_create(const char *name)
{
    pfe_mirror_t *mirror = NULL_PTR;
#if PFE_CFG_MIRRORS_MAX > 0
    uint32_t     length;
#endif /* PFE_CFG_MIRRORS_MAX */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == name))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
#if PFE_CFG_MIRRORS_MAX > 0
        /* check name for validity */
        length = autolibc_strnlen(name, sizeof(mirror->name));
        if((sizeof(mirror->name) <= length) || (0U == length))
        {
            NXP_LOG_ERROR("PFE mirror name string is invalid\n");
        }
        else if(NULL_PTR != pfe_mirror_db.class)
        {
            /* Do not allow duplicates */
            if(NULL_PTR == pfe_mirror_get_first(MIRROR_BY_NAME, (void *)name))
            {
                /* No such entry in the database, we may add a new one */
                mirror = (pfe_mirror_t *)isa_reserve(&pfe_mirror_db.mirrors);
                if(NULL_PTR != mirror)
                {
                    /* ISA entry available */
                    (void)autolibc_memset(mirror, 0, sizeof(*mirror));
                    /* Allocate DMEM */
                    mirror->phys_addr = pfe_class_dmem_heap_alloc(pfe_mirror_db.class, sizeof(pfe_ct_mirror_t));
                    if(0U == mirror->phys_addr)
                    {
                        /* No DMEM */
                        NXP_LOG_ERROR("Not enough DMEM for mirror\n");
                        (void)isa_release(&pfe_mirror_db.mirrors, mirror);
                        mirror = NULL_PTR;
                    }
                    else
                    {
                        /* Remember name */
                        (void)autolibc_strncpy(mirror->name, name, sizeof(mirror->name));
                    }
                }
            }
        }
        else
        {
            ;
        }
#else
      (void)name;
#endif /* PFE_CFG_MIRRORS_MAX */
    }

    return mirror;
}

/**
 * @brief Destroys the selected mirror
 * @param[in] mirror Mirror instance
 * @warning Make sure the mirror is not in use.
 */
void pfe_mirror_destroy(pfe_mirror_t *mirror)
{
#if PFE_CFG_MIRRORS_MAX > 0
    if(NULL_PTR != mirror)
    {
        pfe_class_dmem_heap_free(pfe_mirror_db.class, mirror->phys_addr);
        (void)isa_release(&pfe_mirror_db.mirrors, mirror);
    }
#else
    (void)mirror;
#endif /* PFE_CFG_MIRRORS_MAX */
}

/**
 * @brief Retrieves DMEM address used by the mirror instance
 * @param[in] mirror Mirror instance
 * @return DMEM address used by the mirror
 */
uint32_t pfe_mirror_get_address(const pfe_mirror_t *mirror)
{
    uint32_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = 0U;
    }
    else
#endif
    {
        ret = mirror->phys_addr;
    }
    return ret;
}

/**
 * @brief Retrieves mirror name
 * @param[in] mirror Mirror instance
 * @return Mirror name - this string shall not be modified outside; NULL in case of failure
 */
const char *pfe_mirror_get_name(const pfe_mirror_t *mirror)
{
    const char *str;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        str = NULL_PTR;
    }
    else
#endif
    {
        str = mirror->name;
    }

    return str;
}

/**
 * @brief Configures egress port for mirrored frames
 * @param[in] mirror Mirror instance
 * @param[in] egress Egress port for mirrored frames
 * @return EOK when success or error code otherwise
 */
errno_t pfe_mirror_set_egress_port(pfe_mirror_t *mirror, pfe_ct_phy_if_id_t egress)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* No endian conversion is needed since the size is 8-bits */
        mirror->phys.e_phy_if = egress;
        ret = pfe_class_write_dmem(pfe_mirror_db.class, -1, mirror->phys_addr, &mirror->phys, sizeof(pfe_ct_mirror_t));
    }

    return ret;
}

/**
 * @brief Retrieves egress port for mirrored frames
 * @param[in] mirror Mirror instance
 * @return The egress port
 */
pfe_ct_phy_if_id_t pfe_mirror_get_egress_port(const pfe_mirror_t *mirror)
{
    pfe_ct_phy_if_id_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = PFE_PHY_IF_ID_INVALID;
    }
    else
#endif
    {
        /* No endian conversion is needed since the size is 8-bits */
        ret = mirror->phys.e_phy_if;
    }

    return ret;
}

/**
 * @brief Configures flexible filter to select mirrored frames
 * @param[in] mirror Mirror instance
 * @param[in] filter_adress Address of flexible filter to select mirrored frames (0 to disable the filter)
 * @return EOK when success or error code otherwise
 */
errno_t pfe_mirror_set_filter(pfe_mirror_t *mirror, uint32_t filter_address)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        /* Set the address of the filter table (convert endian) */
        mirror->phys.flexible_filter = oal_htonl(filter_address);
        ret = pfe_class_write_dmem(pfe_mirror_db.class, -1, mirror->phys_addr, &mirror->phys, sizeof(pfe_ct_mirror_t));
    }

    return ret;
}

/**
 * @brief Retrieves flexible filter to select mirrored frames
 * @param[in] mirror Mirror instance
 * @return Address of flexible filter to select mirrored frames (0 = disabled the filter)
 */
uint32_t pfe_mirror_get_filter(const pfe_mirror_t *mirror)
{
    uint32_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = 0U;
    }
    else
#endif
    {
        ret = oal_ntohl(mirror->phys.flexible_filter);
    }
    /* Set the address of the filter table (convert endian) */

    return ret;
}

/**
 * @brief Configures mirrored frame modifications
 * @param[in] mirror Mirror instance
 * @param[in] actions Actions to be done on mirrored frame (network endian)
 * @param[in] args Arguments for actions (all fields in network endian)
 * @return EOK when success or error code otherwise
 */
errno_t pfe_mirror_set_actions(pfe_mirror_t *mirror, pfe_ct_route_actions_t actions, const pfe_ct_route_actions_args_t *args)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == mirror))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        mirror->phys.actions = actions;
        if(RT_ACT_NONE != actions)
        {
            (void)autolibc_memcpy(&mirror->phys.args, args, sizeof(pfe_ct_route_actions_args_t));
        }
        ret = pfe_class_write_dmem(pfe_mirror_db.class, -1, mirror->phys_addr, &mirror->phys, sizeof(pfe_ct_mirror_t));
    }

    return ret;
}

/**
 * @brief Queries mirrored frame modifications
 * @param[in] mirror Mirror instance
 * @param[out] actions Actions to be done on mirrored frame (network endian)
 * @param[out] args Arguments for actions (all fields in network endian)
 * @return EOK when success or error code otherwise
 */
errno_t pfe_mirror_get_actions(const pfe_mirror_t *mirror, pfe_ct_route_actions_t *actions, pfe_ct_route_actions_args_t *args)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == mirror)||(NULL == args)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif
    {
        ret = EOK;
        *actions = mirror->phys.actions;
        if(RT_ACT_NONE != mirror->phys.actions)
        {   /* Arguments are needed */
            (void)autolibc_memcpy(args, &mirror->phys.args, sizeof(pfe_ct_route_actions_args_t));
        }
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
