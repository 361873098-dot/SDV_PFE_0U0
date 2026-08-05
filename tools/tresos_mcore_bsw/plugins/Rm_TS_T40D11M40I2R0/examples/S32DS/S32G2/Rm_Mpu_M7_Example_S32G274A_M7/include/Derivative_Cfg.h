#ifndef __DERIVATIVE_CFG_H__
#define __DERIVATIVE_CFG_H__

#include "S32G274A_SCB.h"
#include "S32G274A_COMMON.h"

#define T_REGION                        (8U)
#define T_MEMMANAGE_VECTOR_OFFSET       (4U)
#define TEST_PERIPHERAL_ADDR            (0x40000000UL)
#define PERIPHERAL_ADDR                 (*(volatile uint32*)TEST_PERIPHERAL_ADDR)

#define PATTERN                         (0x5A5A5A5AUL)

#endif    /* __DERIVATIVE_CFG_H__ */
