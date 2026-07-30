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

#ifndef PCIE_IP_DEVICEREG_H
#define PCIE_IP_DEVICEREG_H


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

[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
[!CODE!][!WS "0"!]#include "S32G274A_PCIE_EP.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_SERDES_SS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
[!CODE!][!WS "0"!]#include "S32G399A_PCIE_EP.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_SERDES_SS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCIE_IP_DEVICEREG_VENDOR_ID                     43
#define PCIE_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION      4
#define PCIE_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION      4
#define PCIE_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION   0
#define PCIE_IP_DEVICEREG_SW_MAJOR_VERSION              4
#define PCIE_IP_DEVICEREG_SW_MINOR_VERSION              0
#define PCIE_IP_DEVICEREG_SW_PATCH_VERSION              2


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

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

#endif /* PCIE_IP_DEVICEREG_H */
