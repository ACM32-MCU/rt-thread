
/******************************************************************************
*@file  : hal_systimer.h
*@brief : systimer
******************************************************************************/

#ifndef __HAL_SYSTIMER_H
#define __HAL_SYSTIMER_H

#include "acm32g103_hal_conf.h"

typedef struct
{
   uint32_t freq;           //��ʱ��Ƶ�ʣ���λ Hz
   uint32_t period;         //��ʱ������ 
   uint32_t direct;         //��ʱ������0-���ϼ���,1-���¼���
   uint32_t clkPerUs;       //ÿ΢���CLK��
   uint32_t clkPerMs;       //ÿ�����CLK��  
   uint32_t msPeriod;       //ÿ�����ڵ�΢����
   uint32_t usPer65536Clk;  //65536 clk��΢����    
} SYSTIMER_HandleTypeDef;

typedef struct
{
   uint32_t clktickLatest;   
   uint32_t mstickLatest;
   uint32_t clkCount;     
   uint32_t msCount;       
} SYSTIMER_DelayHandleTypeDef;



void HAL_SYSTIMER_Init(void);
void HAL_SYSTIMER_SuppendTick(void);
void HAL_SYSTIMER_ResumeTick(void);
void HAL_SYSTIMER_Enable(void);
void HAL_SYSTIMER_Disable(void);
uint32_t HAL_SYSTIMER_GetMstick(void);
uint32_t HAL_SYSTIMER_GetClktick(void);
void HAL_SYSTIMER_GetClktickMstick(uint32_t *pClktick, uint32_t *pMstick);

uint32_t HAL_SYSTIMER_GetClkDelay(uint32_t clktickStart);

void HAL_SYSTIMER_StartDelay(SYSTIMER_DelayHandleTypeDef *hdelay);
void HAL_SYSTIMER_UpdateDelay(SYSTIMER_DelayHandleTypeDef *hdelay);
uint32_t HAL_SYSTIMER_GetUsDelay(SYSTIMER_DelayHandleTypeDef *hdelay);
uint32_t HAL_SYSTIMER_GetMsDelay(SYSTIMER_DelayHandleTypeDef *hdelay);

uint32_t HAL_SYSTIMER_GetMsDelay_NeedInt(uint32_t msTickStart);

void HAL_SYSTIMER_DelayClks(uint32_t clks);
void HAL_SYSTIMER_DelayUs(uint32_t us);
void HAL_SYSTIMER_DelayMs(uint32_t ms);

void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void delay(uint32_t count);


#endif /* __HAL_SYSTIMER_H */

