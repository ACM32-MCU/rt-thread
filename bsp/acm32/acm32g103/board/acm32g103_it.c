/******************************************************************************
*@file  : acm32g103_it.c
*@brief : Main Interrupt Service Routines
*           This file provides template for all exceptions handler and
*           peripherals interrupt service routine.
******************************************************************************/

#include "hal.h"
#include <rtthread.h>

void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();
    HAL_IncTick();

    /* leave interrupt */
    rt_interrupt_leave();
}