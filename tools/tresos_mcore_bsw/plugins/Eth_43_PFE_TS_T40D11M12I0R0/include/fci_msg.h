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
 * @file        fci_msg.h
 * @brief       The FCI IPC message type
 * @details     This header provides the fci_msg_t.
 *
 */

#ifndef SRC_FCI_MSG_H_
#define SRC_FCI_MSG_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43120440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43120440
#endif

#include "ct_assert.h"

/**
 * @brief   Maximum size of FCI IPC message payload
 * @see     fci_msg_t
 */
#define FCI_CFG_MAX_CMD_PAYLOAD_LEN     256U

/**
 * @brief   FCI message types
 * @see     fci_msg_t
 */
typedef enum
{
    FCI_MSG_TYPE_MIN = 0x1000,
    FCI_MSG_CLIENT_REGISTER,
    FCI_MSG_CLIENT_UNREGISTER,
    FCI_MSG_CMD,
    FCI_MSG_CORE_CLIENT_BROADCAST,
    /* Ensure proper size */
    FCI_MSG_TYPE_MAX = (int)(1U << 31U)
} msg_type_t;

ct_assert(sizeof(msg_type_t) == sizeof(uint32_t));

/**
 * @brief   FCI message command type
 */
typedef struct
{
    uint32_t code;                                  /*!< Message code */
    uint32_t length;                                /*!< Message length */
    uint32_t sender;                                /*!< Message sender originator identifier */
    uint8_t payload[FCI_CFG_MAX_CMD_PAYLOAD_LEN];   /*!< Message payload */
} fci_msg_cmd_t;

#include "fci_msg_autosar.h"

#endif /* SRC_FCI_MSG_H_ */

/** @}*/
