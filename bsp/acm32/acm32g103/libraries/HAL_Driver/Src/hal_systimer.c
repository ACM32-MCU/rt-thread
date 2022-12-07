
/******************************************************************************
*@file  : hal_systimer.c
*@brief : ϵͳ��ʱ��ģ�顣Ĭ��ʹ��SysTick��ʱ�������¼�����
*         �û���ѡ�������Ķ�ʱ������Ҫ��д���º�����
*           void HAL_SYSTIMER_Init(void);
*           void HAL_SYSTIMER_SuppendTick(void);
*           void HAL_SYSTIMER_ResumeTick(void);
*           void HAL_SYSTIMER_Enable(void);
*           void HAL_SYSTIMER_Disable(void);
*           uint32_t HAL_SYSTIMER_GetMstick(void);
*           uint32_t HAL_SYSTIMER_GetClktick(void);
*           void HAL_SYSTIMER_GetClktickMstick(uint32_t *pClktick, uint32_t *pMstick);
******************************************************************************/

#include "hal.h"


SYSTIMER_HandleTypeDef g_systimerHandle;

/******************************************************************************
*@brief : systimer��ʼ����
*@param : ��
*@ret   : ��
******************************************************************************/
__weak void HAL_SYSTIMER_Init(void)
{
    if(SysTick->CTRL & SysTick_CTRL_CLKSOURCE_Msk)
    {
        g_systimerHandle.freq = g_SystemCoreClock;
    }
    else
    {
         g_systimerHandle.freq = g_SystemCoreClock>>3;   //8��Ƶ     
    }
    g_systimerHandle.period = SysTick->LOAD; 
    g_systimerHandle.direct = 1;  
    g_systimerHandle.clkPerUs = g_systimerHandle.freq / 1000000;
    g_systimerHandle.clkPerMs = g_systimerHandle.freq / 1000;    
    g_systimerHandle.msPeriod = g_TickFreq; 
    g_systimerHandle.usPer65536Clk = 65536 / g_systimerHandle.clkPerUs;
}

/******************************************************************************
*@brief : ����ϵͳ��ʱ���жϡ�
*@param : ��
*@ret   : ��
******************************************************************************/
__weak void HAL_SYSTIMER_SuppendTick(void)
{
    SysTick->CTRL  &=  ~(SysTick_CTRL_TICKINT_Msk);
}

/******************************************************************************
*@brief : �ָ�ϵͳ��ʱ���жϡ�
*@param : ��
*@ret   : ��
******************************************************************************/
__weak void HAL_SYSTIMER_ResumeTick(void)
{
    SysTick->CTRL  |=  SysTick_CTRL_TICKINT_Msk;
}


/******************************************************************************
*@brief : ʹ�ܶ�ʱ����
*@param : ��
*@ret   : ��
******************************************************************************/
__weak void HAL_SYSTIMER_Enable(void)
{
    SysTick->CTRL  |=  SysTick_CTRL_ENABLE_Msk;
}

/******************************************************************************
*@brief : ֹͣ��ʱ����
*@param : ��
*@ret   : ��
******************************************************************************/
__weak void HAL_SYSTIMER_Disable(void)
{
    SysTick->CTRL  &=  ~(SysTick_CTRL_ENABLE_Msk);
}

/******************************************************************************
*@brief : ��ȡ����tick��
*@param : ��
*@ret   : ��
******************************************************************************/
__weak uint32_t HAL_SYSTIMER_GetMstick(void)
{
   return g_Tick; 
}

/******************************************************************************
*@brief : ��ȡ��ʱ��clktick��
*@param : ��
*@ret   : ��
******************************************************************************/
__weak uint32_t HAL_SYSTIMER_GetClktick(void)
{
   return SysTick->VAL; 
}

/******************************************************************************
*@brief : ��ȡ��ʱ��clktick��mstick��
*@param : ��
*@ret   : ��
******************************************************************************/
__weak void HAL_SYSTIMER_GetClktickMstick(uint32_t *pClktick, uint32_t *pMstick)
{
    do 
    {
        *pMstick = g_Tick;
        *pClktick= SysTick->VAL;
    } 
    while(g_Tick != *pMstick); 
}


/******************************************************************************
*@brief : ����ϵͳ��ʱ��clk�ӳ�ʱ�䡣���ֻ�ܼ���1����ʱ�����ڡ���ʱ���жϹرղ�Ӱ�������
*@param : clktickStart: ��ʼ������ֵ
*@ret   : �ӳ�ʱ�䣬��λ����ʱ��clk
******************************************************************************/
uint32_t HAL_SYSTIMER_GetClkDelay(uint32_t clktickStart)
{
    uint32_t clktickNow;

    clktickNow = HAL_SYSTIMER_GetClktick();
    
    if(g_systimerHandle.direct==0)  //���ϼ���
    {
        if(clktickNow >= clktickStart)
        {
            return (clktickNow - clktickStart);
        }
        else
        {
            return (g_systimerHandle.period + clktickNow - clktickStart);
        }            
    }
    else  //���¼���
    {
        if(clktickNow <= clktickStart)
        {
            return (clktickStart - clktickNow);
        }
        else
        {
            return (clktickStart + g_systimerHandle.period - clktickNow);
        }         
    }
}

/******************************************************************************
*@brief : ����delay���񡣻�ȡ��ǰtick����ʼ��delay handle������
*@param : hdelay: delay handle
*@ret   : ��
******************************************************************************/
void HAL_SYSTIMER_StartDelay(SYSTIMER_DelayHandleTypeDef *hdelay)
{
    do 
    {
        hdelay->mstickLatest = HAL_SYSTIMER_GetMstick();
        hdelay->clktickLatest = HAL_SYSTIMER_GetClktick();
    } 
    while(HAL_SYSTIMER_GetMstick() != hdelay->mstickLatest);
    
    hdelay->clkCount = 0;  
    hdelay->msCount = 0;  
}

/******************************************************************************
*@brief : ����delay����
*@param : hdelay: delay handle
*@ret   : ��
******************************************************************************/
void HAL_SYSTIMER_UpdateDelay(SYSTIMER_DelayHandleTypeDef *hdelay)
{
    uint32_t clktickNow, mstickNow;
    
    HAL_SYSTIMER_GetClktickMstick(&clktickNow, &mstickNow);
    
    if(mstickNow - hdelay->mstickLatest < g_systimerHandle.msPeriod)
    {
        if(g_systimerHandle.direct==0)  //���ϼ���
        {
            if(clktickNow >= hdelay->clktickLatest)
            {
                hdelay->clkCount += clktickNow - hdelay->clktickLatest;
            }
            else
            {
                hdelay->clkCount += g_systimerHandle.period + clktickNow - hdelay->clktickLatest;
            }            
        }
        else  //���¼���
        {
            if(clktickNow <= hdelay->clktickLatest)
            {
                hdelay->clkCount += hdelay->clktickLatest - clktickNow;
            }
            else
            {
                hdelay->clkCount += hdelay->clktickLatest + g_systimerHandle.period - clktickNow;
            }
        }
    }
    else
    {
        if(g_systimerHandle.direct==0)  //���ϼ���
        {
            hdelay->clkCount += g_systimerHandle.period + clktickNow - hdelay->clktickLatest;          
        }
        else  //���¼���
        {
            hdelay->clkCount += hdelay->clktickLatest + g_systimerHandle.period - clktickNow;
        }
        hdelay->msCount += (mstickNow - hdelay->mstickLatest) - g_systimerHandle.msPeriod;
    }
    hdelay->clktickLatest = clktickNow;   
    hdelay->mstickLatest = mstickNow;    
    
    if(hdelay->clkCount >= g_systimerHandle.period)
    {
        hdelay->clkCount -= g_systimerHandle.period;
        hdelay->msCount += g_systimerHandle.msPeriod;
    }
//    
//    while(hdelay->clkCount >= g_systimerHandle.clkPerMs)
//    {
//        hdelay->clkCount -= g_systimerHandle.clkPerMs;
//        hdelay->msCount++;
//    }    
    
}

/******************************************************************************
*@brief : ������delay����ʼ������ǰʱ���΢���ӳ١�����ʱ70�������ҡ���ʱ���жϹرպ�Ҳ��ʹ�á�
*         �����ʱ���жϹرգ���ÿ����ʱ��������Ҫ����HAL_SYSTIMER_UpdateDelay�������߱�����2�����ϣ�
*           ����ᵼ�·��ص���ʱʱ���ʵ��ʱ��ƫС��
*         �����ʱ���жϿ�������û���������ơ�
*@param : hdelay: delay handle
*@ret   : ΢���ӳ�
******************************************************************************/
uint32_t HAL_SYSTIMER_GetUsDelay(SYSTIMER_DelayHandleTypeDef *hdelay)
{
    uint32_t us;
    HAL_SYSTIMER_UpdateDelay(hdelay);
    
    us = (hdelay->clkCount * g_systimerHandle.usPer65536Clk) >> 16;
    us += hdelay->msCount * 1000;    
    return us;
}

/******************************************************************************
*@brief : ������delay����ʼ������ǰʱ��ĺ����ӳ١���ʱ���жϹرպ�Ҳ��ʹ�á�
*         �����ʱ���жϹرգ���ÿ����ʱ��������Ҫ����HAL_SYSTIMER_UpdateDelay�������߱�����2�����ϣ�
*           ����ᵼ�·��ص���ʱʱ���ʵ��ʱ��ƫС��
*         �����ʱ���жϿ�������û���������ơ�
*@param : hdelay: delay handle
*@ret   : �����ӳ�
******************************************************************************/
uint32_t HAL_SYSTIMER_GetMsDelay(SYSTIMER_DelayHandleTypeDef *hdelay)
{
    HAL_SYSTIMER_UpdateDelay(hdelay);
    
    return hdelay->msCount; 
}

/******************************************************************************
*@brief : ����ʼmstick��ʼ������ǰʱ��ĺ����ӳ١�ʹ�ñ���������Ҫ��ǰ������ʱ���жϡ�
*@param : msTickStart: ��ʼmstick
*@ret   : �����ӳ�
******************************************************************************/
uint32_t HAL_SYSTIMER_GetMsDelay_NeedInt(uint32_t msTickStart)
{
    return (HAL_SYSTIMER_GetMstick() - msTickStart);
}

/******************************************************************************
*@brief : ϵͳ��ʱ��ʱ����ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ��100MHzʱ��ʱ�������ʱ32�룬����ʱ���Դ����ơ�
*@param : clks: ��ʱ��clks
*@ret   : ��
******************************************************************************/
void HAL_SYSTIMER_DelayClks(uint32_t clks)
{
    uint32_t clktickStart, clktickNow;
    uint32_t count;

    clktickStart = HAL_SYSTIMER_GetClktick();
    count = 0;
    while(1)
    {
        clktickNow = HAL_SYSTIMER_GetClktick();
        
        if(g_systimerHandle.direct==0)  //���ϼ���
        {
            if(clktickNow >= clktickStart)
            {
                count += clktickNow - clktickStart;
            }
            else
            {
                count += g_systimerHandle.period + clktickNow - clktickStart;
            }
        }
        else  //���¼���
        {
            if(clktickNow <= clktickStart)
            {
                count += clktickStart - clktickNow;
            }
            else
            {
                count += clktickStart + g_systimerHandle.period - clktickNow;
            }
        }
        
        if(count >= clks)
        {
            return;
        }
        clktickStart = clktickNow;
    }
}

/******************************************************************************
*@brief : ΢����ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ�������ʱ70�������ҡ�
*@param : us: ��ʱ��΢����
*@ret   : ��
******************************************************************************/
void HAL_SYSTIMER_DelayUs(uint32_t us)
{
    if(us<1000000)
    {
        HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerUs * us);
    }
    else
    {
        HAL_SYSTIMER_DelayMs(us/1000);
    }
}

/******************************************************************************
*@brief : ������ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ�������ʱ49�����ҡ�
*@param : ms: ��ʱ�ĺ�����
*@ret   : ��
******************************************************************************/
void HAL_SYSTIMER_DelayMs(uint32_t ms)
{
    while(ms--)
    {
        HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerMs);
    }
}

/******************************************************************************
*@brief : ΢����ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ�������ʱ70�������ҡ�
*@param : us: ��ʱ��΢����
*@ret   : ��
******************************************************************************/
__weak void delay_us(uint32_t us)
{
    HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerUs * us);
}

/******************************************************************************
*@brief : ������ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ�������ʱ49�����ҡ�
*@param : ms: ��ʱ�ĺ�����
*@ret   : ��
******************************************************************************/
__weak void delay_ms(uint32_t ms)
{
    while(ms--)
    {
        HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerMs);
    }
}


/*****************************************************************
@����	����ʱ
@����	count[in]:��ʱʱ��
@����	��
******************************************************************/

/******************************************************************************
*@brief : ����ʱ��while(1)ѭ����
*@param : count: ѭ������
*@ret   : ��
******************************************************************************/
__weak void delay(uint32_t count)
{
    while(count--);
}

