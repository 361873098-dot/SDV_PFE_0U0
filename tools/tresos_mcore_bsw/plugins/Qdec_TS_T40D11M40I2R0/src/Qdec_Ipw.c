/*==================================================================================================
*     Project             : RTD AUTOSAR 4.4
*     Platform            : CORTEXM
*     Peripheral          : Ftm
*     Dependencies        : none
*
*     Autosar Version     : 4.4.0
*     Autosar Revision    : ASR_REL_4_4_REV_0000
*     Autosar ConfVariant
*     SWVersion           : 4.0.2
*     BuildVersion        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
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
*     @file       Qdec_Ipw.c
*
*     @internal
*     @addtogroup qdec_ipw Qdec_Ipw Driver
*     @{
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

#include "Qdec_Ipw.h"
#include "Ftm_Qdec_Ip.h"

/*==================================================================================================
*                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define QDEC_IPW_VENDOR_ID_C                     43
#define QDEC_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define QDEC_IPW_AR_RELEASE_MINOR_VERSION_C      4
#define QDEC_IPW_AR_RELEASE_REVISION_VERSION_C   0
#define QDEC_IPW_SW_MAJOR_VERSION_C              4
#define QDEC_IPW_SW_MINOR_VERSION_C              0
#define QDEC_IPW_SW_PATCH_VERSION_C              2

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Qdec_Ipw header file are of the same vendor */
#if (QDEC_IPW_VENDOR_ID_C != QDEC_IPW_VENDOR_ID)
#error "Qdec_Ipw.c and Qdec_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Qdec_Ipw header file are of the same Autosar version */
#if ((QDEC_IPW_AR_RELEASE_MAJOR_VERSION_C != QDEC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_MINOR_VERSION_C != QDEC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_REVISION_VERSION_C != QDEC_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw.c and Qdec_Ipw.h are different"
#endif
/* Check if source file and Qdec_Ipw header file are of the same Software Version */
#if ((QDEC_IPW_SW_MAJOR_VERSION_C != QDEC_IPW_SW_MAJOR_VERSION) || \
     (QDEC_IPW_SW_MINOR_VERSION_C != QDEC_IPW_SW_MINOR_VERSION) || \
     (QDEC_IPW_SW_PATCH_VERSION_C != QDEC_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw.c and Qdec_Ipw.h are different"
#endif

/* Check if source file and Ftm_Qdec_Ip header file are of the same vendor */
#if (QDEC_IPW_VENDOR_ID_C != FTM_QDEC_IP_VENDOR_ID)
#error "Qdec_Ipw.c and Ftm_Qdec_Ip.h have different vendor IDs"
#endif
/* Check if source file and Ftm_Qdec_Ip header file are of the same Autosar version */
#if ((QDEC_IPW_AR_RELEASE_MAJOR_VERSION_C != FTM_QDEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_MINOR_VERSION_C != FTM_QDEC_IP_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_REVISION_VERSION_C != FTM_QDEC_IP_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw.c and Ftm_Qdec_Ip.h are different"
#endif
/* Check if source file and Ftm_Qdec_Ip header file are of the same Software Version */
#if ((QDEC_IPW_SW_MAJOR_VERSION_C != FTM_QDEC_IP_SW_MAJOR_VERSION) || \
     (QDEC_IPW_SW_MINOR_VERSION_C != FTM_QDEC_IP_SW_MINOR_VERSION) || \
     (QDEC_IPW_SW_PATCH_VERSION_C != FTM_QDEC_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw.c and Ftm_Qdec_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#define QDEC_START_SEC_CODE
#include "Qdec_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief Configures the quadrature mode and starts measurement.
*
* @param [in] count     Number Qdec Instance.
* @param [in] Config    Configuration structure(Quadrature Decoder Mode, polarity for both phases,
*                       minimum and maximum value for the counter, filter configuration).
* @return None.
*/
void Qdec_Ipw_Init(uint8 count, const Qdec_Ipw_ConfigType *Config)
{
    uint8 index;
    for(index = 0; index < count; index++)
    {
        Ftm_Qdec_Ip_Init((Config -> Logic2HwMap[index]).IpInstance, &(Config->Ftm_Qdec_Ip_ConfigInstance[index]));
    }

}

/*================================================================================================*/
/**
* @brief Disable the Quadrature Decoder Mode.
*
* @param [in] count     Number Qdec Instance.
* @param [in] Config    Configuration structure(Quadrature Decoder Mode, polarity for both phases,
*                       minimum and maximum value for the counter, filter configuration).
* @return None.
*/
void Qdec_Ipw_DeInit(uint8 count, const Qdec_Ipw_ConfigType *Config)
{
    uint8 index;
    for(index = 0; index < count; index++)
    {
        Ftm_Qdec_Ip_Deinit((Config -> Logic2HwMap[index]).IpInstance);
    }
}

/*================================================================================================*/
/**
* @brief Get the current quadrature decoder state (counter value and flags).
*
* @param [in] module Qdec hardware instance used;
* @param [in] Config The current quadrature configuration used.
* @return Pointer to the current state of module.
*/
Qdec_Ipw_State Qdec_Ipw_GetState(uint8 module, const Qdec_Ipw_ConfigType *Config)
{
    Ftm_Qdec_Ip_StateType FtmState = Ftm_Qdec_Ip_GetState(Config->Logic2HwMap[module].IpInstance);
    Qdec_Ipw_State IpwState;

    IpwState.Counter = FtmState.mCounter;
    IpwState.TimerOverflow = FtmState.mTimerOverflow;
    IpwState.TimerOverflowDir = FtmState.mTimerOverflowDir;
    IpwState.CountDir = FtmState.mCountDir;
    return IpwState;
}

/*================================================================================================*/
#if (QDEC_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Qdec_Ipw_SetClockMode
* @details      This function will call SetClockMode function of all configured hardware eMIOS modules.
*
* @param[in]    prescaler      Pre-scaler type
* @param[in]    ipConfig       Pointer to QDEC top configuration structure
* @return       void
*
*/
void Qdec_Ipw_SetClockMode(const Qdec_Ipw_ConfigType *Config, uint8 moduleId, Qdec_SelectPrescalerType prescaler)
{
    uint8 FtmPrescaler;

    if(QDEC_ALTERNATIVE_PRESCALER == prescaler)
    {
        FtmPrescaler = (Config->Ftm_Qdec_Ip_ConfigInstance->AlternateCtrVal & QDEC_FTM_ALT_CLOCK_DIV_MASK_U8) >> QDEC_FTM_ALT_CLOCK_DIV_SHIFT;
    }
    else
    {
        FtmPrescaler = (Config->Ftm_Qdec_Ip_ConfigInstance->ModuleControlValue & QDEC_FTM_CLOCK_DIV_MASK_U8) >> QDEC_FTM_CLOCK_DIV_SHIFT;
    }

    /* Call FTM IP function */
    Ftm_Qdec_Ip_SetClockMode(moduleId, FtmPrescaler);

}
#endif /* QDEC_SET_CLOCK_MODE_API */

/*================================================================================================*/
/**
* @brief Set the state of counter
*
* @param [in] module Qdec instance ID used;
* @param [in] Config The current quadrature configuration used.
* @return void.
*/
void Qdec_Ipw_CounterState(const uint8 module, const Qdec_Ipw_ConfigType *Config)
{
    Ftm_Qdec_Ip_CounterState(Config->Logic2HwMap[module].IpInstance);
}

/*================================================================================================*/
/**
* @brief Reset to default current state of the QDEC module
*
* @param [in] module Qdec instance ID used.
* @param [in] Config The current quadrature configuration used.
* @return void.
*/
void Qdec_Ipw_ResetState(const uint8 module, const Qdec_Ipw_ConfigType *Config)
{
    Ftm_Qdec_Ip_ResetState(Config->Logic2HwMap[module].IpInstance);
}

/*================================================================================================*/
#if (QDEC_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Qdec_Ipw_DisableOverFlowNotification
*
* @param [in] module        Qdec instance ID used.
* @param [in] Config        The current quadrature configuration used.
* @return       void
*
*/
void Qdec_Ipw_DisableOverFlowNotification(const uint8 module, const Qdec_Ipw_ConfigType *Config)
{
    Ftm_Qdec_Ip_DisableOverFlowNotification(Config->Logic2HwMap[module].IpInstance);
}

/*================================================================================================*/
/**
* @brief        Qdec_Ipw_EnableOverFlowNotification
*
* @param [in] module        Qdec instance ID used.
* @param [in] Config        The current quadrature configuration used.
* @return       void
*
*/
void Qdec_Ipw_EnableOverFlowNotification(const uint8 module, const Qdec_Ipw_ConfigType *Config)
{

    Ftm_Qdec_Ip_EnableOverFlowNotification(Config->Logic2HwMap[module].IpInstance);
}
#endif

/*================================================================================================*/
/**
* @brief Set mode of Qdec module
*
* @param [in] module Qdec instance ID used.
* @param [in] Config The current quadrature configuration used.
* @param [in] mode The given mode
* @return void.
*/
void Qdec_Ipw_SetMode(const uint8 module, const Qdec_Ipw_ConfigType *Config, Qdec_ModeType mode)
{
    Ftm_ModeType ftmMode;

    if (mode == QDEC_MODE_NORMAL)
    {
        ftmMode = FTM_QDEC_MODE_NORMAL;
    }
    else
    {
        ftmMode = FTM_QDEC_MODE_SLEEP;
    }
    Ftm_Qdec_Ip_SetMode(Config->Logic2HwMap[module].IpInstance, ftmMode);
}

#define QDEC_STOP_SEC_CODE
#include "Qdec_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
