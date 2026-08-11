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

==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Serdes_Ipw.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#include "Serdes_Ipw.h"
#include "Serdes_Types.h"
#include "Serdes_Ip.h"
#include "Serdes_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Serdes_Ipw.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define SERDES_IPW_VENDOR_ID_C                      43
#define SERDES_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define SERDES_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define SERDES_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define SERDES_IPW_SW_MAJOR_VERSION_C               4
#define SERDES_IPW_SW_MINOR_VERSION_C               0
#define SERDES_IPW_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ipw.h file are of the same vendor */
#if (SERDES_IPW_VENDOR_ID_C != SERDES_IPW_VENDOR_ID)
    #error "Serdes_Ipw.c and Serdes_Ipw.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw.h file are of the same Autosar version */
#if ((SERDES_IPW_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IPW_AR_RELEASE_MINOR_VERSION_C    != SERDES_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IPW_AR_RELEASE_REVISION_VERSION_C != SERDES_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw.c and Serdes_Ipw.h are different"
#endif
/* Check if current file and Serdes_Ipw.h file are of the same Software version */
#if ((SERDES_IPW_SW_MAJOR_VERSION_C != SERDES_IPW_SW_MAJOR_VERSION) || \
     (SERDES_IPW_SW_MINOR_VERSION_C != SERDES_IPW_SW_MINOR_VERSION) || \
     (SERDES_IPW_SW_PATCH_VERSION_C != SERDES_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ipw.c and Serdes_Ipw.h are different"
#endif

/* Check if current file and Serdes_Types.h file are of the same vendor */
#if (SERDES_IPW_VENDOR_ID_C != SERDES_TYPES_VENDOR_ID)
    #error "Serdes_Ipw.c and Serdes_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Types.h file are of the same Autosar version */
#if ((SERDES_IPW_AR_RELEASE_MAJOR_VERSION_C    != SERDES_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IPW_AR_RELEASE_MINOR_VERSION_C    != SERDES_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IPW_AR_RELEASE_REVISION_VERSION_C != SERDES_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw.c and Serdes_Types.h are different"
#endif
/* Check if current file and Serdes_Types.h file are of the same Software version */
#if ((SERDES_IPW_SW_MAJOR_VERSION_C != SERDES_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_IPW_SW_MINOR_VERSION_C != SERDES_TYPES_SW_MINOR_VERSION) || \
     (SERDES_IPW_SW_PATCH_VERSION_C != SERDES_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ipw.c and Serdes_Types.h are different"
#endif

/* Check if current file and Serdes_Ip.h file are of the same vendor */
#if (SERDES_IPW_VENDOR_ID_C != SERDES_IP_VENDOR_ID)
    #error "Serdes_Ipw.c and Serdes_Ip.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Autosar version */
#if ((SERDES_IPW_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IPW_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IPW_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw.c and Serdes_Ip.h are different"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Software version */
#if ((SERDES_IPW_SW_MAJOR_VERSION_C != SERDES_IP_SW_MAJOR_VERSION) || \
     (SERDES_IPW_SW_MINOR_VERSION_C != SERDES_IP_SW_MINOR_VERSION) || \
     (SERDES_IPW_SW_PATCH_VERSION_C != SERDES_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ipw.c and Serdes_Ip.h are different"
#endif

/* Check if current file and Serdes_Cfg.h file are of the same vendor */
#if (SERDES_IPW_VENDOR_ID_C != SERDES_VENDOR_ID_CFG)
    #error "Serdes_Ipw.c and Serdes_Cfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Cfg.h file are of the same Autosar version */
#if ((SERDES_IPW_AR_RELEASE_MAJOR_VERSION_C    != SERDES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SERDES_IPW_AR_RELEASE_MINOR_VERSION_C    != SERDES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SERDES_IPW_AR_RELEASE_REVISION_VERSION_C != SERDES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw.c and Serdes_Cfg.h are different"
#endif
/* Check if current file and Serdes_Cfg.h file are of the same Software version */
#if ((SERDES_IPW_SW_MAJOR_VERSION_C != SERDES_SW_MAJOR_VERSION_CFG) || \
     (SERDES_IPW_SW_MINOR_VERSION_C != SERDES_SW_MINOR_VERSION_CFG) || \
     (SERDES_IPW_SW_PATCH_VERSION_C != SERDES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Serdes_Ipw.c and Serdes_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
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

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/**
* @brief          Starts initialization of serdes module.
* @details        Initialization is done asynchronous and will not be completed after calling this
                  function.
*
* @param[in]      Instance    Serdes hardware Instance.
* @param[in]      ConfigPtr   Hw configuration structure.
*
* @return         Returns E_OK if initialization was started successfully, else returns E_NOT_OK.
*/

Std_ReturnType Serdes_Ipw_InitChannel(const uint8 Instance,
                                      const Serdes_Ipw_HwChannelConfigType * ConfigPtr
                                     )
{
    Serdes_Ip_StatusType Status;
    Std_ReturnType StdStatus = E_NOT_OK;

    Status = Serdes_Ip_Init(Instance, ConfigPtr->SerdesHwConfig);

    if (SERDES_IP_SUCCESS == Status)
    {
        StdStatus = E_OK;
    }

    return StdStatus;
}

Serdes_StatusType Serdes_Ipw_MainFunction(uint8 Instance)
{
    Serdes_StatusType Status = SERDES_ERROR;

    if (SERDES_IP_JOB_PENDING == Serdes_Ip_GetJobResult(Instance))
    {
        if (SERDES_IP_SUCCESS == Serdes_Ip_MainFunction(Instance))
        {
            Status = SERDES_SUCCESS;
        }

#ifdef SERDES_JOB_FAILED_CALLBACK
        /* Check Job Result */
        if (SERDES_IP_JOB_FAILED == Serdes_Ip_GetJobResult(Instance))
        {
            /* Call job failed callback */
             SERDES_JOB_FAILED_CALLBACK(Instance);
        }
#endif /* SERDES_JOB_FAILED_CALLBACK */

#ifdef SERDES_JOB_DONE_CALLBACK
        if (SERDES_IP_JOB_DONE == Serdes_Ip_GetJobResult(Instance))
        {
            /* Call job done callback */
            SERDES_JOB_DONE_CALLBACK(Instance);
        }
#endif /* SERDES_JOB_DONE_CALLBACK */
    }

    return Status;
}

Serdes_StatusType Serdes_Ipw_GetStatus(uint8 Instance)
{
    Serdes_StatusType RetStatus = SERDES_ERROR;
    Serdes_Ip_StatusType Status;

    /* Get driver status */
    Status = Serdes_Ip_GetStatus(Instance);

    /* CDD_SERDES_00025: If the Serdes was completely and successfully initialized the Serdes_GetStatus() shall return SERDES_SUCCESS. */
    if (SERDES_IP_SUCCESS == Status)
    {
        RetStatus = SERDES_SUCCESS;
    }
    /* CDD_SERDES_00026: If the Serdes initialization is in progress function  Serdes_GetStatus() shall return SERDES_INIT_IN_PROGRESS. */
    else if (SERDES_IP_BUSY == Status)
    {
        RetStatus = SERDES_INIT_IN_PROGRESS;
    }
    /* CDD_SERDES_00027: If the Serdes initialization is not successful and the  Serdes_GetStatus() shall return SERDES_ERROR. */
    else
    {
        RetStatus = SERDES_ERROR;
    }

    return RetStatus;
}

Serdes_JobResultType Serdes_Ipw_GetJobResult(uint8 Instance)
{
    Serdes_JobResultType RetJobResult = SERDES_INIT_FAILED;
    Serdes_Ip_JobResultType JobResult;

    /* Get job status */
    JobResult = Serdes_Ip_GetJobResult(Instance);

    if (SERDES_IP_JOB_DONE == JobResult)
    {
        RetJobResult = SERDES_INIT_OK;
    }
    else if (SERDES_IP_JOB_PENDING == JobResult)
    {
        RetJobResult = SERDES_INIT_PENDING;
    }
    else
    {
        RetJobResult = SERDES_INIT_FAILED;
    }

    return RetJobResult;
}

/**
 * @brief           Sets the power mode for the selected channel.
 * @details
 *
 * @param[in]       Instance    Serdes hardware instance.
 * @param[in]       Mode        Serdes hardware power mode.
 *
 * @return          void
 */
void Serdes_Ipw_SetMode(uint8 Instance, Serdes_ModeType Mode)
{
    switch (Mode)
    {
        case SERDES_POWER_NORMAL:
            Serdes_Ip_SetMode(Instance, SERDES_IP_XPCS_POWER_UP);
            break;
        case SERDES_POWER_DOWN:
            Serdes_Ip_SetMode(Instance, SERDES_IP_XPCS_POWER_DOWN);
            break;
        case SERDES_POWER_SAVE_RXTX:
            Serdes_Ip_SetMode(Instance, SERDES_IP_XPCS_POWER_SAVE);
            break;
        default:
            /* Nothing to do */
            break;
    }
}

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
