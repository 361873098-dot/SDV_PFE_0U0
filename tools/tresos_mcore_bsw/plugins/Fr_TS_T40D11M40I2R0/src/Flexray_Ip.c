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
*   @file Flexray_Ip.c
*   @implements Flexray_Ip.c_Artifact
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
#include "OsIf.h"
#include "Flexray_Ip.h"
#include "Flexray_Ip_Irq.h"
#include "Flexray_Ip_HwAccess.h"
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif

#ifdef FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE
    #if (STD_ON == FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
        #include "RegLockMacros.h"
    #endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_VENDOR_ID_C                        43
#define FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C         4
#define FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C         4
#define FLEXRAY_IP_AR_RELEASE_REVISION_VERSION_C      0
#define FLEXRAY_IP_SW_MAJOR_VERSION_C                 4
#define FLEXRAY_IP_SW_MINOR_VERSION_C                 0
#define FLEXRAY_IP_SW_PATCH_VERSION_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip.h header file are of the same vendor */
#if(FLEXRAY_IP_VENDOR_ID_C != FLEXRAY_IP_VENDOR_ID)
    #error "Flexray_Ip.c and Flexray_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same Autosar version */
#if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip.c and Flexray_Ip.h are different"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same software version */
#if((FLEXRAY_IP_SW_MAJOR_VERSION_C != FLEXRAY_IP_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP_SW_MINOR_VERSION_C != FLEXRAY_IP_SW_MINOR_VERSION) || \
    (FLEXRAY_IP_SW_PATCH_VERSION_C != FLEXRAY_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip.c and Flexray_Ip.h are different"
#endif

/* Check if current file and Flexray_Ip_Irq.h header file are of the same vendor */
#if(FLEXRAY_IP_VENDOR_ID_C != FLEXRAY_IP_IRQ_VENDOR_ID)
    #error "Flexray_Ip.c and Flexray_Ip_Irq.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_Irq.h header file are of the same Autosar version */
#if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip.c and Flexray_Ip_Irq.h are different"
#endif
/* Check if current file and Flexray_Ip_Irq.h header file are of the same software version */
#if((FLEXRAY_IP_SW_MAJOR_VERSION_C != FLEXRAY_IP_IRQ_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP_SW_MINOR_VERSION_C != FLEXRAY_IP_IRQ_SW_MINOR_VERSION) || \
    (FLEXRAY_IP_SW_PATCH_VERSION_C != FLEXRAY_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip.c and Flexray_Ip_Irq.h are different"
#endif

/* Check if current file and Flexray_Ip_HwAccess.h header file are of the same vendor */
#if(FLEXRAY_IP_VENDOR_ID_C != FLEXRAY_IP_HWACCESS_VENDOR_ID)
    #error "Flexray_Ip.c and Flexray_Ip_HwAccess.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_HwAccess.h header file are of the same Autosar version */
#if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip.c and Flexray_Ip_HwAccess.h are different"
#endif
/* Check if current file and Flexray_Ip_HwAccess.h header file are of the same software version */
#if((FLEXRAY_IP_SW_MAJOR_VERSION_C != FLEXRAY_IP_HWACCESS_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP_SW_MINOR_VERSION_C != FLEXRAY_IP_HWACCESS_SW_MINOR_VERSION) || \
    (FLEXRAY_IP_SW_PATCH_VERSION_C != FLEXRAY_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip.c and Flexray_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexray_Ip.c and OsIf.h are different"
    #endif
    #if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
        /* Check if current file and Devassert.h header file are of the same Autosar version */
        #if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Flexray_Ip.c and Devassert.h are different"
        #endif
    #endif

    #ifdef FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE
        #if (STD_ON == FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE)
            /* Check if current file and RegLockMacros.h header file are of the same Autosar version */
            #if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Flexray_Ip.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define FLEXRAY_WMAX_NMVREAD_U8                       ((uint8)5U)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define FR_START_SEC_VAR_CLEARED_32
#include "Fr_MemMap.h"

static uint32 Flexray_Ip_u32uSecondsToTicks; /* implicit zero initialization*/

#define FR_STOP_SEC_VAR_CLEARED_32
#include "Fr_MemMap.h"

#if (FLEXRAY_INSTANCE_COUNT > 0U)

    #define FR_START_SEC_CONST_UNSPECIFIED
    #include "Fr_MemMap.h"
    /*! @brief  Table of base addresses for FR instances. */
    FLEXRAY_Type * const Flexray_Ip_apxBase[FLEXRAY_INSTANCE_COUNT] = IP_FLEXRAY_BASE_PTRS;

    #define FR_STOP_SEC_CONST_UNSPECIFIED
    #include "Fr_MemMap.h"

    #define FR_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Fr_MemMap.h"

    /*! @brief Pointers to FR internal driver state for each instance */
    static Flexray_Ip_StateType* Flexray_Ip_apxState[FLEXRAY_INSTANCE_COUNT];
    static Flexray_Ip_SoftwareStatesType Flexray_Ip_aeDriverStates[FLEXRAY_INSTANCE_COUNT];

    #define FR_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Fr_MemMap.h"
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static void Flexray_InitState(uint8 instNum, const Flexray_Ip_ConfigType* config, const Flexray_Ip_StateAllocateType *stateAlloc);
static void Flexray_InitCC(uint8 instNum, const Flexray_Ip_CcConfigType* ccConfig);
static void Flexray_InitCallback(uint8 instNum, const Flexray_Ip_ConfigType* config);
static Flexray_Ip_StatusType Flexray_Ip_ConfigureIndBuffer(uint8 instNum, Flexray_Ip_IndConfigType* pIndConfig, uint32 indDataOffset);
static void FLEXRAY_ProcessTxMBWhenUpdatedSlotStatus(uint8 instNum, uint8 bufferId);
static boolean FLEXRAY_IndexRxSanityCheck(uint16 phyMbIndex, uint16 objectiveIndex, const FLEXRAY_Type* inst, uint8 mbIndex);
static void FLEXRAY_ProcessRxMBWhenUpdatedSlotStatus(uint8 instNum, uint8 mbIndex,Flexray_Ip_FrameHeaderType* frameHdr, uint8* pData, uint8 pdataLength);
static void Flexray_GetTransmitStatus(const FLEXRAY_Type* inst, uint8 mbIndex , Flexray_Ip_BufferStateType* bState);
static void Flexray_Ip_ConfigureShadowBuffer(uint8 instNum, const Flexray_Ip_ShadowConfigType* pShadowConfig, uint32 shadowDataOffset);
static void Flexray_Ip_SetFiFoRangeFilter(uint8 instNum, const Flexray_Ip_FifoConfigType* fifoConfig);
static Flexray_Ip_StatusType Flexray_Ip_ConfigureRxFiFo(uint8 instNum, boolean isChnB, const Flexray_Ip_FifoConfigType* fifoConfig, uint32 fifoDataOffset);
static void FLEXRAY_CalculateSizeOfSysMemAndFiFoSysMem(uint8 instNum, const Flexray_Ip_ConfigType* config);
static Flexray_Ip_StatusType Flexray_InitBuffer(uint8 instNum, const Flexray_Ip_ConfigType* config);
static inline void Flexray_Ip_CheckDynamicLength(const FLEXRAY_Type* base, const Flexray_Ip_BufferStateType* bState, uint16* pHeaderMB, uint8 dataLength, uint8 mbIndex);
static inline void FLEXRAY_CheckMBasignement(const Flexray_Ip_FrameHeaderType* frameHdr, const boolean *bChnA, const boolean *bChnB, boolean  *bStatusVal);
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
static boolean FLEXRAY_CheckShadowForRxIndBuffer(const Flexray_Ip_ConfigType* config);
static void FLEXRAY_CheckRxIndBufferChannelAppearsOnce(const Flexray_Ip_IndConfigType* pIndConfig, boolean* chanA, boolean* chanB);
static void FLEXRAY_CheckRxIndBufferSegmentAppearsOnce(const Flexray_Ip_IndConfigType* pIndConfig, boolean* seg1, boolean* seg2, uint8 indS1Size);
static void FLEXRAY_CheckShadowBufferAppearsOnce(const Flexray_Ip_ShadowConfigType* pShadowConfig, boolean* shadowSeg1, boolean* shadowSeg2, boolean* shadowChanA, boolean* shadowChanB);
#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

#ifdef FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE
#if (STD_ON == FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the instance accessible
 *                 in user mode.
 *END**************************************************************************/
void Flexray_Ip_SetUserAccessAllowed(const FLEXRAY_Type *base)
{
    SET_USER_ACCESS_ALLOWED((uint32)base, FLEXRAY_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the instance
 *                 accessible in user mode.
 *END**************************************************************************/
void Flexray_Ip_ClrUserAccessAllowed(const FLEXRAY_Type *base)
{
    CLR_USER_ACCESS_ALLOWED((uint32)base, FLEXRAY_PROT_MEM_U32);
}
#endif
#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetCurrentState
 * Description   : This function gets the POC current state of FR.
 *
 * @implements Flexray_Ip_GetCurrentState_Activity
 *END**************************************************************************/
Flexray_Ip_PocStateType Flexray_Ip_GetCurrentState(uint8 instNum)
{
    const FLEXRAY_Type* inst;
    Flexray_Ip_PocStateType retValue = FLEXRAY_STATE_CONFIG;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    switch(((inst->PSR0 & FLEXRAY_PSR0_PROTSTATE_MASK) >> FLEXRAY_PSR0_PROTSTATE_SHIFT))
    {
        case FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_DEFAULT_CONFIG;
            break;

        case FLEXRAY_PSR0_PROTSTATE_CONFIG_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_CONFIG;
            break;

        case FLEXRAY_PSR0_PROTSTATE_WAKEUP_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_WAKEUP;
            break;

        case FLEXRAY_PSR0_PROTSTATE_READY_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_READY;
            break;

        case FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_NORMAL_PASSIVE;
            break;

        case FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_NORMAL_ACTIVE;
            break;

        case FLEXRAY_PSR0_PROTSTATE_STARTUP_U16:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_STARTUP;
            break;

        case FLEXRAY_PSR0_PROTSTATE_HALT_U16:
        default:
            /* Store the POC status to location referenced by given pointer */
            retValue = FLEXRAY_STATE_HALT;
            break;
    }
#ifdef FLEXRAY_AUTOSAR_MODE_USED
    if(Flexray_OccurFreeze(inst))
    {
        retValue = FLEXRAY_STATE_HALT;
    }
#endif

    return retValue;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SendCHICommand
 * Description   : This function sends a controller host interface command for change
 * POC state. It is important for each phase of FR operation.
 *
 * @implements Flexray_Ip_SendCHICommand_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_SendCHICommand(uint8 instNum,
                                                                Flexray_Ip_ChiCmdType cmd)
{
    FLEXRAY_Type* inst;
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    uint32 timeElapsed = 0U;
    uint32 timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    do
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
    }while (FLEXRAY_GetPOCStatus(inst) && (timeElapsed < Flexray_Ip_u32uSecondsToTicks));

    if (timeElapsed < Flexray_Ip_u32uSecondsToTicks)
    {
        FLEXRAY_SetProtocolControlCommand(inst, cmd);
    }
    else
    {
        retValue = FLEXRAY_STATUS_TIMEOUT;
    }

    return retValue;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_WaitPOCState
 * Description   : Wait change POC State
 * @implements Flexray_Ip_WaitPOCState_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_WaitPOCState(uint8 instNum,
                                                              Flexray_Ip_PocStateType pocState)
{
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    uint32 timeElapsed = 0U;
    uint32 timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);

    do
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
    }while((Flexray_Ip_GetCurrentState(instNum) != pocState) && (timeElapsed <= Flexray_Ip_u32uSecondsToTicks));

    if (timeElapsed >= Flexray_Ip_u32uSecondsToTicks)
    {
        retValue = FLEXRAY_STATUS_TIMEOUT;
    }

    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ConfigTimer
 * Description   : This function configures the timer operation.
 *
 * @implements Flexray_Ip_ConfigTimer_Activity
 *END**************************************************************************/
void Flexray_Ip_ConfigTimer(uint8 instNum,
                                            const Flexray_Ip_TimerConfigType* timerCfg)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (timerCfg->timer == FLEXRAY_TIMER1)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_00();

        FLEXRAY_ConfigureTimer1(inst, timerCfg);

        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_00();
    }
    else if (timerCfg->timer == FLEXRAY_TIMER2)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_00();

        FLEXRAY_ConfigureTimer2(inst, timerCfg);

        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_00();
    }
    else
    {
        /* do nothing */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_StartTimer
 * Description   : Start the chosen timer(Timer 1/Timer 2).
 *
 * @implements Flexray_Ip_StartTimer_Activity
 *END**************************************************************************/
void Flexray_Ip_StartTimer(uint8 instNum,
                                           Flexray_Ip_TimerType timer)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (timer == FLEXRAY_TIMER1)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_01();
        FLEXRAY_StartTimer1(inst, TRUE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_01();
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_01();
        FLEXRAY_StartTimer2(inst, TRUE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_01();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_StopTimer
 * Description   : Stop the chosen timer(Timer 1/Timer 2).
 *
 * @implements Flexray_Ip_StopTimer_Activity
 *END**************************************************************************/
void Flexray_Ip_StopTimer(uint8 instNum,
                                          Flexray_Ip_TimerType timer)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (timer == FLEXRAY_TIMER1)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_02();
        FLEXRAY_StopTimer1(inst, TRUE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_02();
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_02();
        FLEXRAY_StopTimer2(inst, TRUE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_02();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetStatusCounter
 * Description   : Configure slot status counter
 *
 * @implements Flexray_Ip_SetStatusCounter_Activity
 *END**************************************************************************/
void Flexray_Ip_SetStatusCounter(uint8 instNum,
                                                 uint8 counterIndex,
                                                 const Flexray_Ip_CounterConfigType* counterConfig)
{

    FLEXRAY_Type* inst;
    uint8 syntaxErrVal, contentErrVal, boudaryViolateVal, transmitConflictVal, multiCycleVal, validFrameOnlyVal, syncFrameOnlyVal, nullFrameOnlyVal, startupFrameOnlyVal, slotStatusMask;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(counterConfig != NULL_PTR);
    DevAssert(counterIndex < FLEXRAY_SSCR_COUNT);
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    /* Counter index value must be less than the supported slot status counter */


    syntaxErrVal = ((counterConfig->syntaxErr) ? 1U : 0U);
    contentErrVal = ((counterConfig->contentErr) ? 1U : 0U);
    boudaryViolateVal = ((counterConfig->boundaryViolate) ? 1U : 0U);
    transmitConflictVal = ((counterConfig->transmitConflict) ? 1U : 0U);
    multiCycleVal = ((counterConfig->multiCycle) ? 1U : 0U);
    validFrameOnlyVal = ((counterConfig->validFrameOnly) ? 1U : 0U);
    syncFrameOnlyVal = ((counterConfig->syncFrameOnly) ? 1U : 0U);
    nullFrameOnlyVal = ((counterConfig->nullFrameOnly) ? 1U : 0U);
    startupFrameOnlyVal  = ((counterConfig->startupFrameOnly) ? 1U : 0U);
    slotStatusMask = (uint8)((syntaxErrVal << 3U) |
                                       (contentErrVal << 2U) |
                                       (boudaryViolateVal << 1U) |
                                       (transmitConflictVal));

    inst->SSCCR = (uint16)(FLEXRAY_SSCCR_SEL(counterIndex) |
                             FLEXRAY_SSCCR_CNTCFG((uint16)(counterConfig->counterInc)) |
                             FLEXRAY_SSCCR_MCY(multiCycleVal) |
                             FLEXRAY_SSCCR_VFR(validFrameOnlyVal) |
                             FLEXRAY_SSCCR_SYF(syncFrameOnlyVal) |
                             FLEXRAY_SSCCR_NUF(nullFrameOnlyVal) |
                             FLEXRAY_SSCCR_SUF(startupFrameOnlyVal) |
                             FLEXRAY_SSCCR_STATUSMASK(slotStatusMask));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetStatusCounter
 * Description   : Get the current value of the Slot Status Counter.
 *
 * @implements Flexray_Ip_GetStatusCounter_Activity
 *END**************************************************************************/
uint16 Flexray_Ip_GetStatusCounter(uint8 instNum,
                                                   uint8 counterIndex)
{

    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(counterIndex < FLEXRAY_SSCR_COUNT);
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    /* Counter index value must be less than the supported slot status counter */
    return (inst->SSCR[counterIndex]);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetProtocolInterrupt
 * Description   : This function disables/enables the chosen protocol interrupt
 *
 * @implements Flexray_Ip_SetProtocolInterrupt_Activity
 *END**************************************************************************/
void Flexray_Ip_SetProtocolInterrupt(uint8 instNum,
                                                     Flexray_Ip_ProtocolIntType pInt,
                                                     boolean enable)
{
    FLEXRAY_Type* inst;
    uint8 tpInt = (uint8)pInt;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (enable)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_03();
        if (tpInt < FLEXRAY_REGISTER_SIZE)
        {
            inst->PIER0 |= (uint16)((uint16)1U << tpInt);
        }
        else
        {
            inst->PIER1 |= (uint16)((uint16)1U << (tpInt % FLEXRAY_REGISTER_SIZE));
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_03();
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_03();
        if (tpInt < FLEXRAY_REGISTER_SIZE)
        {
            inst->PIER0 &= ~(uint16)((uint16)1U << tpInt);
        }
        else
        {
            inst->PIER1 &= ~(uint16)((uint16)1U << (tpInt % FLEXRAY_REGISTER_SIZE));
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_03();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetProtocolInterruptFlag
 * Description   : This function gets individual flag of the chosen protocol  interrupt.
 *
 * @implements Flexray_Ip_GetProtocolInterruptFlag_Activity
 *END**************************************************************************/
boolean Flexray_Ip_GetProtocolInterruptFlag(uint8 instNum,
                                                            Flexray_Ip_ProtocolIntType pInt)
{
    const FLEXRAY_Type* inst;
    uint8 tpInt = (uint8)pInt;
    boolean retValue;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (tpInt < FLEXRAY_REGISTER_SIZE)
    {
        retValue = ((inst->PIFR0 & (uint16)((uint16)1U << tpInt)) != 0U);
    }
    else
    {
        retValue = ((inst->PIFR1 & (uint16)((uint16)1U << (tpInt % FLEXRAY_REGISTER_SIZE))) != 0U);
    }

    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ClearProtocolInterruptFlag
 * Description   : This function clears the chosen protocol interrupt individual flag.
 *
 * @implements Flexray_Ip_ClearProtocolInterruptFlag_Activity
 *END**************************************************************************/
void Flexray_Ip_ClearProtocolInterruptFlag(uint8 instNum,
                                                           Flexray_Ip_ProtocolIntType pInt)
{
    FLEXRAY_Type* inst;
    uint8 tpInt = (uint8)pInt;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (tpInt < FLEXRAY_REGISTER_SIZE)
    {
        inst->PIFR0 = (uint16)((uint16)1U << tpInt);
    }
    else
    {
        inst->PIFR1 = (uint16)((uint16)1U << (tpInt % FLEXRAY_REGISTER_SIZE));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetGlobalInterruptFlag
 * Description   : This function gets flag of the chosen global interrupt.
 *
 * @implements Flexray_Ip_GetGlobalInterruptFlag_Activity
 *END**************************************************************************/
boolean Flexray_Ip_GetGlobalInterruptFlag(uint8 instNum,
                                                          Flexray_Ip_GlobalIntType gInt)
{
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    return ((inst->GIFER & ((uint16)gInt)) != 0U);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetGlobalInterrupt
 * Description   : This function disables/enables the chosen global interrupt.
 *
 * @implements Flexray_Ip_SetGlobalInterrupt_Activity
 *END**************************************************************************/
void Flexray_Ip_SetGlobalInterrupt(uint8 instNum,
                                                   Flexray_Ip_GlobalIntType gInt,
                                                   boolean enable)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    uint16 temp;

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_04();
    temp = inst->GIFER;
    temp &= ~(uint16)(FLEXRAY_GIFER_WUPIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK | FLEXRAY_GIFER_FAFBIF_MASK);

    if (enable)
    {
        temp |= (uint16)((uint16)gInt >> 8U);
        inst->GIFER = temp;
    }
    else
    {
        temp &= ~(uint16)((uint16)gInt >> 8U);
        inst->GIFER = temp;
    }
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_04();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ClearGlobalInterruptFlag
 * Description   : This function clears the chosen global interrupt flag.
 * This function only applies for: Wakeup Interrupt Flag, Receive FIFO Channel B
 * Almost Full Interrupt Flag and Receive FIFO Channel A Almost Full Interrupt Flag.
 *
 * @implements Flexray_Ip_ClearGlobalInterruptFlag_Activity
 *END**************************************************************************/
void Flexray_Ip_ClearGlobalInterruptFlag(uint8 instNum,
                                                         Flexray_Ip_GlobalIntType gInt)
{
    FLEXRAY_Type* inst;
    uint16 temp;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_05();
    temp = inst->GIFER;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert((gInt == FLEXRAY_WAKEUP_INTERRUPT) || (gInt == FLEXRAY_FIFOA_INTERRUPT) || (gInt == FLEXRAY_FIFOB_INTERRUPT));
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    temp &= ~(uint16)(FLEXRAY_GIFER_WUPIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK | FLEXRAY_GIFER_FAFBIF_MASK);
    temp |= ((uint16)gInt);
    inst->GIFER = temp;
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_05();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetCHIInterruptFlag
 * Description   : This function gets flag of the chosen controller host interface interrupt.
 *
 * @implements Flexray_Ip_GetCHIInterruptFlag_Activity
 *END**************************************************************************/
boolean Flexray_Ip_GetCHIInterruptFlag(uint8 instNum,
                                                       Flexray_Ip_ChiIntType cInt)
{
    const FLEXRAY_Type* inst;
    boolean retValue = FALSE;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

   if ((inst->CHIERFR & ((uint16)cInt)) != 0U)
   {
       retValue = TRUE;
   }

   else
   {
       retValue = FALSE;
   }
    return retValue;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ClearCHIInterruptFlag
 * Description   : This function clears the chosen controller host interface interrupt flag.
 *
 * @implements Flexray_Ip_ClearCHIInterruptFlag_Activity
 *END**************************************************************************/
void Flexray_Ip_ClearCHIInterruptFlag(uint8 instNum,
                                                      Flexray_Ip_ChiIntType cInt)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    inst->CHIERFR = (uint16)cInt;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetStatusMonitorSlot
 * Description   : Select one of the four internal slot status selection register for
 * a slot.
 * @implements Flexray_Ip_SetStatusMonitorSlot_Activity
 *END**************************************************************************/
void Flexray_Ip_SetStatusMonitorSlot(uint8 instNum,
                                                     uint8 monitorIndex,
                                                     uint16 slotNumber)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(monitorIndex < 4U);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst->SSSR = FLEXRAY_SSSR_SEL(monitorIndex) | FLEXRAY_SSSR_SLOTNUMBER(slotNumber);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetStatusMonitor
 * Description   : This function gets slot status from slot status monitor
 * a slot.
 * @implements Flexray_Ip_GetStatusMonitor_Activity
 *END**************************************************************************/
uint8 Flexray_Ip_GetStatusMonitor(uint8 instNum,
                                                  uint8 monitorIndex,
                                                  boolean channelA,
                                                  boolean evenCycle)
{
    uint8 slotStatus;
    uint8 slotIdx;
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(monitorIndex < 4U);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    if (evenCycle)
    {
        slotIdx = monitorIndex << 1U;
        slotStatus = FLEXRAY_GetSlotStatus(inst, slotIdx, channelA);
    }
    else
    {
        slotIdx = (monitorIndex << 1U) + 1U;
        slotStatus = FLEXRAY_GetSlotStatus(inst, slotIdx, channelA);
    }

    return slotStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetExternalCorrection
 * Description   : This function applies external rate or offset correction value.
 *
 * @implements Flexray_Ip_SetExternalCorrection_Activity
 *END**************************************************************************/
void Flexray_Ip_SetExternalCorrection(uint8 instNum,
                                                      boolean rateCorrect,
                                                      Flexray_Ip_ExtClkCorrectType correctType)
{
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (rateCorrect)
    {
        FLEXRAY_SetRateCorrection(inst, correctType);
    }
    else
    {
        FLEXRAY_SetOffsetCorrection(inst, correctType);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetMTS
 * Description   : This function enables or disables the generation of the MTS on
 * either channel
 *
 * @implements Flexray_Ip_SetMTS_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_SetMTS(uint8 instNum,
                                                        boolean channelA,
                                                        boolean enable)
{
    FLEXRAY_Type* inst;
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    /* Check POC current state is in NORMAL ACTIVE */
    if (FLEXRAY_STATE_NORMAL_ACTIVE != Flexray_Ip_GetCurrentState(instNum))
    {
        retValue = FLEXRAY_STATUS_ERROR;
    }
    else
    {
        /* Enable/ disable generate MTS */
        FLEXRAY_SetMTS(inst, channelA, enable);
    }

    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetCurrentSlotCounter
 * Description   : This function return current slot counter on channel
 *
 * @implements Flexray_Ip_GetCurrentSlotCounter_Activity
 *END**************************************************************************/
uint16 Flexray_Ip_GetCurrentSlotCounter(uint8 instNum,
                                                        boolean channelA)
{
    const FLEXRAY_Type* inst;
    uint16 slotCounter = 0U;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if (channelA)
    {
        slotCounter = (inst->SLTCTAR & FLEXRAY_SLTCTAR_SLOTCNTA_MASK);
    }
    else
    {
        slotCounter = (inst->SLTCTBR & FLEXRAY_SLTCTBR_SLOTCNTB_MASK);
    }

    return slotCounter;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_InitState
 * Description   : Initiate FR state.
 *
 *END**************************************************************************/
static void Flexray_InitState(uint8 instNum,
                                              const Flexray_Ip_ConfigType* config,
                                              const Flexray_Ip_StateAllocateType *stateAlloc)
{
    Flexray_Ip_StateType* state;
    const Flexray_Ip_IndMemConfigType* indMemConfig = config->indMemConfig;
    Flexray_Ip_IndConfigType* indConfig = config->indBufConfig;

    uint8 i;
    Flexray_Ip_BufferStateType* bufferState = stateAlloc->bufferState;
    Flexray_Ip_BufferStateType** mbStateMap = stateAlloc->mbStateMap;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bufferState != NULL_PTR);
    DevAssert(mbStateMap != NULL_PTR);
    DevAssert(stateAlloc->state != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    Flexray_Ip_apxState[instNum] = stateAlloc->state;
    state = Flexray_Ip_apxState[instNum];
    state->bufferState = stateAlloc->bufferState;
    state->mbStateMap = stateAlloc->mbStateMap;
    state->numShadowBuffer = config->numShadowConfig;
    state->sysMemSize = 0U;
    state->fifoSysMemSize = 0U;
    if ((indMemConfig != NULL_PTR) && (indConfig != NULL_PTR))
    {
        state->numberOfMbUsed = indMemConfig->S1Size + indMemConfig->S2Size;
        state->numberOfBuffer = indMemConfig->TotalBuffers;
    }
    else
    {
        state->numberOfMbUsed = 0U;
        state->numberOfBuffer = 0U;
    }

    /* init state for all ind buffer and mapping bufferState into mbStateMap*/
    for (i = 0U; i < state->numberOfBuffer; i++)
    {
        bufferState[i].bufferId = i;
        bufferState[i].mbId = indConfig[i].MBIndex;
        bufferState[i].status = FLEXRAY_STATUS_UNSUPPORTED;
        bufferState[i].allowDynamicLength = indConfig[i].allowVariableLength;
        bufferState[i].PPI = indConfig[i].PPI;
        bufferState[i].blocking = FALSE;
        bufferState[i].frameHdr = &(indConfig[i].frameHdr);
        bufferState[i].pData = NULL_PTR;
        if(TRUE == indConfig[i].firstInit)
        {
            /* Mapping bufferState into mbStateMap */
            mbStateMap[indConfig[i].MBIndex] = &bufferState[i];
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_InitCC
 * Description   : Initiate communication controller.
 *
 *END**************************************************************************/
static void Flexray_InitCC(uint8 instNum,
                                           const Flexray_Ip_CcConfigType* ccConfig)
{
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    /* at least one channel must be enabled */
    DevAssert(ccConfig->channelA || ccConfig->channelB);
    /* System memory and FiFo system memory should be allocated */
    DevAssert(ccConfig->pSysMem != NULL_PTR);
    /* last 4 bit of address must be zero */
    DevAssert((((uint32)ccConfig->pSysMem) & 0xFU) == 0U);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    /*Disable CC */
    FLEXRAY_EnableCC(inst, FALSE);

    FLEXRAY_SetSysMemAccessTimeout(inst, ccConfig->timeout);

    FLEXRAY_SetModuleConfiguration(inst, ccConfig);

    FLEXRAY_SetSysMemBaseAddr(inst, (uint32)(ccConfig->pSysMem));

    if (ccConfig->memLayout == FLEXRAY_MEM_LAYOUT_DEDICATED)
    {

    #if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
        DevAssert(ccConfig->pFiFoSysMem != NULL_PTR);
    #endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

        FLEXRAY_SetRxFiFoSysMemBaseAddr(inst, (uint32)(ccConfig->pFiFoSysMem));
    }

    FLEXRAY_EnableCC(inst, TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_InitCallback
 * Description   : Enable all callback function if setup.
 *
 *END**************************************************************************/
static void Flexray_InitCallback(uint8 instNum,
                                                 const Flexray_Ip_ConfigType* config)
{
    #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    #endif
    Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];

    if (config->cbConfig != NULL_PTR)
    {
        /* Assign callback function to FR state */
        state->callback.protocolCallback = config->cbConfig->protocolCallback;
        state->callback.chiCallback = config->cbConfig->chiCallback;
        state->callback.wakeupCallback = config->cbConfig->wakeupCallback;
        state->callback.fifoACallback = config->cbConfig->fifoACallback;
        state->callback.fifoBCallback = config->cbConfig->fifoBCallback;
        state->callback.txMBCallback = config->cbConfig->txMBCallback;
        state->callback.rxMBCallback = config->cbConfig->rxMBCallback;

        /* Assign callback parameter to FR state */
        state->callback.wakeupCallbackParam = config->cbConfig->wakeupCallbackParam;
        state->callback.prCallbackParam = config->cbConfig->prCallbackParam;
        state->callback.chiCallbackParam = config->cbConfig->chiCallbackParam;
        state->callback.fifoACallbackParam = config->cbConfig->fifoACallbackParam;
        state->callback.fifoBCallbackParam = config->cbConfig->fifoBCallbackParam;
        state->callback.txCallbackParam = config->cbConfig->txCallbackParam;
        state->callback.rxCallbackParam = config->cbConfig->rxCallbackParam;
    }
    #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
    /* set tx & rx interrupt enable bit */
    FLEXRAY_SetTxMBInterrupt(inst, TRUE);
    FLEXRAY_SetRxMBInterrupt(inst, TRUE);
    #endif

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ConfigureIndBuffer
 * Description   : Configure individual message buffer
 *
 *END**************************************************************************/
static Flexray_Ip_StatusType Flexray_Ip_ConfigureIndBuffer(uint8 instNum,
                                                                           Flexray_Ip_IndConfigType* pIndConfig,
                                                                           uint32 indDataOffset)
{

    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    Flexray_Ip_HeaderDataType * pHeaderData = NULL_PTR;
    Flexray_Ip_HeaderDataType * pBaseHeaderData = NULL_PTR;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_SUCCESS;
    uint32 timeElapsed = 0U;
    uint32 timeStart = 0U;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(pIndConfig != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    pBaseHeaderData = (Flexray_Ip_HeaderDataType *)(FLEXRAY_GetSysMemBaseAddr(inst));

    FLEXRAY_SetMBEnableMode(inst, pIndConfig->MBIndex, FALSE);
    FLEXRAY_SetMBDirection(inst, pIndConfig->MBIndex, pIndConfig->isTx);
    FLEXRAY_SetMBRepeat(inst, pIndConfig->MBIndex, pIndConfig->repeatTx);
    FLEXRAY_SetMBChn(inst, pIndConfig->MBIndex, pIndConfig->channelA, pIndConfig->channelB);
    FLEXRAY_SetCycleCountFilter(inst, pIndConfig->MBIndex, pIndConfig->ccFilter, \
                                 pIndConfig->ccFilterVal, pIndConfig->ccFilterMask);
    FLEXRAY_SetMBFrameId(inst, pIndConfig->MBIndex, pIndConfig->frameID);
    #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
    if (pIndConfig->isTx)
    {
        FLEXRAY_SetMBInterrupt(inst, pIndConfig->MBIndex, TRUE);
    }
    else
    {
        FLEXRAY_SetMBInterrupt(inst, pIndConfig->MBIndex, FALSE);
    }
    #endif

    FLEXRAY_ClearMBFlag(inst, pIndConfig->MBIndex);
    FLEXRAY_SetPhyMBIndex(inst, pIndConfig->MBIndex, pIndConfig->phyMBIndex);
    FLEXRAY_SetMBDataOffset(inst, pIndConfig->phyMBIndex, indDataOffset);

    pHeaderData = &(pBaseHeaderData[pIndConfig->phyMBIndex]);

    /* Pack header individual message buffer */
    if(pIndConfig->isTx)
    {
        if(pIndConfig->frameID <= FLEXRAY_GetNumbOfStaticSlots(inst))
        {
            /*Set payload length for static slots */
            pIndConfig->payloadLength =  (uint8)(FLEXRAY_GetPayloadLengthStatic(inst));
        }
        if(pIndConfig->frameID == FLEXRAY_GetKeySlot(inst))
        {
             Flexray_calCrc(pIndConfig->payloadLength, pIndConfig->frameID, TRUE, TRUE, &(pIndConfig->headerCrc));
        } else
        {
             Flexray_calCrc(pIndConfig->payloadLength, pIndConfig->frameID, FALSE, FALSE, &(pIndConfig->headerCrc));
        }
        (*pHeaderData)[1] = (pIndConfig->PPI ? 0x40U : 0x0U) | ((uint8)(pIndConfig->frameID >> 8U));
        (*pHeaderData)[0] = (uint8) pIndConfig->frameID;
        (*pHeaderData)[2] = pIndConfig->payloadLength;
        (*pHeaderData)[5] = (uint8)(pIndConfig->headerCrc >> 8U);
        (*pHeaderData)[4] = (uint8)(pIndConfig->headerCrc);
    }

    if (pIndConfig->enable)
    {
        FLEXRAY_SetMBEnableMode(inst, pIndConfig->MBIndex, TRUE);
        FLEXRAY_SetMBLockMode(inst, pIndConfig->MBIndex, FALSE);
        FLEXRAY_ClearMBFlag(inst, pIndConfig->MBIndex);
    }
    else
    {
        timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);

        MCAL_FAULT_INJECTION_POINT(T_FR_FIP_MBCCSR0_EDT_FIRST_TIME);
        /* wait until message buffer status is disable */
        while (FLEXRAY_GetMBEnableStatus(inst, pIndConfig->MBIndex) &&
              (timeElapsed < Flexray_Ip_u32uSecondsToTicks))
        {
            FLEXRAY_SetMBEnableMode(inst, pIndConfig->MBIndex, FALSE);
            timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
            MCAL_FAULT_INJECTION_POINT(T_FR_FIP_MBCCSR0_EDT_SECOND_TIME);
        }

        /* Necessary to check if the code hanged in previous loop. */
        if (timeElapsed >= Flexray_Ip_u32uSecondsToTicks)
        {
            ret = FLEXRAY_STATUS_TIMEOUT;
        }
    }
    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_CalculateNumRxFifoBuf
 * Description   : This function returns number of buffers assigned to Fifo
 * structures
 *
 *END**************************************************************************/
static uint16 Flexray_CalculateNumRxFifoBuf(const Flexray_Ip_FifoConfigType* fifoConfigA,
                                                            const Flexray_Ip_FifoConfigType* fifoConfigB)
{
    uint16 numRxFiFoBuf = 0U;
    if (fifoConfigA != NULL_PTR)
    {
        numRxFiFoBuf = fifoConfigA->fifoDepth;
    }

    if (fifoConfigB != NULL_PTR)
    {
        numRxFiFoBuf += fifoConfigB->fifoDepth;
    }
    return numRxFiFoBuf;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_InitBuffer
 * Description   : Initiate all buffer and filter for reception.
 *
 *END**************************************************************************/
static Flexray_Ip_StatusType Flexray_InitBuffer(uint8 instNum,
                                                                const Flexray_Ip_ConfigType* config)
{
    uint8 i = 0U;
    uint8 MbIndex = 0U;
    uint32 indDataOffset = 0U;
    uint32 fifoDataOffset = 0U;
    uint16 numIndBuf = 0U;
    uint16 numRxFiFoBuf = 0U;
    uint32 indDataSize = 0U;
    uint8 numShadowConfig = 0U;
    Flexray_Ip_IndConfigType* pIndConfig = NULL_PTR;
    const Flexray_Ip_ShadowConfigType* pShadowConfig = NULL_PTR;
    Flexray_Ip_IndConfigType* indBufConfig = config->indBufConfig;
    const Flexray_Ip_ShadowConfigType* shadowConfig = config->shadowConfig;
    const Flexray_Ip_IndMemConfigType* indMemConfig = config->indMemConfig;
    const Flexray_Ip_FifoConfigType* fifoConfigA = config->fifoConfigA;
    const Flexray_Ip_FifoConfigType* fifoConfigB = config->fifoConfigB;
    Flexray_Ip_StatusType retConfigFiFoA;
    Flexray_Ip_StatusType retConfigFiFoB;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_SUCCESS;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];

    if ((indMemConfig != NULL_PTR) && (indBufConfig != NULL_PTR))
    {
        numIndBuf = (uint16)((uint16)(indMemConfig->S1Size) + indMemConfig->S2Size);
        indDataSize = (((uint32)((uint32)(indMemConfig->S1DataSize) * indMemConfig->S1Size) + \
                        (uint32)((uint32)(indMemConfig->S2DataSize) * indMemConfig->S2Size)) << 1U);

        if (shadowConfig != NULL_PTR)
        {
            numShadowConfig = config->numShadowConfig;
        }

        numRxFiFoBuf = Flexray_CalculateNumRxFifoBuf(fifoConfigA, fifoConfigB);

        if (config->ccConfig->memLayout == FLEXRAY_MEM_LAYOUT_MIXED)
        {
            indDataOffset = (uint32)(((uint32)numIndBuf + numShadowConfig + numRxFiFoBuf) * FRAME_HEADER_SIZE);
            fifoDataOffset = indDataOffset + indDataSize;

            for (i = 0U; i < numShadowConfig; i++)
            {
                fifoDataOffset += ((uint32)(shadowConfig[i].segment1 ? indMemConfig->S1DataSize : indMemConfig->S2DataSize) << 1U);
            }
        }
        else
        {
            indDataOffset = ((uint32)(((uint32)numIndBuf + numShadowConfig) * FRAME_HEADER_SIZE));
            fifoDataOffset = (uint32)((uint32)numRxFiFoBuf * FRAME_HEADER_SIZE);
        }

        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
        /* Avoid accidentally interrupt */
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_06();
        FLEXRAY_SetTxMBInterrupt(inst, FALSE);
        FLEXRAY_SetRxMBInterrupt(inst, FALSE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_06();
        #endif

    #if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
        DevAssert(TRUE == FLEXRAY_CheckShadowForRxIndBuffer(config));
    #endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

        /* Configure individual message buffer */
        if (indMemConfig->TotalBuffers > 0U)
        {
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_06();
            FLEXRAY_SetSegmentSize(inst, indMemConfig->S1Size, indMemConfig->S2Size);
            FLEXRAY_SetSegmentBuffSize(inst, indMemConfig->S1DataSize, indMemConfig->S2DataSize);
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_06();
            for(MbIndex =0U; MbIndex < numIndBuf ; MbIndex++)
            {
                for (i = 0U; i < indMemConfig->TotalBuffers; i++)
                {
                    if((MbIndex == indBufConfig[i].MBIndex) && (TRUE == indBufConfig[i].firstInit))
                    {
                        pIndConfig = &indBufConfig[i];
                        /* Start critical section: implementation depends on integrator */
                        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_06();
                        /* Check for timeout during individual buffer configuration. */
                        ret = Flexray_Ip_ConfigureIndBuffer(instNum, pIndConfig, indDataOffset);
                        /* End critical section: implementation depends on integrator */
                        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_06();
                        indDataOffset += ((uint32)((pIndConfig->MBIndex < indMemConfig->S1Size) ? indMemConfig->S1DataSize : indMemConfig->S2DataSize) << 1U);
                    }
                }
            }
        }
        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
        /* Enable transfer on bus */
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_06();
        FLEXRAY_SetTxMBInterrupt(inst, TRUE);
        FLEXRAY_SetRxMBInterrupt(inst, TRUE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_06();
        #endif

        /* Configure shadow buffer */
        for (i = 0U; i < numShadowConfig; i++)
        {
            pShadowConfig = &shadowConfig[i];
            Flexray_Ip_ConfigureShadowBuffer(instNum, pShadowConfig, indDataOffset);
            indDataOffset += ((uint32)(pShadowConfig->segment1 ? indMemConfig->S1DataSize : indMemConfig->S2DataSize) << 1U);
        }

        /* Configure FiFo A */
        retConfigFiFoA = Flexray_Ip_ConfigureRxFiFo(instNum, FALSE, fifoConfigA, fifoDataOffset);
        if (retConfigFiFoA == FLEXRAY_STATUS_ERROR)
        {
            ret = FLEXRAY_STATUS_FIFO_A_ERROR_CONFIG;
        }

        if (fifoConfigA != NULL_PTR)
        {
            fifoDataOffset += ((uint32)((uint32)(fifoConfigA->fifoDepth) * fifoConfigA->entrySize) << 1U);
        }

        /* Configure FiFo B */
        retConfigFiFoB = Flexray_Ip_ConfigureRxFiFo(instNum, TRUE, fifoConfigB, fifoDataOffset);

        if (retConfigFiFoB == FLEXRAY_STATUS_ERROR)
        {
            if (retConfigFiFoA != FLEXRAY_STATUS_ERROR)
            {
                ret = FLEXRAY_STATUS_FIFO_B_ERROR_CONFIG;
            }
            else
            {
                ret = FLEXRAY_STATUS_FIFO_AB_ERROR_CONFIG;
            }
        }

        FLEXRAY_CalculateSizeOfSysMemAndFiFoSysMem(instNum, config);
    }
    else
    {
        ret = FLEXRAY_STATUS_ERROR;
    }
    return ret;
}

#ifdef FLEXRAY_AUTOSAR_MODE_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_PowerCycle
 * Description   : This function will power cycle to Fr Controller before init.
 *
 *END**************************************************************************/
static void Flexray_PowerCycle(uint8 instNum)
{
  FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
  if(TRUE == FLEXRAY_IsEnabled(inst))
  {
    if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_FREEZE))
    {
        if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_WaitPOCState(instNum, (Flexray_Ip_PocStateType) FLEXRAY_STATE_HALT))
        {
            if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_DEFAULT_CONFIG))
            {
                if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_WaitPOCState(instNum, (Flexray_Ip_PocStateType) FLEXRAY_STATE_DEFAULT_CONFIG))
                {
                    /* Disable FR CC */
                    FLEXRAY_EnableCC(inst, FALSE);
                }
            }
        }
    }
  }
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_Init
 * Description   : This function will initialize CC, PE, message buffer and rx
 * filter for FR.
 *
 * @implements Flexray_Ip_Init_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_Init(uint8 instNum,
                                                      const Flexray_Ip_ConfigType* config,
                                                      const Flexray_Ip_StateAllocateType *stateAlloc)
{
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_ERROR;
    Flexray_Ip_StatusType retIntBuffer = FLEXRAY_STATUS_SUCCESS;
    FLEXRAY_Type* inst;
    const Flexray_Ip_PeConfigType* peConfig;
    const Flexray_Ip_CcConfigType* ccConfig;
    uint8 u8PocStartAttempts = 255U;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(stateAlloc != NULL_PTR);
    DevAssert(config != NULL_PTR);
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    ccConfig = config->ccConfig;
    peConfig = config->peConfig;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(peConfig != NULL_PTR);
    DevAssert(ccConfig != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    Flexray_Ip_u32uSecondsToTicks = OsIf_MicrosToTicks(FLEXRAY_TIMEOUT_DURATION_US, FLEXRAY_TIMEOUT_TYPE);
#ifdef FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE
#if (STD_ON == FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Set the UAA bit in REG_PROT to make the instance accessible in user mode */
    OsIf_Trusted_Call1param(Flexray_Ip_SetUserAccessAllowed, inst);
#endif
#endif

#ifdef FLEXRAY_AUTOSAR_MODE_USED
    Flexray_PowerCycle(instNum);
    if(FALSE == FLEXRAY_IsEnabled(inst))
    {
#endif
        /* Check POC current state is DEFAULT_CONFIG */
        if (FLEXRAY_STATE_DEFAULT_CONFIG != Flexray_Ip_GetCurrentState(instNum))
        {
            do
            {
                (void) Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_DEFAULT_CONFIG);
                u8PocStartAttempts--;
            } while (( FLEXRAY_STATE_DEFAULT_CONFIG != Flexray_Ip_GetCurrentState(instNum)) && ((uint8)0U < u8PocStartAttempts));
        }

        if (FLEXRAY_STATE_DEFAULT_CONFIG != Flexray_Ip_GetCurrentState(instNum))
        {
            ret = FLEXRAY_STATUS_ERROR;
        }

        else
        {
            Flexray_InitState(instNum, config, stateAlloc);

            /* Initialize Communication Controller */
            Flexray_InitCC(instNum, ccConfig);
            ret = Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_CONFIG);

            if (ret == FLEXRAY_STATUS_SUCCESS)
            {
                ret = Flexray_Ip_WaitPOCState(instNum, FLEXRAY_STATE_CONFIG);
            }

            if (ret == FLEXRAY_STATUS_SUCCESS)
            {
                /* Set MTS cycle filter for both two channels: A & B */
                FLEXRAY_SetMTSFilterChnA(inst, config->mtsfilterChnA);
                FLEXRAY_SetMTSFilterChnB(inst, config->mtsfilterChnB);
                /* Initialize callback for all global interrupt */
                Flexray_InitCallback(instNum, config);
                /* Initialize parameters of protocol engine */
                FLEXRAY_InitPE(instNum, peConfig);
                /* Initialize individual buffer and receive FiFo */
                retIntBuffer = Flexray_InitBuffer(instNum, config);
                /* Set timebase mode for timer 2 */
                FLEXRAY_SetTimebaseModeTimer2(inst, config->timer2IsRelative);
                /* Set timer duration for receive FiFo */
                FLEXRAY_SetFiFoTimerDuration(inst, config->fifoTimerDuration);
                /* Send CONFIG_COMPLETE CHI command to fulfill configuration */
                ret = Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_CONFIG_COMPLETE);

                if (ret == FLEXRAY_STATUS_SUCCESS)
                {
                    ret = Flexray_Ip_WaitPOCState(instNum, FLEXRAY_STATE_READY);

                    if ((peConfig->pKeySlotUsedForStartup) && (peConfig->pKeySlotUsedForSync) && (ret == FLEXRAY_STATUS_SUCCESS))
                    {
                        ret = Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_ALLOW_COLDSTART);
                    }
                }
            }

            if (ret == FLEXRAY_STATUS_SUCCESS)
            {
                if (retIntBuffer != FLEXRAY_STATUS_SUCCESS)
                {
                    ret = retIntBuffer;
                }
                Flexray_Ip_aeDriverStates[instNum] = FLEXRAY_STATE_INIT;
            }
        }

#ifdef FLEXRAY_AUTOSAR_MODE_USED
    }
#endif
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_ClearMemory
 * Description   : This function clears fifo and system memory for de-init
 *
 *END**************************************************************************/
static void Flexray_ClearMemory(uint8 instNum)
{
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    uint8 currentLevel;
    uint32 i;
    uint8* pSysMem = NULL_PTR;
    uint8* pFiFoSysMem = NULL_PTR;

    /* Pop all frames into fifo if exists */
    currentLevel = Flexray_Ip_GetFifoLevel(instNum, TRUE);
    if (currentLevel > 0U)
    {
        FLEXRAY_PopCountFiFo(inst, TRUE, currentLevel);
        Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_FIFOB_INTERRUPT);
    }

    currentLevel = Flexray_Ip_GetFifoLevel(instNum, FALSE);
    if (currentLevel > 0U)
    {
        FLEXRAY_PopCountFiFo(inst, FALSE, currentLevel);
        Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_FIFOA_INTERRUPT);
    }

    /* Clear Flexray memory area */
    if (FLEXRAY_GetMemLayout(inst))
    {
        pSysMem = (uint8 *)FLEXRAY_GetSysMemBaseAddr(inst);
        pFiFoSysMem = (uint8 *)FLEXRAY_GetRxFiFoSysMemBaseAddr(inst);

        for (i = 0U; i < (state->sysMemSize); i++)
        {
            pSysMem[i] = 0U;
        }
        for (i = 0U; i < (state->fifoSysMemSize); i++)
        {
            pFiFoSysMem[i] = 0U;
        }
    }
    else
    {
        pSysMem = (uint8 *)FLEXRAY_GetSysMemBaseAddr(inst);
        for (i = 0U; i < (state->sysMemSize); i++)
        {
            pSysMem[i] = 0U;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_Deinit
 * Description   : Shutdown a Flexray module.
 * This function will disable all message buffer, and disable the Flexray.
 *
 * @implements Flexray_Ip_Deinit_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_Deinit(uint8 instNum)
{
    uint32 i = 0U;
    FLEXRAY_Type* inst;
    uint8 nBuffer;
    uint8 bufferId;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_SUCCESS;
    Flexray_Ip_BufferStateType* bState;
    uint32 timeElapsed = 0U;
    uint32 timeStart = 0U;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    nBuffer = Flexray_Ip_apxState[instNum]->numberOfBuffer;
    bState = Flexray_Ip_apxState[instNum]->bufferState;

    /* Disable all message buffer */
    for (i = 0U; i < nBuffer; i++)
    {
        bufferId = bState[i].bufferId;
        timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
        while ((FLEXRAY_GetMBEnableStatus(inst, bufferId)) && (timeElapsed < Flexray_Ip_u32uSecondsToTicks))
        {
            FLEXRAY_SetMBEnableMode(inst, bufferId, FALSE);
            bState[i].frameHdr = NULL_PTR;
            bState[i].pData = NULL_PTR;
            timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
        }
        if (timeElapsed >= Flexray_Ip_u32uSecondsToTicks)
        {
            ret = FLEXRAY_STATUS_TIMEOUT;
            break;
        }
    }

    /* Disable all protocol and global interrupts */
    FLEXRAY_DisableAllProtocolInterrupt(inst);
    FLEXRAY_DisableAllGlobalInterrupt(inst);

    /* Clear interrupt flags */
    FLEXRAY_ClearAllProtocolInterruptFlag(inst);
    Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_WAKEUP_INTERRUPT);
    Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_FIFOA_INTERRUPT);
    Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_FIFOB_INTERRUPT);
    FLEXRAY_ClearAllCHIErrorInterruptFlag(inst);

    /* Disable MTS for channel A & B */
    (void)Flexray_Ip_SetMTS(instNum, TRUE, FALSE);
    (void)Flexray_Ip_SetMTS(instNum, FALSE, FALSE);

    /* Set FR module to POC:HALT state */
    /* The POC state is not updated to register if the FREEZE occurred */
    if (ret == FLEXRAY_STATUS_SUCCESS)
    {
        ret = Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_FREEZE);
    }

    /* Wait time to occur freeze and transfer to POC:HALT successfully */
    if (ret == FLEXRAY_STATUS_SUCCESS)
    {
        timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);
        timeElapsed = 0U;
        do
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
        }while((!Flexray_OccurFreeze(inst)) &&(timeElapsed < Flexray_Ip_u32uSecondsToTicks));

        if (timeElapsed >= Flexray_Ip_u32uSecondsToTicks)
        {
            ret = FLEXRAY_STATUS_TIMEOUT;
        }
    }

    /* Set FR module to POC:DEFAULT CONFIG state for disable module */
    if (ret == FLEXRAY_STATUS_SUCCESS)
    {
        ret = Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_DEFAULT_CONFIG);
    }

    if (ret == FLEXRAY_STATUS_SUCCESS)
    {
        /* Wait DEFAUT_CONFIG POC state */
        ret = Flexray_Ip_WaitPOCState(instNum, FLEXRAY_STATE_DEFAULT_CONFIG);
    }

    if (ret == FLEXRAY_STATUS_SUCCESS)
    {
        /* Disable module */
        Flexray_Ip_aeDriverStates[instNum] = FLEXRAY_STATE_UNINIT;
        FLEXRAY_EnableCC(inst, FALSE);
        Flexray_ClearMemory(instNum);
    #ifdef FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE
    #if (STD_ON == FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        /* Clear the UAA bit in REG_PROT to reset the elevation requirement */
        OsIf_Trusted_Call1param(Flexray_Ip_ClrUserAccessAllowed, inst);
    #endif
    #endif
    }

    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_ProcessTxMBWhenUpdatedSlotStatus
 * Description   : Process tx message buffer when the interrupt flag of this message buffer is raised
 *
 *END**************************************************************************/
static void FLEXRAY_ProcessTxMBWhenUpdatedSlotStatus(uint8 instNum,
                                                                     uint8 bufferId)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    const FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    uint8 mbIndex = state->bufferState[bufferId].mbId;
    Flexray_Ip_BufferStateType* bState = state->mbStateMap[mbIndex];
    if(FLEXRAY_IsMBTx(inst, mbIndex))
    {
        if (bState->status == FLEXRAY_STATUS_BUSY)
        {
            /* Read Status of TX buffer */
            Flexray_GetTransmitStatus(inst, mbIndex , bState);
            #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
            /* Disable interrupt */
            FLEXRAY_SetMBInterrupt((FLEXRAY_Type*)inst, mbIndex, FALSE);
            #endif
            if (state->callback.txMBCallback != NULL_PTR)
            {
                state->callback.txMBCallback(bufferId, state->callback.txCallbackParam);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_IndexRxSanityCheck
 * Description   : Sanity check for index and Rx flag
 *
 *END**************************************************************************/
static boolean FLEXRAY_IndexRxSanityCheck(uint16 phyMbIndex, 
                                                                 uint16 objectiveIndex, 
                                                                 const FLEXRAY_Type* inst, 
                                                                 uint8 mbIndex
                                                                )
{
    boolean retValue = FALSE;
    /* Check whether the read value not greater than the last utilized MB index */
    if(phyMbIndex < objectiveIndex)
    {
        /* Message buffer configured for Rx ? */
        if(!FLEXRAY_IsMBTx(inst, mbIndex))
        {
            retValue = TRUE;
        }
    }
    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_ProcessRxMBWhenUpdatedSlotStatus
 * Description   : Process Rx message buffer
 *
 *END**************************************************************************/
static void FLEXRAY_ProcessRxMBWhenUpdatedSlotStatus(uint8 instNum,
                                                                     uint8 mbIndex,
                                                                     Flexray_Ip_FrameHeaderType* frameHdr,
                                                                     uint8* pData,
                                                                     uint8 pdataLength)
{
    uint16 phyMbIndex;
    uint16 objMbIdx;
    boolean  bStatusVal = FALSE;
    Flexray_Ip_HeaderDataType* pBaseHeaderData;
    Flexray_Ip_HeaderDataType* pHeaderData;
    const uint16* pFrameData;
    FLEXRAY_Type* inst;
    boolean bChnA;
    boolean bChnB;
    uint8 index;
    uint16_t dataIndex;
    const Flexray_Ip_StateType* state;
    Flexray_Ip_BufferStateType* bState;
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
    DevAssert(frameHdr != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    inst = Flexray_Ip_apxBase[instNum];

    state = Flexray_Ip_apxState[instNum];

    bState = state->mbStateMap[mbIndex];
    bState->frameHdr = frameHdr;
    pBaseHeaderData = (Flexray_Ip_HeaderDataType *)(FLEXRAY_GetSysMemBaseAddr(inst));
    /* Load current MB index - the original value of mbIndex is replaced by the index of mess. buffer header field */
    phyMbIndex = FLEXRAY_GetPhyMBIndex(inst, mbIndex);
    objMbIdx = (uint16)((uint16)(state->numberOfMbUsed) + state->numShadowBuffer);
    if(FLEXRAY_IndexRxSanityCheck(phyMbIndex, objMbIdx, inst, mbIndex))
    {
            if(FLEXRAY_GetMBDataUpdate(inst,mbIndex))
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_01();
                /* Lock Rx MB */
                FLEXRAY_SetMBLockMode(inst,mbIndex, TRUE);
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_01();
                /* Read the MB again to check if the MB is locked, */
                if(FLEXRAY_GetMBLockStatus(inst, mbIndex))
                {   /* MB is locked */
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
                    DevAssert(pBaseHeaderData != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
                    Flexray_UnpackMessageBufferHeader((Flexray_Ip_HeaderDataType *)&(pBaseHeaderData[phyMbIndex]), frameHdr);
                    FLEXRAY_GetMBChn(inst, mbIndex ,&bChnA,&bChnB);
#if(FLEXRAY_RXSTRINGENTLENGTHCHECK == STD_ON)
                    /* Payload data length is also limited by Rx MB configuration */
                    if(frameHdr->payloadLength == pdataLength)
                    {
#else
                        /* Copy only limited length of data */
                        if(frameHdr->payloadLength > pdataLength)
                        {
                            frameHdr->payloadLength = pdataLength;
                        }
#endif /* FLEXRAY_RX_STRINGENT_LENGTH_CHECK */

                        /* Check MB and update bStatusVal */
                        FLEXRAY_CheckMBasignement(frameHdr, &bChnA, &bChnB, &bStatusVal);
                        if(TRUE ==  bStatusVal)
                        {
                            pHeaderData = (Flexray_Ip_HeaderDataType *)FLEXRAY_GetSysMemBaseAddr(inst);
                            pFrameData = (uint16*)((uint32)((uint64)FLEXRAY_GetMBDataOffset(inst, phyMbIndex) + (uint32)pHeaderData));

                            dataIndex = 0U;
                            for(index = 0U; index < (uint8)(frameHdr->payloadLength); index++)
                            {
                                /* Store 16bit pFrameData[] as MSB first in pData. */
                                pData[dataIndex] = (uint8)(pFrameData[index] >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32);
                                pData[dataIndex + (uint8)1U] = (uint8)pFrameData[index];
                                dataIndex += (uint8)2U;
                            }
                            bState->slotStatusError = FALSE;
                            bState->status = FLEXRAY_STATUS_SUCCESS;
                        }
                        else
                        {
                            bState->status = FLEXRAY_STATUS_ERROR;
                            bState->slotStatusError = TRUE;
                        }
#if(FLEXRAY_RXSTRINGENTLENGTHCHECK == STD_ON)
                    }
                    else
                    {
                        bState->status = FLEXRAY_STATUS_ERROR;
                        bState->slotStatusError = FALSE;
                    }
#endif /* FLEXRAY_RX_STRINGENT_LENGTH_CHECK */
                    /* Start critical section: implementation depends on integrator */
                    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_08();
                    /* Unlock MB */
                    FLEXRAY_SetMBLockMode(inst, mbIndex, FALSE);

#ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
                    /* Disable interrupt */
                    FLEXRAY_SetMBInterrupt(inst, mbIndex, FALSE);
#endif
                    /* End critical section: implementation depends on integrator */
                    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_08();
                }
            }
            else    /* MBIF == 0 of DUP == 0 (data already read or no valid frame received) */
            {
                bState->status = FLEXRAY_STATUS_ERROR;
                bState->slotStatusError = FALSE;
            }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_CheckMBasignement
 * Description   : Goes through each slotStatus and checks if the
 *                 MB is assigned to a channel.
 *END**************************************************************************/
static void FLEXRAY_CheckMBasignement(const Flexray_Ip_FrameHeaderType* frameHdr,
                                                      const boolean *bChnA,
                                                      const boolean *bChnB,
                                                      boolean  *bStatusVal)
{

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(frameHdr != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    if((TRUE == *bChnA) && (TRUE == *bChnB))
    {
        /* MB is assigned to channels AB */
        /* Check Slot Status information */
        if((0x080U == (frameHdr->slotStatus & FLEXRAY_STRINGENT_MASK_A)) || ( 0x8000U ==(frameHdr->slotStatus & FLEXRAY_STRINGENT_MASK_B)))
        {
             *bStatusVal = TRUE;
        }
    }
    else if(TRUE == *bChnA)
    {
        /* MB is assigned to channel A */
        /* Check Slot Status information */
        if(0x0080U == ( frameHdr->slotStatus & FLEXRAY_STRINGENT_MASK_A))
        {
             *bStatusVal = TRUE;
        }
    }
    else
    {
        /* MB is assigned to channel B */
        /* Check Slot Status information */
        if(0x8000U == ( frameHdr->slotStatus & FLEXRAY_STRINGENT_MASK_B))
        {
             *bStatusVal = TRUE;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_Send
 * Description   : This function will sends a FR frame using a configured message
 * buffer. The function returns status immediately and assigned to buffer state.
 * If a callback is installed, it will be invoked after the frame was sent.
 *
 * @implements Flexray_Ip_Send_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_Send(uint8 instNum,
                                                      uint8 bufferId,
                                                      const uint8* pData,
                                                      uint8 dataLength)
{
    Flexray_Ip_StatusType res;
    const Flexray_Ip_StateType* state;
    FLEXRAY_Type* base;
    Flexray_Ip_HeaderDataType* pHeaderData;
    uint16* pHeaderMB;
    uint8* pFrameData;
    uint8 mbIndex;
    uint16 phyMbIndex;
    boolean eds, lcks;
    uint8 tempDataLength;

    uint8 u8tmpdata;
    uint16 u16tmpdata;
    uint32 u32tmpdata;

    #ifdef FLEXRAY_UNUSED_BIT_VALUE_U16
    uint8 tempPayloadLength;
    #endif
    Flexray_Ip_BufferStateType* bState;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    state = Flexray_Ip_apxState[instNum];
    base = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state->numberOfBuffer > 0U);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    /* read Mb index thought bufferId*/
    mbIndex = state->bufferState[bufferId].mbId;
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
    DevAssert(dataLength > 0UL);
    DevAssert(pData != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    /* Check mbId and mbIndex to verify that resource are correctly assigned */
    if( mbIndex == bState->mbId)
    {
#endif
        /* Check if this is transmit message buffer */
        if(TRUE == FLEXRAY_IsMBTx(base, mbIndex))
        {
            #ifndef FLEXRAY_AUTOSAR_MODE_USED
            if (bState->status != FLEXRAY_STATUS_BUSY)
            {
            #endif
                /* Get data buffer index */
                phyMbIndex = FLEXRAY_GetPhyMBIndex(base, mbIndex);
                if(phyMbIndex < (uint16)((uint16)(state->numberOfMbUsed) + state->numShadowBuffer))
                {
                    /* Start critical section: implementation depends on integrator */
                    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_09();
                    #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
                    /* Disable MB interrupt */
                    FLEXRAY_SetMBInterrupt(base, mbIndex, FALSE);
                    #endif

                    /* Clear Message Buffer Interrupt Flag */
                    FLEXRAY_ClearMBFlag(base, mbIndex);
                    /* End critical section: implementation depends on integrator */
                    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_09();
                    /* Header field */
                    pHeaderData = (Flexray_Ip_HeaderDataType*)FLEXRAY_GetSysMemBaseAddr(base);

                    pHeaderMB = (uint16*)(&(pHeaderData[mbIndex]));
                    /* Prepare message buffer data */
                    pFrameData = (uint8*)((uint32)((uint64)FLEXRAY_GetMBDataOffset(base, phyMbIndex) + (uint32)pHeaderData));

                    /* Get lock and enable status of message buffer */
                    eds = FLEXRAY_GetMBEnableStatus(base, mbIndex);

                    /* Start critical section: implementation depends on integrator */
                    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_09();
                    /* Lock individual buffer */
                    FLEXRAY_SetMBLockMode(base, mbIndex, TRUE);
                    lcks = FLEXRAY_GetMBLockStatus(base, mbIndex);

                    /* End critical section: implementation depends on integrator */
                    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_09();
                    /* Check if we can modify buffer data */
                    if((!eds) || lcks)
                    {
                        for(tempDataLength = 0U; tempDataLength < (dataLength >> 2U); tempDataLength++)
                        {
                            ((uint32*)pFrameData)[tempDataLength] = ((const uint32 *)pData)[tempDataLength];
                            /* Low byte first. */
                            u32tmpdata = ((uint32*)pFrameData)[tempDataLength];
                            u32tmpdata = (uint32)(((uint32)(u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((uint32)(u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
                            ((uint32*)pFrameData)[tempDataLength] = u32tmpdata;
                        }
                        tempDataLength = (uint8)((tempDataLength * 2U) & 0xFFU);
                        if(tempDataLength < (dataLength >> 1U))
                        {
                            ((uint16*)pFrameData)[tempDataLength] = ((const uint16 *)pData)[tempDataLength];
                            /* Low byte first. */
                            u16tmpdata = ((uint16*)pFrameData)[tempDataLength];
                            u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
                            ((uint16*)pFrameData)[tempDataLength] = u16tmpdata;
                            tempDataLength++;
                        }

                        tempDataLength = (uint8)((tempDataLength * 2U) & 0xFFU);

                        if(tempDataLength < dataLength)
                        {
                            pFrameData[tempDataLength] = pData[tempDataLength];
                            tempDataLength++;

                            #ifdef FLEXRAY_UNUSED_BIT_VALUE_U8
                            pFrameData[tempDataLength] = FLEXRAY_UNUSED_BIT_VALUE_U8;
                            #endif /* FLEXRAY_UNUSED_BIT_VALUE_U8 */

                            /* Low byte first. */
                            u8tmpdata = pFrameData[tempDataLength];
                            pFrameData[tempDataLength] = pFrameData[tempDataLength - (uint8)1U];
                            pFrameData[tempDataLength - (uint8)1U] = u8tmpdata;
                        }

                        #ifdef FLEXRAY_UNUSED_BIT_VALUE_U16
                        tempDataLength++;
                        if(FLEXRAY_GetMBFrameId(base,mbIndex) < FLEXRAY_GetNumbOfStaticSlots(base))
                        {
                            tempPayloadLength = FLEXRAY_GetPayloadLengthStatic(base);
                            for(tempDataLength = (tempDataLength >> 1U); tempDataLength < tempPayloadLength ; tempDataLength ++)
                            {
                                ((uint16*)pFrameData)[tempDataLength] = FLEXRAY_UNUSED_BIT_VALUE_U16 ;
                            }
                        }
                        #endif

                        /* Check if the dynamic length is allow and compute the necessary CRC if needed. */
                        Flexray_Ip_CheckDynamicLength(base, bState, pHeaderMB, dataLength, mbIndex);

                        /* Start critical section: implementation depends on integrator */
                        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_09();
                        FLEXRAY_SetMBTrasmitReady(base, mbIndex, TRUE);

                        if(!eds)
                        {
                            FLEXRAY_SetMBEnableMode(base, mbIndex, TRUE);
                        }
                        FLEXRAY_SetMBLockMode(base, mbIndex, FALSE);
                        /* End critical section: implementation depends on integrator */
                        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_09();
                        res = FLEXRAY_STATUS_SUCCESS;
                    }
                    else
                    {
                        res = FLEXRAY_STATUS_ERROR;
                    }

                    bState->status = FLEXRAY_STATUS_BUSY;
                    if(bState->blocking == FALSE)
                    {
                        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
                        /* Start critical section: implementation depends on integrator */
                        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_09();
                        /* Enable MB interrupt */
                        FLEXRAY_SetMBInterrupt(base, mbIndex, TRUE);
                        /* End critical section: implementation depends on integrator */
                        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_09();
                        #endif
                    }
                }
                else
                {
                    res = FLEXRAY_STATUS_ERROR;
                }
            #ifndef FLEXRAY_AUTOSAR_MODE_USED
            } else
            {
                res = FLEXRAY_STATUS_ERROR;
            }
            #endif
        }
        else
        {
            res = FLEXRAY_STATUS_ERROR;
        }
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    }
    else
    {
        res = FLEXRAY_STATUS_ERROR;
    }
#endif
    return res;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_CheckDynamicLength
 * Description   : Checks if the dynamic length is allowed and computes the
                   necessary CRC when needed.
 *END**************************************************************************/
static inline void Flexray_Ip_CheckDynamicLength(const FLEXRAY_Type* base,
                                                                 const Flexray_Ip_BufferStateType* bState,
                                                                 uint16* pHeaderMB,
                                                                 uint8 dataLength,
                                                                 uint8 mbIndex)
{
    uint8 tempDataLength;
    uint16 frameId;

    if(TRUE == bState->allowDynamicLength)
    {
        tempDataLength= dataLength>>1U;
        if(0U != (dataLength % 2U))
        {
            tempDataLength++;
        }
        if(pHeaderMB[1U] != tempDataLength)
        {
            pHeaderMB[1U] = tempDataLength;
            frameId = FLEXRAY_GetMBFrameId(base,mbIndex);
            if(frameId == FLEXRAY_GetKeySlot(base))
            {
                 Flexray_calCrc(tempDataLength, frameId, TRUE, TRUE, (uint16*) &pHeaderMB[2U]);
            } else
            {
                 Flexray_calCrc(tempDataLength, frameId, FALSE, FALSE, (uint16*) &pHeaderMB[2U]);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SendBlocking
 * Description   : This function sends a FR frame using a configured message
 * buffer. The function blocks until either the frame was sent, or the specified
 * timeout expired. If happens timeout, abort the transmit message buffer immediately.
 *
 * @implements Flexray_Ip_SendBlocking_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_SendBlocking(uint8 instNum,
                                                              uint8 bufferId,
                                                              const uint8* pData,
                                                              uint8 dataLength,
                                                              uint32 timeout_ms)
{

    FLEXRAY_Type* inst;
    const Flexray_Ip_StateType* state;
    Flexray_Ip_BufferStateType* bState;
    Flexray_Ip_StatusType result = FLEXRAY_STATUS_SUCCESS;
    Flexray_Ip_StatusType res;
    uint8 mbIndex;
    uint32 timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);
    uint32 timeElapsed = 0U;
    uint32 mS2Ticks = OsIf_MicrosToTicks((timeout_ms * 1000U), FLEXRAY_TIMEOUT_TYPE);

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    state = Flexray_Ip_apxState[instNum];


#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state->numberOfBuffer > 0U);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    mbIndex = state->bufferState[bufferId].mbId;
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
    DevAssert(FLEXRAY_IsMBTx(inst, mbIndex) == TRUE);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    bState->blocking = TRUE;
    (void) Flexray_Ip_Send(instNum, bufferId, pData, dataLength);
    bState->blocking = FALSE;

    while(FLEXRAY_GetMBFlag(inst, mbIndex) != TRUE)
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
        if (timeElapsed >= mS2Ticks)
        {
            result = FLEXRAY_STATUS_TIMEOUT;
            break;
        }
    }

    if (result == FLEXRAY_STATUS_TIMEOUT)
    {
        /* Stop transmit anyway by clearing CMT bit */
        FLEXRAY_SetMBTrasmitReady(inst, mbIndex, FALSE);

        bState->status = FLEXRAY_STATUS_TIMEOUT;
        res = FLEXRAY_STATUS_TIMEOUT;
    }
    else
    {
        Flexray_GetTransmitStatus(inst, mbIndex, bState);
        res = bState->status;
        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
        /* Enable MB interrupt */
        FLEXRAY_SetMBInterrupt(inst, mbIndex, TRUE);
        #endif
    }

    return res;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ReceiveInd
 * Description   : This function will receives a FR frame into a configured message
 * buffer. The function returns status immediately and assigned to buffer state.
 * If a callback is installed, it will be invoked after the frame was received.
 *
 * @implements Flexray_Ip_ReceiveInd_Activity
 *END**************************************************************************/
void Flexray_Ip_ReceiveInd(uint8 instNum,
                                           uint8 bufferId,
                                           Flexray_Ip_FrameHeaderType* frameHdr,
                                           uint8* pData,
                                           uint8 dataLength)
{
    FLEXRAY_Type* base;
    uint8 mbIndex;
    const Flexray_Ip_StateType* state;
    Flexray_Ip_BufferStateType* bState;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    base = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    state = Flexray_Ip_apxState[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state->numberOfBuffer > 0U);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    mbIndex = state->bufferState[bufferId].mbId;
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
    DevAssert(pData != NULL_PTR);
    DevAssert(frameHdr != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    /* Check mbId and mbIndex to verify that resource are correctly assigned */
    if( mbIndex == bState->mbId)
    {
#endif
        /* Check if this is receive message buffer */
        if(FALSE == FLEXRAY_IsMBTx(base, mbIndex))
        {
            #ifndef FLEXRAY_AUTOSAR_MODE_USED
            /* If message buffer is aborted formerly, enable again rx message buffer */
            if((bState->status) == FLEXRAY_STATUS_ABORTED)
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_07();
                FLEXRAY_SetMBEnableMode(base, mbIndex, TRUE);
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_07();
            }
            #endif
            bState->status = FLEXRAY_STATUS_BUSY;

            /* Check new data for rx message buffer */
            if (FLEXRAY_GetMBFlag(base, mbIndex))
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_07();
                FLEXRAY_ClearMBFlag(base, mbIndex);
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_07();
                FLEXRAY_ProcessRxMBWhenUpdatedSlotStatus(instNum, mbIndex, frameHdr, pData, dataLength);
            }
#ifdef FLEXRAY_AUTOSAR_MODE_USED
            else
            {
                bState->status = FLEXRAY_STATUS_ERROR;
            }
#else
            else
            {
                bState->frameHdr = frameHdr;
                bState->pData = pData;
                bState->dataLength = dataLength;
                #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
                /* Enable MB interrupt */
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_07();
                FLEXRAY_SetMBInterrupt(base, mbIndex, TRUE);
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_07();
                #endif
            }
#endif
        }
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    }
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ReceiveIndBlocking
 * Description   : This function will receives a FR frame into a configured message
 * buffer. The function blocks until either a frame was received, or the
 * specified timeout expired.
 *
 * @implements Flexray_Ip_ReceiveIndBlocking_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_ReceiveIndBlocking(uint8 instNum,
                                                                    uint8 bufferId,
                                                                    Flexray_Ip_FrameHeaderType* frameHdr,
                                                                    uint8* pData,
                                                                    uint8 dataLength,
                                                                    uint32 timeout_ms)
{

    FLEXRAY_Type* inst;
    Flexray_Ip_StatusType result = FLEXRAY_STATUS_SUCCESS;
    Flexray_Ip_StatusType res;
    const Flexray_Ip_StateType* state;
    Flexray_Ip_BufferStateType* bState;
    uint8 mbIndex;
    uint32 timeStart = OsIf_GetCounter(FLEXRAY_TIMEOUT_TYPE);
    uint32 timeElapsed = 0U;
    uint32 mS2Ticks = OsIf_MicrosToTicks((timeout_ms * 1000U), FLEXRAY_TIMEOUT_TYPE);

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    state = Flexray_Ip_apxState[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    mbIndex = state->bufferState[bufferId].mbId;
    bState = state->mbStateMap[mbIndex];
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
    DevAssert(FALSE == FLEXRAY_IsMBTx(inst, mbIndex));
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    /* If message buffer is aborted formerly, enable again rx message buffer */
    if((bState->status) == FLEXRAY_STATUS_ABORTED)
    {
        bState->status = FLEXRAY_STATUS_BUSY;
        FLEXRAY_SetMBEnableMode(inst, mbIndex, TRUE);
    }

    while(FLEXRAY_GetMBFlag(inst, mbIndex) != TRUE)
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXRAY_TIMEOUT_TYPE);
        if (timeElapsed >= mS2Ticks)
        {
            result = FLEXRAY_STATUS_TIMEOUT;
            break;
        }
    }
    if (result == FLEXRAY_STATUS_TIMEOUT)
    {
        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
        /* disable RxMB interrupt */
        FLEXRAY_SetMBInterrupt(inst, bufferId, FALSE);
        #endif
        bState->status = FLEXRAY_STATUS_TIMEOUT;
        res = FLEXRAY_STATUS_TIMEOUT;
    }
    else
    {
        Flexray_Ip_ReceiveInd(instNum, bufferId, frameHdr, pData, dataLength);
        res = bState->status;
    }
    return res;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ReceiveFIFO
 * Description   : This function receives a FR frame using the Rx FIFO. The
 * function returns immediately. If a callback is installed, it will be invoked
 * after the frame was received and read into the specified buffer.
 *
 * @implements Flexray_Ip_ReceiveFIFO_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_ReceiveFIFO(uint8 instNum,
                                                             boolean channel,
                                                             Flexray_Ip_FrameHeaderType* frameHdr,
                                                             uint8* pData ,
                                                             uint8 dataLength)
{
    Flexray_Ip_HeaderDataType* pHeaderData;
    const uint16* pFrameData;
    uint32 index, dataIndex;
    uint16 mbIndex;
    uint8 fillLevel;
    uint16 fifoDataOff;
    uint32 fifoCurrentDataOff;
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    FLEXRAY_Type* inst;
    boolean bReceive;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
    DevAssert(dataLength > 0UL);
    DevAssert(pData != NULL_PTR);
    DevAssert(frameHdr != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    /* Select FIFO */
    FLEXRAY_SetFiFoChn(inst, channel);

    fillLevel = FLEXRAY_FillLevelFiFo(inst, channel);

    /* Check if we can read buffer data */
    if(fillLevel > 0U)
    {
        if(!FLEXRAY_GetMemLayout(inst))
        {
            /* Read data from header field */
            pHeaderData = (Flexray_Ip_HeaderDataType *)(FLEXRAY_GetSysMemBaseAddr(inst));
        }
        else
        {
            /* Read data from header field */
            pHeaderData = (Flexray_Ip_HeaderDataType *)(FLEXRAY_GetRxFiFoSysMemBaseAddr(inst));
        }

        if(FALSE == channel)
        {
            mbIndex = FLEXRAY_ReceiveFiFoAReadIdx(inst);
        } else
        {
            mbIndex = FLEXRAY_ReceiveFiFoBReadIdx(inst);
        }
        Flexray_UnpackMessageBufferHeader((Flexray_Ip_HeaderDataType *)&(pHeaderData[mbIndex]), frameHdr);
        #if(FLEXRAY_RXSTRINGENTLENGTHCHECK == STD_ON)
        if(frameHdr->payloadLength == dataLength)
        {
        #else
            if(frameHdr->payloadLength > dataLength)
            {
                frameHdr->payloadLength = dataLength;
            }
        #endif
            bReceive = FALSE;
            if(FALSE == channel)
            {
                if(0x0080U == (frameHdr->slotStatus & FLEXRAY_STRINGENT_MASK_A))
                {
                    bReceive = TRUE;
                }
            }
            else
            {
                if(0x8000U == (frameHdr->slotStatus & FLEXRAY_STRINGENT_MASK_B))
                {
                    bReceive = TRUE;
                }
            }
            if(TRUE == bReceive)
            {
                /* Get data buffer index in fifo buffer data */
                mbIndex -= FLEXRAY_GetFiFoStartIdx(inst);
                fifoDataOff = (uint16)FLEXRAY_GetFiFoDataOffset(inst);
                fifoCurrentDataOff = (uint32)((uint32)(mbIndex * (uint32)FLEXRAY_GetFiFoEntrySize(inst)) << 1U);
                pFrameData = (uint16*)((uint32)pHeaderData + fifoDataOff + fifoCurrentDataOff);
                /* Copy data in MB */
                dataIndex = 0U;
                for(index = 0U; index < frameHdr->payloadLength; index++)
                {
                    /* Store 16bit pFrameData[] as MSB first in pData. */
                    pData[dataIndex] = (uint8)(pFrameData[index] >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32);
                    pData[dataIndex + (uint8)1U] = (uint8)pFrameData[index];
                    dataIndex += (uint8)2U;
                }
                retValue = FLEXRAY_STATUS_SUCCESS;
            }
            else
            {
                retValue = FLEXRAY_STATUS_ERROR;
            }
        #if(FLEXRAY_RXSTRINGENTLENGTHCHECK == STD_ON)
        }
        else /* received payload length does not match configured payload length */
        {
            retValue = FLEXRAY_STATUS_ERROR;
        }
        #endif
        if(FALSE == channel)
        {
            FLEXRAY_ClearFifoAInterruptFlag(inst);
        }
        else
        {
            FLEXRAY_ClearFifoBInterruptFlag(inst);
        }
    }
    else
    {
        /* Cannot access message buffer this time */
        retValue = FLEXRAY_STATUS_ERROR;
    }

    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_GetTransmitStatus
 * Description   : Checks for channel conflicts and writes the result
 *                 in the buffer state.
 *END**************************************************************************/
static void Flexray_GetTransmitStatus(const FLEXRAY_Type* inst,
                                                      uint8 mbIndex ,
                                                      Flexray_Ip_BufferStateType* bState)
{
    uint16 phyMBIndex;
    uint32 sysBaseAddr;
    uint32 headerBuffOffset;
    Flexray_Ip_HeaderDataType *pHeaderData;

    phyMBIndex = FLEXRAY_GetPhyMBIndex(inst, mbIndex);
    sysBaseAddr = FLEXRAY_GetSysMemBaseAddr(inst);
    headerBuffOffset = (uint32)((uint32)phyMBIndex * FRAME_HEADER_SIZE);
    pHeaderData = (Flexray_Ip_HeaderDataType *)(sysBaseAddr + headerBuffOffset);

    /* The frameHdr must not point to null at this point. */
    if(bState->frameHdr != NULL_PTR)
    {
       Flexray_UnpackMessageBufferHeader(pHeaderData, bState->frameHdr);
    }

    /* Check all channels for conflicts. */
    if(FLEXRAY_GetTxChnAConflict(inst) && FLEXRAY_GetTxChnBConflict(inst))
    {
        bState->status = FLEXRAY_STATUS_TX_CONFLICT_AB;
    } else if(FLEXRAY_GetTxChnAConflict(inst))
    {
        bState->status = FLEXRAY_STATUS_TX_CONFLICT_A;
    } else if(FLEXRAY_GetTxChnBConflict(inst))
    {
        bState->status = FLEXRAY_STATUS_TX_CONFLICT_B;
    } else
    {
        bState->status = FLEXRAY_STATUS_SUCCESS;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetTransferStatus
 * Description   : This function returns whether the current buffer status is saved
 * into buffer state.
 * bufferId decides tx or rx message buffer
 *
 * @implements Flexray_Ip_GetTransferStatus_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_GetTransferStatus(uint8 instNum,
                                                                   uint8 bufferId)
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    const Flexray_Ip_StateType* state;
#ifdef FLEXRAY_AUTOSAR_MODE_USED
    const FLEXRAY_Type* inst;
#endif
    Flexray_Ip_BufferStateType* bState;
    uint8 mbIndex;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    state = Flexray_Ip_apxState[instNum];
#ifdef FLEXRAY_AUTOSAR_MODE_USED
    inst = Flexray_Ip_apxBase[instNum];
#endif

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state != NULL_PTR);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    mbIndex = state->bufferState[bufferId].mbId;
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
#endif

    #if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    /* Check mbId and mbIndex to verify that resource are correctly assigned */
    if( mbIndex == bState->mbId)
    {
    #endif
        #ifdef FLEXRAY_AUTOSAR_MODE_USED
        if(FLEXRAY_IsMBTx(inst, mbIndex))
        {
            if(FLEXRAY_GetMBFlag(inst, mbIndex) == TRUE)
            {
                Flexray_GetTransmitStatus(inst, mbIndex , bState);
            }
        #endif
            retVal = bState->status;
        #ifdef FLEXRAY_AUTOSAR_MODE_USED
        }
        else
        {
            retVal = FLEXRAY_STATUS_ERROR;
        }
        #endif
    #if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    }
    #endif
    return retVal;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_TxIrq
 * Description   : Transmit interrupt handler for FR.
 * This handler set PPI or payloadLength for dynamic frame in individual buffer,
 * assign buffer status when buffer status is busy and clear tx message buffer interrupt flag
 * This is not a public API as it is called whenever an interrupt occurs.
 *
 *END**************************************************************************/
void Flexray_Ip_TxIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    const Flexray_Ip_BufferStateType* bState;
    uint8 bufferId;
    uint8 idxMB;
    uint8 numberMb = state->numberOfMbUsed;
    boolean isTxMB;
    for (idxMB = 0U; idxMB < numberMb; idxMB++)
    {
        bState = state->mbStateMap[idxMB];
        bufferId = bState->bufferId;
        isTxMB = FLEXRAY_IsMBTx(inst, idxMB);
        if (FLEXRAY_GetMBFlag(inst, idxMB) && isTxMB )
        {
            if(FLEXRAY_GetMBInterruptEnable(inst, idxMB))
            {
                FLEXRAY_ClearMBFlag(inst, idxMB);
                if(Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT)
                {
                    FLEXRAY_ProcessTxMBWhenUpdatedSlotStatus(instNum, bufferId);
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_RxIrq
 * Description   : Transmit interrupt handler for FR.
 * This handler clear rx message buffer interrupt flag and initialize count timer of osif,
 * callback function if enabled
 * This is not a public API as it is called whenever an interrupt occurs.
 *
 *END**************************************************************************/
void Flexray_Ip_RxIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    const Flexray_Ip_BufferStateType* bState;
    uint8 bufferId;
    uint8 idxMB;
    boolean isTxMB;
    uint8 numberMB = state->numberOfMbUsed;

    for (idxMB = 0U; idxMB < numberMB; idxMB++)
    {
        bState = state->mbStateMap[idxMB];
        bufferId = bState->bufferId;
        /* save register to avoid misra */
        isTxMB = FLEXRAY_IsMBTx(inst, idxMB );
        /* Check new data for rx message buffer */
        if (FLEXRAY_GetMBFlag(inst, idxMB) && (!isTxMB))
        {
            if (FLEXRAY_GetMBInterruptEnable(inst, idxMB))
            {
                FLEXRAY_ClearMBFlag(inst, idxMB);
                if((bState->status == FLEXRAY_STATUS_BUSY) && (Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT))
                {
                    FLEXRAY_ProcessRxMBWhenUpdatedSlotStatus(instNum, bufferId, bState->frameHdr, bState->pData, bState->dataLength);
                }
            }
        }
        bState++;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_PrIrq
 * Description   : The interrupt handler for protocol interrupt
 * Execute to get protocol interrupt flags and use this value as input parameter
 * of callback function
 *
 *END**************************************************************************/
void Flexray_Ip_PrIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    void* callbackParam = state->callback.prCallbackParam;
    uint32 prIntFlagValue = FLEXRAY_GetAllProtocolInterruptFlag(inst);

    MCAL_FAULT_INJECTION_POINT(T_FR_FIP_1_PRIRQ);
    if((prIntFlagValue != 0UL) && (FLEXRAY_GetAllProtocolInterruptEnable(inst) != 0UL))
    {
        FLEXRAY_ClearAllProtocolInterruptFlag(inst);

        if((state->callback.protocolCallback != NULL_PTR) && (Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT))
        {
            state->callback.protocolCallback(prIntFlagValue, callbackParam);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ChiIrq
 * Description   : The interrupt handler for chi interrupt
 * Execute to get chi interrupt flags and use this value as input parameter
 * of callback function
 *
 *END**************************************************************************/
void Flexray_Ip_ChiIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    void* callbackParam = state->callback.chiCallbackParam;
    uint16 chiErrorFlagValue = FLEXRAY_GetAllCHIErrorInterruptFlag(inst);

    MCAL_FAULT_INJECTION_POINT(T_FR_FIP_2_CHIRQ);
    if((chiErrorFlagValue != 0UL) && FLEXRAY_GetCHIInterruptEnable(inst))
    {
        FLEXRAY_ClearAllCHIErrorInterruptFlag(inst);

        if((state->callback.chiCallback != NULL_PTR) && (Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT))
        {
            state->callback.chiCallback(chiErrorFlagValue, callbackParam);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_WupIrq
 * Description   : The interrupt handler for wakeup interrupt
 *
 *END**************************************************************************/
void Flexray_Ip_WupIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    const FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    void* callbackParam = state->callback.wakeupCallbackParam;

    MCAL_FAULT_INJECTION_POINT(T_FR_FIP_3_WUPIRQ);
    if((FLEXRAY_GetWUPInterruptFlag(inst)) && FLEXRAY_GetWUPInterruptEnable(inst))
    {
        Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_WAKEUP_INTERRUPT);

        if((state->callback.wakeupCallback != NULL_PTR) && (Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT))
        {
            state->callback.wakeupCallback(callbackParam);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_FAFAIrq
 * Description   : The interrupt handler for receive FIFO Channel A Almost Full
 * interrupt
 *
 *END**************************************************************************/
void Flexray_Ip_FAFAIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    const FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    void* callbackParam = state->callback.fifoACallbackParam;

    if(FLEXRAY_GetFifoAInterruptFlag(inst) && FLEXRAY_GetFIFOAInterruptEnable(inst))
    {
        if((state->callback.fifoACallback != NULL_PTR) && (Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT))
        {
            state->callback.fifoACallback(callbackParam);
        }
        else
        {
            Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_FIFOA_INTERRUPT);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_FAFBIrq
 * Description   : The interrupt handler for receive FIFO Channel B Almost Full
 * interrupt
 *
 *END**************************************************************************/
void Flexray_Ip_FAFBIrq(uint8 instNum)
{
    const Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    const FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    void* callbackParam = state->callback.fifoBCallbackParam;

    if(FLEXRAY_GetFifoBInterruptFlag(inst) && FLEXRAY_GetFIFOBInterruptEnable(inst))
    {
        if((state->callback.fifoBCallback != NULL_PTR) && (Flexray_Ip_aeDriverStates[instNum] == FLEXRAY_STATE_INIT))
        {
            state->callback.fifoBCallback(callbackParam);
        }
        else
        {
            Flexray_Ip_ClearGlobalInterruptFlag(instNum, FLEXRAY_FIFOB_INTERRUPT);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_Abort
 * Description   : This function shuts down the FR by:
 * disabling buffer interrupt, message buffer.
 *
 * @implements Flexray_Ip_Abort_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_Abort(uint8 instNum,
                                                       uint8 bufferId)
{
    const Flexray_Ip_StateType* state;
    Flexray_Ip_BufferStateType* bState;
    FLEXRAY_Type* inst;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_ERROR;
    uint8 mbIndex;
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    state = Flexray_Ip_apxState[instNum];
    inst = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state != NULL_PTR);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    mbIndex = state->bufferState[bufferId].mbId;
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    /* Check mbId and mbIndex to verify that resource are correctly assigned */
    if( mbIndex == bState->mbId)
    {
#endif
#ifndef FLEXRAY_AUTOSAR_MODE_USED
        if (bState->status == FLEXRAY_STATUS_SUCCESS)
        {
            ret = FLEXRAY_STATUS_ERROR;
        }
        else
        {
#endif

#ifdef ERR_IPV_FLEXRAY_E050119
    #if(STD_ON == ERR_IPV_FLEXRAY_E050119)
            /* Workaround for Errata ERR050119 */
            if(FLEXRAY_STATE_STARTUP != Flexray_Ip_GetCurrentState(instNum))
            {
    #endif
#endif
                if (FLEXRAY_IsMBTx(inst, mbIndex))
                {
                    /* Start critical section: implementation depends on integrator */
                    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_10();
                    /* Lock message buffer to set about not ready */
                    FLEXRAY_SetMBLockMode(inst, mbIndex, TRUE);
                    /* End critical section: implementation depends on integrator */
                    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_10();
                    /* Check lock message buffer status */
                    if (FLEXRAY_GetMBLockStatus(inst, mbIndex))
                    {
                        /* Start critical section: implementation depends on integrator */
                        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_10();
                        /* Stop transmit anyway by clearing CMT bit */
                        FLEXRAY_SetMBTrasmitReady(inst, mbIndex, FALSE);
                        /* End critical section: implementation depends on integrator */
                        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_10();
                        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
                        FLEXRAY_SetMBInterrupt(inst, mbIndex, FALSE);
                        #endif
                        bState->status = FLEXRAY_STATUS_ABORTED;
                        ret = FLEXRAY_STATUS_SUCCESS;
                    }
                    else
                    {
                        /* Can not trigger to lock message buffer */
                        ret = FLEXRAY_STATUS_ERROR;
                    }
                }
                else
                {
                    /* Start critical section: implementation depends on integrator */
                    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_10();
                    /* Disable rx message buffer */
                    FLEXRAY_SetMBEnableMode(inst, mbIndex, FALSE);

                    /* End critical section: implementation depends on integrator */
                    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_10();
                    if (!FLEXRAY_GetMBEnableStatus(inst, mbIndex))
                    {
                        #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
                        FLEXRAY_SetMBInterrupt(inst, mbIndex, FALSE);
                        #endif
                        bState->status = FLEXRAY_STATUS_ABORTED;
                        ret = FLEXRAY_STATUS_SUCCESS;
                    }
                    else
                    {
                        /* Can not trigger to disable message buffer */
                        ret = FLEXRAY_STATUS_ERROR;
                    }
                }
#ifdef ERR_IPV_FLEXRAY_E050119
    #if(STD_ON == ERR_IPV_FLEXRAY_E050119)
            }
    #endif
#endif
#ifndef FLEXRAY_AUTOSAR_MODE_USED
        }
#endif
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    }
#endif
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_CancelTxBuffer
 * Description   : This function cancels the current tx buffer
 *
 * @implements Flexray_Ip_CancelTxBuffer_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_CancelTxBuffer(uint8 instNum,
                                                                uint8 bufferId,
                                                                boolean* pendingStatus)
{
    const Flexray_Ip_StateType* state;
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    const Flexray_Ip_BufferStateType* bState;
#endif
    FLEXRAY_Type* inst;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_ERROR;
    uint8 mbIndex;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif

    state = Flexray_Ip_apxState[instNum];
    inst = Flexray_Ip_apxBase[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state != NULL_PTR);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif

    mbIndex = state->bufferState[bufferId].mbId;
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(bState != NULL_PTR);
#endif
#endif

#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    /* Check mbId and mbIndex to verify that resource are correctly assigned */
    if( mbIndex == bState->mbId)
    {
#endif
        if(FLEXRAY_IsMBTx(inst,mbIndex))
        {
            #ifdef FLEXRAY_MB_INTERRUPT_SUPPORT
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_11();
            /* Disable MB interrupt */
            FLEXRAY_SetMBInterrupt(inst, mbIndex, FALSE);
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_11();
            #endif
            /* Message buffer data ready for transmission ? */
            if(!FLEXRAY_GetMBTrasmitReady(inst,mbIndex))
            {
                *pendingStatus = TRUE;
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_11();
                FLEXRAY_SetMBLockMode(inst,mbIndex, TRUE);
                FLEXRAY_SetMBTrasmitReady(inst,mbIndex, FALSE);
                FLEXRAY_SetMBLockMode(inst,mbIndex, FALSE);

                if(!FLEXRAY_GetMBLockStatus(inst, mbIndex) && FLEXRAY_GetMBTrasmitReady(inst,mbIndex))
                {
                    ret = FLEXRAY_STATUS_SUCCESS;
                }
                else
                {

                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_11();
            }
            else
            {
                 ret = FLEXRAY_STATUS_SUCCESS;
            }
        }
#if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    }
#endif
    return ret;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetStartupStatus
 * Description   : This function gets the startup current state of FR.
 *
 * @implements Flexray_Ip_GetStartupStatus_Activity
 *END**************************************************************************/
Flexray_Ip_StartupStatusType Flexray_Ip_GetStartupStatus(uint8 instNum)
{
    const FLEXRAY_Type* inst;
    Flexray_Ip_StartupStatusType retValue = FLEXRAY_STARTUP_UNDEFINED;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    switch(((inst->PSR0 & FLEXRAY_PSR0_STARTUPSTATE_MASK) >> FLEXRAY_PSR0_STARTUPSTATE_SHIFT))
    {
        case FLEXRAY_PSR0_STARTUP_CCR_U16:
            retValue = FLEXRAY_COLDSTART_COLLISION;
            break;

        case FLEXRAY_PSR0_STARTUP_CL_U16:
            retValue = FLEXRAY_COLDSTART_LISTEN;
            break;

        case FLEXRAY_PSR0_STARTUP_ICOC_U16:
            retValue = FLEXRAY_INTE_CHECK;
            break;

        case FLEXRAY_PSR0_STARTUP_IL_U16:
            retValue = FLEXRAY_INTE_LISTEN;
            break;

        case FLEXRAY_PSR0_STARTUP_IS_U16:
            retValue = FLEXRAY_INIT_SCHEDULE;
            break;

        case FLEXRAY_PSR0_STARTUP_CCC_U16:
            retValue = FLEXRAY_COLDSTART_CONS_CHECK;
            break;

        case FLEXRAY_PSR0_STARTUP_ICLC_U16:
            retValue = FLEXRAY_INTE_COLDSTART_CHECK;
            break;

        case FLEXRAY_PSR0_STARTUP_CG_U16:
            retValue = FLEXRAY_COLDSTART_GAP;
            break;

        case FLEXRAY_PSR0_STARTUP_CJ_U16:
            retValue = FLEXRAY_COLDSTART_JOIN;
            break;

        default:
            retValue = FLEXRAY_STARTUP_UNDEFINED;
            break;
    }
    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetCurrentCycleCount
 * Description   : This function gets the current cycle count of FR.
 *
 * @implements Flexray_Ip_GetCurrentCycleCount_Activity
 *END**************************************************************************/
uint8 Flexray_Ip_GetCurrentCycleCount(uint8 instNum)
{
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    return (uint8) ((inst->CYCTR & FLEXRAY_CYCTR_CYCCNT_MASK)>>FLEXRAY_CYCTR_CYCCNT_SHIFT);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetWakeupChannel
 * Description   : This function Set wakeup channel of FR.
 *
 * @implements Flexray_Ip_SetWakeupChannel_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_SetWakeupChannel(uint8 instNum,
                                                                  boolean bChnA,
                                                                  boolean bChnB)
{
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_ERROR;
    uint16 u16tmpVal;
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_CONFIG))
    {
        /* Wait till FlexRay CC is not in POC:Config */
        if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_WaitPOCState(instNum, FLEXRAY_STATE_CONFIG))
        {

            /* The CC should be in POC:config */
            /* Load the PCR10 */
            u16tmpVal = inst->PCR10;

            /* Determine the channel */
            if(TRUE == bChnA)
            {   /* Channel A should be used for wakeup sending */
                /* Channel A - clear the bit in register */
                 u16tmpVal &= ~((uint16)FLEXRAY_PCR10_wakeup_channel_MASK);
            }
            if(TRUE == bChnB)
            {   /* Channel B should be used for wakeup sending */
                /* Fr_CtrlIdx: PCR10: wakeup_channel */
                u16tmpVal |= (uint16)FLEXRAY_PCR10_wakeup_channel_MASK;       /* Channel B - set the bit */
            }

            inst->PCR10= u16tmpVal;  /* Store new settings */

            /* Invoke CHI command CONFIG COMPLETE */
            /* Immediately transition to POC:ready state */
            if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_SendCHICommand(instNum, FLEXRAY_CHI_CMD_CONFIG_COMPLETE))
            {
                /* Wait till FlexRay CC is not in POC:Ready */
                if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_WaitPOCState(instNum, FLEXRAY_STATE_READY))
                {
                    retValue = FLEXRAY_STATUS_SUCCESS;
                }
            }
        }
    }
    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetWakeupChannel
 * Description   : This function gets wakeup channel of FR.
 * Wakeup channel flag will be cleared immediately
 *
 * @implements Flexray_Ip_GetWakeupChannel_Activity
 *END**************************************************************************/
Flexray_Ip_WakeUpChannelType Flexray_Ip_GetWakeupChannel(uint8 instNum)
{
    FLEXRAY_Type* inst;
    Flexray_Ip_WakeUpChannelType channel;
    uint16 tmpRegVal;
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    tmpRegVal = inst->PSR3;
    if((0U != (tmpRegVal & FLEXRAY_PSR3_WUA_MASK)) && (0U != (tmpRegVal & FLEXRAY_PSR3_WUB_MASK)))
    {
        channel = FLEXRAY_WUP_AB;
    } else if(0U != (tmpRegVal & FLEXRAY_PSR3_WUA_MASK))
    {
        channel = FLEXRAY_WUP_A;
    } else if(0U != (tmpRegVal & FLEXRAY_PSR3_WUB_MASK))
    {
        channel = FLEXRAY_WUP_B;
    }
    else
    {
        channel = FLEXRAY_WUP_NO_WAKEUP;
    }
    inst->PSR3 = FLEXRAY_PSR3_WUA_MASK | FLEXRAY_PSR3_WUB_MASK; /* write 1 to clear bits */
    return channel;
}

/*FUNCTION**********************************************************************
 *Flexray_Ip_WakeupStatusType
 * Function Name : Flexray_Ip_GetWakeupStatus
 * Description   : This function gets wakeup status of FR.
 *
 * @implements Flexray_Ip_GetWakeupStatus_Activity
 *END**************************************************************************/
Flexray_Ip_WakeupStatusType Flexray_Ip_GetWakeupStatus(uint8 instNum)
{
    const FLEXRAY_Type* inst;
    Flexray_Ip_WakeupStatusType retValue = FLEXRAY_UNDEFINED;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    switch(((inst->PSR0 & FLEXRAY_PSR0_WAKEUPSTATUS_MASK) >> FLEXRAY_PSR0_WAKEUPSTATUS_SHIFT))
    {
        case FLEXRAY_PSR0_WUP_RH_U16:
            retValue = FLEXRAY_RECEIVED_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_RW_U16:
            retValue = FLEXRAY_RECEIVED_WUP;
            break;

        case FLEXRAY_PSR0_WUP_HC_U16:
            retValue = FLEXRAY_COLLISION_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_WC_U16:
            retValue = FLEXRAY_COLLISION_WUP;
            break;

        case FLEXRAY_PSR0_WUP_UC_U16:
            retValue = FLEXRAY_COLLISION_UNKNOWN;
            break;

        case FLEXRAY_PSR0_WUP_T_U16:
            retValue = FLEXRAY_TRANSMITTED_WUP;
            break;

        case FLEXRAY_PSR0_WUP_UD_U16:
            retValue = FLEXRAY_UNDEFINED;
            break;

        default:
            retValue = FLEXRAY_UNDEFINED;
            break;
    }
    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ConfigureShadowBuffer
 * Description   : Configure shadow buffer
 *
 *END**************************************************************************/
static void Flexray_Ip_ConfigureShadowBuffer(uint8 instNum,
                                                             const Flexray_Ip_ShadowConfigType* pShadowConfig,
                                                             uint32 shadowDataOffset)
{

    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    uint8 sel = 0U;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(pShadowConfig != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    sel = pShadowConfig->segment1 ? 0U : 1U;
    sel |= pShadowConfig->channelA ? 0U : 2U;

    FLEXRAY_SetShadowBufferIdx(inst, pShadowConfig->phyMBIndex, sel);
    FLEXRAY_SetMBDataOffset(inst, pShadowConfig->phyMBIndex, shadowDataOffset);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetFiFoRangeFilter
 * Description   : Set FiFo Range Filter
 *
 *END**************************************************************************/
static void Flexray_Ip_SetFiFoRangeFilter(uint8 instNum,
                                                          const Flexray_Ip_FifoConfigType* fifoConfig)
{
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    uint8 filterIdx = 0U;

    /* Configure range filter */
    for (filterIdx = 0U; filterIdx < 4U; filterIdx++)
    {
        FLEXRAY_SetFiFoRangeFilter(inst, filterIdx, &fifoConfig->rangeFilter[filterIdx]);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ConfigureRxFiFo
 * Description   : Configure Rx FiFo
 *
 *END**************************************************************************/
static Flexray_Ip_StatusType Flexray_Ip_ConfigureRxFiFo(uint8 instNum,
                                                                        boolean isChnB,
                                                                        const Flexray_Ip_FifoConfigType* fifoConfig,
                                                                        uint32 fifoDataOffset)
{
    FLEXRAY_Type* inst = Flexray_Ip_apxBase[instNum];
    uint16 currentReadIdx = 0U;
    uint16 startIndex = 0U;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_SUCCESS;

    if (fifoConfig != NULL_PTR)
    {
        FLEXRAY_SetFiFoWatermark(inst, isChnB, fifoConfig->watermark);
        if (fifoConfig->fifoDepth == 0U)
        {
            FLEXRAY_SetFiFoRejFilter(inst, 0U, 0U);
        }
        else
        {
            startIndex = FLEXRAY_GetFiFoStartIdx(inst);
            if (isChnB)
            {
                currentReadIdx = FLEXRAY_ReceiveFiFoBReadIdx(inst);
            }
            else
            {
                currentReadIdx = FLEXRAY_ReceiveFiFoAReadIdx(inst);
            }

            /* Rx FiFo only can operate correctly when the sum of the current fifo depth value and the previous start index value is
             * bigger than the previous read index */
            if((fifoConfig->fifoDepth + startIndex) > currentReadIdx)
            {
                FLEXRAY_SetFiFoPos(inst, fifoConfig->startIndex, fifoDataOffset);
                FLEXRAY_SetFiFoSize(inst, fifoConfig->entrySize, fifoConfig->fifoDepth);
                FLEXRAY_SetFiFoRejFilter(inst, fifoConfig->fidRejVal, fifoConfig->fidRejMask);
                FLEXRAY_SetFiFoAcceptFilter(inst, fifoConfig->midAccVal, fifoConfig->midAccMask);
                Flexray_Ip_SetFiFoRangeFilter(instNum, fifoConfig);
            }
            else
            {
                ret = FLEXRAY_STATUS_ERROR;
            }
        }
    }
    else
    {
        FLEXRAY_SetFiFoWatermark(inst, isChnB, 0U);
        FLEXRAY_SetFiFoRejFilter(inst, 0U, 0U);
    }

    return ret;
}

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_CheckRxIndBufferChannelAppearsOnce
 * Description   : Check rx individual message buffers if Appears Once Channel A or B.
 *
 *END**************************************************************************/
static void FLEXRAY_CheckRxIndBufferChannelAppearsOnce(const Flexray_Ip_IndConfigType* pIndConfig,
                                                                       boolean* chanA,
                                                                       boolean* chanB)
{

    if (pIndConfig->channelA)
    {
        *chanA = TRUE;
    }
    if (pIndConfig->channelB)
    {
        *chanB = TRUE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_CheckRxIndBufferSegmentAppearsOnce
 * Description   : Check rx individual message buffers if Appears Once Segment 1 or 2.
 *
 *END**************************************************************************/
static void FLEXRAY_CheckRxIndBufferSegmentAppearsOnce(const Flexray_Ip_IndConfigType* pIndConfig,
                                                                       boolean* seg1,
                                                                       boolean* seg2,
                                                                       uint8 indS1Size)
{

    if (pIndConfig->MBIndex < indS1Size)
    {
        *seg1 = TRUE;
    }
    else
    {
        *seg2 = TRUE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_CheckShadowBufferAppearsOnce
 * Description   : Check Shadow buffer if Appears Once.
 *
 *END**************************************************************************/
static void FLEXRAY_CheckShadowBufferAppearsOnce(const Flexray_Ip_ShadowConfigType* pShadowConfig,
                                                                 boolean* shadowSeg1,
                                                                 boolean* shadowSeg2,
                                                                 boolean* shadowChanA,
                                                                 boolean* shadowChanB)
{
    if (pShadowConfig->channelA)
    {
        *shadowChanA = TRUE;
    }
    else
    {
        *shadowChanB = TRUE;
    }
    if (pShadowConfig->segment1)
    {
        *shadowSeg1 = TRUE;
    }else
    {
        *shadowSeg2 = TRUE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_CheckShadowForRxIndBuffer
 * Description   : Check shadow configuration with rx individual buffer.
 *
 *END**************************************************************************/
static boolean FLEXRAY_CheckShadowForRxIndBuffer(const Flexray_Ip_ConfigType* config)
{
    const Flexray_Ip_IndMemConfigType* indMemConfig = config->indMemConfig;
    const Flexray_Ip_IndConfigType* indBufConfig = config->indBufConfig;
    const Flexray_Ip_ShadowConfigType* shadowConfig = config->shadowConfig;
    uint16 numIndBuf = 0U;
    uint8 numShadowConfig = 0U;
    uint8 idx = 0U;
    boolean correctShadow;

    boolean seg1 = FALSE;
    boolean seg2 = FALSE;
    boolean chanA = FALSE;
    boolean chanB = FALSE;
    boolean shadowSeg1 = FALSE;
    boolean shadowSeg2 = FALSE;
    boolean shadowChanA = FALSE;
    boolean shadowChanB = FALSE;

    /*  Check position of rx individual message buffers */
    if ((indMemConfig != NULL_PTR) && (indBufConfig != NULL_PTR))
    {
        numIndBuf = (uint16)((uint16)(indMemConfig->S1Size) + indMemConfig->S2Size);
        for (idx = 0U; idx < numIndBuf; idx++)
        {
            if(!indBufConfig->isTx)
            {
                FLEXRAY_CheckRxIndBufferChannelAppearsOnce(&indBufConfig[idx] , &chanA, &chanB);
                FLEXRAY_CheckRxIndBufferSegmentAppearsOnce(&indBufConfig[idx] , &seg1, &seg2, indMemConfig->S1Size);
            }
        }
    }

    /*  Check position of shadows */
    if (shadowConfig != NULL_PTR)
    {
        numShadowConfig = config->numShadowConfig;
        for (idx = 0U; idx < numShadowConfig; idx++)
        {
            FLEXRAY_CheckShadowBufferAppearsOnce(&shadowConfig[idx], &shadowSeg1, &shadowSeg2, &shadowChanA, &shadowChanB);
        }
    }

    correctShadow = (boolean)(((shadowChanA == chanA) || !chanA) && ((shadowChanB == chanB)  || !chanB) && ((shadowSeg1 == seg1) || !seg1) && ((shadowSeg2 == seg2) || !seg2));

    return correctShadow;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXRAY_CaculateSizeOfSysMemAndFiFoSysMem
 * Description   : Calculate size of system memory and fifo memory of FIFO
 *
 *END**************************************************************************/
static void FLEXRAY_CalculateSizeOfSysMemAndFiFoSysMem(uint8 instNum,
                                                                       const Flexray_Ip_ConfigType* config)
{
    Flexray_Ip_StateType* state = Flexray_Ip_apxState[instNum];
    const Flexray_Ip_IndConfigType* indBufConfig = config->indBufConfig;
    const Flexray_Ip_ShadowConfigType* shadowConfig = config->shadowConfig;
    const Flexray_Ip_IndMemConfigType* indMemConfig = config->indMemConfig;
    const Flexray_Ip_FifoConfigType* fifoConfigA = config->fifoConfigA;
    const Flexray_Ip_FifoConfigType* fifoConfigB = config->fifoConfigB;
    uint32 headerSysMemSize = 0U;
    uint32 headerFiFoSysMemSize = 0U;
    uint32 dataSysMemSize = 0U;
    uint32 dataFiFoSysMemSize = 0U;
    uint32 dataShadowSize = 0U;
    uint32 idx = 0U;
    uint16 numIndBuf = 0U;
    uint16 numRxFiFoBuf = 0U;
    uint32 indDataSize = 0U;
    uint8 numShadowConfig = 0U;

    if ((indMemConfig != NULL_PTR) && (indBufConfig != NULL_PTR))
    {
        numIndBuf = (uint16)((uint16)(indMemConfig->S1Size) + indMemConfig->S2Size);
        indDataSize = (((uint32)((uint32)(indMemConfig->S1DataSize) * indMemConfig->S1Size) + \
                       (uint32)((uint32)(indMemConfig->S2DataSize) * indMemConfig->S2Size)) << 1U);

        if (shadowConfig != NULL_PTR)
        {
            numShadowConfig = config->numShadowConfig;
        }
    }

    if (fifoConfigA != NULL_PTR)
    {
        numRxFiFoBuf = fifoConfigA->fifoDepth;
        dataFiFoSysMemSize = ((uint32)((uint32)(fifoConfigA->fifoDepth) * fifoConfigA->entrySize) << 1U);
    }

    if (fifoConfigB != NULL_PTR)
    {
        numRxFiFoBuf += fifoConfigB->fifoDepth;
        dataFiFoSysMemSize += (uint32)(((uint32)(fifoConfigB->fifoDepth) * fifoConfigB->entrySize) << 1U);
    }

    headerSysMemSize = ((uint32)(((uint32)numIndBuf + numShadowConfig) * FRAME_HEADER_SIZE));
    headerFiFoSysMemSize = (uint32)((uint32)numRxFiFoBuf * FRAME_HEADER_SIZE);

    for (idx = 0U; idx < numShadowConfig; idx++)
    {
        dataShadowSize += ((uint32)(shadowConfig[idx].segment1 ? indMemConfig->S1DataSize : indMemConfig->S2DataSize) << 1U);
    }
    dataSysMemSize = indDataSize + dataShadowSize;

    /* Save memory size with system and fifo */
    if (config->ccConfig->memLayout == FLEXRAY_MEM_LAYOUT_MIXED)
    {
        state->sysMemSize = headerSysMemSize + headerFiFoSysMemSize + dataSysMemSize + dataFiFoSysMemSize;
    }
    else
    {
        state->sysMemSize = headerSysMemSize + dataSysMemSize;
        state->fifoSysMemSize = headerFiFoSysMemSize + dataFiFoSysMemSize;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetDefaultConfig
 * Description   : Gets the default configuration structure
 *
 * @implements Flexray_Ip_GetDefaultConfig_Activity
 *END**************************************************************************/
void Flexray_Ip_GetDefaultConfig(const Flexray_Ip_ConfigType * config)
{
    Flexray_Ip_PeConfigType* peConfig = config->peConfig;
    Flexray_Ip_CcConfigType* ccConfig = config->ccConfig;

    /* PE Configuration */
    peConfig->gColdstartAttempts = 8U;
    peConfig->gdActionPointOffset = 4U;
    peConfig->gdCASRxLowMax = 97U;
    peConfig->gdDynamicSlotIdlePhase = 1U;
    peConfig->gdMinislot = 9U;
    peConfig->gdMinislotActionPointOffset = 4U;
    peConfig->gdStaticSlot = 35;
    peConfig->gSymbolWindowExists = TRUE;
    peConfig->gdSymbolWindow = 40U;
    peConfig->gdTSSTransmitter = 11U;
    peConfig->gdWakeupSymbolRxIdle = 40U;
    peConfig->gdWakeupSymbolRxLow = 40U;
    peConfig->gdWakeupSymbolRxWindow = 480U;
    peConfig->gdWakeupSymbolTxIdle = 180U;
    peConfig->gdWakeupSymbolTxLow = 60U;
    peConfig->gListenNoise = 2U;
    peConfig->gMacroPerCycle = 5000U;
    peConfig->gMaxWithoutClockCorrectionFatal = 2U;
    peConfig->gMaxWithoutClockCorrectionPassive = 2U;
    peConfig->gMiniSlotExists = TRUE;
    peConfig->gNumberOfMinislots = 219U;
    peConfig->gNumberOfStaticSlots = 85U;
    peConfig->gOffsetCorrectionStart = 4990U;
    peConfig->gPayloadLengthStatic = 8U;
    peConfig->gSyncNodeMax = 15U;
    peConfig->gNetworkManagementVectorLength = 0U;
    peConfig->pdListenTimeout = 400242U;
    peConfig->pMacroInitialOffsetA = 6U;
    peConfig->pMacroInitialOffsetB = 6U;
    peConfig->pPayloadLengthDynMax = 127U;
    peConfig->pAllowHaltDueToClock = TRUE;
    peConfig->pAllowPassiveToActive = 0U;
    peConfig->pClusterDriftDamping = 2U;
    peConfig->pdAcceptedStartupRange = 281U;
    peConfig->pDelayCompensationA = 5U;
    peConfig->pDelayCompensationB = 5U;
    peConfig->pKeySlotId = 3;
    peConfig->pKeySlotUsedForStartup = TRUE;
    peConfig->pKeySlotUsedForSync = TRUE;
    peConfig->pLatestTx = 188U;
    peConfig->pMicroInitialOffsetA = 23U;
    peConfig->pMicroInitialOffsetB = 23U;
    peConfig->pMicroPerCycle = 200000U;
    peConfig->pdMaxDrift = 1000U;
    peConfig->pMicroPerMacroNom = 40U;
    peConfig->pOffsetCorrectionOut = 153U;
    peConfig->pRateCorrectionOut = 121U;
    peConfig->pSingleSlotEnabled = FALSE;
    peConfig->pWakeupChannel = TRUE;
    peConfig->pWakeupPattern = 14U;
    peConfig->pDecodingCorrection = 52U;
    peConfig->keySlotHeaderCrc = 0x02F1;
    peConfig->pExternOffsetCorrection = 0U;
    peConfig->pExternRateCorrection = 0U;

    /* CC Configuration */
    ccConfig->freezeMode = TRUE;
    ccConfig->channelA = TRUE;
    ccConfig->channelB = TRUE;
    ccConfig->syncFrameFilter = FALSE;
    ccConfig->bitRate = FLEXRAY_BITRATE_10;
    ccConfig->memLayout = FLEXRAY_MEM_LAYOUT_MIXED;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_SetBasicDynamicTxFrame
 * Description   : This function sets PPI or payloadLength for Dynamic frame.
 *
 * @implements    Flexray_Ip_SetBasicDynamicTxFrame_Activity
 *END**************************************************************************/
void Flexray_Ip_SetBasicDynamicTxFrame(uint8 instNum,
                                                       uint8 bufferId,
                                                       boolean PPI,
                                                       uint8 payloadLength)
{
    const Flexray_Ip_StateType* state;
    FLEXRAY_Type* base;
    Flexray_Ip_HeaderDataType* pHeaderData;
    Flexray_Ip_FrameHeaderType frameHdr;
    uint16 index;
    boolean eds, lcks;
    Flexray_Ip_BufferStateType* bState;
    uint8 mbIndex;
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    state = Flexray_Ip_apxState[instNum];

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(state != NULL_PTR);
    DevAssert(bufferId <= state->numberOfBuffer);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    base = Flexray_Ip_apxBase[instNum];
    mbIndex = state->bufferState[bufferId].mbId;
    MCAL_DATA_SYNC_BARRIER();
    bState = state->mbStateMap[mbIndex];


#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(mbIndex <= state->numberOfMbUsed);
    DevAssert(bState != NULL_PTR);
    DevAssert(payloadLength > 0UL);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    /* Check if transmit message buffer */
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(FLEXRAY_IsMBTx(base, mbIndex) == TRUE);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_12();
    /* Lock individual buffer */
    FLEXRAY_SetMBLockMode(base, mbIndex, TRUE);

    /* Get lock and enable status of message buffer */
    eds = FLEXRAY_GetMBEnableStatus(base, mbIndex);
    lcks = FLEXRAY_GetMBLockStatus(base, mbIndex);
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_12();
    /* Check if we can modify buffer data */
    if((!eds) || lcks)
    {
        /* Read data from header field */
        pHeaderData = (Flexray_Ip_HeaderDataType *)FLEXRAY_GetSysMemBaseAddr(base);

        /* Get data buffer index */
        index = FLEXRAY_GetPhyMBIndex(base, mbIndex);

        /* Get header data of message buffer */
        Flexray_UnpackMessageBufferHeader(&pHeaderData[index], &frameHdr);

    #if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
        DevAssert(frameHdr.frameID > FLEXRAY_GetNumbOfStaticSlots(base));
    #endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

        frameHdr.payloadPreambleIndicator = PPI;
        frameHdr.payloadLength = payloadLength;
        Flexray_PackMessageBufferHeader(&pHeaderData[index], &frameHdr);
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_12();
        if(!eds)
        {
            FLEXRAY_SetMBEnableMode(base, mbIndex, TRUE);
        }
        FLEXRAY_SetMBLockMode(base, mbIndex, FALSE);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_12();
    }
    else
    {
        bState->PPI = PPI;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ReConfigIndividual
 * Description   : Re-Configure all field of FR frame except 2 parameters:
 * Message buffer index and physical message buffer index.
 * This function are used when POC state is POC:config or the message buffer is disable.
 *
 * @implements    Flexray_Ip_ReConfigIndividual_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_ReConfigIndividual(uint8 instNum,
                                                                    Flexray_Ip_IndConfigType* pIndConfig)
{
    FLEXRAY_Type* inst;
    Flexray_Ip_HeaderDataType * pHeaderData;
    Flexray_Ip_HeaderDataType * pBaseHeaderData;
    uint8 MBIndex;
    uint16 phyMbIndex;
    Flexray_Ip_StatusType ret = FLEXRAY_STATUS_SUCCESS;
    const Flexray_Ip_StateType* state;
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
    DevAssert(Flexray_Ip_apxState[instNum] != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    inst = Flexray_Ip_apxBase[instNum];
    state = Flexray_Ip_apxState[instNum];
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(pIndConfig != NULL_PTR);
    DevAssert(state != NULL_PTR);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    MBIndex = pIndConfig->MBIndex;
    if(MBIndex < (state->numberOfMbUsed))
    {
        phyMbIndex = FLEXRAY_GetPhyMBIndex(inst, MBIndex);
        if(phyMbIndex < (uint16)((uint16)(state->numberOfMbUsed) + state->numShadowBuffer))
        {
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_13();
            FLEXRAY_SetMBEnableMode(inst, MBIndex, FALSE);
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_13();
            if(!FLEXRAY_GetMBEnableStatus(inst, MBIndex))
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_13();
                FLEXRAY_SetMBTrasmitReady(inst, MBIndex, FALSE);

                pBaseHeaderData = (Flexray_Ip_HeaderDataType *)(FLEXRAY_GetSysMemBaseAddr(inst));

                FLEXRAY_SetMBRepeat(inst, MBIndex, pIndConfig->repeatTx);
                FLEXRAY_SetMBChn(inst, MBIndex, pIndConfig->channelA, pIndConfig->channelB);
                FLEXRAY_SetCycleCountFilter(inst, MBIndex, pIndConfig->ccFilter, \
                                             pIndConfig->ccFilterVal, pIndConfig->ccFilterMask);
                FLEXRAY_SetMBFrameId(inst, MBIndex, pIndConfig->frameID);
                FLEXRAY_SetMBDirection(inst, MBIndex, pIndConfig->isTx);
                FLEXRAY_SetMBInterrupt(inst, MBIndex, TRUE);
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_13();
                pHeaderData = &(pBaseHeaderData[phyMbIndex]);

                if(pIndConfig->isTx)
                {
                    if(pIndConfig->frameID <= FLEXRAY_GetNumbOfStaticSlots(inst))
                    {
                        /*Set payload length for static slots */
                        pIndConfig->payloadLength =  (uint8)(FLEXRAY_GetPayloadLengthStatic(inst));
                    }
                    Flexray_calCrc(pIndConfig->payloadLength, pIndConfig->frameID, FALSE, FALSE, &(pIndConfig->headerCrc));
                    (*pHeaderData)[1] = (pIndConfig->PPI ? 0x40U : 0x0U) | ((uint8)(pIndConfig->frameID >> 8U));
                    (*pHeaderData)[0] = (uint8) pIndConfig->frameID;
                    (*pHeaderData)[2] = pIndConfig->payloadLength;
                    (*pHeaderData)[5] = (uint8)(pIndConfig->headerCrc >> 8U);
                    (*pHeaderData)[4] = (uint8)(pIndConfig->headerCrc);
                }
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_13();
                FLEXRAY_SetMBLockMode(inst, pIndConfig->MBIndex, FALSE);
                if (pIndConfig->enable)
                {
                    FLEXRAY_SetMBEnableMode(inst, MBIndex, TRUE);
                    if(FALSE == FLEXRAY_GetMBEnableStatus(inst, MBIndex))
                    {
                        ret = FLEXRAY_STATUS_ERROR;
                    }
                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_13();
            }
            else
            {
                ret = FLEXRAY_STATUS_ERROR;
            }
        }
        else
        {
            ret = FLEXRAY_STATUS_ERROR;
        }
    }
    else
    {
        ret = FLEXRAY_STATUS_ERROR;
    }
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetNMVector
 * Description   : This function will get the network management vector of last cycle.
 *
 * @implements Flexray_Ip_GetNMVector_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_GetNMVector(uint8 instNum,
                                                             uint8* data,
                                                             uint8* configLen)
{
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    uint8 i;
    uint8 nmvLength = 0U;
    uint16 nmvValue = 0U;
    boolean bDataCons;
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(*configLen <= 12U);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    inst = Flexray_Ip_apxBase[instNum];
    nmvLength = FLEXRAY_GetNMVLength(inst);
    bDataCons = TRUE;
    /* Copy all network management vector items */
    for(i = 0U; i < nmvLength; i++)
    {
        if((i & (uint8)0x01) == (uint8)0x00)
        {
            nmvValue = FLEXRAY_GetNMV(inst, (i >> 1U));
            if(data[i] != (uint8)((nmvValue & 0xFF00U) >> 8U))
            {
                /* Copy vector value into memory location given by reference*/
                data[i] = (uint8) ((nmvValue & 0xFF00U) >> 8U);
                /* Indicate data inconsitency => another check is required */
                bDataCons = FALSE;
            }
        }
        else
        {
            if(data[i] != (uint8)(nmvValue & 0x00FFU))
            {
                /* Copy vector value into memory location given by reference*/
                data[i] = (uint8) ((nmvValue & 0x00FFU));
                /* Indicate data inconsitency => another check is required */
                bDataCons = FALSE;
            }
        }
        if(i == *configLen)
        {
            break;
        }
    }

    if(TRUE == bDataCons)
    {
        retValue = FLEXRAY_STATUS_SUCCESS;
    }

    if(nmvLength != *configLen)
    {
        retValue = FLEXRAY_STATUS_ERROR;
        *configLen = nmvLength;
    }
    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetFifoLevel
 * Description   : Get the number of entries in fifo.
 *
 * @implements Flexray_Ip_GetFifoLevel_Activity
 *END**************************************************************************/
uint8 Flexray_Ip_GetFifoLevel(uint8 instNum,
                                              boolean isChnB)
{
    const FLEXRAY_Type* inst;
    uint8 fifoLevel;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    fifoLevel = FLEXRAY_FillLevelFiFo(inst, isChnB);

    return fifoLevel;
}

 /* FLEXRAY_AUTOSAR_MODE_USED */

void Flexray_Ip_GetPocStatus(uint8 instNum, uint16* data)
{
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */
    inst = Flexray_Ip_apxBase[instNum];

    data[0] = inst->PSR0;
    data[1] = inst->PSR1;
    data[2] = inst->PSR2;
    data[3] = inst->PSR3;

}

/***************************************************************************************************
* @function_name    Flexray_Ip_CheckCCAccess
*
* @brief            IP function for checking access to the CC
* @description      Checks access to the CC
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        Fr_CC_enabled - Indicates whether CC module should be enabled or not
* @param[in]        regMVR - Value of the MVR
* @return           ::Flexray_Ip_StatusType
*                       - E_OK      Function call finished successfully:
*                       - FLEXRAY_STATUS_ERROR  Function call aborted due to no access to the FlexRay CC
* @implements Flexray_Ip_CheckCCAccess_Activity
***************************************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_CheckCCAccess(uint8 instNum,
                                                               boolean Fr_CC_enabled,
                                                               uint16 regMVR)
{
    uint16 u16regVal_154;
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    /* Check if MVR register is correct */
    if (regMVR != inst->MVR)
    {/* MVR register is wrong, report error */
        retValue = FLEXRAY_STATUS_ERROR;
    }

    if (TRUE == Fr_CC_enabled)
    {
        if (FLEXRAY_STATUS_SUCCESS == retValue)
        {
            /* Check if FlexRay module is enabled */
            u16regVal_154 = inst->MCR;
            if ((u16regVal_154 & FLEXRAY_MCR_MEN_MASK) != FLEXRAY_MCR_MEN_MASK)
            {/* FlexRay module is not enabled, report error */
                retValue = FLEXRAY_STATUS_ERROR;
            }
        }
    }

    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_ClearDisableIRQs
 * Description   : Clears and disables IRQs.
 *
 * @implements Flexray_Ip_ClearDisableIRQs_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_ClearDisableIRQs(uint8 instNum)
{
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_ERROR;
    uint16 u16regVal;    /* Temporary variable for register access */
    uint16 u16timeout;  /* Temp variable for never-ending while loop protection */
    boolean bEnd = FALSE;  /* wait cycle finish or not */
    boolean bEnd2 = FALSE; /* wait cycle finish or not */
    uint16 u16tmpVal;
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_14();
    /* Clear MBIF flags and disable MB interrupts(MBIE), loop over all message buffers */
    for(u16tmpVal = 0U; u16tmpVal < FLEXRAY_NUMBER_MB; u16tmpVal++)
    {
        u16regVal = inst->MB[u16tmpVal].CCSR;
        /* Clear CMT and MBIE */
        u16regVal &= ~(uint16)(FLEXRAY_CCSR_CMT_MASK | FLEXRAY_CCSR_MBIE_MASK);
        u16regVal |= FLEXRAY_CCSR_MBIF_MASK; /* Clear MBIF */
        inst->MB[u16tmpVal].CCSR = u16regVal;
    }
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_14();
    u16timeout = 0U;
    /* Clear FIFO FNEBIF&FNEAIF flags - loop until FNEBIF&FNEAIF are not set, or timeout expired */
    while((FALSE == bEnd) && (FALSE == bEnd2))
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_14();
        u16regVal = inst->GIFER;
        /* Check FNEAIF and FNEBIF */
        if((FLEXRAY_GIFER_FAFAIF_MASK == (u16regVal & FLEXRAY_GIFER_FAFAIF_MASK)) || (FLEXRAY_GIFER_FAFBIF_MASK == (u16regVal & FLEXRAY_GIFER_FAFBIF_MASK)))
        {
            /* Clear FNEAIF and FNEBIF */
            u16regVal |= (uint16)(FLEXRAY_GIFER_FAFAIF_MASK | FLEXRAY_GIFER_FAFBIF_MASK);
            inst->GIFER = u16regVal;
        }
        else
        {/* FIFO interrupts are not set */
            bEnd = TRUE;
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_14();
        if(u16timeout > 255U)
        {/* timeout has expired */
            bEnd2 = TRUE;
        }
        u16timeout++;
    }
   /* SchM_ExitFr_FR_EXCLUSIVE_AREA_00(); */

    /* Verify timeout occured */
    if(FALSE == bEnd2)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_14();
        /* Clear all interrupt flags */

        inst->GIFER = (uint16)(FLEXRAY_GIFER_WUPIF_MASK | (uint16)(FLEXRAY_GIFER_FAFBIF_MASK | FLEXRAY_GIFER_FAFAIF_MASK));
        FLEXRAY_ClearAllProtocolInterruptFlag(inst);
        FLEXRAY_ClearAllCHIErrorInterruptFlag(inst);

        /* Disable all FlexRay interrupts */
        FLEXRAY_DisableAllGlobalInterrupt(inst);
        /* Check that interupts were disabled and no interrupt is pending */
        if(0U == inst->GIFER)
        {
            /* Disable interrupts */
            FLEXRAY_DisableAllProtocolInterrupt(inst);
            /* Check that interupts were disabled */
            if((0U == inst->PIER0) && (0U == inst->PIER1))
            {
                    /* All interrupts were disabled */
                    retValue = FLEXRAY_STATUS_SUCCESS;
            }
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_14();
    }
    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetGlobalTime
 * Description   : Clears and disables IRQs.
 *
 * @implements Flexray_Ip_GetGlobalTime_Activity
 *END**************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_GetGlobalTime(uint8 instNum,
                                                               uint8* cyclePtr,
                                                               uint16* macroTickPtr)
{
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    const FLEXRAY_Type* inst;
    uint32 u32regValue;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];
    /* Read both MTCTR and CYCTR in the same time */
    u32regValue = FLEXRAY_ReadCYCTR_MTCTR((const uint32 *)inst);
    *macroTickPtr = (uint16)(u32regValue);
    *cyclePtr = (uint8)(u32regValue >> 16U);

    /* Check whether the read value does not exceed configured one */
    if(((inst->PCR10) & 0x3fffU) <= *macroTickPtr)
    {
        /* Register read issue - use saturated value */
        *macroTickPtr = (uint16)(((inst->PCR10) & 0x3fffU) - 1U);
        /* Report error */
        retValue = FLEXRAY_STATUS_ERROR;
    }

    return retValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexray_Ip_GetChannelStatus
 * Description   : Returns status of channels A and B.
 *
 * @implements Flexray_Ip_GetChannelStatus_Activity
 *END**************************************************************************/
void Flexray_Ip_GetChannelStatus(uint8 instNum,
                                                 uint16* channelAStatusPtr,
                                                 uint16* channelBStatusPtr)
{
    uint16 tmpRegVal; /* Temporary variable for register access */
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    /* Read PSR2 register */
    tmpRegVal = inst->PSR2;

    *channelBStatusPtr = (uint16)((tmpRegVal & FLEXRAY_PSR2_CHB_MASK_U16) >> 2U);
    *channelAStatusPtr = (uint16)((tmpRegVal & FLEXRAY_PSR2_CHA_MASK_U16) << 4U);

    /* Read PSR3 register */
    tmpRegVal = inst->PSR3;

    *channelBStatusPtr |= ((tmpRegVal & FLEXRAY_PSR3_CHB_MASK_U16) >> 8U);
    *channelAStatusPtr |= (tmpRegVal & FLEXRAY_PSR3_CHA_MASK_U16);
}

/***************************************************************************************************
* @function_name    Flexray_Ip_GetClockCorrection
*
* @brief            FrIP function for the FLEXRAY_GetChannelStatus API
* @description      Read rate and offset correction values from FLEXRAY_RTCORVR and FLEXRAY_OFCORVR registers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       rateCorrectionPtr - Address of the variable the rate correction value is
*                                       stored to
* @param[out]       offsetCorrectionPtr - Address of the variable the offset correction value is
*                                         stored to
*
* @implements       Flexray_Ip_GetClockCorrection_Activity
***************************************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_GetClockCorrection(uint8 instNum,
                                                                    sint16* rateCorrectionPtr,
                                                                    sint32* offsetCorrectionPtr)
{
    uint32 u32RateOffsetCorrMax;
    sint16 s16tmpVal;
    uint32 u32tmpVal;
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    const FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    /* Get pRateCorrectionOut maximum magnitude from configuration */
    u32RateOffsetCorrMax = (((((uint32) inst->PCR14) << 16U) | inst->PCR15) >> 21U) & 0x000007FFU;

    /* Read signed extended rate correction value */
    *rateCorrectionPtr = (sint16)inst->RTCORVR;
    /* Prepare absolute value */
    s16tmpVal = *rateCorrectionPtr;
    if(s16tmpVal < 0)
    {
        s16tmpVal = (sint16)(-(s16tmpVal));
    }
    /* Check range */
    if(s16tmpVal > (sint16)(u32RateOffsetCorrMax))
    {
        /* Not-In-Range, use saturated value */
        *rateCorrectionPtr = (sint16)(u32RateOffsetCorrMax);
        /* Indicate error */
        retValue = FLEXRAY_STATUS_ERROR;
    }

    /* Get pOffsetCorrectionOut maximum magnitude from configuration */
    u32RateOffsetCorrMax =  ((((uint32) inst->PCR8) << 16U) | inst->PCR9 ) & 0x00003FFFU;
    /* Read offset correction value */
    u32tmpVal = (uint32)inst->OFCORVR;
    /* Extend the read value to 32-bit signed int and prepare absolute value */
    s16tmpVal = (sint16)(u32tmpVal);
    if(s16tmpVal < 0)
    {
        u32tmpVal |= 0xffff0000U;
        s16tmpVal = (sint16)(-(s16tmpVal));
    }
    /* Check range */
    if(s16tmpVal > (sint16)(u32RateOffsetCorrMax))
    {
        /* Not-In-Range, use saturated value */
        *offsetCorrectionPtr = (sint32)(u32RateOffsetCorrMax);
        /* Indicate error */
        retValue = FLEXRAY_STATUS_ERROR;
    }
    else
    {
        /* Store the output value */
        *offsetCorrectionPtr = (sint32)(u32tmpVal);
    }

    return retValue;
}

/***************************************************************************************************
* @function_name    Flexray_Ip_GetSyncFrameList
*
* @brief            FrIP function for the FLEXRAY_GetSyncFrameList API
* @description      Reads syncFrame List ID table from FlexRay memory
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       channelAEvenListPtr - Address of the variable the channel A even list is
*                                         stored to
* @param[out]       channelBEvenListPtr - Address of the variable the channel B even list is
*                                         stored to
* @param[out]       channelAOddListPtr - Address of the variable the channel A odd list is
*                                        stored to
* @param[out]       channelBOddListPtr - Address of the variable the channel B odd list is
*                                        stored to
* @return           ::Flexray_Ip_StatusType
*                       - E_OK      API call has been successful
*                       - FLEXRAY_STATUS_ERROR  API call aborted due to errors
*
* @implements        Flexray_Ip_GetSyncFrameList_Activity
***************************************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_GetSyncFrameList(uint8 instNum,
                                                                  const Flexray_Ip_ConfigType * config,
                                                                  uint8 listSize,
                                                                  uint16* channelAEvenListPtr,
                                                                  uint16* channelBEvenListPtr,
                                                                  uint16* channelAOddListPtr,
                                                                  uint16* channelBOddListPtr)
{
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_ERROR;
    uint8 index;                /* Temporary variable for copying process access */
    uint16 u16tmpSyncFrameCnt;  /* Temporary variable for Sync Frame Counter */
    uint8 u8tmpListSizeChAEven; /* Temporary variable for listSize chA even */
    uint8 u8tmpListSizeChBEven; /* Temporary variable for listSize chB even */
    uint8 u8tmpListSizeChAOdd;  /* Temporary variable for listSize chA odd */
    uint8 u8tmpListSizeChBOdd;  /* Temporary variable for listSize chB odd */
    uint8 u8tmpListSizeMax;     /* Temporary variable for max listSize */
    FLEXRAY_Type* inst;

#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    inst = Flexray_Ip_apxBase[instNum];

    if(15U >= listSize)
    {
        u8tmpListSizeMax = listSize;
    }
    else
    {/* Maximum 15 syncframes shall be supported */
        u8tmpListSizeMax = 15U;
    }
    /* Check if both EVAL OVAL bits are set */
    if((uint16)((uint16)FLEXRAY_SFTCCSR_EVAL_MASK | FLEXRAY_SFTCCSR_OVAL_MASK) == ((inst->SFTCCSR) & (uint16)((uint16)FLEXRAY_SFTCCSR_EVAL_MASK | FLEXRAY_SFTCCSR_OVAL_MASK)))
    {
        /* Lock even/odd cycle tables */
        inst->SFTCCSR = ((uint16)FLEXRAY_SFTCCSR_OLKT_MASK | FLEXRAY_SFTCCSR_ELKT_MASK);

        /* Check Even/Odd Cycle Table Lock Status */
        if((uint16)((uint16)FLEXRAY_SFTCCSR_ELKS_MASK | FLEXRAY_SFTCCSR_OLKS_MASK) == (((inst->SFTCCSR) & ((uint16)FLEXRAY_SFTCCSR_ELKS_MASK | ((uint16)FLEXRAY_SFTCCSR_OLKS_MASK | FLEXRAY_SFTCCSR_SIDEN_MASK)))))
        {
            /* Read Sync Frame Counter for all subset of sync table */
            u16tmpSyncFrameCnt = inst->SFCNTR;
            /* Prepare list size for channel A Even Sync Frames */
            u8tmpListSizeChAEven = (uint8)((u16tmpSyncFrameCnt & 0x0F00U) >> 8U);
            /* Prepare list size for channel B Even Sync Frames */
            u8tmpListSizeChBEven = (uint8)((u16tmpSyncFrameCnt & 0xF000U) >> 12U);
            /* Prepare list size for channel A Odd Sync Frames */
            u8tmpListSizeChAOdd = (uint8)(u16tmpSyncFrameCnt & 0x000FU);
            /* Prepare list size for channel B Odd Sync Frames */
            u8tmpListSizeChBOdd = (uint8)((u16tmpSyncFrameCnt & 0x00F0U) >> 4U);
            for(index = 0U; index < u8tmpListSizeMax; index++)
            {
                channelAEvenListPtr[index] = 0U;
                channelBEvenListPtr[index] = 0U;
                channelAOddListPtr[index] = 0U;
                channelBOddListPtr[index] = 0U;
                if(index < u8tmpListSizeChAEven)
                {/* Copy channel A Even Sync Frame ID Table */
                    channelAEvenListPtr[index] = ((volatile uint16*)((pointerSizeType)FLEXRAY_GetSysMemBaseAddr(inst) + (pointerSizeType)config->peConfig->SyncFrameTableOffset))[index];
                }
                if(index < u8tmpListSizeChBEven)
                {/* Copy channel B Even Sync Frame ID Table */
                    channelBEvenListPtr[index] = ((volatile uint16*)((pointerSizeType)FLEXRAY_GetSysMemBaseAddr(inst) + (pointerSizeType)config->peConfig->SyncFrameTableOffset + 0x001EU))[index];
                }
                if(index < u8tmpListSizeChAOdd)
                {/* Copy channel A Odd Sync Frame ID Table */
                    channelAOddListPtr[index] = ((volatile uint16*)((pointerSizeType)FLEXRAY_GetSysMemBaseAddr(inst) + (pointerSizeType)config->peConfig->SyncFrameTableOffset + 0x003CU))[index];
                }
                if(index < u8tmpListSizeChBOdd)
                {/* Copy channel B Odd Sync Frame ID Table */
                    channelBOddListPtr[index] = ((volatile uint16*)((pointerSizeType)FLEXRAY_GetSysMemBaseAddr(inst) + (pointerSizeType)config->peConfig->SyncFrameTableOffset + 0x005AU))[index];
                }
            }

            /* Unlock even/odd cycle table and enable generation*/
            inst->SFTCCSR = (uint16)((uint16)FLEXRAY_SFTCCSR_ELKT_MASK | ((uint16)FLEXRAY_SFTCCSR_OLKT_MASK | FLEXRAY_SFTCCSR_SIDEN_MASK));

            /* Check Even Cycle Table Lock Status */
            if(FLEXRAY_SFTCCSR_ELKS_MASK == (inst->SFTCCSR & FLEXRAY_SFTCCSR_ELKS_MASK))
            {
                /* Tables were not unlocked */
            }
            /* Check Odd Cycle Table Lock Status */
            else if(FLEXRAY_SFTCCSR_OLKS_MASK == (inst->SFTCCSR & FLEXRAY_SFTCCSR_OLKS_MASK))
            {
                /* Tables were not unlocked */
            }
            else
            {
                /* Tables were unlocked successfully*/
                retValue = FLEXRAY_STATUS_SUCCESS;
            }
        }
        else
        {
            /* Tables were not locked return FLEXRAY_STATUS_ERROR */
        }
    }
    else
    {
        /* EVAL OVAL bits are not set, table is not valid return FLEXRAY_STATUS_ERROR  */
    }

    return retValue;
}

/***************************************************************************************************
* @function_name    Flexray_Ip_GetNumOfStartFrames
*
* @brief            FrIP function for the FLEXRAY_GetNumOfStartupFrames
* @description      Reads number of startup frames
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        configParamIdx - Index of LPdu to be reconfigured
* @return           ::Flexray_Ip_StatusType
*                       - E_OK      Function call finished successfully:
*                       - FLEXRAY_STATUS_ERROR  Function call aborted due to no access to the FlexRay CC
*
* @implements        Flexray_Ip_GetNumOfStartFrames_Activity
***************************************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_GetNumOfStartFrames(uint8 instNum,
                                                                     uint8* numOfStartupFramesPtr)
{
    /* Set initial return value */
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    /* FlexRay 2.1 Rev A compliant hardware does not suppport accumulating the number of
       startupframes. The driver shall always assume 2 startup frames available */
    *numOfStartupFramesPtr = 2U;
    (void) instNum;
    return retValue;
}

/***************************************************************************************************
* @function_name    Flexray_Ip_ReadbackCCConfig
*
* @brief            FrIP function for the Fr_ControllerInit API
* @description      Read back and compare cluster and configuration values to reference values
*                   held in the configuration.
* @param[in]        ctrlIdx - Index of FlexRay CC
* @return           ::Flexray_Ip_StatusType
*                       - E_OK      Configuration is OK
*                       - FLEXRAY_STATUS_ERROR  Error in configuration was found
*
* @implements        Flexray_Ip_ReadbackCCConfig_Activity
***************************************************************************************************/
Flexray_Ip_StatusType Flexray_Ip_ReadbackCCConfig(uint8 instNum,
                                                                  const Flexray_Ip_PeConfigType* peConfig)
{
#if (STD_ON == FLEXRAY_DEV_ERROR_DETECT)
    DevAssert(instNum < FLEXRAY_INSTANCE_COUNT);
#endif /* (STD_ON == FLEXRAY_DEV_ERROR_DETECT) */

    const FLEXRAY_Type* base = Flexray_Ip_apxBase[instNum];
    Flexray_Ip_StatusType retValue = FLEXRAY_STATUS_SUCCESS;
    uint8 i;
    uint16  configValsArr[31U];
    const uint32 regAddr = (uint32)(&(base->PCR0));
    const volatile uint16 *memValsArr = (const volatile uint16 *)regAddr;

    /* compute members of configValsArr*/
    configValsArr[0U]  = FLEXRAY_PCR0_action_point_offset((uint16)peConfig->gdActionPointOffset - 1U) | FLEXRAY_PCR0_static_slot_length(peConfig->gdStaticSlot);
    configValsArr[1U]  = FLEXRAY_PCR1_macro_after_first_static_slot(peConfig->gMacroPerCycle - peConfig->gdStaticSlot);
    configValsArr[2U]  = FLEXRAY_PCR2_minislot_after_action_point((uint16)peConfig->gdMinislot - (uint16)peConfig->gdMinislotActionPointOffset - 1U) | FLEXRAY_PCR2_number_of_static_slots(peConfig->gNumberOfStaticSlots);
    configValsArr[3U]  = FLEXRAY_PCR3_wakeup_symbol_rx_low(peConfig->gdWakeupSymbolRxLow) |  FLEXRAY_PCR3_minislot_action_point_offset((uint16)peConfig->gdMinislotActionPointOffset - 1U) | FLEXRAY_PCR3_coldstart_attempts(peConfig->gColdstartAttempts);
    configValsArr[4U]  = FLEXRAY_PCR4_cas_rx_low_max((uint16)peConfig->gdCASRxLowMax - 1U) | FLEXRAY_PCR4_wakeup_symbol_rx_window(peConfig->gdWakeupSymbolRxWindow);
    configValsArr[5U]  = FLEXRAY_PCR5_tss_transmitter(peConfig->gdTSSTransmitter) | FLEXRAY_PCR5_wakeup_symbol_tx_low(peConfig->gdWakeupSymbolTxLow) | FLEXRAY_PCR5_wakeup_symbol_rx_idle(peConfig->gdWakeupSymbolRxIdle);
    configValsArr[6U]  = FLEXRAY_PCR6_symbol_window_after_action_point((uint16)peConfig->gdSymbolWindow - (uint16)peConfig->gdActionPointOffset - 1U) | FLEXRAY_PCR6_macro_initial_offset_a(peConfig->pMacroInitialOffsetA);
    configValsArr[7U]  = FLEXRAY_PCR7_decoding_correction_b(peConfig->pDecodingCorrection + peConfig->pDelayCompensationB + 2U) | FLEXRAY_PCR7_micro_per_macro_nom_half((uint8)((peConfig->pMicroPerMacroNom)/2U));
    configValsArr[8U]  = FLEXRAY_PCR8_max_without_clock_correction_fatal(peConfig->gMaxWithoutClockCorrectionFatal) | FLEXRAY_PCR8_max_without_clock_correction_passive(peConfig->gMaxWithoutClockCorrectionPassive) | FLEXRAY_PCR8_wakeup_symbol_tx_idle(peConfig->gdWakeupSymbolTxIdle);
    configValsArr[9U]  = FLEXRAY_PCR9_minislot_exists(convertBoolInt(peConfig->gMiniSlotExists)) | FLEXRAY_PCR9_symbol_window_exists(convertBoolInt(peConfig->gSymbolWindowExists)) | FLEXRAY_PCR9_offset_correction_out(peConfig->pOffsetCorrectionOut);
    configValsArr[10U] = FLEXRAY_PCR10_single_slot_enabled(convertBoolInt(peConfig->pSingleSlotEnabled)) | FLEXRAY_PCR10_wakeup_channel(convertBoolInt(peConfig->pWakeupChannel)) | FLEXRAY_PCR10_macro_per_cycle(peConfig->gMacroPerCycle);
    configValsArr[11U] = FLEXRAY_PCR11_key_slot_used_for_startup(convertBoolInt(peConfig->pKeySlotUsedForStartup)) | FLEXRAY_PCR11_key_slot_used_for_sync(convertBoolInt(peConfig->pKeySlotUsedForSync)) | FLEXRAY_PCR11_offset_correction_start(peConfig->gOffsetCorrectionStart);
    configValsArr[12U] = FLEXRAY_PCR12_allow_passive_to_active(peConfig->pAllowPassiveToActive) | FLEXRAY_PCR12_key_slot_header_crc(peConfig->keySlotHeaderCrc);
    configValsArr[13U] = FLEXRAY_PCR13_first_minislot_action_point_offset((peConfig->gdActionPointOffset > peConfig->gdMinislotActionPointOffset) ? ((uint16)peConfig->gdActionPointOffset - 1U) : ((uint16)peConfig->gdMinislotActionPointOffset - 1U)) | FLEXRAY_PCR13_static_slot_after_action_point(peConfig->gdStaticSlot - (uint16)peConfig->gdActionPointOffset - 1U);
    configValsArr[14U] = FLEXRAY_PCR14_rate_correction_out(peConfig->pRateCorrectionOut) | FLEXRAY_PCR14_listen_timeout((peConfig->pdListenTimeout - 1U) >> 16U);
    configValsArr[15U] = FLEXRAY_PCR15_listen_timeout((peConfig->pdListenTimeout - 1U) & 0xFFFFU);
    configValsArr[16U] = FLEXRAY_PCR16_macro_initial_offset_b(peConfig->pMacroInitialOffsetB) | FLEXRAY_PCR16_noise_listen_timeout(((peConfig->gListenNoise * peConfig->pdListenTimeout) - 1U) >> 16U);
    configValsArr[17U] = FLEXRAY_PCR17_noise_listen_timeout(((peConfig->gListenNoise * peConfig->pdListenTimeout) - 1U) & 0xFFFFU);
    configValsArr[18U] = FLEXRAY_PCR18_wakeup_pattern(peConfig->pWakeupPattern) | FLEXRAY_PCR18_key_slot_id(peConfig->pKeySlotId);
    configValsArr[19U] = FLEXRAY_PCR19_decoding_correction_a(peConfig->pDecodingCorrection + peConfig->pDelayCompensationA + 2U) | FLEXRAY_PCR19_payload_length_static(peConfig->gPayloadLengthStatic);
    configValsArr[20U] = FLEXRAY_PCR20_micro_initial_offset_a(peConfig->pMicroInitialOffsetA) | FLEXRAY_PCR20_micro_initial_offset_b(peConfig->pMicroInitialOffsetB);
    configValsArr[21U] = FLEXRAY_PCR21_latest_tx(peConfig->gNumberOfMinislots - peConfig->pLatestTx);
    configValsArr[22U] = FLEXRAY_PCR22_comp_accepted_startup_range_a(peConfig->pdAcceptedStartupRange - peConfig->pDelayCompensationA) | FLEXRAY_PCR22_micro_per_cycle(peConfig->pMicroPerCycle >> 16U);
    configValsArr[23U] = FLEXRAY_PCR23_micro_per_cycle(peConfig->pMicroPerCycle & 0xFFFFU);
    configValsArr[24U] = FLEXRAY_PCR24_cluster_drift_damping(peConfig->pClusterDriftDamping) | FLEXRAY_PCR24_max_payload_length_dynamic(peConfig->pPayloadLengthDynMax) | FLEXRAY_PCR24_micro_per_cycle_min((peConfig->pMicroPerCycle - peConfig->pdMaxDrift) >> 16U);
    configValsArr[25U] = FLEXRAY_PCR25_micro_per_cycle_min((peConfig->pMicroPerCycle - peConfig->pdMaxDrift) & 0xFFFFU);
    configValsArr[26U] = FLEXRAY_PCR26_allow_halt_due_to_clock(convertBoolInt(peConfig->pAllowHaltDueToClock)) | FLEXRAY_PCR26_comp_accepted_startup_range_b(peConfig->pdAcceptedStartupRange - peConfig->pDelayCompensationB) | FLEXRAY_PCR26_micro_per_cycle_max((peConfig->pMicroPerCycle + peConfig->pdMaxDrift) >> 16U);
    configValsArr[27U] = FLEXRAY_PCR27_micro_per_cycle_max((peConfig->pMicroPerCycle + peConfig->pdMaxDrift) & 0xFFFFU);
    configValsArr[28U] = FLEXRAY_PCR28_dynamic_slot_idle_phase(peConfig->gdDynamicSlotIdlePhase) | FLEXRAY_PCR28_macro_after_offset_correction(peConfig->gMacroPerCycle - peConfig->gOffsetCorrectionStart);
    configValsArr[29U] = FLEXRAY_PCR29_extern_offset_correction(peConfig->pExternOffsetCorrection) | FLEXRAY_PCR29_minislots_max(peConfig->gNumberOfMinislots - 1U);
    configValsArr[30U] = FLEXRAY_PCR30_sync_node_max(peConfig->gSyncNodeMax);

    /* compare configured values with the ones in memory */
    for(i = 0U; i < 31U; i++)
    {
        if(memValsArr[i] != configValsArr[i])
        {
            retValue = FLEXRAY_STATUS_ERROR;
            break;
        }
    }

    return retValue;
}

#ifdef FLEXRAY_43_LLCE
/*************************************************************************************************
* @function_name    Flexray_Llce_AckFrpeIRQ
*
* @brief            Clear interrupt flag from FRPE core
* @description      Clears the interrupt flag from Core2Core module
* @param[in]        none
* @return           none
**************************************************************************************************/
void Flexray_Llce_AckFrpeIRQ(void)
{
    /* @violates @ref Fr_Flexray_c_REF_3 */
    /* @violates @ref Fr_Flexray_c_REF_4 */
    LLCE_FRPE2HOST_CLEAR_INTERRUPT(0);
}
#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


#ifdef __cplusplus
}
#endif
