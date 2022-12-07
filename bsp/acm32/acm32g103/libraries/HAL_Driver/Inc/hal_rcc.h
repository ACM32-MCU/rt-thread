
/******************************************************************************
*@file  : hal_rcc.h
*@brief : Header file of RCC HAL module.
******************************************************************************/

#ifndef __HAL_RCC_H__
#define __HAL_RCC_H__

#include "acm32g103_hal_conf.h"
    

/**
  * @brief  RCC PLL configuration structure definition
  */
typedef struct
{
    uint32_t    PLL;            /*!< The new state of the PLL.
                                     This parameter can be a value of @ref FunctionalState                      */

    uint32_t    PLLSource;      /*!< RCC_PLLSource: PLL entry clock source.
                                     This parameter must be a value of @ref RCC_PLL_Source                      */

    uint32_t    PLLM;           /*!< PLLM: Output frequency division control field.
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 3      */

    uint32_t    PLLN;           /*!< PLLN: the frequency division factor of the reference frequency.
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 7      */                        

    uint32_t    PLLF;           /*!< PLLP:  the frequency multiplication factor of the reference frequency..
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 31     */

}RCC_PLLInitTypeDef;

/**
  * @brief  RCC Internal/External Oscillator (RC64M, RC32K, XTH, and XTL) or PLL 
  *         configuration structure definition
  */

typedef struct
{
    uint32_t    OscType;        /*!< The oscillators or PLL to be configured.
                                     This parameter can be a value of @ref RCC_Oscillator_Type      */
    
    uint32_t    RC64M;          /*!< The new state of the RC64M.
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    RC64MDiv16;     /*!< If the system clock is RC64M, the system clock will change 
                                     to 1/16 of the original after this position is ENABLE.
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    RC32K;          /*!< The new state of the RC32K.
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    XTH;            /*!< The new state of the XTH.
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    XTHBypass;      /*!< XTH oscillator bypass
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    XTL;            /*!< The new state of the RC32K.
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    XTLBypass;      /*!< XTL oscillator bypass
                                     This parameter can be a value of @ref FunctionalState          */
    
    uint32_t    XTLDrive;       /*!< XTL oscillator drive capability
                                     This parameter can be a value of @ref RCC_XTL_Drive_Capacity   */
    
    RCC_PLLInitTypeDef  PLL;    /*!< PLL structure parameters                                       */
    
}RCC_OscInitTypeDef;


/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  */
typedef struct
{
    uint32_t    SYSCLKSource;   /*!< The system clock source.
                                     This parameter can be a value of @ref RCC_Sysclk_Source        */

    uint32_t    SYSCLKDiv0;     /*!< First level frequency division of system clock.
                                     This parameter can be a value of @ref RCC_Sysclk_DIV0          */

    uint32_t    SYSCLKDiv1;     /*!< Second level frequency division of system clock.
                                     This parameter can be a value of @ref RCC_Sysclk_DIV1          */

    uint32_t    PCLK1Div;       /*!< PCLK1 (the APB1 clock) divider.
                                     This parameter can be a value of @ref RCC_PCLK1_DIV            */
    
    uint32_t    PCLK2Div;       /*!< PCLK2 (the APB2 clock) divider.
                                     This parameter can be a value of @ref RCC_PCLK2_DIV            */
    
}RCC_ClkInitTypeDef;

/**
  * @brief  RCC MCO configuration structure definition
  */

typedef struct
{
    uint32_t    Output;         /*!< MCO output select.
                                     This parameter can be a value of @ref RCC_MCO_Output                       */
    
    uint32_t    MCO1;           /*!< The new state of the MCO1.
                                     This parameter can be a value of @ref FunctionalState                      */
    
    uint32_t    MCO1Div;        /*!< MCO11 clock divider.
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 65535  */
    
    uint32_t    MCO1RevPol;     /*!< The new state of the MCO1 clock reverse polarity.
                                     This parameter can be a value of @ref FunctionalState                      */
    
    uint32_t    MCO2;           /*!< The new state of the MCO2.
                                     This parameter can be a value of @ref FunctionalState                      */
    
    uint32_t    MCO2Div;        /*!< MCO2 clock divider.
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 63     */
    
    uint32_t    MCO2RevPol;     /*!< The new state of the MCO2 clock reverse polarity.
                                     This parameter can be a value of @ref FunctionalState                      */
    
}RCC_MCOInitTypeDef;

/** @defgroup RCC_Private_Constants
  * @{
  */

#define RCC_RC64M_TIMEOUT                       ( 0xFFFFU )
#define RCC_RC32K_TIMEOUT                       ( 0xFFFFU )
#define RCC_XTH_TIMEOUT                         ( 0xFFFFU )
#define RCC_XTL_TIMEOUT                         ( 0xFFFFU )
#define RCC_PLL_TIMEOUT                         ( 0xFFFFU )
#define RCC_DIV_TIMEOUT                         ( 0xFFFFU )

/**
  * @}
  */

/** @defgroup RCC_Oscillator_Type
  * @{
  */

#define RCC_OSCTYPE_RC64M                       ( 0x01U )
#define RCC_OSCTYPE_RC32K                       ( 0x02U )
#define RCC_OSCTYPE_XTH                         ( 0x04U )
#define RCC_OSCTYPE_XTL                         ( 0x08U )
#define RCC_OSCTYPE_PLL                         ( 0x10U )

/**
  * @}
  */
  
/** @brief  Oscillator type mask for assert test
  */

#define RCC_OSCTYPE_MASK                        ( RCC_OSCTYPE_RC64M | RCC_OSCTYPE_RC32K | RCC_OSCTYPE_XTH | RCC_OSCTYPE_XTL | RCC_OSCTYPE_PLL )

/** @brief  Reset the whole system except for analog IP, EFC, SENSOR and system register module.
  */

#define __HAL_RCC_RESET()                       ( RCC->RCR &= ~(RCC_RCR_SRSTMAP) )

/** @brief  Reset the whole system except for analog IP, EFC, SENSOR and system register module, 
  *         but does not change the REMap state.
  */

#define __HAL_RCC_RESET_NO_MAP()                ( RCC->RCR &= ~(RCC_RCR_SRSTNOMAP) )

/** @brief  Flash Reset.
  */

#define __HAL_RCC_RESET_EFC()                   ( RCC->RCR &= ~(RCC_RCR_EFCRST) )

/** @brief  Enable or disable the remap.
  */

#define __HAL_RCC_REMAP_ENABLE()                do                                      \
                                                {                                       \
                                                    RCC->RCR &= ~RCC_RCR_REMAPIMP;      \
                                                    RCC->RCR |= RCC_RCR_REMAPIMP;       \
                                                } while (0)
#define __HAL_RCC_REMAP_DISABLE()               ( RCC->RCR &= ~(RCC_RCR_REMAPIMP) )
          
/** @brief  Enable or disable LOCKUP to reset system logic.
  */

#define __HAL_RCC_LOCKRSTTOSYSRST_ENABLE()              ( RCC->RCR |= (RCC_RCR_LOCKRSTEN) )
#define __HAL_RCC_LOCKRSTTOSYSRST_DISABLE()             ( RCC->RCR &= ~(RCC_RCR_LOCKRSTEN) )
          
/** @brief  Enable or disable IWDT reset to reset system logic.
  */

#define __HAL_RCC_IWDTRSTTOSYSRST_ENABLE()              ( RCC->RCR |= (RCC_RCR_IWDTRSTEN) )
#define __HAL_RCC_IWDTRSTTOSYSRST_DISABLE()             ( RCC->RCR &= ~(RCC_RCR_IWDTRSTEN) )
          
/** @brief  Enable or disable WDT reset to reset system logic.
  */

#define __HAL_RCC_WDTRSTTOSYSRST_ENABLE()               ( RCC->RCR |= (RCC_RCR_WDTRSTEN) )
#define __HAL_RCC_WDTRSTTOSYSRST_DISABLE()              ( RCC->RCR &= ~(RCC_RCR_WDTRSTEN) )
          
/** @brief  Enable or disable LVD reset to reset system logic.
  */

#define __HAL_RCC_LVDRSTTOSYSRST_ENABLE()               ( RCC->RCR |= (RCC_RCR_LVDRSTEN) )
#define __HAL_RCC_LVDRSTTOSYSRST_DISABLE()              ( RCC->RCR &= ~(RCC_RCR_LVDRSTEN) )

/** @defgroup  RCC_Reset_Source RCC Reset Source
  * @{
  */

#define RCC_RESETSOURCE_PWR                     ( RCC_RSR_PWRRSTF )
#define RCC_RESETSOURCE_POR12                   ( RCC_RSR_POR12RSTF )
#define RCC_RESETSOURCE_SOFT                    ( RCC_RSR_SRSTF )
#define RCC_RESETSOURCE_NOMAP                   ( RCC_RSR_SRSTNMF )
#define RCC_RESETSOURCE_EFC                     ( RCC_RSR_EFCRSTF )
#define RCC_RESETSOURCE_RSTN                    ( RCC_RSR_RSTNF )
#define RCC_RESETSOURCE_SYSREQ                  ( RCC_RSR_SYSREQRSTF )
#define RCC_RESETSOURCE_LOCKUP                  ( RCC_RSR_LOCKUPRSTF )
#define RCC_RESETSOURCE_IWDT                    ( RCC_RSR_IWDTRSTF )
#define RCC_RESETSOURCE_WDT                     ( RCC_RSR_WDTRSTF )
#define RCC_RESETSOURCE_LVD                     ( RCC_RSR_LVDRSTF )

/**
  * @}
  */
  
/** @brief Clear Reset Source. 
  */

#define __HAL_RCC_CLEAR_RESETSOURCE()           ( RCC->RSR |= RCC_RSR_RSTFLAGCLR )

/** @brief  Check Reset Source. The returned value can be a or more value of @ref RCC_Reset_Source
  */
  
#define __HAL_RCC_GET_RESETSOURCE()             ( RCC->RSR & (RCC_RESETSOURCE_PWR | RCC_RESETSOURCE_POR12 | \
                                                              RCC_RESETSOURCE_SOFT | RCC_RESETSOURCE_NOMAP | \
                                                              RCC_RESETSOURCE_EFC | RCC_RESETSOURCE_RSTN | \
                                                              RCC_RESETSOURCE_SYSREQ | RCC_RESETSOURCE_LOCKUP | \
                                                              RCC_RESETSOURCE_IWDT | RCC_RESETSOURCE_WDT | \
                                                              RCC_RESETSOURCE_LVD))

/******************************************************************************/

/** @defgroup RCC_Sysclk_Source
  */

#define RCC_SYSCLKSOURCE_RC64M                  ( 0U )
#define RCC_SYSCLKSOURCE_RC32K                  ( RCC_CCR1_SYSCLKSEL_0 )
#define RCC_SYSCLKSOURCE_XTH                    ( RCC_CCR1_SYSCLKSEL_1 )
#define RCC_SYSCLKSOURCE_XTL                    ( RCC_CCR1_SYSCLKSEL_1 | RCC_CCR1_SYSCLKSEL_0 )
#define RCC_SYSCLKSOURCE_PLLCLK                 ( RCC_CCR1_SYSCLKSEL_2 )

/**
  * @}
  */

/** @brief RCC Flag. 
  */

#define RCC_FLAG_DIV_DONE                       ( RCC_CCR2_DIVDONE )

/** @defgroup RCC_LPTIM1_CLK_Source
  */

#define RCC_LPTIM1CLKSOURCE_PCLK                ( 0U )
#define RCC_LPTIM1CLKSOURCE_RC32K               ( RCC_CCR2_LPTLCKSEL_0 )
#define RCC_LPTIM1CLKSOURCE_RC64M               ( RCC_CCR2_LPTLCKSEL_1 )
#define RCC_LPTIM1CLKSOURCE_XTL                 ( RCC_CCR2_LPTLCKSEL_1 | RCC_CCR2_LPTLCKSEL_0 )

/**
  * @}
  */

/** @defgroup RCC_FLT_CLK_Source
  */

#define RCC_FLTCLKSOURCE_PCLK_DIV32             ( 0U )
#define RCC_FLTCLKSOURCE_RC32K                  ( RCC_CCR2_FLTCLKSEL )

/**
  * @}
  */

/** @defgroup RCC_LPUART1_CLK_Source
  */

#define RCC_LPUART1CLKSOURCE_RC32K              ( 0U )
#define RCC_LPUART1CLKSOURCE_XTL                ( RCC_CCR2_LPUARTDIV_0 )
#define RCC_LPUART1CLKSOURCE_PCLK_DIV4          ( RCC_CCR2_LPUARTDIV_1 )
#define RCC_LPUART1CLKSOURCE_PCLK_DIV8          ( RCC_CCR2_LPUARTDIV_1 | RCC_CCR2_PCLK2DIV_0 )
#define RCC_LPUART1CLKSOURCE_PCLK_DIV16         ( RCC_CCR2_LPUARTDIV_1 | RCC_CCR2_PCLK2DIV_1 )
#define RCC_LPUART1CLKSOURCE_PCLK_DIV32         ( RCC_CCR2_LPUARTDIV_1 | RCC_CCR2_PCLK2DIV_1 | RCC_CCR2_PCLK2DIV_0 )

/**
  * @}
  */

/** @defgroup RCC_PCLK2_DIV
  */

#define RCC_PCLK2_DIV_1                         ( 0U )
#define RCC_PCLK2_DIV_2                         ( RCC_CCR2_PCLK2DIV_2 )
#define RCC_PCLK2_DIV_4                         ( RCC_CCR2_PCLK2DIV_2 | RCC_CCR2_PCLK2DIV_0)
#define RCC_PCLK2_DIV_8                         ( RCC_CCR2_PCLK2DIV_2 | RCC_CCR2_PCLK2DIV_1 )
#define RCC_PCLK2_DIV_16                        ( RCC_CCR2_PCLK2DIV_2 | RCC_CCR2_PCLK2DIV_1 | RCC_CCR2_PCLK2DIV_0 )

/**
  * @}
  */

/** @defgroup RCC_PCLK1_DIV
  */

#define RCC_PCLK1_DIV_1                         ( 0U )
#define RCC_PCLK1_DIV_2                         ( RCC_CCR2_PCLK1DIV_2 )
#define RCC_PCLK1_DIV_4                         ( RCC_CCR2_PCLK1DIV_2 | RCC_CCR2_PCLK1DIV_0)
#define RCC_PCLK1_DIV_8                         ( RCC_CCR2_PCLK1DIV_2 | RCC_CCR2_PCLK1DIV_1 )
#define RCC_PCLK1_DIV_16                        ( RCC_CCR2_PCLK1DIV_2 | RCC_CCR2_PCLK1DIV_1 | RCC_CCR2_PCLK1DIV_0 )

/**
  * @}
  */

/** @defgroup RCC_Sysclk_DIV1
  */

#define RCC_SYSDIV1_DIV_1                       ( 0U )
#define RCC_SYSDIV1_DIV_2                       ( RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_3                       ( RCC_CCR2_SYSDIV1_1 )
#define RCC_SYSDIV1_DIV_4                       ( RCC_CCR2_SYSDIV1_1 | RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_5                       ( RCC_CCR2_SYSDIV1_2 )
#define RCC_SYSDIV1_DIV_6                       ( RCC_CCR2_SYSDIV1_2 | RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_7                       ( RCC_CCR2_SYSDIV1_2 | RCC_CCR2_SYSDIV1_1 )
#define RCC_SYSDIV1_DIV_8                       ( RCC_CCR2_SYSDIV1_2 | RCC_CCR2_SYSDIV1_1 | RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_9                       ( RCC_CCR2_SYSDIV1_3 )
#define RCC_SYSDIV1_DIV_10                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_11                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_1 )
#define RCC_SYSDIV1_DIV_12                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_1 | RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_13                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_2 )
#define RCC_SYSDIV1_DIV_14                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_2 | RCC_CCR2_SYSDIV1_0 )
#define RCC_SYSDIV1_DIV_15                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_2 | RCC_CCR2_SYSDIV1_1 )
#define RCC_SYSDIV1_DIV_16                      ( RCC_CCR2_SYSDIV1_3 | RCC_CCR2_SYSDIV1_2 | RCC_CCR2_SYSDIV1_1 | RCC_CCR2_SYSDIV1_0 )

/**
  * @}
  */

/** @defgroup RCC_Sysclk_DIV0
  */

#define RCC_SYSDIV0_DIV_1                       ( 0U )
#define RCC_SYSDIV0_DIV_2                       ( RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_3                       ( RCC_CCR2_SYSDIV0_1 )
#define RCC_SYSDIV0_DIV_4                       ( RCC_CCR2_SYSDIV0_1 | RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_5                       ( RCC_CCR2_SYSDIV0_2 )
#define RCC_SYSDIV0_DIV_6                       ( RCC_CCR2_SYSDIV0_2 | RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_7                       ( RCC_CCR2_SYSDIV0_2 | RCC_CCR2_SYSDIV0_1 )
#define RCC_SYSDIV0_DIV_8                       ( RCC_CCR2_SYSDIV0_2 | RCC_CCR2_SYSDIV0_1 | RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_9                       ( RCC_CCR2_SYSDIV0_3 )
#define RCC_SYSDIV0_DIV_10                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_11                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_1 )
#define RCC_SYSDIV0_DIV_12                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_1 | RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_13                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_2 )
#define RCC_SYSDIV0_DIV_14                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_2 | RCC_CCR2_SYSDIV0_0 )
#define RCC_SYSDIV0_DIV_15                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_2 | RCC_CCR2_SYSDIV0_1 )
#define RCC_SYSDIV0_DIV_16                      ( RCC_CCR2_SYSDIV0_3 | RCC_CCR2_SYSDIV0_2 | RCC_CCR2_SYSDIV0_1 | RCC_CCR2_SYSDIV0_0 )

/**
  * @}
  */

/** @defgroup RCC_Interrupt
  */

#define RCC_IT_RC32K                            ( RCC_CIR_RC32KRDYIE )
#define RCC_IT_XTL                              ( RCC_CIR_XTLRDYIE )
#define RCC_IT_RC64M                            ( RCC_CIR_RC64MRDYIE )
#define RCC_IT_XTH                              ( RCC_CIR_XTHRDYIE )
#define RCC_IT_PLLL                             ( RCC_CIR_PLLLOCKIE )

/**
  * @}
  */

/** @brief  Enable or disable Interrupt. This parameter can be a or more value of @ref RCC_Interrupt.
  */

#define __HAL_RCC_ENABLE_IT(__INTERRUPT__)      ( RCC->CIR |= (__INTERRUPT__) )
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__)     ( RCC->CIR &= ~(__INTERRUPT__) )

/** @brief  Check Interrupt. The returned value can be a or more value of @ref RCC_Interrupt
  */

#define __HAL_RCC_GET_IT(__INTERRUPT__)         ( RCC->CIR & ((__INTERRUPT__) >> 8) )

/** @brief  Clear Interrupt Flag. This parameter can be a or more value of @ref RCC_Interrupt.
  */

#define __HAL_RCC_CLEAR_IT(__INTERRUPT__)       ( RCC->CIR |= ((__INTERRUPT__) << 8) )

/** @brief  RC64M 16 frequency division.
  */

#define RCC_RC64M_DIV_1                         ( 0U )
#define RCC_RC64M_DIV_16                        ( RCC_RC64MCR_RC64MDIV )

/** @brief  Enable or disable RC64M.
  */

#define __HAL_RCC_RC64M_ENABLE()                ( RCC->RC64MCR |= RCC_RC64MCR_RC64MEN )
#define __HAL_RCC_RC64M_DISABLE()               ( RCC->RC64MCR &= ~RCC_RC64MCR_RC64MEN )

/** @brief  Check whether the RC64M clock is stable.
  */

#define __HAL_RCC_RC64M_ISREADY()               ( (RCC->RC64MCR & RCC_RC64MCR_RC64MRDY) != 0U )

/** @brief  The RC64M clock stable time.
  */

#define RCC_XTH_STABILITY_1024                  ( 0U )
#define RCC_XTH_STABILITY_4096                  ( RCC_XTHCR_XTHRDYTIME_0 )
#define RCC_XTH_STABILITY_16384                 ( RCC_XTHCR_XTHRDYTIME_1 )
#define RCC_XTH_STABILITY_32768                 ( RCC_XTHCR_XTHRDYTIME_1 | RCC_XTHCR_XTHRDYTIME_0 )

/** @brief  Enable or disable XTH bypass mode.
  */

#define __HAL_RCC_XTH_BYPASS_ENABLE()           ( RCC->XTHCR |= RCC_XTHCR_XTHBYP )
#define __HAL_RCC_XTH_BYPASS_DISABLE()          ( RCC->XTHCR &= ~RCC_XTHCR_XTHBYP )

/** @brief  Enable or disable XTH.
  */

#define __HAL_RCC_XTH_ENABLE()                  ( RCC->XTHCR |= RCC_XTHCR_XTHEN )
#define __HAL_RCC_XTH_DISABLE()                 ( RCC->XTHCR &= ~RCC_XTHCR_XTHEN )

/** @brief  Check whether the XTH clock is stable.
  */

#define __HAL_RCC_XTH_ISREADY()                 ( (RCC->XTHCR & RCC_XTHCR_XTHRDY) != 0U )

/** @brief  RCC PLL Lock Source.
  */

#define RCC_PLLLOCKSOURCE_LOCK                  ( 0U )
#define RCC_PLLLOCKSOURCE_FREE                  ( RCC_PLLCR_PLLLOCKSEL )

/** @defgroup RCC_PLL_Source
  */

#define RCC_PLLSOURCE_RC64M_DIV16               ( 0U )
#define RCC_PLLSOURCE_XTH                       ( RCC_PLLCR_PLLSRCSEL_1 )

/**
  * @}
  */

/** @brief  Check whether the PLL clock is stable.
  */

#define __HAL_RCC_PLL_ISREADY()                 ( (RCC->PLLCR & RCC_PLLCR_PLLFREERUN) != 0U )

/** @brief  The PLL configuration updates the control bit. 
  * @note   Rewrite PLL_M¡¢PLL_N and PLL_F¡¢PLL_SRC After SEL, 
  *         this bit needs to be set to a new configuration to take effect.
  */

#define __HAL_RCC_PLLUPDATE()                   ( RCC->PLLCR |= RCC_PLLCR_PLLUPDATEEN )

/** @brief  Enable or disable PLL sleep.
  */

#define __HAL_RCC_PLLSLEEP_ENABLE()             ( RCC->PLLCR |= RCC_PLLCR_PLLSLEEP )
#define __HAL_RCC_PLLSLEEP_DISABLE()            ( RCC->PLLCR &= ~RCC_PLLCR_PLLSLEEP )

/** @brief  Enable or disable PLL.
  */

#define __HAL_RCC_PLL_ENABLE()                  ( RCC->PLLCR |= RCC_PLLCR_PLLEN )
#define __HAL_RCC_PLL_DISABLE()                 ( RCC->PLLCR &= ~RCC_PLLCR_PLLEN )

/** @defgroup RCC_MCO_Output
  */

#define RCC_MCO_NONE                            ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_2 | RCC_CLKOCR_CLKTESTSEL_1 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_HCLK                            ( 0U )
#define RCC_MCO_RC64M                           ( RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_RC32K                           ( RCC_CLKOCR_CLKTESTSEL_1 )
#define RCC_MCO_XTH                             ( RCC_CLKOCR_CLKTESTSEL_1 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_XTL                             ( RCC_CLKOCR_CLKTESTSEL_2 )
#define RCC_MCO_PLLCLK                          ( RCC_CLKOCR_CLKTESTSEL_2 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_PCLK1                           ( RCC_CLKOCR_CLKTESTSEL_2 | RCC_CLKOCR_CLKTESTSEL_1 )
#define RCC_MCO_PCLK2                           ( RCC_CLKOCR_CLKTESTSEL_2 | RCC_CLKOCR_CLKTESTSEL_1 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_SYSCLK                          ( RCC_CLKOCR_CLKTESTSEL_3 )
#define RCC_MCO_TIMCLK1                         ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_TIMCLK2                         ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_1 )
#define RCC_MCO_LPUARTCLK                       ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_1 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_SYSTICK                         ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_2 )
#define RCC_MCO_USBPHYPLL48M                    ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_2 | RCC_CLKOCR_CLKTESTSEL_0 )
#define RCC_MCO_RTC_PCLK                        ( RCC_CLKOCR_CLKTESTSEL_3 | RCC_CLKOCR_CLKTESTSEL_2 | RCC_CLKOCR_CLKTESTSEL_1 )

/**
  * @}
  */

/** @brief  Check whether the XTL clock is stable.
  */

#define __HAL_RCC_XTL_ISREADY()                 ( (RCC->STDBYCTRL & RCC_STDBYCTRL_XTLRDY) != 0U )

/** @brief  Check whether the RC32K clock is stable.
  */

#define __HAL_RCC_RC32K_ISREADY()               ( (RCC->STDBYCTRL & RCC_STDBYCTRL_RC32KRDY) != 0U )

/** @brief  Enable or disable RC32K.
  */

#define __HAL_RCC_RC32K_ENABLE()                ( RCC->STDBYCTRL |= RCC_STDBYCTRL_RC32EN )
#define __HAL_RCC_RC32K_DISABLE()               ( RCC->STDBYCTRL &= ~RCC_STDBYCTRL_RC32EN )

/** @defgroup RCC_RTC_Clock_Source
  */

#define RCC_RTCCLKSOURCE_RC32K                  ( 0U )
#define RCC_RTCCLKSOURCE_XTL                    ( RCC_STDBYCTRL_RTCSEL_0 )

/**
  * @}
  */

/** @brief  Enable or disable RTC clock.
  */

#define __HAL_RCC_RTCCLK_ENABLE()               ( RCC->STDBYCTRL |= RCC_STDBYCTRL_RTCEN )
#define __HAL_RCC_RTCCLK_DISABLE()              ( RCC->STDBYCTRL &= ~RCC_STDBYCTRL_RTCEN )

/** @defgroup RCC_XTL_Drive_Capacity.
  */

#define RCC_XTL_DRIVE_LOW                       ( 0U )
#define RCC_XTL_DRIVE_HIGH                      ( RCC_STDBYCTRL_XTLDRV_1 | RCC_STDBYCTRL_XTLDRV_0 )
#define RCC_XTL_DRIVE_LOW_WITH_LOWPOWER         ( RCC_STDBYCTRL_XTLDRV_2 )
#define RCC_XTL_DRIVE_HIGH_WITH_HIGH_POWER      ( RCC_STDBYCTRL_XTLDRV_2 | RCC_STDBYCTRL_XTLDRV_1 | RCC_STDBYCTRL_XTLDRV_0 )

/**
  * @}
  */

/** @brief  the APB1 peripheral reset.
  */

#define __HAL_RCC_LPUART1_RESET()               do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_LPUART1RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_LPUART1RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_LPTIM1_RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_LPTIM1RST;     \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_LPTIM1RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_PMU_RESET()                   do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_PMURST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_PMURST;          \
                                                }while (0)
                                                
#define __HAL_RCC_CAN2_RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_CAN2RST;        \
                                                }while (0)
                                                
#define __HAL_RCC_CAN1_RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST;         \
                                                }while (0)
                                                
#define __HAL_RCC_I2C2__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_I2C1__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_UART4__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST;     \
                                                }while (0)
                                                
#define __HAL_RCC_UART3__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART3RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_UART3RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_UART2__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART2RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_UART2RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_I2S2__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2S2RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_I2S2RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_I2S1__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2S1RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_I2S1RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_WDT__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_WDTRST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_WDTRST;        \
                                                }while (0)
                                                
#define __HAL_RCC_RTC__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_RTCRST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_RTCRST;        \
                                                }while (0)
                                                
#define __HAL_RCC_TIM7__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM7RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_TIM7RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_TIM6__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_TIM4__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_TIM4RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_TIM3__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_TIM3RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_TIM2__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB1RSTR |= RCC_APB1RSTR_TIM2RST;       \
                                                }while (0)

/** @brief  The APB2 peripheral reset.
  */

#define __HAL_RCC_TIM17__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM17RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_TIM17RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_TIM16__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM16RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_TIM16RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_TIM15__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM15RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_TIM15RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_UART1__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_UART1RST;      \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_UART1RST;      \
                                                }while (0)
                                                
#define __HAL_RCC_TIM8__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM8RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_TIM1__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST;       \
                                                }while (0)
                                                
#define __HAL_RCC_EXTI__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_EXTIRST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_EXTIRST;       \
                                                }while (0)
                                                
#define __HAL_RCC_OPA__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_OPARST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_OPARST;        \
                                                }while (0)
                                                
#define __HAL_RCC_CMP__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_CMPRST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_CMPRST;        \
                                                }while (0)
                                                
#define __HAL_RCC_VREFBUF__RESET()              do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_VREFBUFRST;    \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_VREFBUFRST;    \
                                                }while (0)
                                                
#define __HAL_RCC_SYSCFG__RESET()               do                                                  \
                                                {                                                   \
                                                    RCC->APB2RSTR &= ~RCC_APB2RSTR_SYSCFGRST;     \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST;     \
                                                }while (0)
                                                
/** @brief  The AHB peripheral reset.
  */

#define __HAL_RCC_EXMC__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_MIMRST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_MIMRST;         \
                                                }while (0)

#define __HAL_RCC_ROM__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_ROMRST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_ROMRST;         \
                                                }while (0)

#define __HAL_RCC_FAU__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_FAURST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_FAURST;         \
                                                }while (0)

#define __HAL_RCC_HRNG__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_HRNGRST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_HRNGRST;        \
                                                }while (0)

#define __HAL_RCC_AES__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_AESRST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_AESRST;         \
                                                }while (0)

#define __HAL_RCC_DAC1__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_DAC1RST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_DAC1RST;        \
                                                }while (0)

#define __HAL_RCC_ADC12__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_ADC12RST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_ADC12RST;       \
                                                }while (0)

#define __HAL_RCC_GPIOF__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOFRST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOFRST;       \
                                                }while (0)

#define __HAL_RCC_GPIOE__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOERST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOERST )       \
                                                }while (0)

#define __HAL_RCC_GPIOD__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIODRST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_GPIODRST;       \
                                                }while (0)

#define __HAL_RCC_GPIOC__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOCRST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOCRST;       \
                                                }while (0)

#define __HAL_RCC_GPIOB__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOBRST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOBRST;       \
                                                }while (0)

#define __HAL_RCC_GPIOA__RESET()                do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOARST;       \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST;       \
                                                }while (0)

#define __HAL_RCC_SPI3__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_SPI3RST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_SPI3RST;        \
                                                }while (0)

#define __HAL_RCC_SPI2__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_SPI2RST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_SPI2RST;        \
                                                }while (0)

#define __HAL_RCC_SPI1__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_SPI1RST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_SPI1RST;        \
                                                }while (0)

#define __HAL_RCC_CRC__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_CRCRST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_CRCRST;        \
                                                }while (0)

#define __HAL_RCC_USB__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_USBRST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_USBRST;         \
                                                }while (0)

#define __HAL_RCC_EFC__RESET()                  do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_EFCRST;         \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_EFCRST;         \
                                                }while (0)

#define __HAL_RCC_SRAM__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_SRAMRST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_SRAMRST;        \
                                                }while (0)

#define __HAL_RCC_DMA2__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_DMA2RST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_DMA2RST;        \
                                                }while (0)

#define __HAL_RCC_DMA1__RESET()                 do                                                  \
                                                {                                                   \
                                                    RCC->AHBRSTR &= ~RCC_AHBRSTR_DMA1RST;        \
                                                    __NOP();__NOP();__NOP();                        \
                                                    RCC->AHBRSTR |= RCC_AHBRSTR_DMA1RST;        \
                                                }while (0)

/** @brief  Enable or disable the APB1 peripheral clock.
  */

#define __HAL_RCC_LPUART1_CLK_ENABLE()          ( RCC->APB1ENR |= (RCC_APB1ENR_LPUART1CKEN) )
#define __HAL_RCC_LPTIM1_CLK_ENABLE()           ( RCC->APB1ENR |= (RCC_APB1ENR_LPTIM1CKEN) )
#define __HAL_RCC_PMU_CLK_ENABLE()              ( RCC->APB1ENR |= (RCC_APB1ENR_PMUCKEN) )
#define __HAL_RCC_CAN2_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_CAN2CKEN) )
#define __HAL_RCC_CAN1_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_CAN1CKEN) )
#define __HAL_RCC_I2C2_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_I2C2CKEN) )
#define __HAL_RCC_I2C1_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_I2C1CKEN) )
#define __HAL_RCC_UART4_CLK_ENABLE()            ( RCC->APB1ENR |= (RCC_APB1ENR_UART4CKEN) )
#define __HAL_RCC_UART3_CLK_ENABLE()            ( RCC->APB1ENR |= (RCC_APB1ENR_UART3CKEN) )
#define __HAL_RCC_UART2_CLK_ENABLE()            ( RCC->APB1ENR |= (RCC_APB1ENR_UART2CKEN) )
#define __HAL_RCC_I2S2_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_I2S2CKEN) )
#define __HAL_RCC_I2S1_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_I2S1CKEN) )
#define __HAL_RCC_WDT_CLK_ENABLE()              ( RCC->APB1ENR |= (RCC_APB1ENR_WDTCKEN) )
#define __HAL_RCC_RTC_CLK_ENABLE()              ( RCC->APB1ENR |= (RCC_APB1ENR_RTCCKEN) )
#define __HAL_RCC_TIM7_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_TIM7CKEN) )
#define __HAL_RCC_TIM6_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_TIM6CKEN) )
#define __HAL_RCC_TIM4_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_TIM4CKEN) )
#define __HAL_RCC_TIM3_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_TIM3CKEN) )
#define __HAL_RCC_TIM2_CLK_ENABLE()             ( RCC->APB1ENR |= (RCC_APB1ENR_TIM2CKEN) )

#define __HAL_RCC_LPUART1_CLK_DISABLE()         ( RCC->APB1ENR &= ~(RCC_APB1ENR_LPUART1CKEN) )
#define __HAL_RCC_LPTIM1_CLK_DISABLE()          ( RCC->APB1ENR &= ~(RCC_APB1ENR_LPTIM1CKEN) )
#define __HAL_RCC_PMU_CLK_DISABLE()             ( RCC->APB1ENR &= ~(RCC_APB1ENR_PMUCKEN) )
#define __HAL_RCC_CAN2_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_CAN2CKEN) )
#define __HAL_RCC_CAN1_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_CAN1CKEN) )
#define __HAL_RCC_I2C2_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2CKEN) )
#define __HAL_RCC_I2C1_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_I2C1CKEN) )
#define __HAL_RCC_UART4_CLK_DISABLE()           ( RCC->APB1ENR &= ~(RCC_APB1ENR_UART4CKEN) )
#define __HAL_RCC_UART3_CLK_DISABLE()           ( RCC->APB1ENR &= ~(RCC_APB1ENR_UART3CKEN) )
#define __HAL_RCC_UART2_CLK_DISABLE()           ( RCC->APB1ENR &= ~(RCC_APB1ENR_UART2CKEN) )
#define __HAL_RCC_I2S2_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_I2S2CKEN) )
#define __HAL_RCC_I2S1_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_I2S1CKEN) )
#define __HAL_RCC_WDT_CLK_DISABLE()             ( RCC->APB1ENR &= ~(RCC_APB1ENR_WDTCKEN) )
#define __HAL_RCC_RTC_CLK_DISABLE()             ( RCC->APB1ENR &= ~(RCC_APB1ENR_RTCCKEN) )
#define __HAL_RCC_TIM7_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7CKEN) )
#define __HAL_RCC_TIM6_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6CKEN) )
#define __HAL_RCC_TIM4_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4CKEN) )
#define __HAL_RCC_TIM3_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3CKEN) )
#define __HAL_RCC_TIM2_CLK_DISABLE()            ( RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2CKEN) )

/** @brief  Enable or disable the APB2 peripheral clock.
  */

#define __HAL_RCC_TIM17_CLK_ENABLE()            ( RCC->APB2ENR |= (RCC_APB2ENR_TIM17CKEN) )
#define __HAL_RCC_TIM16_CLK_ENABLE()            ( RCC->APB2ENR |= (RCC_APB2ENR_TIM16CKEN) )
#define __HAL_RCC_TIM15_CLK_ENABLE()            ( RCC->APB2ENR |= (RCC_APB2ENR_TIM15CKEN) )
#define __HAL_RCC_UART1_CLK_ENABLE()            ( RCC->APB2ENR |= (RCC_APB2ENR_UART1CKEN) )
#define __HAL_RCC_TIM8_CLK_ENABLE()             ( RCC->APB2ENR |= (RCC_APB2ENR_TIM8CKEN) )
#define __HAL_RCC_TIM1_CLK_ENABLE()             ( RCC->APB2ENR |= (RCC_APB2ENR_TIM1CKEN) )
#define __HAL_RCC_EXTI_CLK_ENABLE()             ( RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN) )
#define __HAL_RCC_OPA_CLK_ENABLE()              ( RCC->APB2ENR |= (RCC_APB2ENR_OPACKEN) )
#define __HAL_RCC_CMP_CLK_ENABLE()              ( RCC->APB2ENR |= (RCC_APB2ENR_CMPCKEN) )
#define __HAL_RCC_VREFBUF_CLK_ENABLE()          ( RCC->APB2ENR |= (RCC_APB2ENR_VREFBUFCKEN) )
#define __HAL_RCC_SYSCFG_CLK_ENABLE()           ( RCC->APB2ENR |= (RCC_APB2ENR_SYSCFGCKEN) )

#define __HAL_RCC_TIM17_CLK_DISABLE()           ( RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17CKEN) )
#define __HAL_RCC_TIM16_CLK_DISABLE()           ( RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16CKEN) )
#define __HAL_RCC_TIM15_CLK_DISABLE()           ( RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15CKEN) )
#define __HAL_RCC_UART1_CLK_DISABLE()           ( RCC->APB2ENR &= ~(RCC_APB2ENR_UART1CKEN) )
#define __HAL_RCC_TIM8_CLK_DISABLE()            ( RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8CKEN) )
#define __HAL_RCC_TIM1_CLK_DISABLE()            ( RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1CKEN) )
#define __HAL_RCC_EXTI_CLK_DISABLE()            ( RCC->APB2ENR &= ~(RCC_APB2ENR_EXTICKEN) )
#define __HAL_RCC_OPA_CLK_DISABLE()             ( RCC->APB2ENR &= ~(RCC_APB2ENR_OPACKEN) )
#define __HAL_RCC_CMP_CLK_DISABLE()             ( RCC->APB2ENR &= ~(RCC_APB2ENR_CMPCKEN) )
#define __HAL_RCC_VREFBUF_CLK_DISABLE()         ( RCC->APB2ENR &= ~(RCC_APB2ENR_VREFBUFCKEN) )
#define __HAL_RCC_SYSCFG_CLK_DISABLE()          ( RCC->APB2ENR &= ~(RCC_APB2ENR_SYSCFGCKEN) )

/** @brief  Enable or disable the AHB peripheral clock.
  */

#define __HAL_RCC_EXMC_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_EXMCCKEN) )
#define __HAL_RCC_ROM_CLK_ENABLE()              ( RCC->AHBENR |= (RCC_AHBENR_ROMCKEN) )
#define __HAL_RCC_FAU_CLK_ENABLE()              ( RCC->AHBENR |= (RCC_AHBENR_FAUCKEN) )
#define __HAL_RCC_HRNG_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_HRNGCKEN) )
#define __HAL_RCC_AES_CLK_ENABLE()              ( RCC->AHBENR |= (RCC_AHBENR_AESCKEN) )
#define __HAL_RCC_DAC1_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_DAC1CKEN) )
#define __HAL_RCC_ADC12_CLK_ENABLE()            ( RCC->AHBENR |= (RCC_AHBENR_ADC12CKEN) )
#define __HAL_RCC_GPIOF_CLK_ENABLE()            do                                                      \
                                                {                                                       \
                                                    RCC->AHBENR |= (RCC_AHBENR_GPIOFCKEN);      \
                                                    RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN);     \
                                                }while (0)
#define __HAL_RCC_GPIOE_CLK_ENABLE()            do                                                      \
                                                {                                                       \
                                                    RCC->AHBENR |= (RCC_AHBENR_GPIOECKEN);      \
                                                    RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN);     \
                                                }while (0)
#define __HAL_RCC_GPIOD_CLK_ENABLE()            do                                                      \
                                                {                                                       \
                                                    RCC->AHBENR |= (RCC_AHBENR_GPIODCKEN);      \
                                                    RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN);     \
                                                }while (0)
#define __HAL_RCC_GPIOC_CLK_ENABLE()            do                                                      \
                                                {                                                       \
                                                    RCC->AHBENR |= (RCC_AHBENR_GPIOCCKEN);      \
                                                    RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN);     \
                                                }while (0)
#define __HAL_RCC_GPIOB_CLK_ENABLE()            do                                                      \
                                                {                                                       \
                                                    RCC->AHBENR |= (RCC_AHBENR_GPIOBCKEN);      \
                                                    RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN);     \
                                                }while (0)
#define __HAL_RCC_GPIOA_CLK_ENABLE()            do                                                      \
                                                {                                                       \
                                                    RCC->AHBENR |= (RCC_AHBENR_GPIOACKEN);      \
                                                    RCC->APB2ENR |= (RCC_APB2ENR_EXTICKEN);     \
                                                }while (0)
#define __HAL_RCC_SPI3_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_SPI3CKEN) )
#define __HAL_RCC_SPI2_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_SPI2CKEN) )
#define __HAL_RCC_SPI1_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_SPI1CKEN) )
#define __HAL_RCC_CRC_CLK_ENABLE()              ( RCC->AHBENR |= (RCC_AHBENR_CRCCKEN) )
#define __HAL_RCC_USB_CLK_ENABLE()              ( RCC->AHBENR |= (RCC_AHBENR_USBCCKEN) )
#define __HAL_RCC_EFC_CLK_ENABLE()              ( RCC->AHBENR |= (RCC_AHBENR_EFCCKEN) )
#define __HAL_RCC_SRAM_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_SRAMCKEN) )
#define __HAL_RCC_DMA2_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_DMA2CKEN) )
#define __HAL_RCC_DMA1_CLK_ENABLE()             ( RCC->AHBENR |= (RCC_AHBENR_DMA1CKEN) )

#define __HAL_RCC_MIM_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_MIMCKEN) )
#define __HAL_RCC_ROM_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_ROMCKEN) )
#define __HAL_RCC_FAU_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_FAUCKEN) )
#define __HAL_RCC_HRNG_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_HRNGCKEN) )
#define __HAL_RCC_AES_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_AESCKEN) )
#define __HAL_RCC_DAC1_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_DAC1CKEN) )
#define __HAL_RCC_ADC12_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_ADC12CKEN) )
#define __HAL_RCC_GPIOF_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_GPIOFCKEN) )
#define __HAL_RCC_GPIOE_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_GPIOECKEN) )
#define __HAL_RCC_GPIOD_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_GPIODCKEN) )
#define __HAL_RCC_GPIOC_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_GPIOCCKEN) )
#define __HAL_RCC_GPIOB_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_GPIOBCKEN) )
#define __HAL_RCC_GPIOA_CLK_DISABLE()           ( RCC->AHBENR &= ~(RCC_AHBENR_GPIOACKEN) )
#define __HAL_RCC_SPI3_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_SPI3CKEN) )
#define __HAL_RCC_SPI2_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_SPI2CKEN) )
#define __HAL_RCC_SPI1_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_SPI1CKEN) )
#define __HAL_RCC_CRC_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_CRCCKEN) )
#define __HAL_RCC_USB_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_USBCCKEN) )
#define __HAL_RCC_EFC_CLK_DISABLE()             ( RCC->AHBENR &= ~(RCC_AHBENR_EFCCKEN) )
#define __HAL_RCC_SRAM_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_SRAMCKEN) )
#define __HAL_RCC_DMA2_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_DMA2CKEN) )
#define __HAL_RCC_DMA1_CLK_DISABLE()            ( RCC->AHBENR &= ~(RCC_AHBENR_DMA1CKEN) )

/** @brief  Get the enable or disable status of the APB1 peripheral clock.
  */

#define __HAL_RCC_LPUART1_IS_CLK_ENABLE()       ( (RCC->APB1ENR & (RCC_APB1ENR_LPUART1CKEN)) != 0U )
#define __HAL_RCC_LPTIM1_IS_CLK_ENABLE()        ( (RCC->APB1ENR & (RCC_APB1ENR_LPTIM1CKEN)) != 0U )
#define __HAL_RCC_PMU_IS_CLK_ENABLE()           ( (RCC->APB1ENR & (RCC_APB1ENR_PMUCKEN)) != 0U )
#define __HAL_RCC_CAN2_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_CAN2CKEN)) != 0U )
#define __HAL_RCC_CAN1_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_CAN1CKEN)) != 0U )
#define __HAL_RCC_I2C2_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_I2C2CKEN)) != 0U )
#define __HAL_RCC_I2C1_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_I2C1CKEN)) != 0U )
#define __HAL_RCC_UART4_IS_CLK_ENABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_UART4CKEN)) != 0U )
#define __HAL_RCC_UART3_IS_CLK_ENABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_UART3CKEN)) != 0U )
#define __HAL_RCC_UART2_IS_CLK_ENABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_UART2CKEN)) != 0U )
#define __HAL_RCC_I2S2_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_I2S2CKEN)) != 0U )
#define __HAL_RCC_I2S1_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_I2S1CKEN) != 0U )
#define __HAL_RCC_WDT_IS_CLK_ENABLE()           ( (RCC->APB1ENR & (RCC_APB1ENR_WDTCKEN)) != 0U )
#define __HAL_RCC_RTC_IS_CLK_ENABLE()           ( (RCC->APB1ENR & (RCC_APB1ENR_RTCCKEN)) != 0U )
#define __HAL_RCC_TIM7_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_TIM7CKEN)) != 0U )
#define __HAL_RCC_TIM6_IS_CLK_ENABLE()          ( (RCC->APB1ENR &= (RCC_APB1ENR_TIM6CKEN)) != 0U )
#define __HAL_RCC_TIM4_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_TIM4CKEN)) != 0U )
#define __HAL_RCC_TIM3_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_TIM3CKEN)) != 0U )
#define __HAL_RCC_TIM2_IS_CLK_ENABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_TIM2CKEN)) != 0U )

#define __HAL_RCC_LPUART1_IS_CLK_DISABLE()      ( (RCC->APB1ENR & (RCC_APB1ENR_LPUART1CKEN)) == 0U )
#define __HAL_RCC_LPTIM1_IS_CLK_DISABLE()       ( (RCC->APB1ENR & (RCC_APB1ENR_LPTIM1CKEN)) == 0U )
#define __HAL_RCC_PMU_IS_CLK_DISABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_PMUCKEN)) == 0U )
#define __HAL_RCC_CAN2_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_CAN2CKEN)) == 0U )
#define __HAL_RCC_CAN1_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_CAN1CKEN)) == 0U )
#define __HAL_RCC_I2C2_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_I2C2CKEN)) == 0U )
#define __HAL_RCC_I2C1_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_I2C1CKEN)) == 0U )
#define __HAL_RCC_UART4_IS_CLK_DISABLE()        ( (RCC->APB1ENR & (RCC_APB1ENR_UART4CKEN)) == 0U )
#define __HAL_RCC_UART3_IS_CLK_DISABLE()        ( (RCC->APB1ENR & (RCC_APB1ENR_UART3CKEN)) == 0U )
#define __HAL_RCC_UART2_IS_CLK_DISABLE()        ( (RCC->APB1ENR & (RCC_APB1ENR_UART2CKEN)) == 0U )
#define __HAL_RCC_I2S2_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_I2S2CKEN)) == 0U )
#define __HAL_RCC_I2S1_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_I2S1CKEN) == 0U )
#define __HAL_RCC_WDT_IS_CLK_DISABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_WDTCKEN)) == 0U )
#define __HAL_RCC_RTC_IS_CLK_DISABLE()          ( (RCC->APB1ENR & (RCC_APB1ENR_RTCCKEN)) == 0U )
#define __HAL_RCC_TIM7_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_TIM7CKEN)) == 0U )
#define __HAL_RCC_TIM6_IS_CLK_DISABLE()         ( (RCC->APB1ENR &= (RCC_APB1ENR_TIM6CKEN)) == 0U )
#define __HAL_RCC_TIM4_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_TIM4CKEN)) == 0U )
#define __HAL_RCC_TIM3_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_TIM3CKEN)) == 0U )
#define __HAL_RCC_TIM2_IS_CLK_DISABLE()         ( (RCC->APB1ENR & (RCC_APB1ENR_TIM2CKEN)) == 0U )

/** @brief  Get the enable or disable status of the APB2 peripheral clock.
  */

#define __HAL_RCC_TIM17_IS_CLK_ENABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_TIM17CKEN)) != 0U )
#define __HAL_RCC_TIM16_IS_CLK_ENABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_TIM16CKEN)) != 0U )
#define __HAL_RCC_TIM15_IS_CLK_ENABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_TIM15CKEN)) != 0U )
#define __HAL_RCC_UART1_IS_CLK_ENABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_UART1CKEN)) != 0U )
#define __HAL_RCC_TIM8_IS_CLK_ENABLE()          ( (RCC->APB2ENR & (RCC_APB2ENR_TIM8CKEN)) != 0U )
#define __HAL_RCC_TIM1_IS_CLK_ENABLE()          ( (RCC->APB2ENR & (RCC_APB2ENR_TIM1CKEN)) != 0U )
#define __HAL_RCC_EXTI_IS_CLK_ENABLE()          ( (RCC->APB2ENR & (RCC_APB2ENR_EXTICKEN)) != 0U )
#define __HAL_RCC_OPA_IS_CLK_ENABLE()           ( (RCC->APB2ENR & (RCC_APB2ENR_OPACKEN)) != 0U )
#define __HAL_RCC_CMP_IS_CLK_ENABLE()           ( (RCC->APB2ENR &= (RCC_APB2ENR_CMPCKEN)) != 0U )
#define __HAL_RCC_VREFBUF_IS_CLK_ENABLE()       ( (RCC->APB2ENR & (RCC_APB2ENR_VREFBUFCKEN)) != 0U )
#define __HAL_RCC_SYSCFG_IS_CLK_ENABLE()        ( (RCC->APB2ENR & (RCC_APB2ENR_SYSCFGCKEN)) != 0U )

#define __HAL_RCC_TIM17_IS_CLK_DISABLE()        ( (RCC->APB2ENR & (RCC_APB2ENR_TIM17CKEN)) == 0U )
#define __HAL_RCC_TIM16_IS_CLK_DISABLE()        ( (RCC->APB2ENR & (RCC_APB2ENR_TIM16CKEN)) == 0U )
#define __HAL_RCC_TIM15_IS_CLK_DISABLE()        ( (RCC->APB2ENR & (RCC_APB2ENR_TIM15CKEN)) == 0U )
#define __HAL_RCC_UART1_IS_CLK_DISABLE()        ( (RCC->APB2ENR & (RCC_APB2ENR_UART1CKEN)) == 0U )
#define __HAL_RCC_TIM8_IS_CLK_DISABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_TIM8CKEN)) == 0U )
#define __HAL_RCC_TIM1_IS_CLK_DISABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_TIM1CKEN)) == 0U )
#define __HAL_RCC_EXTI_IS_CLK_DISABLE()         ( (RCC->APB2ENR & (RCC_APB2ENR_EXTICKEN)) == 0U )
#define __HAL_RCC_OPA_IS_CLK_DISABLE()          ( (RCC->APB2ENR & (RCC_APB2ENR_OPACKEN)) == 0U )
#define __HAL_RCC_CMP_IS_CLK_DISABLE()          ( (RCC->APB2ENR &= (RCC_APB2ENR_CMPCKEN)) == 0U )
#define __HAL_RCC_VREFBUF_IS_CLK_DISABLE()      ( (RCC->APB2ENR & (RCC_APB2ENR_VREFBUFCKEN)) == 0U )
#define __HAL_RCC_SYSCFG_IS_CLK_DISABLE()       ( (RCC->APB2ENR & (RCC_APB2ENR_SYSCFGCKEN)) == 0U )

/** @brief  Get the enable or disable status of the AHB peripheral clock.
  */

#define __HAL_RCC_MIM_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_MIMCKEN)) != 0U )
#define __HAL_RCC_ROM_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_ROMCKEN)) != 0U )
#define __HAL_RCC_FAU_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_FAUCKEN)) != 0U )
#define __HAL_RCC_HRNG_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_HRNGCKEN)) != 0U )
#define __HAL_RCC_AES_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_AESCKEN)) != 0U )
#define __HAL_RCC_DAC1_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_DAC1CKEN)) != 0U )
#define __HAL_RCC_ADC12_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_ADC12CKEN)) != 0U )
#define __HAL_RCC_GPIOF_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_GPIOFCKEN)) != 0U )
#define __HAL_RCC_GPIOE_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_GPIOECKEN)) != 0U )
#define __HAL_RCC_GPIOD_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_GPIODCKEN)) != 0U )
#define __HAL_RCC_GPIOC_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_GPIOCCKEN)) != 0U )
#define __HAL_RCC_GPIOB_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_GPIOBCKEN)) != 0U )
#define __HAL_RCC_GPIOA_IS_CLK_ENABLE()         ( (RCC->AHBENR & (RCC_AHBENR_GPIOACKEN)) != 0U )
#define __HAL_RCC_SPI3_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_SPI3CKEN)) != 0U )
#define __HAL_RCC_SPI2_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_SPI2CKEN)) != 0U )
#define __HAL_RCC_SPI1_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_SPI1CKEN)) != 0U )
#define __HAL_RCC_CRC_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_CRCCKEN)) != 0U )
#define __HAL_RCC_USB_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_USBCCKEN)) != 0U )
#define __HAL_RCC_EFC_IS_CLK_ENABLE()           ( (RCC->AHBENR & (RCC_AHBENR_EFCCKEN)) != 0U )
#define __HAL_RCC_SRAM_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_SRAMCKEN)) != 0U )
#define __HAL_RCC_DMA2_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_DMA2CKEN)) != 0U )
#define __HAL_RCC_DMA1_IS_CLK_ENABLE()          ( (RCC->AHBENR & (RCC_AHBENR_DMA1CKEN)) != 0U )

#define __HAL_RCC_MIM_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_MIMCKEN)) == 0U )
#define __HAL_RCC_ROM_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_ROMCKEN)) == 0U )
#define __HAL_RCC_FAU_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_FAUCKEN)) == 0U )
#define __HAL_RCC_HRNG_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_HRNGCKEN)) == 0U )
#define __HAL_RCC_AES_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_AESCKEN)) == 0U )
#define __HAL_RCC_DAC1_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_DAC1CKEN)) == 0U )
#define __HAL_RCC_ADC12_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_ADC12CKEN)) == 0U )
#define __HAL_RCC_GPIOF_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_GPIOFCKEN)) == 0U )
#define __HAL_RCC_GPIOE_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_GPIOECKEN)) == 0U )
#define __HAL_RCC_GPIOD_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_GPIODCKEN)) == 0U )
#define __HAL_RCC_GPIOC_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_GPIOCCKEN)) == 0U )
#define __HAL_RCC_GPIOB_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_GPIOBCKEN)) == 0U )
#define __HAL_RCC_GPIOA_IS_CLK_DISABLE()        ( (RCC->AHBENR & (RCC_AHBENR_GPIOACKEN)) == 0U )
#define __HAL_RCC_SPI3_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_SPI3CKEN)) == 0U )
#define __HAL_RCC_SPI2_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_SPI2CKEN)) == 0U )
#define __HAL_RCC_SPI1_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_SPI1CKEN)) == 0U )
#define __HAL_RCC_CRC_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_CRCCKEN)) == 0U )
#define __HAL_RCC_USB_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_USBCCKEN)) == 0U )
#define __HAL_RCC_EFC_IS_CLK_DISABLE()          ( (RCC->AHBENR & (RCC_AHBENR_EFCCKEN)) == 0U )
#define __HAL_RCC_SRAM_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_SRAMCKEN)) == 0U )
#define __HAL_RCC_DMA2_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_DMA2CKEN)) == 0U )
#define __HAL_RCC_DMA1_IS_CLK_DISABLE()         ( (RCC->AHBENR & (RCC_AHBENR_DMA1CKEN)) == 0U )

/******************************************************************************/

/** @defgroup  GPIO Private Macros
  * @{
  */
#define IS_RCC_PLL_PLL(PLL)                     (((PLL) == ENABLE) || \
                                                 ((PLL) == DISABLE))

#define IS_RCC_PLL_PLLSOURCE(PLLSOURCE)         (((PLLSOURCE) == RCC_PLLSOURCE_RC64M_DIV16) || \
                                                 ((PLLSOURCE) == RCC_PLLSOURCE_XTH))

#define IS_RCC_PLL_PLLM(PLLM)                   ((PLLM) <= 3U)
#define IS_RCC_PLL_PLLN(PLLN)                   ((PLLN) <= 7U)
#define IS_RCC_PLL_PLLF(PLLF)                   ((PLLF) <= 31U)

#define IS_RCC_OSC_OSCTYPE(OSCTYPE)             ((((OSCTYPE) & RCC_OSCTYPE_MASK) != 0U) && (((OSCTYPE) & ~RCC_OSCTYPE_MASK) == 0U))

#define IS_RCC_OSC_RC64M(RC64M)                 (((RC64M) == ENABLE) || \
                                                 ((RC64M) == DISABLE))

#define IS_RCC_OSC_RC64MD_DIV16(DIV16)          (((DIV16) == ENABLE) || \
                                                 ((DIV16) == DISABLE))

#define IS_RCC_OSC_RC32K(RC32K)                 (((RC32K) == ENABLE) || \
                                                 ((RC32K) == DISABLE))

#define IS_RCC_OSC_XTH(XTH)                     (((XTH) == ENABLE) || \
                                                 ((XTH) == DISABLE))

#define IS_RCC_OSC_XTH_BYPASS(BYPASS)           (((BYPASS) == ENABLE) || \
                                                 ((BYPASS) == DISABLE))

#define IS_RCC_OSC_XTL(XTL)                     (((XTL) == ENABLE) || \
                                                 ((XTL) == DISABLE))

#define IS_RCC_OSC_XTL_BYPASS(BYPASS)           (((BYPASS) == ENABLE) || \
                                                 ((BYPASS) == DISABLE))

#define IS_RCC_OSC_XTL_DRIVE(DRIVE)             (((DRIVE) == RCC_XTL_DRIVE_LOW) || \
                                                 ((DRIVE) == RCC_XTL_DRIVE_HIGH) || \
                                                 ((DRIVE) == RCC_XTL_DRIVE_LOW_WITH_LOWPOWER) || \
                                                 ((DRIVE) == RCC_XTL_DRIVE_HIGH_WITH_HIGH_POWER))

#define IS_RCC_OSC_SYSCLK_SOURCE(SOURCE)        (((SOURCE) == RCC_SYSCLKSOURCE_RC64M) || \
                                                 ((SOURCE) == RCC_SYSCLKSOURCE_RC32K) || \
                                                 ((SOURCE) == RCC_SYSCLKSOURCE_XTH) || \
                                                 ((SOURCE) == RCC_SYSCLKSOURCE_XTL) || \
                                                 ((SOURCE) == RCC_SYSCLKSOURCE_PLLCLK))

#define IS_RCC_OSC_SYSCLK_DIV0(DIV)             (((DIV) == RCC_SYSDIV0_DIV_1) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_2) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_3) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_4) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_5) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_6) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_7) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_8) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_9) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_10) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_11) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_12) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_13) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_14) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_15) || \
                                                 ((DIV) == RCC_SYSDIV0_DIV_16))

#define IS_RCC_OSC_SYSCLK_DIV1(DIV)             (((DIV) == RCC_SYSDIV1_DIV_1) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_2) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_3) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_4) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_5) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_6) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_7) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_8) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_9) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_10) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_11) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_12) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_13) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_14) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_15) || \
                                                 ((DIV) == RCC_SYSDIV1_DIV_16))

#define IS_RCC_OSC_PCLK1_DIV(DIV)               (((DIV) == RCC_PCLK1_DIV_1) || \
                                                 ((DIV) == RCC_PCLK1_DIV_2) || \
                                                 ((DIV) == RCC_PCLK1_DIV_4) || \
                                                 ((DIV) == RCC_PCLK1_DIV_8) || \
                                                 ((DIV) == RCC_PCLK1_DIV_16))

#define IS_RCC_OSC_PCLK2_DIV(DIV)               (((DIV) == RCC_PCLK2_DIV_1) || \
                                                 ((DIV) == RCC_PCLK2_DIV_2) || \
                                                 ((DIV) == RCC_PCLK2_DIV_4) || \
                                                 ((DIV) == RCC_PCLK2_DIV_8) || \
                                                 ((DIV) == RCC_PCLK2_DIV_16))

#define IS_RCC_MCO_OUTPUT(OUTPUT)               (((OUTPUT) == RCC_MCO_NONE) || \
                                                 ((OUTPUT) == RCC_MCO_HCLK) || \
                                                 ((OUTPUT) == RCC_MCO_RC64M) || \
                                                 ((OUTPUT) == RCC_MCO_RC32K) || \
                                                 ((OUTPUT) == RCC_MCO_XTH) || \
                                                 ((OUTPUT) == RCC_MCO_XTL) || \
                                                 ((OUTPUT) == RCC_MCO_PLLCLK) || \
                                                 ((OUTPUT) == RCC_MCO_PCLK1) || \
                                                 ((OUTPUT) == RCC_MCO_PCLK2) || \
                                                 ((OUTPUT) == RCC_MCO_SYSCLK) || \
                                                 ((OUTPUT) == RCC_MCO_TIMCLK1) || \
                                                 ((OUTPUT) == RCC_MCO_TIMCLK2) || \
                                                 ((OUTPUT) == RCC_MCO_LPUARTCLK) || \
                                                 ((OUTPUT) == RCC_MCO_SYSTICK) || \
                                                 ((OUTPUT) == RCC_MCO_USBPHYPLL48M) || \
                                                 ((OUTPUT) == RCC_MCO_RTC_PCLK))

#define IS_RCC_MCO1(MCO1)                       (((MCO1) == ENABLE) || \
                                                 ((MCO1) == DISABLE))

#define IS_RCC_MCO1_DIV(DIV)                    ((DIV) <= 65525U)

#define IS_RCC_MCO1_REVPOL(REVPOL)              (((REVPOL) == ENABLE) || \
                                                 ((REVPOL) == DISABLE))

#define IS_RCC_MCO2(BUZZER2)                    (((BUZZER2) == ENABLE) || \
                                                 ((BUZZER2) == DISABLE))

#define IS_RCC_MCO2_DIV(DIV)                    ((DIV) <= 63U)

#define IS_RCC_MCO2_REVPOL(REVPOL)              (((REVPOL) == ENABLE) || \
                                                 ((REVPOL) == DISABLE))

#define IS_RCC_LPTIM1_CLKSOURCE(SOURCE)         (((SOURCE) == RCC_LPTIM1CLKSOURCE_PCLK) || \
                                                 ((SOURCE) == RCC_LPTIM1CLKSOURCE_RC32K) || \
                                                 ((SOURCE) == RCC_LPTIM1CLKSOURCE_RC64M) || \
                                                 ((SOURCE) == RCC_LPTIM1CLKSOURCE_XTL))

#define IS_RCC_FLTCLK_CLKSOURCE(SOURCE)         (((SOURCE) == RCC_FLTCLKSOURCE_PCLK_DIV32) || \
                                                 ((SOURCE) == RCC_FLTCLKSOURCE_RC32K))

#define IS_RCC_LPUART1_CLKSOURCE(SOURCE)        (((SOURCE) == RCC_LPUART1CLKSOURCE_RC32K) || \
                                                 ((SOURCE) == RCC_LPUART1CLKSOURCE_XTL) || \
                                                 ((SOURCE) == RCC_LPUART1CLKSOURCE_PCLK_DIV4) || \
                                                 ((SOURCE) == RCC_LPUART1CLKSOURCE_PCLK_DIV8) || \
                                                 ((SOURCE) == RCC_LPUART1CLKSOURCE_PCLK_DIV16) || \
                                                 ((SOURCE) == RCC_LPUART1CLKSOURCE_PCLK_DIV32))
                                                 
                                           
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct);
HAL_StatusTypeDef HAL_RCC_SwitchSYSCLK(uint32_t SYSCLKSource);
HAL_StatusTypeDef HAL_RCC_LPTIM1ClockConfig(uint32_t  source);
HAL_StatusTypeDef HAL_RCC_FLTClockConfig(uint32_t  source);
HAL_StatusTypeDef HAL_RCC_LPUART1ClockConfig(uint32_t  source);
uint32_t HAL_RCC_MCOConfig(RCC_MCOInitTypeDef *MCO_Init);
uint32_t HAL_RCC_GetRC64MVal(void);
uint32_t HAL_RCC_GetRC32KVal(void);
uint32_t HAL_RCC_GetSYSCLKFreq(void);
uint32_t HAL_RCC_GetSysCoreClockFreq(void);
uint32_t HAL_RCC_GetFCLKFreq(void);
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLK1Freq(void);
uint32_t HAL_RCC_GetPCLK2Freq(void);
uint32_t HAL_RCC_GetLPTIM1CLKFreq(void);
uint32_t HAL_RCC_GetFLTCLKFreq(void);
uint32_t HAL_RCC_GetLPUART1CLKFreq(void);


#ifdef __cplusplus
}
#endif

#endif
