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
#include <hw_hash.h>

#if defined(BSP_USING_SHA1) || defined(BSP_USING_SHA256)

static int hash_sample(int argc, char *argv[])
{
    struct rt_hwcrypto_ctx *ctx;
    rt_uint32_t type;
    rt_err_t rc = RT_EOK;
    rt_uint8_t digest[32] = {0};

    if(argc < 3)
    {
        rt_kprintf("usage : sha1_sample type msg1, msg2, msg...\r\n");
        return -1;
    }

    type = atoi(argv[1]);

    ctx = rt_hwcrypto_hash_create(rt_hwcrypto_dev_default(), type);
    if(ctx == RT_NULL)
    {
        rt_kprintf("rt_hwcrypto_hash_create failed\n");
        return -1;
    }

    do
    {
        rt_bool_t succ = RT_TRUE;
        for(int i = 0; i< argc - 2; i++)
        {
            rc = rt_hwcrypto_hash_update(ctx, (const rt_uint8_t*)argv[2+i], rt_strlen(argv[2+i]));
            if(rc != RT_EOK)
            {
                succ = RT_FALSE;
                rt_kprintf("rt_hwcrypto_hash_update failed\n");
                break;
            }
        }

        if(RT_TRUE != succ)
        {
            break;
        }

        rt_hwcrypto_hash_finish(ctx, digest, 32);
        if(rc != RT_EOK)
        {
            rt_kprintf("rt_hwcrypto_hash_finish failed\n");
            break;
        }

        rt_kprintf("digest : ");
        for(int i = 0; i<32;i++)
        {
            rt_kprintf("%02X ", digest[i]);
        }
        rt_kprintf("\n");

    } while(0);

    rt_hwcrypto_hash_destroy(ctx);

    return 0;
}
MSH_CMD_EXPORT(hash_sample, "hash sample:hash_sample type msg1, msg2, msg...");
#endif /* defined(BSP_USING_SHA1) && defined(BSP_USING_SHA256) */

