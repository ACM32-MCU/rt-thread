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
#include <hw_rng.h>

#if defined(RT_HWCRYPTO_USING_RNG) && defined(BSP_USING_HRNG)

static int hrng_sample(int argc, char *argv[])
{
    rt_uint32_t result=0;
    int i, num0=0, num1 =0;
    const int max_test = 1000 * 10000;

    for (i = 0; i < max_test; i++)
    {
        result = rt_hwcrypto_rng_update();
        result%2 ? num1++ : num0++;
    }
    rt_kprintf(" num1: %d, num0: %d ",num1, num0);

    return 0;
}
MSH_CMD_EXPORT(hrng_sample, hrng sample:hrng_sample);
#endif /* defined(RT_HWCRYPTO_USING_RNG) && defined(BSP_USING_HRNG) */
