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

#ifndef WDG_43_VR5510_H
#define WDG_43_VR5510_H

/**
*   @file   Wdg_43_VR5510.h
*
*   @addtogroup Wdg_VR5510_HLD
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
#include "Mcal.h"
#include "Wdg_43_VR5510_Cfg.h"
#include "Wdg_43_VR5510_IPW_Types.h"
#include "Gpt.h"
#include "WdgIf_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510_VENDOR_ID                    43
#define WDG_43_VR5510_MODULE_ID                    102
#define WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION     4
#define WDG_43_VR5510_AR_RELEASE_MINOR_VERSION     4
#define WDG_43_VR5510_AR_RELEASE_REVISION_VERSION  0
#define WDG_43_VR5510_SW_MAJOR_VERSION             4
#define WDG_43_VR5510_SW_MINOR_VERSION             0
#define WDG_43_VR5510_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same vendor */
#if (WDG_43_VR5510_VENDOR_ID != MCAL_VENDOR_ID)
    #error "Wdg_43_VR5510.h and Mcal.h have different vendor ids"
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#if ((WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_AR_RELEASE_REVISION_VERSION != MCAL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_43_VR5510.h and Mcal.h are different"
#endif
/* Check if current file and Mcal header file are of the same software version */
#if ((WDG_43_VR5510_SW_MAJOR_VERSION != MCAL_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_SW_MINOR_VERSION != MCAL_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_SW_PATCH_VERSION != MCAL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_43_VR5510.h and Mcal.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief  This enumerated type will contain the service ids for the watchodg functions
*
* @pre To define WDG_GETVERSION_ID, WDG_VERSION_INFO_API has to be equal to STD_ON
*
*/
typedef enum
{
#if (STD_ON == WDG_43_VR5510_VERSION_INFO_API)
    WDG_VR5510_GETVERSION_ID   = 0x04, /*< @brief The service id for the Wdg_GetVersion function,
                                            used when using DET */
#endif
    WDG_VR5510_INIT_ID                 = 0x00, /*< @brief The service id for the Wdg_43_VR5510_InitDevice function, used
                                            when using DET */
    WDG_VR5510_SETMODE_ID              = 0x01, /*< @brief The service id for the Wdg_43_VR5510_SetMode function, used
                                            when using DET */
    WDG_VR5510_TRIGGER_ID              = 0x02,  /*< @brief The service id for the Wdg_43_VR5510_Cbk_GptNotification and Wdg_43_VR5510_Trigger function, used
                                            when using DET */
    WDG_VR5510_SETTRIGGERCONDITION_ID  = 0x03 /*< @brief The service id for the Wdg_43_VR5510_SetTriggerCondition function, used
                                            when using DET */
} Wdg_VR5510_ServiceIdType;

/**
* @brief  Indicates the aditional det errors used by the watchdog driver
*
* @implements  Wdg_VR5510_ErrorIdType_enum
*/
typedef enum
{
    WDG_VR5510_E_DRIVER_STATE  = 0x10,        /*< @brief API service used in wrong context (e.g. driver not
                                                   initialized) */
    WDG_VR5510_E_PARAM_MODE,                  /*< @brief = 0x11 API service called with wrong/inconsistent
                                                          parameter(s) */
    WDG_VR5510_E_PARAM_CONFIG,                /*< @brief = 0x12 API service called with wrong/inconsistent
                                                          parameter(s) */
    WDG_VR5510_E_PARAM_TIMEOUT,               /*< @brief = 0x13 API service called with wrong/inconsistent
                                                          parameter(s) */
    WDG_VR5510_E_PARAM_POINTER,               /*< @brief = 0x14 Wdg_GetVersionInfo service called with
                                                   NULL_PTR */
    WDG_VR5510_E_INIT_FAILED,                 /*< @brief = 0x15 Invalid configuration set selection */
} Wdg_VR5510_ErrorIdType;

/**
* @brief  This enumerated type will contain the watchdog external driver's possible states
*
* @implements  Wdg_VR5510_DeviceStatusType_enum
*/
typedef enum
{
    WDG_VR5510_DEVICE_UNINIT         = 0x00,  /**< @brief The watchdog driver is not uninitialized */
    WDG_VR5510_DEVICE_IDLE           = 0x01,  /**< @brief = 0x01 The watchdog driver is currently idle,
                                                   i.e not being triggered or mode changed */
    WDG_VR5510_DEVICE_BUSY           = 0x02,   /**< @brief = 0x02 The watchdog driver is currently busy,
                                                   i.e triggered or switched between modes */
    WDG_VR5510_DEVICE_INITIALIZING   = 0x03   /**< @brief = 0x03 The watchdog driver is currently initializing */

} Wdg_VR5510_DeviceStatusType;

/**
* @brief  This enumerated type contains the Wdg external driver's possible states.
*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief           This gives the call-out type for PMIC read status notifications.
*/
typedef void      (*Wdg_VR5510_CheckFaultStatusNotifyType)(const uint16 u16RegValue);

/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting.
* @implements       Wdg_VR5510_DemConfigType_struct
*/
typedef struct
{
    const Mcal_DemErrorType Wdg_VR5510_E_Disable_Rejected;
    const Mcal_DemErrorType Wdg_VR5510_E_Mode_Failed;
} Wdg_VR5510_DemConfigType;

/**
* @brief  Defines the configuration structure
* @implements     Wdg_43_VR5510_ConfigType_struct
*/
typedef struct
{
    /**
    @brief The number of configured channels
    */
    const WdgIf_ModeType Wdg_VR5510_DefaultMode;
    /**
    @brief ID of PMIC device.
    */
    const uint32 u16WdgPmicDeviceID;
    /**
    @brief Gpt Channel configured
    */
    const Gpt_ChannelType Wdg_VR5510_TimerChannel;
    /**
    @brief The frequency of the configured timer channel
    */
    const uint32 Wdg_VR5510_u32TriggerSourceClock;
    /**
    @brief Pointer to Watchdog Specific implementation details
    */
#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /**< @brief DEM error reporting configuration. */
    const Wdg_VR5510_DemConfigType * Wdg_VR5510_pDemConfig;
#endif
    const Wdg_VR5510_IPW_ConfigType * Wdg_VR5510_ModeSettings[3];
    /**< @brief Pointer to callout get the PMIC fault status by user for task notifications. */
    const Wdg_VR5510_CheckFaultStatusNotifyType Wdg_VR5510_pCheckFaultNotification;
} Wdg_43_VR5510_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifdef WDG_43_VR5510_CONFIG_EXT
#define WDG_43_VR5510_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

WDG_43_VR5510_CONFIG_EXT

#define WDG_43_VR5510_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"
#endif

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
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
* @brief   This function initializes the WDG module.
* @details The @p Wdg_43_VR5510_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in] ConfigPtr     Pointer to configuration set.
*
*
* @api
*/
void Wdg_43_VR5510_Init(const Wdg_43_VR5510_ConfigType * pConfigPtr);

/**
* @brief   Switches the watchdog into the mode Mode.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p  Wdg_43_VR5510_SetMode
*          function:<br>
*          - WDGIF_OFF_MODE,
*          - WDGIF_SLOW_MODE.
*          - WDGIF_FAST_MODE.
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      -# WDGIF_OFF_MODE,
*                      -# WDGIF_SLOW_MODE,
*                      -# WDGIF_FAST_MODE.
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* @api
*/
Std_ReturnType Wdg_43_VR5510_SetMode(WdgIf_ModeType Mode);


/**
 * @brief   Reset the watchdog timeout counter according to the timeout value passed.
 * @details
 *
 * @param[in] Timeout value (milliseconds) for setting the trigger counter.
 *
 * @implements      Wdg_43_VR5510_SetTriggerCondition_Activity
 *
 * @api
 */
void Wdg_43_VR5510_SetTriggerCondition(uint16 u16Timeout);

#if (STD_ON == WDG_43_VR5510_VERSION_INFO_API)

/**
* @brief   Returns the version information of the module.
* @details The Wdg_43_VR5510_GetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This function is only required if the WDG_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] pVersioninfo   Pointer to where to store the version
*                              information of this module.
*
* @api
*
*
*/
void Wdg_43_VR5510_GetVersionInfo(Std_VersionInfoType * pVersioninfo);

#endif /* STD_ON == WDG_43_VR5510_VERSION_INFO_API*/
/**
* @brief   Triggers the Watchdog.
* @details The Wdg_Cbk_GptNotification shall trigger the hardware. It is set up
*          as notification function for the Gpt timer that controls the trigger of
*          the watchdog
*
* @pre    This API has to be set up as notification for the Gpt channels that is set up
*         for Wdg
*
* @param[in]   Wdg_InstanceID  ID of Watchdog external device.
*
*
*/
void Wdg_43_VR5510_Trigger(void);

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

#endif /* WDG_WDG_WDG_43_VR5510_H */
