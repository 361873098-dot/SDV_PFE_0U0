[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : TMU
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
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

#ifndef TMU_IP_CFG_H
#define TMU_IP_CFG_H

/**
*   @file
*
*   @addtogroup tmu_ip_config TMU IPL Configuration
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
#include "StandardTypes.h"
[!NOCODE!][!//

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Tmu_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Tmu_Ip_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!]

!INCLUDE "Thermal_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_CFG                    43
#define TMU_IP_MODULE_ID_CFG                    255
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_CFG     4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define TMU_IP_SW_MAJOR_VERSION_CFG             4
#define TMU_IP_SW_MINOR_VERSION_CFG             0
#define TMU_IP_SW_PATCH_VERSION_CFG             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (TMU_IP_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Tmu_Ip_Cfg.h and StandardTypes.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_CFG != TMU_IP_AR_RELEASE_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_CFG != TMU_IP_AR_RELEASE_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_CFG != TMU_IP_AR_RELEASE_REVISION_VERSION_[!"text:toupper(.)"!]_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip_Cfg.h and Tmu_Ip_[!"."!]_PBcfg.h are different"
#endif

#if ((TMU_IP_SW_MAJOR_VERSION_CFG != TMU_IP_SW_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (TMU_IP_SW_MINOR_VERSION_CFG != TMU_IP_SW_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (TMU_IP_SW_PATCH_VERSION_CFG != TMU_IP_SW_PATCH_VERSION_[!"text:toupper(.)"!]_PBCFG_H) \
    )
    #error "Software Version Numbers of Tmu_Ip_Cfg.h and Tmu_Ip_[!"."!]_PBcfg.h are different"
#endif

#if (TMU_IP_VENDOR_ID_CFG != TMU_IP_VENDOR_ID_[!"text:toupper(.)"!]_PBCFG_H)
    #error "Tmu_Ip_Cfg.h and Tmu_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_CFG != TMU_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_CFG != TMU_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_CFG != TMU_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip_Cfg.h and Tmu_Ip_PBcfg.h are different"
#endif

#if ((TMU_IP_SW_MAJOR_VERSION_CFG != TMU_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (TMU_IP_SW_MINOR_VERSION_CFG != TMU_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (TMU_IP_SW_PATCH_VERSION_CFG != TMU_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Tmu_Ip_Cfg.h and Tmu_Ip_PBcfg.h are different"
#endif

#if (TMU_IP_VENDOR_ID_CFG != TMU_IP_VENDOR_ID_PBCFG_H)
    #error "Tmu_Ip_Cfg.h and Tmu_Ip_PBcfg.h have different vendor ids"
#endif
[!ENDIF!]
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TMU_IP_CFG_H */
[!ENDCODE!][!//

