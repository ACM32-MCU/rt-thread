/*
  ******************************************************************************
  * @file    HAL_LPTIM.c
  * @version V1.0.0
  * @date    2020
  * @brief   LPTIM HAL module driver.
  *          This file provides firmware functions to manage the following 
  *          functionalities of the LPTIM:
  ******************************************************************************
*/
#include "ACM32Fxx_HAL.h"


__weak void HAL_LPTIM_MSP(LPTIM_HandleTypeDef *handler)
{
    
}

/*********************************************************************************
* Function    : HAL_LPTIM_Init
* Description : Configure LPTIM parameter
* Input       : point at initiation parameter  
* Output      : None
* Author      : xwl                     
**********************************************************************************/

HAL_StatusTypeDef  HAL_LPTIM_Init(LPTIM_HandleTypeDef *handler)
{
    HAL_LPTIM_MSP(handler); 
    
    handler->Instance->CR &= (~LPTIM_CR_ENABLE_BIT);  // disable lptim firstly   
    
    handler->Instance->CFGR = 0;  
    
    if (handler->Init.clk_src <= CLK_SRC_ENUM_XTL) 
    {   
        RCC->CCR2 = (RCC->CCR2 & (~(BIT20 | BIT21) ) ) | (handler->Init.clk_src << 20);   
    }
    else
    {
        handler->Instance->CFGR |= BIT0; 
        handler->Instance->CFGR2 = (handler->Instance->CFGR2 & (~(BIT0|BIT1)) )  | (handler->Init.clk_src-CLK_SRC_ENUM_EXTERNAL_MUX0);    
    }
    
    if (handler->Init.count_mode >= COUNT_MODE_ENUM_MUX0)   
    {
       handler->Instance->CFGR |= (BIT23);   
       handler->Instance->CFGR2 = (handler->Instance->CFGR2 & (~(BIT0|BIT1)) )  | (handler->Init.count_mode-COUNT_MODE_ENUM_MUX0);    
    }
    
    if (PRELOAD_ENABLE == handler->Init.preload ) 
    {
        handler->Instance->CFGR |= (BIT22);  
    } 
    
    handler->Instance->CFGR |= (handler->Init.prescaler << 9) | (handler->Init.ext_clk_filter << 3) | (handler->Init.ext_clock_polarity << 1);  

    if (handler->Init.trigger_source >= TRIG_SRC_EXT0) 
    {
        handler->Instance->CFGR |= ( (handler->Init.trigger_source - TRIG_SRC_EXT0) << 13);   
        handler->Instance->CFGR |= ( (handler->Init.trigger_polarity) << 17);            
    }
    
    handler->Instance->IER = handler->Init.interrupt;   
    
    handler->Instance->CR |= LPTIM_CR_ENABLE_BIT;  
    
    handler->Instance->ARR = handler->Init.period;
    
    handler->Instance->COMPA = handler->Init.duty;     
    
    handler->Instance->RCR = handler->Init.repeat;   
    
    return HAL_OK;  
}  

HAL_StatusTypeDef HAL_LPTIM_Start(LPTIM_HandleTypeDef *handler, uint32_t op_mode) 
{
   if (CONTINUE_MODE == op_mode) 
   {
       handler->Instance->CR |= BIT2; 
   }
   else
   {
      handler->Instance->CR |= BIT1;   
   }
   
   return HAL_OK;   
}

uint32_t HAL_LPTIM_Read_Count(LPTIM_HandleTypeDef *handler)
{
    volatile uint32_t count;
    
    count = handler->Instance->CNT; 
    
    if (count == (handler->Instance->CNT) ) 
    {
        return count; 
    }
    else
    {
        0xFFFFFFFFU;   
    }
} 

void HAL_LPTIM_ENABLE_Interrupt(LPTIM_HandleTypeDef *handler, uint32_t interrupt)  
{
    handler->Instance->IER = interrupt;   
}

void HAL_LPTIM_RESET_Count(LPTIM_HandleTypeDef *handler)  
{
    handler->Instance->CR |= BIT3; 
}

void HAL_LPTIM_RESET_Count_After_Read_Enanble(LPTIM_HandleTypeDef *handler)  
{
    handler->Instance->CR |= BIT4; 
}


