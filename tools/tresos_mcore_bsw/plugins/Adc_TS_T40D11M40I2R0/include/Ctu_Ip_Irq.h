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

#ifndef CTU_IP_IRQ_H
#define CTU_IP_IRQ_H

/**
*   @file
*
*   @addtogroup ctu_ip
*   @{
*/
#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Ctu_Ip_Types.h"
#include "Ctu_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTU_IP_VENDOR_ID_IRQ                      43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ       4
#define CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define CTU_IP_SW_MAJOR_VERSION_IRQ               4
#define CTU_IP_SW_MINOR_VERSION_IRQ               0
#define CTU_IP_SW_PATCH_VERSION_IRQ               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ctu_Ip_Irq.h file and StandardTypes.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Irq.h and StandardTypes.h are different"
#endif
#endif

/* Check if Ctu_Ip_Irq.h file and Ctu_Ip_Types.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_IRQ != CTU_IP_VENDOR_ID_TYPES)
    #error "Ctu_Ip_Irq.h and Ctu_Ip_Types.h have different vendor ids"
#endif

/* Check if Ctu_Ip_Irq.h file and Ctu_Ip_Types.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ != CTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ != CTU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ != CTU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Irq.h and Ctu_Ip_Types.h are different"
#endif

/* Check if Ctu_Ip_Irq.h file and Ctu_Ip_Types.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_IRQ != CTU_IP_SW_MAJOR_VERSION_TYPES) || \
     (CTU_IP_SW_MINOR_VERSION_IRQ != CTU_IP_SW_MINOR_VERSION_TYPES) || \
     (CTU_IP_SW_PATCH_VERSION_IRQ != CTU_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Ctu_Ip_Irq.h and Ctu_Ip_Types.h are different"
#endif

/* Check if Ctu_Ip_Irq.h file and Ctu_Ip_CfgDefines.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_IRQ != CTU_IP_VENDOR_ID_CFGDEFINES)
    #error "Ctu_Ip_Irq.h and Ctu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Ctu_Ip_Irq.h file and Ctu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ != CTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ != CTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ != CTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Irq.h and Ctu_Ip_CfgDefines.h are different"
#endif

/* Check if Ctu_Ip_Irq.h file and Ctu_Ip_CfgDefines.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_IRQ != CTU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (CTU_IP_SW_MINOR_VERSION_IRQ != CTU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (CTU_IP_SW_PATCH_VERSION_IRQ != CTU_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Ctu_Ip_Irq.h and Ctu_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/* ISR prototypes required by IAR compiler */
#if (FEATURE_CTU_HAS_FIFO_IRQ_ROLLED)
ISR(Ctu_FIFO_Isr);
#else
ISR(Ctu_FIFO0_Isr);
ISR(Ctu_FIFO1_Isr);
ISR(Ctu_FIFO2_Isr);
ISR(Ctu_FIFO3_Isr);
#endif /* FEATURE_CTU_HAS_FIFO_IRQ_ROLLED */
ISR(Ctu_Trig_Isr);
ISR(Ctu_Error_Isr);

#ifdef CTU_IP_DMA_SUPPORTED
/* 
 * The following functions handle internal CTU updates after a DMA transfer is completed in Control Mode.
 * They are notifications to be called by DMA IPL, each corresponding to the completion of data transfer
 * from an internal FIFO, triggered by threshold from that FIFO being exceeded.
 */
void Ctu_Ip_Fifo0DmaComplete(void);
void Ctu_Ip_Fifo1DmaComplete(void);
void Ctu_Ip_Fifo2DmaComplete(void);
void Ctu_Ip_Fifo3DmaComplete(void);
#endif /* CTU_IP_DMA_SUPPORTED */

void Ctu_Ip_IRQHandler(const uint32 Instance,
                       const Ctu_Ip_IRQType IRQType,
                       const uint8 Offset);
#ifdef CTU_IP_DMA_SUPPORTED
void Ctu_Ip_FifoDmaHandler(const uint32 Instance,
                           const uint32 FifoIndex);
#endif /* CTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* CTU_IP_IRQ_H */
