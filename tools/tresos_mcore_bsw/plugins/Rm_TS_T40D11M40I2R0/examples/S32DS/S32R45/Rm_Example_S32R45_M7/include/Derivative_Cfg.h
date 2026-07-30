#ifndef __DERIVATIVE_CFG_H__
#define __DERIVATIVE_CFG_H__

#include "S32R45_SIUL2.h"
#include "S32R45_SCB.h"

#define FULL_ACCESS_PERIPHERAL      0x40100000u        /* SWT_0 */
#define NO_ACCESS_PERIPHERAL        0x40104000u        /* SWT_1 */

#define IP_XRDC_INSTANCE_NAME       IP_XRDC_0
#define IP_XRDC_INSTANCE_ID         (0U)
#define T_HF_VECTOR_OFFSET          (3U)

#endif    /* __DERIVATIVE_CFG_H__ */
