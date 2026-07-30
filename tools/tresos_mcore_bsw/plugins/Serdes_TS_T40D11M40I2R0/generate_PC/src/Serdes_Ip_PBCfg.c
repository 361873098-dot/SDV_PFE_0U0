/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : SERDES_SS
* Dependencies : none
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

/**
*   @file
*   @internal
*   @addtogroup Serdes
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Serdes_Ip.h"
#include "Serdes_Ip_PBCfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_PBCFG_VENDOR_ID_C                     43
#define SERDES_IP_PBCFG_MODULE_ID_C                     255
#define SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define SERDES_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define SERDES_IP_PBCFG_SW_MAJOR_VERSION_C              4
#define SERDES_IP_PBCFG_SW_MINOR_VERSION_C              0
#define SERDES_IP_PBCFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Serdes_Ip_PBCfg.c */
#if (SERDES_IP_PBCFG_VENDOR_ID_C != SERDES_IP_VENDOR_ID)
    #error "Serdes_Ip.h and Serdes_Ip_PBCfg.c have different vendor ids"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Autosar version */
#if ((SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Serdes_Ip.h and Serdes_Ip_PBCfg.c are different"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Software version */
#if ((SERDES_IP_PBCFG_SW_MAJOR_VERSION_C != SERDES_IP_SW_MAJOR_VERSION) || \
     (SERDES_IP_PBCFG_SW_MINOR_VERSION_C != SERDES_IP_SW_MINOR_VERSION) || \
     (SERDES_IP_PBCFG_SW_PATCH_VERSION_C != SERDES_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.h and Serdes_Ip_PBCfg.c are different"
#endif

/* Check if current file and Serdes_Ip_PBCfg.h  file are of the same vendor */
#if (SERDES_IP_PBCFG_VENDOR_ID != SERDES_IP_PBCFG_VENDOR_ID_C)
    #error "Serdes_Ip_PBCfg.c and Serdes_Ip_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_PBCfg.h file are of the same Autosar version */
#if ((SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C) || \
     (SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION != SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C) || \
     (SERDES_IP_PBCFG_AR_RELEASE_REVISION_VERSION != SERDES_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip_PBCfg.c and Serdes_Ip_PBCfg.h are different"
#endif
/* Check if current file and Serdes_Ip_PBCfg.h file are of the same Software version */
#if ((SERDES_IP_PBCFG_SW_MAJOR_VERSION_C != SERDES_IP_PBCFG_SW_MAJOR_VERSION) || \
     (SERDES_IP_PBCFG_SW_MINOR_VERSION_C != SERDES_IP_PBCFG_SW_MINOR_VERSION) || \
     (SERDES_IP_PBCFG_SW_PATCH_VERSION_C != SERDES_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip_PBCfg.c and Serdes_Ip_PBCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Autosar version */
    #if ((SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip_PBCfg.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define SERDES_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

[!NOCODE!][!//
[!LOOP "SerdesGlobalConfig/SerdesChannel/*"!] /* Loop through all configured channels */
[!CODE!]
[!IF "node:value(UseXpcs0) = 'true'"!]
/* XPCS0  configuration [!"SerdesHwChannel"!] */
static const Serdes_Ip_XpcsConfigType Xpcs0_Config[!"SerdesHwChannel"!] =
{
    /* Loopback */
    (boolean)[!"text:toupper(XPCS_0/SerdesLoopback_0)"!],

    /* Xpcs speed */
    [!"XPCS_0/XpcsSpeed0"!],

    /* Xpcs duplex */
    [!"XPCS_0/XpcsDuplex0"!],

    /* Xpcs autonegotiation */
    (boolean)[!"text:toupper(XPCS_0/XPCS0_AN)"!]
};
[!ENDIF!]

[!IF "node:value(UseXpcs1) = 'true'"!]
/* XPCS1  configuration [!"SerdesHwChannel"!] */
static const Serdes_Ip_XpcsConfigType Xpcs1_Config[!"SerdesHwChannel"!] =
{
    /* Loopback */
    (boolean)[!"text:toupper(XPCS_1/SerdesLoopback_1)"!],

    /* Xpcs speed */
    [!"XPCS_1/XpcsSpeed1"!],

     /* Xpcs duplex */
    [!"XPCS_1/XpcsDuplex1"!],

    /* Xpcs autonegotiation */
    (boolean)[!"text:toupper(XPCS_1/XPCS1_AN)"!]
};
[!ENDIF!]

/* Channel configuration for channel [!"SerdesHwChannel"!] */
const Serdes_Ip_ConfigType SerdesConfig[!"SerdesChannelId"!] =
{
    /* PHY clock */
    [!"SerdesPhyClock"!],

    /* Serdes clock */
    [!"SerdesClock"!],

    /* Serdes working mode */
    [!"SerdesMode"!],

    /* XPCS0 config */
    [!IF "node:value(UseXpcs0) = 'true'"!]&Xpcs0_Config[!"SerdesHwChannel"!][!ELSE!]NULL_PTR[!ENDIF!],

    /* XPCS1 config */
    [!IF "node:value(UseXpcs1) = 'true'"!]&Xpcs1_Config[!"SerdesHwChannel"!][!ELSE!]NULL_PTR[!ENDIF!]

};

[!ENDCODE!]
[!ENDLOOP!] /* End of the loop */

[!ENDNOCODE!][!//

#define SERDES_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
