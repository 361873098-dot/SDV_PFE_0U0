[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Port_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Src.m"!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('Port.Derivative'))='S32G2')"!][!//
    [!INCLUDE "Port_S32G2_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='S32G3')"!][!//
    [!INCLUDE "Port_S32G3_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='S32R')"!][!//
    [!INCLUDE "Port_S32R_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='S32V')"!][!//
    [!INCLUDE "Port_S32V_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                4
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                2

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif

/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/* Check if Port_Cfg.c and Port.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on first SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_0_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV1"!]] =
{[!//
[!"$SIUL2_0_IN_SETTINGS_INDEX_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on second SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 1"!][!//
static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(2)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_1_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV1"!]] =
{[!//
[!"$SIUL2_1_IN_SETTINGS_INDEX_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on first SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
static const Port_PinModeAvailabilityArrayType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16PinModeAvailability')"!] =
{[!//
[!"$SIUL2_0_PIN_MODE_AVAILABILITY_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on second SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 1"!][!//
static const Port_PinModeAvailabilityArrayType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(2)], '_au16PinModeAvailability')"!] =
{[!//
[!"$SIUL2_1_PIN_MODE_AVAILABILITY_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

/**
* @brief Array of elements storing information about IN functionalities on the first SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInMuxSettings')"!][[!"$SIUL2_0_SIZE_OF_IN_SETTINGS_ON_SUBDERIV1"!]] =
{[!//
[!"$SIUL2_0_IN_SETTINGS_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

/**
* @brief Array of elements storing information about IN functionalities on the second SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 1"!][!//
static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(2)], '_aInMuxSettings')"!][[!"$SIUL2_1_SIZE_OF_IN_SETTINGS_ON_SUBDERIV1"!]] =
{[!//
[!"$SIUL2_1_IN_SETTINGS_ON_SUBDERIV1"!][!//
};

[!ENDIF!][!//

/**
* @brief Array of elements storing information about INOUT functionalities on the first SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
static const Port_InoutSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInoutMuxSettings')"!][[!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i(1)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!]] =
{[!//
[!"$SIUL2_0_INOUT_SETTINGS_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

/**
* @brief Array of elements storing information about INOUT functionalities on the second SIUL2 instance
*/
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 1"!][!//
static const Port_InoutSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(2)], '_aInoutMuxSettings')"!][[!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i(2)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!]] =
{[!//
[!"$SIUL2_1_INOUT_SETTINGS_ON_SUBDERIV1"!][!//
};
[!ENDIF!][!//

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    [!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    &[!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16PinModeAvailability')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    &[!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16PinModeAvailability')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
const uint16 * const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16InMuxSettingsIndex')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16InMuxSettingsIndex')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInoutMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInoutMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
[!ENDCODE!][!//
