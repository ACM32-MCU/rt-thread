/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-25     AisinoChip   first implementation
 */

#include <rthw.h>
#include <rtthread.h>
#include "board.h"
#include <rtdevice.h>

#define SOC_SRAM_END_ADDR   (SOC_SRAM_START_ADDR+SOC_SRAM_SIZE)

extern int  rt_application_init(void);

#if defined(__ARMCC_VERSION)
    extern int Image$$RW_IRAM1$$ZI$$Limit;
#elif __ICCARM__
    #pragma section="HEAP"
#else
    extern int __bss_end;
#endif

extern void rt_hw_uart_init(void);


/**
 * This function will initial EVB board.
 */
void rt_hw_board_init(void)
{
    /* Configure the SysTick */
    SysTick_Config(HAL_RCC_GetFCLKFreq() / RT_TICK_PER_SECOND);

    rt_hw_uart_init();
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);

#ifdef RT_USING_HEAP
#if defined(__ARMCC_VERSION)
    rt_system_heap_init((void *)&Image$$RW_IRAM1$$ZI$$Limit, (void *)SOC_SRAM_END_ADDR);
#elif __ICCARM__
    rt_system_heap_init(__segment_end("HEAP"), (void *)SOC_SRAM_END_ADDR);
#else
    /* init memory system */
    rt_system_heap_init((void *)&__bss_end, (void *)SOC_SRAM_END_ADDR);
#endif
#endif /* RT_USING_HEAP */

#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
}

void assert_failed(uint8_t* file, uint32_t line)
{ 
    rt_kprintf("error in file[%s : %d]\n", file, line);
    while (1);
}
