[!NOCODE!]
/**
    @file    Power_Ip_RegOperations.m
    @version 4.0.2

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.4
    Platform CORTEXM
    Peripheral 
    Dependencies none

    ARVersion 4.4.0
    ARRevision ASR_REL_4_4_REV_0000
    ARConfVariant
    SWVersion 4.0.2
    BuildVersion S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630

    (c) Copyright 2020-2023 NXP Semiconductors
    All Rights Reserved.
 */


[!MACRO "NumberOfCores", "ParamPrtnIndex"!][!//
    [!VAR "ResourceName" = "concat('MCU.MC_ME.Partition', $ParamPrtnIndex, '.Cores.List')"!]
    [!VAR "Count" = "num:i(count(ecu:list($ResourceName)))"!]
    [!"$Count"!]
[!ENDMACRO!][!//NumberOfCores


[!MACRO "Power_Ip_LinkerSymbols","Type"!][!//
[!NOCODE!][!//
    [!VAR "SymbolTable" = "''"!]
    [!VAR "NumOfPartitions" = "count(ecu:list('MCU.Partitions.List'))"!]
    [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
        [!FOR "PartitionCounter" = "1" TO "$NumOfPartitions"!]
            [!VAR "PartitionEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($PartitionCounter)], 'Partition'))"!]
            [!VAR "CurrentPartitionPrefixStr" = "concat('McuPartitionConfiguration/McuPartition', $PartitionEffectiveIndex, 'Config')"!]
            [!SELECT "node:ref($CurrentPartitionPrefixStr)"!]
                [!VAR "PartitionCoresListResName" = "concat('MCU.MC_ME.Partition', $PartitionEffectiveIndex ,'.Cores.List')"!]
                [!VAR "NumOfCoresInPartition" = "count(ecu:list($PartitionCoresListResName))"!]
                [!FOR "CoreCounter" = "1" TO "$NumOfCoresInPartition"!]
                    [!VAR "CurrentCoreEffectiveIndex" = "substring-after(ecu:list($PartitionCoresListResName)[num:i($CoreCounter)], 'CORE_')"!]
                    [!VAR "CurrentCorePrefixStr" = "concat('McuCore', $CurrentCoreEffectiveIndex, 'Configuration')"!]
                    [!SELECT "node:ref($CurrentCorePrefixStr)"!]
                        [!IF "node:exists(McuCoreBootAddressLinkerSym) and (McuCoreBootAddressLinkerSym != '')"!]
                            [!VAR "Extern_Core_BAL" = "concat('extern uint32 ', McuCoreBootAddressLinkerSym, '[1U];')"!]
                            [!IF "not(text:contains(text:split($SymbolTable), McuCoreBootAddressLinkerSym))"!]
[!CODE!][!//
[!"$Extern_Core_BAL"!]
[!ENDCODE!][!//
                            [!VAR "SymbolTable" = "concat($SymbolTable, ' ', McuCoreBootAddressLinkerSym)"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDSELECT!][!//node:ref($CurrentCorePrefixStr)
                [!ENDFOR!][!//CoreCounter
            [!ENDSELECT!][!//node:ref($CurrentPartitionPrefixStr)
        [!ENDFOR!][!//PartitionCounter
    [!ENDLOOP!][!//McuModuleConfiguration/McuModeSettingConf/*
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Power_Ip_MC_ME_Core_Config","Type"!][!//
[!NOCODE!]
    [!VAR "Mac_NumOfPartitions" = "count(ecu:list('MCU.Partitions.List'))"!]
    [!FOR "PartitionCounter" = "1" TO "$Mac_NumOfPartitions"!]
        [!VAR "Mac_PartitionEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($PartitionCounter)], 'Partition'))"!]
        [!VAR "Mac_CurrentPartitionPrefixStr" = "concat('McuPartition', $Mac_PartitionEffectiveIndex, 'Config')"!]
        [!VAR "Mac_CoreResourcePath" = "concat('MCU.MC_ME.Partition', $Mac_PartitionEffectiveIndex, '.Cores.List')"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "Mac_ModeConfigIndex" = "@index"!]
            [!VAR "Mac_NumOfCores"!][!CALL "NumberOfCores", "ParamPrtnIndex" = "$Mac_PartitionEffectiveIndex"!][!ENDVAR!]
            [!IF "num:i($Mac_NumOfCores) > 0"!]
                [!VAR "Mac_FirstCore" = "1"!]
[!CODE!][!//
static const Power_Ip_MC_ME_CoreConfigType Power_Ip_MC_ME_aPartition[!"$Mac_PartitionEffectiveIndex"!]CoreConfig[!"$Type"!]_[!"num:i($Mac_ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($Mac_NumOfCores)"!]U] =
{
[!ENDCODE!]
    [!LOOP "./McuPartitionConfiguration/*"!]
        [!IF "contains(@name, $Mac_CurrentPartitionPrefixStr)"!]
            [!FOR "CoreCounter" = "1" TO "$Mac_NumOfCores"!]
                [!VAR "Mac_CoreEffectiveIndex" = "num:i(substring-after(ecu:list($Mac_CoreResourcePath)[number($CoreCounter)], 'CORE_'))"!]
                [!VAR "Mac_CurrentCorePrefixStr" = "concat('McuCore', $Mac_CoreEffectiveIndex, 'Configuration')"!]
                [!LOOP "./*"!]
                    [!IF "contains(@name, $Mac_CurrentCorePrefixStr) = 'true'"!]
                        [!VAR "Mac_CoreUnderMcuCtr"    = "node:value(McuCoreUnderMcuControl)"!]
                        [!VAR "Mac_CoreBootAddress"    = "node:value(McuCoreBootAddress)"!]
                        [!VAR "Mac_CoreBootAddressSym" = "node:value(McuCoreBootAddressLinkerSym)"!]
                        [!IF "$Mac_PartitionEffectiveIndex = num:i(1)"!]
                            [!IF "$Mac_CoreEffectiveIndex = num:i(1) or $Mac_CoreEffectiveIndex = num:i(4) or $Mac_CoreEffectiveIndex = num:i(5)"!]
                                [!VAR "Mac_CoreClockEnable"    = "node:value(../McuCore0Configuration/McuCoreClockEnable)"!]
                            [!ELSEIF "$Mac_CoreEffectiveIndex = num:i(3) or $Mac_CoreEffectiveIndex = num:i(6) or $Mac_CoreEffectiveIndex = num:i(7)"!]
                                [!VAR "Mac_CoreClockEnable"    = "node:value(../McuCore2Configuration/McuCoreClockEnable)"!]
                            [!ELSE!]
                                [!VAR "Mac_CoreClockEnable"    = "node:value(McuCoreClockEnable)"!]
                            [!ENDIF!]
                        [!ELSE!]
                            [!VAR "Mac_CoreClockEnable"    = "node:value(McuCoreClockEnable)"!]
                        [!ENDIF!]
[!CODE!][!//
[!IF "num:i($Mac_FirstCore)=0"!],[!ENDIF!][!VAR "Mac_FirstCore"="0"!]
    /* The configuration structure for Partition [!"$Mac_PartitionEffectiveIndex"!] Core [!"$Mac_CoreEffectiveIndex"!]. */
    {
        /* Specifies whether the given core is under MCU control. */
        [!IF "text:tolower($Mac_CoreUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* The index of the core within the partition. */
        (uint8)[!"num:i($Mac_CoreEffectiveIndex)"!]U,

        /* The boot address of the core. */
        (uint32 *)[!IF "$Mac_CoreBootAddressSym = ''"!][!"num:inttohex($Mac_CoreBootAddress,8)"!]U[!ELSE!][!"$Mac_CoreBootAddressSym"!][!ENDIF!],

        /* The process configuration register value of the core. */
        MC_ME_PRTN[!"$Mac_PartitionEffectiveIndex"!]_CORE[!"num:i($Mac_CoreEffectiveIndex)"!]_PCONF_CCE
        (
            [!IF "text:tolower($Mac_CoreClockEnable) = 'true'"!]MC_ME_PRTNX_COREX_PCONF_CCE_EN_U32[!ELSE!]MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32[!ENDIF!]
        )
    }[!//
[!ENDCODE!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDFOR!][!//CoreCounter
        [!ENDIF!]
    [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
            [!ENDIF!][!//num:i($Mac_NumOfCores) > 0
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDFOR!][!//PartitionCounter
[!ENDNOCODE!]
[!ENDMACRO!][!//Power_Ip_MC_ME_Core_Config


[!MACRO "NumberOfCofbs", "ParamPrtnIndex"!][!//
    [!VAR "ResourceName" = "concat('MCU.MC_ME.Partition', $ParamPrtnIndex, '.COFBs.List')"!]
    [!VAR "Count" = "num:i(count(ecu:list($ResourceName)))"!]
    [!"$Count"!]
[!ENDMACRO!][!//NumberOfCofbs


[!MACRO "GetEnabledPeripherals","ParamPrtnIndex","ParamCofbIndex"!][!//
[!NOCODE!]
    [!CODE!]((uint32)0x00000000U)[!ENDCODE!]
    [!LOOP "../McuPeripheral/*"!]
        [!IF "text:toupper(McuModeEntrySlot) != 'NONE'"!]
            [!VAR "PrtnIndex" = "num:i(substring(McuModeEntrySlot, (string-length('PRTN') + 1), 1))"!]
            [!IF "num:i($PrtnIndex) = num:i($ParamPrtnIndex)"!]
                [!VAR "CofbIndex" = "num:i(substring(McuModeEntrySlot, (string-length(concat('PRTN', num:i($ParamPrtnIndex), '_COFB')) + 1), 1))"!]
                [!IF "num:i($CofbIndex) = num:i($ParamCofbIndex)"!]
                    [!VAR "ReqIndex" = "num:i(substring-after(McuModeEntrySlot, concat('PRTN', num:i($ParamPrtnIndex), '_COFB', num:i($ParamCofbIndex), '_REQ')))"!]
                    [!IF "McuPeripheralClockEnable = 'true'"!]
                [!CODE!] | MC_ME_PRTN[!"$PrtnIndex"!]_COFB[!"$CofbIndex"!]_CLKEN_REQ[!"$ReqIndex"!]_MASK[!ENDCODE!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_MC_ME_COFB_Config","Type"!][!//
[!NOCODE!]
    [!VAR "NumOfPartitions" = "count(ecu:list('MCU.Partitions.List'))"!]
    [!FOR "PartitionCounter" = "1" TO "$NumOfPartitions"!]
        [!VAR "PartitionEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($PartitionCounter)], 'Partition'))"!]
        [!VAR "CurrentPartitionPrefixStr" = "concat('McuPartition', num:i($PartitionEffectiveIndex), 'Config')"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "ModeConfigIndex" = "@index"!]
            [!VAR "NumOfCofbs"!][!CALL "NumberOfCofbs", "ParamPrtnIndex" = "num:i($PartitionEffectiveIndex)"!][!ENDVAR!]
            [!IF "num:i($NumOfCofbs) > 0"!]
                [!VAR "FirstCofb" = "1"!]
[!CODE!]
static const Power_Ip_MC_ME_CofbConfigType Power_Ip_MC_ME_aPartition[!"$PartitionEffectiveIndex"!]CofbConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfCofbs)"!]U] =
{
[!ENDCODE!]
    [!LOOP "./McuPartitionConfiguration/*"!]
        [!IF "contains(@name, $CurrentPartitionPrefixStr)"!]
            [!FOR "CofbCounter" = "1" TO "$NumOfCofbs"!]
                [!VAR "CurrentPrtnCofbListResName" = "concat('MCU.MC_ME.Partition', $PartitionEffectiveIndex, '.COFBs.List')"!]
                [!VAR "CofbEffectiveIndex" = "num:i(substring-after(ecu:list($CurrentPrtnCofbListResName)[number($CofbCounter)], 'COFB_'))"!]
                [!VAR "CofbUnderMcuCtr"    = "node:value(concat('McuPrtnCofb', $CofbEffectiveIndex, 'UnderMcuControl'))"!]
[!CODE!][!//
[!IF "num:i($FirstCofb)=0"!],[!ENDIF!][!VAR "FirstCofb"="0"!]
    /* The configuration structure for Partition [!"$PartitionEffectiveIndex"!] COFB [!"$CofbEffectiveIndex"!]. */
    {
        /* Specifies whether the given COFB set is under MCU control. */
        [!IF "text:tolower($CofbUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* The index of the COFB set within the partition. */
        (uint8)[!"num:i($CofbEffectiveIndex)"!]U,

        /* The clock enable register value of the COFB set. */
        MC_ME_PRTN[!"$PartitionEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN
        (
            [!CALL "GetEnabledPeripherals", "ParamPrtnIndex" = "$PartitionEffectiveIndex", "ParamCofbIndex" = "$CofbEffectiveIndex"!][!//
        ),

        /* Mask containing the COFB blocks to be updated. */
        MC_ME_PRTN[!"$PartitionEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN_RWBITS_MASK
    }
[!ENDCODE!]
            [!ENDFOR!]
        [!ENDIF!]
    [!ENDLOOP!]
[!CODE!][!//
};
[!ENDCODE!]
            [!ENDIF!][!//num:i($NumOfCofbs) > 0
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDFOR!][!//PartitionCounter
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_MC_ME_Partition_Config","Type"!][!//
[!NOCODE!]
    [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
        [!VAR "ModeConfigIndex" = "@index"!]
        [!VAR "NumOfPartitions" = "count(ecu:list('MCU.Partitions.List'))"!]
        [!VAR "FirstPartition" = "1"!]
[!CODE!][!//
static const Power_Ip_MC_ME_PartitionConfigType Power_Ip_MC_ME_aPartitionConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfPartitions)"!]U] =
{
[!ENDCODE!]
    [!FOR "PartitionCounter" = "1" TO "$NumOfPartitions"!]
        [!VAR "PartitionEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($PartitionCounter)], 'Partition'))"!]
        [!VAR "NumOfCofbs"!][!CALL "NumberOfCofbs", "ParamPrtnIndex" = "num:i($PartitionEffectiveIndex)"!][!ENDVAR!]
        [!VAR "NumOfCores"!][!CALL "NumberOfCores", "ParamPrtnIndex" = "num:i($PartitionEffectiveIndex)"!][!ENDVAR!]
        [!VAR "PartitionUnderMcuCtr"      = "node:value(concat('McuPartitionConfiguration/McuPartition', $PartitionEffectiveIndex, 'Config/McuPartitionUnderMcuControl'))"!]
        [!VAR "PartitionPowerUnderMcuCtr" = "node:value(concat('McuPartitionConfiguration/McuPartition', $PartitionEffectiveIndex, 'Config/McuPartitionPowerUnderMcuControl'))"!]
        [!VAR "PartitionClockEnable"      = "node:value(concat('McuPartitionConfiguration/McuPartition', $PartitionEffectiveIndex, 'Config/McuPartitionClockEnable'))"!]
[!CODE!][!//
[!IF "num:i($FirstPartition)=0"!],[!ENDIF!][!VAR "FirstPartition"="0"!]
    /* The configuration structure for Partition [!"$PartitionEffectiveIndex"!]. */
    {
        /* Specifies whether the given partition is under MCU control. */
        [!IF "text:tolower($PartitionUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* Specifies whether the given partition's power management is under MCU control. */
        [!IF "text:tolower($PartitionPowerUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* Partition Index */
        (uint8)[!"num:i($PartitionEffectiveIndex)"!]U,

        /* The process configuration register value of the partition. */
        (
            [!IF "text:tolower(ecu:get('MCU.MC_ME.HasOutputSafeState')) = 'true'"!]
            [!IF "text:tolower($PartitionClockEnable) = 'true'"!]MC_ME_PRTNX_PCONF_PCE_EN_U32[!ELSE!]MC_ME_PRTNX_PCONF_PCE_DIS_U32[!ENDIF!] |

            [!IF "text:tolower($PartitionClockEnable) = 'true'"!]MC_ME_PRTNX_PCONF_OSSE_DIS_U32[!ELSE!]MC_ME_PRTNX_PCONF_OSSE_EN_U32[!ENDIF!]
            [!ELSE!]
            [!IF "text:tolower($PartitionClockEnable) = 'true'"!]MC_ME_PRTNX_PCONF_PCE_EN_U32[!ELSE!]MC_ME_PRTNX_PCONF_PCE_DIS_U32[!ENDIF!]
            [!ENDIF!]
        ),

        /* Mask containing the Partition triggers (PCE/OSSE/etc) to be updated. */
        MC_ME_PRTN[!"$PartitionEffectiveIndex"!]_PUPD_RWBITS_MASK,

        /* Number of COFBs within Partition [!"num:i($PartitionEffectiveIndex)"!] */
        (uint8)[!"num:i($NumOfCofbs)"!]U,
        /* Configuration for the COFBs within Partition [!"num:i($PartitionEffectiveIndex)"!]. */
        [!IF "num:i($NumOfCofbs) != 0"!]&Power_Ip_MC_ME_aPartition[!"$PartitionEffectiveIndex"!]CofbConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!](NULL_PTR)[!ENDIF!],

        /* Number of Cores within Partition [!"num:i($PartitionEffectiveIndex)"!] */
        (uint8)[!"num:i($NumOfCores)"!]U,
        /* Configuration for the Cores within Partition [!"num:i($PartitionEffectiveIndex)"!]. */
        [!IF "num:i($NumOfCores) != 0"!]&Power_Ip_MC_ME_aPartition[!"$PartitionEffectiveIndex"!]CoreConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!](NULL_PTR)[!ENDIF!]
    }[!//
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]
    [!ENDLOOP!][!//McuModeSettingConf/*
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Power_Ip_MC_ME_Mode_Config","Type"!][!//
[!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!][!//
[!NOCODE!][!//
[!CODE!][!//
/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
static const Power_Ip_MC_ME_ModeConfigType Power_Ip_MC_ME_ModeConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
#if (defined(POWER_IP_RESET_DURING_STANDBY_SUPPORTED))
  #if (POWER_IP_RESET_DURING_STANDBY_SUPPORTED == STD_ON)
    #if (defined(POWER_IP_ENTER_LOW_POWER_MODE) && (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON))
    /* MC_ME Main Core ID register */
    MC_ME_MAIN_COREID_U32
    (
[!IF "McuPowerMode = 'SOC_STANDBY'"!][!//
        MC_ME_MAIN_COREID_PIDX_[!"McuMainCoreSelect"!]_U32 |
        MC_ME_MAIN_COREID_CIDX_[!"McuMainCoreSelect"!]_U32
[!ELSE!][!//
        MC_ME_MAIN_COREID_NOT_USED_U32
[!ENDIF!][!//
    ),
    #endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
  #endif
#endif
    /* MC_ME Mode Partition Settings. */
    &Power_Ip_MC_ME_aPartitionConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDLOOP!][!//McuModeSettingConf/*
[!ENDMACRO!][!//

[!MACRO "Power_Ip_MC_RGM_Core_Config","Type"!][!//
[!NOCODE!]
    [!VAR "NumOfDomains" = "count(ecu:list('MCU.Partitions.List'))"!]
    [!FOR "DomainCounter" = "1" TO "$NumOfDomains"!]
        [!VAR "DomainEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($DomainCounter)], 'Partition'))"!]
        [!VAR "CurrentDomainPrefixStr" = "concat('McuPartition', $DomainEffectiveIndex, 'Config')"!]
        [!VAR "Mac_CoreResourcePath" = "concat('MCU.MC_ME.Partition', $DomainEffectiveIndex, '.Cores.List')"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "ModeConfigIndex" = "@index"!]
            [!VAR "NumOfCores"!][!CALL "NumberOfCores", "ParamPrtnIndex" = "$DomainEffectiveIndex"!][!ENDVAR!]
            [!IF "num:i($NumOfCores) > 0"!]
                [!VAR "FirstCore" = "1"!]
[!CODE!]
static const Power_Ip_MC_RGM_CoreConfigType Power_Ip_MC_RGM_aDomain[!"$DomainEffectiveIndex"!]CoreConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfCores)"!]U] =
{
[!ENDCODE!]
    [!LOOP "./McuPartitionConfiguration/*"!]
        [!IF "contains(@name, $CurrentDomainPrefixStr)"!]
            [!FOR "CoreCounter" = "1" TO "$NumOfCores"!]
                [!VAR "Mac_CoreEffectiveIndex" = "num:i(substring-after(ecu:list($Mac_CoreResourcePath)[number($CoreCounter)], 'CORE_'))"!]
                [!VAR "Mac_CurrentCorePrefixStr" = "concat('McuCore', $Mac_CoreEffectiveIndex, 'Configuration')"!]
                [!LOOP "./*"!]
                    [!IF "contains(@name, $Mac_CurrentCorePrefixStr) = 'true'"!]
                        [!VAR "CoreUnderMcuCtr"    = "node:value(McuCoreUnderMcuControl)"!]
                        [!VAR "CoreResetEnable"    = "node:value(McuCoreResetEnable)"!]
[!CODE!][!//
    [!IF "num:i($FirstCore)=0"!],[!ENDIF!][!VAR "FirstCore"="0"!]
    /* The configuration structure for Domain [!"$DomainEffectiveIndex"!] Core [!"$Mac_CoreEffectiveIndex"!]. */
    {
        /* Specifies whether the given core is under MCU control. */
        [!IF "text:tolower($CoreUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* The index of the core within the domain. */
        (uint8)[!"num:i($Mac_CoreEffectiveIndex)"!]U,
[!NOCODE!][!//
    [!IF "$DomainEffectiveIndex = num:i(0) and $Mac_CoreEffectiveIndex = num:i(4)"!]
        [!VAR "Mac_CoreEffectiveIndex" = "num:i(6)"!]
    [!ENDIF!]
[!ENDNOCODE!]
        /* The reset enable register value of the core. */
        MC_RGM_PRST[!"$DomainEffectiveIndex"!]_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            [!IF "text:tolower($CoreResetEnable) = 'true'"!]| MC_RGM_PRST[!"$DomainEffectiveIndex"!]_COFB0_RSTEN_CORES_MASK([!"$Mac_CoreEffectiveIndex"!]U)[!ENDIF!]
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST[!"$DomainEffectiveIndex"!]_COFB0_RSTEN_CORES_MASK([!"$Mac_CoreEffectiveIndex"!]U)
    }
[!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDFOR!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
            [!ENDIF!][!//num:i($NumOfCores) > 0
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDFOR!][!//PartitionCounter
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "NumberOfRstCofbs", "ParamDomainIndex"!][!//
    [!VAR "ResourceName" = "concat('MCU.MC_RGM.Partition', $ParamDomainIndex, '.COFBs.List')"!][!//
    [!VAR "Count" = "num:i(count(ecu:list($ResourceName)))"!][!//
    [!"$Count"!][!//
[!ENDMACRO!][!//

[!MACRO "GetResettablePeripherals","ParamDomainIndex","ParamCofbIndex"!][!//
[!NOCODE!][!//
    [!CODE!]((uint32)0x00000000U) [!ENDCODE!][!//
    [!LOOP "../McuPeripheral/*"!][!//
        [!IF "text:toupper(McuResetGenerationSlot) != 'NONE'"!]
            [!VAR "PrstIndex" = "num:i(substring-after(McuResetGenerationSlot, 'PRST'))"!]
            [!IF "num:i($PrstIndex) = num:i($ParamDomainIndex)"!]
                [!VAR "CofbIndex" = "num:i(substring-after(McuResetGenerationSlot, concat('PRST', $ParamDomainIndex, '_COFB')))"!]
                [!IF "num:i($CofbIndex) = num:i($ParamCofbIndex)"!]
                    [!VAR "ReqIndex" = "num:i(substring-after(McuResetGenerationSlot, concat('PRST', $ParamDomainIndex, '_COFB', $ParamCofbIndex, '_PERIPH_')))"!]
                    [!//[!VAR "ReqIndex" = "num:i(num:mod($ReqIndex, 32))"!]
                    [!IF "McuPeripheralResetEnable = 'true'"!]
                [!CODE!]| MC_RGM_PRST_[!"$PrstIndex"!]_PERIPH_[!"$ReqIndex"!]_RST_MASK [!ENDCODE!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_MC_RGM_COFB_Config","Type"!][!//
[!NOCODE!][!//
    [!VAR "NumOfDomains" = "count(ecu:list('MCU.Partitions.List'))"!]
    [!FOR "DomainCounter" = "1" TO "$NumOfDomains"!]
        [!VAR "DomainEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($DomainCounter)], 'Partition'))"!]
        [!VAR "CurrentDomainPrefixStr" = "concat('McuPartition', num:i($DomainEffectiveIndex), 'Config')"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "ModeConfigIndex" = "@index"!]
            [!VAR "NumOfCofbs"!][!CALL "NumberOfRstCofbs", "ParamDomainIndex" = "num:i($DomainEffectiveIndex)"!][!ENDVAR!]
            [!IF "num:i($NumOfCofbs) > 0"!]
                [!VAR "FirstCofb" = "1"!]
[!CODE!][!//
static const Power_Ip_MC_RGM_CofbConfigType Power_Ip_MC_RGM_aDomain[!"$DomainEffectiveIndex"!]CofbConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfCofbs)"!]U] =
{
[!ENDCODE!][!//
    [!LOOP "./McuPartitionConfiguration/*"!]
        [!IF "contains(@name, $CurrentDomainPrefixStr)"!]
            [!FOR "CofbCounter" = "1" TO "$NumOfCofbs"!]
                [!VAR "CurrentDomainCofbListResName" = "concat('MCU.MC_RGM.Partition', $DomainEffectiveIndex, '.COFBs.List')"!]
                [!VAR "CofbEffectiveIndex"   = "num:i(substring-after(ecu:list($CurrentDomainCofbListResName)[number($CofbCounter)], 'COFB_'))"!]
                [!VAR "CofbUnderMcuCtr"      = "node:value(concat('McuPrstCofb', $CofbEffectiveIndex, 'UnderMcuControl'))"!]
[!CODE!][!//
    [!IF "num:i($FirstCofb)=0"!],[!ENDIF!][!VAR "FirstCofb"="0"!]
    /* The configuration structure for Domain [!"$DomainEffectiveIndex"!] COFB [!"$CofbEffectiveIndex"!] (i.e. PRST[!"$DomainEffectiveIndex"!]_[!"$CofbEffectiveIndex"!]). */
    {
        /* Specifies whether the given COFB set is under MCU control. */
        [!IF "text:tolower($CofbUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* The index of the COFB set within the domain. */
        (uint8)[!"num:i($CofbEffectiveIndex)"!]U,

        /* The reset enable register value of the COFB set. */
        MC_RGM_PRST[!"$DomainEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_RSTEN
        (
            [!CALL "GetResettablePeripherals", "ParamDomainIndex" = "$DomainEffectiveIndex", "ParamCofbIndex" = "$CofbEffectiveIndex"!][!//
        ),

        /* Mask containing the COFB blocks to be updated. */
        MC_RGM_PRST[!"$DomainEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_RSTEN_PERIPH_MASK
    }
[!ENDCODE!][!//
            [!ENDFOR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
            [!ENDIF!][!//num:i($NumOfCofbs) > 0
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDFOR!][!//DomainCounter
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Power_Ip_MC_RGM_Domain_Config","Type"!][!//
[!NOCODE!]
    [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!][!//
        [!VAR "ModeConfigIndex" = "@index"!][!//
        [!VAR "NumOfDomains" = "count(ecu:list('MCU.Partitions.List'))"!][!//
        [!VAR "FirstDomain" = "1"!][!//
[!CODE!][!//
static const Power_Ip_MC_RGM_DomainConfigType Power_Ip_MC_RGM_aDomainConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfDomains)"!]U] =
{
[!ENDCODE!]
    [!FOR "DomainCounter" = "1" TO "$NumOfDomains"!]
        [!VAR "DomainEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($DomainCounter)], 'Partition'))"!]
        [!VAR "NumOfCofbs"!][!CALL "NumberOfRstCofbs", "ParamDomainIndex" = "num:i($DomainEffectiveIndex)"!][!ENDVAR!]
        [!VAR "NumOfCores"!][!CALL "NumberOfCores", "ParamPrtnIndex" = "$DomainEffectiveIndex"!][!ENDVAR!]
        [!VAR "DomainUnderMcuCtr"      = "node:value(concat('McuPartitionConfiguration/McuPartition', $DomainEffectiveIndex, 'Config/McuPartitionUnderMcuControl'))"!]
        [!VAR "DomainPowerUnderMcuCtr" = "node:value(concat('McuPartitionConfiguration/McuPartition', $DomainEffectiveIndex, 'Config/McuPartitionPowerUnderMcuControl'))"!]
        [!VAR "PartitionResetEnable"   = "node:value(concat('McuPartitionConfiguration/McuPartition', $DomainEffectiveIndex, 'Config/McuPartitionResetEnable'))"!]
[!CODE!]
    [!IF "num:i($FirstDomain)=0"!],[!ENDIF!][!VAR "FirstDomain"="0"!]
    /* The configuration structure for Domain [!"$DomainEffectiveIndex"!]. */
    {
        /* Specifies whether the given domain is under MCU control. */
        [!IF "text:tolower($DomainUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* Specifies whether the given domain's power management is under MCU control. */
        [!IF "text:tolower($DomainPowerUnderMcuCtr) = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* Domain Index */
        (uint8)[!"num:i($DomainEffectiveIndex)"!]U,

        /* The process configuration register value of the domain. */
        [!IF "text:tolower($PartitionResetEnable) = 'false'"!]RDC_RDX_CTRL_REG_ICON_INTF_ENABLE[!ELSE!]RDC_RDX_CTRL_REG_ICON_INTF_DISABLE[!ENDIF!],

        /* Number of COFBs within Domain [!"num:i($DomainEffectiveIndex)"!] */
        (uint8)[!"num:i($NumOfCofbs)"!]U,
        /* Configuration for the COFBs within Domain [!"num:i($DomainEffectiveIndex)"!]. */
        [!IF "num:i($NumOfCofbs) != 0"!]&Power_Ip_MC_RGM_aDomain[!"$DomainEffectiveIndex"!]CofbConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!](NULL_PTR)[!ENDIF!],

        /* Number of Cores within Domain [!"num:i($DomainEffectiveIndex)"!] */
        (uint8)[!"num:i($NumOfCores)"!]U,
        /* Configuration for the Cores within Domain [!"num:i($DomainEffectiveIndex)"!]. */
        [!IF "num:i($NumOfCores) != 0"!]&Power_Ip_MC_RGM_aDomain[!"$DomainEffectiveIndex"!]CoreConfig[!"$Type"!]_[!"num:i($ModeConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!](NULL_PTR)[!ENDIF!]
    }
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]
    [!ENDLOOP!][!//McuModeSettingConf/*
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Power_Ip_MC_RGM_Mode_Config","Type"!][!//
[!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!][!//
[!NOCODE!][!//
[!CODE!][!//
/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
static const Power_Ip_MC_RGM_ModeConfigType Power_Ip_MC_RGM_ModeConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* MC_RGM Mode Domain Settings. */
    &Power_Ip_MC_RGM_aDomainConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDLOOP!][!//McuModeSettingConf/*
[!ENDMACRO!][!//

[!MACRO "Power_Ip_Mode_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/**
* @brief          Initialization mode data.
* @details        Static configuration realized by calling Mcu_SetMode() API.
*
*/
const Power_Ip_ModeConfigType Power_Ip_aModeConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]
        [!VAR "ModeConfigs"= "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))-1"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
[!CODE!][!//
    /* Start of Mcu_aModeConfig[[!"@index"!]] */
    {
[!ENDCODE!][!//
        [!VAR "PCindex" = "@index"!]
[!CODE!][!//
        /* Mode Configuration ID. */
        (Power_Ip_ModeType)[!"num:i(McuMode)"!]U,

        /* The Power Mode name (code). */
        POWER_IP_[!"McuPowerMode"!]_MODE,

        /* The Sleep On Exit configuration */
        [!IF "McuEnableSleepOnExit='true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],

        /* MC_ME IP Mode settings. */
        &Power_Ip_MC_ME_ModeConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!IF "count(ecu:list('MCU.MC_RGM.Partition0.COFBs.List')) > 0"!][!//
        /* MC_RGM IP Mode settings. */
        &Power_Ip_MC_RGM_ModeConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ENDIF!][!//
    }[!IF "$PCindex < $ModeConfigs"!],[!ENDIF!] /* End of Mcu_aModeConfig[[!"@index"!]] */
[!ENDCODE!][!//
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDIF!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//






[!MACRO "Power_Ip_MC_RGM_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for MC_RGM hardware IP.
* @details        Static configuration assigned at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_MC_RGM_ConfigType Power_Ip_MC_RGM_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
#if (POWER_IP_PERFORM_RESET_API == STD_ON)
    /* MC_ResetType: Functional vs Destructive. */
    ([!IF "McuModuleConfiguration/McuResetConfig/McuResetType = 'FunctionalReset'"!]MCU_FUNC_RESET[!ELSE!]MCU_DEST_RESET[!ENDIF!]),
#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */

[!ENDCODE!]
[!IF "num:i(count(McuModuleConfiguration/McuResetConfig/McuResetSourcesConfig/*)) != num:i(0)"!]
[!CODE!]
#if (defined(POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT) && (POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT == STD_ON))
    /* Func_ResetOpt: FERD Register Configuration. */
    (
[!ENDCODE!]
    [!LOOP "McuModuleConfiguration/McuResetConfig/McuResetSourcesConfig/*"!]
        [!VAR "ResetSource" = "substring-before( substring-after( @name,'Mcu' ),'_ResetSource' )"!]
        [!IF "node:value(McuDisableReset)"!]
[!CODE!][!//
        MC_RGM_FERD_D_[!"$ResetSource"!]_MASK |
[!ENDCODE!][!//
        [!ENDIF!]
    [!ENDLOOP!]
[!CODE!][!//
        0U
    ),
#endif /* POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT */
[!ENDCODE!]
[!ENDIF!]
[!CODE!]

    /* Func_Threshold_Reset: RGM_FRET Register Configuration. */
    MC_RGM_FRET_FRET((uint32)[!"num:i(McuModuleConfiguration/McuResetConfig/McuFuncResetEscThreshold)"!]U),

    /* Dest_Threshold_Reset: RGM_DRET Register Configuration. */
    MC_RGM_DRET_DRET((uint32)[!"num:i(McuModuleConfiguration/McuResetConfig/McuDestResetEscThreshold)"!]U)
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "GetEnabledNCSPD"!][!//
[!NOCODE!]
    [!CODE!]((uint32)0x00000000U) [!ENDCODE!]
    [!VAR "NumOfNCSPD" = "count(ecu:list('MCU.PMC.NonCriticalSPD.List'))"!]
    [!FOR "NCSPDCounter" = "1" TO "$NumOfNCSPD"!]
        [!VAR "NCSPDNode"  = "concat('Mcu', ecu:list('MCU.PMC.NonCriticalSPD.List')[num:i($NCSPDCounter)], 'NonCriticalFlag')"!]
        [!VAR "NCSPDValue" = "node:value($NCSPDNode)"!]
        [!IF "text:tolower($NCSPDValue) = 'true'"!]
        [!CODE!]| PMC_NCSPD_CTL_NCSPD_CTL[!"ecu:list('MCU.PMC.NonCriticalSPD.Indices.List')[num:i($NCSPDCounter)]"!]_MASK [!ENDCODE!]
    [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "GetEnabledCONFIG"!][!//
[!NOCODE!]
    [!CODE!]((uint32)0x00000000U) [!ENDCODE!]
    [!VAR "NumOfCONFIG" = "count(ecu:list('MCU.PMC.Config.List'))"!]
    [!FOR "CONFIGCounter" = "1" TO "$NumOfCONFIG"!]
        [!VAR "CONFIGNode"  = "concat('Mcu', ecu:list('MCU.PMC.Config.List')[num:i($CONFIGCounter)], 'Enable')"!]
        [!VAR "CONFIGValue" = "node:value($CONFIGNode)"!]
        [!IF "text:tolower($CONFIGValue) = 'true'"!]
        [!CODE!]| PMC_CONFIG_[!"ecu:list('MCU.PMC.Config.List')[num:i($CONFIGCounter)]"!]_MASK [!ENDCODE!]
    [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Power_Ip_PMC_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration/McuPowerControl/McuPMC_Config"!]
[!CODE!]
/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static const Power_Ip_PMC_ConfigType Power_Ip_PMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!IF "count(ecu:list('MCU.PMC.NonCriticalSPD.List')) > num:i(0)"!][!//
    /* Non-Critical Supply Presence Detector Control Register (NCSPD_CTL). */
    (
        [!CALL "GetEnabledNCSPD"!][!//
    )
[!ENDIF!][!//
[!IF "count(ecu:list('MCU.PMC.Config.List')) > num:i(0)"!][!//
    /* PMC Configuration Register (CONFIG). */
    (
        [!CALL "GetEnabledCONFIG"!][!//
    )
[!ENDIF!][!//
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration/McuPowerControl/McuPMC_Config
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Power_Ip_HwIPs_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
const Power_Ip_HwIPsConfigType Power_Ip_HwIPsConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Configuration for MC_RGM (Reset Generation Module) hardware IP. */
    &Power_Ip_MC_RGM_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for PMU (Power Management Unit) hardware IP, part of PCU. */
    &Power_Ip_PMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!ENDNOCODE!][!//


