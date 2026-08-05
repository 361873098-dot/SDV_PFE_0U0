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
 *  @file     Fr_SpecChecks.m
 *  @version  4.0.2
 *
 *  @brief    AUTOSAR Fr - specification checks.
 *  @details  FlexRay Protocol specification checks.
 */

    [!/* Multiple inclusion protection */!]
    [!IF "not(var:defined('FR_FRSPECCHECKS_M'))"!]
        [!VAR "FR_FRSPECCHECKS_M" = "'true'"!]

        [!/* This macro checks whether the configuration is according to the FlexRay specification 2.1A */!]
        [!/* Errors reported here use different numbering schema than the rest of errors */!]
        [!MACRO "SpecChecks", "FrIfCluster" = "", "FrController" = ""!]
            [!VAR "MacDynamicSegmentLength" = "number(node:ref($FrIfCluster)/FrIfGdMinislot) * number(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)"!]
            [!VAR "MacStaticSegmentLength" = "number(node:ref($FrIfCluster)/FrIfGdStaticSlot) * number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!]
            [!VAR "MacComputedNitLength" = "number(node:ref($FrIfCluster)/FrIfGMacroPerCycle) - number(node:ref($FrIfCluster)/FrIfGdSymbolWindow) - $MacDynamicSegmentLength - $MacStaticSegmentLength"!]
            [!/* Check the length of gdNit with respect to other parts of the cycle */!]
            [!IF "$MacComputedNitLength != number(node:ref($FrIfCluster)/FrIfGdNit)"!]
                [!ERROR!]
                    [!WS "0"!]Error 800: The length of gdNit must be equal to gMacroPerCycle - gdSymbolWindow - (gNumberOfStaticSlots * gdStaticSlot) - (gNumberOfMinislots * gdMinislot) = [!"num:i($MacComputedNitLength)"!].
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDMACRO!]

        [!/* This macro performs a check on the FrIf ASR nodes used in Fr plugin generation */!]
        [!MACRO "FrIfSanityCheck"!]
            [!NOCODE!]
                [!SELECT "node:ref('ASPathDataOfSchema:/AUTOSAR/EcucDefs/FrIf')"!]
                    [!/* Check FrIfController array */!]
                    [!LOOP "./FrIfConfig/FrIfCluster/*/FrIfController/*"!]
                        [!/* Check that all LPdus contain a valid reference to frame triggering */!]
                        [!IF "node:refvalid(./FrIfFrCtrlRef) = false()"!]
                            [!ERROR!]Error 010: [!"node:path(.)"!]/FrIfFrCtrlRef contains an invalid reference.[!ENDERROR!]
                        [!ENDIF!]

                        [!/* Check that FrIf LPdu Index is not duplicated in any FrIf LPdu array */!]
                        [!IF "text:uniq(../*/FrIfFrCtrlRef, ./FrIfFrCtrlRef) = false()"!]
                            [!ERROR!]Error 011: [!"node:path(.)"!]/FrIfFrCtrlRef is duplicated within [!"node:name(.)"!].[!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]

                    [!/* Check FrIf Frame Triggering */!]
                    [!LOOP "./FrIfConfig/FrIfCluster/*/FrIfController/*/FrIfFrameTriggering/*"!]
                        [!/* Check FrIfAllowDynamicLSduLength is disabled for static segment configuration */!]
                        [!IF "num:i(./FrIfSlotId) <= num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                            [!IF "node:value(FrIfAllowDynamicLSduLength) = 'true'"!]
                                [!ERROR!]Error 012: [!"node:path(.)"!]/FrIfAllowDynamicLSduLength is enabled altought the slot is configured in static segment.[!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]

                        [!/* Check FrIfChannel value in single channel mode */!]
                        [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/VendorSpecific/SingleChannelModeEnabled) = 'true'"!]
                            [!/* In single channel mode only CHANNEL_A is supported */!]
                            [!IF "node:value(./FrIfChannel) != 'FRIF_CHANNEL_A'"!]
                                [!ERROR!]Error 013: [!"node:path(.)"!]/FrIfChannel is set to [!"node:value(./FrIfChannel)"!], but the controller is configured as single channel device. For a single channel device, the application can access and configure only the registers related to internal channel A.[!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]

                        [!/* Check FrIfChannel value in multi channel mode */!]
                        [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/VendorSpecific/SingleChannelModeEnabled) = 'false'"!]
                            [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/FrPChannels) = 'FR_CHANNEL_A'"!]
                                [!IF "node:value(./FrIfChannel) = 'FRIF_CHANNEL_B'"!]
                                    [!ERROR!]Error 014: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_B but the controller is configured as connected to FR_CHANNEL_A only, see the [!"node:path(node:ref(../../FrIfFrCtrlRef))"!]/FrPChannels parameter.[!ENDERROR!]
                                [!ENDIF!]
                            [!ENDIF!]

                            [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/FrPChannels) = 'FR_CHANNEL_B'"!]
                                [!IF "node:value(./FrIfChannel) = 'FRIF_CHANNEL_A'"!]
                                    [!ERROR!]Error 015: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_A but the controller is configured as connected to FR_CHANNEL_B only, see the [!"node:path(node:ref(../../FrIfFrCtrlRef))"!]/FrPChannels parameter.[!ENDERROR!]
                                [!ENDIF!]
                            [!ENDIF!]

                            [!IF "num:i(./FrIfSlotId) > num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                                [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/FrPChannels) = 'FR_CHANNEL_B'"!]
                                    [!IF "node:value(./FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                                        [!ERROR!]Error 016: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but the controller is configured as connected to FR_CHANNEL_B only. Transmission or reception in the dynamic segment will not work.[!ENDERROR!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]

                            [!IF "num:i(./FrIfSlotId) > num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                                [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/FrPChannels) = 'FR_CHANNEL_AB'"!]
                                    [!IF "node:value(./FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                                        [!WARNING!]Error 010: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but transmission or reception in the dynamic segment on FlexRay channel B will be ignored.[!ENDWARNING!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]

                            [!IF "num:i(./FrIfSlotId) <= num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                                [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/FrPChannels) = 'FR_CHANNEL_A'"!]
                                    [!IF "node:value(./FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                                        [!WARNING!]Error 011: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but the controller is configured as connected to FR_CHANNEL_A only. Transmission or reception on FlexRay channel B will be ignored.[!ENDWARNING!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]

                            [!IF "num:i(./FrIfSlotId) <= num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                                [!IF "node:value(node:ref(../../FrIfFrCtrlRef)/FrPChannels) = 'FR_CHANNEL_B'"!]
                                    [!IF "node:value(./FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                                        [!WARNING!]Error 012: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but the controller is configured as connected to FR_CHANNEL_B only. Transmission or reception on FlexRay channel A will be ignored.[!ENDWARNING!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]

                        [!/* Check FrIfCycleRepetition value for static segment */!]
                        [!IF "num:i(./FrIfSlotId) <= num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                            [!IF "node:containsValue(text:split('1 2 4 8 16 32 64'), ./FrIfCycleRepetition) = false()"!]
                                [!ERROR!]Error 017: [!"node:path(.)"!]/FrIfCycleRepetition contains unsupported value [!"num:i(FrIfCycleRepetition)"!].[!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]

                        [!/* Check FrIfLSduLength value for dynamic segment */!]
                        [!IF "num:i(./FrIfSlotId) > num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                            [!IF "num:i(node:ref(../../FrIfFrCtrlRef)/FrPPayloadLengthDynMax) * 2 < ./FrIfLSduLength"!]
                                [!ERROR!]Error 018: [!"node:path(.)"!]/FrIfLSduLength is greater than [!"node:path(node:ref(../../FrIfFrCtrlRef)/FrPPayloadLengthDynMax)"!] * 2.[!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]

                        [!/* Check FrIfLSduLength value for static segment */!]
                        [!IF "num:i(./FrIfSlotId) <= num:i(../../../../FrIfGNumberOfStaticSlots)"!]
                            [!IF "num:i(../../../../FrIfGPayloadLengthStatic) * 2 != ./FrIfLSduLength"!]
                                [!ERROR!]Error 019: [!"node:path(.)"!]/FrIfLSduLength is not equal to [!"node:path(../../../..)"!]/FrIfGPayloadLengthStatic * 2 altought the slot is configured in static segment.[!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]

                        [!/* Check that all Frame Triggering contain a valid reference to frame structure */!]
                        [!IF "node:refvalid(./FrIfFrameStructureRef) = false()"!]
                            [!ERROR!]Error 020: [!"node:path(.)"!]/FrIfFrameStructureRef contains an invalid reference.[!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]

                    [!/* Check FrIf LPdus */!]
                    [!LOOP "./FrIfConfig/FrIfCluster/*/FrIfController/*/FrIfLPdu/*"!]
                        [!/* Check that FrIf LPdu Index is not duplicated in any FrIf LPdu array */!]
                        [!IF "text:uniq(../*/FrIfLPduIdx, ./FrIfLPduIdx) = false()"!]
                            [!ERROR!]Error 021: [!"node:path(.)"!]/FrIfLPduIdx is duplicated within [!"node:name(.)"!].[!ENDERROR!]
                        [!ENDIF!]

                        [!/* Check that FrIf LPdu Index values are consecutive */!]
                        [!IF "num:i(./FrIfLPduIdx) >= num:i(count(../*))"!]
                            [!ERROR!]Error 022: [!"node:path(.)"!]/FrIfLPduIdx is not consecutive within [!"node:name(.)"!].[!ENDERROR!]
                        [!ENDIF!]

                        [!/* Check that all LPdus contain a valid reference to frame triggering */!]
                        [!IF "node:refvalid(./FrIfVBTriggeringRef) = false()"!]
                            [!ERROR!]Error 023: [!"node:path(.)"!]/FrIfVBTriggeringRef contains an invalid reference.[!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]

                    [!/* Check that FrIf Communication Operation Index is not duplicated in any FrIf Communication Operation array */!]
                    [!LOOP "./FrIfConfig/FrIfCluster/*/FrIfJobList/FrIfJob/*/FrIfCommunicationOperation/*"!]
                        [!IF "text:uniq(../*/FrIfCommunicationOperationIdx, ./FrIfCommunicationOperationIdx) = false()"!]
                            [!ERROR!]Error 024: [!"node:path(.)"!]/FrIfCommunicationOperationIdx is duplicated within [!"node:name(.)"!].[!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDSELECT!]
            [!ENDNOCODE!]
        [!ENDMACRO!]
    [!ENDIF!]
[!ENDNOCODE!]
