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

#ifndef SERDES_IP_PBCFG_H
#define SERDES_IP_PBCFG_H


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
#include "Serdes_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_PBCFG_VENDOR_ID                     43
#define SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION      4
#define SERDES_IP_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define SERDES_IP_PBCFG_SW_MAJOR_VERSION              4
#define SERDES_IP_PBCFG_SW_MINOR_VERSION              0
#define SERDES_IP_PBCFG_SW_PATCH_VERSION              2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Serdes_Ip.h file are of the same vendor */
#if (SERDES_IP_PBCFG_VENDOR_ID != SERDES_IP_VENDOR_ID)
    #error "Serdes_Ip_PBCfg.h and Serdes_Ip.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Autosar version */
#if ((SERDES_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != SERDES_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_PBCFG_AR_RELEASE_MINOR_VERSION != SERDES_IP_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_PBCFG_AR_RELEASE_REVISION_VERSION != SERDES_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip_PBCfg.h and Serdes_Ip.h are different"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Software version */
#if ((SERDES_IP_PBCFG_SW_MAJOR_VERSION != SERDES_IP_SW_MAJOR_VERSION) || \
     (SERDES_IP_PBCFG_SW_MINOR_VERSION != SERDES_IP_SW_MINOR_VERSION) || \
     (SERDES_IP_PBCFG_SW_PATCH_VERSION != SERDES_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip_PBCfg.h and Serdes_Ip.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define SERDES_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

[!NOCODE!][!//
[!LOOP "SerdesGlobalConfig/SerdesChannel/*"!] /* Loop through all configured channels */
[!CODE!]

/* Channel configuration for channel [!"SerdesHwChannel"!] */
extern const Serdes_Ip_ConfigType SerdesConfig[!"SerdesChannelId"!];

[!ENDCODE!]
[!ENDLOOP!] /* End of the loop */

[!ENDNOCODE!][!//

#define SERDES_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SERDES_IP_PBCFG_H */
