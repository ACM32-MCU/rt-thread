
/******************************************************************************
*@file  : hal_systimer.c
*@brief : 系统定时器模块。默认使用SysTick定时器，向下计数。
*         用户可选择其他的定时器。需要重写以下函数：
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
*@brief : systimer初始化。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak void HAL_SYSTIMER_Init(void)
{
    if(SysTick->CTRL & SysTick_CTRL_CLKSOURCE_Msk)
    {
        g_systimerHandle.freq = g_SystemCoreClock;
    }
    else
    {
         g_systimerHandle.freq = g_SystemCoreClock>>3;   //8分频     
    }
    g_systimerHandle.period = SysTick->LOAD; 
    g_systimerHandle.direct = 1;  
    g_systimerHandle.clkPerUs = g_systimerHandle.freq / 1000000;
    g_systimerHandle.clkPerMs = g_systimerHandle.freq / 1000;    
    g_systimerHandle.msPeriod = g_TickFreq; 
    g_systimerHandle.usPer65536Clk = 65536 / g_systimerHandle.clkPerUs;
}

/******************************************************************************
*@brief : 挂起系统定时器中断。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak void HAL_SYSTIMER_SuppendTick(void)
{
    SysTick->CTRL  &=  ~(SysTick_CTRL_TICKINT_Msk);
}

/******************************************************************************
*@brief : 恢复系统定时器中断。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak void HAL_SYSTIMER_ResumeTick(void)
{
    SysTick->CTRL  |=  SysTick_CTRL_TICKINT_Msk;
}


/******************************************************************************
*@brief : 使能定时器。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak void HAL_SYSTIMER_Enable(void)
{
    SysTick->CTRL  |=  SysTick_CTRL_ENABLE_Msk;
}

/******************************************************************************
*@brief : 停止定时器。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak void HAL_SYSTIMER_Disable(void)
{
    SysTick->CTRL  &=  ~(SysTick_CTRL_ENABLE_Msk);
}

/******************************************************************************
*@brief : 获取毫秒tick。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak uint32_t HAL_SYSTIMER_GetMstick(void)
{
   return g_Tick; 
}

/******************************************************************************
*@brief : 获取定时器clktick。
*@param : 无
*@ret   : 无
******************************************************************************/
__weak uint32_t HAL_SYSTIMER_GetClktick(void)
{
   return SysTick->VAL; 
}

/******************************************************************************
*@brief : 获取定时器clktick和mstick。
*@param : 无
*@ret   : 无
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
*@brief : 计算系统定时器clk延迟时间。最大只能计算1个定时器周期。定时器中断关闭不影响计数。
*@param : clktickStart: 起始计数器值
*@ret   : 延迟时间，单位：定时器clk
******************************************************************************/
uint32_t HAL_SYSTIMER_GetClkDelay(uint32_t clktickStart)
{
    uint32_t clktickNow;

    clktickNow = HAL_SYSTIMER_GetClktick();
    
    if(g_systimerHandle.direct==0)  //向上计数
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
    else  //向下计数
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
*@brief : 启动delay事务。获取当前tick，初始化delay handle参数。
*@param : hdelay: delay handle
*@ret   : 无
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
*@brief : 更新delay事务。
*@param : hdelay: delay handle
*@ret   : 无
******************************************************************************/
void HAL_SYSTIMER_UpdateDelay(SYSTIMER_DelayHandleTypeDef *hdelay)
{
    uint32_t clktickNow, mstickNow;
    
    HAL_SYSTIMER_GetClktickMstick(&clktickNow, &mstickNow);
    
    if(mstickNow - hdelay->mstickLatest < g_systimerHandle.msPeriod)
    {
        if(g_systimerHandle.direct==0)  //向上计数
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
        else  //向下计数
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
        if(g_systimerHandle.direct==0)  //向上计数
        {
            hdelay->clkCount += g_systimerHandle.period + clktickNow - hdelay->clktickLatest;          
        }
        else  //向下计数
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
*@brief : 从启动delay事务开始，到当前时间的微秒延迟。最大计时70分钟左右。定时器中断关闭后也可使用。
*         如果定时器中断关闭，则每个定时器周期需要调用HAL_SYSTIMER_UpdateDelay函数或者本函数2次以上，
*           否则会导致返回的延时时间比实际时间偏小。
*         如果定时器中断开启，则没有以上限制。
*@param : hdelay: delay handle
*@ret   : 微秒延迟
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
*@brief : 从启动delay事务开始，到当前时间的毫秒延迟。定时器中断关闭后也可使用。
*         如果定时器中断关闭，则每个定时器周期需要调用HAL_SYSTIMER_UpdateDelay函数或者本函数2次以上，
*           否则会导致返回的延时时间比实际时间偏小。
*         如果定时器中断开启，则没有以上限制。
*@param : hdelay: delay handle
*@ret   : 毫秒延迟
******************************************************************************/
uint32_t HAL_SYSTIMER_GetMsDelay(SYSTIMER_DelayHandleTypeDef *hdelay)
{
    HAL_SYSTIMER_UpdateDelay(hdelay);
    
    return hdelay->msCount; 
}

/******************************************************************************
*@brief : 从起始mstick开始，到当前时间的毫秒延迟。使用本函数，需要提前开启定时器中断。
*@param : msTickStart: 起始mstick
*@ret   : 毫秒延迟
******************************************************************************/
uint32_t HAL_SYSTIMER_GetMsDelay_NeedInt(uint32_t msTickStart)
{
    return (HAL_SYSTIMER_GetMstick() - msTickStart);
}

/******************************************************************************
*@brief : 系统定时器时钟延时。定时中断关闭也可计时。100MHz时钟时，最大延时32秒，其他时钟以此类推。
*@param : clks: 延时的clks
*@ret   : 无
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
        
        if(g_systimerHandle.direct==0)  //向上计数
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
        else  //向下计数
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
*@brief : 微秒延时。定时中断关闭也可计时。最大延时70分钟左右。
*@param : us: 延时的微秒数
*@ret   : 无
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
*@brief : 毫秒延时。定时中断关闭也可计时。最大延时49天左右。
*@param : ms: 延时的毫秒数
*@ret   : 无
******************************************************************************/
void HAL_SYSTIMER_DelayMs(uint32_t ms)
{
    while(ms--)
    {
        HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerMs);
    }
}

/******************************************************************************
*@brief : 微秒延时。定时中断关闭也可计时。最大延时70分钟左右。
*@param : us: 延时的微秒数
*@ret   : 无
******************************************************************************/
__weak void delay_us(uint32_t us)
{
    HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerUs * us);
}

/******************************************************************************
*@brief : 毫秒延时。定时中断关闭也可计时。最大延时49天左右。
*@param : ms: 延时的毫秒数
*@ret   : 无
******************************************************************************/
__weak void delay_ms(uint32_t ms)
{
    while(ms--)
    {
        HAL_SYSTIMER_DelayClks(g_systimerHandle.clkPerMs);
    }
}


/*****************************************************************
@功能	简单延时
@参数	count[in]:延时时间
@返回	无
******************************************************************/

/******************************************************************************
*@brief : 简单延时。while(1)循环。
*@param : count: 循环次数
*@ret   : 无
******************************************************************************/
__weak void delay(uint32_t count)
{
    while(count--);
}

