/**
*   @file    Lin_43_LLCE.h
*   @implements Lin.h_Artifact
*   @version 1.0.7
*
*   @brief   AUTOSAR Lin_43_LLCE - High level header of LIN driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup LIN_LLCE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.
*   By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to comply with and are bound
*   by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
*   may not retain, install, activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_43_LLCE_H
#define LIN_43_LLCE_H

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

#include "ComStackTypes.h"
#include "Lin_GeneralTypes.h"
#include "Lin_43_LLCE_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LLCE_VENDOR_ID                      43
#if ((LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) || (LIN_43_LLCE_VERSION_INFO_API == STD_ON))
#define LIN_43_LLCE_MODULE_ID                      82
#endif  /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
#define LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION       4
#define LIN_43_LLCE_AR_RELEASE_MINOR_VERSION       4
#define LIN_43_LLCE_AR_RELEASE_REVISION_VERSION    0
#define LIN_43_LLCE_SW_MAJOR_VERSION               1
#define LIN_43_LLCE_SW_MINOR_VERSION               0
#define LIN_43_LLCE_SW_PATCH_VERSION               7
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin_Cfg header file are of the same Autosar version */
#if (LIN_43_LLCE_VENDOR_ID != LIN_43_LLCE_CFG_VENDOR_ID)
    #error "Lin_43_LLCE.h and Lin_43_LLCE_Cfg.h have different vendor ids"
#endif
#if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION    != LIN_43_LLCE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION    != LIN_43_LLCE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LLCE_AR_RELEASE_REVISION_VERSION != LIN_43_LLCE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LLCE.h and Lin_43_LLCE_Cfg.h are different"
#endif
/* Check if current file and Lin_Cfg header file are of the same Software version */
#if ((LIN_43_LLCE_SW_MAJOR_VERSION != LIN_43_LLCE_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LLCE_SW_MINOR_VERSION != LIN_43_LLCE_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LLCE_SW_PATCH_VERSION != LIN_43_LLCE_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lin_43_LLCE.h and Lin_43_LLCE_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStack_Types header file are of the same Autosar version */
    #if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LLCE.h and ComStackTypes.h are different"
    #endif

    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LLCE.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
/**
* @brief            API service used without module initialization
* @details          The LIN Driver module shall report the development error "LIN_43_LLCE_E_UNINIT (0x00)",
*                   when the API Service is used without module initialization.
*
*/
#define LIN_43_LLCE_E_UNINIT            ((uint8)0x00U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LLCE_E_INVALID_CHANNEL (0x02)", when API Service used with
*                   an invalid or inactive channel parameter.
*
*/
#define LIN_43_LLCE_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LLCE_E_INVALID_POINTER (0x03)", when API Service is called
*                   with invalid configuration pointer.
*
*/
#define LIN_43_LLCE_E_INVALID_POINTER   ((uint8)0x03U)

/**
* @brief            Invalid state transition for the current state
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LLCE_E_STATE_TRANSITION (0x04)", when Invalid state transition
*                   occurs from the current state.
*
*/
#define LIN_43_LLCE_E_STATE_TRANSITION  ((uint8)0x04U)

/**
* @brief            API service called with a NULL pointer
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LLCE_E_PARAM_POINTER (0x05)", when API Service is called
*                   with a NULL pointer. In case of this error, the API service
*                   shall return immediately without any further action,
*                   beside reporting this development error.
*
*/
#define LIN_43_LLCE_E_PARAM_POINTER  ((uint8)0x05U)


/**
* @brief            Timeout caused by hardware error
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LLCE_E_TIMEOUT (0x06)", when the error "Timeout caused by hardware error"
*                   has occurred and the reference LinDemEventParameterRefs/LIN_E_TIMEOUT is
*                   not configured.
*
*/
#define LIN_43_LLCE_E_TIMEOUT       ((uint8)0x06U)
#endif  /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */

/**
* @brief            LIN driver states
* @details          The state LIN_43_LLCE_UNINIT means that the Lin module has not
*                   been initialized yet and cannot be used.
*
*/
#define LIN_43_LLCE_UNINIT              (0x01U)

/**
* @brief            LIN driver states
* @details          The LIN_43_LLCE_INIT state indicates that the LIN driver has been
*                   initialized, making each available channel ready for service.
*
*/
#define LIN_43_LLCE_INIT                (0x02U)

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
/* API functions service IDs.*/

/**
* @brief            API service ID for Lin_43_LLCE_GetStatus() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_GETSTATUS_ID            ((uint8)0x08U)

#if (LIN_43_LLCE_VERSION_INFO_API == STD_ON)
/**
* @brief            API service ID for Lin_GetVersionInfo() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_GETVERSIONINFO_ID       ((uint8)0x01U)
#endif /* (LIN_43_LLCE_VERSION_INFO_API == STD_ON) */

/**
* @brief            API service ID for Lin_43_LLCE_GoToSleep() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_GOTOSLEEP_ID            ((uint8)0x06U)
/**
* @brief            API service ID for Lin_43_LLCE_GoToSleepInternal() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_GOTOSLEEPINTERNAL_ID    ((uint8)0x09U)
/**
* @brief            API service ID for Lin_43_LLCE_Init() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_INIT_ID                 ((uint8)0x00U)
/**
* @brief            API service ID for Lin_43_LLCE_SendFrame() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_SENDFRAME_ID            ((uint8)0x04U)
/**
* @brief            API service ID for Lin_43_LLCE_WakeUp() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_WAKEUP_ID               ((uint8)0x07U)
/**
* @brief            API service ID for Lin_43_LLCE_WakeupInternal() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_WAKEUPINTERNAL_ID       ((uint8)0x0BU)
/**
* @brief            API service ID for Lin_43_LLCE_CheckWakeup() function.
* @details          Parameters used when raising an error or exception.
*
*/
#define LIN_43_LLCE_CHECKWAKEUP_ID          ((uint8)0x0AU)
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

#if (LIN_43_LLCE_PRECOMPILE_SUPPORT == STD_OFF)
/* Export Post-Build configurations.*/
LIN_43_LLCE_CONFIG_EXT
#endif /* (LIN_43_LLCE_PRECOMPILE_SUPPORT == STD_OFF) */

#define LIN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

/**
* @brief   Validates for upper layers the wake up of LIN channel.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver.
*          This function calls EcuM and LinIf only the first time
*          ater the wake up event.
*
* @retval E_OK         No error has occurred during execution of the API
* @retval E_NOT_OK     An error has occurred during execution of the API
*
* @note    Autosar Service ID: 0x0A.
*
*/
Std_ReturnType  Lin_43_LLCE_CheckWakeup(uint8 Channel);

/**
* @brief   Initializes the LIN module.
* @details This function performs software initialization of LIN
*          driver:
*          - Clears the shadow buffer of all available Lin channels
*          - Set LIN channel state machine of all available Lin
*            channels to LIN_CH_OPERATIONAL
*          - Set frame operation state machine of all available LIN
*            channels to LIN_CH_READY_STATE
*          - Set driver state machine to LIN_43_LLCE_INIT.
*
* @param[in] Config        Pointer to LIN driver configuration set.
*
* @return  void
*
* @note    Autosar Service ID: 0x00.
* @note    Synchronous, non reentrant function.
*
*/
void            Lin_43_LLCE_Init(const Lin_43_LLCE_ConfigType * Config);

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
    /**
    * @brief   Gets the status of the LIN driver.
    * @details This function returns the state of the current
    *          transmission, reception or operation status.
    *          If the reception of a Slave response was successful then
    *          this service provides a pointer to the buffer where the
    *          data is stored.
    *
    * @param[in] Channel       LIN channel to be checked.
    *
    * @param[out] Lin_SduPtr   Lin_SduPtr pointer to pointer to a shadow
    *                          buffer or memory mapped LIN Hardware
    *                          receive buffer where the current SDU is
    *                          stored.
    * @return                  Lin_StatusType.
    * @retval LIN_NOT_OK       Development or production error raised
    *                          none of the below conditions.
    * @retval LIN_TX_OK        Successful transmission.
    * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
    * @retval LIN_TX_HEADER_ERROR Error occurred during header
    *                          transmission.
    * @retval LIN_TX_ERROR     Error occurred during response
    *                          transmission.
    * @retval LIN_RX_OK        Reception of correct response.
    * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
    *                          has been received.
    * @retval LIN_RX_ERROR     Error occurred during reception.
    * @retval LIN_RX_NO_RESPONSE No data byte has been received yet.
    * @retval LIN_OPERATIONAL  Channel is ready for next header.
    *                          transmission and no data are available.
    * @retval LIN_CH_SLEEP     Channel is in sleep mode.
    *
    * @note    Autosar Service ID: 0x08.
    * @note    Synchronous, non reentrant function.
    *
    */
    Lin_StatusType  Lin_43_LLCE_GetStatus(uint8 Channel, \
                                                  uint8 ** Lin_SduPtr \
                                                 );

    /**
    * @brief   Sends a LIN frame.
    * @details Sends a LIN header and a LIN response, if necessary. The
    *          direction of the frame response (master response, slave
    *          response, slave-to-slave communication) is provided by
    *          the PduInfoPtr.
    *
    * @param[in] Channel       LIN channel to be addressed.
    * @param[in] PduInfoPtr    pointer to PDU containing the PID,
    *                          Checksum model, Response type, Dl and SDU
    *                          data pointer.
    *
    * @return                  Std_ReturnType.
    * @retval E_NOT_OK         If the LIN Channel is not valid or
    *                          LIN driver is not initialized or
    *                          PduInfoPtr is NULL or
    *                          a timeout occurs or
    *                          LIN Channel is in sleep state.
    * @retval E_OK             Otherwise.
    *
    * @note    Autosar Service ID: 0x04.
    * @note    Synchronous, non reentrant function.
    *
    */
    Std_ReturnType  Lin_43_LLCE_SendFrame(uint8 Channel, \
                                                  const Lin_PduType * PduInfoPtr \
                                                 );

    /**
    * @brief   The service instructs the driver to transmit a
    *          go-to-sleep-command on the addressed LIN channel.
    * @details This function stops any ongoing transmission and initiates
    *          the transmission of the sleep command (master command
    *          frame with ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF,
    *          0xFF, 0xFF, 0xFF, 0xFF). State transition in
    *          LIN_CH_SLEEP_STATE shall be done after the completion of
    *          the sleep command transmission regardless of the success
    *          (therefore the ISR is responsible to put the channel in
    *          LIN_CH_SLEEP_STATE).
    *
    * @param[in] Channel       LIN channel to be checked.
    *
    * @return                  Std_ReturnType.
    * @retval E_NOT_OK         If the LIN Channel is not valid or
    *                          LIN driver is not initialized or
    *                          LIN Channel is in sleep state or
    *                          a timeout occurs.
    * @retval E_OK             Otherwise.
    *
    * @note    Autosar Service ID: 0x06.
    * @note    Synchronous, non reentrant function.
    *
    */
    Std_ReturnType  Lin_43_LLCE_GoToSleep(uint8 Channel);
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

/**
* @brief   Put a Lin channel in the internal sleep state.
* @details Stops any ongoing transmission, sets the channel
*          state to LIN_CH_SLEEP and put the LIN
*          hardware unit to a reduced power operation mode.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @note    Autosar Service ID: 0x09.
* @note    Synchronous, non reentrant function.
*
*/
Std_ReturnType  Lin_43_LLCE_GoToSleepInternal(uint8 Channel);

/**
* @brief   Generates a wake up pulse.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @note    Autosar Service ID: 0x07.
* @note    Synchronous, non reentrant function.
*
*/
Std_ReturnType  Lin_43_LLCE_Wakeup(uint8 Channel);

/**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without sending a
*          wake up signal to the LIN bus
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @note    Autosar Service ID: 0x0B.
* @note    Asynchronous, non reentrant function.
*
*/
Std_ReturnType Lin_43_LLCE_WakeupInternal(uint8 Channel);

#if LIN_43_LLCE_VERSION_INFO_API == STD_ON
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return                  void.
*
* @pre            Preconditions as text description. Optional tag.
*
* @note    Autosar Service ID: 0x01.
* @note    Synchronous, non reentrant function.
*
*/
void  Lin_43_LLCE_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif  /* #if LIN_43_LLCE_VERSION_INFO_API == STD_ON */

#define LIN_43_LLCE_STOP_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LLCE_H */
