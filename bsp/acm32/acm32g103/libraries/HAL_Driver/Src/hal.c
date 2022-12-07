
/******************************************************************************
*@file  : hal.c
*@brief : This is the common part of the HAL initialization
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#include "hal.h"  


static __IO uint32_t g_msTick = 0;
HAL_SysTickHandleTypeDef g_systickHandle;

/******************************************************************************
*@brief : init hal library
*@param : none
*@return: none
******************************************************************************/
HAL_StatusTypeDef HAL_Init(void)
{
    
	#if (INS_ACCELERATE_ENABLE == 1)
		System_EnableIAccelerate();
	#endif

	#if (DATA_ACCELERATE_ENABLE == 1)
		System_EnableDAccelerate();
	#endif     
    
	/* Set Interrupt Group Priority */
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    
	g_SystemCoreClock = HAL_RCC_GetSysCoreClockFreq();
    
	/* Use systick as time base source and configure 1ms tick (default clock after Reset is HSI) */ 
	HAL_InitTick(TICK_INT_PRIORITY, TICK_PERIOD_MS);

	/* Init the low level hardware */
	HAL_MspInit();
	

	/* Return function status */
	return HAL_OK;
}


/******************************************************************************
*@brief : deinit hal library
*@param : none
*@return: none
******************************************************************************/
HAL_StatusTypeDef HAL_DeInit(void)
{
  /* Reset of all peripherals */

  /* De-Init the low level hardware */
  HAL_MspDeInit();
    
  /* Return function status */
  return HAL_OK;
}


/******************************************************************************
*@brief : Initialize the MSP
*@param : none
*@return: none
******************************************************************************/
__weak void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
}


/******************************************************************************
*@brief : DeInitializes the MSP
*@param : none
*@return: none
******************************************************************************/
__weak void HAL_MspDeInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspDeInit could be implemented in the user file
   */ 
}


/******************************************************************************
*@brief : This function configures the source of the time base.
*         The time source is configured  to have 1ms time base with a dedicated Tick interrupt priority.       
*@note  : This function is called  automatically at the beginning of program after
*         reset by HAL_Init() or at any time when clock is reconfigured  by HAL_RCC_ClockConfig().
*@note  : In the default implementation, SysTick timer is the source of time base. 
*           It is used to generate interrupts at regular time intervals. 
*           Care must be taken if HAL_Delay() is called from a peripheral ISR process, 
*           The SysTick interrupt must have higher priority (numerically lower)
*           than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
*           The function is declared as __weak  to be overwritten  in case of other
*           implementation  in user file.
*@param : TickPriority: Tick interrupt priority.
*@retval: HAL status
******************************************************************************/
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t intPrio, uint32_t msPeriod)
{
    /* Configure the SysTick to have interrupt in 1ms time basis*/
    g_systickHandle.freq = g_SystemCoreClock;   
    if (HAL_SYSTICK_Config(g_systickHandle.freq / (1000U / msPeriod)) > 0U)
    {
        return HAL_ERROR;
    }
    
    g_systickHandle.period = SysTick->LOAD;  
    g_systickHandle.clkPerUs = g_systickHandle.freq / 1000000;
    g_systickHandle.clkPerMs = g_systickHandle.freq / 1000;    
    g_systickHandle.msPeriod = msPeriod; 
    g_systickHandle.usPer65536Clk = 65536 / g_systickHandle.clkPerUs;  

    /* Configure the SysTick IRQ priority */
    if (intPrio >= (1UL << __NVIC_PRIO_BITS))
    {
        intPrio = (1UL << __NVIC_PRIO_BITS)-1;
    }
    HAL_NVIC_SetPriority(SysTick_IRQn, intPrio, 0U);
    g_systickHandle.intPrio = intPrio;

    /* Return function status */
    return HAL_OK;
}

/******************************************************************************
*@brief : This function is called to increment  a global variable "g_msTick"
*           In the default implementation, this variable is incremented each 1ms in SysTick ISR.
*           This function is declared as __weak to be overwritten in case of other implementations in user file.
*@param : none
*@return: none
******************************************************************************/
__weak void HAL_IncTick(void)
{
	g_msTick += g_systickHandle.msPeriod;
}


/******************************************************************************
*@brief : Provides a tick value in millisecond
*         This function is declared as __weak to be overwritten in case of other implementations in user file.
*@return: none
******************************************************************************/
__weak uint32_t HAL_GetTick(void)
{
    return (g_msTick);
}


/******************************************************************************
*@brief : Set new SysTick period in ms
*@return: Status
******************************************************************************/
HAL_StatusTypeDef HAL_SetTickMsPeriod(int msPeriod)
{
  HAL_StatusTypeDef status  = HAL_OK;

  if (g_systickHandle.msPeriod != msPeriod)
  {
    status = HAL_InitTick(g_systickHandle.intPrio, g_systickHandle.msPeriod);
  }

  return status;
}

/******************************************************************************
*@brief : Return SysTick period
*@return: SysTick period in ms
******************************************************************************/
uint32_t HAL_GetTickMsPeriod(void)
{
  return g_systickHandle.msPeriod;
}


/******************************************************************************
*@brief : This function provides minimum delay (in milliseconds) based on variable incremented
*           This function is declared as __weak to be overwritten in case of other implementations in user file.
*@param : Delay: specifies the delay time length, in milliseconds.
*@return: none
******************************************************************************/
__weak void HAL_Delay(uint32_t msDelay)
{
    uint32_t tickstart = HAL_GetTick();
    uint32_t wait = msDelay;

    /* Add a freq to guarantee minimum wait */
    if (wait < HAL_MAX_DELAY-(uint32_t)(g_systickHandle.msPeriod))
    {
        wait += (uint32_t)(g_systickHandle.msPeriod);
    }

    while((HAL_GetTick() - tickstart) < wait)
    {
    }
}



/******************************************************************************
*@brief : Suspend Tick increment
*@param : none
*@return: none
******************************************************************************/
__weak void HAL_SuspendTick(void)  
{
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;   
}

/******************************************************************************
*@brief : Resume Tick increment
*@param : none
*@return: none
******************************************************************************/
__weak void HAL_ResumeTick(void)  
{
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;   
}


/******************************************************************************
*@brief : SysTickʱ����ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ��100MHzʱ��ʱ�������ʱ32�룬����ʱ���Դ����ơ�
*@param : clks: ��ʱ��clks
*@ret   : ��
******************************************************************************/
void HAL_DelayClks(uint32_t clks)
{
    uint32_t clktickStart, clktickNow;
    uint32_t count;

    clktickStart = SysTick->VAL;
    count = 0;
    while(1)
    {
        clktickNow = SysTick->VAL;
        
        if(clktickNow <= clktickStart)
        {
            count += clktickStart - clktickNow;
        }
        else
        {
            count += clktickStart + g_systickHandle.period - clktickNow;
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
void HAL_DelayUs(uint32_t us)
{
    while(us>1000000)
    {
        HAL_DelayClks(g_systickHandle.freq);
        us -= 1000000;
    }
    HAL_DelayClks(g_systickHandle.clkPerUs * us);
}

/******************************************************************************
*@brief : ������ʱ����ʱ�жϹر�Ҳ�ɼ�ʱ�������ʱ49�����ҡ�
*@param : ms: ��ʱ�ĺ�����
*@ret   : ��
******************************************************************************/
void HAL_DelayMs(uint32_t ms)
{
    while(ms>1000)
    {
        HAL_DelayClks(g_systickHandle.freq);
        ms -= 1000;
    }
    HAL_DelayClks(g_systickHandle.clkPerMs * ms);
}

/******************************************************************************
*@brief : ͨ��whileѭ������ʱ��
*@param : delay: whileѭ������
*@ret   : ��
******************************************************************************/
void HAL_SimpleDelay(uint32_t delay)
{
    while(delay--)
    {
        ;
    }
}


/******************************************************************************
*@brief : ����delay���񡣻�ȡ��ǰtick����ʼ��delay handle������
*@param : hdelay: delay handle
*@ret   : ��
******************************************************************************/
void HAL_StartDelay(HAL_DelayHandleTypeDef *hdelay)
{
    do 
    {
        hdelay->mstickLatest = g_msTick;
        hdelay->clktickLatest = SysTick->VAL;
    } 
    while(g_msTick != hdelay->mstickLatest);
    
    hdelay->clkCount = 0;  
    hdelay->msCount = 0;  
}

/******************************************************************************
*@brief : ����delay����
*@param : hdelay: delay handle
*@ret   : ��
******************************************************************************/
void HAL_UpdateDelay(HAL_DelayHandleTypeDef *hdelay)
{
    uint32_t clktickNow, mstickNow,mstickNext;
    
    do 
    {
        mstickNow = g_msTick;
        clktickNow = SysTick->VAL;
    } 
    while(g_msTick != mstickNow);
    
    mstickNext = hdelay->mstickLatest + g_systickHandle.msPeriod;
    
    if(mstickNow < mstickNext)
    {
        if(clktickNow <= hdelay->clktickLatest)
        {
            hdelay->clkCount += hdelay->clktickLatest - clktickNow;
        }
        else
        {
            hdelay->clkCount += hdelay->clktickLatest + g_systickHandle.period - clktickNow;
        }
    }
    else
    {
        hdelay->clkCount += hdelay->clktickLatest + g_systickHandle.period - clktickNow;
        hdelay->msCount += mstickNow - mstickNext;
    }
    
    hdelay->clktickLatest = clktickNow;   
    hdelay->mstickLatest = mstickNow;    
    
    if(hdelay->clkCount >= g_systickHandle.period)
    {
        hdelay->clkCount -= g_systickHandle.period;
        hdelay->msCount += g_systickHandle.msPeriod;
    }
}


/******************************************************************************
*@brief : ������delay����ʼ������ǰʱ���clk�ӳ١�����ʱ70�������ҡ���ʱ���жϹرպ�Ҳ��ʹ�á�
*         �����ʱ���жϹرգ���ÿ����ʱ��������Ҫ����HAL_UpdateDelay�������߱�����1�����ϣ�
*           ����ᵼ�·��ص���ʱʱ���ʵ��ʱ��ƫС��
*         �����ʱ���жϿ�������û���������ơ�
*@param : hdelay: delay handle
*@ret   : ΢���ӳ�
******************************************************************************/
uint32_t HAL_GetClkDelay(HAL_DelayHandleTypeDef *hdelay)
{
    HAL_UpdateDelay(hdelay);
    
    return hdelay->clkCount +  hdelay->msCount * g_systickHandle.clkPerMs;
}

/******************************************************************************
*@brief : ������delay����ʼ������ǰʱ���΢���ӳ١�����ʱ70�������ҡ���ʱ���жϹرպ�Ҳ��ʹ�á�
*         �����ʱ���жϹرգ���ÿ����ʱ��������Ҫ����HAL_UpdateDelay�������߱�����1�����ϣ�
*           ����ᵼ�·��ص���ʱʱ���ʵ��ʱ��ƫС��
*         �����ʱ���жϿ�������û���������ơ�
*@param : hdelay: delay handle
*@ret   : ΢���ӳ�
******************************************************************************/
uint32_t HAL_GetUsDelay(HAL_DelayHandleTypeDef *hdelay)
{
    uint32_t us;
    HAL_UpdateDelay(hdelay);
    
    us = (hdelay->clkCount * g_systickHandle.usPer65536Clk ) >> 16;
    us += hdelay->msCount * 1000;    
    return us;
}

/******************************************************************************
*@brief : ������delay����ʼ������ǰʱ��ĺ����ӳ١���ʱ���жϹرպ�Ҳ��ʹ�á�
*         �����ʱ���жϹرգ���ÿ����ʱ��������Ҫ����HAL_UpdateDelay�������߱�����1�����ϣ�
*           ����ᵼ�·��ص���ʱʱ���ʵ��ʱ��ƫС��
*         �����ʱ���жϿ�������û���������ơ�
*@param : hdelay: delay handle
*@ret   : �����ӳ�
******************************************************************************/
uint32_t HAL_GetMsDelay(HAL_DelayHandleTypeDef *hdelay)
{
    HAL_UpdateDelay(hdelay);
    
    return hdelay->msCount; 
}


/******************************************************************************
*@brief : Returns the unique device identifier (UID based on 128 bits)
*@param : UID: buffer of uid
*@return: none
******************************************************************************/
void HAL_GetUID(uint32_t *UID)
{
    ;
}


 


