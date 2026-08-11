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

#ifndef PCIE_CFG_H
#define PCIE_CFG_H

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

#include "Mcal.h"
#include "Pcie_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_CFG_VENDOR_ID                       43
#define PCIE_CFG_AR_RELEASE_MAJOR_VERSION        4
#define PCIE_CFG_AR_RELEASE_MINOR_VERSION        4
#define PCIE_CFG_AR_RELEASE_REVISION_VERSION     0
#define PCIE_CFG_SW_MAJOR_VERSION                4
#define PCIE_CFG_SW_MINOR_VERSION                0
#define PCIE_CFG_SW_PATCH_VERSION                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Pcie_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PCIE_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pcie_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_CFG_AR_RELEASE_MAJOR_VERSION != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_MINOR_VERSION != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_CFG_AR_RELEASE_REVISION_VERSION != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Types.h and Pcie_Cfg.h are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_CFG_SW_MAJOR_VERSION != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_CFG_SW_MINOR_VERSION != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_CFG_SW_PATCH_VERSION != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Types.h and Pcie_Cfg.h are different"
#endif
/* Check if Pcie_Types.h and Pcie_Cfg.h file are of the same vendor */
#if (PCIE_CFG_VENDOR_ID != PCIE_TYPES_VENDOR_ID)
    #error "Pcie_Cfg.h and Pcie_Types.h have different vendor IDs"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define PCIE_PRECOMPILE_SUPPORT [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** @brief   Total number of Pcie channel configured. */
#define PCIE_HW_MAX_CONFIG           ([!"num:i(count(PcieGlobalConfig/PcieChannel/*))"!]U)
/** @brief   Total number of available hardware Pcie channels. */
#define PCIE_HW_MAX_MODULES          ([!"num:i(ecu:get('Pcie.PcieGlobalConfig.PcieChannel'))"!]U)

/** @brief   Pre-processor switch to enable/disable development error detection for Pcie API */
#define PCIE_DEV_ERROR_DETECT                         ([!IF "PcieGeneral/PcieDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief   Number of DMA read channels for a pcie device */
#define PCIE_DMA_READ_CHANNELS_COUNT                           ([!"num:i(ecu:get('Pcie.PcieGlobalConfig.PcieDmaReadChannels'))"!]U)

/** @brief   Number of DMA write channels for a pcie device */
#define PCIE_DMA_WRITE_CHANNELS_COUNT                          ([!"num:i(ecu:get('Pcie.PcieGlobalConfig.PcieDmaWriteChannels'))"!]U)

#if (PCIE_DEV_ERROR_DETECT == STD_ON)
/** @brief   Number of IATU outbound regions for a pcie device */
#define PCIE_IATU_OUTBOUND_REGIONS_COUNT                          ([!"num:i(ecu:get('Pcie.PcieGlobalConfig.PcieIatuOutboundRegions'))"!]U)

/** @brief   Number of MSI-X interrupts supported by the pcie device */
#define PCIE_MSIX_COUNT                                          ([!"num:i(ecu:get('Pcie.PcieGlobalConfig.PcieMsixCount'))"!]U)
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */

/** @brief   Pre-processor switches to enable/disable the driver APIs */
#define PCIE_SET_OUTBOUND_REGION_API                  ([!IF "PcieGlobalConfig/APIconfiguration/PcieSetOutboundRegionApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_READ_API                             ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaReadApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_READ_INT_ENABLE_API                  ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaReadIntEnableApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_CHECK_READ_STATUS_API                ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaCheckReadStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_WRITE_API                            ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaWriteApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_WRITE_INT_ENABLE_API                 ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaWriteIntEnableApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_CHECK_WRITE_STATUS_API               ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaCheckWriteStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_SEND_MSI_API                             ([!IF "PcieGlobalConfig/APIconfiguration/PcieSendMsiApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_SEND_MSI_X_API                           ([!IF "PcieGlobalConfig/APIconfiguration/PcieSendMsiXApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_LL_READ_SETUP_API                    ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaLlReadSetupApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_DMA_LL_WRITE_SETUP_API                   ([!IF "PcieGlobalConfig/APIconfiguration/PcieDmaLlWriteSetupApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define PCIE_VERSION_INFO_API                         ([!IF "PcieGlobalConfig/APIconfiguration/PcieVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief   Number of BAR reserved for MSI-X table */
#define PCIE_MSIX_BAR                                            ([!"num:i(ecu:get('Pcie.PcieGlobalConfig.PcieMsixBar'))"!]U)

/** @brief    Enable/Disable Multi Core Support. */
#define PCIE_MULTICORE_SUPPORT                        ([!IF "(PcieGeneral/PcieMulticoreSupport='true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (PCIE_MULTICORE_SUPPORT == STD_ON)
    #define Pcie_GetCoreID()     ((uint32)OsIf_GetCoreID())
#else
    #define Pcie_GetCoreID()     ((uint32)0UL)
#endif /* (PCIE_MULTICORE_SUPPORT == STD_ON) */

/** @brief     Maximum number of partitions used in configuration. */
[!NOCODE!]
[!VAR "MaxCoreId"="0"!]
[!IF "as:modconf('Pcie')[1]/PcieGeneral/PcieMulticoreSupport='true'"!][!//
    [!LOOP "as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*"!][!//
            [!IF "$MaxCoreId < node:value(./EcucCoreId)"!]
                [!VAR "MaxCoreId"="node:value(./EcucCoreId)"!]
            [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!]
[!ENDNOCODE!]
#define PCIE_MAX_CORE_ID     ((uint8)[!"num:i($MaxCoreId+1)"!]U)

/** @brief   Hardware channel id */
[!CODE!]
[!LOOP "PcieGlobalConfig/PcieChannel/*"!]
#define PCIE_[!"substring-after(PcieHwChannel, '_')"!]                         [!"substring-after(PcieHwChannel, '_')"!]U
[!ENDLOOP!]
[!ENDCODE!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL CONSTANTS DECLARATIONS
==================================================================================================*/

#define PCIE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

/**
* @brief   Export Pre-Compile configurations.
*/
extern const Pcie_ConfigType * const Pcie_PBCfgVariantPredefined[PCIE_MAX_CORE_ID];

#define PCIE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PCIE_CFG_H */