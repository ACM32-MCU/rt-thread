
/******************************************************************************
*@file  : hal_exti.c
*@brief : GPIO EXTI module driver.
******************************************************************************/

#include "hal.h" 

#ifdef HAL_EXTI_MODULE_ENABLED

/******************************************************************************
*@brief : EXTI interrupt request.
*@param : Line: Exti line number.
*               This parameter can be a combination of @ref EXTI_Line.
*@return: None
******************************************************************************/
void HAL_EXTI_IRQHandler(uint32_t Line)
{
    assert_param(IS_EXTI_ALL_LINE(Line));
    
    if (EXTI->PDR & Line)
    {
		HAL_EXTI_LineCallback(Line);
        EXTI->PDR = Line;
    }
}

/******************************************************************************
*@brief : EXTI interrupt callback.
*@param : Line: Exti line number.
*               This parameter can be a combination of @ref EXTI_Line.
*@return: None
******************************************************************************/
__weak void HAL_EXTI_LineCallback(uint32_t Line)
{
	UNUSED(Line);
}

/******************************************************************************
*@brief : Set configuration of a dedicated Exti line.
*@param : GPIOx: where x can be (A..F) to select the GPIO peripheral.
*                This parameter is only possible for line 0 to 15.
*@param : Line:  Exti line number.
*                This parameter can be a combination of @ref EXTI_Line.
*@param : Mode:  The Exit Mode to be configured for a core.
                 This parameter can be a value of @ref EXTI_Mode .
*@return: HAL Status
******************************************************************************/
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(GPIO_TypeDef *GPIOx, uint32_t Line, uint32_t Mode)
{
    uint32_t tempCR1;
    uint32_t tempCR2;
    uint32_t tempLine;
    uint32_t position;
    uint32_t source;
    
    /* Check the parameters */
    assert_param(IS_EXTI_ALL_LINE(Line));
    assert_param(IS_EXTI_MODE(Mode));

    /* disable interrupt and event */
	EXTI->IENR  &= ~Line;
	EXTI->EENR  &= ~Line;
	EXTI->RTENR &= ~Line;
	EXTI->FTENR &= ~Line;

    /* Line0 ~ 15 trigger from GPIO */
    tempLine = Line & EXTI_GPIO_LINE_MASK;
	if (tempLine)
	{
        /* Check the parameters */
        assert_param(IS_EXTI_GPIOX(GPIOx));
        assert_param(IS_EXTI_GPIO_PIN(GPIOx, Line));
        
        /* Configure EXTI source select */
		if (GPIOx == GPIOA)
			source = EXTI_GPIOA;
		else if (GPIOx == GPIOB)
			source = EXTI_GPIOB;
		else if (GPIOx == GPIOC)
			source = EXTI_GPIOC;
		else if (GPIOx == GPIOD)
			source = EXTI_GPIOD;
		else if (GPIOx == GPIOE)
			source = EXTI_GPIOE;
		else if (GPIOx == GPIOF)
			source = EXTI_GPIOF;
		
        tempCR1 = EXTI->CR1;
        tempCR2 = EXTI->CR2;
        
        position = 0;
        while (tempLine >> position)
        {
            if (tempLine & (0x1U << position))
            {
                if (position < 8) 
                {
                    /* Line0 ~ 7 */
                    tempCR1 &= ~(0x0FUL << (position << 2U));
                    tempCR1 |= source << (position << 2U);
                }
                else 
                {
                    /* Line8 ~ 15 */
                    tempCR2 &= ~(0x0FUL << ((position - 8U) << 2U));
                    tempCR2 |= source << ((position - 8U) << 2U);
                }
            }
            position++;
        }
        
        EXTI->CR1 = tempCR1;
        EXTI->CR2 = tempCR2;
    }
	
    if (Mode == EXTI_MODE_IT_RISING)
    {
        /* Interrupt rising edge mode */
        EXTI->RTENR |=  Line;
        EXTI->IENR  |=  Line;
    }
    else if (Mode == EXTI_MODE_IT_FALLING)
    {
        /* Interrupt falling edge mode */
        EXTI->FTENR |=  Line;
        EXTI->IENR  |=  Line;
    }
    else if (Mode == EXTI_MODE_IT_RISING_FALLING)
    {
        /* Interrupt rising and falling edge mode */
        EXTI->RTENR |=  Line;
        EXTI->FTENR |=  Line;
        EXTI->IENR  |=  Line;
    }
    else if (Mode == EXTI_MODE_EVT_RISING)
    {
        /* Event rising edge mode */
        EXTI->RTENR |=  Line;
        EXTI->EENR |=  Line;
    }
    else if (Mode == EXTI_MODE_EVT_FALLING)
    {
        /* Event falling edge mode */
        EXTI->FTENR |=  Line;
        EXTI->EENR |=  Line;
    }
    else if (Mode == EXTI_MODE_EVT_RISING_FALLING)
    {
        /* Event rising and falling edge mode */
        EXTI->RTENR |=  Line;
        EXTI->FTENR |=  Line;
        EXTI->EENR |=  Line;
    }

    return HAL_OK;
}

/******************************************************************************
*@brief : Clear whole configuration of a dedicated Exti line.
*@param : Line:  Exti line number.
*                This parameter can be a combination of @ref EXTI_Line.
*@return: HAL Status
******************************************************************************/
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(uint32_t Line)
{
    /* Check the parameters */
    assert_param(IS_EXTI_ALL_LINE(Line));

    /* disable interrupt and event */
	EXTI->IENR  &= ~Line;
	EXTI->EENR  &= ~Line;
	EXTI->RTENR &= ~Line;
	EXTI->FTENR &= ~Line;

    return HAL_OK;
}

/******************************************************************************
*@brief : Check whether the LINE of the specified GPIOx is configured.
*@param : GPIOx: where x can be (A..F) to select the GPIO peripheral.
*                This parameter is only possible for line 0 to 15.
*@param : Line:  Exti line number.
*                This parameter can be a value of @ref EXTI_Line.
*@return: configuration status
*         This parameter can be a value of @ref FunctionalState.
*             @arg ENABLE: Configured.
*             @arg DISABLE: Not configured.
******************************************************************************/
FunctionalState HAL_EXTI_IsConfigLine(GPIO_TypeDef *GPIOx, uint32_t Line)
{
    uint32_t tempCR1;
    uint32_t tempCR2;
    uint32_t tempLine;
    uint32_t position;
    uint32_t source;
    uint32_t currSource;
    
    /* Check the parameters */
    assert_param(IS_EXTI_SINGLE_LINE(Line));

    if (((EXTI->IENR & Line) == 0U) && ((EXTI->IENR & Line) == 0U))
        return (DISABLE);
    
    tempLine = Line & EXTI_GPIO_LINE_MASK;
    
	if (tempLine == 0U)
    {
        /* Line16 ~ 26 trigger ,expect line 22 */
        return (ENABLE);
    }
    
    /* Line0 ~ 15 trigger from GPIO */
    
    /* Check the parameters */
    assert_param(IS_EXTI_GPIOX(GPIOx));
    assert_param(IS_EXTI_GPIO_PIN(GPIOx, Line));
    
    /* Configure EXTI source select */
    if (GPIOx == GPIOA)
        currSource = EXTI_GPIOA;
    else if (GPIOx == GPIOB)
        currSource = EXTI_GPIOB;
    else if (GPIOx == GPIOC)
        currSource = EXTI_GPIOC;
    else if (GPIOx == GPIOD)
        currSource = EXTI_GPIOD;
    else if (GPIOx == GPIOE)
        currSource = EXTI_GPIOE;
    else if (GPIOx == GPIOF)
        currSource = EXTI_GPIOF;
    
    position = 0U;
    while (tempLine >> position)
    {
        if (tempLine & (0x1U << position))
        {
            if (position < 8U) 
            {
                /* Line0 ~ 7 */
                source = (EXTI->CR1 >> (position << 2U)) & 0x0FU;
            }
            else 
            {
                /* Line8 ~ 15 */
                source = (EXTI->CR2 >> ((position - 8U) << 2U)) & 0x0FU;
            }
            
            if (source == currSource)
                return (ENABLE);
            else
                return (DISABLE);
        }
        position++;
    }
	
	return (DISABLE);
}

/******************************************************************************
*@brief : The specified Line generates a software interrupt.
*@param : Line:  Exti line number.
*                This parameter can be a combination of @ref EXTI_Line.
*@return: None.
******************************************************************************/
void HAL_EXTI_GenerateSWI(uint32_t Line)
{
    /* Check the parameters */
    assert_param(IS_EXTI_ALL_LINE(Line));

    EXTI->SWIER &= ~Line;
    EXTI->SWIER |=  Line;
}

/******************************************************************************
*@brief : Get interrupt pending bit of a dedicated line.
*@param : Line:  Exti line number.
*                This parameter can be a value of @ref EXTI_Line.
*@return: interrupt pending bit status
*         This parameter can be a value of @ref FlagStatus.
*             @arg SET: interrupt is pending.
*             @arg RESET: interrupt is not pending.
******************************************************************************/
FlagStatus HAL_EXTI_GetPending(uint32_t Line)
{
    /* Check the parameters */
    assert_param(IS_EXTI_SINGLE_LINE(Line));

    if (EXTI->PDR & Line)
		return (SET);
	else
		return (RESET);
}

/******************************************************************************
*@brief : Clear interrupt pending bit of a dedicated line.
*@param : Line:  Exti line number.
*                This parameter can be a combination of @ref EXTI_Line.
*@return: None.
******************************************************************************/
void HAL_EXTI_ClearPending(uint32_t Line)
{
    /* Check the parameters */
    assert_param(IS_EXTI_ALL_LINE(Line));

    /* Clear pending status */
    EXTI->PDR = Line;
}

/******************************************************************************
*@brief : Clear all interrupt pending bit.
*@return: None.
******************************************************************************/
void HAL_EXTI_ClearAllPending(void)
{
    /* Clear pending status */
    EXTI->PDR = EXTI_ALL_LINE_MASK;   
}



#endif /* HAL_EXTI_MODULE_ENABLED */

/************************ (C) COPYRIGHT AISINOCHIP *****END OF FILE****/


