
/******************************************************************************
*@file  : hal_rcc.c
*@brief : RCC HAL module driver.
******************************************************************************/

#include "hal.h"

#ifdef HAL_RCC_MODULE_ENABLED


/******************************************************************************
*@brief : Initializes the RCC Oscillators according to the specified parameters
*         in the RCC_OscInitTypeDef.
*@param : RCC_OscInit: pointer to an RCC_OscInitTypeDef structure that contains 
*         the configuration information for the RCC Oscillators.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInit)
{
    volatile uint32_t temp;
    uint32_t startTick;
    uint32_t timeout;
    uint32_t changed;
    
    /* Check the parameters */
    assert_param(IS_RCC_OSC_OSCTYPE(RCC_OscInit->OscType));
    
    HAL_EFLASH_SET_RDWAIT(EFLASH_RDWAIT_ENSURE_OK);
    
    changed = 0;
    
    /*------------------------------- RC64M Configuration ------------------------*/
    if (RCC_OscInit->OscType & RCC_OSCTYPE_RC64M)
    {
        /* Check the parameters */
        assert_param(IS_RCC_OSC_RC64M(RCC_OscInit->RC64M));
        
        /* check whether the current configured clock is the system clock */
        if ((RCC->CCR1 & RCC_CCR1_SYSCLKSEL_Msk) == RCC_SYSCLKSOURCE_RC64M)
            changed = 1;
        
        if (RCC_OscInit->RC64M != DISABLE)
        {
            /* Check the parameters */
            assert_param(IS_RCC_OSC_RC64MD_DIV16(RCC_OscInit->RC64MDiv16));
            
            /* 16 frequency division configuration */
            /* If RC64M is selected for PLL source, RC64M will force 16 frequency division */
            temp = RCC->RC64MCR;
            temp &= ~RCC_RC64MCR_RC64MDIV_Msk;
            if ((RCC_OscInit->RC64MDiv16 != DISABLE) || \
                ((RCC_OscInit->PLL.PLL != DISABLE) && (RCC_OscInit->PLL.PLLSource == RCC_PLLSOURCE_RC64M_DIV16)))
            {
                temp |= RCC_RC64M_DIV_16;
            }
            temp |= RCC_RC64MCR_RC64MEN;                /* enable RC64M */
            RCC->RC64MCR = temp;
            
            /* Wait till RC64M is ready */
            timeout = RCC_RC64M_TIMEOUT;
            while (!(__HAL_RCC_RC64M_ISREADY()))
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
        else
        {
            /* disable RC64M */
            __HAL_RCC_RC64M_DISABLE();
            
            /* Wait till RC64M is disabled */
            timeout = RCC_RC64M_TIMEOUT;
            while (__HAL_RCC_RC64M_ISREADY())
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
    }
    
    /*------------------------------- RC32K Configuration ------------------------*/
    if (RCC_OscInit->OscType & RCC_OSCTYPE_RC32K)
    {
        /* Check the parameters */
        assert_param(IS_RCC_OSC_RC32K(RCC_OscInit->RC32K));
        
        /* check whether the current configured clock is the system clock */
        if ((RCC->CCR1 & RCC_CCR1_SYSCLKSEL_Msk) == RCC_SYSCLKSOURCE_RC32K)
            changed = 1;
        
        if (RCC_OscInit->RC32K != DISABLE)
        {
            /* enable RC32K */
            __HAL_RCC_RC32K_ENABLE();
            
            /* Wait till RC32K is ready */
            timeout = RCC_RC32K_TIMEOUT;
            while (!(__HAL_RCC_RC32K_ISREADY()))
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
        else
        {
            /* disable RC32K */
            __HAL_RCC_RC32K_DISABLE();
            
            /* Wait till RC32K is disabled */
            timeout = RCC_RC32K_TIMEOUT;
            while (__HAL_RCC_RC32K_ISREADY())
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
    }
    
    /*------------------------------- XTH Configuration ------------------------*/
    if (RCC_OscInit->OscType & RCC_OSCTYPE_XTH)
    {
        /* Check the parameters */
        assert_param(IS_RCC_OSC_XTH(RCC_OscInit->XTH));
        assert_param(IS_RCC_OSC_XTH_BYPASS(RCC_OscInit->XTHBypass));
        
        /* check whether the current configured clock is the system clock */
        if ((RCC->CCR1 & RCC_CCR1_SYSCLKSEL_Msk) == RCC_SYSCLKSOURCE_XTH)
            changed = 1;
        
        if (RCC_OscInit->XTH != DISABLE)
        {
            /* Check the parameters */
            assert_param(IS_RCC_OSC_XTH_BYPASS(RCC_OscInit->XTHBypass));
            
            temp = RCC->XTHCR;
            
            /* XTH oscillator bypass configuration */
            temp &= ~RCC_XTHCR_XTHBYP;
            if (RCC_OscInit->XTHBypass != DISABLE)
                temp |= RCC_XTHCR_XTHBYP;
            
            /* XTH stability time : 32768 clocks */
            temp &= ~RCC_XTHCR_XTHRDYTIME_Msk;
            temp |= RCC_XTH_STABILITY_32768;
            
            /* enable XTH */
            temp |= RCC_XTHCR_XTHEN;
            
            RCC->XTHCR = temp;
            
            /* Wait till XTH is ready */
            timeout = RCC_XTH_TIMEOUT;
            while (!(__HAL_RCC_XTH_ISREADY()))
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
        else
        {
            /* disable XTH */
            temp = RCC->XTHCR;
            temp &= ~(RCC_XTHCR_XTHBYP | RCC_XTHCR_XTHRDYTIME_Msk | RCC_XTHCR_XTHEN);
            RCC->XTHCR = temp;
            
            /* Wait till XTH is disabled */
            timeout = RCC_XTH_TIMEOUT;
            while (__HAL_RCC_XTH_ISREADY())
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
    }
    
    /*------------------------------- XTL Configuration ------------------------*/
    if (RCC_OscInit->OscType & RCC_OSCTYPE_XTL)
    {
        /* Check the parameters */
        assert_param(IS_RCC_OSC_XTL(RCC_OscInit->XTL));
        
        /* check whether the current configured clock is the system clock */
        if ((RCC->CCR1 & RCC_CCR1_SYSCLKSEL_Msk) == RCC_SYSCLKSOURCE_XTL)
            changed = 1;
        
        if (RCC_OscInit->XTL != DISABLE)
        {
            /* Check the parameters */
            assert_param(IS_RCC_OSC_XTL_BYPASS(RCC_OscInit->XTLBypass));
            assert_param(IS_RCC_OSC_XTL_DRIVE(RCC_OscInit->XTLDrive));
            
            temp = RCC->STDBYCTRL;
            temp &= ~(RCC_STDBYCTRL_XTLBYP | RCC_STDBYCTRL_XTLDRV_Msk);
            
            /* XTL oscillator bypass configuration */
            if (RCC_OscInit->XTLBypass != DISABLE)
                temp |= RCC_STDBYCTRL_XTLBYP;
            /* driving capacity configuration */
            temp |= RCC_OscInit->XTLDrive;
            
            /* enable XTL */
            temp |= RCC_STDBYCTRL_XTLEN;
            
            RCC->STDBYCTRL = temp;
            
            /* Wait till XTL is ready */
            timeout = RCC_XTL_TIMEOUT;
            while (!(__HAL_RCC_XTL_ISREADY()))
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
        else
        {
            /* disable XTL */
            temp = RCC->STDBYCTRL;
            temp &= ~(RCC_STDBYCTRL_XTLBYP_Msk | RCC_STDBYCTRL_XTLDRV_Msk | RCC_STDBYCTRL_XTLEN_Msk);
            RCC->STDBYCTRL = temp;
            
            /* Wait till XTL is disabled */
            timeout = RCC_XTL_TIMEOUT;
            while (__HAL_RCC_XTL_ISREADY())
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
    }
    
    /*------------------------------- PLL Configuration ------------------------*/
    if (RCC_OscInit->OscType & RCC_OSCTYPE_PLL)
    {
        /* Check the parameters */
        assert_param(IS_RCC_PLL_PLL(RCC_OscInit->PLL.PLL));
        
        /* check whether the current configured clock is the system clock */
        if ((RCC->CCR1 & RCC_CCR1_SYSCLKSEL_Msk) == RCC_SYSCLKSOURCE_PLLCLK)
            changed = 1;
        
        if (RCC_OscInit->PLL.PLL == DISABLE)
        {
            /* disable PLL */
            __HAL_RCC_PLL_DISABLE();
            
            /* Wait till PLL is disabled */
            timeout = RCC_PLL_TIMEOUT;
            while (__HAL_RCC_PLL_ISREADY())
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
        else
        {
            /* Check the parameters */
            assert_param(IS_RCC_PLL_PLLSOURCE(RCC_OscInit->PLL.PLLSource));
            assert_param(IS_RCC_PLL_PLLM(RCC_OscInit->PLL.PLLM));
            assert_param(IS_RCC_PLL_PLLN(RCC_OscInit->PLL.PLLN));
            assert_param(IS_RCC_PLL_PLLF(RCC_OscInit->PLL.PLLF));
        
            /* enable PLL */
            __HAL_RCC_PLL_ENABLE();
            
            /* exit sleep mode */
            __HAL_RCC_PLLSLEEP_DISABLE();
            
            /* Wait till PLL is ready */
            timeout = RCC_PLL_TIMEOUT;
            while (!(__HAL_RCC_PLL_ISREADY()))
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
            
            /* config: pll clock source and PLLM¡¢PLLN¡¢PLLF */
            temp = RCC->PLLCR;
            temp &= ~(RCC_PLLCR_PLLSRCSEL_Msk | RCC_PLLCR_PLLM_Msk | RCC_PLLCR_PLLN_Msk | RCC_PLLCR_PLLF_Msk);
            temp |= RCC_OscInit->PLL.PLLSource | ((RCC_OscInit->PLL.PLLM << RCC_PLLCR_PLLM_Pos) & RCC_PLLCR_PLLM_Msk) | \
                                                 ((RCC_OscInit->PLL.PLLN << RCC_PLLCR_PLLN_Pos) & RCC_PLLCR_PLLN_Msk) | \
                                                 ((RCC_OscInit->PLL.PLLF << RCC_PLLCR_PLLF_Pos) & RCC_PLLCR_PLLF_Msk);
            RCC->PLLCR = temp;
            
            /* update pll */
            __HAL_RCC_PLLUPDATE();
            
            /* Wait till PLL is ready */
            timeout = RCC_PLL_TIMEOUT;
            while (!(__HAL_RCC_PLL_ISREADY()))
            {
                if (timeout-- == 0)
                    return (HAL_TIMEOUT);
            }
        }
    }
    
    /*------------------------------- Update Tick ------------------------------*/
    if (changed)
    {
        g_SystemCoreClock = HAL_RCC_GetSysCoreClockFreq();
        
        HAL_EFLASH_SetRdwaitBySysCoreClock(g_SystemCoreClock);
        
        HAL_InitTick(g_systickHandle.intPrio,g_systickHandle.msPeriod);
    
    }
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Initializes the CPU, AHB and APB buses clocks according to the 
*         specified parameters in the RCC_ClkInitTypeDef.
*@param : RCC_ClkInit: pointer to an RCC_ClkInitTypeDef structure that
*         contains the configuration information for the RCC peripheral.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInit)
{
    uint32_t temp;
    uint32_t timeout;
    
    /* Check the parameters */
    assert_param(IS_RCC_OSC_SYSCLK_SOURCE(RCC_ClkInit->SYSCLKSource));
    assert_param(IS_RCC_OSC_SYSCLK_DIV0(RCC_ClkInit->SYSCLKDiv0));
    assert_param(IS_RCC_OSC_SYSCLK_DIV1(RCC_ClkInit->SYSCLKDiv1));
    assert_param(IS_RCC_OSC_PCLK1_DIV(RCC_ClkInit->PCLK1Div));
    assert_param(IS_RCC_OSC_PCLK2_DIV(RCC_ClkInit->PCLK2Div));
    
    HAL_EFLASH_SET_RDWAIT(EFLASH_RDWAIT_ENSURE_OK);
    
    /* system clok source configuration */
    temp = RCC->CCR1;
    temp &= ~RCC_CCR1_SYSCLKSEL_Msk;
    temp |= RCC_ClkInit->SYSCLKSource;
    RCC->CCR1 = temp;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    /* first level frequency division of system clock */
    temp = RCC->CCR2;
    temp &= ~RCC_CCR2_SYSDIV0_Msk;
    temp |= RCC_ClkInit->SYSCLKDiv0;
    RCC->CCR2 = temp;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    /* second level frequency division of system clock */
    temp = RCC->CCR2;
    temp &= ~RCC_CCR2_SYSDIV1_Msk;
    temp |= RCC_ClkInit->SYSCLKDiv1;
    RCC->CCR2 = temp;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    /* frequency division of PCLK1 and PCLK2 clock */
    temp = RCC->CCR2;
    temp &= ~(RCC_CCR2_PCLK1DIV_Msk | RCC_CCR2_PCLK2DIV_Msk);
    temp |= RCC_ClkInit->PCLK1Div | RCC_ClkInit->PCLK2Div;
    RCC->CCR2 = temp;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    g_SystemCoreClock = HAL_RCC_GetSysCoreClockFreq();
    
    HAL_EFLASH_SetRdwaitBySysCoreClock(g_SystemCoreClock);
    
    HAL_InitTick(g_systickHandle.intPrio,g_systickHandle.msPeriod);
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Switch the system clock.
*@param : SYSCLKSource: SYSCLK clock source.
*         This parameter must be a value of @ref RCC_Sysclk_Source.
*             @arg RCC_SYSCLKSOURCE_RC64M: RC64M clock selected as SYSCLK source
*             @arg RCC_SYSCLKSOURCE_RC32K: RC32K clock selected as SYSCLK source
*             @arg RCC_SYSCLKSOURCE_XTH: XTH clock selected as SYSCLK source
*             @arg RCC_SYSCLKSOURCE_XTL: XTL clock selected as SYSCLK source
*             @arg RCC_SYSCLKSOURCE_PLLCLK: PLL clock selected as SYSCLK source
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RCC_SwitchSYSCLK(uint32_t SYSCLKSource)
{
    uint32_t temp;
    uint32_t timeout;
    
    /* Check the parameters */
    assert_param(IS_RCC_OSC_SYSCLK_SOURCE(SYSCLKSource));
    
    HAL_EFLASH_SET_RDWAIT(EFLASH_RDWAIT_ENSURE_OK);
    
    if (SYSCLKSource == RCC_SYSCLKSOURCE_RC64M)
    {
        /* Check whether the RC64M clock is turned on and running stably */
        if ((RCC->RC64MCR & (RCC_RC64MCR_RC64MDIV | RCC_RC64MCR_RC64MRDY)) == 0U)
            return HAL_ERROR;
    }
    else if (SYSCLKSource == RCC_SYSCLKSOURCE_RC32K)
    {
        /* Check whether the RC32K clock is turned on and running stably */
        if ((RCC->STDBYCTRL & (RCC_STDBYCTRL_RC32EN | RCC_STDBYCTRL_RC32KRDY)) == 0U)
            return HAL_ERROR;
    }
    else if (SYSCLKSource == RCC_SYSCLKSOURCE_XTH)
    {
        /* Check whether the XTH clock is turned on and running stably */
        if ((RCC->XTHCR & (RCC_XTHCR_XTHEN | RCC_XTHCR_XTHRDY)) == 0U)
            return HAL_ERROR;
    }
    else if (SYSCLKSource == RCC_SYSCLKSOURCE_XTL)
    {
        /* Check whether the XTL clock is turned on and running stably */
        if ((RCC->STDBYCTRL & (RCC_STDBYCTRL_XTLEN | RCC_STDBYCTRL_XTLRDY)) == 0U)
            return HAL_ERROR;
    }
    else if (SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {
        /* Check whether the PLL clock is turned on and running stably */
        if ((RCC->PLLCR & (RCC_PLLCR_PLLEN | RCC_PLLCR_PLLFREERUN)) == 0U)
            return HAL_ERROR;
    }
    
    /* system clok source configuration */
    temp = RCC->CCR1;
    temp &= ~RCC_CCR1_SYSCLKSEL_Msk;
    temp |= SYSCLKSource;
    RCC->CCR1 = temp;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    g_SystemCoreClock = HAL_RCC_GetSysCoreClockFreq();
    
    HAL_EFLASH_SetRdwaitBySysCoreClock(g_SystemCoreClock);
    
    HAL_InitTick(g_systickHandle.intPrio,g_systickHandle.msPeriod);
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Configure LPTIM1 clock source.
*@param : clkSource: LPTIM1 clock source.
*         This parameter must be a value of @ref RCC_LPTIM1_CLK_Source.
*             @arg RCC_LPTIM1CLKSOURCE_PCLK: PCLK clock selected as PLTIM1 source
*             @arg RCC_LPTIM1CLKSOURCE_RC32K: RC32K clock selected as PLTIM1 source
*             @arg RCC_LPTIM1CLKSOURCE_RC64M: RC64M clock selected as PLTIM1 source
*             @arg RCC_LPTIM1CLKSOURCE_XTL: XTL clock selected as PLTIM1 source
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RCC_LPTIM1ClockConfig(uint32_t clkSource)
{
    uint32_t temp;
    uint32_t timeout;
    
    /* Check the parameters */
    assert_param(IS_RCC_LPTIM1_CLKSOURCE(clkSource));
    
    /* LPTIM1 clok source configuration */
    temp = RCC->CCR2;
    temp &= ~RCC_CCR2_LPTLCKSEL_Msk;
    temp |= clkSource;
    temp = RCC->CCR2;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Configure FLTCLK (LVD and COMP clock) source.
*@param : clkSource: LVD and COMP clock source.
*         This parameter must be a value of @ref RCC_FLT_CLK_Source.
*             @arg RCC_FLTCLKSOURCE_PCLK_DIV32: clock after pclk 32 frequency division selected as FLTCLK source
*             @arg RCC_FLTCLKSOURCE_RC32K: RC32K clock selected as FLTCLK source
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RCC_FLTClockConfig(uint32_t clkSource)
{
    uint32_t temp;
    uint32_t timeout;
    
    /* Check the parameters */
    assert_param(IS_RCC_FLTCLK_CLKSOURCE(clkSource));
    
    /* FLTCLK clok source configuration */
    temp = RCC->CCR2;
    temp &= ~RCC_CCR2_FLTCLKSEL_Msk;
    temp |= clkSource;
    temp = RCC->CCR2;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Configure LPUART1 clock source.
*@param : clkSource: LPUART1 clock source.
*         This parameter must be a value of @ref RCC_LPUART1_CLK_Source.
*             @arg RCC_LPUART1CLKSOURCE_RC32K: RC32K clock selected as LPUART1 source
*             @arg RCC_LPUART1CLKSOURCE_XTL: XTL clock selected as LPUART1 source
*             @arg RCC_LPUART1CLKSOURCE_PCLK_DIV4: clock after pclk 4 frequency division selected as LPUART1 source
*             @arg RCC_LPUART1CLKSOURCE_PCLK_DIV8: clock after pclk 8 frequency division selected as LPUART1 source
*             @arg RCC_LPUART1CLKSOURCE_PCLK_DIV16: clock after pclk 16 frequency division selected as LPUART1 source
*             @arg RCC_LPUART1CLKSOURCE_PCLK_DIV32: clock after pclk 32 frequency division selected as LPUART1 source
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_RCC_LPUART1ClockConfig(uint32_t  clkSource)
{
    uint32_t temp;
    uint32_t timeout;
    
    /* Check the parameters */
    assert_param(IS_RCC_LPUART1_CLKSOURCE(clkSource));
    
    /* LPUART1 clok source configuration */
    temp = RCC->CCR2;
    temp &= ~(RCC_CCR2_LPUCLKSEL_Msk | RCC_CCR2_LPUARTDIV_Msk);
    temp |= clkSource;
    temp = RCC->CCR2;
    
    /* Wait till the update frequency division to complete */
    timeout = RCC_DIV_TIMEOUT;
    while ((RCC->CCR2 & RCC_FLAG_DIV_DONE) == 0)
    {
        if (timeout-- == 0)
            return (HAL_TIMEOUT);
    }
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Configure MCO output.
*@param : MCO_Init: pointer to an RCC_MCOInitTypeDef structure that contains 
*         the configuration information for the MCO output.
*@return: HAL status
******************************************************************************/
uint32_t HAL_RCC_MCOConfig(RCC_MCOInitTypeDef *MCO_Init)
{
    uint32_t temp;
    
    /* Check the parameters */
    assert_param(IS_RCC_MCO_OUTPUT(MCO_Init->Output));
    
    if (MCO_Init->Output == RCC_MCO_NONE)
    {
        RCC->CLKOCR = MCO_Init->Output;
        
        return HAL_OK;
    }
    
    assert_param(IS_RCC_MCO1(MCO_Init->MCO1));
    assert_param(IS_RCC_MCO2(MCO_Init->MCO2));
    
    temp = 0;
    
    if (MCO_Init->MCO1 != DISABLE)
    {
        assert_param(IS_RCC_MCO1_DIV(MCO_Init->MCO1Div));
        assert_param(IS_RCC_MCO1_REVPOL(MCO_Init->MCO1RevPol));
        
        temp |= RCC_CLKOCR_BUZZER1EN;
        
        /* MCO1 clock polarity configuration */
        if (MCO_Init->MCO1RevPol != DISABLE)
            temp |= RCC_CLKOCR_BUZZER1POL;
        
        /* MCO1 division configuration */
        temp |= (MCO_Init->MCO1Div << RCC_CLKOCR_BUZZER1DIV_Pos) & RCC_CLKOCR_BUZZER1DIV_Msk;
    }
    
    if (MCO_Init->MCO2 != DISABLE)
    {
        assert_param(IS_RCC_MCO2_DIV(MCO_Init->MCO2Div));
        assert_param(IS_RCC_MCO2_REVPOL(MCO_Init->MCO2RevPol));
        
        temp |= RCC_CLKOCR_BUZZER2EN;
        
        /* MCO2 clock polarity configuration */
        if (MCO_Init->MCO2RevPol != DISABLE)
            temp |= RCC_CLKOCR_BUZZER2POL;
        
        /* MCO2 division configuration */
        temp |= (MCO_Init->MCO2Div << RCC_CLKOCR_BUZZER2DIV_Pos) & RCC_CLKOCR_BUZZER2DIV_Msk;
    }
    
    temp |= MCO_Init->Output;
    
    /* MCO output source configuration */
    if ((MCO_Init->MCO1 != DISABLE) || (MCO_Init->MCO1 != DISABLE))
        temp |= RCC_CLKOCR_MCOSEL;
    
    RCC->CLKOCR = temp;
    
    return (HAL_OK);
}

/******************************************************************************
*@brief : Returns RC64M infact value
*@return: RC64M val
******************************************************************************/
uint32_t HAL_RCC_GetRC64MVal(void)
{
    uint32_t rc64mTrim,rc64mVal;    
    rc64mTrim = *(volatile uint32_t *)EFLASH_NVR2_RC64M_TRIM_ADDR;
    if((rc64mTrim>>16) == ((~rc64mTrim)&0xffff))
    {
        rc64mVal = *(volatile uint32_t *)EFLASH_NVR2_RC64M_VAL_ADDR * 16000U;
    }
    else
    {
        rc64mVal = 64000000;
    }  
    return rc64mVal;  
}

/******************************************************************************
*@brief : Returns RC32K infact value
*@return: RC32K val
******************************************************************************/
uint32_t HAL_RCC_GetRC32KVal(void)
{
    uint32_t rc32kTrim,rc32kVal;    
    rc32kTrim = *(volatile uint32_t *)EFLASH_NVR2_RC32K_TRIM_ADDR;
    if((rc32kTrim>>16) == ((~rc32kTrim)&0xffff))
    {
        rc32kVal = *(volatile uint32_t *)EFLASH_NVR2_RC32K_VAL_ADDR * 10U;
    }
    else
    {
        rc32kVal = 32000;
    }  
    return rc32kVal;  
}


/******************************************************************************
*@brief : Returns the SYSCLK frequency
*@return: SYSCLK frequency
******************************************************************************/
uint32_t HAL_RCC_GetSYSCLKFreq(void)
{
    uint32_t temp;
    uint32_t pllm;
    uint32_t plln;
    uint32_t pllf;
    uint32_t freq = 0U;
    uint32_t rc64mTrim,rc32kTrim;
    
    /* check system clock source */
    temp = RCC->CCR1 & RCC_CCR1_SYSCLKSEL_Msk;
    switch (temp)
    {
        case RCC_SYSCLKSOURCE_RC64M :       /* system clock source : RC64M */
            
            temp = RCC->RC64MCR & RCC_RC64MCR_RC64MDIV_Msk;
            switch (temp)
            {
                case RCC_RC64M_DIV_1 : 
                    
                    freq = HAL_RCC_GetRC64MVal();
                    break;
                
                case RCC_RC64M_DIV_16 : 
				
                    freq = HAL_RCC_GetRC64MVal() >> 4;
                    break;
                default : 
                   return (0U);
            }
            break;
            
        case RCC_SYSCLKSOURCE_RC32K :       /* system clock source : RC32K */
		
            freq = HAL_RCC_GetRC32KVal();
            break;
            
        case RCC_SYSCLKSOURCE_XTH :         /* system clock source : XTH */
            
            freq = XTH_VALUE;
            break;
            
        case RCC_SYSCLKSOURCE_XTL :         /* system clock source : XTL */
            
            freq = XTL_VALUE;
            break;
            
        case RCC_SYSCLKSOURCE_PLLCLK :      /* system clock source : PLLCLK */
        default :                           /* system clock source : PLLCLK */
            
            /* check PLL clock source */
            temp = RCC->PLLCR & RCC_PLLCR_PLLSRCSEL_Msk;
            switch (temp)
            {
                case RCC_PLLSOURCE_RC64M_DIV16 :  /* PLL clock source : RC64M div 16 */
				
                    freq = HAL_RCC_GetRC64MVal() >> 4;
                    break;
                
                case RCC_PLLSOURCE_XTH :    /* PLL clock source : XTH */
                    
                    freq = XTH_VALUE;
                    break;
                
                default : 
                   return (HAL_ERROR);
            }
            
            pllm = (RCC->PLLCR & RCC_PLLCR_PLLM_Msk) >> RCC_PLLCR_PLLM_Pos;
            plln = (RCC->PLLCR & RCC_PLLCR_PLLN_Msk) >> RCC_PLLCR_PLLN_Pos;
            pllf = (RCC->PLLCR & RCC_PLLCR_PLLF_Msk) >> RCC_PLLCR_PLLF_Pos;
            
            /* input frequency between 3MHz and 48MHz */
            if ((freq < 3000000U) || (freq > 48000000U))
                return (0U);
            
            /* (freq / (plln + 1)) frequency between 3MHz and 6MHz */
            temp = freq / (plln + 1);
            if ((temp < 3000000U) || (temp > 6000000U))
                return (0U);
            
            freq = freq * (pllf + 15) / (plln + 1);
            freq = freq >> pllm;
            break;
    }
    
    return (freq);
}

/******************************************************************************
*@brief : Returns the SysCoreClock frequency
*@return: SysCoreClock frequency
******************************************************************************/
uint32_t HAL_RCC_GetSysCoreClockFreq(void)
{
    uint32_t temp;
    uint32_t freq = 0U;
    
    freq = HAL_RCC_GetSYSCLKFreq();
    
    /* first level frequency division of system clock */
    temp = ((RCC->CCR2 & RCC_CCR2_SYSDIV0_Msk) >> RCC_CCR2_SYSDIV0_Pos) + 1;
    
    /* second level frequency division of system clock */
    temp = temp * (((RCC->CCR2 & RCC_CCR2_SYSDIV1_Msk) >> RCC_CCR2_SYSDIV1_Pos) + 1);
    
    freq = freq / temp;
    
    return (freq);
}

/******************************************************************************
*@brief : Returns the HCLK (AHB CLK) frequency
*@return: HCLK frequency
******************************************************************************/
uint32_t HAL_RCC_GetFCLKFreq(void)
{
    /* HCLK = SYSCLK */
    return g_SystemCoreClock;
}

/******************************************************************************
*@brief : Returns the HCLK (AHB CLK) frequency
*@return: HCLK frequency
******************************************************************************/
uint32_t HAL_RCC_GetHCLKFreq(void)
{
    /* HCLK = SYSCLK */
    return g_SystemCoreClock;
}


/******************************************************************************
*@brief : Returns the PCLK1 (APB1 CLK) frequency
*@return: PCLK1 frequency
******************************************************************************/
uint32_t HAL_RCC_GetPCLK1Freq(void)
{
    uint32_t div;
    uint32_t freq;
    
    /* get HCK frequency */
    freq = HAL_RCC_GetHCLKFreq();
    
    /* check PCLK1 division */
    div = RCC->CCR2 & RCC_CCR2_PCLK1DIV_Msk;
    switch (div)
    {
        case RCC_PCLK1_DIV_1 : 
            
            break;
        
        case RCC_PCLK1_DIV_2 : 
            
            freq = freq >> 1;
            break;
        
        case RCC_PCLK1_DIV_4 : 
            
            freq = freq >> 2;
            break;
        
        case RCC_PCLK1_DIV_8 : 
            
            freq = freq >> 3;
            break;
        
        case RCC_PCLK1_DIV_16 : 
            
            freq = freq >> 4;
            break;
        
        default :
            
            break;
    }
    
    return (freq);
}

/******************************************************************************
*@brief : Returns the PCLK2 (APB2 CLK) frequency
*@return: PCLK2 frequency
******************************************************************************/
uint32_t HAL_RCC_GetPCLK2Freq(void)
{
    uint32_t div;
    uint32_t freq;
    
    /* get HCK frequency */
    freq = HAL_RCC_GetHCLKFreq();
    
    /* check PCLK2 division */
    div = RCC->CCR2 & RCC_CCR2_PCLK2DIV_Msk;
    switch (div)
    {
        case RCC_PCLK2_DIV_1 : 
            
            break;
        
        case RCC_PCLK2_DIV_2 : 
            
            freq = freq >> 1;
            break;
        
        case RCC_PCLK2_DIV_4 : 
            
            freq = freq >> 2;
            break;
        
        case RCC_PCLK2_DIV_8 : 
            
            freq = freq >> 3;
            break;
        
        case RCC_PCLK2_DIV_16 : 
            
            freq = freq >> 4;
            break;
        
        default :
            
            break;
    }
    
    return (freq);
}

/******************************************************************************
*@brief : Returns the LPTIME1 clock frequency
*@return: LPTIME1 clock frequency
******************************************************************************/
uint32_t HAL_RCC_GetLPTIM1CLKFreq(void)
{
    uint32_t div;
    uint32_t source;
    uint32_t freq;
    
    /* check LPTIM1 clock source */
    source = RCC->CCR2 & RCC_CCR2_LPTLCKSEL_Msk;
    switch (source)
    {
        case RCC_LPTIM1CLKSOURCE_PCLK :             /* LPTIM1 clock source : PCLK */
            
            freq = HAL_RCC_GetPCLK1Freq();
            break;
        
        case RCC_LPTIM1CLKSOURCE_RC32K :            /* LPTIM1 clock source : RC32K */
            
            freq = HAL_RCC_GetRC32KVal();
            break;
        
        case RCC_LPTIM1CLKSOURCE_RC64M :            /* LPTIM1 clock source : RC64M */
            
            div = RCC->RC64MCR & RCC_RC64MCR_RC64MDIV_Msk;
            switch (div)
            {
                case RCC_RC64M_DIV_1 : 
                    
                    freq = HAL_RCC_GetRC64MVal();
                    break;
                
                case RCC_RC64M_DIV_16 : 
                    
                    freq = HAL_RCC_GetRC64MVal() >> 4;
                    break;
                
                default : 
                    
                    break;
                 
            }
            break;
            
        case RCC_LPTIM1CLKSOURCE_XTL :              /* LPTIM1 clock source : XTL */
            
            freq = XTL_VALUE;
            break;
        
        default :
            
            freq = 0U;
            break;
    }
    
    return (freq);
}

/******************************************************************************
*@brief : Returns the FLTCLK clock frequency
*@return: FLTCLK clock frequency
******************************************************************************/
uint32_t HAL_RCC_GetFLTCLKFreq(void)
{
    uint32_t source;
    uint32_t freq;
    
    /* check FLTCLK clock source */
    source = RCC->CCR2 & RCC_CCR2_FLTCLKSEL_Msk;
    switch (source)
    {
        case RCC_FLTCLKSOURCE_PCLK_DIV32 :          /* LPTIM1 clock source : PCLK 32 frequency division */
            
            freq = HAL_RCC_GetPCLK1Freq();
            freq = freq >> 5;
            break;
        
        case RCC_FLTCLKSOURCE_RC32K :               /* LPTIM1 clock source : RC32K */
            
            freq = HAL_RCC_GetRC32KVal();
            break;
        
        default :
            
            freq = 0U;
            break;
    }
    
    return (freq);
}

/******************************************************************************
*@brief : Returns the LPUART1 clock frequency
*@return: LPUART1 clock frequency
******************************************************************************/
uint32_t HAL_RCC_GetLPUART1CLKFreq(void)
{
    uint32_t source;
    uint32_t div;
    uint32_t freq;
    
    /* check LPUART1 clock source */
    source = RCC->CCR2 & RCC_CCR2_LPUCLKSEL_Msk;
    switch (source)
    {
        case 0U :                                   /* LPTIM1 clock source : RC32K */
            
            freq = HAL_RCC_GetRC32KVal();
            break;
        
        case RCC_CCR2_LPUCLKSEL_0 :                 /* LPTIM1 clock source : XTL */
            
            freq = XTL_VALUE;
            break;
        
        case RCC_CCR2_LPUCLKSEL_1 :                 /* LPTIM1 clock source : PCLK1 division */
            
            freq = HAL_RCC_GetPCLK1Freq();
            div = RCC->CCR2 & RCC_CCR2_LPUARTDIV_Msk;
            switch (div)
            {
                case 0U :                           /* LPTIM1 clock source : PCLK1 4 frequency division */
                    
                    freq = freq >> 2;
                    break;
                
                case RCC_CCR2_LPUARTDIV_0 :         /* LPTIM1 clock source : PCLK1 8 frequency division */
                    
                    freq = freq >> 3;
                    break;
                
                case RCC_CCR2_LPUARTDIV_1 :         /* LPTIM1 clock source : PCLK1 16 frequency division */
                    
                    freq = freq >> 4;
                    break;
                
                case (RCC_CCR2_LPUARTDIV_1 | RCC_CCR2_LPUARTDIV_0) :    /* LPTIM1 clock source : PCLK1 32 frequency division */
                    
                    freq = freq >> 5;
                    break;
                
                default :
                    
                    freq = 0U;
                    break;
            }
            break;
                
        default :
            
            freq = 0U;
            break;
    }
    
    return (freq);
}

#endif /* HAL_RCC_MODULE_ENABLED */

/************************ (C) COPYRIGHT AISINOCHIP *****END OF FILE****/
