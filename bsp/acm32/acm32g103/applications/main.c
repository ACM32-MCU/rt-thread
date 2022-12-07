/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-09-17     AisinoChip   the first version
 */

#include <rthw.h>
#include <rtthread.h>
#include "board.h"
#include <drivers/pin.h>

#define LED_PIN_NAME        "PF.3"
#define PB_PIN_NAME         "PC.13"

void cb_pb_click(void* args)
{
    rt_kprintf("button pressed\n");
}

int main(void)
{
    rt_base_t led_num = rt_pin_get(LED_PIN_NAME);
    rt_pin_mode(led_num, PIN_MODE_OUTPUT);

    rt_base_t pb_num = rt_pin_get(PB_PIN_NAME);
    rt_pin_attach_irq(pb_num, PIN_IRQ_MODE_FALLING, cb_pb_click, RT_NULL);
    rt_pin_irq_enable(pb_num, PIN_IRQ_ENABLE);

    while (1)
    {
        rt_pin_write(led_num, PIN_LOW);
        rt_thread_delay(RT_TICK_PER_SECOND / 2);
        rt_pin_write(led_num, PIN_HIGH);
        rt_thread_delay(RT_TICK_PER_SECOND / 2);
    }
}

