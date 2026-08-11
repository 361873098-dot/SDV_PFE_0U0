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

#ifndef PCIE_IP_H
#define PCIE_IP_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDES
==================================================================================================*/

#include "Pcie_Types.h"
#include "Pcie_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Pcie_Ip.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IP_VENDOR_ID                    43
#define PCIE_IP_MODULE_ID                    255
#define PCIE_IP_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_IP_AR_RELEASE_MINOR_VERSION     4
#define PCIE_IP_AR_RELEASE_REVISION_VERSION  0
#define PCIE_IP_SW_MAJOR_VERSION             4
#define PCIE_IP_SW_MINOR_VERSION             0
#define PCIE_IP_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pcie types header file are of the same vendor */
#if (PCIE_IP_VENDOR_ID != PCIE_TYPES_VENDOR_ID)
#error "Pcie_Ip.h and Pcie_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_IP_AR_RELEASE_MAJOR_VERSION    != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_MINOR_VERSION    != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_REVISION_VERSION != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip.h and Pcie_Types.h are different"
#endif
/* Check if current file and Pcie types header file are of the same software version */
#if ((PCIE_IP_SW_MAJOR_VERSION != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IP_SW_MINOR_VERSION != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IP_SW_PATCH_VERSION != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip.h and Pcie_Types.h are different"
#endif

/* Check if current file and Pcie Ip config header file are of the same vendor */
#if (PCIE_IP_VENDOR_ID != PCIE_IP_CFG_VENDOR_ID)
#error "Pcie_Ip.h and Pcie_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Pcie Ip config header file are of the same Autosar version */
#if ((PCIE_IP_AR_RELEASE_MAJOR_VERSION    != PCIE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_MINOR_VERSION    != PCIE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_REVISION_VERSION != PCIE_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip.h and Pcie_Ip_Cfg.h are different"
#endif
/* Check if current file and Pcie Ip config header file are of the same software version */
#if ((PCIE_IP_SW_MAJOR_VERSION != PCIE_IP_CFG_SW_MAJOR_VERSION) || \
     (PCIE_IP_SW_MINOR_VERSION != PCIE_IP_CFG_SW_MINOR_VERSION) || \
     (PCIE_IP_SW_PATCH_VERSION != PCIE_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip.h and Pcie_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define PCIE_IP_S32G_PCIE_0_BASE_U32          ((uint32)0x40400000U)
#define PCIE_IP_S32G_PCIE_1_BASE_U32          ((uint32)0x44100000U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"

/* Pcie Init */
void Pcie_Ip_Init(uint8 instance, const Pcie_Ip_ConfigType *pcieConfig);
/* Pcie Set Outbound Region */
Pcie_Ip_StatusType Pcie_Ip_SetOutboundRegion(uint8 instance, const Pcie_OutRegDescriptorType *outRegDesc);
/* Pcie DMA read */
Pcie_Ip_StatusType Pcie_Ip_DmaRead(uint8 instance, uint8 channel, const Pcie_DmaReadDescriptorType *readDesc);
/* Enable DMA read interrupts */
Pcie_Ip_StatusType Pcie_Ip_DmaReadIntEnable(uint8 instance, uint8 channel, boolean enable);
/* Pcie DMA check read status */
Pcie_Ip_StatusType Pcie_Ip_DmaCheckReadStatus(uint8 instance, uint8 channel, uint32 *transfersLeft);
/* Pcie DMA write */
Pcie_Ip_StatusType Pcie_Ip_DmaWrite(uint8 instance, uint8 channel, const Pcie_DmaWriteDescriptorType *writeDesc);
/* Enable DMA write interrupts */
Pcie_Ip_StatusType Pcie_Ip_DmaWriteIntEnable(uint8 instance, uint8 channel, boolean enable);
/* Pcie DMA check write status */
Pcie_Ip_StatusType Pcie_Ip_DmaCheckWriteStatus(uint8 instance, uint8 channel, uint32 *transfersLeft);
/* Send MSI interrupt */
Pcie_Ip_StatusType Pcie_Ip_SendMsi(uint8 instance, uint32 intNo);
/* Send MSI-X interrupt */
Pcie_Ip_StatusType Pcie_Ip_SendMsiX(uint8 instance, uint32 intNo);
/* Prepare read DMA channel for linked list operation */
Pcie_Ip_StatusType Pcie_Ip_DmaLlReadSetup(uint8 instance, uint8 channel, Pcie_DmaLlElementType *llPtr, uint32 size);
/* Prepare write DMA channel for linked list operation */
Pcie_Ip_StatusType Pcie_Ip_DmaLlWriteSetup(uint8 instance, uint8 channel, Pcie_DmaLlElementType *llPtr, uint32 size);
/* PCIe IRQ handler */
void Pcie_Ip_DmaIRQHandler(uint8 instance);

#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* PCIE_IP_H */
