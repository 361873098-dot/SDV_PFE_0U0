#The path to the GCC installation dir
GCC_DIR ?= C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi

#The path to the EB Tresos installation dir
TRESOS_DIR ?= C:/EB/tresos29

#The path to the T32 installation dir
T32_DIR ?= C:/Tools/T32_ARM

#The path to the VDK installation dir
VDK_DIR ?= C:/NOT/CONFIGURED/PATH

#The path to the Tresos plugins directory
PLUGINS_DIR ?= C:/NXP/SW32G_RTD_4.4_4.0.2_P04_D2312/eclipse/plugins

#The path to the Tresos add-on plugins directory
PLUGINS_DIR_ADDON ?=

#The paths to the additional directories to be included at build phase
ADDITIONAL_INCLUDE_DIRS ?=

#The path to the NXP IPCF driver instalation dir
SHM_DRIVER_PATH ?= ../..

# ------------------------------------------------------------------------------------
#Example specific parameters - do not modify

#MCAL modules used
MCAL_MODULE_LIST := BaseNXP Platform Resource

#MCAL modules used - only for examples based on 2 software products
MCAL_MODULE_LIST_ADDON :=

#The package name for the MCAL release
AR_PKG_NAME = TS_T40D11M40I2R0

#The package name for the MCAL release - only for examples based on 2 software products
AR_PKG_NAME_ADDON =

#The derivative of the device
EXAMPLE_DERIVATIVE = S32G399A

#The core type of the device
EXAMPLE_CORE_TYPE = M7

#The name of the elf file
ELFNAME = IPCF_Example_multi_instance_S32G399A_M7_1

#The name of the Tresos project
TRESOS_PROJECT_NAME = IPCF_Example_multi_instance_S32G399A_M7_1

#The number of variants for the Tresos project
VARIANT_NO = 0
