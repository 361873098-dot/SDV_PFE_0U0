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
*   @file
*
*   @addtogroup PCIE_DRIVER_CONFIGURATION Pcie Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pcie_Ip_PBCfg.h"
#include "Pcie_Ipw_PBCfg.h"
#include "Pcie_Ipw_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_IPW_PBCFG_VENDOR_ID_C                     43
#define PCIE_IPW_PBCFG_MODULE_ID_C                     255
#define PCIE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PCIE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define PCIE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define PCIE_IPW_PBCFG_SW_MAJOR_VERSION_C              4
#define PCIE_IPW_PBCFG_SW_MINOR_VERSION_C              0
#define PCIE_IPW_PBCFG_SW_PATCH_VERSION_C              2


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pcie_Ip_PBCfg.h file are of the same vendor */
#if (PCIE_IPW_PBCFG_VENDOR_ID_C  != PCIE_IP_PBCFG_VENDOR_ID)
    #error "Pcie_Ipw_PBCfg.c and Pcie_Ip_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip_PBCfg.h file are of the same Autosar version */
#if ((PCIE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != PCIE_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip_PBCfg.h and Pcie_Ipw_PBCfg.c are different"
#endif
/* Check if current file and Pcie_Ip_PBCfg.h file are of the same Software version */
#if ((PCIE_IPW_PBCFG_SW_MAJOR_VERSION_C != PCIE_IP_PBCFG_SW_MAJOR_VERSION) || \
     (PCIE_IPW_PBCFG_SW_MINOR_VERSION_C != PCIE_IP_PBCFG_SW_MINOR_VERSION) || \
     (PCIE_IPW_PBCFG_SW_PATCH_VERSION_C != PCIE_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip_PBCfg.h and Pcie_Ipw_PBCfg.c are different"
#endif

/* Check if current file and Pcie_Ipw_PBCfg.h file are of the same module */
#if (PCIE_IPW_PBCFG_MODULE_ID_C != PCIE_IPW_PBCFG_MODULE_ID)
    #error "Pcie_Ipw_PBCfg.c and Pcie_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ipw_PBCfg.h file are of the same vendor */
#if (PCIE_IPW_PBCFG_VENDOR_ID_C != PCIE_IPW_PBCFG_VENDOR_ID)
    #error "Pcie_Ipw_PBCfg.c and Pcie_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ipw_PBCfg.h file are of the same Autosar version */
#if ((PCIE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != PCIE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != PCIE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ipw_PBCfg.c and Pcie_Ipw_PBCfg.h are different"
#endif
/* Check if current file and Pcie_Ipw_PBCfg.h file are of the same Software version */
#if ((PCIE_IPW_PBCFG_SW_MAJOR_VERSION_C != PCIE_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (PCIE_IPW_PBCFG_SW_MINOR_VERSION_C != PCIE_IPW_PBCFG_SW_MINOR_VERSION) || \
     (PCIE_IPW_PBCFG_SW_PATCH_VERSION_C != PCIE_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ipw_PBCfg.h and Pcie_Ipw_PBCfg.c are different"
#endif

/* Check if current file and Pcie_Ipw_Types.h are of the same vendor */
#if (PCIE_IPW_PBCFG_MODULE_ID_C != PCIE_IPW_TYPES_MODULE_ID)
    #error "Pcie_Ipw_PBCfg.c and Pcie_Ipw_Types.h have different module ids"
#endif
/* Check if current file and Pcie_Ipw_Types.h are of the same vendor */
#if (PCIE_IPW_PBCFG_VENDOR_ID_C != PCIE_IPW_TYPES_VENDOR_ID)
    #error "Pcie_Ipw_PBCfg.c and Pcie_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ipw_Types.h are of the same Autosar version */
#if ((PCIE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PCIE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != PCIE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != PCIE_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ipw_PBCfg.c and Pcie_Ipw_Types.h are different"
#endif
/* Check if current file and Pcie_Ipw_Types.h are of the same Software version */
#if ((PCIE_IPW_PBCFG_SW_MAJOR_VERSION_C != PCIE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IPW_PBCFG_SW_MINOR_VERSION_C != PCIE_IPW_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IPW_PBCFG_SW_PATCH_VERSION_C != PCIE_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ipw_PBCfg.c and Pcie_Ipw_Types.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#define PCIE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

[!NOCODE!][!//

[!LOOP "PcieGlobalConfig/PcieChannel/*"!] /* Loop through all configured channels */
[!CODE!]

/* Config structure for channel [!"PcieHwChannel"!] */
const Pcie_Ipw_HwChannelConfigType Pcie_Ipw_ChannelConfig[!"PcieChannelId"!] =
{
    &PcieConfig[!"PcieChannelId"!]

};
[!ENDCODE!]
[!ENDLOOP!] /* End of the loop */

[!ENDNOCODE!][!//

#define PCIE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pcie_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
