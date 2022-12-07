
/******************************************************************************
* @file      : HAL_PMU.c
* @version   : 1.0
* @date      : 2022.10.25
* @brief     : PMU HAL module driver
*   
* @history   :	
*   2022.10.25    lwq    create
*   
******************************************************************************/
#include "hal.h" 


#ifdef HAL_PMU_MODULE_ENABLED

/******************************************************************************
* @brief : try to enter sleep mode.
* @param : sleepEntry: SLEEPENTRY_WFI or SLEEPENTRY_WFE
* @return: none
******************************************************************************/
void HAL_PMU_EnterSleepMode(uint32_t sleepEntry)
{
    /* clear SLEEPDEEP bit of Cortex System Control Register */
    CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));         

    if(sleepEntry == WAIT_FOR_INT)       
    {
        /* Wait For Interrupt */
        __WFI();
    }
    else
    {
        
        __SEV();      
        __WFE();
        __WFE(); /*Wait For Event */     
    }  
}

/******************************************************************************
* @brief : try to enter stop mode.
* @param : stopEntry: WAIT_FOR_INT or WAIT_FOR_EVENT
* @param : stopMode: LOWPOWER_SEL_STOP0 or LOWPOWER_SEL_STOP1 or LOWPOWER_SEL_STOP2.
* @return: none
******************************************************************************/
void HAL_PMU_EnterStopMode(uint32_t stopEntry, uint32_t stopMode)
{
    
    SysTick->CTRL = 0;   // disable systick        
    __set_PRIMASK(1);    // disable interrupt 
    SCB->ICSR = BIT25;   // clear systick pending bit 

    __HAL_RCC_PMU_CLK_ENABLE();	
      
    if(stopMode == PMU_CTL0_LPMS_STOP2)
    {
        //STOP2
        PMU->CTRL0 |= (0x1 << 8);
        RCC->STDBYCTRL |= (1<<8);
        
        /*Ê±ÖÓÇÐ»»µ½RC32K*/
        RCC->CCR1 = 0x01; 
        while(0 == ((RCC->STDBYCTRL) & (1U << 9)));
        MODIFY_REG(PMU->CTRL0, PMU_CTL0_LPMS_Msk, PMU_CTL0_LPMS_STOP2);
    }
    MODIFY_REG(PMU->CTRL0, PMU_CTL0_LPMS_Msk, stopMode);//Stop0/1/2 Mode
    
    SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));   // Set SLEEPDEEP bit of Cortex System Control Register 

    if(stopEntry == WAIT_FOR_INT)
    {
        /* Wait For Interrupt */   
        __WFI();
    }
    else
    {
        /* Wait For Event */  
        __SEV();   
        __WFE();
        __WFE();    
    }
    /* clear SLEEPDEEP bit of Cortex System Control Register */
    CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk)); 

    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; /* Enable SysTick IRQ and SysTick Timer */               
    __set_PRIMASK(0);    // enable interrupt 

}


/******************************************************************************
* @brief : try to enter standby mode.
* @param : none
* @return: none
******************************************************************************/
void HAL_PMU_EnterStandbyMode(void)
{
    SysTick->CTRL = 0;   // disable systick        
    __set_PRIMASK(1);    // disable interrupt 
    SCB->ICSR = BIT25;   // clear systick pending bit
    
    __HAL_RCC_PMU_CLK_ENABLE();	
    
    MODIFY_REG(PMU->CTRL0, PMU_CTL0_LPMS_Msk, PMU_CTL0_LPMS_STANDBY);//Standby Mode

    SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));   // Set SLEEPDEEP bit of Cortex System Control Register 

    /* Wait For Interrupt */   
    __WFI();


    CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk)); 

    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; /* Enable SysTick IRQ and SysTick Timer */               
    __set_PRIMASK(0);    // enable interrupt 

    printfS("Enter Standby Mode Failed! \n");   // should not go here  
}


/******************************************************************************
* @brief : wakeup source select.
* @param : wakeup_io: wakeup source select(STANDBY_WAKEUP1 STANDBY_WAKEUP2 ...) 
* @param : edge: 0(Rising edge), 1(Falling edge).
* @return: none
******************************************************************************/
void HAL_PMU_StandbyWakeupIOConfig(PMU_WakeUpIo_t wakeup_io, uint32_t edge)
{
    switch (wakeup_io)
    {
        case STANDBY_WAKEUP1: 
        case STANDBY_WAKEUP2: 
        case STANDBY_WAKEUP3: 
        case STANDBY_WAKEUP4: 
        case STANDBY_WAKEUP5: 
        {			
            //PMU CLK Enable
            __HAL_RCC_PMU_CLK_ENABLE();            

             //Clear flags
            SET_BIT(PMU->STCLR, (PMU_SRCLR_CWUPFX_Msk | PMU_SRCLR_CSBF_Msk));

            /* Wakeup IO Filter Enable */
            PMU->CTRL2 |= wakeup_io << PMU_CTL2_WUXFILEN_Pos;

            /* Wakeup IO Enable */
            PMU->CTRL2  |= wakeup_io;
               
            if (edge) 
            {
                PMU->CTRL3 |= edge;
            }
            else 
            {
                PMU->CTRL3 &= ~(1<<edge);   
            }
 
        }
        break;
        
        default: break;       
    }
}

/******************************************************************************
* @brief : wakeup source select.
* @param : Wakeup_rtc: wakeup source select(RTC_WAKEUP_DATE...) 
* @return: none
******************************************************************************/
void HAL_PMU_StandbyWakeupRTCConfig(PMU_WakeUpRtc_t wakeup_rtc)
{
    switch (wakeup_rtc)    
    {
        case STANDBY_WAKEUP_WUTIE:
        case STANDBY_WAKEUP_STAMP2:
        case STANDBY_WAKEUP_STAMP1:
        case STANDBY_WAKEUP_32S:
        case STANDBY_WAKEUP_ALARM:
        case STANDBY_WAKEUP_1KHZ:
        case STANDBY_WAKEUP_256HZ:
        case STANDBY_WAKEUP_64HZ:
        case STANDBY_WAKEUP_16HZ:
        case STANDBY_WAKEUP_8HZ:
        case STANDBY_WAKEUP_4HZ:
        case STANDBY_WAKEUP_2HZ:  
        case STANDBY_WAKEUP_SEC:
        case STANDBY_WAKEUP_MIN:
        case STANDBY_WAKEUP_HOUR:
        case STANDBY_WAKEUP_DATE:        
        {	
            //PMU CLK Enable
            __HAL_RCC_PMU_IS_CLK_ENABLE();

            //Clear flags
            SET_BIT(PMU->STCLR, (PMU_SRCLR_CWUPFX_Msk | PMU_SRCLR_CSBF_Msk));

            //disable wakeup io
            PMU->CTRL2 &= ~(PMU_CTL2_EWUPX_Msk | PMU_CTL2_WUXFILEN_Msk);

            RTC->SR |= wakeup_rtc;
            RTC->IE |= wakeup_rtc;

        }break;

        default: break; 
    }
}

/*********************************************************************************
* @brief : Check MCU have entered standby mode
* @param : none 
* @return: 0: Not Enter Standby Mode,1: Entered Standby Mode
**********************************************************************************/
bool HAL_RTC_GetStandbyStatus(void)
{
    if (PMU->SR & PMU_SR_SBF_Msk) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/******************************************************************************
* @brief : Get MCU Standby Wakeup Source.
* @param : none 
* @return: Wakeup Source(PMU_SR_WUPFX_WKUP1¡¢PMU_SR_WUPFX_WKUP2 ...)
******************************************************************************/
uint32_t HAL_PMU_GetStandbyWakeupSource(void)
{
    return PMU->SR;
}



#endif






