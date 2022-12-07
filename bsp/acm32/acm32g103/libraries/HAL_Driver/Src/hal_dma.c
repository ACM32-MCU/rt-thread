
/******************************************************************************
*@file  : hal_dma.c
*@brief : DMA HAL module driver.
******************************************************************************/

#include "hal.h" 

#ifdef HAL_DMA_MODULE_ENABLED

/******************************************************************************
*@brief : This function handles DMA interrupt request.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for DMA module.
*@return: None
******************************************************************************/
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma)
{
    uint32_t ChannelIndex;
    DMA_TypeDef *DMABaseAddr;
    
    /* calculate DMA base and stream number */
	if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel0))
	{
		ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA1_Channel0)) >> 5U;
        DMABaseAddr = DMA1;
	}
	else
	{
		ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA2_Channel0)) >> 5U;
        DMABaseAddr = DMA2;
	}

    /* Channel has been interrupted */
    if (DMABaseAddr->INTSTATUS & (1U << ChannelIndex))
    {
		/* Transfer half interrupt */
		if(DMABaseAddr->INTTCSTATUS & (1U << (ChannelIndex + 8U)))
		{
			if (NULL != hdma->XferHalfCpltCallback)
            {
                hdma->XferHalfCpltCallback(hdma);
            }
			DMABaseAddr->INTTCCLR = (1U << (ChannelIndex + 8U));
		}
        /* Transfer complete interrupt */
        else if (DMABaseAddr->INTTCSTATUS & (1U << ChannelIndex))
        {
            if (NULL != hdma->XferCpltCallback)
            {
                hdma->XferCpltCallback(hdma);
            }
            DMABaseAddr->INTTCCLR = (1U << ChannelIndex);
        }
        
        /* Transfer error interrupt */
        if (DMABaseAddr->INTERRSTATUS & (1 << ChannelIndex))
        {
            if (NULL != hdma->XferErrorCallback)
            {
                hdma->XferErrorCallback(hdma);
            }
            DMABaseAddr->INTERRCLR = (1 << ChannelIndex);
        }
    }
}

/******************************************************************************
*@brief : Initialize the DMA according to the specified.
*         parameters in the DMA_InitTypeDef and create the associated handle.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma) 
{
	uint32_t RequestID;
	
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	assert_param(IS_DMA_MODE(hdma->Init.Mode));
	assert_param(IS_DMA_DATAFLOW(hdma->Init.DataFlow));
	assert_param(IS_DMA_SRCINC(hdma->Init.SrcInc));
	assert_param(IS_DMA_DESTINC(hdma->Init.DestInc));
	assert_param(IS_DMA_SRCWIDTH(hdma->Init.SrcWidth));
	assert_param(IS_DMA_DESTWIDTH(hdma->Init.DestWidth));
	assert_param(IS_DMA_SRCBURST(hdma->Init.SrcBurst));
	assert_param(IS_DMA_DESTBURST(hdma->Init.DestBurst));

	/* Check the DMA peripheral handle */
	if(hdma == NULL)
		return HAL_ERROR;
    
    /* calculation of the channel index */
	if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel0))
	{
        /* Check the parameters */
        assert_param(IS_DMA_REQ1ID(hdma->Init.Mode, hdma->Init.ReqID));
        
	    /* DMA1 */
		hdma->ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA1_Channel0)) >> 5;
		hdma->DmaBaseAddress = DMA1;
	}
	else
	{
        /* Check the parameters */
        assert_param(IS_DMA_REQ2ID(hdma->Init.Mode, hdma->Init.ReqID));
        
	    /* DMA2 */
		hdma->ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA2_Channel0)) >> 5;
		hdma->DmaBaseAddress = DMA2;
	}
	
    /* Enable DMA */
    hdma->DmaBaseAddress->CONFIG |= DMA_CONFIG_EN;
	
	hdma->DmaBaseAddress->SYNCLO |= 0xFFFFFFFF;
	hdma->DmaBaseAddress->SYNCHI |= 0xFFFFFFFF;

    /* Clear Channel Config */
    hdma->Instance->CHCONFIG = 0; 
    
    if (hdma->Init.DataFlow == DMA_DATAFLOW_M2P) 
    {
        RequestID = hdma->Init.ReqID << DMA_CHCONFIG_DESTPERIPH_Pos;
    }
    else if (hdma->Init.DataFlow == DMA_DATAFLOW_P2M) 
    {
        RequestID = hdma->Init.ReqID << DMA_CHCONFIG_SRCPERIPH_Pos;
    }
	else
	{
		RequestID = 0;
	}

    hdma->Instance->CHCONFIG = hdma->Init.DataFlow | RequestID;
    
    /* Config Channel Control */
    hdma->Instance->CHCTRL = DMA_CHCTRL_ITC;
	
    /* Source or Desination address increase */
    hdma->Instance->CHCTRL |= (hdma->Init.DestInc | hdma->Init.SrcInc);
	
    /* Source or Desination date width */
    hdma->Instance->CHCTRL |= (hdma->Init.DestWidth | hdma->Init.SrcWidth);

    /* Source or Desination burst size */
    hdma->Instance->CHCTRL |= hdma->Init.SrcBurst | hdma->Init.DestBurst;
    
    return HAL_OK;
}

/******************************************************************************
*@brief : DeInitializes the DMA peripheral.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma)
{
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	
	/* Check the DMA peripheral handle */
	if(hdma == NULL)
		return HAL_ERROR;
    
	hdma->Instance->CHCONFIG    = 0U;
	hdma->Instance->CHCTRL		= 0U;
	hdma->Instance->CHSRCADDR	= 0U;
	hdma->Instance->CHDESTADDR	= 0U;
	hdma->Instance->CHLLI       = 0U;
	
    hdma->XferCpltCallback		= NULL;
    hdma->XferHalfCpltCallback	= NULL;
	hdma->XferErrorCallback		= NULL;
	
	hdma->DmaBaseAddress		= 0U;
	hdma->ChannelIndex			= 0U;

    return HAL_OK;
}

/******************************************************************************
*@brief : Register callbacks.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@param : CallbackID: User Callback identifier
*                     This parameter can be a combination of @ref DMA_XfeCallbackID.
*                     @arg DMA_XFER_CPLT_CB_ID: Transfer completion interrupt callback function.
*                     @arg DMA_XFER_HALFCPLT_CB_ID: Half transfer completion interrupt callback function.
*                     @arg DMA_XFER_ERROR_CB_ID: Error interrupt callback function.
*@param : pCallback: callback function.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, uint32_t CallbackID, \
                                     void (* pCallback)(struct __DMA_HandleTypeDef * hdma))
{
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	assert_param(IS_DMA_CALLBACK_ID(CallbackID));
	
	/* Check the DMA peripheral handle */
	if(hdma == NULL)
		return HAL_ERROR;

	switch (CallbackID)
	{
		case  DMA_XFER_CPLT_CB_ID:
			
			hdma->XferCpltCallback = pCallback;
			break;

		case  DMA_XFER_HALFCPLT_CB_ID:
			
			hdma->XferHalfCpltCallback = pCallback;
			break;

		case  DMA_XFER_ERROR_CB_ID:
			
			hdma->XferErrorCallback = pCallback;
			break;

		default:
			return HAL_ERROR;
	}
	
	return HAL_OK;
}

/******************************************************************************
*@brief : UnRegister callbacks.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@param : CallbackID: User Callback identifier
*                     This parameter can be a combination of @ref DMA_XfeCallbackID.
*                     @arg DMA_XFER_CPLT_CB_ID: Transfer completion interrupt callback function.
*                     @arg DMA_XFER_HALFCPLT_CB_ID: Half transfer completion interrupt callback function.
*                     @arg DMA_XFER_ERROR_CB_ID: Error interrupt callback function.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, uint32_t CallbackID)
{
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	assert_param(IS_DMA_CALLBACK_ID(CallbackID));
	
	/* Check the DMA peripheral handle */
	if(hdma == NULL)
		return HAL_ERROR;

	switch (CallbackID)
	{
		case  DMA_XFER_CPLT_CB_ID:
			
			hdma->XferCpltCallback = NULL;
			break;

		case  DMA_XFER_HALFCPLT_CB_ID:
			
			hdma->XferHalfCpltCallback = NULL;
			break;

		case  DMA_XFER_ERROR_CB_ID:
			
			hdma->XferErrorCallback = NULL;
			break;

		default:
			return HAL_ERROR;
	}
	
	return HAL_OK;
}

/******************************************************************************
*@brief : Starts the DMA Transfer.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@param : SrcAddr: The source memory Buffer address.
*@param : DestAddr: The destination memory Buffer address.
*@param : Size: The length of data to be transferred from source to destination.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddr, uint32_t DestAddr, uint32_t Size)
{
	uint32_t temp;
	
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	assert_param(IS_DMA_MODE(hdma->Init.Mode));
	assert_param(IS_DMA_SRCADDR(SrcAddr));
	assert_param(IS_DMA_DESTADDR(DestAddr));
	assert_param(IS_DMA_SIZE(Size));
	
	/* Check the DMA peripheral handle */
	if(hdma == NULL)
		return HAL_ERROR;
    
    if ((Size == 0) || (Size > DMA_TRANSFER_SIZE))
        return HAL_ERROR;

    /* DMA Channel Disable */
    hdma->Instance->CHCONFIG &= ~DMA_CHCONFIG_EN;
	
    /* Set source address and desination address */
    hdma->Instance->CHSRCADDR  = SrcAddr;
    hdma->Instance->CHDESTADDR = DestAddr;
	
    /* Set Transfer Size */
	temp = hdma->Instance->CHCTRL;
	temp &= ~DMA_TRANSFER_SIZE;
	temp |= Size;
    hdma->Instance->CHCTRL = temp;
    
    /* Set Next Link */
    if (hdma->Init.Mode == DMA_MODE_NORMAL)
    {
        hdma->Instance->CHLLI = 0;
    }
    else if (hdma->Init.Mode == DMA_MODE_CIRCULAR)
    {
        hdma->Link.SrcAddr = hdma->Instance->CHSRCADDR;
        hdma->Link.DestAddr = hdma->Instance->CHDESTADDR;
        hdma->Link.Next = &hdma->Link;
        hdma->Link.Ctrl = (hdma->Instance->CHCTRL & ~DMA_TRANSFER_SIZE) | Size;
        
        hdma->Instance->CHLLI = (uint32_t)(&hdma->Link);
    }
    
    /* DMA Channel Enable */
    hdma->Instance->CHCONFIG |= DMA_CHCONFIG_EN;

    return HAL_OK;
}

/******************************************************************************
*@brief : Start the DMA Transfer with interrupt enabled.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@param : SrcAddr: The source memory Buffer address.
*@param : DestAddr: The destination memory Buffer address.
*@param : Size: The length of data to be transferred from source to destination.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddr, \
									uint32_t DestAddr, uint32_t Size)
{
	uint32_t temp;
	
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	assert_param(IS_DMA_MODE(hdma->Init.Mode));
	assert_param(IS_DMA_SRCADDR(SrcAddr));
	assert_param(IS_DMA_DESTADDR(DestAddr));
	assert_param(IS_DMA_SIZE(Size));
    
    /* DMA Channel Disable */
    hdma->Instance->CHCONFIG &= ~DMA_CHCONFIG_EN;
	
    /* Set source address and desination address */
    hdma->Instance->CHSRCADDR  = SrcAddr;
    hdma->Instance->CHDESTADDR = DestAddr;
	
    /* Set Next Link */
    hdma->Instance->CHLLI = NULL;

    /* Set Transfer Size and enable LLI interrupt */
	temp = hdma->Instance->CHCTRL;
	temp &= ~DMA_TRANSFER_SIZE;
	temp |= Size;
    hdma->Instance->CHCTRL = temp;

	hdma->Instance->CHCONFIG &= ~DMA_CHCONFIG_IHFTC;
	hdma->Instance->CHCONFIG |= DMA_CHCONFIG_ITC | DMA_CHCONFIG_IE;	
	
    if(NULL != hdma->XferHalfCpltCallback)
	{
		hdma->Instance->CHCONFIG |= DMA_CHCONFIG_IHFTC;	
	}

    /* Set Next Link */
    if (hdma->Init.Mode == DMA_MODE_NORMAL)
    {
        hdma->Instance->CHLLI = 0;
    }
    else if (hdma->Init.Mode == DMA_MODE_CIRCULAR)
    {
        hdma->Link.SrcAddr = hdma->Instance->CHSRCADDR;
        hdma->Link.DestAddr = hdma->Instance->CHDESTADDR;
        hdma->Link.Next = &hdma->Link;
        hdma->Link.Ctrl = (hdma->Instance->CHCTRL & ~DMA_TRANSFER_SIZE) | Size;
        
        hdma->Instance->CHLLI = (uint32_t)(&hdma->Link);
    }
    
    /* DMA Channel Enable */
    hdma->Instance->CHCONFIG |= DMA_CHCONFIG_EN;
	
    return HAL_OK;
}

/******************************************************************************
*@brief : Initialize linked list.
*@param : Link: Initialize linked list node.
*@param : Link_Init: pointer to an DMA_LinkInitTypeDef structure that contains 
*                    the configuration information for the specified Link.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_InitLink(DMA_LinkTypeDef *Link, DMA_LinkInitTypeDef *Link_Init)
{
    /* Check the parameters */
	assert_param(IS_DMA_SRCADDR(Link_Init->SrcAddr));
	assert_param(IS_DMA_DESTADDR(Link_Init->DestAddr));
	assert_param(IS_DMA_RAWIT(Link_Init->RawInt));
	assert_param(IS_DMA_SRCINC(Link_Init->SrcInc));
	assert_param(IS_DMA_DESTINC(Link_Init->DestInc));
	assert_param(IS_DMA_SRCWIDTH(Link_Init->SrcWidth));
	assert_param(IS_DMA_DESTWIDTH(Link_Init->DestWidth));
	assert_param(IS_DMA_SRCBURST(Link_Init->SrcBurst));
	assert_param(IS_DMA_DESTBURST(Link_Init->DestBurst));
	assert_param(IS_DMA_SIZE(Link_Init->Size));

	
	if ((Link == NULL) || (Link_Init == NULL))
        return HAL_ERROR;
    
	Link->SrcAddr = Link_Init->SrcAddr;
	Link->DestAddr = Link_Init->DestAddr;
	Link->Next = Link_Init->Next;
	Link->Ctrl = Link_Init->RawInt | Link_Init->SrcInc | Link_Init->DestInc | \
                 Link_Init->SrcWidth | Link_Init->DestWidth | Link_Init->SrcBurst | \
                 Link_Init->DestBurst | Link_Init->Size ;

    return HAL_OK;
}

/******************************************************************************
*@brief : Set the next node of the linked node.
*@param : Curr: current linked node.
*@param : Next: next linked node.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_SetLinkNext(DMA_LinkTypeDef *Curr, DMA_LinkTypeDef *Next)
{
	uint32_t temp;
	
	if (Curr == NULL)
        return HAL_ERROR;
	
    Curr->Next = Next;

    return HAL_OK;
}

/******************************************************************************
*@brief : DMA link transfer start.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@param : Link: First node of linked list.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_Start_Link(DMA_HandleTypeDef *hdma, DMA_LinkTypeDef *Link)
{
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

    if (Link == 0)
        return HAL_ERROR;
    
    /* DMA Channel Disable */
    hdma->Instance->CHCONFIG &= ~DMA_CHCONFIG_EN;
	
    /* Set source address and desination address */
    hdma->Instance->CHSRCADDR  = Link->SrcAddr;
    hdma->Instance->CHDESTADDR = Link->DestAddr;

    /* Set Next Link */
    hdma->Instance->CHLLI = (uint32_t)Link->Next;

    /* Set Transfer Size */
    hdma->Instance->CHCTRL = Link->Ctrl;

    /* DMA Channel Enable */
    hdma->Instance->CHCONFIG |= DMA_CHCONFIG_EN;

    return HAL_OK;
}

/******************************************************************************
*@brief : Abort the DMA Transfer .
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@return: HAL status
******************************************************************************/
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma)
{
    uint32_t ChannelIndex;

    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

    /* calculation of the channel index */
	if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel0))
	{
		ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA1_Channel0)) >> 5U;
	}
	else
	{
		ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA2_Channel0)) >> 5U;
	}

    /* DMA Channel Disable */
    hdma->Instance->CHCONFIG &= ~(1U << 0);
    
    /* Clear TC ERR Falg */
    hdma->DmaBaseAddress->INTTCCLR  |= (1U << ChannelIndex) | (1U << (ChannelIndex + 8U));
    hdma->DmaBaseAddress->INTERRCLR |= (1U << ChannelIndex);

    return HAL_OK;
}

/******************************************************************************
*@brief : Returns the DMA state.
*@param : hdma: pointer to a DMA_HandleTypeDef structure that contains
*               the configuration information for the specified DMA Channel.
*@param : Flag: DMA flag
*               This parameter can be a combination of @ref DMA_Flag.
*               @arg DMA_FLAG_IT: indicating transmission completion interrupt or error interrupt occur.
*               @arg DMA_FLAG_TC: indicating transmission completion interrupt occur.
*               @arg DMA_FLAG_HTC: indicating half transmission completion interrupt occur.
*               @arg DMA_FLAG_ERR: indicating error interrupt occur.
*               @arg DMA_FLAG_RTC: indicating raw transmission completion interrupt occur.
*               @arg DMA_FLAG_RHTC: indicating raw half transmission completion interrupt occur.
*               @arg DMA_FLAG_RERR: indicating raw error interrupt occur.
*@return: DMA status
******************************************************************************/
FlagStatus HAL_DMA_GetState(DMA_HandleTypeDef *hdma, uint32_t Flag)
{
    uint32_t ChannelIndex;
    uint32_t Status;
    
    /* Check the parameters */
	assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
	assert_param(IS_DMA_FLAGS(Flag));

    /* calculation of the channel index */
	if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel0))
	{
		ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA1_Channel0)) >> 5;
	}
	else
	{
		ChannelIndex = ((uint32_t)(hdma->Instance) - (uint32_t)(DMA2_Channel0)) >> 5;
	}
	
	if (Flag == DMA_FLAG_IT)
	{
		Status = hdma->DmaBaseAddress->INTSTATUS & (1U << ChannelIndex);
	}
	else if (Flag == DMA_FLAG_TC)
	{
		Status = hdma->DmaBaseAddress->INTTCSTATUS & (1U << ChannelIndex);
	}
	else if (Flag == DMA_FLAG_HTC)
	{
		Status = hdma->DmaBaseAddress->INTTCSTATUS & (1U << (ChannelIndex + 8U));
	}
	else if (Flag == DMA_FLAG_ERR)
	{
		Status = hdma->DmaBaseAddress->INTERRSTATUS & (1U << (ChannelIndex + 8U));
	}
	else if (Flag == DMA_FLAG_RTC)
	{
		Status = hdma->DmaBaseAddress->RAWINTTCSTATUS & (1U << ChannelIndex);
	}
	else if (Flag == DMA_FLAG_RHTC)
	{
		Status = hdma->DmaBaseAddress->RAWINTTCSTATUS & (1U << (ChannelIndex + 8U));
	}
	else if (Flag == DMA_FLAG_RERR)
	{
		Status = hdma->DmaBaseAddress->RAWINTERRSTATUS & (1U << (ChannelIndex + 8U));
	}
	
	if (Status)
		return (SET);
	else
		return (RESET);
}

#endif /* HAL_DMA_MODULE_ENABLED */

/************************ (C) COPYRIGHT AISINOCHIP *****END OF FILE****/

