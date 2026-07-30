/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

#ifndef CTU_DRIVER_H
#define CTU_DRIVER_H

/**
*   @file
*
*   @addtogroup ctu_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ctu_Ip_Types.h"
#include "Ctu_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTU_IP_VENDOR_ID                      43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION       4
#define CTU_IP_AR_RELEASE_MINOR_VERSION       4
#define CTU_IP_AR_RELEASE_REVISION_VERSION    0
#define CTU_IP_SW_MAJOR_VERSION               4
#define CTU_IP_SW_MINOR_VERSION               0
#define CTU_IP_SW_PATCH_VERSION               2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ctu_Ip.h file and Ctu_Ip_Types.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID != CTU_IP_VENDOR_ID_TYPES)
    #error "Ctu_Ip.h and Ctu_Ip_Types.h have different vendor ids"
#endif

/* Check if Ctu_Ip.h file and Ctu_Ip_Types.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION != CTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION != CTU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION != CTU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.h and Ctu_Ip_Types.h are different"
#endif

/* Check if Ctu_Ip.h file and Ctu_Ip_Types.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION != CTU_IP_SW_MAJOR_VERSION_TYPES) || \
     (CTU_IP_SW_MINOR_VERSION != CTU_IP_SW_MINOR_VERSION_TYPES) || \
     (CTU_IP_SW_PATCH_VERSION != CTU_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Ctu_Ip.h and Ctu_Ip_Types.h are different"
#endif

/* Check if Ctu_Ip.h file and Ctu_Ip_Cfg.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID != CTU_IP_VENDOR_ID_CFG)
    #error "Ctu_Ip.h and Ctu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Ctu_Ip.h file and Ctu_Ip_Cfg.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION != CTU_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION != CTU_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION != CTU_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip.h and Ctu_Ip_Cfg.h are different"
#endif

/* Check if Ctu_Ip.h file and Ctu_Ip_Cfg.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION != CTU_IP_SW_MAJOR_VERSION_CFG) || \
     (CTU_IP_SW_MINOR_VERSION != CTU_IP_SW_MINOR_VERSION_CFG) || \
     (CTU_IP_SW_PATCH_VERSION != CTU_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of Ctu_Ip.h and Ctu_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/
/*!
 * @brief Macros for selecting input triggers signal edges - mapped to TRGSISR register format.
 * Implements : CTU_INPUT_TRIG_BITMASK_Class
 */
#define CTU_IP_INPUT_TRIG_BITMASK_RISING(INPUT_IDX)    ((uint32)1u << (2u * ((uint32)(INPUT_IDX))))          /*!< Select input triggers: even bits correspond to rising edge of the input idx */
#define CTU_IP_INPUT_TRIG_BITMASK_FALLING(INPUT_IDX)   ((uint32)1u << ((2u * ((uint32)(INPUT_IDX))) + 1u))   /*!< Select input triggers: odd bits correspond to falling edge of the input idx */
#define CTU_IP_INPUT_TRIG_BITMASK_BOTH(INPUT_IDX)      ((uint32)3u << (2u * ((uint32)(INPUT_IDX))))          /*!< Select input triggers: both rising and falling edges of the input idx  */
#define CTU_IP_INPUT_TRIG_BITMASK_ALL                  (0xFFFFFFFFu)                                             /*!< Select input triggers: both rising and falling edges for all inputs  */


/*!
 * @brief Macros for selecting CTU outputs to be enabled - mapped to THCR register.
 * Implements : CTU_IP_OUTPUT_TRIG_Class
 */
#define CTU_IP_OUTPUT_TRIG_ADC_CMD_EN          ((uint32)CTU_THCR1_T0_ADCE_MASK)

#ifdef CTU_THCR1_T0_T1E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_1_EN          ((uint32)CTU_THCR1_T0_T1E_MASK)
#endif /* CTU_THCR1_T0_T1E_MASK */

#ifdef CTU_THCR1_T0_T2E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_2_EN          ((uint32)CTU_THCR1_T0_T2E_MASK)
#endif /* CTU_THCR1_T0_T2E_MASK */

#ifdef CTU_THCR1_T0_T3E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_3_EN          ((uint32)CTU_THCR1_T0_T3E_MASK)
#endif /* CTU_THCR1_T0_T3E_MASK */

#ifdef CTU_THCR1_T0_T4E_MASK
#define CTU_IP_OUTPUT_TRIG_TIMER_4_EN          ((uint32)CTU_THCR1_T0_T4E_MASK)
#endif /* CTU_THCR1_T0_T4E_MASK */

#ifdef CTU_THCR1_T0_ETE_MASK
#define CTU_IP_OUTPUT_TRIG_EXT_EN              ((uint32)CTU_THCR1_T0_ETE_MASK)
#endif /* CTU_THCR1_T0_ETE_MASK */

/*! Enable the output for selected CTU trigger. If not set, all outputs are disabled. */
#define CTU_IP_OUTPUT_TRIG_EN                  ((uint32)CTU_THCR1_T0_E_MASK)

#define CTU_IP_OUTPUT_TRIG_ALL_EN              (CTU_IP_OUTPUT_TRIG_ADC_CMD_EN | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_1_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_2_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_3_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_4_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_EXT_EN_LOCAL     | \
                                                CTU_IP_OUTPUT_TRIG_EN)

#define CTU_IP_OUTPUT_TRIG_ALL_E               (CTU_IP_OUTPUT_TRIG_TIMER_1_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_2_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_3_EN_LOCAL | \
                                                CTU_IP_OUTPUT_TRIG_TIMER_4_EN_LOCAL)


/*!
 * @brief Macros for selecting CTU result FIFO status and interrupt flags - mapped to FST and FCR registers.
 * Implements : CTU_FIFO_Class
 */
#define CTU_IP_FIFO_FULL                       ((uint32)CTU_FST_FULL0_MASK)
#define CTU_IP_FIFO_EMPTY                      ((uint32)CTU_FST_EMP0_MASK)
#define CTU_IP_FIFO_OVERFLOW                   ((uint32)CTU_FST_OF0_MASK)
#define CTU_IP_FIFO_OVERRUN                    ((uint32)CTU_FST_OR0_MASK)
#define CTU_IP_FIFO_ALL                        (CTU_IP_FIFO_FULL | CTU_IP_FIFO_EMPTY | CTU_IP_FIFO_OVERFLOW | CTU_IP_FIFO_OVERRUN)

/*!
 * @brief Macros for selecting CTU error flags - mapped to EFR register.
 * Implements : CTU_IP_ERROR_FLAG_Class
 */
#define CTU_IP_ERROR_FLAG_MRS_RE               (CTU_EFR_MRS_RE_MASK)
#define CTU_IP_ERROR_FLAG_SM_TRIG_OVERRUN      (CTU_EFR_SM_TO_MASK)
#define CTU_IP_ERROR_FLAG_INVALID_CMD          (CTU_EFR_ICE_MASK)
#define CTU_IP_ERROR_FLAG_MRS_OVERRUN          (CTU_EFR_MRS_O_MASK)
#define CTU_IP_ERROR_FLAG_TGS_SM_OVERRUN       (CTU_EFR_TGS_OSM_MASK)
#define CTU_IP_ERROR_FLAG_ADC_OVERRUN          (CTU_EFR_ADC_OE_MASK)

#ifdef CTU_EFR_T1_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_1_OVERRUN      (CTU_EFR_T1_OE_MASK)
#endif /* CTU_EFR_T1_OE_MASK */
#ifdef CTU_EFR_T2_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_2_OVERRUN      (CTU_EFR_T2_OE_MASK)
#endif /* CTU_EFR_T2_OE_MASK */
#ifdef CTU_EFR_T3_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_3_OVERRUN      (CTU_EFR_T3_OE_MASK)
#endif /* CTU_EFR_T3_OE_MASK */
#ifdef CTU_EFR_T4_OE_MASK
#define CTU_IP_ERROR_FLAG_TIMER_4_OVERRUN      (CTU_EFR_T4_OE_MASK)
#endif /* CTU_EFR_T4_OE_MASK */

#define CTU_IP_ERROR_FLAG_ERRCMP               (CTU_EFR_ERRCMP_MASK)

#ifdef CTU_EFR_ET_OE_MASK
#define CTU_IP_ERROR_FLAG_EXT_TRIG_OVERRUN     (CTU_EFR_ET_OE_MASK)
#endif /* CTU_EFR_ET_OE_MASK */

#define CTU_IP_ERROR_FLAG_LIST_BUSY            (CTU_EFR_LIST_BE_MASK)

#define CTU_IP_ERROR_FLAG_ALL                  (CTU_IP_ERROR_FLAG_MRS_RE            | CTU_IP_ERROR_FLAG_SM_TRIG_OVERRUN  | CTU_IP_ERROR_FLAG_INVALID_CMD      | \
                                                CTU_IP_ERROR_FLAG_MRS_OVERRUN       | CTU_IP_ERROR_FLAG_TGS_SM_OVERRUN   | CTU_IP_ERROR_FLAG_ADC_OVERRUN      | \
                                                CTU_IP_ERROR_FLAG_TIMER_1_OVERRUN_LOCAL   | CTU_IP_ERROR_FLAG_TIMER_2_OVERRUN_LOCAL  | \
                                                CTU_IP_ERROR_FLAG_TIMER_3_OVERRUN_LOCAL   | CTU_IP_ERROR_FLAG_TIMER_4_OVERRUN_LOCAL  | \
                                                CTU_IP_ERROR_FLAG_ERRCMP            | CTU_IP_ERROR_FLAG_EXT_TRIG_OVERRUN_LOCAL | \
                                                CTU_IP_ERROR_FLAG_SELF_TEST_RUNNING_LOCAL | CTU_IP_ERROR_FLAG_LIST_BUSY)

/*!
* @brief Macros for selecting CTU NOTIFICATION status flags - mapped to IFR register.
* Implements : CTU_IP_NOTIFICATION_FLAG_Class
*/
#define CTU_IP_NOTIFICATION_FLAG_MRS              (CTU_IFR_MRS_I_MASK)    /*!< Set when Master Reload Signal is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_0           (CTU_IFR_T0_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_1           (CTU_IFR_T1_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_2           (CTU_IFR_T2_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_3           (CTU_IFR_T3_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_4           (CTU_IFR_T4_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_5           (CTU_IFR_T5_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_6           (CTU_IFR_T6_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_TRIG_7           (CTU_IFR_T7_I_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_FLAG_ADC_CMD          (CTU_IFR_ADC_I_MASK)    /*!< Set when a new ADC command is issued. */
#define CTU_IP_NOTIFICATION_FLAG_SERR_A           (CTU_IFR_SERR_A_MASK)   /*!< Duration of ADC 0 conversion is greater than the maximum configured. */
#define CTU_IP_NOTIFICATION_FLAG_SERR_B           (CTU_IFR_SERR_B_MASK)   /*!< Duration of ADC 1 conversion is greater than the maximum configured. */

#define CTU_IP_NOTIFICATION_FLAG_ALL              (CTU_IP_NOTIFICATION_FLAG_MRS     | CTU_IP_NOTIFICATION_FLAG_TRIG_0 | CTU_IP_NOTIFICATION_FLAG_TRIG_1 | \
                                                   CTU_IP_NOTIFICATION_FLAG_TRIG_2  | CTU_IP_NOTIFICATION_FLAG_TRIG_3 | CTU_IP_NOTIFICATION_FLAG_TRIG_4 | \
                                                   CTU_IP_NOTIFICATION_FLAG_TRIG_5  | CTU_IP_NOTIFICATION_FLAG_TRIG_6 | CTU_IP_NOTIFICATION_FLAG_TRIG_7 | \
                                                   CTU_IP_NOTIFICATION_FLAG_ADC_CMD | CTU_IP_NOTIFICATION_FLAG_SERR_A | CTU_IP_NOTIFICATION_FLAG_SERR_B)


/*!
* @brief Macros for enabling CTU notifications - mapped to IR register.
* Implements : CTU_IP_NOTIFICATION_Class
*/
#define CTU_IP_NOTIFICATION_MRS              (CTU_IR_MRS_IE_MASK)    /*!< Set when Master Reload Signal is issued. */
#define CTU_IP_NOTIFICATION_TRIG_0           (CTU_IR_T0_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_1           (CTU_IR_T1_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_2           (CTU_IR_T2_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_3           (CTU_IR_T3_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_4           (CTU_IR_T4_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_5           (CTU_IR_T5_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_6           (CTU_IR_T6_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */
#define CTU_IP_NOTIFICATION_TRIG_7           (CTU_IR_T7_IE_MASK)     /*!< Set when the corresponding internal trigger is issued. */

#define CTU_IP_NOTIFICATION_ALL              (CTU_IP_NOTIFICATION_MRS     | CTU_IP_NOTIFICATION_TRIG_0 | CTU_IP_NOTIFICATION_TRIG_1 | \
                                              CTU_IP_NOTIFICATION_TRIG_2  | CTU_IP_NOTIFICATION_TRIG_3 | CTU_IP_NOTIFICATION_TRIG_4 | \
                                              CTU_IP_NOTIFICATION_TRIG_5  | CTU_IP_NOTIFICATION_TRIG_6 | CTU_IP_NOTIFICATION_TRIG_7)

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

 /*!
  * @brief Configure the global functionalities of a CTU instance.
  *
  * This function configures the global functionalities of a CTU instance.
  *
  * @param[in] u32Instance - the CTU instance number
  * @param[in] pConfig - pointer to the input configuration structure
  * @return status:
 *    - CTU_IP_STATUS_SUCCESS: Init successful
 *    - CTU_IP_STATUS_TIMEOUT: Init step timed out
  */
Ctu_Ip_StatusType Ctu_Ip_Init(const uint32 u32Instance,
                              const Ctu_Ip_ConfigType * const pConfig);

/*!
 * @brief Reset all registers of a CTU instance to default values.
 *
 * This function resets all registers of a CTU instance to default values.
 * It stops and resets any running ADC command list.
 * Note: the function also enables the CTU output (default state is enabled).
 *
 * @param[in] u32Instance - the CTU instance number
 * @return status:
 *    - CTU_IP_STATUS_SUCCESS: Deinit successful
 *    - CTU_IP_STATUS_TIMEOUT: Deinit step timed out
 */
Ctu_Ip_StatusType Ctu_Ip_Deinit(const uint32 u32Instance);

/*!
 * @brief Enable the selected signal edge(s) for a CTU input trigger.
 *
 * This function enables the selected signal edge(s) for a CTU input trigger.
 * The affected register is double-buffered, so the new value will take effect only
 * after MRS occurs or Ctu_Ip_SyncInputSelect() is called.
 * Please note that the set operation is cumulative, e.g. set falling edge, then set rising edge
 * for same input trigger, results in both edges being enabled for that trigger.
 * The same applies also when setting both edges, followed by set falling/rising.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] pInputTrig - the selected input trigger
 * @param[in] pInputEdge - the selected signal edge(s) of the input trigger
 * @return void
 */
void Ctu_Ip_SetInputSelect(const uint32 u32Instance,
                           const Ctu_Ip_InputTrigType pInputTrig,
                           const Ctu_Ip_InputEdgeType pInputEdge);

/*!
 * @brief Disable the selected signal edge(s) for a CTU input trigger.
 *
 * This function disables the selected signal edge(s) for a CTU input trigger.
 * The affected register is double-buffered, so the new value will take effect only
 * after MRS occurs or Ctu_Ip_SyncInputSelect() is called.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] pInputTrig - the selected input trigger
 * @param[in] pInputEdge - the selected signal edge(s) of the input trigger
 * @return void
 */
void Ctu_Ip_ClearInputSelect(const uint32 u32Instance,
                             const Ctu_Ip_InputTrigType pInputTrig,
                             const Ctu_Ip_InputEdgeType pInputEdge);

/*!
 * @brief Load the new value of input trigger select - TGSISR (double buffered register).
 *
 * This function loads the new value of input trigger select - TGSISR (double buffered register).
 * The function waits until the TGSISR register is updated from the corresponding buffer register.
 *
 * @param[in] u32Instance - the CTU instance number
 * @return status:
 *    - CTU_IP_STATUS_SUCCESS: Sync successful
 *    - CTU_IP_STATUS_TIMEOUT: Sync timed out
 */
Ctu_Ip_StatusType Ctu_Ip_SyncInputSelect(const uint32 u32Instance);

/*!
 * @brief Configure the compare value of a single internal trigger.
 *
 * This function configures the compare value of a single internal trigger.
 * By internal trigger, the CTU driver refers to the output triggers from TGS (Trigger Generator Subunit),
 * fed as input triggers to the SU (Scheduler Subunit). \n
 *
 * Note: u8CmpVal corresponds to a double buffered register,
 * so the configured value is loaded and will take effect only after MRS occurs. \n
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32TrigIdx - index of the trigger
 * @param[in] u16CmpVal - compare value
 * @return void
 */
void Ctu_Ip_SetTriggerCompare(const uint32 u32Instance,
                              const uint32 u32TrigIdx,
                              const uint16 u16CmpVal);

/*!
 * @brief Configure the Adc command address of a single internal trigger.
 *
 * This function configures the first address of the command list associated with an internal trigger.
 * By internal trigger, the CTU driver refers to the output triggers from TGS (Trigger Generator Subunit),
 * fed as input triggers to the SU (Scheduler Subunit). \n
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32TrigIdx - index of the trigger
 * @param[in] u8AdcCmdAddress - address of the first command
 * @return void
 */
void Ctu_Ip_SetTriggerAdcCmdAddress(const uint32 u32Instance,
                                    const uint32 u32TrigIdx,
                                    const uint8 u8AdcCmdAddress);

/*!
 * @brief Configure which CTU output triggers are enabled for a single internal trigger.
 *
 * This function configures which CTU output triggers are enabled for a single internal trigger.
 * By internal trigger, the CTU driver refers to the output triggers from TGS (Trigger Generator Subunit),
 * fed as input triggers to the SU (Scheduler Subunit). \n
 *
 * Note: u8TriggerEnableMask corresponds to a double buffered register,
 * so the configured value is loaded and will take effect only after MRS occurs. \n
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32TrigIdx - index of the trigger
 * @param[in] u8TriggerEnableMask - mask that selects the CTU output triggers to be enabled
 * @return void
 */
void Ctu_Ip_WriteTriggerEnableMask(const uint32 u32Instance,
                                   const uint32 u32TrigIdx,
                                   const uint8 u8TriggerEnableMask);

/*!
 * @brief Set the enable bit for a single internal trigger.
 *
 * This function sets the enable bit Tx_E of THCRx register for a single internal trigger. \n
 * By internal trigger, the CTU driver refers to the output triggers from TGS (Trigger Generator Subunit),
 * fed as input triggers to the SU (Scheduler Subunit). \n
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32TrigIdx - index of the trigger
 * @param[in] bEnable - value of the enable bit
 * @return void
 */
void Ctu_Ip_SetTriggerEnable(const uint32 u32Instance,
                             const uint32 u32TrigIdx,
                             const boolean bEnable);

/*!
 * @brief Configure an array of ADC commands and marks accordingly the last command.
 *
 * This function configures an array of ADC commands and marks accordingly the last command. \n
 *
 * Note: the ADC command registers are double buffered,
 *  so configured values are loaded and take effect only after MRS occurs. \n
 *  The function doesn't take into account the reload mechanism (refer to device reference manual for details),
 *  so it needs to be handled externally - may use Ctu_Ip_SetGeneralReloadEnable().
 *  Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32StartCmdListAdr - index of the starting element in the conversion list
 * @param[in] pAdcCmdArray - pointer to the array of the ADC command list
 * @param[in] u8NumCmds - number of commands in the array of ADC command list
 * @return void
 */
void Ctu_Ip_ConfigAdcCmdList(const uint32 u32Instance,
                             const uint32 u32StartCmdListAdr,
                             const Ctu_Ip_AdcCmdType * const pAdcCmdArray,
                             const uint8 u8NumCmds);

/*!
 * @brief Configure the threshold of a selected result FIFO.
 *
 * This function configures the threshold of a selected result FIFO.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32FifoIdx - index of the result FIFO
 * @param[in] u8Threshold - threshold value
 * @return void
 */
void Ctu_Ip_SetFifoThreshold(const uint32 u32Instance,
                             const uint32 u32FifoIdx,
                             const uint8 u8Threshold);

/*!
 * @brief Return the conversion data result aligned according to the alignment parameter.
 *
 * This function returns the conversion data result aligned according
 * to the alignment parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32FifoIdx - index of the result FIFO
 * @param[in] pAlignment - left or right alignment of the result data
 * @param[in] u8ResultLength - number of results to be read
 * @param[out] pData - pointer to the results array
 * @return void
 */
void Ctu_Ip_GetFifoData(const uint32 u32Instance,
                        const uint32 u32FifoIdx,
                        Ctu_Ip_DataAlignType pAlignment,
                        const uint8 u8ResultLength,
                        uint16 * const pData);

/*!
 * @brief Get the full conversion result information, with
 * the conversion data aligned according to the alignment parameter.
 *
 * This function gets the full conversion result information, with
 * the conversion data aligned according to the alignment parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32FifoIdx - index of the result FIFO
 * @param[in] pAlignment - left or right alignment of the result data
 * @param[in] u8ResultLength - number of results to be read
 * @param[out] pResults - pointer to the output structure containing full conversion result information
 * @return void
 */
void Ctu_Ip_GetFifoResult(const uint32 u32Instance,
                          const uint32 u32FifoIdx,
                          const Ctu_Ip_DataAlignType pAlignment,
                          const uint8 u8ResultLength,
                          Ctu_Ip_ConvResultType * const pResults);

/*!
 * @brief Enable the notifications for the selected result FIFO, corresponding
 * to the bits set in mask parameter.
 *
 * This function enables the notifications for the selected result FIFO, corresponding
 * to the bits set in mask parameter.
 * Note: FIFO notifications(except overrun) can't be cleared by flag.
 * Clearing overflow and full notifications is done by reading from the FIFO.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32FifoIdx - index of the result FIFO
 * @param[in] u32NotificationMask - bit-mask selecting which FIFO notifications to be enabled
 * @return void
 */
void Ctu_Ip_EnableFifoNotifications(const uint32 u32Instance,
                                    const uint32 u32FifoIdx,
                                    const uint32 u32NotificationMask);

/*!
 * @brief Disable the notifications for the selected result FIFO, corresponding
 * to the bits set in mask parameter.
 *
 * This function disables the notifications for the selected result FIFO, corresponding
 * to the bits set in mask parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32FifoIdx - index of the result FIFO
 * @param[in] u32NotificationMask - bit-mask selecting which FIFO notifications to be disabled
 * @return void
 */
void Ctu_Ip_DisableFifoNotifications(const uint32 u32Instance,
                                     const uint32 u32FifoIdx,
                                     const uint32 u32NotificationMask);

/*!
 * @brief Enable the notifications corresponding to the bits set in mask parameter.
 *
 * This function enables the notifications corresponding to the bits set in mask parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u16NotificationMask - bit-mask selecting which notifications to be enabled
 * @return void
 */
void Ctu_Ip_EnableNotifications(const uint32 u32Instance,
                                const uint16 u16NotificationMask);

/*!
 * @brief Disable the notifications corresponding to the bits set in mask parameter.
 *
 * This function disables the notifications corresponding to the bits set in mask parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u16NotificationMask - bit-mask selecting which notifications to be disabled
 * @return void
 */
void Ctu_Ip_DisableNotifications(const uint32 u32Instance,
                                 const uint16 u16NotificationMask);

/*!
 * @brief Enable the triggers corresponding to the bits set in mask parameter.
 *
 * This function enables the triggers corresponding to the bits set in mask parameter.
 * This is done by modifying the Tx_E bits of THCRx register corresponding to the
 * triggers set in the mask parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u8TrigIdxMask - bit-mask selecting which triggers to be enabled
 * @return void
 */
void Ctu_Ip_EnableTrigger(const uint32 u32Instance,
                          const uint8 u8TrigIdxMask);

/*!
 * @brief Disable the triggers corresponding to the bits set in mask parameter.
 *
 * This function disables the triggers corresponding to the bits set in mask parameter.
 * This is done by modifying the Tx_E bits of THCRx register corresponding to the
 * triggers set in the mask parameter.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u8TrigIdxMask - bit-mask selecting which triggers to be disabled
 * @return void
 */
void Ctu_Ip_DisableTrigger(const uint32 u32Instance,
                           const uint8 u8TrigIdxMask);

/*!
 * @brief Clear the error flags corresponding to the bits set in mask parameter.
 *
 * This function clears the error flags corresponding to the bits set in mask parameter.
 * The mask parameter can be set using the defines provided in the driver header
 * file that have the pattern CTU_IP_ERROR_FLAG_... e.g. CTU_IP_ERROR_FLAG_INVALID_CMD.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32FlagsMask - bit-mask selecting which error flags to be cleared
 * @return void
 */
void Ctu_Ip_ClearErrorFlags(const uint32 u32Instance,
                            const uint32 u32FlagsMask);

/*!
 * @brief Return bit-mask with values for all the CTU error flags.
 *
 * This function returns bit-mask with values for all the CTU error flags.
 * Values for individual flags may be retrieved by masking the result with defines provided
 * in the driver header file that have the pattern CTU_IP_ERROR_FLAG_... e.g. CTU_IP_ERROR_FLAG_MRS_RE.
 *
 * @param[in] u32Instance - the CTU instance number
 * @return uint32 - bit-mask with values for all the CTU error flags.
 */
uint16 Ctu_Ip_GetErrorFlags(const uint32 u32Instance);

/*!
 * @brief Get the list status information.
 *
 * This function gets the list status information.
 * Information for multiple lists is available when executing in parallel mode.
 *
 * @param[in] u32Instance - the instance number
 * @param[in] u32ListIdx - index of the list
 * @param[out] u32ListStatus - pointer to list status information
 * @return status:
 *    - CTU_IP_STATUS_SUCCESS: returned information is valid
 *    - CTU_IP_STATUS_ERROR: list status information is not meaningful, because EFR.LIST_BE is not set.
 */
Ctu_Ip_StatusType Ctu_Ip_GetListStatus(const uint32 u32Instance,
                                       const uint32 u32ListIdx,
                                       Ctu_Ip_ListStatusType * const pListStatus);

/*!
 * @brief Generates from software an event on the selected internal trigger.
 *
 * Generates from software an event on the selected internal trigger,
 * provided as input to the Scheduler subunit (SU).
 * This bypasses any delays configured in Trigger Generator Subunit (TGS)
 * and can be used when the TGS Counter is running or stopped.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] u32TrigIdx - index of the internal trigger
 * @return void
 */
void Ctu_Ip_SwInternalTrigger(const uint32 u32Instance,
                              const uint32 u32TrigIdx);

/*!
 * @brief Software trigger the Master Reload Signal.
 *
 * Software trigger the Master Reload Signal.
 *
 * @param[in] u32Instance - the CTU instance number
 * @return void
 */
void Ctu_Ip_SwMasterReload(const uint32 u32Instance);

/*!
 * @brief Enable CTU output.
 *
 * This function enables CTU output.
 * The output can be a pulse, an ADC command or a stream of ADC commands.
 *
 * @param[in] u32Instance - the CTU instance number
 * @return void
 */
void Ctu_Ip_EnableOutput(const uint32 u32Instance);

/*!
 * @brief Disable CTU output.
 *
 * This function disables CTU output.
 * The output can be a pulse, an ADC command or a stream of ADC commands.
 *
 * @param[in] u32Instance - the CTU instance number
 * @return void
 */
void Ctu_Ip_DisableOutput(const uint32 u32Instance);

/*!
 * @brief Set the Enable General Reload flag (CR.GRE)
 *
 * This function sets the Enable General Reload flag (CR.GRE).
 * It needs to be called before MRS, after the last write to a double-buffered register.
 * It marks that the user has completed writing all the double-buffered registers for
 * the current control cycle, so an MRS event shall load all the new values in the double-buffered registers.
 * If CR.GRE is not set and at least a double-buffered register has been written during the current control cycle
 * (i.e. after the last MRS), the next MRS will not load the new values and an error flag will be raised (EFR.MRS_RE).
 *    For more details please see reload mechanism described in device reference manual.
 *
 * @param[in] u32Instance - the CTU instance number
 * @param[in] bEnable - value of the enable bit to be set
 * @return status:
 *    - CTU_IP_STATUS_SUCCESS: Set successful
 *    - CTU_IP_STATUS_TIMEOUT: Set timed out
 */
Ctu_Ip_StatusType Ctu_Ip_SetGeneralReloadEnable(const uint32 u32Instance,
                                                const boolean bEnable);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CTU_DRIVER_H */
