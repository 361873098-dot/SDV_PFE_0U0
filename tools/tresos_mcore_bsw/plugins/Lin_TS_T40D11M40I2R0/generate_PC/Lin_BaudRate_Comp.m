[!/**
    @file    LIN_VersionCheck_Inc.m
    @version 4.0.2

    @brief   AUTOSAR Lin - Brief description.
    @details Version check variables vor Lin_PBcfg.c

    Project RTD AUTOSAR 4.4
    Patform CORTEXM
    Peripheral LINFLEXD
    Dependencies none

    ARVersion 4.4.0
    ARRevision ASR_REL_4_4_REV_0000
    ARConfVariant
    SWVersion 4.0.2
    BuildVersion S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630

    (c) Copyright 2020-2023 NXP Semiconductors. 
    All Rights Reserved.
*/!]
[!/*==================================================================================================
==================================================================================================
*/!]
[!VAR "ClockFrequencyFromMcu" = "McuClockReferencePointFrequency"!]
[!/* LINFLEXD baudrate */!]
    [!VAR "LFDIV" = "($ClockFrequencyFromMcu div ($LinBaudrate * 16))"!][!//
    [!VAR "temp1" = "num:i($LFDIV)"!][!//
    [!VAR "temp2" = "$LFDIV - $temp1"!][!//
    [!VAR "LINFBRR" = "round($temp2 * 16)"!][!//
    [!VAR "LINFBRR" = "num:inttohex($LINFBRR,8)"!][!//
    [!VAR "LINIBRR" = "num:inttohex($temp1,8)"!][!//
    [!VAR "LINIBRR" = "num:hextoint($LINIBRR)"!][!//
    [!VAR "LINFBRR" = "num:hextoint($LINFBRR)"!][!//
    [!VAR "LINIBRR" = "bit:shl($LINIBRR,8)"!][!//
    [!VAR "BaudrateConf_Value" = "bit:or($LINIBRR,$LINFBRR)"!][!//
    [!VAR "BaudrateConf_Value" = "num:inttohex($BaudrateConf_Value,8)"!][!//

