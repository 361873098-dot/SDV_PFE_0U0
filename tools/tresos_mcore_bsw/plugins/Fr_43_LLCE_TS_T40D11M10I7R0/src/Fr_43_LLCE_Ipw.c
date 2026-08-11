/**
*   @file    Fr_43_LLCE_Ipw.c
*   @version 1.0.7
*
*   @brief   AUTOSAR Fr_43_LLCE - module interface.
*   @implements  Fr_Ipw.c_Artifact
*
*   @addtogroup FR_DRIVER
*   @{
*/
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
*   @file Fr_43_LLCE_Ipw.c
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
#include "Fr_43_LLCE_Ipw.h"
#include "Flexray_43_LLCE_Ip.h"

#if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_43_LLCE_IPW_VENDOR_ID_C                        43
#define FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION_C         4
#define FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION_C         4
#define FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION_C      0
#define FR_43_LLCE_IPW_SW_MAJOR_VERSION_C                 1
#define FR_43_LLCE_IPW_SW_MINOR_VERSION_C                 0
#define FR_43_LLCE_IPW_SW_PATCH_VERSION_C                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_43_LLCE_Ipw.h header file are of the same vendor */
#if (FR_43_LLCE_IPW_VENDOR_ID_C != FR_43_LLCE_IPW_VENDOR_ID)
    #error "Fr_43_LLCE_Ipw.c and Fr_43_LLCE_Ipw.h have different Vendor IDs"
#endif
/* Check if current file and Fr_43_LLCE_Ipw.h header file are of the same Autosar version */
#if ((FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION_C    != FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION_C    != FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION_C != FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE_Ipw.c and Fr_43_LLCE_Ipw.h are different"
#endif
/* Check if current file and Fr_43_LLCE_Ipw.h header file are of the same software version */
#if ((FR_43_LLCE_IPW_SW_MAJOR_VERSION_C != FR_43_LLCE_IPW_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_MINOR_VERSION_C != FR_43_LLCE_IPW_SW_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_PATCH_VERSION_C != FR_43_LLCE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE_Ipw.c and Fr_43_LLCE_Ipw.h are different"
#endif

/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same vendor */
#if (FR_43_LLCE_IPW_VENDOR_ID_C != FLEXRAY_43_LLCE_IP_VENDOR_ID)
    #error "Fr_43_LLCE_Ipw.c and Flexray_43_LLCE_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same Autosar version */
#if ((FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_43_LLCE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE_Ipw.c and Flexray_43_LLCE_Ip.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same software version */
#if ((FR_43_LLCE_IPW_SW_MAJOR_VERSION_C != FLEXRAY_43_LLCE_IP_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_MINOR_VERSION_C != FLEXRAY_43_LLCE_IP_SW_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_PATCH_VERSION_C != FLEXRAY_43_LLCE_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE_Ipw.c and Flexray_43_LLCE_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h header file are of the same Autosar version */
    #if ((FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fr_43_LLCE_Ipw.c and Dem.h are different"
    #endif
#endif
#endif /* CHECK_AUTOSAR_VERSION */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_43_LLCE_START_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

static Std_ReturnType Fr_43_LLCE_Ipw_GetWakeupState(uint16 u16RegValuePSR0,
                                                            Fr_WakeupStatusType* WakeupStatusPtr
                                                           );
static Std_ReturnType Fr_43_LLCE_Ipw_GetSlotMode(uint16 u16RegValuePSR0,
                                                         Fr_SlotModeType* SlotModePtr
                                                        );
static Std_ReturnType Fr_43_LLCE_Ipw_GetErrorMode(uint16 u16RegValuePSR0,
                                                          Fr_ErrorModeType* ErrorModePtr
                                                         );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/***************************************************************************************************
 * @function_name       Fr_43_LLCE_Ipw_GetgNumberOfStaticSlots
 *
 * @brief               Returns the number of static slots from the
 *                      configuration.
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return uint16
***************************************************************************************************/
uint16 Fr_43_LLCE_Ipw_GetgNumberOfStaticSlots(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    /* Number of static slots*/
    return ((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->peConfig->gNumberOfStaticSlots;
}

/***************************************************************************************************
 * @function_name       Fr_43_LLCE_Ipw_GetgChannel
 *
 * @brief               Checks the configuration for current channel usage.
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return uint8
***************************************************************************************************/
uint8 Fr_43_LLCE_Ipw_GetgChannel(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    uint8 u8gChannel = 0U;

    /* Position 0 = ChA, position 1 = ChB */
    if (((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->ccConfig->channelA == TRUE)
    {
        u8gChannel += 1U;
    }
    if (((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->ccConfig->channelB == TRUE)
    {
        u8gChannel += 2U;
    }
    return u8gChannel;
}

/***************************************************************************************************
 * @function_name       Fr_43_LLCE_Ipw_GetgPayloadLengthStatic
 *
 * @brief               Returns the static payload length.
 *
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return uint8
***************************************************************************************************/
uint8 Fr_43_LLCE_Ipw_GetgPayloadLengthStatic(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    return (uint8)((uint16)(((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->peConfig->gPayloadLengthStatic) * 2U);
}

/***************************************************************************************************
 * @function_name       Fr_43_LLCE_Ipw_Gettimer2IsRelative
 *
 * @brief               Returns the state of timer2IsRelative, that can be
 *                      either relative or absolute.
 *
 * @param pCtrlCfg      Pointer to the configuration of FlexRay CC
 * @return boolean      True - timer 2 is relative.
***************************************************************************************************/
boolean Fr_43_LLCE_Ipw_Gettimer2IsRelative(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    return ((Flexray_Ip_ConfigType*)pCtrlCfg->IpConfigPtr)->timer2IsRelative;
}


#if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_DemSetEventStatus
*
* @brief            FrIP function in order to report DEM error.
* @details          Report DEM error.
* @param[in]        ccLpduInfo  - Store the reference to Rx MB configuration
* @param[in]        u16StatusReport - The status of DEM event.
***************************************************************************************************/

static void Fr_43_LLCE_Ipw_DemSetEventStatus(Fr_43_LLCE_CCLpduInfoType ccLpduInfo,
                                                     Dem_EventStatusType u16StatusReport
                                                    )
{
    Dem_EventIdType FR_E_LPDU_SLOTSTATUS;

    if (TRUE == ccLpduInfo.DemFTSlotSTatusRefExist)
    {
        FR_E_LPDU_SLOTSTATUS = ccLpduInfo.DemFTSlotStatus;
        (void)Dem_SetEventStatus(FR_E_LPDU_SLOTSTATUS, u16StatusReport);
    }
}

#endif

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_ControllerInit
*
* @brief            LLD function for FlexRay CC configuration
* @details          Writes values from configuration file into the Module Configuration Register
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           Std_ReturnType
*                       - E_OK      FR CC was successfully reinitialized
*                       - E_NOT_OK  not possible to move FR CC to default config state
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_ControllerInit(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    Std_ReturnType retVal = E_NOT_OK;

    const Flexray_Ip_ConfigType* pIpConfigPtr = (const Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    if (FLEXRAY_STATUS_SUCCESS == Flexray_43_LLCE_Ip_Init(pCtrlCfg->CtrlIdx, pIpConfigPtr, pCtrlCfg->IpStateAllocPtr))
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

Std_ReturnType Fr_43_LLCE_Ipw_DeInit(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (FLEXRAY_STATUS_SUCCESS == Flexray_43_LLCE_Ip_Deinit(pCtrlCfg->CtrlIdx))
    {
        retVal = E_OK;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_CheckCCAccess
*
* @brief            LLD function for checking access to the CC
* @details          Function checks whether the FlexRay CC is accessible or not
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        Fr_CC_Enabled Indicates whether CC module should be enabled or not
* @return           Std_ReturnType
*                       - E_OK      CC is accessible
*                       - E_NOT_OK  CC is not accessible
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_CheckCCAccess(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    const boolean Fr_CC_Enabled
                                                   )
{
    /* Check Module Version Register */
    return  (Std_ReturnType)Flexray_43_LLCE_Ip_CheckCCAccess(pCtrlCfg->CtrlIdx, Fr_CC_Enabled, FLEXRAY_MVR_U16);

}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_ClearDisableIRQs
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
Std_ReturnType Fr_43_LLCE_Ipw_ClearDisableIRQs(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    /* note: we can't touch hw access functions.
        those irq ones are used by functions only.
        better to implement our own?
        can we take static out of hw access functions?*/

    return (Std_ReturnType)Flexray_43_LLCE_Ip_ClearDisableIRQs(pCtrlCfg->CtrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_DisableTimers
*
* @brief            LLD function which disables timers.
* @details          Function clears all T1SP and T2SP bits in the TICCR register.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           none
***************************************************************************************************/
void Fr_43_LLCE_Ipw_DisableTimers(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    Flexray_43_LLCE_Ip_StopTimer(pCtrlCfg->CtrlIdx, FLEXRAY_TIMER1);
    Flexray_43_LLCE_Ip_StopTimer(pCtrlCfg->CtrlIdx, FLEXRAY_TIMER2);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetPOCState
*
* @brief            LLD function for quering the controller POC status
* @details          Read the FlexRay controller Protocol Status Register 1.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[out]       pocStatus - Address of the variable wher the Protocol status is stored to
* @return           uint16
***************************************************************************************************/
Fr_POCStateType Fr_43_LLCE_Ipw_GetPOCState(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    Flexray_Ip_PocStateType currentState;
    Fr_POCStateType retValue;
    currentState = Flexray_43_LLCE_Ip_GetCurrentState(pCtrlCfg->CtrlIdx);

    switch (currentState)
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
* @function_name    Fr_43_LLCE_Ipw_GetPOCStatus
*
* @brief            LLD function for quering the controller POC status
* @details          Read the FlexRay controller Protocol Status Register 1.
* @param[in]        pCtrlCfg      Pointer config of FlexRay CC
* @param[out]       POCStatusPtr  Address of the variable wher the Protocol status is stored to
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Reserved value was read
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetPOCStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   Fr_POCStatusType* POCStatusPtr
                                                  )
{
    uint8 u8InstNum = pCtrlCfg->CtrlIdx;
    Std_ReturnType retVal = E_OK;
    uint16 PocStatus[4];
    Flexray_Ip_StartupStatusType startupStatus;
    Flexray_43_LLCE_Ip_GetPocStatus(pCtrlCfg->CtrlIdx , PocStatus);

    if (FLEXRAY_PSR1_FRZ_U16 == ((uint16)(PocStatus[1]) & FLEXRAY_PSR1_FRZ_U16))
    {
        POCStatusPtr->State = FR_POCSTATE_HALT;
        POCStatusPtr->Freeze = TRUE;
    }
    else
    {
        POCStatusPtr->State = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
        POCStatusPtr->Freeze = FALSE;
    }
    if (FR_POCSTATE_STARTUP == POCStatusPtr->State)
    {
        startupStatus = Flexray_43_LLCE_Ip_GetStartupStatus(u8InstNum);
        switch (startupStatus)
        {
            case FLEXRAY_STARTUP_UNDEFINED:
                POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
                retVal = E_NOT_OK;
                break;

            case FLEXRAY_COLDSTART_LISTEN:
                POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_LISTEN;
                break;

            case FLEXRAY_INTE_COLDSTART_CHECK:
                POCStatusPtr->StartupState = FR_STARTUP_INTEGRATION_COLDSTART_CHECK;
                break;

            case FLEXRAY_COLDSTART_JOIN:
                POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_JOIN;
                break;

            case FLEXRAY_COLDSTART_COLLISION:
                POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_COLLISION_RESOLUTION;
                break;

            case FLEXRAY_COLDSTART_CONS_CHECK:
                POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_CONSISTENCY_CHECK;
                break;

            case FLEXRAY_INTE_LISTEN:
                POCStatusPtr->StartupState = FR_STARTUP_INTEGRATION_LISTEN;
                break;

            case FLEXRAY_INIT_SCHEDULE:
                POCStatusPtr->StartupState = FR_STARTUP_INITIALIZE_SCHEDULE;
                break;

            case FLEXRAY_INTE_CHECK:
                POCStatusPtr->StartupState = FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK;
                break;

            case FLEXRAY_COLDSTART_GAP:
                POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_GAP;
                break;

            default:
                POCStatusPtr->StartupState = FR_STARTUP_EXTERNAL_STARTUP;
                break;
        }
    }
    else
    {
        POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
    }
    if ((Std_ReturnType)E_NOT_OK == (Std_ReturnType) Fr_43_LLCE_Ipw_GetWakeupState(PocStatus[0],&(POCStatusPtr->WakeupStatus)))
    {
        retVal = E_NOT_OK;
    }
    if ((Std_ReturnType)E_NOT_OK == (Std_ReturnType) Fr_43_LLCE_Ipw_GetSlotMode(PocStatus[0],&(POCStatusPtr->SlotMode)))
    {
        retVal = E_NOT_OK;
    }
    if ((Std_ReturnType)E_NOT_OK == (Std_ReturnType) Fr_43_LLCE_Ipw_GetErrorMode(PocStatus[0],&(POCStatusPtr->ErrorMode)))
    {
        retVal = E_NOT_OK;
    }

    if (FLEXRAY_PSR1_HHR_U16 == ((uint16)(PocStatus[1]) & FLEXRAY_PSR1_HHR_U16))
    {
        POCStatusPtr->CHIHaltRequest = TRUE;
    }
    else
    {
        POCStatusPtr->CHIHaltRequest = FALSE;
    }

     if (FLEXRAY_PSR1_CPN_U16 == ((uint16)(PocStatus[1]) & FLEXRAY_PSR1_CPN_U16))
    {
        POCStatusPtr->ColdstartNoise = TRUE;
    }
    else
    {
        POCStatusPtr->ColdstartNoise = FALSE;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetWakeupState
*
* @brief            FrIP function for the Fr_43_LLCE_GetPOCStatus API
* @details          The FlexRay controller wakeup state is determined here.
* @param[in]        u16RegValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       WakeupStatusPtr - Address the Wakeup status is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static Std_ReturnType Fr_43_LLCE_Ipw_GetWakeupState(uint16 u16RegValuePSR0,
                                                            Fr_WakeupStatusType* WakeupStatusPtr
                                                           )
{
    /* Initialize variable */
    Std_ReturnType retVal = (Std_ReturnType)(E_OK);

    /* Determine the wakeup status */
    switch (u16RegValuePSR0 & FLEXRAY_PSR0_WAKEUPSTATUS_MASK)
    {
        case FLEXRAY_PSR0_WUP_RH_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_RECEIVED_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_RW_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_RECEIVED_WUP;
            break;

        case FLEXRAY_PSR0_WUP_HC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_COLLISION_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_WC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_COLLISION_WUP;
            break;

        case FLEXRAY_PSR0_WUP_UC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_COLLISION_UNKNOWN;
            break;

        case FLEXRAY_PSR0_WUP_T_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_TRANSMITTED;
            break;

        case FLEXRAY_PSR0_WUP_UD_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *WakeupStatusPtr = FR_WAKEUP_UNDEFINED;
            break;

        default:
            /* Reserved value cannot occur */
            *WakeupStatusPtr = FR_WAKEUP_UNDEFINED;
            retVal = (Std_ReturnType)(E_NOT_OK);
            break;
    }

    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetSlotMode
*
* @brief            FrIP function for the Fr_43_LLCE_GetPOCStatus API
* @details          The FlexRay controller slot mode is determined here.
* @param[in]        u16RegValuePSR0  Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       SlotModePtr   Address the Slot mode is stored to.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static Std_ReturnType Fr_43_LLCE_Ipw_GetSlotMode(uint16 u16RegValuePSR0,
                                                         Fr_SlotModeType* SlotModePtr
                                                        )
{
    /* Initialize variable */
    Std_ReturnType retVal = E_OK;

    /* Determine the slot mode */
    switch (u16RegValuePSR0 & FLEXRAY_PSR0_SLOTMODE_MASK)
    {
        case FLEXRAY_PSR0_SLOTMODE_SINGLE_U16:
            /* Store the slot mode to location referenced by given pointer */
            *SlotModePtr = FR_SLOTMODE_SINGLE;
            break;

        case FLEXRAY_PSR0_SLOTMODE_ALL_PENDING_U16:
            /* Store the slot mode to location referenced by given pointer */
            *SlotModePtr = FR_SLOTMODE_ALL_PENDING;
            break;

        case FLEXRAY_PSR0_SLOTMODE_ALL_U16:
            /* Store the slot mode to location referenced by given pointer */
            *SlotModePtr = FR_SLOTMODE_ALL;
            break;

        default:
            /* Reserved value cannot occur */
            *SlotModePtr = FR_SLOTMODE_SINGLE;
            retVal = E_NOT_OK;
            break;
    }

    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetErrorMode
*
* @brief            FrIP function for the Fr_43_LLCE_GetPOCStatus API
* @details          The FlexRay controller error mode is determined here.
* @param[in]        u16RegValuePSR0  Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       ErrorModePtr  Address the Error mode is stored to.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static Std_ReturnType Fr_43_LLCE_Ipw_GetErrorMode(uint16 u16RegValuePSR0,
                                                          Fr_ErrorModeType* ErrorModePtr
                                                         )
{
    /* Initialize variable */
    Std_ReturnType retVal = (Std_ReturnType)(E_OK);

    /* Determine the error mode */
    switch (u16RegValuePSR0 & FLEXRAY_PSR0_ERRMODE_MASK)
    {
        case FLEXRAY_PSR0_ERRMODE_ACTIVE_U16:
            /* Store the Error mode to location referenced by given pointer */
            *ErrorModePtr = FR_ERRORMODE_ACTIVE;
            break;

        case FLEXRAY_PSR0_ERRMODE_PASSIVE_U16:
            /* Store the Error mode to location referenced by given pointer */
            *ErrorModePtr = FR_ERRORMODE_PASSIVE;
            break;

        case FLEXRAY_PSR0_ERRMODE_COMM_HALT_U16:
            /* Store the Error mode to location referenced by given pointer */
            *ErrorModePtr = FR_ERRORMODE_COMM_HALT;
            break;

        default:
            /* Reserved value cannot occur */
            *ErrorModePtr = FR_ERRORMODE_ACTIVE;
            retVal = (Std_ReturnType)(E_NOT_OK);
            break;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_InvokeCHIcommand
*
* @brief            LLD function for invoking POCCMD commands
* @details           Invokes required CHI command
* @param[in]        pCtrlCfg    Pointer config of FlexRay CC
* @param[in]        ChiCommand  required CHI command
* @return           Std_ReturnType:
*                       - E_OK      CHI command was accepted by PE
*                       - E_NOT_OK  CHI command was not accepted by PE due to BSY flag
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_InvokeCHICommand(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                       Flexray_Ip_ChiCmdType ChiCommand
                                                      )
{
   return (Std_ReturnType) Flexray_43_LLCE_Ip_SendCHICommand(pCtrlCfg->CtrlIdx, ChiCommand);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_AckAbsTimerIRQ
*
* @brief            LLD function for the Fr_43_LLCE_AckAbsoluteTimerIRQ API
* @details          Ack the FlexRay CC absolute timer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u8TimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_AckAbsoluteTimerIRQ(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                uint8 u8TimerIdx
                                               )
{
    if (0U == u8TimerIdx)
    {   /* Timer 1 */
        Flexray_43_LLCE_Ip_ClearProtocolInterruptFlag(pCtrlCfg->CtrlIdx, FLEXRAY_T1_EXPIRED); /* Clear flag */
    }
    else
    {   /* Timer 2 */
        Flexray_43_LLCE_Ip_ClearProtocolInterruptFlag(pCtrlCfg->CtrlIdx, FLEXRAY_T2_EXPIRED); /* Clear flag */
    }

    Flexray_Llce_AckFrpeIRQ();
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_CancelAbsoluteTimer
*
* @brief            LLD function for the Fr_43_LLCE_CancelAbsoluteTimer API
* @details          Cancel the FlexRay CC absolute timer
* @param[in]        pCtrlCfg   Pointer config of FlexRay CC
* @param[in]        u8TimerIdx   Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_CancelAbsoluteTimer(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                uint8 u8TimerIdx
                                               )
{
    /* first we check which timer is running. we will only stop the timer */
    if (0U == u8TimerIdx)
    {   /* Timer 1 should be stoped */
        Flexray_43_LLCE_Ip_StopTimer(pCtrlCfg->CtrlIdx,FLEXRAY_TIMER1);
    }
    else
    {   /* Timer 2 should be stoped */
        Flexray_43_LLCE_Ip_StopTimer(pCtrlCfg->CtrlIdx,FLEXRAY_TIMER2);
    }
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_DisableAbsoluteTimerIRQ
*
* @brief            LLD function for the Fr_43_LLCE_DisableAbsoluteTimerIRQ API
* @details          Disable the FlexRay CC absolute timer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u8TimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_DisableAbsoluteTimerIRQ(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    uint8 u8TimerIdx
                                                   )
{
    if (0U == u8TimerIdx)
    {   /* Timer 1 irq should be disabled */
        Flexray_43_LLCE_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx,FLEXRAY_T1_EXPIRED,FALSE);
    }
    else
    {   /* Timer 2 irq should be disabled */
        Flexray_43_LLCE_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx,FLEXRAY_T2_EXPIRED,FALSE);
    }

}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_EnableAbsoluteTimerIRQ
*
* @brief            LLD function for the Fr_43_LLCE_EnableAbsoluteTimerIRQ
* @details          Enable the FlexRay CC absolute timer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u8TimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_EnableAbsoluteTimerIRQ(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   uint8 u8TimerIdx
                                                  )
{
     if (0U == u8TimerIdx)
    {   /* Timer 1 irq should be enabled */
        Flexray_43_LLCE_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_T1_EXPIRED, TRUE);
        Flexray_43_LLCE_Ip_SetGlobalInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_PROTOCOL_INTERRUPT, TRUE);

    }
    else
    {   /* Timer 2 irq should be enabled */
        Flexray_43_LLCE_Ip_SetProtocolInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_T2_EXPIRED, TRUE);
        Flexray_43_LLCE_Ip_SetGlobalInterrupt(pCtrlCfg->CtrlIdx, FLEXRAY_PROTOCOL_INTERRUPT, TRUE);
    }
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetAbsoluteTimerIRQStatus
*
* @brief            LLD function for the Fr_43_LLCE_GetAbsoluteTimerIRQStatus
* @details          Check whether absolute timer inerrupt flag is pending
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u8TimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           boolean
*                     - (boolean)TRUE - Interrupt is pending
*                     - (boolean)FALSE - Interrupt is not pending
***************************************************************************************************/
boolean Fr_43_LLCE_Ipw_GetAbsoluteTimerIRQStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                         uint8 u8TimerIdx
                                                        )
{
    boolean retVal = FALSE;
    if (0U == u8TimerIdx)
    {
        retVal = Flexray_43_LLCE_Ip_GetProtocolInterruptFlag(pCtrlCfg->CtrlIdx,FLEXRAY_T1_EXPIRED);
    }
    else
    {
        retVal = Flexray_43_LLCE_Ip_GetProtocolInterruptFlag(pCtrlCfg->CtrlIdx,FLEXRAY_T2_EXPIRED);
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_SetAbsoluteTimer
*
* @brief            LLD function for the Fr_43_LLCE_SetAbsoluteTimer API
* @details          Store information about absolute timer into the FlexRay CC registers
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u8TimerIdx  Index of FlexRay timer
* @param[in]        u8Cycle     Cycle the timer shall elapse in
* @param[in]        u16Offset    Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                             elapse at
* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_SetAbsoluteTimer(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                             uint8 u8TimerIdx,
                                             uint8 u8Cycle,
                                             uint16 u16Offset
                                            )
{
    uint8 u8InstNum = pCtrlCfg->CtrlIdx;
    /*  see if stopping a timer already stopped is ok */
    /* create struct with the default values */
    Flexray_Ip_TimerConfigType timerCfg;

    timerCfg.cycMask = 0x3FU;
    timerCfg.isRepetitive = FALSE;

    if (0U == u8TimerIdx)
    {
        timerCfg.timer = FLEXRAY_TIMER1;
    }
    else
    {
        timerCfg.timer = FLEXRAY_TIMER2;
    }

    /* for selected timer, macrotick (offset), cycle value */
    /* then, stop timer, store cycle, store macrotick, starttimer */

    timerCfg.cycVal = u8Cycle;
    timerCfg.macroTick = u16Offset;

    Flexray_43_LLCE_Ip_StopTimer(u8InstNum, timerCfg.timer);
    Flexray_43_LLCE_Ip_ConfigTimer(u8InstNum, &timerCfg );
    Flexray_43_LLCE_Ip_StartTimer(u8InstNum,timerCfg.timer);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_SetWakeupChannel
*
* @brief            LLD function for the Fr_43_LLCE_SetWakeupChannel API
* @details          Store information about wakeup channel into FlexRay CC registers
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        ChnlIdx   Index of FlexRay channel
* @return           Std_ReturnType:
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during set wakeup channel
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_SetWakeupChannel(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                       Fr_ChannelType ChnlIdx
                                                      )
{
    Std_ReturnType retVal;
    if (FR_CHANNEL_A == ChnlIdx)
    {
        retVal = (Std_ReturnType)Flexray_43_LLCE_Ip_SetWakeupChannel(pCtrlCfg->CtrlIdx, TRUE, FALSE);
    }
    else
    {
        retVal = (Std_ReturnType)Flexray_43_LLCE_Ip_SetWakeupChannel(pCtrlCfg->CtrlIdx, FALSE, TRUE);
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetGlobalTime
*
* @brief            LLD function for the Fr_43_LLCE_GetGlobalTime API
* @details          Query current cycle and macrotick from FlexRay CC registers
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[out]       CyclePtr  Address where current cycle is stored to
* @param[out]       MacroTickPtr - Address where current macrotick is stored to
* @return           void
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetGlobalTime(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    uint8* CyclePtr,
                                                    uint16* MacroTickPtr
                                                   )
{
    return (Std_ReturnType)Flexray_43_LLCE_Ip_GetGlobalTime(pCtrlCfg->CtrlIdx, CyclePtr, MacroTickPtr);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetNmVector
*
* @brief            LLD function for the Fr_43_LLCE_GetNmVector API
* @details          Read the network management vector of the last communication cycle
*                   and write it to the output parameter Fr_NmVectorPtr. The number of bytes
*                   written to the output parameter is constant and known at configuration time
* @param[in]        pCtrlCfg     Pointer config of FlexRay CC
* @param[out]       NmVectorPtr  Address of the variable the NmVector is stored to
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetNmVector(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint8* NmVectorPtr,
                                                  boolean* CheckLen
                                                 )
{
    Std_ReturnType retVal = E_OK;
    const Flexray_Ip_ConfigType *pFlexrayIpConfig = pCtrlCfg->IpConfigPtr;
    uint8 u8ConfigLen = pFlexrayIpConfig->peConfig->gNetworkManagementVectorLength;

    retVal = (Std_ReturnType) Flexray_43_LLCE_Ip_GetNMVector(pCtrlCfg->CtrlIdx, NmVectorPtr, &u8ConfigLen);
    if (u8ConfigLen != pFlexrayIpConfig->peConfig->gNetworkManagementVectorLength)
    {
        *CheckLen = FALSE;
    } else
    {
        *CheckLen = TRUE;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetChannelStatus
*
* @brief            LLD function for the Fr_43_LLCE_GetChannelStatus API
* @details          Reads the aggregated channel status, NIT status and symbol window status from
*                   FLEXRAY_PSR2, and FLEXRAY_PSR3 registers
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[out]       ChannelAStatusPtr  Address of the variable the channel A status is stored to
* @param[out]       ChannelBStatusPtr  Address of the variable the channel A status is stored to
* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_GetChannelStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                             uint16* ChannelAStatusPtr,
                                             uint16* ChannelBStatusPtr
                                            )
{
    Flexray_43_LLCE_Ip_GetChannelStatus(pCtrlCfg->CtrlIdx, ChannelAStatusPtr, ChannelBStatusPtr);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetClockCorrection
*
* @brief            LLD function for the Fr_43_LLCE_GetChannelStatus API
* @details          Read rate and offset correction values from FR_RTCORVR and FR_OFCORVR registers
* @param[in]        pCtrlCfg             Pointer config of FlexRay CC
* @param[out]       RateCorrectionPtr    Address of the variable the rate correction value is
*                                        stored to
* @param[out]       OffsetCorrectionPtr  Address of the variable the offset correction value is
*                                         stored to
* @return           void
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetClockCorrection(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                         sint16* RateCorrectionPtr,
                                                         sint32* OffsetCorrectionPtr
                                                        )
{
    return (Std_ReturnType)Flexray_43_LLCE_Ip_GetClockCorrection(pCtrlCfg->CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetSyncFrameList
*
* @brief            LLD function for the Fr_43_LLCE_GetSyncFrameList API
* @details          Reads syncFrame List ID table from FlexRay memory
* @param[in]        pCtrlCfg             Pointer config of FlexRay CC
* @param[out]       ChannelAEvenListPtr  Address of the variable the channel A even list is
*                                        stored to
* @param[out]       ChannelBEvenListPtr  Address of the variable the channel B even list is
*                                        stored to
* @param[out]       ChannelAOddListPtr   Address of the variable the channel A odd list is
*                                        stored to
* @param[out]       ChannelBOddListPtr   Address of the variable the channel B odd list is
*                                        stored to
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetSyncFrameList(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                       uint8 u8ListSize,
                                                       uint16* ChannelAEvenListPtr,
                                                       uint16* ChannelBEvenListPtr,
                                                       uint16* ChannelAOddListPtr,
                                                       uint16* ChannelBOddListPtr
                                                      )
{
    return (Std_ReturnType) Flexray_43_LLCE_Ip_GetSyncFrameList(pCtrlCfg->CtrlIdx, (Flexray_Ip_ConfigType*) pCtrlCfg->IpConfigPtr, u8ListSize, ChannelAEvenListPtr, ChannelBEvenListPtr, ChannelAOddListPtr, ChannelBOddListPtr);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetChannelStatus
*
* @brief            LLD function for the Fr_43_LLCE_GetWakeupRxStatus API
* @details          Reads the Wakeup Symbol Received on channel A and channel B bits from the
*                   FLEXRAY_PSR3 register
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[out]       WakeupRxStatusPtr  Address of a variable where the wakeup Rx status is stored to
* @return           void
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetWakeupRxStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                        uint8* WakeupRxStatusPtr
                                                       )
{
    Std_ReturnType retVal = E_NOT_OK;
    uint16 u16WakeupRxStatus = 0U;
    uint8 u8ChARxStatus = 0U;
    uint8 u8ChBRxStatus = 0U;
    uint16 PocStatus[4];

    u16WakeupRxStatus = (uint16) Flexray_43_LLCE_Ip_GetWakeupChannel(pCtrlCfg->CtrlIdx);
    u8ChARxStatus = (uint8)((u16WakeupRxStatus & FLEXRAY_PSR3_WUA_MASK) >> FLEXRAY_PSR3_WUA_SHIFT);
    u8ChBRxStatus = (uint8)((u16WakeupRxStatus & FLEXRAY_PSR3_WUB_MASK) >> FLEXRAY_PSR3_WUB_SHIFT);
    *WakeupRxStatusPtr = (u8ChBRxStatus << 1U) |  u8ChARxStatus;
    Flexray_43_LLCE_Ip_GetPocStatus(pCtrlCfg->CtrlIdx , PocStatus);
    if ((PocStatus[3] & (FLEXRAY_PSR3_WUA_MASK | FLEXRAY_PSR3_WUB_MASK)) == 0U)
    {
        retVal = E_OK;
    }
    return retVal;
}


/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_ReadbackCCConfig
*
* @brief            LLD function for the Fr_43_LLCE_ControllerInit API
* @details          Read back and compare cluster and configuration values to reference values
*                   held in the configuration.
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      Configuration is OK
*                       - E_NOT_OK  Error in configuration was found
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_ReadbackCCConfig(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg)
{
    return (Std_ReturnType)Flexray_43_LLCE_Ip_ReadbackCCConfig(pCtrlCfg->CtrlIdx,((Flexray_Ip_ConfigType*) pCtrlCfg->IpConfigPtr)->peConfig);
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_GetNumOfStartupFrames
*
* @brief            LLD function for the Fr_43_LLCE_GetNumOfStartupFrames
* @details          Reconfigures required LPdu
* @param[in]        pCtrlCfg        Pointer config of FlexRay CC
* @param[in]        configParamIdx  Index of LPdu to be reconfigured
* @return           Std_ReturnType
*                       - E_OK      Configuration is OK
*                       - E_NOT_OK  Error in configuration was found
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_GetNumOfStartupFrames(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                            uint8* NumOfStartupFramesPtr
                                                           )
{
    Std_ReturnType retVal = (Std_ReturnType)Flexray_43_LLCE_Ip_GetNumOfStartFrames(pCtrlCfg->CtrlIdx, NumOfStartupFramesPtr);
    return (retVal);
}

/**
 * @brief Checks the length of payload
 * either for dynamic or static type depending
 * on the number of static slots.
 *
 * @param pCtrlCfg   Pointer config of FlexRay CC
 * @param u16LPduIdx    Index of LPdu
 * @param u8LsduLength Payload length of data to be transmitted
 * @return Std_ReturnType E_OK - Payload length is lower than maximum allowed.
 */
Std_ReturnType Fr_43_LLCE_Ipw_CheckLpduLengthTransmitTX(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                                uint16 u16LPduIdx,
                                                                uint8 u8LsduLength
                                                               )
{

    Std_ReturnType retVal = (Std_ReturnType)(E_OK);
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);

    if (pIndBuff_info->frameID > pIpConfigPtr->peConfig->gNumberOfStaticSlots)
    {/* Buffer configured for the dynamic segment */
        if (u8LsduLength > (pIpConfigPtr->peConfig->pPayloadLengthDynMax * 2U))
        {

            retVal = (Std_ReturnType)(E_NOT_OK);
        }
    }
    else
    {/* Static segment */
        if (u8LsduLength > (pIpConfigPtr->peConfig->gPayloadLengthStatic * 2U))
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
 * @param u16LPduIdx  Index of LPdu
 * @return Std_ReturnType
 *              - E_OK if the buffer is Tx.
 */
Std_ReturnType Fr_43_LLCE_Ipw_CheckTXLpdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint16 u16LPduIdx
                                                 )
{
    Std_ReturnType retVal = (Std_ReturnType)(E_OK);
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);

    /* Check the buffer type. */
    if (TRUE != pIndBuff_info->isTx)
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}


/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_TransmitTxLPdu
*
* @brief            LLD function for the Fr_43_LLCE_TransmitTxLPdu API
* @details          Copy data and activate it for transmission
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[in]        u16LPduIdx            Index of LPdu to be transmitted
* @param[in]        LsduPtr            Address of data to be transmitted
* @param[in]        u8LsduLength         Payload length of data to be transmitted
* @param[out]       SlotAssignmentPtr  This reference points to the memory location where the
                                       actual cycle, slot ID, and channel of the frame identified by
                                       Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                       information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_TransmitTxLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                     uint16 u16LPduIdx,
                                                     const uint8* LsduPtr,
                                                     uint8 u8LsduLength,
                                                     Fr_SlotAssignmentType* SlotAssignmentPtr
                                                    )
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    #if (FR_43_LLCE_EXTENDED_LPDU_REPORTING == STD_ON)
    Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);
    #endif

    if (FLEXRAY_STATUS_SUCCESS == Flexray_43_LLCE_Ip_Send(pCtrlCfg->CtrlIdx, u8IndBufferConfigIndex, LsduPtr, u8LsduLength))
    {
        retVal = FLEXRAY_STATUS_SUCCESS;
        #if (FR_43_LLCE_EXTENDED_LPDU_REPORTING == STD_ON)

        if (NULL_PTR != SlotAssignmentPtr)
        {
            /* Read  the number of the current communication cycle in the CYCTR registers */
            (SlotAssignmentPtr->Cycle) = ((uint8) Flexray_43_LLCE_Ip_GetCurrentCycleCount(pCtrlCfg->CtrlIdx));
            /* copy slot ID of the transmitted frame to FLEXRAY_SlotAssignment*/
            (SlotAssignmentPtr->SlotId) = (pIndBuff_info->frameID);
            /* channel transmit data */
            if ((TRUE == (pIndBuff_info->channelA))&&(TRUE == (pIndBuff_info->channelB)))
            {
                /* Transmit on both A and B channels */
                SlotAssignmentPtr->channelId = FR_CHANNEL_AB;
            }
            else if ((TRUE == (pIndBuff_info->channelA))&&(FALSE == (pIndBuff_info->channelB)))
            {
                /* Transmit on channel A only */
                SlotAssignmentPtr->channelId = FR_CHANNEL_A;
            }
            else if ((FALSE == (pIndBuff_info->channelA))&&(TRUE == (pIndBuff_info->channelB)))
            {
                /* Transmit on channel B only */
                SlotAssignmentPtr->channelId = FR_CHANNEL_B;
            }
            else
            {
                /* Do nothing */
            }
        }
        #else
        (void)SlotAssignmentPtr;
        #endif
    }
    return (Std_ReturnType)retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_ReceiveRxLPdu
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @details          Copy receive payload data
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[in]        u16LPduIdx            Index of LPdu to be transmitted
* @param[out]       LsduPtr            Address of field that data is copied to
* @param[out]       LPduStatusPtr      Address of the variable the status is stored to
* @param[out]       LsduLengthPtr      Address of the variable the payload is stored to
* @param[out]       SlotAssignmentPtr  This reference points to the memory location where the
                                       actual cycle, slot ID, and channel of the frame identified by
                                       Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                       information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the controller
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_ReceiveRxLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    uint16 u16LPduIdx,
                                                    uint8* LsduPtr,
                                                    Fr_RxLPduStatusType* LPduStatusPtr,
                                                    uint8* LsduLengthPtr,
                                                    Fr_SlotAssignmentType* SlotAssignmentPtr
                                                   )
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);
    const Flexray_Ip_BufferStateType* bState = &(((Flexray_Ip_BufferStateType*)(pIpStateAllocPtr->bufferState))[u8IndBufferConfigIndex]);
    Flexray_Ip_FrameHeaderType frameHdr = {FALSE};

    Flexray_43_LLCE_Ip_ReceiveInd(pCtrlCfg->CtrlIdx, u8IndBufferConfigIndex, &frameHdr, LsduPtr ,pIndBuff_info->payloadLength);
    if (FLEXRAY_STATUS_UNSUPPORTED !=  bState->status)
    {
        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if (TRUE == bState->slotStatusError)
        {
            Fr_43_LLCE_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[u16LPduIdx], DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            Fr_43_LLCE_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[u16LPduIdx], DEM_EVENT_STATUS_PASSED);
        }
        #endif /* FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
        #if (FR_43_LLCE_EXTENDED_LPDU_REPORTING == STD_ON)
         if (NULL_PTR != SlotAssignmentPtr)
         {
             /* Read  the number of the current communication cycle in the CYCTR registers */
             (SlotAssignmentPtr->Cycle) = ((uint8)frameHdr.cycleCount);
             /* copy slot ID of the transmitted frame to FLEXRAY_SlotAssignment*/
             (SlotAssignmentPtr->SlotId) = ((uint8)frameHdr.frameID);
             /* channel transmit data */
             if ((0x0080U == (frameHdr.slotStatus & FLEXRAY_43_LLCE_STRINGENT_MASK_A)) || ( 0x8000U ==(frameHdr.slotStatus & FLEXRAY_43_LLCE_STRINGENT_MASK_B)))
             {
                 SlotAssignmentPtr->channelId = FR_CHANNEL_AB;
             }
             else if (0x0080U == (frameHdr.slotStatus & FLEXRAY_43_LLCE_STRINGENT_MASK_A))
             {
                 /* Transmit on channel A only */
                 SlotAssignmentPtr->channelId = FR_CHANNEL_A;
             }
             else if (0x8000U == (frameHdr.slotStatus & FLEXRAY_43_LLCE_STRINGENT_MASK_B))
             {
                 /* Transmit on channel B only */
                 SlotAssignmentPtr->channelId = FR_CHANNEL_B;
             }
             else
             {
                 /* Do nothing */
             }
         }
         #else
             (void)SlotAssignmentPtr;
         #endif
         if (FLEXRAY_STATUS_SUCCESS == bState->status)
         {
             *LsduLengthPtr = (uint8)(frameHdr.payloadLength << 1U);
             *LPduStatusPtr = FR_RECEIVED;
         }
         else
         {
             *LsduLengthPtr = 0U;
             *LPduStatusPtr = FR_NOT_RECEIVED;
         }

         retVal = FLEXRAY_STATUS_SUCCESS;

    }
    return (Std_ReturnType) retVal;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_ReceiveFifo
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @details          Copy Fifo data
* @param[in]        pCtrlCfg          Pointer config of FlexRay CC
* @param[in]        u16LPduIdx           Index of LPdu to be transmitted
* @param[out]       LsduPtr           Address of field that data is copied to
* @param[out]       LPduStatusPtr     Address of the variable the status is stored to
* @param[out]       LsduLengthPtr     Address of the variable the payload is stored to
* @param[out]       SlotAssignmentPtr Pointer used to store cycle, slot ID, and channel of the frame identified by Fr_LPduIdx
* @param[in]        FIFOChannel       Channel for FIFO

* @return           void
***************************************************************************************************/
void Fr_43_LLCE_Ipw_ReceiveFifo(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                        uint16 u16LPduIdx,
                                        uint8* LsduPtr,
                                        Fr_RxLPduStatusType* LPduStatusPtr,
                                        uint8* LsduLengthPtr,
                                        Fr_SlotAssignmentType* SlotAssignmentPtr
                                       )
{
    Flexray_Ip_StatusType retVal;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    const Flexray_Ip_FifoConfigType* pFifoBuff_info ;
    Flexray_Ip_FrameHeaderType frameHdr;

    if (FR_43_LLCE_FIFOA_BUFFER == pCtrlCfg->LpduInfoPtr[u16LPduIdx].StorageType)
    {
        pFifoBuff_info = pIpConfigPtr->fifoConfigA;
        retVal = Flexray_43_LLCE_Ip_ReceiveFIFO(pCtrlCfg->CtrlIdx, FALSE, &frameHdr, LsduPtr, pFifoBuff_info->entrySize);
    } else
    {
        pFifoBuff_info = pIpConfigPtr->fifoConfigB;
        retVal = Flexray_43_LLCE_Ip_ReceiveFIFO(pCtrlCfg->CtrlIdx, TRUE, &frameHdr, LsduPtr, pFifoBuff_info->entrySize);
    }
    if (FLEXRAY_STATUS_SUCCESS == retVal)
    {
        #if (FR_43_LLCE_EXTENDED_LPDU_REPORTING == STD_ON)
         if (NULL_PTR != SlotAssignmentPtr)
         {
             /* Read  the number of the current communication cycle in the CYCTR registers */
             (SlotAssignmentPtr->Cycle) = ((uint8)frameHdr.cycleCount);
             /* copy slot ID of the transmitted frame to FLEXRAY_SlotAssignment*/
             (SlotAssignmentPtr->SlotId) = ((uint8)frameHdr.frameID);
             /* channel transmit data */
             if (FR_43_LLCE_FIFOA_BUFFER == pCtrlCfg->LpduInfoPtr[u16LPduIdx].StorageType)
             {
                 SlotAssignmentPtr->channelId = FR_CHANNEL_A;
             }
             else
             {
                 SlotAssignmentPtr->channelId = FR_CHANNEL_B;
             }

         }
         #else
             (void)SlotAssignmentPtr;
         #endif
         *LsduLengthPtr = (uint8)(frameHdr.payloadLength << 1U);
         *LPduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;

    }
    else
    {
        *LsduLengthPtr = 0U;
        *LPduStatusPtr = FR_NOT_RECEIVED;
    }
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_CheckTxLPduStatus
*
* @brief            LLD function for the Fr_43_LLCE_CheckTxLPduStatus API
* @details          Check whether LPdu was transmitted or not
* @param[in]        pCtrlCfg           Pointer config of FlexRay CC
* @param[in]        u16LPduIdx            Index of LPdu to be canceled
* @param[out]       TxLPduStatusPtr    Address of the variable where the status information is
*                                      stored to
* @param[out]       SlotAssignmentPtr  This reference points to the memory location where the
                                       actual cycle, slot ID, and channel of the frame identified by
                                       Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                       information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_CheckTxLPduStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                        uint16 u16LPduIdx,
                                                        Fr_TxLPduStatusType* TxLPduStatusPtr,
                                                        Fr_SlotAssignmentType* SlotAssignmentPtr
                                                       )
{

    Flexray_Ip_StatusType retVal;
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    #if (FR_43_LLCE_EXTENDED_LPDU_REPORTING == STD_ON)
    Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);
    #endif
    const Flexray_Ip_BufferStateType* bState = &(((Flexray_Ip_BufferStateType*)(pIpStateAllocPtr->bufferState))[u8IndBufferConfigIndex]);

    retVal = Flexray_43_LLCE_Ip_GetTransferStatus(pCtrlCfg->CtrlIdx, u8IndBufferConfigIndex);
    if (FLEXRAY_STATUS_ERROR != retVal)
    {
    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if (0U == (bState->frameHdr->slotStatus & 0x0101U))
        {
            Fr_43_LLCE_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[u16LPduIdx], DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            Fr_43_LLCE_Ipw_DemSetEventStatus (pCtrlCfg->LpduInfoPtr[u16LPduIdx], DEM_EVENT_STATUS_FAILED);
        }
    #endif
    #if (FR_43_LLCE_EXTENDED_LPDU_REPORTING == STD_ON)
        if (NULL_PTR != SlotAssignmentPtr)
        {
            SlotAssignmentPtr->Cycle = ((uint8) Flexray_43_LLCE_Ip_GetCurrentCycleCount(pCtrlCfg->CtrlIdx));
            SlotAssignmentPtr->SlotId = ((uint8)bState->frameHdr->frameID);
            if ((pIndBuff_info->channelA)&&(pIndBuff_info->channelB))
            {
                SlotAssignmentPtr->channelId = FR_CHANNEL_AB;
            }
            else if (pIndBuff_info->channelA)
            {
                SlotAssignmentPtr->channelId = FR_CHANNEL_A;
            }
            else
            {
                SlotAssignmentPtr->channelId = FR_CHANNEL_B;
            }
        }
    #else
        (void)bState;
        (void)SlotAssignmentPtr;
    #endif
        if ((FLEXRAY_STATUS_TX_CONFLICT_A == retVal) || (FLEXRAY_STATUS_TX_CONFLICT_B == retVal) || (FLEXRAY_STATUS_TX_CONFLICT_AB == retVal))
        {
            *TxLPduStatusPtr = FR_TRANSMITTED_CONFLICT;
        }
        else if (FLEXRAY_STATUS_SUCCESS == retVal)
        {
            *TxLPduStatusPtr = FR_TRANSMITTED;
        } else
        {
            *TxLPduStatusPtr = FR_NOT_TRANSMITTED;
        }
        retVal = FLEXRAY_STATUS_SUCCESS;
    }
    return (Std_ReturnType) retVal;
}

#if (FR_43_LLCE_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_PrepareLPdu
*
* @brief            LLD function for the Fr_43_LLCE_PrepareLPdu API
* @details          Check LPdu status
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u16LPduIdx   Index of LPdu to be prepared
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_PrepareLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint16 u16LPduIdx
                                                 )
{
    /* Set initial return value */
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    uint8 u8InstNum = pCtrlCfg->CtrlIdx;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    Flexray_Ip_IndConfigType* pIndBuff_info = &(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);
    Flexray_Ip_BufferStateType** mbStateMap = pIpStateAllocPtr->mbStateMap;
    Flexray_Ip_BufferStateType* bufferState = pIpStateAllocPtr->bufferState;

    if (FR_43_LLCE_IND_BUFFER == pCtrlCfg->LpduInfoPtr[u16LPduIdx].StorageType)
    {
        retVal = Flexray_43_LLCE_Ip_ReConfigIndividual(u8InstNum, pIndBuff_info);
        if (FLEXRAY_STATUS_SUCCESS == retVal)
        {
            mbStateMap[pIndBuff_info->MBIndex] = &bufferState[u8IndBufferConfigIndex];
        }
    }

    return (Std_ReturnType) retVal;
}

#endif /* FR_43_LLCE_PREPARE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_CancelTxLPdu
*
* @brief            LLD function for the Fr_43_LLCE_CancelTxLPdu API
* @details          Cancel required LPdu and provide information about it
* @param[in]        pCtrlCfg      Pointer config of FlexRay CC
* @param[in]        u16LPduIdx       Index of LPdu to be canceled
* @param[out]       PendingStatus Information whether the LPdu was canceled or not
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_CancelTxLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   uint16 u16LPduIdx,
                                                   boolean* PendingStatus
                                                  )
{
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    return (Std_ReturnType) Flexray_43_LLCE_Ip_CancelTxBuffer(pCtrlCfg->CtrlIdx, u8IndBufferConfigIndex, PendingStatus);
}


#if (FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_ReconfigLPdu
*
* @brief            LLD function for the Fr_43_LLCE_ReconfigLPdu API
* @details          Reconfigures required LPdu
* @param[in]        pCtrlCfg        Pointer config of FlexRay CC
* @param[in]        u16LPduIdx         Index of LPdu to be reconfigured
* @param[in]        FrameId         Frame ID for reconfiguration
* @param[in]        CycleRepetition Repetition value for cycle filter mechanism
* @param[in]        CycleOffste     Offste value for cycle filter mechanism
* @param[in]        PayloadLength   payload for data to be reconfigured
* @param[in]        HeaderCRC       hedaer CRC value
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_ReconfigLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   uint16 u16LPduIdx,
                                                   uint16 FrameId,
                                                   Fr_ChannelType ChnlIdx,
                                                   uint8 CycleRepetition,
                                                   uint8 CycleOffset,
                                                   uint8 PayloadLength,
                                                   uint16 HeaderCRC
                                                  )
{
    Flexray_Ip_StatusType retVal = FLEXRAY_STATUS_ERROR;
    const Flexray_Ip_ConfigType* pIpConfigPtr = (Flexray_Ip_ConfigType*)(pCtrlCfg->IpConfigPtr);
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;
    const Flexray_Ip_IndConfigType* pIndBuff_info =&(((Flexray_Ip_IndConfigType*)(pIpConfigPtr->indBufConfig))[u8IndBufferConfigIndex]);
    #if (STD_ON == FLEXRAY_43_LLCE_PREPARE_LPDU_SUPPORT)
    const Flexray_Ip_StateAllocateType* pIpStateAllocPtr = (Flexray_Ip_StateAllocateType*)(pCtrlCfg->IpStateAllocPtr);
    #endif
    Flexray_Ip_IndConfigType pIndBuff_info_reconfig;

    #if (STD_ON == FLEXRAY_43_LLCE_PREPARE_LPDU_SUPPORT)
    if (pIpStateAllocPtr->mbStateMap[pIndBuff_info->MBIndex]->bufferId == u8IndBufferConfigIndex)
    {
    #endif
        pIndBuff_info_reconfig.MBIndex = pIndBuff_info->MBIndex;
        pIndBuff_info_reconfig.phyMBIndex = pIndBuff_info->phyMBIndex;
        pIndBuff_info_reconfig.firstInit = pIndBuff_info->firstInit;
        pIndBuff_info_reconfig.frameID = FrameId;
        pIndBuff_info_reconfig.headerCrc = HeaderCRC;
        pIndBuff_info_reconfig.PPI = FALSE;
        pIndBuff_info_reconfig.payloadLength = PayloadLength;
        pIndBuff_info_reconfig.isTx = pIndBuff_info->isTx;
        if (FR_CHANNEL_AB == ChnlIdx)
        {
            pIndBuff_info_reconfig.channelA = TRUE;
            pIndBuff_info_reconfig.channelB = TRUE;
        }
        else if (FR_CHANNEL_A == ChnlIdx)
        {
            pIndBuff_info_reconfig.channelA = TRUE;
            pIndBuff_info_reconfig.channelB = FALSE;
        }
        else
        {
            pIndBuff_info_reconfig.channelA = FALSE;
            pIndBuff_info_reconfig.channelB = TRUE;
        }
        pIndBuff_info_reconfig.ccFilterVal = CycleOffset;
        pIndBuff_info_reconfig.ccFilterMask = CycleRepetition - 1U;
        if ((CycleOffset != 0U)||(CycleRepetition > 1U))
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
        retVal = Flexray_43_LLCE_Ip_ReConfigIndividual(pCtrlCfg->CtrlIdx, &pIndBuff_info_reconfig);
    #if (STD_ON == FLEXRAY_43_LLCE_PREPARE_LPDU_SUPPORT)
    }
    #endif
    return (Std_ReturnType) retVal ;
}

#endif /* FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON */

#if (FR_43_LLCE_DISABLE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_Ipw_DisableLPdu
*
* @brief            LLD function for the Fr_43_LLCE_DisableLPdu
* @details          Disables required Message Buffer
* @param[in]        pCtrlCfg  Pointer config of FlexRay CC
* @param[in]        u16LPduIdx   Index of LPdu to be reconfigured
* @return           Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_Ipw_DisableLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint16 u16LPduIdx
                                                 )
{
    uint8 u8IndBufferConfigIndex = pCtrlCfg->LpduInfoPtr[u16LPduIdx].BufferConfigIndex;

    return (Std_ReturnType)Flexray_43_LLCE_Ip_Abort(pCtrlCfg->CtrlIdx, u8IndBufferConfigIndex);
}
#endif /* FR_43_LLCE_DISABLE_LPDU_SUPPORT == STD_ON */

#define FR_43_LLCE_STOP_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
