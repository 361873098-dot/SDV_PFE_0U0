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
*   @file    Spi_Ipw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Isolation level file for SPI driver.
*   @details Implementation file for function definition on isolation level between high and low level driver.
*
*   @addtogroup SPI_DRIVER Spi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spi_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID_C                       43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION_C        4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION_C        4
#define SPI_IPW_AR_RELEASE_REVISION_VERSION_C     0
#define SPI_IPW_SW_MAJOR_VERSION_C                4
#define SPI_IPW_SW_MINOR_VERSION_C                0
#define SPI_IPW_SW_PATCH_VERSION_C                2
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw.c and Spi_Ipw.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi_Ipw.c and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi_Ipw.c file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw.c and Spi_Ipw.h are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw.c and Spi_Ipw.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

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
#define   SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

extern Spi_HWUnitQueue Spi_axSpiHwUnitQueueArray[SPI_MAX_HWUNIT];

extern Spi_Ip_StateStructureType* Spi_Ip_apxStateStructureArray[SPI_INSTANCE_COUNT];
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
extern Lpspi_Ip_StateStructureType* Lpspi_Ip_apxStateStructureArray[LPSPI_INSTANCE_COUNT];
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief Mapping between Spi channel id and instance id
*/
static Spi_HWUnitType Spi_Ipw_au8SpiHWUnitMapping[SPI_INSTANCE_COUNT];

#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
/**
* @brief Mapping between Lpspi channel id and hardware unit id
*/
static Spi_HWUnitType Spi_Ipw_au8LpspiHWUnitMapping[LPSPI_INSTANCE_COUNT];
#endif
#endif
#endif

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES 
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_Ipw_CallbackSpi(uint8 Instance, Spi_Ip_EventType Event);
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
static void Spi_Ipw_CallbackLpspi(uint8 Instance, Lpspi_Ip_EventType Event);
#endif
#endif
static void Spi_Ipw_EndChannelCallback(uint8 Instance, Spi_Ipw_SupportedIpsType IpType, Spi_JobResultType JobResult);
#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
static void Spi_Ipw_SequenceDmaFastTransfer(const Spi_SequenceConfigType *SequenceConfig, uint8 HWUnit, uint32 SpiCoreID);
#endif
#endif

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
static Std_ReturnType Spi_Ipw_SyncTransmitProcess
    (
        const Spi_JobConfigType *JobConfig,
        const Spi_ChannelConfigType *ChannelConfig,
        Spi_DataBufferType *RxBuffer,
        const Spi_DataBufferType *TxBuffer
    );
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
/* Std_ReturnType Spi_Ipw_SyncTransmitProcess */
static Std_ReturnType Spi_Ipw_SyncTransmitProcess
    (
        const Spi_JobConfigType *JobConfig,
        const Spi_ChannelConfigType *ChannelConfig,
        Spi_DataBufferType *RxBuffer,
        const Spi_DataBufferType *TxBuffer
    )
{
    Spi_Ip_StatusType Spi_SpiStatus = SPI_IP_STATUS_SUCCESS;
    const Spi_Ip_ExternalDeviceType* SpiExternalDevice;
    Std_ReturnType Ipw_Status = (Std_ReturnType)E_OK;
    Spi_NumberOfDataType NumberOfBytes;
    Spi_Ipw_SupportedIpsType IpType = JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType;
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    Lpspi_Ip_StatusType Spi_LpspiStatus = LPSPI_IP_STATUS_SUCCESS;
    const Lpspi_Ip_ExternalDeviceType* Lpspi_SpiExternalDevice;
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
    Lpspi_Ip_HalfDuplexType HalfDuplexMode;
    boolean HalfDuplexModeSupport = TRUE;
    Spi_DataBufferType *Buffer;

    if (SPI_HALF_DUPLEX_TRANSMIT == ChannelConfig->HalfDuplexMode)
    {
        HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_TRANSMIT;
        Buffer = (Spi_DataBufferType*)TxBuffer;
    }
    else if (SPI_HALF_DUPLEX_RECEIVE == ChannelConfig->HalfDuplexMode)
    {
        HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_RECEIVE;
        Buffer = RxBuffer;
    }
    else
    {
        HalfDuplexMode = LPSPI_IP_FULL_DUPLEX;
        HalfDuplexModeSupport = FALSE;
    }
#endif
#endif
#endif

    NumberOfBytes = ChannelConfig->ChannelState->Length;
    if (SPI_OVER_SPI == IpType)
    {
        SpiExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.SpiExternalDeviceConfig;
        SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        Spi_SpiStatus = Spi_Ip_SyncTransmit(SpiExternalDevice, TxBuffer, RxBuffer, NumberOfBytes, SPI_TIMEOUT_COUNTER_U32);
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
        Lpspi_SpiExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.LpspiExternalDeviceConfig;
        Spi_LpspiStatus = Lpspi_Ip_UpdateDefaultTransmitData(Lpspi_SpiExternalDevice, ChannelConfig->DefaultTransmitValue);
        if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
        {
            Spi_LpspiStatus = Lpspi_Ip_UpdateFrameSize(Lpspi_SpiExternalDevice, ChannelConfig->FrameSize);
            if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
            {
                Spi_LpspiStatus = Lpspi_Ip_UpdateLsb(Lpspi_SpiExternalDevice, ChannelConfig->Lsb);
                if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
                {
                    #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
                    if(HalfDuplexModeSupport)
                    {
                        Spi_LpspiStatus = Lpspi_Ip_SyncTransmitHalfDuplex(Lpspi_SpiExternalDevice, Buffer, NumberOfBytes, HalfDuplexMode, SPI_TIMEOUT_COUNTER_U32);
                    }
                    else
                    #endif
                    {
                        Spi_LpspiStatus = Lpspi_Ip_SyncTransmit(Lpspi_SpiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, SPI_TIMEOUT_COUNTER_U32);
                    }
                }
            }
        }
    }
    
    if(LPSPI_IP_STATUS_SUCCESS != Spi_LpspiStatus)
    {
        Ipw_Status = (Std_ReturnType)E_NOT_OK;   
    }
#endif
#endif

    if(SPI_IP_STATUS_SUCCESS != Spi_SpiStatus)
    {
        Ipw_Status = (Std_ReturnType)E_NOT_OK;   
    }
    
    return Ipw_Status;
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Spi_Ipw_Init */
void Spi_Ipw_Init(const Spi_HWUnitType HWUnitId, const Spi_HWUnitConfigType *HWUnit)
{
    if (SPI_OVER_SPI == HWUnit->IpType)
    {
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        Spi_Ipw_au8SpiHWUnitMapping[HWUnit->Instance] = HWUnitId;
    #else
        (void)HWUnitId;
    #endif
        (void)Spi_Ip_Init(HWUnit->IpConfig.SpiIpConfig);
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        Spi_Ipw_au8LpspiHWUnitMapping[HWUnit->Instance] = HWUnitId;
    #else
        (void)HWUnitId;
    #endif
        (void)Lpspi_Ip_Init(HWUnit->IpConfig.LpspiIpConfig);
    }
#endif
#endif
}

/* Spi_Ipw_DeInit */
void Spi_Ipw_DeInit(Spi_HWUnitType HWUnit, uint32 SpiCoreID)
{
    if (SPI_OVER_SPI == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType)
    {
        (void)Spi_Ip_DeInit(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance);
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
        (void)Lpspi_Ip_DeInit(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance);
    }
#endif
#endif
}

/* Spi_Ipw_SyncTransmit */
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
Std_ReturnType Spi_Ipw_SyncTransmit(const Spi_JobConfigType *JobConfig, uint32 SpiCoreID)
{

    Std_ReturnType Ipw_Status = (Std_ReturnType)E_OK;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    const Spi_ChannelConfigType *ChannelConfig;
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    const Spi_ChannelConfigType *NextChannelConfig;
#endif
#endif
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;
    Spi_Ipw_SupportedIpsType IpType = JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType;
    
    NumChannelsInJob = JobConfig->NumChannels;
    for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelID].ChannelCfg;
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if(0u != (ChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            TxBuffer = NULL_PTR;
        }
        else
        {
            if(EB == ChannelConfig->BufferType)
            {
                TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
            }
        }

        if (SPI_OVER_SPI == IpType)
        {
            if(ChannelIndex == (NumChannelsInJob - 1u))
            {
                /* Clear CS after current channel */
                Spi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->KeepCs = FALSE;
            }
            else
            {
                Spi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->KeepCs = TRUE;
            }
        }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
        else
        {
            if(ChannelIndex == (NumChannelsInJob - 1u))
            {
                /* Clear CS after current channel */
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->KeepCs = FALSE;
            }
            else
            {
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->KeepCs = TRUE;
                /* update data for next transfer */
                NextChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[JobConfig->ChannelIndexList[ChannelIndex + 1u]].ChannelCfg;
                if(0u != (NextChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
                {
                    Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->TxBufferNext = NULL_PTR;
                }
                else
                {
                    if(EB == NextChannelConfig->BufferType)
                    {
                        Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->TxBufferNext = NextChannelConfig->BufferDescriptor->ExternalBufferTX;
                    }
                    else
                    {
                        Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->TxBufferNext = (const uint8*)(NextChannelConfig->BufferDescriptor->InternalBufferTX);
                    }
                }
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->FrameSizeNext = NextChannelConfig->FrameSize;
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->LsbNext = NextChannelConfig->Lsb;
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->DefaultDataNext = NextChannelConfig->DefaultTransmitValue;
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->LengthNext = NextChannelConfig->ChannelState->Length;
                #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
                /* Get mode of next channel */
                if (SPI_HALF_DUPLEX_RECEIVE == NextChannelConfig->HalfDuplexMode)
                {
                    Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->NextChannelIsRX = TRUE;
                }
                else
                {
                    Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->NextChannelIsRX = FALSE;
                }
                #endif
            }
            if(0u == ChannelIndex)
            {
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->FirstCmd = TRUE;
            }
            else
            {
                Lpspi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->FirstCmd = FALSE;
            }
        }
#endif
#endif
        Ipw_Status = Spi_Ipw_SyncTransmitProcess(JobConfig, ChannelConfig, RxBuffer, (const uint8*)TxBuffer);
    }
    return Ipw_Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) ) */


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_IrqPoll */
void Spi_Ipw_IrqPoll(Spi_HWUnitType HWUnit, uint32 SpiCoreID)
{
    if (SPI_OVER_SPI == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType)
    {
        if(SPI_IP_POLLING == Spi_Ip_apxStateStructureArray[Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance]->TransferMode)
        {
            Spi_Ip_ManageBuffers(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance);
        }
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
        if(LPSPI_IP_POLLING == Lpspi_Ip_apxStateStructureArray[Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance]->TransferMode)
        {
            Lpspi_Ip_ManageBuffers(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance);
        }
    }
#endif
#endif
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_IrqConfig */
void Spi_Ipw_IrqConfig(Spi_HWUnitType HWUnit, Spi_AsyncModeType Mode, uint32 SpiCoreID)
{    
    if (SPI_OVER_SPI == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType)
    {
        if (SPI_POLLING_MODE == Mode)
        {
            (void)Spi_Ip_UpdateTransferMode(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance, SPI_IP_POLLING);
        }
        else
        {
            (void)Spi_Ip_UpdateTransferMode(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance, SPI_IP_INTERRUPT);
        }
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
        if (SPI_POLLING_MODE == Mode)
        {
            (void)Lpspi_Ip_UpdateTransferMode(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance, LPSPI_IP_POLLING);
        }
        else
        {
            (void)Lpspi_Ip_UpdateTransferMode(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance, LPSPI_IP_INTERRUPT);
        }
    }
#endif
#endif
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Function to manage switching between channels. */
static void Spi_Ipw_EndChannelCallback(uint8 Instance, Spi_Ipw_SupportedIpsType IpType, Spi_JobResultType JobResult)
{
    uint32 SpiCoreID;
    Spi_HWUnitType HwUnit = 0;
    Spi_ChannelType ChannelIndex, NumberOfChannels, ChannelNumber;
    Spi_JobType Job;
    const Spi_Ip_ExternalDeviceType *SpiExternalDevice;
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    const Lpspi_Ip_ExternalDeviceType *Lpspi_SpiExternalDevice;
    const Spi_ChannelConfigType *NextChannelConfig;
    Lpspi_Ip_StatusType Spi_LpspiStatus = LPSPI_IP_STATUS_SUCCESS;
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
    Lpspi_Ip_HalfDuplexType HalfDuplexMode;
    boolean HalfDuplexModeSupport = TRUE;
    Spi_DataBufferType *Buffer;
#endif
#endif
#endif
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_NumberOfDataType NumberOfBytes;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

    if (SPI_OVER_SPI == IpType)
    {
        HwUnit = Spi_Ipw_au8SpiHWUnitMapping[Instance];
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
        HwUnit = Spi_Ipw_au8LpspiHWUnitMapping[Instance];
    }
#endif
#endif

    ChannelIndex = Spi_axSpiHwUnitQueueArray[HwUnit].Channel;
    Job = Spi_axSpiHwUnitQueueArray[HwUnit].Job;
    NumberOfChannels = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->NumChannels;

    if (((ChannelIndex + 1u) < NumberOfChannels) && (SPI_JOB_OK == JobResult))
    {
        Spi_axSpiHwUnitQueueArray[HwUnit].Channel++;
        ChannelIndex++;
        MCAL_DATA_SYNC_BARRIER();
        ChannelNumber = (Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig)[Job].JobCfg->ChannelIndexList[ChannelIndex];
        ChannelConfig = (Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig)[ChannelNumber].ChannelCfg;
        MCAL_DATA_SYNC_BARRIER();
        NumberOfBytes = ChannelConfig->ChannelState->Length;
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if(EB == ChannelConfig->BufferType)
        {
            TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
        }
        else
        {
            TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
        }
        if (SPI_OVER_SPI == IpType)
        {
            SpiExternalDevice = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.SpiExternalDeviceConfig;
            if(ChannelIndex == (NumberOfChannels - 1u))
            {
                /* Clear CS after current channel */
                Spi_Ip_apxStateStructureArray[Instance]->KeepCs = FALSE;
            }
            else
            {
                Spi_Ip_apxStateStructureArray[Instance]->KeepCs = TRUE;
            }
            
            /* update default data, Lsb, Framesize */
            SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
            SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
            SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
            {
                (void)Spi_Ip_AsyncTransmit(SpiExternalDevice, TxBuffer, RxBuffer, NumberOfBytes, &Spi_Ipw_CallbackSpi); 
            }
        }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
        else
        {
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
            if (SPI_HALF_DUPLEX_TRANSMIT == ChannelConfig->HalfDuplexMode)
            {
                HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_TRANSMIT;
                Buffer = (Spi_DataBufferType*)TxBuffer;
            }
            else if (SPI_HALF_DUPLEX_RECEIVE == ChannelConfig->HalfDuplexMode)
            {
                HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_RECEIVE;
                Buffer = RxBuffer;
            }
            else
            {
                HalfDuplexMode = LPSPI_IP_FULL_DUPLEX;
                HalfDuplexModeSupport = FALSE;
            }
#endif
            Lpspi_SpiExternalDevice = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.LpspiExternalDeviceConfig; 
            if(ChannelIndex == (NumberOfChannels - 1u))
            {
                /* Clear CS after current channel */
                Lpspi_Ip_apxStateStructureArray[Instance]->KeepCs = FALSE;
            }
            else
            {
                Lpspi_Ip_apxStateStructureArray[Instance]->KeepCs = TRUE;
                MCAL_DATA_SYNC_BARRIER();
                /* update data for next transfer */
                NextChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->ChannelIndexList[ChannelIndex + 1u]].ChannelCfg;
                MCAL_DATA_SYNC_BARRIER();
                if(0u != (NextChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
                {
                    Lpspi_Ip_apxStateStructureArray[Instance]->TxBufferNext = NULL_PTR;
                }
                else
                {
                    if(EB == NextChannelConfig->BufferType)
                    {
                        Lpspi_Ip_apxStateStructureArray[Instance]->TxBufferNext = NextChannelConfig->BufferDescriptor->ExternalBufferTX;
                    }
                    else
                    {
                        Lpspi_Ip_apxStateStructureArray[Instance]->TxBufferNext = (const uint8*)(NextChannelConfig->BufferDescriptor->InternalBufferTX);
                    }
                }
                Lpspi_Ip_apxStateStructureArray[Instance]->FrameSizeNext = NextChannelConfig->FrameSize;
                Lpspi_Ip_apxStateStructureArray[Instance]->LsbNext = NextChannelConfig->Lsb;
                Lpspi_Ip_apxStateStructureArray[Instance]->DefaultDataNext = NextChannelConfig->DefaultTransmitValue;
                Lpspi_Ip_apxStateStructureArray[Instance]->LengthNext = NextChannelConfig->ChannelState->Length;
                #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
                /* Get mode of next channel */
                if (SPI_HALF_DUPLEX_RECEIVE == NextChannelConfig->HalfDuplexMode)
                {
                    Lpspi_Ip_apxStateStructureArray[Instance]->NextChannelIsRX = TRUE;
                }
                else
                {
                    Lpspi_Ip_apxStateStructureArray[Instance]->NextChannelIsRX = FALSE;
                }
                #endif
            }
            Lpspi_Ip_apxStateStructureArray[Instance]->FirstCmd = FALSE;
            /* update default data */
            Spi_LpspiStatus = Lpspi_Ip_UpdateDefaultTransmitData(Lpspi_SpiExternalDevice, ChannelConfig->DefaultTransmitValue);
            if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
            {
                Spi_LpspiStatus = Lpspi_Ip_UpdateFrameSize(Lpspi_SpiExternalDevice, ChannelConfig->FrameSize);
            }
            if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
            {
                Spi_LpspiStatus = Lpspi_Ip_UpdateLsb(Lpspi_SpiExternalDevice, ChannelConfig->Lsb);
            }
            if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
            {
                #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
                if(HalfDuplexModeSupport)
                {
                    (void)Lpspi_Ip_AsyncTransmitHalfDuplex(Lpspi_SpiExternalDevice, Buffer, NumberOfBytes, HalfDuplexMode, &Spi_Ipw_CallbackLpspi);    
                }
                else
                #endif
                {
                    (void)Lpspi_Ip_AsyncTransmit(Lpspi_SpiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, &Spi_Ipw_CallbackLpspi); 
                }
            }
        }
#endif
#endif
    }
    else
    {
        Spi_JobTransferFinished(Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg, JobResult);
    }
 }

/* SPI end of channel callback. */
static void Spi_Ipw_CallbackSpi(uint8 Instance, Spi_Ip_EventType Event)
{
    Spi_Ipw_SupportedIpsType IpType = SPI_OVER_SPI;
    if (Event != SPI_IP_EVENT_END_TRANSFER)
    {
        Spi_Ipw_EndChannelCallback(Instance, IpType, SPI_JOB_FAILED);
    }
    else
    {
        Spi_Ipw_EndChannelCallback(Instance, IpType, SPI_JOB_OK);
    }
}

#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
/* LPSPI end of channel callback. */
static void Spi_Ipw_CallbackLpspi(uint8 Instance, Lpspi_Ip_EventType Event)
{
    Spi_Ipw_SupportedIpsType IpType = SPI_OVER_LPSPI;
    if (Event != LPSPI_IP_EVENT_END_TRANSFER)
    {
        Spi_Ipw_EndChannelCallback(Instance, IpType, SPI_JOB_FAILED);
    }
    else
    {
        Spi_Ipw_EndChannelCallback(Instance, IpType, SPI_JOB_OK);
    }
}
#endif
#endif

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
static void Spi_Ipw_SequenceDmaFastTransfer(const Spi_SequenceConfigType *SequenceConfig, uint8 HWUnit, uint32 SpiCoreID)
{
    Spi_Ip_FastTransferType *SpiDmaFastTransferCfg = Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpConfig.SpiFastTransferCfg;
    uint8 TransferCount = 0u;
    Spi_JobType JobsCount;
    const Spi_JobType *JobIndexList;
    const Spi_JobConfigType *JobConfig;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;

    /* Get the number of Jobs in the sequence */
    JobsCount = SequenceConfig->NumJobs;
    JobIndexList = SequenceConfig->JobIndexList;
    while (0u < JobsCount)
    {
        /* Set the Job Status as pending */
        Spi_axSpiJobState[*JobIndexList].Result = SPI_JOB_PENDING;
        JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[*JobIndexList].JobCfg;
        NumChannelsInJob = JobConfig->NumChannels;
        for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
        {
            ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
            ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelID].ChannelCfg;
            if (SPI_OVER_SPI == JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType)
            {
                SpiDmaFastTransferCfg[TransferCount].Length = ChannelConfig->ChannelState->Length;
                SpiDmaFastTransferCfg[TransferCount].RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
                if(0u != (ChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
                {
                    SpiDmaFastTransferCfg[TransferCount].TxBuffer = NULL_PTR;
                }
                else
                {
                    if(EB == ChannelConfig->BufferType)
                    {
                        SpiDmaFastTransferCfg[TransferCount].TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
                    }
                    else
                    {
                        SpiDmaFastTransferCfg[TransferCount].TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
                    }
                }
                SpiDmaFastTransferCfg[TransferCount].ExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.SpiExternalDeviceConfig;
                if(ChannelIndex == (NumChannelsInJob - 1u))
                {
                    /* Clear CS after current channel */
                    SpiDmaFastTransferCfg[TransferCount].KeepCs = (boolean)FALSE;
                }
                else
                {
                    SpiDmaFastTransferCfg[TransferCount].KeepCs = (boolean)TRUE;
                }
                /* For Dma Fast transfer, All transfers use the same HWUnit and in Master Mode only. Only some parameters can be changed as Continuous CS, PCS.
                Some parameters such as Baudrate, Clock Polarity, Clock Phase, Delays timming configuration, Bit Order, Frame Size
                must be the same between transfers. So, make sure they are configured the same in each External Device, Channel allocated to Jobs for Dma Fast Transfers. */
                /* update default data */
                SpiDmaFastTransferCfg[TransferCount].DefaultData = ChannelConfig->DefaultTransmitValue;
                (void)Spi_Ip_UpdateFrameSize(SpiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->FrameSize);
                (void)Spi_Ip_UpdateLsb(SpiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->Lsb);             
            }
            TransferCount++;
        }
        /* iterate to next Job in sequence */
        JobIndexList++;
        JobsCount--;
    } /* while (JobsCount > 0u) */

    /* Because of all Channels and all Jobs are transferred successfully when Spi_Ipw_Callback called.
    So, remaining of Channels in current Job must set to 0, this will lead to Spi_JobTransferFinished() called when Spi_Ipw_Callback called.
    And Spi_JobTransferFinished() will set remainning of Job to 0 and set all Jobs result to SPI_JOB_OK, unlock all Jobs for this Dma Fast Sequence. */
    Spi_axSpiHwUnitQueueArray[HWUnit].Channel = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Spi_axSpiHwUnitQueueArray[HWUnit].Job].JobCfg->NumChannels - 1u;
    if (SPI_OVER_SPI == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType)
    {
        (void)Spi_Ip_AsyncTransmitFast(SpiDmaFastTransferCfg, TransferCount, &Spi_Ipw_CallbackSpi);
    }
}
#endif

/* Triggers first channel of the Job. */
void Spi_Ipw_JobTransfer(const Spi_JobConfigType *JobConfig)
{
    const Spi_Ip_ExternalDeviceType *SpiExternalDevice;
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    const Lpspi_Ip_ExternalDeviceType *Lpspi_SpiExternalDevice;
    const Spi_ChannelConfigType *NextChannelConfig;
    Lpspi_Ip_StatusType Spi_LpspiStatus = LPSPI_IP_STATUS_SUCCESS;
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)    
    Lpspi_Ip_HalfDuplexType HalfDuplexMode;
    boolean HalfDuplexModeSupport = TRUE;
    Spi_DataBufferType *Buffer;
#endif
#endif
#endif
    uint8 Instance;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_NumberOfDataType NumberOfBytes;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    uint32 SpiCoreID;
#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    const Spi_SequenceConfigType *SequenceConfig = JobConfig->JobState->AsyncCrtSequenceState->Sequence;
#endif
    
    /* get core ID */
    SpiCoreID = Spi_GetCoreID;
    /* Perform Job StartNotification (if there is one) */
    if (NULL_PTR != JobConfig->StartNotification)
    {
        JobConfig->StartNotification();
    }
    else
    {
        /* Do nothing */
    }

    #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    if(TRUE == SequenceConfig->EnableDmaFastTransfer)
    {
        Spi_Ipw_SequenceDmaFastTransfer(SequenceConfig, JobConfig->HWUnit, SpiCoreID);
    }
    else
    #endif
    {
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
        Lpspi_SpiExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.LpspiExternalDeviceConfig;
#endif
#endif
        SpiExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.SpiExternalDeviceConfig;
        Instance = JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance;
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[JobConfig->ChannelIndexList[0u]].ChannelCfg;
        NumberOfBytes = ChannelConfig->ChannelState->Length;
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if(0u != (ChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            TxBuffer = NULL_PTR;
        }
        else
        {
            if(EB == ChannelConfig->BufferType)
            {
                TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                if(EB == ChannelConfig->BufferType)
                {
                    TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
                }
                else
                {
                    TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
                }
            }
        }

#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
        if (SPI_HALF_DUPLEX_TRANSMIT == ChannelConfig->HalfDuplexMode)
        {
            HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_TRANSMIT;
            Buffer = (Spi_DataBufferType*)TxBuffer;
        }
        else if (SPI_HALF_DUPLEX_RECEIVE == ChannelConfig->HalfDuplexMode)
        {
            HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_RECEIVE;
            Buffer = RxBuffer;
        }
        else
        {
            HalfDuplexMode = LPSPI_IP_FULL_DUPLEX;
            HalfDuplexModeSupport = FALSE;
        }
#endif
#endif
#endif
        if (SPI_OVER_SPI == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[JobConfig->HWUnit].PhyUnitConfig->IpType)
        {
            if (1u == JobConfig->NumChannels)
            {
                /* Clear CS after current channel */
                Spi_Ip_apxStateStructureArray[Instance]->KeepCs = FALSE;
            }
            else
            {
                Spi_Ip_apxStateStructureArray[Instance]->KeepCs = TRUE;
            }
            /* update default data, Lsb, Framesize */
            SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
            SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
            SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
            (void)Spi_Ip_AsyncTransmit(SpiExternalDevice, TxBuffer, RxBuffer, NumberOfBytes, &Spi_Ipw_CallbackSpi); 
        }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
        else
        {
            if (1u == JobConfig->NumChannels)
            {
                /* Clear CS after current channel */
                Lpspi_Ip_apxStateStructureArray[Instance]->KeepCs = FALSE;
            }
            else
            {
                Lpspi_Ip_apxStateStructureArray[Instance]->KeepCs = TRUE;
                /* update data for next transfer */
                NextChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[JobConfig->ChannelIndexList[1u]].ChannelCfg;
                if(0u != (NextChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
                {
                    Lpspi_Ip_apxStateStructureArray[Instance]->TxBufferNext = NULL_PTR;
                }
                else
                {
                    if(EB == NextChannelConfig->BufferType)
                    {
                        Lpspi_Ip_apxStateStructureArray[Instance]->TxBufferNext = NextChannelConfig->BufferDescriptor->ExternalBufferTX;
                    }
                    else
                    {
                        Lpspi_Ip_apxStateStructureArray[Instance]->TxBufferNext = (const uint8*)(NextChannelConfig->BufferDescriptor->InternalBufferTX);
                    }
                }
                Lpspi_Ip_apxStateStructureArray[Instance]->FrameSizeNext = NextChannelConfig->FrameSize;
                Lpspi_Ip_apxStateStructureArray[Instance]->LsbNext = NextChannelConfig->Lsb;
                Lpspi_Ip_apxStateStructureArray[Instance]->DefaultDataNext = NextChannelConfig->DefaultTransmitValue;
                Lpspi_Ip_apxStateStructureArray[Instance]->LengthNext = NextChannelConfig->ChannelState->Length;
                #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
                /* Get mode of next channel */
                if (SPI_HALF_DUPLEX_RECEIVE == NextChannelConfig->HalfDuplexMode)
                {
                    Lpspi_Ip_apxStateStructureArray[Instance]->NextChannelIsRX = TRUE;
                }
                else
                {
                    Lpspi_Ip_apxStateStructureArray[Instance]->NextChannelIsRX = FALSE;
                }
                #endif
            }
            Lpspi_Ip_apxStateStructureArray[Instance]->FirstCmd = TRUE;
            /* update default data */
            Spi_LpspiStatus = Lpspi_Ip_UpdateDefaultTransmitData(Lpspi_SpiExternalDevice, ChannelConfig->DefaultTransmitValue);
            if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
            {
                Spi_LpspiStatus = Lpspi_Ip_UpdateFrameSize(Lpspi_SpiExternalDevice, ChannelConfig->FrameSize);
                if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
                {
                    Spi_LpspiStatus = Lpspi_Ip_UpdateLsb(Lpspi_SpiExternalDevice, ChannelConfig->Lsb);
                    if (LPSPI_IP_STATUS_SUCCESS == Spi_LpspiStatus)
                    {
                        #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
                        if (HalfDuplexModeSupport)
                        {
                            (void)Lpspi_Ip_AsyncTransmitHalfDuplex(Lpspi_SpiExternalDevice, Buffer, NumberOfBytes, HalfDuplexMode, &Spi_Ipw_CallbackLpspi);
                        }
                        else
                        #endif
                        {
                            (void)Lpspi_Ip_AsyncTransmit(Lpspi_SpiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, &Spi_Ipw_CallbackLpspi); 
                        }
                    }
                }
            }
        }
#endif
#endif
    }
}
#endif

#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
void Spi_Ipw_SlaveCancel(const Spi_JobConfigType *JobConfig)
{
    boolean SlaveMode;
    
    /* DSPI do not support Slave mode */
    if (SPI_OVER_SPI == JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType)
    {
#if (SPI_IP_SLAVE_SUPPORT == STD_ON)
        SlaveMode = Spi_apxSpiConfigPtr[Spi_GetCoreID]->HWUnitConfig[JobConfig->HWUnit].PhyUnitConfig->IpConfig.SpiIpConfig->SlaveMode;
        if(TRUE == SlaveMode)
        {
            Spi_Ip_Cancel(JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance);
            Spi_JobTransferFinished(JobConfig, SPI_JOB_FAILED);
        }
#endif
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        SlaveMode = Spi_apxSpiConfigPtr[Spi_GetCoreID]->HWUnitConfig[JobConfig->HWUnit].PhyUnitConfig->IpConfig.LpspiIpConfig->SlaveMode;
        if(TRUE == SlaveMode)
        {
            Lpspi_Ip_Cancel(JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance);
            Spi_JobTransferFinished(JobConfig, SPI_JOB_FAILED);
        }
#endif
    }
#endif
#endif
}
    #endif
#endif

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
void Spi_Ipw_SetClockMode(Spi_DualClockModeType ClockMode, const Spi_HWUnitConfigType * HWUnitConfig)
{
    if (SPI_OVER_SPI == HWUnitConfig->IpType)
    {
        (void)Spi_Ip_SetClockMode(HWUnitConfig->Instance, (Spi_Ip_DualClockModeType)ClockMode);
    }
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
    else
    {
        (void)Lpspi_Ip_SetClockMode(HWUnitConfig->Instance, (Lpspi_Ip_DualClockModeType)ClockMode);
    }
#endif
#endif
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
