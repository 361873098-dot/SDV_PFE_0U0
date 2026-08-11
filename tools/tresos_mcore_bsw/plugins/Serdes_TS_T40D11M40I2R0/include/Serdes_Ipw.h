
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

#ifndef SERDES_IPW_H
#define SERDES_IPW_H

/**
*   @file
*
*   @internal
*   @addtogroup Serdes
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
#include "Serdes_Ipw_Types.h"
#include "Serdes_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IPW_VENDOR_ID                    43
#define SERDES_IPW_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_IPW_AR_RELEASE_MINOR_VERSION     4
#define SERDES_IPW_AR_RELEASE_REVISION_VERSION  0
#define SERDES_IPW_SW_MAJOR_VERSION             4
#define SERDES_IPW_SW_MINOR_VERSION             0
#define SERDES_IPW_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ipw_Types.h file are of the same vendor */
#if (SERDES_IPW_TYPES_VENDOR_ID != SERDES_IPW_VENDOR_ID)
    #error "Serdes_Ipw_Types.h and Serdes_Ipw.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw_Types.h file are of the same Autosar version */
#if ((SERDES_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != SERDES_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IPW_TYPES_AR_RELEASE_MINOR_VERSION != SERDES_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SERDES_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw_Types.h and Serdes_Ipw.h are different"
#endif
/* Check if current file and Serdes_Ipw_Types.h file are of the same Software version */
#if ((SERDES_IPW_TYPES_SW_MAJOR_VERSION != SERDES_IPW_SW_MAJOR_VERSION) || \
     (SERDES_IPW_TYPES_SW_MINOR_VERSION != SERDES_IPW_SW_MINOR_VERSION) || \
     (SERDES_IPW_TYPES_SW_PATCH_VERSION != SERDES_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ipw_Types.h and Serdes_Ipw.h are different"
#endif

/* Check if current file and Serdes_Types.h file are of the same vendor */
#if (SERDES_TYPES_VENDOR_ID != SERDES_IPW_VENDOR_ID)
    #error "Serdes_Types.h and Serdes_Ipw.h have different vendor ids"
#endif
/* Check if current file and  Serdes_Types.h file are of the same Autosar version */
#if ((SERDES_TYPES_AR_RELEASE_MAJOR_VERSION != SERDES_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_TYPES_AR_RELEASE_MINOR_VERSION != SERDES_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_TYPES_AR_RELEASE_REVISION_VERSION != SERDES_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Types.h and Serdes_Ipw.h are different"
#endif
/* Check if current file and Serdes_Types.h file are of the same Software version */
#if ((SERDES_TYPES_SW_MAJOR_VERSION != SERDES_IPW_SW_MAJOR_VERSION) || \
     (SERDES_TYPES_SW_MINOR_VERSION != SERDES_IPW_SW_MINOR_VERSION) || \
     (SERDES_TYPES_SW_PATCH_VERSION != SERDES_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Types.h and Serdes_Ipw.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

Std_ReturnType Serdes_Ipw_InitChannel(const uint8 Instance, const Serdes_Ipw_HwChannelConfigType * ConfigPtr);
Serdes_StatusType Serdes_Ipw_MainFunction(uint8 Instance);
Serdes_StatusType Serdes_Ipw_GetStatus(uint8 Instance);
Serdes_JobResultType Serdes_Ipw_GetJobResult(uint8 Instance);

/**
 * @brief           Sets the power mode for the selected channel.
 */
void Serdes_Ipw_SetMode(uint8 Instance, Serdes_ModeType Mode);

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SERDES_IPW_H */


