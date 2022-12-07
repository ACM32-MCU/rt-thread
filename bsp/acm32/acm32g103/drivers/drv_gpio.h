/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2021-09-18     AisinoChip        first version
 */

#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__
#include "board.h"
rt_bool_t drv_gpio_init(GPIO_TypeDef *gpiox, rt_uint32_t pin, rt_uint32_t mode,
        rt_uint32_t pull, rt_uint32_t alternate);
GPIO_TypeDef* drv_gpio_get_port(rt_uint32_t index);
rt_uint32_t drv_gpio_get_pin(rt_uint32_t index);
rt_base_t drv_gpio_get_index(const char* name);
rt_bool_t drv_gpio_init_by_name(const char* name, rt_uint32_t mode,
                        rt_uint32_t pull, rt_uint32_t alternate);
#endif
