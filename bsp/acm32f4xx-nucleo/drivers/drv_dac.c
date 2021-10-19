/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-15     Aisinochip   First version
 */

#include <board.h>
#include <rtthread.h>
#include <rtdevice.h>

#if defined(BSP_USING_DAC)

#define     DAC_NAME        "dac"

struct acm32_dac
{
    DAC_HandleTypeDef       handle;
    struct rt_dac_device    acm32_dac_device;
    rt_uint8_t              enable;
};

static struct acm32_dac acm32_dac_obj = {0};

static bool dac_channel_validate(rt_uint32_t channel)
{
    if((channel<<4) == DAC_CHANNEL_1 || (channel<<4) == DAC_CHANNEL_2)
    {
        return true;
    }
    return false;
}

static rt_err_t _dac_enabled(struct rt_dac_device *device, rt_uint32_t channel)
{
    struct acm32_dac *dacObj = RT_NULL;
    DAC_ChannelConfTypeDef sConfig;

    RT_ASSERT(device != RT_NULL);

    if(!dac_channel_validate(channel))
    {
        return -RT_ERROR;
    }

    dacObj = rt_container_of(device, struct acm32_dac, acm32_dac_device);

    if(dacObj->enable &(1<<channel))
    {
        return RT_EOK;
    }

    dacObj->handle.Instance = DAC;

    HAL_DAC_Init(&dacObj->handle);

    sConfig.DAC_Trigger=DAC_TRIGGER_SOFTWARE;
    sConfig.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
    sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
    sConfig.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_DISABLE;
    sConfig.DAC_UserTrimming = DAC_TRIMMING_FACTORY;

    dacObj->enable |= (1<<channel);

    HAL_DAC_ConfigChannel(&dacObj->handle, &sConfig, channel<<4);

    HAL_DACEx_SelfCalibrate(&dacObj->handle, &sConfig, channel<<4);

    return RT_EOK;
}

static rt_err_t _dac_disabled(struct rt_dac_device *device, rt_uint32_t channel)
{
    struct acm32_dac *dacObj = RT_NULL;

    RT_ASSERT(device != RT_NULL);

    if(!dac_channel_validate(channel))
    {
        return -RT_ERROR;
    }

    dacObj = rt_container_of(device, struct acm32_dac, acm32_dac_device);

    dacObj->enable &= ~(1<<channel);

    HAL_DAC_Stop(&dacObj->handle, channel<<4);

    return RT_EOK;
}

static rt_err_t _dac_convert(struct rt_dac_device *device, rt_uint32_t channel, rt_uint32_t *value)
{
    struct acm32_dac *dacObj = RT_NULL;

    RT_ASSERT(device != RT_NULL);
    RT_ASSERT(value != RT_NULL);

    if(!dac_channel_validate(channel))
    {
        return -RT_ERROR;
    }

    dacObj = rt_container_of(device, struct acm32_dac, acm32_dac_device);

    /* channel disabled */
    if(0 == (dacObj->enable & (1<<channel) ))
    {
        return -RT_ERROR;
    }

    HAL_DAC_SetValue(&dacObj->handle, channel<<4, DAC_ALIGN_12B_R, *value);

    HAL_DAC_Start(&dacObj->handle, channel<<4);

    return RT_EOK;
}

static const struct rt_dac_ops acm_dac_ops =
{
    .enabled = _dac_enabled,
    .disabled = _dac_disabled,
    .convert = _dac_convert,
};

static int rt_hw_dac_init(void)
{
    return rt_hw_dac_register(&acm32_dac_obj.acm32_dac_device,
                              DAC_NAME,
                              &acm_dac_ops,
                              RT_NULL);
}
INIT_BOARD_EXPORT(rt_hw_dac_init);

void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac)
{
    if(hdac->Instance==DAC)
    {
        /* Enable DAC clock */
        System_Module_Enable(DAC_MODULE_CLOCK);
        GPIO_InitTypeDef GPIO_InitStructure;

        /* Initialization GPIO */
        GPIO_InitStructure.Pin = DAC_CHNL1_PIN;
        GPIO_InitStructure.Pull=DAC_CHNL1_PULL;
        GPIO_InitStructure.Mode = DAC_CHNL1_MODE;
        HAL_GPIO_Init(DAC_CHNL1_PORT, &GPIO_InitStructure);

        GPIO_InitStructure.Pin = DAC_CHNL2_PIN;
        GPIO_InitStructure.Pull=DAC_CHNL2_PULL;
        GPIO_InitStructure.Mode = DAC_CHNL2_MODE;
        HAL_GPIO_Init(DAC_CHNL2_PORT, &GPIO_InitStructure);

        /* Enable the DAC DMA underrun interrupt */
        hdac->Instance->CR |= DAC_CR_DMAUDRIE1|DAC_CR_DMAUDRIE2;
        NVIC_ClearPendingIRQ(DAC_IRQ_NUMBER);
        NVIC_SetPriority(DAC_IRQ_NUMBER, DAC_IRQ_PRIORITY);
        NVIC_EnableIRQ(DAC_IRQ_NUMBER);
    }
}
#endif /* BSP_USING_DAC */

