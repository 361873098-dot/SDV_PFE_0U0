/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
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
*   @file Lin_ASRExt.c
*
*   @internal 
*   @addtogroup LIN_IPW
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin.h"
#include "Lin_ASRExt.h"
#include "Linflexd_Lin_Ip_Autosar.h"

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_ASREXT_VENDOR_ID_C                    43
#define LIN_ASREXT_AR_RELEASE_MAJOR_VERSION_C     4
#define LIN_ASREXT_AR_RELEASE_MINOR_VERSION_C     4
#define LIN_ASREXT_AR_RELEASE_REVISION_VERSION_C  0
#define LIN_ASREXT_SW_MAJOR_VERSION_C             4
#define LIN_ASREXT_SW_MINOR_VERSION_C             0
#define LIN_ASREXT_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor id */
#if (LIN_ASREXT_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin_ASRExt.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_ASREXT_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_ASREXT_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_ASREXT_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_ASRExt.c and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_ASREXT_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_ASREXT_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION) || \
     (LIN_ASREXT_SW_PATCH_VERSION_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_ASRExt.c and Lin.h are different"
#endif

/* Check if current file and Lin_ASRExt header file are of the same vendor id */
#if (LIN_ASREXT_VENDOR_ID_C != LIN_ASREXT_VENDOR_ID)
    #error "Lin_ASRExt.c and Lin_ASRExt.h have different vendor ids"
#endif
/* Check if current file and Lin_ASRExt header file are of the same Autosar version */
#if ((LIN_ASREXT_AR_RELEASE_MAJOR_VERSION_C    != LIN_ASREXT_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_ASREXT_AR_RELEASE_MINOR_VERSION_C    != LIN_ASREXT_AR_RELEASE_MINOR_VERSION) || \
     (LIN_ASREXT_AR_RELEASE_REVISION_VERSION_C != LIN_ASREXT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_ASRExt.c and Lin_ASRExt.h are different"
#endif
/* Check if current file and Lin_ASRExt header file are of the same Software version */
#if ((LIN_ASREXT_SW_MAJOR_VERSION_C != LIN_ASREXT_SW_MAJOR_VERSION) || \
     (LIN_ASREXT_SW_MINOR_VERSION_C != LIN_ASREXT_SW_MINOR_VERSION) || \
     (LIN_ASREXT_SW_PATCH_VERSION_C != LIN_ASREXT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_ASRExt.c and Lin_ASRExt.h are different"
#endif

#if (LIN_ASREXT_VENDOR_ID_C != LINFLEXD_LIN_IP_AUTOSAR_VENDOR_ID)
    #error "Lin_ASRExt.c and Linflexd_Lin_Ip_Autosar.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Autosar header file are of the same Autosar version */
#if ((LIN_ASREXT_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_ASREXT_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION) || \
     (LIN_ASREXT_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_ASRExt.c and Linflexd_Lin_Ip_Autosar.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Autosar header file are of the same Software version */
#if ((LIN_ASREXT_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_MAJOR_VERSION) || \
     (LIN_ASREXT_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_MINOR_VERSION) || \
     (LIN_ASREXT_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_ASRExt.c and Linflexd_Lin_Ip_Autosar.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */ 
        #if ((LIN_ASREXT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_ASREXT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lin_ASRExt.c and Det.h are different"
        #endif
    #endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_VAR_INIT_8
#include "Lin_MemMap.h"

extern uint8 Lin_au8LinDrvStatus[LIN_MAX_PARTITIONS];

#define LIN_STOP_SEC_VAR_INIT_8
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

extern const Lin_ChannelConfigType *Lin_apChannelConfigPtr[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == LIN_DUAL_CLOCK_MODE)

/**
* @brief          Lin_SetClockMode.
* @details        Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*
* @param[in]      ClockMode   New clock mode.
*
* @return                     The result of the switching clock operation.
* @retval E_OK                The switching operation was OK.
* @retval E_NOT_OK            The switching operation has failed caused by the
*                             wrong driver state.
*
* @api            Switch the clock mode to the alternate clock mode on all
*                 the Lin channels.
*
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @note           Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*/
/**
* @implements     Lin_SetClockMode_Activity
*/
Std_ReturnType Lin_SetClockMode(Lin_ClockModesType ClockMode)
{
    Std_ReturnType TempReturn = (uint8)E_OK;
    uint8 ChLoop;
    uint8 LinFlex;
    uint32 CoreId;
    
    CoreId = (uint32)Lin_GetCoreID();

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_au8LinDrvStatus[CoreId])
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_SETCLOCKMODE_ID, \
                              (uint8)LIN_E_UNINIT \
                             );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        for (ChLoop=(uint8)0U; ChLoop < LIN_HW_MAX_MODULES; ChLoop++)
        {
            if (Lin_apChannelConfigPtr[ChLoop] != NULL_PTR)
            {
                if ((TRUE == Lin_apChannelConfigPtr[ChLoop]->AllocatedPartition) &&
                    (CoreId == Lin_apChannelConfigPtr[ChLoop]->ChannelCoreId)
                   )
                {
                    /* Get the hardware Lin channel from logical channel */
                    LinFlex = Lin_apChannelConfigPtr[ChLoop]->ChannelConfigPtr->LinHwChannel;
            
                    /* Set the Baudrate */
                    if (ClockMode == LIN_NORMAL)
                    {
                        /* Configure baudrate */
                        Linflexd_Lin_Ip_SetBaudrate(LinFlex, Lin_apChannelConfigPtr[ChLoop]->ChannelConfigPtr->LinFlexdConfig->BaudrateRegValue);
                    }
                    else
                    {
                        /* Configure baudrate */
                        Linflexd_Lin_Ip_SetBaudrate(LinFlex, Lin_apChannelConfigPtr[ChLoop]->ChannelConfigPtr->BaudrateRegValueAlternate);
                    }
                }
            }
        }
    }

    return TempReturn;
}

#endif /* STD_ON == LIN_DUAL_CLOCK_MODE */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
