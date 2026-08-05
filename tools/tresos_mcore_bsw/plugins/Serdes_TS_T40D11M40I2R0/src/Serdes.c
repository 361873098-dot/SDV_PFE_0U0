/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
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
*   @file    Serdes.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Serdes - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup SERDES_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Serdes.h"

#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#include "SchM_Serdes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_VENDOR_ID_C                      43
#define SERDES_AR_RELEASE_MAJOR_VERSION_C       4
#define SERDES_AR_RELEASE_MINOR_VERSION_C       4
#define SERDES_AR_RELEASE_REVISION_VERSION_C    0
#define SERDES_SW_MAJOR_VERSION_C               4
#define SERDES_SW_MINOR_VERSION_C               0
#define SERDES_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes.h file are of the same vendor */
#if (SERDES_VENDOR_ID_C != SERDES_VENDOR_ID)
    #error "Serdes.c and Serdes.h have different vendor ids"
#endif
/* Check if current file and Serdes.h file are of the same Autosar version */
#if ((SERDES_AR_RELEASE_MAJOR_VERSION_C    != SERDES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_AR_RELEASE_MINOR_VERSION_C    != SERDES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_AR_RELEASE_REVISION_VERSION_C != SERDES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes.c and Serdes.h are different"
#endif
/* Check if current file and Serdes.h file are of the same Software version */
#if ((SERDES_SW_MAJOR_VERSION_C != SERDES_SW_MAJOR_VERSION) || \
     (SERDES_SW_MINOR_VERSION_C != SERDES_SW_MINOR_VERSION) || \
     (SERDES_SW_PATCH_VERSION_C != SERDES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes.c and Serdes.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (SERDES_DEV_ERROR_DETECT == STD_ON)
        #if ((SERDES_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (SERDES_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Serdes.c and Det.h are different"
        #endif
    #endif
    /* Checks against SchM_Serdes.h */
    #if ((SERDES_AR_RELEASE_MAJOR_VERSION_C != SCHM_SERDES_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_AR_RELEASE_MINOR_VERSION_C != SCHM_SERDES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Serdes.c and SchM_Serdes.h are different"
    #endif
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define SERDES_START_SEC_VAR_INIT_8
#include "Serdes_MemMap.h"

/**
* @brief          Serdes driver status variable.
* @details        Serdes driver state machine.
*/
static Serdes_StatusType Serdes_DriverStatus = SERDES_UNINIT;

#define SERDES_STOP_SEC_VAR_INIT_8
#include "Serdes_MemMap.h"


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define SERDES_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"
/**
* @brief   Export Pre-Compile configurations.
*/
extern const Serdes_ConfigType Serdes_PBCfgVariantPredefined[];

#define SERDES_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define SERDES_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Serdes_MemMap.h"
/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
static const Serdes_ConfigType * Serdes_Config;

#define SERDES_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Serdes_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief        This function checks the multi-channel initialization process.
* @details      This function checks the multi-channel initialization process.
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           Channel successed to initialize
* @retval       E_NOT_OK:       Channel failed to initialize
*/
Std_ReturnType Serdes_InitMultiChannels(void);

/**
* @brief        This function check CoreId is used.
* @details      This function check CoreId is used.
*
* @param[in]      CfgPtr           Configuration data pointer.
* @param[in]      CoreId           Current CoreID
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           CoreId is valid
* @retval       E_NOT_OK:       CoreId is not valid
*/
static inline Std_ReturnType Serdes_CheckCurrentCoreId(const Serdes_ConfigType * CfgPtr,
                                                       uint32 CoreId
                                                      )
{
    Std_ReturnType ValidCoreId = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR != CfgPtr)
    {
        if ((CoreId == CfgPtr->CoreId) && (NULL_PTR != (*CfgPtr->Serdes_HwConfig)))
        {
            ValidCoreId = (Std_ReturnType)E_OK;
        }
#if (SERDES_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_INIT_ID, (uint8)SERDES_E_PARAM_CONFIG);
        }
    }
    else
    {
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_INIT_ID, (uint8)SERDES_E_PARAM_CONFIG);
#endif
    }

    return ValidCoreId;
}
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

Std_ReturnType Serdes_InitMultiChannels(void)
{
    uint8 ChLoop;
    Std_ReturnType StatusInit = (Std_ReturnType)E_NOT_OK;

    for (ChLoop = (uint8)0U; ChLoop < SERDES_HW_MAX_CONFIG; ChLoop++)
    {
        if (NULL_PTR != ((*Serdes_Config->Serdes_HwConfig)[ChLoop].HwChannelConfig))
        {
            /* Initialization channel */
            StatusInit = Serdes_Ipw_InitChannel((*Serdes_Config->Serdes_HwConfig)[ChLoop].Serdes_HwUnit, (*Serdes_Config->Serdes_HwConfig)[ChLoop].HwChannelConfig);
            if ((Std_ReturnType)E_NOT_OK == StatusInit)
            {
                /* Channel failed to initialize. Stop init. */
                break;
            }
        }
    }

    return StatusInit;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/**
* @brief          Starts initialization of serdes module.
* @details        Initialization is done asynchronous and will not be completed after calling this
*                 function. Serdes_MainFunction() should be called multiple times until initialization
*                 is completed.
* @param[in]      Config      Serdes configuration structure.
*
* @return         void
*/
/* implements Serdes_Init_Activity */
void Serdes_Init(const Serdes_ConfigType * Config)
{
    uint32 CoreId;
    Std_ReturnType ValidCoreId;
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;

    CoreId = (uint32)Serdes_GetCoreID();
#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Serdes driver is in SERDES_UNINIT state */
    if (SERDES_INIT_IN_PROGRESS == Serdes_DriverStatus)
    {
        /* SERDES driver has been already initialized */
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_INIT_ID, (uint8)SERDES_E_INIT_IN_PROGRESS);
    }
    else if (NULL_PTR != Config)
    {
        /* Invalid pointer */
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_INIT_ID, (uint8)SERDES_E_INVALID_POINTER);
    }
    else
    {
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */
        ValidCoreId = Serdes_CheckCurrentCoreId(&Serdes_PBCfgVariantPredefined[CoreId], CoreId);

        if ((Std_ReturnType)E_OK == ValidCoreId)
        {
            Serdes_Config = &Serdes_PBCfgVariantPredefined[CoreId];
            (void)Config;
            /* Initialization for multiple channels of serdes module*/
            Status = Serdes_InitMultiChannels();
        }
#if (SERDES_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_INIT_ID, (uint8)SERDES_E_PARAM_CONFIG);
        }
    }
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */
    Serdes_DriverStatus = ((Std_ReturnType)E_OK == Status) ? SERDES_INIT_IN_PROGRESS : SERDES_UNINIT;
}

/**
* @brief          Continues initialization of serdes module.
* @details        This function should be called multiple times until initialization
*                 os Serdes module is completed.
*
* @param[in]      Config      Serdes configuration structure.
*
* @return         void
*/
/* implements Serdes_MainFunction_Activity */
void Serdes_MainFunction(void)
{
    uint8 ChLoop;
    uint8 CountInitedChannel = 0U;
    Serdes_StatusType MainFuctionStatus;

    /* Check whether the Serdes driver is in SERDES_INIT_IN_PROGRESS state */
    /* CPR_RTD_00662: If a Scheduled functions (Main processing functions) of un-initialized BSW Module is called from
    the BSW Scheduler, then it shall return immediately without performing any functionality and without raising any errors. */
    if (SERDES_INIT_IN_PROGRESS == Serdes_DriverStatus)
    {
        for (ChLoop=(uint8)0U; ChLoop < SERDES_HW_MAX_CONFIG; ChLoop++)
        {
            if (0xFFU != ((*Serdes_Config->Serdes_HwConfig)[ChLoop].Serdes_HwUnit))
            {
                /* Continue initialization of Serdes driver */
                MainFuctionStatus = Serdes_Ipw_MainFunction((*Serdes_Config->Serdes_HwConfig)[ChLoop].Serdes_HwUnit);
                /* CDD_SERDES_00006: If the module initialization (started in the function Serdes_Init) is completed in the module’s
                main function, the function Serdes_MainFunction shall set the module status from SERDES_INIT_IN_PROGRESS to SERDES_SUCCESS
                once initialization of the module has been successfully finished. */
                if (SERDES_SUCCESS == MainFuctionStatus)
                {
                    CountInitedChannel++;
                }
            }
        }
        /* Check that all instances that are configured were initialized. */
        if (SERDES_HW_MAX_CONFIG == CountInitedChannel)
        {
            Serdes_DriverStatus = SERDES_SUCCESS;
        }
    }
}

/**
* @brief          Returns job result.
* @details        This function returns the initialization job result. In case the initialization is
*                 completed it will return SERDES_INIT_OK, otherwise it will return SERDES_INIT_PENDING
*                 if initialization is still in progress or SERDES_INIT_FAILED if initialization failed to
*                 complete.
*
* @return         void
*/
/* implements Serdes_GetJobResult_Activity */
Serdes_JobResultType Serdes_GetJobResult(void)
{
    uint8 ChLoop;
    uint8 JobResultHw = 0U;
    Serdes_JobResultType JobResult = SERDES_INIT_FAILED;
    Serdes_JobResultType Serdes_JobResult;

#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Serdes driver has been initialized */
    if (SERDES_UNINIT == Serdes_DriverStatus)
    {
        /* SERDES driver has not started the initialization */
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_GETJOBRESULT_ID, (uint8)SERDES_E_UNINIT);
    }
    else
    {
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */

        for (ChLoop = (uint8)0U; ChLoop < SERDES_HW_MAX_CONFIG; ChLoop++)
        {
            if (0xFFU != ((*Serdes_Config->Serdes_HwConfig)[ChLoop].Serdes_HwUnit))
            {
                /* Continue initialization of Serdes driver */
                Serdes_JobResult =  Serdes_Ipw_GetJobResult((*Serdes_Config->Serdes_HwConfig)[ChLoop].Serdes_HwUnit);
                JobResultHw |= (uint8) Serdes_JobResult;
            }
        }

        /* Check driver job result */
        if (JobResultHw == (uint8)SERDES_INIT_OK)
        {
            JobResult = SERDES_INIT_OK;
        }
        else if ((JobResultHw == (uint8)SERDES_INIT_PENDING) || (JobResultHw == (uint8)((uint8)SERDES_INIT_PENDING | (uint8)SERDES_INIT_OK)))
        {
            JobResult = SERDES_INIT_PENDING;
        }
        else
        {
            JobResult = SERDES_INIT_FAILED;
        }
#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */

    return JobResult;
}

/**
* @brief          Returns driver status.
* @details
*
* @return         void
*/
/* implements Serdes_GetStatus_Activity */
Serdes_StatusType Serdes_GetStatus(uint8 Channel)
{
    Serdes_StatusType ChannelStatus;

#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    /* SERDES driver has not started the initialization */
    if (SERDES_UNINIT == Serdes_DriverStatus)
    {
        /* SERDES driver has not started initialization */
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_GETSTATUS_ID, (uint8)SERDES_E_UNINIT);
        ChannelStatus = SERDES_ERROR;
    }
    else if (Channel >= SERDES_HW_MAX_CONFIG)
    {
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_GETSTATUS_ID, (uint8)SERDES_E_INVALID_PARAMETER);
        ChannelStatus = SERDES_ERROR;
    }
    else
    {
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */

    ChannelStatus = Serdes_Ipw_GetStatus((*Serdes_Config->Serdes_HwConfig)[Channel].Serdes_HwUnit);

#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */

    return ChannelStatus;
}

#ifdef SERDES_SET_MODE_API
#if (STD_ON == SERDES_SET_MODE_API)
/**
* @brief          Sets the power mode for the selected channel.
* @details
*
* @return         void
*/
/* implements Serdes_SetMode_Activity */
void Serdes_SetMode(uint8 Channel, Serdes_ModeType Mode)
{
#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Serdes driver is in SERDES_UNINIT state */
    if (SERDES_UNINIT == Serdes_DriverStatus)
    {
        /* SERDES driver has not started the initialization */
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_SETMODE_ID, (uint8)SERDES_E_UNINIT);
    }
    else if (Channel >= SERDES_HW_MAX_CONFIG)
    {
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_SETMODE_ID, (uint8)SERDES_E_INVALID_PARAMETER);
    }
    else
    {
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */
        Serdes_Ipw_SetMode(Channel, Mode);
#if (SERDES_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (SERDES_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (STD_ON == SERDES_SET_MODE_API) */
#endif /* SERDES_SET_MODE_API */

#if (SERDES_VERSION_INFO_API == STD_ON)

/**
* @brief          Gets the version information of this module.
* @details
*
* @return         void
*/
/* implements Serdes_GetVersionInfo_Activity */
void Serdes_GetVersionInfo (Std_VersionInfoType * VersionInfo)
{
#if ( SERDES_DEV_ERROR_DETECT == STD_ON )
    if ( NULL_PTR == VersionInfo )
    {
        (void)Det_ReportError((uint16)SERDES_MODULE_ID, (uint8)0, (uint8)SERDES_GETVERSIONINFO_ID, (uint8) SERDES_E_INVALID_POINTER);
    }
    else
    {
#endif /* SERDES_DEV_ERROR_DETECT == STD_ON */
        (VersionInfo)->vendorID = (uint16) SERDES_VENDOR_ID;
        (VersionInfo)->moduleID = (uint16) SERDES_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8) SERDES_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8) SERDES_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8) SERDES_SW_PATCH_VERSION;
#if ( SERDES_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* SERDES_DEV_ERROR_DETECT == STD_ON */
}
#endif /* SERDES_VERSION_INFO_API == STD_ON */

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
