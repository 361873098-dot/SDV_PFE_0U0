/**
*   @file    Lin.c
*   @implements Lin.c_Artifact
*   @version 1.0.7
*
*   @brief   AUTOSAR Lin_43_LLCE - High level part of LIN driver.
*   @details This file contains the functions defined by AutoSAR.
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
#include "Lin_43_LLCE.h"
#include "Lin_43_LLCE_IPW.h"
#include "EcuM_Externals.h"
#include "LinIf.h"
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

#if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_43_LLCE_VENDOR_ID_C                      43
#define LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_43_LLCE_AR_RELEASE_MINOR_VERSION_C       4

#define LIN_43_LLCE_AR_RELEASE_REVISION_VERSION_C    0
#define LIN_43_LLCE_SW_MAJOR_VERSION_C               1
#define LIN_43_LLCE_SW_MINOR_VERSION_C               0
#define LIN_43_LLCE_SW_PATCH_VERSION_C               7
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same Autosar version */
#if (LIN_43_LLCE_VENDOR_ID_C != LIN_43_LLCE_VENDOR_ID)
    #error "Lin.c and Lin_43_LLCE.h have different vendor ids"
#endif
#if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LLCE_AR_RELEASE_REVISION_VERSION_C != LIN_43_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin.c and Lin_43_LLCE.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_43_LLCE_SW_MAJOR_VERSION_C != LIN_43_LLCE_SW_MAJOR_VERSION) || \
     (LIN_43_LLCE_SW_MINOR_VERSION_C != LIN_43_LLCE_SW_MINOR_VERSION) || \
     (LIN_43_LLCE_SW_PATCH_VERSION_C != LIN_43_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin.c and Lin_43_LLCE.h are different"
#endif
/* Check if current file and Lin_IPW header file are of the same Autosar version */
#if (LIN_43_LLCE_VENDOR_ID_C != LIN_43_LLCE_IPW_VENDOR_ID)
    #error "Lin.c and Lin_43_LLCE_IPW.h have different vendor ids"
#endif
#if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LLCE_AR_RELEASE_REVISION_VERSION_C != LIN_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin.c and Lin_43_LLCE_IPW.h are different"
#endif
/* Check if current file and Lin_IPW header file are of the same Software version */
#if ((LIN_43_LLCE_SW_MAJOR_VERSION_C != LIN_43_LLCE_IPW_SW_MAJOR_VERSION) || \
     (LIN_43_LLCE_SW_MINOR_VERSION_C != LIN_43_LLCE_IPW_SW_MINOR_VERSION) || \
     (LIN_43_LLCE_SW_PATCH_VERSION_C != LIN_43_LLCE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin.c and Lin_43_LLCE_IPW.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if the source file and Dem header file are of the same version */
        #if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lin.c and Dem.h are different"
        #endif
    #endif

    #if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_43_LLCE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lin.c and Det.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

#if (LIN_43_LLCE_PRECOMPILE_SUPPORT == STD_ON)
extern const Lin_43_LLCE_ConfigType Lin_43_LLCE_Config;
#endif

#define LIN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#define LIN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
const Lin_43_LLCE_ConfigType * Lin_43_LLCE_pxConfigPtr = NULL_PTR;

#define LIN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

#define LIN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
const Lin_43_LLCE_ChannelConfigType * Lin_43_LLCE_pChannelConfigPtr[LIN_43_LLCE_HW_MAX_MODULES];

#define LIN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

#define LIN_43_LLCE_START_SEC_VAR_INIT_8
#include "Lin_43_LLCE_MemMap.h"

/* LIN driver status variable.*/
uint8 Lin_u8LinDrvStatus = LIN_43_LLCE_UNINIT;

#define LIN_43_LLCE_STOP_SEC_VAR_INIT_8
#include "Lin_43_LLCE_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

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
* @implements Lin_Init_Activity
*
*/
void Lin_43_LLCE_Init(const Lin_43_LLCE_ConfigType * Config)
{
    uint8 u8Lin_ChLoop;

    /* Check whether the LIN driver is in LIN_43_LLCE_UNINIT state */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    if (LIN_43_LLCE_UNINIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has been already initialized */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_43_LLCE_INIT_ID, \
                              (uint8)LIN_43_LLCE_E_STATE_TRANSITION \
                             );
    }
    else
    {
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
#if (LIN_43_LLCE_PRECOMPILE_SUPPORT != STD_ON)
        /* Check Config for not being a null pointer */
        if (NULL_PTR == Config)
        {
        #if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_INIT_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_POINTER \
                                 );
        #endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            Lin_43_LLCE_pxConfigPtr = Config;
#else /* LIN_43_LLCE_PRECOMPILE_SUPPORT == STD_ON */
        if (NULL_PTR != Config)
        {
        #if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_INIT_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_POINTER \
                                 );
        #endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            Lin_43_LLCE_pxConfigPtr = &Lin_43_LLCE_Config;
#endif /* LIN_43_LLCE_PRECOMPILE_SUPPORT */
            for (u8Lin_ChLoop=(uint8)0U; u8Lin_ChLoop < LIN_43_LLCE_HW_MAX_MODULES; u8Lin_ChLoop++)
            {
                Lin_43_LLCE_pChannelConfigPtr[u8Lin_ChLoop] = Lin_43_LLCE_pxConfigPtr->pLin_Channel[u8Lin_ChLoop];
            }
            Lin_43_LLCE_Ipw_Init();
            /* Update LIN driver status to LIN_43_LLCE_INIT */
            Lin_u8LinDrvStatus = LIN_43_LLCE_INIT;
        }
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
    return; /* Exit function with no return */
}

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
* @implements Lin_CheckWakeup_Activity
*
*/
Std_ReturnType Lin_43_LLCE_CheckWakeup(uint8 Channel)
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if (LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_43_LLCE_CHECKWAKEUP_ID, \
                              (uint8)LIN_43_LLCE_E_UNINIT \
                             );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_CHECKWAKEUP_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            u8TempReturn = Lin_43_LLCE_Ipw_CheckWakeup(Channel);

            if ((uint8)E_OK == u8TempReturn)
            {
                if ((uint8) STD_ON == Lin_43_LLCE_pxConfigPtr->pLin_Channel[Channel]->pChannelConfigPC->u8LinChannelWakeupSupport)
                {
                    /* Indicates a valid timer wakeup event to ECU State Manager */
                    EcuM_SetWakeupEvent(Lin_43_LLCE_pChannelConfigPtr[Channel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
                    /* Report the wakeup source to the LinInterface after a successful wakeup */
                    LinIf_WakeupConfirmation(Lin_43_LLCE_pChannelConfigPtr[Channel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
                }
            }
            else
            {
                /* Return E_OK, there was no error during the execution */
                u8TempReturn = (uint8)E_OK;
            }
        }
    }
    return u8TempReturn;
}

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
* @implements Lin_GetStatus_Activity
*
*/
Lin_StatusType Lin_43_LLCE_GetStatus(uint8 Channel, \
                                             uint8 ** Lin_SduPtr \
                                            )
{
    Lin_StatusType u8tempReturn = LIN_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if(LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID,(uint8)0,(uint8)LIN_43_LLCE_GETSTATUS_ID,(uint8)LIN_43_LLCE_E_UNINIT);
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8tempReturn = LIN_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_GETSTATUS_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8tempReturn = LIN_NOT_OK;
        }
        else
        {
            /* Check PduInfoPtr for not being a null pointer */
            if (NULL_PTR == Lin_SduPtr)
            {
                /* Invalid pointer */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_43_LLCE_GETSTATUS_ID, \
                                      (uint8)LIN_43_LLCE_E_PARAM_POINTER \
                                     );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                u8tempReturn = LIN_NOT_OK;
            }
            else
            {
                u8tempReturn = Lin_43_LLCE_Ipw_HardwareGetStatus(Channel, Lin_SduPtr);
            }
        }
    }
    return u8tempReturn;
}
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
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
* @implements Lin_GoToSleep_Activity
*
*/
Std_ReturnType Lin_43_LLCE_GoToSleep(uint8 Channel)
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if (LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID,(uint8)0,(uint8)LIN_43_LLCE_GOTOSLEEP_ID,(uint8)LIN_43_LLCE_E_UNINIT);
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_GOTOSLEEP_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            u8TempReturn = Lin_43_LLCE_Ipw_GoToSleep(Channel);
        }
    }
    return u8TempReturn;
}
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
* @implements Lin_GoToSleepInternal_Activity
*
*/
Std_ReturnType Lin_43_LLCE_GoToSleepInternal(uint8 Channel)
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if (LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_43_LLCE_GOTOSLEEPINTERNAL_ID, \
                              (uint8)LIN_43_LLCE_E_UNINIT \
                             );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_GOTOSLEEPINTERNAL_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn =  (uint8)E_NOT_OK;
        }
        else
        {
            u8TempReturn = Lin_43_LLCE_Ipw_GoToSleepInternal(Channel);
        }
    }
    return u8TempReturn;
}

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
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
* @implements Lin_SendFrame_Activity
*
*/
Std_ReturnType Lin_43_LLCE_SendFrame(uint8 Channel, \
                                             const Lin_PduType * PduInfoPtr \
                                            )
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if (LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_43_LLCE_SENDFRAME_ID, \
                              (uint8)LIN_43_LLCE_E_UNINIT \
                             );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID,(uint8)0,(uint8)LIN_43_LLCE_SENDFRAME_ID, (uint8)LIN_43_LLCE_E_INVALID_CHANNEL);
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check PduInfoPtr for not being a null pointer */
            if (NULL_PTR == PduInfoPtr)
            {
                /* Invalid pointer */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_43_LLCE_SENDFRAME_ID, \
                                      (uint8)LIN_43_LLCE_E_PARAM_POINTER \
                                     );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                u8TempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                u8TempReturn = Lin_43_LLCE_Ipw_SendFrame(Channel,PduInfoPtr);
            }
        }
    }
    return u8TempReturn;
}
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

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
* @implements Lin_Wakeup_Activity
*
*/
Std_ReturnType Lin_43_LLCE_Wakeup(uint8 Channel)
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if (LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID,(uint8)0,(uint8)LIN_43_LLCE_WAKEUP_ID,(uint8)LIN_43_LLCE_E_UNINIT);
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_WAKEUP_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Call LLD function */
            u8TempReturn = Lin_43_LLCE_Ipw_WakeUp(Channel);
        }
    }
    return u8TempReturn;
}

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
* @implements Lin_WakeupInternal_Activity
*
*/
Std_ReturnType Lin_43_LLCE_WakeupInternal(uint8 Channel)
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_43_LLCE_INIT state */
    if (LIN_43_LLCE_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID,(uint8)0,(uint8)LIN_43_LLCE_WAKEUPINTERNAL_ID,(uint8)LIN_43_LLCE_E_UNINIT);
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= LIN_43_LLCE_HW_MAX_MODULES)
        {
            /* Invalid channel */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_43_LLCE_WAKEUPINTERNAL_ID, \
                                  (uint8)LIN_43_LLCE_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Call LLD function */
            u8TempReturn = Lin_43_LLCE_Ipw_WakeUpInternal(Channel);
        }
    }
    return u8TempReturn;
}

 #if (LIN_43_LLCE_VERSION_INFO_API == STD_ON)
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
* @implements Lin_GetVersionInfo_Activity
*
*/
void Lin_43_LLCE_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_43_LLCE_GETVERSIONINFO_ID, \
                              (uint8) LIN_43_LLCE_E_PARAM_POINTER \
                             );
    }
    else
    {
#endif /* LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON */
        (versioninfo)->vendorID = (uint16) LIN_43_LLCE_VENDOR_ID;
        (versioninfo)->moduleID = (uint8) LIN_43_LLCE_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8) LIN_43_LLCE_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8) LIN_43_LLCE_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8) LIN_43_LLCE_SW_PATCH_VERSION;
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LIN_43_LLCE_VERSION_INFO_API == STD_ON */

#define LIN_43_LLCE_STOP_SEC_CODE
 #include "Lin_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
