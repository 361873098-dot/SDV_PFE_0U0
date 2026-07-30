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

/**
 * @addtogroup  dxgr_FCI
 * @{
 *
 * @file        fci_msg_autosar.h
 * @brief       The AUTOSAR-specific FCI IPC message (fci_msg_t) format
 * @details     The FCI message is used to transport FCI commands and events
 *              between FCI endpoint and FCI clients (libFCI) using IPC.
 *
 */

#ifndef PUBLIC_FCI_MSG_AUTOSAR_H_
#define PUBLIC_FCI_MSG_AUTOSAR_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#include "fpp.h"

#ifndef SRC_FCI_MSG_H_
#include "fci_msg.h"
#endif

#define FCI_CFG_MSG_FIFO_DEPTH 8

/**
 * @brief   FCI IPC message format
 */
typedef struct CAL_ALIGNED(4)
{
    msg_type_t type;    /* 4 bytes */

    fci_msg_cmd_t msg_cmd;

    /*  FCI internal storage */
    void *client;
} fci_msg_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t fci_core_client_get_msg(fci_msg_t *msg);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_FCI_MSG_AUTOSAR_H_ */

/** @}*/
