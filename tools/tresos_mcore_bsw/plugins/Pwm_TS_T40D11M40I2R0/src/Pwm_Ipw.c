/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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
*   @file       Pwm_Ipw.c
*
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Pwm_Ipw.h"

#include "Pwm_Ipw_Notif.h"

#include "Ftm_Pwm_Ip.h"

/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define PWM_IPW_VENDOR_ID_C                     43
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define PWM_IPW_AR_RELEASE_MINOR_VERSION_C      4
#define PWM_IPW_AR_RELEASE_REVISION_VERSION_C   0
#define PWM_IPW_SW_MAJOR_VERSION_C              4
#define PWM_IPW_SW_MINOR_VERSION_C              0
#define PWM_IPW_SW_PATCH_VERSION_C              2

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if source file and Pwm_Ipw.h header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw.h header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw.h header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_NOTIF_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip.h header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID_C != FTM_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and Ftm_Pwm_Ip.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip.h header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and Ftm_Pwm_Ip.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip.h header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION_C != FTM_PWM_IP_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != FTM_PWM_IP_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != FTM_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and Ftm_Pwm_Ip.h are different."
#endif

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"

/** @brief Array to save the period of the ftm channel */
extern uint16 Ftm_Pwm_Ip_aPeriod[FTM_PWM_IP_INSTANCE_COUNT];

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/** @brief Array to save the duty cycle of the ftm channel */
static uint16 Pwm_Ipw_aFtmDutyCycle[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];
#endif

#define PWM_STOP_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"


#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/*! @brief Arrays to store the current state of channel */
extern Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aChannelState[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the previous state of each channel */
extern Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aPreviousChannelState[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the type of notification for each channel */
extern Ftm_Pwm_Ip_EdgeInterruptType Ftm_Pwm_Ip_aNotifIrq[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the polarity of each channel */
Ftm_Pwm_Ip_PolarityType Ftm_Pwm_Ip_aPolarity[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"
/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/

/*===============================================================================================
*                                          LOCAL MACROS
===============================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
static Ftm_Pwm_Ip_NotifType Pwm_Ipw_ConvertChIDToNotifType(uint8 ChannelID);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static Ftm_Pwm_Ip_NotifType Pwm_Ipw_ConvertChIDToNotifType(uint8 ChannelID)
{
    Ftm_Pwm_Ip_NotifType NotifTypeValue = FTM_PWM_IP_CHANNEL_0_NOTIFICATION;
    
    switch (ChannelID)
    {
        case 0x0U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_0_NOTIFICATION;

            break;
        }
        case 0x01U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_1_NOTIFICATION;

            break;
        }
        case 0x02U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_2_NOTIFICATION;

            break;
        }
        case 0x03U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_3_NOTIFICATION;

            break;
        }
        case 0x04U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_4_NOTIFICATION;

            break;
        }
        case 0x05U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_5_NOTIFICATION;

            break;
        }
        case 0x06U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_6_NOTIFICATION;

            break;
        }
        case 0x07U:
        {
            NotifTypeValue = FTM_PWM_IP_CHANNEL_7_NOTIFICATION;

            break;
        }
        default:
        {
            /* Do nothing */
            break;
        }
    }
    
    return NotifTypeValue;
}
#endif
/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/

/*=============================================================================================*/
/**
* @brief        Pwm_Ipw_Init
* @details      This function call the supported IP initialization functions.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_Init(const Pwm_IpwChannelConfigType * const IpConfig)
{

    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            /* Duty cycle of Ftm Ip */
            Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = IpConfig->ChannelDutyCycle;
#endif
            /* Nothing to do. No hw channel assigned to the logical channel */
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}

/*=============================================================================================*/
#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_InitInstance
* @details      This Pwm_Ipw_InitInstance is called once for each channel in the used configuration.
*               It determines the type of the HW channel (e.g. Ftm,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_InitInstance(const Pwm_IpwInstanceConfigType * const IpConfig)
{
#if (PWM_FTM_USED == STD_ON)
    uint8 Index = 0U;
    uint8 ChannelId = 0U;
#endif
    switch(IpConfig->InstanceType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_INSTANCE_FTM:
            if (NULL_PTR != IpConfig->FtmInsConfig)
            {
                /* Call Ftm IP initialize instances */
                Ftm_Pwm_Ip_Init(IpConfig->InstanceId, (const Ftm_Pwm_Ip_UserCfgType *)IpConfig->FtmInsConfig);

                /* Configure all channels in the user cfg */
                for (Index = 0; Index < IpConfig->FtmInsConfig->NoOfConfiguredCh; Index++)
                {
                    ChannelId = IpConfig->FtmInsConfig->ConfiguredChArray[Index]->ChannelId;
                    /* Update the polarity of each channel */
                    Ftm_Pwm_Ip_aPolarity[IpConfig->InstanceId][ChannelId] = IpConfig->FtmInsConfig->ConfiguredChArray[Index]->Polarity;
                }
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_HW_INSTANCE_USED == STD_ON */

/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        Pwm_Ipw_DeInit
* @details      This function call the supported IP de-initialization functions.
*
* @param[in]    IpConfig            Pointer to PWM top configuration structure
* @param[in]    ChannelIdleState    The state of the channel output in idle mode
*
* @return       void
*
*/
void Pwm_Ipw_DeInit(const Pwm_IpwChannelConfigType * const IpConfig, Pwm_OutputStateType ChannelIdleState)
{

    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            /* Duty cycle of Ftm Ip */
            Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = 0U;
#endif
            /* Nothing to do. No hw channel assigned to the logical channel */
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
    (void) ChannelIdleState;
}

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_DeInitInstance
* @details      This function call the supported IP de-initialization instances.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_DeInitInstance(const Pwm_IpwInstanceConfigType * const IpConfig)
{

    switch(IpConfig->InstanceType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_INSTANCE_FTM:
            if (NULL_PTR != IpConfig->FtmInsConfig)
            {
                /* Call Ftm IP initialize instances */
                Ftm_Pwm_Ip_DeInit(IpConfig->InstanceId);
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}
#endif
#endif /* PWM_DE_INIT_API */

/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetDutyCycle
* @details      This function will call SetDutyCycle function for the corresponding IP of PwmChannel
*
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        The duty cycle could not be set
*               E_OK            The duty cycle is set to the new value
*
*/
Std_ReturnType Pwm_Ipw_SetDutyCycle(uint16                           DutyCycle,
                                    const Pwm_IpwChannelConfigType * const IpConfig)
{

    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
#if (PWM_FTM_USED == STD_ON)
    uint16 FtmDutyCycle = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
            if (NULL_PTR != IpConfig->FtmChConfig)
            {
                FtmDutyCycle = (uint16)(((uint32)Ftm_Pwm_Ip_aPeriod[IpConfig->ChannelInstanceId] * DutyCycle) / 0x8000U);
                /* Call Ftm IP initialize function */
                Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel(IpConfig->ChannelInstanceId,
                                                     ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId,
                                                     FtmDutyCycle,
                                                     TRUE);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                /* Duty cycle of Ftm Ip */
                Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = DutyCycle;
#endif
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }

    return RetVal;
}
#endif /* PWM_SET_DUTY_CYCLE_API */

/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetPeriodAndDuty
* @details      This function will call SetPeriodAndDuty function for the corresponding IP of PwmChannel
*
* @param[in]    Period         Period value for this channel
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPeriodAndDuty(Pwm_PeriodType                   Period,
                              uint16                           DutyCycle,
                              const Pwm_IpwChannelConfigType * const IpConfig)
{

#if (PWM_FTM_USED == STD_ON)
    uint16 FtmDutyCycle = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
            if (NULL_PTR != IpConfig->FtmChConfig)
            {
                FtmDutyCycle = (uint16)(((uint32)Period * DutyCycle) / 0x8000U);
                /* Call Ftm IP initialize function */
                Ftm_Pwm_Ip_UpdatePwmPeriodAndDuty(IpConfig->ChannelInstanceId,
                                                  ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId,
                                                  Period,
                                                  FtmDutyCycle,
                                                  TRUE);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                /* Duty cycle of Ftm Ip */
                Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = DutyCycle;
#endif
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */

/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetOutputToIdle
* @details      This function will call SetOutputToIdle function for the corresponding IP of PwmChannel
*
* @param[in]    IdleState      The state of output channel when entering Idle mode
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetOutputToIdle(const Pwm_OutputStateType IdleState, const Pwm_IpwChannelConfigType * const IpConfig)
{
#if (PWM_FTM_USED == STD_ON)
    uint8 Instance  =  IpConfig->ChannelInstanceId;
    uint8 Channel   =  ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
            if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
            {
                /* update new state of channel */
                Ftm_Pwm_Ip_aChannelState[Instance][Channel] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_IDLE;
                
                Ftm_Pwm_Ip_SwOutputControl(Instance,
                                           Channel,
                                           ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->InitOut,
                                           TRUE);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                /* Duty cycle of Ftm Ip */
                Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = 0U;
#endif
            }
            else
            {
                /* Do Nothing */
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }

    (void) IdleState;
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        Pwm_Ipw_GetOutputState
* @details      This function will call GetOutputState function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Pwm_OutputStateType
*
*/
Pwm_OutputStateType Pwm_Ipw_GetOutputState(const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Return value */
    Pwm_OutputStateType                      RetVal = PWM_LOW;

#if (PWM_FTM_USED == STD_ON)
    Ftm_Pwm_Ip_OutputStateType               FtmRetVal = FTM_PWM_IP_OUTPUT_STATE_LOW;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
            if (NULL_PTR != IpConfig->FtmChConfig)
            {
                /* Call FTM IP function */
                FtmRetVal = Ftm_Pwm_Ip_GetOutputState(IpConfig->ChannelInstanceId,
                                                      ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId);

                RetVal = (FTM_PWM_IP_OUTPUT_STATE_LOW == FtmRetVal) ? PWM_LOW : PWM_HIGH;                            
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }

    return RetVal;
}
#endif /* PWM_GET_OUTPUT_STATE_API */

/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_DisableNotification
* @details      This function will call DisableNotification function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_DisableNotification(const Pwm_IpwChannelConfigType * const IpConfig)
{
    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
            if (NULL_PTR != IpConfig->FtmChConfig)
            {
                /* Get the notification type corresponding channel ID */
                Ftm_Pwm_Ip_NotifType NotifType = Pwm_Ipw_ConvertChIDToNotifType(((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId);

                /* Call Ftm IP initialize function */
                Ftm_Pwm_Ip_DisableNotification(IpConfig->ChannelInstanceId,
                                               NotifType);


            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_EnableNotification
* @details      This function will call EnableNotification function for the corresponding IP of PwmChannel
*
* @param[in]    Notification   Notification edge type to be enabled
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_EnableNotification(Pwm_EdgeNotificationType         Notification,
                                const Pwm_IpwChannelConfigType * const IpConfig)
{
    switch(IpConfig->ChannelType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_CHANNEL_FTM:
            if (NULL_PTR != IpConfig->FtmChConfig)
            {
                /* Clear notification type of given channel in global array to prepare writing new value */
                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] &= (uint8)(~(uint32)(FTM_PWM_IP_CHF_IRQ_EDGE | FTM_PWM_IP_TOF_IRQ_EDGE));
                /* Get mode of channel*/
                Ftm_Pwm_Ip_ChannelModeType ChannelMode = (Ftm_Pwm_Ip_ChannelModeType)(((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelMode);
                /* Get the channel ID */
                uint8 ChannelIdx = ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId;
                /* Get the notification type corresponding channel ID */
                Ftm_Pwm_Ip_NotifType NotifType = Pwm_Ipw_ConvertChIDToNotifType(ChannelIdx);
            
                if ((FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH   == ChannelMode) ||
                (FTM_PWM_IP_MODE_EDGE_ALIGNED_LOW        == ChannelMode) ||
                (FTM_PWM_IP_MODE_CENTER_ALIGNED_HIGH     == ChannelMode) ||
                (FTM_PWM_IP_MODE_CENTER_ALIGNED_LOW      == ChannelMode))
                {   
                    switch (Notification)
                    {
                        case PWM_BOTH_EDGES:
                        {
                            Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx] |= (Ftm_Pwm_Ip_EdgeInterruptType)(FTM_PWM_IP_TOF_IRQ_EDGE | FTM_PWM_IP_CHF_IRQ_EDGE);
            
                            break;
                        }
                        case PWM_RISING_EDGE:
                        {
                            if (FTM_PWM_IP_POLARITY_HIGH == Ftm_Pwm_Ip_aPolarity[IpConfig->ChannelInstanceId][ChannelIdx])
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx] |= FTM_PWM_IP_TOF_IRQ_EDGE;
                            }
                            else
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx] |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            }
            
                            break;
                        }
                        case PWM_FALLING_EDGE:
                        {
                            if (FTM_PWM_IP_POLARITY_LOW == Ftm_Pwm_Ip_aPolarity[IpConfig->ChannelInstanceId][ChannelIdx])
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx] |= FTM_PWM_IP_TOF_IRQ_EDGE;
                            }
                            else
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx] |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            }
            
                            break;
                        }
                        default:
                        {
                            /* Do nothing */
                            break;
                        }
                    }
                }
                else
                {
                    /* Writing new notification type for given channel in combine mode */
                    switch (Notification)
                    {
                        case PWM_BOTH_EDGES:
                        {
                            Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx]        |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx + 1U]   |= FTM_PWM_IP_CHF_IRQ_EDGE;
            
                            break;
                        }
                        case PWM_RISING_EDGE:
                        {
                            if (FTM_PWM_IP_POLARITY_HIGH == Ftm_Pwm_Ip_aPolarity[IpConfig->ChannelInstanceId][ChannelIdx])
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx]        |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            }
                            else
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx + 1U]   |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            }
            
                            break;
                        }
                        case PWM_FALLING_EDGE:
                        {
                            if (FTM_PWM_IP_POLARITY_LOW == Ftm_Pwm_Ip_aPolarity[IpConfig->ChannelInstanceId][ChannelIdx])
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx + 1U]   |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            }
                            else
                            {
                                Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][ChannelIdx]        |= FTM_PWM_IP_CHF_IRQ_EDGE;
                            }
            
                            break;
                        }
                        default:
                        {
                            /* Do nothing */
                            break;
                        }
                    }
                }

                /* Call Ftm IP initialize function */
                Ftm_Pwm_Ip_EnableNotification(IpConfig->ChannelInstanceId,
                                              NotifType);
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_DisableReloadNotification
* @details      This function will call DisableReloadNotification function for the corresponding IP of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_DisableReloadNotification(uint8 ModuleId)
{
    /* Call Ftm IP function */
    Ftm_Pwm_Ip_DisableNotification(ModuleId, FTM_PWM_IP_RELOAD_POINT_NOTIFICATION);
}
#endif /* PWM_RELOAD_NOTIF_SUPPORTED */

/*===============================================================================================*/
#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_EnableReloadNotification
* @details      This function will call EnableReloadNotification function for the corresponding IP of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_EnableReloadNotification(uint8 ModuleId)
{
    /* Call Ftm IP function */
    Ftm_Pwm_Ip_EnableNotification(ModuleId, FTM_PWM_IP_RELOAD_POINT_NOTIFICATION);
}
#endif /* PWM_RELOAD_NOTIF_SUPPORTED */

/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        Pwm_Ipw_GetChannelState
* @details      This function will call GetChannelState function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       uint16
*
*/
uint16 Pwm_Ipw_GetChannelState(const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Return duty cycle value */
    uint16      DutyCycle = (uint16)0U;

    /* Get Duty cycle of Ftm Ip */
    DutyCycle =  Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId];

    return DutyCycle;
}
#endif /* PWM_GET_CHANNEL_STATE_API */

/*===============================================================================================*/
#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief        Pwm_Ipw_ForceOutputToZero
* @details      This function will call ForceOutputToZero function only if then channel is a
*               FTM channel
*
* @param[in]    Force          Flag to state if force to zero should be applied or not
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
* @implements   Pwm_Ipw_ForceOutputToZero_Activity
*/
void Pwm_Ipw_ForceOutputToZero(boolean                          Force,
                               const Pwm_IpwChannelConfigType * const IpConfig)
{

    uint8                      Instance    =  IpConfig->ChannelInstanceId;
    uint8                      Channel     =  ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId;
    boolean                    ForceOutput =  Force;
    Ftm_Pwm_Ip_PolarityType    Polarity    =  ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->Polarity;
    Ftm_Pwm_Ip_OutputStateType OutputState =  (FTM_PWM_IP_POLARITY_LOW == Polarity)? FTM_PWM_IP_OUTPUT_STATE_HIGH : FTM_PWM_IP_OUTPUT_STATE_LOW;

    if (FTM_PWM_IP_CHANNEL_OUTPUT_FORCED != Ftm_Pwm_Ip_aChannelState[Instance][Channel])
    {
        if(TRUE == ForceOutput)
        {
            /* Store this current state into previous state array */
            Ftm_Pwm_Ip_aPreviousChannelState[Instance][Channel] = Ftm_Pwm_Ip_aChannelState[Instance][Channel];
            
            Ftm_Pwm_Ip_aChannelState[Instance][Channel] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_OUTPUT_FORCED;
        }
        else
        {
            /* Do Nothing*/
        }
    }
    else
    {
        if(FALSE == ForceOutput)
        {
            /* ..then get the last operation then store into current state array */
            Ftm_Pwm_Ip_aChannelState[Instance][Channel] = Ftm_Pwm_Ip_aPreviousChannelState[Instance][Channel];
            
            if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_IDLE == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
            {
                OutputState = ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->InitOut;
                ForceOutput = TRUE;
            }
        }
        else
        {
            /* Do Nothing*/
        }
    }

    Ftm_Pwm_Ip_SwOutputControl(Instance,
                               Channel,
                               OutputState,
                               ForceOutput);
}
#endif /* PWM_FORCE_OUTPUT_TO_ZERO_API */

/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockMode
* @details      This function will call SetClockMode function of all configured hardware FTM module
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockMode(Pwm_PrescalerType                 Prescaler,
                          const Pwm_IpwInstanceConfigType * const IpConfig)
{
    Ftm_Pwm_Ip_PrescalerType     FtmPrescaler;

    if (PWM_PRIMARY_PRESCALER == Prescaler)
    {
        FtmPrescaler = FTM_PWM_IP_PRIMARY_PRESCALER;
    }
    else
    {
        FtmPrescaler = FTM_PWM_IP_ALTERNATIVE_PRESCALER;
    }

    /* Call FTM IP function */
    Ftm_Pwm_Ip_SetClockMode(IpConfig->InstanceId,
                            FtmPrescaler);
}
#endif /* PWM_SET_CLOCK_MODE_API */

/*===============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief
* @details      This function is used to update the deadtime at runtime for Pwm channels.
*
* @param[in]    DeadTimeTicks       Dead Time value in ticks unit
* @param[in]    IpConfig            Pointer to PWM top configuration structure
*
* @return       void
*
*
*/
void Pwm_Ipw_SetChannelDeadTime(uint16                           DeadTimeTicks,
                                const Pwm_IpwChannelConfigType * const IpConfig)
{
    /* Call FTM IP function */
    Ftm_Pwm_Ip_SetChannelDeadTime
    (
        IpConfig->ChannelInstanceId,
        ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId,
        DeadTimeTicks
    );
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*===============================================================================================*/
#if (PWM_ENABLE_TRIGGER_API == STD_ON)
/**
* @brief        This function enables trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*                   Bit 0   Channel 2 Trigger Enable
*                   Bit 1   Channel 3 Trigger Enable
*                   Bit 2   Channel 4 Trigger Enable
*                   Bit 3   Channel 5 Trigger Enable
*                   Bit 4   Channel 0 Trigger Enable
*                   Bit 5   Channel 1 Trigger Enable
*                   Bit 6   Initialization Trigger Enable
*
* @param[in]        TriggerHostId  FTM module ID
* @param[in]        TriggerMask    Bit mask will be clear for FTM_EXTTRIG.
* @param[in]        IpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*/
void Pwm_Ipw_EnableTrigger(uint8                             TriggerHostId,
                           uint16                            TriggerMask,
                           const Pwm_IpwInstanceConfigType * const IpConfig)
{

    if (TriggerHostId == IpConfig->InstanceId)
    {
        /* Call FTM IP function */
        Ftm_Pwm_Ip_EnableTrigger(TriggerHostId, (uint32)TriggerMask);
    }
    else
    {
        /* This parameter is not used */
        (void)TriggerHostId;
        (void)TriggerMask;
    }
}
#endif /* PWM_ENABLE_TRIGGER_API */

/*===============================================================================================*/
#if (PWM_DISABLE_TRIGGER_API == STD_ON)
/**
* @brief        This function disables trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*                   Bit 0   Channel 2 Trigger Enable
*                   Bit 1   Channel 3 Trigger Enable
*                   Bit 2   Channel 4 Trigger Enable
*                   Bit 3   Channel 5 Trigger Enable
*                   Bit 4   Channel 0 Trigger Enable
*                   Bit 5   Channel 1 Trigger Enable
*                   Bit 6   Initialization Trigger Enable
*
* @param[in]        TriggerHostId  FTM module ID
* @param[in]        TriggerMask    Bit mask will be clear for FTM_EXTTRIG.
* @param[in]        IpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*/
void Pwm_Ipw_DisableTrigger(uint8                             TriggerHostId,
                            uint16                            TriggerMask,
                            const Pwm_IpwInstanceConfigType * const IpConfig)
{
    if (TriggerHostId == IpConfig->InstanceId)
    {
        /* Call FTM IP function */
        Ftm_Pwm_Ip_DisableTrigger(TriggerHostId, (uint32)TriggerMask);
    }
    else
    {
        /* This parameter is not used */
        (void)TriggerHostId;
        (void)TriggerMask;
    }
}
#endif /* PWM_DISABLE_TRIGGER_API */

/*===============================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        Pwm_Ipw_ResetCounterEnable
* @details      This function enables counter reset by Pwm_SyncUpdate() call
*
* @param[in]    ModuleId       FTM module ID
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_ResetCounterEnable(uint8                             ModuleId,
                                const Pwm_IpwInstanceConfigType * const IpConfig)
{

    if (ModuleId == IpConfig->InstanceId)
    {
        /* Call FTM IP function */
        Ftm_Pwm_Ip_ResetCounter(ModuleId, TRUE);
    }
    else
    {
        /* This parameter is not used */
        (void)ModuleId;
    }
}
#endif /* PWM_RESET_COUNTER_API */

/*===============================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        Pwm_Ipw_ResetCounterDisable
* @details      This function disables counter reset by Pwm_SyncUpdate() call
*
* @param[in]    ModuleId      FTM module ID
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_ResetCounterDisable(uint8                             ModuleId,
                                 const Pwm_IpwInstanceConfigType * const IpConfig)
{


   if (ModuleId == IpConfig->InstanceId)
    {
        /* Call FTM IP function */
        Ftm_Pwm_Ip_ResetCounter(ModuleId, FALSE);
    }
    else
    {
        /* This parameter is not used */
        (void)ModuleId;
    }
}
#endif /* PWM_RESET_COUNTER_API */

/*===============================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
* @details      Corresponding bits with channel will be masked:
*                   Bit 0   Channel 0 Output Mask
*                   Bit 1   Channel 1 Output Mask
*                   Bit 2   Channel 2 Output Mask
*                   Bit 3   Channel 3 Output Mask
*                   Bit 4   Channel 4 Output Mask
*                   Bit 5   Channel 5 Output Mask
*
* @param[in]        ModuleId      FTM module ID
* @param[in]        ChannelMask   Bit mask will be set for FTM_OUTMASK.
* @param[in]        IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_MaskOutputs(uint8                             ModuleId,
                         uint8                             ChannelMask,
                         const Pwm_IpwInstanceConfigType * const IpConfig)
{

    if (ModuleId == IpConfig->InstanceId)
    {
         /* Call FTM IP function */
        Ftm_Pwm_Ip_MaskOutputChannels(ModuleId, ChannelMask, TRUE);
    }
    else
    {
        /* This parameter is not used */
        (void)ModuleId;
        (void)ChannelMask;
    }
}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

/*===============================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function puts channels output to normal operation state
* @details      Corresponding bits with channel will be masked:
*                   Bit 0   Channel 0 Output Mask
*                   Bit 1   Channel 1 Output Mask
*                   Bit 2   Channel 2 Output Mask
*                   Bit 3   Channel 3 Output Mask
*                   Bit 4   Channel 4 Output Mask
*                   Bit 5   Channel 5 Output Mask
*
* @param[in]        ModuleId      FTM module ID
* @param[in]        ChannelMask   Bit mask will be set for FTM_OUTMASK.
* @param[in]        IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_UnMaskOutputs(uint8                             ModuleId,
                           uint8                             ChannelMask,
                           const Pwm_IpwInstanceConfigType * const IpConfig)
{

    if (ModuleId == IpConfig->InstanceId)
    {
        /* Call FTM IP function */
        Ftm_Pwm_Ip_UnMaskOutputChannels(ModuleId, ChannelMask, TRUE);
    }
    else
    {
        /* This parameter is not used */
        (void)ModuleId;
        (void)ChannelMask;
    }
}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */


/*===============================================================================================*/
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Pwm_Ipw_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShift              Phase shift value (in ticks)
* @param[in]    IpConfig                Pointer to PWM top configuration structure
* @param[in]    SyncUpdate              Update the value immediately or not
*                                       TRUE   Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                                       FALSE  Set phase shift and duty cycle value immediately
*
* @return       void
*
*/
void Pwm_Ipw_SetDutyPhaseShift(uint16                           DutyCycle,
                               uint16                           PhaseShift,
                               const Pwm_IpwChannelConfigType * const IpConfig,
                               boolean                          SyncUpdate)
{

    uint16 FtmDutyCycle = (uint16)(((uint32)Ftm_Pwm_Ip_aPeriod[IpConfig->ChannelInstanceId] * DutyCycle) / 0x8000U);
    
    /* Call FTM IP function */
    Ftm_Pwm_Ip_SetDutyPhaseShift(IpConfig->ChannelInstanceId,
                               ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId,
                                FtmDutyCycle,
                                PhaseShift,
                                SyncUpdate);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
    /* Duty cycle of Ftm Ip */
    Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = DutyCycle;
#endif
}
#endif /* PWM_SET_DUTY_PHASE_SHIFT_API */

/*===============================================================================================*/
#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SetDutyCycle_NoUpdate
* @details      This function will call Ftm_Pwm_Ip_SetDutyCycle (synchronous mode) if
*               the given channel is a FTM channel
*
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
Std_ReturnType Pwm_Ipw_SetDutyCycle_NoUpdate(uint16                           DutyCycle,
                                             const Pwm_IpwChannelConfigType * const IpConfig)
{

    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    
    uint16 FtmDutyCycle = (uint16)(((uint32)Ftm_Pwm_Ip_aPeriod[IpConfig->ChannelInstanceId] * DutyCycle) / 0x8000U);
    /* Call FTM IP function */
    Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel
    (
        IpConfig->ChannelInstanceId,
        ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId,
        FtmDutyCycle,
        FALSE
    );
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
    /* Duty cycle of Ftm Ip */
    Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = DutyCycle;
#endif

    return RetVal;
}
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_DUTY_CYCLE_NO_UPDATE_API */

/*===============================================================================================*/
#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SetPeriodAndDuty_NoUpdate
* @details      This function will call Ftm_Pwm_Ip_SetPeriodAndDuty (synchronous mode)
*               if the given channel is a FTM channel
*
* @param[in]    Period         Period value for this channel
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPeriodAndDuty_NoUpdate(Pwm_PeriodType                   Period,
                                       uint16                           DutyCycle,
                                       const Pwm_IpwChannelConfigType * const IpConfig)
{

    uint16 FtmDutyCycle = (uint16)(((uint32)Period * DutyCycle) / 0x8000U);

    /* Call FTM IP function */
    Ftm_Pwm_Ip_UpdatePwmPeriodAndDuty
    (
        IpConfig->ChannelInstanceId,
        ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId,
        Period,
        FtmDutyCycle,
        FALSE
    );
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
    /* Duty cycle of Ftm Ip */
    Pwm_Ipw_aFtmDutyCycle[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId] = DutyCycle;
#endif
}
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */


/*===============================================================================================*/
#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SYNC_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SyncUpdate
* @details      This function will call Ftm_Pwm_Ip_SyncUpdate to allow synchronized loading
*               of the duty registers for all the channels of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_SyncUpdate(uint8  ModuleId)
{
    /* Call FTM IP function */
    Ftm_Pwm_Ip_SyncUpdate
    (
       ModuleId
    );
}
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SYNC_UPDATE_API */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_SetPowerState
* @details      This function will call SetPowerState function of all configured hardware FTM module
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
* @param[in]    PowerState     Target power mode
*
* @return       void
*
*/
void Pwm_Ipw_SetPowerState(const Pwm_IpwInstanceConfigType * const IpConfig,
                           Pwm_PowerStateType                PowerState)
{

#if (PWM_FTM_USED == STD_ON)
    Ftm_Pwm_Ip_PowerStateType   FtmPowerState = (PWM_FULL_POWER == PowerState)? FTM_PWM_IP_FULL_POWER : FTM_PWM_IP_LOW_POWER;
#endif
    switch(IpConfig->InstanceType)
    {
#if (PWM_FTM_USED == STD_ON)
        case PWM_INSTANCE_FTM:
            if (NULL_PTR != IpConfig->FtmInsConfig)
            {
                /* Call Ftm IP initialize instances */
                Ftm_Pwm_Ip_SetPowerState(IpConfig->InstanceId,
                                         FtmPowerState);
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateDeadTime
* @details      This function will check validate operation mode of current channel to use
*               deadtime feature.
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Current channel mode is invalid
*               E_OK            Current channel mode is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateDeadTime(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    
    const Ftm_Pwm_Ip_PairCfgType * FtmPairCfg = ((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->PairCfg;

    if (NULL_PTR == FtmPairCfg)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if ((TRUE == FtmPairCfg->DeadtimeEn) && (TRUE == FtmPairCfg->ComplementaryModeEn))
        {
            RetVal = (Std_ReturnType)E_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return RetVal;
}

/**
* @brief        Pwm_Ipw_ValidateParamDeadTime
* @details      This function will check validate input value of current channel to use
*               deadtime feature.
*
* @param[in]    DeadTimeTicks        The deadtime input value
* @param[in]    IpConfig             Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        DeadTimeTicks value is invalid
*               E_OK            DeadTimeTicks value is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateParamDeadTime(uint16                           DeadTimeTicks,
                                             const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

    if ((DeadTimeTicks < 1024U) && (DeadTimeTicks > 0U))
    {
        RetVal = (Std_ReturnType)E_OK;
    }

    /* Avoid the compiler warning */
    (void)IpConfig;

    return RetVal;
}
#endif /* ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)) */

/*=============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateForceOutputToZero
* @details      This function will check validate of force zero output feature
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @retval       Std_ReturnType
*               E_NOT_OK        Force zero output not support
*               E_OK            Force zero output is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateForceOutputToZero(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    (void)IpConfig;

    return RetVal;
}
#endif


/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateSetPhaseShift
* @details      This function will check given channel with phase shift supported
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Phase shift is not supported this channel
*               E_OK            Phase shift is supported this channel
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetPhaseShift(const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;

    Ftm_Pwm_Ip_ChannelModeType  ChannelMode = (Ftm_Pwm_Ip_ChannelModeType)(((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelMode);
    
    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          != ChannelMode) &&
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH != ChannelMode) &&
        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  != ChannelMode) &&
#endif
        ( FTM_PWM_IP_MODE_COMBINE_LOW           != ChannelMode))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}
#endif /* PWM_DEV_ERROR_DETECT && PWM_SET_DUTY_PHASE_SHIFT_API */


/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateSetDutyPhaseShiftParams
* @details      This function will check phase shift and duty cycle value
*
* @param[in]    PhaseShift   Phase shift value
* @param[in]    DutyCycle    Duty Cycle value
*
* @return       Std_ReturnType  
*               E_NOT_OK    Phase shift or duty cycle value is invalid
*               E_OK        Phase shift or duty cycle is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetDutyPhaseShiftParams(uint16                           PhaseShift,
                                                       uint16                           DutyCycle,
                                                       const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;

    if ((FTM_PWM_IP_MAX_DUTY_CYCLE != DutyCycle) && (0U != DutyCycle))
    {
        if (Ftm_Pwm_Ip_aPeriod[IpConfig->ChannelInstanceId] <= PhaseShift)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return RetVal;
}
#endif /* PWM_DEV_ERROR_DETECT == STD_ON && PWM_SET_DUTY_PHASE_SHIFT_API */

/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SYNC_UPDATE_API == STD_ON)))
/**
* @brief        Pwm_Ipw_ValidateUpdateSynchronous
* @details      This function will check given channel with synchronization supported
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK   synchronization is not supported this channel
*               E_OK       synchronization is supported this channel
*
*/
Std_ReturnType Pwm_Ipw_ValidateUpdateSynchronous(const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;
    (void)IpConfig;

    return RetVal;
}
#endif /* PWM_DEV_ERROR_DETECT && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API) */

/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_ENABLE_TRIGGER_API == STD_ON) || (PWM_DISABLE_TRIGGER_API == STD_ON)))
/**
* @brief        This function will check bit mask.
* @details      Bit mask will be process at lower layer has to be compatible with hardware register
*
* @param[in]    TriggerMask    Trigger mask value
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK  Bit mask is not compatible.
*               E_OK      Bit mask is compatible.
*/
Std_ReturnType Pwm_Ipw_ValidateTriggerMask(uint32                           TriggerMask,
                                           const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
 
    if ((uint32)0U != (
                        TriggerMask &
                        (~(uint32)((uint32)FTM_EXTTRIG_CH0TRIG_MASK |
                               (uint32)FTM_EXTTRIG_CH1TRIG_MASK |
                               (uint32)FTM_EXTTRIG_CH2TRIG_MASK |
                               (uint32)FTM_EXTTRIG_CH3TRIG_MASK |
                               (uint32)FTM_EXTTRIG_CH4TRIG_MASK |
                               (uint32)FTM_EXTTRIG_CH5TRIG_MASK |
                               (uint32)FTM_EXTTRIG_INITTRIGEN_MASK))
                       )
       )

    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* This parameter is not used */
    (void)IpConfig;

    return RetVal;
}
#endif /* PWM_DEV_ERROR_DETECT && (PWM_ENABLE_TRIGGER_API || PWM_DISABLE_TRIGGER_API) */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_ValidateIdleState
* @details      This function will call ValidateIdleState function of all configured hardware FTM module
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        The Idle state is not ready
*               E_OK            The Idle state is ready
*
*/
Std_ReturnType Pwm_Ipw_ValidateIdleState(const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;

    if (FTM_PWM_IP_CHANNEL_RUNNING == Ftm_Pwm_Ip_aChannelState[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId])
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if (FTM_PWM_IP_NO_EDGE != Ftm_Pwm_Ip_aNotifIrq[IpConfig->ChannelInstanceId][((const Ftm_Pwm_Ip_ChannelConfigType *)IpConfig->FtmChConfig)->ChannelId])
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif
    return RetVal;
}
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #if ((PWM_SYNC_UPDATE_API            == STD_ON) || \
         (PWM_ENABLE_TRIGGER_API         == STD_ON) || \
         (PWM_DISABLE_TRIGGER_API        == STD_ON) || \
         (PWM_RESET_COUNTER_API          == STD_ON) || \
         (PWM_ENABLE_MASKING_OPERATIONS  == STD_ON) || \
         (PWM_RELOAD_NOTIF_SUPPORTED     == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateModuleId
* @details      Validate the module id.
*               In order to be valid, the module id should less than number of module that supported
*
* @param[in]    ModuleId        The Id of the ipv module
*
* @return       Std_ReturnType
*               E_NOT_OK        The ModuleId is invalid
*               E_OK            The ModuleId is valid
*
*/     
Std_ReturnType  Pwm_Ipw_ValidateModuleId(uint8 ModuleId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType      RetVal = (Std_ReturnType)E_OK;
   
    if(PWM_HW_MODULE_FTM_NO <= ModuleId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }

    return RetVal;
}
    #endif
#endif


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
