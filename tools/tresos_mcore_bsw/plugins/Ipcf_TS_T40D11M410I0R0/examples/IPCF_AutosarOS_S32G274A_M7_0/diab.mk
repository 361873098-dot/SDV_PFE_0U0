#   Copyright 2023-2024 NXP
#
#   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
#   in accordance with the applicable license terms.  By expressly accepting
#   such terms or by downloading, installing, activating and/or otherwise using
#   the software, you are agreeing that you have read, and that you agree to
#   comply with and are bound by, such license terms.  If you do not agree to
#   be bound by the applicable license terms, then you may not retain,
#   install, activate or otherwise use the software.
#
#   This file contains sample code only. It is not part of the production code deliverables.
#

# Compiler paths
cbin        := $(DIAB_DIR)/WIN64/bin
cinc        := $(DIAB_DIR)/include
clib        := $(DIAB_DIR)/ARMV7EMMN
cinc_llvm   := $(DIAB_DIR)/../lvm-9.0.1.1/WIN64/lib/clang/9.0.1.1/include

CC          := $(cbin)/dcc.exe
LD          := $(cbin)/dld.exe
AS          := $(cbin)/dcc.exe
OT          := $(cbin)/objcopyarm.exe

CCOPT_CORE = -tARMCORTEXM7MG:simple
ASOPT_CORE = -tARMCORTEXM7MG:simple
LDOPT_CORE = -tARMCORTEXM7MG:simple

#linker definition  per compiler
LINKER_DEF = lcf/$(compiler)/linker_ram.dld

################################################################################
# Compiler options
################################################################################
CCOPT           :=  $(CCOPT) \
                    $(MISRA) \
                    $(CCOPT_CORE) \
                    -D$(PLATFORM) \
                    -D$(FAMILY) \
                    -D$(DERIVATIVE) \
                    -DDIAB \
                    -DOSDIABARM \
                    -DOSNOSMALLSECTIONS \
                    -DEU_DISABLE_ANSILIB_CALLS \
                    -DUSE_SW_VECTOR_MODE \
                    -c \
                    -mthumb \
                    -std=c99 \
                    -Oz \
                    -g \
                    -fstandalone-debug \
                    -Wstrict-prototypes \
                    -Wsign-compare \
                    -Wdouble-promotion \
                    -Wunknown-pragmas \
                    -Wundef \
                    -Wextra \
                    -Wall \
                    -pedantic \
                    -Werror=implicit-function-declaration \
                    -fno-common \
                    -fno-signed-char \
                    -fno-trigraphs

CCOPT           := $(CCOPT) \
                    -I$(cinc) \
                    -I$(cinc_llvm)

LDOPT           := $(LDOPT_CORE) \
                    -e Reset_Handler \
                    -m30 \
                    -Xstack-usage \
                    -Xpreprocess-lecl \
                    -Xremove-unused-sections \
                    -L$(clib) \
                    -lc \
                    -lm \
                    $(LINKER_DEF) >"$(MAPFILE)"

ASOPT           :=  $(ASOPT_CORE) \
                    -DOSDIABARM \
                    -c \
                    -mthumb \
                    -Xpreprocess-assembly \
                    -Xassembly-listing

OTOPT :=    -O binary
