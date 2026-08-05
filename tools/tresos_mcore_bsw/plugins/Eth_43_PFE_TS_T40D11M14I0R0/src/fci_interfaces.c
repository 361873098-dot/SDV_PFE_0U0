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
 * @addtogroup  dxgr_FCI
 * @{
 *
 * @file        fci_interfaces.c
 * @brief       Ethernet interfaces management functions.
 * @details     All interfaces-related functionality provided by the FCI should be
 *              implemented within this file. This includes commmands dedicated
 *              to register and unregister interface to/from the FCI.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "pfe_platform_cfg.h"
#include "libfci.h"
#include "fpp.h"
#include "fpp_ext.h"
#include "fci_internal.h"
#include "fci_fp_db.h"
#include "fci.h"
#include "pfe_mirror.h"
#include "pfe_feature_mgr.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static errno_t fci_interfaces_get_arg_info(fpp_if_m_args_t *m_arg, pfe_ct_if_m_rules_t rule, void **offset, size_t *size, uint32_t *fp_table_addr);
static errno_t fci_interfaces_destroy_fptables(const fpp_if_m_rules_t match, const pfe_ct_if_m_args_t* args);
static errno_t fci_interfaces_log_cmd_param_validate(fci_msg_t *msg, uint16_t *fci_ret, fpp_log_if_cmd_t *reply_buf, uint32_t *reply_len, const fci_t *fci_context);
static bool_t null_arg_check(fpp_if_m_args_t *m_arg, void **offset, size_t *size);
static errno_t fp_table_addr_check(uint32_t *fp_table_addr);
static errno_t mac_cmd__set_fci_ret_based_on_get_mac_addr_ret(uint16_t *fci_ret, errno_t ret);
static errno_t mac_cmd__get_phy_if(uint16_t *fci_ret, fpp_if_mac_cmd_t *if_mac_cmd, pfe_phy_if_t **phy_if);
static errno_t phy_cmd__fpp_action_update__set_mirrors(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if);
static errno_t phy_cmd__fpp_action_update__get_phy_if_and_set_mode(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t **phy_if);
static errno_t phy_cmd__fpp_action_update__set_flags_aux1(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch);
static errno_t phy_cmd__fpp_action_update__set_flags_aux2(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch);
static errno_t phy_cmd__fpp_action_update__set_flags_aux3(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch);
static errno_t phy_cmd__fpp_action_update__set_flags(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch);
static void phy_cmd__fpp_action_update__set_ftable(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if);
static errno_t phy_cmd__fpp_action_update__set_ptp_mgmt_if(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if);
static errno_t phy_cmd__fpp_action_query_cont__part2(uint16_t *fci_ret, fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t *phy_if, bool_t *break_switch);
static errno_t phy_cmd__fpp_action_query_cont__part1(uint16_t *fci_ret, pfe_if_db_entry_t *entry, fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t **phy_if, bool_t *break_switch);
static void phy_cmd__fpp_action_query_cont__stats_and_flags(fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t *phy_if, pfe_ct_phy_if_stats_t stats);
static void phy_cmd__fpp_action_query_cont__mirrors(fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t *phy_if);
static uint32_t push_table_and_get_addr(char_t *table_name);
static void evaluate_ret_error(uint16_t *fci_ret, errno_t ret, pfe_log_if_t *log_if, const char *log_message, const uint16_t fci_val);
static void evaluate_ret_warning(uint16_t *fci_ret, errno_t ret, const char *log_message, const uint16_t fci_val);
static errno_t log_cmd__fpp_action_update__set_flags(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t *log_if);
static errno_t log_cmd__fpp_action_register(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd);
static errno_t log_cmd__fpp_action_deregister(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd);
static errno_t log_cmd__fpp_action_update(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, uint32_t *reply_len);
static errno_t phy_cmd__fpp_action_update(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd);
static errno_t log_cmd__fpp_action_update__prepare_data(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t **log_if, pfe_ct_if_m_args_t *args, bool_t *break_switch);
static errno_t log_cmd__fpp_action_update__update_fp_tables(uint16_t *fci_ret, uint32_t *fp_table_destroy, char *fp_table_ifcmd, PFE_PTR(pfe_ct_fp_table_t) *fp0_table_args, bool_t *break_switch);
static void log_cmd__fpp_action_update__update_rules(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t *log_if);
static void log_cmd__fpp_action_update__destroy_fp_table(uint32_t fp_table_destroy);
static void log_cmd__fpp_action_update__update_egress(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t *log_if);
static errno_t log_cmd__fpp_action_query_cont__stats_and_flags(fpp_log_if_cmd_t *reply_buf, pfe_log_if_t *log_if);
static void log_cmd__fpp_action_query_cont__rules(fpp_log_if_cmd_t *reply_buf, pfe_log_if_t *log_if);
static errno_t log_cmd__fpp_action_query_cont(uint16_t *fci_ret, pfe_if_db_entry_t *entry, fpp_log_if_cmd_t *reply_buf, uint32_t *reply_len);
static void log_cmd__fpp_action_query_cont__egress_and_rules(fpp_log_if_cmd_t *reply_buf, pfe_log_if_t *log_if);
static errno_t mac_cmd__fpp_action_register(uint16_t *fci_ret, fpp_if_mac_cmd_t *if_mac_cmd, pfe_phy_if_t *phy_if, pfe_drv_id_t sender_phy_if_id);
static errno_t mac_cmd__fpp_action_deregister(uint16_t *fci_ret, fpp_if_mac_cmd_t *if_mac_cmd, pfe_phy_if_t *phy_if, pfe_drv_id_t sender_phy_if_id);
static errno_t mac_cmd__fpp_action_query__finish_and_set_length(uint16_t *fci_ret, fpp_if_mac_cmd_t *reply_buf, uint32_t *reply_len, pfe_phy_if_t *phy_if);

/**
 * @brief           Null argument check
 */
static bool_t null_arg_check(fpp_if_m_args_t *m_arg, void **offset, size_t *size)
{
    return (bool_t) ((NULL == m_arg) || (NULL == offset) || (NULL == size));/* */
}

/**
 * @brief           Null table pointer check
 */
static errno_t fp_table_addr_check(uint32_t *fp_table_addr)
{
    errno_t retval = EOK;

    if(0U == *fp_table_addr) /* */
    {
        retval = ENOENT;
    }

    return retval;
}

/**
 * @brief           FPP_CMD_IF_MAC + FPP_ACTION_QUERY/_QUERY_CONT : Subroutine to set fci_ret based on return value of get_mac_addr_first()/_next().
 */
static errno_t mac_cmd__set_fci_ret_based_on_get_mac_addr_ret(uint16_t *fci_ret, errno_t ret)
{
    if (EOK != ret)
    {
        if (ENOENT == ret)
        {
            /* FCI command attempted to register already registered entity. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_MAC_NOT_FOUND;
            ret = EOK;
        }
        if (EINVAL == ret)
        {
            /* FCI command requested unfulfillable action. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_NOT_SUPPORTED;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_IF_MAC + FPP_ACTION_QUERY/_QUERY_CONT : Subroutine to write rest of response data into the query response buffer (and to set response length).
 */
static errno_t mac_cmd__fpp_action_query__finish_and_set_length(uint16_t *fci_ret, fpp_if_mac_cmd_t *reply_buf, uint32_t *reply_len, pfe_phy_if_t *phy_if)
{
    errno_t  ret = EOK;

    if ((uint16_t)FPP_ERR_OK == *fci_ret)
    {
        /* Store phy_if name into reply message */
        (void)autolibc_strncpy(reply_buf->name, pfe_phy_if_get_name(phy_if), (uint32_t)IFNAMSIZ - 1U);

        /* Set reply length and return OK */
        *reply_len = sizeof(fpp_if_mac_cmd_t);
        *fci_ret = FPP_ERR_OK;
        ret = EOK;
    }

    return ret;
}

/**
 * @brief           FPP_CMD_IF_MAC : General subroutine to get phy_if.
 */
static errno_t mac_cmd__get_phy_if(uint16_t *fci_ret, fpp_if_mac_cmd_t *if_mac_cmd, pfe_phy_if_t **phy_if)
{
    const fci_t *fci_context = (fci_t *)&context;
    errno_t ret = EOK;
    pfe_if_db_entry_t *entry = NULL;

    /*  Preparation: get the requested interface */
    ret = pfe_if_db_get_single(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_NAME, if_mac_cmd->name, &entry);

    if (EOK != ret)
    {
        /* DB not locked or locked by some other FCI user.*/
        /* FCI command requested unfulfillable action. Respond with FCI error code. */
        NXP_LOG_WARNING("Incorrect session ID detected\n");
        *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
        ret = EOK;
    }
    else
    {
        /* Check if entry is not NULL and get physical interface */
        if (NULL != entry)
        {
            *phy_if = pfe_if_db_entry_get_phy_if(entry);
        }

        /* Check if the entry exists */
        if (NULL == *phy_if)
        {
            /* Parent physical interface doesn't exist or cannot be extracted from the entry. */
            /* FCI command requested nonexistent entity. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update mirror objects of phy_if.
 */
static errno_t phy_cmd__fpp_action_update__set_mirrors(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if)
{
    uint32_t i;
    errno_t ret = EOK;
    pfe_mirror_t *mirror = NULL;

    for(i = 0U; i < (uint32_t)FPP_MIRRORS_CNT; i++)
    {
        /* RX */
        if('\0' == if_cmd->rx_mirrors[i][0])
        {   /* Mirror is disabled */
            if (EOK != pfe_phy_if_set_rx_mirror(phy_if, i, NULL))
            {
                NXP_LOG_ERROR("Configures the selected RX mirror failed\n");
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
                break;
            }
        }
        else
        {   /* Mirror is enabled and to be configured */
            /* Get requested mirror handle */
            mirror = pfe_mirror_get_first(MIRROR_BY_NAME, if_cmd->rx_mirrors[i]);
            if(NULL == mirror)
            {
                /* FCI command requested nonexistent entity. Respond with FCI error code. */
                NXP_LOG_WARNING("Mirror %s cannot be found\n", if_cmd->rx_mirrors[i]);
                *fci_ret = FPP_ERR_MIRROR_NOT_FOUND;
                ret = EOK;
                break;
            }
            /* Set the mirror */
            if (EOK != pfe_phy_if_set_rx_mirror(phy_if, i, mirror))
            {
                /*  Notify mirror module we are done working with the mirror instance. */
                pfe_mirror_put(mirror);
                mirror = NULL;

                NXP_LOG_ERROR("Configures the selected RX mirror failed\n");
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
                break;
            }
            /*  Notify mirror module we are done working with the mirror instance. */
            pfe_mirror_put(mirror);
            mirror = NULL;

        }
        /* TX */
        if('\0' == if_cmd->tx_mirrors[i][0])
        {   /* Mirror is disabled */
            if (EOK != pfe_phy_if_set_tx_mirror(phy_if, i, NULL))
            {
                NXP_LOG_ERROR("Configures the selected TX mirror failed\n");
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
                break;
            }
        }
        else
        {   /* Mirror is enabled and to be configured */
            /* Get requested mirror handle */
            mirror = pfe_mirror_get_first(MIRROR_BY_NAME, if_cmd->tx_mirrors[i]);
            if(NULL == mirror)
            {
                /* FCI command requested nonexistent entity. Respond with FCI error code. */
                NXP_LOG_WARNING("Mirror %s cannot be found\n", if_cmd->rx_mirrors[i]);
                *fci_ret = FPP_ERR_MIRROR_NOT_FOUND;
                ret = EOK;
                break;
            }
            /* Set the mirror */
            if (EOK != pfe_phy_if_set_tx_mirror(phy_if, i, mirror))
            {
                /*  Notify mirror module we are done working with the mirror instance. */
                pfe_mirror_put(mirror);
                mirror = NULL;

                NXP_LOG_ERROR("Configures the selected TX mirror failed\n");
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
                break;
            }
            /*  Notify mirror module we are done working with the mirror instance. */
            pfe_mirror_put(mirror);
            mirror = NULL;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to get phy_if object. Also set mode and blocking state of the phy_if.
 */
static errno_t phy_cmd__fpp_action_update__get_phy_if_and_set_mode(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t **phy_if)
{
    const fci_t *fci_context = (fci_t *)&context;
    errno_t ret = EINVAL;
    pfe_if_db_entry_t *entry = NULL;

    /* Get the requested interface */
    ret = pfe_if_db_get_first(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_NAME, if_cmd->name, &entry);

    if(EOK != ret)
    {
        NXP_LOG_WARNING("Incorrect session ID detected\n");
        *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
    }
    else
    {
        /* Check if entry is not NULL and get physical interface */
        if(NULL != entry)
        {
            *phy_if = pfe_if_db_entry_get_phy_if(entry);
        }

        /* Check if the entry exits*/
        if((NULL == entry) || (NULL == *phy_if))
        {
            /* Interface doesn't exist or couldn't be extracted from the entry */
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
        }
        else
        {
            /*  Set the interface block state - use the fact the enumerations
                have same values */
            ret = pfe_phy_if_set_block_state(*phy_if, (pfe_ct_block_state_t)if_cmd->block_state);
            if(EOK != ret)
            {
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
            }
            else
            {
                /* Set the interface mode */
                ret = pfe_phy_if_set_op_mode(*phy_if, (pfe_ct_if_op_mode_t)(if_cmd->mode));
                if(EOK != ret)
                {
                    *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update interface flags of phy_if. Part 1 of 3.
 */
static errno_t phy_cmd__fpp_action_update__set_flags_aux1(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch)
{
    errno_t ret = EOK;
    bool_t flag_in_cmd;
    bool_t flag_in_drv;

    /*  Enable/Disable */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_ENABLED))
    {
        ret = pfe_phy_if_enable(phy_if);
    }
    else
    {
        ret = pfe_phy_if_disable(phy_if);
    }

    if(EOK != ret)
    {
        NXP_LOG_ERROR("ENABLE flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
        *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
    }

    /* promisc */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_PROMISC))
    {
        ret = pfe_phy_if_promisc_enable(phy_if);
    }
    else
    {
        ret = pfe_phy_if_promisc_disable(phy_if);
    }

    if(EOK != ret)
    {
        NXP_LOG_ERROR("PROMISC flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
        *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
    }

    /*  VLAN conformance check */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_VLAN_CONF_CHECK))
    {
        flag_in_cmd = TRUE;
        ret = pfe_phy_if_set_flag(phy_if, IF_FL_VLAN_CONF_CHECK);
    }
    else
    {
        flag_in_cmd = FALSE;
        ret = pfe_phy_if_clear_flag(phy_if, IF_FL_VLAN_CONF_CHECK);
    }

    if(EOK != ret)
    {
        flag_in_drv = (IF_FL_NONE != pfe_phy_if_get_flag(phy_if, IF_FL_VLAN_CONF_CHECK));

        if (EPERM == ret)
        {
            if(flag_in_cmd == flag_in_drv)
            {
                /* Unavailable feature and FCI command didn't modify it. Continue through. */
                ret = EOK;
            }
            else
            {
                /* Unavailable feature and FCI command tried to modify it. Respond with FCI error code. */
                *fci_ret = FPP_ERR_FW_FEATURE_NOT_AVAILABLE;
                ret = EOK;
                *break_switch = TRUE;
            }
        }
        else
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_ERROR("VLAN_CONF_CHECK flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            *break_switch = TRUE;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update interface flags of phy_if. Part 2 of 3.
 */
static errno_t phy_cmd__fpp_action_update__set_flags_aux2(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch)
{
    errno_t ret = EOK;
    bool_t flag_in_cmd;
    bool_t flag_in_drv;
    
    /*  PTP conformance check */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_PTP_CONF_CHECK))
    {
        flag_in_cmd = TRUE;
        ret = pfe_phy_if_set_flag(phy_if, IF_FL_PTP_CONF_CHECK);
    }
    else
    {
        flag_in_cmd = FALSE;
        ret = pfe_phy_if_clear_flag(phy_if, IF_FL_PTP_CONF_CHECK);
    }

    if(EOK != ret)
    {
        flag_in_drv = (IF_FL_NONE != pfe_phy_if_get_flag(phy_if, IF_FL_PTP_CONF_CHECK));

        if (EPERM == ret)
        {
            if(flag_in_cmd == flag_in_drv)
            {
                /* Unavailable feature and FCI command didn't modify it. Continue through. */
                ret = EOK;
            }
            else
            {
                /* Unavailable feature and FCI command tried to modify it. Respond with FCI error code. */
                *fci_ret = FPP_ERR_FW_FEATURE_NOT_AVAILABLE;
                ret = EOK;
                *break_switch = TRUE;
            }
        }
        else
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_ERROR("PTP_CONF_CHECK flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            *break_switch = TRUE;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update interface flags of phy_if. Part 3 of 3.
 */
static errno_t phy_cmd__fpp_action_update__set_flags_aux3(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch)
{
    errno_t ret = EOK;

    /*  PTP promiscuous mode */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_PTP_PROMISC))
    {
        ret = pfe_phy_if_set_flag(phy_if, IF_FL_PTP_PROMISC);
    }
    else
    {
        ret = pfe_phy_if_clear_flag(phy_if, IF_FL_PTP_PROMISC);
    }

    if(EOK != ret)
    {
        /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
        NXP_LOG_ERROR("PTP_PROMISC flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
        *fci_ret = FPP_ERR_INTERNAL_FAILURE;
        *break_switch = TRUE;
    }
    else
    {
        /* Fast-Forward of ingress TCP SYN, RST, FIN */
        if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_FF_ALL_TCP))
        {
            ret = pfe_phy_if_set_flag(phy_if, IF_FL_FF_ALL_TCP);
        }
        else
        {
            ret = pfe_phy_if_clear_flag(phy_if, IF_FL_FF_ALL_TCP);
        }

        if(EOK != ret)
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_ERROR("FF_ALL_TCP flag wasn't updated correctly on %s",  pfe_phy_if_get_name(phy_if));
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            *break_switch = TRUE;
        }
        else
        {
            /*  QinQ support control */
            if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_ALLOW_Q_IN_Q))
            {
                ret = pfe_phy_if_set_flag(phy_if, IF_FL_ALLOW_Q_IN_Q);
            }
            else
            {
                ret = pfe_phy_if_clear_flag(phy_if, IF_FL_ALLOW_Q_IN_Q);
            }

            if(EOK != ret)
            {
                NXP_LOG_ERROR("ALLOW_Q_IN_Q flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
            }

            /*  TTL discard control */
            if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_DISCARD_TTL))
            {
                ret = pfe_phy_if_set_flag(phy_if, IF_FL_DISCARD_TTL);
            }
            else
            {
                ret = pfe_phy_if_clear_flag(phy_if, IF_FL_DISCARD_TTL);
            }

            if(EOK != ret)
            {
                NXP_LOG_ERROR("DISCARD_TTL flag wasn't updated correctly on %s\n",  pfe_phy_if_get_name(phy_if));
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update interface flags of phy_if.
 */
static errno_t phy_cmd__fpp_action_update__set_flags(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if, bool_t *break_switch)
{
    errno_t ret = EINVAL;

    ret = phy_cmd__fpp_action_update__set_flags_aux1(fci_ret, if_cmd, phy_if, break_switch);

    if(FALSE == *break_switch)
    {
        ret = phy_cmd__fpp_action_update__set_flags_aux2(fci_ret, if_cmd, phy_if, break_switch);

        if(FALSE == *break_switch)
        {
            ret = phy_cmd__fpp_action_update__set_flags_aux3(fci_ret, if_cmd, phy_if, break_switch);
        }
    }

    return ret;
}

/**
 * @brief           Pushes table to HW and returns the address
 */
static uint32_t push_table_and_get_addr(char_t *table_name)
{
    const fci_t *fci_context = (fci_t *)&context;
    uint32_t addr = 0U;

    addr = fci_fp_db_get_table_dmem_addr(table_name);
    if (0U == addr)
    {
        (void)fci_fp_db_push_table_to_hw(fci_context->class, table_name);
        addr = fci_fp_db_get_table_dmem_addr(table_name);
    }

    return addr;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update Flexible Filter of phy_if.
 * @details         Flexible Filter of phy_if is a Flexible Parser table employed as a traffic filter.
 */
static void phy_cmd__fpp_action_update__set_ftable(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if)
{
    uint32_t addr = 0U;
    char_t *name;
    errno_t ret = EOK;

    /*  Flexible Filter */
    if (0U != autolibc_strlen((char_t *)if_cmd->ftable))
    {
        /*  Validate table */
        if (NULL == fci_fp_db_get_first(FP_TABLE_CRIT_NAME, (void *)if_cmd->ftable))
        {
            /*  Table not found */
            NXP_LOG_WARNING("%s: FP table %s not found\n", pfe_phy_if_get_name(phy_if), if_cmd->ftable);
        }
        else
        {
            /*  If not already done, write the table to HW */
            addr = push_table_and_get_addr((char_t *)if_cmd->ftable);

            /*  Assign the table to the physical interface */
            ret = pfe_phy_if_set_ftable(phy_if, addr);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("%s: Could not set filter table: %d\n", pfe_phy_if_get_name(phy_if), ret);
                *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
            }
        }
    }
    else
    {
        /*  Disable the filter. Get table entry from DB first. */
        addr = pfe_phy_if_get_ftable(phy_if);
        if (EOK == fci_fp_db_get_table_from_addr(addr, &name))
        {
            /* Delete the table from DMEM - no longer in use, copy is in database */
            (void)fci_fp_db_pop_table_from_hw(name);
        }

        /*  Assign NULL-table to the physical interface */
        ret = pfe_phy_if_set_ftable(phy_if, 0U);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("%s: Could not set filter table: %d\n", pfe_phy_if_get_name(phy_if), ret);
            *fci_ret = FPP_ERR_IF_OP_UPDATE_FAILED;
        }
    }

}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE : Subroutine to update PTP management interface of phy_if.
 */
static errno_t phy_cmd__fpp_action_update__set_ptp_mgmt_if(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd, pfe_phy_if_t *phy_if)
{
    const fci_t *fci_context = (fci_t *)&context;
    pfe_if_db_entry_t *mgmt_entry = NULL;
    pfe_phy_if_t *mgmt_if = NULL;
    errno_t ret = EOK;

    /* PTP mgmt interface */
    if ('\0' == if_cmd->ptp_mgmt_if[0])
    {
        /* Disable mgmt interface */
        ret = pfe_phy_if_set_mgmt_interface(phy_if, PFE_PHY_IF_ID_INVALID);
        if (EOK != ret)
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_ERROR("%s: Could not disable mgmt interface\n", pfe_phy_if_get_name(phy_if));
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
        }
    }
    else
    {
        ret = pfe_if_db_get_single(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_NAME, if_cmd->ptp_mgmt_if, &mgmt_entry);
        if (EOK != ret)
        {
            /* FCI command requested unfulfillable action. Respond with FCI error code. */
            NXP_LOG_WARNING("Incorrect session ID detected\n");
            *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
            ret = EOK;
        }
        else
        {
            /* Check if entry is not NULL and get physical interface */
            if (NULL != mgmt_entry)
            {
                mgmt_if = pfe_if_db_entry_get_phy_if(mgmt_entry);
            }
            /* Check if the entry exists */
            if ((NULL == mgmt_entry) || (NULL == mgmt_if))
            {
                /* FCI command requested nonexistent entity. Respond with FCI error code. */
                *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                ret = EOK;
            }
            else
            {
                /* Enable mgmt interface and set its target physical interface */
                ret = pfe_phy_if_set_mgmt_interface(phy_if, pfe_phy_if_get_id(mgmt_if));
                if (EOK != ret)
                {
                    /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                    NXP_LOG_ERROR("%s: Could not set new mgmt interface %s\n", pfe_phy_if_get_name(phy_if), pfe_phy_if_get_name(mgmt_if));
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_QUERY_CONT : Subroutine to write interface Flexible Filter info and PTP management interface info into query response buffer.
 */
static errno_t phy_cmd__fpp_action_query_cont__part2(uint16_t *fci_ret, fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t *phy_if, bool_t *break_switch)
{
    const fci_t *fci_context = (fci_t *)&context;
    uint32_t addr = 0U;
    char_t *name;
    pfe_ct_phy_if_id_t mgmt_if_id = PFE_PHY_IF_ID_INVALID;
    pfe_if_db_entry_t *mgmt_entry = NULL;
    pfe_phy_if_t *mgmt_if = NULL;
    errno_t  ret = EOK;

    /*  Get filter info */
    addr = pfe_phy_if_get_ftable(phy_if);
    if (0U != addr)
    {
        ret = fci_fp_db_get_table_from_addr(addr, &name);
        if (EOK == ret)
        {
            (void)autolibc_strncpy(reply_buf->ftable, name, sizeof(reply_buf->ftable) - 1U);
        }
        else
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_ERROR("Can't get table name from DB: %d\n", ret);
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            *break_switch = TRUE;
        }
    }
    else
    {
        (void)autolibc_memset(reply_buf->ftable, 0, sizeof(reply_buf->ftable));
    }

    if(FALSE == *break_switch)
    {
        /* Get PTP mgmt interface */
        mgmt_if_id = pfe_phy_if_get_mgmt_interface(phy_if);
        if (PFE_PHY_IF_ID_INVALID <= mgmt_if_id)
        {
            (void)autolibc_memset(reply_buf->ptp_mgmt_if, 0, sizeof(reply_buf->ptp_mgmt_if));
        }
        else
        {
            ret = pfe_if_db_get_single(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_ID, (void*)mgmt_if_id, &mgmt_entry);
            if (EOK != ret)
            {
                /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                NXP_LOG_WARNING("Incorrect session ID detected\n");
                *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                *break_switch = TRUE;
            }
            else
            {
                /* Check if entry is not NULL and get physical interface */
                if (NULL != mgmt_entry)
                {
                    mgmt_if = pfe_if_db_entry_get_phy_if(mgmt_entry);
                }
                /* Check if the entry exists */
                if ((NULL == mgmt_entry) || (NULL == mgmt_if))
                {
                    /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                    NXP_LOG_ERROR("Unexpected NULL mgmt_if\n");
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                    *break_switch = TRUE;
                }
                else
                {
                    (void)autolibc_strncpy(reply_buf->ptp_mgmt_if, pfe_phy_if_get_name(mgmt_if), (uint32_t)IFNAMSIZ-1U);
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_QUERY_CONT : Subroutine to write interface statistics and interface flags into query response buffer.
 */
static void phy_cmd__fpp_action_query_cont__stats_and_flags(fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t *phy_if, pfe_ct_phy_if_stats_t stats)
{
    /* Copy the phy if statistics to reply */
    (void)autolibc_memcpy(&reply_buf->stats, &stats, sizeof(reply_buf->stats));

    /* Store phy_if name */
    (void)autolibc_strncpy(reply_buf->name, pfe_phy_if_get_name(phy_if), (uint32_t)IFNAMSIZ-1U);

    /* Store phy_if id */
    reply_buf->id = oal_htonl(pfe_phy_if_get_id(phy_if));

    reply_buf->flags |= (TRUE == pfe_phy_if_is_promisc(phy_if)) ? oal_htonl(FPP_IF_PROMISC) : 0U;
    reply_buf->flags |= (TRUE == pfe_phy_if_is_enabled(phy_if)) ? oal_htonl(FPP_IF_ENABLED) : 0U;
    reply_buf->flags |= ((uint32_t)IF_FL_NONE != (uint32_t)pfe_phy_if_get_flag(phy_if, IF_FL_VLAN_CONF_CHECK)) ? oal_htonl(FPP_IF_VLAN_CONF_CHECK) : 0U;
    reply_buf->flags |= ((uint32_t)IF_FL_NONE != (uint32_t)pfe_phy_if_get_flag(phy_if, IF_FL_PTP_CONF_CHECK)) ? oal_htonl(FPP_IF_PTP_CONF_CHECK) : 0U;
    reply_buf->flags |= ((uint32_t)IF_FL_NONE != (uint32_t)pfe_phy_if_get_flag(phy_if, IF_FL_PTP_PROMISC)) ? oal_htonl(FPP_IF_PTP_PROMISC) : 0U;
    reply_buf->flags |= ((uint32_t)IF_FL_NONE != (uint32_t)pfe_phy_if_get_flag(phy_if, IF_FL_FF_ALL_TCP)) ? oal_htonl(FPP_IF_FF_ALL_TCP) : 0U;
    reply_buf->flags |= ((uint32_t)IF_FL_NONE != (uint32_t)pfe_phy_if_get_flag(phy_if, IF_FL_ALLOW_Q_IN_Q)) ? oal_htonl(FPP_IF_ALLOW_Q_IN_Q) : 0U;
    reply_buf->flags |= ((uint32_t)IF_FL_NONE != (uint32_t)pfe_phy_if_get_flag(phy_if, IF_FL_DISCARD_TTL)) ? oal_htonl(FPP_IF_DISCARD_TTL) : 0U;

    /* Get the mode - use the fact enums have same values */
    reply_buf->mode = (fpp_phy_if_op_mode_t) pfe_phy_if_get_op_mode(phy_if);
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_QUERY_CONT : Subroutine to write interface mirrors into query response buffer.
 */
static void phy_cmd__fpp_action_query_cont__mirrors(fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t *phy_if)
{
    uint32_t i;
    pfe_mirror_t *mirror = NULL;
    const char *str;

    for(i = 0U; i < (uint32_t)FPP_MIRRORS_CNT; i++)
    {
        /* RX */
        mirror = pfe_phy_if_get_rx_mirror(phy_if, i);
        if(NULL != mirror)
        {
            str = pfe_mirror_get_name(mirror);
            if(NULL != str)
            {
                (void)autolibc_strncpy(&reply_buf->rx_mirrors[i][0], str, 16);
                reply_buf->rx_mirrors[i][15] = '\0'; /* Ensure correct string end */
            }
            else
            {
                NXP_LOG_WARNING("Could not obtain mirror name\n");
            }
        }
        /*  Notify mirror module we are done working with the mirror instance. This releases the reference obtained from pfe_phy_if_get_rx_mirror(). */
        pfe_mirror_put(mirror);
        mirror = NULL;

        /* TX */
        mirror = pfe_phy_if_get_tx_mirror(phy_if, i);
        if(NULL != mirror)
        {
            str = pfe_mirror_get_name(mirror);
            if(NULL != str)
            {
                (void)autolibc_strncpy(&reply_buf->tx_mirrors[i][0], str, 16);
                reply_buf->tx_mirrors[i][15] = '\0'; /* Ensure correct string end */
            }
            else
            {
                NXP_LOG_WARNING("Could not obtain mirror name\n");
            }
        }
        /*  Notify mirror module we are done working with the mirror instance. This releases the reference obtained from pfe_phy_if_get_tx_mirror(). */
        pfe_mirror_put(mirror);
        mirror = NULL;
    }
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_QUERY_CONT : part 1
 */
static errno_t phy_cmd__fpp_action_query_cont__part1(uint16_t *fci_ret, pfe_if_db_entry_t *entry, fpp_phy_if_cmd_t *reply_buf, pfe_phy_if_t **phy_if, bool_t *break_switch)
{
    const fci_t *fci_context = (fci_t *)&context;
    pfe_ct_phy_if_stats_t stats = { 0 };
    pfe_ct_block_state_t block_state;
    errno_t ret = EOK;

    if (NULL == entry)
    {
        ret = pfe_if_db_get_next(fci_context->phy_if_db, fci_context->if_session_id, &entry);
        if(EOK != ret)
        {
            ret = EOK;
            *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
            *break_switch = TRUE;
        }

        if((FALSE == *break_switch) && (NULL == entry))
        {
            ret = EOK;
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            *break_switch = TRUE;
        }
    }
    if(FALSE == *break_switch)
    {
        *phy_if = pfe_if_db_entry_get_phy_if(entry);
        if (NULL == *phy_if)
        {
            NXP_LOG_DEBUG("Was not possible to resolve DB entry to phy_if");
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            *break_switch = TRUE;
        }
        else
        {
            ret = pfe_phy_if_get_stats(*phy_if, &stats);
            if(EOK != ret)
            {
                NXP_LOG_ERROR("Could not get interface statistics\n");
                *break_switch = TRUE;
            }
            else
            {
                phy_cmd__fpp_action_query_cont__stats_and_flags(reply_buf, *phy_if, stats);
                /* Get the block state */
                (void)pfe_phy_if_get_block_state(*phy_if, &block_state);
                /* Use the fact that the enums have same values */
                reply_buf->block_state = (fpp_phy_if_block_state_t)block_state;
                phy_cmd__fpp_action_query_cont__mirrors(reply_buf, *phy_if);
            }
        }
    }

    return ret;
}

/**
 * @brief           Get offset and size of the rule
 * @details         Errors are handled in platform driver
 * @param[in]       m_args pointer to the argument structure
 * @param[in]       rule single rule. See pfe_ct_if_m_rules_t
 * @param[in,out]   offset is set based on the rule to the structure m_arg
 * @param[in,out]   size of the underlying type in the struct based on the rule
 */
static errno_t fci_interfaces_get_arg_info(fpp_if_m_args_t *m_arg, pfe_ct_if_m_rules_t rule, void **offset, size_t *size, uint32_t *fp_table_addr)
{
    errno_t retval = EOK; /* Function return value */
    uint32_t table_addr;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(null_arg_check(m_arg, offset, size)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        retval = EINVAL;
    }
    else
#else
        (void)(null_arg_check);
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (rule)
        {
            case IF_MATCH_VLAN:
            {
                *size = sizeof(m_arg->vlan);
                *offset = &m_arg->vlan;
                break;
            }

            case IF_MATCH_PROTO:
            {
                *size = sizeof(m_arg->proto);
                *offset = &m_arg->proto;
                break;
            }

            case IF_MATCH_SPORT:
            {
                *size = sizeof(m_arg->sport);
                *offset = &m_arg->sport;
                break;
            }

            case IF_MATCH_DPORT:
            {
                *size = sizeof(m_arg->dport);
                *offset = &m_arg->dport;
                break;
            }

            case IF_MATCH_SIP6:
            {
                *size = sizeof(m_arg->ipv.v6.sip);
                *offset = &m_arg->ipv.v6.sip;
                break;
            }

            case IF_MATCH_DIP6:
            {
                *size = sizeof(m_arg->ipv.v6.dip);
                *offset = &m_arg->ipv.v6.dip;
                break;
            }

            case IF_MATCH_SIP:
            {
                *size = sizeof(m_arg->ipv.v4.sip);
                *offset = &m_arg->ipv.v4.sip;
                break;
            }

            case IF_MATCH_DIP:
            {
                *size = sizeof(m_arg->ipv.v4.dip);
                *offset = &m_arg->ipv.v4.dip;
                break;
            }

            case IF_MATCH_ETHTYPE:
            {
                *size = sizeof(m_arg->ethtype);
                *offset = &m_arg->ethtype;
                break;
            }

            case IF_MATCH_FP0:
            {
                /* Get the table address in the HW */
                table_addr = fci_fp_db_get_table_dmem_addr(m_arg->fp_table0);
                *fp_table_addr = oal_htonl(table_addr);
                retval = fp_table_addr_check(fp_table_addr);
                *offset = fp_table_addr;
                *size = sizeof(uint32_t);
                break;
            }

            case IF_MATCH_FP1:
            {
                /* Get the table address in the HW */
                table_addr = fci_fp_db_get_table_dmem_addr(m_arg->fp_table1);
                *fp_table_addr = oal_htonl(table_addr);
                retval = fp_table_addr_check(fp_table_addr);
                *offset = fp_table_addr;
                *size = sizeof(uint32_t);
                break;
            }

            case IF_MATCH_SMAC:
            {
                *size = sizeof(m_arg->smac);
                *offset = &m_arg->smac;
                break;
            }

            case IF_MATCH_DMAC:
            {
                *size = sizeof(m_arg->dmac);
                *offset = &m_arg->dmac;
                break;
            }

            case IF_MATCH_HIF_COOKIE:
            {
                *size = sizeof(m_arg->hif_cookie);
                *offset = &m_arg->hif_cookie;
                break;
            }

            default:
            {
                *size = 0U;
                *offset = NULL;
                break;
            }
        }
    }
    return retval;
}

/**
 * @brief           Destroy FP tables if they are used.
 *                  Auxiliary function for logical interface processing.
 * @param[in]       match   Match rules of a logical interface.
 * @param[in]       args    Match rule arguments of a logical interface.
 * @return          EOK if success, error code otherwise
 */
static errno_t fci_interfaces_destroy_fptables(const fpp_if_m_rules_t match, const pfe_ct_if_m_args_t* args)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (NULL == args)
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        char_t *table_name = NULL;

        if((uint32_t)FPP_IF_MATCH_FP0 == ((uint32_t)match & (uint32_t)FPP_IF_MATCH_FP0))
        {   /* A flexible parser table was dropped - it needs to be destroyed if it existed */
            if(0U != args->fp0_table)
            {   /* Table existed */
                (void)fci_fp_db_get_table_from_addr(args->fp0_table, &table_name);
                (void)fci_fp_db_pop_table_from_hw(table_name);
            }
        }
        if((uint32_t)FPP_IF_MATCH_FP1 == ((uint32_t)match & (uint32_t)FPP_IF_MATCH_FP1))
        {   /* A flexible parser table was dropped - it needs to be destroyed if it existed */
            if(0U != args->fp1_table)
            {   /* Table existed */
                (void)fci_fp_db_get_table_from_addr(args->fp1_table, &table_name);
                (void)fci_fp_db_pop_table_from_hw(table_name);
            }
        }
        ret = EOK;
    }
    return ret;
}

/**
 * @brief           Process interface atomic session related commands
 * @param[in]       msg FCI cmd code
 * @param[out]      fci_ret FCI return code
 * @return          EOK if success, error code otherwise
 */
errno_t fci_interfaces_session_cmd(uint32_t code, uint16_t *fci_ret)
{
    fci_t *fci_context = (fci_t *)&context;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == fci_ret))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch(code)
        {
            case FPP_CMD_IF_LOCK_SESSION:
            {
                *fci_ret = FPP_ERR_OK;
                if (EOK != pfe_if_db_lock(&fci_context->if_session_id))
                {
                    *fci_ret = FPP_ERR_IF_RESOURCE_ALREADY_LOCKED;
                    NXP_LOG_DEBUG("DB lock failed\n");
                }
                break;
            }
            case FPP_CMD_IF_UNLOCK_SESSION:
            {
                *fci_ret = FPP_ERR_OK;
                if (EOK != pfe_if_db_unlock(fci_context->if_session_id))
                {
                    *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
                    NXP_LOG_DEBUG("DB unlock failed due to incorrect session ID\n");
                }
                break;
            }
            default:
            {
                NXP_LOG_WARNING("Unknown Interface Session Command Received\n");
                *fci_ret = FPP_ERR_UNKNOWN_ACTION;
                break;
            }
        }
    }
    return ret;
}

/**
 * @brief           validate parameter processing FPP_CMD_LOG_IF commands
 * @param[in]       msg FCI message containing the FPP_CMD_LOG_IF command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_log_if_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @param[in,out]   fci_context fci context
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with interface DB session lock.
 */
static errno_t fci_interfaces_log_cmd_param_validate(fci_msg_t *msg, uint16_t *fci_ret, fpp_log_if_cmd_t *reply_buf, uint32_t *reply_len, const fci_t *fci_context)
{
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == msg) || (NULL == fci_ret) || (NULL == reply_buf) || (NULL == reply_len) || (NULL == fci_context)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(FALSE == fci_context->fci_initialized))
    {
        NXP_LOG_ERROR("Context not initialized\n");
        ret = EPERM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (*reply_len < sizeof(fpp_log_if_cmd_t))
        {
            NXP_LOG_WARNING("Buffer length does not match expected value (fpp_if_cmd_t)\n");
            ret = EINVAL;
        }
    }

    (void)msg;
    (void)fci_ret;
    (void)reply_buf;
    (void)fci_context;

    return ret;
}

/**
 * @brief           Auxiliary function evaluate return value and set fci_ret value, sets nxp log error
 */
static void evaluate_ret_error(uint16_t *fci_ret, errno_t ret, pfe_log_if_t *log_if, const char *log_message, const uint16_t fci_val)
{
    if( NULL != log_if)
    {
        if(EOK != ret)
        {
            NXP_LOG_ERROR("%s %s\n", log_message, pfe_log_if_get_name(log_if));
            *fci_ret = fci_val;
        }
    }
    else
    {
        if(EOK != ret)
        {
            NXP_LOG_ERROR("%s \n", log_message);
            *fci_ret = fci_val;
        }
    }
}

/**
 * @brief           Auxiliary function evaluate return value and set fci_ret value, sets nxp log warning
 */
static void evaluate_ret_warning(uint16_t *fci_ret, errno_t ret, const char *log_message, const uint16_t fci_val)
{
    if(EOK != ret)
    {
        NXP_LOG_WARNING("%s \n", log_message);
       *fci_ret = fci_val;
    }
    (void) log_message;      /*suppress compiler warning*/
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE : Subroutine to update (set) flags of log_if.
 */
static errno_t log_cmd__fpp_action_update__set_flags(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t *log_if)
{
    errno_t ret = EOK;

    /* AND/OR rules */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_MATCH_OR))
    {
        ret = pfe_log_if_set_match_or(log_if);
    }
    else
    {
        ret = pfe_log_if_set_match_and(log_if);
    }

    evaluate_ret_error( fci_ret, ret, log_if, "AND/OR flag wasn't updated correctly on", FPP_ERR_IF_OP_UPDATE_FAILED);

    /* enable/disable */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_ENABLED))
    {
        ret = pfe_log_if_enable(log_if);
    }
    else
    {
        ret = pfe_log_if_disable(log_if);
    }

    evaluate_ret_error( fci_ret, ret, log_if, "ENABLE flag wasn't updated correctly on", FPP_ERR_IF_OP_UPDATE_FAILED);

    /* promisc */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_PROMISC))
    {
        ret = pfe_log_if_promisc_enable(log_if);
    }
    else
    {
        ret = pfe_log_if_promisc_disable(log_if);
    }

    evaluate_ret_error( fci_ret, ret, log_if, "PROMISC flag wasn't updated correctly on", FPP_ERR_IF_OP_UPDATE_FAILED);

    /* discard */
    if(0U != (oal_ntohl(if_cmd->flags) & (uint32_t)FPP_IF_DISCARD))
    {
        ret = pfe_log_if_discard_enable(log_if);
    }
    else
    {
        ret = pfe_log_if_discard_disable(log_if);
    }

    evaluate_ret_error( fci_ret, ret, log_if, "DISCARD flag wasn't updated correctly on", FPP_ERR_IF_OP_UPDATE_FAILED);

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_REGISTER
 */
static errno_t log_cmd__fpp_action_register(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd)
{
    const fci_t *fci_context = (fci_t *)&context;
    pfe_if_db_entry_t *entry = NULL;
    pfe_log_if_t *log_if = NULL;
    pfe_phy_if_t *phy_if = NULL;
    errno_t ret = EINVAL;

    /* Get the intended parent physical interface */
    ret = pfe_if_db_get_first(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_NAME, if_cmd->parent_name, &entry);
    if(EOK != ret)
    {
        *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
    }
    else
    {
        phy_if = pfe_if_db_entry_get_phy_if(entry);
        if(NULL == phy_if)
        {
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            ret = ENOENT;
        }
        else
        {
            /* Create the logical interface */
            log_if = pfe_log_if_create(phy_if, if_cmd->name);
            if(NULL == log_if)
            {
                *fci_ret = FPP_ERR_IF_OP_CANNOT_CREATE;
                ret = ENOENT;
            }
            else
            {
                /* Add the interface into the database */
                ret = pfe_if_db_add(fci_context->log_if_db, fci_context->if_session_id, log_if, pfe_phy_if_get_id(phy_if));
                if(EOK != ret)
                {
                    pfe_log_if_destroy(log_if);
                    *fci_ret = FPP_ERR_IF_OP_CANNOT_CREATE;
                }
                else
                {
                    NXP_LOG_INFO("Added logical interface %s to physical interface %s\n", if_cmd->name, if_cmd->parent_name);
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_DEREGISTER
 */
static errno_t log_cmd__fpp_action_deregister(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd)
{
    const fci_t *fci_context = (fci_t *)&context;
    pfe_if_db_entry_t *entry = NULL;
    pfe_log_if_t *log_if = NULL;
    pfe_ct_if_m_args_t args;
    pfe_ct_if_m_rules_t rules;
    errno_t ret = EINVAL;

    ret = pfe_if_db_get_first(fci_context->log_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_NAME, if_cmd->name, &entry);

    if(EOK != ret)
    {
        NXP_LOG_WARNING("Incorrect session ID detected\n");
        *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
    }
    else
    {
        /* Check if entry is not NULL and get logical interface */
        if(NULL != entry)
        {
            log_if = pfe_if_db_entry_get_log_if(entry);
        }

        /* Check if the entry exists */
        if((NULL == entry) || (NULL == log_if))
        {
            /* Interface doesn't exist or couldn't be extracted from the entry */
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            ret = ENOENT;
        }
        else
        {
            /* Destroy FP tables if they were used by this interface. */
            if(EOK == pfe_log_if_get_match_rules(log_if, &rules, &args))
            {
                /* Fix endians of FP tables */
                args.fp0_table = oal_ntohl(args.fp0_table);
                args.fp1_table = oal_ntohl(args.fp1_table);

                /* Destroy FP tables */
                (void)fci_interfaces_destroy_fptables((fpp_if_m_rules_t)rules, &args);
            }

            /* Remove interface from the database */
            (void)pfe_if_db_remove(fci_context->log_if_db, fci_context->if_session_id, entry);
            /* Destroy the interface */
            pfe_log_if_destroy(log_if);
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE : Subroutine to get a log_if object and prepare data for update of the log_if object.
 */
static errno_t log_cmd__fpp_action_update__prepare_data(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t **log_if, pfe_ct_if_m_args_t *args, bool_t *break_switch)
{
    const fci_t *fci_context = (fci_t *)&context;
    errno_t ret = EINVAL;
    pfe_if_db_entry_t *entry;
    pfe_ct_if_m_rules_t rules;

    *break_switch = FALSE;
    ret = pfe_if_db_get_first(fci_context->log_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_NAME, if_cmd->name, &entry);

    if(EOK != ret)
    {
        NXP_LOG_WARNING("Incorrect session ID detected\n");
        *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
        *break_switch = TRUE;
    }
    else
    {
        /* Check if entry is not NULL and get logical interface */
        if(NULL != entry)
        {
            *log_if = pfe_if_db_entry_get_log_if(entry);
        }

        /* Check if the entry exists */
        if((NULL == entry) || (NULL == *log_if))
        {
            /* Interface doesn't exist or couldn't be extracted from the entry */
            *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            *break_switch = TRUE;
        }
        else
        {
            /* Get the currently set rules */
            ret = pfe_log_if_get_match_rules(*log_if, &rules, args);
            if(ret != EOK)
            {
                *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                *break_switch = TRUE;
            }
            else
            {
                /* Avoid mixing IPV4 and IPV6 rules */
                if ((0U != ((((uint32_t)FPP_IF_MATCH_SIP)  | ((uint32_t)FPP_IF_MATCH_DIP))  & oal_ntohl(if_cmd->match))) &&
                    (0U != ((((uint32_t)FPP_IF_MATCH_SIP6) | ((uint32_t)FPP_IF_MATCH_DIP6)) & oal_ntohl(if_cmd->match))))
                {
                    /* FCI command requested unfulfillable action. Respond with FCI error code. */
                    *fci_ret = FPP_ERR_IF_MATCH_UPDATE_FAILED;
                    *break_switch = TRUE;
                }
                else
                {
                    /* Fix endians of FP tables */
                    args->fp0_table = oal_ntohl(args->fp0_table);
                    args->fp1_table = oal_ntohl(args->fp1_table);

                    rules = (pfe_ct_if_m_rules_t)(~oal_ntohl(if_cmd->match));

                    /* Drop all unset rules (if any) */
                    ret = pfe_log_if_del_match_rule(*log_if, rules);

                    /* Destroy FP tables if they are not used by new rules */
                    (void)fci_interfaces_destroy_fptables((fpp_if_m_rules_t)rules, args);

                    if(EOK == ret)
                    {
                        NXP_LOG_INFO("All match rules were dropped on %s before match rule update.\n",  pfe_log_if_get_name(*log_if));
                    }
                    else
                    {
                        NXP_LOG_WARNING("Dropping of all match rules on logical interface %s failed !!\n",  pfe_log_if_get_name(*log_if));
                        *fci_ret = FPP_ERR_IF_MATCH_UPDATE_FAILED;
                    }
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE : Subroutine to update FP tables of log_if.
 */
static errno_t log_cmd__fpp_action_update__update_fp_tables(uint16_t *fci_ret, uint32_t *fp_table_destroy, char *fp_table_ifcmd, PFE_PTR(pfe_ct_fp_table_t) *fp0_table_args, bool_t *break_switch)
{
    const fci_t *fci_context = (fci_t *)&context;
    uint32_t fp_table_addr;
    errno_t ret = EOK;

    *break_switch = FALSE;

    /* Get the newly configured table address */
    fp_table_addr = fci_fp_db_get_table_dmem_addr(fp_table_ifcmd);
    if(0U == fp_table_addr)
    {   /* Table has not been created yet */
        ret = fci_fp_db_push_table_to_hw(fci_context->class, fp_table_ifcmd);
        if(EOK != ret)
        {   /* Failed to write */
            *fci_ret = FPP_ERR_IF_MATCH_UPDATE_FAILED;
            *break_switch = TRUE;
        }
        else
        {
            /* We have just created the table therefore the existing one must be different
            and it needs to be destroyed before we overwrite the reference */
            if(0U != *fp0_table_args)
            {
                /* Table is still in use therefore it cannot be destroyed,
                just remember it */
                *fp_table_destroy = *fp0_table_args;
            }
        }
    }
    else
    {   /* Table does exist */
        /* Check whether it is already configured */
        if(fp_table_addr != *fp0_table_args)
        {   /* Different table is configured thus the new one must be in use
            somewhere else (because it does have the address) and cannot be
            used here */
            NXP_LOG_WARNING("Table %s already in use.\n", *fp_table_ifcmd);
            *fci_ret = FPP_ERR_IF_MATCH_UPDATE_FAILED;
            *break_switch = TRUE;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE : Subroutine to destroy Flexible Parser table.
 */
static void log_cmd__fpp_action_update__destroy_fp_table(uint32_t fp_table_destroy)
{
    char_t *table_name;

    if(0U != fp_table_destroy)
    {
        (void)fci_fp_db_get_table_from_addr(fp_table_destroy, &table_name);
        (void)fci_fp_db_pop_table_from_hw(table_name);
    }
}


/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE : Subroutine to update egress interface list of log_if.
 */
static void log_cmd__fpp_action_update__update_egress(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t *log_if)
{
    const fci_t *fci_context = (fci_t *)&context;
    uint32_t index = 0U, egress = 0U;
    pfe_phy_if_t *phy_if = NULL;
    pfe_if_db_entry_t *entry;
    errno_t ret = EOK;

    /* Update egress in case at least one is set (old egress is dropped) */
    if(0U != if_cmd->egress)
    {
        NXP_LOG_INFO("Updating egress interfaces on %s (0x%x)\n",  pfe_log_if_get_name(log_if), (uint_t)oal_ntohl(if_cmd->egress));
        for(index = 0U; (uint32_t)PFE_PHY_IF_ID_INVALID > index;  ++index)
        {

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            if((uint32_t)PFE_PHY_IF_ID_HIF == index)
            {
                /* Skip currently not used interfaces */
                continue;
            }
#else
            if(((uint32_t)PFE_PHY_IF_ID_HIF == index) || ((uint32_t)PFE_PHY_IF_ID_HIF_NOCPY == index))
            {
                /* Skip currently not used interfaces */
                continue;
            }
#endif
            /* For each bit in egress mask search if the phy if exists */
            ret = pfe_if_db_get_first(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_ID, (void *)(addr_t)index, &entry);
            if((EOK == ret) && (NULL != entry))
            {   /* phy if does exist */
                phy_if = pfe_if_db_entry_get_phy_if(entry);
                /* Check whether the phy if shall be added
                We are getting inputs in network order thus conversion is needed */
                if(0U != (oal_ntohl(if_cmd->egress) & (1UL << index)))
                {   /* Add */
                    /* If the ID exits add corresponding phy_if as egress to log_if*/
                    ret = pfe_log_if_add_egress_if(log_if, phy_if);
                    evaluate_ret_error(fci_ret, ret, log_if, "Could not set egress interface for", FPP_ERR_IF_EGRESS_UPDATE_FAILED);
                }
                else
                {   /* Do not add (drop from the list if already on the list) */
                    /* Get current egress interfaces */
                    ret = pfe_log_if_get_egress_ifs(log_if, &egress);
                    if(EOK == ret)
                    {
                        if(0U != (egress & ((uint32_t)1U << index)))
                        {   /* Interface is on the current list but not on the requested list - drop it */
                            ret = pfe_log_if_del_egress_if(log_if, phy_if);
                        }
                    }
                    evaluate_ret_error(fci_ret, ret, log_if, "Could not get and clear egress interface for", FPP_ERR_IF_EGRESS_UPDATE_FAILED);

                }
            }
            else
            {
                NXP_LOG_WARNING("Egress %u on %s is not set because it doesn't exist\n", (uint_t)index,  pfe_log_if_get_name(log_if));
                /* Error in input do not continue */
                *fci_ret = FPP_ERR_IF_EGRESS_DOESNT_EXIST;
            }
        }
    }
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE : Subroutine to update interface rules of log_if.
 */
static void log_cmd__fpp_action_update__update_rules(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, pfe_log_if_t *log_if)
{
    uint32_t index = 0U;
    void *offset = NULL;
    uint32_t fp_table_addr;
    errno_t ret = EOK;
    size_t size = 0U;

    /* Update each rule one by one */
    for(index = 0U; (8U * sizeof(if_cmd->match)) > index; ++index)
    {
        if(0U != (oal_ntohl(if_cmd->match) & (1UL << index)))
        {
            /* Resolve position of data and size */
            ret = fci_interfaces_get_arg_info(&if_cmd->arguments, (pfe_ct_if_m_rules_t)(oal_ntohl(if_cmd->match) & (1UL << index)), &offset, &size, &fp_table_addr);
            if(EOK != ret)
            {
                NXP_LOG_WARNING("Failed to get update argument\n");
                *fci_ret = FPP_ERR_IF_MATCH_UPDATE_FAILED;
            }

            /* Add match rule and arguments */
            ret = pfe_log_if_add_match_rule(log_if, (pfe_ct_if_m_rules_t)(oal_ntohl(if_cmd->match) & (1UL << index)), offset, size);

            if(EOK != ret)
            {
                NXP_LOG_WARNING("Updating single rule on logical interface %s failed !!\n",  pfe_log_if_get_name(log_if));
                *fci_ret = FPP_ERR_IF_MATCH_UPDATE_FAILED;
            }
        }
    }
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_UPDATE
 */
static errno_t log_cmd__fpp_action_update(uint16_t *fci_ret, fpp_log_if_cmd_t *if_cmd, uint32_t *reply_len)
{
    errno_t ret = EINVAL;
    pfe_ct_if_m_args_t args;
    uint32_t fp_table_destroy[2];
    pfe_log_if_t *log_if = NULL;
    bool_t break_switch = FALSE;

    *fci_ret = FPP_ERR_OK;
    *reply_len = sizeof(fpp_log_if_cmd_t);

    ret = log_cmd__fpp_action_update__prepare_data(fci_ret, if_cmd, &log_if, &args, &break_switch);
    if((EOK == ret) && (FALSE == break_switch))
    {
        /* Clear the storage for queues to be destroyed */
        fp_table_destroy[0] = 0U;
        fp_table_destroy[1] = 0U;
        /* We are going to configure Flexible parser - prepare table(s) */
        if((uint32_t)FPP_IF_MATCH_FP0 == (oal_ntohl(if_cmd->match) & (uint32_t)FPP_IF_MATCH_FP0))
        {
            ret = log_cmd__fpp_action_update__update_fp_tables(fci_ret, &fp_table_destroy[0], if_cmd->arguments.fp_table0, &args.fp0_table, &break_switch);
        }
        if(FALSE == break_switch)
        {
            if((uint32_t)FPP_IF_MATCH_FP1 == (oal_ntohl(if_cmd->match) & (uint32_t)FPP_IF_MATCH_FP1))
            {
                ret = log_cmd__fpp_action_update__update_fp_tables(fci_ret, &fp_table_destroy[1], if_cmd->arguments.fp_table1, &args.fp1_table, &break_switch);
            }
            if(FALSE == break_switch)
            {
                log_cmd__fpp_action_update__update_rules(fci_ret, if_cmd, log_if);

                log_cmd__fpp_action_update__destroy_fp_table(fp_table_destroy[0]);
                log_cmd__fpp_action_update__destroy_fp_table(fp_table_destroy[1]);

                log_cmd__fpp_action_update__update_egress(fci_ret, if_cmd, log_if);

                ret = log_cmd__fpp_action_update__set_flags(fci_ret, if_cmd, log_if);
            }
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_QUERY_CONT : Subroutine to write interface statistics and interface flags into the query response buffer.
 */
static errno_t log_cmd__fpp_action_query_cont__stats_and_flags(fpp_log_if_cmd_t *reply_buf, pfe_log_if_t *log_if)
{
    errno_t ret = EINVAL;
    pfe_ct_class_algo_stats_t stats = { 0 };

    ret = pfe_log_if_get_stats(log_if,&stats);
    if(EOK != ret)
    {
        NXP_LOG_ERROR("Could not get interface statistics\n");
    }
    else
    {
        /* Copy the log if statistics to reply */
        (void)autolibc_memcpy(&reply_buf->stats, &stats, sizeof(reply_buf->stats));

        /* Get important flag values */
        (void)autolibc_memset(&reply_buf->flags, 0, sizeof(reply_buf->flags));
        if(pfe_log_if_is_enabled(log_if))
        {
            reply_buf->flags |= oal_htonl(FPP_IF_ENABLED);
        }

        if(pfe_log_if_is_promisc(log_if))
        {
            reply_buf->flags |= oal_htonl(FPP_IF_PROMISC);
        }

        if(pfe_log_if_is_discard(log_if))
        {
            reply_buf->flags |= oal_htonl(FPP_IF_DISCARD);
        }

        if(pfe_log_if_is_match_or(log_if))
        {
            reply_buf->flags |= oal_htonl(FPP_IF_MATCH_OR);
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_QUERY_CONT : Subroutine to write interface rules and their arguments into the query response buffer.
 */
static void log_cmd__fpp_action_query_cont__rules(fpp_log_if_cmd_t *reply_buf, pfe_log_if_t *log_if)
{
    pfe_ct_if_m_rules_t rules;
    pfe_ct_if_m_args_t args;
    char_t *table_name;

    (void)autolibc_memset(&rules, 0, sizeof(pfe_ct_if_m_rules_t));
    (void)autolibc_memset(&args, 0, sizeof(pfe_ct_if_m_args_t));
    /* Store rules for FCI */
    if(EOK != pfe_log_if_get_match_rules(log_if, &rules, &args))
    {
        NXP_LOG_ERROR("Was not possible to get match rules and arguments\n");
    }

    /* Fix endians of FP tables */
    args.fp0_table = oal_ntohl(args.fp0_table);
    args.fp1_table = oal_ntohl(args.fp1_table);
    reply_buf->match = (fpp_if_m_rules_t)(oal_htonl(rules));

    /* Store match rule arguments for FCI */
    reply_buf->arguments.vlan = args.vlan;
    reply_buf->arguments.ethtype = args.ethtype;
    reply_buf->arguments.sport = args.sport;
    reply_buf->arguments.dport = args.dport;
    reply_buf->arguments.proto = args.proto;
    reply_buf->arguments.hif_cookie = args.hif_cookie;

    /* Copy IPV4 or IPV6 according to match rule */
    if (0U != ((((uint32_t)FPP_IF_MATCH_SIP6) | ((uint32_t)FPP_IF_MATCH_DIP6)) & (uint32_t)rules))
    {
        (void)autolibc_memcpy( &reply_buf->arguments.ipv.v6, &args.ipv.v6, sizeof(reply_buf->arguments.ipv.v6));
    }
    else
    {
        (void)autolibc_memcpy( &reply_buf->arguments.ipv.v4, &args.ipv.v4, sizeof(reply_buf->arguments.ipv.v4));
    }

    (void)autolibc_memcpy(reply_buf->arguments.smac, args.smac, 6U);
    (void)autolibc_memcpy(reply_buf->arguments.dmac, args.dmac, 6U);

    /* Translate names of flexible parser tables from addresses to strings. */
    (void)autolibc_memset(reply_buf->arguments.fp_table0, 0, IFNAMSIZ);
    (void)autolibc_memset(reply_buf->arguments.fp_table1, 0, IFNAMSIZ);
    if(EOK == fci_fp_db_get_table_from_addr(args.fp0_table, &table_name))
    {
        (void)autolibc_strcpy(reply_buf->arguments.fp_table0, table_name);
    }
    if(EOK == fci_fp_db_get_table_from_addr(args.fp1_table, &table_name))
    {
        (void)autolibc_strcpy(reply_buf->arguments.fp_table1, table_name);
    }
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_QUERY_CONT : Subroutine to write egress list and interface rules into the query response buffer.
 */
static void log_cmd__fpp_action_query_cont__egress_and_rules(fpp_log_if_cmd_t *reply_buf, pfe_log_if_t *log_if)
{
    uint32_t egress = 0U;

    /* Store egress interfaces */
    if(EOK != pfe_log_if_get_egress_ifs(log_if, &egress))
    {
        NXP_LOG_ERROR("Was not possible to get egress interfaces\n");
    }
    reply_buf->egress = oal_htonl(egress);

    log_cmd__fpp_action_query_cont__rules(reply_buf, log_if);

    /* Set ids */
    reply_buf->id = oal_htonl(pfe_log_if_get_id(log_if));
    reply_buf->parent_id = oal_htonl(pfe_phy_if_get_id(pfe_log_if_get_parent(log_if)));
}

/**
 * @brief           FPP_CMD_LOG_IF + FPP_ACTION_QUERY_CONT
 */
static errno_t log_cmd__fpp_action_query_cont(uint16_t *fci_ret, pfe_if_db_entry_t *entry, fpp_log_if_cmd_t *reply_buf, uint32_t *reply_len)
{
    pfe_phy_if_t *phy_if = NULL;
    pfe_log_if_t *log_if = NULL;
    errno_t ret = EOK;
    bool_t break_switch = FALSE;

    log_if = pfe_if_db_entry_get_log_if(entry);

    if(NULL != log_if)
    {
        phy_if = pfe_log_if_get_parent(log_if);
    }
    /* Store names */
    if(NULL != phy_if)
    {
        (void)autolibc_strncpy(reply_buf->name, pfe_log_if_get_name(log_if), (uint32_t)IFNAMSIZ-1U);
        (void)autolibc_strncpy(reply_buf->parent_name, pfe_phy_if_get_name(phy_if), (uint32_t)IFNAMSIZ-1U);
    }
    else
    {
        NXP_LOG_DEBUG("Was not possible to resolve DB entry to log_if or parent phy_if");
        *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
        break_switch = TRUE;
    }
    if(FALSE == break_switch)
    {
        ret = log_cmd__fpp_action_query_cont__stats_and_flags(reply_buf, log_if);

        if(EOK == ret)
        {
            log_cmd__fpp_action_query_cont__egress_and_rules(reply_buf, log_if);
            *reply_len = sizeof(fpp_log_if_cmd_t);
            *fci_ret = FPP_ERR_OK;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_IF_MAC + FPP_ACTION_REGISTER
 */
static errno_t mac_cmd__fpp_action_register(uint16_t *fci_ret, fpp_if_mac_cmd_t *if_mac_cmd, pfe_phy_if_t *phy_if, pfe_drv_id_t sender_phy_if_id)
{
    errno_t ret = EINVAL;

    ret = pfe_phy_if_add_mac_addr(phy_if, if_mac_cmd->mac, sender_phy_if_id);
    if (EOK != ret)
    {
        if (EEXIST == ret)
        {
            /* FCI command attempted to register already registered entity. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_MAC_ALREADY_REGISTERED;
            ret = EOK;
        }
        if (EINVAL == ret)
        {
            /* FCI command requested unfulfillable action. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_NOT_SUPPORTED;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief           FPP_CMD_IF_MAC + FPP_ACTION_DEREGISTER
 */
static errno_t mac_cmd__fpp_action_deregister(uint16_t *fci_ret, fpp_if_mac_cmd_t *if_mac_cmd, pfe_phy_if_t *phy_if, pfe_drv_id_t sender_phy_if_id)
{
    errno_t ret = EINVAL;

    ret = pfe_phy_if_del_mac_addr(phy_if, if_mac_cmd->mac, sender_phy_if_id);
    if (EOK != ret)
    {
        if (ENOENT == ret)
        {
            /* FCI command requested nonexistent entity. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_MAC_NOT_FOUND;
            ret = EOK;
        }
        if (EINVAL == ret)
        {
            /* FCI command requested unfulfillable action. Respond with FCI error code. */
            *fci_ret = FPP_ERR_IF_NOT_SUPPORTED;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief           Process FPP_CMD_LOG_IF commands
 * @param[in]       msg FCI message containing the FPP_CMD_LOG_IF command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_log_if_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with interface DB session lock.
 */
errno_t fci_interfaces_log_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_log_if_cmd_t *reply_buf, uint32_t *reply_len)
{
    const fci_t *fci_context = (fci_t *)&context;
    fpp_log_if_cmd_t *if_cmd;
    errno_t ret = EOK;
    pfe_if_db_entry_t *entry = NULL;


    ret = fci_interfaces_log_cmd_param_validate(msg, fci_ret, reply_buf, reply_len, fci_context);
    if(E_OK == ret)
    {
        /*  No data written to reply buffer (yet) */
        *reply_len = 0U;
        /*  Initialize the reply buffer */
        (void)autolibc_memset(reply_buf, 0, sizeof(fpp_log_if_cmd_t));

        if_cmd = (fpp_log_if_cmd_t *)msg->msg_cmd.payload;

        switch(if_cmd->action)
        {
            case FPP_ACTION_REGISTER:
            {
                ret = log_cmd__fpp_action_register(fci_ret, if_cmd);
                break;
            }

            case FPP_ACTION_DEREGISTER:
            {
                ret = log_cmd__fpp_action_deregister(fci_ret, if_cmd);
                break;
            }

            case FPP_ACTION_UPDATE:
            {
                ret = log_cmd__fpp_action_update(fci_ret, if_cmd, reply_len);
                break;
            }
            case FPP_ACTION_QUERY:
            {
                ret = pfe_if_db_get_first(fci_context->log_if_db, fci_context->if_session_id, IF_DB_CRIT_ALL, NULL, &entry);
                if (NULL == entry)
                {
                    *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                    evaluate_ret_warning( fci_ret, ret, "Incorrect session ID detected\n", FPP_ERR_IF_WRONG_SESSION_ID);
                    ret = EOK;
                    break;
                }
            }/* FALLTHRU */
            /* no break */

            case FPP_ACTION_QUERY_CONT:
            {
                if (NULL == entry)
                {
                    ret = pfe_if_db_get_next(fci_context->log_if_db, fci_context->if_session_id, &entry);
                    if (NULL == entry)
                    {
                        *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                        evaluate_ret_warning( fci_ret, ret, "Incorrect session ID detected\n", FPP_ERR_IF_WRONG_SESSION_ID);
                        ret = EOK;
                        break;
                    }
                }
                ret = log_cmd__fpp_action_query_cont(fci_ret, entry, reply_buf, reply_len);
                break;
            }
            default:
            {
                /*Do Nothing*/
                break;
            }
        }
    }

    return ret;
}

/**
 * @brief           Validate param before processing FPP_CMD_PHY_IF commands
 * @param[in]       msg FCI message containing the FPP_CMD_PHY_IF command
  * @param[in]      fci_context FCI context
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_phy_if_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with interface DB session lock.
 */

static errno_t fci_interface_phy_param_validate(fci_msg_t *msg, uint16_t *fci_ret, fpp_phy_if_cmd_t *reply_buf, uint32_t *reply_len, const fci_t *fci_context)
{
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == msg) || (NULL == fci_ret) || (NULL == reply_buf) || (NULL == reply_len) || (NULL == fci_context)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(FALSE == fci_context->fci_initialized))
    {
        NXP_LOG_ERROR("Context not initialized\n");
        ret = EPERM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (*reply_len < sizeof(fpp_phy_if_cmd_t))
        {
            NXP_LOG_WARNING("Buffer length does not match expected value (fpp_if_cmd_t)\n");
            ret = EINVAL;
        }
    }

    (void)msg;
    (void)fci_ret;
    (void)reply_buf;
    (void)fci_context;

    return ret;
}

/**
 * @brief           FPP_CMD_PHY_IF + FPP_ACTION_UPDATE
 */
static errno_t phy_cmd__fpp_action_update(uint16_t *fci_ret, fpp_phy_if_cmd_t *if_cmd)
{
    errno_t ret = EOK;
    pfe_phy_if_t *phy_if = NULL;
    bool_t break_switch = FALSE;

    /* Get the requested interface */
    ret = phy_cmd__fpp_action_update__get_phy_if_and_set_mode(fci_ret, if_cmd, &phy_if);
    if(EOK == ret)
    {
        (void) phy_cmd__fpp_action_update__set_mirrors(fci_ret, if_cmd, phy_if);
        ret = phy_cmd__fpp_action_update__set_flags(fci_ret, if_cmd, phy_if, &break_switch);
        if(FALSE == break_switch)
        {
            phy_cmd__fpp_action_update__set_ftable(fci_ret, if_cmd, phy_if);
            ret = phy_cmd__fpp_action_update__set_ptp_mgmt_if(fci_ret, if_cmd, phy_if);
        }
    }

    return ret;
}

/**
 * @brief           Process FPP_CMD_PHY_IF commands
 * @param[in]       msg FCI message containing the FPP_CMD_PHY_IF command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_phy_if_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with interface DB session lock.
 */
errno_t fci_interfaces_phy_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_phy_if_cmd_t *reply_buf, uint32_t *reply_len)
{
    const fci_t *fci_context = (fci_t *)&context;
    fpp_phy_if_cmd_t *if_cmd;
    errno_t ret = EOK;
    pfe_if_db_entry_t *entry = NULL;
    pfe_phy_if_t *phy_if = NULL;

    ret = fci_interface_phy_param_validate(msg, fci_ret, reply_buf, reply_len, fci_context);
    if (EOK == ret)
    {
        /*  No data written to reply buffer (yet) */
        *reply_len = 0U;
        /*  Initialize the reply buffer */
        (void)autolibc_memset(reply_buf, 0, sizeof(fpp_phy_if_cmd_t));

        if_cmd = (fpp_phy_if_cmd_t *)msg->msg_cmd.payload;

        switch (if_cmd->action)
        {
            case FPP_ACTION_UPDATE:
            {
                ret = phy_cmd__fpp_action_update(fci_ret, if_cmd);
                break;
            }

            case FPP_ACTION_QUERY:
            {
                ret = pfe_if_db_get_first(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_ALL, NULL, &entry);

                if(EOK != ret)
                {
                    NXP_LOG_WARNING("Incorrect session ID detected\n");
                    *fci_ret = FPP_ERR_IF_WRONG_SESSION_ID;
                    break;
                }

                if (NULL == entry)
                {
                    ret = EOK;
                    *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                    break;
                }
            } /* FALLTHRU */
            /* no break */

            case FPP_ACTION_QUERY_CONT:
            {
                bool_t break_switch = FALSE;

                ret = phy_cmd__fpp_action_query_cont__part1(fci_ret, entry, reply_buf, &phy_if, &break_switch);

                if(TRUE == break_switch)
                {
                    break;
                }
                ret = phy_cmd__fpp_action_query_cont__part2(fci_ret, reply_buf, phy_if, &break_switch);
                if(TRUE == break_switch)
                {
                    break;
                }

                /* Set reply length end return OK */
                *reply_len = sizeof(fpp_phy_if_cmd_t);
                *fci_ret = FPP_ERR_OK;
                ret = EOK;
                break;
            }

            default:
            {
                NXP_LOG_WARNING("Interface Command: Unknown action received: 0x%x\n", if_cmd->action);
                *fci_ret = FPP_ERR_UNKNOWN_ACTION;
                break;
            }
        }
    }
    return ret;
}

/**
 * @brief           Validate param before processing FPP_CMD_IF_MAC commands
 * @param[in]       msg FCI message containing the FPP_CMD_IF_MAC command
* @param[in]        fci_context FCI context
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_if_mac_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with interface DB session lock.
 */
static errno_t fci_interface_mac_param_validate(fci_msg_t *msg, uint16_t *fci_ret, fpp_if_mac_cmd_t *reply_buf, uint32_t *reply_len, const fci_t *fci_context)
{
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == msg) || (NULL == fci_ret) || (NULL == reply_buf) || (NULL == reply_len) || (NULL == fci_context)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(FALSE == fci_context->fci_initialized))
    {
        NXP_LOG_ERROR("Context not initialized\n");
        ret = EPERM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *fci_ret = FPP_ERR_OK;

        if (*reply_len < sizeof(fpp_if_mac_cmd_t))
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_WARNING("Buffer length does not match expected value (fpp_if_mac_cmd_t)\n");
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            ret = EINVAL;
        }
    }

    (void)msg;
    (void)fci_ret;
    (void)reply_buf;
    (void)fci_context;

    return ret;
}

/**
 * @brief           Process FPP_CMD_IF_MAC commands
 * @param[in]       msg FCI message containing the FPP_CMD_IF_MAC command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_if_mac_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with interface DB session lock.
 */
errno_t fci_interfaces_mac_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_if_mac_cmd_t *reply_buf, uint32_t *reply_len)
{
    const fci_t *fci_context = (fci_t *)&context;
    fpp_if_mac_cmd_t *if_mac_cmd = NULL;
    errno_t ret = EOK;
    pfe_phy_if_t *phy_if = NULL;
    pfe_drv_id_t sender_phy_if_id = (pfe_drv_id_t) PFE_CFG_LOCAL_IF;

    ret = fci_interface_mac_param_validate(msg, fci_ret, reply_buf, reply_len, fci_context);
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    if (EOK == ret)
    {
        /* Get FCI sender */
        ret = fci_sender_get_phy_if_id(msg->msg_cmd.sender, (pfe_ct_phy_if_id_t *) &sender_phy_if_id);
        if (EOK != ret)
        {
            NXP_LOG_WARNING("Unable to get FCI sender");
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
        }
    }
#endif
    if (EOK == ret)
    {
        /* No data written to reply buffer (yet) */
        *reply_len = 0U;
        /* Initialize the reply buffer */
        (void)autolibc_memset(reply_buf, 0, sizeof(fpp_if_mac_cmd_t));

        /* Initialize pointer to the command data */
        if_mac_cmd = (fpp_if_mac_cmd_t *)msg->msg_cmd.payload;
        
        ret = mac_cmd__get_phy_if(fci_ret, if_mac_cmd, &phy_if);

        if ((uint16_t)FPP_ERR_OK == *fci_ret)
        {
            /* Process the command */
            switch (if_mac_cmd->action)
            {
                case FPP_ACTION_REGISTER:
                {
                    ret = mac_cmd__fpp_action_register(fci_ret, if_mac_cmd, phy_if, sender_phy_if_id);

                    /* No further actions. */
                    break;
                }

                case FPP_ACTION_DEREGISTER:
                {
                    ret = mac_cmd__fpp_action_deregister(fci_ret, if_mac_cmd, phy_if, sender_phy_if_id);

                    /*  No further actions. */
                    break;
                }

                case FPP_ACTION_QUERY:
                {
                    ret = pfe_phy_if_get_mac_addr_first(phy_if, reply_buf->mac, MAC_DB_CRIT_ALL, PFE_TYPE_ANY, sender_phy_if_id);
                    ret = mac_cmd__set_fci_ret_based_on_get_mac_addr_ret(fci_ret, ret);
                    ret = mac_cmd__fpp_action_query__finish_and_set_length(fci_ret, reply_buf, reply_len, phy_if);
                    break;
                }

                case FPP_ACTION_QUERY_CONT:
                {
                    ret = pfe_phy_if_get_mac_addr_next(phy_if, reply_buf->mac);
                    ret = mac_cmd__set_fci_ret_based_on_get_mac_addr_ret(fci_ret, ret);
                    ret = mac_cmd__fpp_action_query__finish_and_set_length(fci_ret, reply_buf, reply_len, phy_if);
                    break;
                }

                default: 
                {
                    /* Unknown action. Respond with FCI error code. */
                    NXP_LOG_WARNING("FPP_CMD_IF_MAC: Unknown action received: 0x%x\n", if_mac_cmd->action);
                    *fci_ret = FPP_ERR_UNKNOWN_ACTION;
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

#endif /* PFE_CFG_FCI_ENABLE */
#endif /* PFE_CFG_PFE_MASTER */
