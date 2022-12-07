/******************************************************************************
* @file  :  hal_uart.c
* @brief :  UART HAL module driver.
*          This file provides firmware functions to manage the following
*          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (UART).
* @ver   :  V1.0.0
* @date  :  2020
******************************************************************************/
#include "hal.h" 


#ifdef HAL_UART_MODULE_ENABLED

UART_TypeDef *g_DebugUart=NULL;   //printf UARTx

/* Private function prototypes -----------------------------------------------*/
static void UART_Config_BaudRate(UART_HandleTypeDef *huart);
static HAL_StatusTypeDef HAL_UART_Wait_Tx_Done(UART_HandleTypeDef *huart);

__weak void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
__weak void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);

/******************************************************************************
*@brief : Handle UART interrupt request
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_IRQHandler(UART_HandleTypeDef *huart)
{
    __IO uint32_t isrflags, ieits, errorflags;  
    
    assert_param(IS_UART_ALL_INSTANCE(huart->Instance));

    isrflags = READ_REG(huart->Instance->ISR);
    ieits    = READ_REG(huart->Instance->IE);
    errorflags =0x00U;
    errorflags =(isrflags & (uint32_t)(UART_ISR_PEI|UART_ISR_OEI|UART_ISR_FEI|UART_ISR_BEI));
	
    /* Enable TXI */
    if (huart->Instance->IE & UART_IE_TXI)
    {
        if (huart->Instance->ISR & UART_ISR_TXI)
        {
            /* Clear TXI Status */
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_TXI);

            for(;;)
            {
                if(huart->TxCount == huart->TxSize) 
                {                               
                    huart->TxBusy = false;
             
                    /* Disable TX interrupt */
                    CLEAR_BIT(huart->Instance->IE, UART_IE_TXI); 

                    if(HAL_UART_TxCpltCallback)
                        HAL_UART_TxCpltCallback(huart);
                    break;
                }

                if (READ_BIT(huart->Instance->FR, UART_FR_TXFF))
                {
                    break;
                }
                
				if (huart->Init.WordLength == UART_WORDLENGTH_9B)
                {
                    uint16_t *pbuf_16;
                    pbuf_16 = (uint16_t *)huart->TxData;
                    huart->Instance->DR = (uint16_t)(*pbuf_16 & 0x01FFU);
                    huart->TxData += 2U;
                    huart->TxCount++;
                }
                else
                {
                    huart->Instance->DR = huart->TxData[huart->TxCount++];
                }
            }
        }
    }

    /* RXI */
    if (((huart->Instance->IE & UART_IE_RXI) || (huart->Instance->IE & UART_IE_IDLEI)) && (errorflags == 0)) 
	{ 
		if (huart->Instance->ISR & UART_ISR_RXI) 
		{
			/* Clear RXI Status */
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_RXI);
									
			while(huart->RxCount < huart->RxSize )  
			{
				if(!READ_BIT(huart->Instance->FR, UART_FR_RXFE))
				{
					 /* Store Data in buffer */
                     if (huart->Init.WordLength == UART_WORDLENGTH_9B)
                     {
                         uint16_t *pbuf_16;
                         pbuf_16 = (uint16_t *)huart->RxData;
                         *pbuf_16 = (uint16_t)(huart->Instance->DR & 0x1FF);
                         huart->RxData += 2U;
                         huart->RxCount++;
                     }
                     else
                     {
                        huart->RxData[huart->RxCount++] = (uint8_t)huart->Instance->DR;	
                     }                         
				}  
				else
			    {
					break;
			    }  
			}
            
			if(huart->RxCount ==huart->RxSize )
			{
				huart->RxBusy = false;
			
				/* Disable RX and RTI interrupt */
				CLEAR_BIT(huart->Instance->IE, (UART_IE_RXI|UART_IE_IDLEI));
				
				/* clear error interrupt */
				CLEAR_BIT(huart->Instance->IE, UART_IE_OEI|UART_IE_BEI|UART_IE_PEI|UART_IE_FEI);
				
                if(HAL_UART_RxCpltCallback)
                    HAL_UART_RxCpltCallback(huart);
		   }
		}
		else if(huart->Instance->ISR & UART_ISR_IDLEI)
		{
			/*clear IDLE Status */
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_IDLEI);

			while(!READ_BIT(huart->Instance->FR, UART_FR_RXFE))
			{
                if (huart->Init.WordLength == UART_WORDLENGTH_9B)
                {
                     uint16_t *pbuf_16;
                     pbuf_16 = (uint16_t *)huart->RxData;
                     *pbuf_16 = (uint16_t)(huart->Instance->DR & 0x1FF);
                     huart->RxData += 2U;
                     huart->RxCount++;
                }
                else
                {                    
                    huart->RxData[huart->RxCount++] = (uint8_t)huart->Instance->DR;
                }
			}

			huart->RxBusy = false;

			/* Disable RX and RTI interrupt */
			CLEAR_BIT(huart->Instance->IE, (UART_IE_RXI|UART_IE_IDLEI));

			/* clear error interrupt */
			CLEAR_BIT(huart->Instance->IE, UART_IE_OEI|UART_IE_BEI|UART_IE_PEI|UART_IE_FEI);
			
            if(HAL_UART_RxCpltCallback)
                HAL_UART_RxCpltCallback(huart);
		}		
	}
	/* if some errors occurred */
	if(errorflags != 0 &&(ieits & (UART_IE_OEI|UART_IE_BEI|UART_IE_PEI|UART_IE_FEI)))
	{
		/* UART parity error interrupt occurred */
	    if (((isrflags & UART_ISR_PEI) != 0) && ((ieits & UART_IE_PEI) != 0))
	    {
	    	/* Clear parity error status */
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_PEI);//huart->Instance->ISR = UART_ISR_PEI;
	      	huart->ErrorCode |= HAL_UART_ERROR_PE;
	    }

	    /* UART break error interrupt occurred */
	    if (((isrflags & UART_ISR_BEI) != 0) && ((ieits & UART_IE_BEI) != 0))
	    {
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_BEI);//huart->Instance->ISR = UART_ISR_BEI;
	      	huart->ErrorCode |= HAL_UART_ERROR_NE;
	    }

	    /* UART frame error interrupt occurred */
	    if (((isrflags & UART_ISR_FEI) != 0) && ((ieits & UART_IE_FEI) != 0))
	    {
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_FEI);//huart->Instance->ISR = UART_ISR_FEI;
	      	huart->ErrorCode |= HAL_UART_ERROR_FE;
	    }

	    /* UART Over-Run interrupt occurred */
	    if (((isrflags & UART_ISR_OEI) != 0) && ((ieits & UART_IE_OEI) != 0))
	    {
            CLEAR_STATUS(huart->Instance->ISR, UART_ISR_OEI);//huart->Instance->ISR = UART_ISR_OEI;
	      	huart->ErrorCode |= HAL_UART_ERROR_ORE;
	    }

		/* clear error interrupt */
		//CLEAR_BIT(huart->Instance->IE, UART_IE_OEI|UART_IE_BEI|UART_IE_PEI|UART_IE_FEI);
        if(HAL_UART_ErrorCallback)
            HAL_UART_ErrorCallback(huart);
	}    
}


/******************************************************************************
*@brief : wait Tx FIFO empty
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
static HAL_StatusTypeDef HAL_UART_Wait_Tx_Done(UART_HandleTypeDef *huart)
{	

    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));
    
	/* wait TX not busy*/
	while(READ_BIT(huart->Instance->FR, UART_FR_BUSY)); 

	return HAL_OK;
}

/******************************************************************************
*@brief : Initialize the UART MSP: CLK, GPIO, NVIC
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    /* 
      NOTE: This function should be modified, when the callback is needed,
      the HAL_UART_MspInit can be implemented in the user file.
    */

    /* For Example */
    GPIO_InitTypeDef    GPIO_Uart = {0};
    
    if (huart->Instance == UART1) 
    {
        /* Enable Clock */
        __HAL_RCC_UART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /* A9:Tx  A10:Rx */
        GPIO_Uart.Pin       = GPIO_PIN_9 | GPIO_PIN_10;
        GPIO_Uart.Mode      = GPIO_MODE_AF_PP;
        GPIO_Uart.Pull      = GPIO_PULLUP;
        GPIO_Uart.Drive     = GPIO_DRIVE_LEVEL3;
        GPIO_Uart.Alternate = GPIO_FUNCTION_1;
        
        HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) 
        {
            /* A11:CTS */
            GPIO_Uart.Pin = GPIO_PIN_11;
            
            HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) 
        {
            /* A12:RTS */
            GPIO_Uart.Pin = GPIO_PIN_12;
            
            HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        }
        /* NVIC Config */
        NVIC_ClearPendingIRQ(UART1_IRQn);
        NVIC_SetPriority(UART1_IRQn, 5);
        NVIC_EnableIRQ(UART1_IRQn);
    }
    else if (huart->Instance == UART2) 
    {
        /* Enable Clock */
        __HAL_RCC_UART2_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /* A2:Tx  A3:Rx */
        GPIO_Uart.Pin       = GPIO_PIN_2 | GPIO_PIN_3;
        GPIO_Uart.Mode      = GPIO_MODE_AF_PP;
        GPIO_Uart.Pull      = GPIO_PULLUP;
        GPIO_Uart.Drive     = GPIO_DRIVE_LEVEL3;
        GPIO_Uart.Alternate = GPIO_FUNCTION_1;
        
        HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) 
        {
            /* A0:CTS */
            GPIO_Uart.Pin = GPIO_PIN_0;
            
            HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) 
        {
            /* A1:RTS */
            GPIO_Uart.Pin = GPIO_PIN_1;
            
            HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        }
        /* NVIC Config */
        NVIC_ClearPendingIRQ(UART2_IRQn);
        NVIC_SetPriority(UART2_IRQn, 5);
        NVIC_EnableIRQ(UART2_IRQn);
    }
    else if(huart->Instance == UART3)
    {
        /* Enable Clock */
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_UART3_CLK_ENABLE();
        /* B10:Tx  B11:Rx */
        GPIO_Uart.Pin       = GPIO_PIN_10 | GPIO_PIN_11;
        GPIO_Uart.Mode      = GPIO_MODE_AF_PP;
        GPIO_Uart.Pull      = GPIO_PULLUP;
        GPIO_Uart.Drive     = GPIO_DRIVE_LEVEL3;
        GPIO_Uart.Alternate = GPIO_FUNCTION_1;
        
        HAL_GPIO_Init(GPIOB, &GPIO_Uart);
        
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) 
        {
            /* B13:CTS */
            GPIO_Uart.Pin = GPIO_PIN_13;
            GPIO_Uart.Alternate = GPIO_FUNCTION_0;
            HAL_GPIO_Init(GPIOB, &GPIO_Uart);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) 
        {
            /* B14:RTS */
            GPIO_Uart.Pin = GPIO_PIN_14;
            GPIO_Uart.Alternate = GPIO_FUNCTION_0;
            HAL_GPIO_Init(GPIOB, &GPIO_Uart);
        }
        /* NVIC Config */
        NVIC_ClearPendingIRQ(UART3_IRQn);
        NVIC_SetPriority(UART3_IRQn, 5);
        NVIC_EnableIRQ(UART3_IRQn);
    }
    else if(huart->Instance == UART4)
    {
        /* Enable Clock */
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_UART4_CLK_ENABLE();
        /* A0:Tx  A1:Rx */
        GPIO_Uart.Pin       = GPIO_PIN_0 | GPIO_PIN_1;
        GPIO_Uart.Mode      = GPIO_MODE_AF_PP;
        GPIO_Uart.Pull      = GPIO_PULLUP;
        GPIO_Uart.Drive = GPIO_DRIVE_LEVEL3;
        GPIO_Uart.Alternate = GPIO_FUNCTION_3;
        
        HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) 
        {
            /* B7:CTS */
            GPIO_Uart.Pin = GPIO_PIN_7;
            GPIO_Uart.Alternate = GPIO_FUNCTION_4;
            HAL_GPIO_Init(GPIOB, &GPIO_Uart);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) 
        {
            /* A15:RTS */
            GPIO_Uart.Pin = GPIO_PIN_15;
            GPIO_Uart.Alternate = GPIO_FUNCTION_3;
            HAL_GPIO_Init(GPIOA, &GPIO_Uart);
        }
        /* NVIC Config */
        NVIC_ClearPendingIRQ(UART4_IRQn);
        NVIC_SetPriority(UART4_IRQn, 5);
        NVIC_EnableIRQ(UART4_IRQn);
    }
}

/******************************************************************************
*@brief : Initialize the UART DE Pin for RS485
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_RS485Msp_Init(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef    gpio = {0};
    
    if (huart->Instance == UART1) 
    {
        /* Initialization GPIO */
        /* PE3: UART1_RTS_DE */
        __HAL_RCC_GPIOE_CLK_ENABLE(); 
        gpio.Pin       = GPIO_PIN_3;
        gpio.Mode      = GPIO_MODE_AF_PP;
        gpio.Pull      = GPIO_PULLUP;
        gpio.Alternate = GPIO_FUNCTION_3;
        
        HAL_GPIO_Init(GPIOE, &gpio);
    }
    
    if (huart->Instance == UART2) 
    {
        /* Initialization GPIO */
        /* PA1: UART1_RTS_DE */
        __HAL_RCC_GPIOA_CLK_ENABLE();
        gpio.Pin       = GPIO_PIN_1;
        gpio.Mode      = GPIO_MODE_AF_PP;
        gpio.Pull      = GPIO_PULLUP;
        gpio.Alternate = GPIO_FUNCTION_1;
        
        HAL_GPIO_Init(GPIOA, &gpio);
    }
    
    if (huart->Instance == UART3) 
    {
        /* Initialization GPIO */
        /* PB14: UART1_RTS_DE */
        __HAL_RCC_GPIOB_CLK_ENABLE();
        gpio.Pin       = GPIO_PIN_14;
        gpio.Mode      = GPIO_MODE_AF_PP;
        gpio.Pull      = GPIO_PULLUP;
        gpio.Alternate = GPIO_FUNCTION_0;
        
        HAL_GPIO_Init(GPIOB, &gpio);
    }
    
    if (huart->Instance == UART4) 
    {
        /* Initialization GPIO */
        /* PA15: UART1_RTS_DE */
        __HAL_RCC_GPIOA_CLK_ENABLE();
        gpio.Pin       = GPIO_PIN_15;
        gpio.Mode      = GPIO_MODE_AF_PP;
        gpio.Pull      = GPIO_PULLUP;
        gpio.Alternate = GPIO_FUNCTION_3;
        
        HAL_GPIO_Init(GPIOA, &gpio);
    }
}

/******************************************************************************
*@brief : Initialize the UART according to the specified parameters in huart.
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart)
{

    if (huart == NULL)
    {
        return HAL_ERROR;
    }
    
    if (!IS_UART_ALL_INSTANCE(huart->Instance))                 return HAL_ERROR;
    if (!IS_UART_WORDLENGTH(huart->Init.WordLength))            return HAL_ERROR;
    if (!IS_UART_STOPBITS(huart->Init.StopBits))                return HAL_ERROR;
    if (!IS_UART_PARITY(huart->Init.Parity))                    return HAL_ERROR;
    if (!IS_UART_MODE(huart->Init.Mode))                        return HAL_ERROR;
    if (!IS_UART_HARDWARE_FLOW_CONTROL(huart->Init.HwFlowCtl))  return HAL_ERROR;

    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    HAL_UART_MspInit(huart);
    
    /* Config BaudRate */
    UART_Config_BaudRate(huart);
    
    /* Set the UART Communication parameters */
    huart->Instance->CR3 = huart->Init.WordLength | UART_CR3_FEN | huart->Init.StopBits | huart->Init.Parity;
    huart->Instance->CR1 = huart->Init.HwFlowCtl | huart->Init.Mode;
    
    if (huart->Init.Mode == UART_MODE_HALF_DUPLEX) 
    {
        huart->Instance->CR2 |= UART_CR2_HDSEL;
    }
    
    __HAL_UART_ENABLE(huart);
    
    huart->ErrorCode = HAL_UART_ERROR_NONE;
    
	return HAL_OK;
}

/******************************************************************************
*@brief : Initialize the UART RS485 according to the specified parameters in huart.
*         
*@param : huart: uart handle with UART parameters.
*@param : de_polarity: RS485 DE Pin polarity. see @UART_RS485_DE_POL_Enum
*@param : deat_time: the time between the DE Pin activated and data transmiting.
*@param : dedt_time: the time between the last transmiting of data and the DE Pin de-activated.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_RS485_Init(UART_HandleTypeDef *huart, UART_RS485_DE_POL_Enum de_polarity, uint8_t deat_time, uint8_t dedt_time)
{
    if(HAL_UART_Init(huart) == HAL_OK)
    {
        UART_TypeDef *instance = huart->Instance;
        
        /*uart RTS can not be used in RS485DE*/
        instance->CR1 &= ~UART_CR1_RTSEN;           //clear bit UART RTSen
        
        HAL_UART_RS485Msp_Init(huart);
        
        instance->BCNT |= UART_EX_BCNT_DEM;

        /* config DE Pin polarity */
        instance->BCNT &= ~UART_EX_BCNT_DEP;
        instance->BCNT |= de_polarity << 26;
        
        /* config deat time */
        instance->BCNT &= ~UART_EX_BCNT_DEAT_MASK;
        instance->BCNT |= (deat_time & 0xF) << UART_EX_BCNT_DEAT_POS;
        /* config dedt time */
        instance->BCNT &= ~UART_EX_BCNT_DEDT_MASK;
        instance->BCNT |= (dedt_time & 0xF) << UART_EX_BCNT_DEDT_POS;
    }
    else
    {
        return HAL_ERROR;
    }
    
    return HAL_OK;
}

/******************************************************************************
*@brief : Initialize the UART IRDA Mode according to the specified parameters in huart.
*         
*@param : huart: uart handle with UART parameters.
*@param : is_lowpwr: config IRDA low power mode.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_IRDA_Init(UART_HandleTypeDef *huart, bool is_lowpwr)
{
    if(HAL_UART_Init(huart) == HAL_OK)
    {
        uint32_t Uart_Clk;
        UART_TypeDef *instance = huart->Instance;
        
        if(instance == UART1)
        {
            Uart_Clk = HAL_RCC_GetPCLK2Freq();
        }
        else
        {
            Uart_Clk = HAL_RCC_GetPCLK1Freq();
        }
        
        instance->CR1 |= UART_CR1_SIREN;
        
        if(is_lowpwr)
        {
            instance->CR1 |= UART_CR1_SIRLP;
            instance->GTPR = (uint8_t)(Uart_Clk / (115200 * 16));
        }
        else
        {
            instance->CR1 &= ~UART_CR1_SIRLP;
        }
    }
    else
    {
        return HAL_ERROR;
    }
    
    return HAL_OK;
}


/******************************************************************************
*@brief : Initialize the Multi-UART Communication Mode 
*                   according to the specified parameters in huart.
*         
*@param : huart: uart handle with UART parameters.
*@param : addr: uart address
*@param : wakeupMode: UART waked up by idle line or address mark, 
*         see @UART_WakeupMode_Enum for more information
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t addr, UART_WakeupMode_Enum wakeupMode)
{
    /* Check the UART handle allocation */
    if (huart == NULL)
    {
        return HAL_ERROR;
    }

    if(HAL_UART_Init(huart) == HAL_OK)
    {
        /* config uart addr mode & addr */
        if(IS_UART_7BIT_ADDR_MODE(addr))
        {
            SET_BIT(huart->Instance->CR2, UART_CR2_ADDM7);
            MODIFY_REG(huart->Instance->CR2, UART_CR2_ADDR_Msk, addr & 0x7F);
        }
        else
        {
            CLEAR_BIT(huart->Instance->CR2, UART_CR2_ADDM7);
            MODIFY_REG(huart->Instance->CR2, UART_CR2_ADDR_Msk, addr & 0xF);
        }

        /* config uart wakeup mode */
        MODIFY_REG(huart->Instance->CR2, UART_CR2_WAKE, wakeupMode);
    }
    else
    {
        return HAL_ERROR;
    }

  __HAL_UART_ENABLE(huart);


  huart->ErrorCode = HAL_UART_ERROR_NONE;


  return HAL_OK;
}

/******************************************************************************
*@brief : DeInitialize the UART MSP
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
    /* 
      NOTE: This function should be modified, when the callback is needed,
      the HAL_UART_MspDeInit can be implemented in the user file.
    */    
    if (huart->Instance == UART1) 
    {
        /* Disable Clock */
        __HAL_RCC_UART1_CLK_DISABLE();

        /* DeInitialization GPIO */
        /* A9:Tx  A10:Rx */
        HAL_GPIO_DeInit(GPIOA,GPIO_PIN_9 | GPIO_PIN_10);
		
		if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) 
        {
            /* A11:CTS */
            HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) 
        {
            /* A12:RTS */
            HAL_GPIO_DeInit(GPIOA, GPIO_PIN_12);
        }
		
        /* NVIC DeInit */
        NVIC_DisableIRQ(UART1_IRQn);
		
    }
	else if(huart->Instance == UART2)
	{
        /*...*/
	}
    else if(huart->Instance == UART3)
	{
        /*...*/
	}
    else if(huart->Instance == UART4)
	{
        /*...*/
	}
}

/******************************************************************************
*@brief : DeInitialize the UART module
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart)
{

    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    /* DeInit the low level hardware : GPIO, CLOCK, NVIC */
    HAL_UART_MspDeInit(huart);

	return HAL_OK;
    
}

/******************************************************************************
*@brief : Send an amount of data by loop mode within timeout period.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to be sent.
*@param : timeout: Timeout duration, unit MS, 1(ms)~~0xFFFFFFFF(wait forever)
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size, uint32_t timeout)
{
    uint8_t  *pbuf_8    = NULL;
    uint16_t *pbuf_16   = NULL;
    uint32_t Start_Tick;
    
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));
    
    if (huart->Init.Mode == UART_MODE_HALF_DUPLEX) 
    {
        huart->Instance->CR1 &= ~UART_CR1_RXE; /* disable RX */
    }

    huart->TxCount = 0;
    
    if (huart->Init.WordLength == UART_WORDLENGTH_9B)
    {
      pbuf_16 = (uint16_t *) buf;
    }
    else
    {
      pbuf_8  = buf;
    }
    
    Start_Tick = HAL_GetTick();
    
    while (size--) 
    {
        if (pbuf_8 == NULL)
        {
            huart->Instance->DR = (uint16_t)(*pbuf_16 & 0x01FFU);
            pbuf_16++;
        }
        else
        {
            huart->Instance->DR = (uint8_t)(*pbuf_8 & 0xFFU);
            pbuf_8++;
        }

        huart->TxCount++;
        
        while (huart->Instance->FR & UART_FR_TXFF)
        {
            if ((HAL_GetTick() - Start_Tick) > timeout) 
            {
                return HAL_TIMEOUT;
            }
        }
    }
    
    HAL_UART_Wait_Tx_Done(huart); 

    if (huart->Init.Mode == UART_MODE_HALF_DUPLEX) 
    {
        huart->Instance->CR1 |= UART_CR1_RXE; /* enable RX */
    }
    
    return HAL_OK;
}

/******************************************************************************
*@brief : Receive an amount of data by loop mode within timeout period.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to receive.
*@param : timeout: Timeout duration, unit MS, 1(ms)~~0xFFFFFFFF(wait forever)
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size, uint32_t timeout)
{
    uint8_t  *pbuf_8  = NULL;
    uint16_t *pbuf_16 = NULL;
    uint32_t Start_Tick;
    
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    huart->RxCount = 0;
    
    if (huart->Init.WordLength == UART_WORDLENGTH_9B)
    {
      pbuf_16 = (uint16_t *) buf;
    }
    else
    {
      pbuf_8  = buf;
    }
    
    Start_Tick = HAL_GetTick();

    while (size--) 
    {
        while(huart->Instance->FR & UART_FR_RXFE)
        {
            if ((HAL_GetTick() - Start_Tick) > timeout)  
            {
                return HAL_TIMEOUT;
            }
        }
        
        if (pbuf_8 == NULL)
        {
            *pbuf_16 = (uint16_t)(huart->Instance->DR & 0x01FF);
            pbuf_16++;
        }
        else
        {
            *pbuf_8 = (uint16_t)(huart->Instance->DR & 0xFF);
            pbuf_8++;
        }

        huart->RxCount++;
    }
    
    return HAL_OK;
}

/******************************************************************************
*@brief : Receive an amount of data to Idle line or  BCNT time.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to receive.
*@param : rece_mode: by idle line, or by bit value count reached
*@param : timeout: BCNT value(relative to UART baudrate), when UART BaudRate = 115200, 
                    then set timeout = 115200,it is approximately 1 second. MAX BCNT value can be 0xFFFFFF.
*                   Only used when 'rece_mode' = RECEIVE_TOBCNT
*                             when 'rece_mode' = RECEIVE_TOIDLE, it is meaningless.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Receive_To_IDLEorBCNT(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size, 
                                                UART_Receive_Mode_Enum rece_mode, uint32_t timeout)
{
    uint8_t  *pbuf_8  = NULL;
    uint16_t *pbuf_16 = NULL;
    uint32_t Start_Tick;
    
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    huart->RxCount = 0;
    
    if (huart->Init.WordLength == UART_WORDLENGTH_9B)
    {
      pbuf_16 = (uint16_t *) buf;
    }
    else
    {
      pbuf_8  = buf;
    }
    
    if(rece_mode == RECEIVE_TOBCNT)
    {
        MODIFY_REG(huart->Instance->BCNT, UART_EX_BCNT_VALUE_MASK, timeout);
        SET_BIT(huart->Instance->BCNT, UART_EX_BCNT_AUTO_START_EN);
    }

    while (size--) 
    {
        while(huart->Instance->FR & UART_FR_RXFE)
        {
            if(rece_mode == RECEIVE_TOBCNT)
            {    
                if(READ_BIT(huart->Instance->ISR, UART_ISR_BCNTI))
                {
                    CLEAR_STATUS(huart->Instance->ISR, UART_ISR_BCNTI);
                    return HAL_TIMEOUT;
                }
            }
            else
            {
                if(READ_BIT(huart->Instance->ISR, UART_ISR_IDLEI))
                {
                    CLEAR_STATUS(huart->Instance->ISR, UART_ISR_IDLEI);
                    return HAL_TIMEOUT;
                }
            }
        }
        
        if (pbuf_8 == NULL)
        {
            *pbuf_16 = (uint16_t)(huart->Instance->DR & 0x01FF);
            pbuf_16++;
        }
        else
        {
            *pbuf_8 = (uint16_t)(huart->Instance->DR & 0xFF);
            pbuf_8++;
        }

        huart->RxCount++;
    }
    
    return HAL_OK;
}

/******************************************************************************
*@brief : Send an amount of data in interrupt mode.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to send.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));
    
    if (huart->TxBusy == true) 
    {
        return HAL_BUSY;
    }
    
    if (size == 0 || buf == NULL) 
    {
        return HAL_ERROR;
    }
    
    if (huart->Init.Mode == UART_MODE_HALF_DUPLEX) 
    {
        huart->Instance->CR1 &= ~UART_CR1_RXE; //disable RX
    }
    
    huart->TxSize  = size;
    huart->TxCount = 0;
    huart->TxData   = buf;
    huart->TxBusy   = true;
    
    /* Clear TXI Status */
    huart->Instance->ISR = UART_ISR_TXI;
    /* FIFO Enable */
    SET_BIT(huart->Instance->CR3, UART_CR3_FEN);
	/*FIFO Select*/
    __UART_TXI_FIFO_LEVEL_SET(UART_TX_FIFO_1_2);

    for(;;) 
    {	
        /*Data Size less than 16Byte */
	    if(size == huart->TxCount) 
	    {
	        huart->TxBusy = false;
			
			while ((huart->Instance->FR & UART_FR_BUSY)){}
			
            if(HAL_UART_TxCpltCallback)
                HAL_UART_TxCpltCallback(huart);
			
	        return HAL_OK;  
	    }
	    if(READ_BIT(huart->Instance->FR, UART_FR_TXFF)) 
	    {				
	         break;
	    }
        if (huart->Init.WordLength == UART_WORDLENGTH_9B)
        {
            uint16_t *pbuf_16;
            pbuf_16 = (uint16_t *)huart->TxData;
            huart->Instance->DR = (*pbuf_16) & 0x1FF;
            huart->TxData += 2U;
            huart->TxCount++;
        }
        else
        {
            huart->Instance->DR = huart->TxData[huart->TxCount++];
        }
    }
	
    /* Enable TX interrupt */
    huart->Instance->IE |= UART_IE_TXI;

    return HAL_OK;
}

/******************************************************************************
*@brief : Receive an amount of data in interrupt mode.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to receive.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));
    
    if (huart->RxBusy == true) 
    {
        return HAL_BUSY;
    }

    if (size == 0 || buf == NULL) 
    {
        return HAL_ERROR;
    }
    
    if (huart->Init.Mode == UART_MODE_HALF_DUPLEX) 
    {
        huart->Instance->CR1 |= UART_CR1_RXE; //enable RX
    }
    
    huart->RxSize  = size;
    huart->RxCount = 0;
    huart->RxData   = buf;
    huart->RxBusy   = true;

    /* Clear RXI Status */
    huart->Instance->ISR = UART_ISR_RXI;
    /* FIFO Enable */
    SET_BIT(huart->Instance->CR3, UART_CR3_FEN);
	/*FIFO Select*/
    __UART_RXI_FIFO_LEVEL_SET(UART_RX_FIFO_1_2);
	/* Enable the UART Errors interrupt */
	SET_BIT(huart->Instance->IE,UART_IE_OEI|UART_IE_BEI|UART_IE_PEI|UART_IE_FEI);
    /* Enable RX and RTI interrupt */
    SET_BIT(huart->Instance->IE,UART_IE_RXI | UART_IE_IDLEI); 

    return HAL_OK;
}

/******************************************************************************
*@brief : Send an amount of data in DMA mode.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to send.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    if (huart->TxBusy == true) 
    {
        return HAL_BUSY;
    }

    if (size == 0 || buf == NULL) 
    {
        return HAL_ERROR;
    }

    huart->Instance->CR1 |= UART_CR1_TXDMAE;

    __UART_TXI_FIFO_LEVEL_SET(UART_TX_FIFO_1_16);

    if (HAL_DMA_Start_IT(huart->HDMA_Tx, (uint32_t)buf, (uint32_t)(&huart->Instance->DR), size))
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

/******************************************************************************
*@brief : Receive an amount of data in DMA mode.
*         
*@param : huart: uart handle with UART parameters.
*@param : buf: Pointer to data buffer.
*@param : size: Amount of data elements to receive.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    if (huart->RxBusy == true) 
    {
        return HAL_BUSY;
    }

    if (size == 0 || buf == NULL) 
    {
        return HAL_ERROR;
    }

    huart->Instance->CR1 |= UART_CR1_RXDMAE;
    
    __UART_RXI_FIFO_LEVEL_SET(UART_RX_FIFO_1_16);

    if (HAL_DMA_Start_IT(huart->HDMA_Rx, (uint32_t)(&huart->Instance->DR), (uint32_t)buf, size))
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

/******************************************************************************
*@brief : Tx Transfer completed callbacks.
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    /* 
      NOTE: This function Should be modified, when the callback is needed,
      the HAL_UART_TxCpltCallback could be implemented in the user file.
    */
}

/******************************************************************************
*@brief : Rx Transfer completed callbacks.
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* 
      NOTE: This function Should be modified, when the callback is needed,
      the HAL_UART_RxCpltCallback could be implemented in the user file.
    */
}

/******************************************************************************
*@brief : Recv Error callbacks.
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
__weak void HAL_UART_ErrorCallBack(UART_HandleTypeDef *huart)
{
    /* 
      NOTE: This function Should be modified, when the callback is needed,
      the HAL_UART_ErrorCallBack could be implemented in the user file.
    */
}

/******************************************************************************
*@brief : Config UART BaudRate
*         
*@param : huart: uart handle with UART parameters.
*@return: None
******************************************************************************/
static void UART_Config_BaudRate(UART_HandleTypeDef *huart)
{
    uint32_t pclk;
    uint32_t ibaud, fbaud;
    uint64_t tmp;

    if (UART1 == huart->Instance) 
    {
        pclk = HAL_RCC_GetPCLK2Freq(); 
    }
    else
    {
        pclk = HAL_RCC_GetPCLK1Freq();  
    }

    /* Integral part */
    ibaud = pclk / (huart->Init.BaudRate * 16);

    /* Fractional part */
    tmp = pclk % (huart->Init.BaudRate * 16);
    tmp = (tmp * 1000000) / (huart->Init.BaudRate * 16);
    fbaud     = (tmp * 64 + 500000) / 1000000;

    if (fbaud >= 64) 
    {
        MODIFY_REG(huart->Instance->BRR, UART_BRR_IBAUD_Msk, ((ibaud + 1) << UART_BRR_IBAUD_Pos));
        MODIFY_REG(huart->Instance->BRR, UART_BRR_FBAUD_Msk, (0 << UART_BRR_FBAUD_Pos));
    }
    else 
    {
        MODIFY_REG(huart->Instance->BRR, UART_BRR_IBAUD_Msk, (ibaud << UART_BRR_IBAUD_Pos));
        MODIFY_REG(huart->Instance->BRR, UART_BRR_FBAUD_Msk, (fbaud << UART_BRR_FBAUD_Pos));
    }
}

/******************************************************************************
*@brief : Return the uart State
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_BUSY or HAL_OK
******************************************************************************/
HAL_StatusTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

	if(huart->TxBusy || huart->RxBusy)
	{
		return HAL_BUSY;		
	}

	return HAL_OK;
}

/******************************************************************************
*@brief : Return the uart Error
*         
*@param : huart: uart handle with UART parameters.
*@return: uart errcode
******************************************************************************/
uint32_t HAL_UART_GetError(UART_HandleTypeDef *huart)
{
  	return huart->ErrorCode;
}

/******************************************************************************
*@brief : Abort ongoing transfers(blocking mode)
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart)
{
	assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

	/*disble all interrupt*/
	huart->Instance->IE  =0x00;

	/* Disable the UART DMA Tx request if enable */
	if(READ_BIT(huart->Instance->CR1, UART_CR1_TXDMAE))
	{
		CLEAR_BIT(huart->Instance->CR1, UART_CR1_TXDMAE);

		/* Abort the UART Tx Channel   */
		if(huart->HDMA_Tx)
		{
			/*Set the UART DMA Abort callback to Null */
			huart->HDMA_Tx->XferCpltCallback =NULL;

			if(HAL_DMA_Abort(huart->HDMA_Tx)!=HAL_OK)
			{
				return HAL_TIMEOUT;
			}
		}
	}

	/* Disable the UART DMA Rx request if enable */
	if(READ_BIT(huart->Instance->CR1, UART_CR1_RXDMAE))
	{
		CLEAR_BIT(huart->Instance->CR1, UART_CR1_RXDMAE);
		
		/* Abort the UART Rx Channel   */
		if(huart->HDMA_Rx)
		{
			/*Set the UART DMA Abort callback to Null */
			huart->HDMA_Rx->XferCpltCallback =NULL;

			if(HAL_DMA_Abort(huart->HDMA_Rx)!=HAL_OK)
			{
				return HAL_TIMEOUT;
			}
		}
	}

	/*Reset Tx and Rx Transfer size*/
	huart->TxSize = 0;
	huart->RxSize = 0;

	/* Restore huart->TxBusy and huart->RxBusy to Ready */
	huart->TxBusy = false;
	huart->RxBusy = false;
		
	return HAL_OK;
}

/******************************************************************************
*@brief : Pause the UART DMA Transfer
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    if(READ_BIT(huart->Instance->CR1, UART_CR1_TXDMAE))
    {
        /* Disable the UART DMA Tx request */
        CLEAR_BIT(huart->Instance->CR1, UART_CR1_TXDMAE);
    }

    if (READ_BIT(huart->Instance->CR1, UART_CR1_RXDMAE))
    {
        /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
        CLEAR_BIT(huart->Instance->IE, UART_IE_OEI|UART_IE_BEI|UART_IE_FEI);

        /* Disable the UART DMA Rx request */
        CLEAR_BIT(huart->Instance->CR1, UART_CR1_RXDMAE);
    }

    return HAL_OK;
}

/******************************************************************************
*@brief : Resume the UART DMA Transfer
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));

    if (huart->TxBusy == false)
    {
        /* Enable the UART DMA Tx request */
        SET_BIT(huart->Instance->CR1, UART_CR1_TXDMAE);
    }

    if (huart->RxBusy == false)
    {
        /* Reenable PE and ERR (Frame error, noise error, overrun error) interrupts */
        SET_BIT(huart->Instance->IE, UART_IE_OEI|UART_IE_BEI|UART_IE_FEI);

        /* Enable the UART DMA Rx request */
        SET_BIT(huart->Instance->CR1, UART_CR1_RXDMAE);
    }

    return HAL_OK;
}

/******************************************************************************
*@brief : Stop the UART DMA Transfer
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart)
{
    assert_param (IS_UART_ALL_INSTANCE(huart->Instance));
    
    if(huart->Instance->CR1 & UART_CR1_TXDMAE)
    {
        CLEAR_BIT(huart->Instance->CR1, UART_CR1_TXDMAE);
        if(huart->HDMA_Tx != NULL)
        {
            HAL_DMA_Abort(huart->HDMA_Tx);
        }
        
        CLEAR_BIT(huart->Instance->IE, (UART_IE_TXI));
    }
    
    if(huart->Instance->CR1 & UART_CR1_RXDMAE)
    {
        CLEAR_BIT(huart->Instance->CR1, UART_CR1_RXDMAE);
        if(huart->HDMA_Rx != NULL)
        {
            HAL_DMA_Abort(huart->HDMA_Rx);
        }

        CLEAR_BIT(huart->Instance->IE, (UART_IE_RXI | UART_IE_PEI));

        CLEAR_BIT(huart->Instance->IE, UART_IE_IDLEI);
    }

  return HAL_OK;
}

/******************************************************************************
*@brief : uart module enter into mute mode
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_OK
******************************************************************************/
HAL_StatusTypeDef HAL_UART_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart)
{
    SET_BIT(huart->Instance->CR2, UART_CR2_RWU);
    return HAL_OK;
}

/******************************************************************************
*@brief : uart module exit from mute mode
*         
*@param : huart: uart handle with UART parameters.
*@return: HAL_OK
******************************************************************************/
HAL_StatusTypeDef HAL_UART_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart)
{
    CLEAR_BIT(huart->Instance->CR2, UART_CR2_RWU);
    return HAL_OK;
}

/******************************************************************************
*@brief : which uart instance is selected for debug using
*         
*@param : UARTx: UART instance.
*@return: None
******************************************************************************/
void HAL_UART_SetDebugUart(UART_TypeDef *UARTx)
{
    if(UARTx != NULL)
    {
        assert_param (IS_UART_ALL_INSTANCE(UARTx));
    }
    g_DebugUart = UARTx;
}

/******************************************************************************
*@brief : re-direct fputc to uart port
*         
*@param : ch:  character to send
*@param : f: a pointer to FILE struct, no use in uart re-directing
*@return: character sent
******************************************************************************/
__weak int fputc(int ch, FILE *f)
{
    if(g_DebugUart)
    {
        g_DebugUart->DR = ch;    
        while ((g_DebugUart->FR & UART_FR_BUSY));        
    }
    return ch;
}

#endif //HAL_UART_MODULE_ENABLED

