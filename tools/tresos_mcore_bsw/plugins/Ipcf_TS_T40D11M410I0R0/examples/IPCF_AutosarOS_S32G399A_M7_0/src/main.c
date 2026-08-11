/**
 * IPC Shared Memory Driver sample application
 *
 * Copyright 2023 NXP
 * All Rights Reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 *
 */
#if defined(__cplusplus)
extern "C"{
#endif

#include "CDD_Rm.h"
#include <Os.h>

/**
 * main() - starts OS
 */
int main(void)
{

	/* Initialize RM CDD */
	Rm_Init(NULL_PTR);

	StartOS(Mode01); /* jump to OS startup */

	return 0;
}

#if defined(__cplusplus)
}
#endif
