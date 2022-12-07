
/******************************************************************************
*@file  : acm32g103.h
*@brief : Device Peripheral Access Layer Header File
*           This file contains:
*           - Data structures and the address mapping for all peripherals
*           - peripherals registers declarations and bits definition
*           - Macros to access peripheral¡¯s registers hardware
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#ifndef __ACM32G103_H__
#define __ACM32G103_H__

    
/* -------  Interrupt Number Definition  ---------------------------------- */

typedef enum IRQn
{
/* -------  Cortex-M33 Processor Exceptions Numbers ----------------------- */
    Reset_IRQn                  = -15,          // Reset Vector, invoked on Power up and warm reset
    NonMaskableInt_IRQn         = -14,          // Non Maskable Interrupt
    HardFault_IRQn              = -13,          // HardFault Interrupt
    MemoryManagement_IRQn       = -12,          // Memory Management, MPU mismatch, including Access Violation and No Match
    BusFault_IRQn               = -11,          // Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memoryrelated Fault
    UsageFault_IRQn             = -10,          // Usage Fault, i.e. Undef Instruction, Illegal State Transition
    SVCall_IRQn                 = -5,           // SV Call Interrupt
    DebugMonitor_IRQn           = -4,           // Debug Monitor
    PendSV_IRQn                 = -2,           // Pend SV Interrupt
    SysTick_IRQn                = -1,           // System Tick Interrupt
/* -------  ACM32 Specific Interrupt Numbers  ---------------------------- */
    WDT_IRQn                    = 0,            // WDT_IRQHandler
    LVD_IRQn                    = 1,            // LVD_IRQHandler
    RTC_IRQn                    = 2,            // RTC_IRQHandler
    RSV1_IRQn                   = 3,            // 
    EFC_IRQn                    = 4,            // EFC_IRQHandler
    SRAM_PARITY_IRQn            = 5,            // SRAM_PARITY_IRQHandler
    CLKRDY_IRQn                 = 6,            // CLKRDY_IRQHandler
    EXTI0_IRQn                  = 7,            // EXTI0_IRQHandler
    EXTI1_IRQn                  = 8,            // EXTI1_IRQHandler  
    EXTI2_IRQn                  = 9,            // EXTI2_IRQHandler
    EXTI3_IRQn                  = 10,           // EXTI3_IRQHandler  
    EXTI4_IRQn                  = 11,           // EXTI4_IRQHandler
    DMA1_IRQn                   = 12,           // DMA1_IRQHandler
    DMA2_IRQn                   = 13,           // DMA2_IRQHandler
    ADC12_IRQn                  = 14,           // ADC1_2_IRQHandler
    RSV2_IRQn                   = 15,           // 
    DAC_IRQn                    = 16,           // DAC_IRQHandler
    COMP1_2_IRQn                = 17,           // COMP1_2_IRQHandler
    USB_IRQn                    = 18,           // USB_IRQHandler
    CAN1_IRQn                   = 19,           // CAN1_IRQHandler
    CAN2_IRQn                   = 20,           // CAN2_IRQHandler
    EXTI9_5_IRQn                = 21,           // CAN2_IRQHandler
    TIM1_BRK_UP_TRG_COM_IRQn    = 22,           // TIM1_BRK_UP_TRG_COM_IRQHandler
    TIM1_CC_IRQn                = 23,           // TIM1_CC_IRQHandler
    TIM2_IRQn                   = 24,           // TIM2_IRQHandler
    TIM3_IRQn                   = 25 ,          // TIM3_IRQHandler
    TIM6_IRQn                   = 26,           // TIM6_IRQHandler 
    TIM7_IRQn                   = 27,           // TIM7_IRQHandler 
    TIM8_BRK_UP_TRG_COM_IRQn    = 28,           // TIM8_BRK_UP_TRG_COM_IRQHandler
    TIM8_CC_IRQn                = 29,           // TIM8_CC_IRQHandler
    TIM15_IRQn                  = 30,           // TIM15_IRQHandler
    TIM16_IRQn                  = 31,           // TIM16_IRQHandler
    TIM17_IRQn                  = 32,           // TIM17_IRQHandler
    I2C1_IRQn                   = 33,           // I2C1_IRQHandler
    I2C2_IRQn                   = 34,           // I2C2_IRQHandler
    SPI1_IRQn                   = 35,           // SPI1_IRQHandler
    SPI2_IRQn                   = 36,           // SPI2_IRQHandler
    SPI3_IRQn                   = 37,           // SPI3_IRQHandler
    I2S1_IRQn                   = 38,           // I2S1_IRQHandler
    I2S2_IRQn                   = 39,           // I2S2_IRQHandler
    UART1_IRQn                  = 40,           // UART1_IRQHandler
    UART2_IRQn                  = 41,           // UART2_IRQHandler
    UART3_IRQn                  = 42,           // UART3_IRQHandler
    UART4_IRQn                  = 43,           // UART4_IRQHandler
    EXTI15_10_IRQn              = 44,           // EXIT15_10_IRQhandler
    USB_WAKEUP_IRQn             = 45,           // USB_WAKEUP_IRQHandler
    LPUART_IRQn                 = 46,           // LPUART1_IRQHandler   
    LPTIM1_IRQn                 = 47,           // LPTIM1_IRQHandler  
    RSV3_IRQn                   = 48,           // 
    AES_IRQn                    = 49,           // AES_IRQHandler
    FPU_IRQn                    = 50,           // FPU_IRQHandler
    RSV4_IRQn                   = 51,           //    
    STOP_RESET_IRQn             = 52,           // STOP_RESET_IRQHandler  
    TIM4_IRQn                   = 53 ,          // TIM4_IRQHandler
	COMP3_4_IRQn                = 54,           // COMP3_4_IRQn
	IWDT_WAKEUP_IRQn            = 55,           // IWDT_WAKEUP_IRQHandler
} IRQn_Type;

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
#pragma push
#pragma anon_unions
#elif defined (__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
/* anonymous unions are enabled by default */
#elif defined (__TMS470__)
/* anonymous unions are enabled by default */
#elif defined (__TASKING__)
#pragma warning 586
#elif defined (__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif



/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __MPU_PRESENT           1       /*!< cm4ikmcu does not provide a MPU present or not       */
#define __NVIC_PRIO_BITS        4       /*!< cm4ikmcu Supports 2 Bits for the Priority Levels     */
#define __Vendor_SysTickConfig  0       /*!< Set to 1 if different SysTick Config is used                 */

#define   ARM_MATH_CM4          1 
#define __TARGET_FPU_VFP        1 
#define __FPU_PRESENT           1 
#define __DSP_PRESENT           1 
#define __ARM_COMPAT_H          1 

#include "core_cm33.h"                       /* Processor and core peripherals */
#include "system_acm32g103.h"
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
#pragma pop
#elif defined (__ICCARM__)
/* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#elif defined (__GNUC__)
/* anonymous unions are enabled by default */
#elif defined (__TMS470__)
/* anonymous unions are enabled by default */
#elif defined (__TASKING__)
#pragma warning restore
#elif defined (__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/*-------------------Bit Opertions------------------------*/
#define BIT0            (1U << 0)
#define BIT1            (1U << 1)
#define BIT2            (1U << 2)
#define BIT3            (1U << 3)
#define BIT4            (1U << 4)
#define BIT5            (1U << 5)
#define BIT6            (1U << 6)
#define BIT7            (1U << 7)
#define BIT8            (1U << 8)
#define BIT9            (1U << 9)
#define BIT10           (1U << 10)
#define BIT11           (1U << 11)
#define BIT12           (1U << 12)
#define BIT13           (1U << 13)
#define BIT14           (1U << 14)
#define BIT15           (1U << 15)
#define BIT16           (1U << 16)
#define BIT17           (1U << 17)
#define BIT18           (1U << 18)
#define BIT19           (1U << 19)
#define BIT20           (1U << 20)
#define BIT21           (1U << 21)
#define BIT22           (1U << 22)
#define BIT23           (1U << 23)
#define BIT24           (1U << 24)
#define BIT25           (1U << 25)
#define BIT26           (1U << 26)
#define BIT27           (1U << 27)
#define BIT28           (1U << 28)
#define BIT29           (1U << 29)
#define BIT30           (1U << 30)
#define BIT31           (1U << 31) 


/*-------------------Peripheral memory map-------------------------*/

#define SRAM_BASE_ADDR         (0x20000000UL)
#define PERIPH_BASE_ADDR       (0x40000000UL)
#define QSPI_BASE_ADDR         (0x90000000UL)

#define APB1PERIPH_BASE_ADDR   (PERIPH_BASE_ADDR)
#define APB2PERIPH_BASE_ADDR   (PERIPH_BASE_ADDR + 0x10000UL)
#define AHB1PERIPH_BASE_ADDR   (PERIPH_BASE_ADDR + 0x20000UL)
#define AHB2PERIPH_BASE_ADDR   (PERIPH_BASE_ADDR + 0x8000000UL)

///*----------------------APB1 peripherals------------------------*/
#define TIM2_BASE_ADDR         (APB1PERIPH_BASE_ADDR) 
#define TIM3_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00000400UL) 
#define TIM4_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00000800UL) 
#define TIM6_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00001000UL)
#define TIM7_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00001400UL)

#define RTC_BASE_ADDR          (APB1PERIPH_BASE_ADDR + 0x00002800UL)
#define WDT_BASE_ADDR          (APB1PERIPH_BASE_ADDR + 0x00002C00UL)
#define IWDT_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00003000UL)

#define I2S1_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00003800UL)
#define I2S2_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00003C00UL)

#define UART2_BASE_ADDR        (APB1PERIPH_BASE_ADDR + 0x00004400UL)
#define UART3_BASE_ADDR        (APB1PERIPH_BASE_ADDR + 0x00004800UL)
#define UART4_BASE_ADDR        (APB1PERIPH_BASE_ADDR + 0x00004C00UL)

#define I2C1_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00005400UL)
#define I2C2_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00005800UL)

#define CAN1_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00006400UL)
#define CAN2_BASE_ADDR         (APB1PERIPH_BASE_ADDR + 0x00006800UL)

#define PMU_BASE_ADDR          (APB1PERIPH_BASE_ADDR + 0x00007000UL)
#define LPTIM1_BASE_ADDR       (APB1PERIPH_BASE_ADDR + 0x00007C00UL)
#define LPUART_BASE_ADDR       (APB1PERIPH_BASE_ADDR + 0x00008000UL)


///*----------------------APB2 peripherals------------------------*/
#define SYSCFG_BASE_ADDR       (APB2PERIPH_BASE_ADDR)
#define VREFBUF_BASE_ADDR      (APB2PERIPH_BASE_ADDR + 0x00000030UL)
#define COMP_BASE_ADDR          (APB2PERIPH_BASE_ADDR + 0x00000200UL)
#define OPA_BASE_ADDR          (APB2PERIPH_BASE_ADDR + 0x00000300UL)
#define EXTI_BASE_ADDR         (APB2PERIPH_BASE_ADDR + 0x00000400UL)

#define TIM1_BASE_ADDR         (APB2PERIPH_BASE_ADDR + 0x00002C00UL)
#define TIM8_BASE_ADDR         (APB2PERIPH_BASE_ADDR + 0x00003400UL)
#define UART1_BASE_ADDR        (APB2PERIPH_BASE_ADDR + 0x00003800UL)

#define TIM15_BASE_ADDR        (APB2PERIPH_BASE_ADDR + 0x00004000UL)
#define TIM16_BASE_ADDR        (APB2PERIPH_BASE_ADDR + 0x00004400UL)
#define TIM17_BASE_ADDR        (APB2PERIPH_BASE_ADDR + 0x00004800UL)


///*----------------------AHB1 peripherals------------------------*/
#define RCC_BASE_ADDR          (AHB1PERIPH_BASE_ADDR + 0x00001000UL)
#define EFC_BASE_ADDR          (AHB1PERIPH_BASE_ADDR + 0x00002000UL)
#define CRC_BASE_ADDR          (AHB1PERIPH_BASE_ADDR + 0x00003000UL)
#define SPI1_BASE_ADDR         (AHB1PERIPH_BASE_ADDR + 0x00010000UL)
#define SPI2_BASE_ADDR         (AHB1PERIPH_BASE_ADDR + 0x00010400UL)
#define SPI3_BASE_ADDR         (AHB1PERIPH_BASE_ADDR + 0x00010800UL)

#define DMA1_BASE_ADDR         (PERIPH_BASE_ADDR+0x31000UL)
#define DMA1_Channel0_BASE     (DMA1_BASE_ADDR + 0x00000100UL)
#define DMA1_Channel1_BASE     (DMA1_BASE_ADDR + 0x00000120UL)
#define DMA1_Channel2_BASE     (DMA1_BASE_ADDR + 0x00000140UL)
#define DMA1_Channel3_BASE     (DMA1_BASE_ADDR + 0x00000160UL)
#define DMA1_Channel4_BASE     (DMA1_BASE_ADDR + 0x00000180UL)
#define DMA1_Channel5_BASE     (DMA1_BASE_ADDR + 0x000001A0UL)
#define DMA1_Channel6_BASE     (DMA1_BASE_ADDR + 0x000001C0UL)
#define DMA1_Channel7_BASE     (DMA1_BASE_ADDR + 0x000001E0UL)
#define DMA2_BASE_ADDR         (PERIPH_BASE_ADDR+ 0x32000UL)
#define DMA2_Channel0_BASE     (DMA2_BASE_ADDR + 0x00000100UL)
#define DMA2_Channel1_BASE     (DMA2_BASE_ADDR + 0x00000120UL)
#define DMA2_Channel2_BASE     (DMA2_BASE_ADDR + 0x00000140UL)
#define DMA2_Channel3_BASE     (DMA2_BASE_ADDR + 0x00000160UL)
#define DMA2_Channel4_BASE     (DMA2_BASE_ADDR + 0x00000180UL)
#define DMA2_Channel5_BASE     (DMA2_BASE_ADDR + 0x000001A0UL)
#define DMA2_Channel6_BASE     (DMA2_BASE_ADDR + 0x000001C0UL)
#define DMA2_Channel7_BASE     (DMA2_BASE_ADDR + 0x000001E0UL)

#define USB_BASE_ADDR          (AHB1PERIPH_BASE_ADDR + 0x00030000UL)    

///*----------------------AHB2 peripherals------------------------*/
#define GPIOA_BASE_ADDR        (AHB2PERIPH_BASE_ADDR)
#define GPIOB_BASE_ADDR        (AHB2PERIPH_BASE_ADDR + 0x00000400UL)
#define GPIOC_BASE_ADDR        (AHB2PERIPH_BASE_ADDR + 0x00000800UL)
#define GPIOD_BASE_ADDR        (AHB2PERIPH_BASE_ADDR + 0x00000C00UL)
#define GPIOE_BASE_ADDR        (AHB2PERIPH_BASE_ADDR + 0x00001000UL)
#define GPIOF_BASE_ADDR        (AHB2PERIPH_BASE_ADDR + 0x00001400UL)
#define ADC1_BASE_ADDR         (AHB2PERIPH_BASE_ADDR + 0x08000000UL)
#define ADC2_BASE_ADDR         (AHB2PERIPH_BASE_ADDR + 0x08000100UL)
#define ADC_COMMOM_BASE_ADDR   (AHB2PERIPH_BASE_ADDR + 0x08000300UL)
#define DAC_BASE_ADDR          (AHB2PERIPH_BASE_ADDR + 0x08000800UL)
#define AES_BASE_ADDR          (AHB2PERIPH_BASE_ADDR + 0x08060000UL)    
#define FAU_BASE_ADDR          (AHB2PERIPH_BASE_ADDR + 0x08060400UL)    
#define HRNG_BASE_ADDR         (AHB2PERIPH_BASE_ADDR + 0x08060800UL)     
#define HASH_BASE_ADDR         (AHB2PERIPH_BASE_ADDR + 0x08060C00UL)     

///*----------------------QSPI Memory----------------------------*/
#define QSPI1_BASE_ADDR        (QSPI_BASE_ADDR)

///*----------------------External memory------------------------*/
#define EXMC_BASE_ADDR         (0xA0000000UL)    
#define EXMC_EX_BASE_ADDR      (EXMC_BASE_ADDR + 0x0104) 

#define ROM_BASE_ADDR                    0x12000000

///*----------------------EFC------------------------*/

//#define ROM_Start 
#ifdef ROM_Start

#define EFLASH_BASE_ADDR  ((uint32_t)0x10000000)

#else

#define EFLASH_BASE_ADDR  ((uint32_t)0x00000000)
#endif


/*--------   Peripheral_registers_structures   ---------------*/
    
///*----------------------UART------------------------*/
typedef struct
{
    __IO uint32_t DR;       //0x00
    __IO uint32_t FR;       //0x04
    __IO uint32_t BRR;      //0x08
    __IO uint32_t IE;       //0x0c
    __IO uint32_t ISR;      //0x10
    __IO uint32_t CR1;      //0x14
    __IO uint32_t CR2;      //0x18
    __IO uint32_t CR3;      //0x1c
    __IO uint32_t GTPR;     //0x20
    __IO uint32_t BCNT;     //0x24

}UART_TypeDef;


///*-----------------------CRC-------------------------*/
typedef struct
{
    __IO uint32_t DATA;     //0x00
    __IO uint32_t CTRL;     //0x04
    __IO uint32_t INIT;     //0x08
    __IO uint32_t RSV0;     
    __IO uint32_t OUTXOR;   //0x10
    __IO uint32_t POLY;     //0x14
    __IO uint32_t FDATA;    //0x18
}CRC_TypeDef;

///*-----------------------CMP-------------------------*/
typedef struct
{
    __IO uint32_t CR1;      //0x00
    __IO uint32_t CR2;      //0x04
    __IO uint32_t CR3;      //0x08
    __IO uint32_t CR4;      //0x0C
    __IO uint32_t SR;       //0x10
}COMP_TypeDef;

///*-----------------------OPA------------------------*/
typedef struct
{
    __IO uint32_t CSR1;     //0x00
    __IO uint32_t CSR2;     //0x04
    __IO uint32_t CSR3;     //0x08
}OPA_TypeDef;


///*------------------- EXTI  ----------------------*/
typedef struct
{
    __IO uint32_t IENR;     //0x00
    __IO uint32_t EENR;     //0x04
    __IO uint32_t RTENR;    //0x08
    __IO uint32_t FTENR;    //0x0C
    __IO uint32_t SWIER;    //0x10
    __IO uint32_t PDR;      //0x14
    __IO uint32_t CR1;      //0x18
    __IO uint32_t CR2;      //0x1C
}EXTI_TypeDef;

///*-----------------------ADC-------------------------*/
typedef struct
{
    __IO uint32_t SR;       //0x00
	__IO uint32_t IE;       //0x04
    __IO uint32_t CR1;      //0x08
    __IO uint32_t CR2;      //0x0C
	__IO uint32_t SMPR1;    //0x10
	__IO uint32_t SMPR2;    //0x14
	__IO uint32_t SMPR3;    //0x18
	__IO uint32_t HTR;      //0x1C
	__IO uint32_t LTR;      //0x20    
    __IO uint32_t SQR1;     //0x24
    __IO uint32_t SQR2;     //0x28
    __IO uint32_t SQR3;     //0x2C
    __IO uint32_t JSQR;     //0x30
    __IO uint32_t JDR1;     //0x34
	__IO uint32_t JDR2;     //0x38
	__IO uint32_t JDR3;     //0x3C
	__IO uint32_t JDR4;     //0x40
	__IO uint32_t RSV;
    __IO uint32_t DR;       //0x48
	__IO uint32_t DIFF;     //0x4C
    __IO uint32_t SIGN;     //0x50
	__IO uint32_t RSV1[3];  //
	__IO uint32_t OFR1;     //0x60
	__IO uint32_t OFR2;     //0x64
	__IO uint32_t OFR3;     //0x68
	__IO uint32_t OFR4;     //0x6C
	__IO uint32_t RSV2[4];
	__IO uint32_t ANACFG;   //0x80
}ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSD;        // ADC Common status register,                  Address offset: ADC1 base address + 0x300 
  __IO uint32_t CCR;        // ADC common control register,                 Address offset: ADC1 base address + 0x304 
  __IO uint32_t CDR;        // ADC common regular data register for dual AND triple modes,  Address offset: ADC1 base address + 0x308
  __IO uint32_t CTSREF;
} ADC_Common_TypeDef;


///*------------------- SPI  ----------------------*/
typedef struct
{
    __IO uint32_t DAT;      //0x00
    __IO uint32_t BAUD;     //0x04
    __IO uint32_t CTL;      //0x08
    __IO uint32_t TX_CTL;   //0x0C
    __IO uint32_t RX_CTL;   //0x10
    __IO uint32_t IE;       //0x14
    __IO uint32_t STATUS;   //0x18
    __IO uint32_t TX_DELAY; //0x1C
    __IO uint32_t BATCH;    //0x20
    __IO uint32_t CS;       //0x24
    __IO uint32_t OUT_EN;   //0x28
    __IO uint32_t MEMO_ACC; //0x2C
    __IO uint32_t CMD;      //0x30
    __IO uint32_t PARA;     //0x34
}SPI_TypeDef;

///*-----------------------DMAC------------------------*/
typedef struct
{
    __IO uint32_t INTSTATUS;       //0x00
    __IO uint32_t INTTCSTATUS;    //0x04
    __IO uint32_t INTTCCLR;       //0x08
    __IO uint32_t INTERRSTATUS;   //0x0C
    __IO uint32_t INTERRCLR;      //0x10
    __IO uint32_t RAWINTTCSTATUS;//0x14
    __IO uint32_t RAWINTERRSTATUS;//0x18
    __IO uint32_t ENCHSTATUS;     //0x1C
    __IO uint32_t RSV0[4];          
    __IO uint32_t CONFIG;           //0x30
    __IO uint32_t SYNCLO;          //0x34
    __IO uint32_t SYNCHI;          //0x38
}DMA_TypeDef;  


typedef struct
{
    __IO uint32_t CHSRCADDR;     
    __IO uint32_t CHDESTADDR;    
    __IO uint32_t CHLLI;
    __IO uint32_t CHCTRL;
    __IO uint32_t CHCONFIG;
}DMA_Channel_TypeDef;


#define REG_DMAC_ChSrcAddr(x)            (*(volatile uint32_t *)(DMAC_BASE_ADDR + 0x100 + 0x20 * (x)))
#define REG_DMAC_ChDestAddr(x)           (*(volatile uint32_t *)(DMAC_BASE_ADDR + 0x104 + 0x20 * (x)))
#define REG_DMAC_ChLinkList(x)           (*(volatile uint32_t *)(DMAC_BASE_ADDR + 0x108 + 0x20 * (x)))
#define REG_DMAC_ChCtrl(x)               (*(volatile uint32_t *)(DMAC_BASE_ADDR + 0x10C + 0x20 * (x)))
#define REG_DMAC_ChConfig(x)             (*(volatile uint32_t *)(DMAC_BASE_ADDR + 0x110 + 0x20 * (x)))


///*------------------- I2S  ----------------------*/
typedef struct
{
    __IO uint32_t DAT;      //0x00
    __IO uint32_t CTL;      //0x04
    __IO uint32_t PSC;      //0x08
    __IO uint32_t IE;       //0x0C
    __IO uint32_t STATUS;   //0x10
}I2S_TypeDef;


///*------------------- I2C  ----------------------*/
typedef struct
{
    __IO uint32_t SLAVE_ADDR1;      //0x00
    __IO uint32_t CLK_DIV;          //0x04
    __IO uint32_t CR;               //0x08
    __IO uint32_t SR;               //0x0C
    __IO uint32_t DR;               //0x10
    __IO uint32_t SLAVE_ADDR2_3;    //0x14
    __IO uint32_t RSV0; 
    __IO uint32_t FILTER;           //0x1C
    __IO uint32_t RSV1; 
    __IO uint32_t TIMEOUT;          //0x24
}I2C_TypeDef;

///*------------------- WDT  ----------------------*/
typedef struct
{
    __IO uint32_t LOAD;         //0x00
    __IO uint32_t COUNT;        //0x04
    __IO uint32_t CTRL;         //0x08
    __IO uint32_t FEED;         //0x0C
    __IO uint32_t INTCLRTIME; //0x10
    __IO uint32_t RIS;          //0x14
}WDT_TypeDef;


///*------------------- IWDT  ----------------------*/
typedef struct
{
    __IO uint32_t CMDR;         //0x00
    __IO uint32_t PR;           //0x04
    __IO uint32_t RLR;          //0x08
    __IO uint32_t SR;           //0x0C
    __IO uint32_t WINR;         //0x10
    __IO uint32_t WUTR;         //0x14
}IWDT_TypeDef;

///*------------------- RTC¡¢PMU  ----------------------*/
typedef struct
{
    __IO uint32_t WP;           //0x00
    __IO uint32_t IE;           //0x04
    __IO uint32_t SR;           //0x08
    __IO uint32_t SEC;          //0x0C
    __IO uint32_t MIN;          //0x10
    __IO uint32_t HOUR;         //0x14
    __IO uint32_t DATE;         //0x18
    __IO uint32_t WEEK;         //0x1C
    __IO uint32_t MONTH;        //0x20
    __IO uint32_t YEAR;         //0x24
    __IO uint32_t ALM;          //0x28
    __IO uint32_t CR;           //0x2C
    __IO uint32_t ADJUST;       //0x30
    __IO uint32_t RSV0[4];
    __IO uint32_t CLK_STAMP1;   //0x44
    __IO uint32_t CAL_STAMP1;   //0x48
    __IO uint32_t CLK_STAMP2;   //0x4C
    __IO uint32_t CAL_STAMP2;   //0x50
    __IO uint32_t WUTR;         //0x54
    __IO uint32_t RSV2[7];
    __IO uint32_t BAKUP[16];    //0x70
}RTC_TypeDef;

typedef struct
{
    __IO uint32_t CTRL0;       //0x00
    __IO uint32_t CTRL1;       //0x04
    __IO uint32_t CTRL2;       //0x08
    __IO uint32_t CTRL3;       //0x0C
    __IO uint32_t SR;          //0x10
    __IO uint32_t STCLR;       //0x14
	__IO uint32_t IOSEL;       //0x18
    __IO uint32_t RSV[42];
    __IO uint32_t ANATEST_SR;  //0xC0
    __IO uint32_t LDOCAL;      //0xC4
    __IO uint32_t LDOCR;       //0xC8
}PMU_TypeDef;

///*-----------------------CAN------------------------*/

typedef union 
{
   __IO uint32_t DATABUF[13];
}DF_typedef;


typedef struct
{
    __IO uint32_t MOD;      //0x00
    __IO uint32_t CMR;      //0x04
    __IO uint32_t SR;       //0x08
    __IO uint32_t IR;       //0x0C
    __IO uint32_t IER;      //0x10
    __IO uint32_t BTR;      //0x14
    __IO uint32_t OCR;      //0x18
    __IO uint32_t ECCR;     //0x1C
    __IO uint32_t ERRCNTR;  //0x20
    __IO uint32_t RSR;      //0x24
//    __IO uint32_t ACR0;   //0x28
//    __IO uint32_t ACR1;   //0x2C
//    __IO uint32_t ACR2;   //0x30
//    __IO uint32_t ACR3;   //0x34
//    __IO uint32_t ACR4;   //0x38
//    __IO uint32_t ACR5;   //0x3C
//    __IO uint32_t ACR6;   //0x40
//    __IO uint32_t AMR0;   //0x44
//    __IO uint32_t AMR1;   //0x48
//    __IO uint32_t AMR2;   //0x4C
//    __IO uint32_t AMR3;   //0x50
//    __IO uint32_t AMR4;   //0x54
//    __IO uint32_t AMR5;   //0x58
//    __IO uint32_t AMR6;   //0x5C 
    __IO uint32_t FILTER[14];   //0x28-0x5C      
    DF_typedef DF;              //0x60~0x90
    __IO uint32_t RSV[4];  
    __IO uint32_t RXFIFO[64];   //0xA0~0x19C
    __IO uint32_t TXFIFO[13];   //0x1A0~0x1D0
}CAN_TypeDef;  

///*-----------------------RCC------------------------*/
typedef struct
{
    __IO uint32_t RCR;      //0x00
    __IO uint32_t RSR;      //0x04
    __IO uint32_t APB1RSTR; //0x08
    __IO uint32_t APB2RSTR; //0x0C
    __IO uint32_t AHBRSTR;  //0x10
    __IO uint32_t CCR1;     //0x14
    __IO uint32_t CCR2;     //0x18
    __IO uint32_t CIR;      //0x1C
    __IO uint32_t APB1ENR;  //0x20
    __IO uint32_t APB2ENR;  //0x24
    __IO uint32_t AHBENR;   //0x28
    __IO uint32_t RC64MCR;  //0x2C
    __IO uint32_t XTHCR;    //0x30
    __IO uint32_t PLLCR;    //0x34
    __IO uint32_t CLKOCR;   //0x38
     __IO uint32_t STDBYCTRL;//0x3c
}RCC_TypeDef;  


///*----------------------EXMC------------------------*/
typedef struct
{
  __IO uint32_t SNCTLCFG[8];   
} EXMC_TypeDef; 
  
typedef struct
{
  __IO uint32_t SNWTCFG[7];
} EXMC_Ex_TypeDef;


///*-----------------------iCache------------------------*/
typedef struct
{
    __IO uint32_t REG_CACR;//0x00

}ICACHE_TypeDef; 

///*------------------- LPUART Registers ----------------------*/
typedef struct
{
    __IO uint32_t RXDR;     // 0x00
    __IO uint32_t TXDR;     // 0x04
    __IO uint32_t LCR;      // 0x08
    __IO uint32_t CR;       // 0x0C
    __IO uint32_t IBAUD;    // 0x10
    __IO uint32_t FBAUD;    // 0x14
    __IO uint32_t IE;       // 0x18
    __IO uint32_t SR;       // 0x1C
    __IO uint32_t ADDR;     // 0x20
}LPUART_TypeDef;

///*----------------------GPIO_TypeDef-----------------------*/
typedef struct
{
  __IO uint32_t MD;         //0x00    
  __IO uint32_t OTYP;       //0x04
  __IO uint32_t PUPD;       //0x08
  __IO uint32_t IDATA;      //0x0C
  __IO uint32_t ODATA;      //0x10
  __IO uint32_t BSC;        //0x14
  __IO uint32_t AF0;        //0x18
  __IO uint32_t AF1;        //0x1C
  __IO uint32_t DS0;        //0x20 
  __IO uint32_t DS1;        //0x24 
  __IO uint32_t SMIT;       //0x28
  __IO uint32_t LOCK;       //0x2C           
  __IO uint32_t AIEN;       //0x30     
} GPIO_TypeDef;  

///*------------------- FLASH Registers ----------------------*/
typedef struct
{
    __IO uint32_t CTRL;     //0x00
    __IO uint32_t SEC;      //0x04
    __IO uint32_t ADCT;     //0x08
    __IO uint32_t ERTO;     //0x0C
    __IO uint32_t WRTO;     //0x10
    __IO uint32_t STATUS;   //0x14
    __IO uint32_t INTSTATUS;//0x18
    __IO uint32_t INTEN;    //0x1C
    __IO uint32_t RSV1;     //0x20
    __IO uint32_t EDCTRL;   //0x24
    __IO uint32_t TRIM0 ;   //0x28
    __IO uint32_t TRIM1 ;   //0x2C
    __IO uint32_t TRIM2 ;   //0x30
    __IO uint32_t FF_DEC;   //0x34
    __IO uint32_t RSV2[10]; 
    __IO uint32_t MEMDENSITY;   //0x60
    __IO uint32_t IPCKEN;       //0x64
    __IO uint32_t PCROP_AreaA;  //0x68
    __IO uint32_t PCROP_AreaB ; //0x6C
    __IO uint32_t WRP_AreaA;    //0x70
    __IO uint32_t WRP_AreaB;    //0x74
    __IO uint32_t SEC_SIZE ;    //0x78
    __IO uint32_t IPCK2EN;      //0x7C
    __IO uint32_t IPCK3EN;      //0x80
}EFC_TypeDef;  

///*------------------- Timer Registers ----------------------*/
typedef struct
{
    __IO uint32_t CR1;      // 0x00
    __IO uint32_t CR2;      // 0x04
    __IO uint32_t SMCR;     // 0x08
    __IO uint32_t DIER;     // 0x0C
    __IO uint32_t SR;       // 0x10
    __IO uint32_t EGR;      // 0x14
    __IO uint32_t CCMR1;    // 0x18
    __IO uint32_t CCMR2;    // 0x1C
    __IO uint32_t CCER;     // 0x20
    __IO uint32_t CNT;      // 0x24
    __IO uint32_t PSC;      // 0x28
    __IO uint32_t ARR;      // 0x2C
    __IO uint32_t RCR;      // 0x30
    __IO uint32_t CCR1;     // 0x34
    __IO uint32_t CCR2;     // 0x38
    __IO uint32_t CCR3;     // 0x3C
    __IO uint32_t CCR4;     // 0x40
    __IO uint32_t BDTR;     // 0x44
    __IO uint32_t DCR;      // 0x48
    __IO uint32_t DMAR;     // 0x4C
    __IO uint32_t OR1;      // 0x50
    __IO uint32_t CCMR3;    // 0x54
    __IO uint32_t CCR5;     // 0x58
    __IO uint32_t CCR6;     // 0x5C
    __IO uint32_t AF1;      // 0x60
    __IO uint32_t AF2;      // 0x64
    __IO uint32_t TISEL;    // 0x68
    __IO uint32_t DBER;     // 0x6C
}TIM_TypeDef;

///*----------------------SYSCFG_TypeDef-----------------------*/
typedef struct
{
  __IO uint32_t SYSCR;      //0x00
  __IO uint32_t WMR;        //0x04
  __IO uint32_t VER;        //0x08
  __IO uint32_t RSV;
  __IO uint32_t PHYCFG;     //0x10
  __IO uint32_t DUMMY;      //0x14  
} SYSCFG_TypeDef;  


///*----------------------LPTIM_TypeDef-----------------------*/
typedef struct
{
  __IO uint32_t ISR;        //0x00
  __IO uint32_t ICR;        //0x04
  __IO uint32_t IER;        //0x08
  __IO uint32_t CFGR;       //0x0C
  __IO uint32_t CR;         //0x10
  __IO uint32_t CMP;        //0x14   
  __IO uint32_t ARR;        //0x18    
  __IO uint32_t CNT;        //0x1C  
  __IO uint32_t RSV; 
  __IO uint32_t CFGR2;      //0x24 
  __IO uint32_t RCR;        //0x2C
} LPTIM_TypeDef;    

///*------------------- DAC  ----------------------*/
typedef struct
{
    __IO uint32_t CR;       //0x00
    __IO uint32_t SWTRIGR;  //0x04
    __IO uint32_t DHR12R1;  //0x08
    __IO uint32_t DHR12L1;  //0x0C
    __IO uint32_t DHR8R1;   //0x10
    __IO uint32_t DHR12R2;  //0x14
    __IO uint32_t DHR12L2;  //0x18
    __IO uint32_t DHR8R2;   //0x1C
    __IO uint32_t DHR12RD;  //0x20
    __IO uint32_t DHR12LD;  //0x24
    __IO uint32_t DHR8RD;   //0x28
    __IO uint32_t DOR1;     //0x2C
    __IO uint32_t DOR2;     //0x30
    __IO uint32_t SR;       //0x34
    __IO uint32_t CCR;      //0x38
    __IO uint32_t MCR;      //0x3C
    __IO uint32_t SHSR1;    //0x40
    __IO uint32_t SHSR2;    //0x44
    __IO uint32_t SHHR;     //0x48
    __IO uint32_t SHRR;     //0x4C
    __IO uint32_t RSV[2];
    __IO uint32_t STR1;     //0x58
    __IO uint32_t STR2;     //0x5C
    __IO uint32_t STMODR;   //0x60
}DAC_TypeDef;  

///*------------------- USB Registers ----------------------*/
typedef struct
{
    __IO uint32_t WORKING_MODE;
    __IO uint32_t EPxCSR[5]; 
    __IO uint32_t USB_ADDR;
    __IO uint32_t SETIP_0_3_DATA;
    __IO uint32_t SETIP_4_7_DATA;
    __IO uint32_t EPADDR_CFG;
    __IO uint32_t CURRENT_PID;
    __IO uint32_t CURRENT_FRAME_NUMBER;
    __IO uint32_t CRC_ERROR_CNT;
    __IO uint32_t USB_STATUS_DETECT_CNT;
    __IO uint32_t RSV0;
    __IO uint32_t RSV1;
    __IO uint32_t EPxSENDBN[5];
}USB_CTRLTypeDef;

///*------------------- USB interrupt access Registers ----------------------*/
typedef struct
{
    __IO uint32_t INT_STAT_RAW;    
    __IO uint32_t INT_EN;  
    __IO uint32_t RSV;  
    __IO uint32_t INT_CLR;       
}USB_INTTypeDef;  



///*--------------------Peripheral declatation--------------------*/

#define TIM2            ((TIM_TypeDef *)TIM2_BASE_ADDR)
#define TIM3            ((TIM_TypeDef *)TIM3_BASE_ADDR)
#define TIM4            ((TIM_TypeDef *)TIM4_BASE_ADDR)
#define TIM6            ((TIM_TypeDef *)TIM6_BASE_ADDR)
#define TIM7            ((TIM_TypeDef *)TIM7_BASE_ADDR)

#define PMU             ((PMU_TypeDef *)PMU_BASE_ADDR)
#define RTC             ((RTC_TypeDef *)RTC_BASE_ADDR)
#define WDT             ((WDT_TypeDef *)WDT_BASE_ADDR)
#define IWDT            ((IWDT_TypeDef *)IWDT_BASE_ADDR)
#define UART2           ((UART_TypeDef *)UART2_BASE_ADDR)
#define UART3           ((UART_TypeDef *)UART3_BASE_ADDR)
#define UART4           ((UART_TypeDef *)UART4_BASE_ADDR)
#define I2C1            ((I2C_TypeDef *)I2C1_BASE_ADDR)
#define I2C2            ((I2C_TypeDef *)I2C2_BASE_ADDR)
#define I2S1            ((I2S_TypeDef *)I2S1_BASE_ADDR)
#define I2S2            ((I2S_TypeDef *)I2S2_BASE_ADDR)
#define CAN1            ((CAN_TypeDef *)CAN1_BASE_ADDR)
#define CAN2            ((CAN_TypeDef *)CAN2_BASE_ADDR)
#define LPUART          ((LPUART_TypeDef *)LPUART_BASE_ADDR)
#define EXTI            ((EXTI_TypeDef *)EXTI_BASE_ADDR)
#define CRC             ((CRC_TypeDef *)CRC_BASE_ADDR)
#define COMP            ((COMP_TypeDef *)COMP_BASE_ADDR)
#define OPA             ((OPA_TypeDef *)OPA_BASE_ADDR)
#define ADC1            ((ADC_TypeDef *)ADC1_BASE_ADDR)
#define ADC2            ((ADC_TypeDef *)ADC2_BASE_ADDR)
#define ADC12_COMMON    ((ADC_Common_TypeDef *) ADC_COMMOM_BASE_ADDR)
#define TIM1            ((TIM_TypeDef *)TIM1_BASE_ADDR)
#define TIM8            ((TIM_TypeDef *)TIM8_BASE_ADDR)
#define UART1           ((UART_TypeDef *)UART1_BASE_ADDR)
#define TIM15           ((TIM_TypeDef *)TIM15_BASE_ADDR)
#define TIM16           ((TIM_TypeDef *)TIM16_BASE_ADDR)
#define TIM17           ((TIM_TypeDef *)TIM17_BASE_ADDR)

#define SPI1            ((SPI_TypeDef *)SPI1_BASE_ADDR)
#define SPI2            ((SPI_TypeDef *)SPI2_BASE_ADDR)
#define SPI3            ((SPI_TypeDef *)SPI3_BASE_ADDR)

#define DMA1            ((DMA_TypeDef *)DMA1_BASE_ADDR)
#define DMA2            ((DMA_TypeDef *)DMA2_BASE_ADDR)
#define DMA1_Channel0   ((DMA_Channel_TypeDef *)DMA1_Channel0_BASE)
#define DMA1_Channel1   ((DMA_Channel_TypeDef *)DMA1_Channel1_BASE)
#define DMA1_Channel2   ((DMA_Channel_TypeDef *)DMA1_Channel2_BASE)
#define DMA1_Channel3   ((DMA_Channel_TypeDef *)DMA1_Channel3_BASE)
#define DMA1_Channel4   ((DMA_Channel_TypeDef *)DMA1_Channel4_BASE)
#define DMA1_Channel5   ((DMA_Channel_TypeDef *)DMA1_Channel5_BASE)
#define DMA1_Channel6   ((DMA_Channel_TypeDef *)DMA1_Channel6_BASE)
#define DMA1_Channel7   ((DMA_Channel_TypeDef *)DMA1_Channel7_BASE)
#define DMA2_Channel0   ((DMA_Channel_TypeDef *)DMA2_Channel0_BASE)
#define DMA2_Channel1   ((DMA_Channel_TypeDef *)DMA2_Channel1_BASE)
#define DMA2_Channel2   ((DMA_Channel_TypeDef *)DMA2_Channel2_BASE)
#define DMA2_Channel3   ((DMA_Channel_TypeDef *)DMA2_Channel3_BASE)
#define DMA2_Channel4   ((DMA_Channel_TypeDef *)DMA2_Channel4_BASE)
#define DMA2_Channel5   ((DMA_Channel_TypeDef *)DMA2_Channel5_BASE)
#define DMA2_Channel6   ((DMA_Channel_TypeDef *)DMA1_Channel6_BASE)
#define DMA2_Channel7   ((DMA_Channel_TypeDef *)DMA1_Channel7_BASE)

#define ICACHE          ((ICACHE_TypeDef *)ICACHE_BASE_ADDR)
#define EFC             ((EFC_TypeDef *)EFC_BASE_ADDR)  
#define RCC             ((RCC_TypeDef *)RCC_BASE_ADDR)

#define GPIOA           ((GPIO_TypeDef *) GPIOA_BASE_ADDR)
#define GPIOB           ((GPIO_TypeDef *) GPIOB_BASE_ADDR)
#define GPIOC           ((GPIO_TypeDef *) GPIOC_BASE_ADDR)
#define GPIOD           ((GPIO_TypeDef *) GPIOD_BASE_ADDR)
#define GPIOE           ((GPIO_TypeDef *) GPIOE_BASE_ADDR)
#define GPIOF           ((GPIO_TypeDef *) GPIOF_BASE_ADDR)
#define EXMC            ((EXMC_TypeDef *) EXMC_BASE_ADDR)
#define EXMC_Ex         ((EXMC_Ex_TypeDef*) EXMC_EX_BASE_ADDR)  
#define DAC             ((DAC_TypeDef *)DAC_BASE_ADDR) 

#define SYSCFG          ((SYSCFG_TypeDef*) SYSCFG_BASE_ADDR)    
#define LPTIM1          ((LPTIM_TypeDef *) LPTIM1_BASE_ADDR) 
#define USBCTRL         ((USB_CTRLTypeDef *)USB_BASE_ADDR)
#define USBINT          ((USB_INTTypeDef *)(USB_BASE_ADDR+0xFFE4))  

///*-----------  Peripheral_Registers_Bits_Definition  -----------------*/


/***************  Bits definition for RCC_RCR register  **********************/

#define RCC_RCR_SRSTMAP_Pos                     ( 31U )
#define RCC_RCR_SRSTMAP_Msk                     ( 0x1UL << RCC_RCR_SRSTMAP_Pos )
#define RCC_RCR_SRSTMAP                         ( RCC_RCR_SRSTMAP_Msk )

#define RCC_RCR_SRSTNOMAP_Pos                   ( 30U )
#define RCC_RCR_SRSTNOMAP_Msk                   ( 0x1UL << RCC_RCR_SRSTNOMAP_Pos )
#define RCC_RCR_SRSTNOMAP                       ( RCC_RCR_SRSTNOMAP_Msk )

#define RCC_RCR_EFCRST_Pos                      ( 29U )
#define RCC_RCR_EFCRST_Msk                      ( 0x1UL << RCC_RCR_EFCRST_Pos )
#define RCC_RCR_EFCRST                          ( RCC_RCR_EFCRST_Msk )

#define RCC_RCR_REMAPIMP_Pos                    ( 16U )
#define RCC_RCR_REMAPIMP_Msk                    ( 0x1UL << RCC_RCR_REMAPIMP_Pos )
#define RCC_RCR_REMAPIMP                        ( RCC_RCR_REMAPIMP_Msk )

#define RCC_RCR_LOCKRSTEN_Pos                   ( 3U )
#define RCC_RCR_LOCKRSTEN_Msk                   ( 0x1UL << RCC_RCR_LOCKRSTEN_Pos )
#define RCC_RCR_LOCKRSTEN                       ( RCC_RCR_LOCKRSTEN_Msk )

#define RCC_RCR_IWDTRSTEN_Pos                   ( 2U )
#define RCC_RCR_IWDTRSTEN_Msk                   ( 0x1UL << RCC_RCR_IWDTRSTEN_Pos )
#define RCC_RCR_IWDTRSTEN                       ( RCC_RCR_IWDTRSTEN_Msk )

#define RCC_RCR_WDTRSTEN_Pos                    ( 1U )
#define RCC_RCR_WDTRSTEN_Msk                    ( 0x1UL << RCC_RCR_WDTRSTEN_Pos )
#define RCC_RCR_WDTRSTEN                        ( RCC_RCR_WDTRSTEN_Msk )

#define RCC_RCR_LVDRSTEN_Pos                    ( 0U )
#define RCC_RCR_LVDRSTEN_Msk                    ( 0x1UL << RCC_RCR_LVDRSTEN_Pos )
#define RCC_RCR_LVDRSTEN                        ( RCC_RCR_LVDRSTEN_Msk )

/***************  Bits definition for RCC_RSR register  **********************/

#define RCC_RSR_RSTFLAGCLR_Pos                  ( 16U )
#define RCC_RSR_RSTFLAGCLR_Msk                  ( 0x1UL << RCC_RSR_RSTFLAGCLR_Pos )
#define RCC_RSR_RSTFLAGCLR                      ( RCC_RSR_RSTFLAGCLR_Msk )

#define RCC_RSR_PWRRSTF_Pos                     ( 10U )
#define RCC_RSR_PWRRSTF_Msk                     ( 0x1UL << RCC_RSR_PWRRSTF_Pos )
#define RCC_RSR_PWRRSTF                         ( RCC_RSR_PWRRSTF_Msk )

#define RCC_RSR_POR12RSTF_Pos                   ( 9U )
#define RCC_RSR_POR12RSTF_Msk                   ( 0x1UL << RCC_RSR_POR12RSTF_Pos )
#define RCC_RSR_POR12RSTF                       ( RCC_RSR_POR12RSTF_Msk )

#define RCC_RSR_SRSTF_Pos                       ( 8U )
#define RCC_RSR_SRSTF_Msk                       ( 0x1UL << RCC_RSR_SRSTF_Pos )
#define RCC_RSR_SRSTF                           ( RCC_RSR_SRSTF_Msk )

#define RCC_RSR_SRSTNMF_Pos                     ( 7U )
#define RCC_RSR_SRSTNMF_Msk                     ( 0x1UL << RCC_RSR_SRSTNMF_Pos )
#define RCC_RSR_SRSTNMF                         ( RCC_RSR_SRSTNMF_Msk )

#define RCC_RSR_EFCRSTF_Pos                     ( 6U )
#define RCC_RSR_EFCRSTF_Msk                     ( 0x1UL << RCC_RSR_EFCRSTF_Pos )
#define RCC_RSR_EFCRSTF                         ( RCC_RSR_EFCRSTF_Msk )

#define RCC_RSR_RSTNF_Pos                       ( 5U )
#define RCC_RSR_RSTNF_Msk                       ( 0x1UL << RCC_RSR_RSTNF_Pos )
#define RCC_RSR_RSTNF                           ( RCC_RSR_RSTNF_Msk )

#define RCC_RSR_SYSREQRSTF_Pos                  ( 4U )
#define RCC_RSR_SYSREQRSTF_Msk                  ( 0x1UL << RCC_RSR_SYSREQRSTF_Pos )
#define RCC_RSR_SYSREQRSTF                      ( RCC_RSR_SYSREQRSTF_Msk )

#define RCC_RSR_LOCKUPRSTF_Pos                  ( 3U )
#define RCC_RSR_LOCKUPRSTF_Msk                  ( 0x1UL << RCC_RSR_LOCKUPRSTF_Pos )
#define RCC_RSR_LOCKUPRSTF                      ( RCC_RSR_LOCKUPRSTF_Msk )

#define RCC_RSR_IWDTRSTF_Pos                    ( 2U )
#define RCC_RSR_IWDTRSTF_Msk                    ( 0x1UL << RCC_RSR_IWDTRSTF_Pos )
#define RCC_RSR_IWDTRSTF                        ( RCC_RSR_IWDTRSTF_Msk )

#define RCC_RSR_WDTRSTF_Pos                     ( 1U )
#define RCC_RSR_WDTRSTF_Msk                     ( 0x1UL << RCC_RSR_WDTRSTF_Pos )
#define RCC_RSR_WDTRSTF                         ( RCC_RSR_WDTRSTF_Msk )

#define RCC_RSR_LVDRSTF_Pos                     ( 0U )
#define RCC_RSR_LVDRSTF_Msk                     ( 0x1UL << RCC_RSR_LVDRSTF_Pos )
#define RCC_RSR_LVDRSTF                         ( RCC_RSR_LVDRSTF_Msk )

/********************  Bit definition for RCC_APB1RSTR register  **************/

#define RCC_APB1RSTR_LPUART1RST_Pos             ( 31U )
#define RCC_APB1RSTR_LPUART1RST_Msk             ( 0x1UL << RCC_APB1RSTR_LPUART1RST_Pos )
#define RCC_APB1RSTR_LPUART1RST                 ( RCC_APB1RSTR_LPUART1RST_Msk )

#define RCC_APB1RSTR_LPTIM1RST_Pos              ( 30U )
#define RCC_APB1RSTR_LPTIM1RST_Msk              ( 0x1UL << RCC_APB1RSTR_LPTIM1RST_Pos )
#define RCC_APB1RSTR_LPTIM1RST                  ( RCC_APB1RSTR_LPTIM1RST_Msk )

#define RCC_APB1RSTR_PMURST_Pos                 ( 27U )
#define RCC_APB1RSTR_PMURST_Msk                 ( 0x1UL << RCC_APB1RSTR_PMURST_Pos )
#define RCC_APB1RSTR_PMURST                     ( RCC_APB1RSTR_PMURST_Msk )

#define RCC_APB1RSTR_CAN2RST_Pos                ( 25U )
#define RCC_APB1RSTR_CAN2RST_Msk                ( 0x1UL << RCC_APB1RSTR_CAN2RST_Pos )
#define RCC_APB1RSTR_CAN2RST                    ( RCC_APB1RSTR_CAN2RST_Msk )

#define RCC_APB1RSTR_CAN1RST_Pos                ( 24U )
#define RCC_APB1RSTR_CAN1RST_Msk                ( 0x1UL << RCC_APB1RSTR_CAN1RST_Pos )
#define RCC_APB1RSTR_CAN1RST                    ( RCC_APB1RSTR_CAN1RST_Msk )

#define RCC_APB1RSTR_I2C2RST_Pos                ( 22U )
#define RCC_APB1RSTR_I2C2RST_Msk                ( 0x1UL << RCC_APB1RSTR_I2C2RST_Pos )
#define RCC_APB1RSTR_I2C2RST                    ( RCC_APB1RSTR_I2C2RST_Msk )

#define RCC_APB1RSTR_I2C1RST_Pos                ( 21U )
#define RCC_APB1RSTR_I2C1RST_Msk                ( 0x1UL << RCC_APB1RSTR_I2C1RST_Pos )
#define RCC_APB1RSTR_I2C1RST                    ( RCC_APB1RSTR_I2C1RST_Msk )

#define RCC_APB1RSTR_UART4RST_Pos               ( 19U )
#define RCC_APB1RSTR_UART4RST_Msk               ( 0x1UL << RCC_APB1RSTR_UART4RST_Pos )
#define RCC_APB1RSTR_UART4RST                   ( RCC_APB1RSTR_UART4RST_Msk )

#define RCC_APB1RSTR_UART3RST_Pos               ( 18U )
#define RCC_APB1RSTR_UART3RST_Msk               ( 0x1UL << RCC_APB1RSTR_UART3RST_Pos )
#define RCC_APB1RSTR_UART3RST                   ( RCC_APB1RSTR_UART3RST_Msk )

#define RCC_APB1RSTR_UART2RST_Pos               ( 17U )
#define RCC_APB1RSTR_UART2RST_Msk               ( 0x1UL << RCC_APB1RSTR_UART2RST_Pos )
#define RCC_APB1RSTR_UART2RST                   ( RCC_APB1RSTR_UART2RST_Msk )

#define RCC_APB1RSTR_I2S2RST_Pos                ( 15U )
#define RCC_APB1RSTR_I2S2RST_Msk                ( 0x1UL << RCC_APB1RSTR_I2S2RST_Pos )
#define RCC_APB1RSTR_I2S2RST                    ( RCC_APB1RSTR_I2S2RST_Msk )

#define RCC_APB1RSTR_I2S1RST_Pos                ( 14U )
#define RCC_APB1RSTR_I2S1RST_Msk                ( 0x1UL << RCC_APB1RSTR_I2S1RST_Pos )
#define RCC_APB1RSTR_I2S1RST                    ( RCC_APB1RSTR_I2S1RST_Msk )

#define RCC_APB1RSTR_WDTRST_Pos                 ( 11U )
#define RCC_APB1RSTR_WDTRST_Msk                 ( 0x1UL << RCC_APB1RSTR_WDTRST_Pos )
#define RCC_APB1RSTR_WDTRST                     ( RCC_APB1RSTR_WDTRST_Msk )

#define RCC_APB1RSTR_TIM7RST_Pos                ( 5U )
#define RCC_APB1RSTR_TIM7RST_Msk                ( 0x1UL << RCC_APB1RSTR_TIM7RST_Pos )
#define RCC_APB1RSTR_TIM7RST                    ( RCC_APB1RSTR_TIM7RST_Msk )

#define RCC_APB1RSTR_TIM6RST_Pos                ( 4U )
#define RCC_APB1RSTR_TIM6RST_Msk                ( 0x1UL << RCC_APB1RSTR_TIM6RST_Pos )
#define RCC_APB1RSTR_TIM6RST                    ( RCC_APB1RSTR_TIM6RST_Msk )

#define RCC_APB1RSTR_TIM4RST_Pos                ( 2U )
#define RCC_APB1RSTR_TIM4RST_Msk                ( 0x1UL << RCC_APB1RSTR_TIM4RST_Pos )
#define RCC_APB1RSTR_TIM4RST                    ( RCC_APB1RSTR_TIM4RST_Msk )

#define RCC_APB1RSTR_TIM3RST_Pos                ( 1U )
#define RCC_APB1RSTR_TIM3RST_Msk                ( 0x1UL << RCC_APB1RSTR_TIM3RST_Pos )
#define RCC_APB1RSTR_TIM3RST                    ( RCC_APB1RSTR_TIM3RST_Msk )

#define RCC_APB1RSTR_TIM2RST_Pos                ( 0U )
#define RCC_APB1RSTR_TIM2RST_Msk                ( 0x1UL << RCC_APB1RSTR_TIM2RST_Pos )
#define RCC_APB1RSTR_TIM2RST                    ( RCC_APB1RSTR_TIM2RST_Msk )

/***************  Bits definition for RCC_APB2RSTR register  ***************/

#define RCC_APB2RSTR_TIM17RST_Pos             ( 13U )
#define RCC_APB2RSTR_TIM17RST_Msk             ( 0x1UL << RCC_APB2RSTR_TIM17RST_Pos )
#define RCC_APB2RSTR_TIM17RST                 ( RCC_APB2RSTR_TIM17RST_Msk )

#define RCC_APB2RSTR_TIM16RST_Pos             ( 12U )
#define RCC_APB2RSTR_TIM16RST_Msk             ( 0x1UL << RCC_APB2RSTR_TIM16RST_Pos )
#define RCC_APB2RSTR_TIM16RST                 ( RCC_APB2RSTR_TIM16RST_Msk )

#define RCC_APB2RSTR_TIM15RST_Pos             ( 11U )
#define RCC_APB2RSTR_TIM15RST_Msk             ( 0x1UL << RCC_APB2RSTR_TIM15RST_Pos )
#define RCC_APB2RSTR_TIM15RST                 ( RCC_APB2RSTR_TIM15RST_Msk )

#define RCC_APB2RSTR_UART1RST_Pos             ( 9U )
#define RCC_APB2RSTR_UART1RST_Msk             ( 0x1UL << RCC_APB2RSTR_UART1RST_Pos )
#define RCC_APB2RSTR_UART1RST                 ( RCC_APB2RSTR_UART1RST_Msk )

#define RCC_APB2RSTR_TIM8RST_Pos              ( 8U )
#define RCC_APB2RSTR_TIM8RST_Msk              ( 0x1UL << RCC_APB2RSTR_TIM8RST_Pos )
#define RCC_APB2RSTR_TIM8RST                  ( RCC_APB2RSTR_TIM8RST_Msk )

#define RCC_APB2RSTR_TIM1RST_Pos              ( 6U )
#define RCC_APB2RSTR_TIM1RST_Msk              ( 0x1UL << RCC_APB2RSTR_TIM1RST_Pos )
#define RCC_APB2RSTR_TIM1RST                  ( RCC_APB2RSTR_TIM1RST_Msk )

#define RCC_APB2RSTR_EXTIRST_Pos              ( 4U )
#define RCC_APB2RSTR_EXTIRST_Msk              ( 0x1UL << RCC_APB2RSTR_EXTIRST_Pos )
#define RCC_APB2RSTR_EXTIRST                  ( RCC_APB2RSTR_EXTIRST_Msk )

#define RCC_APB2RSTR_OPARST_Pos               ( 3U )
#define RCC_APB2RSTR_OPARST_Msk               ( 0x1UL << RCC_APB2RSTR_OPARST_Pos )
#define RCC_APB2RSTR_OPARST                   ( RCC_APB2RSTR_OPARST_Msk )

#define RCC_APB2RSTR_CMPRST_Pos               ( 2U )
#define RCC_APB2RSTR_CMPRST_Msk               ( 0x1UL << RCC_APB2RSTR_CMPRST_Pos )
#define RCC_APB2RSTR_CMPRST                   ( RCC_APB2RSTR_CMPRST_Msk )

#define RCC_APB2RSTR_VREFBUFRST_Pos           ( 1U )
#define RCC_APB2RSTR_VREFBUFRST_Msk           ( 0x1UL << RCC_APB2RSTR_VREFBUFRST_Pos )
#define RCC_APB2RSTR_VREFBUFRST               ( RCC_APB2RSTR_VREFBUFRST_Msk )

#define RCC_APB2RSTR_SYSCFGRST_Pos            ( 0U )
#define RCC_APB2RSTR_SYSCFGRST_Msk            ( 0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos )
#define RCC_APB2RSTR_SYSCFGRST                ( RCC_APB2RSTR_SYSCFGRST_Msk )

/***************  Bits definition for RCC_AHBRSTR register  ****************/

#define RCC_AHBRSTR_EXMCRST_Pos                ( 29U )
#define RCC_AHBRSTR_EXMCRST_Msk                ( 0x1UL << RCC_AHBRSTR_EXMCRST_Pos )
#define RCC_AHBRSTR_EXMCRST                    ( RCC_AHBRSTR_EXMCRST_Msk )

#define RCC_AHBRSTR_UACRST_Pos                ( 27U )
#define RCC_AHBRSTR_UACRST_Msk                ( 0x1UL << RCC_AHBRSTR_UACRST_Pos )
#define RCC_AHBRSTR_UACRST                    ( RCC_AHBRSTR_UACRST_Msk )

#define RCC_AHBRSTR_DAC1RST_Pos               ( 20U )
#define RCC_AHBRSTR_DAC1RST_Msk               ( 0x1UL << RCC_AHBRSTR_DAC1RST_Pos )
#define RCC_AHBRSTR_DAC1RST                   ( RCC_AHBRSTR_DAC1RST_Msk )

#define RCC_AHBRSTR_ADC12RST_Pos              ( 18U )
#define RCC_AHBRSTR_ADC12RST_Msk              ( 0x1UL << RCC_AHBRSTR_ADC12RST_Pos )
#define RCC_AHBRSTR_ADC12RST                  ( RCC_AHBRSTR_ADC12RST_Msk )

#define RCC_AHBRSTR_GPIOFRST_Pos              ( 15U )
#define RCC_AHBRSTR_GPIOFRST_Msk              ( 0x1UL << RCC_AHBRSTR_GPIOFRST_Pos )
#define RCC_AHBRSTR_GPIOFRST                  ( RCC_AHBRSTR_GPIOFRST_Msk )

#define RCC_AHBRSTR_GPIOERST_Pos              ( 14U )
#define RCC_AHBRSTR_GPIOERST_Msk              ( 0x1UL << RCC_AHBRSTR_GPIOERST_Pos )
#define RCC_AHBRSTR_GPIOERST                  ( RCC_AHBRSTR_GPIOERST_Msk )

#define RCC_AHBRSTR_GPIODRST_Pos              ( 13U )
#define RCC_AHBRSTR_GPIODRST_Msk              ( 0x1UL << RCC_AHBRSTR_GPIODRST_Pos )
#define RCC_AHBRSTR_GPIODRST                  ( RCC_AHBRSTR_GPIODRST_Msk )

#define RCC_AHBRSTR_GPIOCRST_Pos              ( 12U )
#define RCC_AHBRSTR_GPIOCRST_Msk              ( 0x1UL << RCC_AHBRSTR_GPIOCRST_Pos )
#define RCC_AHBRSTR_GPIOCRST                  ( RCC_AHBRSTR_GPIOCRST_Msk )

#define RCC_AHBRSTR_GPIOBRST_Pos              ( 11U )
#define RCC_AHBRSTR_GPIOBRST_Msk              ( 0x1UL << RCC_AHBRSTR_GPIOBRST_Pos )
#define RCC_AHBRSTR_GPIOBRST                  ( RCC_AHBRSTR_GPIOBRST_Msk )

#define RCC_AHBRSTR_GPIOARST_Pos              ( 10U )
#define RCC_AHBRSTR_GPIOARST_Msk              ( 0x1UL << RCC_AHBRSTR_GPIOARST_Pos )
#define RCC_AHBRSTR_GPIOARST                  ( RCC_AHBRSTR_GPIOARST_Msk )

#define RCC_AHBRSTR_SPI3RST_Pos               ( 8U )
#define RCC_AHBRSTR_SPI3RST_Msk               ( 0x1UL << RCC_AHBRSTR_SPI3RST_Pos )
#define RCC_AHBRSTR_SPI3RST                   ( RCC_AHBRSTR_SPI3RST_Msk )

#define RCC_AHBRSTR_SPI2RST_Pos               ( 7U )
#define RCC_AHBRSTR_SPI2RST_Msk               ( 0x1UL << RCC_AHBRSTR_SPI2RST_Pos )
#define RCC_AHBRSTR_SPI2RST                   ( RCC_AHBRSTR_SPI2RST_Msk )

#define RCC_AHBRSTR_SPI1RST_Pos               ( 6U )
#define RCC_AHBRSTR_SPI1RST_Msk               ( 0x1UL << RCC_AHBRSTR_SPI1RST_Pos )
#define RCC_AHBRSTR_SPI1RST                   ( RCC_AHBRSTR_SPI1RST_Msk )

#define RCC_AHBRSTR_CRCRST_Pos                ( 5U )
#define RCC_AHBRSTR_CRCRST_Msk                ( 0x1UL << RCC_AHBRSTR_CRCRST_Pos )
#define RCC_AHBRSTR_CRCRST                    ( RCC_AHBRSTR_CRCRST_Msk )

#define RCC_AHBRSTR_USBCRST_Pos               ( 4U )
#define RCC_AHBRSTR_USBCRST_Msk               ( 0x1UL << RCC_AHBRSTR_USBCRST_Pos )
#define RCC_AHBRSTR_USBCRST                   ( RCC_AHBRSTR_USBCRST_Msk )

#define RCC_AHBRSTR_DMA2RST_Pos               ( 1U )
#define RCC_AHBRSTR_DMA2RST_Msk               ( 0x1UL << RCC_AHBRSTR_DMA2RST_Pos )
#define RCC_AHBRSTR_DMA2RST                   ( RCC_AHBRSTR_DMA2RST_Msk )

#define RCC_AHBRSTR_DMA1RST_Pos               ( 0U )
#define RCC_AHBRSTR_DMA1RST_Msk               ( 0x1UL << RCC_AHBRSTR_DMA1RST_Pos )
#define RCC_AHBRSTR_DMA1RST                   ( RCC_AHBRSTR_DMA1RST_Msk )


/***************  Bits definition for RCC_CCR1 register  *********************/

#define RCC_CCR1_SYSCLKSEL_Pos                  ( 0U )
#define RCC_CCR1_SYSCLKSEL_Msk                  ( 0x7UL << RCC_CCR1_SYSCLKSEL_Pos )
#define RCC_CCR1_SYSCLKSEL                      ( RCC_CCR1_SYSCLKSEL_Msk )
#define RCC_CCR1_SYSCLKSEL_0                    ( 0x1UL << RCC_CCR1_SYSCLKSEL_Pos )
#define RCC_CCR1_SYSCLKSEL_1                    ( 0x2UL << RCC_CCR1_SYSCLKSEL_Pos )
#define RCC_CCR1_SYSCLKSEL_2                    ( 0x4UL << RCC_CCR1_SYSCLKSEL_Pos )


/***************  Bits definition for RCC_CCR2 register  *********************/

#define RCC_CCR2_DIVDONE_Pos                    ( 31U )
#define RCC_CCR2_DIVDONE_Msk                    ( 0x1UL << RCC_CCR2_DIVDONE_Pos )
#define RCC_CCR2_DIVDONE                        ( RCC_CCR2_DIVDONE_Msk )

#define RCC_CCR2_LPTLCKSEL_Pos                  ( 20U )
#define RCC_CCR2_LPTLCKSEL_Msk                  ( 0x3UL << RCC_CCR2_LPTLCKSEL_Pos )
#define RCC_CCR2_LPTLCKSEL                      ( RCC_CCR2_LPTLCKSEL_Msk )
#define RCC_CCR2_LPTLCKSEL_0                    ( 0x1UL << RCC_CCR2_LPTLCKSEL_Pos )
#define RCC_CCR2_LPTLCKSEL_1                    ( 0x2UL << RCC_CCR2_LPTLCKSEL_Pos )

#define RCC_CCR2_FLTCLKSEL_Pos                  ( 18U )
#define RCC_CCR2_FLTCLKSEL_Msk                  ( 0x1UL << RCC_CCR2_FLTCLKSEL_Pos )
#define RCC_CCR2_FLTCLKSEL                      ( RCC_CCR2_FLTCLKSEL_Msk )

#define RCC_CCR2_LPUCLKSEL_Pos                  ( 16U )
#define RCC_CCR2_LPUCLKSEL_Msk                  ( 0x3UL << RCC_CCR2_LPUCLKSEL_Pos )
#define RCC_CCR2_LPUCLKSEL                      ( RCC_CCR2_LPUCLKSEL_Msk )
#define RCC_CCR2_LPUCLKSEL_0                    ( 0x1UL << RCC_CCR2_LPUCLKSEL_Pos )
#define RCC_CCR2_LPUCLKSEL_1                    ( 0x2UL << RCC_CCR2_LPUCLKSEL_Pos )

#define RCC_CCR2_LPUARTDIV_Pos                  ( 14U )
#define RCC_CCR2_LPUARTDIV_Msk                  ( 0x3UL << RCC_CCR2_LPUARTDIV_Pos )
#define RCC_CCR2_LPUARTDIV                      ( RCC_CCR2_LPUARTDIV_Msk )
#define RCC_CCR2_LPUARTDIV_0                    ( 0x1UL << RCC_CCR2_LPUARTDIV_Pos )
#define RCC_CCR2_LPUARTDIV_1                    ( 0x2UL << RCC_CCR2_LPUARTDIV_Pos )

#define RCC_CCR2_PCLK2DIV_Pos                   ( 11U )
#define RCC_CCR2_PCLK2DIV_Msk                   ( 0x7UL << RCC_CCR2_PCLK2DIV_Pos )
#define RCC_CCR2_PCLK2DIV                       ( RCC_CCR2_PCLK2DIV_Msk )
#define RCC_CCR2_PCLK2DIV_0                     ( 0x1UL << RCC_CCR2_PCLK2DIV_Pos )
#define RCC_CCR2_PCLK2DIV_1                     ( 0x2UL << RCC_CCR2_PCLK2DIV_Pos )
#define RCC_CCR2_PCLK2DIV_2                     ( 0x4UL << RCC_CCR2_PCLK2DIV_Pos )

#define RCC_CCR2_PCLK1DIV_Pos                   ( 8U )
#define RCC_CCR2_PCLK1DIV_Msk                   ( 0x7UL << RCC_CCR2_PCLK1DIV_Pos )
#define RCC_CCR2_PCLK1DIV                       ( RCC_CCR2_PCLK1DIV_Msk )
#define RCC_CCR2_PCLK1DIV_0                     ( 0x1UL << RCC_CCR2_PCLK1DIV_Pos )
#define RCC_CCR2_PCLK1DIV_1                     ( 0x2UL << RCC_CCR2_PCLK1DIV_Pos )
#define RCC_CCR2_PCLK1DIV_2                     ( 0x4UL << RCC_CCR2_PCLK1DIV_Pos )

#define RCC_CCR2_SYSDIV1_Pos                    ( 4U )
#define RCC_CCR2_SYSDIV1_Msk                    ( 0xFUL << RCC_CCR2_SYSDIV1_Pos )
#define RCC_CCR2_SYSDIV1                        ( RCC_CCR2_SYSDIV1_Msk )
#define RCC_CCR2_SYSDIV1_0                      ( 0x1UL << RCC_CCR2_SYSDIV1_Pos )
#define RCC_CCR2_SYSDIV1_1                      ( 0x2UL << RCC_CCR2_SYSDIV1_Pos )
#define RCC_CCR2_SYSDIV1_2                      ( 0x4UL << RCC_CCR2_SYSDIV1_Pos )
#define RCC_CCR2_SYSDIV1_3                      ( 0x8UL << RCC_CCR2_SYSDIV1_Pos )

#define RCC_CCR2_SYSDIV0_Pos                    ( 0U )
#define RCC_CCR2_SYSDIV0_Msk                    ( 0xFUL << RCC_CCR2_SYSDIV0_Pos )
#define RCC_CCR2_SYSDIV0                        ( RCC_CCR2_SYSDIV0_Msk )
#define RCC_CCR2_SYSDIV0_0                      ( 0x1UL << RCC_CCR2_SYSDIV0_Pos )
#define RCC_CCR2_SYSDIV0_1                      ( 0x2UL << RCC_CCR2_SYSDIV0_Pos )
#define RCC_CCR2_SYSDIV0_2                      ( 0x4UL << RCC_CCR2_SYSDIV0_Pos )
#define RCC_CCR2_SYSDIV0_3                      ( 0x8UL << RCC_CCR2_SYSDIV0_Pos )


/***************  Bits definition for RCC_CIR register  **********************/

#define RCC_CIR_PLLLOCKIC_Pos                   ( 20U )
#define RCC_CIR_PLLLOCKIC_Msk                   ( 0x1UL << RCC_CIR_PLLLOCKIC_Pos )
#define RCC_CIR_PLLLOCKIC                       ( RCC_CIR_PLLLOCKIC_Msk )

#define RCC_CIR_XTHRDYIC_Pos                    ( 19U )
#define RCC_CIR_XTHRDYIC_Msk                    ( 0x1UL << RCC_CIR_XTHRDYIC_Pos )
#define RCC_CIR_XTHRDYIC                        ( RCC_CIR_XTHRDYIC_Msk )

#define RCC_CIR_RC64MRDYIC_Pos                  ( 18U )
#define RCC_CIR_RC64MRDYIC_Msk                  ( 0x1UL << RCC_CIR_RC64MRDYIC_Pos )
#define RCC_CIR_RC64MRDYIC                      ( RCC_CIR_RC64MRDYIC_Msk )

#define RCC_CIR_XTLRDYIC_Pos                    ( 17U )
#define RCC_CIR_XTLRDYIC_Msk                    ( 0x1UL << RCC_CIR_XTLRDYIC_Pos )
#define RCC_CIR_XTLRDYIC                        ( RCC_CIR_XTLRDYIC_Msk )

#define RCC_CIR_RC32KRDYIC_Pos                  ( 16U )
#define RCC_CIR_RC32KRDYIC_Msk                  ( 0x1UL << RCC_CIR_RC32KRDYIC_Pos )
#define RCC_CIR_RC32KRDYIC                      ( RCC_CIR_RC32KRDYIC_Msk )

#define RCC_CIR_PLLLOCKIE_Pos                   ( 12U )
#define RCC_CIR_PLLLOCKIE_Msk                   ( 0x1UL << RCC_CIR_PLLLOCKIE_Pos )
#define RCC_CIR_PLLLOCKIE                       ( RCC_CIR_PLLLOCKIE_Msk )

#define RCC_CIR_XTHRDYIE_Pos                    ( 11U )
#define RCC_CIR_XTHRDYIE_Msk                    ( 0x1UL << RCC_CIR_XTHRDYIE_Pos )
#define RCC_CIR_XTHRDYIE                        ( RCC_CIR_XTHRDYIE_Msk )

#define RCC_CIR_RC64MRDYIE_Pos                  ( 10U )
#define RCC_CIR_RC64MRDYIE_Msk                  ( 0x1UL << RCC_CIR_RC64MRDYIE_Pos )
#define RCC_CIR_RC64MRDYIE                      ( RCC_CIR_RC64MRDYIE_Msk )

#define RCC_CIR_XTLRDYIE_Pos                    ( 9U )
#define RCC_CIR_XTLRDYIE_Msk                    ( 0x1UL << RCC_CIR_XTLRDYIE_Pos )
#define RCC_CIR_XTLRDYIE                        ( RCC_CIR_XTLRDYIE_Msk )

#define RCC_CIR_RC32KRDYIE_Pos                  ( 8U )
#define RCC_CIR_RC32KRDYIE_Msk                  ( 0x1UL << RCC_CIR_RC32KRDYIE_Pos )
#define RCC_CIR_RC32KRDYIE                      ( RCC_CIR_RC32KRDYIE_Msk )

#define RCC_CIR_PLLLOCKIF_Pos                   ( 4U )
#define RCC_CIR_PLLLOCKIF_Msk                   ( 0x1UL << RCC_CIR_PLLLOCKIF_Pos )
#define RCC_CIR_PLLLOCKIF                       ( RCC_CIR_PLLLOCKIF_Msk )

#define RCC_CIR_XTHRDYIF_Pos                    ( 3U )
#define RCC_CIR_XTHRDYIF_Msk                    ( 0x1UL << RCC_CIR_XTHRDYIF_Pos )
#define RCC_CIR_XTHRDYIF                        ( RCC_CIR_XTHRDYIF_Msk )

#define RCC_CIR_RC64MRDYIF_Pos                  ( 2U )
#define RCC_CIR_RC64MRDYIF_Msk                  ( 0x1UL << RCC_CIR_RC64MRDYIF_Pos )
#define RCC_CIR_RC64MRDYIF                      ( RCC_CIR_RC64MRDYIF_Msk )

#define RCC_CIR_XTLRDYIF_Pos                    ( 1U )
#define RCC_CIR_XTLRDYIF_Msk                    ( 0x1UL << RCC_CIR_XTLRDYIF_Pos )
#define RCC_CIR_XTLRDYIF                        ( RCC_CIR_XTLRDYIF_Msk )

#define RCC_CIR_RC32KRDYIF_Pos                  ( 0U )
#define RCC_CIR_RC32KRDYIF_Msk                  ( 0x1UL << RCC_CIR_RC32KRDYIF_Pos )
#define RCC_CIR_RC32KRDYIF                      ( RCC_CIR_RC32KRDYIF_Msk )


/***************  Bits definition for RCC_APB1ENR register  **************/

#define RCC_APB1ENR_LPUART1CKEN_Pos         ( 31U )
#define RCC_APB1ENR_LPUART1CKEN_Msk         ( 0x1UL << RCC_APB1ENR_LPUART1CKEN_Pos )
#define RCC_APB1ENR_LPUART1CKEN             ( RCC_APB1ENR_LPUART1CKEN_Msk )

#define RCC_APB1ENR_LPTIM1CKEN_Pos          ( 30U )
#define RCC_APB1ENR_LPTIM1CKEN_Msk          ( 0x1UL << RCC_APB1ENR_LPTIM1CKEN_Pos )
#define RCC_APB1ENR_LPTIM1CKEN              ( RCC_APB1ENR_LPTIM1CKEN_Msk )

#define RCC_APB1ENR_PMUCKEN_Pos             ( 27U )
#define RCC_APB1ENR_PMUCKEN_Msk             ( 0x1UL << RCC_APB1ENR_PMUCKEN_Pos )
#define RCC_APB1ENR_PMUCKEN                 ( RCC_APB1ENR_PMUCKEN_Msk )

#define RCC_APB1ENR_CAN2CKEN_Pos            ( 25U )
#define RCC_APB1ENR_CAN2CKEN_Msk            ( 0x1UL << RCC_APB1ENR_CAN2CKEN_Pos )
#define RCC_APB1ENR_CAN2CKEN                ( RCC_APB1ENR_CAN2CKEN_Msk )

#define RCC_APB1ENR_CAN1CKEN_Pos            ( 24U )
#define RCC_APB1ENR_CAN1CKEN_Msk            ( 0x1UL << RCC_APB1ENR_CAN1CKEN_Pos )
#define RCC_APB1ENR_CAN1CKEN                ( RCC_APB1ENR_CAN1CKEN_Msk )

#define RCC_APB1ENR_I2C2CKEN_Pos            ( 22U )
#define RCC_APB1ENR_I2C2CKEN_Msk            ( 0x1UL << RCC_APB1ENR_I2C2CKEN_Pos )
#define RCC_APB1ENR_I2C2CKEN                ( RCC_APB1ENR_I2C2CKEN_Msk )

#define RCC_APB1ENR_I2C1CKEN_Pos            ( 21U )
#define RCC_APB1ENR_I2C1CKEN_Msk            ( 0x1UL << RCC_APB1ENR_I2C1CKEN_Pos )
#define RCC_APB1ENR_I2C1CKEN                ( RCC_APB1ENR_I2C1CKEN_Msk )

#define RCC_APB1ENR_UART4CKEN_Pos           ( 19U )
#define RCC_APB1ENR_UART4CKEN_Msk           ( 0x1UL << RCC_APB1ENR_UART4CKEN_Pos )
#define RCC_APB1ENR_UART4CKEN               ( RCC_APB1ENR_UART4CKEN_Msk )

#define RCC_APB1ENR_UART3CKEN_Pos           ( 18U )
#define RCC_APB1ENR_UART3CKEN_Msk           ( 0x1UL << RCC_APB1ENR_UART3CKEN_Pos )
#define RCC_APB1ENR_UART3CKEN               ( RCC_APB1ENR_UART3CKEN_Msk )

#define RCC_APB1ENR_UART2CKEN_Pos           ( 17U )
#define RCC_APB1ENR_UART2CKEN_Msk           ( 0x1UL << RCC_APB1ENR_UART2CKEN_Pos )
#define RCC_APB1ENR_UART2CKEN               ( RCC_APB1ENR_UART2CKEN_Msk )

#define RCC_APB1ENR_I2S2CKEN_Pos            ( 15U )
#define RCC_APB1ENR_I2S2CKEN_Msk            ( 0x1UL << RCC_APB1ENR_I2S2CKEN_Pos )
#define RCC_APB1ENR_I2S2CKEN                ( RCC_APB1ENR_I2S2CKEN_Msk )

#define RCC_APB1ENR_I2S1CKEN_Pos            ( 14U )
#define RCC_APB1ENR_I2S1CKEN_Msk            ( 0x1UL << RCC_APB1ENR_I2S1CKEN_Pos )
#define RCC_APB1ENR_I2S1CKEN                ( RCC_APB1ENR_I2S1CKEN_Msk )

#define RCC_APB1ENR_WDTCKEN_Pos             ( 11U )
#define RCC_APB1ENR_WDTCKEN_Msk             ( 0x1UL << RCC_APB1ENR_WDTCKEN_Pos )
#define RCC_APB1ENR_WDTCKEN                 ( RCC_APB1ENR_WDTCKEN_Msk )

#define RCC_APB1ENR_RTCCKEN_Pos             ( 10U )
#define RCC_APB1ENR_RTCCKEN_Msk             ( 0x1UL << RCC_APB1ENR_RTCCKEN_Pos )
#define RCC_APB1ENR_RTCCKEN                 ( RCC_APB1ENR_RTCCKEN_Msk )

#define RCC_APB1ENR_TIM7CKEN_Pos            ( 5U )
#define RCC_APB1ENR_TIM7CKEN_Msk            ( 0x1UL << RCC_APB1ENR_TIM7CKEN_Pos )
#define RCC_APB1ENR_TIM7CKEN                ( RCC_APB1ENR_TIM7CKEN_Msk )

#define RCC_APB1ENR_TIM6CKEN_Pos            ( 4U )
#define RCC_APB1ENR_TIM6CKEN_Msk            ( 0x1UL << RCC_APB1ENR_TIM6CKEN_Pos )
#define RCC_APB1ENR_TIM6CKEN                ( RCC_APB1ENR_TIM6CKEN_Msk )

#define RCC_APB1ENR_TIM4CKEN_Pos            ( 2U )
#define RCC_APB1ENR_TIM4CKEN_Msk            ( 0x1UL << RCC_APB1ENR_TIM4CKEN_Pos )
#define RCC_APB1ENR_TIM4CKEN                ( RCC_APB1ENR_TIM4CKEN_Msk )

#define RCC_APB1ENR_TIM3CKEN_Pos            ( 1U )
#define RCC_APB1ENR_TIM3CKEN_Msk            ( 0x1UL << RCC_APB1ENR_TIM3CKEN_Pos )
#define RCC_APB1ENR_TIM3CKEN                ( RCC_APB1ENR_TIM3CKEN_Msk )

#define RCC_APB1ENR_TIM2CKEN_Pos            ( 0U )
#define RCC_APB1ENR_TIM2CKEN_Msk            ( 0x1UL << RCC_APB1ENR_TIM2CKEN_Pos )
#define RCC_APB1ENR_TIM2CKEN                ( RCC_APB1ENR_TIM2CKEN_Msk )


/***************  Bits definition for RCC_APB2ENR register  **************/

#define RCC_APB2ENR_TIM17CKEN_Pos           ( 13U )
#define RCC_APB2ENR_TIM17CKEN_Msk           ( 0x1UL << RCC_APB2ENR_TIM17CKEN_Pos )
#define RCC_APB2ENR_TIM17CKEN               ( RCC_APB2ENR_TIM17CKEN_Msk )

#define RCC_APB2ENR_TIM16CKEN_Pos           ( 12U )
#define RCC_APB2ENR_TIM16CKEN_Msk           ( 0x1UL << RCC_APB2ENR_TIM16CKEN_Pos )
#define RCC_APB2ENR_TIM16CKEN               ( RCC_APB2ENR_TIM16CKEN_Msk )

#define RCC_APB2ENR_TIM15CKEN_Pos           ( 11U )
#define RCC_APB2ENR_TIM15CKEN_Msk           ( 0x1UL << RCC_APB2ENR_TIM15CKEN_Pos )
#define RCC_APB2ENR_TIM15CKEN               ( RCC_APB2ENR_TIM15CKEN_Msk )

#define RCC_APB2ENR_UART1CKEN_Pos           ( 9U )
#define RCC_APB2ENR_UART1CKEN_Msk           ( 0x1UL << RCC_APB2ENR_UART1CKEN_Pos )
#define RCC_APB2ENR_UART1CKEN               ( RCC_APB2ENR_UART1CKEN_Msk )

#define RCC_APB2ENR_TIM8CKEN_Pos            ( 8U )
#define RCC_APB2ENR_TIM8CKEN_Msk            ( 0x1UL << RCC_APB2ENR_TIM8CKEN_Pos )
#define RCC_APB2ENR_TIM8CKEN                ( RCC_APB2ENR_TIM8CKEN_Msk )

#define RCC_APB2ENR_TIM1CKEN_Pos            ( 6U )
#define RCC_APB2ENR_TIM1CKEN_Msk            ( 0x1UL << RCC_APB2ENR_TIM1CKEN_Pos )
#define RCC_APB2ENR_TIM1CKEN                ( RCC_APB2ENR_TIM1CKEN_Msk )

#define RCC_APB2ENR_EXTICKEN_Pos            ( 4U )
#define RCC_APB2ENR_EXTICKEN_Msk            ( 0x1UL << RCC_APB2ENR_EXTICKEN_Pos )
#define RCC_APB2ENR_EXTICKEN                ( RCC_APB2ENR_EXTICKEN_Msk )

#define RCC_APB2ENR_OPACKEN_Pos             ( 3U )
#define RCC_APB2ENR_OPACKEN_Msk             ( 0x1UL << RCC_APB2ENR_OPACKEN_Pos )
#define RCC_APB2ENR_OPACKEN                 ( RCC_APB2ENR_OPACKEN_Msk )

#define RCC_APB2ENR_CMPCKEN_Pos             ( 2U )
#define RCC_APB2ENR_CMPCKEN_Msk             ( 0x1UL << RCC_APB2ENR_CMPCKEN_Pos )
#define RCC_APB2ENR_CMPCKEN                 ( RCC_APB2ENR_CMPCKEN_Msk )

#define RCC_APB2ENR_VREFBUFCKEN_Pos         ( 1U )
#define RCC_APB2ENR_VREFBUFCKEN_Msk         ( 0x1UL << RCC_APB2ENR_VREFBUFCKEN_Pos )
#define RCC_APB2ENR_VREFBUFCKEN             ( RCC_APB2ENR_VREFBUFCKEN_Msk )

#define RCC_APB2ENR_SYSCFGCKEN_Pos          ( 0U )
#define RCC_APB2ENR_SYSCFGCKEN_Msk          ( 0x1UL << RCC_APB2ENR_SYSCFGCKEN_Pos )
#define RCC_APB2ENR_SYSCFGCKEN              ( RCC_APB2ENR_SYSCFGCKEN_Msk )


/***************  Bits definition for RCC_AHBENR register  ***************/

#define RCC_AHBENR_EXMCCKEN_Pos              ( 29U )
#define RCC_AHBENR_EXMCCKEN_Msk              ( 0x1UL << RCC_AHBENR_EXMCCKEN_Pos )
#define RCC_AHBENR_EXMCCKEN                  ( RCC_AHBENR_EXMCCKEN_Msk )

#define RCC_AHBENR_ROMCKEN_Pos              ( 28U )
#define RCC_AHBENR_ROMCKEN_Msk              ( 0x1UL << RCC_AHBENR_ROMCKEN_Pos )
#define RCC_AHBENR_ROMCKEN                  ( RCC_AHBENR_ROMCKEN_Msk )

#define RCC_AHBENR_FAUCKEN_Pos              ( 27U )
#define RCC_AHBENR_FAUCKEN_Msk              ( 0x1UL << RCC_AHBENR_FAUCKEN_Pos )
#define RCC_AHBENR_FAUCKEN                  ( RCC_AHBENR_FAUCKEN_Msk )

#define RCC_AHBENR_HRNGCKEN_Pos             ( 26U )
#define RCC_AHBENR_HRNGCKEN_Msk             ( 0x1UL << RCC_AHBENR_HRNGCKEN_Pos )
#define RCC_AHBENR_HRNGCKEN                 ( RCC_AHBENR_HRNGCKEN_Msk )

#define RCC_AHBENR_AESCKEN_Pos              ( 25U )
#define RCC_AHBENR_AESCKEN_Msk              ( 0x1UL << RCC_AHBENR_AESCKEN_Pos )
#define RCC_AHBENR_AESCKEN                  ( RCC_AHBENR_AESCKEN_Msk )

#define RCC_AHBENR_DAC1CKEN_Pos             ( 20U )
#define RCC_AHBENR_DAC1CKEN_Msk             ( 0x1UL << RCC_AHBENR_DAC1CKEN_Pos )
#define RCC_AHBENR_DAC1CKEN                 ( RCC_AHBENR_DAC1CKEN_Msk )

#define RCC_AHBENR_ADC12CKEN_Pos            ( 18U )
#define RCC_AHBENR_ADC12CKEN_Msk            ( 0x1UL << RCC_AHBENR_ADC12CKEN_Pos )
#define RCC_AHBENR_ADC12CKEN                ( RCC_AHBENR_ADC12CKEN_Msk )

#define RCC_AHBENR_GPIOFCKEN_Pos            ( 15U )
#define RCC_AHBENR_GPIOFCKEN_Msk            ( 0x1UL << RCC_AHBENR_GPIOFCKEN_Pos )
#define RCC_AHBENR_GPIOFCKEN                ( RCC_AHBENR_GPIOFCKEN_Msk )

#define RCC_AHBENR_GPIOECKEN_Pos            ( 14U )
#define RCC_AHBENR_GPIOECKEN_Msk            ( 0x1UL << RCC_AHBENR_GPIOECKEN_Pos )
#define RCC_AHBENR_GPIOECKEN                ( RCC_AHBENR_GPIOECKEN_Msk )

#define RCC_AHBENR_GPIODCKEN_Pos            ( 13U )
#define RCC_AHBENR_GPIODCKEN_Msk            ( 0x1UL << RCC_AHBENR_GPIODCKEN_Pos )
#define RCC_AHBENR_GPIODCKEN                ( RCC_AHBENR_GPIODCKEN_Msk )

#define RCC_AHBENR_GPIOCCKEN_Pos            ( 12U )
#define RCC_AHBENR_GPIOCCKEN_Msk            ( 0x1UL << RCC_AHBENR_GPIOCCKEN_Pos )
#define RCC_AHBENR_GPIOCCKEN                ( RCC_AHBENR_GPIOCCKEN_Msk )

#define RCC_AHBENR_GPIOBCKEN_Pos            ( 11U )
#define RCC_AHBENR_GPIOBCKEN_Msk            ( 0x1UL << RCC_AHBENR_GPIOBCKEN_Pos )
#define RCC_AHBENR_GPIOBCKEN                ( RCC_AHBENR_GPIOBCKEN_Msk )

#define RCC_AHBENR_GPIOACKEN_Pos            ( 10U )
#define RCC_AHBENR_GPIOACKEN_Msk            ( 0x1UL << RCC_AHBENR_GPIOACKEN_Pos )
#define RCC_AHBENR_GPIOACKEN                ( RCC_AHBENR_GPIOACKEN_Msk )

#define RCC_AHBENR_SPI3CKEN_Pos             ( 8U )
#define RCC_AHBENR_SPI3CKEN_Msk             ( 0x1UL << RCC_AHBENR_SPI3CKEN_Pos )
#define RCC_AHBENR_SPI3CKEN                 ( RCC_AHBENR_SPI3CKEN_Msk )

#define RCC_AHBENR_SPI2CKEN_Pos             ( 7U )
#define RCC_AHBENR_SPI2CKEN_Msk             ( 0x1UL << RCC_AHBENR_SPI2CKEN_Pos )
#define RCC_AHBENR_SPI2CKEN                 ( RCC_AHBENR_SPI2CKEN_Msk )

#define RCC_AHBENR_SPI1CKEN_Pos             ( 6U )
#define RCC_AHBENR_SPI1CKEN_Msk             ( 0x1UL << RCC_AHBENR_SPI1CKEN_Pos )
#define RCC_AHBENR_SPI1CKEN                 ( RCC_AHBENR_SPI1CKEN_Msk )

#define RCC_AHBENR_CRCCKEN_Pos              ( 5U )
#define RCC_AHBENR_CRCCKEN_Msk              ( 0x1UL << RCC_AHBENR_CRCCKEN_Pos )
#define RCC_AHBENR_CRCCKEN                  ( RCC_AHBENR_CRCCKEN_Msk )

#define RCC_AHBENR_USBCCKEN_Pos             ( 4U )
#define RCC_AHBENR_USBCCKEN_Msk             ( 0x1UL << RCC_AHBENR_USBCCKEN_Pos )
#define RCC_AHBENR_USBCCKEN                 ( RCC_AHBENR_USBCCKEN_Msk )

#define RCC_AHBENR_EFCKEN_Pos               ( 3U )
#define RCC_AHBENR_EFCKEN_Msk               ( 0x1UL << RCC_AHBENR_EFCKEN_Pos )
#define RCC_AHBENR_EFCKEN                   ( RCC_AHBENR_EFCKEN_Msk )

#define RCC_AHBENR_SRAMCKEN_Pos             ( 2U )
#define RCC_AHBENR_SRAMCKEN_Msk             ( 0x1UL << RCC_AHBENR_SRAMCKEN_Pos )
#define RCC_AHBENR_SRAMCKEN                 ( RCC_AHBENR_SRAMCKEN_Msk )

#define RCC_AHBENR_DMA2CKEN_Pos             ( 1U )
#define RCC_AHBENR_DMA2CKEN_Msk             ( 0x1UL << RCC_AHBENR_DMA2CKEN_Pos )
#define RCC_AHBENR_DMA2CKEN                 ( RCC_AHBENR_DMA2CKEN_Msk )

#define RCC_AHBENR_DMA1CKEN_Pos             ( 0U )
#define RCC_AHBENR_DMA1CKEN_Msk             ( 0x1UL << RCC_AHBENR_DMA1CKEN_Pos )
#define RCC_AHBENR_DMA1CKEN                 ( RCC_AHBENR_DMA1CKEN_Msk )

/***************  Bits definition for RCC_RC64MCR register  ******************/

#define RCC_RC64MCR_RC64MTRIM_Pos               ( 8U )
#define RCC_RC64MCR_RC64MTRIM_Msk               ( 0x1FFUL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM                   ( RCC_RC64MCR_RC64MTRIM_Msk )
#define RCC_RC64MCR_RC64MTRIM_0                 ( 0x1UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_1                 ( 0x2UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_2                 ( 0x4UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_3                 ( 0x8UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_4                 ( 0x10UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_5                 ( 0x20UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_6                 ( 0x40UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_7                 ( 0x80UL << RCC_RC64MCR_RC64MTRIM_Pos )
#define RCC_RC64MCR_RC64MTRIM_8                 ( 0x100UL << RCC_RC64MCR_RC64MTRIM_Pos )

#define RCC_RC64MCR_RC64MRDY_Pos                ( 4U )
#define RCC_RC64MCR_RC64MRDY_Msk                ( 0x1UL << RCC_RC64MCR_RC64MRDY_Pos )
#define RCC_RC64MCR_RC64MRDY                    ( RCC_RC64MCR_RC64MRDY_Msk )

#define RCC_RC64MCR_RC64MDIV_Pos                ( 3U )
#define RCC_RC64MCR_RC64MDIV_Msk                ( 0x1UL << RCC_RC64MCR_RC64MDIV_Pos )
#define RCC_RC64MCR_RC64MDIV                    ( RCC_RC64MCR_RC64MDIV_Msk )

#define RCC_RC64MCR_RC64MEN_Pos                 ( 0U )
#define RCC_RC64MCR_RC64MEN_Msk                 ( 0x1UL << RCC_RC64MCR_RC64MEN_Pos )
#define RCC_RC64MCR_RC64MEN                     ( RCC_RC64MCR_RC64MEN_Msk )


/***************  Bits definition for RCC_XTHCR register  ********************/

#define RCC_XTHCR_XTHRDY_Pos                    ( 4U )
#define RCC_XTHCR_XTHRDY_Msk                    ( 0x1UL << RCC_XTHCR_XTHRDY_Pos )
#define RCC_XTHCR_XTHRDY                        ( RCC_XTHCR_XTHRDY_Msk )

#define RCC_XTHCR_XTHRDYTIME_Pos                ( 2U )
#define RCC_XTHCR_XTHRDYTIME_Msk                ( 0x3UL << RCC_XTHCR_XTHRDYTIME_Pos )
#define RCC_XTHCR_XTHRDYTIME                    ( RCC_XTHCR_XTHRDYTIME_Msk )
#define RCC_XTHCR_XTHRDYTIME_0                  ( 0x1UL << RCC_XTHCR_XTHRDYTIME_Pos )
#define RCC_XTHCR_XTHRDYTIME_1                  ( 0x2UL << RCC_XTHCR_XTHRDYTIME_Pos )

#define RCC_XTHCR_XTHBYP_Pos                    ( 1U )
#define RCC_XTHCR_XTHBYP_Msk                    ( 0x1UL << RCC_XTHCR_XTHBYP_Pos )
#define RCC_XTHCR_XTHBYP                        ( RCC_XTHCR_XTHBYP_Msk )

#define RCC_XTHCR_XTHEN_Pos                     ( 0U )
#define RCC_XTHCR_XTHEN_Msk                     ( 0x1UL << RCC_XTHCR_XTHEN_Pos )
#define RCC_XTHCR_XTHEN                         ( RCC_XTHCR_XTHEN_Msk )


/***************  Bits definition for RCC_PLLCR register  ********************/

#define RCC_PLLCR_PLLLOCKSEL_Pos                ( 31U )
#define RCC_PLLCR_PLLLOCKSEL_Msk                ( 0x1UL << RCC_PLLCR_PLLLOCKSEL_Pos )
#define RCC_PLLCR_PLLLOCKSEL                    ( RCC_PLLCR_PLLLOCKSEL_Msk )

#define RCC_PLLCR_PLLFREERUN_Pos                ( 30U )
#define RCC_PLLCR_PLLFREERUN_Msk                ( 0x1UL << RCC_PLLCR_PLLFREERUN_Pos )
#define RCC_PLLCR_PLLFREERUN                    ( RCC_PLLCR_PLLFREERUN_Msk )

#define RCC_PLLCR_PLLLOCK_Pos                   ( 29U )
#define RCC_PLLCR_PLLLOCK_Msk                   ( 0x1UL << RCC_PLLCR_PLLLOCK_Pos )
#define RCC_PLLCR_PLLLOCK                       ( RCC_PLLCR_PLLLOCK_Msk )

#define RCC_PLLCR_PLLRUNDLY_Pos                 ( 23U )
#define RCC_PLLCR_PLLRUNDLY_Msk                 ( 0x3FUL << RCC_PLLCR_PLLRUNDLY_Pos )
#define RCC_PLLCR_PLLRUNDLY                     ( RCC_PLLCR_PLLRUNDLY_Msk )
#define RCC_PLLCR_PLLRUNDLY_0                   ( 0x1UL << RCC_PLLCR_PLLRUNDLY_Pos )
#define RCC_PLLCR_PLLRUNDLY_1                   ( 0x2UL << RCC_PLLCR_PLLRUNDLY_Pos )
#define RCC_PLLCR_PLLRUNDLY_2                   ( 0x4UL << RCC_PLLCR_PLLRUNDLY_Pos )
#define RCC_PLLCR_PLLRUNDLY_3                   ( 0x8UL << RCC_PLLCR_PLLRUNDLY_Pos )
#define RCC_PLLCR_PLLRUNDLY_4                   ( 0x10UL << RCC_PLLCR_PLLRUNDLY_Pos )
#define RCC_PLLCR_PLLRUNDLY_5                   ( 0x20UL << RCC_PLLCR_PLLRUNDLY_Pos )

#define RCC_PLLCR_PLLUPDATEEN_Pos               ( 22U )
#define RCC_PLLCR_PLLUPDATEEN_Msk               ( 0x1UL << RCC_PLLCR_PLLUPDATEEN_Pos )
#define RCC_PLLCR_PLLUPDATEEN                   ( RCC_PLLCR_PLLUPDATEEN_Msk )

#define RCC_PLLCR_PLLSLEEP_Pos                  ( 21U )
#define RCC_PLLCR_PLLSLEEP_Msk                  ( 0x1UL << RCC_PLLCR_PLLSLEEP_Pos )
#define RCC_PLLCR_PLLSLEEP                      ( RCC_PLLCR_PLLSLEEP_Msk )

#define RCC_PLLCR_PLLM_Pos                      ( 16U )
#define RCC_PLLCR_PLLM_Msk                      ( 0x3UL << RCC_PLLCR_PLLM_Pos )
#define RCC_PLLCR_PLLM                          ( RCC_PLLCR_PLLM_Msk )
#define RCC_PLLCR_PLLM_0                        ( 0x1UL << RCC_PLLCR_PLLM_Pos )
#define RCC_PLLCR_PLLM_1                        ( 0x2UL << RCC_PLLCR_PLLM_Pos )

#define RCC_PLLCR_PLLN_Pos                      ( 12U )
#define RCC_PLLCR_PLLN_Msk                      ( 0x7UL << RCC_PLLCR_PLLN_Pos )
#define RCC_PLLCR_PLLN                          ( RCC_PLLCR_PLLN_Msk )
#define RCC_PLLCR_PLLN_0                        ( 0x1UL << RCC_PLLCR_PLLN_Pos )
#define RCC_PLLCR_PLLN_1                        ( 0x2UL << RCC_PLLCR_PLLN_Pos )
#define RCC_PLLCR_PLLN_2                        ( 0x4UL << RCC_PLLCR_PLLN_Pos )

#define RCC_PLLCR_PLLF_Pos                      ( 3U )
#define RCC_PLLCR_PLLF_Msk                      ( 0x1FUL << RCC_PLLCR_PLLF_Pos )
#define RCC_PLLCR_PLLF                          ( RCC_PLLCR_PLLF_Msk )
#define RCC_PLLCR_PLLF_0                        ( 0x1UL << RCC_PLLCR_PLLF_Pos )
#define RCC_PLLCR_PLLF_1                        ( 0x2UL << RCC_PLLCR_PLLF_Pos )
#define RCC_PLLCR_PLLF_2                        ( 0x4UL << RCC_PLLCR_PLLF_Pos )
#define RCC_PLLCR_PLLF_3                        ( 0x8UL << RCC_PLLCR_PLLF_Pos )
#define RCC_PLLCR_PLLF_4                        ( 0x10UL << RCC_PLLCR_PLLF_Pos )

#define RCC_PLLCR_PLLSRCSEL_Pos                 ( 1U )
#define RCC_PLLCR_PLLSRCSEL_Msk                 ( 0x3UL << RCC_PLLCR_PLLSRCSEL_Pos )
#define RCC_PLLCR_PLLSRCSEL                     ( RCC_PLLCR_PLLSRCSEL_Msk )
#define RCC_PLLCR_PLLSRCSEL_0                   ( 0x1UL << RCC_PLLCR_PLLSRCSEL_Pos )
#define RCC_PLLCR_PLLSRCSEL_1                   ( 0x2UL << RCC_PLLCR_PLLSRCSEL_Pos )

#define RCC_PLLCR_PLLEN_Pos                     ( 0U )
#define RCC_PLLCR_PLLEN_Msk                     ( 0x1UL << RCC_PLLCR_PLLEN_Pos )
#define RCC_PLLCR_PLLEN                         ( RCC_PLLCR_PLLEN_Msk )


/***************  Bits definition for RCC_CLKOCR register  *******************/

#define RCC_CLKOCR_BUZZER2EN_Pos                ( 31U )
#define RCC_CLKOCR_BUZZER2EN_Msk                ( 0x1UL << RCC_CLKOCR_BUZZER2EN_Pos )
#define RCC_CLKOCR_BUZZER2EN                    ( RCC_CLKOCR_BUZZER2EN_Msk )

#define RCC_CLKOCR_BUZZER2POL_Pos               ( 30U )
#define RCC_CLKOCR_BUZZER2POL_Msk               ( 0x1UL << RCC_CLKOCR_BUZZER2POL_Pos )
#define RCC_CLKOCR_BUZZER2POL                   ( RCC_CLKOCR_BUZZER2POL_Msk )

#define RCC_CLKOCR_BUZZER2DIV_Pos               ( 24U )
#define RCC_CLKOCR_BUZZER2DIV_Msk               ( 0x3FUL << RCC_CLKOCR_BUZZER2DIV_Pos )
#define RCC_CLKOCR_BUZZER2DIV                   ( RCC_CLKOCR_BUZZER2DIV_Msk )
#define RCC_CLKOCR_BUZZER2DIV_0                 ( 0x1UL << RCC_CLKOCR_BUZZER2DIV_Pos )
#define RCC_CLKOCR_BUZZER2DIV_1                 ( 0x2UL << RCC_CLKOCR_BUZZER2DIV_Pos )
#define RCC_CLKOCR_BUZZER2DIV_2                 ( 0x4UL << RCC_CLKOCR_BUZZER2DIV_Pos )
#define RCC_CLKOCR_BUZZER2DIV_3                 ( 0x8UL << RCC_CLKOCR_BUZZER2DIV_Pos )
#define RCC_CLKOCR_BUZZER2DIV_4                 ( 0x10UL << RCC_CLKOCR_BUZZER2DIV_Pos )
#define RCC_CLKOCR_BUZZER2DIV_5                 ( 0x20UL << RCC_CLKOCR_BUZZER2DIV_Pos )

#define RCC_CLKOCR_BUZZER1EN_Pos                 ( 23U )
#define RCC_CLKOCR_BUZZER1EN_Msk                 ( 0x1UL << RCC_CLKOCR_BUZZER1EN_Pos )
#define RCC_CLKOCR_BUZZER1EN                     ( RCC_CLKOCR_BUZZER1EN_Msk )

#define RCC_CLKOCR_BUZZER1POL_Pos                ( 22U )
#define RCC_CLKOCR_BUZZER1POL_Msk                ( 0x1UL << RCC_CLKOCR_BUZZER1POL_Pos )
#define RCC_CLKOCR_BUZZER1POL                    ( RCC_CLKOCR_BUZZER1POL_Msk )

#define RCC_CLKOCR_BUZZER1DIV_Pos                ( 5U )
#define RCC_CLKOCR_BUZZER1DIV_Msk                ( 0xFFFFUL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV                    ( RCC_CLKOCR_BUZZER1DIV_Msk )
#define RCC_CLKOCR_BUZZER1DIV_0                  ( 0x1UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_1                  ( 0x2UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_2                  ( 0x4UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_3                  ( 0x8UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_4                  ( 0x10UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_5                  ( 0x20UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_6                  ( 0x40UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_7                  ( 0x80UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_8                  ( 0x100UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_9                  ( 0x200UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_10                 ( 0x400UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_11                 ( 0x800UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_12                 ( 0x1000UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_13                 ( 0x2000UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_14                 ( 0x4000UL << RCC_CLKOCR_BUZZER1DIV_Pos )
#define RCC_CLKOCR_BUZZER1DIV_15                 ( 0x8000UL << RCC_CLKOCR_BUZZER1DIV_Pos )

#define RCC_CLKOCR_MCOSEL_Pos                   ( 4U )
#define RCC_CLKOCR_MCOSEL_Msk                   ( 0x1UL << RCC_CLKOCR_MCOSEL_Pos )
#define RCC_CLKOCR_MCOSEL                       ( RCC_CLKOCR_MCOSEL_Msk )

#define RCC_CLKOCR_CLKTESTSEL_Pos               ( 0U )
#define RCC_CLKOCR_CLKTESTSEL_Msk               ( 0xFUL << RCC_CLKOCR_CLKTESTSEL_Pos )
#define RCC_CLKOCR_CLKTESTSEL                   ( RCC_CLKOCR_CLKTESTSEL_Msk )
#define RCC_CLKOCR_CLKTESTSEL_0                 ( 0x1UL << RCC_CLKOCR_CLKTESTSEL_Pos )
#define RCC_CLKOCR_CLKTESTSEL_1                 ( 0x2UL << RCC_CLKOCR_CLKTESTSEL_Pos )
#define RCC_CLKOCR_CLKTESTSEL_2                 ( 0x4UL << RCC_CLKOCR_CLKTESTSEL_Pos )
#define RCC_CLKOCR_CLKTESTSEL_3                 ( 0x8UL << RCC_CLKOCR_CLKTESTSEL_Pos )


/***************  Bits definition for RCC_STDBYCTRL register  ****************/

#define RCC_STDBYCTRL_STDBYRST_Pos              ( 23U )
#define RCC_STDBYCTRL_STDBYRST_Msk              ( 0x1UL << RCC_STDBYCTRL_STDBYRST_Pos )
#define RCC_STDBYCTRL_STDBYRST                  ( RCC_STDBYCTRL_STDBYRST_Msk )

#define RCC_STDBYCTRL_RTCEN_Pos                 ( 22U )
#define RCC_STDBYCTRL_RTCEN_Msk                 ( 0x1UL << RCC_STDBYCTRL_RTCEN_Pos )
#define RCC_STDBYCTRL_RTCEN                     ( RCC_STDBYCTRL_RTCEN_Msk )

#define RCC_STDBYCTRL_RTCSEL_Pos                ( 20U )
#define RCC_STDBYCTRL_RTCSEL_Msk                ( 0x3UL << RCC_STDBYCTRL_RTCSEL_Pos )
#define RCC_STDBYCTRL_RTCSEL                    ( RCC_STDBYCTRL_RTCSEL_Msk )
#define RCC_STDBYCTRL_RTCSEL_0                  ( 0x1UL << RCC_STDBYCTRL_RTCSEL_Pos )
#define RCC_STDBYCTRL_RTCSEL_1                  ( 0x2UL << RCC_STDBYCTRL_RTCSEL_Pos )

#define RCC_STDBYCTRL_RC32KTRIM_Pos             ( 10U )
#define RCC_STDBYCTRL_RC32KTRIM_Msk             ( 0x3FUL << RCC_STDBYCTRL_RC32KTRIM_Pos )
#define RCC_STDBYCTRL_RC32KTRIM                 ( RCC_STDBYCTRL_RC32KTRIM_Msk )
#define RCC_STDBYCTRL_RC32KTRIM_0               ( 0x1UL << RCC_STDBYCTRL_RC32KTRIM_Pos )
#define RCC_STDBYCTRL_RC32KTRIM_1               ( 0x2UL << RCC_STDBYCTRL_RC32KTRIM_Pos )
#define RCC_STDBYCTRL_RC32KTRIM_2               ( 0x4UL << RCC_STDBYCTRL_RC32KTRIM_Pos )
#define RCC_STDBYCTRL_RC32KTRIM_3               ( 0x8UL << RCC_STDBYCTRL_RC32KTRIM_Pos )
#define RCC_STDBYCTRL_RC32KTRIM_4               ( 0x10UL << RCC_STDBYCTRL_RC32KTRIM_Pos )
#define RCC_STDBYCTRL_RC32KTRIM_5               ( 0x20UL << RCC_STDBYCTRL_RC32KTRIM_Pos )

#define RCC_STDBYCTRL_RC32KRDY_Pos              ( 9U )
#define RCC_STDBYCTRL_RC32KRDY_Msk              ( 0x1UL << RCC_STDBYCTRL_RC32KRDY_Pos )
#define RCC_STDBYCTRL_RC32KRDY                  ( RCC_STDBYCTRL_RC32KRDY_Msk )

#define RCC_STDBYCTRL_RC32EN_Pos                ( 8U )
#define RCC_STDBYCTRL_RC32EN_Msk                ( 0x1UL << RCC_STDBYCTRL_RC32EN_Pos )
#define RCC_STDBYCTRL_RC32EN                    ( RCC_STDBYCTRL_RC32EN_Msk )

#define RCC_STDBYCTRL_XTLDRV_Pos                ( 3U )
#define RCC_STDBYCTRL_XTLDRV_Msk                ( 0x7UL << RCC_STDBYCTRL_XTLDRV_Pos )
#define RCC_STDBYCTRL_XTLDRV                    ( RCC_STDBYCTRL_XTLDRV_Msk )
#define RCC_STDBYCTRL_XTLDRV_0                  ( 0x1UL << RCC_STDBYCTRL_XTLDRV_Pos )
#define RCC_STDBYCTRL_XTLDRV_1                  ( 0x2UL << RCC_STDBYCTRL_XTLDRV_Pos )
#define RCC_STDBYCTRL_XTLDRV_2                  ( 0x4UL << RCC_STDBYCTRL_XTLDRV_Pos )

#define RCC_STDBYCTRL_XTLBYP_Pos                ( 2U )
#define RCC_STDBYCTRL_XTLBYP_Msk                ( 0x1UL << RCC_STDBYCTRL_XTLBYP_Pos )
#define RCC_STDBYCTRL_XTLBYP                    ( RCC_STDBYCTRL_XTLBYP_Msk )

#define RCC_STDBYCTRL_XTLRDY_Pos                ( 1U )
#define RCC_STDBYCTRL_XTLRDY_Msk                ( 0x1UL << RCC_STDBYCTRL_XTLRDY_Pos )
#define RCC_STDBYCTRL_XTLRDY                    ( RCC_STDBYCTRL_XTLRDY_Msk )

#define RCC_STDBYCTRL_XTLEN_Pos                 ( 0U )
#define RCC_STDBYCTRL_XTLEN_Msk                 ( 0x1UL << RCC_STDBYCTRL_XTLEN_Pos )
#define RCC_STDBYCTRL_XTLEN                     ( RCC_STDBYCTRL_XTLEN_Msk )

/***************  Bits definition for GPIO_MD register  **********************/

#define GPIO_MD_MD15_Pos                        ( 30U )
#define GPIO_MD_MD15_Msk                        ( 0x3UL << GPIO_MD_MD15_Pos )
#define GPIO_MD_MD15                            ( GPIO_MD_MD15_Msk )
#define GPIO_MD_MD15_0                          ( 0x1UL << GPIO_MD_MD15_Pos )
#define GPIO_MD_MD15_1                          ( 0x2UL << GPIO_MD_MD15_Pos )

#define GPIO_MD_MD14_Pos                        ( 28U )
#define GPIO_MD_MD14_Msk                        ( 0x3UL << GPIO_MD_MD14_Pos )
#define GPIO_MD_MD14                            ( GPIO_MD_MD14_Msk )
#define GPIO_MD_MD14_0                          ( 0x1UL << GPIO_MD_MD14_Pos )
#define GPIO_MD_MD14_1                          ( 0x2UL << GPIO_MD_MD14_Pos )

#define GPIO_MD_MD13_Pos                        ( 26U )
#define GPIO_MD_MD13_Msk                        ( 0x3UL << GPIO_MD_MD13_Pos )
#define GPIO_MD_MD13                            ( GPIO_MD_MD13_Msk )
#define GPIO_MD_MD13_0                          ( 0x1UL << GPIO_MD_MD13_Pos )
#define GPIO_MD_MD13_1                          ( 0x2UL << GPIO_MD_MD13_Pos )

#define GPIO_MD_MD12_Pos                        ( 24U )
#define GPIO_MD_MD12_Msk                        ( 0x3UL << GPIO_MD_MD12_Pos )
#define GPIO_MD_MD12                            ( GPIO_MD_MD12_Msk )
#define GPIO_MD_MD12_0                          ( 0x1UL << GPIO_MD_MD12_Pos )
#define GPIO_MD_MD12_1                          ( 0x2UL << GPIO_MD_MD12_Pos )

#define GPIO_MD_MD11_Pos                        ( 22U )
#define GPIO_MD_MD11_Msk                        ( 0x3UL << GPIO_MD_MD11_Pos )
#define GPIO_MD_MD11                            ( GPIO_MD_MD11_Msk )
#define GPIO_MD_MD11_0                          ( 0x1UL << GPIO_MD_MD11_Pos )
#define GPIO_MD_MD11_1                          ( 0x2UL << GPIO_MD_MD11_Pos )

#define GPIO_MD_MD10_Pos                        ( 20U )
#define GPIO_MD_MD10_Msk                        ( 0x3UL << GPIO_MD_MD10_Pos )
#define GPIO_MD_MD10                            ( GPIO_MD_MD10_Msk )
#define GPIO_MD_MD10_0                          ( 0x1UL << GPIO_MD_MD10_Pos )
#define GPIO_MD_MD10_1                          ( 0x2UL << GPIO_MD_MD10_Pos )

#define GPIO_MD_MD9_Pos                         ( 18U )
#define GPIO_MD_MD9_Msk                         ( 0x3UL << GPIO_MD_MD9_Pos )
#define GPIO_MD_MD9                             ( GPIO_MD_MD9_Msk )
#define GPIO_MD_MD9_0                           ( 0x1UL << GPIO_MD_MD9_Pos )
#define GPIO_MD_MD9_1                           ( 0x2UL << GPIO_MD_MD9_Pos )

#define GPIO_MD_MD8_Pos                         ( 16U )
#define GPIO_MD_MD8_Msk                         ( 0x3UL << GPIO_MD_MD8_Pos )
#define GPIO_MD_MD8                             ( GPIO_MD_MD8_Msk )
#define GPIO_MD_MD8_0                           ( 0x1UL << GPIO_MD_MD8_Pos )
#define GPIO_MD_MD8_1                           ( 0x2UL << GPIO_MD_MD8_Pos )

#define GPIO_MD_MD7_Pos                         ( 14U )
#define GPIO_MD_MD7_Msk                         ( 0x3UL << GPIO_MD_MD7_Pos )
#define GPIO_MD_MD7                             ( GPIO_MD_MD7_Msk )
#define GPIO_MD_MD7_0                           ( 0x1UL << GPIO_MD_MD7_Pos )
#define GPIO_MD_MD7_1                           ( 0x2UL << GPIO_MD_MD7_Pos )

#define GPIO_MD_MD6_Pos                         ( 12U )
#define GPIO_MD_MD6_Msk                         ( 0x3UL << GPIO_MD_MD6_Pos )
#define GPIO_MD_MD6                             ( GPIO_MD_MD6_Msk )
#define GPIO_MD_MD6_0                           ( 0x1UL << GPIO_MD_MD6_Pos )
#define GPIO_MD_MD6_1                           ( 0x2UL << GPIO_MD_MD6_Pos )

#define GPIO_MD_MD5_Pos                         ( 10U )
#define GPIO_MD_MD5_Msk                         ( 0x3UL << GPIO_MD_MD5_Pos )
#define GPIO_MD_MD5                             ( GPIO_MD_MD5_Msk )
#define GPIO_MD_MD5_0                           ( 0x1UL << GPIO_MD_MD5_Pos )
#define GPIO_MD_MD5_1                           ( 0x2UL << GPIO_MD_MD5_Pos )

#define GPIO_MD_MD4_Pos                         ( 8U )
#define GPIO_MD_MD4_Msk                         ( 0x3UL << GPIO_MD_MD4_Pos )
#define GPIO_MD_MD4                             ( GPIO_MD_MD4_Msk )
#define GPIO_MD_MD4_0                           ( 0x1UL << GPIO_MD_MD4_Pos )
#define GPIO_MD_MD4_1                           ( 0x2UL << GPIO_MD_MD4_Pos )

#define GPIO_MD_MD3_Pos                         ( 6U )
#define GPIO_MD_MD3_Msk                         ( 0x3UL << GPIO_MD_MD3_Pos )
#define GPIO_MD_MD3                             ( GPIO_MD_MD3_Msk )
#define GPIO_MD_MD3_0                           ( 0x1UL << GPIO_MD_MD3_Pos )
#define GPIO_MD_MD3_1                           ( 0x2UL << GPIO_MD_MD3_Pos )

#define GPIO_MD_MD2_Pos                         ( 4U )
#define GPIO_MD_MD2_Msk                         ( 0x3UL << GPIO_MD_MD2_Pos )
#define GPIO_MD_MD2                             ( GPIO_MD_MD2_Msk )
#define GPIO_MD_MD2_0                           ( 0x1UL << GPIO_MD_MD2_Pos )
#define GPIO_MD_MD2_1                           ( 0x2UL << GPIO_MD_MD2_Pos )

#define GPIO_MD_MD1_Pos                         ( 2U )
#define GPIO_MD_MD1_Msk                         ( 0x3UL << GPIO_MD_MD1_Pos )
#define GPIO_MD_MD1                             ( GPIO_MD_MD1_Msk )
#define GPIO_MD_MD1_0                           ( 0x1UL << GPIO_MD_MD1_Pos )
#define GPIO_MD_MD1_1                           ( 0x2UL << GPIO_MD_MD1_Pos )

#define GPIO_MD_MD0_Pos                         ( 0U )
#define GPIO_MD_MD0_Msk                         ( 0x3UL << GPIO_MD_MD0_Pos )
#define GPIO_MD_MD0                             ( GPIO_MD_MD0_Msk )
#define GPIO_MD_MD0_0                           ( 0x1UL << GPIO_MD_MD0_Pos )
#define GPIO_MD_MD0_1                           ( 0x2UL << GPIO_MD_MD0_Pos )


/***************  Bits definition for GPIO_OTYP register  ********************/

#define GPIO_OTYP_OTYP15_Pos                    ( 15U )
#define GPIO_OTYP_OTYP15_Msk                    ( 0x1UL << GPIO_OTYP_OTYP15_Pos )
#define GPIO_OTYP_OTYP15                        ( GPIO_OTYP_OTYP15_Msk )

#define GPIO_OTYP_OTYP14_Pos                    ( 14U )
#define GPIO_OTYP_OTYP14_Msk                    ( 0x1UL << GPIO_OTYP_OTYP14_Pos )
#define GPIO_OTYP_OTYP14                        ( GPIO_OTYP_OTYP14_Msk )

#define GPIO_OTYP_OTYP13_Pos                    ( 13U )
#define GPIO_OTYP_OTYP13_Msk                    ( 0x1UL << GPIO_OTYP_OTYP13_Pos )
#define GPIO_OTYP_OTYP13                        ( GPIO_OTYP_OTYP13_Msk )

#define GPIO_OTYP_OTYP12_Pos                    ( 12U )
#define GPIO_OTYP_OTYP12_Msk                    ( 0x1UL << GPIO_OTYP_OTYP12_Pos )
#define GPIO_OTYP_OTYP12                        ( GPIO_OTYP_OTYP12_Msk )

#define GPIO_OTYP_OTYP11_Pos                    ( 11U )
#define GPIO_OTYP_OTYP11_Msk                    ( 0x1UL << GPIO_OTYP_OTYP11_Pos )
#define GPIO_OTYP_OTYP11                        ( GPIO_OTYP_OTYP11_Msk )

#define GPIO_OTYP_OTYP10_Pos                    ( 10U )
#define GPIO_OTYP_OTYP10_Msk                    ( 0x1UL << GPIO_OTYP_OTYP10_Pos )
#define GPIO_OTYP_OTYP10                        ( GPIO_OTYP_OTYP10_Msk )

#define GPIO_OTYP_OTYP9_Pos                     ( 9U )
#define GPIO_OTYP_OTYP9_Msk                     ( 0x1UL << GPIO_OTYP_OTYP9_Pos )
#define GPIO_OTYP_OTYP9                         ( GPIO_OTYP_OTYP9_Msk )

#define GPIO_OTYP_OTYP8_Pos                     ( 8U )
#define GPIO_OTYP_OTYP8_Msk                     ( 0x1UL << GPIO_OTYP_OTYP8_Pos )
#define GPIO_OTYP_OTYP8                         ( GPIO_OTYP_OTYP8_Msk )

#define GPIO_OTYP_OTYP7_Pos                     ( 7U )
#define GPIO_OTYP_OTYP7_Msk                     ( 0x1UL << GPIO_OTYP_OTYP7_Pos )
#define GPIO_OTYP_OTYP7                         ( GPIO_OTYP_OTYP7_Msk )

#define GPIO_OTYP_OTYP6_Pos                     ( 6U )
#define GPIO_OTYP_OTYP6_Msk                     ( 0x1UL << GPIO_OTYP_OTYP6_Pos )
#define GPIO_OTYP_OTYP6                         ( GPIO_OTYP_OTYP6_Msk )

#define GPIO_OTYP_OTYP5_Pos                     ( 5U )
#define GPIO_OTYP_OTYP5_Msk                     ( 0x1UL << GPIO_OTYP_OTYP5_Pos )
#define GPIO_OTYP_OTYP5                         ( GPIO_OTYP_OTYP5_Msk )

#define GPIO_OTYP_OTYP4_Pos                     ( 4U )
#define GPIO_OTYP_OTYP4_Msk                     ( 0x1UL << GPIO_OTYP_OTYP4_Pos )
#define GPIO_OTYP_OTYP4                         ( GPIO_OTYP_OTYP4_Msk )

#define GPIO_OTYP_OTYP3_Pos                     ( 3U )
#define GPIO_OTYP_OTYP3_Msk                     ( 0x1UL << GPIO_OTYP_OTYP3_Pos )
#define GPIO_OTYP_OTYP3                         ( GPIO_OTYP_OTYP3_Msk )

#define GPIO_OTYP_OTYP2_Pos                     ( 2U )
#define GPIO_OTYP_OTYP2_Msk                     ( 0x1UL << GPIO_OTYP_OTYP2_Pos )
#define GPIO_OTYP_OTYP2                         ( GPIO_OTYP_OTYP2_Msk )

#define GPIO_OTYP_OTYP1_Pos                     ( 1U )
#define GPIO_OTYP_OTYP1_Msk                     ( 0x1UL << GPIO_OTYP_OTYP1_Pos )
#define GPIO_OTYP_OTYP1                         ( GPIO_OTYP_OTYP1_Msk )

#define GPIO_OTYP_OTYP0_Pos                     ( 0U )
#define GPIO_OTYP_OTYP0_Msk                     ( 0x1UL << GPIO_OTYP_OTYP0_Pos )
#define GPIO_OTYP_OTYP0                         ( GPIO_OTYP_OTYP0_Msk )


/***************  Bits definition for GPIO_PUPD register  *******************/

#define GPIO_PUPD_PUPD15_Pos                   ( 30U )
#define GPIO_PUPD_PUPD15_Msk                   ( 0x3UL << GPIO_PUPD_PUPD15_Pos )
#define GPIO_PUPD_PUPD15                       ( GPIO_PUPD_PUPD15_Msk )
#define GPIO_PUPD_PUPD15_0                     ( 0x1UL << GPIO_PUPD_PUPD15_Pos )
#define GPIO_PUPD_PUPD15_1                     ( 0x2UL << GPIO_PUPD_PUPD15_Pos )

#define GPIO_PUPD_PUPD14_Pos                   ( 28U )
#define GPIO_PUPD_PUPD14_Msk                   ( 0x3UL << GPIO_PUPD_PUPD14_Pos )
#define GPIO_PUPD_PUPD14                       ( GPIO_PUPD_PUPD14_Msk )
#define GPIO_PUPD_PUPD14_0                     ( 0x1UL << GPIO_PUPD_PUPD14_Pos )
#define GPIO_PUPD_PUPD14_1                     ( 0x2UL << GPIO_PUPD_PUPD14_Pos )

#define GPIO_PUPD_PUPD13_Pos                   ( 26U )
#define GPIO_PUPD_PUPD13_Msk                   ( 0x3UL << GPIO_PUPD_PUPD13_Pos )
#define GPIO_PUPD_PUPD13                       ( GPIO_PUPD_PUPD13_Msk )
#define GPIO_PUPD_PUPD13_0                     ( 0x1UL << GPIO_PUPD_PUPD13_Pos )
#define GPIO_PUPD_PUPD13_1                     ( 0x2UL << GPIO_PUPD_PUPD13_Pos )

#define GPIO_PUPD_PUPD12_Pos                   ( 24U )
#define GPIO_PUPD_PUPD12_Msk                   ( 0x3UL << GPIO_PUPD_PUPD12_Pos )
#define GPIO_PUPD_PUPD12                       ( GPIO_PUPD_PUPD12_Msk )
#define GPIO_PUPD_PUPD12_0                     ( 0x1UL << GPIO_PUPD_PUPD12_Pos )
#define GPIO_PUPD_PUPD12_1                     ( 0x2UL << GPIO_PUPD_PUPD12_Pos )

#define GPIO_PUPD_PUPD11_Pos                   ( 22U )
#define GPIO_PUPD_PUPD11_Msk                   ( 0x3UL << GPIO_PUPD_PUPD11_Pos )
#define GPIO_PUPD_PUPD11                       ( GPIO_PUPD_PUPD11_Msk )
#define GPIO_PUPD_PUPD11_0                     ( 0x1UL << GPIO_PUPD_PUPD11_Pos )
#define GPIO_PUPD_PUPD11_1                     ( 0x2UL << GPIO_PUPD_PUPD11_Pos )

#define GPIO_PUPD_PUPD10_Pos                   ( 20U )
#define GPIO_PUPD_PUPD10_Msk                   ( 0x3UL << GPIO_PUPD_PUPD10_Pos )
#define GPIO_PUPD_PUPD10                       ( GPIO_PUPD_PUPD10_Msk )
#define GPIO_PUPD_PUPD10_0                     ( 0x1UL << GPIO_PUPD_PUPD10_Pos )
#define GPIO_PUPD_PUPD10_1                     ( 0x2UL << GPIO_PUPD_PUPD10_Pos )

#define GPIO_PUPD_PUPD9_Pos                    ( 18U )
#define GPIO_PUPD_PUPD9_Msk                    ( 0x3UL << GPIO_PUPD_PUPD9_Pos )
#define GPIO_PUPD_PUPD9                        ( GPIO_PUPD_PUPD9_Msk )
#define GPIO_PUPD_PUPD9_0                      ( 0x1UL << GPIO_PUPD_PUPD9_Pos )
#define GPIO_PUPD_PUPD9_1                      ( 0x2UL << GPIO_PUPD_PUPD9_Pos )

#define GPIO_PUPD_PUPD8_Pos                    ( 16U )
#define GPIO_PUPD_PUPD8_Msk                    ( 0x3UL << GPIO_PUPD_PUPD8_Pos )
#define GPIO_PUPD_PUPD8                        ( GPIO_PUPD_PUPD8_Msk )
#define GPIO_PUPD_PUPD8_0                      ( 0x1UL << GPIO_PUPD_PUPD8_Pos )
#define GPIO_PUPD_PUPD8_1                      ( 0x2UL << GPIO_PUPD_PUPD8_Pos )

#define GPIO_PUPD_PUPD7_Pos                    ( 14U )
#define GPIO_PUPD_PUPD7_Msk                    ( 0x3UL << GPIO_PUPD_PUPD7_Pos )
#define GPIO_PUPD_PUPD7                        ( GPIO_PUPD_PUPD7_Msk )
#define GPIO_PUPD_PUPD7_0                      ( 0x1UL << GPIO_PUPD_PUPD7_Pos )
#define GPIO_PUPD_PUPD7_1                      ( 0x2UL << GPIO_PUPD_PUPD7_Pos )

#define GPIO_PUPD_PUPD6_Pos                    ( 12U )
#define GPIO_PUPD_PUPD6_Msk                    ( 0x3UL << GPIO_PUPD_PUPD6_Pos )
#define GPIO_PUPD_PUPD6                        ( GPIO_PUPD_PUPD6_Msk )
#define GPIO_PUPD_PUPD6_0                      ( 0x1UL << GPIO_PUPD_PUPD6_Pos )
#define GPIO_PUPD_PUPD6_1                      ( 0x2UL << GPIO_PUPD_PUPD6_Pos )

#define GPIO_PUPD_PUPD5_Pos                    ( 10U )
#define GPIO_PUPD_PUPD5_Msk                    ( 0x3UL << GPIO_PUPD_PUPD5_Pos )
#define GPIO_PUPD_PUPD5                        ( GPIO_PUPD_PUPD5_Msk )
#define GPIO_PUPD_PUPD5_0                      ( 0x1UL << GPIO_PUPD_PUPD5_Pos )
#define GPIO_PUPD_PUPD5_1                      ( 0x2UL << GPIO_PUPD_PUPD5_Pos )

#define GPIO_PUPD_PUPD4_Pos                    ( 8U )
#define GPIO_PUPD_PUPD4_Msk                    ( 0x3UL << GPIO_PUPD_PUPD4_Pos )
#define GPIO_PUPD_PUPD4                        ( GPIO_PUPD_PUPD4_Msk )
#define GPIO_PUPD_PUPD4_0                      ( 0x1UL << GPIO_PUPD_PUPD4_Pos )
#define GPIO_PUPD_PUPD4_1                      ( 0x2UL << GPIO_PUPD_PUPD4_Pos )

#define GPIO_PUPD_PUPD3_Pos                    ( 6U )
#define GPIO_PUPD_PUPD3_Msk                    ( 0x3UL << GPIO_PUPD_PUPD3_Pos )
#define GPIO_PUPD_PUPD3                        ( GPIO_PUPD_PUPD3_Msk )
#define GPIO_PUPD_PUPD3_0                      ( 0x1UL << GPIO_PUPD_PUPD3_Pos )
#define GPIO_PUPD_PUPD3_1                      ( 0x2UL << GPIO_PUPD_PUPD3_Pos )

#define GPIO_PUPD_PUPD2_Pos                    ( 4U )
#define GPIO_PUPD_PUPD2_Msk                    ( 0x3UL << GPIO_PUPD_PUPD2_Pos )
#define GPIO_PUPD_PUPD2                        ( GPIO_PUPD_PUPD2_Msk )
#define GPIO_PUPD_PUPD2_0                      ( 0x1UL << GPIO_PUPD_PUPD2_Pos )
#define GPIO_PUPD_PUPD2_1                      ( 0x2UL << GPIO_PUPD_PUPD2_Pos )

#define GPIO_PUPD_PUPD1_Pos                    ( 2U )
#define GPIO_PUPD_PUPD1_Msk                    ( 0x3UL << GPIO_PUPD_PUPD1_Pos )
#define GPIO_PUPD_PUPD1                        ( GPIO_PUPD_PUPD1_Msk )
#define GPIO_PUPD_PUPD1_0                      ( 0x1UL << GPIO_PUPD_PUPD1_Pos )
#define GPIO_PUPD_PUPD1_1                      ( 0x2UL << GPIO_PUPD_PUPD1_Pos )

#define GPIO_PUPD_PUPD0_Pos                    ( 0U )
#define GPIO_PUPD_PUPD0_Msk                    ( 0x3UL << GPIO_PUPD_PUPD0_Pos )
#define GPIO_PUPD_PUPD0                        ( GPIO_PUPD_PUPD0_Msk )
#define GPIO_PUPD_PUPD0_0                      ( 0x1UL << GPIO_PUPD_PUPD0_Pos )
#define GPIO_PUPD_PUPD0_1                      ( 0x2UL << GPIO_PUPD_PUPD0_Pos )


/***************  Bits definition for GPIO_IDATA register  *******************/

#define GPIO_IDATA_IDATA15_Pos                  ( 15U )
#define GPIO_IDATA_IDATA15_Msk                  ( 0x1UL << GPIO_IDATA_IDATA15_Pos )
#define GPIO_IDATA_IDATA15                      ( GPIO_IDATA_IDATA15_Msk )

#define GPIO_IDATA_IDATA14_Pos                  ( 14U )
#define GPIO_IDATA_IDATA14_Msk                  ( 0x1UL << GPIO_IDATA_IDATA14_Pos )
#define GPIO_IDATA_IDATA14                      ( GPIO_IDATA_IDATA14_Msk )

#define GPIO_IDATA_IDATA13_Pos                  ( 13U )
#define GPIO_IDATA_IDATA13_Msk                  ( 0x1UL << GPIO_IDATA_IDATA13_Pos )
#define GPIO_IDATA_IDATA13                      ( GPIO_IDATA_IDATA13_Msk )

#define GPIO_IDATA_IDATA12_Pos                  ( 12U )
#define GPIO_IDATA_IDATA12_Msk                  ( 0x1UL << GPIO_IDATA_IDATA12_Pos )
#define GPIO_IDATA_IDATA12                      ( GPIO_IDATA_IDATA12_Msk )

#define GPIO_IDATA_IDATA11_Pos                  ( 11U )
#define GPIO_IDATA_IDATA11_Msk                  ( 0x1UL << GPIO_IDATA_IDATA11_Pos )
#define GPIO_IDATA_IDATA11                      ( GPIO_IDATA_IDATA11_Msk )

#define GPIO_IDATA_IDATA10_Pos                  ( 10U )
#define GPIO_IDATA_IDATA10_Msk                  ( 0x1UL << GPIO_IDATA_IDATA10_Pos )
#define GPIO_IDATA_IDATA10                      ( GPIO_IDATA_IDATA10_Msk )

#define GPIO_IDATA_IDATA9_Pos                   ( 9U )
#define GPIO_IDATA_IDATA9_Msk                   ( 0x1UL << GPIO_IDATA_IDATA9_Pos )
#define GPIO_IDATA_IDATA9                       ( GPIO_IDATA_IDATA9_Msk )

#define GPIO_IDATA_IDATA8_Pos                   ( 8U )
#define GPIO_IDATA_IDATA8_Msk                   ( 0x1UL << GPIO_IDATA_IDATA8_Pos )
#define GPIO_IDATA_IDATA8                       ( GPIO_IDATA_IDATA8_Msk )

#define GPIO_IDATA_IDATA7_Pos                   ( 7U )
#define GPIO_IDATA_IDATA7_Msk                   ( 0x1UL << GPIO_IDATA_IDATA7_Pos )
#define GPIO_IDATA_IDATA7                       ( GPIO_IDATA_IDATA7_Msk )

#define GPIO_IDATA_IDATA6_Pos                   ( 6U )
#define GPIO_IDATA_IDATA6_Msk                   ( 0x1UL << GPIO_IDATA_IDATA6_Pos )
#define GPIO_IDATA_IDATA6                       ( GPIO_IDATA_IDATA6_Msk )

#define GPIO_IDATA_IDATA5_Pos                   ( 5U )
#define GPIO_IDATA_IDATA5_Msk                   ( 0x1UL << GPIO_IDATA_IDATA5_Pos )
#define GPIO_IDATA_IDATA5                       ( GPIO_IDATA_IDATA5_Msk )

#define GPIO_IDATA_IDATA4_Pos                   ( 4U )
#define GPIO_IDATA_IDATA4_Msk                   ( 0x1UL << GPIO_IDATA_IDATA4_Pos )
#define GPIO_IDATA_IDATA4                       ( GPIO_IDATA_IDATA4_Msk )

#define GPIO_IDATA_IDATA3_Pos                   ( 3U )
#define GPIO_IDATA_IDATA3_Msk                   ( 0x1UL << GPIO_IDATA_IDATA3_Pos )
#define GPIO_IDATA_IDATA3                       ( GPIO_IDATA_IDATA3_Msk )

#define GPIO_IDATA_IDATA2_Pos                   ( 2U )
#define GPIO_IDATA_IDATA2_Msk                   ( 0x1UL << GPIO_IDATA_IDATA2_Pos )
#define GPIO_IDATA_IDATA2                       ( GPIO_IDATA_IDATA2_Msk )

#define GPIO_IDATA_IDATA1_Pos                   ( 1U )
#define GPIO_IDATA_IDATA1_Msk                   ( 0x1UL << GPIO_IDATA_IDATA1_Pos )
#define GPIO_IDATA_IDATA1                       ( GPIO_IDATA_IDATA1_Msk )

#define GPIO_IDATA_IDATA0_Pos                   ( 0U )
#define GPIO_IDATA_IDATA0_Msk                   ( 0x1UL << GPIO_IDATA_IDATA0_Pos )
#define GPIO_IDATA_IDATA0                       ( GPIO_IDATA_IDATA0_Msk )


/***************  Bits definition for GPIO_ODATA register  *******************/

#define GPIO_ODATA_ODATA15_Pos                  ( 15U )
#define GPIO_ODATA_ODATA15_Msk                  ( 0x1UL << GPIO_ODATA_ODATA15_Pos )
#define GPIO_ODATA_ODATA15                      ( GPIO_ODATA_ODATA15_Msk )

#define GPIO_ODATA_ODATA14_Pos                  ( 14U )
#define GPIO_ODATA_ODATA14_Msk                  ( 0x1UL << GPIO_ODATA_ODATA14_Pos )
#define GPIO_ODATA_ODATA14                      ( GPIO_ODATA_ODATA14_Msk )

#define GPIO_ODATA_ODATA13_Pos                  ( 13U )
#define GPIO_ODATA_ODATA13_Msk                  ( 0x1UL << GPIO_ODATA_ODATA13_Pos )
#define GPIO_ODATA_ODATA13                      ( GPIO_ODATA_ODATA13_Msk )

#define GPIO_ODATA_ODATA12_Pos                  ( 12U )
#define GPIO_ODATA_ODATA12_Msk                  ( 0x1UL << GPIO_ODATA_ODATA12_Pos )
#define GPIO_ODATA_ODATA12                      ( GPIO_ODATA_ODATA12_Msk )

#define GPIO_ODATA_ODATA11_Pos                  ( 11U )
#define GPIO_ODATA_ODATA11_Msk                  ( 0x1UL << GPIO_ODATA_ODATA11_Pos )
#define GPIO_ODATA_ODATA11                      ( GPIO_ODATA_ODATA11_Msk )

#define GPIO_ODATA_ODATA10_Pos                  ( 10U )
#define GPIO_ODATA_ODATA10_Msk                  ( 0x1UL << GPIO_ODATA_ODATA10_Pos )
#define GPIO_ODATA_ODATA10                      ( GPIO_ODATA_ODATA10_Msk )

#define GPIO_ODATA_ODATA9_Pos                   ( 9U )
#define GPIO_ODATA_ODATA9_Msk                   ( 0x1UL << GPIO_ODATA_ODATA9_Pos )
#define GPIO_ODATA_ODATA9                       ( GPIO_ODATA_ODATA9_Msk )

#define GPIO_ODATA_ODATA8_Pos                   ( 8U )
#define GPIO_ODATA_ODATA8_Msk                   ( 0x1UL << GPIO_ODATA_ODATA8_Pos )
#define GPIO_ODATA_ODATA8                       ( GPIO_ODATA_ODATA8_Msk )

#define GPIO_ODATA_ODATA7_Pos                   ( 7U )
#define GPIO_ODATA_ODATA7_Msk                   ( 0x1UL << GPIO_ODATA_ODATA7_Pos )
#define GPIO_ODATA_ODATA7                       ( GPIO_ODATA_ODATA7_Msk )

#define GPIO_ODATA_ODATA6_Pos                   ( 6U )
#define GPIO_ODATA_ODATA6_Msk                   ( 0x1UL << GPIO_ODATA_ODATA6_Pos )
#define GPIO_ODATA_ODATA6                       ( GPIO_ODATA_ODATA6_Msk )

#define GPIO_ODATA_ODATA5_Pos                   ( 5U )
#define GPIO_ODATA_ODATA5_Msk                   ( 0x1UL << GPIO_ODATA_ODATA5_Pos )
#define GPIO_ODATA_ODATA5                       ( GPIO_ODATA_ODATA5_Msk )

#define GPIO_ODATA_ODATA4_Pos                   ( 4U )
#define GPIO_ODATA_ODATA4_Msk                   ( 0x1UL << GPIO_ODATA_ODATA4_Pos )
#define GPIO_ODATA_ODATA4                       ( GPIO_ODATA_ODATA4_Msk )

#define GPIO_ODATA_ODATA3_Pos                   ( 3U )
#define GPIO_ODATA_ODATA3_Msk                   ( 0x1UL << GPIO_ODATA_ODATA3_Pos )
#define GPIO_ODATA_ODATA3                       ( GPIO_ODATA_ODATA3_Msk )

#define GPIO_ODATA_ODATA2_Pos                   ( 2U )
#define GPIO_ODATA_ODATA2_Msk                   ( 0x1UL << GPIO_ODATA_ODATA2_Pos )
#define GPIO_ODATA_ODATA2                       ( GPIO_ODATA_ODATA2_Msk )

#define GPIO_ODATA_ODATA1_Pos                   ( 1U )
#define GPIO_ODATA_ODATA1_Msk                   ( 0x1UL << GPIO_ODATA_ODATA1_Pos )
#define GPIO_ODATA_ODATA1                       ( GPIO_ODATA_ODATA1_Msk )

#define GPIO_ODATA_ODATA0_Pos                   ( 0U )
#define GPIO_ODATA_ODATA0_Msk                   ( 0x1UL << GPIO_ODATA_ODATA0_Pos )
#define GPIO_ODATA_ODATA0                       ( GPIO_ODATA_ODATA0_Msk )


/***************  Bits definition for GPIO_BSC register  *********************/

#define GPIO_BSC_CLR15_Pos                      ( 31U )
#define GPIO_BSC_CLR15_Msk                      ( 0x1UL << GPIO_BSC_CLR15_Pos )
#define GPIO_BSC_CLR15                          ( GPIO_BSC_CLR15_Msk )

#define GPIO_BSC_CLR14_Pos                      ( 30U )
#define GPIO_BSC_CLR14_Msk                      ( 0x1UL << GPIO_BSC_CLR14_Pos )
#define GPIO_BSC_CLR14                          ( GPIO_BSC_CLR14_Msk )

#define GPIO_BSC_CLR13_Pos                      ( 29U )
#define GPIO_BSC_CLR13_Msk                      ( 0x1UL << GPIO_BSC_CLR13_Pos )
#define GPIO_BSC_CLR13                          ( GPIO_BSC_CLR13_Msk )

#define GPIO_BSC_CLR12_Pos                      ( 28U )
#define GPIO_BSC_CLR12_Msk                      ( 0x1UL << GPIO_BSC_CLR12_Pos )
#define GPIO_BSC_CLR12                          ( GPIO_BSC_CLR12_Msk )

#define GPIO_BSC_CLR11_Pos                      ( 27U )
#define GPIO_BSC_CLR11_Msk                      ( 0x1UL << GPIO_BSC_CLR11_Pos )
#define GPIO_BSC_CLR11                          ( GPIO_BSC_CLR11_Msk )

#define GPIO_BSC_CLR10_Pos                      ( 26U )
#define GPIO_BSC_CLR10_Msk                      ( 0x1UL << GPIO_BSC_CLR10_Pos )
#define GPIO_BSC_CLR10                          ( GPIO_BSC_CLR10_Msk )

#define GPIO_BSC_CLR9_Pos                       ( 25U )
#define GPIO_BSC_CLR9_Msk                       ( 0x1UL << GPIO_BSC_CLR9_Pos )
#define GPIO_BSC_CLR9                           ( GPIO_BSC_CLR9_Msk )

#define GPIO_BSC_CLR8_Pos                       ( 24U )
#define GPIO_BSC_CLR8_Msk                       ( 0x1UL << GPIO_BSC_CLR8_Pos )
#define GPIO_BSC_CLR8                           ( GPIO_BSC_CLR8_Msk )

#define GPIO_BSC_CLR7_Pos                       ( 23U )
#define GPIO_BSC_CLR7_Msk                       ( 0x1UL << GPIO_BSC_CLR7_Pos )
#define GPIO_BSC_CLR7                           ( GPIO_BSC_CLR7_Msk )

#define GPIO_BSC_CLR6_Pos                       ( 22U )
#define GPIO_BSC_CLR6_Msk                       ( 0x1UL << GPIO_BSC_CLR6_Pos )
#define GPIO_BSC_CLR6                           ( GPIO_BSC_CLR6_Msk )

#define GPIO_BSC_CLR5_Pos                       ( 21U )
#define GPIO_BSC_CLR5_Msk                       ( 0x1UL << GPIO_BSC_CLR5_Pos )
#define GPIO_BSC_CLR5                           ( GPIO_BSC_CLR5_Msk )

#define GPIO_BSC_CLR4_Pos                       ( 20U )
#define GPIO_BSC_CLR4_Msk                       ( 0x1UL << GPIO_BSC_CLR4_Pos )
#define GPIO_BSC_CLR4                           ( GPIO_BSC_CLR4_Msk )

#define GPIO_BSC_CLR3_Pos                       ( 19U )
#define GPIO_BSC_CLR3_Msk                       ( 0x1UL << GPIO_BSC_CLR3_Pos )
#define GPIO_BSC_CLR3                           ( GPIO_BSC_CLR3_Msk )

#define GPIO_BSC_CLR2_Pos                       ( 18U )
#define GPIO_BSC_CLR2_Msk                       ( 0x1UL << GPIO_BSC_CLR2_Pos )
#define GPIO_BSC_CLR2                           ( GPIO_BSC_CLR2_Msk )

#define GPIO_BSC_CLR1_Pos                       ( 17U )
#define GPIO_BSC_CLR1_Msk                       ( 0x1UL << GPIO_BSC_CLR1_Pos )
#define GPIO_BSC_CLR1                           ( GPIO_BSC_CLR1_Msk )

#define GPIO_BSC_CLR0_Pos                       ( 16U )
#define GPIO_BSC_CLR0_Msk                       ( 0x1UL << GPIO_BSC_CLR0_Pos )
#define GPIO_BSC_CLR0                           ( GPIO_BSC_CLR0_Msk )

#define GPIO_BSC_SET15_Pos                      ( 15U )
#define GPIO_BSC_SET15_Msk                      ( 0x1UL << GPIO_BSC_SET15_Pos )
#define GPIO_BSC_SET15                          ( GPIO_BSC_SET15_Msk )

#define GPIO_BSC_SET14_Pos                      ( 14U )
#define GPIO_BSC_SET14_Msk                      ( 0x1UL << GPIO_BSC_SET14_Pos )
#define GPIO_BSC_SET14                          ( GPIO_BSC_SET14_Msk )

#define GPIO_BSC_SET13_Pos                      ( 13U )
#define GPIO_BSC_SET13_Msk                      ( 0x1UL << GPIO_BSC_SET13_Pos )
#define GPIO_BSC_SET13                          ( GPIO_BSC_SET13_Msk )

#define GPIO_BSC_SET12_Pos                      ( 12U )
#define GPIO_BSC_SET12_Msk                      ( 0x1UL << GPIO_BSC_SET12_Pos )
#define GPIO_BSC_SET12                          ( GPIO_BSC_SET12_Msk )

#define GPIO_BSC_SET11_Pos                      ( 11U )
#define GPIO_BSC_SET11_Msk                      ( 0x1UL << GPIO_BSC_SET11_Pos )
#define GPIO_BSC_SET11                          ( GPIO_BSC_SET11_Msk )

#define GPIO_BSC_SET10_Pos                      ( 10U )
#define GPIO_BSC_SET10_Msk                      ( 0x1UL << GPIO_BSC_SET10_Pos )
#define GPIO_BSC_SET10                          ( GPIO_BSC_SET10_Msk )

#define GPIO_BSC_SET9_Pos                       ( 9U )
#define GPIO_BSC_SET9_Msk                       ( 0x1UL << GPIO_BSC_SET9_Pos )
#define GPIO_BSC_SET9                           ( GPIO_BSC_SET9_Msk )

#define GPIO_BSC_SET8_Pos                       ( 8U )
#define GPIO_BSC_SET8_Msk                       ( 0x1UL << GPIO_BSC_SET8_Pos )
#define GPIO_BSC_SET8                           ( GPIO_BSC_SET8_Msk )

#define GPIO_BSC_SET7_Pos                       ( 7U )
#define GPIO_BSC_SET7_Msk                       ( 0x1UL << GPIO_BSC_SET7_Pos )
#define GPIO_BSC_SET7                           ( GPIO_BSC_SET7_Msk )

#define GPIO_BSC_SET6_Pos                       ( 6U )
#define GPIO_BSC_SET6_Msk                       ( 0x1UL << GPIO_BSC_SET6_Pos )
#define GPIO_BSC_SET6                           ( GPIO_BSC_SET6_Msk )

#define GPIO_BSC_SET5_Pos                       ( 5U )
#define GPIO_BSC_SET5_Msk                       ( 0x1UL << GPIO_BSC_SET5_Pos )
#define GPIO_BSC_SET5                           ( GPIO_BSC_SET5_Msk )

#define GPIO_BSC_SET4_Pos                       ( 4U )
#define GPIO_BSC_SET4_Msk                       ( 0x1UL << GPIO_BSC_SET4_Pos )
#define GPIO_BSC_SET4                           ( GPIO_BSC_SET4_Msk )

#define GPIO_BSC_SET3_Pos                       ( 3U )
#define GPIO_BSC_SET3_Msk                       ( 0x1UL << GPIO_BSC_SET3_Pos )
#define GPIO_BSC_SET3                           ( GPIO_BSC_SET3_Msk )

#define GPIO_BSC_SET2_Pos                       ( 2U )
#define GPIO_BSC_SET2_Msk                       ( 0x1UL << GPIO_BSC_SET2_Pos )
#define GPIO_BSC_SET2                           ( GPIO_BSC_SET2_Msk )

#define GPIO_BSC_SET1_Pos                       ( 1U )
#define GPIO_BSC_SET1_Msk                       ( 0x1UL << GPIO_BSC_SET1_Pos )
#define GPIO_BSC_SET1                           ( GPIO_BSC_SET1_Msk )

#define GPIO_BSC_SET0_Pos                       ( 0U )
#define GPIO_BSC_SET0_Msk                       ( 0x1UL << GPIO_BSC_SET0_Pos )
#define GPIO_BSC_SET0                           ( GPIO_BSC_SET0_Msk )

/***************  Bits definition for GPIO_AF0 register  *********************/

#define GPIO_AF0_AFSEL7_Pos                     ( 28U )
#define GPIO_AF0_AFSEL7_Msk                     ( 0xFUL << GPIO_AF0_AFSEL7_Pos )
#define GPIO_AF0_AFSEL7                         ( GPIO_AF0_AFSEL7_Msk )
#define GPIO_AF0_AFSEL7_0                       ( 0x1UL << GPIO_AF0_AFSEL7_Pos )
#define GPIO_AF0_AFSEL7_1                       ( 0x2UL << GPIO_AF0_AFSEL7_Pos )
#define GPIO_AF0_AFSEL7_2                       ( 0x4UL << GPIO_AF0_AFSEL7_Pos )
#define GPIO_AF0_AFSEL7_3                       ( 0x8UL << GPIO_AF0_AFSEL7_Pos )

#define GPIO_AF0_AFSEL6_Pos                     ( 24U )
#define GPIO_AF0_AFSEL6_Msk                     ( 0xFUL << GPIO_AF0_AFSEL6_Pos )
#define GPIO_AF0_AFSEL6                         ( GPIO_AF0_AFSEL6_Msk )
#define GPIO_AF0_AFSEL6_0                       ( 0x1UL << GPIO_AF0_AFSEL6_Pos )
#define GPIO_AF0_AFSEL6_1                       ( 0x2UL << GPIO_AF0_AFSEL6_Pos )
#define GPIO_AF0_AFSEL6_2                       ( 0x4UL << GPIO_AF0_AFSEL6_Pos )
#define GPIO_AF0_AFSEL6_3                       ( 0x8UL << GPIO_AF0_AFSEL6_Pos )

#define GPIO_AF0_AFSEL5_Pos                     ( 20U )
#define GPIO_AF0_AFSEL5_Msk                     ( 0xFUL << GPIO_AF0_AFSEL5_Pos )
#define GPIO_AF0_AFSEL5                         ( GPIO_AF0_AFSEL5_Msk )
#define GPIO_AF0_AFSEL5_0                       ( 0x1UL << GPIO_AF0_AFSEL5_Pos )
#define GPIO_AF0_AFSEL5_1                       ( 0x2UL << GPIO_AF0_AFSEL5_Pos )
#define GPIO_AF0_AFSEL5_2                       ( 0x4UL << GPIO_AF0_AFSEL5_Pos )
#define GPIO_AF0_AFSEL5_3                       ( 0x8UL << GPIO_AF0_AFSEL5_Pos )

#define GPIO_AF0_AFSEL4_Pos                     ( 16U )
#define GPIO_AF0_AFSEL4_Msk                     ( 0xFUL << GPIO_AF0_AFSEL4_Pos )
#define GPIO_AF0_AFSEL4                         ( GPIO_AF0_AFSEL4_Msk )
#define GPIO_AF0_AFSEL4_0                       ( 0x1UL << GPIO_AF0_AFSEL4_Pos )
#define GPIO_AF0_AFSEL4_1                       ( 0x2UL << GPIO_AF0_AFSEL4_Pos )
#define GPIO_AF0_AFSEL4_2                       ( 0x4UL << GPIO_AF0_AFSEL4_Pos )
#define GPIO_AF0_AFSEL4_3                       ( 0x8UL << GPIO_AF0_AFSEL4_Pos )

#define GPIO_AF0_AFSEL3_Pos                     ( 12U )
#define GPIO_AF0_AFSEL3_Msk                     ( 0xFUL << GPIO_AF0_AFSEL3_Pos )
#define GPIO_AF0_AFSEL3                         ( GPIO_AF0_AFSEL3_Msk )
#define GPIO_AF0_AFSEL3_0                       ( 0x1UL << GPIO_AF0_AFSEL3_Pos )
#define GPIO_AF0_AFSEL3_1                       ( 0x2UL << GPIO_AF0_AFSEL3_Pos )
#define GPIO_AF0_AFSEL3_2                       ( 0x4UL << GPIO_AF0_AFSEL3_Pos )
#define GPIO_AF0_AFSEL3_3                       ( 0x8UL << GPIO_AF0_AFSEL3_Pos )

#define GPIO_AF0_AFSEL2_Pos                     ( 8U )
#define GPIO_AF0_AFSEL2_Msk                     ( 0xFUL << GPIO_AF0_AFSEL2_Pos )
#define GPIO_AF0_AFSEL2                         ( GPIO_AF0_AFSEL2_Msk )
#define GPIO_AF0_AFSEL2_0                       ( 0x1UL << GPIO_AF0_AFSEL2_Pos )
#define GPIO_AF0_AFSEL2_1                       ( 0x2UL << GPIO_AF0_AFSEL2_Pos )
#define GPIO_AF0_AFSEL2_2                       ( 0x4UL << GPIO_AF0_AFSEL2_Pos )
#define GPIO_AF0_AFSEL2_3                       ( 0x8UL << GPIO_AF0_AFSEL2_Pos )

#define GPIO_AF0_AFSEL1_Pos                     ( 4U )
#define GPIO_AF0_AFSEL1_Msk                     ( 0xFUL << GPIO_AF0_AFSEL1_Pos )
#define GPIO_AF0_AFSEL1                         ( GPIO_AF0_AFSEL1_Msk )
#define GPIO_AF0_AFSEL1_0                       ( 0x1UL << GPIO_AF0_AFSEL1_Pos )
#define GPIO_AF0_AFSEL1_1                       ( 0x2UL << GPIO_AF0_AFSEL1_Pos )
#define GPIO_AF0_AFSEL1_2                       ( 0x4UL << GPIO_AF0_AFSEL1_Pos )
#define GPIO_AF0_AFSEL1_3                       ( 0x8UL << GPIO_AF0_AFSEL1_Pos )

#define GPIO_AF0_AFSEL0_Pos                     ( 0U )
#define GPIO_AF0_AFSEL0_Msk                     ( 0xFUL << GPIO_AF0_AFSEL0_Pos )
#define GPIO_AF0_AFSEL0                         ( GPIO_AF0_AFSEL0_Msk )
#define GPIO_AF0_AFSEL0_0                       ( 0x1UL << GPIO_AF0_AFSEL0_Pos )
#define GPIO_AF0_AFSEL0_1                       ( 0x2UL << GPIO_AF0_AFSEL0_Pos )
#define GPIO_AF0_AFSEL0_2                       ( 0x4UL << GPIO_AF0_AFSEL0_Pos )
#define GPIO_AF0_AFSEL0_3                       ( 0x8UL << GPIO_AF0_AFSEL0_Pos )


/***************  Bits definition for GPIO_AF1 register  *********************/

#define GPIO_AF1_AFSEL15_Pos                    ( 28U )
#define GPIO_AF1_AFSEL15_Msk                    ( 0xFUL << GPIO_AF1_AFSEL15_Pos )
#define GPIO_AF1_AFSEL15                        ( GPIO_AF1_AFSEL15_Msk )
#define GPIO_AF1_AFSEL15_0                      ( 0x1UL << GPIO_AF1_AFSEL15_Pos )
#define GPIO_AF1_AFSEL15_1                      ( 0x2UL << GPIO_AF1_AFSEL15_Pos )
#define GPIO_AF1_AFSEL15_2                      ( 0x4UL << GPIO_AF1_AFSEL15_Pos )
#define GPIO_AF1_AFSEL15_3                      ( 0x8UL << GPIO_AF1_AFSEL15_Pos )

#define GPIO_AF1_AFSEL14_Pos                    ( 24U )
#define GPIO_AF1_AFSEL14_Msk                    ( 0xFUL << GPIO_AF1_AFSEL14_Pos )
#define GPIO_AF1_AFSEL14                        ( GPIO_AF1_AFSEL14_Msk )
#define GPIO_AF1_AFSEL14_0                      ( 0x1UL << GPIO_AF1_AFSEL14_Pos )
#define GPIO_AF1_AFSEL14_1                      ( 0x2UL << GPIO_AF1_AFSEL14_Pos )
#define GPIO_AF1_AFSEL14_2                      ( 0x4UL << GPIO_AF1_AFSEL14_Pos )
#define GPIO_AF1_AFSEL14_3                      ( 0x8UL << GPIO_AF1_AFSEL14_Pos )

#define GPIO_AF1_AFSEL13_Pos                    ( 20U )
#define GPIO_AF1_AFSEL13_Msk                    ( 0xFUL << GPIO_AF1_AFSEL13_Pos )
#define GPIO_AF1_AFSEL13                        ( GPIO_AF1_AFSEL13_Msk )
#define GPIO_AF1_AFSEL13_0                      ( 0x1UL << GPIO_AF1_AFSEL13_Pos )
#define GPIO_AF1_AFSEL13_1                      ( 0x2UL << GPIO_AF1_AFSEL13_Pos )
#define GPIO_AF1_AFSEL13_2                      ( 0x4UL << GPIO_AF1_AFSEL13_Pos )
#define GPIO_AF1_AFSEL13_3                      ( 0x8UL << GPIO_AF1_AFSEL13_Pos )

#define GPIO_AF1_AFSEL12_Pos                    ( 16U )
#define GPIO_AF1_AFSEL12_Msk                    ( 0xFUL << GPIO_AF1_AFSEL12_Pos )
#define GPIO_AF1_AFSEL12                        ( GPIO_AF1_AFSEL12_Msk )
#define GPIO_AF1_AFSEL12_0                      ( 0x1UL << GPIO_AF1_AFSEL12_Pos )
#define GPIO_AF1_AFSEL12_1                      ( 0x2UL << GPIO_AF1_AFSEL12_Pos )
#define GPIO_AF1_AFSEL12_2                      ( 0x4UL << GPIO_AF1_AFSEL12_Pos )
#define GPIO_AF1_AFSEL12_3                      ( 0x8UL << GPIO_AF1_AFSEL12_Pos )

#define GPIO_AF1_AFSEL11_Pos                    ( 12U )
#define GPIO_AF1_AFSEL11_Msk                    ( 0xFUL << GPIO_AF1_AFSEL11_Pos )
#define GPIO_AF1_AFSEL11                        ( GPIO_AF1_AFSEL11_Msk )
#define GPIO_AF1_AFSEL11_0                      ( 0x1UL << GPIO_AF1_AFSEL11_Pos )
#define GPIO_AF1_AFSEL11_1                      ( 0x2UL << GPIO_AF1_AFSEL11_Pos )
#define GPIO_AF1_AFSEL11_2                      ( 0x4UL << GPIO_AF1_AFSEL11_Pos )
#define GPIO_AF1_AFSEL11_3                      ( 0x8UL << GPIO_AF1_AFSEL11_Pos )

#define GPIO_AF1_AFSEL10_Pos                    ( 8U )
#define GPIO_AF1_AFSEL10_Msk                    ( 0xFUL << GPIO_AF1_AFSEL10_Pos )
#define GPIO_AF1_AFSEL10                        ( GPIO_AF1_AFSEL10_Msk )
#define GPIO_AF1_AFSEL10_0                      ( 0x1UL << GPIO_AF1_AFSEL10_Pos )
#define GPIO_AF1_AFSEL10_1                      ( 0x2UL << GPIO_AF1_AFSEL10_Pos )
#define GPIO_AF1_AFSEL10_2                      ( 0x4UL << GPIO_AF1_AFSEL10_Pos )
#define GPIO_AF1_AFSEL10_3                      ( 0x8UL << GPIO_AF1_AFSEL10_Pos )

#define GPIO_AF1_AFSEL9_Pos                     ( 4U )
#define GPIO_AF1_AFSEL9_Msk                     ( 0xFUL << GPIO_AF1_AFSEL9_Pos )
#define GPIO_AF1_AFSEL9                         ( GPIO_AF1_AFSEL9_Msk )
#define GPIO_AF1_AFSEL9_0                       ( 0x1UL << GPIO_AF1_AFSEL9_Pos )
#define GPIO_AF1_AFSEL9_1                       ( 0x2UL << GPIO_AF1_AFSEL9_Pos )
#define GPIO_AF1_AFSEL9_2                       ( 0x4UL << GPIO_AF1_AFSEL9_Pos )
#define GPIO_AF1_AFSEL9_3                       ( 0x8UL << GPIO_AF1_AFSEL9_Pos )

#define GPIO_AF1_AFSEL8_Pos                     ( 0U )
#define GPIO_AF1_AFSEL8_Msk                     ( 0xFUL << GPIO_AF1_AFSEL8_Pos )
#define GPIO_AF1_AFSEL8                         ( GPIO_AF1_AFSEL8_Msk )
#define GPIO_AF1_AFSEL8_0                       ( 0x1UL << GPIO_AF1_AFSEL8_Pos )
#define GPIO_AF1_AFSEL8_1                       ( 0x2UL << GPIO_AF1_AFSEL8_Pos )
#define GPIO_AF1_AFSEL8_2                       ( 0x4UL << GPIO_AF1_AFSEL8_Pos )
#define GPIO_AF1_AFSEL8_3                       ( 0x8UL << GPIO_AF1_AFSEL8_Pos )


/***************  Bits definition for GPIO_DS0 register  *********************/

#define GPIO_DS0_DS7_Pos                        ( 28U )
#define GPIO_DS0_DS7_Msk                        ( 0xFUL << GPIO_DS0_DS7_Pos )
#define GPIO_DS0_DS7                            ( GPIO_DS0_DS7_Msk )
#define GPIO_DS0_DS7_0                          ( 0x1UL << GPIO_DS0_DS7_Pos )
#define GPIO_DS0_DS7_1                          ( 0x2UL << GPIO_DS0_DS7_Pos )
#define GPIO_DS0_DS7_2                          ( 0x4UL << GPIO_DS0_DS7_Pos )
#define GPIO_DS0_DS7_3                          ( 0x8UL << GPIO_DS0_DS7_Pos )

#define GPIO_DS0_DS6_Pos                        ( 24U )
#define GPIO_DS0_DS6_Msk                        ( 0xFUL << GPIO_DS0_DS6_Pos )
#define GPIO_DS0_DS6                            ( GPIO_DS0_DS6_Msk )
#define GPIO_DS0_DS6_0                          ( 0x1UL << GPIO_DS0_DS6_Pos )
#define GPIO_DS0_DS6_1                          ( 0x2UL << GPIO_DS0_DS6_Pos )
#define GPIO_DS0_DS6_2                          ( 0x4UL << GPIO_DS0_DS6_Pos )
#define GPIO_DS0_DS6_3                          ( 0x8UL << GPIO_DS0_DS6_Pos )

#define GPIO_DS0_DS5_Pos                        ( 20U )
#define GPIO_DS0_DS5_Msk                        ( 0xFUL << GPIO_DS0_DS5_Pos )
#define GPIO_DS0_DS5                            ( GPIO_DS0_DS5_Msk )
#define GPIO_DS0_DS5_0                          ( 0x1UL << GPIO_DS0_DS5_Pos )
#define GPIO_DS0_DS5_1                          ( 0x2UL << GPIO_DS0_DS5_Pos )
#define GPIO_DS0_DS5_2                          ( 0x4UL << GPIO_DS0_DS5_Pos )
#define GPIO_DS0_DS5_3                          ( 0x8UL << GPIO_DS0_DS5_Pos )

#define GPIO_DS0_DS4_Pos                        ( 16U )
#define GPIO_DS0_DS4_Msk                        ( 0xFUL << GPIO_DS0_DS4_Pos )
#define GPIO_DS0_DS4                            ( GPIO_DS0_DS4_Msk )
#define GPIO_DS0_DS4_0                          ( 0x1UL << GPIO_DS0_DS4_Pos )
#define GPIO_DS0_DS4_1                          ( 0x2UL << GPIO_DS0_DS4_Pos )
#define GPIO_DS0_DS4_2                          ( 0x4UL << GPIO_DS0_DS4_Pos )
#define GPIO_DS0_DS4_3                          ( 0x8UL << GPIO_DS0_DS4_Pos )

#define GPIO_DS0_DS3_Pos                        ( 12U )
#define GPIO_DS0_DS3_Msk                        ( 0xFUL << GPIO_DS0_DS3_Pos )
#define GPIO_DS0_DS3                            ( GPIO_DS0_DS3_Msk )
#define GPIO_DS0_DS3_0                          ( 0x1UL << GPIO_DS0_DS3_Pos )
#define GPIO_DS0_DS3_1                          ( 0x2UL << GPIO_DS0_DS3_Pos )
#define GPIO_DS0_DS3_2                          ( 0x4UL << GPIO_DS0_DS3_Pos )
#define GPIO_DS0_DS3_3                          ( 0x8UL << GPIO_DS0_DS3_Pos )

#define GPIO_DS0_DS2_Pos                        ( 8U )
#define GPIO_DS0_DS2_Msk                        ( 0xFUL << GPIO_DS0_DS2_Pos )
#define GPIO_DS0_DS2                            ( GPIO_DS0_DS2_Msk )
#define GPIO_DS0_DS2_0                          ( 0x1UL << GPIO_DS0_DS2_Pos )
#define GPIO_DS0_DS2_1                          ( 0x2UL << GPIO_DS0_DS2_Pos )
#define GPIO_DS0_DS2_2                          ( 0x4UL << GPIO_DS0_DS2_Pos )
#define GPIO_DS0_DS2_3                          ( 0x8UL << GPIO_DS0_DS2_Pos )

#define GPIO_DS0_DS1_Pos                        ( 4U )
#define GPIO_DS0_DS1_Msk                        ( 0xFUL << GPIO_DS0_DS1_Pos )
#define GPIO_DS0_DS1                            ( GPIO_DS0_DS1_Msk )
#define GPIO_DS0_DS1_0                          ( 0x1UL << GPIO_DS0_DS1_Pos )
#define GPIO_DS0_DS1_1                          ( 0x2UL << GPIO_DS0_DS1_Pos )
#define GPIO_DS0_DS1_2                          ( 0x4UL << GPIO_DS0_DS1_Pos )
#define GPIO_DS0_DS1_3                          ( 0x8UL << GPIO_DS0_DS1_Pos )

#define GPIO_DS0_DS0_Pos                        ( 0U )
#define GPIO_DS0_DS0_Msk                        ( 0xFUL << GPIO_DS0_DS0_Pos )
#define GPIO_DS0_DS0                            ( GPIO_DS0_DS0_Msk )
#define GPIO_DS0_DS0_0                          ( 0x1UL << GPIO_DS0_DS0_Pos )
#define GPIO_DS0_DS0_1                          ( 0x2UL << GPIO_DS0_DS0_Pos )
#define GPIO_DS0_DS0_2                          ( 0x4UL << GPIO_DS0_DS0_Pos )
#define GPIO_DS0_DS0_3                          ( 0x8UL << GPIO_DS0_DS0_Pos )


/***************  Bits definition for GPIO_DS1 register  *********************/

#define GPIO_DS1_DS15_Pos                       ( 28U )
#define GPIO_DS1_DS15_Msk                       ( 0xFUL << GPIO_DS1_DS15_Pos )
#define GPIO_DS1_DS15                           ( GPIO_DS1_DS15_Msk )
#define GPIO_DS1_DS15_0                         ( 0x1UL << GPIO_DS1_DS15_Pos )
#define GPIO_DS1_DS15_1                         ( 0x2UL << GPIO_DS1_DS15_Pos )
#define GPIO_DS1_DS15_2                         ( 0x4UL << GPIO_DS1_DS15_Pos )
#define GPIO_DS1_DS15_3                         ( 0x8UL << GPIO_DS1_DS15_Pos )

#define GPIO_DS1_DS14_Pos                       ( 24U )
#define GPIO_DS1_DS14_Msk                       ( 0xFUL << GPIO_DS1_DS14_Pos )
#define GPIO_DS1_DS14                           ( GPIO_DS1_DS14_Msk )
#define GPIO_DS1_DS14_0                         ( 0x1UL << GPIO_DS1_DS14_Pos )
#define GPIO_DS1_DS14_1                         ( 0x2UL << GPIO_DS1_DS14_Pos )
#define GPIO_DS1_DS14_2                         ( 0x4UL << GPIO_DS1_DS14_Pos )
#define GPIO_DS1_DS14_3                         ( 0x8UL << GPIO_DS1_DS14_Pos )

#define GPIO_DS1_DS13_Pos                       ( 20U )
#define GPIO_DS1_DS13_Msk                       ( 0xFUL << GPIO_DS1_DS13_Pos )
#define GPIO_DS1_DS13                           ( GPIO_DS1_DS13_Msk )
#define GPIO_DS1_DS13_0                         ( 0x1UL << GPIO_DS1_DS13_Pos )
#define GPIO_DS1_DS13_1                         ( 0x2UL << GPIO_DS1_DS13_Pos )
#define GPIO_DS1_DS13_2                         ( 0x4UL << GPIO_DS1_DS13_Pos )
#define GPIO_DS1_DS13_3                         ( 0x8UL << GPIO_DS1_DS13_Pos )

#define GPIO_DS1_DS12_Pos                       ( 16U )
#define GPIO_DS1_DS12_Msk                       ( 0xFUL << GPIO_DS1_DS12_Pos )
#define GPIO_DS1_DS12                           ( GPIO_DS1_DS12_Msk )
#define GPIO_DS1_DS12_0                         ( 0x1UL << GPIO_DS1_DS12_Pos )
#define GPIO_DS1_DS12_1                         ( 0x2UL << GPIO_DS1_DS12_Pos )
#define GPIO_DS1_DS12_2                         ( 0x4UL << GPIO_DS1_DS12_Pos )
#define GPIO_DS1_DS12_3                         ( 0x8UL << GPIO_DS1_DS12_Pos )

#define GPIO_DS1_DS11_Pos                       ( 12U )
#define GPIO_DS1_DS11_Msk                       ( 0xFUL << GPIO_DS1_DS11_Pos )
#define GPIO_DS1_DS11                           ( GPIO_DS1_DS11_Msk )
#define GPIO_DS1_DS11_0                         ( 0x1UL << GPIO_DS1_DS11_Pos )
#define GPIO_DS1_DS11_1                         ( 0x2UL << GPIO_DS1_DS11_Pos )
#define GPIO_DS1_DS11_2                         ( 0x4UL << GPIO_DS1_DS11_Pos )
#define GPIO_DS1_DS11_3                         ( 0x8UL << GPIO_DS1_DS11_Pos )

#define GPIO_DS1_DS10_Pos                       ( 8U )
#define GPIO_DS1_DS10_Msk                       ( 0xFUL << GPIO_DS1_DS10_Pos )
#define GPIO_DS1_DS10                           ( GPIO_DS1_DS10_Msk )
#define GPIO_DS1_DS10_0                         ( 0x1UL << GPIO_DS1_DS10_Pos )
#define GPIO_DS1_DS10_1                         ( 0x2UL << GPIO_DS1_DS10_Pos )
#define GPIO_DS1_DS10_2                         ( 0x4UL << GPIO_DS1_DS10_Pos )
#define GPIO_DS1_DS10_3                         ( 0x8UL << GPIO_DS1_DS10_Pos )

#define GPIO_DS1_DS9_Pos                        ( 4U )
#define GPIO_DS1_DS9_Msk                        ( 0xFUL << GPIO_DS1_DS9_Pos )
#define GPIO_DS1_DS9                            ( GPIO_DS1_DS9_Msk )
#define GPIO_DS1_DS9_0                          ( 0x1UL << GPIO_DS1_DS9_Pos )
#define GPIO_DS1_DS9_1                          ( 0x2UL << GPIO_DS1_DS9_Pos )
#define GPIO_DS1_DS9_2                          ( 0x4UL << GPIO_DS1_DS9_Pos )
#define GPIO_DS1_DS9_3                          ( 0x8UL << GPIO_DS1_DS9_Pos )

#define GPIO_DS1_DS8_Pos                        ( 0U )
#define GPIO_DS1_DS8_Msk                        ( 0xFUL << GPIO_DS1_DS8_Pos )
#define GPIO_DS1_DS8                            ( GPIO_DS1_DS8_Msk )
#define GPIO_DS1_DS8_0                          ( 0x1UL << GPIO_DS1_DS8_Pos )
#define GPIO_DS1_DS8_1                          ( 0x2UL << GPIO_DS1_DS8_Pos )
#define GPIO_DS1_DS8_2                          ( 0x4UL << GPIO_DS1_DS8_Pos )
#define GPIO_DS1_DS8_3                          ( 0x8UL << GPIO_DS1_DS8_Pos )


/***************  Bits definition for GPIO_SMIT register  ********************/

#define GPIO_SMIT_SMTEN15_Pos                   ( 15U )
#define GPIO_SMIT_SMTEN15_Msk                   ( 0x1UL << GPIO_SMIT_SMTEN15_Pos )
#define GPIO_SMIT_SMTEN15                       ( GPIO_SMIT_SMTEN15_Msk )

#define GPIO_SMIT_SMTEN14_Pos                   ( 14U )
#define GPIO_SMIT_SMTEN14_Msk                   ( 0x1UL << GPIO_SMIT_SMTEN14_Pos )
#define GPIO_SMIT_SMTEN14                       ( GPIO_SMIT_SMTEN14_Msk )

#define GPIO_SMIT_SMTEN13_Pos                   ( 13U )
#define GPIO_SMIT_SMTEN13_Msk                   ( 0x1UL << GPIO_SMIT_SMTEN13_Pos )
#define GPIO_SMIT_SMTEN13                       ( GPIO_SMIT_SMTEN13_Msk )

#define GPIO_SMIT_SMTEN12_Pos                   ( 12U )
#define GPIO_SMIT_SMTEN12_Msk                   ( 0x1UL << GPIO_SMIT_SMTEN12_Pos )
#define GPIO_SMIT_SMTEN12                       ( GPIO_SMIT_SMTEN12_Msk )

#define GPIO_SMIT_SMTEN11_Pos                   ( 11U )
#define GPIO_SMIT_SMTEN11_Msk                   ( 0x1UL << GPIO_SMIT_SMTEN11_Pos )
#define GPIO_SMIT_SMTEN11                       ( GPIO_SMIT_SMTEN11_Msk )

#define GPIO_SMIT_SMTEN10_Pos                   ( 10U )
#define GPIO_SMIT_SMTEN10_Msk                   ( 0x1UL << GPIO_SMIT_SMTEN10_Pos )
#define GPIO_SMIT_SMTEN10                       ( GPIO_SMIT_SMTEN10_Msk )

#define GPIO_SMIT_SMTEN9_Pos                    ( 9U )
#define GPIO_SMIT_SMTEN9_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN9_Pos )
#define GPIO_SMIT_SMTEN9                        ( GPIO_SMIT_SMTEN9_Msk )

#define GPIO_SMIT_SMTEN8_Pos                    ( 8U )
#define GPIO_SMIT_SMTEN8_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN8_Pos )
#define GPIO_SMIT_SMTEN8                        ( GPIO_SMIT_SMTEN8_Msk )

#define GPIO_SMIT_SMTEN7_Pos                    ( 7U )
#define GPIO_SMIT_SMTEN7_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN7_Pos )
#define GPIO_SMIT_SMTEN7                        ( GPIO_SMIT_SMTEN7_Msk )

#define GPIO_SMIT_SMTEN6_Pos                    ( 6U )
#define GPIO_SMIT_SMTEN6_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN6_Pos )
#define GPIO_SMIT_SMTEN6                        ( GPIO_SMIT_SMTEN6_Msk )

#define GPIO_SMIT_SMTEN5_Pos                    ( 5U )
#define GPIO_SMIT_SMTEN5_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN5_Pos )
#define GPIO_SMIT_SMTEN5                        ( GPIO_SMIT_SMTEN5_Msk )

#define GPIO_SMIT_SMTEN4_Pos                    ( 4U )
#define GPIO_SMIT_SMTEN4_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN4_Pos )
#define GPIO_SMIT_SMTEN4                        ( GPIO_SMIT_SMTEN4_Msk )

#define GPIO_SMIT_SMTEN3_Pos                    ( 3U )
#define GPIO_SMIT_SMTEN3_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN3_Pos )
#define GPIO_SMIT_SMTEN3                        ( GPIO_SMIT_SMTEN3_Msk )

#define GPIO_SMIT_SMTEN2_Pos                    ( 2U )
#define GPIO_SMIT_SMTEN2_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN2_Pos )
#define GPIO_SMIT_SMTEN2                        ( GPIO_SMIT_SMTEN2_Msk )

#define GPIO_SMIT_SMTEN1_Pos                    ( 1U )
#define GPIO_SMIT_SMTEN1_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN1_Pos )
#define GPIO_SMIT_SMTEN1                        ( GPIO_SMIT_SMTEN1_Msk )

#define GPIO_SMIT_SMTEN0_Pos                    ( 0U )
#define GPIO_SMIT_SMTEN0_Msk                    ( 0x1UL << GPIO_SMIT_SMTEN0_Pos )
#define GPIO_SMIT_SMTEN0                        ( GPIO_SMIT_SMTEN0_Msk )


/***************  Bits definition for GPIO_LOCK register  ********************/

#define GPIO_LOCK_LOCKKEY_Pos                   ( 16U )
#define GPIO_LOCK_LOCKKEY_Msk                   ( 0x1UL << GPIO_LOCK_LOCKKEY_Pos )
#define GPIO_LOCK_LOCKKEY                       ( GPIO_LOCK_LOCKKEY_Msk )

#define GPIO_LOCK_LOCKEN15_Pos                  ( 15U )
#define GPIO_LOCK_LOCKEN15_Msk                  ( 0x1UL << GPIO_LOCK_LOCKEN15_Pos )
#define GPIO_LOCK_LOCKEN15                      ( GPIO_LOCK_LOCKEN15_Msk )

#define GPIO_LOCK_LOCKEN14_Pos                  ( 14U )
#define GPIO_LOCK_LOCKEN14_Msk                  ( 0x1UL << GPIO_LOCK_LOCKEN14_Pos )
#define GPIO_LOCK_LOCKEN14                      ( GPIO_LOCK_LOCKEN14_Msk )

#define GPIO_LOCK_LOCKEN13_Pos                  ( 13U )
#define GPIO_LOCK_LOCKEN13_Msk                  ( 0x1UL << GPIO_LOCK_LOCKEN13_Pos )
#define GPIO_LOCK_LOCKEN13                      ( GPIO_LOCK_LOCKEN13_Msk )

#define GPIO_LOCK_LOCKEN12_Pos                  ( 12U )
#define GPIO_LOCK_LOCKEN12_Msk                  ( 0x1UL << GPIO_LOCK_LOCKEN12_Pos )
#define GPIO_LOCK_LOCKEN12                      ( GPIO_LOCK_LOCKEN12_Msk )

#define GPIO_LOCK_LOCKEN11_Pos                  ( 11U )
#define GPIO_LOCK_LOCKEN11_Msk                  ( 0x1UL << GPIO_LOCK_LOCKEN11_Pos )
#define GPIO_LOCK_LOCKEN11                      ( GPIO_LOCK_LOCKEN11_Msk )

#define GPIO_LOCK_LOCKEN10_Pos                  ( 10U )
#define GPIO_LOCK_LOCKEN10_Msk                  ( 0x1UL << GPIO_LOCK_LOCKEN10_Pos )
#define GPIO_LOCK_LOCKEN10                      ( GPIO_LOCK_LOCKEN10_Msk )

#define GPIO_LOCK_LOCKEN9_Pos                   ( 9U )
#define GPIO_LOCK_LOCKEN9_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN9_Pos )
#define GPIO_LOCK_LOCKEN9                       ( GPIO_LOCK_LOCKEN9_Msk )

#define GPIO_LOCK_LOCKEN8_Pos                   ( 8U )
#define GPIO_LOCK_LOCKEN8_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN8_Pos )
#define GPIO_LOCK_LOCKEN8                       ( GPIO_LOCK_LOCKEN8_Msk )

#define GPIO_LOCK_LOCKEN7_Pos                   ( 7U )
#define GPIO_LOCK_LOCKEN7_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN7_Pos )
#define GPIO_LOCK_LOCKEN7                       ( GPIO_LOCK_LOCKEN7_Msk )

#define GPIO_LOCK_LOCKEN6_Pos                   ( 6U )
#define GPIO_LOCK_LOCKEN6_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN6_Pos )
#define GPIO_LOCK_LOCKEN6                       ( GPIO_LOCK_LOCKEN6_Msk )

#define GPIO_LOCK_LOCKEN5_Pos                   ( 5U )
#define GPIO_LOCK_LOCKEN5_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN5_Pos )
#define GPIO_LOCK_LOCKEN5                       ( GPIO_LOCK_LOCKEN5_Msk )

#define GPIO_LOCK_LOCKEN4_Pos                   ( 4U )
#define GPIO_LOCK_LOCKEN4_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN4_Pos )
#define GPIO_LOCK_LOCKEN4                       ( GPIO_LOCK_LOCKEN4_Msk )

#define GPIO_LOCK_LOCKEN3_Pos                   ( 3U )
#define GPIO_LOCK_LOCKEN3_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN3_Pos )
#define GPIO_LOCK_LOCKEN3                       ( GPIO_LOCK_LOCKEN3_Msk )

#define GPIO_LOCK_LOCKEN2_Pos                   ( 2U )
#define GPIO_LOCK_LOCKEN2_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN2_Pos )
#define GPIO_LOCK_LOCKEN2                       ( GPIO_LOCK_LOCKEN2_Msk )

#define GPIO_LOCK_LOCKEN1_Pos                   ( 1U )
#define GPIO_LOCK_LOCKEN1_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN1_Pos )
#define GPIO_LOCK_LOCKEN1                       ( GPIO_LOCK_LOCKEN1_Msk )

#define GPIO_LOCK_LOCKEN0_Pos                   ( 0U )
#define GPIO_LOCK_LOCKEN0_Msk                   ( 0x1UL << GPIO_LOCK_LOCKEN0_Pos )
#define GPIO_LOCK_LOCKEN0                       ( GPIO_LOCK_LOCKEN0_Msk )


/***************  Bits definition for GPIO_AIEN register  ********************/

#define GPIO_AIEN_AIEN15_Pos                    ( 15U )
#define GPIO_AIEN_AIEN15_Msk                    ( 0x1UL << GPIO_AIEN_AIEN15_Pos )
#define GPIO_AIEN_AIEN15                        ( GPIO_AIEN_AIEN15_Msk )

#define GPIO_AIEN_AIEN14_Pos                    ( 14U )
#define GPIO_AIEN_AIEN14_Msk                    ( 0x1UL << GPIO_AIEN_AIEN14_Pos )
#define GPIO_AIEN_AIEN14                        ( GPIO_AIEN_AIEN14_Msk )

#define GPIO_AIEN_AIEN13_Pos                    ( 13U )
#define GPIO_AIEN_AIEN13_Msk                    ( 0x1UL << GPIO_AIEN_AIEN13_Pos )
#define GPIO_AIEN_AIEN13                        ( GPIO_AIEN_AIEN13_Msk )

#define GPIO_AIEN_AIEN12_Pos                    ( 12U )
#define GPIO_AIEN_AIEN12_Msk                    ( 0x1UL << GPIO_AIEN_AIEN12_Pos )
#define GPIO_AIEN_AIEN12                        ( GPIO_AIEN_AIEN12_Msk )

#define GPIO_AIEN_AIEN11_Pos                    ( 11U )
#define GPIO_AIEN_AIEN11_Msk                    ( 0x1UL << GPIO_AIEN_AIEN11_Pos )
#define GPIO_AIEN_AIEN11                        ( GPIO_AIEN_AIEN11_Msk )

#define GPIO_AIEN_AIEN10_Pos                    ( 10U )
#define GPIO_AIEN_AIEN10_Msk                    ( 0x1UL << GPIO_AIEN_AIEN10_Pos )
#define GPIO_AIEN_AIEN10                        ( GPIO_AIEN_AIEN10_Msk )

#define GPIO_AIEN_AIEN9_Pos                     ( 9U )
#define GPIO_AIEN_AIEN9_Msk                     ( 0x1UL << GPIO_AIEN_AIEN9_Pos )
#define GPIO_AIEN_AIEN9                         ( GPIO_AIEN_AIEN9_Msk )

#define GPIO_AIEN_AIEN8_Pos                     ( 8U )
#define GPIO_AIEN_AIEN8_Msk                     ( 0x1UL << GPIO_AIEN_AIEN8_Pos )
#define GPIO_AIEN_AIEN8                         ( GPIO_AIEN_AIEN8_Msk )

#define GPIO_AIEN_AIEN7_Pos                     ( 7U )
#define GPIO_AIEN_AIEN7_Msk                     ( 0x1UL << GPIO_AIEN_AIEN7_Pos )
#define GPIO_AIEN_AIEN7                         ( GPIO_AIEN_AIEN7_Msk )

#define GPIO_AIEN_AIEN6_Pos                     ( 6U )
#define GPIO_AIEN_AIEN6_Msk                     ( 0x1UL << GPIO_AIEN_AIEN6_Pos )
#define GPIO_AIEN_AIEN6                         ( GPIO_AIEN_AIEN6_Msk )

#define GPIO_AIEN_AIEN5_Pos                     ( 5U )
#define GPIO_AIEN_AIEN5_Msk                     ( 0x1UL << GPIO_AIEN_AIEN5_Pos )
#define GPIO_AIEN_AIEN5                         ( GPIO_AIEN_AIEN5_Msk )

#define GPIO_AIEN_AIEN4_Pos                     ( 4U )
#define GPIO_AIEN_AIEN4_Msk                     ( 0x1UL << GPIO_AIEN_AIEN4_Pos )
#define GPIO_AIEN_AIEN4                         ( GPIO_AIEN_AIEN4_Msk )

#define GPIO_AIEN_AIEN3_Pos                     ( 3U )
#define GPIO_AIEN_AIEN3_Msk                     ( 0x1UL << GPIO_AIEN_AIEN3_Pos )
#define GPIO_AIEN_AIEN3                         ( GPIO_AIEN_AIEN3_Msk )

#define GPIO_AIEN_AIEN2_Pos                     ( 2U )
#define GPIO_AIEN_AIEN2_Msk                     ( 0x1UL << GPIO_AIEN_AIEN2_Pos )
#define GPIO_AIEN_AIEN2                         ( GPIO_AIEN_AIEN2_Msk )

#define GPIO_AIEN_AIEN1_Pos                     ( 1U )
#define GPIO_AIEN_AIEN1_Msk                     ( 0x1UL << GPIO_AIEN_AIEN1_Pos )
#define GPIO_AIEN_AIEN1                         ( GPIO_AIEN_AIEN1_Msk )

#define GPIO_AIEN_AIEN0_Pos                     ( 0U )
#define GPIO_AIEN_AIEN0_Msk                     ( 0x1UL << GPIO_AIEN_AIEN0_Pos )
#define GPIO_AIEN_AIEN0                         ( GPIO_AIEN_AIEN0_Msk )

/***************  Bits definition for EXTI_IENR register  ********************/

#define EXTI_IENR_INTEN26_Pos                   ( 26U )
#define EXTI_IENR_INTEN26_Msk                   ( 0x1UL << EXTI_IENR_INTEN26_Pos )
#define EXTI_IENR_INTEN26                       ( EXTI_IENR_INTEN26_Msk )

#define EXTI_IENR_INTEN25_Pos                   ( 25U )
#define EXTI_IENR_INTEN25_Msk                   ( 0x1UL << EXTI_IENR_INTEN25_Pos )
#define EXTI_IENR_INTEN25                       ( EXTI_IENR_INTEN25_Msk )

#define EXTI_IENR_INTEN24_Pos                   ( 24U )
#define EXTI_IENR_INTEN24_Msk                   ( 0x1UL << EXTI_IENR_INTEN24_Pos )
#define EXTI_IENR_INTEN24                       ( EXTI_IENR_INTEN24_Msk )

#define EXTI_IENR_INTEN23_Pos                   ( 23U )
#define EXTI_IENR_INTEN23_Msk                   ( 0x1UL << EXTI_IENR_INTEN23_Pos )
#define EXTI_IENR_INTEN23                       ( EXTI_IENR_INTEN23_Msk )

#define EXTI_IENR_INTEN22_Pos                   ( 22U )
#define EXTI_IENR_INTEN22_Msk                   ( 0x1UL << EXTI_IENR_INTEN22_Pos )
#define EXTI_IENR_INTEN22                       ( EXTI_IENR_INTEN22_Msk )

#define EXTI_IENR_INTEN21_Pos                   ( 21U )
#define EXTI_IENR_INTEN21_Msk                   ( 0x1UL << EXTI_IENR_INTEN21_Pos )
#define EXTI_IENR_INTEN21                       ( EXTI_IENR_INTEN21_Msk )

#define EXTI_IENR_INTEN20_Pos                   ( 20U )
#define EXTI_IENR_INTEN20_Msk                   ( 0x1UL << EXTI_IENR_INTEN20_Pos )
#define EXTI_IENR_INTEN20                       ( EXTI_IENR_INTEN20_Msk )

#define EXTI_IENR_INTEN19_Pos                   ( 19U )
#define EXTI_IENR_INTEN19_Msk                   ( 0x1UL << EXTI_IENR_INTEN19_Pos )
#define EXTI_IENR_INTEN19                       ( EXTI_IENR_INTEN19_Msk )

#define EXTI_IENR_INTEN18_Pos                   ( 18U )
#define EXTI_IENR_INTEN18_Msk                   ( 0x1UL << EXTI_IENR_INTEN18_Pos )
#define EXTI_IENR_INTEN18                       ( EXTI_IENR_INTEN18_Msk )

#define EXTI_IENR_INTEN17_Pos                   ( 17U )
#define EXTI_IENR_INTEN17_Msk                   ( 0x1UL << EXTI_IENR_INTEN17_Pos )
#define EXTI_IENR_INTEN17                       ( EXTI_IENR_INTEN17_Msk )

#define EXTI_IENR_INTEN16_Pos                   ( 16U )
#define EXTI_IENR_INTEN16_Msk                   ( 0x1UL << EXTI_IENR_INTEN16_Pos )
#define EXTI_IENR_INTEN16                       ( EXTI_IENR_INTEN16_Msk )

#define EXTI_IENR_INTEN15_Pos                   ( 15U )
#define EXTI_IENR_INTEN15_Msk                   ( 0x1UL << EXTI_IENR_INTEN15_Pos )
#define EXTI_IENR_INTEN15                       ( EXTI_IENR_INTEN15_Msk )

#define EXTI_IENR_INTEN14_Pos                   ( 14U )
#define EXTI_IENR_INTEN14_Msk                   ( 0x1UL << EXTI_IENR_INTEN14_Pos )
#define EXTI_IENR_INTEN14                       ( EXTI_IENR_INTEN14_Msk )

#define EXTI_IENR_INTEN13_Pos                   ( 13U )
#define EXTI_IENR_INTEN13_Msk                   ( 0x1UL << EXTI_IENR_INTEN13_Pos )
#define EXTI_IENR_INTEN13                       ( EXTI_IENR_INTEN13_Msk )

#define EXTI_IENR_INTEN12_Pos                   ( 12U )
#define EXTI_IENR_INTEN12_Msk                   ( 0x1UL << EXTI_IENR_INTEN12_Pos )
#define EXTI_IENR_INTEN12                       ( EXTI_IENR_INTEN12_Msk )

#define EXTI_IENR_INTEN11_Pos                   ( 11U )
#define EXTI_IENR_INTEN11_Msk                   ( 0x1UL << EXTI_IENR_INTEN11_Pos )
#define EXTI_IENR_INTEN11                       ( EXTI_IENR_INTEN11_Msk )

#define EXTI_IENR_INTEN10_Pos                   ( 10U )
#define EXTI_IENR_INTEN10_Msk                   ( 0x1UL << EXTI_IENR_INTEN10_Pos )
#define EXTI_IENR_INTEN10                       ( EXTI_IENR_INTEN10_Msk )

#define EXTI_IENR_INTEN9_Pos                    ( 9U )
#define EXTI_IENR_INTEN9_Msk                    ( 0x1UL << EXTI_IENR_INTEN9_Pos )
#define EXTI_IENR_INTEN9                        ( EXTI_IENR_INTEN9_Msk )

#define EXTI_IENR_INTEN8_Pos                    ( 8U )
#define EXTI_IENR_INTEN8_Msk                    ( 0x1UL << EXTI_IENR_INTEN8_Pos )
#define EXTI_IENR_INTEN8                        ( EXTI_IENR_INTEN8_Msk )

#define EXTI_IENR_INTEN7_Pos                    ( 7U )
#define EXTI_IENR_INTEN7_Msk                    ( 0x1UL << EXTI_IENR_INTEN7_Pos )
#define EXTI_IENR_INTEN7                        ( EXTI_IENR_INTEN7_Msk )

#define EXTI_IENR_INTEN6_Pos                    ( 6U )
#define EXTI_IENR_INTEN6_Msk                    ( 0x1UL << EXTI_IENR_INTEN6_Pos )
#define EXTI_IENR_INTEN6                        ( EXTI_IENR_INTEN6_Msk )

#define EXTI_IENR_INTEN5_Pos                    ( 5U )
#define EXTI_IENR_INTEN5_Msk                    ( 0x1UL << EXTI_IENR_INTEN5_Pos )
#define EXTI_IENR_INTEN5                        ( EXTI_IENR_INTEN5_Msk )

#define EXTI_IENR_INTEN4_Pos                    ( 4U )
#define EXTI_IENR_INTEN4_Msk                    ( 0x1UL << EXTI_IENR_INTEN4_Pos )
#define EXTI_IENR_INTEN4                        ( EXTI_IENR_INTEN4_Msk )

#define EXTI_IENR_INTEN3_Pos                    ( 3U )
#define EXTI_IENR_INTEN3_Msk                    ( 0x1UL << EXTI_IENR_INTEN3_Pos )
#define EXTI_IENR_INTEN3                        ( EXTI_IENR_INTEN3_Msk )

#define EXTI_IENR_INTEN2_Pos                    ( 2U )
#define EXTI_IENR_INTEN2_Msk                    ( 0x1UL << EXTI_IENR_INTEN2_Pos )
#define EXTI_IENR_INTEN2                        ( EXTI_IENR_INTEN2_Msk )

#define EXTI_IENR_INTEN1_Pos                    ( 1U )
#define EXTI_IENR_INTEN1_Msk                    ( 0x1UL << EXTI_IENR_INTEN1_Pos )
#define EXTI_IENR_INTEN1                        ( EXTI_IENR_INTEN1_Msk )

#define EXTI_IENR_INTEN0_Pos                    ( 0U )
#define EXTI_IENR_INTEN0_Msk                    ( 0x1UL << EXTI_IENR_INTEN0_Pos )
#define EXTI_IENR_INTEN0                        ( EXTI_IENR_INTEN0_Msk )


/***************  Bits definition for EXTI_EENR register  ********************/

#define EXTI_EENR_EVEN26_Pos                    ( 26U )
#define EXTI_EENR_EVEN26_Msk                    ( 0x1UL << EXTI_EENR_EVEN26_Pos )
#define EXTI_EENR_EVEN26                        ( EXTI_EENR_EVEN26_Msk )

#define EXTI_EENR_EVEN25_Pos                    ( 25U )
#define EXTI_EENR_EVEN25_Msk                    ( 0x1UL << EXTI_EENR_EVEN25_Pos )
#define EXTI_EENR_EVEN25                        ( EXTI_EENR_EVEN25_Msk )

#define EXTI_EENR_EVEN24_Pos                    ( 24U )
#define EXTI_EENR_EVEN24_Msk                    ( 0x1UL << EXTI_EENR_EVEN24_Pos )
#define EXTI_EENR_EVEN24                        ( EXTI_EENR_EVEN24_Msk )

#define EXTI_EENR_EVEN23_Pos                    ( 23U )
#define EXTI_EENR_EVEN23_Msk                    ( 0x1UL << EXTI_EENR_EVEN23_Pos )
#define EXTI_EENR_EVEN23                        ( EXTI_EENR_EVEN23_Msk )

#define EXTI_EENR_EVEN22_Pos                    ( 22U )
#define EXTI_EENR_EVEN22_Msk                    ( 0x1UL << EXTI_EENR_EVEN22_Pos )
#define EXTI_EENR_EVEN22                        ( EXTI_EENR_EVEN22_Msk )

#define EXTI_EENR_EVEN21_Pos                    ( 21U )
#define EXTI_EENR_EVEN21_Msk                    ( 0x1UL << EXTI_EENR_EVEN21_Pos )
#define EXTI_EENR_EVEN21                        ( EXTI_EENR_EVEN21_Msk )

#define EXTI_EENR_EVEN20_Pos                    ( 20U )
#define EXTI_EENR_EVEN20_Msk                    ( 0x1UL << EXTI_EENR_EVEN20_Pos )
#define EXTI_EENR_EVEN20                        ( EXTI_EENR_EVEN20_Msk )

#define EXTI_EENR_EVEN19_Pos                    ( 19U )
#define EXTI_EENR_EVEN19_Msk                    ( 0x1UL << EXTI_EENR_EVEN19_Pos )
#define EXTI_EENR_EVEN19                        ( EXTI_EENR_EVEN19_Msk )

#define EXTI_EENR_EVEN18_Pos                    ( 18U )
#define EXTI_EENR_EVEN18_Msk                    ( 0x1UL << EXTI_EENR_EVEN18_Pos )
#define EXTI_EENR_EVEN18                        ( EXTI_EENR_EVEN18_Msk )

#define EXTI_EENR_EVEN17_Pos                    ( 17U )
#define EXTI_EENR_EVEN17_Msk                    ( 0x1UL << EXTI_EENR_EVEN17_Pos )
#define EXTI_EENR_EVEN17                        ( EXTI_EENR_EVEN17_Msk )

#define EXTI_EENR_EVEN16_Pos                    ( 16U )
#define EXTI_EENR_EVEN16_Msk                    ( 0x1UL << EXTI_EENR_EVEN16_Pos )
#define EXTI_EENR_EVEN16                        ( EXTI_EENR_EVEN16_Msk )

#define EXTI_EENR_EVEN15_Pos                    ( 15U )
#define EXTI_EENR_EVEN15_Msk                    ( 0x1UL << EXTI_EENR_EVEN15_Pos )
#define EXTI_EENR_EVEN15                        ( EXTI_EENR_EVEN15_Msk )

#define EXTI_EENR_EVEN14_Pos                    ( 14U )
#define EXTI_EENR_EVEN14_Msk                    ( 0x1UL << EXTI_EENR_EVEN14_Pos )
#define EXTI_EENR_EVEN14                        ( EXTI_EENR_EVEN14_Msk )

#define EXTI_EENR_EVEN13_Pos                    ( 13U )
#define EXTI_EENR_EVEN13_Msk                    ( 0x1UL << EXTI_EENR_EVEN13_Pos )
#define EXTI_EENR_EVEN13                        ( EXTI_EENR_EVEN13_Msk )

#define EXTI_EENR_EVEN12_Pos                    ( 12U )
#define EXTI_EENR_EVEN12_Msk                    ( 0x1UL << EXTI_EENR_EVEN12_Pos )
#define EXTI_EENR_EVEN12                        ( EXTI_EENR_EVEN12_Msk )

#define EXTI_EENR_EVEN11_Pos                    ( 11U )
#define EXTI_EENR_EVEN11_Msk                    ( 0x1UL << EXTI_EENR_EVEN11_Pos )
#define EXTI_EENR_EVEN11                        ( EXTI_EENR_EVEN11_Msk )

#define EXTI_EENR_EVEN10_Pos                    ( 10U )
#define EXTI_EENR_EVEN10_Msk                    ( 0x1UL << EXTI_EENR_EVEN10_Pos )
#define EXTI_EENR_EVEN10                        ( EXTI_EENR_EVEN10_Msk )

#define EXTI_EENR_EVEN9_Pos                     ( 9U )
#define EXTI_EENR_EVEN9_Msk                     ( 0x1UL << EXTI_EENR_EVEN9_Pos )
#define EXTI_EENR_EVEN9                         ( EXTI_EENR_EVEN9_Msk )

#define EXTI_EENR_EVEN8_Pos                     ( 8U )
#define EXTI_EENR_EVEN8_Msk                     ( 0x1UL << EXTI_EENR_EVEN8_Pos )
#define EXTI_EENR_EVEN8                         ( EXTI_EENR_EVEN8_Msk )

#define EXTI_EENR_EVEN7_Pos                     ( 7U )
#define EXTI_EENR_EVEN7_Msk                     ( 0x1UL << EXTI_EENR_EVEN7_Pos )
#define EXTI_EENR_EVEN7                         ( EXTI_EENR_EVEN7_Msk )

#define EXTI_EENR_EVEN6_Pos                     ( 6U )
#define EXTI_EENR_EVEN6_Msk                     ( 0x1UL << EXTI_EENR_EVEN6_Pos )
#define EXTI_EENR_EVEN6                         ( EXTI_EENR_EVEN6_Msk )

#define EXTI_EENR_EVEN5_Pos                     ( 5U )
#define EXTI_EENR_EVEN5_Msk                     ( 0x1UL << EXTI_EENR_EVEN5_Pos )
#define EXTI_EENR_EVEN5                         ( EXTI_EENR_EVEN5_Msk )

#define EXTI_EENR_EVEN4_Pos                     ( 4U )
#define EXTI_EENR_EVEN4_Msk                     ( 0x1UL << EXTI_EENR_EVEN4_Pos )
#define EXTI_EENR_EVEN4                         ( EXTI_EENR_EVEN4_Msk )

#define EXTI_EENR_EVEN3_Pos                     ( 3U )
#define EXTI_EENR_EVEN3_Msk                     ( 0x1UL << EXTI_EENR_EVEN3_Pos )
#define EXTI_EENR_EVEN3                         ( EXTI_EENR_EVEN3_Msk )

#define EXTI_EENR_EVEN2_Pos                     ( 2U )
#define EXTI_EENR_EVEN2_Msk                     ( 0x1UL << EXTI_EENR_EVEN2_Pos )
#define EXTI_EENR_EVEN2                         ( EXTI_EENR_EVEN2_Msk )

#define EXTI_EENR_EVEN1_Pos                     ( 1U )
#define EXTI_EENR_EVEN1_Msk                     ( 0x1UL << EXTI_EENR_EVEN1_Pos )
#define EXTI_EENR_EVEN1                         ( EXTI_EENR_EVEN1_Msk )

#define EXTI_EENR_EVEN0_Pos                     ( 0U )
#define EXTI_EENR_EVEN0_Msk                     ( 0x1UL << EXTI_EENR_EVEN0_Pos )
#define EXTI_EENR_EVEN0                         ( EXTI_EENR_EVEN0_Msk )


/***************  Bits definition for EXTI_RTENR register  *******************/

#define EXTI_RTENR_RTEN26_Pos                   ( 26U )
#define EXTI_RTENR_RTEN26_Msk                   ( 0x1UL << EXTI_RTENR_RTEN26_Pos )
#define EXTI_RTENR_RTEN26                       ( EXTI_RTENR_RTEN26_Msk )

#define EXTI_RTENR_RTEN25_Pos                   ( 25U )
#define EXTI_RTENR_RTEN25_Msk                   ( 0x1UL << EXTI_RTENR_RTEN25_Pos )
#define EXTI_RTENR_RTEN25                       ( EXTI_RTENR_RTEN25_Msk )

#define EXTI_RTENR_RTEN24_Pos                   ( 24U )
#define EXTI_RTENR_RTEN24_Msk                   ( 0x1UL << EXTI_RTENR_RTEN24_Pos )
#define EXTI_RTENR_RTEN24                       ( EXTI_RTENR_RTEN24_Msk )

#define EXTI_RTENR_RTEN23_Pos                   ( 23U )
#define EXTI_RTENR_RTEN23_Msk                   ( 0x1UL << EXTI_RTENR_RTEN23_Pos )
#define EXTI_RTENR_RTEN23                       ( EXTI_RTENR_RTEN23_Msk )

#define EXTI_RTENR_RTEN22_Pos                   ( 22U )
#define EXTI_RTENR_RTEN22_Msk                   ( 0x1UL << EXTI_RTENR_RTEN22_Pos )
#define EXTI_RTENR_RTEN22                       ( EXTI_RTENR_RTEN22_Msk )

#define EXTI_RTENR_RTEN21_Pos                   ( 21U )
#define EXTI_RTENR_RTEN21_Msk                   ( 0x1UL << EXTI_RTENR_RTEN21_Pos )
#define EXTI_RTENR_RTEN21                       ( EXTI_RTENR_RTEN21_Msk )

#define EXTI_RTENR_RTEN20_Pos                   ( 20U )
#define EXTI_RTENR_RTEN20_Msk                   ( 0x1UL << EXTI_RTENR_RTEN20_Pos )
#define EXTI_RTENR_RTEN20                       ( EXTI_RTENR_RTEN20_Msk )

#define EXTI_RTENR_RTEN19_Pos                   ( 19U )
#define EXTI_RTENR_RTEN19_Msk                   ( 0x1UL << EXTI_RTENR_RTEN19_Pos )
#define EXTI_RTENR_RTEN19                       ( EXTI_RTENR_RTEN19_Msk )

#define EXTI_RTENR_RTEN18_Pos                   ( 18U )
#define EXTI_RTENR_RTEN18_Msk                   ( 0x1UL << EXTI_RTENR_RTEN18_Pos )
#define EXTI_RTENR_RTEN18                       ( EXTI_RTENR_RTEN18_Msk )

#define EXTI_RTENR_RTEN17_Pos                   ( 17U )
#define EXTI_RTENR_RTEN17_Msk                   ( 0x1UL << EXTI_RTENR_RTEN17_Pos )
#define EXTI_RTENR_RTEN17                       ( EXTI_RTENR_RTEN17_Msk )

#define EXTI_RTENR_RTEN16_Pos                   ( 16U )
#define EXTI_RTENR_RTEN16_Msk                   ( 0x1UL << EXTI_RTENR_RTEN16_Pos )
#define EXTI_RTENR_RTEN16                       ( EXTI_RTENR_RTEN16_Msk )

#define EXTI_RTENR_RTEN15_Pos                   ( 15U )
#define EXTI_RTENR_RTEN15_Msk                   ( 0x1UL << EXTI_RTENR_RTEN15_Pos )
#define EXTI_RTENR_RTEN15                       ( EXTI_RTENR_RTEN15_Msk )

#define EXTI_RTENR_RTEN14_Pos                   ( 14U )
#define EXTI_RTENR_RTEN14_Msk                   ( 0x1UL << EXTI_RTENR_RTEN14_Pos )
#define EXTI_RTENR_RTEN14                       ( EXTI_RTENR_RTEN14_Msk )

#define EXTI_RTENR_RTEN13_Pos                   ( 13U )
#define EXTI_RTENR_RTEN13_Msk                   ( 0x1UL << EXTI_RTENR_RTEN13_Pos )
#define EXTI_RTENR_RTEN13                       ( EXTI_RTENR_RTEN13_Msk )

#define EXTI_RTENR_RTEN12_Pos                   ( 12U )
#define EXTI_RTENR_RTEN12_Msk                   ( 0x1UL << EXTI_RTENR_RTEN12_Pos )
#define EXTI_RTENR_RTEN12                       ( EXTI_RTENR_RTEN12_Msk )

#define EXTI_RTENR_RTEN11_Pos                   ( 11U )
#define EXTI_RTENR_RTEN11_Msk                   ( 0x1UL << EXTI_RTENR_RTEN11_Pos )
#define EXTI_RTENR_RTEN11                       ( EXTI_RTENR_RTEN11_Msk )

#define EXTI_RTENR_RTEN10_Pos                   ( 10U )
#define EXTI_RTENR_RTEN10_Msk                   ( 0x1UL << EXTI_RTENR_RTEN10_Pos )
#define EXTI_RTENR_RTEN10                       ( EXTI_RTENR_RTEN10_Msk )

#define EXTI_RTENR_RTEN9_Pos                    ( 9U )
#define EXTI_RTENR_RTEN9_Msk                    ( 0x1UL << EXTI_RTENR_RTEN9_Pos )
#define EXTI_RTENR_RTEN9                        ( EXTI_RTENR_RTEN9_Msk )

#define EXTI_RTENR_RTEN8_Pos                    ( 8U )
#define EXTI_RTENR_RTEN8_Msk                    ( 0x1UL << EXTI_RTENR_RTEN8_Pos )
#define EXTI_RTENR_RTEN8                        ( EXTI_RTENR_RTEN8_Msk )

#define EXTI_RTENR_RTEN7_Pos                    ( 7U )
#define EXTI_RTENR_RTEN7_Msk                    ( 0x1UL << EXTI_RTENR_RTEN7_Pos )
#define EXTI_RTENR_RTEN7                        ( EXTI_RTENR_RTEN7_Msk )

#define EXTI_RTENR_RTEN6_Pos                    ( 6U )
#define EXTI_RTENR_RTEN6_Msk                    ( 0x1UL << EXTI_RTENR_RTEN6_Pos )
#define EXTI_RTENR_RTEN6                        ( EXTI_RTENR_RTEN6_Msk )

#define EXTI_RTENR_RTEN5_Pos                    ( 5U )
#define EXTI_RTENR_RTEN5_Msk                    ( 0x1UL << EXTI_RTENR_RTEN5_Pos )
#define EXTI_RTENR_RTEN5                        ( EXTI_RTENR_RTEN5_Msk )

#define EXTI_RTENR_RTEN4_Pos                    ( 4U )
#define EXTI_RTENR_RTEN4_Msk                    ( 0x1UL << EXTI_RTENR_RTEN4_Pos )
#define EXTI_RTENR_RTEN4                        ( EXTI_RTENR_RTEN4_Msk )

#define EXTI_RTENR_RTEN3_Pos                    ( 3U )
#define EXTI_RTENR_RTEN3_Msk                    ( 0x1UL << EXTI_RTENR_RTEN3_Pos )
#define EXTI_RTENR_RTEN3                        ( EXTI_RTENR_RTEN3_Msk )

#define EXTI_RTENR_RTEN2_Pos                    ( 2U )
#define EXTI_RTENR_RTEN2_Msk                    ( 0x1UL << EXTI_RTENR_RTEN2_Pos )
#define EXTI_RTENR_RTEN2                        ( EXTI_RTENR_RTEN2_Msk )

#define EXTI_RTENR_RTEN1_Pos                    ( 1U )
#define EXTI_RTENR_RTEN1_Msk                    ( 0x1UL << EXTI_RTENR_RTEN1_Pos )
#define EXTI_RTENR_RTEN1                        ( EXTI_RTENR_RTEN1_Msk )

#define EXTI_RTENR_RTEN0_Pos                    ( 0U )
#define EXTI_RTENR_RTEN0_Msk                    ( 0x1UL << EXTI_RTENR_RTEN0_Pos )
#define EXTI_RTENR_RTEN0                        ( EXTI_RTENR_RTEN0_Msk )


/***************  Bits definition for EXTI_FTENR register  *******************/

#define EXTI_FTENR_FTEN26_Pos                   ( 26U )
#define EXTI_FTENR_FTEN26_Msk                   ( 0x1UL << EXTI_FTENR_FTEN26_Pos )
#define EXTI_FTENR_FTEN26                       ( EXTI_FTENR_FTEN26_Msk )

#define EXTI_FTENR_FTEN25_Pos                   ( 25U )
#define EXTI_FTENR_FTEN25_Msk                   ( 0x1UL << EXTI_FTENR_FTEN25_Pos )
#define EXTI_FTENR_FTEN25                       ( EXTI_FTENR_FTEN25_Msk )

#define EXTI_FTENR_FTEN24_Pos                   ( 24U )
#define EXTI_FTENR_FTEN24_Msk                   ( 0x1UL << EXTI_FTENR_FTEN24_Pos )
#define EXTI_FTENR_FTEN24                       ( EXTI_FTENR_FTEN24_Msk )

#define EXTI_FTENR_FTEN23_Pos                   ( 23U )
#define EXTI_FTENR_FTEN23_Msk                   ( 0x1UL << EXTI_FTENR_FTEN23_Pos )
#define EXTI_FTENR_FTEN23                       ( EXTI_FTENR_FTEN23_Msk )

#define EXTI_FTENR_FTEN22_Pos                   ( 22U )
#define EXTI_FTENR_FTEN22_Msk                   ( 0x1UL << EXTI_FTENR_FTEN22_Pos )
#define EXTI_FTENR_FTEN22                       ( EXTI_FTENR_FTEN22_Msk )

#define EXTI_FTENR_FTEN21_Pos                   ( 21U )
#define EXTI_FTENR_FTEN21_Msk                   ( 0x1UL << EXTI_FTENR_FTEN21_Pos )
#define EXTI_FTENR_FTEN21                       ( EXTI_FTENR_FTEN21_Msk )

#define EXTI_FTENR_FTEN20_Pos                   ( 20U )
#define EXTI_FTENR_FTEN20_Msk                   ( 0x1UL << EXTI_FTENR_FTEN20_Pos )
#define EXTI_FTENR_FTEN20                       ( EXTI_FTENR_FTEN20_Msk )

#define EXTI_FTENR_FTEN19_Pos                   ( 19U )
#define EXTI_FTENR_FTEN19_Msk                   ( 0x1UL << EXTI_FTENR_FTEN19_Pos )
#define EXTI_FTENR_FTEN19                       ( EXTI_FTENR_FTEN19_Msk )

#define EXTI_FTENR_FTEN18_Pos                   ( 18U )
#define EXTI_FTENR_FTEN18_Msk                   ( 0x1UL << EXTI_FTENR_FTEN18_Pos )
#define EXTI_FTENR_FTEN18                       ( EXTI_FTENR_FTEN18_Msk )

#define EXTI_FTENR_FTEN17_Pos                   ( 17U )
#define EXTI_FTENR_FTEN17_Msk                   ( 0x1UL << EXTI_FTENR_FTEN17_Pos )
#define EXTI_FTENR_FTEN17                       ( EXTI_FTENR_FTEN17_Msk )

#define EXTI_FTENR_FTEN16_Pos                   ( 16U )
#define EXTI_FTENR_FTEN16_Msk                   ( 0x1UL << EXTI_FTENR_FTEN16_Pos )
#define EXTI_FTENR_FTEN16                       ( EXTI_FTENR_FTEN16_Msk )

#define EXTI_FTENR_FTEN15_Pos                   ( 15U )
#define EXTI_FTENR_FTEN15_Msk                   ( 0x1UL << EXTI_FTENR_FTEN15_Pos )
#define EXTI_FTENR_FTEN15                       ( EXTI_FTENR_FTEN15_Msk )

#define EXTI_FTENR_FTEN14_Pos                   ( 14U )
#define EXTI_FTENR_FTEN14_Msk                   ( 0x1UL << EXTI_FTENR_FTEN14_Pos )
#define EXTI_FTENR_FTEN14                       ( EXTI_FTENR_FTEN14_Msk )

#define EXTI_FTENR_FTEN13_Pos                   ( 13U )
#define EXTI_FTENR_FTEN13_Msk                   ( 0x1UL << EXTI_FTENR_FTEN13_Pos )
#define EXTI_FTENR_FTEN13                       ( EXTI_FTENR_FTEN13_Msk )

#define EXTI_FTENR_FTEN12_Pos                   ( 12U )
#define EXTI_FTENR_FTEN12_Msk                   ( 0x1UL << EXTI_FTENR_FTEN12_Pos )
#define EXTI_FTENR_FTEN12                       ( EXTI_FTENR_FTEN12_Msk )

#define EXTI_FTENR_FTEN11_Pos                   ( 11U )
#define EXTI_FTENR_FTEN11_Msk                   ( 0x1UL << EXTI_FTENR_FTEN11_Pos )
#define EXTI_FTENR_FTEN11                       ( EXTI_FTENR_FTEN11_Msk )

#define EXTI_FTENR_FTEN10_Pos                   ( 10U )
#define EXTI_FTENR_FTEN10_Msk                   ( 0x1UL << EXTI_FTENR_FTEN10_Pos )
#define EXTI_FTENR_FTEN10                       ( EXTI_FTENR_FTEN10_Msk )

#define EXTI_FTENR_FTEN9_Pos                    ( 9U )
#define EXTI_FTENR_FTEN9_Msk                    ( 0x1UL << EXTI_FTENR_FTEN9_Pos )
#define EXTI_FTENR_FTEN9                        ( EXTI_FTENR_FTEN9_Msk )

#define EXTI_FTENR_FTEN8_Pos                    ( 8U )
#define EXTI_FTENR_FTEN8_Msk                    ( 0x1UL << EXTI_FTENR_FTEN8_Pos )
#define EXTI_FTENR_FTEN8                        ( EXTI_FTENR_FTEN8_Msk )

#define EXTI_FTENR_FTEN7_Pos                    ( 7U )
#define EXTI_FTENR_FTEN7_Msk                    ( 0x1UL << EXTI_FTENR_FTEN7_Pos )
#define EXTI_FTENR_FTEN7                        ( EXTI_FTENR_FTEN7_Msk )

#define EXTI_FTENR_FTEN6_Pos                    ( 6U )
#define EXTI_FTENR_FTEN6_Msk                    ( 0x1UL << EXTI_FTENR_FTEN6_Pos )
#define EXTI_FTENR_FTEN6                        ( EXTI_FTENR_FTEN6_Msk )

#define EXTI_FTENR_FTEN5_Pos                    ( 5U )
#define EXTI_FTENR_FTEN5_Msk                    ( 0x1UL << EXTI_FTENR_FTEN5_Pos )
#define EXTI_FTENR_FTEN5                        ( EXTI_FTENR_FTEN5_Msk )

#define EXTI_FTENR_FTEN4_Pos                    ( 4U )
#define EXTI_FTENR_FTEN4_Msk                    ( 0x1UL << EXTI_FTENR_FTEN4_Pos )
#define EXTI_FTENR_FTEN4                        ( EXTI_FTENR_FTEN4_Msk )

#define EXTI_FTENR_FTEN3_Pos                    ( 3U )
#define EXTI_FTENR_FTEN3_Msk                    ( 0x1UL << EXTI_FTENR_FTEN3_Pos )
#define EXTI_FTENR_FTEN3                        ( EXTI_FTENR_FTEN3_Msk )

#define EXTI_FTENR_FTEN2_Pos                    ( 2U )
#define EXTI_FTENR_FTEN2_Msk                    ( 0x1UL << EXTI_FTENR_FTEN2_Pos )
#define EXTI_FTENR_FTEN2                        ( EXTI_FTENR_FTEN2_Msk )

#define EXTI_FTENR_FTEN1_Pos                    ( 1U )
#define EXTI_FTENR_FTEN1_Msk                    ( 0x1UL << EXTI_FTENR_FTEN1_Pos )
#define EXTI_FTENR_FTEN1                        ( EXTI_FTENR_FTEN1_Msk )

#define EXTI_FTENR_FTEN0_Pos                    ( 0U )
#define EXTI_FTENR_FTEN0_Msk                    ( 0x1UL << EXTI_FTENR_FTEN0_Pos )
#define EXTI_FTENR_FTEN0                        ( EXTI_FTENR_FTEN0_Msk )

/***************  Bits definition for EXTI_SWIER register  *******************/

#define EXTI_SWIER_SWIE26_Pos                   ( 26U )
#define EXTI_SWIER_SWIE26_Msk                   ( 0x1UL << EXTI_SWIER_SWIE26_Pos )
#define EXTI_SWIER_SWIE26                       ( EXTI_SWIER_SWIE26_Msk )

#define EXTI_SWIER_SWIE25_Pos                   ( 25U )
#define EXTI_SWIER_SWIE25_Msk                   ( 0x1UL << EXTI_SWIER_SWIE25_Pos )
#define EXTI_SWIER_SWIE25                       ( EXTI_SWIER_SWIE25_Msk )

#define EXTI_SWIER_SWIE24_Pos                   ( 24U )
#define EXTI_SWIER_SWIE24_Msk                   ( 0x1UL << EXTI_SWIER_SWIE24_Pos )
#define EXTI_SWIER_SWIE24                       ( EXTI_SWIER_SWIE24_Msk )

#define EXTI_SWIER_SWIE23_Pos                   ( 23U )
#define EXTI_SWIER_SWIE23_Msk                   ( 0x1UL << EXTI_SWIER_SWIE23_Pos )
#define EXTI_SWIER_SWIE23                       ( EXTI_SWIER_SWIE23_Msk )

#define EXTI_SWIER_SWIE22_Pos                   ( 22U )
#define EXTI_SWIER_SWIE22_Msk                   ( 0x1UL << EXTI_SWIER_SWIE22_Pos )
#define EXTI_SWIER_SWIE22                       ( EXTI_SWIER_SWIE22_Msk )

#define EXTI_SWIER_SWIE21_Pos                   ( 21U )
#define EXTI_SWIER_SWIE21_Msk                   ( 0x1UL << EXTI_SWIER_SWIE21_Pos )
#define EXTI_SWIER_SWIE21                       ( EXTI_SWIER_SWIE21_Msk )

#define EXTI_SWIER_SWIE20_Pos                   ( 20U )
#define EXTI_SWIER_SWIE20_Msk                   ( 0x1UL << EXTI_SWIER_SWIE20_Pos )
#define EXTI_SWIER_SWIE20                       ( EXTI_SWIER_SWIE20_Msk )

#define EXTI_SWIER_SWIE19_Pos                   ( 19U )
#define EXTI_SWIER_SWIE19_Msk                   ( 0x1UL << EXTI_SWIER_SWIE19_Pos )
#define EXTI_SWIER_SWIE19                       ( EXTI_SWIER_SWIE19_Msk )

#define EXTI_SWIER_SWIE18_Pos                   ( 18U )
#define EXTI_SWIER_SWIE18_Msk                   ( 0x1UL << EXTI_SWIER_SWIE18_Pos )
#define EXTI_SWIER_SWIE18                       ( EXTI_SWIER_SWIE18_Msk )

#define EXTI_SWIER_SWIE17_Pos                   ( 17U )
#define EXTI_SWIER_SWIE17_Msk                   ( 0x1UL << EXTI_SWIER_SWIE17_Pos )
#define EXTI_SWIER_SWIE17                       ( EXTI_SWIER_SWIE17_Msk )

#define EXTI_SWIER_SWIE16_Pos                   ( 16U )
#define EXTI_SWIER_SWIE16_Msk                   ( 0x1UL << EXTI_SWIER_SWIE16_Pos )
#define EXTI_SWIER_SWIE16                       ( EXTI_SWIER_SWIE16_Msk )

#define EXTI_SWIER_SWIE15_Pos                   ( 15U )
#define EXTI_SWIER_SWIE15_Msk                   ( 0x1UL << EXTI_SWIER_SWIE15_Pos )
#define EXTI_SWIER_SWIE15                       ( EXTI_SWIER_SWIE15_Msk )

#define EXTI_SWIER_SWIE14_Pos                   ( 14U )
#define EXTI_SWIER_SWIE14_Msk                   ( 0x1UL << EXTI_SWIER_SWIE14_Pos )
#define EXTI_SWIER_SWIE14                       ( EXTI_SWIER_SWIE14_Msk )

#define EXTI_SWIER_SWIE13_Pos                   ( 13U )
#define EXTI_SWIER_SWIE13_Msk                   ( 0x1UL << EXTI_SWIER_SWIE13_Pos )
#define EXTI_SWIER_SWIE13                       ( EXTI_SWIER_SWIE13_Msk )

#define EXTI_SWIER_SWIE12_Pos                   ( 12U )
#define EXTI_SWIER_SWIE12_Msk                   ( 0x1UL << EXTI_SWIER_SWIE12_Pos )
#define EXTI_SWIER_SWIE12                       ( EXTI_SWIER_SWIE12_Msk )

#define EXTI_SWIER_SWIE11_Pos                   ( 11U )
#define EXTI_SWIER_SWIE11_Msk                   ( 0x1UL << EXTI_SWIER_SWIE11_Pos )
#define EXTI_SWIER_SWIE11                       ( EXTI_SWIER_SWIE11_Msk )

#define EXTI_SWIER_SWIE10_Pos                   ( 10U )
#define EXTI_SWIER_SWIE10_Msk                   ( 0x1UL << EXTI_SWIER_SWIE10_Pos )
#define EXTI_SWIER_SWIE10                       ( EXTI_SWIER_SWIE10_Msk )

#define EXTI_SWIER_SWIE9_Pos                    ( 9U )
#define EXTI_SWIER_SWIE9_Msk                    ( 0x1UL << EXTI_SWIER_SWIE9_Pos )
#define EXTI_SWIER_SWIE9                        ( EXTI_SWIER_SWIE9_Msk )

#define EXTI_SWIER_SWIE8_Pos                    ( 8U )
#define EXTI_SWIER_SWIE8_Msk                    ( 0x1UL << EXTI_SWIER_SWIE8_Pos )
#define EXTI_SWIER_SWIE8                        ( EXTI_SWIER_SWIE8_Msk )

#define EXTI_SWIER_SWIE7_Pos                    ( 7U )
#define EXTI_SWIER_SWIE7_Msk                    ( 0x1UL << EXTI_SWIER_SWIE7_Pos )
#define EXTI_SWIER_SWIE7                        ( EXTI_SWIER_SWIE7_Msk )

#define EXTI_SWIER_SWIE6_Pos                    ( 6U )
#define EXTI_SWIER_SWIE6_Msk                    ( 0x1UL << EXTI_SWIER_SWIE6_Pos )
#define EXTI_SWIER_SWIE6                        ( EXTI_SWIER_SWIE6_Msk )

#define EXTI_SWIER_SWIE5_Pos                    ( 5U )
#define EXTI_SWIER_SWIE5_Msk                    ( 0x1UL << EXTI_SWIER_SWIE5_Pos )
#define EXTI_SWIER_SWIE5                        ( EXTI_SWIER_SWIE5_Msk )

#define EXTI_SWIER_SWIE4_Pos                    ( 4U )
#define EXTI_SWIER_SWIE4_Msk                    ( 0x1UL << EXTI_SWIER_SWIE4_Pos )
#define EXTI_SWIER_SWIE4                        ( EXTI_SWIER_SWIE4_Msk )

#define EXTI_SWIER_SWIE3_Pos                    ( 3U )
#define EXTI_SWIER_SWIE3_Msk                    ( 0x1UL << EXTI_SWIER_SWIE3_Pos )
#define EXTI_SWIER_SWIE3                        ( EXTI_SWIER_SWIE3_Msk )

#define EXTI_SWIER_SWIE2_Pos                    ( 2U )
#define EXTI_SWIER_SWIE2_Msk                    ( 0x1UL << EXTI_SWIER_SWIE2_Pos )
#define EXTI_SWIER_SWIE2                        ( EXTI_SWIER_SWIE2_Msk )

#define EXTI_SWIER_SWIE1_Pos                    ( 1U )
#define EXTI_SWIER_SWIE1_Msk                    ( 0x1UL << EXTI_SWIER_SWIE1_Pos )
#define EXTI_SWIER_SWIE1                        ( EXTI_SWIER_SWIE1_Msk )

#define EXTI_SWIER_SWIE0_Pos                    ( 0U )
#define EXTI_SWIER_SWIE0_Msk                    ( 0x1UL << EXTI_SWIER_SWIE0_Pos )
#define EXTI_SWIER_SWIE0                        ( EXTI_SWIER_SWIE0_Msk )


/***************  Bits definition for EXTI_PDR  register  ********************/

#define EXTI_PDR_PD26_Pos                      ( 26U )
#define EXTI_PDR_PD26_Msk                      ( 0x1UL << EXTI_PDR_PD26_Pos )
#define EXTI_PDR_PD26                          ( EXTI_PDR_PD26_Msk )

#define EXTI_PDR_PD25_Pos                      ( 25U )
#define EXTI_PDR_PD25_Msk                      ( 0x1UL << EXTI_PDR_PD25_Pos )
#define EXTI_PDR_PD25                          ( EXTI_PDR_PD25_Msk )

#define EXTI_PDR_PD24_Pos                      ( 24U )
#define EXTI_PDR_PD24_Msk                      ( 0x1UL << EXTI_PDR_PD24_Pos )
#define EXTI_PDR_PD24                          ( EXTI_PDR_PD24_Msk )

#define EXTI_PDR_PD23_Pos                      ( 23U )
#define EXTI_PDR_PD23_Msk                      ( 0x1UL << EXTI_PDR_PD23_Pos )
#define EXTI_PDR_PD23                          ( EXTI_PDR_PD23_Msk )

#define EXTI_PDR_PD22_Pos                      ( 22U )
#define EXTI_PDR_PD22_Msk                      ( 0x1UL << EXTI_PDR_PD22_Pos )
#define EXTI_PDR_PD22                          ( EXTI_PDR_PD22_Msk )

#define EXTI_PDR_PD21_Pos                      ( 21U )
#define EXTI_PDR_PD21_Msk                      ( 0x1UL << EXTI_PDR_PD21_Pos )
#define EXTI_PDR_PD21                          ( EXTI_PDR_PD21_Msk )

#define EXTI_PDR_PD20_Pos                      ( 20U )
#define EXTI_PDR_PD20_Msk                      ( 0x1UL << EXTI_PDR_PD20_Pos )
#define EXTI_PDR_PD20                          ( EXTI_PDR_PD20_Msk )

#define EXTI_PDR_PD19_Pos                      ( 19U )
#define EXTI_PDR_PD19_Msk                      ( 0x1UL << EXTI_PDR_PD19_Pos )
#define EXTI_PDR_PD19                          ( EXTI_PDR_PD19_Msk )

#define EXTI_PDR_PD18_Pos                      ( 18U )
#define EXTI_PDR_PD18_Msk                      ( 0x1UL << EXTI_PDR_PD18_Pos )
#define EXTI_PDR_PD18                          ( EXTI_PDR_PD18_Msk )

#define EXTI_PDR_PD17_Pos                      ( 17U )
#define EXTI_PDR_PD17_Msk                      ( 0x1UL << EXTI_PDR_PD17_Pos )
#define EXTI_PDR_PD17                          ( EXTI_PDR_PD17_Msk )

#define EXTI_PDR_PD16_Pos                      ( 16U )
#define EXTI_PDR_PD16_Msk                      ( 0x1UL << EXTI_PDR_PD16_Pos )
#define EXTI_PDR_PD16                          ( EXTI_PDR_PD16_Msk )

#define EXTI_PDR_PD15_Pos                      ( 15U )
#define EXTI_PDR_PD15_Msk                      ( 0x1UL << EXTI_PDR_PD15_Pos )
#define EXTI_PDR_PD15                          ( EXTI_PDR_PD15_Msk )

#define EXTI_PDR_PD14_Pos                      ( 14U )
#define EXTI_PDR_PD14_Msk                      ( 0x1UL << EXTI_PDR_PD14_Pos )
#define EXTI_PDR_PD14                          ( EXTI_PDR_PD14_Msk )

#define EXTI_PDR_PD13_Pos                      ( 13U )
#define EXTI_PDR_PD13_Msk                      ( 0x1UL << EXTI_PDR_PD13_Pos )
#define EXTI_PDR_PD13                          ( EXTI_PDR_PD13_Msk )

#define EXTI_PDR_PD12_Pos                      ( 12U )
#define EXTI_PDR_PD12_Msk                      ( 0x1UL << EXTI_PDR_PD12_Pos )
#define EXTI_PDR_PD12                          ( EXTI_PDR_PD12_Msk )

#define EXTI_PDR_PD11_Pos                      ( 11U )
#define EXTI_PDR_PD11_Msk                      ( 0x1UL << EXTI_PDR_PD11_Pos )
#define EXTI_PDR_PD11                          ( EXTI_PDR_PD11_Msk )

#define EXTI_PDR_PD10_Pos                      ( 10U )
#define EXTI_PDR_PD10_Msk                      ( 0x1UL << EXTI_PDR_PD10_Pos )
#define EXTI_PDR_PD10                          ( EXTI_PDR_PD10_Msk )

#define EXTI_PDR_PD9_Pos                       ( 9U )
#define EXTI_PDR_PD9_Msk                       ( 0x1UL << EXTI_PDR_PD9_Pos )
#define EXTI_PDR_PD9                           ( EXTI_PDR_PD9_Msk )

#define EXTI_PDR_PD8_Pos                       ( 8U )
#define EXTI_PDR_PD8_Msk                       ( 0x1UL << EXTI_PDR_PD8_Pos )
#define EXTI_PDR_PD8                           ( EXTI_PDR_PD8_Msk )

#define EXTI_PDR_PD7_Pos                       ( 7U )
#define EXTI_PDR_PD7_Msk                       ( 0x1UL << EXTI_PDR_PD7_Pos )
#define EXTI_PDR_PD7                           ( EXTI_PDR_PD7_Msk )

#define EXTI_PDR_PD6_Pos                       ( 6U )
#define EXTI_PDR_PD6_Msk                       ( 0x1UL << EXTI_PDR_PD6_Pos )
#define EXTI_PDR_PD6                           ( EXTI_PDR_PD6_Msk )

#define EXTI_PDR_PD5_Pos                       ( 5U )
#define EXTI_PDR_PD5_Msk                       ( 0x1UL << EXTI_PDR_PD5_Pos )
#define EXTI_PDR_PD5                           ( EXTI_PDR_PD5_Msk )

#define EXTI_PDR_PD4_Pos                       ( 4U )
#define EXTI_PDR_PD4_Msk                       ( 0x1UL << EXTI_PDR_PD4_Pos )
#define EXTI_PDR_PD4                           ( EXTI_PDR_PD4_Msk )

#define EXTI_PDR_PD3_Pos                       ( 3U )
#define EXTI_PDR_PD3_Msk                       ( 0x1UL << EXTI_PDR_PD3_Pos )
#define EXTI_PDR_PD3                           ( EXTI_PDR_PD3_Msk )

#define EXTI_PDR_PD2_Pos                       ( 2U )
#define EXTI_PDR_PD2_Msk                       ( 0x1UL << EXTI_PDR_PD2_Pos )
#define EXTI_PDR_PD2                           ( EXTI_PDR_PD2_Msk )

#define EXTI_PDR_PD1_Pos                       ( 1U )
#define EXTI_PDR_PD1_Msk                       ( 0x1UL << EXTI_PDR_PD1_Pos )
#define EXTI_PDR_PD1                           ( EXTI_PDR_PD1_Msk )

#define EXTI_PDR_PD0_Pos                       ( 0U )
#define EXTI_PDR_PD0_Msk                       ( 0x1UL << EXTI_PDR_PD0_Pos )
#define EXTI_PDR_PD0                           ( EXTI_PDR_PD0_Msk )


/***************  Bits definition for EXTI_CR1 register  *********************/

#define EXTI_CR1_EXTI7_Pos                      ( 28U )
#define EXTI_CR1_EXTI7_Msk                      ( 0xFUL << EXTI_CR1_EXTI7_Pos )
#define EXTI_CR1_EXTI7                          ( EXTI_CR1_EXTI7_Msk )
#define EXTI_CR1_EXTI7_0                        ( 0x1UL << EXTI_CR1_EXTI7_Pos )
#define EXTI_CR1_EXTI7_1                        ( 0x2UL << EXTI_CR1_EXTI7_Pos )
#define EXTI_CR1_EXTI7_2                        ( 0x4UL << EXTI_CR1_EXTI7_Pos )
#define EXTI_CR1_EXTI7_3                        ( 0x8UL << EXTI_CR1_EXTI7_Pos )

#define EXTI_CR1_EXTI6_Pos                      ( 24U )
#define EXTI_CR1_EXTI6_Msk                      ( 0xFUL << EXTI_CR1_EXTI6_Pos )
#define EXTI_CR1_EXTI6                          ( EXTI_CR1_EXTI6_Msk )
#define EXTI_CR1_EXTI6_0                        ( 0x1UL << EXTI_CR1_EXTI6_Pos )
#define EXTI_CR1_EXTI6_1                        ( 0x2UL << EXTI_CR1_EXTI6_Pos )
#define EXTI_CR1_EXTI6_2                        ( 0x4UL << EXTI_CR1_EXTI6_Pos )
#define EXTI_CR1_EXTI6_3                        ( 0x8UL << EXTI_CR1_EXTI6_Pos )

#define EXTI_CR1_EXTI5_Pos                      ( 20U )
#define EXTI_CR1_EXTI5_Msk                      ( 0xFUL << EXTI_CR1_EXTI5_Pos )
#define EXTI_CR1_EXTI5                          ( EXTI_CR1_EXTI5_Msk )
#define EXTI_CR1_EXTI5_0                        ( 0x1UL << EXTI_CR1_EXTI5_Pos )
#define EXTI_CR1_EXTI5_1                        ( 0x2UL << EXTI_CR1_EXTI5_Pos )
#define EXTI_CR1_EXTI5_2                        ( 0x4UL << EXTI_CR1_EXTI5_Pos )
#define EXTI_CR1_EXTI5_3                        ( 0x8UL << EXTI_CR1_EXTI5_Pos )

#define EXTI_CR1_EXTI4_Pos                      ( 16U )
#define EXTI_CR1_EXTI4_Msk                      ( 0xFUL << EXTI_CR1_EXTI4_Pos )
#define EXTI_CR1_EXTI4                          ( EXTI_CR1_EXTI4_Msk )
#define EXTI_CR1_EXTI4_0                        ( 0x1UL << EXTI_CR1_EXTI4_Pos )
#define EXTI_CR1_EXTI4_1                        ( 0x2UL << EXTI_CR1_EXTI4_Pos )
#define EXTI_CR1_EXTI4_2                        ( 0x4UL << EXTI_CR1_EXTI4_Pos )
#define EXTI_CR1_EXTI4_3                        ( 0x8UL << EXTI_CR1_EXTI4_Pos )

#define EXTI_CR1_EXTI3_Pos                      ( 12U )
#define EXTI_CR1_EXTI3_Msk                      ( 0xFUL << EXTI_CR1_EXTI3_Pos )
#define EXTI_CR1_EXTI3                          ( EXTI_CR1_EXTI3_Msk )
#define EXTI_CR1_EXTI3_0                        ( 0x1UL << EXTI_CR1_EXTI3_Pos )
#define EXTI_CR1_EXTI3_1                        ( 0x2UL << EXTI_CR1_EXTI3_Pos )
#define EXTI_CR1_EXTI3_2                        ( 0x4UL << EXTI_CR1_EXTI3_Pos )
#define EXTI_CR1_EXTI3_3                        ( 0x8UL << EXTI_CR1_EXTI3_Pos )

#define EXTI_CR1_EXTI2_Pos                      ( 8U )
#define EXTI_CR1_EXTI2_Msk                      ( 0xFUL << EXTI_CR1_EXTI2_Pos )
#define EXTI_CR1_EXTI2                          ( EXTI_CR1_EXTI2_Msk )
#define EXTI_CR1_EXTI2_0                        ( 0x1UL << EXTI_CR1_EXTI2_Pos )
#define EXTI_CR1_EXTI2_1                        ( 0x2UL << EXTI_CR1_EXTI2_Pos )
#define EXTI_CR1_EXTI2_2                        ( 0x4UL << EXTI_CR1_EXTI2_Pos )
#define EXTI_CR1_EXTI2_3                        ( 0x8UL << EXTI_CR1_EXTI2_Pos )

#define EXTI_CR1_EXTI1_Pos                      ( 4U )
#define EXTI_CR1_EXTI1_Msk                      ( 0xFUL << EXTI_CR1_EXTI1_Pos )
#define EXTI_CR1_EXTI1                          ( EXTI_CR1_EXTI1_Msk )
#define EXTI_CR1_EXTI1_0                        ( 0x1UL << EXTI_CR1_EXTI1_Pos )
#define EXTI_CR1_EXTI1_1                        ( 0x2UL << EXTI_CR1_EXTI1_Pos )
#define EXTI_CR1_EXTI1_2                        ( 0x4UL << EXTI_CR1_EXTI1_Pos )
#define EXTI_CR1_EXTI1_3                        ( 0x8UL << EXTI_CR1_EXTI1_Pos )

#define EXTI_CR1_EXTI0_Pos                      ( 0U )
#define EXTI_CR1_EXTI0_Msk                      ( 0xFUL << EXTI_CR1_EXTI0_Pos )
#define EXTI_CR1_EXTI0                          ( EXTI_CR1_EXTI0_Msk )
#define EXTI_CR1_EXTI0_0                        ( 0x1UL << EXTI_CR1_EXTI0_Pos )
#define EXTI_CR1_EXTI0_1                        ( 0x2UL << EXTI_CR1_EXTI0_Pos )
#define EXTI_CR1_EXTI0_2                        ( 0x4UL << EXTI_CR1_EXTI0_Pos )
#define EXTI_CR1_EXTI0_3                        ( 0x8UL << EXTI_CR1_EXTI0_Pos )


/***************  Bits definition for EXTI_CR2 register  *********************/

#define EXTI_CR2_EXTI15_Pos                     ( 28U )
#define EXTI_CR2_EXTI15_Msk                     ( 0xFUL << EXTI_CR2_EXTI15_Pos )
#define EXTI_CR2_EXTI15                         ( EXTI_CR2_EXTI15_Msk )
#define EXTI_CR2_EXTI15_0                       ( 0x1UL << EXTI_CR2_EXTI15_Pos )
#define EXTI_CR2_EXTI15_1                       ( 0x2UL << EXTI_CR2_EXTI15_Pos )
#define EXTI_CR2_EXTI15_2                       ( 0x4UL << EXTI_CR2_EXTI15_Pos )
#define EXTI_CR2_EXTI15_3                       ( 0x8UL << EXTI_CR2_EXTI15_Pos )

#define EXTI_CR2_EXTI14_Pos                     ( 24U )
#define EXTI_CR2_EXTI14_Msk                     ( 0xFUL << EXTI_CR2_EXTI14_Pos )
#define EXTI_CR2_EXTI14                         ( EXTI_CR2_EXTI14_Msk )
#define EXTI_CR2_EXTI14_0                       ( 0x1UL << EXTI_CR2_EXTI14_Pos )
#define EXTI_CR2_EXTI14_1                       ( 0x2UL << EXTI_CR2_EXTI14_Pos )
#define EXTI_CR2_EXTI14_2                       ( 0x4UL << EXTI_CR2_EXTI14_Pos )
#define EXTI_CR2_EXTI14_3                       ( 0x8UL << EXTI_CR2_EXTI14_Pos )

#define EXTI_CR2_EXTI13_Pos                     ( 20U )
#define EXTI_CR2_EXTI13_Msk                     ( 0xFUL << EXTI_CR2_EXTI13_Pos )
#define EXTI_CR2_EXTI13                         ( EXTI_CR2_EXTI13_Msk )
#define EXTI_CR2_EXTI13_0                       ( 0x1UL << EXTI_CR2_EXTI13_Pos )
#define EXTI_CR2_EXTI13_1                       ( 0x2UL << EXTI_CR2_EXTI13_Pos )
#define EXTI_CR2_EXTI13_2                       ( 0x4UL << EXTI_CR2_EXTI13_Pos )
#define EXTI_CR2_EXTI13_3                       ( 0x8UL << EXTI_CR2_EXTI13_Pos )

#define EXTI_CR2_EXTI12_Pos                     ( 16U )
#define EXTI_CR2_EXTI12_Msk                     ( 0xFUL << EXTI_CR2_EXTI12_Pos )
#define EXTI_CR2_EXTI12                         ( EXTI_CR2_EXTI12_Msk )
#define EXTI_CR2_EXTI12_0                       ( 0x1UL << EXTI_CR2_EXTI12_Pos )
#define EXTI_CR2_EXTI12_1                       ( 0x2UL << EXTI_CR2_EXTI12_Pos )
#define EXTI_CR2_EXTI12_2                       ( 0x4UL << EXTI_CR2_EXTI12_Pos )
#define EXTI_CR2_EXTI12_3                       ( 0x8UL << EXTI_CR2_EXTI12_Pos )

#define EXTI_CR2_EXTI11_Pos                     ( 12U )
#define EXTI_CR2_EXTI11_Msk                     ( 0xFUL << EXTI_CR2_EXTI11_Pos )
#define EXTI_CR2_EXTI11                         ( EXTI_CR2_EXTI11_Msk )
#define EXTI_CR2_EXTI11_0                       ( 0x1UL << EXTI_CR2_EXTI11_Pos )
#define EXTI_CR2_EXTI11_1                       ( 0x2UL << EXTI_CR2_EXTI11_Pos )
#define EXTI_CR2_EXTI11_2                       ( 0x4UL << EXTI_CR2_EXTI11_Pos )
#define EXTI_CR2_EXTI11_3                       ( 0x8UL << EXTI_CR2_EXTI11_Pos )

#define EXTI_CR2_EXTI10_Pos                     ( 8U )
#define EXTI_CR2_EXTI10_Msk                     ( 0xFUL << EXTI_CR2_EXTI10_Pos )
#define EXTI_CR2_EXTI10                         ( EXTI_CR2_EXTI10_Msk )
#define EXTI_CR2_EXTI10_0                       ( 0x1UL << EXTI_CR2_EXTI10_Pos )
#define EXTI_CR2_EXTI10_1                       ( 0x2UL << EXTI_CR2_EXTI10_Pos )
#define EXTI_CR2_EXTI10_2                       ( 0x4UL << EXTI_CR2_EXTI10_Pos )
#define EXTI_CR2_EXTI10_3                       ( 0x8UL << EXTI_CR2_EXTI10_Pos )

#define EXTI_CR2_EXTI9_Pos                      ( 4U )
#define EXTI_CR2_EXTI9_Msk                      ( 0xFUL << EXTI_CR2_EXTI9_Pos )
#define EXTI_CR2_EXTI9                          ( EXTI_CR2_EXTI9_Msk )
#define EXTI_CR2_EXTI9_0                        ( 0x1UL << EXTI_CR2_EXTI9_Pos )
#define EXTI_CR2_EXTI9_1                        ( 0x2UL << EXTI_CR2_EXTI9_Pos )
#define EXTI_CR2_EXTI9_2                        ( 0x4UL << EXTI_CR2_EXTI9_Pos )
#define EXTI_CR2_EXTI9_3                        ( 0x8UL << EXTI_CR2_EXTI9_Pos )

#define EXTI_CR2_EXTI8_Pos                      ( 0U )
#define EXTI_CR2_EXTI8_Msk                      ( 0xFUL << EXTI_CR2_EXTI8_Pos )
#define EXTI_CR2_EXTI8                          ( EXTI_CR2_EXTI8_Msk )
#define EXTI_CR2_EXTI8_0                        ( 0x1UL << EXTI_CR2_EXTI8_Pos )
#define EXTI_CR2_EXTI8_1                        ( 0x2UL << EXTI_CR2_EXTI8_Pos )
#define EXTI_CR2_EXTI8_2                        ( 0x4UL << EXTI_CR2_EXTI8_Pos )
#define EXTI_CR2_EXTI8_3                        ( 0x8UL << EXTI_CR2_EXTI8_Pos )

/***************  Bits definition for DMA_INTSTATUS register  ****************/

#define DMA_INTSTATUS_INT7_Pos                  ( 7U )
#define DMA_INTSTATUS_INT7_Msk                  ( 0x1UL << DMA_INTSTATUS_INT7_Pos )
#define DMA_INTSTATUS_INT7                      ( DMA_INTSTATUS_INT7_Msk )

#define DMA_INTSTATUS_INT6_Pos                  ( 6U )
#define DMA_INTSTATUS_INT6_Msk                  ( 0x1UL << DMA_INTSTATUS_INT6_Pos )
#define DMA_INTSTATUS_INT6                      ( DMA_INTSTATUS_INT6_Msk )

#define DMA_INTSTATUS_INT5_Pos                  ( 5U )
#define DMA_INTSTATUS_INT5_Msk                  ( 0x1UL << DMA_INTSTATUS_INT5_Pos )
#define DMA_INTSTATUS_INT5                      ( DMA_INTSTATUS_INT5_Msk )

#define DMA_INTSTATUS_INT4_Pos                  ( 4U )
#define DMA_INTSTATUS_INT4_Msk                  ( 0x1UL << DMA_INTSTATUS_INT4_Pos )
#define DMA_INTSTATUS_INT4                      ( DMA_INTSTATUS_INT4_Msk )

#define DMA_INTSTATUS_INT3_Pos                  ( 3U )
#define DMA_INTSTATUS_INT3_Msk                  ( 0x1UL << DMA_INTSTATUS_INT3_Pos )
#define DMA_INTSTATUS_INT3                      ( DMA_INTSTATUS_INT3_Msk )

#define DMA_INTSTATUS_INT2_Pos                  ( 2U )
#define DMA_INTSTATUS_INT2_Msk                  ( 0x1UL << DMA_INTSTATUS_INT2_Pos )
#define DMA_INTSTATUS_INT2                      ( DMA_INTSTATUS_INT2_Msk )

#define DMA_INTSTATUS_INT1_Pos                  ( 1U )
#define DMA_INTSTATUS_INT1_Msk                  ( 0x1UL << DMA_INTSTATUS_INT1_Pos )
#define DMA_INTSTATUS_INT1                      ( DMA_INTSTATUS_INT1_Msk )

#define DMA_INTSTATUS_INT0_Pos                  ( 0U )
#define DMA_INTSTATUS_INT0_Msk                  ( 0x1UL << DMA_INTSTATUS_INT0_Pos )
#define DMA_INTSTATUS_INT0                      ( DMA_INTSTATUS_INT0_Msk )


/***************  Bits definition for DMA_INTTCSTATUS register  **************/

#define DMA_INTTCSTATUS_HFTC15_Pos              ( 15U )
#define DMA_INTTCSTATUS_HFTC15_Msk              ( 0x1UL << DMA_INTTCSTATUS_HFTC15_Pos )
#define DMA_INTTCSTATUS_HFTC15                  ( DMA_INTTCSTATUS_HFTC15_Msk )

#define DMA_INTTCSTATUS_HFTC14_Pos              ( 14U )
#define DMA_INTTCSTATUS_HFTC14_Msk              ( 0x1UL << DMA_INTTCSTATUS_HFTC14_Pos )
#define DMA_INTTCSTATUS_HFTC14                  ( DMA_INTTCSTATUS_HFTC14_Msk )

#define DMA_INTTCSTATUS_HFTC13_Pos              ( 13U )
#define DMA_INTTCSTATUS_HFTC13_Msk              ( 0x1UL << DMA_INTTCSTATUS_HFTC13_Pos )
#define DMA_INTTCSTATUS_HFTC13                  ( DMA_INTTCSTATUS_HFTC13_Msk )

#define DMA_INTTCSTATUS_HFTC12_Pos              ( 12U )
#define DMA_INTTCSTATUS_HFTC12_Msk              ( 0x1UL << DMA_INTTCSTATUS_HFTC12_Pos )
#define DMA_INTTCSTATUS_HFTC12                  ( DMA_INTTCSTATUS_HFTC12_Msk )

#define DMA_INTTCSTATUS_HFTC11_Pos              ( 11U )
#define DMA_INTTCSTATUS_HFTC11_Msk              ( 0x1UL << DMA_INTTCSTATUS_HFTC11_Pos )
#define DMA_INTTCSTATUS_HFTC11                  ( DMA_INTTCSTATUS_HFTC11_Msk )

#define DMA_INTTCSTATUS_HFTC10_Pos              ( 10U )
#define DMA_INTTCSTATUS_HFTC10_Msk              ( 0x1UL << DMA_INTTCSTATUS_HFTC10_Pos )
#define DMA_INTTCSTATUS_HFTC10                  ( DMA_INTTCSTATUS_HFTC10_Msk )

#define DMA_INTTCSTATUS_HFTC9_Pos               ( 9U )
#define DMA_INTTCSTATUS_HFTC9_Msk               ( 0x1UL << DMA_INTTCSTATUS_HFTC9_Pos )
#define DMA_INTTCSTATUS_HFTC9                   ( DMA_INTTCSTATUS_HFTC9_Msk )

#define DMA_INTTCSTATUS_HFTC8_Pos               ( 8U )
#define DMA_INTTCSTATUS_HFTC8_Msk               ( 0x1UL << DMA_INTTCSTATUS_HFTC8_Pos )
#define DMA_INTTCSTATUS_HFTC8                   ( DMA_INTTCSTATUS_HFTC8_Msk )

#define DMA_INTTCSTATUS_TC7_Pos                 ( 7U )
#define DMA_INTTCSTATUS_TC7_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC7_Pos )
#define DMA_INTTCSTATUS_TC7                     ( DMA_INTTCSTATUS_TC7_Msk )

#define DMA_INTTCSTATUS_TC6_Pos                 ( 6U )
#define DMA_INTTCSTATUS_TC6_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC6_Pos )
#define DMA_INTTCSTATUS_TC6                     ( DMA_INTTCSTATUS_TC6_Msk )

#define DMA_INTTCSTATUS_TC5_Pos                 ( 5U )
#define DMA_INTTCSTATUS_TC5_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC5_Pos )
#define DMA_INTTCSTATUS_TC5                     ( DMA_INTTCSTATUS_TC5_Msk )

#define DMA_INTTCSTATUS_TC4_Pos                 ( 4U )
#define DMA_INTTCSTATUS_TC4_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC4_Pos )
#define DMA_INTTCSTATUS_TC4                     ( DMA_INTTCSTATUS_TC4_Msk )

#define DMA_INTTCSTATUS_TC3_Pos                 ( 3U )
#define DMA_INTTCSTATUS_TC3_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC3_Pos )
#define DMA_INTTCSTATUS_TC3                     ( DMA_INTTCSTATUS_TC3_Msk )

#define DMA_INTTCSTATUS_TC2_Pos                 ( 2U )
#define DMA_INTTCSTATUS_TC2_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC2_Pos )
#define DMA_INTTCSTATUS_TC2                     ( DMA_INTTCSTATUS_TC2_Msk )

#define DMA_INTTCSTATUS_TC1_Pos                 ( 1U )
#define DMA_INTTCSTATUS_TC1_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC1_Pos )
#define DMA_INTTCSTATUS_TC1                     ( DMA_INTTCSTATUS_TC1_Msk )

#define DMA_INTTCSTATUS_TC0_Pos                 ( 0U )
#define DMA_INTTCSTATUS_TC0_Msk                 ( 0x1UL << DMA_INTTCSTATUS_TC0_Pos )
#define DMA_INTTCSTATUS_TC0                     ( DMA_INTTCSTATUS_TC0_Msk )


/***************  Bits definition for DMA_INTTCCLR register  *****************/

#define DMA_INTTCCLR_HFTC15_Pos                 ( 15U )
#define DMA_INTTCCLR_HFTC15_Msk                 ( 0x1UL << DMA_INTTCCLR_HFTC15_Pos )
#define DMA_INTTCCLR_HFTC15                     ( DMA_INTTCCLR_HFTC15_Msk )

#define DMA_INTTCCLR_HFTC14_Pos                 ( 14U )
#define DMA_INTTCCLR_HFTC14_Msk                 ( 0x1UL << DMA_INTTCCLR_HFTC14_Pos )
#define DMA_INTTCCLR_HFTC14                     ( DMA_INTTCCLR_HFTC14_Msk )

#define DMA_INTTCCLR_HFTC13_Pos                 ( 13U )
#define DMA_INTTCCLR_HFTC13_Msk                 ( 0x1UL << DMA_INTTCCLR_HFTC13_Pos )
#define DMA_INTTCCLR_HFTC13                     ( DMA_INTTCCLR_HFTC13_Msk )

#define DMA_INTTCCLR_HFTC12_Pos                 ( 12U )
#define DMA_INTTCCLR_HFTC12_Msk                 ( 0x1UL << DMA_INTTCCLR_HFTC12_Pos )
#define DMA_INTTCCLR_HFTC12                     ( DMA_INTTCCLR_HFTC12_Msk )

#define DMA_INTTCCLR_HFTC11_Pos                 ( 11U )
#define DMA_INTTCCLR_HFTC11_Msk                 ( 0x1UL << DMA_INTTCCLR_HFTC11_Pos )
#define DMA_INTTCCLR_HFTC11                     ( DMA_INTTCCLR_HFTC11_Msk )

#define DMA_INTTCCLR_HFTC10_Pos                 ( 10U )
#define DMA_INTTCCLR_HFTC10_Msk                 ( 0x1UL << DMA_INTTCCLR_HFTC10_Pos )
#define DMA_INTTCCLR_HFTC10                     ( DMA_INTTCCLR_HFTC10_Msk )

#define DMA_INTTCCLR_HFTC9_Pos                  ( 9U )
#define DMA_INTTCCLR_HFTC9_Msk                  ( 0x1UL << DMA_INTTCCLR_HFTC9_Pos )
#define DMA_INTTCCLR_HFTC9                      ( DMA_INTTCCLR_HFTC9_Msk )

#define DMA_INTTCCLR_HFTC8_Pos                  ( 8U )
#define DMA_INTTCCLR_HFTC8_Msk                  ( 0x1UL << DMA_INTTCCLR_HFTC8_Pos )
#define DMA_INTTCCLR_HFTC8                      ( DMA_INTTCCLR_HFTC8_Msk )

#define DMA_INTTCCLR_TC7_Pos                    ( 7U )
#define DMA_INTTCCLR_TC7_Msk                    ( 0x1UL << DMA_INTTCCLR_TC7_Pos )
#define DMA_INTTCCLR_TC7                        ( DMA_INTTCCLR_TC7_Msk )

#define DMA_INTTCCLR_TC6_Pos                    ( 6U )
#define DMA_INTTCCLR_TC6_Msk                    ( 0x1UL << DMA_INTTCCLR_TC6_Pos )
#define DMA_INTTCCLR_TC6                        ( DMA_INTTCCLR_TC6_Msk )

#define DMA_INTTCCLR_TC5_Pos                    ( 5U )
#define DMA_INTTCCLR_TC5_Msk                    ( 0x1UL << DMA_INTTCCLR_TC5_Pos )
#define DMA_INTTCCLR_TC5                        ( DMA_INTTCCLR_TC5_Msk )

#define DMA_INTTCCLR_TC4_Pos                    ( 4U )
#define DMA_INTTCCLR_TC4_Msk                    ( 0x1UL << DMA_INTTCCLR_TC4_Pos )
#define DMA_INTTCCLR_TC4                        ( DMA_INTTCCLR_TC4_Msk )

#define DMA_INTTCCLR_TC3_Pos                    ( 3U )
#define DMA_INTTCCLR_TC3_Msk                    ( 0x1UL << DMA_INTTCCLR_TC3_Pos )
#define DMA_INTTCCLR_TC3                        ( DMA_INTTCCLR_TC3_Msk )

#define DMA_INTTCCLR_TC2_Pos                    ( 2U )
#define DMA_INTTCCLR_TC2_Msk                    ( 0x1UL << DMA_INTTCCLR_TC2_Pos )
#define DMA_INTTCCLR_TC2                        ( DMA_INTTCCLR_TC2_Msk )

#define DMA_INTTCCLR_TC1_Pos                    ( 1U )
#define DMA_INTTCCLR_TC1_Msk                    ( 0x1UL << DMA_INTTCCLR_TC1_Pos )
#define DMA_INTTCCLR_TC1                        ( DMA_INTTCCLR_TC1_Msk )

#define DMA_INTTCCLR_TC0_Pos                    ( 0U )
#define DMA_INTTCCLR_TC0_Msk                    ( 0x1UL << DMA_INTTCCLR_TC0_Pos )
#define DMA_INTTCCLR_TC0                        ( DMA_INTTCCLR_TC0_Msk )


/***************  Bits definition for DMA_INTERRSTATUS register  *************/

#define DMA_INTERRSTATUS_ERR7_Pos               ( 7U )
#define DMA_INTERRSTATUS_ERR7_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR7_Pos )
#define DMA_INTERRSTATUS_ERR7                   ( DMA_INTERRSTATUS_ERR7_Msk )

#define DMA_INTERRSTATUS_ERR6_Pos               ( 6U )
#define DMA_INTERRSTATUS_ERR6_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR6_Pos )
#define DMA_INTERRSTATUS_ERR6                   ( DMA_INTERRSTATUS_ERR6_Msk )

#define DMA_INTERRSTATUS_ERR5_Pos               ( 5U )
#define DMA_INTERRSTATUS_ERR5_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR5_Pos )
#define DMA_INTERRSTATUS_ERR5                   ( DMA_INTERRSTATUS_ERR5_Msk )

#define DMA_INTERRSTATUS_ERR4_Pos               ( 4U )
#define DMA_INTERRSTATUS_ERR4_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR4_Pos )
#define DMA_INTERRSTATUS_ERR4                   ( DMA_INTERRSTATUS_ERR4_Msk )

#define DMA_INTERRSTATUS_ERR3_Pos               ( 3U )
#define DMA_INTERRSTATUS_ERR3_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR3_Pos )
#define DMA_INTERRSTATUS_ERR3                   ( DMA_INTERRSTATUS_ERR3_Msk )

#define DMA_INTERRSTATUS_ERR2_Pos               ( 2U )
#define DMA_INTERRSTATUS_ERR2_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR2_Pos )
#define DMA_INTERRSTATUS_ERR2                   ( DMA_INTERRSTATUS_ERR2_Msk )

#define DMA_INTERRSTATUS_ERR1_Pos               ( 1U )
#define DMA_INTERRSTATUS_ERR1_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR1_Pos )
#define DMA_INTERRSTATUS_ERR1                   ( DMA_INTERRSTATUS_ERR1_Msk )

#define DMA_INTERRSTATUS_ERR0_Pos               ( 0U )
#define DMA_INTERRSTATUS_ERR0_Msk               ( 0x1UL << DMA_INTERRSTATUS_ERR0_Pos )
#define DMA_INTERRSTATUS_ERR0                   ( DMA_INTERRSTATUS_ERR0_Msk )


/***************  Bits definition for DMA_INTERRCLR register  ****************/

#define DMA_INTERRCLR_ERR7_Pos                  ( 7U )
#define DMA_INTERRCLR_ERR7_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR7_Pos )
#define DMA_INTERRCLR_ERR7                      ( DMA_INTERRCLR_ERR7_Msk )

#define DMA_INTERRCLR_ERR6_Pos                  ( 6U )
#define DMA_INTERRCLR_ERR6_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR6_Pos )
#define DMA_INTERRCLR_ERR6                      ( DMA_INTERRCLR_ERR6_Msk )

#define DMA_INTERRCLR_ERR5_Pos                  ( 5U )
#define DMA_INTERRCLR_ERR5_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR5_Pos )
#define DMA_INTERRCLR_ERR5                      ( DMA_INTERRCLR_ERR5_Msk )

#define DMA_INTERRCLR_ERR4_Pos                  ( 4U )
#define DMA_INTERRCLR_ERR4_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR4_Pos )
#define DMA_INTERRCLR_ERR4                      ( DMA_INTERRCLR_ERR4_Msk )

#define DMA_INTERRCLR_ERR3_Pos                  ( 3U )
#define DMA_INTERRCLR_ERR3_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR3_Pos )
#define DMA_INTERRCLR_ERR3                      ( DMA_INTERRCLR_ERR3_Msk )

#define DMA_INTERRCLR_ERR2_Pos                  ( 2U )
#define DMA_INTERRCLR_ERR2_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR2_Pos )
#define DMA_INTERRCLR_ERR2                      ( DMA_INTERRCLR_ERR2_Msk )

#define DMA_INTERRCLR_ERR1_Pos                  ( 1U )
#define DMA_INTERRCLR_ERR1_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR1_Pos )
#define DMA_INTERRCLR_ERR1                      ( DMA_INTERRCLR_ERR1_Msk )

#define DMA_INTERRCLR_ERR0_Pos                  ( 0U )
#define DMA_INTERRCLR_ERR0_Msk                  ( 0x1UL << DMA_INTERRCLR_ERR0_Pos )
#define DMA_INTERRCLR_ERR0                      ( DMA_INTERRCLR_ERR0_Msk )


/***************  Bits definition for DMAC_RAWINTTCSTATUS register  **********/

#define DMA_RAWINTTCSTATUS_HFTC15_Pos          ( 15U )
#define DMA_RAWINTTCSTATUS_HFTC15_Msk          ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC15_Pos )
#define DMA_RAWINTTCSTATUS_HFTC15              ( DMAC_RAWINTTCSTATUS_HFTC15_Msk )

#define DMA_RAWINTTCSTATUS_HFTC14_Pos          ( 14U )
#define DMA_RAWINTTCSTATUS_HFTC14_Msk          ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC14_Pos )
#define DMA_RAWINTTCSTATUS_HFTC14              ( DMAC_RAWINTTCSTATUS_HFTC14_Msk )

#define DMA_RAWINTTCSTATUS_HFTC13_Pos          ( 13U )
#define DMA_RAWINTTCSTATUS_HFTC13_Msk          ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC13_Pos )
#define DMA_RAWINTTCSTATUS_HFTC13              ( DMAC_RAWINTTCSTATUS_HFTC13_Msk )

#define DMA_RAWINTTCSTATUS_HFTC12_Pos          ( 12U )
#define DMA_RAWINTTCSTATUS_HFTC12_Msk          ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC12_Pos )
#define DMA_RAWINTTCSTATUS_HFTC12              ( DMAC_RAWINTTCSTATUS_HFTC12_Msk )

#define DMA_RAWINTTCSTATUS_HFTC11_Pos          ( 11U )
#define DMA_RAWINTTCSTATUS_HFTC11_Msk          ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC11_Pos )
#define DMA_RAWINTTCSTATUS_HFTC11              ( DMAC_RAWINTTCSTATUS_HFTC11_Msk )

#define DMA_RAWINTTCSTATUS_HFTC10_Pos          ( 10U )
#define DMA_RAWINTTCSTATUS_HFTC10_Msk          ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC10_Pos )
#define DMA_RAWINTTCSTATUS_HFTC10              ( DMAC_RAWINTTCSTATUS_HFTC10_Msk )

#define DMA_RAWINTTCSTATUS_HFTC9_Pos           ( 9U )
#define DMA_RAWINTTCSTATUS_HFTC9_Msk           ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC9_Pos )
#define DMA_RAWINTTCSTATUS_HFTC9               ( DMAC_RAWINTTCSTATUS_HFTC9_Msk )

#define DMA_RAWINTTCSTATUS_HFTC8_Pos           ( 8U )
#define DMA_RAWINTTCSTATUS_HFTC8_Msk           ( 0x1UL << DMAC_RAWINTTCSTATUS_HFTC8_Pos )
#define DMA_RAWINTTCSTATUS_HFTC8               ( DMAC_RAWINTTCSTATUS_HFTC8_Msk )

#define DMA_RAWINTTCSTATUS_TC7_Pos             ( 7U )
#define DMA_RAWINTTCSTATUS_TC7_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC7_Pos )
#define DMA_RAWINTTCSTATUS_TC7                 ( DMAC_RAWINTTCSTATUS_TC7_Msk )

#define DMA_RAWINTTCSTATUS_TC6_Pos             ( 6U )
#define DMA_RAWINTTCSTATUS_TC6_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC6_Pos )
#define DMA_RAWINTTCSTATUS_TC6                 ( DMAC_RAWINTTCSTATUS_TC6_Msk )

#define DMA_RAWINTTCSTATUS_TC5_Pos             ( 5U )
#define DMA_RAWINTTCSTATUS_TC5_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC5_Pos )
#define DMA_RAWINTTCSTATUS_TC5                 ( DMAC_RAWINTTCSTATUS_TC5_Msk )

#define DMA_RAWINTTCSTATUS_TC4_Pos             ( 4U )
#define DMA_RAWINTTCSTATUS_TC4_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC4_Pos )
#define DMA_RAWINTTCSTATUS_TC4                 ( DMAC_RAWINTTCSTATUS_TC4_Msk )

#define DMA_RAWINTTCSTATUS_TC3_Pos             ( 3U )
#define DMA_RAWINTTCSTATUS_TC3_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC3_Pos )
#define DMA_RAWINTTCSTATUS_TC3                 ( DMAC_RAWINTTCSTATUS_TC3_Msk )

#define DMA_RAWINTTCSTATUS_TC2_Pos             ( 2U )
#define DMA_RAWINTTCSTATUS_TC2_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC2_Pos )
#define DMA_RAWINTTCSTATUS_TC2                 ( DMAC_RAWINTTCSTATUS_TC2_Msk )

#define DMA_RAWINTTCSTATUS_TC1_Pos             ( 1U )
#define DMA_RAWINTTCSTATUS_TC1_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC1_Pos )
#define DMA_RAWINTTCSTATUS_TC1                 ( DMAC_RAWINTTCSTATUS_TC1_Msk )

#define DMA_RAWINTTCSTATUS_TC0_Pos             ( 0U )
#define DMA_RAWINTTCSTATUS_TC0_Msk             ( 0x1UL << DMAC_RAWINTTCSTATUS_TC0_Pos )
#define DMA_RAWINTTCSTATUS_TC0                 ( DMAC_RAWINTTCSTATUS_TC0_Msk )


/***************  Bits definition for DMAC_RAWINTERRSTATUS register  *********/

#define DMA_RAWINTERRSTATUS_ERR7_Pos           ( 7U )
#define DMA_RAWINTERRSTATUS_ERR7_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR7_Pos )
#define DMA_RAWINTERRSTATUS_ERR7               ( DMAC_RAWINTERRSTATUS_ERR7_Msk )

#define DMA_RAWINTERRSTATUS_ERR6_Pos           ( 6U )
#define DMA_RAWINTERRSTATUS_ERR6_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR6_Pos )
#define DMA_RAWINTERRSTATUS_ERR6               ( DMAC_RAWINTERRSTATUS_ERR6_Msk )

#define DMA_RAWINTERRSTATUS_ERR5_Pos           ( 5U )
#define DMA_RAWINTERRSTATUS_ERR5_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR5_Pos )
#define DMA_RAWINTERRSTATUS_ERR5               ( DMAC_RAWINTERRSTATUS_ERR5_Msk )

#define DMA_RAWINTERRSTATUS_ERR4_Pos           ( 4U )
#define DMA_RAWINTERRSTATUS_ERR4_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR4_Pos )
#define DMA_RAWINTERRSTATUS_ERR4               ( DMAC_RAWINTERRSTATUS_ERR4_Msk )

#define DMA_RAWINTERRSTATUS_ERR3_Pos           ( 3U )
#define DMA_RAWINTERRSTATUS_ERR3_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR3_Pos )
#define DMA_RAWINTERRSTATUS_ERR3               ( DMAC_RAWINTERRSTATUS_ERR3_Msk )

#define DMA_RAWINTERRSTATUS_ERR2_Pos           ( 2U )
#define DMA_RAWINTERRSTATUS_ERR2_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR2_Pos )
#define DMA_RAWINTERRSTATUS_ERR2               ( DMAC_RAWINTERRSTATUS_ERR2_Msk )

#define DMA_RAWINTERRSTATUS_ERR1_Pos           ( 1U )
#define DMA_RAWINTERRSTATUS_ERR1_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR1_Pos )
#define DMA_RAWINTERRSTATUS_ERR1               ( DMAC_RAWINTERRSTATUS_ERR1_Msk )

#define DMA_RAWINTERRSTATUS_ERR0_Pos           ( 0U )
#define DMA_RAWINTERRSTATUS_ERR0_Msk           ( 0x1UL << DMAC_RAWINTERRSTATUS_ERR0_Pos )
#define DMA_RAWINTERRSTATUS_ERR0               ( DMAC_RAWINTERRSTATUS_ERR0_Msk )

/***************  Bits definition for DMA_ENCHSTATUS register  ***************/

#define DMA_ENCHSTATUS_ENCHSTAT7_Pos            ( 7U )
#define DMA_ENCHSTATUS_ENCHSTAT7_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT7_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT7                ( DMA_ENCHSTATUS_ENCHSTAT7_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT6_Pos            ( 6U )
#define DMA_ENCHSTATUS_ENCHSTAT6_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT6_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT6                ( DMA_ENCHSTATUS_ENCHSTAT6_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT5_Pos            ( 5U )
#define DMA_ENCHSTATUS_ENCHSTAT5_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT5_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT5                ( DMA_ENCHSTATUS_ENCHSTAT5_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT4_Pos            ( 4U )
#define DMA_ENCHSTATUS_ENCHSTAT4_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT4_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT4                ( DMA_ENCHSTATUS_ENCHSTAT4_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT3_Pos            ( 3U )
#define DMA_ENCHSTATUS_ENCHSTAT3_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT3_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT3                ( DMA_ENCHSTATUS_ENCHSTAT3_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT2_Pos            ( 2U )
#define DMA_ENCHSTATUS_ENCHSTAT2_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT2_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT2                ( DMA_ENCHSTATUS_ENCHSTAT2_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT1_Pos            ( 1U )
#define DMA_ENCHSTATUS_ENCHSTAT1_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT1_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT1                ( DMA_ENCHSTATUS_ENCHSTAT1_Msk )

#define DMA_ENCHSTATUS_ENCHSTAT0_Pos            ( 0U )
#define DMA_ENCHSTATUS_ENCHSTAT0_Msk            ( 0x1UL << DMA_ENCHSTATUS_ENCHSTAT0_Pos )
#define DMA_ENCHSTATUS_ENCHSTAT0                ( DMA_ENCHSTATUS_ENCHSTAT0_Msk )


/***************  Bits definition for DMA_CONFIG register  *******************/

#define DMA_CONFIG_ENDIAN_Pos                   ( 1U )
#define DMA_CONFIG_ENDIAN_Msk                   ( 0x1UL << DMA_CONFIG_ENDIAN_Pos )
#define DMA_CONFIG_ENDIAN                       ( DMA_CONFIG_ENDIAN_Msk )

#define DMA_CONFIG_EN_Pos                       ( 0U )
#define DMA_CONFIG_EN_Msk                       ( 0x1UL << DMA_CONFIG_EN_Pos )
#define DMA_CONFIG_EN                           ( DMA_CONFIG_EN_Msk )


/***************  Bits definition for DMA_SYNCLO register  *******************/

#define DMA_SYNCLO_SYNCLO31_Pos                 ( 31U )
#define DMA_SYNCLO_SYNCLO31_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO31_Pos )
#define DMA_SYNCLO_SYNCLO31                     ( DMA_SYNCLO_SYNCLO31_Msk )

#define DMA_SYNCLO_SYNCLO30_Pos                 ( 30U )
#define DMA_SYNCLO_SYNCLO30_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO30_Pos )
#define DMA_SYNCLO_SYNCLO30                     ( DMA_SYNCLO_SYNCLO30_Msk )

#define DMA_SYNCLO_SYNCLO29_Pos                 ( 29U )
#define DMA_SYNCLO_SYNCLO29_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO29_Pos )
#define DMA_SYNCLO_SYNCLO29                     ( DMA_SYNCLO_SYNCLO29_Msk )

#define DMA_SYNCLO_SYNCLO28_Pos                 ( 28U )
#define DMA_SYNCLO_SYNCLO28_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO28_Pos )
#define DMA_SYNCLO_SYNCLO28                     ( DMA_SYNCLO_SYNCLO28_Msk )

#define DMA_SYNCLO_SYNCLO27_Pos                 ( 27U )
#define DMA_SYNCLO_SYNCLO27_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO27_Pos )
#define DMA_SYNCLO_SYNCLO27                     ( DMA_SYNCLO_SYNCLO27_Msk )

#define DMA_SYNCLO_SYNCLO26_Pos                 ( 26U )
#define DMA_SYNCLO_SYNCLO26_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO26_Pos )
#define DMA_SYNCLO_SYNCLO26                     ( DMA_SYNCLO_SYNCLO26_Msk )

#define DMA_SYNCLO_SYNCLO25_Pos                 ( 25U )
#define DMA_SYNCLO_SYNCLO25_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO25_Pos )
#define DMA_SYNCLO_SYNCLO25                     ( DMA_SYNCLO_SYNCLO25_Msk )

#define DMA_SYNCLO_SYNCLO24_Pos                 ( 24U )
#define DMA_SYNCLO_SYNCLO24_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO24_Pos )
#define DMA_SYNCLO_SYNCLO24                     ( DMA_SYNCLO_SYNCLO24_Msk )

#define DMA_SYNCLO_SYNCLO23_Pos                 ( 23U )
#define DMA_SYNCLO_SYNCLO23_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO23_Pos )
#define DMA_SYNCLO_SYNCLO23                     ( DMA_SYNCLO_SYNCLO23_Msk )

#define DMA_SYNCLO_SYNCLO22_Pos                 ( 22U )
#define DMA_SYNCLO_SYNCLO22_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO22_Pos )
#define DMA_SYNCLO_SYNCLO22                     ( DMA_SYNCLO_SYNCLO22_Msk )

#define DMA_SYNCLO_SYNCLO21_Pos                 ( 21U )
#define DMA_SYNCLO_SYNCLO21_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO21_Pos )
#define DMA_SYNCLO_SYNCLO21                     ( DMA_SYNCLO_SYNCLO21_Msk )

#define DMA_SYNCLO_SYNCLO20_Pos                 ( 20U )
#define DMA_SYNCLO_SYNCLO20_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO20_Pos )
#define DMA_SYNCLO_SYNCLO20                     ( DMA_SYNCLO_SYNCLO20_Msk )

#define DMA_SYNCLO_SYNCLO19_Pos                 ( 19U )
#define DMA_SYNCLO_SYNCLO19_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO19_Pos )
#define DMA_SYNCLO_SYNCLO19                     ( DMA_SYNCLO_SYNCLO19_Msk )

#define DMA_SYNCLO_SYNCLO18_Pos                 ( 18U )
#define DMA_SYNCLO_SYNCLO18_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO18_Pos )
#define DMA_SYNCLO_SYNCLO18                     ( DMA_SYNCLO_SYNCLO18_Msk )

#define DMA_SYNCLO_SYNCLO17_Pos                 ( 17U )
#define DMA_SYNCLO_SYNCLO17_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO17_Pos )
#define DMA_SYNCLO_SYNCLO17                     ( DMA_SYNCLO_SYNCLO17_Msk )

#define DMA_SYNCLO_SYNCLO16_Pos                 ( 16U )
#define DMA_SYNCLO_SYNCLO16_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO16_Pos )
#define DMA_SYNCLO_SYNCLO16                     ( DMA_SYNCLO_SYNCLO16_Msk )

#define DMA_SYNCLO_SYNCLO15_Pos                 ( 15U )
#define DMA_SYNCLO_SYNCLO15_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO15_Pos )
#define DMA_SYNCLO_SYNCLO15                     ( DMA_SYNCLO_SYNCLO15_Msk )

#define DMA_SYNCLO_SYNCLO14_Pos                 ( 14U )
#define DMA_SYNCLO_SYNCLO14_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO14_Pos )
#define DMA_SYNCLO_SYNCLO14                     ( DMA_SYNCLO_SYNCLO14_Msk )

#define DMA_SYNCLO_SYNCLO13_Pos                 ( 13U )
#define DMA_SYNCLO_SYNCLO13_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO13_Pos )
#define DMA_SYNCLO_SYNCLO13                     ( DMA_SYNCLO_SYNCLO13_Msk )

#define DMA_SYNCLO_SYNCLO12_Pos                 ( 12U )
#define DMA_SYNCLO_SYNCLO12_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO12_Pos )
#define DMA_SYNCLO_SYNCLO12                     ( DMA_SYNCLO_SYNCLO12_Msk )

#define DMA_SYNCLO_SYNCLO11_Pos                 ( 11U )
#define DMA_SYNCLO_SYNCLO11_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO11_Pos )
#define DMA_SYNCLO_SYNCLO11                     ( DMA_SYNCLO_SYNCLO11_Msk )

#define DMA_SYNCLO_SYNCLO10_Pos                 ( 10U )
#define DMA_SYNCLO_SYNCLO10_Msk                 ( 0x1UL << DMA_SYNCLO_SYNCLO10_Pos )
#define DMA_SYNCLO_SYNCLO10                     ( DMA_SYNCLO_SYNCLO10_Msk )

#define DMA_SYNCLO_SYNCLO9_Pos                  ( 9U )
#define DMA_SYNCLO_SYNCLO9_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO9_Pos )
#define DMA_SYNCLO_SYNCLO9                      ( DMA_SYNCLO_SYNCLO9_Msk )

#define DMA_SYNCLO_SYNCLO8_Pos                  ( 8U )
#define DMA_SYNCLO_SYNCLO8_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO8_Pos )
#define DMA_SYNCLO_SYNCLO8                      ( DMA_SYNCLO_SYNCLO8_Msk )

#define DMA_SYNCLO_SYNCLO7_Pos                  ( 7U )
#define DMA_SYNCLO_SYNCLO7_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO7_Pos )
#define DMA_SYNCLO_SYNCLO7                      ( DMA_SYNCLO_SYNCLO7_Msk )

#define DMA_SYNCLO_SYNCLO6_Pos                  ( 6U )
#define DMA_SYNCLO_SYNCLO6_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO6_Pos )
#define DMA_SYNCLO_SYNCLO6                      ( DMA_SYNCLO_SYNCLO6_Msk )

#define DMA_SYNCLO_SYNCLO5_Pos                  ( 5U )
#define DMA_SYNCLO_SYNCLO5_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO5_Pos )
#define DMA_SYNCLO_SYNCLO5                      ( DMA_SYNCLO_SYNCLO5_Msk )

#define DMA_SYNCLO_SYNCLO4_Pos                  ( 4U )
#define DMA_SYNCLO_SYNCLO4_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO4_Pos )
#define DMA_SYNCLO_SYNCLO4                      ( DMA_SYNCLO_SYNCLO4_Msk )

#define DMA_SYNCLO_SYNCLO3_Pos                  ( 3U )
#define DMA_SYNCLO_SYNCLO3_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO3_Pos )
#define DMA_SYNCLO_SYNCLO3                      ( DMA_SYNCLO_SYNCLO3_Msk )

#define DMA_SYNCLO_SYNCLO2_Pos                  ( 2U )
#define DMA_SYNCLO_SYNCLO2_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO2_Pos )
#define DMA_SYNCLO_SYNCLO2                      ( DMA_SYNCLO_SYNCLO2_Msk )

#define DMA_SYNCLO_SYNCLO1_Pos                  ( 1U )
#define DMA_SYNCLO_SYNCLO1_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO1_Pos )
#define DMA_SYNCLO_SYNCLO1                      ( DMA_SYNCLO_SYNCLO1_Msk )

#define DMA_SYNCLO_SYNCLO0_Pos                  ( 0U )
#define DMA_SYNCLO_SYNCLO0_Msk                  ( 0x1UL << DMA_SYNCLO_SYNCLO0_Pos )
#define DMA_SYNCLO_SYNCLO0                      ( DMA_SYNCLO_SYNCLO0_Msk )


/***************  Bits definition for DMA_SYNCHI register  *******************/

#define DMA_SYNCHI_SYNCHI31_Pos                 ( 31U )
#define DMA_SYNCHI_SYNCHI31_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI31_Pos )
#define DMA_SYNCHI_SYNCHI31                     ( DMA_SYNCHI_SYNCHI31_Msk )

#define DMA_SYNCHI_SYNCHI30_Pos                 ( 30U )
#define DMA_SYNCHI_SYNCHI30_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI30_Pos )
#define DMA_SYNCHI_SYNCHI30                     ( DMA_SYNCHI_SYNCHI30_Msk )

#define DMA_SYNCHI_SYNCHI29_Pos                 ( 29U )
#define DMA_SYNCHI_SYNCHI29_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI29_Pos )
#define DMA_SYNCHI_SYNCHI29                     ( DMA_SYNCHI_SYNCHI29_Msk )

#define DMA_SYNCHI_SYNCHI28_Pos                 ( 28U )
#define DMA_SYNCHI_SYNCHI28_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI28_Pos )
#define DMA_SYNCHI_SYNCHI28                     ( DMA_SYNCHI_SYNCHI28_Msk )

#define DMA_SYNCHI_SYNCHI27_Pos                 ( 27U )
#define DMA_SYNCHI_SYNCHI27_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI27_Pos )
#define DMA_SYNCHI_SYNCHI27                     ( DMA_SYNCHI_SYNCHI27_Msk )

#define DMA_SYNCHI_SYNCHI26_Pos                 ( 26U )
#define DMA_SYNCHI_SYNCHI26_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI26_Pos )
#define DMA_SYNCHI_SYNCHI26                     ( DMA_SYNCHI_SYNCHI26_Msk )

#define DMA_SYNCHI_SYNCHI25_Pos                 ( 25U )
#define DMA_SYNCHI_SYNCHI25_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI25_Pos )
#define DMA_SYNCHI_SYNCHI25                     ( DMA_SYNCHI_SYNCHI25_Msk )

#define DMA_SYNCHI_SYNCHI24_Pos                 ( 24U )
#define DMA_SYNCHI_SYNCHI24_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI24_Pos )
#define DMA_SYNCHI_SYNCHI24                     ( DMA_SYNCHI_SYNCHI24_Msk )

#define DMA_SYNCHI_SYNCHI23_Pos                 ( 23U )
#define DMA_SYNCHI_SYNCHI23_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI23_Pos )
#define DMA_SYNCHI_SYNCHI23                     ( DMA_SYNCHI_SYNCHI23_Msk )

#define DMA_SYNCHI_SYNCHI22_Pos                 ( 22U )
#define DMA_SYNCHI_SYNCHI22_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI22_Pos )
#define DMA_SYNCHI_SYNCHI22                     ( DMA_SYNCHI_SYNCHI22_Msk )

#define DMA_SYNCHI_SYNCHI21_Pos                 ( 21U )
#define DMA_SYNCHI_SYNCHI21_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI21_Pos )
#define DMA_SYNCHI_SYNCHI21                     ( DMA_SYNCHI_SYNCHI21_Msk )

#define DMA_SYNCHI_SYNCHI20_Pos                 ( 20U )
#define DMA_SYNCHI_SYNCHI20_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI20_Pos )
#define DMA_SYNCHI_SYNCHI20                     ( DMA_SYNCHI_SYNCHI20_Msk )

#define DMA_SYNCHI_SYNCHI19_Pos                 ( 19U )
#define DMA_SYNCHI_SYNCHI19_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI19_Pos )
#define DMA_SYNCHI_SYNCHI19                     ( DMA_SYNCHI_SYNCHI19_Msk )

#define DMA_SYNCHI_SYNCHI18_Pos                 ( 18U )
#define DMA_SYNCHI_SYNCHI18_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI18_Pos )
#define DMA_SYNCHI_SYNCHI18                     ( DMA_SYNCHI_SYNCHI18_Msk )

#define DMA_SYNCHI_SYNCHI17_Pos                 ( 17U )
#define DMA_SYNCHI_SYNCHI17_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI17_Pos )
#define DMA_SYNCHI_SYNCHI17                     ( DMA_SYNCHI_SYNCHI17_Msk )

#define DMA_SYNCHI_SYNCHI16_Pos                 ( 16U )
#define DMA_SYNCHI_SYNCHI16_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI16_Pos )
#define DMA_SYNCHI_SYNCHI16                     ( DMA_SYNCHI_SYNCHI16_Msk )

#define DMA_SYNCHI_SYNCHI15_Pos                 ( 15U )
#define DMA_SYNCHI_SYNCHI15_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI15_Pos )
#define DMA_SYNCHI_SYNCHI15                     ( DMA_SYNCHI_SYNCHI15_Msk )

#define DMA_SYNCHI_SYNCHI14_Pos                 ( 14U )
#define DMA_SYNCHI_SYNCHI14_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI14_Pos )
#define DMA_SYNCHI_SYNCHI14                     ( DMA_SYNCHI_SYNCHI14_Msk )

#define DMA_SYNCHI_SYNCHI13_Pos                 ( 13U )
#define DMA_SYNCHI_SYNCHI13_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI13_Pos )
#define DMA_SYNCHI_SYNCHI13                     ( DMA_SYNCHI_SYNCHI13_Msk )

#define DMA_SYNCHI_SYNCHI12_Pos                 ( 12U )
#define DMA_SYNCHI_SYNCHI12_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI12_Pos )
#define DMA_SYNCHI_SYNCHI12                     ( DMA_SYNCHI_SYNCHI12_Msk )

#define DMA_SYNCHI_SYNCHI11_Pos                 ( 11U )
#define DMA_SYNCHI_SYNCHI11_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI11_Pos )
#define DMA_SYNCHI_SYNCHI11                     ( DMA_SYNCHI_SYNCHI11_Msk )

#define DMA_SYNCHI_SYNCHI10_Pos                 ( 10U )
#define DMA_SYNCHI_SYNCHI10_Msk                 ( 0x1UL << DMA_SYNCHI_SYNCHI10_Pos )
#define DMA_SYNCHI_SYNCHI10                     ( DMA_SYNCHI_SYNCHI10_Msk )

#define DMA_SYNCHI_SYNCHI9_Pos                  ( 9U )
#define DMA_SYNCHI_SYNCHI9_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI9_Pos )
#define DMA_SYNCHI_SYNCHI9                      ( DMA_SYNCHI_SYNCHI9_Msk )

#define DMA_SYNCHI_SYNCHI8_Pos                  ( 8U )
#define DMA_SYNCHI_SYNCHI8_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI8_Pos )
#define DMA_SYNCHI_SYNCHI8                      ( DMA_SYNCHI_SYNCHI8_Msk )

#define DMA_SYNCHI_SYNCHI7_Pos                  ( 7U )
#define DMA_SYNCHI_SYNCHI7_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI7_Pos )
#define DMA_SYNCHI_SYNCHI7                      ( DMA_SYNCHI_SYNCHI7_Msk )

#define DMA_SYNCHI_SYNCHI6_Pos                  ( 6U )
#define DMA_SYNCHI_SYNCHI6_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI6_Pos )
#define DMA_SYNCHI_SYNCHI6                      ( DMA_SYNCHI_SYNCHI6_Msk )

#define DMA_SYNCHI_SYNCHI5_Pos                  ( 5U )
#define DMA_SYNCHI_SYNCHI5_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI5_Pos )
#define DMA_SYNCHI_SYNCHI5                      ( DMA_SYNCHI_SYNCHI5_Msk )

#define DMA_SYNCHI_SYNCHI4_Pos                  ( 4U )
#define DMA_SYNCHI_SYNCHI4_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI4_Pos )
#define DMA_SYNCHI_SYNCHI4                      ( DMA_SYNCHI_SYNCHI4_Msk )

#define DMA_SYNCHI_SYNCHI3_Pos                  ( 3U )
#define DMA_SYNCHI_SYNCHI3_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI3_Pos )
#define DMA_SYNCHI_SYNCHI3                      ( DMA_SYNCHI_SYNCHI3_Msk )

#define DMA_SYNCHI_SYNCHI2_Pos                  ( 2U )
#define DMA_SYNCHI_SYNCHI2_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI2_Pos )
#define DMA_SYNCHI_SYNCHI2                      ( DMA_SYNCHI_SYNCHI2_Msk )

#define DMA_SYNCHI_SYNCHI1_Pos                  ( 1U )
#define DMA_SYNCHI_SYNCHI1_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI1_Pos )
#define DMA_SYNCHI_SYNCHI1                      ( DMA_SYNCHI_SYNCHI1_Msk )

#define DMA_SYNCHI_SYNCHI0_Pos                  ( 0U )
#define DMA_SYNCHI_SYNCHI0_Msk                  ( 0x1UL << DMA_SYNCHI_SYNCHI0_Pos )
#define DMA_SYNCHI_SYNCHI0                      ( DMA_SYNCHI_SYNCHI0_Msk )


/***************  Bits definition for DMA_CHSRCADDR register  ******************/

#define DMA_CHSRCADDR_SRCADDR_Pos                 ( 0U )
#define DMA_CHSRCADDR_SRCADDR_Msk                 ( 0xFFFFFFFFUL << DMA_CHSRCADDR_SRCADDR_Pos )
#define DMA_CHSRCADDR_SRCADDR                     ( DMA_CHSRCADDR_SRCADDR_Msk )


/***************  Bits definition for DMA_CHDESTADDR register  *****************/

#define DMA_CHDESTADDR_DESTADDR_Pos               ( 0U )
#define DMA_CHDESTADDR_DESTADDR_Msk               ( 0xFFFFFFFFUL << DMA_CHDESTADDR_DESTADDR_Pos )
#define DMA_CHDESTADDR_DESTADDR                   ( DMA_CHDESTADDR_DESTADDR_Msk )


/***************  Bits definition for DMA_CHLLI register  **********************/

#define DMA_CHLLI_LLI_Pos                         ( 2U )
#define DMA_CHLLI_LLI_Msk                         ( 0x3FFFFFFFUL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI                             ( DMA_CHLLI_LLI_Msk )
#define DMA_CHLLI_LLI_0                           ( 0x1UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_1                           ( 0x2UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_2                           ( 0x4UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_3                           ( 0x8UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_4                           ( 0x10UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_5                           ( 0x20UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_6                           ( 0x40UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_7                           ( 0x80UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_8                           ( 0x100UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_9                           ( 0x200UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_10                          ( 0x400UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_11                          ( 0x800UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_12                          ( 0x1000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_13                          ( 0x2000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_14                          ( 0x4000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_15                          ( 0x8000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_16                          ( 0x10000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_17                          ( 0x20000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_18                          ( 0x40000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_19                          ( 0x80000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_20                          ( 0x100000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_21                          ( 0x200000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_22                          ( 0x400000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_23                          ( 0x800000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_24                          ( 0x1000000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_25                          ( 0x2000000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_26                          ( 0x4000000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_27                          ( 0x8000000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_28                          ( 0x10000000UL << DMA_CHLLI_LLI_Pos )
#define DMA_CHLLI_LLI_29                          ( 0x20000000UL << DMA_CHLLI_LLI_Pos )


/***************  Bits definition for DMA_CHCTRL register  *********************/

#define DMA_CHCTRL_ITC_Pos                        ( 31U )
#define DMA_CHCTRL_ITC_Msk                        ( 0x1UL << DMA_CHCTRL_ITC_Pos )
#define DMA_CHCTRL_ITC                            ( DMA_CHCTRL_ITC_Msk )

#define DMA_CHCTRL_DI_Pos                         ( 29U )
#define DMA_CHCTRL_DI_Msk                         ( 0x1UL << DMA_CHCTRL_DI_Pos )
#define DMA_CHCTRL_DI                             ( DMA_CHCTRL_DI_Msk )

#define DMA_CHCTRL_SI_Pos                         ( 28U )
#define DMA_CHCTRL_SI_Msk                         ( 0x1UL << DMA_CHCTRL_SI_Pos )
#define DMA_CHCTRL_SI                             ( DMA_CHCTRL_SI_Msk )

#define DMA_CHCTRL_DWIDTH_Pos                     ( 25U )
#define DMA_CHCTRL_DWIDTH_Msk                     ( 0x7UL << DMA_CHCTRL_DWIDTH_Pos )
#define DMA_CHCTRL_DWIDTH                         ( DMA_CHCTRL_DWIDTH_Msk )
#define DMA_CHCTRL_DWIDTH_0                       ( 0x1UL << DMA_CHCTRL_DWIDTH_Pos )
#define DMA_CHCTRL_DWIDTH_1                       ( 0x2UL << DMA_CHCTRL_DWIDTH_Pos )
#define DMA_CHCTRL_DWIDTH_2                       ( 0x4UL << DMA_CHCTRL_DWIDTH_Pos )

#define DMA_CHCTRL_SWIDTH_Pos                     ( 22U )
#define DMA_CHCTRL_SWIDTH_Msk                     ( 0x7UL << DMA_CHCTRL_SWIDTH_Pos )
#define DMA_CHCTRL_SWIDTH                         ( DMA_CHCTRL_SWIDTH_Msk )
#define DMA_CHCTRL_SWIDTH_0                       ( 0x1UL << DMA_CHCTRL_SWIDTH_Pos )
#define DMA_CHCTRL_SWIDTH_1                       ( 0x2UL << DMA_CHCTRL_SWIDTH_Pos )
#define DMA_CHCTRL_SWIDTH_2                       ( 0x4UL << DMA_CHCTRL_SWIDTH_Pos )

#define DMA_CHCTRL_DBSIZE_Pos                     ( 19U )
#define DMA_CHCTRL_DBSIZE_Msk                     ( 0x7UL << DMA_CHCTRL_DBSIZE_Pos )
#define DMA_CHCTRL_DBSIZE                         ( DMA_CHCTRL_DBSIZE_Msk )
#define DMA_CHCTRL_DBSIZE_0                       ( 0x1UL << DMA_CHCTRL_DBSIZE_Pos )
#define DMA_CHCTRL_DBSIZE_1                       ( 0x2UL << DMA_CHCTRL_DBSIZE_Pos )
#define DMA_CHCTRL_DBSIZE_2                       ( 0x4UL << DMA_CHCTRL_DBSIZE_Pos )

#define DMA_CHCTRL_SBSIZE_Pos                     ( 16U )
#define DMA_CHCTRL_SBSIZE_Msk                     ( 0x7UL << DMA_CHCTRL_SBSIZE_Pos )
#define DMA_CHCTRL_SBSIZE                         ( DMA_CHCTRL_SBSIZE_Msk )
#define DMA_CHCTRL_SBSIZE_0                       ( 0x1UL << DMA_CHCTRL_SBSIZE_Pos )
#define DMA_CHCTRL_SBSIZE_1                       ( 0x2UL << DMA_CHCTRL_SBSIZE_Pos )
#define DMA_CHCTRL_SBSIZE_2                       ( 0x4UL << DMA_CHCTRL_SBSIZE_Pos )

#define DMA_CHCTRL_TRANSFERSIZE_Pos               ( 0U )
#define DMA_CHCTRL_TRANSFERSIZE_Msk               ( 0xFFFFUL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE                   ( DMA_CHCTRL_TRANSFERSIZE_Msk )
#define DMA_CHCTRL_TRANSFERSIZE_0                 ( 0x1UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_1                 ( 0x2UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_2                 ( 0x4UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_3                 ( 0x8UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_4                 ( 0x10UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_5                 ( 0x20UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_6                 ( 0x40UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_7                 ( 0x80UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_8                 ( 0x100UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_9                 ( 0x200UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_10                ( 0x400UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_11                ( 0x800UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_12                ( 0x1000UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_13                ( 0x2000UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_14                ( 0x4000UL << DMA_CHCTRL_TRANSFERSIZE_Pos )
#define DMA_CHCTRL_TRANSFERSIZE_15                ( 0x8000UL << DMA_CHCTRL_TRANSFERSIZE_Pos )

/***************  Bits definition for DMA_CHCONFIG register  *******************/

#define DMA_CHCONFIG_SRCPERIPH_Pos                ( 24U )
#define DMA_CHCONFIG_SRCPERIPH_Msk                ( 0x3FUL << DMA_CHCONFIG_SRCPERIPH_Pos )
#define DMA_CHCONFIG_SRCPERIPH                    ( DMA_CHCONFIG_SRCPERIPH_Msk )
#define DMA_CHCONFIG_SRCPERIPH_0                  ( 0x1UL << DMA_CHCONFIG_SRCPERIPH_Pos )
#define DMA_CHCONFIG_SRCPERIPH_1                  ( 0x2UL << DMA_CHCONFIG_SRCPERIPH_Pos )
#define DMA_CHCONFIG_SRCPERIPH_2                  ( 0x4UL << DMA_CHCONFIG_SRCPERIPH_Pos )
#define DMA_CHCONFIG_SRCPERIPH_3                  ( 0x8UL << DMA_CHCONFIG_SRCPERIPH_Pos )
#define DMA_CHCONFIG_SRCPERIPH_4                  ( 0x10UL << DMA_CHCONFIG_SRCPERIPH_Pos )
#define DMA_CHCONFIG_SRCPERIPH_5                  ( 0x20UL << DMA_CHCONFIG_SRCPERIPH_Pos )

#define DMA_CHCONFIG_DESTPERIPH_Pos               ( 16U )
#define DMA_CHCONFIG_DESTPERIPH_Msk               ( 0x3FUL << DMA_CHCONFIG_DESTPERIPH_Pos )
#define DMA_CHCONFIG_DESTPERIPH                   ( DMA_CHCONFIG_DESTPERIPH_Msk )
#define DMA_CHCONFIG_DESTPERIPH_0                 ( 0x1UL << DMA_CHCONFIG_DESTPERIPH_Pos )
#define DMA_CHCONFIG_DESTPERIPH_1                 ( 0x2UL << DMA_CHCONFIG_DESTPERIPH_Pos )
#define DMA_CHCONFIG_DESTPERIPH_2                 ( 0x4UL << DMA_CHCONFIG_DESTPERIPH_Pos )
#define DMA_CHCONFIG_DESTPERIPH_3                 ( 0x8UL << DMA_CHCONFIG_DESTPERIPH_Pos )
#define DMA_CHCONFIG_DESTPERIPH_4                 ( 0x10UL << DMA_CHCONFIG_DESTPERIPH_Pos )
#define DMA_CHCONFIG_DESTPERIPH_5                 ( 0x20UL << DMA_CHCONFIG_DESTPERIPH_Pos )

#define DMA_CHCONFIG_HALT_Pos                     ( 8U )
#define DMA_CHCONFIG_HALT_Msk                     ( 0x1UL << DMA_CHCONFIG_HALT_Pos )
#define DMA_CHCONFIG_HALT                         ( DMA_CHCONFIG_HALT_Msk )

#define DMA_CHCONFIG_ACTIVE_Pos                   ( 7U )
#define DMA_CHCONFIG_ACTIVE_Msk                   ( 0x1UL << DMA_CHCONFIG_ACTIVE_Pos )
#define DMA_CHCONFIG_ACTIVE                       ( DMA_CHCONFIG_ACTIVE_Msk )

#define DMA_CHCONFIG_IHFTC_Pos                    ( 6U )
#define DMA_CHCONFIG_IHFTC_Msk                    ( 0x1UL << DMA_CHCONFIG_IHFTC_Pos )
#define DMA_CHCONFIG_IHFTC                        ( DMA_CHCONFIG_IHFTC_Msk )

#define DMA_CHCONFIG_ITC_Pos                      ( 5U )
#define DMA_CHCONFIG_ITC_Msk                      ( 0x1UL << DMA_CHCONFIG_ITC_Pos )
#define DMA_CHCONFIG_ITC                          ( DMA_CHCONFIG_ITC_Msk )

#define DMA_CHCONFIG_IE_Pos                       ( 4U )
#define DMA_CHCONFIG_IE_Msk                       ( 0x1UL << DMA_CHCONFIG_IE_Pos )
#define DMA_CHCONFIG_IE                           ( DMA_CHCONFIG_IE_Msk )

#define DMA_CHCONFIG_FLOWCTRL_Pos                 ( 1U )
#define DMA_CHCONFIG_FLOWCTRL_Msk                 ( 0x7UL << DMA_CHCONFIG_FLOWCTRL_Pos )
#define DMA_CHCONFIG_FLOWCTRL                     ( DMA_CHCONFIG_FLOWCTRL_Msk )
#define DMA_CHCONFIG_FLOWCTRL_0                   ( 0x1UL << DMA_CHCONFIG_FLOWCTRL_Pos )
#define DMA_CHCONFIG_FLOWCTRL_1                   ( 0x2UL << DMA_CHCONFIG_FLOWCTRL_Pos )
#define DMA_CHCONFIG_FLOWCTRL_2                   ( 0x4UL << DMA_CHCONFIG_FLOWCTRL_Pos )

#define DMA_CHCONFIG_EN_Pos                       ( 0U )
#define DMA_CHCONFIG_EN_Msk                       ( 0x1UL << DMA_CHCONFIG_EN_Pos )
#define DMA_CHCONFIG_EN                           ( DMA_CHCONFIG_EN_Msk )

/***************  Bits definition for IWDT_CMDR register  ********************/

#define IWDT_CMDR_CMD_Pos                       ( 0U )
#define IWDT_CMDR_CMD_Msk                       ( 0xFFFFUL << IWDT_CMDR_CMD_Pos )
#define IWDT_CMDR_CMD                           ( IWDT_CMDR_CMD_Msk )


/***************  Bits definition for IWDT_PR register  **********************/

#define IWDT_PR_PR_Pos                          ( 0U )
#define IWDT_PR_PR_Msk                          ( 0x7UL << IWDT_PR_PR_Pos )
#define IWDT_PR_PR                              ( IWDT_PR_PR_Msk )
#define IWDT_PR_PR_0                            ( 0x1UL << IWDT_PR_PR_Pos )
#define IWDT_PR_PR_1                            ( 0x2UL << IWDT_PR_PR_Pos )
#define IWDT_PR_PR_2                            ( 0x4UL << IWDT_PR_PR_Pos )


/***************  Bits definition for IWDT_RLR register  *********************/

#define IWDT_RLR_PL_Pos                         ( 0U )
#define IWDT_RLR_PL_Msk                         ( 0xFFFUL << IWDT_RLR_PL_Pos )
#define IWDT_RLR_PL                             ( IWDT_RLR_PL_Msk )


/***************  Bits definition for IWDT_SR register  **********************/

#define IWDT_SR_RLF_Pos                         ( 4U )
#define IWDT_SR_RLF_Msk                         ( 0x1UL << IWDT_SR_RLF_Pos )
#define IWDT_SR_RLF                             ( IWDT_SR_RLF_Msk )

#define IWDT_SR_WTU_Pos                         ( 3U )
#define IWDT_SR_WTU_Msk                         ( 0x1UL << IWDT_SR_WTU_Pos )
#define IWDT_SR_WTU                             ( IWDT_SR_WTU_Msk )

#define IWDT_SR_WVU_Pos                         ( 2U )
#define IWDT_SR_WVU_Msk                         ( 0x1UL << IWDT_SR_WVU_Pos )
#define IWDT_SR_WVU                             ( IWDT_SR_WVU_Msk )

#define IWDT_SR_RVU_Pos                         ( 1U )
#define IWDT_SR_RVU_Msk                         ( 0x1UL << IWDT_SR_RVU_Pos )
#define IWDT_SR_RVU                             ( IWDT_SR_RVU_Msk )

#define IWDT_SR_PVU_Pos                         ( 0U )
#define IWDT_SR_PVU_Msk                         ( 0x1UL << IWDT_SR_PVU_Pos )
#define IWDT_SR_PVU                             ( IWDT_SR_PVU_Msk )


/***************  Bits definition for IWDT_WINR register  ********************/

#define IWDT_WINR_WIN_Pos                       ( 0U )
#define IWDT_WINR_WIN_Msk                       ( 0xFFFUL << IWDT_WINR_WIN_Pos )
#define IWDT_WINR_WIN                           ( IWDT_WINR_WIN_Msk )


/***************  Bits definition for IWDT_WUTR register  ********************/

#define IWDT_WUTR_WUT_Pos                       ( 0U )
#define IWDT_WUTR_WUT_Msk                       ( 0xFFFUL << IWDT_WUTR_WUT_Pos )
#define IWDT_WUTR_WUT                           ( IWDT_WUTR_WUT_Msk )


/***************  Bits definition for LPTIM_ISR register  ********************/

#define LPTIM_ISR_REPOK_Pos                     ( 8U )
#define LPTIM_ISR_REPOK_Msk                     ( 0x1UL << LPTIM_ISR_REPOK_Pos )
#define LPTIM_ISR_REPOK                         ( LPTIM_ISR_REPOK_Msk )

#define LPTIM_ISR_UE_Pos                        ( 7U )
#define LPTIM_ISR_UE_Msk                        ( 0x1UL << LPTIM_ISR_UE_Pos )
#define LPTIM_ISR_UE                            ( LPTIM_ISR_UE_Msk )

#define LPTIM_ISR_DOWN_Pos                      ( 6U )
#define LPTIM_ISR_DOWN_Msk                      ( 0x1UL << LPTIM_ISR_DOWN_Pos )
#define LPTIM_ISR_DOWN                          ( LPTIM_ISR_DOWN_Msk )

#define LPTIM_ISR_UP_Pos                        ( 5U )
#define LPTIM_ISR_UP_Msk                        ( 0x1UL << LPTIM_ISR_UP_Pos )
#define LPTIM_ISR_UP                            ( LPTIM_ISR_UP_Msk )

#define LPTIM_ISR_ARROK_Pos                     ( 4U )
#define LPTIM_ISR_ARROK_Msk                     ( 0x1UL << LPTIM_ISR_ARROK_Pos )
#define LPTIM_ISR_ARROK                         ( LPTIM_ISR_ARROK_Msk )

#define LPTIM_ISR_CMPOK_Pos                     ( 3U )
#define LPTIM_ISR_CMPOK_Msk                     ( 0x1UL << LPTIM_ISR_CMPOK_Pos )
#define LPTIM_ISR_CMPOK                         ( LPTIM_ISR_CMPOK_Msk )

#define LPTIM_ISR_EXTTRIG_Pos                   ( 2U )
#define LPTIM_ISR_EXTTRIG_Msk                   ( 0x1UL << LPTIM_ISR_EXTTRIG_Pos )
#define LPTIM_ISR_EXTTRIG                       ( LPTIM_ISR_EXTTRIG_Msk )

#define LPTIM_ISR_ARRM_Pos                      ( 1U )
#define LPTIM_ISR_ARRM_Msk                      ( 0x1UL << LPTIM_ISR_ARRM_Pos )
#define LPTIM_ISR_ARRM                          ( LPTIM_ISR_ARRM_Msk )

#define LPTIM_ISR_CMPM_Pos                      ( 0U )
#define LPTIM_ISR_CMPM_Msk                      ( 0x1UL << LPTIM_ISR_CMPM_Pos )
#define LPTIM_ISR_CMPM                          ( LPTIM_ISR_CMPM_Msk )


/***************  Bits definition for LPTIM_ICR register  ********************/

#define LPTIM_ICR_REPOKCF_Pos                   ( 8U )
#define LPTIM_ICR_REPOKCF_Msk                   ( 0x1UL << LPTIM_ICR_REPOKCF_Pos )
#define LPTIM_ICR_REPOKCF                       ( LPTIM_ICR_REPOKCF_Msk )

#define LPTIM_ICR_UECF_Pos                      ( 7U )
#define LPTIM_ICR_UECF_Msk                      ( 0x1UL << LPTIM_ICR_UECF_Pos )
#define LPTIM_ICR_UECF                          ( LPTIM_ICR_UECF_Msk )

#define LPTIM_ICR_DOWNCF_Pos                    ( 6U )
#define LPTIM_ICR_DOWNCF_Msk                    ( 0x1UL << LPTIM_ICR_DOWNCF_Pos )
#define LPTIM_ICR_DOWNCF                        ( LPTIM_ICR_DOWNCF_Msk )

#define LPTIM_ICR_UPCF_Pos                      ( 5U )
#define LPTIM_ICR_UPCF_Msk                      ( 0x1UL << LPTIM_ICR_UPCF_Pos )
#define LPTIM_ICR_UPCF                          ( LPTIM_ICR_UPCF_Msk )

#define LPTIM_ICR_ARROKCF_Pos                   ( 4U )
#define LPTIM_ICR_ARROKCF_Msk                   ( 0x1UL << LPTIM_ICR_ARROKCF_Pos )
#define LPTIM_ICR_ARROKCF                       ( LPTIM_ICR_ARROKCF_Msk )

#define LPTIM_ICR_CMPOKCF_Pos                   ( 3U )
#define LPTIM_ICR_CMPOKCF_Msk                   ( 0x1UL << LPTIM_ICR_CMPOKCF_Pos )
#define LPTIM_ICR_CMPOKCF                       ( LPTIM_ICR_CMPOKCF_Msk )

#define LPTIM_ICR_EXTTRIGCF_Pos                 ( 2U )
#define LPTIM_ICR_EXTTRIGCF_Msk                 ( 0x1UL << LPTIM_ICR_EXTTRIGCF_Pos )
#define LPTIM_ICR_EXTTRIGCF                     ( LPTIM_ICR_EXTTRIGCF_Msk )

#define LPTIM_ICR_ARRMCF_Pos                    ( 1U )
#define LPTIM_ICR_ARRMCF_Msk                    ( 0x1UL << LPTIM_ICR_ARRMCF_Pos )
#define LPTIM_ICR_ARRMCF                        ( LPTIM_ICR_ARRMCF_Msk )

#define LPTIM_ICR_CMPMCF_Pos                    ( 0U )
#define LPTIM_ICR_CMPMCF_Msk                    ( 0x1UL << LPTIM_ICR_CMPMCF_Pos )
#define LPTIM_ICR_CMPMCF                        ( LPTIM_ICR_CMPMCF_Msk )


/***************  Bits definition for LPTIM_IER register  ********************/

#define LPTIM_IER_REPOKIE_Pos                   ( 8U )
#define LPTIM_IER_REPOKIE_Msk                   ( 0x1UL << LPTIM_IER_REPOKIE_Pos )
#define LPTIM_IER_REPOKIE                       ( LPTIM_IER_REPOKIE_Msk )

#define LPTIM_IER_UEIE_Pos                      ( 7U )
#define LPTIM_IER_UEIE_Msk                      ( 0x1UL << LPTIM_IER_UEIE_Pos )
#define LPTIM_IER_UEIE                          ( LPTIM_IER_UEIE_Msk )

#define LPTIM_IER_DOWNIE_Pos                    ( 6U )
#define LPTIM_IER_DOWNIE_Msk                    ( 0x1UL << LPTIM_IER_DOWNIE_Pos )
#define LPTIM_IER_DOWNIE                        ( LPTIM_IER_DOWNIE_Msk )

#define LPTIM_IER_UPIE_Pos                      ( 5U )
#define LPTIM_IER_UPIE_Msk                      ( 0x1UL << LPTIM_IER_UPIE_Pos )
#define LPTIM_IER_UPIE                          ( LPTIM_IER_UPIE_Msk )

#define LPTIM_IER_ARROKIE_Pos                   ( 4U )
#define LPTIM_IER_ARROKIE_Msk                   ( 0x1UL << LPTIM_IER_ARROKIE_Pos )
#define LPTIM_IER_ARROKIE                       ( LPTIM_IER_ARROKIE_Msk )

#define LPTIM_IER_CMPOKIE_Pos                   ( 3U )
#define LPTIM_IER_CMPOKIE_Msk                   ( 0x1UL << LPTIM_IER_CMPOKIE_Pos )
#define LPTIM_IER_CMPOKIE                       ( LPTIM_IER_CMPOKIE_Msk )

#define LPTIM_IER_EXTTRIGIE_Pos                 ( 2U )
#define LPTIM_IER_EXTTRIGIE_Msk                 ( 0x1UL << LPTIM_IER_EXTTRIGIE_Pos )
#define LPTIM_IER_EXTTRIGIE                     ( LPTIM_IER_EXTTRIGIE_Msk )

#define LPTIM_IER_ARRMIE_Pos                    ( 1U )
#define LPTIM_IER_ARRMIE_Msk                    ( 0x1UL << LPTIM_IER_ARRMIE_Pos )
#define LPTIM_IER_ARRMIE                        ( LPTIM_IER_ARRMIE_Msk )

#define LPTIM_IER_CMPMIE_Pos                    ( 0U )
#define LPTIM_IER_CMPMIE_Msk                    ( 0x1UL << LPTIM_IER_CMPMIE_Pos )
#define LPTIM_IER_CMPMIE                        ( LPTIM_IER_CMPMIE_Msk )


/***************  Bits definition for LPTIM_CFGR register  *******************/

#define LPTIM_CFGR_ENC_Pos                      ( 24U )
#define LPTIM_CFGR_ENC_Msk                      ( 0x1UL << LPTIM_CFGR_ENC_Pos )
#define LPTIM_CFGR_ENC                          ( LPTIM_CFGR_ENC_Msk )

#define LPTIM_CFGR_COUNTMODE_Pos                ( 23U )
#define LPTIM_CFGR_COUNTMODE_Msk                ( 0x1UL << LPTIM_CFGR_COUNTMODE_Pos )
#define LPTIM_CFGR_COUNTMODE                    ( LPTIM_CFGR_COUNTMODE_Msk )

#define LPTIM_CFGR_PRELOAD_Pos                  ( 22U )
#define LPTIM_CFGR_PRELOAD_Msk                  ( 0x1UL << LPTIM_CFGR_PRELOAD_Pos )
#define LPTIM_CFGR_PRELOAD                      ( LPTIM_CFGR_PRELOAD_Msk )

#define LPTIM_CFGR_WAVPOL_Pos                   ( 21U )
#define LPTIM_CFGR_WAVPOL_Msk                   ( 0x1UL << LPTIM_CFGR_WAVPOL_Pos )
#define LPTIM_CFGR_WAVPOL                       ( LPTIM_CFGR_WAVPOL_Msk )

#define LPTIM_CFGR_WAVE_Pos                     ( 20U )
#define LPTIM_CFGR_WAVE_Msk                     ( 0x1UL << LPTIM_CFGR_WAVE_Pos )
#define LPTIM_CFGR_WAVE                         ( LPTIM_CFGR_WAVE_Msk )

#define LPTIM_CFGR_TIMOUT_Pos                   ( 19U )
#define LPTIM_CFGR_TIMOUT_Msk                   ( 0x1UL << LPTIM_CFGR_TIMOUT_Pos )
#define LPTIM_CFGR_TIMOUT                       ( LPTIM_CFGR_TIMOUT_Msk )

#define LPTIM_CFGR_TRIGEN_Pos                   ( 17U )
#define LPTIM_CFGR_TRIGEN_Msk                   ( 0x3UL << LPTIM_CFGR_TRIGEN_Pos )
#define LPTIM_CFGR_TRIGEN                       ( LPTIM_CFGR_TRIGEN_Msk )
#define LPTIM_CFGR_TRIGEN_0                     ( 0x1UL << LPTIM_CFGR_TRIGEN_Pos )
#define LPTIM_CFGR_TRIGEN_1                     ( 0x2UL << LPTIM_CFGR_TRIGEN_Pos )

#define LPTIM_CFGR_TRIGSEL_Pos                  ( 13U )
#define LPTIM_CFGR_TRIGSEL_Msk                  ( 0x7UL << LPTIM_CFGR_TRIGSEL_Pos )
#define LPTIM_CFGR_TRIGSEL                      ( LPTIM_CFGR_TRIGSEL_Msk )
#define LPTIM_CFGR_TRIGSEL_0                    ( 0x1UL << LPTIM_CFGR_TRIGSEL_Pos )
#define LPTIM_CFGR_TRIGSEL_1                    ( 0x2UL << LPTIM_CFGR_TRIGSEL_Pos )
#define LPTIM_CFGR_TRIGSEL_2                    ( 0x4UL << LPTIM_CFGR_TRIGSEL_Pos )

#define LPTIM_CFGR_PRESC_Pos                    ( 9U )
#define LPTIM_CFGR_PRESC_Msk                    ( 0x7UL << LPTIM_CFGR_PRESC_Pos )
#define LPTIM_CFGR_PRESC                        ( LPTIM_CFGR_PRESC_Msk )
#define LPTIM_CFGR_PRESC_0                      ( 0x1UL << LPTIM_CFGR_PRESC_Pos )
#define LPTIM_CFGR_PRESC_1                      ( 0x2UL << LPTIM_CFGR_PRESC_Pos )
#define LPTIM_CFGR_PRESC_2                      ( 0x4UL << LPTIM_CFGR_PRESC_Pos )

#define LPTIM_CFGR_TRGFLT_Pos                   ( 6U )
#define LPTIM_CFGR_TRGFLT_Msk                   ( 0x3UL << LPTIM_CFGR_TRGFLT_Pos )
#define LPTIM_CFGR_TRGFLT                       ( LPTIM_CFGR_TRGFLT_Msk )
#define LPTIM_CFGR_TRGFLT_0                     ( 0x1UL << LPTIM_CFGR_TRGFLT_Pos )
#define LPTIM_CFGR_TRGFLT_1                     ( 0x2UL << LPTIM_CFGR_TRGFLT_Pos )

#define LPTIM_CFGR_CKFLT_Pos                    ( 3U )
#define LPTIM_CFGR_CKFLT_Msk                    ( 0x3UL << LPTIM_CFGR_CKFLT_Pos )
#define LPTIM_CFGR_CKFLT                        ( LPTIM_CFGR_CKFLT_Msk )
#define LPTIM_CFGR_CKFLT_0                      ( 0x1UL << LPTIM_CFGR_CKFLT_Pos )
#define LPTIM_CFGR_CKFLT_1                      ( 0x2UL << LPTIM_CFGR_CKFLT_Pos )

#define LPTIM_CFGR_CKPOL_Pos                    ( 1U )
#define LPTIM_CFGR_CKPOL_Msk                    ( 0x3UL << LPTIM_CFGR_CKPOL_Pos )
#define LPTIM_CFGR_CKPOL                        ( LPTIM_CFGR_CKPOL_Msk )
#define LPTIM_CFGR_CKPOL_0                      ( 0x1UL << LPTIM_CFGR_CKPOL_Pos )
#define LPTIM_CFGR_CKPOL_1                      ( 0x2UL << LPTIM_CFGR_CKPOL_Pos )

#define LPTIM_CFGR_CKSEL_Pos                    ( 0U )
#define LPTIM_CFGR_CKSEL_Msk                    ( 0x1UL << LPTIM_CFGR_CKSEL_Pos )
#define LPTIM_CFGR_CKSEL                        ( LPTIM_CFGR_CKSEL_Msk )


/***************  Bits definition for LPTIM_CR register  *********************/

#define LPTIM_CR_RSTARE_Pos                     ( 4U )
#define LPTIM_CR_RSTARE_Msk                     ( 0x1UL << LPTIM_CR_RSTARE_Pos )
#define LPTIM_CR_RSTARE                         ( LPTIM_CR_RSTARE_Msk )

#define LPTIM_CR_COUNTRST_Pos                   ( 3U )
#define LPTIM_CR_COUNTRST_Msk                   ( 0x1UL << LPTIM_CR_COUNTRST_Pos )
#define LPTIM_CR_COUNTRST                       ( LPTIM_CR_COUNTRST_Msk )

#define LPTIM_CR_CNTSTRT_Pos                    ( 2U )
#define LPTIM_CR_CNTSTRT_Msk                    ( 0x1UL << LPTIM_CR_CNTSTRT_Pos )
#define LPTIM_CR_CNTSTRT                        ( LPTIM_CR_CNTSTRT_Msk )

#define LPTIM_CR_SNGSTRT_Pos                    ( 1U )
#define LPTIM_CR_SNGSTRT_Msk                    ( 0x1UL << LPTIM_CR_SNGSTRT_Pos )
#define LPTIM_CR_SNGSTRT                        ( LPTIM_CR_SNGSTRT_Msk )

#define LPTIM_CR_ENABLE_Pos                     ( 0U )
#define LPTIM_CR_ENABLE_Msk                     ( 0x1UL << LPTIM_CR_ENABLE_Pos )
#define LPTIM_CR_ENABLE                         ( LPTIM_CR_ENABLE_Msk )


/***************  Bits definition for LPTIM_CMP register  ********************/

#define LPTIM_CMP_CMP_Pos                       ( 0U )
#define LPTIM_CMP_CMP_Msk                       ( 0xFFFFUL << LPTIM_CMP_CMP_Pos )
#define LPTIM_CMP_CMP                           ( LPTIM_CMP_CMP_Msk )


/***************  Bits definition for LPTIM_ARR register  ********************/

#define LPTIM_ARR_ARR_Pos                       ( 0U )
#define LPTIM_ARR_ARR_Msk                       ( 0xFFFFUL << LPTIM_ARR_ARR_Pos )
#define LPTIM_ARR_ARR                           ( LPTIM_ARR_ARR_Msk )


/***************  Bits definition for LPTIM_CNT register  ********************/

#define LPTIM_CNT_CNT_Pos                       ( 0U )
#define LPTIM_CNT_CNT_Msk                       ( 0xFFFFUL << LPTIM_CNT_CNT_Pos )
#define LPTIM_CNT_CNT                           ( LPTIM_CNT_CNT_Msk )


/***************  Bits definition for LPTIM_CFGR2 register  ******************/

#define LPTIM_CFGR2_IN2SEL_Pos                  ( 4U )
#define LPTIM_CFGR2_IN2SEL_Msk                  ( 0x3UL << LPTIM_CFGR2_IN2SEL_Pos )
#define LPTIM_CFGR2_IN2SEL                      ( LPTIM_CFGR2_IN2SEL_Msk )
#define LPTIM_CFGR2_IN2SEL_0                    ( 0x1UL << LPTIM_CFGR2_IN2SEL_Pos )
#define LPTIM_CFGR2_IN2SEL_1                    ( 0x2UL << LPTIM_CFGR2_IN2SEL_Pos )

#define LPTIM_CFGR2_IN1SEL_Pos                  ( 0U )
#define LPTIM_CFGR2_IN1SEL_Msk                  ( 0x3UL << LPTIM_CFGR2_IN1SEL_Pos )
#define LPTIM_CFGR2_IN1SEL                      ( LPTIM_CFGR2_IN1SEL_Msk )
#define LPTIM_CFGR2_IN1SEL_0                    ( 0x1UL << LPTIM_CFGR2_IN1SEL_Pos )
#define LPTIM_CFGR2_IN1SEL_1                    ( 0x2UL << LPTIM_CFGR2_IN1SEL_Pos )


/***************  Bits definition for LPTIM_RCR register  ********************/

#define LPTIM_RCR_REP_Pos                       ( 0U )
#define LPTIM_RCR_REP_Msk                       ( 0xFFUL << LPTIM_RCR_REP_Pos )
#define LPTIM_RCR_REP                           ( LPTIM_RCR_REP_Msk )


/***************  Bits definition for LPUART_RXDR register  ******************/

#define LPUART_RXDR_RXDATA_Pos                  ( 0U )
#define LPUART_RXDR_RXDATA_Msk                  ( 0xFFUL << LPUART_RXDR_RXDATA_Pos )
#define LPUART_RXDR_RXDATA                      ( LPUART_RXDR_RXDATA_Msk )


/***************  Bits definition for LPUART_TXDR register  ******************/

#define LPUART_TXDR_TXDATA_Pos                  ( 0U )
#define LPUART_TXDR_TXDATA_Msk                  ( 0xFFUL << LPUART_TXDR_TXDATA_Pos )
#define LPUART_TXDR_TXDATA                      ( LPUART_TXDR_TXDATA_Msk )


/***************  Bits definition for LPUART_LCR register  *******************/

#define LPUART_LCR_TXPOL_Pos                    ( 9U )
#define LPUART_LCR_TXPOL_Msk                    ( 0x1UL << LPUART_LCR_TXPOL_Pos )
#define LPUART_LCR_TXPOL                        ( LPUART_LCR_TXPOL_Msk )

#define LPUART_LCR_RXPOL_Pos                    ( 8U )
#define LPUART_LCR_RXPOL_Msk                    ( 0x1UL << LPUART_LCR_RXPOL_Pos )
#define LPUART_LCR_RXPOL                        ( LPUART_LCR_RXPOL_Msk )

#define LPUART_LCR_WKCK_Pos                     ( 7U )
#define LPUART_LCR_WKCK_Msk                     ( 0x1UL << LPUART_LCR_WKCK_Pos )
#define LPUART_LCR_WKCK                         ( LPUART_LCR_WKCK_Msk )

#define LPUART_LCR_RXWKS_Pos                    ( 5U )
#define LPUART_LCR_RXWKS_Msk                    ( 0x3UL << LPUART_LCR_RXWKS_Pos )
#define LPUART_LCR_RXWKS                        ( LPUART_LCR_RXWKS_Msk )
#define LPUART_LCR_RXWKS_0                      ( 0x1UL << LPUART_LCR_RXWKS_Pos )
#define LPUART_LCR_RXWKS_1                      ( 0x2UL << LPUART_LCR_RXWKS_Pos )

#define LPUART_LCR_WLEN_Pos                     ( 4U )
#define LPUART_LCR_WLEN_Msk                     ( 0x1UL << LPUART_LCR_WLEN_Pos )
#define LPUART_LCR_WLEN                         ( LPUART_LCR_WLEN_Msk )

#define LPUART_LCR_STP2_Pos                     ( 3U )
#define LPUART_LCR_STP2_Msk                     ( 0x1UL << LPUART_LCR_STP2_Pos )
#define LPUART_LCR_STP2                         ( LPUART_LCR_STP2_Msk )

#define LPUART_LCR_EPS_Pos                      ( 2U )
#define LPUART_LCR_EPS_Msk                      ( 0x1UL << LPUART_LCR_EPS_Pos )
#define LPUART_LCR_EPS                          ( LPUART_LCR_EPS_Msk )

#define LPUART_LCR_SPS_Pos                      ( 1U )
#define LPUART_LCR_SPS_Msk                      ( 0x1UL << LPUART_LCR_SPS_Pos )
#define LPUART_LCR_SPS                          ( LPUART_LCR_SPS_Msk )

#define LPUART_LCR_PEN_Pos                      ( 0U )
#define LPUART_LCR_PEN_Msk                      ( 0x1UL << LPUART_LCR_PEN_Pos )
#define LPUART_LCR_PEN                          ( LPUART_LCR_PEN_Msk )


/***************  Bits definition for LPUART_CR register  ********************/

#define LPUART_CR_DMAEN_Pos                     ( 2U )
#define LPUART_CR_DMAEN_Msk                     ( 0x1UL << LPUART_CR_DMAEN_Pos )
#define LPUART_CR_DMAEN                         ( LPUART_CR_DMAEN_Msk )

#define LPUART_CR_TXE_Pos                       ( 1U )
#define LPUART_CR_TXE_Msk                       ( 0x1UL << LPUART_CR_TXE_Pos )
#define LPUART_CR_TXE                           ( LPUART_CR_TXE_Msk )

#define LPUART_CR_RXE_Pos                       ( 0U )
#define LPUART_CR_RXE_Msk                       ( 0x1UL << LPUART_CR_RXE_Pos )
#define LPUART_CR_RXE                           ( LPUART_CR_RXE_Msk )


/***************  Bits definition for LPUART_IBAUD register  *****************/

#define LPUART_IBAUD_RXSAM_Pos                  ( 8U )
#define LPUART_IBAUD_RXSAM_Msk                  ( 0xFFUL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM                      ( LPUART_IBAUD_RXSAM_Msk )
#define LPUART_IBAUD_RXSAM_0                    ( 0x1UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_1                    ( 0x2UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_2                    ( 0x4UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_3                    ( 0x8UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_4                    ( 0x10UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_5                    ( 0x20UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_6                    ( 0x40UL << LPUART_IBAUD_RXSAM_Pos )
#define LPUART_IBAUD_RXSAM_7                    ( 0x80UL << LPUART_IBAUD_RXSAM_Pos )

#define LPUART_IBAUD_IBAUD_Pos                  ( 0U )
#define LPUART_IBAUD_IBAUD_Msk                  ( 0xFFUL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD                      ( LPUART_IBAUD_IBAUD_Msk )
#define LPUART_IBAUD_IBAUD_0                    ( 0x1UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_1                    ( 0x2UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_2                    ( 0x4UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_3                    ( 0x8UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_4                    ( 0x10UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_5                    ( 0x20UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_6                    ( 0x40UL << LPUART_IBAUD_IBAUD_Pos )
#define LPUART_IBAUD_IBAUD_7                    ( 0x80UL << LPUART_IBAUD_IBAUD_Pos )


/***************  Bits definition for LPUART_FBAUD register  *****************/

#define LPUART_FBAUD_FBAUD_Pos                  ( 0U )
#define LPUART_FBAUD_FBAUD_Msk                  ( 0xFFFUL << LPUART_FBAUD_FBAUD_Pos )
#define LPUART_FBAUD_FBAUD                      ( LPUART_FBAUD_FBAUD_Msk )


/***************  Bits definition for LPUART_IE register  ********************/

#define LPUART_IE_STARTIE_Pos                   ( 9U )
#define LPUART_IE_STARTIE_Msk                   ( 0x1UL << LPUART_IE_STARTIE_Pos )
#define LPUART_IE_STARTIE                       ( LPUART_IE_STARTIE_Msk )

#define LPUART_IE_MATCHIE_Pos                   ( 8U )
#define LPUART_IE_MATCHIE_Msk                   ( 0x1UL << LPUART_IE_MATCHIE_Pos )
#define LPUART_IE_MATCHIE                       ( LPUART_IE_MATCHIE_Msk )

#define LPUART_IE_RXOVIE_Pos                    ( 5U )
#define LPUART_IE_RXOVIE_Msk                    ( 0x1UL << LPUART_IE_RXOVIE_Pos )
#define LPUART_IE_RXOVIE                        ( LPUART_IE_RXOVIE_Msk )

#define LPUART_IE_FEIE_Pos                      ( 4U )
#define LPUART_IE_FEIE_Msk                      ( 0x1UL << LPUART_IE_FEIE_Pos )
#define LPUART_IE_FEIE                          ( LPUART_IE_FEIE_Msk )

#define LPUART_IE_PEIE_Pos                      ( 3U )
#define LPUART_IE_PEIE_Msk                      ( 0x1UL << LPUART_IE_PEIE_Pos )
#define LPUART_IE_PEIE                          ( LPUART_IE_PEIE_Msk )

#define LPUART_IE_TXEIE_Pos                     ( 2U )
#define LPUART_IE_TXEIE_Msk                     ( 0x1UL << LPUART_IE_TXEIE_Pos )
#define LPUART_IE_TXEIE                         ( LPUART_IE_TXEIE_Msk )

#define LPUART_IE_TCIE_Pos                      ( 1U )
#define LPUART_IE_TCIE_Msk                      ( 0x1UL << LPUART_IE_TCIE_Pos )
#define LPUART_IE_TCIE                          ( LPUART_IE_TCIE_Msk )

#define LPUART_IE_RXIE_Pos                      ( 0U )
#define LPUART_IE_RXIE_Msk                      ( 0x1UL << LPUART_IE_RXIE_Pos )
#define LPUART_IE_RXIE                          ( LPUART_IE_RXIE_Msk )


/***************  Bits definition for LPUART_SR register  ********************/

#define LPUART_SR_TXE_Pos                       ( 10U )
#define LPUART_SR_TXE_Msk                       ( 0x1UL << LPUART_SR_TXE_Pos )
#define LPUART_SR_TXE                           ( LPUART_SR_TXE_Msk )

#define LPUART_SR_STARTIF_Pos                   ( 9U )
#define LPUART_SR_STARTIF_Msk                   ( 0x1UL << LPUART_SR_STARTIF_Pos )
#define LPUART_SR_STARTIF                       ( LPUART_SR_STARTIF_Msk )

#define LPUART_SR_MATCHIF_Pos                   ( 8U )
#define LPUART_SR_MATCHIF_Msk                   ( 0x1UL << LPUART_SR_MATCHIF_Pos )
#define LPUART_SR_MATCHIF                       ( LPUART_SR_MATCHIF_Msk )

#define LPUART_SR_TXOVF_Pos                     ( 7U )
#define LPUART_SR_TXOVF_Msk                     ( 0x1UL << LPUART_SR_TXOVF_Pos )
#define LPUART_SR_TXOVF                         ( LPUART_SR_TXOVF_Msk )

#define LPUART_SR_RXF_Pos                       ( 6U )
#define LPUART_SR_RXF_Msk                       ( 0x1UL << LPUART_SR_RXF_Pos )
#define LPUART_SR_RXF                           ( LPUART_SR_RXF_Msk )

#define LPUART_SR_RXOVIF_Pos                    ( 5U )
#define LPUART_SR_RXOVIF_Msk                    ( 0x1UL << LPUART_SR_RXOVIF_Pos )
#define LPUART_SR_RXOVIF                        ( LPUART_SR_RXOVIF_Msk )

#define LPUART_SR_FEIF_Pos                      ( 4U )
#define LPUART_SR_FEIF_Msk                      ( 0x1UL << LPUART_SR_FEIF_Pos )
#define LPUART_SR_FEIF                          ( LPUART_SR_FEIF_Msk )

#define LPUART_SR_PEIF_Pos                      ( 3U )
#define LPUART_SR_PEIF_Msk                      ( 0x1UL << LPUART_SR_PEIF_Pos )
#define LPUART_SR_PEIF                          ( LPUART_SR_PEIF_Msk )

#define LPUART_SR_TXEIF_Pos                     ( 2U )
#define LPUART_SR_TXEIF_Msk                     ( 0x1UL << LPUART_SR_TXEIF_Pos )
#define LPUART_SR_TXEIF                         ( LPUART_SR_TXEIF_Msk )

#define LPUART_SR_TCIF_Pos                      ( 1U )
#define LPUART_SR_TCIF_Msk                      ( 0x1UL << LPUART_SR_TCIF_Pos )
#define LPUART_SR_TCIF                          ( LPUART_SR_TCIF_Msk )

#define LPUART_SR_RXIF_Pos                      ( 0U )
#define LPUART_SR_RXIF_Msk                      ( 0x1UL << LPUART_SR_RXIF_Pos )
#define LPUART_SR_RXIF                          ( LPUART_SR_RXIF_Msk )


/***************  Bits definition for LPUART_ADDR register  ******************/

#define LPUART_ADDR_ADDR_Pos                    ( 0U )
#define LPUART_ADDR_ADDR_Msk                    ( 0xFFUL << LPUART_ADDR_ADDR_Pos )
#define LPUART_ADDR_ADDR                        ( LPUART_ADDR_ADDR_Msk )


/***************  Bits definition for WDT_LOAD register  *********************/

#define WDT_LOAD_LOAD_Pos                       ( 0U )
#define WDT_LOAD_LOAD_Msk                       ( 0xFFFFFFFFUL << WDT_LOAD_LOAD_Pos )
#define WDT_LOAD_LOAD                           ( WDT_LOAD_LOAD_Msk )


/***************  Bits definition for WDT_COUNT register  ********************/

#define WDT_COUNT_COUNT_Pos                     ( 0U )
#define WDT_COUNT_COUNT_Msk                     ( 0xFFFFFFFFUL << WDT_COUNT_COUNT_Pos )
#define WDT_COUNT_COUNT                         ( WDT_COUNT_COUNT_Msk )


/***************  Bits definition for WDT_CTRL register  *********************/

#define WDT_CTRL_EN_Pos                         ( 7U )
#define WDT_CTRL_EN_Msk                         ( 0x1UL << WDT_CTRL_EN_Pos )
#define WDT_CTRL_EN                             ( WDT_CTRL_EN_Msk )

#define WDT_CTRL_MODE_Pos                       ( 6U )
#define WDT_CTRL_MODE_Msk                       ( 0x1UL << WDT_CTRL_MODE_Pos )
#define WDT_CTRL_MODE                           ( WDT_CTRL_MODE_Msk )

#define WDT_CTRL_INTEN_Pos                      ( 4U )
#define WDT_CTRL_INTEN_Msk                      ( 0x1UL << WDT_CTRL_INTEN_Pos )
#define WDT_CTRL_INTEN                          ( WDT_CTRL_INTEN_Msk )

#define WDT_CTRL_DIVISOR_Pos                    ( 0U )
#define WDT_CTRL_DIVISOR_Msk                    ( 0x7UL << WDT_CTRL_DIVISOR_Pos )
#define WDT_CTRL_DIVISOR                        ( WDT_CTRL_DIVISOR_Msk )
#define WDT_CTRL_DIVISOR_0                      ( 0x1UL << WDT_CTRL_DIVISOR_Pos )
#define WDT_CTRL_DIVISOR_1                      ( 0x2UL << WDT_CTRL_DIVISOR_Pos )
#define WDT_CTRL_DIVISOR_2                      ( 0x4UL << WDT_CTRL_DIVISOR_Pos )


/***************  Bits definition for WDT_FEED register  *********************/

#define WDT_FEED_FEED_Pos                       ( 0U )
#define WDT_FEED_FEED_Msk                       ( 0xFFFFFFFFUL << WDT_FEED_FEED_Pos )
#define WDT_FEED_FEED                           ( WDT_FEED_FEED_Msk )


/***************  Bits definition for WDT_INTCLRTIME register  ***************/

#define WDT_INTCLRTIME_INTCLRT_Pos              ( 0U )
#define WDT_INTCLRTIME_INTCLRT_Msk              ( 0xFFFFUL << WDT_INTCLRTIME_INTCLRT_Pos )
#define WDT_INTCLRTIME_INTCLRT                  ( WDT_INTCLRTIME_INTCLRT_Msk )


/***************  Bits definition for WDT_RIS register  **********************/

#define WDT_RIS_WDTRIS_Pos                      ( 0U )
#define WDT_RIS_WDTRIS_Msk                      ( 0x1UL << WDT_RIS_WDTRIS_Pos )
#define WDT_RIS_WDTRIS                          ( WDT_RIS_WDTRIS_Msk )


/***************  Bits definition for I2S_DR register  ***********************/

#define I2S_DR_I2SDR_Pos                        ( 0U )
#define I2S_DR_I2SDR_Msk                        ( 0xFFFFFFFFUL << I2S_DR_I2SDR_Pos )
#define I2S_DR_I2SDR                            ( I2S_DR_I2SDR_Msk )


/***************  Bits definition for I2S_CR register  ***********************/

#define I2S_CR_I2SE_Pos                         ( 10U )
#define I2S_CR_I2SE_Msk                         ( 0x1UL << I2S_CR_I2SE_Pos )
#define I2S_CR_I2SE                             ( I2S_CR_I2SE_Msk )

#define I2S_CR_I2SOPMOD_Pos                     ( 8U )
#define I2S_CR_I2SOPMOD_Msk                     ( 0x3UL << I2S_CR_I2SOPMOD_Pos )
#define I2S_CR_I2SOPMOD                         ( I2S_CR_I2SOPMOD_Msk )
#define I2S_CR_I2SOPMOD_0                       ( 0x1UL << I2S_CR_I2SOPMOD_Pos )
#define I2S_CR_I2SOPMOD_1                       ( 0x2UL << I2S_CR_I2SOPMOD_Pos )

#define I2S_CR_PCMSMOD_Pos                      ( 7U )
#define I2S_CR_PCMSMOD_Msk                      ( 0x1UL << I2S_CR_PCMSMOD_Pos )
#define I2S_CR_PCMSMOD                          ( I2S_CR_PCMSMOD_Msk )

#define I2S_CR_I2SSTD_Pos                       ( 4U )
#define I2S_CR_I2SSTD_Msk                       ( 0x3UL << I2S_CR_I2SSTD_Pos )
#define I2S_CR_I2SSTD                           ( I2S_CR_I2SSTD_Msk )
#define I2S_CR_I2SSTD_0                         ( 0x1UL << I2S_CR_I2SSTD_Pos )
#define I2S_CR_I2SSTD_1                         ( 0x2UL << I2S_CR_I2SSTD_Pos )

#define I2S_CR_CKPL_Pos                         ( 3U )
#define I2S_CR_CKPL_Msk                         ( 0x1UL << I2S_CR_CKPL_Pos )
#define I2S_CR_CKPL                             ( I2S_CR_CKPL_Msk )

#define I2S_CR_DTLEN_Pos                        ( 1U )
#define I2S_CR_DTLEN_Msk                        ( 0x3UL << I2S_CR_DTLEN_Pos )
#define I2S_CR_DTLEN                            ( I2S_CR_DTLEN_Msk )
#define I2S_CR_DTLEN_0                          ( 0x1UL << I2S_CR_DTLEN_Pos )
#define I2S_CR_DTLEN_1                          ( 0x2UL << I2S_CR_DTLEN_Pos )

#define I2S_CR_CHLEN_Pos                        ( 0U )
#define I2S_CR_CHLEN_Msk                        ( 0x1UL << I2S_CR_CHLEN_Pos )
#define I2S_CR_CHLEN                            ( I2S_CR_CHLEN_Msk )


/***************  Bits definition for I2S_PR register  ***********************/

#define I2S_PR_MCKOE_Pos                        ( 10U )
#define I2S_PR_MCKOE_Msk                        ( 0x1UL << I2S_PR_MCKOE_Pos )
#define I2S_PR_MCKOE                            ( I2S_PR_MCKOE_Msk )

#define I2S_PR_OF_Pos                           ( 9U )
#define I2S_PR_OF_Msk                           ( 0x1UL << I2S_PR_OF_Pos )
#define I2S_PR_OF                               ( I2S_PR_OF_Msk )

#define I2S_PR_DIV_Pos                          ( 0U )
#define I2S_PR_DIV_Msk                          ( 0x1FFUL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV                              ( I2S_PR_DIV_Msk )
#define I2S_PR_DIV_0                            ( 0x1UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_1                            ( 0x2UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_2                            ( 0x4UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_3                            ( 0x8UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_4                            ( 0x10UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_5                            ( 0x20UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_6                            ( 0x40UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_7                            ( 0x80UL << I2S_PR_DIV_Pos )
#define I2S_PR_DIV_8                            ( 0x100UL << I2S_PR_DIV_Pos )


/***************  Bits definition for I2S_DIER register  *********************/

#define I2S_DIER_TBEIE_Pos                      ( 7U )
#define I2S_DIER_TBEIE_Msk                      ( 0x1UL << I2S_DIER_TBEIE_Pos )
#define I2S_DIER_TBEIE                          ( I2S_DIER_TBEIE_Msk )

#define I2S_DIER_RBNEIE_Pos                     ( 6U )
#define I2S_DIER_RBNEIE_Msk                     ( 0x1UL << I2S_DIER_RBNEIE_Pos )
#define I2S_DIER_RBNEIE                         ( I2S_DIER_RBNEIE_Msk )

#define I2S_DIER_ERRIE_Pos                      ( 5U )
#define I2S_DIER_ERRIE_Msk                      ( 0x1UL << I2S_DIER_ERRIE_Pos )
#define I2S_DIER_ERRIE                          ( I2S_DIER_ERRIE_Msk )

#define I2S_DIER_TXDMATEN_Pos                   ( 1U )
#define I2S_DIER_TXDMATEN_Msk                   ( 0x1UL << I2S_DIER_TXDMATEN_Pos )
#define I2S_DIER_TXDMATEN                       ( I2S_DIER_TXDMATEN_Msk )

#define I2S_DIER_RXDMAREN_Pos                   ( 0U )
#define I2S_DIER_RXDMAREN_Msk                   ( 0x1UL << I2S_DIER_RXDMAREN_Pos )
#define I2S_DIER_RXDMAREN                       ( I2S_DIER_RXDMAREN_Msk )


/***************  Bits definition for I2S_SR register  ***********************/

#define I2S_SR_FERR_Pos                         ( 8U )
#define I2S_SR_FERR_Msk                         ( 0x1UL << I2S_SR_FERR_Pos )
#define I2S_SR_FERR                             ( I2S_SR_FERR_Msk )

#define I2S_SR_TRANS_Pos                        ( 7U )
#define I2S_SR_TRANS_Msk                        ( 0x1UL << I2S_SR_TRANS_Pos )
#define I2S_SR_TRANS                            ( I2S_SR_TRANS_Msk )

#define I2S_SR_RXORERR_Pos                      ( 6U )
#define I2S_SR_RXORERR_Msk                      ( 0x1UL << I2S_SR_RXORERR_Pos )
#define I2S_SR_RXORERR                          ( I2S_SR_RXORERR_Msk )

#define I2S_SR_TXURERR_Pos                      ( 3U )
#define I2S_SR_TXURERR_Msk                      ( 0x1UL << I2S_SR_TXURERR_Pos )
#define I2S_SR_TXURERR                          ( I2S_SR_TXURERR_Msk )

#define I2S_SR_I2SCH_Pos                        ( 2U )
#define I2S_SR_I2SCH_Msk                        ( 0x1UL << I2S_SR_I2SCH_Pos )
#define I2S_SR_I2SCH                            ( I2S_SR_I2SCH_Msk )

#define I2S_SR_TXBE_Pos                         ( 1U )
#define I2S_SR_TXBE_Msk                         ( 0x1UL << I2S_SR_TXBE_Pos )
#define I2S_SR_TXBE                             ( I2S_SR_TXBE_Msk )

#define I2S_SR_RXBNE_Pos                        ( 0U )
#define I2S_SR_RXBNE_Msk                        ( 0x1UL << I2S_SR_RXBNE_Pos )
#define I2S_SR_RXBNE                            ( I2S_SR_RXBNE_Msk )



/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/


/***************  Bits definition for EFC_CTRL register  *********************/

#define EFC_CTRL_RDP1PROT_Pos                   ( 19U )
#define EFC_CTRL_RDP1PROT_Msk                   ( 0x1UL << EFC_CTRL_RDP1PROT_Pos )
#define EFC_CTRL_RDP1PROT                       ( EFC_CTRL_RDP1PROT_Msk )

#define EFC_CTRL_SECPROT_Pos                    ( 18U )
#define EFC_CTRL_SECPROT_Msk                    ( 0x1UL << EFC_CTRL_SECPROT_Pos )
#define EFC_CTRL_SECPROT                        ( EFC_CTRL_SECPROT_Msk )

#define EFC_CTRL_ONEROWPRMODE_Pos               ( 16U )
#define EFC_CTRL_ONEROWPRMODE_Msk               ( 0x1UL << EFC_CTRL_ONEROWPRMODE_Pos )
#define EFC_CTRL_ONEROWPRMODE                   ( EFC_CTRL_ONEROWPRMODE_Msk )

#define EFC_CTRL_RECALLREADMODE_Pos             ( 15U )
#define EFC_CTRL_RECALLREADMODE_Msk             ( 0x1UL << EFC_CTRL_RECALLREADMODE_Pos )
#define EFC_CTRL_RECALLREADMODE                 ( EFC_CTRL_RECALLREADMODE_Msk )

#define EFC_CTRL_EWCNTEN_Pos                    ( 14U )
#define EFC_CTRL_EWCNTEN_Msk                    ( 0x1UL << EFC_CTRL_EWCNTEN_Pos )
#define EFC_CTRL_EWCNTEN                        ( EFC_CTRL_EWCNTEN_Msk )

#define EFC_CTRL_RESETB_Pos                     ( 13U )
#define EFC_CTRL_RESETB_Msk                     ( 0x1UL << EFC_CTRL_RESETB_Pos )
#define EFC_CTRL_RESETB                         ( EFC_CTRL_RESETB_Msk )

#define EFC_CTRL_SLEEP_Pos                      ( 12U )
#define EFC_CTRL_SLEEP_Msk                      ( 0x1UL << EFC_CTRL_SLEEP_Pos )
#define EFC_CTRL_SLEEP                          ( EFC_CTRL_SLEEP_Msk )

#define EFC_CTRL_RDWAIT_Pos                     ( 7U )
#define EFC_CTRL_RDWAIT_Msk                     ( 0x1FUL << EFC_CTRL_RDWAIT_Pos )
#define EFC_CTRL_RDWAIT                         ( EFC_CTRL_RDWAIT_Msk )
#define EFC_CTRL_RDWAIT_0                       ( 0x1UL << EFC_CTRL_RDWAIT_Pos )
#define EFC_CTRL_RDWAIT_1                       ( 0x2UL << EFC_CTRL_RDWAIT_Pos )
#define EFC_CTRL_RDWAIT_2                       ( 0x4UL << EFC_CTRL_RDWAIT_Pos )
#define EFC_CTRL_RDWAIT_3                       ( 0x8UL << EFC_CTRL_RDWAIT_Pos )
#define EFC_CTRL_RDWAIT_4                       ( 0x10UL << EFC_CTRL_RDWAIT_Pos )

#define EFC_CTRL_FTOEN_Pos                      ( 6U )
#define EFC_CTRL_FTOEN_Msk                      ( 0x1UL << EFC_CTRL_FTOEN_Pos )
#define EFC_CTRL_FTOEN                          ( EFC_CTRL_FTOEN_Msk )

#define EFC_CTRL_ACEN_Pos                       ( 5U )
#define EFC_CTRL_ACEN_Msk                       ( 0x1UL << EFC_CTRL_ACEN_Pos )
#define EFC_CTRL_ACEN                           ( EFC_CTRL_ACEN_Msk )

#define EFC_CTRL_PEVSTART_Pos                   ( 4U )
#define EFC_CTRL_PEVSTART_Msk                   ( 0x1UL << EFC_CTRL_PEVSTART_Pos )
#define EFC_CTRL_PEVSTART                       ( EFC_CTRL_PEVSTART_Msk )

#define EFC_CTRL_WRVEN_Pos                      ( 3U )
#define EFC_CTRL_WRVEN_Msk                      ( 0x1UL << EFC_CTRL_WRVEN_Pos )
#define EFC_CTRL_WRVEN                          ( EFC_CTRL_WRVEN_Msk )

#define EFC_CTRL_CHIPERASEMODE_Pos              ( 2U )
#define EFC_CTRL_CHIPERASEMODE_Msk              ( 0x1UL << EFC_CTRL_CHIPERASEMODE_Pos )
#define EFC_CTRL_CHIPERASEMODE                  ( EFC_CTRL_CHIPERASEMODE_Msk )

#define EFC_CTRL_PAGEERASEMODE_Pos              ( 1U )
#define EFC_CTRL_PAGEERASEMODE_Msk              ( 0x1UL << EFC_CTRL_PAGEERASEMODE_Pos )
#define EFC_CTRL_PAGEERASEMODE                  ( EFC_CTRL_PAGEERASEMODE_Msk )

#define EFC_CTRL_WRITEMODE_Pos                  ( 0U )
#define EFC_CTRL_WRITEMODE_Msk                  ( 0x1UL << EFC_CTRL_WRITEMODE_Pos )
#define EFC_CTRL_WRITEMODE                      ( EFC_CTRL_WRITEMODE_Msk )


/***************  Bits definition for EFC_SEC register  **********************/

#define EFC_SEC_WRITELOCKSER_Pos                ( 0U )
#define EFC_SEC_WRITELOCKSER_Msk                ( 0xFFFFFFFFUL << EFC_SEC_WRITELOCKSER_Pos )
#define EFC_SEC_WRITELOCKSER                    ( EFC_SEC_WRITELOCKSER_Msk )


/***************  Bits definition for EFC_ADCT register  *********************/

#define EFC_ADCT_ADCT_Pos                       ( 0U )
#define EFC_ADCT_ADCT_Msk                       ( 0x1FFFFUL << EFC_ADCT_ADCT_Pos )
#define EFC_ADCT_ADCT                           ( EFC_ADCT_ADCT_Msk )


/***************  Bits definition for EFC_ERTO register  *********************/

#define EFC_ERTO_ERSD_Pos                       ( 0U )
#define EFC_ERTO_ERSD_Msk                       ( 0x7FFFUL << EFC_ERTO_ERSD_Pos )
#define EFC_ERTO_ERSD                           ( EFC_ERTO_ERSD_Msk )


/***************  Bits definition for EFC_WRTO register  *********************/

#define EFC_WRTO_WRCYCLE_Pos                    ( 0U )
#define EFC_WRTO_WRCYCLE_Msk                    ( 0xFFUL << EFC_WRTO_WRCYCLE_Pos )
#define EFC_WRTO_WRCYCLE                        ( EFC_WRTO_WRCYCLE_Msk )


/***************  Bits definition for EFC_STATUS register  *******************/

#define EFC_STATUS_TBIT_Pos                     ( 17U )
#define EFC_STATUS_TBIT_Msk                     ( 0x1UL << EFC_STATUS_TBIT_Pos )
#define EFC_STATUS_TBIT                         ( EFC_STATUS_TBIT_Msk )

#define EFC_STATUS_BUSY_Pos                     ( 16U )
#define EFC_STATUS_BUSY_Msk                     ( 0x1UL << EFC_STATUS_BUSY_Pos )
#define EFC_STATUS_BUSY                         ( EFC_STATUS_BUSY_Msk )

#define EFC_STATUS_REMAPNVR_Pos                 ( 14U )
#define EFC_STATUS_REMAPNVR_Msk                 ( 0x1UL << EFC_STATUS_REMAPNVR_Pos )
#define EFC_STATUS_REMAPNVR                     ( EFC_STATUS_REMAPNVR_Msk )

#define EFC_STATUS_RDP1EN_Pos                   ( 13U )
#define EFC_STATUS_RDP1EN_Msk                   ( 0x1UL << EFC_STATUS_RDP1EN_Pos )
#define EFC_STATUS_RDP1EN                       ( EFC_STATUS_RDP1EN_Msk )

#define EFC_STATUS_ROMJTAGDIS_Pos               ( 12U )
#define EFC_STATUS_ROMJTAGDIS_Msk               ( 0x1UL << EFC_STATUS_ROMJTAGDIS_Pos )
#define EFC_STATUS_ROMJTAGDIS                   ( EFC_STATUS_ROMJTAGDIS_Msk )

#define EFC_STATUS_SECVALID_Pos                 ( 11U )
#define EFC_STATUS_SECVALID_Msk                 ( 0x1UL << EFC_STATUS_SECVALID_Pos )
#define EFC_STATUS_SECVALID                     ( EFC_STATUS_SECVALID_Msk )

#define EFC_STATUS_WRPEN_Pos                    ( 10U )
#define EFC_STATUS_WRPEN_Msk                    ( 0x1UL << EFC_STATUS_WRPEN_Pos )
#define EFC_STATUS_WRPEN                        ( EFC_STATUS_WRPEN_Msk )

#define EFC_STATUS_PCROPEN_Pos                  ( 9U )
#define EFC_STATUS_PCROPEN_Msk                  ( 0x1UL << EFC_STATUS_PCROPEN_Pos )
#define EFC_STATUS_PCROPEN                      ( EFC_STATUS_PCROPEN_Msk )

#define EFC_STATUS_FLASHCRYPT_Pos               ( 8U )
#define EFC_STATUS_FLASHCRYPT_Msk               ( 0x1UL << EFC_STATUS_FLASHCRYPT_Pos )
#define EFC_STATUS_FLASHCRYPT                   ( EFC_STATUS_FLASHCRYPT_Msk )

#define EFC_STATUS_JTAGDISABLE_Pos              ( 7U )
#define EFC_STATUS_JTAGDISABLE_Msk              ( 0x1UL << EFC_STATUS_JTAGDISABLE_Pos )
#define EFC_STATUS_JTAGDISABLE                  ( EFC_STATUS_JTAGDISABLE_Msk )

#define EFC_STATUS_DFTDISABLE_Pos               ( 6U )
#define EFC_STATUS_DFTDISABLE_Msk               ( 0x1UL << EFC_STATUS_DFTDISABLE_Pos )
#define EFC_STATUS_DFTDISABLE                   ( EFC_STATUS_DFTDISABLE_Msk )

#define EFC_STATUS_NVR4LOCK_Pos                 ( 4U )
#define EFC_STATUS_NVR4LOCK_Msk                 ( 0x1UL << EFC_STATUS_NVR4LOCK_Pos )
#define EFC_STATUS_NVR4LOCK                     ( EFC_STATUS_NVR4LOCK_Msk )

#define EFC_STATUS_NVR3LOCK_Pos                 ( 3U )
#define EFC_STATUS_NVR3LOCK_Msk                 ( 0x1UL << EFC_STATUS_NVR3LOCK_Pos )
#define EFC_STATUS_NVR3LOCK                     ( EFC_STATUS_NVR3LOCK_Msk )

#define EFC_STATUS_NVR2LOCK_Pos                 ( 2U )
#define EFC_STATUS_NVR2LOCK_Msk                 ( 0x1UL << EFC_STATUS_NVR2LOCK_Pos )
#define EFC_STATUS_NVR2LOCK                     ( EFC_STATUS_NVR2LOCK_Msk )

#define EFC_STATUS_NVR1LOCK_Pos                 ( 1U )
#define EFC_STATUS_NVR1LOCK_Msk                 ( 0x1UL << EFC_STATUS_NVR1LOCK_Pos )
#define EFC_STATUS_NVR1LOCK                     ( EFC_STATUS_NVR1LOCK_Msk )

#define EFC_STATUS_EFLASHREADY_Pos              ( 0U )
#define EFC_STATUS_EFLASHREADY_Msk              ( 0x1UL << EFC_STATUS_EFLASHREADY_Pos )
#define EFC_STATUS_EFLASHREADY                  ( EFC_STATUS_EFLASHREADY_Msk )


/***************  Bits definition for EFC_INTSTATUS register  ****************/

#define EFC_INTSTATUS_RDERR_Pos                 ( 10U )
#define EFC_INTSTATUS_RDERR_Msk                 ( 0x1UL << EFC_INTSTATUS_RDERR_Pos )
#define EFC_INTSTATUS_RDERR                     ( EFC_INTSTATUS_RDERR_Msk )

#define EFC_INTSTATUS_ERWRTOERR_Pos             ( 9U )
#define EFC_INTSTATUS_ERWRTOERR_Msk             ( 0x1UL << EFC_INTSTATUS_ERWRTOERR_Pos )
#define EFC_INTSTATUS_ERWRTOERR                 ( EFC_INTSTATUS_ERWRTOERR_Msk )

#define EFC_INTSTATUS_WRPERR_Pos                ( 8U )
#define EFC_INTSTATUS_WRPERR_Msk                ( 0x1UL << EFC_INTSTATUS_WRPERR_Pos )
#define EFC_INTSTATUS_WRPERR                    ( EFC_INTSTATUS_WRPERR_Msk )

#define EFC_INTSTATUS_PCROPRDERR_Pos            ( 7U )
#define EFC_INTSTATUS_PCROPRDERR_Msk            ( 0x1UL << EFC_INTSTATUS_PCROPRDERR_Pos )
#define EFC_INTSTATUS_PCROPRDERR                ( EFC_INTSTATUS_PCROPRDERR_Msk )

#define EFC_INTSTATUS_NVRERR_Pos                ( 5U )
#define EFC_INTSTATUS_NVRERR_Msk                ( 0x1UL << EFC_INTSTATUS_NVRERR_Pos )
#define EFC_INTSTATUS_NVRERR                    ( EFC_INTSTATUS_NVRERR_Msk )

#define EFC_INTSTATUS_PWRVFERR_Pos              ( 4U )
#define EFC_INTSTATUS_PWRVFERR_Msk              ( 0x1UL << EFC_INTSTATUS_PWRVFERR_Pos )
#define EFC_INTSTATUS_PWRVFERR                  ( EFC_INTSTATUS_PWRVFERR_Msk )

#define EFC_INTSTATUS_ADCTERR_Pos               ( 3U )
#define EFC_INTSTATUS_ADCTERR_Msk               ( 0x1UL << EFC_INTSTATUS_ADCTERR_Pos )
#define EFC_INTSTATUS_ADCTERR                   ( EFC_INTSTATUS_ADCTERR_Msk )

#define EFC_INTSTATUS_PERVFDONE_Pos             ( 2U )
#define EFC_INTSTATUS_PERVFDONE_Msk             ( 0x1UL << EFC_INTSTATUS_PERVFDONE_Pos )
#define EFC_INTSTATUS_PERVFDONE                 ( EFC_INTSTATUS_PERVFDONE_Msk )

#define EFC_INTSTATUS_PERVFERR_Pos              ( 1U )
#define EFC_INTSTATUS_PERVFERR_Msk              ( 0x1UL << EFC_INTSTATUS_PERVFERR_Pos )
#define EFC_INTSTATUS_PERVFERR                  ( EFC_INTSTATUS_PERVFERR_Msk )

#define EFC_INTSTATUS_ERWRDONE_Pos             ( 0U )
#define EFC_INTSTATUS_ERWRDONE_Msk             ( 0x1UL << EFC_INTSTATUS_ERWRDONE_Pos )
#define EFC_INTSTATUS_ERWRDONE                 ( EFC_INTSTATUS_ERWRDONE_Msk )


/***************  Bits definition for EFC_INEN register  *********************/

#define EFC_INEN_RDERRIE_Pos                    ( 10U )
#define EFC_INEN_RDERRIE_Msk                    ( 0x1UL << EFC_INEN_RDERRIE_Pos )
#define EFC_INEN_RDERRIE                        ( EFC_INEN_RDERRIE_Msk )

#define EFC_INEN_ERWRTOIE_Pos                   ( 9U )
#define EFC_INEN_ERWRTOIE_Msk                   ( 0x1UL << EFC_INEN_ERWRTOIE_Pos )
#define EFC_INEN_ERWRTOIE                       ( EFC_INEN_ERWRTOIE_Msk )

#define EFC_INEN_WRPERRIE_Pos                   ( 8U )
#define EFC_INEN_WRPERRIE_Msk                   ( 0x1UL << EFC_INEN_WRPERRIE_Pos )
#define EFC_INEN_WRPERRIE                       ( EFC_INEN_WRPERRIE_Msk )

#define EFC_INEN_PCROPRDERRIE_Pos               ( 7U )
#define EFC_INEN_PCROPRDERRIE_Msk               ( 0x1UL << EFC_INEN_PCROPRDERRIE_Pos )
#define EFC_INEN_PCROPRDERRIE                   ( EFC_INEN_PCROPRDERRIE_Msk )

#define EFC_INEN_NVRERRIE_Pos                   ( 5U )
#define EFC_INEN_NVRERRIE_Msk                   ( 0x1UL << EFC_INEN_NVRERRIE_Pos )
#define EFC_INEN_NVRERRIE                       ( EFC_INEN_NVRERRIE_Msk )

#define EFC_INEN_PWRVFIE_Pos                    ( 4U )
#define EFC_INEN_PWRVFIE_Msk                    ( 0x1UL << EFC_INEN_PWRVFIE_Pos )
#define EFC_INEN_PWRVFIE                        ( EFC_INEN_PWRVFIE_Msk )

#define EFC_INEN_ADCTIE_Pos                     ( 3U )
#define EFC_INEN_ADCTIE_Msk                     ( 0x1UL << EFC_INEN_ADCTIE_Pos )
#define EFC_INEN_ADCTIE                         ( EFC_INEN_ADCTIE_Msk )

#define EFC_INEN_PERVFDONEIE_Pos                ( 2U )
#define EFC_INEN_PERVFDONEIE_Msk                ( 0x1UL << EFC_INEN_PERVFDONEIE_Pos )
#define EFC_INEN_PERVFDONEIE                    ( EFC_INEN_PERVFDONEIE_Msk )

#define EFC_INEN_PERVFIE_Pos                    ( 1U )
#define EFC_INEN_PERVFIE_Msk                    ( 0x1UL << EFC_INEN_PERVFIE_Pos )
#define EFC_INEN_PERVFIE                        ( EFC_INEN_PERVFIE_Msk )

#define EFC_INEN_ERDONEIE_Pos                   ( 0U )
#define EFC_INEN_ERDONEIE_Msk                   ( 0x1UL << EFC_INEN_ERDONEIE_Pos )
#define EFC_INEN_ERDONEIE                       ( EFC_INEN_ERDONEIE_Msk )


/***************  Bits definition for EFC_EDCTRL register  *******************/

#define EFC_EDCTRL_EDCTRLSECDATA_Pos            ( 16U )
#define EFC_EDCTRL_EDCTRLSECDATA_Msk            ( 0xFFFFUL << EFC_EDCTRL_EDCTRLSECDATA_Pos )
#define EFC_EDCTRL_EDCTRLSECDATA                ( EFC_EDCTRL_EDCTRLSECDATA_Msk )

#define EFC_EDCTRL_FLASHDATAEDECEN_Pos          ( 1U )
#define EFC_EDCTRL_FLASHDATAEDECEN_Msk          ( 0x1UL << EFC_EDCTRL_FLASHDATAEDECEN_Pos )
#define EFC_EDCTRL_FLASHDATAEDECEN              ( EFC_EDCTRL_FLASHDATAEDECEN_Msk )

#define EFC_EDCTRL_EDSEL_Pos                    ( 0U )
#define EFC_EDCTRL_EDSEL_Msk                    ( 0x1UL << EFC_EDCTRL_EDSEL_Pos )
#define EFC_EDCTRL_EDSEL                        ( EFC_EDCTRL_EDSEL_Msk )


/***************  Bits definition for EFC_TRIM0 register  ********************/

#define EFC_TRIM0_CONFIGDATA0_Pos               ( 0U )
#define EFC_TRIM0_CONFIGDATA0_Msk               ( 0xFFFFFFFFUL << EFC_TRIM0_CONFIGDATA0_Pos )
#define EFC_TRIM0_CONFIGDATA0                   ( EFC_TRIM0_CONFIGDATA0_Msk )


/***************  Bits definition for EFC_TRIM1 register  ********************/

#define EFC_TRIM1_CONFIGDATA1_Pos               ( 0U )
#define EFC_TRIM1_CONFIGDATA1_Msk               ( 0xFFFFFFFFUL << EFC_TRIM1_CONFIGDATA1_Pos )
#define EFC_TRIM1_CONFIGDATA1                   ( EFC_TRIM1_CONFIGDATA1_Msk )


/***************  Bits definition for EFC_TRIM2 register  ********************/

#define EFC_TRIM2_CONFIGDATA2_Pos               ( 0U )
#define EFC_TRIM2_CONFIGDATA2_Msk               ( 0xFFFFFFFFUL << EFC_TRIM2_CONFIGDATA2_Pos )
#define EFC_TRIM2_CONFIGDATA2                   ( EFC_TRIM2_CONFIGDATA2_Msk )


/***************  Bits definition for EFC_FF_DEC register  *******************/

#define EFC_FF_DEC_FFVALUE_Pos                  ( 0U )
#define EFC_FF_DEC_FFVALUE_Msk                  ( 0xFFFFFFFFUL << EFC_FF_DEC_FFVALUE_Pos )
#define EFC_FF_DEC_FFVALUE                      ( EFC_FF_DEC_FFVALUE_Msk )


/***************  Bits definition for EFC_MEMDENSITY register  ***************/

#define EFC_MEMDENSITY_SRAMDENSITY_Pos          ( 16U )
#define EFC_MEMDENSITY_SRAMDENSITY_Msk          ( 0xFFFFUL << EFC_MEMDENSITY_SRAMDENSITY_Pos )
#define EFC_MEMDENSITY_SRAMDENSITY              ( EFC_MEMDENSITY_SRAMDENSITY_Msk )

#define EFC_MEMDENSITY_FLASHDENSITY_Pos         ( 0U )
#define EFC_MEMDENSITY_FLASHDENSITY_Msk         ( 0xFFFFUL << EFC_MEMDENSITY_FLASHDENSITY_Pos )
#define EFC_MEMDENSITY_FLASHDENSITY             ( EFC_MEMDENSITY_FLASHDENSITY_Msk )


/***************  Bits definition for EFC_IPCKEN register  *******************/

#define EFC_IPCKEN_CLKEN_Pos                    ( 0U )
#define EFC_IPCKEN_CLKEN_Msk                    ( 0xFFFFFFFFUL << EFC_IPCKEN_CLKEN_Pos )
#define EFC_IPCKEN_CLKEN                        ( EFC_IPCKEN_CLKEN_Msk )


/***************  Bits definition for EFC_PCROP_AREAA register  **************/

#define EFC_PCROP_AREAA_PCROP1AEND_Pos          ( 16U )
#define EFC_PCROP_AREAA_PCROP1AEND_Msk          ( 0xFFUL << EFC_PCROP_AREAA_PCROP1AEND_Pos )
#define EFC_PCROP_AREAA_PCROP1AEND              ( EFC_PCROP_AREAA_PCROP1AEND_Msk )

#define EFC_PCROP_AREAA_PCROP1ASTRT_Pos         ( 0U )
#define EFC_PCROP_AREAA_PCROP1ASTRT_Msk         ( 0xFFUL << EFC_PCROP_AREAA_PCROP1ASTRT_Pos )
#define EFC_PCROP_AREAA_PCROP1ASTRT             ( EFC_PCROP_AREAA_PCROP1ASTRT_Msk )


/***************  Bits definition for EFC_PCROP_AREAB register  **************/

#define EFC_PCROP_AREAB_PCROP1BEND_Pos          ( 16U )
#define EFC_PCROP_AREAB_PCROP1BEND_Msk          ( 0xFFUL << EFC_PCROP_AREAB_PCROP1BEND_Pos )
#define EFC_PCROP_AREAB_PCROP1BEND              ( EFC_PCROP_AREAB_PCROP1BEND_Msk )

#define EFC_PCROP_AREAB_PCROP1BSTRT_Pos         ( 0U )
#define EFC_PCROP_AREAB_PCROP1BSTRT_Msk         ( 0xFFUL << EFC_PCROP_AREAB_PCROP1BSTRT_Pos )
#define EFC_PCROP_AREAB_PCROP1BSTRT             ( EFC_PCROP_AREAB_PCROP1BSTRT_Msk )


/***************  Bits definition for EFC_WRP_AREAA register  ****************/

#define EFC_WRP_AREAA_WRP1AEND_Pos              ( 16U )
#define EFC_WRP_AREAA_WRP1AEND_Msk              ( 0x7FUL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND                  ( EFC_WRP_AREAA_WRP1AEND_Msk )
#define EFC_WRP_AREAA_WRP1AEND_0                ( 0x1UL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND_1                ( 0x2UL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND_2                ( 0x4UL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND_3                ( 0x8UL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND_4                ( 0x10UL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND_5                ( 0x20UL << EFC_WRP_AREAA_WRP1AEND_Pos )
#define EFC_WRP_AREAA_WRP1AEND_6                ( 0x40UL << EFC_WRP_AREAA_WRP1AEND_Pos )

#define EFC_WRP_AREAA_WRP1ASTRT_Pos             ( 0U )
#define EFC_WRP_AREAA_WRP1ASTRT_Msk             ( 0x7FUL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT                 ( EFC_WRP_AREAA_WRP1ASTRT_Msk )
#define EFC_WRP_AREAA_WRP1ASTRT_0               ( 0x1UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT_1               ( 0x2UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT_2               ( 0x4UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT_3               ( 0x8UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT_4               ( 0x10UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT_5               ( 0x20UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )
#define EFC_WRP_AREAA_WRP1ASTRT_6               ( 0x40UL << EFC_WRP_AREAA_WRP1ASTRT_Pos )


/***************  Bits definition for EFC_WRP_AREAB register  ****************/

#define EFC_WRP_AREAB_WRP1BEND_Pos              ( 16U )
#define EFC_WRP_AREAB_WRP1BEND_Msk              ( 0x7FUL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND                  ( EFC_WRP_AREAB_WRP1BEND_Msk )
#define EFC_WRP_AREAB_WRP1BEND_0                ( 0x1UL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND_1                ( 0x2UL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND_2                ( 0x4UL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND_3                ( 0x8UL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND_4                ( 0x10UL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND_5                ( 0x20UL << EFC_WRP_AREAB_WRP1BEND_Pos )
#define EFC_WRP_AREAB_WRP1BEND_6                ( 0x40UL << EFC_WRP_AREAB_WRP1BEND_Pos )

#define EFC_WRP_AREAB_WRP1BSTRT_Pos             ( 0U )
#define EFC_WRP_AREAB_WRP1BSTRT_Msk             ( 0x7FUL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT                 ( EFC_WRP_AREAB_WRP1BSTRT_Msk )
#define EFC_WRP_AREAB_WRP1BSTRT_0               ( 0x1UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT_1               ( 0x2UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT_2               ( 0x4UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT_3               ( 0x8UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT_4               ( 0x10UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT_5               ( 0x20UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )
#define EFC_WRP_AREAB_WRP1BSTRT_6               ( 0x40UL << EFC_WRP_AREAB_WRP1BSTRT_Pos )


/***************  Bits definition for EFC_SEC_SIZE register  *****************/

#define EFC_SEC_SIZE_SECSIZE_Pos                ( 0U )
#define EFC_SEC_SIZE_SECSIZE_Msk                ( 0x7FUL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE                    ( EFC_SEC_SIZE_SECSIZE_Msk )
#define EFC_SEC_SIZE_SECSIZE_0                  ( 0x1UL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE_1                  ( 0x2UL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE_2                  ( 0x4UL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE_3                  ( 0x8UL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE_4                  ( 0x10UL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE_5                  ( 0x20UL << EFC_SEC_SIZE_SECSIZE_Pos )
#define EFC_SEC_SIZE_SECSIZE_6                  ( 0x40UL << EFC_SEC_SIZE_SECSIZE_Pos )


/***************  Bits definition for EFC_IPCK2EN register  ******************/

#define EFC_IPCK2EN_CLKEN_Pos                   ( 0U )
#define EFC_IPCK2EN_CLKEN_Msk                   ( 0xFFFFUL << EFC_IPCK2EN_CLKEN_Pos )
#define EFC_IPCK2EN_CLKEN                       ( EFC_IPCK2EN_CLKEN_Msk )


/***************  Bits definition for EFC_IPCK3EN register  ******************/

#define EFC_IPCK3EN_CLKEN_Pos                   ( 0U )
#define EFC_IPCK3EN_CLKEN_Msk                   ( 0xFFFFUL << EFC_IPCK3EN_CLKEN_Pos )
#define EFC_IPCK3EN_CLKEN                       ( EFC_IPCK3EN_CLKEN_Msk )

/***************  Bits definition for UART_DR register  **********************/

#define UART_DR_OE_Pos                          ( 12U )
#define UART_DR_OE_Msk                          ( 0x1UL << UART_DR_OE_Pos )
#define UART_DR_OE                              ( UART_DR_OE_Msk )

#define UART_DR_BE_Pos                          ( 11U )
#define UART_DR_BE_Msk                          ( 0x1UL << UART_DR_BE_Pos )
#define UART_DR_BE                              ( UART_DR_BE_Msk )

#define UART_DR_PE_Pos                          ( 10U )
#define UART_DR_PE_Msk                          ( 0x1UL << UART_DR_PE_Pos )
#define UART_DR_PE                              ( UART_DR_PE_Msk )

#define UART_DR_FE_Pos                          ( 9U )
#define UART_DR_FE_Msk                          ( 0x1UL << UART_DR_FE_Pos )
#define UART_DR_FE                              ( UART_DR_FE_Msk )

#define UART_DR_DATA_Pos                        ( 0U )
#define UART_DR_DATA_Msk                        ( 0x1FFUL << UART_DR_DATA_Pos )
#define UART_DR_DATA                            ( UART_DR_DATA_Msk )


/***************  Bits definition for UART_FR register  **********************/

#define UART_FR_BUSY_Pos                        ( 9U )
#define UART_FR_BUSY_Msk                        ( 0x1UL << UART_FR_BUSY_Pos )
#define UART_FR_BUSY                            ( UART_FR_BUSY_Msk )

#define UART_FR_CTS_Pos                         ( 8U )
#define UART_FR_CTS_Msk                         ( 0x1UL << UART_FR_CTS_Pos )
#define UART_FR_CTS                             ( UART_FR_CTS_Msk )

#define UART_FR_TXFE_Pos                        ( 7U )
#define UART_FR_TXFE_Msk                        ( 0x1UL << UART_FR_TXFE_Pos )
#define UART_FR_TXFE                            ( UART_FR_TXFE_Msk )

#define UART_FR_RXFF_Pos                        ( 6U )
#define UART_FR_RXFF_Msk                        ( 0x1UL << UART_FR_RXFF_Pos )
#define UART_FR_RXFF                            ( UART_FR_RXFF_Msk )

#define UART_FR_TXFF_Pos                        ( 5U )
#define UART_FR_TXFF_Msk                        ( 0x1UL << UART_FR_TXFF_Pos )
#define UART_FR_TXFF                            ( UART_FR_TXFF_Msk )

#define UART_FR_RXFE_Pos                        ( 4U )
#define UART_FR_RXFE_Msk                        ( 0x1UL << UART_FR_RXFE_Pos )
#define UART_FR_RXFE                            ( UART_FR_RXFE_Msk )

#define UART_FR_OE_Pos                          ( 3U )
#define UART_FR_OE_Msk                          ( 0x1UL << UART_FR_OE_Pos )
#define UART_FR_OE                              ( UART_FR_OE_Msk )

#define UART_FR_BE_Pos                          ( 2U )
#define UART_FR_BE_Msk                          ( 0x1UL << UART_FR_BE_Pos )
#define UART_FR_BE                              ( UART_FR_BE_Msk )

#define UART_FR_PE_Pos                          ( 1U )
#define UART_FR_PE_Msk                          ( 0x1UL << UART_FR_PE_Pos )
#define UART_FR_PE                              ( UART_FR_PE_Msk )

#define UART_FR_FE_Pos                          ( 0U )
#define UART_FR_FE_Msk                          ( 0x1UL << UART_FR_FE_Pos )
#define UART_FR_FE                              ( UART_FR_FE_Msk )


/***************  Bits definition for UART_BRR register  *********************/

#define UART_BRR_IBAUD_Pos                  ( 6U )
#define UART_BRR_IBAUD_Msk                  ( 0xFFFFUL << UART_BRR_IBAUD_Pos )
#define UART_BRR_IBAUD                      ( UART_BRR_IBAUD_Msk )

#define UART_BRR_FBAUD_Pos                  ( 0U )
#define UART_BRR_FBAUD_Msk                  ( 0x3FUL << UART_BRR_FBAUD_Pos )
#define UART_BRR_FBAUD                      ( UART_BRR_FBAUD_Msk )

/***************  Bits definition for UART_IE register  **********************/

#define UART_IE_ABRI_Pos                        ( 14U )
#define UART_IE_ABRI_Msk                        ( 0x1UL << UART_IE_ABRI_Pos )
#define UART_IE_ABRI                            ( UART_IE_ABRI_Msk )

#define UART_IE_IDLEI_Pos                       ( 13U )
#define UART_IE_IDLEI_Msk                       ( 0x1UL << UART_IE_IDLEI_Pos )
#define UART_IE_IDLEI                           ( UART_IE_IDLEI_Msk )

#define UART_IE_BCNTI_Pos                       ( 12U )
#define UART_IE_BCNTI_Msk                       ( 0x1UL << UART_IE_BCNTI_Pos )
#define UART_IE_BCNTI                           ( UART_IE_BCNTI_Msk )

#define UART_IE_LBDI_Pos                        ( 11U )
#define UART_IE_LBDI_Msk                        ( 0x1UL << UART_IE_LBDI_Pos )
#define UART_IE_LBDI                            ( UART_IE_LBDI_Msk )

#define UART_IE_OEI_Pos                         ( 10U )
#define UART_IE_OEI_Msk                         ( 0x1UL << UART_IE_OEI_Pos )
#define UART_IE_OEI                             ( UART_IE_OEI_Msk )

#define UART_IE_BEI_Pos                         ( 9U )
#define UART_IE_BEI_Msk                         ( 0x1UL << UART_IE_BEI_Pos )
#define UART_IE_BEI                             ( UART_IE_BEI_Msk )

#define UART_IE_PEI_Pos                         ( 8U )
#define UART_IE_PEI_Msk                         ( 0x1UL << UART_IE_PEI_Pos )
#define UART_IE_PEI                             ( UART_IE_PEI_Msk )

#define UART_IE_FEI_Pos                         ( 7U )
#define UART_IE_FEI_Msk                         ( 0x1UL << UART_IE_FEI_Pos )
#define UART_IE_FEI                             ( UART_IE_FEI_Msk )

#define UART_IE_TXI_Pos                         ( 5U )
#define UART_IE_TXI_Msk                         ( 0x1UL << UART_IE_TXI_Pos )
#define UART_IE_TXI                             ( UART_IE_TXI_Msk )

#define UART_IE_RXI_Pos                         ( 4U )
#define UART_IE_RXI_Msk                         ( 0x1UL << UART_IE_RXI_Pos )
#define UART_IE_RXI                             ( UART_IE_RXI_Msk )

/***************  Bits definition for UART_ISR register  *********************/

#define UART_ISR_ABRI_Pos                       ( 14U )
#define UART_ISR_ABRI_Msk                       ( 0x1UL << UART_ISR_ABRI_Pos )
#define UART_ISR_ABRI                           ( UART_ISR_ABRI_Msk )

#define UART_ISR_IDLEI_Pos                      ( 13U )
#define UART_ISR_IDLEI_Msk                      ( 0x1UL << UART_ISR_IDLEI_Pos )
#define UART_ISR_IDLEI                          ( UART_ISR_IDLEI_Msk )

#define UART_ISR_BCNTI_Pos                      ( 12U )
#define UART_ISR_BCNTI_Msk                      ( 0x1UL << UART_ISR_BCNTI_Pos )
#define UART_ISR_BCNTI                          ( UART_ISR_BCNTI_Msk )

#define UART_ISR_LBDI_Pos                       ( 11U )
#define UART_ISR_LBDI_Msk                       ( 0x1UL << UART_ISR_LBDI_Pos )
#define UART_ISR_LBDI                           ( UART_ISR_LBDI_Msk )

#define UART_ISR_OEI_Pos                        ( 10U )
#define UART_ISR_OEI_Msk                        ( 0x1UL << UART_ISR_OEI_Pos )
#define UART_ISR_OEI                            ( UART_ISR_OEI_Msk )

#define UART_ISR_BEI_Pos                        ( 9U )
#define UART_ISR_BEI_Msk                        ( 0x1UL << UART_ISR_BEI_Pos )
#define UART_ISR_BEI                            ( UART_ISR_BEI_Msk )

#define UART_ISR_PEI_Pos                        ( 8U )
#define UART_ISR_PEI_Msk                        ( 0x1UL << UART_ISR_PEI_Pos )
#define UART_ISR_PEI                            ( UART_ISR_PEI_Msk )

#define UART_ISR_FEI_Pos                        ( 7U )
#define UART_ISR_FEI_Msk                        ( 0x1UL << UART_ISR_FEI_Pos )
#define UART_ISR_FEI                            ( UART_ISR_FEI_Msk )

#define UART_ISR_TXI_Pos                        ( 5U )
#define UART_ISR_TXI_Msk                        ( 0x1UL << UART_ISR_TXI_Pos )
#define UART_ISR_TXI                            ( UART_ISR_TXI_Msk )

#define UART_ISR_RXI_Pos                        ( 4U )
#define UART_ISR_RXI_Msk                        ( 0x1UL << UART_ISR_RXI_Pos )
#define UART_ISR_RXI                            ( UART_ISR_RXI_Msk )


/***************  Bits definition for UART_CR1 register  *********************/

#define UART_CR1_CTSEN_Pos                      ( 15U )
#define UART_CR1_CTSEN_Msk                      ( 0x1UL << UART_CR1_CTSEN_Pos )
#define UART_CR1_CTSEN                          ( UART_CR1_CTSEN_Msk )

#define UART_CR1_RTSEN_Pos                      ( 14U )
#define UART_CR1_RTSEN_Msk                      ( 0x1UL << UART_CR1_RTSEN_Pos )
#define UART_CR1_RTSEN                          ( UART_CR1_RTSEN_Msk )

#define UART_CR1_RTS_Pos                        ( 11U )
#define UART_CR1_RTS_Msk                        ( 0x1UL << UART_CR1_RTS_Pos )
#define UART_CR1_RTS                            ( UART_CR1_RTS_Msk )

#define UART_CR1_RXE_Pos                        ( 9U )
#define UART_CR1_RXE_Msk                        ( 0x1UL << UART_CR1_RXE_Pos )
#define UART_CR1_RXE                            ( UART_CR1_RXE_Msk )

#define UART_CR1_TXE_Pos                        ( 8U )
#define UART_CR1_TXE_Msk                        ( 0x1UL << UART_CR1_TXE_Pos )
#define UART_CR1_TXE                            ( UART_CR1_TXE_Msk )

#define UART_CR1_DMAONERR_Pos                   ( 5U )
#define UART_CR1_DMAONERR_Msk                   ( 0x1UL << UART_CR1_DMAONERR_Pos )
#define UART_CR1_DMAONERR                       ( UART_CR1_DMAONERR_Msk )

#define UART_CR1_TXDMAE_Pos                     ( 4U )
#define UART_CR1_TXDMAE_Msk                     ( 0x1UL << UART_CR1_TXDMAE_Pos )
#define UART_CR1_TXDMAE                         ( UART_CR1_TXDMAE_Msk )

#define UART_CR1_RXDMAE_Pos                     ( 3U )
#define UART_CR1_RXDMAE_Msk                     ( 0x1UL << UART_CR1_RXDMAE_Pos )
#define UART_CR1_RXDMAE                         ( UART_CR1_RXDMAE_Msk )

#define UART_CR1_SIRLP_Pos                      ( 2U )
#define UART_CR1_SIRLP_Msk                      ( 0x1UL << UART_CR1_SIRLP_Pos )
#define UART_CR1_SIRLP                          ( UART_CR1_SIRLP_Msk )

#define UART_CR1_SIREN_Pos                      ( 1U )
#define UART_CR1_SIREN_Msk                      ( 0x1UL << UART_CR1_SIREN_Pos )
#define UART_CR1_SIREN                          ( UART_CR1_SIREN_Msk )

#define UART_CR1_UARTEN_Pos                     ( 0U )
#define UART_CR1_UARTEN_Msk                     ( 0x1UL << UART_CR1_UARTEN_Pos )
#define UART_CR1_UARTEN                         ( UART_CR1_UARTEN_Msk )


/***************  Bits definition for UART_CR2 register  *********************/

#define UART_CR2_ADDM7_Pos                      ( 18U )
#define UART_CR2_ADDM7_Msk                      ( 0x1UL << UART_CR2_ADDM7_Pos )
#define UART_CR2_ADDM7                          ( UART_CR2_ADDM7_Msk )

#define UART_CR2_ADDR_Pos                       ( 11U )
#define UART_CR2_ADDR_Msk                       ( 0x7FUL << UART_CR2_ADDR_Pos )
#define UART_CR2_ADDR                           ( UART_CR2_ADDR_Msk )

#define UART_CR2_CLKEN_Pos                      ( 7U )
#define UART_CR2_CLKEN_Msk                      ( 0x1UL << UART_CR2_CLKEN_Pos )
#define UART_CR2_CLKEN                          ( UART_CR2_CLKEN_Msk )

#define UART_CR2_NACK_Pos                       ( 6U )
#define UART_CR2_NACK_Msk                       ( 0x1UL << UART_CR2_NACK_Pos )
#define UART_CR2_NACK                           ( UART_CR2_NACK_Msk )

#define UART_CR2_SCEN_Pos                       ( 5U )
#define UART_CR2_SCEN_Msk                       ( 0x1UL << UART_CR2_SCEN_Pos )
#define UART_CR2_SCEN                           ( UART_CR2_SCEN_Msk )

#define UART_CR2_ABREN_Pos                      ( 4U )
#define UART_CR2_ABREN_Msk                      ( 0x1UL << UART_CR2_ABREN_Pos )
#define UART_CR2_ABREN                          ( UART_CR2_ABREN_Msk )

#define UART_CR2_WAKE_Pos                       ( 3U )
#define UART_CR2_WAKE_Msk                       ( 0x1UL << UART_CR2_WAKE_Pos )
#define UART_CR2_WAKE                           ( UART_CR2_WAKE_Msk )

#define UART_CR2_RWU_Pos                        ( 2U )
#define UART_CR2_RWU_Msk                        ( 0x1UL << UART_CR2_RWU_Pos )
#define UART_CR2_RWU                            ( UART_CR2_RWU_Msk )

#define UART_CR2_HDSEL_Pos                      ( 0U )
#define UART_CR2_HDSEL_Msk                      ( 0x1UL << UART_CR2_HDSEL_Pos )
#define UART_CR2_HDSEL                          ( UART_CR2_HDSEL_Msk )


/***************  Bits definition for UART_CR3 register  *********************/

#define UART_CR3_RXIFLSEL_Pos                   ( 13U )
#define UART_CR3_RXIFLSEL_Msk                   ( 0x7UL << UART_CR3_RXIFLSEL_Pos )
#define UART_CR3_RXIFLSEL                       ( UART_CR3_RXIFLSEL_Msk )

#define UART_CR3_TXIFLSEL_Pos                   ( 10U )
#define UART_CR3_TXIFLSEL_Msk                   ( 0x7UL << UART_CR3_TXIFLSEL_Pos )
#define UART_CR3_TXIFLSEL                       ( UART_CR3_TXIFLSEL_Msk )

#define UART_CR3_SPS_Pos                        ( 9U )
#define UART_CR3_SPS_Msk                        ( 0x1UL << UART_CR3_SPS_Pos )
#define UART_CR3_SPS                            ( UART_CR3_SPS_Msk )

#define UART_CR3_WLEN_Pos                       ( 6U )
#define UART_CR3_WLEN_Msk                       ( 0x7UL << UART_CR3_WLEN_Pos )
#define UART_CR3_WLEN                           ( UART_CR3_WLEN_Msk )

#define UART_CR3_FEN_Pos                        ( 5U )
#define UART_CR3_FEN_Msk                        ( 0x1UL << UART_CR3_FEN_Pos )
#define UART_CR3_FEN                            ( UART_CR3_FEN_Msk )

#define UART_CR3_STP2_Pos                       ( 3U )
#define UART_CR3_STP2_Msk                       ( 0x1UL << UART_CR3_STP2_Pos )
#define UART_CR3_STP2                           ( UART_CR3_STP2_Msk )

#define UART_CR3_EPS_Pos                        ( 2U )
#define UART_CR3_EPS_Msk                        ( 0x1UL << UART_CR3_EPS_Pos )
#define UART_CR3_EPS                            ( UART_CR3_EPS_Msk )

#define UART_CR3_PEN_Pos                        ( 1U )
#define UART_CR3_PEN_Msk                        ( 0x1UL << UART_CR3_PEN_Pos )
#define UART_CR3_PEN                            ( UART_CR3_PEN_Msk )

#define UART_CR3_BRK_Pos                        ( 0U )
#define UART_CR3_BRK_Msk                        ( 0x1UL << UART_CR3_BRK_Pos )
#define UART_CR3_BRK                            ( UART_CR3_BRK_Msk )


/***************  Bits definition for UART_GTPR register  ********************/

#define UART_GTPR_GT_Pos                        ( 8U )
#define UART_GTPR_GT_Msk                        ( 0xFUL << UART_GTPR_GT_Pos )
#define UART_GTPR_GT                            ( UART_GTPR_GT_Msk )

#define UART_GTPR_PSC_Pos                       ( 0U )
#define UART_GTPR_PSC_Msk                       ( 0xFFUL << UART_GTPR_PSC_Pos )
#define UART_GTPR_PSC                           ( UART_GTPR_PSC_Msk )


/***************  Bits definition for UART_BCNT register  ********************/

#define UART_BCNT_DEM_Pos                       ( 27U )
#define UART_BCNT_DEM_Msk                       ( 0x1UL << UART_BCNT_DEM_Pos )
#define UART_BCNT_DEM                           ( UART_BCNT_DEM_Msk )

#define UART_BCNT_DEP_Pos                       ( 26U )
#define UART_BCNT_DEP_Msk                       ( 0x1UL << UART_BCNT_DEP_Pos )
#define UART_BCNT_DEP                           ( UART_BCNT_DEP_Msk )

#define UART_BCNT_AUTOSTARTEN_Pos               ( 25U )
#define UART_BCNT_AUTOSTARTEN_Msk               ( 0x1UL << UART_BCNT_AUTOSTARTEN_Pos )
#define UART_BCNT_AUTOSTARTEN                   ( UART_BCNT_AUTOSTARTEN_Msk )

#define UART_BCNT_BCNTSTART_Pos                 ( 24U )
#define UART_BCNT_BCNTSTART_Msk                 ( 0x1UL << UART_BCNT_BCNTSTART_Pos )
#define UART_BCNT_BCNTSTART                     ( UART_BCNT_BCNTSTART_Msk )

#define UART_BCNT_BCNTVALUE_Pos                 ( 0U )
#define UART_BCNT_BCNTVALUE_Msk                 ( 0xFFFFFFUL << UART_BCNT_BCNTVALUE_Pos )
#define UART_BCNT_BCNTVALUE                     ( UART_BCNT_BCNTVALUE_Msk )


/***************  Bits definition for I2C_SLAVE_ADDR1 register  ***********************/

#define I2C_SLAVE_ADDR1_Pos                     ( 1U )
#define I2C_SLAVE_ADDR1_Msk                     ( 0x7FUL << I2C_SLAVE_ADDR1_Pos )
#define I2C_SLAVE_ADDR1                         ( I2C_SLAVE_ADDR1_Msk )


/***************  Bits definition for I2C_CLK_DIV register  ***********************/

#define I2C_CLK_DIV_Pos                         ( 0U )
#define I2C_CLK_DIV_Msk                         ( 0xFFFUL << I2C_CLK_DIV_Pos )
#define I2C_CLK_DIV                             ( I2C_CLK_DIV_Msk )




/***************  Bits definition for I2C_CR register  ***********************/

#define I2C_CR_STOPF_INTEN_Pos                  ( 20U )
#define I2C_CR_STOPF_INTEN_Msk                  ( 0x1UL << I2C_CR_STOPF_INTEN_Pos )
#define I2C_CR_STOPF_INTEN                      ( I2C_CR_STOPF_INTEN_Msk )

#define I2C_CR_RX_ADDR3_INTEN_Pos               ( 19U )
#define I2C_CR_RX_ADDR3_INTEN_Msk               ( 0x1UL << I2C_CR_RX_ADDR3_INTEN_Pos )
#define I2C_CR_RX_ADDR3_INTEN                   ( I2C_CR_RX_ADDR3_INTEN_Msk )

#define I2C_CR_DMA_EN_Pos                       ( 18U )
#define I2C_CR_DMA_EN_Msk                       ( 0x1UL << I2C_CR_DMA_EN_Pos )
#define I2C_CR_DMA_EN                           ( I2C_CR_DMA_EN_Msk )

#define I2C_CR_TXE_SEL_Pos                      ( 17U )
#define I2C_CR_TXE_SEL_Msk                      ( 0x1UL << I2C_CR_TXE_SEL_Pos )
#define I2C_CR_TXE_SEL                          ( I2C_CR_TXE_SEL_Msk )

#define I2C_CR_MARLO_INTEN_Pos                  ( 16U )
#define I2C_CR_MARLO_INTEN_Msk                  ( 0x1UL << I2C_CR_MARLO_INTEN_Pos )
#define I2C_CR_MARLO_INTEN                      ( I2C_CR_MARLO_INTEN_Msk )

#define I2C_CR_TX_AUTO_EN_Pos                   ( 15U )
#define I2C_CR_TX_AUTO_EN_Msk                   ( 0x1UL << I2C_CR_TX_AUTO_EN_Pos )
#define I2C_CR_TX_AUTO_EN                       ( I2C_CR_TX_AUTO_EN_Msk )

#define I2C_CR_OD_MODE_Pos                      ( 14U )
#define I2C_CR_OD_MODE_Msk                      ( 0x1UL << I2C_CR_OD_MODE_Pos )
#define I2C_CR_OD_MODE                          ( I2C_CR_OD_MODE_Msk )

#define I2C_CR_DETR_INT_EN_Pos                  ( 13U )
#define I2C_CR_DETR_INT_EN_Msk                  ( 0x1UL << I2C_CR_DETR_INT_EN_Pos )
#define I2C_CR_DETR_INT_EN                      ( I2C_CR_DETR_INT_EN_Msk )

#define I2C_CR_RX_ADDR2_INT_EN_Pos              ( 12U )
#define I2C_CR_RX_ADDR2_INT_EN_Msk              ( 0x1UL << I2C_CR_RX_ADDR2_INT_EN_Pos )
#define I2C_CR_RX_ADDR2_INT_EN                  ( I2C_CR_RX_ADDR2_INT_EN_Msk )

#define I2C_CR_OVR_INT_EN_Pos                   ( 11U )
#define I2C_CR_OVR_INT_EN_Msk                   ( 0x1UL << I2C_CR_OVR_INT_EN_Pos )
#define I2C_CR_OVR_INT_EN                       ( I2C_CR_OVR_INT_EN_Msk )

#define I2C_CR_RXNE_INT_EN_Pos                  ( 10U )
#define I2C_CR_RXNE_INT_EN_Msk                  ( 0x1UL << I2C_CR_RXNE_INT_EN_Pos )
#define I2C_CR_RXNE_INT_EN                      ( I2C_CR_RXNE_INT_EN_Msk )

#define I2C_CR_TXE_INT_EN_Pos                   ( 9U )
#define I2C_CR_TXE_INT_EN_Msk                   ( 0x1UL << I2C_CR_TXE_INT_EN_Pos )
#define I2C_CR_TXE_INT_EN                       ( I2C_CR_TXE_INT_EN_Msk )

#define I2C_CR_RX_ADDR1_INT_EN_Pos              ( 8U )
#define I2C_CR_RX_ADDR1_INT_EN_Msk              ( 0x1UL << I2C_CR_RX_ADDR1_INT_EN_Pos )
#define I2C_CR_RX_ADDR1_INT_EN                  ( I2C_CR_RX_ADDR1_INT_EN_Msk )

#define I2C_CR_MTF_INT_EN_Pos                   ( 7U )
#define I2C_CR_MTF_INT_EN_Msk                   ( 0x1UL << I2C_CR_MTF_INT_EN_Pos )
#define I2C_CR_MTF_INT_EN                       ( I2C_CR_MTF_INT_EN_Msk )

#define I2C_CR_TACK_Pos                         ( 6U )
#define I2C_CR_TACK_Msk                         ( 0x1UL << I2C_CR_TACK_Pos )
#define I2C_CR_TACK                             ( I2C_CR_TACK_Msk )

#define I2C_CR_STOP_Pos                         ( 5U )
#define I2C_CR_STOP_Msk                         ( 0x1UL << I2C_CR_STOP_Pos )
#define I2C_CR_STOP                             ( I2C_CR_STOP_Msk )

#define I2C_CR_START_Pos                        ( 4U )
#define I2C_CR_START_Msk                        ( 0x1UL << I2C_CR_START_Pos )
#define I2C_CR_START                            ( I2C_CR_START_Msk )

#define I2C_CR_TX_Pos                           ( 3U )
#define I2C_CR_TX_Msk                           ( 0x1UL << I2C_CR_TX_Pos )
#define I2C_CR_TX                               ( I2C_CR_TX_Msk )

#define I2C_CR_MASTER_Pos                       ( 2U )
#define I2C_CR_MASTER_Msk                       ( 0x1UL << I2C_CR_MASTER_Pos )
#define I2C_CR_MASTER                           ( I2C_CR_MASTER_Msk )

#define I2C_CR_NOSTRETCH_Pos                    ( 1U )
#define I2C_CR_NOSTRETCH_Msk                    ( 0x1UL << I2C_CR_NOSTRETCH_Pos )
#define I2C_CR_NOSTRETCH                        ( I2C_CR_NOSTRETCH_Msk )

#define I2C_CR_MEN_Pos                          ( 0U )
#define I2C_CR_MEN_Msk                          ( 0x1UL << I2C_CR_MEN_Pos )
#define I2C_CR_MEN                              ( I2C_CR_MEN_Msk )



/***************  Bits definition for I2C_SR register  ***********************/

#define I2C_SR_TIMEOUTBF_Pos                    ( 16U )
#define I2C_SR_TIMEOUTBF_Msk                    ( 0x1UL << I2C_SR_TIMEOUTBF_Pos )
#define I2C_SR_TIMEOUTBF                        ( I2C_SR_TIMEOUTBF_Msk )

#define I2C_SR_TIMEOUTAF_Pos                    ( 15U )
#define I2C_SR_TIMEOUTAF_Msk                    ( 0x1UL << I2C_SR_TIMEOUTAF_Pos )
#define I2C_SR_TIMEOUTAF                        ( I2C_SR_TIMEOUTAF_Msk )

#define I2C_SR_RX_ADDR3_Pos                     ( 14U )
#define I2C_SR_RX_ADDR3_Msk                     ( 0x1UL << I2C_SR_RX_ADDR3_Pos )
#define I2C_SR_RX_ADDR3                         ( I2C_SR_RX_ADDR3_Msk )

#define I2C_SR_DETR_Pos                         ( 13U )
#define I2C_SR_DETR_Msk                         ( 0x1UL << I2C_SR_DETR_Pos )
#define I2C_SR_DETR                             ( I2C_SR_DETR_Msk )

#define I2C_SR_RX_ADDR2_Pos                     ( 12U )
#define I2C_SR_RX_ADDR2_Msk                     ( 0x1UL << I2C_SR_RX_ADDR2_Pos )
#define I2C_SR_RX_ADDR2                         ( I2C_SR_RX_ADDR2_Msk )

#define I2C_SR_OVR_Pos                          ( 11U )
#define I2C_SR_OVR_Msk                          ( 0x1UL << I2C_SR_OVR_Pos )
#define I2C_SR_OVR                              ( I2C_SR_OVR_Msk )

#define I2C_SR_RXNE_Pos                         ( 10U )
#define I2C_SR_RXNE_Msk                         ( 0x1UL << I2C_SR_RXNE_Pos )
#define I2C_SR_RXNE                             ( I2C_SR_RXNE_Msk )

#define I2C_SR_TXE_Pos                          ( 9U )
#define I2C_SR_TXE_Msk                          ( 0x1UL << I2C_SR_TXE_Pos )
#define I2C_SR_TXE                              ( I2C_SR_TXE_Msk )

#define I2C_SR_RX_ADDR1_Pos                     ( 8U )
#define I2C_SR_RX_ADDR1_Msk                     ( 0x1UL << I2C_SR_RX_ADDR1_Pos )
#define I2C_SR_RX_ADDR1                         ( I2C_SR_RX_ADDR1_Msk )

#define I2C_SR_MTF_Pos                          ( 7U )
#define I2C_SR_MTF_Msk                          ( 0x1UL << I2C_SR_MTF_Pos )
#define I2C_SR_MTF                              ( I2C_SR_MTF_Msk )

#define I2C_SR_MARLO_Pos                        ( 6U )
#define I2C_SR_MARLO_Msk                        ( 0x1UL << I2C_SR_MARLO_Pos )
#define I2C_SR_MARLO                            ( I2C_SR_MARLO_Msk )

#define I2C_SR_TX_RX_FLAG_Pos                   ( 5U )
#define I2C_SR_TX_RX_FLAG_Msk                   ( 0x1UL << I2C_SR_TX_RX_FLAG_Pos )
#define I2C_SR_TX_RX_FLAG                       ( I2C_SR_TX_RX_FLAG_Msk )

#define I2C_SR_BUS_BUSY_Pos                     ( 4U )
#define I2C_SR_BUS_BUSY_Msk                     ( 0x1UL << I2C_SR_BUS_BUSY_Pos )
#define I2C_SR_BUS_BUSY                         ( I2C_SR_BUS_BUSY_Msk )

#define I2C_SR_SRW_Pos                          ( 3U )
#define I2C_SR_SRW_Msk                          ( 0x1UL << I2C_SR_SRW_Pos )
#define I2C_SR_SRW                              ( I2C_SR_SRW_Msk )

#define I2C_SR_STOPF_Pos                        ( 2U )
#define I2C_SR_STOPF_Msk                        ( 0x1UL << I2C_SR_STOPF_Pos )
#define I2C_SR_STOPF                            ( I2C_SR_STOPF_Msk )

#define I2C_SR_STARTF_Pos                       ( 1U )
#define I2C_SR_STARTF_Msk                       ( 0x1UL << I2C_SR_STARTF_Pos )
#define I2C_SR_STARTF                           ( I2C_SR_STARTF_Msk )

#define I2C_SR_RACK_Pos                         ( 0U )
#define I2C_SR_RACK_Msk                         ( 0x1UL << I2C_SR_RACK_Pos )
#define I2C_SR_RACK                             ( I2C_SR_RACK_Msk )



/***************  Bits definition for I2C_SLAVE ADDR2/ADDR3 register  ********************/

#define I2C_SLAVE_ADDR3_Pos                     ( 9U )
#define I2C_SLAVE_ADDR3_Msk                     ( 0x7FUL << I2C_SLAVE_ADDR3_Pos )
#define I2C_SLAVE_ADDR3                         ( I2C_SLAVE_ADDR3_Msk )

#define I2C_SLAVE_ADDR3EN_Pos                   ( 8U )
#define I2C_SLAVE_ADDR3EN_Msk                   ( 0x1UL << I2C_SLAVE_ADDR3EN_Pos )
#define I2C_SLAVE_ADDR3EN                       ( I2C_SLAVE_ADDR3EN_Msk )

#define I2C_SLAVE_ADDR2_Pos                     ( 1U )
#define I2C_SLAVE_ADDR2_Msk                     ( 0x7FUL << I2C_SLAVE_ADDR2_Pos )
#define I2C_SLAVE_ADDR2                         ( I2C_SLAVE_ADDR2_Msk )

#define I2C_SLAVE_ADDR2EN_Pos                   ( 0U )
#define I2C_SLAVE_ADDR2EN_Msk                   ( 0x1UL << I2C_SLAVE_ADDR2EN_Pos )
#define I2C_SLAVE_ADDR2EN                       ( I2C_SLAVE_ADDR2EN_Msk )


/***************  Bits definition for I2C DETCNT register  **************************/

#define I2C_DETCNT_Pos                          ( 0U )
#define I2C_DETCNT_Msk                          ( 0xFFFFUL << I2C_DETCNT_Pos )
#define I2C_DETCNT                              ( I2C_DETCNT_Msk )



/***************  Bits definition for I2C_FILTER register  *******************/

#define I2C_FILTER_SDAINDELAY_Pos               ( 8U )
#define I2C_FILTER_SDAINDELAY_Msk               ( 0x1FUL << I2C_FILTER_SDAINDELAY_Pos )
#define I2C_FILTER_SDAINDELAY                   ( I2C_FILTER_SDAINDELAY_Msk )

#define I2C_FILTER_SCLFITER_Pos                 ( 0U )
#define I2C_FILTER_SCLFITER_Msk                 ( 0x1FUL << I2C_FILTER_SCLFITER_Pos )
#define I2C_FILTER_SCLFITER                     ( I2C_FILTER_SCLFITER_Msk )


/***************  Bits definition for I2C_SMBUS register  ********************/

#define I2C_SMBUS_EXTEN_Pos                     ( 31U )
#define I2C_SMBUS_EXTEN_Msk                     ( 0x1UL << I2C_SMBUS_EXTEN_Pos )
#define I2C_SMBUS_EXTEN                         ( I2C_SMBUS_EXTEN_Msk )

#define I2C_SMBUS_TOUTBINTEN_Pos                ( 30U )
#define I2C_SMBUS_TOUTBINTEN_Msk                ( 0x1UL << I2C_SMBUS_TOUTBINTEN_Pos )
#define I2C_SMBUS_TOUTBINTEN                    ( I2C_SMBUS_TOUTBINTEN_Msk )

#define I2C_SMBUS_EXTMODE_Pos                   ( 29U )
#define I2C_SMBUS_EXTMODE_Msk                   ( 0x1UL << I2C_SMBUS_EXTMODE_Pos )
#define I2C_SMBUS_EXTMODE                       ( I2C_SMBUS_EXTMODE_Msk )

#define I2C_SMBUS_TIMEOUTB_Pos                  ( 16U )
#define I2C_SMBUS_TIMEOUTB_Msk                  ( 0xFFFUL << I2C_SMBUS_TIMEOUTB_Pos )
#define I2C_SMBUS_TIMEOUTB                      ( I2C_SMBUS_TIMEOUTB_Msk )

#define I2C_SMBUS_TIMOUTEN_Pos                  ( 15U )
#define I2C_SMBUS_TIMOUTEN_Msk                  ( 0x1UL << I2C_SMBUS_TIMOUTEN_Pos )
#define I2C_SMBUS_TIMOUTEN                      ( I2C_SMBUS_TIMOUTEN_Msk )

#define I2C_SMBUS_TOUTAINTEN_Pos                ( 14U )
#define I2C_SMBUS_TOUTAINTEN_Msk                ( 0x1UL << I2C_SMBUS_TOUTAINTEN_Pos )
#define I2C_SMBUS_TOUTAINTEN                    ( I2C_SMBUS_TOUTAINTEN_Msk )

#define I2C_SMBUS_TIMEOUTA_Pos                  ( 0U )
#define I2C_SMBUS_TIMEOUTA_Msk                  ( 0xFFFUL << I2C_SMBUS_TIMEOUTA_Pos )
#define I2C_SMBUS_TIMEOUTA                      ( I2C_SMBUS_TIMEOUTA_Msk )


/***************  Bits definition for SPI_BAUD register  *********************/

#define SPI_BAUD_DIV2_Pos                       ( 8U )
#define SPI_BAUD_DIV2_Msk                       ( 0xFFUL << SPI_BAUD_DIV2_Pos )
#define SPI_BAUD_DIV2                           ( SPI_BAUD_DIV2_Msk )

#define SPI_BAUD_DIV1_Pos                       ( 0U )
#define SPI_BAUD_DIV1_Msk                       ( 0xFFUL << SPI_BAUD_DIV1_Pos )
#define SPI_BAUD_DIV1                           ( SPI_BAUD_DIV1_Msk )


/***************  Bits definition for SPI_CTRL register  *********************/

#define SPI_CTL_SWCS_EN_Pos                    ( 21U )
#define SPI_CTL_SWCS_EN_Msk                    ( 0x1UL << SPI_CTL_SWCS_EN_Pos )
#define SPI_CTL_SWCS_EN                        ( SPI_CTL_SWCS_EN_Msk )

#define SPI_CTL_SWCS_Pos                       ( 20U )
#define SPI_CTL_SWCS_Msk                       ( 0x1UL << SPI_CTL_SWCS_Pos )
#define SPI_CTL_SWCS                           ( SPI_CTL_SWCS_Msk )

#define SPI_CTL_CS_TIME_Pos                    ( 11U )
#define SPI_CTL_CS_TIME_Msk                    ( 0xFFUL << SPI_CTL_CS_TIME_Pos )
#define SPI_CTL_CS_TIME                        ( SPI_CTL_CS_TIME_Msk )

#define SPI_CTL_CS_FILTER_Pos                  ( 10U )
#define SPI_CTL_CS_FILTER_Msk                  ( 0x1UL << SPI_CTL_CS_FILTER_Pos )
#define SPI_CTL_CS_FILTER                      ( SPI_CTL_CS_FILTER_Msk )

#define SPI_CTL_CS_RST_Pos                     ( 9U )
#define SPI_CTL_CS_RST_Msk                     ( 0x1UL << SPI_CTL_CS_RST_Pos )
#define SPI_CTL_CS_RST                         ( SPI_CTL_CS_RST_Msk )

#define SPI_CTL_SLAVE_EN_Pos                   ( 8U )
#define SPI_CTL_SLAVE_EN_Msk                   ( 0x1UL << SPI_CTL_SLAVE_EN_Pos )
#define SPI_CTL_SLAVE_EN                       ( SPI_CTL_SLAVE_EN_Msk )

#define SPI_CTL_IO_MODE_Pos                    ( 7U )
#define SPI_CTL_IO_MODE_Msk                    ( 0x1UL << SPI_CTL_IO_MODE_Pos )
#define SPI_CTL_IO_MODE                        ( SPI_CTL_IO_MODE_Msk )

#define SPI_CTL_X_MODE_Pos                     ( 5U )
#define SPI_CTL_X_MODE_Msk                     ( 0x3UL << SPI_CTL_X_MODE_Pos )
#define SPI_CTL_X_MODE                         ( SPI_CTL_X_MODE_Msk )

#define SPI_CTL_LSB_FIRST_Pos                  ( 4U )
#define SPI_CTL_LSB_FIRST_Msk                  ( 0x1UL << SPI_CTL_LSB_FIRST_Pos )
#define SPI_CTL_LSB_FIRST                      ( SPI_CTL_LSB_FIRST_Msk )

#define SPI_CTL_CPOL_Pos                       ( 3U )
#define SPI_CTL_CPOL_Msk                       ( 0x1UL << SPI_CTL_CPOL_Pos )
#define SPI_CTL_CPOL                           ( SPI_CTL_CPOL_Msk )

#define SPI_CTL_CPHA_Pos                       ( 2U )
#define SPI_CTL_CPHA_Msk                       ( 0x1UL << SPI_CTL_CPHA_Pos )
#define SPI_CTL_CPHA                           ( SPI_CTL_CPHA_Msk )

#define SPI_CTL_SFILTER_Pos                    ( 1U )
#define SPI_CTL_SFILTER_Msk                    ( 0x1UL << SPI_CTL_SFILTER_Pos )
#define SPI_CTL_SFILTER                        ( SPI_CTL_SFILTER_Msk )

#define SPI_CTL_MST_MODE_Pos                   ( 0U )
#define SPI_CTL_MST_MODE_Msk                   ( 0x1UL << SPI_CTL_MST_MODE_Pos )
#define SPI_CTL_MST_MODE                       ( SPI_CTL_MST_MODE_Msk )


/***************  Bits definition for SPI_TX_CTRL register  ******************/

#define SPI_TX_CTL_DUMMY_Pos                   ( 8U )
#define SPI_TX_CTL_DUMMY_Msk                   ( 0xFFUL << SPI_TX_CTL_DUMMY_Pos )
#define SPI_TX_CTL_DUMMY                       ( SPI_TX_CTL_DUMMY_Msk )

#define SPI_TX_CTL_DMA_LEVEL_Pos            ( 4U )
#define SPI_TX_CTL_DMA_LEVEL_Msk            ( 0xFUL << SPI_TX_CTL_DMA_LEVEL_Pos )
#define SPI_TX_CTL_DMA_LEVEL                ( SPI_TX_CTL_DMA_LEVEL_Msk )
#define SPI_TX_CTL_DMA_LEVEL_0              ( 0x1UL << SPI_TX_CTL_DMA_LEVEL_Pos )
#define SPI_TX_CTL_DMA_LEVEL_1              ( 0x2UL << SPI_TX_CTL_DMA_LEVEL_Pos )
#define SPI_TX_CTL_DMA_LEVEL_2              ( 0x4UL << SPI_TX_CTL_DMA_LEVEL_Pos )
#define SPI_TX_CTL_DMA_LEVEL_3              ( 0x8UL << SPI_TX_CTL_DMA_LEVEL_Pos )

#define SPI_TX_CTL_DMA_REQ_EN_Pos           ( 3U )
#define SPI_TX_CTL_DMA_REQ_EN_Msk           ( 0x1UL << SPI_TX_CTL_DMA_REQ_EN_Pos )
#define SPI_TX_CTL_DMA_REQ_EN               ( SPI_TX_CTL_DMA_REQ_EN_Msk )

#define SPI_TX_CTL_MODE_Pos                 ( 2U )
#define SPI_TX_CTL_MODE_Msk                 ( 0x1UL << SPI_TX_CTL_MODE_Pos )
#define SPI_TX_CTL_MODE                     ( SPI_TX_CTL_MODE_Msk )

#define SPI_TX_CTL_FIFO_RESET_Pos           ( 1U )
#define SPI_TX_CTL_FIFO_RESET_Msk           ( 0x1UL << SPI_TX_CTL_FIFO_RESET_Pos )
#define SPI_TX_CTL_FIFO_RESET               ( SPI_TX_CTL_FIFO_RESET_Msk )

#define SPI_TX_CTL_EN_Pos                   ( 0U )
#define SPI_TX_CTL_EN_Msk                   ( 0x1UL << SPI_TX_CTL_EN_Pos )
#define SPI_TX_CTL_EN                       ( SPI_TX_CTL_EN_Msk )


/***************  Bits definition for SPI_RX_CTRL register  ******************/

#define SPI_RX_CTL_SSHIFT_Pos               ( 8U )
#define SPI_RX_CTL_SSHIFT_Msk               ( 0x3UL << SPI_RX_CTL_SSHIFT_Pos )
#define SPI_RX_CTL_SSHIFT                   ( SPI_RX_CTL_SSHIFT_Msk )

#define SPI_RX_CTL_DMA_LEVEL_Pos            ( 4U )
#define SPI_RX_CTL_DMA_LEVEL_Msk            ( 0xFUL << SPI_RX_CTL_DMA_LEVEL_Pos )
#define SPI_RX_CTL_DMA_LEVEL                ( SPI_RX_CTL_DMA_LEVEL_Msk )
#define SPI_RX_CTL_DMA_LEVEL_0              ( 0x1UL << SPI_RX_CTL_DMA_LEVEL_Pos )
#define SPI_RX_CTL_DMA_LEVEL_1              ( 0x2UL << SPI_RX_CTL_DMA_LEVEL_Pos )
#define SPI_RX_CTL_DMA_LEVEL_2              ( 0x4UL << SPI_RX_CTL_DMA_LEVEL_Pos )
#define SPI_RX_CTL_DMA_LEVEL_3              ( 0x8UL << SPI_RX_CTL_DMA_LEVEL_Pos )

#define SPI_RX_CTL_DMA_REQ_EN_Pos           ( 3U )
#define SPI_RX_CTL_DMA_REQ_EN_Msk           ( 0x1UL << SPI_RX_CTL_DMA_REQ_EN_Pos )
#define SPI_RX_CTL_DMA_REQ_EN               ( SPI_RX_CTL_DMA_REQ_EN_Msk )

#define SPI_RX_CTL_FIFO_RESET_Pos           ( 1U )
#define SPI_RX_CTL_FIFO_RESET_Msk           ( 0x1UL << SPI_RX_CTL_FIFO_RESET_Pos )
#define SPI_RX_CTL_FIFO_RESET               ( SPI_RX_CTL_FIFO_RESET_Msk )

#define SPI_RX_CTL_EN_Pos                   ( 0U )
#define SPI_RX_CTL_EN_Msk                   ( 0x1UL << SPI_RX_CTL_EN_Pos )
#define SPI_RX_CTL_EN                       ( SPI_RX_CTL_EN_Msk )


/***************  Bits definition for SPI_IE register  ***********************/

#define SPI_IE_RX_BATCH_DONE_EN_Pos             ( 15U )
#define SPI_IE_RX_BATCH_DONE_EN_Msk             ( 0x1UL << SPI_IE_RX_BATCH_DONE_EN_Pos )
#define SPI_IE_RX_BATCH_DONE_EN                 ( SPI_IE_RX_BATCH_DONE_EN_Msk )

#define SPI_IE_TX_BATCH_DONE_EN_Pos             ( 14U )
#define SPI_IE_TX_BATCH_DONE_EN_Msk             ( 0x1UL << SPI_IE_TX_BATCH_DONE_EN_Pos )
#define SPI_IE_TX_BATCH_DONE_EN                 ( SPI_IE_TX_BATCH_DONE_EN_Msk )

#define SPI_IE_RX_FIFO_FULL_OVERFLOW_EN_Pos     ( 13U )
#define SPI_IE_RX_FIFO_FULL_OVERFLOW_EN_Msk     ( 0x1UL << SPI_IE_RX_FIFO_FULL_OVERFLOW_EN_Pos )
#define SPI_IE_RX_FIFO_FULL_OVERFLOW_EN         ( SPI_IE_RX_FIFO_FULL_OVERFLOW_EN_Msk )

#define SPI_IE_RX_FIFO_EMPTY_OVERFLOW_EN_Pos    ( 12U )
#define SPI_IE_RX_FIFO_EMPTY_OVERFLOW_EN_Msk    ( 0x1UL << SPI_IE_RX_FIFO_EMPTY_OVERFLOW_EN_Pos )
#define SPI_IE_RX_FIFO_EMPTY_OVERFLOW_EN        ( SPI_IE_RX_FIFO_EMPTY_OVERFLOW_EN_Msk )

#define SPI_IE_RX_FIFO_NOT_EMPTY_EN_Pos         ( 11U )
#define SPI_IE_RX_FIFO_NOT_EMPTY_EN_Msk         ( 0x1UL << SPI_IE_RX_FIFO_NOT_EMPTY_EN_Pos )
#define SPI_IE_RX_FIFO_NOT_EMPTY_EN             ( SPI_IE_RX_FIFO_NOT_EMPTY_EN_Msk )

#define SPI_IE_CS_POS_EN_Pos                    ( 10U )
#define SPI_IE_CS_POS_EN_Msk                    ( 0x1UL << SPI_IE_CS_POS_EN_Pos )
#define SPI_IE_CS_POS_EN                        ( SPI_IE_CS_POS_EN_Msk )

#define SPI_IE_RX_FIFO_HALF_FULL_EN_Pos         ( 9U )
#define SPI_IE_RX_FIFO_HALF_FULL_EN_Msk         ( 0x1UL << SPI_IE_RX_FIFO_HALF_FULL_EN_Pos )
#define SPI_IE_RX_FIFO_HALF_FULL_EN             ( SPI_IE_RX_FIFO_HALF_FULL_EN_Msk )

#define SPI_IE_RX_FIFO_HALF_EMPTY_EN_Pos        ( 8U )
#define SPI_IE_RX_FIFO_HALF_EMPTY_EN_Msk        ( 0x1UL << SPI_IE_RX_FIFO_HALF_EMPTY_EN_Pos )
#define SPI_IE_RX_FIFO_HALF_EMPTY_EN            ( SPI_IE_RX_FIFO_HALF_EMPTY_EN_Msk )

#define SPI_IE_TX_FIFO_HALF_FULL_EN_Pos         ( 7U )
#define SPI_IE_TX_FIFO_HALF_FULL_EN_Msk         ( 0x1UL << SPI_IE_TX_FIFO_HALF_FULL_EN_Pos )
#define SPI_IE_TX_FIFO_HALF_FULL_EN             ( SPI_IE_TX_FIFO_HALF_FULL_EN_Msk )

#define SPI_IE_TX_FIFO_HALF_EMPTY_EN_Pos        ( 6U )
#define SPI_IE_TX_FIFO_HALF_EMPTY_EN_Msk        ( 0x1UL << SPI_IE_TX_FIFO_HALF_EMPTY_EN_Pos )
#define SPI_IE_TX_FIFO_HALF_EMPTY_EN            ( SPI_IE_TX_FIFO_HALF_EMPTY_EN_Msk )

#define SPI_IE_RX_FIFO_FULL_EN_Pos              ( 5U )
#define SPI_IE_RX_FIFO_FULL_EN_Msk              ( 0x1UL << SPI_IE_RX_FIFO_FULL_EN_Pos )
#define SPI_IE_RX_FIFO_FULL_EN                  ( SPI_IE_RX_FIFO_FULL_EN_Msk )

#define SPI_IE_RX_FIFO_EMPTY_EN_Pos             ( 4U )
#define SPI_IE_RX_FIFO_EMPTY_EN_Msk             ( 0x1UL << SPI_IE_RX_FIFO_EMPTY_EN_Pos )
#define SPI_IE_RX_FIFO_EMPTY_EN                 ( SPI_IE_RX_FIFO_EMPTY_EN_Msk )

#define SPI_IE_TX_FIFO_FULL_EN_Pos              ( 3U )
#define SPI_IE_TX_FIFO_FULL_EN_Msk              ( 0x1UL << SPI_IE_TX_FIFO_FULL_EN_Pos )
#define SPI_IE_TX_FIFO_FULL_EN                  ( SPI_IE_TX_FIFO_FULL_EN_Msk )

#define SPI_IE_TX_FIFO_EMPTY_EN_Pos             ( 2U )
#define SPI_IE_TX_FIFO_EMPTY_EN_Msk             ( 0x1UL << SPI_IE_TX_FIFO_EMPTY_EN_Pos )
#define SPI_IE_TX_FIFO_EMPTY_EN                 ( SPI_IE_TX_FIFO_EMPTY_EN_Msk )

#define SPI_IE_BATCH_DONE_EN_Pos                ( 1U )
#define SPI_IE_BATCH_DONE_EN_Msk                ( 0x1UL << SPI_IE_BATCH_DONE_EN_Pos )
#define SPI_IE_BATCH_DONE_EN                    ( SPI_IE_BATCH_DONE_EN_Msk )


/***************  Bits definition for SPI_STATUS register  *******************/

#define SPI_STATUS_RX_BATCH_DONE_Pos            ( 15U )
#define SPI_STATUS_RX_BATCH_DONE_Msk            ( 0x1UL << SPI_STATUS_RX_BATCH_DONE_Pos )
#define SPI_STATUS_RX_BATCH_DONE                ( SPI_STATUS_RX_BATCH_DONE_Msk )

#define SPI_STATUS_TX_BATCH_DONE_Pos            ( 14U )
#define SPI_STATUS_TX_BATCH_DONE_Msk            ( 0x1UL << SPI_STATUS_TX_BATCH_DONE_Pos )
#define SPI_STATUS_TX_BATCH_DONE                ( SPI_STATUS_TX_BATCH_DONE_Msk )

#define SPI_STATUS_RX_FIFO_FULL_OVERFLOW_Pos    ( 13U )
#define SPI_STATUS_RX_FIFO_FULL_OVERFLOW_Msk    ( 0x1UL << SPI_STATUS_RX_FIFO_FULL_OVERFLOW_Pos )
#define SPI_STATUS_RX_FIFO_FULL_OVERFLOW        ( SPI_STATUS_RX_FIFO_FULL_OVERFLOW_Msk )

#define SPI_STATUS_RX_FIFO_EMPTY_OVERFLOW_Pos   ( 12U )
#define SPI_STATUS_RX_FIFO_EMPTY_OVERFLOW_Msk   ( 0x1UL << SPI_STATUS_RX_FIFO_EMPTY_OVERFLOW_Pos )
#define SPI_STATUS_RX_FIFO_EMPTY_OVERFLOW       ( SPI_STATUS_RX_FIFO_EMPTY_OVERFLOW_Msk )

#define SPI_STATUS_RX_FIFO_NOT_EMPTY_Pos        ( 11U )
#define SPI_STATUS_RX_FIFO_NOT_EMPTY_Msk        ( 0x1UL << SPI_STATUS_RX_FIFO_NOT_EMPTY_Pos )
#define SPI_STATUS_RX_FIFO_NOT_EMPTY            ( SPI_STATUS_RX_FIFO_NOT_EMPTY_Msk )

#define SPI_STATUS_CS_POS_FLG_Pos               ( 10U )
#define SPI_STATUS_CS_POS_FLG_Msk               ( 0x1UL << SPI_STATUS_CS_POS_FLG_Pos )
#define SPI_STATUS_CS_POS_FLG                   ( SPI_STATUS_CS_POS_FLG_Msk )

#define SPI_STATUS_RX_FIFO_HALF_FULL_Pos        ( 9U )
#define SPI_STATUS_RX_FIFO_HALF_FULL_Msk        ( 0x1UL << SPI_STATUS_RX_FIFO_HALF_FULL_Pos )
#define SPI_STATUS_RX_FIFO_HALF_FULL            ( SPI_STATUS_RX_FIFO_HALF_FULL_Msk )

#define SPI_STATUS_RX_FIFO_HALF_EMPTY_Pos       ( 8U )
#define SPI_STATUS_RX_FIFO_HALF_EMPTY_Msk       ( 0x1UL << SPI_STATUS_RX_FIFO_HALF_EMPTY_Pos )
#define SPI_STATUS_RX_FIFO_HALF_EMPTY           ( SPI_STATUS_RX_FIFO_HALF_EMPTY_Msk )

#define SPI_STATUS_TX_FIFO_HALF_FULL_Pos        ( 7U )
#define SPI_STATUS_TX_FIFO_HALF_FULL_Msk        ( 0x1UL << SPI_STATUS_TX_FIFO_HALF_FULL_Pos )
#define SPI_STATUS_TX_FIFO_HALF_FULL            ( SPI_STATUS_TX_FIFO_HALF_FULL_Msk )

#define SPI_STATUS_TX_FIFO_HALF_EMPTY_Pos       ( 6U )
#define SPI_STATUS_TX_FIFO_HALF_EMPTY_Msk       ( 0x1UL << SPI_STATUS_TX_FIFO_HALF_EMPTY_Pos )
#define SPI_STATUS_TX_FIFO_HALF_EMPTY           ( SPI_STATUS_TX_FIFO_HALF_EMPTY_Msk )

#define SPI_STATUS_RX_FIFO_FULL_Pos             ( 5U )
#define SPI_STATUS_RX_FIFO_FULL_Msk             ( 0x1UL << SPI_STATUS_RX_FIFO_FULL_Pos )
#define SPI_STATUS_RX_FIFO_FULL                 ( SPI_STATUS_RX_FIFO_FULL_Msk )

#define SPI_STATUS_RX_FIFO_EMPTY_Pos            ( 4U )
#define SPI_STATUS_RX_FIFO_EMPTY_Msk            ( 0x1UL << SPI_STATUS_RX_FIFO_EMPTY_Pos )
#define SPI_STATUS_RX_FIFO_EMPTY                ( SPI_STATUS_RX_FIFO_EMPTY_Msk )

#define SPI_STATUS_TX_FIFO_FULL_Pos             ( 3U )
#define SPI_STATUS_TX_FIFO_FULL_Msk             ( 0x1UL << SPI_STATUS_TX_FIFO_FULL_Pos )
#define SPI_STATUS_TX_FIFO_FULL                 ( SPI_STATUS_TX_FIFO_FULL_Msk )

#define SPI_STATUS_TX_FIFO_EMPTY_Pos            ( 2U )
#define SPI_STATUS_TX_FIFO_EMPTY_Msk            ( 0x1UL << SPI_STATUS_TX_FIFO_EMPTY_Pos )
#define SPI_STATUS_TX_FIFO_EMPTY                ( SPI_STATUS_TX_FIFO_EMPTY_Msk )

#define SPI_STATUS_BATCH_DONE_Pos               ( 1U )
#define SPI_STATUS_BATCH_DONE_Msk               ( 0x1UL << SPI_STATUS_BATCH_DONE_Pos )
#define SPI_STATUS_BATCH_DONE                   ( SPI_STATUS_BATCH_DONE_Msk )

#define SPI_STATUS_TX_BUSY_Pos                  ( 0U )
#define SPI_STATUS_TX_BUSY_Msk                  ( 0x1UL << SPI_STATUS_TX_BUSY_Pos )
#define SPI_STATUS_TX_BUSY                      ( SPI_STATUS_TX_BUSY_Msk )


/***************  Bits definition for SPI register  **************************/

#define SPI_CS_Pos                              ( 0U )
#define SPI_CS_Msk                              ( 0x3UL << SPI__CS_Pos )
#define SPI_CS                                  ( SPI_CS_Msk )
#define SPI_CS_CS0                              ( 0x1UL << SPI_CS_Pos )
#define SPI_CS_CS1                              ( 0x2UL << SPI_CS_Pos )


/***************  Bits definition for SPI_OUT_EN register  *************************/

#define SPI_HOLD_EN_Pos                        ( 3U )
#define SPI_HOLD_EN_Msk                        ( 0x1UL << SPI__HOLD_EN_Pos )
#define SPI_HOLD_EN                            ( SPI__HOLD_EN_Msk )

#define SPI_WP_EN_Pos                          ( 2U )
#define SPI_WP_EN_Msk                          ( 0x1UL << SPI__WP_EN_Pos )
#define SPI_WP_EN                              ( SPI__WP_EN_Msk )

#define SPI_MISO_EN_Pos                        ( 1U )
#define SPI_MISO_EN_Msk                        ( 0x1UL << SPI__MISO_EN_Pos )
#define SPI_MISO_EN                            ( SPI__MISO_EN_Msk )

#define SPI_MOSI_EN_Pos                        ( 0U )
#define SPI_MOSI_EN_Msk                        ( 0x1UL << SPI__MOSI_EN_Pos )
#define SPI_MOSI_EN                            ( SPI__MOSI_EN_Msk )



/******************************************************************************/
/*                                                                            */
/*                                    COMP                                    */
/*                                                                            */
/******************************************************************************/

/***************  Bits definition for COMP_CR1 register  *********************/

#define COMP_CR1_LOCK_Pos                       ( 31U )
#define COMP_CR1_LOCK_Msk                       ( 0x1UL << COMP_CR1_LOCK_Pos )
#define COMP_CR1_LOCK                           ( COMP_CR1_LOCK_Msk )

#define COMP_CR1_CRVCFG_Pos                     ( 25U )
#define COMP_CR1_CRVCFG_Msk                     ( 0xFUL << COMP_CR1_CRVCFG_Pos )
#define COMP_CR1_CRVCFG                         ( COMP_CR1_CRVCFG_Msk )
#define COMP_CR1_CRVCFG_0                       ( 0x1UL << COMP_CR1_CRVCFG_Pos )
#define COMP_CR1_CRVCFG_1                       ( 0x2UL << COMP_CR1_CRVCFG_Pos )
#define COMP_CR1_CRVCFG_2                       ( 0x4UL << COMP_CR1_CRVCFG_Pos )
#define COMP_CR1_CRVCFG_3                       ( 0x8UL << COMP_CR1_CRVCFG_Pos )

#define COMP_CR1_CRVSEL_Pos                     ( 24U )
#define COMP_CR1_CRVSEL_Msk                     ( 0x1UL << COMP_CR1_CRVSEL_Pos )
#define COMP_CR1_CRVSEL                         ( COMP_CR1_CRVSEL_Msk )

#define COMP_CR1_CRVEN_Pos                      ( 23U )
#define COMP_CR1_CRVEN_Msk                      ( 0x1UL << COMP_CR1_CRVEN_Pos )
#define COMP_CR1_CRVEN                          ( COMP_CR1_CRVEN_Msk )

#define COMP_CR1_WINMODE_Pos                    ( 22U )
#define COMP_CR1_WINMODE_Msk                    ( 0x1UL << COMP_CR1_WINMODE_Pos )
#define COMP_CR1_WINMODE                        ( COMP_CR1_WINMODE_Msk )

#define COMP_CR1_WINOUT_Pos                     ( 21U )
#define COMP_CR1_WINOUT_Msk                     ( 0x1UL << COMP_CR1_WINOUT_Pos )
#define COMP_CR1_WINOUT                         ( COMP_CR1_WINOUT_Msk )

#define COMP_CR1_POLARITY_Pos                   ( 20U )
#define COMP_CR1_POLARITY_Msk                   ( 0x1UL << COMP_CR1_POLARITY_Pos )
#define COMP_CR1_POLARITY                       ( COMP_CR1_POLARITY_Msk )

#define COMP_CR1_FLTEN_Pos                      ( 19U )
#define COMP_CR1_FLTEN_Msk                      ( 0x1UL << COMP_CR1_FLTEN_Pos )
#define COMP_CR1_FLTEN                          ( COMP_CR1_FLTEN_Msk )

#define COMP_CR1_FLTTIME_Pos                    ( 16U )
#define COMP_CR1_FLTTIME_Msk                    ( 0x7UL << COMP_CR1_FLTTIME_Pos )
#define COMP_CR1_FLTTIME                        ( COMP_CR1_FLTTIME_Msk )
#define COMP_CR1_FLTTIME_0                      ( 0x1UL << COMP_CR1_FLTTIME_Pos )
#define COMP_CR1_FLTTIME_1                      ( 0x2UL << COMP_CR1_FLTTIME_Pos )
#define COMP_CR1_FLTTIME_2                      ( 0x4UL << COMP_CR1_FLTTIME_Pos )

#define COMP_CR1_BLANKSEL_Pos                   ( 12U )
#define COMP_CR1_BLANKSEL_Msk                   ( 0x7UL << COMP_CR1_BLANKSEL_Pos )
#define COMP_CR1_BLANKSEL                       ( COMP_CR1_BLANKSEL_Msk )
#define COMP_CR1_BLANKSEL_0                     ( 0x1UL << COMP_CR1_BLANKSEL_Pos )
#define COMP_CR1_BLANKSEL_1                     ( 0x2UL << COMP_CR1_BLANKSEL_Pos )
#define COMP_CR1_BLANKSEL_2                     ( 0x4UL << COMP_CR1_BLANKSEL_Pos )

#define COMP_CR1_INPSEL_Pos                     ( 8U )
#define COMP_CR1_INPSEL_Msk                     ( 0xFUL << COMP_CR1_INPSEL_Pos )
#define COMP_CR1_INPSEL                         ( COMP_CR1_INPSEL_Msk )
#define COMP_CR1_INPSEL_0                       ( 0x1UL << COMP_CR1_INPSEL_Pos )
#define COMP_CR1_INPSEL_1                       ( 0x2UL << COMP_CR1_INPSEL_Pos )
#define COMP_CR1_INPSEL_2                       ( 0x4UL << COMP_CR1_INPSEL_Pos )
#define COMP_CR1_INPSEL_3                       ( 0x8UL << COMP_CR1_INPSEL_Pos )

#define COMP_CR1_INMSEL_Pos                     ( 4U )
#define COMP_CR1_INMSEL_Msk                     ( 0xFUL << COMP_CR1_INMSEL_Pos )
#define COMP_CR1_INMSEL                         ( COMP_CR1_INMSEL_Msk )
#define COMP_CR1_INMSEL_0                       ( 0x1UL << COMP_CR1_INMSEL_Pos )
#define COMP_CR1_INMSEL_1                       ( 0x2UL << COMP_CR1_INMSEL_Pos )
#define COMP_CR1_INMSEL_2                       ( 0x4UL << COMP_CR1_INMSEL_Pos )
#define COMP_CR1_INMSEL_3                       ( 0x8UL << COMP_CR1_INMSEL_Pos )

#define COMP_CR1_HYS_Pos                        ( 1U )
#define COMP_CR1_HYS_Msk                        ( 0x7UL << COMP_CR1_HYS_Pos )
#define COMP_CR1_HYS                            ( COMP_CR1_HYS_Msk )
#define COMP_CR1_HYS_0                          ( 0x1UL << COMP_CR1_HYS_Pos )
#define COMP_CR1_HYS_1                          ( 0x2UL << COMP_CR1_HYS_Pos )
#define COMP_CR1_HYS_2                          ( 0x4UL << COMP_CR1_HYS_Pos )

#define COMP_CR1_EN_Pos                         ( 0U )
#define COMP_CR1_EN_Msk                         ( 0x1UL << COMP_CR1_EN_Pos )
#define COMP_CR1_EN                             ( COMP_CR1_EN_Msk )


/***************  Bits definition for COMP_CR2 register  *********************/

#define COMP_CR2_LOCK_Pos                       ( 31U )
#define COMP_CR2_LOCK_Msk                       ( 0x1UL << COMP_CR2_LOCK_Pos )
#define COMP_CR2_LOCK                           ( COMP_CR2_LOCK_Msk )

#define COMP_CR2_CRVCFG_Pos                     ( 25U )
#define COMP_CR2_CRVCFG_Msk                     ( 0xFUL << COMP_CR2_CRVCFG_Pos )
#define COMP_CR2_CRVCFG                         ( COMP_CR2_CRVCFG_Msk )
#define COMP_CR2_CRVCFG_0                       ( 0x1UL << COMP_CR2_CRVCFG_Pos )
#define COMP_CR2_CRVCFG_1                       ( 0x2UL << COMP_CR2_CRVCFG_Pos )
#define COMP_CR2_CRVCFG_2                       ( 0x4UL << COMP_CR2_CRVCFG_Pos )
#define COMP_CR2_CRVCFG_3                       ( 0x8UL << COMP_CR2_CRVCFG_Pos )

#define COMP_CR2_CRVSEL_Pos                     ( 24U )
#define COMP_CR2_CRVSEL_Msk                     ( 0x1UL << COMP_CR2_CRVSEL_Pos )
#define COMP_CR2_CRVSEL                         ( COMP_CR2_CRVSEL_Msk )

#define COMP_CR2_CRVEN_Pos                      ( 23U )
#define COMP_CR2_CRVEN_Msk                      ( 0x1UL << COMP_CR2_CRVEN_Pos )
#define COMP_CR2_CRVEN                          ( COMP_CR2_CRVEN_Msk )

#define COMP_CR2_WINMODE_Pos                    ( 22U )
#define COMP_CR2_WINMODE_Msk                    ( 0x1UL << COMP_CR2_WINMODE_Pos )
#define COMP_CR2_WINMODE                        ( COMP_CR2_WINMODE_Msk )

#define COMP_CR2_WINOUT_Pos                     ( 21U )
#define COMP_CR2_WINOUT_Msk                     ( 0x1UL << COMP_CR2_WINOUT_Pos )
#define COMP_CR2_WINOUT                         ( COMP_CR2_WINOUT_Msk )

#define COMP_CR2_POLARITY_Pos                   ( 20U )
#define COMP_CR2_POLARITY_Msk                   ( 0x1UL << COMP_CR2_POLARITY_Pos )
#define COMP_CR2_POLARITY                       ( COMP_CR2_POLARITY_Msk )

#define COMP_CR2_FLTEN_Pos                      ( 19U )
#define COMP_CR2_FLTEN_Msk                      ( 0x1UL << COMP_CR2_FLTEN_Pos )
#define COMP_CR2_FLTEN                          ( COMP_CR2_FLTEN_Msk )

#define COMP_CR2_FLTTIME_Pos                    ( 16U )
#define COMP_CR2_FLTTIME_Msk                    ( 0x7UL << COMP_CR2_FLTTIME_Pos )
#define COMP_CR2_FLTTIME                        ( COMP_CR2_FLTTIME_Msk )
#define COMP_CR2_FLTTIME_0                      ( 0x1UL << COMP_CR2_FLTTIME_Pos )
#define COMP_CR2_FLTTIME_1                      ( 0x2UL << COMP_CR2_FLTTIME_Pos )
#define COMP_CR2_FLTTIME_2                      ( 0x4UL << COMP_CR2_FLTTIME_Pos )

#define COMP_CR2_BLANKSEL_Pos                   ( 12U )
#define COMP_CR2_BLANKSEL_Msk                   ( 0x7UL << COMP_CR2_BLANKSEL_Pos )
#define COMP_CR2_BLANKSEL                       ( COMP_CR2_BLANKSEL_Msk )
#define COMP_CR2_BLANKSEL_0                     ( 0x1UL << COMP_CR2_BLANKSEL_Pos )
#define COMP_CR2_BLANKSEL_1                     ( 0x2UL << COMP_CR2_BLANKSEL_Pos )
#define COMP_CR2_BLANKSEL_2                     ( 0x4UL << COMP_CR2_BLANKSEL_Pos )

#define COMP_CR2_INPSEL_Pos                     ( 8U )
#define COMP_CR2_INPSEL_Msk                     ( 0xFUL << COMP_CR2_INPSEL_Pos )
#define COMP_CR2_INPSEL                         ( COMP_CR2_INPSEL_Msk )
#define COMP_CR2_INPSEL_0                       ( 0x1UL << COMP_CR2_INPSEL_Pos )
#define COMP_CR2_INPSEL_1                       ( 0x2UL << COMP_CR2_INPSEL_Pos )
#define COMP_CR2_INPSEL_2                       ( 0x4UL << COMP_CR2_INPSEL_Pos )
#define COMP_CR2_INPSEL_3                       ( 0x8UL << COMP_CR2_INPSEL_Pos )

#define COMP_CR2_INMSEL_Pos                     ( 4U )
#define COMP_CR2_INMSEL_Msk                     ( 0xFUL << COMP_CR2_INMSEL_Pos )
#define COMP_CR2_INMSEL                         ( COMP_CR2_INMSEL_Msk )
#define COMP_CR2_INMSEL_0                       ( 0x1UL << COMP_CR2_INMSEL_Pos )
#define COMP_CR2_INMSEL_1                       ( 0x2UL << COMP_CR2_INMSEL_Pos )
#define COMP_CR2_INMSEL_2                       ( 0x4UL << COMP_CR2_INMSEL_Pos )
#define COMP_CR2_INMSEL_3                       ( 0x8UL << COMP_CR2_INMSEL_Pos )

#define COMP_CR2_HYS_Pos                        ( 1U )
#define COMP_CR2_HYS_Msk                        ( 0x7UL << COMP_CR2_HYS_Pos )
#define COMP_CR2_HYS                            ( COMP_CR2_HYS_Msk )
#define COMP_CR2_HYS_0                          ( 0x1UL << COMP_CR2_HYS_Pos )
#define COMP_CR2_HYS_1                          ( 0x2UL << COMP_CR2_HYS_Pos )
#define COMP_CR2_HYS_2                          ( 0x4UL << COMP_CR2_HYS_Pos )

#define COMP_CR2_EN_Pos                         ( 0U )
#define COMP_CR2_EN_Msk                         ( 0x1UL << COMP_CR2_EN_Pos )
#define COMP_CR2_EN                             ( COMP_CR2_EN_Msk )


/***************  Bits definition for COMP_CR3 register  *********************/

#define COMP_CR3_LOCK_Pos                       ( 31U )
#define COMP_CR3_LOCK_Msk                       ( 0x1UL << COMP_CR3_LOCK_Pos )
#define COMP_CR3_LOCK                           ( COMP_CR3_LOCK_Msk )

#define COMP_CR3_CRVCFG_Pos                     ( 25U )
#define COMP_CR3_CRVCFG_Msk                     ( 0xFUL << COMP_CR3_CRVCFG_Pos )
#define COMP_CR3_CRVCFG                         ( COMP_CR3_CRVCFG_Msk )
#define COMP_CR3_CRVCFG_0                       ( 0x1UL << COMP_CR3_CRVCFG_Pos )
#define COMP_CR3_CRVCFG_1                       ( 0x2UL << COMP_CR3_CRVCFG_Pos )
#define COMP_CR3_CRVCFG_2                       ( 0x4UL << COMP_CR3_CRVCFG_Pos )
#define COMP_CR3_CRVCFG_3                       ( 0x8UL << COMP_CR3_CRVCFG_Pos )

#define COMP_CR3_CRVSEL_Pos                     ( 24U )
#define COMP_CR3_CRVSEL_Msk                     ( 0x1UL << COMP_CR3_CRVSEL_Pos )
#define COMP_CR3_CRVSEL                         ( COMP_CR3_CRVSEL_Msk )

#define COMP_CR3_CRVEN_Pos                      ( 23U )
#define COMP_CR3_CRVEN_Msk                      ( 0x1UL << COMP_CR3_CRVEN_Pos )
#define COMP_CR3_CRVEN                          ( COMP_CR3_CRVEN_Msk )

#define COMP_CR3_WINMODE_Pos                    ( 22U )
#define COMP_CR3_WINMODE_Msk                    ( 0x1UL << COMP_CR3_WINMODE_Pos )
#define COMP_CR3_WINMODE                        ( COMP_CR3_WINMODE_Msk )

#define COMP_CR3_WINOUT_Pos                     ( 21U )
#define COMP_CR3_WINOUT_Msk                     ( 0x1UL << COMP_CR3_WINOUT_Pos )
#define COMP_CR3_WINOUT                         ( COMP_CR3_WINOUT_Msk )

#define COMP_CR3_POLARITY_Pos                   ( 20U )
#define COMP_CR3_POLARITY_Msk                   ( 0x1UL << COMP_CR3_POLARITY_Pos )
#define COMP_CR3_POLARITY                       ( COMP_CR3_POLARITY_Msk )

#define COMP_CR3_FLTEN_Pos                      ( 19U )
#define COMP_CR3_FLTEN_Msk                      ( 0x1UL << COMP_CR3_FLTEN_Pos )
#define COMP_CR3_FLTEN                          ( COMP_CR3_FLTEN_Msk )

#define COMP_CR3_FLTTIME_Pos                    ( 16U )
#define COMP_CR3_FLTTIME_Msk                    ( 0x7UL << COMP_CR3_FLTTIME_Pos )
#define COMP_CR3_FLTTIME                        ( COMP_CR3_FLTTIME_Msk )
#define COMP_CR3_FLTTIME_0                      ( 0x1UL << COMP_CR3_FLTTIME_Pos )
#define COMP_CR3_FLTTIME_1                      ( 0x2UL << COMP_CR3_FLTTIME_Pos )
#define COMP_CR3_FLTTIME_2                      ( 0x4UL << COMP_CR3_FLTTIME_Pos )

#define COMP_CR3_BLANKSEL_Pos                   ( 12U )
#define COMP_CR3_BLANKSEL_Msk                   ( 0x7UL << COMP_CR3_BLANKSEL_Pos )
#define COMP_CR3_BLANKSEL                       ( COMP_CR3_BLANKSEL_Msk )
#define COMP_CR3_BLANKSEL_0                     ( 0x1UL << COMP_CR3_BLANKSEL_Pos )
#define COMP_CR3_BLANKSEL_1                     ( 0x2UL << COMP_CR3_BLANKSEL_Pos )
#define COMP_CR3_BLANKSEL_2                     ( 0x4UL << COMP_CR3_BLANKSEL_Pos )

#define COMP_CR3_INPSEL_Pos                     ( 8U )
#define COMP_CR3_INPSEL_Msk                     ( 0xFUL << COMP_CR3_INPSEL_Pos )
#define COMP_CR3_INPSEL                         ( COMP_CR3_INPSEL_Msk )
#define COMP_CR3_INPSEL_0                       ( 0x1UL << COMP_CR3_INPSEL_Pos )
#define COMP_CR3_INPSEL_1                       ( 0x2UL << COMP_CR3_INPSEL_Pos )
#define COMP_CR3_INPSEL_2                       ( 0x4UL << COMP_CR3_INPSEL_Pos )
#define COMP_CR3_INPSEL_3                       ( 0x8UL << COMP_CR3_INPSEL_Pos )

#define COMP_CR3_INMSEL_Pos                     ( 4U )
#define COMP_CR3_INMSEL_Msk                     ( 0xFUL << COMP_CR3_INMSEL_Pos )
#define COMP_CR3_INMSEL                         ( COMP_CR3_INMSEL_Msk )
#define COMP_CR3_INMSEL_0                       ( 0x1UL << COMP_CR3_INMSEL_Pos )
#define COMP_CR3_INMSEL_1                       ( 0x2UL << COMP_CR3_INMSEL_Pos )
#define COMP_CR3_INMSEL_2                       ( 0x4UL << COMP_CR3_INMSEL_Pos )
#define COMP_CR3_INMSEL_3                       ( 0x8UL << COMP_CR3_INMSEL_Pos )

#define COMP_CR3_HYS_Pos                        ( 1U )
#define COMP_CR3_HYS_Msk                        ( 0x7UL << COMP_CR3_HYS_Pos )
#define COMP_CR3_HYS                            ( COMP_CR3_HYS_Msk )
#define COMP_CR3_HYS_0                          ( 0x1UL << COMP_CR3_HYS_Pos )
#define COMP_CR3_HYS_1                          ( 0x2UL << COMP_CR3_HYS_Pos )
#define COMP_CR3_HYS_2                          ( 0x4UL << COMP_CR3_HYS_Pos )

#define COMP_CR3_EN_Pos                         ( 0U )
#define COMP_CR3_EN_Msk                         ( 0x1UL << COMP_CR3_EN_Pos )
#define COMP_CR3_EN                             ( COMP_CR3_EN_Msk )


/***************  Bits definition for COMP_CR4 register  *********************/

#define COMP_CR4_LOCK_Pos                       ( 31U )
#define COMP_CR4_LOCK_Msk                       ( 0x1UL << COMP_CR4_LOCK_Pos )
#define COMP_CR4_LOCK                           ( COMP_CR4_LOCK_Msk )

#define COMP_CR4_CRVCFG_Pos                     ( 25U )
#define COMP_CR4_CRVCFG_Msk                     ( 0xFUL << COMP_CR4_CRVCFG_Pos )
#define COMP_CR4_CRVCFG                         ( COMP_CR4_CRVCFG_Msk )
#define COMP_CR4_CRVCFG_0                       ( 0x1UL << COMP_CR4_CRVCFG_Pos )
#define COMP_CR4_CRVCFG_1                       ( 0x2UL << COMP_CR4_CRVCFG_Pos )
#define COMP_CR4_CRVCFG_2                       ( 0x4UL << COMP_CR4_CRVCFG_Pos )
#define COMP_CR4_CRVCFG_3                       ( 0x8UL << COMP_CR4_CRVCFG_Pos )

#define COMP_CR4_CRVSEL_Pos                     ( 24U )
#define COMP_CR4_CRVSEL_Msk                     ( 0x1UL << COMP_CR4_CRVSEL_Pos )
#define COMP_CR4_CRVSEL                         ( COMP_CR4_CRVSEL_Msk )

#define COMP_CR4_CRVEN_Pos                      ( 23U )
#define COMP_CR4_CRVEN_Msk                      ( 0x1UL << COMP_CR4_CRVEN_Pos )
#define COMP_CR4_CRVEN                          ( COMP_CR4_CRVEN_Msk )

#define COMP_CR4_WINMODE_Pos                    ( 22U )
#define COMP_CR4_WINMODE_Msk                    ( 0x1UL << COMP_CR4_WINMODE_Pos )
#define COMP_CR4_WINMODE                        ( COMP_CR4_WINMODE_Msk )

#define COMP_CR4_WINOUT_Pos                     ( 21U )
#define COMP_CR4_WINOUT_Msk                     ( 0x1UL << COMP_CR4_WINOUT_Pos )
#define COMP_CR4_WINOUT                         ( COMP_CR4_WINOUT_Msk )

#define COMP_CR4_POLARITY_Pos                   ( 20U )
#define COMP_CR4_POLARITY_Msk                   ( 0x1UL << COMP_CR4_POLARITY_Pos )
#define COMP_CR4_POLARITY                       ( COMP_CR4_POLARITY_Msk )

#define COMP_CR4_FLTEN_Pos                      ( 19U )
#define COMP_CR4_FLTEN_Msk                      ( 0x1UL << COMP_CR4_FLTEN_Pos )
#define COMP_CR4_FLTEN                          ( COMP_CR4_FLTEN_Msk )

#define COMP_CR4_FLTTIME_Pos                    ( 16U )
#define COMP_CR4_FLTTIME_Msk                    ( 0x7UL << COMP_CR4_FLTTIME_Pos )
#define COMP_CR4_FLTTIME                        ( COMP_CR4_FLTTIME_Msk )
#define COMP_CR4_FLTTIME_0                      ( 0x1UL << COMP_CR4_FLTTIME_Pos )
#define COMP_CR4_FLTTIME_1                      ( 0x2UL << COMP_CR4_FLTTIME_Pos )
#define COMP_CR4_FLTTIME_2                      ( 0x4UL << COMP_CR4_FLTTIME_Pos )

#define COMP_CR4_BLANKSEL_Pos                   ( 12U )
#define COMP_CR4_BLANKSEL_Msk                   ( 0x7UL << COMP_CR4_BLANKSEL_Pos )
#define COMP_CR4_BLANKSEL                       ( COMP_CR4_BLANKSEL_Msk )
#define COMP_CR4_BLANKSEL_0                     ( 0x1UL << COMP_CR4_BLANKSEL_Pos )
#define COMP_CR4_BLANKSEL_1                     ( 0x2UL << COMP_CR4_BLANKSEL_Pos )
#define COMP_CR4_BLANKSEL_2                     ( 0x4UL << COMP_CR4_BLANKSEL_Pos )

#define COMP_CR4_INPSEL_Pos                     ( 8U )
#define COMP_CR4_INPSEL_Msk                     ( 0xFUL << COMP_CR4_INPSEL_Pos )
#define COMP_CR4_INPSEL                         ( COMP_CR4_INPSEL_Msk )
#define COMP_CR4_INPSEL_0                       ( 0x1UL << COMP_CR4_INPSEL_Pos )
#define COMP_CR4_INPSEL_1                       ( 0x2UL << COMP_CR4_INPSEL_Pos )
#define COMP_CR4_INPSEL_2                       ( 0x4UL << COMP_CR4_INPSEL_Pos )
#define COMP_CR4_INPSEL_3                       ( 0x8UL << COMP_CR4_INPSEL_Pos )

#define COMP_CR4_INMSEL_Pos                     ( 4U )
#define COMP_CR4_INMSEL_Msk                     ( 0xFUL << COMP_CR4_INMSEL_Pos )
#define COMP_CR4_INMSEL                         ( COMP_CR4_INMSEL_Msk )
#define COMP_CR4_INMSEL_0                       ( 0x1UL << COMP_CR4_INMSEL_Pos )
#define COMP_CR4_INMSEL_1                       ( 0x2UL << COMP_CR4_INMSEL_Pos )
#define COMP_CR4_INMSEL_2                       ( 0x4UL << COMP_CR4_INMSEL_Pos )
#define COMP_CR4_INMSEL_3                       ( 0x8UL << COMP_CR4_INMSEL_Pos )

#define COMP_CR4_HYS_Pos                        ( 1U )
#define COMP_CR4_HYS_Msk                        ( 0x7UL << COMP_CR4_HYS_Pos )
#define COMP_CR4_HYS                            ( COMP_CR4_HYS_Msk )
#define COMP_CR4_HYS_0                          ( 0x1UL << COMP_CR4_HYS_Pos )
#define COMP_CR4_HYS_1                          ( 0x2UL << COMP_CR4_HYS_Pos )
#define COMP_CR4_HYS_2                          ( 0x4UL << COMP_CR4_HYS_Pos )

#define COMP_CR4_EN_Pos                         ( 0U )
#define COMP_CR4_EN_Msk                         ( 0x1UL << COMP_CR4_EN_Pos )
#define COMP_CR4_EN                             ( COMP_CR4_EN_Msk )


/***************  Bits definition for COMP_SR register  **********************/

#define COMP_SR_VCOUT4ORG_Pos                   ( 7U )
#define COMP_SR_VCOUT4ORG_Msk                   ( 0x1UL << COMP_SR_VCOUT4ORG_Pos )
#define COMP_SR_VCOUT4ORG                       ( COMP_SR_VCOUT4ORG_Msk )

#define COMP_SR_VCOUT3ORG_Pos                   ( 6U )
#define COMP_SR_VCOUT3ORG_Msk                   ( 0x1UL << COMP_SR_VCOUT3ORG_Pos )
#define COMP_SR_VCOUT3ORG                       ( COMP_SR_VCOUT3ORG_Msk )

#define COMP_SR_VCOUT2ORG_Pos                   ( 5U )
#define COMP_SR_VCOUT2ORG_Msk                   ( 0x1UL << COMP_SR_VCOUT2ORG_Pos )
#define COMP_SR_VCOUT2ORG                       ( COMP_SR_VCOUT2ORG_Msk )

#define COMP_SR_VCOUT1ORG_Pos                   ( 4U )
#define COMP_SR_VCOUT1ORG_Msk                   ( 0x1UL << COMP_SR_VCOUT1ORG_Pos )
#define COMP_SR_VCOUT1ORG                       ( COMP_SR_VCOUT1ORG_Msk )

#define COMP_SR_VCOUT4_Pos                      ( 3U )
#define COMP_SR_VCOUT4_Msk                      ( 0x1UL << COMP_SR_VCOUT4_Pos )
#define COMP_SR_VCOUT4                          ( COMP_SR_VCOUT4_Msk )

#define COMP_SR_VCOUT3_Pos                      ( 2U )
#define COMP_SR_VCOUT3_Msk                      ( 0x1UL << COMP_SR_VCOUT3_Pos )
#define COMP_SR_VCOUT3                          ( COMP_SR_VCOUT3_Msk )

#define COMP_SR_VCOUT2_Pos                      ( 1U )
#define COMP_SR_VCOUT2_Msk                      ( 0x1UL << COMP_SR_VCOUT2_Pos )
#define COMP_SR_VCOUT2                          ( COMP_SR_VCOUT2_Msk )

#define COMP_SR_VCOUT1_Pos                      ( 0U )
#define COMP_SR_VCOUT1_Msk                      ( 0x1UL << COMP_SR_VCOUT1_Pos )
#define COMP_SR_VCOUT1                          ( COMP_SR_VCOUT1_Msk )


/******************************************************************************/
/*                                                                            */
/*                                    OPA                                     */
/*                                                                            */
/******************************************************************************/


/***************  Bits definition for OPA_CSR1 register  *********************/

#define OPA_CSR1_LOCK_Pos                       ( 31U )
#define OPA_CSR1_LOCK_Msk                       ( 0x1UL << OPA_CSR1_LOCK_Pos )
#define OPA_CSR1_LOCK                           ( OPA_CSR1_LOCK_Msk )

#define OPA_CSR1_HSM_Pos                        ( 28U )
#define OPA_CSR1_HSM_Msk                        ( 0x1UL << OPA_CSR1_HSM_Pos )
#define OPA_CSR1_HSM                            ( OPA_CSR1_HSM_Msk )

#define OPA_CSR1_GAINSEL_Pos                    ( 23U )
#define OPA_CSR1_GAINSEL_Msk                    ( 0x1FUL << OPA_CSR1_GAINSEL_Pos )
#define OPA_CSR1_GAINSEL                        ( OPA_CSR1_GAINSEL_Msk )
#define OPA_CSR1_GAINSEL_0                      ( 0x1UL << OPA_CSR1_GAINSEL_Pos )
#define OPA_CSR1_GAINSEL_1                      ( 0x2UL << OPA_CSR1_GAINSEL_Pos )
#define OPA_CSR1_GAINSEL_2                      ( 0x4UL << OPA_CSR1_GAINSEL_Pos )
#define OPA_CSR1_GAINSEL_3                      ( 0x8UL << OPA_CSR1_GAINSEL_Pos )
#define OPA_CSR1_GAINSEL_4                      ( 0x10UL << OPA_CSR1_GAINSEL_Pos )

#define OPA_CSR1_POLSEL_Pos                     ( 21U )
#define OPA_CSR1_POLSEL_Msk                     ( 0x3UL << OPA_CSR1_POLSEL_Pos )
#define OPA_CSR1_POLSEL                         ( OPA_CSR1_POLSEL_Msk )
#define OPA_CSR1_POLSEL_0                       ( 0x1UL << OPA_CSR1_POLSEL_Pos )
#define OPA_CSR1_POLSEL_1                       ( 0x2UL << OPA_CSR1_POLSEL_Pos )

#define OPA_CSR1_VINN0EN_Pos                    ( 20U )
#define OPA_CSR1_VINN0EN_Msk                    ( 0x1UL << OPA_CSR1_VINN0EN_Pos )
#define OPA_CSR1_VINN0EN                        ( OPA_CSR1_VINN0EN_Msk )

#define OPA_CSR1_MODESEL_Pos                    ( 18U )
#define OPA_CSR1_MODESEL_Msk                    ( 0x3UL << OPA_CSR1_MODESEL_Pos )
#define OPA_CSR1_MODESEL                        ( OPA_CSR1_MODESEL_Msk )
#define OPA_CSR1_MODESEL_0                      ( 0x1UL << OPA_CSR1_MODESEL_Pos )
#define OPA_CSR1_MODESEL_1                      ( 0x2UL << OPA_CSR1_MODESEL_Pos )

#define OPA_CSR1_VINPSEL_Pos                    ( 16U )
#define OPA_CSR1_VINPSEL_Msk                    ( 0x3UL << OPA_CSR1_VINPSEL_Pos )
#define OPA_CSR1_VINPSEL                        ( OPA_CSR1_VINPSEL_Msk )
#define OPA_CSR1_VINPSEL_0                      ( 0x1UL << OPA_CSR1_VINPSEL_Pos )
#define OPA_CSR1_VINPSEL_1                      ( 0x2UL << OPA_CSR1_VINPSEL_Pos )

#define OPA_CSR1_OUTSEL_Pos                     ( 14U )
#define OPA_CSR1_OUTSEL_Msk                     ( 0x3UL << OPA_CSR1_OUTSEL_Pos )
#define OPA_CSR1_OUTSEL                         ( OPA_CSR1_OUTSEL_Msk )
#define OPA_CSR1_OUTSEL_0                       ( 0x1UL << OPA_CSR1_OUTSEL_Pos )
#define OPA_CSR1_OUTSEL_1                       ( 0x2UL << OPA_CSR1_OUTSEL_Pos )

#define OPA_CSR1_TRIMOSN_Pos                    ( 9U )
#define OPA_CSR1_TRIMOSN_Msk                    ( 0x1FUL << OPA_CSR1_TRIMOSN_Pos )
#define OPA_CSR1_TRIMOSN                        ( OPA_CSR1_TRIMOSN_Msk )
#define OPA_CSR1_TRIMOSN_0                      ( 0x1UL << OPA_CSR1_TRIMOSN_Pos )
#define OPA_CSR1_TRIMOSN_1                      ( 0x2UL << OPA_CSR1_TRIMOSN_Pos )
#define OPA_CSR1_TRIMOSN_2                      ( 0x4UL << OPA_CSR1_TRIMOSN_Pos )
#define OPA_CSR1_TRIMOSN_3                      ( 0x8UL << OPA_CSR1_TRIMOSN_Pos )
#define OPA_CSR1_TRIMOSN_4                      ( 0x10UL << OPA_CSR1_TRIMOSN_Pos )

#define OPA_CSR1_TRIMOSP_Pos                    ( 4U )
#define OPA_CSR1_TRIMOSP_Msk                    ( 0x1FUL << OPA_CSR1_TRIMOSP_Pos )
#define OPA_CSR1_TRIMOSP                        ( OPA_CSR1_TRIMOSP_Msk )
#define OPA_CSR1_TRIMOSP_0                      ( 0x1UL << OPA_CSR1_TRIMOSP_Pos )
#define OPA_CSR1_TRIMOSP_1                      ( 0x2UL << OPA_CSR1_TRIMOSP_Pos )
#define OPA_CSR1_TRIMOSP_2                      ( 0x4UL << OPA_CSR1_TRIMOSP_Pos )
#define OPA_CSR1_TRIMOSP_3                      ( 0x8UL << OPA_CSR1_TRIMOSP_Pos )
#define OPA_CSR1_TRIMOSP_4                      ( 0x10UL << OPA_CSR1_TRIMOSP_Pos )

#define OPA_CSR1_CALOUT_Pos                     ( 3U )
#define OPA_CSR1_CALOUT_Msk                     ( 0x1UL << OPA_CSR1_CALOUT_Pos )
#define OPA_CSR1_CALOUT                         ( OPA_CSR1_CALOUT_Msk )

#define OPA_CSR1_CALNEN_Pos                     ( 2U )
#define OPA_CSR1_CALNEN_Msk                     ( 0x1UL << OPA_CSR1_CALNEN_Pos )
#define OPA_CSR1_CALNEN                         ( OPA_CSR1_CALNEN_Msk )

#define OPA_CSR1_CALPEN_Pos                     ( 1U )
#define OPA_CSR1_CALPEN_Msk                     ( 0x1UL << OPA_CSR1_CALPEN_Pos )
#define OPA_CSR1_CALPEN                         ( OPA_CSR1_CALPEN_Msk )

#define OPA_CSR1_EN_Pos                         ( 0U )
#define OPA_CSR1_EN_Msk                         ( 0x1UL << OPA_CSR1_EN_Pos )
#define OPA_CSR1_EN                             ( OPA_CSR1_EN_Msk )


/***************  Bits definition for OPA_CSR2 register  *********************/

#define OPA_CSR2_LOCK_Pos                       ( 31U )
#define OPA_CSR2_LOCK_Msk                       ( 0x1UL << OPA_CSR2_LOCK_Pos )
#define OPA_CSR2_LOCK                           ( OPA_CSR2_LOCK_Msk )

#define OPA_CSR2_HSM_Pos                        ( 28U )
#define OPA_CSR2_HSM_Msk                        ( 0x1UL << OPA_CSR2_HSM_Pos )
#define OPA_CSR2_HSM                            ( OPA_CSR2_HSM_Msk )

#define OPA_CSR2_GAINSEL_Pos                    ( 23U )
#define OPA_CSR2_GAINSEL_Msk                    ( 0x1FUL << OPA_CSR2_GAINSEL_Pos )
#define OPA_CSR2_GAINSEL                        ( OPA_CSR2_GAINSEL_Msk )
#define OPA_CSR2_GAINSEL_0                      ( 0x1UL << OPA_CSR2_GAINSEL_Pos )
#define OPA_CSR2_GAINSEL_1                      ( 0x2UL << OPA_CSR2_GAINSEL_Pos )
#define OPA_CSR2_GAINSEL_2                      ( 0x4UL << OPA_CSR2_GAINSEL_Pos )
#define OPA_CSR2_GAINSEL_3                      ( 0x8UL << OPA_CSR2_GAINSEL_Pos )
#define OPA_CSR2_GAINSEL_4                      ( 0x10UL << OPA_CSR2_GAINSEL_Pos )

#define OPA_CSR2_POLSEL_Pos                     ( 21U )
#define OPA_CSR2_POLSEL_Msk                     ( 0x3UL << OPA_CSR2_POLSEL_Pos )
#define OPA_CSR2_POLSEL                         ( OPA_CSR2_POLSEL_Msk )
#define OPA_CSR2_POLSEL_0                       ( 0x1UL << OPA_CSR2_POLSEL_Pos )
#define OPA_CSR2_POLSEL_1                       ( 0x2UL << OPA_CSR2_POLSEL_Pos )

#define OPA_CSR2_VINN0EN_Pos                    ( 20U )
#define OPA_CSR2_VINN0EN_Msk                    ( 0x1UL << OPA_CSR2_VINN0EN_Pos )
#define OPA_CSR2_VINN0EN                        ( OPA_CSR2_VINN0EN_Msk )

#define OPA_CSR2_MODESEL_Pos                    ( 18U )
#define OPA_CSR2_MODESEL_Msk                    ( 0x3UL << OPA_CSR2_MODESEL_Pos )
#define OPA_CSR2_MODESEL                        ( OPA_CSR2_MODESEL_Msk )
#define OPA_CSR2_MODESEL_0                      ( 0x1UL << OPA_CSR2_MODESEL_Pos )
#define OPA_CSR2_MODESEL_1                      ( 0x2UL << OPA_CSR2_MODESEL_Pos )

#define OPA_CSR2_VINPSEL_Pos                    ( 16U )
#define OPA_CSR2_VINPSEL_Msk                    ( 0x3UL << OPA_CSR2_VINPSEL_Pos )
#define OPA_CSR2_VINPSEL                        ( OPA_CSR2_VINPSEL_Msk )
#define OPA_CSR2_VINPSEL_0                      ( 0x1UL << OPA_CSR2_VINPSEL_Pos )
#define OPA_CSR2_VINPSEL_1                      ( 0x2UL << OPA_CSR2_VINPSEL_Pos )

#define OPA_CSR2_OUTSEL_Pos                     ( 14U )
#define OPA_CSR2_OUTSEL_Msk                     ( 0x3UL << OPA_CSR2_OUTSEL_Pos )
#define OPA_CSR2_OUTSEL                         ( OPA_CSR2_OUTSEL_Msk )
#define OPA_CSR2_OUTSEL_0                       ( 0x1UL << OPA_CSR2_OUTSEL_Pos )
#define OPA_CSR2_OUTSEL_1                       ( 0x2UL << OPA_CSR2_OUTSEL_Pos )

#define OPA_CSR2_TRIMOSN_Pos                    ( 9U )
#define OPA_CSR2_TRIMOSN_Msk                    ( 0x1FUL << OPA_CSR2_TRIMOSN_Pos )
#define OPA_CSR2_TRIMOSN                        ( OPA_CSR2_TRIMOSN_Msk )
#define OPA_CSR2_TRIMOSN_0                      ( 0x1UL << OPA_CSR2_TRIMOSN_Pos )
#define OPA_CSR2_TRIMOSN_1                      ( 0x2UL << OPA_CSR2_TRIMOSN_Pos )
#define OPA_CSR2_TRIMOSN_2                      ( 0x4UL << OPA_CSR2_TRIMOSN_Pos )
#define OPA_CSR2_TRIMOSN_3                      ( 0x8UL << OPA_CSR2_TRIMOSN_Pos )
#define OPA_CSR2_TRIMOSN_4                      ( 0x10UL << OPA_CSR2_TRIMOSN_Pos )

#define OPA_CSR2_TRIMOSP_Pos                    ( 4U )
#define OPA_CSR2_TRIMOSP_Msk                    ( 0x1FUL << OPA_CSR2_TRIMOSP_Pos )
#define OPA_CSR2_TRIMOSP                        ( OPA_CSR2_TRIMOSP_Msk )
#define OPA_CSR2_TRIMOSP_0                      ( 0x1UL << OPA_CSR2_TRIMOSP_Pos )
#define OPA_CSR2_TRIMOSP_1                      ( 0x2UL << OPA_CSR2_TRIMOSP_Pos )
#define OPA_CSR2_TRIMOSP_2                      ( 0x4UL << OPA_CSR2_TRIMOSP_Pos )
#define OPA_CSR2_TRIMOSP_3                      ( 0x8UL << OPA_CSR2_TRIMOSP_Pos )
#define OPA_CSR2_TRIMOSP_4                      ( 0x10UL << OPA_CSR2_TRIMOSP_Pos )

#define OPA_CSR2_CALOUT_Pos                     ( 3U )
#define OPA_CSR2_CALOUT_Msk                     ( 0x1UL << OPA_CSR2_CALOUT_Pos )
#define OPA_CSR2_CALOUT                         ( OPA_CSR2_CALOUT_Msk )

#define OPA_CSR2_CALNEN_Pos                     ( 2U )
#define OPA_CSR2_CALNEN_Msk                     ( 0x1UL << OPA_CSR2_CALNEN_Pos )
#define OPA_CSR2_CALNEN                         ( OPA_CSR2_CALNEN_Msk )

#define OPA_CSR2_CALPEN_Pos                     ( 1U )
#define OPA_CSR2_CALPEN_Msk                     ( 0x1UL << OPA_CSR2_CALPEN_Pos )
#define OPA_CSR2_CALPEN                         ( OPA_CSR2_CALPEN_Msk )

#define OPA_CSR2_EN_Pos                         ( 0U )
#define OPA_CSR2_EN_Msk                         ( 0x1UL << OPA_CSR2_EN_Pos )
#define OPA_CSR2_EN                             ( OPA_CSR2_EN_Msk )


/***************  Bits definition for OPA_CSR3 register  *********************/

#define OPA_CSR3_LOCK_Pos                       ( 31U )
#define OPA_CSR3_LOCK_Msk                       ( 0x1UL << OPA_CSR3_LOCK_Pos )
#define OPA_CSR3_LOCK                           ( OPA_CSR3_LOCK_Msk )

#define OPA_CSR3_REV_Pos                        ( 29U )
#define OPA_CSR3_REV_Msk                        ( 0x3UL << OPA_CSR3_REV_Pos )
#define OPA_CSR3_REV                            ( OPA_CSR3_REV_Msk )
#define OPA_CSR3_REV_0                          ( 0x1UL << OPA_CSR3_REV_Pos )
#define OPA_CSR3_REV_1                          ( 0x2UL << OPA_CSR3_REV_Pos )

#define OPA_CSR3_HSM_Pos                        ( 28U )
#define OPA_CSR3_HSM_Msk                        ( 0x1UL << OPA_CSR3_HSM_Pos )
#define OPA_CSR3_HSM                            ( OPA_CSR3_HSM_Msk )

#define OPA_CSR3_GAINSEL_Pos                    ( 23U )
#define OPA_CSR3_GAINSEL_Msk                    ( 0x1FUL << OPA_CSR3_GAINSEL_Pos )
#define OPA_CSR3_GAINSEL                        ( OPA_CSR3_GAINSEL_Msk )
#define OPA_CSR3_GAINSEL_0                      ( 0x1UL << OPA_CSR3_GAINSEL_Pos )
#define OPA_CSR3_GAINSEL_1                      ( 0x2UL << OPA_CSR3_GAINSEL_Pos )
#define OPA_CSR3_GAINSEL_2                      ( 0x4UL << OPA_CSR3_GAINSEL_Pos )
#define OPA_CSR3_GAINSEL_3                      ( 0x8UL << OPA_CSR3_GAINSEL_Pos )
#define OPA_CSR3_GAINSEL_4                      ( 0x10UL << OPA_CSR3_GAINSEL_Pos )

#define OPA_CSR3_POLSEL_Pos                     ( 21U )
#define OPA_CSR3_POLSEL_Msk                     ( 0x3UL << OPA_CSR3_POLSEL_Pos )
#define OPA_CSR3_POLSEL                         ( OPA_CSR3_POLSEL_Msk )
#define OPA_CSR3_POLSEL_0                       ( 0x1UL << OPA_CSR3_POLSEL_Pos )
#define OPA_CSR3_POLSEL_1                       ( 0x2UL << OPA_CSR3_POLSEL_Pos )

#define OPA_CSR3_VINN0EN_Pos                    ( 20U )
#define OPA_CSR3_VINN0EN_Msk                    ( 0x1UL << OPA_CSR3_VINN0EN_Pos )
#define OPA_CSR3_VINN0EN                        ( OPA_CSR3_VINN0EN_Msk )

#define OPA_CSR3_MODESEL_Pos                    ( 18U )
#define OPA_CSR3_MODESEL_Msk                    ( 0x3UL << OPA_CSR3_MODESEL_Pos )
#define OPA_CSR3_MODESEL                        ( OPA_CSR3_MODESEL_Msk )
#define OPA_CSR3_MODESEL_0                      ( 0x1UL << OPA_CSR3_MODESEL_Pos )
#define OPA_CSR3_MODESEL_1                      ( 0x2UL << OPA_CSR3_MODESEL_Pos )

#define OPA_CSR3_VINPSEL_Pos                    ( 16U )
#define OPA_CSR3_VINPSEL_Msk                    ( 0x3UL << OPA_CSR3_VINPSEL_Pos )
#define OPA_CSR3_VINPSEL                        ( OPA_CSR3_VINPSEL_Msk )
#define OPA_CSR3_VINPSEL_0                      ( 0x1UL << OPA_CSR3_VINPSEL_Pos )
#define OPA_CSR3_VINPSEL_1                      ( 0x2UL << OPA_CSR3_VINPSEL_Pos )

#define OPA_CSR3_OUTSEL_Pos                     ( 14U )
#define OPA_CSR3_OUTSEL_Msk                     ( 0x3UL << OPA_CSR3_OUTSEL_Pos )
#define OPA_CSR3_OUTSEL                         ( OPA_CSR3_OUTSEL_Msk )
#define OPA_CSR3_OUTSEL_0                       ( 0x1UL << OPA_CSR3_OUTSEL_Pos )
#define OPA_CSR3_OUTSEL_1                       ( 0x2UL << OPA_CSR3_OUTSEL_Pos )

#define OPA_CSR3_TRIMOSN_Pos                    ( 9U )
#define OPA_CSR3_TRIMOSN_Msk                    ( 0x1FUL << OPA_CSR3_TRIMOSN_Pos )
#define OPA_CSR3_TRIMOSN                        ( OPA_CSR3_TRIMOSN_Msk )
#define OPA_CSR3_TRIMOSN_0                      ( 0x1UL << OPA_CSR3_TRIMOSN_Pos )
#define OPA_CSR3_TRIMOSN_1                      ( 0x2UL << OPA_CSR3_TRIMOSN_Pos )
#define OPA_CSR3_TRIMOSN_2                      ( 0x4UL << OPA_CSR3_TRIMOSN_Pos )
#define OPA_CSR3_TRIMOSN_3                      ( 0x8UL << OPA_CSR3_TRIMOSN_Pos )
#define OPA_CSR3_TRIMOSN_4                      ( 0x10UL << OPA_CSR3_TRIMOSN_Pos )

#define OPA_CSR3_TRIMOSP_Pos                    ( 4U )
#define OPA_CSR3_TRIMOSP_Msk                    ( 0x1FUL << OPA_CSR3_TRIMOSP_Pos )
#define OPA_CSR3_TRIMOSP                        ( OPA_CSR3_TRIMOSP_Msk )
#define OPA_CSR3_TRIMOSP_0                      ( 0x1UL << OPA_CSR3_TRIMOSP_Pos )
#define OPA_CSR3_TRIMOSP_1                      ( 0x2UL << OPA_CSR3_TRIMOSP_Pos )
#define OPA_CSR3_TRIMOSP_2                      ( 0x4UL << OPA_CSR3_TRIMOSP_Pos )
#define OPA_CSR3_TRIMOSP_3                      ( 0x8UL << OPA_CSR3_TRIMOSP_Pos )
#define OPA_CSR3_TRIMOSP_4                      ( 0x10UL << OPA_CSR3_TRIMOSP_Pos )

#define OPA_CSR3_CALOUT_Pos                     ( 3U )
#define OPA_CSR3_CALOUT_Msk                     ( 0x1UL << OPA_CSR3_CALOUT_Pos )
#define OPA_CSR3_CALOUT                         ( OPA_CSR3_CALOUT_Msk )

#define OPA_CSR3_CALNEN_Pos                     ( 2U )
#define OPA_CSR3_CALNEN_Msk                     ( 0x1UL << OPA_CSR3_CALNEN_Pos )
#define OPA_CSR3_CALNEN                         ( OPA_CSR3_CALNEN_Msk )

#define OPA_CSR3_CALPEN_Pos                     ( 1U )
#define OPA_CSR3_CALPEN_Msk                     ( 0x1UL << OPA_CSR3_CALPEN_Pos )
#define OPA_CSR3_CALPEN                         ( OPA_CSR3_CALPEN_Msk )

#define OPA_CSR3_EN_Pos                         ( 0U )
#define OPA_CSR3_EN_Msk                         ( 0x1UL << OPA_CSR3_EN_Pos )
#define OPA_CSR3_EN                             ( OPA_CSR3_EN_Msk )




///*-----------  Peripheral_Registers_Bits_Definition END  -----------------*/


typedef enum 
{
  RESET = 0U, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;



#define SET_BIT(REG, BIT)      ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)    ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)     ((REG) & (BIT))
#define CLEAR_REG(REG)         ((REG) = (0x0))
#define WRITE_REG(REG, VAL)    ((REG) = (VAL))
#define READ_REG(REG)          ((REG))
#define MODIFY_REG(REG,MASK,BITS) ((REG) = (((REG)&(~(MASK)))|((BITS)&(MASK))))
#define POSITION_VAL(VAL)      (__CLZ(__RBIT(VAL)))


#endif  /* __ACM32G103_H */
