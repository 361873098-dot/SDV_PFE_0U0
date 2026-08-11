#===============================================================================
#
#    @file       modules.mak
#    @version    23.02.0
#
#    @brief      Configuration modules
#    @details    Makefile containing the modules and functionalities included
#                in the build.
#
#    Platform        : CORTEXM
#    Build Version   : S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
#
#   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
#       All Rights Reserved.
#
#    This file contains sample code only.
#    It is not part of the production code deliverables.
#===============================================================================

SAMPLE_APP_NAME := Bootloader

# The Platform Integration DALs to be used.
DALS_LIST := SysDal
include $(TRESOS_WORKSPACE_DIR)/SysDal_Components.mak

DRIVERS_MODULE_LIST += Fls MemIf








DALS_LIST += MemDal
include $(TRESOS_WORKSPACE_DIR)/MemDal_Components.mak


SDHC_ENABLED := OFF


SAF_ENABLED := OFF


CCOPT += -DCONSOLE_ENABLED=STD_OFF

