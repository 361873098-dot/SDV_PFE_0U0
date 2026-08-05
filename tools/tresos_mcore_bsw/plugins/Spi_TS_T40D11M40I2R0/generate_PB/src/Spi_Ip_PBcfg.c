/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
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
*   @file    Spi_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_IP_DRIVER_CONFIGURATION Spi Ip Driver Configuration
*   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spi_Ip.h"
#if (SPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_MODULE_ID_PBCFG_C                        83
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_PBCFG_C                        43
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG_C         4
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_PBCFG_C                 4
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_PBCFG_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ip.h and Spi_Ip_PBcfg.c are of the same vendor */
#if (SPI_IP_VENDOR_ID != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_PBCFG_C)
    #error "Spi_Ip.h and Spi_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if Spi_Ip.h file and Spi_Ip_PBcfg.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi_Ip.h and Spi_Ip_PBcfg.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IP_SW_MINOR_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_IP_SW_PATCH_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Spi_Ip.h and Spi_Ip_PBcfg.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (SPI_IP_DMA_USED == STD_ON)
         /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
             (DMA_IP_AR_RELEASE_MINOR_VERSION != SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG_C))
        #error "AutoSar Version Numbers of Spi_Ip_PBcfg.c and Dma_Ip.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

[!NOCODE!][!//
[!MACRO "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalAbsoluteTimeError" = "1000000"!]
  [!VAR "OptimalRelativeTimeError" = "0"!]
  [!VAR "OptimalTime" = "0"!]
  [!VAR "OptimalPrescaler" = "0"!]
  [!VAR "OptimalScaler" = "0"!]
  [!// if $DesiredTime=0, initialized values are OK; no further calculations needed
  [!IF "$DesiredTime > 0.0"!]
    [!FOR "Prescaler_Count" = "0" TO "3"!]
      [!VAR "Prescaler" = "$Prescaler_Count*2 + 1"!]
      [!VAR "Scaler" = "2"!]
      [!FOR "Scaler_Count" = "0" TO "15"!]
        [!VAR "CalculatedTime" = "$Prescaler * 1000 * $Scaler div $BusClock"!]
        [!VAR "RelativeTimeError" = "($CalculatedTime div $DesiredTime) - 1 "!]
        [!VAR "AbsoluteTimeError" = "$RelativeTimeError"!]
        [!IF "$AbsoluteTimeError < 0"!][!VAR "AbsoluteTimeError" = "$AbsoluteTimeError * (-1)"!][!ENDIF!]
        [!IF "$AbsoluteTimeError < $OptimalAbsoluteTimeError"!]
          [!VAR "OptimalAbsoluteTimeError" = "$AbsoluteTimeError"!]
          [!VAR "OptimalRelativeTimeError" = "$RelativeTimeError"!]
          [!VAR "OptimalTime" = "$CalculatedTime"!]
          [!VAR "OptimalPrescaler" = "$Prescaler_Count"!]
          [!VAR "OptimalScaler" = "$Scaler_Count"!]
        [!ENDIF!]
        [!VAR "Scaler" = "$Scaler*2"!]
      [!ENDFOR!]
    [!ENDFOR!]
  [!ENDIF!][!//"$DesiredTime > 0.0"
[!ENDMACRO!][!//

[!MACRO "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalAbsoluteBaudrateError" = "1000000"!]
  [!VAR "OptimalRelativeBaudrateError" = "0"!]
  [!VAR "OptimalBaudrate" = "0"!]
  [!VAR "OptimalDouble" = "0"!]
  [!VAR "OptimalPrescaler" = "0"!]
  [!VAR "OptimalScaler" = "0"!]
  [!FOR "Double" = "0" TO "1"!]
    [!FOR "Prescaler_Count" = "0" TO "3"!]
      [!VAR "Prescaler" = "$Prescaler_Count*2 + 1"!]
      [!IF "$Prescaler = 1"!][!VAR "Prescaler" = "2"!][!ENDIF!]
      [!VAR "Scaler" = "2"!]
      [!FOR "Scaler_Count" = "0" TO "15"!]
        [!VAR "CalculatedBaudrate" = "1000000 * $BusClock * (1+ $Double) div ($Prescaler * $Scaler)"!]
        [!// DesiredBaudrate is always positive
        [!VAR "RelativeBaudrateError" = "($CalculatedBaudrate div $DesiredBaudrate) - 1 "!]
        [!VAR "AbsoluteBaudrateError" = "$RelativeBaudrateError"!]
        [!IF "$AbsoluteBaudrateError < 0"!][!VAR "AbsoluteBaudrateError" = "$AbsoluteBaudrateError * (-1)"!][!ENDIF!]
        [!IF "$AbsoluteBaudrateError < $OptimalAbsoluteBaudrateError"!]
          [!VAR "OptimalAbsoluteBaudrateError" = "$AbsoluteBaudrateError"!]
          [!VAR "OptimalRelativeBaudrateError" = "$RelativeBaudrateError"!]
          [!VAR "OptimalBaudrate" = "$CalculatedBaudrate"!]
          [!VAR "OptimalDouble" = "$Double"!]
          [!VAR "OptimalPrescaler" = "$Prescaler_Count"!]
          [!VAR "OptimalScaler" = "$Scaler_Count"!]
        [!ENDIF!]
        [!IF "$Scaler = 4"!]
          [!VAR "Scaler" = "6"!]
        [!ELSEIF "$Scaler = 6"!]
          [!VAR "Scaler" = "8"!]
        [!ELSE!]
          [!VAR "Scaler" = "$Scaler*2"!]
        [!ENDIF!]
      [!ENDFOR!]
    [!ENDFOR!]
  [!ENDFOR!]
[!ENDMACRO!][!//

[!MACRO "GenerateExternalDeviceInfo"!]]

  [!VAR "BusClock" = "$BusClockNormal"!][!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPCSCLK" = "$OptimalPrescaler"!]
  [!VAR "OptimalSCSCLK" = "$OptimalScaler"!]
  [!VAR "OptimalTimeCs2Clk" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2ClkError" = "$OptimalRelativeTimeError"!]

  [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPASC" = "$OptimalPrescaler"!]
  [!VAR "OptimalSASC" = "$OptimalScaler"!]
  [!VAR "OptimalTimeClk2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeClk2CsError" = "$OptimalRelativeTimeError"!]

  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPDT" = "$OptimalPrescaler"!]
  [!VAR "OptimalSDT" = "$OptimalScaler"!]
  [!VAR "OptimalTimeCs2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2CsError" = "$OptimalRelativeTimeError"!]
  
  [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
  [!CALL "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalPBR" = "$OptimalPrescaler"!]
  [!VAR "OptimalBR" = "$OptimalScaler"!]
  [!VAR "OptimalDBR" = "$OptimalDouble"!]
  [!VAR "OptimalBaudrateNormal" = "$OptimalBaudrate"!]
  [!VAR "OptimalRelativeBaudrateErrorNormal" = "$OptimalRelativeBaudrateError"!]

  [!IF "$DualClockEnabled = 'true'"!][!//
    [!VAR "BusClock" = "$BusClockAlternate"!][!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPCSCLKAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSCSCLKAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeCs2ClkAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2ClkErrorAlternate" = "$OptimalRelativeTimeError"!]

    [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPASCAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSASCAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeClk2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeClk2CsErrorAlternate" = "$OptimalRelativeTimeError"!]

    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPDTAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSDTAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeCs2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2CsErrorAlternate" = "$OptimalRelativeTimeError"!]

    [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
    [!CALL "DetermineOptimalBaudrateSettings"!]
    [!VAR "OptimalPBRAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalBRAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalDBRAlternate" = "$OptimalDouble"!]
    [!VAR "OptimalBaudrateAlternate" = "$OptimalBaudrate"!]
    [!VAR "OptimalRelativeBaudrateErrorAlternate" = "$OptimalRelativeBaudrateError"!]
  [!ENDIF!][!// "$DualClockEnabled = 'true'"
[!ENDMACRO!][!//

[!MACRO "Spi_CheckDualClockSupport"!][!// In some platfroms, SPI Instances will not use the same source clock. In that case, MCU clock reference will be separated for each SPI HW Unit.
    [!VAR "SeparateSpiClockRefer" = "'true'"!]
    [!VAR "DualClockEnabled" = "'false'"!]
    [!VAR "DualClockSupport" = "'false'"!]
    [!IF "(node:exists(SpiGeneral/SpiClockRef))"!]
        [!VAR "SeparateSpiClockRefer" = "'false'"!]
        [!VAR "DualClockEnabled" = "(node:exists(SpiAutosarExt/SpiAlternateClockRef))"!]
        [!SELECT "node:ref(SpiGeneral/SpiClockRef)"!]
            [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!]
        [!ENDSELECT!]
        [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!]
        [!IF "$DualClockEnabled = 'true'"!]
            [!VAR "DualClockSupport" = "'true'"!]
            [!SELECT "node:ref(SpiAutosarExt/SpiAlternateClockRef)"!]
                [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!]
            [!ENDSELECT!]
            [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!]
        [!ENDIF!]
    [!ELSE!]
        [!LOOP "SpiGeneral/SpiPhyUnit/*"!]
            [!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!]
                [!VAR "DualClockSupport"= "'true'"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDMACRO!]

[!CALL "Spi_CheckDualClockSupport"!]

[!ENDNOCODE!][!//

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

[!NOCODE!][!//
[!VAR "NumberOfExternalDeviceSpi" = "0"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
    [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
    [!IF "not(contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))),'_')),'LPSPI'))"!]
        [!VAR "NumberOfExternalDeviceSpi"= "$NumberOfExternalDeviceSpi + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "num:i($NumberOfExternalDeviceSpi) != 0"!]
[!CODE!][!//
/* Spi_Ip_DeviceParamsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Device Attribute Configuration of Spi*/
static Spi_Ip_DeviceParamsType Spi_Ip_DeviceParamsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumberOfExternalDeviceSpi)"!]U] =
{
[!ENDCODE!][!//
    [!VAR "ExIndex"="1"!]
    [!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
        [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "not(contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))),'_')),'LPSPI'))"!]
        [!CODE!]
    {
        (uint8)8UL, /* Frame size - dummy value */
        (boolean)TRUE, /*Lsb - dummy value */
        (uint32)1U  /* Default Data - dummy value */
    }[!IF "$ExIndex < num:i($NumberOfExternalDeviceSpi)"!],[!ENDIF!][!//
        [!ENDCODE!][!//
        [!VAR "ExIndex"="$ExIndex + 1"!][!//
        [!ENDIF!]
    [!ENDLOOP!][!//
[!CODE!]
};
[!ENDCODE!][!//
[!ENDIF!]
[!ENDNOCODE!][!//

#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

[!NOCODE!][!//
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "node:exists(SpiMaxDmaFastTransfer)"!][!//
[!CODE!][!//
/* Spi_Ip_CmdDmaFast_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Command Configuration of Dma Fast transfers */
static Spi_Ip_CmdDmaFastType Spi_Ip_CmdDmaFast_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(SpiMaxDmaFastTransfer)"!]U];
[!ENDCODE!][!//
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!][!//

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

[!NOCODE!][!//
[!VAR "ExIndex"="0"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
[!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
[!IF "not(contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))),'_')),'LPSPI'))"!]
[!CODE!][!//
/* Spi_Ip_DeviceAttributes[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Device Attribute Configuration of Spi*/
const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
    [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
    [!IF "$SeparateSpiClockRefer = 'true'"!] [!// Source clock is different between SPI Instances
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
            [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
            [!VAR "DualClockEnabled" = "'true'"!][!//
            [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
                [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
            [!ENDSELECT!][!//
            [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!ELSE!]
            [!VAR "DualClockEnabled" = "'false'"!][!//
        [!ENDIF!][!//
    [!ENDIF!]
    [!CALL "GenerateExternalDeviceInfo"!]
    
[!CODE!][!//
[!INDENT "4"!]
    [!"num:i(substring-after(node:value(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitMapping),'_'))"!]U,  /* Instance */
    /* ctar */
    [!IF "$DualClockSupport = 'true'"!][!//
    {
        /* Normal Mode */
    [!ENDIF!][!//
        (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]SPI_CTAR_CPOL(0U)[!//
        [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]SPI_CTAR_CPOL(1U)[!//
        [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
        [!ENDIF!] | /* Clock Polarity (Idle State) */
        [!IF "SpiDataShiftEdge = 'LEADING'"!]SPI_CTAR_CPHA(1U)[!//
        [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!]SPI_CTAR_CPHA(0U)[!//
        [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
        [!ENDIF!] | /* Clock Phase */
        SPI_CTAR_PCSSCK([!"num:i($OptimalPCSCLK)"!]U) | SPI_CTAR_CSSCK([!"num:i($OptimalSCSCLK)"!]U) | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
        SPI_CTAR_PASC([!"num:i($OptimalPASC)"!]U) | SPI_CTAR_ASC([!"num:i($OptimalSASC)"!]U) | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
        SPI_CTAR_PDT([!"num:i($OptimalPDT)"!]U) | SPI_CTAR_DT([!"num:i($OptimalSDT)"!]U) | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
        SPI_CTAR_PBR([!"num:i($OptimalPBR)"!]U) | SPI_CTAR_BR([!"num:i($OptimalBR)"!]U) | SPI_CTAR_DBR([!"num:i($OptimalDBR)"!]u)), /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateNormal)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorNormal) div 100"!]% */
    [!IF "$DualClockSupport = 'true'"!][!//
        [!IF "$DualClockEnabled = 'true'"!][!//
        /* Alternate Mode */
        (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]SPI_CTAR_CPOL(0U)[!//
        [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]SPI_CTAR_CPOL(1U)[!//
        [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
        [!ENDIF!] | /* Clock Polarity (Idle State) */
        [!IF "SpiDataShiftEdge = 'LEADING'"!]SPI_CTAR_CPHA(1U)[!//
        [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!]SPI_CTAR_CPHA(0U)[!//
        [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
        [!ENDIF!] | /* Clock Phase */
        SPI_CTAR_PCSSCK([!"num:i($OptimalPCSCLKAlternate)"!]U) | SPI_CTAR_CSSCK([!"num:i($OptimalSCSCLKAlternate)"!]U) | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2ClkAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2ClkErrorAlternate) div 100"!]% */
        SPI_CTAR_PASC([!"num:i($OptimalPASCAlternate)"!]U) | SPI_CTAR_ASC([!"num:i($OptimalSASCAlternate)"!]U) | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeClk2CsErrorAlternate) div 100"!]% */
        SPI_CTAR_PDT([!"num:i($OptimalPDTAlternate)"!]U) | SPI_CTAR_DT([!"num:i($OptimalSDTAlternate)"!]U) | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2CsErrorAlternate) div 100"!]% */
        SPI_CTAR_PBR([!"num:i($OptimalPBRAlternate)"!]U) | SPI_CTAR_BR([!"num:i($OptimalBRAlternate)"!]U) | SPI_CTAR_DBR([!"num:i($OptimalDBRAlternate)"!]u)) /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateAlternate)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorAlternate) div 100"!]% */
       [!ELSE!][!//$DualClockEnabled = 'true'
        (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]SPI_CTAR_CPOL(0U)[!//
        [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]SPI_CTAR_CPOL(1U)[!//
        [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
        [!ENDIF!] | /* Clock Polarity (Idle State) */
        [!IF "SpiDataShiftEdge = 'LEADING'"!]SPI_CTAR_CPHA(1U)[!//
        [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!]SPI_CTAR_CPHA(0U)[!//
        [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
        [!ENDIF!] | /* Clock Phase */
        SPI_CTAR_PCSSCK([!"num:i($OptimalPCSCLK)"!]U) | SPI_CTAR_CSSCK([!"num:i($OptimalSCSCLK)"!]U) | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
        SPI_CTAR_PASC([!"num:i($OptimalPASC)"!]U) | SPI_CTAR_ASC([!"num:i($OptimalSASC)"!]U) | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
        SPI_CTAR_PDT([!"num:i($OptimalPDT)"!]U) | SPI_CTAR_DT([!"num:i($OptimalSDT)"!]U) | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
        SPI_CTAR_PBR([!"num:i($OptimalPBR)"!]U) | SPI_CTAR_BR([!"num:i($OptimalBR)"!]U) | SPI_CTAR_DBR([!"num:i($OptimalDBR)"!]u)), /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateNormal)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorNormal) div 100"!]% */       
       [!ENDIF!]
    },
    [!ENDIF!][!//
    (uint32)(SPI_CTARE_FMSZE(0U) | SPI_CTARE_DTCP(1U)), /* ctare */
    /* pushCmd */
    (uint16)((SPI_PUSHR_CTAS(0U)|    /* Use CTAR0 */
    [!IF "SpiEnableCs = 'true'"!][!//
        [!IF "node:exists(SpiCsSelection)"!][!//
            [!IF "SpiCsSelection = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
                SPI_PUSHR_PCS([!"bit:bitset(0, substring-after(SpiCsIdentifier,'PCS'))"!]) | /* Chip Select Pin Via Peripheral Engine*/     
                [!IF "SpiCsContinous = 'FALSE'"!]SPI_PUSHR_CONT(0U) /* Continuous chip select */
                [!ELSEIF "SpiCsContinous = 'TRUE'"!]SPI_PUSHR_CONT(1U) /* Continuous chip select */
                [!ELSE!][!ERROR "Illegal value for SpiCsContinous"!][!//
                [!ENDIF!][!//
            [!ELSEIF "SpiCsSelection = 'CS_VIA_GPIO'"!][!//
                    0x00000000u /* Chip Select Via GPIO */
            [!ENDIF!][!//
        [!ELSE!]0x00000000u /* Chip Select Via GPIO */
        [!ENDIF!][!//
    [!ELSE!]0x00000000u /* Chip Select Via GPIO */
    [!ENDIF!])>>16u),
    &Spi_Ip_DeviceParamsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($ExIndex)"!]U]
[!ENDINDENT!]
};
[!ENDCODE!][!//
    [!VAR "ExIndex"="$ExIndex + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "hwUnitIndex"= "0"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "not(contains(node:value(SpiPhyUnitMapping),'LPSPI'))"!]
    [!IF "(ecu:get('Spi.SpiDMAPresent') = 'TRUE') and (../../SpiGlobalDmaEnable = 'true') and (../../SpiLevelDelivered >0) and (SpiPhyUnitAsyncUseDma = 'true')"!][!//
        [!VAR "NumOfCmdDmaSG"="count(node:ref(SpiPhyTxCmdDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*)"!]
[!CODE!]
/* List of TCD Scatter Gather Id for CMD DMA channel */
static const uint8 Spi_Ip_ListCmdDmaSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfCmdDmaSG)"!]U] =
{
[!ENDCODE!]
    [!FOR "SGIndex" = "0" TO "num:i($NumOfCmdDmaSG - 1)"!]
[!CODE!]
    (uint8)[!"node:value(node:ref(SpiPhyTxCmdDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*[$SGIndex + 1]/dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_ScatterGatherElementNameType)"!][!//
    [!IF "$SGIndex < ($NumOfCmdDmaSG - 1)"!],[!ENDIF!]
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!]

    [!IF "node:exists(SpiMaxDmaFastTransfer)"!]
        [!IF "node:fallback(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_EnableScatterGather, 'false') = 'false'"!]
            [!ERROR!] Tx Dma channel of [!"@name"!] wasn't be enabled Scatter/Gather in dma fast mode.[!ENDERROR!]
        [!ENDIF!]
        [!IF "node:fallback(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_EnableScatterGather, 'false') = 'false'"!]
            [!ERROR!] Rx Dma channel of [!"@name"!] wasn't be enabled Scatter/Gather in dma fast mode.[!ENDERROR!]
        [!ENDIF!]
        [!VAR "NumOfTxDmaFastSG"="count(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*)"!]
[!CODE!]
#if ((SPI_IP_DMA_USED == STD_ON) && (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
/* List of TCD Scatter Gather Id for Tx DMA channel used in Dma Fast transfer */
static const uint8 Spi_Ip_ListTxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfTxDmaFastSG)"!]U] =
{
[!ENDCODE!]
    [!FOR "SGIndex" = "0" TO "num:i($NumOfTxDmaFastSG - 1)"!]
[!CODE!]
    (uint8)[!"node:value(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*[$SGIndex + 1]/dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_ScatterGatherElementNameType)"!][!//
    [!IF "$SGIndex < ($NumOfTxDmaFastSG - 1)"!],[!ENDIF!]
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]

    [!VAR "NumOfRxDmaFastSG"="count(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*)"!]
[!CODE!]
/* List of TCD Scatter Gather Id for Rx DMA channel used in Dma Fast transfer */
static const uint8 Spi_Ip_ListRxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfRxDmaFastSG)"!]U] =
{
[!ENDCODE!]
    [!FOR "SGIndex" = "0" TO "num:i($NumOfRxDmaFastSG - 1)"!]
[!CODE!]
    (uint8)[!"node:value(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*[$SGIndex + 1]/dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_ScatterGatherElementNameType)"!][!//
    [!IF "$SGIndex < ($NumOfRxDmaFastSG - 1)"!],[!ENDIF!]
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
#endif
[!ENDCODE!]
    [!ENDIF!]

[!IF "SpiPhyUnitMode = 'SPI_MASTER'"!][!//
    [!VAR "Master" = "1"!]
[!ELSE!]
    [!VAR "Master" = "0"!]
[!ENDIF!][!// "SpiPhyUnitMode     = 'SPI_MASTER'"

[!VAR "SamplePoint" = "0"!]
[!IF "SpiModifiedTransferFormatEnable = 'true'"!][!//
    [!VAR "ModifiedFormat" = "1"!]
    [!VAR "SamplePoint" = "SpiSamplePoint"!]
[!ELSE!]
    [!VAR "ModifiedFormat" = "0"!]
[!ENDIF!]

[!VAR "HwIndex" = "@index"!]
[!VAR "Polarity" = "0"!]
[!LOOP "../../../SpiDriver/SpiExternalDevice/*"!][!//
    [!VAR "ExtDevHwIndex" = "num:i(substring-after(SpiHwUnit,'CSIB'))"!]
    [!IF "$HwIndex = $ExtDevHwIndex"!]
        [!VAR "PCSIndex" = "num:i(substring-after(SpiCsIdentifier,'PCS'))"!]
        [!IF "SpiCsPolarity = 'LOW'"!]
            [!VAR "Polarity" = "bit:bitset($Polarity, $PCSIndex)"!]
        [!ENDIF!]
    [!ENDIF!][!// "$HwIndex = $ExtDevHwIndex"
[!ENDLOOP!]
[!CODE!][!//
/* The SPI Hw Unit configuration structures */
const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!"num:i(substring-after(SpiPhyUnitMapping,'_'))"!]U,  /* Instance */
    /* mcr */
    (uint32)(SPI_MCR_MSTR([!"num:i($Master)"!]U) | SPI_MCR_CONT_SCKE(0U) | SPI_MCR_FRZ(0U) | SPI_MCR_MTFE([!"num:i($ModifiedFormat)"!]U) | 
    SPI_MCR_PCSIS([!"num:i($Polarity)"!]U) | SPI_MCR_MDIS(0U) | SPI_MCR_SMPL_PT([!"num:i($SamplePoint)"!]) | SPI_MCR_XSPI(1U) | SPI_MCR_HALT(1U)),
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    (boolean)[!IF "$Master = 0"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    #endif
    #if (SPI_IP_DMA_USED == STD_ON)
[!ENDCODE!][!//
    [!IF "(ecu:get('Spi.SpiDMAPresent') = 'TRUE') and (../../SpiGlobalDmaEnable = 'true') and (../../SpiLevelDelivered >0) and (SpiPhyUnitAsyncUseDma = 'true')"!][!//
[!CODE!][!//
    (boolean)TRUE,
    (uint8)[!"node:value(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_LogicName)"!], /* txDmaChannel */
    (uint8)[!"node:value(node:ref(SpiPhyTxCmdDmaChannel)/dmaLogicChannel_LogicName)"!], /* txCmdDmaChannel */
    (uint8)[!"num:i($NumOfCmdDmaSG)"!], /* u8NumTxCmdDmsSGId */
    Spi_Ip_ListCmdDmaSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], /* pu8TxCmdDmaSGId */
    (uint8)[!"node:value(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_LogicName)"!], /* rxDmaChannel */
    #if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    [!IF "node:exists(SpiMaxDmaFastTransfer)"!]
    (uint8)[!"num:i(SpiMaxDmaFastTransfer)"!]U, /* u8NumOfDmaFastTransfer */
    Spi_Ip_CmdDmaFast_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!"num:i($NumOfRxDmaFastSG)"!]U, /* Number of TCD Scatter Gather for Rx */
    Spi_Ip_ListTxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Spi_Ip_ListRxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!ELSE!]
    (uint8)0U, /* u8NumOfDmaFastTransfer */
    NULL_PTR, /* pCmdDmaFast */
    (uint8)0U,
    NULL_PTR, /* List of Tx SG Id */
    NULL_PTR, /* List of Rx SG Id */
    [!ENDIF!]
    #endif
[!ENDCODE!][!//
    [!ELSE!]
[!CODE!][!//
    (boolean)FALSE,
    (uint8)0U, /* txDmaChannel */
    (uint8)0U, /* txCmdDmaChannel */
    (uint8)0U, /* u8NumTxCmdDmsSGId */
    NULL_PTR, /* pu8TxCmdDmaSGId */
    (uint8)0U, /* rxDmaChannel */
    #if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    (uint8)0U, /* u8NumOfDmaFastTransfer */
    NULL_PTR, /* pCmdDmaFast */
    (uint8)0U,
    NULL_PTR, /* List of Tx SG Id */
    NULL_PTR, /* List of Rx SG Id */
    #endif
[!ENDCODE!][!//
    [!ENDIF!]
[!CODE!][!//
    #endif  /* (SPI_IP_DMA_USED == STD_ON) */
    SPI_IP_POLLING, /* Transfer mode */
    (uint8)[!"num:i($hwUnitIndex)"!]U /* State structure element from the array */
};
[!ENDCODE!][!//
[!VAR "hwUnitIndex"= "$hwUnitIndex + 1"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!][!//

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
