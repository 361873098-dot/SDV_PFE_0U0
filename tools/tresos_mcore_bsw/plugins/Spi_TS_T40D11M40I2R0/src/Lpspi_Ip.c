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
*   @file    Lpspi_Ip.c
*   
*
*   @brief   LPSPI low-level driver implementations.
*   @details LPSPI low-level driver implementations.
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
#include "Lpspi_Ip_Cfg.h"
#if (STD_ON == LPSPI_IP_SUPPORT)
#include "Lpspi_Ip.h"
#include "Mcal.h"
#include "OsIf.h"
#if (STD_ON == LPSPI_IP_DMA_USED)
    #include "Dma_Ip.h"
#endif
#if (STD_ON == LPSPI_IP_ENABLE_USER_MODE_SUPPORT)
   #define USER_MODE_REG_PROT_ENABLED   (LPSPI_IP_ENABLE_USER_MODE_SUPPORT)
   #include "RegLockMacros.h"
#endif
#include "SchM_Spi.h"
#if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_VENDOR_ID_C                      43
#define LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define LPSPI_IP_AR_RELEASE_MINOR_VERSION_C       4
#define LPSPI_IP_AR_RELEASE_REVISION_VERSION_C    0
#define LPSPI_IP_SW_MAJOR_VERSION_C               4
#define LPSPI_IP_SW_MINOR_VERSION_C               0
#define LPSPI_IP_SW_PATCH_VERSION_C               2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == LPSPI_IP_SUPPORT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lpspi_Ip.c and Mcal.h are different"
    #endif

    #if (STD_ON == LPSPI_IP_DMA_USED)
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
             (DMA_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_C))
            #error "AutoSar Version Numbers of Lpspi_Ip.c and Dma_Ip.h are different"
        #endif
    #endif
    
    #if (STD_ON == LPSPI_IP_ENABLE_USER_MODE_SUPPORT)
        #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lpspi_Ip.c and RegLockMacros.h are different"
        #endif
    #endif

    /* Check if the current file and SchM_Spi.h header file are of the same version */
    #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpspi_Ip.c and SchM_Spi.h are different"
    #endif

    /* Check if the current file and OsIf.h header file are of the same version */
    #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpspi_Ip.c and OsIf.h are different"
    #endif

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
        /* Check if the current file and Devassert.h header file are of the same version */
        #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lpspi_Ip.c and Devassert.h are different"
        #endif
    #endif /* (STD_ON == LPSPI_IP_DEV_ERROR_DETECT) */
#endif

/* Check if Lpspi_Ip.h and Lpspi_Ip.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP_VENDOR_ID_C)
    #error "Lpspi_Ip.h and Lpspi_Ip.c have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION_C) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION_C) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip.c are different"
#endif

/* Check if Lpspi_Ip_Cfg.h and Lpspi_Ip.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID_CFG != LPSPI_IP_VENDOR_ID_C)
    #error "Lpspi_Ip_Cfg.h and Lpspi_Ip.c have different vendor ids"
#endif
/* Check if Lpspi_Ip_Cfg.h file and Lpspi_Ip.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != LPSPI_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != LPSPI_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Lpspi_Ip_Cfg.h and Lpspi_Ip.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION_CFG != LPSPI_IP_SW_MAJOR_VERSION_C) || \
     (LPSPI_IP_SW_MINOR_VERSION_CFG != LPSPI_IP_SW_MINOR_VERSION_C) || \
     (LPSPI_IP_SW_PATCH_VERSION_CFG != LPSPI_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Lpspi_Ip_Cfg.h and Lpspi_Ip.c are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == LPSPI_IP_DMA_USED)
    /* the maximum of Major loop when Minor loop Channel Linking Disabled */
    #define LPSPI_IP_DMA_MAX_ITER_CNT_U16 ((uint16)0x7FFFu)
#endif

/**
* @brief SR mask
*/
#define LPSPI_IP_SR_W1C_MASK_U32    (uint32)((uint32)LPSPI_SR_WCF_MASK | (uint32)LPSPI_SR_FCF_MASK | (uint32)LPSPI_SR_TCF_MASK | \
                                             (uint32)LPSPI_SR_TEF_MASK | (uint32)LPSPI_SR_REF_MASK | (uint32)LPSPI_SR_DMF_MASK)
                                            
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == LPSPI_IP_DMA_USED)
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"
static Lpspi_Ip_StateStructureType Lpspi_Ip_axStateStructure[LPSPI_IP_NUMBER_OF_INSTANCES];
#if (STD_ON == LPSPI_IP_DMA_USED)
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#if (STD_ON == LPSPI_IP_DMA_USED)
    #define SPI_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Spi_MemMap.h"
static uint32 Lpspi_Ip_u32DiscardData;
    #define SPI_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

Lpspi_Ip_StateStructureType* Lpspi_Ip_apxStateStructureArray[LPSPI_INSTANCE_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

static LPSPI_Type* const Lpspi_Ip_apxBases[LPSPI_INSTANCE_COUNT] = IP_LPSPI_BASE_PTRS;
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
static LLCE_Core_to_core_Type* const Lpspi_Ip_LlceCoreToCoreBase[1u] = IP_LLCE_Core_to_core_BASE_PTRS;
#endif
#endif

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

LOCAL_INLINE void Lpspi_Ip_ReadDataFromFifo(uint8 Instance, uint8 NumberOfReads);
LOCAL_INLINE void Lpspi_Ip_PushDataToFifo(uint8 Instance, uint8 NumberOfWrites);
static void Lpspi_Ip_ChannelFinished(uint8 Instance, boolean ErrorFlag);
#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
static void Lpspi_Ip_TransferProcessHalfDuplex(uint8 Instance);
static boolean Lpspi_Ip_HalfDupleTransmitChannelComplete(uint8 Instance);
LOCAL_INLINE boolean Lpspi_Ip_HalfDuplexTransmitProcess(uint8 Instance, uint8 NumberOfWrites);
LOCAL_INLINE void Lpspi_Ip_HalfDuplexPushDataToFifo(uint8 Instance, uint8 NumberOfWrites);
static void Lpspi_Ip_HalfDuplexPrepare(uint8 Instance, uint8* Buffer);
#endif
static void Lpspi_Ip_TransferProcess(uint8 Instance);
static void Lpspi_TransmitTxInit(uint8 Instance,
                                 const uint8* TxBuffer,
                                 uint8 TxFrameSize,
                                 boolean TxLsb,
                                 uint16 NumberOfFrames);
static void Lpspi_TransmitRxInit(uint8 Instance,
                                 uint8* RxBuffer,
                                 uint8 RxFrameSize,
                                 uint16 NumberOfFrames);
#if (STD_ON == LPSPI_IP_ENABLE_USER_MODE_SUPPORT)
void Lpspi_Ip_SetUserAccess(uint8 Instance);
static void Lpspi_Ip_SetUserAccessAllowed(uint8 Instance);
#endif /* LPSPI_IP_ENABLE_USER_MODE_SUPPORT */
#if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
static void Lpspi_Ip_CheckValidParameters
(
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
    uint16 Length
);
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function will read Data from RX FIFO.
* @details This function will read Data from RX FIFO.
*
* @param[in]     Instance      Index of the hardware instance.
* @param[in]     NumberOfReads      Number of Data can be read from RX FIFO.
* @return void
*/
LOCAL_INLINE void Lpspi_Ip_ReadDataFromFifo(uint8 Instance, uint8 NumberOfReads)
{
    const LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 Data = 0u;
    uint8 Index = 0u;

    /* To increase the performance of transfer, we will reduce the checking conditions in per "for" statement so we should have more than 1 "for" statement here */
    if (NULL_PTR != State->RxBuffer)
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            for (Index = 0; Index < NumberOfReads; Index++)
            {
                Data = Base->RDR;
                *((uint8*)(&State->RxBuffer[State->RxIndex + Index])) = (uint8)Data;
            }
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            for (Index = 0; Index < NumberOfReads; Index++)
            {
                Data = Base->RDR;
                *((uint16*)(&State->RxBuffer[2u * (State->RxIndex + Index)])) = (uint16)Data;
            }
        }
        else
        {
            for (Index = 0; Index < NumberOfReads; Index++)
            {
                Data = Base->RDR;
                *((uint32*)(&State->RxBuffer[4u * (State->RxIndex + Index)])) = (uint32)Data;
            }
        }
    }
    else
    {
        for (Index = 0; Index < NumberOfReads; Index++)
        {
            /* Read RDR register to discard data */
            (void)Base->RDR;
        }
    }
    State->RxIndex += NumberOfReads;
}

/**
* @brief   This function will push Data into TX FIFO.
* @details This function will push Data into TX FIFO.
*
* @param[in]     Instance            Index of the hardware instance.
* @param[in]     NumberOfWrites      Number of Data can be pushed to TX FIFO.
* @return void
*/
LOCAL_INLINE void Lpspi_Ip_PushDataToFifo(uint8 Instance, uint8 NumberOfWrites)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 Data = 0u;
    uint8 Index = 0u;

    /* Default data will be sent if TX buffer is null */
    Data = State->ExternalDevice->DeviceParams->DefaultData;
    /* To increase the performance of transfer, we will reduce the checking conditions in per "for" statement so we should have more than 1 "for" statement here */
    if (NULL_PTR != State->TxBuffer)
    {
        if (State->TxFrameSize < 9u)
        {
            for (Index = 0; Index < NumberOfWrites; Index++)
            {
                Data = *((const uint8*)(&State->TxBuffer[State->TxIndex + Index]));
                Base->TDR = Data;
            }
        }
        else if (State->TxFrameSize < 17u)
        {
            for (Index = 0; Index < NumberOfWrites; Index++)
            {
                Data = *((const uint16*)(&State->TxBuffer[2u * (State->TxIndex + Index)]));
                Base->TDR = Data;
            }
        }
        else
        {
            for (Index = 0; Index < NumberOfWrites; Index++)
            {
                Data = *((const uint32*)(&State->TxBuffer[4u * (State->TxIndex + Index)]));
                Base->TDR = Data;
            }
        }
    }
    else
    {
        for (Index = 0; Index < NumberOfWrites; Index++)
        {
            Base->TDR = Data;
        }
    }
    State->TxIndex += NumberOfWrites;
}

/**
* @brief   This function will clear status flag.
* @details This function will clear status flag.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
LOCAL_INLINE void Lpspi_Ip_ClearStatusFlag(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif
    
    Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    if((BaseCoreToCore->HINTCR[1] & (((uint32)0x01U) << ((uint32)Instance))) != 0U)
    {
        /* Clears interrupt flags to host */
        BaseCoreToCore->HINTCR[1] = (((uint32)0x01U) << ((uint32)Instance));
    }
    #endif
    #endif
}

/**
* @brief   This function will finish transfer of a channel.
* @details This function will finish transfer of a channel.
*
* @param[in]     Instance            Index of the hardware instance.
* @param[in]     ErrorFlag           Save the status of transfer error flags
* @return void
*/
static void Lpspi_Ip_ChannelFinished(uint8 Instance, boolean ErrorFlag)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Lpspi_Ip_EventType EventState = LPSPI_IP_EVENT_FAULT;

    if (TRUE == ErrorFlag)
    {
        State->Status = LPSPI_IP_FAULT;
        EventState = LPSPI_IP_EVENT_FAULT;
    }
    else
    {
        State->Status = LPSPI_IP_IDLE;
        EventState = LPSPI_IP_EVENT_END_TRANSFER;
    }

    if (NULL_PTR != State->Callback)
    {
        State->Callback(Instance, EventState);
    }
}

#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
/**
* @brief   This function is called by Lpspi_Ip_IrqHandler or Lpspi_Ip_ManageBuffers. It will process transfer in interrupt mode or polling mode.
* @details This function will fill Data into TX FIFO and read Data in RX FIFO fill to Rx Buffers.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Lpspi_Ip_TransferProcessHalfDuplex(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister;
    uint8 NumberOfWrites = 0u;
    uint8 NumberOfReads = 0u;
    boolean ErrorFlag = FALSE;
    Lpspi_Ip_HalfDuplexType TransferType;
    boolean TransferCompleted = FALSE;
    uint8 NumberOfFramesTxFifo;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    if (LPSPI_IP_BUSY == State->Status)
    {
        /* Read Status and clear all flags. */
        SrStatusRegister = Base->SR;
        /* clear all flags */
        Lpspi_Ip_ClearStatusFlag(Instance);
        
        TransferType = State->ExternalDevice->DeviceParams->TransferType;       
        
        if ((SrStatusRegister & (LPSPI_SR_REF_MASK | LPSPI_SR_TEF_MASK)) != 0u)
        {
            /* mark error flag */
            ErrorFlag = TRUE;
        }
        else
        {
            /* TX of latest channel in job have done */
            /* Check TX FIFO is available to fill CMD */
            if ((State->ExpectedFifoWrites == State->TxIndex) && (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType))
            {
                ErrorFlag = Lpspi_Ip_HalfDupleTransmitChannelComplete(Instance);
                /* In Transmit only mode, masks the transfer has finish */
                TransferCompleted = TRUE;
            }
            if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
            {
                /* RECEIVE DATA */
                /* Read all Data available in receive HW fifo. */
                NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }
                if (0u != NumberOfReads)
                {
                    Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                }
                /* In slave mode, do not need push CMD */
                #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
                if (FALSE == State->PhyUnitConfig->SlaveMode)
                #endif
                {
                    /* PUSH CMD */
                    /* Only write to TCR when TX FIFO is empty in receive mode */
                    if ((0u == ((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK)) && (State->ExpectedFifoWrites != State->TxIndex))
                    {
                        /* Push one CMD to start transfer. */
                        Base->TCR = State->HalfDuplexTcrCommand;
                        State->TxIndex++;
                    }
                }
            }
            else
            {
                /* TRANSMIT */
                /* Push Data until HW fifo is full or transfer is done. */
                NumberOfFramesTxFifo = (uint8)(((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) >> LPSPI_FSR_TXCOUNT_SHIFT);
                NumberOfWrites = LPSPI_IP_FIFO_SIZE_U8 - NumberOfFramesTxFifo;
                if ((0u != NumberOfWrites) && (State->ExpectedFifoWrites != State->TxIndex))
                {
                    Lpspi_Ip_HalfDuplexPushDataToFifo(Instance, NumberOfWrites);
                }
            }
        }

        /* End of transfer */
        if (
            ((LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType) && (TRUE == TransferCompleted)) ||
            ((State->RxIndex == State->ExpectedFifoReads) && (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)) ||
            (TRUE == ErrorFlag)
           )
        {
            /* Disable interrupts */
            Base->IER = 0u;

            /* Disable ISR FW from LLCE */
            #ifdef LPSPI_IP_LLCE_SUPPORT
                #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
                /* Enable interrupt to host */
                BaseCoreToCore->HINTCER[1] &= (~(((uint32)0x01U) << ((uint32)Instance)));
                #endif
            #endif
            Lpspi_Ip_ChannelFinished(Instance, ErrorFlag);
        }
    }
}

/**
* @brief   This function to complete TX channel in HD mode.
* @details This function to complete TX channel in HD mode.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static boolean Lpspi_Ip_HalfDupleTransmitChannelComplete(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 TimeoutTicks = OsIf_MicrosToTicks(LPSPI_IP_HALF_DUPLEX_TIMEOUT_COUNTER, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    boolean TimeOutError = FALSE;

    /* TX of latest channel in job have done */
    if (FALSE == State->KeepCs)
    {
        /* No need clear for slave mode */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        #endif
        {
            /* Clear CS */
            Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
        }
    }
    if ((TRUE == State->NextChannelIsRX) || (FALSE == State->KeepCs))
    {
        /* If this is latest channel, waiting for all frames in TXFIFO have moved out before finish transfer for next job */
        /* If next channel is in receive mode, waiting for TX of this channel to complete before start next channel */
        while ((((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
        {
            CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
        }
        if (ElapsedTicks >= TimeoutTicks)
        {
            /* mark error flag */
            TimeOutError = TRUE;
            /* Clear TX FIFO */
            Base->CR |= LPSPI_CR_RTF_MASK;
        }
    }
    return TimeOutError;
}

/**
* @brief   This function will process to transmit data.
* @details This function will process to transmit data.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
LOCAL_INLINE boolean Lpspi_Ip_HalfDuplexTransmitProcess(uint8 Instance, uint8 NumberOfWrites)
{
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    boolean TransferCompleted = FALSE;

    if (State->ExpectedFifoWrites != State->TxIndex)
    {
        Lpspi_Ip_HalfDuplexPushDataToFifo(Instance, NumberOfWrites);
    }
    else
    {
        /* At least 1 TX FIFO slot must be available at here to make sure that driver can push one more CMD to TX FIFO to clear CONT at the end of latest channel in a job */
        if ((FALSE == State->KeepCs))
        {
            /* Clear CS if there is request to clear CONT bit, make sure that is having at least 1 entry TX FIFO is available to fill CMD by check TDF flag */
            if (0u != (Base->TCR & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
                /* Set transfer flag is done to break from while loop to finish transfer */
            }
        }
        /* Transfer is finished */
        TransferCompleted = TRUE;
    }
    return TransferCompleted;
}

/**
* @brief   This function will perform Transmit data in half duplex mode.
* @details This function will perform Transmit data in half duplex mode.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
LOCAL_INLINE void Lpspi_Ip_HalfDuplexPushDataToFifo(uint8 Instance, uint8 NumberOfWrites)
{
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint8 WriteToFifoTime = NumberOfWrites;

    /* Limits to remaining frames. */
    if (NumberOfWrites > (State->ExpectedFifoWrites - State->TxIndex))
    {
        WriteToFifoTime = (uint8)(State->ExpectedFifoWrites - State->TxIndex);
    }
    /* Push Data into TX FIFO */
    Lpspi_Ip_PushDataToFifo(Instance, WriteToFifoTime);
}
/**
* @brief   This function will prepare to transfer in half duplex mode.
* @details This function will prepare to transfer in half duplex mode.
*
* @param[in]     Instance           Index of the hardware instance.
* @param[in]     Buffer             Transfer buffer.
* @return void
*/
static void Lpspi_Ip_HalfDuplexPrepare(uint8 Instance, uint8* Buffer)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    uint8 LsbWriteValue = State->TxLsb ? 1U : 0U;

    /* In half duplex mode, CFGR1 register should be updated to configure PCSCFG, OUTCFG, PINCFG fields. This bit fields should be reset before write new value */
    Base->CFGR1 &= ~(LPSPI_CFGR1_PCSCFG_MASK | LPSPI_CFGR1_OUTCFG_MASK | LPSPI_CFGR1_PINCFG_MASK);
    Base->CFGR1 |= State->ExternalDevice->HalfDuplexCfgr1;
    /* This variable will be used only in polling mode, It do not determine the number of frames in TX FIFO in half mode. it only makes sure that in Slave receive mode, TDF is set but it will not be used to execute process function */
    /* Set this variable to different 0 if is not in Slave Receive mode */
    State->CurrentTxFifoSlot = 1u;
    if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType)
    {
        State->TxBuffer = (const uint8*)Buffer;
    }
    else
    {
        State->RxBuffer = Buffer;

        /* Update TCR value to using in ISR function */
        #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
        State->HalfDuplexTcrCommand = State->ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(LsbWriteValue);
        #else
        State->HalfDuplexTcrCommand = State->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(LsbWriteValue);
        #endif
        /* In Slave mode, CONT bit should be cleared */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            State->HalfDuplexTcrCommand &= ~LPSPI_TCR_CONT_MASK;
            /* This variable will be used only in polling mode, It do not determine the number of frames in TX FIFO in half mode. it only makes sure that in Slave receive mode, TDF is set but it will not be used to execute process function */
            /* Set this variable to 0 in Slave Receive mode */
            State->CurrentTxFifoSlot = 0u;
        }
        #endif
        /* Because of not supporting CS continous mode so nothing need to be done with CONT bit */
        /* Mark TX FIFO */
        State->HalfDuplexTcrCommand |= LPSPI_TCR_TXMSK_MASK;
    }
}
#endif

/**
* @brief   This function is called by Lpspi_Ip_IrqHandler or Lpspi_Ip_ManageBuffers. It will process transfer in interrupt mode or polling mode.
* @details This function will fill Data into TX FIFO and read Data in RX FIFO fill to Rx Buffers.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Lpspi_Ip_TransferProcess(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister;
    uint8 NumberOfWrites = 0u;
    uint8 NumberOfReads = 0u;
    boolean ErrorFlag = FALSE;

    if (LPSPI_IP_BUSY == State->Status)
    {
        /* Read Status and clear all flags. */
        SrStatusRegister = Base->SR;
        /* clear all flags */
        Lpspi_Ip_ClearStatusFlag(Instance);
        
        if ((SrStatusRegister & (LPSPI_SR_REF_MASK | LPSPI_SR_TEF_MASK)) != 0u)
        {
            /* mark error flag */
            ErrorFlag = TRUE;
        }
        else
        {
            /* RECEIVE */
            /* Read all Data available in receive HW fifo. */
            NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
            if (NumberOfReads != 0u)
            {
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }
                /* If these are the first frames of this channel. Current TXFIFO slot must be plus 1 because the slot of CMD have moved out and
                  CurrentTxFifoSlot was minus 1 when prepare TX channel */
                if (0u == State->RxIndex)
                {
                    State->CurrentTxFifoSlot += 1u;
                }
                /* Read Data from RX FIFO */
                Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                /* Update current FIFO slots are available to fill .*/
                State->CurrentTxFifoSlot += NumberOfReads;
            }

            /*TRANSMIT*/
            /* Push Data until HW fifo is full or transfer is done. */
            /* After driver code read all frames in RX FIFO, if there are still some frames in TX FIFO, at the time before driver code check number of frames available in TX FIFO to prepare
            to fill TX FIFO. At that time, another interrupt occurred and preemptive current interrupt, and the time to process that interrupt is longer than the time to transfer all frames
            in TX FIFO. So TX FIFO will be empty and some frames received in RX FIFO, then the program is returned from that interrupt and fill TX FIFO until full and exist SPI interrupt function.
            And if there is a interrupt occurred with higher priority of SPI interrupt and the time to process that interrupt is longer than the time to transfer all frames in TX FIFO.
            So, RX FIFO can be overflow due to SPI interrupt function is not serviced to read RX FIFO.
            State->CurrentTxFifoSlot variable is used to hanlde number of frames are "on bus transfer". They are always less than FIFO size */
            if ((State->CurrentTxFifoSlot != 0u) && (State->TxDoneFlag != TRUE))
            {
                if (State->ExpectedFifoWrites != State->TxIndex)
                {
                    NumberOfWrites = State->CurrentTxFifoSlot;
                    /* Limits to remaining frames. */
                    if (NumberOfWrites > (State->ExpectedFifoWrites - State->TxIndex))
                    {
                        NumberOfWrites = (uint8)(State->ExpectedFifoWrites - State->TxIndex);
                    }
                    /* Push Data into TX FIFO */
                    Lpspi_Ip_PushDataToFifo(Instance, NumberOfWrites);
                    State->CurrentTxFifoSlot -= NumberOfWrites;
                }
                else
                {
                    if (TRUE == State->NextTransferConfigAvailable)
                    {
                        /* Initialize next transfer */
                        State->ExternalDevice->DeviceParams->DefaultData = State->DefaultDataNext;
                        State->FirstCmd = FALSE;
                        Lpspi_TransmitTxInit(Instance, State->TxBufferNext, State->FrameSizeNext, State->LsbNext, State->LengthNext);
                        State->NextTransferConfigAvailable = FALSE;
                    }
                    else
                    {
                        State->TxDoneFlag = TRUE;
                        /* Disable TX interrupt */
                        Base->IER &= ~LPSPI_IER_TDIE_MASK;
                        if ((FALSE == State->KeepCs) && (0u != (Base->TCR & LPSPI_TCR_CONT_MASK)))
                        {
                            /* Clear CS */
                            Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
                        }
                    }
                }
            }
        }

        /* End of transfer */
        if ((State->RxIndex == State->ExpectedFifoReads) || (TRUE == ErrorFlag))
        {
            /* In slave mode. After Slave devices to finish its transfer then SPI module masks rx to avoid un-expected extra Data from Master device */
            #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
            if (((FALSE == State->KeepCs) || (TRUE == ErrorFlag)) && (TRUE == State->PhyUnitConfig->SlaveMode))
            {
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_18();
                /* Mask Rx */
                Base->TCR |= LPSPI_TCR_RXMSK(1);
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_18();
            }
            #endif
            /* Disable interrupts */
            Base->IER = 0u;
            /* Disable ISR FW from LLCE */
            #ifdef LPSPI_IP_LLCE_SUPPORT
                #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
                /* Enable interrupt to host */
                BaseCoreToCore->HINTCER[1] &= (~(((uint32)0x01U) << ((uint32)Instance)));
                #endif
            #endif
            Lpspi_Ip_ChannelFinished(Instance, ErrorFlag);
        }
    }
}

#if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
/**
* @brief   This function will verify the validation of some input parameters of transmision functions.
* @details This function will verify the validation of some input parameters of transmision functions.
*
* @param[in]     ExternalDevice   Pointer to the external device where data is transmitted.
* @param[in]     Length         Number of bytes to be sent.
* @return        LPSPI_IP_STATUS_SUCCESS: Don't have any errors was found.
*                LPSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
*/
static void Lpspi_Ip_CheckValidParameters(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, uint16 Length)
{

    if (ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        DevAssert((Length%4) == 0u);
    }
    else if (ExternalDevice->DeviceParams->FrameSize > 8u)
    {
        DevAssert((Length%2) == 0u);
    }
    else
    {
        /* do nothing */
    }
}
#endif


#if (STD_ON == LPSPI_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief This function will set UAA bit in REG_PROT for SPI unit
*/
void Lpspi_Ip_SetUserAccess(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];

    SET_USER_ACCESS_ALLOWED((uint32)Base,LPSPI_IP_PROT_MEM_U32);
}

/**
* @brief This function will enable writing all SPI registers under protection in User mode by configuring REG_PROT
*/
static void Lpspi_Ip_SetUserAccessAllowed(uint8 Instance)
{
    OsIf_Trusted_Call1param(Lpspi_Ip_SetUserAccess, Instance);
}
#endif /* LPSPI_IP_ENABLE_USER_MODE_SUPPORT */
/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_Init(const Lpspi_Ip_ConfigType *PhyUnitConfigPtr)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(PhyUnitConfigPtr != NULL_PTR);
    #endif
    Instance = PhyUnitConfigPtr->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    Base = Lpspi_Ip_apxBases[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(State == NULL_PTR);
    #endif
    Lpspi_Ip_apxStateStructureArray[Instance] = &Lpspi_Ip_axStateStructure[PhyUnitConfigPtr->StateIndex];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    State->PhyUnitConfig = PhyUnitConfigPtr;
    /* enable in debug mode to ensure CS will be kept when CPU halts at breakpoint */
    Base->CR = PhyUnitConfigPtr->Cr | LPSPI_CR_DBGEN_MASK;
    Base->CFGR1 = PhyUnitConfigPtr->Cfgr1;
    /* Set TX WATER. it will be set again in DMA mode */
    Base->FCR = LPSPI_FCR_TXWATER((uint32)LPSPI_IP_FIFO_SIZE_U8 - (uint32)1u);
    #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
    State->ClockMode = LPSPI_IP_NORMAL_CLOCK;
    #endif
    State->KeepCs = FALSE;
    State->FirstCmd = TRUE;
    /* set State to idle */
    State->Status = LPSPI_IP_IDLE;
    (void)Lpspi_Ip_UpdateTransferMode(Instance, PhyUnitConfigPtr->TransferMode);

    /* Enable SPI module */
    Base->CR |= LPSPI_CR_MEN_MASK;

    #ifdef ERR_IPV_LPSPI_0001
    /* ERRATA051472: The SR[REF] would assert if software disables the LPSPI module
    after receiving some data and then enabled the LPSPI again without performing a software reset.
    Clear SR[REF] flag after LPSPI module enabled */
    if (0U != (Base->SR & LPSPI_SR_REF_MASK))
    {
        Base->SR |= LPSPI_SR_REF_MASK;
    }
    #endif

    return Status;
}
/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_DeInit(uint8 Instance)
{
    LPSPI_Type* Base;
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
    #endif
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    if (LPSPI_IP_BUSY == State->Status)
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Use reset hardware feature. */
        Base->CR |= LPSPI_CR_RST(1u);
        Base->CR = 0;

        Lpspi_Ip_apxStateStructureArray[Instance] = NULL_PTR;
    }
    return Status;
}

/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_SyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                          const uint8 *TxBuffer,
                                          uint8 *RxBuffer,
                                          uint16 Length,
                                          uint32 TimeOut)
{
    LPSPI_Type *Base;
    Lpspi_Ip_StateStructureType *State;
    uint8 NumberOfWrites, NumberOfReads;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 Instance = 0u;
    uint32 Cfgr1 = 0u;
    boolean TxDoneFlag = FALSE;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    DevAssert(0u != TimeOut);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
    #endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(State != NULL_PTR);
    #endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_15();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        /* Clear some bits which support for half duplex mode at previous transfer */
        Base->CFGR1 &= ~(LPSPI_CFGR1_PCSCFG_MASK | LPSPI_CFGR1_OUTCFG_MASK | LPSPI_CFGR1_PINCFG_MASK);
        #endif

        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();

        /* Disable DMA requests and all interrupts */
        Base->IER = 0u;
        /* Disable ISR FW from LLCE */
        #ifdef LPSPI_IP_LLCE_SUPPORT
            #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
            /* Enable interrupt to host */
            BaseCoreToCore->HINTCER[1] &= (~(((uint32)0x01U) << ((uint32)Instance)));
            #endif
        #endif

        /* Update State structure. */
        State->NextTransferConfigAvailable = State->KeepCs;

        /* Set clock configuration */
        if (TRUE == State->FirstCmd)
        {
            /* Makes sure that FIFOs will be empty before start new transfer session.
            There is maybe a frame in RX shifter register (previous transfer is broken and CS did not de-assert).
            So use reset FIFO do not prevent the potential issue. So reset module by software reset bit should be used here */
            /* Reset FIFOs using CR[RST] bit */
            /* store CFGR1 and restore after all registers are reset */
            Cfgr1 = Base->CFGR1;
            Base->CR |= LPSPI_CR_RST_MASK;
            Base->CR &= ~LPSPI_CR_RST_MASK;
            /* restore CFGR1 */
            Base->CFGR1 = Cfgr1;
            /* clear all flags */
            Lpspi_Ip_ClearStatusFlag(Instance);

            #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
            Base->CCR = ExternalDevice->Ccr[State->ClockMode];
            #else
            Base->CCR = ExternalDevice->Ccr;
            #endif
                /* Reset current FIFO slots are available to fill at beginning of job (HLD).*/
            State->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
            Lpspi_TransmitTxInit(Instance, (const uint8*)TxBuffer, State->ExternalDevice->DeviceParams->FrameSize, State->ExternalDevice->DeviceParams->Lsb, Length);
        }
        Lpspi_TransmitRxInit(Instance, RxBuffer, State->ExternalDevice->DeviceParams->FrameSize, Length);
        /* initialize current counter */
        CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
        while (State->RxIndex != State->ExpectedFifoReads)
        {
            /* RECEIVE DATA */
            /* The receiving should be performed first because maybe have a last frame in RX FIFO from previous channel
                , it should be read to clear RXFIFO before start a new write to TXFIFO */
            /* Read all Data available in receive HW fifo. */
            NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
            /* Limits to remaining frames. */

            if (NumberOfReads != 0u)
            {
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }
                /* If these are the first frames of this channel. Current TXFIFO slot must be plus 1 because the slot of CMD have moved out */
                if (0u == State->RxIndex)
                {
                    State->CurrentTxFifoSlot += 1u;
                }
                /* Read Data from RX FIFO */
                Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                /* Update current FIFO slots are available to fill .*/
                State->CurrentTxFifoSlot += NumberOfReads;
                ElapsedTicks = 0u;
            }

            /* TRANSMIT DATA */
            /* Push Data until HW fifo is full or transfer is done. */
            /* After driver code read all frames in RX FIFO, if there are still some frames in TX FIFO, at the time before driver code check number of frames available in TX FIFO
            to prepare to fill TX FIFO. At that time, interrupt occurred, and the time to process interrupt is longer than the time to transfer all frames in TX FIFO.
            So TX FIFO will be empty and some frames received in RX FIFO, then the program is returned from interrupt and fill TX FIFO until full.
            And there is a interrupt occurred after that before read all frames in RX FIFO, and the time to process interrupt is longer than the time to transfer all frames in TX FIFO.
            State->CurrentTxFifoSlot variable is used to handle number of frames are "on bus transfer". They are always less than FIFO size */
            if ((State->CurrentTxFifoSlot != 0u) && (TxDoneFlag != TRUE))
            {
                if (State->ExpectedFifoWrites != State->TxIndex)
                {
                    NumberOfWrites = State->CurrentTxFifoSlot;
                    /* Limits to remaining frames. */
                    if (NumberOfWrites > (State->ExpectedFifoWrites - State->TxIndex))
                    {
                        NumberOfWrites = (uint8)(State->ExpectedFifoWrites - State->TxIndex);
                    }
                    /* Push Data into TX FIFO */
                    Lpspi_Ip_PushDataToFifo(Instance, NumberOfWrites);
                    State->CurrentTxFifoSlot -= NumberOfWrites;
                    ElapsedTicks = 0u;
                }
                else
                {
                    if (TRUE == State->NextTransferConfigAvailable)
                    {
                        /* Initialize next transfer */
                        State->ExternalDevice->DeviceParams->DefaultData = State->DefaultDataNext;
                        State->FirstCmd = FALSE;
                        Lpspi_TransmitTxInit(Instance, State->TxBufferNext, State->FrameSizeNext, State->LsbNext, State->LengthNext);
                        State->NextTransferConfigAvailable = FALSE;
                    }
                    else
                    {
                        TxDoneFlag = TRUE;
                        if ((FALSE == State->KeepCs) && (0u != (Base->TCR & LPSPI_TCR_CONT_MASK)))
                        {
                            /* Clear CS */
                            Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
                        }
                    }
                }
            }
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                Status = LPSPI_IP_TIMEOUT;
                break;
            }
        }
        if ((LPSPI_IP_STATUS_SUCCESS != Status) || (0u == Length))
        {
#if (STD_OFF == LPSPI_IP_DEV_ERROR_DETECT)
            /* Return Fail status if length is 0. Error Detect is enabled, nothing need to be done here */
            if (0u == Length)
            {
                Status = LPSPI_IP_STATUS_FAIL;
            }
#endif
            State->Status = LPSPI_IP_FAULT;
        }
        else
        {
            State->Status = LPSPI_IP_IDLE;
        }
    }
    return Status;
}

#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
Lpspi_Ip_StatusType Lpspi_Ip_SyncTransmitHalfDuplex(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                    uint8 *Buffer,
                                                    uint16 Length,
                                                    Lpspi_Ip_HalfDuplexType TransferType,
                                                    uint32 TimeOut)
{
    LPSPI_Type *Base;
    Lpspi_Ip_StateStructureType *State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 Instance = 0u;
    boolean TransferCompleted = FALSE;
    uint8 NumberOfFramesTxFifo;
    uint8 NumberOfWrites;
    uint8 NumberOfReads;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
    #endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(State != NULL_PTR);
    #endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_15();
    if ((LPSPI_IP_BUSY == State->Status) || (0u == Length))
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        /* Update TransferType */
        State->ExternalDevice->DeviceParams->TransferType = TransferType;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();
        /* Prepare the transfer: Write to CFGR1 register the bit fields supporting Half duplex, get transfer buffer, get CMD value in receive mode.*/
        Lpspi_Ip_HalfDuplexPrepare(Instance, Buffer);

        /* Disable DMA requests and all interrupts */
        Base->IER = 0u;
        /* Disable ISR FW from LLCE */
        #ifdef LPSPI_IP_LLCE_SUPPORT
            #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
            /* Enable interrupt to host */
            BaseCoreToCore->HINTCER[1] &= (~(((uint32)0x01U) << ((uint32)Instance)));
            #endif
        #endif
        /* Update State structure. */
        State->NextTransferConfigAvailable = State->KeepCs;

        /* Set clock configuration */
        if (TRUE == State->FirstCmd)
        {
            /* Make sure that FIFOs will be empty before start new transfer session */
            Base->CR |= LPSPI_CR_RTF_MASK|LPSPI_CR_RRF_MASK;
            /* clear all flags */

            #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
            Base->CCR = ExternalDevice->Ccr[State->ClockMode];
            #else
            Base->CCR = ExternalDevice->Ccr;
            #endif
        }

        /* Init TX channel */
        Lpspi_TransmitTxInit(Instance, NULL_PTR, State->ExternalDevice->DeviceParams->FrameSize, State->ExternalDevice->DeviceParams->Lsb, Length);
        /* If in half duplex Transmit only mode, RX do not need to be configured */
        if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
        {
            Lpspi_TransmitRxInit(Instance, NULL_PTR, State->ExternalDevice->DeviceParams->FrameSize, Length);
        }
        /* initialize current counter */
        CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
        while ((TRUE != TransferCompleted) && (LPSPI_IP_STATUS_SUCCESS == Status))
        {
            if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
            {
                /* RECEIVE DATA */
                /* Read all Data available in receive HW fifo. */
                NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }
                if (0u != NumberOfReads)
                {
                    Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                }
                /* PUSH CMD */
                /* Only write to TCR when TX FIFO is empty in receive mode */
                if ((0u == ((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK)) && (State->ExpectedFifoWrites != State->TxIndex))
                {
                    /* Push one CMD to start transfer. */
                    Base->TCR = State->HalfDuplexTcrCommand;
                    State->TxIndex++;
                }
                ElapsedTicks = 0u;
                if (State->ExpectedFifoReads == State->RxIndex)
                {
                    /* if all frames have received, break from the while loop to finish transfer */
                    break;
                }
            }
            else
            {
                /* TRANSMIT DATA */
                /* Push Data until HW fifo is full or transfer is done. */
                NumberOfFramesTxFifo = (uint8)(((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) >> LPSPI_FSR_TXCOUNT_SHIFT);
                NumberOfWrites = LPSPI_IP_FIFO_SIZE_U8 - NumberOfFramesTxFifo;
                if (0u != NumberOfWrites)
                {
                    TransferCompleted = Lpspi_Ip_HalfDuplexTransmitProcess(Instance, NumberOfWrites);
                }
                /* If this is latest channel, waiting for all frames in TXFIFO have moved out before finish transfer for next job */
                /* If next channel is in receive mode, waiting for TX of this channel to complete before start next channel */
                if ((TRUE == TransferCompleted) && ((TRUE == State->NextChannelIsRX) || (FALSE == State->KeepCs)))
                {
                    TransferCompleted = FALSE;
                    if (((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) == 0u)
                    {
                        TransferCompleted = TRUE;
                    }
                }
                ElapsedTicks = 0u;
            }
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                Status = LPSPI_IP_TIMEOUT;
            }
        }
        if (LPSPI_IP_STATUS_SUCCESS != Status)
        {
            State->Status = LPSPI_IP_FAULT;
        }
        else
        {
            State->Status = LPSPI_IP_IDLE;
        }
    }
    return Status;
}
#endif

static void Lpspi_TransmitTxInit(uint8 Instance,
                                 const uint8* TxBuffer,
                                 uint8 TxFrameSize,
                                 boolean TxLsb,
                                 uint16 NumberOfFrames)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 TransferCommand = 0u;
    uint8 LsbWriteValue = TxLsb ? 1U : 0U;

    State->TxFrameSize = TxFrameSize;
    State->TxLsb = TxLsb;
    /* Get transfer command */
#if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
    TransferCommand = State->ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)TxFrameSize - 1u) | LPSPI_TCR_LSBF(LsbWriteValue);
#else
    TransferCommand = State->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)TxFrameSize - 1u) | LPSPI_TCR_LSBF(LsbWriteValue);
#endif
#if ((STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT) && (STD_ON == LPSPI_IP_SLAVE_SUPPORT))
    /* In Receive only mode of Slave, a CMD with TXMSK should be push here */
    if ((LPSPI_IP_HALF_DUPLEX_RECEIVE == State->ExternalDevice->DeviceParams->TransferType) && (TRUE == State->PhyUnitConfig->SlaveMode))
    {
        /* Mask TX in Transmit only mode */
        TransferCommand |= LPSPI_TCR_TXMSK_MASK;
        TransferCommand &= ~LPSPI_TCR_CONT_MASK;
        Base->TCR = TransferCommand;
    }
#endif
#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    /* In RX only mode, TX FIFO will be masked, Push CMD to TX FIFO to transfer and pushing CMD will be done in transfer time. Push nothing to TCR register here */
    if (LPSPI_IP_HALF_DUPLEX_RECEIVE != State->ExternalDevice->DeviceParams->TransferType)
#endif
    {
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType)
        {
            /* Mask RX FIFO in Transmit only mode */
            TransferCommand |= LPSPI_TCR_RXMSK_MASK;
        }
        #endif
        /* In Slave mode, CONT bit should be cleared */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
        }
        #endif

        if (TRUE == State->FirstCmd)
        {
            /* Set transfer command */
            Base->TCR = TransferCommand;
        }
        else
        {
            if (0u != (TransferCommand & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR = TransferCommand | LPSPI_TCR_CONTC_MASK;
            }
            else
            {
                Base->TCR = TransferCommand;
            }
        }
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        if (LPSPI_IP_FULL_DUPLEX == State->ExternalDevice->DeviceParams->TransferType)
        #endif
        {
            /* CMD will take 1 slot in TXFIFO, update current TX FIFO slot. it will be plus 1 when the first frames of channel have received */
            State->CurrentTxFifoSlot -= 1u;
        }
    }

    /* Update State structure. */
    State->TxIndex = 0u;

    /* In half duplex mode, TX buffer have updated */
    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
    {
        /* Avoid misra and compiler warning violation */
        (void)TxBuffer;
    }
    else
    #endif
    {
        State->TxBuffer = TxBuffer;
    }

    if (TxFrameSize < 9u)
    {
        State->ExpectedFifoWrites = NumberOfFrames;
    }
    else if (TxFrameSize < 17u)
    {
        State->ExpectedFifoWrites = NumberOfFrames/2u;
    }
    else
    {
        State->ExpectedFifoWrites = NumberOfFrames/4u;
    }
}

static void Lpspi_TransmitRxInit(uint8 Instance,
                                 uint8* RxBuffer,
                                 uint8 RxFrameSize,
                                 uint16 NumberOfFrames)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];

    /* Update State structure. */
    State->RxIndex = 0u;

    /* In half duplex mode, RX buffer have updated */
    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
    {
        (void)RxBuffer;
    }
    else
    #endif
    {
        State->RxBuffer = RxBuffer;
    }

    if (RxFrameSize < 9u)
    {
        State->ExpectedFifoReads = NumberOfFrames;
    }
    else if (RxFrameSize < 17u)
    {
        State->ExpectedFifoReads = NumberOfFrames/2u;
    }
    else
    {
        State->ExpectedFifoReads = NumberOfFrames/4u;
    }
}

Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                           const uint8 *TxBuffer,
                                           uint8 *RxBuffer,
                                           uint16 Length,
                                           Lpspi_Ip_CallbackType EndCallback)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
    #endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(State != NULL_PTR);
    #endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_15();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        /* Clear some bits which support for half duplex mode at previous transfer */
        Base->CFGR1 &= ~(LPSPI_CFGR1_PCSCFG_MASK | LPSPI_CFGR1_OUTCFG_MASK | LPSPI_CFGR1_PINCFG_MASK);
        #endif
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();

        /* Update State structure. */
        State->Callback = EndCallback;
        State->NextTransferConfigAvailable = State->KeepCs;

        /* Reset TX done flag */
        State->TxDoneFlag = FALSE;

        /* Set clock configuration */
        if (TRUE == State->FirstCmd)
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_17();
            /* Make sure that FIFOs will be empty before start new transfer session */
            Base->CR |= LPSPI_CR_RTF_MASK|LPSPI_CR_RRF_MASK;
            /* clear all flags */
            Lpspi_Ip_ClearStatusFlag(Instance);
            /* Does not use the Clock Configuration Register (CCR) for Slave mode */
            #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
            if (FALSE == State->PhyUnitConfig->SlaveMode)
            #endif
            {
                #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
                Base->CCR = ExternalDevice->Ccr[State->ClockMode];
                #else
                Base->CCR = ExternalDevice->Ccr;
                #endif
            }
            /* Update current FIFO slots are available to fill .*/
            State->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
            /* In setting up Transmit command register, the RXMSK is also cleared */
            Lpspi_TransmitTxInit(Instance, (const uint8*)TxBuffer, State->ExternalDevice->DeviceParams->FrameSize, State->ExternalDevice->DeviceParams->Lsb, Length);
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_17();
        }
        Lpspi_TransmitRxInit(Instance, RxBuffer, State->ExternalDevice->DeviceParams->FrameSize, Length);

        {
            #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
            if (TRUE == State->PhyUnitConfig->SlaveMode)
            {
                Base->FCR = LPSPI_FCR_TXWATER(0u);
            }
            else
            #endif
            {
                /* Set TX water */
                Base->FCR = LPSPI_FCR_TXWATER((uint32)LPSPI_IP_FIFO_SIZE_U8 - (uint32)1u);
            }

            switch (State->TransferMode)
            {
                case LPSPI_IP_POLLING:
                    /* Disable interrupts. */
                    Base->IER = 0u;
                    /* Disable ISR FW from LLCE */
                    #ifdef LPSPI_IP_LLCE_SUPPORT
                        #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
                        /* Enable interrupt to host */
                        BaseCoreToCore->HINTCER[1] &= (~(((uint32)0x01U) << ((uint32)Instance)));
                        #endif
                    #endif
                    break;
                case LPSPI_IP_INTERRUPT:
                    /* Enable ISR FW from LLCE */
                    #ifdef LPSPI_IP_LLCE_SUPPORT
                        #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
                        /* Enable interrupt to host */
                        BaseCoreToCore->HINTCER[1] |= ((((uint32)0x01U) << ((uint32)Instance)));
                        #endif
                    #endif
                    Base->IER = LPSPI_IER_RDIE_MASK | LPSPI_IER_TDIE_MASK | LPSPI_IER_REIE_MASK | LPSPI_IER_TEIE_MASK;
                    break;
                default:
                    /* Nothing to do */
                    break;
            }
        }
    }
    return Status;
}

#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmitHalfDuplex(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                     uint8 *Buffer,
                                                     uint16 Length,
                                                     Lpspi_Ip_HalfDuplexType TransferType,
                                                     Lpspi_Ip_CallbackType EndCallback)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
    uint32 InterruptEnable = 0u;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
    #endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(State != NULL_PTR);
    #endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_15();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        /* Update TransferType */
        State->ExternalDevice->DeviceParams->TransferType = TransferType;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();

        /* Prepare the transfer: Write to CFGR1 register the bit fields supporting Half duplex, get transfer buffer, get CMD value in reeive mode.*/
        Lpspi_Ip_HalfDuplexPrepare(Instance, Buffer);

        /* Update State structure. */
        State->Callback = EndCallback;
        State->NextTransferConfigAvailable = State->KeepCs;

        /* Set clock configuration */
        if (TRUE == State->FirstCmd)
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_17();
            /* Make sure that FIFOs will be empty before start new transfer session */
            Base->CR |= LPSPI_CR_RTF_MASK|LPSPI_CR_RRF_MASK;
            /* clear all flags */
            Lpspi_Ip_ClearStatusFlag(Instance);
            /* Does not use the Clock Configuration Register (CCR) for Slave mode */
            #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
            if (FALSE == State->PhyUnitConfig->SlaveMode)
            #endif
            {
                #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
                Base->CCR = ExternalDevice->Ccr[State->ClockMode];
                #else
                Base->CCR = ExternalDevice->Ccr;
                #endif
            }
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_17();
        }
        /* Init TX channel */
        Lpspi_TransmitTxInit(Instance, NULL_PTR, State->ExternalDevice->DeviceParams->FrameSize, State->ExternalDevice->DeviceParams->Lsb, Length);
        /* If in Transmit only mode, RX do not need to be configured */
        if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
        {
            Lpspi_TransmitRxInit(Instance, NULL_PTR, State->ExternalDevice->DeviceParams->FrameSize, Length);
        }

        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if ((TRUE == State->PhyUnitConfig->SlaveMode) && (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType))
        {
            /* In slave receive mode, only use RX Flags */
            InterruptEnable = LPSPI_IER_RDIE_MASK | LPSPI_IER_REIE_MASK;
        }
        else
        #endif
        {
            /* Others mode still use TX flag to trigger to push CMDs */
            InterruptEnable = LPSPI_IER_RDIE_MASK | LPSPI_IER_TDIE_MASK | LPSPI_IER_REIE_MASK | LPSPI_IER_TEIE_MASK;
        }

        {
            /* In Receive mode, Next CMD could only be pushed to TXFIFO when previous CMD have moved out (TXFIFO is empty)
               On Slave receive mode, do not care about TX WATER because TDIE flag is not set */
            if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
            {
                Base->FCR = LPSPI_FCR_TXWATER(0u);
            }
            else
            {
                Base->FCR = LPSPI_FCR_TXWATER((uint32)LPSPI_IP_FIFO_SIZE_U8 - (uint32)1u);
            }
            switch (State->TransferMode)
            {
                case LPSPI_IP_POLLING:
                    /* Disable interrupts. */
                    Base->IER = 0u;
                    /* Disable ISR FW from LLCE */
                    #ifdef LPSPI_IP_LLCE_SUPPORT
                        #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
                        /* Enable interrupt to host */
                        BaseCoreToCore->HINTCER[1] &= (~(((uint32)0x01U) << ((uint32)Instance)));
                        #endif
                    #endif
                    break;
                case LPSPI_IP_INTERRUPT:
                    /* Enable ISR FW from LLCE */
                    #ifdef LPSPI_IP_LLCE_SUPPORT
                        #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
                        /* Enable interrupt to host */
                        BaseCoreToCore->HINTCER[1] |= ((((uint32)0x01U) << ((uint32)Instance)));
                        #endif
                    #endif
                    Base->IER = InterruptEnable;
                    break;
                default:
                    /* Nothing to do */
                    break;
            }
        }
    }
    return Status;
}
#endif


void Lpspi_Ip_ManageBuffers(uint8 Instance)
{
    const LPSPI_Type* Base;
    const Lpspi_Ip_StateStructureType* State;

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
    #endif
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    if (LPSPI_IP_POLLING == State->TransferMode)
    {
        {
            /* In half duplex master mode:
                - Transmit: TDF is set only, RDF will never be set by RX FIFO have masked.
                - Receive: Both TDF (push CDM) and DRF (receive data) are set.
               In half duplex Slave mode:
                - Transmit: TDF is set only, RDF will never be set by RX FIFO have masked.
                - Receive: Both TDF and RDF are set. But only process for RDF to receive data. In this case, State->CurrentTxFifoSlot will be set to 0 */
            if ((0u != (Base->SR & LPSPI_SR_RDF_MASK)) ||
                ((0u != (Base->SR & LPSPI_SR_TDF_MASK)) && (0u!= State->CurrentTxFifoSlot)))
            {
                #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
                if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
                {
                    Lpspi_Ip_TransferProcessHalfDuplex(Instance);
                }
                else
                #endif
                {
                    Lpspi_Ip_TransferProcess(Instance); 
                }
            }
        }
    }
}
/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_UpdateFrameSize(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, uint8 FrameSize)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(LPSPI_IP_FRAMESIZE_MAX_U8 >= FrameSize);
    DevAssert(LPSPI_IP_FRAMESIZE_MIN_U8 <= FrameSize);
    #endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Frame size can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->FrameSize = FrameSize;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }
    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateLsb(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, boolean Lsb)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    #endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->Lsb = Lsb;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }
    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateDefaultTransmitData(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, uint32 DefaultData)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    #endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->DefaultData = DefaultData;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }
    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateTransferMode(uint8 Instance, Lpspi_Ip_ModeType Mode)
{
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
    #endif
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Transfer mode can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        State->TransferMode = Mode;
        /* Enable ISR FW from LLCE */
        #ifdef LPSPI_IP_LLCE_SUPPORT
            #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
            /* Trigger interrupt forwarding */     
            BaseCoreToCore->CINTHR[1] |= (0x01U);        
            #endif
        #endif
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }
    return Status;
}

void Lpspi_Ip_Cancel(uint8 Instance)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    uint32 Cfgr1 = 0u;
    
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
    #endif
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_16();
    if (LPSPI_IP_BUSY == State->Status)
    {
        /* Mask Rx to discard received data */
        Base->TCR |= LPSPI_TCR_RXMSK(1);
        /* store CFGR1 and restore after all registers are reset */
        Cfgr1 = Base->CFGR1;
        /* Disable interrupts and DMA requests. */
        /* Clear FIFO */
        /* RTF and RRF will not clear shifter, so RST must be used to ensure old Data in shifter will also be cleared. */
        Base->CR |= LPSPI_CR_RST_MASK;
        Base->CR &= ~LPSPI_CR_RST_MASK;
        /* restore CFGR1 */
        Base->CFGR1 = Cfgr1;
        /* set State to idle */
        State->Status = LPSPI_IP_IDLE;
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_16();
}
/**
* @brief   This function is called by LSPI ISRs.
* @details This function will process activities for flags TDF, RDF, REF and TEF.
*
* @param[in]     Instance            Instance of the hardware unit.
*
* @implements Lpspi_Ip_IrqHandler_Activity
*/
void Lpspi_Ip_IrqHandler(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 IrqFlags = 0u;
    #ifdef LPSPI_IP_LLCE_SUPPORT
    #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
    LLCE_Core_to_core_Type* BaseCoreToCore = Lpspi_Ip_LlceCoreToCoreBase[0];
    #endif
    #endif

    if (NULL_PTR != State)
    {
        /* the driver has been initialized */
        IrqFlags = Base->SR & (LPSPI_SR_TDF_MASK | LPSPI_SR_RDF_MASK | LPSPI_SR_TEF_MASK | LPSPI_SR_REF_MASK);
        IrqFlags &= Base->IER & (LPSPI_IER_TDIE_MASK | LPSPI_IER_RDIE_MASK | LPSPI_IER_TEIE_MASK | LPSPI_IER_REIE_MASK);
        
        if (0u != IrqFlags)
        {
            #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
            if (
                (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType) ||
                (LPSPI_IP_HALF_DUPLEX_RECEIVE == State->ExternalDevice->DeviceParams->TransferType)
                )
            {
                Lpspi_Ip_TransferProcessHalfDuplex(Instance);    
            }
            else
            #endif
            {
                Lpspi_Ip_TransferProcess(Instance); 
            }
        }
        else
        {
            #ifdef LPSPI_IP_LLCE_SUPPORT
            #if (LPSPI_IP_LLCE_SUPPORT == STD_ON)
            /* This behavior doesn't affect to supricious interrupt handler, only clear forwarding interrupt flag not SPI status flag */
            if((BaseCoreToCore->HINTCR[1] & (((uint32)0x01U) << ((uint32)Instance))) != 0U)
            {
                /* Clears interrupt flags to host */
                BaseCoreToCore->HINTCR[1] = (((uint32)0x01U) << ((uint32)Instance));
            }
            #endif
            #endif
        }
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags */
        Lpspi_Ip_ClearStatusFlag(Instance);
    }
}

/**
* @brief            Get status of HW unit.
* @details          This function returns the status of the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           Lpspi_Ip_HwStatusType
*/
Lpspi_Ip_HwStatusType Lpspi_Ip_GetStatus(uint8 Instance)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_HwStatusType Status = LPSPI_IP_UNINIT;
    
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
    #endif
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    if (State != NULL_PTR)
    {
        Status = State->Status;
    }
    
    return Status;
}

#if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
Lpspi_Ip_StatusType Lpspi_Ip_SetClockMode(uint8 Instance, Lpspi_Ip_DualClockModeType ClockMode)
{
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
    #endif
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == LPSPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Clock mode can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        State->ClockMode = ClockMode;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }  
    return Status;
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif

#ifdef __cplusplus
}
#endif

/** @} */
