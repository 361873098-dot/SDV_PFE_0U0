/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Pmic_VR55XX
*   Dependencies         : MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP
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

#ifndef CDD_PMIC_CFG_H
#define CDD_PMIC_CFG_H

/**
*   @file CDD_Pmic_Cfg.h
*
*   @addtogroup PMIC_DRIVER_CONFIGURATION PMIC Driver Configurations
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
#include "Mcal.h"
[!IF "node:value(PmicGeneralConfiguration/PmicTimeoutMechanism) = 'TICKS'"!][!//
#include "OsIf.h"
[!ENDIF!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#include "CDD_Pmic_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!][!//
#include "CDD_Pmic_PBcfg.h"
[!ENDIF!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PMIC_MODULE_ID_CFG                    255
#define PMIC_CFG_VENDOR_ID                    43
#define PMIC_CFG_AR_RELEASE_MAJOR_VERSION     4
#define PMIC_CFG_AR_RELEASE_MINOR_VERSION     4
#define PMIC_CFG_AR_RELEASE_REVISION_VERSION  0
#define PMIC_CFG_SW_MAJOR_VERSION             4
#define PMIC_CFG_SW_MINOR_VERSION             0
#define PMIC_CFG_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((PMIC_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_Pmic_Cfg.h and Mcal.h are different"
    #endif
#endif
[!NOCODE!][!//
[!INCLUDE "CDD_Pmic_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          The symbolic names of all the available devices (given in a particular configuration).
*/
[!NOCODE!][!//
[!SELECT "PmicGlobalConfig"!][!//
[!LOOP "PmicDevice/*"!][!//
[!CODE!][!//
#define PmicConf_PmicDevice_[!"node:name(.)"!]    ((uint32)[!"PmicDeviceId"!]U)
[!ENDCODE!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//

/**
* @brief            Create defines with the IDs assigned to PMIC Clock configurations.
*                   These IDs will be transmitted as input parameters to Pmic_InitClock() API.
*/
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "DeviceName" = "name(.)"!][!//
[!LOOP "PmicClockSettingConfig/*"!][!//
#define PmicConf_[!"$DeviceName"!]_PmicClockSettingConfig_[!"name(.)"!]    ((uint32)[!"num:i( num:i(PmicClockSettingId) )"!]U)
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/**
* @brief            Create defines with the IDs assigned to PMIC Mode configurations.
*                   These IDs will be transmitted as input parameters to Pmic_SetMode() API.
*/
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "DeviceName" = "name(.)"!][!//
[!LOOP "PmicModeSettingConf/*"!][!//
#define PmicConf_[!"$DeviceName"!]_PmicModeSettingConf_[!"name(.)"!]    ((uint32)[!"num:i( num:i(PmicModeID) )"!]U)
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/**
* @brief            Create defines with the IDs assigned to PMIC Reaction configurations.
*                   These IDs will be transmitted as input parameters to Pmic_SetReactions() API.
*/
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "DeviceName" = "name(.)"!][!//
[!LOOP "PmicReactionsSettingConf/*"!][!//
#define PmicConf_[!"$DeviceName"!]_PmicReactionsSettingConf_[!"name(.)"!]    ((uint32)[!"num:i( num:i(PmicReactionsSettingId) )"!]U)
[!ENDLOOP!][!//
[!ENDLOOP!][!//

[!IF "PmicGeneralConfiguration/PmicWatchdogApi"!][!//
/**
* @brief            Create defines with the IDs assigned to PMIC Watchdog configurations.
*                   These IDs will be transmitted as input parameters to Pmic_ConfigureWatchdog() API.
*/
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "DeviceName" = "name(.)"!][!//
[!LOOP "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*"!][!//
#define PmicConf_[!"$DeviceName"!]_PmicWatchdogSettingConf_[!"name(.)"!]    ((uint32)[!"num:i( num:i(PmicWatchdogSettingId) )"!]U)
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!IF "PmicGeneralConfiguration/PmicSetAnalogMuxApi = 'true'"!][!//
/**
* @brief            Create defines with the IDs assigned to PMIC AMUX configurations.
*                   These IDs will be transmitted as input parameters to Pmic_SetAnalogMux() API.
*/
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "DeviceName" = "name(.)"!][!//
[!LOOP "PmicAMUXConfiguration/PmicAmuxChannel/*"!][!//
#define PmicConf_[!"$DeviceName"!]_PmicAmuxChannel_[!"name(.)"!]    ((uint32)[!"num:i( num:i(PmicAmuxChannelId) )"!]U)
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//

[!IF "PmicGeneralConfiguration/PmicSwitchSVSApi = 'true'"!][!//
/**
* @brief            Create defines with the IDs assigned to PMIC SVS configurations.
*                   These IDs will be transmitted as input parameters to Pmic_SwitchSVS() API.
*/
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "DeviceName" = "name(.)"!][!//
[!LOOP "PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*"!][!//
#define PmicConf_[!"$DeviceName"!]_PmicSVS_[!"name(.)"!]    ((uint32)[!"num:i( num:i(PmicSVSSettingId) )"!]U)
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//

[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!][!//
/**
* @brief   macro contains all PB configuration macros.
*/
#define PMIC_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
    PMIC_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
    PMIC_CONFIG_PB
[!ENDIF!]
[!ENDIF!]

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define PMIC_PRECOMPILE_SUPPORT    [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define PMIC_DEV_ERROR_DETECT    [!IF "PmicGeneralConfiguration/PmicDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF) /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief   Switches the Ip Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define PMIC_IP_DEV_ERROR_DETECT    [!IF "PmicGeneralConfiguration/PmicDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF) /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief          Support for version info API.
* @details        Switches the Pmic_GetVersionInfo() API ON or OFF.
*
* @api
*/
#define PMIC_VERSION_INFO_API    [!IF "PmicGeneralConfiguration/PmicVersionInfoApi"!](STD_ON)  /* Enable API Pmic_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API Pmic_GetVersionInfo     */[!ENDIF!]

/**
* @brief          Support for device info API.
* @details        Switches the Pmic_GetDeviceInfo() API ON or OFF.
*
* @api
*/
#define PMIC_DEVICE_INFO_API    [!IF "PmicGeneralConfiguration/PmicDeviceInfoApi"!](STD_ON)  /* Enable API Pmic_GetDeviceInfo      */[!ELSE!](STD_OFF) /* Disable API Pmic_GetDeviceInfo     */[!ENDIF!]

/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define PMIC_DISABLE_DEM_REPORT_ERROR_STATUS    [!IF "(PmicGeneralConfiguration/PmicDisableDemReportErrorStatus='true') or (num:i(count(PmicGlobalConfig/PmicDemEventParameterRefs[node:exists(.)]))=0)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable/Disable the API for setting the AMUX pin.
*/
#define PMIC_SET_ANALOG_MUX_API    [!IF "PmicGeneralConfiguration/PmicSetAnalogMuxApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable/Disable the API for setting the failsafe static voltage scaler SVS.
*/
#define PMIC_SWITCH_SVS_API    [!IF "PmicGeneralConfiguration/PmicSwitchSVSApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable/Disable the Watchdog API.
*/
#define PMIC_WATCHDOG_API    [!IF "PmicGeneralConfiguration/PmicWatchdogApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable/Disable the External Watchdog Primitives.
*/
#define PMIC_EXTERNAL_WATCHDOG_API    [!IF "(PmicGeneralConfiguration/PmicExternalWatchdog='true') and (PmicGeneralConfiguration/PmicWatchdogApi='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Check if at least one Pmic device has watchdog monitoring enabled.
*/
[!NOCODE!][!//
[!VAR "PmicWdOn" = "0"!][!//
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!LOOP "PmicOtpConfiguration/*"!][!//
    [!IF "(PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicWatchdogEnable = 'true')"!][!//
   [!VAR "PmicWdOn" = "1"!][!//
       [!BREAK!][!//
        [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
#define PMIC_WATCHDOG_ENABLED    [!IF "num:i($PmicWdOn) = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable/Disable the Emulation OTP API.
*/
#define PMIC_OTP_EMULATION_MODE_API    [!IF "PmicGeneralConfiguration/PmicOtpEmulationModeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!//

[!NOCODE!][!//
[!IF "PmicGeneralConfiguration/PmicTimeoutMechanism = 'LOOPS'"!][!//
[!CODE!][!//
/**
* @brief            Enable/Disable timeout mechanism using loop counting.
*/
#define PMIC_TIMEOUT_MECHANISM_LOOPS    (STD_ON)
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
/**
* @brief            Enable/Disable timeout mechanism using timer ticks.
*/
#define PMIC_TIMEOUT_MECHANISM_LOOPS    (STD_OFF)
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!IF "node:value(PmicGeneralConfiguration/PmicTimeoutMechanism) = 'TICKS'"!][!//
/* OsIf counter type used in timeout*/
#define PMIC_TIMEOUT_OSIF_COUNTER_TYPE    ([!"PmicGeneralConfiguration/PmicTimeoutMethod"!])
[!ENDIF!][!//

/**
* @brief            Maximum duration before returning PMIC_E_TIMEOUT. The unit of measurement is given by PmicTimeoutMechanism.
*/
#define PMIC_TIMEOUT_DURATION    ([!"PmicGeneralConfiguration/PmicTimeoutDuration"!]U)

/**
* @brief            Support for the DIE_PROCESS Setup.
*/
#define PMIC_DIE_PROCESS_ENABLE    [!IF "PmicGeneralConfiguration/PmicDieProcessEnable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!//

/**
* @brief            Support for the user mode.
*/
#define PMIC_ENABLE_USER_MODE_SUPPORT    [!IF "PmicGeneralConfiguration/PmicEnableUserModeSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!//

/**
* @brief            Support for the I2C interface.
*/
#define PMIC_INTERFACE_I2C_USED    (STD_ON)

/**
* @brief            Support for the SPI interface.
*/
#define PMIC_INTERFACE_SPI_USED    (STD_OFF)
[!IF "PmicGeneralConfiguration/PmicDieProcessEnable"!][!//
/**
* @brief            Support for the OCotp interface.
*/
#define PMIC_OCOTP_ISTANCE    ((uint32)0U)

/**
* @brief            Used in calculating the value of die process in Mcu OTP.
*/
#define PMIC_OCOTP_DIE_PROCESS_MASK    ((uint32)3U)
[!ENDIF!][!//
/**
* @brief            Used in calculating the size of the internal buffer used for the "Pmic_ReadRegister" and "Pmic_WriteRegister" functions.
*/
#define PMIC_BYTES_PER_COMMAND_U32    ((uint8)5U)

/**
* @brief            The number of bytes representing the actual data within the packet/command.
*/
#define PMIC_PAYLOAD_SIZE_U32    ((uint8)4U)

/**
* @brief            The SIUL_2 instance of I2C pin.
*/
#define PMIC_SIUL_INSTANCE_U8    ((uint8)0U)

/**
* @brief            The number of OTP main register.
*/
#define PMIC_VR55XX_NUMBER_OF_OTP_MAIN_REGISTER    ((uint8)26U)

/**
* @brief            The number of OTP main register.
*/
#define PMIC_VR55XX_NUMBER_OF_OTP_FAIL_SAFE_REGISTER    ((uint8)21U)

/**
* @brief            Maximum number of PMIC device configurations.
*/
[!NOCODE!][!//
[!VAR "MaxNoOfDeviceCfgs" = "0"!][!//
[!IF "$MaxNoOfDeviceCfgs < num:i(count(PmicGlobalConfig/PmicDevice/*))"!][!//
[!VAR "MaxNoOfDeviceCfgs" = "num:i(count(PmicGlobalConfig/PmicDevice/*))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define PMIC_MAX_DEVICECONFIGS    ((uint32)[!"num:i($MaxNoOfDeviceCfgs)"!]U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            The Pmic_DeviceIndexType specifies the identification (ID) for a Pmic mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_DeviceIndexType_typedef
*/
typedef uint32 Pmic_DeviceIndexType;

/**
* @brief            The Pmic_ModeIndexType specifies the identification (ID) for a Pmic mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_ModeIndexType_typedef
*/
typedef uint32 Pmic_ModeIndexType;

/**
* @brief            The Pmic_ClockSettingIndexType specifies the identification (ID) for a Pmic clock setting, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_ClockSettingIndexType_typedef
*/
typedef uint32 Pmic_ClockSettingIndexType;

[!IF "PmicGeneralConfiguration/PmicSetAnalogMuxApi"!][!//
/**
* @brief            The Pmic_AmuxChannelIndexType specifies the identification (ID) for a Pmic amux channel, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_AmuxChannelIndexType_typedef
*/
typedef uint32 Pmic_AmuxChannelIndexType;
[!ENDIF!][!//

[!IF "PmicGeneralConfiguration/PmicSwitchSVSApi"!][!//
/**
* @brief            The Pmic_SvsSettingIndexType specifies the identification (ID) for a Pmic svs, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_SvsSettingIndexType_typedef
*/
typedef uint32 Pmic_SvsSettingIndexType;
[!ENDIF!][!//

/**
* @brief            The Pmic_ReactionSettingIndexType specifies the identification (ID) for a Pmic reaction setting, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_ReactionSettingIndexType_typedef
*/
typedef uint32 Pmic_ReactionSettingIndexType;

/**
* @brief            The Pmic_WatchdogSettingIndexType specifies the identification (ID) for a Pmic watchdog configuration, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_WatchdogSettingIndexType_typedef
*/
typedef uint32 Pmic_WatchdogSettingIndexType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_PMIC_CFG_H */
