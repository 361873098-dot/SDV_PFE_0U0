/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef OCOTP_IP_H
#define OCOTP_IP_H

/**
*   @file
*
*   @addtogroup OCOTP_IP
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
#include "Ocotp_Ip_Cfg.h"
#include "Ocotp_Ip_Types.h"
#include "Ocotp_Ip_Features.h"
#include "Devassert.h"
#include "OsIf.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IP_VENDOR_ID                    43
#define OCOTP_IP_AR_RELEASE_MAJOR_VERSION     4
#define OCOTP_IP_AR_RELEASE_MINOR_VERSION     4
#define OCOTP_IP_AR_RELEASE_REVISION_VERSION  0
#define OCOTP_IP_SW_MAJOR_VERSION             4
#define OCOTP_IP_SW_MINOR_VERSION             0
#define OCOTP_IP_SW_PATCH_VERSION             2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Ip_Cfg header file are of the same vendor */
#if (OCOTP_IP_VENDOR_ID != OCOTP_IP_VENDOR_ID_CFG)
    #error "Ocotp_Ip.h and Ocotp_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Cfg header file are of the same Autosar version */
#if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION    != OCOTP_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (OCOTP_IP_AR_RELEASE_MINOR_VERSION    != OCOTP_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (OCOTP_IP_AR_RELEASE_REVISION_VERSION != OCOTP_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ocotp_Ip.h and Ocotp_Ip_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Ip_Cfg header file are of the same Software version */
#if ((OCOTP_IP_SW_MAJOR_VERSION != OCOTP_IP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_IP_SW_MINOR_VERSION != OCOTP_IP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_IP_SW_PATCH_VERSION != OCOTP_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_Ip.h and Ocotp_Ip_Cfg.h are different"
#endif

/* Check if current file and Ocotp_Ip_Type header file are of the same vendor */
#if (OCOTP_IP_VENDOR_ID != OCOTP_IP_TYPES_VENDOR_ID)
    #error "Ocotp_Ip.h and Ocotp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Type header file are of the same Autosar version */
#if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION    != OCOTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IP_AR_RELEASE_MINOR_VERSION    != OCOTP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IP_AR_RELEASE_REVISION_VERSION != OCOTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_Ip.h and Ocotp_Ip_Types.h are different"
#endif
/* Check if current file and Ocotp_Ip_Type header file are of the same Software version */
#if ((OCOTP_IP_SW_MAJOR_VERSION != OCOTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_IP_SW_MINOR_VERSION != OCOTP_IP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_IP_SW_PATCH_VERSION != OCOTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Ip.h and Ocotp_Types.h are different"
#endif

/* Check if current file and Ocotp_Ip_Features header file are of the same vendor */
#if (OCOTP_IP_VENDOR_ID != OCOTP_IP_FEATURES_VENDOR_ID)
    #error "Ocotp_Ip.h and Ocotp_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Features header file are of the same Autosar version */
#if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION    != OCOTP_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IP_AR_RELEASE_MINOR_VERSION    != OCOTP_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IP_AR_RELEASE_REVISION_VERSION != OCOTP_IP_FEATURES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_Ip.h and Ocotp_Ip_Features.h are different"
#endif
/* Check if current file and Ocotp_Ip_Features header file are of the same Software version */
#if ((OCOTP_IP_SW_MAJOR_VERSION != OCOTP_IP_FEATURES_SW_MAJOR_VERSION) || \
     (OCOTP_IP_SW_MINOR_VERSION != OCOTP_IP_FEATURES_SW_MINOR_VERSION) || \
     (OCOTP_IP_SW_PATCH_VERSION != OCOTP_IP_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Ip.h and Ocotp_Ip_Features.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same Autosar version */
    #if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocotp_Ip.h and Devassert.h are different"
    #endif

        /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocotp_Ip.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#if (OCOTP_IP_DEV_ERROR_DETECT == STD_ON)
#define     DEV_ASSERT_OCOTP(x)   DevAssert((x))
#else
#define     DEV_ASSERT_OCOTP(x)   (void)(x);
#endif

#define OCOTP_CTRL_SYS_WRITE      2U
#define OCOTP_CTRL_SYS_READ       1U
#define OCOTP_AUTH_KEY            0x12U
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"
/**
 * @brief        The function initializes Ocotp module.
 * @details      The function clear all errors flag and initializes Ocotp module.
 *
 * @param[in]    pConfig       pointer points to configuration structure.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if module is initialized successfully.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_Init(const Ocotp_Ip_ConfigType *pConfig);

/**
 * @brief        The function de-initializes Ocotp module.
 * @details      The function de-initializes Ocotp module.
 *
 * @param[in]    instance       hardware instance.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Ocotp_Ip_DeInit(uint32 instance);

#if (OCOTP_IP_WRITE_EFUSE_API == STD_ON)
/**
 * @brief        The function writes data to the specified eFuse.
 * @details      The function writes data to the specified eFuse.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of eFuse.
 * @param[in]    data           data to be written.
 * @param[in]    eccEnable      enable ECC protection for current fuse word or not.
 * @param[in]    blocking       TRUE: write operation is blocking. FALSE: otherwise.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if write operation is successful.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_ERROR_TIMEOUT timeout supervision is enabled and timeout occurred.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_WriteEFuse
(
    uint32 instance,
    uint32 address,
    uint32 data,
    boolean bEccEnable,
    boolean bBlocking
);
#endif /* OCOTP_IP_WRITE_EFUSE_API == STD_ON */

#if (OCOTP_IP_WRITE_SHADOW_API == STD_ON)
/**
 * @brief        The function writes data to the specified shadow register.
 * @details      The function writes data to the specified shadow register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of shadow register.
 * @param[in]    data           data to be written.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if write operation is successful.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_WriteShadowRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 data
);
#endif /* OCOTP_IP_WRITE_SHADOW_API == STD_ON */

#if (OCOTP_IP_READ_EFUSE_API == STD_ON)
/**
 * @brief        The function reads data from the specified eFuse.
 * @details      The function reads data from the specified eFuse.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of eFuse.
 * @param[in]    data           pointer points to data result.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if read operation is successful.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_ERROR_TIMEOUT timeout supervision is enabled and timeout occurred.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_ReadEFuse
(
    uint32 instance,
    uint32 address,
    uint32* data
);
#endif /* OCOTP_IP_READ_EFUSE_API == STD_ON */

#if (OCOTP_IP_READ_SHADOW_API == STD_ON)
/**
 * @brief        The function reads data from the specified shadow register.
 * @details      The function reads data from the specified shadow register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of shadow register.
 * @param[in]    data           pointer points to data result.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if read operation is successful.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_ReadShadowRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 *data
);
#endif /* OCOTP_IP_READ_SHADOW_API == STD_ON */

#if (OCOTP_IP_ECC_GET_ERROR_API == STD_ON)
/**
 * @brief        The function gets ECC error from the specified eFuse.
 * @details      The function gets ECC error from the specified eFuse.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of eFuse.
 * @param[in]    typeECC        type of ECC to be checked(OCOTP_IP_ECC_SINGLE_ERROR, OCOTP_IP_ECC_DOUBLE_ERROR).
 *
 * @return       boolean
 * @retval       TRUE if ECC error flag is set.
 * @retval       FALSE if ECC error flag is not set.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
boolean Ocotp_Ip_EccGetError
(
    uint32 instance,
    uint32 address,
    Ocotp_Ip_EccErrorType typeECC
);
#endif /* OCOTP_IP_ECC_GET_ERROR_API == STD_ON */

/**
 * @brief        The function clears all errors flags.
 * @details      The function clears all errors flags.
 *
 * @param[in]    instance       hardware instance.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Ocotp_Ip_ClearErrorFlags (uint32 instance);

#if (OCOTP_IP_READ_GP_REGISTER_API == STD_ON)
/**
 * @brief        The function reads data from the specified GP register.
 * @details      The function reads data from the specified GP register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of GP register.
 *
 * @return       uint32
 * @retval       data read from GP register
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
uint32 Ocotp_Ip_ReadGpRegister
(
    uint32 instance,
    uint32 indexRegister
);
#endif /* OCOTP_IP_READ_GP_REGISTER_API == STD_ON */

#if (OCOTP_IP_WRITE_GP_REGISTER_API == STD_ON)
/**
 * @brief        The function writes data to the specified GP register.
 * @details      The function writes data to the specified GP register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of GP register.
 * @param[in]    data           data to be written.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Ocotp_Ip_WriteGpRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 data
);
#endif /* OCOTP_IP_WRITE_GP_REGISTER_API == STD_ON */

#ifdef OCOTP_IP_READ_STR_REGISTER_API
#if (OCOTP_IP_READ_STR_REGISTER_API == STD_ON)
/**
 * @brief        The function reads data from the specified STR register.
 * @details      The function reads data from the specified STR register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of STR register.
 *
 * @return       uint32
 * @retval       data read from STR register
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
uint32 Ocotp_Ip_ReadStrRegister
(
    uint32 instance,
    uint32 indexRegister
);
#endif /* OCOTP_IP_READ_STR_REGISTER_API == STD_ON */

#if (OCOTP_IP_WRITE_STR_REGISTER_API == STD_ON)
/**
 * @brief        The function writes data to the specified STR register.
 * @details      The function writes data to the specified STR register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of STR register.
 * @param[in]    data           data to be written.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Ocotp_Ip_WriteStrRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 data
);
#endif /* OCOTP_IP_WRITE_STR_REGISTER_API == STD_ON */
#endif /* define OCOTP_IP_READ_STR_REGISTER_API */

#if (OCOTP_IP_ECC_ERROR_INJECT_API == STD_ON)
/**
 * @brief        The function injects Ecc error into the specified shadow register.
 * @details      The function inverts value in the specified bit postion in shadow register.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    indexRegister  index of shadow register.
 * @param[in]    bit            bit postion which will be inverted.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Ocotp_Ip_EccErrorInject
(
    uint32 instance,
    uint32 indexRegister,
    uint32 bit
);
#endif /* OCOTP_IP_ECC_ERROR_INJECT_API == STD_ON */

#if (OCOTP_IP_SET_MODE_API == STD_ON)
/**
 * @brief        The function sets mode operation for Ocotp.
 * @details      The function sets mode operation for Ocotp.
 *               If mode is OCOTP_FBXC_NORMAL_MODE: module is in normal running mode.
 *               If mode is OCOTP_FBXC_POWER_DOWN_MODE: module is in powerdown mode.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    mode           mode to be set.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if set mode operation is successful.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 * @retval       STATUS_OCOTP_IP_ERROR_TIMEOUT timeout supervision is enbaled and timeout occurred.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_Setmode
(
    uint32 instance,
    Ocotp_Ip_ModeType mode
);
#endif /* OCOTP_IP_SET_MODE_API == STD_ON */


/**
 * @brief        The function checks busy and error state of hardware.
 * @details      The function checks busy and error state of hardware.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if hardware is ready.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_GetBusyState (uint32 instance);

#if (OCOTP_IP_CRC_TEST_API == STD_ON)
/**
 * @brief        The function calculates and writes CRC value to CRC fuse word base on the input data.
 * @details      The function calculates and writes CRC value to CRC fuse word base on the input data.
 *
 * @param[in]    instance              hardware instance.
 * @param[in]    CRCEfuseAddress       address of CRC fuse word.
 * @param[in]    dataPtr               input data pointer.
 * @param[in]    dataSize              size of data(in 4 bytes).
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if write CRC value is successful.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_CalculateAndWriteCrcValue
(
    uint32 instance,
    uint32 CRCEfuseAddress,
    const uint32* dataPtr,
    uint32 dataSize
);

/*!
 * @brief tests CRC32 in specified region
 *
 * @param instance                OCOTP peripheral instance number
 * @param crcEFuseWordAddress     address of CRC fuse word
 * @param startAddress            start address of the specified region
 * @param endAddress              end address of the specified region
 * @return    STATUS_OCOTP_IP_SUCCESS - CRC test passed. or otherwise CRC test failed
 */
Ocotp_Ip_StatusType Ocotp_Ip_CrcTest
(
    uint32 instance,
    uint32 crcEFuseWordAddress,
    uint32 startAddress,
    uint32 endAddress
);
#endif /* OCOTP_IP_CRC_TEST_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCOTP_IP_H */
