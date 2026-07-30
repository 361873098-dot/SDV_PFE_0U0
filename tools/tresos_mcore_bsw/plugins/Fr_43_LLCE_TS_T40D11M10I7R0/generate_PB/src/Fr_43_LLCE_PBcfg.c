[!AUTOSPACING!]
[!NOCODE!]
    [!INCLUDE "Fr_43_LLCE_VersionCheck.m"!]
    [!INCLUDE "Fr_43_LLCE_SpecChecks.m"!]
    [!INCLUDE "Fr_43_LLCE_GeneratorUtils.m"!]

    [!VAR "postBuildVariantName" = "''"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantName" = "concat('_', $postBuildVariant)"!]
    [!ENDIF!]

    [!VAR "CfgVariant" = "string('PB')"!]

    [!/* Sanity check for FrIf plugin to make sure all expected nodes have a valid configuration */!]
    [!CALL "FrIfSanityCheck"!]



    [!/* Macros used to generate Fr driver configuration structures code */!]
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
                                                [!WS "8"!](boolean)TRUE,  /* First Init */
                                            [!ENDIF!]
                                        [!ENDIF!]
                                    [!ENDLOOP!]
                                [!ENDLOOP!]
                                [!IF "$MacReconfigurableDynamic='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                    [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                    [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                    [!WS "8"!](boolean)TRUE, /* First Init */
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
                                                [!WS "8"!](boolean)FALSE,   /* First Init */
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
                                    [!WS "8"!](boolean)TRUE,  /* First Init */
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
                                    [!WS "8"!](boolean)TRUE,   /* Cycle counter filtering enabled */
                                [!ELSE!]
                                    [!WS "8"!](boolean)FALSE,  /* Cycle counter filtering disabled */
                                [!ENDIF!]
                                [!WS "8"!][!"node:value(FrIfBaseCycle)"!]U, /* Cycle counter filter match value */
                                [!WS "8"!][!"num:inttohex(node:value(FrIfCycleRepetition)-1,2)"!]U, /* Cycle counter filter mask (repetition each [!"node:value(FrIfCycleRepetition)"!] cycles) */
                                [!WS "8"!](boolean)FALSE,  /* Repeat TX N/A */
                                [!WS "8"!](boolean)FALSE,  /* Dynamic payload length N/A */
                                [!WS "8"!](boolean)TRUE   /* Buffer Enabled */
                                [!WS "4"!]}[!//
                            [!ENDSELECT!]
                            [!VAR "MacComma" = "','"!]
                        [!ENDIF!]
                    [!ELSE!]
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
                                            [!WS "8"!](boolean)TRUE,  /* First Init */
                                            [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                            [!ENDLOOP!]
                            [!IF "$MacReconfigurableDynamic='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                [!WS "8"!][!"num:i($MacDynamicPosition)"!]U,
                                [!WS "8"!](boolean)TRUE,  /* First Init */
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
                                            [!WS "8"!](boolean)TRUE,  /* First Init */
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
                                [!WS "8"!](boolean)TRUE,   /* Cycle counter filtering enabled */
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
                            [!WS "8"!](boolean)TRUE   /* Buffer Enabled */
                            [!WS "4"!]}[!//
                        [!ENDSELECT!]
                        [!VAR "MacComma" = "','"!]
                    [!ENDIF!][!// Receive and transmit
                [!ENDLOOP!]
                [!WS "0"!][!CR!]
                [!WS "0"!]};
                [!WS "0"!][!CR!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDMACRO!]



    [!MACRO "LPduInfoCfg", "CfgVariant" = "string('PB')", "FrIfCluster" = "", "FrController" = "", "FIFOASlots" = "", "FIFOBSlots" = "", "Reconfigurations" = "", "ReconfigurationsDynamic" = ""!]
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
                [!WS "0"!]/* This structure contains information about all LPdus: buffer type, configuration details,
                [!WS "1"!] * assigned buffer whether the buffer shall be configured at the beginning and whether
                [!WS "1"!] * the buffer is reconfigurable. */
                [!SELECT "node:ref($FrIfCluster)/../.."!]
                    [!VAR "FrIfConfigIndex" = "position()"!]
                [!ENDSELECT!]
                [!WS "0"!]static const Fr_43_LLCE_CCLpduInfoType FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_LPduInfoCfgSet_[!"string($CfgVariant)"!][] =
                [!WS "0"!]{
                [!WS "0"!][!// Go through all LPdus
                [!VAR "MacComma" = "''"!]
                [!VAR "MacFifoALpdu" = "''"!]
                [!VAR "MacFifoBLpdu" = "''"!]
                [!VAR "MacFifoAMatch" = "false()"!]
                [!VAR "MacFifoBMatch" = "false()"!]
                [!VAR "LPDUReferId" = "num:i(0)"!]
                [!LOOP "node:order(FrIfLPdu/*,'node:value(FrIfLPduIdx)','node:name(.)')"!]
                    [!WS "0"!][!// Check whether it is a receive LPdu
                    [!WS "0"!][!IF "contains($MacComma, ',') = 'true'"!][!"$MacComma"!][!CR!][!ENDIF!][!//
                    [!VAR "MacNotFifo" = "true()"!]
                    [!VAR "MacReconfig" = "node:value(FrIfReconfigurable)"!]
                    [!IF "node:name(node:ref(node:ref(node:ref(FrIfVBTriggeringRef)/FrIfFrameStructureRef)/FrIfPdusInFrame/*[position()=1]/FrIfPduRef)/FrIfPduDirection)='FrIfRxPdu'"!]
                        [!WS "0"!][!// RX LPdu; Check whether it is received into a FIFO
                        [!IF "node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A'"!]
                            [!VAR "MacTmpFrIfSlotId" = "string(number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))"!]
                            [!VAR "MacTmpFrIfSlotId" = "concat(' ',$MacTmpFrIfSlotId,' ')"!]
                            [!IF "text:contains(string($FIFOASlots), $MacTmpFrIfSlotId)"!]
                                [!VAR "MacFifoAMatch" = "true()"!]
                                [!IF "text:tolower($MacFIFOAConfigured) = 'true'"!]
                                    [!WARNING!]
                                        [!WS "0"!]Warning 306: Lpdu with FrIfLPduIdx=[!"num:i(FrIfLPduIdx)"!] was assigned to FIFO A but there is another LPdu with FrIfLPduIdx=[!"num:i($MacFifoALpdu)"!] already assigned to FIFO A in the [!"node:path(node:ref($FrIfCluster)/FrIfController/*[node:ref($FrController)]/FrIfLPdu/*[num:i($MacFifoALpdu + 1)])"!].
                                    [!ENDWARNING!]
                                [!ELSE!]
                                    [!VAR "MacFifoALpdu" = "num:i(FrIfLPduIdx)"!]
                                [!ENDIF!][!// FIFO A
                                [!VAR "MacNotFifo" = "false()"!]
                                [!WS "4"!]{FR_43_LLCE_FIFOA_BUFFER, 0U, (boolean)FALSE, 0U, (boolean)FALSE}[!//
                                [!VAR "MacComma" = "concat(', /* LPdu ', num:i(FrIfLPduIdx),' */')"!]
                                [!VAR "MacFIFOAConfigured" = "true()"!]
                                [!VAR "Fifo_A_Exists" ="'true'"!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!IF "node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B'"!]
                            [!VAR "MacTmpFrIfSlotId" = "string(number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))"!]
                            [!VAR "MacTmpFrIfSlotId" = "concat(' ',$MacTmpFrIfSlotId,' ')"!]
                            [!IF "text:contains(string($FIFOBSlots), $MacTmpFrIfSlotId)"!]
                                [!VAR "MacFifoBMatch" = "true()"!]
                                [!IF "text:tolower($MacFIFOBConfigured) = 'true'"!]
                                    [!WARNING!]
                                        [!WS "0"!]Warning 307: Lpdu with FrIfLPduIdx=[!"num:i(FrIfLPduIdx)"!] was assigned to FIFO B but there is another LPdu with FrIfLPduIdx=[!"num:i($MacFifoBLpdu)"!] already assigned to FIFO B it the [!"node:path(node:ref($FrIfCluster)/FrIfController/*[node:ref($FrController)]/FrIfLPdu/*[($MacFifoBLpdu)])"!].
                                    [!ENDWARNING!]
                                [!ELSE!]
                                    [!VAR "MacFifoBLpdu" = "num:i(FrIfLPduIdx)"!]
                                [!ENDIF!][!// FIFO B
                                [!VAR "MacNotFifo" = "false()"!]
                                [!WS "4"!]{FR_43_LLCE_FIFOB_BUFFER, 0U, (boolean)FALSE, 0U, (boolean)FALSE}[!//
                                [!VAR "MacComma" = "concat(', /* LPdu ', num:i(FrIfLPduIdx),' */')"!]
                                [!VAR "MacFIFOBConfigured" = "true()"!]
                                [!VAR "Fifo_B_Exists" ="'true'"!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!IF "text:tolower($MacNotFifo) = 'true'"!]
                            [!WS "4"!]{FR_43_LLCE_IND_BUFFER, [!//
                        [!ENDIF!]
                    [!ELSE!]
                        [!WS "0"!][!/* Tx LPdu; Check whether it is in FIFO ID range*/!]
                        [!IF "node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_A'"!]
                            [!VAR "MacTmpFrIfSlotId" = "string(number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))"!]
                            [!VAR "MacTmpFrIfSlotId" = "concat(' ',$MacTmpFrIfSlotId,' ')"!]
                            [!IF "text:contains(string($FIFOASlots), $MacTmpFrIfSlotId)"!]
                                [!WARNING!]
                                    [!WS "0"!]Warning 316: Lpdu with FrIfLPduIdx=[!"num:i(FrIfLPduIdx)"!] is a transmit Lpdu and its frame ID is in FIFOA ID range.
                                [!ENDWARNING!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!IF "node:value(node:ref(FrIfVBTriggeringRef)/FrIfChannel)='FRIF_CHANNEL_B'"!]
                            [!VAR "MacTmpFrIfSlotId" = "string(number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId))"!]
                            [!VAR "MacTmpFrIfSlotId" = "concat(' ',$MacTmpFrIfSlotId,' ')"!]
                            [!IF "text:contains(string($FIFOBSlots), $MacTmpFrIfSlotId)"!]
                                [!WARNING!]
                                    [!WS "0"!]Warning 317: Lpdu with FrIfLPduIdx=[!"num:i(FrIfLPduIdx)"!] is a transmit Lpdu and its frame ID is in FIFOB ID range.
                                [!ENDWARNING!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!WS "4"!]{FR_43_LLCE_IND_BUFFER, [!//
                    [!ENDIF!]
                    [!IF "text:tolower($MacNotFifo) = 'true'"!][!// Append to line end if it is not a FIFO LPdu
                        [!VAR "LPDUReferId" = "num:i($LPDUReferId + 1)"!]
                        [!WS "0"!][!"num:i($LPDUReferId - 1)"!]U, [!//
                        [!IF "number(node:ref(FrIfVBTriggeringRef)/FrIfSlotId)>number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!// Static or dynamic slot?
                            [!VAR "MacLPduIdx" = "num:i(FrIfLPduIdx)"!]
                            [!VAR "MacReconfigurableDynamic"="'false'"!]
                            [!LOOP "text:split($ReconfigurationsDynamic, '#')"!][!// Go through all groups of LPdus sharing one buffer
                                [!VAR "MacRMaster" = "text:split(.,' ')[1]"!][!// Master LPdu will have own the buffer and share it with the slaves - the rest of the group
                                [!LOOP "text:split(.,' ')"!]
                                    [!IF "num:i(.)=$MacLPduIdx"!][!// Check whether the current LPdu is in the group
                                    [!VAR "MacReconfigurableDynamic"="'true'"!]
                                        [!IF "text:tolower(text:contains(string($MacBufferMastersDynamic), concat('#',$MacRMaster,' ')))='true'"!][!// Check whether the group has already a master
                                            [!WS "0"!][!IF "text:tolower($MacReconfig) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], [!//
                                        [!ELSE!]
                                            [!VAR "MacBufferMastersDynamic" = "concat($MacBufferMastersDynamic, '#', $MacRMaster, ' ', $MacDynamicPosition)"!][!// No master yet, this LPdu will be a master - assign it a buffer and save this info
                                            [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                                            [!WS "0"!][!IF "text:tolower($MacReconfig) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], [!//
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                            [!ENDLOOP!]
                            [!IF "$MacReconfigurableDynamic='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                [!VAR "MacDynamicPosition" = "num:i($MacDynamicPosition + 1)"!]
                                [!WS "0"!][!IF "text:tolower($MacReconfig) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], [!//
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
                                            [!WS "0"!][!IF "text:tolower($MacReconfig) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], [!//
                                        [!ELSE!]
                                            [!VAR "MacBufferMasters" = "concat($MacBufferMasters, '#', $MacRMaster, ' ', $MacStaticPosition)"!][!// No master yet, this LPdu will be a master - assign it a buffer and save this info
                                            [!VAR "MacStaticPosition" = "num:i($MacStaticPosition + 1)"!]
                                            [!WS "0"!][!IF "text:tolower($MacReconfig) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], [!//
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDLOOP!]
                            [!ENDLOOP!]
                            [!IF "$MacReconfigurable='false'"!][!// This LPdu is not reconfigured so assign it an own buffer
                                [!VAR "MacStaticPosition" = "num:i($MacStaticPosition + 1)"!]
                                [!WS "0"!][!IF "text:tolower($MacReconfig) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], [!//
                            [!ENDIF!]
                        [!ENDIF!]
                        [!SELECT "node:ref(FrIfVBTriggeringRef)"!]
                            [!IF "node:value(node:refs('ASPathDataOfSchema:/AUTOSAR/Fr')/FrGeneral/VendorSpecific/FrDisableDemReportErrorStatus) = 'false'"!]
                                [!IF "node:exists(FrIfFrameTriggeringDemEventParameterRefs/FRIF_E_LPDU_SLOTSTATUS)"!]
                                    [!IF "node:refvalid(FrIfFrameTriggeringDemEventParameterRefs/FRIF_E_LPDU_SLOTSTATUS) = false()"!]
                                        [!WARNING!]
                                            [!WS "0"!]Warning 114: FrIfFrameTriggeringDemEventParameterRefs/FRIF_E_LPDU_SLOTSTATUS of the '[!"node:name(.)"!]' has no reference to DemEventID
                                        [!ENDWARNING!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ELSE!]
                                [!IF "node:refvalid(FrIfFrameTriggeringDemEventParameterRefs/FRIF_E_LPDU_SLOTSTATUS) = true()"!]
                                    [!WARNING!]
                                        [!WS "0"!]Warning 115: Dem reporting for the '[!"node:name(.)"!]' is disabled by the /FrGeneral/VendorSpecific/FrDisableDemReportErrorStatus configuration parameter
                                    [!ENDWARNING!]
                                [!ENDIF!]
                            [!ENDIF!]
                            [!IF "node:value(node:refs('ASPathDataOfSchema:/AUTOSAR/Fr')/FrGeneral/VendorSpecific/FrDisableDemReportErrorStatus) = 'false'"!]
                                [!IF "node:refvalid(FrIfFrameTriggeringDemEventParameterRefs/FRIF_E_LPDU_SLOTSTATUS) = true()"!]
                                    [!WS "0"!]DemConf_DemEventParameter_[!"node:name(node:ref(FrIfFrameTriggeringDemEventParameterRefs/FRIF_E_LPDU_SLOTSTATUS))"!], [!//
                                    [!WS "0"!](boolean)TRUE[!//
                                [!ELSE!]
                                    [!WS "0"!]0U, [!//
                                    [!WS "0"!](boolean)FALSE[!//
                                [!ENDIF!]
                            [!ELSE!]
                                [!WS "0"!]0U, [!//
                                [!WS "0"!](boolean)FALSE[!//
                            [!ENDIF!]
                        [!ENDSELECT!]
                        [!WS "0"!]}[!//
                        [!VAR "MacComma" = "concat(', /* LPdu ', num:i(FrIfLPduIdx),' */')"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!WS "0"!][!"substring-after($MacComma,',')"!]
                [!WS "0"!]};
                [!WS "0"!][!CR!]
                [!IF "string($FIFOASlots) != " ""!]
                    [!IF "text:tolower($MacFifoAMatch) = 'false'"!]
                        [!WARNING!]
                            [!WS "0"!]Warning 308: There is no LPdu matching FIFO A criteria for [!"node:path(node:ref($FrIfCluster)/FrIfController/*[node:ref($FrController)]/FrIfLPdu)"!].
                        [!ENDWARNING!]
                    [!ENDIF!]
                [!ENDIF!]
                [!IF "string($FIFOBSlots) != " ""!]
                    [!IF "text:tolower($MacFifoBMatch) = 'false'"!]
                        [!WARNING!]
                            [!WS "0"!]Warning 309: There is no LPdu matching FIFO B criteria for [!"node:path(node:ref($FrIfCluster)/FrIfController/*[node:ref($FrController)]/FrIfLPdu)"!].
                        [!ENDWARNING!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDMACRO!]



    [!MACRO "PSRRegisters", "CfgIdx" = "0", "CfgVariant" = "", "FrIfCluster" = "", "FrController" = ""!]
        [!WS "0"!][!// this code snippet will compute keyslot header crc
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
        [!ENDIF!]
        [!WS "0"!][!// this code snipper will compute SFTOR value
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
        [!VAR "MacSFTBeginning" = "($MacStaticBuffersCnt + $MacDynamicBuffersCnt + $MacShadowCount1 + $MacShadowCount2 + $MacFIFOBDepth + $MacFIFOADepth) * 8"!]
        [!VAR "MacSFTBeginning" = "num:i(bit:and(num:i($MacSFTBeginning + 1), num:hextoint('0xFFFFFFFE')))"!][!// Adjust to be a multiple of 2
        [!VAR "MacSFTBeginning" = "$MacSFTBeginning + ($MacStaticBuffersCnt * $MacStaticPayload) + ($MacDynamicBuffersCnt * $MacDynamicPayload) + ($MacShadowCount1 * $MacStaticPayload) + ($MacShadowCount2 * $MacDynamicPayload) + ($MacFIFOADepth * $MacFIFOALength) + ($MacFIFOBDepth * $MacFIFOBLength)"!]
        [!WS "0"!]/*  This field contains FlexRay Protocol configuration
        [!WS "1"!] *  parameters returned by the Fr_43_LLCE_ReadCCConfig function */
        [!WS "0"!]static const uint32 Fr_43_LLCEMC[!"num:i($CfgIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_CCReadBackParamSet_[!"string($CfgVariant)"!][] =
        [!WS "0"!]{
        [!WS "4"!][!"num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdCycle)*1000000000,8)"!]U, /* gdCycle=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdCycle)*1000000000)"!][ns] */
        [!WS "4"!][!"num:inttohex(node:value(node:ref($FrController)/FrPMicroPerCycle),8)"!]U, /* pMicroPerCycle=[!"num:i(node:value(node:ref($FrController)/FrPMicroPerCycle))"!] */
        [!WS "4"!][!"num:inttohex(node:value(node:ref($FrController)/FrPdListenTimeout),8)"!]U, /* pdListenTimeout=[!"num:i(node:value(node:ref($FrController)/FrPdListenTimeout))"!][uT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdMacrotick)*1000000000,4),'0x') )"!]U, /* gMacroPerCycle=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle))"!][MT], gdMacrotick=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdMacrotick)*1000000000)"!][ns] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots),4),'0x') )"!]U, /* gNumberOfMinislots=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots))"!], gNumberOfStaticSlots=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots))"!] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdNit),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdStaticSlot),4), '0x') )"!]U, /* gdNIT=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdNit))"!][MT], gdStaticSlot=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdStaticSlot))"!][MT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxWindow),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPKeySlotId),4), '0x') )"!]U, /* gdWakeupRxWindow=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxWindow))"!][MT], pKeySlotId=[!"num:i(node:value(node:ref($FrController)/FrPKeySlotId))"!] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPLatestTx),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPOffsetCorrectionOut),4), '0x') )"!]U, /* pLatestTx=[!"num:i(node:value(node:ref($FrController)/FrPLatestTx))"!][Minislot], pOffsetCorrectionOut=[!"num:i(node:value(node:ref($FrController)/FrPOffsetCorrectionOut))"!][uT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPOffsetCorrectionStart),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPRateCorrectionOut),4), '0x') )"!]U, /* gOffsetCorrectionStart=[!"num:i(node:value(node:ref($FrController)/FrPOffsetCorrectionStart))"!][MT], pRateCorrectionOut=[!"num:i(node:value(node:ref($FrController)/FrPRateCorrectionOut))"!][uT] */
        [!WS "4"!][!"concat( num:inttohex('0',4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPdAcceptedStartupRange),4), '0x') )"!]U, /* pSecondKeySlotId=0(Not supported by the FlexRay Protocol 2.1revA specification), pdAcceptedStartupRange=[!"num:i(node:value(node:ref($FrController)/FrPdAcceptedStartupRange))"!][uT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGColdStartAttempts),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGCycleCountMax),4), '0x') )"!]U, /* gColdStartAttempts=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGColdStartAttempts))"!], cCycleCountMax=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGCycleCountMax))"!] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGListenNoise),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectFatal),4), '0x') )"!]U, /* gListenNoise=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGListenNoise))"!], gMaxWithoutClockCorrectFatal=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectFatal))"!][even/odd cycle pairs] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectPassive),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGNetworkManagementVectorLength),4), '0x') )"!]U, /* gMaxWithoutClockCorrectionPassive=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectPassive))"!][even/odd cycle pairs], gNetworkManagementVectorLength=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGNetworkManagementVectorLength))"!][bytes] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGSyncFrameIDCountMax),4), '0x') )"!]U, /* gPayloadLengthStatic=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic))"!][two-byte-words], gSyncFrameIDCountMax=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGSyncFrameIDCountMax))"!] */
        [!IF "node:value(node:ref($FrIfCluster)/FrIfGdBit)='T100NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// gdBit T100NS
        [!ELSEIF "node:value(node:ref($FrIfCluster)/FrIfGdBit)='T200NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// gdBit T200NS
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('2',4)"!][!// gdBit T400NS
        [!ENDIF!]
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdActionPointOffset),4), substring-after($MacTempValue1, '0x') )"!]U, /* gdActionPointOffset [!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdActionPointOffset))"!] MT, gdBit [!"num:hextoint($MacTempValue1)"!] [!"node:value(node:ref($FrIfCluster)/FrIfGdBit)"!] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdCasRxLowMax),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdDynamicSlotIdlePhase),4), '0x') )"!]U, /* gdCasRxLowMax=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdCasRxLowMax))"!][gdBit], gdDynamicSlotIdlePhase=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdDynamicSlotIdlePhase))"!][Minislot] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdMiniSlotActionPointOffset),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdMinislot),4), '0x') )"!]U, /* gdMiniSlotActionPointOffset=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdMiniSlotActionPointOffset))"!][MT], gdMinislot=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdMinislot))"!][MT] */
        [!IF "node:value(node:ref($FrIfCluster)/FrIfGdSampleClockPeriod)='T12_5NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// gdSampleClockPeriod T12_5NS
        [!ELSEIF "node:value(node:ref($FrIfCluster)/FrIfGdSampleClockPeriod)='T25NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// gdSampleClockPeriod T25NS
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('2',4)"!][!// gdSampleClockPeriod T50NS
        [!ENDIF!]
        [!WS "4"!][!"concat( $MacTempValue1, substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindow),4), '0x') )"!]U, /* gdSampleClockPeriod=[!"num:hextoint($MacTempValue1)"!]([!"node:value(node:ref($FrIfCluster)/FrIfGdSampleClockPeriod)"!]), gdSymbolWindow=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindow))"!][MT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindowActionPointOffset),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdTSSTransmitter),4), '0x') )"!]U, /* gdActionPointOffset=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindowActionPointOffset))"!][MT], gdTSSTransmitter=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdTSSTransmitter))"!][gdBit] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxIdle),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxLow),4), '0x') )"!]U, /* gdWakeupSymbolRxIdle=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxIdle))"!][gdBit], gdWakeupSymbolRxLow=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxLow))"!][gdBit] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxActive),4), substring-after(num:inttohex(node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxIdle),4), '0x') )"!]U, /* gdWakeupSymbolTxActive=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxActive))"!][gdBit], gdWakeupSymbolTxIdle=[!"num:i(node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxIdle))"!][gdBit] */
        [!IF "node:value(node:ref($FrController)/FrPChannels)='FR_CHANNEL_A'"!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pChannels FR_CHANNEL_A
        [!ELSEIF "node:value(node:ref($FrController)/FrPChannels)='FR_CHANNEL_B'"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pChannels FR_CHANNEL_B
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('2',4)"!][!// pChannels FR_CHANNEL_AB
        [!ENDIF!]
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPAllowPassiveToActive),4), substring-after($MacTempValue1, '0x') )"!]U, /* pAllowPassiveToActive=[!"num:i(node:value(node:ref($FrController)/FrPAllowPassiveToActive))"!][even/odd cycle pairs], pChannels=[!"num:hextoint($MacTempValue1)"!]([!"node:value(node:ref($FrController)/FrPChannels)"!]) */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPClusterDriftDamping),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPDecodingCorrection),4), '0x') )"!]U, /* pClusterDriftDamping=[!"num:i(node:value(node:ref($FrController)/FrPClusterDriftDamping))"!][uT], pDecodingCorrection=[!"num:i(node:value(node:ref($FrController)/FrPDecodingCorrection))"!][uT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPDelayCompensationA),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPDelayCompensationB),4), '0x') )"!]U, /* pDelayCompensationA=[!"num:i(node:value(node:ref($FrController)/FrPDelayCompensationA))"!][uT], pDelayCompensationB=[!"num:i(node:value(node:ref($FrController)/FrPDelayCompensationB))"!][uT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPMacroInitialOffsetA),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPMacroInitialOffsetB),4), '0x') )"!]U, /* pMacroInitialOffsetA=[!"num:i(node:value(node:ref($FrController)/FrPMacroInitialOffsetA))"!][MT], pMacroInitialOffsetB=[!"num:i(node:value(node:ref($FrController)/FrPMacroInitialOffsetB))"!][MT] */
        [!WS "4"!][!"concat( num:inttohex(node:value(node:ref($FrController)/FrPMicroInitialOffsetA),4), substring-after(num:inttohex(node:value(node:ref($FrController)/FrPMicroInitialOffsetB),4), '0x') )"!]U, /* pMicroInitialOffsetA=[!"num:i(node:value(node:ref($FrController)/FrPMicroInitialOffsetA))"!][uT], pMicroInitialOffsetB=[!"num:i(node:value(node:ref($FrController)/FrPMicroInitialOffsetB))"!][uT] */
        [!IF "node:value(node:ref($FrController)/FrPSamplesPerMicrotick)='N1SAMPLES'"!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pSamplesPerMicrotick N1SAMPLES
        [!ELSEIF "node:value(node:ref($FrController)/FrPSamplesPerMicrotick)='N2SAMPLES'"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pSamplesPerMicrotick N2SAMPLES
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('2',4)"!][!// pSamplesPerMicrotick N4SAMPLES
        [!ENDIF!]
        [!WS "4"!][!"concat( num:inttohex(bit:and(number(node:ref($FrController)/FrPPayloadLengthDynMax),127),4), substring-after($MacTempValue1, '0x') )"!]U, /* pPayloadLengthDynMax [!"num:i(bit:and(number(node:ref($FrController)/FrPPayloadLengthDynMax),127))"!] two-byte-words , pSamplesPerMicrotick [!"num:hextoint($MacTempValue1)"!] [!"node:value(node:ref($FrController)/FrPSamplesPerMicrotick)"!] */
        [!IF "node:value(node:ref($FrController)/FrPWakeupChannel)='FR_CHANNEL_A'"!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pWakeupChannel FR_CHANNEL_A
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pWakeupChannel FR_CHANNEL_B
        [!ENDIF!]
        [!WS "4"!][!"concat( $MacTempValue1, substring-after(num:inttohex(node:value(node:ref($FrController)/FrPWakeupPattern),4), '0x') )"!]U, /* pWakeupChannel=[!"num:hextoint($MacTempValue1)"!]([!"node:value(node:ref($FrController)/FrPWakeupChannel)"!]), pWakeupPattern=[!"num:i(node:value(node:ref($FrController)/FrPWakeupPattern))"!] */
        [!IF "node:value(node:ref($FrController)/FrPdMicrotick)='T12_5NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pdMicrotick T12_5NS
        [!ELSEIF "node:value(node:ref($FrController)/FrPdMicrotick)='T25NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pdMicrotick T25NS
        [!ELSEIF "node:value(node:ref($FrController)/FrPdMicrotick)='T50NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('2',4)"!][!// pdMicrotick T50NS
        [!ELSEIF "node:value(node:ref($FrController)/FrPdMicrotick)='T100NS'"!]
            [!VAR "MacTempValue1" = "num:inttohex('3',4)"!][!// pdMicrotick T100NS
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('4',4)"!][!// pdMicrotick T200NS
        [!ENDIF!]
        [!WS "4"!][!"concat( $MacTempValue1 , substring-after(num:inttohex('0',4), '0x') )"!]U, /* pdMicrotick=[!"num:hextoint($MacTempValue1)"!]([!"node:value(node:ref($FrController)/FrPdMicrotick)"!]), gdIgnoreAfterTx=0(Not supported by the FlexRay Protocol 2.1revA specification) */
        [!IF "node:value(node:ref($FrController)/FrPAllowHaltDueToClock)"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pAllowHaltDueToClock enabled
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pAllowHaltDueToClock disabled
        [!ENDIF!]
        [!WS "4"!][!"concat( $MacTempValue1, substring-after(num:inttohex('0',4), '0x') )"!]U, /* pAllowHaltDueToClock=[!"num:hextoint($MacTempValue1)"!]([!"node:value(node:ref($FrController)/FrPAllowHaltDueToClock)"!]), pExternalSync=0(Not supported by the FlexRay Protocol 2.1revA specification) */
        [!IF "text:tolower(node:value(node:ref($FrController)/FrPKeySlotOnlyEnabled))='true'"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pKeySlotOnlyEnabled
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pKeySlotOnlyEnabled
        [!ENDIF!]
        [!WS "4"!][!"concat( num:inttohex('0',4) , substring-after($MacTempValue1, '0x') )"!]U, /* pFallBackInternal=0(Not supported by the FlexRay Protocol 2.1revA specification), pKeySlotOnlyEnabled=[!"num:hextoint($MacTempValue1)"!]([!"node:value(node:ref($FrController)/FrPKeySlotOnlyEnabled)"!]) */
        [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)"!]
            [!VAR "MacTempValue1" = "num:inttohex('1',4)"!][!// pKeySlotUsedForStartup
        [!ELSE!]
            [!VAR "MacTempValue1" = "num:inttohex('0',4)"!][!// pKeySlotUsedForStartup
        [!ENDIF!]
        [!IF "node:value(node:ref($FrController)/FrPKeySlotUsedForSync)"!]
            [!VAR "MacTempValue2" = "num:inttohex('1',4)"!][!// pKeySlotUsedForSync
        [!ELSE!]
            [!VAR "MacTempValue2" = "num:inttohex('0',4)"!][!// pKeySlotUsedForSync
        [!ENDIF!]
        [!WS "4"!][!"concat($MacTempValue1, substring-after($MacTempValue2, '0x') )"!]U, /* pKeySlotUsedForStartup [!"num:hextoint($MacTempValue1)"!] [!"node:value(node:ref($FrController)/FrPKeySlotUsedForStartup)"!], pKeySlotUsedForSync [!"num:hextoint($MacTempValue2)"!] [!"node:value(node:ref($FrController)/FrPKeySlotUsedForSync)"!] */
        [!WS "4"!][!"concat( num:inttohex('0',4), substring-after(num:inttohex('0',4), '0x') )"!]U /* pNmVectorEarlyUpdate=0(Not supported by the FlexRay Protocol 2.1revA specification), pTwoKeySlotMode=0(Not supported by the FlexRay Protocol 2.1revA specification) */
        [!WS "0"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]/*  Structure of this type contains configuration
        [!WS "1"!] *  information of the one low level parameters set */
        [!WS "0"!]static const Fr_43_LLCE_CCLowLevelConfigSetType Fr_43_LLCEMC[!"num:i($CfgIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_CCLowLevelCfgSet_[!"string($CfgVariant)"!] =
        [!WS "0"!]{
        [!WS "0"!][!// PCR0
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdActionPointOffset)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdStaticSlot)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)-1"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),1023)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,10)),$MacTempValue2)"!]
        [!WS "0"!][!// PCR1
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdStaticSlot)"!]
        [!VAR "MacTempValue1_2" = "number($MacTempValue1)-number($MacTempValue2)"!]
        [!WS "4"!][!"concat(num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR0_1 */
        [!WS "0"!][!// PCR2
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdMinislot)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdMiniSlotActionPointOffset)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)-number($MacTempValue2)-1"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),1023)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,10)),$MacTempValue3)"!]
        [!WS "0"!][!// PCR3
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxLow)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdMiniSlotActionPointOffset)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGColdStartAttempts)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "(bit:and(number($MacTempValue2),31)-1)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),31)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,5)),$MacTempValue2)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,5)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR2_3 */
        [!WS "0"!][!// PCR4
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdCasRxLowMax)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxWindow)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)-1"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),511)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,9)),$MacTempValue2)"!]
        [!WS "0"!][!// PCR5
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdTSSTransmitter)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxActive)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGdWakeupRxIdle)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),63)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),63)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,6)),$MacTempValue2)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,6)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR4_5 */
        [!WS "0"!][!// PCR6
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindow)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdActionPointOffset)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPMacroInitialOffsetA)"!]
        [!IF "$MacTempValue1 != 0"!][!// Check if GdSymbolWindow is not equal to zero
            [!VAR "MacTempValue1" = "number($MacTempValue1)-number($MacTempValue2)-1"!][!// No -> normal calculation
        [!ELSE!][!// Yes, GdSymbolWindow is equal to zero -> store zero value instead of standard calculation
            [!VAR "MacTempValue1" = "0"!]
        [!ENDIF!][!// End of checking
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),127)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,7)),$MacTempValue3)"!]
        [!WS "0"!][!// PCR7
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPDecodingCorrection)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrController)/FrPDelayCompensationB)"!]
        [!VAR "MacTempValue4" = "node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPMicroPerCycle)"!]
        [!VAR "MacTempValue3" = "num:i($MacTempValue3 div $MacTempValue4)"!][!// Compute pMicroPerMacroNom value
        [!VAR "MacTempValue1" = "number($MacTempValue1)+number($MacTempValue2)+2"!]
        [!VAR "MacTempValue3" = "(number($MacTempValue3) div 2)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,7)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR6_7 */
        [!WS "0"!][!// PCR8
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectFatal)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGMaxWithoutClockCorrectPassive)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGdWakeupTxIdle)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),15)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),255)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,4)),$MacTempValue2)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,8)),$MacTempValue3)"!]
        [!WS "0"!][!// PCR9
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdSymbolWindow)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPOffsetCorrectionOut)"!]
        [!VAR "MacTempValue1" = "num:i($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "num:i($MacTempValue2)"!]
        [!VAR "MacTempValue3" = "bit:and(num:i($MacTempValue3),16383)"!]
        [!IF "$MacTempValue1!=0"!]
            [!VAR "MacTempValue1"="1"!]
        [!ELSE!]
            [!VAR "MacTempValue1"="0"!]
        [!ENDIF!]
        [!IF "$MacTempValue2!=0"!]
            [!VAR "MacTempValue2"="1"!]
        [!ELSE!]
            [!VAR "MacTempValue2"="0"!]
        [!ENDIF!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,1)),$MacTempValue2)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,14)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR8_9 */
        [!WS "0"!][!// PCR10
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle)"!]
        [!IF "text:tolower(node:value(node:ref($FrController)/FrPKeySlotOnlyEnabled))='true'"!]
            [!VAR "MacTempValue1"="1"!]
        [!ELSE!]
            [!VAR "MacTempValue1"="0"!]
        [!ENDIF!]
        [!IF "node:value(node:ref($FrController)/FrPWakeupChannel)='FR_CHANNEL_A'"!]
            [!VAR "MacTempValue2"="0"!]
        [!ELSE!]
            [!VAR "MacTempValue2"="1"!]
        [!ENDIF!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),16383)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,1)),$MacTempValue2)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,14)),$MacTempValue3)"!]
        [!WS "0"!][!// PCR11
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPOffsetCorrectionStart)"!]
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
        [!VAR "MacTempValue1" = "number($KeySlotStartup)"!]
        [!VAR "MacTempValue2" = "number($KeySlotSync)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),16383)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,1)),$MacTempValue2)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,14)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR10_11  PCR11 - pOffsetCorrectionStart from spec. 3.0 used instead of gOffsetCorrectionStart from spec. 2.1*/
        [!WS "0"!][!// PCR12
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPAllowPassiveToActive)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic)"!]
        [!IF "number(node:ref($FrController)/FrPKeySlotId) > 0"!]
            [!CALL "CrcCalculation", "Sync" = "number($KeySlotSync)", "Startup" = "number($KeySlotStartup)", "FrameId" = "number(node:ref($FrController)/FrPKeySlotId)", "PayloadLengthW" = "$MacTempValue2", "OutCrc"="1"!]
            [!VAR "MacTempValue2" = "bit:and(number($OutCrc),2047)"!]
        [!ELSE!]
            [!VAR "MacTempValue2" = "0"!]
            [!VAR "OutCrc" = "0"!]
        [!ENDIF!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,11)),$MacTempValue2)"!]
        [!WS "0"!][!// PCR13
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdActionPointOffset)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGdMiniSlotActionPointOffset)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGdStaticSlot)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)"!]
        [!VAR "MacTempValue3" = "number($MacTempValue3)"!]
        [!VAR "MacTempValue3" = "number($MacTempValue3)-number($MacTempValue1)-1"!]
        [!IF "$MacTempValue1 >= $MacTempValue2"!]
            [!VAR "MacTempValue4"="$MacTempValue1"!]
        [!ELSE!]
            [!VAR "MacTempValue4"="$MacTempValue2"!]
        [!ENDIF!]
        [!VAR "MacTempValue4" = "(number($MacTempValue4)-1)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),1023)"!]
        [!VAR "MacTempValue4" = "bit:or((bit:shl($MacTempValue4,10)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue4,4),'0x') )"!]U,        /*  PCR12_13  PCR12 - Key slot crc is [!"num:i($OutCrc)"!] = [!"num:inttohex($OutCrc, 4)"!] */
        [!WS "0"!][!// PCR14
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPdListenTimeout)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrController)/FrPRateCorrectionOut)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)-1"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)"!]
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue1),2031616)"!]
        [!VAR "MacTempValue3_1" = "bit:or((bit:shl($MacTempValue2,5)),(bit:shr($MacTempValue3,16)))"!]
        [!WS "0"!][!// PCR15
        [!VAR "TempValue3_2" = "bit:and(number($MacTempValue1),65535)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue3_1,4), substring-after(num:inttohex($TempValue3_2,4),'0x') )"!]U,        /*  PCR14_15 */
        [!WS "0"!][!// PCR16
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPdListenTimeout)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrController)/FrPMacroInitialOffsetB)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrIfCluster)/FrIfGListenNoise)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)"!]
        [!VAR "MacTempValue4" = "number($MacTempValue1)*number($MacTempValue3)"!]
        [!VAR "MacTempValue4" = "number($MacTempValue4)-1"!]
        [!VAR "MacTempValue5" = "bit:and(number($MacTempValue4),33488896)"!]
        [!VAR "MacTempValue5_1" = "bit:or((bit:shl($MacTempValue2,9)),(bit:shr($MacTempValue5,16)))"!]
        [!WS "0"!][!// PCR17
        [!VAR "MacTempValue5_2" = "bit:and(number($MacTempValue4),65535)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue5_1,4), substring-after(num:inttohex($MacTempValue5_2,4),'0x') )"!]U,        /*  PCR16_17 */
        [!WS "0"!][!// PCR18
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPWakeupPattern)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "bit:and(number(node:ref($FrController)/FrPKeySlotId),1023)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,10)),$MacTempValue2)"!]
        [!WS "0"!][!// PCR19
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPDecodingCorrection)"!]
        [!VAR "MacTempValue2_2" = "node:value(node:ref($FrController)/FrPDelayCompensationA)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)+number($MacTempValue2_2)+2"!]
        [!VAR "MacTempValue3" = "bit:and(number(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic),127)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,7)),$MacTempValue3)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR18_19  PCR18 - Key Slot ID is [!"$MacTempValue2"!][!IF "0 = number($KeySlotStartup) and 0 = number($KeySlotSync)"!], Key Slot is not used for sync/startup.[!ENDIF!][!"' '"!]*/
        [!WS "0"!][!// PCR20
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPMicroInitialOffsetB)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrController)/FrPMicroInitialOffsetA)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,8)),$MacTempValue2)"!]
        [!WS "0"!][!// PCR21
        [!VAR "MacTempValue1" = "0"!][!// pExternRateCorrection is no longer supported, used value 0
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPLatestTx)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)-number($MacTempValue3)"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),8191)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,13)),$MacTempValue2)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR20_21 */
        [!WS "0"!][!// PCR22
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPdAcceptedStartupRange)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrController)/FrPDelayCompensationA)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPMicroPerCycle)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue1)-number($MacTempValue2)"!]
        [!VAR "MacTempValue5" = "bit:and(number($MacTempValue3),983040)"!]
        [!VAR "MacTempValue4" = "bit:or((bit:shl($MacTempValue2,4)),(bit:shr($MacTempValue5,16)))"!]
        [!WS "0"!][!// PCR23
        [!VAR "MacTempValue3" = "bit:and(number($MacTempValue3),65535)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue4,4), substring-after(num:inttohex($MacTempValue3,4),'0x') )"!]U,        /*  PCR22_23 */
        [!WS "0"!][!// PCR24
        [!VAR "MacTempValue1" = "node:value(node:ref($FrController)/FrPClusterDriftDamping)"!]
        [!VAR "MacTempValue2" = "bit:and(number(node:ref($FrController)/FrPPayloadLengthDynMax),127)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPMicroPerCycle)"!]
        [!WS "0"!][!// Compute the value of the pdMaxDrift
        [!VAR "MacTempValue4" = "ceiling(number(node:value(node:ref($FrController)/FrPMicroPerCycle))*2*0.0015 div(1-0.0015))"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue3" = "number($MacTempValue3)-number($MacTempValue4)"!]
        [!VAR "MacTempValue5" = "bit:and(number($MacTempValue3),983040)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,7)),$MacTempValue2)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,4)),(bit:shr($MacTempValue5,16)))"!]
        [!WS "0"!][!// PCR25
        [!VAR "MacTempValue5" = "bit:and(number($MacTempValue3),65535)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1,4), substring-after(num:inttohex($MacTempValue5,4),'0x') )"!]U,        /*  PCR24_25 */
        [!WS "0"!][!// PCR26
        [!IF "node:value(node:ref($FrController)/FrPAllowHaltDueToClock)"!]
            [!VAR "MacTempValue1"="1"!]
        [!ELSE!]
            [!VAR "MacTempValue1"="0"!]
        [!ENDIF!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrController)/FrPdAcceptedStartupRange)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPDelayCompensationB)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)-number($MacTempValue3)"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),2047)"!]
        [!VAR "MacTempValue4" = "node:value(node:ref($FrController)/FrPMicroPerCycle)"!]
        [!WS "0"!][!// Compute the value of the pdMaxDrift
        [!VAR "MacTempValue5" = "ceiling(number(node:value(node:ref($FrController)/FrPMicroPerCycle))*2*0.0015 div(1-0.0015))"!]
        [!VAR "MacTempValue4" = "number($MacTempValue4)+number($MacTempValue5)"!]
        [!VAR "MacTempValue6" = "bit:and(number($MacTempValue4),983040)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,11)),$MacTempValue2)"!]
        [!VAR "MacTempValue1" = "bit:or((bit:shl($MacTempValue1,4)),(bit:shr($MacTempValue6,16)))"!]
        [!WS "0"!][!// PCR27
        [!VAR "MacTempValue6" = "bit:and(number($MacTempValue4),65535)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1,4), substring-after(num:inttohex($MacTempValue6,4),'0x') )"!]U,        /*  PCR26_27 */
        [!WS "0"!][!// PCR28
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGdDynamicSlotIdlePhase)"!]
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGMacroPerCycle)"!]
        [!VAR "MacTempValue3" = "node:value(node:ref($FrController)/FrPOffsetCorrectionStart)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)-number($MacTempValue3)"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),16383)"!]
        [!VAR "MacTempValue1_1" = "bit:or((bit:shl($MacTempValue1,14)),$MacTempValue2)"!]
        [!WS "0"!][!// PCR29
        [!VAR "MacTempValue1" = "0"!][!// pExternOffsetCorrection is no longer supported, used value 0
        [!VAR "MacTempValue2" = "node:value(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!VAR "MacTempValue2" = "number($MacTempValue2)-1"!]
        [!VAR "MacTempValue2" = "bit:and(number($MacTempValue2),8191)"!]
        [!VAR "MacTempValue1_2" = "bit:or((bit:shl($MacTempValue1,13)),$MacTempValue2)"!]
        [!WS "4"!][!"concat(  num:inttohex($MacTempValue1_1,4), substring-after(num:inttohex($MacTempValue1_2,4),'0x') )"!]U,        /*  PCR28_29 */
        [!WS "0"!][!// PCR30
        [!VAR "MacTempValue1" = "node:value(node:ref($FrIfCluster)/FrIfGSyncFrameIDCountMax)"!]
        [!VAR "MacTempValue1" = "number($MacTempValue1)"!]
        [!WS "4"!][!"num:inttohex($MacTempValue1,4)"!]U,            /*  PCR30 */
        [!WS "4"!][!"num:i(number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots))"!]U,                /*  gNumberOfStaticSlots */
        [!WS "4"!][!"num:i(number(node:ref($FrController)/FrPPayloadLengthDynMax))"!]U,                 /*  pPayloadLengthDynMax */
        [!WS "4"!][!"num:i(node:value(node:ref($FrIfCluster)/FrIfGPayloadLengthStatic))"!]U                 /*  gPayloadLengthStatic */
        [!WS "0"!]};
        [!WS "0"!][!CR!]
    [!ENDMACRO!]

[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
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
*   @file Fr_43_LLCE_PBcfg.c
*   @implements  Fr_PBcfg.c_Artifact
*
*   @addtogroup FR_HLD
*   @{
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
#include "Fr_43_LLCE.h"
#include "Dem.h"
#include "Flexray_43_LLCE_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_VENDOR_ID_C                      43
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_MAJOR_VERSION_C               1
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_MINOR_VERSION_C               0
#define FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_PATCH_VERSION_C               7

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_VENDOR_ID_C != FR_43_LLCE_VENDOR_ID)
    #error "Fr[!"$postBuildVariantName"!]_PBcfg.c and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FR_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FR_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FR_43_LLCE_AR_RELEASE_REVISION_VERSION))
    #error "Software Version Numbers of Fr[!"$postBuildVariantName"!]_PBcfg.c and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same software version */
#if((FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_MAJOR_VERSION_C != FR_43_LLCE_SW_MAJOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_MINOR_VERSION_C != FR_43_LLCE_SW_MINOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_PATCH_VERSION_C != FR_43_LLCE_SW_PATCH_VERSION))
    #error "Autosar Version Numbers of Fr[!"$postBuildVariantName"!]_PBcfg.c and Fr.h are different"
#endif

/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same vendor */
#if(FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_VENDOR_ID_C != FLEXRAY_43_LLCE_IP_VENDOR_ID)
    #error "Fr[!"$postBuildVariantName"!]_PBcfg.c and Flexray_43_LLCE_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same Autosar version */
#if((FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MAJOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MINOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_43_LLCE_IP_AR_RELEASE_REVISION_VERSION))
    #error "Software Version Numbers of Fr[!"$postBuildVariantName"!]_PBcfg.c and Flexray_43_LLCE_Ip.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same software version */
#if((FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_MAJOR_VERSION_C != FLEXRAY_43_LLCE_IP_SW_MAJOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_MINOR_VERSION_C != FLEXRAY_43_LLCE_IP_SW_MINOR_VERSION) || \
    (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_SW_PATCH_VERSION_C != FLEXRAY_43_LLCE_IP_SW_PATCH_VERSION))
    #error "Autosar Version Numbers of Fr[!"$postBuildVariantName"!]_PBcfg.c and Flexray_43_LLCE_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if(FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h header file are of the same Autosar version */
    #if((FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (FR_43_LLCE[!"$postBuildVariantName"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr[!"$postBuildVariantName"!]_PBcfg.c and Dem.h are different"
    #endif
#endif
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
#define FR_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_43_LLCE_MemMap.h"

    [!VAR "CtrlNum" = "num:i('0')"!][!//Stores max number of CC which wre configured for all multpile configurations
    [!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!][!//Sort the multiple configurations by their name at first
        [!IF "count(FrController/*) > $CtrlNum"!]
            [!VAR "CtrlNum" = "count(FrController/*)"!][!//Find multiple configuration wit max. number of configured CC
        [!ENDIF!]
    [!ENDLOOP!]
    [!VAR "CtrlNum" = "num:i('0')"!]
    [!IF "node:value(FrGeneral/FrNumCtrlSupported) > (1)"!]
        [!ERROR!]
            [!WS "0"!]Error 050: Too many controllers are required to be supported at [!"node:path(FrGeneral/FrNumCtrlSupported)"!] by the driver. Driver will support maximum [!"num:i(1)"!] FlexRay [!IF "num:i(1) > 1"!]controllers available on the hardware[!ELSE!]controller available on the hardware[!ENDIF!].
        [!ENDERROR!]
    [!ENDIF!]
    [!WS "0"!][!// Go through all Fr multiple configurations
    [!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!][!//Sort the multiple configurations by their name at first
        [!VAR "FrConfigName" = "as:name(.)"!][!//Store the name of Fr controller multiple configuration
        [!VAR "FrConfigIdx" = "position()"!][!//Store the index of Fr controller multiple configuration
        [!WS "0"!][!// Go through all controllers in the Fr multiple configuration
        [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
            [!IF "$CtrlNum < count(../*)"!]
                [!VAR "CtrlNum" = "count(../*)"!]
            [!ENDIF!]
            [!VAR "FrCtrlName" = "node:name(.)"!][!//Store the name of Fr controller for future usage
            [!VAR "FrController" = "node:path(.)"!][!//Store the path to the Fr controller for future comparisons
            [!WS "0"!][!//Store the reference to the multiple cluster using this FrController
            [!VAR "FrControllersUsage" = "node:path(node:refs('ASPathDataOfSchema:/AUTOSAR/EcucDefs/FrIf/FrIfConfig/FrIfCluster/FrIfController/FrIfFrCtrlRef')[node:path(node:ref(.)) = node:path(node:current())]/..)"!][!//Store the path of the controllers cluster for further accesses
            [!WS "0"!][!//No ambiguous configuration detected, proceed with checks of configuration parameters
            [!WS "0"!][!//to simplify further accesses put the FrIfCluster using the current FrController into a variable
            [!VAR "FrControllersCluster" = "node:path(node:ref($FrControllersUsage)/../..)"!]
            [!WS "0"!]/******************************************************************************
            [!WS "0"!]*  Configuration for
            [!WS "0"!]*  Fr:
            [!WS "0"!]*  FrMultipleConfiguration container  '[!"as:name(../..)"!][!"$postBuildVariantName"!]'
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
            [!IF "text:tolower(node:value(../../../FrGeneral/FrPrepareLPduSupport)) = 'true'"!]
                [!IF "($NeededBuffers > 8) or ('true' = text:tolower(VendorSpecific/ForceReconfiguration))"!]
                    [!INFO!]
                        [!WS "0"!]Starting reconfiguration. [!CR!]Buffers available: [!"num:i(256)"!] [!CR!]Buffers needed: [!"num:i($NeededBuffers)"!] [!CR!]Buffers available for reconfiguration: [!"num:i($ReconfigurableBuffers)"!]
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
                    [!IF "(256 + $NumberOfSlaveShared + $NumberOfSlaveSharedDynamic) < $NeededBuffers"!]
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
                [!IF "$NeededBuffers > 256"!]
                    [!ERROR!]
                        [!WS "0"!]Error 035: Not enough resources for all LPdus, try enable the parameter FrPrepareLPduSupport which enables API function Fr_43_LLCE_PrepareLPdu(), so more than one LPdu can share one Message Buf
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
            [!VAR "NumberOfNonFifoMacs" = "num:i(0)"!]
            [!CALL "GetNonFifoMacs", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots"!]
            [!CALL "PSRRegisters", "CfgIdx" = "$FrConfigIdx", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)"!]
            [!CALL "LPduInfoCfg", "CfgVariant" = "string('PB')", "FrIfCluster" = "$FrControllersCluster", "FrController" = "node:path(.)", "FIFOASlots" = "$OutFIFOASlots", "FIFOBSlots" = "$OutFIFOBSlots", "Reconfigurations" = "$Reconfigurations", "ReconfigurationsDynamic" = "$ReconfigurationsDynamic"!]
            [!IF "../../../FrGeneral/VendorSpecific/FrDisableDemReportErrorStatus = 'false'"!]
                [!WS "0"!]/* This structure  holds information about reported DEM errors */
                [!WS "0"!]static const Fr_43_LLCE_DemErrorType Fr_43_LLCEMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref(node:path(.))/FrCtrlIdx)"!]_DemEventParameter_[!"string($CfgVariant)"!] =
                [!WS "0"!]{
                [!IF "node:exists(FrControllerDemEventParameterRefs/FR_E_CTRL_TESTRESULT)"!]
                    [!IF "node:refvalid(./FrControllerDemEventParameterRefs/FR_E_CTRL_TESTRESULT) = 'true'"!]
                        [!WS "4"!](uint32)STD_ON, /* DEM reporting is enabled */
                        [!WS "4"!]DemConf_DemEventParameter_[!"node:name(node:ref(FrControllerDemEventParameterRefs/FR_E_CTRL_TESTRESULT))"!] /* DEM ID */
                    [!ELSE!]
                        [!ERROR!]
                            [!WS "0"!]Error 037: The controller [!"node:name(../..)"!]/[!"node:name(.)"!]/FrControllerDemEventParameterRefs/FR_E_CTRL_TESTRESULT has no reference to DemEventID.
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ELSE!]
                    [!WS "4"!](uint32)STD_OFF, /* DEM reporting is inhibited */
                    [!WS "4"!]0U /* DEM ID is not assigned */
                [!ENDIF!]
                [!WS "0"!]};
                [!WS "0"!][!CR!]
            [!ENDIF!]
        [!ENDLOOP!][!//FrController
        [!VAR "CtrlConfigCount" = "num:i(count(./FrController/*))"!]
        [!VAR "Comma" = "''"!]
        [!LOOP "node:order(./FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
            [!VAR "FrController" = "node:path(.)"!][!//Store the path to the Fr controller for future comparisons
            [!VAR "CtrlIdx" = "num:i(node:value(./FrCtrlIdx))"!]
            [!WS "0"!][!//Store the reference to the multiple cluster using this FrController
            [!VAR "FrControllersUsage" = "node:path(node:refs('ASPathDataOfSchema:/AUTOSAR/EcucDefs/FrIf/FrIfConfig/FrIfCluster/FrIfController/FrIfFrCtrlRef')[node:path(node:ref(.)) = node:path(node:current())]/..)"!][!//Store the path of the controllers cluster for further accesses
            [!SELECT "node:ref($FrControllersUsage)/../../../.."!]
                [!VAR "FrIfConfigIndex" = "position()"!]
            [!ENDSELECT!]
            [!WS "0"!]/* This structure all information about controller [!"$CtrlIdx"!] */
            [!WS "0"!]static const Fr_43_LLCE_CtrlCfgType Fr_Controller_[!"$CtrlIdx"!] =
            [!WS "0"!]{
            [!WS "4"!][!"$CtrlIdx"!]U,
            [!WS "4"!]&Fr_43_LLCE_MC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_Cfg_[!"string($CfgVariant)"!][!"$postBuildVariantName"!],
            [!WS "4"!]&Fr_43_LLCE_MC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_StateAlloc_[!"string($CfgVariant)"!][!"$postBuildVariantName"!],
            [!SELECT "node:ref($FrControllersUsage)/.."!]
                [!VAR "FrIfController" = "node:path(.)"!]
            [!ENDSELECT!]
            [!SELECT "(node:ref($FrIfController)/*[node:ref(FrIfFrCtrlRef)=node:ref($FrController)])"!]
                [!IF "$FrController = node:path(node:ref(FrIfFrCtrlRef))"!]
                    [!WS "4"!][!"num:i(count(FrIfLPdu/*))"!]U,
                [!ENDIF!]
            [!ENDSELECT!]
            [!SELECT "node:ref($FrControllersUsage)/../.."!]
                [!VAR "FrIfCurrentCluster" = "node:path(.)"!]
            [!ENDSELECT!]
            [!WS "4"!]FrIfMC[!"$FrIfConfigIndex"!]_Clst[!"num:i(node:ref($FrIfCurrentCluster)/FrIfClstIdx)"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_LPduInfoCfgSet_[!"string($CfgVariant)"!],
            [!WS "4"!]&Fr_43_LLCEMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref(node:path(.))/FrCtrlIdx)"!]_CCLowLevelCfgSet_[!"string($CfgVariant)"!],
            [!WS "4"!]Fr_43_LLCEMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_CCReadBackParamSet_[!"string($CfgVariant)"!],
            [!IF "../../../FrGeneral/VendorSpecific/FrDisableDemReportErrorStatus = 'false'"!]
                [!WS "4"!]&Fr_43_LLCEMC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref(node:path(.))/FrCtrlIdx)"!]_DemEventParameter_[!"string($CfgVariant)"!]
            [!ELSE!]
                [!WS "4"!]NULL_PTR
            [!ENDIF!]
            [!WS "0"!]};
            [!WS "0"!][!CR!]
        [!ENDLOOP!][!//FrController
        [!VAR "MaxCoreIdConfig" = "num:i(count(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*))"!]
        [!VAR "CtrlConfigCount" = "num:i(count(./FrController/*))"!]
        [!IF "num:i(count(../FrGeneral/FrEcucPartitionRef/*)) = '0'"!]
            [!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
                [!WS "0"!]/* This structure puts together all information about controllers for Fr_43_LLCE_Config[!"$postBuildVariantName"!][!WS "1"!] multiple configuration */
                [!WS "0"!]const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config[!"$postBuildVariantName"!] =
            [!ELSE!]
                [!WS "0"!]/* This structure puts together all information about controllers for Fr_43_LLCE_Config multiple configuration */
                [!WS "0"!]static const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config =
            [!ENDIF!]
            [!WS "0"!]{
                [!WS "4"!]{
            [!LOOP "node:order(./FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
                [!VAR "FrController" = "node:path(.)"!][!//Store the path to the Fr controller for future comparisons
                [!VAR "CtrlIdx" = "num:i(node:value(./FrCtrlIdx))"!]
                [!WS "0"!][!//Store the reference to the multiple cluster using this FrController
                [!VAR "FrControllersUsage" = "node:path(node:refs('ASPathDataOfSchema:/AUTOSAR/EcucDefs/FrIf/FrIfConfig/FrIfCluster/FrIfController/FrIfFrCtrlRef')[node:path(node:ref(.)) = node:path(node:current())]/..)"!][!//Store the path of the controllers cluster for further accesses
                [!SELECT "node:ref($FrControllersUsage)/../../../.."!]
                    [!VAR "FrIfConfigIndex" = "position()"!]
                [!ENDSELECT!]
                [!WS "8"!]&Fr_Controller_[!"$CtrlIdx"!][!IF "($CtrlIdx + 1) < $CtrlConfigCount"!],[!ENDIF!][!CR!]
            [!ENDLOOP!][!//FrController
                [!WS "4"!]},
                [!WS "4"!]0U
            [!WS "0"!]};
            [!WS "0"!][!CR!]
        [!ELSE!]
            [!LOOP "../FrGeneral/FrEcucPartitionRef/*"!]
                [!VAR "FrPartitionPath" = "node:value(.)"!]
                [!IF "((../../../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../../../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
                    [!WS "0"!]/* This structure puts together all information about controllers for Fr_43_LLCE_Config[!"$postBuildVariantName"!]_[!"node:ref(.)/@name"!][!WS "1"!] multiple configuration */
                    [!WS "0"!]const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config[!"$postBuildVariantName"!]_[!"node:ref(.)/@name"!] =
                [!ELSE!]
                    [!WS "0"!]/* This structure puts together all information about controllers for Fr_43_LLCE_Config_[!"node:ref(.)/@name"!][!WS "1"!] multiple configuration */
                    [!WS "0"!]static const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config_[!"node:ref(.)/@name"!] =
                [!ENDIF!]
                [!WS "0"!]{
                    [!WS "4"!]{
                [!LOOP "node:order(../../../FrMultipleConfiguration/FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
                    [!VAR "FrController" = "node:path(.)"!][!//Store the path to the Fr controller for future comparisons
                    [!VAR "CtrlIdx" = "num:i(node:value(./FrCtrlIdx))"!]
                    [!WS "0"!][!//Store the reference to the multiple cluster using this FrController
                    [!VAR "FrControllersUsage" = "node:path(node:refs('ASPathDataOfSchema:/AUTOSAR/EcucDefs/FrIf/FrIfConfig/FrIfCluster/FrIfController/FrIfFrCtrlRef')[node:path(node:ref(.)) = node:path(node:current())]/..)"!][!//Store the path of the controllers cluster for further accesses
                    [!SELECT "node:ref($FrControllersUsage)/../../../.."!]
                        [!VAR "FrIfConfigIndex" = "position()"!]
                    [!ENDSELECT!]
                    [!VAR "CheckCoreId" = "'false'"!]
                    [!VAR "CheckCoreIdIndex" = "'0'"!]
                    [!VAR "FrCtlPartitionPath" = "node:value(./FrCtrlEcucPartitionRef)"!]
                    [!IF "$FrCtlPartitionPath = $FrPartitionPath"!]
                        [!LOOP "node:order(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*, './EcucCoreId')"!]
                            [!VAR "CoreId" = "node:value(./EcucCoreId)"!]
                            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                                [!IF "$CoreId = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                                    [!IF "$FrCtlPartitionPath = node:value(./OsAppEcucPartitionRef)"!]
                                        [!VAR "CheckCoreId" = "'true'"!]
                                        [!VAR "CheckCoreIdIndex" = "$CoreId"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDLOOP!]
                        [!IF "$CheckCoreId = 'true'"!]
                            [!WS "8"!]&Fr_Controller_[!"$CtrlIdx"!][!IF "($CtrlIdx + 1) < $CtrlConfigCount"!],[!ENDIF!][!CR!]
                        [!ELSE!]
                            [!WS "8"!]NULL_PTR[!IF "($CtrlIdx + 1) < $CtrlConfigCount"!],[!ENDIF!][!CR!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!WS "8"!]NULL_PTR[!IF "($CtrlIdx + 1) < $CtrlConfigCount"!],[!ENDIF!][!CR!]
                    [!ENDIF!]
                [!ENDLOOP!][!//FrController
                    [!WS "4"!]},
                [!IF "$CheckCoreId = 'false'"!]
                    [!CR!][!WS "4"!]0U
                [!ELSE!]
                    [!CR!][!WS "4"!][!"$CheckCoreIdIndex"!]U
                [!ENDIF!]
                [!WS "0"!]};
                [!WS "0"!][!CR!]
            [!ENDLOOP!][!//FrEcucPartitionRef
        [!ENDIF!]
        [!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
        [!ELSE!]
            [!WS "0"!]/* This structure puts together all information about controllers for Fr_43_LLCE_PBCfgVariantPredefined multiple configuration */
            [!VAR "Fr_PartitionRefCount" = "0"!]
            [!VAR "EcuC_EcucPartitionConfigCount" = "0"!]
            [!IF "node:exists(../FrGeneral/FrEcucPartitionRef/*)"!]
                [!VAR "Fr_PartitionRefCount" = "num:i(count(node:ref(../FrGeneral/FrEcucPartitionRef/*[1])/../*))"!]
                [!VAR "EcuC_EcucPartitionConfigCount" = "num:i(count(node:ref(../FrGeneral/FrEcucPartitionRef/*[1])/../*))"!]
            [!ENDIF!]
            [!WS "0"!]const Fr_43_LLCE_ConfigurationType* Fr_43_LLCE_PBCfgVariantPredefined[FR_43_LLCE_ECUC_PARTITION] =
            [!WS "0"!]{
            [!IF "num:i(count(../FrGeneral/FrEcucPartitionRef/*)) = '0'"!]
                [!WS "4"!]&Fr_43_LLCE_Config
            [!ELSE!]
                [!VAR "coreIdx" = "0"!]
                [!LOOP "node:order(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*, './EcucCoreId')"!]
                    [!VAR "coreIdx" = "$coreIdx + 1"!]
                    [!VAR "CoreId" = "node:value(./EcucCoreId)"!]
                    [!VAR "FrPartShortName" = "''"!]
                    [!VAR "FrPartMatchCounter" = "0"!]
                    [!VAR "OsAppPart" = "''"!]
                    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                        [!IF "$CoreId = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                            [!VAR "OsAppPart" = "node:value(./OsAppEcucPartitionRef)"!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                    [!LOOP "as:modconf('Fr')[1]/FrGeneral/FrEcucPartitionRef/*"!]
                        [!IF "$OsAppPart = node:value(.)"!]
                            [!VAR "Fr_Partition_name" = "node:ref(.)/@name"!]
                            [!VAR "FrPartMatchCounter" = "$FrPartMatchCounter + 1"!]
                            [!VAR "FrPartShortName" = "substring-after(substring-after(., 'EcuC/EcuC/'), '/')"!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                    [!WS "4"!][!IF "$FrPartMatchCounter = 1"!]&Fr_43_LLCE_Config_[!"$Fr_Partition_name"!][!ELSE!]NULL_PTR[!ENDIF!][!IF "$coreIdx < $MaxCoreIdConfig"!],[!ENDIF!][!CR!]
                [!ENDLOOP!]
            [!ENDIF!]
            [!WS "0"!]};
            [!WS "0"!][!CR!]
        [!ENDIF!]
    [!ENDLOOP!][!//FrMultipleConfiguration
#define FR_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_43_LLCE_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */


[!ENDCODE!]
