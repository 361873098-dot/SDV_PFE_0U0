/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : IIC
* Dependencies : MCU,PORT,DET,RTE
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.2
* Build Version : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef I2C_IP_CFGDEFINES_H
#define I2C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup IIC_DRIVER_CONFIGURATION IIC Driver Configurations
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
#include "[!"ecu:get('I2c.I2cHeaderName')"!].h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_CFGDEFINES_VENDOR_ID                     43
#define I2C_IP_CFGDEFINES_MODULE_ID                     255
#define I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      4
#define I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define I2C_IP_CFGDEFINES_SW_MAJOR_VERSION              4
#define I2C_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define I2C_IP_CFGDEFINES_SW_PATCH_VERSION              2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "masterConfig" = "0"!]
[!VAR "slaveConfig" = "0"!]
[!LOOP "I2cGlobalConfig/I2cChannel/*"!] /* Loop through all configured channels */
    [!IF "contains(I2cHwChannel,'IIC')"!] /* Select only I2C channels */
        [!IF "contains(I2cMasterSlaveConfiguration,'MASTER')"!] /* Based on the master-slave configuration other structures will be generated */
        [!VAR "masterConfig" = "num:i($masterConfig)+1"!]
        [!ELSE!]
        [!VAR "slaveConfig" = "num:i($slaveConfig)+1"!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!] /* End of the loop */
[]

[!ENDNOCODE!][!//


#define I2C_IP_NUMBER_OF_MASTER_INSTANCES [!"num:i($masterConfig)"!]U
#define I2C_IP_NUMBER_OF_SLAVE_INSTANCES  [!"num:i($slaveConfig)"!]U

/**
* @brief Define size of MUL array
*/
[!VAR "MULArraySize" = "num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescaledShiftRegister.MUL')))"!]
#define I2C_MUL_ARRAY_SIZE [!"$MULArraySize"!]U

/**
* @brief Define MUL array
*/
#define I2C_MUL_ARRAY     {[!FOR "ArrayLoop" = "1" TO "count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescaledShiftRegister.MUL'))"!][!CODE!][!"ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescaledShiftRegister.MUL')[num:i($ArrayLoop)]"!]U[!IF "$ArrayLoop != $MULArraySize"!], [!ENDIF!][!ENDCODE!][!ENDFOR!]}

/**
* @brief Define size of divider array
*/
[!VAR "ArraySize" = "num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.SCL2TAP')))"!]
#define I2C_DIVIDER_ARRAY_SIZE [!"$ArraySize"!]U

/**
* @brief Define SCL2TAP array
*/
#define I2C_SCL2TAP_ARRAY     {[!FOR "ArrayLoop" = "1" TO "count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.SCL2TAP'))"!][!CODE!][!"ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.SCL2TAP')[num:i($ArrayLoop)]"!]U[!IF "$ArrayLoop != $ArraySize"!], [!ENDIF!][!ENDCODE!][!ENDFOR!]}

/**
* @brief Define SCL2TAP array when glitch filter is enabled
*/
#define I2C_SCL2TAP_GLITCH_ARRAY     {[!FOR "ArrayLoop" = "1" TO "count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.SCL2TAP_GLITCH_ENABLED'))"!][!CODE!][!"ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.SCL2TAP_GLITCH_ENABLED')[num:i($ArrayLoop)]"!]U[!IF "$ArrayLoop != $ArraySize"!], [!ENDIF!][!ENDCODE!][!ENDFOR!]}

/**
* @brief Define SCLTAP array
*/
#define I2C_SCLTAP_ARRAY      {[!FOR "ArrayLoop" = "1" TO "count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cShiftRegisterTapPoint.SCL_TAP'))"!][!CODE!][!"ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cShiftRegisterTapPoint.SCL_TAP')[num:i($ArrayLoop)]"!]U[!IF "$ArrayLoop != $ArraySize"!], [!ENDIF!][!ENDCODE!][!ENDFOR!]}

/**
* @brief Define TAP2TAP array
*/
#define I2C_TAP2TAP_ARRAY     {[!FOR "ArrayLoop" = "1" TO "count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.TAP2TAP'))"!][!CODE!][!"ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cMasterConfiguration.I2cPrescalerDivider.TAP2TAP')[num:i($ArrayLoop)]"!]U[!IF "$ArrayLoop != $ArraySize"!], [!ENDIF!][!ENDCODE!][!ENDFOR!]}

/**
* @brief            Error detection for IP layer
*/
#define I2C_IP_DEV_ERROR_DETECT   [!IF "GeneralConfiguration/I2cDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Development Error Detection for IP */[!ENDIF!]

/**
* @brief            Error events of the i2c module enable/disabled
*/
#define I2C_IP_EVENT_ERROR_DETECT   [!IF "node:exists(GeneralConfiguration/I2cErrorCallback)"!](STD_ON)  /* Enable Development Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Development Error Detection for IP */[!ENDIF!]

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define I2C_IP_DMA_TRANSFER_ERROR_DETECT   [!IF "GeneralConfiguration/I2cDmaTransferErrorDetect"!](STD_ON)  /* Enable Dma Transfer Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Dma Transfer Error Detection for IP */[!ENDIF!]

/**
* @brief            Dma support enable/disabled
*/
#define I2C_IP_DMA_FEATURE_AVAILABLE [!IF "GeneralConfiguration/I2cDmaUsed"!](STD_ON) /* Enable DMA support for IP */[!ELSE!](STD_OFF) /* Disable DMA support for IP */[!ENDIF!]

/**
* @brief            Enable User Mode Support.
*/
#define I2C_ENABLE_USER_MODE_SUPPORT   [!IF "GeneralConfiguration/I2cEnableUserModeSupport"!](STD_ON) /* Enable User Mode support for IP */[!ELSE!](STD_OFF) /* Disable User Mode support for IP */[!ENDIF!]

#define I2C_TIMEOUT_TYPE                ([!"GeneralConfiguration/I2cTimeoutMethod"!])

/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running I2C in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT macro needs to be defined.
  #endif /* (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /* I2C_IP_CFGDEFINES_H */
