/*
*   Copyright 2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "check_example.h"
#include "Mcu.h"
#include "Pcie.h"
#include "Pcie_Ip_Irq.h"
#include "Serdes.h"
#include "sys_init.h"
#include "SchM_Serdes.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Macros to set and get the status of the example run */
#define App_SetSuccessStatus(value)         (u32NumFailedApiCalls += ((value) ? 0U : 1U))
#define App_GetSuccessStatus()              (0U == u32NumFailedApiCalls)


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/* Select MSI or MSIX. Only one of them should be active. */
#define MSI_ENABLE              1
#define MSIX_ENABLE             0

#define PCIE_DEVICE              0U
#define PCIE_INSTANCE            1U
#define PCIE1_BASE          (uint64)0x4800000000
#define PCIE_IATU_OUT_REG        0U
#define PCIE_DMA_CHANNEL         0U
#define PCIE_DMA_CHANNEL_LL      1U


#define PCIE_DATA_SIZE      0x100
#define PCIE_DATA_SIZE_LL   0xC00
#define PCIE_DATA_OFF_LL    0x10
#define PCIE_WRITE_OFFSET   0x100
#define PCIE_LL_BASE        0x1000
#define PCIE_LL_SIZE        11U
#define PCIE_LL_TRANSFERS   30U
#define PCIE_LL_INT_WAIT    1U
#define PCIE_LL_INT_STEP    3U
#define PCIE_BAD_ADDR       0x22000000


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define PCIE_MEM_REGION_SIZE_0     0x10000U  
#define PCIE_MEM_REGION_SIZE_1     0x10000U  
#define PCIE_MEM_REGION_SIZE_4     0x10000U  

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define PCIE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Pcie_MemMap.h"

/* Counter for errors during test  */
volatile uint32 u32NumFailedApiCalls = 0U; 
/* Arrays in which to map bar regions. Names must match PCIe configuration. Other options are linker symbols or numeric addresses. */
uint8 pcieMem_0[PCIE_MEM_REGION_SIZE_0] __attribute__ ((aligned (PCIE_MEM_REGION_SIZE_0)));
uint8 pcieMem_1[PCIE_MEM_REGION_SIZE_1] __attribute__ ((aligned (PCIE_MEM_REGION_SIZE_1)));
uint8 pcieMem_4[PCIE_MEM_REGION_SIZE_4] __attribute__ ((aligned (PCIE_MEM_REGION_SIZE_4)));
/* Address and size of RC region to read/write */
uint64 RC_memAddr;
uint32 RC_mem_size;

/* Arrays for data read/write via DMA */
volatile uint32 Pcie_DataRead1[PCIE_DATA_SIZE];
volatile uint32 Pcie_DataRead2[PCIE_DATA_SIZE];
volatile uint32 Pcie_DataWrite[PCIE_DATA_SIZE];
/* Arrays for DMA - Linked List */
Pcie_DmaLlElementType llPtr[PCIE_LL_SIZE];
volatile uint32 Pcie_DataReadLl[PCIE_DATA_SIZE_LL + PCIE_DATA_OFF_LL * (PCIE_LL_TRANSFERS - 1U)];
volatile uint32 Pcie_DataWriteLl[PCIE_DATA_SIZE_LL];
volatile uint32 Pcie_DataWriteLlReadback[PCIE_DATA_SIZE_LL + PCIE_DATA_OFF_LL * (PCIE_LL_TRANSFERS - 1U)];

/* Variables used by interrupt handler */
volatile boolean pcie_dma_ll_ready = TRUE;

volatile uint32 dmaReadDoneEvents = 0U;
volatile uint32 dmaReadErrorEvents = 0U;
volatile uint32 dmaWriteDoneEvents = 0U;
volatile uint32 dmaWriteErrorEvents = 0U;

uint32 eventsWatermark = 0U;

/* Transfer descriptors for DMA read/write */
Pcie_DmaReadDescriptorType readDesc;
Pcie_DmaWriteDescriptorType writeDesc;


#define PCIE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Pcie_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void delay(uint32 n);
static Pcie_StatusType Check_pcieData(void);
static void Init_pcieData(void);
static void WaitRC(void);
static Pcie_StatusType CheckLlDataRead(void);
static Pcie_StatusType CheckLlDataWrite(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/* Introduces a delay */
static void delay(uint32 n)
{
    volatile uint32 i = n;
    for (i = 0U; i < n; i++);
}

/* Initialize test data */
static void Init_pcieData(void)
{
    uint32 i;

    for (i = 0U; i < PCIE_DATA_SIZE; i++)
    {
        Pcie_DataWrite[i] = (uint32)((i & 0xF) * 0x11111111U);
    }
    for (i = 0U; i < PCIE_DATA_SIZE_LL; i++)
    {
        Pcie_DataWriteLl[i] = (uint32)((i & 0xF) * 0x11111111U);
    }

}

/* Fills a read transfer descriptor */
static void FillReadDesc(Pcie_DmaReadDescriptorType* readDesc, uint64 srcAddr, uint32 dstAddr, uint32 size, uint16 transferId, boolean interrupt)
{
    readDesc->srcAddr = srcAddr;
    readDesc->dstAddr = dstAddr;
    readDesc->size = size;
    readDesc->transferId = transferId;
    readDesc->interrupt = interrupt;
}

/* Fills a write transfer descriptor */
static void FillWriteDesc(Pcie_DmaWriteDescriptorType* writeDesc, uint32 srcAddr, uint64 dstAddr, uint32 size, uint16 transferId, boolean interrupt)
{
    writeDesc->srcAddr = srcAddr;
    writeDesc->dstAddr = dstAddr;
    writeDesc->size = size;
    writeDesc->transferId = transferId;
    writeDesc->interrupt = interrupt;
}

/* Checks correctness of DMA read/write data */
static Pcie_StatusType Check_pcieData(void)
{
    uint32 i;
    uint32 byteVal;
    uint32 rcValue;
    Pcie_StatusType RetVal = PCIE_SUCCESS;

    for (i = 0U; i < PCIE_DATA_SIZE; i++)
    {
        /* Check read data. RC memory is pre-initialized with 0, 1, 2, ... */
        byteVal = (4U * i) & 0xFF;
        rcValue =  byteVal + ((byteVal + 1U) << 8U) + ((byteVal + 2U) << 16U) + ((byteVal + 3U) << 24U);
        if (Pcie_DataRead1[i] != rcValue)
        {
            RetVal = PCIE_ERROR;
        }
        /* Check write data matches read back data. */
        if (Pcie_DataWrite[i] != Pcie_DataRead2[i])
        {
            RetVal = PCIE_ERROR;
        }
    }
    return RetVal;
}

/* Waits for Root Complex application to start and send us the address and size of the shared memory */
static void WaitRC(void)
{
    volatile uint64* RC_memAddrPtr;
    volatile uint32* RC_mem_sizePtr;

    /* read address and size from the first 2 locations of the memory region defined by BAR 0 */
    RC_memAddrPtr = (volatile uint64*)(pcieMem_0);
    RC_mem_sizePtr = (volatile uint32*)(&RC_memAddrPtr[1]);
    /* wait for RC to write data */
    while( (*RC_memAddrPtr == 0) || (*RC_mem_sizePtr == 0) );

    /* copy address and size to global vars */
    RC_memAddr = *RC_memAddrPtr;
    RC_mem_size = *RC_mem_sizePtr;
}

/* Checks correctness of DMA - linked list read data */
static Pcie_StatusType CheckLlDataRead(void)
{
    uint32 i;
    uint32 dataCnt = 0U;
    uint32 dataVal;
    uint8 *dataPtr = (uint8 *)Pcie_DataReadLl;
    Pcie_StatusType RetVal = PCIE_SUCCESS;

    /* Reads are partially overlapped to keep memory consumption reasonable */
    for (i = 0U; i < PCIE_LL_TRANSFERS; i++)
    {
        for (dataVal = 0U; dataVal < PCIE_DATA_OFF_LL * 4U; dataCnt++, dataVal++)
        {
            if (dataPtr[dataCnt] != (uint8)dataVal) 
            {
                RetVal = PCIE_ERROR;
            }
        }
    }
    for (; dataVal < PCIE_DATA_SIZE_LL * 4U; dataCnt++, dataVal++)
    {
        if (dataPtr[dataCnt] != (uint8)dataVal) 
        {
            RetVal = PCIE_ERROR;
        }
    }
    return RetVal;
}

/* Checks correctness of DMA - linked list write data */
static Pcie_StatusType CheckLlDataWrite(void)
{
    Pcie_StatusType RetValPcie;
    uint32 i;
    uint32 dataCnt = 0U;
    uint32 dataVal;
    uint8 *dataPtr = (uint8 *)Pcie_DataWriteLlReadback;
    Pcie_StatusType RetVal = PCIE_SUCCESS;

    /* Read back data through the DMA non-ll channel */
    FillReadDesc(&readDesc, (uint64)(PCIE1_BASE + PCIE_LL_BASE), (uint32)(&Pcie_DataWriteLlReadback), sizeof(Pcie_DataWriteLlReadback), 0U, FALSE);
    RetValPcie = Pcie_DmaRead(PCIE_DEVICE, PCIE_DMA_CHANNEL, &readDesc);
    App_SetSuccessStatus(PCIE_SUCCESS == RetValPcie);
    while((RetValPcie = Pcie_DmaCheckReadStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_SUCCESS == RetValPcie);

    /* Writes are partially overlapped to keep memory consumption reasonable */
    for (i = 0U; i < PCIE_LL_TRANSFERS; i++)
    {
        for (dataVal = 0U; dataVal < PCIE_DATA_OFF_LL * 4U; dataCnt++, dataVal++)
        {
            if (dataPtr[dataCnt] != (uint8)(((dataVal >> 2U) & 0xF) * 0x11U))
            {
                RetVal = PCIE_ERROR;
            }
        }
    }
    for (; dataVal < PCIE_DATA_SIZE_LL * 4U; dataCnt++, dataVal++)
    {
        if (dataPtr[dataCnt] != (uint8)(((dataVal >> 2U) & 0xF) * 0x11U))
        {
            RetVal = PCIE_ERROR;
        }
    }
    return RetVal;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/* Handler for DMA read done event */
void dmaReadDoneHandler(uint8 instance, uint8 channel, uint16 transferId)
{
    static uint16 expectedId = 1U;
    App_SetSuccessStatus(instance == PCIE_INSTANCE);
    App_SetSuccessStatus(channel == PCIE_DMA_CHANNEL_LL);
    App_SetSuccessStatus(transferId == expectedId);
    expectedId ++;
    dmaReadDoneEvents++;
}

/* Handler for DMA read error event */
void dmaReadErrorHandler(uint8 instance, uint8 channel)
{
    App_SetSuccessStatus(instance == PCIE_INSTANCE);
    App_SetSuccessStatus(channel == PCIE_DMA_CHANNEL_LL);
    dmaReadErrorEvents++;
}

/* Handler for DMA write done event */
void dmaWriteDoneHandler(uint8 instance, uint8 channel, uint16 transferId)
{
    static uint16 expectedId = 1U;
    App_SetSuccessStatus(instance == PCIE_INSTANCE);
    App_SetSuccessStatus(channel == PCIE_DMA_CHANNEL_LL);
    App_SetSuccessStatus(transferId == expectedId);
    expectedId ++;
    dmaWriteDoneEvents++;
}

/* Handler for DMA write error event */
void dmaWriteErrorHandler(uint8 instance, uint8 channel)
{
    App_SetSuccessStatus(instance == PCIE_INSTANCE);
    App_SetSuccessStatus(channel == PCIE_DMA_CHANNEL_LL);
    dmaWriteErrorEvents++;
}


/**
 * Pcie example main function      
 */
int main(void) 
{
    volatile Pcie_StatusType RetStatusPcie = PCIE_ERROR;
    volatile Std_ReturnType RetValPcie = PCIE_ERROR;
    uint32 i;
    uint32 transferId;
    static Pcie_OutRegDescriptorType RegionDescr;

    /* Configure MCU */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() ){}
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

    /* Install PCIe 1 DMA interrupt handler */
    sys_registerIsrHandler(214, Pcie_Ip_PCIE_1_DmaIRQHandler);
    sys_enableIsrSource(214, 0xF0);

    /* Initialize data to be written via PCIe */
    Init_pcieData();
    /* =============================================================================================================================== */
    /*    Serdes/PCIe drivers initialization                                                                           */ 
    /* =============================================================================================================================== */

    /* Init SerDes device */
    Serdes_Init(NULL_PTR);
	while (SERDES_INIT_PENDING == Serdes_GetJobResult())
	{
		Serdes_MainFunction();
	}

    /* Init PCIe */
    Pcie_Init(NULL_PTR);

    /* Wait for RC to be up and send us the address and size for the outbound region */
    WaitRC();

    /* =============================================================================================================================== */
    /*    Test set outbound window                                                                           */ 
    /* =============================================================================================================================== */
    /* Set outbound region */
    RegionDescr.regNo = PCIE_IATU_OUT_REG; 
    RegionDescr.srcAddr = PCIE1_BASE;      
    RegionDescr.srcAddrLim = (uint32)(PCIE1_BASE + RC_mem_size);  
    RegionDescr.dstAddr = RC_memAddr; 
    RegionDescr.type = PCIE_IATU_REG_TYPE_MEM; 
    RetValPcie = Pcie_SetOutboundRegion(PCIE_DEVICE, &RegionDescr);
    App_SetSuccessStatus(E_OK == RetValPcie);

    /* =============================================================================================================================== */
    /*    Test DMA read/write in normal mode                                                                           */ 
    /* =============================================================================================================================== */
    /* Read data through DMA - Bad address */
    FillReadDesc(&readDesc, (uint64)PCIE_BAD_ADDR, (uint32)(&Pcie_DataRead1), sizeof(Pcie_DataRead1), 0U, FALSE);
    RetStatusPcie = Pcie_DmaRead(PCIE_DEVICE, PCIE_DMA_CHANNEL, &readDesc);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckReadStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_ERROR == RetStatusPcie);          /* Expect error because of bad address */
    /* Read data through DMA */
    FillReadDesc(&readDesc, (uint64)PCIE1_BASE, (uint32)(&Pcie_DataRead1), sizeof(Pcie_DataRead1), 0U, FALSE);
    RetStatusPcie = Pcie_DmaRead(PCIE_DEVICE, PCIE_DMA_CHANNEL, &readDesc);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckReadStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);

    /* Write data through DMA - Bad address */
    FillWriteDesc(&writeDesc, (uint32)PCIE_BAD_ADDR, (uint64)(PCIE1_BASE + PCIE_WRITE_OFFSET), sizeof(Pcie_DataWrite), 0U, FALSE);
    RetStatusPcie = Pcie_DmaWrite(PCIE_DEVICE, PCIE_DMA_CHANNEL, &writeDesc);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckWriteStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_ERROR == RetStatusPcie);          /* Expect error because of bad address */
    /* Write data through DMA */
    FillWriteDesc(&writeDesc, (uint32)(&Pcie_DataWrite), (uint64)(PCIE1_BASE + PCIE_WRITE_OFFSET), sizeof(Pcie_DataWrite), 0U, FALSE);
    RetStatusPcie = Pcie_DmaWrite(PCIE_DEVICE, PCIE_DMA_CHANNEL, &writeDesc);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckWriteStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    /* Read back data through DMA to check it */
    FillReadDesc(&readDesc, (uint64)(PCIE1_BASE + PCIE_WRITE_OFFSET), (uint32)(&Pcie_DataRead2), sizeof(Pcie_DataRead2), 0U, FALSE);
    RetStatusPcie = Pcie_DmaRead(PCIE_DEVICE, PCIE_DMA_CHANNEL, &readDesc);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckReadStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    RetStatusPcie = Check_pcieData();
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);

    /* =============================================================================================================================== */
    /*    Test DMA read in linked-list mode                                                                           */ 
    /* =============================================================================================================================== */
    pcie_dma_ll_ready = TRUE;
    eventsWatermark = dmaReadDoneEvents;
    /* Prepare DMA channel for linked list operation */
    RetValPcie = Pcie_DmaLlReadSetup(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, llPtr, PCIE_LL_SIZE);
    App_SetSuccessStatus(E_OK == RetValPcie);
    /* Enable interrupt */
    Pcie_DmaReadIntEnable(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, TRUE);
    App_SetSuccessStatus(E_OK == RetValPcie);
    transferId = (PCIE_LL_INT_STEP == 1U) ? 1U : 0U;
    for (i = 0U; i < PCIE_LL_TRANSFERS; )
    {
        if (pcie_dma_ll_ready == TRUE)
        {
            FillReadDesc(&readDesc, (uint64)(PCIE1_BASE + PCIE_LL_BASE), (uint32)(&(Pcie_DataReadLl[i * PCIE_DATA_OFF_LL])), PCIE_DATA_SIZE_LL * 4U, transferId, ((i % PCIE_LL_INT_STEP) == (PCIE_LL_INT_STEP - 1U)) ? TRUE : FALSE);
            RetStatusPcie = Pcie_DmaRead(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, &readDesc);
            if (RetStatusPcie == PCIE_ERROR) break;
            if (RetStatusPcie == PCIE_BUSY) 
            {
                /* Linked list is full, retry operation later */
                if (PCIE_LL_INT_WAIT == 1U)
                {
                    /* Wait for the interrupt before retrying */
                    pcie_dma_ll_ready = FALSE;
                }
                continue;
            }
            i++;
            /* Increment transferID on transfers which request interrupt */
            transferId += ((i % PCIE_LL_INT_STEP) == (PCIE_LL_INT_STEP - 1U)) ? 1U : 0U;
        }
        else
        {
            /* wait for read done event */
            if (eventsWatermark != dmaReadDoneEvents)
            {
                eventsWatermark = dmaReadDoneEvents;
                pcie_dma_ll_ready = TRUE;
            }
        }
    }
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckReadStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    RetStatusPcie = CheckLlDataRead();
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    App_SetSuccessStatus(dmaReadDoneEvents == PCIE_LL_TRANSFERS / PCIE_LL_INT_STEP);

    /* =============================================================================================================================== */
    /*    Test DMA write in linked-list mode                                                                           */ 
    /* =============================================================================================================================== */
    pcie_dma_ll_ready = TRUE;
    eventsWatermark = dmaWriteDoneEvents;
    RetValPcie = Pcie_DmaLlWriteSetup(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, llPtr, PCIE_LL_SIZE);
    App_SetSuccessStatus(E_OK == RetValPcie);
    /* Enable interrupt */
    Pcie_DmaWriteIntEnable(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, TRUE);
    App_SetSuccessStatus(E_OK == RetValPcie);
    transferId = (PCIE_LL_INT_STEP == 1U) ? 1U : 0U;
    for (i = 0U; i < PCIE_LL_TRANSFERS; )
    {
        if (pcie_dma_ll_ready == TRUE)
        {
            FillWriteDesc(&writeDesc, (uint32)(&Pcie_DataWriteLl), (uint64)(PCIE1_BASE + PCIE_LL_BASE + i * PCIE_DATA_OFF_LL * sizeof(uint32)), PCIE_DATA_SIZE_LL * 4U, transferId, ((i % PCIE_LL_INT_STEP) == (PCIE_LL_INT_STEP - 1U)) ? TRUE : FALSE);
            RetStatusPcie = Pcie_DmaWrite(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, &writeDesc);
            if (RetStatusPcie == PCIE_ERROR) break;
            if (RetStatusPcie == PCIE_BUSY) 
            {
                /* Linked list is full, retry operation later */
                if (PCIE_LL_INT_WAIT == 1U)
                {
                    /* Wait for the interrupt before retrying */
                    pcie_dma_ll_ready = FALSE;
                }
                continue;
            }
            i++;
            /* Increment transferID on transfers which request interrupt */
            transferId += ((i % PCIE_LL_INT_STEP) == (PCIE_LL_INT_STEP - 1U)) ? 1U : 0U;
        }
        else
        {
            /* wait for read done event */
            if (eventsWatermark != dmaWriteDoneEvents)
            {
                eventsWatermark = dmaWriteDoneEvents;
                pcie_dma_ll_ready = TRUE;
            }
        }
    }
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    while((RetStatusPcie = Pcie_DmaCheckWriteStatus(PCIE_DEVICE, PCIE_DMA_CHANNEL_LL, NULL_PTR)) == PCIE_BUSY);
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    RetStatusPcie = CheckLlDataWrite();
    App_SetSuccessStatus(PCIE_SUCCESS == RetStatusPcie);
    App_SetSuccessStatus(dmaWriteDoneEvents == PCIE_LL_TRANSFERS / PCIE_LL_INT_STEP);

    /* =============================================================================================================================== */
    /*    Test MSI                                                                           */ 
    /* =============================================================================================================================== */
    for (i = 0U; i < 10U; i++)
    {
        delay(1000000U);
#if (MSI_ENABLE == 1)
        /* Send MSI to RC in succession: 0,1,2,3 */
        RetValPcie = Pcie_SendMsi(PCIE_DEVICE, i & 3U);
        if ((i & 3U) <= 1U)
        {
            App_SetSuccessStatus(E_OK == RetValPcie);
        }
        else
        {
            /* RC is configured to allow 2 MSIs, so MSIs 2 and 3 should return error */
            App_SetSuccessStatus(E_NOT_OK == RetValPcie);
        }
#elif (MSIX_ENABLE == 1)
        /* Send MSI-X to RC */
        RetValPcie = Pcie_SendMsiX(PCIE_DEVICE, i & 3U);
        App_SetSuccessStatus(E_OK == RetValPcie);
#endif
    }

    /* =============================================================================================================================== */
    /*    Finish application execution, signaling the status                                                                           */ 
    /* =============================================================================================================================== */
    Exit_Example(App_GetSuccessStatus());
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
