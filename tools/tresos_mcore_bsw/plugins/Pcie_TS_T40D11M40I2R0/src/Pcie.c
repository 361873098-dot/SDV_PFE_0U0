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
* @file           Pcie.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#include "Pcie.h"

#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Pcie.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_VENDOR_ID_C                      43
#define PCIE_AR_RELEASE_MAJOR_VERSION_C       4
#define PCIE_AR_RELEASE_MINOR_VERSION_C       4
#define PCIE_AR_RELEASE_REVISION_VERSION_C    0
#define PCIE_SW_MAJOR_VERSION_C               4
#define PCIE_SW_MINOR_VERSION_C               0
#define PCIE_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pcie header file are of the same vendor */
#if (PCIE_VENDOR_ID_C != PCIE_VENDOR_ID)
    #error "Pcie.c and Pcie.h have different vendor ids"
#endif
/* Check if current file and Pcie header file are of the same Autosar version */
#if ((PCIE_AR_RELEASE_MAJOR_VERSION_C    != PCIE_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_AR_RELEASE_MINOR_VERSION_C    != PCIE_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_AR_RELEASE_REVISION_VERSION_C != PCIE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie.c and Pcie.h are different"
#endif
/* Check if current file and Pcie header file are of the same Software version */
#if ((PCIE_SW_MAJOR_VERSION_C != PCIE_SW_MAJOR_VERSION) || \
     (PCIE_SW_MINOR_VERSION_C != PCIE_SW_MINOR_VERSION) || \
     (PCIE_SW_PATCH_VERSION_C != PCIE_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie.c and Pcie.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((PCIE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (PCIE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Pcie.c and Det.h are different"
        #endif
    #endif
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
#define PCIE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE

#include "Pcie_MemMap.h"

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
static const Pcie_ConfigType * Pcie_apConfig[PCIE_MAX_CORE_ID];

#define PCIE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE

#include "Pcie_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"

#if (PCIE_DEV_ERROR_DETECT == STD_ON)
static boolean Pcie_CheckBars(const Pcie_Ipw_HwChannelConfigType * ConfigPtr)
{
    uint8 barCnt;
    boolean retVal = TRUE;
    uint32 barSize;
    uint32 barAddr;

    /* loop through all BARs */
    for (barCnt = 0U; barCnt < PCIE_IP_NUMBER_OF_BARS; barCnt++)
    {
        barSize = ConfigPtr->PcieHwConfig->bars[barCnt].size;
        barAddr = (uint32)(ConfigPtr->PcieHwConfig->bars[barCnt].memStart);
        if ((barSize > 0U) && ((barAddr & (barSize - 1U)) != 0U))
        {
            retVal = FALSE;
        }
    }

    return retVal;
}
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS

==================================================================================================*/

/*================================================================================================*/

/**
 * @brief           Initializtion of PCIe driver.
 * @details         Configures and enables all PCIe instances specified in the configuration structure.
 *
 * @param[in]        Config          PCIe configuration structure.
 *
 * @implements       Pcie_Init_Activity
 *
 */
void Pcie_Init(const Pcie_ConfigType * Config)
{
    uint8 ChLoop;
    uint8 CoreId;
    const Pcie_ConfigType *PcieConfig;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    boolean initOk = TRUE;
    /* Check whether the Pcie driver is already initialized */
    if (NULL_PTR != Pcie_apConfig[CoreId])
    {
        /* PCIE driver already initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_INIT_ID, (uint8)PCIE_E_INIT_DONE);
    }
    else if (NULL_PTR != Config)
    {
        /* Invalid pointer */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_INIT_ID, (uint8)PCIE_E_INVALID_PARAM);
    }
    else if ((NULL_PTR == Pcie_PBCfgVariantPredefined[CoreId]) || (CoreId != Pcie_PBCfgVariantPredefined[CoreId]->CoreId))
    {
        /* Invalid core Id */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_INIT_ID, (uint8)PCIE_E_PARAM_CONFIG);
    }
    else
    {
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
        PcieConfig = Pcie_PBCfgVariantPredefined[CoreId];
        (void)Config;

        /* initialization of PCIe channels */
        for (ChLoop = (uint8)0U; ChLoop < PCIE_HW_MAX_CONFIG; ChLoop++)
        {
            /* check if the current channel is assigned to this core */
            if ((*(PcieConfig->Pcie_HwConfig))[ChLoop].CoreId == CoreId)
            {
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
                if (Pcie_CheckBars((*(PcieConfig->Pcie_HwConfig))[ChLoop].HwChannelConfig) != TRUE)
                {
                    /* Invalid BAR settings */
                    (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_INIT_ID, (uint8)PCIE_E_INVALID_PARAM);
                    initOk = FALSE;
                    break;
                }
                else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
                {
                    Pcie_Ipw_InitChannel((*(PcieConfig->Pcie_HwConfig))[ChLoop].Pcie_HwUnit, (*(PcieConfig->Pcie_HwConfig))[ChLoop].HwChannelConfig);
                }
            }
        }
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
        if (TRUE == initOk)
        {
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
            /* Store config for later use. This also marks the driver as initialized */
            Pcie_apConfig[CoreId] = PcieConfig;
            /* Add an unnecessary code in order to avoid the compiler warning. */
            (void)Pcie_apConfig;
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
}


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
Std_ReturnType Pcie_SetOutboundRegion(uint8 instance,
                                      const Pcie_OutRegDescriptorType *outboundRegion)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SETOUTBOUNDREGION_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SETOUTBOUNDREGION_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SETOUTBOUNDREGION_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else if (NULL_PTR == outboundRegion)
    {
        /* Invalid outbound region descriptor */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SETOUTBOUNDREGION_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if (outboundRegion->regNo >= PCIE_IATU_OUTBOUND_REGIONS_COUNT)
    {
        /* Invalid outbound region number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SETOUTBOUNDREGION_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if (((outboundRegion->srcAddr & (PCIE_IATU_REGIONS_ALIGN - 1U)) != 0U) ||
             ((outboundRegion->srcAddrLim & (PCIE_IATU_REGIONS_ALIGN - 1U)) != 0U) ||
             ((outboundRegion->dstAddr & (PCIE_IATU_REGIONS_ALIGN - 1U)) != 0U))
    {
        /* Invalid outbound region start/end/target address - 4 kB alignment is required */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SETOUTBOUNDREGION_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_SetOutboundRegion((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, outboundRegion);
    }
    return status;
}
#endif /* PCIE_SET_OUTBOUND_REGION_API == STD_ON */


#if (PCIE_DMA_READ_API == STD_ON)
/**
 * @brief           Reads data through DMA.
 * @details         Initiates an asynchronous read through DMA. Pcie_DmaCheckReadStatus must be called to check if the read is complete.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[in]        readDesc          pointer to DMA read descriptor.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaRead_Activity
 *
 */
Pcie_StatusType Pcie_DmaRead(uint8 instance,
                             uint8 channel,
                             const Pcie_DmaReadDescriptorType *readDesc)
{
    Pcie_StatusType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREAD_ID, (uint8)PCIE_E_UNINIT);
        status = PCIE_ERROR;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREAD_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREAD_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = PCIE_ERROR;
    }
    else if (channel >= PCIE_DMA_READ_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREAD_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if (NULL_PTR == readDesc)
    {
        /* Invalid descriptor pointer */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREAD_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if (0U == readDesc->size)
    {
        /* Invalid size */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREAD_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaRead((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, readDesc);
    }
    return status;
}
#endif /* PCIE_DMA_READ_API == STD_ON */


#if (PCIE_DMA_READ_INT_ENABLE_API == STD_ON)
/**
 * @brief           Enables DMA read interrupt.
 * @details         Enables DMA read interrupt. The interrupt will be triggered when the operation is complete.
 *                  Pcie_DmaCheckReadStatus must be called inside the interrupt routine to clear the status flag.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[in]        enable            TRUE to enable interrupts, FALSE to disable.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaReadIntEnable_Activity
 *
 */
Std_ReturnType Pcie_DmaReadIntEnable(uint8 instance,
                                     uint8 channel,
                                     boolean enable)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREADINTENABLE_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREADINTENABLE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREADINTENABLE_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else if (channel >= PCIE_DMA_READ_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAREADINTENABLE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaReadIntEnable((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, enable);
    }
    return status;
}
#endif /* PCIE_DMA_READ_INT_ENABLE_API == STD_ON */



#if (PCIE_DMA_CHECK_READ_STATUS_API == STD_ON)
/**
 * @brief           Checks the status of a DMA read.
 * @details         Checks the status of previously started DMA read. Also clears any status flags in case the read is completed.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[out]       transfersLeft     Number of transfers remaining in the queue.
 *
 * @return           Pcie_StatusType
 * @retval           PCIE_SUCCESS           Read operation was successfully completed.
 * @retval           PCIE_BUSY              Driver busy with a previous operation.
 * @retval           PCIE_ERROR             PCIe device reported an error, operation failed.
 *
 * @implements       Pcie_DmaCheckReadStatus_Activity
 *
 */
Pcie_StatusType Pcie_DmaCheckReadStatus(uint8 instance,
                                        uint8 channel,
                                        uint32 *transfersLeft)
{
    Pcie_StatusType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKREADSTATUS_ID, (uint8)PCIE_E_UNINIT);
        status = PCIE_ERROR;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKREADSTATUS_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKREADSTATUS_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = PCIE_ERROR;
    }
    else if (channel >= PCIE_DMA_READ_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKREADSTATUS_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaCheckReadStatus((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, transfersLeft);
    }
    return status;
}
#endif /* PCIE_DMA_CHECK_READ_STATUS_API == STD_ON */


#if (PCIE_DMA_WRITE_API == STD_ON)
/**
 * @brief           Writes data through DMA.
 * @details         Initiates an asynchronous write through DMA. Pcie_DmaCheckWriteStatus must be called to check if the write is complete.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[in]        writeDesc         pointer to DMA write descriptor.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaWrite_Activity
 *
 */
Pcie_StatusType Pcie_DmaWrite(uint8 instance,
                              uint8 channel,
                              const Pcie_DmaWriteDescriptorType *writeDesc)
{
    Pcie_StatusType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITE_ID, (uint8)PCIE_E_UNINIT);
        status = PCIE_ERROR;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITE_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = PCIE_ERROR;
    }
    else if (channel >= PCIE_DMA_WRITE_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if (NULL_PTR == writeDesc)
    {
        /* Invalid descriptor pointer */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if (writeDesc->size == 0U)
    {
        /* Invalid size */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaWrite((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, writeDesc);
    }
    return status;
}
#endif /* PCIE_DMA_WRITE_API == STD_ON */


#if (PCIE_DMA_WRITE_INT_ENABLE_API == STD_ON)
/**
 * @brief           Enables DMA write interrupt.
 * @details         Enables DMA write interrupt. The interrupt will be triggered when the operation is complete.
 *                  Pcie_DmaCheckWriteStatus must be called inside the interrupt routine to clear the status flag.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[in]        enable            TRUE to enable interrupts, FALSE to disable.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaWriteIntEnable_Activity
 *
 */
Std_ReturnType Pcie_DmaWriteIntEnable(uint8 instance,
                                      uint8 channel,
                                      boolean enable)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITEINTENABLE_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITEINTENABLE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITEINTENABLE_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else if (channel >= PCIE_DMA_WRITE_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMAWRITEINTENABLE_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaWriteIntEnable((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, enable);
    }
    return status;
}
#endif /* PCIE_DMA_WRITE_INT_ENABLE_API == STD_ON */



#if (PCIE_DMA_CHECK_WRITE_STATUS_API == STD_ON)
/**
 * @brief           Checks the status of a DMA write.
 * @details         Checks the status of previously started DMA write. Also clears any status flags in case the write is completed.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[out]       transfersLeft     Number of transfers remaining in the queue.
 *
 * @return           Pcie_StatusType
 * @retval           PCIE_SUCCESS           Write operation was successfully completed.
 * @retval           PCIE_BUSY              Driver busy with a previous operation.
 * @retval           PCIE_ERROR             PCIe device reported an error, operation failed.
 *
 * @implements       Pcie_DmaCheckWriteStatus_Activity
 *
 */
Pcie_StatusType Pcie_DmaCheckWriteStatus(uint8 instance,
                                         uint8 channel,
                                         uint32 *transfersLeft)
{
    Pcie_StatusType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKWRITESTATUS_ID, (uint8)PCIE_E_UNINIT);
        status = PCIE_ERROR;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKWRITESTATUS_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKWRITESTATUS_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = PCIE_ERROR;
    }
    else if (channel >= PCIE_DMA_WRITE_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMACHECKWRITESTATUS_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = PCIE_ERROR;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaCheckWriteStatus((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, transfersLeft);
    }
    return status;
}
#endif /* PCIE_DMA_CHECK_WRITE_STATUS_API == STD_ON */


#if (PCIE_SEND_MSI_API == STD_ON)
/**
 * @brief           Triggers an MSI interrupt.
 * @details         Triggers an MSI interrupt if MSI interrupts are enabled for this device.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        intNo             MSI interrupt number.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_SendMsi_Activity
 *
 */
Std_ReturnType Pcie_SendMsi(uint8 instance,
                            uint32 intNo)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSI_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSI_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSI_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_SendMsi((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, intNo);
    }
    return status;
}
#endif /* PCIE_SEND_MSI_API == STD_ON */


#if (PCIE_SEND_MSI_X_API == STD_ON)
/**
 * @brief           Triggers an MSI-X interrupt.
 * @details         Triggers an MSI-X interrupt if MSI-X interrupts are enabled for this device.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        intNo             MSI-X interrupt number.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_SendMsiX_Activity
 *
 */
Std_ReturnType Pcie_SendMsiX(uint8 instance,
                             uint32 intNo)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSIX_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSIX_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSIX_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else if (intNo >= PCIE_MSIX_COUNT)
    {
        /* Invalid msi-x interrupt number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_SENDMSIX_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_SendMsiX((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, intNo);
    }
    return status;
}
#endif /* PCIE_SEND_MSI_X_API == STD_ON */


#if (PCIE_DMA_LL_READ_SETUP_API == STD_ON)
/**
 * @brief           Prepares a DMA read channel for linked list operation.
 * @details         Prepares a DMA read channel for linked list operation using the memory array provided by the application for the linked list.
 *                  After this function succesfully completes, Pcie_DmaRead can be used to queue read operations.
 *                  If interrupts are used, Pcie_DmaReadIntEnable must be used to enable interrupts.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[in]        llPtr             Pointer to an array of linked list elements.
 * @param[in]        size              Size of the array of linked list elements. Includes Link element, so maximum number of transfers which can be queued is size - 1
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaLlReadSetup_Activity
 *
 */
Std_ReturnType Pcie_DmaLlReadSetup(uint8 instance,
                                   uint8 channel,
                                   Pcie_DmaLlElementType *llPtr,
                                   uint32 size)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLREADSETUP_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLREADSETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLREADSETUP_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else if (channel >= PCIE_DMA_READ_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLREADSETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if (NULL_PTR == llPtr)
    {
        /* Invalid list pointer */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLREADSETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if (size <= 3U)
    {
        /* Invalid list size. There must be at least three data elements plus the link element */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLREADSETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaLlReadSetup((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, llPtr, size);
    }
    return status;
}
#endif /* PCIE_DMA_LL_READ_SETUP_API == STD_ON */


#if (PCIE_DMA_LL_WRITE_SETUP_API == STD_ON)
/**
 * @brief           Prepares a DMA write channel for linked list operation.
 * @details         Prepares a DMA write channel for linked list operation using the memory array provided by the application for the linked list.
 *                  After this function succesfully completes, Pcie_DmaWrite can be used to queue write operations.
 *                  If interrupts are used, Pcie_DmaWriteIntEnable must be used to enable interrupts.
 *
 * @param[in]        instance          PCIe instance number.
 * @param[in]        channel           DMA channel number.
 * @param[in]        llPtr             Pointer to an array of linked list elements.
 * @param[in]        size              Size of the array of linked list elements. Includes Link element, so maximum number of transfers which can be queued is size - 1
 *
 * @return           Std_ReturnType
 * @retval           E_OK                 Operation was successful.
 * @retval           E_NOT_OK             Operation failed.
 *
 * @implements       Pcie_DmaLlWriteSetup_Activity
 *
 */
Std_ReturnType Pcie_DmaLlWriteSetup(uint8 instance,
                                    uint8 channel,
                                    Pcie_DmaLlElementType *llPtr,
                                    uint32 size)
{
    Std_ReturnType status;
    uint8 CoreId;

    CoreId = (uint8) Pcie_GetCoreID();
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Pcie driver is initialized */
    if (NULL_PTR == Pcie_apConfig[CoreId])
    {
        /* PCIE driver not initialized */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLWRITESETUP_ID, (uint8)PCIE_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (instance >= PCIE_HW_MAX_CONFIG)
    {
        /* Invalid instance number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLWRITESETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if ((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].CoreId != CoreId)
    {
        /* Instance not allocated for this core */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLWRITESETUP_ID, (uint8)PCIE_E_PARAM_CONFIG);
        status = E_NOT_OK;
    }
    else if (channel >= PCIE_DMA_WRITE_CHANNELS_COUNT)
    {
        /* Invalid DMA channel number */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLWRITESETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if (NULL_PTR == llPtr)
    {
        /* Invalid list pointer */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLWRITESETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else if (size <= 3U)
    {
        /* Invalid list size. There must be at least three data elements plus the link element */
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_DMALLWRITESETUP_ID, (uint8)PCIE_E_INVALID_PARAM);
        status = E_NOT_OK;
    }
    else
#endif /* (PCIE_DEV_ERROR_DETECT == STD_ON) */
    {
        /* call IPW function */
        status = Pcie_Ipw_DmaLlWriteSetup((*(Pcie_apConfig[CoreId]->Pcie_HwConfig))[instance].Pcie_HwUnit, channel, llPtr, size);
    }
    return status;
}
#endif /* PCIE_DMA_LL_WRITE_SETUP_API == STD_ON */

#if (PCIE_VERSION_INFO_API == STD_ON)

/*FUNCTION**********************************************************************
 *
 * Function Name : Pcie_GetVersionInfo
 * Description   : Gets the version information of this module.
 *
 *END**************************************************************************/
void Pcie_GetVersionInfo (Std_VersionInfoType * VersionInfo)
{
#if (PCIE_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)PCIE_MODULE_ID, (uint8)0U, (uint8)PCIE_GETVERSIONINFO_ID, (uint8) PCIE_E_INVALID_PARAM);
    }
    else
#endif /* PCIE_DEV_ERROR_DETECT == STD_ON */
    {
        (VersionInfo)->vendorID = (uint16) PCIE_VENDOR_ID;
        (VersionInfo)->moduleID = (uint16) PCIE_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8) PCIE_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8) PCIE_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8) PCIE_SW_PATCH_VERSION;
    }
}
#endif /* PCIE_VERSION_INFO_API == STD_ON */

#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
