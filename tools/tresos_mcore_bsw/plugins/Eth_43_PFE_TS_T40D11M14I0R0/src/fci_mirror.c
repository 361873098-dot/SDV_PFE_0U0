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
 *  Copyright 2021-2024 NXP
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
#include "libfci.h"
#include "fpp.h"
#include "fpp_ext.h"
#include "fci_fp_db.h"
#include "fci_msg.h"
#include "fci.h"
#include "fci_internal.h"
#include "oal.h"
#include "fci_mirror.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"


static errno_t fci_mirror_cmd_update_egress_port(fci_t **fci_context, pfe_mirror_t **mirror, uint16_t **fci_ret, fpp_mirror_cmd_t *mirror_cmd);
static errno_t fci_mirror_cmd_update_set_filter(fci_t *fci_context, pfe_mirror_t **mirror, uint16_t **fci_ret, fpp_mirror_cmd_t *mirror_cmd);
static errno_t fci_mirror_cmd_query_cont_get_mirror(fci_t *fci_context, pfe_mirror_t **mirror, uint16_t **fci_ret, fpp_mirror_cmd_t **reply_buf);
static errno_t mirror_cmd_fpp_action_register(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd, bool_t *break_switch);
static errno_t mirror_cmd_fpp_query_cont(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *reply_buf, uint32_t *reply_len);
static errno_t mirror_cmd_fpp_action_update(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd);
static errno_t mirror_cmd_get_mirror(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd);
static errno_t mirror_cmd_fpp_action_deregister(uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd);
static errno_t remove_fp_filter(errno_t ret, uint32_t addr, uint16_t **fci_ret);
static pfe_ct_phy_if_id_t get_egress_interface(fpp_mirror_cmd_t **reply_buf, pfe_mirror_t *tmp_mirror);
static errno_t fill_reply_buf(fpp_mirror_cmd_t **reply_buf, pfe_phy_if_t *phy_if, pfe_mirror_t *tmp_mirror, fci_t *fci_context);
#if defined(PFE_CFG_NULL_ARG_CHECK)
static errno_t null_arg_check(fci_msg_t *msg, uint16_t *fci_ret, void *reply_buf, uint32_t *reply_len);

/**
 * @brief           Auxiliary function to check for NULL arguments
 * @param[in]       msg FCI message containing the FPP_CMD_FP_TABLE command
 * @param[in]       fci_ret FCI command return value
 * @param[in]       reply_buf Pointer to a buffer where function will construct command reply (fpp_fp_table_cmd_t)
 * @param[in]       reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 */
static errno_t null_arg_check(fci_msg_t *msg, uint16_t *fci_ret, void *reply_buf, uint32_t *reply_len)
{
    errno_t ret=EOK;
    const fci_t *fci_context = (fci_t *)&context;

    if (unlikely((NULL == msg) || (NULL == fci_ret) || (NULL == reply_buf) || (NULL == reply_len)))
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
    {
        /*MISRA required*/
    }

    return ret;
}
#endif /* PFE_CFG_NULL_ARG_CHECK */

static errno_t fci_mirror_cmd_update_egress_port(fci_t **fci_context, pfe_mirror_t **mirror, uint16_t **fci_ret, fpp_mirror_cmd_t *mirror_cmd)
{
    errno_t             ret;
    pfe_ct_phy_if_id_t  egress_id;
    pfe_phy_if_t        *phy_if     = NULL;
    pfe_if_db_entry_t   *entry      = NULL;

    /* Lock interface db and get the requested interface */
    ret = pfe_if_db_lock(&(*fci_context)->if_session_id);
    if(EOK != ret)
    {
        /* FCI command requested unfulfillable action. Respond with FCI error code. */
        **fci_ret = FPP_ERR_IF_RESOURCE_ALREADY_LOCKED;
        ret = EOK;
    }
    else
    {

        (void)pfe_if_db_get_first((*fci_context)->phy_if_db, (*fci_context)->if_session_id, IF_DB_CRIT_BY_NAME, mirror_cmd->egress_phy_if, &entry);
        if (NULL != entry)
        {
            phy_if = pfe_if_db_entry_get_phy_if(entry);
        }

        if((NULL == entry) || (NULL == phy_if))
        {
            /* FCI command requested nonexistent entity. Respond with FCI error code. */
            (void)pfe_if_db_unlock((*fci_context)->if_session_id);
            NXP_LOG_DEBUG("No interface '%s'\n", mirror_cmd->egress_phy_if);
            **fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
            ret = EOK;
        }
        else
        {
            /* Set the interface as mirror's egress port */
            egress_id = pfe_phy_if_get_id(phy_if);
            ret = pfe_mirror_set_egress_port((*mirror), egress_id);
            if(EOK != ret)
            {
                /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                (void)pfe_if_db_unlock((*fci_context)->if_session_id);
                NXP_LOG_ERROR("Cannot set egress port for '%s'\n", mirror_cmd->name);
                **fci_ret = FPP_ERR_INTERNAL_FAILURE;
            }
            else
            {
                (void)pfe_if_db_unlock((*fci_context)->if_session_id);
            }
        }
    }

    return ret;
}

static errno_t remove_fp_filter(errno_t ret, uint32_t addr, uint16_t **fci_ret)
{
    const char *str;

    if(0U != addr)
    {   /* Some filter (Flexible Parser table) is used. Get it and remove it from DMEM. */
        ret = fci_fp_db_get_table_from_addr(addr, (char **)&str);
        if(EOK != ret)
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_ERROR("Cannot obtain filter name.\n");
            **fci_ret = FPP_ERR_INTERNAL_FAILURE;
        }
        else
        {
            (void)fci_fp_db_pop_table_from_hw((char *)str);
        }
    }

    return ret;
}

static errno_t fci_mirror_cmd_update_set_filter(fci_t *fci_context, pfe_mirror_t **mirror, uint16_t **fci_ret, fpp_mirror_cmd_t *mirror_cmd)
{
    errno_t ret = EOK;
    uint32_t addr;

    if('\0' == mirror_cmd->filter_table_name[0U])
    {   /* FCI command requests that the filter shall be disabled */
        /* Check if the mirror currently uses some filter. */
        addr = pfe_mirror_get_filter((*mirror));
        ret = remove_fp_filter(ret, addr, fci_ret);

        if(EOK == ret)
        {
            /* Disable the filter */
            ret = pfe_mirror_set_filter((*mirror), 0U);
            if(EOK != ret)
            {
                /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                NXP_LOG_WARNING("Failed to disable filter on mirror '%s'.\n", mirror_cmd->name);
                **fci_ret = FPP_ERR_INTERNAL_FAILURE;
                ret = EOK;
            }
        }
    }
    else
    {   /* FCI command requests that the filter shall be enabled or replaced by another one. */

        /* Check that the newly requested filter exists */
        if (NULL == fci_fp_db_get_first(FP_TABLE_CRIT_NAME, mirror_cmd->filter_table_name))
        {
            /* FCI command requested nonexistent entity. Respond with FCI error code. */
            NXP_LOG_WARNING("Requested filter table '%s' does not exist.\n", mirror_cmd->filter_table_name);
            **fci_ret = FPP_ERR_WRONG_COMMAND_PARAM;
            ret = EOK;
        }
        else
        {
            /* Check if the mirror currently uses some filter. */
            addr = pfe_mirror_get_filter((*mirror));
            ret = remove_fp_filter(ret, addr, fci_ret);

            if(EOK == ret)
            {
                /* Set the filter */
                addr = fci_fp_db_get_table_dmem_addr((char_t *)mirror_cmd->filter_table_name);
                if(0U == addr)
                {   /* Requested filter table (from FCI command) is not used anywhere yet. Good. Use it as filter. */

                    /* Add filter table to HW */
                    (void)fci_fp_db_push_table_to_hw(fci_context->class, (char_t *)mirror_cmd->filter_table_name);
                    addr = fci_fp_db_get_table_dmem_addr((char_t *)mirror_cmd->filter_table_name);

                    /* Update filter address of mirror */
                    ret = pfe_mirror_set_filter((*mirror), addr);
                    if(EOK != ret)
                    {
                        /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                        NXP_LOG_ERROR("Failed to set filter %s to mirror %s\n", mirror_cmd->filter_table_name, mirror_cmd->name);
                        **fci_ret = FPP_ERR_INTERNAL_FAILURE;
                    }
                }
                else
                {   /* Requested filter table (from FCI command) is already used somewhere and cannot be used here. */

                    /* FCI command requested unfulfillable action. Respond with FCI error code. */
                    NXP_LOG_WARNING("Filter '%s' already in use, but it should not be!\n", mirror_cmd->filter_table_name);
                    **fci_ret = FPP_ERR_WRONG_COMMAND_PARAM;
                    ret = EOK;
                }
            }
        }
    }

    return ret;
}

static errno_t fill_reply_buf(fpp_mirror_cmd_t **reply_buf, pfe_phy_if_t *phy_if, pfe_mirror_t *tmp_mirror, fci_t *fci_context)
{
    errno_t ret = EOK;
    pfe_ct_route_actions_t m_actions;
    const char *str;
    uint32_t addr;
    pfe_ct_route_actions_args_t m_args;

    /* Get egress port name, step #2 - get name of the egress interface */
    str = pfe_phy_if_get_name(phy_if);
    (void)autolibc_strncpy((*reply_buf)->egress_phy_if, str, (uint32_t)IFNAMSIZ - 1U);
    (*reply_buf)->egress_phy_if[(uint32_t)IFNAMSIZ - 1U] = '\0';  /* Ensure termination */
    (void)pfe_if_db_unlock(fci_context->if_session_id);

    /* Get filter name */
    (void)autolibc_memset((*reply_buf)->filter_table_name, 0, IFNAMSIZ);
    addr = pfe_mirror_get_filter(tmp_mirror);
    if(0U != addr)
    {
        ret = fci_fp_db_get_table_from_addr(addr, (char **)&str);
        if(EOK == ret)
        {
            (void)autolibc_strncpy((*reply_buf)->filter_table_name, str, 15);
            (*reply_buf)->filter_table_name[15] = '\0';  /* Ensure termination */
        }
    }

    /* Initialize */
    (void)autolibc_memset(&m_args, 0, sizeof(pfe_ct_route_actions_args_t));
    m_actions = RT_ACT_NONE;

    /* Get modification actions */
    (*reply_buf)->m_actions = MODIFY_ACT_NONE;
    (void)pfe_mirror_get_actions(tmp_mirror, &m_actions, &m_args);
    m_actions = (pfe_ct_route_actions_t) oal_ntohl(m_actions);  /* PFE has modification actions in big endian. */
    if(0U != ((uint32_t)m_actions & (uint32_t)RT_ACT_ADD_VLAN_HDR))
    {
        (*reply_buf)->m_actions |= MODIFY_ACT_ADD_VLAN_HDR;
        (*reply_buf)->m_args.vlan = m_args.vlan;
    }
    (*reply_buf)->m_actions = (fpp_modify_actions_t)oal_htonl((*reply_buf)->m_actions);

    return ret;
}

static pfe_ct_phy_if_id_t get_egress_interface(fpp_mirror_cmd_t **reply_buf, pfe_mirror_t *tmp_mirror)
{
    const char *str;

    /* Get mirror name */
    str = pfe_mirror_get_name(tmp_mirror);
    (void)autolibc_strncpy((*reply_buf)->name, str, sizeof((*reply_buf)->name) - 1U);

    return pfe_mirror_get_egress_port(tmp_mirror);
}

static errno_t fci_mirror_cmd_query_cont_get_mirror(fci_t *fci_context, pfe_mirror_t **mirror, uint16_t **fci_ret, fpp_mirror_cmd_t **reply_buf)
{
    errno_t ret = EOK;
    pfe_ct_phy_if_id_t egress_id;
    pfe_if_db_entry_t *entry = NULL;
    pfe_phy_if_t *phy_if = NULL;

    **fci_ret = FPP_ERR_OK;
    /* If not fallthrough, then get the next mirror */
    if(NULL == *mirror)
    {
        *mirror = pfe_mirror_get_next();
        if(NULL == *mirror)
        {
            /* End of the query process (no more entities to report). Respond with FCI error code. */
            **fci_ret = FPP_ERR_MIRROR_NOT_FOUND;
            ret = EOK;
        }
    }

    if(FPP_ERR_OK == **fci_ret)
    {
        /* Get egress port name, step #1 - find the egress interface in the interface db */
        egress_id = get_egress_interface(reply_buf, *mirror);
        ret = pfe_if_db_lock(&fci_context->if_session_id);
        if(EOK != ret)
        {
            /* FCI command requested unfulfillable action. Respond with FCI error code. */
            **fci_ret = FPP_ERR_IF_RESOURCE_ALREADY_LOCKED;
            ret = EOK;
        }
        else
        {
            (void)pfe_if_db_get_single(fci_context->phy_if_db, fci_context->if_session_id, IF_DB_CRIT_BY_ID, (void *)(addr_t)egress_id, &entry);
            if (NULL != entry)
            {
                phy_if = pfe_if_db_entry_get_phy_if(entry);
            }

            if((NULL == entry) || (NULL == phy_if))
            {
                /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                (void)pfe_if_db_unlock(fci_context->if_session_id);
                NXP_LOG_ERROR("Cannot get egress interface of the mirror '%s'.\n", pfe_mirror_get_name(*mirror));
                **fci_ret = FPP_ERR_INTERNAL_FAILURE;
                ret = ENOENT;
            }
            else
            {
                ret = fill_reply_buf(reply_buf, phy_if, *mirror, fci_context);
            }
        }
    }

    return ret;
}

static errno_t mirror_cmd_fpp_action_register(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd, bool_t *break_switch)
{
    errno_t ret = EOK;

    *break_switch = FALSE;

    /* Check that the requested mirror name is not already registered */
    *mirror = pfe_mirror_get_first(MIRROR_BY_NAME, mirror_cmd->name);
    if (NULL != *mirror)
    {
        /*  Notify mirror module we are done working with the mirror instance. */
        pfe_mirror_put(*mirror);
        *mirror = NULL;
        /* FCI command attempted to register already registered entity. Respond with FCI error code. */
        NXP_LOG_DEBUG("Mirror '%s' is already registered.\n", mirror_cmd->name);
        *fci_ret = FPP_ERR_MIRROR_ALREADY_REGISTERED;
        ret = EOK;
        *break_switch = TRUE;
    }
    else
    {
        /* Create mirror */
        *mirror = pfe_mirror_create(mirror_cmd->name);
        if (NULL == *mirror)
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_WARNING("Cannot create mirror '%s'\n", mirror_cmd->name);
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            ret = EPERM;
            *break_switch = TRUE;
        }
    }

    return ret;
}

static errno_t mirror_cmd_fpp_action_update(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd)
{
    errno_t ret = EOK;
    fci_t *fci_context = (fci_t *)&context;
    pfe_ct_route_actions_args_t m_args;
    pfe_ct_route_actions_t m_actions;

    /* 1) Set egress port */
    ret = fci_mirror_cmd_update_egress_port(&fci_context, mirror, &fci_ret, mirror_cmd);
    if(FPP_ERR_OK == *fci_ret)
    {
        /* 2) Set filter to select frames */
        ret = fci_mirror_cmd_update_set_filter(fci_context, mirror, &fci_ret, mirror_cmd);
        if(FPP_ERR_OK == *fci_ret)
        {
            /* 3) Set modification actions */
            mirror_cmd->m_actions = (fpp_modify_actions_t)oal_ntohl(mirror_cmd->m_actions);
            if(MODIFY_ACT_NONE == mirror_cmd->m_actions)
            {   /* No modifications */
                ret = pfe_mirror_set_actions(*mirror, RT_ACT_NONE, NULL);
                if(EOK != ret)
                {
                    NXP_LOG_ERROR("Failed to set modification action: MODIFY_ACT_NONE.\n");
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                }
            }
            else
            {   /* Some actions to be set - add one by one */
                /* Initialize */
                (void)autolibc_memset(&m_args, 0, sizeof(pfe_ct_route_actions_args_t));
                m_actions = RT_ACT_NONE;

                /* Start adding */
                if(0U != ((uint32_t)mirror_cmd->m_actions & (uint32_t)MODIFY_ACT_ADD_VLAN_HDR))
                {   /* VLAN header add/replace */
                    m_args.vlan = mirror_cmd->m_args.vlan;
                    m_actions |= RT_ACT_ADD_VLAN_HDR;
                }

                /* Apply */
                m_actions = (pfe_ct_route_actions_t) oal_htonl(m_actions);  /* PFE has modification actions in big endian. */
                ret = pfe_mirror_set_actions(*mirror, m_actions, &m_args);
                if(EOK != ret)
                {
                    NXP_LOG_ERROR("Failed to set modification actions.\n");
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                }
            }
        }
    }

    return ret;
}

static errno_t mirror_cmd_fpp_action_deregister(uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd)
{
    errno_t ret = EOK;
    pfe_mirror_t *mirror = NULL;
    const char *str;
    uint32_t addr;

    /* Get mirror */
    mirror = pfe_mirror_get_first(MIRROR_BY_NAME, mirror_cmd->name);
    if(NULL == mirror)
    {
        /* FCI command requested nonexistent entity. Respond with FCI error code. */
        NXP_LOG_DEBUG("No mirror with name '%s'\n", mirror_cmd->name);
        *fci_ret = FPP_ERR_MIRROR_NOT_FOUND;
        ret = EOK;
    }
    else
    {
        /* Note filter address (if any). */
        addr = pfe_mirror_get_filter(mirror);
        /* Destroy the mirror. */
        ret = pfe_mirror_destroy(mirror);
        if (EBUSY == ret)
        {
            /*  Notify mirror module we are done working with the mirror instance. */
            pfe_mirror_put(mirror);
            mirror = NULL;
            /* FCI command requested unfulfillable action. Respond with FCI error code. */
            NXP_LOG_WARNING("Cannot destroy a mirror (it is currently utilized).\n");
            *fci_ret = FPP_ERR_MIRROR_CURRENTLY_UTILIZED;
            ret = EOK;
            /* Intentionally skip destruction of filter. We are keeping the mirror completely intact. */
        }
        else
        {
            mirror = NULL;  /* Mirror was destroyed. */
            /* Check if the mirror had some filter. */
            if(0U != addr)
            {   /* Some filter (Flexible Parser table) is used. Get it and remove it from DMEM. */
                ret = fci_fp_db_get_table_from_addr(addr, (char **)&str);
                if(EOK != ret)
                {
                    /* No need to release the mirror instance here. The instance is already destroyed. */
                    /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
                    NXP_LOG_ERROR("Cannot obtain filter name.\n");
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                }
                else
                {
                    (void)fci_fp_db_pop_table_from_hw((char *)str);
                }
            }
        }
    }

    return ret;
}

static errno_t mirror_cmd_get_mirror(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *mirror_cmd)
{
    errno_t ret = EOK;

    if(NULL == *mirror)
    {   /* Not the FALLTHRU case - obtain the mirror */
        /* Get mirror */
        *mirror = pfe_mirror_get_first(MIRROR_BY_NAME, mirror_cmd->name);
        if(NULL == *mirror)
        {
            /* FCI command requested nonexistent entity. Respond with FCI error code. */
            NXP_LOG_DEBUG("No mirror with name '%s'\n", mirror_cmd->name);
            *fci_ret = FPP_ERR_MIRROR_NOT_FOUND;
            ret = EINVAL;
        }
    }

    return ret;
}

static errno_t mirror_cmd_fpp_query_cont(pfe_mirror_t **mirror, uint16_t *fci_ret, fpp_mirror_cmd_t *reply_buf, uint32_t *reply_len)
{
    errno_t ret = EOK;
    fci_t *fci_context = (fci_t *)&context;

    ret = fci_mirror_cmd_query_cont_get_mirror(fci_context, mirror, &fci_ret, &reply_buf);
    if(FPP_ERR_OK == *fci_ret)
    {
        /* Set reply length end return OK */
        *reply_len = sizeof(fpp_mirror_cmd_t);
        ret = EOK;
    }

    return ret;
}

/**
 * @brief           Processes FPP_CMD_MIRROR commands
 * @param[in]       msg FCI message containing the FPP_CMD_MIRROR command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_mirror_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 */
errno_t fci_mirror_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_mirror_cmd_t *reply_buf, uint32_t *reply_len)
{
    fpp_mirror_cmd_t *mirror_cmd;
    errno_t ret = EOK;
    pfe_mirror_t *mirror = NULL;
    bool_t break_switch = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    ret = null_arg_check(msg, fci_ret, (void*) reply_buf, reply_len);
    if (likely(EOK == ret))
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *fci_ret = FPP_ERR_OK;

        /* Important to initialize to avoid buffer overflows */
        if (*reply_len < sizeof(fpp_mirror_cmd_t))
        {
            /* Internal problem. Set fci_ret, but respond with detected internal error code (ret). */
            NXP_LOG_WARNING("Buffer length does not match expected value (fpp_mirror_cmd_t)\n");
            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
            ret = EINVAL;
        }
        else
        {
            /* No data written to reply buffer (yet) */
            *reply_len = 0U;

            (void)autolibc_memset(reply_buf, 0, sizeof(fpp_mirror_cmd_t));
            mirror_cmd = (fpp_mirror_cmd_t *)(msg->msg_cmd.payload);

            switch (mirror_cmd->action)
            {
                case FPP_ACTION_REGISTER:
                {
                    ret = mirror_cmd_fpp_action_register(&mirror, fci_ret, mirror_cmd, &break_switch);
                    if (TRUE == break_switch)
                    {
                        break;
                    }
                }/* FALLTHRU */
                /* no break */

                case FPP_ACTION_UPDATE:
                {
                    ret = mirror_cmd_get_mirror(&mirror, fci_ret, mirror_cmd);
                    if(EOK == ret)
                    {
                        ret = mirror_cmd_fpp_action_update(&mirror, fci_ret, mirror_cmd);
                    }
                    /*  Notify mirror module we are done working with the mirror instance. */
                    pfe_mirror_put(mirror);
                    mirror = NULL;
                    break;
                }

                case FPP_ACTION_DEREGISTER:
                {
                    ret = mirror_cmd_fpp_action_deregister(fci_ret, mirror_cmd);
                    break;
                }

                case FPP_ACTION_QUERY:
                {
                    /* Get the first mirror */
                    mirror = pfe_mirror_get_first(MIRROR_ANY, NULL);
                    if(NULL == mirror)
                    {
                        /* End of the query process (no more entities to report). Respond with FCI error code. */
                        *fci_ret = FPP_ERR_MIRROR_NOT_FOUND;
                        ret = EOK;
                        break;
                    }
                }/* FALLTHRU */
                /* no break */

                case FPP_ACTION_QUERY_CONT:
                {
                    ret = mirror_cmd_fpp_query_cont(&mirror, fci_ret, reply_buf, reply_len);
                    /*  Notify mirror module we are done working with the mirror instance. */
                    pfe_mirror_put(mirror);
                    mirror = NULL;
                    break;
                }

                default:
                {
                    /* Unknown command. Respond with FCI error code. */
                    NXP_LOG_WARNING("FPP_CMD_MIRROR command: Unknown action received: 0x%x\n", mirror_cmd->action);
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
