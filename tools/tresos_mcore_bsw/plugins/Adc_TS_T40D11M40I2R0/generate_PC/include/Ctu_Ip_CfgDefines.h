[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

#ifndef CTU_IP_CFGDEFINES_H
#define CTU_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup ctu_ip_config CTU IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!INDENT "0"!][!//
[!NOCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_CTU.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_CTU.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R45') or contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_CTU.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//
#include "OsIf.h"
[!NOCODE!][!//
[!INCLUDE "Adc_VersionCheck_Src.m"!][!//
[!INCLUDE "Adc_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CTU_IP_VENDOR_ID_CFGDEFINES                       43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES        4
#define CTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES        4
#define CTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES     0
#define CTU_IP_SW_MAJOR_VERSION_CFGDEFINES                4
#define CTU_IP_SW_MINOR_VERSION_CFGDEFINES                0
#define CTU_IP_SW_PATCH_VERSION_CFGDEFINES                2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

[!CALL "CtuIpCfgDefinesMacro"!][!//
#define CTU_IP_INVALID_DMA_CHANNEL_ID       (0xFFU)
[!IF "AutosarExt/CtuEnableDmaTransferMode"!][!//
#define CTU_IP_DMA_SUPPORTED
[!IF "AdcConfigSet/CtuHwUnit/*[1]/CtuFifoDmaRawData"!][!//
#define CTU_IP_FIFO_DMA_RAW_EN
[!ENDIF!][!//
[!ENDIF!][!//
#define CTU_IP_COMMAND_LIST_COUNT           (CTU_CLR_COUNT)
#define CTU_IP_FIFO_COUNT                   (4U)
#define CTU_IP_FIFO_DEPTH                   ([!"ecu:get('AdcMaxCTUFifoDepth')"!]U)
#define FEATURE_CTU_NUM_ADC                 ([!"ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!]U)
#define FEATURE_CTU_NUM_TRG                 (8U)

#define FEATURE_CTU_HAS_TCR_UNROLLED            (STD_OFF)
#define FEATURE_CTU_HAS_FIFO_IRQ_ROLLED         (STD_ON)
/* On this platform the CLR register has big endian format */
#define FEATURE_CTU_CLR_LITTLE_ENDIAN           (STD_OFF)
/* Mark if there is an external trigger pin available */
#define FEATURE_CTU_EXT_TRIG_PRESENT            (STD_OFF)

/* Available input triggers */
[!CALL "FeatureAvailableCtuTrigSourceMacro"!][!//

/* NOTE: Defines added only to allow definition of CTU_IP_OUTPUT_TRIG_ALL_EN with value set dynamically
 * depending on which ETIMER instances are connected to CTU for the current device */
#ifdef CTU_THCR1_T0_T1E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_1_EN_LOCAL    (CTU_THCR1_T0_T1E_MASK) /* define used only for CTU_IP_OUTPUT_TRIG_ALL_EN */
#else
#define CTU_IP_OUTPUT_TRIG_TIMER_1_EN_LOCAL    (0U) /* INSTANCE NOT AVAILABLE */
#endif /* CTU_THCR1_T0_T1E_MASK */
#ifdef CTU_THCR1_T0_T2E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_2_EN_LOCAL    (CTU_THCR1_T0_T2E_MASK) /* define used only for CTU_IP_OUTPUT_TRIG_ALL_EN */
#else
#define CTU_IP_OUTPUT_TRIG_TIMER_2_EN_LOCAL    (0U) /* INSTANCE NOT AVAILABLE */
#endif /* CTU_THCR1_T0_T2E_MASK */
#ifdef CTU_THCR1_T0_T3E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_3_EN_LOCAL    (CTU_THCR1_T0_T3E_MASK) /* define used only for CTU_IP_OUTPUT_TRIG_ALL_EN */
#else
#define CTU_IP_OUTPUT_TRIG_TIMER_3_EN_LOCAL    (0U) /* INSTANCE NOT AVAILABLE */
#endif /* CTU_THCR1_T0_T3E_MASK */
#ifdef CTU_THCR1_T0_T4E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_4_EN_LOCAL    (CTU_THCR1_T0_T4E_MASK) /* define used only for CTU_IP_OUTPUT_TRIG_ALL_EN */
#else
#define CTU_IP_OUTPUT_TRIG_TIMER_4_EN_LOCAL    (0U) /* INSTANCE NOT AVAILABLE */
#endif /* CTU_THCR1_T0_T4E_MASK */
#ifdef CTU_THCR1_T0_ETE_MASK
#define CTU_IP_OUTPUT_TRIG_EXT_EN_LOCAL        (CTU_THCR1_T0_ETE_MASK)  /* define used only for CTU_IP_OUTPUT_TRIG_ALL_EN */
#else
#define CTU_IP_OUTPUT_TRIG_EXT_EN_LOCAL        (0U)  /* External Trigger output Enable is not present */
#endif /* CTU_THCR1_T0_ETE_MASK */

/* NOTE: Defines added only to allow definition of CTU_IP_ERROR_FLAG_ALL with value set dynamically
 * depending on which ETIMER instances are connected to CTU for the current device */
#ifdef CTU_EFR_T1_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_1_OVERRUN_LOCAL      (CTU_EFR_T1_OE_MASK)
#else
#define CTU_IP_ERROR_FLAG_TIMER_1_OVERRUN_LOCAL      (0U)
#endif /* CTU_EFR_T1_OE_MASK */
#ifdef CTU_EFR_T2_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_2_OVERRUN_LOCAL      (CTU_EFR_T2_OE_MASK)
#else
#define CTU_IP_ERROR_FLAG_TIMER_2_OVERRUN_LOCAL      (0U)
#endif /* CTU_EFR_T2_OE_MASK */
#ifdef CTU_EFR_T3_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_3_OVERRUN_LOCAL      (CTU_EFR_T3_OE_MASK)
#else
#define CTU_IP_ERROR_FLAG_TIMER_3_OVERRUN_LOCAL      (0U)
#endif /* CTU_EFR_T3_OE_MASK */
#ifdef CTU_EFR_T4_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_4_OVERRUN_LOCAL      (CTU_EFR_T4_OE_MASK)
#else
#define CTU_IP_ERROR_FLAG_TIMER_4_OVERRUN_LOCAL      (0U)
#endif /* CTU_EFR_T4_OE_MASK */
#ifdef CTU_EFR_ET_OE_MASK
#define CTU_IP_ERROR_FLAG_EXT_TRIG_OVERRUN_LOCAL     (CTU_EFR_ET_OE_MASK)
#else
#define CTU_IP_ERROR_FLAG_EXT_TRIG_OVERRUN_LOCAL     (0U)
#endif /* CTU_EFR_ET_OE_MASK */

#ifdef CTU_EFR_CS_MASK
#define CTU_IP_ERROR_FLAG_SELF_TEST_RUNNING_LOCAL     (CTU_EFR_CS_MASK)
#else
#define CTU_IP_ERROR_FLAG_SELF_TEST_RUNNING_LOCAL     (0U)
#endif /* CTU_EFR_CS_MASK */

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
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

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CTU_IP_CFGDEFINES_H */
[!ENDCODE!]
