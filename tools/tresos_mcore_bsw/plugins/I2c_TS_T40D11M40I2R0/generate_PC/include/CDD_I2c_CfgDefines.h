/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IIC
*   Dependencies         : MCU,PORT,DET,RTE
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_I2C_CFGDEFINES_H
#define CDD_I2C_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup i2c_driver_config I2c Driver Configuration
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_VENDOR_ID_CFGDEFINES                    43
#define I2C_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define I2C_AR_RELEASE_MINOR_VERSION_CFGDEFINES     4
#define I2C_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define I2C_SW_MAJOR_VERSION_CFGDEFINES             4
#define I2C_SW_MINOR_VERSION_CFGDEFINES             0
#define I2C_SW_PATCH_VERSION_CFGDEFINES             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "not(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!] [!//
/**
* @brief   macro contains all PB configuration macros.
*/
#define I2C_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantIndex"="0"!][!//
[!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
 I2C_CONFIG_[!"."!]_PB [!IF "$variantIndex < $variantNumber"!]\[!ENDIF!]
[!ENDLOOP!][!//
[!ELSE!][!//
 I2C_CONFIG_PB
[!ENDIF!]
[!ENDIF!]

/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define I2C_PRECOMPILE_SUPPORT [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief   Total number of I2c channel configured.
*/
#define I2C_HW_MAX_CONFIG           ([!"num:i(count(I2cGlobalConfig/I2cChannel/*))"!]U)

/**
* @brief   Total number of available hardware I2C channels.
*/
#define I2C_HW_MAX_MODULES          ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')))"!]U)

/**
* @brief   Total number of available hardware I2C channels.
*/
#define I2C_IIC_MAX_MODULES       ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')[contains(., 'IIC')]))"!]U)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define I2C_DEV_ERROR_DETECT      [!IF "GeneralConfiguration/I2cDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF) /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief          Support for version info API.
* @details        Switches the I2c_GetVersionInfo() API ON or OFF.
*
* @api
*/
#define I2C_VERSION_INFO_API      [!IF "GeneralConfiguration/I2cVersionInfoApi"!](STD_ON)  /* Enable API I2c_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API I2c_GetVersionInfo     */[!ENDIF!]

[!NOCODE!]
[!IF "variant:size()<=1"!][!//
[!CODE!]
/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
* @details        Link I2c channels symbolic names with I2c channel IDs.
*
* @api
*/
[!ENDCODE!]
[!FOR "index" = "0" TO "num:i(ecu:get('I2c.I2cGlobalConfig.I2cChannel'))-1"!]
    [!VAR "I2cEcuHwChannel" = "string((ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel'))[$index+1])"!]
    [!VAR "ChannelFound" = "0"!]
    [!LOOP "I2cGlobalConfig/I2cChannel/*"!]
        [!VAR "HardwareChannel" = "string(I2cHwChannel)"!]
        [!IF "$I2cEcuHwChannel = $HardwareChannel"!]
            [!IF "$ChannelFound = 0"!]
                [!CODE!][!//

#define I2C_[!"$I2cEcuHwChannel"!]    [!"substring-after(I2cHwChannel,'_')"!]U[!//

                [!ENDCODE!]
                [!VAR "ChannelFound" = "1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]

[!CODE!]
/**
* @brief  I2c channel name to logic channel id mapping
*/
[!ENDCODE!]
    [!VAR "I2cMasterNumber" = "num:i(0)"!]
    [!VAR "I2cSlaveNumber" = "num:i(0)"!]
    [!LOOP "I2cGlobalConfig/I2cChannel/*"!][!//
        [!VAR "I2cMasterSlave" = "node:value(I2cMasterSlaveConfiguration)"!]
            [!CODE!]
#define [!"@name"!]                 ([!"node:value(I2cChannelId)"!]U)[!CR!][!//
            [!ENDCODE!]
        [!IF "$I2cMasterSlave = 'MASTER_MODE'"!]
            [!CODE!]
#define I2C_MASTER_[!"$I2cMasterNumber"!]             [!"@name"!][!CR!][!//
            [!VAR "I2cMasterNumber" = "num:i($I2cMasterNumber + 1)"!]
            [!ENDCODE!]
        [!ELSE!]
            [!CODE!]
#define I2C_SLAVE_[!"$I2cSlaveNumber"!]               [!"@name"!][!CR!][!//
            [!VAR "I2cSlaveNumber" = "num:i($I2cSlaveNumber + 1)"!]
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!][!//

[!ENDIF!]
[!ENDNOCODE!]

[!IF "as:modconf('I2c')[1]/GeneralConfiguration/I2cMulticoreSupport='true'"!]
[!CODE!]
/**
* @brief          Unallocate coreid.
* @details        If have any channel not allocate to partition
*
* @api
*/
#define I2C_UNALLOCATED_CORE_ID     ([!"num:i(255)"!]U)
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!]
/**
* @brief          Spurious coreid.
* @details        If multicore support disable
*
* @api
*/
#define I2C_SPURIOUS_CORE_ID        ([!"num:i(0)"!]U)
[!ENDCODE!][!//
[!ENDIF!][!//

/**
* @brief          Symbolic names for configured channels.
* @details        Symbolic names for configured channels.
*
* @api
*/
[!LOOP "I2cGlobalConfig/I2cChannel/*"!][!//
/*
* @violates @ref CDD_I2c_Cfg_h_REF_1 The compiler/linker shall be schecked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2cConf_I2cChannel_[!"node:name(.)"!]         [!"I2cChannelId"!]
[!ENDLOOP!][!//


/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define I2C_DISABLE_DEM_REPORT_ERROR_STATUS   [!IF "(GeneralConfiguration/I2cDisableDemReportErrorStatus='false') or (node:exists(I2cGlobalConfig/I2cDemEventParameterRefs))"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

/**
* @brief            Enable/Disable Multi Core Support.
*/
#define I2C_MULTICORE_SUPPORT   [!IF "(GeneralConfiguration/I2cMulticoreSupport='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            DMA is used for at least one channel (STD_ON/STD_OFF)
*/
[!CODE!][!//
#define I2C_DMA_USED   [!IF "(GeneralConfiguration/I2cDmaUsed='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#if (I2C_MULTICORE_SUPPORT == STD_ON)
    #define I2c_GetCoreID()            OsIf_GetCoreID()
#else
    #define I2c_GetCoreID()            ((uint32)0UL)
#endif /* (I2C_MULTICORE_SUPPORT == STD_ON) */

/**
* @brief            TIMEOUT for sync transmissions
*/
#define I2C_TIMEOUT               [!"GeneralConfiguration/I2cTimeoutDuration"!]U
[!ENDCODE!][!//

[!IF "(GeneralConfiguration/I2c_Callback)='true'"!]
    [!IF "(GeneralConfiguration/I2cCallback)!='NULL_PTR'"!]
/**
* @brief            The callback configured by the user for i2c events.
*/
/* @violates @ref I2c_Cfg_h_REF_6 A function should be used in preference to a function-like macro where they are interchangeable. */
#define I2C_MODULE_CALLBACK(Event, Channel) ([!"normalize-space(GeneralConfiguration/I2cCallback)"!](Event, Channel))

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief            The callback configured by the user for i2c events.
*/
extern void I2C_MODULE_CALLBACK(uint8 Event, uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
    [!ENDIF!]
[!ENDIF!]
[!IF "(GeneralConfiguration/I2c_ErrorCallback)='true'"!]
    [!IF "(GeneralConfiguration/I2cErrorCallback)!='NULL_PTR'"!]
/**
* @brief            The callback configured by the user for i2c events.
*/
/* @violates @ref I2c_Cfg_h_REF_6 A function should be used in preference to a function-like macro where they are interchangeable. */
#define I2C_ERROR_CALLBACK(Event, Channel) ([!"normalize-space(GeneralConfiguration/I2cErrorCallback)"!](Event, Channel))

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief            The callback configured by the user for i2c events.
*/
extern void I2C_ERROR_CALLBACK(uint8 Event, uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
    [!ENDIF!]
[!ENDIF!]
/**
* @brief        Variable storing number of maximum partitions using in configuration.
*/
[!NOCODE!]
[!VAR "MaxCoreId"="0"!]
[!IF "as:modconf('I2c')[1]/GeneralConfiguration/I2cMulticoreSupport='true'"!][!//
    [!LOOP "as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*"!][!//
        [!IF "$MaxCoreId < node:value(./EcucCoreId)"!]
            [!VAR "MaxCoreId"="node:value(./EcucCoreId)"!]
        [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!]
[!ENDNOCODE!]
#define I2C_MAX_CORE_ID     ((uint8)[!"num:i($MaxCoreId+1)"!]U)

/**
* @brief    The value initialization un init for each core.
*/
#define I2C_UNINIT_CORE \
{[!//
[!NOCODE!]
    [!VAR "FirstCore"="num:i(1)"!]
    [!FOR "Coreid"="0" TO "$MaxCoreId"!]
        [!IF "$FirstCore = num:i(0)"!][!CODE!],[!ENDCODE!][!ELSE!][!VAR "FirstCore"="num:i(0)"!][!ENDIF!][!CODE!] I2C_UNINIT[!ENDCODE!][!//
    [!ENDFOR!]
[!ENDNOCODE!][!//
}

/**
* @brief    The value initialization null pointer for each core.
*/
#define I2C_NULL_PTR \
{[!//
[!NOCODE!]
    [!VAR "FirstCore"="num:i(1)"!]
    [!FOR "Coreid"="0" TO "$MaxCoreId"!]
        [!IF "$FirstCore = num:i(0)"!][!CODE!],[!ENDCODE!][!ELSE!][!VAR "FirstCore"="num:i(0)"!][!ENDIF!][!CODE!] NULL_PTR[!ENDCODE!][!//
    [!ENDFOR!]
[!ENDNOCODE!][!//
}

[!NOCODE!][!//
[!VAR "HwMaxChannel" = "num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')))"!]
[!ENDNOCODE!][!//
/**
* @brief        The value initialization Hardware Map.
*/
#define I2C_HW_MAP_INIT \
{[!//
[!NOCODE!]
    [!VAR "FirstChannel"="num:i(1)"!]
    [!FOR "Channel"="0" TO "$HwMaxChannel - 1"!]
        [!IF "$FirstChannel = num:i(0)"!][!CODE!],[!ENDCODE!][!ELSE!][!VAR "FirstChannel"="num:i(0)"!][!ENDIF!][!CODE!] -1[!ENDCODE!][!//
    [!ENDFOR!]
[!ENDNOCODE!][!//
}

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

#endif /* CDD_I2C_CFGDEFINES_H */

