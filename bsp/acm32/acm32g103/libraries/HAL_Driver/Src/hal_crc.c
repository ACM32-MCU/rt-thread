/*
  ******************************************************************************
  * @file    HAL_Crc.c
  * @author  AisinoChip Firmware Team
  * @version V1.0.0
  * @date    2020
  * @brief   CRC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (UART).
  *           @ Initialization and de-initialization functions
  *           @ IO operation functions
  *           @ Peripheral Control functions
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020 AisinoChip.
  * All rights reserved.
  ******************************************************************************
*/
#include "hal.h"

/*********************************************************************************
* Function    : HAL_CRC_Init
* Description : Initialize the CRC.
* Input       : hcrc: CRC handle.
* Output      : 
* Author      : cl                         Data : 2021 
**********************************************************************************/
void HAL_CRC_Init(CRC_HandleTypeDef *hcrc)
{
    /* 
      NOTE: This function could be modified, the HAL_UART_MspInit can be implemented in the user file.
    */

    /* For Example */
    __HAL_RCC_CRC_CLK_ENABLE();//enable CRC clock	

	hcrc->Instance->CTRL = hcrc->Init.PolyRev | hcrc->Init.OutxorRev | hcrc->Init.InitRev | hcrc->Init.RsltRev |
	                       hcrc->Init.DataRev | hcrc->Init.PolyLen   | hcrc->Init.DataLen;

	hcrc->Instance->INIT = hcrc->Init.InitData;	
	hcrc->Instance->OUTXOR = hcrc->Init.OutXorData;
	hcrc->Instance->POLY = hcrc->Init.PolyData;
}

/*********************************************************************************
* Function    : HAL_CRC_Calculate
* Description : Calculate the crc calue of input data.
* Input       : hcrc:         CRC handle.
* Output      : CRC value
* Author      : cl                        Data : 2021 
**********************************************************************************/
uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc)
{
	HAL_CRC_Init(hcrc);

    while(hcrc->CRC_Data_Len--)
    {
        hcrc->Instance->DATA = *hcrc->CRC_Data_Buff++;
    }
	return (hcrc->Instance->DATA);
    
//  __HAL_RCC_CRC_CLK_DISABLE();//enable CRC clock
}


