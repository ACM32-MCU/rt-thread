/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2022-10-25     AisinoChip        first version
 */

#include <rthw.h>
#include <rtdevice.h>
#include "board.h"
#include <rtdbg.h>

#ifdef RT_USING_PIN
#define MAX_PIN_IRQ 16

struct pin_isr
{
    GPIO_TypeDef* port;
    rt_uint32_t mode;
    rt_uint32_t pin;
    void (*isr_cb)(void *args);
    void* isr_args;
    rt_uint32_t enabled;
};

static struct pin_isr exti_isr_table[MAX_PIN_IRQ] = {0};

static void _pin_write(rt_device_t dev, rt_base_t index, rt_base_t value)
{
    GPIO_TypeDef* port = NULL;
    rt_uint32_t  pin = 0;

    port = drv_gpio_get_port(index);
    RT_ASSERT(port != RT_NULL);

    pin = drv_gpio_get_pin(index);
    RT_ASSERT(pin != 0);

    HAL_GPIO_WritePin(port, pin, value == PIN_HIGH ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static int _pin_read(rt_device_t dev, rt_base_t index)
{
    GPIO_TypeDef* port = NULL;
    rt_uint32_t  pin = 0;

    port = drv_gpio_get_port(index);
    RT_ASSERT(port != RT_NULL);

    pin = drv_gpio_get_pin(index);
    RT_ASSERT(pin != 0);

    return HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET ? PIN_HIGH : PIN_LOW;
}

static void _pin_mode(rt_device_t dev, rt_base_t index, rt_base_t mode)
{
    GPIO_TypeDef* port = NULL;
    rt_uint32_t  pin;
    rt_uint32_t pull;
    rt_uint32_t hal_mode;

    port = drv_gpio_get_port(index);
    RT_ASSERT(port != RT_NULL);

    pin = drv_gpio_get_pin(index);
    RT_ASSERT(pin != 0);

    switch(mode)
    {
    case PIN_MODE_OUTPUT:
        /* output setting */
        hal_mode = GPIO_MODE_OUTPUT_PP;
        pull = GPIO_NOPULL;
        break;

    case PIN_MODE_INPUT:
        /* input setting: not pull. */
        hal_mode = GPIO_MODE_INPUT;
        pull = GPIO_NOPULL;
        break;

    case PIN_MODE_INPUT_PULLUP:
        /* input setting: pull up. */
        hal_mode = GPIO_MODE_INPUT;
        pull = GPIO_PULLUP;
        break;

    case PIN_MODE_INPUT_PULLDOWN:
        /* input setting: pull down. */
        hal_mode = GPIO_MODE_INPUT;
        pull = GPIO_PULLDOWN;
        break;

    case PIN_MODE_OUTPUT_OD:
        /* output setting: od. */
        hal_mode = GPIO_MODE_OUTPUT_OD;
        pull = GPIO_NOPULL;
        break;

    default:
        return;
    }

    drv_gpio_init(port, pin, hal_mode, pull, GPIO_FUNCTION_0);
}

static rt_err_t _pin_attach_irq(struct rt_device *device, rt_int32_t pin,
                                     rt_uint32_t mode, void (*hdr)(void *args), void *args)
{
    GPIO_TypeDef* port = NULL;
    rt_uint32_t  line = 0;
    rt_uint32_t hal_mode;
    rt_uint32_t slot = 0;

    port = drv_gpio_get_port(pin);
    if(port == RT_NULL)
    {
        return -RT_EINVAL;
    }

    line = drv_gpio_get_pin(pin);
    if(line == 0)
    {
        return -RT_EINVAL;
    }

    if(hdr == RT_NULL)
    {
        return -RT_EINVAL;
    }

    switch(mode)
    {
    case PIN_IRQ_MODE_RISING:
        hal_mode = GPIO_MODE_IT_RISING;
        break;
    case PIN_IRQ_MODE_FALLING:
        hal_mode = GPIO_MODE_IT_FALLING;
        break;
    case PIN_IRQ_MODE_RISING_FALLING:
        hal_mode = GPIO_MODE_IT_RISING_FALLING;
        break;
    case PIN_IRQ_MODE_HIGH_LEVEL:
    case PIN_IRQ_MODE_LOW_LEVEL:
    default:
        return -RT_EINVAL;
    }

    slot = __rt_ffs(line) - 1;

    if(exti_isr_table[slot].enabled == PIN_IRQ_ENABLE)
    {
        return -RT_EFULL;
    }

    exti_isr_table[slot].port = port;
    exti_isr_table[slot].pin= line;
    exti_isr_table[slot].mode = hal_mode;
    exti_isr_table[slot].isr_cb = hdr;
    exti_isr_table[slot].isr_args = args;
    exti_isr_table[slot].enabled = PIN_IRQ_DISABLE;

    return RT_EOK;
}

static rt_err_t _pin_dettach_irq(struct rt_device *device, rt_int32_t index)
{
    GPIO_TypeDef* port = NULL;
    rt_uint32_t  pin = 0;
    rt_uint32_t hal_mode;
    rt_uint32_t slot;

    port = drv_gpio_get_port(index);
    if(port == RT_NULL)
    {
        return -RT_EINVAL;
    }

    pin = drv_gpio_get_pin(index);
    if(pin == 0)
    {
        return -RT_EINVAL;
    }

    slot = __rt_ffs(pin) - 1;
    if(exti_isr_table[slot].enabled != PIN_IRQ_DISABLE)
    {
        return -RT_EFULL;
    }

    exti_isr_table[slot].port = RT_NULL;
    exti_isr_table[slot].enabled = PIN_IRQ_DISABLE;
    exti_isr_table[slot].pin = 0;
    exti_isr_table[slot].mode = 0;
    exti_isr_table[slot].isr_cb = 0;
    exti_isr_table[slot].isr_args = 0;

    return RT_EOK;
}

static rt_err_t _pin_irq_enable(struct rt_device *device, rt_base_t index,
                                     rt_uint32_t enabled)
{
    GPIO_TypeDef* port = NULL;
    rt_uint32_t  pin = 0;
    rt_uint32_t alternate;
    rt_uint32_t slot;
    IRQn_Type   irq;

    port = drv_gpio_get_port(index);
    if(port == RT_NULL)
    {
        return -RT_EINVAL;
    }

    pin = drv_gpio_get_pin(index);
    if(pin == 0)
    {
        return -RT_EINVAL;
    }

    if(PIN_IRQ_DISABLE != enabled && PIN_IRQ_ENABLE != enabled)
    {
        return -RT_EINVAL;
    }

    slot = __rt_ffs(pin) - 1;

    if(exti_isr_table[slot].port != port || exti_isr_table[slot].pin != pin)
    {
        return -RT_EINVAL;
    }

    if(exti_isr_table[slot].enabled == enabled)
    {
        return RT_EOK;
    }

    switch(exti_isr_table[slot].mode)
    {
    case GPIO_MODE_IT_FALLING:
        alternate = GPIO_PULLUP;
        break;
    case GPIO_MODE_IT_RISING:
        alternate = GPIO_PULLDOWN;
        break;
    case GPIO_MODE_IT_RISING_FALLING:
        alternate = GPIO_NOPULL;
        break;
    }

    drv_gpio_init(port, pin, exti_isr_table[slot].mode, alternate, GPIO_FUNCTION_0);

    switch(slot)
    {
    case 0:
        irq = EXTI0_IRQn;
        break;
    case 1:
        irq = EXTI1_IRQn;
        break;
    case 2:
        irq = EXTI2_IRQn;
        break;
    case 3:
        irq = EXTI3_IRQn;
        break;
    case 4:
        irq = EXTI4_IRQn;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        irq = EXTI9_5_IRQn;
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        irq = EXTI15_10_IRQn;
        break;
    default:
        return -RT_ERROR;
    }

    if(enabled == PIN_IRQ_ENABLE)
    {
        __HAL_RCC_EXTI_CLK_ENABLE();
        HAL_EXTI_ClearPending(pin);
        NVIC_ClearPendingIRQ(irq);

        NVIC_SetPriority(irq, 0x00);
        NVIC_EnableIRQ(irq);
        exti_isr_table[slot].enabled = PIN_IRQ_ENABLE;
    }
    else
    {
        HAL_EXTI_ClearPending(pin);
        NVIC_ClearPendingIRQ(irq);

        NVIC_SetPriority(irq, 0x00);
        NVIC_DisableIRQ(irq);
        exti_isr_table[slot].enabled = PIN_IRQ_DISABLE;
    }

    return RT_EOK;
}


static rt_base_t _pin_get(const char *name)
{
    RT_ASSERT(name != RT_NULL);
    return drv_gpio_get_index(name);
}

const static struct rt_pin_ops _acm32_pin_ops =
{
    _pin_mode,
    _pin_write,
    _pin_read,
    _pin_attach_irq,
    _pin_dettach_irq,
    _pin_irq_enable,
    _pin_get,
};

int rt_hw_pin_init(void)
{
    return rt_device_pin_register("pin", &_acm32_pin_ops, RT_NULL);
}
INIT_BOARD_EXPORT(rt_hw_pin_init);

static void exti_isr(rt_uint32_t line)
{
    rt_uint32_t slot = __rt_ffs(line) - 1;

    if (EXTI->PDR & line)
    {
        if (exti_isr_table[slot].enabled == PIN_IRQ_ENABLE)
        {
            exti_isr_table[slot].isr_cb(exti_isr_table[slot].isr_args);
        }
        EXTI->PDR = line;
    }
}

void EXTI0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_0);

    /* leave interrupt */
    rt_interrupt_leave();
}

void EXTI1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_1);

    /* leave interrupt */
    rt_interrupt_leave();
}

void EXTI2_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_2);

    /* leave interrupt */
    rt_interrupt_leave();
}

void EXTI3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_3);

    /* leave interrupt */
    rt_interrupt_leave();
}

void EXTI4_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_4);

    /* leave interrupt */
    rt_interrupt_leave();
}

void EXTI9_5_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_5);
    exti_isr(GPIO_PIN_6);
    exti_isr(GPIO_PIN_7);
    exti_isr(GPIO_PIN_8);
    exti_isr(GPIO_PIN_9);

    /* leave interrupt */
    rt_interrupt_leave();
}

void EXTI15_10_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* exti isr routine */
    exti_isr(GPIO_PIN_10);
    exti_isr(GPIO_PIN_11);
    exti_isr(GPIO_PIN_12);
    exti_isr(GPIO_PIN_13);
    exti_isr(GPIO_PIN_14);
    exti_isr(GPIO_PIN_15);

    /* leave interrupt */
    rt_interrupt_leave();
}

#endif /* RT_USING_PIN */

