/**
*   @file    Can_43_LLCE_Macros.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Macros for configuration generation
*
*   @addtogroup CAN_LLCE
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.4
*   Build Version        : S32_RTD_1_0_4_D2204_ASR_REL_4_4_REV_0000_20220429
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
[!VAR "C2PCIE_CNT"  = "num:i(0)"!][!//
[!VAR "C2O_CNT"  = "num:i(0)"!][!//

[!AUTOSPACING!]
[!NOCODE!]
[!// To be called in a CAN Ctrl context
[!MACRO "GetRWDestInterfaceFromCtrl"!][!//
[!IF "not(node:exists(RWDestInterface))"!][!//
[!CODE!][!WS "8"!](uint8)[!"substring-after(CanHwChannel,'BCAN_')"!]U[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!WS "8"!](uint8)[!"substring-after(RWDestInterface,'FIFO_INTERFACE_')"!]U[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!]

[!NOCODE!][!//
[!// To be called in a HOH context
[!MACRO "GetRWDestInterfaceFromHOH"!][!//
[!AUTOSPACING!][!//
[!IF "not(node:exists(node:ref(CanControllerRef)/RWDestInterface))"!][!//
[!CODE!][!WS "8"!](uint8)[!"substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_')"!]U[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!WS "8"!](uint8)[!"substring-after(node:ref(CanControllerRef)/RWDestInterface,'FIFO_INTERFACE_')"!]U[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!][!//

[!MACRO "GenerateFilterConfig"!][!//
[!INDENT "6"!][!//
    [!IF "node:exists('RangeFilter')"!][!//
        [!IF "num:i(RangeFilter/RangeEnd) > 2047"!][!//
            (uint32)([!"num:i(RangeFilter/RangeEnd)"!]U | LLCE_CAN_MB_IDE_U32), /* uIdMask = RangeEnd */
        [!ELSE!][!//
            (uint32)[!"num:i(RangeFilter/RangeEnd)"!], /* uIdMask = RangeEnd */
        [!ENDIF!][!//
    [!ELSE!][!//
        [!IF "(CanHandleType = 'FULL')"!][!//
            (uint32)((CAN_43_LLCE_MAX_IDMASK[!//
        [!ELSE!][!//
            (uint32)((([!"num:inttohex(CanHwFilter/CanHwFilterMask)"!]U & CAN_43_LLCE_MAX_IDMASK)[!//
        [!ENDIF!][!//
        | LLCE_CAN_MB_RTR_U32) [!//
        [!IF "CanIdType != 'MIXED'"!] | [!ELSE!] & ~[!ENDIF!] LLCE_CAN_MB_IDE_U32),  /* uIdMask */
    [!ENDIF!][!//
    [!IF "node:exists('RangeFilter')"!][!//
        [!IF "num:i(RangeFilter/RangeStart) > 2047"!][!//
            (uint32)([!"num:i(RangeFilter/RangeStart)"!]U | LLCE_CAN_MB_IDE_U32), /* MessageId = RangeStart*/
        [!ELSE!][!//
            (uint32)[!"num:i(RangeFilter/RangeStart)"!], /* MessageId = RangeStart */
        [!ENDIF!][!//
    [!ELSE!][!//
        (uint32)(([!"num:inttohex(CanHwFilter/CanHwFilterCode)"!]U & CAN_43_LLCE_MAX_IDMASK)[!IF "CanIdType = 'EXTENDED'"!] | LLCE_CAN_MB_IDE_U32[!ENDIF!]),   /* MessageId */
    [!ENDIF!][!//
        (uint16)[!"num:inttohex(CanObjectId)"!]U, /* FilterId */
    [!IF " (node:exists(CanHwObjectCount))"!][!//
        (uint16)[!"num:inttohex(CanHwObjectCount)"!], /* MBCount */
    [!ELSE!][!//
        (uint16)1U, /* MBCount */
    [!ENDIF!][!//
    (uint16)0U, /* Output filter address */
        [!IF "node:refexists(CanMainFunctionRWPeriodRef) and (((node:ref(CanControllerRef)/CanRxProcessing = 'MIXED') and (CanHardwareObjectUsesPolling = 'true')) or (((node:ref(CanControllerRef)/CanRxProcessing = 'POLLING'))))"!][!//
            (uint8)[!"num:i(node:ref(CanMainFunctionRWPeriodRef)/RxInterface)"!]U,   /* Rx is reported through this interface. */
        [!ELSE!][!//
            [!CALL "GetRWDestInterfaceFromHOH"!], /* Rx is reported through this interface . */
        [!ENDIF!][!//
    [!IF "node:exists('RangeFilter')"!][!//
        LLCE_CAN_ENTRY_CFG_RANGED,
    [!ELSEIF "(CanHandleType = 'FULL')"!][!//
        LLCE_CAN_ENTRY_EXACT_MATCH,
    [!ELSE!][!//
        LLCE_CAN_ENTRY_CFG_MASKED,
    [!ENDIF!][!//
    [!IF "node:exists('CanObjectPayloadLength') and (CanObjectPayloadLength='CAN_OBJECT_PL_8')"!][!//
        USE_SHORT_MB /* Use 8B size Hw Object */
    [!ELSE!][!//
        USE_LONG_MB /* Use 64B size Hw Object */
    [!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDMACRO!]!// GenerateFilterConfig

[!MACRO "CheckEthBufferSize"!][!//
    [!VAR "AVTP_NTSCF_BRIEF" = "num:i(26 + 8)"!][!//general header + BRIEF size
    [!VAR "AVTP_NTSCF_FULL" = "num:i(26 + 16)"!][!//general header size + FULL size
    [!VAR "AVTP_TSCF_BRIEF" = "num:i(38 + 8)"!][!//general header size + BRIEF size
    [!VAR "AVTP_TSCF_FULL" = "num:i(38 + 16)"!][!//general header size + FULL size
    [!VAR "UDP" = "num:i(42 + 8)"!][!// header size + CAN metadata
    [!VAR "CAN_PAYLOAD" = "num:i(0)"!][!//
    [!VAR "MIN_BUFFER_SIZE" = "num:i(0)"!][!//

    [!IF "node:exists(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable)"!][!//
        [!IF "node:exists(node:ref(node:ref(CanControllerRef)/CanControllerDefaultBaudrate)/CanControllerFdBaudrateConfig)"!][!//
            [!VAR "CAN_PAYLOAD" = "num:i(64)"!][!//
        [!ELSE!]
            [!VAR "CAN_PAYLOAD" = "num:i(8)"!][!//
        [!ENDIF!][!//
        [!IF "node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/EncapsulationType = 'AVTP_NTSCF_BRIEF'"!][!//
            [!VAR "MIN_BUFFER_SIZE"="num:i($CAN_PAYLOAD) + ($AVTP_NTSCF_BRIEF)"!]
        [!ELSE!]
            [!IF "node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/EncapsulationType = 'AVTP_NTSCF_FULL'"!][!//
                [!VAR "MIN_BUFFER_SIZE"="num:i($CAN_PAYLOAD) + ($AVTP_NTSCF_FULL)"!]
            [!ELSE!]
                [!IF "node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/EncapsulationType = 'AVTP_TSCF_BRIEF'"!][!//
                    [!VAR "MIN_BUFFER_SIZE"="num:i($CAN_PAYLOAD) + ($AVTP_TSCF_BRIEF)"!]
                [!ELSE!]
                        [!IF "node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/EncapsulationType = 'AVTP_TSCF_FULL'"!][!//
                            [!VAR "MIN_BUFFER_SIZE"="num:i($CAN_PAYLOAD) + ($AVTP_TSCF_FULL)"!]
                        [!ELSE!]
                            [!IF "(node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/EncapsulationType = 'UDP') or
                                  (node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/EncapsulationType = 'UDP_B')"!][!//
                                [!VAR "MIN_BUFFER_SIZE"="num:i($CAN_PAYLOAD) + ($UDP)"!]
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!IF "node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/Can2EthBufferSize < num:i($CAN_PAYLOAD)"!][!//
            [!WARNING!]Configured buffer size is not large enough to hold a CAN frame for controller CanController_[!"node:ref(CanControllerRef)/CanControllerId"!] ! Configured buffer size is [!"node:ref(node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)/Can2EthRoutingEnable/Can2EthRoutingTableRef)/Can2EthBufferSize"!] and minimum size is [!"num:i($MIN_BUFFER_SIZE)"!].[!ENDWARNING!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDMACRO!][!// CheckEthBufferSize

[!MACRO "CountFilters"!][!//
[!NOCODE!]
[!VAR "GLOBAL_RX_FILTERCOUNT_LIST" = "''"!][!// Array-like variable holding per-channel number of regular filters
[!VAR "GLOBAL_RXAF_FILTERCOUNT_LIST" = "''"!][!// Array-like variable holding per-channel number of advanced filters
[!VAR "GLOBAL_AUX_RX_FILTERCOUNT_LIST" = "''"!][!// Array-like variable holding per-channel number of auxilliary filters
[!SELECT "CanConfigSet"!]
    [!VAR "MAX_CTRL_RX_FILTERS_COUNT" = "num:i(0)"!][!// Number of Filters per hardware controller
    [!VAR "MAX_CTRL_RXAF_FILTERS_COUNT" = "num:i(0)"!][!// Number of Advanced Filters per hardware controller
[!//
    [!FOR "i" = "0" TO "15"!] 
        [!VAR "MAX_CTRL_RX_FILTERS_COUNT" = "num:i(0)"!]
        [!VAR "MAX_CTRL_RXAF_FILTERS_COUNT" = "num:i(0)"!]
        [!VAR "MAX_CTRL_AUX_RX_FILTERS_COUNT" = "num:i(0)"!]
        [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
            [!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true' and CanObjectType = 'RECEIVE'"!]
                [!IF "substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = $i"!]
                    [!IF "node:exists(CanAdvancedFeature)"!]
                        [!CALL "CheckEthBufferSize"!]
                        [!VAR "MAX_CTRL_RXAF_FILTERS_COUNT"="num:i($MAX_CTRL_RXAF_FILTERS_COUNT) + 1"!]
                    [!ELSE!]
                        [!VAR "MAX_CTRL_RX_FILTERS_COUNT"="num:i($MAX_CTRL_RX_FILTERS_COUNT) + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "node:exists(../CanGeneral/CanAuxFilterEnable)"!]
            [!LOOP "CanAuxFilter/*"!]
                [!IF "node:ref(./CanControllerRef)/CanControllerActivation = 'true'"!]
                    [!IF "substring-after(node:ref(./CanControllerRef)/CanHwChannel,'BCAN_') = $i"!]
                        [!VAR "MAX_CTRL_AUX_RX_FILTERS_COUNT"="num:i($MAX_CTRL_AUX_RX_FILTERS_COUNT) + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
        [!VAR "GLOBAL_RX_FILTERCOUNT_LIST"   = "concat($GLOBAL_RX_FILTERCOUNT_LIST,   ' ', num:i($MAX_CTRL_RX_FILTERS_COUNT))"!]
        [!VAR "GLOBAL_RXAF_FILTERCOUNT_LIST" = "concat($GLOBAL_RXAF_FILTERCOUNT_LIST, ' ', num:i($MAX_CTRL_RXAF_FILTERS_COUNT))"!]
        [!VAR "GLOBAL_AUX_RX_FILTERCOUNT_LIST"   = "concat($GLOBAL_AUX_RX_FILTERCOUNT_LIST,   ' ', num:i($MAX_CTRL_AUX_RX_FILTERS_COUNT))"!]
    [!ENDFOR!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!MACRO "GeneratePlatformInit", "CanEcuCPartitionPath" = " 'none' "!][!//
[!AUTOSPACING!][!//
[!SELECT "CanConfigSet"!][!//
[!NOCODE!]
    [!VAR "MAX_IF_RXMB_COUNT" = "num:i(0)"!] [!// Number of MBs per fifo-interface.
    [!VAR "GLOBAL_IF_RXMB_COUNT_LIST" ="''"!] [!// Array-like variable holding per-fifo-interface number of RXMB
    [!VAR "MAX_IF_ACK_COUNT" = "num:i(0)"!] [!// Number of reserved tx confirmation buffers per fifo-interface
    [!VAR "GLOBAL_IF_ACK_COUNT_LIST" ="''"!] [!// Array-like variable holding per-fifo-interface number of ACK buffers
    [!VAR "MAX_POOL_RXMB_COUNT" = "num:i(0)"!][!// Number of MBs of all HRHs reported through  a pooling class
    [!VAR "MAX_POOL_ACK_COUNT" = "num:i(0)"!][!// Number of reserved tx confirmation buffers reported through  a pooling class
[!ENDNOCODE!][!//
[!INDENT "4"!][!//
        /*  Array containing the initialization status of the controllers */
        { [!//
        [!FOR "i" = "0" TO "15"!][!//
            [!VAR "CTRL_CONFIGURED"="num:i(0)"!][!//
            [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!][!//
                [!IF "substring-after(./CanHwChannel,'BCAN_') = $i and (CanControllerActivation = 'true') "!][!//
                    [!IF "$CanEcuCPartitionPath = 'none' or (node:exists(./CanControllerEcucPartitionRef) and (node:value(./CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
                        [!VAR "CTRL_CONFIGURED"="num:i(1)"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "$CTRL_CONFIGURED = 1"!][!//
                [!WS "0"!]INITIALIZED[!//
            [!ELSE!][!//
                [!WS "0"!]UNINITIALIZED[!//
            [!ENDIF!][!//
            [!IF "$i < 15"!][!//
                [!WS "0"!], [!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        },

        /* Array containing maximum number of regular filters per hardware controller */
        {[!//
        [!FOR "i" = "0" TO "15"!][!//
            [!WS "4"!](uint16)[!"text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($i+1)]"!]U[!//
            [!IF "$i < 15"!], [!ENDIF!][!//
        [!ENDFOR!][!//
        [!WS "0"!] },

        /* Array containing maximum number of advanced filters per hardware controller */
        {[!//
        [!FOR "i" = "0" TO "15"!][!//
            [!WS "4"!](uint16)[!"text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($i+1)]"!]U[!//
            [!IF "$i < 15"!], [!ENDIF!][!//
        [!ENDFOR!][!//
        [!WS "0"!] },

        /* Array containing maximum number of INTERRUPT driven receive Message Buffers per FIFO interface. */
        {   [!NOCODE!][!FOR "i" = "0" TO "15"!]
            [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
                [!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true' and CanObjectType = 'RECEIVE'"!]
                    [!IF "$CanEcuCPartitionPath = 'none' or [!//
                        (node:exists(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) and (node:value(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
                        [!IF "( ((substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = $i) and not(node:exists(node:ref(CanControllerRef)/RWDestInterface)) ) [!// Default mapping is 1 to 1 (channel-FIFO_IF)
                            or (node:exists(node:ref(CanControllerRef)/RWDestInterface) and (substring-after(node:ref(CanControllerRef)/RWDestInterface,'FIFO_INTERFACE_') = $i))) [!// Custom FIFO_IF selection per HRH
                          and (((node:ref(CanControllerRef)/CanRxProcessing = 'MIXED') and CanHardwareObjectUsesPolling = 'false') or node:ref(CanControllerRef)/CanRxProcessing = 'INTERRUPT')"!]
                        [!VAR "MAX_IF_RXMB_COUNT"="num:i($MAX_IF_RXMB_COUNT) +  num:i(CanHwObjectCount)"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
                [!VAR "GLOBAL_IF_RXMB_COUNT_LIST" = "concat($GLOBAL_IF_RXMB_COUNT_LIST,   ' ', num:i($MAX_IF_RXMB_COUNT))"!]
                [!VAR "MAX_IF_RXMB_COUNT" = "num:i(0)"!]
            [!ENDFOR!]
        [!FOR "i" = "0" TO "15"!]
            [!CODE!](uint16)[!"text:split($GLOBAL_IF_RXMB_COUNT_LIST)[num:i($i+1)]"!]U[!//
            [!IF "$i < 15"!], [!ENDIF!][!ENDCODE!]
        [!ENDFOR!][!//
        [!ENDNOCODE!][!//
        [!WS "0"!] },

        [!VAR "MAX_CTRL_COUNT" = "num:i(16)"!][!//
        [!VAR "POLLING_CLASSES_CNT" = "num:i(6)"!][!//
        [!VAR "FIRST_POLLING_CLASS" = "$MAX_CTRL_COUNT"!][!//
        [!VAR "LAST_POLLING_CLASS" = "$FIRST_POLLING_CLASS + $POLLING_CLASSES_CNT - 1"!][!//
        /* Array containing maximum number of RX Message Buffers per POLLING class. There are [!"num:i($POLLING_CLASSES_CNT)"!] of them available */
        {   [!FOR "i" = "$FIRST_POLLING_CLASS" TO "$LAST_POLLING_CLASS"!][!//
            [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!][!//
                [!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true' and CanObjectType = 'RECEIVE'"!][!//
                    [!IF "$CanEcuCPartitionPath = 'none' or [!//
                        (node:exists(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) and (node:value(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
                        [!IF "(((node:ref(CanControllerRef)/CanRxProcessing = 'MIXED') and (CanHardwareObjectUsesPolling = 'true')) or (node:ref(CanControllerRef)/CanRxProcessing = 'POLLING'))"!][!//
                            [!IF "node:ref(CanMainFunctionRWPeriodRef)/RxInterface = $i"!][!//
                                [!VAR "MAX_POOL_RXMB_COUNT"="num:i($MAX_POOL_RXMB_COUNT) + num:i(CanHwObjectCount)"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!WS "0"!](uint16)[!"num:i($MAX_POOL_RXMB_COUNT)"!]U[!//
        [!VAR "MAX_POOL_RXMB_COUNT" = "num:i(0)"!][!//
        [!IF "$i < $LAST_POLLING_CLASS"!][!//
        [!WS "0"!], [!//
        [!ENDIF!][!//
        [!ENDFOR!][!//
        [!WS "0"!] },

        /* Array containing maximum number of INTERRUPT driven TX confirmation buffers per FIFO interface. */
        {   [!NOCODE!][!FOR "i" = "0" TO "15"!][!//
            [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
                [!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true' and CanObjectType = 'TRANSMIT'"!]
                    [!IF "$CanEcuCPartitionPath = 'none' or [!//
                        (node:exists(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) and (node:value(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
                        [!IF "( ((substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = $i) and not(node:exists(node:ref(CanControllerRef)/RWDestInterface)) )  [!// Default mapping is 1 to 1 (channel-FIFO_IF)
                            or (node:exists(node:ref(CanControllerRef)/RWDestInterface) and (substring-after(node:ref(CanControllerRef)/RWDestInterface,'FIFO_INTERFACE_') = $i))) [!// Custom FIFO_IF selection per HTH
                             and  (((node:ref(CanControllerRef)/CanTxProcessing = 'MIXED') and CanHardwareObjectUsesPolling = 'false') or node:ref(CanControllerRef)/CanTxProcessing = 'INTERRUPT')"!]
                        [!VAR "MAX_IF_ACK_COUNT"="num:i($MAX_IF_ACK_COUNT) +  num:i(CanHwObjectCount)"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
                [!VAR "GLOBAL_IF_ACK_COUNT_LIST" = "concat($GLOBAL_IF_ACK_COUNT_LIST,   ' ', num:i($MAX_IF_ACK_COUNT))"!]
                [!VAR "MAX_IF_ACK_COUNT" = "num:i(0)"!]
            [!ENDFOR!]
            [!WS "0"!]
        [!FOR "i" = "0" TO "15"!] 
            [!CODE!](uint16)[!"text:split($GLOBAL_IF_ACK_COUNT_LIST)[num:i($i+1)]"!]U[!//
            [!IF "$i < 15"!], [!ENDIF!][!ENDCODE!]
        [!ENDFOR!][!//
        [!ENDNOCODE!][!//
        [!WS "0"!] },

        /* Array containing maximum number of TX confirmation buffers per POLLING class. There are 6 of them available */
        {   [!FOR "i" = "$FIRST_POLLING_CLASS" TO "$LAST_POLLING_CLASS"!][!//
            [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!][!//
                [!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true' and CanObjectType = 'TRANSMIT'"!][!//
                    [!IF "$CanEcuCPartitionPath = 'none' or [!//
                        (node:exists(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) and (node:value(node:ref(CanControllerRef)/CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
                        [!IF "(((node:ref(CanControllerRef)/CanTxProcessing = 'MIXED') and (CanHardwareObjectUsesPolling = 'true')) or (node:ref(CanControllerRef)/CanTxProcessing = 'POLLING'))"!][!//
                            [!IF "node:ref(CanMainFunctionRWPeriodRef)/AckInterface = $i"!][!//
                                [!VAR "MAX_POOL_ACK_COUNT"="num:i($MAX_POOL_ACK_COUNT) + num:i(CanHwObjectCount)"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!WS "0"!](uint16)[!"num:i($MAX_POOL_ACK_COUNT)"!]U[!//
            [!VAR "MAX_POOL_ACK_COUNT" = "num:i(0)"!][!//
            [!IF "$i < $LAST_POLLING_CLASS"!][!//
            [!WS "0"!], [!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!WS "0"!] },

        /* Structure describing the way of processing each errors category. This can be: INTERRUPT, POLLING or IGNORE. */
    [!SELECT "CanErrorReporting"!][!//
        {
            [!IF "CAN_PROTOCOL_ERR = 'INTERRUPT'"!][!//
                    [!WS "4"!]NOTIF_FIFO0, /*CAN_PROTOCOL_ERR*/
            [!ELSE!][!//
                [!IF "CAN_PROTOCOL_ERR = 'POLLING'"!][!//
                    [!WS "4"!]NOTIF_FIFO1, /*CAN_PROTOCOL_ERR*/
                [!ELSE!][!//
                    [!WS "4"!]IGNORE, /*CAN_PROTOCOL_ERR*/
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "DATALOST_ERR = 'INTERRUPT'"!][!//
                [!WS "4"!]NOTIF_FIFO0, /*DATALOST_ERR*/
            [!ELSE!][!//
                [!IF "DATALOST_ERR = 'POLLING'"!][!//
                    [!WS "4"!]NOTIF_FIFO1, /*DATALOST_ERR*/
                [!ELSE!][!//
                    [!WS "4"!]IGNORE, /*DATALOST_ERR*/
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "CONFIGURATION_ERR = 'INTERRUPT'"!][!//
                [!WS "4"!]NOTIF_FIFO0, /*CONFIGURATION_ERR*/
            [!ELSE!][!//
                [!IF "CONFIGURATION_ERR = 'POLLING'"!][!//
                    [!WS "4"!]NOTIF_FIFO1, /*CONFIGURATION_ERR*/
                [!ELSE!][!//
                    [!WS "4"!]IGNORE, /*CONFIGURATION_ERR*/
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "INTERNAL_ERR = 'INTERRUPT'"!][!//
                [!WS "4"!]NOTIF_FIFO0, /*INTERNAL_ERR*/
            [!ELSE!][!//
                [!IF "INTERNAL_ERR = 'POLLING'"!][!//
                    [!WS "4"!]NOTIF_FIFO1, /*INTERNAL_ERR*/
                [!ELSE!][!//
                    [!WS "4"!]IGNORE, /*INTERNAL_ERR*/
                [!ENDIF!][!//
            [!ENDIF!][!//
    [!ENDSELECT!][!//
            [!WS "4"!]{
            [!FOR "i" = "0" TO "15"!][!//
                [!VAR "CTRL_ENABLED"="num:i(0)"!][!//
                [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!][!//
                    [!IF "substring-after(./CanHwChannel,'BCAN_') = $i"!][!//
                        [!IF "(CanControllerActivation = 'true') "!][!//
                            [!IF "$CanEcuCPartitionPath = 'none' or (node:exists(CanControllerEcucPartitionRef) and (node:value(CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
                                [!IF "CanBusoffProcessing = 'INTERRUPT'"!][!//
                                    [!WS "4"!]NOTIF_FIFO0[!//
                                [!ELSE!][!//
                                    [!WS "4"!]NOTIF_FIFO1[!//
                                [!ENDIF!][!//
                                [!VAR "CTRL_ENABLED"="num:i(1)"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
                [!IF "$CTRL_ENABLED = 0"!][!//
                    [!WS "4"!] IGNORE[!//
                [!ENDIF!][!//
                [!IF "$i < 15"!][!//
                    [!WS "0"!],
                [!ENDIF!][!//
            [!ENDFOR!]
            [!WS "4"!]}, /* BusOff processing type for each channel */
    [!SELECT "CanErrorReporting"!][!//
            [!IF "CAN_PROTOCOL_WRN = 'INTERRUPT'"!][!//
                [!WS "4"!]NOTIF_FIFO0, /*CAN_PROTOCOL_WRN*/
            [!ELSE!][!//
                [!IF "CAN_PROTOCOL_WRN = 'POLLING'"!][!//
                    [!WS "4"!]NOTIF_FIFO1, /*CAN_PROTOCOL_WRN*/
                [!ELSE!][!//
                    [!WS "4"!]IGNORE, /*CAN_PROTOCOL_WRN*/
                [!ENDIF!][!//
            [!ENDIF!][!//
    [!ENDSELECT!][!//
        }
[!ENDINDENT!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!// GeneratePlatformInit

[!MACRO "GenerateChannelInit", "SkipGenerateEmpty" = "0", "CanEcuCPartitionPath" = " 'none' "!][!//
[!INDENT "4"!][!//
[!SELECT "CanConfigSet"!][!//
[!FOR "crtCtrl" = "0" TO "15"!][!//
    [!VAR "ctrlFound" = "0"!][!//
    [!VAR "MAX_TXMB" = "num:i(0)"!][!//
    [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!][!//
        [!IF "(CanControllerActivation = 'true') and (substring-after(CanHwChannel,'BCAN_') = num:i($crtCtrl))"!][!//
            [!IF "$CanEcuCPartitionPath = 'none' or (node:exists(./CanControllerEcucPartitionRef) and (node:value(./CanControllerEcucPartitionRef) = $CanEcuCPartitionPath))"!][!//
        { /* Options for BCAN_[!"$crtCtrl"!] */
            [!INDENT "8"!][!//
            /* ===== Controller Options for firmware ===== */
            (uint32)(
            [!IF "CanTimeStampEnable = 'END_OF_FRAME'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_TST_END_U32 |/* Timestamp capture point END */
            [!ELSEIF "CanTimeStampEnable = 'START_OF_FRAME'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_TST_START_U32 |/* Timestamp capture point START */
            [!ELSEIF "CanTimeStampEnable = 'CAN_START_OF_FRAME_CANFD_RES'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_TST_FD_U32 |/* Timestamp capture point START or RES bit */
            [!ELSE!][!//
                /* TimeStamp disabled */ 
            [!ENDIF!][!//
            [!IF "CanListenOnlyMode = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_LOM_EN_U32 | /* Listen-only mode enabled */
            [!ELSE!][!//
                /* Listen-only mode disabled */                
            [!ENDIF!][!//
            [!IF "CanLoopBackMode = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_LPB_EN_U32 | /* LoopBack mode enabled */
            [!ELSE!][!//
                /* LoopBack mode disabled */                
            [!ENDIF!][!//
            [!IF "SelfReceptionEnable = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_SRX_EN_U32 | /* Self reception mode enabled */
            [!ELSE!][!//
                /* Self reception mode disabled */                
            [!ENDIF!][!//
            [!IF "CanProtocolException = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_PE_EN_U32 | /* Protocol exception feature enabled */
            [!ELSE!][!//
                /* Protocol Exception feature disabled */                
            [!ENDIF!][!//
            [!IF "CanTxFifoMode = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_TXFIFO_EN_U32 | /* Can TX FIFO Mode enabled */
            [!ELSE!][!//
                /* Can TX FIFO Mode disabled */                
            [!ENDIF!][!//
            [!IF "AutomaticBusOffRecovery = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_ABR_EN_U32 | /* Automatic Bus Off Recovery enabled */
            [!ELSE!][!//
                /* Automatic Bus Off Recovery disabled */                
            [!ENDIF!][!//
            [!IF "ManualBusOffRecovery = 'true'"!][!//
                LLCE_CAN_CONTROLLERCONFIG_MBR_EN_U32 | /* Manual Bus Off Recovery enabled */
            [!ELSE!][!//
                /* Manual Bus Off Recovery disabled */                
            [!ENDIF!][!//
            
            LLCE_CAN_CONTROLLERCONFIG_CTRL_EN_U32
            ),
            [!LOOP "node:order(../../CanHardwareObject/*,'node:value(CanObjectId)')"!][!//
                [!IF "(substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = num:i($crtCtrl)) and (CanObjectType = 'TRANSMIT')"!][!//
                    [!VAR "MAX_TXMB"="num:i($MAX_TXMB) + num:i(CanHwObjectCount)"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "$MAX_TXMB > 16"!][!//
                [!ERROR!]The hardware platform does not include enough message buffers in order to service all configured HTHs for BCAN_[!"$crtCtrl"!] [!ENDERROR!][!//
            [!ENDIF!][!//
            /* Number of configured HTHs for this controller */
            (uint8)[!"num:i($MAX_TXMB)"!]U
            [!VAR "ctrlFound" = "1"!][!//
            [!ENDINDENT!][!//
            },
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!//
    [!IF "($ctrlFound = 0) and ($SkipGenerateEmpty = 0)"!][!//
        { /* Options for BCAN_[!"$crtCtrl"!] */
            [!INDENT "8"!][!//
            /* BCAN_[!"$crtCtrl"!] not enabled */
            (uint32)(0U),
            /* Number of configured HTHs for this controller */
            (uint8)0U
            [!ENDINDENT!][!//
        },
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDINDENT!][!//
[!ENDMACRO!][!// GenerateChannelInit

[!MACRO "GenerateAdvancedFilterConfig"!][!//
[!INDENT "4"!][!//
  { /* Advanced filter [!"num:i($crtFilter)"!] for BCAN_[!"num:i($crtCtrl)"!] */
    [!INDENT "6"!][!//
    { /* RxFilter */
      [!CALL "GenerateFilterConfig"!][!//
    },
    { /* AdvancedFeature */
        [!SELECT "node:ref(CanAdvancedFeature/CanAdvancedFeatureRef)"!][!//
        [!IF "node:value(AuthenticationFrameEnable) = 'true'"!][!//
            LLCE_AF_AUTHENTICATION_ENABLED,  /* Option for frame authentication feature */
        [!ELSE!][!//
            LLCE_AF_AUTHENTICATION_DISABLED, /* Option for frame authentication feature */
        [!ENDIF!][!//
        [!IF "node:value(HostReceiveEnable) = 'true'"!][!//
            LLCE_AF_HOSTRECEIVE_ENABLED,  /* Option for host receive feature */
        [!ELSE!][!//
            LLCE_AF_HOSTRECEIVE_DISABLED, /* Option for host receive feature */
        [!ENDIF!][!//
        [!IF "node:value(LoggingFeatureEnable) = 'true'"!][!//
            LLCE_AF_LOGGING_ENABLED,  /* Option for logging feature */
        [!ELSE!][!//
            LLCE_AF_LOGGING_DISABLED, /* Option for logging feature */
        [!ENDIF!][!//
        [!IF "node:value(CustomProcessingEnable) = 'true'"!][!//
            LLCE_AF_CUSTOMPROCESSING_ENABLED,  /* Option for custom processing in FDK */
        [!ELSE!][!//
            LLCE_AF_CUSTOMPROCESSING_DISABLED, /* Option for custom processing in FDK */
        [!ENDIF!][!//
        [!IF "node:exists(Can2CanRoutingEnable)"!][!//
            (uint8)[!"node:ref(Can2CanRoutingEnable/Can2CanRoutingTableRef)/@index"!]U, /* Reference to Can2Can routing entry */
        [!ELSE!][!//
            (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED, /* Can2Can not used */
        [!ENDIF!][!//
        [!IF "node:exists(Can2EthRoutingEnable)"!][!//
            (uint8)[!"node:ref(Can2EthRoutingEnable/Can2EthRoutingTableRef)/@index"!]U + LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT, /* Reference to Can2Eth routing entry */
        [!ELSE!][!//
            (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED,  /* Can2Eth not used */
        [!ENDIF!][!//
        [!IF "node:exists(Can2OtherRoutingEnable)"!][!//
            (uint8)[!"node:ref(Can2OtherRoutingEnable/Can2OtherRoutingTableRef)/@index"!]U + LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT /* Reference to Can2Other routing entry */
        [!ELSE!][!//
            (uint8)LLCE_CAN_ADVANCED_FILTER_NOT_USED  /* Can2Other not used */
        [!ENDIF!][!//
        [!ENDSELECT!][!//
    }
    [!ENDINDENT!][!//
  } /* End advanced filter [!"num:i($crtFilter)"!] for BCAN_[!"num:i($crtCtrl)"!] */[!//
[!ENDINDENT!][!//
[!ENDMACRO!][!// GenerateAdvancedFilterConfig

[!MACRO "GenerateAdvancedDestinations"!][!//
    [!LOOP "Can2CanRoutingTable/*"!][!//
        [!VAR "DESTCH_CNT" = "num:i(count(CanDestinationList/*))"!][!//
        [!INDENT "4"!][!//
            {
            [!INDENT "8"!][!//
                {.Can2Can = {
                    [!INDENT "12"!][!//
                        /* ======= Routing Rule ======= */
                        (uint32)(
                        [!IF "(CanFd2Can = 'false') and (Can2CanFd = 'false')"!][!//
                            [!WS "10"!]LLCE_CAN_ROUTING_NOCHANGE |
                        [!ELSE!][!//
                            [!IF "(CanFd2Can = 'false') and (Can2CanFd = 'true')"!][!//
                                [!WS "10"!]LLCE_CAN_ROUTING_CANFD |
                            [!ELSE!][!//
                                [!IF "(CanFd2Can = 'true') and (Can2CanFd = 'false')"!][!//
                                    [!WS "10"!]LLCE_CAN_ROUTING_CAN |
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                        [!IF "node:exists(CanIdRemapping)"!][!//
                            [!WS "10"!]LLCE_CAN_ROUTING_ID_REMAPPING_EN |
                        [!ENDIF!][!//
                        [!WS "10"!]LLCE_CAN_ROUTING_OPTION_DEFAULT_CONFIG
                        [!WS "8"!]),
                        [!IF "node:exists(CanIdRemapping)"!][!//
                            (uint32)[!"num:i(CanIdRemapping)"!]U [!//
                            [!IF "num:i(CanIdRemapping) > 2047"!][!//
                                | LLCE_CAN_MB_IDE_U32,[!// Add IDE bit
                            [!ELSE!][!//
                                [!IF "ForceExtendedID = 'true'"!][!//
                                    | LLCE_CAN_MB_IDE_U32,[!// Add IDE bit
                                [!ELSE!][!//
                                    << LLCE_CAN_MB_IDSTD_SHIFT_U32,[!// Shift for standard ID
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ELSE!][!//
                            (uint32)0U,
                        [!ENDIF!][!//
                        {
                            [!VAR "END_COMMA2"="0"!][!//
                            [!LOOP "CanDestinationList/*"!][!//
                                [!VAR "END_COMMA2"="$END_COMMA2 + 1"!][!//
                                [!INDENT "16"!][!//
                                    [!SELECT "node:ref(Can2CanControllerRef)"!][!//
                                        (uint8)[!"substring-after(CanHwChannel,'BCAN_')"!][!//
                                        [!IF "$END_COMMA2 < $DESTCH_CNT"!][!//
                                            ,
                                        [!ELSE!][!//
                                            [!FOR "i" = "$DESTCH_CNT" TO "15"!][!/* Initialize remaining elements in array in order to comply with misra rule 9.3 */!][!//
                                            ,
                                                    (uint8)0[!//
                                            [!ENDFOR!][!//
                                        [!ENDIF!][!//
                                        [!VAR "CanFdEnabled" = "'true'"!][!//
                                        [!LOOP "CanControllerBaudrateConfig/*"!][!//
                                            [!VAR "CanFdEnabled"="$CanFdEnabled and (node:exists(CanControllerFdBaudrateConfig))"!][!//
                                        [!ENDLOOP!][!//
                                    [!ENDSELECT!][!//
                                    [!IF "(node:value(../../Can2CanFd) = 'true') and $CanFdEnabled = 'false'"!][!//
                                        [!WARNING!]Controllers from destination list has non CAN-FD baudrates configurations, even if converting option is to CAN-FD. The received frames will be dropped.[!ENDWARNING!][!//
                                    [!ENDIF!][!//
                                [!ENDINDENT!][!//
                            [!ENDLOOP!][!//
                            [!CR!][!//
                        },
                        (uint8)[!"$DESTCH_CNT"!]U
                    [!ENDINDENT!][!//
                }},
                /* ======= Destination rule type ======= */
                CAN_AF_CAN2CAN
            [!ENDINDENT!][!//
            },
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
    [!VAR "crtIdx" = "0"!][!//
    [!LOOP "Can2EthRoutingTable/*"!][!//
        [!VAR "DestMacArray" = "text:replaceAll(EthDestAddress, ':', ', (uint8)0x')"!][!//
        [!VAR "DestMacArray" = "text:concat('(uint8)0x', $DestMacArray)"!][!//
        [!VAR "DestMacArray" = "text:replace($DestMacArray, '\[', '\{ ')"!][!//
        [!VAR "DestMacArray" = "text:replace($DestMacArray, '\]', ' \}')"!][!//
        [!VAR "SrcMacArray" = "text:replaceAll(EthSrcAddress, ':', ', (uint8)0x')"!][!//
        [!VAR "SrcMacArray" = "text:concat('(uint8)0x', $SrcMacArray)"!][!//
        [!VAR "SrcMacArray" = "text:replace($SrcMacArray, '\[', '\{ ')"!][!//
        [!VAR "SrcMacArray" = "text:replace($SrcMacArray, '\]', ' \}')"!][!//
        [!INDENT "4"!][!//
            {
            [!INDENT "8"!][!//
                {.Can2Eth = {
                    /* ======= Routing Rule ======= */
                    [!INDENT "12"!][!//
                        (uint32)0U,
                        (uint16)sizeof(Llce_Can2Eth_Buffer[!"num:i($crtIdx)"!][0]),
                        [!"Can2EthBufferCount"!],
                        LLCE_AF_CAN2[!"EncapsulationType"!],
                        [!"$DestMacArray"!],
                        [!"$SrcMacArray"!],
                        [!IF "(EncapsulationType = 'UDP') or (EncapsulationType = 'UDP_B')"!][!//
                            {[!LOOP "text:split(IpDestAddress,'.')"!][!//
                              [!IF "num:i(.) > 255"!][!//
                                    [!ERROR!]Invalid IP address[!ENDERROR!][!//
                              [!ELSE!][!//
                                    [!"num:i(.)"!],[!//
                              [!ENDIF!][!//
                            [!ENDLOOP!]},
                            {[!LOOP "text:split(IpSrcAddress,'.')"!][!//
                              [!IF "num:i(.) > 255"!][!//
                                    [!ERROR!]Invalid IP address[!ENDERROR!][!//
                              [!ELSE!][!//
                                    [!"num:i(.)"!],[!//
                              [!ENDIF!][!//
                            [!ENDLOOP!]},
                            [!"UdpDestPort"!],
                            [!"UdpSrcPort"!],
                        [!ELSE!][!//
                        {0U, 0U, 0U, 0U},
                        {0U, 0U, 0U, 0U},
                        0U,
                        0U,
                        [!ENDIF!][!//
                        [!LOOP "EthPhyIf/*"!][!//
                            LLCE_CAN2ETH_[!"."!][!IF "not(node:islast(.))"!] | [!ENDIF!][!//
                        [!ENDLOOP!]
                    }
                    [!ENDINDENT!][!//
                },
                /* ======= Destination rule type ======= */
                CAN_AF_CAN2ETH
            [!ENDINDENT!][!//
            },
        [!VAR "crtIdx" = "$crtIdx+1"!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
    [!VAR "pcieIdx" = "0"!][!//
    [!LOOP "Can2OtherRoutingTable/*"!][!//
      [!IF "RoutingType = 'PCIe'"!]
          [!INDENT "4"!][!//
          {
          [!INDENT "8"!][!//
            {.Can2Pcie = {
            /* ======= Routing Rule ======= */
            [!INDENT "12"!][!//
                (uint64)[!"num:inttohex(PcieRcBuffAddr)"!],
                (uint32)0U,
                (uint16)sizeof(Llce_Can2Pcie_Buffer[!"num:i($pcieIdx)"!][0]),
                [!"BufferCount"!],
                [!"num:i(PcieController)"!],
                [!"num:i(DmaChannel)"!],
              [!IF "node:exists(MsiId)"!][!//
                [!"num:i(MsiId)"!]
              [!ELSE!][!//
                0xFF
              [!ENDIF!][!//
            }
            [!ENDINDENT!][!//
            },
            /* ======= Destination rule type ======= */
            CAN_AF_CAN2PCIE
          [!ENDINDENT!][!//
          },
          [!VAR "pcieIdx" = "$pcieIdx+1"!][!//
          [!ENDINDENT!][!//
      [!ENDIF!]
      [!IF "RoutingType = 'HSE'"!]
          [!INDENT "4"!][!//
          {
          [!INDENT "8"!][!//
            {.Can2Hse = {
            /* ======= Routing Rule ======= */
            [!INDENT "12"!][!//
                (uint32)[!"CanKeyHandle"!]
            }
            [!ENDINDENT!][!//
            },
            /* ======= Destination rule type ======= */
            CAN_AF_CAN2HSE
          [!ENDINDENT!][!//
          },
          [!ENDINDENT!][!//
      [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDMACRO!][!// GenerateAdvancedDestinations

[!MACRO "GenerateBaudrate"!][!//
[!INDENT "0"!][!//
    [!NOCODE!][!//
    [!/*
    Sync-seg = is the segment that is used to synchronise the nodes on the bus. A bit edge (if there is a data change) is expected during this segment.
    Prop-Seg = is a period of time that is used to compensate for physical delay times within the network.
    Phase-seg1 = is a buffer segment that may be lengthened during resynchronisation to compensate for oscillator drift and positive phase differences between the oscillators of the transmitting and receiving node(s).
    Phase-seg2 = is a buffer segment that may be shortened during resynchronisation (described below) to compensate for negative phase errors and oscillator drift.

    The Sample point is always at the end of Phase-seg1 and is the time at which the bus level is read and interpreted as the value of the current bit.
    Whether transmitting or receiving, all nodes on a single CAN bus must have the same nominal bit time. Bit time is programmable at each node on a CAN Bus and is a function
        of the period of the oscillator local to each node, the value that is user-programmed into a Baud Rate Prescaler (BRP) register in the controller at each node, and the programmed number of time quanta per bit.

    When any node receives a data frame or a remote frame, it is necessary for the receiver to synchronise with the transmitter.
        1. The first is hard synchronisation and occurs at Start-of-Frame (SOF).
        2. For subsequent bits in any received frame, if a bit edge does not occur in the Sync-seg segment of bit time, resynchronisation is automatically invoked and will shorten or lengthen the current bit time depending
            on where the edge occurs. The maximum amount by which the bit time is lengthened or shortened is determined by a user-programmable number of time quanta known as the Synchronisation Jump Width (SJW).
    */!][!//
    [!ENDNOCODE!][!//
    [!IF "../../CanControllerActivation = 'true'"!][!//
        [!WS "8"!]/* Configuration [!"@index"!] for CanController ID[!"../../CanControllerId"!] == [!"../../CanHwChannel"!] */
        [!WS "8"!]{
        [!WS "12"!]/* ===== Nominal Bit Timing Register - NCBT ===== */
        [!VAR "TimeQuantum" = "num:i(./CanControllerPrescaller) div $CanClockSrc"!][!//
        [!VAR "NumOfTQN" = "num:i(round(1 div (./CanControllerBaudRate * 1000 * $TimeQuantum)))"!][!/* Number of Tq in nominal bit time = (1 div ((desired_baudrate(kbps) * 1000) * TQ )) */!][!//
        [!VAR "Tsyncsegment" = "1"!][!/* Sync_seg has 1 Tq length */!][!//
        [!IF "node:exists(CanAdvancedSetting) and (CanAdvancedSetting  = 'true')"!][!//
            [!/* Initiates the derivation of the CAN bit timing values from the CanControllerBaudRate parameter. */!][!//
            [!VAR "PropSeg" = "num:i(1)"!][!//
            [!VAR "PhaseSegment1" = "num:i(2)"!][!//
            [!VAR "PhaseSegment2" = "num:i(2)"!][!//
            [!VAR "RJW" = "num:i(1)"!][!//
            [!CALL "Can_BaudRate_Inference",
                    "CanPhysBusLength" = "num:i(./CanBusLength)",
                    "PropDelayTransceiver" = "num:i(./CanPropDelayTranceiver)",
                    "PhaseSegment1_Max" = "256",
                    "PhaseSegment2_Max" = "128",
                    "NumOfTQ" = "$NumOfTQN"!][!//
        [!ELSE!][!//
            [!IF "CanControllerCheckCanStandard"!][!/* Nominal Baudrate checking */!][!//
                [!VAR "TqNSeg1" = "num:i(./CanControllerPropSeg + ./CanControllerSeg1 + ./CanControllerSyncSeg)"!][!//
                [!VAR "TqNSeg2" = "num:i(./CanControllerSeg2)"!][!//
                [!VAR "UserNoTimeQuantas" = "num:i($TqNSeg1 + $TqNSeg2)"!][!/* Number of given Tq  */!][!//
                [!IF "$NumOfTQN != $UserNoTimeQuantas"!][!//
                    [!VAR "CorrespondingBaudrate" = "num:i(round(1 div ($UserNoTimeQuantas * $TimeQuantum * 1000)))"!][!/* Baudrate(kbps) corresponding to given Tq */!][!//
                    [!VAR "CorrespondingSamplePoint" = "num:f($TqNSeg1 div $UserNoTimeQuantas) * 100"!][!/* Sample point corresponding to given Tq */!][!//
                    [!WARNING!][!//
                        The total time quanta configured ([!"$UserNoTimeQuantas"!]) corresponds to a baudrate of [!"$CorrespondingBaudrate"!] kbps for nominal phase which
                        is different from the one given [!"./CanControllerBaudRate"!] kbps and computed from [!"$NumOfTQN"!] time quantas using the Can Clock 
                        (default is considered 40Mhz if no MCU clock source provided) and Prescaler. The corresponding sample point is [!"$CorrespondingSamplePoint"!]%.
                    [!ENDWARNING!][!//
                [!ENDIF!][!//
            [!ENDIF!] [!/* End of nominal baudrate checking  */!][!//
        [!ENDIF!][!//
        [!WS "12"!](uint32)( ((uint32)[!"num:i(num:i(CanControllerPrescaller) - 1)"!] << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
        [!IF "node:exists(CanAdvancedSetting) and (CanAdvancedSetting  = 'true')"!][!//
                 [!WS "22"!]((uint32)[!"num:i(num:i($RJW) - 1)"!]U << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                 [!WS "22"!]((uint32)[!"num:i(num:i($PhaseSegment1) + num:i($PropSeg) - 1)"!]U) |      /*Segment 1 */
                 [!WS "22"!]((uint32)[!"num:i(num:i($PhaseSegment2) - 1)"!]U << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
        [!ELSE!][!//
                 [!WS "22"!]((uint32)[!"num:i(num:i(CanControllerSyncJumpWidth) - 1)"!] << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
                 [!WS "22"!]((uint32)[!"num:i(num:i(CanControllerSeg1) + num:i(CanControllerPropSeg) - 1)"!]) |      /*Segment 1 */
                 [!WS "22"!]((uint32)[!"num:i(num:i(CanControllerSeg2) - 1)"!] << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
        [!ENDIF!][!//
            [!WS "20"!]),
        [!/* For further adding of CanControllerBaudRate number in configuration structure*/!][!//
        [!WS "12"!]{ /* Llce_Can_ControllerFdConfig */
        [!IF "node:exists(CanControllerFdBaudrateConfig/CanAdvancedSettingFd) and (CanControllerFdBaudrateConfig/CanAdvancedSettingFd = 'true')"!][!//
            [!VAR "TimeQuantumFD" = "num:i(CanControllerFdBaudrateConfig/CanControllerFDPrescaller) div $CanClockSrc"!][!//
            [!VAR "NumOfTQD" = "num:i(round(1 div (CanControllerFdBaudrateConfig/CanControllerFdBaudRate * 1000 * $TimeQuantumFD))"!][!/* Number of Tq in Data bit time = (1 div ((desired_baudrate(kbps) * 1000) * TQ )) */!][!//
            [!VAR "PhaseSegment1Fd" = "num:i(2)"!][!//
            [!VAR "PhaseSegment2Fd" = "num:i(2)"!][!//
            [!VAR "PropSegFd" = "num:i(1)"!][!//
            [!VAR "RJW_Fd" = "num:i(1)"!][!//
            [!CALL "Can_BaudRate_Inference",
                    "CanPhysBusLength" = "num:i(./CanControllerFdBaudrateConfig/CanBusLengthFd)",
                    "PropDelayTranceiver" = "num:i(0)",[!//CAN Fd provides an optional tranceiver delay mechanism
                    "PhaseSegment1_Max" = "32",
                    "PhaseSegment2_Max" = "16",
                    "NumOfTQ" = "$NumOfTQD"!][!//
        [!ELSE!][!//
            [!IF "CanControllerCheckCanStandard"!][!/* Data Baudrate checking  */!][!//
                [!IF "(node:exists(CanControllerFdBaudrateConfig) = 'true') and ((node:value(CanControllerFdBaudrateConfig/CanControllerTxBitRateSwitch)) = 'true')"!][!//
                 [!IF "node:value(CanControllerFdBaudrateConfig/CanControllerFdBaudRate) > num:i(text:split('8000 8000 8000 8000 8000 8000 7400 7400 6600 6600 5700 5700 5700 5700 5000 5000')[num:i($CONFIGURED_CONTROLLERS_COUNT)])"!][!//
                    [!WARNING!][!//
                        Maximum baudrate for a number of [!"num:i($CONFIGURED_CONTROLLERS_COUNT)"!] started controllers is [!//
                            [!"num:i(text:split('8000 8000 8000 8000 8000 8000 7400 7400 6600 6600 5700 5700 5700 5700 5000 5000')[num:i($CONFIGURED_CONTROLLERS_COUNT)])"!] kbps.
                    [!ENDWARNING!][!//
                    [!/* For further adding of CanControllerFdBaudRate number in configuration structure*/!][!//
                    [!ENDIF!][!//
                    [!VAR "TimeQuantumFD" = "num:i(CanControllerFdBaudrateConfig/CanControllerFDPrescaller) div $CanClockSrc"!][!//
                    [!VAR "NumOfTQD" = "num:i(round(1 div (CanControllerFdBaudrateConfig/CanControllerFdBaudRate * 1000 * $TimeQuantumFD)))"!][!/* Number of Tq in Data bit time = (1 div ((desired_baudrate(kbps) * 1000) * TQ )) */!][!//
                    [!VAR "TqDSeg1" = "num:i(CanControllerFdBaudrateConfig/CanControllerFdSyncSeg + CanControllerFdBaudrateConfig/CanControllerPropSeg + CanControllerFdBaudrateConfig/CanControllerSeg1)"!][!//
                    [!VAR "TqDSeg2" = "num:i(CanControllerFdBaudrateConfig/CanControllerSeg2)"!][!//
                    [!VAR "UserNoTimeQuantasFd" = "num:i($TqDSeg1 + $TqDSeg2)"!][!//
                    [!IF "$NumOfTQD != $UserNoTimeQuantasFd"!][!//
                        [!VAR "CorrespondingBaudrate" = "num:i(round(1 div ($UserNoTimeQuantasFd * $TimeQuantumFD * 1000)))"!][!/* Baudrate(kbps) corresponding to given Tq */!][!//
                        [!VAR "CorrespondingSamplePoint" = "num:f($TqDSeg1 div $UserNoTimeQuantasFd) * 100"!][!/* Sample point corresponding to given Tq */!][!//
                    [!WARNING!][!//
                        Maximum baudrate for a number of [!"num:i($CONFIGURED_CONTROLLERS_COUNT)"!] started controllers is [!//
                            [!"num:i(text:split('8000 8000 8000 8000 8000 8000 7400 7400 6600 6600 5700 5700 5700 5700 5000 5000')[num:i($CONFIGURED_CONTROLLERS_COUNT)])"!] kbps.
                    [!ENDWARNING!][!//
                    [!/* For further adding of CanControllerFdBaudRate number in configuration structure*/!][!//
                    [!ENDIF!][!//
                    [!VAR "TqDSeg1" = "num:i(CanControllerFdBaudrateConfig/CanControllerFdSyncSeg + CanControllerFdBaudrateConfig/CanControllerPropSeg + CanControllerFdBaudrateConfig/CanControllerSeg1)"!][!//
                    [!VAR "TqDSeg2" = "num:i(CanControllerFdBaudrateConfig/CanControllerSeg2)"!][!//
                    [!VAR "UserNoTimeQuantasFd" = "num:i($TqDSeg1 + $TqDSeg2)"!][!//
                    [!IF "$NumOfTQD != $UserNoTimeQuantasFd"!][!//
                        [!VAR "CorrespondingBaudrate" = "num:i(round(1 div ($UserNoTimeQuantasFd * $TimeQuantumFD * 1000)))"!][!/* Baudrate(kbps) corresponding to given Tq */!][!//
                        [!VAR "CorrespondingSamplePoint" = "num:f($TqDSeg1 div $UserNoTimeQuantasFd) * 100"!][!/* Sample point corresponding to given Tq */!][!//
                        [!WARNING!][!//
                            The total time quanta configured ([!"$UserNoTimeQuantasFd"!]) corresponds to a baudrate of [!"$CorrespondingBaudrate"!] kbps for data phase which 
                            is different from the one given [!"./CanControllerFdBaudrateConfig/CanControllerFdBaudRate"!] kbps and computed from [!"$NumOfTQD"!] time quantas using the Can Clock 
                            (default is considered 40Mhz if no MCU clock source provided) and Prescaler. The corresponding sample point is [!"$CorrespondingSamplePoint"!]%.
                        [!ENDWARNING!][!//
                    [!ENDIF!][!//
                    [!IF "(node:exists(CanControllerFdBaudrateConfig/CanControllerSspOffset)) = 'true'"!][!//
                        [!IF "CanControllerFdBaudrateConfig/CanControllerSspOffset > ((3 * num:i($NumOfTQD)) - 2)"!][!//
                            [!WARNING!][!//
                                The maximum delay which can be compensated by the BCAN transceiver delay compensation during the data phase is 3 CAN bit times – 2 TQ, [!"(3 * num:i($NumOfTQD)) - 2"!].
                                Current CanControllerSspOffset value is [!"CanControllerFdBaudrateConfig/CanControllerSspOffset"!] .
                            [!ENDWARNING!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!/* End of data baudrate checking  */!][!//
        [!ENDIF!][!//
        [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!][!//
            [!WS "12"!](uint32)(((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerFDPrescaller) - 1)"!]U << LLCE_DCBT_DPRESDIV_SHIFT_U8) |   /* CAN FD prescaler */
            [!IF "node:exists(CanControllerFdBaudrateConfig/CanAdvancedSettingFd) and (CanControllerFdBaudrateConfig/CanAdvancedSettingFd = 'true')"!][!//
                    [!WS "21"!]((uint32)[!"num:i(num:i($RJW_Fd) - 1)"!]U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                    [!WS "21"!]((uint32)[!"num:i(num:i($PhaseSegment1Fd) + num:i($PropSegFd) - 1)"!]U) |   /* Time segment 1 */
                    [!WS "21"!]((uint32)[!"num:i(num:i($PhaseSegment2Fd) - 1)"!]U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            [!ELSE!][!//
                    [!WS "21"!]((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerSyncJumpWidth - 1))"!]U << LLCE_DCBT_DRJW_SHIFT_U8) | /*Sync jump width*/
                    [!WS "21"!]((uint32)[!"num:i(num:i(CanControllerFdBaudrateConfig/CanControllerSeg1) + num:i(CanControllerFdBaudrateConfig/CanControllerPropSeg) - 1)"!]U) |   /* Time segment 1 */
                    [!WS "21"!]((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerSeg2) - 1)"!]U<<LLCE_DCBT_DTSEG2_SHIFT_U8)),   /*Time segment 2  */
            [!ENDIF!][!//
            [!WS "12"!](uint8)LLCE_TRUE,  /* CAN FD enabled */
            [!IF "((node:value(CanControllerFdBaudrateConfig/CanControllerTxBitRateSwitch)) = 'true')"!][!//
                [!WS "12"!](uint8)LLCE_TRUE,  /* BRS activated*/
            [!ELSE!][!//
                [!WS "12"!](uint8)LLCE_FALSE, /* BRS deactivated*/
            [!ENDIF!][!//
            [!IF "(node:exists(CanControllerFdBaudrateConfig/CanControllerSspOffset)) = 'true'"!][!//
                [!WS "12"!](uint8)LLCE_TRUE, /* CanTrcvDelayCompEnable*/
                [!WS "12"!](uint8)LLCE_TRUE, /* CanTrcvDelayMeasEnable */
                [!WS "12"!](uint8)[!"CanControllerFdBaudrateConfig/CanControllerSspOffset"!]U, /*Trcv Delay*/
            [!ELSE!][!//
                [!WS "12"!](uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
                [!WS "12"!](uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
                [!WS "12"!](uint8)0U, /*Trcv Delay*/
            [!ENDIF!][!//
        [!ELSE!][!//
            [!WS "12"!](uint32)(0U |  /* CAN FD prescaler */
                    [!WS "21"!]0U | /*Sync jump width*/
                    [!WS "21"!]0U | /* Time segment 1 */
                    [!WS "21"!]0U),  /*Time segment 2  */
            [!WS "12"!](uint8)LLCE_FALSE, /*CAN FD Deactivated*/
            [!WS "12"!](uint8)LLCE_FALSE, /* BRS deactivated*/
            [!WS "12"!](uint8)LLCE_TRUE, /* CanTrcvDelayCompEnable*/
            [!WS "12"!](uint8)LLCE_TRUE, /* CanTrcvDelayMeasEnable */
            [!WS "12"!]0U,   /*Trcv Delay*/
        [!ENDIF!][!//
        [!WS "12"!]},
        [!WS "8"!]},
    [!ELSE!][!//
        [!WS "8"!]{
        [!WS "12"!]/* [!"../../CanHwChannel"!] ControlRegister Default Configuration: 125kb/s */
        [!WS "12"!]/* ===== Nominal Bit Timing Register - NCBT ===== */
        [!WS "12"!](uint32)( ((uint32)7 << LLCE_NCBT_NPRESDIV_SHIFT_U8) |    /* Clock Prescaler */
        [!WS "22"!]((uint32)0 << LLCE_NCBT_NRJW_SHIFT_U8) |     /* Resynchronization Jump Width */
        [!WS "22"!]((uint32)21) |      /*Segment 1 */
        [!WS "22"!]((uint32)16 << LLCE_NCBT_NTSEG2_SHIFT_U8)    /* Segment 2 */
        [!WS "20"!]),
        [!WS "12"!]{
        [!WS "7"!](uint32)(0U |
                [!WS "16"!]0U | /*Sync jump width*/
                [!WS "16"!]0U |
                [!WS "16"!]0U),
        [!WS "16"!](uint8)LLCE_FALSE, /*CAN FD Deactivated*/
        [!WS "16"!](uint8)LLCE_FALSE, /*false -> BRS deactivated*/
        [!WS "16"!](uint8)LLCE_FALSE, /* CanTrcvDelayCompEnable*/
        [!WS "16"!](uint8)LLCE_FALSE, /* CanTrcvDelayMeasEnable */
        [!WS "16"!]0U,   /*Trcv Delay*/
        [!WS "12"!]},
        [!WS "8"!]},
    [!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDMACRO!][!// GenerateBaudrate

[!MACRO "CountCan2Other"!][!//

    [!VAR "AF_CNT"  = "num:i(count(CanAdvancedFeature/*))"!][!//
    [!VAR "C2C_CNT" = "num:i(count(Can2CanRoutingTable/*))"!][!//
    [!VAR "C2E_CNT" = "num:i(count(Can2EthRoutingTable/*))"!][!//
    [!LOOP "node:order(Can2OtherRoutingTable/*)"!][!//
        [!IF "RoutingType = 'PCIe'"!][!//
        [!VAR "C2PCIE_CNT"="$C2PCIE_CNT + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "C2O_CNT" = "num:i(count(Can2OtherRoutingTable/*))"!][!//

[!ENDMACRO!][!// CountCan2Other
