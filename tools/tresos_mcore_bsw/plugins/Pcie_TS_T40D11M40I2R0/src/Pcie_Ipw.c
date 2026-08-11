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

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Pcie_Ipw.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#include "Pcie_Ipw.h"
#include "Pcie_Types.h"
#include "Pcie_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Pcie_Ipw.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IPW_VENDOR_ID_C                      43
#define PCIE_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define PCIE_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define PCIE_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define PCIE_IPW_SW_MAJOR_VERSION_C               4
#define PCIE_IPW_SW_MINOR_VERSION_C               0
#define PCIE_IPW_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pcie_Ipw header file are of the same vendor */
#if (PCIE_IPW_VENDOR_ID_C != PCIE_IPW_VENDOR_ID)
    #error "Pcie_Ipw.c and Pcie_Ipw.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ipw header file are of the same Autosar version */
#if ((PCIE_IPW_AR_RELEASE_MAJOR_VERSION_C    != PCIE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_AR_RELEASE_MINOR_VERSION_C    != PCIE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_AR_RELEASE_REVISION_VERSION_C != PCIE_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ipw.c and Pcie_Ipw.h are different"
#endif
/* Check if current file and Pcie_Ipw header file are of the same Software version */
#if ((PCIE_IPW_SW_MAJOR_VERSION_C != PCIE_IPW_SW_MAJOR_VERSION) || \
     (PCIE_IPW_SW_MINOR_VERSION_C != PCIE_IPW_SW_MINOR_VERSION) || \
     (PCIE_IPW_SW_PATCH_VERSION_C != PCIE_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ipw.c and Pcie_Ipw.h are different"
#endif

/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_IPW_AR_RELEASE_MAJOR_VERSION_C != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_AR_RELEASE_MINOR_VERSION_C != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_AR_RELEASE_REVISION_VERSION_C != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Types.h and Pcie_Ipw.c are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_IPW_SW_MAJOR_VERSION_C != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IPW_SW_MINOR_VERSION_C != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IPW_SW_PATCH_VERSION_C != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Types.h and Pcie_Ipw.c are different"
#endif
/* Check if Pcie_Types.h and Pcie_Cfg.h file are of the same vendor */
#if (PCIE_IPW_VENDOR_ID_C != PCIE_TYPES_VENDOR_ID)
    #error "Pcie_Ipw.c and Pcie_Types.h have different vendor IDs"
#endif

/* Check if current file and Pcie_Ipw header file are of the same vendor */
#if (PCIE_IPW_VENDOR_ID_C != PCIE_IP_VENDOR_ID)
    #error "Pcie_Ipw.c and Pcie_Ip.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip header file are of the same Autosar version */
#if ((PCIE_IPW_AR_RELEASE_MAJOR_VERSION_C    != PCIE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_AR_RELEASE_MINOR_VERSION_C    != PCIE_IP_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ipw.c and Pcie_Ip.h are different"
#endif
/* Check if current file and Pcie_Ip header file are of the same Software version */
#if ((PCIE_IPW_SW_MAJOR_VERSION_C != PCIE_IP_SW_MAJOR_VERSION) || \
     (PCIE_IPW_SW_MINOR_VERSION_C != PCIE_IP_SW_MINOR_VERSION) || \
     (PCIE_IPW_SW_PATCH_VERSION_C != PCIE_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ipw.c and Pcie_Ip.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/* Initializtion of PCIe device */
void Pcie_Ipw_InitChannel(const uint8 instance,
                          const Pcie_Ipw_HwChannelConfigType * ConfigPtr)
{
    Pcie_Ip_Init(instance, ConfigPtr->PcieHwConfig);
}


/* Creates an outbound address translation region */
Std_ReturnType Pcie_Ipw_SetOutboundRegion(uint8 instance,
                                          const Pcie_OutRegDescriptorType *outRegDesc)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_SetOutboundRegion(instance, outRegDesc);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}

/* Reads data through DMA */
Pcie_StatusType Pcie_Ipw_DmaRead(uint8 instance,
                                 uint8 channel,
                                 const Pcie_DmaReadDescriptorType *readDesc)
{
    Pcie_Ip_StatusType Status;
    Pcie_StatusType StdStatus = PCIE_ERROR;

    Status = Pcie_Ip_DmaRead(instance, channel, readDesc);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = PCIE_SUCCESS;
    }
    else if (PCIE_IP_BUSY == Status)
    {
        StdStatus = PCIE_BUSY;
    }
    else
    {
        /* StdStatus remains PCIE_ERROR */
    }

    return StdStatus;
}


/* Enables DMA read interrupt */
Std_ReturnType Pcie_Ipw_DmaReadIntEnable(uint8 instance,
                                         uint8 channel,
                                         boolean enable)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_DmaReadIntEnable(instance, channel, enable);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}


/* Checks the status of a DMA read */
Pcie_StatusType Pcie_Ipw_DmaCheckReadStatus(uint8 instance,
                                            uint8 channel,
                                            uint32 *transfersLeft)
{
    Pcie_Ip_StatusType Status;
    Pcie_StatusType StdStatus = PCIE_ERROR;

    Status = Pcie_Ip_DmaCheckReadStatus(instance, channel, transfersLeft);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = PCIE_SUCCESS;
    }
    else if (PCIE_IP_BUSY == Status)
    {
        StdStatus = PCIE_BUSY;
    }
    else
    {
        /* StdStatus remains PCIE_ERROR */
    }

    return StdStatus;
}


/* Writes data through DMA */
Pcie_StatusType Pcie_Ipw_DmaWrite(uint8 instance,
                                  uint8 channel,
                                  const Pcie_DmaWriteDescriptorType *writeDesc)
{
    Pcie_Ip_StatusType Status;
    Pcie_StatusType StdStatus = PCIE_ERROR;

    Status = Pcie_Ip_DmaWrite(instance, channel, writeDesc);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = PCIE_SUCCESS;
    }
    else if (PCIE_IP_BUSY == Status)
    {
        StdStatus = PCIE_BUSY;
    }
    else
    {
        /* StdStatus remains PCIE_ERROR */
    }

    return StdStatus;
}

/* Enables DMA write interrupt */
Std_ReturnType Pcie_Ipw_DmaWriteIntEnable(uint8 instance,
                                          uint8 channel,
                                          boolean enable)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_DmaWriteIntEnable(instance, channel, enable);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}

/* Checks the status of a DMA write */
Pcie_StatusType Pcie_Ipw_DmaCheckWriteStatus(uint8 instance, 
                                             uint8 channel, 
                                             uint32 *transfersLeft)
{
    Pcie_Ip_StatusType Status;
    Pcie_StatusType StdStatus = PCIE_ERROR;

    Status = Pcie_Ip_DmaCheckWriteStatus(instance, channel, transfersLeft);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = PCIE_SUCCESS;
    }
    else if (PCIE_IP_BUSY == Status)
    {
        StdStatus = PCIE_BUSY;
    }
    else
    {
        /* StdStatus remains PCIE_ERROR */
    }

    return StdStatus;
}


/* Triggers an MSI interrupt */
Std_ReturnType Pcie_Ipw_SendMsi(uint8 instance,
                                uint32 intNo)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_SendMsi(instance, intNo);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}

/* Triggers an MSI-X interrupt */
Std_ReturnType Pcie_Ipw_SendMsiX(uint8 instance,
                                 uint32 intNo)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_SendMsiX(instance, intNo);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}

/* Prepares a DMA read channel for linked list operation */
Std_ReturnType Pcie_Ipw_DmaLlReadSetup(uint8 instance, 
                                       uint8 channel, 
                                       Pcie_DmaLlElementType *llPtr, 
                                       uint32 size)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_DmaLlReadSetup(instance, channel, llPtr, size);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}


/* Prepares a DMA write channel for linked list operation */
Std_ReturnType Pcie_Ipw_DmaLlWriteSetup(uint8 instance,
                                        uint8 channel,
                                        Pcie_DmaLlElementType *llPtr, uint32 size)
{
    Pcie_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Pcie_Ip_DmaLlWriteSetup(instance, channel, llPtr, size);

    if (PCIE_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}



#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
