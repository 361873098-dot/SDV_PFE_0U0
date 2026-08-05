/**
*   @file      Bootloader_Cfg.h
*   @version   23.02.0
*
*   @brief     Contains the configuration data for the Bootloader.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*    All Rights Reserved.
*
*    This file contains sample code only. It is not part of the production code deliverables.
*/

#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H

[!AUTOSPACING!]
[!NOCODE!]
[!CODE!]

/*==============================================================================
* GLOBAL SYMBOLIC CONSTANTS
==============================================================================*/

/* Used for indicating that an image is not encrypted */
#define UNENCRYPTED_BINARY  255

#define NUMBER_PARTITIONS  2

/* Flag for invalid flash memory address */
#define BL_INVALID_FLASH_ADDRESS    0xFFFFFFFFU

/* Flag for invalid ComManager session */
#define BL_INVALID_COM_SESSION      0xFFFFFFFFU

/* Flag for invalid MemDal block ID */
#define BL_INVALID_MEMBLOCK_ID      0xFFFFU

/* Flag for indicating an image which doesn't use CRC32 check */
#define BL_CRC32_NOT_USED           0U

/* Flag for un-encrypted images */
#define BL_NO_ENCRYPTION_ID         0xFFU
[!ENDCODE!]

[!SELECT "/AUTOSAR/TOP-LEVEL-PACKAGES/Bootloader/ELEMENTS/Bootloader"!]
    [!VAR "noConfiguredCoreSettings" = "num:i(count(CoreConfiguration/*))"!]
    [!VAR "SignatureAlgorithmEnabled" = "'STD_OFF'"!]
    [!VAR "SdhcEnabled" = "'STD_OFF'"!]
    [!VAR "ImageDecryptionEnabled" = "'STD_OFF'"!]
    [!VAR "CryptoUsed" = "'STD_OFF'"!]
    [!VAR "ComUsed" = "'STD_OFF'"!]

    [!LOOP "CoreConfiguration/*"!]
        [!VAR "AuthMethod" = "node:value(node:ref(BootSourcesCfg)/AuthenticationAlgorithm)"!]
        [!IF "$AuthMethod != 'NONE' and $AuthMethod != 'CRC32'"!]
            [!VAR "SignatureAlgorithmEnabled" = "'STD_ON'"!]
            [!VAR "CryptoUsed" = "'STD_ON'"!]
        [!ENDIF!]

        [!IF "node:refexists(node:ref(BootSourcesCfg)/EncryptionRef)"!]
            [!VAR "ImageDecryptionEnabled" = "'STD_ON'"!]
            [!VAR "CryptoUsed" = "'STD_ON'"!]
        [!ENDIF!]

        [!VAR "ImageStorage" = "node:value(node:ref(BootSourcesCfg)/BootSource)"!]
        [!IF "$ImageStorage = 'SDMMC'"!]
            [!VAR "SdhcEnabled" = "'STD_ON'"!]
        [!ELSEIF "$ImageStorage = 'COM'"!]
            [!VAR "ComUsed" = "'STD_ON'"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!IF "node:value(BootloaderGeneral/InTarget_debug_flag) = 'true'"!]
        [!VAR "use_breakpoint" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "use_breakpoint" = "'STD_OFF'"!]
    [!ENDIF!]
    [!IF "node:value(BootloaderGeneral/Safety_flag) = 'true'"!]
        [!VAR "use_safety" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "use_safety" = "'STD_OFF'"!]
    [!ENDIF!]
    [!IF "node:value(BootloaderGeneral/Bl_EnableSecBoot) = 'true'"!]
        [!VAR "secure_boot_enabled" = "'STD_ON'"!]
        [!VAR "secure_boot_key_index" = "num:i(node:ref(BootloaderGeneral/Bl_SecBootKeyRef)/@index)"!]
        [!VAR "sys_image_storage_addr" = "num:i(node:value(BootloaderGeneral/SysImageStorageAddr))"!]
        [!VAR "CryptoUsed" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "secure_boot_enabled" = "'STD_OFF'"!]
        [!VAR "secure_boot_key_index" = "num:i(0)"!]
        [!VAR "sys_image_storage_addr" = "num:i(0)"!]
    [!ENDIF!]
	[!IF "node:value(BootloaderGeneral/Bl_EnableFlexNoc) = 'true'"!]
        [!VAR "flex_noc_enabled" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "flex_noc_enabled" = "'STD_OFF'"!]
    [!ENDIF!]
    [!IF "node:value(BootloaderGeneral/Bl_SynchronizedBoot) = 'true'"!]
        [!VAR "synchronized_boot" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "synchronized_boot" = "'STD_OFF'"!]
    [!ENDIF!]
	
    [!IF "node:value(BootloaderGeneral/Bl_ConfigureDDR) = 'true'"!]
        [!VAR "configure_ddr" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "configure_ddr" = "'STD_OFF'"!]
    [!ENDIF!]

    [!IF "node:value(BootloaderGeneral/A53LockstepEnable) = 'true'"!]
        [!VAR "A53LockstepEnable" = "'STD_ON'"!]
    [!ELSE!]
        [!VAR "A53LockstepEnable" = "'STD_OFF'"!]
    [!ENDIF!]
[!CODE!]

/* Compile switch to enable/disable images authentication */
#define BL_SUPPORT_AUTHENTICATION [!"$SignatureAlgorithmEnabled"!]

/* Number of applications configured in the Bootloader plugin */
#define CONFIGURED_CORES_COUNT [!"$noConfiguredCoreSettings"!]U

/*Compile switch to enable used of SD/eMMC card */
#define BL_SDHC_ENABLED [!"$SdhcEnabled"!]

/* Compile switch to enable/disable secure boot sequence */
#define BL_ENABLE_SECURE_BOOT [!"$secure_boot_enabled"!]

/* Compile switch to enable/disable  flexNOC init */
#define BL_ENABLE_FLEX_NOC [!"$flex_noc_enabled"!]

/* Key index in the cryptodal descriptors list */
#define BL_SEC_BOOT_KEY_INDEX [!"$secure_boot_key_index"!]

/* HSE system image storage address */
#define BL_SYS_IMAGE_STORAGE_ADDR [!"$sys_image_storage_addr"!]

/* Compile switch for COM boot usage */
#define BL_COM_BOOT_USED [!"$ComUsed"!]

/* Compile switch to enable debug breakpoint */
#define BL_USE_BREAKPOINT [!"$use_breakpoint"!]

/* Compile switch to enable synchronized boot */
#define BL_SYNCHRONIZED_BOOT [!"$synchronized_boot"!]

/* Compile switch to enable Safety enviroment  */
#define BL_USE_SAFETY [!"$use_safety"!]

/* Compile switch to enable ddr configuration */
#define BL_CONFIGURE_DDR   [!"$configure_ddr"!]

/* Macro defining whether image decryption is used or not */
#define BL_IMAGE_DECRYPTION_ENABLED [!"$ImageDecryptionEnabled"!]

/* Macro abstracting all the cryptographic operations supported */
#define BL_CRYPTO_USED [!"$CryptoUsed"!]

/* Macro defining whether A53 lockstep is enabled or not */
#define BL_ENABLE_A53_LOCKSTEP [!"$A53LockstepEnable"!]

/* This macro enables boot Presetup */
#define BL_PRE_SETUP_REQUIRED

[!ENDCODE!]
[!ENDSELECT!]

[!SELECT "/AUTOSAR/TOP-LEVEL-PACKAGES/Mcl/ELEMENTS/Mcl/MclConfigSet/DMACrcChannel/*[1]"!]
[!CODE!]
/* To do:  Use BL_CRC_POLYNOMIAL when the pipeline load and authenticate will be used. */
/* Polynomial used for computing the CRC. */
#define BL_CRC_POLYNOMIAL [!"concat(node:value(./MclCRCPolynomialSelect),'_U32')"!]

/* To do:  Use BL_CRC_INITIAL_UPLOAD when the pipeline load and authenticate will be used. */
/* Initial value uploaded for CRC computation */
#define BL_CRC_INITIAL_UPLOAD [!"node:value(MclCRCInitialPolynome)"!]U

[!ENDCODE!]
[!ENDSELECT!]

[!SELECT "/AUTOSAR/TOP-LEVEL-PACKAGES/Bootloader/ELEMENTS/Bootloader"!]
    [!VAR "Use_CRC" = "'STD_OFF'"!]
    [!LOOP "BootSources/*"!]
        [!IF "AuthenticationAlgorithm = 'CRC32'"!]
            [!VAR "Use_CRC" = "'STD_ON'"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!CODE!]
/* Compile switch to enable/disable CRC check after DMA application image transfer */
#define BL_ENABLE_CRC_CHECK ([!"$Use_CRC"!])

[!ENDCODE!]

[!ENDSELECT!]
[!SELECT "/AUTOSAR/TOP-LEVEL-PACKAGES/Bootloader/ELEMENTS/Bootloader/Boot_Triggers/*"!]
[!IF "node:value(BootTriggerSupport) = 'true'"!]
[!CODE!]
/* Macro used to enable communication support on Bootloader*/
#define BL_BOOT_TRIGGER_ENABLED STD_ON

/* Macro used to define the timer used for communication timeout*/
#define GPT_TIMEOUT_CH [!"(node:value(node:ref(GptTimeoutChannel)/GptChannelId))"!]U

[!VAR "Freq" = "num:i(node:value(node:ref(node:value(node:ref('GptTimeoutChannel')))/GptChannelTickFrequency))"!]
[!VAR "TicksPerMs" =  "($Freq) div num:i(1000)"!]
[!VAR "ConfiguredPeriod" = "num:i(node:value(ComTimeoutTime))"!]
/* Macro used to define the communication timeout perriod[ticks]*/
#define GPT_TIMEOUT_PERIOD [!"num:i($TicksPerMs * $ConfiguredPeriod)"!]
[!ENDCODE!]
[!ELSE!]
[!CODE!]
/* Macro used to enable communication support on Bootloader*/
#define BL_BOOT_TRIGGER_ENABLED STD_OFF
[!ENDCODE!]
[!ENDIF!]
[!ENDSELECT!]
[!ENDNOCODE!]

#endif /* BOOTLOADER_CFG_H */
