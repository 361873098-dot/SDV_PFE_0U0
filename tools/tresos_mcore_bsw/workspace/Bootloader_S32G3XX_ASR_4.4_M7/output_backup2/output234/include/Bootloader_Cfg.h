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

/* Compile switch to enable/disable images authentication */
#define BL_SUPPORT_AUTHENTICATION STD_OFF

/* Number of applications configured in the Bootloader plugin */
#define CONFIGURED_CORES_COUNT 2U

/*Compile switch to enable used of SD/eMMC card */
#define BL_SDHC_ENABLED STD_OFF

/* Compile switch to enable/disable secure boot sequence */
#define BL_ENABLE_SECURE_BOOT STD_ON

/* Compile switch to enable/disable  flexNOC init */
#define BL_ENABLE_FLEX_NOC STD_OFF

/* Key index in the cryptodal descriptors list */
#define BL_SEC_BOOT_KEY_INDEX 0

/* HSE system image storage address */
#define BL_SYS_IMAGE_STORAGE_ADDR 786432

/* Compile switch for COM boot usage */
#define BL_COM_BOOT_USED STD_OFF

/* Compile switch to enable debug breakpoint */
#define BL_USE_BREAKPOINT STD_ON

/* Compile switch to enable synchronized boot */
#define BL_SYNCHRONIZED_BOOT STD_ON

/* Compile switch to enable Safety enviroment  */
#define BL_USE_SAFETY STD_OFF

/* Compile switch to enable ddr configuration */
#define BL_CONFIGURE_DDR   STD_OFF

/* Macro defining whether image decryption is used or not */
#define BL_IMAGE_DECRYPTION_ENABLED STD_OFF

/* Macro abstracting all the cryptographic operations supported */
#define BL_CRYPTO_USED STD_ON

/* Macro defining whether A53 lockstep is enabled or not */
#define BL_ENABLE_A53_LOCKSTEP STD_OFF

/* This macro enables boot Presetup */
#define BL_PRE_SETUP_REQUIRED

/* Compile switch to enable/disable CRC check after DMA application image transfer */
#define BL_ENABLE_CRC_CHECK (STD_OFF)

/* Macro used to enable communication support on Bootloader*/
#define BL_BOOT_TRIGGER_ENABLED STD_OFF

#endif /* BOOTLOADER_CFG_H */
