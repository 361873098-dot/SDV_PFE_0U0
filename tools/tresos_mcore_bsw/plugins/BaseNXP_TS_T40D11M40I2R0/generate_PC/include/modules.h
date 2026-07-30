[!CODE!][!//
/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : 
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
/**
*   @file    modules.h
*   @version 4.0.2
*
*   @brief   AUTOSAR BaseNXP - Project configuration.
*   @details Header file describing all Autosar MCAL modules present in the current project.
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/
/**
* @file        modules.h
*/

#ifndef MODULES_H
#define MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        modules.h
* @brief Include Standard types & defines
*/
#include "StandardTypes.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/** 
@{
* @brief Parameters that shall be published within the modules header file.
*       The integration of incompatible files shall be avoided.
*/
#define MODULES_VENDOR_ID                       43
#define MODULES_MODULE_ID                       0
#define MODULES_AR_RELEASE_MAJOR_VERSION_H      4
#define MODULES_AR_RELEASE_MINOR_VERSION_H      4
#define MODULES_AR_RELEASE_REVISION_VERSION_H   0
#define MODULES_SW_MAJOR_VERSION_H              4
#define MODULES_SW_MINOR_VERSION_H              0
#define MODULES_SW_PATCH_VERSION_H              2
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and StandardTypes.h header file are of the same Autosar version */
    #if ((MODULES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MODULES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of modules.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This constant used for other modules to check if ADC is present in the project.   
*/
#define USE_ADC_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Adc")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if CAN is present in the project.   
*/
#define USE_CAN_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if CAN_43_FLEXCAN is present in the project.   
*/
#define USE_CAN_43_FLEXCAN_MODULE   ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'FLEXCAN')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if CAN_43_CANEXCEL is present in the project.   
*/
#define USE_CAN_43_CANEXCEL_MODULE  ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'CANEXCEL')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CAN_43_LLCE is present in the project.   
*/
#define USE_CAN_43_LLCE_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LLCE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRCU is present in the project.   
*/
#define USE_CRCU_MODULE             ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Crcu")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRYPTO is present in the project.   
*/
#define USE_CRYPTO_MODULE           ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Crypto")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRYPTO_43_HSE is present in the project.   
*/
#define USE_CRYPTO_43_HSE_MODULE    ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Crypto")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'HSE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRYPTO_43_ACE is present in the project.   
*/
#define USE_CRYPTO_43_ACE_MODULE    ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Crypto")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'ACE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if DIO is present in the project.   
*/
#define USE_DIO_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Dio")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if EEP is present in the project. 
*/
#define USE_EEP_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eep")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH is present in the project. 
*/
#define USE_ETH_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH_43_ENET is present in the project. 
*/
#define USE_ETH_43_ENET_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'ENET')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH_43_GMAC is present in the project. 
*/
#define USE_ETH_43_GMAC_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'GMAC')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH_43_NETC is present in the project. 
*/
#define USE_ETH_43_NETC_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'NETC')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if FEE is present in the project.   
*/
#define USE_FEE_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Fee")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if FLS is present in the project.   
*/
#define USE_FLS_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Fls")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Fr is present in the project.   
*/
#define USE_FR_MODULE               ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Fr")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Fr_43_LLCE is present in the project.   
*/
#define USE_FR_43_LLCE_MODULE       ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Fr")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LLCE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if GPT is present in the project.   
*/
#define USE_GPT_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Gpt")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if I2C is present in the project.   
*/
#define USE_I2C_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("I2c")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ICU is present in the project.   
*/
#define USE_ICU_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Icu")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if LIN is present in the project.   
*/
#define USE_LIN_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if Lin_43_LPUART_FLEXIO is present in the project.   
*/
#define USE_LIN_43_LPUART_FLEXIO_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LPUART')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if Lin_43_LINFLEXD is present in the project.   
*/
#define USE_LIN_43_LINFLEXD_MODULE           ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LINFLEXD')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Lin_43_LLCE is present in the project.   
*/
#define USE_LIN_43_LLCE_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LLCE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.   
*/
#define USE_MCEM_MODULE             ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Mcem")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.   
*/
#define USE_MCL_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Mcl")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MCU is present in the project.   
*/
#define USE_MCU_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Mcu")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if OCU is present in the project. 
*/
#define USE_OCU_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Ocu")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if PORT is present in the project.   
*/
#define USE_PORT_MODULE             ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Port")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if PWM is present in the project.   
*/
#define USE_PWM_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Pwm")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if SENT is present in the project.   
*/
#define USE_SENT_MODULE             ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Sent")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if SPI is present in the project.   
*/
#define USE_SPI_MODULE              ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Spi")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

[!VAR "isAnyWdgInstanceUsed" = "0"!][!//
/** 
* @brief This constant used for other modules to check if WDG is present in the project.   
*/
#define USE_WDG_MODULE    ([!VAR "MDL_DEF" = "0"!][!//
[!LOOP "as:modconf("Wdg")"!][!//
[!IF "(CommonPublishedInformation/VendorId = num:i(43))"!][!//
[!IF "(CommonPublishedInformation/VendorApiInfix = 'Instance0')"!][!VAR "MDL_DEF" = "1"!][!VAR "isAnyWdgInstanceUsed" = "1"!][!ENDIF!][!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!//

[!FOR "i" = "1" TO "21"!]
 /**
 * @brief This constant used for other modules to check if WDG Instance [!"$i"!] is present in the project.
 */
#define USE_WDG_INSTANCE[!"$i"!]     ([!VAR "MDL_DEF" = "0"!][!//
[!LOOP "as:modconf("Wdg")"!][!//
[!IF "(CommonPublishedInformation/VendorId = num:i(43))"!][!//
[!IF "(CommonPublishedInformation/VendorApiInfix = concat('Instance',string($i)))"!][!VAR "MDL_DEF" = "1"!][!VAR "isAnyWdgInstanceUsed" = "1"!][!ENDIF!][!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDFOR!][!//

/**
 * @brief This constant used for other modules to check if any WDG Instance is present in the project.
 */
#define USE_WDG_INSTANCE_ANY     ([!IF "$isAnyWdgInstanceUsed = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if WDG for chip vr5510 is present in the project.   
*/
#define USE_WDG_43_VR5510_MODULE      ([!VAR "MDL_DEF" = "0"!][!//
[!LOOP "as:modconf("Wdg")"!][!//
[!IF "(CommonPublishedInformation/VendorId = num:i(43))"!][!//
[!IF "(CommonPublishedInformation/VendorApiInfix = 'VR5510')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */

[!ENDCODE!][!//

