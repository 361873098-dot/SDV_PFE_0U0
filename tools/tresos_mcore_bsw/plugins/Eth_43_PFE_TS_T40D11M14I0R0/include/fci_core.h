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
 * @file        fci_core.h
 * @brief       The FCI core header file
 * @details     The FCI core is OS-specific module responsible for:
 *                  -   IPC with FCI clients running within separated processes within the OS
 *                      environment.
 *                  -   Reception of commands from clients and executing OS-independent command
 *                      translator provided by FCI.
 *                  -   Maintenance of list of the clients.
 *                  -   Provision of API to the rest of FCI to communicate with the clients.
 *
 *              This file specifies common API the FCI core implementation has to implement.
 *
 */

#ifndef SRC_FCI_CORE_H_
#define SRC_FCI_CORE_H_

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

#include "oal_types.h"  /* Common types */
#include "fci_msg.h"    /* The fci_msg_t and related stuff */

/**
 * @brief   Maximum number of event listeners (FCI clients) which can be
 *          registered to receive runtime notifications from the FCI
 *          endpoint.
 */
#define FCI_CFG_MAX_CLIENTS             5

/**
 * @brief   FCI core type
 * @details This is OS-specific part of FCI
 */
typedef struct fci_core_tag fci_core_t;

/**
 * @brief   FCI core client type
 */
typedef struct fci_core_client_tag fci_core_client_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Create FCI core instance
 * @details     The FCI core is OS-specific part of the FCI endpoint. It is responsible
 *              for IPC connectivity with the rest of system.
 * @param[in]   id String identifier specifying the core instance. Intended to be used
 *              by libFCI to locate the endpoint.
 * @retval      EOK Success
 * @retval      EINVAL invalid argument received
 * @retval      ENOMEM initialization failed
 */
errno_t fci_core_init(const char_t *const id);

/**
 * @brief       Destroy FCI core
 * @details     Close all connections and release all associated resources
 */
void fci_core_fini(void);

/**
 * @brief       Send message to the FCI core
 * @param[in]   msg Pointer to the buffer containing payload to be sent
 * @param[in]   rep Pointer to buffer where reply data shall be stored
 * @return      EOK if success, error code otherwise
 */
errno_t fci_core_send(fci_msg_t *msg, fci_msg_t *rep);

/**
 * @brief       Send message to FCI client
 * @param[in]   client The FCI client instance
 * @param[in]   msg Pointer to the buffer containing payload to be sent
 * @param[in]   rep Pointer to buffer where reply data shall be stored
 * @return      EOK if success, error code otherwise
 */
errno_t fci_core_client_send(fci_core_client_t *client, fci_msg_t *msg, fci_msg_t *rep);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* SRC_FCI_CORE_H_ */

/** @}*/
