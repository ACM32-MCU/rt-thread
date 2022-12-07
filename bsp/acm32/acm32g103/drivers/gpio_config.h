/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-25     AisinoChip   the first version
 */

#ifndef __GPIO_CONFIG_H__
#define __GPIO_CONFIG_H__

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SOC_PACKAGE_QFN32
#elif defined(SOC_PACKAGE_LQFP48)
#elif defined(SOC_PACKAGE_LQFP64)
    /*
     * pin index                pin name
        1	VDD
        2	PF0
        3	PF1
        4	NRST
        5	VDDA
        6	PA0
        7	PA1
        8	PA2
        9	PA3
        10	PA4
        11	PA5
        12	PA6
        13	PA7
        14	PB0
        15	PB1
        16	VDD
        17	PA8
        18	PA9
        19	PA10
        20	PA11
        21	PA12
        22	PA13
        23	VDD
        24	PA14
        25	PA15
        26	PB3
        27	PB4
        28	PB5
        29	PB6
        30	PB7
        31	PF3
        32	VSS
        *
     * */
#elif defined(SOC_PACKAGE_LQFP100)
#else
#error soc package error
#endif

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_CONFIG_H__ */

#define UARTX_TX(x)  UART#x#_TX

drv_gpio_set(name, func)

