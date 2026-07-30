[!NOCODE!][!//Do not generate any output, only warnings and errors
/*
 *  \file    Eth_VersionCheck_Inc.m
 *
 *  \brief   AUTOSAR Eth_43_PFE - version check macro.
 *  \details Version checks.
 *  
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
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
[!/* Multiple Inclusion Protection *** */!][!//
[!IF "not(var:defined('ETH_CHECKS_M'))"!][!//
    [!VAR "ETH_CHECKS_M"="true()"!][!//
    [!// Peripheral detection
    [!MACRO "CheckValidConfig"!][!//
        [!LOOP "EthConfigSet/*"!][!//
            [!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
                [!VAR "VarEthCtrlIdx" = "EthCtrlIdx"!]
            [!ENDLOOP!]
        [!ENDLOOP!]
    [!ENDMACRO!]
[!ENDIF!]
[!ENDNOCODE!]