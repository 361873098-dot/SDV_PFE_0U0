/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*
* Target device: This linker is demo and it is using for device S32G2XX only
* Target core: This linker target application which is running on any M7 cores.
* Linker support for application running on single/multicore M7 by single image file. It need to align with MPU default setup in system.c as well.
*/

/*
* GHS Linker Command File:
* 0x20000000	0x2000FFFF	64KB	M7_0 M7 D-TCM
* 0x20100000	0x2010FFFF	64KB	M7_0 TCM Backdoor
* 0x20180000	0x2018FFFF	64KB	M7_1 TCM Backdoor
* 0x20200000	0x2020FFFF	64KB	M7_2 TCM Backdoor
* 0x24000000	0x33FFFFFF	262144	Standby RAM (32K) (Not supported on S32R45)
* The memory size used for common S32G3XX
* 0x34000000	0x34600000	6144KB	Internal SRAM
* Derivative: S32G234M
* 0x34000000	0x34800000	8192KB	Internal SRAM
* Derivative: S32G233A
* 0x34000000	0x34600000	6144KB	Internal SRAM
* Derivative: S32G254A, S32G274A
* 0x34000000	0x34800000	8192KB	Internal SRAM
* Derivative: S32R45
* 0x34000000	0x34800000	8192KB	Internal SRAM
*
* 0x43000000    0x43FFFFFF  16384KB LLCE Address Space (16M)
* Please note that current demo linker target only for S32G233A, in order to maximum benefit of ram usage, please modify linker and MPU default setting in system.c
*
*
*
*
*
*/
DEFAULTS
{
    int_results_reserve = 0x100
}

MEMORY
{
    int_itcm                : ORIGIN = 0x00000000, LENGTH = 0x00000000 /* 0KB - Not Supported */
    int_dtcm                : ORIGIN = 0x20000000, LENGTH = 0x0000E000 /* 64K */
    int_dtcm_stack          : ORIGIN = 0x2000E000, LENGTH = 0x00002000 /* 8K */
    int_sram_shareable      : ORIGIN = 0x22C00000, LENGTH = 0x00004000 /* 16KB */
    IPCFsharedRAM (RW)      : ORIGIN = 0x34100000, LENGTH = 0x00200000 /* 2MB */
    int_sram                : ORIGIN = 0x34300000, LENGTH = 0x00200000 /* 2MB */
    int_sram_no_cacheable   : ORIGIN = 0x34500000, LENGTH = 0x00100000 /* 1MB, needs to include int_results  */
    ram_rsvd2               : ORIGIN = 0x34600000, LENGTH = 0          /* End of SRAM */

    LLCE_CAN_SHAREDMEMORY   : ORIGIN = 0x43800000 LENGTH = 0x3C800
    LLCE_LIN_SHAREDMEMORY   : ORIGIN = 0x4383C800 LENGTH = 0xa0
    LLCE_BOOT_END           : ORIGIN = 0x4383C8A0 LENGTH = 0x50
    LLCE_MEAS_SHAREDMEMORY  : ORIGIN = 0x4384FFDF LENGTH = 0x20
}


SECTIONS
{
    .core_loop                                   ALIGN(4)     : > int_sram
    .startup                                     ALIGN(4)     : > . /* Reset code*/
    .text.startup                                ALIGN(4)     : > .
    .text                                        ALIGN(4)     : > .
    .mcal_text                                   ALIGN(4)     : > .

    .rodata                                     ALIGN(4)      : > .
    .mcal_const_cfg                             ALIGN(4)      : > .
    .mcal_const                                 ALIGN(4)      : > .
    .init_table                                 ALIGN(4)      : > .
    .zero_table                                 ALIGN(4)      : > .

    .acfls_code_rom                               ALIGN(4)     : > .
    .aceep_code_rom                               ALIGN(4)     : > .
    .acmcu_code_rom                               ALIGN(4)     : > .
    .ramcode                                 ABS  ALIGN(4)     : > .
    .data                                        ALIGN(4)      : > .
    .mcal_data                                   ALIGN(4)      : > .
    .bss                               (NOLOAD)  ALIGN(16)     : > .
    .mcal_bss                          (NOLOAD)  ALIGN(16)     : > .
    .ROM.mcal_shared_data ROM(.mcal_shared_data) ALIGN(4)      : > .
    .ROM.dtcm_data               ROM(.dtcm_data) ALIGN(4)      : > .
    __ROM_DTCM_END = align(4);

    .int_results           ALIGN(4) PAD(int_results_reserve)  : > int_sram_no_cacheable
    .intc_vector                               ALIGN(1024)    : > .
    .mcal_bss_no_cacheable            (NOLOAD) ALIGN(16)      : > .
    .mcal_data_no_cacheable                    ALIGN(4)       : > .
    .mcal_const_no_cacheable                   ALIGN(4)       : > .
    .pfe_bmu_mem                       ALIGN(0x40000)         : > .
    .pfe_bd_mem                              ALIGN(4)         : > .
    .pfe_buf_mem                              ALIGN(4)        : > .

    .llce_boot_end                             ALIGN(4)       : > LLCE_BOOT_END
    .can_43_llce_sharedmemory                  ALIGN(4)       : > LLCE_CAN_SHAREDMEMORY
    .lin_43_llce_sharedmemory                  ALIGN(4)       : > LLCE_LIN_SHAREDMEMORY
    .llce_meas_sharedmemory                    ALIGN(4)       : > LLCE_MEAS_SHAREDMEMORY

    .mcal_shared_bss                  (NOLOAD) ALIGN(16)      : > int_sram_shareable
    .mcal_shared_data                          ALIGN(16)      : > .

    .intc_vector_dtcm             ALIGN(2048) PAD(SIZEOF(.intc_vector)) : > int_dtcm
    .dtcm_data                                 ALIGN(4)                 : > .
    .dtcm_bss                         (NOLOAD) ALIGN(4)                 : > .

    __Stack_dtcm_end              = ADDR(int_dtcm_stack);
    __Stack_dtcm_start            = ADDR(int_dtcm_stack) + SIZEOF(int_dtcm_stack);

    __INT_SRAM_START         = ADDR(int_sram);
    __INT_SRAM_END           = ADDR(ram_rsvd2);

    __INT_ITCM_START         = ADDR(int_itcm);
    __INT_ITCM_END           = ADDR(int_itcm) + SIZEOF(int_itcm);

    __INT_DTCM_START         = ADDR(int_dtcm);
    __INT_DTCM_END           = ADDR(int_dtcm) + SIZEOF(int_dtcm) + SIZEOF(int_dtcm_stack);

    __RAM_SHAREABLE_START    = ADDR(.mcal_shared_data);
    __RAM_SHAREABLE_END      = ADDR(.mcal_shared_data) + SIZEOF(.mcal_shared_data);
    __ROM_SHAREABLE_START    = ADDR(.ROM.mcal_shared_data);
    __ROM_SHAREABLE_END      = ADDR(.ROM.mcal_shared_data) + SIZEOF(.ROM.mcal_shared_data);
    __RAM_NO_CACHEABLE_START = ADDR(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_END   = ADDR(int_sram_no_cacheable) + SIZEOF(int_sram_no_cacheable);
    __ROM_NO_CACHEABLE_START = 0;
    __ROM_NO_CACHEABLE_END   = 0;
    __RAM_CACHEABLE_START    = ADDR(int_sram);
    __RAM_CACHEABLE_END      = ADDR(int_sram) + SIZEOF(int_sram) - 1;
    __ROM_CACHEABLE_START    = 0;
    __ROM_CACHEABLE_END      = 0;

    __BSS_SRAM_START         = ADDR(.bss);
    __BSS_SRAM_SIZE          = SIZEOF(.bss)+SIZEOF(.mcal_bss);
    __BSS_SRAM_END           = __BSS_SRAM_START + __BSS_SRAM_SIZE;

    __BSS_SRAM_NC_START      = ADDR(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_SIZE       = SIZEOF(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_END        = __BSS_SRAM_NC_START + __BSS_SRAM_NC_SIZE;

    __BSS_SRAM_SH_START      = ADDR(.mcal_shared_bss);
    __BSS_SRAM_SH_SIZE       = SIZEOF(.mcal_shared_bss);
    __BSS_SRAM_SH_END        = __BSS_SRAM_SH_START + __BSS_SRAM_SH_SIZE;

    __RAM_INTERRUPT_START    = ADDR(.intc_vector_dtcm);
    __INIT_INTERRUPT_START   = ADDR(.intc_vector);
    __INIT_INTERRUPT_END     = ADDR(.intc_vector) + SIZEOF(.intc_vector);

    __INIT_TABLE             = ADDR(.init_table);
    __ZERO_TABLE             = ADDR(.zero_table);

    __RAM_INIT               = 0;
    __ITCM_INIT              = 0;
    __DTCM_INIT              = 1;

    __RAM_DTCM_START         = ADDR(.dtcm_data);
    __ROM_DTCM_START         = ADDR(.ROM.dtcm_data);
   /* Discard boot header in RAM */
   /DISCARD/ : { *(.boot_header) }

    __INDEX_COPY_CORE2       = 3;    /* This symbol is used to initialize data of ITCM/DTCM for secondary cores */
}
