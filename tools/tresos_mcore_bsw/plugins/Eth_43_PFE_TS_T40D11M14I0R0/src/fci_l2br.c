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

/**
 * @addtogroup  dxgr_FCI
 * @{
 *
 * @file        fci_l2br.c
 * @brief       L2 bridge management functions.
 * @details     All bridge-related functionality provided by the FCI should be
 *              implemented within this file. This includes mainly bridge-related
 *              commands.
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

#include "fci_internal.h"
#include "fci.h"

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_FCI_ENABLE
#ifdef PFE_CFG_L2BRIDGE_ENABLE

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief           Process FPP_CMD_L2_FLUSH_* commands
 * @param[in]       msg FCI cmd code
 * @param[out]      fci_ret FCI return code
 * @return          EOK if success, error code otherwise
 */
errno_t fci_l2br_flush_cmd(uint32_t code, uint16_t *fci_ret)
{
    const fci_t *fci_context = (fci_t *)&context;
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
        *fci_ret = FPP_ERR_OK;

        switch (code)
        {
            case FPP_CMD_L2_FLUSH_ALL:
            {
                ret = pfe_l2br_flush_all(fci_context->l2_bridge);
                if (EOK != ret)
                {
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                    NXP_LOG_ERROR("Can't flush MAC table entries: %d\n", ret);
                }

                break;
            }

            case FPP_CMD_L2_FLUSH_LEARNED:
            {
                ret = pfe_l2br_flush_learned(fci_context->l2_bridge);
                if (EOK != ret)
                {
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                    NXP_LOG_ERROR("Can't flush learned MAC table entries: %d\n", ret);
                }

                break;
            }

            case FPP_CMD_L2_FLUSH_STATIC:
            {
                ret = pfe_l2br_flush_static(fci_context->l2_bridge);
                if (EOK != ret)
                {
                    *fci_ret = FPP_ERR_INTERNAL_FAILURE;
                    NXP_LOG_ERROR("Can't flush static MAC table entries: %d\n", ret);
                }

                break;
            }

            default:
            {
                NXP_LOG_WARNING("Unknown L2 bridge command: 0x%x\n", (uint_t)code);
                *fci_ret = FPP_ERR_UNKNOWN_ACTION;
                break;
            }
        }
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_L2BRIDGE_ENABLE */
#endif /* PFE_CFG_FCI_ENABLE */
#endif /* PFE_CFG_PFE_MASTER */
