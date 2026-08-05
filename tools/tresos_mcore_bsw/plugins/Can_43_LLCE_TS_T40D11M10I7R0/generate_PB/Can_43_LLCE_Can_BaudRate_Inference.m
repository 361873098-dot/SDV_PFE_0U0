[!/**
*   @file    Can_BaudRate_Inference.m
*   @version 1.0.7
*
*   @brief   Compute CAN Baud Rate segments.
*   @details Compute segments starting from desired baud rate and physical setup parameters.
*  
*   Project RTD AUTOSAR 4.4
*   Platform CORTEXM
*   Peripheral LLCE
*   Dependencies 
*  
*   ARVersion 4.4.0
*   ARRevision ASR_REL_4_4_REV_0000
*   ARConfVariant
*   SWVersion 1.0.7
*   BuildVersion S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
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
*/!]

[!/***********************Can Baud Inference Macro ****************************************/!]
[!NOCODE!]
[!MACRO "Can_BaudRate_Inference",
        "CanPhysBusLength" = "40",
        "PropDelayTransceiver" = "150",
        "PhaseSegment1_Max" = "256",
        "PhaseSegment2_Max" = "128", 
        "NumOfTQ" = "1"!]
[!NOCODE!]
    [!/* Initiates the inference of the CAN bit timing values from the CanControllerBaudRate parameter. */!]
    [!VAR "PhaseSegment1_Min" ="num:i(2)"!]
    [!VAR "PhaseSegment2_Min" ="num:i(2)"!]
    [!VAR "BusPropagationDelay" ="5 div 1000000000"!][!/* Hard coded to 5ns/m. */!]
    [!VAR "PhysicalDelayOfBus"="$CanPhysBusLength * $BusPropagationDelay"!]
    [!/* Tprop_seg=TpropAB + TpropBA = 2 * (Tbus + Trx + Ttx). Usually Trx=Ttx. */!]
    [!VAR "TpropagationSegment"="2*($PhysicalDelayOfBus + 2 * $PropDelayTransceiver)"!]
    [!VAR "PropagationSegment"="1+round($TpropagationSegment div $NumOfTQ )"!]
    [!IF "($PropagationSegment >= 0) and ($PropagationSegment <= 256)"!]
        [!VAR "PhaseSegments" = "($NumOfTQ - $PropagationSegment - $Tsyncsegment)"!]
        [!IF "$PhaseSegments >= 2"!]
            [!VAR "Modulo" = "$PhaseSegments mod 2"!]
            [!IF "$Modulo = 0"!]
                [!VAR "PhaseSeg1" = "num:i($PhaseSegments div 2)"!]
                [!VAR "PhaseSeg2" = "num:i($PhaseSeg1)"!]
            [!ELSE!]
                [!VAR "PhaseSeg1" = "num:i(($PhaseSegments - 1) div 2)"!]
                [!VAR "PhaseSeg2" = "num:i($PhaseSeg1 + 1)"!]
            [!ENDIF!]
            [!IF "($PhaseSeg1 < $PhaseSegment1_Min) or ($PhaseSeg1 > $PhaseSegment1_Max)"!]
                [!ERROR!]
                    For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                    PhaseSegment1 is out of range [!"num:i($PhaseSegment1_Min)"!]:[!"num:i($PhaseSegment1_Max)"!]]. Current value is [!"num:i($PhaseSeg1)"!].
                    The bit length has [!"num:i($NumOfTQ)"!] Time Quantas.
                    Propagation Segment based bus length and transceiver delay has [!"num:i($PropagationSegment)"!] Time Quantas.
                    Need to increase PropagationSegment or to decrease the number of Time Quantas per bit.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "($PhaseSeg2 < $PhaseSegment2_Min) or ($PhaseSeg2 > $PhaseSegment2_Max)"!]
                [!ERROR!]
                    For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                    PhaseSegment2 is out of range [!"num:i($PhaseSegment2_Min)"!]:[!"num:i($PhaseSegment2_Max)"!]]. Current value is [!"num:i($PhaseSeg2)"!]
                    The bit length has [!"num:i($NumOfTQ)"!] Time Quantas.
                    Propagation Segment based bus length and transceiver delay has [!"num:i($PropagationSegment)"!] Time Quantas.
                    Need to increase PropagationSegment or to decrease the number of Time Quantas per bit.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "$PhaseSeg1 < 5"!]
                [!VAR "RJWidth" = "num:i($PhaseSeg1)"!]
            [!ELSE!]
                [!VAR "RJWidth" = "4"!]
            [!ENDIF!]
        [!ELSE!]
            [!ERROR!] For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!], (Phase Segment1+Phase Segment2) must be >= 8. Increase no of NumOfTQ ([!"num:i($NumOfTQ)"!]) per bit or decrease PropSegment ([!"num:i($PropagationSegment)"!])(based CanBusLength and CanPropDelayTranceiver).[!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
        [!ERROR!]
        For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
        Delay A_to_B >= node output delay(A) + bus line delay(A+B) + node input delay(B)
        Prop_Seg >= Delay A_to_B + Delay B_to_A
        Prop_Seg >= 2 * [max(node output delay+ bus line delay + node input delay)]

        The formulas used:
        BusPropagationDelay =5 div 1000000000 /* Hard coded to 5ns/m. */
        PhysicalDelayOfBus = CanBusLength * BusPropagationDelay
        TpropagationSegment = 2*(PhysicalDelayOfBus + 2 * CanPropDelayTranceiver)
        PropagationSegment = 1+round(TpropagationSegment div NumOfTQ )
        [!ENDERROR!]
    [!ENDIF!]
    [!VAR "NoTimeQuantas"= "num:i($Tsyncsegment + $PropagationSegment + $PhaseSeg1 + $PhaseSeg2)"!]
    [!IF "CanAdvancedSetting = 'true'"!]
        [!/* Ensure a minimum of 8 time quanta for basic CAN bit time */!]
        [!IF "num:i($NoTimeQuantas) < num:i(8)"!]
            [!ERROR!]
            CAN bit time should be at least 8 time quanta. Please increase PropagationSegment, PhaseSegment1 or PhaseSegment2.
            [!ENDERROR!]
        [!ENDIF!]
        [!VAR "PropSeg" = "num:i($PropagationSegment)"!]
        [!VAR "PhaseSegment1" = "num:i($PhaseSeg1)"!]
        [!VAR "PhaseSegment2" = "num:i($PhaseSeg2)"!]
        [!VAR "RJW" = "num:i($RJWidth)"!]
    [!ENDIF!]
    [!/* Check $PropDelayTransceiver because it has a unique value for CanFd*/!]
    [!IF "node:exists((CanControllerFdBaudrateConfig/CanAdvancedSettingFd)) = 'true' and $PropDelayTransceiver=0"!]
        [!IF "(node:exists(CanControllerFdBaudrateConfig/CanControllerSspOffset)) = 'true'"!]
            [!IF "CanControllerFdBaudrateConfig/CanControllerSspOffset > ((3 * num:i($NumOfTQ)) - 2)"!]
                [!WARNING!]
                    The maximum delay which can be compensated by the BCAN transceiver delay compensation during the data phase is 3 CAN bit times – 2 TQ, [!"(3 * num:i($NumOfTQD)) - 2"!].
                    Current CanControllerSspOffset value is [!"CanControllerFdBaudrateConfig/CanControllerSspOffset"!] .
                [!ENDWARNING!]
            [!ENDIF!]
        [!ENDIF!]
        [!VAR "PropSegFd" = "num:i($PropagationSegment)"!]
        [!VAR "PhaseSegment1Fd" = "num:i($PhaseSeg1)"!]
        [!VAR "PhaseSegment2Fd" = "num:i($PhaseSeg2)"!]
        [!VAR "RJW_Fd" = "num:i($RJWidth)"!]
    [!ENDIF!]   
[!ENDNOCODE!]
[!ENDMACRO!]
[!ENDNOCODE!]
