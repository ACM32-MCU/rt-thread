/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-08     AisinoChip   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <stdlib.h>

rt_device_t dev = RT_NULL;
static struct rt_semaphore rx_sem;

static rt_err_t uart_input(rt_device_t dev, rt_size_t size)
{
    rt_sem_release(&rx_sem);
    return RT_EOK;
}

static int vcom_sample(int argc, char *argv[])
{
    rt_device_t dev = RT_NULL;
    char buf[256];

    dev = rt_device_find("vcom");

    if (dev)
        rt_device_open(dev, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    else
    {
        rt_kprintf("open vcom failed\n");
        return -RT_ERROR;
    }
    rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);
    rt_device_set_rx_indicate(dev, uart_input);

    while (1)
    {
        rt_size_t size = rt_device_read(dev, -1, buf, 256) ;
        if (size == 0)
        {
            rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
        }
        else
        {
            rt_device_write(dev, 0, buf, size);
        }
    }

    return RT_EOK;
}
MSH_CMD_EXPORT(vcom_sample, vcom sample: vcom_sample);
