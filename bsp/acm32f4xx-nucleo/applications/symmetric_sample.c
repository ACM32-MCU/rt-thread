/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-04     AisinoChip   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <hw_symmetric.h>

#if defined(BSP_USING_AES)
static int symm_sample(int argc, char *argv[])
{
    struct rt_hwcrypto_ctx *ctx;
    rt_uint32_t type,mode,idx;
    rt_err_t rc = RT_EOK;
    rt_uint8_t out[256] = {0};

    if(argc < 5)
    {
        rt_kprintf("usage : symmetric_sample type operate key [iv] data \r\n");
        return -1;
    }

    idx = 1;
    type = atoi(argv[idx++]);
    mode = atoi(argv[idx++]);

    ctx = rt_hwcrypto_symmetric_create(rt_hwcrypto_dev_default(), type);
    if(ctx == RT_NULL)
    {
        rt_kprintf("rt_hwcrypto_symmetric_create failed\n");
        return -1;
    }

    do
    {
        rc = rt_hwcrypto_symmetric_setkey(ctx, (rt_uint8_t*)argv[idx], rt_strlen(argv[idx])<<3);
        idx ++;
        if(rc != RT_EOK)
        {
            rt_kprintf("rt_hwcrypto_symmetric_setkey failed\n");
            break;
        }

        if(type&((0x02 << 8)))
        {
            rc = rt_hwcrypto_symmetric_setiv(ctx, (rt_uint8_t*)argv[idx], rt_strlen(argv[idx]));
            idx++;
            if(rc != RT_EOK)
            {
                rt_kprintf("rt_hwcrypto_symmetric_setiv failed\n");
                break;
            }
        }

        rc = rt_hwcrypto_symmetric_crypt(ctx, mode, rt_strlen(argv[idx]), (rt_uint8_t*)argv[idx], out);
        if(rc != RT_EOK)
        {
            rt_kprintf("rt_hwcrypto_symmetric_crypt failed\n");
            break;
        }
        rt_kprintf("out : ");
        for(int i = 0 ;i < rt_strlen(argv[idx]); i++)
            rt_kprintf("%02X ", out[i]);
        rt_kprintf("\n");

    } while(0);

    rt_hwcrypto_hash_destroy(ctx);

    return 0;
}
MSH_CMD_EXPORT(symm_sample, symmetric sample:symm_sample type operate key [iv] data);
#endif /* defined(BSP_USING_AES) */

