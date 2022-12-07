/******************************************************************************
*@file  : hal_uart_ex.h
*@brief : Header file of UART EX HAL module.
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/
#ifndef __HAL_UART_EX_H__
#define __HAL_UART_EX_H__

#include "acm32g103_hal_conf.h"

/****************  Bit definition for UART GTPR register  ***********************/
#define UART_EX_GTPR_GT_POS                 (8U)
#define UART_EX_GTPR_GT_MASK                (0xF00U)
#define UART_EX_GTPR_PSC_POS                (0U)
#define UART_EX_GTPR_PSC_MASK               (0xFFU)

/****************  Bit definition for UART BCNT register  ***********************/
#define UART_EX_BCNT_DEM                     BIT27
#define UART_EX_BCNT_DEP                     BIT26
#define UART_EX_BCNT_AUTO_START_EN           BIT25
#define UART_EX_BCNT_START                   BIT24
#define UART_EX_BCNT_VALUE_POS              (0U)
#define UART_EX_BCNT_VALUE_MASK             (0xFFFFFFU)
#define UART_EX_BCNT_DEAT_MASK              (0xF)
#define UART_EX_BCNT_DEAT_POS               (0x0)
#define UART_EX_BCNT_DEDT_MASK              (0xF0)
#define UART_EX_BCNT_DEDT_POS               (4)

/****************  Definition of LIN BUS VERSION  ***********************/
#define UART_LIN_V1D3         0    //Lin bus version 1.3
#define UART_LIN_V2DX         1    //Lin bus version 2.0/2.1/2.2

#define HAL_UART_LIN_Init   HAL_UART_Init
void HAL_UART_LIN_Master_Transmit(UART_HandleTypeDef *huart, uint8_t Lin_Version, uint8_t Lin_Id, uint8_t *pData, uint8_t Size);
void HAL_UART_LIN_Slave_Transmit(UART_HandleTypeDef *huart, uint8_t Lin_Version, uint8_t Lin_Id, uint8_t *pData, uint8_t Size);
uint8_t HAL_UART_LIN_Master_Receive(UART_HandleTypeDef *huart, uint8_t Lin_Version, uint8_t Lin_Id, uint8_t *pData, uint32_t Timeout);
uint8_t HAL_UART_LIN_Slave_Receive(UART_HandleTypeDef *huart, uint8_t Lin_Version, uint8_t *pData, uint32_t Timeout);

#endif
