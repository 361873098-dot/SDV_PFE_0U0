/*==================================================================================================
* Project              : RTD AUTOSAR 4.4
* Platform             : CORTEXM
* Peripheral           : Ftm
* Dependencies         : none
*
* Autosar Version      : 4.4.0
* Autosar Revision     : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version           : 4.0.2
* Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
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

#ifndef PWM_IPW_NOTIF_H
#define PWM_IPW_NOTIF_H

/**
*   @file       Pwm_Ipw_Notif.h
*
*   @internal
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define PWM_IPW_NOTIF_VENDOR_ID                       43
#define PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION        4
#define PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION        4
#define PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION     0
#define PWM_IPW_NOTIF_SW_MAJOR_VERSION                4
#define PWM_IPW_NOTIF_SW_MINOR_VERSION                0
#define PWM_IPW_NOTIF_SW_PATCH_VERSION                2

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/


/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/** @brief      Function for notifications of FTM channels implemented through macro */
#define Pwm_Ipw_FtmChannelNotification(Channel)     Pwm_Notification((Pwm_ChannelType)(Channel))
#endif /* PWM_NOTIFICATION_SUPPORTED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_IPW_NOTIF_H */
