[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef OCOTP_IP_CFG_H
#define OCOTP_IP_CFG_H

/**
*   @file
*
*   @addtogroup OCOTP_IP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocotp_Ip_Types.h"
#include "[!"ecu:get('Ocotp.Header')"!]"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IP_VENDOR_ID_CFG                    43
#define OCOTP_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define OCOTP_IP_AR_RELEASE_MINOR_VERSION_CFG     4
#define OCOTP_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define OCOTP_IP_SW_MAJOR_VERSION_CFG             4
#define OCOTP_IP_SW_MINOR_VERSION_CFG             0
#define OCOTP_IP_SW_PATCH_VERSION_CFG             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Ip_Types header file are of the same vendor */
#if (OCOTP_IP_VENDOR_ID_CFG != OCOTP_IP_TYPES_VENDOR_ID)
    #error "Ocotp_Ip_Cfg.h and Ocotp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Types header file are of the same Autosar version */
#if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION_CFG    != OCOTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IP_AR_RELEASE_MINOR_VERSION_CFG    != OCOTP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IP_AR_RELEASE_REVISION_VERSION_CFG != OCOTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_Ip_Cfg.h and Ocotp_Ip_Types.h are different"
#endif
/* Check if current file and Ocotp_Ip_Types header file are of the same Software version */
#if ((OCOTP_IP_SW_MAJOR_VERSION_CFG != OCOTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_IP_SW_MINOR_VERSION_CFG != OCOTP_IP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_IP_SW_PATCH_VERSION_CFG != OCOTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Ip_Cfg.h and Ocotp_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!CODE!]
/* Ocotp Hardware ConfigSet */
extern const Ocotp_Ip_ConfigType Ocotp_ConfigSet_[!"."!]_pHwConfig;
        [!ENDCODE!]
    [!ENDLOOP!]
[!ELSE!]
    [!CODE!]
/* Ocotp Hardware ConfigSet */
extern const Ocotp_Ip_ConfigType Ocotp_ConfigSet_pHwConfig;
    [!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Number of mapped eFuses  */
#define OCOTP_IP_NUMBER_OF_MAP_EFUSES            [!"ecu:get('Ocotp.NumberSupportedEFuses')"!]U

/* Column [0] = eFuse address, column [1] = corresponding ECC eFuse address, column [2] = shift for corresponding ECC */
#define OCOTP_IP_EFUSE_ADDRESS_MAP            { {0x208, 0x39C, 16U}, {0x20C, 0x39C, 24U}, {0x210, 0U, 0U},     {0x214, 0U, 0U},     \
                                     [!WS "48"!]{0x218, 0U, 0U},     {0x234, 0x3A8, 8U},  {0x238, 0x3A8, 16U}, {0x23C, 0x3A8, 24U}, \
                                     [!WS "48"!]{0x240, 0x3AC, 0U},  {0x244, 0x3AC, 8U},  {0x248, 0x3AC, 16U}, {0x24C, 0x3AC, 24U}, \
                                     [!WS "48"!]{0x250, 0x3B0, 0U},  {0x298, 0u, 0U},     {0x2A4, 0x3C4, 8U},  {0x2A8, 0x3C4, 16U}, \
                                     [!WS "48"!]{0x2DC, 0x3D0, 24U}, {0x2E0, 0x3D4, 0U},  {0x2E4, 0x3D4, 8U},  {0x360, 0x3F4, 0U},  \
                                     [!WS "48"!]{0x364, 0x3F4, 8U},  {0x368, 0x3F4, 16U}, {0x36C, 0x3F4, 24U}, {0x370, 0x3F8, 0U},  \
                                     [!WS "48"!]{0x374, 0x3F8, 8U},  {0x378, 0x3F8, 16U}, {0x37C, 0x3F8, 24U}, {0x380, 0x3FC, 0U},  \
                                     [!WS "48"!]{0x384, 0x3FC, 8U},  {0x388, 0x3FC, 16U} }

/* Number of shadow registers are available for Read Write */
#define OCOTP_IP_NUMBER_OF_RW_SHADOW             [!"ecu:get('Ocotp.NumberShadowRegisters')"!]U

/* Pre-processor switch to enable/disable development error detection for Ocotp Ip API */
#define OCOTP_IP_DEV_ERROR_DETECT              ([!IF "OcotpGeneral/OcotpIpDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_WRITE_EFUSE_API               ([!IF "OcotpGeneral/OcotpWriteEFuseApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_WRITE_SHADOW_API              ([!IF "OcotpGeneral/OcotpWriteShadowRegisterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_READ_EFUSE_API                ([!IF "OcotpGeneral/OcotpReadEFuseApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_READ_SHADOW_API               ([!IF "OcotpGeneral/OcotpReadShadowRegisterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_READ_GP_REGISTER_API          ([!IF "OcotpGeneral/OcotpReadApplicationInformationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_WRITE_GP_REGISTER_API         ([!IF "OcotpGeneral/OcotpWriteApplicationInformationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_ECC_ERROR_INJECT_API          ([!IF "OcotpGeneral/OcotpEccErrorInjectionApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_ECC_GET_ERROR_API             ([!IF "OcotpGeneral/OcotpEccGetErrorApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_SET_MODE_API                  ([!IF "OcotpGeneral/OcotpSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_CRC_TEST_API                  ([!IF "OcotpGeneral/OcotpCrcTestApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_TIMEOUT_TYPE                  ([!"node:value(OcotpGeneral/OcotpTimeoutMethod)"!])

[!IF "ecu:get('Ocotp.SupportStickyRegister') = 'true'"!]
#define OCOTP_IP_READ_STR_REGISTER_API          ([!IF "OcotpGeneral/OcotpReadStickyInformationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_IP_WRITE_STR_REGISTER_API         ([!IF "OcotpGeneral/OcotpWriteStickyInformationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//

/* OCOTP timeout value */
#define OCOTP_IP_WRITE_TIMEOUT_VALUE              [!"num:i(OcotpGeneral/OcotpWriteTimeout)"!]U
#define OCOTP_IP_READ_TIMEOUT_VALUE               [!"num:i(OcotpGeneral/OcotpReadTimeout)"!]U
#define OCOTP_IP_SET_MODE_TIMEOUT_VALUE           [!"num:i(OcotpGeneral/OcotpSetModeTimeout)"!]U
#define OCOTP_IP_CRC_VALIDATE_TIMEOUT_VALUE       [!"num:i(OcotpGeneral/OcotpCrcValidateTimeout)"!]U

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

[!ENDINDENT!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCOTP_IP_CFG_H */
