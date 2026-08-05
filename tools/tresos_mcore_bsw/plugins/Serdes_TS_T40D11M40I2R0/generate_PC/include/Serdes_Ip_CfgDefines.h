/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : SERDES_SS
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.2
* Build Version : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
* Copyright 2020-2023 NXP Semiconductors

*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef SERDES_IP_CFGDEFINES_H
#define SERDES_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup SERDES_DRIVER_CONFIGURATION Serdes Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
[!CODE!][!WS "0"!]#include "S32G274A_SERDES_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_SERDES_SS.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_PCIE_EP.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_PCIE_RC.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
[!CODE!][!WS "0"!]#include "S32G399A_SERDES_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_SERDES_SS.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_PCIE_EP.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_PCIE_RC.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_CFGDEFINES_VENDOR_ID                     43
#define SERDES_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define SERDES_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      4
#define SERDES_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define SERDES_IP_CFGDEFINES_SW_MAJOR_VERSION              4
#define SERDES_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define SERDES_IP_CFGDEFINES_SW_PATCH_VERSION              2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
[!CODE!][!WS "0"!]#define SERDES_0_XPCS1_2_5G[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#define SERDES_1_XPCS1_2_5G[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SERDES_IP_CFGDEFINES_H */
