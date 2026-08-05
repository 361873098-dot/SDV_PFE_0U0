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
 * @addtogroup  dxgr_FCI
 * @{
 *
 * @file        fci_hm.c
 * @brief       Health Monitor management functions.
 * @details     All Health Monitor-related functionality provided by the FCI should be
 *              implemented within this file.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "libfci.h"
#include "fpp.h"
#include "fpp_ext.h"
#include "pfe_hm.h"

#include "fci_internal.h"
#include "fci.h"

#ifdef PFE_CFG_FCI_ENABLE

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief      Callback from Health Monitor (HM) module. Intended for sending of FPP_CMD_HEALTH_MONITOR_EVENT.
 * @details    This callback is used by FCI as a notification of some HM activity.
 *             Function parameter is not utilized. A full search through HM database is done instead, 
 *             to make sure all existing HM items were reported.
 * @param[in]  unused  Health Monitor item as reported by HM module.
 *                     Not needed in this callback, but required by HM callback function signature.
 */
static void fci_hm_cb(pfe_hm_item_t *unused)
{
    fci_t *fci_context = (fci_t *)&context;
    errno_t ret;
    pfe_hm_item_t item;
    fci_msg_t msg;
    fpp_health_monitor_cmd_t hm_event = {0};
    uint8_t u8LoopCnt = 0U;

    (void)unused;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(FALSE == fci_context->fci_initialized))
    {
        NXP_LOG_RAW_ERROR("Context not initialized\n");
        ret = EPERM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        msg.type = FCI_MSG_CMD;
        msg.msg_cmd.code = FPP_CMD_HEALTH_MONITOR_EVENT;
        msg.msg_cmd.length = sizeof(fpp_health_monitor_cmd_t);
        msg.msg_cmd.sender = 0U;
        msg.client = NULL;

        /* Consume items from HM database and send FCI event for each of them. */
        do
        {
            if (FALSE == fci_context->is_some_client) /* Consume only if there is someone to send data to. */
            {
                ret = EPERM;
                NXP_LOG_DEBUG("No client to send data to.\n");
            }
            else
            {
                ret = pfe_hm_get(&item);
                if (EOK != ret)
                {
                    NXP_LOG_DEBUG("No more items in HM database\n");
                }
                else
                {
                    hm_event.action = 0U;
                    hm_event.id = oal_htons(item.id);
                    hm_event.type = (uint8_t)item.type;
                    hm_event.src = (uint8_t)item.src;
#ifdef NXP_LOG_ENABLED
                    (void)autolibc_strncpy(hm_event.desc, pfe_hm_get_event_str(item.id), (FPP_HEALTH_MONITOR_DESC_SIZE-1U));
#endif /* NXP_LOG_ENABLED */
                    {
                        /* Indented code block needed because ct_assert() otherwise causes
                         * compilation error 'ISO C90 forbids mixed declarations and code' */
                        ct_assert(sizeof(msg.msg_cmd.payload) >= sizeof(fpp_health_monitor_cmd_t));
                        (void)autolibc_memcpy(msg.msg_cmd.payload, &hm_event, sizeof(fpp_health_monitor_cmd_t));
                    }
                    ret = fci_core_client_send_broadcast(&msg, NULL);
                    u8LoopCnt++;
                }
            }
        }
        while ((EOK == ret) && (u8LoopCnt < PFE_HM_QUEUE_LEN));

#ifdef NXP_LOG_ENABLED
        if (u8LoopCnt >= PFE_HM_QUEUE_LEN)
        {
            NXP_LOG_WARNING("It already has too many events reported, and we exit intentionally\n");
        }
#endif /* NXP_LOG_ENABLED */
    }
}

/**
 * @brief  Read HM items from HM database and send FCI event for each reported HM item.
 */
void fci_hm_send_events(void)
{
    fci_hm_cb(NULL);
}

/**
 * @brief   Register FCI callback in Health Monitor module. This needs to be called during FCI init.
 * @return  EOK if success, error code otherwise.
 */
errno_t fci_hm_cb_register(void)
{
    errno_t ret = EINVAL;

    if (TRUE == pfe_hm_register_event_cb(fci_hm_cb))
    {
       ret = EOK;
    }

    return ret;
}

/**
 * @brief   Deregister FCI callback from Health Monitor module. This needs to be called during FCI fini.
 * @return  EOK if success, error code otherwise.
 */
errno_t fci_hm_cb_deregister(void)
{
    return EOK; /* HM module currently does not support callback deregistration. */
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_FCI_ENABLE */
