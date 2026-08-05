#=========================================================================================================================
#   @file       SysDal_Components.mak
#   @version 23.02.0
#
#   @brief   This file specifies BSW modules which will be compiled and linked
#   @details
#
#   (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
#       Copyright 2017-2021 NXP
#   All Rights Reserved.
#   This file contains sample code only. It is not part of the production code deliverables.
#
#
#=========================================================================================================================
#   Project              : AUTOSAR 4.4 MCAL
#   Platform             : CORTEXM
#
#   Autosar Version      : 4.4.0
#   Autosar Revision     : ASR_REL_4_4_REV_0000
#
#   SW Version           : 23.02.0
#   Build Version        : S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
#
#===========================================================================================================================*/


# The RTD modules to be used.
DRIVERS_MODULE_LIST :=  Mcu Port Det Base EcuM EcuC Rte  Mcl Os Platform Gpt 

ASR_OS_FLAG =  AUTOSAR_OS_NOT_USED

USE_NON_ASR_PERIPHERALS=STD_OFF

USER_CODE_FALG =   USER_CODE_NOT_USED

OTHER_SYSTEM_FLAGS :=  

OTHER_SYSTEM_FLAGS += -DENABLE_RUNTIME_MEASUREMENTS
RTM_ENABLED=STD_ON

OTHER_SYSTEM_FLAGS += -DSYS_TICK_RUNTIME_MEASUREMENTS
    
