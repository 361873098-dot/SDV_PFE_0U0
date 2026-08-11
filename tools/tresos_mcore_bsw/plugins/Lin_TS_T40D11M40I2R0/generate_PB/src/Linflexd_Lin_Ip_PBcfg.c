/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
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
*   @file    Linflexd_Lin_Ip_PBcfg.c
*   @implements Linflexd_Lin_Ip_PBcfg.c_Artifact
*
*   @addtogroup LINFLEXD_IP
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
#include "Linflexd_Lin_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              4
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Linflexd_Lin_Ip_Cfg.h */
#if (LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != LINFLEXD_LIN_IP_CFG_VENDOR_ID)
    #error "Linflexd_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Linflexd_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Linflexd_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Linflexd_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Cfg header file are of the same Software version */
#if ((LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Linflexd_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Linflexd_Lin_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"
[!NOCODE!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
/**
* @brief          Hardware configuration for Lin Hardware Instance [!"LinHwChannel"!] - Configuration:
*
* 
*/
[!VAR "LinBaudrate" = "LinChannelBaudRate"!][!//
[!IF "node:exists(LinClockRef)"!]
[!SELECT "node:ref(LinClockRef)"!][!//
    [!INCLUDE "Lin_BaudRate_Comp.m"!][!//
[!ENDSELECT!][!//
[!ENDIF!]
[!CODE!]

const Linflexd_Lin_Ip_UserConfigType Linflexd_Lin_Ip_pHwConfigPB_[!"LinChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    [!"num:i(substring-after(LinHwChannel,'_'))"!]U,  /* Instance */
    (boolean)[!IF "LinChannelWakeupSupport"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* Support wakeup detection */
    [!IF "contains(node:value(LinNodeType), 'MASTER')"!][!//
    (boolean)LINFLEXD_LIN_IP_MASTER,                        /*!< Master node */
    [!ELSE!][!//
    (boolean)LINFLEXD_LIN_IP_SLAVE,                         /*!< Slave node */
    [!ENDIF!]
    (boolean)FALSE,                                  /*!< Enable Autobaud feature */
    [!NOCODE!][!//
        [!VAR "IntegerBrkLength" = "substring-after(BreakLength,'_')"!]
        [!IF "$IntegerBrkLength = 36"!]
            [!VAR "VarBreakLength"="14"!]
        [!ELSEIF "$IntegerBrkLength = 50"!]
            [!VAR "VarBreakLength"="15"!]
        [!ELSE!]
            [!VAR "VarBreakLength"="$IntegerBrkLength - 10"!]
        [!ENDIF!]
    [!ENDNOCODE!]
    [!"num:inttohex($VarBreakLength,2)"!]U,                /*!< BreakLength = [!"substring-after(BreakLength,'_')"!] bits */

    (Linflexd_Lin_Ip_CallbackType)Lin_Ipw_Callback,         /*!< Callback function to invoke after receiving a byte or transmitting a byte. */

    &Linflexd_Lin_Ip_axStateStructure[[!"LinChannelId"!]],    /*!< Runtime state structure refference */

    (uint32)[!"$BaudrateConf_Value"!]UL,             /*!< Baud rates value */

    (uint8)[!"LinResponseTimeout"!]U,           /*!< Response timeout bit time */

    (uint8)[!"LinHeaderTimeout"!]U,             /*!< Header timeout bit time */

    (uint8)[!"num:i(11 - num:i(substring-after(SlaveSyncBreakLength,'_')))"!]U,         /*!< Slave sync break length = [!"substring-after(SlaveSyncBreakLength,'_')"!] */

    (uint8)0u,                                  /*!< 1 stop bit will be added after each frame byte */

    (uint8)STD_OFF                              /*!< Hardware performs the checksum calculation */
};
[!ENDCODE!]
[!ENDLOOP!][!//
[!ENDNOCODE!]
#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
