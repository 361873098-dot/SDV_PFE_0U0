/*===================================================================================================*/
/*
*   @file              MemDal_Cfg.h
*   project            AUTOSAR 4.4 MCAL
*   platform           CORTEXM

*   @version           23.02.0
*
*   @brief             Configuration of MemDal software component.
*   @details           Definitions of all pre-compile configuration parameters.
*
*   Autosar Version    4.4.0
*   Build Version      S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*/
/*===================================================================================================*/
#ifndef MENDAL_CFG_H
#define MENDAL_CFG_H

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
#include "MemDal_Types.h"

/*===================================================================================================*/
/*                              SOURCE FILE VERSION INFORMATION                                      */
/*===================================================================================================*/
#define MEMDAL_CFG_VENDOR_ID                            43

#define MEMDAL_CFG_AR_RELEASE_MAJOR_VERSION             4
#define MEMDAL_CFG_AR_RELEASE_MINOR_VERSION             4
#define MEMDAL_CFG_AR_RELEASE_REVISION_VERSION          0

#define MEMDAL_CFG_SW_MAJOR_VERSION                     23
#define MEMDAL_CFG_SW_MINOR_VERSION                     02
#define MEMDAL_CFG_SW_PATCH_VERSION                     0

/*===================================================================================================*/
/*                                      FILE VERSION CHECKS                                          */
/*===================================================================================================*/

/* Check if MemDal configuration header file and types header file are of the same vendor */
#if (MEMDAL_CFG_VENDOR_ID != MEMDAL_TYPES_VENDOR_ID)
    #error "MemDal_Cfg.h and MemDal_Types.h have different vendor ids"
#endif

/* Check if MemDal configuration header file and types header file are of the same Autosar version */
#if ((MEMDAL_CFG_AR_RELEASE_MAJOR_VERSION != MEMDAL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEMDAL_CFG_AR_RELEASE_MINOR_VERSION != MEMDAL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEMDAL_CFG_AR_RELEASE_REVISION_VERSION != MEMDAL_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MemDal_Cfg.h and MemDal_Types.h are different"
#endif

/* Check if MemDal configuration header file and types header file are of the same software version */
#if ((MEMDAL_CFG_SW_MAJOR_VERSION != MEMDAL_TYPES_SW_MAJOR_VERSION) || \
     (MEMDAL_CFG_SW_MINOR_VERSION != MEMDAL_TYPES_SW_MINOR_VERSION) || \
     (MEMDAL_CFG_SW_PATCH_VERSION != MEMDAL_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MemDal_Cfg.h and MemDal_Types.h are different"
#endif

/*===================================================================================================*/
/*                                       DEFINES AND MACROS                                          */
/*===================================================================================================*/

/* MemDal component enable flag */
#define MEMDAL_ENABLED                      STD_OFF

/* MemDal FEE component enable flag */
#define MEMDAL_FEE_ENABLED                  STD_OFF

/* MemDal SDHC component enable flag */
#define MEMDAL_SDHC_ENABLED                 STD_OFF

/* Number of FEE blocks */
#define MEMDAL_BLOCKS_NUMBER_FEE            0U

/* Number of SDHC blocks */
#define MEMDAL_BLOCKS_NUMBER_SDHC           0U

/* Number of MemDal blocks */
#define MEMDAL_BLOCKS_NUMBER                0U

/* MemDal development error detect */
#define MEMDAL_JOB_QUEUE_SIZE               50U

/* MemDal development error detect */
#define MEMDAL_DEV_ERROR_DETECT             STD_ON

/* MemDal blocks ID */

/*===================================================================================================*/
/*                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)                          */
/*===================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MENDAL_CFG_H */


