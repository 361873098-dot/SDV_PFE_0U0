#Select a toolchain from the list: replace_toolchain_list
TOOLCHAIN = gcc

#The path to the GCC installation dir
GCC_DIR = replace_gcc_dir

#The path to the DIAB installation dir
DIAB_DIR = replace_diab_dir

#The path to the EB Tresos installation dir
TRESOS_DIR = replace_tresos_dir

#The path to the T32 installation dir
T32_DIR = replace_t32_dir

#The path to the VDK installation dir
VDK_DIR = C:/N-2017.12-20191120-1100/VirtualizerRuntime/SLS/windows
VDK_TEMPLATE_NAME = replace_vdk_template_name
VDK_TEMPLATE_VERSION = replace_vdk_template_version
VDK_VPCONFIG_NAME = replace_vdk_vpconfig_name

LLCE_BIN_LOCATION = replace_llce_bin_dir
LLCE_INTERFACE_LOCATION = replace_llce_interface_dir

#The path to the Tresos plugins directory
PLUGINS_DIR = replace_rtd_plugin_dir

#The path to the Tresos add-on plugins directory
PLUGINS_DIR_ADDON = ../../../../../

#The paths to the additional directories to be included at build phase
ADDITIONAL_INCLUDE_DIRS = 

#Loading project to ram or flash
LOAD_TO=

# ------------------------------------------------------------------------------------
#Example specific parameters - do not modify 

#MCAL modules used
MCAL_MODULE_LIST := BaseNXP Det Dem Rte Platform Mcu Port Rte EcuC FrIf Resource

#MCAL modules used - only for examples based on 2 software products
MCAL_MODULE_LIST_ADDON := Fr_43_LLCE

#The package name for the MCAL release
AR_PKG_NAME = TS_T40D11M40I2R0

#The AUTOSAR module origin ('NXP')
AR_MODULE_ORIGIN = NXP

#The package name for the MCAL release - only for examples based on 2 software products
AR_PKG_NAME_ADDON = TS_T40D11M10I7R0

#The derivative of the device
EXAMPLE_DERIVATIVE = S32G399A

#The core type of the device
EXAMPLE_CORE_TYPE = M7

#The name of the elf file
ELFNAME = main

#The test base address 
TEST_BASE_ADDR = 0x34500000

# The test block size
TEST_BLOCK_SIZE = 255

#The name of the Tresos project 
TRESOS_PROJECT_NAME = FR_ExternalCommunication_node1_S32G399A_M7

#The number of variants for the Tresos project 
VARIANT_NO = 0

#Connection type of lauterbach
PBI = replace_pbi

RUN_SECOND_SAMPLEAPP_ENABLE = 
SECOND_SAMPLEAPP_DIR = 

