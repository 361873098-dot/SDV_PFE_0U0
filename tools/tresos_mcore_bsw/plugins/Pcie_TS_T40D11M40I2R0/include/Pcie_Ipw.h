
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
==================================================================================================*/

#ifndef PCIE_IPW_H
#define PCIE_IPW_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pcie_Ipw_Types.h"
#include "Pcie_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           template_h.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IPW_VENDOR_ID                    43
#define PCIE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_IPW_AR_RELEASE_MINOR_VERSION     4
#define PCIE_IPW_AR_RELEASE_REVISION_VERSION  0
#define PCIE_IPW_SW_MAJOR_VERSION             4
#define PCIE_IPW_SW_MINOR_VERSION             0
#define PCIE_IPW_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pcie IPW types header file are of the same vendor */
#if (PCIE_IPW_TYPES_VENDOR_ID != PCIE_IPW_VENDOR_ID)
#error "Pcie_Ipw.h and Pcie_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie IPW types header file are of the same Autosar version */
#if ((PCIE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != PCIE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != PCIE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != PCIE_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ipw.h and Pcie_Ipw_Types.h are different"
#endif
/* Check if current file and Pcie IPW types header file are of the same software version */
#if ((PCIE_IPW_TYPES_SW_MAJOR_VERSION != PCIE_IPW_SW_MAJOR_VERSION) || \
     (PCIE_IPW_TYPES_SW_MINOR_VERSION != PCIE_IPW_SW_MINOR_VERSION) || \
     (PCIE_IPW_TYPES_SW_PATCH_VERSION != PCIE_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ipw.h and Pcie_Ipw_Types.h are different"
#endif

/* Check if current file and Pcie types header file are of the same vendor */
#if (PCIE_TYPES_VENDOR_ID != PCIE_IPW_VENDOR_ID)
#error "Pcie_Ipw.h and Pcie_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_TYPES_AR_RELEASE_MAJOR_VERSION    != PCIE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_TYPES_AR_RELEASE_MINOR_VERSION    != PCIE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_TYPES_AR_RELEASE_REVISION_VERSION != PCIE_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ipw.h and Pcie_Types.h are different"
#endif
/* Check if current file and Pcie types header file are of the same software version */
#if ((PCIE_TYPES_SW_MAJOR_VERSION != PCIE_IPW_SW_MAJOR_VERSION) || \
     (PCIE_TYPES_SW_MINOR_VERSION != PCIE_IPW_SW_MINOR_VERSION) || \
     (PCIE_TYPES_SW_PATCH_VERSION != PCIE_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ipw.h and Pcie_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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

/* Initializtion of PCIe device */
void Pcie_Ipw_InitChannel(const uint8 instance, const Pcie_Ipw_HwChannelConfigType * ConfigPtr);
/* Creates an outbound address translation region */
Std_ReturnType Pcie_Ipw_SetOutboundRegion(uint8 instance, const Pcie_OutRegDescriptorType *outRegDesc);
/* Reads data through DMA */
Pcie_StatusType Pcie_Ipw_DmaRead(uint8 instance, uint8 channel, const Pcie_DmaReadDescriptorType *readDesc);
/* Enables DMA read interrupt */
Std_ReturnType Pcie_Ipw_DmaReadIntEnable(uint8 instance, uint8 channel, boolean enable);
/* Checks the status of a DMA read */
Pcie_StatusType Pcie_Ipw_DmaCheckReadStatus(uint8 instance, uint8 channel, uint32 *transfersLeft);
/* Writes data through DMA */
Pcie_StatusType Pcie_Ipw_DmaWrite(uint8 instance, uint8 channel, const Pcie_DmaWriteDescriptorType *writeDesc);
/* Enables DMA write interrupt */
Std_ReturnType Pcie_Ipw_DmaWriteIntEnable(uint8 instance, uint8 channel, boolean enable);
/* Checks the status of a DMA write */
Pcie_StatusType Pcie_Ipw_DmaCheckWriteStatus(uint8 instance, uint8 channel, uint32 *transfersLeft);
/* Triggers an MSI interrupt */
Std_ReturnType Pcie_Ipw_SendMsi(uint8 instance, uint32 intNo);
/* Triggers an MSI-X interrupt */
Std_ReturnType Pcie_Ipw_SendMsiX(uint8 instance, uint32 intNo);
/* Prepares a DMA read channel for linked list operation */
Std_ReturnType Pcie_Ipw_DmaLlReadSetup(uint8 instance, uint8 channel, Pcie_DmaLlElementType *llPtr, uint32 size);
/* Prepares a DMA write channel for linked list operation */
Std_ReturnType Pcie_Ipw_DmaLlWriteSetup(uint8 instance, uint8 channel, Pcie_DmaLlElementType *llPtr, uint32 size);

#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
