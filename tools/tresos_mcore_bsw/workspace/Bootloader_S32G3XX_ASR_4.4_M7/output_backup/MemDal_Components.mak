#===================================================================================================
#
#   @file              MemDal_Components.mak
#   project            AUTOSAR 4.4 MCAL
#   platform           CORTEXM
#
#   @brief             This file specifies BSW modules which will be compiled and linked
#   @details
#
#   Autosar Version    4.4.0
#   Build Version      S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
#
#   (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
#       Copyright 2017-2020 NXP
#   All Rights Reserved.
#
#===================================================================================================

MEMDAL_SDHC_ENABLED:=ON

MEMDAL_FEE_ENABLED:=OFF
MEMDAL_FEE_ASR_MODULES:=

DRIVERS_MODULE_LIST += $(MEMDAL_FEE_ASR_MODULES)


