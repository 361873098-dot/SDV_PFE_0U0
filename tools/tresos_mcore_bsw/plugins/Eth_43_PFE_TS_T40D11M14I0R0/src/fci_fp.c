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
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "libfci.h"
#include "fpp.h"
#include "fpp_ext.h"
#include "fci_fp_db.h"
#include "pfe_fp.h"
#include "fci_msg.h"
#include "fci.h"
#include "fci_internal.h"
#include "pfe_class.h"
#include "fci_fp.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/

static void fci_fp_construct_rule_reply(fpp_fp_rule_props_t *r, fci_fp_rule_info_t *rules, char *next_rule);
static uint16_t set_fci_ret(errno_t ret);
static uint16_t set_rule_reply(errno_t ret, fci_fp_rule_info_t *rule, char **next_rule, fpp_fp_rule_props_t *r,  uint32_t *reply_len);
static errno_t register_rule(fpp_fp_rule_cmd_t *fp_cmd, uint16_t *fci_ret);
#if defined(PFE_CFG_NULL_ARG_CHECK)
static errno_t null_arg_check(fci_msg_t *msg, uint16_t *fci_ret, void *reply_buf, uint32_t *reply_len);
#endif /* PFE_CFG_NULL_ARG_CHECK */


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
* @brief Constructs a query reply with specified rule parameters in the specified buffer
* @param[in] r Buffer where to construct the query reply
* @param[in] rules Structure containing the rules
* @param[in] next_rule Value of the next_rule parameter of the replied rule
*/
static void fci_fp_construct_rule_reply(fpp_fp_rule_props_t *r, fci_fp_rule_info_t *rules, char *next_rule)
{
    (void)autolibc_strncpy((char_t *)r->rule_name, rules->rule_name, 15);
    r->data = rules->data;
    r->mask = rules->mask;
    r->offset = rules->offset;
    if(NULL != next_rule)
    {
        (void)autolibc_strncpy((char_t *)r->next_rule_name, next_rule, 15);
    }
    if(((uint8_t)rules->flags & (uint8_t)FP_FL_ACCEPT) != 0U)
    {
        /*  Ensure correct endianess */
        r->match_action = FP_ACCEPT;
    }
    else if(((uint8_t)rules->flags & (uint8_t)FP_FL_REJECT) != 0U)
    {
        r->match_action = FP_REJECT;
    }
    else
    {
        r->match_action = FP_NEXT_RULE;
    }
    if(((uint8_t)rules->flags & (uint8_t)FP_FL_INVERT) != 0U)
    {
        r->invert = TRUE;
    }
    else
    {
        r->invert = FALSE;
    }

    if(((uint8_t)rules->flags & (uint8_t)FP_FL_L3_OFFSET) != 0U)
    {
        r->offset_from = FP_OFFSET_FROM_L3_HEADER;
    }
    else if(((uint8_t)rules->flags & (uint8_t)FP_FL_L4_OFFSET) != 0U)
    {
        r->offset_from = FP_OFFSET_FROM_L4_HEADER;
    }
    else
    {
        r->offset_from = FP_OFFSET_FROM_L2_HEADER;
    }
}

#if defined(PFE_CFG_NULL_ARG_CHECK)
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

/**
 * @brief           Auxiliary function to check ret value and set fci_ret value
 * @param[in]       ret error code to evaluate
 * @return          FPP_ERR_OK if success, FPP_ERR_WRONG_COMMAND_PARAM otherwise
 */
static uint16_t set_fci_ret(errno_t ret)
{
    uint16_t fci_ret;

    if(EOK == ret)
    {
        fci_ret = FPP_ERR_OK;
    }
    else
    {
        fci_ret = FPP_ERR_WRONG_COMMAND_PARAM;
    }

    return fci_ret;
}

/**
 * @brief           Auxiliary function to check ret value and construct reply
 * @param[in]       ret error code to evaluate
 * @param[in]       rule Structure containing the rules
 * @param[in]       reply_buf Pointer to a buffer where function will construct command reply (fpp_fp_table_cmd_t)
 * @param[inout]    next_rule Value of the next_rule parameter of the replied rule
 * @param[in]       reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          FPP_ERR_OK if success, FPP_ERR_WRONG_COMMAND_PARAM otherwise
 */
static uint16_t set_rule_reply(errno_t ret, fci_fp_rule_info_t *rule, char **next_rule, fpp_fp_rule_props_t *r,  uint32_t *reply_len)
{
    uint16_t fci_ret;

    if(EOK == ret)
    {
        fci_fp_construct_rule_reply(r, rule, *next_rule);
        fci_ret = FPP_ERR_OK;
        *reply_len = sizeof(fpp_fp_table_cmd_t);
    }
    else
    {
        fci_ret = FPP_ERR_FP_RULE_NOT_FOUND;
    }

    return fci_ret;
}

/**
 * @brief           Prepare data for rule
 * @param[in]       fp_cmd fp command rule table pointer
 * @param[out]      fci_ret FCI command return value
 * @return          EOK if success, error code otherwise
 */
static errno_t register_rule(fpp_fp_rule_cmd_t *fp_cmd, uint16_t *fci_ret)
{
    errno_t ret = EOK;
    pfe_ct_fp_flags_t flags = FP_FL_NONE;

    switch(fp_cmd->r.match_action)
    {
        case FP_ACCEPT:
            flags |= FP_FL_ACCEPT;
            break;
        case FP_REJECT:
            flags |= FP_FL_REJECT;
            break;
        case FP_NEXT_RULE:
            break;
        default:
            NXP_LOG_WARNING("Impossible happened\n");
            *fci_ret = FPP_ERR_WRONG_COMMAND_PARAM;
            ret = EINVAL;
            break;
    }
    if(EOK == ret)
    {
        switch(fp_cmd->r.offset_from)
        {
            case FP_OFFSET_FROM_L2_HEADER:
                break;
            case FP_OFFSET_FROM_L3_HEADER:
                flags |= FP_FL_L3_OFFSET;
                break;
            case FP_OFFSET_FROM_L4_HEADER:
                flags |= FP_FL_L4_OFFSET;
                break;
            default:
                NXP_LOG_WARNING("Impossible happened\n");
                *fci_ret = FPP_ERR_WRONG_COMMAND_PARAM;
                ret = EINVAL;
                break;
        }
        if(EOK == ret)
        {
            if(0U != fp_cmd->r.invert)
            {
                flags |= FP_FL_INVERT;
            }

            ret = fci_fp_db_create_rule((char_t *)fp_cmd->r.rule_name, fp_cmd->r.data, fp_cmd->r.mask,
                                    fp_cmd->r.offset, flags,
                                    (char_t *)fp_cmd->r.next_rule_name);
            *fci_ret = set_fci_ret(ret);
        }
    }

    return ret;
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief           Processes FPP_CMD_FP_TABLE commands
 * @param[in]       msg FCI message containing the FPP_CMD_FP_TABLE command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_fp_table_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with domain DB protected against concurrent accesses.
 */
errno_t fci_fp_table_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_fp_table_cmd_t *reply_buf, uint32_t *reply_len)
{
    fpp_fp_table_cmd_t *fp_cmd;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    ret = null_arg_check(msg, fci_ret, (void*) reply_buf, reply_len);
    if (likely(EOK == ret))
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Important to initialize to avoid buffer overflows */
        if (*reply_len < sizeof(fpp_fp_table_cmd_t))
        {
            NXP_LOG_WARNING("Buffer length does not match expected value (fpp_fp_table_cmd_t)\n");
            ret = EINVAL;
        }
        else
        {
            /*  No data written to reply buffer (yet) */
            *reply_len = 0U;
            fp_cmd = (fpp_fp_table_cmd_t *)(msg->msg_cmd.payload);
            switch (fp_cmd->action)
            {
                case FPP_ACTION_REGISTER:
                {
                    ret = fci_fp_db_create_table((char_t *)fp_cmd->table_info.t.table_name);
                    *fci_ret = set_fci_ret(ret);
                    break;
                }
                case FPP_ACTION_DEREGISTER:
                {
                    ret = fci_fp_db_destroy_table((char_t *)fp_cmd->table_info.t.table_name, FALSE);
                    *fci_ret = set_fci_ret(ret);
                    break;
                }
                case FPP_ACTION_USE_RULE:
                {
                    ret = fci_fp_db_add_rule_to_table((char_t *)fp_cmd->table_info.t.table_name, (char_t *)fp_cmd->table_info.t.rule_name, oal_ntohs(fp_cmd->table_info.t.position));
                    *fci_ret = set_fci_ret(ret);
                    break;
                }
                case FPP_ACTION_UNUSE_RULE:
                {
                    ret = fci_fp_db_remove_rule_from_table((char_t *)fp_cmd->table_info.t.rule_name);
                    *fci_ret = set_fci_ret(ret);
                    break;
                }
                case FPP_ACTION_QUERY:
                {
                    fci_fp_rule_info_t rule = {0};
                    char *next_rule = NULL_PTR;

                    ret = fci_fp_db_get_table_first_rule((char_t *)fp_cmd->table_info.t.table_name, &rule, &next_rule);
                    *fci_ret = set_rule_reply(ret, &rule, &next_rule, &reply_buf->table_info.r, reply_len);
                    break;
                }
                case FPP_ACTION_QUERY_CONT:
                {
                    fci_fp_rule_info_t rule = {0};
                    char *next_rule = NULL_PTR;

                    ret = fci_fp_db_get_table_next_rule((char_t *)fp_cmd->table_info.t.table_name, &rule, &next_rule);
                    *fci_ret = set_rule_reply(ret, &rule, &next_rule, &reply_buf->table_info.r, reply_len);
                    break;
                }
                default:
                {
                    NXP_LOG_WARNING("FPP_CMD_L2_BD: Unknown action received: 0x%x\n", fp_cmd->action);
                    *fci_ret = FPP_ERR_UNKNOWN_ACTION;
                    break;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           Processes FPP_CMD_FP_RULE commands
 * @param[in]       msg FCI message containing the FPP_CMD_FP_RULE command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_fp_rule_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 * @note            Function is only called within the FCI worker thread context.
 * @note            Must run with domain DB protected against concurrent accesses.
 */
errno_t fci_fp_rule_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_fp_rule_cmd_t *reply_buf, uint32_t *reply_len)
{
    fpp_fp_rule_cmd_t *fp_cmd;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    ret = null_arg_check(msg, fci_ret, (void*) reply_buf, reply_len);
    if (likely(EOK == ret))
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (*reply_len < sizeof(fpp_fp_rule_cmd_t))
        {
            NXP_LOG_WARNING("Buffer length does not match expected value (fpp_fp_rule_cmd_t)\n");
            ret = EINVAL;
        }
        else
        {
            /*  No data written to reply buffer (yet) */
            *reply_len = 0U;

            fp_cmd = (fpp_fp_rule_cmd_t *)(msg->msg_cmd.payload);
            switch (fp_cmd->action)
            {
                case FPP_ACTION_REGISTER:
                {
                    ret = register_rule(fp_cmd,fci_ret);
                    break;
                }
                case FPP_ACTION_DEREGISTER:
                {
                    ret = fci_fp_db_destroy_rule((char_t*)fp_cmd->r.rule_name);
                    *fci_ret = set_fci_ret(ret);
                    break;
                }
                case FPP_ACTION_QUERY:
                {
                    fci_fp_rule_info_t rule = {0};
                    char *next_rule = NULL_PTR;

                    ret = fci_fp_db_get_first_rule(&rule, &next_rule);
                    *fci_ret = set_rule_reply(ret, &rule, &next_rule, &reply_buf->r, reply_len);
                    break;
                }
                case FPP_ACTION_QUERY_CONT:
                {
                    fci_fp_rule_info_t rule = {0};
                    char *next_rule = NULL_PTR;

                    ret = fci_fp_db_get_next_rule(&rule, &next_rule);
                    *fci_ret = set_rule_reply(ret, &rule, &next_rule, &reply_buf->r, reply_len);
                    break;
                }

                default:
                {
                    NXP_LOG_WARNING("FPP_CMD_L2_BD: Unknown action received: 0x%x\n", fp_cmd->action);
                    *fci_ret = FPP_ERR_UNKNOWN_ACTION;
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
