/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.8.0
*   Build Version        : S32K3_RTD_0_8_0_D2305_ASR_REL_4_7_REV_0000_20230524
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
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

/**
* @file         CanTrcv_tja1145a_Ip_Regs.h
* @version      0.8.0
*
* @brief        AUTOSAR CanTrcv_43_tja1145a - module interface.
*
* @addtogroup   CanTrcv_tja1145a_Driver
* @{
*/

#ifndef TJA1145A_MAP_H
#define TJA1145A_MAP_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced
* The register header defines macros for all bitfields to be used by the application code.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
#define TJA1145A_VENDOR_ID_REGMAP						43
#define TJA1145A_MODULE_ID_REGMAP                   	70
#define TJA1145A_AR_RELEASE_MAJOR_VERSION_REGMAP     	4
#define TJA1145A_AR_RELEASE_MINOR_VERSION_REGMAP     	7
#define TJA1145A_AR_RELEASE_REVISION_VERSION_REGMAP  	0
#define TJA1145A_SW_MAJOR_VERSION_REGMAP             	0
#define TJA1145A_SW_MINOR_VERSION_REGMAP             	8
#define TJA1145A_SW_PATCH_VERSION_REGMAP             	0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/******************************************************************************/
/* MODE_CONTROL - Type: RW                                                    */
/******************************************************************************/

#define TJA1145A_MODE_CONTROL_ADDR        0x01U
#define TJA1145A_MODE_CONTROL_DEFAULT     0x04U

/**
 * mode control
 */
#define TJA1145A_M_MC_MASK                0x07U

/**
 * mode control
 */
#define TJA1145A_M_MC_SHIFT               0x00U

/**
 * Sleep mode
 */
#define TJA1145A_M_MC_SLEEP_MODE          (0x01U << TJA1145A_M_MC_SHIFT)
/**
 * Standby mode
 */
#define TJA1145A_M_MC_STANDBY_MODE        (0x04U << TJA1145A_M_MC_SHIFT)
/**
 * Normal mode
 */
#define TJA1145A_M_MC_NORMAL_MODE         (0x07U << TJA1145A_M_MC_SHIFT)

/******************************************************************************/
/* MAIN_STATUS - Type: R                                                      */
/******************************************************************************/

#define TJA1145A_MAIN_STATUS_ADDR         0x03U
#define TJA1145A_MAIN_STATUS_DEFAULT      0x20U

/**
 * Normal mode status
 */
#define TJA1145A_M_NMS_MASK               0x20U
/**
 * overtemperature warning status
 */
#define TJA1145A_M_OTWS_MASK              0x40U
/**
 * Sleep mode transition status
 */
#define TJA1145A_M_FSMS_MASK              0x80U

/**
 * Normal mode status
 */
#define TJA1145A_M_NMS_SHIFT              0x05U
/**
 * overtemperature warning status
 */
#define TJA1145A_M_OTWS_SHIFT             0x06U
/**
 * Sleep mode transition status
 */
#define TJA1145A_M_FSMS_SHIFT             0x07U

/**
 * TJA1145AA has entered Normal mode (after power-up)
 */
#define TJA1145A_M_NMS_WAS_OR_IS_IN_NORMAL_MODE (0x00U << TJA1145A_M_NMS_SHIFT)
/**
 * TJA1145AA has not yet been in Normal mode since recent power-up
 */
#define TJA1145A_M_NMS_HAS_NOT_BEEN_IN_NORMAL_MODE (0x01U << TJA1145A_M_NMS_SHIFT)

/**
 * IC temperature below overtemperature warning threshold
 */
#define TJA1145A_M_OTWS_TEMPERATURE_BELOW_WARNING_THRESHOLD (0x00U << TJA1145A_M_OTWS_SHIFT)
/**
 * IC temperature above overtemperature warning threshold
 */
#define TJA1145A_M_OTWS_TEMPERATURE_ABOVE_WARNING_THRESHOLD (0x01U << TJA1145A_M_OTWS_SHIFT)

/**
 * transition to Sleep mode triggered by an SPI command
 */
#define TJA1145A_M_FSMS_SLEEP_MODE_REASON_SPI_COMMAND (0x00U << TJA1145A_M_FSMS_SHIFT)
/**
 * an undervoltage on VCC and/or VIO forced a transition to Sleep mode
 */
#define TJA1145A_M_FSMS_SLEEP_MODE_REASON_UNDERVOLTAGE (0x01U << TJA1145A_M_FSMS_SHIFT)

/******************************************************************************/
/* SYSTEM_EVENT_ENABLE - Type: RW                                             */
/******************************************************************************/

#define TJA1145A_SYSTEM_EVENT_ENABLE_ADDR 		0x04U
#define TJA1145A_SYSTEM_EVENT_ENABLE_DEFAULT 	0x00U

/**
 * SPI failure enable
 */
#define TJA1145A_M_SPIFE_MASK             0x02U
/**
 * overtemperature warning enable
 */
#define TJA1145A_M_OTWE_MASK              0x04U

/**
 * SPI failure enable
 */
#define TJA1145A_M_SPIFE_SHIFT            0x01U
/**
 * overtemperature warning enable
 */
#define TJA1145A_M_OTWE_SHIFT             0x02U

/**
 * SPI failure detection disabled
 */
#define TJA1145A_M_SPIFE_DISABLED         (0x00U << TJA1145A_M_SPIFE_SHIFT)
/**
 * SPI failure detection enabled
 */
#define TJA1145A_M_SPIFE_ENABLED          (0x01U << TJA1145A_M_SPIFE_SHIFT)

/**
 * overtemperature warning disabled
 */
#define TJA1145A_M_OTWE_DISABLED          (0x00U << TJA1145A_M_OTWE_SHIFT)
/**
 * overtemperature warning enabled
 */
#define TJA1145A_M_OTWE_ENABLED           (0x01U << TJA1145A_M_OTWE_SHIFT)

/******************************************************************************/
/* MEMORY_0 - Type: RW                                                        */
/******************************************************************************/

#define TJA1145A_MEMORY_0_ADDR            0x06U
#define TJA1145A_MEMORY_0_DEFAULT         0x00U

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_MASK               0xFFU

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_SHIFT              0x00U

/******************************************************************************/
/* MEMORY_1 - Type: RW                                                        */
/******************************************************************************/

#define TJA1145A_MEMORY_1_ADDR            0x07U
#define TJA1145A_MEMORY_1_DEFAULT         0x00U

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_MASK               0xFFU

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_SHIFT              0x00U

/******************************************************************************/
/* MEMORY_2 - Type: RW                                                        */
/******************************************************************************/

#define TJA1145A_MEMORY_2_ADDR            0x08U
#define TJA1145A_MEMORY_2_DEFAULT         0x00U

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_MASK               0xFFU

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_SHIFT              0x00U

/******************************************************************************/
/* MEMORY_3 - Type: RW                                                        */
/******************************************************************************/

#define TJA1145A_MEMORY_3_ADDR            0x09U
#define TJA1145A_MEMORY_3_DEFAULT         0x00U

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_MASK               0xFFU

/**
 * General purpose memory
 */
#define TJA1145A_M_GPM_SHIFT              0x00U

/******************************************************************************/
/* LOCK_CONTROL - Type: RW                                                    */
/******************************************************************************/

#define TJA1145A_LOCK_CONTROL_ADDR        0x0AU
#define TJA1145A_LOCK_CONTROL_DEFAULT     0x00U

/**
 * lock control 0: address area 0x06 to 0x09 - general-purpose memory
 */
#define TJA1145A_M_LK0C_MASK              0x01U
/**
 * lock control 1: address area 0x10 to 0x1F
 */
#define TJA1145A_M_LK1C_MASK              0x02U
/**
 * lock control 2: address area 0x20 to 0x2F - transceiver control and partial networking
 */
#define TJA1145A_M_LK2C_MASK              0x04U
/**
 * lock control 3: address area 0x30 to 0x3F
 */
#define TJA1145A_M_LK3C_MASK              0x08U
/**
 * lock control 4: address area 0x40 to 0x4F - WAKE pin control
 */
#define TJA1145A_M_LK4C_MASK              0x10U
/**
 * lock control 5: address area 0x50 to 0x5F
 */
#define TJA1145A_M_LK5C_MASK              0x20U
/**
 * lock control 6: address area 0x68 to 0x6F
 */
#define TJA1145A_M_LK6C_MASK              0x40U

/**
 * lock control 0: address area 0x06 to 0x09 - general-purpose memory
 */
#define TJA1145A_M_LK0C_SHIFT             0x00U
/**
 * lock control 1: address area 0x10 to 0x1F
 */
#define TJA1145A_M_LK1C_SHIFT             0x01U
/**
 * lock control 2: address area 0x20 to 0x2F - transceiver control and partial networking
 */
#define TJA1145A_M_LK2C_SHIFT             0x02U
/**
 * lock control 3: address area 0x30 to 0x3F
 */
#define TJA1145A_M_LK3C_SHIFT             0x03U
/**
 * lock control 4: address area 0x40 to 0x4F - WAKE pin control
 */
#define TJA1145A_M_LK4C_SHIFT             0x04U
/**
 * lock control 5: address area 0x50 to 0x5F
 */
#define TJA1145A_M_LK5C_SHIFT             0x05U
/**
 * lock control 6: address area 0x68 to 0x6F
 */
#define TJA1145A_M_LK6C_SHIFT             0x06U

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK0C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK0C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK0C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK0C_SHIFT)

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK1C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK1C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK1C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK1C_SHIFT)

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK2C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK2C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK2C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK2C_SHIFT)

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK3C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK3C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK3C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK3C_SHIFT)

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK4C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK4C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK4C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK4C_SHIFT)

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK5C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK5C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK5C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK5C_SHIFT)

/**
 * SPI write access enabled
 */
#define TJA1145A_M_LK6C_WRITING_ENABLED   (0x00U << TJA1145A_M_LK6C_SHIFT)
/**
 * SPI write access disabled
 */
#define TJA1145A_M_LK6C_WRITING_DISABLED  (0x01U << TJA1145A_M_LK6C_SHIFT)

/******************************************************************************/
/* CAN_CONTROL - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_CAN_CONTROL_ADDR         0x20U
#define TJA1145A_CAN_CONTROL_DEFAULT      0x00U

/**
 * CAN transceiver operating mode selection
 */
#define TJA1145A_FS_I_CMC_MASK            0x03U
/**
 * CAN selective wake-up; when enabled, node is part of a partial network
 */
#define TJA1145A_FS_I_CPNC_MASK           0x10U
/**
 * CAN partial networking configuration
 */
#define TJA1145A_FS_I_PNCOK_MASK          0x20U
/**
 * CAN FD control(TJA1145AATK/FD only; otherwise ignored)
 */
#define TJA1145A_FS_I_CFDC_MASK           0x40U

/**
 * CAN transceiver operating mode selection
 */
#define TJA1145A_FS_I_CMC_SHIFT           0x00U
/**
 * CAN selective wake-up; when enabled, node is part of a partial network
 */
#define TJA1145A_FS_I_CPNC_SHIFT          0x04U
/**
 * CAN partial networking configuration
 */
#define TJA1145A_FS_I_PNCOK_SHIFT         0x05U
/**
 * CAN FD control(TJA1145AATK/FD only; otherwise ignored)
 */
#define TJA1145A_FS_I_CFDC_SHIFT          0x06U

/**
 * Offline mode
 */
#define TJA1145A_FS_I_CMC_OFFLINE_MODE    (0x00U << TJA1145A_FS_I_CMC_SHIFT)
/**
 * Active mode (when the TJA1145AA is in Normal mode); Vcc  undervoltage detection active; transition to Active mode,
 * and remaining in Active mode, requires Vcc above undervoltage threshold
 */
#define TJA1145A_FS_I_CMC_ACTIVE_MODE__01 (0x01U << TJA1145A_FS_I_CMC_SHIFT)
/**
 * Active mode (while TJA1145AA is in Normal mode); Vcc undervoltage detection inactive; transition to Active mode
 * requires Vcc above undervoltage threshold
 */
#define TJA1145A_FS_I_CMC_ACTIVE_MODE__10 (0x02U << TJA1145A_FS_I_CMC_SHIFT)
/**
 * Listen-only mode
 */
#define TJA1145A_FS_I_CMC_LISTEN_ONLY_MODE (0x03U << TJA1145A_FS_I_CMC_SHIFT)

/**
 * disable CAN selective wake-up
 */
#define TJA1145A_FS_I_CPNC_SELECTIVE_WAKE_DISABLED (0x00U << TJA1145A_FS_I_CPNC_SHIFT)
/**
 * enable CAN selective wake-up
 */
#define TJA1145A_FS_I_CPNC_SELECTIVE_WAKE_ENABLED (0x01U << TJA1145A_FS_I_CPNC_SHIFT)

/**
 * partial networking registers configured successfully
 */
#define TJA1145A_FS_I_PNCOK_PN_CONFIGURED	(0x01U << TJA1145A_FS_I_PNCOK_SHIFT)

/**
 * CAN FD tolerance disabled
 */
#define TJA1145A_FS_I_CFDC_FD_DISABLED (0x00U << TJA1145A_FS_I_CFDC_SHIFT)
/**
 * CAN FD tolerance enabled
 */
#define TJA1145A_FS_I_CFDC_FD_ENABLED (0x01U << TJA1145A_FS_I_CFDC_SHIFT)

/******************************************************************************/
/* TRANSCEIVER_STATUS - Type: R                                                */
/******************************************************************************/

#define TJA1145A_TRANSCEIVER_STATUS_ADDR   0x22U
#define TJA1145A_TRANSCEIVER_STATUS_DEFAULT 0x48U

/**
 * CAN failure status
 */
#define TJA1145A_FS_I_CFS_MASK            0x01U
/**
 * Vcc supply voltage status
 */
#define TJA1145A_FS_I_VCS_MASK            0x02U
/**
 * CAN-bus silence status
 */
#define TJA1145A_FS_I_CBSS_MASK           0x08U
/**
 * CAN oscillator status
 */
#define TJA1145A_FS_I_COSCS_MASK          0x10U
/**
 * CAN partial networking status
 */
#define TJA1145A_FS_I_CPNS_MASK           0x20U
/**
 * CAN partial networking error status
 */
#define TJA1145A_FS_I_CPNERR_MASK         0x40U
/**
 * CAN transceiver status
 */
#define TJA1145A_FS_I_CTS_MASK            0x80U

/**
 * CAN failure status
 */
#define TJA1145A_FS_I_CFS_SHIFT           0x00U
/**
 * Vcc supply voltage status
 */
#define TJA1145A_FS_I_VCS_SHIFT           0x01U
/**
 * CAN-bus silence status
 */
#define TJA1145A_FS_I_CBSS_SHIFT          0x03U
/**
 * CAN oscillator status
 */
#define TJA1145A_FS_I_COSCS_SHIFT         0x04U
/**
 * CAN partial networking status
 */
#define TJA1145A_FS_I_CPNS_SHIFT          0x05U
/**
 * CAN partial networking error status
 */
#define TJA1145A_FS_I_CPNERR_SHIFT        0x06U
/**
 * CAN transceiver status
 */
#define TJA1145A_FS_I_CTS_SHIFT           0x07U

/**
 * no TXD dominant time-out event detected
 */
#define TJA1145A_FS_I_CFS_NO_TIME_OUT_EVENT_DETECTED (0x00U << TJA1145A_FS_I_CFS_SHIFT)
/**
 * CAN transmitter disabled due to a TXD dominant time-out event
 */
#define TJA1145A_FS_I_CFS_TIME_OUT_EVENT_DETECTED (0x01U << TJA1145A_FS_I_CFS_SHIFT)

/**
 * Vcc is above undervoltage detection threshold
 */
#define TJA1145A_FS_I_VCS_ABOVE_UNDERVOLTAGE_THRESHOLD (0x00U << TJA1145A_FS_I_VCS_SHIFT)
/**
 * Vcc is below undervoltage detection threshold
 */
#define TJA1145A_FS_I_VCS_BELOW_UNDERVOLTAGE_THRESHOLD (0x01U << TJA1145A_FS_I_VCS_SHIFT)

/**
 * CAN-bus active (communication detected on bus)
 */
#define TJA1145A_FS_I_CBSS_CAN_BUS_ACTIVE (0x00U << TJA1145A_FS_I_CBSS_SHIFT)
/**
 * CAN-bus inactive (for longer than tto(silence))
 */
#define TJA1145A_FS_I_CBSS_CAN_BUS_INACTIVE (0x01U << TJA1145A_FS_I_CBSS_SHIFT)

/**
 * CAN partial networking oscillator  unning at target frequency
 */
#define TJA1145A_FS_I_COSCS_NOT_AT_TARGET_FREQUENCY (0x00U << TJA1145A_FS_I_COSCS_SHIFT)
/**
 * CAN partial networking oscillator running at target frequency
 */
#define TJA1145A_FS_I_COSCS_AT_TARGET_FREQUENCY (0x01U << TJA1145A_FS_I_COSCS_SHIFT)

/**
 * CAN partial networking configuration error detected (PNCOK = 0)
 */
#define TJA1145A_FS_I_CPNS_CONFIGURATION_ERROR_DETECTED (0x00U << TJA1145A_FS_I_CPNS_SHIFT)
/**
 * CAN partial networking configuration OK (PNCOK = 1)
 */
#define TJA1145A_FS_I_CPNS_CONFIGURATION_OK (0x01U << TJA1145A_FS_I_CPNS_SHIFT)

/**
 * no CAN partial networking error detected (PNFDE = 0 AND PNCOK = 1)
 */
#define TJA1145A_FS_I_CPNERR_NO_ERROR_DETECTED (0x00U << TJA1145A_FS_I_CPNERR_SHIFT)
/**
 * CAN partial networking error detected (PNFDE = 1 OR PNCOK = 0; wake-up via standard wake-up pattern only)
 */
#define TJA1145A_FS_I_CPNERR_ERROR_DETECTED (0x01U << TJA1145A_FS_I_CPNERR_SHIFT)

/**
 * CAN transceiver not in Active mode
 */
#define TJA1145A_FS_I_CTS_NOT_IN_ACTIVE_MODE (0x00U << TJA1145A_FS_I_CTS_SHIFT)
/**
 * CAN transceiver in Active mode
 */
#define TJA1145A_FS_I_CTS_IN_ACTIVE_MODE  (0x01U << TJA1145A_FS_I_CTS_SHIFT)

/******************************************************************************/
/* TRANSCEIVER_EVENT_ENABLE - Type: RW                                         */
/******************************************************************************/

#define TJA1145A_TRANSCEIVER_EVENT_ENABLE_ADDR			0x23U
#define TJA1145A_TRANSCEIVER_EVENT_ENABLE_DEFAULT		0x00U

/**
 * CAN wake-up enable
 */
#define TJA1145A_FS_I_CWE_MASK            0x01U
/**
 * CAN failure enable
 */
#define TJA1145A_FS_I_CFE_MASK            0x02U
/**
 * CAN-bus silence enable
 */
#define TJA1145A_FS_I_CBSE_MASK           0x10U

/**
 * CAN wake-up enable
 */
#define TJA1145A_FS_I_CWE_SHIFT           0x00U
/**
 * CAN failure enable
 */
#define TJA1145A_FS_I_CFE_SHIFT           0x01U
/**
 * CAN-bus silence enable
 */
#define TJA1145A_FS_I_CBSE_SHIFT          0x04U

/**
 * CAN wake-up detection disabled
 */
#define TJA1145A_FS_I_CWE_DISABLED        (0x00U << TJA1145A_FS_I_CWE_SHIFT)
/**
 * CAN wake-up detection enabled
 */
#define TJA1145A_FS_I_CWE_ENABLED         (0x01U << TJA1145A_FS_I_CWE_SHIFT)

/**
 * CAN failure detection disabled
 */
#define TJA1145A_FS_I_CFE_DISABLED        (0x00U << TJA1145A_FS_I_CFE_SHIFT)
/**
 * CAN failure detection enabled
 */
#define TJA1145A_FS_I_CFE_ENABLED         (0x01U << TJA1145A_FS_I_CFE_SHIFT)

/**
 * CAN-bus silence detection disabled
 */
#define TJA1145A_FS_I_CBSE_DISABLED       (0x00U << TJA1145A_FS_I_CBSE_SHIFT)
/**
 * CAN-bus silence detection enabled
 */
#define TJA1145A_FS_I_CBSE_ENABLED        (0x01U << TJA1145A_FS_I_CBSE_SHIFT)

/******************************************************************************/
/* DATA_RATE - Type: RW                                                       */
/******************************************************************************/

#define TJA1145A_DATA_RATE_ADDR           0x26U
#define TJA1145A_DATA_RATE_DEFAULT        0x05U

/**
 * CAN data rate selection
 */
#define TJA1145A_FS_I_CDR_MASK            0x07U

/**
 * CAN data rate selection
 */
#define TJA1145A_FS_I_CDR_SHIFT           0x00U

/**
 * 50 kbit/s
 */
#define TJA1145A_FS_I_CDR_50_KBIT_S       (0x00U << TJA1145A_FS_I_CDR_SHIFT)
/**
 * 100 kbit/s
 */
#define TJA1145A_FS_I_CDR_100_KBIT_S      (0x01U << TJA1145A_FS_I_CDR_SHIFT)
/**
 * 125 kbit/s
 */
#define TJA1145A_FS_I_CDR_125_KBIT_S      (0x02U << TJA1145A_FS_I_CDR_SHIFT)
/**
 * 250 kbit/s
 */
#define TJA1145A_FS_I_CDR_250_KBIT_S      (0x03U << TJA1145A_FS_I_CDR_SHIFT)
/**
 * 500 kbit/s
 */
#define TJA1145A_FS_I_CDR_500_KBIT_S      (0x05U << TJA1145A_FS_I_CDR_SHIFT)
/**
 * 1000 kbit/s
 */
#define TJA1145A_FS_I_CDR_1000_KBIT_S     (0x07U << TJA1145A_FS_I_CDR_SHIFT)

/******************************************************************************/
/* IDENTIFIER_0 - Type: RW                                                    */
/******************************************************************************/

#define TJA1145A_IDENTIFIER_0_ADDR        0x27U
#define TJA1145A_IDENTIFIER_0_DEFAULT     0x00U

/**
 * bits ID07 to ID00 of the extended frame format
 */
#define TJA1145A_FS_I_ID0_MASK             0xFFU

/**
 * bits ID07 to ID00 of the extended frame format
 */
#define TJA1145A_FS_I_ID0_SHIFT            0x00U

/******************************************************************************/
/* IDENTIFIER_1 - Type: RW                                                    */
/******************************************************************************/

#define TJA1145A_IDENTIFIER_1_ADDR        0x28U
#define TJA1145A_IDENTIFIER_1_DEFAULT     0x00U

/******************************************************************************/
/* IDENTIFIER_2 - Type: RW                                                    */
/******************************************************************************/

#define TJA1145A_IDENTIFIER_2_ADDR        0x29U
#define TJA1145A_IDENTIFIER_2_DEFAULT     0x00U

/******************************************************************************/
/* IDENTIFIER_3 - Type: RW                                                    */
/******************************************************************************/

#define TJA1145A_IDENTIFIER_3_ADDR        0x2AU
#define TJA1145A_IDENTIFIER_3_DEFAULT     0x00U

/******************************************************************************/
/* MASK_0 - Type: RW                                                          */
/******************************************************************************/

#define TJA1145A_MASK_0_ADDR              0x2BU
#define TJA1145A_MASK_0_DEFAULT           0x00U

/**
 * ID mask bits 7 to 0 of the extended frame format
 */
#define TJA1145A_FS_I_M_MASK              0xFFU

/**
 * ID mask bits 7 to 0 of the extended frame format
 */
#define TJA1145A_FS_I_M_SHIFT             0x00U

/******************************************************************************/
/* MASK_1 - Type: RW                                                          */
/******************************************************************************/

#define TJA1145A_MASK_1_ADDR              0x2CU
#define TJA1145A_MASK_1_DEFAULT           0x00U

/******************************************************************************/
/* MASK_2 - Type: RW                                                          */
/******************************************************************************/

#define TJA1145A_MASK_2_ADDR              0x2DU
#define TJA1145A_MASK_2_DEFAULT           0x00U

/******************************************************************************/
/* MASK_3 - Type: RW                                                          */
/******************************************************************************/

#define TJA1145A_MASK_3_ADDR              0x2EU
#define TJA1145A_MASK_3_DEFAULT           0x00U

/******************************************************************************/
/* FRAME_CONTROL - Type: RW                                                   */
/******************************************************************************/

#define TJA1145A_FRAME_CONTROL_ADDR       0x2FU
#define TJA1145A_FRAME_CONTROL_DEFAULT    0x40U

/**
 * number of data bytes expected in a CAN frame
 */
#define TJA1145A_FS_I_DLC_MASK            0x0FU
/**
 * partial networking data mask
 */
#define TJA1145A_FS_I_PNDM_MASK           0x40U
/**
 * identifier format
 */
#define TJA1145A_FS_I_IDE_MASK            0x80U

/**
 * number of data bytes expected in a CAN frame
 */
#define TJA1145A_FS_I_DLC_SHIFT           0x00U
/**
 * partial networking data mask
 */
#define TJA1145A_FS_I_PNDM_SHIFT          0x06U
/**
 * identifier format
 */
#define TJA1145A_FS_I_IDE_SHIFT           0x07U

/**
 * 0
 */
#define TJA1145A_FS_I_DLC_0               (0x00U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 1
 */
#define TJA1145A_FS_I_DLC_1               (0x01U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 2
 */
#define TJA1145A_FS_I_DLC_2               (0x02U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 3
 */
#define TJA1145A_FS_I_DLC_3               (0x03U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 4
 */
#define TJA1145A_FS_I_DLC_4               (0x04U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 5
 */
#define TJA1145A_FS_I_DLC_5               (0x05U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 6
 */
#define TJA1145A_FS_I_DLC_6               (0x06U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 7
 */
#define TJA1145A_FS_I_DLC_7               (0x07U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * 8
 */
#define TJA1145A_FS_I_DLC_8               (0x08U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1001__8_BYTES_EXPECTED_ (0x09U << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1010__8_BYTES_EXPECTED_ (0x0AU << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1011__8_BYTES_EXPECTED_ (0x0BU << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1100__8_BYTES_EXPECTED_ (0x0CU << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1101__8_BYTES_EXPECTED_ (0x0DU << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1110__8_BYTES_EXPECTED_ (0x0EU << TJA1145A_FS_I_DLC_SHIFT)
/**
 * tolerated, 8 bytes expected
 */
#define TJA1145A_FS_I_DLC_1111__8_BYTES_EXPECTED_ (0x0FU << TJA1145A_FS_I_DLC_SHIFT)

/**
 * data length code and data field are _don_t care_ for wake-up
 */
#define TJA1145A_FS_I_PNDM_DLC___DATA__DON_T_CARE_ (0x00U << TJA1145A_FS_I_PNDM_SHIFT)
/**
 * data length code and data field are evaluated at wake-up
 */
#define TJA1145A_FS_I_PNDM_DLC___DATA_EVALUATED (0x01U << TJA1145A_FS_I_PNDM_SHIFT)

/**
 * standard frame format (11-bit)
 */
#define TJA1145A_FS_I_IDE_STANDARD__11_BIT_ (0x00U << TJA1145A_FS_I_IDE_SHIFT)
/**
 * extended frame format (29-bit)
 */
#define TJA1145A_FS_I_IDE_EXTENDED__29_BIT_ (0x01U << TJA1145A_FS_I_IDE_SHIFT)

/******************************************************************************/
/* DATA_MASK_0 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_0_ADDR         0x68U
#define TJA1145A_DATA_MASK_0_DEFAULT      0xFFU

/**
 * data mask 0 configuration
 */
#define TJA1145A_FS_I_DM0_MASK            0xFFU

/**
 * data mask 0 configuration
 */
#define TJA1145A_FS_I_DM0_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_1 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_1_ADDR         0x69U
#define TJA1145A_DATA_MASK_1_DEFAULT      0xFFU

/**
 * data mask 1 configuration
 */
#define TJA1145A_FS_I_DM1_MASK            0xFFU

/**
 * data mask 1 configuration
 */
#define TJA1145A_FS_I_DM1_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_2 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_2_ADDR         0x6AU
#define TJA1145A_DATA_MASK_2_DEFAULT      0xFFU

/**
 * data mask 2 configuration
 */
#define TJA1145A_FS_I_DM2_MASK            0xFFU

/**
 * data mask 2 configuration
 */
#define TJA1145A_FS_I_DM2_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_3 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_3_ADDR         0x6BU
#define TJA1145A_DATA_MASK_3_DEFAULT      0xFFU

/**
 * data mask 3 configuration
 */
#define TJA1145A_FS_I_DM3_MASK            0xFFU

/**
 * data mask 3 configuration
 */
#define TJA1145A_FS_I_DM3_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_4 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_4_ADDR         0x6CU
#define TJA1145A_DATA_MASK_4_DEFAULT      0xFFU

/**
 * data mask 4 configuration
 */
#define TJA1145A_FS_I_DM4_MASK            0xFFU

/**
 * data mask 4 configuration
 */
#define TJA1145A_FS_I_DM4_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_5 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_5_ADDR         0x6DU
#define TJA1145A_DATA_MASK_5_DEFAULT      0xFFU

/**
 * data mask 5 configuration
 */
#define TJA1145A_FS_I_DM5_MASK            0xFFU

/**
 * data mask 5 configuration
 */
#define TJA1145A_FS_I_DM5_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_6 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_6_ADDR         0x6EU
#define TJA1145A_DATA_MASK_6_DEFAULT      0xFFU

/**
 * data mask 6 configuration
 */
#define TJA1145A_FS_I_DM6_MASK            0xFFU

/**
 * data mask 6 configuration
 */
#define TJA1145A_FS_I_DM6_SHIFT           0x00U

/******************************************************************************/
/* DATA_MASK_7 - Type: RW                                                     */
/******************************************************************************/

#define TJA1145A_DATA_MASK_7_ADDR         0x6FU
#define TJA1145A_DATA_MASK_7_DEFAULT      0xFFU

/**
 * data mask 7 configuration
 */
#define TJA1145A_FS_I_DM7_MASK            0xFFU

/**
 * data mask 7 configuration
 */
#define TJA1145A_FS_I_DM7_SHIFT           0x00U

/******************************************************************************/
/* WAKE_PIN_STATUS - Type: R                                                  */
/******************************************************************************/

#define TJA1145A_WAKE_PIN_STATUS_ADDR     0x4BU
#define TJA1145A_WAKE_PIN_STATUS_DEFAULT  0x00U

/**
 * WAKE pin status
 */
#define TJA1145A_FS_WPVS_MASK             0x02U

/**
 * WAKE pin status
 */
#define TJA1145A_FS_WPVS_SHIFT            0x01U

/**
 * voltage on WAKE pin below switching threshold (Vth(sw))
 */
#define TJA1145A_FS_WPVS_BELOW_SWITCHING_THRESHOLD (0x00U << TJA1145A_FS_WPVS_SHIFT)
/**
 * voltage on WAKE pin above switching threshold (Vth(sw))
 */
#define TJA1145A_FS_WPVS_ABOVE_SWITCHING_THRESHOLD (0x01U << TJA1145A_FS_WPVS_SHIFT)

/******************************************************************************/
/* WAKE_PIN_ENABLE - Type: RW                                                 */
/******************************************************************************/

#define TJA1145A_WAKE_PIN_ENABLE_ADDR     0x4CU
#define TJA1145A_WAKE_PIN_ENABLE_DEFAULT  0x00U

/**
 * WAKE pin falling-edge enable
 */
#define TJA1145A_FS_WPFE_MASK             0x01U
/**
 * WAKE pin rising-edge enable
 */
#define TJA1145A_FS_WPRE_MASK             0x02U

/**
 * WAKE pin falling-edge enable
 */
#define TJA1145A_FS_WPFE_SHIFT            0x00U
/**
 * WAKE pin rising-edge enable
 */
#define TJA1145A_FS_WPRE_SHIFT            0x01U

/**
 * falling-edge detection on WAKE pin disabled
 */
#define TJA1145A_FS_WPFE_FALLING_EDGE_DISABLED (0x00U << TJA1145A_FS_WPFE_SHIFT)
/**
 * falling-edge detection on WAKE pin enabled
 */
#define TJA1145A_FS_WPFE_FALLING_EDGE_ENABLED (0x01U << TJA1145A_FS_WPFE_SHIFT)

/**
 * rising-edge detection on WAKE pin disabled
 */
#define TJA1145A_FS_WPRE_RISING_EDGE_DISABLED (0x00U << TJA1145A_FS_WPRE_SHIFT)
/**
 * rising-edge detection on WAKE pin enabled
 */
#define TJA1145A_FS_WPRE_RISING_EDGE_ENABLED (0x01U << TJA1145A_FS_WPRE_SHIFT)

/******************************************************************************/
/* EVENT_CAPTURE_STATUS - Type: R                                             */
/******************************************************************************/

#define TJA1145A_EVENT_CAPTURE_STATUS_ADDR 		0x60U
#define TJA1145A_EVENT_CAPTURE_STATUS_DEFAULT 	0x01U

/**
 * system event
 */
#define TJA1145A_FS_SYSE_MASK             0x01U
/**
 * transceiver event
 */
#define TJA1145A_FS_TRXE_MASK             0x04U
/**
 * WAKE pin event
 */
#define TJA1145A_FS_WPE_MASK              0x08U

/**
 * system event
 */
#define TJA1145A_FS_SYSE_SHIFT            0x00U
/**
 * transceiver event
 */
#define TJA1145A_FS_TRXE_SHIFT            0x02U
/**
 * WAKE pin event
 */
#define TJA1145A_FS_WPE_SHIFT             0x03U

/**
 * no pending system event
 */
#define TJA1145A_FS_SYSE_NO_PENDING_EVENTS (0x00U << TJA1145A_FS_SYSE_SHIFT)
/**
 * system event pending at address 0x61
 */
#define TJA1145A_FS_SYSE_PENDING_EVENT_S_ (0x01U << TJA1145A_FS_SYSE_SHIFT)

/**
 * no pending transceiver event
 */
#define TJA1145A_FS_TRXE_NO_PENDING_EVENTS (0x00U << TJA1145A_FS_TRXE_SHIFT)
/**
 * transceiver event pending at address 0x63
 */
#define TJA1145A_FS_TRXE_PENDING_EVENT_S_ (0x01U << TJA1145A_FS_TRXE_SHIFT)

/**
 * no pending WAKE pin event
 */
#define TJA1145A_FS_WPE_NO_PENDING_EVENTS (0x00U << TJA1145A_FS_WPE_SHIFT)
/**
 * WAKE pin event pending at address 0x64
 */
#define TJA1145A_FS_WPE_PENDING_EVENT_S_  (0x01U << TJA1145A_FS_WPE_SHIFT)

/******************************************************************************/
/* SYSTEM_EVENT_STATUS - Type: RW                                             */
/******************************************************************************/

#define TJA1145A_SYSTEM_EVENT_STATUS_ADDR 		0x61U
#define TJA1145A_SYSTEM_EVENT_STATUS_DEFAULT 	0x10U

/**
 * SPI failure
 */
#define TJA1145A_FS_SPIF_MASK             0x02U
/**
 * overtemperature warning
 */
#define TJA1145A_FS_OTW_MASK              0x04U
/**
 * power-on
 */
#define TJA1145A_FS_PO_MASK               0x10U

/**
 * SPI failure
 */
#define TJA1145A_FS_SPIF_SHIFT            0x01U
/**
 * overtemperature warning
 */
#define TJA1145A_FS_OTW_SHIFT             0x02U
/**
 * power-on
 */
#define TJA1145A_FS_PO_SHIFT              0x04U

/**
 * SPI failure detected
 */
#define TJA1145A_FS_SPIF_SPI_FAILURE_EVENT (0x01U << TJA1145A_FS_SPIF_SHIFT)

/**
 * the global chip temperature has exceeded the overtemperature warning threshold, T_th(warn)otp
 */
#define TJA1145A_FS_OTW_OVERTEMP_WARNING_EVENT (0x01U << TJA1145A_FS_OTW_SHIFT)

/**
 * the TJA1145AA has left Off mode after battery power-on
 */
#define TJA1145A_FS_PO_POWER_ON_EVENT     (0x01U << TJA1145A_FS_PO_SHIFT)

/******************************************************************************/
/* TRANSCEIVER_EVENT_STATUS - Type: RW                                         */
/******************************************************************************/

#define TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR 		0x63U
#define TJA1145A_TRANSCEIVER_EVENT_STATUS_DEFAULT 	0x00U

/**
 * CAN wake-up
 */
#define TJA1145A_FS_CW_MASK               0x01U
/**
 * CAN failure
 */
#define TJA1145A_FS_CF_MASK               0x02U
/**
 * CAN-bus status
 */
#define TJA1145A_FS_CBS_MASK              0x10U
/**
 * partial networking frame detection error
 */
#define TJA1145A_FS_PNFDE_MASK            0x20U

/**
 * CAN wake-up
 */
#define TJA1145A_FS_CW_SHIFT              0x00U
/**
 * CAN failure
 */
#define TJA1145A_FS_CF_SHIFT              0x01U
/**
 * CAN-bus status
 */
#define TJA1145A_FS_CBS_SHIFT             0x04U
/**
 * partial networking frame detection error
 */
#define TJA1145A_FS_PNFDE_SHIFT           0x05U

/**
 * CAN wake-up event detected
 */
#define TJA1145A_FS_CW_CAN_WAKE_UP_EVENT  (0x01U << TJA1145A_FS_CW_SHIFT)

/**
 * CAN failure event detected
 */
#define TJA1145A_FS_CF_CAN_FAILURE_EVENT  (0x01U << TJA1145A_FS_CF_SHIFT)

/**
 * no activity on CAN-bus for tto(silence)
 */
#define TJA1145A_FS_CBS_BUS_SILENCE_EVENT (0x01U << TJA1145A_FS_CBS_SHIFT)

/**
 * partial networking frame detection error detected
 */
#define TJA1145A_FS_PNFDE_FRAME_ERROR_EVENT (0x01U << TJA1145A_FS_PNFDE_SHIFT)

/******************************************************************************/
/* WAKE_PIN_EVENT_STATUS - Type: RW                                           */
/******************************************************************************/

#define TJA1145A_WAKE_PIN_EVENT_STATUS_ADDR 		0x64U
#define TJA1145A_WAKE_PIN_EVENT_STATUS_DEFAULT 		0x00U

/**
 * WAKE pin falling edge
 */
#define TJA1145A_FS_WPF_MASK              0x01U
/**
 * WAKE pin rising edge
 */
#define TJA1145A_FS_WPR_MASK              0x02U

/**
 * WAKE pin falling edge
 */
#define TJA1145A_FS_WPF_SHIFT             0x00U
/**
 * WAKE pin rising edge
 */
#define TJA1145A_FS_WPR_SHIFT             0x01U

/**
 * falling edge detected on WAKE pin
 */
#define TJA1145A_FS_WPF_FALLING_EDGE_EVENT (0x01U << TJA1145A_FS_WPF_SHIFT)

/**
 * rising edge detected on WAKE pin
 */
#define TJA1145A_FS_WPR_RISING_EDGE_EVENT (0x01U << TJA1145A_FS_WPR_SHIFT)

/******************************************************************************/
/* IDENTIFICATION - Type: R                                                   */
/******************************************************************************/

#define TJA1145A_IDENTIFICATION_ADDR      0x7EU
#define TJA1145A_IDENTIFICATION_DEFAULT   0x74U

/**
 * device identification code
 */
#define TJA1145A_FS_IDS_MASK              0xFFU

/**
 * device identification code
 */
#define TJA1145A_FS_IDS_SHIFT             0x00U

/**
 * TJA1145AATK
 */
#define TJA1145A_FS_IDS_TJA1145AATK        (0x70U << TJA1145A_FS_IDS_SHIFT)
/**
 * TJA1145AATK/FD
 */
#define TJA1145A_FS_IDS_TJA1145AATK_FD     (0x74U << TJA1145A_FS_IDS_SHIFT)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* TJA1145A_MAP_H */

/** @} */
