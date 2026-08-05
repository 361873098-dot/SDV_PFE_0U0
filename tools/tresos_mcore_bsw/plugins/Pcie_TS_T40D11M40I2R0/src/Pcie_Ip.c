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

#include "Pcie_Ip.h"
#include "Pcie_Cfg.h"
#include "Pcie_Ip_HwAccess.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Pcie_Ip.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IP_VENDOR_ID_C                      43
#define PCIE_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define PCIE_IP_AR_RELEASE_MINOR_VERSION_C       4
#define PCIE_IP_AR_RELEASE_REVISION_VERSION_C    0
#define PCIE_IP_SW_MAJOR_VERSION_C               4
#define PCIE_IP_SW_MINOR_VERSION_C               0
#define PCIE_IP_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pcie_Ip header file are of the same vendor */
#if (PCIE_IP_VENDOR_ID_C != PCIE_IP_VENDOR_ID)
    #error "Pcie_Ip.c and Pcie_Ip.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip header file are of the same Autosar version */
#if ((PCIE_IP_AR_RELEASE_MAJOR_VERSION_C    != PCIE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_MINOR_VERSION_C    != PCIE_IP_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip.c and Pcie_Ip.h are different"
#endif
/* Check if current file and Pcie_Ip header file are of the same Software version */
#if ((PCIE_IP_SW_MAJOR_VERSION_C != PCIE_IP_SW_MAJOR_VERSION) || \
     (PCIE_IP_SW_MINOR_VERSION_C != PCIE_IP_SW_MINOR_VERSION) || \
     (PCIE_IP_SW_PATCH_VERSION_C != PCIE_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip.c and Pcie_Ip.h are different"
#endif

/* Check if current file and Pcie_Cfg header file are of the same vendor */
#if (PCIE_IP_VENDOR_ID_C != PCIE_CFG_VENDOR_ID)
    #error "Pcie_Ip.c and Pcie_Cfg.h have different vendor ids"
#endif
/* Check if current file and Pcie_Cfg header file are of the same Autosar version */
#if ((PCIE_IP_AR_RELEASE_MAJOR_VERSION_C    != PCIE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_MINOR_VERSION_C    != PCIE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_REVISION_VERSION_C != PCIE_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip.c and Pcie_Cfg.h are different"
#endif
/* Check if current file and Pcie_Cfg header file are of the same Software version */
#if ((PCIE_IP_SW_MAJOR_VERSION_C != PCIE_CFG_SW_MAJOR_VERSION) || \
     (PCIE_IP_SW_MINOR_VERSION_C != PCIE_CFG_SW_MINOR_VERSION) || \
     (PCIE_IP_SW_PATCH_VERSION_C != PCIE_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip.c and Pcie_Cfg.h are different"
#endif

/* Check if current file and Pcie_Ip_HwAccess header file are of the same vendor */
#if (PCIE_IP_VENDOR_ID_C != PCIE_IP_HWACCESS_VENDOR_ID)
#error "Pcie_Ip.c and Pcie_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip_HwAccess header file are of the same Autosar version */
#if ((PCIE_IP_AR_RELEASE_MAJOR_VERSION_C != PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_MINOR_VERSION_C != PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip.c and Pcie_Ip_HwAccess.h are different"
#endif
/* Check if current file and Pcie_Ip_HwAccess header file are of the same software version */
#if ((PCIE_IP_SW_MAJOR_VERSION_C != PCIE_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (PCIE_IP_SW_MINOR_VERSION_C != PCIE_IP_HWACCESS_SW_MINOR_VERSION) || \
     (PCIE_IP_SW_PATCH_VERSION_C != PCIE_IP_HWACCESS_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip.c and Pcie_Ip_HwAccess.h are different"
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define PCIE_IP_DMA_LL_TRANSFERID_OFFSET        16U
#define PCIE_IP_DMA_LL_TRANSFER_REPORTED_MASK   0x8000U

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#define PCIE_IP_BASE(instance) (((instance) == 0U)  ? (PCIE_IP_S32G_PCIE_0_BASE_U32) : (PCIE_IP_S32G_PCIE_1_BASE_U32))

#define PCIE_IP_SERDES_SS_BASE_ADDR(instance)    ((SerDes_SS_Type *)(PCIE_IP_BASE(instance) + PCIE_IP_SERDES_SS_BASE))

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


typedef struct
{
    Pcie_DmaLlElementType *list;         /* Linked list for this channel                                                             */
    uint32 size;                         /* Size of linked list                                                                      */
    uint32 pcs;                          /* Producer Cycle State - value used to initialize Cycle Bit of list elements               */
    uint32 swLlp;                        /* Index of the next element in the linked list to be used by producer (sw)                 */
}Pcie_Ip_DmaLlStateType;


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define PCIE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pcie_MemMap.h"

static Pcie_Ip_DmaLlStateType pcieLlReadState[PCIE_HW_MAX_MODULES][PCIE_DMA_READ_CHANNELS_COUNT];
static Pcie_Ip_DmaLlStateType pcieLlWriteState[PCIE_HW_MAX_MODULES][PCIE_DMA_WRITE_CHANNELS_COUNT];

static const Pcie_Ip_ConfigType * Pcie_Ip_Config[PCIE_HW_MAX_MODULES];

#define PCIE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pcie_MemMap.h"


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"

/* Configures link width */
static inline uint32 Pcie_Ip_LinkedListMoveBackPosition (uint32 addr,
                                                         uint32 size)
{
    uint32 new_addr;
    /* Move back one position to get the last completed transfer */
    if (0U == addr)
    {
        new_addr = size - 2U;   /* Last data element */
    }
    else
    {
        new_addr = addr - 1U;           /* Previous data element */
    }

    return new_addr;
}

/* Configures link width */
static void Pcie_Ip_SetLinkWidth(uint32 base,
                                 Pcie_Ip_LinkWidthType linkwidth)
{
    /* Set link width */
    Serdes_Pcie_Ip_SetLinkWidth((PCIE_EP_Type *)base, linkwidth);

    if (PCIE_IP_LINK_WIDTH_X1 == linkwidth)
    {
        /* Set link X1 */
        Serdes_Pcie_Ip_SetLinkCapable((PCIE_EP_Type *)base, 1U);
    }
    else
    {
        Serdes_Pcie_Ip_SetLinkCapable((PCIE_EP_Type *)base, 3U);
    }
}

/* Initialized PCIe link in Endpoint mode */
static void Pcie_Ip_InitEp(uint32 base,
                           Pcie_Ip_ModeType pcieType,
                           Pcie_Ip_LinkWidthType linkwidth)
{
    /* Set device type */
    Serdes_Pcie_Ip_SetType(base, pcieType);

    /* Enable direct speed change */
    Serdes_Pcie_Ip_SpeedChange((PCIE_EP_Type *)base);

    /* Disable phase 2,3 equalization */
    Serdes_Pcie_Ip_DisablePhase_2_3_eq((PCIE_EP_Type *)base);

    Pcie_Ip_SetLinkWidth(base, linkwidth);

    /* Configure transactions as Cacheable, Outer Shareable. */
    Serdes_Pcie_Ip_ChangeMstrAceCache((PCIE_EP_Type *)base, 3U, 3U);
    Serdes_Pcie_Ip_ChangeMstrAceDomain((PCIE_EP_Type *)base, 0U, 0U);

    /* Enable direct speed change */
    Serdes_Pcie_Ip_SpeedChange((PCIE_EP_Type *)base);

    /* Disable phase 2,3 equalization */
    Serdes_Pcie_Ip_DisablePhase_2_3_eq((PCIE_EP_Type *)base);

    Serdes_Pcie_Ip_Gen3RelatedEqPhase_2_3((PCIE_EP_Type *)base);
}

/* Configure BAR registers */
static void Pcie_Ip_Init_Set_Bars(uint32 base,
                                  const Pcie_Ip_ConfigType *pcieConfig)
{
    uint8 idx;

    /* Configure the BAR registers with required address spaces.  */
    for (idx = 0U; idx < PCIE_IP_NUMBER_OF_BARS; idx++)
    {
        Serdes_Pcie_Ip_SetupBar(base, (uint32) ((uint32)PCIE_IP_BAR0 + ((uint32)idx * 4U)), pcieConfig->bars[idx].size, pcieConfig->bars[idx].type);
    }
}

/* Configures the Internal Address Translation Unit */
static void Pcie_Ip_Init_Set_Iatu(uint32 base,
                                const Pcie_Ip_ConfigType *pcieConfig)
{
    uint32 region = 0U;
    uint8 idx;
    uint32 type = (uint32)PCIE_IATU_REG_TYPE_MEM;

    for (idx = 0U; idx < PCIE_IP_NUMBER_OF_BARS; idx++)
    {
        /* Setup inbound region for BARs with non-zero size, except for the BAR reserved for MSI-X  */
        if ((pcieConfig->bars[idx].size > 0U) && !((pcieConfig->msixSupport == TRUE) && (idx == PCIE_MSIX_BAR)))
        {
            /* Check type */
            if (PCIE_IP_BAR_TYPE_IO == (pcieConfig->bars[idx].type & PCIE_IP_BAR_TYPE_IO))
            {
                type = (uint32)PCIE_IATU_REG_TYPE_IO;
            }
            else
            {
                type = (uint32)PCIE_IATU_REG_TYPE_MEM;
            }
            Serdes_Pcie_Ip_IatuInboundSetBar(base, region, idx, (uint32)(pcieConfig->bars[idx].memStart), type);
            region++;
        }
    }
}

/* Checks the status of a read channel. */
static Pcie_Ip_StatusType Pcie_Ip_DmaCheckReadChannelStatusInternal(uint8 instance,
                                                                    uint8 channel)
{
    uint32 cs;
    uint32 transferSize;
    Pcie_Ip_StatusType status;
    uint32 base = PCIE_IP_BASE(instance);

    /* read channel status */
    cs = Serdes_Pcie_Ip_DmaReadGetCs(base, channel);
    if (PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_HALTED_U32  == cs)
    {
        /* DMA channel reported errors during transfer */
        status = PCIE_IP_ERROR;
    }
    else if (PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_RUNNING_U32  == cs)
    {
        /* DMA channel is running */
        status = PCIE_IP_BUSY;
    }
    else /* PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_STOPPED or PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_RESERVED */
    {
        /* DMA channel is stopped or never started. Additionally check that transfer size is 0 */
        transferSize = Serdes_Pcie_Ip_DmaReadGetTransferSize(base, channel);
        if (0u == transferSize)
        {
            status = PCIE_IP_SUCCESS;
        }
        else
        {
            status = PCIE_IP_BUSY;
        }
    }
    return status;
}

/* Checks the status of a write channel. */
static Pcie_Ip_StatusType Pcie_Ip_DmaCheckWriteChannelStatusInternal(uint8 instance,
                                                                     uint8 channel)
{
    uint32 cs;
    uint32 transferSize;
    Pcie_Ip_StatusType status;
    uint32 base = PCIE_IP_BASE(instance);

    /* read channel status */
    cs = Serdes_Pcie_Ip_DmaWriteGetCs(base, channel);
    if (PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_HALTED_U32  == cs)
    {
        /* DMA channel reported errors during transfer */
        status = PCIE_IP_ERROR;
    }
    else if ( PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_RUNNING_U32  == cs)
    {
        /* DMA channel is running */
        status = PCIE_IP_BUSY;
    }
    else /* PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_STOPPED or PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_RESERVED */
    {
        /* DMA channel is stopped or never started. Additionally check that transfer size is 0 */
        transferSize = Serdes_Pcie_Ip_DmaWriteGetTransferSize(base, channel);
        if (0u == transferSize)
        {
            status = PCIE_IP_SUCCESS;
        }
        else
        {
            status = PCIE_IP_BUSY;
        }
    }
    return status;
}

/* Checks the completion status of a normal read operation. Also clears any flags that are set. */
static Pcie_Ip_StatusType Pcie_Ip_DmaCheckReadFlagsInternal(uint8 instance,
                                                            uint8 channel)
{
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType status = PCIE_IP_BUSY;

    if (TRUE == Serdes_Pcie_Ip_DmaReadCheckClearComplete(base, channel))
    {
        status = PCIE_IP_SUCCESS;
    }
    if (TRUE == Serdes_Pcie_Ip_DmaReadCheckClearError(base, channel))
    {
        status = PCIE_IP_ERROR;
    }
    return status;
}

/* Checks the completion status of a normal write operation. Also clears any flags that are set. */
static Pcie_Ip_StatusType Pcie_Ip_DmaCheckWriteFlagsInternal(uint8 instance,
                                                             uint8 channel)
{
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType status = PCIE_IP_BUSY;

    if (TRUE == Serdes_Pcie_Ip_DmaWriteCheckClearComplete(base, channel))
    {
        status = PCIE_IP_SUCCESS;
    }
    if (TRUE == Serdes_Pcie_Ip_DmaWriteCheckClearError(base, channel))
    {
        status = PCIE_IP_ERROR;
    }
    return status;
}

/* Calls user handlers for DMA Read Done events. */
static void Pcie_Ip_CallReadDoneHandlers(uint8 instance,
                                         uint32 flags,
                                         uint8 channels,
                                         Pcie_DmaDoneHandlerPtrType handler)
{
    uint8 chanCnt;
    const Pcie_Ip_DmaLlStateType *state;
    uint32 llp;
    uint32 transferId;
    uint32 base = PCIE_IP_BASE(instance);

    if (NULL_PTR != handler)
    {
        for (chanCnt = 0U; chanCnt < channels; chanCnt++)
        {
            if ((flags & ((uint32)1U << chanCnt)) != 0U)
            {
                state = &(pcieLlReadState[instance][chanCnt]);
                /* check if the channel is configured in linked list mode */
                if (NULL_PTR == state->list)
                {   /* normal operation; use dummy transferId, as it is not used in this mode */
                    handler(instance, chanCnt, 0U);
                }
                else
                {   /* linked list operation */
                    /* get current link list pointer */
                    llp = Serdes_Pcie_Ip_DmaReadGetLlp(base, chanCnt);
                    llp = (llp - (uint32)(state->list)) / sizeof(Pcie_DmaLlElementType);
                    /* Move back one position to get the last completed transfer */
                    llp = Pcie_Ip_LinkedListMoveBackPosition(llp, state->size);

                    /* Call application handler to report completion of this transfer */
                    if (0u == ((state->list[llp]).ctrl & PCIE_IP_DMA_LL_TRANSFER_REPORTED_MASK))
                    {
                        transferId = (uint16)((state->list[llp]).ctrl >> PCIE_IP_DMA_LL_TRANSFERID_OFFSET);
                        handler(instance, chanCnt, transferId);
                        /* mark the transfer as reported */
                        (state->list[llp]).ctrl |= PCIE_IP_DMA_LL_TRANSFER_REPORTED_MASK;
                    }
                    else
                    {
                        /* transfer already reported, ignore it */
                    }
                }
            }
        }
    }
}

/* Calls user handlers for DMA Write Done events. */
static void Pcie_Ip_CallWriteDoneHandlers(uint8 instance,
                                          uint32 flags,
                                          uint8 channels,
                                          Pcie_DmaDoneHandlerPtrType handler)
{
    uint8 chanCnt;
    const Pcie_Ip_DmaLlStateType *state;
    uint32 llp;
    uint32 transferId;
    uint32 base = PCIE_IP_BASE(instance);

    if (handler != NULL_PTR)
    {
        for (chanCnt = 0U; chanCnt < channels; chanCnt++)
        {
            if ((flags & ((uint32)1U << chanCnt)) != 0U)
            {
                state = &(pcieLlWriteState[instance][chanCnt]);
                /* check if the channel is configured in linked list mode */
                if (NULL_PTR == state->list)
                {   /* normal operation; use dummy transferId, as it is not used in this mode */
                    handler(instance, chanCnt, 0U);
                }
                else
                {   /* linked list operation */
                    /* get current link list pointer */
                    llp = Serdes_Pcie_Ip_DmaWriteGetLlp(base, chanCnt);
                    llp = (llp - (uint32)(state->list)) / sizeof(Pcie_DmaLlElementType);
                    /* Move back one position to get the last completed transfer */
                    llp = Pcie_Ip_LinkedListMoveBackPosition(llp, state->size);

                    /* Call application handler to report completion of this transfer */
                    if (0U == ((state->list[llp]).ctrl & PCIE_IP_DMA_LL_TRANSFER_REPORTED_MASK))
                    {
                        transferId = (uint16)((state->list[llp]).ctrl >> PCIE_IP_DMA_LL_TRANSFERID_OFFSET);
                        handler(instance, chanCnt, transferId);
                        /* mark the transfer as reported */
                        (state->list[llp]).ctrl |= PCIE_IP_DMA_LL_TRANSFER_REPORTED_MASK;
                    }
                    else
                    {
                        /* transfer already reported, ignore it */
                    }
                }
            }
        }
    }
}

/* Calls user handlers for DMA Error events. */
static void Pcie_Ip_CallErrorHandlers(uint8 instance,
                                      uint32 flags,
                                      uint8 channels,
                                      Pcie_DmaErrorHandlerPtrType handler)
{
    uint8 chanCnt;

    if (handler != NULL_PTR)
    {
        for (chanCnt = 0U; chanCnt < channels; chanCnt++)
        {
            if ((flags & ((uint32)1U << chanCnt)) != 0U)
            {
                handler(instance, chanCnt);
            }
        }
    }
}

/*Add Write element to Linked List*/
static inline Pcie_Ip_StatusType Pcie_Ip_AddNewLlWriteElement(uint8 instance,
                                                              uint8 channel,
                                                              Pcie_Ip_DmaLlStateType *listState,
                                                              const Pcie_DmaWriteDescriptorType *writeDesc
                                                             )
{
    uint32 tempCtrl;
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType chanStatus;

    listState->list[listState->swLlp].size = writeDesc->size;
    listState->list[listState->swLlp].srcLow = writeDesc->srcAddr;
    listState->list[listState->swLlp].srcHigh = 0U;
    listState->list[listState->swLlp].destLow = (uint32)writeDesc->dstAddr;
    listState->list[listState->swLlp].destHigh = (uint32)(writeDesc->dstAddr >> 32U);
    MCAL_DATA_SYNC_BARRIER();
    /* update ctrl reg. last; once cycle bit is updated DMA has ownership */
    /* Store the transfer ID in the unused upper part of ctrl */
    tempCtrl = ((uint32)(writeDesc->transferId) << PCIE_IP_DMA_LL_TRANSFERID_OFFSET);
    if (TRUE == writeDesc->interrupt)
    {
        /* If callback notification is requested for this transfer, enable interrupt */
        tempCtrl |= PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_MASK_U32;
    }
    /* Toggle cycle bit to indicate DMA ownership */
    tempCtrl &= ~PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK_U32;
    tempCtrl |= (uint32)(listState->pcs << PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_SHIFT) & PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK_U32;
    listState->list[listState->swLlp].ctrl = tempCtrl;

    listState->swLlp++;
    if (listState->swLlp == (listState->size - 1U))
    {
        /* reached link element, toggle PCS and go back to the top*/
        listState->pcs = (1U - listState->pcs);
        tempCtrl = listState->list[listState->swLlp].ctrl & ~PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK_U32;
        tempCtrl |= (uint32)(listState->pcs << PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_SHIFT) & PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK_U32;
        listState->list[listState->swLlp].ctrl = tempCtrl;
        listState->swLlp = 0U;
    }
    /* Check if DMA must be manually restarted */
    chanStatus = Pcie_Ip_DmaCheckWriteChannelStatusInternal(instance, channel);

    /* If the channel status is PCIE_IP_SUCCESS then ring DMA doorbell to restart transfer in linked list mode for read channels */
    if (PCIE_IP_SUCCESS == chanStatus)
    {
        /* DMA is stopped or never started, ring doorbell */
        Serdes_Pcie_Ip_DmaWriteRingDoorbell(base, channel);
    }
    else
    {
        /* CDD_PCIE_00017: If the device reported an error during the DMA write, the function Pcie_DmaCheckWriteStatus() shall return PCIE_ERROR. */
        /* If the channel status is PCIE_IP_ERROR - the DMA is halted then do nothing and return chanStatus*/
        /* chanStatus is PCIE_IP_BUSY - DMA channel is running, no need to do anything */
    }
    return chanStatus;
}

/*Add Read element to Linked List*/
static inline Pcie_Ip_StatusType Pcie_Ip_AddNewLlReadElement(uint8 instance,
                                                             uint8 channel,
                                                             Pcie_Ip_DmaLlStateType *listState,
                                                             const Pcie_DmaReadDescriptorType *readDesc
                                                            )
{
    uint32 tempCtrl;
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType chanStatus;

    /* list is not full, add new element to the list */
    listState->list[listState->swLlp].size = readDesc->size;
    listState->list[listState->swLlp].srcLow = (uint32)readDesc->srcAddr;
    listState->list[listState->swLlp].srcHigh = (uint32)(readDesc->srcAddr >> 32U);
    listState->list[listState->swLlp].destLow = readDesc->dstAddr;
    listState->list[listState->swLlp].destHigh = 0U;
    MCAL_DATA_SYNC_BARRIER();
    /* update ctrl reg. last; once cycle bit is updated DMA has ownership */
    /* Store the transfer ID in the unused upper part of ctrl */
    tempCtrl = ((uint32)(readDesc->transferId) << PCIE_IP_DMA_LL_TRANSFERID_OFFSET);
    if (TRUE == readDesc->interrupt)
    {
        /* If callback notification is requested for this transfer, enable interrupt */
        tempCtrl |= PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_MASK_U32;
    }
    /* Toggle cycle bit to indicate DMA ownership */
    tempCtrl &= ~PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK_U32;
    tempCtrl |= (uint32)(listState->pcs << PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_SHIFT) & PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK_U32;
    listState->list[listState->swLlp].ctrl = tempCtrl;

    listState->swLlp++;
    if (listState->swLlp == (listState->size - 1U))
    {
        /* reached link element, toggle PCS and go back to the top*/
        listState->pcs = (1U - listState->pcs);
        tempCtrl = listState->list[listState->swLlp].ctrl & ~PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK_U32;
        tempCtrl |= (uint32)(listState->pcs << PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_SHIFT) & PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK_U32;
        listState->list[listState->swLlp].ctrl = tempCtrl;
        listState->swLlp = 0U;
    }
    /* check if DMA must be manually restarted */
    chanStatus = Pcie_Ip_DmaCheckReadChannelStatusInternal(instance, channel);

    /* If the channel status is PCIE_IP_SUCCESS then ring DMA doorbell to restart transfer in linked list mode for read channels */
    if (PCIE_IP_SUCCESS == chanStatus)
    {
        /* DMA is stopped or never started, ring doorbell */
        Serdes_Pcie_Ip_DmaReadRingDoorbell(base, channel);
    }
    else
    {
        /* CDD_PCIE_00010: If the device reported an error during the DMA read, the function Pcie_DmaCheckReadStatus() shall return PCIE_ERROR. */
        /* If the channel status is PCIE_IP_ERROR - the DMA is halted then do nothing and return chanStatus*/
        /* chanStatus is PCIE_IP_BUSY - DMA channel is running, no need to do anything */
    }
    return chanStatus;
}

/* Doing DMA read operation at linked list mode. */
static inline Pcie_Ip_StatusType Pcie_Ip_DmaReadAtLinkedListMode(uint8 instance,
                                                                 uint8 channel,
                                                                 Pcie_Ip_DmaLlStateType *state,
                                                                 const Pcie_DmaReadDescriptorType *readDesc
                                                                )
{
    uint32 llp;
    uint32 ccs;
    Pcie_Ip_StatusType status = PCIE_IP_SUCCESS;
    uint32 base = PCIE_IP_BASE(instance);

    /* linked list operation */
    if (Serdes_Pcie_Ip_DmaReadCheckError(base, channel))
    {
        /* There was an unreported transfer error for this channel, report it and exit */
        status = PCIE_IP_ERROR;
    }
    else
    {
        /* check if the list is full */
        llp = Serdes_Pcie_Ip_DmaReadGetLlp(base, channel);
        llp = (llp - (uint32)(state->list)) / sizeof(Pcie_DmaLlElementType);
        if (llp == state->swLlp)
        {
            /* List is either empty or full */
            ccs = Serdes_Pcie_Ip_DmaReadGetCcs(base, channel);
            if (state->pcs != ccs)
            {
                /* list is full */
                status = PCIE_IP_BUSY;
            }
        }
        if (PCIE_IP_SUCCESS == status)
        {
            /* Move back one position */
            llp = Pcie_Ip_LinkedListMoveBackPosition(llp, state->size);

            if (llp == state->swLlp)
            {
                /* List is almost full; to avoid a possible race condition the list will not be completely filled */
                status = PCIE_IP_BUSY;
            }
        }
        if (PCIE_IP_SUCCESS == status)
        {
            status = Pcie_Ip_AddNewLlReadElement(instance, channel, state, readDesc);

            /* Following the requirement CDD_PCIE_00005, the Pcie_DmaRead() only returns PCIE_BUSY when the device is busy with another transfer or the linked list is full. */
            /* In fact, before going to Pcie_Ip_AddNewLlReadElement(), the status is SUCCESS so if now the status is BUSY, it means that the DMA is running. */
            /* As the scope of Pcie_Ip_DmaRead(), we don't want to expose the BUSY status when DMA is running so the status needs to be changed from BUSY to SUCCESS */
            if (PCIE_IP_BUSY == status)
            {
                status = PCIE_IP_SUCCESS;
            }
        }
    }
    return status;
}

/* Doing DMA Write operation at linked list mode. */
static inline Pcie_Ip_StatusType Pcie_Ip_DmaWriteAtLinkedListMode(uint8 instance,
                                                                  uint8 channel,
                                                                  Pcie_Ip_DmaLlStateType *state,
                                                                  const Pcie_DmaWriteDescriptorType *writeDesc
                                                                 )
{
    uint32 llp;
    uint32 ccs;
    Pcie_Ip_StatusType status = PCIE_IP_SUCCESS;
    uint32 base = PCIE_IP_BASE(instance);

    /* linked list operation */
    if (Serdes_Pcie_Ip_DmaWriteCheckError(base, channel))
    {
        /* There was an unreported transfer error for this channel, report it and exit */
        status = PCIE_IP_ERROR;
    }
    else
    {
        /* check if the list is full */
        llp = Serdes_Pcie_Ip_DmaWriteGetLlp(base, channel);
        llp = (llp - (uint32)(state->list)) / sizeof(Pcie_DmaLlElementType);
        if (llp == state->swLlp)
        {
            /* List is either empty or full */
            ccs = Serdes_Pcie_Ip_DmaWriteGetCcs(base, channel);
            if (state->pcs != ccs)
            {
                /* list is full */
                status = PCIE_IP_BUSY;
            }
        }
        if (PCIE_IP_SUCCESS == status)
        {
            /* Move back one position */
            llp = Pcie_Ip_LinkedListMoveBackPosition(llp, state->size);

            if (llp == state->swLlp)
            {
                /* List is almost full; to avoid a possible race condition the list will not be completely filled */
                status = PCIE_IP_BUSY;
            }
        }
        if (PCIE_IP_SUCCESS == status)
        {
            /* list is not full, add new element to the list */
            status = Pcie_Ip_AddNewLlWriteElement(instance, channel, state, writeDesc);

            /* Following the requirement CDD_PCIE_00005, the Pcie_DmaRead() only returns PCIE_BUSY when the device is busy with another transfer or the linked list is full. */
            /* In fact, before going to Pcie_Ip_AddNewLlReadElement(), the status is SUCCESS so if now the status is BUSY, it means that the DMA is running. */
            /* As the scope of Pcie_Ip_DmaRead(), we don't want to expose the BUSY status when DMA is running so the status needs to be changed from BUSY to SUCCESS */
            if (PCIE_IP_BUSY == status)
            {
                status = PCIE_IP_SUCCESS;
            }
        }
    }
    return status;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Set Outbound Region
* @details      This function configures an oubound region in the PCIe module, allowing address tranlastion for outgoing TLPs.
*/
Pcie_Ip_StatusType Pcie_Ip_SetOutboundRegion(uint8 instance,
                                             const Pcie_OutRegDescriptorType *outRegDesc)
{
    uint32 base = PCIE_IP_BASE(instance);

    Serdes_Pcie_Ip_IatuOutboundSet(base, outRegDesc);
    return PCIE_IP_SUCCESS;
}

/**
* @brief        Send MSI interrupt
* @details      This function sends a MSI message to the RC.
*/

Pcie_Ip_StatusType Pcie_Ip_SendMsi(uint8 instance,
                                   uint32 intNo)
{
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType status = PCIE_IP_ERROR;

    if (intNo < Serdes_Pcie_Ip_MsiGetIntNo(base))
    {
        Serdes_Pcie_Ip_MsiTriggerSet(base, intNo);
        Serdes_Pcie_Ip_MsiTriggerReset(base, intNo);
        status = PCIE_IP_SUCCESS;
    }

    return status;
}

/**
* @brief        Send MSI-X interrupt
* @details      This function sends a MSI-X message to the RC.
*/
Pcie_Ip_StatusType Pcie_Ip_SendMsiX(uint8 instance,
                                    uint32 intNo)
{
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType status = PCIE_IP_ERROR;

    /* Check if MSIX is enabled by RC */
    if (Serdes_Pcie_Ip_MsixGetEnable(base))
    {
        Serdes_Pcie_Ip_MsxDoorbell(base, intNo);
        status = PCIE_IP_SUCCESS;
    }

    return status;
}

/**
* @brief        PCIe DMA read interrupt enable
* @details      This function enables/disables interrupt generation on the completion of a read operation
*
* @implements       Pcie_Ip_DmaReadIntEnable_Activity
*
*/
Pcie_Ip_StatusType Pcie_Ip_DmaReadIntEnable(uint8 instance,
                                            uint8 channel,
                                            boolean enable)
{
    uint32 base = PCIE_IP_BASE(instance);

    if (TRUE == enable)
    {
        Serdes_Pcie_Ip_DmaReadLocalIntUnmask(base, channel);
    }
    else
    {
        Serdes_Pcie_Ip_DmaReadLocalIntMask(base, channel);
    }
    return PCIE_IP_SUCCESS;
}

/**
* @brief        PCIe DMA write interrupt enable
* @details      This function enables/disables interrupt generation on the completion of a write operation
* 
* @implements       Pcie_Ip_DmaWriteIntEnable_Activity
*
*/
Pcie_Ip_StatusType Pcie_Ip_DmaWriteIntEnable(uint8 instance,
                                             uint8 channel,
                                             boolean enable)
{
    uint32 base = PCIE_IP_BASE(instance);

    if (TRUE == enable)
    {
        Serdes_Pcie_Ip_DmaWriteLocalIntUnmask(base, channel);
    }
    else
    {
        Serdes_Pcie_Ip_DmaWriteLocalIntMask(base, channel);
    }
    return PCIE_IP_SUCCESS;
}

/**
* @brief        PCIe DMA read
* @details      This function performs a read operation of a memory region from remote device to local memory.
*               If the channel was previously configured in linked list mode, the read will be added to the list,
*               otherwise it will started immediately.
*/
Pcie_Ip_StatusType Pcie_Ip_DmaRead(uint8 instance,
                                   uint8 channel,
                                   const Pcie_DmaReadDescriptorType *readDesc)
{
    Pcie_Ip_DmaLlStateType *state;
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType status = PCIE_IP_SUCCESS;
    uint64 srcAddr = readDesc->srcAddr;
    uint32 dstAddr = readDesc->dstAddr;
    uint32 size = readDesc->size;

    state = &(pcieLlReadState[instance][channel]);
    /* check if the channel is configured in linked list mode */
    if (NULL_PTR == state->list)
    {   /* normal operation */
        /* check if channel is idle */
        status = Pcie_Ip_DmaCheckReadChannelStatusInternal(instance, channel);
        if (status != PCIE_IP_BUSY)
        {
            /* Enable DMA Read Engine */
            Serdes_Pcie_Ip_DmaReadEngineEnable(base);
            /* Set LIE to allow poll of status reg. */
            Serdes_Pcie_Ip_DmaReadLocalIntEnable(base, channel);
            /* Set up and start the transfer */
            Serdes_Pcie_Ip_DmaReadStartTransfer(base, channel, srcAddr, dstAddr, size);
            status = PCIE_IP_SUCCESS;
        }
    }
    else
    {
        status = Pcie_Ip_DmaReadAtLinkedListMode(instance, channel, state, readDesc);
    }
    return status;
}

/**
* @brief        Pcie DMA write
* @details      This function performs a write operation of a memory region from remote device to local memory.
*               If the channel was previously configured in linked list mode, the write will be added to the list,
*               otherwise it will started immediately.
*/
Pcie_Ip_StatusType Pcie_Ip_DmaWrite(uint8 instance,
                                    uint8 channel,
                                    const Pcie_DmaWriteDescriptorType *writeDesc)
{
    Pcie_Ip_DmaLlStateType *state;
    uint32 base = PCIE_IP_BASE(instance);
    Pcie_Ip_StatusType status = PCIE_IP_SUCCESS;
    uint32 srcAddr = writeDesc->srcAddr;
    uint64 dstAddr = writeDesc->dstAddr;
    uint32 size = writeDesc->size;

    state = &(pcieLlWriteState[instance][channel]);
    /* check if the channel is configured in linked list mode */
    if (NULL_PTR == state->list)
    {   /* normal operation */
        /* check if channel is idle */
        status = Pcie_Ip_DmaCheckWriteChannelStatusInternal(instance, channel);
        if (status != PCIE_IP_BUSY)
        {
            /* Enable DMA Write Engine */
            Serdes_Pcie_Ip_DmaWriteEngineEnable(base);
            /* Set LIE to allow poll of status reg. */
            Serdes_Pcie_Ip_DmaWriteLocalIntEnable(base, channel);
            /* Set up and start the transfer */
            Serdes_Pcie_Ip_DmaWriteStartTransfer(base, channel, srcAddr, dstAddr, size);
            status = PCIE_IP_SUCCESS;
        }
    }
    else
    {
        status = Pcie_Ip_DmaWriteAtLinkedListMode(instance, channel, state, writeDesc);
    }
    return status;
}

/**
* @brief        Checks the status of a DMA read channel
* @details      This function checks the status of a DMA read channel configured either for normal or for linked list mode.
*/
Pcie_Ip_StatusType Pcie_Ip_DmaCheckReadStatus(uint8 instance,
                                              uint8 channel,
                                              uint32 *transfersLeft)
{
    uint32 llp;
    Pcie_Ip_StatusType status;
    const Pcie_Ip_DmaLlStateType *state;
    uint32 base = PCIE_IP_BASE(instance);
    uint32 msgLeftLocal = 0U;

    state = &(pcieLlReadState[instance][channel]);
    status = Pcie_Ip_DmaCheckReadChannelStatusInternal(instance, channel);
    /* check if the channel is configured in linked list mode */
    if (NULL_PTR == state->list)
    {   /* normal operation */
        msgLeftLocal = (PCIE_IP_BUSY == status)?1U:0U;
    }
    else
    {
        /* linked list operation */
        if (PCIE_IP_BUSY == status)
        {
            /* DMA channel is running, compute remaining elements */
            llp = Serdes_Pcie_Ip_DmaReadGetLlp(base, channel);
            llp = (llp - (uint32)(state->list)) / sizeof(Pcie_DmaLlElementType);
            if (llp < state->swLlp)
            {
                msgLeftLocal = state->swLlp - llp;
            }
            else
            {
                /* sw is one cycle ahead of DMA */
                msgLeftLocal = (state->size - 1U) + state->swLlp - llp;
            }
        }
        /* CDD_PCIE_00010: If the device reported an error during the DMA read, the function Pcie_DmaCheckReadStatus() shall return PCIE_ERROR. */
        /* CDD_PCIE_00011: If the DMA read is completed either succesfully or with an error, the function Pcie_DmaCheckReadStatus() shall also clear the DMA status bits, in addition to reporting the status. */
        else if (PCIE_IP_ERROR == status)
        {
            Serdes_Pcie_Ip_DmaReadRingDoorbell(base, channel);
        }
        else
        {
            /* status == PCIE_IP_SUCCESS - nothing to do but return status */
        }
    }
    /* clear any pending flags */
    (void)Pcie_Ip_DmaCheckReadFlagsInternal(instance, channel);
    if (NULL_PTR != transfersLeft)
    {
        *transfersLeft = msgLeftLocal;
    }
    return status;
}

/**
* @brief        Checks the status of a DMA write channel
* @details      This function checks the status of a DMA write channel configured either for normal or for linked list mode.
*/
Pcie_Ip_StatusType Pcie_Ip_DmaCheckWriteStatus(uint8 instance,
                                               uint8 channel,
                                               uint32 *transfersLeft)
{
    uint32 llp;
    Pcie_Ip_StatusType status;
    const Pcie_Ip_DmaLlStateType *state;
    uint32 base = PCIE_IP_BASE(instance);
    uint32 msgLeftLocal = 0U;

    state = &(pcieLlWriteState[instance][channel]);
    status = Pcie_Ip_DmaCheckWriteChannelStatusInternal(instance, channel);
    /* check if the channel is configured in linked list mode */
    if (NULL_PTR == state->list)
    {   /* normal operation */
        msgLeftLocal = (status == PCIE_IP_BUSY)?1U:0U;
    }
    else
    {
        /* linked list operation */
        if (PCIE_IP_BUSY == status)
        {
            /* DMA channel is running, compute remaining elements */
            llp = Serdes_Pcie_Ip_DmaWriteGetLlp(base, channel);
            llp = (llp - (uint32)(state->list)) / sizeof(Pcie_DmaLlElementType);
            if (llp < state->swLlp)
            {
                msgLeftLocal = state->swLlp - llp;
            }
            else
            {
                /* sw is one cycle ahead of DMA */
                msgLeftLocal = (state->size - 1U) + state->swLlp - llp;
            }
        }
        /* CDD_PCIE_00017: If the device reported an error during the DMA write, the function Pcie_DmaCheckWriteStatus() shall return PCIE_ERROR. */
        /* CDD_PCIE_00018: If the DMA write is completed either succesfully or with an error, the function Pcie_DmaCheckWriteStatus() shall also clear the DMA status bits, in addition to reporting the status. */
        else if (PCIE_IP_ERROR == status)
        {
            Serdes_Pcie_Ip_DmaWriteRingDoorbell(base, channel);
        }
        else
        {
            /* status == PCIE_IP_SUCCESS - nothing to do but return status */
        }
    }
    /* clear any pending flags */
    (void)Pcie_Ip_DmaCheckWriteFlagsInternal(instance, channel);
    if (transfersLeft != NULL_PTR)
    {
        *transfersLeft = msgLeftLocal;
    }
    return status;
}

/**
* @brief        Prepare read DMA channel for linked list operation
* @details      This function initilizes the read channel and elements in the linked list which will be used for DMA linked list operation.
*/
Pcie_Ip_StatusType Pcie_Ip_DmaLlReadSetup(uint8 instance,
                                          uint8 channel,
                                          Pcie_DmaLlElementType *llPtr,
                                          uint32 size)
{
    Pcie_Ip_DmaLlStateType *state;
    uint32 i;
    uint32 base = PCIE_IP_BASE(instance);

    state = &(pcieLlReadState[instance][channel]);
    /* Configure the data elements in the linked list */
    for (i = 0U; i < (size - 1U); i++)
    {
        llPtr[i].ctrl = 0U; /* LIE = 0, LLP = 0, CB = 0 */
    }
    /* Configure link element */
    llPtr[size - 1U].ctrl = (PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK_U32  | PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_MASK_U32  | PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_MASK_U32 );
    llPtr[size - 1U].srcLow = (uint32)&(llPtr[0U]);  /* Link back to first element  */
    llPtr[size - 1U].srcHigh = 0U;
    /* Enable DMA Read Engine */
    Serdes_Pcie_Ip_DmaReadEngineEnable(base);
    /* Configure channel for linked list operation */
    Serdes_Pcie_Ip_DmaReadLLEnable(base, channel, (uint32)&(llPtr[0U]));
    /* Initialize state data for this channel */
    state->list = &(llPtr[0U]);
    state->pcs = 1U;
    state->swLlp = 0U;
    state->size = size;
    return PCIE_IP_SUCCESS;
}

/**
* @brief        Prepare write DMA channel for linked list operation
* @details      This function initilizes the write channel and elements in the linked list which will be used for DMA linked list operation.
*/
Pcie_Ip_StatusType Pcie_Ip_DmaLlWriteSetup(uint8 instance,
                                           uint8 channel,
                                           Pcie_DmaLlElementType *llPtr,
                                           uint32 size)
{
    Pcie_Ip_DmaLlStateType *state;
    uint32 i;
    uint32 base = PCIE_IP_BASE(instance);

    state = &(pcieLlWriteState[instance][channel]);
    /* Configure the data elements in the linked list */
    for (i = 0U; i < (size - 1U); i++)
    {
        llPtr[i].ctrl = 0U; /* LIE = 0, LLP = 0, CB = 0 */
    }
    /* Configure link element */
    llPtr[size - 1U].ctrl = (PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK_U32 | PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_MASK_U32 | PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_MASK_U32);
    llPtr[size - 1U].srcLow = (uint32)&(llPtr[0U]);  /* Link back to first element  */
    llPtr[size - 1U].srcHigh = 0U;
    /* Enable DMA Write Engine */
    Serdes_Pcie_Ip_DmaWriteEngineEnable(base);
    /* Configure channel for linked list operation */
    Serdes_Pcie_Ip_DmaWriteLLEnable(base, channel, (uint32)&(llPtr[0U]));
    /* Initialize state data for this channel */
    state->list = &(llPtr[0U]);
    state->pcs = 1U;
    state->swLlp = 0U;
    state->size = size;
    return PCIE_IP_SUCCESS;
}

/**
* @brief        Initialize PCIe logic
* @details      This function configures PCIe module in EP mode.
* @note         Function should be called after Serdes_Init.
*/
void Pcie_Ip_Init(uint8 instance,
                  const Pcie_Ip_ConfigType *pcieConfig)
{
    uint32 base = PCIE_IP_BASE(instance);
    SerDes_SS_Type * ss_base = PCIE_IP_SERDES_SS_BASE_ADDR(instance);

    Pcie_Ip_InitEp(base, PCIE_IP_ENDPOINT, PCIE_IP_LINK_WIDTH_X1);
    /* Enable ltssm */
    serdes_pci_EnableLtssm(ss_base);
    /* Enable writing dbi registers */
    Serdes_Pcie_Ip_EnableDbiRw((PCIE_EP_Type *)base);
    /* Delay incoming configuration requests */
    Serdes_Pcie_Ip_EnableCrs(ss_base);

    /* Set the CLASS_REV of EP CFG header    */
    Serdes_Pcie_Ip_SetClass(base, pcieConfig->pcieClass);

    /* setup bars */
    Pcie_Ip_Init_Set_Bars(base, pcieConfig);
    /* setup iATU */
    Pcie_Ip_Init_Set_Iatu(base, pcieConfig);

    /* Ready for incoming configuration requests */
    Serdes_Pcie_Ip_DisableCrs(ss_base);

    /* Configure MSIs if required */
    if (pcieConfig->msiCount > 0U)
    {
        Serdes_Pcie_Ip_MsiSetIntNo(base, pcieConfig->msiCount);
    }

    /* Disable writing dbi registers */
    Serdes_Pcie_Ip_DisableDbiRw((PCIE_EP_Type *)base);
    /* Record configuration */
    Pcie_Ip_Config[instance] = pcieConfig;
}

/**
 * @brief        PCIe IRQ handler
 * @details      This function handles interrupts from the internal DMA.
 *
 * @implements   Pcie_Ip_DmaIRQHandler_Activity
 *
 */
void Pcie_Ip_DmaIRQHandler(uint8 instance)
{
    uint32 read_done_flags;
    uint32 read_error_flags;
    uint32 write_done_flags;
    uint32 write_error_flags;
    const Pcie_Ip_ConfigType *config = Pcie_Ip_Config[instance];
    uint32 base = PCIE_IP_BASE(instance);

    /* Check that the driver has been initialized */
    if (NULL_PTR == config)
    {
        /* Driver not initialized */
        Serdes_Pcie_Ip_DmaCleanInterrupts(base);
    }
    else
    {
        /* Check read done events */
        read_done_flags =   Serdes_Pcie_Ip_DmaGetReadDoneFlags(base);
        if (0U != read_done_flags)
        {
            Serdes_Pcie_Ip_DmaClearReadDoneFlags(base, read_done_flags);
            Pcie_Ip_CallReadDoneHandlers(instance, read_done_flags, PCIE_DMA_READ_CHANNELS_COUNT, config->dmaReadDoneHandler);
        }

        /* Check read error events */
        read_error_flags =  Serdes_Pcie_Ip_DmaGetReadErrorFlags(base);
        if (0U != read_error_flags)
        {
            Serdes_Pcie_Ip_DmaClearReadErrorFlags(base, read_error_flags);
            Pcie_Ip_CallErrorHandlers(instance, read_error_flags, PCIE_DMA_READ_CHANNELS_COUNT, config->dmaReadErrorHandler);
        }

        /* Check write done events */
        write_done_flags =  Serdes_Pcie_Ip_DmaGetWriteDoneFlags(base);
        if (0u != write_done_flags)
        {
            Serdes_Pcie_Ip_DmaClearWriteDoneFlags(base, write_done_flags);
            Pcie_Ip_CallWriteDoneHandlers(instance, write_done_flags, PCIE_DMA_WRITE_CHANNELS_COUNT, config->dmaWriteDoneHandler);
        }

        /* Check write error events */
        write_error_flags = Serdes_Pcie_Ip_DmaGetWriteErrorFlags(base);
        if (0u != write_error_flags)
        {
            Serdes_Pcie_Ip_DmaClearWriteErrorFlags(base, write_error_flags);
            Pcie_Ip_CallErrorHandlers(instance, write_error_flags, PCIE_DMA_WRITE_CHANNELS_COUNT, config->dmaWriteErrorHandler);
        }
    }
}


#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
