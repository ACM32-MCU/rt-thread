
/******************************************************************************
*@file  : system-acm32g103.c
*@brief : CMSIS Cortex-M33 Device Peripheral Access Layer System Source File
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#include "hal.h"

typedef enum 
{
    SYSCLK_120M_SRC_RC64M = 0,
    SYSCLK_80M_SRC_RC64M,
    SYSCLK_64M_SRC_RC64M,
    SYSCLK_32M_SRC_RC64M,
    SYSCLK_16M_SRC_RC64M,
    SYSCLK_8M_SRC_RC64M,

    SYSCLK_120M_SRC_XTH_12M,
    SYSCLK_80M_SRC_XTH_12M,
    SYSCLK_60M_SRC_XTH_12M,
    SYSCLK_40M_SRC_XTH_12M,
    SYSCLK_24M_SRC_XTH_12M,
    SYSCLK_12M_SRC_XTH_12M

}SYSCLK_SelectTypeDef;

/****** system core clock select, uesr config ***********/
#define SYSCLK_SELECT       SYSCLK_120M_SRC_RC64M 

/******************************************************************************
*@brief : PCLK1_DIV_SELECT: pclk1 div select, uesr config
*           @arg RCC_PCLK1_DIV_1
*           @arg RCC_PCLK1_DIV_2
*           @arg RCC_PCLK1_DIV_4
*           @arg RCC_PCLK1_DIV_8
*           @arg RCC_PCLK1_DIV_16
******************************************************************************/
#define PCLK1_DIV_SELECT    RCC_PCLK1_DIV_2

/******************************************************************************
*@brief : PCLK2_DIV_SELECT: pclk2 div select, uesr config
*           @arg RCC_PCLK2_DIV_1
*           @arg RCC_PCLK2_DIV_2
*           @arg RCC_PCLK2_DIV_4
*           @arg RCC_PCLK2_DIV_8
*           @arg RCC_PCLK2_DIV_16
******************************************************************************/
#define PCLK2_DIV_SELECT    RCC_PCLK2_DIV_2

/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x0U /*!< Vector Table base offset field. This value must be a multiple of 0x200. */

#ifdef DATA_IN_ExtSRAM
  static void SystemInit_ExtMemCtl(void); 
#endif

/******************************************************************************
*@note  : g_SystemCoreClock variable is updated in three ways:
*           1) by calling CMSIS function SystemCoreClockUpdate()
*           2) by calling HAL API function HAL_RCC_GetSysCoreClockFreq()
*           3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency 
*               If you use this function to configure the system clock; then there
*               is no need to call the 2 first functions listed above, since g_SystemCoreClock
*               variable is updated automatically.
******************************************************************************/
uint32_t g_SystemCoreClock = 64000000;


/******************************************************************************
*@brief : configure FPU and vector table address
*         - This function is called at startup just after reset and before branch to main program. 
*         - This call is made inside the "startup_acm32g103.s" file
*@param : none
*@return: none
******************************************************************************/
void SystemInit(void)
{
	#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
		/* set CP10 and CP11 Full Access */
		SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));
	#endif

	RCC->RC64MCR &= ~RCC_RC64MCR_RC64MDIV;
	RCC->RC64MCR |= RCC_RC64MCR_RC64MEN;
	
	while (!(RCC->RC64MCR & RCC_RC64MCR_RC64MRDY))
	{
	};
	
	RCC->CCR1 &= ~RCC_CCR1_SYSCLKSEL;	/* sysclk = RC64M  */
	 
	RCC->CCR2 &= ~(RCC_CCR2_SYSDIV0 | RCC_CCR2_SYSDIV1 | RCC_CCR2_PCLK1DIV | RCC_CCR2_PCLK2DIV);
	
	while(!(RCC->CCR2 & RCC_CCR2_DIVDONE))
    {
    };
	
	#ifdef DATA_IN_ExtSRAM
		SystemInit_ExtMemCtl(); 
	#endif /* DATA_IN_ExtSRAM || DATA_IN_ExtSDRAM */

    /* Configure the Vector Table location add offset address ------------------*/
	#ifdef VECT_TAB_SRAM
		SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET;    /* Vector Table Relocation in Internal SRAM */
	#else
		SCB->VTOR = EFLASH_BASE_ADDR | VECT_TAB_OFFSET;  /* Vector Table Relocation in Internal FLASH */
	#endif
}

/******************************************************************************
*@brief : Update g_SystemCoreClock variable according to Clock Register Values.
*         The SystemCoreClock variable contains the core clock (HCLK), it can
*         be used by the user application to setup the SysTick timer or configure
*         other parameters.
*           
*@note  : Each time the core clock (HCLK) changes, this function must be called
*         to update SystemCoreClock variable value. Otherwise, any configuration
*         based on this variable will be incorrect.  
*@param : none
*@return: none
******************************************************************************/
void SystemCoreClockUpdate(void)
{
    g_SystemCoreClock = HAL_RCC_GetSysCoreClockFreq();   
}


/******************************************************************************
*@brief : fast config system core clock. 
*@param : sysclkSel: system core clk select, see SYSCLK_SelectTypeDef  enum
*@param : pclk1Div: pclk1 div select
*           @arg RCC_PCLK1_DIV_1
*           @arg RCC_PCLK1_DIV_2
*           @arg RCC_PCLK1_DIV_4
*           @arg RCC_PCLK1_DIV_8
*           @arg RCC_PCLK1_DIV_16
*@param : pclk2Div: pclk2 div select
*           @arg RCC_PCLK2_DIV_1
*           @arg RCC_PCLK2_DIV_2
*           @arg RCC_PCLK2_DIV_4
*           @arg RCC_PCLK2_DIV_8
*           @arg RCC_PCLK2_DIV_16
*@return: none
******************************************************************************/
void SystemClock_FastConfig(SYSCLK_SelectTypeDef sysclkSel, uint32_t pclk1Div, uint32_t pclk2Div)
{
    RCC_OscInitTypeDef      RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef      RCC_ClkInitStruct = {0};
    
    switch(sysclkSel)
    {
        case SYSCLK_120M_SRC_RC64M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_RC64M | RCC_OSCTYPE_PLL;
        
            RCC_OscInitStruct.RC64M = ENABLE;
            RCC_OscInitStruct.RC64MDiv16 = ENABLE;      
        
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_RC64M_DIV16;
        
            // Fpll=4*(F15+15)/(N0+1)/(2^M0)
            RCC_OscInitStruct.PLL.PLLF = 15U;        
            RCC_OscInitStruct.PLL.PLLN = 0U;
            RCC_OscInitStruct.PLL.PLLM = 0U; 

            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;

            break;
        
        case SYSCLK_80M_SRC_RC64M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_RC64M | RCC_OSCTYPE_PLL;
        
            RCC_OscInitStruct.RC64M = ENABLE;
            RCC_OscInitStruct.RC64MDiv16 = ENABLE;      
        
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_RC64M_DIV16;
        
            // Fpll=4*(F5+15)/(N0+1)/(2^M0)
            RCC_OscInitStruct.PLL.PLLF = 5U;        
            RCC_OscInitStruct.PLL.PLLN = 0U;
            RCC_OscInitStruct.PLL.PLLM = 0U; 

            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            
            break;  
            
        case SYSCLK_64M_SRC_RC64M:
        case SYSCLK_32M_SRC_RC64M:            
        case SYSCLK_16M_SRC_RC64M:        
        case SYSCLK_8M_SRC_RC64M:
            if(sysclkSel == SYSCLK_64M_SRC_RC64M)
            {
                RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            }
            else if(sysclkSel == SYSCLK_32M_SRC_RC64M)
            {
                RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_2;
            }
            else if(sysclkSel == SYSCLK_16M_SRC_RC64M)
            {
                RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_3;
            }
            else if(sysclkSel == SYSCLK_8M_SRC_RC64M)
            {
                RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_4;
            }
            else
            {
                RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            }
            
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_RC64M;
        
            RCC_OscInitStruct.RC64M = ENABLE;
            RCC_OscInitStruct.RC64MDiv16 = DISABLE;      

            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_RC64M;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;

            break;
            
        case SYSCLK_120M_SRC_XTH_12M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_XTH | RCC_OSCTYPE_PLL;
            RCC_OscInitStruct.XTH = ENABLE;
            RCC_OscInitStruct.XTHBypass = DISABLE;
            
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_XTH;
        
            // Fpll=12*(F15+15)/(N2+1)/(2^M0)
            RCC_OscInitStruct.PLL.PLLF = 15U;        
            RCC_OscInitStruct.PLL.PLLN = 2U;
            RCC_OscInitStruct.PLL.PLLM = 0U; 
 
            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            break; 

        case SYSCLK_80M_SRC_XTH_12M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_XTH | RCC_OSCTYPE_PLL;
            RCC_OscInitStruct.XTH = ENABLE;
            RCC_OscInitStruct.XTHBypass = DISABLE;
            
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_XTH;
        
            // Fpll=12*(F5+15)/(N2+1)/(2^M0)
            RCC_OscInitStruct.PLL.PLLF = 5U;        
            RCC_OscInitStruct.PLL.PLLN = 2U;
            RCC_OscInitStruct.PLL.PLLM = 0U; 
 
            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            break; 
        
        case SYSCLK_60M_SRC_XTH_12M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_XTH | RCC_OSCTYPE_PLL;
            RCC_OscInitStruct.XTH = ENABLE;
            RCC_OscInitStruct.XTHBypass = DISABLE;
            
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_XTH;
        
            // Fpll=12*(F15+15)/(N2+1)/(2^M1)
            RCC_OscInitStruct.PLL.PLLF = 15U;        
            RCC_OscInitStruct.PLL.PLLN = 2U;
            RCC_OscInitStruct.PLL.PLLM = 1U; 
 
            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            break;         
        
        case SYSCLK_40M_SRC_XTH_12M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_XTH | RCC_OSCTYPE_PLL;
            RCC_OscInitStruct.XTH = ENABLE;
            RCC_OscInitStruct.XTHBypass = DISABLE;
            
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_XTH;
        
            // Fpll=12*(F5+15)/(N2+1)/(2^M1)
            RCC_OscInitStruct.PLL.PLLF = 5U;        
            RCC_OscInitStruct.PLL.PLLN = 2U;
            RCC_OscInitStruct.PLL.PLLM = 1U; 
 
            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            break;

        case SYSCLK_24M_SRC_XTH_12M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_XTH | RCC_OSCTYPE_PLL;
            RCC_OscInitStruct.XTH = ENABLE;
            RCC_OscInitStruct.XTHBypass = DISABLE;
            
            RCC_OscInitStruct.PLL.PLL = ENABLE;
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_XTH;
        
            // Fpll=12*(F9+15)/(N2+1)/(2^M2)
            RCC_OscInitStruct.PLL.PLLF = 9U;        
            RCC_OscInitStruct.PLL.PLLN = 2U;
            RCC_OscInitStruct.PLL.PLLM = 2U; 
 
            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            break;

        case SYSCLK_12M_SRC_XTH_12M:
            RCC_OscInitStruct.OscType = RCC_OSCTYPE_XTH | RCC_OSCTYPE_PLL;
            RCC_OscInitStruct.XTH = ENABLE;
            RCC_OscInitStruct.XTHBypass = DISABLE;

            RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_XTH;
            RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
            RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
            RCC_ClkInitStruct.PCLK1Div = pclk1Div;
            RCC_ClkInitStruct.PCLK2Div = pclk2Div;
            break;
            
        default:            
        
            return;        
    }
    
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        while (1);
    }    

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct) != HAL_OK)
    {
        while (1);
    }       

}



/******************************************************************************
*@brief : flexible config system clock
*@param : none
*@return: none
******************************************************************************/
void SystemClock_FlexibleConfig(void)
{
    RCC_OscInitTypeDef      RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef      RCC_ClkInitStruct = {0};
    
    RCC_OscInitStruct.OscType = RCC_OSCTYPE_RC64M | RCC_OSCTYPE_PLL;
    RCC_OscInitStruct.RC64M = ENABLE;
    RCC_OscInitStruct.RC64MDiv16 = ENABLE;  
    
    RCC_OscInitStruct.PLL.PLL = ENABLE;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_RC64M_DIV16;
    RCC_OscInitStruct.PLL.PLLM = 0U;
    RCC_OscInitStruct.PLL.PLLN = 0U;
    RCC_OscInitStruct.PLL.PLLF = 15U;
    
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        while (1);
    }
    
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDiv0 = RCC_SYSDIV0_DIV_1;
    RCC_ClkInitStruct.SYSCLKDiv1 = RCC_SYSDIV1_DIV_1;
    RCC_ClkInitStruct.PCLK1Div = RCC_PCLK1_DIV_2;
    RCC_ClkInitStruct.PCLK2Div = RCC_PCLK2_DIV_2;
    
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct) != HAL_OK)
    {
        while (1);
    }
}

/******************************************************************************
*@brief : config system clock, user call it in main()
*@param : none
*@return: none
******************************************************************************/
void SystemClock_Config(void)
{
    SystemClock_FastConfig(SYSCLK_SELECT,PCLK1_DIV_SELECT,PCLK2_DIV_SELECT);
    //SystemClock_FlexibleConfig();
}


  
#ifdef DATA_IN_ExtSRAM

static void SystemInit_ExtMemCtl(void)
{
}

#endif /* (DATA_IN_ExtSRAM) || defined (DATA_IN_ExtSDRAM) */

