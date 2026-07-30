/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
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
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup Serdes
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
#include "Serdes_Cfg.h"
#include "Serdes_Types.h"
#include "Serdes_Ipw_PBCfg.h"
[!NOCODE!][!//
[!INCLUDE "Serdes_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_CFG_VENDOR_ID_CFG_C                      43
#define SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define SERDES_CFG_SW_MAJOR_VERSION_CFG_C               4
#define SERDES_CFG_SW_MINOR_VERSION_CFG_C               0
#define SERDES_CFG_SW_PATCH_VERSION_CFG_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Serdes header file are of the same vendor */
#if (SERDES_CFG_VENDOR_ID_CFG_C != SERDES_VENDOR_ID_CFG)
    #error "Serdes_Cfg.c and Serdes_Cfg.h have different vendor ids"
#endif
/* Check if current file and Serdes header file are of the same Autosar version */
#if ((SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != SERDES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C    != SERDES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C != SERDES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Serdes_Cfg.c and Serdes_Cfg.h are different"
#endif
/* Check if current file and Serdes header file are of the same Software version */
#if ((SERDES_CFG_SW_MAJOR_VERSION_CFG_C != SERDES_SW_MAJOR_VERSION_CFG) || \
     (SERDES_CFG_SW_MINOR_VERSION_CFG_C != SERDES_SW_MINOR_VERSION_CFG) || \
     (SERDES_CFG_SW_PATCH_VERSION_CFG_C != SERDES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Serdes_Cfg.c and Serdes_Cfg.h are different"
#endif

/* Check if current file and Serdes_Types.h file are of the same vendor */
#if (SERDES_CFG_VENDOR_ID_CFG_C != SERDES_TYPES_VENDOR_ID)
    #error "Serdes_Cfg.c and Serdes_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Types.h file are of the same Autosar version */
#if ((SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != SERDES_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C    != SERDES_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C != SERDES_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Cfg.c and Serdes_Types.h are different"
#endif
/* Check if current file and Serdes_Types.h file are of the same Software version */
#if ((SERDES_CFG_SW_MAJOR_VERSION_CFG_C != SERDES_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_CFG_SW_MINOR_VERSION_CFG_C != SERDES_TYPES_SW_MINOR_VERSION) || \
     (SERDES_CFG_SW_PATCH_VERSION_CFG_C != SERDES_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Cfg.c and Serdes_Types.h are different"
#endif

/* Check if current file and Serdes_Ipw_PBCfg.h file are of the same vendor */
#if (SERDES_CFG_VENDOR_ID_CFG_C != SERDES_IPW_PBCFG_VENDOR_ID)
    #error "Serdes_Cfg.c and Serdes_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw_PBCfg.h file are of the same Autosar version */
#if ((SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != SERDES_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C    != SERDES_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C != SERDES_IPW_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Cfg.c and Serdes_Ipw_PBCfg.h are different"
#endif
/* Check if current file and Serdes_Ipw_PBCfg.h file are of the same Software version */
#if ((SERDES_CFG_SW_MAJOR_VERSION_CFG_C != SERDES_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (SERDES_CFG_SW_MINOR_VERSION_CFG_C != SERDES_IPW_PBCFG_SW_MINOR_VERSION) || \
     (SERDES_CFG_SW_PATCH_VERSION_CFG_C != SERDES_IPW_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Cfg.c and Serdes_Ipw_PBCfg.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!AUTOSPACING!][!//

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define SERDES_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

[!CODE!][!//
[!VAR "Channel"= "num:i(count(SerdesGlobalConfig/SerdesChannel/*))-1"!]
/**
* @brief        Definition of Serdes hardware channel structure.
* @details      Configures the hardware peripheral of a Serdes channel.
*               Configuration set by calling Serdes_Init() API.
*/
[!VAR "VariantsNo" = "variant:size()"!]
[!VAR "MaxPartition" = "num:i(0)"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "MaxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]
[!IF "$MaxPartition = 0"!][!VAR "MaxPartition" = "num:i(1)"!][!ENDIF!][!//
[!IF "node:exists(SerdesGeneral/SerdesMulticoreSupport) and node:value(SerdesGeneral/SerdesMulticoreSupport) = 'true'"!]
    [!FOR "idx" = "0" TO "num:i($MaxPartition) - 1"!][!//
        [!VAR "PartitionExist"="0"!][!//
        [!LOOP "SerdesGeneral/SerdesEcucPartitionRef/*"!][!//
            [!VAR "PCIndex" = "../../@index"!][!//
            [!VAR "SerdesCrtPart" = "node:value(.)"!][!//
            [!VAR "SerdesCrtPartShortName" = "substring-after(substring-after($SerdesCrtPart, node:name(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1])), "/")"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "$SerdesCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                        [!IF "$idx = node:value(./EcucCoreId)"!][!//
                            [!VAR "CurrentPartition" = "$SerdesCrtPartShortName"!][!//
                            [!VAR "PartitionExist"="1"!][!//
static const Serdes_HwUnitConfigType Serdes_ChannelConfig_[!"$CurrentPartition"!][2] =
{
                            [!LOOP "as:modconf('Serdes')[1]/SerdesGlobalConfig/SerdesChannel/*"!][!//
                                [!VAR "ChannelIndex" = "@index + 1"!][!//
                                [!LOOP "SerdesChannelEcucPartitionRef/*"!][!//
                                    [!VAR "SerdesChannelPartition" = "node:value(.)"!][!//
                                    [!VAR "SerdesChannelPartitionShortName" = "substring-after(substring-after($SerdesChannelPartition, node:name(as:modconf("EcuC")[1]/   EcucPartitionCollection/*[1])), "/")"!][!//
                                    [!IF "$CurrentPartition = $SerdesChannelPartitionShortName"!][!//

    {
        (Serdes_HwUnitType)SERDES_IP_SS_BASE_ADDR_[!"substring-after(../../SerdesHwChannel, '_')"!],[!//

        &Serdes_Ipw_ChannelConfig[!"../../SerdesChannelId"!]
    }[!IF "$ChannelIndex < num:i(count(../../../*))"!],[!ENDIF!]
                                    [!ELSE!][!//

    {
        (Serdes_HwUnitType)255,
        NULL_PTR
    }[!IF "$ChannelIndex < num:i(count(../../../*))"!],[!ENDIF!]
                                    [!ENDIF!][!//
                                [!ENDLOOP!][!//
                            [!ENDLOOP!][!//
                            [!IF "$PartitionExist = 1"!][!//

};

                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDFOR!][!//
[!ELSE!][!// Multicore = off
static const Serdes_HwUnitConfigType Serdes_ChannelConfig[[!"num:i(count(SerdesGlobalConfig/SerdesChannel/*))"!]] =
{
    [!LOOP "SerdesGlobalConfig/SerdesChannel/*"!]
        [!VAR "PCindex" = "@index"!]
        {
            /* The hardware channel ID. */
            (Serdes_HwUnitType) SERDES_IP_SS_BASE_ADDR_[!"substring-after(SerdesHwChannel, '_')"!],

            &Serdes_Ipw_ChannelConfig[!"SerdesChannelId"!]
        }[!IF "$PCindex < $Channel"!],[!ENDIF!] /* End of Serdes_ChannelConfig[[!"@index"!]]. */
    [!ENDLOOP!]
};
[!ENDIF!][!//
[!ENDCODE!][!//

[!CODE!][!//
/**
* @brief        Definition of Serdes hardware channel structure.
* @details      Configures the hardware peripheral of a Serdes channel.
*               Configuration set by calling Serdes_Init() API.
*/
[!ENDCODE!][!//
[!NOCODE!][!//
[!VAR "MaxPartition" = "num:i(0)"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "MaxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!][!//
[!IF "$MaxPartition = 0"!][!VAR "MaxPartition" = "num:i(1)"!][!ENDIF!][!//

[!IF "node:exists(SerdesGeneral/SerdesMulticoreSupport) and node:value(SerdesGeneral/SerdesMulticoreSupport)='true'"!]
[!CODE!][!//
const Serdes_ConfigType Serdes_PBCfgVariantPredefined[SERDES_MAX_PARTITIONS] =
{
    /* Pointer to Serdes Hardware Unit configuration. */
[!ENDCODE!][!//
    [!FOR "idx" = "0" TO "num:i($MaxPartition) - 1"!][!//
        [!VAR "PartitionExist"="0"!][!//
        [!LOOP "SerdesGeneral/SerdesEcucPartitionRef/*"!][!//
            [!VAR "SerdesCrtPart" = "node:value(.)"!][!//
            [!VAR "SerdesCrtPartShortName" = "substring-after(substring-after($SerdesCrtPart, node:name(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1])), "/")"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "$SerdesCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                        [!IF "$idx = node:value(./EcucCoreId)"!][!//
                            [!VAR "CurrentPartition" = "$SerdesCrtPartShortName"!][!//
                            [!VAR "PartitionExist"="1"!][!//
                        [!ENDIF!][!//
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
        [!IF "$PartitionExist = 1"!][!//
[!CODE!][!//
    {
        /* CoreId */
        (uint32)([!"$idx"!]UL),
        /* Pointer to Serdes Hardware Unit configuration. */
        &Serdes_ChannelConfig_[!"$CurrentPartition"!]
            [!IF "$idx < ($MaxPartition - 1)"!][!//
    },
            [!ELSE!][!//
    }
            [!ENDIF!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
    {
        /* CoreId */
        (uint32)([!"$idx"!]UL),
        /* Pointer to Serdes Hardware Unit configuration. */
        NULL_PTR
            [!IF "$idx < ($MaxPartition - 1)"!][!//
    },
            [!ELSE!][!//
    }
            [!ENDIF!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ELSE!][!// Multicore = Off
[!CODE!][!//
const Serdes_ConfigType Serdes_PBCfgVariantPredefined[1] =
{
    {
        /* CoreId */
        (uint32)(0UL),
        /* Pointer to Serdes Hardware Unit configuration. */
        &Serdes_ChannelConfig
    }
[!ENDCODE!][!//
[!ENDIF!][!// Multicore
[!CODE!]};[!ENDCODE!][!//

};

[!ENDNOCODE!][!//

#define SERDES_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
