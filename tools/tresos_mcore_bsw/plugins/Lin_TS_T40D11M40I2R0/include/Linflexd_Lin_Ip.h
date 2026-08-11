/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef LINFLEXD_LIN_IP_H
#define LINFLEXD_LIN_IP_H

/**
*   @file Linflexd_Lin_Ip.h
*
*   @addtogroup LINFLEXD_IP
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Linflexd_Lin_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_LIN_IP_VENDOR_ID                      43
#define LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION       4
#define LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION       4
#define LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION    0
#define LINFLEXD_LIN_IP_SW_MAJOR_VERSION               4
#define LINFLEXD_LIN_IP_SW_MINOR_VERSION               0
#define LINFLEXD_LIN_IP_SW_PATCH_VERSION               2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Linflexd_Lin_Ip_Cfg.h */
#if (LINFLEXD_LIN_IP_VENDOR_ID != LINFLEXD_LIN_IP_CFG_VENDOR_ID)
    #error "Linflexd_Lin_Ip.h and Linflexd_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION    != LINFLEXD_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION != LINFLEXD_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Linflexd_Lin_Ip.h and Linflexd_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Cfg header file are of the same Software version */
#if ((LINFLEXD_LIN_IP_SW_MAJOR_VERSION != LINFLEXD_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_SW_MINOR_VERSION != LINFLEXD_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_SW_PATCH_VERSION != LINFLEXD_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Lin_Ip.h and Linflexd_Lin_Ip_Cfg.h are different"
#endif

/* Checks against Linflexd_Lin_Ip_Types.h */
#if (LINFLEXD_LIN_IP_VENDOR_ID != LINFLEXD_LIN_IP_TYPES_VENDOR_ID)
    #error "Linflexd_Lin_Ip.h and Linflexd_Lin_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Types header file are of the same Autosar version */
#if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION    != LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION != LINFLEXD_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Linflexd_Lin_Ip.h and Linflexd_Lin_Ip_Types.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Types header file are of the same Software version */
#if ((LINFLEXD_LIN_IP_SW_MAJOR_VERSION != LINFLEXD_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_SW_MINOR_VERSION != LINFLEXD_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_SW_PATCH_VERSION != LINFLEXD_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Lin_Ip.h and Linflexd_Lin_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Lin_Ip.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define LINFLEXD_LIN_IP_LINSR_W1C_ALL_FLAGS_U32    ((uint32)( LINFLEXD_LINSR_RMB(1) \
                                                     | LINFLEXD_LINSR_DRBNE(1) \
                                                     | LINFLEXD_LINSR_WUF(1) \
                                                     | LINFLEXD_LINSR_DTF(1) \
                                                     | LINFLEXD_LINSR_HRF(1) \
                                                     | LINFLEXD_LINSR_DRF(1)) \
                                                   )
#define LINFLEXD_LIN_IP_LINESR_W1C_ALL_FLAGS_U32   ((uint32)( LINFLEXD_LINESR_SZF(1) \
                                                     | LINFLEXD_LINESR_OCF(1) \
                                                     | LINFLEXD_LINESR_BEF(1) \
                                                     | LINFLEXD_LINESR_CEF(1) \
                                                     | LINFLEXD_LINESR_SFEF(1) \
                                                     | LINFLEXD_LINESR_SDEF(1) \
                                                     | LINFLEXD_LINESR_IDPEF(1) \
                                                     | LINFLEXD_LINESR_FEF(1) \
                                                     | LINFLEXD_LINESR_BOF(1)) \
                                                   )


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                     STRUCTURES AND OTHERS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/*!
 * @brief Initializes an LIN_LINFLEXD instance for LIN Network.
 *
 * The caller provides memory for the driver state structures during initialization.
 * The user must select the LIN_LINFLEXD clock source in the application to initialize the LIN_LINFLEXD.
 * This function initializes a LINFLEXD instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the LINFLEXD module transmitter and receiver
 *
 * @param instance LIN_LINFLEXD instance number
 * @param LinUserConfig user configuration structure of type #Linflexd_Lin_Ip_UserConfigType
 * @return  LINFLEXD_LIN_IP_STATUS_SUCCESS - Initialization command has been accepted.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - Initialization command has not been accepted. 
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_Init(const uint8 Instance, const Linflexd_Lin_Ip_UserConfigType *LinUserConfig);

/*!
 * @brief Shuts down the LIN_LINFLEXD by disabling interrupts and transmitter/receiver.
 *
 * @param instance LIN_LINFLEXD instance number
 * @return  LINFLEXD_LIN_IP_STATUS_SUCCESS - De-initialization command has been accepted.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - De-initialization command has not been accepted.
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_Deinit(const uint8 Instance);

/*!
 * @brief Sends frame out through the LIN_LINFLEXD module using non-blocking method.
 *  This enables an a-sync method for transmitting data.
 *  Non-blocking  means that the function returns immediately.
 *  The application has to get the transmit status to know when the transmit is complete.
 *  This function will calculate the checksum byte and send it with the frame data after header transmitted.
 *  If frame size is equal to 0 or greater than 8 or node's current state is in SLEEP mode
 *  then the function will return STATUS_ERROR. If isBusBusy is currently true then the
 *  function will return STATUS_BUSY.
 *
 * @param instance LIN_LINFLEXD instance number
 * @param PduInfoPtr contains information of frame
 * @return operation status:
 *          LINFLEXD_LIN_IP_STATUS_SUCCESS - Send command has been accepted.
 *          LINFLEXD_LIN_IP_STATUS_BUSY - Operation failed due to hardware instance busy.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - Send command has not been accepted. 
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_SendFrame(const uint8 Instance, const Linflexd_Lin_Ip_PduType *PduInfoPtr);

/*!
 * @brief Aborts an on-going non-blocking transmission/reception.
 *  While performing a non-blocking transferring data, users can call this function
 *  to terminate immediately the transferring.
 *
 * @param instance LIN_LINFLEXD instance number
 * @return operation status:
 *          LINFLEXD_LIN_IP_STATUS_SUCCESS - Abort transfer is successful.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - Abort transfer is fail.
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_AbortTransferData(const uint8 Instance);

/*!
 * @brief This function is used to retrieve the current state of the lin node.
 *
 * @param Instance LIN_LINFLEXD instance number
 * @return operation status: Linflexd_Lin_Ip_NodeStateType
 */
Linflexd_Lin_Ip_NodeStateType Linflexd_Lin_Ip_GetCurrentNodeState(const uint8 Instance);

/*!
 * @brief This function returns the status of the current non-blocking transfer.
 *  If a response reception has been successfully received, Buffer will be referenced to receive buffer.
 *
 * @param Instance LIN_LINFLEXD instance number
 * @param Buffer contain received data if reception completed
 * @return operation status: Linflexd_Lin_Ip_TransferStatusType
 */
Linflexd_Lin_Ip_TransferStatusType Linflexd_Lin_Ip_GetStatus(const uint8 Instance, uint8 **Buffer);

/*!
 * @brief This function puts current node to sleep mode
 * This function changes current node state to LIN_NODE_STATE_SLEEP_MODE
 *
 * @param instance LIN_LINFLEXD instance number
 * @return operation status:
 *          LINFLEXD_LIN_IP_STATUS_SUCCESS - Command has been accepted.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - Command has not been accepted, error occurred.
 *          LINFLEXD_LIN_IP_STATUS_TIMEOUT - Operation has timeout 
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_GoToSleepMode(const uint8 Instance);

/*!
 * @brief This function puts current node to idle mode
 *
 * @param instance LIN_LINFLEXD instance number
 * @return
 *          LINFLEXD_LIN_IP_STATUS_SUCCESS - Command has been accepted.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - Command has not been accepted, error occurred.
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_GotoIdleState(const uint8 Instance);

/*!
 * @brief Sends a wakeup signal through the LIN_LINFLEXD interface
 *
 * @param instance LIN_LINFLEXD instance number
 * @return operation status:
 *          LINFLEXD_LIN_IP_STATUS_SUCCESS - Command has been accepted.
 *          LINFLEXD_LIN_IP_STATUS_ERROR - Command has not been accepted, error occurred.
 *          LINFLEXD_LIN_IP_STATUS_BUSY - Bus busy flag is true.
 */
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_SendWakeupSignal(const uint8 Instance);

void Linflexd_Lin_Ip_TxRx_IRQHandler(const uint32 Instance);
void Linflexd_Lin_Ip_Error_IRQHandler(const uint32 Instance);

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_LIN_IP_H */
