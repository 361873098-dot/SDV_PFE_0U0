/*===================================================================================================*/
/*
*   @file              SysDal_Rtm_Cfg.c
*   project            AUTOSAR 4.4 MCAL
*   platform           CORTEXM
*
*   @brief             Configuration of SysDal RTM software component.
*   @details           This application performs code flows execution measurement
*
*   Autosar Version    4.4.0
*   Build Version      S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*/
/*===================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*===================================================================================================*/
/*                                         INCLUDE FILES                                             
   1) system and project includes
   2) needed interfaces from external units
   3) internal and external interfaces from this unit
*/   
/*===================================================================================================*/
#include "SysDal_Rtm_Cfg.h"

#if (SYSDAL_RTM_ENABLED == STD_ON)

#include "SysDal_Rtm_Types.h"

/*===================================================================================================*/
/*                              SOURCE FILE VERSION INFORMATION                                      */
/*===================================================================================================*/
#define SYSDAL_RTM_CFG_VENDOR_ID_C                          43

#define SYSDAL_RTM_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define SYSDAL_RTM_CFG_AR_RELEASE_MINOR_VERSION_C           4
#define SYSDAL_RTM_CFG_AR_RELEASE_REVISION_VERSION_C        0

#define SYSDAL_RTM_CFG_SW_MAJOR_VERSION_C                   23
#define SYSDAL_RTM_CFG_SW_MINOR_VERSION_C                   02
#define SYSDAL_RTM_CFG_SW_PATCH_VERSION_C                   0

/*===================================================================================================*/
/*                                      FILE VERSION CHECKS                                          */
/*===================================================================================================*/

/* Check if SYSDAL RTM configuration files are of the same vendor */
#if (SYSDAL_RTM_CFG_VENDOR_ID_C != SYSDAL_RTM_CFG_VENDOR_ID)
    #error "SysDal_Rtm_Cfg.c and SysDal_Rtm_Cfg.h have different vendor ids"
#endif

/* Check if SYSDAL RTM configuration files are of the same Autosar version */
#if ((SYSDAL_RTM_CFG_AR_RELEASE_MAJOR_VERSION_C != SYSDAL_RTM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_RTM_CFG_AR_RELEASE_MINOR_VERSION_C != SYSDAL_RTM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_RTM_CFG_AR_RELEASE_REVISION_VERSION_C != SYSDAL_RTM_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal_Rtm_Cfg.c and SysDal_Rtm_Cfg.h are different"
#endif

/* Check if SYSDAL RTM configuration files are of the same software version */
#if ((SYSDAL_RTM_CFG_SW_MAJOR_VERSION_C != SYSDAL_RTM_CFG_SW_MAJOR_VERSION) || \
     (SYSDAL_RTM_CFG_SW_MINOR_VERSION_C != SYSDAL_RTM_CFG_SW_MINOR_VERSION) || \
     (SYSDAL_RTM_CFG_SW_PATCH_VERSION_C != SYSDAL_RTM_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal_Rtm_Cfg.c and SysDal_Rtm_Cfg.h are different"
#endif

/*===================================================================================================*/
/*                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)                          */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                       DEFINES AND MACROS                                          */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                             LOCAL CONSTANTS                                       */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                             LOCAL VARIABLES                                       */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                            GLOBAL CONSTANTS                                       */   
/*===================================================================================================*/

/*===================================================================================================*/
/*                                            GLOBAL VARIABLES                                       */ 
/*===================================================================================================*/

/* List of configuread RTM measurements.
 * Each of this measurement could be run in parallel with the rest
 */
VAR(SysDal_Rtm_MeasurementType, AUTOMATIC) SysDal_Rtm_Measurements[SYSDAL_RTM_MAX_MEAS_NUMBER] =
{
    /* LoadAndAuthM7 */
    {
        FALSE,                  /**< @brief Measurement enable flag */
        {0U, 0U},               /**< @brief Measurement start point */
        {0U, 0U},               /**< @brief Measurement stop point */
        RTM_MODE_ONESHOT,       /**< @brief Measurement mode */
        0U                      /**< @brief Measurement result index */
    }
};

#endif /* (SYSDAL_RTM_ENABLED == STD_ON) */

/*===================================================================================================*/
#ifdef __cplusplus
}
#endif

