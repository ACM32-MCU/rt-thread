/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2021-09-18     AisinoChip        first version
 */

#include <rthw.h>
#include <rtdevice.h>
#include "board.h"

struct _pin_item
{
    rt_uint32_t index;
    char       *name;
};

#ifdef SOC_PACKAGE_QFN32
static const struct _pin_item pin_table[] =
{
    {1, "VDD"},
    {2, "PF0"},
    {3, "PF1"},
    {4, "NRST"},
    {5, "VDDA"},
    {6, "PA0"},
    {7, "PA1"},
    {8, "PA2"},
    {9, "PA3"},
    {10, "PA4"},
    {11, "PA5"},
    {12, "PA6"},
    {13, "PA7"},
    {14, "PB0"},
    {15, "PB1"},
    {16, "VDD"},
    {17, "PA8"},
    {18, "PA9"},
    {19, "PA10"},
    {20, "PA11"},
    {21, "PA12"},
    {22, "PA13"},
    {23, "VDD"},
    {24, "PA14"},
    {25, "PA15"},
    {26, "PB3"},
    {27, "PB4"},
    {28, "PB5"},
    {29, "PB6"},
    {30, "PB7"},
    {31, "PF3"},
    {32, "VSS"},
};
#elif defined(SOC_PACKAGE_LQFP48)
static const struct _pin_item pin_table[] =
{
    {48, "VDD"},
    {2, "PC13"},
    {3, "PC14"},
    {4, "PC15"},
    {5, "PF0"},
    {6, "PF1"},
    {7, "NRST"},
    {8, "VREFN"},
    {9, "VDDA"},
    {10, "PA0"},
    {11, "PA1"},
    {12, "PA2"},
    {13, "PA3"},
    {14, "PA4"},
    {15, "PA5"},
    {16, "PA6"},
    {17, "PA7"},
    {18, "PB0"},
    {19, "PB1"},
    {20, "PB2"},
    {21, "PB10"},
    {22, "PB11"},
    {23, "VSS"},
    {24, "VDD"},
    {25, "PB12"},
    {26, "PB13"},
    {27, "PB14"},
    {28, "PB15"},
    {29, "PA8"},
    {30, "PA9"},
    {31, "PA10"},
    {32, "PA11"},
    {33, "PA12"},
    {34, "PA13"},
    {35, "VSS"},
    {36, "VDD"},
    {37, "PA14"},
    {38, "PA15"},
    {39, "PB3"},
    {40, "PB4"},
    {41, "PB5"},
    {42, "PB6"},
    {43, "PB7"},
    {44, "PF3"},
    {45, "PB8"},
    {46, "PB9"},
    {47, "VSS"},
};
#elif defined(SOC_PACKAGE_LQFP64)
static const struct _pin_item pin_table[] =
{
    {64, "VDD"},
    {2, "PC13"},
    {3, "PC14"},
    {4, "PC15"},
    {5, "PF0"},
    {6, "PF1"},
    {7, "NRST"},
    {8, "PC0"},
    {9, "PC1"},
    {10, "PC2"},
    {11, "PC3"},
    {12, "VREFN"},
    {13, "VDDA"},
    {14, "PA0"},
    {15, "PA1"},
    {16, "PA2"},
    {17, "PA3"},
    {18, "VSS"},
    {19, "VDD"},
    {20, "PA4"},
    {21, "PA5"},
    {22, "PA6"},
    {23, "PA7"},
    {24, "PC4"},
    {25, "PC5"},
    {26, "PB0"},
    {27, "PB1"},
    {28, "PB2"},
    {29, "PB10"},
    {30, "PB11"},
    {31, "VSS"},
    {32, "VDD"},
    {33, "PB12"},
    {34, "PB13"},
    {35, "PB14"},
    {36, "PB15"},
    {37, "PC6"},
    {38, "PC7"},
    {39, "PC8"},
    {40, "PC9"},
    {41, "PA8"},
    {42, "PA9"},
    {43, "PA10"},
    {44, "PA11"},
    {45, "PA12"},
    {46, "PA13"},
    {47, "VSS"},
    {48, "VDD"},
    {49, "PA14"},
    {50, "PA15"},
    {51, "PC10"},
    {52, "PC11"},
    {53, "PC12"},
    {54, "PD2"},
    {55, "PB3"},
    {56, "PB4"},
    {57, "PB5"},
    {58, "PB6"},
    {59, "PB7"},
    {60, "PF3"},
    {61, "PB8"},
    {62, "PB9"},
    {63, "VSS"},

};
#elif defined(SOC_PACKAGE_LQFP100)
static const struct _pin_item pin_table[] =
{
    {100, "VDD"},
    {1, "PE2"},
    {2, "PE3"},
    {3, "PE4"},
    {4, "PE5"},
    {5, "PE6"},
    {6, "NC"},
    {7, "PC13"},
    {8, "PC14"},
    {9, "PC15"},
    {10, "VSS"},
    {11, "VDD"},
    {12, "PF0"},
    {13, "PF1"},
    {14, "NRST"},
    {15, "PC0"},
    {16, "PC1"},
    {17, "PC2"},
    {18, "PC3"},
    {19, "PF2"},
    {20, "VREFN"},
    {21, "VREFP"},
    {22, "VDDA"},
    {23, "PA0"},
    {24, "PA1"},
    {25, "PA2"},
    {26, "PA3"},
    {27, "VSS"},
    {28, "VDD"},
    {29, "PA4"},
    {30, "PA5"},
    {31, "PA6"},
    {32, "PA7"},
    {33, "PC4"},
    {34, "PC5"},
    {35, "PB0"},
    {36, "PB1"},
    {37, "PB2"},
    {38, "PE7"},
    {39, "PE8"},
    {40, "PE9"},
    {41, "PE10"},
    {42, "PE11"},
    {43, "PE12"},
    {44, "PE13"},
    {45, "PE14"},
    {46, "PE15"},
    {47, "PB10"},
    {48, "PB11"},
    {49, "VSS"},
    {50, "VDD"},
    {51, "PB12"},
    {52, "PB13"},
    {53, "PB14"},
    {54, "PB15"},
    {55, "PD8"},
    {56, "PD9"},
    {57, "PD10"},
    {58, "PD11"},
    {59, "PD12"},
    {60, "PD13"},
    {61, "PD14"},
    {62, "PD15"},
    {63, "PC6"},
    {64, "PC7"},
    {65, "PC8"},
    {66, "PC9"},
    {67, "PA8"},
    {68, "PA9"},
    {69, "PA10"},
    {70, "PA11"},
    {71, "PA12"},
    {72, "PA13"},
    {73, "PF4"},
    {74, "VSS"},
    {75, "VDD"},
    {76, "PA14"},
    {77, "PA15"},
    {78, "PC10"},
    {79, "PC11"},
    {80, "PC12"},
    {81, "PD0"},
    {82, "PD1"},
    {83, "PD2"},
    {84, "PD3"},
    {85, "PD4"},
    {86, "PD5"},
    {87, "PD6"},
    {88, "PD7"},
    {89, "PB3"},
    {90, "PB4"},
    {91, "PB5"},
    {92, "PB6"},
    {93, "PB7"},
    {94, "PF3"},
    {95, "PB8"},
    {96, "PB9"},
    {97, "PE0"},
    {98, "PE1"},
    {99, "VSS"},
};
#else
#error soc package error
#endif

rt_bool_t drv_gpio_init(GPIO_TypeDef *gpiox, rt_uint32_t pin, rt_uint32_t mode,
                        rt_uint32_t pull, rt_uint32_t alternate)
{
    GPIO_InitTypeDef    GPIO_InitStruct = {0};

    RT_ASSERT(IS_GPIO_ALL_INSTANCE(gpiox));
    RT_ASSERT(IS_GPIO_PIN(gpiox, pin));
    RT_ASSERT(IS_GPIO_MODE(mode));
    RT_ASSERT(IS_GPIO_PULL(pull));
    RT_ASSERT(IS_GPIO_FUNCTION(alternate));

    switch((uint32_t)gpiox)
    {
        case (uint32_t)GPIOA:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;
        case (uint32_t)GPIOB:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;
        case (uint32_t)GPIOC:
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;
        case (uint32_t)GPIOD:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;
        case (uint32_t)GPIOE:
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;
        case (uint32_t)GPIOF:
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;
        default:
            return RT_FALSE;
    }

    GPIO_InitStruct.Pin       = pin;
    GPIO_InitStruct.Mode      = mode;
    GPIO_InitStruct.Pull      = pull;
    GPIO_InitStruct.Alternate = alternate;
    HAL_GPIO_Init(gpiox, &GPIO_InitStruct);

    return RT_TRUE;
}

GPIO_TypeDef *drv_gpio_get_port(rt_uint32_t index)
{
    rt_uint32_t i;

    for (i = 0; i < sizeof(pin_table) / sizeof(pin_table[0]); i++)
    {
        if (pin_table[i].index == index)
        {
            if (pin_table[i].name[0] != 'P')
            {
                return RT_NULL;
            }
            switch (pin_table[i].name[1])
            {
            case 'A':
                return GPIOA;
            case 'B':
                return GPIOB;
            case 'C':
                return GPIOC;
            case 'D':
                return GPIOD;
            case 'E':
                return GPIOE;
            case 'F':
                return GPIOF;
            default:
                return RT_NULL;
            }
        }
    }
    return RT_NULL;
}

rt_uint32_t drv_gpio_get_pin(rt_uint32_t index)
{
    rt_uint32_t i;

    for (i = 0; i < sizeof(pin_table) / sizeof(pin_table[0]); i++)
    {
        if (pin_table[i].index == index)
        {
            if (pin_table[i].name[0] != 'P')
            {
                return 0;
            }

            rt_size_t name_size = rt_strlen(pin_table[i].name);

            if (name_size == 3)
            {
                return (1 << (pin_table[i].name[2] - '0'));
            }
            else if (name_size == 4)
            {
                if (pin_table[i].name[2] != '1')
                {
                    return 0;
                }
                return (1 << (pin_table[i].name[3] - '0' + 10));
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

rt_base_t drv_gpio_get_index(const char* name)
{
    int ca, cb;
    ca = name[1];
    if (ca >= 'A' && ca <= 'Z')
        ca += 'a' - 'A';
    for (rt_uint32_t i = 0; i < sizeof(pin_table) / sizeof(pin_table[0]); i++)
    {
        cb = pin_table[i].name[1];
        if (cb >= 'A' && cb <= 'Z')
            cb += 'a' - 'A';
        if(ca == cb && 0 == rt_strcmp(&name[3], &pin_table[i].name[2]))
        {
            return pin_table[i].index;
        }
    }
    return 0;
}

rt_bool_t drv_gpio_init_by_name(const char* name, rt_uint32_t mode,
                        rt_uint32_t pull, rt_uint32_t alternate)
{
    GPIO_TypeDef *gpiox;
    rt_uint32_t pin;
    rt_uint32_t index;

    index = drv_gpio_get_index(name);
    gpiox = drv_gpio_get_port(index);
    pin = drv_gpio_get_pin(index);


    return drv_gpio_init(gpiox, pin, mode, pull, alternate);
}

