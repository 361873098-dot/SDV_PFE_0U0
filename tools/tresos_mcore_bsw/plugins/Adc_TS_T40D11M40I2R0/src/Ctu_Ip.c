/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   @addtogroup ctu_ip
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
#include "Ctu_Ip.h"
#include "Ctu_Ip_Irq.h"
#include "Ctu_Ip_TrustedFunctions.h"
#include "OsIf.h"
#include "Reg_eSys.h"
#include "SchM_Adc.h"

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

#if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
    /* USER_MODE_REG_PROT_ENABLED is defined for Base sanity check in RegLockMacros.h */
    #define USER_MODE_REG_PROT_ENABLED      (CTU_IP_ENABLE_USER_MODE_SUPPORT)
    #include "RegLockMacros.h"
#endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTU_IP_VENDOR_ID_C                      43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define CTU_IP_AR_RELEASE_MINOR_VERSION_C       4
#define CTU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define CTU_IP_SW_MAJOR_VERSION_C               4
#define CTU_IP_SW_MINOR_VERSION_C               0
#define CTU_IP_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ctu_Ip.c file and Ctu_Ip.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_C != CTU_IP_VENDOR_ID)
    #error "Ctu_Ip.c and Ctu_Ip.h have different vendor ids"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != CTU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != CTU_IP_AR_RELEASE_MINOR_VERSION) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_C != CTU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and Ctu_Ip.h are different"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_C != CTU_IP_SW_MAJOR_VERSION) || \
     (CTU_IP_SW_MINOR_VERSION_C != CTU_IP_SW_MINOR_VERSION) || \
     (CTU_IP_SW_PATCH_VERSION_C != CTU_IP_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Ctu_Ip.c and Ctu_Ip.h are different"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip_Irq.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_C != CTU_IP_VENDOR_ID_IRQ)
    #error "Ctu_Ip.c and Ctu_Ip_Irq.h have different vendor ids"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip_Irq.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_C != CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and Ctu_Ip_Irq.h are different"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip_Irq.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_C != CTU_IP_SW_MAJOR_VERSION_IRQ) || \
     (CTU_IP_SW_MINOR_VERSION_C != CTU_IP_SW_MINOR_VERSION_IRQ) || \
     (CTU_IP_SW_PATCH_VERSION_C != CTU_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Ctu_Ip.c and Ctu_Ip_Irq.h are different"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip_TrustedFunctions.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_C != CTU_IP_VENDOR_ID_TRUSTEDFUNCTIONS)
    #error "Ctu_Ip.c and Ctu_Ip_TrustedFunctions.h have different vendor ids"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != CTU_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != CTU_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_C != CTU_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and Ctu_Ip_TrustedFunctions.h are different"
#endif

/* Check if Ctu_Ip.c file and Ctu_Ip_TrustedFunctions.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_C != CTU_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (CTU_IP_SW_MINOR_VERSION_C != CTU_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (CTU_IP_SW_PATCH_VERSION_C != CTU_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS) \
    )
  #error "Software Version Numbers of Ctu_Ip.c and Ctu_Ip_TrustedFunctions.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ctu_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and OsIf.h are different"
#endif

/* Check if Ctu_Ip.c file and Reg_eSys.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and Reg_eSys.h are different"
#endif

#if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
    /* Checks against RegLockMacros.h */
    #if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
            (CTU_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Ctu_Ip.c and RegLockMacros.h are different"
    #endif
#endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */

/* Check if Ctu_Ip.c file and SchM_Adc.h file are of the same version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and SchM_Adc.h are different"
#endif

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
 /* Check if Ctu_Ip.c file and Devassert.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.c and Devassert.h are different"
#endif
#endif /* CTU_IP_DEV_ERROR_DETECT */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                      PRE-CHECK
==================================================================================================*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running CTU in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/

/*==================================================================================================
                                     LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

static uint32 Ctu_SelectInput(const Ctu_Ip_InputTrigType InputTrig,
                              const Ctu_Ip_InputEdgeType InputEdge);
static void Ctu_ConfigSingleCmd(const uint32 Instance,
                                const uint32 Pos,
                                const Ctu_Ip_AdcCmdType * const AdcCmd,
                                const uint32 LcFlagValue);
static inline uint32 Ctu_CorrectCLRposition(const uint32 Pos);
static inline void Ctu_ConfigOutputDisable(CTU_Type * const CtuBasePtr,
                                           boolean Enable);
static inline void Ctu_ConfigDigitalFilter(CTU_Type * const CtuBasePtr,
                                           uint8 DigitalFilter);
static inline void Ctu_ConfigListMode(CTU_Type * const CtuBasePtr,
                                      Ctu_Ip_AdcCmdListModeType Mode);
static inline void Ctu_GetDefaultConfig(Ctu_Ip_ConfigType * const Config);
static uint32 Ctu_GetFifoStatusFlags(const uint32 Instance,
                                     const uint32 FifoIdx);
static inline Ctu_Ip_StatusType Ctu_ResetFifo(const uint32 Instance);
static inline Ctu_Ip_StatusType Ctu_ReloadDoubleBuffer(const uint32 Instance,
                                                       Ctu_Ip_TGSModeType TgsMode);
static inline void Ctu_ConfigTrigGenSubunit(CTU_Type * const CtuBasePtr,
                                            const Ctu_Ip_TrigGenSubType * TgscrCfg);
static inline void Ctu_ConfigMultiAdcSubLists(const uint32 Instance,
                                              const Ctu_Ip_AdcCmdConfigType * const AdcCmdArray,
                                              const uint8 NumCmds);
static inline void Ctu_ConfigAndUpdateFifoNotification(const uint32 Instance,
                                                       const Ctu_Ip_FifoConfigType * const FifoConfigArray,
                                                       const uint8 NumFifoConfigs);
static inline void Ctu_CheckAndCallNotification(void (*Callback)(void));
static inline void Ctu_CheckAndCallFifoNotification(CTU_Type * const CtuBasePtr,
                                                    uint8 FifoIdx,
                                                    uint32 Flag,
                                                    void (*Callback)(void));
static inline void Ctu_CheckAndCallTrigNotification(const uint32 Instance,
                                                    CTU_Type * const CtuBasePtr,
                                                    uint8 TrigIdx);
#ifdef CTU_IP_DMA_SUPPORTED
static inline void Ctu_FifoSetupDma(const Ctu_Ip_FifoConfigType * const FifoConfig);
#endif /* CTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*==================================================================================================
                                     GLOBAL VARIABLES
==================================================================================================*/
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/* Table of Base addresses for CTU instances. */
static CTU_Type * const Ctu_Ip_apxCtuBase[CTU_INSTANCE_COUNT] = IP_CTU_BASE_PTRS;

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

/* Global state structure */
static Ctu_Ip_StateStructType Ctu_Ip_axCtuState[CTU_INSTANCE_COUNT];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"
#ifdef CTU_IP_DMA_SUPPORTED
static uint32 Ctu_Ip_au32CtuFifoDmaChannel[CTU_IP_FIFO_COUNT];
#endif /* CTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"

/*==================================================================================================
                                     FUNCTION DEFINITIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_Init
* Description   : This function configures the global functionalities of a CTU instance.
*
* @implements      Ctu_Ip_Init_Activity
* END**************************************************************************/
Ctu_Ip_StatusType Ctu_Ip_Init(const uint32 u32Instance,
                              const Ctu_Ip_ConfigType * const pConfig)
{
    Ctu_Ip_StatusType Status = CTU_IP_STATUS_SUCCESS;
    Ctu_Ip_TrigGenSubType TgscrCfg;
    uint16 Ir = 0u;
    uint8 Index = 0u;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(pConfig != NULL_PTR);
    DevAssert(pConfig->SeqModeMrsInputEdge < CTU_IP_INPUT_EDGE_BOTH); /* A single edge can be selected for MRS input */
    DevAssert(pConfig->NumTrigConfigs <= FEATURE_CTU_NUM_TRG);
    DevAssert(pConfig->NumAdcCmdConfigs <= CTU_CLR_COUNT);
    DevAssert(pConfig->NumFifoConfigs <= CTU_IP_FIFO_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

#if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
    /* Set the UAA bit in REG_PROT to make the instance accessible in user mode */
    OsIf_Trusted_Call1param(Ctu_Ip_SetUserAccessAllowed, CtuBasePtr);
#endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */

    Ir |= (pConfig->MrsNotification != NULL_PTR) ? (uint16)CTU_IR_MRS_IE_MASK : (0u);
    Ir |= (pConfig->ErrNotification != NULL_PTR) ? (uint16)CTU_IR_IEE_MASK : (0u);
    Ir |= (TRUE == pConfig->DmaDoneGRE) ? (uint16)CTU_IR_DMA_DE_MASK : (0u);
    Ir |= (TRUE == pConfig->DmaReqMRS) ? (uint16)CTU_IR_MRS_DMAE_MASK : (0u);
    CtuBasePtr->IR = Ir;

    /* Configure trigger generator subunit control */
    TgscrCfg.TgsMode = pConfig->TgsMode;
    TgscrCfg.Prescaler = pConfig->Prescaler;
    TgscrCfg.SeqModeMrsInput = pConfig->SeqModeMrsInput;
    TgscrCfg.SeqModeMrsInputEdge = pConfig->SeqModeMrsInputEdge;
#if FEATURE_CTU_EXT_TRIG_PRESENT
    TgscrCfg.ExtTrigMode = pConfig->ExtTrigMode;
#endif /* FEATURE_CTU_EXT_TRIG_PRESENT */
    Ctu_ConfigTrigGenSubunit(CtuBasePtr, &TgscrCfg);

    CtuBasePtr->TGSCCR = CTU_TGSCCR_TGSCCV(pConfig->TgsCounterCompareVal);
    CtuBasePtr->TGSCRR = CTU_TGSCRR_TGSCRV(pConfig->TgsCounterReloadVal);

    CtuBasePtr->TGSISR = pConfig->InputTrigSelectMask;

    /* Load the new value for TGSISR (double buffered reg) */
    Status = Ctu_Ip_SyncInputSelect(u32Instance);
    if (CTU_IP_STATUS_SUCCESS == Status)
    {
        /* Selects the parallel/streamming mode for the list execution */
        Ctu_ConfigListMode(CtuBasePtr, pConfig->AdcCmdListMode);
        /* Configure CTU output disable */
        Ctu_ConfigOutputDisable(CtuBasePtr, pConfig->DisableOutput);
        /* Set digital filter value */
        Ctu_ConfigDigitalFilter(CtuBasePtr, pConfig->DigitalFilter);

        /* Set expected conversion range and duration */
        CtuBasePtr->EXPAR = CTU_EXPAR_EXPA(pConfig->ConvDurationExpectedVal[CTU_IP_ADC_PORT_A]);
#if (FEATURE_CTU_NUM_ADC > 1)
        CtuBasePtr->EXPBR = CTU_EXPBR_EXPB(pConfig->ConvDurationExpectedVal[CTU_IP_ADC_PORT_B]);
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
        CtuBasePtr->CNTRNGR = CTU_CNTRNGR_CNTRNG(pConfig->ConvDurationCounterRange);

        /* Set Control On-Time and Guard Time value */
        CtuBasePtr->COTR = (((uint16)pConfig->ControlOnTime << CTU_COTR_COTGT_SHIFT) & CTU_COTR_COTGT_MASK);

        /* Configure triggers */
        if (pConfig->TrigConfigs != NULL_PTR)
        {
            for (Index = 0; Index < pConfig->NumTrigConfigs; Index++)
            {
                const Ctu_Ip_TrigConfigType * const pTrigConfig = &(pConfig->TrigConfigs[Index]);
                Ctu_Ip_SetTriggerCompare(u32Instance, (uint32) pTrigConfig->TrigIndex, pTrigConfig->CompareVal);
                Ctu_Ip_SetTriggerAdcCmdAddress(u32Instance, (uint32) pTrigConfig->TrigIndex, (uint8) pTrigConfig->CmdListStartAdr);
                Ctu_Ip_WriteTriggerEnableMask(u32Instance, (uint32) pTrigConfig->TrigIndex, (uint8) pTrigConfig->OutputTrigEnMask);

                Ctu_Ip_axCtuState[u32Instance].TrigNotifications[pTrigConfig->TrigIndex] = pTrigConfig->TrigNotification;
            }
        }

        /* Configure ADC commands */
        if (pConfig->AdcCmdConfigs != NULL_PTR)
        {
            Ctu_ConfigMultiAdcSubLists(u32Instance, pConfig->AdcCmdConfigs, pConfig->NumAdcCmdConfigs);
        }

        /* Configure FIFOs */
        if (pConfig->FifoConfigs != NULL_PTR)
        {
            Ctu_ConfigAndUpdateFifoNotification(u32Instance, pConfig->FifoConfigs, pConfig->NumFifoConfigs);
        }

        /* Add remaining callbacks in the state structure */
        Ctu_Ip_axCtuState[u32Instance].MrsNotification = pConfig->MrsNotification;
        Ctu_Ip_axCtuState[u32Instance].AdcCommandIssueNotification = pConfig->AdcCommandIssueNotification;
        for (Index = 0u; Index < FEATURE_CTU_NUM_ADC; Index++)
        {
            Ctu_Ip_axCtuState[u32Instance].ConvDurationExceedNotification[Index] = pConfig->ConvDurationExceedNotification[Index];
        }

        /* Mark that the driver was initialized */
        Ctu_Ip_axCtuState[u32Instance].InitStatus = TRUE;
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_Deinit
* Description   : This function resets all registers of a CTU instance to default values.
* It stops and resets any running ADC command list.
* Note: the function also enables the CTU output (default state).
*
* @implements      Ctu_Ip_Deinit_Activity
* END**************************************************************************/
Ctu_Ip_StatusType Ctu_Ip_Deinit(const uint32 u32Instance)
{
    Ctu_Ip_StatusType Status = CTU_IP_STATUS_SUCCESS;
    Ctu_Ip_TGSModeType TgsModeBeforeReset = CTU_IP_TGS_MODE_TRIGGERED;
    Ctu_Ip_ConfigType Config;
    uint8 Index;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    /* Clear GRE bit to ensure the double buffered registers could be written */
    Status = Ctu_Ip_SetGeneralReloadEnable(u32Instance, FALSE);

    if (CTU_IP_STATUS_SUCCESS == Status)
    {
        /* Save TGS Mode state */
        if ((CtuBasePtr->TGSCR & CTU_TGSCR_TGS_M_MASK) != 0u)
        {
            TgsModeBeforeReset = CTU_IP_TGS_MODE_SEQUENTIAL;
        }

        /* Disable all input triggers */
        CtuBasePtr->TGSISR = 0u;
        /* Load the new value for TGSISR (double buffered reg) */
        Status = Ctu_Ip_SyncInputSelect(u32Instance);
        if (CTU_IP_STATUS_SUCCESS == Status)
        {
            Ctu_Ip_DisableOutput(u32Instance);

            /* Reset running ADC command list */
            CtuBasePtr->CR |= CTU_CR_CTU_ADC_R_MASK;

            /* Reset general configurations to default */
            Ctu_GetDefaultConfig(&Config);

            Status = Ctu_Ip_Init(u32Instance, &Config);
            if (CTU_IP_STATUS_SUCCESS == Status)
            {
                /* Reset internal trigger properties */
#if FEATURE_CTU_HAS_TCR_UNROLLED
                CtuBasePtr->T0CR = 0u;
                CtuBasePtr->T1CR = 0u;
                CtuBasePtr->T2CR = 0u;
                CtuBasePtr->T3CR = 0u;
                CtuBasePtr->T4CR = 0u;
                CtuBasePtr->T5CR = 0u;
                CtuBasePtr->T6CR = 0u;
                CtuBasePtr->T7CR = 0u;
#else
                for (Index = 0; Index < CTU_TCR_COUNT; Index++)
                {
                    CtuBasePtr->TCR[Index] = 0u;
                }
#endif /* FEATURE_CTU_HAS_TCR_UNROLLED */

                CtuBasePtr->CLCR1 = 0u;
                CtuBasePtr->CLCR2 = 0u;
                CtuBasePtr->THCR1 = 0u;
                CtuBasePtr->THCR2 = 0u;

                /* Reset command list registers */
                for (Index = 0; Index < CTU_CLR_COUNT; Index++)
                {
                    CtuBasePtr->CLR.A[Index] = 0u;
                    CtuBasePtr->CLR.B[Index] = 0u;
                }

                /* Reset FIFOs */
                Status = Ctu_ResetFifo(u32Instance);
                if (CTU_IP_STATUS_SUCCESS == Status)
                {
                    /* Threshold is only reset to 0 if FIFO doesn't have any remaining results
                    otherwise get in a forever interrupt loop because CtuControlOngoing = FALSE and no more result is read from user notification */
                    CtuBasePtr->FTH  = 0u;

                    /* Clear error flags */
                    Ctu_Ip_ClearErrorFlags(u32Instance, CTU_IP_ERROR_FLAG_ALL);

                    /* Load the reset values to the double bufferred registers */
                    Status = Ctu_ReloadDoubleBuffer(u32Instance, TgsModeBeforeReset);
                    if (CTU_IP_STATUS_SUCCESS == Status)
                    {
                        /* Reset the rest of registers to default */
                        CtuBasePtr->IR      = 0u;
                        CtuBasePtr->COTR    = 0u;
                        CtuBasePtr->DFR     = 0u;
                        CtuBasePtr->EXPAR   = CTU_EXPAR_EXPA_MASK;
#if (FEATURE_CTU_NUM_ADC > 1)
                        CtuBasePtr->EXPBR   = CTU_EXPBR_EXPB_MASK;
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
                        CtuBasePtr->CNTRNGR = 0u;
                        CtuBasePtr->LISTCSR = 0u;
                        CtuBasePtr->CR      = 0u; /* Reset also CR.CTU_ODIS to enable the output */
                        CtuBasePtr->TGSCR   = 0u;
                        CtuBasePtr->TGSCCR  = 0u;
                        CtuBasePtr->TGSCRR  = 0u;

#if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
                        /* Clear the UAA bit in REG_PROT to reset the elevation requirement */
                        OsIf_Trusted_Call1param(Ctu_Ip_ClrUserAccessAllowed, CtuBasePtr);
#endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */
                        /* Mark that the driver was deinitialized */
                        Ctu_Ip_axCtuState[u32Instance].InitStatus = FALSE;
                    }
                }
            }
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SetInputSelect
* Description   : This function enables the selected signal edge(s) for a CTU input trigger.
* The affected register is double-buffered, so the new value will take effect only
* after MRS occurs or Ctu_Ip_SyncInputSelect() is called.
* Please note that the set operation is cumulative, e.g. set falling edge, then set rising edge
* for same input trigger, results in both edges being enabled for that trigger.
*
* @implements      Ctu_Ip_SetInputSelect_Activity
* END**************************************************************************/
void Ctu_Ip_SetInputSelect(const uint32 u32Instance,
                           const Ctu_Ip_InputTrigType pInputTrig,
                           const Ctu_Ip_InputEdgeType pInputEdge)
{
    uint32 TgsisrMask;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    TgsisrMask = Ctu_SelectInput(pInputTrig, pInputEdge);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_59();
    CtuBasePtr->TGSISR |= TgsisrMask;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_59();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_ClearInputSelect
* Description   : This function disables the selected signal edge(s) for a CTU input trigger.
* The affected register is double-buffered, so the new value will take effect only
* after MRS occurs or Ctu_Ip_SyncInputSelect() is called.
*
* @implements      Ctu_Ip_ClearInputSelect_Activity
* END**************************************************************************/
void Ctu_Ip_ClearInputSelect(const uint32 u32Instance,
                             const Ctu_Ip_InputTrigType pInputTrig,
                             const Ctu_Ip_InputEdgeType pInputEdge)
{
    uint32 TgsisrMask;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    TgsisrMask = Ctu_SelectInput(pInputTrig, pInputEdge);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_60();
    CtuBasePtr->TGSISR &= ~TgsisrMask;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_60();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SyncInputSelect
* Description   : This function loads the new value of input trigger select - TGSISR (double buffered register).
* The function waits until the TGSISR register is updated from the corresponding buffer register.
*
* @implements      Ctu_Ip_SyncInputSelect_Activity
* END**************************************************************************/
Ctu_Ip_StatusType Ctu_Ip_SyncInputSelect(const uint32 u32Instance)
{
    Ctu_Ip_StatusType Status = CTU_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(CTU_IP_TIMEOUT_VAL, CTU_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(CTU_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_54();
    CtuBasePtr->CR |= CTU_CR_TGSISR_RE_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_54();

    /* Wait until the TGSISR is updated from the corresponding buffer register (according to double-buffering mechanism).
     * TGSISR_RE is self negated - once set, remains set until TGSISR update is complete. */
    while (((CtuBasePtr->CR & CTU_CR_TGSISR_RE_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, CTU_IP_TIMEOUT_TYPE);
    }
    if (ElapsedTicks >= TimeoutTicks)
    {
        Status = CTU_IP_STATUS_TIMEOUT;
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SetTriggerCompare
* Description   : This function configures the compare value of a single internal trigger. \n
*
* Note: the ADC command registers are double buffered,
*  so configured values are loaded and take effect only after MRS occurs. \n
*  The function doesn't take into account the reload mechanism (refer to device reference manual for details),
*  so it needs to be handled externally - may use Ctu_Ip_SetGeneralReloadEnable().
*
* @implements      Ctu_Ip_SetTriggerCompare_Activity
* END**************************************************************************/
void Ctu_Ip_SetTriggerCompare(const uint32 u32Instance,
                              const uint32 u32TrigIdx,
                              const uint16 u16CmpVal)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32TrigIdx < CTU_TCR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

#if FEATURE_CTU_HAS_TCR_UNROLLED
    switch (u32TrigIdx)
    {
        case 0:
            CtuBasePtr->T0CR = u16CmpVal;
            break;
        case 1:
            CtuBasePtr->T1CR = u16CmpVal;
            break;
        case 2:
            CtuBasePtr->T2CR = u16CmpVal;
            break;
        case 3:
            CtuBasePtr->T3CR = u16CmpVal;
            break;
        case 4:
            CtuBasePtr->T4CR = u16CmpVal;
            break;
        case 5:
            CtuBasePtr->T5CR = u16CmpVal;
            break;
        case 6:
            CtuBasePtr->T6CR = u16CmpVal;
            break;
        case 7:
            CtuBasePtr->T7CR = u16CmpVal;
            break;

        default:
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }
#else
    CtuBasePtr->TCR[u32TrigIdx] = u16CmpVal;
#endif /* FEATURE_CTU_HAS_TCR_UNROLLED */
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SetTriggerAdcCmdAddress
* Description   : This function configures the first address of the command list associated with an internal trigger. \n
*
* Note: the ADC command registers are double buffered,
*  so configured values are loaded and take effect only after MRS occurs. \n
*  The function doesn't take into account the reload mechanism (refer to device reference manual for details),
*  so it needs to be handled externally - may use Ctu_Ip_SetGeneralReloadEnable().
*
* @implements      Ctu_Ip_SetTriggerAdcCmdAddress_Activity
* END**************************************************************************/
void Ctu_Ip_SetTriggerAdcCmdAddress(const uint32 u32Instance,
                                    const uint32 u32TrigIdx,
                                    const uint8 u8AdcCmdAddress)
{
    uint32 Shift;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32TrigIdx < CTU_TCR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    if (u32TrigIdx < 4u) /* CLCR1 store info for internal triggers: #0 -> #3 */
    {
        Shift = u32TrigIdx * CTU_CLCR1_T1_INDEX_SHIFT;

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_61();
        /* Clear bits corresponding to Tn_INDEX bitfield - where 'n' is u32TrigIdx */
        CtuBasePtr->CLCR1 &= ~((uint32)CTU_CLCR1_T0_INDEX_MASK << Shift);
        /* Write new value */
        CtuBasePtr->CLCR1 |= CTU_CLCR1_T0_INDEX(u8AdcCmdAddress) << Shift;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_61();
    }
    else /* CLCR2 store info for internal triggers: #3 -> #7 */
    {
        Shift = (u32TrigIdx - 4u) * CTU_CLCR2_T5_INDEX_SHIFT;

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_61();
        /* Clear bits corresponding to Tn_INDEX bitfield - where 'n' is u32TrigIdx */
        CtuBasePtr->CLCR2 &= ~((uint32)CTU_CLCR2_T4_INDEX_MASK << Shift);
        /* Write new value */
        CtuBasePtr->CLCR2 |= CTU_CLCR2_T4_INDEX(u8AdcCmdAddress) << Shift;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_61();
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_WriteTriggerEnableMask
* Description   : This function configures which CTU output triggers are enabled for a single internal trigger. \n
*
* Note: the ADC command registers are double buffered,
*  so configured values are loaded and take effect only after MRS occurs. \n
*  The function doesn't take into account the reload mechanism (refer to device reference manual for details),
*  so it needs to be handled externally - may use Ctu_Ip_SetGeneralReloadEnable().
*
* @implements      Ctu_Ip_WriteTriggerEnableMask_Activity
* END**************************************************************************/
void Ctu_Ip_WriteTriggerEnableMask(const uint32 u32Instance,
                                   const uint32 u32TrigIdx,
                                   const uint8 u8TriggerEnableMask)
{
    uint32 Shift;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32TrigIdx < CTU_TCR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    Shift = ((u32TrigIdx % 4u) * 8u);
    if (u32TrigIdx < 4u) /* THCR1 store info for internal triggers: #0 -> #3 */
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_62();
        /* Clear bits corresponding to Tn bitfields - where 'n' is u32TrigIdx */
        CtuBasePtr->THCR1 &= ~(CTU_IP_OUTPUT_TRIG_ALL_EN << Shift);
        /* Write new value */
        CtuBasePtr->THCR1 |= ((uint32)u8TriggerEnableMask & CTU_IP_OUTPUT_TRIG_ALL_EN) << Shift;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_62();
    }
    else /* THCR2 store info for internal triggers: #3 -> #7 */
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_62();
        /* Clear bits corresponding to Tn bitfields - where 'n' is u32TrigIdx */
        CtuBasePtr->THCR2 &= ~(CTU_IP_OUTPUT_TRIG_ALL_EN << Shift);
        /* Write new value */
        CtuBasePtr->THCR2 |= ((uint32)u8TriggerEnableMask & CTU_IP_OUTPUT_TRIG_ALL_EN) << Shift;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_62();
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SetTriggerEnable
* Description   : This function sets the enable bit Tx_E of THCRx register for
* a single internal trigger. \n
*
* By internal trigger, the CTU driver refers to the output triggers from TGS (Trigger Generator Subunit),
* fed as input triggers to the SU (Scheduler Subunit). \n
*
* @implements      Ctu_Ip_SetTriggerEnable_Activity
* END**************************************************************************/
void Ctu_Ip_SetTriggerEnable(const uint32 u32Instance,
                             const uint32 u32TrigIdx,
                             const boolean bEnable)
{
    uint32 Shift;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32TrigIdx < CTU_TCR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    Shift = ((u32TrigIdx % 4u) * 8u);
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_63();
    if (u32TrigIdx < 4u) /* THCR1 store info for internal triggers: #0 -> #3 */
    {
        if (TRUE == bEnable)
        {
            CtuBasePtr->THCR1 |= (CTU_IP_OUTPUT_TRIG_EN << Shift);
        }
        else
        {
            CtuBasePtr->THCR1 &= ~(CTU_IP_OUTPUT_TRIG_EN << Shift);
        }
    }
    else /* THCR2 store info for internal triggers: #3 -> #7 */
    {
        if (TRUE == bEnable)
        {
            CtuBasePtr->THCR2 |= (CTU_IP_OUTPUT_TRIG_EN << Shift);
        }
        else
        {
            CtuBasePtr->THCR2 &= ~(CTU_IP_OUTPUT_TRIG_EN << Shift);
        }
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_63();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_ConfigAdcCmdList
* Description   : This function configures an array of ADC commands and marks accordingly the last command. \n
*
* Note: the ADC command registers are double buffered,
*  so configured values are loaded and take effect only after MRS occurs. \n
*  The function doesn't take into account the reload mechanism (refer to device reference manual for details),
*  so it needs to be handled externally - may use Ctu_Ip_SetGeneralReloadEnable().
*  Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
*
* @implements      Ctu_Ip_ConfigAdcCmdList_Activity
* END**************************************************************************/
void Ctu_Ip_ConfigAdcCmdList(const uint32 u32Instance,
                             const uint32 u32StartCmdListAdr,
                             const Ctu_Ip_AdcCmdType * const pAdcCmdArray,
                             const uint8 u8NumCmds)
{
    uint32 Idx;
    uint32 LcFlagFirstCmd;
    uint32 Pos;
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    uint32 Iter;

    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32StartCmdListAdr < CTU_CLR_COUNT);
    DevAssert(pAdcCmdArray != NULL_PTR);
    DevAssert(u8NumCmds <= CTU_CLR_COUNT);
    DevAssert(u8NumCmds != 0u);
    for (Iter = 0u; Iter < u8NumCmds; Iter++)
    {
        if ((pAdcCmdArray[Iter].AdcChanA > (((uint8)1U << (CTU_B_CH_A_WIDTH)) - 1U))
#if (FEATURE_CTU_NUM_ADC > 1)
         || (pAdcCmdArray[Iter].AdcChanB > (((uint8)1U << (CTU_B_CH_B_WIDTH)) - 1U))
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
           )
        {
            DevAssert(FALSE);
            break;
        }
    }
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    Pos = u32StartCmdListAdr;

    /* Preserve value of LastCommand (LC) flag corresponding to the first command in the list,
     * because LC bit is ignored in the first command of a list. */
    LcFlagFirstCmd = ((uint32)CtuBasePtr->CLR.A[Ctu_CorrectCLRposition(Pos)] & CTU_A_LC_MASK) >> CTU_A_LC_SHIFT;
    Ctu_ConfigSingleCmd(u32Instance, Ctu_CorrectCLRposition(Pos), &(pAdcCmdArray[0u]), LcFlagFirstCmd);

    for (Idx = 1u; Idx < u8NumCmds; Idx++)
    {
        Pos = (u32StartCmdListAdr + Idx) % CTU_CLR_COUNT;
        Ctu_ConfigSingleCmd(u32Instance, Ctu_CorrectCLRposition(Pos), &(pAdcCmdArray[Idx]), 0u);
    }

    /* Mark the last command in the list.
     * The last command (n) is defined by the LC bit of the next command (n+1) in the list.
     * Note that the command with LC=1 does not belong to the list and thus it is not executed.
     * Note also that the LC bit is ignored in the first command of a list. */
    Pos = (Pos + 1u) % CTU_CLR_COUNT;
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_68();
    CtuBasePtr->CLR.A[Ctu_CorrectCLRposition(Pos)] |= CTU_A_LC_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_68();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_ConfigMultiAdcSubLists
* Description   : This function configures an array of ADC commands that might contains multiple sub lists
*
* Note: the ADC command registers are double buffered,
*  so configured values are loaded and take effect only after MRS occurs. \n
*  The function doesn't take into account the reload mechanism (refer to device reference manual for details),
*  so it needs to be handled externally - may use Ctu_Ip_SetGeneralReloadEnable().
*
* END**************************************************************************/
static inline void Ctu_ConfigMultiAdcSubLists(const uint32 Instance,
                                              const Ctu_Ip_AdcCmdConfigType * const AdcCmdArray,
                                              const uint8 NumCmds)
{
    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];
    uint32 Idx = 0u;
    boolean LastCmdPrev = FALSE;
    Ctu_Ip_AdcCmdType AdcCmdTemp;

    for (Idx = 0u; Idx < NumCmds; Idx++)
    {
        AdcCmdTemp.IntEn      = AdcCmdArray[Idx].IntEn;
        AdcCmdTemp.FifoIdx   = AdcCmdArray[Idx].FifoIdx;
        AdcCmdTemp.ConvMode   = AdcCmdArray[Idx].ConvMode;
        AdcCmdTemp.AdcPort    = AdcCmdArray[Idx].AdcPort;
        AdcCmdTemp.AdcChanA  = AdcCmdArray[Idx].AdcChanA;
#if (FEATURE_CTU_NUM_ADC > 1)
        AdcCmdTemp.AdcChanB  = AdcCmdArray[Idx].AdcChanB;
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
        Ctu_ConfigSingleCmd(Instance, Ctu_CorrectCLRposition(Idx % CTU_CLR_COUNT), &AdcCmdTemp, (LastCmdPrev ? 1u : 0u));

        /* Set the Last Command(LC) bit of the next command to 1 */
        LastCmdPrev = AdcCmdArray[Idx].bLastCmd;
    }

    /* Set the Last Command(LC) bit of the next entry to 1 if the last
     * element in the list had the last command field set */
    if (LastCmdPrev)
    {
        CtuBasePtr->CLR.A[Ctu_CorrectCLRposition(Idx % CTU_CLR_COUNT)] |= CTU_A_LC_MASK;
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SetFifoThreshold
* Description   : This function configures the threshold of a selected result FIFO.
*
* @implements      Ctu_Ip_SetFifoThreshold_Activity
* END**************************************************************************/
void Ctu_Ip_SetFifoThreshold(const uint32 u32Instance,
                             const uint32 u32FifoIdx,
                             const uint8 u8Threshold)
{
    uint32 Shift;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32FifoIdx < CTU_FR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    Shift = CTU_FTH_TH1_SHIFT * u32FifoIdx;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_73();
    /* Clear bits corresponding to u32FifoIdx in FTH */
    CtuBasePtr->FTH &= ~((uint32)CTU_FTH_TH0_MASK << Shift);
    /* Set new values for u32FifoIdx in FTH */
    CtuBasePtr->FTH |= ((uint32)u8Threshold & CTU_FTH_TH0_MASK) << Shift;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_73();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_GetFifoData
* Description   : This function returns the conversion data result aligned according
* to the alignment parameter.
*
* @implements      Ctu_Ip_GetFifoData_Activity
* END**************************************************************************/
void Ctu_Ip_GetFifoData(const uint32 u32Instance,
                        const uint32 u32FifoIdx,
                        Ctu_Ip_DataAlignType pAlignment,
                        const uint8 u8ResultLength,
                        uint16 * const pData)
{
    uint8 Remaining;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32FifoIdx < CTU_FR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    Remaining = u8ResultLength;

    while (Remaining > 0u)
    {
        switch (pAlignment)
        {
            case CTU_IP_RESULT_ALIGN_RIGHT_UNSIGNED:
                pData[u8ResultLength-Remaining] = (uint16) (CtuBasePtr->FR[u32FifoIdx] & CTU_FR_DATA_MASK);
                break;
            case CTU_IP_RESULT_ALIGN_LEFT_SIGNED:
                pData[u8ResultLength-Remaining] = (uint16) (CtuBasePtr->FL[u32FifoIdx] & CTU_FL_LA_DATA_MASK);
                break;
            default:
                ; /* no-op */
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
                break;
        }
        Remaining--;
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_GetFifoResult
* Description   : This function gets the full conversion result information, with
* the conversion data aligned according to the alignment parameter.
*
* @implements      Ctu_Ip_GetFifoResult_Activity
* END**************************************************************************/
void Ctu_Ip_GetFifoResult(const uint32 u32Instance,
                          const uint32 u32FifoIdx,
                          const Ctu_Ip_DataAlignType pAlignment,
                          const uint8 u8ResultLength,
                          Ctu_Ip_ConvResultType * const pResults)
{
    uint8 Remaining;
    uint32 ResInfo = 0u;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32FifoIdx < CTU_FR_COUNT);
    DevAssert(pResults != NULL_PTR);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    Remaining = u8ResultLength;

    while (Remaining > 0u)
    {
        switch (pAlignment)
        {
            case CTU_IP_RESULT_ALIGN_RIGHT_UNSIGNED:
                ResInfo = CtuBasePtr->FR[u32FifoIdx];
                pResults[u8ResultLength-Remaining].ConvData = (uint16) (ResInfo & CTU_FR_DATA_MASK);
                break;
            case CTU_IP_RESULT_ALIGN_LEFT_SIGNED:
                ResInfo = CtuBasePtr->FL[u32FifoIdx];
                pResults[u8ResultLength-Remaining].ConvData = (uint16) (ResInfo & CTU_FL_LA_DATA_MASK);
                break;
            default:
                ; /* no-op */
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
                break;
        }

        if ((ResInfo & CTU_FR_ADC_MASK) != 0u)
        {
            pResults[u8ResultLength-Remaining].AdcPort = CTU_IP_ADC_PORT_A;
        }
#if (FEATURE_CTU_NUM_ADC > 1)
        else
        {
            pResults[u8ResultLength-Remaining].AdcPort = CTU_IP_ADC_PORT_B;
        }
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
        pResults[u8ResultLength-Remaining].AdcChanNum = (uint8) ((ResInfo & CTU_FR_N_CH_MASK) >> CTU_FR_N_CH_SHIFT);

        Remaining--;
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_EnableFifoNotifications
* Description   : This function enables the notifications for the selected result FIFO, corresponding
* to the bits set in mask parameter.
* Note: FIFO notifications(except overrun) can't be cleared by flag.
* Clearing overflow and full notifications is done by reading from the FIFO.
*
* The mask parameter can be set using the defines provided in the driver header file:
* CTU_FIFO_ - e.g. CTU_IP_FIFO_FULL.
*
* @implements      Ctu_Ip_EnableFifoNotifications_Activity
* END**************************************************************************/
void Ctu_Ip_EnableFifoNotifications(const uint32 u32Instance,
                                    const uint32 u32FifoIdx,
                                    const uint32 u32NotificationMask)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32FifoIdx < CTU_FR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    const uint32 Shift = CTU_FCR_FULL_EN1_SHIFT * u32FifoIdx;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_71();
    CtuBasePtr->FCR |= ((u32NotificationMask & CTU_IP_FIFO_ALL) << Shift);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_71();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_DisableFifoNotifications
* Description   : This function disables the notifications for the selected result FIFO, corresponding
* to the bits set in mask parameter.
* The mask parameter can be set using the defines provided in the driver header file:
* CTU_FIFO_ - e.g. CTU_IP_FIFO_FULL.
*
* @implements      Ctu_Ip_DisableFifoNotifications_Activity
* END**************************************************************************/
void Ctu_Ip_DisableFifoNotifications(const uint32 u32Instance,
                                     const uint32 u32FifoIdx,
                                     const uint32 u32NotificationMask)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32FifoIdx < CTU_FR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    const uint32 Shift = CTU_FCR_FULL_EN1_SHIFT * u32FifoIdx;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_72();
    CtuBasePtr->FCR &= ~((u32NotificationMask & CTU_IP_FIFO_ALL) << Shift);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_72();

#ifdef FEATURE_CPU_HAS_WRITE_BUFFER
    /* Dummy read as a workaround for write buffer feature to ensure the flags are
    cleared before continuing. */
    (void) CtuBasePtr->FCR;
#endif /* FEATURE_CPU_HAS_WRITE_BUFFER */
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_EnableNotifications
* Description   : This function enables the notifications corresponding to the bits set in mask parameter.
*
* The mask parameter can be set using the defines provided in the driver header file:
* CTU_IP_NOTIFICATION_ - e.g. CTU_IP_NOTIFICATION_ALL.
*
* @implements      Ctu_Ip_EnableNotifications_Activity
* END**************************************************************************/
void Ctu_Ip_EnableNotifications(const uint32 u32Instance,
                                const uint16 u16NotificationMask)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_66();
    CtuBasePtr->IR |= u16NotificationMask & CTU_IP_NOTIFICATION_ALL;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_66();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_DisableNotifications
* Description   : This function enables the notifications corresponding to the bits set in mask parameter.
*
* The mask parameter can be set using the defines provided in the driver header file:
* CTU_IP_NOTIFICATION_ - e.g. CTU_IP_NOTIFICATION_ALL.
*
* @implements      Ctu_Ip_DisableNotifications_Activity
* END**************************************************************************/
void Ctu_Ip_DisableNotifications(const uint32 u32Instance,
                                 const uint16 u16NotificationMask)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_67();
    CtuBasePtr->IR &= ~(u16NotificationMask & CTU_IP_NOTIFICATION_ALL);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_67();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_EnableTrigger
* Description   : This function enables the triggers corresponding to the bits set in mask parameter.
* This is done by modifying the Tx_E bits of THCRx register corresponding to the
* triggers set in the mask parameter.
*
* @implements      Ctu_Ip_EnableTrigger_Activity
* END**************************************************************************/
void Ctu_Ip_EnableTrigger(const uint32 u32Instance,
                          const uint8 u8TrigIdxMask)
{
    uint32 Index;
    uint32 Shift;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    for (Index = 0; Index < FEATURE_CTU_NUM_TRG; Index++)
    {
        if (((u8TrigIdxMask >> Index) & 1u) != 0u)
        {
            /* The THCR1 and THCR2 registers are together organized into 8 groups of enable bits.
               Each register contains 4 groups with group's size is 8
               Each group is associated with one trigger from the Trigger subunit */
            Shift = ((Index % 4u) * 8u) + CTU_THCR1_T0_E_SHIFT;

            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_64();
            if (Index < 4u)
            {
                CtuBasePtr->THCR1 |= ((uint32)1u << Shift);
            }
            else
            {
                CtuBasePtr->THCR2 |= ((uint32)1u << Shift);
            }
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_64();
        }
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_DisableTrigger
* Description   : This function disables the triggers corresponding to the bits set in mask parameter.
* This is done by modifying the Tx_E bits of THCRx register corresponding to the
* triggers set in the mask parameter.
*
* @implements      Ctu_Ip_DisableTrigger_Activity
* END**************************************************************************/
void Ctu_Ip_DisableTrigger(const uint32 u32Instance,
                           const uint8 u8TrigIdxMask)
{
    uint32 Index;
    uint32 Shift;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    for (Index = 0; Index < FEATURE_CTU_NUM_TRG; Index++)
    {
        if (((u8TrigIdxMask >> Index) & 1u) != 0u)
        {
            /* The THCR1 and THCR2 registers are together organized into 8 groups of enable bits.
               Each register contains 4 groups with group's size is 8
               Each group is associated with one trigger from the Trigger subunit */
            Shift = ((Index % 4u) * 8u) + CTU_THCR1_T0_E_SHIFT;

            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_65();
            if (Index < 4u)
            {
                CtuBasePtr->THCR1 &= ~(1UL << Shift);
            }
            else
            {
                CtuBasePtr->THCR2 &= ~(1UL << Shift);
            }
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_65();
        }
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_ClearErrorFlags
* Description   : Clears the error flags corresponding to the bits set in mask parameter.
* The mask parameter can be set using the defines provided in the driver header file:
* CTU_IP_ERROR_FLAG_ - e.g. CTU_IP_ERROR_FLAG_INVALID_CMD.
*
* @implements      Ctu_Ip_ClearErrorFlags_Activity
* END**************************************************************************/
void Ctu_Ip_ClearErrorFlags(const uint32 u32Instance,
                            const uint32 u32FlagsMask)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    CtuBasePtr->EFR = (uint16)(u32FlagsMask & CTU_IP_ERROR_FLAG_ALL);

#ifdef FEATURE_CPU_HAS_WRITE_BUFFER
    /* Dummy read as a workaround for write buffer feature to ensure the flags are
    cleared before continuing. */
    (void) CtuBasePtr->EFR;
#endif /* FEATURE_CPU_HAS_WRITE_BUFFER */
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_GetErrorFlags
* Description   : Returns bit-mask with values for all the CTU error flags.
* Values for individual flags may be retrieved by masking the result with defines provided
* in the driver header file: CTU_IP_ERROR_FLAG_ - e.g. CTU_IP_ERROR_FLAG_MRS_RE.
*
* @implements      Ctu_Ip_GetErrorFlags_Activity
* END**************************************************************************/
uint16 Ctu_Ip_GetErrorFlags(const uint32 u32Instance)
{
    uint16 u16Result;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];
    u16Result = CtuBasePtr->EFR & CTU_IP_ERROR_FLAG_ALL;

    return u16Result;
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_GetListStatus
* Description   : This function gets the list status information.
* Information for multiple lists is available when executing in parallel mode.
*
* @implements      Ctu_Ip_GetListStatus_Activity
* END**************************************************************************/
Ctu_Ip_StatusType Ctu_Ip_GetListStatus(const uint32 u32Instance,
                                       const uint32 u32ListIdx,
                                       Ctu_Ip_ListStatusType * const pListStatus)
{
    Ctu_Ip_StatusType Status;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    if ((Ctu_Ip_GetErrorFlags(u32Instance) & CTU_IP_ERROR_FLAG_LIST_BUSY) == 0u)
    {
        Status = CTU_IP_STATUS_ERROR; /* Result is not meaningful, because EFR.LIST_BE is not set. */
    }
    else
    {
        switch (u32ListIdx)
        {
            case 0u:
                pListStatus->ListAddr   = (uint8) ((CtuBasePtr->LISTCSR & CTU_LISTCSR_LIST0_ADDR_MASK) >> CTU_LISTCSR_LIST0_ADDR_SHIFT);
                pListStatus->ListBlocked = ((CtuBasePtr->LISTCSR & CTU_LISTCSR_LIST0_BLK_MASK) != 0u) ? TRUE : FALSE;
                break;
            case 1u:
                pListStatus->ListAddr   = (uint8) ((CtuBasePtr->LISTCSR & CTU_LISTCSR_LIST1_ADDR_MASK) >> CTU_LISTCSR_LIST1_ADDR_SHIFT);
                pListStatus->ListBlocked = ((CtuBasePtr->LISTCSR & CTU_LISTCSR_LIST1_BLK_MASK) != 0u) ? TRUE : FALSE;
                break;
            default:
                ; /* no-op */
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
                break;
        }
        Status = CTU_IP_STATUS_SUCCESS;
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SwInternalTrigger
* Description   : Generates from software an event on the selected internal trigger,
* provided as input to the Scheduler subunit (SU).
* This bypasses any delays configured in Trigger Generator Subunit (TGS)
* and can be used when the TGS Counter is running or stopped.
*
* @implements      Ctu_Ip_SwInternalTrigger_Activity
* END**************************************************************************/
void Ctu_Ip_SwInternalTrigger(const uint32 u32Instance,
                              const uint32 u32TrigIdx)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
    DevAssert(u32TrigIdx < CTU_TCR_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_55();
    CtuBasePtr->CR |= CTU_CR_T0_SG_MASK << u32TrigIdx;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_55();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SwMasterReload
* Description   : Software triggers the Master Reload Signal.
*
* @implements      Ctu_Ip_SwMasterReload_Activity
* END**************************************************************************/
void Ctu_Ip_SwMasterReload(const uint32 u32Instance)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_56();
    CtuBasePtr->CR |= CTU_CR_MRS_SG_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_56();
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_EnableOutput
* Description   : Enables CTU output
*
* @implements      Ctu_Ip_EnableOutput_Activity
* END**************************************************************************/
void Ctu_Ip_EnableOutput(const uint32 u32Instance)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    Ctu_ConfigOutputDisable(CtuBasePtr, FALSE);
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_DisableOutput
* Description   : Disables CTU output
*
* @implements      Ctu_Ip_DisableOutput_Activity
* END**************************************************************************/
void Ctu_Ip_DisableOutput(const uint32 u32Instance)
{
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    Ctu_ConfigOutputDisable(CtuBasePtr, TRUE);
}

/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_SetGeneralReloadEnable
* Description   : Enables General Reload (CR.GRE)
*
* @implements      Ctu_Ip_SetGeneralReloadEnable_Activity
* END**************************************************************************/
Ctu_Ip_StatusType Ctu_Ip_SetGeneralReloadEnable(const uint32 u32Instance,
                                                const boolean bEnable)
{
    Ctu_Ip_StatusType Status = CTU_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(CTU_IP_TIMEOUT_VAL, CTU_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(CTU_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;
    uint16 Cr;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_57();
    if (TRUE == bEnable)
    {
        CtuBasePtr->CR |= CTU_CR_GRE_MASK;
    }
    else
    {
        CtuBasePtr->CR |= CTU_CR_CGRE_MASK;

        Cr = CtuBasePtr->CR;

        /* Wait while CGRE takes effect and clears GRE bit.
        * This is done to mitigate propagation delay in CTU module and guarantee that any code called after Ctu_Ip_DisableGeneralReload
        * is executed after CGRE write takes effect.
        * The delay is not expected to take more than 2 CTU clock cycles. */
        while (((Cr & CTU_CR_GRE_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
        {
            Cr = CtuBasePtr->CR;
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, CTU_IP_TIMEOUT_TYPE);
        }
        if (ElapsedTicks >= TimeoutTicks)
        {
            Status = CTU_IP_STATUS_TIMEOUT;
        }
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_57();

    return Status;
}
#ifdef CTU_IP_DMA_SUPPORTED
/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_FifoDmaHandler
* Description   : Handle CTU DMA FIFO Transfer
* END**************************************************************************/
void Ctu_Ip_FifoDmaHandler(const uint32 Instance,
                           const uint32 FifoIndex)
{
    Ctu_Ip_axCtuState[Instance].FifoNotifications[FifoIndex].ThresholdNotification();
    /* DMA Hardware Request was disabled after the transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
    (void)Dma_Ip_SetLogicChannelCommand(Ctu_Ip_au32CtuFifoDmaChannel[FifoIndex], DMA_IP_CH_SET_HARDWARE_REQUEST);
}
#endif /* CTU_IP_DMA_SUPPORTED */
/*FUNCTION**********************************************************************
*
* Function Name : Ctu_Ip_IRQHandler
* Description   : Handle CTU interrupts
* END*********************************************************************************/
void Ctu_Ip_IRQHandler(const uint32 Instance,
                       const Ctu_Ip_IRQType IRQType,
                       const uint8 Offset)
{
    uint8 Index;
    uint16 Mask;
    uint16 Efr = 0u;
    uint32 Fst = 0u;
    uint16 Ifr = 0u;

#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CTU_INSTANCE_COUNT);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */

    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];

    /* CPR_RTD_00011 */
    if (Ctu_Ip_axCtuState[Instance].InitStatus)
    {
        switch (IRQType)
        {
            case CTU_IP_IRQ_FIFO:
#if FEATURE_CTU_HAS_FIFO_IRQ_ROLLED
                /* Avoid compiler warning */
                (void) Offset;
                for (Index = 0u; Index < CTU_IP_FIFO_COUNT; Index++)
#else
                Index = Offset;
#endif /* FEATURE_CTU_HAS_FIFO_IRQ_ROLLED */
                {
                    /* Check which interrupt was triggered */
                    Ctu_CheckAndCallFifoNotification(CtuBasePtr, Index, CTU_IP_FIFO_EMPTY,
                        Ctu_Ip_axCtuState[Instance].FifoNotifications[Index].UnderrunNotification);
                    Ctu_CheckAndCallFifoNotification(CtuBasePtr, Index, CTU_IP_FIFO_FULL,
                        Ctu_Ip_axCtuState[Instance].FifoNotifications[Index].FullNotification);
                    Ctu_CheckAndCallFifoNotification(CtuBasePtr, Index, CTU_IP_FIFO_OVERFLOW,
                        Ctu_Ip_axCtuState[Instance].FifoNotifications[Index].ThresholdNotification);
                    Ctu_CheckAndCallFifoNotification(CtuBasePtr, Index, CTU_IP_FIFO_OVERRUN,
                        Ctu_Ip_axCtuState[Instance].FifoNotifications[Index].OverrunNotification);
                }
                break;
            case CTU_IP_IRQ_TRIG:
                for (Index = 0u; Index < FEATURE_CTU_NUM_TRG; Index++)
                {
                    /* Check and call the triggerd input notification */
                    Ctu_CheckAndCallTrigNotification(Instance, CtuBasePtr, Index);
                }
                break;
            case CTU_IP_IRQ_ERROR:
                Mask = (uint16)(CtuBasePtr->EFR & CTU_IP_ERROR_FLAG_ALL);
                /* Check and call error flags notification */
                if ((((CtuBasePtr->IR) & (CTU_IR_IEE_MASK)) != 0u) && (Mask != 0U))
                {

                    /* Clear flags */
                    /* CPR_RTD_00644 */
                    CtuBasePtr->EFR = Mask;

                    if (Ctu_Ip_axCtuState[Instance].ErrNotification != NULL_PTR)
                    {
                        Ctu_Ip_axCtuState[Instance].ErrNotification(Mask);
                    }
                }

                break;
            default:
                ; /* no-op */
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
                break;
        }
    }
    else
    {
        /* CPR_RTD_00011 */
        Efr = CtuBasePtr->EFR;
        CtuBasePtr->EFR = Efr;

        Fst = CtuBasePtr->FST;
        CtuBasePtr->FST = Fst;

        Ifr = CtuBasePtr->IFR;
        CtuBasePtr->IFR = Ifr;
    }
}

#if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Ctu_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the instance accessible in user mode.
 *
 *END**************************************************************************/
void Ctu_Ip_SetUserAccessAllowed(const CTU_Type * const CtuBasePtr)
{
    SET_USER_ACCESS_ALLOWED((uint32)CtuBasePtr, CTU_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ctu_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the instance inaccessible in user mode.
 *
 *END**************************************************************************/
void Ctu_Ip_ClrUserAccessAllowed(const CTU_Type * const CtuBasePtr)
{
    CLR_USER_ACCESS_ALLOWED((uint32)CtuBasePtr, CTU_PROT_MEM_U32);
}
#endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_SelectInput
* Description   : Returns bitmask with '1' on the position of the input signal edge(s)
* END*********************************************************************************/
static uint32 Ctu_SelectInput(const Ctu_Ip_InputTrigType InputTrig,
                              const Ctu_Ip_InputEdgeType InputEdge)
{
    uint32 TgsisrMask = ~(CTU_IP_INPUT_TRIG_BITMASK_ALL);

    switch (InputEdge)
    {
        case CTU_IP_INPUT_EDGE_RISING:
            TgsisrMask = CTU_IP_INPUT_TRIG_BITMASK_RISING(InputTrig);
            break;
        case CTU_IP_INPUT_EDGE_FALLING:
            TgsisrMask = CTU_IP_INPUT_TRIG_BITMASK_FALLING(InputTrig);
            break;
        case CTU_IP_INPUT_EDGE_BOTH:
            TgsisrMask = CTU_IP_INPUT_TRIG_BITMASK_BOTH(InputTrig);
            break;
        default:
            ; /* no-op */
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }

    return TgsisrMask;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_ConfigSingleCmd
* Description   : Configures a single ADC command at a selected position in the CTU command list.
* Note0: current lcFlag value refers to previous command in the list.
*  The last command (n) is defined by the LC bit of the next command (n+1) in the list.
* Note1: assumes 'pos' parameter is in correct range.
* Note2: pos is already corrected for endianness handling
* END*********************************************************************************/
static void Ctu_ConfigSingleCmd(const uint32 Instance,
                                const uint32 Pos,
                                const Ctu_Ip_AdcCmdType * const AdcCmd,
                                const uint32 LcFlagValue)
{
    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];
    uint16 Cmd = 0u;

    Cmd |= CTU_A_LC(LcFlagValue); /* Common between all 3 formats */
    Cmd |= (TRUE == AdcCmd->IntEn) ? CTU_A_CIR_MASK : 0u; /* Common between all 3 formats, but ignored in format C */
    Cmd |= CTU_A_FIFO(AdcCmd->FifoIdx);                   /* Common between formats A and B */

    switch (AdcCmd->ConvMode)
    {
        case CTU_IP_CONV_MODE_SINGLE: /* Command format A */
            Cmd |= CTU_A_SU(AdcCmd->AdcPort);
            Cmd |= CTU_A_CH(AdcCmd->AdcChanA);
            CtuBasePtr->CLR.A[Pos] = Cmd;
            break;
#if (FEATURE_CTU_NUM_ADC > 1)
        case CTU_IP_CONV_MODE_DUAL: /* Command format B */
            Cmd |= CTU_B_CMS_MASK;
            Cmd |= CTU_B_CH_A(AdcCmd->AdcChanA);
            Cmd |= CTU_B_CH_B(AdcCmd->AdcChanB);
            CtuBasePtr->CLR.A[Pos] = Cmd;
            break;
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
        default:
            ; /* no-op */
#if (CTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (CTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_CorrectCLRposition
* Description   : This function correct the position of CLR index,
* that is depending on CORE_BIG_ENDIAN or CORE_LITTLE_ENDIAN
* This function return the correct index.
* Note1: assumes 'pos' parameter is in correct range.
* END*********************************************************************************/
static inline uint32 Ctu_CorrectCLRposition(const uint32 Pos)
{
    uint32 PosTemp = Pos;

    /*! @brief CTU CLR index endianness handling */
#if FEATURE_CTU_CLR_LITTLE_ENDIAN
    /*! @brief swap even with odd position  */
    if ((Pos % 2u) == 0u)
    {
        PosTemp = Pos + 1u;
    }
    else
    {
        PosTemp = Pos - 1u;
    }
#endif /* FEATURE_CTU_CLR_LITTLE_ENDIAN */
    return PosTemp;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_GetFifoStatusFlags
* Description   : Returns bitmask with all the status flags for a selected result FIFO.
* Values for individual flags may be retrieved by masking the result with defines provided
* in the driver header file: CTU_FIFO_ - e.g. CTU_IP_FIFO_OVERFLOW.
* END*********************************************************************************/
static uint32 Ctu_GetFifoStatusFlags(const uint32 Instance,
                                     const uint32 FifoIdx)
{
    const CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];
    uint32 Result;
    /* Reduce data width of "FifoIdx" to 16-bit to avoid CWE INTEGER_OVERFLOW when perform multiplication */
    const uint32 Shift = (uint16)(CTU_FST_FULL1_SHIFT * (uint16)FifoIdx);

    Result = (CtuBasePtr->FST & (CTU_IP_FIFO_ALL << Shift)) >> Shift;

    return Result;
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_ConfigOutputDisable
 * Description   : Enable/Disable CTU output
 *
 *END*************************************************************************/
static inline void Ctu_ConfigOutputDisable(CTU_Type * const CtuBasePtr,
                                           boolean Enable)
{
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_58();
    if (TRUE == Enable)
    {
        CtuBasePtr->CR |= (uint16)CTU_CR_CTU_ODIS_MASK;
    }
    else
    {
        CtuBasePtr->CR &= ~((uint16)CTU_CR_CTU_ODIS_MASK);
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_58();
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_ConfigDigitalFilter
 * Description   : Configure digital filter mode
 *
 *END*************************************************************************/
static inline void Ctu_ConfigDigitalFilter(CTU_Type * const CtuBasePtr,
                                           uint8 DigitalFilter)
{
    if (DigitalFilter == 0u)
    {
        CtuBasePtr->CR &= (~(uint16)CTU_CR_DFE_MASK);
        CtuBasePtr->DFR = (uint16) CTU_DFR_FILTER_N(0u);
    }
    else
    {
        CtuBasePtr->DFR = CTU_DFR_FILTER_N(DigitalFilter);
        CtuBasePtr->CR |= (uint16)CTU_CR_DFE_MASK;
    }
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_ConfigListMode
 * Description   : The list execution will be ran with streaming or parallel mode
 *
 *END*************************************************************************/
static inline void Ctu_ConfigListMode(CTU_Type * const CtuBasePtr,
                                      Ctu_Ip_AdcCmdListModeType Mode)
{
    if (Mode == CTU_IP_ADC_CMD_LIST_MODE_PARALLEL)
    {
        CtuBasePtr->LISTCSR |= CTU_LISTCSR_PAR_LIST_MASK;
    }
    else
    {
        CtuBasePtr->LISTCSR &= (~CTU_LISTCSR_PAR_LIST_MASK);
    }
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_GetDefaultConfig
* Description   : This function populates the configuration structure with the
* default configuration for CTU
*
* END*********************************************************************************/
static inline void Ctu_GetDefaultConfig(Ctu_Ip_ConfigType * const Config)
{
    uint8 Index;

    /* Reset general configurations to default */
    Config->TgsMode                        = CTU_IP_TGS_MODE_TRIGGERED;
    Config->Prescaler                      = CTU_IP_PRESCALER_1;
#if FEATURE_CTU_EXT_TRIG_PRESENT
    Config->ExtTrigMode                    = CTU_IP_EXT_TRIG_MODE_PULSE;
#endif /*FEATURE_CTU_EXT_TRIG_PRESENT */
    Config->InputTrigSelectMask          = 0u;
    Config->TgsCounterCompareVal         = 0u;
    Config->TgsCounterReloadVal          = 0u;
    Config->AdcCmdListMode                 = CTU_IP_ADC_CMD_LIST_MODE_STREAMING;
    Config->SeqModeMrsInput                = CTU_IP_INPUT_TRIG_PWM_REL;
    Config->SeqModeMrsInputEdge            = CTU_IP_INPUT_EDGE_RISING;
    Config->DmaDoneGRE                     = FALSE;
    Config->DmaReqMRS                      = FALSE;
    Config->DisableOutput                  = FALSE;
    Config->DigitalFilter                 = 0u;
    Config->ConvDurationCounterRange     = 0u;
    Config->ControlOnTime                 = 0u;
    Config->ErrNotification               = NULL_PTR;
    Config->MrsNotification               = NULL_PTR;
    Config->AdcCommandIssueNotification   = NULL_PTR;
    Config->NumTrigConfigs                = 0u;
    Config->TrigConfigs                    = NULL_PTR;
    Config->NumAdcCmdConfigs              = 0u;
    Config->AdcCmdConfigs                  = NULL_PTR;
    Config->NumFifoConfigs                = 0u;
    Config->FifoConfigs                    = NULL_PTR;
    for (Index = 0; Index < FEATURE_CTU_NUM_ADC; Index++)
    {
        Config->ConvDurationExpectedVal[Index]           = 0xFF;
        Config->ConvDurationExceedNotification[Index]   = NULL_PTR;
    }
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_ResetFifo
* Description   : The function resets all Fifo registers to default value. Also flush
* Fifo results in Fifo data registers
*
* END*********************************************************************************/
static inline Ctu_Ip_StatusType Ctu_ResetFifo(const uint32 Instance)
{
    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];
    uint32 FifoEmptyMask;
    uint16 ConvData;
    uint8 Index;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(CTU_IP_TIMEOUT_VAL, CTU_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    Ctu_Ip_StatusType Status = CTU_IP_STATUS_SUCCESS;

    /* Reset Fifo DMA Control */
    CtuBasePtr->FDCR = 0u;

    /* Empty the result FIFOs without triggering additional interrupts */
    /* Assumes that there is no pending conversion data to be written in the FIFOs. */
    for (Index = 0u; Index < CTU_FR_COUNT; Index++)
    {
        Ctu_Ip_DisableFifoNotifications(Instance, Index, CTU_IP_FIFO_ALL);
        FifoEmptyMask = Ctu_GetFifoStatusFlags(Instance, Index) & CTU_IP_FIFO_EMPTY;
        CurrentTicks = OsIf_GetCounter(CTU_IP_TIMEOUT_TYPE);
        ElapsedTicks = 0u;
        while ((FifoEmptyMask == 0u) && (ElapsedTicks < TimeoutTicks))
        {
            Ctu_Ip_GetFifoData(Instance, Index, CTU_IP_RESULT_ALIGN_RIGHT_UNSIGNED, 1u, &ConvData);
            (void) ConvData; /* Data is only read to empty the result FIFO */

            FifoEmptyMask = Ctu_GetFifoStatusFlags(Instance, Index) & CTU_IP_FIFO_EMPTY;
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, CTU_IP_TIMEOUT_TYPE);
        }
        if (ElapsedTicks >= TimeoutTicks) {
            Status = CTU_IP_STATUS_TIMEOUT;
            break;
        }
        /* Note that CTU_IP_FIFO_EMPTY flags will remain set, because they reflect the state of the FIFOs
         * and cannot be reset by writing to them. */
        CtuBasePtr->FST = (uint32) CTU_FST_OR0_MASK << (CTU_FST_FULL1_SHIFT * Index);

#ifdef FEATURE_CPU_HAS_WRITE_BUFFER
        /* Dummy read as a workaround for write buffer feature to ensure the flags are cleared before continuing. */
        (void) CtuBasePtr->FST;
#endif /* FEATURE_CPU_HAS_WRITE_BUFFER */
    }

    return Status;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_ReloadDoubleBuffer
* Description   : The function load the programmed values to the double bufferred registers
* The function enable GRE and generate MRS to create a normal re-load where the buffers of
* the double buffered registers are programmed and the GRE bit is set before the next MRS occurs
*
* END*********************************************************************************/
static inline Ctu_Ip_StatusType Ctu_ReloadDoubleBuffer(const uint32 Instance,
                                                       Ctu_Ip_TGSModeType TgsMode)
{
    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];
    Ctu_Ip_StatusType Status;
    uint32 ErrFlags;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(CTU_IP_TIMEOUT_VAL, CTU_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(CTU_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;

    /* SW trigger MRS to make sure reset values get loaded to the double buffered registers
     * and FGRE flag is reset (refer to device reference manual for reload mechanism). */
    Status = Ctu_Ip_SetGeneralReloadEnable(Instance, TRUE);

    if (CTU_IP_STATUS_SUCCESS == Status)
    {
        /* Start TGS Counter */
        Ctu_Ip_SwMasterReload(Instance);

        /* If CTU before reset is in triggered mode */
        if (TgsMode == CTU_IP_TGS_MODE_TRIGGERED)
        {
            /* In TRIGGERED mode, the Sw MRS starts the TGS Counter, also in the case when TGSCRR = TGSCRR (see Reference Manual chapter on TGS counter).
            * So need to wait until the TGS Counter stops.
            * In SEQUENTIAL mode, the Sw MRS doesn't start the TGS Counter at all. So, these procedures are not required. */
            do
            {
                ErrFlags = Ctu_Ip_GetErrorFlags(Instance);
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, CTU_IP_TIMEOUT_TYPE);
            }
            while (((ErrFlags & CTU_IP_ERROR_FLAG_ERRCMP) == 0u) && (ElapsedTicks <= TimeoutTicks));

            if (ElapsedTicks < TimeoutTicks)
            {
                /* Clear error and interrupt flags which may have been set during the control cycle started by Sw MRS */
                Ctu_Ip_ClearErrorFlags(Instance, CTU_IP_ERROR_FLAG_ALL);
                CtuBasePtr->IFR = (uint16) (CTU_IP_NOTIFICATION_FLAG_ALL);
            }
            else
            {
                Status = CTU_IP_STATUS_TIMEOUT;
            }
        }
    }

    return Status;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_ConfigAndUpdateFifoNotification
* Description   : Configure Fifo with an array of provided structure and update Fifo
* notification
*
* END*********************************************************************************/
static inline void Ctu_ConfigAndUpdateFifoNotification(const uint32 Instance,
                                                       const Ctu_Ip_FifoConfigType * const FifoConfigArray,
                                                       const uint8 NumFifoConfigs)
{
    uint8 Index;
    uint16 Fdcr;
    uint32 Shift;
    uint32 Mask;
    const Ctu_Ip_FifoConfigType * FifoConfig;
    CTU_Type * const CtuBasePtr = Ctu_Ip_apxCtuBase[Instance];

    for (Index = 0; Index < NumFifoConfigs; Index++)
    {
        FifoConfig = &(FifoConfigArray[Index]);
        Fdcr = 0u;
        Shift = 0u;
        Mask = 0u;
        /* If Fifo Dma is enabled, the FIFO interrputs should NOT configure */
        if (FALSE == FifoConfig->FifoDmaEnable)
        {
            /* Create bit mask for FIFO interrupts */
            Mask |= (FifoConfig->ThresholdNotification != NULL_PTR) ? CTU_IP_FIFO_OVERFLOW : 0u;
            Mask |= (FifoConfig->UnderrunNotification != NULL_PTR) ? CTU_IP_FIFO_EMPTY : 0u;
            Mask |= (FifoConfig->OverrunNotification != NULL_PTR) ? CTU_IP_FIFO_OVERRUN : 0u;
            Mask |= (FifoConfig->FullNotification != NULL_PTR) ? CTU_IP_FIFO_FULL : 0u;
        }
#ifdef CTU_IP_DMA_SUPPORTED
        else
        {
            Ctu_FifoSetupDma(FifoConfig);
            Ctu_Ip_au32CtuFifoDmaChannel[Index] = FifoConfig->FifoDmaChannel;
        }
#endif /* CTU_IP_DMA_SUPPORTED */
        Shift = (uint32)CTU_FCR_FULL_EN1_SHIFT * FifoConfig->FifoIndex;
        /* Clear bits corresponding to fifoIdx in FCR */
        CtuBasePtr->FCR &= ~(CTU_IP_FIFO_ALL << Shift);
        /* Set new values for fifoIdx in FCR */
        CtuBasePtr->FCR |= (Mask & CTU_IP_FIFO_ALL) << Shift;

        Ctu_Ip_SetFifoThreshold(Instance, (uint32) FifoConfig->FifoIndex, FifoConfig->FifoThreshold);

        /* FDCR includes reserved w1c bitfields which will be set with 0s */
        Fdcr = (CtuBasePtr->FDCR) & (CTU_FDCR_DE0_MASK | CTU_FDCR_DE1_MASK | CTU_FDCR_DE2_MASK | CTU_FDCR_DE3_MASK);

        if (TRUE == FifoConfig->FifoDmaEnable)
        {
            Fdcr |= (uint16)CTU_FDCR_DE0_MASK << FifoConfig->FifoIndex;
        }
        else
        {
            Fdcr &= ~((uint16)CTU_FDCR_DE0_MASK << FifoConfig->FifoIndex);
        }

        CtuBasePtr->FDCR = Fdcr;

        Ctu_Ip_axCtuState[Instance].FifoNotifications[FifoConfig->FifoIndex].ThresholdNotification = FifoConfig->ThresholdNotification;
        Ctu_Ip_axCtuState[Instance].FifoNotifications[FifoConfig->FifoIndex].UnderrunNotification = FifoConfig->UnderrunNotification;
        Ctu_Ip_axCtuState[Instance].FifoNotifications[FifoConfig->FifoIndex].OverrunNotification = FifoConfig->OverrunNotification;
        Ctu_Ip_axCtuState[Instance].FifoNotifications[FifoConfig->FifoIndex].FullNotification = FifoConfig->FullNotification;
    }
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Ctu_ConfigTrigGenSubunit
* Description   : Configure trigger generator subunit control
*
* END*********************************************************************************/
static inline void Ctu_ConfigTrigGenSubunit(CTU_Type * const CtuBasePtr,
                                            const Ctu_Ip_TrigGenSubType * TgscrCfg)
{
    uint16 Offset;
    uint16 Tgscr = 0u;

    if (TgscrCfg->TgsMode == CTU_IP_TGS_MODE_SEQUENTIAL)
    {
        Tgscr |= CTU_TGSCR_TGS_M_MASK;
        Offset = (TgscrCfg->SeqModeMrsInputEdge == CTU_IP_INPUT_EDGE_RISING) ? (uint16)0u : (uint16)1u;
        /* TGSCR.MRS_SM must be set with the index corresponding to entries in TGSISR */
        Tgscr |= CTU_TGSCR_MRS_SM((2u * ((uint16) TgscrCfg->SeqModeMrsInput)) + Offset);
    }

    Tgscr |= CTU_TGSCR_PRES(TgscrCfg->Prescaler);
#if FEATURE_CTU_EXT_TRIG_PRESENT
    Tgscr |= (TgscrCfg->ExtTrigMode == CTU_IP_EXT_TRIG_MODE_TOGGLE) ? CTU_TGSCR_ET_TM_MASK : 0u;
#endif /* FEATURE_CTU_EXT_TRIG_PRESENT */

    CtuBasePtr->TGSCR = Tgscr;
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_CheckAndCallNotification
 * Description   : Check the given callback is not NULL then calls it.
 *
 *END*********************************************************************************/
static inline void Ctu_CheckAndCallNotification(void (*Callback)(void))
{
    if (Callback != NULL_PTR)
    {
        Callback();
    }
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_CheckAndCallFifoNotification
 * Description   : Checks if a given Fifo interrupt was triggered and was not
 * spurious and call the associated callback.
 *
 *END*********************************************************************************/
static inline void Ctu_CheckAndCallFifoNotification(CTU_Type * const CtuBasePtr,
                                                    uint8 FifoIdx,
                                                    uint32 Flag,
                                                    void (*Callback)(void))
{
    uint32 EnFlag     = Flag << (CTU_FCR_FULL_EN1_SHIFT * FifoIdx);
    uint32 StatusFlag = Flag << (CTU_FST_FULL1_SHIFT * FifoIdx);

    EnFlag     &= CtuBasePtr->FCR;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_69();
    StatusFlag &= CtuBasePtr->FST;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_69();

    if ((EnFlag != 0u) && (StatusFlag != 0u))
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_69();
        /* Overrun is the only FIFO interrupt that can be cleared */
        if (Flag == CTU_IP_FIFO_OVERRUN)
        {
           CtuBasePtr->FST = StatusFlag;
        }
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_69();

        Ctu_CheckAndCallNotification(Callback);
    }
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_CheckAndCallTrigNotification
 * Description   : Checks if a given trigger input interrupt was triggered and was not
 * spurious and call the associated callback.
 *
 *END*********************************************************************************/
static inline void Ctu_CheckAndCallTrigNotification(const uint32 Instance,
                                                    CTU_Type * const CtuBasePtr,
                                                    uint8 TrigIdx)
{
    uint16 Mask = (uint16)CTU_IP_NOTIFICATION_FLAG_TRIG_0 << TrigIdx;
    /* Check if the interrupt was triggered */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_70();
    if ((CtuBasePtr->IFR & Mask) != 0u)
    {
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_70();

        /* Check if the interrupt is enabled */
        if ((CtuBasePtr->IR & (CTU_IR_T0_IE_MASK << TrigIdx)) != 0u)
        {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_70();
            /* Clear the interrupt */
            /* CPR_RTD_00644 */
            CtuBasePtr->IFR = Mask;
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_70();
            /* Call the callback */
            Ctu_CheckAndCallNotification(Ctu_Ip_axCtuState[Instance].TrigNotifications[TrigIdx]);
        }
    }
    else
    {
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_70();
    }
}

#ifdef CTU_IP_DMA_SUPPORTED
/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Ctu_FifoSetupDma
 * Description   : Setup the TCD for Dma Channel to use DMA Transfer Result from FIFO.
 *                 Note that FIFO interrupts and DMA should not enables in the same time
 *
 *END*************************************************************************/
static inline void Ctu_FifoSetupDma(const Ctu_Ip_FifoConfigType * const FifoConfig)
{
    Dma_Ip_LogicChannelTransferListType LocTransferList[12U];

    /* Prepare for Software TCD Configuration:
    0. Source Address (SADDR): Point to Address of Ctu Fifo Result Data Register.
    1. Source Transfer Size (SSIZE): Number of bytes to read each time.
    2. Source Address Offset (SOFF): Each source read is completed,
       this value will be added to the current source address (Signed).
    3. Destination Address (DADDR): Point to Result Buffter Pointer.
    4. Destination Transfer Size (DSIZE): Number of bytes to write each time.
    5. Destination Address Offset (DOFF): Each destination write is completed,
       this value will be added to the current destination address (Signed).
    6. Minor Loop Size (NBYTES): number of bytes to transfer per service request.
       Number of bytes of enties FIFO that need to transfer.
    7. Major Loop Count (CITER): Number of minor loop in a major loop.
    8. Last Destination Add Adj (DLAST): this value will be added to the destination address
       at the completion of the major iteration count.
    9. Enable Major Interrupt (INTMAJOR): Enable Interrupt If Major count complete
    10. Enable Half Major Interrupt (INTHALF): Enable Interrupt If Major Counter Half-complete
    11. Disable Automatic Hardware Request (DREQ): clear automatically the ERQ bit
        when the current major iteration count reaches 0 To avoid overwriting any new results
        before this gets processed. Will be re-enabled in notification callback.
    */
    LocTransferList[0].Param  = DMA_IP_CH_SET_SOURCE_ADDRESS;
    LocTransferList[1].Param  = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    LocTransferList[2].Param  = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    LocTransferList[2].Value  = (uint32)0U;
    LocTransferList[3].Param  = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    LocTransferList[3].Value  = (uint32)(FifoConfig->UserFifoBuffer);
    LocTransferList[4].Param  = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    LocTransferList[5].Param  = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    LocTransferList[6].Param  = DMA_IP_CH_SET_MINORLOOP_SIZE;
    LocTransferList[7].Param  = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    LocTransferList[7].Value  = (uint32)(1U);
    LocTransferList[8].Param  = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    LocTransferList[9].Param  = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    LocTransferList[9].Value  = TRUE;
    LocTransferList[10].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
    LocTransferList[10].Value = (uint32)0U;
    LocTransferList[11].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    LocTransferList[11].Value = TRUE;
#ifdef CTU_IP_FIFO_DMA_RAW_EN
    LocTransferList[0].Value  = (uint32)(&IP_CTU->FR[FifoConfig->FifoIndex]);
    LocTransferList[1].Value  = (uint32)2U; /* 4 Bytes. It means read all FIFO Result Data (Raw Data) */
    LocTransferList[4].Value  = (uint32)2U; /* 4 Bytes */
    LocTransferList[5].Value  = (uint32)4U;
    LocTransferList[6].Value  = (4U*((uint32)FifoConfig->FifoThreshold + 1U));
#else
    LocTransferList[0].Value  = (uint32)((uint32)(&IP_CTU->FR[FifoConfig->FifoIndex]) + 2U);
    LocTransferList[1].Value  = (uint32)1U; /* 2 Bytes. It means read FIFO Data Only*/
    LocTransferList[4].Value  = (uint32)1U; /* 2 Bytes */
    LocTransferList[5].Value  = (uint32)2U;
    LocTransferList[6].Value  = (2U*((uint32)FifoConfig->FifoThreshold + 1U));
#endif /* CTU_IP_FIFO_DMA_RAW_EN */
    LocTransferList[8].Value  = ((uint32)(~((uint32)(LocTransferList[6].Value)) + 1U));

    /* Write TCD Configuration for the channel */
    (void)Dma_Ip_SetLogicChannelTransferList(FifoConfig->FifoDmaChannel, LocTransferList, 12U);
    /* Enable Hardware Request for Dma */
    (void)Dma_Ip_SetLogicChannelCommand(FifoConfig->FifoDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}
#endif /* CTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
