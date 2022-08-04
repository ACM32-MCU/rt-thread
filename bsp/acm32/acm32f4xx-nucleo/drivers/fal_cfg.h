/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-8      zylx         first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtthread.h>
#include <board.h>

extern struct fal_flash_dev nor_flash0;
extern struct fal_flash_dev acm32_onchip_flash;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &acm32_onchip_flash,                                             \
    &nor_flash0,                                                     \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG

/* partition table */
#define FAL_PART_TABLE                                                                     \
{                                                                                          \
    {FAL_PART_MAGIC_WROD, "eflash",   "onchip_flash",               0,       256 * 1024,  0},  \
    {FAL_PART_MAGIC_WROD, "norflash", FAL_USING_NOR_FLASH_DEV_NAME, 0,   2 * 1024 * 1024, 0},  \
}
#endif /* FAL_PART_HAS_TABLE_CFG */
#endif /* _FAL_CFG_H_ */
