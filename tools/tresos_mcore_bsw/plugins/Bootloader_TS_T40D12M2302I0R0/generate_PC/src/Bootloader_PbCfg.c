/**
*   @file      Bootloader_PbCfg.c
*   @version   23.02.0
*
*   @brief     Contains the post-build configuration data structures.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*    All Rights Reserved.
*
*    This file contains sample code only. It is not part of the production code deliverables.
*/

#include "Bootloader.h"
#include "Bootloader_Cfg.h"

#if (STD_ON == BL_COM_BOOT_USED)
#include "ComManager_Cfg.h"
#endif /* STD_ON == BL_COM_BOOT_USED */

#if (STD_ON == BL_IMAGE_DECRYPTION_ENABLED)
#include "CryptoDal_Cfg.h"
#endif /* STD_ON == BL_IMAGE_DECRYPTION_ENABLED */

/*==============================================================================
* GLOBAL VARIABLES
==============================================================================*/

[!AUTOSPACING!]
[!NOCODE!]

[!SELECT "/AUTOSAR/TOP-LEVEL-PACKAGES/Bootloader/ELEMENTS/Bootloader"!]
	[!VAR "SMR_IDX_VALUE_TOTAL" = "0"!]
	[!VAR "SMR_IDX_VALUE_COUNT" = "0"!]
	[!VAR "SMR_IDX_VALUE_LIST" = "'0'"!]
    [!VAR "SECURE_BOOT_ENABLED" = "node:value(/AUTOSAR/TOP-LEVEL-PACKAGES/Bootloader/ELEMENTS/Bootloader/BootloaderGeneral/Bl_EnableSecBoot)"!]
    [!LOOP "CoreConfiguration/*"!]
        [!VAR "CORE_ID" = "node:value(CoreID)"!]
        [!VAR "IMAGE_STORAGE" = "node:value(node:ref(BootSourcesCfg)/BootSource)"!]
        [!VAR "IMAGES_NUMBER" = "num:i(count(node:ref(BootSourcesCfg)/ImageFragments/*))"!]
        [!VAR "APP_RESET_HANDLER" = "num:i(node:value(node:ref(BootSourcesCfg)/ApplicationResetHandler))"!]
        [!VAR "SIGNATURE_ALGORITHM" = "node:value(node:ref(BootSourcesCfg)/AuthenticationAlgorithm)"!]
        [!VAR "RESET_HANDLER_CHECK" = "num:i(0)"!]
        [!VAR "RAM_IMAGE_RANGE" = "''"!]
        [!VAR "CONFIG_NAME" = "node:name(node:ref(BootSourcesCfg))"!]

        [!CODE!]
[!CR!]/* List of boot images for core [!"$CORE_ID"!] */
static Bl_BootImageFragmentType [!"$CONFIG_NAME"!][[!"$IMAGES_NUMBER"!]] =
{       [!ENDCODE!]

        [!LOOP "node:ref(BootSourcesCfg)/ImageFragments/*"!]
            [!VAR "FLASH_STORAGE_ADDRESS" = "'BL_INVALID_FLASH_ADDRESS'"!]
            [!VAR "COMMANAGER_SESSION_REF" = "'BL_INVALID_COM_SESSION'"!]
            [!VAR "MEM_BLOCK_ID" = "'BL_INVALID_MEMBLOCK_ID'"!]
            [!VAR "RAM_ADDRESS" = "num:i(node:value(LoadAddressRam))"!]
            [!VAR "CHUNK_SIZE" = "num:i(node:value(ImageSize))"!]
			[!VAR "SMR_INDEX" = "num:i(node:value(SmrIndex))"!]
            [!VAR "CRC_VALUE" = "'BL_CRC32_NOT_USED'"!]

            [!IF "$SIGNATURE_ALGORITHM = 'CRC32' and $IMAGE_STORAGE = 'QSPI'"!]
                [!VAR "CRC_VALUE" = "num:i(node:value(CrcValue))"!]
            [!ENDIF!]

            [!IF "$IMAGE_STORAGE = 'QSPI'"!]
                [!VAR "FLASH_STORAGE_ADDRESS" = "num:inttohex(node:value(SourceAddressQspi))"!]
                [!IF "$SIGNATURE_ALGORITHM = 'SHA1' or $SIGNATURE_ALGORITHM = 'SHA256'"!]
                    [!// QSPI images auth with SHA1/SHA256 contains the size in the signature header
                    [!VAR "CHUNK_SIZE" = "num:i(0)"!]
                [!ENDIF!]
            [!ENDIF!]
            [!IF "$IMAGE_STORAGE = 'SDMMC'"!]
                [!VAR "MEM_BLOCK_ID" = "node:ref(MemoryBlockId)/MemDalSdhcBlockId"!]
                [!VAR "CHUNK_SIZE" = "num:i(node:ref(MemoryBlockId)/MemDalSdhcBlockSize)"!]
            [!ENDIF!]
            [!IF "$IMAGE_STORAGE = 'COM'"!]
                [!VAR "COMMANAGER_SESSION_REF" = "concat('COMMANAGER_', text:toupper(node:name(node:ref(ComManagerSessionReference))))"!]
            [!ENDIF!]

            [!VAR "START_RAM_ADDRESS" = "$RAM_ADDRESS"!]
            [!VAR "END_RAM_ADDRESS" = "num:i($RAM_ADDRESS + $CHUNK_SIZE)"!]

            [!VAR "RAM_IMAGE_RANGE" = "concat($RAM_IMAGE_RANGE, '[', num:inttohex($START_RAM_ADDRESS), ' - ', num:inttohex($END_RAM_ADDRESS), '] ')"!]
            [!IF "$APP_RESET_HANDLER >= $START_RAM_ADDRESS and $APP_RESET_HANDLER < $END_RAM_ADDRESS"!]
                [!VAR "RESET_HANDLER_CHECK" = "num:i($RESET_HANDLER_CHECK + 1)"!]
            [!ENDIF!]

            [!CODE!][!CR!]
    /* [!"@name"!] */
    {
        /* u32FlashAddress */
        [!"$FLASH_STORAGE_ADDRESS"!],
        /* u32ComSessionId */
        [!"$COMMANAGER_SESSION_REF"!],
        /* u16MemBlockId */
        [!"$MEM_BLOCK_ID"!],
        /* u32DestinationAddress */
        [!" num:inttohex($RAM_ADDRESS)"!],
        /* u32Size */
        [!"$CHUNK_SIZE"!],
		/* u8SMRIndex */
        [!"$SMR_INDEX"!],
        /* u32CrcValue */
        [!"$CRC_VALUE"!]
    }[!IF "num:i($IMAGES_NUMBER - 1) != num:i(@index)"!],[!ELSE!][!CR!][!ENDIF!]
            [!ENDCODE!]

			[!IF "$SMR_INDEX != '0'"!]
                [!IF " $IMAGE_STORAGE != 'QSPI' or $SIGNATURE_ALGORITHM != 'NONE' or $SECURE_BOOT_ENABLED !='true'"!]
                    [!ERROR!]
SMR copy functionality(Non zero SMR Index on any used Boot Source) is only supported for Secure Boot with QSPI Boot source and without any authentication method.
                    [!ENDERROR!]
                [!ENDIF!]

			    [!VAR "SMR_IDX_VALUE_LIST" = "concat($SMR_IDX_VALUE_LIST,' ',$SMR_INDEX)"!]
			    [!VAR "SMR_IDX_VALUE_COUNT" = "num:i($SMR_IDX_VALUE_COUNT + 1)"!]
			    [!VAR "SMR_IDX_VALUE_TOTAL" = "num:i($SMR_IDX_VALUE_TOTAL + $SMR_INDEX)"!]
			[!ENDIF!]
        [!ENDLOOP!]
        [!IF "not($IMAGE_STORAGE = 'QSPI' and ($SIGNATURE_ALGORITHM = 'SHA1' or $SIGNATURE_ALGORITHM = 'SHA256'))"!]
            [!IF "num:i($RESET_HANDLER_CHECK) != 1"!]
                [!ERROR!]
Boot source configuration [!"$CONFIG_NAME"!] for core [!"$CORE_ID"!] contains errors. The ResetHandler address is not matching any RAM image!
ResetHandler = [!"num:inttohex($APP_RESET_HANDLER)"!]
RAM images ranges = [!"$RAM_IMAGE_RANGE"!]
The ResetHandler must be contained in one image range.
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]

        [!CODE!]
};[!CR!]
        [!ENDCODE!]
    [!ENDLOOP!]

	[!FOR "counter1" = "1" TO "$SMR_IDX_VALUE_COUNT + 1"!]
		[!FOR "counter2" = "$counter1 + 1" TO "$SMR_IDX_VALUE_COUNT + 1"!]
			[!IF "text:split($SMR_IDX_VALUE_LIST)[position() = $counter1] = text:split($SMR_IDX_VALUE_LIST)[position() = $counter2]"!]
				[!ERROR!]
A unique SMR Index for each image fragment for all listed cores in Core Configuration and their coresponding boot sources is required! Verify that each non zero SMR Index has a unique numerical value.
				[!ENDERROR!]
			[!ENDIF!]
		[!ENDFOR!]
	[!ENDFOR!]

    [!FOR "counter1" = "1" TO "$SMR_IDX_VALUE_COUNT + 1"!]
		[!FOR "counter2" = "$counter1 + 1" TO "$SMR_IDX_VALUE_COUNT + 1"!]
				[!IF "$SMR_IDX_VALUE_TOTAL!= ($SMR_IDX_VALUE_COUNT * ($SMR_IDX_VALUE_COUNT + 1)) div 2"!]
					[!ERROR!]
A non gapped SMR Index values list for all image fragments that are assigned to the cores from Core Configuration is required! Example: SMR Indexes 1, 2 for M7_0 and it's boot source image fragments and SMR Indexes 3,4  for A53_0 and it's boot source image fragments.
					[!ENDERROR!]
			[!ENDIF!]
		[!ENDFOR!]
	[!ENDFOR!]


    [!VAR "CoreConfigsNumber" = "num:i(count(CoreConfiguration/*))"!]

[!CODE!]

/* Cores boot configuration */
Bl_ApplicationDetails bootApplications[CONFIGURED_CORES_COUNT] =
{
[!ENDCODE!]
    [!LOOP "CoreConfiguration/*"!]
        [!VAR "CORE_ID" = "node:value(CoreID)"!]
        [!VAR "IMAGE_STORAGE" = "node:value(node:ref(BootSourcesCfg)/BootSource)"!]
        [!VAR "APP_RESET_HANDLER" = "num:i(node:value(node:ref(BootSourcesCfg)/ApplicationResetHandler))"!]
        [!VAR "SIGNATURE_ALGORITHM" = "node:value(node:ref(BootSourcesCfg)/AuthenticationAlgorithm)"!]
        [!VAR "IMAGES_NUMBER" = "num:i(count(node:ref(BootSourcesCfg)/ImageFragments/*))"!]
        [!VAR "CRYPTO_INDEX" = "'BL_NO_ENCRYPTION_ID'"!]

        [!IF "node:refexists(node:ref(BootSourcesCfg)/EncryptionRef)"!]
            [!VAR "CRYPTO_INDEX" = "node:name(node:ref(node:ref(BootSourcesCfg)/EncryptionRef))"!]
        [!ENDIF!]

        [!CODE!][!CR!]
    /* Boot configuration for core [!"$CORE_ID"!] */
    {
        /* Target core ID */
        [!"$CORE_ID"!],

        /* Image storage */
        BS_[!"$IMAGE_STORAGE"!],

        /* The address of the application reset handler */
        [!"num:inttohex($APP_RESET_HANDLER)"!],

        /* Authentication algorithm */
        [!"$SIGNATURE_ALGORITHM"!],

        /* Crypto descriptor index */
        [!"$CRYPTO_INDEX"!],

        /* Number of images to be loaded */
        [!"$IMAGES_NUMBER"!],

        /* List of images to be loaded */
        [!"node:name(node:ref(BootSourcesCfg))"!],

        /* Critical application flag */
        [!"text:toupper(IsCriticalApplication)"!],

        /* Flag to mark if bootloader should start the core */
        [!"text:toupper(StartCore)"!]
    }[!IF "num:i($CoreConfigsNumber - 1) != num:i(@index)"!],[!ELSE!][!CR!]};[!CR!][!ENDIF!]

        [!ENDCODE!]
    [!ENDLOOP!]
    [!CODE!][!CR!]
Bl_ResetReasonType Bl_AcceptedResetReason = ([!"num:i(number(contains(node:value(BootloaderAcceptedResetReasons/Bl_POR), 'true')))"!] << 4) |
                                            ([!"num:i(number(contains(node:value (BootloaderAcceptedResetReasons/Bl_DestructiveReset), 'true')))"!] << 3) |
                                            ([!"num:i(number(contains(node:value (BootloaderAcceptedResetReasons/Bl_FunctionalReset), 'true')))"!] << 2) |
                                            ([!"num:i(number(contains(node:value (BootloaderAcceptedResetReasons/Bl_StandbyReset), 'true')))"!] << 1) |
                                            ([!"num:i(number(contains(node:value (BootloaderAcceptedResetReasons/Bl_UnknownReset), 'true')))"!] << 0);

    [!ENDCODE!]
[!ENDSELECT!]

[!ENDNOCODE!]
