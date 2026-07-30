
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
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_OCOTP_H_
#define CDD_OCOTP_H_

/**
*   @file
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Ocotp_Cfg.h"
#include "Ocotp_Types.h"
#include "Ocotp_IPW.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_OCOTP_VENDOR_ID                    43
#define CDD_OCOTP_AR_RELEASE_MAJOR_VERSION     4
#define CDD_OCOTP_AR_RELEASE_MINOR_VERSION     4
#define CDD_OCOTP_AR_RELEASE_REVISION_VERSION  0
#define CDD_OCOTP_SW_MAJOR_VERSION             4
#define CDD_OCOTP_SW_MINOR_VERSION             0
#define CDD_OCOTP_SW_PATCH_VERSION             2
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Cfg.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
    #error "CDD_Ocotp.h and Ocotp_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION != OCOTP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (CDD_OCOTP_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (CDD_OCOTP_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Cfg.h are different"
#endif

/* Check if current file and Ocotp_Types.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID != OCOTP_TYPES_VENDOR_ID)
    #error "CDD_Ocotp.h and Ocotp_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Types.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION != OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION != OCOTP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION != OCOTP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Types.h are different"
#endif
/* Check if current file and Ocotp_Types.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION != OCOTP_TYPES_SW_MAJOR_VERSION) || \
     (CDD_OCOTP_SW_MINOR_VERSION != OCOTP_TYPES_SW_MINOR_VERSION) || \
     (CDD_OCOTP_SW_PATCH_VERSION != OCOTP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Types.h are different"
#endif

/* Check if current file and Ocotp_IPW.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID != OCOTP_IPW_VENDOR_ID)
    #error "CDD_Ocotp.h and Ocotp_IPW.h have different vendor ids"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION != OCOTP_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION != OCOTP_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION != OCOTP_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_IPW.h are different"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION != OCOTP_IPW_SW_MAJOR_VERSION) || \
     (CDD_OCOTP_SW_MINOR_VERSION != OCOTP_IPW_SW_MINOR_VERSION) || \
     (CDD_OCOTP_SW_PATCH_VERSION != OCOTP_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_IPW.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define OCOTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"
OCOTP_CONFIG_EXT
#define OCOTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"

#ifdef OCOTP_PRECOMPILE_SUPPORT
#define OCOTP_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Ocotp_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once */
#include "Ocotp_MemMap.h"

extern const Ocotp_ConfigType Ocotp_Config;

#define OCOTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Ocotp_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once */
#include "Ocotp_MemMap.h"
#endif
/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          ID of module and instance.
*/
#define OCOTP_MODULE_ID                255U          /*!< Ocotp module ID */
#define OCOTP_INSTANCE_ID              0U            /*!< Ocotp instance ID */

/**
* @brief          Invalid value of index and address.
*/
#define OCOTP_INVALID_INDEX            0xFFU         /*!< Ocotp invalid index ID */
#define OCOTP_INVALID_ADDRESS          0xFFFFFFFFU   /*!< Ocotp invalid address ID */

/**
* @brief          Development error codes (passed to DET).
* @implements     Ocotp_ErrorCodes_define
*/
#define OCOTP_E_PARAM_CONFIG           0x01U /*!< API service called with wrong parameter */
#define OCOTP_E_PARAM_LENGTH           0x02U /*!< API service called with wrong parameter */
#define OCOTP_E_PARAM_MODE             0x06U /*!< API service called with wrong parameter */
#define OCOTP_E_PARAM_POINTER          0x03U /*!< API service called with invalid pointer */
#define OCOTP_E_PARAM_CHANNEL          0x04U /*!< API service used with an invalid channel identifier or channel was not configured for the functionality of the calling API */
#define OCOTP_E_PARAM_INSTANCE         0x05U /*!< API service used with an invalid hardware unit identifier or hardware unit was not configured for the functionality of the calling API */
#define OCOTP_E_UNINIT                 0x07U /*!< API service called without module initialization */
#define OCOTP_E_ALREADY_INITIALIZED    0x08U /*!< Ocotp_init service called module initialization */
#define OCOTP_E_BUSY                   0x09U /*!< API service called while driver still busy */

/**
* @brief          Runtime error codes (passed to DET).
*/
#define OCOTP_E_TIMEOUT                0x0CU /*!< Timeout exceeded */
/**
 *
* @brief          Transient Faults codes (passed to DET).
*
*/
#define OCOTP_E_READ_FAILED            0x0BU /*!< Ocotp read failed (HW) */
#define OCOTP_E_WRITE_FAILED           0x0AU /*!< Ocotp write failed (HW) */


#if (OCOTP_MULTICORE_SUPPORT == STD_ON)
/**
* @brief          Multicore error codes (passed to DET).
*/
#define OCOTP_E_MULTICORE_CHANNEL      0x0DU /*!< Channel is not assigned to current core */
#define OCOTP_E_MULTICORE_INSTANCE     0x0EU /*!< Instance is not assigned to current core */
#endif
/**
* @brief          All service IDs (passed to DET).
*/
#define OCOTP_INIT_ID                              0x00U   /*!< Service ID of Ocotp_Init function */
#define OCOTP_DEINIT_ID                            0x01U   /*!< Service ID of Ocotp_Deinit function */
#define OCOTP_WRITE_EFUSE_ID                       0x02U   /*!< Service ID of Ocotp_WriteEfuse function */
#define OCOTP_WRITE_SHADOW_REGISTER_ID             0x03U   /*!< Service ID of Ocotp_WriteShadow function */
#define OCOTP_READ_SHADOW_REGISTER_ID              0x05U   /*!< Service ID of Ocotp_ReadShadow function */
#define OCOTP_READ_APPLICATION_INFORMATION_ID      0x06U   /*!< Service ID of Ocotp_ReadApplicationInformation function */
#define OCOTP_WRITE_APPLICATION_INFORMATION_ID     0x07U   /*!< Service ID of Ocotp_WriteApplicationInformation function */
#define OCOTP_ECC_ERROR_INJECT_ID                  0x08U   /*!< Service ID of Ocotp_EccErrorInject function */
#define OCOTP_ECC_GET_ERROR_ID                     0x09U   /*!< Service ID of Ocotp_EccGetError function */
#define OCOTP_SET_MODE_ID                          0x0AU   /*!< Service ID of Ocotp_SetMode function */
#define OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID     0x0BU   /*!< Service ID of Ocotp_CalculateAndWriteCrcValue function */
#define OCOTP_CRC_VALIDATE_ID                      0x0CU   /*!< Service ID of Ocotp_CrcValidate function */
#define OCOTP_READ_EFUSE_ID                        0x04U   /*!< Service ID of Ocotp_ReadEFuse function */
#define OCOTP_GET_STATUS_ID                        0x0DU   /*!< Service ID of Ocotp_GetStatus function */
#ifdef OCOTP_READ_STICKY_INFORMATION_API
#if (OCOTP_READ_STICKY_INFORMATION_API == STD_ON)
#define OCOTP_READ_STICKY_INFORMATION_ID           0x0EU   /*!< Service ID of Ocotp_ReadStickyInformation function */
#endif
#if (OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON)
#define OCOTP_WRITE_STICKY_INFORMATION_ID          0x0FU   /*!< Service ID of Ocotp_WriteStickyInformation function */
#endif
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define OCOTP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"

extern const Ocotp_ConfigType *Ocotp_pConfigPtr;

#define OCOTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define OCOTP_START_SEC_CODE

#include "Ocotp_MemMap.h"
/**
 * @brief        The function initializes Ocotp module.
 * @details      The function sets the internal module variables according to given
 *               configuration set.
 *
 * @param[in]    ConfigPtr        Pointer to Ocotp driver configuration set.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must be NULL_PTR.
 *
 */
void Ocotp_Init(const Ocotp_ConfigType * const ConfigPtr);

/**
 * @brief        The function de-initializes Ocotp module.
 * @details      The function sets the Ocotp module's status to un-initialized.
 *
 * @param[in]    none.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
void Ocotp_Deinit(void);

#if(OCOTP_WRITE_EFUSE_API == STD_ON)
/**
 * @brief        The function writes data to efuse word.
 * @details      The function writes the specified data to the eFuse which was
 *               configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data user want to write to eFuse word.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write operation is successful.
 * @retval       E_NOT_OK                Write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_WriteEFuse
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
);
#endif /* OCOTP_WRITE_EFUSE_API == STD_ON */

#if (OCOTP_WRITE_SHADOW_API == STD_ON)
/**
 * @brief        The function writes data to shadow register.
 * @details      The function writes the specified data to the shadow register corresponding to eFuse
 *               which was configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data user want to write to shadow register.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write operation is successful.
 * @retval       E_NOT_OK                Write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_WriteShadowRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
);
#endif /* OCOTP_WRITE_SHADOW_API == STD_ON */

#if (OCOTP_READ_EFUSE_API == STD_ON)
/**
 * @brief        The function reads data from efuse word.
 * @details      The function reads the data from the eFuse which was
 *               configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                pointer points to the data read from eFuse word.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Read operation is successful.
 * @retval       E_NOT_OK                Read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_ReadEFuse
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
);
#endif /* OCOTP_READ_EFUSE_API == STD_ON */

#if (OCOTP_READ_SHADOW_API == STD_ON)
/**
 * @brief        The function writes data to shadow register.
 * @details      The function writes the specified data to the shadow register corresponding to eFuse
 *               which was configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data user want to write to shadow register.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write operation is successful.
 * @retval       E_NOT_OK                Write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_ReadShadowRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32 *pData
);
#endif /* OCOTP_READ_SHADOW_API == STD_ON */

#if (OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON)
/**
 * @brief        The function reads data from GP register.
 * @details      The function reads the data from the GP register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK read operation is successful.
 * @retval       E_NOT_OK read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_ReadApplicationInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
);
#endif /* OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON */

#if (OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON)
/**
 * @brief        The function writes data to GP register.
 * @details      The function writes the data to the GP register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data to be written.
 *
 * @return       Std_ReturnType
 * @retval       E_OK write operation is successful.
 * @retval       E_NOT_OK write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_WriteApplicationInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
);
#endif /* OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON */

#ifdef OCOTP_READ_STICKY_INFORMATION_API
#if (OCOTP_READ_STICKY_INFORMATION_API == STD_ON)
/**
 * @brief        The function reads data from STR register.
 * @details      The function reads the data from the STR register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[out]   pData               Pointer points to read data value
 *
 * @return       Std_ReturnType
 * @retval       E_OK read operation is successful.
 * @retval       E_NOT_OK read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_ReadStickyInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
);
#endif

#if (OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON)
/**
 * @brief        The function writes data to STR register.
 * @details      The function writes the data to the STR register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data to be written.
 *
 * @return       Std_ReturnType
 * @retval       E_OK write operation is successful.
 * @retval       E_NOT_OK write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_WriteStickyInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
);
#endif /* OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON */
#endif /* define OCOTP_READ_STICKY_INFORMATION_API */

#if (OCOTP_ECC_ERROR_INJECT_API == STD_ON)
/**
 * @brief        The function injects ECC error in the specified eFuse.
 * @details      The function inverts the value of the specified bit in the shadow register
 *               corresponding to eFuse which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    bit                 bit's position which will be inverted.
 *
 * @return       Std_ReturnType
 * @retval       E_OK inject operation is successful.
 * @retval       E_NOT_OK inject operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_EccErrorInject
(
    Ocotp_ChannelType eFuseChannel,
    uint8 bit
);
#endif /* OCOTP_ECC_ERROR_INJECT_API == STD_ON */

#if (OCOTP_ECC_GET_ERROR_API == STD_ON)
/**
 * @brief        The function gets ECC error of the specified eFuse.
 * @details      The function check the single-bit and double-bit ECC error bit
 *               of the specified eFuse.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK get error operation is successful.
 * @retval       E_NOT_OK get error operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_EccGetError
(
    Ocotp_ChannelType eFuseChannel,
    Ocotp_EccErrorType* pEccValue
);
#endif /* OCOTP_ECC_GET_ERROR_API == STD_ON */

#if (OCOTP_SET_MODE_API == STD_ON)
/**
 * @brief        The function sets operation mode for Ocotp module.
 * @details      The function sets operation mode for Ocotp module.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    mode                mode which is to be applied (OCOTP_NORMAL_MODE, OCOTP_POWERDOWN_MODE).
 *
 * @return       Std_ReturnType
 * @retval       E_OK     mode is set successfully.
 * @retval       E_NOT_OK set mode failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_SetMode
(
    uint8 HwIndex,
    Ocotp_ModeType mode
);
#endif /* OCOTP_SET_MODE_API == STD_ON */

#if (OCOTP_CRC_VALIDATE_API == STD_ON)
/**
 * @brief        The function writes the CRC value to the CRC fuse word.
 * @details      The function calculates and writes the CRC value to the CRC fuse word
 *               which is configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    pData               Pointer points to the data buffer which need calculating CRC.
 * @param[in]    dataSize            Size of the data need calculating CRC in byte.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write CRC value is successful.
 * @retval       E_NOT_OK                Write CRC value failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_CalculateAndWriteCrcValue
(
    Ocotp_ChannelType eFuseChannel,
    const uint32* pData,
    uint32 dataSize
);

/**
 * @brief        The function validates the CRC.
 * @details      The function compares the CRC value calculated by hardware
 *               to CRC value in the CRC fuse word which is configured in eFuse channel.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                Validate CRC value is successful.
 * @retval       E_NOT_OK            Validate CRC value failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_CrcValidate(Ocotp_ChannelType eFuseChannel);
#endif /* OCOTP_CRC_VALIDATE_API == STD_ON */


#if (OCOTP_GET_STATUS_API == STD_ON)
/**
 * @brief        The function gets status of Ocotp module.
 * @details      The function gets status of Ocotp module
 *               Secure mode is enabled or not. Error occurred or not and
 *               Status of hardware.
 *
 * @param[in]    HwIndex        Index of hardware configured.
 * @param[in]    pStatus        Pointer points to status structure.
 *
 * @return       Std_ReturnType
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_GetStatus
(
    uint8 HwIndex,
    Ocotp_StatusType* pStatus
);
#endif /* OCOTP_GET_STATUS_API == STD_ON */


#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* Ocotp_H */
