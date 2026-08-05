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

#ifndef PCIE_IP_PBCFG_H
#define PCIE_IP_PBCFG_H


/**
*   @file
*
*   @addtogroup PCIE_DRIVER_CONFIGURATION Pcie Driver Configurations
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
#include "Pcie_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_IP_PBCFG_VENDOR_ID                     43
#define PCIE_IP_PBCFG_MODULE_ID                     255
#define PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION      4
#define PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define PCIE_IP_PBCFG_SW_MAJOR_VERSION              4
#define PCIE_IP_PBCFG_SW_MINOR_VERSION              0
#define PCIE_IP_PBCFG_SW_PATCH_VERSION              2


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pcie_Ip_Types.h header file are of the same vendor */
#if (PCIE_IP_PBCFG_MODULE_ID  != PCIE_IP_TYPES_MODULE_ID)
    #error "Pcie_Ip_PBCfg.h and Pcie_Ip_Types.h have different module ids"
#endif

/* Check if current file and Pcie_Ip_Types.h header file are of the same vendor */
#if (PCIE_IP_PBCFG_VENDOR_ID != PCIE_IP_TYPES_VENDOR_ID)
    #error "Pcie_Ip_PBCfg.h and Pcie_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip_Types.h header file are of the same Autosar version */
#if ((PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != PCIE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION != PCIE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION != PCIE_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip_PBCfg.h and Pcie_Ip_Types.h are different"
#endif
/* Check if current file and Pcie_Ip_Types.h header file are of the same Software version */
#if ((PCIE_IP_PBCFG_SW_MAJOR_VERSION != PCIE_IP_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IP_PBCFG_SW_MINOR_VERSION != PCIE_IP_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IP_PBCFG_SW_PATCH_VERSION != PCIE_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip_PBCfg.h and Pcie_Ip_Types.h are different"
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

[!NOCODE!][!//
[!LOOP "PcieGlobalConfig/PcieChannel/*"!] /* Loop through all configured channels */
[!CODE!]
[!INDENT "0"!][!//
#define PCIE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"
[!IF "(BAR0Configuration/Bar0StartSymbol != '') or (BAR1Configuration/Bar1StartSymbol != '') or (BAR4Configuration/Bar4StartSymbol != '') or (BAR5Configuration/Bar5StartSymbol != '')"!][!//
/* Declaration of BAR address symbols */
    [!IF "(BAR0Configuration/Bar0StartSymbol != '')"!][!//
    extern uint8 [!"BAR0Configuration/Bar0StartSymbol"!][];
    [!ENDIF!]
    [!IF "node:exists(BAR1Configuration)"!][!//
        [!IF "(BAR1Configuration/Bar1StartSymbol != '')"!][!//
        extern uint8 [!"BAR1Configuration/Bar1StartSymbol"!][];
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(BAR4Configuration/Bar4StartSymbol != '')"!][!//
    extern uint8 [!"BAR4Configuration/Bar4StartSymbol"!][];
    [!ENDIF!]
    [!IF "node:exists(BAR5Configuration)"!][!//
        [!IF "(BAR5Configuration/Bar5StartSymbol != '')"!][!//
        extern uint8 [!"BAR5Configuration/Bar5StartSymbol"!][];
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]

/* Channel configuration for channel [!"PcieHwChannel"!] */
extern Pcie_Ip_ConfigType PcieConfig[!"PcieChannelId"!];

#define PCIE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

[!ENDINDENT!][!//
[!ENDCODE!]
[!ENDLOOP!] /* End of the loop */

[!LOOP "PcieGlobalConfig/PcieChannel/*"!] /* Loop through all configured channels */
[!CODE!]
[!INDENT "0"!][!//

[!IF "node:exists(DmaReadDoneHandler) or node:exists(DmaReadErrorHandler) or node:exists(DmaWriteDoneHandler) or node:exists(DmaWriteErrorHandler)"!][!//
#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"
/* Declaration of DMA event handlers */
    [!IF "node:exists(DmaReadDoneHandler)"!][!//
    extern void [!"DmaReadDoneHandler"!](uint8 instance, uint8 channel, uint16 transferId);
    [!ENDIF!]
    [!IF "node:exists(DmaReadErrorHandler)"!][!//
    extern void [!"DmaReadErrorHandler"!](uint8 instance, uint8 channel);
    [!ENDIF!]
    [!IF "node:exists(DmaWriteDoneHandler)"!][!//
    extern void [!"DmaWriteDoneHandler"!](uint8 instance, uint8 channel, uint16 transferId);
    [!ENDIF!]
    [!IF "node:exists(DmaWriteErrorHandler)"!][!//
    extern void [!"DmaWriteErrorHandler"!](uint8 instance, uint8 channel);
    [!ENDIF!]
#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"
[!ENDIF!]

[!ENDINDENT!][!//
[!ENDCODE!]
[!ENDLOOP!] /* End of the loop */

[!ENDNOCODE!][!//


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PCIE_IP_PBCFG_H */
