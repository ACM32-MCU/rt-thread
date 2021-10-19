/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-05     AisinoChip   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <hw_crc.h>

#if defined(BSP_USING_CRC)

static int crc_sample(int argc, char *argv[])
{
    struct rt_hwcrypto_ctx *ctx;
    struct hwcrypto_crc_cfg cfg;
    rt_uint32_t result;

    if(argc < 7)
    {
        rt_kprintf("usage :crc sample:crc_sample init poly width outxor flags data...\r\n");
        return -1;
    }

    ctx = rt_hwcrypto_crc_create(rt_hwcrypto_dev_default(), HWCRYPTO_CRC_CUSTOM);
    if(ctx == RT_NULL)
    {
        rt_kprintf("rt_hwcrypto_crc_create failed\n");
        return -1;
    }

    cfg.last_val = atoi(argv[1]);
    cfg.poly = atoi(argv[2]);
    cfg.width = atoi(argv[3]);
    cfg.xorout = atoi(argv[4]);
    cfg.flags = atoi(argv[5]);

    rt_hwcrypto_crc_cfg(ctx, &cfg);

    for(int i = 0; i< argc - 6; i++)
    {
        result = rt_hwcrypto_crc_update(ctx, (const rt_uint8_t*)argv[6+i], rt_strlen(argv[6+i]));
        rt_kprintf("%08X\n", result);
    }

    rt_hwcrypto_crc_destroy(ctx);

    return 0;
}
MSH_CMD_EXPORT(crc_sample, crc sample:crc_sample init poly width outxor flags data ...);
#endif /* defined(BSP_USING_CRC) */

