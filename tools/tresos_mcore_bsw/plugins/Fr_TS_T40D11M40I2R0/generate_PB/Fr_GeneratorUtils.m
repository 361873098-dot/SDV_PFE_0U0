[!NOCODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
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
/**
 *  @file     Fr_GeneratorUtils.m
 *  @version  4.0.2
 *
 *  @brief    AUTOSAR Fr - generator helper functions.
 *  @details  FlexRay Protocol generator helper functions.
 */

    [!/* Multiple inclusion protection */!]
    [!IF "not(var:defined('FR_FRGENERATORUTILS_M'))"!]
        [!VAR "FR_FRGENERATORUTILS_M" = "'true'"!]

        [!/* This macro performs a crc calculation for the header crc */!]
        [!MACRO "CrcCalculation", "Sync" = "0", "Startup" = "0", "FrameId" = "1", "PayloadLengthW" = "8", "OutCrc" = "1"!][!NOCODE!]
            [!VAR "MacCrc" = "0"!]
            [!VAR "MacNextBit" = "0"!]
            [!VAR "MacCrcNextBit" = "0"!]
            [!VAR "MacCounter" = "0"!]
            [!VAR "MacCrc" = "26"!]
            [!VAR "MacCrcNextBit" = "bit:xor(bit:and($Sync, 1), (bit:and((bit:shr($MacCrc, 10)), 1)))"!]
            [!VAR "MacCrc" = "bit:shl($MacCrc, 1)"!]
            [!IF "$MacCrcNextBit != 0"!]
                [!VAR "MacCrc" = "bit:xor($MacCrc, 901)"!]
            [!ENDIF!]
            [!VAR "MacNextBit" = "bit:and($Startup, 1)"!]
            [!VAR "MacCrcNextBit" = "bit:xor($MacNextBit, (bit:and((bit:shr($MacCrc, 10)), 1)))"!]
            [!VAR "MacCrc" = "bit:shl($MacCrc, 1)"!]
            [!IF "$MacCrcNextBit != 0"!]
                [!VAR "MacCrc" = "bit:xor($MacCrc, 901)"!]
            [!ENDIF!]
            [!FOR "MacCounter" = "10" TO "0" STEP "-1"!]
                [!VAR "MacNextBit" = "bit:and(bit:shr($FrameId,$MacCounter), 1)"!]
                [!VAR "MacCrcNextBit" = "bit:xor($MacNextBit, (bit:and((bit:shr($MacCrc, 10)), 1)))"!]
                [!VAR "MacCrc" = "bit:shl($MacCrc, 1)"!]
                [!VAR "MacCrc" = "bit:and($MacCrc, 65535)"!]
                [!IF "$MacCrcNextBit != 0"!]
                    [!VAR "MacCrc" = "bit:xor($MacCrc, 901)"!]
                [!ENDIF!]
            [!ENDFOR!]
            [!FOR "MacCounter" = "6" TO "0" STEP "-1"!]
                [!VAR "MacNextBit" = "bit:and(bit:shr($PayloadLengthW, $MacCounter), 1)"!]
                [!VAR "MacCrcNextBit" = "bit:xor($MacNextBit, (bit:and((bit:shr($MacCrc, 10)), 1)))"!]
                [!VAR "MacCrc" = "bit:shl($MacCrc, 1)"!]
                [!VAR "MacCrc" = "bit:and($MacCrc, 65535)"!]
                [!IF "$MacCrcNextBit != 0"!]
                    [!VAR "MacCrc" = "bit:xor($MacCrc, 901)"!]
                [!ENDIF!]
            [!ENDFOR!]
            [!VAR "MacCrc" = "(bit:and($MacCrc, 2047))"!]
            [!VAR "OutCrc" = "$MacCrc"!]
        [!ENDNOCODE!][!ENDMACRO!]

        [!// This macro returns a list of all slots received into the FIFOA and FIFOB
        [!MACRO "RxFIFOSlots", "FrIfCluster" = "", "FrController" = "", "OutFIFOASlots" = "", "OutFIFOBSlots" = ""!][!NOCODE!]
            [!VAR "OutFIFOASlots" = "''"!]
            [!VAR "OutFIFOBSlots" = "''"!]
            [!LOOP "(node:ref($FrController)/FrFifo/*)"!]
                [!IF "count(./FrRange/*) > 0"!]
                    [!LOOP "node:order(FrRange/*, 'node:value(./FrVendorSpecific/FrRangeMode)', 'node:name(.)')"!]
                        [!IF "node:value(../../FrChannels) = 'FR_CHANNEL_A'"!]
                            [!IF "node:value(./FrVendorSpecific/FrRangeMode) = 'FR_ACCEPTANCE'"!]
                                [!VAR "OutFIFOASlots" = "concat($OutFIFOASlots, ' ', text:join(text:range(node:value(./FrRangeMin), node:value(./FrRangeMax))))"!]
                            [!ELSE!]
                                [!VAR "Remove" = "text:join(text:range(node:value(./FrRangeMin), node:value(./FrRangeMax)))"!]
                                [!VAR "Result" = "''"!]
                                [!LOOP "text:split($OutFIFOASlots, ' ')"!]
                                    [!IF "not(text:contains(text:split($Remove, ' '), number(.)))"!]
                                        [!VAR "Result" = "concat($Result, ' ', .)"!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                                [!VAR "OutFIFOASlots" = "$Result"!]
                            [!ENDIF!]
                        [!ELSE!]
                            [!IF "node:value(./FrVendorSpecific/FrRangeMode) = 'FR_ACCEPTANCE'"!]
                                [!VAR "OutFIFOBSlots" = "concat($OutFIFOBSlots,' ',text:join(text:range(node:value(./FrRangeMin), node:value(./FrRangeMax))))"!]
                            [!ELSE!]
                                [!VAR "Remove" = "text:join(text:range(node:value(./FrRangeMin), node:value(./FrRangeMax)))"!]
                                [!VAR "Result" = "''"!]
                                [!LOOP "text:split($OutFIFOBSlots, ' ')"!]
                                    [!IF "not(text:contains(text:split($Remove, ' '), number(.)))"!]
                                        [!VAR "Result" = "concat($Result, ' ', .)"!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                                    [!VAR "OutFIFOBSlots" = "$Result"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!VAR "OutFIFOASlots" = "text:replaceAll($OutFIFOASlots, '\.0', '')"!]
            [!VAR "OutFIFOASlots" = "concat($OutFIFOASlots, ' ')"!]
            [!VAR "OutFIFOBSlots" = "text:replaceAll($OutFIFOBSlots, '\.0', '')"!]
            [!VAR "OutFIFOBSlots" = "concat($OutFIFOBSlots, ' ')"!]
        [!ENDNOCODE!][!ENDMACRO!]

        [!/* Macro will count the number of nonFifoMacs for the given FrControler in the FrIfCluster */!]
        [!MACRO "GetNonFifoMacs", "CfgVariant" = "string('PB')", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = ""!][!NOCODE!]
            [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(./FrIfFrCtrlRef) = node:ref($FrController)])"!]
                [!IF "$FrController = node:path(node:ref(./FrIfFrCtrlRef))"!]
                    [!LOOP "node:order(./FrIfLPdu/*,'node:value(./FrIfLPduIdx)','node:name(.)')"!]
                        [!/* Use references FrIfLPdu->FrIfFrameTriggering->FrIfFrameStructure->FrIfPdu to obtain direction of the LPdu - all PDus in frame must have same direction */!]
                        [!IF "node:name(node:ref(node:ref(node:ref(./FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position() = 1]/FrIfPduRef)/FrIfPduDirection) = 'FrIfRxPdu'"!]
                            [!VAR "MacNotFifo" = "'true'"!]
                            [!IF "node:value(node:ref(./FrIfVBTriggeringRef)/FrIfChannel) = 'FRIF_CHANNEL_A'"!]
                                [!IF "text:contains(text:split(string($FIFOASlots)), string(number(node:ref(./FrIfVBTriggeringRef)/FrIfSlotId)))"!]
                                    [!VAR "MacNotFifo" = "'false'"!]
                                [!ENDIF!]
                            [!ENDIF!]
                                [!IF "node:value(node:ref(./FrIfVBTriggeringRef)/FrIfChannel) = 'FRIF_CHANNEL_B'"!]
                                    [!IF "text:contains(text:split(string($FIFOBSlots)), string(number(node:ref(./FrIfVBTriggeringRef)/FrIfSlotId)))"!]
                                        [!VAR "MacNotFifo" = "'false'"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                                [!IF "$MacNotFifo = 'true'"!]
                                    [!VAR "NumberOfNonFifoMacs" = "num:i($NumberOfNonFifoMacs + 1)"!]
                                [!ENDIF!]
                        [!ELSE!]
                            [!VAR "NumberOfNonFifoMacs" = "num:i($NumberOfNonFifoMacs + 1)"!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDIF!]
            [!ENDSELECT!]
        [!ENDNOCODE!][!ENDMACRO!]

    [!ENDIF!]
[!ENDNOCODE!]
