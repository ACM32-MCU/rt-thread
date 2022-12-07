/******************************************************************************
* @file    hal_uart.h

* @brief   Header file of UART HAL module.
* @version V1.0.0
* @date    2020
******************************************************************************/
#ifndef __HAL_UART_H__
#define __HAL_UART_H__

#include "acm32g103_hal_conf.h"


/** @defgroup UARTEx_Word_Length UARTEx Word Length
  * @{
  */
#define UART_WORDLENGTH_5B                  (0x00000000U)    /*!< 5-bit Word Length */
#define UART_WORDLENGTH_6B                  (0x00000040U)    /*!< 6-bit Word Length */
#define UART_WORDLENGTH_7B                  (0x00000080U)    /*!< 7-bit Word Length */
#define UART_WORDLENGTH_8B                  (0x000000C0U)    /*!< 8-bit Word Length */
#define UART_WORDLENGTH_9B                  (0x00000100U)    /*!< 9-bit Word Length */
/**
  * @}
  */


/** @defgroup UART_Parity  UART Parity
  * @{
  */
#define UART_PARITY_NONE                    (0x00000000U)    /*!< No parity   */
#define UART_PARITY_EVEN                    (0x00000006U)    /*!< Even parity */
#define UART_PARITY_ODD                     (0x00000002U)    /*!< Odd parity  */
#define UART_PARITY_0                       (0x00000206U)    /*!< 0 parity  */
#define UART_PARITY_1                       (0x00000202U)    /*!< 1 parity  */
/**
  * @}
  */


/** @defgroup UART_Stop_Bits   UART Number of Stop Bits
  * @{
  */
#define UART_STOPBITS_1                     (0x00000000U)    /*!< UART frame with 1 stop bit    */
#define UART_STOPBITS_2                     (0x00000008U)    /*!< UART frame with 2 stop bits   */
/**
  * @}
  */


/** @defgroup UART_Hardware_Flow_Control UART Hardware Flow Control
  * @{
  */
#define UART_HWCONTROL_NONE                  (0x00000000U)        /*!< No hardware control       */
#define UART_HWCONTROL_CTS                   (0x00008000U)        /*!< Clear To Send             */
#define UART_HWCONTROL_RTS                   (0x00004000U)        /*!< Request To Send           */
#define UART_HWCONTROL_CTS_RTS               (UART_HWCONTROL_CTS | UART_HWCONTROL_RTS)    /*!< Request and Clear To Send */
/**
  * @}
  */


/** @defgroup UART_Mode UART Transfer Mode
  * @{
  */
#define UART_MODE_RX                        (0x00000200)        /*!< RX mode        */
#define UART_MODE_TX                        (0x00000100)        /*!< TX mode        */
#define UART_MODE_TX_RX                     (0x00000300)        /*!< RX and TX mode */
#define UART_MODE_HALF_DUPLEX               (0x20000300)        /*!< Single half duplex */
/**
  * @}
  */


/** @defgroup FIFO interrupt Config
  * @{
  */
#define UART_TX_FIFO_1_16             (0x00001400)        /*!< Transfer 1 Data  */
#define UART_TX_FIFO_1_8              (0x00000000)        /*!< Transfer 2 Data  */
#define UART_TX_FIFO_1_4              (0x00000400)        /*!< Transfer 4 Data  */
#define UART_TX_FIFO_1_2              (0x00000800)        /*!< Transfer 8 Data  */
#define UART_TX_FIFO_3_4              (0x00000C00)        /*!< Transfer 12 Data */
#define UART_TX_FIFO_7_8              (0x00001000)        /*!< Transfer 14 Data */

#define UART_RX_FIFO_1_16             (0x0000A000)        /*!< Receive  1 Data  */
#define UART_RX_FIFO_1_8              (0x00000000)        /*!< Receive  2 Data  */
#define UART_RX_FIFO_1_4              (0x00002000)        /*!< Receive  4 Data  */
#define UART_RX_FIFO_1_2              (0x00004000)        /*!< Receive  8 Data  */
#define UART_RX_FIFO_3_4              (0x00006000)        /*!< Receive  12 Data */
#define UART_RX_FIFO_7_8              (0x00008000)        /*!< Receive  14 Data */
/**
  * @}
  */

/** @defgroup UART_Error_Code UART Error Code
  * @{
  */
#define HAL_UART_ERROR_NONE              0x00000000U   /*!< No error            */
#define HAL_UART_ERROR_PE                0x00000001U   /*!< Parity error        */
#define HAL_UART_ERROR_NE                0x00000002U   /*!< Noise error         */
#define HAL_UART_ERROR_FE                0x00000004U   /*!< Frame error         */
#define HAL_UART_ERROR_ORE               0x00000008U   /*!< Overrun error       */
#define HAL_UART_ERROR_DMA               0x00000010U   /*!< DMA transfer error  */
/**
  * @}
  */


/*
 * @brief UART Init Structure definition
 */
typedef struct
{
    uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate. */

    uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                             This parameter can be a value of @ref UARTEx_Word_Length. */

    uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                             This parameter can be a value of @ref UART_Stop_Bits. */

    uint32_t Parity;                    /*!< Specifies the parity mode. 
                                             This parameter can be a value of @ref UART_Parity. */

    uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                             This parameter can be a value of @ref UART_Mode. */

    uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                             This parameter can be a value of @ref UART_Hardware_Flow_Control. */

}UART_InitTypeDef;

/*
 * @brief  UART handle Structure definition
 */
typedef struct
{
    UART_TypeDef            *Instance;                /*!< UART registers base address        */

    UART_InitTypeDef         Init;                    /*!< UART communication parameters      */

    uint32_t                 TxSize;                  /*!< UART Transmit parameters in interrupt  */
    __IO uint32_t            TxCount;
    uint8_t                 *TxData;
    
    uint32_t                 RxSize;                  /*!< UART Receive parameters in interrupt  */
    __IO uint32_t            RxCount; 
    uint8_t                 *RxData;  
    
    
    __IO uint8_t             TxBusy;  
    __IO uint8_t             RxBusy;  
    
    DMA_HandleTypeDef       *HDMA_Tx;                 /*!< UART Tx DMA handle parameters */
    DMA_HandleTypeDef       *HDMA_Rx;                 /*!< UART Rx DMA handle parameters */ 

	__IO uint32_t           ErrorCode;                /*!<UART Error Code */

}UART_HandleTypeDef;

/******************************************************************************
*@brief : RS485 DE Pin polarity enum
*         
*@note : 
******************************************************************************/
typedef enum
{
    RS485_DE_POLARITY_HIGH = 0,     /*!< RS485 DE Pin, High active*/
    RS485_DE_POLARITY_LOW,          /*!< RS485 DE Pin, Low active*/
    
}UART_RS485_DE_POL_Enum;

/******************************************************************************
*@brief : UART wake up method enum
*         
*@note : 
******************************************************************************/
typedef enum
{
    UART_WKUP_BY_IDLELINE = 0,      /*!< UART is waked up by idle line */
    UART_WKUP_BY_ADDR,              /*!< UART is waked up by address mark */
    
}UART_WakeupMode_Enum;


/******************************************************************************
*@brief : UART receive mode enum
*         
*@note : the enum is used in UART LOOP receive function: HAL_UART_Receive_To_Idle_BCNT
******************************************************************************/
typedef enum
{
    RECEIVE_TOIDLE,                 /*!< end of receiving data by idle line checked */
    RECEIVE_TOBCNT,                 /*!< end of receiving data by bit count value reached */
}UART_Receive_Mode_Enum;

/** @defgroup  GPIO Private Macros
  * @{
  */
#define IS_UART_ALL_INSTANCE(INSTANCE)    (((INSTANCE) == UART1) || \
                                           ((INSTANCE) == UART2) || \
                                           ((INSTANCE) == UART3) || \
                                           ((INSTANCE) == UART4))

#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)  (((INSTANCE) == UART1) || \
                                               ((INSTANCE) == UART2) || \
                                               ((INSTANCE) == UART3) || \
                                               ((INSTANCE) == UART4))

#define IS_UART_WORDLENGTH(__WORDLENGTH__)    (((__WORDLENGTH__) == UART_WORDLENGTH_5B) || \
                                               ((__WORDLENGTH__) == UART_WORDLENGTH_6B) || \
                                               ((__WORDLENGTH__) == UART_WORDLENGTH_7B) || \
                                               ((__WORDLENGTH__) == UART_WORDLENGTH_8B) || \
                                               ((__WORDLENGTH__) == UART_WORDLENGTH_9B))

#define IS_UART_STOPBITS(__STOPBITS__)    (((__STOPBITS__) == UART_STOPBITS_1) || \
                                           ((__STOPBITS__) == UART_STOPBITS_2))

#define IS_UART_PARITY(__PARITY__)        (((__PARITY__) == UART_PARITY_NONE) || \
                                           ((__PARITY__) == UART_PARITY_EVEN) || \
                                           ((__PARITY__) == UART_PARITY_ODD))

#define IS_UART_MODE(__MODE__)            (((__MODE__) == UART_MODE_RX)          || \
                                           ((__MODE__) == UART_MODE_TX)          || \
                                           ((__MODE__) == UART_MODE_TX_RX)       || \
                                           ((__MODE__) == UART_MODE_HALF_DUPLEX))
                                           
#define IS_UART_HARDWARE_FLOW_CONTROL(__CONTROL__)    (((__CONTROL__) == UART_HWCONTROL_NONE) || \
                                                       ((__CONTROL__) == UART_HWCONTROL_RTS)  || \
                                                       ((__CONTROL__) == UART_HWCONTROL_CTS)  || \
                                                       ((__CONTROL__) == UART_HWCONTROL_CTS_RTS))
                                                       
#define UART_7BIT_ADDR_MSK                  £¨0x80£©
#define IS_UART_7BIT_ADDR_MODE(addr)        ((addr & 0x80) == 0x80)
                                                       
                                                       
/** @brief  Enable UART
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval None
  */
#define __HAL_UART_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  UART_CR1_UARTEN)

/** @brief  Disable UART
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval None
  */
#define __HAL_UART_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~UART_CR1_UARTEN)



#define CLEAR_STATUS(reg, flag)     WRITE_REG(reg, flag)


#define __UART_TXI_FIFO_LEVEL_SET(fifo_level)      MODIFY_REG(huart->Instance->CR3, UART_CR3_TXIFLSEL_Msk, fifo_level); 

#define __UART_RXI_FIFO_LEVEL_SET(fifo_level)      MODIFY_REG(huart->Instance->CR3, UART_CR3_RXIFLSEL_Msk, fifo_level);  
/**
  * @}
  */

/* HAL_UART_IRQHandler */
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);

/* HAL_UART_MspInit */
void HAL_UART_MspInit(UART_HandleTypeDef *huart);

/* HAL_UART_Init */
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);

/* HAL_UART_DeInit */
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);

/*uart init for RS485*/
HAL_StatusTypeDef HAL_UART_RS485_Init(UART_HandleTypeDef *huart, UART_RS485_DE_POL_Enum de_polarity, uint8_t deat_time, uint8_t dedt_time);

/*uart init for IRDA*/
HAL_StatusTypeDef HAL_UART_IRDA_Init(UART_HandleTypeDef *huart, bool is_lowpwr);

/* uart init for multi-processor */
HAL_StatusTypeDef HAL_UART_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t addr, UART_WakeupMode_Enum wakeupMode);

/* HAL_UART_GetState */
HAL_StatusTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);

/* HAL_UART_GetError*/
uint32_t HAL_UART_GetError(UART_HandleTypeDef *huart);

/* HAL_UART_Abort*/
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);

/* HAL_UART_DMAPause */
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);

/* HAL_UART_DMAResume */
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);


HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

/* HAL_UART_Transmit */
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size, uint32_t timeout);

/* HAL_UART_Receive */
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size, uint32_t timeout);

HAL_StatusTypeDef HAL_UART_Receive_To_IDLEorBCNT(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size, 
                                                UART_Receive_Mode_Enum rece_mode, uint32_t timeout);

/* HAL_UART_Transmit_IT */
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size);

/* HAL_UART_Receive_IT */
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size);

/* HAL_UART_Transmit_DMA */
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size);

/* HAL_UART_Receive_DMA */
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *buf, uint32_t size);

void HAL_UART_SetDebugUart(UART_TypeDef *UARTx);

#endif
