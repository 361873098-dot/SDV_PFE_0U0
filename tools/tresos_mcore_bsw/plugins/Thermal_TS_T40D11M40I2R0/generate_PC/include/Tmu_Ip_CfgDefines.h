[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : TMU
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
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

#ifndef TMU_IP_CFGDEFINES_H
#define TMU_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup tmu_ip_config TMU IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
[!CODE!][!WS "0"!]#include "S32G274A_TMU.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
[!CODE!][!WS "0"!]#include "S32G399A_TMU.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
[!CODE!][!WS "0"!]#include "S32R45_TMU.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!//
[!CODE!][!WS "0"!]#include "S32R41_TMU.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#include "OsIf.h"
[!NOCODE!][!//
[!INCLUDE "Thermal_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_CFGDEFINES                    43
#define TMU_IP_MODULE_ID_CFGDEFINES                    255
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define TMU_IP_SW_MAJOR_VERSION_CFGDEFINES             4
#define TMU_IP_SW_MINOR_VERSION_CFGDEFINES             0
#define TMU_IP_SW_PATCH_VERSION_CFGDEFINES             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (TMU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Tmu_Ip_CfgDefines.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define TMU_IP_DEV_ERROR_DETECT                         [!IF "ThermalGeneral/TmuIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Tmu Timeout Method. Based on this selection a certain timeout method from OsIf will be used in the driver.
*/
#define TMU_IP_TIMEOUT_TYPE                             [!IF "contains(ThermalGeneral/TmuTimeoutMethod,'OSIF_COUNTER_DUMMY')"!](OSIF_COUNTER_DUMMY)[!ELSEIF "contains(ThermalGeneral/TmuTimeoutMethod,'OSIF_COUNTER_SYSTEM')"!](OSIF_COUNTER_SYSTEM)[!ELSEIF "contains(ThermalGeneral/TmuTimeoutMethod,'OSIF_COUNTER_CUSTOM')"!][!ENDIF!]

/**
* @brief          Tmu Timeout Value.
*/
#define TMU_IP_TIMEOUT_VAL                              ([!"ThermalGeneral/TmuTimeoutVal"!]UL)

/**
* @brief          The default value for central module register.
* Important note: DAC_OFFSET initial value is sampled during POR from fuses, is partspecific, and should not be changed by the user.
*/
#define TMU_IP_DEFAULT_CENTRAL_MODULE_REG               ( TMU_TCMCFG_DPM(0U)  | TMU_TCMCFG_OCM(1U)     | \
                                                          TMU_TCMCFG_OCS(0U)  | TMU_TCMCFG_DEMA(1U)    | \
                                                          TMU_TCMCFG_RCTC(4U) | TMU_TCMCFG_CLK_DIV(4U) | \
                                                          TMU_TCMCFG_DFD(3U)  | TMU_TCMCFG_CMET(0U) )

/**
* @brief          Number of default calibration point configurations.
*/
#define TMU_IP_DEFAULT_CALIB_POINT_COUNT                ([!"num:i(ecu:get('Thermal.DefaultCalibPointCount'))"!]U)

/**
* @brief          The Trim value will be added/not added to default sensor value ((STD_ON)/(STD_OFF)).
*/
#define TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP                 [!IF "ThermalGeneral/ThermalLoadDacTrimFromOcotp"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          TMU_CFG_DAC_TRIM fuse address.
*/
#define TMU_IP_CFG_DAC_TRIM_ADDRESS                     ([!"ecu:get('Thermal.TmuCfgDacTrim.Address')"!])

/**
* @brief          The number of Trim will be added to default sensor value.
*/
#define TMU_IP_CFG_DAC_TRIM_COUNT                       ([!"num:i(ecu:get('Thermal.TmuCfgDacTrim.Count'))"!]U)

/**
* @brief          Tmu DAC Trim shift,index0 ->trim0, index1->trim1.
*/
#define TMU_IP_CFG_DAC_TRIM_SHIFT                       { [!"normalize-space( ecu:get('Thermal.TmuCfgDacTrim.Shift') )"!] }


/**
* @brief          Tmu DAC Trim valid mask to select the valid bit from fuse value.
*/
#define TMU_IP_CFG_DAC_TRIM_VALID_MASK                  ([!"ecu:get('Thermal.TmuCfgDacTrim.ValidMask')"!])


/**
* @brief          Tmu DAC Trim mask to select the data bits from the fuse value.
*/
#define TMU_IP_CFG_DAC_TRIM_DATA_MASK                   ([!"ecu:get('Thermal.TmuCfgDacTrim.DataMask')"!])

/**
* @brief          The Mask of CFG_DAC_TRIM sign bit.
*/
#define TMU_IP_CFG_DAC_TRIM_SIGN_MASK                   ([!"ecu:get('Thermal.TmuCfgDacTrim.SignMask')"!])

/**
* @brief          Maximum measurable temperature.
*/
#define TMU_IP_MAX_TEMP_AVAILABLE                       ([!"num:i(ecu:get('Thermal.MaxTempAvailable'))"!]U) /* Value expressed in Kelvin */

/**
* @brief          Tmu Ip configuration type.
*/
#define TMU_IP_CONFIG_TYPE                              Tmu_Ip_ConfigType

/**
* @brief          Tmu Separated critical interrupt ID is available or not
*/
#define TMU_IP_HAS_SEPARATED_IRQ                        [!IF "ecu:get('Thermal.HasSeparatedIrq') = 'TRUE'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!CODE!][!//
/**
* @brief          Default sensor values for default calibration point configurations.
*/
#define TMU_IP_DEFAULT_SENSOR_VALUE                     { [!"normalize-space( ecu:get('Thermal.DefaultSensorValues') )"!] }

/**
* @brief          Default temperature ranges for default calibration point configurations. These values are expressed in Kelvin.
*/
#define TMU_IP_DEFAULT_TEMPERATURE_VALUE                { [!"normalize-space( ecu:get('Thermal.DefaultTempValues') )"!] }


/**
* @brief          the Index to add Trim values to Default sensor values.
*/
#define TMU_IP_SENSOR_DAC_TRIM_INDEX                    { [!"normalize-space( ecu:get('Thermal.SensorDacTrimIndex') )"!] }

[!ENDCODE!][!//
/**
* @brief          Tmu user mode support enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define TMU_IP_ENABLE_USER_MODE_SUPPORT                 [!IF "ThermalGeneral/ThermalEnableUserModeSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          USER_MODE_REG_PROT_ENABLED is defined for Base sanity check in RegLockMacros.h
*/
#define USER_MODE_REG_PROT_ENABLED                      (TMU_IP_ENABLE_USER_MODE_SUPPORT)

[!NOCODE!][!//
    [!LOOP "ThermalConfigSet/TmuHwUnit/*"!][!//
    [!IF "count(TmuMonitoringSite/*[TmuEnableSite='true']) > 0"!]
[!CODE!][!//
/**
* @brief          Defines which associate monitoring site name to the corresponding index.
*                 Each index is associated to a physical placement that depends on the current platform.
*/
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "NumOfSites" = "count(ecu:list('Thermal.TmuConfigSet.TmuHwUnit.MonitoringSitePlacement'))"!]
    [!FOR "Index" = "0" TO "num:i($NumOfSites)"!][!//
        [!LOOP "ThermalConfigSet/TmuHwUnit/*/TmuMonitoringSite/*"!][!//
            [!IF "(TmuEnableSite = 'true') and (TmuSitePlacement = ecu:list('Thermal.TmuConfigSet.TmuHwUnit.MonitoringSitePlacement')[num:i($Index)])"!][!//
[!CODE!][!//
#define [!"@name"!]                             ([!"num:i($Index - 1)"!]U)
[!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TMU_IP_CFGDEFINES_H */
[!ENDCODE!][!//
