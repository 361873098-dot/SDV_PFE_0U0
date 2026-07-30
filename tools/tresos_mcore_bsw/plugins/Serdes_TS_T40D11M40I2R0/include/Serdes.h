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

#ifndef SERDES_H
#define SERDES_H

/**
*   @file    Serdes.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Serdes - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*   @implements Serdes.h_Artifact
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
#include "Mcal.h"
#include "Serdes_Types.h"
#include "Serdes_Ipw.h"
#include "Serdes_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SERDES_VENDOR_ID                    43
#define SERDES_MODULE_ID                    255
#define SERDES_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_AR_RELEASE_MINOR_VERSION     4
#define SERDES_AR_RELEASE_REVISION_VERSION  0
#define SERDES_SW_MAJOR_VERSION             4
#define SERDES_SW_MINOR_VERSION             0
#define SERDES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Cfg.h file are of the same vendor */
#if (SERDES_VENDOR_ID != SERDES_VENDOR_ID_CFG)
    #error "Serdes.h and Serdes_Cfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Cfg.h file are of the same Autosar version */
#if ((SERDES_AR_RELEASE_MAJOR_VERSION    != SERDES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SERDES_AR_RELEASE_MINOR_VERSION    != SERDES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SERDES_AR_RELEASE_REVISION_VERSION != SERDES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Serdes.h and Serdes_Cfg.h are different"
#endif
/* Check if current file and Serdes_Cfg.h file are of the same software version */
#if ((SERDES_SW_MAJOR_VERSION != SERDES_SW_MAJOR_VERSION_CFG) || \
     (SERDES_SW_MINOR_VERSION != SERDES_SW_MINOR_VERSION_CFG) || \
     (SERDES_SW_PATCH_VERSION != SERDES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Serdes.h and Serdes_Cfg.h are different"
#endif

/* Check if current file and Serdes_Types.h file are of the same vendor */
#if (SERDES_VENDOR_ID != SERDES_TYPES_VENDOR_ID)
    #error "Serdes.h and Serdes_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Types.h file are of the same Autosar version */
#if ((SERDES_AR_RELEASE_MAJOR_VERSION    != SERDES_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_AR_RELEASE_MINOR_VERSION    != SERDES_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_AR_RELEASE_REVISION_VERSION != SERDES_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes.h and Serdes_Types.h are different"
#endif
/* Check if current file and Serdes_Types.h file are of the same software version */
#if ((SERDES_SW_MAJOR_VERSION != SERDES_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_SW_MINOR_VERSION != SERDES_TYPES_SW_MINOR_VERSION) || \
     (SERDES_SW_PATCH_VERSION != SERDES_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes.h and Serdes_Types.h are different"
#endif

/* Check if current file and Serdes_Ipw.h file are of the same vendor */
#if (SERDES_VENDOR_ID != SERDES_IPW_VENDOR_ID)
#error "Serdes.h and Serdes_Ipw.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw.h file are of the same Autosar version */
#if ((SERDES_AR_RELEASE_MAJOR_VERSION    != SERDES_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_AR_RELEASE_MINOR_VERSION    != SERDES_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_AR_RELEASE_REVISION_VERSION != SERDES_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes.h and Serdes_Ipw.h are different"
#endif
/* Check if current file and Serdes_Ipw.h file are of the same software version */
#if ((SERDES_SW_MAJOR_VERSION != SERDES_IPW_SW_MAJOR_VERSION) || \
     (SERDES_SW_MINOR_VERSION != SERDES_IPW_SW_MINOR_VERSION) || \
     (SERDES_SW_PATCH_VERSION != SERDES_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes.h and Serdes_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Autosar version */
    #if ((SERDES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#if (SERDES_DEV_ERROR_DETECT == STD_ON)

/**
* @brief            API service called with invalid configuration pointer
* @details          The Serdes Driver module shall report the development error
*                   "SERDES_E_INVALID_POINTER (0x01)", when API Service is called
*                   with invalid configuration pointer.
*
* @api
*/
#define SERDES_E_INVALID_POINTER   ((uint8)0x01U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The Serdes Driver module shall report the development error
*                   "SERDES_E_INIT_IN_POINTER (0x02)", when API Service is called
*                   and Serdes initialization is already in progress.
*
* @api
*/
#define SERDES_E_INIT_IN_PROGRESS   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The Serdes Driver module shall report the development error
*                   "SERDES_E_UNINIT (0x03)", when API Service is called
*                   and Serdes initialization is not started.
*
* @api
*/
#define SERDES_E_UNINIT   ((uint8)0x03U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The Serdes Driver module shall report the development error
*                   "SERDES_E_INVALID_PARAMETER (0x04)", when API Service is called
*                   with out of range parameter.
*
* @api
*/
#define SERDES_E_INVALID_PARAMETER   ((uint8)0x04U)

/* Service ID for Serdes_Init() function */
#define SERDES_INIT_ID    ((uint8)0x00U)

/* Service ID for Serdes_MainFunction() function */
#define SERDES_MAIN_FUNCTION_ID    ((uint8)0x01U)

/* Service ID for Serdes_GetStatus() function */
#define SERDES_GETSTATUS_ID    ((uint8)0x03U)

/* Service ID for Serdes_GetJobResult() function */
#define SERDES_GETJOBRESULT_ID    ((uint8)0x02U)

/* Service ID for Serdes_SetMode() function*/
#define SERDES_SETMODE_ID    ((uint8)0x04U)

/* Service ID for Serdes_GetVersionInfo() function*/
#define SERDES_GETVERSIONINFO_ID    ((uint8)0x0AU)

#endif /* SERDES_DEV_ERROR_DETECT == STD_ON*/

/**
* @brief          The SERDES module is not properly configured
*
* @api
*/
#define SERDES_E_PARAM_CONFIG                ((uint8)0xF0)



/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == SERDES_MULTICORE_ENABLED)
    #define Serdes_GetCoreID()            OsIf_GetCoreID()
#else
    #define Serdes_GetCoreID()            ((uint32)0UL)
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/**
* @brief          Starts initialization of serdes module.
* @details        Initialization is done asynchronous and will not be completed after calling this
*                 function. Serdes_MainFunction() should be called multiple times until initialization
*                 is completed.
*
* @param[in]      Config      Serdes configuration structure.
*
* @return         void
*/
void Serdes_Init(const Serdes_ConfigType * Config);

/**
* @brief          Returns job result.
* @details        This function returns the initialization job result. In case the initialization is
*                 completed it will return SERDES_INIT_OK, otherwise it will return SERDES_INIT_PENDING
*                 if initialization is still in progress or SERDES_INIT_FAILED if initialization failed to
*                 complete.
*
* @return         void
*/
Serdes_JobResultType Serdes_GetJobResult(void);

/**
* @brief          Returns driver status.
* @details
*
* @return         void
*/
Serdes_StatusType Serdes_GetStatus(uint8 Channel);

#ifdef SERDES_SET_MODE_API
#if (STD_ON == SERDES_SET_MODE_API)
/**
* @brief          Sets the power mode for the selected channel.
* @details
*
* @return         void
*/
void Serdes_SetMode(uint8 Channel, Serdes_ModeType Mode);
#endif /* (STD_ON == SERDES_SET_MODE_API) */
#endif /* SERDES_SET_MODE_API */

#if (SERDES_VERSION_INFO_API == STD_ON)

/**
* @brief          Gets version information.
* @details
*
* @return         void
*/
void Serdes_GetVersionInfo (Std_VersionInfoType * VersionInfo);
#endif

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SERDES_H*/
