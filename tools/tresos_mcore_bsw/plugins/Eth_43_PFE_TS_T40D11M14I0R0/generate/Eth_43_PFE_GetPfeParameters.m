[!NOCODE!][!//
/*
 *  @file    Eth_43_PFE_GetPfeParameters.m
 *
 *  @brief   AUTOSAR Eth_43_PFE - Macros for driver parameters calculation
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
 *  Copyright 2022 NXP
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

[!VAR "meta_buffer_size" = "32"!]

[!// output: "$power_of_2"
[!MACRO "RoundUpToPowerOf2", "value" = "0"!][!//
[!NOCODE!]
    [!VAR "power_of_2" = "1"!]
    [!FOR "dummy" = "0" TO "63" STEP "1"!]
        [!IF "$value > $power_of_2"!]
            [!VAR "power_of_2" = "$power_of_2 * 2"!]
        [!ELSE!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!// output: rx_fifo_buf_num_max tx_fifo_buf_num_max
[!MACRO "rx_tx_fifo_depth_per_controller"!][!//
[!NOCODE!]
    [!VAR "rx_fifo_buf_num_max" = "0"!]
    [!LOOP "EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*"!]
        [!IF "$rx_fifo_buf_num_max < EthCtrlConfigIngressFifoBufTotal"!]
            [!VAR "rx_fifo_buf_num_max" = "EthCtrlConfigIngressFifoBufTotal"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$rx_fifo_buf_num_max > 0"!]
        [!CALL "RoundUpToPowerOf2", "value" = "$rx_fifo_buf_num_max"!][!// calculated value stored to "$power_of_2"
        [!VAR "rx_fifo_buf_num_max" = "$power_of_2"!]
    [!ENDIF!]
    [!VAR "tx_fifo_buf_num_max" = "0"!]
    [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!]
        [!IF "$tx_fifo_buf_num_max < EthCtrlConfigEgressFifoBufTotal"!]
            [!VAR "tx_fifo_buf_num_max" = "EthCtrlConfigEgressFifoBufTotal"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$tx_fifo_buf_num_max > 0"!]
        [!CALL "RoundUpToPowerOf2", "value" = "$tx_fifo_buf_num_max"!][!// calculated value stored to "$power_of_2"
        [!VAR "tx_fifo_buf_num_max" = "$power_of_2"!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!// output: rx_buf_size rx_buf_num rx_bd_num
[!MACRO "CalculateRxBufPerHifInConfigset"!][!//
[!NOCODE!]
    [!VAR "rx_buf_num" = "0"!]
    [!VAR "rx_buf_size_max" = "0"!]
    [!LOOP "EthCtrlConfig/*"!]
        [!LOOP "EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*"!]
            [!IF "$rx_buf_size_max < 1522"!]  [!//1522 for EthCtrlConfigIngressFifoBufLenByte
                [!VAR "rx_buf_size_max" = "1522"!] [!//1522 for EthCtrlConfigIngressFifoBufLenByte
            [!ENDIF!]
            [!VAR "rx_buf_num" = "$rx_buf_num + EthCtrlConfigIngressFifoBufTotal"!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!// Workaround for Errata ERR051211 - shall use at least 72 extra Rx buffers per standard HIF (in each configuration)
    [!IF "(../EthGeneral/EthVendorSpecific/EnERR051211Workaround = 'true') and (../EthGeneral/EthVendorSpecific/EthCommonHif != 'HIF_NOCPY')"!]
        [!VAR "rx_buf_num" = "$rx_buf_num + 72"!]
    [!ENDIF!]
    [!// Add Rx buffers for IDEX frames
    [!IF "../EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'true'"!]
        [!VAR "rx_buf_num" = "$rx_buf_num + 4"!]
    [!ENDIF!]
    [!VAR "rx_bd_num" = "$rx_buf_num + 1"!][!// Need to have at least 1 disabled BD
    [!VAR "rx_buf_size" = "num:i(($rx_buf_size_max+16+7) div 8) * 8"!] [!// Increase by 16 bytes and align to 8
    [!// No buffers for HIF_NOCPY
    [!IF "../EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF_NOCPY'"!]
        [!VAR "rx_buf_size" = "0"!]
        [!VAR "rx_buf_num" = "0"!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!// output: rx_buf_poolsz_max rx_meta_buf_poolsz_max rx_bd_num_max
[!MACRO "CalculateTotalMaximumRxValues"!][!//
[!NOCODE!]
    [!// Calculate pre-compile values that are used for Eth buffer and BD memory allocations
    [!// Max of all config sets
    [!VAR "rx_buf_poolsz_max"  = "0"!]
    [!VAR "rx_bd_num_max" = "0"!]
    [!VAR "rx_buf_num_max" = "0"!]
    [!SELECT "EthConfigSet"!][!// Select configuration
        [!// Maximal number of Rx BDs for BD memory allocation
        [!CALL "CalculateRxBufPerHifInConfigset"!]
        [!IF "$rx_buf_num_max < $rx_buf_num"!]
            [!VAR "rx_buf_num_max" = "$rx_buf_num"!]
        [!ENDIF!]
        [!IF "$rx_bd_num_max < $rx_bd_num"!]
            [!VAR "rx_bd_num_max" = "$rx_bd_num"!]
        [!ENDIF!]
        [!IF "$rx_buf_poolsz_max < ($rx_buf_size * $rx_buf_num)"!]
            [!VAR "rx_buf_poolsz_max" = "$rx_buf_size * $rx_buf_num"!]
        [!ENDIF!]
    [!ENDSELECT!]
    [!VAR "rx_meta_buf_poolsz_max" = "$rx_buf_num_max * $meta_buffer_size"!]
    [!// Avoid zero sized array (in case only HIF_NOCPY is used)
    [!IF "$rx_meta_buf_poolsz_max < 1"!]
        [!VAR "rx_meta_buf_poolsz_max" = "1"!]
    [!ENDIF!]
    [!IF "$rx_buf_poolsz_max < 1"!]
        [!VAR "rx_buf_poolsz_max" = "1"!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!// output: tx_bd_num
[!MACRO "CalculateTxBDPerHifInConfigset"!][!//
[!NOCODE!]
    [!VAR "tx_bd_num" = "0"!]
    [!LOOP "EthCtrlConfig/*"!]
        [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!]
            [!VAR "tx_bd_num" = "$tx_bd_num + EthCtrlConfigEgressFifoBufTotal"!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!// Add Tx BDs for RPC frames
    [!IF "../EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'true'"!]
        [!VAR "tx_bd_num" = "$tx_bd_num + 4"!]
    [!ENDIF!]
    [!VAR "tx_bd_num" = "$tx_bd_num + 1"!][!// Need to have at least 1 disabled BD
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!// output: tx_buf_poolsz_max tx_fifo_num_max tx_fifo_buf_num_max tx_ctrl_buf_num_max tx_bd_num_max
[!MACRO "CalculateTotalMaximumTxValues"!][!//
[!NOCODE!]
    [!// Calculate pre-compile values that are used for Eth buffer and BD memory allocations
    [!// Max of all config sets
    [!VAR "tx_buf_poolsz_max"  = "1"!][!// Avoid zero sized array (in case HIF_NOCPY is used)
    [!VAR "tx_fifo_num_max"  = "0"!]
    [!VAR "tx_fifo_buf_num_max"  = "0"!]
    [!VAR "tx_ctrl_buf_num_max"  = "0"!]
    [!VAR "tx_bd_num_max" = "0"!]
    [!SELECT "EthConfigSet"!][!// Select configuration
        [!// Total values for this config set
        [!VAR "tx_buf_num" = "0"!]
        [!VAR "tx_buf_poolsz" = "0"!]
        [!LOOP "EthCtrlConfig/*"!][!//
            [!VAR "tx_ctrl_buf_num" = "0"!]
            [!IF "$tx_fifo_num_max < count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)"!]
                [!VAR "tx_fifo_num_max" = "count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)"!]
            [!ENDIF!]
            [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!]
                [!IF "../../../../../../EthGeneral/EthVendorSpecific/EthCommonHif != 'HIF_NOCPY'"!]
                    [!// Add 16 bytes per buffer for Tx header
                    [!// Align buffer size to be exact multiple of 8
                    [!VAR "tx_buf_poolsz" = "$tx_buf_poolsz + EthCtrlConfigEgressFifoBufTotal * num:i((EthCtrlConfigEgressFifoBufLenByte + 7 + 16) div 8) * 8"!]
                [!ENDIF!]
                [!VAR "tx_buf_num" = "$tx_buf_num + EthCtrlConfigEgressFifoBufTotal"!]
                [!VAR "tx_ctrl_buf_num" = "$tx_ctrl_buf_num + EthCtrlConfigEgressFifoBufTotal"!]
                [!IF "$tx_fifo_buf_num_max < EthCtrlConfigEgressFifoBufTotal"!]
                    [!VAR "tx_fifo_buf_num_max" = "EthCtrlConfigEgressFifoBufTotal"!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$tx_ctrl_buf_num_max < $tx_ctrl_buf_num"!]
                [!VAR "tx_ctrl_buf_num_max" = "$tx_ctrl_buf_num"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!// Add values for RPC
        [!// Calculate maximum values for Tx
        [!IF "$tx_buf_poolsz_max < $tx_buf_poolsz"!]
            [!VAR "tx_buf_poolsz_max" = "$tx_buf_poolsz"!]
        [!ENDIF!]
        
        [!// Maximal number of Tx BDs for BD memory allocation
        [!CALL "CalculateTxBDPerHifInConfigset"!][!// output: tx_bd_num
        [!IF "$tx_bd_num_max < $tx_bd_num"!]
            [!VAR "tx_bd_num_max" = "$tx_bd_num"!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!NOCODE!][!//
[!VAR "HifInterruptEnabled" = "false()"!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!] [!// Loop over the controller config
  [!IF "EthCtrlEnableRxInterrupt = 'true'"!][!//
    [!VAR "HifInterruptEnabled" = "true()"!]
    [!BREAK!]
  [!ENDIF!][!//
  [!IF "EthCtrlEnableTxInterrupt = 'true'"!][!//
    [!VAR "HifInterruptEnabled" = "true()"!]
    [!BREAK!]
  [!ENDIF!][!//
[!ENDLOOP!][!//End loop of controller
[!ENDNOCODE!][!//
