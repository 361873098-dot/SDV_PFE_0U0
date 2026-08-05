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

#ifndef PCIE_IP_HWACCESS_H
#define PCIE_IP_HWACCESS_H

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

#include "Pcie_Ip_DeviceReg.h"
#include "Pcie_Ip_Cfg.h"
#include "Pcie_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_IP_HWACCESS_VENDOR_ID                    43
#define PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     4
#define PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define PCIE_IP_HWACCESS_SW_MAJOR_VERSION             4
#define PCIE_IP_HWACCESS_SW_MINOR_VERSION             0
#define PCIE_IP_HWACCESS_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pcie types header file are of the same vendor */
#if (PCIE_IP_HWACCESS_VENDOR_ID != PCIE_TYPES_VENDOR_ID)
#error "Pcie_Ip_HwAccess.h and Pcie_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip_HwAccess.h and Pcie_Types.h are different"
#endif
/* Check if current file and Pcie types header file are of the same software version */
#if ((PCIE_IP_HWACCESS_SW_MAJOR_VERSION != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IP_HWACCESS_SW_MINOR_VERSION != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IP_HWACCESS_SW_PATCH_VERSION != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip_HwAccess.h and Pcie_Types.h are different"
#endif

/* Checks against Pcie_Ip_Cfg.h */
#if (PCIE_IP_HWACCESS_VENDOR_ID != PCIE_IP_CFG_VENDOR_ID)
     #error "Pcie_Ip_Cfg.h and Pcie_Ip_HwAccess.h have different vendor ids"
#endif
#if ((PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != PCIE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != PCIE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != PCIE_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Pcie_Ip_Cfg.h and Pcie_Ip_HwAccess.h are different"
#endif
#if ((PCIE_IP_HWACCESS_SW_MAJOR_VERSION != PCIE_IP_CFG_SW_MAJOR_VERSION) || \
     (PCIE_IP_HWACCESS_SW_MINOR_VERSION != PCIE_IP_CFG_SW_MINOR_VERSION) || \
     (PCIE_IP_HWACCESS_SW_PATCH_VERSION != PCIE_IP_CFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pcie_Ip_Cfg.h and Pcie_Ip_HwAccess.h are different"
#endif

/* Check if current file and device registers header file are of the same vendor */
#if (PCIE_IP_HWACCESS_VENDOR_ID != PCIE_IP_DEVICEREG_VENDOR_ID)
#error "Pcie_Ip_HwAccess.h and Pcie_Ip_DeviceReg.h have different vendor ids"
#endif
/* Check if current file and device registers header file are of the same Autosar version */
#if ((PCIE_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != PCIE_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != PCIE_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != PCIE_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip_HwAccess.h and Pcie_Ip_DeviceReg.h are different"
#endif
/* Check if current file and device registers header file are of the same software version */
#if ((PCIE_IP_HWACCESS_SW_MAJOR_VERSION != PCIE_IP_DEVICEREG_SW_MAJOR_VERSION) || \
     (PCIE_IP_HWACCESS_SW_MINOR_VERSION != PCIE_IP_DEVICEREG_SW_MINOR_VERSION) || \
     (PCIE_IP_HWACCESS_SW_PATCH_VERSION != PCIE_IP_DEVICEREG_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip_HwAccess.h and Pcie_Ip_DeviceReg.h are different"
#endif


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/* PCIe registers */
#define PCIE_IP_SERDES_SS_BASE                          0x80000U

/* MSI */
#define PCIE_IP_MSI_CIDNC                               0x50U
#define PCIE_PE0_MSI_GEN_CTRL                           (PCIE_IP_SERDES_SS_BASE + 0x10ECU)

#define PCIE_IP_MSI_CIDNC_ENABLE_MASK_U32               0x00010000U
#define PCIE_IP_MSI_CIDNC_MULTI_MSG_EN_MASK_U32         0x00700000U
#define PCIE_IP_MSI_CIDNC_MULTI_MSG_EN_SHIFT            20U
#define PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP_MASK_U32        0x000E0000U
#define PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP_SHIFT           17U
#define PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP(x)          (((x) << PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP_SHIFT) & PCIE_IP_MSI_CIDNC_MULTI_MSG_CAP_MASK_U32)

#define PCIE_IP_IATU_BAR_NUM_SHIFT                       8U
#define PCIE_IP_IATU_BAR_NUM_MASK_U32                    0x00000700U
#define PCIE_IP_IATU_BAR_NUM(x)            (((x) << PCIE_IP_IATU_BAR_NUM_SHIFT) & PCIE_IP_IATU_BAR_NUM_MASK_U32)

/* MSI-X */
#define PCIE_IP_MSIX_CAP_ID_NEXT_CTRL_REG_U32                                0xB0U
#define PCIE_IP_MSIX_DOORBELL_OFF_U32                                        0x948U
#define PCIE_IP_MSIX_CAP_ID_NEXT_CTRL_REG_PCI_MSIX_ENABLE_MASK_U32           0x80000000U


/* IATU */
#define PCIE_IP_IATU_REGION_CTRL_1_OFF_INBOUND_0_U32           0x60100U
#define PCIE_IP_IATU_REGION_CTRL_2_OFF_INBOUND_0_U32           0x60104U
#define PCIE_IP_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_U32         0x60114U
#define PCIE_IP_IATU_UPPER_TARGET_ADDR_OFF_INBOUND_0_U32       0x60118U

#define PCIE_IP_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_U32          0x60000U
#define PCIE_IP_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_U32          0x60004U
#define PCIE_IP_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_U32          0x60008U
#define PCIE_IP_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_U32        0x6000CU
#define PCIE_IP_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_U32             0x60010U
#define PCIE_IP_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_U32        0x60014U
#define PCIE_IP_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_U32      0x60018U

#define PCIE_IP_IATU_REGION_OFFSET                                0x200U

#define PCIE_IP_IATU_REGION_EN_MASK_U32                        0x80000000U
#define PCIE_IP_IATU_MATCH_MODE_MASK_U32                       0x40000000U

/* DMA */
#define PCIE_IP_DMACHANNEL_OFFSET                               0x200U

#define PCIE_IP_DMA_WRITE_ENGINE_EN_OFF_U32                      0x7000CU
#define PCIE_IP_DMA_WRITE_DOORBELL_OFF_U32                       0x70010U
#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_U32                       0x70054U
#define PCIE_IP_DMA_READ_ENGINE_EN_OFF_U32                       0x7002CU
#define PCIE_IP_DMA_READ_DOORBELL_OFF_U32                        0x70030U
#define PCIE_IP_DMA_READ_INT_MASK_OFF_U32                        0x700A8U
#define PCIE_IP_DMA_WRITE_INT_STATUS_OFF_U32                     0x7004CU
#define PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_U32                      0x70058U
#define PCIE_IP_DMA_READ_INT_CLEAR_OFF_U32                       0x700ACU
#define PCIE_IP_DMA_READ_INT_STATUS_OFF_U32                      0x700A0U
#define PCIE_IP_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_U32             0x70090U
#define PCIE_IP_DMA_READ_LINKED_LIST_ERR_EN_OFF_U32              0x700C4U

#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_U32                  0x70200U
#define PCIE_IP_DMATRANSFER_SIZE_OFF_WRCH_0_U32                 0x70208U
#define PCIE_IP_DMASAR_LOW_OFF_WRCH_0_U32                       0x7020CU
#define PCIE_IP_DMASAR_HIGH_OFF_WRCH_0_U32                      0x70210U
#define PCIE_IP_DMADAR_LOW_OFF_WRCH_0_U32                       0x70214U
#define PCIE_IP_DMADAR_HIGH_OFF_WRCH_0_U32                      0x70218U
#define PCIE_IP_DMALLP_LOW_OFF_WRCH_0_U32                       0x7021CU
#define PCIE_IP_DMALLP_HIGH_OFF_WRCH_0_U32                      0x70220U

#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_U32                  0x70300U
#define PCIE_IP_DMATRANSFER_SIZE_OFF_RDCH_0_U32                 0x70308U
#define PCIE_IP_DMASAR_LOW_OFF_RDCH_0_U32                       0x7030CU
#define PCIE_IP_DMASAR_HIGH_OFF_RDCH_0_U32                      0x70310U
#define PCIE_IP_DMADAR_LOW_OFF_RDCH_0_U32                       0x70314U
#define PCIE_IP_DMADAR_HIGH_OFF_RDCH_0_U32                      0x70318U
#define PCIE_IP_DMALLP_LOW_OFF_RDCH_0_U32                       0x7031CU
#define PCIE_IP_DMALLP_HIGH_OFF_RDCH_0_U32                      0x70220U

#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_RUNNING_U32       1U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_HALTED_U32        2U

#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_RUNNING_U32       1U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_HALTED_U32        2U

#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_MASK_U32         0x00000200U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_MASK_U32         0x00000100U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_SHIFT            8U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_MASK_U32         0x00000008U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_MASK_U32          0x00000060U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CS_SHIFT             5U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_MASK_U32         0x00000004U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_MASK_U32         0x00000002U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK_U32          0x00000001U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_RDCH_0_CB_SHIFT             0U

#define PCIE_IP_DMA_READ_INT_STATUS_OFF_DONE_OFFSET              0U
#define PCIE_IP_DMA_READ_INT_STATUS_OFF_DONE_MASK_U32            0x0000000FU
#define PCIE_IP_DMA_READ_INT_STATUS_OFF_ABORT_OFFSET             16U
#define PCIE_IP_DMA_READ_INT_STATUS_OFF_ABORT_MASK_U32           0x000F0000U
#define PCIE_IP_DMA_READ_LINKED_LIST_ERR_EN_OFF_LLLAIE_OFFSET    16U

#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_MASK_U32         0x00000200U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_MASK_U32         0x00000100U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_SHIFT            8U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_MASK_U32         0x00000008U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_MASK_U32          0x00000060U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CS_SHIFT             5U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_MASK_U32         0x00000004U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_MASK_U32         0x00000002U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK_U32          0x00000001U
#define PCIE_IP_DMA_CH_CONTROL1_OFF_WRCH_0_CB_SHIFT             0U

#define PCIE_IP_DMA_WRITE_INT_STATUS_OFF_DONE_OFFSET             0U
#define PCIE_IP_DMA_WRITE_INT_STATUS_OFF_DONE_MASK_U32           0x0000000FU
#define PCIE_IP_DMA_WRITE_INT_STATUS_OFF_ABORT_OFFSET            16U
#define PCIE_IP_DMA_WRITE_INT_STATUS_OFF_ABORT_MASK_U32          0x000F0000U
#define PCIE_IP_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_LLLAIE_OFFSET   16U

#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_DONE_OFFSET               0U
#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_DONE_MASK_U32             0x0000000FU
#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_ABORT_OFFSET              16U
#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_ABORT_MASK_U32            0x000F0000U

#define PCIE_IP_DMA_READ_INT_MASK_OFF_DONE_OFFSET                0U
#define PCIE_IP_DMA_READ_INT_MASK_OFF_DONE_MASK_U32              0x0000000FU
#define PCIE_IP_DMA_READ_INT_MASK_OFF_ABORT_OFFSET               16U
#define PCIE_IP_DMA_READ_INT_MASK_OFF_ABORT_MASK_U32             0x000F0000U

#define PCIE_IP_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_CH0_U32  0x00010000U
#define PCIE_IP_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_CH0_U32   0x00000001U
#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_CH0_U32 0x00010000U
#define PCIE_IP_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_CH0_U32  0x00000001U

#define PCIE_IP_DMA_READ_INT_CLEAR_OFF_DONE_OFFSET               0U
#define PCIE_IP_DMA_READ_INT_CLEAR_OFF_DONE_MASK_U32             0x0000000FU
#define PCIE_IP_DMA_READ_INT_CLEAR_OFF_ABORT_OFFSET              16U
#define PCIE_IP_DMA_READ_INT_CLEAR_OFF_ABORT_MASK_U32            0x000F0000U
#define PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_DONE_OFFSET              0U
#define PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_DONE_MASK_U32            0x0000000FU
#define PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_ABORT_OFFSET             16U
#define PCIE_IP_DMA_WRITE_INT_CLEAR_OFF_ABORT_MASK_U32           0x000F0000U

/* RESET CONTROL Register */
#define PCIE_IP_CLASS_CODE_REVISION_ID            (0x8U)

/* BARs */
#define PCIE_IP_ENABLE_BAR_MASK_U32               (1U)
#define PCIE_IP_CS2_MASK                          (0x20000U)

#define PCIE_IP_BAR0                              0x10U


#define PCIE_IP_NUM_OF_LANES(x)                   (uint32)((0x1FU & (x)) << 8U)


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

typedef enum
{
    PCIE_IP_ENDPOINT                  = 0U, 
    PCIE_IP_ROOTCOMPLEX               = 4U,
}Pcie_Ip_ModeType;

typedef enum 
{
    PCIE_IP_LINK_WIDTH_X1 = 0x1U,     /* 1 lane PCIe  */
    PCIE_IP_LINK_WIDTH_X2 = 0x2U      /* 2 lanes PCIe */
} Pcie_Ip_LinkWidthType;

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"

/* Serdes PCIe functions*/
void Serdes_Pcie_Ip_SpeedChange(PCIE_EP_Type *base);
void Serdes_Pcie_Ip_SetType(uint32 base, Pcie_Ip_ModeType type);
void Serdes_Pcie_Ip_EnableDbiRw(PCIE_EP_Type *base);
void Serdes_Pcie_Ip_DisableDbiRw(PCIE_EP_Type *base);
void Serdes_Pcie_Ip_EnableCrs(SerDes_SS_Type *base);
void Serdes_Pcie_Ip_DisableCrs(SerDes_SS_Type *base);
void Serdes_Pcie_Ip_SetClass(uint32 base, uint32 class);
void Serdes_Pcie_Ip_IatuInboundSetBar(uint32 base, uint32 region_no, uint32 bar, uint32 addr, uint32 ctrl_1);
void Serdes_Pcie_Ip_IatuOutboundSet(uint32 base, const Pcie_OutRegDescriptorType *outRegDesc);
void Serdes_Pcie_Ip_DisablePhase_2_3_eq(PCIE_EP_Type *base);
void Serdes_Pcie_Ip_SetLinkWidth(PCIE_EP_Type *base, Pcie_Ip_LinkWidthType linkwidth);
void Serdes_Pcie_Ip_SetLinkCapable(PCIE_EP_Type *base, uint32 link_capable);
void Serdes_Pcie_Ip_ChangeMstrAceCache(PCIE_EP_Type *base, uint32 arcache, uint32 awcache);
void Serdes_Pcie_Ip_ChangeMstrAceDomain(PCIE_EP_Type *base, uint32 ardomain, uint32 awdomain);
void Serdes_Pcie_Ip_SetupBar(uint32 base, uint32 baroffset, uint32 size, uint32 init);
void Serdes_Pcie_Ip_Gen3RelatedEqPhase_2_3(PCIE_EP_Type * base);
void serdes_pci_EnableLtssm(SerDes_SS_Type *base);
void Serdes_Pcie_Ip_DmaReadEngineEnable(uint32 base);
void Serdes_Pcie_Ip_DmaReadLocalIntEnable(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaReadStartTransfer(uint32 base, uint8 channel, uint64 srcAddr, uint32 dstAddr, uint32 size);
boolean Serdes_Pcie_Ip_DmaReadCheckClearComplete(uint32 base, uint8 channel);
boolean Serdes_Pcie_Ip_DmaReadCheckClearError(uint32 base, uint8 channel);
boolean Serdes_Pcie_Ip_DmaReadCheckError(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaWriteEngineEnable(uint32 base);
void Serdes_Pcie_Ip_DmaWriteLocalIntEnable(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaWriteStartTransfer(uint32 base, uint8 channel, uint32 srcAddr, uint64 dstAddr, uint32 size);
boolean Serdes_Pcie_Ip_DmaWriteCheckClearComplete(uint32 base, uint8 channel);
boolean Serdes_Pcie_Ip_DmaWriteCheckClearError(uint32 base, uint8 channel);
boolean Serdes_Pcie_Ip_DmaWriteCheckError(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_MsiTriggerSet(uint32 base, uint32 intNo);
void Serdes_Pcie_Ip_MsiTriggerReset(uint32 base, uint32 intNo);
void Serdes_Pcie_Ip_MsxDoorbell(uint32 base, uint32 intNo);
void Serdes_Pcie_Ip_MsiSetIntNo(uint32 base, uint8 intNo);
uint32 Serdes_Pcie_Ip_MsiGetIntNo(uint32 base);
boolean Serdes_Pcie_Ip_MsixGetEnable(uint32 base);
void Serdes_Pcie_Ip_DmaReadLocalIntMask(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaReadLocalIntUnmask(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaWriteLocalIntMask(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaWriteLocalIntUnmask(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaReadLLEnable(uint32 base, uint8 channel, uint32 addr);
void Serdes_Pcie_Ip_DmaWriteLLEnable(uint32 base, uint8 channel, uint32 addr);
uint32 Serdes_Pcie_Ip_DmaReadGetLlp(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaWriteGetLlp(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaReadGetCcs(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaWriteGetCcs(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaReadGetCs(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaWriteGetCs(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaReadGetTransferSize(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaWriteGetTransferSize(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaReadRingDoorbell(uint32 base, uint8 channel);
void Serdes_Pcie_Ip_DmaWriteRingDoorbell(uint32 base, uint8 channel);
uint32 Serdes_Pcie_Ip_DmaGetReadDoneFlags(uint32 base);
uint32 Serdes_Pcie_Ip_DmaGetReadErrorFlags(uint32 base);
uint32 Serdes_Pcie_Ip_DmaGetWriteDoneFlags(uint32 base);
uint32 Serdes_Pcie_Ip_DmaGetWriteErrorFlags(uint32 base);
void Serdes_Pcie_Ip_DmaClearReadDoneFlags(uint32 base, uint32 flags);
void Serdes_Pcie_Ip_DmaClearReadErrorFlags(uint32 base, uint32 flags);
void Serdes_Pcie_Ip_DmaClearWriteDoneFlags(uint32 base, uint32 flags);
void Serdes_Pcie_Ip_DmaClearWriteErrorFlags(uint32 base, uint32 flags);
void Serdes_Pcie_Ip_DmaCleanInterrupts(uint32 base);

#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif   /* PCIE_IP_HWACCESS_H */
