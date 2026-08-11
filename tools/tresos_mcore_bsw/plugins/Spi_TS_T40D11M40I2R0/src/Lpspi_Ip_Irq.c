/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
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
*   @file    Lpspi_Ip_Irq.c
*   @implements     Lpspi_Ip_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup LPSPI_DRIVER Lpspi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpspi_Ip.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_VENDOR_ID_IRQ_C                      43
#define LPSPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define LPSPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       4
#define LPSPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define LPSPI_IP_SW_MAJOR_VERSION_IRQ_C               4
#define LPSPI_IP_SW_MINOR_VERSION_IRQ_C               0
#define LPSPI_IP_SW_PATCH_VERSION_IRQ_C               2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lpspi_Ip.h and Lpspi_Ip_Irq.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP_VENDOR_ID_IRQ_C)
    #error "Lpspi_Ip.h and Lpspi_Ip_Irq.c have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip_Irq.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip_Irq.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION_IRQ_C) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION_IRQ_C) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION_IRQ_C))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip_Irq.c are different"
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
static LLCE_Core_to_core_Type* const Lpspi_Ip_LlceCore2CoreBase[1u] = IP_LLCE_Core_to_core_BASE_PTRS;
#endif
#endif

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == LPSPI_IP_SUPPORT)  
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

ISR(Lpspi_Ip_Combined_IRQHandler);
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
ISR(Lpspi_Ip_Combined_IRQHandler)
{
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    const LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCore2CoreBase[0];
    #endif
    #endif
#ifdef LPSPI_IP_0_ENABLED
    #if (LPSPI_IP_0_ENABLED == STD_ON)
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    if((BaseCoreToCore->HINTCR[1] & BaseCoreToCore->HINTCER[1] & (((uint32)0x01U) << ((uint32)0U))) != 0U)
#endif
#endif
    {
        /* Interrupt handler for instance 0 */
        Lpspi_Ip_IrqHandler(0u);
    }
    #endif
#endif
#ifdef LPSPI_IP_1_ENABLED
    #if (LPSPI_IP_1_ENABLED == STD_ON)
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    if((BaseCoreToCore->HINTCR[1] & BaseCoreToCore->HINTCER[1] & (((uint32)0x01U) << ((uint32)1U))) != 0U)
#endif
#endif
    {
        /* Interrupt handler for instance 1 */
        Lpspi_Ip_IrqHandler(1u);
    }
    #endif
#endif
#ifdef LPSPI_IP_2_ENABLED
    #if (LPSPI_IP_2_ENABLED == STD_ON)
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    if((BaseCoreToCore->HINTCR[1] & BaseCoreToCore->HINTCER[1] & (((uint32)0x01U) << ((uint32)2U))) != 0U)
#endif
#endif
    {
        /* Interrupt handler for instance 2 */
        Lpspi_Ip_IrqHandler(2u);
    }
    #endif
#endif
#ifdef LPSPI_IP_3_ENABLED
    #if (LPSPI_IP_3_ENABLED == STD_ON)
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    if((BaseCoreToCore->HINTCR[1] & BaseCoreToCore->HINTCER[1] & (((uint32)0x01U) << ((uint32)3U))) != 0U)
#endif
#endif
    {
        /* Interrupt handler for instance 3 */
        Lpspi_Ip_IrqHandler(3u);
    }
    #endif
#endif
#ifdef LPSPI_IP_4_ENABLED
    #if (LPSPI_IP_4_ENABLED == STD_ON)
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    if((BaseCoreToCore->HINTCR[1] & BaseCoreToCore->HINTCER[1] & (((uint32)0x01U) << ((uint32)4U))) != 0U)
#endif
#endif
    {
        /* Interrupt handler for instance 4 */
        Lpspi_Ip_IrqHandler(4u);
    }
    #endif
#endif
    /* avoid compiler warning */
    (void)BaseCoreToCore;
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif

#ifdef __cplusplus
}
#endif

/** @} */
