/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef CLOCK_IP_CFG_DEFINES_H
#define CLOCK_IP_CFG_DEFINES_H

/**
*   @file       Clock_Ip_Cfg_Defines.h
*   @version    4.0.2
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
[!CODE!][!WS "0"!]#include "S32G399A_COMMON.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_CGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_CGM_1.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_CGM_2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_CGM_5.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_CGM_6.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_FXOSC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_PLLDIG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_RESET.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_SRAMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_DFS.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_39.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_46.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_47.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_48.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_49.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_50.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_CMU_FC_51.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_S32G_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_RTC.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
[!CODE!][!WS "0"!]#include "S32G274A_COMMON.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MC_CGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MC_CGM_1.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MC_CGM_2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_FXOSC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_PLLDIG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_RESET.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_SRAMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_DFS.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_CMU_FC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_SYSTICK.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_S32G_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_RTC.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32R45_COMMON.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_MC_CGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_MC_CGM_1.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_MC_CGM_2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_FXOSC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_PLLDIG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_RESET.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_SRAMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_DFS.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_CMU_FC.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_DEFINES_VENDOR_ID                       43
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION                4
#define CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION                2

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Platform used.
*/
#define CLOCK_IP_PLATFORM_[!"ecu:get('MCU.Platform')"!]

/**
* @brief            Max number of internal oscillators
*/
#define CLOCK_IP_IRCOSCS_COUNT       ([!"num:i( count( ecu:list('MCU.IRCOSC.List') ) )"!]U)

/**
* @brief            Max number of external oscillators
*/
#define CLOCK_IP_XOSCS_COUNT       ([!"num:i( count( ecu:list('MCU.XOSC.List') ) )"!]U)

/**
* @brief            Max number of pll devices
*/
#define CLOCK_IP_PLLS_COUNT       ([!"num:i( count( ecu:list('MCU.PLL.List') ) )"!]U)

/**
* @brief            Max number of selectors
*/
#define CLOCK_IP_SELECTORS_COUNT       ([!"num:i( count( ecu:list('MCU.SELECTOR.Names.List') ) )"!]U)

/**
* @brief            Max number of dividers
*/
#define CLOCK_IP_DIVIDERS_COUNT       ([!"num:i( count( ecu:list('MCU.DIVIDER.Names.List') ) )"!]U)

/**
* @brief            Max number of divider triggers
*/
#define CLOCK_IP_DIVIDER_TRIGGERS_COUNT       ([!"num:i( count( ecu:list('MCU.DIVIDER.TRIGGER.Names.List') ) )"!]U)

/**
* @brief            Max number of fractional dividers
*/
#define CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT       ([!"num:i( count( ecu:list('MCU.ClockDFS.List') ) )"!]U)

/**
* @brief            Max number of external clocks
*/
#define CLOCK_IP_EXT_CLKS_COUNT       ([!"num:i( count( ecu:list('MCU.ExtClock.List') ) )"!]U)

/**
* @brief            Max number of pcfs
*/
#define CLOCK_IP_PCFS_COUNT       ([!"num:i( count( ecu:list('MCU.CGM.CgmPcfs.List') ))"!]U)

/**
* @brief            Max number of clock gates
*/
#define CLOCK_IP_GATES_COUNT       ([!"num:i( count( ecu:list('MCU.GATE.Names.List') ) )"!]U)

/**
* @brief            Max number of clock monitoring units
*/
#define CLOCK_IP_CMUS_COUNT       ([!"num:i( count( ecu:list('MCU.CMU_FC.List') ) )"!]U)

/**
* @brief            Max number of configured frequencies values
*/
#define CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT       ([!"num:i( count( ecu:list('MCU.ConfiguredFrequency.List') ) )"!]U)

/**
* @brief            Max number of specific peripheral (eMIOS) units
*/
#define CLOCK_IP_SPECIFIC_PERIPH_COUNT       ([!"num:i( count( ecu:list('MCU.SPECIFIC_PERIPHERAL_PRAMs.List') ) )"!]U)

/**
* @brief            Supported power mode.
*/
#define CLOCK_IP_HAS_RUN_MODE                0U

/**
* @brief            Firc frequency
*/
#define CLOCK_IP_FIRC_FREQUENCY              48000000U

/**
* @brief            Sirc frequency
*/
#define CLOCK_IP_SIRC_FREQUENCY              32000U

/**
* @brief            Clock ip supports clock frequency
*/
#define CLOCK_IP_GET_FREQUENCY_API              [!IF "McuDebugConfiguration/McuGetClockFrequencyApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Default fxosc frequency
*/
#define CLOCK_IP_DEFAULT_FXOSC_FREQUENCY     40000000U

/**
* @brief            Clock ip supports ram wait states
*/
[!IF "McuGeneralConfiguration/McuDisableRamWaitStatesConfig = 'false'"!]
#define CLOCK_IP_HAS_RAM_WAIT_STATES
[!ENDIF!]

/**
* @brief            Clock ip supports flash wait states
*/
[!IF "McuGeneralConfiguration/McuDisableFlashWaitStatesConfig = 'false'"!]
#define CLOCK_IP_HAS_FLASH_WAIT_STATES
[!ENDIF!]

/**
* @brief            Supported clocks.
*/
[!FOR "Index" = "1" TO "num:i( count( ecu:list('MCU.ProducerClocks.List') ) )"!][!//
#define CLOCK_IP_HAS_[!"ecu:list('MCU.ProducerClocks.List')[num:i($Index)]"!]         [!"num:i(num:i($Index) - 1)"!]U
[!ENDFOR!][!//
#define CLOCK_IP_FEATURE_PRODUCERS_NO         [!"num:i( count( ecu:list('MCU.ProducerClocks.List') ) )"!]U
[!FOR "Index" = "1" TO "num:i( count( ecu:list('MCU.ConsumerClocks.List') ) )"!][!//
#define CLOCK_IP_HAS_[!"ecu:list('MCU.ConsumerClocks.List')[num:i($Index)]"!]         [!"num:i(num:i($Index) + num:i(count(ecu:list('MCU.ProducerClocks.List'))) )"!]U
[!ENDFOR!][!//
#define CLOCK_IP_FEATURE_NAMES_NO         [!"num:i(num:i(count(ecu:list('MCU.ProducerClocks.List'))) + num:i(count(ecu:list('MCU.ConsumerClocks.List'))) + 1)"!]U

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef CLOCK_IP_CFG_DEFINES_H */

