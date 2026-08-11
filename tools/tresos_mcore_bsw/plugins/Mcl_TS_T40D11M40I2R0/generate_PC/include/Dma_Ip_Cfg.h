/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,FTM
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

#ifndef DMA_IP_CFG_H
#define DMA_IP_CFG_H

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
#include "Dma_Ip_Types.h"
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#include "Dma_Ip_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!][!//
#include "Dma_Ip_PBcfg.h"
[!ENDIF!][!//

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_VENDOR_ID                       43
#define DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_AR_RELEASE_MINOR_VERSION        4
#define DMA_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_SW_MAJOR_VERSION                4
#define DMA_IP_CFG_SW_MINOR_VERSION                0
#define DMA_IP_CFG_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Types.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_TYPES_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Types.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_Types.h are different"
#endif

/* Check if header file and Dma_Ip_Types.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_TYPES_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_TYPES_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_Types.h are different"
#endif

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if header file and Dma_Ip_[!"."!]_PBcfg.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_[!"."!]_PBCFG_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_[!"."!]_PBcfg.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_[!"."!]_PBcfg.h are different"
#endif

/* Check if header file and Dma_Ip_[!"."!]_PBcfg.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_[!"."!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if header file and Dma_Ip_PBcfg.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_PBCFG_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_PBcfg.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_PBcfg.h are different"
#endif

/* Check if header file and Dma_Ip_PBcfg.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_PBCFG_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_PBCFG_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_PBcfg.h are different"
#endif
[!ENDIF!][!//

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "node:value(./MclGeneral/MclDma/MclEnableDma)"!][!//

[!INCLUDE "Dma_Ip_RegOperations.m"!]
/* Number Of Configured Logic Instances */
[!IF "node:value(./MclGeneral/MclEnableUserModeSupport)"!][!//
#define MCL_ENABLE_USER_MODE_SUPPORT    STD_ON
[!ELSE!][!//
#define MCL_ENABLE_USER_MODE_SUPPORT    STD_OFF
[!ENDIF!][!//

#if (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT)
#define MCL_DMA_REG_PROT_AVAILABLE
#endif

#define DMA_IP_NOF_CFG_LOGIC_INSTANCES   ((uint32)[!CALL "Dma_Ip_GetNrOfLogicInstances"!]U)

[!LOOP "./MclConfig/dmaLogicInstance_ConfigType/*"!]
/* Logic Instance [!"@index"!] */
#define [!"node:value(dmaLogicInstance_IdName)"!]    ((uint32)[!"@index"!]U)
[!ENDLOOP!][!//

/* Number Of Configured Logic Channels */
#define DMA_IP_NOF_CFG_LOGIC_CHANNELS   ((uint32)[!CALL "Dma_Ip_GetNrOfLogicChannels"!]U)
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!VAR "LogicChannelName"="node:value(dmaLogicChannel_LogicName)"!]
/* Logic Channel [!"@index"!] */
#define [!"$LogicChannelName"!]      ((uint32)[!"@index"!]U)

[!IF "node:value(dmaLogicChannel_EnableScatterGather)"!][!//
/* Logic Channel [!"@index"!] Scatter/Gather Elements */
#define [!"$LogicChannelName"!]_NOF_CFG_SGA_ELEMENTS  ((uint32)[!CALL "Dma_Ip_GetNrOfSGElements_HardCodedPath"!]U)
[!LOOP "./dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*"!][!//
[!VAR "ElementName"="node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_ScatterGatherElementNameType)"!]
#define [!"$ElementName"!]       ((uint32)[!"@index"!]U)
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//


#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/* DMA Initialization Structure */
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
extern const Dma_Ip_InitType Dma_Ip_xDmaInitPB_[!"."!];
[!ENDLOOP!][!//
[!ELSE!][!//
extern const Dma_Ip_InitType Dma_Ip_xDmaInitPB;
[!ENDIF!][!//

extern const Dma_Ip_LogicChannelConfigType Dma_Ip_xLogicChannelResetConfig;

extern const Dma_Ip_LogicInstanceConfigType Dma_Ip_xLogicInstanceResetConfig;

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/* DMA IRQ Handlers */
ISR(Dma0_Ch0_Ch15_IrqHandler);
ISR(Dma0_Ch16_Ch31_IrqHandler);
ISR(Dma0_Error_IrqHandler);
ISR(Dma1_Ch0_Ch15_IrqHandler);
ISR(Dma1_Ch16_Ch31_IrqHandler);
ISR(Dma1_Error_IrqHandler);

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

[!ENDIF!][!//

#ifdef __cplusplus
}
#endif

#endif /* DMA_IP_CFG_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
