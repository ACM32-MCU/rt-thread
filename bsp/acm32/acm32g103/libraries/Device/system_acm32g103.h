
/******************************************************************************
*@file  : system-acm32g103.h
*@brief : CMSIS Cortex-M33 Device Peripheral Access Layer System Source File
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#ifndef __SYSTEM_ACM32G103_H
#define __SYSTEM_ACM32G103_H

#include "acm32g103_hal_conf.h"
    
/******************************************************************************
*@note  : g_SystemCoreClock variable is updated in three ways:
*           1) by calling CMSIS function SystemCoreClockUpdate()
*           2) by calling HAL API function HAL_RCC_GetSysClkFreq()
*           3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency 
*               If you use this function to configure the system clock; then there
*               is no need to call the 2 first functions listed above, since g_SystemCoreClock
*               variable is updated automatically.
******************************************************************************/
extern uint32_t g_SystemCoreClock; /*!< System Clock Frequency (Core Clock) */

void SystemInit(void);
void SystemCoreClockUpdate(void);
void SystemClock_Config(void);

#endif /* __SYSTEM_ACM32G103_H */
