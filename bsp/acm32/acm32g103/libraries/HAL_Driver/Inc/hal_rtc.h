/*
  ******************************************************************************
  * @file    HAL_RTC.h
  * @version V1.0.0
  * @date    2022
  * @brief   Header file of RTC HAL module.
  ******************************************************************************
*/

#ifndef __HAL_RTC_H__
#define __HAL_RTC_H__

#include "acm32g103_hal_conf.h"

/************************************************************************************/
/*                             Registers Bits Definition                            */
/************************************************************************************/

/****************  Bit definition for RTC IE Register  ***********************/
#define RTC_IE_WUTIE_Pos                ( 17U )
#define RTC_IE_WUTIE_Msk                ( 0x1U << RTC_IE_WUTIE_Pos )
#define RTC_IE_WUTIE                    ( RTC_IE_WUTIE_Msk )
#define RTC_IE_STP2RIE_Pos              ( 16U )
#define RTC_IE_STP2RIE_Msk              ( 0x1U << RTC_IE_STP2RIE_Pos )
#define RTC_IE_STP2RIE                  ( RTC_IE_STP2RIE_Msk )
#define RTC_IE_STP2FIE_Pos              ( 15U )
#define RTC_IE_STP2FIE_Msk              ( 0x1U << RTC_IE_WUTIE_Pos )
#define RTC_IE_STP2FIE                  ( RTC_IE_STP2FIE_Msk )
#define RTC_IE_STP1RIE_Pos              ( 14U )
#define RTC_IE_STP1RIE_Msk              ( 0x1U << RTC_IE_STP1RIE_Pos)
#define RTC_IE_STP1RIE                  ( RTC_IE_STP1RIE_Msk )
#define RTC_IE_STP1FIE_Pos              ( 13U )
#define RTC_IE_STP1FIE_Msk              ( 0x1U << RTC_IE_STP1FIE_Pos )
#define RTC_IE_STP1FIE                  ( RTC_IE_STP1FIE_Msk )
#define RTC_IE_ADJ32_Pos                ( 12U ) 
#define RTC_IE_ADJ32_Msk                ( 0x1U << RTC_IE_ADJ32_Pos)
#define RTC_IE_ADJ32                    ( RTC_IE_ADJ32_Msk )
#define RTC_IE_ALM_Pos                  ( 11U )   
#define RTC_IE_ALM_Msk                  ( 0x1U << RTC_IE_ALM_Pos )
#define RTC_IE_ALM                      ( RTC_IE_ALM_Msk )
#define RTC_IE_1KHZ_Pos                 ( 10U )
#define RTC_IE_1KHZ_Msk                 ( 0x1U << RTC_IE_1KHZ_Pos)
#define RTC_IE_1KHZ                     ( RTC_IE_1KHZ_Msk )
#define RTC_IE_256HZ_Pos                ( 9U )
#define RTC_IE_256HZ_Msk                ( 0x1U << RTC_IE_256HZ_Pos )
#define RTC_IE_256HZ                    ( RTC_IE_256HZ_Msk )
#define RTC_IE_64HZ_Pos                 ( 8U )
#define RTC_IE_64HZ_Msk                 ( 0x1U << RTC_IE_64HZ_Pos )
#define RTC_IE_64HZ                     ( RTC_IE_64HZ_Msk )
#define RTC_IE_16HZ_Pos                 ( 7U )
#define RTC_IE_16HZ_Msk                 ( 0x1U << RTC_IE_16HZ_Pos )
#define RTC_IE_16HZ                     ( RTC_IE_16HZ_Msk )
#define RTC_IE_8HZ_Pos                  ( 6U )
#define RTC_IE_8HZ_Msk                  ( 0x1U << RTC_IE_8HZ_Pos )
#define RTC_IE_8HZ                      ( RTC_IE_8HZ_Msk )
#define RTC_IE_4HZ_Pos                  ( 5U )
#define RTC_IE_4HZ_Msk                  ( 0x1U << RTC_IE_4HZ_Pos)
#define RTC_IE_4HZ                      ( RTC_IE_4HZ_Msk )
#define RTC_IE_2HZ_Pos                  ( 4U )
#define RTC_IE_2HZ_Msk                  ( 0x1U << RTC_IE_2HZ_Pos )
#define RTC_IE_2HZ                      ( RTC_IE_2HZ_Msk )
#define RTC_IE_SEC_Pos                  ( 3U )
#define RTC_IE_SEC_Msk                  ( 0x1U << RTC_IE_SEC_Pos )
#define RTC_IE_SEC                      ( RTC_IE_SEC_Msk )
#define RTC_IE_MIN_Pos                  ( 2U )
#define RTC_IE_MIN_Msk                  ( 0x1U << RTC_IE_MIN_Pos )
#define RTC_IE_MIN                      ( RTC_IE_MIN_Msk )
#define RTC_IE_HOUR_Pos                 ( 1U )
#define RTC_IE_HOUR_Msk                 ( 0x1U << RTC_IE_HOUR_Pos )
#define RTC_IE_HOUR                     ( RTC_IE_HOUR_Msk )
#define RTC_IE_DATE_Pos                 ( 0U )
#define RTC_IE_DATE_Msk                 ( 0x1U << RTC_IE_DATE_Pos )
#define RTC_IE_DATE                     ( RTC_IE_DATE_Msk )

/****************  Bit definition for RTC SR Register  ***********************/
#define RTC_SR_WUTWF_Pos                ( 24U )
#define RTC_SR_WUTWF_Msk                ( 0x1U << RTC_SR_WUTWF_Pos )
#define RTC_SR_WUTWF                    ( RTC_SR_WUTWF_Msk )
#define RTC_SR_WUTF_Pos                 ( 17U )
#define RTC_SR_WUTF_Msk                 ( 0x1U << RTC_SR_WUTF_Pos )
#define RTC_SR_WUTF                     ( RTC_SR_WUTF_Msk )
#define RTC_SR_STP2RIE_Pos              ( 16U )
#define RTC_SR_STP2RIE_Msk              ( 0x1U << RTC_SR_STP2RIE_Pos )
#define RTC_SR_STP2RIE                  ( RTC_SR_STP2RIE_Msk )
#define RTC_SR_STP2FIE_Pos              ( 15U )
#define RTC_SR_STP2FIE_Msk              ( 0x1U << RTC_SR_STP2FIE_Pos )
#define RTC_SR_STP2FIE                  ( RTC_SR_STP2FIE_Msk )
#define RTC_SR_STP1RIE_Pos              ( 14U )
#define RTC_SR_STP1RIE_Msk              ( 0x1U << RTC_SR_STP1RIE_Pos )
#define RTC_SR_STP1RIE                  ( RTC_SR_STP1RIE_Msk )
#define RTC_SR_STP1FIE_Pos              ( 13U )
#define RTC_SR_STP1FIE_Msk              ( 0x1U << RTC_SR_STP1FIE_Pos )
#define RTC_SR_STP1FIE                  ( RTC_SR_STP1FIE_Msk )
#define RTC_SR_ADJ32_Pos                ( 12U )
#define RTC_SR_ADJ32_Msk                ( 0x1U << RTC_SR_ADJ32_Pos ) 
#define RTC_SR_ADJ32                    ( RTC_SR_ADJ32_Msk )
#define RTC_SR_ALM_Pos                  ( 11U )   
#define RTC_SR_ALM_Msk                  ( 0x1U << RTC_SR_ALM_Pos )
#define RTC_SR_ALM                      ( RTC_SR_ALM_Msk )
#define RTC_SR_1KHZ_Pos                 ( 10U )
#define RTC_SR_1KHZ_Msk                 ( 0x1 << RTC_SR_1KHZ_Pos )
#define RTC_SR_1KHZ                     ( RTC_SR_1KHZ_Msk )
#define RTC_SR_256HZ_Pos                ( 9U )
#define RTC_SR_256HZ_Msk                ( 0x1U << RTC_SR_256HZ_Pos )
#define RTC_SR_256HZ                    ( RTC_SR_256HZ_Msk )
#define RTC_SR_64HZ_Pos                 ( 8U )
#define RTC_SR_64HZ_Msk                 ( 0x1U << RTC_SR_64HZ_Pos )
#define RTC_SR_64HZ                     ( RTC_SR_64HZ_Msk )
#define RTC_SR_16HZ_Pos                 ( 7U )
#define RTC_SR_16HZ_Msk                 ( 0x1U << RTC_SR_16HZ_Pos )
#define RTC_SR_16HZ                     ( RTC_SR_16HZ_Msk )
#define RTC_SR_8HZ_Pos                  ( 6U )
#define RTC_SR_8HZ_Msk                  ( 0x1U << RTC_SR_8HZ_Pos )
#define RTC_SR_8HZ                      ( RTC_SR_8HZ_Msk )
#define RTC_SR_4HZ_Pos                  ( 5U )
#define RTC_SR_4HZ_Msk                  ( 0x1U << RTC_SR_4HZ_Pos)
#define RTC_SR_4HZ                      ( RTC_SR_4HZ_Msk )
#define RTC_SR_2HZ_Pos                  ( 4U )
#define RTC_SR_2HZ_Msk                  ( 0x1U << RTC_SR_2HZ_Pos)
#define RTC_SR_2HZ                      ( RTC_SR_2HZ_Msk )
#define RTC_SR_SEC_Pos                  ( 3U )
#define RTC_SR_SEC_Msk                  (0x1U << RTC_SR_SEC_Pos )
#define RTC_SR_SEC                      ( RTC_SR_SEC_Msk )
#define RTC_SR_MIN_Pos                  ( 2U )
#define RTC_SR_MIN_Msk                  ( 0x1U << RTC_SR_MIN_Pos )
#define RTC_SR_MIN                      ( RTC_SR_MIN_Msk )
#define RTC_SR_HOUR_Pos                 ( 1U )
#define RTC_SR_HOUR_Msk                 ( 0x1U << RTC_SR_HOUR_Pos )
#define RTC_SR_HOUR                     ( RTC_SR_HOUR_Msk )
#define RTC_SR_DATE_Pos                 ( 0U )
#define RTC_SR_DATE_Msk                 ( 0x1U << RTC_SR_DATE_Pos )
#define RTC_SR_DATE                     ( RTC_SR_DATE_Msk )

/****************  Bit definition for RTC ALM Register  ***********************/
#define RTC_ALM_ALM_WDS_Pos             ( 31U )
#define RTC_ALM_ALM_WDS_Msk             ( 0x1U << RTC_ALM_ALM_WDS_Pos )
#define RTC_ALM_ALM_WDS_WEEK            ( 0x0U << RTC_ALM_ALM_WDS_Pos )
#define RTC_ALM_ALM_WDS_DAY             ( 0x1U << RTC_ALM_ALM_WDS_Pos )
#define RTC_ALM_ALMWEEK_Pos             ( 24U )
#define RTC_ALM_ALMWEEK_Msk             ( 0x7FU << RTC_ALM_ALMWEEK_Pos )
#define RTC_ALM_ALMDAY_Pos              ( 24U )
#define RTC_ALM_ALMDAY_Msk              ( 0x3FU << RTC_ALM_ALMDAY_Pos )
#define RTC_ALM_ALMHOUR_Pos             ( 16U )
#define RTC_ALM_ALMHOUR_Msk             ( 0x3FU << RTC_ALM_ALMHOUR_Pos )
#define RTC_ALM_ALMMIN_Pos              ( 8U )
#define RTC_ALM_ALMMIN_Msk              ( 0x7FU << RTC_ALM_ALMMIN_Pos )
#define RTC_ALM_ALMSEC_Pos              ( 0U )
#define RTC_ALM_ALMSEC_Msk              ( 0x7FU << RTC_ALM_ALMSEC_Pos )

/****************  Bit definition for RTC CR Register  ***********************/
#define RTC_CR_WUCKSEL_Pos              (24U )
#define RTC_CR_WUCKSEL_Msk              ( 0x7U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_1_16             ( 0x0U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_1_8              ( 0x1U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_1_4              ( 0x2U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_1_2              ( 0x3U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_1HZ              ( 0x4U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_1_2HZ            ( 0x5U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUCKSEL_2HZ              ( 0x6U << RTC_CR_WUCKSEL_Pos )
#define RTC_CR_WUTE_Pos                 ( 23U )
#define RTC_CR_WUTE_Msk                 ( 0x1U << RTC_CR_WUTE_Pos)
#define RTC_CR_WUTE                     ( RTC_CR_WUTE_Msk )
#define RTC_CR_TAMPFLTCLK_Pos           ( 22U )
#define RTC_CR_TAMPFLTCLK_Msk           ( 0x1U << RTC_CR_TAMPFLTCLK_Pos )
#define RTC_CR_TAMPFLTCLK_512_RTCCLK    ( RTC_CR_TAMPFLTCLK_Msk )
#define RTC_CR_TS2EDGE_Pos              ( 21U )
#define RTC_CR_TS2EDGE_Msk              ( 0x1U << RTC_CR_TS2EDGE_Pos )
#define RTC_CR_TS2EDGE                  ( RTC_CR_TS2EDGE_Msk )
#define RTC_CR_TAMP2FLT_Pos             ( 19U )
#define RTC_CR_TAMP2FLT_Msk             ( 0x3U << RTC_CR_TAMP2FLT_Pos )
#define RTC_CR_TAMP2FLT_1               ( 0x0U << RTC_CR_TAMP2FLT_Pos )
#define RTC_CR_TAMP2FLT_2               ( 0x1U << RTC_CR_TAMP2FLT_Pos )
#define RTC_CR_TAMP2FLT_4               ( 0x2U << RTC_CR_TAMP2FLT_Pos )
#define RTC_CR_TAMP2FLT_8               ( 0x3U << RTC_CR_TAMP2FLT_Pos )
#define RTC_CR_TAMP2FLTEN_Pos           ( 18U )
#define RTC_CR_TAMP2FLTEN_Msk           ( 0x1U << RTC_CR_TAMP2FLTEN_Pos)
#define RTC_CR_TAMP2FLTEN               ( RTC_CR_TAMP2FLTEN_Msk )
#define RTC_CR_TAMP2FCLR_Pos            ( 17U )
#define RTC_CR_TAMP2FCLR_Msk            ( 0x1U << RTC_CR_TAMP2FCLR_Pos )
#define RTC_CR_TAMP2FCLR                ( RTC_CR_TAMP2FCLR_Msk )
#define RTC_CR_TAMP2RCLR_Pos            ( 16U )
#define RTC_CR_TAMP2RCLR_Msk            ( 0x1U << RTC_CR_TAMP2RCLR_Pos )
#define RTC_CR_TAMP2RCLR                ( RTC_CR_TAMP2RCLR_Msk )
#define RTC_CR_TS1EDGE_Pos              ( 15U )
#define RTC_CR_TS1EDGE_Msk              ( 0x1U << RTC_CR_TS1EDGE_Pos )
#define RTC_CR_TS1EDGE                  ( RTC_CR_TS1EDGE_Msk )
#define RTC_CR_TAMP1FLT_Pos             ( 13U )
#define RTC_CR_TAMP1FLT_Msk             ( 0x3U << RTC_CR_TAMP1FLT_Pos )
#define RTC_CR_TAMP1FLT_1               ( 0x0U << RTC_CR_TAMP1FLT_Pos )
#define RTC_CR_TAMP1FLT_2               ( 0x1U << RTC_CR_TAMP1FLT_Pos )
#define RTC_CR_TAMP1FLT_4               ( 0x2U << RTC_CR_TAMP1FLT_Pos )
#define RTC_CR_TAMP1FLT_8               ( 0x3U << RTC_CR_TAMP1FLT_Pos )
#define RTC_CR_TAMP1FLTEN_Pos           ( 12U )
#define RTC_CR_TAMP1FLTEN_Msk           ( 0x1U << RTC_CR_TAMP1FLTEN_Pos)
#define RTC_CR_TAMP1FLTEN               ( RTC_CR_TAMP1FLTEN_Msk )
#define RTC_CR_ALM_MKSD_Pos             ( 11U )
#define RTC_CR_ALM_MKSD_Msk             ( 0x1U << RTC_CR_ALM_MKSD_Pos )
#define RTC_CR_ALM_MKSD                 ( RTC_CR_ALM_MKSD_Msk )
#define RTC_CR_ALM_MSKH_Pos             ( 10U )
#define RTC_CR_ALM_MSKH_Msk             ( 0x1U << RTC_CR_ALM_MSKH_Pos )
#define RTC_CR_ALM_MSKH                 ( RTC_CR_ALM_MSKH_Msk )
#define RTC_CR_ALM_MSKM_Pos             ( 9U )
#define RTC_CR_ALM_MSKM_Msk             ( 0x1U << RTC_CR_ALM_MSKM_Pos )
#define RTC_CR_ALM_MSKM                 ( RTC_CR_ALM_MSKM_Msk )
#define RTC_CR_TAMP1FCLR_Pos            ( 8U )
#define RTC_CR_TAMP1FCLR_Msk            ( 0x1U << RTC_CR_TAMP1FCLR_Pos )
#define RTC_CR_TAMP1FCLR                ( RTC_CR_TAMP1FCLR_Msk )
#define RTC_CR_TAMP1RCLR_Pos            ( 7U )
#define RTC_CR_TAMP1RCLR_Msk            ( 0x1U << RTC_CR_TAMP1RCLR_Pos )
#define RTC_CR_TAMP1RCLR                ( RTC_CR_TAMP1RCLR_Msk )
#define RTC_CR_TAMP2EN_Pos              ( 6U )
#define RTC_CR_TAMP2EN_Msk              ( 0x1U << RTC_CR_TAMP2EN_Pos )
#define RTC_CR_TAMP2EN                  ( RTC_CR_TAMP2EN_Msk )
#define RTC_CR_TAMP1EN_Pos              ( 5U )
#define RTC_CR_TAMP1EN_Msk              ( 0x1U << RTC_CR_TAMP1EN_Pos )
#define RTC_CR_TAMP1EN                  ( RTC_CR_TAMP1EN_Msk )
#define RTC_CR_ALM_EN_Pos               ( 4U )
#define RTC_CR_ALM_EN_Msk               ( 0x1U << RTC_CR_ALM_EN_Pos )
#define RTC_CR_ALM_EN                   ( RTC_CR_ALM_EN_Msk )
#define RTC_CR_FSEL_Pos                 ( 0U )
#define RTC_CR_FSEL_Msk                 ( 0xFU << RTC_CR_FSEL_Pos)

/****************  Bit definition for RTC ADJUST Register  ***********************/
#define RTC_ADJUST_ADJSIGN_Pos          ( 9U )
#define RTC_ADJUST_ADJSIGN_Msk          ( 0x1U << RTC_ADJUST_ADJSIGN_Pos )
#define RTC_ADJUST_ADJSIGN_INC          ( 0x0U << RTC_ADJUST_ADJSIGN_Pos )
#define RTC_ADJUST_ADJSIGN_DEC          ( 0x1U << RTC_ADJUST_ADJSIGN_Pos )


/**
  * @brief  RTC Configuration Structure definition
  */
typedef struct
{
    uint32_t ClockSource;           /*!< The RTC Clock Source to be configured.*/

    uint32_t Compensation;          /*!< The RTC Clock Compensation to be configured.*/

    uint32_t CompensationValue;     /*!< The RTC Clock Compensation Value to be configured.*/
}RTC_ConfigTypeDef;


/**
  * @brief  RTC Date structure definition
  */
typedef struct
{
    uint8_t Year;     /*!< Specifies the RTC Date Year.
                              This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x99 */

    uint8_t Month;    /*!< Specifies the RTC Date Month (in BCD format).*/

    uint8_t Date;     /*!< Specifies the RTC Date.
                              This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x31 */

    uint8_t WeekDay;  /*!< Specifies the RTC Date WeekDay.*/
}RTC_DateTypeDef;
/* Attention: Year、Month、Date、Week use BCD code */


/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
    uint8_t Hour;       /*!< Specifies the RTC Time Hour.
                                 This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x23 */

    uint8_t Minute;     /*!< Specifies the RTC Time Minute.
                                 This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59 */

    uint8_t Second;     /*!< Specifies the RTC Time Seconds.
                                 This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59 */
}RTC_TimeTypeDef;
/* Attention: Hour、Minute、Second use BCD code */


/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
    uint32_t u32_AlarmMode;         /*!< Specifies the RTC alarm Mode.*/

    uint32_t u32_AlarmInterrupt;    /*!< Specifies the RTC alarm interrupt Enable or Disable.*/

    uint32_t u32_DayMask;           /*!< Specifies the RTC alarm Day/Week Mask.*/
    
    uint32_t u32_HourMask;          /*!< Specifies the RTC alarm Hour Mask.*/
    
    uint32_t u32_MinMask;           /*!< Specifies the RTC alarm Min Mask.*/
    
    uint32_t u32_AlarmWeek;         /*!< Specifies the RTC alarm week select(Select WeekMode this parameter is valid).*/
    
    uint32_t u32_AlarmDay;          /*!< Specifies the RTC alarm day  select(Select DayMode this parameter is valid).
                                         This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x31 */
    
    uint32_t u32_Hours;             /*!< Specifies the RTC alarm Hour.
                                         This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x23 */

    uint32_t u32_Minutes;           /*!< Specifies the RTC alarm Minute.
                                         This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59 */

    uint32_t u32_Seconds;           /*!< Specifies the RTC alarm Seconds.
                                         This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59 */
}RTC_AlarmTypeDef;


/**
  * @brief  RTC Temper structure definition
  */
typedef struct 
{
    uint32_t u32_TemperEdge;      /*!< Specifies the RTC Temper edge select. */

    uint32_t u32_InterruptEN;     /*!< Specifies the RTC Temper interrupt enable.*/

    uint32_t u32_ClearBackup;     /*!< Specifies the RTC Temper clear backup register. */
                                       
    uint32_t u32_FilterClk;         /*!< Specifies the RTC Temper Filter Clock select. */

    uint32_t u32_Filter;          /*!< Specifies the RTC Temper Filter select.*/
}RTC_TemperTypeDef;


/**
  * @brief  RTC Wakeup Timer structure definition
  */
typedef struct 
{
	uint32_t u32_WuckSel;          /*!< The RTC WUCKSEL Value to be configured. 
                                             This parameter can be a value of @ref WUCKSEL_1Hz */
	
	uint32_t u32_InterruptEN;     /*!< Specifies the RTC Temper interrupt enable.
                                       This parameter can be a value of @ref RTC_WUTIMER Interrupt */
    uint32_t WakeUpCounter;

}RTC_WUTimerTypeDef;

/**
  * @brief  RTC Temper index definition
  */
typedef enum
{
    RTC_TEMPER_1,
    RTC_TEMPER_2,
}RTC_Temper_t;


/** @defgroup ClockSource
  * @{
  */
#define RTC_CLOCK_RC32K       (0x00000000)
#define RTC_CLOCK_XTL         (0x00000004)

/** @defgroup Clock_Compensation
  * @{
  */
#define COMPENSATION_INCREASE      (0x00000000)
#define COMPENSATION_DECREASE      (0x00000200)



/** @defgroup RTC_Month_Date_Definitions RTC Month Date Definitions
  * @{
  */
/* Coded in BCD format */
#define RTC_MONTH_JANUARY           (0x01)
#define RTC_MONTH_FEBRUARY          (0x02)
#define RTC_MONTH_MARCH             (0x03)
#define RTC_MONTH_APRIL             (0x04)
#define RTC_MONTH_MAY               (0x05)
#define RTC_MONTH_JUNE              (0x06)
#define RTC_MONTH_JULY              (0x07)
#define RTC_MONTH_AUGUST            (0x08)
#define RTC_MONTH_SEPTEMBER         (0x09)
#define RTC_MONTH_OCTOBER           (0x10)
#define RTC_MONTH_NOVEMBER          (0x11)
#define RTC_MONTH_DECEMBER          (0x12)



/** @defgroup RTC_WeekDay_Definitions RTC WeekDay Definitions
  * @{
  */
#define RTC_WEEKDAY_MONDAY          (0x01)
#define RTC_WEEKDAY_TUESDAY         (0x02)
#define RTC_WEEKDAY_WEDNESDAY       (0x03)
#define RTC_WEEKDAY_THURSDAY        (0x04)
#define RTC_WEEKDAY_FRIDAY          (0x05)
#define RTC_WEEKDAY_SATURDAY        (0x06)
#define RTC_WEEKDAY_SUNDAY          (0x07)

/** @defgroup RTC_AlarmInterrupt Definitions
  * @{
  */
#define RTC_ALARM_INT_ENABLE       (0x00000000)
#define RTC_ALARM_INT_DISABLE      (0x00000001)



/** @defgroup RTC_DayMask Definitions
  * @{
  */
#define RTC_ALARM_DAY_MASK_ENABLE       RTC_CR_ALM_MKSD
#define RTC_ALARM_DAY_MASK_DISABLE      (0x00000000)



/** @defgroup RTC_HourMask Definitions
  * @{
  */
#define RTC_ALARM_HOUR_MASK_ENABLE       RTC_CR_ALM_MSKH
#define RTC_ALARM_HOUR_MASK_DISABLE      (0x00000000)



/** @defgroup RTC_MinMask Definitions
  * @{
  */
#define RTC_ALARM_MIN_MASK_ENABLE       RTC_CR_ALM_MSKM
#define RTC_ALARM_MIN_MASK_DISABLE      (0x00000000)

/** @defgroup RTC_Alarm_WeekSelect Definitions
  * @{
  */
#define RTC_ALARM_WEEK_SUNDAY       (0x01000000)
#define RTC_ALARM_WEEK_MONDAY       (0x02000000)
#define RTC_ALARM_WEEK_TUESDAY      (0x04000000)
#define RTC_ALARM_WEEK_WEDNESDAY    (0x08000000)
#define RTC_ALARM_WEEK_THURSDAY     (0x10000000)
#define RTC_ALARM_WEEK_FRIDAY       (0x20000000)
#define RTC_ALARM_WEEK_SATURDAY     (0x40000000)


/** @defgroup RTC_Temper_edge Definitions
  * @{
  */
#define RTC_TEMP_EDGE_RISING       (0x00000000)
#define RTC_TEMP_EDGE_FALLING      (0x00000001)


/** @defgroup RTC_TemperInterrupt Definitions
  * @{
  */
#define RTC_TEMP_INT_DISABLE      (0x00000000)
#define RTC_TEMP_INT_ENABLE       (0x00000001)


/** @defgroup RTC_ClearBackup Definitions
  * @{
  */
#define RTC_TEMP_CLEAR_DISABLE       (0x00000000)
#define RTC_TEMP_CLEAR_ENABLE        (0x00000001)


/** @defgroup RTC_TemperFilter Clock Definitions
  * @{
  */
#define RTC_TEMP_FILTER_RTCCLK          (0x00000000)
#define RTC_TEMP_FILTER_512_RTCCLK      (0x00000001)

/** @defgroup RTC_TemperFilter Definitions
  * @{
  */
#define RTC_TEMP_FILTER_1_RTCCLK        (0x00000001)
#define RTC_TEMP_FILTER_2_RTCCLK        (0x00000002)
#define RTC_TEMP_FILTER_4_RTCCLK        (0x00000003)
#define RTC_TEMP_FILTER_8_RTCCLK        (0x00000004)

/** @defgroup  RTC Private Macros
  * @{
  */
#define IS_RTC_CLOCKSRC(__CLOCKSRC__)     (((__CLOCKSRC__) == RTC_CLOCK_RC32K) || \
                                           ((__CLOCKSRC__) == RTC_CLOCK_XTL))

#define IS_RTC_COMPENSATION(__COMPENSATION__)     (((__COMPENSATION__) == COMPENSATION_INCREASE) || \
                                                   ((__COMPENSATION__) == COMPENSATION_DECREASE))

#define IS_RTC_YEAR(__YEAR__)       ((__YEAR__) >= 0x00 && (__YEAR__) <= 0x99)

#define IS_RTC_MONTH(__MONTH__)     (((__MONTH__) == RTC_MONTH_JANUARY)   || \
                                     ((__MONTH__) == RTC_MONTH_FEBRUARY)  || \
                                     ((__MONTH__) == RTC_MONTH_MARCH)     || \
                                     ((__MONTH__) == RTC_MONTH_APRIL)     || \
                                     ((__MONTH__) == RTC_MONTH_MAY)       || \
                                     ((__MONTH__) == RTC_MONTH_JUNE)      || \
                                     ((__MONTH__) == RTC_MONTH_JULY)      || \
                                     ((__MONTH__) == RTC_MONTH_AUGUST)    || \
                                     ((__MONTH__) == RTC_MONTH_SEPTEMBER) || \
                                     ((__MONTH__) == RTC_MONTH_OCTOBER)   || \
                                     ((__MONTH__) == RTC_MONTH_NOVEMBER)  || \
                                     ((__MONTH__) == RTC_MONTH_DECEMBER))

#define IS_RTC_DAY(__DAY__)          ((__DAY__) >= 0x01 && (__DAY__) <= 0x31)

#define IS_RTC_WEEKDAY(__WEEKDAY__)   (((__WEEKDAY__) == RTC_WEEKDAY_MONDAY)    || \
                                       ((__WEEKDAY__) == RTC_WEEKDAY_TUESDAY)   || \
                                       ((__WEEKDAY__) == RTC_WEEKDAY_WEDNESDAY) || \
                                       ((__WEEKDAY__) == RTC_WEEKDAY_THURSDAY)  || \
                                       ((__WEEKDAY__) == RTC_WEEKDAY_FRIDAY)    || \
                                       ((__WEEKDAY__) == RTC_WEEKDAY_SATURDAY)  || \
                                       ((__WEEKDAY__) == RTC_WEEKDAY_SUNDAY))

#define IS_RTC_HOUR(__HOUR__)    ((__HOUR__) >= 0x00 && (__HOUR__) <= 0x23)

#define IS_RTC_MIN(__MIN__)      ((__MIN__) >= 0x00 && (__MIN__) <= 0x59)

#define IS_RTC_SEC(__SEC__)      ((__SEC__) >= 0x00 && (__SEC__) <= 0x59)


#define IS_RTC_ALARM_MODE(__MODE__)      (((__MODE__) == RTC_ALM_ALM_WDS_WEEK) || \
                                          ((__MODE__) == RTC_ALM_ALM_WDS_DAY))

#define IS_RTC_ALARM_INT(__INT__)        (((__INT__) == RTC_ALARM_INT_ENABLE) || \
                                          ((__INT__) == RTC_ALARM_INT_DISABLE))

#define IS_RTC_ALARM_DAY_MASK(__MASKD__)     (((__MASKD__) == RTC_ALARM_DAY_MASK_ENABLE) || \
                                              ((__MASKD__) == RTC_ALARM_DAY_MASK_DISABLE))
                                              
#define IS_RTC_ALARM_HOUR_MASK(__MASKH__)    (((__MASKH__) == RTC_ALARM_HOUR_MASK_ENABLE) || \
                                              ((__MASKH__) == RTC_ALARM_HOUR_MASK_DISABLE))

#define IS_RTC_ALARM_MIN_MASK(__MASKM__)     (((__MASKM__) == RTC_ALARM_MIN_MASK_ENABLE) || \
                                              ((__MASKM__) == RTC_ALARM_MIN_MASK_DISABLE))

#define IS_RTC_ALARM_WEEKDAY(__WEEKDAY__)    (((__WEEKDAY__) == RTC_ALARM_WEEK_SUNDAY)    || \
                                              ((__WEEKDAY__) == RTC_ALARM_WEEK_MONDAY)    || \
                                              ((__WEEKDAY__) == RTC_ALARM_WEEK_TUESDAY)   || \
                                              ((__WEEKDAY__) == RTC_ALARM_WEEK_WEDNESDAY) || \
                                              ((__WEEKDAY__) == RTC_ALARM_WEEK_THURSDAY)  || \
                                              ((__WEEKDAY__) == RTC_ALARM_WEEK_FRIDAY)    || \
                                              ((__WEEKDAY__) == RTC_ALARM_WEEK_SATURDAY)  || \
                                              ((__WEEKDAY__) >= 0x01000000 && (__WEEKDAY__) <= 0x7F000000))


#define IS_RTC_TEMP_EDGE(__EDGE__)           (((__EDGE__) == RTC_TEMP_EDGE_RISING) || \
                                              ((__EDGE__) == RTC_TEMP_EDGE_FALLING))

#define IS_RTC_TEMP_INT(__INT__)             (((__INT__) == RTC_TEMP_INT_ENABLE) || \
                                              ((__INT__) == RTC_TEMP_INT_DISABLE))

#define IS_RTC_TEMP_CLEAR_BACKUP(__CLEAR__)    (((__CLEAR__) == RTC_TEMP_CLEAR_DISABLE) || \
                                                ((__CLEAR__) == RTC_TEMP_CLEAR_ENABLE))

#define IS_RTC_TEMP_FILTER(__FILTER__)         (((__FILTER__) == RTC_TEMP_FILTER_1_RTCCLK)   || \
                                                ((__FILTER__) == RTC_TEMP_FILTER_2_RTCCLK)   || \
                                                ((__FILTER__) == RTC_TEMP_FILTER_4_RTCCLK)   || \
                                                ((__FILTER__) == RTC_TEMP_FILTER_8_RTCCLK))
/**
  * @}
  */

/* RTC stamp1 interrupt enable、disable */
#define __HAL_RTC_ENABLE_STAMP1_IT         (RTC->IE |= (RTC_IE_STP1RIE | RTC_IE_STP1FIE))
#define __HAL_RTC_DISABLE_STAMP1_IT        (RTC->IE &= ~(RTC_IE_STP1RIE | RTC_IE_STP1FIE))

/* RTC stamp2 interrupt enable、disable */
#define __HAL_RTC_ENABLE_STAMP2_IT         (RTC->IE |= (RTC_IE_STP2RIE | RTC_IE_STP2FIE))
#define __HAL_RTC_DISABLE_STAMP2_IT        (RTC->IE &= ~(RTC_IE_STP2RIE | RTC_IE_STP2FIE))

/* RTC 32S interrupt enable、disable */
#define __HAL_RTC_ENABLE_32S_IT            (RTC->IE |= RTC_IE_ADJ32)
#define __HAL_RTC_DISABLE_32S_IT           (RTC->IE &= ~RTC_IE_ADJ32)

/* RTC alarm interrupt enable、disable */
#define __HAL_RTC_ENABLE_ALM_IT            (RTC->IE |= RTC_IE_ALM)
#define __HAL_RTC_DISABLE_ALM_IT           (RTC->IE &= RTC_IE_ALM)

/* RTC sec interrupt enable、disable */
#define __HAL_RTC_ENABLE_SEC_IT            (RTC->IE |= RTC_IE_SEC)
#define __HAL_RTC_DISABLE_SEC_IT           (RTC->IE &= ~RTC_IE_SEC)

/* RTC Minute interrupt enable、disable */
#define __HAL_RTC_ENABLE_MIN_IT            (RTC->IE |= RTC_IE_MIN)
#define __HAL_RTC_DISABLE_MIN_IT           (RTC->IE &= ~RTC_IE_MIN)

/* RTC Hour interrupt enable、disable */
#define __HAL_RTC_ENABLE_HOUR_IT           (RTC->IE |= RTC_IE_HOUR)
#define __HAL_RTC_DISABLE_HOUR_IT          (RTC->IE &= ~RTC_IE_HOUR)

/* RTC Date interrupt enable、disable */
#define __HAL_RTC_ENABLE_DATE_IT           (RTC->IE |= RTC_IE_DATE)
#define __HAL_RTC_DISABLE_DATE_IT          (RTC->IE &= ~RTC_IE_DATE)

/* RTC Timer Wakeup interrupt enable、disable */
#define __HAL_RTC_ENABLE_WUTIE_IT           (RTC->IE |= RTC_IE_WUTIE)
#define __HAL_RTC_DISABLE_WUTIE_IT          (RTC->IE &= ~RTC_IE_WUTIE)


HAL_StatusTypeDef HAL_RTC_Config(RTC_ConfigTypeDef *hrtc);

void HAL_RTC_SetTime(RTC_TimeTypeDef *fp_Time);

void HAL_RTC_GetTime(RTC_TimeTypeDef *fp_Time);

void HAL_RTC_SetDate(RTC_DateTypeDef *fp_Date);

void HAL_RTC_GetDate(RTC_DateTypeDef *fp_Date);

void HAL_RTC_AlarmConfig(RTC_AlarmTypeDef *fp_Alarm);

void HAL_RTC_AlarmEnable(void);

void HAL_RTC_AlarmDisable(void);

void HAL_RTC_Tamper(RTC_Temper_t fe_Temper, RTC_TemperTypeDef *fp_Temper);

void HAL_RTC_TamperEnable(RTC_Temper_t fe_Temper);

void HAL_RTC_TamperDisable(RTC_Temper_t fe_Temper);

void HAL_RTC_SetWakeUpTimer(RTC_WUTimerTypeDef *hrtc);

#endif
