
/******************************************************************************
*@file  : acm32g103_hal_conf.c
*@brief : HAL configuration file
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#ifndef __ACM32G103_HAL_CONF_H
#define __ACM32G103_HAL_CONF_H

#include "acm32g103.h"
#include "hal_def.h"
#include "hal.h"

/******* enable printf in debug stage ****************************************/
#define DEBUG

#ifdef DEBUG
    #define printfS(fmt, ...)       printf(fmt, ##__VA_ARGS__)
#else
    #define printfS(fmt, ...)         
#endif

/******* enable assert in debug stage ****************************************/
#define USE_FULL_ASSERT

#ifdef USE_FULL_ASSERT
  void assert_failed(uint8_t* file, uint32_t line);
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
#else
  #define assert_param(expr) ((void)0U)
#endif

 /******* config data if or not in extern sram *******************************/ 
//#define DATA_IN_ExtSRAM
  

/******* config extern high speed osc freq and low osc freq in Hz ************/
#define XTH_VALUE                   ( 12000000U )
#define XTL_VALUE                   ( 32768U )


/******* SysTick interrupt priority  *****************************************/
#define TICK_INT_PRIORITY           ((1<<__NVIC_PRIO_BITS)-1)  

/******* SysTick ms period set ,1ms or 10ms **********************************/
#define TICK_PERIOD_1MS             (1U)
#define TICK_PERIOD_10MS            (10U)
#define TICK_PERIOD_MS              (TICK_PERIOD_1MS)  


/******* instruction and data accelerate enable ******************************/
#define INS_ACCELERATE_ENABLE       (1U)    //instruction accelerate enable 
#define DATA_ACCELERATE_ENABLE      (0U)    //data accelerate enable

/******* module selection ****************************************************/

#define HAL_CORTEX_MODULE_ENABLED
#define HAL_EXMC_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_ADC_MODULE_ENABLED
#define HAL_DAC_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
//#define HAL_I2S_MODULE_ENABLED
#define HAL_IWDT_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_RTC_MODULE_ENABLED
#define HAL_PMU_MODULE_ENABLED
#define HAL_TIMER_MODULE_ENABLED
#define HAL_EFLASH_MODULE_ENABLED
//#define HAL_LPUART_MODULE_ENABLED
//#define HAL_WDT_MODULE_ENABLED 
//#define HAL_FSUSB_MODULE_ENABLED
//#define HAL_CRC_ENABLED  
//#define HAL_FAU_ENABLED  
//#define HAL_AES_ENABLED  
//#define HAL_HASH_SHA1_ENABLED 
//#define HAL_HASH_SHA256_ENABLED 
//#define HAL_HRNG_ENABLED  
//#define HAL_LPTIM_ENABLED    
#define HAL_CAN_MODULE_ENABLED    
//#define HAL_COMP_MODULE_ENABLED
//#define HAL_OPA_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED


/******* include modules header file *****************************************/

    
#if ((INS_ACCELERATE_ENABLE==1) ||  (DATA_ACCELERATE_ENABLE==1))
    #include "system_accelerate.h"
#endif  
    
#ifdef HAL_CORTEX_MODULE_ENABLED
    #include "hal_cortex.h"
#endif    

#ifdef HAL_EXMC_MODULE_ENABLED
    #include "hal_exmc.h"
#endif

#ifdef HAL_DMA_MODULE_ENABLED
    #include "hal_dma.h"
#endif

#ifdef HAL_GPIO_MODULE_ENABLED
    #include "hal_gpio.h"
#endif

#ifdef HAL_UART_MODULE_ENABLED
    #include "hal_uart.h"
    #include "hal_uart_ex.h"
#endif

#ifdef HAL_ADC_MODULE_ENABLED
    #include "hal_adc.h"
#endif

#ifdef HAL_DAC_MODULE_ENABLED
    #include "hal_dac.h"
#endif

#ifdef HAL_EXTI_MODULE_ENABLED
    #include "hal_exti.h"
#endif

#ifdef HAL_I2C_MODULE_ENABLED
    #include "hal_i2c.h"
#endif  

#ifdef HAL_I2S_MODULE_ENABLED
    #include "hal_i2s.h"
#endif

#ifdef HAL_RCC_MODULE_ENABLED
    #include "hal_rcc.h"
#endif

#ifdef HAL_RTC_MODULE_ENABLED
    #include "hal_rtc.h"
#endif

#ifdef HAL_PMU_MODULE_ENABLED
	#include "hal_pmu.h"
#endif

#ifdef HAL_SPI_MODULE_ENABLED
    #include "hal_spi.h"
#endif

#ifdef HAL_IWDT_MODULE_ENABLED
    #include "hal_iwdt.h"
#endif

#ifdef HAL_EFLASH_MODULE_ENABLED
    #include "hal_eflash.h"
#endif

#ifdef HAL_OPA_MODULE_ENABLED
    #include "hal_opa.h"
#endif

#ifdef HAL_COMP_MODULE_ENABLED
    #include "hal_comp.h"
#endif

#ifdef HAL_CAN_MODULE_ENABLED
    #include "hal_can.h"
#endif

#ifdef HAL_LPUART_MODULE_ENABLED
    #include "hal_lpuart.h"
#endif

#ifdef HAL_WDT_MODULE_ENABLED
    #include "hal_wdt.h"
#endif

#ifdef HAL_TIMER_MODULE_ENABLED
    #include "hal_timer.h"  
    #include "hal_timer_ex.h"
#endif  

#ifdef HAL_FSUSB_MODULE_ENABLED
    #include "hal_fusb.h"
#endif

#ifdef HAL_CRC_ENABLED  
    #include  "hal_crc.h"
#endif  

#ifdef  HAL_AES_ENABLED
    #include  "hal_aes.h"  
#endif    

#ifdef HAL_FAU_ENABLED    
    #include  "hal_fau.h"       
#endif 

#ifdef HAL_HASH_SHA1_ENABLED 
    #include "hal_sha1.h"  
#endif 

#ifdef HAL_HASH_SHA256_ENABLED 
    #include "hal_sha256.h"  
#endif  

#ifdef HAL_HRNG_ENABLED     
    #include "hal_hrng.h"    
#endif    

#ifdef HAL_LPTIM_ENABLED        
    #include "hal_lptim.h"                            
#endif          


#endif /* __ACM32G103_HAL_CONF_H  */

  