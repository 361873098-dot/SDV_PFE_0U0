[!NOCODE!]
/**
    @file    Clock_Ip_RegOperations.m
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

[!NOCODE!]
[!VAR "HwpIrcoscCount" = "count(ecu:list('MCU.IRCOSC.List'))"!]
[!VAR "HwpXoscsCount" = "count(ecu:list('MCU.XOSC.List'))"!]
[!VAR "HwpllsCount" = "count(ecu:list('MCU.PLL.List'))"!]
[!VAR "HwSelectorCount" = "count(ecu:list('MCU.SELECTOR.Names.List'))"!]
[!VAR "HwDividerCount" = "count(ecu:list('MCU.DIVIDER.Names.List'))"!]
[!VAR "HwDividerTriggerCount" = "count(ecu:list('MCU.DIVIDER.TRIGGER.Names.List'))"!]
[!VAR "HwDfsCount" = "count(ecu:list('MCU.DFS.OutputPorts.List'))"!]
[!VAR "NrOfOutPortsClkDfs" = "count(ecu:list('MCU.ClockDFS.List'))"!]
[!VAR "NrOfClkExternal" = "count(ecu:list('MCU.ExtClock.List'))"!]
[!VAR "NrOfCgmx" = "count(ecu:list('MCU.CGM.CgmModules.List'))"!]
[!VAR "NumOfPCFSs" = "count(ecu:list('MCU.CGM.CgmPcfs.List'))"!]
[!VAR "NumOfClkSource" = "count(ecu:list('MCU.PCFS.Indices.List'))"!]
[!VAR "NrOfClkGates" = "count(ecu:list('MCU.GATE.Names.List'))"!]
[!VAR "NrOfClkMonitor" = "count(ecu:list('MCU.CMU_FC.List'))"!]
[!VAR "NrOfSpecificPeriph" = "count(ecu:list('MCU.SPECIFIC_PERIPHERAL_PRAMs.List'))"!]
[!ENDNOCODE!][!//

[!MACRO "Count_Ircoscs","Config"!][!//
[!NOCODE!]
    [!VAR "ircoscsCount" = "0"!]
    [!IF "node:exists("McuFIRC")"!]
        [!IF "node:value("McuFIRC/McuFircUnderMcuControl")"!]
            [!VAR "ircoscsCount" = "$ircoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "node:exists("McuSIRC")"!]
        [!IF "node:value("McuSIRC/McuSircUnderMcuControl")"!]
            [!VAR "ircoscsCount" = "$ircoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($ircoscsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Specific"!][!//
[!NOCODE!]
    [!VAR "specificCount" = "0"!]
    [!IF "node:exists("McuEMIOS")"!]
        [!LOOP "./McuEMIOS/*"!]
            [!IF "node:value(./McuEMIOSUnderMcuControl)"!]
                [!VAR "specificCount" = "$specificCount + 1"!]
            [!ENDIF!]

        [!ENDLOOP!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($specificCount * 5)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Print_Specific"!][!//
[!NOCODE!][!//
[!IF "node:exists("McuEMIOS")"!][!//
[!LOOP "./McuEMIOS/*"!][!//
[!IF "node:value(./McuEMIOSUnderMcuControl)"!][!//
[!VAR "prescaleType" = "concat(node:value(./McuEMIOSName),'_PRESCALER_VALUE')"!][!//
[!VAR "gateType" = "concat(node:value(./McuEMIOSName),'_GATE_VALUE')"!][!//
[!VAR "glbEnableType" = "concat(node:value(./McuEMIOSName),'_GLOBAL_BUS_ENABLE_VALUE')"!][!//
[!VAR "freezeType" = "concat(node:value(./McuEMIOSName),'_FREEZE_VALUE')"!][!//
[!VAR "moduleDisableType" = "concat(node:value(./McuEMIOSName),'_MODULE_DISABLE_VALUE')"!][!//
[!CODE!][!//
                {
                    [!"($prescaleType)"!],
                    [!"num:i(node:value(./McuGlobalPrescaler))"!]U,
                },
                {
                    [!"($gateType)"!],
                    [!IF "node:value(./McuGlobalPrescalerEnable)"!]1[!ELSE!]0[!ENDIF!]U
                },
                {
                    [!"($glbEnableType)"!],
                    [!IF "node:value(./McuGlobalTimeBaseEnable)"!]1[!ELSE!]0[!ENDIF!]U
                },
                {
                    [!"($freezeType)"!],
                    [!IF "node:value(./McuFreezeBit)"!]1[!ELSE!]0[!ENDIF!]U
                },
                {
                    [!"($moduleDisableType)"!],
                    [!IF "node:value(./McuMdisBit)"!]1[!ELSE!]0[!ENDIF!]U
                },
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDLOOP!]
[!CODE!][!//
[!FOR "CurrentSpecific" = "$specificCount" TO "num:i($NrOfSpecificPeriph) - 1"!][!//
                {
                    RESERVED_VALUE,
                    0U,
                },
[!ENDFOR!][!//
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
                {
                    RESERVED_VALUE,
                    0U,
                },
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Xoscs","Config"!][!//
[!NOCODE!]
    [!VAR "xoscsCount" = "0"!]
    [!IF "node:exists("McuFXOSC")"!]
        [!IF "node:value("McuFXOSC/McuFxoscUnderMcuControl")"!]
            [!VAR "xoscsCount" = "$xoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "node:exists("McuSXOSC")"!]
        [!IF "node:value("McuSXOSC/McuSxoscUnderMcuControl")"!]
            [!VAR "xoscsCount" = "$xoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($xoscsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Plls","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfPllUnderMcuCtr" = "0"!]
    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
        [!VAR "IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "PllPath" = "concat('McuPll_',$IndexPllx)"!]
        [!IF "node:exists($PllPath)"!]
            [!VAR "McuControlPllPath" = "concat($PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($McuControlPllPath)"!]
                [!VAR "NumOfPllUnderMcuCtr" = "$NumOfPllUnderMcuCtr  + 1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"num:i($NumOfPllUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Selectors","Config"!][!//
[!NOCODE!]
    [!VAR "selectorsCount" = "0"!]
[!// Selector of MC_CGM
        [!FOR "SelectorCGMx" = "1" TO "num:i($NrOfCgmx)"!]
        [!VAR "IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGMx)], 'Cgm')"!]
            [!VAR "NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List')))"!]
            [!FOR "SelectorIterator" = "1" TO "num:i($NumOfSelectors)"!]
                [!VAR "SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List'))[num:i($SelectorIterator)],'CLKMUX_')"!]
                [!VAR "SelectorPath" = "concat('McuCgm',$IndexCGMx,'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',$SelectorIndex)"!]
                [!IF "node:exists($SelectorPath)"!]
                    [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List'))[num:i($SelectorIterator)],'GENCTRL1_')"!]
                    [!VAR "SelectorPath" = "concat('McuCgm',$IndexCGMx,'SettingConfig/McuGENCTRL1_EMAC',$SelectorIndex)"!]
                    [!IF "node:exists($SelectorPath)"!]
                        [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                        [!IF "node:value($ControlPath)"!]
                            [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
[!// Selector of RTC_RTCC
       [!VAR "SelectorPath" = "'McuRtcClockSelect'"!]
       [!IF "node:exists($SelectorPath)"!]
           [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
           [!IF "node:value($ControlPath)"!]
           [!VAR "selectorsCount" = "$selectorsCount + 1"!]
           [!ENDIF!]
       [!ENDIF!]
[!CODE!][!//
[!"num:i($selectorsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Count_Dividers","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfDivUnderMcuCtr" = "0"!]
    [!FOR "SelectorCGM" = "1" TO "num:i($NrOfCgmx)"!]
        [!VAR "IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGM)],'Cgm')"!]
        [!VAR "NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List')))"!]
        [!FOR "SelectorIterator" = "0" TO "num:i($NumOfSelectors - 1)"!]
            [!VAR "SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List'))[num:i($SelectorIterator + 1)], 'CLKMUX_')"!]
            [!VAR "SelectorPath" = "concat('McuCgm',$IndexCGMx,'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',$SelectorIndex)"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "DividersList" = "concat('MCU.CGM',$IndexCGMx,'.ClockMux',$SelectorIndex,'.Dividers.List')"!]
                    [!VAR "NumOfDividers" = "count(ecu:list($DividersList))"!]
                    [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + $NumOfDividers"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]

    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
        [!VAR "IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "PllPath" = "concat('McuPll_',$IndexPllx)"!]
        [!IF "node:exists($PllPath)"!]
            [!VAR "McuControlPllPath" = "concat($PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($McuControlPllPath)"!]
                [!VAR "NumOfPllDividers" = "count(ecu:list('MCU.PLL.Dividers.List'))"!]
                [!VAR "DividersList" = "concat('MCU.PLL',$IndexPllx,'.Dividers.List')"!]
                [!VAR "NumOfDividers" = "count(ecu:list($DividersList))"!]
                [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + $NumOfPllDividers + $NumOfDividers"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"num:i($NumOfDivUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetDivTriggerClk","CrtCgm","CrtMux"!][!//
[!NOCODE!]
    [!VAR "divtriggername" = "concat('Cgm',$CrtCgm,'ClockMux',$CrtMux)"!]
    [!FOR "Currentdiv" = "1" TO "num:i($HwDividerTriggerCount)"!]
        [!IF "ecu:list('MCU.CGM.DIVIDER.TRIGGER.List')[num:i($Currentdiv)] = ($divtriggername)"!]
        [!VAR "divtriggerclk" = "ecu:list('MCU.DIVIDER.TRIGGER.Names.List')[num:i($Currentdiv)]"!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"($divtriggerclk)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Dividers_Trigger","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfDivTriggerUnderMcuCtr" = "0"!]
    [!IF "text:tolower(ecu:get('MCU.CGM.DividerTriggerSupport')) = 'true'"!][!//
        [!FOR "SelectorCGM" = "1" TO "num:i($NrOfCgmx)"!]
            [!VAR "IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGM)],'Cgm')"!]
            [!VAR "NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List')))"!]
            [!FOR "SelectorIterator" = "0" TO "num:i($NumOfSelectors - 1)"!]
                [!VAR "SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List'))[num:i($SelectorIterator + 1)], 'CLKMUX_')"!]
                [!VAR "SelectorPath" = "concat('McuCgm',$IndexCGMx,'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',$SelectorIndex)"!]
                [!IF "node:exists($SelectorPath)"!]
                    [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!VAR "DividersList" = "concat('MCU.CGM',$IndexCGMx,'.ClockMux',$SelectorIndex,'.Dividers.List')"!][!//
                        [!VAR "NrOfMuxDivs" = "count(ecu:list($DividersList))"!][!//
                        [!FOR "MuxDiv" = "1" TO "num:i($NrOfMuxDivs)"!][!//
                            [!IF "node:exists(concat($SelectorPath,'/McuClkMux',$SelectorIndex,ecu:list($DividersList)[num:i($MuxDiv)],'_En'))"!]
                            [!VAR "DivPath" = "concat($SelectorPath,'/McuClkMux',$SelectorIndex,ecu:list($DividersList)[num:i($MuxDiv)],'_En')"!]
                                [!IF "node:value($DivPath)"!]
                                    [!VAR "DivTriggerPath" = "concat($SelectorPath,'/McuClkMux',$SelectorIndex,ecu:list($DividersList)[num:i($MuxDiv)],'Trigger')"!]
                                    [!IF "node:exists($DivTriggerPath)"!]
                                        [!IF "text:tolower(ecu:get('MCU.CGM.MultipleOnMuxSupport')) = 'true'"!][!//
                                            [!VAR "NumOfDivTriggerUnderMcuCtr" = "1"!]
                                        [!ELSE!]
                                            [!VAR "NumOfDivTriggerUnderMcuCtr" = "$NumOfDivTriggerUnderMcuCtr + 1"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDFOR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($NumOfDivTriggerUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Dfs","Config"!][!//
[!NOCODE!]
[!VAR "NumOfDfsPortUnderMcuCtr" = "0"!]
[!FOR "HwDfs" = "1" TO "num:i($HwDfsCount)"!][!//
[!FOR "DfsPort" = "1" TO "ecu:list('MCU.DFS.OutputPorts.List')[num:i($HwDfs)]"!][!//
[!IF "num:i($HwDfs) = num:i('1')"!][!VAR "pathDFSUnderMcuControl" = "concat('McuCoreDfs/McuDfs_',$DfsPort,'/McuDFSUnderMcuControl')"!][!ELSE!][!VAR "pathDFSUnderMcuControl" = "concat('McuPeriphDfs/McuDfs_',$DfsPort,'/McuDFSUnderMcuControl')"!][!ENDIF!][!//
[!IF "node:value($pathDFSUnderMcuControl)"!][!//
    [!VAR "NumOfDfsPortUnderMcuCtr" = "$NumOfDfsPortUnderMcuCtr  + 1"!]
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
[!"num:i($NumOfDfsPortUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Clk_Pcfs","Config"!][!//
[!NOCODE!]
[!VAR "NumOfClkPcfs" = "0"!][!//
[!FOR "CurrentCgm" = "1" TO "num:i($NrOfCgmx)"!][!//
[!VAR "cgm" = "ecu:list('MCU.CGM.CgmModules.List')[num:i($CurrentCgm)]"!][!//
[!VAR "capitalName" = "text:replace($cgm,substring($cgm,2),text:toupper(substring($cgm,2)))"!][!//
[!VAR "pcfscount" = "count(ecu:list(concat('MCU.',$capitalName,'.CgmPcfs.List')))"!][!//
[!FOR "CurrentPCFS" = "0" TO "num:i($pcfscount - 1)"!][!//
[!IF "node:value(concat('Mcu',$cgm,'SettingConfig/Mcu',$cgm,'PcsConfig/Mcu',$cgm,'PcsConfig_',$CurrentPCFS,'/McuClockPcfsUnderMcuControl'))"!][!//
[!VAR "NumOfClkPcfs" = "$NumOfClkPcfs + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
[!"num:i($NumOfClkPcfs)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Clk_Monitor","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfClkMonitor" = "0"!]
    [!IF "node:exists("McuClkMonitor")"!]
        [!LOOP "./McuClkMonitor/*"!]
            [!IF "node:value(./McuClockMonitorUnderMcuControl)"!]
                [!VAR "NumOfClkMonitor" = "$NumOfClkMonitor + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($NumOfClkMonitor)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuEnable"!][!//
[!NOCODE!]
    [!VAR "CmuEn"!][!IF "node:value('./McuClkMonitorEn')"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($CmuEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuInterruptEnable"!][!//
[!NOCODE!]
[!VAR "CmuInterruptEn" = "0"!][!//
[!IF "node:value('./McuMonitorInterruptEn')"!][!//
[!VAR "CmuInterruptEn" = "1"!][!//
[!ENDIF!][!//
[!CODE!][!//
[!"num:i($CmuInterruptEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMonitoredClockFrequency","Name"!][!//
[!NOCODE!]
[!VAR "monitoredclockfrequency" = "0"!]
[!VAR "nammonitoredclock" = "substring-after(substring-after($McuCmuName,'CMU_FC_'),'_')"!]

[!IF "$nammonitoredclock = 'FXOSC_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuFXOSC/McuFXOSC_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'XBAR_DIV3_FAIL_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 6 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'CORE_M7_0_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'XBAR_DIV3_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 6 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'CORE_M7_1_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'CORE_M7_2_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'CORE_M7_3_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PER_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux3/McuClockMux3Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'SERDES_REF_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuPll_1/McuPll_Parameter/PLL_PHI0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'SERDES0_REF_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuPll_1/McuPll_Parameter/PLL_PHI0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'SERDES1_REF_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuPll_1/McuPll_Parameter/PLL_PHI0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'FLEXRAY_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux6/McuClockMux6Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'FLEXCAN_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux7/McuClockMux7_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'GMAC0_TX_CLK'"!][!//
    [!IF "contains(ecu:get('MCU.CGM0.ClockMuxes.List'), 'CLKMUX_10')"!][!//
        [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux10/McuClockMux10Divider0_Frequency)"!][!//
    [!ELSE!][!//
        [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm6SettingConfig/McuCgm6ClockMux1/McuClockMux1Divider0_Frequency)"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'GMAC_TS_CLK'"!][!//
    [!IF "contains(ecu:get('MCU.CGM0.ClockMuxes.List'), 'CLKMUX_9')"!][!//
        [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux9/McuClockMux9Divider0_Frequency)"!][!//
    [!ELSE!][!//
        [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm6SettingConfig/McuCgm6ClockMux0/McuClockMux0Divider0_Frequency)"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'LINFLEXD_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux8/McuClockMux8_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'QSPI_1X_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux12/McuClockMux12Divider0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'SDHC_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux14/McuClockMux14Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'DDR_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm5SettingConfig/McuCgm5ClockMux0/McuClockMux0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'GMAC0_RX_CLK'"!][!//
    [!IF "contains(ecu:get('MCU.CGM0.ClockMuxes.List'), 'CLKMUX_11')"!][!//
        [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux11/McuClockMux11_Frequency)"!][!//
    [!ELSE!][!//
        [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm6SettingConfig/McuCgm6ClockMux2/McuClockMux2_Frequency)"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'SPI_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux16/McuClockMux16_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'CORE_A53_CLUSTER_0_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm1SettingConfig/McuCgm1ClockMux0/McuClockMux0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'CORE_A53_CLUSTER_1_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm1SettingConfig/McuCgm1ClockMux0/McuClockMux0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFE_SYS_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux0/McuClockMux0Divider0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC0_TX_DIV_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux1/McuClockMux1Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC0_RX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux4/McuClockMux4_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC1_TX_DIV_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux4/McuClockMux4_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC1_TX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux2/McuClockMux2Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC1_RX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux5/McuClockMux5_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC2_TX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux3/McuClockMux3Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC2_TX_DIV_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux3/McuClockMux3Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'PFEMAC2_RX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux6/McuClockMux6_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'ACCEL3_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux0/McuClockMux0Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'ACCEL4_LAX0_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux1/McuClockMux1Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'ACCEL4_LAX1_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux1/McuClockMux1Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'GMAC1_TX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux2/McuClockMux2Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'GMAC1_RX_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm2SettingConfig/McuCgm2ClockMux4/McuClockMux4_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'XBAR_MIPICSI201_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!IF "$nammonitoredclock = 'XBAR_MIPICSI223_CLK'"!][!//
    [!VAR "monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//

[!CODE!][!//
[!"num:i($monitoredclockfrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Count_ExtClks","Config"!][!//
[!NOCODE!][!//
    [!VAR "extClksCount" = "count(ecu:list('MCU.ExtClock.List'))"!][!//
[!CODE!][!//
[!"num:i($extClksCount)"!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_configureFrequencies","Config"!][!//
[!NOCODE!][!//
    [!VAR "configureFrequenciesCount" = "count(ecu:list('MCU.ConfiguredFrequency.List'))"!][!//
[!CODE!][!//
[!"num:i($configureFrequenciesCount)"!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscEn","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "enPath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'StandbyEnable')"!]
    [!VAR "ircoscEn"!][!IF "node:value($enPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($ircoscEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscFrequency","Name"!][!//
[!NOCODE!]
    [!VAR "freqPath" = "concat('Mcu',$Name,'/Mcu',$Name,'_Frequency')"!]
    [!VAR "xoscFreq" = "num:i(node:value($freqPath))"!]
[!CODE!][!//
[!"num:i($xoscFreq)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscCounter","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "counterPath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'Counter')"!]
    [!VAR "xoscCounter" = "num:i(node:value($counterPath))"!]
[!CODE!][!//
[!"num:i($xoscCounter)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscOverdrive","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "overdrivePath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'OverdriveProtection')"!]
    [!IF "node:exists($overdrivePath)"!]
        [!VAR "xoscOverdrive" = "num:i(node:value($overdrivePath))"!]
    [!ELSE!]
        [!VAR "xoscOverdrive" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($xoscOverdrive)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscAutoLevelController","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "ALCEnablePath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'ALCEnable')"!]
    [!IF "node:exists($ALCEnablePath)"!]
        [!VAR "xoscALCEnable" = "num:i(node:value($ALCEnablePath) = "Disabled")"!]
    [!ELSE!]
        [!VAR "xoscALCEnable" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($xoscALCEnable)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscBypass","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "bypassPath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'ByPass')"!]
    [!IF "node:exists($bypassPath)"!]
        [!VAR "xoscBypass"!][!IF "node:value($bypassPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "xoscBypass" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($xoscBypass)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscComp","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "compPath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'MainComparator')"!]
    [!IF "node:exists($compPath)"!]
        [!VAR "xoscComp"!][!IF "node:value($compPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "xoscComp" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($xoscComp)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscEn","Name"!][!//
[!NOCODE!]
    [!VAR "capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "enPath" = "concat('Mcu',$Name,'/Mcu',$capitalName,'PowerDownCtr')"!]
    [!VAR "xoscEn"!][!IF "node:value($enPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($xoscEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetDivisorValue","CrtCgm","CrtMux","CrtDiv"!][!//
[!NOCODE!]
    [!VAR "muxPath" = "concat('McuCgm0SettingConfig/McuCgm0ClockMux',num:i($CrtMux))"!]
    [!VAR "divPathPrefix" = "concat($muxPath,'/McuClkMux',num:i($CrtMux),'Div',num:i($CrtDiv))"!]
    [!VAR "divEnPath" = "concat($divPathPrefix,'_En')"!]
    [!VAR "divValuePath" = "concat($divPathPrefix,'_Divisor')"!]
    [!IF "node:value($divEnPath)"!]
        [!VAR "divValue" = "num:i(node:value($divValuePath) + 1)"!]
    [!ELSE!]
        [!VAR "divValue" = "0"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($divValue)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllEnable","Name"!][!//
[!NOCODE!]
    [!VAR "pllEn"!][!IF "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPLLEnabled'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($pllEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllClockSelection","Name"!][!//
[!NOCODE!]
    [!VAR "pllclockselectionPath" = "concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPllClockSelection')"!]
    [!IF "node:exists($pllclockselectionPath)"!]
        [!VAR "pllclockselection" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPllClockSelection'))"!]
    [!ELSE!]
        [!VAR "pllclockselection" = "'RESERVED_CLK'"!]
    [!ENDIF!]
[!CODE!][!//
[!"($pllclockselection)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllModBypassEnable","Name"!][!//
[!NOCODE!]
    [!VAR "pllBypEn"!][!IF "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFmSscgbyp'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($pllBypEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllPrediv","Name"!][!//
[!NOCODE!]
    [!VAR "pllPrediv" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllDvRdiv'))"!]
[!CODE!][!//
[!"num:i($pllPrediv)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllNumerator","Name"!][!//
[!NOCODE!]
    [!VAR "pllNum" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFdMfn'))"!]
[!CODE!][!//
[!"num:i($pllNum)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllMultiplier","Name"!][!//
[!NOCODE!]
    [!VAR "pllMul" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllDvMfi'))"!]
[!CODE!][!//
[!"num:i($pllMul)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllStepSize","Name"!][!//
[!NOCODE!]
    [!VAR "pllStepSize" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFmStepSize'))"!]
[!CODE!][!//
[!"num:i($pllStepSize)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllStepNumber","Name"!][!//
[!NOCODE!]
    [!VAR "pllStepNo" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFmStepNo'))"!]
[!CODE!][!//
[!"num:i($pllStepNo)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllSigmaDelta","Name"!][!//
[!NOCODE!]
    [!VAR "pllSDEn"!][!IF "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFdSdmen'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($pllSDEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetDfsPortEnable","NumMcuPLL","DfsPortIndex"!][!//
[!NOCODE!]
[!IF "num:i($NumMcuPLL) = num:i('0')"!][!VAR "pathMcuDFSPort_En" = "concat('McuCoreDfs/McuDfs_',$DfsPortIndex,'/McuDFSPort_En')"!][!ELSE!][!VAR "pathMcuDFSPort_En" = "concat('McuPeriphDfs/McuDfs_',$DfsPortIndex,'/McuDFSPort_En')"!][!ENDIF!][!//
    [!VAR "DfsPortEn"!][!IF "node:value($pathMcuDFSPort_En)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($DfsPortEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMcuDFSPortMf","NumMcuPLL","DfsPortIndex"!][!//
[!NOCODE!]
[!IF "num:i($NumMcuPLL) = num:i('0')"!][!VAR "pathMcuDFSPortMfi" = "concat('McuCoreDfs/McuDfs_',$DfsPortIndex,'/McuDFSPortMfi')"!][!ELSE!][!VAR "pathMcuDFSPortMfi" = "concat('McuPeriphDfs/McuDfs_',$DfsPortIndex,'/McuDFSPortMfi')"!][!ENDIF!][!//
[!IF "num:i($NumMcuPLL) = num:i('0')"!][!VAR "pathMcuDFSPortMfn" = "concat('McuCoreDfs/McuDfs_',$DfsPortIndex,'/McuDFSPortMfn')"!][!ELSE!][!VAR "pathMcuDFSPortMfn" = "concat('McuPeriphDfs/McuDfs_',$DfsPortIndex,'/McuDFSPortMfn')"!][!ENDIF!][!//
    [!VAR "valueDFSPortMfi" = "node:value($pathMcuDFSPortMfi)"!]
    [!VAR "valueDFSPortMfn" = "node:value($pathMcuDFSPortMfn)"!]
[!CODE!][!//
[!"num:i($valueDFSPortMfi)"!]U,
                    [!"num:i($valueDFSPortMfn)"!]U,[!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetNameClockSource","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "mcupcsname" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_Name'))"!]
    [!FOR "Currentclksrc" = "1" TO "num:i($NumOfClkSource)"!]
        [!IF "ecu:list('MCU.PCFS.Indices.List')[num:i($Currentclksrc)] = ($mcupcsname)"!]
        [!VAR "clksrc" = "ecu:list('MCU.ClockSource.List')[num:i($Currentclksrc)]"!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"($clksrc)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPcfsClockSourceFrequency","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "pcfsclocksourcefrequency" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_SourceFrequency'))"!]
[!CODE!][!//
[!"num:i($pcfsclocksourcefrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPcfsSelectorName","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "mcupcsname" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_Name'))"!]
    [!FOR "Currentclksrc" = "1" TO "num:i($NumOfClkSource)"!]
        [!IF "ecu:list('MCU.PCFS.Indices.List')[num:i($Currentclksrc)] = ($mcupcsname)"!]
        [!VAR "clksrc" = "ecu:list('MCU.PcfsSelectorName.List')[num:i($Currentclksrc)]"!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"($clksrc)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetClockExternal","Name"!][!//
[!NOCODE!]
    [!VAR "externalPath" = "concat('../../McuExternalPAD_',$Name,'_FrequencyHz')"!]
    [!IF "node:exists($externalPath)"!]
        [!VAR "valueclockexternal" = "node:value(concat('../../McuExternalPAD_',$Name,'_FrequencyHz'))"!]
    [!ELSE!]
        [!VAR "externalPath" = "concat('../../McuInternalPAD_',$Name,'_FrequencyHz')"!]
        [!IF "node:exists($externalPath)"!]
            [!VAR "valueclockexternal" = "node:value(concat('../../McuInternalPAD_',$Name,'_FrequencyHz'))"!]
        [!ELSE!]
            [!VAR "valueclockexternal" = "num:i(0)"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($valueclockexternal)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetClockConfiguredFrequency","Name"!][!//
[!NOCODE!]
[!VAR "clockConfiguredfrequency" = "0"!]

[!IF "$Name = 'FIRC_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "num:i(48000000)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'FXOSC_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuFXOSC/McuFXOSC_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'XBAR_DIV3_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 6 "!][!//
[!ENDIF!][!//
[!IF "$Name = 'XBAR_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0_Frequency) div 2 "!][!//
[!ENDIF!][!//
[!CODE!][!//
[!"num:i($clockConfiguredfrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMcuPCSStepDuration","Name"!][!//
[!NOCODE!]
    [!VAR "pcsstepduration" = "node:value(concat('Mcu',$Name,'SettingConfig/McuPCSStepDuration'))"!]
[!CODE!][!//
[!"num:i($pcsstepduration)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetmaxAllowableIDDchange","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "maxallowableiddchange" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_MaxAllowableDynamicIDD'))"!]
[!CODE!][!//
[!"num:i($maxallowableiddchange)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Clock_Ip_Clock_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/* *************************************************************************
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
 /*! @brief User Configuration structure clock_Cfg_0 */
const Clock_Ip_ClockConfigType Mcu_aClockConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]U] = {
[!ENDCODE!]
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
    [!VAR "ClockConfig" = "0"!]
    [!VAR "ircoscsCount"!][!CALL "Count_Ircoscs",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "xoscsCount"!][!CALL "Count_Xoscs",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfPllUnderMcuCtr"!][!CALL "Count_Plls",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "selectorsCount"!][!CALL "Count_Selectors",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfDivUnderMcuCtr"!][!CALL "Count_Dividers",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfDfsPortUnderMcuCtr"!][!CALL "Count_Dfs",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "extClksCount"!][!CALL "Count_ExtClks",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "specificCount"!][!CALL "Count_Specific"!][!ENDVAR!]
    [!VAR "NumOfDivTriggerUnderMcuCtr"!][!CALL "Count_Dividers_Trigger"!][!ENDVAR!]
    [!VAR "NumOfUnderClkPcfs"!][!CALL "Count_Clk_Pcfs",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfUnderClkMonitor"!][!CALL "Count_Clk_Monitor",Config="$ClockConfig"!][!ENDVAR!]   
    [!VAR "configureFrequenciesCount"!][!CALL "Count_configureFrequencies",Config="$ClockConfig"!][!ENDVAR!]    
    [!CODE!]
    {
        [!"num:i(num:i(McuClockSettingId))"!]U,                                 /* clkConfigId */

        [!"$ircoscsCount"!]U,                                 /* ircoscsCount */
        [!"$xoscsCount"!]U,                                 /* xoscsCount */
        [!"$NumOfPllUnderMcuCtr"!]U,                                 /* pllsCount */
        [!"$selectorsCount"!]U,                                /* selectorsCount */
        [!"$NumOfDivUnderMcuCtr"!]U,                                /* dividersCount */
        [!"$NumOfDivTriggerUnderMcuCtr"!]U,                                 /* dividerTriggersCount */
        [!"$NumOfDfsPortUnderMcuCtr"!]U,                                /* fracDivsCount */
        [!"$extClksCount"!]U,                                /* extClksCount */
        0U,                                 /* gatesCount */
        [!"$NumOfUnderClkPcfs"!]U,                                 /* pcfsCount */
        [!"$NumOfUnderClkMonitor"!]U,                                /* cmusCount */
        [!"$configureFrequenciesCount"!]U,                                /* configureFrequenciesCount */

        /* IRCOSC initialization. */
        {
[!IF "$ircoscsCount > num:i(0)"!][!//
[!FOR "IrcoscsIterator" = "1" TO "num:i($HwpIrcoscCount)"!][!//
[!VAR "Ircoscs" = "ecu:list('MCU.IRCOSC.List')[num:i($IrcoscsIterator)]"!][!//
[!VAR "capitalIrcoscs" = "text:replace($Ircoscs,substring($Ircoscs,2),text:tolower(substring($Ircoscs,2)))"!][!//
[!VAR "IrcoscsPath" = "concat('Mcu',$Ircoscs,'/Mcu',$capitalIrcoscs,'UnderMcuControl')"!][!//
[!IF "node:value($IrcoscsPath)"!][!//
            #if CLOCK_IP_IRCOSCS_NO > [!"num:i($IrcoscsIterator - 1)"!]U
[!VAR "Ircosc" = "ecu:list('MCU.IRCOSC.List')[num:i($IrcoscsIterator)]"!][!//
            {
                [!"ecu:list('MCU.IRCOSC.Names')[num:i($IrcoscsIterator)]"!],
                [!CALL "GetIrcoscEn","Name"="$Ircosc"!]U,
                0U,
                0U,
                0U,
                0U,
            },
            #endif
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "IrcoscsIterator" = "$ircoscsCount" TO "num:i($HwpIrcoscCount - 1)"!][!//
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                0U,                     /* Enable regulator */
                0U,                     /* Ircosc range */
                0U,                     /* Ircosc enable in VLP mode */
                0U,                     /* Ircosc enable in STOP mode */
            },
[!ENDFOR!][!//
[!ELSE!][!//
    [!FOR "IrcoscsIterator" = "1" TO "num:i($HwpIrcoscCount)"!]
           #if CLOCK_IP_IRCOSCS_NO > [!"num:i($IrcoscsIterator - 1)"!]U
           {
               RESERVED_CLK,           /* name */
               0U,                     /* enable */
               0U,                     /* Enable regulator */
               0U,                     /* Ircosc range */
               0U,                     /* Ircosc enable in VLP mode */
               0U,                     /* Ircosc enable in STOP mode */
           },
           #endif
    [!ENDFOR!]
[!ENDIF!][!//
        },

        /* XOSC initialization. */
        {
[!IF "$xoscsCount > num:i(0)"!][!//
[!FOR "XoscsIterator" = "1" TO "num:i($HwpXoscsCount)"!][!//
[!VAR "Xosc" = "ecu:list('MCU.XOSC.List')[num:i($XoscsIterator)]"!][!//
[!VAR "capitalXosc" = "text:replace($Xosc,substring($Xosc,2),text:tolower(substring($Xosc,2)))"!][!//
[!VAR "XoscPath" = "concat('Mcu',$Xosc,'/Mcu',$capitalXosc,'UnderMcuControl')"!][!//
[!IF "node:value($XoscPath)"!][!//
            #if CLOCK_IP_XOSCS_NO > [!"num:i($XoscsIterator - 1)"!]U
[!VAR "Xosc" = "ecu:list('MCU.XOSC.List')[num:i($XoscsIterator)]"!][!//
            {
                [!"ecu:list('MCU.XOSC.Names')[num:i($XoscsIterator)]"!],                    /* Clock name associated to xosc */
                [!CALL "GetXoscFrequency","Name"="$Xosc"!]U,                    /* External oscillator frequency. */
                [!CALL "GetXoscEn","Name"="$Xosc"!]U,                           /* Enable xosc. */
                [!CALL "GetXoscCounter","Name"="$Xosc"!]U,                         /* Startup stabilization time. */
                [!CALL "GetXoscBypass","Name"="$Xosc"!]U,                           /* XOSC bypass option */
                [!CALL "GetXoscComp","Name"="$Xosc"!]U,                           /* Comparator enable */
                [!CALL "GetXoscOverdrive","Name"="$Xosc"!]U,                          /* Crystal overdrive protection */
                0U,                     /* Gain value */
                0U,                     /* Monitor type */
                [!CALL "GetXoscAutoLevelController","Name"="$Xosc"!]U,                     /* Automatic level controller */
            },
            #endif
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "XoscsIterator" = "$xoscsCount" TO "num:i($HwpXoscsCount - 1)"!][!//
            {
                RESERVED_CLK,           /* Clock name associated to xosc */
                0U,                     /* External oscillator frequency. */
                0U,                     /* Enable xosc. */
                0U,                     /* Startup stabilization time. */
                0U,                     /* XOSC bypass option */
                0U,                     /* Comparator enable */
                0U,                     /* Crystal overdrive protection */
                0U,                     /* Gain value */
                0U,                     /* Monitor type */
                0U,                     /* Automatic level controller */
            },
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "XoscsIterator" = "1" TO "num:i($HwpXoscsCount)"!][!//
            #if CLOCK_IP_XOSCS_NO > [!"num:i($XoscsIterator - 1)"!]U
            {
                RESERVED_CLK,           /* Clock name associated to xosc */
                0U,                     /* External oscillator frequency. */
                0U,                     /* Enable xosc. */
                0U,                     /* Startup stabilization time. */
                0U,                     /* XOSC bypass option */
                0U,                     /* Comparator enable */
                0U,                     /* Crystal overdrive protection */
                0U,                     /* Gain value */
                0U,                     /* Monitor type */
                0U,                     /* Automatic level controller */
            },
            #endif
[!ENDFOR!][!//
[!ENDIF!]
        },

        /* PLL initialization. */
        {
[!IF "$NumOfPllUnderMcuCtr > num:i(0)"!][!//
[!VAR "CurrentPll" = "0"!][!//
[!FOR "PllIterator" = "1" TO "num:i($HwpllsCount)"!][!//
[!IF "node:value(concat('McuPll_',num:i(number(substring-after(ecu:list('MCU.PLL.List')[num:i($PllIterator)],'PLL_'))),'/McuPLLUnderMcuControl'))"!][!//
[!VAR "Pll" = "ecu:list('MCU.PLL.List')[num:i($PllIterator)]"!][!//
[!IF "num:i(number(substring-after(ecu:list('MCU.PLL.List')[num:i($PllIterator)],'PLL_'))) = num:i(1)"!][!//
[!VAR "PllBypass" = "num:i('1')"!][!//
[!ELSE!][!//
[!VAR "PllBypass"!][!CALL "GetPllModBypassEnable","Name"="$Pll"!][!ENDVAR!][!//
[!ENDIF!][!//
            #if CLOCK_IP_PLLS_NO > [!"num:i($CurrentPll)"!]U
            {
                [!"ecu:list('MCU.PLL.Names.List')[num:i($PllIterator)]"!],                  /*!<     name;                    */
                [!CALL "GetPllEnable","Name"="$Pll"!]U,                           /*!<     enable;                  */
                [!CALL "GetPllClockSelection","Name"="$Pll"!],                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                [!CALL "GetPllPrediv","Name"="$Pll"!]U,                           /*!<     predivider;              */
                [!CALL "GetPllNumerator","Name"="$Pll"!]U,                           /*!<     numeratorFracLoopDiv;    */
                [!CALL "GetPllMultiplier","Name"="$Pll"!]U,                          /*!<     mulFactorDiv;            */
                [!IF "num:i($PllBypass) = num:i('1')"!]1[!ELSE!]0[!ENDIF!]U,                           /*!<     ModulationBypass;              */
                0U,                           /*!<     modulationType;          */
                [!IF "num:i(number(substring-after(ecu:list('MCU.PLL.List')[num:i($PllIterator)],'PLL_'))) = num:i(1)"!]0[!ELSE!][!CALL "GetPllStepSize","Name"="$Pll"!][!ENDIF!]U,                           /*!<     modulationPeriod;        */
                [!IF "num:i(number(substring-after(ecu:list('MCU.PLL.List')[num:i($PllIterator)],'PLL_'))) = num:i(1)"!]0[!ELSE!][!CALL "GetPllStepNumber","Name"="$Pll"!][!ENDIF!]U,                           /*!<     incrementStep;           */
                [!CALL "GetPllSigmaDelta","Name"="$Pll"!]U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
[!VAR "CurrentPll" = "$CurrentPll + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "PllIterator" = "$NumOfPllUnderMcuCtr" TO "num:i($HwpllsCount - 1)"!][!//
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                RESERVED_CLK,           /* inputReference */
                0U,                     /* Bypass */
                0U,                     /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                0U,                     /* mulFactorDiv */
                0U,                     /* ModulationBypass */
                0U,                     /* Modulaton type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                     /* monitor type */
                {                             /*!< Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "PllIterator" = "1" TO "num:i($HwpllsCount)"!][!//
            #if CLOCK_IP_PLLS_NO > [!"num:i($PllIterator - 1)"!]U
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                RESERVED_CLK,           /* inputReference */
                0U,                     /* Bypass */
                0U,                     /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                0U,                     /* mulFactorDiv */
                0U,                     /* ModulationBypass */
                0U,                     /* Modulaton type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                     /* monitor type */
                {                             /*!< Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
[!ENDFOR!][!//
[!ENDIF!]
        },


        /* SELECTOR initialization. */
        {
[!ENDCODE!]
[!IF "$selectorsCount > num:i(0)"!][!//
[!VAR "CurrentSelector" = "0"!]
            [!FOR "SelectorCGMx" = "1" TO "num:i($NrOfCgmx)"!]
[!VAR "IndexCGM" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGMx)], 'Cgm')"!]
            [!VAR "NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$IndexCGM,'.ClockMuxes.List')))"!]
            [!VAR "CurrentSelector" = "$CurrentSelector"!]
            [!FOR "SelectorIterator" = "1" TO "num:i($NumOfSelectors)"!]
                [!VAR "SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGM,'.ClockMuxes.List'))[num:i($SelectorIterator)],'CLKMUX_')"!]
                [!VAR "SelectorPath" = "concat('McuCgm',$IndexCGM,'SettingConfig/McuCgm',$IndexCGM,'ClockMux',$SelectorIndex)"!]
                [!IF "node:exists($SelectorPath)"!]
                    [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"ecu:list(concat('MCU.CGM',$IndexCGM,'.ClockMuxes.Names.List'))[num:i($SelectorIterator)]"!],                     /* Clock name associated to selector */
                [!"node:value(concat($SelectorPath,'/McuClkMux',$SelectorIndex,'_Source'))"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                    [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGM,'.ClockMuxes.List'))[num:i($SelectorIterator)],'GENCTRL1_')"!]
                    [!VAR "SelectorPath" = "concat('McuCgm',$IndexCGM,'SettingConfig/McuGENCTRL1_EMAC',$SelectorIndex)"!]
                    [!IF "node:exists($SelectorPath)"!]
                        [!VAR "ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                        [!IF "node:value($ControlPath)"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"ecu:list(concat('MCU.CGM',$IndexCGM,'.ClockMuxes.Names.List'))[num:i($SelectorIterator)]"!],                     /* Clock name associated to selector */
                [!"node:value(concat($SelectorPath,'/McuGENCTRL1_EMAC',$SelectorIndex,'_Source'))"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
            [!ENDFOR!]

[!// Selector of RTC_RTCC
        [!VAR "SelectorPath" = "'McuRtcClockSelect'"!]
        [!IF "node:exists($SelectorPath)"!]
            [!VAR "Mac_ControlPath" = "concat($SelectorPath,'/McuClockMuxUnderMcuControl')"!]
            [!IF "node:value($Mac_ControlPath)"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                RTC_CLK,                     /* Clock name associated to selector */
                [!"node:value(concat($SelectorPath,'/McuRtc_Source'))"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
            [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
            [!ENDIF!]
        [!ENDIF!]

[!FOR "SelectorIterator" = "$selectorsCount" TO "num:i($HwSelectorCount - 1)"!][!//
        [!CODE!]
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        [!ENDCODE!]
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "SelectorIterator" = "1" TO "num:i($HwSelectorCount)"!][!//
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($SelectorIterator - 1)"!]U
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
[!ENDFOR!][!//
[!ENDIF!]
        [!CODE!]
        },

        /* DIVIDER initialization. */
        {
        [!ENDCODE!]
[!IF "$NumOfDivUnderMcuCtr > num:i(0)"!][!//
    [!VAR "CurrentDivider" = "0"!]
    [!VAR "DivValue" = "0"!]
    [!// Divider of PLL
    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
        [!VAR "IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "PllPath" = "concat('McuPll_',$IndexPllx)"!]
        [!IF "node:exists($PllPath)"!]
            [!VAR "McuControlPllPath" = "concat($PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($McuControlPllPath)"!]
                [!VAR "PllDividersList" = "concat('MCU.PLL',$IndexPllx,'.Dividers.List')"!]
                [!VAR "NrOfPllDivs" = "count(ecu:list($PllDividersList))"!]
                [!VAR "NrOfPllDV" = "count(ecu:list('MCU.PLL.Dividers.List'))"!]
                [!FOR "PllDivIterator" = "1" TO "num:i($NrOfPllDV)"!]
                    [!VAR "PllDivName" = "ecu:list('MCU.PLL.Dividers.Names.List')[num:i($PllDivIterator)]"!]
                    [!VAR "PllDivPath" = "concat('McuPll_',($IndexPllx),'/McuPll_Configuration/McuPllDvOdiv2')"!]
                    [!IF "node:exists($PllDivPath)"!]
                        [!VAR "DivValue" = "num:i(node:value($PllDivPath))"!]
                    [!ELSE!]
                        [!VAR "DivValue" = "0"!]
                    [!ENDIF!]
                    [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($PllDivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
                    [!ENDCODE!]
                    [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                [!ENDFOR!]
                [!FOR "PllDivIterator" = "1" TO "num:i($NrOfPllDivs)"!]
                    [!VAR "PllDivName" = "ecu:list(concat('MCU.PLL',$IndexPllx,'.Dividers.Names.List'))[num:i($PllDivIterator)]"!]
                    [!VAR "DivEnPath" = "concat('McuPll_',($IndexPllx),'/McuPll_Configuration/Mcu',ecu:list($PllDividersList)[num:i($PllDivIterator)],'_En')"!]
                    [!IF "node:value($DivEnPath)"!]
                        [!VAR "DivValPath" = "concat('McuPll_',($IndexPllx),'/McuPll_Configuration/Mcu',ecu:list($PllDividersList)[num:i($PllDivIterator)],'_Div')"!]
                        [!VAR "DivValue" = "num:i(node:value($DivValPath) + 1)"!]
                    [!ELSE!]
                        [!VAR "DivValue" = "0"!]
                    [!ENDIF!]
                    [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($PllDivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
                    [!ENDCODE!]
                    [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                [!ENDFOR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!// Divider of CGM
    [!FOR "CgmCount" = "1" TO "num:i($NrOfCgmx)"!]
        [!VAR "IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($CgmCount)],'Cgm')"!]
        [!VAR "NumOfMux" = "count(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List')))"!]
        [!FOR "MuxIterator" = "1" TO "num:i($NumOfMux)"!]
            [!VAR "IndexMux" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List'))[num:i($MuxIterator)], 'CLKMUX_')"!]
            [!VAR "MuxPath" = "concat('McuCgm',$IndexCGMx,'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',$IndexMux)"!]
            [!IF "node:exists($MuxPath)"!]
                [!VAR "ControlPath" = "concat($MuxPath,'/McuClockMuxUnderMcuControl')"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "DividersList" = "concat('MCU.CGM',$IndexCGMx,'.ClockMux',$IndexMux,'.Dividers.List')"!]
                    [!VAR "NrOfMuxDivs" = "count(ecu:list($DividersList))"!]
                    [!FOR "MuxDivIterator" = "1" TO "num:i($NrOfMuxDivs)"!]
                        [!VAR "MuxDivName" = "ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMux',$IndexMux,'.Dividers.Names.List'))[num:i($MuxDivIterator)]"!]
                        [!VAR "MuxDivEnPath" = "concat('McuCgm',($IndexCGMx),'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',($IndexMux),'/McuClkMux',($IndexMux),ecu:list($DividersList)[num:i($MuxDivIterator)],'_En')"!]
                        [!IF "node:value($MuxDivEnPath)"!]
                            [!VAR "DivValPath" = "concat('McuCgm',($IndexCGMx),'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',($IndexMux),'/McuClkMux',($IndexMux),ecu:list($DividersList)[num:i($MuxDivIterator)],'_Divisor')"!]
                            [!VAR "DivValue" = "num:i(node:value($DivValPath) + 1)"!]
                        [!ELSE!]
                            [!VAR "DivValue" = "0"!]
                        [!ENDIF!]
                        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($MuxDivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
                        [!ENDCODE!]
                        [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                    [!ENDFOR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
[!FOR "PllDivIterator" = "$NumOfDivUnderMcuCtr" TO "num:i($HwDividerCount - 1)"!][!//
        [!CODE!]
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        [!ENDCODE!]
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "PllDivIterator" = "1" TO "num:i($HwDividerCount)"!][!//
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($PllDivIterator - 1)"!]U
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
            #endif
        [!ENDCODE!]
[!ENDFOR!][!//
[!ENDIF!]
        [!CODE!]
        },

        /* DIVIDER TRIGGER Initialization. */
        {
[!IF "text:tolower(ecu:get('MCU.CGM.DividerTriggerSupport')) = 'true'"!][!//
[!IF "$NumOfDivTriggerUnderMcuCtr > num:i(0)"!][!//
[!VAR "CommonDividerTrigger" = "0"!][!//
[!VAR "CurrentDividerTrigger" = "0"!][!//
[!VAR "DivTriggerValue" = "0"!][!//
[!FOR "CgmCount" = "1" TO "num:i($NrOfCgmx)"!][!//
[!VAR "IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($CgmCount)],'Cgm')"!][!//
[!VAR "NumOfMux" = "count(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List')))"!][!//
[!FOR "MuxIterator" = "1" TO "num:i($NumOfMux)"!][!//
[!VAR "IndexMux" = "substring-after(ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMuxes.List'))[num:i($MuxIterator)], 'CLKMUX_')"!][!//
[!VAR "MuxPath" = "concat('McuCgm',$IndexCGMx,'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',$IndexMux)"!][!//
[!IF "node:exists($MuxPath)"!][!//
[!VAR "ControlPath" = "concat($MuxPath,'/McuClockMuxUnderMcuControl')"!][!//
[!IF "node:value($ControlPath)"!][!//
[!IF "text:tolower(ecu:get('MCU.CGM.MultipleOnMuxSupport')) = 'true'"!][!//
[!VAR "DividersList" = "concat('MCU.CGM',$IndexCGMx,'.ClockMux',$IndexMux,'.Dividers.List')"!][!//
[!VAR "NrOfMuxDivs" = "count(ecu:list($DividersList))"!][!//
[!FOR "MuxDivIterator" = "1" TO "num:i($NrOfMuxDivs)"!][!//
[!VAR "MuxDivName" = "ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMux',$IndexMux,'.Dividers.Names.List'))[num:i($MuxDivIterator)]"!][!//
[!VAR "MuxDivEnPath" = "concat('McuCgm',($IndexCGMx),'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',($IndexMux),'/McuClkMux',($IndexMux),ecu:list($DividersList)[num:i($MuxDivIterator)],'_En')"!][!//
[!IF "node:value($MuxDivEnPath)"!][!//
[!VAR "DivTriggerPath" = "concat($MuxPath,'/McuClkMux',$IndexMux,ecu:list($DividersList)[num:i($MuxDivIterator)],'Trigger')"!][!//
[!IF "node:exists($DivTriggerPath)"!][!//
[!IF "node:value($DivTriggerPath) = 'COMMON_TRIGGER_DIVIDER_UPDATE'"!]
[!VAR "CommonDividerTrigger" = "$CommonDividerTrigger + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ELSE!][!//
[!VAR "DividersList" = "concat('MCU.CGM',$IndexCGMx,'.ClockMux',$IndexMux,'.Dividers.List')"!][!//
[!VAR "NrOfMuxDivs" = "count(ecu:list($DividersList))"!][!//
[!FOR "MuxDivIterator" = "1" TO "num:i($NrOfMuxDivs)"!][!//
[!VAR "MuxDivName" = "ecu:list(concat('MCU.CGM',$IndexCGMx,'.ClockMux',$IndexMux,'.Dividers.Names.List'))[num:i($MuxDivIterator)]"!][!//
[!VAR "MuxDivEnPath" = "concat('McuCgm',($IndexCGMx),'SettingConfig/McuCgm',$IndexCGMx,'ClockMux',($IndexMux),'/McuClkMux',($IndexMux),ecu:list($DividersList)[num:i($MuxDivIterator)],'_En')"!][!//
[!IF "node:value($MuxDivEnPath)"!][!//
[!VAR "DivTriggerPath" = "concat($MuxPath,'/McuClkMux',$IndexMux,ecu:list($DividersList)[num:i($MuxDivIterator)],'Trigger')"!][!//
[!IF "node:exists($DivTriggerPath)"!][!//
[!VAR "DivTriggerValue" = "node:value($DivTriggerPath)"!][!//
[!CODE!][!//
            #if CLOCK_IP_DIVIDER_TRIGGERS_NO > [!"num:i($CurrentDividerTrigger)"!]U
            {
                [!CALL "GetDivTriggerClk","CrtCgm"="$IndexCGMx","CrtMux"="$IndexMux"!],                     /* divider name */
                [!"($DivTriggerValue)"!],      /* trigger value */
                [!CALL "GetDivTriggerClk","CrtCgm"="$IndexCGMx","CrtMux"="$IndexMux"!],                     /* input source name */
            },
            #endif
[!ENDCODE!][!//
[!VAR "CurrentDividerTrigger" = "$CurrentDividerTrigger + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!IF "text:tolower(ecu:get('MCU.CGM.MultipleOnMuxSupport')) = 'true'"!][!//
[!IF "$CommonDividerTrigger > num:i(0)"!][!//
[!CODE!][!//
            #if CLOCK_IP_DIVIDER_TRIGGERS_NO > 0U
            {
                CORE_CLK,                     /* divider name */
                COMMON_TRIGGER_DIVIDER_UPDATE,      /* trigger value */
                CORE_CLK,                     /* input source name */
            },
            #endif
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
            #if CLOCK_IP_DIVIDER_TRIGGERS_NO > 0U
            {
                CORE_CLK,                     /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,      /* trigger value */
                CORE_CLK,                     /* input source name */
            },
            #endif
[!ENDCODE!][!//
[!VAR "NumOfDivTriggerUnderMcuCtr" = "1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!FOR "DivTriggerIterator" = "$NumOfDivTriggerUnderMcuCtr" TO "num:i($HwDividerTriggerCount - 1)"!][!//
            #if CLOCK_IP_DIVIDER_TRIGGERS_NO > [!"num:i($DivTriggerIterator)"!]U
            {
                RESERVED_CLK,          /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,                    /* trigger value */
                RESERVED_CLK,          /* input source name */
            },
            #endif
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "DivTriggerIterator" = "1" TO "num:i($HwDividerTriggerCount)"!][!//
[!CODE!][!//
            #if CLOCK_IP_DIVIDER_TRIGGERS_NO > [!"num:i($DivTriggerIterator - 1)"!]U
            {
                RESERVED_CLK,          /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,                    /* trigger value */
                RESERVED_CLK,          /* input source name */
            },
            #endif
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ELSE!][!//
            {
                RESERVED_CLK,          /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,                    /* trigger value */
                RESERVED_CLK,          /* input source name */
            },
[!ENDIF!][!//
        },

        /* FRACTIONAL DIVIDER initialization. */
        {
[!IF "$NumOfDfsPortUnderMcuCtr > num:i(0)"!][!//
[!VAR "CurrentDfsPort" = "0"!][!//
[!FOR "HwDfs" = "1" TO "num:i($HwDfsCount)"!][!//
[!FOR "DfsPort" = "1" TO "ecu:list('MCU.DFS.OutputPorts.List')[num:i($HwDfs)]"!][!//
[!IF "num:i($HwDfs) = num:i('1')"!][!VAR "ClkDfsPortname" = "concat('CORE_PLL_DFS',$DfsPort,'_CLK')"!][!ELSE!][!VAR "ClkDfsPortname" = "concat('PERIPH_PLL_DFS',$DfsPort,'_CLK')"!][!ENDIF!][!//
[!IF "num:i($HwDfs) = num:i('1')"!][!VAR "pathDFSUnderMcuControl" = "concat('McuCoreDfs/McuDfs_',$DfsPort,'/McuDFSUnderMcuControl')"!][!ELSE!][!VAR "pathDFSUnderMcuControl" = "concat('McuPeriphDfs/McuDfs_',$DfsPort,'/McuDFSUnderMcuControl')"!][!ENDIF!][!//
[!IF "node:value($pathDFSUnderMcuControl)"!][!//
[!CODE!][!//
            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > [!"num:i($CurrentDfsPort)"!]U
            {
                [!"($ClkDfsPortname)"!],
                [!CALL "GetDfsPortEnable","NumMcuPLL"="num:i($HwDfs - 1)","DfsPortIndex"="num:i($DfsPort)"!]U,
                {
                    [!CALL "GetMcuDFSPortMf","NumMcuPLL"="num:i($HwDfs - 1)","DfsPortIndex"="num:i($DfsPort)"!]
                },
            },
            #endif
[!ENDCODE!]
[!VAR "CurrentDfsPort" = "$CurrentDfsPort + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!FOR "DfsPortIterator" = "$NumOfDfsPortUnderMcuCtr" TO "num:i($NrOfOutPortsClkDfs - 1)"!][!//
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "DfsPortIterator" = "1" TO "num:i($NrOfOutPortsClkDfs)"!][!//
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
[!ENDFOR!][!//
[!ENDIF!][!//
        },

        /* EXTERNAL CLOCKS initialization. */
        {
[!FOR "ClkExternal" = "1" TO "num:i($NrOfClkExternal)"!][!//
[!VAR "ClkExternalname" = "ecu:list('MCU.ExtClock.List')[num:i($ClkExternal)]"!][!//
[!CODE!][!//
            #if CLOCK_IP_EXT_CLKS_NO  > [!"num:i($ClkExternal - 1)"!]U
            {
                [!"($ClkExternalname)"!],
                [!CALL "GetClockExternal","Name"="$ClkExternalname"!]U,
            },
            #endif
[!ENDCODE!]
[!ENDFOR!][!//
        },

        /* CLOCK GATE initialization. */
        {
    [!FOR "ClkGateIterator" = "1" TO "num:i($NrOfClkGates)"!]
            {
                RESERVED_CLK,
                0U,
            },
    [!ENDFOR!]
        },

        /* PCFS initialization. */
        {
[!IF "$NumOfUnderClkPcfs > num:i(0)"!][!//
[!VAR "ClkPcfsIterator" = "0"!][!//
[!FOR "CurrentCgm" = "1" TO "num:i($NrOfCgmx)"!][!//
[!VAR "cgm" = "ecu:list('MCU.CGM.CgmModules.List')[num:i($CurrentCgm)]"!][!//
[!VAR "capitalName" = "text:replace($cgm,substring($cgm,2),text:toupper(substring($cgm,2)))"!][!//
[!VAR "pcfscount" = "count(ecu:list(concat('MCU.',$capitalName,'.CgmPcfs.List')))"!][!//
[!FOR "CurrentPCFS" = "0" TO "num:i($pcfscount - 1)"!][!//
[!IF "node:value(concat('Mcu',$cgm,'SettingConfig/Mcu',$cgm,'PcsConfig/Mcu',$cgm,'PcsConfig_',$CurrentPCFS,'/McuClockPcfsUnderMcuControl'))"!][!//
[!CODE!][!//
            #if CLOCK_IP_PCFS_NO > [!"num:i($ClkPcfsIterator)"!]U
            {          
                [!CALL "GetNameClockSource","Name"="$cgm","Pcfs"="$CurrentPCFS"!],         
                [!CALL "GetmaxAllowableIDDchange","Name"="$cgm","Pcfs"="$CurrentPCFS"!]U,                
                [!CALL "GetMcuPCSStepDuration","Name"="$cgm"!]U,                           
                [!CALL "GetPcfsSelectorName","Name"="$cgm","Pcfs"="$CurrentPCFS"!],        
                [!CALL "GetPcfsClockSourceFrequency","Name"="$cgm","Pcfs"="$CurrentPCFS"!]U,                     
            },
            #endif
[!ENDCODE!]
[!VAR "ClkPcfsIterator" = "$ClkPcfsIterator + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!FOR "ClkPcfsIterator" = "$NumOfUnderClkPcfs" TO "num:i($NumOfPCFSs - 1)"!][!//
            #if CLOCK_IP_PCFS_NO > [!"num:i($ClkPcfsIterator)"!]U
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
            #endif
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "ClkPcfsIterator" = "1" TO "num:i($NumOfPCFSs)"!][!//
           #if CLOCK_IP_PCFS_NO > [!"num:i($ClkPcfsIterator - 1)"!]U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
[!ENDFOR!][!//
[!ENDIF!][!//
        },

        /* Clock monitor */ 
        {     
[!IF "$NumOfUnderClkMonitor > num:i(0)"!][!//
[!IF "node:exists("McuClkMonitor")"!][!//
[!VAR "ClkMonitorIterator" = "0"!][!//
[!VAR "ClkMonitorName" = "0"!][!//
[!LOOP "./McuClkMonitor/*"!][!//
[!VAR "ClkMonitorName" = "$ClkMonitorName + 1"!][!//
[!VAR "McuCmuName" = "ecu:list('MCU.CMU_FC.List')[num:i($ClkMonitorName)]"!][!//
[!IF "node:value(./McuClockMonitorUnderMcuControl)"!][!//
[!VAR "ClkMonitorIterator" = "$ClkMonitorIterator + 1"!][!//
            #if CLOCK_IP_CMUS_NO > [!"num:i($ClkMonitorIterator - 1)"!]U
            {
                [!"substring-after(substring-after($McuCmuName,'CMU_FC_'),'_')"!],            /* Clock name associated to clock monitor. */
                [!CALL "GetCmuEnable"!]U,                   /*Enable/disable clock monitor [!"McuCmuName"!] */
                (                                           /* IER for [!"McuCmuName"!] */
                CMU_FC_IER_FLLIE([!IF "./McuSyncFLLInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
                CMU_FC_IER_FHHIE([!IF "./McuSyncFHHInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
                CMU_FC_IER_FLLAIE([!IF "./McuAsyncFLLInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
                CMU_FC_IER_FHHAIE([!IF "./McuAsyncFHHInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!])
                ),
                [!CALL "GetMonitoredClockFrequency","Name"="$McuCmuName"!]U,
            },
            #endif
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!FOR "ClkMonitorIterator" = "$NumOfUnderClkMonitor" TO "num:i($NrOfClkMonitor - 1)"!][!//
            #if CLOCK_IP_CMUS_NO > [!"num:i($ClkMonitorIterator)"!]U
            {
                RESERVED_CLK,
                0U,
                0U,
                0U,
            },
            #endif
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "ClkMonitorIterator" = "1" TO "num:i($NrOfClkMonitor)"!][!//
           #if CLOCK_IP_CMUS_NO > [!"num:i($ClkMonitorIterator - 1)"!]U
           {
               RESERVED_CLK,
               0U,
               0U,
               0U,
           },
           #endif
[!ENDFOR!][!//
[!ENDIF!][!//
        },
        
        /* Specific peripheral initialization. */
        {
            [!"$specificCount"!]U,
            {
[!CALL "Print_Specific"!]
            },
        },
        
        /* Configured frequency values. */
        {
[!FOR "ClkConfiguredFrequency" = "1" TO "num:i($configureFrequenciesCount)"!][!//
[!VAR "ClkConfiguredFrequencyname" = "ecu:list('MCU.ConfiguredFrequency.List')[num:i($ClkConfiguredFrequency)]"!][!//
[!CODE!][!//
            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > [!"num:i($ClkConfiguredFrequency - 1)"!]U
            {
                [!"($ClkConfiguredFrequencyname)"!],
                [!CALL "GetClockConfiguredFrequency","Name"="$ClkConfiguredFrequencyname"!]U,
            },
            #endif
[!ENDCODE!]
[!ENDFOR!][!//
        },
    },
[!ENDCODE!]
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!CODE!]
};
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!]
