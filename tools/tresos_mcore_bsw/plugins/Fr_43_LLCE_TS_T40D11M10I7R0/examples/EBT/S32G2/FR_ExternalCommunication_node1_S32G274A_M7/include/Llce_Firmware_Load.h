/**
*   @file    Llce_Firmware_Load.h
*   @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*   @brief   AUTOSAR M4_SRC_MODULE_NAME - Llce_Firmware_Load header
*   @details Llce_Firmware_Load header
*            This file contains sample code only. It is not part of the production code deliverables.
*   @addtogroup TESTS
*   @{
*/
/*==================================================================================================
*   Project              : M4_SRC_PROJECT_NAME
*   Platform             : M4_SRC_MCU_FAMILY
*   Peripheral           : M4_SRC_USED_PERIPHERAL
*   Dependencies         : M4_SRC_AR_MODULE_DEPENDENCY
*
*   Autosar Version      : M4_SRC_AR_SPEC_VERSION_MAJOR.M4_SRC_AR_SPEC_VERSION_MINOR.M4_SRC_AR_SPEC_VERSION_PATCH
*   Autosar Revision     : M4_SRC_AR_RELEASE_REVISION
*   Autosar Conf.Variant :
*   SW Version           : M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*   Build Version        : M4_SRC_BUILD_ID
*
*   (c) Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
ifdef(`M4_SRC_KEEP_REVISION_HISTORY', `dnl - DO NOT modify this M4 line!
Revision History:
                             Modification     Tracking
Author (core ID)              Date D/M/Y       Number     Description of Changes
---------------------------   ----------    ------------  ------------------------------------------
Daniel Spataru (nxf47223)     10/10/2019     AMNG-5743     Add Llce firmware loading API      
---------------------------   ----------    ------------  ------------------------------------------
',)dnl - DO NOT modify this M4 line!
==================================================================================================*/
#ifndef LLCE_FIRMWARE_LOAD_H
#define LLCE_FIRMWARE_LOAD_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/


/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
Std_ReturnType Llce_Firmware_Load(void);

#ifdef __cplusplus
}
#endif

#endif /* LLCE_FIRMWARE_LOAD_H */

/** @} */
