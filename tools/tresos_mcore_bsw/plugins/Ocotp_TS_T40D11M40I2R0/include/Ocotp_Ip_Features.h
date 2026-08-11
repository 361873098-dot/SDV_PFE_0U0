/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef OCOTP_IP_FEATURES_H
#define OCOTP_IP_FEATURES_H

/**
*   @file
*
*   @addtogroup OCOTP_IP
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IP_FEATURES_VENDOR_ID                    43
#define OCOTP_IP_FEATURES_AR_RELEASE_MAJOR_VERSION     4
#define OCOTP_IP_FEATURES_AR_RELEASE_MINOR_VERSION     4
#define OCOTP_IP_FEATURES_AR_RELEASE_REVISION_VERSION  0
#define OCOTP_IP_FEATURES_SW_MAJOR_VERSION             4
#define OCOTP_IP_FEATURES_SW_MINOR_VERSION             0
#define OCOTP_IP_FEATURES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define OCOTP_IP_FIRST_EFUSE_ADDRESS             0x200U

/* ECC enable bit mask */
#define OCOTP_IP_ECC_ENABLE_MASK                 0x80

/* ECC is on 7-bit */
#define OCOTP_IP_ECC_LENGTH                      7U

/* ECC G[i] values */
#define OCOTP_IP_ECC_VALUES                      {0xC14840FFU, 0x2124FF90U, 0x6CFF0808U, 0xFF01A444U, 0x16F092A6U, 0x101F7161U, 0x8A820F1BU}

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

#endif /* OCOTP_IP_FEATURES_H */
