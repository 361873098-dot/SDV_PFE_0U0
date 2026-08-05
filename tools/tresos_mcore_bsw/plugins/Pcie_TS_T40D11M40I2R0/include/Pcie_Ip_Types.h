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

#ifndef PCIE_IP_TYPES_H
#define PCIE_IP_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           template_h.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IP_TYPES_VENDOR_ID                    43
#define PCIE_IP_TYPES_MODULE_ID                    255
#define PCIE_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_IP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define PCIE_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define PCIE_IP_TYPES_SW_MAJOR_VERSION             4
#define PCIE_IP_TYPES_SW_MINOR_VERSION             0
#define PCIE_IP_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pcie_Ip_Types.h file and Mcal.h header file are of the same Autosar version */
    #if ((PCIE_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie_Ip_Types.h and Mcal.h are different"
    #endif
    /* Check if Pcie_Ip_Types.h file and Std_Types.h header file are of the same Autosar version */
    #if ((PCIE_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie_Ip_Types.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** @brief  Total number of PCIe BAR registers */
#define PCIE_IP_NUMBER_OF_BARS                    (6U)

/** @brief  Pcie BAR properties */
#define PCIE_IP_BAR_TYPE_PREFETCHABLE       (1U << 3U)
#define PCIE_IP_BAR_TYPE_64BIT              (1U << 2U)
#define PCIE_IP_BAR_TYPE_IO                 (1U << 0U)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

typedef  enum
{
    PCIE_IP_SUCCESS = 0, 
    PCIE_IP_ERROR,
    PCIE_IP_BUSY
}Pcie_Ip_StatusType;

typedef void (*Pcie_DmaDoneHandlerPtrType)(uint8 instance, uint8 channel, uint16 transferId);
typedef void (*Pcie_DmaErrorHandlerPtrType)(uint8 instance, uint8 channel);


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct
{
    uint32 size;             /* Size of address space to configure in this BAR, 0 to disable. Must be a power of 2.  */
    uint32 type;             /* Type of address space in this BAR                                                    */
    uint8 (*memStart)[1U];   /* Memory address to which BAR is mapped. Must be aligned to size.                      */
} Pcie_Ip_BarConfigType;

typedef struct
{
    uint32 pcieClass;                                  /* PCIE class to configure in the PCIe header                     */
    Pcie_Ip_BarConfigType bars[PCIE_IP_NUMBER_OF_BARS];   /* Bar configurations                                             */
    uint8 msiCount;                                    /* Number o MSI interrupts to request, 0 to disable MSI           */
    boolean msixSupport;                               /* Support for MSI-X. Cannot be used at the same time as MSI      */
    Pcie_DmaDoneHandlerPtrType dmaReadDoneHandler;     /* Handler for DMA read done event                                */
    Pcie_DmaErrorHandlerPtrType dmaReadErrorHandler;   /* Handler for DMA read error event                               */
    Pcie_DmaDoneHandlerPtrType dmaWriteDoneHandler;    /* Handler for DMA write done event                               */
    Pcie_DmaErrorHandlerPtrType dmaWriteErrorHandler;  /* Handler for DMA write error event                              */
} Pcie_Ip_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*PCIE_IP_TYPES_H*/

/** @} */

