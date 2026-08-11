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

#ifndef PCIE_IPW_TYPES_H
#define PCIE_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Pcie_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           template_h.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IPW_TYPES_VENDOR_ID                    43
#define PCIE_IPW_TYPES_MODULE_ID                    255
#define PCIE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_IPW_TYPES_AR_RELEASE_MINOR_VERSION     4
#define PCIE_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define PCIE_IPW_TYPES_SW_MAJOR_VERSION             4
#define PCIE_IPW_TYPES_SW_MINOR_VERSION             0
#define PCIE_IPW_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pcie_Ipw_Types.h file and Std_Types.h header file are of the same Autosar version */
    #if ((PCIE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_IPW_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie_Ipw_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (PCIE_IPW_TYPES_VENDOR_ID != PCIE_IP_TYPES_VENDOR_ID)
#error "Pcie_Ipw_Types.h and Pcie_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are of the same Autosar version */
#if ((PCIE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != PCIE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != PCIE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != PCIE_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ipw_Types.h and Pcie_Ip_Types.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are of the same software version */
#if ((PCIE_IPW_TYPES_SW_MAJOR_VERSION != PCIE_IP_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IPW_TYPES_SW_MINOR_VERSION != PCIE_IP_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IPW_TYPES_SW_PATCH_VERSION != PCIE_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ipw_Types.h and Pcie_Ip_Types.h are different"
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

/**
* @brief   The structure contains the hardware channel configuration type.
*/
typedef struct
{
    const Pcie_Ip_ConfigType *   PcieHwConfig;

} Pcie_Ipw_HwChannelConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*PCIE_IPW_TYPES_H*/

/** @} */
