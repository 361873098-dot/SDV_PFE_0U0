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

#ifndef SERDES_IP_CFG_H
#define SERDES_IP_CFG_H


/**
*   @file
*   @internal
*   @addtogroup Serdes
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

/*==================================================================================================
                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_CFG_VENDOR_ID                     43
#define SERDES_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define SERDES_IP_CFG_AR_RELEASE_MINOR_VERSION      4
#define SERDES_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define SERDES_IP_CFG_SW_MAJOR_VERSION              4
#define SERDES_IP_CFG_SW_MINOR_VERSION              0
#define SERDES_IP_CFG_SW_PATCH_VERSION              2

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


/*XPCS0 enabled */
#define SERDES_1_XPCS0_ENABLED   (STD_ON)

/*XPCS1 enabled */
#define SERDES_1_XPCS1_ENABLED   (STD_ON)



/*XPCS0 enabled */
#define SERDES_1_USED   (STD_ON)


/* Define User Mode */
#define SERDES_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

/**
*   @brief      SERDES_IP_TIMEOUT_U32
*   @details    This is a timeout value which is used to wait for power good state
*/
#define SERDES_IP_TIMEOUT_U32                  (1000UL)
#define SERDES_IP_TIMEOUT_TYPE             (OSIF_COUNTER_DUMMY)

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SERDES_IP_CFG_H */
