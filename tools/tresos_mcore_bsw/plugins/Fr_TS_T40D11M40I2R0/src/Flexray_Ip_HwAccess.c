/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
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
*   @file Flexray_Ip_HwAccess.c
*
*   @brief FLEXRAY HardWare Access
*
*   @addtogroup Flexray
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
#include "Flexray_Ip_HwAccess.h"
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_HWACCESS_VENDOR_ID_C                        43
#define FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C         4
#define FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C         4
#define FLEXRAY_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C      0
#define FLEXRAY_IP_HWACCESS_SW_MAJOR_VERSION_C                 4
#define FLEXRAY_IP_HWACCESS_SW_MINOR_VERSION_C                 0
#define FLEXRAY_IP_HWACCESS_SW_PATCH_VERSION_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip_HwAccess.h header file are of the same vendor */
#if(FLEXRAY_IP_HWACCESS_VENDOR_ID_C != FLEXRAY_IP_HWACCESS_VENDOR_ID)
    #error "Flexray_Ip_HwAccess.c and Flexray_Ip_HwAccess.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_HwAccess.h header file are of the same Autosar version */
#if((FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip_HwAccess.c and Flexray_Ip_HwAccess.h are different"
#endif
/* Check if current file and Flexray_Ip_HwAccess.h header file are of the same software version */
#if((FLEXRAY_IP_HWACCESS_SW_MAJOR_VERSION_C != FLEXRAY_IP_HWACCESS_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP_HWACCESS_SW_MINOR_VERSION_C != FLEXRAY_IP_HWACCESS_SW_MINOR_VERSION) || \
    (FLEXRAY_IP_HWACCESS_SW_PATCH_VERSION_C != FLEXRAY_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip_HwAccess.c and Flexray_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
        /* Check if current file and Devassert.h header file are of the same Autosar version */
        #if((FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Flexray_Ip_HwAccess.c and Devassert.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_InitPE
 * Description   : Configures all parameters of protocol engine.
 *
 *END**************************************************************************/
void FLEXRAY_InitPE(uint8 instNum,
                                    const Flexray_Ip_PeConfigType* peConfig)
{
    FLEXRAY_Type* base = Flexray_Ip_apxBase[instNum];
    base->PCR0 = FLEXRAY_PCR0_action_point_offset((uint16)(peConfig->gdActionPointOffset) - 1U) |
               FLEXRAY_PCR0_static_slot_length(peConfig->gdStaticSlot);
    base->PCR1 = FLEXRAY_PCR1_macro_after_first_static_slot(peConfig->gMacroPerCycle - peConfig->gdStaticSlot);
    base->PCR2 = FLEXRAY_PCR2_minislot_after_action_point((uint16)(peConfig->gdMinislot) - peConfig->gdMinislotActionPointOffset - 1U) |
               FLEXRAY_PCR2_number_of_static_slots(peConfig->gNumberOfStaticSlots);
    base->PCR3 = FLEXRAY_PCR3_wakeup_symbol_rx_low(peConfig->gdWakeupSymbolRxLow) |
               FLEXRAY_PCR3_minislot_action_point_offset((uint16)(peConfig->gdMinislotActionPointOffset) - 1U) |
               FLEXRAY_PCR3_coldstart_attempts(peConfig->gColdstartAttempts);
    base->PCR4 = FLEXRAY_PCR4_cas_rx_low_max((uint16)(peConfig->gdCASRxLowMax) - 1U) |
               FLEXRAY_PCR4_wakeup_symbol_rx_window(peConfig->gdWakeupSymbolRxWindow);
    base->PCR5 = FLEXRAY_PCR5_tss_transmitter(peConfig->gdTSSTransmitter) |
               FLEXRAY_PCR5_wakeup_symbol_tx_low(peConfig->gdWakeupSymbolTxLow) |
               FLEXRAY_PCR5_wakeup_symbol_rx_idle(peConfig->gdWakeupSymbolRxIdle);
    base->PCR6 = FLEXRAY_PCR6_symbol_window_after_action_point((uint16)(peConfig->gdSymbolWindow) - peConfig->gdActionPointOffset - 1U) |
               FLEXRAY_PCR6_macro_initial_offset_a(peConfig->pMacroInitialOffsetA);
    base->PCR7 = FLEXRAY_PCR7_decoding_correction_b(peConfig->pDecodingCorrection + peConfig->pDelayCompensationB + 2U) |
               FLEXRAY_PCR7_micro_per_macro_nom_half((uint8)((peConfig->pMicroPerMacroNom)/2U));
    base->PCR8 = FLEXRAY_PCR8_max_without_clock_correction_fatal(peConfig->gMaxWithoutClockCorrectionFatal) |
               FLEXRAY_PCR8_max_without_clock_correction_passive(peConfig->gMaxWithoutClockCorrectionPassive) |
               FLEXRAY_PCR8_wakeup_symbol_tx_idle(peConfig->gdWakeupSymbolTxIdle);
    base->PCR9 = FLEXRAY_PCR9_minislot_exists(convertBoolInt(peConfig->gMiniSlotExists)) |
               FLEXRAY_PCR9_symbol_window_exists(convertBoolInt(peConfig->gSymbolWindowExists)) |
               FLEXRAY_PCR9_offset_correction_out(peConfig->pOffsetCorrectionOut);
    base->PCR10 = FLEXRAY_PCR10_single_slot_enabled(convertBoolInt(peConfig->pSingleSlotEnabled)) |
                FLEXRAY_PCR10_wakeup_channel(convertBoolInt(peConfig->pWakeupChannel)) |
                FLEXRAY_PCR10_macro_per_cycle(peConfig->gMacroPerCycle);
    base->PCR11 = FLEXRAY_PCR11_key_slot_used_for_startup(convertBoolInt(peConfig->pKeySlotUsedForStartup)) |
                FLEXRAY_PCR11_key_slot_used_for_sync(convertBoolInt(peConfig->pKeySlotUsedForSync)) |
                FLEXRAY_PCR11_offset_correction_start(peConfig->gOffsetCorrectionStart);
    base->PCR12 = FLEXRAY_PCR12_allow_passive_to_active(peConfig->pAllowPassiveToActive) |
                FLEXRAY_PCR12_key_slot_header_crc(peConfig->keySlotHeaderCrc);
    base->PCR13 = FLEXRAY_PCR13_first_minislot_action_point_offset((peConfig->gdActionPointOffset > peConfig->gdMinislotActionPointOffset) ? ((uint16)(peConfig->gdActionPointOffset) - 1U) : ((uint16)(peConfig->gdMinislotActionPointOffset) - 1U)) |
                FLEXRAY_PCR13_static_slot_after_action_point(peConfig->gdStaticSlot - peConfig->gdActionPointOffset - 1U);
    base->PCR14 = FLEXRAY_PCR14_rate_correction_out(peConfig->pRateCorrectionOut) |
                FLEXRAY_PCR14_listen_timeout((peConfig->pdListenTimeout - 1U) >> 16U);
    base->PCR15 = FLEXRAY_PCR15_listen_timeout((peConfig->pdListenTimeout - 1U) & 0xFFFFU);
    base->PCR16 = FLEXRAY_PCR16_macro_initial_offset_b(peConfig->pMacroInitialOffsetB) |
                FLEXRAY_PCR16_noise_listen_timeout(((peConfig->gListenNoise * peConfig->pdListenTimeout) - 1U) >> 16U);
    base->PCR17 = FLEXRAY_PCR17_noise_listen_timeout(((peConfig->gListenNoise * peConfig->pdListenTimeout) - 1U) & 0xFFFFU);
    base->PCR18 = FLEXRAY_PCR18_wakeup_pattern(peConfig->pWakeupPattern) |
                FLEXRAY_PCR18_key_slot_id(peConfig->pKeySlotId);
    base->PCR19 = FLEXRAY_PCR19_decoding_correction_a(peConfig->pDecodingCorrection + peConfig->pDelayCompensationA + 2U) |
                FLEXRAY_PCR19_payload_length_static(peConfig->gPayloadLengthStatic);
    base->PCR20 = FLEXRAY_PCR20_micro_initial_offset_a(peConfig->pMicroInitialOffsetA) |
                FLEXRAY_PCR20_micro_initial_offset_b(peConfig->pMicroInitialOffsetB);
    base->PCR21 = /* FLEXRAY_PCR21_extern_rate_correction(peConfig->pExternRateCorrection) | */
                FLEXRAY_PCR21_latest_tx(peConfig->gNumberOfMinislots - peConfig->pLatestTx);
    base->PCR22 = FLEXRAY_PCR22_comp_accepted_startup_range_a(peConfig->pdAcceptedStartupRange - peConfig->pDelayCompensationA) |
                FLEXRAY_PCR22_micro_per_cycle(peConfig->pMicroPerCycle >> 16U);
    base->PCR23 = FLEXRAY_PCR23_micro_per_cycle(peConfig->pMicroPerCycle & 0xFFFFU);
    base->PCR24 = FLEXRAY_PCR24_cluster_drift_damping(peConfig->pClusterDriftDamping) |
                FLEXRAY_PCR24_max_payload_length_dynamic(peConfig->pPayloadLengthDynMax) |
                FLEXRAY_PCR24_micro_per_cycle_min((peConfig->pMicroPerCycle - peConfig->pdMaxDrift) >> 16U);
    base->PCR25 = FLEXRAY_PCR25_micro_per_cycle_min((peConfig->pMicroPerCycle - peConfig->pdMaxDrift) & 0xFFFFU);
    base->PCR26 = FLEXRAY_PCR26_allow_halt_due_to_clock(convertBoolInt(peConfig->pAllowHaltDueToClock)) |
                FLEXRAY_PCR26_comp_accepted_startup_range_b(peConfig->pdAcceptedStartupRange - peConfig->pDelayCompensationB) |
                FLEXRAY_PCR26_micro_per_cycle_max((peConfig->pMicroPerCycle + peConfig->pdMaxDrift) >> 16U);
    base->PCR27 = FLEXRAY_PCR27_micro_per_cycle_max((peConfig->pMicroPerCycle + peConfig->pdMaxDrift) & 0xFFFFU);
    base->PCR28 = FLEXRAY_PCR28_dynamic_slot_idle_phase(peConfig->gdDynamicSlotIdlePhase) |
                FLEXRAY_PCR28_macro_after_offset_correction(peConfig->gMacroPerCycle - peConfig->gOffsetCorrectionStart);
    base->PCR29 = FLEXRAY_PCR29_extern_offset_correction(peConfig->pExternOffsetCorrection) |
                FLEXRAY_PCR29_minislots_max(peConfig->gNumberOfMinislots - 1U);
    base->PCR30 = FLEXRAY_PCR30_sync_node_max(peConfig->gSyncNodeMax);
    base->NMVLR = FLEXRAY_NMVLR_NMVL(peConfig->gNetworkManagementVectorLength);

    /* new additions */
    if(0U != peConfig->SyncFrameTableOffset) /* IPL doesn't use these params, only write them if they are configured (by HL)*/
    {
        base->SFTOR = peConfig->SyncFrameTableOffset;
        base->SFTCCSR = FLEXRAY_SFTCCSR_SIDEN_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_SetFiFoRangeFilter
 * Description   : Configures the range filter for the rx fifo.
 *
 *END**************************************************************************/
void FLEXRAY_SetFiFoRangeFilter(FLEXRAY_Type* base,
                                                uint8 filterNum,
                                                const Flexray_Ip_RangeFilterType *filterCfg)
{
    uint16 regValue = 0U;
    uint8 rangeFilterMode;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(filterNum < 4U);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    /* Set Lower Value of range filter */
    rangeFilterMode = 0U;
    regValue = (uint16)(FLEXRAY_RFRFCFR_SEL(filterNum) | FLEXRAY_RFRFCFR_IBD(rangeFilterMode) | FLEXRAY_RFRFCFR_SID(filterCfg->rangeFilterLower));
    base->RFRFCFR = regValue;

    /* Set Upper Value of range filter */
    regValue = 0U;
    rangeFilterMode = 1U;
    regValue = (uint16)(FLEXRAY_RFRFCFR_SEL(filterNum) | FLEXRAY_RFRFCFR_IBD(rangeFilterMode) | FLEXRAY_RFRFCFR_SID(filterCfg->rangeFilterUpper));
    base->RFRFCFR = regValue;

    /* Set mode and enable range filter */
    regValue = base->RFRFCTR;
    regValue &= ~((uint16)(((uint16)1U << (filterNum + FLEXRAY_RFRFCTR_F0EN_SHIFT)) | ((uint16)1U << (filterNum + FLEXRAY_RFRFCTR_F0MD_SHIFT))));
    regValue |= ((uint16)(((uint16)(convertBoolInt(filterCfg->rangeFilterEnable)))<<(FLEXRAY_RFRFCTR_F0EN_SHIFT + filterNum)) |
                (uint16)(((uint16)(filterCfg->rangeFilterMode))<<(FLEXRAY_RFRFCTR_F0MD_SHIFT + filterNum)));
    base->RFRFCTR = regValue;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_ConfigureTimer1
 * Description   : Configures the timer 1
 *
 *END**************************************************************************/
void FLEXRAY_ConfigureTimer1(FLEXRAY_Type *base,
                                             const Flexray_Ip_TimerConfigType* timerCfg)
{
    if (timerCfg->isRepetitive)
    {
        base->TICCR |= (uint16)FLEXRAY_TICCR_T1_REP_MASK;
    }
    else
    {
        base->TICCR &= ~((uint16)FLEXRAY_TICCR_T1_REP_MASK);
    }
    base->TI1CYSR = FLEXRAY_TI1CYSR_T1_CYC_MSK(timerCfg->cycMask) | FLEXRAY_TI1CYSR_T1_CYC_VAL(timerCfg->cycVal);
    base->TI1MTOR = FLEXRAY_TI1MTOR_T1_MTOFFSET(timerCfg->macroTick);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_ConfigureTimer2
 * Description   : Configures the timer 2
 *
 *END**************************************************************************/
void FLEXRAY_ConfigureTimer2(FLEXRAY_Type *base,
                                             const Flexray_Ip_TimerConfigType* timerCfg)
{
    if ((base->TICCR & FLEXRAY_TICCR_T2_CFG_MASK) != 0U)
    {
        base->TI2CR0.REL = (uint16)((timerCfg->macroTick >> 16U) & 0xFFFFU);
        base->TI2CR1.REL = (uint16)((timerCfg->macroTick) & 0xFFFFU);
    }
    else
    {
        base->TI2CR0.ABS = FLEXRAY_ABS_T2CYCVAL(timerCfg->cycVal) | FLEXRAY_ABS_T2CYCMSK(timerCfg->cycMask);
        base->TI2CR1.ABS = FLEXRAY_ABS_T2MOFF(timerCfg->macroTick);
    }
    if (timerCfg->isRepetitive)
    {
        base->TICCR |= (uint16)FLEXRAY_TICCR_T2_REP_MASK;
    }
    else
    {
        base->TICCR &= ~(uint16)(FLEXRAY_TICCR_T2_REP_MASK);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_PackMessageBufferHeader
 * Description   : Pack all fields of header into a header data array with 8 bytes.
 *
 *END**************************************************************************/
void Flexray_PackMessageBufferHeader(Flexray_Ip_HeaderDataType * pHeaderData,
                                                     Flexray_Ip_FrameHeaderType* pFrameHdr)
{

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(pHeaderData != NULL_PTR);
    DevAssert(pFrameHdr != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    Flexray_calCrc(pFrameHdr->payloadLength, pFrameHdr->frameID, FALSE, FALSE, &(pFrameHdr->headerCrc));
    /* Update PPI, FrameID, payload length, header CRC for transfer buffer header frame */
    (*pHeaderData)[1] = (pFrameHdr->payloadPreambleIndicator ? 0x40U : 0x0U) | ((uint8)(pFrameHdr->frameID >> 8U));
    (*pHeaderData)[0] = (uint8) pFrameHdr->frameID;
    (*pHeaderData)[2] = (uint8) pFrameHdr->payloadLength;
    (*pHeaderData)[5] = (uint8)(pFrameHdr->headerCrc >> 8U);
    (*pHeaderData)[4] = (uint8)(pFrameHdr->headerCrc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_UnpackMessageBufferHeader
 * Description   : Unpack a header data array to each element of Flexray_Ip_FrameHeaderType
 * structure.
 *
 *END**************************************************************************/
void Flexray_UnpackMessageBufferHeader (Flexray_Ip_HeaderDataType * pHeaderData,
                                                        Flexray_Ip_FrameHeaderType* pFrameHdr)
{

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(pHeaderData != NULL_PTR);
    DevAssert(pFrameHdr != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    pFrameHdr->slotStatus = ((uint16)((*pHeaderData)[7]) << 8U) | (uint16)((*pHeaderData)[6]);
    pFrameHdr->headerCrc = ((uint16)(*pHeaderData)[5] << 8U) | (uint16)(*pHeaderData)[4];
    pFrameHdr->cycleCount = (*pHeaderData)[3];

    /* Sanitize the payload data size. */
    if (FLEXRAY_MAXIMUM_PAYLOAD_LENGTH < (uint8)(*pHeaderData)[2])
    {
        pFrameHdr->payloadLength = FLEXRAY_MAXIMUM_PAYLOAD_LENGTH;
    } else {
        pFrameHdr->payloadLength = (uint8)(*pHeaderData)[2];
    }

    pFrameHdr->frameID = (((uint16)(*pHeaderData)[1] & 0x7U) << 8U) | (uint16)(*pHeaderData)[0];
    pFrameHdr->reservedBit = ((*pHeaderData)[1] & 0x80U) != 0U;
    pFrameHdr->payloadPreambleIndicator = ((*pHeaderData)[1] & 0x40U) != 0U;
    pFrameHdr->reservedBit = ((*pHeaderData)[1] & 0x40U) != 0U;
    pFrameHdr->nullFrameIndicator = ((*pHeaderData)[1] & 0x20U) != 0U;
    pFrameHdr->syncFrameIndicator = ((*pHeaderData)[1] & 0x10U) != 0U;
    pFrameHdr->startupFrameIndicator = ((*pHeaderData)[1] & 0x08U) != 0U;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_calCrc
 * Description   : Computes the CRC11 of a frame header.
 *
 *END**************************************************************************/
void Flexray_calCrc(uint8 payloadLength,
                                    uint16 frameID,
                                    boolean startupFrameIndicator,
                                    boolean syncFrameIndicator,
                                    uint16* headerCrc)
{
    uint16 macCrc = 0x1A;
    uint16 macCRCnextbit;
    uint8 i;
    uint32 dataWord = payloadLength;

    dataWord |= (uint32)((uint32)frameID << 7U);
    dataWord |= (((uint32)convertBoolInt(startupFrameIndicator)) << 18U);
    dataWord |= (((uint32)convertBoolInt(syncFrameIndicator)) << 19U);
    dataWord = dataWord << 1U;
    for(i = 20U; i > 0U; i--)
    {
        macCRCnextbit = (uint16)((dataWord >> i) & 1U);
        macCRCnextbit = (macCRCnextbit ^ ((macCrc >> 10U) & 1U));
        macCrc = macCrc << 1U;
        macCrc = macCrc & 0xFFFFU;
        if (macCRCnextbit != 0U)
        {
            macCrc= macCrc ^ 0x385U;
        }
    }
    *headerCrc = macCrc & 0x7FFU;
}

/*!
 * @brief Check freeze
 *
 * @param[in]   base           The Flexray base address
 *
 * @return (boolean)TRUE: if occur freeze/(boolean)FALSE: if not occur freeze
 */

boolean Flexray_OccurFreeze(const FLEXRAY_Type* inst)
{
    return (((inst->PSR1 & FLEXRAY_PSR1_FRZ_MASK) >> FLEXRAY_PSR1_FRZ_SHIFT) != 0U);
}

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


#ifdef __cplusplus
}
#endif
/* End of file */
