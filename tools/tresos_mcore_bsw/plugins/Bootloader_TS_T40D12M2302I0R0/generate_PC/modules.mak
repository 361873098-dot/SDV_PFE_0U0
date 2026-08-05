[!AUTOSPACING!]
#===============================================================================
#
#    @file       modules.mak
#    @version    23.02.0
#
#    @brief      Configuration modules
#    @details    Makefile containing the modules and functionalities included
#                in the build.
#
#    Platform        : CORTEXM
#    Build Version   : S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
#
#   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
#       All Rights Reserved.
#
#    This file contains sample code only.
#    It is not part of the production code deliverables.
#===============================================================================

[!NOCODE!]
[!CODE!]
SAMPLE_APP_NAME := Bootloader

# The Platform Integration DALs to be used.
DALS_LIST := SysDal
include $(TRESOS_WORKSPACE_DIR)/SysDal_Components.mak

DRIVERS_MODULE_LIST += Fls MemIf

[!IF "node:exists('/AUTOSAR/TOP-LEVEL-PACKAGES/Rm/ELEMENTS/Rm')"!]
[!CODE!]
DRIVERS_MODULE_LIST += Rm
[!ENDCODE!]
[!ENDIF!]

[!IF "node:exists('/AUTOSAR/TOP-LEVEL-PACKAGES/Uart/ELEMENTS/Uart')"!]
[!CODE!]
DRIVERS_MODULE_LIST += Uart
[!ENDCODE!]
[!ENDIF!]

[!ENDCODE!]

[!SELECT "/AUTOSAR/TOP-LEVEL-PACKAGES/Bootloader/ELEMENTS/Bootloader"!]
    [!VAR "CryptoUsed" = "num:i(0)"!]
    [!VAR "ComUsed" = "num:i(0)"!]
    [!VAR "SdhcEnabled" = "'STD_OFF'"!]
    [!LOOP "BootSources/*"!]
        [!IF "AuthenticationAlgorithm != 'NONE' and AuthenticationAlgorithm != 'CRC32'"!]
            [!VAR "CryptoUsed" = "num:i(1)"!]
        [!ENDIF!]
        [!IF "node:refexists(EncryptionRef)"!]
            [!VAR "CryptoUsed" = "num:i(1)"!]
        [!ENDIF!]
        [!IF "ImageStorage = 'SDMMC'"!]
            [!VAR "SdhcEnabled" = "'STD_ON'"!]
        [!ELSEIF "ImageStorage = 'COM'"!]
            [!VAR "ComUsed" = "num:i(1)"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "node:value(BootloaderGeneral/Bl_EnableSecBoot) = 'true'"!]
        [!VAR "CryptoUsed" = "num:i(1)"!]
    [!ENDIF!]
[!CODE!]
[!SELECT "Boot_Triggers/*"!][!//
[!IF "(BootTriggerSupport = 'true') or ($ComUsed = num:i(1))"!]
DRIVERS_MODULE_LIST += EcuM Gpt
[!ENDIF!]
[!ENDSELECT!]

[!IF "node:exists('/AUTOSAR/TOP-LEVEL-PACKAGES/ComDal/ELEMENTS/ComDal')"!]
[!CODE!]
DALS_LIST += ComDal
-include $(TRESOS_WORKSPACE_DIR)/ComDal_Components.mak
[!ENDCODE!]
[!ENDIF!]

[!IF "$ComUsed = num:i(1)"!]
MANAGERS_LIST += ComManager
[!ENDIF!]

[!IF "num:i($CryptoUsed) = num:i(1)"!]
DRIVERS_MODULE_LIST += Crypto CryIf Csm
DALS_LIST += CryptoDal
[!ENDIF!]

[!IF "node:value(BootloaderGeneral/Safety_flag) = 'true'"!]
SAF_MODULE_LIST := SafetyBase Crcu eMcem mSel sCheck sBoot sReco Bist Rte
[!ENDIF!]

[!IF "node:exists('/AUTOSAR/TOP-LEVEL-PACKAGES/MemDal/ELEMENTS/MemDal')"!]
DALS_LIST += MemDal
include $(TRESOS_WORKSPACE_DIR)/MemDal_Components.mak
[!ENDIF!]

[!IF "$SdhcEnabled = 'STD_ON'"!]
SDHC_ENABLED := ON
[!ELSE!]
SDHC_ENABLED := OFF
[!ENDIF!]

[!IF "node:value(BootloaderGeneral/Safety_flag) = 'true'"!]
SAF_ENABLED := ON
[!ELSE!]
SAF_ENABLED := OFF
[!ENDIF!]

[!IF "node:value(BootloaderConsoleLog/Bl_ConsoleLog) = 'true'"!]
[!VAR "console_com_index" = "num:i(node:ref(BootloaderConsoleLog/Bl_ConsoleComChannelRef)/@index)"!]
CCOPT += -DCONSOLE_COMDAL_CHANNEL=[!"$console_com_index"!]
CCOPT += -DCONSOLE_ENABLED=STD_ON
CCOPT += -DCONSOLE_TAG=\"bootloader\"
[!ELSE!]
CCOPT += -DCONSOLE_ENABLED=STD_OFF
[!ENDIF!]

[!ENDCODE!]
[!ENDSELECT!]
[!ENDNOCODE!]
