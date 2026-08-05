/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : VR5510
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

/**
*   @file   Wdg_43_VR5510.c
*
*   @addtogroup  Wdg_VR5510_HLD
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg_43_VR5510.h"
#include "Wdg_43_VR5510_IPW.h"
#include "Wdg_43_VR5510_Cfg.h"
#include "SchM_Wdg_43_VR5510.h"
#include "Wdg_43_VR5510_EnvCfg.h"

#if (WDG_43_VR5510_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
#include "Wdg_43_VR5510_CfgExt.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510_VENDOR_ID_C                      43
#define WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C       4
#define WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C       4
#define WDG_43_VR5510_AR_RELEASE_REVISION_VERSION_C    0
#define WDG_43_VR5510_SW_MAJOR_VERSION_C               4
#define WDG_43_VR5510_SW_MINOR_VERSION_C               0
#define WDG_43_VR5510_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_43_VR5510 header file are of the same vendor */
#if (WDG_43_VR5510_VENDOR_ID_C != WDG_43_VR5510_VENDOR_ID)
    #error "Wdg_43_VR5510.c and Wdg_43_VR5510.h have different vendor ids"
#endif
/* Check if current file and Wdg_43_VR5510 header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C    != WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C    != WDG_43_VR5510_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_REVISION_VERSION_C != WDG_43_VR5510_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.c and Wdg_43_VR5510.h are different"
#endif
/* Check if current file and Wdg_43_VR5510 header file are of the same Software version */
#if ((WDG_43_VR5510_SW_MAJOR_VERSION_C != WDG_43_VR5510_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_SW_MINOR_VERSION_C != WDG_43_VR5510_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_SW_PATCH_VERSION_C != WDG_43_VR5510_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_43_VR5510.c and Wdg_43_VR5510.h are different"
#endif

/* Check if current file and Wdg_43_VR5510_IPW header file are of the same vendor */
#if (WDG_43_VR5510_VENDOR_ID_C != WDG_43_VR5510_IPW_VENDOR_ID)
    #error "Wdg_43_VR5510.c and Wdg_43_VR5510_IPW.h have different vendor ids"
#endif
/* Check if current file and Wdg_43_VR5510_IPW header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C    != WDG_43_VR5510_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C    != WDG_43_VR5510_IPW_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_REVISION_VERSION_C != WDG_43_VR5510_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.c and Wdg_43_VR5510_IPW.h are different"
#endif
/* Check if current file and Wdg_43_VR5510_IPW header file are of the same Software version */
#if ((WDG_43_VR5510_SW_MAJOR_VERSION_C != WDG_43_VR5510_IPW_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_SW_MINOR_VERSION_C != WDG_43_VR5510_IPW_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_SW_PATCH_VERSION_C != WDG_43_VR5510_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_43_VR5510.c and Wdg_43_VR5510_IPW.h are different"
#endif

/* Check if current file and Wdg_43_VR5510_CfgExt header file are of the same vendor */
#if (WDG_43_VR5510_VENDOR_ID_C != WDG_43_VR5510_CFG_EXT_VENDOR_ID)
    #error "Wdg_43_VR5510.c and Wdg_43_VR5510_CfgExt.h have different vendor ids"
#endif
/* Check if current file and Wdg_43_VR5510_CfgExt header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C    != WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C    != WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_REVISION_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.c and Wdg_43_VR5510_CfgExt.h are different"
#endif
/* Check if current file and Wdg_43_VR5510_CfgExt header file are of the same Software version */
#if ((WDG_43_VR5510_SW_MAJOR_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_SW_MINOR_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_SW_PATCH_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_43_VR5510.c and Wdg_43_VR5510_CfgExt.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Mcal header file are of the same vendor */
#if (WDG_43_VR5510_VENDOR_ID_C != MCAL_VENDOR_ID)
    #error "Wdg_43_VR5510.c and Mcal.h have different vendor ids"
#endif
/* Check if current file and Mcal header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C    != MCAL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_REVISION_VERSION_C != MCAL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.c and Mcal.h are different"
#endif
/* Check if current file and Mcal header file are of the same Software version */
#if ((WDG_43_VR5510_SW_MAJOR_VERSION_C != MCAL_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_SW_MINOR_VERSION_C != MCAL_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_SW_PATCH_VERSION_C != MCAL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_43_VR5510.c and Mcal.h are different"
#endif
#endif
#if (WDG_43_VR5510_DEV_ERROR_DETECT == STD_ON)
/* Check if current file and Det header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C    != DET_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C    != DET_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.c and Det.h are different"
#endif
#endif

#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if current file and Dem header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION_C    != DEM_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.c and Dem.h are different"
#endif
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

#define WDG_43_VR5510_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

/**
*  @brief Variable that indicate the current configuration set
*/
static const Wdg_43_VR5510_ConfigType * Wdg_VR5510_pConfigPtr;

#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief          DEM errors configuration pointer.
* @details        This is used to report DEM errors in the Wdg external driver.
*/
static const Wdg_VR5510_DemConfigType * Wdg_VR5510_pDemConfigPtr;
#endif


#define WDG_43_VR5510_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#define WDG_43_VR5510_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
/**
*  @brief Variable that indicated the state of the driver
*/
static Wdg_VR5510_DeviceStatusType Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_UNINIT;
#endif

#define WDG_43_VR5510_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

#define WDG_43_VR5510_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

/**
*  @brief Variable that indicates the last Wdg Mode
*/
static WdgIf_ModeType Wdg_eCurrentMode; /* implicit zero initialization*/

#define WDG_43_VR5510_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

#define WDG_43_VR5510_START_SEC_VAR_CLEARED_32
#include "Wdg_43_VR5510_MemMap.h"

/**
*  @brief Variable that indicate the watchdog timeout
*/
static uint32 Wdg_VR5510_u32Timeout;

/**
*  @brief Variable that indicated the timer value in ms
*/
static uint32 Wdg_VR5510_u32GptPeriod;

/**
*  @brief Variable that indicated the timer value in ms
*/
static uint32 Wdg_VR5510_u32NewGptPeriod;

#define WDG_43_VR5510_STOP_SEC_VAR_CLEARED_32
#include "Wdg_43_VR5510_MemMap.h"


#define WDG_43_VR5510_START_SEC_VAR_CLEARED_BOOLEAN
#include "Wdg_43_VR5510_MemMap.h"

static boolean Wdg_VR5510_bSetModeRequest  = FALSE;

#define WDG_43_VR5510_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Wdg_43_VR5510_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_START_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_START_SEC_RAMCODE
    #endif
#endif
#include "Wdg_43_VR5510_MemMap.h"

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
static inline Std_ReturnType Wdg_VR5510_ValidateGlobalCall(const Wdg_VR5510_ServiceIdType ServiceId);
#endif

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
static inline void Wdg_VR5510_EndValidateGlobalCall(const Wdg_VR5510_ServiceIdType ServiceId, Std_ReturnType Validation);
#endif

#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
static inline Std_ReturnType Wdg_VR5510_ValidatePtrInit(const Wdg_43_VR5510_ConfigType * ConfigPtr);
#endif

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
static inline Std_ReturnType Wdg_VR5510_ValidateTrigerCondition(void);
#endif

#if ((WDG_43_VR5510_VALIDATE_PARAMS == STD_ON) && (WDG_43_VR5510_VERSION_INFO_API == STD_ON))
static inline Std_ReturnType Wdg_VR5510_ValidatePtrVersion(const Std_VersionInfoType * Versioninfo);
#endif

static inline Std_ReturnType Wdg_VR5510_ValidateMode(WdgIf_ModeType Wdg_VR5510_Mode,
                                                     Wdg_VR5510_ServiceIdType ServiceId,
                                                     Wdg_VR5510_ErrorIdType ErrorId
                                                    );

static inline Std_ReturnType Wdg_VR5510_VadidateDoSetMode(const WdgIf_ModeType Mode);

#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
static inline Std_ReturnType Wdg_VR5510_ValidateTimeout(uint16 Timeout);
#endif

static inline Std_ReturnType Wdg_VR5510_ExecuteInit(void);

#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_STOP_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_STOP_SEC_RAMCODE
    #endif
#endif
#include "Wdg_43_VR5510_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_START_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_START_SEC_RAMCODE
    #endif
#endif
#include "Wdg_43_VR5510_MemMap.h"

 /*
 * @brief      This function will execute trigger watchdog
 * @details    This function is Gpt callback notification. It will trigger watchdog each time interrupt.
 *
 * @return      void
 *
 * @implements  Wdg_VR5510_Cbk_GptNotification0_Activity
 * */
void Wdg_VR5510_Cbk_GptNotification0(void)
{
    uint16 u16RegValue = 0U;
    Std_ReturnType ReturnStatus = E_OK;
    Wdg_43_VR5510_Trigger();

    if (NULL_PTR != Wdg_VR5510_pConfigPtr)
    {
    /* if Check fault notification was used, driver will read FS_G_Flag value and include the user's notification API */
        if (NULL_PTR != Wdg_VR5510_pConfigPtr->Wdg_VR5510_pCheckFaultNotification)
        {
            ReturnStatus = Wdg_IPW_VR5510_ReadFsGFlagRegister(Wdg_VR5510_pConfigPtr->u16WdgPmicDeviceID, &u16RegValue);
            if ((Std_ReturnType)E_OK == ReturnStatus)
            {
                /* this function will be declared by user */
                Wdg_VR5510_pConfigPtr->Wdg_VR5510_pCheckFaultNotification(u16RegValue);
            }

        }
    }
}

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for functions
 *             that uses all the channels - Wdg_43_VR5510_Init, Wdg_43_VR5510_SetTriggerCondition, Wdg_43_VR5510_SetMode.
 *
 * @param[in]   ServiceId      The service id of the caller function
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_VR5510_ValidateGlobalCall_Activity
 * */
static inline Std_ReturnType Wdg_VR5510_ValidateGlobalCall(const Wdg_VR5510_ServiceIdType ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;

    SchM_Enter_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_03();
    if  (
            ((WDG_VR5510_DEVICE_UNINIT == Wdg_VR5510_eDeviceStatus) && (WDG_VR5510_INIT_ID != ServiceId)) ||\
            (WDG_VR5510_DEVICE_INITIALIZING == Wdg_VR5510_eDeviceStatus) || (WDG_VR5510_DEVICE_BUSY == Wdg_VR5510_eDeviceStatus) ||\
            ((WDG_VR5510_DEVICE_UNINIT != Wdg_VR5510_eDeviceStatus) && (WDG_VR5510_INIT_ID == ServiceId))
        )
    {
        SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_03();
        (void)Det_ReportError((uint16)WDG_43_VR5510_MODULE_ID, (uint8)0, (uint8)ServiceId, (uint8)WDG_VR5510_E_DRIVER_STATE);
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if ( WDG_VR5510_INIT_ID == ServiceId )
        {
            Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_INITIALIZING;
        }
        else
        {
            Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_BUSY;
        }
        SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_03();
    }

    return Valid;
}

/**
 * @brief      This function ends the validation of the global call.
 * @details    This service is a non reentrant function used for end the validation the calls for
 *             functions that uses all the channels - Wdg_43_VR5510_Init, Wdg_43_VR5510_SetTriggerCondition, Wdg_43_VR5510_SetMode.
 *
 * @param[in]   ServiceId       The function service id
 * @param[in]   validation      The function call was previously validated
 * @return void
 *
 * @implements  Wdg_VR5510_EndValidateGlobalCall_Activity
 * */
static inline void Wdg_VR5510_EndValidateGlobalCall(const Wdg_VR5510_ServiceIdType ServiceId, Std_ReturnType Validation)
{
    SchM_Enter_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_04();
    if ( (Std_ReturnType)E_OK == Validation )
    {
        Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_IDLE;
    }
    else
    {
        if ( WDG_VR5510_DEVICE_BUSY == Wdg_VR5510_eDeviceStatus )
        {
            Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_IDLE;
        }
        else
        {
            if ( (NULL_PTR == Wdg_VR5510_pConfigPtr) || (WDG_VR5510_INIT_ID == ServiceId) )
            {
                if ( Wdg_VR5510_eDeviceStatus != WDG_VR5510_DEVICE_IDLE )
                {
                    Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_UNINIT;
                }
            }
            else
            {
                if ( Wdg_VR5510_eDeviceStatus != WDG_VR5510_DEVICE_UNINIT )
                {
                    Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_IDLE;
                }
            }
        }
    }
    SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_04();
}
#endif /* WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON*/

#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   ConfigPtr        Pointer to a selected configuration structure
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_VR5510_ValidatePtrInit_Activity
 * */
static inline Std_ReturnType Wdg_VR5510_ValidatePtrInit(const Wdg_43_VR5510_ConfigType * ConfigPtr)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;

#if (WDG_43_VR5510_PRECOMPILE_SUPPORT == STD_ON)
    if ( NULL_PTR != ConfigPtr )
#else
    if ( NULL_PTR == ConfigPtr )
#endif /*#if (WDG_PRECOMPILE_SUPPORT == STD_ON)*/
    {
        (void)Det_ReportError((uint16)WDG_43_VR5510_MODULE_ID, (uint8)0, (uint8)WDG_VR5510_INIT_ID, (uint8)WDG_VR5510_E_INIT_FAILED);
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Wdg_VR5510_eDeviceStatus = WDG_VR5510_DEVICE_INITIALIZING;
    }
    return Valid;
}
#endif /* (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)*/

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the call of Wdg_ChannelSetTriggerCondition function
 * @details    This service is a function used for validating the calls for
               Wdg_ChannelSetTriggerCondition.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
static inline Std_ReturnType Wdg_VR5510_ValidateTrigerCondition(void)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;

    if ( (WDG_VR5510_DEVICE_UNINIT == Wdg_VR5510_eDeviceStatus) || (WDG_VR5510_DEVICE_INITIALIZING == Wdg_VR5510_eDeviceStatus) )
    {
        (void)Det_ReportError((uint16)WDG_43_VR5510_MODULE_ID, (uint8)0, (uint8)WDG_VR5510_SETTRIGGERCONDITION_ID, (uint8)WDG_VR5510_E_DRIVER_STATE);
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    return Valid;
}
#endif /* WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((WDG_43_VR5510_VALIDATE_PARAMS == STD_ON) && (WDG_43_VR5510_VERSION_INFO_API == STD_ON))
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   pVersioninfo        Pointer to a selected configuration structure.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_VR5510_ValidatePtrVersion_Activity
 * */
static inline Std_ReturnType Wdg_VR5510_ValidatePtrVersion(const Std_VersionInfoType * Versioninfo)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;

    if ( NULL_PTR == Versioninfo )
    {
        (void)Det_ReportError((uint16)WDG_43_VR5510_MODULE_ID, (uint8)0,(uint8)WDG_VR5510_GETVERSION_ID,(uint8)WDG_VR5510_E_PARAM_POINTER);
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    return Valid;
}
#endif /* (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)*/
/**
 * @brief       This function validate the mode that will be set up.
 *
 * @param[in]   Wdg_VR5510_Mode      The watchdog mode that will be set up.
 * @param[in]   uServiceId           The service id of the caller function
 * @param[in]   uErrorId             The function call was previously validated
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 *
 * */
static inline Std_ReturnType Wdg_VR5510_ValidateMode(WdgIf_ModeType Wdg_VR5510_Mode,
                                                     Wdg_VR5510_ServiceIdType ServiceId,
                                                     Wdg_VR5510_ErrorIdType ErrorId
                                                    )
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;
    boolean DisableRejectedErrActive  = FALSE;
    boolean ModeFailedErrActive  = FALSE;

    if ( !((WDGIF_OFF_MODE  == Wdg_VR5510_Mode) || (WDGIF_FAST_MODE == Wdg_VR5510_Mode) || (WDGIF_SLOW_MODE == Wdg_VR5510_Mode)) )
    {
#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
        (void)Det_ReportError((uint16)WDG_43_VR5510_MODULE_ID, (uint8)0, (uint8)ServiceId, (uint8)ErrorId);
#else
        (void)ServiceId;
        (void)ErrorId;
#endif
         ModeFailedErrActive  = TRUE;
         Valid = (Std_ReturnType)E_NOT_OK;
    }
#if (WDG_43_VR5510_DISABLE_ALLOWED == STD_OFF)
    if ( WDGIF_OFF_MODE == Wdg_VR5510_Mode )
    {
        DisableRejectedErrActive  = TRUE;
        Valid = (Std_ReturnType)E_NOT_OK;
    }
#endif  /* (WDG_43_VR5510_DISABLE_ALLOWED == STD_OFF) */
#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if ( (uint32)STD_ON == Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Disable_Rejected.state )
    {
#if (WDG_43_VR5510_DISABLE_ALLOWED == STD_OFF)
            if ( TRUE == DisableRejectedErrActive )
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Disable_Rejected.id, DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Disable_Rejected.id, DEM_EVENT_STATUS_PASSED);
            }
#else
        (void)DisableRejectedErrActive;
#endif     /*WDG_43_VR5510_DISABLE_ALLOWED == STD_OFF*/
    }
    if ((uint32)STD_ON == Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.state)
    {
        if ( TRUE == ModeFailedErrActive )
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
        }
    }
#else
    (void)ModeFailedErrActive;
    (void)DisableRejectedErrActive;
#endif  /* (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

    return Valid;
}

/**
 * @brief       This function validates the mode setting for wdg.
 *
 * @param[in] Mode      One of the following statically configured modes:<br>
 *                      -# WDGIF_OFF_MODE,
 *                      -# WDGIF_SLOW_MODE,
 *                      -# WDGIF_FAST_MODE.
 * @param[in]   Status        the status of set mode Wdg

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
static inline Std_ReturnType Wdg_VR5510_VadidateDoSetMode(const WdgIf_ModeType Mode)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;
    Gpt_ValueType uElapsedTime;
    uint32 TempTimeout;

    if ( Wdg_eCurrentMode != Mode )
    {
        if ( WDGIF_OFF_MODE == Mode )
        {
            Gpt_StopTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
            SchM_Enter_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_05();

            uElapsedTime =  Gpt_GetTimeElapsed(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
            if ( uElapsedTime > Wdg_VR5510_u32Timeout )
            {
                Wdg_VR5510_u32Timeout = 0U;
                SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_05();
            }
            else
            {
                TempTimeout = Wdg_VR5510_u32Timeout - uElapsedTime;
                Wdg_VR5510_u32Timeout = TempTimeout;
                SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_05();
            }
        }
        else
        {

            if ( WDGIF_OFF_MODE == Wdg_eCurrentMode )
            {
                if (Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Mode]->u32TimerValue > Wdg_VR5510_u32Timeout)
                {
                    Valid |= (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Gpt_StartTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel, \
                                   Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Mode]->u32TimerValue
                                  );
                }
            }
            else
            {
                if (Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Wdg_eCurrentMode]->u32TimerValue > Wdg_VR5510_u32Timeout)
                {
                    Valid |= (Std_ReturnType)E_NOT_OK;
                }
            }
            if ((Std_ReturnType)E_OK == Valid)
            {
                SchM_Enter_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_01();
                Wdg_VR5510_u32NewGptPeriod = (Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Mode]->u32TimerValue);
                Wdg_VR5510_bSetModeRequest =  TRUE;
                SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_01();
            }
        }

        if ((Std_ReturnType)E_OK == Valid)
        {
            /* Remember the last Wdg Mode */
            Wdg_eCurrentMode = Mode;
        }
    }

    return Valid;
}

#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   u16Timeout    timeout window

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * This function is called in IP HW.
 * @implements  Wdg_VR5510_ValidateTimeout_Activity
 * */
static inline Std_ReturnType Wdg_VR5510_ValidateTimeout(uint16 Timeout)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;
    uint16 MaxTimeoutCfg = WDG_43_VR5510_MAX_TIMEOUT_U16;

    if ( MaxTimeoutCfg < Timeout )
    {
        (void)Det_ReportError((uint16)WDG_43_VR5510_MODULE_ID, (uint8)0,(uint8)WDG_VR5510_SETTRIGGERCONDITION_ID,(uint8)WDG_VR5510_E_PARAM_TIMEOUT);
        Valid = (Std_ReturnType)E_NOT_OK;
    }

    return Valid;
}
#endif /* WDG_43_VR5510_VALIDATE_PARAMS == STD_ON */

static inline Std_ReturnType Wdg_VR5510_ExecuteInit(void)
{
    Std_ReturnType Valid = Wdg_VR5510_ValidateMode(Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode, WDG_VR5510_INIT_ID, WDG_VR5510_E_PARAM_CONFIG);
    if ( (Std_ReturnType)E_OK == Valid )
    {
        Gpt_StopTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
        Wdg_VR5510_u32GptPeriod = (Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode]->u32TimerValue);
        Wdg_VR5510_u32Timeout = (uint32)WDG_43_VR5510_INITIAL_TIMEOUT_U16 * Wdg_VR5510_pConfigPtr->Wdg_VR5510_u32TriggerSourceClock;

        if ( (Wdg_VR5510_u32Timeout < Wdg_VR5510_u32GptPeriod) && (WDGIF_OFF_MODE != Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode) )
        {
            Valid = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Valid = Wdg_VR5510_IPW_Init(Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode],
                                        Wdg_VR5510_pConfigPtr->u16WdgPmicDeviceID
                                       );
            if ( (Std_ReturnType)E_OK == Valid )
            {
                Gpt_EnableNotification(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
                /* start the timer channel only if the mode is not off mode */
                if ( WDGIF_OFF_MODE != Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode )
                {
                    Gpt_StartTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel, \
                                   Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode]->u32TimerValue
                                  );
                }
                Wdg_eCurrentMode = Wdg_VR5510_pConfigPtr->Wdg_VR5510_DefaultMode;
            }
        }
#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* report the mode fail */
        if ( (uint32)STD_ON == Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.state )
        {
            if ( (Std_ReturnType)E_OK == Valid )
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);

            }
            else
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
            }
        }
#endif
    }

    return Valid;
}

#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_STOP_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_STOP_SEC_RAMCODE
    #endif
#endif
/**
* @brief Include Memory mapping specification
*/
#include "Wdg_43_VR5510_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_START_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_START_SEC_RAMCODE
    #endif
#endif
#include "Wdg_43_VR5510_MemMap.h"

/**
* @brief   This function initializes the WDG External module.
* @details The @p Wdg_43_VR5510_Init function shall initialize the Wdg External module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in] ConfigPtr     Pointer to configuration set.
*
* @implements      Wdg_43_VR5510_Init_Activity
**/
void Wdg_43_VR5510_Init(const Wdg_43_VR5510_ConfigType * pConfigPtr)
{
    Std_ReturnType Valid;

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
    Valid = Wdg_VR5510_ValidateGlobalCall(WDG_VR5510_INIT_ID);
    if ( (Std_ReturnType)E_OK == Valid )
    {
#endif /* (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */

#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
        Valid = Wdg_VR5510_ValidatePtrInit(pConfigPtr);
        if ( (Std_ReturnType)E_OK == Valid )
        {
#else
        (void)pConfigPtr;
#endif

#if (WDG_43_VR5510_PRECOMPILE_SUPPORT == STD_ON)
            Wdg_VR5510_pConfigPtr = &Wdg_VR5510_PBCfgVariantPredefined;
            (void)pConfigPtr;
#else
            Wdg_VR5510_pConfigPtr = pConfigPtr;
#endif /* (PMIC_PRECOMPILE_SUPPORT == STD_ON) */

#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* Get a local copy of the DEM error reporting structure. */
            Wdg_VR5510_pDemConfigPtr = Wdg_VR5510_pConfigPtr->Wdg_VR5510_pDemConfig;
#endif /* (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

            Valid = Wdg_VR5510_ExecuteInit();
#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Wdg_VR5510_EndValidateGlobalCall(WDG_VR5510_INIT_ID, Valid);
#else
    (void)Valid;
#endif
}

/**
* @brief   Switches the watchdog into the mode list.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p  Wdg_43_VR5510_SetMode
*          function:<br>
*          - WDGIF_OFF_MODE,
*          - WDGIF_SLOW_MODE,
*          - WDGIF_FAST_MODE.
*          .
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      -# WDGIF_OFF_MODE,
*                      -# WDGIF_SLOW_MODE,
*                      -# WDGIF_FAST_MODE.
*                      .
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* @implements      Wdg_43_VR5510_SetMode_Activity
**/
Std_ReturnType Wdg_43_VR5510_SetMode(WdgIf_ModeType Mode)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    Std_ReturnType Valid;

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
    Valid = Wdg_VR5510_ValidateGlobalCall(WDG_VR5510_SETMODE_ID);
    if ( (Std_ReturnType)E_OK == Valid )
    {
#endif /* (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */
        Valid = Wdg_VR5510_ValidateMode(Mode, WDG_VR5510_SETMODE_ID, WDG_VR5510_E_PARAM_MODE);
        if ( (Std_ReturnType)E_OK == Valid )
        {
            Valid = Wdg_VR5510_IPW_SetMode(Wdg_VR5510_pConfigPtr->Wdg_VR5510_ModeSettings[Mode],Wdg_VR5510_pConfigPtr->u16WdgPmicDeviceID);
            if ( (Std_ReturnType)E_OK == Valid)
            {
                Ret = Wdg_VR5510_VadidateDoSetMode(Mode);
            }
            /* If dem event enable */
            #if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* report dem event */
            if ( (uint32)STD_ON == Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.state )
            {
                if ( (Std_ReturnType)E_NOT_OK == Ret)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
                }
                else
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_VR5510_pDemConfigPtr->Wdg_VR5510_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
                }
            }
            #endif


        }
#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Wdg_VR5510_EndValidateGlobalCall(WDG_VR5510_SETMODE_ID, Ret);
#endif

    return Ret;
}

/**
* @brief   Reset the watchdog timeout counter according to the timeout value passed.
* @details
*
* @param[in] Timeout value (milliseconds) for setting the trigger counter.
*
* @implements      Wdg_43_VR5510_SetTriggerCondition_Activity
**/
void Wdg_43_VR5510_SetTriggerCondition(uint16 u16Timeout)
{
    Gpt_ValueType uElapsedTime = (Gpt_ValueType)0U;
#if ((WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON) || (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON))
    Std_ReturnType Valid;
#endif

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
        Valid = Wdg_VR5510_ValidateTrigerCondition();
        if ( (Std_ReturnType)E_OK == Valid )
        {
#endif /* (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */
#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
            Valid = Wdg_VR5510_ValidateTimeout(u16Timeout);
            if ( (Std_ReturnType)E_OK == Valid )
            {
#endif
                SchM_Enter_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_02();

                uElapsedTime =  Gpt_GetTimeElapsed(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
                if ( ((Gpt_ValueType)(uElapsedTime) > Wdg_VR5510_u32Timeout) || ((uint16)0 == u16Timeout) )
                {
                    Wdg_VR5510_u32Timeout = (uint32)0;
                    SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_02();
                    Gpt_StopTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
                }
                else
                {
                    Wdg_VR5510_u32Timeout = (uint32)(u16Timeout * Wdg_VR5510_pConfigPtr->Wdg_VR5510_u32TriggerSourceClock) + uElapsedTime;
                    SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_02();
                }
#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
            }
#endif
#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
        }
#endif /* (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */
}

#if (WDG_43_VR5510_VERSION_INFO_API == STD_ON)

/**
* @brief   Returns the version information of the module.
* @details The Wdg_43_VR5510_GetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This function is only required if the WDG_43_VR5510_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] pVersioninfo   Pointer to where to store the version
*                              information of this module.
*
* @implements     Wdg_43_VR5510_GetVersionInfo_Activity
**/
void Wdg_43_VR5510_GetVersionInfo(Std_VersionInfoType * pVersioninfo)
{
#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType Valid = Wdg_VR5510_ValidatePtrVersion(pVersioninfo);

    if ( (Std_ReturnType)E_OK == Valid )
    {
#endif /*(WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)*/
        (pVersioninfo)->vendorID         = (uint16)WDG_43_VR5510_VENDOR_ID;
        (pVersioninfo)->moduleID         = (uint8)WDG_43_VR5510_MODULE_ID;
        (pVersioninfo)->sw_major_version = (uint8)WDG_43_VR5510_SW_MAJOR_VERSION;
        (pVersioninfo)->sw_minor_version = (uint8)WDG_43_VR5510_SW_MINOR_VERSION;
        (pVersioninfo)->sw_patch_version = (uint8)WDG_43_VR5510_SW_PATCH_VERSION;
#if (WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)
    }
#endif /*(WDG_43_VR5510_VALIDATE_PARAMS == STD_ON)*/
}
#endif /*(WDG_43_VR5510_VERSION_INFO_API == STD_ON)*/

/**
* @brief   Triggers the Watchdog.
* @details The Wdg_Cbk_GptNotification shall trigger the hardware. It is set up
*          as notification function for the Gpt timer that controls the trigger of
*          the watchdog
*
* @pre    This API has to be set up as notification for the Gpt channels that is set up
*         for Wdg
*
* @param[in]   Wdg_InstanceID  Harwdware SWT instance.
*
*
* @implements      Wdg_43_VR5510_Trigger_Activity
*
*/
void Wdg_43_VR5510_Trigger(void)
{
    uint32 TempTimeout;
    Wdg_VR55xx_PmicStateType  eHwState;

#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
    Std_ReturnType Valid = Wdg_VR5510_ValidateGlobalCall(WDG_VR5510_TRIGGER_ID);

    if ( (Std_ReturnType)E_OK == Valid )
    {
#endif /* (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */
        eHwState = Wdg_VR5510_IPW_CheckPmicState(Wdg_VR5510_pConfigPtr->u16WdgPmicDeviceID);
        if ( FS_STATES_FSM_STATES_INIT_FS != eHwState )
        {
            SchM_Enter_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_00();
            if ( Wdg_VR5510_u32Timeout < Wdg_VR5510_u32GptPeriod )
            {
                SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_00();
                Gpt_StopTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
            }
            else
            {
                TempTimeout = Wdg_VR5510_u32Timeout - Wdg_VR5510_u32GptPeriod;
                Wdg_VR5510_u32Timeout = TempTimeout;

                if ( TRUE == Wdg_VR5510_bSetModeRequest )
                {
                    Gpt_StopTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel);
                    Wdg_VR5510_bSetModeRequest = FALSE;
                    Wdg_VR5510_u32GptPeriod = Wdg_VR5510_u32NewGptPeriod;
                    Gpt_StartTimer(Wdg_VR5510_pConfigPtr->Wdg_VR5510_TimerChannel, \
                                   Wdg_VR5510_u32GptPeriod
                                  );
                }
                SchM_Exit_Wdg_43_VR5510_WDG_EXCLUSIVE_AREA_00();
                Wdg_VR5510_IPW_Trigger(Wdg_VR5510_pConfigPtr->u16WdgPmicDeviceID);
            }
        }
        else
        {
            Wdg_VR5510_IPW_Trigger(Wdg_VR5510_pConfigPtr->u16WdgPmicDeviceID);
        }
#if (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Wdg_VR5510_EndValidateGlobalCall(WDG_VR5510_TRIGGER_ID, Valid);
#endif /* (WDG_43_VR5510_VALIDATE_GLOBAL_CALL == STD_ON */
}

#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_STOP_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_STOP_SEC_RAMCODE
    #endif
#endif
#include "Wdg_43_VR5510_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} */
