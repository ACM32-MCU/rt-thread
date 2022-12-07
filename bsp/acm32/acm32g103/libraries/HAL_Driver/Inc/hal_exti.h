
/******************************************************************************
*@file  : hal_exti.h
*@brief : Header file of EXTI HAL module.
******************************************************************************/

#ifndef __HAL_EXTI_H__
#define __HAL_EXTI_H__

#include "hal.h"
#include "hal_gpio.h"


/** @defgroup EXTI_Line
  * @brief    When line is 0-15, its definition is the same as GPIO_pins
  * @{
  */

#define EXTI_LINE_0				                (0x000001U)
#define EXTI_LINE_1				                (0x000002U)
#define EXTI_LINE_2				                (0x000004U)
#define EXTI_LINE_3				                (0x000008U)
#define EXTI_LINE_4				                (0x000010U)
#define EXTI_LINE_5				                (0x000020U)
#define EXTI_LINE_6				                (0x000040U)
#define EXTI_LINE_7				                (0x000080U)
#define EXTI_LINE_8				                (0x000100U)
#define EXTI_LINE_9				                (0x000200U)
#define EXTI_LINE_10				            (0x000400U)
#define EXTI_LINE_11				            (0x000800U)
#define EXTI_LINE_12				            (0x001000U)
#define EXTI_LINE_13				            (0x002000U)
#define EXTI_LINE_14				            (0x004000U)
#define EXTI_LINE_15				            (0x008000U)
#define EXTI_LINE_16				            (0x010000U)
#define EXTI_LINE_17				            (0x020000U)
#define EXTI_LINE_18				            (0x040000U)
#define EXTI_LINE_19				            (0x080000U)
#define EXTI_LINE_20				            (0x100000U)
#define EXTI_LINE_21				            (0x200000U)
#define EXTI_LINE_23				            (0x800000U)
#define EXTI_LINE_24				            (0x1000000U)
#define EXTI_LINE_25				            (0x2000000U)
#define EXTI_LINE_26				            (0x4000000U)

/**
  * @}
  */

/** @brief  PIN mask for assert test
  */

#define EXTI_ALL_LINE_MASK                      (0x7BFFFFFU)    /* PIN mask for assert test */
#define EXTI_GPIO_LINE_MASK                     (0xFFFFU)       /* PIN mask */
#define EXTI_GPIOF_LINE_MASK                    (0x7BF001FU)    /* PIN mask for assert test */

/** @defgroup EXTI_Mode
  * @brief    its definition is the same as that of GPIO_MODE_IT_RISING、GPIO_MODE_IT_FALLING、
  *           GPIO_MODE_IT_RISING_FALLING、GPIO_MODE_EVT_RISING、GPIO_MODE_EVT_RISING、
  *           GPIO_MODE_EVT_RISING in GPIO_Mode
  * @{
  */

#define  EXTI_MODE_IT_RISING                    (0x10110000U)   /*!< External Interrupt Mode with Rising edge trigger detection          */
#define  EXTI_MODE_IT_FALLING                   (0x10210000U)   /*!< External Interrupt Mode with Falling edge trigger detection         */
#define  EXTI_MODE_IT_RISING_FALLING            (0x10310000U)   /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */
#define  EXTI_MODE_EVT_RISING                   (0x10120000U)   /*!< External Event Mode with Rising edge trigger detection              */
#define  EXTI_MODE_EVT_FALLING                  (0x10220000U)   /*!< External Event Mode with Falling edge trigger detection             */
#define  EXTI_MODE_EVT_RISING_FALLING           (0x10320000U)   /*!< External Event Mode with Rising/Falling edge trigger detection      */

/**
  * @}
  */

/** @defgroup EXTI_GPIOSel  EXTI GPIOSel
  * @brief
  * @{
  */
  
#define EXTI_GPIOA                              ( 0x0U )
#define EXTI_GPIOB                              ( 0x1U )
#define EXTI_GPIOC                              ( 0x2U )
#define EXTI_GPIOD                              ( 0x3U )
#define EXTI_GPIOE                              ( 0x4U )
#define EXTI_GPIOF                              ( 0x5U ) 

/**
  * @}
  */




/** @defgroup  EXTI Private Macros
  * @{
  */
  
#define IS_EXTI_GPIOX(__GPIO__)                 (((__GPIO__) == GPIOA) || \
                                                 ((__GPIO__) == GPIOB) || \
                                                 ((__GPIO__) == GPIOC) || \
                                                 ((__GPIO__) == GPIOD) || \
                                                 ((__GPIO__) == GPIOE) || \
                                                 ((__GPIO__) == GPIOF))

#define IS_EXTI_ALL_LINE(__LINE__)              ((((uint32_t)(__LINE__) &  EXTI_ALL_LINE_MASK) != 0x00u) &&\
                                                 (((uint32_t)(__LINE__) & ~EXTI_ALL_LINE_MASK) == 0x00u))

#define IS_EXTI_GPIOF_LINE(__LINE__)            (((uint32_t)(__LINE__) & ~EXTI_GPIOF_LINE_MASK) == 0x00u)

#define IS_EXTI_GPIO_PIN(__GPIO__, __LINE__)    (((__GPIO__) == GPIOF) ? (IS_EXTI_GPIOF_LINE(__LINE__)) : SET)


#define IS_EXTI_SINGLE_LINE(__LINE__)           (((__LINE__) == EXTI_LINE_0) || \
                                                 ((__LINE__) == EXTI_LINE_1) || \
                                                 ((__LINE__) == EXTI_LINE_2) || \
                                                 ((__LINE__) == EXTI_LINE_3) || \
                                                 ((__LINE__) == EXTI_LINE_4) || \
                                                 ((__LINE__) == EXTI_LINE_5) || \
                                                 ((__LINE__) == EXTI_LINE_6) || \
                                                 ((__LINE__) == EXTI_LINE_7) || \
                                                 ((__LINE__) == EXTI_LINE_8) || \
                                                 ((__LINE__) == EXTI_LINE_9) || \
                                                 ((__LINE__) == EXTI_LINE_10) || \
                                                 ((__LINE__) == EXTI_LINE_11) || \
                                                 ((__LINE__) == EXTI_LINE_12) || \
                                                 ((__LINE__) == EXTI_LINE_13) || \
                                                 ((__LINE__) == EXTI_LINE_14) || \
                                                 ((__LINE__) == EXTI_LINE_15) || \
                                                 ((__LINE__) == EXTI_LINE_16) || \
                                                 ((__LINE__) == EXTI_LINE_17) || \
                                                 ((__LINE__) == EXTI_LINE_18) || \
                                                 ((__LINE__) == EXTI_LINE_19) || \
                                                 ((__LINE__) == EXTI_LINE_20) || \
                                                 ((__LINE__) == EXTI_LINE_21) || \
                                                 ((__LINE__) == EXTI_LINE_23) || \
                                                 ((__LINE__) == EXTI_LINE_24) || \
                                                 ((__LINE__) == EXTI_LINE_25) || \
                                                 ((__LINE__) == EXTI_LINE_26))




#define IS_EXTI_MODE(__MODE__)		            (((__MODE__) == EXTI_MODE_IT_RISING) || \
                                                 ((__MODE__) == EXTI_MODE_IT_FALLING) || \
                                                 ((__MODE__) == EXTI_MODE_IT_RISING_FALLING) || \
                                                 ((__MODE__) == EXTI_MODE_EVT_RISING) || \
                                                 ((__MODE__) == EXTI_MODE_EVT_FALLING) || \
                                                 ((__MODE__) == EXTI_MODE_EVT_RISING_FALLING))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

void HAL_EXTI_IRQHandler(uint32_t Line);
void HAL_EXTI_LineCallback(uint32_t Line);
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(GPIO_TypeDef *GPIOx, uint32_t Line, uint32_t Mode);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(uint32_t Line);
FunctionalState HAL_EXTI_IsConfigLine(GPIO_TypeDef *GPIOx, uint32_t Line);
void HAL_EXTI_GenerateSWI(uint32_t Line);
FlagStatus HAL_EXTI_GetPending(uint32_t Line);
void HAL_EXTI_ClearPending(uint32_t Line);
void HAL_EXTI_ClearAllPending(void);



#endif

