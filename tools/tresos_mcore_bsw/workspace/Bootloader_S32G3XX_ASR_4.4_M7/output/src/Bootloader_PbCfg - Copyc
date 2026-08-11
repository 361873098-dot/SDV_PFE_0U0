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


/* List of boot images for core M7_0 */
static Bl_BootImageFragmentType ipcp_freertos[1] =
{
    /* ImageFragments_0 */
    {
        /* u32FlashAddress */
        0x200000,
        /* u32ComSessionId */
        BL_INVALID_COM_SESSION,
        /* u16MemBlockId */
        BL_INVALID_MEMBLOCK_ID,
        /* u32DestinationAddress */
        0x34400000,
        /* u32Size */
        2621440,
		/* u8SMRIndex */
        0,
        /* u32CrcValue */
        BL_CRC32_NOT_USED
    }
};

/* List of boot images for core A53_0 */
static Bl_BootImageFragmentType linux_bsp_atf[1] =
{
    /* ImageFragments_0 */
    {
        /* u32FlashAddress */
        0x100000,
        /* u32ComSessionId */
        BL_INVALID_COM_SESSION,
        /* u16MemBlockId */
        BL_INVALID_MEMBLOCK_ID,
        /* u32DestinationAddress */
        0x342f9a00,
        /* u32Size */
        262144,
		/* u8SMRIndex */
        0,
        /* u32CrcValue */
        BL_CRC32_NOT_USED
    }
};

/* Cores boot configuration */
Bl_ApplicationDetails bootApplications[CONFIGURED_CORES_COUNT] =
{

    /* Boot configuration for core M7_0 */
    {
        /* Target core ID */
        M7_0,

        /* Image storage */
        BS_QSPI,

        /* The address of the application reset handler */
        0x34400010,

        /* Authentication algorithm */
        NONE,

        /* Crypto descriptor index */
        BL_NO_ENCRYPTION_ID,

        /* Number of images to be loaded */
        1,

        /* List of images to be loaded */
        ipcp_freertos,

        /* Critical application flag */
        TRUE,

        /* Flag to mark if bootloader should start the core */
        TRUE
    },

    /* Boot configuration for core A53_0 */
    {
        /* Target core ID */
        A53_0,

        /* Image storage */
        BS_QSPI,

        /* The address of the application reset handler */
        0x34302000,

        /* Authentication algorithm */
        NONE,

        /* Crypto descriptor index */
        BL_NO_ENCRYPTION_ID,

        /* Number of images to be loaded */
        1,

        /* List of images to be loaded */
        linux_bsp_atf,

        /* Critical application flag */
        TRUE,

        /* Flag to mark if bootloader should start the core */
        TRUE
    }
};


Bl_ResetReasonType Bl_AcceptedResetReason = (1 << 4) |
                                            (1 << 3) |
                                            (1 << 2) |
                                            (1 << 1) |
                                            (1 << 0);

