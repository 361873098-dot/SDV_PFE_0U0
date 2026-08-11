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

#ifndef CDD_I2C_CFG_H
#define CDD_I2C_CFG_H

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
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

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
[!CODE!]#include "CDD_I2c_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!]#include "CDD_I2c_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_VENDOR_ID_CFG                    43
#define I2C_MODULE_ID_CFG                    255
#define I2C_AR_RELEASE_MAJOR_VERSION_CFG     4
#define I2C_AR_RELEASE_MINOR_VERSION_CFG     4
#define I2C_AR_RELEASE_REVISION_VERSION_CFG  0
#define I2C_SW_MAJOR_VERSION_CFG             4
#define I2C_SW_MINOR_VERSION_CFG             0
#define I2C_SW_PATCH_VERSION_CFG             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h file are of the same module */
#if (I2C_MODULE_ID_CFG  != I2C_[!"."!]_PBCFG_MODULE_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h have different module ids"
#endif
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h file are of the same vendor */
#if (I2C_VENDOR_ID_CFG != I2C_[!"."!]_PBCFG_VENDOR_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h file are of the same Autosar version */
#if (  (I2C_AR_RELEASE_MAJOR_VERSION_CFG    != I2C_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
       (I2C_AR_RELEASE_MINOR_VERSION_CFG    != I2C_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
       (I2C_AR_RELEASE_REVISION_VERSION_CFG != I2C_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h are different"
#endif
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h file are of the same Software version */
#if ( (I2C_SW_MAJOR_VERSION_CFG != I2C_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
      (I2C_SW_MINOR_VERSION_CFG != I2C_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
      (I2C_SW_PATCH_VERSION_CFG != I2C_[!"."!]_PBCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if current file and CDD_I2c_PBcfg.h file are of the same module */
#if (I2C_MODULE_ID_CFG  != I2C_PBCFG_MODULE_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h have different module ids"
#endif
/* Check if current file and CDD_I2c_PBcfg.h file are of the same vendor */
#if (I2C_VENDOR_ID_CFG != I2C_PBCFG_VENDOR_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_PBcfg.h file are of the same Autosar version */
#if (  (I2C_AR_RELEASE_MAJOR_VERSION_CFG    != I2C_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
       (I2C_AR_RELEASE_MINOR_VERSION_CFG    != I2C_PBCFG_AR_RELEASE_MINOR_VERSION) || \
       (I2C_AR_RELEASE_REVISION_VERSION_CFG != I2C_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h are different"
#endif
/* Check if current file and CDD_I2c_PBcfg.h file are of the same Software version */
#if ( (I2C_SW_MAJOR_VERSION_CFG != I2C_PBCFG_SW_MAJOR_VERSION) || \
      (I2C_SW_MINOR_VERSION_CFG != I2C_PBCFG_SW_MINOR_VERSION) || \
      (I2C_SW_PATCH_VERSION_CFG != I2C_PBCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h are different"
#endif
[!ENDIF!][!//

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHERS
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

#endif /* CDD_I2C_CFG_H */

