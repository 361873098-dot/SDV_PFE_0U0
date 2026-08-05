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
*   @addtogroup PCIE_DRIVER
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
#include "Pcie_Cfg.h"
#include "Pcie_Types.h"
#include "Pcie_Ipw_PBCfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_CFG_VENDOR_ID_C                      43
#define PCIE_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define PCIE_CFG_AR_RELEASE_MINOR_VERSION_C       4
#define PCIE_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define PCIE_CFG_SW_MAJOR_VERSION_C               4
#define PCIE_CFG_SW_MINOR_VERSION_C               0
#define PCIE_CFG_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Pcie_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/* Check if Pcie configuration source file and Pcie configuration header file are of the same vendor */
#if (PCIE_CFG_VENDOR_ID_C != PCIE_CFG_VENDOR_ID)
    #error "Pcie_Cfg.c and Pcie_Cfg.h have different vendor ids"
#endif

/* Check if Pcie configuration source file and Pcie configuration header file are of the same Autosar version */
#if ((PCIE_CFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_MINOR_VERSION_C != PCIE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_REVISION_VERSION_C != PCIE_CFG_AR_RELEASE_REVISION_VERSION))   
    #error "AutoSar Version Numbers of Pcie_Cfg.c and Pcie_Cfg.h are different"
#endif

/* Check if Pcie configuration source file and Pcie configuration header file are of the same Software version */
#if ((PCIE_CFG_SW_MAJOR_VERSION_C != PCIE_CFG_SW_MAJOR_VERSION) || \
     (PCIE_CFG_SW_MINOR_VERSION_C != PCIE_CFG_SW_MINOR_VERSION) || \
     (PCIE_CFG_SW_PATCH_VERSION_C != PCIE_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Cfg.c and Pcie_Cfg.h are different"
#endif

/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_CFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_MINOR_VERSION_C != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_REVISION_VERSION_C != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Types.h and Pcie_Cfg.c are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_CFG_SW_MAJOR_VERSION_C != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_CFG_SW_MINOR_VERSION_C != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_CFG_SW_PATCH_VERSION_C != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Types.h and Pcie_Cfg.c are different"
#endif
/* Check if Pcie_Types.h and Pcie_Cfg.c file are of the same vendor */
#if (PCIE_CFG_VENDOR_ID_C != PCIE_TYPES_VENDOR_ID)
    #error "Pcie_Cfg.c and Pcie_Types.h have different vendor IDs"
#endif

/* Check if current file and Pcie_Ipw_PBCfg.h are of the same vendor */
#if (PCIE_CFG_VENDOR_ID_C!= PCIE_IPW_PBCFG_VENDOR_ID)
    #error "Pcie_Cfg.c and Pcie_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ipw_PBCfg.h are of the same Autosar version */
#if ((PCIE_CFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_MINOR_VERSION_C != PCIE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_REVISION_VERSION_C != PCIE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Cfg.c and Pcie_Ipw_PBCfg.h are different"
#endif
/* Check if current file and Pcie_Ipw_PBCfg.h are of the same Software version */
#if ((PCIE_CFG_SW_MAJOR_VERSION_C != PCIE_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (PCIE_CFG_SW_MINOR_VERSION_C != PCIE_IPW_PBCFG_SW_MINOR_VERSION) || \
     (PCIE_CFG_SW_PATCH_VERSION_C != PCIE_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Cfg.c and Pcie_Ipw_PBCfg.h are different"
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

/**
* @brief          Paritition IDs.
*/
[!LOOP "as:modconf('Pcie')[1]/PcieGlobalConfig/PcieEcucPartitionRef/*"!][!//
    [!VAR "PartRef" = "node:value(.)"!][!//
    [!VAR "PartName" = "text:toupper(node:name(node:ref(.)))"!][!//
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
        [!IF "$PartRef = node:value(./OsAppEcucPartitionRef)"!][!//
            [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                [!CODE!]
#define PCIE_[!"$PartName"!]_CORE_ID       ([!"node:value(./EcucCoreId)"!]U)
                [!ENDCODE!]
            [!ENDSELECT!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDLOOP!][!//

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/


[!NOCODE!]
[!VAR "Channel"= "num:i(count(PcieGlobalConfig/PcieChannel/*))-1"!]
[!CODE!]
#define PCIE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

/**
* @brief        Definition of Pcie hardware channel structure.
* @details      Configures the hardware peripheral of a Pcie channel.
*               Configuration set by calling Pcie_Init() API.
*/
static const Pcie_HwUnitConfigType Pcie_ChannelConfig[[!"num:i(count(PcieGlobalConfig/PcieChannel/*))"!]] =
{
    [!LOOP "PcieGlobalConfig/PcieChannel/*"!]
        [!VAR "PCindex" = "@index"!]
        {
           (uint8) PCIE_[!"substring-after(PcieHwChannel, '_')"!],      /* Pcie_HwUnit */
            [!IF "as:modconf('Pcie')[1]/PcieGeneral/PcieMulticoreSupport='true'"!][!//
            [!VAR "PartName" = "text:toupper(node:name(node:ref(./PcieChannelEcucPartitionRef)))"!][!//
            (uint32)PCIE_[!"$PartName"!]_CORE_ID,                       /* CoreId */
            [!ELSE!][!//
            (uint32)0U,                                                 /* CoreId */
            [!ENDIF!][!//
            &Pcie_Ipw_ChannelConfig[!"PcieChannelId"!]                  /* HwChannelConfig */[!//

        }[!IF "$PCindex < $Channel"!],[!ENDIF!] /* End of Pcie_ChannelConfig[[!"@index"!]].*/
    [!ENDLOOP!]
};


[!IF "as:modconf('Pcie')[1]/PcieGeneral/PcieMulticoreSupport='true'"!][!//

[!LOOP "PcieGlobalConfig/PcieEcucPartitionRef/*"!]

    [!IF "node:containsValue(../../PcieChannel/*/PcieChannelEcucPartitionRef, node:value(.))"!]
    [!VAR "PartName" = "node:name(node:ref(.))"!]
/**
* @brief        Pcie configuration for partition [!"$PartName"!]
*/
static const Pcie_ConfigType Pcie_Config_[!"$PartName"!] =
{
    (uint32)PCIE_[!"text:toupper($PartName)"!]_CORE_ID,   /* CoreId */
    &Pcie_ChannelConfig                     /* Pcie_HwConfig */
};
    [!ENDIF!]
[!ENDLOOP!]

[!ELSE!][!// PcieMulticoreSupport='false'
/**
* @brief        Pcie configuration - single core.
*/
static const Pcie_ConfigType Pcie_Config =
{
    (uint32)0U,              /* CoreId */
    &Pcie_ChannelConfig      /* Pcie_HwConfig */
};

[!ENDIF!][!// PcieMulticoreSupport

/**
* @brief        Configuration data for the Pcie driver.
*/
const Pcie_ConfigType * const Pcie_PBCfgVariantPredefined[PCIE_MAX_CORE_ID] =
{
[!IF "as:modconf('Pcie')[1]/PcieGeneral/PcieMulticoreSupport='true'"!][!//
[!VAR "MaxCoreId"="0"!][!// compute maximum core id used
[!LOOP "as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*"!][!//
    [!IF "$MaxCoreId < node:value(./EcucCoreId)"!]
        [!VAR "MaxCoreId"="node:value(./EcucCoreId)"!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!VAR "NoPartitions" = "0"!][!//
[!FOR "CurrentCoreId" = "0" TO "$MaxCoreId"!]
    [!VAR "foundPartition" = "0"!]
    [!LOOP "PcieGlobalConfig/PcieEcucPartitionRef/*"!]
        [!IF "num:i($foundPartition) = 0"!]
            [!VAR "PartName" = "node:name(node:ref(.))"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$PartName = node:name(node:ref(./OsAppEcucPartitionRef))"!]
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                        [!VAR "OsCoreId" = "node:value(./EcucCoreId)"!]
                        [!IF "num:i($OsCoreId) = num:i($CurrentCoreId)"!]
                            [!LOOP "as:modconf('Pcie')[1]/PcieGlobalConfig/PcieChannel/*/PcieChannelEcucPartitionRef"!]
                                [!IF "node:name(node:ref(.)) = $PartName"!]
                                    [!VAR "foundPartition" = "1"!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$foundPartition = 1"!]
    &Pcie_Config_[!"$PartName"!][!IF "$NoPartitions < num:i($MaxCoreId)"!],[!VAR "NoPartitions" = "$NoPartitions + 1"!][!ENDIF!]
    [!ELSE!]
    NULL_PTR[!IF "$NoPartitions < num:i($MaxCoreId)"!],[!VAR "NoPartitions" = "$NoPartitions + 1"!][!ENDIF!]
    [!ENDIF!]

[!ENDFOR!]
[!ELSE!][!// PcieMulticoreSupport='false'
    &Pcie_Config
[!ENDIF!][!// PcieMulticoreSupport
};

#define PCIE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"
[!ENDCODE!]
[!ENDNOCODE!]


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
