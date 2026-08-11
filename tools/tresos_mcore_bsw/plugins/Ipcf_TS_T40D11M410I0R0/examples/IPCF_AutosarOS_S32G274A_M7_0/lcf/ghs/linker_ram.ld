/**************************************************************************************
*
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2011 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 - 2018,2023 NXP
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation
*      thereof.
*
*  Description:  GHS linker command file for AUTOSAR OS sample application
*
**************************************************************************************/
MEMORY
{
    IPCFsharedRAM : org = 0x34100000, len = 0x00200000
    OsInternalRAM :   org = 0x34300000, len = 0x20000    /* 128K should be enough for sample */
}


SECTIONS
{

     /* Interrupt vectors table */
    .vector                         : > OsInternalRAM



    .startup                        : > . /* reset code */
    .systeminit                     : > . /* SystemInit */
    .text.startup                   : > .

    /* Code and constant area (all code and constant sections shall be placed between .osbegincode and .osendcode sections). */
    .osbegincode  ALIGN(0x20)       : > .
    .ostext                         : > .
    .oshook                         : > .
    .osrodata                       : > .
    .syscall                        : > .
    .secinfo                        : > .
    .rodata                         : > .



    .ossrodata                      : > .
    .sapp_c32                       : > .
    .sapp_c16                       : > .
    .sapp_cU                        : > .
    .sapp_c8                        : > .


    .text                           : > .
    .appcode                        : > .
    .ROM.data                       : > .
    .osendcode                      : > . /* for mem protection only */

    /* ------------------------------------ OS stack area ------------------------------------ */
    .osstack      ALIGN(0x20)       : > . /* only one mem this time, OsInternalRAM2 */
    .osstack2     ALIGN(0x20)       : > .

    OS_NONCACHE_BSS_START           = . ;
    .osbeginnoncache ALIGN(0x20)    : > .
    .osnoncacheablebss CLEAR        : > . /* this section shall be cleared */
    /* user may place own noncachebale bss section here */
    .osendnoncache ALIGN(0x20)      : > .
    OS_NONCACHE_BSS_END             = . ;


    /* ------------------------------------ OS application data ------------------------------------ */
/* Begin of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area #1 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area #1 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area #2 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area #2 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GHS */

    /* -------------------------------------- Default data/bss --------------------------------- */
    .data                           : > .
    .osdata                         : > . /* it is empty */
    .ossdata                        : > .

    . = ALIGN(0x20);
    .sapp_v32_data                  : > .
    .sapp_v16_data                  : > .
    .sapp_vU_data                   : > .
    .sapp_v8_data                   : > .

    /* ------------------------------------ BSS sections ------------------------------------ */
    _bss_start = .;

    .osbss  ALIGN(1K)   CLEAR         : > .
    .ossbss                           : > .

    .bss    ALIGN(0x20) CLEAR         : > .
    .sbss                             : > .

    .sapp_v32_bss ALIGN(0x20) CLEAR   : > .
    .sapp_v16_bss       CLEAR       : > .
    .sapp_vU_bss        CLEAR       : > .
    .sapp_v8_bss        CLEAR       : > .


    _bss_end = .;

    /* ------------------------------------ main stacks section ------------------------------------ */

    .stack_main  ALIGN(16)          : > .
    .stack2_main  ALIGN(16)         : > .

    _Stack_end    = addr(.stack_main);
    _Stack_start  = addr(.stack_main)+sizeof(.stack_main);

    _Stack2_end   = addr(.stack2_main);
    _Stack2_start = addr(.stack2_main)+sizeof(.stack2_main);

    OS_MAIN_STACK_MIN  = _Stack_end;
    OS_MAIN_STACK_MAX  = _Stack_start;

    OS2_MAIN_STACK_MIN = _Stack2_end;
    OS2_MAIN_STACK_MAX = _Stack2_start;

}

