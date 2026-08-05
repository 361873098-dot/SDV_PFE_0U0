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

/**
*   @file
*
*   @addtogroup PCIE_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Pcie_Ip_HwAccess.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PCIE_IP_HWACCESS_VENDOR_ID_C                      43
#define PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C       4
#define PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define PCIE_IP_HWACCESS_SW_MAJOR_VERSION_C               4
#define PCIE_IP_HWACCESS_SW_MINOR_VERSION_C               0
#define PCIE_IP_HWACCESS_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pcie_Ip_HwAccess header file are of the same vendor */
#if (PCIE_IP_HWACCESS_VENDOR_ID != PCIE_IP_HWACCESS_VENDOR_ID_C)
#error "Pcie_Ip_HwAccess.c and Pcie_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip_HwAccess header file are of the same Autosar version */
#if ((PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Pcie_Ip_HwAccess.c and Pcie_Ip_HwAccess.h are different"
#endif
/* Check if current file and Pcie_Ip_HwAccess header file are of the same software version */
#if ((PCIE_IP_HWACCESS_SW_MAJOR_VERSION != PCIE_IP_HWACCESS_SW_MAJOR_VERSION_C) || \
     (PCIE_IP_HWACCESS_SW_MINOR_VERSION != PCIE_IP_HWACCESS_SW_MINOR_VERSION_C) || \
     (PCIE_IP_HWACCESS_SW_PATCH_VERSION != PCIE_IP_HWACCESS_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Pcie_Ip_HwAccess.c and Pcie_Ip_HwAccess.h are different"
#endif

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#define PCIE_IP_HAL_WRITE32(val, addr)  (*(volatile uint32 *)(addr) = (val))
#define PCIE_IP_HAL_READ32(addr)        (*(volatile uint32 *)(addr))

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"

/* Enable ltssm */
void serdes_pci_EnableLtssm(SerDes_SS_Type *base)
{
    base->PE0_GEN_CTRL_3 |= SerDes_SS_PE0_GEN_CTRL_3_LTSSM_EN_MASK;
}

/* Delay incoming configuration requests, to allow initialization to complete,
 * by enabling Configuration Request Retry Status (CRS).
 */
void Serdes_Pcie_Ip_EnableCrs(SerDes_SS_Type *base)
{
    base->PE0_GEN_CTRL_3 |= SerDes_SS_PE0_GEN_CTRL_3_CRS_EN_MASK;
}

/* Disable Configuration Request Retry Status (CRS).
 */
void Serdes_Pcie_Ip_DisableCrs(SerDes_SS_Type *base)
{
    base->PE0_GEN_CTRL_3 &= ~SerDes_SS_PE0_GEN_CTRL_3_CRS_EN_MASK;
}

/* Set PCIe class/subclass - to do: PCIE_CLASS_CODE_ID is read only in header file */
void Serdes_Pcie_Ip_SetClass(uint32 base,
                           uint32 class)
{
    PCIE_IP_HAL_WRITE32(class, (uint32)base + PCIE_IP_CLASS_CODE_REVISION_ID);
}

/* PCIE speed change */
void Serdes_Pcie_Ip_SpeedChange(PCIE_EP_Type *base)
{
    base->GEN2_CTRL_OFF |= PCIE_EP_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK;
}

/* Set PCIe type */
void Serdes_Pcie_Ip_SetType(uint32 base,
                          Pcie_Ip_ModeType type)
{
    SerDes_SS_Type * SerDes_SS_Ptr = (SerDes_SS_Type *)((uint32)base + PCIE_IP_SERDES_SS_BASE);

    SerDes_SS_Ptr->PE0_GEN_CTRL_1 &= ~(uint32)SerDes_SS_PE0_GEN_CTRL_1_DEVICE_TYPE_MASK;
    SerDes_SS_Ptr->PE0_GEN_CTRL_1 |= (uint32)type;
}

/* Pcie enable DBI read-write */
void Serdes_Pcie_Ip_EnableDbiRw(PCIE_EP_Type *base)
{
    base->MISC_CONTROL_1_OFF |= PCIE_EP_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_MASK;
}

/* Pcie disable DBI read-write */
void Serdes_Pcie_Ip_DisableDbiRw(PCIE_EP_Type *base)
{
    base->MISC_CONTROL_1_OFF &= ~(uint32)(PCIE_EP_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_MASK);
}

/* Disable phase 2,3 equalization */
void Serdes_Pcie_Ip_DisablePhase_2_3_eq(PCIE_EP_Type *base)
{
    base->GEN3_EQ_CONTROL_OFF &= ~(uint32)(PCIE_EP_GEN3_EQ_CONTROL_OFF_GEN3_EQ_PSET_REQ_VEC_MASK | PCIE_EP_GEN3_EQ_CONTROL_OFF_GEN3_EQ_FB_MODE_MASK);
    base->GEN3_EQ_CONTROL_OFF |= PCIE_EP_GEN3_EQ_CONTROL_OFF_GEN3_EQ_FB_MODE(0x1U) | PCIE_EP_GEN3_EQ_CONTROL_OFF_GEN3_EQ_PSET_REQ_VEC(0x84U);
}

/* Set link width */
void Serdes_Pcie_Ip_SetLinkWidth(PCIE_EP_Type *base,
                                Pcie_Ip_LinkWidthType linkwidth)
{
    base->GEN2_CTRL_OFF &= ~(uint32)(PCIE_EP_GEN2_CTRL_OFF_NUM_OF_LANES_MASK);
    base->GEN2_CTRL_OFF |= PCIE_IP_NUM_OF_LANES((uint32)linkwidth);
}

/* Set number of connected lanes */
void Serdes_Pcie_Ip_SetLinkCapable(PCIE_EP_Type *base,
                                  uint32 link_capable)
{
    base->PORT_LINK_CTRL_OFF &= ~(uint32)(PCIE_EP_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MASK);
    base->PORT_LINK_CTRL_OFF |= PCIE_EP_PORT_LINK_CTRL_OFF_LINK_CAPABLE(link_capable);
}

/* Configure master read/write cache settings */
void Serdes_Pcie_Ip_ChangeMstrAceCache(PCIE_EP_Type *base,
                                       uint32 arcache,
                                       uint32 awcache)
{
    base->COHERENCY_CONTROL_3_OFF |= (PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_MASK | PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_MASK);

    base->COHERENCY_CONTROL_3_OFF &= ~((PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_MASK | PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_MASK));
    base->COHERENCY_CONTROL_3_OFF |= (PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE(arcache) | PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE(awcache));
}

/* Configure master read/write domain settings */
void Serdes_Pcie_Ip_ChangeMstrAceDomain(PCIE_EP_Type *base,
                                        uint32 ardomain,
                                        uint32 awdomain)
{
    base->COHERENCY_CONTROL_3_OFF |= (PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARDOMAIN_MODE_MASK | PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWDOMAIN_MODE_MASK);

    base->COHERENCY_CONTROL_3_OFF &= ~((uint32)(PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARDOMAIN_VALUE_MASK | PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWDOMAIN_VALUE_MASK));
    base->COHERENCY_CONTROL_3_OFF |= (PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARDOMAIN_VALUE(ardomain) | PCIE_EP_COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWDOMAIN_VALUE(awdomain));
}

/* Configure bars. size must be a power of 2. size = 0 means bar is disabled */
void Serdes_Pcie_Ip_SetupBar (uint32 base,
                            uint32 baroffset,
                            uint32 size,
                            uint32 init)
{
    if (0U == size)
    {   /* disable bar */
        PCIE_IP_HAL_WRITE32(0U , (uint32)base + baroffset + PCIE_IP_CS2_MASK);
        PCIE_IP_HAL_WRITE32(0U , (uint32)base + baroffset);
    }
    else
    {
        PCIE_IP_HAL_WRITE32((uint32)PCIE_IP_ENABLE_BAR_MASK_U32 , (uint32)base + baroffset + PCIE_IP_CS2_MASK);
        PCIE_IP_HAL_WRITE32((uint32)(size - 1U), (uint32)base + baroffset + PCIE_IP_CS2_MASK);
        PCIE_IP_HAL_WRITE32((uint32)init, (uint32)base + baroffset);
    }
}

/* Configure outbound IATU region */
void Serdes_Pcie_Ip_IatuOutboundSet(uint32 base,
                                   const Pcie_OutRegDescriptorType *outRegDesc)
{
    uint32 region_no =      outRegDesc->regNo;
    uint64 s_addr =        outRegDesc->srcAddr;
    uint32 s_addr_lim =     outRegDesc->srcAddrLim;
    uint64 d_addr =        outRegDesc->dstAddr;
    uint32 ctrl_1 = (uint32)outRegDesc->type;

    PCIE_IP_HAL_WRITE32(0U, (uint32)base + PCIE_IP_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32((uint32)s_addr, (uint32)base + PCIE_IP_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32((uint32)(s_addr >> 32U),  (uint32)base + PCIE_IP_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32(s_addr_lim - 1U, (uint32)base + PCIE_IP_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32((uint32)d_addr, (uint32)base + PCIE_IP_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32((uint32)(d_addr >> 32U),  (uint32)base + PCIE_IP_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32(ctrl_1, (uint32)base + PCIE_IP_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));

    PCIE_IP_HAL_WRITE32(PCIE_IP_IATU_REGION_EN_MASK_U32, (uint32)base + PCIE_IP_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
}

/* Configure inbound IATU region */
void Serdes_Pcie_Ip_IatuInboundSetBar(uint32 base,
                                      uint32 region_no,
                                      uint32 bar,
                                      uint32 addr,
                                      uint32 ctrl_1)
{
    uint32 tmp;

    tmp =  PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_IATU_REGION_CTRL_2_OFF_INBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32(((tmp) & ~((uint32)PCIE_IP_IATU_REGION_EN_MASK_U32)),
                      (uint32)base + PCIE_IP_IATU_REGION_CTRL_2_OFF_INBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));

    PCIE_IP_HAL_WRITE32(addr, (uint32)base + PCIE_IP_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_U32   + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32(0x0U,  (uint32)base + PCIE_IP_IATU_UPPER_TARGET_ADDR_OFF_INBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
    PCIE_IP_HAL_WRITE32(ctrl_1, (uint32)base + PCIE_IP_IATU_REGION_CTRL_1_OFF_INBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));

    tmp = tmp & ~PCIE_IP_IATU_BAR_NUM_MASK_U32;
    tmp = tmp | (PCIE_IP_IATU_REGION_EN_MASK_U32 | PCIE_IP_IATU_MATCH_MODE_MASK_U32 | PCIE_IP_IATU_BAR_NUM(bar));
    PCIE_IP_HAL_WRITE32(tmp, (uint32)base + PCIE_IP_IATU_REGION_CTRL_2_OFF_INBOUND_0_U32  + (PCIE_IP_IATU_REGION_OFFSET * region_no));
}

/* Equalization Phase 2 And Phase 3 Disable */
void Serdes_Pcie_Ip_Gen3RelatedEqPhase_2_3(PCIE_EP_Type * base)
{
    base->GEN3_RELATED_OFF |= PCIE_EP_GEN3_RELATED_OFF_EQ_PHASE_2_3_MASK;
}

/* Enable DMA read engine */
void Serdes_Pcie_Ip_DmaReadEngineEnable(uint32 base)
{
    PCIE_IP_HAL_WRITE32(0x1U,  (uint32)base + PCIE_IP_DMA_READ_ENGINE_EN_OFF_U32);
}

/* Enable DMA local interrupt */
void Serdes_Pcie_Ip_DmaReadLocalIntEnable(uint32 base,
                                           uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32);

    PCIE_IP_HAL_WRITE32(tmp | PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_MASK_U32 , (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32);
}

/* Mask DMA local read interrupt */
void Serdes_Pcie_Ip_DmaReadLocalIntMask(uint32 base,
                                         uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_MASK_OFF_U32);
    uint32 mask =  (PCIE_IP_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_CH0_U32 | PCIE_IP_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_CH0_U32) << channel;

    PCIE_IP_HAL_WRITE32(tmp | mask, (uint32)base + PCIE_IP_DMA_READ_INT_MASK_OFF_U32);
}

/* Unmask DMA local read interrupt */
void Serdes_Pcie_Ip_DmaReadLocalIntUnmask(uint32 base,
                                          uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_MASK_OFF_U32);
    uint32 mask =  (PCIE_IP_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_CH0_U32 | PCIE_IP_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_CH0_U32) << channel;

    PCIE_IP_HAL_WRITE32(tmp & (~mask), (uint32)base + PCIE_IP_DMA_READ_INT_MASK_OFF_U32);
}

/* Starts a DMA read */
void Serdes_Pcie_Ip_DmaReadStartTransfer(uint32 base,
                                         uint8 channel,
                                         uint64 srcAddr,
                                         uint32 dstAddr,
                                         uint32 size)
{
    /* DMA Transfer Size = size */
    PCIE_IP_HAL_WRITE32((uint32)size,  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMATRANSFER_SIZE_OFF_RDCH_0_U32);
    /* DMA SAR Low  = srcAddr low */
    PCIE_IP_HAL_WRITE32((uint32)(srcAddr & 0xFFFFFFFFU),  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMASAR_LOW_OFF_RDCH_0_U32);
    /* DMA SAR High  = srcAddr high */
    PCIE_IP_HAL_WRITE32((uint32)(srcAddr >> 32U),  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMASAR_HIGH_OFF_RDCH_0_U32);
    /* DMA DAR Low  = dstAddr  */
    PCIE_IP_HAL_WRITE32((uint32)dstAddr,  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMADAR_LOW_OFF_RDCH_0_U32);
    /* DMA DAR High  = 0x0 */
    PCIE_IP_HAL_WRITE32((uint32)0x0U,  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMADAR_HIGH_OFF_RDCH_0_U32);
    /* DMA Read Doorbell = channel */
    PCIE_IP_HAL_WRITE32((uint32)channel,  (uint32)base + PCIE_IP_DMA_READ_DOORBELL_OFF_U32);
}

/* Checks if DMA read is completed; also clears the flag */
boolean Serdes_Pcie_Ip_DmaReadCheckClearComplete(uint32 base,
                                                 uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_STATUS_OFF_U32);
    tmp &= ((uint32)1U << (PCIE_IP_DMA_READ_INT_STATUS_OFF_DONE_OFFSET + channel));
    /* clear flag */
    PCIE_IP_HAL_WRITE32(tmp,  (uint32)base + PCIE_IP_DMA_READ_INT_CLEAR_OFF_U32);
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Checks if DMA read ended in error; also clears the flag */
boolean Serdes_Pcie_Ip_DmaReadCheckClearError(uint32 base,
                                              uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_STATUS_OFF_U32);
    tmp &= ((uint32)1U << (PCIE_IP_DMA_READ_INT_STATUS_OFF_ABORT_OFFSET + channel));
    /* clear flag */
    PCIE_IP_HAL_WRITE32(tmp,  (uint32)base + PCIE_IP_DMA_READ_INT_CLEAR_OFF_U32);
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Checks the error flag for a DMA read channel */
boolean Serdes_Pcie_Ip_DmaReadCheckError(uint32 base,
                                         uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_STATUS_OFF_U32);
    tmp &= ((uint32)1U << (PCIE_IP_DMA_READ_INT_STATUS_OFF_ABORT_OFFSET + channel));
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Return the DMA read channel done flags for all channels */
uint32 Serdes_Pcie_Ip_DmaGetReadDoneFlags(uint32 base)
{
    uint32 tmp;
    uint32 tmp_en;

    tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_STATUS_OFF_U32);
    tmp &= PCIE_IP_DMA_READ_INT_STATUS_OFF_DONE_MASK_U32 ;
    tmp >>= PCIE_IP_DMA_READ_INT_STATUS_OFF_DONE_OFFSET ;
    /* Read interrupt enable bits to mask out not enabled interrupts */
    tmp_en = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_MASK_OFF_U32);
    tmp_en = (~tmp_en) & PCIE_IP_DMA_READ_INT_MASK_OFF_DONE_MASK_U32;      /* Negate mask to get 1 for enabled interrupts  */
    tmp_en >>= PCIE_IP_DMA_READ_INT_MASK_OFF_DONE_OFFSET;

    return tmp & tmp_en;
}

/* Return the DMA read channel abort flags for all channels */
uint32 Serdes_Pcie_Ip_DmaGetReadErrorFlags(uint32 base)
{
    uint32 tmp;
    uint32 tmp_en;

    tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_STATUS_OFF_U32);
    tmp &= PCIE_IP_DMA_READ_INT_STATUS_OFF_ABORT_MASK_U32 ;
    tmp >>= PCIE_IP_DMA_READ_INT_STATUS_OFF_ABORT_OFFSET ;
    /* Read interrupt enable bits to mask out not enabled interrupts */
    tmp_en = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_INT_MASK_OFF_U32);
    tmp_en = (~tmp_en) & PCIE_IP_DMA_READ_INT_MASK_OFF_ABORT_MASK_U32;      /* Negate mask to get 1 for enabled interrupts  */
    tmp_en >>= PCIE_IP_DMA_READ_INT_MASK_OFF_ABORT_OFFSET;

    return tmp & tmp_en;
}

/* Return the DMA write channel done flags for all channels */
uint32 Serdes_Pcie_Ip_DmaGetWriteDoneFlags(uint32 base)
{
    uint32 tmp;
    uint32 tmp_en;

    tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_STATUS_OFF_U32);
    tmp &= PCIE_IP_DMA_WRITE_INT_STATUS_OFF_DONE_MASK_U32;
    tmp >>= PCIE_IP_DMA_WRITE_INT_STATUS_OFF_DONE_OFFSET;
    /* Read interrupt enable bits to mask out not enabled interrupts */
    tmp_en = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32);
    tmp_en = (~tmp_en) & PCIE_IP_DMA_WRITE_INT_MASK_OFF_DONE_MASK_U32;      /* Negate mask to get 1 for enabled interrupts  */
    tmp_en >>= PCIE_IP_DMA_WRITE_INT_MASK_OFF_DONE_OFFSET;

    return tmp & tmp_en;
}

/* Return the DMA write channel abort flags for all channels */
uint32 Serdes_Pcie_Ip_DmaGetWriteErrorFlags(uint32 base)
{
    uint32 tmp;
    uint32 tmp_en;

    tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_STATUS_OFF_U32);
    tmp &= PCIE_IP_DMA_WRITE_INT_STATUS_OFF_ABORT_MASK_U32;
    tmp >>= PCIE_IP_DMA_WRITE_INT_STATUS_OFF_ABORT_OFFSET;
    /* Read interrupt enable bits to mask out not enabled interrupts */
    tmp_en = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32);
    tmp_en = (~tmp_en) & PCIE_IP_DMA_WRITE_INT_MASK_OFF_ABORT_MASK_U32;      /* Negate mask to get 1 for enabled interrupts  */
    tmp_en >>= PCIE_IP_DMA_WRITE_INT_MASK_OFF_ABORT_OFFSET;

    return tmp & tmp_en;
}

/* Clear DMA read channel done flags */
void Serdes_Pcie_Ip_DmaClearReadDoneFlags(uint32 base,
                                           uint32 flags)
{
    PCIE_IP_HAL_WRITE32(flags << PCIE_IP_DMA_READ_INT_CLEAR_OFF_DONE_OFFSET, (uint32)base + PCIE_IP_DMA_READ_INT_CLEAR_OFF_U32);
}

/* Clear DMA read channel error flags */
void Serdes_Pcie_Ip_DmaClearReadErrorFlags(uint32 base,
                                            uint32 flags)
{
    PCIE_IP_HAL_WRITE32(flags << PCIE_IP_DMA_READ_INT_CLEAR_OFF_ABORT_OFFSET, (uint32)base + PCIE_IP_DMA_READ_INT_CLEAR_OFF_U32);
}

/* Clear DMA write channel done flags */
void Serdes_Pcie_Ip_DmaClearWriteDoneFlags(uint32 base,
                                            uint32 flags)
{
    PCIE_IP_HAL_WRITE32(flags << PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_DONE_OFFSET, (uint32)base + PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_U32);
}

/* Clear DMA write channel error flags */
void Serdes_Pcie_Ip_DmaClearWriteErrorFlags(uint32 base,
                                             uint32 flags)
{
    PCIE_IP_HAL_WRITE32(flags << PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_ABORT_OFFSET, (uint32)base + PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_U32);
}

/* Cleans all interrupt flags and interrupt enable bits for a PCIe instance. */
void Serdes_Pcie_Ip_DmaCleanInterrupts(uint32 base)
{
    /* Clear all interrupt flags */
    PCIE_IP_HAL_WRITE32((PCIE_IP_DMA_READ_INT_CLEAR_OFF_DONE_MASK_U32 | PCIE_IP_DMA_READ_INT_CLEAR_OFF_ABORT_MASK_U32), (uint32)base + PCIE_IP_DMA_READ_INT_CLEAR_OFF_U32);
    PCIE_IP_HAL_WRITE32((PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_DONE_MASK_U32 | PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_ABORT_MASK_U32), (uint32)base + PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_U32);
}

/* Enable DMA write engine */
void Serdes_Pcie_Ip_DmaWriteEngineEnable(uint32 base)
{
    PCIE_IP_HAL_WRITE32(0x1U,  (uint32)base + PCIE_IP_DMA_WRITE_ENGINE_EN_OFF_U32);
}

/* Enable DMA local write interrupt */
void Serdes_Pcie_Ip_DmaWriteLocalIntEnable(uint32 base,
                                            uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32);

    PCIE_IP_HAL_WRITE32(tmp | PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_MASK_U32, (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32);
}

/* Mask DMA local write interrupt */
void Serdes_Pcie_Ip_DmaWriteLocalIntMask(uint32 base,
                                          uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32);
    uint32 mask =  (PCIE_IP_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_CH0_U32 | PCIE_IP_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_CH0_U32) << channel;

    PCIE_IP_HAL_WRITE32(tmp | mask, (uint32)base + PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32);
}

/* Unmask DMA local write interrupt */
void Serdes_Pcie_Ip_DmaWriteLocalIntUnmask(uint32 base,
                                            uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32);
    uint32 mask =  (PCIE_IP_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_CH0_U32 | PCIE_IP_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_CH0_U32) << channel;

    PCIE_IP_HAL_WRITE32(tmp & (~mask), (uint32)base + PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32);
}

/* Starts a DMA write */
void Serdes_Pcie_Ip_DmaWriteStartTransfer(uint32 base,
                                          uint8 channel,
                                          uint32 srcAddr,
                                          uint64 dstAddr,
                                          uint32 size)
{
    /* DMA Transfer Size = size */
    PCIE_IP_HAL_WRITE32((uint32)size,  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMATRANSFER_SIZE_OFF_WRCH_0_U32);
    /* DMA SAR Low  = srcAddr */
    PCIE_IP_HAL_WRITE32((uint32)srcAddr,  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMASAR_LOW_OFF_WRCH_0_U32);
    /* DMA SAR High  = 0x0 */
    PCIE_IP_HAL_WRITE32((uint32)0x0U,  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMASAR_HIGH_OFF_WRCH_0_U32);
    /* DMA DAR Low  = dstAddr low */
    PCIE_IP_HAL_WRITE32((uint32)(dstAddr & 0xFFFFFFFFU),  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMADAR_LOW_OFF_WRCH_0_U32);
    /* DMA DAR High  = dstAddr high */
    PCIE_IP_HAL_WRITE32((uint32)(dstAddr >> 32U),  (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMADAR_HIGH_OFF_WRCH_0_U32);
    /* DMA Write Doorbell = channel */
    PCIE_IP_HAL_WRITE32((uint32)channel,  (uint32)base + PCIE_IP_DMA_WRITE_DOORBELL_OFF_U32);
}

/* Checks if DMA write is completed; also clears the flag */
boolean Serdes_Pcie_Ip_DmaWriteCheckClearComplete(uint32 base,
                                                  uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_STATUS_OFF_U32);

    tmp &= ((uint32)1U << (PCIE_IP_DMA_WRITE_INT_STATUS_OFF_DONE_OFFSET + channel));
    /* clear flag */
    PCIE_IP_HAL_WRITE32(tmp,  (uint32)base + PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_U32);
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Checks if DMA write ended in error; also clears the flag */
boolean Serdes_Pcie_Ip_DmaWriteCheckClearError(uint32 base,
                                               uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_STATUS_OFF_U32);

    tmp &= ((uint32)1U << (PCIE_IP_DMA_WRITE_INT_STATUS_OFF_ABORT_OFFSET + channel));
    /* clear flag */
    PCIE_IP_HAL_WRITE32(tmp,  (uint32)base + PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_U32);
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Checks the error flag for a DMA write channel */
boolean Serdes_Pcie_Ip_DmaWriteCheckError(uint32 base,
                                          uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_INT_STATUS_OFF_U32);
    tmp &= ((uint32)1U << (PCIE_IP_DMA_WRITE_INT_STATUS_OFF_ABORT_OFFSET + channel));
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Sets MSI interrupt trigger */
void Serdes_Pcie_Ip_MsiTriggerSet(uint32 base,
                                 uint32 intNo)
{
    PCIE_IP_HAL_WRITE32(((uint32)1U << intNo), (uint32)base + PCIE_PE0_MSI_GEN_CTRL);
}

/* Releases MSI interrupt trigger */
void Serdes_Pcie_Ip_MsiTriggerReset(uint32 base,
                                   uint32 intNo)
{
    (void)intNo;
    PCIE_IP_HAL_WRITE32(0U, (uint32)base + PCIE_PE0_MSI_GEN_CTRL);
}

/* Initiates MSIx interrupt */
void Serdes_Pcie_Ip_MsxDoorbell(uint32 base,
                              uint32 intNo)
{
    (void)intNo;
    PCIE_IP_HAL_WRITE32(intNo, (uint32)base + PCIE_IP_MSIX_DOORBELL_OFF_U32);
}

/* Configure number of MSIs required by EP */
void Serdes_Pcie_Ip_MsiSetIntNo(uint32 base,
                                uint8 intNo)
{
    uint32 intVal;
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_MSI_CIDNC);

    if (intNo <= 1U)
    {
        intVal = 0U;
    }
    else if (intNo <= 2U)
    {
        intVal = 1U;
    }
    else if (intNo <= 4U)
    {
        intVal = 2U;
    }
    else if (intNo <= 8U)
    {
        intVal = 3U;
    }
    else if (intNo <= 16U)
    {
        intVal = 4U;
    }
    else
    {
        intVal = 5U;
    }
    tmp &= ~(uint32)(PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP_MASK_U32);
    tmp |= (uint32)(PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP(intVal));
    PCIE_IP_HAL_WRITE32(tmp, (uint32)base + PCIE_IP_MSI_CIDNC);
}

/* Checsk number of MSIs allowed by RC */
uint32 Serdes_Pcie_Ip_MsiGetIntNo(uint32 base)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_MSI_CIDNC);

    if (0U == (tmp & PCIE_IP_MSI_CIDNC_ENABLE_MASK_U32) )
    {
        /*  MSIs not enabled by RC, return 0 */
        tmp = (uint32)0U;
    }
    else
    {
        /*  MSIs enabled by RC, check MULTI_MSG_EN field */
        tmp &= (uint32)PCIE_IP_MSI_CIDNC_MULTI_MSG_EN_MASK_U32;
        tmp >>= (uint32)PCIE_IP_MSI_CIDNC_MULTI_MSG_EN_SHIFT;
        if (tmp < 5U)
        {
            tmp = ((uint32)1U << tmp);
        }
        else
        {
            tmp = (uint32)32U;
        }
    }
    return tmp;
}

/* Check if MSIx is enabled by RC */
boolean Serdes_Pcie_Ip_MsixGetEnable(uint32 base)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_MSIX_CAP_ID_NEXT_CTRL_REG_U32);

    tmp &= PCIE_IP_MSIX_CAP_ID_NEXT_CTRL_REG_PCI_MSIX_ENABLE_MASK_U32;
    return (tmp != 0U) ? TRUE : FALSE;
}

/* Enables DMA read channel in linked list mode */
void Serdes_Pcie_Ip_DmaReadLLEnable(uint32 base,
                                    uint8 channel,
                                    uint32 addr)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32);

    /* Set LLE = 1, CCS = 1 */
    PCIE_IP_HAL_WRITE32(tmp | (PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_MASK_U32  | PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_MASK_U32 ),
                (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32);
    PCIE_IP_HAL_WRITE32(addr, (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMALLP_LOW_OFF_RDCH_0_U32);
    PCIE_IP_HAL_WRITE32(0U, (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMALLP_HIGH_OFF_RDCH_0_U32);
    /* Activate abort interrupt for this channel */
    tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_READ_LINKED_LIST_ERR_EN_OFF_U32);
    tmp |= ((uint32)1U << (PCIE_IP_DMA_READ_LINKED_LIST_ERR_EN_OFF_LLLAIE_OFFSET  + channel));
    PCIE_IP_HAL_WRITE32(tmp, (uint32)base + PCIE_IP_DMA_READ_LINKED_LIST_ERR_EN_OFF_U32);
}

/* Enables DMA write channel in linked list mode */
void Serdes_Pcie_Ip_DmaWriteLLEnable(uint32 base,
                                     uint8 channel,
                                     uint32 addr)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32);

    /* Set LLE = 1, CCS = 1 */
    PCIE_IP_HAL_WRITE32(tmp | (PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_MASK_U32  | PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_MASK_U32 ),
                (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32);
    PCIE_IP_HAL_WRITE32(addr, (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMALLP_LOW_OFF_WRCH_0_U32);
    PCIE_IP_HAL_WRITE32(0U, (uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMALLP_HIGH_OFF_WRCH_0_U32);
    /* Activate abort interrupt for this channel */
    tmp = PCIE_IP_HAL_READ32((uint32)base + PCIE_IP_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_U32);
    tmp |= ((uint32)1U << (PCIE_IP_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_LLLAIE_OFFSET + channel));
    PCIE_IP_HAL_WRITE32(tmp, (uint32)base + PCIE_IP_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_U32);
}

/* Reads current value of linked list pointer of read DMA channel */
uint32 Serdes_Pcie_Ip_DmaReadGetLlp(uint32 base,
                                    uint8 channel)
{
    return PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMALLP_LOW_OFF_RDCH_0_U32);
}

/* Reads current value of linked list pointer of write DMA channel */
uint32 Serdes_Pcie_Ip_DmaWriteGetLlp(uint32 base,
                                     uint8 channel)
{
    return PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMALLP_LOW_OFF_WRCH_0_U32);
}

/* Reads current value of ccs bit of read DMA channel */
uint32 Serdes_Pcie_Ip_DmaReadGetCcs(uint32 base,
                                    uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32);

    tmp = (tmp & PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_MASK_U32 ) >> PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_SHIFT ;
    return tmp;
}

/* Reads current value of ccs bit of write DMA channel */
uint32 Serdes_Pcie_Ip_DmaWriteGetCcs(uint32 base,
                                     uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32);

    tmp = (tmp & PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_MASK_U32 ) >> PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_SHIFT ;
    return tmp;
}

/* Reads channel status of read DMA channel */
uint32 Serdes_Pcie_Ip_DmaReadGetCs(uint32 base,
                                   uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32);

    tmp = (tmp & PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_MASK_U32 ) >> PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_SHIFT ;
    return tmp;
}

/* Reads channel status of write DMA channel */
uint32 Serdes_Pcie_Ip_DmaWriteGetCs(uint32 base,
                                    uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32);

    tmp = (tmp & PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_MASK_U32) >> PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_SHIFT;
    return tmp;
}

/* Reads transfer size of read DMA channel */
uint32 Serdes_Pcie_Ip_DmaReadGetTransferSize(uint32 base,
                                              uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMATRANSFER_SIZE_OFF_RDCH_0_U32);

    return tmp;
}

/* Reads transfer size of write DMA channel */
uint32 Serdes_Pcie_Ip_DmaWriteGetTransferSize(uint32 base,
                                               uint8 channel)
{
    uint32 tmp = PCIE_IP_HAL_READ32((uint32)base + ((uint32)channel * PCIE_IP_DMACHANNEL_OFFSET) + PCIE_IP_DMATRANSFER_SIZE_OFF_WRCH_0_U32);

    return tmp;
}

/* Ring DMA doorbell to restart transfer in ll mode for read channels */
void Serdes_Pcie_Ip_DmaReadRingDoorbell(uint32 base,
                                        uint8 channel)
{
    /* DMA Read Doorbell = channel */
    PCIE_IP_HAL_WRITE32((uint32)channel,  (uint32)base + PCIE_IP_DMA_READ_DOORBELL_OFF_U32);
}

/* Ring DMA doorbell to restart transfer in ll mode for write channels */
void Serdes_Pcie_Ip_DmaWriteRingDoorbell(uint32 base,
                                         uint8 channel)
{
    /* DMA Write Doorbell = channel */
    PCIE_IP_HAL_WRITE32((uint32)channel,  (uint32)base + PCIE_IP_DMA_WRITE_DOORBELL_OFF_U32);
}


#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
