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

/**
 * @file        pfe_phy_if_slave.c
 * @brief       The PFE physical interface module source file (slave).
 * @details     This file contains physical interface-related functionality for
 *              the slave driver variant. All physical interface instance
 *              manipulation is done via RPC in way that local driver only
 *              sends requests to master driver which performs the actual
 *              requested operations.
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"

#ifdef PFE_CFG_PFE_SLAVE
#include "hal.h"
#include "pfe_platform_cfg.h"
#include "pfe_ct.h"
#include "linked_list.h"
#include "pfe_phy_if.h"
#include "pfe_idex.h" /* The RPC provider */
#include "pfe_platform_rpc.h" /* The RPC codes and data structures */

struct pfe_phy_if_tag
{
    pfe_ct_phy_if_id_t id;
    const char_t *name;
    pfe_mac_db_t mac_db; /* MAC database */
    bool_t is_enabled;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_phy_if_t pfe_phy_ifs[PFE_PHY_IF_ID_MAX + 1U];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================*/
static errno_t pfe_phy_if_db_lock(void)
{
    errno_t ret;

    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_IF_LOCK, NULL, 0, NULL, 0U);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Unable to lock interface DB: %d\n", ret);
    }

    return ret;
}

/*==================================================================================================*/
static errno_t pfe_phy_if_db_unlock(void)
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
 * @brief       Create new physical interface instance
 * @param[in]   class The classifier instance
 * @param[in]   id The PFE firmware is using HW interface identifiers to distinguish
 *              between particular interfaces. The set of available IDs (the
 *              pfe_ct_phy_if_id_t) shall remain compatible with the firmware.
 * @param[in]   name Name of the interface
 * @return      The interface instance or NULL if failed
 */
pfe_phy_if_t *pfe_phy_if_create(pfe_class_t *class, pfe_ct_phy_if_id_t id, const char_t *name)
{
    pfe_phy_if_t *iface;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == name))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        iface = NULL_PTR;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)class;

        iface = &pfe_phy_ifs[id];
        (void)autolibc_memset(iface, 0, sizeof(*iface));
        iface->id = id;
        if (EOK != pfe_mac_db_create(&iface->mac_db))
        {
            NXP_LOG_ERROR("Could not create MAC database\n");
            (void)autolibc_memset(iface, 0, sizeof(*iface));
            iface = NULL_PTR;
        }
        else
        {
            iface->name = name;
        }
    }

    return iface;
}

/**
 * @brief       Destroy interface instance
 * @param[in]   iface The interface instance
 */
void pfe_phy_if_destroy(pfe_phy_if_t *iface)
{
    pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t arg;
    errno_t ret;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t));

    if (NULL_PTR != iface)
    {
        /*  Ask the master driver to remove all associated MAC addresses */
        (void)pfe_phy_if_db_lock();
        arg.phy_if_id = iface->id;
        arg.crit = MAC_DB_CRIT_BY_OWNER;
        arg.type = PFE_TYPE_ANY;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS, &arg, (uint16_t)sizeof(arg), NULL_PTR, 0U);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS failed: %d\n", ret);
        }
        (void)pfe_phy_if_db_unlock();

        iface->name = NULL;

        (void)autolibc_memset(iface, 0, sizeof(*iface));
    }
}

/**
 * @brief       Return classifier instance associated with interface
 * @param[in]   iface The interface instance
 * @return      The classifier instance
 */
__attribute__((pure)) pfe_class_t *pfe_phy_if_get_class(const pfe_phy_if_t *iface)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return NULL;
}

/**
 * @brief       Get operational mode
 * @param[in]   iface The interface instance
 * @retval      Current phy_if mode. See pfe_ct_if_op_mode_t.
 */
pfe_ct_if_op_mode_t pfe_phy_if_get_op_mode(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_ct_if_op_mode_t mode = IF_OP_DEFAULT;
    pfe_platform_rpc_pfe_phy_if_get_op_mode_arg_t arg = {0};
    pfe_platform_rpc_pfe_phy_if_get_op_mode_ret_t rpc_ret;

    (void)autolibc_memset(&rpc_ret, 0, sizeof(pfe_platform_rpc_pfe_phy_if_get_op_mode_ret_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        mode = IF_OP_DEFAULT;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to change the operation mode */
        arg.phy_if_id = (uint8_t)iface->id;

        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_GET_OP_MODE, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_GET_OP_MODE failed: %d\n", ret);
        }
        else
        {
            mode = rpc_ret.mode;
        }

        (void)pfe_phy_if_db_unlock();
    }

    return mode;
}

/**
 * @brief Set the block state
 * @param[in] iface The interface instance
 * @param[out] block_state Block state to set
 * @return EOK on success or an error code
 */
errno_t pfe_phy_if_set_block_state(pfe_phy_if_t *iface, pfe_ct_block_state_t block_state)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to change the block state */
        arg.phy_if_id = iface->id;
        arg.block_state = block_state;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_SET_BLOCK_STATE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_SET_BLOCK_STATE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief Get the block state
 * @param[in] iface The interface instance
 * @param[out] block_state Current block state
 * @return EOK On success or an error code
 */
errno_t pfe_phy_if_get_block_state(pfe_phy_if_t *iface, pfe_ct_block_state_t *block_state)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_get_block_state_arg_t arg = {0};
    pfe_platform_rpc_pfe_phy_if_get_block_state_ret_t rpc_ret;

    (void)autolibc_memset(&rpc_ret, 0, sizeof(pfe_platform_rpc_pfe_phy_if_get_block_state_ret_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == block_state)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* GLOBAL_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to get the block state */
        arg.phy_if_id = ((uint8_t)iface->id);

        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_GET_BLOCK_STATE, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_GET_BLOCK_STATE failed: %d\n", ret);
        }
        else
        {
            *block_state = rpc_ret.state;
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}
/**
 * @brief       Bind interface with EMAC
 * @param[in]   iface The interface instance
 * @param[in]   emac The EMAC instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOTSUP Not supported
 */
errno_t pfe_phy_if_bind_emac(pfe_phy_if_t *iface, pfe_emac_t *emac)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == iface)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
    (void)emac;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  We're not going to allow slave driver to do this */
        NXP_LOG_WARNING("%s: Not supported\n", __func__);
        ret = ENOTSUP;
    }

    return ret;
}

/**
 * @brief       Bind interface with HIF channel
 * @param[in]   iface The interface instance
 * @param[in]   hif The HIF channel instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOTSUP Not supported
 */
errno_t pfe_phy_if_bind_hif(pfe_phy_if_t *iface, pfe_hif_chnl_t *hif)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == hif) || (NULL == iface)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
    (void)hif;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  We're not going to allow slave driver to do this */
        NXP_LOG_WARNING("%s: Not supported\n", __func__);
        ret = ENOTSUP;
    }

    return ret;
}

/**
 * @brief       Initialize util physical interface
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOTSUP Not supported
 */
errno_t pfe_phy_if_bind_util(pfe_phy_if_t *iface)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  We're not going to allow slave driver to do this */
        NXP_LOG_WARNING("%s: Not supported\n", __func__);
        ret = ENOTSUP;
    }

    return ret;
}

/**
 * @brief       Check if interface is enabled
 * @param[in]   iface The interface instance
 * @retval      TRUE if enabled
 * @retval      FALSE if disabled
 */
bool_t pfe_phy_if_is_enabled(pfe_phy_if_t *iface)
{
    errno_t ret;
    bool_t status = FALSE;
    pfe_platform_rpc_pfe_phy_if_is_enabled_arg_t arg = {0};
    pfe_platform_rpc_pfe_phy_if_is_enabled_ret_t rpc_ret = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        status = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to enable the interface */
        arg.phy_if_id = ((uint8_t)iface->id);
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_IS_ENABLED, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_IS_ENABLED failed: %d\n", ret);
        }
        else
        {
            status = rpc_ret.status;
        }

        (void)pfe_phy_if_db_unlock();
    }

    return status;
}

/**
 * @brief       Enable interface (RX/TX)
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_enable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_enable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_enable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to enable the interface */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ENABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_ENABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

errno_t pfe_phy_if_disable_nolock(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_disable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_disable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to disable the interface */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_DISABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_DISABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Disable interface (RX/TX)
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_disable(pfe_phy_if_t *iface)
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
        ret = pfe_phy_if_disable_nolock(iface);
    }

    return ret;
}

/**
 * @brief       Set physical interface flag
 * @param[in]   iface The interface instance
 * @param[in]   flag The flag to set
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_phy_if_set_flag(pfe_phy_if_t *iface, pfe_ct_if_flags_t flag)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  We're not going to allow slave driver to do this */
        NXP_LOG_WARNING("%s: Not supported\n", __func__);
        ret = ENOTSUP;

        (void)flag;
    }

    return ret;
}

/**
 * @brief       Clear physical interface flag
 * @param[in]   iface The interface instance
 * @param[in]   flag The flag to clear
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_phy_if_clear_flag(pfe_phy_if_t *iface, pfe_ct_if_flags_t flag)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  We're not going to allow slave driver to do this */
        NXP_LOG_WARNING("%s: Not supported\n", __func__);
        ret = ENOTSUP;

        (void)flag;
    }

    return ret;
}

/**
 * @brief       Get physical interface flag
 * @param[in]   iface The interface instance
 * @param[in]   flag The flag to check
 * @return      Flag if 'flag' is set, zero (IF_FL_NONE) otherwise
 */
pfe_ct_if_flags_t pfe_phy_if_get_flag(pfe_phy_if_t *iface, pfe_ct_if_flags_t flag)
{
    pfe_ct_if_flags_t ret_flag;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_flag = IF_FL_NONE;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  We're not going to allow slave driver to do this */
        NXP_LOG_WARNING("%s: Not supported\n", __func__);
        (void)flag;
        ret_flag = IF_FL_NONE;
    }

    return ret_flag;
}

/**
 * @brief       Check if phy_if in promiscuous mode
 * @param[in]   iface The interface instance
 * @retval      TRUE promiscuous mode is enabled
 * @retval      FALSE  promiscuous mode is disbaled
 */
bool_t pfe_phy_if_is_promisc(pfe_phy_if_t *iface)
{
    errno_t ret;
    bool_t status = FALSE;
    pfe_platform_rpc_pfe_phy_if_is_promisc_arg_t arg = {0};
    pfe_platform_rpc_pfe_phy_if_is_promisc_ret_t rpc_ret = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        status = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to enable the interface */
        arg.phy_if_id = ((uint8_t)iface->id);
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_IS_PROMISC, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_IS_ENABLED failed: %d\n", ret);
        }
        else
        {
            status = rpc_ret.status;
        }

        (void)pfe_phy_if_db_unlock();
    }

    return status;
}

/**
 * @brief       Enable promiscuous mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_promisc_enable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_promisc_enable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_promisc_enable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to enable the promiscuous mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_ENABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_PROMICS_ENABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Disable promiscuous mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_promisc_disable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_promisc_disable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_promisc_disable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to disable the promiscuous mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_DISABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_PROMICS_DISABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Enable loopback mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_loopback_enable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_loopback_enable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_loopback_enable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /* Ask the master driver to enable the loopback mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_ENABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_ENABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Disable loopback mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_loopback_disable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_loopback_disable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_loopback_disable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /* Ask the master driver to disable the loopback mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_DISABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_PROMICS_DISABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Enable loadbalance mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_loadbalance_enable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_loadbalance_enable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_loadbalance_enable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /* Ask the master driver to enable the loadbalance mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_ENABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_ENABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Disable loadbalance mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_loadbalance_disable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_loadbalance_disable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_loadbalance_disable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /* Ask the master driver to disable the loadbalance mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_DISABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_DISABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Enable ALLMULTI mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_allmulti_enable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_allmulti_enable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_allmulti_enable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to enable the allmulti mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_ENABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_ENABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Disable ALLMULTI mode
 * @param[in]   iface The interface instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_phy_if_allmulti_disable(pfe_phy_if_t *iface)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_allmulti_disable_arg_t arg;

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_allmulti_disable_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to disable the allmulti mode */
        arg.phy_if_id = iface->id;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_DISABLE, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_DISABLE failed: %d\n", ret);
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Get rx/tx flow control config
 * @param[in]   iface The interface instance
 * @param[out]  tx_ena tx flow control status
 * @param[out]  rx_ena rx flow control status
 * @return      EOK on success
 */
errno_t pfe_phy_if_get_flow_control(pfe_phy_if_t *iface, bool_t* tx_ena, bool_t* rx_ena)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        NXP_LOG_WARNING("%s: Not supported", __func__);
        (void)tx_ena;
        (void)rx_ena;
        ret = ENOTSUP;
    }

    return ret;
}

/**
 * @brief       Set tx flow control
 * @param[in]   iface The interface instance
 * @param[in]   tx_ena TRUE: enable flow control, FALSE: disable flow control
 * @return      EOK on success
 */
errno_t pfe_phy_if_set_tx_flow_control(pfe_phy_if_t *iface, bool_t tx_ena)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        NXP_LOG_WARNING("%s: Not supported", __func__);
        (void)tx_ena;
        ret = ENOTSUP;
    }

    return ret;
}

/**
 * @brief       Set rx flow control
 * @param[in]   iface The interface instance
 * @param[in]   rx_ena TRUE: enable flow control, FALSE: disable flow control
 * @return      EOK on success
 */
errno_t pfe_phy_if_set_rx_flow_control(pfe_phy_if_t *iface, bool_t rx_ena)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)iface;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        NXP_LOG_WARNING("%s: Not supported", __func__);
        (void)rx_ena;
        ret = ENOTSUP;
    }

    return ret;
}

/**
 * @brief       Add new MAC address
 * @param[in]   iface The interface instance
 * @param[in]   addr The MAC address to add
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      EEXIST The address already exists in local database
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_phy_if_add_mac_addr(pfe_phy_if_t *iface, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t arg;

    ct_assert(sizeof(pfe_mac_addr_t) == sizeof(arg.mac_addr));

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t));
    (void)owner; /* Owner will be added directly to the RPC */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();
        /*  Add address to local database */
        ret = pfe_mac_db_add_addr(&iface->mac_db, addr, owner);
        if(EOK == ret)
        {
            /*  Ask the master driver to add the MAC address */
            (void)autolibc_memcpy(&arg.mac_addr[0], addr, sizeof(arg.mac_addr));
            arg.phy_if_id = iface->id;
            ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ADD_MAC_ADDR, &arg, (uint16_t)sizeof(arg), NULL, 0U);
            if(EEXIST == ret)
            {
                NXP_LOG_WARNING("Adding MAC address which already exists in master driver\n");
                ret = EOK;
            }
            else if (EOK != ret)
            {
                NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_ADD_MAC_ADDR failed: %d\n", ret);
                ret = pfe_mac_db_del_addr(&iface->mac_db, addr, owner);
                if(EOK != ret)
                {
                    NXP_LOG_WARNING("Unable to remove MAC address from phy_if MAC database: %d\n", ret);
                }
            }
            else
            {
                NXP_LOG_DEBUG("Address %02x:%02x:%02x:%02x:%02x:%02x added to %s\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], iface->name);
            }
        }
        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Delete MAC address
 * @param[in]   iface The interface instance
 * @param[in]   addr The MAC address to delete
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOENT Address not found
 */
errno_t pfe_phy_if_del_mac_addr(pfe_phy_if_t *iface, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t arg;

    ct_assert(sizeof(pfe_mac_addr_t) == sizeof(arg.mac_addr));

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        ret = pfe_mac_db_del_addr(&iface->mac_db, addr, owner);
        if(EOK != ret)
        {
            NXP_LOG_WARNING("Unable to remove MAC address from phy_if MAC database: %d\n", ret);
        }
        else
        {
            /*  Ask the master driver to delete the MAC address */
            (void)autolibc_memcpy(&arg.mac_addr[0], addr, sizeof(arg.mac_addr));
            arg.phy_if_id = iface->id;
            ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_DEL_MAC_ADDR, &arg, (uint16_t)sizeof(arg), NULL, 0U);
            if (EOK != ret)
            {
                NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_DEL_MAC_ADDR failed: %d\n", ret);

                /* Removal of MAC address by master failed, put it back to DB */
                ret = pfe_mac_db_add_addr(&iface->mac_db, addr, owner);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Unable to put back the MAC address into phy_if MAC database: %d\n", ret);
                }
            }
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Get handle of internal MAC database
 * @param[in]   iface The interface instance
 * @retval      Database handle.
 */
pfe_mac_db_t *pfe_phy_if_get_mac_db(pfe_phy_if_t *iface)
{
    pfe_mac_db_t *mac_db;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        mac_db = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        mac_db = &iface->mac_db;
    }

    return mac_db;
}

/**
 * @brief       Get MAC address
 * @param[in]   iface The interface instance
 * @param[out]  addr The MAC address will be written here
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOENT No address found
 */
errno_t pfe_phy_if_get_mac_addr_first(pfe_phy_if_t *iface, pfe_mac_addr_t addr, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
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
        ret = pfe_mac_db_get_first_addr(&iface->mac_db, crit, type, owner, addr);
        if(EOK != ret)
        {
            NXP_LOG_WARNING("%s: Unable to get MAC address: %d\n", iface->name, ret);
        }
    }

    return ret;
}

/**
 * @brief       Delete MAC addresses added by owner with defined type
 * @param[in]   iface The interface instance
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner Required owner of MAC address
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOEXEC Command failed
 */
errno_t pfe_phy_if_flush_mac_addrs(pfe_phy_if_t *iface, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t arg;
    (void)owner; /* Owner will be added directly to the RPC */

    (void)autolibc_memset(&arg, 0, sizeof(pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        /*  Ask the master driver to flush owner's MAC addresses due to flush mode */
        arg.phy_if_id = iface->id;
        arg.crit = crit;
        arg.type = type;
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS, &arg, (uint16_t)sizeof(arg), NULL, 0U);
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS failed: %d\n", ret);
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

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

/**
 * @brief       Get HW ID of the interface
 * @param[in]   iface The interface instance
 * @return      Interface ID
 */
__attribute__((pure)) pfe_ct_phy_if_id_t pfe_phy_if_get_id(const pfe_phy_if_t *iface)
{
    pfe_ct_phy_if_id_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = PFE_PHY_IF_ID_INVALID;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = iface->id;
    }

    return ret;
}

/**
 * @brief       Get physical interface instance for HW ID
 * @param[in]   iface_id The interface HW ID
 * @return      Interface instance OR null if iface_id is not a valid id
 */
__attribute__((pure)) pfe_phy_if_t *pfe_phy_if_get_phy(pfe_ct_phy_if_id_t iface_id)
{
    pfe_phy_if_t *phy_if;

    if (PFE_PHY_IF_ID_MAX >= (uint32_t)iface_id)
    {
        phy_if = &pfe_phy_ifs[iface_id];
    }
    else
    {
        phy_if = NULL_PTR;
    }

    return phy_if;
}

/**
 * @brief       Get name
 * @param[in]   iface The interface instance
 * @return      Pointer to interface name string or "(unknown)" when called with NULL_PTR
 */
__attribute__((pure)) const char_t *pfe_phy_if_get_name(const pfe_phy_if_t *iface)
{
    const char_t *str;

    if (NULL_PTR != iface)
    {
        str = iface->name;
    }
    else
    {
        NXP_LOG_WARNING("NULL argument received for pfe_phy_if_get_name\n");
        str = "(unknown)";
    }

    return str;
}

/**
 * @brief       Get phy interface statistics
 * @param[in]   iface The interface instance
 * @param[out]  stat Statistic structure
 * @retval      EOK Success
 * @retval      NOMEM Not possible to allocate memory for read
 */
errno_t pfe_phy_if_get_stats(pfe_phy_if_t *iface, pfe_ct_phy_if_stats_t *stat)
{
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_stats_arg_t arg = {0};
    pfe_platform_rpc_pfe_phy_if_stats_ret_t rpc_ret = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == iface) || (NULL == stat)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)pfe_phy_if_db_lock();

        arg.phy_if_id = ((uint8_t)iface->id);
        ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_STATS, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
        if (EOK != ret)
        {
            NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_IS_STATS failed: %d\n", ret);
        }
        else
        {
            (void)autolibc_memcpy(stat,&rpc_ret.stats,sizeof(rpc_ret.stats));
        }

        (void)pfe_phy_if_db_unlock();
    }

    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return physical interface runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   iface       The physical interface instance
 * @param[in]   buf         A pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_phy_if_get_text_statistics(const pfe_phy_if_t *iface, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

    (void)verb_level;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == iface))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "[PhyIF 0x%x]: Unable to read DMEM (not implemented)\n", iface->id);
    }

    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_PFE_SLAVE */
