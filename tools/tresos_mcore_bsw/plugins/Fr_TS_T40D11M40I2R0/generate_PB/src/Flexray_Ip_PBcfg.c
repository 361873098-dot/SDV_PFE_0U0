[!AUTOSPACING!]
[!NOCODE!]
    [!INCLUDE "Fr_VersionCheck.m"!]
    [!INCLUDE "Fr_SpecChecks.m"!]
    [!INCLUDE "Fr_GeneratorUtils.m"!]

    [!MACRO "CfgChecks", "FrIfCluster" = "", "FrController" = ""!]
    [!NOCODE!]
        [!WS "0"!][!// Key Slot checks
        [!IF "'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)) or 'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForSync))"!][!//Check whether the Key slot is used/enabled
            [!VAR "MacTempValue1" = "number(node:ref($FrController)/FrPKeySlotId)"!][!// Value of the Key slot
            [!VAR "MacTempValue2" = "number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!// Number of static slots
            [!WS "0"!][!//Check whether the Key Slot is correctly configured to static segment
            [!IF "$MacTempValue1 > $MacTempValue2"!]
                [!ERROR!]
                    [!WS "0"!]Error 004: The [!"$FrController"!]/FrKeySlotId value [!"num:i(number(node:ref($FrController)/FrPKeySlotId))"!] is greater than the [!"$FrIfCluster"!]/FrIfGNumberOfStaticSlots value [!"number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!].
                [!ENDERROR!]
            [!ENDIF!]
            [!WS "0"!][!//Check whether the Key Slot is correctly used for both sync and startup
            [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)!= node:value(node:ref($FrController)/FrPKeySlotUsedForSync)"!][!//Check whether sync and startup bits have the same value
                [!ERROR!]
                    [!WS "0"!]Error 005: The [!"$FrController"!]/FrPKeySlotUsedForStartup value '[!"node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)"!]' is different than the [!"$FrController"!]/FrPKeySlotUsedForSync value '[!"node:value(node:ref($FrController)/FrPKeySlotUsedForSync)"!]'.
                [!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!WS "0"!][!// No check, because the Key slot is unused
        [!ENDIF!]

        [!WS "0"!][!//Check whether a valid bitrate is selected
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/VendorSpecific/ChannelBitrate)"!]
        [!IF "($MacTempValue1!='br_10Mbps') and ($MacTempValue1!='br_5Mbps') and ($MacTempValue1!='br_2500kbps')"!]
            [!ERROR!]
                [!WS "0"!]Error 007: The [!"$FrController"!]/VendorSpecific/ChannelBitrate value [!"node:value(node:ref($FrController)/VendorSpecific/ChannelBitrate)"!] is not supported bitrate value.
            [!ENDERROR!]
        [!ENDIF!]

        [!WS "0"!][!//Check whether the symator value is correct
        [!VAR "MacTempValue1" = "num:i(number(node:value(node:ref($FrController)/VendorSpecific/SystemFrequency)) * 0.45)-8"!]
        [!IF "num:i(node:value(node:ref($FrController)/VendorSpecific/SystemMemoryAccessTimeOut)) > $MacTempValue1"!]
            [!WARNING!]
                [!WS "0"!]Warning 301: The [!"$FrController"!]/VendorSpecific/SystemMemoryAccessTimeOut value [!"node:value(node:ref($FrController)/VendorSpecific/SystemMemoryAccessTimeOut)"!] is too high for the selected System Frequency (fchi), the maximum value is [!"num:i($MacTempValue1)"!].
            [!ENDWARNING!]
        [!ENDIF!]

        [!WS "0"!][!//Check whether the controller channels are correctly configured
        [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
            [!IF "node:value(node:ref($FrController)/FrPChannels)='FR_CHANNEL_AB'"!]
                [!ERROR!]
                    [!WS "0"!]Error 027: The [!"$FrController"!]/VendorSpecific/SingleChannelModeEnabled is enabled but [!"$FrController"!]/FrPChannels is set to FR_CHANNEL_AB.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "node:value(node:ref($FrController)/FrPWakeupChannel)='FR_CHANNEL_B'"!]
                [!ERROR!]
                    [!WS "0"!]Error 023: The [!"$FrController"!]/VendorSpecific/SingleChannelModeEnabled is enabled but [!"$FrController"!]/FrPWakeupChannel is set to FR_CHANNEL_B. For a single channel device, the application can access and configure only the registers related to internal channel A.
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
        [!WS "0"!][!//Check number of configured absolute counters and their indices validity
        [!IF "count(node:ref($FrController)/FrAbsoluteTimer/*)<1"!][!// Check that at least one timer is configured
            [!ERROR!]
                [!WS "0"!]Error 008: The [!"$FrController"!]/FrAbsoluteTimer does not contain any Absolute timer, at least one is required.
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "count(node:ref($FrController)/FrAbsoluteTimer/*)>(ecu:get('FR.AbsTimer'))"!][!// Check that at most two timers are configured
            [!ERROR!]
                [!WS "0"!]Error 009: The [!"$FrController"!]/FrAbsoluteTimer contains more than 2 absolute timers, only 2 of them are available on the hardware.
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "count(node:ref($FrController)/FrAbsoluteTimer/*)>1"!][!//If two timers are configured, check that indices are unique
            [!IF "node:value(node:ref($FrController)/FrAbsoluteTimer/*[position()=1]/FrAbsTimerIdx)=node:value(node:ref($FrController)/FrAbsoluteTimer/*[position()=2]/FrAbsTimerIdx)"!]
                [!ERROR!]
                    [!WS "0"!]Error 010: The index of the absolute timer [!"node:path(node:ref($FrController)/FrAbsoluteTimer/*[position()=1])"!] is equal to the index of the absolute timer [!"node:path(node:ref($FrController)/FrAbsoluteTimer/*[position()=2])"!].
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
        [!LOOP "node:ref($FrController)/FrAbsoluteTimer/*"!][!//For each configured timer
            [!IF "FrAbsTimerIdx>=count(node:ref($FrController)/FrAbsoluteTimer/*)"!][!//Check whether the index is within range 0..n-1
                [!ERROR!]
                    [!WS "0"!]Error 011: The index of the absolute timer [!"node:path(.)"!] should be lower than [!"num:i(count(node:ref($FrController)/FrAbsoluteTimer/*))"!].
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!WS "0"!][!// Check LPdus, FrameTriggerings...
        [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
        [!LOOP "node:order(FrIfLPdu/*,'node:value(FrIfLPduIdx)','node:name(.)')"!]
            [!WS "0"!][!//Check that all LPdus contain valid reference to frame triggering
            [!IF "text:tolower(node:refvalid(FrIfVBTriggeringRef))='false'"!][!// Check FrIfVBTriggeringRef reference validity
                [!ERROR!]
                    [!WS "0"!]Error 012: [!"node:path(.)"!]/FrIfVBTriggeringRef contains an invalid reference.
                [!ENDERROR!]
            [!ENDIF!]
            [!WS "0"!][!//Check that LPdu indices are unique
            [!IF "text:tolower(text:uniq(../*/FrIfLPduIdx, FrIfLPduIdx)) = 'false'"!][!// Check FrIfVBTriggeringRef reference validity
                [!ERROR!]
                    [!WS "0"!]Error 020: [!"node:path(.)"!]/FrIfLPduIdx is not unique within all LPdus.
                [!ENDERROR!]
            [!ENDIF!]
            [!WS "0"!][!//Check that LPdu indices constitute continuous row beginning with 0
            [!IF "number(FrIfLPduIdx) >= count(../*)"!][!// Check FrIfVBTriggeringRef reference validity
                [!ERROR!]
                    [!WS "0"!]Error 021: LPdu indices do not create continuous row beginning with 0
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!WS "0"!][!//Check that all FrameTriggerings contain valid reference to frame structure
        [!LOOP "node:order(FrIfFrameTriggering/*,'node:name(.)')"!]
            [!IF "text:tolower(node:refvalid(FrIfFrameStructureRef))='false'"!][!// Check FrIfFrameStructureRef reference validity
                [!ERROR!]
                    [!WS "0"!]Error 006: [!"node:path(.)"!]/FrIfFrameStructureRef contains an invalid reference.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "number(FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!//Check whether it is static or dynamic segment slot
                [!WS "0"!][!//Dynamic
                [!IF "number(node:ref($FrController)/FrPPayloadLengthDynMax) * 2 < FrIfLSduLength"!]
                    [!ERROR!]
                        [!WS "0"!]Error 019: [!"node:path(.)"!]/FrIfLSduLength is greater than [!"node:path(node:ref($FrController))"!]/FrPPayloadLengthDynMax * 2.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!WS "0"!][!//Static
                [!IF "number(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic) * 2 != FrIfLSduLength"!][!//Check the length
                    [!ERROR!]
                        [!WS "0"!]Error 017: [!"node:path(.)"!]/FrIfLSduLength is not equal to [!"node:path(node:ref($FrIfCluster))"!]/FrIfGPayloadLengthStatic * 2 altought the slot is configured in static segment.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "text:tolower(node:value(FrIfAllowDynamicLSduLength))='true'"!][!//Check the that dynamic length is disabled
                    [!ERROR!]
                        [!WS "0"!]Error 018: [!"node:path(.)"!]/FrIfAllowDynamicLSduLength is enabled altought the slot is configured in static segment.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "number(FrIfCycleRepetition) != 1"!]
                    [!IF "number(FrIfCycleRepetition) != 2"!]
                        [!IF "number(FrIfCycleRepetition) != 4"!]
                            [!IF "number(FrIfCycleRepetition) != 8"!]
                                [!IF "number(FrIfCycleRepetition) != 16"!]
                                    [!IF "number(FrIfCycleRepetition) != 32"!]
                                        [!IF "number(FrIfCycleRepetition) != 64"!]
                                            [!ERROR!]
                                                [!WS "0"!]Error 036: [!"node:path(.)"!]/FrIfCycleRepetition contains unsupported value [!"num:i(FrIfCycleRepetition)"!].
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
            [!WS "0"!][!//Check that none is assigned for both channels if the single channel mode is enabled
            [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
                [!IF "node:value(FrIfChannel) != 'FRIF_CHANNEL_A'"!]
                    [!ERROR!]
                        [!WS "0"!]Error 022: [!"node:path(.)"!]/FrIfChannel is set to [!"node:value(FrIfChannel)"!] but the controller is configured as single channel device. For a single channel device, the application can access and configure only the registers related to internal channel A.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!IF "node:value(node:ref($FrController)/FrPChannels)='FR_CHANNEL_AB'"!]
                    [!IF "number(FrIfSlotId) > number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!]
                        [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                            [!WARNING!]
                                [!WS "0"!]Warning 303: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but transmission or reception in the dynamic segment on FlexRay channel B will be ignored.
                            [!ENDWARNING!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ELSE!]
                    [!IF "node:value(node:ref($FrController)/FrPWakeupChannel)!=node:value(node:ref($FrController)/FrPChannels)"!]
                        [!ERROR!]
                            [!WS "0"!]Error 024: [!"$FrController"!]/FrPChannels is set to [!"node:value(node:ref($FrController)/FrPChannels)"!] only but [!"$FrController"!]/FrPWakeupChannel is set to [!"node:value(node:ref($FrController)/FrPWakeupChannel)"!].
                        [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "node:value(node:ref($FrController)/FrPChannels)='FR_CHANNEL_A'"!]
                        [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_B'"!]
                            [!ERROR!]
                                [!WS "0"!]Error 025: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_B but the controller is configured as connected to FR_CHANNEL_A only, see the [!"$FrController"!]/FrPChannels parameter.
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                            [!IF "number(FrIfSlotId) <= number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!]
                                [!WARNING!]
                                    [!WS "0"!]Warning 304: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but the controller is configured as connected to FR_CHANNEL_A only. Transmission or reception on FlexRay channel B will be ignored.
                                [!ENDWARNING!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                    [!IF "node:value(node:ref($FrController)/FrPChannels)='FR_CHANNEL_B'"!]
                        [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_A'"!]
                            [!ERROR!]
                                [!WS "0"!]Error 026: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_A but the controller is configured as connected to FR_CHANNEL_B only, see the [!"$FrController"!]/FrPChannels parameter.
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_AB'"!]
                            [!IF "number(FrIfSlotId) <= number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!// Static segment
                                [!WARNING!]
                                    [!WS "0"!]Warning 305: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but the controller is configured as connected to FR_CHANNEL_B only. Transmission or reception on FlexRay channel A will be ignored.
                                [!ENDWARNING!]
                            [!ELSE!][!// Dynamic segment
                                [!ERROR!]
                                    [!WS "0"!]Error 038: [!"node:path(.)"!]/FrIfChannel is set to FRIF_CHANNEL_AB but the controller is configured as connected to FR_CHANNEL_B only. Transmission or reception in the dynamic segment will not work.
                                [!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!ENDSELECT!]

        [!IF "count(node:ref($FrController)/FrFifo/*)>0"!][!//Check that FIFO was configured
            [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
                [!IF "count(node:ref($FrController)/FrFifo/*)>1"!][!//Check that count of FIFOs is less than 1
                    [!ERROR!]
                        [!WS "0"!]Error 039: [!"$FrController"!]/VendorSpecific/SingleChannelModeEnabled is enabled but the [!"$FrController"!]/FrFifo container contains more than 1 FIFO, only 1 FIFO is supported when the controller is configured as single channel device.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "node:value(node:ref($FrController)/FrFifo/*/FrChannels)='FR_CHANNEL_B'"!]
                    [!ERROR!]
                        [!WS "0"!]Error 040: [!"$FrController"!]/VendorSpecific/SingleChannelModeEnabled is enabled but [!"node:path(node:ref($FrController)/FrFifo/*[position()=1]/FrChannels)"!] is set to FR_CHANNEL_B. For a single channel device, the application can access and configure only the registers related to internal channel A.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ELSE!][!//Dual channel mode
                [!IF "node:value(node:ref($FrController)/FrPChannels)!='FR_CHANNEL_AB'"!]
                    [!IF "count(node:ref($FrController)/FrFifo/*)>1"!]
                        [!ERROR!]
                            [!WS "0"!]Error 041: The [!"$FrController"!]/FrFifo container contains more than 1 FIFO but [!"node:path(node:ref($FrController)/FrPChannels)"!] is set to [!"node:value(node:ref($FrController)/FrPChannels)"!] only. Only one FIFO per channel is supported by the hardware.
                        [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "node:value(node:ref($FrController)/FrPChannels)!= node:value(node:ref($FrController)/FrFifo/*[position()=1]/FrChannels)"!]
                        [!ERROR!]
                            [!WS "0"!]Error 042: Wrong channel is assigned to FIFO. [!"node:path(node:ref($FrController)/FrFifo/*[position()=1]/FrChannels)"!] is configured to [!"node:value(node:ref($FrController)/FrFifo/*[position()=1]/FrChannels)"!] but [!"node:path(node:ref($FrController)/FrPChannels)"!] is configured to [!"node:value(node:ref($FrController)/FrPChannels)"!].
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
                [!WS "0"!][!// Check that at most 2 FIFOs are configured and for different channels, with at least one range filter for each
                [!IF "count(node:ref($FrController)/FrFifo/*)>2"!][!//Check that count of FIFOs is less than 2
                    [!ERROR!]
                        [!WS "0"!]Error 013: [!"node:ref($FrController)"!]/FrFifo contains more than 2 FIFOs, only 2 of them are supported by the hardware.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "count(node:ref($FrController)/FrFifo/*)>1"!][!//If more FIFOs are configured then check
                    [!IF "node:value(node:ref($FrController)/FrFifo/*[position()=1]/FrChannels)=node:value(node:ref($FrController)/FrFifo/*[position()=2]/FrChannels)"!]
                        [!ERROR!]
                            [!WS "0"!]Error 014: [!"node:ref($FrController)"!]/FrFifo - both FIFOs are configured for the same channel.
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
            [!LOOP "node:ref($FrController)/FrFifo/*"!][!//For each fifo
                [!IF "count(FrRange/*)<1"!][!//Check that at least one range is defined
                    [!ERROR!]
                        [!WS "0"!]Error 015: [!"node:path(.)"!]/FrRange does not contain any range filter, please configure at least one.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "count(FrRange/*)>4"!][!//Check that at most 4 ranges are defined
                    [!ERROR!]
                        [!WS "0"!]Error 016: [!"node:path(.)"!]/FrRange contains more than 4 range filters, please configure at at most 4.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "count(FrRange/*[node:value(FrVendorSpecific/FrRangeMode) = 'FR_ACCEPTANCE'])<1"!][!//Check that at least one acceptance range is defined
                    [!ERROR!]
                        [!WS "0"!]Error 030: [!"node:path(.)"!]/FrRange does not contain any acceptance range.
                    [!ENDERROR!]
                [!ENDIF!]
                [!WS "0"!][!//Check that all ranges have maximum greater or equal to minimum
                [!LOOP "FrRange/*"!]
                    [!IF "number(FrRangeMax)<number(FrRangeMin)"!]
                        [!ERROR!]
                            [!WS "0"!]Error 028: FrRangeMax is lower than FrRangeMin in the [!"node:path(.)"!].
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]
        [!ENDIF!]
        [!WS "0"!][!// Check that communication operations have unique indices
        [!SELECT "node:ref($FrIfCluster)/FrIfJobList"!]
            [!LOOP "FrIfJob/*"!]
                [!LOOP "FrIfCommunicationOperation/*"!]
                    [!IF "text:tolower(text:uniq(../*/FrIfCommunicationOperationIdx, FrIfCommunicationOperationIdx)) = 'false'"!]
                        [!ERROR!]
                            [!WS "0"!]Error 033: [!"node:path(.)"!]/FrIfCommunicationOperationIdx is not unique within [!"node:path(../..)"!].
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]
        [!ENDSELECT!]
    [!ENDNOCODE!]
    [!ENDMACRO!]



    [!MACRO "ExtendedCfgChecks", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = "", "Reconfigurations" = "", "ReconfigurationsDynamic" = ""!]
        [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
            [!IF "$FrController = node:path(node:ref(FrIfFrCtrlRef))"!]
                [!VAR "MacKeySlotTransmitted" = "'false'"!]
                [!LOOP "node:order(FrIfLPdu/*,'node:value(FrIfLPduIdx)','node:name(.)')"!]
                    [!VAR "MacLPduIndex" = "num:i(FrIfLPduIdx)"!]
                    [!VAR "MacReconfigurable" = "text:tolower(node:value(FrIfReconfigurable))"!]
                    [!VAR "MacLPduPath" = "node:path(.)"!]
                    [!SELECT "node:ref(FrIfVBTriggeringRef)"!]
                        [!WS "0"!][!// Check which LPdus are received into the FIFO A and check that they are not reconfigurable
                        [!IF "node:name(node:ref(node:ref(FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu'"!]
                            [!WS "0"!][!// Receive LPdu
                            [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_A'"!]
                                [!IF "text:contains(text:split(string($FIFOASlots)), string(FrIfSlotId))"!]
                                    [!INFO!]
                                        [!WS "0"!]LPdu [!"$MacLPduIndex"!] will be received into the FIFO A.
                                    [!ENDINFO!]
                                    [!IF "$MacReconfigurable = 'true'"!]
                                        [!ERROR!]
                                            [!WS "0"!]Error 031: LPdu [!"$MacLPduIndex"!] ([!"$MacLPduPath"!]) will be received into the FIFO A but the FrIfReconfigurable is set.
                                        [!ENDERROR!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                            [!WS "0"!][!// Check which LPdus are received into the FIFO B and check that they are not reconfigurable
                            [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_B'"!]
                                [!IF "text:contains(text:split(string($FIFOBSlots)), string(FrIfSlotId))"!]
                                    [!INFO!]
                                        [!WS "0"!]LPdu [!"$MacLPduIndex"!] will be received into the FIFO B.
                                    [!ENDINFO!]
                                    [!IF "$MacReconfigurable = 'true'"!]
                                        [!ERROR!]
                                            [!WS "0"!]Error 032: LPdu [!"$MacLPduIndex"!] ([!"$MacLPduPath"!]) will be received into the FIFO B but the FrIfReconfigurable is set.
                                        [!ENDERROR!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ELSE!]
                            [!WS "0"!][!// Transmit LPdu
                            [!WS "0"!][!// Check whether it is a Key Slot transmission LPdu
                            [!IF "'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)) or 'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForSync))"!][!//Check whether the Key slot is used/enabled
                                [!IF "number(FrIfSlotId) = number(node:ref($FrController)/FrPKeySlotId) "!]
                                    [!VAR "MacKeySlotTransmitted" = "'true'"!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDLOOP!]
                [!IF "'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)) or 'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForSync))"!][!//Check whether the Key slot is used/enabled
                    [!IF "$MacKeySlotTransmitted != 'true'"!]
                        [!WARNING!]
                            [!WS "0"!]Warning 302: There is no LPdu assigned for the Key Slot transmission. There is no LPdu in the [!"node:path(.)"!] assined for Key Slot with FrPKeySlotId=[!"(node:value(node:ref($FrController)/FrPKeySlotId))"!] configured in the [!"$FrController"!] container.
                        [!ENDWARNING!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDMACRO!]



    [!MACRO "LPduConfigs", "CfgVariant" = "string('PB')", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = ""!]
        [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
            [!IF "$FrController = node:path(node:ref(FrIfFrCtrlRef))"!]
                [!VAR "MacFIFOACountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOAConfigured" = "false()"!]
                [!VAR "MacFIFOBConfigured" = "false()"!]
                [!VAR "MacStaticBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacStaticBuffersCnt" = "num:i(($MacStaticBuffersCnt - $MacFIFOACountS) - $MacFIFOBCountS)"!]
                [!VAR "MacReconfigGroups" = "(count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!]
                [!VAR "MacReconfigDyncmicGroups" = "(count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!]
                [!VAR "MacBufferMasters" = "string('')"!]
                [!VAR "MacBufferMastersDynamic" = "string('')"!]
                [!WS "0"!][!// Check whether the node is connected to one or two channels
                [!VAR "MacStaticPosition" = "num:i(0)"!][!// Counter of used buffers in the static segment
                [!VAR "MacDynamicPosition" = "num:i($MacStaticBuffersCnt - $MacReconfigGroups)"!][!// Couter of used buffers in the dynamicsegment
                [!SELECT "node:ref($FrIfCluster)/../.."!]
                    [!VAR "FrIfConfigIndex" = "position()"!]
                [!ENDSELECT!]
                [!WS "0"!]static Flexray_Ip_IndConfigType [!//
                    [!WS "0"!]FrIfMC[!"$FrIfConfigIndex"!]_[!//
                    [!WS "0"!]Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_[!//
                    [!WS "0"!]Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_[!//
                    [!WS "0"!]pIndBufConfig_[!//
                    [!WS "0"!][!"string($CfgVariant)"!][] =
                [!WS "0"!]{
                [!VAR "MacComma" = "''"!][!// /* always put comma var at first of loop. on first iteration, comma var will be blank.*/
                [!VAR "reachRxLPdu" = "false()"!][!// Needed when checking for empty array generation. At least one of these two variables will be set, when using a correct Fr FrIf configuration.
                [!VAR "reachTxLPdu" = "false()"!]
                [!LOOP "node:order(FrIfLPdu/*,'node:value(FrIfLPduIdx)','node:name(.)')"!]
                    [!VAR "MacReconfig" = "node:value(FrIfReconfigurable)"!]
                    [!WS "0"!][!// Use references FrIfLPdu->FrIfFrameTriggering->FrIfFrameStructur->FrIfPdu to obtain direction of the LPdu - all PDus in frame must have same direction
                    [!IF "node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu'"!]
                        [!WS "0"!][!// Receive LPdu
                        [!VAR "MacNotFifo" = "true()"!]
                        [!IF "node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A'"!]
                            [!IF "text:contains(text:split(string($FIFOASlots)), string(number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)))"!]
                                [!VAR "MacNotFifo" = "false()"!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!IF "node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B'"!]
                            [!IF "text:contains(text:split(string($FIFOBSlots)), string(number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)))"!]
                                [!VAR "MacNotFifo" = "false()"!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!IF "text:tolower($MacNotFifo) = 'true'"!]
                            [!VAR "reachRxLPdu" = "true()"!]
                            [!WS "0"!][!IF "$MacComma = ','"!][!"$MacComma"!][!CR!][!ENDIF!][!//
                            [!WS "4"!]/* below is lpduid [!"node:value(FrIfLPduIdx)"!] */
                            [!WS "4"!]{
                            [!WS "0"!][!// Get the information about the LPdu usage from the FrIfTriggering
                            [!IF "number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!// Static or dynamic slot?
                                [!VAR "MacLPduIdx" = "num:i(FrIfLPduIdx)"!]
                                [!VAR "MacReconfigurableDynamic"="'false'"!]
                                [!LOOP "text:split($ReconfigurationsDynamic, '#')"!][!// Go through all groups of LPdus sharing one buffer
                                    [!VAR "MacRMaster" = "text:split(.,' ')[1]"!][!// Master LPdu will have own the buffer and share it with the slaves - the rest of the group
                                    [!LOOP "text:split(.,' ')"!]
                                        [!IF "num:i(.)=$MacLPduIdx"!][!// Check whether the current LPdu is in the group
                                            [!VAR "MacReconfigurableDynamic"="'true'"!]
                                            [!IF "text:tolower(text:contains(string($MacBufferMastersDynamic), concat('#',$MacRMaster,' ')))='true'"!][!// Check whether the group has already a master
                                                [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMastersDynamic, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                                [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMastersDynamic, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                                [!WS "8"!](boolean)FALSE,  /* First Init */
                                            [!ELSE!]
                                                [!VAR "MacBufferMastersDynamic" = "concat($MacBufferMastersDynamic, '#', $MacRMaster, ' ', $MacDynamicPosition)"!][!// No master yet, this LPdu will be a master - assign it a buffer and save this info
                                                [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                                [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                                [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                                                [!WS "8"!](boolean)TRUE,   /* First Init */
                                            [!ENDIF!]
                                        [!ENDIF!]
                                    [!ENDLOOP!]
                                [!ENDLOOP!]
                                [!IF "$MacReconfigurableDynamic='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                    [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                    [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                    [!WS "8"!](boolean)TRUE,   /* First Init */
                                    [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                                [!ENDIF!]
                            [!ELSE!]
                                [!VAR "MacLPduIdx" = "num:i(FrIfLPduIdx)"!]
                                [!VAR "MacReconfigurable"="'false'"!]
                                [!LOOP "text:split($Reconfigurations, '#')"!][!// Go through all groups of LPdus sharing one buffer
                                    [!VAR "MacRMaster" = "text:split(.,' ')[1]"!][!// Master LPdu will have own the buffer and share it with the slaves - the rest of the group
                                    [!LOOP "text:split(.,' ')"!]
                                        [!IF "num:i(.)=$MacLPduIdx"!][!// Check whether the current LPdu is in the group
                                            [!VAR "MacReconfigurable"="'true'"!]
                                            [!IF "text:tolower(text:contains(string($MacBufferMasters), concat('#',$MacRMaster,' ')))='true'"!][!// Check whether the group has already a master
                                                [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMasters, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                                [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMasters, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                                [!WS "8"!](boolean)FALSE,  /* First Init */
                                            [!ELSE!]
                                                [!VAR "MacBufferMasters" = "concat($MacBufferMasters, '#', $MacRMaster, ' ', $MacStaticPosition)"!][!// No master yet, this LPdu will be a master - assign it a buffer and save this info
                                                [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                                [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                                [!VAR "MacStaticPosition" = "num:i($MacStaticPosition + 1)"!]
                                                [!WS "8"!](boolean)TRUE,   /* First Init */
                                            [!ENDIF!]
                                        [!ENDIF!]
                                    [!ENDLOOP!]
                                [!ENDLOOP!]
                                [!IF "$MacReconfigurable='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                    [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                    [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                    [!WS "8"!](boolean)TRUE,   /* First Init */
                                    [!VAR "MacStaticPosition" = "num:i($MacStaticPosition + 1)"!]
                                [!ENDIF!]
                            [!ENDIF!]
                            [!SELECT "node:ref(FrIfVBTriggeringRef)"!]
                                [!WS "8"!][!"num:i(FrIfSlotId)"!]U, /* Receive Frame ID */
                                [!WS "8"!]0x0000U, /* no header crc needed for rx mb*/
                                [!WS "8"!](boolean)FALSE,  /* Payload preamble disabled */
                                [!WS "8"!][!"num:i(((FrIfLSduLength + 1) div 2))"!]U, /* Data Length in Words */
                                [!WS "8"!](boolean)FALSE,  /* is not TX */
                                [!IF "node:value(FrIfChannel)='FRIF_CHANNEL_A'"!]
                                    [!WS "8"!](boolean)TRUE,   /* Reception on channel A enabled */
                                    [!WS "8"!](boolean)FALSE,  /* Reception on channel B disabled */
                                [!ELSEIF "node:value(FrIfChannel)='FRIF_CHANNEL_B'"!]
                                    [!WS "8"!](boolean)FALSE,  /* Reception on channel A disabled */
                                    [!WS "8"!](boolean)TRUE,   /* Reception on channel B enabled */
                                [!ELSE!][!// FRIF_CHANNEL_AB
                                    [!WS "8"!](boolean)TRUE,   /* Reception on channel A enabled */
                                    [!WS "8"!](boolean)TRUE,   /* Reception on channel B enabled */
                                [!ENDIF!]
                                [!IF "node:value(FrIfCycleRepetition)!='1'"!]
                                    [!WS "8"!](boolean)TRUE,  /* Cycle counter filtering enabled */
                                [!ELSE!]
                                    [!WS "8"!](boolean)FALSE,  /* Cycle counter filtering disabled */
                                [!ENDIF!]
                                [!WS "8"!][!"node:value(FrIfBaseCycle)"!]U, /* Cycle counter filter match value */
                                [!WS "8"!][!"num:inttohex(node:value(FrIfCycleRepetition)-1,2)"!]U, /* Cycle counter filter mask (repetition each [!"node:value(FrIfCycleRepetition)"!] cycles) */
                                [!WS "8"!](boolean)FALSE,  /* Repeat TX N/A */
                                [!WS "8"!](boolean)FALSE,  /* Dynamic payload length N/A */
                                [!WS "8"!](boolean)TRUE,   /* Buffer Enabled */
                                [!WS "8"!]{   /* frame header */
                                [!WS "12"!](boolean)FALSE, /* reservedBit */
                                [!WS "12"!](boolean)FALSE, /* payloadPreambleIndicator */
                                [!WS "12"!](boolean)FALSE, /* nullFrameIndicator */
                                [!WS "12"!](boolean)FALSE, /* syncFrameIndicator */
                                [!WS "12"!](boolean)FALSE, /* startupFrameIndicator */
                                [!WS "12"!]0U, /* frameID */
                                [!WS "12"!]0U, /* cycleCount */
                                [!WS "12"!]0U, /* payloadLength */
                                [!WS "12"!]0U, /* headerCrc */
                                [!WS "12"!]0U /* slotStatus */
                                [!WS "8"!]}
                                [!WS "4"!]}[!//
                            [!ENDSELECT!]
                            [!VAR "MacComma" = "','"!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!VAR "reachTxLPdu" = "true()"!]
                        [!WS "0"!][!// Transmit LPdu
                        [!WS "0"!][!// Build the structure name from the indices of LPdu, Controller, Cluster and Multiple configuration position within the
                        [!WS "0"!][!IF "$MacComma = ','"!][!"$MacComma"!][!CR!][!ENDIF!][!//
                        [!WS "4"!]/* below is lpduid [!"node:value(FrIfLPduIdx)"!] */
                        [!WS "4"!]{
                        [!WS "0"!][!// Get the information about the LPdu usage from the FrIfTriggering
                        [!IF "number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!// Static or dynamic slot?
                            [!VAR "MacLPduIdx" = "num:i(FrIfLPduIdx)"!]
                            [!VAR "MacReconfigurableDynamic"="'false'"!]
                            [!LOOP "text:split($ReconfigurationsDynamic, '#')"!][!// Go through all groups of LPdus sharing one buffer
                                [!VAR "MacRMaster" = "text:split(.,' ')[1]"!][!// Master LPdu will have own the buffer and share it with the slaves - the rest of the group
                                [!LOOP "text:split(.,' ')"!]
                                    [!IF "num:i(.)=$MacLPduIdx"!][!// Check whether the current LPdu is in the group
                                        [!VAR "MacReconfigurableDynamic"="'true'"!]
                                        [!IF "text:tolower(text:contains(string($MacBufferMastersDynamic), concat('#',$MacRMaster,' ')))='true'"!][!// Check whether the group has already a master
                                            [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMastersDynamic, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                            [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMastersDynamic, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                            [!WS "8"!](boolean)FALSE,  /* First Init */
                                        [!ELSE!]
                                            [!VAR "MacBufferMastersDynamic" = "concat($MacBufferMastersDynamic, '#', $MacRMaster, ' ', $MacDynamicPosition)"!][!// No master yet, this LPdu will be a master - assign it a buffer and save this info
                                            [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                            [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                            [!WS "8"!](boolean)TRUE,   /* First Init */
                                            [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                            [!ENDLOOP!]
                            [!IF "$MacReconfigurableDynamic='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                [!WS "8"!](boolean)TRUE,   /* First Init */
                                [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                            [!ENDIF!]
                        [!ELSE!]
                            [!VAR "MacLPduIdx" = "num:i(FrIfLPduIdx)"!]
                            [!VAR "MacReconfigurable"="'false'"!]
                            [!LOOP "text:split($Reconfigurations, '#')"!][!// Go through all groups of LPdus sharing one buffer
                                [!VAR "MacRMaster" = "text:split(.,' ')[1]"!][!// Master LPdu will have own the buffer and share it with the slaves - the rest of the group
                                [!LOOP "text:split(.,' ')"!]
                                    [!IF "num:i(.)=$MacLPduIdx"!][!// Check whether the current LPdu is in the group
                                        [!VAR "MacReconfigurable"="'true'"!]
                                        [!IF "text:tolower(text:contains(string($MacBufferMasters), concat('#',$MacRMaster,' ')))='true'"!][!// Check whether the group has already a master
                                            [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMasters, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                            [!WS "8"!][!"text:split(text:grep(text:split($MacBufferMasters, '#'),concat('^',$MacRMaster, ' [0-9]*')))[2]"!]U,[!// There is already a master, this LPdu will use the same buffer
                                            [!WS "8"!](boolean)FALSE,  /* First Init */
                                        [!ELSE!]
                                            [!VAR "MacBufferMasters" = "concat($MacBufferMasters, '#', $MacRMaster, ' ', $MacStaticPosition)"!][!// No master yet, this LPdu will be a master - assign it a buffer and save this info
                                            [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                            [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                            [!WS "8"!](boolean)TRUE,   /* First Init */
                                            [!VAR "MacStaticPosition" = "num:i($MacStaticPosition + 1)"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                            [!ENDLOOP!]
                            [!IF "$MacReconfigurable='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                [!WS "8"!][!"num:i($MacStaticPosition)"!]U,
                                [!WS "8"!](boolean)TRUE,   /* First Init */
                                [!VAR "MacStaticPosition" = "num:i($MacStaticPosition + 1)"!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!SELECT "node:ref(FrIfVBTriggeringRef)"!]
                            [!WS "8"!][!"num:i(FrIfSlotId)"!]U, /* Transmit Frame ID */
                            [!VAR "MacSlotStartup"="0"!]
                            [!VAR "MacSlotSync"="0"!]
                            [!IF "'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)) or 'true' = text:tolower(node:value(node:ref($FrController)/FrPKeySlotUsedForSync))"!][!//Check whether the Key slot is used/enabled
                                [!IF "num:i(FrIfSlotId)=num:i(node:ref($FrController)/FrPKeySlotId)"!]
                                    [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)"!][!VAR "MacSlotStartup"="1"!][!ENDIF!]
                                    [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForSync)"!][!VAR "MacSlotSync"="1"!][!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                            [!CALL "CrcCalculation", "Sync" = "number($MacSlotSync)", "Startup" = "number($MacSlotStartup)", "FrameId" = "num:i(FrIfSlotId)", "PayloadLengthW" = "num:i(((FrIfLSduLength + 1) div 2))", "OutCrc"="1"!]
                            [!WS "8"!][!"num:inttohex($OutCrc,4)"!]U, /* Frame Header CRC */
                            [!IF "text:tolower(node:value(FrIfPayloadPreamble))='false'"!]
                                [!WS "8"!](boolean)FALSE,  /* Payload preamble disabled */
                            [!ELSE!]
                                [!WS "8"!](boolean)TRUE,   /* Payload preamble enabled */
                            [!ENDIF!]
                            [!WS "8"!][!"num:i(((FrIfLSduLength + 1) div 2))"!]U, /* Data Length in Words */
                            [!WS "8"!](boolean)TRUE,  /* is TX */
                            [!IF "node:value(FrIfChannel)='FRIF_CHANNEL_A'"!]
                                [!WS "8"!](boolean)TRUE,   /* Transmission on channel A enabled */
                                [!WS "8"!](boolean)FALSE,  /* Transmission on channel B disabled */
                            [!ELSEIF "node:value(FrIfChannel)='FRIF_CHANNEL_B'"!]
                                [!WS "8"!](boolean)FALSE,  /* Transmission on channel A disabled */
                                [!WS "8"!](boolean)TRUE,   /* Transmission on channel B enabled */
                            [!ELSE!][!// FRIF_CHANNEL_AB
                                [!WS "8"!](boolean)TRUE,   /* Transmission on channel A enabled */
                                [!WS "8"!](boolean)TRUE,   /* Transmission on channel B enabled */
                            [!ENDIF!]
                            [!IF "node:value(FrIfCycleRepetition)!='1'"!]
                                [!WS "8"!](boolean)TRUE,  /* Cycle counter filtering enabled */
                            [!ELSE!]
                                [!WS "8"!](boolean)FALSE,  /* Cycle counter filtering disabled */
                            [!ENDIF!]
                                [!WS "8"!][!"node:value(FrIfBaseCycle)"!]U, /* Cycle counter filter match value */
                                [!WS "8"!][!"num:inttohex(node:value(FrIfCycleRepetition)-1,2)"!]U, /* Cycle counter filter mask (repetition each [!"node:value(FrIfCycleRepetition)"!] cycles) */
                                [!WS "8"!](boolean)FALSE,  /* Repeat TX todo add*/
                            [!IF "text:tolower(node:value(FrIfAllowDynamicLSduLength))='false'"!]
                                [!WS "8"!](boolean)FALSE,  /* Dynamic payload length disabled */
                            [!ELSE!]
                                [!WS "8"!](boolean)TRUE,   /* Dynamic payload length enabled */
                            [!ENDIF!]
                            [!WS "8"!](boolean)TRUE,   /* Buffer Enabled */
                            [!WS "8"!]{   /* frame header */
                            [!WS "12"!](boolean)FALSE, /* reservedBit */
                            [!WS "12"!](boolean)FALSE, /* payloadPreambleIndicator */
                            [!WS "12"!](boolean)FALSE, /* nullFrameIndicator */
                            [!WS "12"!](boolean)FALSE, /* syncFrameIndicator */
                            [!WS "12"!](boolean)FALSE, /* startupFrameIndicator */
                            [!WS "12"!]0U, /* frameID */
                            [!WS "12"!]0U, /* cycleCount */
                            [!WS "12"!]0U, /* payloadLength */
                            [!WS "12"!]0U, /* headerCrc */
                            [!WS "12"!]0U /* slotStatus */
                            [!WS "8"!]}
                            [!WS "4"!]}[!//
                        [!ENDSELECT!]
                        [!VAR "MacComma" = "','"!]
                    [!ENDIF!][!// Receive and transmit
                [!ENDLOOP!]
                [!WS "0"!][!CR!]
                [!WS "0"!]};
                [!WS "0"!][!CR!]
                [!// Check for empty array and error out.
                [!IF "($reachRxLPdu='false')and($reachTxLPdu='false')"!]
                    [!ERROR!]Error 051: Please check FrIfFrameTriggering and Fr FiFO. For Rx lpduid, at least one FrIfSlotId must not be part of FrFiFo accepted range.[!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDMACRO!]



    [!MACRO "MemorySize", "CfgVariant" = "string('PB')", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = "", "Reconfigurations" = "", "ReconfigurationsDynamic" = ""!]
        [!VAR "MacStaticPayload" = "num:i(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic) * 2"!]
        [!VAR "MacDynamicPayload" = "num:i(node:ref($FrController)/FrPPayloadLengthDynMax) * 2"!]
        [!VAR "NumberOfSlaveShared" = "0"!]
        [!WS "0"!][!// Get numbers of buffers used for reception in static and dynamic segment and numbers of FIFO buffers
        [!LOOP "text:split($Reconfigurations, '#')"!][!// Count the number of slave lpdu shared.
            [!VAR "NumberOfSlaveShared"="$NumberOfSlaveShared + count(text:split(. ,' ')) - 1"!]
        [!ENDLOOP!]
        [!LOOP "node:order(node:ref($FrIfCluster)/FrIfController/*,'node:value(FrIfCtrlIdx)','node:name(.)')"!][!// Sort the controllers by their name at first
            [!IF "$FrController = node:path(node:ref(FrIfFrCtrlRef))"!]
                [!VAR "MacStaticBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacDynamicBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacStaticBuffersCnt" = "$MacStaticBuffersCnt - (count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!][!// Remove reconfigured buffers
                [!VAR "MacDynamicBuffersCnt" = "$MacDynamicBuffersCnt - (count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!][!// Remove reconfigured buffers
                [!VAR "MacFIFOACountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOACountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacCtrlIdx" = "num:i(FrIfCtrlIdx)"!]
                [!WS "0"!][!// Remove FIFO buffers to get correct number of buffers used for individual frame reception
                [!VAR "MacStaticBuffersCnt" = "num:i(($MacStaticBuffersCnt - $MacFIFOACountS) - $MacFIFOBCountS)"!]
                [!VAR "MacDynamicBuffersCnt" = "num:i(($MacDynamicBuffersCnt - $MacFIFOACountD) - $MacFIFOBCountD)"!]
                [!WS "0"!][!// Get number of shadow buffers - check if they are used or not
                [!VAR "MacShadowCount1" = "num:i(0)"!]
                [!VAR "MacShadowCount2" = "num:i(0)"!]
                [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
                    [!IF "number($MacStaticBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount1" = "num:i($MacShadowCount1 + 1)"!]
                    [!ENDIF!]
                    [!IF "number($MacDynamicBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount2" = "num:i($MacShadowCount2 + 1)"!]
                    [!ENDIF!]
                [!ELSE!]
                    [!IF "number($MacStaticBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount1" = "num:i($MacShadowCount1 + 2)"!]
                    [!ENDIF!]
                    [!IF "number($MacDynamicBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount2" = "num:i($MacShadowCount2 + 2)"!]
                    [!ENDIF!]
                [!ENDIF!]
                [!WS "0"!][!// Get payload length for FIFOs - use greater of lengths of segments, where the FIFO is used
                [!IF "$MacFIFOACountS > 0"!]
                    [!VAR "MacFIFOLengthS" = "$MacStaticPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthS" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOACountD > 0"!]
                    [!VAR "MacFIFOLengthD" = "$MacDynamicPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthD" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOLengthD > $MacFIFOLengthS"!]
                    [!VAR "MacFIFOALength" = "$MacFIFOLengthD"!]
                [!ELSE!]
                    [!VAR "MacFIFOALength" = "$MacFIFOLengthS"!]
                [!ENDIF!]
                [!IF "$MacFIFOBCountS > 0"!]
                    [!VAR "MacFIFOLengthS" = "$MacStaticPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthS" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOBCountD > 0"!]
                    [!VAR "MacFIFOLengthD" = "$MacDynamicPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthD" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOLengthD > $MacFIFOLengthS"!]
                    [!VAR "MacFIFOBLength" = "$MacFIFOLengthD"!]
                [!ELSE!]
                    [!VAR "MacFIFOBLength" = "$MacFIFOLengthS"!]
                [!ENDIF!]
                [!VAR "MacFIFOADepth" = "0"!]
                [!VAR "MacFIFOBDepth" = "0"!]
                [!IF "($MacFIFOACountS + $MacFIFOACountD) > 0"!]
                    [!VAR "MacFIFOADepth" = "number(node:ref($FrController)/FrFifo/*[node:value(FrChannels)='FR_CHANNEL_A']/FrFifoDepth)"!]
                [!ENDIF!]
                [!IF "($MacFIFOBCountS + $MacFIFOBCountD) > 0"!]
                    [!VAR "MacFIFOBDepth" = "number(node:ref($FrController)/FrFifo/*[node:value(FrChannels)='FR_CHANNEL_B']/FrFifoDepth)"!]
                [!ENDIF!]
                [!IF "($MacFIFOADepth + $MacFIFOBDepth) > 255"!]
                    [!ERROR!]
                        [!WS "0"!]Error 043: Maximum FIFO depth 255 entries was exceeded!
                    [!ENDERROR!]
                [!ENDIF!]
                [!WS "0"!][!// Compute size of the memory used for buffer headers
                [!VAR "MacHeadersSize" = "num:i(($MacFIFOADepth + $MacFIFOBDepth + $MacShadowCount2 + $MacShadowCount1 + $MacDynamicBuffersCnt + $MacStaticBuffersCnt) * ecu:get('FR.MBHeaderLength'))"!]
                [!WS "0"!][!// Compute how many bytes must be added to headers memory to get address aligned at 2 bytes - memory for data areas
                [!VAR "AllignPad" = "num:i(bit:and(num:i($MacHeadersSize + 1), num:hextoint('0xFFFFFFFE')) - $MacHeadersSize)"!]
                [!WS "0"!][!// Make payloads divisible by 2 to mainatain the buffers alignment
                [!VAR "MacStaticPayload" = "num:i(bit:and(num:i($MacStaticPayload + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
                [!VAR "MacDynamicPayload" = "num:i(bit:and(num:i($MacDynamicPayload + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
                [!VAR "MacFIFOALength" = "num:i(bit:and(num:i($MacFIFOALength + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
                [!VAR "MacFIFOBLength" = "num:i(bit:and(num:i($MacFIFOBLength + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
                [!VAR "SFTOR" = "num:i($MacHeadersSize + $AllignPad + ($MacStaticBuffersCnt * $MacStaticPayload) + ($MacDynamicBuffersCnt * $MacDynamicPayload) + ($MacShadowCount1 * $MacStaticPayload) + ($MacShadowCount2 * $MacDynamicPayload) + ($MacFIFOADepth * $MacFIFOALength) + ($MacFIFOBDepth * $MacFIFOBLength))"!]
                [!IF "(num:i($SFTOR + 240)) > $MemSize"!][!//Select maximum memory size from all multiple configurations for current controller
                    [!VAR "MemSize" = "num:i($SFTOR+ 240)"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDMACRO!]



    [!VAR "NumberOfShadowBuffersUsed" = "num:i(0)"!]
    [!MACRO "BufferCfg", "CfgVariant" = "string('PB')", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = "", "Reconfigurations" = "", "ReconfigurationsDynamic" = ""!]
        [!VAR "A1_MB" = "num:i(0)"!][!// /* initialization of variables*/
        [!VAR "B1_MB" = "num:i(0)"!]
        [!VAR "A2_MB" = "num:i(0)"!]
        [!VAR "B2_MB" = "num:i(0)"!]
        [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
            [!IF "$FrController = node:path(node:ref(FrIfFrCtrlRef))"!]
                [!WS "0"!]/* Receive shadow buffers configuration */
                [!VAR "MacStaticBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacDynamicBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacStaticBuffersCnt" = "$MacStaticBuffersCnt - (count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!]
                [!VAR "MacDynamicBuffersCnt" = "$MacDynamicBuffersCnt - (count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!]
                [!VAR "MacFIFOACountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOACountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacStaticBuffersCnt" = "($MacStaticBuffersCnt - $MacFIFOACountS) - $MacFIFOBCountS"!]
                [!VAR "MacDynamicBuffersCnt" = "($MacDynamicBuffersCnt - $MacFIFOACountD) - $MacFIFOBCountD"!]
                [!VAR "MacRxShadow" = "$MacStaticBuffersCnt + $MacDynamicBuffersCnt - 1"!]
                [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
                    [!WS "0"!][!// Single channel mode - only internal channel A is used so each segment will use only one receive shadow buffer - total 2 buffers
                    [!IF "number($MacStaticBuffersCnt) > 0"!]
                        [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                        [!VAR "A1_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 1 - the initial buffer index */
                        [!VAR "B1_MB" = "num:i(0)"!][!//           /* Ch B, seg 1 - unused*/
                        [!IF "number($MacDynamicBuffersCnt) > 0"!]
                            [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                            [!VAR "A2_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 2 - the initial buffer index */
                            [!VAR "B2_MB" = "num:i(0)"!][!//  /* Ch B, seg 2 - unused */
                        [!ELSE!]
                            [!VAR "A2_MB" = "num:i(0)"!][!//  /* Ch A, seg 2 - unused */
                            [!VAR "B2_MB" = "num:i(0)"!][!//  /* Ch B, seg 2 - unused */
                        [!ENDIF!]
                    [!ELSE!]
                        [!IF "number($MacDynamicBuffersCnt) > 0"!]
                            [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                            [!VAR "A1_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 1 - the initial buffer index */
                            [!VAR "B1_MB" = "num:i(0)"!][!//  /* Ch B, seg 1 - unused */
                            [!VAR "A2_MB" = "num:i(0)"!][!//  /* Ch A, seg 2 - unused */
                            [!VAR "B2_MB" = "num:i(0)"!][!//  /* Ch B, seg 2 - unused */
                        [!ENDIF!]
                    [!ENDIF!]
                [!ELSE!]
                    [!WS "0"!][!// Dual channel mode
                    [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_AB'"!]
                        [!WS "0"!][!// Both channels are used each segment will use both receive shadow buffers - total 4 buffers
                        [!IF "number($MacStaticBuffersCnt) > 0"!]
                            [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                            [!VAR "A1_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 1 - the initial index of the MB header field */
                            [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                            [!VAR "B1_MB" = "num:i($MacRxShadow)"!][!// /* Ch B, seg 1 - the initial index of the MB header field */
                            [!IF "number($MacDynamicBuffersCnt) > 0"!]
                                [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                                [!VAR "A2_MB" = "num:i($MacRxShadow)"!][!//      /* Ch A, seg 2 - the initial index of the MB header field */
                                [!VAR "B2_MB" = "num:i($MacRxShadow + 1)"!][!//  /* Ch B, seg 2 - the initial index of the MB header field */
                            [!ELSE!]
                                [!VAR "A2_MB" = "num:i(0)"!][!// /* Ch A, seg 2 - unused */
                                [!VAR "B2_MB" = "num:i(0)"!][!//  /* Ch B, seg 2 - unused */
                            [!ENDIF!]
                        [!ELSE!]
                            [!IF "number($MacDynamicBuffersCnt) > 0"!]
                                [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                                [!VAR "A1_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 1 - the initial index of the MB header field */
                                [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                                [!VAR "B1_MB" = "num:i($MacRxShadow)"!][!// /* Ch B, seg 1 - the initial index of the MB header field */
                                [!VAR "A2_MB" = "num:i(0)"!][!// /* Ch A, seg 2 - unused */
                                [!VAR "B2_MB" = "num:i(0)"!][!// /* Ch B, seg 2 - unused */
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!IF "number($MacStaticBuffersCnt) > 0"!]
                            [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                            [!VAR "A1_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 1 - [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_A'"!]the initial buffer index[!WS!][!ELSE!]unused[!WS!][!ENDIF!]*/
                            [!VAR "B1_MB" = "num:i($MacRxShadow)"!][!// /* Ch B, seg 1 - [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_B'"!]the initial buffer index[!WS!][!ELSE!]unused[!WS!][!ENDIF!]*/
                            [!IF "number($MacDynamicBuffersCnt) > 0"!]
                                [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                                [!VAR "A2_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 2 - [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_A'"!]the initial buffer index[!WS!][!ELSE!]unused[!WS!][!ENDIF!]*/
                                [!VAR "B2_MB" = "num:i($MacRxShadow)"!][!//  /* Ch B, seg 2 - [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_B'"!]the initial buffer index[!WS!][!ELSE!]unused[!WS!][!ENDIF!]*/
                            [!ELSE!]
                                [!VAR "A2_MB" = "num:i(0)"!][!// /* Ch A, seg 2 - unused */
                                [!VAR "B2_MB" = "num:i(0)"!][!// /* Ch B, seg 2 - unused */
                            [!ENDIF!]
                        [!ELSE!]
                            [!IF "number($MacDynamicBuffersCnt) > 0"!]
                                [!VAR "MacRxShadow" = "$MacRxShadow + 1"!]
                                [!VAR "A1_MB" = "num:i($MacRxShadow)"!][!// /* Ch A, seg 1 - [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_A'"!]the initial buffer index[!WS!][!ELSE!]unused[!WS!][!ENDIF!]*/
                                [!VAR "B1_MB" = "num:i($MacRxShadow)"!][!// /* Ch B, seg 1 - [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_B'"!]the initial buffer index[!WS!][!ELSE!]unused[!WS!][!ENDIF!]*/
                                [!VAR "A2_MB" = "num:i(0)"!][!// /* Ch A, seg 2 - unused */
                                [!VAR "B2_MB" = "num:i(0)"!][!//  /* Ch B, seg 2 - unused */
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!VAR "NumberOfShadowBuffersUsed" ="num:i(0)"!]
            [!IF "num:i($A1_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed" = "$NumberOfShadowBuffersUsed + 1"!]
            [!ENDIF!]
            [!IF "num:i($A2_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed" = "$NumberOfShadowBuffersUsed + 1"!]
            [!ENDIF!]
            [!IF "num:i($B1_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed" = "$NumberOfShadowBuffersUsed + 1"!]
            [!ENDIF!]
            [!IF "num:i($B2_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed" = "$NumberOfShadowBuffersUsed + 1"!]
            [!ENDIF!][!//   /* put comma between shadow buffers if it is not the last shadow buffer (i.e number is not 0 after decrementing) */
            [!VAR "NumberOfShadowBuffersUsed_Copy" = "$NumberOfShadowBuffersUsed"!]
            [!WS "0"!]static Flexray_Ip_ShadowConfigType FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_ShadowConfig_[!"string($CfgVariant)"!][[!"num:i($NumberOfShadowBuffersUsed)"!]U] =
            [!WS "0"!]{
            [!IF "num:i($A1_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed_Copy" = "$NumberOfShadowBuffersUsed_Copy - 1"!]
                [!WS "4"!]{[!"num:i($A1_MB)"!]U, (boolean)TRUE, (boolean)TRUE}[!IF "num:i($NumberOfShadowBuffersUsed_Copy) > 0"!],[!ENDIF!][!"'       /* A1 Shadow Buffer */'"!]
            [!ENDIF!]
            [!IF "num:i($A2_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed_Copy" = "$NumberOfShadowBuffersUsed_Copy - 1"!]
                [!WS "4"!]{[!"num:i($A2_MB)"!]U, (boolean)TRUE, (boolean)FALSE}[!IF "num:i($NumberOfShadowBuffersUsed_Copy) > 0"!],[!ENDIF!][!"'      /* A2 Shadow Buffer */'"!]
            [!ENDIF!]
            [!IF "num:i($B1_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed_Copy" = "$NumberOfShadowBuffersUsed_Copy - 1"!]
                [!WS "4"!]{[!"num:i($B1_MB)"!]U, (boolean)FALSE, (boolean)TRUE}[!IF "num:i($NumberOfShadowBuffersUsed_Copy) > 0"!],[!ENDIF!][!"'      /* B1 Shadow Buffer */'"!]
            [!ENDIF!]
            [!IF "num:i($B2_MB) > 0"!]
                [!VAR "NumberOfShadowBuffersUsed_Copy" = "$NumberOfShadowBuffersUsed_Copy - 1"!]
                [!WS "4"!]{[!"num:i($B2_MB)"!]U, (boolean)FALSE, (boolean)FALSE}[!IF "num:i($NumberOfShadowBuffersUsed_Copy) > 0"!],[!ENDIF!][!"'      /* B2 Shadow Buffer */'"!]
            [!ENDIF!]
            [!WS "0"!]};
            [!CR!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDMACRO!]



    [!MACRO "FifoCfg", "CfgVariant" = "string('PB')", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = "", "Reconfigurations" = "", "ReconfigurationsDynamic" = ""!]
        [!VAR "MacStaticPayload" = "num:i(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic * 2)"!]
        [!VAR "MacDynamicPayload" = "num:i(node:ref($FrController)/FrPPayloadLengthDynMax * 2)"!]
        [!WS "0"!][!// Get numbers of buffers used for reception in static and dynamic segment and numbers of FIFO buffers
        [!VAR "Fifo_A_Exists" ="'false'"!]
        [!VAR "Fifo_B_Exists" ="'false'"!]
        [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
            [!IF "$FrController = node:path(node:ref(FrIfFrCtrlRef))"!]
                [!VAR "MacStaticBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacDynamicBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacStaticBuffersCnt" = "$MacStaticBuffersCnt - (count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!][!// Remove reconfigured buffers
                [!VAR "MacDynamicBuffersCnt" = "$MacDynamicBuffersCnt - (count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!][!// Remove reconfigured buffers
                [!VAR "MacFIFOACountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOACountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacCtrlIdx" = "num:i(FrIfCtrlIdx)"!]
                [!WS "0"!][!// Remove FIFO buffers to get correct number of buffers used for individual frame reception
                [!VAR "MacStaticBuffersCnt" = "num:i(($MacStaticBuffersCnt - $MacFIFOACountS) - $MacFIFOBCountS)"!]
                [!VAR "MacDynamicBuffersCnt" = "num:i(($MacDynamicBuffersCnt - $MacFIFOACountD) - $MacFIFOBCountD)"!]
                [!WS "0"!][!// Get number of shadow buffers - check if they are used or not
                [!VAR "MacShadowCount1" = "num:i(0)"!]
                [!VAR "MacShadowCount2" = "num:i(0)"!]
                [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
                    [!IF "number($MacStaticBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount1" = "num:i($MacShadowCount1 + 1)"!]
                    [!ENDIF!]
                    [!IF "number($MacDynamicBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount2" = "num:i($MacShadowCount2 + 1)"!]
                    [!ENDIF!]
                [!ELSE!]
                    [!IF "number($MacStaticBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount1" = "num:i($MacShadowCount1 + 2)"!]
                    [!ENDIF!]
                    [!IF "number($MacDynamicBuffersCnt) > 0"!]
                        [!VAR "MacShadowCount2" = "num:i($MacShadowCount2 + 2)"!]
                    [!ENDIF!]
                [!ENDIF!]
                [!WS "0"!][!// Get payload length for FIFOs - use grater of lengths of segments, where the FIFO is used
                [!IF "$MacFIFOACountS > 0"!]
                    [!VAR "MacFIFOLengthS" = "$MacStaticPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthS" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOACountD > 0"!]
                    [!VAR "MacFIFOLengthD" = "$MacDynamicPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthD" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOLengthD > $MacFIFOLengthS"!]
                    [!VAR "MacFIFOALength" = "$MacFIFOLengthD"!]
                [!ELSE!]
                    [!VAR "MacFIFOALength" = "$MacFIFOLengthS"!]
                [!ENDIF!]
                [!IF "$MacFIFOBCountS > 0"!]
                    [!VAR "MacFIFOLengthS" = "$MacStaticPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthS" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOBCountD > 0"!]
                    [!VAR "MacFIFOLengthD" = "$MacDynamicPayload"!]
                [!ELSE!]
                    [!VAR "MacFIFOLengthD" = "0"!]
                [!ENDIF!]
                [!IF "$MacFIFOLengthD > $MacFIFOLengthS"!]
                    [!VAR "MacFIFOBLength" = "$MacFIFOLengthD"!]
                [!ELSE!]
                    [!VAR "MacFIFOBLength" = "$MacFIFOLengthS"!]
                [!ENDIF!]
                [!VAR "MacFifoBeginning" = "$MacStaticBuffersCnt + $MacDynamicBuffersCnt + $MacShadowCount1 + $MacShadowCount2"!]
                [!IF "($MacFIFOACountS + $MacFIFOACountD) > 0"!]
                    [!SELECT "node:ref($FrIfCluster)/../.."!]
                        [!VAR "FrIfConfigIndex" = "position()"!]
                    [!ENDSELECT!]
                    [!WS "0"!]/* This structure contains configuration of the receive FIFO for the channel A */
                    [!WS "0"!]static Flexray_Ip_FifoConfigType [!//
                        [!WS "0"!]FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_FIFOA_Cfg_[!"string($CfgVariant)"!] =
                    [!WS "0"!]{
                    [!SELECT "node:ref($FrController)/FrFifo/*[node:value(FrChannels)='FR_CHANNEL_A']"!]
                        [!WS "4"!]FLEXRAY_RECEIVE_FIFOA, /* FIFO receives messages from the channel A */
                        [!WS "4"!][!"num:i($MacFifoBeginning)"!]U, /* The first FIFO message buffer */
                        [!VAR "MacFifoBeginning" = "$MacFifoBeginning + num:i(FrFifoDepth)"!]
                        [!WS "4"!][!"num:i(FrFifoDepth)"!]U, /* The number of FIFO message buffers */
                        [!WS "4"!][!"num:i(($MacFIFOALength + 1) div 2)"!]U, /* Length of the data received into the FIFO */
                        [!WS "4"!]0x7FFU, /* Frame ID filter mask */
                        [!WS "4"!]0x0U, /* Frame ID filter match */
                        [!WS "4"!][!"num:i(FrMsgIdMask)"!]U, /* Message ID filter mask[!//
                        [!IF "number(FrMsgIdMask) = 0"!]
                            [!WS "0"!] - message ID filtering disabled */
                        [!ELSE!]
                            [!WS "0"!] - message ID filtering enabled */
                        [!ENDIF!]
                        [!WS "4"!][!"num:i(FrMsgIdMatch)"!]U, /* Message ID filter match */
                        [!WS "4"!]{ /* FIFO A Range filters configuration */
                        [!IF "count(FrRange/*[position()=1]) = 1"!]
                            [!SELECT "FrRange/*[position()=1]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U},
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                        [!IF "count(FrRange/*[position()=2]) = 1"!]
                            [!SELECT "FrRange/*[position()=2]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U},
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                        [!IF "count(FrRange/*[position()=3]) = 1"!]
                            [!SELECT "FrRange/*[position()=3]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U},
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                        [!IF "count(FrRange/*[position()=4]) = 1"!]
                            [!SELECT "FrRange/*[position()=4]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U}
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U} /* Range filter disabled */
                        [!ENDIF!]
                    [!ENDSELECT!]
                    [!WS "4"!]},
                    [!WS "4"!]0U /* Frame ID filter match FrFifoWatermark */
                    [!WS "0"!]};
                    [!CR!]
                    [!VAR "Fifo_A_Exists" ="'true'"!]
                [!ENDIF!]
                [!IF "($MacFIFOBCountS + $MacFIFOBCountD) > 0"!]
                    [!SELECT "node:ref($FrIfCluster)/../.."!]
                        [!VAR "FrIfConfigIndex" = "position()"!]
                    [!ENDSELECT!]
                    [!WS "0"!]/* This structure contains configuration of the receive FIFO for the channel B */
                    [!WS "0"!]static Flexray_Ip_FifoConfigType [!//
                        [!WS "0"!]FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_FIFOB_Cfg_[!"string($CfgVariant)"!] =
                    [!WS "0"!]{
                    [!SELECT "node:ref($FrController)/FrFifo/*[node:value(FrChannels)='FR_CHANNEL_B']"!]
                        [!WS "4"!]FLEXRAY_RECEIVE_FIFOB, /* FIFO receives messages from the channel B */
                        [!WS "4"!][!"num:i($MacFifoBeginning)"!]U, /* The first FIFO message buffer */
                        [!VAR "MacFifoBeginning" = "$MacFifoBeginning + num:i(FrFifoDepth)"!]
                        [!WS "4"!][!"num:i(FrFifoDepth)"!]U, /* The number of FIFO message buffers */
                        [!WS "4"!][!"num:i(($MacFIFOBLength + 1) div 2)"!]U, /* Length of the data received into the FIFO */
                        [!WS "4"!]0x7FFU, /* Frame ID filter mask*/
                        [!WS "4"!]0x0U, /* Frame ID filter match */
                        [!WS "4"!][!"num:i(FrMsgIdMask)"!]U, /* Message ID filter mask[!//
                        [!IF "0 = number(FrMsgIdMask)"!]
                            [!WS "0"!] - message ID filtering disabled */
                        [!ELSE!]
                            [!WS "0"!] - message ID filtering enabled */
                        [!ENDIF!]
                        [!WS "4"!][!"num:i(FrMsgIdMatch)"!]U, /* Message ID filter match */
                        [!WS "4"!]{ /* FIFO B Range filters configuration */
                        [!IF "count(FrRange/*[position()=1]) = 1"!]
                            [!SELECT "FrRange/*[position()=1]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U},
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                        [!IF "count(FrRange/*[position()=2]) = 1"!]
                            [!SELECT "FrRange/*[position()=2]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U},
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                        [!IF "count(FrRange/*[position()=3]) = 1"!]
                            [!SELECT "FrRange/*[position()=3]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U},
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                        [!IF "count(FrRange/*[position()=4]) = 1"!]
                            [!SELECT "FrRange/*[position()=4]"!]
                                [!WS "8"!]{(boolean)TRUE, [!"node:value(FrVendorSpecific/FrRangeMode)"!], [!"num:i(FrRangeMin)"!]U, [!"num:i(FrRangeMax)"!]U}
                            [!ENDSELECT!]
                        [!ELSE!]
                            [!WS "8"!]{(boolean)FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
                        [!ENDIF!]
                    [!ENDSELECT!]
                    [!WS "4"!]},
                    [!WS "4"!]0U /* Frame ID filter match FrFifoWatermark */
                    [!WS "0"!]};
                    [!CR!]
                    [!VAR "Fifo_B_Exists" ="'true'"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDMACRO!]



    [!MACRO "HWConfig", "CfgIdx" = "0", "CfgVariant" = "", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = "",  "Reconfigurations" = "", "ReconfigurationsDynamic" = ""!]
        [!WS "0"!]/* Structure of this type contains configuration
        [!WS "0"!] * information of one hardware parameters configuration set */
        [!WS "0"!]static Flexray_Ip_CcConfigType FrMC[!"num:i($CfgIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_CCCfgSet_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
            [!WS "4"!](boolean)FALSE, /* temporary for freezeMode */
            [!WS "4"!](boolean)[!"text:toupper(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))"!], /* Single Channel Device mode */
        [!IF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_AB'"!]
            [!WS "4"!](boolean)TRUE,     /* Channel A */
            [!WS "4"!](boolean)TRUE,     /* Channel B */
        [!ELSEIF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_A'"!]
            [!WS "4"!](boolean)TRUE,     /* Channel A */
            [!WS "4"!](boolean)FALSE,    /* Channel B */
        [!ELSEIF "node:value(node:ref($FrController)/FrPChannels) = 'FR_CHANNEL_B'"!]
            [!WS "4"!](boolean)FALSE,    /* Channel A */
            [!WS "4"!](boolean)TRUE,     /* Channel B */
        [!ELSE!]
            [!WS "4"!](boolean)TRUE,     /* Channel A */
            [!WS "4"!](boolean)FALSE,    /* Channel B */
        [!ENDIF!]
            [!WS "4"!](boolean)FALSE, /* temporary for syncFrameFilter */
        [!IF "ecu:get('FR.FrSelectClockSource') = 'true'"!] /* currently not supported by MCAL*/
            [!WS "4"!][!"node:value(node:ref($FrController)/VendorSpecific/ClockSource)"!], /* FlexRay protocol engine clock source */
        [!ENDIF!]
        [!IF "node:value(node:ref($FrController)/VendorSpecific/ChannelBitrate)='br_10Mbps'"!]
            [!WS "4"!]FLEXRAY_BITRATE_10,    /* Bus speed: 10 Mb/s */
        [!ELSEIF "node:value(node:ref($FrController)/VendorSpecific/ChannelBitrate)='br_5Mbps'"!]
            [!WS "4"!]FLEXRAY_BITRATE_5,     /* Bus speed:  5 Mb/s */
        [!ELSEIF "node:value(node:ref($FrController)/VendorSpecific/ChannelBitrate)='br_2500kbps'"!]
            [!WS "4"!]FLEXRAY_BITRATE_2_5,   /* Bus speed:  2500 kb/s */
        [!ELSEIF "node:value(node:ref($FrController)/VendorSpecific/ChannelBitrate)='br_8000kbps'"!]
            [!WS "4"!]FLEXRAY_BITRATE_8,     /* Bus speed:  8000 kb/s */
        [!ELSE!]
            [!WS "4"!]FLEXRAY_BITRATE_10,    /* Bus speed: 10 Mb/s (defaulted)*/
        [!ENDIF!]
            [!WS "4"!]FLEXRAY_MEM_LAYOUT_MIXED, /* temporary for mem_layout*/
            [!WS "4"!][!"num:i(node:ref($FrController)/VendorSpecific/SystemMemoryAccessTimeOut)"!]U, /* System memory access timeout */
            [!WS "4"!]Fr_MemoryArea_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], /* FlexRay memory base address */
            [!WS "4"!]NULL_PTR  /* dedicated memory layout support memory pointer */
        [!WS "0"!]};
        [!CR!]
    [!ENDMACRO!]



    [!MACRO "PSRRegisters", "CfgIdx" = "0", "CfgVariant" = "", "FrIfCluster" = "", "FrController" = ""!][!// this code snippet will compute keyslot header crc
        [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)"!]
            [!VAR "KeySlotStartup"="1"!]
        [!ELSE!]
            [!VAR "KeySlotStartup"="0"!]
        [!ENDIF!]
        [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForSync)"!]
            [!VAR "KeySlotSync"="1"!]
        [!ELSE!]
            [!VAR "KeySlotSync"="0"!]
        [!ENDIF!]
        [!VAR "KSHCRC" = "node:value(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic)"!]
        [!IF "number(node:ref($FrController)/FrPKeySlotId) > 0"!]
            [!CALL "CrcCalculation", "Sync" = "number($KeySlotSync)", "Startup" = "number($KeySlotStartup)", "FrameId" = "number(node:ref($FrController)/FrPKeySlotId)", "PayloadLengthW" = "$KSHCRC", "OutCrc"="1"!]
            [!VAR "KSHCRC" = "num:inttohex(bit:and(number($OutCrc),2047))"!]
        [!ELSE!]
            [!VAR "KSHCRC" = "num:i(0)"!]
        [!ENDIF!][!// this code snipper will compute SFTOR value
        [!VAR "MacStaticPayload" = "num:i(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic * 2)"!]
        [!VAR "MacDynamicPayload" = "num:i(node:ref($FrController)/FrPPayloadLengthDynMax * 2)"!]
        [!WS "0"!][!// Get numbers of buffers used for reception in static and dynamic segment and numbers of FIFO buffers
        [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
            [!VAR "MacStaticBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
            [!VAR "MacDynamicBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
            [!VAR "MacStaticBuffersCnt" = "$MacStaticBuffersCnt - (count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!][!// Remove reconfigured buffers
            [!VAR "MacDynamicBuffersCnt" = "$MacDynamicBuffersCnt - (count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!][!// Remove reconfigured buffers
            [!VAR "MacFIFOACountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
            [!VAR "MacFIFOBCountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
            [!VAR "MacFIFOACountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
            [!VAR "MacFIFOBCountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
        [!ENDSELECT!]
        [!WS "0"!][!// Remove FIFO buffers to get correct number of buffers used for individual frame reception
        [!VAR "MacStaticBuffersCnt" = "num:i(($MacStaticBuffersCnt - $MacFIFOACountS) - $MacFIFOBCountS)"!]
        [!VAR "MacDynamicBuffersCnt" = "num:i(($MacDynamicBuffersCnt - $MacFIFOACountD) - $MacFIFOBCountD)"!]
        [!WS "0"!][!// Get number of shadow buffers - check if they are used or not
        [!VAR "MacShadowCount1" = "num:i(0)"!]
        [!VAR "MacShadowCount2" = "num:i(0)"!]
        [!IF "text:tolower(node:value(node:ref($FrController)/VendorSpecific/SingleChannelModeEnabled))='true'"!]
            [!IF "number($MacStaticBuffersCnt) > 0"!]
                [!VAR "MacShadowCount1" = "num:i($MacShadowCount1 + 1)"!]
            [!ENDIF!]
            [!IF "number($MacDynamicBuffersCnt) > 0"!]
                [!VAR "MacShadowCount2" = "num:i($MacShadowCount2 + 1)"!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "number($MacStaticBuffersCnt) > 0"!]
                [!VAR "MacShadowCount1" = "num:i($MacShadowCount1 + 2)"!]
            [!ENDIF!]
            [!IF "number($MacDynamicBuffersCnt) > 0"!]
                [!VAR "MacShadowCount2" = "num:i($MacShadowCount2 + 2)"!]
            [!ENDIF!]
        [!ENDIF!]
        [!WS "0"!][!// Get payload length for FIFOs - use greater of lengths of segments, where the FIFO is used
        [!IF "$MacFIFOACountS > 0"!]
            [!VAR "MacFIFOLengthS" = "$MacStaticPayload"!]
        [!ELSE!]
            [!VAR "MacFIFOLengthS" = "0"!]
        [!ENDIF!]
        [!IF "$MacFIFOACountD > 0"!]
            [!VAR "MacFIFOLengthD" = "$MacDynamicPayload"!]
        [!ELSE!]
            [!VAR "MacFIFOLengthD" = "0"!]
        [!ENDIF!]
        [!IF "$MacFIFOLengthD > $MacFIFOLengthS"!]
            [!VAR "MacFIFOALength" = "$MacFIFOLengthD"!]
        [!ELSE!]
            [!VAR "MacFIFOALength" = "$MacFIFOLengthS"!]
        [!ENDIF!]
        [!IF "$MacFIFOBCountS > 0"!]
            [!VAR "MacFIFOLengthS" = "$MacStaticPayload"!]
        [!ELSE!]
            [!VAR "MacFIFOLengthS" = "0"!]
        [!ENDIF!]
        [!IF "$MacFIFOBCountD > 0"!]
            [!VAR "MacFIFOLengthD" = "$MacDynamicPayload"!]
        [!ELSE!]
            [!VAR "MacFIFOLengthD" = "0"!]
        [!ENDIF!]
        [!IF "$MacFIFOLengthD > $MacFIFOLengthS"!]
            [!VAR "MacFIFOBLength" = "$MacFIFOLengthD"!]
        [!ELSE!]
            [!VAR "MacFIFOBLength" = "$MacFIFOLengthS"!]
        [!ENDIF!]
        [!VAR "MacFIFOALength" = "num:i(bit:and(num:i($MacFIFOALength + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
        [!VAR "MacFIFOBLength" = "num:i(bit:and(num:i($MacFIFOBLength + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
        [!VAR "MacStaticPayload" = "num:i(bit:and(num:i($MacStaticPayload + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
        [!VAR "MacDynamicPayload" = "num:i(bit:and(num:i($MacDynamicPayload + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
        [!VAR "MacFIFOADepth" = "0"!]
        [!VAR "MacFIFOBDepth" = "0"!]
        [!IF "($MacFIFOACountS + $MacFIFOACountD) > 0"!]
            [!VAR "MacFIFOADepth" = "number(node:ref($FrController)/FrFifo/*[node:value(FrChannels)='FR_CHANNEL_A']/FrFifoDepth)"!]
        [!ENDIF!]
        [!IF "($MacFIFOBCountS + $MacFIFOBCountD) > 0"!]
            [!VAR "MacFIFOBDepth" = "number(node:ref($FrController)/FrFifo/*[node:value(FrChannels)='FR_CHANNEL_B']/FrFifoDepth)"!]
        [!ENDIF!]
        [!VAR "MacSFTBeginning" = "($MacStaticBuffersCnt + $MacDynamicBuffersCnt + $MacShadowCount1 + $MacShadowCount2 + $MacFIFOBDepth + $MacFIFOADepth) * ecu:get('FR.MBHeaderLength')"!]
        [!VAR "MacSFTBeginning" = "num:i(bit:and(num:i($MacSFTBeginning + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
        [!VAR "MacSFTBeginning" = "$MacSFTBeginning + ($MacStaticBuffersCnt * $MacStaticPayload) + ($MacDynamicBuffersCnt * $MacDynamicPayload) + ($MacShadowCount1 * $MacStaticPayload) + ($MacShadowCount2 * $MacDynamicPayload) + ($MacFIFOADepth * $MacFIFOALength) + ($MacFIFOBDepth * $MacFIFOBLength)"!]
        [!WS "0"!][!//
        [!WS "0"!]/* This field contains FlexRay Protocol configuration
        [!WS "0"!] * parameters returned by the Fr_ReadCCConfig function */
        [!WS "0"!]static Flexray_Ip_PeConfigType FrMC[!"num:i($CfgIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_PeConfig_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGColdStartAttempts)"!]U, /* gColdstartAttempts */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdActionPointOffset)"!]U, /* gdActionPointOffset */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdCasRxLowMax)"!]U, /* gdCASRxLowMax */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdDynamicSlotIdlePhase)"!]U, /* gdDynamicSlotIdlePhase */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdMinislot)"!]U, /* gdMinislot */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdMiniSlotActionPointOffset)"!]U, /* gdMinislotActionPointOffset */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdStaticSlot)"!]U, /* gdStaticSlot */
            [!WS "4"!][!IF "num:i(node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindow)) = 0"!](boolean)FALSE[!ELSE!](boolean)TRUE[!ENDIF!], /* gSymbolWindowExists */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindow)"!]U, /* gdSymbolWindow */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdTSSTransmitter)"!]U, /* gdTSSTransmitter */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxIdle)"!]U, /* gdWakeupSymbolRxIdle */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxLow)"!]U, /* gdWakeupSymbolRxLow */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxWindow)"!]U, /* new fr standard maps to gdWakeupRxWindow instead of gdWakeupSymbolRxWindow */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxIdle)"!]U, /* new fr standard maps to gdWakeupTxIdle instead of gdWakeupSymbolTxIdle */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxActive)"!]U, /* new fr standard maps to gdWakeupTxActive instead of gdWakeupSymbolTxLow */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGListenNoise)"!]U, /* gListenNoise */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle)"!]U, /* gMacroPerCycle */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectFatal)"!]U, /* gMaxWithoutClockCorrectionFatal */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectPassive)"!]U, /* gMaxWithoutClockCorrectionPassive */
            [!WS "4"!][!IF "num:i(node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)) = 0"!](boolean)FALSE[!ELSE!](boolean)TRUE[!ENDIF!], /* gMiniSlotExists */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)"!]U, /* gNumberOfMinislots */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!]U, /* gNumberOfStaticSlots */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPOffsetCorrectionStart)"!]U, /* gOffsetCorrectionStart */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic)"!]U, /* gPayloadLengthStatic */
            [!WS "4"!][!"node:value(node:ref($FrIfCluster)/FrIfGSyncFrameIDCountMax)"!]U, /* new fr standard maps to gSyncFrameIDCountMax instead of gSyncNodeMax */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPdListenTimeout)"!]U, /* pdListenTimeout */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPMacroInitialOffsetA)"!]U, /* pMacroInitialOffsetA */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPMacroInitialOffsetB)"!]U, /* pMacroInitialOffsetB */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPPayloadLengthDynMax)"!]U, /* pPayloadLengthDynMax */
            [!WS "4"!](boolean)[!"text:toupper(node:value(node:ref($FrController)/FrPAllowHaltDueToClock))"!], /* pAllowHaltDueToClock */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPAllowPassiveToActive)"!]U, /* pAllowPassiveToActive */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPClusterDriftDamping)"!]U, /* pClusterDriftDamping */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPdAcceptedStartupRange)"!]U, /* pdAcceptedStartupRange */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPDelayCompensationA)"!]U, /* pDelayCompensationA */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPDelayCompensationB)"!]U, /* pDelayCompensationB */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPKeySlotId)"!]U, /* pKeySlotId */
            [!WS "4"!](boolean)[!"text:toupper(node:value(node:ref($FrController)/FrPKeySlotUsedForStartup))"!], /* pKeySlotUsedForStartup */
            [!WS "4"!](boolean)[!"text:toupper(node:value(node:ref($FrController)/FrPKeySlotUsedForSync))"!], /* pKeySlotUsedForSync */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPLatestTx)"!]U, /* pLatestTx */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPMicroInitialOffsetA)"!]U, /* pMicroInitialOffsetA */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPMicroInitialOffsetB)"!]U, /* pMicroInitialOffsetB */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPMicroPerCycle)"!]U, /* pMicroPerCycle */
            [!WS "4"!][!"num:i(ceiling(number(node:value(node:ref($FrController)/FrPMicroPerCycle))*2*0.0015 div(1-0.0015)))"!]U, /* pdMaxDrift */
            [!VAR "pMicroPerMacroNomVar" = "num:i(((node:value(node:ref($FrController)/FrPMicroPerCycle)) div (node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle))))"!]
            [!IF "$pMicroPerMacroNomVar > 255"!]
                [!ERROR!]
                    [!WS "0"!]Error 052: division of FrController/FrPMicroPerCycle to FrIfCluster/FrIfGMacroPerCycle yields a value over 255
                [!ENDERROR!]
            [!ELSE!]
                [!WS "4"!][!"$pMicroPerMacroNomVar"!]U,  /* uint8 pMicroPerMacroNom */
            [!ENDIF!]
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPRateCorrectionOut)"!]U, /* pRateCorrectionOut */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPOffsetCorrectionOut)"!]U, /* pOffsetCorrectionOut */
            [!WS "4"!](boolean)[!"text:toupper(node:value(node:ref($FrController)/FrPKeySlotOnlyEnabled))"!], /* pSingleSlotEnabled */
            [!WS "4"!][!IF "node:value(node:ref($FrController)/FrPWakeupChannel) = 'FR_CHANNEL_A'"!](boolean)FALSE[!ELSE!](boolean)TRUE[!ENDIF!], /* pWakeupChannel */[!CR!]
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPWakeupPattern)"!]U, /* pWakeupPattern */
            [!WS "4"!][!"node:value(node:ref($FrController)/FrPDecodingCorrection)"!]U, /* pExternOffsetCorrection */
            [!WS "4"!][!"$KSHCRC"!]U, /* keySlotHeaderCrc */
            [!WS "4"!]0U, /* pExternOffsetCorrection is no longer supported, used value 0 */
            [!WS "4"!]0U, /* pExternRateCorrection is no longer supported, used value 0 */
            [!WS "4"!][!"num:i(number(node:ref($FrIfCluster)/FrIfGNetworkManagementVectorLength))"!]U, /* gNetworkManagementVectorLength */
            [!WS "4"!][!"num:i($MacSFTBeginning)"!]U /* SyncFrameTableOffset */
        [!WS "0"!]};
        [!WS "0"!][!CR!]
    [!ENDMACRO!]

[!ENDNOCODE!]
[!CODE!]
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
*  @file Flexray_Ip_PBcfg.c
*
*  @addtogroup flexray_ip FlexRay IPL
*  @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexray_Ip_Cfg.h"
#include "Flexray_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                       43
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C                4
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C                0
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip_Cfg.h header file are of the same vendor */
#if(FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != FLEXRAY_IP_CFG_VENDOR_ID)
    #error "Flexray_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Flexray_Ip_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_Cfg.h header file are of the same Autosar version */
#if((FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Flexray_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexray_Ip_Cfg.h header file are of the same software version */
#if((FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != FLEXRAY_IP_CFG_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != FLEXRAY_IP_CFG_SW_MINOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != FLEXRAY_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Flexray_Ip_Cfg.h are different"
#endif

/* Check if current file and Flexray_Ip_Types.h header file are of the same vendor */
#if(FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != FLEXRAY_IP_TYPES_VENDOR_ID)
    #error "Flexray_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Flexray_Ip_Types.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_Types.h header file are of the same Autosar version */
#if((FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Flexray_Ip_Types.h are different"
#endif
/* Check if current file and Flexray_Ip_Types.h header file are of the same software version */
#if((FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != FLEXRAY_IP_TYPES_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != FLEXRAY_IP_TYPES_SW_MINOR_VERSION) || \
    (FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != FLEXRAY_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Flexray_Ip_Types.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
[!WS "0"!][!//-------------------------------------------------------------------------
[!WS "0"!][!//                        MAIN GENERATION SCRIPT
[!WS "0"!][!//-------------------------------------------------------------------------
#define FR_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Fr_MemMap.h"
[!WS "0"!][!//
[!VAR "CtrlNum" = "num:i('0')"!][!//Stores max number of CC which wre configured for all multpile configurations
[!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!][!//Sort the multiple configurations by their name at first
    [!IF "count(FrController/*) > $CtrlNum"!]
        [!VAR "CtrlNum" = "count(FrController/*)"!][!//Find multiple configuration wit max. number of configured CC
    [!ENDIF!]
[!ENDLOOP!]
[!VAR "MultipleCfgNum" = "count(FrMultipleConfiguration)"!]

/* Make the variable properly aligned */
[!FOR "i" = "1" TO "$CtrlNum"!]
    [!VAR "MemSize" = "num:i('0')"!]
    [!WS "0"!]/* FrCtrlIdx = [!"node:value(FrMultipleConfiguration/FrController/*[num:i($i)]/FrCtrlIdx)"!] */
    [!FOR "j" = "1" TO "$MultipleCfgNum"!]
        [!SELECT "FrMultipleConfiguration/FrController/*[num:i($i)]"!]
            [!VAR "FrCtrlPath" = "node:path(.)"!]
            [!LOOP "node:order(as:modconf('FrIf')[1]/FrIfConfig,'node:name(.)')"!][!// Sort multiple configurations by their name at first
                [!LOOP "node:order(FrIfCluster/*,'node:name(.)')"!][!// Sort the clusters by their name at first
                    [!LOOP "node:order(FrIfController/*,'node:value(FrIfCtrlIdx)','node:name(.)')"!][!//Go through all controllers in the cluster to find whether it is the current Fr controller
                        [!IF "$FrCtrlPath = node:path(node:ref(FrIfFrCtrlRef))"!][!//Check reference from FrIf matched Fr controller index
                            [!VAR "FrControllersUsage" = "node:path(.)"!]
                            [!VAR "FrControllersCluster" = "node:path(node:ref($FrControllersUsage)/../..)"!]
                            [!VAR "FrFrIfCtrlReference" = "node:path(node:ref(FrIfFrCtrlRef))"!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDLOOP!]
            [!ENDLOOP!]
            [!IF "$FrCtrlPath = $FrFrIfCtrlReference"!]
                [!IF "FSL_FR_RECONFIG:Reconfig( node:ref($FrControllersUsage)/FrIfLPdu, 4, 0, string(FrCtrlIdx), string(""))='true'"!][!ENDIF!]
                [!VAR "Reconfigurations" = "FSL_FR_RECONFIG:GetReconfigString()"!][!// Get result string of reconfiguration
                [!VAR "ReconfigurationsDynamic" = "string('')"!][!// Get result string of reconfiguration dynamic segment
                [!CALL "RxFIFOSlots", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "OutFIFOASlots" = "string('')", "OutFIFOBSlots" = "string('')"!]
                [!CALL "MemorySize", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots", "Reconfigurations" = "$Reconfigurations", "ReconfigurationsDynamic" = "$ReconfigurationsDynamic"!]
                [!WS "0"!]/* Memory size for [!"as:name(../..)"!] and [!"node:name(.)"!] is [!"(num:i($SFTOR + 240))"!] Bytes */
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]
    [!WS "0"!]ALIGNED_VARS_START(dummy_section, 16U)
    [!WS "0"!]/* Compiler_Warning: We only need aligned start address of array to make sure address of flexray memory  area starts at a 16 byte boundary, don't need aligned all elements of array.*/
    [!WS "0"!]VAR_ALIGN(uint8 Fr_MemoryArea_Ctrl[!"node:value(FrMultipleConfiguration/FrController/*[num:i($i)]/FrCtrlIdx)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"$MemSize"!]], 16U)
    [!WS "0"!]ALIGNED_VARS_STOP()
    [!WS "0"!][!CR!]
[!ENDFOR!]
#define FR_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_MemMap.h"
[!WS "0"!][!//
[!VAR "CtrlNum" = "num:i('0')"!]
[!IF "node:value(FrGeneral/FrNumCtrlSupported) > (ecu:get('FR.AvailableControllers'))"!]
    [!ERROR!]
        [!WS "0"!]Error 050: Too many controllers are required to be supported at [!"node:path(FrGeneral/FrNumCtrlSupported)"!] by the driver. Driver will support maximum [!"num:i(ecu:get('FR.AvailableControllers'))"!] FlexRay [!IF "num:i(ecu:get('FR.AvailableControllers')) > 1"!]controllers available on the hardware[!ELSE!]controller available on the hardware[!ENDIF!].
    [!ENDERROR!]
[!ENDIF!]
[!WS "0"!][!//
[!WS "0"!][!// Go through all Fr multiple configurations
[!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!][!//Sort the multiple configurations by their name at first
    [!CR!]
    [!VAR "FrConfigName" = "as:name(.)"!][!//Store the name of Fr controller multiple configuration
    [!VAR "FrConfigIdx" = "position()"!][!//Store the index of Fr controller multiple configuration
    [!IF "ecu:get('FR.AvailableControllers') < count(FrController/*)"!]
        [!ERROR!]
            [!WS "0"!]Error 048: Too many controllers were configured for [!"node:path(.)"!] multiple configuration. Hardware device supports maximum [!"num:i(ecu:get('FR.AvailableControllers'))"!] FlexRay [!IF "num:i(ecu:get('FR.AvailableControllers')) > 1"!]controllers[!ELSE!]controller[!ENDIF!].
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "node:value(../FrGeneral/FrNumCtrlSupported) < count(FrController/*)"!]
        [!ERROR!]
            [!WS "0"!]Error 049: Too many controllers were configured for [!"node:path(.)"!] multiple configuration. Driver is configured to support [!"node:value(../FrGeneral/FrNumCtrlSupported)"!] FlexRay [!IF "node:value(../FrGeneral/FrNumCtrlSupported) > 1"!]controllers[!ELSE!]controller[!ENDIF!].
        [!ENDERROR!]
    [!ENDIF!]
    [!WS "0"!][!// Go through all controllers in the Fr multiple configuration
    [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
        [!NOCODE!]
            [!IF "text:tolower(text:uniq(../*/FrCtrlIdx, FrCtrlIdx)) = 'false'"!][!// Check FrCtrlIdx is unique
                [!ERROR!]
                    [!WS "0"!]Error 044: [!"node:path(.)"!]/FrCtrlIdx is not unique within [!"node:path(../..)"!].
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "text:tolower(text:uniq(../*/VendorSpecific/CCBaseAddress, VendorSpecific/CCBaseAddress)) = 'false'"!]
                [!WARNING!]
                    [!WS "0"!]Warning 313: CCBaseAddress [!"num:inttohex(node:value(VendorSpecific/CCBaseAddress))"!] is not unique within one multiple configuration for the following controller [!"node:path(.)"!].
                [!ENDWARNING!]
            [!ENDIF!]
            [!IF "$CtrlNum < count(../*)"!]
                [!VAR "CtrlNum" = "count(../*)"!]
            [!ENDIF!]
            [!VAR "FrCtrlName" = "node:name(.)"!][!//Store the name of Fr controller for future usage
            [!VAR "FrCtrlPath" = "node:path(.)"!][!//Store the path to the Fr controller for future comparisons
            [!// Clear counter of controller references from the FrIf - the controller must not be referenced from more than one FrIf cluster
            [!// because then it is not clear which of them contains the configuration parameters to be used (they can be different)
            [!VAR "FrCtrlRefCount" = "0"!]
            [!// Go through all FrIf multiple configurations to find whether the controller is used in some of them
            [!LOOP "node:order(as:modconf('FrIf')[1]/FrIfConfig,'node:name(.)')"!][!// Sort multiple configurations by their name at first
                [!//Go through all clusters in the FrIf multiple configuration to find whether the controller is used in some of them
                [!LOOP "node:order(FrIfCluster/*,'node:name(.)')"!][!// Sort the clusters by their name at first
                    [!//Go through all controllers in the cluster to find whether it is the current Fr controller
                    [!LOOP "node:order(FrIfController/*,'node:value(FrIfCtrlIdx)','node:name(.)')"!][!// Sort the controllers by their name at first
                        [!//Check that the controller is used at most in one cluster - do it as first because the previous reference is otherwise overwritten
                        [!IF "$FrCtrlPath = node:path(node:ref(FrIfFrCtrlRef))"!]
                            [!IF "$FrCtrlRefCount > 0"!]
                                [!ERROR!]
                                    [!WS "0"!]Error 002: The [!"node:name(../../../..)"!]/[!"node:name(../..)"!]/[!"node:name(.)"!]/FrIfFrCtrlRef references [!"node:name(node:ref($FrCtrlPath)/../..)"!]/[!"node:name($FrCtrlPath)"!] which is already used in [!"node:name(node:ref($FrControllersUsage)/../../../..)"!]/[!"node:name(node:ref($FrControllersUsage)/../..)"!]/[!"node:name($FrControllersUsage)"!] cluster. The FrController can be used in only one cluster.
                                [!ENDERROR!]
                            [!ENDIF!]
                            [!IF "node:refvalid(FrIfFrCtrlRef) = true()"!][!// Check valid reference to the Fr controller - avoid accessing node that does not exist
                                [!VAR "FrCtrlRefCount" = "$FrCtrlRefCount + 1"!][!// Increment count of references to this FrController from the FrIf clusters
                                [!//Store the reference to the multiple cluster using this FrController
                                [!VAR "FrControllersUsage" = "node:path(.)"!][!//Store the path of the controllers cluster for further accesses
                            [!ELSE!]
                                [!ERROR!]
                                    [!WS "0"!]Error 001: The [!"node:name(../../../..)"!]/[!"node:name(../..)"!]/[!"node:name(.)"!]/FrIfFrCtrlRef contains invalid reference ([!"string(FrIfFrCtrlRef)"!])
                                [!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!][!//FrIfController loop
                [!ENDLOOP!][!//FrIfCluster loop
            [!ENDLOOP!][!//FrIfConfig loop
            [!//Check that the controller is used
            [!IF "$FrCtrlRefCount = 0"!]
                [!ERROR!]
                    [!WS "0"!]Error 003: The controller [!"node:name(../..)"!]/[!"node:name(.)"!] is not used in any FrIfCluster.
                [!ENDERROR!]
            [!ENDIF!]
            [!//No ambiguous configuration detected, proceed with checks of configuration parameters
            [!//to simplify further accesses put the FrIfCluster using the current FrController into a variable
            [!VAR "FrControllersCluster" = "node:path(node:ref($FrControllersUsage)/../..)"!]
            [!CALL "CfgChecks", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)"!]
        [!ENDNOCODE!]
        [!WS "0"!]/******************************************************************************
        [!WS "0"!]*  Configuration for
        [!WS "0"!]*  Fr:
        [!WS "0"!]*  FrMultipleConfiguration container  '[!"as:name(../..)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]'
        [!WS "0"!]*  FrController container             '[!"node:name(.)"!]','FrCtrlIdx = [!"node:value(FrCtrlIdx)"!]'
        [!WS "0"!]*  FrIf:
        [!WS "0"!]*  FrIfConfig container               '[!"as:name(node:ref($FrControllersCluster)/../..)"!]'
        [!WS "0"!]*  FrIfCluster container              '[!"node:name(node:ref($FrControllersCluster))"!]','FrIfClstIdx = [!"node:value(node:ref($FrControllersCluster)/FrIfClstIdx)"!]'
        [!WS "0"!]*  FrIfController container           '[!"node:name(node:ref($FrControllersUsage))"!]','FrIfCtrlIdx = [!"node:value(node:ref($FrControllersUsage)/FrIfCtrlIdx)"!]'
        [!WS "0"!]******************************************************************************/
        [!WS "0"!][!// This macro will return all slots received into the FIFO A and B in separate lists
        [!CALL "RxFIFOSlots", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "OutFIFOASlots" = "string('')", "OutFIFOBSlots" = "string('')"!]
        [!WS "0"!][!// Count number of required message buffers
        [!VAR "NeededBuffers" = "0"!]
        [!VAR "ReconfigurableBuffers" = "0"!]
        [!VAR "NumberOfSlaveShared"="0"!]
        [!LOOP "node:ref($FrControllersUsage)/FrIfLPdu/*"!]
            [!IF "'true' = text:tolower(node:value(FrIfReconfigurable))"!]
                [!VAR "ReconfigurableBuffers" = "$ReconfigurableBuffers + 1"!]
            [!ENDIF!]
            [!SELECT "node:ref(FrIfVBTriggeringRef)"!]
                [!IF "node:name(node:ref(node:ref(FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu'"!]
                    [!IF "node:value(FrIfChannel) = 'FRIF_CHANNEL_A'"!]
                        [!IF "text:contains(string($OutFIFOASlots), string(FrIfSlotId))"!]
                        [!ELSE!]
                            [!VAR "NeededBuffers" = "$NeededBuffers + 1"!]
                        [!ENDIF!]
                    [!ELSEIF "node:value(FrIfChannel) = 'FRIF_CHANNEL_B'"!]
                        [!IF "text:contains(string($OutFIFOBSlots), string(FrIfSlotId))"!]
                        [!ELSE!]
                            [!VAR "NeededBuffers" = "$NeededBuffers + 1"!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!VAR "NeededBuffers" = "$NeededBuffers + 1"!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "NeededBuffers" = "$NeededBuffers + 1"!]
                [!ENDIF!]
            [!ENDSELECT!]
        [!ENDLOOP!]
        [!IF "text:tolower(node:value(../../../FrGeneral/FrPrepareLPduSupport)) = 'true'"!]
            [!IF "($NeededBuffers > ecu:get('FR.AvailableBuffers')) or ('true' = text:tolower(VendorSpecific/ForceReconfiguration))"!]
                [!INFO!]
                    [!WS "0"!]Starting reconfiguration. [!CR!]Buffers available: [!"num:i(ecu:get('FR.AvailableBuffers'))"!] [!CR!]Buffers needed: [!"num:i($NeededBuffers)"!] [!CR!]Buffers available for reconfiguration: [!"num:i($ReconfigurableBuffers)"!]
                [!ENDINFO!]
                [!IF "FSL_FR_RECONFIG:Reconfig( node:ref($FrControllersUsage)/FrIfLPdu, 4, 0, string(FrCtrlIdx), string(""))='true'"!][!ENDIF!]
                [!WS "0"!][!// in case of some warnings occur, show them (generation will be NOT STOPPED)
                [!IF "FSL_FR_STATUS:HasWarnings() = true()"!]
                    [!WARNING!]Number of warnings: [!"num:i(FSL_FR_STATUS:GetWarningsCount())"!][!"FSL_FR_STATUS:GetWarnings()"!][!ENDWARNING!]
                [!ENDIF!]
                [!WS "0"!][!// in case of some errors occur, show them (generation will be STOPPED)
                [!IF "FSL_FR_STATUS:HasErrors() = true()"!]
                    [!ERROR!]Code Generation stopped! Number of errors: [!"num:i(FSL_FR_STATUS:GetErrorsCount())"!][!"FSL_FR_STATUS:GetErrors()"!][!ENDERROR!]
                [!ENDIF!]
                [!VAR "Reconfigurations" = "FSL_FR_RECONFIG:GetReconfigString()"!][!// Get result string of reconfiguration
                [!VAR "ReconfigurationsDynamic" = "string('')"!][!// Get result string of reconfiguration dynamic segment
                [!VAR "NumberOfSlaveShared"="(count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!][!// Count the number of slave lpdu shared.
                [!VAR "NumberOfSlaveSharedDynamic"="(count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!][!// Count the number of slave lpdu shared.
                [!IF "(ecu:get('FR.AvailableBuffers') + $NumberOfSlaveShared + $NumberOfSlaveSharedDynamic) < $NeededBuffers"!]
                    [!ERROR!]
                        [!WS "0"!]Error 034: Not enough resources for all LPdus even after reconfiguration.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "Reconfigurations" = "''"!]
                [!VAR "ReconfigurationsDynamic"="''"!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "Reconfigurations" = "''"!]
            [!VAR "ReconfigurationsDynamic"="''"!]
            [!IF "$NeededBuffers > ecu:get('FR.AvailableBuffers')"!]
                [!ERROR!]
                    [!WS "0"!]Error 035: Not enough resources for all LPdus, try enable the parameter FrPrepareLPduSupport which enables API function Fr_PrepareLPdu(), so more than one LPdu can share one Message Buffer.
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
        [!WS "0"!][!//
        [!VAR "Fifo_A_Exists" ="'false'"!]
        [!VAR "Fifo_B_Exists" ="'false'"!]
        [!VAR "NumberOfNonFifoMacs" = "num:i(0)"!]
        [!CALL "GetNonFifoMacs", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots"!]
        [!WS "0"!]static Flexray_Ip_StateType FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_State_[!"string($CfgVariant)"!];
        [!WS "0"!][!CR!]
        [!WS "0"!]static Flexray_Ip_BufferStateType FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_BufferState_[!"string($CfgVariant)"!][[!"num:i($NumberOfNonFifoMacs)"!]U];
        [!WS "0"!][!CR!]
        [!WS "0"!]static Flexray_Ip_BufferStateType* FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_BufferMap_[!"string($CfgVariant)"!][[!"num:i($NumberOfNonFifoMacs)"!]U];
        [!WS "0"!][!CR!]
        [!WS "0"!]Flexray_Ip_StateAllocateType Fr_MC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_StateAlloc_[!"string($CfgVariant)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"' '"!]=
        [!WS "0"!]{
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_State_[!"string($CfgVariant)"!],
            [!WS "4"!]FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_BufferState_[!"string($CfgVariant)"!],
            [!WS "4"!]FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_BufferMap_[!"string($CfgVariant)"!]
        [!WS "0"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]/*  Note: The following structure was not supportd by MCAL, values below are hardcoded*/
        [!WS "0"!]static Flexray_Ip_MtsFilterType FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_MtsFilter_A_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
            [!WS "4"!]0U,
            [!WS "4"!]0U
        [!WS "0"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]/*  Note: The following structure was not supportd by MCAL, values below are hardcoded*/
        [!WS "0"!]static Flexray_Ip_MtsFilterType FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_MtsFilter_B_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
            [!WS "4"!]0U,
            [!WS "4"!]0U
        [!WS "0"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]/*  Note: The following structure was not supportd by MCAL, values below are hardcoded*/
        [!WS "0"!]static Flexray_Ip_UserCallbackType FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_userCallBackCfg_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR,
            [!WS "4"!]NULL_PTR
        [!WS "0"!]};
        [!WS "0"!][!CR!]
        [!CALL "ExtendedCfgChecks", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots",  "Reconfigurations" = "$Reconfigurations", "ReconfigurationsDynamic" = "$ReconfigurationsDynamic"!]
        [!CALL "HWConfig", "CfgIdx" = "$FrConfigIdx", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots",  "Reconfigurations" = "$Reconfigurations", "ReconfigurationsDynamic" = "$ReconfigurationsDynamic"!]
        [!CALL "PSRRegisters", "CfgIdx" = "$FrConfigIdx", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)"!]
        [!CALL "LPduConfigs", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots"!]
        [!CALL "FifoCfg", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots", "Reconfigurations" = "$Reconfigurations", "ReconfigurationsDynamic" = "$ReconfigurationsDynamic"!]
        [!CALL "BufferCfg", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots", "Reconfigurations" = "$Reconfigurations", "ReconfigurationsDynamic" = "$ReconfigurationsDynamic"!]
        [!WS "0"!][!//
        [!WS "0"!]static Flexray_Ip_IndMemConfigType FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_MemCfg_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
            [!IF "number($MacStaticBuffersCnt) = 0"!][!//There is no static slot
                [!WS "4"!][!"num:i(node:ref($FrController)/FrPPayloadLengthDynMax)"!]U, /* Data size in buffers segment 1 - pPayloadLengthDynMax */
                [!WS "4"!]0U, /* Data size in buffers segment 2 - second message buffer segment is empty */
            [!ELSE!][!// At least one static slot which belongs to segment1 was configured
                [!WS "4"!][!"num:i(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic)"!]U, /* Data size in buffers segment 1 - gPayloadLengthStatic */
                [!WS "4"!][!"num:i(node:ref($FrController)/FrPPayloadLengthDynMax)"!]U, /* Data size in buffers segment 2 - pPayloadLengthDynMax */
            [!ENDIF!][!//
            [!WS "0"!][!// Get number of buffers used for static (remove reconfigured) and dynamic slots and remove number of slots received into each fifo in static and dynamic segment
            [!SELECT "(node:ref($FrIfCluster)/FrIfController/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
                [!VAR "MacStaticBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacDynamicBuffersCnt" = "count(FrIfLPdu/*[number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)])"!]
                [!VAR "MacFIFOACountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountS" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)<=number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOACountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOASlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacFIFOBCountD" = "count(FrIfLPdu/*[(node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B') and (node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu') and number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots) and text:contains(text:split($FIFOBSlots),num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))])"!]
                [!VAR "MacNumberIndBuffer" = "$MacStaticBuffersCnt +  $MacDynamicBuffersCnt - $MacFIFOACountS - $MacFIFOBCountS - $MacFIFOACountD - $MacFIFOBCountD"!]
                [!VAR "MacStaticBuffersCnt" = "$MacStaticBuffersCnt - (count(text:split($Reconfigurations, ' ')) - count(text:split($Reconfigurations, '#')))"!]
                [!VAR "MacDynamicBuffersCnt" = "$MacDynamicBuffersCnt - (count(text:split($ReconfigurationsDynamic, ' ')) - count(text:split($ReconfigurationsDynamic, '#')))"!]
                [!VAR "MacStaticBuffersCnt" = "($MacStaticBuffersCnt - $MacFIFOACountS) - $MacFIFOBCountS"!]
                [!VAR "MacDynamicBuffersCnt" = "($MacDynamicBuffersCnt - $MacFIFOACountD) - $MacFIFOBCountD"!]
            [!ENDSELECT!]
            [!IF "number($MacStaticBuffersCnt) = 0 "!]
                [!WS "4"!][!"num:i($MacDynamicBuffersCnt)"!]U, /* S1 size */
                [!WS "4"!][!"num:i($MacStaticBuffersCnt)"!]U, /* S2 size */
            [!ELSE!]
                [!WS "4"!][!"num:i($MacStaticBuffersCnt)"!]U, /* S1 size */
                [!WS "4"!][!"num:i($MacDynamicBuffersCnt)"!]U, /* S2 size */
            [!ENDIF!]
            [!WS "4"!][!"num:i($MacNumberIndBuffer)"!]U /* Total ind Buffers */
        [!WS "0"!]};
        [!WS "0"!][!CR!]
        [!SELECT "node:ref($FrControllersUsage)/../../../.."!]
            [!VAR "FrIfConfigIndex" = "position()"!]
        [!ENDSELECT!]
        [!WS "0"!]Flexray_Ip_ConfigType Fr_MC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_Cfg_[!"string($CfgVariant)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"' '"!]=
        [!WS "0"!]{
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_PeConfig_[!"string($CfgVariant)"!],
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_CCCfgSet_[!"string($CfgVariant)"!],
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_userCallBackCfg_[!"string($CfgVariant)"!],
            [!WS "4"!]FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_pIndBufConfig_[!"string($CfgVariant)"!],
            [!WS "4"!]FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_ShadowConfig_[!"string($CfgVariant)"!],
            [!WS "4"!][!"num:i($NumberOfShadowBuffersUsed)"!]U,
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_MemCfg_[!"string($CfgVariant)"!],
            [!WS "4"!][!IF "$Fifo_A_Exists = 'true'"!]&FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_FIFOA_Cfg_[!"string($CfgVariant)"!][!ELSE!]NULL_PTR[!ENDIF!],
            [!WS "4"!][!IF "$Fifo_B_Exists = 'true'"!]&FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_FIFOB_Cfg_[!"string($CfgVariant)"!][!ELSE!]NULL_PTR[!ENDIF!],
            [!WS "4"!]0U,
            [!WS "4"!](boolean)FALSE,
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_MtsFilter_A_[!"string($CfgVariant)"!],
            [!WS "4"!]&FrMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_MtsFilter_B_[!"string($CfgVariant)"!]
        [!WS "0"!]};
        [!WS "0"!][!CR!]
    [!ENDLOOP!][!//FrController
    [!VAR "CtrlConfigCount" = "num:i(count(./FrController/*))"!]
    [!VAR "Comma" = "''"!]
    [!VAR "MaxCoreIdConfig" = "num:i(count(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*))"!]
    [!VAR "CtrlConfigCount" = "num:i(count(./FrController/*))"!]
    [!VAR "Comma" = "''"!]
[!ENDLOOP!][!//FrMultipleConfiguration
[!WS "0"!][!//
#define FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */

[!ENDCODE!]
