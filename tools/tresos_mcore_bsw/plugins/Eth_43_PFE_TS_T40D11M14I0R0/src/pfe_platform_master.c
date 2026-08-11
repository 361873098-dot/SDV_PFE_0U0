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

#ifdef PFE_CFG_PFE_MASTER
#include "elf_cfg.h"
#include "elf.h"

#include "hal.h"

#include "pfe_hm.h"
#include "pfe_cbus.h"
#include "pfe_hif.h"
#include "pfe_platform_cfg.h"
#include "pfe_platform.h"
#include "pfe_ct.h"
#include "pfe_idex.h"
#include "pfe_feature_mgr.h"
#include "pfe_global_wsp.h"
#include "pfe_gpi_csr.h"
#include "pfe_hif_csr.h"
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    #include "pfe_hif_nocpy_csr.h"
#endif
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    #include "pfe_platform_rpc.h" /* RPC codes and arguments */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
#ifdef PFE_CFG_FLEX_PARSER_AND_FILTER
    #include "pfe_fp.h"
#endif /* PFE_CFG_FLEX_PARSER_AND_FILTER */
#ifdef PFE_CFG_FCI_ENABLE
    #include "fci.h"
#endif /* PFE_CFG_FCI_ENABLE */

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BMU_MEM
#include "Eth_43_PFE_MemMap.h"
/* This is the PFE system buffers. The linker/MemMap should be configured to align this section to its size.
The size depend on tresos configuration. Refer to Integration Manual for more information. */
uint8_t pfe_bmu_buffers[PFE_CFG_BMU2_BUF_COUNT * PFE_CFG_BMU2_BUF_SIZE];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BMU_MEM
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

static pfe_platform_t pfe = {.probed = FALSE};

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
#define ETH_43_PFE_START_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"
/* When BMU is created, bmu empty interrupt will occur. We need this variable to detect whether BMU was created successfully or not  */
volatile bool_t bDetectBmuInit = FALSE;
#define ETH_43_PFE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_BMU_IRQ_ENABLED */

#ifdef PFE_CFG_RTABLE_ENABLE
#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief   Routing table heap alignment
 */
#define RT_ALIGNMENT 2048U

__attribute__((aligned(RT_ALIGNMENT))) uint8_t pfe_rtable_buffers[(PFE_CFG_RT_HASH_SIZE + PFE_CFG_RT_COLLISION_SIZE) * sizeof(pfe_ct_rtable_entry_t)];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_RTABLE_ENABLE */

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static void pfe_platform_destroy_pfe_log_ifs(pfe_platform_t *platform);
static void pfe_platform_destroy_pfe_phy_ifs(pfe_platform_t *platform);
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
static errno_t check_irq_vector(pfe_platform_t *platform, const pfe_platform_config_t *config);
#endif /* PFE_CFG_BMU_IRQ_ENABLED */

typedef struct
{
    const char_t *name;
    pfe_ct_phy_if_id_t id;
    pfe_mac_addr_t __attribute__((aligned(4))) mac;
    struct
    {
        pfe_emac_t *emac;
        pfe_gpi_t *gpi;
        pfe_hif_chnl_t *chnl;
    } phy;
} pfe_platform_pfy_if;
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
/**
 * @brief       BMU interrupt service routine
 * @details     Manage BMU interrupt
 * @details     See the oal_irq_handler_t
 */
static bool_t pfe_platform_bmu_isr(void *arg)
{
    const pfe_platform_t *platform = (pfe_platform_t *)arg;
    bool_t handled = FALSE;

    if (NULL != platform->bmu[0U])
    {
        pfe_bmu_irq_mask(platform->bmu[0U]);
    }

    if (NULL != platform->bmu[1U])
    {
        pfe_bmu_irq_mask(platform->bmu[1U]);
    }

    if (EOK == pfe_bmu_isr(platform->bmu[0U]))
    {
        handled |= TRUE;
    }

    if (EOK == pfe_bmu_isr(platform->bmu[1U]))
    {
        handled |= TRUE;
    }

    if (NULL != platform->bmu[0U])
    {
        pfe_bmu_irq_unmask(platform->bmu[0U]);
    }

    if (NULL != platform->bmu[1U])
    {
        pfe_bmu_irq_unmask(platform->bmu[1U]);
    }

    return handled;
}
#endif /* PFE_CFG_BMU_IRQ_ENABLED */

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
/**
 * @brief       IDEX RPC callback
 * @details     All requests from slave drivers are coming and being processed
 *              within this callback. Any request policing should be implemented
 *              here.
 * @warning     Don't block or sleep within the body
 * @param[in]   sender RPC originator identifier. The physical interface ID
 *                     where the request is coming from.
 * @param[in]   id Request identifier
 * @param[in]   buf Pointer to request argument. Can be NULL.
 * @param[in]   buf_len Length of request argument. Can be zero.
 * @param[in]   arg Custom argument provided via pfe_idex_set_rpc_cbk()
 * @note        This callback runs in dedicated context/thread.
 */
void pfe_platform_idex_rpc_cbk(pfe_ct_phy_if_id_t sender, uint32_t id, void *buf, uint16_t buf_len, void *arg)
{
    pfe_platform_t *platform = (pfe_platform_t *)arg;
    pfe_phy_if_t *phy_if_arg = NULL;
    pfe_if_db_entry_t *entry = NULL;
    errno_t ret = EOK;

    (void)buf_len;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == platform))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Check if phy_if should be extracted from argument */
        if( ((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ID_COMPATIBLE_FIRST <= id) &&
            ((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ID_COMPATIBLE_LAST >= id)
          )
        {
            ret = pfe_if_db_get_first(  platform->phy_if_db, (uint32_t)sender, IF_DB_CRIT_BY_ID,
                                        (void *)(addr_t)((pfe_platform_rpc_pfe_phy_if_generic_t*)buf)->phy_if_id, &entry);
            if((EOK == ret) && (NULL != entry))
            {
                phy_if_arg = pfe_if_db_entry_get_phy_if(entry);
            }
            else
            {
                /* Entry doesn't exist */
                ret = ENOENT;
            }
        }

        switch (id)
        {
            case (uint32_t)PFE_PLATFORM_RPC_PFE_IF_LOCK:
            {
                ret = pfe_if_db_lock_owned((uint32_t)sender);

                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }
                /* start timeout*/
                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_IF_UNLOCK:
            {
                ret = pfe_if_db_unlock((uint32_t)sender);

                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }
                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_CREATE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_CREATE\n");

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ENABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_ENABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_enable(phy_if_arg);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_DISABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_DISABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_disable(phy_if_arg);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_ENABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_ENABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_promisc_enable(phy_if_arg);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_DISABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_PROMISC_DISABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_promisc_disable(phy_if_arg);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_ENABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_ENABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_loopback_enable(phy_if_arg);
                }

                /*      Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_DISABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_LOOPBACK_DISABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_loopback_disable(phy_if_arg);
                }

                /*      Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_ENABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_ENABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_loadbalance_enable(phy_if_arg);
                }

                /*      Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_DISABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_LOADBALANCE_DISABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_loadbalance_disable(phy_if_arg);
                }

                /*      Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_ENABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_ENABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_allmulti_enable(phy_if_arg);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_DISABLE:
            {
                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_ALLMULTI_DISABLE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_allmulti_disable(phy_if_arg);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_ADD_MAC_ADDR:
            {
                pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t *rpc_arg = (pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t *)buf;
                pfe_mac_addr_t mac_addr;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_ADD_MAC_ADDR\n");

                if (EOK == ret)
                {
                    ct_assert(sizeof(pfe_mac_addr_t) == sizeof(rpc_arg->mac_addr));
                    (void)autolibc_memcpy(&mac_addr, rpc_arg->mac_addr, sizeof(pfe_mac_addr_t));
                    ret = pfe_phy_if_add_mac_addr(phy_if_arg, mac_addr, sender);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_DEL_MAC_ADDR:
            {
                pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t *rpc_arg = (pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t *)buf;
                pfe_mac_addr_t mac_addr;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_DEL_MAC_ADDR\n");

                if (EOK == ret)
                {
                    ct_assert(sizeof(pfe_mac_addr_t) == sizeof(rpc_arg->mac_addr));
                    (void)autolibc_memcpy(&mac_addr, rpc_arg->mac_addr, sizeof(pfe_mac_addr_t));
                    ret = pfe_phy_if_del_mac_addr(phy_if_arg, mac_addr, sender);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS:
            {
                pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t *rpc_arg = (pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t *)buf;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_FLUSH_MAC_ADDRS\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_flush_mac_addrs(phy_if_arg, rpc_arg->crit, rpc_arg->type, sender);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_SET_BLOCK_STATE:
            {
                pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t *rpc_arg = (pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t *)buf;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_SET_BLOCK_STATE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_set_block_state(phy_if_arg, rpc_arg->block_state);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_GET_BLOCK_STATE:
            {
                pfe_platform_rpc_pfe_phy_if_get_block_state_ret_t rpc_ret = {IF_BS_FORWARDING};
                pfe_ct_block_state_t block_state = IF_BS_FORWARDING;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_GET_BLOCK_STATE\n");

                if (EOK == ret)
                {
                    ret = pfe_phy_if_get_block_state(phy_if_arg, &block_state);
                    rpc_ret.state = block_state;
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_GET_OP_MODE:
            {
                pfe_platform_rpc_pfe_phy_if_get_op_mode_ret_t rpc_ret = {IF_OP_DEFAULT};
                pfe_ct_if_op_mode_t mode = IF_OP_DEFAULT;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_GET_OP_MODE\n");

                if (EOK == ret)
                {
                    mode = pfe_phy_if_get_op_mode(phy_if_arg);
                    rpc_ret.mode = mode;
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_IS_ENABLED:
            {
                pfe_platform_rpc_pfe_phy_if_is_enabled_ret_t rpc_ret = {0};
                bool_t status = FALSE;


                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_IS_ENABLED\n");

                if (EOK == ret)
                {
                    status = pfe_phy_if_is_enabled(phy_if_arg);
                    rpc_ret.status = status;
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_IS_PROMISC:
            {
                pfe_platform_rpc_pfe_phy_if_is_promisc_ret_t rpc_ret = {0};
                bool_t status = FALSE;


                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_IS_PROMISC\n");

                if (EOK == ret)
                {
                    status = pfe_phy_if_is_promisc(phy_if_arg);
                    rpc_ret.status = status;
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_STATS:
            {
                pfe_platform_rpc_pfe_phy_if_stats_ret_t rpc_ret = {0};

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_STATS\n");

                if (EOK == ret)
                {
                    ct_assert(sizeof(pfe_ct_phy_if_stats_t) == sizeof(rpc_ret.stats));
                    ret = pfe_phy_if_get_stats(phy_if_arg, &rpc_ret.stats);
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

            case (uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE:
            {
                pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t *rpc_arg = (pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t *)buf;
                pfe_platform_rpc_pfe_phy_if_get_stat_value_ret_t rpc_ret = {0};
                uint32_t stat_val = 0U;
                pfe_emac_t *emac;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE\n");

                if (EOK == ret)
                {
                    if (2U < rpc_arg->phy_if_id)
                    {
                        NXP_LOG_ERROR("RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE: invalid EMAC id: %d\n", rpc_arg->phy_if_id);
                        /*  Report execution status to caller */
                        if (EOK != pfe_idex_set_rpc_ret_val(EINVAL, NULL, 0U))
                        {
                            NXP_LOG_ERROR("Could not send RPC response\n");
                        }
                        break;
                    }
                    else
                    {
                        emac = pfe.emac[rpc_arg->phy_if_id];
                        stat_val = pfe_emac_get_stat_value(emac, rpc_arg->stat_id);
                        rpc_ret.stat_val = stat_val;
                    }
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }

    #if defined(PFE_CFG_FCI_ENABLE)
            case (uint32_t)PFE_PLATFORM_RPC_PFE_FCI_PROXY:
            {
                pfe_platform_rpc_pfe_fci_proxy_arg_t *rpc_arg = (pfe_platform_rpc_pfe_fci_proxy_arg_t *)buf;
                pfe_platform_rpc_pfe_fci_proxy_ret_t rpc_ret = {0};

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_PFE_FCI_PROXY\n");

                if (EOK == ret)
                {
                    ct_assert(sizeof(msg_type_t) == sizeof(rpc_arg->type));
                    ct_assert(sizeof(fci_msg_cmd_t) == sizeof(rpc_arg->msg_cmd));

                    /* Construct platform-specific FCI message. Use received platform-independent data. */
                    fci_msg_t msg;
                    autolibc_memcpy(&msg.type,    &rpc_arg->type,   sizeof(msg.type));
                    autolibc_memcpy(&msg.msg_cmd, &rpc_arg->msg_cmd,sizeof(msg.msg_cmd));
                    fci_msg_t rep_msg = {.type=FCI_MSG_CMD, .msg_cmd={0}};

                    /* Set sender / originator's interface */
                    msg.msg_cmd.sender = (uint32_t)sender;

                    /* Process the FCI message. */
                    ret = fci_process_ipc_message(&msg, &rep_msg);

                    /* Fill the RPC reply. */
                    rpc_ret.msg_cmd = rep_msg.msg_cmd;
                }

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }
    #endif /* PFE_CFG_FCI_ENABLE */

            case (uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY:
            {
                pfe_platform_rpc_mdio_proxy_arg_t *rpc_arg = (pfe_platform_rpc_mdio_proxy_arg_t *)buf;
                pfe_platform_rpc_mdio_proxy_ret_t rpc_ret = {0};
                pfe_emac_t *emac;
                uint32_t key;

                NXP_LOG_DEBUG("RPC: PFE_PLATFORM_RPC_MDIO_PROXY\n");
                if (EOK == ret)
                {
                    if (2U < rpc_arg->emac_id)
                    {
                        NXP_LOG_ERROR("RPC: PFE_PLATFORM_RPC_MDIO_PROXY: invalid EMAC id: %d\n", rpc_arg->emac_id);
                        /*  Report execution status to caller */
                        if (EOK != pfe_idex_set_rpc_ret_val(EINVAL, NULL, 0U))
                        {
                            NXP_LOG_ERROR("Could not send RPC response\n");
                        }
                    }
                    else
                    {
                        emac = pfe.emac[rpc_arg->emac_id];
                        /* Lock the MDIO bus */
                        ret = pfe_emac_mdio_lock(emac, &key);
                        if (EOK == ret)
                        {
                            /* Process the MDIO OP message */
                            switch (rpc_arg->op)
                            {
                                case PFE_PLATFORM_RPC_MDIO_OP_READ_CL22:
                                {
                                    ret = pfe_emac_mdio_read22(emac, rpc_arg->pa, (uint8_t)rpc_arg->ra, &rpc_ret.val, key);
                                    /*  Report execution status to caller */
                                    if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                                    {
                                        NXP_LOG_ERROR("Could not send RPC response\n");
                                    }
                                    break;
                                }
                                case PFE_PLATFORM_RPC_MDIO_OP_WRITE_CL22:
                                {
                                    ret = pfe_emac_mdio_write22(emac, rpc_arg->pa, (uint8_t)rpc_arg->ra, rpc_arg->val, key);
                                    /*  Report execution status to caller */
                                    if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                                    {
                                        NXP_LOG_ERROR("Could not send RPC response\n");
                                    }
                                    break;
                                }
                                case PFE_PLATFORM_RPC_MDIO_OP_READ_CL45:
                                {
                                    ret = pfe_emac_mdio_read45(emac, rpc_arg->pa, rpc_arg->dev, rpc_arg->ra, &rpc_ret.val, key);
                                    /*  Report execution status to caller */
                                    if (EOK != pfe_idex_set_rpc_ret_val(ret, &rpc_ret, (uint16_t)sizeof(rpc_ret)))
                                    {
                                        NXP_LOG_ERROR("Could not send RPC response\n");
                                    }
                                    break;
                                }
                                case PFE_PLATFORM_RPC_MDIO_OP_WRITE_CL45:
                                {
                                    ret = pfe_emac_mdio_write45(emac, rpc_arg->pa, rpc_arg->dev, rpc_arg->ra, rpc_arg->val, key);
                                    /*  Report execution status to caller */
                                    if (EOK != pfe_idex_set_rpc_ret_val(ret, NULL, 0U))
                                    {
                                        NXP_LOG_ERROR("Could not send RPC response\n");
                                    }
                                    break;
                                }
                                default:
                                {
                                    NXP_LOG_ERROR("Invalid MDIO operation\n");
                                    /*  Report execution status to caller */
                                    if (EOK != pfe_idex_set_rpc_ret_val(EINVAL, NULL, 0U))
                                    {
                                        NXP_LOG_ERROR("Could not send RPC response\n");
                                    }
                                    break;
                                }
                            }
                            /* Unlock the locked MDIO bus */
                            (void)pfe_emac_mdio_unlock(emac, key);
                        }
                        else
                        {
                            NXP_LOG_ERROR("Lock the MDIO bus failed\n");
                            /*  Report execution status to caller */
                            if (EOK != pfe_idex_set_rpc_ret_val(EPERM, NULL, 0U))
                            {
                                NXP_LOG_ERROR("Could not send RPC response\n");
                            }
                        }
                    }
                }
                break;
            }

            default:
            {
                NXP_LOG_WARNING("Unsupported RPC code: %u\n", (uint_t)id);

                /*  Report execution status to caller */
                if (EOK != pfe_idex_set_rpc_ret_val(EINVAL, NULL, 0U))
                {
                    NXP_LOG_ERROR("Could not send RPC response\n");
                }

                break;
            }
        }
    }
}
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

/**
 * @brief       Assign HIF to the platform
 */
static errno_t pfe_platform_create_hif(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    errno_t ret;
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    /* Set FCI ownership configuration */
    platform->hif_fci_owner_chnls_mask = config->hif_fci_owner_chnls_mask;
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
    platform->hif = pfe_hif_create(platform->cbus_baseaddr + CBUS_HIF_BASE_ADDR, config->hif_chnls_mask);
    if (NULL == platform->hif)
    {
        NXP_LOG_ERROR("Couldn't create HIF instance\n");
        ret = ENODEV;
    }
    else
    {
    #ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
        pfe_hif_set_master_detect_cfg(platform->hif, !config->disable_master_detect);
    #endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

        pfe_hif_irq_unmask(platform->hif);

    #ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
        /* Clean Master detect flags for all HIF channels */
        pfe_hif_clear_master_up(platform->hif);
    #endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#if !defined (PFE_CFG_HIF_NOCPY_SUPPORT) /* Applicable only if HIF is a local HIF */
        /* Give local instance ownership of all EMAC timers */
        pfe_hif_init_emac_timer_ownership(platform->hif);
#endif

        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Release HIF-related resources
 */
static void pfe_platform_destroy_hif(pfe_platform_t *platform)
{
    if (NULL != platform->hif)
    {
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
        /* Clean Master detect flags for all HIF channels */
        pfe_hif_clear_master_up(platform->hif);
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
        pfe_hif_irq_mask(platform->hif);
        pfe_hif_destroy(platform->hif);
        platform->hif = NULL;
    }
}

/**
 * @brief       Assign HIF NOCPY to the platform
 */
static errno_t pfe_platform_create_hif_nocpy(pfe_platform_t *platform)
{
    uint16_t lmem_header_size;
    errno_t ReVal;

    if(PFE_S32G3_VERSION == platform->pfe_version)
    {   /* S32G3 */
        lmem_header_size = 48U;
    }
    else
    {   /* S32G2 */
        lmem_header_size = 112U;
    }

    platform->hif_nocpy = pfe_hif_nocpy_create(pfe.cbus_baseaddr + CBUS_HIF_NOCPY_BASE_ADDR, platform->bmu[1U], lmem_header_size);

    if (NULL == platform->hif_nocpy)
    {
        NXP_LOG_ERROR("Couldn't create HIF NOCPY instance\n");
        ReVal = ENODEV;
    }
    else
    {

#if defined (PFE_CFG_HIF_NOCPY_SUPPORT) /* Applicable only if the local HIF is HIF_NOCPY */
        /* Give local instance ownership of all EMAC timers*/
        pfe_hif_nocpy_init_emac_timer_ownership(platform->hif_nocpy);
#endif
        ReVal = EOK;
    }

    return ReVal;
}

#if defined (PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       Release HIF-related resources
 */
static void pfe_platform_destroy_hif_nocpy(pfe_platform_t *platform)
{
    if (NULL != platform->hif_nocpy)
    {
        if (NULL != platform->irq_hif_nocpy)
        {
            oal_irq_destroy(platform->irq_hif_nocpy);
            platform->irq_hif_nocpy = NULL;
        }

        pfe_hif_nocpy_destroy(platform->hif_nocpy);
        platform->hif_nocpy = NULL;
    }
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
/**
 * @brief       Check irq assignment BMU to the platform
 */
static errno_t check_irq_vector(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    errno_t ret = EOK;

    if (NULL == platform->irq_bmu)
    {
        NXP_LOG_ERROR("Could not create BMU IRQ vector %u\n", (uint_t)config->irq_vector_bmu);
        ret = ENODEV;
    }
    else
    {
        if (EOK != oal_irq_add_handler(platform->irq_bmu, &pfe_platform_bmu_isr, platform, NULL))
        {
            NXP_LOG_ERROR("Could not add IRQ handler for the BMU[0]\n");
            ret = ENODEV;
        }
        else
        {
            pfe_bmu_irq_unmask(platform->bmu[0U]);
            pfe_bmu_irq_unmask(platform->bmu[1U]);
            bDetectBmuInit = TRUE;
            ret = EOK;
        }
    }

    return ret;
}
#endif /* PFE_CFG_BMU_IRQ_ENABLED */

/**
 * @brief       Assign BMU to the platform
 */
static errno_t pfe_platform_create_bmu(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    pfe_bmu_cfg_t bmu_cfg = {0U};
    errno_t ret = EOK;

    /*  Must be aligned to BUF_COUNT * BUF_SIZE (assured by fixed configuration) */
    bmu_cfg.pool_pa = (PFE_CFG_CBUS_PHYS_BASE_ADDR + CBUS_LMEM_BASE_ADDR + PFE_CFG_BMU1_LMEM_BASEADDR);
    NXP_LOG_INFO("BMU1 buffer base: p0x%"PRINTADDR_T"\n", bmu_cfg.pool_pa);
    bmu_cfg.max_buf_cnt = PFE_CFG_BMU1_BUF_COUNT;
    bmu_cfg.buf_size = PFE_CFG_BMU1_BUF_SIZE;
    bmu_cfg.bmu_ucast_thres = 0x200U;
    bmu_cfg.bmu_mcast_thres = 0x200U;
    bmu_cfg.int_mem_loc_cnt = 64U;
    bmu_cfg.buf_mem_loc_cnt = 64U;

    platform->bmu[1U] = NULL;
    platform->bmu[0U] = pfe_bmu_create(platform->cbus_baseaddr, CBUS_BMU1_BASE_ADDR, &bmu_cfg, 0U);
    if (NULL == platform->bmu[0U])
    {
        NXP_LOG_ERROR("Couldn't create BMU1 instance\n");
        ret = ENODEV;
    }
    else if (2U > platform->bmu_count)
    {
        NXP_LOG_WARNING("Only single BMU was configured.\n");
        ret = EOK;
    }
    /*  Must be aligned to BUF_COUNT * BUF_SIZE */
    else if(0U != ((addr_t)pfe_bmu_buffers % (PFE_CFG_BMU2_BUF_COUNT * PFE_CFG_BMU2_BUF_SIZE)))
    {
        NXP_LOG_ERROR("The BMU memory is not properly aligned\n");
        ret = EINVAL;
    }
    else
    {
        platform->bmu_buffers_size = PFE_CFG_BMU2_BUF_COUNT * PFE_CFG_BMU2_BUF_SIZE;
        platform->bmu_buffers_va = pfe_bmu_buffers;
        bmu_cfg.pool_va = (addr_t)platform->bmu_buffers_va;
        bmu_cfg.pool_pa = (addr_t)oal_mm_virt_to_phys_contig((void*)platform->bmu_buffers_va);

        /*  S32G: Some of PFE AXI MASTERs can only access range p0x00020000 - p0xbfffffff */
        if (((addr_t)bmu_cfg.pool_pa < 0x00020000U) || (((addr_t)bmu_cfg.pool_pa + platform->bmu_buffers_size) > 0xbfffffffU))
        {
            NXP_LOG_WARNING("BMU2 buffers not in required range: starts @ p0x%"PRINTADDR_T"\n", bmu_cfg.pool_pa);
        }
        else
        {
            NXP_LOG_INFO("BMU2 buffer base: p0x%"PRINTADDR_T" (0x%"PRINTADDR_T" bytes)\n", bmu_cfg.pool_pa, platform->bmu_buffers_size);
        }

        bmu_cfg.max_buf_cnt = PFE_CFG_BMU2_BUF_COUNT;
        bmu_cfg.buf_size = PFE_CFG_BMU2_BUF_SIZE;
        bmu_cfg.bmu_ucast_thres = 0x800U;
        bmu_cfg.bmu_mcast_thres = 0x200U;
        bmu_cfg.int_mem_loc_cnt = 1024U;
        bmu_cfg.buf_mem_loc_cnt = 1024U;

        platform->bmu[1U] = pfe_bmu_create(platform->cbus_baseaddr, CBUS_BMU2_BASE_ADDR, &bmu_cfg, 1U);
        if (NULL == platform->bmu[1U])
        {
            NXP_LOG_ERROR("Couldn't create BMU2 instance\n");
            ret = ENODEV;
        }
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
        else
        {
            platform->irq_bmu = oal_irq_create((int32_t)config->irq_vector_bmu, (oal_irq_flags_t)0, "PFE BMU IRQ");
            ret = check_irq_vector(platform, config);
        }
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
    }
    (void)config;

    return ret;
}

/**
 * @brief       Release BMU-related resources
 */
static void pfe_platform_destroy_bmu(pfe_platform_t *platform)
{
    uint32_t ii;

    for (ii=0; ii<pfe.bmu_count; ii++)
    {
        if (platform->bmu[ii] != NULL)
        {
            pfe_bmu_destroy(platform->bmu[ii]);
            platform->bmu[ii] = NULL;
        }
    }

    #if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
    if (NULL != platform->irq_bmu)
    {
        oal_irq_destroy(platform->irq_bmu);
        platform->irq_bmu = NULL;
    }
    bDetectBmuInit = FALSE;
    #endif /* PFE_CFG_BMU_IRQ_ENABLED */

    platform->bmu_buffers_va = NULL;
}

/**
 * @brief       Assign GPI to the platform
 */
static errno_t pfe_platform_create_gpi(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    pfe_gpi_cfg_t gpi_cfg_tmp;
    uint32_t aseq_len = 0x50U;
    errno_t ret;

    if(PFE_S32G3_VERSION == platform->pfe_version)
    {   /* S32G3 */
        gpi_cfg_tmp.lmem_header_size = 48U;
        gpi_cfg_tmp.g2_ordered_class_writes = FALSE;
        aseq_len = 0x10U;
    }
    else
    {   /* S32G2 */
        gpi_cfg_tmp.lmem_header_size = 112U;
        gpi_cfg_tmp.g2_ordered_class_writes = config->g2_ordered_class_writes;
    }

    /*  GPI1 */
    gpi_cfg_tmp.alloc_retry_cycles = 0x200U;
    gpi_cfg_tmp.gpi_tmlf_txthres = 0x178U;
    gpi_cfg_tmp.gpi_dtx_aseq_len = aseq_len; /* See AAVB-2028 */
    gpi_cfg_tmp.emac_1588_ts_en = TRUE;

    platform->gpi[0U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_EGPI1_BASE_ADDR, &gpi_cfg_tmp, PFE_GPI_1);
    if (NULL == platform->gpi[0])
    {
        NXP_LOG_ERROR("Couldn't create GPI1 instance\n");
        ret = ENODEV;
    }
    else
    {
        /*  GPI2 */
        gpi_cfg_tmp.alloc_retry_cycles = 0x200U;
        gpi_cfg_tmp.gpi_tmlf_txthres = 0x178U;
        gpi_cfg_tmp.gpi_dtx_aseq_len = aseq_len; /* See AAVB-2028 */
        gpi_cfg_tmp.emac_1588_ts_en = TRUE;

        platform->gpi[1U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_EGPI2_BASE_ADDR, &gpi_cfg_tmp, PFE_GPI_2);
        if (NULL == platform->gpi[1U])
        {
            NXP_LOG_ERROR("Couldn't create GPI2 instance\n");
            ret = ENODEV;
        }
        else
        {
            /*  GPI3 */
            gpi_cfg_tmp.alloc_retry_cycles = 0x200U;
            gpi_cfg_tmp.gpi_tmlf_txthres = 0x178U;
            gpi_cfg_tmp.gpi_dtx_aseq_len = aseq_len; /* See AAVB-2028 */
            gpi_cfg_tmp.emac_1588_ts_en = TRUE;

            platform->gpi[2U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_EGPI3_BASE_ADDR, &gpi_cfg_tmp, PFE_GPI_3);
            if (NULL == platform->gpi[2U])
            {
                NXP_LOG_ERROR("Couldn't create GPI3 instance\n");
                ret = ENODEV;
            }
            else
            {
                ret = EOK;
            }
        }
    }

    return ret;
}

/**
 * @brief       Release GPI-related resources
 */
static void pfe_platform_destroy_gpi(pfe_platform_t *platform)
{
    uint32_t ii;

    for (ii=0U; ii<platform->gpi_count; ii++)
    {
        if (NULL != platform->gpi[ii])
        {
            pfe_gpi_destroy(platform->gpi[ii]);
            platform->gpi[ii] = NULL;
        }
    }
}

/**
 * @brief       Assign ETGPI to the platform
 */
static errno_t pfe_platform_create_etgpi(pfe_platform_t *platform)
{
    pfe_gpi_cfg_t gpi_cfg_tmp;
    errno_t ret;
    uint32_t aseq_len = 0x40U;

    if(PFE_S32G3_VERSION == platform->pfe_version)
    {   /* S32G3 */
        gpi_cfg_tmp.lmem_header_size = 48U;
        gpi_cfg_tmp.g2_ordered_class_writes = FALSE;
        aseq_len = 0x10U;
    }
    else
    {   /* S32G2 */
        gpi_cfg_tmp.lmem_header_size = 112U;
#ifdef PFE_CFG_G2_ORDERED_CLASS_WRITES
        gpi_cfg_tmp.g2_ordered_class_writes = TRUE;
#else
        gpi_cfg_tmp.g2_ordered_class_writes = FALSE;
#endif
    }

    /*  ETGPI1 */
    gpi_cfg_tmp.alloc_retry_cycles = 0x200U;
    gpi_cfg_tmp.gpi_tmlf_txthres = 0xbcU;
    gpi_cfg_tmp.gpi_dtx_aseq_len = aseq_len;
    gpi_cfg_tmp.emac_1588_ts_en = TRUE;

    platform->etgpi[0U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_ETGPI1_BASE_ADDR, &gpi_cfg_tmp, PFE_ETGPI_1);
    if (NULL == platform->etgpi[0U])
    {
        NXP_LOG_ERROR("Couldn't create ETGPI1 instance\n");
        ret = ENODEV;
    }
    else
    {
        /*  ETGPI2 */
        gpi_cfg_tmp.alloc_retry_cycles = 0x200U;
        gpi_cfg_tmp.gpi_tmlf_txthres = 0xbcU;
        gpi_cfg_tmp.gpi_dtx_aseq_len = aseq_len;
        gpi_cfg_tmp.emac_1588_ts_en = TRUE;

        platform->etgpi[1U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_ETGPI2_BASE_ADDR, &gpi_cfg_tmp, PFE_ETGPI_2);
        if (NULL == platform->etgpi[1U])
        {
            NXP_LOG_ERROR("Couldn't create ETGPI2 instance\n");
            ret = ENODEV;
        }
        else
        {
            /*  ETGPI3 */
            gpi_cfg_tmp.alloc_retry_cycles = 0x200U;
            gpi_cfg_tmp.gpi_tmlf_txthres = 0xbcU;
            gpi_cfg_tmp.gpi_dtx_aseq_len = aseq_len;
            gpi_cfg_tmp.emac_1588_ts_en = TRUE;

            platform->etgpi[2U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_ETGPI3_BASE_ADDR, &gpi_cfg_tmp, PFE_ETGPI_3);
            if (NULL == platform->etgpi[2U])
            {
                NXP_LOG_ERROR("Couldn't create ETGPI3 instance\n");
                ret = ENODEV;
            }
            else
            {
                ret = EOK;
            }
        }
    }

    return ret;
}

/**
 * @brief       Release ETGPI-related resources
 */
static void pfe_platform_destroy_etgpi(pfe_platform_t *platform)
{
    uint32_t ii;

    for (ii=0U; ii<platform->etgpi_count; ii++)
    {
        if (platform->etgpi[ii] != NULL)
        {
            pfe_gpi_destroy(platform->etgpi[ii]);
            platform->etgpi[ii] = NULL;
        }
    }
}

/**
 * @brief       Assign HGPI to the platform
 */
static errno_t pfe_platform_create_hgpi(pfe_platform_t *platform)
{
    pfe_gpi_cfg_t hgpi_cfg;
    errno_t ret;
    uint32_t aseq_len = HGPI_ASEQ_LEN;

    if(PFE_S32G3_VERSION == platform->pfe_version)
    {   /* S32G3 */
        hgpi_cfg.lmem_header_size = 48U;
        hgpi_cfg.g2_ordered_class_writes = FALSE;
        aseq_len = 0x10;
    }
    else
    {   /* S32G2 */
        hgpi_cfg.lmem_header_size = 112U;
#ifdef PFE_CFG_G2_ORDERED_CLASS_WRITES
        hgpi_cfg.g2_ordered_class_writes = TRUE;
#else
        hgpi_cfg.g2_ordered_class_writes = FALSE;
#endif
    }

    hgpi_cfg.alloc_retry_cycles = 0x200U;
    hgpi_cfg.gpi_tmlf_txthres = 0x178U;
    hgpi_cfg.gpi_dtx_aseq_len = aseq_len;
    hgpi_cfg.emac_1588_ts_en = FALSE;

    platform->hgpi[0U] = pfe_gpi_create(platform->cbus_baseaddr, CBUS_HGPI_BASE_ADDR, &hgpi_cfg, PFE_HGPI_1);
    if (NULL == platform->hgpi[0U])
    {
        NXP_LOG_ERROR("Couldn't create HGPI instance\n");
        ret = ENODEV;
    }
    else
    {
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Release GPI-related resources
 */
static void pfe_platform_destroy_hgpi(pfe_platform_t *platform)
{
    uint32_t ii;

    for (ii=0U; ii<platform->hgpi_count; ii++)
    {
        if (NULL != platform->hgpi[ii])
        {
            pfe_gpi_destroy(platform->hgpi[ii]);
            platform->hgpi[ii] = NULL;
        }
    }
}

/**
 * @brief       Assign CLASS to the platform
 */
static errno_t pfe_platform_create_class_object(pfe_platform_t *platform, pfe_class_cfg_t class_cfg)
{
    errno_t ret = EOK;
    ELF_File_t elf;
    const uint8_t *temp;

    if(PFE_S32G3_VERSION == platform->pfe_version)
    {   /* S32G3 */
        class_cfg.lmem_header_size = 48U;
        class_cfg.ro_header_size = 512U;
    }
    else
    {   /* S32G2 */
        class_cfg.lmem_header_size = 112U;
        class_cfg.ro_header_size = 256U;
    }

    platform->classifier = pfe_class_create(platform->cbus_baseaddr, platform->class_pe_count, &class_cfg);

    if (NULL == platform->classifier)
    {
        NXP_LOG_ERROR("Couldn't create classifier instance\n");
        ret = ENODEV;
    }
    else
    {
        temp = (uint8_t *)platform->fw->class_data;

        if ((temp[0] == 0x7fU) &&
            (temp[1] == (uint8_t)('E')) &&
            (temp[2] == (uint8_t)('L')) &&
            (temp[3] == (uint8_t)('F')))
        {
            /*  FW is ELF file */
            NXP_LOG_INFO("Firmware .elf detected\n");

            if (FALSE == ELF_Open(&elf, platform->fw->class_data))
            {
                NXP_LOG_ERROR("Can't parse CLASS firmware\n");
                ret = EIO;
            }
            else
            {
                NXP_LOG_INFO("Uploading CLASS firmware\n");
                ret = pfe_class_load_firmware(platform->classifier, &elf);

                ELF_Close(&elf);

                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Error during upload of CLASS firmware: %d\n", ret);
                    ret = EIO;
                }
            }
        }
        else
        {
            NXP_LOG_ERROR("Only ELF format is supported\n");
            ret = ENODEV;
        }
    }
    return ret;
}
/**
 * @brief       Assign CLASS to the platform
 */
static errno_t pfe_platform_create_class(pfe_platform_t *platform, const pfe_platform_config_t *conf)
{
    errno_t ret;
    pfe_class_cfg_t class_cfg =
    {
        .resume = FALSE,
        .toe_mode = FALSE,
        .pe_sys_clk_ratio = PFE_CFG_CLMODE,
        .pkt_parse_offset = 6U, /* This is actually the sizeof(struct hif_hdr) to skip the HIF header */
        .g2_ordered_class_writes = conf->g2_ordered_class_writes,
    };

    if (FALSE != conf->g2_ordered_class_writes)
    {
        if (TRUE == pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3))
        {
            NXP_LOG_WARNING("The option 'g2_ordered_class_writes' has no effect on S32G3\n");
        }
        else
        {
            NXP_LOG_WARNING("The option 'g2_ordered_class_writes' is enabled\n");
        }
    }

    if (NULL == platform->fw)
    {
        NXP_LOG_ERROR("The CLASS firmware is NULL\n");
        ret = ENODEV;
    }

    else if (NULL == platform->fw->class_data)
    {
        NXP_LOG_ERROR("The CLASS firmware is not loaded\n");
        ret = EIO;
    }
    else
    {
        ret = pfe_platform_create_class_object(platform, class_cfg);
    }

    return ret;
}

/**
 * @brief       Release CLASS-related resources
 */
static void pfe_platform_destroy_class(pfe_platform_t *platform)
{
    if (NULL != platform->classifier)
    {
        pfe_class_destroy(platform->classifier);
        platform->classifier = NULL;
    }
}

#if !defined(PFE_CFG_L2BRIDGE_ENABLE)
/**
 * @brief       Init L2 Bridge Memory default
 */
static errno_t pfe_platform_init_l2br_mem(pfe_platform_t *platform)
{
    errno_t ret = EOK;
    pfe_l2br_table_t *mactab = NULL;
    pfe_l2br_table_t *vlantab = NULL;
    mactab = pfe_l2br_table_create(platform->cbus_baseaddr, PFE_L2BR_TABLE_MAC2F);
    if (NULL == mactab)
    {
        NXP_LOG_ERROR("Couldn't create default VLAN table instance\n");
        ret = ENODEV;
    }
    vlantab = pfe_l2br_table_create(platform->cbus_baseaddr, PFE_L2BR_TABLE_VLAN);
    if (NULL == vlantab)
    {
        NXP_LOG_ERROR("Couldn't create default VLAN table instance\n");
        ret = ENODEV;
    }

    return ret;
}
#endif

#if defined(PFE_CFG_L2BRIDGE_ENABLE)
/**
 * @brief       Assign L2 Bridge to the platform
 */
static errno_t pfe_platform_create_l2_bridge(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    uint16_t vlan_id = config->vlan_id;
    uint16_t vlan_stats_size = config->vlan_stats_size;
    errno_t ret;

    platform->mactab = pfe_l2br_table_create(platform->cbus_baseaddr, PFE_L2BR_TABLE_MAC2F);
    if (NULL == platform->mactab)
    {
        NXP_LOG_ERROR("Couldn't create MAC table instance\n");
        ret = ENODEV;
    }
    else
    {

        platform->vlantab = pfe_l2br_table_create(platform->cbus_baseaddr, PFE_L2BR_TABLE_VLAN);
        if (NULL == platform->vlantab)
        {
            NXP_LOG_ERROR("Couldn't create VLAN table instance\n");
            ret = ENODEV;
        }
        else
        {
            if((vlan_id == 0U) || (vlan_id >= 4095U))
            {
                NXP_LOG_WARNING("VLAN ID incorrect or not set. Using default VLAN ID = 0x01.\n");
                vlan_id = 0x01;
            }

            if ((vlan_stats_size < 2U) || (vlan_stats_size > 128U))
            {
                NXP_LOG_WARNING("VLAN stats size incorrect or not set. Using default VLAN stats size = 20.\n");
                vlan_stats_size = 20;
            }

            platform->l2_bridge = pfe_l2br_create(platform->classifier, vlan_id, 300U, vlan_stats_size, platform->mactab, platform->vlantab);
            if (NULL == platform->l2_bridge)
            {
                NXP_LOG_ERROR("Could not create L2 Bridge\n");
                ret = ENODEV;
            }
            else
            {
                ret = EOK;
            }
        }
    }

    return ret;
}

/**
 * @brief       Release L2 Bridge-related resources
 */
static void pfe_platform_destroy_l2_bridge(pfe_platform_t *platform)
{
    if (NULL != platform->l2_bridge)
    {
        (void)pfe_l2br_destroy(platform->l2_bridge);
        platform->l2_bridge = NULL;
    }

    if (NULL != platform->mactab)
    {
        platform->mactab = NULL;
    }

    if (NULL != platform->vlantab)
    {
        platform->vlantab = NULL;
    }
}
#endif /* PFE_CFG_L2BRIDGE_ENABLE */

#if defined(PFE_CFG_RTABLE_ENABLE)

/**
 * @brief       Assign Routing Table to the platform
 */
static errno_t pfe_platform_create_rtable(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    addr_t htable_mem;
    addr_t pool_mem;
    uint32_t pool_offs;
    errno_t ret;
    pfe_class_table_sizes_t temp_table;

    if (config->rtable_hash_size > PFE_CFG_RT_HASH_ENTRIES_MAX_CNT)
    {
        NXP_LOG_ERROR("Required HASH size exceeds allowed range.\n");
        ret = EINVAL;
    }
    else
    {
        pool_offs = config->rtable_hash_size * pfe_rtable_get_entry_size();

        platform->rtable_size = (config->rtable_hash_size + config->rtable_collision_size) * pfe_rtable_get_entry_size();
        platform->rtable_va = pfe_rtable_buffers;

        htable_mem = (addr_t)platform->rtable_va;
        pool_mem = (addr_t)platform->rtable_va + pool_offs;

        if (NULL == platform->classifier)
        {
            NXP_LOG_ERROR("Valid classifier instance required\n");
            ret = ENODEV;
        }
        else
        {
            temp_table.htable_base_va = htable_mem;
            temp_table.htable_size = config->rtable_hash_size;
            temp_table.pool_base_va = pool_mem;
            temp_table.pool_size = config->rtable_collision_size;
            platform->rtable = pfe_rtable_create(platform->classifier, platform->l2_bridge, temp_table);

            if (NULL == platform->rtable)
            {
                NXP_LOG_ERROR("Couldn't create routing table instance\n");
                ret = ENODEV;
            }
            else
            {
                NXP_LOG_INFO("Routing table created, Hash Table @ p0x%"PRINTADDR_T", Pool @ p0x%"PRINTADDR_T" (%u bytes)\n", (addr_t)oal_mm_virt_to_phys_contig((void *)htable_mem), (addr_t)oal_mm_virt_to_phys_contig((void *)htable_mem) + (addr_t)pool_offs, (uint_t)platform->rtable_size);
                ret = EOK;
            }
        }
    }
    return ret;
}

/**
 * @brief       Release Routing table-related resources
 */
static void pfe_platform_destroy_rtable(pfe_platform_t *platform)
{
    if (NULL != platform->rtable)
    {
        pfe_rtable_destroy(platform->rtable);
        platform->rtable = NULL;
    }

    platform->rtable_va = NULL;
}
#endif /* PFE_CFG_RTABLE_ENABLE */

/**
 * @brief       Assign TMU to the platform
 */
static errno_t pfe_platform_create_tmu(pfe_platform_t *platform)
{
    errno_t ret;
    pfe_tmu_cfg_t tmu_cfg =
    {
        .pe_sys_clk_ratio = PFE_CFG_CLMODE,
        .on_g3 = FALSE,
    };

    tmu_cfg.on_g3 = pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3);
    platform->tmu = pfe_tmu_create(platform->cbus_baseaddr, platform->tmu_pe_count, &tmu_cfg,
                                   platform->classifier);
    if (NULL == platform->tmu)
    {
        NXP_LOG_ERROR("Couldn't create TMU instance\n");
        ret = ENODEV;
    }
    else
    {
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Release TMU-related resources
 */
static void pfe_platform_destroy_tmu(pfe_platform_t *platform)
{
    if (NULL != platform->tmu)
    {
        pfe_tmu_destroy(platform->tmu);
        platform->tmu = NULL;
    }
}

/**
 * @brief       Create Default Util and Init Memory
 */
static errno_t pfe_platform_default_init_util(pfe_platform_t *platform)
{
    errno_t ret;
    pfe_util_cfg_t util_cfg =
    {
        .pe_sys_clk_ratio = PFE_CFG_CLMODE,
    };

    platform->util = pfe_util_create(platform->cbus_baseaddr, platform->util_pe_count, &util_cfg);

    if (NULL == platform->util)
    {
        NXP_LOG_ERROR("Couldn't create UTIL instance\n");
        ret = ENODEV;
    }
    else
    {
        ret = pfe_util_default_init(platform->util);
    }

    return ret;
}

/**
 * @brief       Assign UTIL to the platform
 */
static errno_t pfe_platform_create_util(pfe_platform_t *platform)
{
    errno_t ret;
    pfe_util_cfg_t util_cfg =
    {
        .pe_sys_clk_ratio = PFE_CFG_CLMODE,
        .on_g3 = FALSE,
    };

    util_cfg.on_g3 = pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3);
    platform->util = pfe_util_create(platform->cbus_baseaddr, platform->util_pe_count, &util_cfg);

    if (NULL == platform->util)
    {
        NXP_LOG_ERROR("Couldn't create UTIL instance\n");
        ret = ENODEV;
    }
    else
    {
        ELF_File_t elf;

        if (NULL == platform->fw->util_data)
        {
            NXP_LOG_WARNING("The UTIL firmware is not loaded\n");
            ret = EOK;
        }
        else
        {
            if (FALSE == ELF_Open(&elf, platform->fw->util_data))
            {
                NXP_LOG_ERROR("Can't parse UTIL firmware\n");
                ret = EIO;
            }
            else
            {
                NXP_LOG_INFO("Uploading UTIL firmware\n");
                ret = pfe_util_load_firmware(platform->util, &elf);

                ELF_Close(&elf);

                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Error during upload of UTIL firmware: %d\n", ret);
                    ret = EIO;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief       Release UTIL-related resources
 */
static void pfe_platform_destroy_util(pfe_platform_t *platform)
{
    if (NULL != platform->util)
    {
        pfe_util_destroy(platform->util);
        platform->util = NULL;
    }
}

/**
 * @brief       Assign EMAC to the platform
 */
static errno_t pfe_platform_create_emac(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    errno_t ret = EOK;

    /*  EMAC1 */
    platform->emac[0U] = pfe_emac_create(platform->cbus_baseaddr, CBUS_EMAC1_BASE_ADDR,
                            config->emac_mode[0U], EMAC_SPEED_1000_MBPS, EMAC_DUPLEX_FULL);
    if (NULL == platform->emac[0U])
    {
        NXP_LOG_ERROR("Couldn't create EMAC1 instance\n");
        ret = ENODEV;
    }
    else
    {
        (void)pfe_emac_set_max_frame_length(platform->emac[0U], 1522U);
        pfe_emac_enable_rx_flow_control(platform->emac[0U]);
        pfe_emac_enable_broadcast(platform->emac[0U]);

        /*  MAC address will be added with phy/log interface */
    }

    /*  EMAC2 */
    if (EOK == ret)
    {
        platform->emac[1U] = pfe_emac_create(platform->cbus_baseaddr, CBUS_EMAC2_BASE_ADDR,
                                config->emac_mode[1U], EMAC_SPEED_1000_MBPS, EMAC_DUPLEX_FULL);
        if (NULL == platform->emac[1U])
        {
            NXP_LOG_ERROR("Couldn't create EMAC2 instance\n");
            ret = ENODEV;
        }
        else
        {
            (void)pfe_emac_set_max_frame_length(platform->emac[1U], 1522U);
            pfe_emac_enable_rx_flow_control(platform->emac[1U]);
            pfe_emac_enable_broadcast(platform->emac[1U]);

            /*  MAC address will be added with phy/log interface */
        }
    }

    if (EOK == ret)
    {
        /*  EMAC3 */
        platform->emac[2U] = pfe_emac_create(platform->cbus_baseaddr, CBUS_EMAC3_BASE_ADDR,
                                config->emac_mode[2U], EMAC_SPEED_1000_MBPS, EMAC_DUPLEX_FULL);
        if (NULL == platform->emac[2U])
        {
            NXP_LOG_ERROR("Couldn't create EMAC3 instance\n");
            ret = ENODEV;
        }
        else
        {
            (void)pfe_emac_set_max_frame_length(platform->emac[2U], 1522U);
            pfe_emac_enable_rx_flow_control(platform->emac[2U]);
            pfe_emac_enable_broadcast(platform->emac[2U]);

            /*  MAC address will be added with phy/log interface */
        }
    }

    return ret;
}

#ifdef PFE_CFG_IEEE1588_SUPPORT
/**
 * @brief       Enable timestamping
 */
static void pfe_platform_enable_ts(pfe_platform_t *platform)
{
    if (EOK != pfe_emac_enable_ts(platform->emac[0U],
            PFE_CFG_IEEE1588_I_CLK_HZ, PFE_CFG_IEEE1588_EMAC0_O_CLK_HZ))
    {
        NXP_LOG_WARNING("EMAC0: Could not configure the timestamping unit\n");
    }
    else if (EOK != pfe_emac_enable_ts(platform->emac[1U],
            PFE_CFG_IEEE1588_I_CLK_HZ, PFE_CFG_IEEE1588_EMAC1_O_CLK_HZ))
    {
        NXP_LOG_WARNING("EMAC1: Could not configure the timestamping unit\n");
    }
    else if (EOK != pfe_emac_enable_ts(platform->emac[2U],
            PFE_CFG_IEEE1588_I_CLK_HZ, PFE_CFG_IEEE1588_EMAC2_O_CLK_HZ))
    {
        NXP_LOG_WARNING("EMAC2: Could not configure the timestamping unit\n");
    }
    else
    {
        /*Do nothing - Avoid MISRA rule 15.7 */
    }
}
#endif /* PFE_CFG_IEEE1588_SUPPORT */

/**
 * @brief       Release EMAC-related resources
 */
static void pfe_platform_destroy_emac(pfe_platform_t *platform)
{
    uint32_t ii;

    for (ii=0U; ii<platform->emac_count; ii++)
    {
        if (NULL != platform->emac[ii])
        {
            pfe_emac_destroy(platform->emac[ii]);
            platform->emac[ii] = NULL;
        }
    }
}

/**
 * @brief       Unmask parity and wdt irq
 */
static void pfe_platform_irq_unmask_parity_wdt(pfe_platform_t *platform)
{
    pfe_parity_irq_unmask(platform->parity);
    pfe_wdt_irq_unmask(platform->wdt);
}

/**
 * @brief       Unmask fails and errors irq
 */
static void pfe_platform_irq_unmask_fails_and_errors(pfe_platform_t *platform)
{
    pfe_bus_err_irq_unmask(platform->bus_err);
    pfe_fw_fail_stop_irq_unmask(platform->fw_fail_stop);
    pfe_host_fail_stop_irq_unmask(platform->host_fail_stop);
    pfe_fail_stop_irq_unmask(platform->fail_stop);
    pfe_ecc_err_irq_unmask(platform->ecc_err);
}

/**
 * @brief       Assign PFE_ERRORS to the platform
 */
static errno_t pfe_platform_create_failures(pfe_platform_t *platform,addr_t cbus_base_va, addr_t parity_base)
{
    errno_t ret = EOK;
    /*  Bus Errors */
    platform->bus_err = pfe_bus_err_create(cbus_base_va, parity_base);

    if (NULL == platform->bus_err)
    {
        NXP_LOG_ERROR("Couldn't create PFE_ERRORS:Bus Error instance\n");
        ret = ENODEV;
    }
    else
    {
        NXP_LOG_INFO("PFE_ERRORS:Bus Error instance created\n");
    }

    /*  FW Fail Stop */
    platform->fw_fail_stop = pfe_fw_fail_stop_create(cbus_base_va, parity_base);

    if (NULL == platform->fw_fail_stop)
    {
        NXP_LOG_ERROR("Couldn't create PFE_ERRORS:FW Fail Stop instance\n");
        ret = ENODEV;
    }
    else
    {
        NXP_LOG_INFO("PFE_ERRORS:FW Fail Stop instance created\n");
    }

    /*  Host Fail Stop */
    platform->host_fail_stop = pfe_host_fail_stop_create(cbus_base_va, parity_base);

    if (NULL == platform->host_fail_stop)
    {
        NXP_LOG_ERROR("Couldn't create PFE_ERRORS:Host Fail Stop instance\n");
        ret = ENODEV;
    }
    else
    {
        NXP_LOG_INFO("PFE_ERRORS:Host Fail Stop instance created\n");
    }

    /*  Fail Stop */
    platform->fail_stop = pfe_fail_stop_create(cbus_base_va, parity_base);

    if (NULL == platform->fail_stop)
    {
        NXP_LOG_ERROR("Couldn't create PFE_ERRORS:Fail Stop instance\n");
        ret = ENODEV;
    }
    else
    {
        NXP_LOG_INFO("PFE_ERRORS:Fail Stop instance created\n");
    }

    /*  ECC Error */
    platform->ecc_err = pfe_ecc_err_create(cbus_base_va, parity_base);

    if (NULL == platform->ecc_err)
    {
        NXP_LOG_ERROR("Couldn't create PFE_ERRORS:ECC Err instance\n");
        ret = ENODEV;
    }
    else
    {
        NXP_LOG_INFO("PFE_ERRORS:ECC Err instance created\n");
    }

    return ret;
}
/**
 * @brief       Assign PFE_ERRORS to the platform
 */
static errno_t pfe_platform_create_pfe_errors(pfe_platform_t *platform, const pfe_platform_config_t *config)
{
    errno_t ret = EOK;
    bool_t bFeatureOnG3;
    (void)config;

    /*  Parity */
    platform->parity = pfe_parity_create(platform->cbus_baseaddr, CBUS_GLOBAL_CSR_BASE_ADDR);

    if (NULL == platform->parity)
    {
        NXP_LOG_ERROR("Couldn't create PFE_ERRORS:Parity instance\n");
        ret = ENODEV;
    }
    else
    {
        NXP_LOG_INFO("PFE_ERRORS:Parity instance created\n");
    }

    if (EOK == ret)
    {
        /*  Watchdogs */
        platform->wdt = pfe_wdt_create(platform->cbus_baseaddr, CBUS_GLOBAL_CSR_BASE_ADDR);

        if (NULL == platform->wdt)
        {
            NXP_LOG_ERROR("Couldn't create PFE_ERRORS:Watchdog instance\n");
            ret = ENODEV;
        }
        else
        {
            NXP_LOG_INFO("PFE_ERRORS:Watchdog instance created\n");
        }
    }

    bFeatureOnG3 = pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3);
    if ((EOK == ret) && (TRUE == bFeatureOnG3))
    {
        ret = pfe_platform_create_failures(platform,platform->cbus_baseaddr, CBUS_GLOBAL_CSR_BASE_ADDR);
    }

    if (EOK == ret)
    {
        pfe_platform_irq_unmask_parity_wdt(platform);

        if (TRUE == pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3))
        {
            pfe_platform_irq_unmask_fails_and_errors(platform);
        }
    }

    return ret;
}

/**
 * @brief       Release PFE_ERRORS-related resources
 */
static void pfe_platform_destroy_pfe_errors(pfe_platform_t *platform)
{
    if (NULL != platform->ecc_err)
    {
        pfe_ecc_err_destroy(platform->ecc_err);
        platform->ecc_err = NULL;
    }

    if (NULL != platform->fail_stop)
    {
        pfe_fail_stop_destroy(platform->fail_stop);
        platform->fail_stop = NULL;
    }

    if (NULL != platform->host_fail_stop)
    {
        pfe_host_fail_stop_destroy(platform->host_fail_stop);
        platform->host_fail_stop = NULL;
    }

    if (NULL != platform->fw_fail_stop)
    {
        pfe_fw_fail_stop_destroy(platform->fw_fail_stop);
        platform->fw_fail_stop = NULL;
    }

    if (NULL != platform->bus_err)
    {
        pfe_bus_err_destroy(platform->bus_err);
        platform->bus_err = NULL;
    }

    if (NULL != platform->parity)
    {
        pfe_parity_destroy(platform->parity);
        platform->parity = NULL;
    }

    if (NULL != platform->wdt)
    {
        pfe_wdt_destroy(platform->wdt);
        platform->wdt = NULL;
    }
}

#ifdef PFE_CFG_FCI_ENABLE
/**
 * @brief       Start the FCI endpoint
 *
 */
static errno_t pfe_platform_create_fci(pfe_platform_t *platform)
{
    fci_init_info_t fci_init_info;
    errno_t ret;

#if defined(PFE_CFG_RTABLE_ENABLE)
    fci_init_info.rtable = platform->rtable;
#endif /* PFE_CFG_RTABLE_ENABLE */
#if defined(PFE_CFG_L2BRIDGE_ENABLE)
    fci_init_info.l2_bridge = platform->l2_bridge;
#endif /* PFE_CFG_L2BRIDGE_ENABLE */
    fci_init_info.class = platform->classifier;
    fci_init_info.phy_if_db = platform->phy_if_db;
    fci_init_info.log_if_db = platform->log_if_db;
    fci_init_info.tmu = platform->tmu;
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    fci_init_info.hif_fci_owner_chnls_mask = platform->hif_fci_owner_chnls_mask;
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
    ret = fci_init(&fci_init_info, "pfe_fci");
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Could not create the FCI endpoint\n");
    }
    else
    {
        platform->fci_created = TRUE;
    }

    return ret;
}

/**
 * @brief       Release FCI-related resources
 */
static void pfe_platform_destroy_fci(pfe_platform_t *platform)
{
    fci_fini();
    platform->fci_created = FALSE;
}
#endif /* PFE_CFG_FCI_ENABLE */

/**
 * @brief       Register physical interface
 * @details     Function will crate mapping table between physical interface IDs and
 *              instances and add the physical interface instance with various validity
 *              checks.
 */
static errno_t pfe_platform_register_phy_if(uint32_t session_id, pfe_phy_if_t *phy_if)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == phy_if))
    {
        NXP_LOG_ERROR("Null argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Owner of the interface is local driver instance */
        ret = pfe_if_db_add(pfe.phy_if_db, session_id, phy_if, PFE_CFG_LOCAL_IF);
    }

    return ret;
}

/**
 * @brief       Get physical interface by its ID
 * @param[in]   platform Platform instance
 * @param[in]   id Physical interface ID
 * @return      Physical interface instance or NULL if failed.
 */
pfe_phy_if_t *pfe_platform_get_phy_if_by_id(const pfe_platform_t *platform, pfe_ct_phy_if_id_t id)
{
    pfe_if_db_entry_t *entry = NULL;
    uint32_t session_id = 0U;
    pfe_phy_if_t *phyif;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == platform))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        phyif = NULL;
    }
    else if (unlikely(NULL == platform->phy_if_db))
    {
        NXP_LOG_ERROR("Physical interface DB not found\n");
        phyif = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (EOK != pfe_if_db_lock(&session_id))
        {
            NXP_LOG_DEBUG("DB lock failed\n");
        }

        (void)pfe_if_db_get_first(platform->phy_if_db, session_id, IF_DB_CRIT_BY_ID, (void *)(addr_t)id, &entry);

        if (EOK != pfe_if_db_unlock(session_id))
        {
            NXP_LOG_DEBUG("DB unlock failed\n");
        }

        phyif = pfe_if_db_entry_get_phy_if(entry);

    }
    return phyif;
}

/**
 * @brief       Add a default LOG_IF to a PHY_IF.
 */
static errno_t pfe_platform_create_default_log_if(pfe_phy_if_t *phy_if, const char *if_name, uint32_t session_id)
{
    pfe_log_if_t *log_if = pfe_log_if_create(phy_if, if_name);
    errno_t ret = ENODEV;
    
    if (NULL == log_if)
    {
        NXP_LOG_ERROR("Couldn't create LOG_IF for %s\n", if_name);
        
    }
    else if (EOK != pfe_if_db_add(pfe.log_if_db, session_id, log_if, PFE_CFG_LOCAL_IF))
    {
        NXP_LOG_ERROR("Could not register LOG_IF %s\n", if_name);
        pfe_log_if_destroy(log_if);
    }
    else if (EOK != pfe_log_if_promisc_enable(log_if))
    {
        NXP_LOG_ERROR("Could not configure LOG_IF %s\n", if_name);
        pfe_log_if_destroy(log_if);
    }
    else
    {
        /* Enable default LOG_IF */
        ret = pfe_log_if_enable(log_if);
    }
    return ret;
}

/**
 * @brief       Bind HIF to the platform and add default log_if
 */
static errno_t pfe_platform_prepare_phy_if_hif(pfe_phy_if_t *phy_if, const pfe_platform_pfy_if *p_phy_ifs, uint32_t session_id)
{
    errno_t ret = EOK;

    /*  If the HIF channel is managed by this driver instance */
    if (NULL != p_phy_ifs->phy.chnl)
    {
        /*  Bind HIF channel instance with the physical IF */
        if (EOK != pfe_phy_if_bind_hif(phy_if, p_phy_ifs->phy.chnl))
        {
            NXP_LOG_ERROR("Can't bind interface with HIF (%s)\n", p_phy_ifs->name);
            ret = ENODEV;
        }
    }
    if (EOK == ret)
    {
        if (EOK != pfe_platform_create_default_log_if(phy_if, p_phy_ifs->name, session_id))
        {
            NXP_LOG_ERROR("Can't create default log_if for %s\n", p_phy_ifs->name);
            ret = ENODEV;
        }
    }

    return ret;
}

/**
 * @brief       Bind EMAC to the platform and add default log_if
 */
static errno_t pfe_platform_prepare_phy_if_emac(pfe_phy_if_t *phy_if, const pfe_platform_pfy_if *p_phy_ifs, uint32_t session_id)
{
    errno_t ret = ENODEV;

    /*  Bind EMAC instance with the physical IF */
    if (EOK != pfe_phy_if_bind_emac(phy_if, p_phy_ifs->phy.emac))
    {
        NXP_LOG_ERROR("Can't bind interface with EMAC (%s)\n", p_phy_ifs->name);
    }
    /* provide gpi handle to emac: emac phy_ifs need access to gpi to configure Ingress QoS */
    else if (EOK != pfe_emac_bind_gpi(p_phy_ifs->phy.emac, p_phy_ifs->phy.gpi))
    {
        NXP_LOG_ERROR("Can't bind interface with GPI (%s)\n", p_phy_ifs->name);
    }
    else if (EOK != pfe_platform_create_default_log_if(phy_if, p_phy_ifs->name, session_id))
    {
        NXP_LOG_ERROR("Can't create default log_if for %s\n", p_phy_ifs->name);
    }
    else
    {
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Prepare and configure a phy_if
 */
static errno_t pfe_platform_prepare_phy_if(pfe_phy_if_t *phy_if, const pfe_platform_pfy_if *p_phy_ifs, uint32_t session_id)
{
    errno_t ret = EOK;
    pfe_ct_phy_if_id_t phy_if_id;

    /*  Set default operation mode */
    if (EOK != pfe_phy_if_set_op_mode(phy_if, IF_OP_DEFAULT))
    {
        NXP_LOG_ERROR("Could not set default operational mode (%s)\n", p_phy_ifs->name);
        ret = ENODEV;
    }
    else
    {
        phy_if_id = pfe_phy_if_get_id(phy_if);
        if ((phy_if_id == PFE_PHY_IF_ID_EMAC0)
         || (phy_if_id == PFE_PHY_IF_ID_EMAC1)
         || (phy_if_id == PFE_PHY_IF_ID_EMAC2))
        {
            ret = pfe_platform_prepare_phy_if_emac(phy_if, p_phy_ifs, session_id);
        }
        else if (phy_if_id == PFE_PHY_IF_ID_UTIL)
        {
            /* All actions on UTIL PHY will not do anything. */
            /* This phy is only present to allow adding new logical interfaces. */
            if (EOK != pfe_phy_if_bind_util(phy_if))
            {
                NXP_LOG_ERROR("Can't initialize UTIL PHY (%s)\n", p_phy_ifs->name);
                ret = ENODEV;
            }
        }
        else
        {
            /*  Bind HIF channel instance with the physical IF */
            ret = pfe_platform_prepare_phy_if_hif(phy_if, p_phy_ifs, session_id);
        }

        /*  Register in platform */
        if (EOK == ret) 
        {
            if (EOK != pfe_platform_register_phy_if(session_id, phy_if))
            {
                NXP_LOG_ERROR("Could not register %s\n", pfe_phy_if_get_name(phy_if));
                ret = ENODEV;
            }
        }
    }
    return ret;
}

/**
 * @brief       Assign interfaces to the platform.
 */
static errno_t pfe_platform_bind_ifaces(void)
{
    errno_t ret = EOK;
    int32_t ii;
    pfe_phy_if_t *phy_if = NULL;
    uint32_t session_id = 0U;
    pfe_if_db_entry_t *entry = NULL;
    pfe_hif_chnl_t *channel_hif0 = NULL;
    pfe_hif_chnl_t *channel_hif1 = NULL;
    pfe_hif_chnl_t *channel_hif2 = NULL;
    pfe_hif_chnl_t *channel_hif3 = NULL;
    pfe_hif_chnl_t *channel_hifncpy = NULL;

    channel_hif0 = pfe_hif_get_channel(pfe.hif, HIF_CHNL_0);
    channel_hif1 = pfe_hif_get_channel(pfe.hif, HIF_CHNL_1);
    channel_hif2 = pfe_hif_get_channel(pfe.hif, HIF_CHNL_2);
    channel_hif3 = pfe_hif_get_channel(pfe.hif, HIF_CHNL_3);
    channel_hifncpy = pfe_hif_nocpy_get_channel(pfe.hif_nocpy, PFE_HIF_CHNL_NOCPY_ID);

    const pfe_platform_pfy_if phy_ifs[] =
    {
            {.name = "emac0", .id = PFE_PHY_IF_ID_EMAC0, .mac = GEMAC0_MAC, {.emac = pfe.emac[0], .gpi = pfe.gpi[0], .chnl = NULL}},
            {.name = "emac1", .id = PFE_PHY_IF_ID_EMAC1, .mac = GEMAC1_MAC, {.emac = pfe.emac[1], .gpi = pfe.gpi[1], .chnl = NULL}},
            {.name = "emac2", .id = PFE_PHY_IF_ID_EMAC2, .mac = GEMAC2_MAC, {.emac = pfe.emac[2], .gpi = pfe.gpi[2], .chnl = NULL}},
            {.name = "util", .id = PFE_PHY_IF_ID_UTIL, .mac = {0}, {.emac = NULL, .gpi = NULL, .chnl = NULL}},
            {.name = "hif0", .id = PFE_PHY_IF_ID_HIF0, .mac = {0}, {.emac = NULL, .gpi = NULL, .chnl = channel_hif0}},
            {.name = "hif1", .id = PFE_PHY_IF_ID_HIF1, .mac = {0}, {.emac = NULL, .gpi = NULL, .chnl = channel_hif1}},
            {.name = "hif2", .id = PFE_PHY_IF_ID_HIF2, .mac = {0}, {.emac = NULL, .gpi = NULL, .chnl = channel_hif2}},
            {.name = "hif3", .id = PFE_PHY_IF_ID_HIF3, .mac = {0}, {.emac = NULL, .gpi = NULL, .chnl = channel_hif3}},
            {.name = "hifncpy", .id = PFE_PHY_IF_ID_HIF_NOCPY, .mac = {0}, {.emac = NULL, .gpi = NULL, .chnl = channel_hifncpy}},
            {.name = NULL, .id = PFE_PHY_IF_ID_INVALID, .mac = {0}, {NULL, NULL, NULL}}
    };

    if (EOK != pfe_if_db_lock(&session_id))
    {
        NXP_LOG_ERROR("DB lock failed\n");
    }

    /*  Create interfaces */
    for (ii=0; phy_ifs[ii].id!=PFE_PHY_IF_ID_INVALID; ii++)
    {
        /*  Check if physical IF with given ID is already registered. We need
            only one local instance per PHY IF. */
        (void)pfe_if_db_get_first(pfe.phy_if_db, session_id, IF_DB_CRIT_BY_ID, (void *)(addr_t)phy_ifs[ii].id, &entry);
        if (NULL != entry)
        {
            /*  Duplicate found */
            continue;
        }

        /*  Create physical IF */
        phy_if = pfe_phy_if_create(pfe.classifier, phy_ifs[ii].id, phy_ifs[ii].name);
        if (NULL == phy_if)
        {
            NXP_LOG_ERROR("Couldn't create %s\n", phy_ifs[ii].name);
            ret = ENODEV;
            break;
        }
        else
        {
            ret = pfe_platform_prepare_phy_if(phy_if, &phy_ifs[ii], session_id);
            if(EOK != ret)
            {
                pfe_phy_if_destroy(phy_if);
                break;
            }
        }
    }

    if (EOK != pfe_if_db_unlock(session_id))
    {
        NXP_LOG_ERROR("DB unlock failed\n");
    }

    return ret;
}

/**
 * @brief       Assign interfaces to the platform.
 */
static errno_t pfe_platform_create_ifaces(void)
{
    errno_t ret = EOK;

    /*  Create interface databases */
    if (NULL == pfe.log_if_db)
    {
        pfe.log_if_db = pfe_if_db_create(PFE_IF_DB_LOG);
        if (NULL == pfe.log_if_db)
        {
            NXP_LOG_DEBUG("Can't create logical interface DB\n");
            ret = ENODEV;
        }
        else
        {
          (void)pfe_log_ifs_init();
        }
    }
    if (EOK == ret)
    {
        if (NULL == pfe.phy_if_db)
        {
            pfe.phy_if_db = pfe_if_db_create(PFE_IF_DB_PHY);
            if (NULL == pfe.phy_if_db)
            {
                NXP_LOG_DEBUG("Can't create physical interface DB\n");
                ret = ENODEV;
            }
            else
            {
                ret = pfe_platform_bind_ifaces();
            }
        }
    }

    return ret;
}

static void pfe_platform_destroy_pfe_log_ifs(pfe_platform_t *platform)
{
    pfe_if_db_entry_t *entry = NULL;
    pfe_log_if_t *log_if;
    uint32_t session_id = 0U;
    errno_t ret;

    /*lock database*/
    if(EOK != pfe_if_db_lock(&session_id))
    {
        NXP_LOG_DEBUG("DB lock failed\n");
    }

    /*get first entry*/
    ret = pfe_if_db_get_first(platform->log_if_db, session_id, IF_DB_CRIT_ALL, NULL, &entry);

    /*remove all entries*/
    while (NULL != entry)
    {
        log_if = pfe_if_db_entry_get_log_if(entry);

        if (EOK != pfe_if_db_remove(platform->log_if_db, session_id, entry))
        {
            NXP_LOG_DEBUG("Could not remove log_if DB entry\n");
        }

        /*remove the entry*/
        pfe_log_if_destroy(log_if);
        entry = NULL;

        /*get next entry*/
        ret = pfe_if_db_get_next(platform->log_if_db, session_id, &entry);
    }

    if(EOK != ret)
    {
        NXP_LOG_DEBUG("Could not remove log_if DB entry, DB was locked\n");
    }

    if(EOK != pfe_if_db_unlock(session_id))
    {
        NXP_LOG_DEBUG("DB unlock failed\n");
    }

    if (NULL != platform->log_if_db)
    {
        pfe_if_db_destroy(platform->log_if_db);
        platform->log_if_db = NULL;
    }
}

static void pfe_platform_destroy_pfe_phy_ifs(pfe_platform_t *platform)
{
    pfe_if_db_entry_t *entry = NULL;
    pfe_phy_if_t *phy_if;
    uint32_t session_id = 0U;
    errno_t ret;

    /*lock database*/
    if(EOK != pfe_if_db_lock(&session_id))
    {
        NXP_LOG_DEBUG("DB lock failed\n");
    }
    /*get first entry*/
    ret = pfe_if_db_get_first(platform->phy_if_db, session_id, IF_DB_CRIT_ALL, NULL, &entry);

    while (NULL != entry)
    {
        phy_if = pfe_if_db_entry_get_phy_if(entry);

        if (EOK != pfe_if_db_remove(platform->phy_if_db, session_id, entry))
        {
            NXP_LOG_DEBUG("Could not remove phy_if DB entry\n");
        }

        /*remove the entry*/
        pfe_phy_if_destroy(phy_if);
        phy_if = NULL;
        entry = NULL;
        /*get next entry*/
        ret = pfe_if_db_get_next(platform->phy_if_db, session_id, &entry);
    }

    if(EOK != ret)
    {
        NXP_LOG_DEBUG("Could not remove log_if DB entry, DB was locked\n");
    }

    if(EOK != pfe_if_db_unlock(session_id))
    {
        NXP_LOG_DEBUG("DB unlock failed\n");
    }

    if (NULL != platform->phy_if_db)
    {
        pfe_if_db_destroy(platform->phy_if_db);
        platform->phy_if_db = NULL;
    }
}

/**
 * @brief       Release interface-related resources
 */
static void pfe_platform_destroy_ifaces(pfe_platform_t *platform)
{
    if (NULL != platform->log_if_db)
    {
        pfe_platform_destroy_pfe_log_ifs(platform);

        pfe_log_ifs_deinit();
    }

    if (NULL != platform->phy_if_db)
    {
        pfe_platform_destroy_pfe_phy_ifs(platform);
    }
}

/**
 * @brief       Perform PFE soft reset
 */
errno_t pfe_platform_soft_reset(const pfe_platform_t *platform)
{
    addr_t addr_gen, addr_dbug;
    uint32_t regval;
    bool_t run_on_g3 = FALSE;
    uint32_t timeout = 1000U;
    errno_t ret = EOK;

    (void)platform;

    if (TRUE == pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3))
    {
        run_on_g3 = TRUE;
    }

    addr_gen = (addr_t)(pfe.cbus_baseaddr) + CBUS_GLOBAL_CSR_BASE_ADDR + WSP_SYS_GENERIC_CONTROL;
    regval = hal_read32(addr_gen);

    /* Clear the soft reset done */
    if (TRUE == run_on_g3)
    {
        regval |= WSP_SYS_GEN_SOFT_RST_DONE_CLR_MASK_G3;
        hal_write32(regval, addr_gen);
        regval &= ~WSP_SYS_GEN_SOFT_RST_DONE_CLR_MASK_G3;
        hal_write32(regval, addr_gen);
    }

    /* Set bit '30' to perform soft reset */
    regval |= WSP_SYS_GEN_SOFT_RST_BIT;
    hal_write32(regval, addr_gen);

    if (TRUE == run_on_g3)
    {
        /* Wait for soft reset done */
        addr_dbug = (addr_t)(pfe.cbus_baseaddr) + CBUS_GLOBAL_CSR_BASE_ADDR + WSP_DBUG_BUS1_G3;
        do
        {
            regval = hal_read32(addr_dbug) & WSP_DBUG_BUS1_SOFT_RST_DONE_BIT_G3;
            timeout--;
        }while ((WSP_DBUG_BUS1_SOFT_RST_DONE_BIT_G3 != regval) && (0U != timeout));

        if (0U == timeout)
        {
            NXP_LOG_INFO("Soft reset done indication timeouted\n");
            ret = ETIMEDOUT;
        }
        else
        {
            regval = hal_read32(addr_gen);
            regval &= ~WSP_SYS_GEN_SOFT_RST_BIT;
            regval |= WSP_SYS_GEN_SOFT_RST_DONE_CLR_MASK_G3;
            hal_write32(regval, addr_gen);
            regval &= ~WSP_SYS_GEN_SOFT_RST_DONE_CLR_MASK_G3;
            hal_write32(regval, addr_gen);
        }
    }
    else
    {
        oal_time_usleep(5U);
        regval &= ~WSP_SYS_GEN_SOFT_RST_BIT;
        hal_write32(regval, addr_gen);
    }

    return ret;
}

#ifdef NXP_LOG_ENABLED
/**
 * @brief   Print PFE FW features available on this target. For debug purposes only.
 */
static void pfe_platform_print_features(void)
{
    const char *feature_name;
    errno_t ret;

    ret = pfe_feature_mgr_get_first(&feature_name);
    while (EOK == ret)
    {
        NXP_LOG_INFO("Detected FW feature: %s\n", feature_name);
        ret = pfe_feature_mgr_get_next(&feature_name);
    }
}
#endif  /* NXP_LOG_ENABLED */

/**
 * @brief   Helper function to the platform init function part_1
 */
static errno_t pfe_platform_create_gpis_add_modules(const pfe_platform_config_t *config)
{
    errno_t ret = EOK;

    /*  Make sure all HIF/HIF_NOCPY chnl DMAs are disabled before the soft reset */
    pfe_hif_cfg_stop_all_chnl_dma();
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    pfe_hif_nocpy_cfg_stop_all_chnl_dma();
#endif

    /*  SOFT RESET */
    if (EOK != pfe_platform_soft_reset(&pfe))
    {
        NXP_LOG_ERROR("Platform reset failed\n");
    }

    /* Initialize the FW features */
    ret = pfe_feature_mgr_add_modules(pfe.classifier, pfe.util, pfe.tmu);
    if (EOK != ret)
    {
        (void)pfe_platform_remove();
    }
    else
    {
#ifdef NXP_LOG_ENABLED
        pfe_platform_print_features();
#endif

        /*  GPI */
        ret = pfe_platform_create_gpi(&pfe, config);
        if (EOK != ret)
        {
            (void)pfe_platform_remove();
        }
        else
        {
            /*  HGPI */
            ret = pfe_platform_create_hgpi(&pfe);
            if (EOK != ret)
            {
                (void)pfe_platform_remove();
            }
        }
    }

    return ret;
}
/**
 * @brief   Helper function to the platform init function part_1
 */
static errno_t pfe_platform_create_err_bmu_class_tmu_emac_util(const pfe_platform_config_t *config)
{
    errno_t ret = EOK;

    /*  PFE_ERRORS */
    ret = pfe_platform_create_pfe_errors(&pfe, config);
    if (EOK == ret)
    {
        /*  BMU */
        ret = pfe_platform_create_bmu(&pfe, config);
        if (EOK == ret)
        {
            /*  Classifier */
            ret = pfe_platform_create_class(&pfe, config);
            if (EOK == ret)
            {
                /*  TMU */
                ret = pfe_platform_create_tmu(&pfe);
                if (EOK == ret)
                {
                    /*  EMAC */
                    ret = pfe_platform_create_emac(&pfe, config);
                    if (EOK == ret)
                    {
                        if(config->enable_util)
                        {
                            /*  UTIL */
                            ret = pfe_platform_create_util(&pfe);
                        }
                        else
                        {
                            NXP_LOG_DEBUG("Util is not enabled but initializing Util Mem now..");
                            (void)pfe_platform_default_init_util(&pfe);
                            pfe_util_destroy(pfe.util);
                            pfe.util = NULL;
                        }
                    }
                }
            }
        }
    }
    if (EOK != ret)
    {
        (void)pfe_platform_remove();
    }
    return ret;
}

/**
 * @brief   The platform init function part_1
 */
static errno_t pfe_platform_init_hm_fw_features(const pfe_platform_config_t *config)
{
    errno_t ret = EOK;
    uint32_t *addr;
    /*  Prevent LMEM initialization loop optimization to autolibc_memset() at -O3 */
    volatile uint32_t *ii;

    (void)autolibc_memset(&pfe, 0, sizeof(pfe_platform_t));
    pfe.fci_created = FALSE;

    pfe.fw = config->fw;

    /*  Map CBUS address space */
    pfe.cbus_baseaddr = (addr_t)oal_mm_dev_map((void *)config->cbus_base, config->cbus_len);
    if (NULL_ADDR == pfe.cbus_baseaddr)
    {
        NXP_LOG_ERROR("Can't map PPFE CBUS\n");
        ret = EINVAL;
        (void)pfe_platform_remove();
    }
    else
    {
        NXP_LOG_INFO("PFE CBUS p0x%"PRINTADDR_T" mapped @ v0x%"PRINTADDR_T"\n", config->cbus_base, pfe.cbus_baseaddr);

        /* Get PFE Version */
        pfe.pfe_version = *(uint32_t*)(void*)((addr_t)pfe.cbus_baseaddr + CBUS_GLOBAL_CSR_BASE_ADDR + WSP_VERSION);
        NXP_LOG_INFO("HW version 0x%x\n", (uint_t)pfe.pfe_version);

        /* Initialize the features */
        ret = pfe_feature_mgr_init((void *)pfe.cbus_baseaddr);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Initialize the features failed.\n");
            (void)pfe_platform_remove();
        }
        else
        {
            if (TRUE == pfe_feature_mgr_is_available(PFE_HW_FEATURE_RUN_ON_G3))
            {
                NXP_LOG_WARNING("Fail-Stop mode disabled\n");
                addr = (void *)(CBUS_GLOBAL_CSR_BASE_ADDR + WSP_FAIL_STOP_MODE_INT_EN + (addr_t)(pfe.cbus_baseaddr));
                hal_write32(0x0, addr);
                addr = (void *)(CBUS_GLOBAL_CSR_BASE_ADDR + WSP_FAIL_STOP_MODE_EN + (addr_t)(pfe.cbus_baseaddr));
                hal_write32(0x0, addr);
                addr = (void *)(CBUS_GLOBAL_CSR_BASE_ADDR + WSP_ECC_ERR_INT_EN + (addr_t)(pfe.cbus_baseaddr));
                hal_write32(0x0, addr);
            }

            addr = (uint32_t*)(void*)((addr_t)pfe.cbus_baseaddr + CBUS_LMEM_BASE_ADDR);
            for (ii = addr; ((addr_t)ii - (addr_t)addr) < CBUS_LMEM_SIZE; ++ii)
            {
                *ii = 0U;
            }

            /*  Create HW components */
            pfe.emac_count = 3U;
            pfe.gpi_count = 3U;
            pfe.etgpi_count = 3U;
            pfe.hgpi_count = 1U;
            pfe.bmu_count = 2U;
            pfe.class_pe_count = 8U;
            pfe.util_pe_count = 1U;
            pfe.tmu_pe_count = 0U;

            /* Health monitor */
            pfe_hm_init();

            ret = pfe_platform_create_err_bmu_class_tmu_emac_util(config);
            if (EOK == ret)
            {
                ret = pfe_platform_create_gpis_add_modules(config);
            }
        }
    }

    /* Remove pointer to firmware binary to support memory reuse */
    if (pfe.fw != NULL)
    {
        pfe.fw->class_data = NULL;
        pfe.fw->util_data = NULL;
    }
    pfe.fw = NULL;

    return ret;
}

/**
 * @brief   The platform init function part_3
 */
static errno_t pfe_platform_init_etgpi_l2br_rtable_hifs(const pfe_platform_config_t *config)
{
    errno_t ret = EOK;

    /*ETGPI*/
    ret = pfe_platform_create_etgpi(&pfe);
    if (EOK != ret)
    {
        (void)pfe_platform_remove();
    }
    else
    {
#ifdef PFE_CFG_FCI_ENABLE
#if defined(PFE_CFG_L2BRIDGE_ENABLE)
        /*L2 Bridge. Must be initialized after soft reset.*/
        ret = pfe_platform_create_l2_bridge(&pfe, config);
        if (EOK != ret)
        {
            (void)pfe_platform_remove();
        }
        else
#else
        pfe.l2_bridge = NULL_PTR;
#endif      /*PFE_CFG_L2BRIDGE_ENABLE*/
        {
#if defined(PFE_CFG_RTABLE_ENABLE)
            /*Routing Table*/
            ret = pfe_platform_create_rtable(&pfe, config);
            if (EOK != ret)
            {
                 (void)pfe_platform_remove();
            }
            else
#endif      /*PFE_CFG_RTABLE_ENABLE*/
#endif      /*PFE_CFG_FCI_ENABLE*/
            {
#if !defined(PFE_CFG_L2BRIDGE_ENABLE)
                ret = pfe_platform_init_l2br_mem(&pfe);
                if (EOK != ret)
                {
                    (void)pfe_platform_remove();
                }
                else
#endif      /*PFE_CFG_L2BRIDGE_ENABLE*/
                {
                /*HIF*/
                    ret = pfe_platform_create_hif(&pfe, config);
                    if (EOK != ret)
                    {
                         (void)pfe_platform_remove();
                    }
                    else
                    {
                        /*HIF NOCPY*/
                        ret = pfe_platform_create_hif_nocpy(&pfe);
                        if (EOK != ret)
                        {
                             (void)pfe_platform_remove();
                        }
                    }
                }
            }
#ifdef PFE_CFG_FCI_ENABLE
        }
#endif      /*PFE_CFG_FCI_ENABLE*/
    }
    return ret;
}

/**
 * @brief   The platform init function part_4
 */
static errno_t pfe_platform_init_tmu_mirror_queue_ifaces_fci(void)
{
    errno_t ret = EOK;

    /* Reset TMU prior to err051211_workaround manipulation */
    ret = pfe_tmu_queue_reset_tail_drop_policy(pfe.tmu);
    if (EOK != ret)
    {
        (void)pfe_platform_remove();
    }
    else
    {
        /* Errata 051211 */
        if (TRUE == pfe_feature_mgr_is_available("err051211_workaround"))
        {
            uint8_t flg = 0U;

#ifndef PFE_CFG_ERR051211_WORKAROUND_ENABLE
            /*  Deactivate in non Master-Slave build */
            if (EOK != pfe_feature_mgr_set_val("err051211_workaround", 0U))
            {
                NXP_LOG_WARNING("Error disabling err051211_workaround feature\n");
            }
#endif /* PFE_CFG_ERR051211_WORKAROUND_ENABLE */

            ret = pfe_feature_mgr_get_val("err051211_workaround", &flg);
            if (EOK == ret)
            {
                NXP_LOG_INFO("Feature err051211_workaround: %s\n", (0U == flg ? "DISABLED" : "ENABLED"));
            }
            else
            {
                NXP_LOG_ERROR("Feature err051211_workaround status unknown\n");
            }

            /* Check HIF RX Ring size in relation to err051211_workaround. */
            if (PFE_HIF_RX_RING_CFG_LENGTH < PFE_TMU_ERR051211_MINIMAL_REQUIRED_RX_RING_LENGTH)
            {
                NXP_LOG_WARNING("HIF RX Rings are too small for FW feature err051211_workaround to fully work.");
                NXP_LOG_WARNING("The feature requires HIF RX Rings with at least %u slots, but rings currently have only %u slots.",
                                (uint_t)PFE_TMU_ERR051211_MINIMAL_REQUIRED_RX_RING_LENGTH, (uint_t)PFE_HIF_RX_RING_CFG_LENGTH);
            }
        }
        else
        {
            NXP_LOG_ERROR("Feature err051211_workaround is not supported in firmware\n");
        }

        ret = pfe_mirror_init(pfe.classifier);
        if (EOK != ret)
        {
            (void)pfe_platform_remove();
        }
        else
        {
            /*  Interfaces */
            ret = pfe_platform_create_ifaces();
            if (EOK != ret)
            {
                (void)pfe_platform_remove();
            }
            else
            {
                pfe.poller_state = POLLER_STATE_DISABLED;

#ifdef PFE_CFG_FCI_ENABLE
                ret = pfe_platform_create_fci(&pfe);
                if (EOK != ret)
                {
                    (void)pfe_platform_remove();
                }
#endif /* PFE_CFG_FCI_ENABLE */
            }
        }
    }
    return ret;
}

/**
 * @brief   The platform init function part_2
 */
static errno_t pfe_platform_init_mirror_spd_acc_features(const pfe_platform_config_t *config)
{
    errno_t ret = EOK;
    uint32_t val = 0U;
    uint32_t *addr;

    ret = pfe_platform_init_etgpi_l2br_rtable_hifs(config);
    if (EOK == ret)
    {
        /*  Activate the classifier */
        pfe_class_enable(pfe.classifier);
        ret = pfe_platform_init_tmu_mirror_queue_ifaces_fci();

        if(EOK == ret)
        {
            /*  Activate PFE blocks */
            pfe_bmu_enable(pfe.bmu[0U]);
            pfe_bmu_enable(pfe.bmu[1U]);
            pfe_gpi_enable(pfe.gpi[0]);
            pfe_gpi_enable(pfe.gpi[1]);
            pfe_gpi_enable(pfe.gpi[2]);
            pfe_gpi_enable(pfe.etgpi[0]);
            pfe_gpi_enable(pfe.etgpi[1]);
            pfe_gpi_enable(pfe.etgpi[2]);
            pfe_gpi_enable(pfe.hgpi[0]);
            pfe_tmu_enable(pfe.tmu);
            if(config->enable_util)
            {
                pfe_util_enable(pfe.util);
            }
            addr = (void *)(CBUS_GLOBAL_CSR_BASE_ADDR + 0x20U + (addr_t)(pfe.cbus_baseaddr));
            val = hal_read32(addr);
            hal_write32((val | 0x80000003U), addr);

            pfe.probed = TRUE;

#ifdef PFE_CFG_IEEE1588_SUPPORT
            (void)pfe_platform_enable_ts(&pfe);
#ifdef PFE_CFG_EMAC0_PPS0_ENABLE
            (void)pfe_emac_pps0_configure(pfe.emac[0U], TRUE, PFE_CFG_EMAC0_PPS0_PERIOD_TICKS, PFE_CFG_EMAC0_PPS0_PULSE_TICKS);
            pfe_emac_pps0_resync(pfe.emac[0U]);
#else
            (void)pfe_emac_pps0_configure(pfe.emac[0U], FALSE, 0U, 0U);
#endif /* PFE_CFG_EMAC0_PPS0_ENABLE */     
#endif /* PFE_CFG_IEEE1588_SUPPORT */
        }
    }
    return ret;
}


/**
 * @brief   The platform init function
 * @details Initializes the PFE HW platform and prepares it for usage according to configuration.
 */
errno_t pfe_platform_init(const pfe_platform_config_t *config)
{
    errno_t ret = EOK;

    ret = pfe_platform_init_hm_fw_features(config);
    if (EOK == ret)
    {
        ret = pfe_platform_init_mirror_spd_acc_features(config);
    }

    return ret;
}

/**
* @brief       Destroy the platform
*/
static void pfe_platform_destroy_group1(void)
{
#ifdef PFE_CFG_FCI_ENABLE
    pfe_platform_destroy_fci(&pfe);
#endif /* PFE_CFG_FCI_ENABLE */
    pfe_platform_destroy_ifaces(&pfe);
    pfe_platform_destroy_hif(&pfe);
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    pfe_platform_destroy_hif_nocpy(&pfe);
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    pfe_platform_destroy_gpi(&pfe);
    pfe_platform_destroy_etgpi(&pfe);
    pfe_platform_destroy_hgpi(&pfe);
    pfe_platform_destroy_bmu(&pfe);
#if defined(PFE_CFG_RTABLE_ENABLE)
    pfe_platform_destroy_rtable(&pfe);
#endif /* PFE_CFG_RTABLE_ENABLE */
#if defined(PFE_CFG_L2BRIDGE_ENABLE)
    pfe_platform_destroy_l2_bridge(&pfe);
#endif /* PFE_CFG_L2BRIDGE_ENABLE */
}

/**
* @brief       Destroy the platform
*/
static void pfe_platform_destroy_group2(void)
{
    pfe_mirror_deinit();
    pfe_platform_destroy_class(&pfe);
    pfe_platform_destroy_util(&pfe);
    pfe_platform_destroy_tmu(&pfe);
    pfe_platform_destroy_emac(&pfe);
    pfe_platform_destroy_pfe_errors(&pfe);
}

/**
 * @brief       Destroy the platform
 */
errno_t pfe_platform_remove(void)
{
    errno_t ret = EOK;
    /*  Remove and disable IRQ just before platform modules are destroyed. */
    if (NULL != pfe.irq_global)
    {
        oal_irq_destroy(pfe.irq_global);
        pfe.irq_global = NULL;
    }

    /*  Clear the generic control register */
    if (NULL_ADDR != pfe.cbus_baseaddr)
    {
        hal_write32(0U, (void *)(CBUS_GLOBAL_CSR_BASE_ADDR + 0x20U + (addr_t)(pfe.cbus_baseaddr)));
    }

    (void)pfe_hm_destroy();

    pfe_platform_destroy_group1();
    pfe_platform_destroy_group2();
    (void)pfe_feature_mgr_fini();

    if (NULL_ADDR != pfe.cbus_baseaddr)
    {
        ret = oal_mm_dev_unmap((void *)pfe.cbus_baseaddr, PFE_CFG_CBUS_LENGTH);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Can't unmap PPFE CBUS: %d\n", ret);
        }
    }
    if (EOK == ret)
    {
        pfe.cbus_baseaddr = (addr_t)0x0ULL;
        pfe.probed = FALSE;
    }

    return ret;
}

/* deinit variables for shutdown*/
void pfe_platform_remove_sw_if(void)
{
    pfe.log_if_db = NULL_PTR;
    pfe.phy_if_db = NULL_PTR;
}

/**
 * @brief       Get the platform instance
 */
pfe_platform_t * pfe_platform_get_instance(void)
{
    pfe_platform_t *pfe_platform= NULL;
    if (TRUE == pfe.probed)
    {
        pfe_platform= &pfe;
    }

    return pfe_platform;
}

/**
 * @brief       Get firmware versions
 * @param[in]   platform Platform instance
 * @param[out]  class_fw The class fw parsed metadata or NULL if not needed
 * @param[out]  util_fw The util fw parsed metadata or NULL if not needed
 */
errno_t pfe_platform_get_fw_versions(const pfe_platform_t *platform, pfe_ct_version_t *class_fw, pfe_ct_version_t *util_fw)
{
    /*  CLASS fw */
    if (NULL != class_fw)
    {
        (void)pfe_class_get_fw_version(platform->classifier, class_fw);
    }

    /*  UTIL fw */
    if (NULL != util_fw)
    {
        (void)pfe_util_get_fw_version(platform->util, util_fw);
    }

    return EOK;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /*PFE_CFG_PFE_MASTER*/
