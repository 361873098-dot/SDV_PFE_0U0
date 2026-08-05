/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,FTM
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

/* Prevention from multiple including the same header */
#ifndef DMA_IP_HWV3_ACCESSINLINE_H_
#define DMA_IP_HWV3_ACCESSINLINE_H_

/**
*   @file    Dma_Ip_Hwv3_AccessInline.h
*
*   @version 4.0.2
*
*   @brief   AUTOSAR Mcl - Dma Ip driver source file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip.h"
#include "Dma_Ip_Devassert.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID                       43
#define DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION        4
#define DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION                4
#define DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION                0
#define DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal header file are of the same Autosar version */
#if ((DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Hwv3_AccessInline.h and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Dma_Ip.h file are of the same vendor */
#if (DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID != DMA_IP_VENDOR_ID)
    #error "DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip.h file are of the same Autosar version */
#if ((DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION != DMA_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip.h file are of the same Software version */
#if ((DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION != DMA_IP_SW_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION != DMA_IP_SW_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION != DMA_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip_Devassert.h file are of the same vendor */
#if (DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID != DMA_IP_DEVASSERT_VENDOR_ID)
    #error "DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip_Devassert.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Devassert.h file are of the same Autosar version */
#if ((DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION != DMA_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION != DMA_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION != DMA_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip_Devassert.h are different"
#endif

/* Check if header file and Dma_Ip_Devassert.h file are of the same Software version */
#if ((DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION != DMA_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION != DMA_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION != DMA_IP_DEVASSERT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip_Devassert.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/*==================================================================================================
 * DMA INSTANCE CONFIGURATION FUNCTION - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaInst_SetConfig(Dma_Ip_Hwv3InstRegType * const ptInst, const Dma_Ip_LogicInstanceConfigType * const pxConfig)
{
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_EDBG_MASK))) | (DMA_IP_MP_CSR_EDBG(pxConfig->EnDebug ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_ERCA_MASK))) | (DMA_IP_MP_CSR_ERCA(pxConfig->EnRoundRobin ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_HAE_MASK)))  | (DMA_IP_MP_CSR_HAE(pxConfig->EnHaltAfterError ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_GCLC_MASK))) | (DMA_IP_MP_CSR_GCLC(pxConfig->EnChLinking ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_GMRC_MASK))) | (DMA_IP_MP_CSR_GMRC(pxConfig->EnGlMasterIdReplication ? TRUE : FALSE)));
    ptInst->reg_CSR = reg;
}

#if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaInst_SetCrcConfig(DMA_CRC_Type * const ptInst, const Dma_Ip_LogicInstanceConfigType * const pxConfig)
{
    uint32 reg = ptInst->GEC;

    /* Swap the DMA data bit-wise */
    reg = ((reg & (~(DMA_CRC_GEC_SWAP_BIT_MASK)))  | (DMA_CRC_GEC_SWAP_BIT(pxConfig->EnSwapBit ? TRUE : FALSE)));
    /* Swap the DMA data byte-wise */
    reg = ((reg & (~(DMA_CRC_GEC_SWAP_BYTE_MASK))) | (DMA_CRC_GEC_SWAP_BYTE(pxConfig->EnSwapByte ? TRUE : FALSE)));
    /* Enables/Disables CRC logic in all channels */
    reg = ((reg & (~(DMA_CRC_GEC_GBL_EN_MASK)))    | (DMA_CRC_GEC_GBL_EN(pxConfig->EnGlobal ? TRUE : FALSE)));
    ptInst->GEC = reg;
}
#endif /* #if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE) */

/*==================================================================================================
 * DMA INSTANCE CMD FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaInst_CmdCancelTransfer(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_CX register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_CX_MASK))) | (DMA_IP_MP_CSR_CX(TRUE)));
    ptInst->reg_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaInst_CmdCancelTransferWithError(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_ECX register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_ECX_MASK))) | (DMA_IP_MP_CSR_ECX(TRUE)));
    ptInst->reg_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaInst_CmdHalt(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_HALT register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_HALT_MASK))) | (DMA_IP_MP_CSR_HALT(TRUE)));
    ptInst->reg_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaInst_CmdResume(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_HALT register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_HALT_MASK))) | (DMA_IP_MP_CSR_HALT(FALSE)));
    ptInst->reg_CSR = reg;
}

/*==================================================================================================
 * DMA INSTANCE STATUS FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaInst_GetErrorStatus(const Dma_Ip_Hwv3InstRegType * const ptInst, uint32 * const pValue)
{
    /* Get ES register */
    *pValue = (ptInst->reg_ES & DMA_IP_MP_ES_MASK);
}
LOCAL_INLINE void hwv3AccInlineDmaInst_GetActiveIdStatus(const Dma_Ip_Hwv3InstRegType * const ptInst, uint8 * const pValue)
{
    /* Get CSR register */
    *pValue = (uint8)((ptInst->reg_CSR & DMA_IP_MP_CSR_ACTIVE_ID_MASK) >> DMA_IP_MP_CSR_ACTIVE_ID_SHIFT);
}
LOCAL_INLINE void hwv3AccInlineDmaInst_GetActiveStatus(const Dma_Ip_Hwv3InstRegType * const ptInst, boolean * const pBool)
{
    /* Get CSR register */
    *pBool = (((ptInst->reg_CSR & DMA_IP_MP_CSR_ACTIVE_MASK) >> DMA_IP_MP_CSR_ACTIVE_SHIFT) == 0U) ? FALSE : TRUE;
}

/*==================================================================================================
 * DMA CHANNEL CMD FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_CmdSetRequest(Dma_Ip_ChRegType * ptCh)
{
    /* Access DMA_IP_TCD_CH_CSR_ERQ register */
    uint32 reg = ptCh->reg_CH_CSR;
    reg = ((reg & (~(DMA_IP_TCD_CH_CSR_ERQ_MASK))) | (DMA_IP_TCD_CH_CSR_ERQ(TRUE)));
    ptCh->reg_CH_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_CmdClearRequest(Dma_Ip_ChRegType * ptCh)
{
    /* Access DMA_IP_TCD_CH_CSR_ERQ register */
    uint32 reg = ptCh->reg_CH_CSR;
    reg = ((reg & (~(DMA_IP_TCD_CH_CSR_ERQ_MASK))) | (DMA_IP_TCD_CH_CSR_ERQ(FALSE)));
    ptCh->reg_CH_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_CmdSwReqStart(Dma_Ip_TcdRegType * ptTcd)
{
    /* Access DMA_IP_TCD_CSR_START register */
    uint16 reg = ptTcd->reg_CSR;
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START(1U)));
    ptTcd->reg_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_CmdClearDone(Dma_Ip_ChRegType * ptCh)
{
    /* Access CH_CSR register */
    uint32 reg = ptCh->reg_CH_CSR;
    reg = (reg | DMA_IP_TCD_CH_CSR_DONE_MASK);
    ptCh->reg_CH_CSR = reg;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_CmdClearError(Dma_Ip_ChRegType * ptCh)
{
    /* Access CH_ES register */
    uint32 reg = ptCh->reg_CH_ES;
    reg = (reg | DMA_IP_TCD_CH_ES_ERR_MASK);
    ptCh->reg_CH_ES = reg;
}

/*==================================================================================================
 * DMA CHANNEL STATUS FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_GetErrorStatus(const Dma_Ip_ChRegType * ptCh, uint32 * const pValue)
{
    /* Get CH_ES register */
    *pValue = (ptCh->reg_CH_ES & DMA_IP_TCD_CH_ES_MASK);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_GetActiveStatus(const Dma_Ip_ChRegType * ptCh, boolean * const pBool)
{
    /* Get CH_CSR register */
    *pBool = (((ptCh->reg_CH_CSR & DMA_IP_TCD_CH_CSR_ACTIVE_MASK) >> DMA_IP_TCD_CH_CSR_ACTIVE_SHIFT) == 0U) ? FALSE : TRUE;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_GetDoneStatus(const Dma_Ip_ChRegType * ptCh, boolean * const pBool)
{
    /* Get CH_CSR register */
    *pBool = (((ptCh->reg_CH_CSR & DMA_IP_TCD_CH_CSR_DONE_MASK) >> DMA_IP_TCD_CH_CSR_DONE_SHIFT) == 0U) ? FALSE : TRUE;
}

/*==================================================================================================
 * DMA CHANNEL GLOBAL FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_EnMasterIdReplication(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_SBR_EMI register */
    uint32 reg = ptCh->reg_CH_SBR;
    ptCh->reg_CH_SBR = ((reg & (~(DMA_IP_TCD_CH_SBR_EMI_MASK))) | (DMA_IP_TCD_CH_SBR_EMI(Value)));
}
#endif
#if (STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_EnBufferedWrites(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_CSR_EBW register */
    uint32 reg = ptCh->reg_CH_CSR;
    ptCh->reg_CH_CSR = ((reg & (~(DMA_IP_TCD_CH_CSR_EBW_MASK))) | (DMA_IP_TCD_CH_CSR_EBW(Value)));
}
#endif

#if (STD_ON == DMA_IP_DMAMUX_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetRequest_SourceMux(volatile Dma_Ip_MuxRegType * pMuxChCfg, const uint32 Value)
{
    /* Access DMAMUX_CHCFG_SOURCE register */
    Dma_Ip_MuxRegType reg = *pMuxChCfg;
    *pMuxChCfg = ((uint8)(reg & (~(DMAMUX_CHCFG_SOURCE_MASK))) | (DMAMUX_CHCFG_SOURCE(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetRequest_EnTriggerMux(volatile Dma_Ip_MuxRegType * pMuxChCfg, uint32 Value)
{
    /* Access DMAMUX_CHCFG_TRIG register */
    Dma_Ip_MuxRegType reg = *pMuxChCfg;
    *pMuxChCfg = ((uint8)(reg & (~(DMAMUX_CHCFG_TRIG_MASK))) | (DMAMUX_CHCFG_TRIG(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetRequest_EnHwRequestMux(volatile Dma_Ip_MuxRegType * pMuxChCfg, const uint32 Value)
{
    /* Access DMAMUX_CHCFG_ENBL register */
    Dma_Ip_MuxRegType reg = *pMuxChCfg;
    *pMuxChCfg = ((uint8)(reg & (~(DMAMUX_CHCFG_ENBL_MASK))) | (DMAMUX_CHCFG_ENBL(Value)));
}
#endif /* (STD_ON == DMA_IP_DMAMUX_IS_AVAILABLE) */

LOCAL_INLINE void hwv3AccInlineDmaCh_SetRequest_EnHwRequest(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_CSR_ERQ register */
    uint32 reg = ptCh->reg_CH_CSR;
    ptCh->reg_CH_CSR = ((reg & (~(DMA_IP_TCD_CH_CSR_ERQ_MASK))) | (DMA_IP_TCD_CH_CSR_ERQ(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetInterrupt_EnError(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_CSR_EEI register */
    uint32 reg = ptCh->reg_CH_CSR;
    ptCh->reg_CH_CSR = ((reg & (~(DMA_IP_TCD_CH_CSR_EEI_MASK))) | (DMA_IP_TCD_CH_CSR_EEI(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetPriority_Group(volatile uint32 * const pGrpri, uint32 Value)
{
    /* Access DMA_IP_MP_CH_GRPRI_GRPRI register */
    uint32 reg = *pGrpri;
    *pGrpri = ((reg & (~(DMA_IP_MP_CH_GRPRI_GRPRI_MASK))) | (DMA_IP_MP_CH_GRPRI_GRPRI(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetPriority_Level(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_PRI_APL register */
    uint32 reg = ptCh->reg_CH_PRI;
    ptCh->reg_CH_PRI = ((reg & (~(DMA_IP_TCD_CH_PRI_APL_MASK))) | (DMA_IP_TCD_CH_PRI_APL(Value)));
}
#if (STD_ON == DMA_IP_PREEMPTION_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetPriority_EnPreemption(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_PRI_ECP register */
    uint32 reg = ptCh->reg_CH_PRI;
    ptCh->reg_CH_PRI = ((reg & (~(DMA_IP_TCD_CH_PRI_ECP_MASK))) | (DMA_IP_TCD_CH_PRI_ECP(Value)));
}
#endif
#if (STD_ON == DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetPriority_DisPreempt(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_PRI_DPA register */
    uint32 reg = ptCh->reg_CH_PRI;
    ptCh->reg_CH_PRI = ((reg & (~(DMA_IP_TCD_CH_PRI_DPA_MASK))) | (DMA_IP_TCD_CH_PRI_DPA(Value)));
}
#endif

/*==================================================================================================
 * DMA CHANNEL TRANSFER FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_SetSource_Address(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SADDR_SADDR register */
    ptTcd->reg_SADDR = DMA_IP_TCD_SADDR_SADDR(Value);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetSource_SignedOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SOFF_SOFF register */
    uint32 reg = ptTcd->reg_SOFF;
    ptTcd->reg_SOFF = ((uint16)(reg & (~(DMA_IP_TCD_SOFF_SOFF_MASK))) | (DMA_IP_TCD_SOFF_SOFF(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetSource_SignedLastAddrAdj(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SLAST_SDA_SLAST_SDA register */
    ptTcd->reg_SLAST_SDA = DMA_IP_TCD_SLAST_SDA_SLAST_SDA(Value);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetSource_TransferSize(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_SSIZE register */
    uint32 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SSIZE_MASK))) | (DMA_IP_TCD_ATTR_SSIZE(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetSource_Modulo(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_SMOD register */
    uint32 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SMOD_MASK))) | (DMA_IP_TCD_ATTR_SMOD(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetDestination_Address(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DADDR_DADDR register */
    ptTcd->reg_DADDR = DMA_IP_TCD_DADDR_DADDR(Value);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetDestination_SignedOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DOFF_DOFF register */
    uint16 reg = ptTcd->reg_DOFF;
    ptTcd->reg_DOFF = ((uint16)(reg & (~(DMA_IP_TCD_DOFF_DOFF_MASK))) | (DMA_IP_TCD_DOFF_DOFF(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetDestination_LastAddrAdj(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DLAST_SGA_DLAST_SGA register */
    ptTcd->reg_DLAST_SGA = DMA_IP_TCD_DLAST_SGA_DLAST_SGA(Value);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetDestination_TransferSize(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_DSIZE register */
    uint16 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DSIZE_MASK))) | (DMA_IP_TCD_ATTR_DSIZE(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetDestination_Modulo(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_DMOD register */
    uint16 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DMOD_MASK))) | (DMA_IP_TCD_ATTR_DMOD(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMinorLoop_enSrcOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    ptTcd->reg_NBYTES.reg_MLOFFYES = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMinorLoop_enDstOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    ptTcd->reg_NBYTES.reg_MLOFFYES = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMinorLoop_SignedOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    ptTcd->reg_NBYTES.reg_MLOFFYES = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMinorLoop_EnLink(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CITER_ELINKYES_ELINK register */
    uint16 reg = ptTcd->reg_BITER.reg_ELINKYES;
    ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_ELINK(Value)));
    reg = ptTcd->reg_CITER.reg_ELINKYES;
    ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_ELINK(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMinorLoop_LinkCh(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CITER_ELINKYES_LINKCH register */
    uint16 reg = ptTcd->reg_BITER.reg_ELINKYES;
    ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKYES_LINKCH_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_LINKCH(Value)));
    reg = ptTcd->reg_CITER.reg_ELINKYES;
    ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKYES_LINKCH_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_LINKCH(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMinorLoop_Size(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFNO;
    if(0U != (reg & (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK | DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK)))
    {
        ptTcd->reg_NBYTES.reg_MLOFFNO = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES(Value)));
    }
    else
    {
        ptTcd->reg_NBYTES.reg_MLOFFNO = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES(Value)));
    }
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMajorLoop_EnLink(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_MAJORELINK register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_MAJORELINK_MASK))) | (DMA_IP_TCD_CSR_MAJORELINK(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMajorLoop_LinkCh(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_MAJORLINKCH register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_MAJORLINKCH_MASK))) | (DMA_IP_TCD_CSR_MAJORLINKCH(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetMajorLoop_Count(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CITER_ELINKYES_CITER register */
    uint16 reg = (ptTcd->reg_BITER.reg_ELINKYES & (DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK)) |
                 (ptTcd->reg_CITER.reg_ELINKYES & (DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK));
    if(0U != reg)
    {
        reg = ptTcd->reg_BITER.reg_ELINKYES;
        ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKYES_BITER_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_BITER(Value)));
        reg = ptTcd->reg_CITER.reg_ELINKYES;
        ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKYES_CITER_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_CITER(Value)));
    }
    else
    {
        reg = ptTcd->reg_BITER.reg_ELINKNO;
        ptTcd->reg_BITER.reg_ELINKNO = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKNO_BITER_MASK))) | (DMA_IP_TCD_BITER_ELINKNO_BITER(Value)));
        reg = ptTcd->reg_CITER.reg_ELINKNO;
        ptTcd->reg_CITER.reg_ELINKNO = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKNO_CITER_MASK))) | (DMA_IP_TCD_CITER_ELINKNO_CITER(Value)));
    }
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_ScatterGatherAddress(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DLAST_SGA_DLAST_SGA register */
    ptTcd->reg_DLAST_SGA = DMA_IP_TCD_DLAST_SGA_DLAST_SGA(Value);
}
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_StoreDestinationAddress(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SLAST_SDA_SLAST_SDA register */
    ptTcd->reg_SLAST_SDA = DMA_IP_TCD_SLAST_SDA_SLAST_SDA(Value);
}
#endif
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_EnStart(Dma_Ip_TcdRegType * ptTcd, const boolean Value)
{
    /* Access DMA_IP_TCD_CSR_START register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START((Value == TRUE) ? 1U: 0U)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_EnMajor(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_INTMAJOR register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTMAJOR_MASK))) | (DMA_IP_TCD_CSR_INTMAJOR(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_EnHalfMajor(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_INTHALF register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTHALF_MASK))) | (DMA_IP_TCD_CSR_INTHALF(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_DisAutoHwRequest(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_DREQ register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_DREQ_MASK))) | (DMA_IP_TCD_CSR_DREQ(Value)));
}
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_EnEndOfPacketSignal(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_EEOP register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_EEOP_MASK))) | (DMA_IP_TCD_CSR_EEOP(Value)));
}
#endif
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControl_BandwidthControl(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_BWC register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_BWC_MASK))) | (DMA_IP_TCD_CSR_BWC(Value)));
}

#if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE)
/*==================================================================================================
 * DMA CHANNEL CRC FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_SetCrc_InstanceChannelSelect(DMA_CRC_Type * const ptCrc, const uint32 LocHwCh, uint32 Value)
{
    /* Access DMA_CRC_CTL_CH_SEL register */
    uint32 reg = ptCrc->CONTROL_REGISTER[LocHwCh].CTL;
    ptCrc->CONTROL_REGISTER[LocHwCh].CTL = ((reg & (~(DMA_CRC_CTL_CH_SEL_MASK))) | (DMA_CRC_CTL_CH_SEL(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetCrc_ModeSelect(DMA_CRC_Type * const ptCrc, const uint32 LocHwCh, uint32 Value)
{
    /* Access DMA_CRC_CTL_MODE register */
    uint32 reg = ptCrc->CONTROL_REGISTER[LocHwCh].CTL;
    ptCrc->CONTROL_REGISTER[LocHwCh].CTL = ((reg & (~(DMA_CRC_CTL_MODE_MASK))) | (DMA_CRC_CTL_MODE(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetCrc_PolynomialSelect(DMA_CRC_Type * const ptCrc, const uint32 LocHwCh, uint32 Value)
{
    /* Access DMA_CRC_CTL_POLY_SEL register */
    uint32 reg = ptCrc->CONTROL_REGISTER[LocHwCh].CTL;
    ptCrc->CONTROL_REGISTER[LocHwCh].CTL = ((reg & (~(DMA_CRC_CTL_POLY_SEL_MASK))) | (DMA_CRC_CTL_POLY_SEL(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetCrc_EnableInitialValue(DMA_CRC_Type * const ptCrc, const uint32 LocHwCh, uint32 Value)
{
    /* Access DMA_CRC_CTL_INIT_SEL register */
    uint32 reg = ptCrc->CONTROL_REGISTER[LocHwCh].CTL;
    ptCrc->CONTROL_REGISTER[LocHwCh].CTL = ((reg & (~(DMA_CRC_CTL_INIT_SEL_MASK))) | (DMA_CRC_CTL_INIT_SEL(Value)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetCrc_InitialValue(DMA_CRC_Type * const ptCrc, const uint32 LocHwCh, uint32 Value)
{
    /* Access DMA_CRC_ICRC_INI_CRC_VAL register */
    ptCrc->CONTROL_REGISTER[LocHwCh].ICRC = DMA_CRC_ICRC_INI_CRC_VAL(Value);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetCrc_EnableLogic(DMA_CRC_Type * const ptCrc, const uint32 LocHwCh, uint32 Value)
{
    /* Access DMA_CRC_CTL_EN register */
    uint32 reg = ptCrc->CONTROL_REGISTER[LocHwCh].CTL;
    ptCrc->CONTROL_REGISTER[LocHwCh].CTL = ((reg & (~(DMA_CRC_CTL_EN_MASK))) | (DMA_CRC_CTL_EN(Value)));
}


#endif /* #if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE) */

/*==================================================================================================
 * DMA CHANNEL GET PARAMETER - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_GetSourceAddress(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_SADDR register */
    *retValue = (uint32)ptTcd->reg_SADDR;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_GetDestinationAddress(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_DADDR register */
    *retValue = (uint32)ptTcd->reg_DADDR;
}
LOCAL_INLINE void hwv3AccInlineDmaCh_GetBeginIterCount(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_BITER register */
    uint16 reg = ptTcd->reg_BITER.reg_ELINKYES & (DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK);
    if(0U != reg)
    {
        *retValue = (uint32)((ptTcd->reg_BITER.reg_ELINKYES & (uint32)DMA_IP_TCD_BITER_ELINKYES_BITER_MASK) >> DMA_IP_TCD_BITER_ELINKYES_BITER_SHIFT);
    }
    else
    {
        *retValue = (uint32)((ptTcd->reg_BITER.reg_ELINKYES & (uint32)DMA_IP_TCD_BITER_ELINKNO_BITER_MASK) >> DMA_IP_TCD_BITER_ELINKNO_BITER_SHIFT);
    }
}
LOCAL_INLINE void hwv3AccInlineDmaCh_GetCurrentIterCount(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_CITER register */
    uint16 reg = (ptTcd->reg_CITER.reg_ELINKYES & (DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK));
    if(0U != reg)
    {
        *retValue = (uint32)((ptTcd->reg_CITER.reg_ELINKYES & (uint32)DMA_IP_TCD_CITER_ELINKYES_CITER_MASK) >> DMA_IP_TCD_CITER_ELINKYES_CITER_SHIFT);
    }
    else
    {
        *retValue = (uint32)((ptTcd->reg_CITER.reg_ELINKNO & (uint32)DMA_IP_TCD_CITER_ELINKNO_CITER_MASK) >> DMA_IP_TCD_CITER_ELINKNO_CITER_SHIFT);
    }
}
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_GetStoreDstAddress(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_SLAST_SDA register */
    *retValue = (uint32)(ptTcd->reg_SLAST_SDA);
}
#endif
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_GetMasterId(const Dma_Ip_ChRegType * ptCh, uint32 * const retValue)
{
    /* Access reg_CH_SBR register */
    *retValue = (uint32)((ptCh->reg_CH_SBR & DMA_IP_TCD_CH_SBR_MID_MASK) >> DMA_IP_TCD_CH_SBR_MID_SHIFT);
}
#endif
LOCAL_INLINE void hwv3AccInlineDmaCh_GetIntMajor(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_CSR register */
    *retValue = (uint32)((ptTcd->reg_CSR & (uint32)DMA_IP_TCD_CSR_INTMAJOR_MASK) >> DMA_IP_TCD_CSR_INTMAJOR_SHIFT);
}
LOCAL_INLINE void hwv3AccInlineDmaCh_GetIntHalfMajor(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_CSR register */
    *retValue = (uint32)((ptTcd->reg_CSR & (uint32)DMA_IP_TCD_CSR_INTHALF_MASK) >> DMA_IP_TCD_CSR_INTHALF_SHIFT);
}

#if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE)
LOCAL_INLINE void hwv3AccInlineDmaCh_GetFinalCrc(const DMA_CRC_Type * const pDmaCrcCtrl, const uint32 LocHwCh, uint32 * const retValue)
{
    /* Access reg_FCRC register */
    *retValue = (uint32)(pDmaCrcCtrl->CONTROL_REGISTER[LocHwCh].FCRC);
}
#endif /* #if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE) */

/*==================================================================================================
 * DMA CHANNEL AUXILIARY FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_SetAuxiliary_EnScatterGatherProcessing(Dma_Ip_TcdRegType * ptTcd, boolean Value)
{
    /* Access DMA_IP_TCD_CSR_ESG register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_ESG_MASK))) | (DMA_IP_TCD_CSR_ESG((Value == TRUE) ? 1U: 0U)));
}
LOCAL_INLINE void hwv3AccInlineDmaCh_SetAuxiliary_EnDestinationStoreAddress(Dma_Ip_TcdRegType * ptTcd, boolean Value)
{
    /* Access DMA_IP_TCD_CSR_ESDA register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_ESDA_MASK))) | (DMA_IP_TCD_CSR_ESDA((Value == TRUE) ? 1U: 0U)));
}

/*==================================================================================================
 * TCD CONTROL AND STATUS (TCD_CSR) - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_SetControlAndStatus(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    /* Set value for TCD_CSR register*/
    uint16 reg = ptTcd->reg_CSR;
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START(pxLocScatterGather->TransferConfig->Control.EnStart ? 1U : 0U)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTMAJOR_MASK))) | (DMA_IP_TCD_CSR_INTMAJOR(pxLocScatterGather->TransferConfig->Control.EnMajorInt ? 1U : 0U)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTHALF_MASK))) | (DMA_IP_TCD_CSR_INTHALF(pxLocScatterGather->TransferConfig->Control.EnHalfMajorInt ? 1U : 0U)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_DREQ_MASK))) | (DMA_IP_TCD_CSR_DREQ(pxLocScatterGather->TransferConfig->Control.DisAutoHwRequest ? 1U : 0U)));
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_EEOP_MASK))) | (DMA_IP_TCD_CSR_EEOP(pxLocScatterGather->TransferConfig->Control.EnEndOfPacketSignal ? 1U : 0U)));
#endif
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_BWC_MASK))) | (DMA_IP_TCD_CSR_BWC(pxLocScatterGather->TransferConfig->Control.BandwidthControl)));
    /* At initialization, Store Destination Address can't be set. */
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_ESDA_MASK)))) | (DMA_IP_TCD_CSR_ESDA(0U));
    ptTcd->reg_CSR= reg;
}

/*==================================================================================================
 * TCD TRANSFER ATTRIBUTES (TCD_ATTR) - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_SetTransferAttributes(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    /* Set value for TCD_ATTR register*/
    uint16 reg = ptTcd->reg_ATTR;
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SSIZE_MASK))) | (DMA_IP_TCD_ATTR_SSIZE(pxLocScatterGather->TransferConfig->Source.TransferSize)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SMOD_MASK))) | (DMA_IP_TCD_ATTR_SMOD(pxLocScatterGather->TransferConfig->Source.Modulo)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DSIZE_MASK))) | (DMA_IP_TCD_ATTR_DSIZE(pxLocScatterGather->TransferConfig->Destination.TransferSize)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DMOD_MASK))) | (DMA_IP_TCD_ATTR_DMOD(pxLocScatterGather->TransferConfig->Destination.Modulo)));
    ptTcd->reg_ATTR= reg;
}

/*==================================================================================================
 * TCD SIGNED MINOR LOOP OFFSET (TCD_NBYTES_MLOFFYES) - REGISTER ACCESS
==================================================================================================*/
LOCAL_INLINE void hwv3AccInlineDmaCh_SetSignedMinorLoopOffset(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    /* Set value for TCD_NBYTES_MLOFFYES register*/
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    reg = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE(pxLocScatterGather->TransferConfig->MinorLoop.EnSrcOffset ? 1U : 0U)));
    reg = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE(pxLocScatterGather->TransferConfig->MinorLoop.EnDstOffset ? 1U : 0U)));
    reg = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF((uint32)pxLocScatterGather->TransferConfig->MinorLoop.Offset)));
    ptTcd->reg_NBYTES.reg_MLOFFYES= reg;
}

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */
#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef DMA_IP_HWV3_ACCESSINLINE_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

