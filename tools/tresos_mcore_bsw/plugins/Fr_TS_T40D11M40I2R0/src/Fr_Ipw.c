/**
*   @file    Fr_Ipw.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Fr - module interface.
*   @implements  Fr_Ipw.c_Artifact
*
*   @addtogroup FR_DRIVER
*   @{
*/
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
*   @file Fr_Ipw.c
*   @implements  Fr_Ipw.c_Artifact
*   @addtogroup FR_DRIVER
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
#include "Fr_Ipw.h"
#include "Flexray_Ip.h"

#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_IPW_VENDOR_ID_C                        43
#define FR_IPW_AR_RELEASE_MAJOR_VERSION_C         4
#define FR_IPW_AR_RELEASE_MINOR_VERSION_C         4
#define FR_IPW_AR_RELEASE_REVISION_VERSION_C      0
#define FR_IPW_SW_MAJOR_VERSION_C                 4
#define FR_IPW_SW_MINOR_VERSION_C                 0
#define FR_IPW_SW_PATCH_VERSION_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_Ipw.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID_C != FR_IPW_VENDOR_ID)
    #error "Fr_Ipw.c and Fr_Ipw.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Ipw.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION_C    != FR_IPW_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION_C    != FR_IPW_AR_RELEASE_MINOR_VERSION) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION_C != FR_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Ipw.c and Fr_Ipw.h are different"
#endif
/* Check if current file and Fr_Ipw.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION_C != FR_IPW_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION_C != FR_IPW_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION_C != FR_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Ipw.c and Fr_Ipw.h are different"
#endif

/* Check if current file and Flexray_Ip.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID_C != FLEXRAY_IP_VENDOR_ID)
    #error "Fr_Ipw.c and Flexray_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_AR_RELEASE_MINOR_VERSION) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Ipw.c and Flexray_Ip.h are different"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION_C != FLEXRAY_IP_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION_C != FLEXRAY_IP_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION_C != FLEXRAY_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Ipw.c and Flexray_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h header file are of the same Autosar version */
    #if((FR_IPW_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (FR_IPW_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr_Ipw.c and Dem.h are different"
    #endif
#endif
#endif /* CHECK_AUTOSAR_VERSION */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

static Std_ReturnType Fr_Ipw_GetWakeupState ( uint16 regValuePSR0,
                                              Fr_WakeupStatusType* wakeupStatusPtr);
static Std_ReturnType Fr_Ipw_GetSlotMode( uint16 regValuePSR0,
                                          Fr_SlotModeType* slotModePtr);
static Std_ReturnType Fr_Ipw_GetErrorMode( uint16 regValuePSR0,
                                           Fr_ErrorModeType* errorModePtr);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/***************************************************************************************************
 * @function_name       Fr_Ipw_GetgNumberOfStaticSlots
 *
 * @brief               Returns the number of static slots from the
 *                      configuration.
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return uint16
***************************************************************************************************/
uint16 Fr_Ipw_GetgNumberOfStaticSlots
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    /* Number of static slots*/
    return ((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->peConfig->gNumberOfStaticSlots;
}

/***************************************************************************************************
 * @function_name       Fr_Ipw_GetgChannel
 *
 * @brief               Checks the configuration for current channel usage.
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return uint8
***************************************************************************************************/
uint8 Fr_Ipw_GetgChannel
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    uint8 gChannel = 0U;
    /* Position 0 = ChA, position 1 = ChB */
    if(((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->ccConfig->channelA == TRUE)
    {
        gChannel += 1U;
    }
    if(((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->ccConfig->channelB == TRUE)
    {
        gChannel += 2U;
    }
    return gChannel;
}

/***************************************************************************************************
 * @function_name       Fr_Ipw_GetgPayloadLengthStatic
 *
 * @brief               Returns the static payload length.
 *
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return uint8
***************************************************************************************************/
uint8 Fr_Ipw_GetgPayloadLengthStatic
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    return (uint8)((uint16)(((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->peConfig->gPayloadLengthStatic) * 2U);
}

/***************************************************************************************************
 * @function_name       Fr_Ipw_Gettimer2IsRelative
 *
 * @brief               Returns the state of timer2IsRelative, that can be
 *                      either relative or absolute.
 *
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return boolean      True - timer 2 is relative.
***************************************************************************************************/
boolean Fr_Ipw_Gettimer2IsRelative
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    return ((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->timer2IsRelative;
}


#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/***************************************************************************************************
* @function_name    Fr_Ipw_DemSetEventStatus
*
* @brief            FrIP function in order to report DEM error.
* @details          Report DEM error.
* @param[in]        ccLpduInfo  - Store the reference to Rx MB configuration
* @param[in]        u16StatusReport - The status of DEM event.
***************************************************************************************************/

static void Fr_Ipw_DemSetEventStatus
(
    Fr_CCLpduInfoType ccLpduInfo,
    Dem_EventStatusType u16StatusReport
)
{
    Dem_EventIdType FR_E_LPDU_SLOTSTATUS;
    if(TRUE == ccLpduInfo.DemFTSlotSTatusRefExist)
    {
        FR_E_LPDU_SLOTSTATUS = ccLpduInfo.DemFTSlotStatus;
        (void)Dem_SetEventStatus(FR_E_LPDU_SLOTSTATUS, u16StatusReport);
    }
}

#endif

/***************************************************************************************************
* @function_name    Fr_Ipw_ControllerInit
*
* @brief            LLD function for FlexRay CC configuration
* @details          Writes values from configuration file into the Module Configuration Register
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           Std_ReturnType
*                       - E_OK      FR CC was successfully reinitialized
*                       - E_NOT_OK  not possible to move FR CC to default config state
***************************************************************************************************/
Std_ReturnType Fr_Ipw_ControllerInit
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    Std_ReturnType retVal = E_NOT_OK;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (const Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_Init(pCtrlCfg->CtrlIdx, pIpConfigPtr, pCtrlCfg->IpStateAllocPtr))
    {
        retVal = E_OK;
    }
    return retVal;
}

/**************************************************************************************************
* @function_name    Fr_IPW_DeInit
*
* @brief            LLD function for FlexRay Deinitialization
* @details          Function de-initialize the FlexRay CC
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           none
**************************************************************************************************/

Std_ReturnType Fr_Ipw_DeInit
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    Std_ReturnType retVal = E_NOT_OK;
    if(FLEXRAY_STATUS_SUCCESS == Flexray_Ip_Deinit(pCtrlCfg->CtrlIdx))
    {
        retVal = E_OK;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_CheckCCAccess
*
* @brief            LLD function for checking access to the CC
* @details          Function checks whether the FlexRay CC is accessible or not
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        Fr_CC_enabled Indicates whether CC module should be enabled or not
* @return           Std_ReturnType
*                       - E_OK      CC is accessible
*                       - E_NOT_OK  CC is not accessible
***************************************************************************************************/
Std_ReturnType Fr_Ipw_CheckCCAccess
(
    const Fr_CtrlCfgType* pCtrlCfg,
    const boolean Fr_CC_enabled
)
{
    /* Check Module Version Register */
    return  (Std_ReturnType)Flexray_Ip_CheckCCAccess(pCtrlCfg->CtrlIdx, Fr_CC_enabled, FLEXRAY_MVR_U16);

}

/***************************************************************************************************
* @function_name    Fr_Ipw_ClearDisableIRQs
*
* @brief            LLD function which clears all interrupt flags and disables all interrupts.
* @details          Function clears all MBIF flags and clears GIFER, PIFR0, PIFR1, PIER0 and PIER1
*                   registers.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      All interrupt flags were cleared and all interrupts were
*                                   disabled
*                       - E_NOT_OK  Some interrupt flag was not clear or some interrupt was not
*                                   disabled
***************************************************************************************************/
Std_ReturnType Fr_Ipw_ClearDisableIRQs
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    /* note: we can't touch hw access functions.
        those irq ones are used by functions only.
        better to implement our own?
        can we take static out of hw access functions?*/

    return (Std_ReturnType)Flexray_Ip_ClearDisableIRQs(pCtrlCfg->CtrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_DisableTimers
*
* @brief            LLD function which disables timers.
* @details          Function clears all T1SP and T2SP bits in the TICCR register.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           none
***************************************************************************************************/
void Fr_Ipw_DisableTimers
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    Flexray_Ip_StopTimer(pCtrlCfg->CtrlIdx, FLEXRAY_TIMER1);
    Flexray_Ip_StopTimer(pCtrlCfg->CtrlIdx, FLEXRAY_TIMER2);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetPOCState
*
* @brief            LLD function for quering the controller POC status
* @details          Read the FlexRay controller Protocol Status Register 1.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[out]       pocStatus - Address of the variable wher the Protocol status is stored to
* @return           uint16
***************************************************************************************************/
Fr_POCStateType Fr_Ipw_GetPOCState
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    Flexray_Ip_PocStateType currentState;
    Fr_POCStateType retValue;
    currentState = Flexray_Ip_GetCurrentState(pCtrlCfg->CtrlIdx);
    switch(currentState)
    {
        case FLEXRAY_STATE_CONFIG:
            retValue = FR_POCSTATE_CONFIG;
            break;

        case FLEXRAY_STATE_DEFAULT_CONFIG:
            retValue = FR_POCSTATE_DEFAULT_CONFIG;
            break;

        case FLEXRAY_STATE_HALT:
            retValue = FR_POCSTATE_HALT;
            break;

        case FLEXRAY_STATE_NORMAL_ACTIVE:
            retValue = FR_POCSTATE_NORMAL_ACTIVE;
            break;

        case FLEXRAY_STATE_NORMAL_PASSIVE:
            retValue = FR_POCSTATE_NORMAL_PASSIVE;
            break;

        case FLEXRAY_STATE_READY:
            retValue = FR_POCSTATE_READY;
            break;

        case FLEXRAY_STATE_STARTUP:
            retValue = FR_POCSTATE_STARTUP;
            break;
        default:
            retValue = FR_POCSTATE_WAKEUP;
            break;
    }
    return retValue;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetPOCStatus
*
* @brief            LLD function for quering the controller POC status
* @details          Read the FlexRay controller Protocol Status Register 1.
* @param[in]        pCtrlCfg      Pointer config of FlexRay CC
* @param[out]       pocStatusPtr  Address of the variable wher the Protocol status is stored to
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Reserved value was read
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetPOCStatus
(
    const Fr_CtrlCfgType* pCtrlCfg,
    Fr_POCStatusType* pocStatusPtr
)

{
    uint8 instNum = pCtrlCfg->CtrlIdx;
    Std_ReturnType retVal = E_OK;
    uint16 PocStatus[4];
    Flexray_Ip_StartupStatusType startupStatus;
    Flexray_Ip_GetPocStatus(pCtrlCfg->CtrlIdx , PocStatus);
    if(FLEXRAY_PSR1_FRZ_U16 == ((uint16)(PocStatus[1]) & FLEXRAY_PSR1_FRZ_U16))
    {
        pocStatusPtr->State = FR_POCSTATE_HALT;
        pocStatusPtr->Freeze = TRUE;
    }
    else
    {
        pocStatusPtr->State = Fr_Ipw_GetPOCState(pCtrlCfg);
        pocStatusPtr->Freeze = FALSE;
    }
    if (FR_POCSTATE_STARTUP == pocStatusPtr->State)
    {
        startupStatus = Flexray_Ip_GetStartupStatus(instNum);
        switch(startupStatus)
        {
            case FLEXRAY_STARTUP_UNDEFINED:
                pocStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
                retVal = E_NOT_OK;
                break;

            case FLEXRAY_COLDSTART_LISTEN:
                pocStatusPtr->StartupState = FR_STARTUP_COLDSTART_LISTEN;
                break;

            case FLEXRAY_INTE_COLDSTART_CHECK:
                pocStatusPtr->StartupState = FR_STARTUP_INTEGRATION_COLDSTART_CHECK;
                break;

            case FLEXRAY_COLDSTART_JOIN:
                pocStatusPtr->StartupState = FR_STARTUP_COLDSTART_JOIN;
                break;

            case FLEXRAY_COLDSTART_COLLISION:
                pocStatusPtr->StartupState = FR_STARTUP_COLDSTART_COLLISION_RESOLUTION;
                break;

            case FLEXRAY_COLDSTART_CONS_CHECK:
                pocStatusPtr->StartupState = FR_STARTUP_COLDSTART_CONSISTENCY_CHECK;
                break;

            case FLEXRAY_INTE_LISTEN:
                pocStatusPtr->StartupState = FR_STARTUP_INTEGRATION_LISTEN;
                break;

            case FLEXRAY_INIT_SCHEDULE:
                pocStatusPtr->StartupState = FR_STARTUP_INITIALIZE_SCHEDULE;
                break;

            case FLEXRAY_INTE_CHECK:
                pocStatusPtr->StartupState = FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK;
                break;

            case FLEXRAY_COLDSTART_GAP:
                pocStatusPtr->StartupState = FR_STARTUP_COLDSTART_GAP;
                break;

            default:
                pocStatusPtr->StartupState = FR_STARTUP_EXTERNAL_STARTUP;
                break;
        }
    }
    else
    {
        pocStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
    }
    if((Std_ReturnType)E_NOT_OK == (Std_ReturnType) Fr_Ipw_GetWakeupState(PocStatus[0],&(pocStatusPtr->WakeupStatus)))
    {
        retVal = E_NOT_OK;
    }
    if((Std_ReturnType)E_NOT_OK == (Std_ReturnType) Fr_Ipw_GetSlotMode(PocStatus[0],&(pocStatusPtr->SlotMode)))
    {
        retVal = E_NOT_OK;
    }
    if((Std_ReturnType)E_NOT_OK == (Std_ReturnType) Fr_Ipw_GetErrorMode(PocStatus[0],&(pocStatusPtr->ErrorMode)))
    {
        retVal = E_NOT_OK;
    }

    if(FLEXRAY_PSR1_HHR_U16 == ((uint16)(PocStatus[1]) & FLEXRAY_PSR1_HHR_U16))
    {
        pocStatusPtr->CHIHaltRequest = TRUE;
    }
    else
    {
        pocStatusPtr->CHIHaltRequest = FALSE;
    }

     if(FLEXRAY_PSR1_CPN_U16 == ((uint16)(PocStatus[1]) & FLEXRAY_PSR1_CPN_U16))
    {
        pocStatusPtr->ColdstartNoise = TRUE;
    }
    else
    {
        pocStatusPtr->ColdstartNoise = FALSE;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetWakeupState
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @details          The FlexRay controller wakeup state is determined here.
* @param[in]        regValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       wakeupStatusPtr - Address the Wakeup status is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static Std_ReturnType Fr_Ipw_GetWakeupState
(
    uint16 regValuePSR0,
    Fr_WakeupStatusType* wakeupStatusPtr
)
{
    /* Initialize variable */
    Std_ReturnType retVal = (Std_ReturnType)(E_OK);

    /* Determine the wakeup status */
    switch(regValuePSR0 & FLEXRAY_PSR0_WAKEUPSTATUS_MASK)
    {
        case FLEXRAY_PSR0_WUP_RH_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_RECEIVED_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_RW_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_RECEIVED_WUP;
            break;

        case FLEXRAY_PSR0_WUP_HC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_COLLISION_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_WC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_COLLISION_WUP;
            break;

        case FLEXRAY_PSR0_WUP_UC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_COLLISION_UNKNOWN;
            break;

        case FLEXRAY_PSR0_WUP_T_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_TRANSMITTED;
            break;

        case FLEXRAY_PSR0_WUP_UD_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_UNDEFINED;
            break;

        default:
            /* Reserved value cannot occur */
            *wakeupStatusPtr = FR_WAKEUP_UNDEFINED;
            retVal = (Std_ReturnType)(E_NOT_OK);
            break;
    }

    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetSlotMode
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @details          The FlexRay controller slot mode is determined here.
* @param[in]        regValuePSR0  Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       slotModePtr   Address the Slot mode is stored to.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static Std_ReturnType Fr_Ipw_GetSlotMode
(
    uint16 regValuePSR0,
    Fr_SlotModeType* slotModePtr
)
{
    /* Initialize variable */
    Std_ReturnType retVal = E_OK;

    /* Determine the slot mode */
    switch(regValuePSR0 & FLEXRAY_PSR0_SLOTMODE_MASK)
    {
        case FLEXRAY_PSR0_SLOTMODE_SINGLE_U16:
            /* Store the slot mode to location referenced by given pointer */
            *slotModePtr = FR_SLOTMODE_SINGLE;
            break;

        case FLEXRAY_PSR0_SLOTMODE_ALL_PENDING_U16:
            /* Store the slot mode to location referenced by given pointer */
            *slotModePtr = FR_SLOTMODE_ALL_PENDING;
            break;

        case FLEXRAY_PSR0_SLOTMODE_ALL_U16:
            /* Store the slot mode to location referenced by given pointer */
            *slotModePtr = FR_SLOTMODE_ALL;
            break;

        default:
            /* Reserved value cannot occur */
            *slotModePtr = FR_SLOTMODE_SINGLE;
            retVal = E_NOT_OK;
            break;
    }

    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetErrorMode
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @details          The FlexRay controller error mode is determined here.
* @param[in]        regValuePSR0  Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       errorModePtr  Address the Error mode is stored to.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static Std_ReturnType Fr_Ipw_GetErrorMode
(
    uint16 regValuePSR0,
    Fr_ErrorModeType* errorModePtr
)
{
    /* Initialize variable */
    Std_ReturnType retVal = (Std_ReturnType)(E_OK);

    /* Determine the error mode */
    switch(regValuePSR0 & FLEXRAY_PSR0_ERRMODE_MASK)
    {
        case FLEXRAY_PSR0_ERRMODE_ACTIVE_U16:
            /* Store the Error mode to location referenced by given pointer */
            *errorModePtr = FR_ERRORMODE_ACTIVE;
            break;

        case FLEXRAY_PSR0_ERRMODE_PASSIVE_U16:
            /* Store the Error mode to location referenced by given pointer */
            *errorModePtr = FR_ERRORMODE_PASSIVE;
            break;

        case FLEXRAY_PSR0_ERRMODE_COMM_HALT_U16:
            /* Store the Error mode to location referenced by given pointer */
            *errorModePtr = FR_ERRORMODE_COMM_HALT;
            break;

        default:
            /* Reserved value cannot occur */
            *errorModePtr = FR_ERRORMODE_ACTIVE;
            retVal = (Std_ReturnType)(E_NOT_OK);
            break;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_InvokeCHIcommand
*
* @brief            LLD function for invoking POCCMD commands
* @details           Invokes required CHI command
* @param[in]        pCtrlCfg    Pointer config of FlexRay CC
* @param[in]        chiCommand  required CHI command
* @return           Std_ReturnType:
*                       - E_OK      CHI command was accepted by PE
*                       - E_NOT_OK  CHI command was not accepted by PE due to BSY flag
***************************************************************************************************/
Std_ReturnType Fr_Ipw_InvokeCHICommand
(
    const Fr_CtrlCfgType* pCtrlCfg,
    Flexray_Ip_ChiCmdType chiCommand
)
{
   return (Std_ReturnType) Flexray_Ip_SendCHICommand(pCtrlCfg->CtrlIdx, chiCommand);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_AckAbsTimerIRQ
*
* @brief            LLD function for the Fr_AckAbsoluteTimerIRQ API
* @details          Ack the FlexRay CC absolute timer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        timerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_Ipw_AckAbsoluteTimerIRQ
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 timerIdx
)
{
    if(0U == timerIdx)
    {   /* Timer 1 */
        Flexray_Ip_ClearProtocolInterruptFlag(pCtrlCfg->CtrlIdx, FLEXRAY_T1_EXPIRED); /* Clear flag */
    }
    else
    {   /* Timer 2 */
        Flexray_Ip_ClearProtocolInterruptFlag(pCtrlCfg->CtrlIdx, FLEXRAY_T2_EXPIRED); /* Clear flag */
    }

#ifdef FLEXRAY_43_LLCE
    Flexray_Llce_AckFrpeIRQ();
#endif

}

/***************************************************************************************************
* @function_name    Fr_Ipw_CancelAbsoluteTimer
*
* @brief            LLD function for the Fr_CancelAbsoluteTimer API
* @details          Cancel the FlexRay CC absolute timer
* @param[in]        pCtrlCfg   Pointer config of FlexRay CC
* @param[in]        timerIdx   Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_Ipw_CancelAbsoluteTimer
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 timerIdx
)
{
    /* first we check which timer is running. we will only stop the timer */
    if(0U == timerIdx)
    {   /* Timer 1 should be stoped */
        Flexray_Ip_StopTimer(pCtrlCfg->CtrlIdx,FLEXRAY_TIMER1);
    }
    else
    {   /* Timer 2 should be stoped */
        Flexray_Ip_StopTimer(pCtrlCfg->CtrlIdx,FLEXRAY_TIMER2);
    }
}

/***************************************************************************************************
* @function_name    Fr_Ipw_DisableAbsoluteTimerIRQ
*
* @brief            LLD function for the Fr_DisableAbsoluteTimerIRQ API
* @details          Disable the FlexRay CC absolute timer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        timerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_Ipw_DisableAbsoluteTimerIRQ
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 timerIdx
)
{
    if(0U == timerIdx)
    {   /* Timer 1 irq should be disabled */
        Flexray_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx,FLEXRAY_T1_EXPIRED,FALSE);
    }
    else
    {   /* Timer 2 irq should be disabled */
        Flexray_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx,FLEXRAY_T2_EXPIRED,FALSE);
    }

}

/***************************************************************************************************
* @function_name    Fr_Ipw_EnableAbsoluteTimerIRQ
*
* @brief            LLD function for the Fr_EnableAbsoluteTimerIRQ
* @details          Enable the FlexRay CC absolute timer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        timerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_Ipw_EnableAbsoluteTimerIRQ
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 timerIdx
)
{
     if(0U == timerIdx)
    {   /* Timer 1 irq should be enabled */
        Flexray_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_T1_EXPIRED, TRUE);
        Flexray_Ip_SetGlobalInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_PROTOCOL_INTERRUPT, TRUE);

    }
    else
    {   /* Timer 2 irq should be enabled */
        Flexray_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_T2_EXPIRED, TRUE);
        Flexray_Ip_SetGlobalInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_PROTOCOL_INTERRUPT, TRUE);
    }
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetAbsoluteTimerIRQStatus
*
* @brief            LLD function for the Fr_GetAbsoluteTimerIRQStatus
* @details          Check whether absolute timer inerrupt flag is pending
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        timerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           boolean
*                     - (boolean)TRUE - Interrupt is pending
*                     - (boolean)FALSE - Interrupt is not pending
***************************************************************************************************/
boolean Fr_Ipw_GetAbsoluteTimerIRQStatus
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 timerIdx
)
{
    boolean retVal = FALSE;
    if(0U == timerIdx)
    {
        retVal = Flexray_Ip_GetProtocolInterruptFlag(pCtrlCfg->CtrlIdx,FLEXRAY_T1_EXPIRED);
    }
    else
    {
        retVal = Flexray_Ip_GetProtocolInterruptFlag(pCtrlCfg->CtrlIdx,FLEXRAY_T2_EXPIRED);
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_SetAbsoluteTimer
*
* @brief            LLD function for the Fr_SetAbsoluteTimer API
* @details          Store information about absolute timer into the FlexRay CC registers
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        timeridx  Index of FlexRay timer
* @param[in]        cycle     Cycle the timer shall elapse in
* @param[in]        offset    Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                             elapse at
* @return           void
***************************************************************************************************/
void Fr_Ipw_SetAbsoluteTimer
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 timerIdx,
    uint8 cycle,
    uint16 offset
)
{
    uint8 instNum = pCtrlCfg->CtrlIdx;
    /*  see if stopping a timer already stopped is ok */
    /* create struct with the default values */
    Flexray_Ip_TimerConfigType timerCfg;

    timerCfg.cycMask = 0x3FU;
    timerCfg.isRepetitive = FALSE;

    if(0U == timerIdx)
    {
        timerCfg.timer = FLEXRAY_TIMER1;
    }
    else
    {
        timerCfg.timer = FLEXRAY_TIMER2;
    }

    /* for selected timer, macrotick (offset), cycle value */
    /* then, stop timer, store cycle, store macrotick, starttimer */

    timerCfg.cycVal = cycle;
    timerCfg.macroTick = offset;

    Flexray_Ip_StopTimer(instNum, timerCfg.timer);
    Flexray_Ip_ConfigTimer(instNum, &timerCfg );
    Flexray_Ip_StartTimer(instNum,timerCfg.timer);

}

/***************************************************************************************************
* @function_name    Fr_Ipw_SetWakeupChannel
*
* @brief            LLD function for the Fr_SetWakeupChannel API
* @details          Store information about wakeup channel into FlexRay CC registers
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        chnlIdx   Index of FlexRay channel
* @return           Std_ReturnType:
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during set wakeup channel
***************************************************************************************************/
Std_ReturnType Fr_Ipw_SetWakeupChannel
(
    const Fr_CtrlCfgType* pCtrlCfg,
    Fr_ChannelType chnlIdx
)
{
    Std_ReturnType retVal;
    if(FR_CHANNEL_A == chnlIdx )
    {
        retVal = (Std_ReturnType)Flexray_Ip_SetWakeupChannel(pCtrlCfg->CtrlIdx, TRUE, FALSE);
    }
    else
    {
        retVal = (Std_ReturnType)Flexray_Ip_SetWakeupChannel(pCtrlCfg->CtrlIdx, FALSE, TRUE);
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetGlobalTime
*
* @brief            LLD function for the Fr_GetGlobalTime API
* @details          Query current cycle and macrotick from FlexRay CC registers
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[out]       cyclePtr  Address where current cycle is stored to
* @param[out]       macrotickPtr - Address where current macrotick is stored to
* @return           void
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetGlobalTime
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8* cyclePtr,
    uint16* macroTickPtr
)
{
    return (Std_ReturnType)Flexray_Ip_GetGlobalTime(pCtrlCfg->CtrlIdx, cyclePtr, macroTickPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetNmVector
*
* @brief            LLD function for the Fr_GetNmVector API
* @details          Read the network management vector of the last communication cycle
*                   and write it to the output parameter Fr_NmVectorPtr. The number of bytes
*                   written to the output parameter is constant and known at configuration time
* @param[in]        pCtrlCfg     Pointer config of FlexRay CC
* @param[out]       nmVectorPtr  Address of the variable the NmVector is stored to
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetNmVector
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8* nmVectorPtr,
    boolean* checkLen
)
{
	Std_ReturnType retVal = E_OK;
	const Flexray_Ip_ConfigType *pFlexrayIpConfig = pCtrlCfg->IpConfigPtr;
    uint8 configLen = pFlexrayIpConfig->peConfig->gNetworkManagementVectorLength;
    retVal = (Std_ReturnType) Flexray_Ip_GetNMVector(pCtrlCfg->CtrlIdx, nmVectorPtr, &configLen);
    if(configLen != pFlexrayIpConfig->peConfig->gNetworkManagementVectorLength)
    {
        *checkLen = FALSE;
    } else
    {
        *checkLen = TRUE;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetChannelStatus
*
* @brief            LLD function for the Fr_GetChannelStatus API
* @details          Reads the aggregated channel status, NIT status and symbol window status from
*                   FLEXRAY_PSR2, and FLEXRAY_PSR3 registers
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[out]       channelAStatusPtr  Address of the variable the channel A status is stored to
* @param[out]       channelAStatusPtr  Address of the variable the channel A status is stored to
* @return           void
***************************************************************************************************/
void Fr_Ipw_GetChannelStatus
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16* channelAStatusPtr,
    uint16* channelBStatusPtr
)
{
    Flexray_Ip_GetChannelStatus(pCtrlCfg->CtrlIdx, channelAStatusPtr, channelBStatusPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetClockCorrection
*
* @brief            LLD function for the Fr_GetChannelStatus API
* @details          Read rate and offset correction values from FR_RTCORVR and FR_OFCORVR registers
* @param[in]        pCtrlCfg             Pointer config of FlexRay CC
* @param[out]       rateCorrectionPtr    Address of the variable the rate correction value is
*                                        stored to
* @param[out]       offsetCorrectionPtr  Address of the variable the offset correction value is
*                                         stored to
* @return           void
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetClockCorrection
(
    const Fr_CtrlCfgType* pCtrlCfg,
    sint16* rateCorrectionPtr,
    sint32* offsetCorrectionPtr
)
{
    return (Std_ReturnType)Flexray_Ip_GetClockCorrection(pCtrlCfg->CtrlIdx, rateCorrectionPtr, offsetCorrectionPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetSyncFrameList
*
* @brief            LLD function for the Fr_GetSyncFrameList API
* @details          Reads syncFrame List ID table from FlexRay memory
* @param[in]        pCtrlCfg             Pointer config of FlexRay CC
* @param[out]       channelAEvenListPtr  Address of the variable the channel A even list is
*                                        stored to
* @param[out]       channelBEvenListPtr  Address of the variable the channel B even list is
*                                        stored to
* @param[out]       channelAOddListPtr   Address of the variable the channel A odd list is
*                                        stored to
* @param[out]       channelBOddListPtr   Address of the variable the channel B odd list is
*                                        stored to
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetSyncFrameList
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8 listSize,
    uint16* channelAEvenListPtr,
    uint16* channelBEvenListPtr,
    uint16* channelAOddListPtr,
    uint16* channelBOddListPtr
)
{

    return (Std_ReturnType) Flexray_Ip_GetSyncFrameList(pCtrlCfg->CtrlIdx, (Flexray_Ip_ConfigType*) pCtrlCfg->IpConfigPtr, listSize, channelAEvenListPtr, channelBEvenListPtr, channelAOddListPtr, channelBOddListPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetChannelStatus
*
* @brief            LLD function for the Fr_GetWakeupRxStatus API
* @details          Reads the Wakeup Symbol Received on channel A and channel B bits from the
*                   FLEXRAY_PSR3 register
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[out]       wakeupRxStatusPtr  Address of a variable where the wakeup Rx status is stored to
* @return           void
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetWakeupRxStatus
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8* wakeupRxStatusPtr
)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint16 wakeupRxStatus = 0U;
    uint8 chARxStatus = 0U;
    uint8 chBRxStatus = 0U;
    uint16 PocStatus[4];

    wakeupRxStatus = (uint16) Flexray_Ip_GetWakeupChannel(pCtrlCfg->CtrlIdx);
    chARxStatus = (uint8)((wakeupRxStatus & FLEXRAY_PSR3_WUA_MASK) >> FLEXRAY_PSR3_WUA_SHIFT);
    chBRxStatus = (uint8)((wakeupRxStatus & FLEXRAY_PSR3_WUB_MASK) >> FLEXRAY_PSR3_WUB_SHIFT);
    *wakeupRxStatusPtr = (chBRxStatus << 1U) |  chARxStatus;
    Flexray_Ip_GetPocStatus(pCtrlCfg->CtrlIdx , PocStatus);
    if((PocStatus[3] & (FLEXRAY_PSR3_WUA_MASK | FLEXRAY_PSR3_WUB_MASK)) == 0U)
    {
        retVal = E_OK;
    }
    return retVal;
}


/***************************************************************************************************
* @function_name    Fr_Ipw_ReadbackCCConfig
*
* @brief            LLD function for the Fr_ControllerInit API
* @details          Read back and compare cluster and configuration values to reference values
*                   held in the configuration.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      Configuration is OK
*                       - E_NOT_OK  Error in configuration was found
***************************************************************************************************/
Std_ReturnType Fr_Ipw_ReadbackCCConfig
(
    const Fr_CtrlCfgType* pCtrlCfg
)
{
    return (Std_ReturnType)Flexray_Ip_ReadbackCCConfig(pCtrlCfg->CtrlIdx,((Flexray_Ip_ConfigType*) pCtrlCfg->IpConfigPtr)->peConfig);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetNumOfStartupFrames
*
* @brief            LLD function for the Fr_GetNumOfStartupFrames
* @details          Reconfigures required LPdu
* @param[in]        pCtrlCfg        Pointer config of FlexRay CC
* @param[in]        configParamIdx  Index of LPdu to be reconfigured
* @return           Std_ReturnType
*                       - E_OK      Configuration is OK
*                       - E_NOT_OK  Error in configuration was found
***************************************************************************************************/
Std_ReturnType Fr_Ipw_GetNumOfStartupFrames
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint8* numOfStartupFramesPtr
)
{
    Std_ReturnType retVal = (Std_ReturnType)Flexray_Ip_GetNumOfStartFrames(pCtrlCfg->CtrlIdx, numOfStartupFramesPtr);
    return (retVal);
}

/**
 * @brief Checks the length of payload
 * either for dynamic or static type depending
 * on the number of static slots.
 *
 * @param pCtrlCfg   Pointer config of FlexRay CC
 * @param lpduIdx    Index of LPdu
 * @param lsduLength Payload length of data to be transmitted
 * @return Std_ReturnType E_OK - Payload length is lower than maximum allowed.
 */
Std_ReturnType Fr_Ipw_CheckLpduLengthTransmitTX
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    uint8 lsduLength
)
{

    Std_ReturnType retVal = (Std_ReturnType)(E_OK);
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);

    if(pIndBuff_info->frameID > pIpConfigPtr->peConfig->gNumberOfStaticSlots)
    {/* Buffer configured for the dynamic segment */
        if(lsduLength > (pIpConfigPtr->peConfig->pPayloadLengthDynMax * 2U))
        {

            retVal = (Std_ReturnType)(E_NOT_OK);
        }
    }
    else
    {/* Static segment */
        if(lsduLength > (pIpConfigPtr->peConfig->gPayloadLengthStatic * 2U))
        {
            retVal = (Std_ReturnType)(E_NOT_OK);
        }
    }
    return retVal;
}

/**
 * @brief Checks if the buffer info type is
 *        Tx.
 * @param pCtrlCfg Pointer config of FlexRay CC
 * @param lpduIdx  Index of LPdu
 * @return Std_ReturnType
 *              - E_OK if the buffer is Tx.
 */
Std_ReturnType Fr_Ipw_CheckTXLpdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx
)
{
    Std_ReturnType retVal = (Std_ReturnType)(E_OK);
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);

    /* Check the buffer type. */
    if(TRUE != pIndBuff_info->isTx)
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}


/***************************************************************************************************
* @function_name    Fr_Ipw_TransmitTxLPdu
*
* @brief            LLD function for the Fr_TransmitTxLPdu API
* @details          Copy data and activate it for transmission
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[in]        lpduIdx            Index of LPdu to be transmitted
* @param[in]        lsduPtr            Address of data to be transmitted
* @param[in]        lsduLength         Payload length of data to be transmitted
* @param[out]       slotAssignmentPtr  This reference points to the memory location where the
                                       actual cycle, slot ID, and channel of the frame identified by
                                       Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                       information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
Std_ReturnType Fr_Ipw_TransmitTxLPdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    const uint8* lsduPtr,
    uint8 lsduLength,
    Fr_SlotAssignmentType* slotAssignmentPtr
)
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    #if(FR_EXTENDED_LPDU_REPORTING == STD_ON)
    Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);
    #endif
    if( FLEXRAY_STATUS_SUCCESS == Flexray_Ip_Send(pCtrlCfg->CtrlIdx, IndBufferConfigIndex, lsduPtr, lsduLength))
    {
        retVal = FLEXRAY_STATUS_SUCCESS;
        #if(FR_EXTENDED_LPDU_REPORTING == STD_ON)

        if(NULL_PTR != slotAssignmentPtr)
        {
            /* Read  the number of the current communication cycle in the CYCTR registers */
            (slotAssignmentPtr->Cycle) = ((uint8) Flexray_Ip_GetCurrentCycleCount(pCtrlCfg->CtrlIdx));
            /* copy slot ID of the transmitted frame to FLEXRAY_SlotAssignment*/
            (slotAssignmentPtr->SlotId) = (pIndBuff_info->frameID);
            /* channel transmit data */
            if ((TRUE == (pIndBuff_info->channelA))&&(TRUE == (pIndBuff_info->channelB)))
            {
                /* Transmit on both A and B channels */
                slotAssignmentPtr->channelId = FR_CHANNEL_AB;
            }
            else if((TRUE == (pIndBuff_info->channelA))&&(FALSE == (pIndBuff_info->channelB)))
            {
                /* Transmit on channel A only */
                slotAssignmentPtr->channelId = FR_CHANNEL_A;
            }
            else if((FALSE == (pIndBuff_info->channelA))&&(TRUE == (pIndBuff_info->channelB)))
            {
                /* Transmit on channel B only */
                slotAssignmentPtr->channelId = FR_CHANNEL_B;
            }
            else
            {
                /* Do nothing */
            }
        }
        #else
        (void)slotAssignmentPtr;
        #endif
    }
    return (Std_ReturnType)retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ReceiveRxLPdu
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @details          Copy receive payload data
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[in]        lpduIdx            Index of LPdu to be transmitted
* @param[out]       lsduPtr            Address of field that data is copied to
* @param[out]       lpduStatusPtr      Address of the variable the status is stored to
* @param[out]       lsduLengthPtr      Address of the variable the payload is stored to
* @param[out]       slotAssignmentPtr  This reference points to the memory location where the
                                       actual cycle, slot ID, and channel of the frame identified by
                                       Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                       information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the controller
***************************************************************************************************/
Std_ReturnType Fr_Ipw_ReceiveRxLPdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    uint8* lsduPtr,
    Fr_RxLPduStatusType* lpduStatusPtr,
    uint8* lsduLengthPtr,
    Fr_SlotAssignmentType* slotAssignmentPtr
)
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);
    const Flexray_Ip_BufferStateType* bState = &(((Flexray_Ip_BufferStateType*)(pIpStateAllocPtr->bufferState))[IndBufferConfigIndex]);
    Flexray_Ip_FrameHeaderType frameHdr = {FALSE};
    Flexray_Ip_ReceiveInd(pCtrlCfg->CtrlIdx, IndBufferConfigIndex, &frameHdr, lsduPtr ,pIndBuff_info->payloadLength);
    if(FLEXRAY_STATUS_UNSUPPORTED !=  bState->status)
    {
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if(TRUE == bState->slotStatusError)
        {
            Fr_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[lpduIdx], DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            Fr_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[lpduIdx], DEM_EVENT_STATUS_PASSED);
        }
        #endif /* FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
        #if(FR_EXTENDED_LPDU_REPORTING == STD_ON)
         if(NULL_PTR != slotAssignmentPtr)
         {
             /* Read  the number of the current communication cycle in the CYCTR registers */
             (slotAssignmentPtr->Cycle) = ((uint8)frameHdr.cycleCount);
             /* copy slot ID of the transmitted frame to FLEXRAY_SlotAssignment*/
             (slotAssignmentPtr->SlotId) = ((uint8)frameHdr.frameID);
             /* channel transmit data */
             if((0x0080U == (frameHdr.slotStatus & FLEXRAY_STRINGENT_MASK_A)) || ( 0x8000U ==(frameHdr.slotStatus & FLEXRAY_STRINGENT_MASK_B)))
             {
                 slotAssignmentPtr->channelId = FR_CHANNEL_AB;
             }
             else if(0x0080U == (frameHdr.slotStatus & FLEXRAY_STRINGENT_MASK_A))
             {
                 /* Transmit on channel A only */
                 slotAssignmentPtr->channelId = FR_CHANNEL_A;
             }
             else if(0x8000U == (frameHdr.slotStatus & FLEXRAY_STRINGENT_MASK_B))
             {
                 /* Transmit on channel B only */
                 slotAssignmentPtr->channelId = FR_CHANNEL_B;
             }
             else
             {
                 /* Do nothing */
             }
         }
         #else
             (void)slotAssignmentPtr;
         #endif
         if(FLEXRAY_STATUS_SUCCESS == bState->status)
         {
             *lsduLengthPtr = (uint8)(frameHdr.payloadLength << 1U);
             *lpduStatusPtr = FR_RECEIVED;
         }
         else
         {
             *lsduLengthPtr = 0U;
             *lpduStatusPtr = FR_NOT_RECEIVED;
         }

         retVal = FLEXRAY_STATUS_SUCCESS;

    }
    return (Std_ReturnType) retVal;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ReceiveFifo
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @details          Copy Fifo data
* @param[in]        pCtrlCfg          Pointer config of FlexRay CC
* @param[in]        lpduIdx           Index of LPdu to be transmitted
* @param[out]       lsduPtr           Address of field that data is copied to
* @param[out]       lpduStatusPtr     Address of the variable the status is stored to
* @param[out]       lsduLengthPtr     Address of the variable the payload is stored to
* @param[out]       slotAssignmentPtr Pointer used to store cycle, slot ID, and channel of the frame identified by Fr_LPduIdx
* @param[in]        FIFOChannel       Channel for FIFO

* @return           void
***************************************************************************************************/
void Fr_Ipw_ReceiveFifo
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    uint8* lsduPtr,
    Fr_RxLPduStatusType* lpduStatusPtr,
    uint8* lsduLengthPtr,
    Fr_SlotAssignmentType* slotAssignmentPtr
)
{
    Flexray_Ip_StatusType retVal;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    const Flexray_Ip_FifoConfigType* pFifoBuff_info ;
    Flexray_Ip_FrameHeaderType frameHdr;
    if(FR_FIFOA_BUFFER == pCtrlCfg->LpduInfoPtr[lpduIdx].StorageType)
    {
        pFifoBuff_info = pIpConfigPtr->fifoConfigA;
        retVal = Flexray_Ip_ReceiveFIFO(pCtrlCfg->CtrlIdx, FALSE, &frameHdr, lsduPtr, pFifoBuff_info->entrySize);
    } else
    {
        pFifoBuff_info = pIpConfigPtr->fifoConfigB;
        retVal = Flexray_Ip_ReceiveFIFO(pCtrlCfg->CtrlIdx, TRUE, &frameHdr, lsduPtr, pFifoBuff_info->entrySize);
    }
    if(FLEXRAY_STATUS_SUCCESS == retVal)
    {
        #if(FR_EXTENDED_LPDU_REPORTING == STD_ON)
         if(NULL_PTR != slotAssignmentPtr)
         {
             /* Read  the number of the current communication cycle in the CYCTR registers */
             (slotAssignmentPtr->Cycle) = ((uint8)frameHdr.cycleCount);
             /* copy slot ID of the transmitted frame to FLEXRAY_SlotAssignment*/
             (slotAssignmentPtr->SlotId) = ((uint8)frameHdr.frameID);
             /* channel transmit data */
             if (FR_FIFOA_BUFFER == pCtrlCfg->LpduInfoPtr[lpduIdx].StorageType)
             {
                 slotAssignmentPtr->channelId = FR_CHANNEL_A;
             }
             else
             {
                 slotAssignmentPtr->channelId = FR_CHANNEL_B;
             }

         }
         #else
             (void)slotAssignmentPtr;
         #endif
         *lsduLengthPtr = (uint8)(frameHdr.payloadLength << 1U);
         *lpduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;

    }
    else
    {
        *lsduLengthPtr = 0U;
        *lpduStatusPtr = FR_NOT_RECEIVED;
    }
}

/***************************************************************************************************
* @function_name    Fr_Ipw_CheckTxLPduStatus
*
* @brief            LLD function for the Fr_CheckTxLPduStatus API
* @details          Check whether LPdu was transmitted or not
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[in]        lpduIdx            Index of LPdu to be canceled
* @param[out]       txLPduStatusPtr    Address of the variable where the status information is
*                                      stored to
* @param[out]       slotAssignmentPtr  This reference points to the memory location where the
                                       actual cycle, slot ID, and channel of the frame identified by
                                       Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                       information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_Ipw_CheckTxLPduStatus
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    Fr_TxLPduStatusType* txLPduStatusPtr,
    Fr_SlotAssignmentType* slotAssignmentPtr
)
{

    Flexray_Ip_StatusType retVal;
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    #if(FR_EXTENDED_LPDU_REPORTING == STD_ON)
    Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);
    #endif
    const Flexray_Ip_BufferStateType* bState = &(((Flexray_Ip_BufferStateType*)(pIpStateAllocPtr->bufferState))[IndBufferConfigIndex]);
    retVal = Flexray_Ip_GetTransferStatus(pCtrlCfg->CtrlIdx, IndBufferConfigIndex);
    if(FLEXRAY_STATUS_ERROR != retVal)
    {
    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if(0U == (bState->frameHdr->slotStatus & 0x0101U))
        {
            Fr_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[lpduIdx], DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            Fr_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[lpduIdx], DEM_EVENT_STATUS_FAILED);
        }
    #endif
    #if(FR_EXTENDED_LPDU_REPORTING == STD_ON)
        if(NULL_PTR != slotAssignmentPtr)
        {
            slotAssignmentPtr->Cycle = ((uint8) Flexray_Ip_GetCurrentCycleCount(pCtrlCfg->CtrlIdx));
            slotAssignmentPtr->SlotId = ((uint8)bState->frameHdr->frameID);
            if ((pIndBuff_info->channelA)&&(pIndBuff_info->channelB))
            {
                slotAssignmentPtr->channelId = FR_CHANNEL_AB;
            }
            else if(pIndBuff_info->channelA)
            {
                slotAssignmentPtr->channelId = FR_CHANNEL_A;
            }
            else
            {
                slotAssignmentPtr->channelId = FR_CHANNEL_B;
            }
        }
    #else
        (void)bState;
        (void)slotAssignmentPtr;
    #endif
        if((FLEXRAY_STATUS_TX_CONFLICT_A == retVal) || (FLEXRAY_STATUS_TX_CONFLICT_B == retVal) || (FLEXRAY_STATUS_TX_CONFLICT_AB == retVal))
        {
            *txLPduStatusPtr = FR_TRANSMITTED_CONFLICT;
        }
        else if(FLEXRAY_STATUS_SUCCESS == retVal)
        {
            *txLPduStatusPtr = FR_TRANSMITTED;
        } else
        {
            *txLPduStatusPtr = FR_NOT_TRANSMITTED;
        }
        retVal = FLEXRAY_STATUS_SUCCESS;
    }
    return (Std_ReturnType) retVal;
}

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Ipw_PrepareLPdu
*
* @brief            LLD function for the Fr_PrepareLPdu API
* @details          Check LPdu status
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        lpduIdx   Index of LPdu to be prepared
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_Ipw_PrepareLPdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx
)
{
    /* Set initial return value */
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    uint8 instNum = pCtrlCfg->CtrlIdx;

    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    Flexray_Ip_IndConfigType* pIndBuff_info = &(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);
    Flexray_Ip_BufferStateType** mbStateMap = pIpStateAllocPtr->mbStateMap;
    Flexray_Ip_BufferStateType* bufferState = pIpStateAllocPtr->bufferState;
    if(FR_IND_BUFFER == pCtrlCfg->LpduInfoPtr[lpduIdx].StorageType)
    {
        retVal = Flexray_Ip_ReConfigIndividual(instNum, pIndBuff_info);
        if(FLEXRAY_STATUS_SUCCESS == retVal )
        {
            mbStateMap[pIndBuff_info->MBIndex] = &bufferState[IndBufferConfigIndex];
        }
    }

    return (Std_ReturnType) retVal;
}

#endif /* FR_PREPARE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_Ipw_CancelTxLPdu
*
* @brief            LLD function for the Fr_CancelTxLPdu API
* @details          Cancel required LPdu and provide information about it
* @param[in]        pCtrlCfg      Pointer config of FlexRay CC
* @param[in]        lpduIdx       Index of LPdu to be canceled
* @param[out]       pendingStatus Information whether the LPdu was canceled or not
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_Ipw_CancelTxLPdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    boolean* pendingStatus
)
{
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    return (Std_ReturnType) Flexray_Ip_CancelTxBuffer(pCtrlCfg->CtrlIdx, IndBufferConfigIndex, pendingStatus);
}


#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Ipw_ReconfigLPdu
*
* @brief            LLD function for the Fr_ReconfigLPdu API
* @details          Reconfigures required LPdu
* @param[in]        pCtrlCfg        Pointer config of FlexRay CC
* @param[in]        lpduIdx         Index of LPdu to be reconfigured
* @param[in]        frameId         Frame ID for reconfiguration
* @param[in]        cycleRepetition Repetition value for cycle filter mechanism
* @param[in]        cycleOffste     Offste value for cycle filter mechanism
* @param[in]        payloadLength   payload for data to be reconfigured
* @param[in]        headerCRC       hedaer CRC value
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_Ipw_ReconfigLPdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx,
    uint16 frameId,
    Fr_ChannelType chnlIdx,
    uint8 cycleRepetition,
    uint8 cycleOffset,
    uint8 payloadLength,
    uint16 headerCRC
)
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[IndBufferConfigIndex]);
    #if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    #endif

    Flexray_Ip_IndConfigType pIndBuff_info_reconfig;
    #if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    if(pIpStateAllocPtr->mbStateMap[pIndBuff_info->MBIndex]->bufferId == IndBufferConfigIndex)
    {
    #endif
        pIndBuff_info_reconfig.MBIndex = pIndBuff_info->MBIndex;
        pIndBuff_info_reconfig.phyMBIndex = pIndBuff_info->phyMBIndex;
        pIndBuff_info_reconfig.firstInit = pIndBuff_info->firstInit;
        pIndBuff_info_reconfig.frameID = frameId;
        pIndBuff_info_reconfig.headerCrc = headerCRC;
        pIndBuff_info_reconfig.PPI = FALSE;
        pIndBuff_info_reconfig.payloadLength = payloadLength;
        pIndBuff_info_reconfig.isTx = pIndBuff_info->isTx;
        if(FR_CHANNEL_AB == chnlIdx)
        {
            pIndBuff_info_reconfig.channelA = TRUE;
            pIndBuff_info_reconfig.channelB = TRUE;
        }
        else if(FR_CHANNEL_A == chnlIdx)
        {
            pIndBuff_info_reconfig.channelA = TRUE;
            pIndBuff_info_reconfig.channelB = FALSE;
        }
        else
        {
            pIndBuff_info_reconfig.channelA = FALSE;
            pIndBuff_info_reconfig.channelB = TRUE;
        }
        pIndBuff_info_reconfig.ccFilterVal = cycleOffset;
        pIndBuff_info_reconfig.ccFilterMask = cycleRepetition - 1U;
        if((cycleOffset != 0U)||(cycleRepetition > 1U))
        {
            pIndBuff_info_reconfig.ccFilter = TRUE;
        }
        else
        {
            pIndBuff_info_reconfig.ccFilter = FALSE;
        }
        pIndBuff_info_reconfig.repeatTx = pIndBuff_info->repeatTx;
        pIndBuff_info_reconfig.allowVariableLength = pIndBuff_info->allowVariableLength;
        pIndBuff_info_reconfig.enable = pIndBuff_info->enable;
        retVal = Flexray_Ip_ReConfigIndividual(pCtrlCfg->CtrlIdx, &pIndBuff_info_reconfig);
    #if(STD_ON == FLEXRAY_PREPARE_LPDU_SUPPORT)
    }
    #endif
    return (Std_ReturnType) retVal ;
}

#endif /* FR_RECONFIG_LPDU_SUPPORT == STD_ON */

#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Ipw_DisableLPdu
*
* @brief            LLD function for the Fr_DisableLPdu
* @details          Disables required Message Buffer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        lpduIdx   Index of LPdu to be reconfigured
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_Ipw_DisableLPdu
(
    const Fr_CtrlCfgType* pCtrlCfg,
    uint16 lpduIdx
)
{
    uint8 IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[lpduIdx].BufferConfigIndex;

    return (Std_ReturnType)Flexray_Ip_Abort(pCtrlCfg->CtrlIdx, IndBufferConfigIndex);
}
#endif /* FR_DISABLE_LPDU_SUPPORT == STD_ON */

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
/* End of file */
