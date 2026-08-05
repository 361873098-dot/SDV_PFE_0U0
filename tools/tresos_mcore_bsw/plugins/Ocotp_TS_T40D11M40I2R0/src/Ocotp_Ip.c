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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocotp_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IP_VENDOR_ID_C                    43
#define OCOTP_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define OCOTP_IP_AR_RELEASE_MINOR_VERSION_C     4
#define OCOTP_IP_AR_RELEASE_REVISION_VERSION_C  0
#define OCOTP_IP_SW_MAJOR_VERSION_C             4
#define OCOTP_IP_SW_MINOR_VERSION_C             0
#define OCOTP_IP_SW_PATCH_VERSION_C             2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Ip header file are of the same vendor */
#if (OCOTP_IP_VENDOR_ID != OCOTP_IP_VENDOR_ID_C)
    #error "Ocotp_Ip.c and Ocotp_Ip.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip header file are of the same Autosar version */
#if ((OCOTP_IP_AR_RELEASE_MAJOR_VERSION    != OCOTP_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (OCOTP_IP_AR_RELEASE_MINOR_VERSION    != OCOTP_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (OCOTP_IP_AR_RELEASE_REVISION_VERSION != OCOTP_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Ocotp_Ip.c and Ocotp_Ip.h are different"
#endif
/* Check if current file and Ocotp_Ip header file are of the same Software version */
#if ((OCOTP_IP_SW_MAJOR_VERSION != OCOTP_IP_SW_MAJOR_VERSION_C) || \
     (OCOTP_IP_SW_MINOR_VERSION != OCOTP_IP_SW_MINOR_VERSION_C) || \
     (OCOTP_IP_SW_PATCH_VERSION != OCOTP_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Ocotp_Ip.c and Ocotp_Ip.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define OCOTP_IP_CRC32_POLYNOMIAL               ((uint32)0x04C11DB7U)
#define OCOTP_IP_CRC32_INITIAL_REMAINDER        ((uint32)0xFFFFFFFFU)
#define OCOTP_IP_FUSE_ADDRESS_INDEX             (0U)
#define OCOTP_IP_ECC_FUSE_ADDRESS_INDEX         (1U)
#define OCOTP_IP_SHIFT_FOR_ECC_INDEX            (2U)
#define OCOTP_IP_REGISTER_DEFAULT_VALUE         (0U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define OCOTP_START_SEC_CONST_UNSPECIFIED
#include "Ocotp_MemMap.h"
static OCOTP_Type * const Ocotp_Ip_pBaseAddress[OCOTP_INSTANCE_COUNT] = IP_OCOTP_BASE_PTRS;

#define OCOTP_STOP_SEC_CONST_UNSPECIFIED
#include "Ocotp_MemMap.h"

#define OCOTP_START_SEC_VAR_INIT_UNSPECIFIED
#include "Ocotp_MemMap.h"

static const Ocotp_Ip_ConfigType *Ocotp_Ip_pOcotpStateCfg[OCOTP_INSTANCE_COUNT] = {NULL_PTR};

#define OCOTP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Ocotp_MemMap.h"

#if ((OCOTP_IP_WRITE_EFUSE_API == STD_ON) || (OCOTP_IP_ECC_GET_ERROR_API == STD_ON))
#define OCOTP_START_SEC_CONST_32
#include "Ocotp_MemMap.h"

static const uint32 Ocotp_Ip_u32FuseMapArray[OCOTP_IP_NUMBER_OF_MAP_EFUSES][3] = OCOTP_IP_EFUSE_ADDRESS_MAP;

#define OCOTP_STOP_SEC_CONST_32
#include "Ocotp_MemMap.h"
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

#if (OCOTP_IP_WRITE_EFUSE_API == STD_ON)
static uint8 Ocotp_Ip_EccCalculation(uint32 data);

static boolean Ocotp_Ip_CheckEFuseIsInFusemap
(
    uint32 instance,
    uint32 fuseAddess,
    uint8 *pEccShift,
    uint32 *pEccAddress
);
#endif /* OCOTP_IP_WRITE_EFUSE_API == STD_ON */

#if (OCOTP_IP_CRC_TEST_API == STD_ON)
static uint32 Ocotp_Ip_CrcCalculation
(
    const uint32 *dataPtr,
    uint32 dataSize
);
#endif /* OCOTP_IP_CRC_TEST_API == STD_ON */

static boolean Ocotp_Ip_GetBusyFlag(uint32 instance);

static boolean Ocotp_Ip_GetErrorFlag(uint32 instance);

#if ((OCOTP_IP_WRITE_EFUSE_API == STD_ON) || (OCOTP_IP_READ_EFUSE_API == STD_ON) || (OCOTP_IP_CRC_TEST_API == STD_ON))
static Ocotp_Ip_StatusType Ocotp_Ip_WaitDeviceReady(uint32 instance, uint32 timeout);
#endif

#if (OCOTP_IP_SET_MODE_API == STD_ON)
static Ocotp_Ip_StatusType Ocotp_Ip_EnterPowerDownMode(uint32 instance);

static void Ocotp_Ip_ExitPowerDownMode(uint32 instance);
#endif /* OCOTP_IP_SET_MODE_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

#if (OCOTP_IP_WRITE_EFUSE_API == STD_ON)
/**
 * @brief        The function calculates ECC value.
 * @details      The function calculates ECC value for the specified input data.
 *
 * @param[in]    data        input data.
 *
 * @return       uint8
 * @retval       Ecc value.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static uint8 Ocotp_Ip_EccCalculation(uint32 data)
{
    uint8 ecc[7] = {0,0,0,0,0,0,0};
    const uint32 u32ECCValueArray[OCOTP_IP_ECC_LENGTH] = OCOTP_IP_ECC_VALUES;
    uint8 eccRez = 0U;
    uint32 eccReg = 0U;
    uint32 eccVar = 0U;
    uint8 eccTemp = 0U;
    uint8 i = 0U;
    uint8 j = 0U;

    /* Get ECC bits value */
    for (i=0U; i<7U; i++)
    {
         eccReg = (uint32)(data & u32ECCValueArray[i]);
         for (j=0U; j<32U; j++)
         {
             eccVar = (uint32)((uint32)(eccReg & ((uint32)1U << (uint8)(31U - j))) >> (uint8)(31U - j));
             eccTemp ^= (uint8)eccVar;
         }
         ecc[i] = eccTemp;
         eccTemp = 0U;
    }

    for (i=0U; i<7U; i++)
    {
         eccTemp = (uint8)(((uint8)(ecc[i] & (uint8)(1U))) << i);
         eccRez |= (uint8)eccTemp;
    }

    return eccRez;
}

static boolean Ocotp_Ip_CheckEFuseIsInFusemap
(
    uint32 instance,
    uint32 fuseAddess,
    uint8 *pEccShift,
    uint32 *pEccAddress
)
{
    boolean eRetVal = FALSE;
    Ocotp_Ip_StatusType eStatus;
    uint32 u32DataRead = 0U;
    uint8 i = 0U;
    uint32 u32Temp;

    /* Check if address is ECC protected to avoid introducing a double ECC error */
    for (i = 0U; i < OCOTP_IP_NUMBER_OF_MAP_EFUSES; i++)
    {
        if (fuseAddess == Ocotp_Ip_u32FuseMapArray[i][OCOTP_IP_FUSE_ADDRESS_INDEX])
        {
            eRetVal = TRUE;
            /* Check if corresponding ECC Fuse is empty */
            if (Ocotp_Ip_u32FuseMapArray[i][OCOTP_IP_ECC_FUSE_ADDRESS_INDEX] != 0U)
            {
                /* Read data from ECC fuse word */
                eStatus = Ocotp_Ip_ReadEFuse(instance, Ocotp_Ip_u32FuseMapArray[i][OCOTP_IP_ECC_FUSE_ADDRESS_INDEX], &u32DataRead);
                if (eStatus != STATUS_OCOTP_IP_SUCCESS)
                {
                    eRetVal = FALSE;
                }
                else
                {
                    /* Check if ECC is enabled for current fuse word */
                    u32Temp = (uint32)OCOTP_IP_ECC_ENABLE_MASK << (uint32)Ocotp_Ip_u32FuseMapArray[i][OCOTP_IP_SHIFT_FOR_ECC_INDEX];
                    if (0U != (u32DataRead & u32Temp))
                    {
                        eRetVal = FALSE;
                    }
                    /* If Ecc is not enabled, Store information of Ecc for current fuse word */
                    else
                    {
                        *pEccShift = (uint8)Ocotp_Ip_u32FuseMapArray[i][OCOTP_IP_SHIFT_FOR_ECC_INDEX];
                        *pEccAddress = Ocotp_Ip_u32FuseMapArray[i][OCOTP_IP_ECC_FUSE_ADDRESS_INDEX];
                    }
                }
            }
            break;
        }
    }

    return eRetVal;
}
#endif /* OCOTP_IP_WRITE_EFUSE_API == STD_ON */

#if (OCOTP_IP_CRC_TEST_API == STD_ON)
/**
 * @brief        The function calculates CRC value.
 * @details      The function calculates CRC value for the specified data array.
 *
 * @param[in]    dataPtr        pointer points to input data array.
 * @param[in]    dataSize       size of data(in 4 bytes).
 *
 * @return       uint32
 * @retval       CRC value.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static uint32 Ocotp_Ip_CrcCalculation(const uint32 *dataPtr, uint32 dataSize)
{
    uint32 i = 0U;
    uint32 j = 0U;
    uint32 u32RemainData = OCOTP_IP_CRC32_INITIAL_REMAINDER;

    for (i = 0U; i < dataSize; i++)
    {
        u32RemainData ^= dataPtr[i];
        for (j = 0U; j < 32U; j++)
        {
            if ((uint32)0U != ((uint32)0x80000000U & u32RemainData))
            {
                u32RemainData = (uint32)((u32RemainData << 1U) ^ OCOTP_IP_CRC32_POLYNOMIAL);
            }
            else
            {
                u32RemainData = (uint32)(u32RemainData << 1U);
            }
        }
    }
    return u32RemainData;
}
#endif /* OCOTP_IP_CRC_TEST_API == STD_ON */

/**
 * @brief        The function checks busy status of Ocotp.
 * @details      The function checks busy status of Ocotp.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       boolean
 * @retval       TRUE if hardware is busy.
 * @retval       FALSE if hardware is NOT busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static boolean Ocotp_Ip_GetBusyFlag(uint32 instance)
{

    volatile uint32 regVal;
    const OCOTP_Type * ocotpBaseAddr;
    boolean bReturnCode = FALSE;
    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    regVal = ocotpBaseAddr->STATUS_SYS;

    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_4);

    if ((regVal & OCOTP_STATUS_SYS_BUSY_MASK) != 0U)
    {
        bReturnCode = TRUE;
    }

    return bReturnCode;
}

/**
 * @brief        The function checks error status of Ocotp.
 * @details      The function checks error status of Ocotp.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       boolean
 * @retval       TRUE if error flag is set.
 * @retval       FALSE if error flag is not set.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static boolean Ocotp_Ip_GetErrorFlag(uint32 instance)
{
    uint32 regVal;
    const OCOTP_Type * ocotpBaseAddr;
    boolean bReturnCode = FALSE;
    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    regVal = ocotpBaseAddr->STATUS_SYS;
    if ((regVal & OCOTP_STATUS_SYS_ERROR_MASK) != 0U)
    {
        bReturnCode = TRUE;
    }
    return bReturnCode;
}

#if ((OCOTP_IP_WRITE_EFUSE_API == STD_ON) || (OCOTP_IP_READ_EFUSE_API == STD_ON) || (OCOTP_IP_CRC_TEST_API == STD_ON))
/**
 * @brief        The function waits Ocotp is ready.
 * @details      The function checks error and busy status of Ocotp.
 *               If the status is different busy, this function will return.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if no errors occurred and hardware is not busy.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_ERROR_TIMEOUT timeout supervision is enbaled and timeout occurred.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static Ocotp_Ip_StatusType Ocotp_Ip_WaitDeviceReady(uint32 instance, uint32 timeout)
{
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks;
    uint32 u32CurrentTicks;
    volatile Ocotp_Ip_StatusType eReturnVal;

    eReturnVal = Ocotp_Ip_GetBusyState(instance);
    u32TimeoutTicks = OsIf_MicrosToTicks(timeout, (OsIf_CounterType)OCOTP_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)OCOTP_IP_TIMEOUT_TYPE);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_1);
    while ((STATUS_OCOTP_IP_BUSY == eReturnVal) && (u32ElapsedTicks < u32TimeoutTicks))
    {
        eReturnVal = Ocotp_Ip_GetBusyState(instance);
        MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_2);
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)OCOTP_IP_TIMEOUT_TYPE);
    }
    if (u32ElapsedTicks >= u32TimeoutTicks)
    {
        eReturnVal = STATUS_OCOTP_IP_ERROR_TIMEOUT;
    }
    return eReturnVal;
}
#endif

#if (OCOTP_IP_SET_MODE_API == STD_ON)
/**
 * @brief        The function puts Ocotp into power down mode.
 * @details      The function puts Ocotp into power down mode.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS if enter powerdown successfully.
 * @retval       STATUS_OCOTP_IP_ERROR if error flag is set.
 * @retval       STATUS_OCOTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static Ocotp_Ip_StatusType Ocotp_Ip_EnterPowerDownMode(uint32 instance)
{
    OCOTP_Type * ocotpBaseAddr;
    volatile uint32 regVal;
    Ocotp_Ip_StatusType eReturnCode;
    uint32 u32TimeoutVal = OCOTP_IP_SET_MODE_TIMEOUT_VALUE;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks;
    uint32 u32CurrentTicks;

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    /* Clear all error flags*/
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Check if device is ready */
    eReturnCode = Ocotp_Ip_GetBusyState(instance);
    if (eReturnCode == STATUS_OCOTP_IP_SUCCESS)
    {
        /* Set IPG_STOP bit */
        regVal = ((ocotpBaseAddr->CTRL_FBX) | (OCOTP_CTRL_FBX_IPG_STOP_MASK));
        ocotpBaseAddr->CTRL_FBX = regVal;

        /* Wait until IPG_STOP_ACK is set*/
        u32TimeoutTicks = OsIf_MicrosToTicks(u32TimeoutVal, (OsIf_CounterType)OCOTP_IP_TIMEOUT_TYPE);
        u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)OCOTP_IP_TIMEOUT_TYPE);

        regVal = (uint32)(ocotpBaseAddr->CTRL_FBX & OCOTP_CTRL_FBX_IPG_STOP_ACK_MASK);

        MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_3);

        while (((uint32)0U == regVal) && (u32ElapsedTicks < u32TimeoutTicks))
        {
            u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)OCOTP_IP_TIMEOUT_TYPE);
            regVal = (uint32)(ocotpBaseAddr->CTRL_FBX & OCOTP_CTRL_FBX_IPG_STOP_ACK_MASK);
        }
        /* If timeout occurred*/
        if (u32ElapsedTicks >= u32TimeoutTicks)
        {
            eReturnCode = STATUS_OCOTP_IP_ERROR_TIMEOUT;
        }
        else
        {
            /* Set the FuseBox Power Down */
            regVal = (uint32)((ocotpBaseAddr->CTRL_FBX) | (OCOTP_CTRL_FBX_FBX_PD_MASK));
            ocotpBaseAddr->CTRL_FBX = regVal;
        }
    }

    return eReturnCode;
}

/**
 * @brief        The function puts Ocotp into normal mode.
 * @details      The function puts Ocotp into normal mode.
 *
 * @param[in]    instance       hardware instance.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static void Ocotp_Ip_ExitPowerDownMode (uint32 instance)
{

    OCOTP_Type * ocotpBaseAddr;
    uint32 regVal;

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    regVal = (uint32)(ocotpBaseAddr->CTRL_FBX & (~OCOTP_CTRL_FBX_FBX_PD_MASK));
    ocotpBaseAddr->CTRL_FBX = regVal;

    return;
}
#endif /* OCOTP_IP_SET_MODE_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
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
 * @pre          Module has not been initialized.
 *
 * @implements   Ocotp_Ip_Init_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_Init
(
    const Ocotp_Ip_ConfigType *pConfig
)
{
    uint8 instance = pConfig->ocotpInstance;;
    OCOTP_Type * ocotpBaseAddr;

    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] == NULL_PTR);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    Ocotp_Ip_pOcotpStateCfg[instance] = pConfig;

    /* Clear error flags */
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Configure secure mode */
    ocotpBaseAddr->CTRL_FBX |= OCOTP_CTRL_FBX_SEC_MODE(pConfig->secureMode);
    return STATUS_OCOTP_IP_SUCCESS;
}

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
 * @implements   Ocotp_Ip_DeInit_Activity
 *
 */
void Ocotp_Ip_DeInit (uint32 instance)
{
    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    OCOTP_Type * ocotpBaseAddr;
    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    Ocotp_Ip_pOcotpStateCfg[instance] = NULL_PTR;
    /* Set CTRL_FBX register to default value */
    ocotpBaseAddr->CTRL_FBX = (uint32)OCOTP_IP_REGISTER_DEFAULT_VALUE;

    return;
}

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
 * @implements   Ocotp_Ip_WriteEFuse_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_WriteEFuse
(
    uint32 instance,
    uint32 address,
    uint32 data,
    boolean bEccEnable,
    boolean bBlocking
)
{
    Ocotp_Ip_StatusType eReturnCode;
    uint32 regVal = 0;
    OCOTP_Type *ocotpBaseAddr;
    uint8 u8EccVal = 0U;
    uint8 u8EccShift = 0U;
    uint32 u32Temp = 0U;
    uint32 u32EccAddress = 0U;
    boolean bAddrFound = FALSE;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    /* Clear all error flag */
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Check if device is ready */
    eReturnCode = Ocotp_Ip_GetBusyState(instance);
    if (eReturnCode == STATUS_OCOTP_IP_SUCCESS)
    {
        /* Check if address is ECC protected to avoid introducing a double ECC error */
        bAddrFound = Ocotp_Ip_CheckEFuseIsInFusemap(instance, address, &u8EccShift, &u32EccAddress);
        if (FALSE == bAddrFound)
        {
            eReturnCode = Ocotp_Ip_GetBusyState(instance);
            if (STATUS_OCOTP_IP_SUCCESS == eReturnCode)
            {
                eReturnCode = STATUS_OCOTP_IP_INVALID_INPUT_ADDRESS;
            }
        }
        /* Check if this eFuse Word is not applied ECC protection */
        else if ((TRUE == bEccEnable) && (0U == u32EccAddress))
        {
            eReturnCode = STATUS_OCOTP_IP_INVALID_INPUT_ADDRESS;
        }
        else
        {
            /* Write eFuse address */
            ocotpBaseAddr->ADDR_SYS = ((ocotpBaseAddr->ADDR_SYS) & (~OCOTP_ADDR_SYS_ADDR_MASK)) | OCOTP_ADDR_SYS_ADDR(address);
            /* Write data */
            ocotpBaseAddr->WRDATA_SYS = OCOTP_WRDATA_SYS_DATA(data);
            /* Write control and authenticate */
            regVal = ocotpBaseAddr->CTRL_SYS;
            regVal &= (~(OCOTP_CTRL_SYS_RD_WR_MASK | OCOTP_CTRL_SYS_AUTH_KEY_MASK));
            regVal |= (OCOTP_CTRL_SYS_RD_WR(OCOTP_CTRL_SYS_WRITE) | OCOTP_CTRL_SYS_AUTH_KEY(OCOTP_AUTH_KEY));
            /* Start writing */
            ocotpBaseAddr->CTRL_SYS = regVal;
            /* If write operation is blocked */
            if (TRUE == bBlocking)
            {
                /* Wait write operation finish */
                eReturnCode = Ocotp_Ip_WaitDeviceReady(instance, OCOTP_IP_WRITE_TIMEOUT_VALUE);
                if (TRUE == bEccEnable)
                {
                    /* If write successfully, enable Ecc protection */
                    if (STATUS_OCOTP_IP_SUCCESS == eReturnCode)
                    {
                        /* Calculate ECC */
                        u8EccVal = Ocotp_Ip_EccCalculation(data);
                        u8EccVal |= (uint8)OCOTP_IP_ECC_ENABLE_MASK;
                        /* Write eFuse address */
                        ocotpBaseAddr->ADDR_SYS = u32EccAddress;
                        /* Write calculated ECC */
                        u32Temp = (uint32)u8EccVal << (uint32)u8EccShift;
                        ocotpBaseAddr->WRDATA_SYS = u32Temp;
                        /* Write control and authenticate */
                        regVal = ocotpBaseAddr->CTRL_SYS;
                        regVal &= (~(OCOTP_CTRL_SYS_RD_WR_MASK | OCOTP_CTRL_SYS_AUTH_KEY_MASK));
                        regVal |= (OCOTP_CTRL_SYS_RD_WR(OCOTP_CTRL_SYS_WRITE) | OCOTP_CTRL_SYS_AUTH_KEY(OCOTP_AUTH_KEY));
                        /* Start writing */
                        ocotpBaseAddr->CTRL_SYS = regVal;
                        /* Wait write operation finish */
                        eReturnCode = Ocotp_Ip_WaitDeviceReady(instance, OCOTP_IP_WRITE_TIMEOUT_VALUE);
                    }
                }
            }
            else
            {
                if (TRUE == bEccEnable)
                {
                    /* Wait write operation finish */
                    eReturnCode = Ocotp_Ip_WaitDeviceReady(instance, OCOTP_IP_WRITE_TIMEOUT_VALUE);
                    /* If write successfully, enable Ecc protection */
                    if (STATUS_OCOTP_IP_SUCCESS == eReturnCode)
                    {
                        /* Calculate ECC */
                        u8EccVal = Ocotp_Ip_EccCalculation(data);
                        u8EccVal |= (uint8)OCOTP_IP_ECC_ENABLE_MASK;
                        /* Write eFuse address */
                        ocotpBaseAddr->ADDR_SYS = u32EccAddress;
                        /* Write calculated ECC */
                        u32Temp = (uint32)u8EccVal << (uint32)u8EccShift;
                        ocotpBaseAddr->WRDATA_SYS = u32Temp;
                        /* Write control and authenticate */
                        regVal = ocotpBaseAddr->CTRL_SYS;
                        regVal &= (~(OCOTP_CTRL_SYS_RD_WR_MASK | OCOTP_CTRL_SYS_AUTH_KEY_MASK));
                        regVal |= (OCOTP_CTRL_SYS_RD_WR(OCOTP_CTRL_SYS_WRITE) | OCOTP_CTRL_SYS_AUTH_KEY(OCOTP_AUTH_KEY));
                        /* Start writing Ecc to enable Ecc protection*/
                        ocotpBaseAddr->CTRL_SYS = regVal;
                    }
                }
            }
        }
    }
    return eReturnCode;
}
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
 * @implements   Ocotp_Ip_WriteShadowRegister_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_WriteShadowRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 data
)
{
    OCOTP_Type * ocotpBaseAddr;
    Ocotp_Ip_StatusType eReturnCode;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_IP_NUMBER_OF_RW_SHADOW);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    /* Clear all error flags*/
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Write data into specified shadow register */
    ocotpBaseAddr->SHADOWS[indexRegister] = data;

    eReturnCode = Ocotp_Ip_GetBusyState(instance);

    return eReturnCode;
}
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
 * @implements   Ocotp_Ip_ReadEFuse_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_ReadEFuse
(
    uint32 instance,
    uint32 address,
    uint32* data
)
{
    Ocotp_Ip_StatusType eReturnCode;
    OCOTP_Type * ocotpBaseAddr;
    uint32 regVal;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    /* Clear all error flags*/
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Check if device is ready */
    eReturnCode = Ocotp_Ip_GetBusyState(instance);
    if (eReturnCode == STATUS_OCOTP_IP_SUCCESS)
    {
        /* Write eFuse address */
        ocotpBaseAddr->ADDR_SYS = ((ocotpBaseAddr->ADDR_SYS) & (~OCOTP_ADDR_SYS_ADDR_MASK)) | OCOTP_ADDR_SYS_ADDR(address);

        /* Write control and authenticate */
        regVal = ocotpBaseAddr->CTRL_SYS;
        regVal &= (~(OCOTP_CTRL_SYS_RD_WR_MASK | OCOTP_CTRL_SYS_AUTH_KEY_MASK));
        regVal |= (OCOTP_CTRL_SYS_RD_WR(OCOTP_CTRL_SYS_READ) | OCOTP_CTRL_SYS_AUTH_KEY(OCOTP_AUTH_KEY));

        ocotpBaseAddr->CTRL_SYS = regVal;

        /* Wait device to be ready */
        eReturnCode = Ocotp_Ip_WaitDeviceReady(instance, OCOTP_IP_READ_TIMEOUT_VALUE);
        /* Clear error flag*/
        if (eReturnCode == STATUS_OCOTP_IP_SUCCESS)
        {
            *data = ocotpBaseAddr->RDATA_SYS;
        }
    }

    return eReturnCode;
}
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
 * @implements   Ocotp_Ip_ReadShadowRegister_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_ReadShadowRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 *data
)
{
    const OCOTP_Type * ocotpBaseAddr;
    Ocotp_Ip_StatusType eReturnCode;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_SHADOWS_COUNT);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    /* Clear all error flags*/
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Read shadow register */
    *data = ocotpBaseAddr->SHADOWS[indexRegister];

    eReturnCode = Ocotp_Ip_GetBusyState(instance);
    return eReturnCode;
}
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
 * @implements   Ocotp_Ip_EccGetError_Activity
 *
 */
boolean Ocotp_Ip_EccGetError
(
    uint32 instance,
    uint32 address,
    Ocotp_Ip_EccErrorType typeECC
)
{
    const OCOTP_Type * ocotpBaseAddr;
    uint32 u32readVal;
    uint32 idxFuse;
    uint32 idxReg;
    uint32 idxBit;
    boolean bReturnCode;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP((address >= OCOTP_IP_FIRST_EFUSE_ADDRESS) && (address <= Ocotp_Ip_u32FuseMapArray[OCOTP_IP_NUMBER_OF_MAP_EFUSES-1U][OCOTP_IP_FUSE_ADDRESS_INDEX]));
    DEV_ASSERT_OCOTP((OCOTP_IP_ECC_SINGLE_ERROR == typeECC) || (OCOTP_IP_ECC_DOUBLE_ERROR == typeECC));

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    idxFuse = (address - OCOTP_IP_FIRST_EFUSE_ADDRESS)/4U;

    /* SEC or DED idx register */
    idxReg = (uint32)((idxFuse)/32U);

    /* Position of the bit from the SEC or DED register*/
    idxBit = (uint32)((idxFuse)%32U);

    /* Check ECC error */
    if (typeECC == OCOTP_IP_ECC_DOUBLE_ERROR)
    {
        /* 2-bit ECC error check */
        u32readVal = ocotpBaseAddr->DED[idxReg];
    }
    else
    {
        /* 1-bit ECC error check */
        u32readVal = ocotpBaseAddr->SEC[idxReg];
    }
    u32readVal &= ((uint32)1U << idxBit);
    if ((uint32)0U == u32readVal)
    {
        bReturnCode = FALSE;
    }
    else
    {
        bReturnCode = TRUE;
    }
    return bReturnCode;
}
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
 * @implements   Ocotp_Ip_ClearErrorFlags_Activity
 *
 */
void Ocotp_Ip_ClearErrorFlags(uint32 instance)
{
    OCOTP_Type * ocotpBaseAddr;
    uint32 regVal;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    regVal = (uint32)(ocotpBaseAddr->STATUS_SYS);
    /* Write 1 to clear */
    ocotpBaseAddr->STATUS_SYS = regVal;

    return;
}

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
 * @implements   Ocotp_Ip_ReadGpRegister_Activity
 *
 */
uint32 Ocotp_Ip_ReadGpRegister
(
    uint32 instance,
    uint32 indexRegister
)
{
    const OCOTP_Type * ocotpBaseAddr;
    uint32 u32DataRead;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_GPR_COUNT);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    /* Read specified general purpose register */
    u32DataRead = ocotpBaseAddr->GPR[indexRegister];

    return u32DataRead;
}
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
 * @implements   Ocotp_Ip_WriteGpRegister_Activity
 *
 */
void Ocotp_Ip_WriteGpRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 data
)
{
    OCOTP_Type * ocotpBaseAddr;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_GPR_COUNT);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    /* Write data into specified general purpose register */
    ocotpBaseAddr->GPR[indexRegister] = data;

    return;
}
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
 * @implements   Ocotp_Ip_ReadStrRegister_Activity
 *
 */
uint32 Ocotp_Ip_ReadStrRegister
(
    uint32 instance,
    uint32 indexRegister
)
{
    const OCOTP_Type * ocotpBaseAddr;
    uint32 u32DataRead;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_STICKY_REG_COUNT);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    /* Read specified general purpose register */
    u32DataRead = ocotpBaseAddr->STR[indexRegister];

    return u32DataRead;
}
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
 * @implements   Ocotp_Ip_WriteStrRegister_Activity
 *
 */
void Ocotp_Ip_WriteStrRegister
(
    uint32 instance,
    uint32 indexRegister,
    uint32 data
)
{
    OCOTP_Type * ocotpBaseAddr;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_STICKY_REG_COUNT);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];

    /* Write data into specified general purpose register */
    ocotpBaseAddr->STR[indexRegister] = data;

    return;
}
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
 * @implements   Ocotp_Ip_EccErrorInject_Activity
 *
 */
void Ocotp_Ip_EccErrorInject
(
    uint32 instance,
    uint32 indexRegister,
    uint32 bit
)
{
    OCOTP_Type * ocotpBaseAddr;
    uint32 bitAddr;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(indexRegister < OCOTP_IP_NUMBER_OF_RW_SHADOW);
    DEV_ASSERT_OCOTP(bit < 32U);

    /* Bits 15:5 from the represents the shadow register, bits 4:0 represents shadow register bit to be inverted */
    bitAddr = (uint32)((uint32)(indexRegister << 5U) | (uint32)bit);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    ocotpBaseAddr->ERR_INJCTR = OCOTP_ERR_INJCTR_ADDR(bitAddr);

    return;
}
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
 * @implements   Ocotp_Ip_Setmode_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_Setmode
(
    uint32 instance,
    Ocotp_Ip_ModeType mode
)
{
    Ocotp_Ip_StatusType eReturnVal = STATUS_OCOTP_IP_SUCCESS;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP((OCOTP_FBXC_NORMAL_MODE == mode) || (OCOTP_FBXC_POWER_DOWN_MODE == mode));

    if (OCOTP_FBXC_NORMAL_MODE == mode)
    {
        Ocotp_Ip_ExitPowerDownMode(instance);
    }
    else
    {
        eReturnVal = Ocotp_Ip_EnterPowerDownMode(instance);
    }
    return eReturnVal;
}
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
 * @implements   Ocotp_Ip_GetBusyState_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_GetBusyState(uint32 instance)
{
    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    Ocotp_Ip_StatusType eRetVal = STATUS_OCOTP_IP_SUCCESS;
    /* Check if device is busy */
    if (TRUE == Ocotp_Ip_GetBusyFlag(instance))
    {
        eRetVal = STATUS_OCOTP_IP_BUSY;
    }
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_5);
    /* Check if an error occurred */
    if (TRUE == Ocotp_Ip_GetErrorFlag(instance))
    {
        eRetVal = STATUS_OCOTP_IP_ERROR;
    }

    return eRetVal;
}

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
 * @implements   Ocotp_Ip_CalculateAndWriteCrcValue_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_CalculateAndWriteCrcValue
(
    uint32 instance,
    uint32 CRCEfuseAddress,
    const uint32* dataPtr,
    uint32 dataSize
)
{
    uint32 u32CRCValue = 0U;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    u32CRCValue = Ocotp_Ip_CrcCalculation(dataPtr, dataSize);
    return Ocotp_Ip_WriteEFuse(instance, CRCEfuseAddress, u32CRCValue,FALSE, TRUE);
}

/**
 * @brief        The function compares CRC value in CRC fuse to the CRC value calculated by hardware.
 * @details      The function compares CRC value in CRC fuse to the CRC value calculated by hardware.
 *
 * @param[in]    instance              hardware instance.
 * @param[in]    CRCEfuseAddress       address of CRC fuse word.
 * @param[in]    startAddress          region start address.
 * @param[in]    endAddress            region end address.
 *
 * @return       Ocotp_Ip_StatusType
 * @retval       STATUS_OCOTP_IP_SUCCESS : CRC test passed.
 * @retval       otherwise : CRC test failed.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 * @implements   Ocotp_Ip_CrcTest_Activity
 *
 */
Ocotp_Ip_StatusType Ocotp_Ip_CrcTest
(
    uint32 instance,
    uint32 crcEFuseWordAddress,
    uint32 startAddress,
    uint32 endAddress
)
{
    OCOTP_Type *ocotpBaseAddr;
    uint32 u32TempVal = 0U;
    Ocotp_Ip_StatusType eRetVal;

    DEV_ASSERT_OCOTP(instance < OCOTP_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Ocotp_Ip_pOcotpStateCfg[instance] != NULL_PTR);
    DEV_ASSERT_OCOTP(startAddress <= endAddress);

    ocotpBaseAddr = Ocotp_Ip_pBaseAddress[instance];
    /* Clear all error flags*/
    Ocotp_Ip_ClearErrorFlags(instance);
    /* Write start and end address */
    u32TempVal = OCOTP_CRC_RGN_SYS_END_ADDR(endAddress)| OCOTP_CRC_RGN_SYS_START_ADDR(startAddress);
    ocotpBaseAddr->CRC_RGN_SYS = u32TempVal;
    /* Provide CRC eFuse address */
    u32TempVal = (ocotpBaseAddr->CRC_ADDR_SYS & (~OCOTP_CRC_ADDR_SYS_ADDR_MASK)) | OCOTP_CRC_ADDR_SYS_ADDR(crcEFuseWordAddress);
    ocotpBaseAddr->CRC_ADDR_SYS = u32TempVal;
    /* Check device is ready */
    eRetVal = Ocotp_Ip_GetBusyState(instance);
    if (STATUS_OCOTP_IP_SUCCESS == eRetVal)
    {
        /* Start CRC32 test */
        ocotpBaseAddr->CTRL_SYS = (ocotpBaseAddr->CTRL_SYS & (~OCOTP_CTRL_SYS_CRC_TEST_MASK)) | OCOTP_CTRL_SYS_CRC_TEST(1U);
        /* Wait device is ready */
        eRetVal = Ocotp_Ip_WaitDeviceReady(instance, OCOTP_IP_CRC_VALIDATE_TIMEOUT_VALUE);
        if (STATUS_OCOTP_IP_SUCCESS == eRetVal)
        {
            /* Check status of CRC test*/
            u32TempVal = ocotpBaseAddr->STATUS_SYS & (uint32)OCOTP_STATUS_SYS_CRC_FAIL_MASK;
            if ((uint32)0U != u32TempVal)
            {
                eRetVal = STATUS_OCOTP_IP_ERROR;
            }
        }
    }
    return eRetVal;
}
#endif /* OCOTP_IP_CRC_TEST_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
