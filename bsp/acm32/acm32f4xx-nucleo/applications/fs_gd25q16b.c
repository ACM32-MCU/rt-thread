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
#include <dfs.h>
#include <dfs_elm.h>
#include <dfs_fs.h>
#include <spi_flash_sfud.h>
#include "board.h"
#ifdef RT_USING_FAL
#include <fal.h>
#endif

#define FLASH_DEVICE_NAME       "spi30"
#define FLASH_NAME              "gd25q16b"
#define FS_PARTITION_NAME       "norflash"
extern rt_err_t rt_hw_spi_device_attach(const char *bus_name, const char *device_name, enum_GPIOx_t cs_gpiox, uint16_t cs_gpio_pin);

int rt_spi_opt_gd25q16b_init(void)
{
    rt_hw_spi_device_attach("spi3", FLASH_DEVICE_NAME, GPIOA, GPIO_PIN_15);

    if(rt_sfud_flash_probe(FLASH_NAME, FLASH_DEVICE_NAME))
    {
#ifdef RT_USING_FAL
        fal_init();

        struct rt_device *flash_dev = (struct rt_device *)fal_blk_device_create(FS_PARTITION_NAME);
        if (flash_dev == NULL)
        {
            rt_kprintf("Can't create a block device on '%s' partition.\n", FS_PARTITION_NAME);
            return -1;
        }
#endif
        return RT_EOK;
    }
    else
    {
        return -RT_ERROR;
    }
}

int dfs_mount_init(void)
{
    rt_spi_opt_gd25q16b_init();

//    if(0 != dfs_mkfs("elm", FS_PARTITION_NAME))
//    {
//        rt_kprintf("dfs_mkfs failed\n");
//        return -1;
//    }

//    if(dfs_mount(FS_PARTITION_NAME, "/", "elm",0,0) == 0)
//    {
//        rt_kprintf("dfs_mount success\n");
//        return RT_EOK;
//    }
//    else
//    {
//        rt_kprintf("dfs_mount failed\n");
//        return -RT_ERROR;
//    }
    return RT_EOK;
}
INIT_ENV_EXPORT(dfs_mount_init);

