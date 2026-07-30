/**
*   @file    Eth_43_PFE.c
*
*   @brief   AUTOSAR Eth driver interface.
*   @details This file contains implementation of the AUTOSAR Ethernet driver
*            and provides whole API except the interrupt handlers.
*
*   @addtogroup ETH_43_PFE_DRIVER
*   @{
*/
/*==================================================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
 *      Copyright 2017-2024 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "Eth_43_PFE.h" /* Includes also Eth_GeneralTypes.h, Eth_43_PFE_Cfg.h,
                    Eth_43_PFE_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "Eth_PFE_LLD.h"     /* LLD driver API */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/*
* @brief         State of the Eth module
* @details       Used to store state of the Ethernet controller driver i.e Eth
*                module. It is initialized to ETH_STATE_UNINIT
*/

volatile Eth_StateType Eth_43_PFE_CtrlState[ETH_43_PFE_MAXCTRLS_SUPPORTED] = {ETH_STATE_UNINIT};


#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/*
* @brief          Used for internal storage of configuration pointer
* @details        This variable is used to store the pointer to the instance
*                 of the Eth_43_PFE_ConfigType containing the configuration parameter,
*                 which is passed to the Eth_43_PFE_Init function, for the subsequent
*                 accesses.
*/
const Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr = NULL_PTR;
#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================*/
#if (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT)
    #define Local_Macro_Eth_PFE_LLD_InitInterfaces(InternalCfgPtr)   OsIf_Trusted_Call1param(Eth_PFE_LLD_InitInterfaces, (InternalCfgPtr))
    #define Local_Macro_Eth_PFE_LLD_InitEMACs(InternalCfgPtr)        OsIf_Trusted_Call1param(Eth_PFE_LLD_InitEMACs, (InternalCfgPtr))
#else
    #define Local_Macro_Eth_PFE_LLD_InitInterfaces(InternalCfgPtr)   Eth_PFE_LLD_InitInterfaces(InternalCfgPtr)
    #define Local_Macro_Eth_PFE_LLD_InitEMACs(InternalCfgPtr)        Eth_PFE_LLD_InitEMACs(InternalCfgPtr)
#endif

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void check_and_configure_controller(uint8 u8CtrlCount);
static BufReq_ReturnType update_and_provide_buffer(uint8 u8CtrlIdx, uint8 Priority, Eth_BufIdxType * BufIdxPtr, uint8 **BufPtr, uint16 * LenBytePtr);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

static void check_and_configure_controller(uint8 u8CtrlCount)
{
    if(TRUE == Eth_PFE_LLD_CheckInitializationStatus(u8CtrlCount))
    {
        if (((Std_ReturnType)E_OK) == Eth_PFE_LLD_ConfigureController(u8CtrlCount))
        {
            /* Set controller to init state */
            Eth_43_PFE_CtrlState[u8CtrlCount] = ETH_STATE_INIT;
            /* Yes, the controller is available, report as passed */
            #ifdef PFE_CFG_PFE_MASTER
                #if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                if((uint32)STD_ON == (uint32)ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(u8CtrlCount))
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType) ETH_43_PFE_CFG_DEM_E_ACCESS(u8CtrlCount), DEM_EVENT_STATUS_PREPASSED);
                }
                #endif /*(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)*/
            #endif /*PFE_CFG_PFE_MASTER*/
        }
        else
        {
            Eth_43_PFE_CtrlState[u8CtrlCount] = ETH_STATE_UNINIT;
        }
    }
    else
    {
        Eth_43_PFE_CtrlState[u8CtrlCount] = ETH_STATE_UNINIT;
    }
}

/*==================================================================================================*/
static BufReq_ReturnType update_and_provide_buffer(uint8 u8CtrlIdx, uint8 Priority, Eth_BufIdxType * BufIdxPtr, uint8 **BufPtr, uint16 * LenBytePtr)
{
    BufReq_ReturnType eFunctionSuccess = BUFREQ_E_NOT_OK;
    uint16 u16TempLenByte; /* Avoid changes of input parameters in case of an error */
    uint8 u8QueueIdx;
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    uint16 oldBufLen;
    uint8* dataPtr;
    uint16 ManagementInfoLength;
    uint16 FrameLength = 0;
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API*/

    u8QueueIdx = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlEgressPrioToFifoIdx[Priority];
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    oldBufLen = *LenBytePtr;
    Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
    Eth_43_PFE_EthSwtDriverFunctionList.TxAdaptBufferLengthFunction(LenBytePtr);
    PfeDevAssert(*LenBytePtr >= oldBufLen);
    ManagementInfoLength = *LenBytePtr - oldBufLen;
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API*/
    u16TempLenByte = *LenBytePtr;
    if(TRUE == Eth_PFE_LLD_ProvideBufferDataArea(u8CtrlIdx, u8QueueIdx, BufIdxPtr, BufPtr, &u16TempLenByte))
    { /* Data space is available */
        *LenBytePtr = u16TempLenByte;
        eFunctionSuccess = BUFREQ_OK;
    }
    else
    {
        if(*LenBytePtr > u16TempLenByte)
        {
            /* Requested size is too long, do not lock buffer */
            /* Set length to maximal available payload length */
            *LenBytePtr = u16TempLenByte;
            eFunctionSuccess = BUFREQ_E_OVFL;
        }
        else
        {
            /* Data space is not available */
            eFunctionSuccess = BUFREQ_E_BUSY;
        }
    }
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    if (eFunctionSuccess == BUFREQ_OK)
    {
        /* dataPtr points to position of EtherType in Ethernet frame*/
        dataPtr = (uint8*)(*BufPtr - 2U);
        /* Calculate frame length */
        PfeDevAssert(*LenBytePtr >= ManagementInfoLength);
        FrameLength = *LenBytePtr - ManagementInfoLength;
        if(E_OK == \
            Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
            Eth_43_PFE_EthSwtDriverFunctionList.TxPrepareFrameFunction( \
                u8CtrlIdx, *BufIdxPtr, &dataPtr, &FrameLength ))
        {   /* Data space is available */
            /* Update pointer to the payload */
            *BufPtr = dataPtr + 2U;
            eFunctionSuccess = BUFREQ_OK;
        }
    }
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API*/
    return eFunctionSuccess;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Initializes the Ethernet Driver
* @details       Passed configuration pointer is internally stored and
*                the driver is initialized. The Ethernet controller is not
*                touched.
* @note          Function should be called only once.
* @warning       Second call can cause undefined behavior.
*                Call the Eth_SetControllerMode() and pass ETH_MODE_DOWN to
*                the CtrlMode argument before the second Eth_43_PFE_Init call to avoid
*                problems.
* @api
* @param[in]     CfgPtr Points to the implementation specific structure containing
*                the Eth driver configuration
* Compiler_Warning: this warning due to behavior of compiler depend on configs.
*/
void Eth_43_PFE_Init(const Eth_43_PFE_ConfigType * CfgPtr)
{
    uint8 u8CtrlCount = 0U;

#if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
#if STD_ON == ETH_43_PFE_PRECOMPILE_SUPPORT
    if(NULL_PTR != CfgPtr)
#else
    if(NULL_PTR == CfgPtr)
#endif
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_INIT, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
    {
#endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
        /* Set the state to ETH_STATE_UNINIT before doing any changes to
           ensure that any preempting function (interrupt handler) will
           ensure that any preempting function (interrupt handler) will
           correctly stop its execution even if the state had been
           ETH_43_PFE_STATE_ACTIVE when the Eth_43_PFE_Init was called. */
        for (u8CtrlCount=0U; u8CtrlCount < (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlCount++)
        {
            Eth_43_PFE_CtrlState[u8CtrlCount] = ETH_STATE_UNINIT;
        }
     /* Store the configuration pointer to internal global variable
        for future usage */
    #if STD_ON == ETH_43_PFE_PRECOMPILE_SUPPORT
        Eth_43_PFE_InternalCfgPtr = &Eth_43_PFE_Config;
        (void)CfgPtr;
    #else
        Eth_43_PFE_InternalCfgPtr = CfgPtr;
    #endif
        #ifdef PFE_CFG_PFE_MASTER
        if(TRUE == Eth_PFE_LLD_CheckAccessToController())
        #endif /*PFE_CFG_PFE_MASTER*/
        {
            /* Reset and configure - common */
            if ((Std_ReturnType)E_OK == Eth_PFE_LLD_PlatformDrvPrepare())
            {
                #ifdef PFE_CFG_PFE_MASTER
                Eth_PFE_LLD_EMACPrepare();
                #endif

                /* Configure - per controller */
                for (u8CtrlCount = 0U; u8CtrlCount < (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlCount++)
                {
                    /* Try to reset the controller - per interface */
                    Eth_PFE_LLD_InterfacePrepare(u8CtrlCount);
                    /*  Check whether the controller is available */
                    check_and_configure_controller(u8CtrlCount);
                }
                #if (defined(PFE_CFG_PFE_MASTER) && ((TRUE == PFE_CFG_HIF_IRQ_ENABLED) || (TRUE == PFE_CFG_BMU_IRQ_ENABLED)))
                Eth_PFE_LLD_bIrqInitStatus = TRUE;
                #endif
                #if defined(PFE_CFG_MULTI_INSTANCE_SUPPORT) && defined(PFE_CFG_PFE_MASTER)
                Eth_43_PFE_LLD_SetMasterUp();
                #endif
            }
        }
        #ifdef PFE_CFG_PFE_MASTER
        else
        {
            for (u8CtrlCount = 0U; u8CtrlCount < (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlCount++)
            {
                /* No, the controller is not available, report an error */
                #if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                    if((uint32)STD_ON == (uint32)ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(u8CtrlCount))
                    {
                        (void)Dem_SetEventStatus   ( \
                            (Dem_EventIdType) \
                            ETH_43_PFE_CFG_DEM_E_ACCESS(u8CtrlCount), \
                            DEM_EVENT_STATUS_PREFAILED \
                                                );
                    }
                #endif
                    Eth_43_PFE_CtrlState[u8CtrlCount] = ETH_STATE_UNINIT;
            }
        }
        #endif /*PFE_CFG_PFE_MASTER*/
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Shutdown the driver gracefully 
* @api
*/
void Eth_43_PFE_DeInit(void)
{
    Eth_PFE_LLD_DeInit();
    Eth_43_PFE_InternalCfgPtr = NULL_PTR;
}

/*================================================================================================*/
/**
* @brief         Enables or disables the given controller
* @warning       Disabling the controller clears all receive and transmit
*                buffers. The application should ensure that no data is lost.
* @api
* @param[in]     u8CtrlIdx Index of the controller to be enabled or disabled.
*                The index is valid within the context of the Ethernet Driver
*                only.
* @param[in]     CtrlMode Mode which shall be entered
*                - ETH_MODE_DOWN: disable the controller
*                - ETH_MODE_ACTIVE: enable the controller
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected and the function
*                failed.
*/
Std_ReturnType Eth_43_PFE_SetControllerMode(uint8 u8CtrlIdx, Eth_ModeType CtrlMode)
{
    Std_ReturnType u8FunctionSuccess = (Std_ReturnType)E_NOT_OK; /* Variable used to track the
                                           function execution success status */

    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_SETCONTROLLERMODE, ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_SETCONTROLLERMODE, ETH_43_PFE_E_UNINIT \
                                  );
        }
        else
        {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
        #ifdef PFE_CFG_PFE_MASTER
        if(TRUE == Eth_PFE_LLD_CheckAccessToController())
        #endif /*PFE_CFG_PFE_MASTER*/
        {
            if(ETH_MODE_ACTIVE == CtrlMode)
            {
                if(TRUE == Eth_PFE_LLD_EnableController(u8CtrlIdx))
                {
                    u8FunctionSuccess = (Std_ReturnType)E_OK;
                }
            }
            else
            {
                if ((Std_ReturnType)E_OK == Eth_PFE_LLD_DisableController(u8CtrlIdx))
                {
                    u8FunctionSuccess = (Std_ReturnType)E_OK;
                }
            }

            #ifdef PFE_CFG_PFE_MASTER
            #if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
            if((uint32)STD_ON == (uint32)ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(u8CtrlIdx))
            {
                (void)Dem_SetEventStatus   ( \
                    (Dem_EventIdType) \
                    ETH_43_PFE_CFG_DEM_E_ACCESS(u8CtrlIdx), \
                    DEM_EVENT_STATUS_PREPASSED  \
                                        );
            }
            #endif
            #endif /*PFE_CFG_PFE_MASTER*/
        }
        #ifdef PFE_CFG_PFE_MASTER
        else
        {
            #if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                if((uint32)STD_ON == (uint32)ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(u8CtrlIdx))
                {
                    (void)Dem_SetEventStatus   ( \
                        (Dem_EventIdType) \
                        ETH_43_PFE_CFG_DEM_E_ACCESS(u8CtrlIdx), \
                        DEM_EVENT_STATUS_PREFAILED \
                                            );
                }
            #endif
        }
        #endif /*PFE_CFG_PFE_MASTER*/
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT */
    return u8FunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Obtains the mode of the given controller
* @api
* @param[in]     u8CtrlIdx Index of the controller which state shall be read.
*                The index is valid within the context of the Ethernet Driver
*                only.
* @param[out]    CtrlModePtr Pointer where to store the current controller mode.
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected and the function
*                failed.
*/
Std_ReturnType Eth_43_PFE_GetControllerMode( \
                            uint8 u8CtrlIdx, \
                            Eth_ModeType * CtrlModePtr \
                                                    )
{
    /*  Variable used to track the function execution success status */
    Std_ReturnType u8FunctionSuccess = (Std_ReturnType)E_NOT_OK;

    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_GETCONTROLLERMODE, ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
       if(NULL_PTR == CtrlModePtr)
        {

            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_GETCONTROLLERMODE, ETH_43_PFE_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_GETCONTROLLERMODE, ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
            {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                * CtrlModePtr = Eth_PFE_LLD_CheckControllerIsActive(u8CtrlIdx);
                u8FunctionSuccess = (Std_ReturnType)E_OK;
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
    return u8FunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Obtains the physical source address used by the indexed
*                controller (the node MAC address).
* @api
* @param[in]     u8CtrlIdx Index of the controller which MAC address should be
*                read. The index is valid within the context of the Ethernet
*                Driver only.
* @param[out]    PhysAddrPtr Pointer where to store physical source address
*                (MAC address). The address in network byte order is stored into
*                6 bytes at the given memory address.
*/
void Eth_43_PFE_GetPhysAddr(uint8 u8CtrlIdx, uint8 * PhysAddrPtr)
{

    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_GETPHYSADDR, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_GETPHYSADDR, ETH_43_PFE_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_GETPHYSADDR, ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
            {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                Eth_PFE_LLD_GetPhysicalAddress(u8CtrlIdx, PhysAddrPtr);
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Set or change physical address to the defined controller.
* @api
* @param[in]     u8CtrlIdx Index of the controller which PHY address should be
*                changed. The index is valid within the context of the Ethernet
*                Driver only.
* @param[in]     PhysAddrPtr Pointer to PHY address which should be set to
*                the controller. The address is stored in 6 bytes of memory
*                in network byte order.
* @caution       This function may be called only when the controller is down.
*                Call of function Eth_43_PFE_ControllerInit change MAC address
*                to the default value!
*/
void Eth_43_PFE_SetPhysAddr(uint8 u8CtrlIdx, const uint8 * PhysAddrPtr)
{
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_SETPHYSADDR, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_SETPHYSADDR, ETH_43_PFE_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_SETPHYSADDR, ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
            {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                (void)Eth_PFE_LLD_SetPhysAddr(u8CtrlIdx, PhysAddrPtr);
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Adds or removes the specified PhysAddrPtr address to or from
*                a multicast address pool in the controller specified by CtrlIdx.
* @api
* @param[in]     u8CtrlIdx Index of the controller. The index is valid within
*                the context of the Ethernet Driver only.
* @param[in]     PhysAddrPtr Pointer to PHY address which shall be added
*                or removed to or from multicast pool.
*                The address in network byte order stored into 6 bytes of
*                memory.
* @param[in]     Action Determine whenever the defined address will be added
*                to the pool ETH_ADD_TO_FILTER or removed from it
*                ETH_REMOVE_FROM_FILTER.
* @note          Each EMAC can handle up to 8 MAC addresses with exact match. All addresses, 
*                multicast and unicast, configured in all drivers (in master-slave scenarios) are 
*                counted in that. When more than 8 addresses are configured for one EMAC, the EMAC 
*                hash table will be used for filtering. This may cause the EMAC to accept also 
*                frames with MAC addresses that were not configured (when using hash matching 
*                algorithm, all frames with same hash group will be accepted). These additional 
*                frames (with DMAC address that was not configured) will be received by master 
*                driver, unless default configuration is changed through FCI.
*/
Std_ReturnType Eth_43_PFE_UpdatePhysAddrFilter ( \
                                    uint8 u8CtrlIdx, \
                                    const uint8 * PhysAddrPtr, \
                                    Eth_FilterActionType Action \
                                                            )
{
    /*  Variable used to track the function execution success status */
    Std_ReturnType u8FunctionSuccess = (Std_ReturnType)E_NOT_OK;

    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_UPDATEADDRFILTER, ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
       if(NULL_PTR == PhysAddrPtr)
        {

            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_UPDATEADDRFILTER, ETH_43_PFE_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_UPDATEADDRFILTER, ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
            {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                u8FunctionSuccess = Eth_PFE_LLD_UpdatePhysAddrFilter(u8CtrlIdx, PhysAddrPtr, Action);
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */

    return u8FunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Provides access to a transmit buffer of the specified
*                controller.
* @warning       The application should handle possible difference between the
*                requested and granted buffer lengths. It is not necessary to
*                use whole granted buffer i.e. some space at the end may not
*                be written.
* @api
* @param[in]     u8CtrlIdx Index of the controller which buffer shall be provided.
*                The index is valid within the context of the Ethernet Driver
*                only.
* @param[in]     Priority Frame priority for transmit buffer FIFO selection.
* @param[out]    BufIdxPtr Index to the granted transmit buffer resource.
*                It uniquely identifies the buffer in all subsequent calls of
*                functions Eth_43_PFE_Transmit() and Eth_43_PFE_TxConfirmation().
* @param[out]    BufPtr Pointer to the granted buffer. This is the space where
*                the data to be transmitted shall be stored.
* @param[in,out] LenBytePtr Buffer payload length
*                - In: desired length in bytes
*                - Out: granted length in bytes
* @return        Error and buffer status
* @retval        BUFREQ_OK: Buffer was successfully granted and no error has
*                occurred.
* @retval        BUFREQ_E_NOT_OK: A development error was detected and no buffer
*                was granted.
* @retval        BUFREQ_E_BUSY: All available buffers in use therefore no
*                buffer was granted. No error has been detected.
*/
BufReq_ReturnType Eth_43_PFE_ProvideTxBuffer( \
                            uint8 u8CtrlIdx, \
                            uint8 Priority, \
                            Eth_BufIdxType * BufIdxPtr, \
                            uint8 **BufPtr, \
                            uint16 * LenBytePtr \
                                                     )
{
    /* Variable used to track function success status */
    BufReq_ReturnType eFunctionSuccess = BUFREQ_E_NOT_OK;

#if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_PROVIDETXBUFFER, ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == BufIdxPtr)
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_PROVIDETXBUFFER, ETH_43_PFE_E_PARAM_POINTER \
                                  );
        }
        else
        {
            if(NULL_PTR == BufPtr)
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_PROVIDETXBUFFER, ETH_43_PFE_E_PARAM_POINTER \
                                      );
            }
            else
            {
                if(NULL_PTR == LenBytePtr)
                {
                    (void)Det_ReportError ( \
                        (uint8) ETH_43_PFE_MODULE_ID, \
                        ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                        ETH_43_PFE_SID_PROVIDETXBUFFER, ETH_43_PFE_E_PARAM_POINTER \
                                          );
                }
                else
                {
                    if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
                    {
                        (void)Det_ReportError ( \
                            (uint8) ETH_43_PFE_MODULE_ID, \
                            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                            ETH_43_PFE_SID_PROVIDETXBUFFER, ETH_43_PFE_E_UNINIT \
                                              );
                    }
                    else
                    {
#endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                        if (Priority <= ETH_43_PFE_MAX_TX_PRIO_NUM)
                        {
                            eFunctionSuccess = update_and_provide_buffer(u8CtrlIdx, Priority, BufIdxPtr, BufPtr, LenBytePtr);
                        }
                        else
                        {
                            eFunctionSuccess = BUFREQ_E_NOT_OK;
                        }
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
                    }
                }
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
    return eFunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Triggers transmission of a previously granted and then filled
*                transmit buffer.
* @api
* @param[in]     u8CtrlIdx Index of the controller which buffer shall be
*                transmitted. The index is valid within the context of
*                the Ethernet Driver only.
* @param[in]     BufIdx Index of the buffer resource to be transmitted.
* @param[in]     FrameType Desired value of the Ethernet frame type in the
*                frame header.
* @param[in]     TxConfirmation Activates transmission confirmation.
* @param[in]     LenByte Buffer data length in bytes (payload length).
* @param[in]     PhysAddrPtr Physical target address (MAC address) in network
*                byte order.
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected and the function
*                failed.
*/
Std_ReturnType Eth_43_PFE_Transmit( \
                            uint8 u8CtrlIdx, \
                            Eth_BufIdxType BufIdx, \
                            Eth_FrameType FrameType, \
                            boolean TxConfirmation, \
                            uint16 LenByte, \
                            const uint8 * PhysAddrPtr \
                                  )
{
    Std_ReturnType u8FunctionSuccess = (Std_ReturnType)E_NOT_OK;

    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    uint16 lmem_header_size;
    uint8 u8FifoIdx;
    uint32 u32BufLen;
    uint32 u32BufHdrSize;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ((uint8) ETH_43_PFE_MODULE_ID, ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_TRANSMIT, ETH_43_PFE_E_INV_CTRL_IDX );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_TRANSMIT, ETH_43_PFE_E_PARAM_POINTER \
                                  );
        }
        else
        {
            if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_TRANSMIT, ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
            {
                if(ETH_MODE_ACTIVE != Eth_PFE_LLD_CheckControllerIsActive(u8CtrlIdx))
                {
                    (void)Det_ReportError ( \
                        (uint8) ETH_43_PFE_MODULE_ID, \
                        ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                        ETH_43_PFE_SID_TRANSMIT, ETH_43_PFE_E_INV_MODE \
                                          );
                }
                else
                {
                    u8FifoIdx = Eth_43_PFE_LLD_GetTxFifoIdx(u8CtrlIdx, BufIdx);
                    lmem_header_size = Eth_43_PFE_LLD_GetLmemHdrSize(u8CtrlIdx);
                    u32BufHdrSize = (uint32)TX_BUF_FRAME_OFFSET + lmem_header_size + (uint32)PFE_LLD_L2_HEADER_SIZE;
                    if(Eth_43_PFE_LLD_GetTxBufferSize(u8CtrlIdx, u8FifoIdx) < u32BufHdrSize)
                    {
                        NXP_LOG_ERROR("Size of TX buffer is invalid\n");
                    }
                    else
                    {
                        u32BufLen = Eth_43_PFE_LLD_GetTxBufferSize(u8CtrlIdx, u8FifoIdx)
                                  - (uint32)TX_BUF_FRAME_OFFSET - lmem_header_size - (uint32)PFE_LLD_L2_HEADER_SIZE;
                        PfeDevAssert(u32BufLen <= UINT16_MAX);
                        if((BufIdx >= ETH_43_PFE_MAX_CTRL_TX_BUF_CNT) || (LenByte > (uint16)u32BufLen))
                        {
                            (void)Det_ReportError ( \
                                (uint8) ETH_43_PFE_MODULE_ID, \
                                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                                ETH_43_PFE_SID_TRANSMIT, ETH_43_PFE_E_INV_PARAM \
                                                  );
                        }
                        else
                        {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                            u8FunctionSuccess = Eth_PFE_LLD_Transmit
                            (
                                u8CtrlIdx, BufIdx, FrameType,
                                LenByte, TxConfirmation, PhysAddrPtr
                            );
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
                        }
                    }
                }
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */

    return u8FunctionSuccess;
}

#if STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API
/*================================================================================================*/
/**
* @brief         Release a previously granted TX buffer. The transmission must not have been triggered.
* @api
* @param[in]     u8CtrlIdx Index of the controller whose buffer shall be released
*                The index is valid within the context of the Ethernet Driver only.
* @param[in]     BufIdx Index of the buffer resource to be released.
* @return        Error status
* @retval        BUFREQ_E_OK - Buffer successfully released
* @retval        BUFREQ_E_NOT_OK - Development error was detected, no buffer was released.
* @retval        BUFREQ_E_BUSY - Couldn't free the TX buffer of an un-finished transmission.
*/
BufReq_ReturnType Eth_43_PFE_ReleaseTxBuffer(uint8 u8CtrlIdx, 
                                             Eth_BufIdxType BufIdx
                                            )
{
    BufReq_ReturnType eReturnValue = BUFREQ_E_NOT_OK;

#if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    uint8 u8DetError = 0U;
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        u8DetError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if(BufIdx >= ETH_43_PFE_MAX_CTRL_TX_BUF_CNT)
    {
        u8DetError = ETH_43_PFE_E_INV_PARAM;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        u8DetError = ETH_43_PFE_E_UNINIT;
    }
    else 
    {
        /* No error, keep u8DetError = 0U */
    }

    if(u8DetError != 0U)
    {
        (void)Det_ReportError((uint8)ETH_43_PFE_MODULE_ID, ETH_43_PFE_DRIVER_INSTANCE, (uint8)ETH_43_PFE_SID_RELEASETXBUFFER, u8DetError);
    }
    else
#endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
    {
        eReturnValue = Eth_PFE_LLD_ReleaseTxBuffer(u8CtrlIdx, BufIdx) ? BUFREQ_OK : BUFREQ_E_BUSY;
    }

    return eReturnValue;
}
#endif  /* STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API */

/*================================================================================================*/
/**
* @brief         Triggers frames reception notifications.
* @details       All receive buffers are checked and the first received frame is
*                passed to the EthIf module. The caller is notified whether any
*                frame was received and whether more frames are available in the
*                receive queue.
* @api
* @param[in]     u8CtrlIdx Index of the controller which shall be checked whether
*                any new frames were received. The index is valid within
*                the context of the Ethernet Driver only.
* @param[in]     FifoIdx Index of Rx Fifo where frames were received.
* @param[out]    RxStatusPtr Informs the caller whether a frame was received
*                (@c ETH_RECEIVED or @c ETH_NOT_RECEIVED) and whether more frames
*                are available in the queue (@c ETH_RECEIVED or
*                @c ETH_RECEIVED_MORE_DATA_AVAILABLE).
*/
void Eth_43_PFE_Receive(uint8 u8CtrlIdx, \
                        uint8 FifoIdx, \
                        Eth_RxStatusType *RxStatusPtr \
                       )
{
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_RECEIVE, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(FifoIdx > (HIF_DRV_CLIENT_QUEUES_MAX - 1U))
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                 ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                 ETH_43_PFE_SID_RECEIVE, ETH_43_PFE_E_INV_PARAM \
                                  );
        }
        else
        {
            if(NULL_PTR == RxStatusPtr)
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_RECEIVE, ETH_43_PFE_E_PARAM_POINTER \
                                      );
            }
            else
            {
                if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
                {
                    (void)Det_ReportError ( \
                        (uint8) ETH_43_PFE_MODULE_ID, \
                        ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_RECEIVE, \
                        ETH_43_PFE_E_UNINIT \
                                          );
                }
                else
                {
                    if(ETH_MODE_ACTIVE != Eth_PFE_LLD_CheckControllerIsActive(u8CtrlIdx))
                    {
                        (void)Det_ReportError ( \
                            (uint8) ETH_43_PFE_MODULE_ID, \
                            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                            ETH_43_PFE_SID_RECEIVE, ETH_43_PFE_E_INV_MODE \
                                              );
                    }
                    else
                    {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                        if(FALSE == ETH_43_PFE_CFG_ENABLERXINTERRUPT(u8CtrlIdx))
                        {
                            /* Check all buffers and report them - returned error
                            status is ignored because there is no mean to report errors
                            in the AUTOSAR specification */
                            *RxStatusPtr = Eth_PFE_LLD_ReportReception(u8CtrlIdx, FifoIdx, (boolean)FALSE);
                        }
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
                    }
                }
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Triggers frame transmission confirmations.
* @api
* @param[in]     u8CtrlIdx Index of the controller which shall be checked whether
*                any frame transmission has finished. The index is valid within
*                the context of the Ethernet Driver only.
* @details       All transmit buffers are checked and upper layers are informed
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
*/
void Eth_43_PFE_TxConfirmation(uint8 u8CtrlIdx)
{
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_TXCONFIRMATION, ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                ETH_43_PFE_SID_TXCONFIRMATION, ETH_43_PFE_E_UNINIT \
                                  );
        }
        else
        {
            if(ETH_MODE_ACTIVE != Eth_PFE_LLD_CheckControllerIsActive(u8CtrlIdx))
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_TXCONFIRMATION, ETH_43_PFE_E_INV_MODE \
                                      );
            }
            else
            {

    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
                if(FALSE == ETH_43_PFE_CFG_ENABLETXINTERRUPT(u8CtrlIdx))
                {
                    uint8 u8NumsFifo;
                    uint8 u8FifoIdx;
                    u8NumsFifo = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlEgressFifoCnt;
                    for(u8FifoIdx = 0U; u8FifoIdx < u8NumsFifo; u8FifoIdx ++)
                    {
                        Eth_PFE_LLD_ReportTransmission(u8CtrlIdx, u8FifoIdx);
    #if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
                        Eth_PFE_LLD_ReportTransmissionTS(u8CtrlIdx, u8FifoIdx);
    #endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */
                    }
                }
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
}

#if STD_ON == ETH_43_PFE_VERSION_INFO_API
#if STD_OFF == ETH_43_PFE_VERSION_INFO_API_MACRO
/*================================================================================================*/
/**
* @brief         Returns the version information of this module.
* @api
* @param[out]    VersionInfoPtr Pointer where to store the version information
*                of this particular module instance.
*/
void Eth_43_PFE_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr)
{
    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    if(NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_GETVERSIONINFO, ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
    {
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (uint16)ETH_43_PFE_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)ETH_43_PFE_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)ETH_43_PFE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)ETH_43_PFE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)ETH_43_PFE_SW_PATCH_VERSION;

    #if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
    }
    #endif /* ETH_43_PFE_DEV_ERROR_DETECT */
}
#endif /* STD_OFF == ETH_43_PFE_VERSION_INFO_API_MACRO */
#endif /* ETH_43_PFE_VERSION_INFO_API */
/*================================================================================================*/
/**
* @brief         The function checks for controller errors and lost frames. Used for polling state
*                changes. Calls EthIf_CtrlModeIndication when the controller mode changed.
* @api
*/
void Eth_43_PFE_MainFunction(void)
{
    Eth_PFE_LLD_MainFunction();
}

#if STD_ON == ETH_43_PFE_CTRLENABLE_MII
/**
 * @brief       Write specified transceiver register through the MII
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver on the MII
 * @param[in]   u8RegIdx Index of the transceiver register on the MII
 * @param[in]   u16RegVal Value to be written into the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_WriteMii(uint8 u8CtrlIdx, \
                                   uint8 u8TrcvIdx, \
                                   uint8 u8RegIdx, \
                                   uint16 u16RegVal \
                                  )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_WRITEMII, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if((u8TrcvIdx > (uint8)ETH_43_PFE_PHY_ADDR_MAX) || (u8RegIdx > (uint8)ETH_43_PFE_PHY_REG_ADDR_MII22_MAX))
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_WRITEMII, \
                ETH_43_PFE_E_INV_PARAM \
                                  );
        }
        else
        {
            if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_WRITEMII, \
                    ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
            {
                eReturnStatus = Eth_43_PFE_LLD_WriteMii(u8CtrlIdx, u8TrcvIdx, u8RegIdx, u16RegVal);
                if((Std_ReturnType)E_OK == eReturnStatus)
                {
                    Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
                    Eth_43_PFE_EthTrcvDriverFunctionList.WriteMiiIndicationFunction(u8CtrlIdx, u8TrcvIdx, u8RegIdx);
                }
            }
#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
        }
    }
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */

    return eReturnStatus;
}

/**
 * @brief       Read the specified transceiver register through the MII
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver on the MII
 * @param[in]   u8RegIdx Index of the transceiver register on the MII
 * @param[out]  pu16RegValPtr Filled with the register content of the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_ReadMii(uint8 u8CtrlIdx, \
                                  uint8 u8TrcvIdx, \
                                  uint8 u8RegIdx, \
                                  uint16 *pu16RegValPtr \
                                 )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_READMII, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if((u8TrcvIdx > (uint8)ETH_43_PFE_PHY_ADDR_MAX) || (u8RegIdx > (uint8)ETH_43_PFE_PHY_REG_ADDR_MII22_MAX))
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_READMII, \
                ETH_43_PFE_E_INV_PARAM \
                                  );
        }
        else
        {
            if(NULL_PTR == pu16RegValPtr)
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                    ETH_43_PFE_SID_READMII, ETH_43_PFE_E_PARAM_POINTER \
                                      );
            }
            else
            {
                if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
                {
                    (void)Det_ReportError ( \
                        (uint8) ETH_43_PFE_MODULE_ID, \
                        ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                        ETH_43_PFE_SID_READMII, ETH_43_PFE_E_UNINIT \
                                          );
                }
                else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
                {
                    eReturnStatus = Eth_43_PFE_LLD_ReadMii(u8CtrlIdx, u8TrcvIdx, u8RegIdx, pu16RegValPtr);
                    if((Std_ReturnType)E_OK == eReturnStatus)
                    {
                        Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
                        Eth_43_PFE_EthTrcvDriverFunctionList.ReadMiiIndicationFunction(u8CtrlIdx, u8TrcvIdx, u8RegIdx, *pu16RegValPtr);
                    }
                }
#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
            }
        }
    }
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */

    return eReturnStatus;
}

#if STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API
/**
 * @brief       Write specified transceiver register through the MII (Clause 45)
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver
 * @param[in]   u8DevIdx Index of the device within the transciever
 * @param[in]   u16RegIdx Index of the transceiver register
 * @param[in]   u16RegVal Value to be written into the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_WriteMii45(uint8 u8CtrlIdx, \
                                     uint8 u8TrcvIdx, \
                                     uint8 u8DevIdx, \
                                     uint16 u16RegIdx, \
                                     uint16 u16RegVal \
                                    )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_WRITEMII45, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if((u8TrcvIdx > (uint8)ETH_43_PFE_PHY_ADDR_MAX) || (u8DevIdx > (uint8)ETH_43_PFE_PHY_DEV_MII45_MAX))
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_WRITEMII45, \
                ETH_43_PFE_E_INV_PARAM \
                                  );
        }
        else
        {
            if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (uint8) ETH_43_PFE_MODULE_ID, \
                    ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_WRITEMII45, \
                    ETH_43_PFE_E_UNINIT \
                                      );
            }
            else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
            {
                eReturnStatus = Eth_43_PFE_LLD_WriteMii45(u8CtrlIdx, u8TrcvIdx, u8DevIdx, u16RegIdx, u16RegVal);
                if((Std_ReturnType)E_OK == eReturnStatus)
                {
                    /*  No indication to EthTrcv due to API incompatibility (u16RegIdx Vs u8RegIdx) */
                    ;
                }
            }
#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
        }
    }
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */

    return eReturnStatus;
}

/**
 * @brief       Read the specified transceiver register through the MII (Clause 45)
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver (address)
 * @param[in]   u16RegIdx Index of the transceiver register
 * @param[in]   u8DevIdx Index of the device within the transciever
 * @param[out]  pu16RegValPtr Filled with the register content of the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_ReadMii45(uint8 u8CtrlIdx, \
                                    uint8 u8TrcvIdx, \
                                    uint8 u8DevIdx, \
                                    uint16 u16RegIdx, \
                                    uint16 *pu16RegValPtr \
                                   )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_READMII45, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if((u8TrcvIdx > (uint8)ETH_43_PFE_PHY_ADDR_MAX) || (u8DevIdx > (uint8)ETH_43_PFE_PHY_DEV_MII45_MAX))
        {
            (void)Det_ReportError ( \
                (uint8) ETH_43_PFE_MODULE_ID, \
                ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_READMII45, \
                ETH_43_PFE_E_INV_PARAM \
                                  );
        }
        else
        {
            if(NULL_PTR == pu16RegValPtr)
            {
                (void)Det_ReportError ( \
                        (uint8) ETH_43_PFE_MODULE_ID, \
                        ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                        ETH_43_PFE_SID_READMII45, ETH_43_PFE_E_PARAM_POINTER \
                                      );
            }
            else
            {
                if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
                {
                    (void)Det_ReportError ( \
                            (uint8) ETH_43_PFE_MODULE_ID, \
                            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
                            ETH_43_PFE_SID_READMII45, ETH_43_PFE_E_UNINIT \
                                          );
                }
                else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
                {
                    eReturnStatus = Eth_43_PFE_LLD_ReadMii45(u8CtrlIdx, u8TrcvIdx, u8DevIdx, u16RegIdx, pu16RegValPtr);
                    if((Std_ReturnType)E_OK == eReturnStatus)
                    {
                        /*  No indication to EthTrcv due to API incompatibility (u16RegIdx Vs u8RegIdx) */
                        ;
                    }
                }
#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
            }
        }
    }
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */

    return eReturnStatus;
}

#endif /* STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API */
#endif /* STD_ON == ETH_43_PFE_CTRLENABLE_MII */

#if STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT
/*================================================================================================*/
/**
 * @brief       Set the global time for the EMAC corresponding to provided controller index
 * @details     If option @ref IEEE1588ClockAttachedToGMAC or @ref IEEE1588ClockAttachedToEMAC0
 *              is enabled for underlying EMAC, this function will fail.
 * @api
 * @param[in]   u8CtrlIdx Index of the controller within the context of the Ethernet Driver
 * @param[in]   timeStampPtr Struct of time value to be configured
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_SetGlobalTime(uint8 u8CtrlIdx, const Eth_TimeStampType *timeStampPtr)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    uint8 DetectedError = (uint8)E_OK;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        DetectedError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if(NULL_PTR == timeStampPtr)
    {
        DetectedError = ETH_43_PFE_E_PARAM_POINTER;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        DetectedError = ETH_43_PFE_E_UNINIT;
    }
    else
    {
        /* This statement is written to avoid MISRA 15.7 */
    }

    if ((uint8)E_OK != DetectedError)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_SETGLOBALTIME, DetectedError \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_SetGlobalTime(u8CtrlIdx, timeStampPtr);
    }

    return eReturnStatus;
}
/*================================================================================================*/

/**
* @brief        Allows the Time Slave to adjust the local ETH Reference clock in HW.
* @details      Only use this function when this controller is used as Time Slave.
*               If option @ref IEEE1588ClockAttachedToGMAC or @ref IEEE1588ClockAttachedToEMAC0
*               is enabled for underlying EMAC, this function will fail.
* @param[in]    u8CtrlIdx       Index of the controller which time shall be corrected
* @param[in]    timeOffsetPtr   Offset between time stamp grandmaster and time stamp by local clock.
* @param[in]    rateRatioPtr    Time elements to calculate and to modify the ratio of the frequency
*               of the grandmaster in relation to the frequency of the Local Clock.
*/
Std_ReturnType Eth_43_PFE_SetCorrectionTime (   uint8 u8CtrlIdx, \
                                                const Eth_TimeIntDiffType *timeOffsetPtr, \
                                                const Eth_RateRatioType *rateRatioPtr \
                                            )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    uint8 DetectedError = (uint8)E_OK;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        DetectedError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if((NULL_PTR == timeOffsetPtr) || (NULL_PTR == rateRatioPtr))
    {
        DetectedError = ETH_43_PFE_E_PARAM_POINTER;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        DetectedError = ETH_43_PFE_E_UNINIT;
    }
    else
    {
        /* This statement is written to avoid MISRA 15.7 */
    }

    if ((uint8)E_OK != DetectedError)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_SETCORRECTIONTIME, DetectedError \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_SetCorrectionTime(u8CtrlIdx, timeOffsetPtr, rateRatioPtr);
    }

    return eReturnStatus;
}

/*================================================================================================*/

/**
 * @brief       Get the global time from the EMAC corresponding to provided controller index
 * @api
 * @param[in]   u8CtrlIdx Index of the controller within the context of the Ethernet Driver
 * @param[out]  timeQualPtr Pointer to quality of HW time stamp
 * @param[out]  timeStampPtr Struct of time value to be read
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_GetCurrentTime( uint8 u8CtrlIdx, \
                                          Eth_TimeStampQualType *timeQualPtr, \
                                          Eth_TimeStampType *timeStampPtr \
                                        )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    uint8 DetectedError = (uint8)E_OK;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        DetectedError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr))
    {
        DetectedError = ETH_43_PFE_E_PARAM_POINTER;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        DetectedError = ETH_43_PFE_E_UNINIT;
    }
    else
    {
        /* This statement is written to avoid MISRA 15.7 */
    }

    if ((uint8)E_OK != DetectedError)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_GETCURRENTTIME, DetectedError \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        *timeQualPtr = ETH_UNCERTAIN;
        Eth_43_PFE_LLD_GetCurrentTime(u8CtrlIdx, timeQualPtr, timeStampPtr);

        if (ETH_VALID == *timeQualPtr)
        {
            eReturnStatus = (Std_ReturnType)E_OK;
        }
    }

    return eReturnStatus;
}

/*================================================================================================*/

/**
 * @brief       Activate egress time stamping on a dedicated message object
 * @api
 * @param[in]   u8CtrlIdx Index of the controller within the context of the Ethernet Driver
 * @param[in]   BufIdx Index of the buffer resource to be used
 */
void Eth_43_PFE_EnableEgressTimeStamp(uint8 u8CtrlIdx, Eth_BufIdxType BufIdx)
{
#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    uint8 DetectedError = (uint8)E_OK;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        DetectedError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if(BufIdx >= ETH_43_PFE_MAX_CTRL_TX_BUF_CNT)
    {
        DetectedError = ETH_43_PFE_E_INV_PARAM;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        DetectedError = ETH_43_PFE_E_UNINIT;
    }
    else
    {
        /* This statement is written to avoid MISRA 15.7 */
    }

    if ((uint8)E_OK != DetectedError)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_ENABLEEGRESSTIMESTAMP, DetectedError \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        Eth_43_PFE_LLD_EnableEgressTimeStamp(u8CtrlIdx, BufIdx);
    }
}

/*================================================================================================*/

/**
 * @brief       Get the egress time stamp of the last packet sending from certain controller
 * @api
 * @param[in]   u8CtrlIdx Index of the controller within the context of the Ethernet Driver
 * @param[in]   BufIdx    Index of the buffer resource was used to be transmitted
 * @param[out]  timeQualPtr Pointer to quality of HW time stamp
 * @param[out]  timeStampPtr Struct of time value to be read
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_GetEgressTimeStamp(   uint8 u8CtrlIdx, \
                                                Eth_BufIdxType BufIdx, \
                                                Eth_TimeStampQualType *timeQualPtr, \
                                                Eth_TimeStampType *timeStampPtr \
                                            )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    uint8 DetectedError = (uint8)E_OK;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        DetectedError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr))
    {
        DetectedError = ETH_43_PFE_E_PARAM_POINTER;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        DetectedError = ETH_43_PFE_E_UNINIT;
    }
    else
    {
        /* This statement is written to avoid MISRA 15.7 */
    }

    if ((uint8)E_OK != DetectedError)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_GETEGRESSTIMESTAMP, DetectedError \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        *timeQualPtr = ETH_UNCERTAIN;
        Eth_43_PFE_LLD_GetTxTimeStamp(u8CtrlIdx, BufIdx, timeQualPtr, timeStampPtr);

        if (ETH_VALID == *timeQualPtr)
        {
            eReturnStatus = (Std_ReturnType)E_OK;
        }
    }

    return eReturnStatus;
}

/*================================================================================================*/

/**
 * @brief       Get the ingress time stamp of the received packet
 * @api
 * @param[in]   u8CtrlIdx Index of the controller within the context of the Ethernet Driver
 * @param[in]   DataPtr   Pointer to the received packet
 * @param[out]  timeQualPtr Pointer to quality of HW time stamp
 * @param[out]  timeStampPtr Struct of time value to be read
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_GetIngressTimeStamp   (   uint8 u8CtrlIdx, \
                                                    const Eth_DataType *DataPtr, \
                                                    Eth_TimeStampQualType *timeQualPtr, \
                                                    Eth_TimeStampType *timeStampPtr \
                                                )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    uint8 DetectedError = (uint8)E_OK;

    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        DetectedError = ETH_43_PFE_E_INV_CTRL_IDX;
    }
    else if((NULL_PTR == DataPtr) || (NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr))
    {
        DetectedError = ETH_43_PFE_E_PARAM_POINTER;
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        DetectedError = ETH_43_PFE_E_UNINIT;
    }
    else
    {
        /* This statement is written to avoid MISRA 15.7 */
    }

    if ((uint8)E_OK != DetectedError)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) \
            ETH_43_PFE_SID_GETINGRESSTIMESTAMP, DetectedError \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        *timeQualPtr = ETH_UNCERTAIN;
        (void)Eth_43_PFE_LLD_GetRxTimeStamp(u8CtrlIdx, DataPtr, timeQualPtr, timeStampPtr);

        if (ETH_VALID == *timeQualPtr)
        {
            eReturnStatus = (Std_ReturnType)E_OK;
        }
    }

    return eReturnStatus;
}
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

/* Can be used to export the pfe_platform instance, which might be needed by external (slave) HIF driver */
void * Eth_43_PFE_GetPlatform(void)
{
    return Eth_PFE_LLD_GetPlatform();
}

/* Should be used to initialize pfe interfaces */
void Eth_43_PFE_PreInit(const Eth_43_PFE_ConfigType * CfgPtr)
{

#if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
#if STD_ON == ETH_43_PFE_PRECOMPILE_SUPPORT
    if(NULL_PTR != CfgPtr)
#else
    if(NULL_PTR == CfgPtr)
#endif /* ETH_43_PFE_PRECOMPILE_SUPPORT */
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, (uint8) ETH_43_PFE_SID_PREINIT, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
#endif /* ETH_43_PFE_DEV_ERROR_DETECT  */
    {
        #if STD_ON == ETH_43_PFE_PRECOMPILE_SUPPORT
            Eth_43_PFE_InternalCfgPtr = &Eth_43_PFE_Config;
            (void)CfgPtr;
        #else
            Eth_43_PFE_InternalCfgPtr = CfgPtr;
        #endif /* ETH_43_PFE_PRECOMPILE_SUPPORT */

        /* Initialize interfaces */
        Local_Macro_Eth_PFE_LLD_InitInterfaces(Eth_43_PFE_InternalCfgPtr);
        Local_Macro_Eth_PFE_LLD_InitEMACs(Eth_43_PFE_InternalCfgPtr);
    }
}

#if STD_ON == ETH_43_GET_CLASS_STATISTIC_API
/**
 * @brief       Get class statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      E_OK Success
 * @retval      E_NOT_OK Not possible to allocate memory for read
 */
Std_ReturnType Eth_43_PFE_GetClassStats(pfe_ct_classify_stats_t * stat)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETCLASSSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETCLASSSTATS, \
            ETH_43_PFE_E_UNINIT \
                              ); 
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetClassStats(stat);
    }
    return eReturnStatus;
}
#endif /* ETH_43_GET_CLASS_STATISTIC_API */

#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
/**
 * @brief       Get bmu statistics from firmware
 * @api
 * @param[in]   u8BmuIndex  Bmu instance
 * @param[out]  stat Statistic structure
 * @retval      E_OK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetBmuStats(uint8 u8BmuIndex, Eth_43_PFE_BmuStatsType* stat)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETBMUSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (PFE_BMU_INSTANCES <= u8BmuIndex)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETBMUSTATS, \
            ETH_43_PFE_E_INV_PARAM \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETBMUSTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetBmuStats(u8BmuIndex, stat);
    }
    return eReturnStatus;
}

/**
 * @brief       Get gpi statistics from firmware
 * @param[in]   u8GpiIndex  Gpi instance
 * @param[out]  stat Statistic structure
 * @retval      E_OK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetGpiStats(uint8 u8GpiIndex, Eth_43_PFE_GpiStatsType* stat)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETGPISTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (PFE_GPI_INSTANCES <= u8GpiIndex)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETGPISTATS, \
            ETH_43_PFE_E_INV_PARAM \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETGPISTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetGpiStats(u8GpiIndex, stat);
    }
    return eReturnStatus;
}

/**
 * @brief       Get wdt statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      E_OK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetWdtStats(Eth_43_PFE_WdtStatsType * stat)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETWDTSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETWDTSTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetWdtStats(stat);
    }
    return eReturnStatus;
}

/**
 * @brief       Get l2 bridge statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      E_OK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetL2BridgeStats(Eth_43_PFE_L2BridgeStatsType * stat, uint32 index_entry)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETL2BRIDGESTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETL2BRIDGESTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetL2BridgeStats(stat, index_entry);
    }
    return eReturnStatus;
}

/**
 * @brief       Get l2 bridge statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @param[in]  index_vlan index of vlan
 * @retval      E_OK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetL2BridgeDomainStats(pfe_ct_vlan_stats_t* stat, uint32 index_vlan)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETL2BRIDGEDOMAINSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETL2BRIDGEDOMAINSTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetL2BridgeDomainStats(stat, (uint8)(index_vlan & UINT8_MAX));
    }
    return eReturnStatus;
}

/**
 * @brief       Get rtable statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @param[out]  conntrack_index conntrack index
 * @retval      EOK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetRtableStats(pfe_ct_conntrack_stats_t * stat, uint8 conntrack_index)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETRTABLESTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETRTABLESTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetRtableStats(stat, conntrack_index);
    }
    return eReturnStatus;
}

/**
 * @brief       Get tmu statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      EOK If possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_GetTmuStats(Eth_43_PFE_TmuStatsType * stat)
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if (NULL_PTR == stat)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTMUSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else if (FALSE == Eth_PFE_LLD_Check_Driver_Init())
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTMUSTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_43_PFE_LLD_GetTmuStats(stat);
    }
    return eReturnStatus;
}
#endif /* ETH_43_GET_PFE_STATISTIC_API */

#if STD_ON == ETH_43_GET_COUNTER_API
/**
* @brief         Reads a list with drop counter values of the corresponding controller.
* @api
* @param[in]     u8CtrlIdx  Index of the controller
* @param[out]    CounterPtr Pointer to Eth_CounterType where to store the read drop counter values
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected or inaccessible to counters register
*                and the function.
* @details       Reads a list with drop counter values of the corresponding controller. The meaning
*                of these values is hardware dependent. However, the list DropCount[] shall
*                contain the following values in the given order, where the maximal possible value
*                shall denote an invalid value, e.g. if this counter is not available:
*                1. Dropped packets due to buffer overrun
*                2. Dropped packets due to CRC errors
*                3. Number of undersize packets which were less than 64 octets long (excluding
*                framing bits, but including FCS octets) and were otherwise will formed. (see IETF
*                RFC 1757)
*                4. Number of oversize packets which are longer than 1518 octets (excluding
*                framing bits, but including FCS octets) and were otherwise well formed. (see IETF
*                RFC 1757)
*                5. Number of alignment errors, i.e. packets which are received and are not an
*                integral number of octets in length and do not pass the CRC.
*                6. SQE test error according to IETF RFC1643 dot3StatsSQETestErrors
*                7. The number of inbound packets which were chosen to be discarded even
*                though no errors had been detected to prevent their being deliverable to a higher layer protocol.
*                One possible reason for discarding such a packet could be to free
*                up buffer space. (see IETF RFC 2233 ifInDiscards)
*                8. Total number of erroneous inbound packets
*                9. The number of outbound packets which were chosen to be discarded even
*                though no errors had been detected to prevent their being transmitted. One
*                possible reason for discarding such a packet could be to free up buffer space.
*                (see IETF RFC 2233 ifOutDiscards)
*                10. Total number of erroneous outbound packets
*                11. Single collision frames: A count of successfully transmitted frames on a
*                particular interface for which transmission is inhibited by exactly one collision. (see
*                IETF RFC1643 dot3StatsSingleCollisionFrames)
*                12. Multiple collision frames: A count of successfully transmitted frames on a
*                particular interface for which transmission is inhibited by more than one collision.
*                (see IETF RFC1643 dot3StatsMultipleCollisionFrames)
*                13. Number of deferred transmission: A count of frames for which the first
*                transmission attempt on a particular interface is delayed because the medium is
*                busy. (see IETF RFC1643 dot3StatsDeferredTransmissions)
*                14. Number of late collisions: The number of times that a collision is detected on
*                a particular interface later than 512 bit times into the transmission of a packet.
*                (see IETF RFC1643 dot3StatsLateCollisions)
*                15. The following positions in the list can contain hardware dependent counter
*                values
* implements     Eth_GetCounterValues_Activity
*/
Std_ReturnType Eth_43_PFE_GetCounterValues(uint8 u8CtrlIdx, \
                                            Eth_CounterType * CounterPtr
                                        )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETCOUNTERVALUE, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETCOUNTERVALUE, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else if (NULL_PTR == CounterPtr)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETCOUNTERVALUE, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_PFE_LLD_GetCounterValues(u8CtrlIdx, CounterPtr);
    }

    return eReturnStatus;
}
#endif /* STD_ON == ETH_43_GET_COUNTER_API */

#if STD_ON == ETH_43_GET_RXSTATS_API
/**
* @brief         Read the status of a controller
* @details       Returns the following list according to IETF RFC2819, where the maximal possible
*                value shall denote an invalid value, e.g. if this counter is not available:
*                1. etherStatsDropEvents
*                2. etherStatsOctets
*                3. etherStatsPkts
*                4. etherStatsBroadcastPkts
*                5. etherStatsMulticastPkts
*                6. etherStatsCrcAlignErrors
*                7. etherStatsUndersizePkts
*                8. etherStatsOversizePkts
*                9. etherStatsFragments
*                10. etherStatsJabbers
*                11. etherStatsCollisions
*                12. etherStatsPkts64Octets
*                13. etherStatsPkts65to127Octets
*                14. etherStatsPkts128to255Octets
*                15. etherStatsPkts256to511Octets
*                16. etherStatsPkts512to1023Octets
*                17. etherStatsPkts1024to1518Octets
* @api
* @param[in]     CtrlIdx Index of the controller which shall be read the status register.
* @param[out]    RxStatsPtr Pointer to 32 bit long memory space to be filled with
*                the list values according to IETF RFC 2819 (Remote Network
*                Monitoring Management Information Base).
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected or inaccessible to counters register
*                and the function.
* implements     Eth_GetRxStats_Activity
*/
Std_ReturnType Eth_43_PFE_GetRxStats(uint8 u8CtrlIdx, \
                                            Eth_RxStatsType * RxStatsPtr
                                        )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETRXSTATS, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETRXSTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else if (NULL_PTR == RxStatsPtr)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETRXSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_PFE_LLD_GetRxStats(u8CtrlIdx, RxStatsPtr);
    }

    return eReturnStatus;
}
#endif /* STD_ON == ETH_43_GET_RXSTATS_API */

#if STD_ON == ETH_43_GET_TXSTATS_API
/**
* @brief         Return the list of Transmission Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    TxStatsPtr Pointer to 32 bit long memory space to be filled with
*                the list values according to IETF RFC 1213
* @details       Return the list of Transmission Statistics out of IETF RFC 1213
*                defined within Eth_TxStatsType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
* @return        The search status
* @retval        E_OK Success
* @retval        E_NOT_OK Tx-statistics could not be obtained.
* implements     Eth_GetTxStats_Activity
*/
Std_ReturnType Eth_43_PFE_GetTxStats(uint8 u8CtrlIdx, \
                                            Eth_TxStatsType * TxStatsPtr
                                        )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTXSTATS, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTXSTATS, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else if (NULL_PTR == TxStatsPtr)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTXSTATS, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_PFE_LLD_GetTxStats(u8CtrlIdx, TxStatsPtr);
    }

    return eReturnStatus;
}
#endif /* STD_ON == ETH_43_GET_TXSTATS_API */

#if STD_ON == ETH_43_GET_TXERROR_COUNTER_API
/**
* @brief         Return the list of Transmission Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    TxErrorCounterValuesPtr List of values to read statistic error counter values for transmission.
* @details       Return the list of Transmission Error Counters out of IETF RFC1213 and RFC1643
*                defined within Eth_TxErrorCounterValuesType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available.
* @return        The search status
* @retval        E_OK Success
* @retval        E_NOT_OK Tx-statistics could not be obtained.
* implements     Eth_GetTxErrorCounterValues_Activity
*/
Std_ReturnType Eth_43_PFE_GetTxErrorCounterValues(uint8 u8CtrlIdx, \
                                            Eth_TxErrorCounterValuesType * TxErrorCounterValuesPtr
                                        )
{
    Std_ReturnType eReturnStatus = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
    if(u8CtrlIdx >= (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTXERRORCOUNTERVALUE, \
            ETH_43_PFE_E_INV_CTRL_IDX \
                              );
    }
    else if(ETH_STATE_INIT != Eth_43_PFE_CtrlState[u8CtrlIdx])
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTXERRORCOUNTERVALUE, \
            ETH_43_PFE_E_UNINIT \
                              );
    }
    else if (NULL_PTR == TxErrorCounterValuesPtr)
    {
        (void)Det_ReportError ( \
            (uint8) ETH_43_PFE_MODULE_ID, \
            ETH_43_PFE_DRIVER_INSTANCE, \
            (uint8) ETH_43_PFE_SID_GETTXERRORCOUNTERVALUE, \
            ETH_43_PFE_E_PARAM_POINTER \
                              );
    }
    else
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
    {
        eReturnStatus = Eth_PFE_LLD_GetTxErrorCounterValues(u8CtrlIdx, TxErrorCounterValuesPtr);
    }

    return eReturnStatus;
}
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */

#if (STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER)
/**
 * @brief       Disables a HIF channel and flushes its cached RX BDs
 * @details     The function is intended for assisting a slave driver to recover from crash. It:
 *              - disables the HIF channel, so it will no longer receive normal traffic,
 *              - flushes cached Rx buffer descriptors from the HIF channel. During this process
 *                the PFE HW needs write access to buffers and buffer descriptor memory which was previously
 *                configured by the crashed driver.
 * @note        This function can only be used for HIF channel of a slave driver which is no longer running.
 * @note        This function is available only on master driver, only if option 
 *              "Enable PFE Channel BD Flush API" is enabled.
 * @param[in]   DestHifChnl Physical interface ID of the HIF used by the slave driver which has crashed.
 * @retval      E_OK Flushing was successfull and is complete
 * @retval      E_NOT_OK Flushing has failed
 * @retval      ETH_43_PFE_E_AGAIN Another call of this function is needed to continue the flush 
 *              (due to limit configured in option PfeChannelBdFlushMaxBdCount)
 */
Std_ReturnType Eth_43_PFE_ChannelBdFlushRx(pfe_ct_phy_if_id_t DestHifChnl)
{
    Std_ReturnType eReturnStatus;
    eReturnStatus = Eth_PFE_LLD_ChannelBdFlushRx(DestHifChnl);
    return eReturnStatus;
}
#endif /* STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
