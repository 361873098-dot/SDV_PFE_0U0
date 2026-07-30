[!NOCODE!][!//
/*
 *  \file    Eth_43_PFE_GetDemParameters.m
 *  \version 1.0.1
 *
 *  \brief   AUTOSAR Eth_43_PFE - Get DEM parameters macro.
 *  \details Get DEM parameters for driver.
 *  
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
 *      Copyright 2017,2019-2020, 2022 NXP
 *
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
 */
[!ENDNOCODE!][!//
[!MACRO "GetDemParameters"!][!//
  [!NOCODE!][!//

    [!IF "node:refvalid(EthDemEventParameterRefs/ETH_E_ACCESS)"!]
      [!VAR "EthDemEAccessEventId" = "node:value(node:refs(EthDemEventParameterRefs/ETH_E_ACCESS)/DemEventId)"!]
    [!ENDIF!]
    [!IF "(node:exists(EthDemEventParameterRefs/ETH_E_ACCESS)='true') and (node:value(../../../EthGeneral/EthVendorSpecific/EthDisableDemEventDetect) = 'false')"!][!// This also checks if the optional part is enabled
      [!VAR "EthDemEAccessEnabled" = "'true'"!]
    [!ELSE!]
      [!VAR "EthDemEAccessEnabled" = "'false'"!]
      [!VAR "EthDemEAccessEventId" = "num:i(0)"!]
    [!ENDIF!]
    [!IF "(../../../EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false') and (node:exists(EthDemEventParameterRefs) = true())"!]
      [!SELECT "EthDemEventParameterRefs"!]
        [!IF "node:refvalid(ETH_E_ACCESS) and node:exists(ETH_E_ACCESS)"!]
          [!VAR "EthDemEAccessEnabled" = "'true'"!]
          [!VAR "EthDemEAccessEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_ACCESS)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEAccessEnabled" = "'false'"!]
          [!VAR "EthDemEAccessEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_RX_FRAMES_LOST) and node:exists(ETH_E_RX_FRAMES_LOST)"!]
          [!VAR "EthDemFrameLostEnabled" = "'true'"!]
          [!VAR "EthDemFrameLostEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_RX_FRAMES_LOST)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemFrameLostEnabled" = "'false'"!]
          [!VAR "EthDemFrameLostEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_CRC) and node:exists(ETH_E_CRC)"!]
          [!VAR "EthDemECRCEnabled" = "'true'"!]
          [!VAR "EthDemECRCEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_CRC)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemECRCEnabled" = "'false'"!]
          [!VAR "EthDemECRCEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_UNDERSIZEFRAME) and node:exists(ETH_E_UNDERSIZEFRAME)"!]
          [!VAR "EthDemEUnderSizeEnabled" = "'true'"!]
          [!VAR "EthDemEUnderSizeEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_UNDERSIZEFRAME)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEUnderSizeEnabled" = "'false'"!]
          [!VAR "EthDemEUnderSizeEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_OVERSIZEFRAME) and node:exists(ETH_E_OVERSIZEFRAME)"!]
          [!VAR "EthDemEOverSizeEnabled" = "'true'"!]
          [!VAR "EthDemEOverSizeEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_OVERSIZEFRAME)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEOverSizeEnabled" = "'false'"!]
          [!VAR "EthDemEOverSizeEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_ALIGNMENT) and node:exists(ETH_E_ALIGNMENT)"!]
          [!VAR "EthDemEAlignmentEnabled" = "'true'"!]
          [!VAR "EthDemEAlignmentEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_ALIGNMENT)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEAlignmentEnabled" = "'false'"!]
          [!VAR "EthDemEAlignmentEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_SINGLECOLLISION) and node:exists(ETH_E_SINGLECOLLISION)"!]
          [!VAR "EthDemE1ColEnabled" = "'true'"!]
          [!VAR "EthDemE1ColEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_SINGLECOLLISION)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemE1ColEnabled" = "'false'"!]
          [!VAR "EthDemE1ColEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_MULTIPLECOLLISION) and node:exists(ETH_E_MULTIPLECOLLISION)"!]
          [!VAR "EthDemEMColEnabled" = "'true'"!]
          [!VAR "EthDemEMColEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_MULTIPLECOLLISION)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEMColEnabled" = "'false'"!]
          [!VAR "EthDemEMColEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_LATECOLLISION) and node:exists(ETH_E_LATECOLLISION)"!]
          [!VAR "EthDemELColEnabled" = "'true'"!]
          [!VAR "EthDemELColEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_LATECOLLISION)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemELColEnabled" = "'false'"!]
          [!VAR "EthDemELColEventId" ="num:i(0)"!]
        [!ENDIF!]
      [!ENDSELECT!]
    [!ELSE!]
      [!VAR "EthDemEAccessEnabled" = "'false'"!]
      [!VAR "EthDemEAccessEventId" ="num:i(0)"!]
      [!VAR "EthDemFrameLostEnabled" = "'false'"!]
      [!VAR "EthDemFrameLostEventId" ="num:i(0)"!]
      [!VAR "EthDemECRCEnabled" = "'false'"!]
      [!VAR "EthDemECRCEventId" ="num:i(0)"!]
      [!VAR "EthDemEUnderSizeEnabled" = "'false'"!]
      [!VAR "EthDemEUnderSizeEventId" ="num:i(0)"!]
      [!VAR "EthDemEOverSizeEnabled" = "'false'"!]
      [!VAR "EthDemEOverSizeEventId" ="num:i(0)"!]
      [!VAR "EthDemEAlignmentEnabled" = "'false'"!]
      [!VAR "EthDemEAlignmentEventId" ="num:i(0)"!]
      [!VAR "EthDemE1ColEnabled" = "'false'"!]
      [!VAR "EthDemE1ColEventId" ="num:i(0)"!]
      [!VAR "EthDemEMColEnabled" = "'false'"!]
      [!VAR "EthDemEMColEventId" ="num:i(0)"!]
      [!VAR "EthDemELColEnabled" = "'false'"!]
      [!VAR "EthDemELColEventId" ="num:i(0)"!]
    [!ENDIF!]
  [!ENDNOCODE!][!//
[!ENDMACRO!][!//