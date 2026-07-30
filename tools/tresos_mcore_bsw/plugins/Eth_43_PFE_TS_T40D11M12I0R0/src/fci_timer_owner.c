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
 *  Copyright 2023 NXP
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

#include "pfe_cfg.h"
#include "oal.h"
#include "libfci.h"
#include "fpp.h"
#include "fpp_ext.h"
#include "pfe_platform.h"
#include "fci_internal.h"
#include "fci.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
static pfe_phy_if_t *fci_get_phy_if_by_name(char_t *name);

/**
 * @brief           Get physical interface by name
 * @param[in]       name The name of the physical interface
 * @return          the physical interface phy_if
 */
static pfe_phy_if_t *fci_get_phy_if_by_name(char_t *name)
{
    fci_t *fci_context = (fci_t *)&context;
    pfe_if_db_entry_t *entry = NULL;
    pfe_phy_if_t *phy_if = NULL;
    errno_t ret;
    uint32_t sid;

    ret = pfe_if_db_lock(&sid);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Could not lock interface DB: %d\n", ret);
    }
    else
    {
        ret = pfe_if_db_get_first(fci_context->phy_if_db, sid, IF_DB_CRIT_BY_NAME, name, &entry);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Interface DB query failed: %d\n", ret);
        }

        if(NULL != entry)
        {
            phy_if = pfe_if_db_entry_get_phy_if(entry);
        }
    }
    
    ret = pfe_if_db_unlock(sid);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Interface DB unlock failed: %d\n", ret);
    }

    return phy_if;
}

/**
 * @brief           Acquire FCI timer ownership
 * @param[in]       msg FCI message containing the command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_timer_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 */
errno_t fci_timer_owner_lock_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_timer_cmd_t *reply_buf, uint32_t *reply_len)
{
    fci_t *fci_context = (fci_t *)&context;
    fpp_timer_cmd_t *timer_cmd;
    pfe_phy_if_t *phy_if = NULL;
    errno_t ret = EOK;
    bool_t has_owner = FALSE;
    pfe_drv_id_t cur_owner = PFE_PHY_IF_ID_INVALID;

#if defined(PFE_CFG_NULL_ARG_CHECK)
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
#else
    (void)fci_context;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (*reply_len < sizeof(fpp_timer_cmd_t))
        {
            NXP_LOG_ERROR("Buffer length does not match expected value (fpp_timer_cmd_t)\n");
            ret = EINVAL;
        }
        else
        {
            /*  No data written to reply buffer (yet) */
            *reply_len = 0U;
            /*  Initialize the reply buffer */
            (void)autolibc_memset(reply_buf, 0, sizeof(fpp_timer_cmd_t));
            timer_cmd = (fpp_timer_cmd_t *)msg->msg_cmd.payload;

            switch(timer_cmd->action)
            {
                case FPP_ACTION_UPDATE:
                {
                    *fci_ret = FPP_ERR_OK;

                    /*  Get physical interface ID */
                    phy_if = fci_get_phy_if_by_name(timer_cmd->if_name);
                    if (NULL == phy_if)
                    {
                        /* FCI command requested nonexistent entity. Respond with FCI error code. */
                        NXP_LOG_DEBUG("No interface '%s'\n", timer_cmd->if_name);
                        *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                        ret = ENOENT;
                        break;
                    }
                    else if (PFE_PHY_IF_EMAC != pfe_phy_if_get_type(phy_if))
                    {
                        /* FCI command requested unfulfillable action. Respond with FCI error code. */
                        *fci_ret = FPP_ERR_IF_NOT_SUPPORTED;
                        ret = EOK;
                        break;
                    }
                    else
                    {
                        ; /* MISRA */
                    }
                    
                    /* Set the sender is timer owner of EMAC */
                    ret = pfe_emac_set_timer_ownership(pfe_phy_if_get_emac(phy_if), (pfe_drv_id_t)msg->msg_cmd.sender);
                    if (EOK == ret)
                    {
                        *fci_ret = FPP_ERR_OK;
                    }
                    else
                    {
                        /* Check if the sender was owner of EMAC */
                        ret = pfe_emac_check_timer_ownership(pfe_phy_if_get_emac(phy_if), &has_owner, &cur_owner);
                        if ((EOK == ret) && (TRUE == has_owner))
                        {
                            if (msg->msg_cmd.sender == cur_owner)
                            {
                                *fci_ret = FPP_ERR_OK;
                            }
                            else
                            {
                                *fci_ret = FPP_ERR_TIMER_ALREADY_LOCKED;
                                NXP_LOG_WARNING("The EMAC is locked by another driver instance: %d\n", cur_owner);
                            }
                        }
                        else
                        {
                            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                        }
                    }

                    break;
                }

                default:
                {
                    NXP_LOG_ERROR("FPP_CMD_TIMER_LOCK: Unknown action received: 0x%x\n", timer_cmd->action);
                    *fci_ret = FPP_ERR_UNKNOWN_ACTION;
                    break;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           Release FCI timer ownership
 * @param[in]       msg FCI message containing the command
 * @param[out]      fci_ret FCI command return value
 * @param[out]      reply_buf Pointer to a buffer where function will construct command reply (fpp_timer_cmd_t)
 * @param[in,out]   reply_len Maximum reply buffer size on input, real reply size on output (in bytes)
 * @return          EOK if success, error code otherwise
 */
errno_t fci_timer_owner_unlock_cmd(fci_msg_t *msg, uint16_t *fci_ret, fpp_timer_cmd_t *reply_buf, uint32_t *reply_len)
{
    fci_t *fci_context = (fci_t *)&context;
    fpp_timer_cmd_t *timer_cmd;
    pfe_phy_if_t *phy_if = NULL;
    errno_t ret = EOK;
    bool_t has_owner = FALSE;
    pfe_drv_id_t cur_owner = PFE_PHY_IF_ID_INVALID;

#if defined(PFE_CFG_NULL_ARG_CHECK)
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
#else
    (void)fci_context;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (*reply_len < sizeof(fpp_timer_cmd_t))
        {
            NXP_LOG_ERROR("Buffer length does not match expected value (fpp_timer_cmd_t)\n");
            ret = EINVAL;
        }
        else
        {
            /*  No data written to reply buffer (yet) */
            *reply_len = 0U;
            /*  Initialize the reply buffer */
            (void)autolibc_memset(reply_buf, 0, sizeof(fpp_timer_cmd_t));
            timer_cmd = (fpp_timer_cmd_t *)msg->msg_cmd.payload;

            switch(timer_cmd->action)
            {
                case FPP_ACTION_UPDATE:
                {
                    *fci_ret = FPP_ERR_OK;

                    /*  Get physical interface ID */
                    phy_if = fci_get_phy_if_by_name(timer_cmd->if_name);
                    if (NULL == phy_if)
                    {
                        /* FCI command requested nonexistent entity. Respond with FCI error code. */
                        *fci_ret = FPP_ERR_IF_ENTRY_NOT_FOUND;
                        ret = ENOENT;
                        break;
                    }
                    else if (PFE_PHY_IF_EMAC != pfe_phy_if_get_type(phy_if))
                    {
                        /* FCI command requested unfulfillable action. Respond with FCI error code. */
                        *fci_ret = FPP_ERR_IF_NOT_SUPPORTED;
                        ret = EOK;
                        break;
                    }
                    else
                    {
                        ; /* MISRA */
                    }

                    /* Set the sender is not timer owner of EMAC */
                    ret = pfe_emac_clear_timer_ownership(pfe_phy_if_get_emac(phy_if), (pfe_drv_id_t)msg->msg_cmd.sender);
                    if (EOK == ret)
                    {
                        *fci_ret = FPP_ERR_OK;
                    }
                    else
                    {
                        /* Get timer ownership status and check if the sender is not the current owner of EMAC */
                        ret = pfe_emac_check_timer_ownership(pfe_phy_if_get_emac(phy_if), &has_owner, &cur_owner);
                        if ((EOK == ret) && (TRUE == has_owner))
                        {
                            if (msg->msg_cmd.sender != cur_owner)
                            {
                                *fci_ret = FPP_ERR_TIMER_NOT_OWNER;
                            }
                            else
                            {
                                *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                            }
                        }
                        else
                        {
                            *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                        }
                    }

                    break;
                }

                default:
                {
                    NXP_LOG_ERROR("FPP_CMD_TIMER_UNLOCK: Unknown action received: 0x%x\n", timer_cmd->action);
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
