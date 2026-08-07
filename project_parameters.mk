#  Copyright 2020-2024 NXP
#
#  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
#  be used strictly in accordance with the applicable license terms. By
#  expressly accepting such terms or by downloading, installing, activating
#  and/or otherwise using the software, you are agreeing that you have read,
#  and that you agree to comply with and are bound by, such license terms. If
#  you do not agree to be bound by the applicable license terms, then you may
#  not retain, install, activate or otherwise use the software.
#
#  This file contains sample code only. It is not part of the production code deliverables.

#The path to the compiler instalation dir
#GHS_DIR ?= c:/ghs/comp_202014
GCC_DIR ?= D:/Tools/gcc_v9.2/gcc-9.2-arm32-eabi
#DIAB_DIR ?= c:/WindRiver/compilers/diab-7.0.3.0

#The path to the Tresos plugins directory
TRESOS_DIR ?= D:/work/SDV_PFE/Hpc_m7_prj/tools/tresos_mcore_bsw
PLUGINS_DIR ?= $(TRESOS_DIR)/plugins
TRESOS_WORKSPACE_DIR ?= $(TRESOS_DIR)/workspace
FW_DIR ?= ./work/driver/pfe_firmware
LWIP_DIR ?= ./work/lwip
MIDDLEWARE_DIR ?= ./work/middleware
FREERTOS_DIR ?= ./work/freertos
FREERTOS_PORT_DIR ?= $(FREERTOS_DIR)/portable/GCC/ARM_CM7/r0p1
FREERTOS_HEAP_DIR ?= $(FREERTOS_DIR)/portable/MemMang
PRJ_CNF_DIR ?= ./work/prj/
IPCF_DIR ?= ./work/driver/ipcf
#MCAL modules used
MCAL_MODULE_LIST :=  BaseNXP Det Dio Dem Gpt Mcu Mcl Rte Port Platform EthSwt EthTrcv I2c Pmic

#The package name for the MCAL release
AR_MCAL_PKG_NAME = TS_T40D11M40I2R0

#The package name for the PFE MCAL release
AR_PFE_PKG_NAME = TS_T40D11M14I0R0

#Ipc package name for the IPCF releas
AR_IPCF_PKG_NAME = TS_T40D11M410I0R0
SHM_PLATFORM ?= s32g3xx
SHM_OS_TARGET ?= freertos
SHM_DRIVER_PATH ?= $(PLUGINS_DIR)/Ipcf_$(AR_IPCF_PKG_NAME)

