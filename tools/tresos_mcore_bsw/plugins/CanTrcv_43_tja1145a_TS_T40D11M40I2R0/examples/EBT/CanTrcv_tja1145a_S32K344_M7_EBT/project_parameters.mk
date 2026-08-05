#The path to the GCC instalation dir
GCC_DIR = D:/SetUp_Common_Tools/S32DS_SETUP_3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi

#The path to the EB Tresos instalation dir
TRESOS_DIR = C:/EB/tresos_29

#The path to the T32 instalation dir
T32_DIR = C:/T32_RUN_TEST/T32_K3_300_RTM

#The path to the Tresos plugins directory
PLUGINS_DIR = C:/NXP/SW32K3_RTD_4.4_R21-11_3.0.0/eclipse/plugins

#The path to the Tresos add-on plugins directory
PLUGINS_DIR_ADDON = ../../../../

#The paths to the additional directories to be included at build phase
ADDITIONAL_INCLUDE_DIRS =

#Loading project to ram or flash
LOAD_TO=

#MCAL modules used
MCAL_MODULE_LIST := BaseNXP Dem Det Resource Mcu Dio Port EcuC EcuM CanIf Can_43_FLEXCAN Platform Rte Spi

#MCAL modules used - only for examples based on 2 software products
MCAL_MODULE_LIST_ADDON:= CanTrcv_43_tja1145a

#The package name for the MCAL release
AR_PKG_NAME = TS_T40D34M30I0R0

#The package name for the MCAL release - only for examples based on 2 software products
AR_PKG_NAME_ADDON = TS_T40D34M8I0R0

#The derivative of the device
EXAMPLE_DERIVATIVE = S32K344

#The name of the elf file
ELFNAME = main

#The test base address 
TEST_BASE_ADDR = 0x2043FF00

#The name of the Tresos project 
TRESOS_PROJECT_NAME = CanTrcv_tja1145a_S32K344_M7_EBT
#The number of variants for the Tresos project 
VARIANT_NO = 1
#Connection type of lauterbach
PBI = replace_pbi
#VDK directory
VDK_DIR=
