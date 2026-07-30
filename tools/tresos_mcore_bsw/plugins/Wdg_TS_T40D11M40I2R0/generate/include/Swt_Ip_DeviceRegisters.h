/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Swt
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

#ifndef SWT_DEVICE_REGISTERS_H
#define SWT_DEVICE_REGISTERS_H

/**
*   @file
*
*   @addtogroup Swt
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
#include "Swt_Ip_FeatureDefines.h"

[!NOCODE!][!// Include specific header file 
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
[!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_SWT.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!// 
[!CODE!][!WS "0"!]#include "S32G274A_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!// 
[!CODE!][!WS "0"!]#include "S32G399A_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!// 
[!CODE!][!WS "0"!]#include "S32R45_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!// 
[!CODE!][!WS "0"!]#include "S32R41_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'sja')"!][!// 
[!CODE!][!WS "0"!]#include "SJA1110.h"[!CR!][!ENDCODE!][!// 
    [!ENDIF!][!// 
[!ENDIF!][!// 
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_DEVICE_REGISTERS_VENDOR_ID                    43
#define SWT_IP_DEVICE_REGISTERS_MODULE_ID                    102
#define SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION     4
#define SWT_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION  0
#define SWT_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION             4
#define SWT_IP_DEVICE_REGISTERS_SW_MINOR_VERSION             0
#define SWT_IP_DEVICE_REGISTERS_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (SWT_IP_DEVICE_REGISTERS_VENDOR_ID != SWT_IP_FEATURE_DEFINES_VENDOR_ID)
#error "Swt_Ip_DeviceRegisters.h and Swt_Ip_FeatureDefines.h have different vendor ids"
#endif

#if ((SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION    != SWT_IP_FEATURE_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION    != SWT_IP_FEATURE_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION != SWT_IP_FEATURE_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip_DeviceRegisters.h and Swt_Ip_FeatureDefines.h are different"
#endif

#if ((SWT_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION != SWT_IP_FEATURE_DEFINES_SW_MAJOR_VERSION) || \
     (SWT_IP_DEVICE_REGISTERS_SW_MINOR_VERSION != SWT_IP_FEATURE_DEFINES_SW_MINOR_VERSION) || \
     (SWT_IP_DEVICE_REGISTERS_SW_PATCH_VERSION != SWT_IP_FEATURE_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip_DeviceRegisters.h and Swt_Ip_FeatureDefines.h are different"
#endif

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

#endif /*SWT_DEVICE_REGISTERS_H */
