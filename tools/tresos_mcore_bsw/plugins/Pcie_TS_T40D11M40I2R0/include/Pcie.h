/**
*   @file    Pcie.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Pcie - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup PCIE_DRIVER
*   @{
*/
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

#ifndef PCIE_H
#define PCIE_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "Pcie_Types.h"
#include "Pcie_Ipw.h"
#include "Pcie_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PCIE_VENDOR_ID                    43
#define PCIE_MODULE_ID                    255
#define PCIE_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_AR_RELEASE_MINOR_VERSION     4
#define PCIE_AR_RELEASE_REVISION_VERSION  0
#define PCIE_SW_MAJOR_VERSION             4
#define PCIE_SW_MINOR_VERSION             0
#define PCIE_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pcie.h file and Mcal.h header file are of the same Autosar version */
    #if ((PCIE_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie.h and Mcal.h are different"
    #endif
#endif

/* Check if current file and Pcie configuration header file are of the same vendor */
#if (PCIE_VENDOR_ID != PCIE_CFG_VENDOR_ID)
#error "Pcie.h and Pcie_Cfg.h have different vendor ids"
#endif
/* Check if current file and Pcie configuration header file are of the same Autosar version */
#if ((PCIE_AR_RELEASE_MAJOR_VERSION    != PCIE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_AR_RELEASE_MINOR_VERSION    != PCIE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_AR_RELEASE_REVISION_VERSION != PCIE_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie.h and Pcie_Cfg.h are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_SW_MAJOR_VERSION != PCIE_CFG_SW_MAJOR_VERSION) || \
     (PCIE_SW_MINOR_VERSION != PCIE_CFG_SW_MINOR_VERSION) || \
     (PCIE_SW_PATCH_VERSION != PCIE_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie.h and Pcie_Cfg.h are different"
#endif

/* Check if current file and Pcie IPW header file are of the same vendor */
#if (PCIE_VENDOR_ID != PCIE_IPW_VENDOR_ID)
#error "Pcie.h and Pcie_Ipw.h have different vendor ids"
#endif
/* Check if current file and Pcie configuration header file are of the same Autosar version */
#if ((PCIE_AR_RELEASE_MAJOR_VERSION    != PCIE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_AR_RELEASE_MINOR_VERSION    != PCIE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_AR_RELEASE_REVISION_VERSION != PCIE_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie.h and Pcie_Ipw.h are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_SW_MAJOR_VERSION != PCIE_IPW_SW_MAJOR_VERSION) || \
     (PCIE_SW_MINOR_VERSION != PCIE_IPW_SW_MINOR_VERSION) || \
     (PCIE_SW_PATCH_VERSION != PCIE_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie.h and Pcie_Ipw.h are different"
#endif

/* Check if current file and Pcie types header file are of the same vendor */
#if (PCIE_VENDOR_ID != PCIE_TYPES_VENDOR_ID)
#error "Pcie.h and Pcie_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie configuration header file are of the same Autosar version */
#if ((PCIE_AR_RELEASE_MAJOR_VERSION    != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_AR_RELEASE_MINOR_VERSION    != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_AR_RELEASE_REVISION_VERSION != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie.h and Pcie_Types.h are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_SW_MAJOR_VERSION != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_SW_MINOR_VERSION != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_SW_PATCH_VERSION != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie.h and Pcie_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#if (PCIE_DEV_ERROR_DETECT == STD_ON)

/** @brief  Driver already initialized */
#define PCIE_E_INIT_DONE       ((uint8)0x01U)
/** @brief  Driver not yet initialized  */
#define PCIE_E_UNINIT          ((uint8)0x02U)
/** @brief  API service called with invalid parameter */
#define PCIE_E_INVALID_PARAM   ((uint8)0x03U)
/** @brief  Invalid configuration */
#define PCIE_E_PARAM_CONFIG    ((uint8)0x04U)


/** @brief  Service ID for Pcie_Init() function  */
#define PCIE_INIT_ID                        ((uint8)0x00U)
/** @brief  Service ID for Pcie_SetOutboundRegion() function  */
#define PCIE_SETOUTBOUNDREGION_ID           ((uint8)0x01U)
/** @brief  Service ID for Pcie_DmaRead() function  */
#define PCIE_DMAREAD_ID                     ((uint8)0x02U)
/** @brief  Service ID for Pcie_DmaReadIntEnable() function  */
#define PCIE_DMAREADINTENABLE_ID            ((uint8)0x03U)
/** @brief  Service ID for Pcie_DmaCheckReadStatus() function  */
#define PCIE_DMACHECKREADSTATUS_ID          ((uint8)0x04U)
/** @brief  Service ID for Pcie_DmaWrite() function  */
#define PCIE_DMAWRITE_ID                    ((uint8)0x05U)
/** @brief  Service ID for Pcie_DmaWriteIntEnable() function  */
#define PCIE_DMAWRITEINTENABLE_ID           ((uint8)0x06U)
/** @brief  Service ID for Pcie_DmaCheckWriteStatus() function  */
#define PCIE_DMACHECKWRITESTATUS_ID         ((uint8)0x07U)
/** @brief  Service ID for Pcie_SendMsi() function  */
#define PCIE_SENDMSI_ID                     ((uint8)0x08U)
/** @brief  Service ID for Pcie_SendMsiX() function  */
#define PCIE_SENDMSIX_ID                    ((uint8)0x09U)
/** @brief  Service ID for Pcie_DmaLlReadSetup() function  */
#define PCIE_DMALLREADSETUP_ID              ((uint8)0x0AU)
/** @brief  Service ID for Pcie_DmaLlWriteSetup() function  */
#define PCIE_DMALLWRITESETUP_ID             ((uint8)0x0BU)
#if (PCIE_VERSION_INFO_API == STD_ON)
/** @brief  Service ID for Pcie_DmaLlWriteSetup() function  */
#define PCIE_GETVERSIONINFO_ID              ((uint8)0x0CU)
#endif /* PCIE_VERSION_INFO_API == STD_ON */

/** @brief  Alignment requirement for IATU inbound/outbound regions  */
#define PCIE_IATU_REGIONS_ALIGN             ((uint32)0x1000U)

#endif /* PCIE_DEV_ERROR_DETECT == STD_ON*/


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

/**
 * @brief           Initializtion of PCIe driver.
 * @details         Configures and enables all PCIe instances specified in the configuration structure.
 *
 * @param[in]        Config          PCIe configuration structure.
 *
 * @implements       Pcie_Init_Activity
 *
 */
void Pcie_Init(const Pcie_ConfigType * Config);

#if (PCIE_SET_OUTBOUND_REGION_API == STD_ON)
/**
 * @brief           Creates an outbound address translation region.
 * @details         Creates an outbound address translation region using the internal address translation unit of the PCIe module.
 *                  Accesses in the range defined by srcAddr and srcAddrLim will be translated in a range of the same size starting from dstAddr.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        outboundRegion    pointer to IATU outbound region descripton.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_SetOutboundRegion_Activity
 *
 */
Std_ReturnType Pcie_SetOutboundRegion(uint8 instance, const Pcie_OutRegDescriptorType *outboundRegion);
#endif /* PCIE_SET_OUTBOUND_REGION_API == STD_ON */

#if (PCIE_DMA_READ_API == STD_ON)
/**
 * @brief           Reads data through DMA.
 * @details         Initiates an asynchronous read through DMA. Pcie_DmaCheckReadStatus must be called to check if the read is complete.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *                   readDesc          Transfer descriptor containing all the parameters of the transfer.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaRead_Activity
 *
 */
Pcie_StatusType Pcie_DmaRead(uint8 instance, uint8 channel, const Pcie_DmaReadDescriptorType *readDesc);
#endif /* PCIE_DMA_READ_API == STD_ON */

#if (PCIE_DMA_READ_INT_ENABLE_API == STD_ON)
/**
 * @brief           Enables DMA read interrupt.
 * @details         Enables DMA read interrupt. The interrupt will be triggered when the operation is complete.
 *                  Pcie_DmaCheckReadStatus must be called inside the interrupt routine to clear the status flag.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *                   enable            TRUE to enable interrupts, FALSE to disable.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaReadIntEnable_Activity
 *
 */
Std_ReturnType Pcie_DmaReadIntEnable(uint8 instance, uint8 channel, boolean enable);
#endif /* PCIE_DMA_READ_INT_ENABLE_API == STD_ON */


#if (PCIE_DMA_CHECK_READ_STATUS_API == STD_ON)
/**
 * @brief           Checks the status of a DMA read.
 * @details         Checks the status of previously started DMA read. Also clears any status flags in case the read is completed.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *
 * @return           Pcie_StatusType
 * @retval           PCIE_SUCCESS           Read operation was successfully completed.
 * @retval           PCIE_BUSY              Driver busy with a previous operation.
 * @retval           PCIE_ERROR             PCIe device reported an error, operation failed.
 *
 * @implements       Pcie_DmaCheckReadStatus_Activity
 *
 */
Pcie_StatusType Pcie_DmaCheckReadStatus(uint8 instance, uint8 channel, uint32 *transfersLeft);
#endif /* PCIE_DMA_CHECK_READ_STATUS_API == STD_ON */

#if (PCIE_DMA_WRITE_API == STD_ON)
/**
 * @brief           Writes data through DMA.
 * @details         Initiates an asynchronous write through DMA. Pcie_DmaCheckWriteStatus must be called to check if the write is complete.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *                   writeDesc         Transfer descriptor containing all the parameters of the transfer.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaWrite_Activity
 *
 */
Pcie_StatusType Pcie_DmaWrite(uint8 instance, uint8 channel, const Pcie_DmaWriteDescriptorType *writeDesc);
#endif /* PCIE_DMA_WRITE_API == STD_ON */

#if (PCIE_DMA_WRITE_INT_ENABLE_API == STD_ON)
/**
 * @brief           Enables DMA write interrupt..
 * @details         Enables DMA write interrupt. The interrupt will be triggered when the operation is complete.
 *                  Pcie_DmaCheckWriteStatus must be called inside the interrupt routine to clear the status flag.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *                   enable            TRUE to enable interrupts, FALSE to disable.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaWriteIntEnable_Activity
 *
 */
Std_ReturnType Pcie_DmaWriteIntEnable(uint8 instance, uint8 channel, boolean enable);
#endif /* PCIE_DMA_WRITE_INT_ENABLE_API == STD_ON */


#if (PCIE_DMA_CHECK_WRITE_STATUS_API == STD_ON)
/**
 * @brief           Checks the status of a DMA write.
 * @details         Checks the status of previously started DMA write. Also clears any status flags in case the write is completed.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *
 * @return           Pcie_StatusType
 * @retval           PCIE_SUCCESS           Write operation was successfully completed.
 * @retval           PCIE_BUSY              Driver busy with a previous operation.
 * @retval           PCIE_ERROR             PCIe device reported an error, operation failed.
 *
 * @implements       Pcie_DmaCheckWriteStatus_Activity
 *
 */
Pcie_StatusType Pcie_DmaCheckWriteStatus(uint8 instance, uint8 channel, uint32 *transfersLeft);
#endif /* PCIE_DMA_CHECK_WRITE_STATUS_API == STD_ON */

#if (PCIE_SEND_MSI_API == STD_ON)
/**
 * @brief           Triggers an MSI interrupt.
 * @details         Triggers an MSI interrupt if MSI interrupts are enabled for this device.
 *
 * @param[in]        instance          PCIe instance number.
 *                   intNo             MSI interrupt number.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_SendMsi_Activity
 *
 */
Std_ReturnType Pcie_SendMsi(uint8 instance, uint32 intNo);
#endif /* PCIE_SEND_MSI_API == STD_ON */

#if (PCIE_SEND_MSI_X_API == STD_ON)
/**
 * @brief           Triggers an MSI-X interrupt.
 * @details         Triggers an MSI-X interrupt if MSI-X interrupts are enabled for this device.
 *
 * @param[in]        instance          PCIe instance number.
 *                   intNo             MSI-X interrupt number.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_SendMsiX_Activity
 *
 */
Std_ReturnType Pcie_SendMsiX(uint8 instance, uint32 intNo);
#endif /* PCIE_SEND_MSI_X_API == STD_ON */

#if (PCIE_DMA_LL_READ_SETUP_API == STD_ON)
/**
 * @brief           Prepares a DMA read channel for linked list operation.
 * @details         Prepares a DMA read channel for linked list operation using the memory array provided by the application for the linked list.
 *                  After this function succesfully completes, Pcie_DmaLlRead can be used to queue read operations.
 *                  If interrupts are used, Pcie_DmaReadIntEnable must be used to enable interrupts.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *                   llPtr             Pointer to an array of linked list elements.
 *                   size              Size of the array of linked list elements. Includes Link element, so maximum number of transfers which can be queued is size - 1
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaLlReadSetup_Activity
 *
 */
Std_ReturnType Pcie_DmaLlReadSetup(uint8 instance, uint8 channel, Pcie_DmaLlElementType *llPtr, uint32 size);
#endif /* PCIE_DMA_LL_READ_SETUP_API == STD_ON */

#if (PCIE_DMA_LL_WRITE_SETUP_API == STD_ON)
/**
 * @brief           Prepares a DMA write channel for linked list operation.
 * @details         Prepares a DMA write channel for linked list operation using the memory array provided by the application for the linked list.
 *                  After this function succesfully completes, Pcie_DmaLlWrite can be used to queue write operations.
 *                  If interrupts are used, Pcie_DmaWriteIntEnable must be used to enable interrupts.
 *
 * @param[in]        instance          PCIe instance number.
 *                   channel           DMA channel number.
 *                   llPtr             Pointer to an array of linked list elements.
 *                   size              Size of the array of linked list elements. Includes Link element, so maximum number of transfers which can be queued is size - 1
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaLlWriteSetup_Activity
 *
 */
Std_ReturnType Pcie_DmaLlWriteSetup(uint8 instance, uint8 channel, Pcie_DmaLlElementType *llPtr, uint32 size);
#endif /* PCIE_DMA_LL_WRITE_SETUP_API == STD_ON */

#if (PCIE_VERSION_INFO_API == STD_ON)
/**
 * @brief           Returns version information for the driver.
 *
 * @param[in]        VersionInfo       Driver version information.
 *
 */
void Pcie_GetVersionInfo (Std_VersionInfoType * VersionInfo);
#endif /* PCIE_VERSION_INFO_API == STD_ON */

#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*PCIE_H*/

/** @} */
