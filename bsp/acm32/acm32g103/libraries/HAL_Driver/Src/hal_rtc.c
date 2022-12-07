
/******************************************************************************
* @file      : HAL_RTC.c
* @version   : 1.0
* @date      : 2022.10.25
* @brief     : RTC HAL module driver
*   
* @history   :	
*   2022.10.25    lwq    create
*   
******************************************************************************/
#include "hal.h"

#ifdef HAL_RTC_MODULE_ENABLED



/******************************************************************************
* @brief : Initialize the RTC peripheral.
* @param : hrtc: Pointer to a RTC_ConfigTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RTC_Config(RTC_ConfigTypeDef *hrtc)
{
    /* Check RTC Parameter */
    assert_param(IS_RTC_CLOCKSRC(hrtc->ClockSource));
    assert_param(IS_RTC_COMPENSATION(hrtc->Compensation));

    //Enable PMU CLK
    __HAL_RCC_PMU_CLK_ENABLE();		
    //Enable RTC CLK
    __HAL_RCC_RTC_CLK_ENABLE();
    //Standby power field soft reset
    SET_BIT(RCC->STDBYCTRL, RCC_STDBYCTRL_STDBYRST);
    //Enable RTC CLK 
    SET_BIT(RCC->STDBYCTRL, RCC_STDBYCTRL_RTCEN);
    /* RTC domain write enable */
    SET_BIT(PMU->CTRL0,PMU_CTL0_RTC_WE);

    switch (hrtc->ClockSource)
    {
        case RTC_CLOCK_RC32K: 
        {
            //RC32K Enable
            RCC->STDBYCTRL |= RCC_STDBYCTRL_RC32EN;
            while(!(RCC->STDBYCTRL & RCC_STDBYCTRL_RC32KRDY));			
            //RTC SEL RC32K
            RCC->STDBYCTRL &= ~RCC_STDBYCTRL_RTCSEL;

        }break;

        case RTC_CLOCK_XTL: 
        {
            RCC->STDBYCTRL = (RCC->STDBYCTRL & ~RCC_STDBYCTRL_XTLDRV) | (RCC_STDBYCTRL_XTLDRV_1 | RCC_STDBYCTRL_XTLDRV_0);

            RCC->STDBYCTRL |= RCC_STDBYCTRL_XTLEN;
            while(!(RCC->STDBYCTRL & RCC_STDBYCTRL_XTLRDY));

            //RTC SEL XTL
            RCC->STDBYCTRL |= RCC_STDBYCTRL_RTCSEL_0;
        }break;

        default: break; 
    }

    if (hrtc->CompensationValue) 
    {
        RTC->ADJUST = hrtc->Compensation | hrtc->CompensationValue;
    }

    return HAL_OK;
}

/******************************************************************************
* @brief : Set RTC current time.
* @param : time: Pointer to RTC_TimeTypeDef structure
* @return: none
******************************************************************************/
void HAL_RTC_SetTime(RTC_TimeTypeDef *time)
{
    /* Check RTC Parameter */
    assert_param(IS_RTC_HOUR(time->Hour));
    assert_param(IS_RTC_MIN(time->Minute));
    assert_param(IS_RTC_SEC(time->Second));


    /* Write-Protect Disable */
    RTC->WP = 0xCA53CA53;

    RTC->HOUR = time->Hour;
    RTC->MIN  = time->Minute;
    RTC->SEC  = time->Second;


    /* Write-Protect Enable */
    RTC->WP = 0;
}

/******************************************************************************
* @brief : Get RTC current time.
* @param : time: Pointer to RTC_TimeTypeDef structure
* @return: none
******************************************************************************/
void HAL_RTC_GetTime(RTC_TimeTypeDef *time)
{
    time->Hour   = RTC->HOUR;
    time->Minute = RTC->MIN;
    time->Second = RTC->SEC;
}


/******************************************************************************
* @brief : Set RTC current Date.
* @param : date: Pointer to RTC_DateTypeDef structure
* @return: none
******************************************************************************/
void HAL_RTC_SetDate(RTC_DateTypeDef *date)
{
    /* Check RTC Parameter */
    assert_param(IS_RTC_YEAR(date->Year));
    assert_param(IS_RTC_MONTH(date->Month));
    assert_param(IS_RTC_DAY(date->Date));
    assert_param(IS_RTC_WEEKDAY(date->WeekDay));


    /* Write-Protect Disable */
    RTC->WP = 0xCA53CA53;

    RTC->YEAR  = date->Year;
    RTC->MONTH = date->Month;
    RTC->DATE  = date->Date;
    RTC->WEEK  = date->WeekDay;
	

    /* Write-Protect Enable */
    RTC->WP = 0;
}

/******************************************************************************
* @brief : Get RTC current Date.
* @param : date: Pointer to RTC_DateTypeDef structure
* @return: none
******************************************************************************/
void HAL_RTC_GetDate(RTC_DateTypeDef *date)
{
    date->Year    = RTC->YEAR;
    date->Month   = RTC->MONTH;
    date->Date    = RTC->DATE;
    date->WeekDay = RTC->WEEK;
}

/******************************************************************************
* @brief : Alarm Config.
* @param : alarm: Pointer to RTC_AlarmTypeDef structure.
* @return: none
******************************************************************************/
void HAL_RTC_AlarmConfig(RTC_AlarmTypeDef *alarm)
{
    uint32_t lu32_WeekDay;
    
    /* Check RTC Parameter */
    assert_param(IS_RTC_ALARM_MODE(alarm->u32_AlarmMode));
    assert_param(IS_RTC_ALARM_INT(alarm->u32_AlarmInterrupt));
    assert_param(IS_RTC_ALARM_DAY_MASK(alarm->u32_DayMask));
    assert_param(IS_RTC_ALARM_HOUR_MASK(alarm->u32_HourMask));
    assert_param(IS_RTC_ALARM_MIN_MASK(alarm->u32_MinMask));    
    assert_param(IS_RTC_HOUR(alarm->u32_Hours));
    assert_param(IS_RTC_MIN(alarm->u32_Minutes));
    assert_param(IS_RTC_SEC(alarm->u32_Seconds));
    
    if (alarm->u32_AlarmMode == RTC_ALM_ALM_WDS_WEEK) 
    {
        assert_param(IS_RTC_ALARM_WEEKDAY(alarm->u32_AlarmWeek));
        lu32_WeekDay = alarm->u32_AlarmWeek;
    }
    else 
    {
        assert_param(IS_RTC_DAY(alarm->u32_AlarmDay));
        lu32_WeekDay = alarm->u32_AlarmDay << RTC_ALM_ALMDAY_Pos;
    }
    
    /* Coinfig Week/Day¡¢Hour¡¢Min¡¢Sec */
    RTC->ALM = alarm->u32_AlarmMode | lu32_WeekDay | alarm->u32_Hours << RTC_ALM_ALMHOUR_Pos | alarm->u32_Minutes << RTC_ALM_ALMMIN_Pos | alarm->u32_Seconds;

    /* Interrupt Enable */
    if (RTC_ALARM_INT_ENABLE == alarm->u32_AlarmInterrupt) 
    {
        RTC->IE |= RTC_IE_ALM;
    }

    MODIFY_REG(RTC->CR, RTC_CR_ALM_MKSD, alarm->u32_DayMask); 
    
    MODIFY_REG(RTC->CR, RTC_CR_ALM_MSKH, alarm->u32_HourMask); 
    
    MODIFY_REG(RTC->CR, RTC_CR_ALM_MSKM, alarm->u32_MinMask); 
}

/******************************************************************************
* @brief : Alarm Enable.
* @param : none.
* @return: none
******************************************************************************/
void HAL_RTC_AlarmEnable(void)
{
    RTC->CR |= RTC_CR_ALM_EN;
}

/******************************************************************************
* @brief : Alarm Disable.
* @param : none.
* @return: none
******************************************************************************/
void HAL_RTC_AlarmDisable(void)
{
    RTC->CR &= ~RTC_CR_ALM_EN;
}


/******************************************************************************
* @brief : RTC Tamper Config.
* @param : temperx: RTC_TEMPER_1 or RTC_TEMPER_2 
* @param : temper: Pointer to RTC_TemperTypeDef structure
* @return: none
******************************************************************************/
void HAL_RTC_Tamper(RTC_Temper_t temperx, RTC_TemperTypeDef *temper)
{

    /* Check RTC Parameter */
    assert_param(IS_RTC_TEMP_EDGE(temper->u32_TemperEdge));
    assert_param(IS_RTC_TEMP_INT(temper->u32_InterruptEN));
    assert_param(IS_RTC_TEMP_CLEAR_BACKUP(temper->u32_ClearBackup));
    assert_param(IS_RTC_TEMP_FILTER(temper->u32_Filter));

    switch (temperx)
    {
        case RTC_TEMPER_1: 
        {
            /* RTC domain write enable */
            SET_BIT(PMU->CTRL0,PMU_CTL0_RTC_WE);
            
            /* Configure PC13 as tamper function */ 
            __HAL_PMU_PC13_SEL(PMU_IOSEL_PC13_SEL_RTC_TAMPER);            
            
            /* Clear Config */
            RTC->CR &= ~(RTC_CR_TAMP1RCLR | RTC_CR_TAMP1FCLR | RTC_CR_TAMP1FLTEN | RTC_CR_TAMP1FLT_Msk | RTC_CR_TS1EDGE | RTC_CR_TAMPFLTCLK_Msk);
			
            /* Edge select */
            RTC->CR |= temper->u32_TemperEdge ? RTC_CR_TS1EDGE : 0x00;
            /* Auto clear backup register */
            if (temper->u32_ClearBackup) 
            {
                RTC->CR |= temper->u32_TemperEdge ? RTC_CR_TAMP1FCLR : RTC_CR_TAMP1RCLR;
            }
            /* Temper filter clock*/
            RTC->CR |= temper->u32_FilterClk; 

            /* Temper filter */
            RTC->CR |= temper->u32_Filter << RTC_CR_TAMP1FLT_Pos;

            RTC->CR |= RTC_CR_TAMP1EN;  
            
            HAL_SimpleDelay(2000);  
            
            RTC->SR |= (RTC_SR_STP1FIE | RTC_SR_STP1RIE);   
            RTC->IE &= (~(RTC_IE_STP1FIE | RTC_IE_STP1RIE));      
            
            /* Put Temper Interrupt enable here !!!*/   
            if (temper->u32_InterruptEN) 
            {
                RTC->IE |= temper->u32_TemperEdge ? RTC_IE_STP1FIE : RTC_IE_STP1RIE;
            }               
 
        }break;
        
        case RTC_TEMPER_2:
        {
            /* RTC domain write enable */
            SET_BIT(PMU->CTRL0,PMU_CTL0_RTC_WE);
            /* Clear Config */
            RTC->CR &= ~(RTC_CR_TAMP2RCLR | RTC_CR_TAMP2FCLR | RTC_CR_TAMP2FLTEN | RTC_CR_TAMP2FLT_Msk | RTC_CR_TS2EDGE | RTC_CR_TAMPFLTCLK_Msk);
            
            RTC->CR |= RTC_CR_TAMP2FLTEN;
            /* Edge select */
            RTC->CR |= temper->u32_TemperEdge ? RTC_CR_TS2EDGE : 0x00;
            /* Auto clear backup register */
            if (temper->u32_ClearBackup) 
            {
                RTC->CR |= temper->u32_TemperEdge ? RTC_CR_TAMP2FCLR : RTC_CR_TAMP2RCLR;
            }
            
            /* Temper filter clock*/
            RTC->CR |= temper->u32_FilterClk;
            
            /* Temper filter */
            RTC->CR |= temper->u32_Filter << 19;
                
            RTC->CR |= RTC_CR_TAMP2EN;
            
            HAL_SimpleDelay(2000);   
            
            RTC->SR |= (RTC_SR_STP2FIE|RTC_SR_STP2RIE);   
            RTC->IE &= (~(RTC_IE_STP2FIE|RTC_IE_STP2RIE));  
            
            /* Temper Interrupt */
            if (temper->u32_InterruptEN) 
            {
                RTC->IE |= temper->u32_TemperEdge ? RTC_IE_STP2FIE : RTC_IE_STP2RIE;
            }

        }break;

        default: break; 
    }
}

/******************************************************************************
* @brief : RTC Tamper Enable.
* @param : temperx: RTC_TEMPER_1 or RTC_TEMPER_2 
* @return: none
******************************************************************************/
void HAL_RTC_TamperEnable(RTC_Temper_t temperx)
{
    if (temperx == RTC_TEMPER_1) 
    {
        RTC->CR |= RTC_CR_TAMP1EN;
    }
    else 
    {
        RTC->CR |= RTC_CR_TAMP2EN;
    }
}

/******************************************************************************
* @brief : RTC Tamper Disable.
* @param : temperx: RTC_TEMPER_1 or RTC_TEMPER_2 
* @return: none
******************************************************************************/
void HAL_RTC_TamperDisable(RTC_Temper_t temperx)
{
    if (temperx == RTC_TEMPER_1) 
    {
        RTC->CR &= ~RTC_CR_TAMP1EN;
    }
    else 
    {
        RTC->CR &= ~RTC_CR_TAMP2EN;
    }
}

/******************************************************************************
* @brief : Sets wakeup timer.
* @param : hrtcTimer: pointer to a RTC_HandleTypeDef structure 
* @return: none
******************************************************************************/
void HAL_RTC_SetWakeUpTimer(RTC_WUTimerTypeDef *hrtcTimer)
{
	
    //Disable WakeUp Timer
    RTC->CR &= ~RTC_CR_WUTE;

    while(!(RTC->SR & RTC_SR_WUTWF));

    RTC->WUTR =hrtcTimer->WakeUpCounter;

    RTC->CR |= hrtcTimer->u32_WuckSel;

    //Enable Wakeup Timer
    RTC->CR |= RTC_CR_WUTE;
    while(!(RTC->SR & RTC_SR_WUTWF));

}


#endif




