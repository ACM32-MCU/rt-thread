/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-18     Aisinochip   first version
 */

#ifndef __PWM_CONFIG_H__
#define __PWM_CONFIG_H__

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BSP_USING_PWM1
#ifndef PWM1_CONFIG
#define PWM1_CONFIG                             \
    {                                           \
       .tim_handle.Instance     = TIM1,         \
       .name                    = "pwm1",       \
       .channel                 = 0             \
    }
#endif /* PWM1_CONFIG */
#endif /* BSP_USING_PWM1 */

#ifdef BSP_USING_PWM2
#ifndef PWM2_CONFIG
#define PWM2_CONFIG                             \
    {                                           \
       .tim_handle.Instance     = TIM2,         \
       .name                    = "pwm2",       \
       .channel                 = 0             \
    }
#endif /* PWM2_CONFIG */
#endif /* BSP_USING_PWM2 */

#ifdef BSP_USING_PWM3
#ifndef PWM3_CONFIG
#define PWM3_CONFIG                             \
    {                                           \
       .tim_handle.Instance     = TIM3,         \
       .name                    = "pwm3",       \
       .channel                 = 0             \
    }
#endif /* PWM3_CONFIG */
#endif /* BSP_USING_PWM3 */

#ifdef BSP_USING_PWM4
#ifndef PWM4_CONFIG
#define PWM4_CONFIG                             \
    {                                           \
       .tim_handle.Instance     = TIM4,         \
       .name                    = "pwm4",       \
       .channel                 = 0             \
    }
#endif /* PWM4_CONFIG */
#endif /* BSP_USING_PWM4 */

#ifdef BSP_USING_PWM14
#ifndef PWM14_CONFIG
#define PWM14_CONFIG                             \
    {                                           \
       .tim_handle.Instance     = TIM14,         \
       .name                    = "pwm14",       \
       .channel                 = 0             \
    }
#endif /* PWM14_CONFIG */
#endif /* BSP_USING_PWM14 */

#ifdef BSP_USING_PWM15
#ifndef PWM15_CONFIG
#define PWM15_CONFIG                             \
    {                                           \
       .tim_handle.Instance     = TIM15,         \
       .name                    = "pwm15",       \
       .channel                 = 0             \
    }
#endif /* PWM15_CONFIG */
#endif /* BSP_USING_PWM15 */

#ifdef BSP_USING_PWM16
#ifndef PWM16_CONFIG
#define PWM16_CONFIG                            \
    {                                           \
       .tim_handle.Instance     = TIM16,        \
       .name                    = "pwm16",      \
       .channel                 = 0             \
    }
#endif /* PWM16_CONFIG */
#endif /* BSP_USING_PWM16 */

#ifdef BSP_USING_PWM17
#ifndef PWM17_CONFIG
#define PWM17_CONFIG                            \
    {                                           \
       .tim_handle.Instance     = TIM17,        \
       .name                    = "pwm17",      \
       .channel                 = 0             \
    }
#endif /* PWM17_CONFIG */
#endif /* BSP_USING_PWM17 */

#ifdef __cplusplus
}
#endif

#endif /* __PWM_CONFIG_H__ */
