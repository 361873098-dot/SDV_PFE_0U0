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

#ifndef ADC_IPW_CFGDEFINES_H
#define ADC_IPW_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_CFGDEFINES                     43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES      4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES      4
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES   0
#define ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES              4
#define ADC_IPW_SW_MINOR_VERSION_CFGDEFINES              0
#define ADC_IPW_SW_PATCH_VERSION_CFGDEFINES              2

/*==================================================================================================
*                              DEFINES AND MACROS
==================================================================================================*/
#define ADC_IPW_INVALID_LOGICAL_UNIT_ID     (0xFFU)

#define ADC_IPW_INVALID_DMA_CHANNEL_ID      (0xFFU)

#define ADC_IPW_INVALID_TRANSFER_TYPE       (0xFFU)

#define ADC_IPW_NUM_OF_GROUP_CHN                ([!"ecu:get('Adc.AdcConfigSet.AdcSar.NumGroupChan')"!]U)

/**
 * @brief          Max number of ADC SAR Hw units.
 */
#define ADC_IPW_MAX_HW_UNITS                    ([!"ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!]U)

/**
 * @brief          Max number of CTU Hw units.
 */
#define ADC_IPW_CTU_MAX_HW_UNITS                    (1U)

#define ADC_IPW_CTU_UNIT_USED                   (0U)

/**
* @brief           Ctu trigger mode is supported.
*/
#define ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED      (STD_ON)

[!IF "AutosarExt/AdcEnableCtuTrigAutosarExtApi"!][!//
/**
* @brief           Maximum number of hardware triggers configred for all groups.
*/
#define ADC_IPW_MAX_HARDWARE_TRIGGERS           ([!"num:i(count(AdcConfigSet/AdcHwTrigger/*))"!]U)

[!ENDIF!][!//
/**
* @brief           PDB available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_PDB_AVAILABLE                   (STD_OFF)

[!IF "AutosarExt/AdcEnableSetChannel"!][!//
/**
* @brief           PDB channel delays available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_DELAY_AVAILABLE                 (ADC_IPW_PDB_AVAILABLE)

[!ENDIF!][!//
/**
* @brief           BCTU available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_BCTU_AVAILABLE                  (STD_OFF)

/**
* @brief           CTU available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_CTU_AVAILABLE                   (STD_ON)

/**
* @brief           Define the number of maximum channels
*/
#define ADC_IPW_MAXIMUM_HW_CHANNELS             (16U)

/**
* @brief           Maximum CTU event configuration.
*/
#define ADC_IPW_MAX_CTU_TRIG_SOURCE_ID      [!IF "ecu:get('Adc.ERR050473') = 'TRUE'"!]([!"num:i(ecu:get('AdcMaxCtuTriggerEventId.ERR050473'))"!]U)[!ELSE!]([!"num:i(ecu:get('AdcMaxCtuTriggerEventId'))"!]U)[!ENDIF!]
[!IF "ecu:get('AdcHasExtTrig') = 'TRUE'"!][!//
#define ADC_IPW_EXT_TRG_SRC                     [!IF "ecu:get('Adc.ERR050473') = 'TRUE'"!]([!"num:i(ecu:get('AdcMaxCtuTriggerEventId.ERR050473') + 1)"!]U)[!ELSE!]([!"num:i(ecu:get('AdcMaxCtuTriggerEventId') + 1)"!]U)[!ENDIF!] /* Normal and injected external trigger */
[!IF "ecu:get('AdcHasAuxExtTrig') = 'TRUE'"!][!//
#define ADC_IPW_AUX_EXT_TRG_SRC                 [!IF "ecu:get('Adc.ERR050473') = 'TRUE'"!]([!"num:i(ecu:get('AdcMaxCtuTriggerEventId.ERR050473') + 2)"!]U)[!ELSE!]([!"num:i(ecu:get('AdcMaxCtuTriggerEventId') + 2)"!]U)[!ENDIF!] /* Auxiliary normal external trigger */
[!ENDIF!][!//
[!ENDIF!][!//

/**
* @brief           Maximum CTU channel ID
*/
#define ADC_IPW_MAX_CTU_CHANNEL_ID       ([!"ecu:get('Adc.AdcMaxCTUChannelNo')"!]U)
#define ADC_IPW_CTU_FIFO_NO              ([!"ecu:get('Adc.AdcNoOfFifos')"!]U)

#define CTU_IPW_FIFO_DEPTH {[!//
[!FOR "x" = "0" TO "ecu:get('Adc.AdcNoOfFifos')-1"!][!//
[!"ecu:get(concat('Adc.AdcConfigSet.CtuHwUnit0.CTUFifo',string($x),'Depth'))"!][!IF "$x < (ecu:get('Adc.AdcNoOfFifos')-1)"!],[!ELSE!][!ENDIF!][!//
[!ENDFOR!][!//
}
/**
* @brief           ADC hardware is supported CALSTAT register
*/
#define ADC_IPW_CALSTAT_AVAILABLE               (STD_ON)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_CFGDEFINES_H */

