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
#include "Mcal.h"
#include "Pcie_Ip.h"
#include "Pcie_Ip_PBCfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_IP_PBCFG_VENDOR_ID_C                     43
#define PCIE_IP_PBCFG_MODULE_ID_C                     255
#define PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define PCIE_IP_PBCFG_SW_MAJOR_VERSION_C              4
#define PCIE_IP_PBCFG_SW_MINOR_VERSION_C              0
#define PCIE_IP_PBCFG_SW_PATCH_VERSION_C              2


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pcie_Ip_PBCfg.c file and Mcal.h header file are of the same Autosar version */
    #if ((PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie_Ip_PBCfg.c and Mcal.h are different"
    #endif
#endif

/* Checks against Pcie_Ip_Cfg.h */
#if (PCIE_IP_PBCFG_VENDOR_ID_C != PCIE_IP_VENDOR_ID)
     #error "Pcie_Ip.h and Pcie_Ip_PBCfg.c have different vendor ids"
#endif
#if (PCIE_IP_PBCFG_MODULE_ID_C != PCIE_IP_MODULE_ID)
     #error "Pcie_Ip.h and Pcie_Ip_PBCfg.c have different module ids"
#endif
#if ((PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != PCIE_IP_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Pcie_Ip.h and Pcie_Ip_PBCfg.c are different"
#endif
#if ((PCIE_IP_PBCFG_SW_MAJOR_VERSION_C != PCIE_IP_SW_MAJOR_VERSION) || \
     (PCIE_IP_PBCFG_SW_MINOR_VERSION_C != PCIE_IP_SW_MINOR_VERSION) || \
     (PCIE_IP_PBCFG_SW_PATCH_VERSION_C != PCIE_IP_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pcie_Ip.h and Pcie_Ip_PBCfg.c are different"
#endif

/* Check if current file and Pcie_Ip_PBCfg.h file are of the same vendor */
#if (PCIE_IP_PBCFG_VENDOR_ID_C  != PCIE_IP_PBCFG_VENDOR_ID)
    #error "Pcie_Ip_PBCfg.c and Pcie_Ip_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip_PBCfg.h file are of the same Autosar version */
#if ((PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip_PBCfg.h and Pcie_Ip_PBCfg.c are different"
#endif
/* Check if current file and Pcie_Ip_PBCfg.h file are of the same Software version */
#if ((PCIE_IP_PBCFG_SW_MAJOR_VERSION_C != PCIE_IP_PBCFG_SW_MAJOR_VERSION) || \
     (PCIE_IP_PBCFG_SW_MINOR_VERSION_C != PCIE_IP_PBCFG_SW_MINOR_VERSION) || \
     (PCIE_IP_PBCFG_SW_PATCH_VERSION_C != PCIE_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip_PBCfg.h and Pcie_Ip_PBCfg.c are different"
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

[!NOCODE!][!//
[!LOOP "PcieGlobalConfig/PcieChannel/*"!] /* Loop through all configured channels */
[!CODE!][!//
[!INDENT "0"!][!//
#define PCIE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

/* Pcie configuration */
Pcie_Ip_ConfigType PcieConfig[!"PcieChannelId"!] =
{
    [!WS "4"!][!"PcieClass"!]U,                               /* PCIe class */
    [!WS "4"!]{    /* BARs configuration */
        [!WS "8"!]{
            [!WS "12"!](uint32)[!"BAR0Configuration/Bar0Size"!]U,
            [!IF "(BAR0Configuration/Bar0Type64Bit = 'false') and (BAR0Configuration/Bar0TypeIo = 'false') and (BAR0Configuration/Bar0TypePrefetchable = 'false')"!][!//
                [!WS "12"!](uint32)0U,
            [!ELSE!][!//
                [!VAR "BarCfgStart" = "'true'"!][!//
                [!VAR "BarCfgText" = "'('"!][!//
                [!IF "BAR0Configuration/Bar0Type64Bit"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_64BIT')"!][!//
                [!ENDIF!][!//
                [!IF "BAR0Configuration/Bar0TypeIo"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_IO')"!][!//
                [!ENDIF!][!//
                [!IF "BAR0Configuration/Bar0TypePrefetchable"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_PREFETCHABLE')"!][!//
                [!ENDIF!][!//
                [!VAR "BarCfgText" = "concat($BarCfgText, ')')"!][!//
                [!WS "12"!](uint32)[!"$BarCfgText"!],
            [!ENDIF!][!//
            [!IF "(BAR0Configuration/Bar0StartSymbol = '')"!][!//
            [!WS "12"!](uint8 (*)[1U])[!"BAR0Configuration/Bar0StartAddr"!]U,
            [!ELSE!][!//
            [!WS "12"!](uint8 (*)[1U])&([!"BAR0Configuration/Bar0StartSymbol"!]),
            [!ENDIF!][!//
        [!WS "8"!]},
        [!WS "8"!]{
        [!IF "node:exists(BAR1Configuration)"!][!//
            [!WS "12"!](uint32)[!"BAR1Configuration/Bar1Size"!]U,
            [!IF "(BAR1Configuration/Bar1TypeIo = 'false')"!][!//
                [!WS "12"!](uint32)0U,
            [!ELSE!][!//
                [!VAR "BarCfgStart" = "'true'"!][!//
                [!VAR "BarCfgText" = "'('"!][!//
                [!IF "BAR1Configuration/Bar1TypeIo"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_IO')"!][!//
                [!ENDIF!][!//
                [!VAR "BarCfgText" = "concat($BarCfgText, ')')"!][!//
                [!WS "12"!](uint32)[!"$BarCfgText"!],
            [!ENDIF!][!//
            [!IF "(BAR1Configuration/Bar1StartSymbol = '')"!][!//
            [!WS "12"!](uint8 (*)[1U])[!"BAR1Configuration/Bar1StartAddr"!]U,
            [!ELSE!][!//
            [!WS "12"!](uint8 (*)[1U])&([!"BAR1Configuration/Bar1StartSymbol"!]),
            [!ENDIF!][!//
        [!ELSE!][!//
            [!WS "12"!](uint32)0U,
            [!WS "12"!](uint32)0U,
            [!WS "12"!]NULL_PTR,
        [!ENDIF!][!//
        [!WS "8"!]},
        [!WS "8"!]{
            [!WS "12"!](uint32)[!IF "MsixEnabled"!]8192U[!ELSE!]0U[!ENDIF!],
            [!WS "12"!](uint32)0U,
            [!WS "12"!]NULL_PTR,
        [!WS "8"!]},
        [!WS "8"!]{
            [!WS "12"!](uint32)0U,
            [!WS "12"!](uint32)0U,
            [!WS "12"!]NULL_PTR,
        [!WS "8"!]},
        [!WS "8"!]{
            [!WS "12"!](uint32)[!"BAR4Configuration/Bar4Size"!]U,
            [!IF "(BAR4Configuration/Bar4Type64Bit = 'false') and (BAR4Configuration/Bar4TypeIo = 'false') and (BAR4Configuration/Bar4TypePrefetchable = 'false')"!][!//
                [!WS "12"!](uint32)0U,
            [!ELSE!][!//
                [!VAR "BarCfgStart" = "'true'"!][!//
                [!VAR "BarCfgText" = "'('"!][!//
                [!IF "BAR4Configuration/Bar4Type64Bit"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_64BIT')"!][!//
                [!ENDIF!][!//
                [!IF "BAR4Configuration/Bar4TypeIo"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_IO')"!][!//
                [!ENDIF!][!//
                [!IF "BAR4Configuration/Bar4TypePrefetchable"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_PREFETCHABLE')"!][!//
                [!ENDIF!][!//
                [!VAR "BarCfgText" = "concat($BarCfgText, ')')"!][!//
                [!WS "12"!](uint32)[!"$BarCfgText"!],
            [!ENDIF!][!//
            [!IF "(BAR4Configuration/Bar4StartSymbol = '')"!][!//
            [!WS "12"!](uint8 (*)[1U])[!"BAR4Configuration/Bar4StartAddr"!]U,
            [!ELSE!][!//
            [!WS "12"!](uint8 (*)[1U])&([!"BAR4Configuration/Bar4StartSymbol"!]),
            [!ENDIF!][!//
        [!WS "8"!]},
        [!WS "8"!]{
        [!IF "node:exists(BAR5Configuration)"!][!//
            [!WS "12"!](uint32)[!"BAR5Configuration/Bar5Size"!]U,
            [!IF "(BAR5Configuration/Bar5TypeIo = 'false')"!][!//
                [!WS "12"!](uint32)0U,
            [!ELSE!][!//
                [!VAR "BarCfgStart" = "'true'"!][!//
                [!VAR "BarCfgText" = "'('"!][!//
                [!IF "BAR5Configuration/Bar5TypeIo"!][!//
                    [!IF "$BarCfgStart"!][!//
                        [!VAR "BarCfgStart" = "'false'"!][!//
                    [!ELSE!][!//
                        [!VAR "BarCfgText" = "concat($BarCfgText, ' | ')"!][!//
                    [!ENDIF!][!//
                    [!VAR "BarCfgText" = "concat($BarCfgText, 'PCIE_IP_BAR_TYPE_IO')"!][!//
                [!ENDIF!][!//
                [!VAR "BarCfgText" = "concat($BarCfgText, ')')"!][!//
                [!WS "12"!](uint32)[!"$BarCfgText"!],
            [!ENDIF!][!//
            [!IF "(BAR5Configuration/Bar5StartSymbol = '')"!][!//
            [!WS "12"!](uint8 (*)[1U])[!"BAR5Configuration/Bar5StartAddr"!]U,
            [!ELSE!][!//
            [!WS "12"!](uint8 (*)[1U])&([!"BAR5Configuration/Bar5StartSymbol"!]),
            [!ENDIF!][!//
        [!ELSE!][!//
            [!WS "12"!](uint32)0U,
            [!WS "12"!](uint32)0U,
            [!WS "12"!]NULL_PTR,
        [!ENDIF!][!//
        [!WS "8"!]},
    [!WS "4"!]},
    [!WS "4"!](uint8)[!"MsiCount"!]U,                            /* msiCount */
    [!WS "4"!](boolean)[!"text:toupper(MsixEnabled)"!],          /* msixSupport */
    [!IF "node:exists(DmaReadDoneHandler)"!][!//
    [!WS "4"!][!"DmaReadDoneHandler"!],          /* dmaReadDoneHandler */
    [!ELSE!][!//
    [!WS "4"!]NULL_PTR,          /* dmaReadDoneHandler */
    [!ENDIF!][!//
    [!IF "node:exists(DmaReadErrorHandler)"!][!//
    [!WS "4"!][!"DmaReadErrorHandler"!],          /* dmaReadErrorHandler */
    [!ELSE!][!//
    [!WS "4"!]NULL_PTR,          /* dmaReadErrorHandler */
    [!ENDIF!][!//
    [!IF "node:exists(DmaWriteDoneHandler)"!][!//
    [!WS "4"!][!"DmaWriteDoneHandler"!],          /* dmaWriteDoneHandler */
    [!ELSE!][!//
    [!WS "4"!]NULL_PTR,          /* dmaWriteDoneHandler */
    [!ENDIF!][!//
    [!IF "node:exists(DmaWriteErrorHandler)"!][!//
    [!WS "4"!][!"DmaWriteErrorHandler"!],          /* dmaWriteErrorHandler */
    [!ELSE!][!//
    [!WS "4"!]NULL_PTR,          /* dmaWriteErrorHandler */
    [!ENDIF!][!//
};

#define PCIE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"
[!ENDINDENT!][!//
[!ENDCODE!]
[!ENDLOOP!] /* Loop through all configured channels */
[!ENDNOCODE!]

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
