/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
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
*   @file @file Flexray_43_LLCE_Ip_HwAccess.h
*
*   @brief Flexray HardWare Access Header File
*   @details Flexray HardWare Access Header File contains the APIs and structures exported by Flexray Driver
*
*   @addtogroup Flexray
*   @{
*/

#ifndef FLEXRAY_43_LLCE_IP_HWACCESS_H
#define FLEXRAY_43_LLCE_IP_HWACCESS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexray_43_LLCE_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_HWACCESS_MODULE_ID                        81
#define FLEXRAY_IP_HWACCESS_VENDOR_ID                        43
#define FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION         4
#define FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION         4
#define FLEXRAY_IP_HWACCESS_AR_RELEASE_REVISION_VERSION      0
#define FLEXRAY_IP_HWACCESS_SW_MAJOR_VERSION                 1
#define FLEXRAY_IP_HWACCESS_SW_MINOR_VERSION                 0
#define FLEXRAY_IP_HWACCESS_SW_PATCH_VERSION                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same vendor */
#if (FLEXRAY_IP_HWACCESS_VENDOR_ID != FLEXRAY_43_LLCE_IP_VENDOR_ID)
    #error "Flexray_43_LLCE_Ip_HwAccess.h and Flexray_43_LLCE_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same Autosar version */
#if ((FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXRAY_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXRAY_43_LLCE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Flexray_43_LLCE_Ip_HwAccess.h and Flexray_43_LLCE_Ip.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same software version */
#if ((FLEXRAY_IP_HWACCESS_SW_MAJOR_VERSION != FLEXRAY_43_LLCE_IP_SW_MAJOR_VERSION) || \
     (FLEXRAY_IP_HWACCESS_SW_MINOR_VERSION != FLEXRAY_43_LLCE_IP_SW_MINOR_VERSION) || \
     (FLEXRAY_IP_HWACCESS_SW_PATCH_VERSION != FLEXRAY_43_LLCE_IP_SW_PATCH_VERSION) \
    )
    #error "Autosar Version Numbers of Flexray_43_LLCE_Ip_HwAccess.h and Flexray_43_LLCE_Ip.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define FRAME_HEADER_SIZE 8U
#define FLEXRAY_REGISTER_SIZE  16U
#define FLEXRAY_MTCTR_ADDR32   ((uint32)0x0CU)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8 Flexray_43_LLCE_Ip_HeaderDataType[FRAME_HEADER_SIZE];

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_43_LLCE_START_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"
void Flexray_43_LLCE_PackMessageBufferHeader(Flexray_43_LLCE_Ip_HeaderDataType * pHeaderData, Flexray_Ip_FrameHeaderType* pFrameHdr);
void Flexray_43_LLCE_UnpackMessageBufferHeader (Flexray_43_LLCE_Ip_HeaderDataType * pHeaderData, Flexray_Ip_FrameHeaderType* pFrameHdr);
void Flexray_43_LLCE_calCrc(uint8 payloadLength, uint16 frameID, boolean startupFrameIndicator, boolean syncFrameIndicator, uint16* headerCrc);
boolean Flexray_43_LLCE_OccurFreeze(const FLEXRAY_Type* inst);
/*!
 * @brief Set FiFo Range Filter
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   filterNum           Number of filter
 * @param[in]   filterCfg           Point to range filter configuration structure (Flexray_Ip_RangeFilterType)
 */
void FLEXRAY_43_LLCE_SetFiFoRangeFilter(FLEXRAY_Type* base, uint8 filterNum, const Flexray_Ip_RangeFilterType *filterCfg);

/**
 * @brief Function to convert boolean to unsigned int
 * @param boolValue
 * @return uint8
 */
static inline uint8 convertBoolInt(boolean boolValue)
{
    uint8 intValue = (boolValue ? 1U : 0U);
    return intValue;
}

/*!
 * @brief   Function to read the value of both CYCTR_MTCTR
 *          registers at the same time (32bit)
 *
 * @param   base       The Flexray base address
 * @return  32bit register data value of CYCTR_MTCTR.
 */
static inline uint32 FLEXRAY_ReadCYCTR_MTCTR(const uint32 *base)
{
    return (base[FLEXRAY_MTCTR_ADDR32]);
}

/*!
 * @brief Checks if the Flexray is enabled.
 *
 * @param   base    The Flexray base address
 * @return  (boolean)TRUE if enabled; (boolean)FALSE if disabled
 */
static inline boolean FLEXRAY_43_LLCE_IsEnabled(const FLEXRAY_Type * pBase)
{
    return (((pBase->MCR & FLEXRAY_MCR_MEN_MASK) >> FLEXRAY_MCR_MEN_SHIFT) == 0U) ? FALSE : TRUE;
}

/*!
 * @brief Set trigger when message buffer switches enabled status (Disable<->Enable)
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   enable  Value for comparing with MB enabled status If difference, turn on trigger(Enable: true/Disable: false).
 */
static inline void FLEXRAY_43_LLCE_SetMBEnableMode(FLEXRAY_Type *base, uint8 index, boolean enable)
{
    uint16 regValue = base->MB[index].CCSR;
    boolean mbStatus = (((regValue & FLEXRAY_CCSR_EDS_MASK) >> FLEXRAY_CCSR_EDS_SHIFT) != 0U);
    if (mbStatus != enable)
    {
        regValue &= ~((uint16)(FLEXRAY_CCSR_EDT_MASK | FLEXRAY_CCSR_MBIF_MASK));
        regValue |= (uint16)FLEXRAY_CCSR_EDT(1U);
        base->MB[index].CCSR = regValue;
    }
}

/*!
 * @brief Set trigger when message buffer switches locked status (Locked<->Unlocked)
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   lock  Value for comparing with MB locked status If difference, turn on trigger(Enable: true/Disable: false).
 */
static inline void FLEXRAY_43_LLCE_SetMBLockMode(FLEXRAY_Type *base, uint8 index, boolean lock)
{
    uint16 regValue = base->MB[index].CCSR;
    boolean lockStatus = (((regValue & FLEXRAY_CCSR_LCKS_MASK) >> FLEXRAY_CCSR_LCKS_SHIFT) != 0U);
    if (lockStatus != lock)
    {
        regValue &= ~((uint16)(FLEXRAY_CCSR_LCKT_MASK | FLEXRAY_CCSR_MBIF_MASK));
        regValue |= (uint16)FLEXRAY_CCSR_LCKT(1U);
        base->MB[index].CCSR = regValue;
    }
}

/*!
 * @brief Commit for Transmission
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   isReady Be ready or be not ready (True: ready/False: Not ready)
 */
static inline void FLEXRAY_43_LLCE_SetMBTrasmitReady(FLEXRAY_Type *base, uint8 index, boolean isReady)
{
    uint16 regValue = base->MB[index].CCSR;
    uint8 setValue = convertBoolInt(isReady);
    regValue &= ~((uint16)(FLEXRAY_CCSR_CMT_MASK | FLEXRAY_CCSR_MBIF_MASK));
    regValue |= (uint16)FLEXRAY_CCSR_CMT(setValue);
    base->MB[index].CCSR = regValue;
}

/*!
 * @brief Commit for Transmission
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   isReady Be ready or be not ready (True: ready/False: Not ready)
 */
static inline boolean FLEXRAY_43_LLCE_GetMBTrasmitReady(const FLEXRAY_Type *base, uint8 index)
{
    boolean trasmitReadyStatus;
    if ((((base->MB[index].CCFR) & FLEXRAY_CCFR_MTM_MASK) >> FLEXRAY_CCFR_MTM_SHIFT) == 0U)
    {
        trasmitReadyStatus = ((((base->MB[index].CCSR) & FLEXRAY_CCSR_CMT_MASK) >> FLEXRAY_CCSR_CMT_SHIFT) == 0U);
    } else
    {
        trasmitReadyStatus = (((((base->MB[index].CCSR) & FLEXRAY_CCSR_CMT_MASK) >> FLEXRAY_CCSR_CMT_SHIFT) != 0U) &&
                             ((((base->MB[index].CCSR) & FLEXRAY_CCSR_DVAL_MASK) >> FLEXRAY_CCSR_DVAL_SHIFT) != 0U));
    }
    return trasmitReadyStatus;
}

/*!
 * @brief Get the locked status
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 *
 * @return lock status (True: Locked/ False: UnLocked)
 */
static inline boolean FLEXRAY_43_LLCE_GetMBLockStatus(const FLEXRAY_Type *base, uint8 index)
{
    return  (((base->MB[index].CCSR & FLEXRAY_CCSR_LCKS_MASK) >> FLEXRAY_CCSR_LCKS_SHIFT) != 0U);
}

/*!
 * @brief Set the message buffer transmission mode.
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   mode    Mode transmission (True: State/False: Event)
 */
static inline void FLEXRAY_43_LLCE_SetMBRepeat(FLEXRAY_Type *base, uint8 index, boolean repeat)
{
    uint16 regValue = base->MB[index].CCFR;
    uint8 isRepeat = convertBoolInt(repeat);
    regValue &= ~((uint16)FLEXRAY_CCFR_MTM_MASK);
    regValue |= (uint16)FLEXRAY_CCFR_MTM(isRepeat);
    base->MB[index].CCFR = regValue;
}

/*!
 * @brief Set the applied channel for message buffer.
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   isChnA  Assign channel A (True: assigned/False: not assigned)
 * @param[in]   isChnB  Assign channel B (True: assigned/False: not assigned)
 */
static inline void FLEXRAY_43_LLCE_SetMBChn(FLEXRAY_Type *base, uint8 index, boolean isChnA, boolean isChnB)
{
    uint16 regValue = base->MB[index].CCFR;
    uint8 setChnA = convertBoolInt(isChnA);
    uint8 setChnB = convertBoolInt(isChnB);
    regValue &= ~((uint16)(FLEXRAY_CCFR_CHA_MASK | FLEXRAY_CCFR_CHB_MASK));
    regValue |= (uint16)(FLEXRAY_CCFR_CHA(setChnA) | FLEXRAY_CCFR_CHB(setChnB));
    base->MB[index].CCFR = regValue;
}

/*!
 * @brief get the applied channel for message buffer.
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 * @param[in]   isChnA  Assign channel A (True: assigned/False: not assigned)
 * @param[in]   isChnB  Assign channel B (True: assigned/False: not assigned)
 */
static inline void FLEXRAY_43_LLCE_GetMBChn(const FLEXRAY_Type* base,uint8 index, boolean* isChnA, boolean* isChnB)
{
    uint16 regValue = base->MB[index].CCFR;
    *isChnA = ((regValue & FLEXRAY_CCFR_CHA_MASK) >> FLEXRAY_CCFR_CHA_SHIFT) != 0U;
    *isChnB = ((regValue & FLEXRAY_CCFR_CHB_MASK) >> FLEXRAY_CCFR_CHB_SHIFT) != 0U;
}

/*!
 * @brief Set the shadow buffer index.
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   phyIdx  Physical index of message buffer
 * @param[in]   sel     Select position (range into 0->3)(0:ChnA&Seg1/1:ChnA&Seg2/2:ChnB&Seg1/3:ChnB&Seg2)
 */
static inline void FLEXRAY_43_LLCE_SetShadowBufferIdx(FLEXRAY_Type *base, uint16 phyIdx, uint8 sel)
{
    uint16 regValue = base->RSBIR;
    regValue &= ~((uint16)(FLEXRAY_RSBIR_SEL_MASK | FLEXRAY_RSBIR_RSBIDX_MASK));
    regValue |= (uint16)(FLEXRAY_RSBIR_SEL(sel) | FLEXRAY_RSBIR_RSBIDX(phyIdx));
    base->RSBIR = regValue;
}

/*!
 * @brief Set the cycle count filter
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 * @param[in]   isEnable    Enable filter (True: enabled/False: Disabled)
 * @param[in]   value       Cycle Counter Filtering Value
 * @param[in]   mark        Cycle Counter Filtering Mark
 */
static inline void FLEXRAY_43_LLCE_SetCycleCountFilter(FLEXRAY_Type * base, uint8 index, boolean isEnable, uint8 value, uint8 mask)
{
    uint16 regValue = base->MB[index].CCFR;
    uint8 setFilEnb = convertBoolInt(isEnable);
    regValue &= ~((uint16)FLEXRAY_CCFR_CCFE_MASK);
    regValue |= (uint16)FLEXRAY_CCFR_CCFE(setFilEnb);

    if (isEnable)
    {
        regValue &= ~((uint16)(FLEXRAY_CCFR_CCFVAL_MASK | FLEXRAY_CCFR_CCFMSK_MASK));
        regValue |= (uint16)(FLEXRAY_CCFR_CCFVAL(value) | FLEXRAY_CCFR_CCFMSK(mask));
    }
    base->MB[index].CCFR = regValue;
}

/*!
 * @brief Set the frame id message buffer
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 * @param[in]   id          Frame id
 */
static inline void FLEXRAY_43_LLCE_SetMBFrameId(FLEXRAY_Type* base, uint8 index, uint16 id)
{
    uint16 regValue = base->MB[index].FIDR;
    regValue &= ~((uint16)FLEXRAY_FIDR_FID_MASK);
    regValue |= (uint16)FLEXRAY_FIDR_FID(id);
    base->MB[index].FIDR = regValue;
}

/*!
 * @brief Get the frame id message buffer
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 *
 * @return the frame id message buffer
 */
static inline uint16 FLEXRAY_43_LLCE_GetMBFrameId(const FLEXRAY_Type* base, uint16 index)
{
    return (uint16)((base->MB[index].FIDR & FLEXRAY_FIDR_FID_MASK) >> FLEXRAY_FIDR_FID_SHIFT);
}

/*!
 * @brief Set the physical index of message buffer
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 * @param[in]   phyIdx      Physical index of buffer
 */
static inline void FLEXRAY_43_LLCE_SetPhyMBIndex(FLEXRAY_Type* base, uint8 index, uint16 phyIdx)
{
    uint16 regValue = base->MB[index].IDXR;
    regValue &= ~((uint16)FLEXRAY_IDXR_MBIDX_MASK);
    regValue |= (uint16)FLEXRAY_IDXR_MBIDX(phyIdx);
    base->MB[index].IDXR = regValue;
}

/*!
 * @brief Get the physical index of message buffer
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 *
 * @return the physical index of message buffer
 */
static inline uint16 FLEXRAY_43_LLCE_GetPhyMBIndex(const FLEXRAY_Type* base, uint8 index)
{
    return (uint16)((base->MB[index].IDXR & FLEXRAY_IDXR_MBIDX_MASK) >> FLEXRAY_IDXR_MBIDX_SHIFT);
}

/*!
 * @brief Set the message buffer direction
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 * @param[in]   isTx        Message buffer direction (True: Transmit/False: Receive)
 */
static inline void FLEXRAY_43_LLCE_SetMBDirection(FLEXRAY_Type* base, uint8 index, boolean isTx)
{
    uint16 regValue = base->MB[index].CCSR;
    uint8 direct = convertBoolInt(isTx);
    regValue &= ~((uint16)(FLEXRAY_CCSR_MTD_MASK | FLEXRAY_CCSR_MBIF_MASK));
    regValue |= (uint16)FLEXRAY_CCSR_MTD(direct);
    base->MB[index].CCSR = regValue;
}

/*!
 * @brief Get the message buffer direction
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   index       Index of message buffer
 * @return the message buffer direction (True: Transmit/False: Receive)
 */
static inline boolean FLEXRAY_43_LLCE_IsMBTx(const FLEXRAY_Type* base, uint8 index)
{
    return (((base->MB[index].CCSR & FLEXRAY_CCSR_MTD_MASK) >> FLEXRAY_CCSR_MTD_SHIFT) != 0U);
}

/*!
 * @brief Set the message buffer interrupt
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   index               Index of message buffer
 * @param[in]   isEnabled           Enable message buffer interrupt (True: enabled/False: disabled)
 */
static inline void FLEXRAY_43_LLCE_SetMBInterrupt(FLEXRAY_Type* base, uint8 index, boolean isEnable)
{
    uint16 regValue =base->MB[index].CCSR;
    uint8 mbEnb = convertBoolInt(isEnable);
    regValue &= ~((uint16)(FLEXRAY_CCSR_MBIF_MASK | FLEXRAY_CCSR_MBIE_MASK));
    regValue |= (uint16)(FLEXRAY_CCSR_MBIE(mbEnb));
    base->MB[index].CCSR = regValue;
}

/*!
 * @brief Set data offset of message buffer
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   phyIdx              Physical index of message buffer
 * @param[in]   dataOffset          Data offset
 */
static inline void FLEXRAY_43_LLCE_SetMBDataOffset(FLEXRAY_Type* base, uint16 phyIdx, uint32 dataOffset)
{
    base->MBDOR[phyIdx] = (uint16)dataOffset;
}

/*!
 * @brief Get data offset of message buffer
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   phyIdx              Physical index of message buffer
 *
 * @return Data offset of message buffer
 */
static inline uint16 FLEXRAY_43_LLCE_GetMBDataOffset(const FLEXRAY_Type* base, uint16 phyIdx)
{
    uint16 phyIdxInt = phyIdx;
    if(phyIdxInt >= FLEXRAY_MBDOR_COUNT)
    {
        phyIdxInt = (uint16)(FLEXRAY_MBDOR_COUNT - 1U);
    }
    else
    {
        ;
    }
    return (uint16)(base->MBDOR[phyIdxInt]);
}

/*!
 * @brief Get the message buffer enabled status
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 *
 * @return enable status (True: Enabled/ False: Disabled)
 */
static inline boolean FLEXRAY_43_LLCE_GetMBEnableStatus(const FLEXRAY_Type* base, uint8 index)
{
    return (((base->MB[index].CCSR & FLEXRAY_CCSR_EDS_MASK) >> FLEXRAY_CCSR_EDS_SHIFT) != 0U);
}

/*!
 * @brief Get the POC status
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   index   Index of message buffer
 *
 * @return POC status (True: Command write busy / False: Command write idle)
 */
static inline boolean FLEXRAY_43_LLCE_GetPOCStatus(const FLEXRAY_Type *base)
{
    return (((base->POCR & FLEXRAY_POCR_BSY_WMC_MASK) >> FLEXRAY_POCR_BSY_WMC_SHIFT) != 0U);
}

/*!
 * @brief Set fifo watermark
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   isChnB              True: Channel B/False: Channel A
 * @param[in]   watermarkValue      Watermark Value
 */
static inline void FLEXRAY_43_LLCE_SetFiFoWatermark(FLEXRAY_Type* base, boolean isChnB, uint8 watermarkValue)
{
    uint16 regValue = base->RFWMSR;
    uint8 setChn = convertBoolInt(isChnB);
    regValue &= ~((uint16)(FLEXRAY_RFWMSR_SEL_MASK | FLEXRAY_RFWMSR_WM_MASK));
    regValue |= (uint16)(FLEXRAY_RFWMSR_SEL(setChn) | FLEXRAY_RFWMSR_WM(watermarkValue));
    base->RFWMSR = regValue;
}

/*!
 * @brief Select FiFo channel
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   isChnB              True: Channel B/False: Channel A
 */
static inline void FLEXRAY_43_LLCE_SetFiFoChn(FLEXRAY_Type* base, boolean isChnB)
{
    uint16 regValue = base->RFWMSR;
    uint8 setChn = convertBoolInt(isChnB);
    regValue &= ~((uint16)FLEXRAY_RFWMSR_SEL_MASK);
    regValue |= (uint16)FLEXRAY_RFWMSR_SEL(setChn);
    base->RFWMSR = regValue;
}

/*!
 * @brief Set FiFo Frame ID Rejection Filter
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   rejValue            Frame ID rejection filter value
 * @param[in]   rejMark             Frame ID rejection filter mask
 */
static inline void FLEXRAY_43_LLCE_SetFiFoRejFilter(FLEXRAY_Type* base, uint16 rejValue, uint16 rejMark)
{
    base->RFFIDRFMR = FLEXRAY_RFFIDRFMR_FIDRFMSK(rejMark);
    base->RFFIDRFVR = FLEXRAY_RFFIDRFVR_FIDRFVAL(rejValue);
}

/*!
 * @brief Set FiFo Message ID Acceptance Filter
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   acceptValue         Value for the message ID acceptance filter
 * @param[in]   acceptMark          Value for the message ID acceptance filter
 */
static inline void FLEXRAY_43_LLCE_SetFiFoAcceptFilter(FLEXRAY_Type* base, uint16 acceptValue, uint16 acceptMark)
{
    base->RFMIDAFVR = FLEXRAY_RFMIDAFVR_MIDAFVAL(acceptValue);
    base->RFMIDAFMR = FLEXRAY_RFMIDAFMR_MIDAFMSK(acceptMark);
}

/*!
 * @brief Set FiFo position
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   startIdx            Start index
 * @param[in]   dataOffset          Start data field offset
 */
static inline void FLEXRAY_43_LLCE_SetFiFoPos(FLEXRAY_Type* base, uint16 startIdx, uint32 dataOffset)
{
    base->RFSIR = FLEXRAY_RFSIR_SIDX(startIdx);
    base->RFSDOR = (uint16)dataOffset;
}

/*!
 * @brief Get FiFo start index
 *
 * @param[in]   base    The Flexray base address
 * @return FiFo start index
 */
static inline uint16 FLEXRAY_43_LLCE_GetFiFoStartIdx(const FLEXRAY_Type* base)
{
    return (uint16)((base->RFSIR & FLEXRAY_RFSIR_SIDX_MASK) >> FLEXRAY_RFSIR_SIDX_SHIFT);
}

/*!
 * @brief Get FiFo start data field offset
 *
 * @param[in]   base    The Flexray base address
 *
 * @return FiFo start data field offset
 */
static inline uint16 FLEXRAY_43_LLCE_GetFiFoDataOffset(const FLEXRAY_Type* base)
{
    return (uint16)((base->RFSDOR & FLEXRAY_RFSDOR_SDO_MASK) >> FLEXRAY_RFSDOR_SDO_SHIFT);
}

/*!
 * @brief Set FiFo size
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   entrySize           Size of entry
 * @param[in]   depth               Number of entry
 */
static inline void FLEXRAY_43_LLCE_SetFiFoSize(FLEXRAY_Type* base, uint8 entrySize, uint8 depth)
{
    uint16 regValue = base->RFDSR;
    regValue &= ~((uint16)(FLEXRAY_RFDSR_ENTRY_SIZE_MASK | FLEXRAY_RFDSR_FIFO_DEPTH_MASK));
    regValue |= (uint16)(FLEXRAY_RFDSR_ENTRY_SIZE(entrySize) | FLEXRAY_RFDSR_FIFO_DEPTH(depth));
    base->RFDSR = regValue;
}

/*!
 * @brief Get FiFo entry size
 *
 * @param[in]   base    The Flexray base address
 *
 * @return Size of entry
 */
static inline uint8 FLEXRAY_43_LLCE_GetFiFoEntrySize(const FLEXRAY_Type* base)
{
    return (uint8)((base->RFDSR & FLEXRAY_RFDSR_ENTRY_SIZE_MASK) >> FLEXRAY_RFDSR_ENTRY_SIZE_SHIFT);
}

/*!
 * @brief Set the protocol control command
 *
 * @param[in]   base    The Flexray base address
 * @param[in]   cmd     POC command
 */
static inline void FLEXRAY_43_LLCE_SetProtocolControlCommand(FLEXRAY_Type *base, Flexray_Ip_ChiCmdType cmd)
{
    base->POCR = (uint16)(FLEXRAY_POCR_WME_MASK | FLEXRAY_POCR_POCCMD(cmd));
}

/*!
 * @brief Set global configuration of the CC.
 * Two parameters are fixed value:
 * + EEC functionality disabled
 * + Read Index is not updated on writing 1 when FIFO happens almost full
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   ccConfig    Point to CC configuration structure (Flexray_Ip_CcConfigType)
 */
static inline void FLEXRAY_43_LLCE_SetModuleConfiguration(FLEXRAY_Type *base, const Flexray_Ip_CcConfigType * ccConfig)
{
    uint8 freezeMode = convertBoolInt(ccConfig->freezeMode);
    uint8 chnDeviceMode = convertBoolInt(ccConfig->singleChnlMode);
    uint8 chnA = convertBoolInt(ccConfig->channelA);
    uint8 chnB = convertBoolInt(ccConfig->channelB);
    uint8 syncFrameFilter = convertBoolInt(ccConfig->syncFrameFilter);
    /* EEC functionality disabled */
    uint8 disEEC = 0U;
    /* Read Index is not updated on writing 1 when FIFO happens almost full */
    uint8 fifoNotUpdate = 0U;
    uint8 memLayout = (uint8)(ccConfig->memLayout);
    uint8 bitRate =(uint8)(ccConfig->bitRate);
    base->MCR = FLEXRAY_MCR_SBFF(freezeMode) |
              FLEXRAY_MCR_SCM(chnDeviceMode) |
              FLEXRAY_MCR_CHB(chnB) |
              FLEXRAY_MCR_CHA(chnA) |
              FLEXRAY_MCR_SFFE(syncFrameFilter) |
              FLEXRAY_MCR_ECCE(disEEC) |
              FLEXRAY_MCR_FUM(fifoNotUpdate) |
              FLEXRAY_MCR_FAM(memLayout) |
              FLEXRAY_MCR_BITRATE(bitRate);
}

/*!
 * @brief Get memory layout
 *
 * @param[in]   base    The Flexray base address
 *
 * @return memory layout (True: Dedicated/False: Mix)
 */
static inline boolean FLEXRAY_43_LLCE_GetMemLayout(const FLEXRAY_Type *base)
{
    return (((base->MCR & FLEXRAY_MCR_FAM_MASK) >> FLEXRAY_MCR_FAM_SHIFT) != 0U);
}

/*!
 * @brief Set the system memory base address
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   baseMemAddr    System memory base address
 */
static inline void FLEXRAY_43_LLCE_SetSysMemBaseAddr(FLEXRAY_Type *base, uint32 baseMemAddr)
{
    base->SYMBADHR = (uint16)((baseMemAddr >> 16UL) & 0xFFFFUL);
    base->SYMBADLR = (uint16)(baseMemAddr & 0xFFFFUL);
}

/*!
 * @brief Get the system memory base address
 *
 * @param[in]   base           The Flexray base address
 *
 * @return system memory base address
 */
static inline uint32 FLEXRAY_43_LLCE_GetSysMemBaseAddr(const FLEXRAY_Type *base)
{
    uint32 addrHighPart = (uint32)(base->SYMBADHR) << 16U;
    uint32 addrLowPart = (uint32)(base->SYMBADLR);
    uint32 sysBaseAddr = addrHighPart + addrLowPart;
    return sysBaseAddr;
}

/*!
 * @brief Set the receive FIFO system memory base address
 *
 * @param[in]   base               The Flexray base address
 * @param[in]   fifobaseMemAddr    System memory base address
 */
static inline void FLEXRAY_43_LLCE_SetRxFiFoSysMemBaseAddr(FLEXRAY_Type *base, uint32 fifobaseMemAddr)
{
    base->RFSYMBADHR = (uint16) ((fifobaseMemAddr >> 16UL) & 0xFFFFUL);
    base->RFSYMBADLR = (uint16) (fifobaseMemAddr & 0xFFFFUL);
}

/*!
 * @brief Get the receive FIFO system memory base address
 *
 * @param[in]   base               The Flexray base address
 *
 * @return system memory base address
 */
static inline uint32 FLEXRAY_43_LLCE_GetRxFiFoSysMemBaseAddr(const FLEXRAY_Type *base)
{
    uint32 addrHighPart = ((uint32)(base->RFSYMBADHR) << 16U);
    uint32 addrLowPart = (uint32)(base->RFSYMBADLR);
    uint32 fifoBaseAddr = addrHighPart + addrLowPart;
    return fifoBaseAddr;
}

/*!
 * @brief Set module enable
 *
 * @param[in]   base               The Flexray base address
 * @param[in]   isEnabled          Enable module (True: CC enabled/False: CC disabled)
 */
static inline void FLEXRAY_43_LLCE_EnableCC(FLEXRAY_Type *base, boolean isEnable)
{
    uint16 regValue = base->MCR;
    uint8 enbCC = convertBoolInt(isEnable);
    regValue &= ~ ((uint16)FLEXRAY_MCR_MEN_MASK);
    regValue |= FLEXRAY_MCR_MEN(enbCC);
    base->MCR = regValue;
}

/*!
 * @brief Set the size of two segments
 *
 * @param[in]   base               The Flexray base address
 * @param[in]   seg1Size           Size of segment 1
 * @param[in]   seg2Size           Size of segment 2
 */
static inline void FLEXRAY_43_LLCE_SetSegmentSize(FLEXRAY_Type *base, uint8 seg1Size, uint8 seg2Size)
{
    uint8 lastMbSeg1 = seg1Size - 1U;
    uint8 lastMbUlt = seg1Size + seg2Size - 1U;

    base->MBSSUTR = FLEXRAY_MBSSUTR_LAST_MB_SEG1(lastMbSeg1) |
                    FLEXRAY_MBSSUTR_LAST_MB_UTIL(lastMbUlt);
}

/*!
 * @brief Get the size of segment 1
 *
 * @param[in]   base               The Flexray base address
 *
 * @return size of segment 1
 */
static inline uint8 FLEXRAY_43_LLCE_GetSegment1Size(const FLEXRAY_Type *base)
{
    return (uint8)((base->MBSSUTR & FLEXRAY_MBSSUTR_LAST_MB_SEG1_MASK) >> FLEXRAY_MBSSUTR_LAST_MB_SEG1_SHIFT);
}

/*!
 * @brief Set the size each buffer into two segments
 *
 * @param[in]   base               The Flexray base address
 * @param[in]   seg1BuffSize       Size each buffer into segment 1
 * @param[in]   seg2BuffSize       Size each buffer into segment 2
 */
static inline void FLEXRAY_43_LLCE_SetSegmentBuffSize(FLEXRAY_Type *base, uint8 seg1BuffSize, uint8 seg2BuffSize)
{
    base->MBDSR = FLEXRAY_MBDSR_MBSEG1DS(seg1BuffSize) |
                  FLEXRAY_MBDSR_MBSEG2DS(seg2BuffSize);
}

/*!
 * @brief Get the size each buffer into segment 1
 *
 * @param[in]   base               The Flexray base address
 *
 * @return the size each buffer into segment 1
 */
static inline uint8 FLEXRAY_43_LLCE_GetSegment1BufferSize(const FLEXRAY_Type *base)
{
    return (uint8)((base->MBDSR & FLEXRAY_MBDSR_MBSEG1DS_MASK) >> FLEXRAY_MBDSR_MBSEG1DS_SHIFT);
}

/*!
 * @brief Get the size each buffer into segment 2
 *
 * @param[in]   base               The Flexray base address
 *
 * @return the size each buffer into segment 2
 */
static inline uint8 FLEXRAY_43_LLCE_GetSegment2BufferSize(const FLEXRAY_Type *base)
{
    return (uint8)((base->MBDSR & FLEXRAY_MBDSR_MBSEG2DS_MASK) >> FLEXRAY_MBDSR_MBSEG2DS_SHIFT);
}

/*!
 * @brief Get the number of static slots
 *
 * @param[in]   base               The Flexray base address
 *
 * @return the number of static slots
 */
static inline uint16 FLEXRAY_43_LLCE_GetNumbOfStaticSlots(const FLEXRAY_Type *base)
{
    return (uint16)((base->PCR2 & FLEXRAY_PCR2_number_of_static_slots_MASK) >> FLEXRAY_PCR2_number_of_static_slots_SHIFT);
}

/*!
 * @brief Get the key slot
 *
 * @param[in]   base               The Flexray base address
 *
 * @return the key slot
 */
static inline uint16 FLEXRAY_43_LLCE_GetKeySlot(const FLEXRAY_Type *base)
{
    return (uint16)((base->PCR18 & FLEXRAY_PCR18_key_slot_id_MASK) >> FLEXRAY_PCR18_key_slot_id_SHIFT);
}


/*!
 * @brief Get the payload length of static slots
 *
 * @param[in]   base               The Flexray base address
 *
 * @return the payload length of static slots
 */
static inline uint8 FLEXRAY_43_LLCE_GetPayloadLengthStatic(const FLEXRAY_Type *base)
{
    return (uint8)((base->PCR19 & FLEXRAY_PCR19_payload_length_static_MASK) >> FLEXRAY_PCR19_payload_length_static_SHIFT);
}


/*!
 * @brief Get the fill level of fifo channel
 *
 * @param[in]   base      The Flexray base address
 * @param[in]   isChnB    Choose channel (True: Channel B/False: Channel A)
 *
 * @return the fill level
 */
static inline uint8 FLEXRAY_43_LLCE_FillLevelFiFo(const FLEXRAY_Type * base, boolean isChnB)
{
    uint8 fillLevel = 0U;
    if (isChnB)
    {
        fillLevel = (uint8)((base->RFFLPCR & FLEXRAY_RFFLPCR_FLB_or_PCB_MASK) >> FLEXRAY_RFFLPCR_FLB_or_PCB_SHIFT);
    }
    else
    {
        fillLevel = (uint8)((base->RFFLPCR & FLEXRAY_RFFLPCR_FLA_or_PCA_MASK) >> FLEXRAY_RFFLPCR_FLA_or_PCA_SHIFT);
    }
    return fillLevel;
}

/*!
 * @brief Set the pop count of fifo channel
 *
 * @param[in]   base      The Flexray base address
 * @param[in]   isChnB    Choose channel (True: Channel B/False: Channel A)
 * @param[in]   popCount  The pop count
 *
 * @return the fill level
 */
static inline void FLEXRAY_43_LLCE_PopCountFiFo(FLEXRAY_Type * base, boolean isChnB, uint8 popCount)
{
    if (isChnB)
    {
        base->RFFLPCR = FLEXRAY_RFFLPCR_FLB_or_PCB(popCount);
    }
    else
    {
        base->RFFLPCR = FLEXRAY_RFFLPCR_FLA_or_PCA(popCount);
    }
}

/*!
 * @brief Read the message buffer header index of the next available FIFOA message
buffer
 *
 * @param[in]   base      The Flexray base address
 *
 * @return the message buffer header index of the next available FIFOA message
buffer
 */
static inline uint16 FLEXRAY_43_LLCE_ReceiveFiFoAReadIdx(const FLEXRAY_Type *base)
{
    return (uint16)((base->RFARIR & FLEXRAY_RFARIR_RDIDX_MASK) >> FLEXRAY_RFARIR_RDIDX_SHIFT);
}

/*!
 * @brief Read the message buffer header index of the next available FIFOB message
buffer
 *
 * @param[in]   base      The Flexray base address
 *
 * @return the message buffer header index of the next available FIFOB message
buffer
 */
static inline uint16 FLEXRAY_43_LLCE_ReceiveFiFoBReadIdx(const FLEXRAY_Type *base)
{
    return (uint16)((base->RFBRIR & FLEXRAY_RFBRIR_RDIDX_MASK) >> FLEXRAY_RFBRIR_RDIDX_SHIFT);
}

/*!
 * @brief Set FiFo timer duration
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   timerDuration   FiFo timer duration value
 *
 */
static inline void FLEXRAY_43_LLCE_SetFiFoTimerDuration(FLEXRAY_Type *base, uint16 timerDuration)
{
    uint16 regValue = base->RFPTR;
    regValue &= ~((uint16)FLEXRAY_RFPTR_PTD_MASK);
    regValue |= FLEXRAY_RFPTR_PTD(timerDuration);
    base->RFPTR = regValue;
}

/*!
 * @brief Set system memory access timeout
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   timeoutVal     Timeout value
 *
 */
static inline void FLEXRAY_43_LLCE_SetSysMemAccessTimeout(FLEXRAY_Type *base, uint32 timeoutVal)
{
    uint16 regValue = base->SYMATOR;
    regValue &= ~((uint16)FLEXRAY_SYMATOR_TIMEOUT_MASK);
    regValue |= FLEXRAY_SYMATOR_TIMEOUT(timeoutVal);
    base->SYMATOR = regValue;
}

/*!
 * @brief Set the protocol engine configuration
 *
 * @param[in]   base        The Flexray base address
 * @param[in]   peConfig    point to protocol engine configuration structure (Flexray_Ip_PeConfigType)
 */
void FLEXRAY_43_LLCE_InitPE(uint8 instNum, const Flexray_Ip_PeConfigType* peConfig);


/*!
 * @brief Clears message buffer tx/rx flag
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   index               Index of message buffer
 */
static inline void FLEXRAY_43_LLCE_ClearMBFlag(FLEXRAY_Type* base, uint8 index)
{
    uint8 one = 1U;
    base->MB[index].CCSR |= FLEXRAY_CCSR_MBIF(one);
}

/*!
 * @brief Gets message buffer tx/rx flag
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   index               Index of message buffer
 */
static inline boolean FLEXRAY_43_LLCE_GetMBFlag(const FLEXRAY_Type* base, uint8 index)
{
    return ((base->MB[index].CCSR & FLEXRAY_CCSR_MBIF_MASK) != 0U);
}

/*!
 * @brief Gets message buffer tx/rx interrupt enable
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   index               Index of message buffer
 */
static inline boolean FLEXRAY_43_LLCE_GetMBInterruptEnable(const FLEXRAY_Type* base, uint8 index)
{
    return ((base->MB[index].CCSR & FLEXRAY_CCSR_MBIE_MASK) != 0U);
}

/*!
 * @brief Gets message buffer data update
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   index               Index of message buffer
 */
static inline boolean FLEXRAY_43_LLCE_GetMBDataUpdate(const FLEXRAY_Type* base, uint8 index)
{
    return ((base->MB[index].CCSR & FLEXRAY_CCSR_DUP_MASK) != 0U);
}

/*!
 * @brief Gets slot status
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   slotIdx             The slot index
 * @param[in]   isChnA              True: channel A/False: channel B
 */
static inline uint8 FLEXRAY_43_LLCE_GetSlotStatus(const FLEXRAY_Type* base, uint8 slotIdx, boolean isChnA)
{
    uint8 slotStatus;

    if (isChnA)
    {
        slotStatus = ((uint8)(base->SSR[slotIdx])) & 0xFFU;
    }
    else
    {
        slotStatus = ((uint8)(base->SSR[slotIdx] >> 8U)) & 0xFFU;
    }

    return slotStatus;
}


/*!
 * @brief Set external offset correction application type
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   correctType    Correction type
 */
static inline void FLEXRAY_43_LLCE_SetOffsetCorrection(FLEXRAY_Type* base, Flexray_Ip_ExtClkCorrectType correctType)
{
    uint16 rateCorrection = base->POCR & FLEXRAY_POCR_ERC_AP_MASK;
    base->POCR = (FLEXRAY_POCR_BSY_WMC_MASK | FLEXRAY_POCR_EOC_AP((uint8)correctType) | rateCorrection);
}

/*!
 * @brief Set external rate correction application type
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   correctType    Correction type
 */
static inline void FLEXRAY_43_LLCE_SetRateCorrection(FLEXRAY_Type* base, Flexray_Ip_ExtClkCorrectType correctType)
{
    uint16 offsetCorrection = base->POCR & FLEXRAY_POCR_EOC_AP_MASK;
    base->POCR = (FLEXRAY_POCR_BSY_WMC_MASK | FLEXRAY_POCR_ERC_AP((uint8)correctType) | offsetCorrection);
}

/*!
 * @brief Set MTS cycle filter of channel A
 *
 * @param[in] base              The Flexray base address
 * @param[in] mtsfilterChnA     MTS cycle count filter of Channel A
 */
static inline void FLEXRAY_43_LLCE_SetMTSFilterChnA(FLEXRAY_Type* base,
                                            const Flexray_Ip_MtsFilterType* mtsfilterChnA)
{
    uint16 regValue = base->MTSACFR;
    regValue &= ~((uint16)(FLEXRAY_MTSACFR_CYCCNTMSK_MASK | FLEXRAY_MTSACFR_CYCCNTVAL_MASK));

    if (mtsfilterChnA != NULL_PTR)
    {
        regValue |= ((uint16)(FLEXRAY_MTSACFR_CYCCNTMSK(mtsfilterChnA->cycCountMask) | \
                                FLEXRAY_MTSACFR_CYCCNTVAL(mtsfilterChnA->cycCountValue)));
    }

    base->MTSACFR = regValue;
}

/*!
 * @brief Set MTS cycle filter of channel B
 *
 * @param[in] base              The Flexray base address
 * @param[in] mtsfilterChnB     MTS cycle count filter of Channel B
 */
static inline void FLEXRAY_43_LLCE_SetMTSFilterChnB(FLEXRAY_Type* base,
                                      const Flexray_Ip_MtsFilterType* mtsfilterChnB)
{
    uint16 regValue = base->MTSBCFR;
    regValue &= ~((uint16)(FLEXRAY_MTSBCFR_CYCCNTMSK_MASK | FLEXRAY_MTSBCFR_CYCCNTVAL_MASK));

    if (mtsfilterChnB != NULL_PTR)
    {
        regValue |= ((uint16)(FLEXRAY_MTSBCFR_CYCCNTMSK(mtsfilterChnB->cycCountMask) | \
                                FLEXRAY_MTSBCFR_CYCCNTVAL(mtsfilterChnB->cycCountValue)));
    }

    base->MTSBCFR = regValue;
}

/*!
 * @brief Gets network management vector length
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   index               Index of message buffer
 */
static inline uint8 FLEXRAY_43_LLCE_GetNMVLength(const FLEXRAY_Type* base)
{
    return (uint8)((base->NMVLR & FLEXRAY_NMVLR_NMVL_MASK) >> FLEXRAY_NMVLR_NMVL_SHIFT);
}

/*!
 * @brief Gets network management vector
 *
 * @param[in]   base                The Flexray base address
 * @param[in]   regIndex            Register index
 */
static inline uint16 FLEXRAY_43_LLCE_GetNMV(const FLEXRAY_Type* base, uint8 regIndex)
{
    uint8 regIndexInt = regIndex;
    if(regIndexInt >= FLEXRAY_NMVR_COUNT)
    {
        regIndexInt = (uint8)(FLEXRAY_NMVR_COUNT - 1U);
    }
    else
    {
        ;
    }
    return (base->NMVR[regIndexInt]);
}

/*!
 * @brief Start timer 1
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isStart        true: start/false: no effect
 */
static inline void FLEXRAY_43_LLCE_StartTimer1(FLEXRAY_Type *base, boolean isStart)
{
    uint16 regValue = base->TICCR;
    uint8 start = convertBoolInt(isStart);
    regValue &= ~((uint16)FLEXRAY_TICCR_T1TR_MASK);
    regValue |= FLEXRAY_TICCR_T1TR(start);
    base->TICCR = regValue;
}

/*!
 * @brief Start timer 2
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isStart        true: start/false: no effect
 */
static inline void FLEXRAY_43_LLCE_StartTimer2(FLEXRAY_Type *base, boolean isStart)
{
    uint16 regValue = base->TICCR;
    uint8 start = convertBoolInt(isStart);
    regValue &= ~((uint16)FLEXRAY_TICCR_T2TR_MASK);
    regValue |= FLEXRAY_TICCR_T2TR(start);
    base->TICCR = regValue;
}

/*!
 * @brief Stop timer 1
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isStop         true: stop/false: no effect
 */
static inline void FLEXRAY_43_LLCE_StopTimer1(FLEXRAY_Type *base, boolean isStop)
{
    uint16 regValue = base->TICCR;
    uint8 stop = convertBoolInt(isStop);
    regValue &= ~((uint16)FLEXRAY_TICCR_T1SP_MASK);
    regValue |= FLEXRAY_TICCR_T1SP(stop);
    base->TICCR = regValue;
}

/*!
 * @brief Stop timer 2
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isStop         true: stop/false: no effect
 */
static inline void FLEXRAY_43_LLCE_StopTimer2(FLEXRAY_Type *base, boolean isStop)
{
    uint16 regValue = base->TICCR;
    uint8 stop = convertBoolInt(isStop);
    regValue &= ~((uint16)FLEXRAY_TICCR_T2SP_MASK);
    regValue |= FLEXRAY_TICCR_T2SP(stop);
    base->TICCR = regValue;
}

/*!
 * @brief Configure timer 1
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   timeCfg        Pointer to timer configuration structure
 */
void FLEXRAY_43_LLCE_ConfigureTimer1(FLEXRAY_Type *base, const Flexray_Ip_TimerConfigType* timerCfg);

/*!
 * @brief Configure timer 2
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   timeCfg        Pointer to timer configuration structure
 */
void FLEXRAY_43_LLCE_ConfigureTimer2(FLEXRAY_Type *base, const Flexray_Ip_TimerConfigType* timerCfg);

/*!
 * @brief Set transmit interrupt. Enable/Disable transmit message buffer interrupt.
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isEnable       true: enabled/false: disable
 */
static inline void FLEXRAY_43_LLCE_SetTxMBInterrupt(FLEXRAY_Type *base, boolean isEnable)
{
    uint16 regValue = base->GIFER;
    uint8 enb = convertBoolInt(isEnable);
    regValue &= ~((uint16)(FLEXRAY_GIFER_TBIE_MASK | FLEXRAY_GIFER_WUPIF_MASK | \
                             FLEXRAY_GIFER_FAFBIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK));
    regValue |= FLEXRAY_GIFER_TBIE(enb);
    base->GIFER = regValue;
}

/*!
 * @brief Set receive interrupt. Enable/Disable receive message buffer interrupt.
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isEnable       true: enabled/false: disable
 */
static inline void FLEXRAY_43_LLCE_SetRxMBInterrupt(FLEXRAY_Type *base, boolean isEnable)
{
    uint16 regValue = base->GIFER;
    uint8 enb = convertBoolInt(isEnable);
    regValue &= ~((uint16)(FLEXRAY_GIFER_RBIE_MASK | FLEXRAY_GIFER_WUPIF_MASK | \
                             FLEXRAY_GIFER_FAFBIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK));
    regValue |= FLEXRAY_GIFER_RBIE(enb);
    base->GIFER = regValue;
}

/*!
 * @brief Get all protocol interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline uint32 FLEXRAY_43_LLCE_GetAllProtocolInterruptFlag(const FLEXRAY_Type *base)
{
    uint32 pr16LowBitFlag = ((uint32)(base->PIFR0));
    uint32 pr16HighBitFlag = ((uint32)(base->PIFR1));

    uint32 prBitFlag = (pr16LowBitFlag | (pr16HighBitFlag << 16U));

    return prBitFlag;
}

/*!
 * @brief Get all protocol interrupt enable
 *
 * @param[in]   base           The Flexray base address
 */
static inline uint32 FLEXRAY_43_LLCE_GetAllProtocolInterruptEnable(const FLEXRAY_Type *base)
{
    uint32 pr16LowBitFlag = ((uint32)(base->PIER0));
    uint32 pr16HighBitFlag = ((uint32)(base->PIER1));

    uint32 prBitFlag = (pr16LowBitFlag | (pr16HighBitFlag << 16U));

    return prBitFlag;
}
/*!
 * @brief Clear all protocol interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_ClearAllProtocolInterruptFlag(FLEXRAY_Type *base)
{
    base->PIFR0 = 0xFFFFU;
    base->PIFR1 = 0xFF30U;
}

/*!
 * @brief Disable all protocol interrupts
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_DisableAllProtocolInterrupt(FLEXRAY_Type *base)
{
    base->PIER0 = 0x00U;
    base->PIER1 = 0x00U;
}

/*!
 * @brief Disable all global interrupts
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_DisableAllGlobalInterrupt(FLEXRAY_Type *base)
{
    base->GIFER = 0x00U;
}

/*!
 *@brief Disable all range filter
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_DisableAllRangeFilter(FLEXRAY_Type *base)
{
    base->RFRFCTR &= ~(uint16)((uint16)FLEXRAY_RFRFCTR_F0EN_MASK | ((uint16)FLEXRAY_RFRFCTR_F1EN_MASK | \
                                 ((uint16)FLEXRAY_RFRFCTR_F2EN_MASK | FLEXRAY_RFRFCTR_F3EN_MASK)));
}

/*!
 * @brief Get WUP interrupt enable
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetWUPInterruptEnable(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_WUPIE_MASK) >> FLEXRAY_GIFER_WUPIE_SHIFT)!= 0U);
}

/*!
 * @brief Get CHI interrupt enable
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetCHIInterruptEnable(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_CHIE_MASK) >> FLEXRAY_GIFER_CHIE_SHIFT)!= 0U);
}

/*!
 * @brief Get FIFOA interrupt enable
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetFIFOAInterruptEnable(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_FAFAIE_MASK) >> FLEXRAY_GIFER_FAFAIE_SHIFT)!= 0U);
}

/*!
 * @brief Get FIFOB interrupt enable
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetFIFOBInterruptEnable(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_FAFBIE_MASK) >> FLEXRAY_GIFER_FAFBIE_SHIFT)!= 0U);
}

/*!
 * @brief Get WUP interrupt enable
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetWUPInterruptFlag(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_WUPIF_MASK) >> FLEXRAY_GIFER_WUPIF_SHIFT)!= 0U);
}

/*!
 * @brief Get FIFOA interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetFifoAInterruptFlag(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_FAFAIF_MASK) >> FLEXRAY_GIFER_FAFAIF_SHIFT)!= 0U);
}

/*!
 * @brief Get FIFOB interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetFifoBInterruptFlag(const FLEXRAY_Type *base)
{
    return ((((base->GIFER) & FLEXRAY_GIFER_FAFBIF_MASK) >> FLEXRAY_GIFER_FAFBIF_SHIFT)!= 0U);
}

/*!
 * @brief Clear FIFOA interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_ClearFifoAInterruptFlag(FLEXRAY_Type *base)
{
    uint8 one = 1U;
    uint16 regValue = base->GIFER;
    regValue &= ~((uint16)(FLEXRAY_GIFER_WUPIF_MASK | FLEXRAY_GIFER_FAFBIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK));
    regValue |= FLEXRAY_GIFER_FAFAIF(one);
    base->GIFER = regValue;
}

/*!
 * @brief Clear FIFOB interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_ClearFifoBInterruptFlag(FLEXRAY_Type *base)
{
    uint8 one = 1U;
    uint16 regValue = base->GIFER;
    regValue &= ~((uint16)(FLEXRAY_GIFER_WUPIF_MASK | FLEXRAY_GIFER_FAFBIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK));
    regValue |= FLEXRAY_GIFER_FAFBIF(one);
    base->GIFER = regValue;
}

/*!
 * @brief Get all chi error interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline uint16 FLEXRAY_43_LLCE_GetAllCHIErrorInterruptFlag(const FLEXRAY_Type *base)
{
    return (base->CHIERFR);
}


/*!
 * @brief Clear all chi error interrupt flags
 *
 * @param[in]   base           The Flexray base address
 */
static inline void FLEXRAY_43_LLCE_ClearAllCHIErrorInterruptFlag(FLEXRAY_Type *base)
{
    base->CHIERFR = 0xFFFFU;
}

/*!
 * @brief Set timebase mode for Timer 2
 *
 * @param[in]   base           The Flexray base address
 * @param[in]   isRelative     True: Relative, False: Absolute
 *
 */
static inline void FLEXRAY_43_LLCE_SetTimebaseModeTimer2(FLEXRAY_Type *base, boolean isRelative)
{
    uint16 regValue = base->TICCR;

    if (isRelative)
    {
        regValue |= ((uint16)FLEXRAY_TICCR_T2_CFG_MASK);
    }
    else
    {
        regValue &= ~((uint16)FLEXRAY_TICCR_T2_CFG_MASK);
    }

    base->TICCR = regValue;
}

/*!
 * @brief Set enable or disable generate MTS
 *
 * @param[in]   base      The Flexray base address
 * @param[in]   isChnA    Assign channel A (True: assigned/False: not assigned)
 * @param[in]   enable    Enable or disable MTS transmission (True: enable/False: disable).
 *
 */
static inline void FLEXRAY_43_LLCE_SetMTS(FLEXRAY_Type *base, boolean isChnA, boolean enable)
{
    uint8 tempValue = convertBoolInt(enable);

    if (isChnA)
    {
        base->MTSACFR = FLEXRAY_MTSACFR_MTE(tempValue);
    }
    else
    {
        base->MTSBCFR = FLEXRAY_MTSBCFR_MTE(tempValue);
    }
}


/*!
 * @brief Get ChnA transmission conflict occurred
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetTxChnAConflict(const FLEXRAY_Type *base)
{
    return ((((base->PSR2) & FLEXRAY_PSR2_STCA_MASK) >> FLEXRAY_PSR2_STCA_SHIFT)!= 0U);
}

/*!
 * @brief Get ChnB transmission conflict occurred
 *
 * @param[in]   base           The Flexray base address
 */
static inline boolean FLEXRAY_43_LLCE_GetTxChnBConflict(const FLEXRAY_Type *base)
{
    return ((((base->PSR2) & FLEXRAY_PSR2_STCB_MASK) >> FLEXRAY_PSR2_STCB_SHIFT)!= 0U);
}

#define FR_43_LLCE_STOP_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXRAY_43_LLCE_IP_HWACCESS_H */
