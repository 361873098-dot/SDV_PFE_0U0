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
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   (c) Copyright 2020-2023 NXP
*   All Rights Reserved.
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
*   @file       Serdes_Cfg.c
*
*   @addtogroup Serdes_HLD
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
#include "Serdes_Cfg.h"
#include "Serdes_Types.h"
#include "Serdes_Ipw_PBCfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_CFG_VENDOR_ID_CFG_C                      43
#define SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define SERDES_CFG_SW_MAJOR_VERSION_CFG_C               4
#define SERDES_CFG_SW_MINOR_VERSION_CFG_C               0
#define SERDES_CFG_SW_PATCH_VERSION_CFG_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Serdes header file are of the same vendor */
#if (SERDES_CFG_VENDOR_ID_CFG_C != SERDES_VENDOR_ID_CFG)
    #error "Serdes_Cfg.c and Serdes_Cfg.h have different vendor ids"
#endif
/* Check if current file and Serdes header file are of the same Autosar version */
#if ((SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != SERDES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C    != SERDES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C != SERDES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Serdes_Cfg.c and Serdes_Cfg.h are different"
#endif
/* Check if current file and Serdes header file are of the same Software version */
#if ((SERDES_CFG_SW_MAJOR_VERSION_CFG_C != SERDES_SW_MAJOR_VERSION_CFG) || \
     (SERDES_CFG_SW_MINOR_VERSION_CFG_C != SERDES_SW_MINOR_VERSION_CFG) || \
     (SERDES_CFG_SW_PATCH_VERSION_CFG_C != SERDES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Serdes_Cfg.c and Serdes_Cfg.h are different"
#endif

/* Check if current file and Serdes_Types.h file are of the same vendor */
#if (SERDES_CFG_VENDOR_ID_CFG_C != SERDES_TYPES_VENDOR_ID)
    #error "Serdes_Cfg.c and Serdes_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Types.h file are of the same Autosar version */
#if ((SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != SERDES_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C    != SERDES_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C != SERDES_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Cfg.c and Serdes_Types.h are different"
#endif
/* Check if current file and Serdes_Types.h file are of the same Software version */
#if ((SERDES_CFG_SW_MAJOR_VERSION_CFG_C != SERDES_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_CFG_SW_MINOR_VERSION_CFG_C != SERDES_TYPES_SW_MINOR_VERSION) || \
     (SERDES_CFG_SW_PATCH_VERSION_CFG_C != SERDES_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Cfg.c and Serdes_Types.h are different"
#endif

/* Check if current file and Serdes_Ipw_PBCfg.h file are of the same vendor */
#if (SERDES_CFG_VENDOR_ID_CFG_C != SERDES_IPW_PBCFG_VENDOR_ID)
    #error "Serdes_Cfg.c and Serdes_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw_PBCfg.h file are of the same Autosar version */
#if ((SERDES_CFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != SERDES_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_MINOR_VERSION_CFG_C    != SERDES_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_CFG_AR_RELEASE_REVISION_VERSION_CFG_C != SERDES_IPW_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Cfg.c and Serdes_Ipw_PBCfg.h are different"
#endif
/* Check if current file and Serdes_Ipw_PBCfg.h file are of the same Software version */
#if ((SERDES_CFG_SW_MAJOR_VERSION_CFG_C != SERDES_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (SERDES_CFG_SW_MINOR_VERSION_CFG_C != SERDES_IPW_PBCFG_SW_MINOR_VERSION) || \
     (SERDES_CFG_SW_PATCH_VERSION_CFG_C != SERDES_IPW_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Cfg.c and Serdes_Ipw_PBCfg.h are different"
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
#define SERDES_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

/**
* @brief        Definition of Serdes hardware channel structure.
* @details      Configures the hardware peripheral of a Serdes channel.
*               Configuration set by calling Serdes_Init() API.
*/

static const Serdes_HwUnitConfigType Serdes_ChannelConfig[1] =
{
        {
            /* The hardware channel ID. */
            (Serdes_HwUnitType) SERDES_IP_SS_BASE_ADDR_1,

            &Serdes_Ipw_ChannelConfig0
        } /* End of Serdes_ChannelConfig[0]. */
};

/**
* @brief        Definition of Serdes hardware channel structure.
* @details      Configures the hardware peripheral of a Serdes channel.
*               Configuration set by calling Serdes_Init() API.
*/
const Serdes_ConfigType Serdes_PBCfgVariantPredefined[1] =
{
    {
        /* CoreId */
        (uint32)(0UL),
        /* Pointer to Serdes Hardware Unit configuration. */
        &Serdes_ChannelConfig
    }
};
#define SERDES_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"
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
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
