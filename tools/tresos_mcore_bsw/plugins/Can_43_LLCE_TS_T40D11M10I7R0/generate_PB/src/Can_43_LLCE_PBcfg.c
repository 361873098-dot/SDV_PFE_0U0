/**
*   @file    Can_43_LLCE_PBcfg.c
*   @version 1.0.7
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PostBuild.
*
*   @addtogroup CAN_LLCE
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
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

#ifdef __cplusplus
extern "C"{
#endif

/*
   (CAN078) The code file structure shall not be defined within this specification completely.
            At this point it shall be pointed out that the code-file structure shall include the following file named: Can_43_LLCE_PBcfg.c.
            This file shall contain all post-build time configurable parameters.
   (CAN221) VariantPB: (Mix of precompile and Post Build multiple selectable configurable configurations.
*/
/**
* @file           Can_43_LLCE_PBcfg.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"

[!AUTOSPACING!]
[!//
[!NOCODE!][!//
[!INCLUDE "Can_43_LLCE_VersionCheck_Src_PB.m"!][!//
[!INCLUDE "Can_43_LLCE_Can_BaudRate_Inference.m"!][!//
[!INCLUDE "Can_43_LLCE_Macros.m"!][!//
[!ENDNOCODE!][!//
[!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_43_LLCE_PBcfg.c
*/
#define CAN_43_LLCE_VENDOR_ID_PBCFG_C                   43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PBCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PBCFG_C  0
#define CAN_SW_MAJOR_VERSION_PBCFG_C             1
#define CAN_SW_MINOR_VERSION_PBCFG_C             0
#define CAN_SW_PATCH_VERSION_PBCFG_C             7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PBCFG_C != CAN_43_LLCE_VENDOR_ID)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_43_LLCE_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_43_LLCE_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_43_LLCE_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PBCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_43_LLCE_PBcfg.c and Can_43_LLCE_IPW.h are different"
#endif

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Can_43_LLCE_MemMap.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!NOCODE!]
[!SELECT "CanConfigSet"!]
    [!VAR "CanEcucPartitionRefCount" = "num:i(count(./CanGeneral/CanEcucPartitionRef/*))"!]
    [!VAR "HOHCount" = "num:i(count(CanHardwareObject/*))"!]
    [!VAR "CustomProcessingFlag"="'false'"!]
    [!VAR "HRHcount" = "0"!]
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
            [!IF "(CanObjectType = 'RECEIVE')"!]
                [!VAR "HRHcount" = "$HRHcount + 1"!]
                [!IF "node:exists(CanAdvancedFeature)"!]
                    [!SELECT "node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)"!]
                        [!IF "CustomProcessingEnable = 'true'"!]
                            [!VAR "CustomProcessingFlag"="'true'"!]
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]

[!MACRO "GetCoreIdOfEcucPartition"!][!// Call with an CanEcucPartitionRef selected
    [!VAR "PartitionMatch" = "num:i(0)"!]
    [!VAR "CanEcucPartitionPath" = "node:value(.)"!]
    [!VAR "CanEcucPartitionName" = "substring-after(substring-after($CanEcucPartitionPath, 'EcuC/EcuC/'), '/')"!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
        [!IF "contains(node:value(./OsAppEcucPartitionRef), $CanEcucPartitionName)"!]
            [!VAR "CoreID" = "node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
            [!VAR "PartitionMatch" = "num:i(1)"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$PartitionMatch = 1"!]    
        [!CODE!][!WS "4"!](uint32)[!"$CoreID"!]U /* Core ID */[!ENDCODE!]
    [!ELSE!]
        [!CODE!][!WS "4"!](uint32)0xFFFFFFFFU /* No core defined for selected partition */[!ENDCODE!]
    [!ENDIF!]        
[!ENDMACRO!]    
[!ENDNOCODE!]

[!CALL "CountFilters"!]
[!FOR "i" = "0" TO "15"!] 
    [!IF "text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($i+1)] > 0"!]
        [!WS "0"!]#define LLCE_CTRL_[!"num:i($i)"!]_MAX_RX_FILTERS      [!"num:i(text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($i+1)])"!]
    [!ENDIF!]
    [!IF "text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($i+1)] > 0"!]
        [!WS "0"!]#define LLCE_CTRL_[!"num:i($i)"!]_MAX_RXAF_FILTERS    [!"num:i(text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($i+1)])"!]
    [!ENDIF!]
[!ENDFOR!]

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
[!IF "$CustomProcessingFlag='true'"!]
VAR_ALIGN( static const uint32 CanFilterId2CustomIdx[[!"num:i($HRHcount)"!]], 32U)
[!ENDIF!]

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================*/
/**
* @brief        Configuration parameters of the entire platform.
* @details      Config parameters needed for init platform command. E.g:
*               Maximum number of filters requested to be supported by filtering hardware. It is used to generate the data structures used for tracking used hardware filters.
*               Maximum number of RX hardware objects (for interrupt mode) of each channel needed to be reserved for RX buffering mechanism.
*               Maximum number of RX hardware objects of each polling class needed to be reserved for RX buffering mechanism.
*               Maximum number of TX confirmation buffers (for interrupt mode) of each channel needed to be reserved for TX confirmations buffering mechanism.
*               Maximum number of TX confirmation buffers of each polling class needed to be reserved for TX confirmations buffering mechanism.
*
*/
/*==================================================================================================*/
[!VAR "CanEcucPartitionRefCount" = "num:i(count(CanGeneral/CanEcucPartitionRef/*))"!]
[!IF "$CanEcucPartitionRefCount = 0"!][!// No CAN EcucPartition References
static const Llce_Can_InitPlatformCmdType PlatformInitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{   
[!CALL "GeneratePlatformInit"!]
};
[!ELSE!][!//
    [!LOOP "CanGeneral/CanEcucPartitionRef/*"!]
        [!VAR "crtEcucPartitionPath" = "node:value(.)"!]
        [!VAR "CanEcucPartitionName" = "substring-after(substring-after($crtEcucPartitionPath, 'EcuC/EcuC/'), '/')"!]
static const Llce_Can_InitPlatformCmdType PlatformInitConfig_[!"$CanEcucPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{   
        [!SELECT "../../.."!]
[!CALL "GeneratePlatformInit", "CanEcuCPartitionPath" = "$crtEcucPartitionPath"!]
};
        [!ENDSELECT!]

    [!ENDLOOP!]
[!ENDIF!]

/*==================================================================================================*/
/**
* @brief          Arrays of filters for LLCE
* @details        Lists of regular and advanced reception filters to be sent to LLCE, grouped by controller
*
*/
/*==================================================================================================*/
[!SELECT "CanConfigSet"!]
[!FOR "crtCtrl" = "0" TO "15"!] 
[!IF "text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
 [!WS "0"!]static Llce_Can_ReceiveFilterType Llce_Rx_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [ LLCE_CTRL_[!"num:i($crtCtrl)"!]_MAX_RX_FILTERS ] =
 [!VAR "crtFilter" = "0"!]
{   
[!INDENT "2"!]     
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
        [!IF "(node:ref(CanControllerRef)/CanControllerActivation = 'true') and (CanObjectType = 'RECEIVE') and (substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = num:i($crtCtrl)) and not(node:exists(CanAdvancedFeature))"!]
            [!IF "$crtFilter > 0"!],
            [!ENDIF!]
            { /* Regular filter [!"num:i($crtFilter)"!] for BCAN_[!"num:i($crtCtrl)"!] */
            [!CALL "GenerateFilterConfig"!]
            }[!//
            [!VAR "crtFilter" = "$crtFilter+1"!]
         [!ENDIF!]
    [!ENDLOOP!]
[!ENDINDENT!]

};
[!ENDIF!]
[!ENDFOR!]

/* List of regular filter arrays */
[!IF "$CanEcucPartitionRefCount = 0"!][!// No CAN EcucPartition References - dump filter count list
static Llce_Can_ReceiveFilterType * Llce_Rx_Filters_List[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{ 
    [!FOR "crtCtrl" = "0" TO "15"!] 
        [!IF "$crtCtrl > 0"!],
        [!ENDIF!]
        [!IF "text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
    Llce_Rx_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
        [!ELSE!][!//
    NULL_PTR /* No regular filters for channel [!"$crtCtrl"!] */[!//
        [!ENDIF!]
    [!ENDFOR!]

};
[!ELSE!][!//
    [!LOOP "../CanGeneral/CanEcucPartitionRef/*"!]
        [!VAR "crtEcucPartitionPath" = "node:value(.)"!]
        [!VAR "CanEcucPartitionName" = "substring-after(substring-after($crtEcucPartitionPath, 'EcuC/EcuC/'), '/')"!]
static Llce_Can_ReceiveFilterType * Llce_Rx_Filters_List_[!"$CanEcucPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{ 
        [!FOR "crtCtrl" = "0" TO "15"!][!//
            [!IF "$crtCtrl > 0"!],
            [!ENDIF!][!//
                [!IF "text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!][!//
                        [!LOOP "node:order(../../../CanConfigSet/CanController/*,'node:value(CanControllerId)')"!][!//
                            [!IF "substring-after(./CanHwChannel,'BCAN_') = $crtCtrl"!][!//
                                [!IF "node:exists(./CanControllerEcucPartitionRef) and (node:value(./CanControllerEcucPartitionRef) = $crtEcucPartitionPath)"!][!//
    Llce_Rx_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
                                [!ELSE!][!//
    NULL_PTR /* Channel [!"$crtCtrl"!] not in current partition*/[!//
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                [!ELSE!][!//
    NULL_PTR /* No regular filters for channel [!"$crtCtrl"!] */[!//
                [!ENDIF!]
        [!ENDFOR!]

};

    [!ENDLOOP!]
[!ENDIF!]
   
[!FOR "crtCtrl" = "0" TO "15"!] 
[!IF "text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
 [!WS "0"!]static Llce_Can_AdvancedFilterType Llce_RxAf_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [ LLCE_CTRL_[!"num:i($crtCtrl)"!]_MAX_RXAF_FILTERS ] =
 [!VAR "crtFilter" = "0"!]
 {   
        [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
            [!IF "(node:ref(CanControllerRef)/CanControllerActivation = 'true') and (CanObjectType = 'RECEIVE') and (substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = num:i($crtCtrl)) and node:exists(CanAdvancedFeature)"!]
              [!IF "$crtFilter > 0"!],
              [!ENDIF!]
              [!CALL "GenerateAdvancedFilterConfig"!]
              [!VAR "crtFilter" = "$crtFilter+1"!]
            [!ENDIF!]
        [!ENDLOOP!]

 };

[!ENDIF!]
[!ENDFOR!]

[!IF "$CanEcucPartitionRefCount = 0"!][!// No CAN EcucPartition References - dump filter count list
static Llce_Can_AdvancedFilterType * Llce_RxAf_Filters_List[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{ 
    [!FOR "crtCtrl" = "0" TO "15"!] 
        [!IF "$crtCtrl > 0"!],
        [!ENDIF!]
        [!IF "text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
    Llce_RxAf_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
        [!ELSE!][!//
    NULL_PTR /* No advanced filters for channel [!"$crtCtrl"!] */[!//
        [!ENDIF!]
    [!ENDFOR!]

};
[!ELSE!][!//
    [!LOOP "../CanGeneral/CanEcucPartitionRef/*"!]
        [!VAR "crtEcucPartitionPath" = "node:value(.)"!]
        [!VAR "CanEcucPartitionName" = "substring-after(substring-after($crtEcucPartitionPath, 'EcuC/EcuC/'), '/')"!]
static Llce_Can_AdvancedFilterType * Llce_RxAf_Filters_List_[!"$CanEcucPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{ 
        [!FOR "crtCtrl" = "0" TO "15"!][!//
            [!IF "$crtCtrl > 0"!],
            [!ENDIF!][!//
                [!IF "text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!][!//
                        [!LOOP "node:order(../../../CanConfigSet/CanController/*,'node:value(CanControllerId)')"!][!//
                            [!IF "substring-after(./CanHwChannel,'BCAN_') = $crtCtrl"!][!//
                                [!IF "node:exists(./CanControllerEcucPartitionRef) and (node:value(./CanControllerEcucPartitionRef) = $crtEcucPartitionPath)"!][!//
    Llce_RxAf_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
                                [!ELSE!][!//
    NULL_PTR /* Channel [!"$crtCtrl"!] not in current partition*/[!//
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                [!ELSE!][!//
    NULL_PTR /* No advanced filters for channel [!"$crtCtrl"!] */[!//
                [!ENDIF!]
        [!ENDFOR!]

};

    [!ENDLOOP!]
[!ENDIF!]

[!ENDSELECT!]    
/*==================================================================================================*/
/**
* @brief          Information about hardware objects.
* @details        (CAN100)Several TX hardware objects with unique HTHs may be configured. The CanIf module provides the HTH as parameter of the TX request. See Figure 7-2 for a possible configuration.
*
*/
/*==================================================================================================*/

[!SELECT "CanConfigSet"!]
    [!VAR "MAX_RX_LONGMB_COUNT" = "num:i(0)"!]
    [!VAR "MAX_RX_SHORTMB_COUNT" = "num:i(0)"!]
    [!VAR "MAX_TXMB_COUNT" = "num:i(0)"!]
    [!WS "0"!]static const Can_43_LLCE_HOHType MessageBufferConfigs_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CAN_43_LLCE_MAXHOH_CONFIGURED] =
    [!WS "0"!]{
    [!VAR "END_COMMA"="0"!]
    [!VAR "MASK_COUNT"="num:i(count(CanHardwareObject/*))"!]
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
        [!VAR "END_COMMA"="$END_COMMA + 1"!]
                [!WS "4"!]/* [!"@name"!] Message Buffer [!"@index"!] on Can Controller [!"num:i(node:ref(CanControllerRef)/CanControllerId)"!] */
                [!WS "4"!]{
                [!INDENT "8"!]
                [!IF "CanObjectType = 'RECEIVE'"!]
                    [!IF "node:exists(CanAdvancedFeature/CanAdvancedFeatureRef)"!]
                        CAN_43_LLCE_RECEIVE_AF, /* Object Type */
                    [!ELSE!]        
                        CAN_43_LLCE_RECEIVE,  /* Object Type */
                    [!ENDIF!]
                    [!IF "node:exists('CanObjectPayloadLength') and (CanObjectPayloadLength='CAN_OBJECT_PL_8')"!]
                        [!VAR "MAX_RX_SHORTMB_COUNT"="num:i($MAX_RX_SHORTMB_COUNT) + num:i(CanHwObjectCount)"!]
                    [!ELSE!]
                        [!VAR "MAX_RX_LONGMB_COUNT"="num:i($MAX_RX_LONGMB_COUNT) + num:i(CanHwObjectCount)"!]
                    [!ENDIF!]

                [!ELSE!]
                        CAN_43_LLCE_TRANSMIT,  /* Object Type */
                    [!VAR "MAX_TXMB_COUNT"="num:i($MAX_TXMB_COUNT) + num:i(CanHwObjectCount)"!]
                [!ENDIF!]
                [!IF " (node:exists(CanHwObjectCount))"!]
                    (uint16)[!"num:inttohex(CanHwObjectCount)"!], /* MBCount */
                [!ELSE!]
                    (uint16)1U, /* MBCount */
                [!ENDIF!]
                    (uint8)[!"num:i(node:ref(CanControllerRef)/CanControllerId)"!]U, /* ControllerId  - based on the order from CanController list */
                [!IF " (node:exists(CanFdPaddingValue)) and (node:exists(../../../CanConfigSet/CanController/*/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig)) and (node:fallback(CanObjectType,'TRANSMIT') = 'TRANSMIT')"!]
                    (uint8)[!"num:inttohex(CanFdPaddingValue)"!], /**< @brief Padding value for MB > 8 bytes */
                [!ELSE!]
                    (uint8)0U, /**< @brief Padding value for MB > 8 bytes */
                [!ENDIF!]
                [!IF "CanObjectType = 'TRANSMIT'"!]
                    /* Read/Write period reference used when polling mode is selected for this HTH */
                    [!IF "node:refexists(CanMainFunctionRWPeriodRef) and (((node:ref(CanControllerRef)/CanTxProcessing = 'MIXED') and (CanHardwareObjectUsesPolling = 'true')) or (((node:ref(CanControllerRef)/CanTxProcessing = 'POLLING'))))"!]
                        [!SELECT "node:ref(CanMainFunctionRWPeriodRef)"!]
                            (uint8)[!"@index"!]U,    /* HTH reference is from [!"node:name(.)"!]. */
                            (uint8)[!"num:i(AckInterface)"!],   /* Ack reported through this interface . */
                        [!ENDSELECT!]
                    [!ELSE!]
                        LLCE_CAN_REFERENCE_NOT_USED,   /* HTH configured for interrupt mode, reference not used.*/
                        [!WS "8"!][!CALL "GetRWDestInterfaceFromHOH"!], /* Ack is reported through this interface . */
                    [!ENDIF!][!//
                    [!IF "CanTxAddFrameMac = 'true'"!]
                        TRUE, /* Add MAC code and Key Handle for all frames transmitted using this HTH. */
                        (uint32)[!"num:inttohex(CanLlceKeyHandle)"!],
                    [!ELSE!]
                        FALSE, /* Add no MAC code for frames transmitted using this HTH. */
                        0u,    /* No key handler required if no MAC code is requested */
                    [!ENDIF!][!//
                [!ELSE!] [!// Receive object
                    [!IF "node:refexists(CanMainFunctionRWPeriodRef) and (((node:ref(CanControllerRef)/CanRxProcessing = 'MIXED') and (CanHardwareObjectUsesPolling = 'true')) or (((node:ref(CanControllerRef)/CanRxProcessing = 'POLLING'))))"!]
                        [!SELECT "node:ref(CanMainFunctionRWPeriodRef)"!]
                            (uint8)[!"@index"!]U,    /* HRH reference is from [!"node:name(.)"!] */
                            (uint8)[!"num:i(RxInterface)"!],   /* Rx is reported through this interface. */
                        [!ENDSELECT!]
                    [!ELSE!]
                        LLCE_CAN_REFERENCE_NOT_USED,   /* HRH configured for interrupt mode, reference not used. */
                        [!WS "2"!][!CALL "GetRWDestInterfaceFromHOH"!], /* Rx is reported through this interface . */
                    [!ENDIF!][!//
                    FALSE, /* Adding MAC code and key handler do not apply for receiving HRH. */
                    0u,
                [!ENDIF!][!//
                [!IF "(node:exists(CanTriggerTransmitEnable)) and (node:value(CanTriggerTransmitEnable) ='true')"!]
                    #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
                    (boolean)TRUE, /* Trigger Transmit enabled */
                    #endif
                [!ELSE!]
                    #if (CAN_43_LLCE_TRIGGER_TRANSMIT_EN == STD_ON)
                    (boolean)FALSE, /* Trigger Transmit disabled */
                    #endif
                [!ENDIF!]
                [!IF "(node:exists(Dummy_HRH)) and (node:value(Dummy_HRH) ='true')"!]
                    #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
                    (boolean)TRUE /* Dummy HRH enabled */
                    #endif
                [!ELSE!]
                    #if (CAN_43_LLCE_DUMMY_HRH_EN == STD_ON)
                    (boolean)FALSE /* Dummy HRH disabled */
                    #endif
                [!ENDIF!]
                [!ENDINDENT!]
                [!WS "4"!]}[!CR!]
        [!IF "$END_COMMA < $MASK_COUNT"!][!//
            [!WS "0"!],
        [!ENDIF!]
        [!CR!]
    [!ENDLOOP!]
    [!WS "0"!]};
    [!IF "num:i($MAX_TXMB_COUNT) > 256"!][!//
        [!ERROR!]The hardware platform does not include enough message buffers in order to service all configured HTHs. Please decrease the number of HTHs and/or the number of MB used by each HTHs.[!ENDERROR!]
    [!ENDIF!]
    [!IF "num:i($MAX_RX_LONGMB_COUNT) > 1700"!][!//
        [!ERROR!]The hardware platform does not include enough long (64B) message buffers in order to service all configured HRHs. Please decrease the number of HRHs and/or the number of long MB used by each HRHs.[!ENDERROR!]
    [!ENDIF!]
    [!IF "num:i($MAX_RX_SHORTMB_COUNT) > 2396"!][!//
        [!ERROR!]The hardware platform does not include enough short (8B) message buffers in order to service all configured HRHs. Please decrease the number of HRHs and/or the number of short MB used by each HRHs.[!ENDERROR!]
    [!ENDIF!]
[!ENDSELECT!]

/*==================================================================================================*/
/**
* @brief          Configuration of Bcan controller
* @details        Configuration of Bcan controller
*
*/
[!SELECT "CanConfigSet"!]
    [!INDENT "0"!]
    [!VAR "CONFIGURED_CONTROLLERS_COUNT" = "num:i(0)"!]
    [!LOOP "CanController/*"!]
        [!IF "CanControllerActivation = 'true'"!]
            [!VAR "CONFIGURED_CONTROLLERS_COUNT"="num:i($CONFIGURED_CONTROLLERS_COUNT) + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!LOOP "CanController/*"!]
        [!VAR "CanClockSrc"="0"!]
        [!IF "(node:exists(./CanCpuClockRef)) = 'true'"!]
            [!VAR "CanClockSrc" = "node:ref(./CanCpuClockRef)/McuClockReferencePointFrequency"!]
        [!ELSE!]
            [!VAR "CanClockSrc" = "num:i(40000000)"!] [!/* Default Can Clock value 40 Mhz */!]
        [!ENDIF!]
        [!VAR "MASK_COUNT2"="num:i(count(CanControllerBaudrateConfig/*))"!]
        [!VAR "END_COMMA2"="0"!]
        static const Can_43_LLCE_ControllerBaudrateConfigType ControllerBaudrateCfgSet_PB_[!"CanControllerId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CAN_43_LLCE_MAX_BAUDRATE_FC_[!"substring-after(CanHwChannel,'BCAN_')"!]_[!"@index"!]] =
        {
        [!LOOP "CanControllerBaudrateConfig/*"!]
            [!WS "4"!]{
            [!CALL "GenerateBaudrate"!]
            #if (CAN_43_LLCE_SET_BAUDRATE_API == STD_ON)
            [!WS "8"!](uint16)[!"CanControllerBaudRateConfigID"!]
            #endif
            [!WS "4"!]}
            [!VAR "END_COMMA2"="$END_COMMA2 + 1"!]
            [!IF "$END_COMMA2 < $MASK_COUNT2"!]
                ,
            [!ENDIF!]
            [!CR!]
        [!ENDLOOP!]
        };
    [!ENDLOOP!]
    [!ENDINDENT!]
[!ENDSELECT!]

/*==================================================================================================*/
/**
* @brief          LLCE Per-channel Init 
* @details        Information needed to initialize each LLCE channel
*
*/

[!IF "$CanEcucPartitionRefCount = 0"!][!// No CAN EcucPartition References
static const Llce_Can_InitCmdType ControllerInit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
{
[!CALL "GenerateChannelInit"!]
};
[!ELSE!][!//
    [!LOOP "CanGeneral/CanEcucPartitionRef/*"!]
        [!VAR "crtEcucPartitionPath" = "node:value(.)"!]
        [!VAR "CanEcucPartitionName" = "substring-after(substring-after($crtEcucPartitionPath, 'EcuC/EcuC/'), '/')"!]
static const Llce_Can_InitCmdType ControllerInit_[!"$CanEcucPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
{   
        [!SELECT "../../.."!]
[!CALL "GenerateChannelInit", "CanEcuCPartitionPath" = "$crtEcucPartitionPath"!]
};
        [!ENDSELECT!]

    [!ENDLOOP!]
[!ENDIF!]

/*==================================================================================================*/
/**
* @brief          Description of individual Bcan controllers on chip
* @details        Description of individual Bcan controllers on chip
*
*/

[!SELECT "CanConfigSet"!]
    [!WS "0"!]static const Can_43_LLCE_ControllerDescriptorType ControllerDescriptors_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CAN_43_LLCE_MAXCTRL_CONFIGURED] =
    [!WS "0"!]{
    [!VAR "MASK_COUNT4"="num:i(count(CanController/*))"!]
    [!VAR "END_COMMA4"="0"!]
    [!VAR "CanGeneralPath" = "as:path(../CanGeneral, true())"!]
    [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!]
        [!WS "4"!]/* ControllerDescriptor of CanController_[!"node:value(CanControllerId)"!]*/
        [!WS "4"!]{
                    [!INDENT "8"!]
                    [!IF "CanControllerActivation = 'true'"!]
                        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
                        (uint8)[!"num:i(count(CanControllerBaudrateConfig/*))"!]U,
                        [!IF "not(contains(node:path(node:ref(CanControllerDefaultBaudrate)),node:path(CanControllerBaudrateConfig)))"!]
                            [!ERROR!]
                                Please select CanControllerDefaultBaudrate from the "[!"substring-after(node:path(CanControllerBaudrateConfig),'ELEMENTS/')"!]" container.
                            [!ENDERROR!]
                        [!ENDIF!]
                        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
                        (uint8)[!"num:i(node:ref(CanControllerDefaultBaudrate)/@index)"!]U,
                        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
                        ControllerBaudrateCfgSet_PB_[!"CanControllerId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
                        /* u32CoreId */ 
                        [!IF "node:exists(./CanControllerEcucPartitionRef)"!]
                            [!SELECT "./CanControllerEcucPartitionRef"!]
                            [!CALL "GetCoreIdOfEcucPartition"!],[!CR!]
                            [!ENDSELECT!] 
                        [!ELSE!]        
                            0xFFFFFFFFU, /* No partition selected */
                        [!ENDIF!]
                        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
                        (uint8)[!"substring-after(CanHwChannel,'BCAN_')"!]
                    [!ELSE!]
                        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
                        (uint8)0U,
                        /* Default BaudRate configured for current controller */
                        (uint8)0U,
                        /* pControllerBaudrateConfigsPtr */
                        ControllerBaudrateCfgSet_PB_[!"CanControllerId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
                        /* u32CoreId */ 
                        [!IF "node:exists(./CanControllerEcucPartitionRef)"!]
                            [!SELECT "./CanControllerEcucPartitionRef"!]
                            [!CALL "GetCoreIdOfEcucPartition"!],[!CR!]
                            [!ENDSELECT!] 
                        [!ELSE!]        
                            0xFFFFFFFFU, /* No partition selected */
                        [!ENDIF!]
                        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
                        (uint8)LLCE_NULL_OFFSET_U8
                    [!ENDIF!]
                   [!ENDINDENT!]
        [!WS "4"!]}[!//
        [!VAR "END_COMMA4"="$END_COMMA4 + 1"!][!//
        [!IF "$END_COMMA4 < $MASK_COUNT4"!][!//
            [!WS "0"!], /* ControllerDescriptors CanController_[!"node:value(CanControllerId)"!] end */
        [!ENDIF!]
        [!CR!]
    [!ENDLOOP!]
    [!WS "0"!]};
[!ENDSELECT!]


[!SELECT "CanConfigSet"!]
    [!WS "0"!]static const Can_43_LLCE_HwControllerDescriptorType HwControllerDescriptors_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
    [!WS "0"!]{
    [!VAR "MASK_COUNT4"="15"!]
    [!VAR "END_COMMA4"="0"!]
    [!VAR "CanGeneralPath" = "as:path(../CanGeneral, true())"!]
    [!FOR "i" = "0" TO "$MASK_COUNT4"!][!//
        [!VAR "HwObjFound"="'false'"!]
        [!WS "4"!]/* ControllerDescriptor of HwCanController_[!"$i"!]*/
        [!WS "4"!]{
        [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!][!//
            [!IF "substring-after(./CanHwChannel,'BCAN_') = $i "!]
                            [!INDENT "8"!]
                            [!IF "CanControllerActivation = 'true'"!]
                                /* ===== Controller Options for the driver ===== */
                                (uint32)(
                                [!IF "CanRxProcessing = 'INTERRUPT' or CanRxProcessing = 'MIXED'"!]
                                    LLCE_CAN_CONTROLLERCONFIG_RXINT_EN_U32 | /* Rx select by interrupt */
                                [!ELSE!]
                                    /* RxPoll Enabled */
                                [!ENDIF!]
                                [!IF "CanTxProcessing = 'INTERRUPT' or CanTxProcessing = 'MIXED'"!]
                                    LLCE_CAN_CONTROLLERCONFIG_TXINT_EN_U32 | /* Tx select by interrupt */
                                [!ELSE!]
                                    /* TxPoll Enabled */
                                [!ENDIF!]
                                [!IF "CanBusoffProcessing = 'INTERRUPT'"!]
                                    LLCE_CAN_CONTROLLERCONFIG_BOINT_EN_U32 | /* BusOff select by interrupt */
                                [!ELSE!]
                                    /* BusOffPoll Enabled */
                                [!ENDIF!]
                                    0U [!/*dummy value, to avoid checks for '|' on each macro definition*/!]
                                ),
                                /* Can Controller ID in CanIf */
                                [!VAR "CanControllerPath" = "as:path(., true())"!]
                                [!VAR "AbstCanIfControllerID" = "0"!]
                                [!SELECT "as:modconf('CanIf')[1]"!]
                                    [!VAR "CanCanIfMatchCounter" = "0"!]
                                    [!LOOP "./CanIfCtrlDrvCfg/*"!]
                                        [!IF "node:value(./CanIfCtrlDrvNameRef) = $CanGeneralPath"!]
                                            [!VAR "CanCanIfMatchCounter" = "$CanCanIfMatchCounter + 1"!]
                                        [!ENDIF!]
                                        [!IF "$CanCanIfMatchCounter = 1"!]
                                            [!LOOP "./CanIfCtrlCfg/*"!]
                                                [!IF "node:value(./CanIfCtrlCanCtrlRef) = $CanControllerPath"!]
                                                    [!VAR "AbstCanIfControllerID" = "node:value(./CanIfCtrlId)"!]
                                                [!ENDIF!]
                                            [!ENDLOOP!]
                                        [!ENDIF!]
                                    [!ENDLOOP!]
                                [!ENDSELECT!]
                                    (uint8)[!"num:i($AbstCanIfControllerID)"!]U,
                                    [!CALL "GetRWDestInterfaceFromCtrl"!] /**< LLCE FIFO Interface used for interrupt processing */
                            [!ELSE!]
                                /* ===== Controller Options for the driver ===== */
                                (uint32)(0U),
                                /* Can Controller ID in CanIf */
                                (uint8)LLCE_NULL_OFFSET_U8,
                                /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
                                (uint8)LLCE_NULL_OFFSET_U8
                            [!ENDIF!]
                            [!VAR "HwObjFound"="'true'"!]
                            [!BREAK!]
                        [!ENDINDENT!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$HwObjFound = 'false'"!][!//
            /* ===== Controller Options for the driver ===== */
            (uint32)(0U),
            /* Can Controller ID in CanIf */
            (uint8)LLCE_NULL_OFFSET_U8,
            /**< LLCE FIFO Interface ID used for interrupt processing of RX/ACK events. */
            (uint8)LLCE_NULL_OFFSET_U8
        [!ENDIF!]
        [!WS "4"!]}[!//
        [!IF "$i < $MASK_COUNT4"!][!//
            [!WS "0"!], /* ControllerDescriptors HwCanController_[!"$i"!] end */
        [!ENDIF!]
        [!CR!]
    [!ENDFOR!]
    [!WS "0"!]};
[!ENDSELECT!]


[!SELECT "CanConfigSet"!]
[!IF "$CustomProcessingFlag='true'"!]
static const uint32 CanFilterId2CustomIdx[[!"num:i($HRHcount)"!]] =
{
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
        [!IF "(CanObjectType = 'RECEIVE')"!]
            [!IF "node:exists(CanAdvancedFeature)"!]
                [!SELECT "node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)"!]
                    [!IF "CustomProcessingEnable = 'true'"!]
                        [!WS "4"!](uint32)[!"num:i(CustomProcessingIndex)"!]U,
                    [!ELSE!]
                        [!WS "4"!](uint32)0U, /* No custom index attached */
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ELSE!]
                [!WS "4"!](uint32)0U, /* No custom index attached */
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
};
[!ENDIF!]
[!//
[!//
[!IF "node:exists(../CanGeneral/CanAuxFilterEnable)"!]
[!IF "node:value(../CanGeneral/CanAuxFilterEnable) = 'true'"!]
[!FOR "ctrl" = "0" TO "15"!] 
    [!IF "text:split($GLOBAL_AUX_RX_FILTERCOUNT_LIST)[num:i($ctrl+1)] > 0"!]
        [!VAR "comma_count" = "text:split($GLOBAL_AUX_RX_FILTERCOUNT_LIST)[num:i($ctrl+1)]"!]
        [!VAR "filter_count" = "num:i(0)"!]
        [!WS "0"!]static Llce_Can_AuxFilterType Llce_AuxRx_Filters_Ctrl[!"$ctrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [[!"text:split($GLOBAL_AUX_RX_FILTERCOUNT_LIST)[num:i($ctrl+1)]"!]] =
        [!WS "0"!]{
        [!LOOP "CanAuxFilter/*"!]
            [!IF "substring-after(node:ref(./CanControllerRef)/CanHwChannel,'BCAN_') = $ctrl"!]
                [!WS "2"!]{ /* Auxilliary filter [!"num:i($filter_count)"!] for BCAN_[!"$ctrl"!] */
                    [!INDENT "4"!] 
                    [!VAR "filter_count" = "$filter_count + num:i(1)"!]
                    [!IF "Filter_Type = 'RANGE'"!]
                        [!IF "num:i(./RangeEnd) > 2047"!]
                            (Can_IdType)([!"num:i(./RangeEnd)"!]U | LLCE_CAN_MB_IDE_U32), /* uIdMask = RangeEnd */
                        [!ELSE!]
                            (Can_IdType)[!"num:i(./RangeEnd)"!], /* uIdMask = RangeEnd */
                        [!ENDIF!]
                        [!IF "num:i(./RangeStart) > 2047"!]
                            (Can_IdType)([!"num:i(./RangeStart)"!]U | LLCE_CAN_MB_IDE_U32), /* MessageId = RangeStart*/
                        [!ELSE!]
                            (Can_IdType)[!"num:i(./RangeStart)"!], /* MessageId = RangeStart */
                        [!ENDIF!]                
                    [!ELSE!]
                        [!IF "(Filter_Type = 'EXACT_MATCH')"!]
                            (Can_IdType)((CAN_43_LLCE_MAX_IDMASK 
                        [!ELSE!]
                            (Can_IdType)((([!"num:inttohex(./CanHwFilterMask)"!]U & CAN_43_LLCE_MAX_IDMASK) [!//
                        [!ENDIF!][!//
                        | LLCE_CAN_MB_RTR_U32)[!//
                        [!IF "CanIdType != 'MIXED'"!] |[!WS "1"!] [!ELSE!] & ~[!ENDIF!] LLCE_CAN_MB_IDE_U32),  /* uIdMask */
                            (Can_IdType)(([!"num:inttohex(./CanHwFilterCode)"!]U & CAN_43_LLCE_MAX_IDMASK)[!IF "CanIdType = 'EXTENDED'"!] | LLCE_CAN_MB_IDE_U32[!ENDIF!]),   /* MessageId */
                    [!ENDIF!]
                    (uint16_t)[!"num:inttohex(./AuxSearchResult)"!], /* Auxilliary Search Result */
                    [!IF "Filter_Type = 'RANGE'"!]
                        LLCE_CAN_ENTRY_CFG_RANGED  /* Filter type */
                    [!ELSE!] 
                        [!IF "Filter_Type = 'MASK'"!]
                            LLCE_CAN_ENTRY_CFG_MASKED  /* Filter type */
                        [!ELSE!]
                            LLCE_CAN_ENTRY_EXACT_MATCH  /* Filter type */
                        [!ENDIF!] 
                    [!ENDIF!]
                    [!ENDINDENT!]
                    [!WS "2"!]}[!//
                    [!IF "num:i($comma_count) > 1"!],
                    [!ELSE!]

                    [!ENDIF!] 
                    [!VAR "comma_count" = "$comma_count - num:i(1)"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!WS "0"!]};

    [!ENDIF!]
[!ENDFOR!]

[!VAR "AUX_FILTERS_COUNT" = "num:i(count(CanAuxFilter/*))"!]
[!IF "$AUX_FILTERS_COUNT != num:i(0)"!]
/* Array containing maximum number of auxilliary filters per hardware controller */
static uint16 Llce_MaxAuxilliaryFilterCount[LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
{[!//
[!FOR "i" = "0" TO "15"!] 
    [!WS "4"!](uint16)[!"text:split($GLOBAL_AUX_RX_FILTERCOUNT_LIST)[num:i($i+1)]"!]U[!//
    [!IF "$i < 15"!],
    [!ENDIF!]
[!ENDFOR!]
};

/* List of auxilliary filter arrays */
[!IF "$CanEcucPartitionRefCount = 0"!][!// No CAN EcucPartition References - dump filter count list
static Llce_Can_AuxFilterType * Llce_AuxRx_Filters_List[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
{ 
    [!FOR "crtCtrl" = "0" TO "15"!] 
        [!IF "$crtCtrl > 0"!],
        [!ENDIF!]
        [!IF "text:split($GLOBAL_AUX_RX_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
    Llce_AuxRx_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
        [!ELSE!][!//
    NULL_PTR /* No filters for channel [!"$crtCtrl"!] */[!//
        [!ENDIF!]
    [!ENDFOR!]

};
[!ELSE!][!//
    [!LOOP "../CanGeneral/CanEcucPartitionRef/*"!]
        [!VAR "crtEcucPartitionPath" = "node:value(.)"!]
        [!VAR "CanEcucPartitionName" = "substring-after(substring-after($crtEcucPartitionPath, 'EcuC/EcuC/'), '/')"!]
static Llce_Can_AuxFilterType * Llce_AuxRx_Filters_List_[!"$CanEcucPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][LLCE_CAN_CONFIG_MAXCTRL_COUNT] =
{ 
    [!FOR "crtCtrl" = "0" TO "15"!][!//
        [!IF "$crtCtrl > 0"!],
        [!ENDIF!][!//
        [!IF "text:split($GLOBAL_AUX_RX_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
            [!LOOP "node:order(../../../CanConfigSet/CanController/*,'node:value(CanControllerId)')"!][!//
                [!IF "substring-after(./CanHwChannel,'BCAN_') = $crtCtrl"!][!//
                    [!IF "node:exists(./CanControllerEcucPartitionRef) and (node:value(./CanControllerEcucPartitionRef) = $crtEcucPartitionPath)"!][!//
Llce_AuxRx_Filters_Ctrl[!"$crtCtrl"!]_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
                    [!ELSE!][!//
NULL_PTR /* Channel [!"$crtCtrl"!] not in current partition*/[!//
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ELSE!][!//
NULL_PTR /* No aux filters for channel [!"$crtCtrl"!] */[!//
        [!ENDIF!]
    [!ENDFOR!]

};

    [!ENDLOOP!]
[!ENDIF!][!// $CanEcucPartitionRefCount = 0
[!ENDIF!][!// $AUX_FILTERS_COUNT != num:i(0)
[!ENDIF!][!// node:exists(../CanGeneral/CanAuxFilterEnable)
[!ENDIF!][!// node:value(../CanGeneral/CanAuxFilterEnable) = 'true'
[!ENDSELECT!]
/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
[!MACRO "GenerateTopConfig", "crtEcuCPartitionName", "pbVariantName", "defaultController"!]
const Can_43_LLCE_ConfigType Can_43_LLCE_Config[!"$pbVariantName"!][!"$crtEcuCPartitionName"!] =
[!WS "0"!]{
[!INDENT "4"!]
    &PlatformInitConfig[!"$crtEcuCPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    ControllerInit[!"$crtEcuCPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Llce_Rx_Filters_List[!"$crtEcuCPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Llce_RxAf_Filters_List[!"$crtEcuCPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!IF "node:exists(as:modconf('Can')[1]/CanGeneral/CanAuxFilterEnable) and ($AUX_FILTERS_COUNT != num:i(0)) and (as:modconf('Can')[1]/CanGeneral/CanAuxFilterEnable = 'true')"!]
    Llce_AuxRx_Filters_List[!"$crtEcuCPartitionName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Llce_MaxAuxilliaryFilterCount,
    [!ELSE!]
    NULL_PTR, /* There are no filters configured for the second rxlut */ 
    NULL_PTR,
    [!ENDIF!]
    MessageBufferConfigs_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    ControllerDescriptors_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    HwControllerDescriptors_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!IF "$CustomProcessingFlag = 'true'"!]
    CanFilterId2CustomIdx,
    [!ELSE!]
    NULL_PTR, /* No custom processing defined for any HRH */
    [!ENDIF!]
    [!IF "node:exists(../CanGeneral/CanLlceHeadlessModeUsed) and (node:value(../CanGeneral/CanLlceHeadlessModeUsed) = 'true')"!]
        [!IF "not(node:exists(../CanGeneral/CanLlceEnableHeadlessMode) and (node:value(../CanGeneral/CanLlceEnableHeadlessMode) = 'true'))"!]
            [!ERROR "To enable headless mode for this variant, also enable the global option"!]
        [!ENDIF!]
    (boolean)TRUE, /* LLCE started in Headless Mode */
    [!ELSE!]
    (boolean)FALSE, /* LLCE started normally */
    [!ENDIF!]
    [!IF "$crtEcuCPartitionName != ''"!][!CALL "GetCoreIdOfEcucPartition"!],[!ELSE!]0xFFFFFFFFU, /* No partition selected */[!ENDIF!][!CR!] 
    [!IF "$crtEcuCPartitionName != ''"!]LLCE_CAN_HIF[!"@index"!],[!ELSE!][!"node:value(../CanGeneral/HostInterface)"!],[!ENDIF!] /* LLCE HIF */ 
    [!"num:i($defaultController)"!]U /* Default controller */    
[!ENDINDENT!]
};
[!ENDMACRO!]

[!SELECT "CanConfigSet"!]
[!VAR "PBname" = "''"!]
[!VAR "crtDefaultController" = "0"!]
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild') or (variant:size() > 1))"!][!// VariantPostBuild or more than 1 configured variant
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "PBname" = "concat('_', $postBuildVariant)"!]
    [!ENDIF!]
[!ENDIF!]
[!//
[!IF "$CanEcucPartitionRefCount = 0"!][!// No CAN EcucPartition References
    [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!][!//
        [!IF "CanControllerActivation = 'true'"!]
        [!VAR "crtDefaultController" = "node:value(CanControllerId)"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDLOOP!]    
    [!CALL "GenerateTopConfig", "pbVariantName" = "$PBname", "defaultController" = "$crtDefaultController"!]
[!ELSE!][!//
    [!LOOP "../CanGeneral/CanEcucPartitionRef/*"!]
        [!VAR "CanEcucPartitionName" = "concat('_', substring-after(substring-after(., 'EcuC/EcuC/'), '/'))"!]
        [!VAR "crtEcucPartitionPath" = "node:value(.)"!]
        [!LOOP "node:order(../../../CanConfigSet/CanController/*,'node:value(CanControllerId)')"!][!//
            [!IF "CanControllerActivation = 'true' and node:exists(./CanControllerEcucPartitionRef) and (node:value(./CanControllerEcucPartitionRef) = $crtEcucPartitionPath)"!][!//
                [!VAR "crtDefaultController" = "node:value(CanControllerId)"!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]    
        [!CALL "GenerateTopConfig", "pbVariantName" = "$PBname", "crtEcuCPartitionName" = "$CanEcucPartitionName", "defaultController" = "$crtDefaultController"!]
    [!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]

[!// Special case for PreCompile with multiple partitions
[!IF "(./IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]
    [!IF "$CanEcucPartitionRefCount != 0"!][!// Existing CAN EcucPartition References
        [!SELECT "as:modconf('EcuC')[1]"!]
            [!VAR "MaxCoreIdConfig" = "num:i(count(./EcucHardware/*[1]/EcucCoreDefinition/*))"!]
        [!ENDSELECT!]
    [!INDENT "0"!]        
    const Can_43_LLCE_ConfigType * const [!WS!]Can_43_LLCE_Config[[!"$MaxCoreIdConfig"!]U] =
    {
        [!VAR "coreIdx" = "0"!]
        [!LOOP "node:order(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*, './EcucCoreId')"!]
            [!VAR "OsAppPart" = "''"!]
            [!VAR "coreIdx" = "$coreIdx + 1"!]
            [!VAR "CoreId" = "node:value(./EcucCoreId)"!]
            [!VAR "CanPartShortName" = "''"!]
            [!VAR "CanPartMatchCounter" = "0"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$CoreId = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                    [!VAR "OsAppPart" = "node:value(./OsAppEcucPartitionRef)"!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!LOOP "as:modconf('Can')[1]/CanGeneral/CanEcucPartitionRef/*"!]
                [!IF "$OsAppPart = node:value(.)"!]
                    [!VAR "CanPartMatchCounter" = "$CanPartMatchCounter + 1"!]
                    [!VAR "CanPartShortName" = "substring-after(substring-after(., 'EcuC/EcuC/'), '/')"!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!WS "4"!][!IF "$CanPartMatchCounter = 1"!]&Can_43_LLCE_Config_[!"$CanPartShortName"!] [!ELSE!] NULL_PTR[!ENDIF!][!IF "$coreIdx < $MaxCoreIdConfig"!],[!ENDIF!][!CR!]
        [!ENDLOOP!]
    };
    [!ENDINDENT!]        
    [!ENDIF!]
[!ENDIF!]


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Can_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
