/*
  ******************************************************************************
  * @file    HAL_PMU.h
  * @version V1.0.0
  * @date    2022
  * @brief   Header file of PMU HAL module.
  ******************************************************************************
*/

#ifndef __HAL_PMU_H__
#define __HAL_PMU_H__

#include "acm32g103_hal_conf.h"


/************************************************************************************/
/*                             Registers Bits Definition                            */
/************************************************************************************/

/****************  Bit definition for PMU CTRL0 Register  ***********************/
#define PMU_CTL0_STOP_WPT_Pos               ( 16U )
#define PMU_CTL0_STOP_WPT_Msk               ( 0xFFFU << PMU_CTL0_STOP_WPT_Pos )
#define PMU_CTL0_LPLDO12_LV_Pos             ( 12U )
#define PMU_CTL0_LPLDO12_LV_Msk             ( 0x7U << PMU_CTL0_LPLDO12_LV_Pos )
#define PMU_CTL0_LPLDO12_LV_1V1             ( 0x4U << PMU_CTL0_LPLDO12_LV_Pos )
#define PMU_CTL0_MLDO12_LOWP_Pos            ( 10U )
#define PMU_CTL0_MLDO12_LOWP_Msk            ( 0x1U << PMU_CTL0_MLDO12_LOWP_Pos )
#define PMU_CTL0_MLDO12_LOWP                ( PMU_CTL0_MLDO12_LOWP_Msk )
#define PMU_CTL0_MLDO12_LV_Pos              ( 8U )
#define PMU_CTL0_MLDO12_LV_Msk              ( 0x3U << PMU_CTL0_MLDO12_LV_Pos )
#define PMU_CTL0_MLDO12_LV_1V2              ( 0x0U << PMU_CTL0_MLDO12_LV_Pos )
#define PMU_CTL0_MLDO12_LV_1V0              ( 0x1U << PMU_CTL0_MLDO12_LV_Pos )
#define PMU_CTL0_MLDO12_LV_0V9              ( 0x2U << PMU_CTL0_MLDO12_LV_Pos )
#define PMU_CTL0_MLDO12_LV_0V8              ( 0x3U << PMU_CTL0_MLDO12_LV_Pos )  
#define PMU_CTL0_RTC_WE_Pos                 ( 7U ) 
#define PMU_CTL0_RTC_WE_Msk                 ( 0x1U << PMU_CTL0_RTC_WE_Pos )
#define PMU_CTL0_RTC_WE                     ( PMU_CTL0_RTC_WE_Msk ) 
#define PMU_CTL0_RC64M_DIV_EN_Pos           ( 5U ) 
#define PMU_CTL0_RC64M_DIV_EN_Msk           ( 0x1U << PMU_CTL0_RC64M_DIV_EN_Pos )
#define PMU_CTL0_RC64M_DIV_EN               ( PMU_CTL0_RC64M_DIV_EN_Msk ) 
#define PMU_CTL0_RC64MPDEN_Pos              ( 4U ) 
#define PMU_CTL0_RC64MPDEN_Msk              ( 0x1U << PMU_CTL0_RC64MPDEN_Pos )
#define PMU_CTL0_RC64MPDEN                  ( PMU_CTL0_RC64MPDEN_Pos )   
#define PMU_CTL0_LPMS_Pos                   ( 0U ) 
#define PMU_CTL0_LPMS_Msk                   ( 0x7U << PMU_CTL0_LPMS_Pos )
#define PMU_CTL0_LPMS_STOP0                 ( 0x0U << PMU_CTL0_LPMS_Pos )  
#define PMU_CTL0_LPMS_STOP1                 ( 0x1U << PMU_CTL0_LPMS_Pos ) 
#define PMU_CTL0_LPMS_STOP2                 ( 0x2U << PMU_CTL0_LPMS_Pos )  
#define PMU_CTL0_LPMS_STANDBY               ( 0x4U << PMU_CTL0_LPMS_Pos ) 
#define PMU_CTL0_LPMS_POWER_DOWN            ( 0x6U << PMU_CTL0_LPMS_Pos )          


/****************  Bit definition for PMU CTRL1 Register  ***********************/
#define PMU_CTL1_LVD_VALUE_Pos              ( 15U )
#define PMU_CTL1_LVD_VALUE_Msk              ( 0x1U << PMU_CTL1_LVD_VALUE_Pos )
#define PMU_CTL1_LVD_VALUE                  ( PMU_CTL1_LVD_VALUE_Msk )
#define PMU_CTL1_LVD_FILTER_Pos             ( 14U )
#define PMU_CTL1_LVD_FILTER_Msk             ( 0x1U << PMU_CTL1_LVD_FILTER_Pos )
#define PMU_CTL1_LVD_FILTER                 ( PMU_CTL1_LVD_FILTER_Msk )
#define PMU_CTL1_FLT_TIME_Pos               ( 9U ) 
#define PMU_CTL1_FLT_TIME_Msk               ( 0x7U << PMU_CTL1_FLT_TIME_Pos )
#define PMU_CTL1_FLT_TIME_1                 ( 0x0U << PMU_CTL1_FLT_TIME_Pos )  
#define PMU_CTL1_FLT_TIME_2                 ( 0x1U << PMU_CTL1_FLT_TIME_Pos ) 
#define PMU_CTL1_FLT_TIME_4                 ( 0x2U << PMU_CTL1_FLT_TIME_Pos )  
#define PMU_CTL1_FLT_TIME_16                ( 0x3U << PMU_CTL1_FLT_TIME_Pos ) 
#define PMU_CTL1_FLT_TIME_64                ( 0x4U << PMU_CTL1_FLT_TIME_Pos )  
#define PMU_CTL1_FLT_TIME_256               ( 0x5U << PMU_CTL1_FLT_TIME_Pos )
#define PMU_CTL1_FLT_TIME_1024              ( 0x6U << PMU_CTL1_FLT_TIME_Pos )
#define PMU_CTL1_FLT_TIME_4095              ( 0x7U << PMU_CTL1_FLT_TIME_Pos )
#define PMU_CTL1_LVD_FLTEN_Pos              ( 8U ) 
#define PMU_CTL1_LVD_FLTEN_Msk              ( 0x1U << PMU_CTL1_LVD_FLTEN_Pos )
#define PMU_CTL1_LVD_FLTEN                  ( PMU_CTL1_LVD_FLTEN_Pos ) 
#define PMU_CTL1_LVD_SEL_Pos                ( 1U ) 
#define PMU_CTL1_LVD_SEL_Msk                ( 0x7U << PMU_CTL1_LVD_SEL_Pos )
#define PMU_CTL1_LVD_SEL_171                ( 0x0U << PMU_CTL1_LVD_SEL_Pos )  
#define PMU_CTL1_LVD_SEL_201                ( 0x1U << PMU_CTL1_LVD_SEL_Pos ) 
#define PMU_CTL1_LVD_SEL_223                ( 0x2U << PMU_CTL1_LVD_SEL_Pos )  
#define PMU_CTL1_LVD_SEL_243                ( 0x3U << PMU_CTL1_LVD_SEL_Pos ) 
#define PMU_CTL1_LVD_SEL_251                ( 0x4U << PMU_CTL1_LVD_SEL_Pos )  
#define PMU_CTL1_LVD_SEL_273                ( 0x5U << PMU_CTL1_LVD_SEL_Pos )
#define PMU_CTL1_LVD_SEL_280                ( 0x6U << PMU_CTL1_LVD_SEL_Pos )
#define PMU_CTL1_LVD_SEL_290                ( 0x7U << PMU_CTL1_LVD_SEL_Pos )
#define PMU_CTL1_LVDEN_Pos                  ( 0U ) 
#define PMU_CTL1_LVDEN_Msk                  ( 0x1U << PMU_CTL1_LVDEN_Pos )
#define PMU_CTL1_LVDEN                      ( PMU_CTL1_LVDEN_Msk ) 

/****************  Bit definition for PMU CTRL2 Register  ***********************/
#define PMU_CTL2_BOR_CFG_Pos                ( 26U )
#define PMU_CTL2_BOR_CFG_Msk                ( 0x3U << PMU_CTL2_BOR_CFG_Pos )
#define PMU_CTL2_BOR_CFG_2V0                ( 0x0U << PMU_CTL2_BOR_CFG_Pos )
#define PMU_CTL2_BOR_CFG_2V2                ( 0x1U << PMU_CTL2_BOR_CFG_Pos )
#define PMU_CTL2_BOR_CFG_2V49               ( 0x2U << PMU_CTL2_BOR_CFG_Pos )
#define PMU_CTL2_BOR_CFG_2V77               ( 0x3U << PMU_CTL2_BOR_CFG_Pos ) 
#define PMU_CTL2_BOR_EN_Pos                 ( 24U ) 
#define PMU_CTL2_BOR_EN_Msk                 ( 0x1U << PMU_CTL2_BOR_EN_Pos )
#define PMU_CTL2_BOR_EN                     ( PMU_CTL2_BOR_EN_Msk )
#define PMU_CTL2_BORRST_EN_Pos              ( 20U ) 
#define PMU_CTL2_BORRST_EN_Msk              ( 0x1U << PMU_CTL2_BORRST_EN_Pos )
#define PMU_CTL2_BORRST_EN                  ( PMU_CTL2_BORRST_EN_Msk ) 
#define PMU_CTL2_STDBY_WPT_Pos              ( 16U ) 
#define PMU_CTL2_STDBY_WPT_Msk              ( 0x7U << PMU_CTL2_STDBY_WPT_Pos )
#define PMU_CTL2_STDBY_WPT_1RC32K           ( 0x0U << PMU_CTL2_STDBY_WPT_Pos )  
#define PMU_CTL2_STDBY_WPT_2RC32K           ( 0x1U << PMU_CTL2_STDBY_WPT_Pos ) 
#define PMU_CTL2_STDBY_WPT_3RC32K           ( 0x2U << PMU_CTL2_STDBY_WPT_Pos )  
#define PMU_CTL2_STDBY_WPT_4RC32K           ( 0x3U << PMU_CTL2_STDBY_WPT_Pos ) 
#define PMU_CTL2_STDBY_WPT_5RC32K           ( 0x4U << PMU_CTL2_STDBY_WPT_Pos )  
#define PMU_CTL2_STDBY_WPT_6RC32K           ( 0x5U << PMU_CTL2_STDBY_WPT_Pos )
#define PMU_CTL2_STDBY_WPT_7RC32K           ( 0x6U << PMU_CTL2_STDBY_WPT_Pos )
#define PMU_CTL2_STDBY_WPT_INVALID          ( 0x7U << PMU_CTL2_STDBY_WPT_Pos ) 
#define PMU_CTL2_WUXFILEN_Pos               ( 8U )           
#define PMU_CTL2_WUXFILEN_Msk               ( 0x1FU << PMU_CTL2_WUXFILEN_Pos )
#define PMU_CTL2_WUXFILEN_WKUP1             ( 0x1U << PMU_CTL2_WUXFILEN_Pos ) 
#define PMU_CTL2_WUXFILEN_WKUP2             ( 0x2U << PMU_CTL2_WUXFILEN_Pos )
#define PMU_CTL2_WUXFILEN_WKUP3             ( 0x4U << PMU_CTL2_WUXFILEN_Pos )
#define PMU_CTL2_WUXFILEN_WKUP4             ( 0x8U << PMU_CTL2_WUXFILEN_Pos )
#define PMU_CTL2_WUXFILEN_WKUP5             ( 0x10U << PMU_CTL2_WUXFILEN_Pos )  
#define PMU_CTL2_EWUPX_Pos                  ( 0U )           
#define PMU_CTL2_EWUPX_Msk                  ( 0x1FU << PMU_CTL2_EWUPX_Pos )
#define PMU_CTL2_EWUPX_WKUP1                ( 0x1U << PMU_CTL2_EWUPX_Pos ) 
#define PMU_CTL2_EWUPX_WKUP2                ( 0x2U << PMU_CTL2_EWUPX_Pos )
#define PMU_CTL2_EWUPX_WKUP3                ( 0x4U << PMU_CTL2_EWUPX_Pos )
#define PMU_CTL2_EWUPX_WKUP4                ( 0x8U << PMU_CTL2_EWUPX_Pos )
#define PMU_CTL2_EWUPX_WKUP5                ( 0x10U << PMU_CTL2_EWUPX_Pos )  

/****************  Bit definition for PMU CTRL3 Register  ***********************/
#define PMU_CTL3_WUPOLX_Pos                 ( 0U )           
#define PMU_CTL3_WUPOLX_Msk                 ( 0x1FU << PMU_CTL3_WUPOLX_Pos )
#define PMU_CTL3_WUPOLX_WKUP1               ( 0x1U << PMU_CTL3_WUPOLX_Pos ) 
#define PMU_CTL3_WUPOLX_WKUP2               ( 0x2U << PMU_CTL3_WUPOLX_Pos )
#define PMU_CTL3_WUPOLX_WKUP3               ( 0x4U << PMU_CTL3_WUPOLX_Pos )
#define PMU_CTL3_WUPOLX_WKUP4               ( 0x8U << PMU_CTL3_WUPOLX_Pos )
#define PMU_CTL3_WUPOLX_WKUP5               ( 0x10U << PMU_CTL3_WUPOLX_Pos )  

/****************  Bit definition for PMU SR Register  ***********************/
#define PMU_SR_BORN_Pos                     ( 16U )
#define PMU_SR_BORN_Msk                     ( 0x1U << PMU_SR_BORN_Pos )
#define PMU_SR_BORN                         (PMU_SR_BORN_Msk)
#define PMU_SR_BORWUF_Pos                   ( 15U )
#define PMU_SR_BORWUF_Msk                   ( 0x1U << PMU_SR_BORWUF_Pos )
#define PMU_SR_BORWUF                       ( PMU_SR_BORWUF_Msk ) 
#define PMU_SR_IWDTWUF_Pos                  ( 14U )
#define PMU_SR_IWDTWUF_Msk                  ( 0x1U << PMU_SR_IWDTWUF_Pos )
#define PMU_SR_IWDTWUF                      ( PMU_SR_IWDTWUF_Msk )
#define PMU_SR_RSTWUF_Pos                   ( 13U )
#define PMU_SR_RSTWUF_Msk                   ( 0x1U << PMU_SR_RSTWUF_Pos )
#define PMU_SR_RSTWUF                       ( PMU_SR_RSTWUF_Msk ) 
#define PMU_SR_RTCWUF_Pos                   ( 12U )
#define PMU_SR_RTCWUF_Msk                   ( 0x1U << PMU_SR_RTCWUF_Pos ) 
#define PMU_SR_RTCWUF                       ( PMU_SR_RTCWUF_Msk )
#define PMU_SR_SBF_Pos                      ( 8U )
#define PMU_SR_SBF_Msk                      ( 0x1U << PMU_SR_SBF_Pos )
#define PMU_SR_SBF                          ( PMU_SR_SBF_Msk ) 
#define PMU_SR_WUPFX_Pos                    ( 0U ) 
#define PMU_SR_WUPFX_WKUP1                  ( 0x1U << PMU_SR_WUPFX_Pos ) 
#define PMU_SR_WUPFX_WKUP2                  ( 0x2U << PMU_SR_WUPFX_Pos )
#define PMU_SR_WUPFX_WKUP3                  ( 0x4U << PMU_SR_WUPFX_Pos )
#define PMU_SR_WUPFX_WKUP4                  ( 0x8U << PMU_SR_WUPFX_Pos )
#define PMU_SR_WUPFX_WKUP5                  ( 0x10U << PMU_SR_WUPFX_Pos ) 


/****************  Bit definition for PMU STCLR Register  ***********************/
#define PMU_SRCLR_CBORWUF_Pos               ( 15U )
#define PMU_SRCLR_CBORWUF_Msk               ( 0x1U << PMU_SRCLR_CBORWUF_Pos )
#define PMU_SRCLR_CBORWUF                   ( PMU_SRCLR_CBORWUF_Msk ) 
#define PMU_SRCLR_CIWDTWUF_Pos              ( 14U )
#define PMU_SRCLR_CIWDTWUF_Msk              ( 0x1U << PMU_SRCLR_CIWDTWUF_Pos )
#define PMU_SRCLR_CIWDTWUF                  ( PMU_SRCLR_CIWDTWUF_Msk )
#define PMU_SRCLR_CRSTWUF_Pos               ( 13U )
#define PMU_SRCLR_CRSTWUF_Msk               ( 0x1U << PMU_SRCLR_CRSTWUF_Pos )
#define PMU_SRCLR_CRSTWUF                   ( PMU_SRCLR_CRSTWUF_Msk ) 
#define PMU_SRCLR_CRTCWUF_Pos               ( 12U )
#define PMU_SRCLR_CRTCWUF_Msk               ( 0x1U << PMU_SRCLR_CRTCWUF_Pos )
#define PMU_SRCLR_CRTCWUF                   ( PMU_SRCLR_CRTCWUF_Msk ) 
#define PMU_SRCLR_CSBF_Pos                  ( 8U )
#define PMU_SRCLR_CSBF_Msk                  ( 0x1U << PMU_SRCLR_CSBF_Pos )
#define PMU_SRCLR_CSBF                      ( PMU_SRCLR_CSBF_Msk )
#define PMU_SRCLR_CWUPFX_Pos                ( 0U ) 
#define PMU_SRCLR_CWUPFX_Msk                ( 0x1FU << PMU_SRCLR_CWUPFX_Pos ) 
#define PMU_SRCLR_CWUPFX_WKUP1              ( 0x1U << PMU_SRCLR_CWUPFX_Pos ) 
#define PMU_SRCLR_CWUPFX_WKUP2              ( 0x2U << PMU_SRCLR_CWUPFX_Pos )
#define PMU_SRCLR_CWUPFX_WKUP3              ( 0x4U << PMU_SRCLR_CWUPFX_Pos )
#define PMU_SRCLR_CWUPFX_WKUP4              ( 0x8U << PMU_SRCLR_CWUPFX_Pos )
#define PMU_SRCLR_CWUPFX_WKUP5              ( 0x10U << PMU_SRCLR_CWUPFX_Pos ) 

/****************  Bit definition for PMU IOSEL Register  ***********************/
#define PMU_IOSEL_PC15_VALUE_Pos            ( 10U )
#define PMU_IOSEL_PC15_VALUE_Msk            ( 0x1U << PMU_IOSEL_PC15_VALUE_Pos ) 
#define PMU_IOSEL_PC15_VALUE                ( PMU_IOSEL_PC15_VALUE_Msk )
#define PMU_IOSEL_PC14_VALUE_Pos            ( 9U )
#define PMU_IOSEL_PC14_VALUE_Msk            ( 0x1U << PMU_IOSEL_PC14_VALUE_Pos )
#define PMU_IOSEL_PC14_VALUE                ( PMU_IOSEL_PC14_VALUE_Msk )
#define PMU_IOSEL_PC13_VALUE_Pos            ( 8U )
#define PMU_IOSEL_PC13_VALUE_Msk            ( 0x1U << PMU_IOSEL_PC13_VALUE_Pos )
#define PMU_IOSEL_PC13_VALUE                ( PMU_IOSEL_PC13_VALUE_Msk )
#define PMU_IOSEL_PC15_SEL_Pos              ( 5U )
#define PMU_IOSEL_PC15_SEL_Msk              ( 0x3U << PMU_IOSEL_PC15_SEL_Pos )
#define PMU_IOSEL_PC15_SEL_GPIO             ( 0x0U << PMU_IOSEL_PC15_SEL_Pos )
#define PMU_IOSEL_PC15_SEL_OUT_PP           ( 0x1U << PMU_IOSEL_PC15_SEL_Pos ) 
#define PMU_IOSEL_PC15_SEL_CLOSE_OUT        ( 0x2U << PMU_IOSEL_PC15_SEL_Pos )
#define PMU_IOSEL_PC14_SEL_Pos              ( 3U )
#define PMU_IOSEL_PC14_SEL_Msk              ( 0x3U << PMU_IOSEL_PC14_SEL_Pos )
#define PMU_IOSEL_PC14_SEL_GPIO             ( 0x0U << PMU_IOSEL_PC14_SEL_Pos )
#define PMU_IOSEL_PC14_SEL_OUT_PP           ( 0x1U << PMU_IOSEL_PC14_SEL_Pos ) 
#define PMU_IOSEL_PC14_SEL_CLOSE_OUT        ( 0x2U << PMU_IOSEL_PC14_SEL_Pos )
#define PMU_IOSEL_PC13_SEL_Pos              ( 0U )
#define PMU_IOSEL_PC13_SEL_Msk              ( 0x3U << PMU_IOSEL_PC13_SEL_Pos )
#define PMU_IOSEL_PC13_SEL_GPIO             ( 0x0U << PMU_IOSEL_PC13_SEL_Pos )
#define PMU_IOSEL_PC13_SEL_RTC_FOUT         ( 0x1U << PMU_IOSEL_PC13_SEL_Pos )
#define PMU_IOSEL_PC13_SEL_RTC_TAMPER       ( 0x2U << PMU_IOSEL_PC13_SEL_Pos )
#define PMU_IOSEL_PC13_SEL_OUT_PP           ( 0x3U << PMU_IOSEL_PC13_SEL_Pos ) 


/**
  * @brief  IO wake-up source
  */
typedef enum
{
    STANDBY_WAKEUP1  = 0x00000001,    //PA0 
    STANDBY_WAKEUP2  = 0x00000002,    //PC13   
    STANDBY_WAKEUP3  = 0x00000004,    //PA2  
    STANDBY_WAKEUP4  = 0x00000008,    //PC5  
    STANDBY_WAKEUP5  = 0x00000010,    //PB5  
}PMU_WakeUpIo_t;


/**
  * @brief  RTC wake-up source
  */
typedef enum
{
    STANDBY_WAKEUP_WUTIE  = RTC_IE_WUTIE,
    STANDBY_WAKEUP_STAMP2 = (RTC_IE_STP2RIE | RTC_IE_STP2FIE),
    STANDBY_WAKEUP_STAMP1 = (RTC_IE_STP1RIE | RTC_IE_STP1FIE),
    STANDBY_WAKEUP_32S    = RTC_IE_ADJ32,
    STANDBY_WAKEUP_ALARM  = RTC_IE_ALM,
    STANDBY_WAKEUP_1KHZ   = RTC_IE_1KHZ,
    STANDBY_WAKEUP_256HZ  = RTC_IE_256HZ,
    STANDBY_WAKEUP_64HZ   = RTC_IE_64HZ,
    STANDBY_WAKEUP_16HZ   = RTC_IE_16HZ,
    STANDBY_WAKEUP_8HZ    = RTC_IE_8HZ,
    STANDBY_WAKEUP_4HZ    = RTC_IE_4HZ,
    STANDBY_WAKEUP_2HZ    = RTC_IE_2HZ,   
    STANDBY_WAKEUP_SEC    = RTC_IE_SEC,
    STANDBY_WAKEUP_MIN    = RTC_IE_MIN,
    STANDBY_WAKEUP_HOUR   = RTC_IE_HOUR,
    STANDBY_WAKEUP_DATE   = RTC_IE_DATE,
}PMU_WakeUpRtc_t;  


/**
  * @brief  Wake Up Edge Configuration
  */

#define STANDBY_WAKEUP_RISING           0x00000000
#define STANDBY_WAKEUP_FALLING          0x00000001


/**
  * @brief  Wait for an interrupt or event
  */

#define WAIT_FOR_INT                    0x00000000  
#define WAIT_FOR_EVENT                  0x00000001



/** @brief  PC13 function select 
  * @param  __FUNC__: PC13 function select.
  *         This parameter can be 0: GPIO£¬1£ºRTC Fout£¬2£ºRTC tamper 3£ºPC13 Value
  */
#define __HAL_PMU_PC13_SEL(__FUNC__)    (PMU->IOSEL |= (PMU->IOSEL & ~(0x3)) | (__FUNC__))

/** @brief  PC14 function select 
  * @param  __FUNC__: PC14 function select.
  *         This parameter can be 0: GPIO£¬1£ºPC14 Value
  */
#define __HAL_PMU_PC14_SEL(__FUNC__)    (PMU->IOSEL |= (PMU->IOSEL & ~(0x3 << 3)) | (__FUNC__ << 3))

/** @brief  PC15 function select 
  * @param  __FUNC__: PC15 function select.
  *         This parameter can be 0: GPIO£¬1£ºPC15 Value
  */
#define __HAL_PMU_PC15_SEL(__FUNC__)    (PMU->IOSEL |= (PMU->IOSEL & ~(0x3 << 5)) | (__FUNC__ << 5))

/** @brief  PC13 Value set 
  * @param  __FUNC__: PC13 Value set.
  *         This parameter can be 0: set£¬1£ºclaer
  */
#define __HAL_PMU_PC13_VALUE(__VALUE__)    (PMU->IOSEL |= (PMU->IOSEL & ~(1 << 8)) | (__VALUE__ << 8))

/** @brief  PC14 Value set 
  * @param  __FUNC__: PC14 Value set.
  *         This parameter can be 0: set£¬1£ºclaer
  */
#define __HAL_PMU_PC14_VALUE(__VALUE__)    (PMU->IOSEL |= (PMU->IOSEL & ~(1 << 9)) | (__VALUE__ << 9))

/** @brief  PC15 Value set 
  * @param  __FUNC__: PC15 Value set.
  *         This parameter can be 0: set£¬1£ºclaer
  */
#define __HAL_PMU_PC15_VALUE(__VALUE__)    (PMU->IOSEL |= (PMU->IOSEL & ~(1 << 10)) | (__VALUE__ << 10))



void HAL_PMU_EnterSleepMode(uint32_t sleepEntry);

void HAL_PMU_EnterStopMode(uint32_t stopEntry, uint32_t stopMode);

void HAL_PMU_EnterStandbyMode(void);

void HAL_PMU_StandbyWakeupIOConfig(PMU_WakeUpIo_t wakeup_io, uint32_t edge);

void HAL_PMU_StandbyWakeupRTCConfig(PMU_WakeUpRtc_t wakeup_rtc);

bool HAL_RTC_GetStandbyStatus(void);

uint32_t HAL_PMU_GetStandbyWakeupSource(void);


#endif



