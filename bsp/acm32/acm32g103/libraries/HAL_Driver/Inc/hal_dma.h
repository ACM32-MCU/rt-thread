
/******************************************************************************
*@file  : hal_dma.h
*@brief : Header file of DMA HAL module.
******************************************************************************/

#ifndef __HAL_DMA_H__
#define __HAL_DMA_H__

#include "hal.h"


/**
  * @brief  DMA Configuration Structure definition
  */
  
typedef struct 
{
    uint32_t Mode;              /*!< Specifies the operation mode of the DMA.
                                     This parameter can be a value of @ref DMA_Mode
                                     @note The circular buffer mode cannot be used if the memory-to-memory
                                           data transfer is configured on the selected channel                          */

    uint32_t DataFlow;          /*!< Specifies if the data will be transferred from memory to peripheral,
                                     from memory to memory or from peripheral to memory.
                                     This parameter can be a value of @ref DMA_DataFlow                                 */

    uint32_t ReqID;             /*!< The request number of the source peripheral and the destination peripheral. 
                                     This value is invalid when the memory to memory data transfer is configured 
                                     on the selected channel. 
                                     This parameter can be a value of @ref DMA1_ReqID or DMA2_ReqID                     */
    
    uint32_t SrcInc;            /*!< Specifies whether the source address register should be incremented or not.
                                     This parameter can be a value of @ref DMA_SrcInc                                   */

    uint32_t DestInc;           /*!< Specifies whether the destination address register should be incremented or not.
                                     This parameter can be a value of @ref DMA_DestInc                                  */
    
    uint32_t SrcWidth;          /*!< Specifies whether the source data width.
                                     This parameter can be a value of @ref DMA_SrcWidth                                 */

    uint32_t DestWidth;         /*!< Specifies whether the destination data width.
                                     This parameter can be a value of @ref DMA_DestWidth                                */

    uint32_t SrcBurst;          /*!< Specifies the Burst transfer configuration for the source transfers.
                                     It specifies the amount of data to be transferred in a single non interruptible
                                     transaction. This parameter can be a value of @ref DMA_SrcBurst.                   */
                                     
    uint32_t DestBurst;         /*!< Specifies the Burst transfer configuration for the destination transfers.
                                     It specifies the amount of data to be transferred in a single non interruptible
                                     transaction. This parameter can be a value of @ref DMA_DestBurst.                  */
    
}DMA_InitTypeDef;

/**
  * @brief  DMA Link List Item Structure
  */

typedef struct __DMA_NextLink
{
    uint32_t				SrcAddr;    /*!< source address                 */

    uint32_t				DestAddr;   /*!< desination address             */
    
    struct __DMA_NextLink   *Next;      /*!< Next Node pointer              */

    uint32_t                Ctrl;       /*!< Ctrol                          */

}DMA_LinkTypeDef;

/**
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
    DMA_Channel_TypeDef *Instance;                                                      /*!< Register base address              */

    DMA_InitTypeDef     Init;                                                           /*!< DMA communication parameters       */

	void                *Parent;                                                        /*!< Parent object state                */
	
    void                (*XferCpltCallback)(struct __DMA_HandleTypeDef * hdma);         /*!< DMA transfer complete callback     */
    
    void                (*XferHalfCpltCallback)(struct __DMA_HandleTypeDef * hdma);     /* DMA transfer half complete callback  */
    
    void                (*XferErrorCallback)(struct __DMA_HandleTypeDef * hdma);        /* DMA error complete callback          */
    
    DMA_TypeDef         *DmaBaseAddress;                                                /*!< DMA channel Base Address           */
    
    uint32_t            ChannelIndex;                                                   /*!< DMA channel index                  */ 
                                     
    DMA_LinkTypeDef     Link;                                                           /*!< DMA Link                           */ 
    
}DMA_HandleTypeDef;

/**
  * @brief  DMA Link Init Structure
  */

typedef struct __DMA_LinkInitTypeDef
{
    uint32_t SrcAddr;           /* source address                                                                       */

    uint32_t DestAddr;          /* desination address                                                                   */

    uint32_t Size;              /* The length of data to be transferred from source to destination.                     */
    
    DMA_LinkTypeDef *Next;      /* Next Node pointer                                                                    */

    uint32_t RawInt ;           /*!< Raw interrupt enable.
                                     This parameter can be a value of @ref DMA_RawInt                                   */

    uint32_t SrcInc;            /*!< Specifies whether the source address register should be incremented or not.
                                     This parameter can be a value of @ref DMA_SrcInc                                   */

    uint32_t DestInc;           /*!< Specifies whether the destination address register should be incremented or not.
                                     This parameter can be a value of @ref DMA_DestInc                                  */
    
    uint32_t SrcWidth;          /*!< Specifies whether the source data width.
                                     This parameter can be a value of @ref DMA_SrcWidth                                 */

    uint32_t DestWidth;         /*!< Specifies whether the destination data width.
                                     This parameter can be a value of @ref DMA_DestWidth                                */

    uint32_t SrcBurst;          /*!< Specifies the Burst transfer configuration for the source transfers.
                                     It specifies the amount of data to be transferred in a single non interruptible
                                     transaction. This parameter can be a value of @ref DMA_SrcBurst.                   */
                                     
    uint32_t DestBurst;         /*!< Specifies the Burst transfer configuration for the destination transfers.
                                     It specifies the amount of data to be transferred in a single non interruptible
                                     transaction. This parameter can be a value of @ref DMA_DestBurst.                  */
                                     
}DMA_LinkInitTypeDef;



/**
  * @brief  DMA transfer max number
  */

#define DMA_TRANSFER_SIZE   (0xFFFF)


/** @defgroup DMA_DataFlow
 *  @{
 */
 
#define    DMA_DATAFLOW_M2M                     ( 0U )
#define    DMA_DATAFLOW_M2P                     ( DMA_CHCONFIG_FLOWCTRL_0 )
#define    DMA_DATAFLOW_P2M                     ( DMA_CHCONFIG_FLOWCTRL_1 )

/**
  * @}
  */


/** @defgroup DMA1_ReqID
 *  @{
 */
 
#define    DMA1_REG_M2M                         ( 0U )
#define    DMA1_REQ0_ADC1                       ( 0U )
#define    DMA1_REQ1_SPI1_SEND                  ( 1U )
#define    DMA1_REQ2_SPI1_RECV                  ( 2U )
#define    DMA1_REQ3_SPI2_SEND                  ( 3U )
#define    DMA1_REQ4_SPI2_RECV                  ( 4U )
#define    DMA1_REQ5_UART1_SEND                 ( 5U )
#define    DMA1_REQ6_UART1_RECV                 ( 6U )
#define    DMA1_REQ7_UART2_SEND                 ( 7U )
#define    DMA1_REQ8_UART2_RECV                 ( 8U )
#define    DMA1_REQ9_I2C1_SEND                  ( 9U )
#define    DMA1_REQ10_I2C1_RECV                 ( 10U )
#define    DMA1_REQ11_I2C2_SEND                 ( 11U )
#define    DMA1_REQ12_I2C2_RECV                 ( 12U )
#define    DMA1_REQ13_TIM1_CH1                  ( 13U )
#define    DMA1_REQ14_TIM1_CH2                  ( 14U )
#define    DMA1_REQ15_TIM1_CH3                  ( 15U )
#define    DMA1_REQ16_TIM1_CH4                  ( 16U )
#define    DMA1_REQ17_TIM1_UP                   ( 17U )
#define    DMA1_REQ18_TIM1_TRIG                 ( 18U )
#define    DMA1_REQ19_TIM1_COM                  ( 19U )
#define    DMA1_REQ20_TIM2_CH1                  ( 20U )
#define    DMA1_REQ21_TIM2_CH2                  ( 21U )
#define    DMA1_REQ22_TIM2_CH3                  ( 22U )
#define    DMA1_REQ23_TIM2_CH4                  ( 23U )
#define    DMA1_REQ24_TIM2_UP                   ( 24U )
#define    DMA1_REQ25_TIM2_TRIG                 ( 25U )
#define    DMA1_REQ26_ADC2                      ( 26U )
#define    DMA1_REQ27_ADC3                      ( 27U )
#define    DMA1_REQ28_UART3_SEND                ( 28U )
#define    DMA1_REQ29_UART3_RECV                ( 29U )
#define    DMA1_REQ30_LPUART_SEND               ( 30U )
#define    DMA1_REQ31_LPUART_RECV               ( 31U )
#define    DMA1_REQ32_TIM15_CH1                 ( 32U )
#define    DMA1_REQ33_TIM15_CH2                 ( 33U )
#define    DMA1_REQ34_TIM15_UP                  ( 34U )
#define    DMA1_REQ35_TIM15_TRIG                ( 35U )
#define    DMA1_REQ36_TIM15_COM                 ( 36U )
#define    DMA1_REQ37_I2S1_TX                   ( 37U )
#define    DMA1_REQ38_I2S1_RX                   ( 38U )
#define    DMA1_REQ39_DAC1_CH1                  ( 39U )
#define    DMA1_REQ40_DAC1_CH2                  ( 40U )
#define    DMA1_REQ41_I2S2_TX                   ( 41U )
#define    DMA1_REQ42_I2S2_RX                   ( 42U )
#define    DMA1_REQ43_AES_IN                    ( 43U )
#define    DMA1_REQ44_AES_OUT                   ( 44U )
#define    DMA1_REQ45_UART4_SEND                ( 45U )
#define    DMA1_REQ46_UART4_RECV                ( 46U )
#define    DMA1_REQ47_SPI3_SEND                 ( 47U )
#define    DMA1_REQ48_SPI3_RECV                 ( 48U )
#define    DMA1_REQ49_TIM4_CH1                  ( 49U )
#define    DMA1_REQ50_TIM4_CH2                  ( 50U )
#define    DMA1_REQ51_TIM4_CH3                  ( 51U )
#define    DMA1_REQ52_TIM4_CH4                  ( 52U )
#define    DMA1_REQ53_TIM4_UP                   ( 53U )
#define    DMA1_REQ54_TIM4_TRIG                 ( 54U )

/**
  * @}
  */
  
/**
  * @brief  DMA1 requeset number max value
  */

#define    DMA1_REQID_MAXLIMIT                  ( 55U )

/** @defgroup DMA2_ReqID
 *  @{
 */
 
#define    DMA2_REG_M2M                         ( 0U )
#define    DMA2_REQ0_ADC1                       ( 0U )
#define    DMA2_REQ1_SPI1_SEND                  ( 1U)
#define    DMA2_REQ2_SPI1_RECV                  ( 2U )
#define    DMA2_REQ3_SPI2_SEND                  ( 3U )
#define    DMA2_REQ4_SPI2_RECV                  ( 4U )
#define    DMA2_REQ5_UART1_SEND                 ( 5U )
#define    DMA2_REQ6_UART1_RECV                 ( 6U )
#define    DMA2_REQ7_UART2_SEND                 ( 7U )
#define    DMA2_REQ8_UART2_RECV                 ( 8U )
#define    DMA2_REQ9_I2C1_SEND                  ( 9U )
#define    DMA2_REQ10_I2C1_RECV                 ( 10U )
#define    DMA2_REQ11_I2C2_SEND                 ( 11U )
#define    DMA2_REQ12_I2C2_RECV                 ( 12U )
#define    DMA2_REQ13_TIM8_CH1                  ( 13U )
#define    DMA2_REQ14_TIM8_CH2                  ( 14U )
#define    DMA2_REQ15_TIM8_CH3                  ( 15U )
#define    DMA2_REQ16_TIM8_CH4                  ( 16U )
#define    DMA2_REQ17_TIM8_UP                   ( 17U )
#define    DMA2_REQ18_TIM8_TRIG                 ( 18U )
#define    DMA2_REQ19_TIM8_COM                  ( 19U )
#define    DMA2_REQ20_TIM3_CH1                  ( 20U )
#define    DMA2_REQ21_TIM3_CH2                  ( 21U )
#define    DMA2_REQ22_TIM3_CH3                  ( 22U )
#define    DMA2_REQ23_TIM3_CH4                  ( 23U )
#define    DMA2_REQ24_TIM3_UP                   ( 24U )
#define    DMA2_REQ25_TIM3_TRIG                 ( 25U )
#define    DMA2_REQ26_ADC2                      ( 26U )
#define    DMA2_REQ27_ADC3                      ( 27U )
#define    DMA2_REQ28_UART3_SEND                ( 28U )
#define    DMA2_REQ29_UART3_RECV                ( 29U )
#define    DMA2_REQ30_LPUART_SEND               ( 30U )
#define    DMA2_REQ31_LPUART_RECV               ( 31U )
#define    DMA2_REQ32_TIM16_CH1                 ( 32U )
#define    DMA2_REQ33_TIM16_UP                  ( 33U )
#define    DMA2_REQ34_TIM17_CH1                 ( 34U )
#define    DMA2_REQ35_TIM17_UP                  ( 35U )
#define    DMA2_REQ36_TIM6_UP                   ( 36U )
#define    DMA2_REQ37_I2S1_TX                   ( 37U )
#define    DMA2_REQ38_I2S1_RX                   ( 38U )
#define    DMA2_REQ39_DAC1_CH1                  ( 39U )
#define    DMA2_REQ40_DAC1_CH2                  ( 40U )
#define    DMA2_REQ41_I2S2_TX                   ( 41U )
#define    DMA2_REQ42_I2S2_RX                   ( 42U )
#define    DMA2_REQ43_AES_IN                    ( 43U )
#define    DMA2_REQ44_AES_OUT                   ( 44U )
#define    DMA2_REQ45_UART4_SEND                ( 45U )
#define    DMA2_REQ46_UART4_RECV                ( 46U )
#define    DMA2_REQ47_SPI3_SEND                 ( 47U )
#define    DMA2_REQ48_SPI3_RECV                 ( 48U )
#define    DMA2_REQ49_TIM7_UP                   ( 49U )

/**
  * @}
  */
  
/**
  * @brief  DMA Link List Item Structure
  */

#define    DMA2_REQID_MAXLIMIT                  ( 50U )


/** @defgroup DMA_RawInt
 *  @{
 */
 
#define    DMA_RAWINT_DISABLE                   ( 0U )
#define    DMA_RAWINT_ENABLE                    ( DMA_CHCTRL_ITC )
/**
  * @}
  */

/** @defgroup DMA_SrcInc
 *  @{
 */
 
#define    DMA_SRCINC_DISABLE                   ( 0U )
#define    DMA_SRCINC_ENABLE                    ( DMA_CHCTRL_SI )
/**
  * @}
  */


/** @defgroup DMA_DestInc
 *  @{
 */
 
#define    DMA_DESTINC_DISABLE                  ( 0U )
#define    DMA_DESTINC_ENABLE                   ( DMA_CHCTRL_DI )
/**
  * @}
  */

/** @defgroup DMA_SrcWidth
 *  @{
 */
#define    DMA_SRCWIDTH_BYTE                    ( 0U )                      /*  8bit */
#define    DMA_SRCWIDTH_HALFWORD                ( DMA_CHCTRL_SWIDTH_0 )     /* 16bit */
#define    DMA_SRCWIDTH_WORD                    ( DMA_CHCTRL_SWIDTH_1 )     /* 36bit */
/**
  * @}
  */

/** @defgroup DMA_DestWidth
 *  @{
 */
#define    DMA_DESTWIDTH_BYTE                   ( 0U )                      /*  8bit */
#define    DMA_DESTWIDTH_HALFWORD               ( DMA_CHCTRL_SWIDTH_0 )     /* 16bit */
#define    DMA_DESTWIDTH_WORD                   ( DMA_CHCTRL_SWIDTH_1 )     /* 36bit */

/**
  * @}
  */
  
 /** @defgroup DMA_Mode
 *  @{
 */
#define DMA_MODE_NORMAL                         ( 0U )                          /*!< Normal mode    */
#define DMA_MODE_CIRCULAR                       ( 1U )                          /*!< Circular mode  */

/**
  * @}
  */

/**
  * @brief  DMA_SrcBurst
  */
  
#define DMA_SRCBURST_1                          ( 0U )
#define DMA_SRCBURST_4                          ( DMA_CHCTRL_SBSIZE_0 )
#define DMA_SRCBURST_8                          ( DMA_CHCTRL_SBSIZE_1 )
#define DMA_SRCBURST_16                         ( DMA_CHCTRL_SBSIZE_1 | DMA_CHCTRL_SBSIZE_0 )
#define DMA_SRCBURST_32                         ( DMA_CHCTRL_SBSIZE_2 )
#define DMA_SRCBURST_64                         ( DMA_CHCTRL_SBSIZE_2 | DMA_CHCTRL_SBSIZE_0 )
#define DMA_SRCBURST_128                        ( DMA_CHCTRL_SBSIZE_2 | DMA_CHCTRL_SBSIZE_1 )
#define DMA_SRCBURST_256                        ( DMA_CHCTRL_SBSIZE_2 | DMA_CHCTRL_SBSIZE_1 | DMA_CHCTRL_SBSIZE_0 )

/**
  * @}
  */

/**
  * @brief  DMA_DestBurst
  */
  
#define DMA_DESTBURST_1                         ( 0U )
#define DMA_DESTBURST_4                         ( DMA_CHCTRL_DBSIZE_0 )
#define DMA_DESTBURST_8                         ( DMA_CHCTRL_DBSIZE_1 )
#define DMA_DESTBURST_16                        ( DMA_CHCTRL_DBSIZE_1 | DMA_CHCTRL_DBSIZE_0 )
#define DMA_DESTBURST_32                        ( DMA_CHCTRL_DBSIZE_2 )
#define DMA_DESTBURST_64                        ( DMA_CHCTRL_DBSIZE_2 | DMA_CHCTRL_DBSIZE_0 )
#define DMA_DESTBURST_128                       ( DMA_CHCTRL_DBSIZE_2 | DMA_CHCTRL_DBSIZE_1 )
#define DMA_DESTBURST_256                       ( DMA_CHCTRL_DBSIZE_2 | DMA_CHCTRL_DBSIZE_1 | DMA_CHCTRL_DBSIZE_0 )

/**
  * @}
  */


/**
  * @brief  DMA_XfeCallbackID
  */
  
#define DMA_XFER_CPLT_CB_ID                         ( 0U )
#define DMA_XFER_HALFCPLT_CB_ID                     ( 1U )
#define DMA_XFER_ERROR_CB_ID                        ( 2U )

/**
  * @}
  */

/** @defgroup  DMA_Flag
  * @{
  */
#define DMA_FLAG_IT						            ( 0x01U )   /*!< Flag, indicating transmission completion interrupt or error interrupt occur */
#define DMA_FLAG_TC						            ( 0x02U )   /*!< Flag, indicating transmission completion interrupt occur	*/
#define DMA_FLAG_HTC					            ( 0x04U )   /*!< Flag, indicating half transmission completion interrupt occur	*/
#define DMA_FLAG_ERR					            ( 0x08U )   /*!< Flag, indicating error interrupt occur	*/
#define DMA_FLAG_RTC					            ( 0x10U )   /*!< Flag, indicating raw transmission completion interrupt occur */
#define DMA_FLAG_RHTC					            ( 0x20U )   /*!< Flag, indicating raw half transmission completion interrupt occur */
#define DMA_FLAG_RERR					            ( 0x40U )   /*!< Flag, indicating raw error interrupt occur */

/**
  * @}
  */

/** @defgroup  DMA Private Macros
  * @{
  */
#define IS_DMA_ALL_INSTANCE(INSTANCE)		(((INSTANCE) == DMA1_Channel0) || \
											 ((INSTANCE) == DMA1_Channel1) || \
											 ((INSTANCE) == DMA1_Channel2) || \
											 ((INSTANCE) == DMA1_Channel3) || \
											 ((INSTANCE) == DMA1_Channel4) || \
											 ((INSTANCE) == DMA1_Channel5) || \
											 ((INSTANCE) == DMA1_Channel6) || \
											 ((INSTANCE) == DMA1_Channel7) || \
											 ((INSTANCE) == DMA2_Channel0) || \
											 ((INSTANCE) == DMA2_Channel1) || \
											 ((INSTANCE) == DMA2_Channel2) || \
											 ((INSTANCE) == DMA2_Channel3) || \
											 ((INSTANCE) == DMA2_Channel4) || \
											 ((INSTANCE) == DMA2_Channel5) || \
											 ((INSTANCE) == DMA2_Channel6) || \
											 ((INSTANCE) == DMA2_Channel7))                                          

#define IS_DMA_MODE(MODE) 					(((MODE) == DMA_MODE_NORMAL )  || \
											 ((MODE) == DMA_MODE_CIRCULAR)) 
                                             
#define IS_DMA_DATAFLOW(DATAFLOW)			(((DATAFLOW) == DMA_DATAFLOW_M2M) || \
											 ((DATAFLOW) == DMA_DATAFLOW_M2P) || \
											 ((DATAFLOW) == DMA_DATAFLOW_P2M))


#define IS_DMA_REQ1ID(DATAFLOW, REQID)      ((DATAFLOW == DMA_DATAFLOW_M2M) ? SET : ((REQID) < DMA1_REQID_MAXLIMIT) )

#define IS_DMA_REQ2ID(DATAFLOW, REQID)      ((DATAFLOW == DMA_DATAFLOW_M2M) ? SET : ((REQID) < DMA2_REQID_MAXLIMIT) )

#define IS_DMA_SRCINC(SRCINC)               (((SRCINC) == DMA_SRCINC_DISABLE )  || \
											 ((SRCINC) == DMA_SRCINC_ENABLE)) 
                                             
#define IS_DMA_DESTINC(DESTINC)             (((DESTINC) == DMA_DESTINC_DISABLE )  || \
											 ((DESTINC) == DMA_DESTINC_ENABLE)) 
                                             
#define IS_DMA_SRCWIDTH(WIDTH)              (((WIDTH) == DMA_SRCWIDTH_BYTE)      || \
											 ((WIDTH) == DMA_SRCWIDTH_HALFWORD) || \
											 ((WIDTH) == DMA_SRCWIDTH_WORD))

#define IS_DMA_DESTWIDTH(WIDTH)             (((WIDTH) == DMA_DESTWIDTH_BYTE)      || \
											 ((WIDTH) == DMA_DESTWIDTH_HALFWORD) || \
											 ((WIDTH) == DMA_DESTWIDTH_WORD))

#define IS_DMA_SRCBURST(BURST)              (((BURST) == DMA_SRCBURST_1)      || \
											 ((BURST) == DMA_SRCBURST_4) || \
											 ((BURST) == DMA_SRCBURST_8) || \
											 ((BURST) == DMA_SRCBURST_16) || \
											 ((BURST) == DMA_SRCBURST_32) || \
											 ((BURST) == DMA_SRCBURST_64) || \
											 ((BURST) == DMA_SRCBURST_128) || \
											 ((BURST) == DMA_SRCBURST_256))

#define IS_DMA_DESTBURST(BURST)             (((BURST) == DMA_DESTBURST_1)      || \
											 ((BURST) == DMA_DESTBURST_4) || \
											 ((BURST) == DMA_DESTBURST_8) || \
											 ((BURST) == DMA_DESTBURST_16) || \
											 ((BURST) == DMA_DESTBURST_32) || \
											 ((BURST) == DMA_DESTBURST_64) || \
											 ((BURST) == DMA_DESTBURST_128) || \
											 ((BURST) == DMA_DESTBURST_256))

#define IS_DMA_CALLBACK_ID(ID)				(((ID) == DMA_XFER_CPLT_CB_ID)      || \
											 ((ID) == DMA_XFER_HALFCPLT_CB_ID) || \
											 ((ID) == DMA_XFER_ERROR_CB_ID))
            
#define IS_DMA_RAWIT(RAWIT)				    (((RAWIT) == DMA_RAWINT_DISABLE)      || \
											 ((RAWIT) == DMA_RAWINT_ENABLE))
            
#define IS_DMA_SRCADDR(ADDR)                (((ADDR) != 0) && (((ADDR) & 0x03U) == 0x0U))
            
#define IS_DMA_DESTADDR(ADDR)               (((ADDR) != 0) && (((ADDR) & 0x03U) == 0x0U))
            
#define IS_DMA_SIZE(SIZE)                   (((SIZE) != 0) && ((SIZE) <= 0xFFFFU))

#define IS_DMA_FLAGS(FLAG)                  (((FLAG) == DMA_FLAG_IT)      || \
											 ((FLAG) == DMA_FLAG_TC) || \
											 ((FLAG) == DMA_FLAG_HTC) || \
											 ((FLAG) == DMA_FLAG_ERR) || \
											 ((FLAG) == DMA_FLAG_RTC) || \
											 ((FLAG) == DMA_FLAG_RHTC) || \
											 ((FLAG) == DMA_FLAG_RERR))
            
	
/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/

#define __HAL_LINK_DMA(_HANDLE_, _DMA_LINK_, _DMA_HANDLE_)    		(_HANDLE_._DMA_LINK_ = &_DMA_HANDLE_)






#define __HAL_DMA_ENABLE_BIG_ENDIAN(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->CONFIG |= DMA_CONFIG_ENDIAN) : \
																	(DMA2->CONFIG |= DMA_CONFIG_ENDIAN))

#define __HAL_DMA_DISABLE_BIG_ENDIAN(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->CONFIG &= ~DMA_CONFIG_ENDIAN) : \
																	(DMA2->CONFIG &= ~DMA_CONFIG_ENDIAN))


#define __HAL_DMA_ENABLE(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->CONFIG |= DMA_CONFIG_EN) : \
																	(DMA2->CONFIG |= DMA_CONFIG_EN))

#define __HAL_DMA_DISABLE(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->CONFIG &= ~DMA_CONFIG_EN) : \
																	(DMA2->CONFIG &= ~DMA_CONFIG_EN))

#define __HAL_DMA_GET_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->INTSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))

#define __HAL_DMA_GET_HFTC_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTTCSTATUS & (1U << ((((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U) + 8U))) : \
																	(DMA2->INTTCSTATUS & (1U << ((((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U) + 8U))))

#define __HAL_DMA_GET_TC_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTTCSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->INTTCSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))

#define __HAL_DMA_GET_ERR_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTERRSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->INTERRSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))


#define __HAL_DMA_GET_RAW_HFTC_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->RAWINTTCSTATUS & (1U << ((((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U) + 8U))) : \
																	(DMA2->RAWINTTCSTATUS & (1U << ((((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U) + 8U))))

#define __HAL_DMA_GET_RAW_TC_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->RAWINTTCSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->RAWINTTCSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))

#define __HAL_DMA_GET_RAW_ERR_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->RAWINTERRSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->RAWINTERRSTATUS & (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))

#define __HAL_DMA_CLEAR_HFTC_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTTCCLR |= (1U << ((((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U) + 8U))) : \
																	(DMA2->INTTCCLR |= (1U << ((((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U) + 8U))))

#define __HAL_DMA_CLEAR_TC_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTTCCLR |= (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->INTTCCLR |= (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))

#define __HAL_DMA_CLEAR_ERR_IT_FLAG(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel0)) ? (DMA1->INTERRCLR |= (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA1_Channel0) >> 5U))) : \
																	(DMA2->INTERRCLR |= (1U << (((uint32_t)((__HANDLE__)->Instance) - (uint32_t)DMA2_Channel0) >> 5U))))


#define __HAL_DMA_GET_HFTC_IT_SOURCE(__HANDLE__) 					((__HANDLE__)->Instance->CHCONFIG & DMA_CHCONFIG_IHFTC)

#define __HAL_DMA_GET_TC_IT_SOURCE(__HANDLE__) 						((__HANDLE__)->Instance->CHCONFIG & DMA_CHCONFIG_ITC)

#define __HAL_DMA_GET_ERR_IT_SOURCE(__HANDLE__) 					((__HANDLE__)->Instance->CHCONFIG & DMA_CHCONFIG_IE)

#define __HAL_DMA_ENABLE_HFTC_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCONFIG |= DMA_CHCONFIG_IHFTC)

#define __HAL_DMA_DISABLE_HFTC_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCONFIG &= ~DMA_CHCONFIG_IHFTC)

#define __HAL_DMA_ENABLE_TC_IT(__HANDLE__) 							((__HANDLE__)->Instance->CHCONFIG |= DMA_CHCONFIG_ITC)

#define __HAL_DMA_DISABLE_TC_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCONFIG &= ~DMA_CHCONFIG_ITC)

#define __HAL_DMA_ENABLE_ERR_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCONFIG |= DMA_CHCONFIG_IE)

#define __HAL_DMA_DISABLE_ERR_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCONFIG &= ~DMA_CHCONFIG_IE)

#define __HAL_DMA_ENABLE_RAW_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCTRL |= DMA_CHCTRL_ITC)

#define __HAL_DMA_DISABLE_RAW_IT(__HANDLE__) 						((__HANDLE__)->Instance->CHCTRL &= ~DMA_CHCTRL_ITC)

#define __HAL_DMA_GET_COUNTER(__HANDLE__) 							((__HANDLE__)->Instance->CHCTRL & 0xFFFFU)



/* Exported functions --------------------------------------------------------*/

/* This function handles DMA interrupt request. */
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);

/* Initialize the DMA according to the specified. */
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);

/* DeInitializes the DMA peripheral. */
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);

/* Register callbacks. */
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, uint32_t CallbackID, \
                                     void (* pCallback)(struct __DMA_HandleTypeDef * hdma));
                                     
/* UnRegister callbacks. */
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, uint32_t CallbackID);

/* Starts the DMA Transfer. */
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddr, uint32_t DestAddr, uint32_t Size);

/* Start the DMA Transfer with interrupt enabled. */
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddr, \
									uint32_t DestAddr, uint32_t Size);
                                    
/* Initialize linked list. */
HAL_StatusTypeDef HAL_DMA_InitLink(DMA_LinkTypeDef *Link, DMA_LinkInitTypeDef *Link_Init);

/* Set the next node of the linked node. */
HAL_StatusTypeDef HAL_DMA_SetLinkNext(DMA_LinkTypeDef *Curr, DMA_LinkTypeDef *Next);

/* DMA link transfer start. */
HAL_StatusTypeDef HAL_DMA_Start_Link(DMA_HandleTypeDef *hdma, DMA_LinkTypeDef *Link);

/* Abort the DMA Transfer. */
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);

/* Returns the DMA state. */
FlagStatus HAL_DMA_GetState(DMA_HandleTypeDef *hdma, uint32_t Flag);

#endif
