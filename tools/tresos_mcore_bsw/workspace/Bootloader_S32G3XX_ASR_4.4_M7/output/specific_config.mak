#===============================================================================
#
#    @file       specific_config.mak
#    @version    23.02.0
#
#    @brief      Platform specific configuration
#    @details    Makefile containing platform-related configuration.
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

################################################################################
# Platform, derivative, package
################################################################################
ifeq ($(DERIVATIVE),)
DERIVATIVE := S32G3XX
endif
PLATFORM   := S32XX

