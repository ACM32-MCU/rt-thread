/*
  ******************************************************************************
  * @file    HAL_EFlash.h
  * @version V1.0.0
  * @date    2020
  * @brief   Header file of EFlash HAL module.
  ******************************************************************************
*/
#ifndef __HAL_LPTIM_H__
#define __HAL_LPTIM_H__ 

#include "ACM32Fxx_HAL.h"

typedef enum 
{
   CLK_SRC_ENUM_PCLK = 0, 
   CLK_SRC_ENUM_RC32K= 1, 
   CLK_SRC_ENUM_RCH =  2,
   CLK_SRC_ENUM_XTL =  3, 
   CLK_SRC_ENUM_EXTERNAL_MUX0 = 4,  
   CLK_SRC_ENUM_EXTERNAL_MUX1 = 5,  
   CLK_SRC_ENUM_EXTERNAL_MUX2 = 6,  
   CLK_SRC_ENUM_EXTERNAL_MUX3 = 7,
}CLK_SRC_ENUM;  

typedef enum 
{
   COUNT_MODE_ENUM_INTERNAL = 0x0,
   COUNT_MODE_ENUM_MUX0     = 0x1, 
   COUNT_MODE_ENUM_MUX1     = 0x2, 
   COUNT_MODE_ENUM_MUX2     = 0x3, 
   COUNT_MODE_ENUM_MUX3     = 0x4,       
}COUNT_MODE_ENUM;   

/*below definition is for external clock*/
typedef enum 
{
   CLOCK_POLARITY_RISING = 0x00, 
   CLOCK_POLARITY_FALLING = 0x01,  
   CLOCK_POLARITY_BOTH = 0x02
}CLOCK_POLARITY_ENUM;  

typedef enum 
{
   TRIG_POLARITY_RISING = 0x01,
   TRIG_POLARITY_FALLING = 0x02,  
   TRIG_POLARITY_BOTH = 0x03
}TRIG_POLARITY_ENUM;    

#define LPTIM_INT_CMP_MATCH       BIT0 
#define LPTIM_INT_ARR_MATCH       BIT1 
#define LPTIM_INT_EXT_TRIG_VALID  BIT2 
#define LPTIM_INT_CMP_REG_OK      BIT3  
#define LPTIM_INT_ARR_REG_OK      BIT4 
#define LPTIM_INT_UP_CHANGE       BIT5 
#define LPTIM_INT_DN_CHANGE       BIT6 
#define LPTIM_INT_UPDATE_EVT      BIT7  
#define LPTIM_INT_RCR_REG_OK      BIT8      

typedef enum 
{
   TRIG_SRC_INTERNAL = 0,
   TRIG_SRC_EXT0 = 1,  
   TRIG_SRC_EXT1 = 2,  
   TRIG_SRC_EXT2 = 3,  
   TRIG_SRC_EXT3 = 4, 
   TRIG_SRC_EXT4 = 5, 
   TRIG_SRC_EXT5 = 6,  
   TRIG_SRC_EXT6 = 7, 
   TRIG_SRC_EXT7 = 8,   
}TRIG_SRC_ENUM;  

typedef enum 
{
   CLK_PRESCALER_1 =   0,
   CLK_PRESCALER_2 =   1,  
   CLK_PRESCALER_4 =   2,  
   CLK_PRESCALER_8 =   3,  
   CLK_PRESCALER_16 =  4, 
   CLK_PRESCALER_32 =  5, 
   CLK_PRESCALER_64 =  6,  
   CLK_PRESCALER_128 = 7,   
}CLK_PRESCALER_ENUM; 

typedef enum 
{
   EX_CLK_FILTER_1 =   0,
   EX_CLK_FILTER_2 =   1,  
   EX_CLK_FILTER_4 =   2,  
   EX_CLK_FILTER_8 =   3,   
}EX_CLK_FILTER_ENUM;   

typedef enum 
{
   SINGLE_MODE   = 0x00, 
   CONTINUE_MODE = 0x01,    
}OPERATION_MODE_ENUM; 

typedef enum 
{
   PRELOAD_DISABLE = 0x00, 
   PRELOAD_ENABLE  =  0x01,    
}PRELOAD_DISABLE_ENABLE;      

#define LPTIM_CR_ENABLE_BIT   BIT0   

typedef struct 
{
    uint16_t clk_src;                  

    uint16_t count_mode;             

    uint16_t duty;            

    uint16_t period;   

    uint16_t preload;  

    uint16_t prescaler;  

    uint16_t repeat;       
   
    uint16_t ext_clock_polarity;   
    
    uint16_t ext_clk_filter;  
    
    uint16_t trigger_source;
    
    uint16_t trigger_filter; 

    uint16_t trigger_polarity;  
    
    uint16_t wave_mode;    
    
    uint16_t interrupt;    

}LPTIM_InitParaTypeDef;  


typedef struct __LPTIM_HandleTypeDef
{
    LPTIM_TypeDef             *Instance;    /* LPTIM registers base address */

    LPTIM_InitParaTypeDef     Init;        /* LPTIM initialization parameters */
    
}LPTIM_HandleTypeDef;  

HAL_StatusTypeDef  HAL_LPTIM_Init(LPTIM_HandleTypeDef *handler);   

HAL_StatusTypeDef HAL_LPTIM_Start(LPTIM_HandleTypeDef *handler, uint32_t op_mode);      

void HAL_LPTIM_ENABLE_Interrupt(LPTIM_HandleTypeDef *handler, uint32_t interrupt);    

void HAL_LPTIM_RESET_Count(LPTIM_HandleTypeDef *handler);  

void HAL_LPTIM_RESET_Count_After_Read_Enanble(LPTIM_HandleTypeDef *handler);     

#endif
