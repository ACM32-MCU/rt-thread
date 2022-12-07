
/******************************************************************************
* @file      : HAL_ADC.c
* @version   : 1.0
* @date      : 2022.10.29
* @brief     : ADC HAL module driver
*   
* @history   :	
*   2022.10.25    lwq    create
*   
******************************************************************************/
#include "hal.h"


#ifdef HAL_ADC_MODULE_ENABLED



/******************************************************************************
* @brief : This function handles ADC interrupt request.
* @param : None.
* @return: none
******************************************************************************/
__weak void HAL_ADC_IRQCallback(void)
{

}

/******************************************************************************
* @brief: Handle ADC interrupt request.
* @param: None.
* @return: None
******************************************************************************/
void HAL_ADC_IRQHandler(void)
{
    HAL_ADC_IRQCallback();
}


/******************************************************************************
* @brief : Initialize the ADC MSP.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: none
******************************************************************************/
__weak void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{   
    /* 
      NOTE : This function should be modified by the user.
      the HAL_ADC_MspInit can be implemented in the user file.
    */
    UNUSED(hadc);  
}

/******************************************************************************
* @brief : Deinitialize the ADC MSP.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: none
******************************************************************************/
__weak void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{    
    /* 
    NOTE : This function should be modified by the user.
    the HAL_ADC_MspDeInit can be implemented in the user file.
    */
    UNUSED(hadc);        
}

 /******************************************************************************
* @brief : Init the ADC module.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef* hadc)
{
    ADC_Common_TypeDef *tmpADC_Common;
    /* Check the ADC handle allocation */
    if (hadc == NULL)
    {
        return HAL_ERROR;
    }

    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
    assert_param(IS_ADC_ALL_CONCONVMODE(hadc->Init.ConConvMode));
    assert_param(IS_ADC_ALL_DMAMODE(hadc->Init.DMAMode));
    assert_param(IS_ADC_ALL_OVERMODE(hadc->Init.OverMode));
    assert_param(IS_ADC_ALL_OVERSAMPMODE(hadc->Init.OverSampMode));       
    assert_param(IS_ADC_ALL_ANALOGWDGEN(hadc->Init.AnalogWDGEn));
    assert_param(IS_ADC_ALL_CLOCKDIV(hadc->Init.ClockPrescaler));   
    assert_param(IS_ADC_ALL_CHANNELEN(hadc->Init.ChannelEn));


    /* Init the low level hardware : GPIO, CLOCK, NVIC, DMA */
    HAL_ADC_MspInit(hadc);

    //Reset AFE.
    SET_BIT(hadc->Instance->CR2,ADC_CR2_AFERSTN);

    //Set Clock DIV.
    tmpADC_Common = ADC_COMMON_REGISTER(hadc);

    MODIFY_REG(tmpADC_Common->CCR,ADC_CCR_ADCDIV_Msk,hadc->Init.ClockPrescaler<<ADC_CCR_ADCDIV_Pos);

    //Resolution
    hadc->Instance->CR2 &= ~(ADC_CR2_RES);
    hadc->Instance->CR2 |= hadc->Init.Resolution;

    /* Set ADC data alignment */
    hadc->Instance->CR2 &= ~(ADC_CR2_ALIGN);
    hadc->Instance->CR2 |= hadc->Init.DataAlign;

    //Set continued convert mode
    if(hadc->Init.ConConvMode)
    {
        SET_BIT(hadc->Instance->CR1,ADC_CR1_CONT);
    }
    else
    {
        CLEAR_BIT(hadc->Instance->CR1,ADC_CR1_CONT);
    }
    //Set Discontinued convert mode
    if(hadc->Init.DiscontinuousConvMode != DISABLE)
    {
        /* Enable the selected ADC regular discontinuous mode */
        hadc->Instance->CR1 |= (uint32_t)ADC_CR1_DISCEN;

        /* Set the number of channels to be converted in discontinuous mode */
        hadc->Instance->CR1 &= ~(ADC_CR1_DISCNUM_Msk);
        hadc->Instance->CR1 |=  ((hadc->Init.NbrOfDiscConversion-1) <<ADC_CR1_DISCNUM_Pos);
    }
    else
    {
        /* Disable the selected ADC regular discontinuous mode */
        hadc->Instance->CR1 &= ~(ADC_CR1_DISCEN);
    }

    //Overflow
    if(hadc->Init.OverMode == ADC_OVERMODE_ENABLE)
    {
        SET_BIT(hadc->Instance->CR2,ADC_CR2_OVRMOD);
    }
    else
    {
        CLEAR_BIT(hadc->Instance->CR2,ADC_CR2_OVRMOD);
    }
    //Over Sample Set
    if(hadc->Init.OverSampMode)
    {
        MODIFY_REG(hadc->Instance->CR2,ADC_CR2_OVSR_Msk,hadc->Init.Oversampling.Ratio<<ADC_CR2_OVSR_Pos);   //over sample rate
        MODIFY_REG(hadc->Instance->CR2,ADC_CR2_OVSS_Msk,hadc->Init.Oversampling.RightBitShift<<ADC_CR2_OVSS_Pos); //over sample right shift.
        SET_BIT(hadc->Instance->CR2,ADC_CR2_OVSE); // Regular channel over sample en.
        if(hadc->Init.Oversampling.TriggeredMode)
        {
            SET_BIT(hadc->Instance->CR2,ADC_CR2_TROVS); // N times sample every trig.
        }
        else
        {
            CLEAR_BIT(hadc->Instance->CR2,ADC_CR2_TROVS); // 1 time sample every trig.
        }
    }

    //ExTrigSel set
    if(hadc->Init.ExternalTrigConv != ADC_SOFTWARE_START)
    {
        /* Select external trigger to start conversion */
        hadc->Instance->CR1 &= ~(ADC_CR1_EXTSEL_Msk);
        hadc->Instance->CR1 |= hadc->Init.ExternalTrigConv << ADC_CR1_EXTSEL_Pos;

        /* Select external trigger polarity */
        hadc->Instance->CR1 &= ~(ADC_CR1_EXTEN_Msk);
        hadc->Instance->CR1 |= hadc->Init.ExternalTrigConvEdge << ADC_CR1_EXTEN_Pos;
    }
    else
    {
        /* Reset the external trigger */
        hadc->Instance->CR1 &= ~(ADC_CR1_EXTSEL_Msk);
        hadc->Instance->CR1 &= ~(ADC_CR1_EXTEN_Msk);
    }

    //Clear the sequence length.
    CLEAR_BIT(hadc->Instance->SQR1,ADC_SQR1); //Clear the sequence length.

    return  HAL_OK;
}


/******************************************************************************
* @brief : DeInit the ADC module.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef* hadc)
{
    /* Check the ADC handle allocation */
    if (hadc == NULL)
    {
        return HAL_ERROR;
    }

    HAL_ADC_MspDeInit(hadc);

    hadc->ChannelNum = 0;
    hadc->ConvCpltCallback = NULL;
    hadc->InjectedConvCpltCallback = NULL;
    hadc->LevelOutOfWindowCallback = NULL;
    memset(&hadc->Init, 0, sizeof(hadc->Init));

    return  HAL_OK;
}
    

/******************************************************************************
* @brief : Config the regular channel.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @param : sConfig : pointer to a ADC_ChannelConfTypeDef structure that contains
*                    the configuration information for ADC channel
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig)
{   
    __IO uint32_t *Reg_ADC_OFR;	

    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
    assert_param(IS_ADC_ALL_CHANNEL(sConfig->Channel));
    assert_param(IS_ADC_ALL_SEQUENCE(sConfig->Sq));

    if((sConfig->OffsetNumber != ADC_OFFSET_NONE) && (hadc->Init.OverSampMode == ADC_OVERSAMPMODE_ENABLE))
    {
        return HAL_ERROR;
    }
    /* Differential mode set*/
    if(sConfig->SingleDiff == ADC_DIFFERENTIAL_ENDED)
    {
        if(sConfig->Channel < 10)
        {
            SET_BIT(hadc->Instance->DIFF,1<<sConfig->Channel);
            CLEAR_BIT(hadc->Instance->SIGN,1<<sConfig->Channel); 
        }
        else
        {
            return HAL_ERROR;
        }
    }
    else if(sConfig->Channel < 10)
    {
        CLEAR_BIT(hadc->Instance->DIFF,1<<sConfig->Channel);
        CLEAR_BIT(hadc->Instance->SIGN,1<<sConfig->Channel);   //If define differential mode ,set as unsign resault
    }

    if((sConfig->Channel >= 10) && (hadc->Instance->DIFF & (1<<(sConfig->Channel-8))))
    {    
        return HAL_ERROR;
    }


    if((sConfig->Sq >= 1)&&(sConfig->Sq <= 5))
    {    
        MODIFY_REG(hadc->Instance->SQR1,(ADC_CH_MASK << (5*sConfig->Sq )),(sConfig->Channel << (5*sConfig->Sq )));
    }
    else if((sConfig->Sq >= 6)&&(sConfig->Sq <= 11))
    {
        MODIFY_REG(hadc->Instance->SQR2,(ADC_CH_MASK << (5*(sConfig->Sq-6))),(sConfig->Channel << (5*(sConfig->Sq-6))));
    }
    else if((sConfig->Sq >= 12)&&(sConfig->Sq <= 16))
    {
        MODIFY_REG(hadc->Instance->SQR3,(ADC_CH_MASK << (5*(sConfig->Sq-12))),(sConfig->Channel << (5*(sConfig->Sq-12))));
    }
    else
    {
        return HAL_ERROR;
    }

    MODIFY_REG(hadc->Instance->SQR1,ADC_SQR1,(hadc->ChannelNum-1));

    /* Set the SMPR to every register*/
    if(sConfig->Channel <= ADC_CHANNEL_7) 
    {
        MODIFY_REG(hadc->Instance->SMPR1,(ADC_SMPR1_SMP0_Msk << (4*sConfig->Channel )),(sConfig->Smp << (4*sConfig->Channel )));
    }
    else if((sConfig->Channel >= ADC_CHANNEL_8)&&(sConfig->Channel <= ADC_CHANNEL_15))
    {
        MODIFY_REG(hadc->Instance->SMPR2,(ADC_SMPR2_SMP8_Msk << (4*(sConfig->Channel-8))),(sConfig->Smp << (4*(sConfig->Channel-8))));
    }
    else if((sConfig->Channel >= ADC_CHANNEL_TEMP)&&(sConfig->Channel <= ADC_CHANNEL_EXT3))
    {
        MODIFY_REG(hadc->Instance->SMPR3,(ADC_SMPR3_SMP16_Msk << (4*(sConfig->Channel-16))),(sConfig->Smp << (4*(sConfig->Channel-16))));
    }
    else
    {
        return HAL_ERROR;
    }

    /*set Offset */
    if (sConfig->OffsetNumber != ADC_OFFSET_NONE)
    {
        switch(sConfig->OffsetNumber)
        {
            case ADC_OFFSET_1:
                MODIFY_REG(hadc->Instance->OFR1, 0XFFFFFFFF,  (ADC_OFR1_OFFSETXEN |(sConfig->Channel<<26)|sConfig->OffsetSign |sConfig->OffsetSaturation |sConfig->Offset));
            break;
            case ADC_OFFSET_2:
                MODIFY_REG(hadc->Instance->OFR2, 0XFFFFFFFF,  (ADC_OFR2_OFFSETXEN |(sConfig->Channel<<26)|sConfig->OffsetSign |sConfig->OffsetSaturation |sConfig->Offset));
            break;
            case ADC_OFFSET_3:
                MODIFY_REG(hadc->Instance->OFR3, 0XFFFFFFFF,  (ADC_OFR3_OFFSETXEN |(sConfig->Channel<<26)|sConfig->OffsetSign |sConfig->OffsetSaturation |sConfig->Offset));
            break;
            case ADC_OFFSET_4:
                MODIFY_REG(hadc->Instance->OFR4, 0XFFFFFFFF,  (ADC_OFR4_OFFSETXEN |(sConfig->Channel<<26)|sConfig->OffsetSign |sConfig->OffsetSaturation |sConfig->Offset));
            break;
            default:
            break;
        }	    			
    }
    else
    {
        hadc->Instance->OFR1 |= BIT31;
        hadc->Instance->OFR2 |= BIT31;
        hadc->Instance->OFR3 |= BIT31;
        hadc->Instance->OFR4 |= BIT31;
    }
    return HAL_OK;
}


/******************************************************************************
* @brief : Enable and start the ADC convertion.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    /* Enable the ADC */
    __HAL_ADC_ENABLE(hadc);

    /* Wait ADC ready */
    while(!(hadc->Instance->SR & ADC_SR_ADRDY));

    if(hadc->Init.ExternalTrigConv == ADC_SOFTWARE_START)
    {
        /* Start covertion */
        hadc->Instance->CR1 |= ADC_CR1_SWSTART;
    }

    /* Return function status */
    return HAL_OK;
}


/******************************************************************************
* @brief : Stop ADC conversion of regular group (and injected channels in 
*              case of auto_injection mode), disable ADC peripheral.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    if(hadc->Init.ConConvMode)
    {
        /* Set stop flag */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP);        
        /* Waitting stop flag be cleared */    
        while(READ_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP));
    }

    /* Disable the ADC peripheral */
    __HAL_ADC_DISABLE(hadc);

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc,ADC_SR_AWD | ADC_SR_OVERF | ADC_SR_EOG | ADC_SR_JEOC | ADC_SR_EOC | ADC_SR_ADRDY);

    /* Return function status */
    return HAL_OK;
}


/******************************************************************************
* @brief : Enable ADC, start conversion of regular group with interruption.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc)
{  
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    /* Enable the ADC */
    __HAL_ADC_ENABLE(hadc);

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc,ADC_SR_AWD | ADC_SR_OVERF | ADC_SR_EOG | ADC_SR_JEOC | ADC_SR_EOC | ADC_SR_ADRDY);      

    /* Disable all interruptions before enabling the desired ones */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IE_EOCIE | ADC_IE_EOGIE | ADC_IE_OVERFIE | ADC_IE_JEOCIE);  

    __HAL_ADC_ENABLE_IT(hadc, ADC_IE_EOCIE | ADC_IE_EOGIE);


    /* Enable ADC overrun interrupt */
    /* If hadc->Init.OverMode is set to ADC_OVERMODE_DISABLE, only then is
    ADC_IE_OVERFIE enabled; otherwise data overwrite is considered as normal
    behavior and no CPU time is lost for a non-processed interruption */
    if (hadc->Init.OverMode == ADC_OVERMODE_DISABLE)
    {
        __HAL_ADC_ENABLE_IT(hadc, ADC_IE_OVERFIE);
    }

    if(hadc->Init.ExternalTrigConv == ADC_SOFTWARE_START)	
    {
        /* Start covertion */
        SET_BIT(hadc->Instance->CR1,ADC_CR1_SWSTART);
    }

    /* Return function status */
    return HAL_OK;
}


/******************************************************************************
* @brief : Stop ADC conversion of regular group (and injected group in 
*              case of auto_injection mode), disable interrution of 
*              end-of-conversion, disable ADC peripheral.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    if(hadc->Init.ConConvMode)
    {
        /* Set stop flag */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP);        
        /* Waitting stop flag be cleared */    
        while(READ_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP));
    }

    /* Disable the ADC peripheral */
    __HAL_ADC_DISABLE(hadc);

    /* Disable all interruptions before enabling the desired ones */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IE_EOCIE | ADC_IE_EOGIE | ADC_IE_OVERFIE | ADC_IE_JEOCIE);  

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc,ADC_SR_AWD | ADC_SR_OVERF | ADC_SR_EOG | ADC_SR_JEOC | ADC_SR_EOC | ADC_SR_ADRDY);

    /* Return function status */
    return HAL_OK;
    }





/******************************************************************************
* @brief : ADC retrieve conversion value intended to be used with polling or interruption.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @return: the ADC covert result
******************************************************************************/
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef *hadc)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    return (hadc->Instance->DR);
}


/******************************************************************************
* @brief : Polling to get the results of the ADC converter.
* @param : hadc : pointer to a ADC_HandleTypeDef structure that contains
*                 the configuration information for ADC module.
* @param : pData : Destination Buffer address.
* @param : Length : Number of data to be transferred from ADC peripheral to memory.
* @param : Timeout : Polling timeout.
* @return: the ADC covert result
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_Polling(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length, uint32_t Timeout)
{
    uint32_t tmp_hal_status;
    __IO uint32_t uiTimeout;    

    if(HAL_ADC_Start(hadc) != HAL_OK)
    {    
        return HAL_ERROR; 
    }
    if(!pData)
    {  
        return HAL_ERROR;
    }
    hadc->AdcResults = pData;
    uiTimeout = Timeout;

    while(Length)
    {
        tmp_hal_status = hadc->Instance->SR;
        if(tmp_hal_status & ADC_SR_EOC)
        {
            *hadc->AdcResults = hadc->Instance->DR;   //| HAL_ADC_EOC_FLAG;
            __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_EOC);

            hadc->AdcResults++;
            Length--;
        }
        if(tmp_hal_status & ADC_SR_OVERF)
        {
            __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_OVERF);
        }        
        if(tmp_hal_status & ADC_SR_EOG)
        {
            __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_EOG);
            break;
        }

        if(uiTimeout)
        {
            uiTimeout--;
            if(uiTimeout == 0)
            {
                return HAL_TIMEOUT;
            }
        }
    }

    HAL_ADC_Stop(hadc); 

    return HAL_OK;
}


/******************************************************************************
* @brief:  Configures for the selected ADC injected channel its corresponding
*          rank in the sequencer and its sample time.
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @param:  sConfigInjected: ADC configuration structure for injected channel. 
* @return: None
******************************************************************************/
HAL_StatusTypeDef HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc, ADC_InjectionConfTypeDef* sConfigInjected)
{
    uint32_t Reg_ADC_OFR;
    if((sConfigInjected->InjectedOffsetNumber!= ADC_OFFSET_NONE) && (sConfigInjected->InjecOversamplingMode== ENABLE))
    {       
        return HAL_ERROR;
    }
    /* JDISCEN and JAUTO bits can't be set at the same time  */
    if((sConfigInjected->InjectedDiscontinuousConvMode == ENABLE) && (sConfigInjected->AutoInjectedConv == ENABLE))
    {
        return HAL_ERROR;
    }
    /*  DISCEN and JAUTO bits can't be set at the same time */
    if((hadc->Init.DiscontinuousConvMode == ENABLE) && (sConfigInjected->AutoInjectedConv == ENABLE))
    {    
        return HAL_ERROR;
    }

    ADC_Common_TypeDef *tmpADC_Common;

    /* Signel or Diff Channel COnfig */
    if(sConfigInjected->InjectedSingleDiff == ADC_DIFFERENTIAL_ENDED)
    {
        if(sConfigInjected->InjectedChannel < 10)
        {
            SET_BIT(hadc->Instance->DIFF,1<<sConfigInjected->InjectedChannel);       
            CLEAR_BIT(hadc->Instance->SIGN,1<<sConfigInjected->InjectedChannel); 
        }
        else
        {
            return HAL_ERROR;
        }
    }
    else if(sConfigInjected->InjectedChannel < 10)
    {
        CLEAR_BIT(hadc->Instance->DIFF,1<<sConfigInjected->InjectedChannel);
        CLEAR_BIT(hadc->Instance->SIGN,1<<sConfigInjected->InjectedChannel);   //If not define differential mode ,set as unsign resault
    }

    /* Set the SMPR to every register*/
    if (sConfigInjected->InjectedChannel  <= ADC_CHANNEL_7)
    {
        MODIFY_REG(hadc->Instance->SMPR1,(ADC_SMPR1_SMP0_Msk << (4*sConfigInjected->InjectedChannel )),(sConfigInjected->InjectedSamplingTime << (4*sConfigInjected->InjectedChannel )));	
    }
    else if(sConfigInjected->InjectedChannel>ADC_CHANNEL_7 || sConfigInjected->InjectedChannel<=ADC_CHANNEL_15)
    {
        MODIFY_REG(hadc->Instance->SMPR2,(ADC_SMPR2_SMP8_Msk << (4*(sConfigInjected->InjectedChannel-8))),(sConfigInjected->InjectedSamplingTime << (4*(sConfigInjected->InjectedChannel-8))));

    }
    else if(sConfigInjected->InjectedChannel>ADC_CHANNEL_TEMP || sConfigInjected->InjectedChannel<=ADC_CHANNEL_EXT3)
    {
        MODIFY_REG(hadc->Instance->SMPR3,(ADC_SMPR3_SMP16_Msk << (4*(sConfigInjected->InjectedChannel-16))),(sConfigInjected->InjectedSamplingTime<< (4*(sConfigInjected->InjectedChannel-16))));
    }
    else
    {
        return HAL_ERROR;
    }
    /*---------------------------- ADCx JSQR Configuration -----------------*/
    //JL configuration
    hadc->Instance->JSQR &= ~(ADC_JSQR_JL);
    hadc->Instance->JSQR |= (sConfigInjected->InjectedNbrOfConversion-1)<<ADC_JSQR_JL_Pos;

    // Rank configuration 
    hadc->Instance->JSQR |= sConfigInjected->InjectedChannel <<(5*sConfigInjected->InjectedRank);

    /* Enable external trigger if trigger selection is different of software  */
    /* start.                                                                 */
    /* Note: This configuration keeps the hardware feature of parameter       */
    /*       ExternalTrigConvEdge "trigger edge none" equivalent to           */
    /*       software start.                                                  */ 
    if(sConfigInjected->ExternalTrigInjecConv != ADC_SOFTWARE_START)
    {  
        /* Select external trigger to start conversion */
        hadc->Instance->JSQR &= ~(ADC_JSQR_JEXTSEL);
        hadc->Instance->JSQR |=  sConfigInjected->ExternalTrigInjecConv << ADC_JSQR_JEXTSEL_Pos;

        /* Select external trigger polarity */
        hadc->Instance->JSQR &= ~(ADC_JSQR_JEXTEN);
        hadc->Instance->JSQR |= sConfigInjected->ExternalTrigInjecConvEdge << ADC_JSQR_JEXTEN_Pos;
    }
    else
    {
        /* Reset the external trigger */
        hadc->Instance->JSQR &= ~(ADC_JSQR_JEXTSEL);
        hadc->Instance->JSQR &= ~(ADC_JSQR_JEXTEN);  
    }

    //JAUTO configuration
    if (sConfigInjected->AutoInjectedConv != DISABLE)
    {
        /* Enable the selected ADC automatic injected group conversion */
        hadc->Instance->CR1 |= ADC_CR1_JAUTO;
    }
    else
    {
        /* Disable the selected ADC automatic injected group conversion */
        hadc->Instance->CR1 &= ~(ADC_CR1_JAUTO);
    }

    //InjectedDiscontinuousConvMode
    if (sConfigInjected->InjectedDiscontinuousConvMode != DISABLE)
    {
        /* Enable the selected ADC injected discontinuous mode */
        hadc->Instance->CR1 |= ADC_CR1_JDISCEN;
    }
    else
    {
        /* Disable the selected ADC injected discontinuous mode */
        hadc->Instance->CR1 &= ~(ADC_CR1_JDISCEN);
    }

    /*set Offset */
    if (sConfigInjected->InjectedOffsetNumber != ADC_OFFSET_NONE)
    {
        switch(sConfigInjected->InjectedOffsetNumber)
        {
            case ADC_OFFSET_1:
                MODIFY_REG(hadc->Instance->OFR1, 0XFFFFFFFF,  (ADC_OFR1_OFFSETXEN|(sConfigInjected->InjectedChannel<<26) |sConfigInjected->InjectedOffsetSign |sConfigInjected->InjectedOffsetSaturation |sConfigInjected->InjectedOffset));
            break;
            case ADC_OFFSET_2:
                MODIFY_REG(hadc->Instance->OFR2, 0XFFFFFFFF,  (ADC_OFR2_OFFSETXEN |(sConfigInjected->InjectedChannel<<26) |sConfigInjected->InjectedOffsetSign |sConfigInjected->InjectedOffsetSaturation |sConfigInjected->InjectedOffset));
            break;
            case ADC_OFFSET_3:
                MODIFY_REG(hadc->Instance->OFR3, 0XFFFFFFFF,  (ADC_OFR3_OFFSETXEN |(sConfigInjected->InjectedChannel<<26) |sConfigInjected->InjectedOffsetSign |sConfigInjected->InjectedOffsetSaturation |sConfigInjected->InjectedOffset));
            break;
            case ADC_OFFSET_4:
                MODIFY_REG(hadc->Instance->OFR4, 0XFFFFFFFF,  (ADC_OFR4_OFFSETXEN |(sConfigInjected->InjectedChannel<<26) |sConfigInjected->InjectedOffsetSign |sConfigInjected->InjectedOffsetSaturation |sConfigInjected->InjectedOffset));
            break;
        }	 
    }

    //Oversampling
    if (sConfigInjected->InjecOversamplingMode == ENABLE)
    {
        MODIFY_REG(hadc->Instance->CR2,ADC_CR2_OVSR_Msk,sConfigInjected->InjecOversampling.Ratio<<ADC_CR2_OVSR_Pos);   //over sample rate
        MODIFY_REG(hadc->Instance->CR2,ADC_CR2_OVSS_Msk,sConfigInjected->InjecOversampling.RightBitShift<<ADC_CR2_OVSS_Pos);      //over sample right shift.
        SET_BIT(hadc->Instance->CR2,ADC_CR2_JOVSE); // Inject channel over sample en.		
    }
    else
    {
        CLEAR_BIT(hadc->Instance->CR2,ADC_CR2_JOVSE); // Inject channel over sample Disable.
    }

    return HAL_OK;	
}	

/******************************************************************************
* @brief:  Enables the selected ADC software start conversion of the injected channels.
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc)
{
    uint32_t tmp1 = 0U, tmp2 = 0U;

    /* Enable the ADC */
    __HAL_ADC_ENABLE(hadc);

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc,ADC_SR_AWD | ADC_SR_OVERF | ADC_SR_EOG | ADC_SR_JEOG | ADC_SR_JEOC | ADC_SR_EOC | ADC_SR_ADRDY);

    /* Wait ADC ready */
    while(!(hadc->Instance->SR & ADC_SR_ADRDY));

    tmp1 = HAL_IS_BIT_CLR(hadc->Instance->JSQR, ADC_JSQR_JEXTEN);
    tmp2 = HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO);
    if(tmp1 && tmp2)
    {
        /* Start covertion */
        SET_BIT(hadc->Instance->CR1,ADC_CR1_JSWSTART);
    }

    return HAL_OK;
}


/******************************************************************************
* @brief:  Stop ADC conversion of regular group (and injected channels in 
*              case of auto_injection mode), disable ADC peripheral.
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_InjectedStop(ADC_HandleTypeDef* hadc)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    if(hadc->Init.ConConvMode)
    {
        /* Set stop flag */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP);        
        /* Waitting stop flag be cleared */    
        while(READ_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP));
    }

    /* Disable the ADC peripheral */
    __HAL_ADC_DISABLE(hadc);

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc,ADC_SR_AWD | ADC_SR_OVERF | ADC_SR_EOG | ADC_SR_JEOG | ADC_SR_JEOC | ADC_SR_EOC | ADC_SR_ADRDY);

    /* Return function status */
    return HAL_OK;
}


/******************************************************************************
* @brief:  Enable ADC, start conversion of injected channel with interruption.
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_InjectedStart_IT(ADC_HandleTypeDef* hadc)
{  
    uint32_t tmp1 = 0U, tmp2 = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    /* Enable the ADC */
    __HAL_ADC_ENABLE(hadc);

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_JEOC |  ADC_SR_JEOG );      

    __HAL_ADC_ENABLE_IT(hadc, ADC_IE_JEOCIE | ADC_IE_JEOGIE );    

    tmp1 = HAL_IS_BIT_CLR(hadc->Instance->JSQR, ADC_JSQR_JEXTEN);
    tmp2 = HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO);
    if(tmp1 && tmp2)
    {
        /* Enable the selected ADC software conversion for injected group */
        hadc->Instance->CR1 |= ADC_CR1_JSWSTART;
    }	

    /* Return function status */
    return HAL_OK;
}

/******************************************************************************
* @brief:  Stop ADC conversion of regular group (and injected group in 
*              case of auto_injection mode), disable interrution of 
*              end-of-conversion, disable ADC peripheral.
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_InjectedStop_IT(ADC_HandleTypeDef* hadc)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    if(hadc->Init.ConConvMode)
    {
        /* Set stop flag */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP);        
        /* Waitting stop flag be cleared */    
        while(READ_BIT(hadc->Instance->CR2, ADC_CR2_ADCSTP));
    }

    /* Disable the ADC peripheral */
    __HAL_ADC_DISABLE(hadc);

    /* Disable all interruptions before enabling the desired ones */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IE_EOCIE | ADC_IE_EOGIE | ADC_IE_OVERFIE | ADC_IE_JEOCIE);  

    /* Clear the SR register */
    __HAL_ADC_CLEAR_FLAG(hadc,ADC_SR_AWD | ADC_SR_OVERF | ADC_SR_EOG | ADC_SR_JEOC | ADC_SR_EOC | ADC_SR_ADRDY);

    /* Return function status */
    return HAL_OK;
}

/******************************************************************************
* @brief:  Gets the converted value from data register of injected channel.
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @param:  InjectedRank: the ADC injected rank.
*          This parameter can be one of the following values:
*            @arg ADC_INJECTED_RANK_1: Injected Channel1 selected
*            @arg ADC_INJECTED_RANK_2: Injected Channel2 selected
*            @arg ADC_INJECTED_RANK_3: Injected Channel3 selected
*            @arg ADC_INJECTED_RANK_4: Injected Channel4 selected
* @return: the ADC covert result
******************************************************************************/
uint32_t HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank)
{
    __IO uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

    /* Clear injected group conversion flag to have similar behaviour as        */
    /* regular group: reading data register also clears end of conversion flag. */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_JEOC);

    /* Return the selected ADC converted value */ 
    switch(InjectedRank)
    {  
        case ADC_INJECTED_RANK_4:
        {
            tmp =  hadc->Instance->JDR4;
        }  
        break;
        case ADC_INJECTED_RANK_3: 
        {  
            tmp =  hadc->Instance->JDR3;
        }  
        break;
        case ADC_INJECTED_RANK_2: 
        {  
            tmp =  hadc->Instance->JDR2;
        }
        break;
        case ADC_INJECTED_RANK_1:
        {
            tmp =  hadc->Instance->JDR1;
        }
        break;
        default:
        break;  
    }
    return tmp;
}

/******************************************************************************
* @brief:  Poll for injected conversion complete
* @param:  hadc: pointer to a ADC_HandleTypeDef structure that contains
*          the configuration information for the specified ADC.
* @param:  Timeout: Timeout value in millisecond.  
* @return: HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef HAL_ADC_InjectedPolling(ADC_HandleTypeDef* hadc, uint32_t InjectedRank, uint32_t* pData, uint32_t Length, uint32_t Timeout)
{
    uint32_t tmp_hal_status;
    __IO uint32_t uiTimeout;    

    if(HAL_ADC_Start(hadc) != HAL_OK)  return HAL_ERROR; 
    if(!pData)  return HAL_ERROR;

    hadc->AdcResults = pData;
    uiTimeout = Timeout;

    while(Length)
    {
        tmp_hal_status = hadc->Instance->SR;
        if(tmp_hal_status & ADC_SR_JEOC)
        {
            HAL_ADCEx_InjectedGetValue(hadc,InjectedRank);
            hadc->AdcResults++;
            Length--;
        }

        if(tmp_hal_status & ADC_SR_OVERF)
        {
            __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_OVERF);
        }        
        if(tmp_hal_status & ADC_SR_JEOG)
        {
            __HAL_ADC_CLEAR_FLAG(hadc, ADC_SR_JEOG);
            break;
        }

        if(uiTimeout)
        {
            uiTimeout--;
            if(uiTimeout == 0)
            {
                return HAL_TIMEOUT;
            }
        }
    }

    return HAL_OK;
}










#endif



