/*
  ******************************************************************************
  * @file    HAL_ADC.h
  * @version V1.0.0
  * @date    2020
  * @brief   Header file of ADC HAL module.
  ******************************************************************************
*/
#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__


#include "hal.h"

/***************  Bits definition for ADC_SR register  ***********************/

#define ADC_SR_AFEBUSY_Pos                      ( 9U )
#define ADC_SR_AFEBUSY_Msk                      ( 0x1UL << ADC_SR_AFEBUSY_Pos )
#define ADC_SR_AFEBUSY                          ( ADC_SR_AFEBUSY_Msk )

#define ADC_SR_AFEVLD_Pos                       ( 8U )
#define ADC_SR_AFEVLD_Msk                       ( 0x1UL << ADC_SR_AFEVLD_Pos )
#define ADC_SR_AFEVLD                           ( ADC_SR_AFEVLD_Msk )

#define ADC_SR_AWD_Pos                          ( 7U )
#define ADC_SR_AWD_Msk                          ( 0x1UL << ADC_SR_AWD_Pos )
#define ADC_SR_AWD                              ( ADC_SR_AWD_Msk )

#define ADC_SR_JEOG_Pos                         ( 6U )
#define ADC_SR_JEOG_Msk                         ( 0x1UL << ADC_SR_JEOG_Pos )
#define ADC_SR_JEOG                             ( ADC_SR_JEOG_Msk )

#define ADC_SR_JEOC_Pos                         ( 5U )
#define ADC_SR_JEOC_Msk                         ( 0x1UL << ADC_SR_JEOC_Pos )
#define ADC_SR_JEOC                             ( ADC_SR_JEOC_Msk )

#define ADC_SR_OVERF_Pos                        ( 4U )
#define ADC_SR_OVERF_Msk                        ( 0x1UL << ADC_SR_OVERF_Pos )
#define ADC_SR_OVERF                            ( ADC_SR_OVERF_Msk )

#define ADC_SR_EOG_Pos                          ( 3U )
#define ADC_SR_EOG_Msk                          ( 0x1UL << ADC_SR_EOG_Pos )
#define ADC_SR_EOG                              ( ADC_SR_EOG_Msk )

#define ADC_SR_EOC_Pos                          ( 2U )
#define ADC_SR_EOC_Msk                          ( 0x1UL << ADC_SR_EOC_Pos )
#define ADC_SR_EOC                              ( ADC_SR_EOC_Msk )

#define ADC_SR_EOSMP_Pos                        ( 1U )
#define ADC_SR_EOSMP_Msk                        ( 0x1UL << ADC_SR_EOSMP_Pos )
#define ADC_SR_EOSMP                            ( ADC_SR_EOSMP_Msk )

#define ADC_SR_ADRDY_Pos                        ( 0U )
#define ADC_SR_ADRDY_Msk                        ( 0x1UL << ADC_SR_ADRDY_Pos )
#define ADC_SR_ADRDY                            ( ADC_SR_ADRDY_Msk )

/***************  Bits definition for ADC_IE register  ***********************/

#define ADC_IE_AWDIE_Pos                        ( 7U )
#define ADC_IE_AWDIE_Msk                        ( 0x1UL << ADC_IE_AWDIE_Pos )
#define ADC_IE_AWDIE                            ( ADC_IE_AWDIE_Msk )

#define ADC_IE_JEOGIE_Pos                       ( 6U )
#define ADC_IE_JEOGIE_Msk                       ( 0x1UL << ADC_IE_JEOGIE_Pos )
#define ADC_IE_JEOGIE                           ( ADC_IE_JEOGIE_Msk )

#define ADC_IE_JEOCIE_Pos                       ( 5U )
#define ADC_IE_JEOCIE_Msk                       ( 0x1UL << ADC_IE_JEOCIE_Pos )
#define ADC_IE_JEOCIE                           ( ADC_IE_JEOCIE_Msk )

#define ADC_IE_OVERFIE_Pos                      ( 4U )
#define ADC_IE_OVERFIE_Msk                      ( 0x1UL << ADC_IE_OVERFIE_Pos )
#define ADC_IE_OVERFIE                          ( ADC_IE_OVERFIE_Msk )

#define ADC_IE_EOGIE_Pos                        ( 3U )
#define ADC_IE_EOGIE_Msk                        ( 0x1UL << ADC_IE_EOGIE_Pos )
#define ADC_IE_EOGIE                            ( ADC_IE_EOGIE_Msk )

#define ADC_IE_EOCIE_Pos                        ( 2U )
#define ADC_IE_EOCIE_Msk                        ( 0x1UL << ADC_IE_EOCIE_Pos )
#define ADC_IE_EOCIE                            ( ADC_IE_EOCIE_Msk )

#define ADC_IE_EOSMPIE_Pos                      ( 1U )
#define ADC_IE_EOSMPIE_Msk                      ( 0x1UL << ADC_IE_EOSMPIE_Pos )
#define ADC_IE_EOSMPIE                          ( ADC_IE_EOSMPIE_Msk )

/***************  Bits definition for ADC_CR1 register  **********************/

#define ADC_CR1_DISCNUM_Pos                     ( 28U )
#define ADC_CR1_DISCNUM_Msk                     ( 0x7UL << ADC_CR1_DISCNUM_Pos )
#define ADC_CR1_DISCNUM                         ( ADC_CR1_DISCNUM_Msk )
#define ADC_CR1_DISCNUM_0                       ( 0x1UL << ADC_CR1_DISCNUM_Msk )
#define ADC_CR1_DISCNUM_1                       ( 0x2UL << ADC_CR1_DISCNUM_Msk )
#define ADC_CR1_DISCNUM_2                       ( 0x4UL << ADC_CR1_DISCNUM_Msk )

#define ADC_CR1_JDISCEN_Pos                     ( 27U )
#define ADC_CR1_JDISCEN_Msk                     ( 0x1UL << ADC_CR1_JDISCEN_Pos )
#define ADC_CR1_JDISCEN                         ( ADC_CR1_JDISCEN_Msk )

#define ADC_CR1_DISCEN_Pos                      ( 26U )
#define ADC_CR1_DISCEN_Msk                      ( 0x1UL << ADC_CR1_DISCEN_Pos )
#define ADC_CR1_DISCEN                          ( ADC_CR1_DISCEN_Msk )

#define ADC_CR1_JAUTO_Pos                       ( 25U )
#define ADC_CR1_JAUTO_Msk                       ( 0x1UL << ADC_CR1_JAUTO_Pos )
#define ADC_CR1_JAUTO                           ( ADC_CR1_JAUTO_Msk )

#define ADC_CR1_CONT_Pos                        ( 24U )
#define ADC_CR1_CONT_Msk                        ( 0x1UL << ADC_CR1_CONT_Pos )
#define ADC_CR1_CONT                            ( ADC_CR1_CONT_Msk )

#define ADC_CR1_SWSTART_Pos                     ( 23U )
#define ADC_CR1_SWSTART_Msk                     ( 0x1UL << ADC_CR1_SWSTART_Pos )
#define ADC_CR1_SWSTART                         ( ADC_CR1_SWSTART_Msk )

#define ADC_CR1_JSWSTART_Pos                    ( 22U )
#define ADC_CR1_JSWSTART_Msk                    ( 0x1UL << ADC_CR1_JSWSTART_Pos )
#define ADC_CR1_JSWSTART                        ( ADC_CR1_JSWSTART_Msk )

#define ADC_CR1_EXTSEL_Pos                      ( 16U )
#define ADC_CR1_EXTSEL_Msk                      ( 0x1FUL << ADC_CR1_EXTSEL_Pos )
#define ADC_CR1_EXTSEL                          ( ADC_CR1_EXTSEL_Msk )
#define ADC_CR1_EXTSEL_0                        ( 0x1UL << ADC_CR1_EXTSEL_Msk )
#define ADC_CR1_EXTSEL_1                        ( 0x2UL << ADC_CR1_EXTSEL_Msk )
#define ADC_CR1_EXTSEL_2                        ( 0x4UL << ADC_CR1_EXTSEL_Msk )
#define ADC_CR1_EXTSEL_3                        ( 0x8UL << ADC_CR1_EXTSEL_Msk )
#define ADC_CR1_EXTSEL_4                        ( 0x10UL << ADC_CR1_EXTSEL_Msk )

#define ADC_CR1_EXTEN_Pos                       ( 14U )
#define ADC_CR1_EXTEN_Msk                       ( 0x3UL << ADC_CR1_EXTEN_Pos )
#define ADC_CR1_EXTEN                           ( ADC_CR1_EXTEN_Msk )
#define ADC_CR1_EXTEN_0                         ( 0x1UL << ADC_CR1_EXTEN_Msk )
#define ADC_CR1_EXTEN_1                         ( 0x2UL << ADC_CR1_EXTEN_Msk )

#define ADC_CR1_DMA_Pos                         ( 13U )
#define ADC_CR1_DMA_Msk                         ( 0x1UL << ADC_CR1_DMA_Pos )
#define ADC_CR1_DMA                             ( ADC_CR1_DMA_Msk )

#define ADC_CR1_AWDEN_Pos                       ( 12U )
#define ADC_CR1_AWDEN_Msk                       ( 0x1UL << ADC_CR1_AWDEN_Pos )
#define ADC_CR1_AWDEN                           ( ADC_CR1_AWDEN_Msk )

#define ADC_CR1_JAWDEN_Pos                      ( 11U )
#define ADC_CR1_JAWDEN_Msk                      ( 0x1UL << ADC_CR1_JAWDEN_Pos )
#define ADC_CR1_JAWDEN                          ( ADC_CR1_JAWDEN_Msk )

#define ADC_CR1_AWDSGL_Pos                      ( 10U )
#define ADC_CR1_AWDSGL_Msk                      ( 0x1UL << ADC_CR1_AWDSGL_Pos )
#define ADC_CR1_AWDSGL                          ( ADC_CR1_AWDSGL_Msk )

#define ADC_CR1_AWDJCH_Pos                      ( 5U )
#define ADC_CR1_AWDJCH_Msk                      ( 0x1FUL << ADC_CR1_AWDJCH_Pos )
#define ADC_CR1_AWDJCH                          ( ADC_CR1_AWDJCH_Msk )
#define ADC_CR1_AWDJCH_0                        ( 0x1UL << ADC_CR1_AWDJCH_Msk )
#define ADC_CR1_AWDJCH_1                        ( 0x2UL << ADC_CR1_AWDJCH_Msk )
#define ADC_CR1_AWDJCH_2                        ( 0x4UL << ADC_CR1_AWDJCH_Msk )
#define ADC_CR1_AWDJCH_3                        ( 0x8UL << ADC_CR1_AWDJCH_Msk )
#define ADC_CR1_AWDJCH_4                        ( 0x10UL << ADC_CR1_AWDJCH_Msk )

#define ADC_CR1_AWDCH_Pos                       ( 0U )
#define ADC_CR1_AWDCH_Msk                       ( 0x1FUL << ADC_CR1_AWDCH_Pos )
#define ADC_CR1_AWDCH                           ( ADC_CR1_AWDCH_Msk )
#define ADC_CR1_AWDCH_0                         ( 0x1UL << ADC_CR1_AWDCH_Msk )
#define ADC_CR1_AWDCH_1                         ( 0x2UL << ADC_CR1_AWDCH_Msk )
#define ADC_CR1_AWDCH_2                         ( 0x4UL << ADC_CR1_AWDCH_Msk )
#define ADC_CR1_AWDCH_3                         ( 0x8UL << ADC_CR1_AWDCH_Msk )
#define ADC_CR1_AWDCH_4                         ( 0x10UL << ADC_CR1_AWDCH_Msk )


/***************  Bits definition for ADC_CR2 register  **********************/

#define ADC_CR2_FASTMOD_Pos                     ( 27U )
#define ADC_CR2_FASTMOD_Msk                     ( 0x1UL << ADC_CR2_FASTMOD_Pos )
#define ADC_CR2_FASTMOD                         ( ADC_CR2_FASTMOD_Msk )

#define ADC_CR2_AFERSTN_Pos                     ( 26U )
#define ADC_CR2_AFERSTN_Msk                     ( 0x1UL << ADC_CR2_AFERSTN_Pos )
#define ADC_CR2_AFERSTN                         ( ADC_CR2_AFERSTN_Msk )

#define ADC_CR2_JOVSE_Pos                       ( 25U )
#define ADC_CR2_JOVSE_Msk                       ( 0x1UL << ADC_CR2_JOVSE_Pos )
#define ADC_CR2_JOVSE                           ( ADC_CR2_JOVSE_Msk )

#define ADC_CR2_TROVS_Pos                       ( 24U )
#define ADC_CR2_TROVS_Msk                       ( 0x1UL << ADC_CR2_TROVS_Pos )
#define ADC_CR2_TROVS                           ( ADC_CR2_TROVS_Msk )

#define ADC_CR2_OVSS_Pos                        ( 20U )
#define ADC_CR2_OVSS_Msk                        ( 0xFUL << ADC_CR2_OVSS_Pos )
#define ADC_CR2_OVSS                            ( ADC_CR2_OVSS_Msk )
#define ADC_CR2_OVSS_0                          ( 0x1UL << ADC_CR2_OVSS_Msk )
#define ADC_CR2_OVSS_1                          ( 0x2UL << ADC_CR2_OVSS_Msk )
#define ADC_CR2_OVSS_2                          ( 0x4UL << ADC_CR2_OVSS_Msk )
#define ADC_CR2_OVSS_3                          ( 0x8UL << ADC_CR2_OVSS_Msk )

#define ADC_CR2_OVSR_Pos                        ( 17U )
#define ADC_CR2_OVSR_Msk                        ( 0x7UL << ADC_CR2_OVSR_Pos )
#define ADC_CR2_OVSR                            ( ADC_CR2_OVSR_Msk )
#define ADC_CR2_OVSR_0                          ( 0x1UL << ADC_CR2_OVSR_Msk )
#define ADC_CR2_OVSR_1                          ( 0x2UL << ADC_CR2_OVSR_Msk )
#define ADC_CR2_OVSR_2                          ( 0x4UL << ADC_CR2_OVSR_Msk )

#define ADC_CR2_OVSE_Pos                        ( 16U )
#define ADC_CR2_OVSE_Msk                        ( 0x1UL << ADC_CR2_OVSE_Pos )
#define ADC_CR2_OVSE                            ( ADC_CR2_OVSE_Msk )

#define ADC_CR2_RES_Pos                         ( 4U )
#define ADC_CR2_RES_Msk                         ( 0x3UL << ADC_CR2_RES_Pos )
#define ADC_CR2_RES                             ( ADC_CR2_RES_Msk )
#define ADC_CR2_RES_0                           ( 0x1UL << ADC_CR2_RES_Msk )
#define ADC_CR2_RES_1                           ( 0x2UL << ADC_CR2_RES_Msk )

#define ADC_CR2_ALIGN_Pos                       ( 3U )
#define ADC_CR2_ALIGN_Msk                       ( 0x1UL << ADC_CR2_ALIGN_Pos )
#define ADC_CR2_ALIGN                           ( ADC_CR2_ALIGN_Msk )

#define ADC_CR2_ADCSTP_Pos                      ( 2U )
#define ADC_CR2_ADCSTP_Msk                      ( 0x1UL << ADC_CR2_ADCSTP_Pos )
#define ADC_CR2_ADCSTP                          ( ADC_CR2_ADCSTP_Msk )

#define ADC_CR2_OVRMOD_Pos                      ( 1U )
#define ADC_CR2_OVRMOD_Msk                      ( 0x1UL << ADC_CR2_OVRMOD_Pos )
#define ADC_CR2_OVRMOD                          ( ADC_CR2_OVRMOD_Msk )

#define ADC_CR2_ADCEN_Pos                       ( 0U )
#define ADC_CR2_ADCEN_Msk                       ( 0x1UL << ADC_CR2_ADCEN_Pos )
#define ADC_CR2_ADCEN                           ( ADC_CR2_ADCEN_Msk )


/***************  Bits definition for ADC_SMPR1 register  ********************/

#define ADC_SMPR1_SMP7_Pos                      ( 28U )
#define ADC_SMPR1_SMP7_Msk                      ( 0xFUL << ADC_SMPR1_SMP7_Pos )
#define ADC_SMPR1_SMP7                          ( ADC_SMPR1_SMP7_Msk )
#define ADC_SMPR1_SMP7_0                        ( 0x1UL << ADC_SMPR1_SMP7_Msk )
#define ADC_SMPR1_SMP7_1                        ( 0x2UL << ADC_SMPR1_SMP7_Msk )
#define ADC_SMPR1_SMP7_2                        ( 0x4UL << ADC_SMPR1_SMP7_Msk )
#define ADC_SMPR1_SMP7_3                        ( 0x8UL << ADC_SMPR1_SMP7_Msk )

#define ADC_SMPR1_SMP6_Pos                      ( 24U )
#define ADC_SMPR1_SMP6_Msk                      ( 0xFUL << ADC_SMPR1_SMP6_Pos )
#define ADC_SMPR1_SMP6                          ( ADC_SMPR1_SMP6_Msk )
#define ADC_SMPR1_SMP6_0                        ( 0x1UL << ADC_SMPR1_SMP6_Msk )
#define ADC_SMPR1_SMP6_1                        ( 0x2UL << ADC_SMPR1_SMP6_Msk )
#define ADC_SMPR1_SMP6_2                        ( 0x4UL << ADC_SMPR1_SMP6_Msk )
#define ADC_SMPR1_SMP6_3                        ( 0x8UL << ADC_SMPR1_SMP6_Msk )

#define ADC_SMPR1_SMP5_Pos                      ( 20U )
#define ADC_SMPR1_SMP5_Msk                      ( 0xFUL << ADC_SMPR1_SMP5_Pos )
#define ADC_SMPR1_SMP5                          ( ADC_SMPR1_SMP5_Msk )
#define ADC_SMPR1_SMP5_0                        ( 0x1UL << ADC_SMPR1_SMP5_Msk )
#define ADC_SMPR1_SMP5_1                        ( 0x2UL << ADC_SMPR1_SMP5_Msk )
#define ADC_SMPR1_SMP5_2                        ( 0x4UL << ADC_SMPR1_SMP5_Msk )
#define ADC_SMPR1_SMP5_3                        ( 0x8UL << ADC_SMPR1_SMP5_Msk )

#define ADC_SMPR1_SMP4_Pos                      ( 16U )
#define ADC_SMPR1_SMP4_Msk                      ( 0xFUL << ADC_SMPR1_SMP4_Pos )
#define ADC_SMPR1_SMP4                          ( ADC_SMPR1_SMP4_Msk )
#define ADC_SMPR1_SMP4_0                        ( 0x1UL << ADC_SMPR1_SMP4_Msk )
#define ADC_SMPR1_SMP4_1                        ( 0x2UL << ADC_SMPR1_SMP4_Msk )
#define ADC_SMPR1_SMP4_2                        ( 0x4UL << ADC_SMPR1_SMP4_Msk )
#define ADC_SMPR1_SMP4_3                        ( 0x8UL << ADC_SMPR1_SMP4_Msk )

#define ADC_SMPR1_SMP3_Pos                      ( 12U )
#define ADC_SMPR1_SMP3_Msk                      ( 0xFUL << ADC_SMPR1_SMP3_Pos )
#define ADC_SMPR1_SMP3                          ( ADC_SMPR1_SMP3_Msk )
#define ADC_SMPR1_SMP3_0                        ( 0x1UL << ADC_SMPR1_SMP3_Msk )
#define ADC_SMPR1_SMP3_1                        ( 0x2UL << ADC_SMPR1_SMP3_Msk )
#define ADC_SMPR1_SMP3_2                        ( 0x4UL << ADC_SMPR1_SMP3_Msk )
#define ADC_SMPR1_SMP3_3                        ( 0x8UL << ADC_SMPR1_SMP3_Msk )

#define ADC_SMPR1_SMP2_Pos                      ( 8U )
#define ADC_SMPR1_SMP2_Msk                      ( 0xFUL << ADC_SMPR1_SMP2_Pos )
#define ADC_SMPR1_SMP2                          ( ADC_SMPR1_SMP2_Msk )
#define ADC_SMPR1_SMP2_0                        ( 0x1UL << ADC_SMPR1_SMP2_Msk )
#define ADC_SMPR1_SMP2_1                        ( 0x2UL << ADC_SMPR1_SMP2_Msk )
#define ADC_SMPR1_SMP2_2                        ( 0x4UL << ADC_SMPR1_SMP2_Msk )
#define ADC_SMPR1_SMP2_3                        ( 0x8UL << ADC_SMPR1_SMP2_Msk )

#define ADC_SMPR1_SMP1_Pos                      ( 4U )
#define ADC_SMPR1_SMP1_Msk                      ( 0xFUL << ADC_SMPR1_SMP1_Pos )
#define ADC_SMPR1_SMP1                          ( ADC_SMPR1_SMP1_Msk )
#define ADC_SMPR1_SMP1_0                        ( 0x1UL << ADC_SMPR1_SMP1_Msk )
#define ADC_SMPR1_SMP1_1                        ( 0x2UL << ADC_SMPR1_SMP1_Msk )
#define ADC_SMPR1_SMP1_2                        ( 0x4UL << ADC_SMPR1_SMP1_Msk )
#define ADC_SMPR1_SMP1_3                        ( 0x8UL << ADC_SMPR1_SMP1_Msk )

#define ADC_SMPR1_SMP0_Pos                      ( 0U )
#define ADC_SMPR1_SMP0_Msk                      ( 0xFUL << ADC_SMPR1_SMP0_Pos )
#define ADC_SMPR1_SMP0                          ( ADC_SMPR1_SMP0_Msk )
#define ADC_SMPR1_SMP0_0                        ( 0x1UL << ADC_SMPR1_SMP0_Msk )
#define ADC_SMPR1_SMP0_1                        ( 0x2UL << ADC_SMPR1_SMP0_Msk )
#define ADC_SMPR1_SMP0_2                        ( 0x4UL << ADC_SMPR1_SMP0_Msk )
#define ADC_SMPR1_SMP0_3                        ( 0x8UL << ADC_SMPR1_SMP0_Msk )


/***************  Bits definition for ADC_SMPR2 register  ********************/

#define ADC_SMPR2_SMP15_Pos                     ( 28U )
#define ADC_SMPR2_SMP15_Msk                     ( 0xFUL << ADC_SMPR2_SMP15_Pos )
#define ADC_SMPR2_SMP15                         ( ADC_SMPR2_SMP15_Msk )
#define ADC_SMPR2_SMP15_0                       ( 0x1UL << ADC_SMPR2_SMP15_Msk )
#define ADC_SMPR2_SMP15_1                       ( 0x2UL << ADC_SMPR2_SMP15_Msk )
#define ADC_SMPR2_SMP15_2                       ( 0x4UL << ADC_SMPR2_SMP15_Msk )
#define ADC_SMPR2_SMP15_3                       ( 0x8UL << ADC_SMPR2_SMP15_Msk )

#define ADC_SMPR2_SMP14_Pos                     ( 24U )
#define ADC_SMPR2_SMP14_Msk                     ( 0xFUL << ADC_SMPR2_SMP14_Pos )
#define ADC_SMPR2_SMP14                         ( ADC_SMPR2_SMP14_Msk )
#define ADC_SMPR2_SMP14_0                       ( 0x1UL << ADC_SMPR2_SMP14_Msk )
#define ADC_SMPR2_SMP14_1                       ( 0x2UL << ADC_SMPR2_SMP14_Msk )
#define ADC_SMPR2_SMP14_2                       ( 0x4UL << ADC_SMPR2_SMP14_Msk )
#define ADC_SMPR2_SMP14_3                       ( 0x8UL << ADC_SMPR2_SMP14_Msk )

#define ADC_SMPR2_SMP13_Pos                     ( 20U )
#define ADC_SMPR2_SMP13_Msk                     ( 0xFUL << ADC_SMPR2_SMP13_Pos )
#define ADC_SMPR2_SMP13                         ( ADC_SMPR2_SMP13_Msk )
#define ADC_SMPR2_SMP13_0                       ( 0x1UL << ADC_SMPR2_SMP13_Msk )
#define ADC_SMPR2_SMP13_1                       ( 0x2UL << ADC_SMPR2_SMP13_Msk )
#define ADC_SMPR2_SMP13_2                       ( 0x4UL << ADC_SMPR2_SMP13_Msk )
#define ADC_SMPR2_SMP13_3                       ( 0x8UL << ADC_SMPR2_SMP13_Msk )

#define ADC_SMPR2_SMP12_Pos                     ( 16U )
#define ADC_SMPR2_SMP12_Msk                     ( 0xFUL << ADC_SMPR2_SMP12_Pos )
#define ADC_SMPR2_SMP12                         ( ADC_SMPR2_SMP12_Msk )
#define ADC_SMPR2_SMP12_0                       ( 0x1UL << ADC_SMPR2_SMP12_Msk )
#define ADC_SMPR2_SMP12_1                       ( 0x2UL << ADC_SMPR2_SMP12_Msk )
#define ADC_SMPR2_SMP12_2                       ( 0x4UL << ADC_SMPR2_SMP12_Msk )
#define ADC_SMPR2_SMP12_3                       ( 0x8UL << ADC_SMPR2_SMP12_Msk )

#define ADC_SMPR2_SMP11_Pos                     ( 12U )
#define ADC_SMPR2_SMP11_Msk                     ( 0xFUL << ADC_SMPR2_SMP11_Pos )
#define ADC_SMPR2_SMP11                         ( ADC_SMPR2_SMP11_Msk )
#define ADC_SMPR2_SMP11_0                       ( 0x1UL << ADC_SMPR2_SMP11_Msk )
#define ADC_SMPR2_SMP11_1                       ( 0x2UL << ADC_SMPR2_SMP11_Msk )
#define ADC_SMPR2_SMP11_2                       ( 0x4UL << ADC_SMPR2_SMP11_Msk )
#define ADC_SMPR2_SMP11_3                       ( 0x8UL << ADC_SMPR2_SMP11_Msk )

#define ADC_SMPR2_SMP10_Pos                     ( 8U )
#define ADC_SMPR2_SMP10_Msk                     ( 0xFUL << ADC_SMPR2_SMP10_Pos )
#define ADC_SMPR2_SMP10                         ( ADC_SMPR2_SMP10_Msk )
#define ADC_SMPR2_SMP10_0                       ( 0x1UL << ADC_SMPR2_SMP10_Msk )
#define ADC_SMPR2_SMP10_1                       ( 0x2UL << ADC_SMPR2_SMP10_Msk )
#define ADC_SMPR2_SMP10_2                       ( 0x4UL << ADC_SMPR2_SMP10_Msk )
#define ADC_SMPR2_SMP10_3                       ( 0x8UL << ADC_SMPR2_SMP10_Msk )

#define ADC_SMPR2_SMP9_Pos                      ( 4U )
#define ADC_SMPR2_SMP9_Msk                      ( 0xFUL << ADC_SMPR2_SMP9_Pos )
#define ADC_SMPR2_SMP9                          ( ADC_SMPR2_SMP9_Msk )
#define ADC_SMPR2_SMP9_0                        ( 0x1UL << ADC_SMPR2_SMP9_Msk )
#define ADC_SMPR2_SMP9_1                        ( 0x2UL << ADC_SMPR2_SMP9_Msk )
#define ADC_SMPR2_SMP9_2                        ( 0x4UL << ADC_SMPR2_SMP9_Msk )
#define ADC_SMPR2_SMP9_3                        ( 0x8UL << ADC_SMPR2_SMP9_Msk )

#define ADC_SMPR2_SMP8_Pos                      ( 0U )
#define ADC_SMPR2_SMP8_Msk                      ( 0xFUL << ADC_SMPR2_SMP8_Pos )
#define ADC_SMPR2_SMP8                          ( ADC_SMPR2_SMP8_Msk )
#define ADC_SMPR2_SMP8_0                        ( 0x1UL << ADC_SMPR2_SMP8_Msk )
#define ADC_SMPR2_SMP8_1                        ( 0x2UL << ADC_SMPR2_SMP8_Msk )
#define ADC_SMPR2_SMP8_2                        ( 0x4UL << ADC_SMPR2_SMP8_Msk )
#define ADC_SMPR2_SMP8_3                        ( 0x8UL << ADC_SMPR2_SMP8_Msk )


/***************  Bits definition for ADC_SMPR3 register  ********************/

#define ADC_SMPR3_CONVPLUS_Pos                  ( 20U )
#define ADC_SMPR3_CONVPLUS_Msk                  ( 0x3UL << ADC_SMPR3_CONVPLUS_Pos )
#define ADC_SMPR3_CONVPLUS                      ( ADC_SMPR3_CONVPLUS_Msk )
#define ADC_SMPR3_CONVPLUS_0                    ( 0x1UL << ADC_SMPR3_CONVPLUS_Msk )
#define ADC_SMPR3_CONVPLUS_1                    ( 0x2UL << ADC_SMPR3_CONVPLUS_Msk )

#define ADC_SMPR3_SMP20_Pos                     ( 16U )
#define ADC_SMPR3_SMP20_Msk                     ( 0xFUL << ADC_SMPR3_SMP20_Pos )
#define ADC_SMPR3_SMP20                         ( ADC_SMPR3_SMP20_Msk )
#define ADC_SMPR3_SMP20_0                       ( 0x1UL << ADC_SMPR3_SMP20_Msk )
#define ADC_SMPR3_SMP20_1                       ( 0x2UL << ADC_SMPR3_SMP20_Msk )
#define ADC_SMPR3_SMP20_2                       ( 0x4UL << ADC_SMPR3_SMP20_Msk )
#define ADC_SMPR3_SMP20_3                       ( 0x8UL << ADC_SMPR3_SMP20_Msk )

#define ADC_SMPR3_SMP19_Pos                     ( 12U )
#define ADC_SMPR3_SMP19_Msk                     ( 0xFUL << ADC_SMPR3_SMP19_Pos )
#define ADC_SMPR3_SMP19                         ( ADC_SMPR3_SMP19_Msk )
#define ADC_SMPR3_SMP19_0                       ( 0x1UL << ADC_SMPR3_SMP19_Msk )
#define ADC_SMPR3_SMP19_1                       ( 0x2UL << ADC_SMPR3_SMP19_Msk )
#define ADC_SMPR3_SMP19_2                       ( 0x4UL << ADC_SMPR3_SMP19_Msk )
#define ADC_SMPR3_SMP19_3                       ( 0x8UL << ADC_SMPR3_SMP19_Msk )

#define ADC_SMPR3_SMP18_Pos                     ( 8U )
#define ADC_SMPR3_SMP18_Msk                     ( 0xFUL << ADC_SMPR3_SMP18_Pos )
#define ADC_SMPR3_SMP18                         ( ADC_SMPR3_SMP18_Msk )
#define ADC_SMPR3_SMP18_0                       ( 0x1UL << ADC_SMPR3_SMP18_Msk )
#define ADC_SMPR3_SMP18_1                       ( 0x2UL << ADC_SMPR3_SMP18_Msk )
#define ADC_SMPR3_SMP18_2                       ( 0x4UL << ADC_SMPR3_SMP18_Msk )
#define ADC_SMPR3_SMP18_3                       ( 0x8UL << ADC_SMPR3_SMP18_Msk )

#define ADC_SMPR3_SMP17_Pos                     ( 4U )
#define ADC_SMPR3_SMP17_Msk                     ( 0xFUL << ADC_SMPR3_SMP17_Pos )
#define ADC_SMPR3_SMP17                         ( ADC_SMPR3_SMP17_Msk )
#define ADC_SMPR3_SMP17_0                       ( 0x1UL << ADC_SMPR3_SMP17_Msk )
#define ADC_SMPR3_SMP17_1                       ( 0x2UL << ADC_SMPR3_SMP17_Msk )
#define ADC_SMPR3_SMP17_2                       ( 0x4UL << ADC_SMPR3_SMP17_Msk )
#define ADC_SMPR3_SMP17_3                       ( 0x8UL << ADC_SMPR3_SMP17_Msk )

#define ADC_SMPR3_SMP16_Pos                     ( 0U )
#define ADC_SMPR3_SMP16_Msk                     ( 0xFUL << ADC_SMPR3_SMP16_Pos )
#define ADC_SMPR3_SMP16                         ( ADC_SMPR3_SMP16_Msk )
#define ADC_SMPR3_SMP16_0                       ( 0x1UL << ADC_SMPR3_SMP16_Msk )
#define ADC_SMPR3_SMP16_1                       ( 0x2UL << ADC_SMPR3_SMP16_Msk )
#define ADC_SMPR3_SMP16_2                       ( 0x4UL << ADC_SMPR3_SMP16_Msk )
#define ADC_SMPR3_SMP16_3                       ( 0x8UL << ADC_SMPR3_SMP16_Msk )


/***************  Bits definition for ADC_HTR register  **********************/

#define ADC_HTR_DHT_Pos                         ( 16U )
#define ADC_HTR_DHT_Msk                         ( 0xFFFUL << ADC_HTR_DHT_Pos )
#define ADC_HTR_DHT                             ( ADC_HTR_DHT_Msk )

#define ADC_HTR_HT_Pos                          ( 0U )
#define ADC_HTR_HT_Msk                          ( 0xFFFUL << ADC_HTR_HT_Pos )
#define ADC_HTR_HT                              ( ADC_HTR_HT_Msk )


/***************  Bits definition for ADC_LTR register  **********************/

#define ADC_LTR_DLT_Pos                         ( 16U )
#define ADC_LTR_DLT_Msk                         ( 0xFFFUL << ADC_LTR_DLT_Pos )
#define ADC_LTR_DLT                             ( ADC_LTR_DLT_Msk )

#define ADC_LTR_LT_Pos                          ( 0U )
#define ADC_LTR_LT_Msk                          ( 0xFFFUL << ADC_LTR_LT_Pos )
#define ADC_LTR_LT                              ( ADC_LTR_LT_Msk )


/***************  Bits definition for ADC_SQR1 register  *********************/

#define ADC_SQR1_SQ5_Pos                        ( 25U )
#define ADC_SQR1_SQ5_Msk                        ( 0x1FUL << ADC_SQR1_SQ5_Pos )
#define ADC_SQR1_SQ5                            ( ADC_SQR1_SQ5_Msk )
#define ADC_SQR1_SQ5_0                          ( 0x1UL << ADC_SQR1_SQ5_Msk )
#define ADC_SQR1_SQ5_1                          ( 0x2UL << ADC_SQR1_SQ5_Msk )
#define ADC_SQR1_SQ5_2                          ( 0x4UL << ADC_SQR1_SQ5_Msk )
#define ADC_SQR1_SQ5_3                          ( 0x8UL << ADC_SQR1_SQ5_Msk )
#define ADC_SQR1_SQ5_4                          ( 0x10UL << ADC_SQR1_SQ5_Msk )

#define ADC_SQR1_SQ4_Pos                        ( 20U )
#define ADC_SQR1_SQ4_Msk                        ( 0x1FUL << ADC_SQR1_SQ4_Pos )
#define ADC_SQR1_SQ4                            ( ADC_SQR1_SQ4_Msk )
#define ADC_SQR1_SQ4_0                          ( 0x1UL << ADC_SQR1_SQ4_Msk )
#define ADC_SQR1_SQ4_1                          ( 0x2UL << ADC_SQR1_SQ4_Msk )
#define ADC_SQR1_SQ4_2                          ( 0x4UL << ADC_SQR1_SQ4_Msk )
#define ADC_SQR1_SQ4_3                          ( 0x8UL << ADC_SQR1_SQ4_Msk )
#define ADC_SQR1_SQ4_4                          ( 0x10UL << ADC_SQR1_SQ4_Msk )

#define ADC_SQR1_SQ3_Pos                        ( 15U )
#define ADC_SQR1_SQ3_Msk                        ( 0x1FUL << ADC_SQR1_SQ3_Pos )
#define ADC_SQR1_SQ3                            ( ADC_SQR1_SQ3_Msk )
#define ADC_SQR1_SQ3_0                          ( 0x1UL << ADC_SQR1_SQ3_Msk )
#define ADC_SQR1_SQ3_1                          ( 0x2UL << ADC_SQR1_SQ3_Msk )
#define ADC_SQR1_SQ3_2                          ( 0x4UL << ADC_SQR1_SQ3_Msk )
#define ADC_SQR1_SQ3_3                          ( 0x8UL << ADC_SQR1_SQ3_Msk )
#define ADC_SQR1_SQ3_4                          ( 0x10UL << ADC_SQR1_SQ3_Msk )

#define ADC_SQR1_SQ2_Pos                        ( 10U )
#define ADC_SQR1_SQ2_Msk                        ( 0x1FUL << ADC_SQR1_SQ2_Pos )
#define ADC_SQR1_SQ2                            ( ADC_SQR1_SQ2_Msk )
#define ADC_SQR1_SQ2_0                          ( 0x1UL << ADC_SQR1_SQ2_Msk )
#define ADC_SQR1_SQ2_1                          ( 0x2UL << ADC_SQR1_SQ2_Msk )
#define ADC_SQR1_SQ2_2                          ( 0x4UL << ADC_SQR1_SQ2_Msk )
#define ADC_SQR1_SQ2_3                          ( 0x8UL << ADC_SQR1_SQ2_Msk )
#define ADC_SQR1_SQ2_4                          ( 0x10UL << ADC_SQR1_SQ2_Msk )

#define ADC_SQR1_SQ1_Pos                        ( 5U )
#define ADC_SQR1_SQ1_Msk                        ( 0x1FUL << ADC_SQR1_SQ1_Pos )
#define ADC_SQR1_SQ1                            ( ADC_SQR1_SQ1_Msk )
#define ADC_SQR1_SQ1_0                          ( 0x1UL << ADC_SQR1_SQ1_Msk )
#define ADC_SQR1_SQ1_1                          ( 0x2UL << ADC_SQR1_SQ1_Msk )
#define ADC_SQR1_SQ1_2                          ( 0x4UL << ADC_SQR1_SQ1_Msk )
#define ADC_SQR1_SQ1_3                          ( 0x8UL << ADC_SQR1_SQ1_Msk )
#define ADC_SQR1_SQ1_4                          ( 0x10UL << ADC_SQR1_SQ1_Msk )

#define ADC_SQR1_Pos                            ( 0U )
#define ADC_SQR1_Msk                            ( 0xFUL << ADC_SQR1_Pos )
#define ADC_SQR1                                ( ADC_SQR1_Msk )
#define ADC_SQR1_0                              ( 0x1UL << ADC_SQR1_Msk )
#define ADC_SQR1_1                              ( 0x2UL << ADC_SQR1_Msk )
#define ADC_SQR1_2                              ( 0x4UL << ADC_SQR1_Msk )
#define ADC_SQR1_3                              ( 0x8UL << ADC_SQR1_Msk )


/***************  Bits definition for ADC_SQR2 register  *********************/

#define ADC_SQR2_SQ11_Pos                       ( 25U )
#define ADC_SQR2_SQ11_Msk                       ( 0x1FUL << ADC_SQR2_SQ11_Pos )
#define ADC_SQR2_SQ11                           ( ADC_SQR2_SQ11_Msk )
#define ADC_SQR2_SQ11_0                         ( 0x1UL << ADC_SQR2_SQ11_Msk )
#define ADC_SQR2_SQ11_1                         ( 0x2UL << ADC_SQR2_SQ11_Msk )
#define ADC_SQR2_SQ11_2                         ( 0x4UL << ADC_SQR2_SQ11_Msk )
#define ADC_SQR2_SQ11_3                         ( 0x8UL << ADC_SQR2_SQ11_Msk )
#define ADC_SQR2_SQ11_4                         ( 0x10UL << ADC_SQR2_SQ11_Msk )

#define ADC_SQR2_SQ10_Pos                       ( 20U )
#define ADC_SQR2_SQ10_Msk                       ( 0x1FUL << ADC_SQR2_SQ10_Pos )
#define ADC_SQR2_SQ10                           ( ADC_SQR2_SQ10_Msk )
#define ADC_SQR2_SQ10_0                         ( 0x1UL << ADC_SQR2_SQ10_Msk )
#define ADC_SQR2_SQ10_1                         ( 0x2UL << ADC_SQR2_SQ10_Msk )
#define ADC_SQR2_SQ10_2                         ( 0x4UL << ADC_SQR2_SQ10_Msk )
#define ADC_SQR2_SQ10_3                         ( 0x8UL << ADC_SQR2_SQ10_Msk )
#define ADC_SQR2_SQ10_4                         ( 0x10UL << ADC_SQR2_SQ10_Msk )

#define ADC_SQR2_SQ9_Pos                        ( 15U )
#define ADC_SQR2_SQ9_Msk                        ( 0x1FUL << ADC_SQR2_SQ9_Pos )
#define ADC_SQR2_SQ9                            ( ADC_SQR2_SQ9_Msk )
#define ADC_SQR2_SQ9_0                          ( 0x1UL << ADC_SQR2_SQ9_Msk )
#define ADC_SQR2_SQ9_1                          ( 0x2UL << ADC_SQR2_SQ9_Msk )
#define ADC_SQR2_SQ9_2                          ( 0x4UL << ADC_SQR2_SQ9_Msk )
#define ADC_SQR2_SQ9_3                          ( 0x8UL << ADC_SQR2_SQ9_Msk )
#define ADC_SQR2_SQ9_4                          ( 0x10UL << ADC_SQR2_SQ9_Msk )

#define ADC_SQR2_SQ8_Pos                        ( 10U )
#define ADC_SQR2_SQ8_Msk                        ( 0x1FUL << ADC_SQR2_SQ8_Pos )
#define ADC_SQR2_SQ8                            ( ADC_SQR2_SQ8_Msk )
#define ADC_SQR2_SQ8_0                          ( 0x1UL << ADC_SQR2_SQ8_Msk )
#define ADC_SQR2_SQ8_1                          ( 0x2UL << ADC_SQR2_SQ8_Msk )
#define ADC_SQR2_SQ8_2                          ( 0x4UL << ADC_SQR2_SQ8_Msk )
#define ADC_SQR2_SQ8_3                          ( 0x8UL << ADC_SQR2_SQ8_Msk )
#define ADC_SQR2_SQ8_4                          ( 0x10UL << ADC_SQR2_SQ8_Msk )

#define ADC_SQR2_SQ7_Pos                        ( 5U )
#define ADC_SQR2_SQ7_Msk                        ( 0x1FUL << ADC_SQR2_SQ7_Pos )
#define ADC_SQR2_SQ7                            ( ADC_SQR2_SQ7_Msk )
#define ADC_SQR2_SQ7_0                          ( 0x1UL << ADC_SQR2_SQ7_Msk )
#define ADC_SQR2_SQ7_1                          ( 0x2UL << ADC_SQR2_SQ7_Msk )
#define ADC_SQR2_SQ7_2                          ( 0x4UL << ADC_SQR2_SQ7_Msk )
#define ADC_SQR2_SQ7_3                          ( 0x8UL << ADC_SQR2_SQ7_Msk )
#define ADC_SQR2_SQ7_4                          ( 0x10UL << ADC_SQR2_SQ7_Msk )

#define ADC_SQR2_SQ6_Pos                        ( 0U )
#define ADC_SQR2_SQ6_Msk                        ( 0x1FUL << ADC_SQR2_SQ6_Pos )
#define ADC_SQR2_SQ6                            ( ADC_SQR2_SQ6_Msk )
#define ADC_SQR2_SQ6_0                          ( 0x1UL << ADC_SQR2_SQ6_Msk )
#define ADC_SQR2_SQ6_1                          ( 0x2UL << ADC_SQR2_SQ6_Msk )
#define ADC_SQR2_SQ6_2                          ( 0x4UL << ADC_SQR2_SQ6_Msk )
#define ADC_SQR2_SQ6_3                          ( 0x8UL << ADC_SQR2_SQ6_Msk )
#define ADC_SQR2_SQ6_4                          ( 0x10UL << ADC_SQR2_SQ6_Msk )


/***************  Bits definition for ADC_SQR3 register  *********************/

#define ADC_SQR3_SQ16_Pos                       ( 20U )
#define ADC_SQR3_SQ16_Msk                       ( 0x1FUL << ADC_SQR3_SQ16_Pos )
#define ADC_SQR3_SQ16                           ( ADC_SQR3_SQ16_Msk )
#define ADC_SQR3_SQ16_0                         ( 0x1UL << ADC_SQR3_SQ16_Msk )
#define ADC_SQR3_SQ16_1                         ( 0x2UL << ADC_SQR3_SQ16_Msk )
#define ADC_SQR3_SQ16_2                         ( 0x4UL << ADC_SQR3_SQ16_Msk )
#define ADC_SQR3_SQ16_3                         ( 0x8UL << ADC_SQR3_SQ16_Msk )
#define ADC_SQR3_SQ16_4                         ( 0x10UL << ADC_SQR3_SQ16_Msk )

#define ADC_SQR3_SQ15_Pos                       ( 15U )
#define ADC_SQR3_SQ15_Msk                       ( 0x1FUL << ADC_SQR3_SQ15_Pos )
#define ADC_SQR3_SQ15                           ( ADC_SQR3_SQ15_Msk )
#define ADC_SQR3_SQ15_0                         ( 0x1UL << ADC_SQR3_SQ15_Msk )
#define ADC_SQR3_SQ15_1                         ( 0x2UL << ADC_SQR3_SQ15_Msk )
#define ADC_SQR3_SQ15_2                         ( 0x4UL << ADC_SQR3_SQ15_Msk )
#define ADC_SQR3_SQ15_3                         ( 0x8UL << ADC_SQR3_SQ15_Msk )
#define ADC_SQR3_SQ15_4                         ( 0x10UL << ADC_SQR3_SQ15_Msk )

#define ADC_SQR3_SQ14_Pos                       ( 10U )
#define ADC_SQR3_SQ14_Msk                       ( 0x1FUL << ADC_SQR3_SQ14_Pos )
#define ADC_SQR3_SQ14                           ( ADC_SQR3_SQ14_Msk )
#define ADC_SQR3_SQ14_0                         ( 0x1UL << ADC_SQR3_SQ14_Msk )
#define ADC_SQR3_SQ14_1                         ( 0x2UL << ADC_SQR3_SQ14_Msk )
#define ADC_SQR3_SQ14_2                         ( 0x4UL << ADC_SQR3_SQ14_Msk )
#define ADC_SQR3_SQ14_3                         ( 0x8UL << ADC_SQR3_SQ14_Msk )
#define ADC_SQR3_SQ14_4                         ( 0x10UL << ADC_SQR3_SQ14_Msk )

#define ADC_SQR3_SQ13_Pos                       ( 5U )
#define ADC_SQR3_SQ13_Msk                       ( 0x1FUL << ADC_SQR3_SQ13_Pos )
#define ADC_SQR3_SQ13                           ( ADC_SQR3_SQ13_Msk )
#define ADC_SQR3_SQ13_0                         ( 0x1UL << ADC_SQR3_SQ13_Msk )
#define ADC_SQR3_SQ13_1                         ( 0x2UL << ADC_SQR3_SQ13_Msk )
#define ADC_SQR3_SQ13_2                         ( 0x4UL << ADC_SQR3_SQ13_Msk )
#define ADC_SQR3_SQ13_3                         ( 0x8UL << ADC_SQR3_SQ13_Msk )
#define ADC_SQR3_SQ13_4                         ( 0x10UL << ADC_SQR3_SQ13_Msk )

#define ADC_SQR3_SQ12_Pos                       ( 0U )
#define ADC_SQR3_SQ12_Msk                       ( 0x1FUL << ADC_SQR3_SQ12_Pos )
#define ADC_SQR3_SQ12                           ( ADC_SQR3_SQ12_Msk )
#define ADC_SQR3_SQ12_0                         ( 0x1UL << ADC_SQR3_SQ12_Msk )
#define ADC_SQR3_SQ12_1                         ( 0x2UL << ADC_SQR3_SQ12_Msk )
#define ADC_SQR3_SQ12_2                         ( 0x4UL << ADC_SQR3_SQ12_Msk )
#define ADC_SQR3_SQ12_3                         ( 0x8UL << ADC_SQR3_SQ12_Msk )
#define ADC_SQR3_SQ12_4                         ( 0x10UL << ADC_SQR3_SQ12_Msk )


/***************  Bits definition for ADC_JSQR register  *********************/

#define ADC_JSQR_JEXTSEL_Pos                    ( 27U )
#define ADC_JSQR_JEXTSEL_Msk                    ( 0x1FUL << ADC_JSQR_JEXTSEL_Pos )
#define ADC_JSQR_JEXTSEL                        ( ADC_JSQR_JEXTSEL_Msk )
#define ADC_JSQR_JEXTSEL_0                      ( 0x1UL << ADC_JSQR_JEXTSEL_Msk )
#define ADC_JSQR_JEXTSEL_1                      ( 0x2UL << ADC_JSQR_JEXTSEL_Msk )
#define ADC_JSQR_JEXTSEL_2                      ( 0x4UL << ADC_JSQR_JEXTSEL_Msk )
#define ADC_JSQR_JEXTSEL_3                      ( 0x8UL << ADC_JSQR_JEXTSEL_Msk )
#define ADC_JSQR_JEXTSEL_4                      ( 0x10UL << ADC_JSQR_JEXTSEL_Msk )

#define ADC_JSQR_JEXTEN_Pos                     ( 25U )
#define ADC_JSQR_JEXTEN_Msk                     ( 0x3UL << ADC_JSQR_JEXTEN_Pos )
#define ADC_JSQR_JEXTEN                         ( ADC_JSQR_JEXTEN_Msk )
#define ADC_JSQR_JEXTEN_0                       ( 0x1UL << ADC_JSQR_JEXTEN_Msk )
#define ADC_JSQR_JEXTEN_1                       ( 0x2UL << ADC_JSQR_JEXTEN_Msk )

#define ADC_JSQR_JSQ4_Pos                       ( 20U )
#define ADC_JSQR_JSQ4_Msk                       ( 0x1FUL << ADC_JSQR_JSQ4_Pos )
#define ADC_JSQR_JSQ4                           ( ADC_JSQR_JSQ4_Msk )
#define ADC_JSQR_JSQ4_0                         ( 0x1UL << ADC_JSQR_JSQ4_Msk )
#define ADC_JSQR_JSQ4_1                         ( 0x2UL << ADC_JSQR_JSQ4_Msk )
#define ADC_JSQR_JSQ4_2                         ( 0x4UL << ADC_JSQR_JSQ4_Msk )
#define ADC_JSQR_JSQ4_3                         ( 0x8UL << ADC_JSQR_JSQ4_Msk )
#define ADC_JSQR_JSQ4_4                         ( 0x10UL << ADC_JSQR_JSQ4_Msk )

#define ADC_JSQR_JSQ3_Pos                       ( 15U )
#define ADC_JSQR_JSQ3_Msk                       ( 0x1FUL << ADC_JSQR_JSQ3_Pos )
#define ADC_JSQR_JSQ3                           ( ADC_JSQR_JSQ3_Msk )
#define ADC_JSQR_JSQ3_0                         ( 0x1UL << ADC_JSQR_JSQ3_Msk )
#define ADC_JSQR_JSQ3_1                         ( 0x2UL << ADC_JSQR_JSQ3_Msk )
#define ADC_JSQR_JSQ3_2                         ( 0x4UL << ADC_JSQR_JSQ3_Msk )
#define ADC_JSQR_JSQ3_3                         ( 0x8UL << ADC_JSQR_JSQ3_Msk )
#define ADC_JSQR_JSQ3_4                         ( 0x10UL << ADC_JSQR_JSQ3_Msk )

#define ADC_JSQR_JSQ2_Pos                       ( 10U )
#define ADC_JSQR_JSQ2_Msk                       ( 0x1FUL << ADC_JSQR_JSQ2_Pos )
#define ADC_JSQR_JSQ2                           ( ADC_JSQR_JSQ2_Msk )
#define ADC_JSQR_JSQ2_0                         ( 0x1UL << ADC_JSQR_JSQ2_Msk )
#define ADC_JSQR_JSQ2_1                         ( 0x2UL << ADC_JSQR_JSQ2_Msk )
#define ADC_JSQR_JSQ2_2                         ( 0x4UL << ADC_JSQR_JSQ2_Msk )
#define ADC_JSQR_JSQ2_3                         ( 0x8UL << ADC_JSQR_JSQ2_Msk )
#define ADC_JSQR_JSQ2_4                         ( 0x10UL << ADC_JSQR_JSQ2_Msk )

#define ADC_JSQR_JSQ1_Pos                       ( 5U )
#define ADC_JSQR_JSQ1_Msk                       ( 0x1FUL << ADC_JSQR_JSQ1_Pos )
#define ADC_JSQR_JSQ1                           ( ADC_JSQR_JSQ1_Msk )
#define ADC_JSQR_JSQ1_0                         ( 0x1UL << ADC_JSQR_JSQ1_Msk )
#define ADC_JSQR_JSQ1_1                         ( 0x2UL << ADC_JSQR_JSQ1_Msk )
#define ADC_JSQR_JSQ1_2                         ( 0x4UL << ADC_JSQR_JSQ1_Msk )
#define ADC_JSQR_JSQ1_3                         ( 0x8UL << ADC_JSQR_JSQ1_Msk )
#define ADC_JSQR_JSQ1_4                         ( 0x10UL << ADC_JSQR_JSQ1_Msk )

#define ADC_JSQR_JL_Pos                         ( 0U )
#define ADC_JSQR_JL_Msk                         ( 0x3UL << ADC_JSQR_JL_Pos )
#define ADC_JSQR_JL                             ( ADC_JSQR_JL_Msk )
#define ADC_JSQR_JL_0                           ( 0x1UL << ADC_JSQR_JL_Msk )
#define ADC_JSQR_JL_1                           ( 0x2UL << ADC_JSQR_JL_Msk )


/***************  Bits definition for ADC_JDR1 register  *********************/

#define ADC_JDR1_JCH_Pos                        ( 16U )
#define ADC_JDR1_JCH_Msk                        ( 0x1FUL << ADC_JDR1_JCH_Pos )
#define ADC_JDR1_JCH                            ( ADC_JDR1_JCH_Msk )
#define ADC_JDR1_JCH_0                          ( 0x1UL << ADC_JDR1_JCH_Msk )
#define ADC_JDR1_JCH_1                          ( 0x2UL << ADC_JDR1_JCH_Msk )
#define ADC_JDR1_JCH_2                          ( 0x4UL << ADC_JDR1_JCH_Msk )
#define ADC_JDR1_JCH_3                          ( 0x8UL << ADC_JDR1_JCH_Msk )
#define ADC_JDR1_JCH_4                          ( 0x10UL << ADC_JDR1_JCH_Msk )

#define ADC_JDR1_JDATA_Pos                      ( 0U )
#define ADC_JDR1_JDATA_Msk                      ( 0xFFFFUL << ADC_JDR1_JDATA_Pos )
#define ADC_JDR1_JDATA                          ( ADC_JDR1_JDATA_Msk )


/***************  Bits definition for ADC_JDR2 register  *********************/

#define ADC_JDR2_JCH_Pos                        ( 16U )
#define ADC_JDR2_JCH_Msk                        ( 0x1FUL << ADC_JDR2_JCH_Pos )
#define ADC_JDR2_JCH                            ( ADC_JDR2_JCH_Msk )
#define ADC_JDR2_JCH_0                          ( 0x1UL << ADC_JDR2_JCH_Msk )
#define ADC_JDR2_JCH_1                          ( 0x2UL << ADC_JDR2_JCH_Msk )
#define ADC_JDR2_JCH_2                          ( 0x4UL << ADC_JDR2_JCH_Msk )
#define ADC_JDR2_JCH_3                          ( 0x8UL << ADC_JDR2_JCH_Msk )
#define ADC_JDR2_JCH_4                          ( 0x10UL << ADC_JDR2_JCH_Msk )

#define ADC_JDR2_JDATA_Pos                      ( 0U )
#define ADC_JDR2_JDATA_Msk                      ( 0xFFFFUL << ADC_JDR2_JDATA_Pos )
#define ADC_JDR2_JDATA                          ( ADC_JDR2_JDATA_Msk )


/***************  Bits definition for ADC_JDR3 register  *********************/

#define ADC_JDR3_JCH_Pos                        ( 16U )
#define ADC_JDR3_JCH_Msk                        ( 0x1FUL << ADC_JDR3_JCH_Pos )
#define ADC_JDR3_JCH                            ( ADC_JDR3_JCH_Msk )
#define ADC_JDR3_JCH_0                          ( 0x1UL << ADC_JDR3_JCH_Msk )
#define ADC_JDR3_JCH_1                          ( 0x2UL << ADC_JDR3_JCH_Msk )
#define ADC_JDR3_JCH_2                          ( 0x4UL << ADC_JDR3_JCH_Msk )
#define ADC_JDR3_JCH_3                          ( 0x8UL << ADC_JDR3_JCH_Msk )
#define ADC_JDR3_JCH_4                          ( 0x10UL << ADC_JDR3_JCH_Msk )

#define ADC_JDR3_JDATA_Pos                      ( 0U )
#define ADC_JDR3_JDATA_Msk                      ( 0xFFFFUL << ADC_JDR3_JDATA_Pos )
#define ADC_JDR3_JDATA                          ( ADC_JDR3_JDATA_Msk )


/***************  Bits definition for ADC_JDR4 register  *********************/

#define ADC_JDR4_JCH_Pos                        ( 16U )
#define ADC_JDR4_JCH_Msk                        ( 0x1FUL << ADC_JDR4_JCH_Pos )
#define ADC_JDR4_JCH                            ( ADC_JDR4_JCH_Msk )
#define ADC_JDR4_JCH_0                          ( 0x1UL << ADC_JDR4_JCH_Msk )
#define ADC_JDR4_JCH_1                          ( 0x2UL << ADC_JDR4_JCH_Msk )
#define ADC_JDR4_JCH_2                          ( 0x4UL << ADC_JDR4_JCH_Msk )
#define ADC_JDR4_JCH_3                          ( 0x8UL << ADC_JDR4_JCH_Msk )
#define ADC_JDR4_JCH_4                          ( 0x10UL << ADC_JDR4_JCH_Msk )

#define ADC_JDR4_JDATA_Pos                      ( 0U )
#define ADC_JDR4_JDATA_Msk                      ( 0xFFFFUL << ADC_JDR4_JDATA_Pos )
#define ADC_JDR4_JDATA                          ( ADC_JDR4_JDATA_Msk )


/***************  Bits definition for ADC_DR register  ***********************/

#define ADC_DR_CH_Pos                           ( 16U )
#define ADC_DR_CH_Msk                           ( 0x1FUL << ADC_DR_CH_Pos )
#define ADC_DR_CH                               ( ADC_DR_CH_Msk )
#define ADC_DR_CH_0                             ( 0x1UL << ADC_DR_CH_Msk )
#define ADC_DR_CH_1                             ( 0x2UL << ADC_DR_CH_Msk )
#define ADC_DR_CH_2                             ( 0x4UL << ADC_DR_CH_Msk )
#define ADC_DR_CH_3                             ( 0x8UL << ADC_DR_CH_Msk )
#define ADC_DR_CH_4                             ( 0x10UL << ADC_DR_CH_Msk )

#define ADC_DR_DATA_Pos                         ( 0U )
#define ADC_DR_DATA_Msk                         ( 0xFFFFUL << ADC_DR_DATA_Pos )
#define ADC_DR_DATA                             ( ADC_DR_DATA_Msk )


/***************  Bits definition for ADC_DIFF register  *********************/

#define ADC_DIFF_DIFF919_Pos                    ( 9U )
#define ADC_DIFF_DIFF919_Msk                    ( 0x1UL << ADC_DIFF_DIFF919_Pos )
#define ADC_DIFF_DIFF919                        ( ADC_DIFF_DIFF919_Msk )

#define ADC_DIFF_DIFF818_Pos                    ( 8U )
#define ADC_DIFF_DIFF818_Msk                    ( 0x1UL << ADC_DIFF_DIFF818_Pos )
#define ADC_DIFF_DIFF818                        ( ADC_DIFF_DIFF818_Msk )

#define ADC_DIFF_DIFF717_Pos                    ( 7U )
#define ADC_DIFF_DIFF717_Msk                    ( 0x1UL << ADC_DIFF_DIFF717_Pos )
#define ADC_DIFF_DIFF717                        ( ADC_DIFF_DIFF717_Msk )

#define ADC_DIFF_DIFF616_Pos                    ( 6U )
#define ADC_DIFF_DIFF616_Msk                    ( 0x1UL << ADC_DIFF_DIFF616_Pos )
#define ADC_DIFF_DIFF616                        ( ADC_DIFF_DIFF616_Msk )

#define ADC_DIFF_DIFF515_Pos                    ( 5U )
#define ADC_DIFF_DIFF515_Msk                    ( 0x1UL << ADC_DIFF_DIFF515_Pos )
#define ADC_DIFF_DIFF515                        ( ADC_DIFF_DIFF515_Msk )

#define ADC_DIFF_DIFF414_Pos                    ( 4U )
#define ADC_DIFF_DIFF414_Msk                    ( 0x1UL << ADC_DIFF_DIFF414_Pos )
#define ADC_DIFF_DIFF414                        ( ADC_DIFF_DIFF414_Msk )

#define ADC_DIFF_DIFF313_Pos                    ( 3U )
#define ADC_DIFF_DIFF313_Msk                    ( 0x1UL << ADC_DIFF_DIFF313_Pos )
#define ADC_DIFF_DIFF313                        ( ADC_DIFF_DIFF313_Msk )

#define ADC_DIFF_DIFF212_Pos                    ( 2U )
#define ADC_DIFF_DIFF212_Msk                    ( 0x1UL << ADC_DIFF_DIFF212_Pos )
#define ADC_DIFF_DIFF212                        ( ADC_DIFF_DIFF212_Msk )

#define ADC_DIFF_DIFF111_Pos                    ( 1U )
#define ADC_DIFF_DIFF111_Msk                    ( 0x1UL << ADC_DIFF_DIFF111_Pos )
#define ADC_DIFF_DIFF111                        ( ADC_DIFF_DIFF111_Msk )

#define ADC_DIFF_DIFF010_Pos                    ( 0U )
#define ADC_DIFF_DIFF010_Msk                    ( 0x1UL << ADC_DIFF_DIFF010_Pos )
#define ADC_DIFF_DIFF010                        ( ADC_DIFF_DIFF010_Msk )


/***************  Bits definition for ADC_SIGN register  *********************/

#define ADC_SIGN_SIGN919_Pos                    ( 9U )
#define ADC_SIGN_SIGN919_Msk                    ( 0x1UL << ADC_SIGN_SIGN919_Pos )
#define ADC_SIGN_SIGN919                        ( ADC_SIGN_SIGN919_Msk )

#define ADC_SIGN_SIGN818_Pos                    ( 8U )
#define ADC_SIGN_SIGN818_Msk                    ( 0x1UL << ADC_SIGN_SIGN818_Pos )
#define ADC_SIGN_SIGN818                        ( ADC_SIGN_SIGN818_Msk )

#define ADC_SIGN_SIGN717_Pos                    ( 7U )
#define ADC_SIGN_SIGN717_Msk                    ( 0x1UL << ADC_SIGN_SIGN717_Pos )
#define ADC_SIGN_SIGN717                        ( ADC_SIGN_SIGN717_Msk )

#define ADC_SIGN_SIGN616_Pos                    ( 6U )
#define ADC_SIGN_SIGN616_Msk                    ( 0x1UL << ADC_SIGN_SIGN616_Pos )
#define ADC_SIGN_SIGN616                        ( ADC_SIGN_SIGN616_Msk )

#define ADC_SIGN_SIGN515_Pos                    ( 5U )
#define ADC_SIGN_SIGN515_Msk                    ( 0x1UL << ADC_SIGN_SIGN515_Pos )
#define ADC_SIGN_SIGN515                        ( ADC_SIGN_SIGN515_Msk )

#define ADC_SIGN_SIGN414_Pos                    ( 4U )
#define ADC_SIGN_SIGN414_Msk                    ( 0x1UL << ADC_SIGN_SIGN414_Pos )
#define ADC_SIGN_SIGN414                        ( ADC_SIGN_SIGN414_Msk )

#define ADC_SIGN_SIGN313_Pos                    ( 3U )
#define ADC_SIGN_SIGN313_Msk                    ( 0x1UL << ADC_SIGN_SIGN313_Pos )
#define ADC_SIGN_SIGN313                        ( ADC_SIGN_SIGN313_Msk )

#define ADC_SIGN_SIGN212_Pos                    ( 2U )
#define ADC_SIGN_SIGN212_Msk                    ( 0x1UL << ADC_SIGN_SIGN212_Pos )
#define ADC_SIGN_SIGN212                        ( ADC_SIGN_SIGN212_Msk )

#define ADC_SIGN_SIGN111_Pos                    ( 1U )
#define ADC_SIGN_SIGN111_Msk                    ( 0x1UL << ADC_SIGN_SIGN111_Pos )
#define ADC_SIGN_SIGN111                        ( ADC_SIGN_SIGN111_Msk )

#define ADC_SIGN_SIGN010_Pos                    ( 0U )
#define ADC_SIGN_SIGN010_Msk                    ( 0x1UL << ADC_SIGN_SIGN010_Pos )
#define ADC_SIGN_SIGN010                        ( ADC_SIGN_SIGN010_Msk )


/***************  Bits definition for ADC_OFR1 register  *********************/

#define ADC_OFR1_OFFSETXEN_Pos                  ( 31U )
#define ADC_OFR1_OFFSETXEN_Msk                  ( 0x1UL << ADC_OFR1_OFFSETXEN_Pos )
#define ADC_OFR1_OFFSETXEN                      ( ADC_OFR1_OFFSETXEN_Msk )

#define ADC_OFR1_OFFSETXCH_Pos                  ( 26U )
#define ADC_OFR1_OFFSETXCH_Msk                  ( 0x1FUL << ADC_OFR1_OFFSETXCH_Pos )
#define ADC_OFR1_OFFSETXCH                      ( ADC_OFR1_OFFSETXCH_Msk )
#define ADC_OFR1_OFFSETXCH_0                    ( 0x1UL << ADC_OFR1_OFFSETXCH_Msk )
#define ADC_OFR1_OFFSETXCH_1                    ( 0x2UL << ADC_OFR1_OFFSETXCH_Msk )
#define ADC_OFR1_OFFSETXCH_2                    ( 0x4UL << ADC_OFR1_OFFSETXCH_Msk )
#define ADC_OFR1_OFFSETXCH_3                    ( 0x8UL << ADC_OFR1_OFFSETXCH_Msk )
#define ADC_OFR1_OFFSETXCH_4                    ( 0x10UL << ADC_OFR1_OFFSETXCH_Msk )

#define ADC_OFR1_OFFSETXSAT_Pos                 ( 25U )
#define ADC_OFR1_OFFSETXSAT_Msk                 ( 0x1UL << ADC_OFR1_OFFSETXSAT_Pos )
#define ADC_OFR1_OFFSETXSAT                     ( ADC_OFR1_OFFSETXSAT_Msk )

#define ADC_OFR1_OFFSETXPOS_Pos                 ( 24U )
#define ADC_OFR1_OFFSETXPOS_Msk                 ( 0x1UL << ADC_OFR1_OFFSETXPOS_Pos )
#define ADC_OFR1_OFFSETXPOS                     ( ADC_OFR1_OFFSETXPOS_Msk )

#define ADC_OFR1_OFFSETY_Pos                    ( 0U )
#define ADC_OFR1_OFFSETY_Msk                    ( 0xFFFUL << ADC_OFR1_OFFSETY_Pos )
#define ADC_OFR1_OFFSETY                        ( ADC_OFR1_OFFSETY_Msk )


/***************  Bits definition for ADC_OFR2 register  *********************/

#define ADC_OFR2_OFFSETXEN_Pos                  ( 31U )
#define ADC_OFR2_OFFSETXEN_Msk                  ( 0x1UL << ADC_OFR2_OFFSETXEN_Pos )
#define ADC_OFR2_OFFSETXEN                      ( ADC_OFR2_OFFSETXEN_Msk )

#define ADC_OFR2_OFFSETXCH_Pos                  ( 26U )
#define ADC_OFR2_OFFSETXCH_Msk                  ( 0x1FUL << ADC_OFR2_OFFSETXCH_Pos )
#define ADC_OFR2_OFFSETXCH                      ( ADC_OFR2_OFFSETXCH_Msk )
#define ADC_OFR2_OFFSETXCH_0                    ( 0x1UL << ADC_OFR2_OFFSETXCH_Msk )
#define ADC_OFR2_OFFSETXCH_1                    ( 0x2UL << ADC_OFR2_OFFSETXCH_Msk )
#define ADC_OFR2_OFFSETXCH_2                    ( 0x4UL << ADC_OFR2_OFFSETXCH_Msk )
#define ADC_OFR2_OFFSETXCH_3                    ( 0x8UL << ADC_OFR2_OFFSETXCH_Msk )
#define ADC_OFR2_OFFSETXCH_4                    ( 0x10UL << ADC_OFR2_OFFSETXCH_Msk )

#define ADC_OFR2_OFFSETXSAT_Pos                 ( 25U )
#define ADC_OFR2_OFFSETXSAT_Msk                 ( 0x1UL << ADC_OFR2_OFFSETXSAT_Pos )
#define ADC_OFR2_OFFSETXSAT                     ( ADC_OFR2_OFFSETXSAT_Msk )

#define ADC_OFR2_OFFSETXPOS_Pos                 ( 24U )
#define ADC_OFR2_OFFSETXPOS_Msk                 ( 0x1UL << ADC_OFR2_OFFSETXPOS_Pos )
#define ADC_OFR2_OFFSETXPOS                     ( ADC_OFR2_OFFSETXPOS_Msk )

#define ADC_OFR2_OFFSETY_Pos                    ( 0U )
#define ADC_OFR2_OFFSETY_Msk                    ( 0xFFFUL << ADC_OFR2_OFFSETY_Pos )
#define ADC_OFR2_OFFSETY                        ( ADC_OFR2_OFFSETY_Msk )


/***************  Bits definition for ADC_OFR3 register  *********************/

#define ADC_OFR3_OFFSETXEN_Pos                  ( 31U )
#define ADC_OFR3_OFFSETXEN_Msk                  ( 0x1UL << ADC_OFR3_OFFSETXEN_Pos )
#define ADC_OFR3_OFFSETXEN                      ( ADC_OFR3_OFFSETXEN_Msk )

#define ADC_OFR3_OFFSETXCH_Pos                  ( 26U )
#define ADC_OFR3_OFFSETXCH_Msk                  ( 0x1FUL << ADC_OFR3_OFFSETXCH_Pos )
#define ADC_OFR3_OFFSETXCH                      ( ADC_OFR3_OFFSETXCH_Msk )
#define ADC_OFR3_OFFSETXCH_0                    ( 0x1UL << ADC_OFR3_OFFSETXCH_Msk )
#define ADC_OFR3_OFFSETXCH_1                    ( 0x2UL << ADC_OFR3_OFFSETXCH_Msk )
#define ADC_OFR3_OFFSETXCH_2                    ( 0x4UL << ADC_OFR3_OFFSETXCH_Msk )
#define ADC_OFR3_OFFSETXCH_3                    ( 0x8UL << ADC_OFR3_OFFSETXCH_Msk )
#define ADC_OFR3_OFFSETXCH_4                    ( 0x10UL << ADC_OFR3_OFFSETXCH_Msk )

#define ADC_OFR3_OFFSETXSAT_Pos                 ( 25U )
#define ADC_OFR3_OFFSETXSAT_Msk                 ( 0x1UL << ADC_OFR3_OFFSETXSAT_Pos )
#define ADC_OFR3_OFFSETXSAT                     ( ADC_OFR3_OFFSETXSAT_Msk )

#define ADC_OFR3_OFFSETXPOS_Pos                 ( 24U )
#define ADC_OFR3_OFFSETXPOS_Msk                 ( 0x1UL << ADC_OFR3_OFFSETXPOS_Pos )
#define ADC_OFR3_OFFSETXPOS                     ( ADC_OFR3_OFFSETXPOS_Msk )

#define ADC_OFR3_OFFSETY_Pos                    ( 0U )
#define ADC_OFR3_OFFSETY_Msk                    ( 0xFFFUL << ADC_OFR3_OFFSETY_Pos )
#define ADC_OFR3_OFFSETY                        ( ADC_OFR3_OFFSETY_Msk )


/***************  Bits definition for ADC_OFR4 register  *********************/

#define ADC_OFR4_OFFSETXEN_Pos                  ( 31U )
#define ADC_OFR4_OFFSETXEN_Msk                  ( 0x1UL << ADC_OFR4_OFFSETXEN_Pos )
#define ADC_OFR4_OFFSETXEN                      ( ADC_OFR4_OFFSETXEN_Msk )

#define ADC_OFR4_OFFSETXCH_Pos                  ( 26U )
#define ADC_OFR4_OFFSETXCH_Msk                  ( 0x1FUL << ADC_OFR4_OFFSETXCH_Pos )
#define ADC_OFR4_OFFSETXCH                      ( ADC_OFR4_OFFSETXCH_Msk )
#define ADC_OFR4_OFFSETXCH_0                    ( 0x1UL << ADC_OFR4_OFFSETXCH_Msk )
#define ADC_OFR4_OFFSETXCH_1                    ( 0x2UL << ADC_OFR4_OFFSETXCH_Msk )
#define ADC_OFR4_OFFSETXCH_2                    ( 0x4UL << ADC_OFR4_OFFSETXCH_Msk )
#define ADC_OFR4_OFFSETXCH_3                    ( 0x8UL << ADC_OFR4_OFFSETXCH_Msk )
#define ADC_OFR4_OFFSETXCH_4                    ( 0x10UL << ADC_OFR4_OFFSETXCH_Msk )

#define ADC_OFR4_OFFSETXSAT_Pos                 ( 25U )
#define ADC_OFR4_OFFSETXSAT_Msk                 ( 0x1UL << ADC_OFR4_OFFSETXSAT_Pos )
#define ADC_OFR4_OFFSETXSAT                     ( ADC_OFR4_OFFSETXSAT_Msk )

#define ADC_OFR4_OFFSETXPOS_Pos                 ( 24U )
#define ADC_OFR4_OFFSETXPOS_Msk                 ( 0x1UL << ADC_OFR4_OFFSETXPOS_Pos )
#define ADC_OFR4_OFFSETXPOS                     ( ADC_OFR4_OFFSETXPOS_Msk )

#define ADC_OFR4_OFFSETY_Pos                    ( 0U )
#define ADC_OFR4_OFFSETY_Msk                    ( 0xFFFUL << ADC_OFR4_OFFSETY_Pos )
#define ADC_OFR4_OFFSETY                        ( ADC_OFR4_OFFSETY_Msk )


/***************  Bits definition for ADC_ANACFG register  *******************/

#define ADC_ANACFG_CLKDLYSEL_Pos                ( 3U )
#define ADC_ANACFG_CLKDLYSEL_Msk                ( 0x3UL << ADC_ANACFG_CLKDLYSEL_Pos )
#define ADC_ANACFG_CLKDLYSEL                    ( ADC_ANACFG_CLKDLYSEL_Msk )
#define ADC_ANACFG_CLKDLYSEL_0                  ( 0x1UL << ADC_ANACFG_CLKDLYSEL_Msk )
#define ADC_ANACFG_CLKDLYSEL_1                  ( 0x2UL << ADC_ANACFG_CLKDLYSEL_Msk )

#define ADC_ANACFG_BIASC_Pos                    ( 0U )
#define ADC_ANACFG_BIASC_Msk                    ( 0x7UL << ADC_ANACFG_BIASC_Pos )
#define ADC_ANACFG_BIASC                        ( ADC_ANACFG_BIASC_Msk )
#define ADC_ANACFG_BIASC_0                      ( 0x1UL << ADC_ANACFG_BIASC_Msk )
#define ADC_ANACFG_BIASC_1                      ( 0x2UL << ADC_ANACFG_BIASC_Msk )
#define ADC_ANACFG_BIASC_2                      ( 0x4UL << ADC_ANACFG_BIASC_Msk )


/***************  Bits definition for ADC_CSR register  **********************/

#define ADC_CSR_AWD_SLV_Pos                     ( 23U )
#define ADC_CSR_AWD_SLV_Msk                     ( 0x1UL << ADC_CSR_AWD_SLV_Pos )
#define ADC_CSR_AWD_SLV                         ( ADC_CSR_AWD_SLV_Msk )

#define ADC_CSR_JEOG_SLV_Pos                    ( 22U )
#define ADC_CSR_JEOG_SLV_Msk                    ( 0x1UL << ADC_CSR_JEOG_SLV_Pos )
#define ADC_CSR_JEOG_SLV                        ( ADC_CSR_JEOG_SLV_Msk )

#define ADC_CSR_JEOC_SLV_Pos                    ( 21U )
#define ADC_CSR_JEOC_SLV_Msk                    ( 0x1UL << ADC_CSR_JEOC_SLV_Pos )
#define ADC_CSR_JEOC_SLV                        ( ADC_CSR_JEOC_SLV_Msk )

#define ADC_CSR_OVERF_SLV_Pos                   ( 20U )
#define ADC_CSR_OVERF_SLV_Msk                   ( 0x1UL << ADC_CSR_OVERF_SLV_Pos )
#define ADC_CSR_OVERF_SLV                       ( ADC_CSR_OVERF_SLV_Msk )

#define ADC_CSR_EOG_SLV_Pos                     ( 19U )
#define ADC_CSR_EOG_SLV_Msk                     ( 0x1UL << ADC_CSR_EOG_SLV_Pos )
#define ADC_CSR_EOG_SLV                         ( ADC_CSR_EOG_SLV_Msk )

#define ADC_CSR_EOC_SLV_Pos                     ( 18U )
#define ADC_CSR_EOC_SLV_Msk                     ( 0x1UL << ADC_CSR_EOC_SLV_Pos )
#define ADC_CSR_EOC_SLV                         ( ADC_CSR_EOC_SLV_Msk )

#define ADC_CSR_EOSMP_SLV_Pos                   ( 17U )
#define ADC_CSR_EOSMP_SLV_Msk                   ( 0x1UL << ADC_CSR_EOSMP_SLV_Pos )
#define ADC_CSR_EOSMP_SLV                       ( ADC_CSR_EOSMP_SLV_Msk )

#define ADC_CSR_ADRDYSLV_Pos                    ( 16U )
#define ADC_CSR_ADRDYSLV_Msk                    ( 0x1UL << ADC_CSR_ADRDYSLV_Pos )
#define ADC_CSR_ADRDYSLV                        ( ADC_CSR_ADRDYSLV_Msk )

#define ADC_CSR_AWDMST_Pos                      ( 7U )
#define ADC_CSR_AWDMST_Msk                      ( 0x1UL << ADC_CSR_AWDMST_Pos )
#define ADC_CSR_AWDMST                          ( ADC_CSR_AWDMST_Msk )

#define ADC_CSR_JEOGMST_Pos                     ( 6U )
#define ADC_CSR_JEOGMST_Msk                     ( 0x1UL << ADC_CSR_JEOGMST_Pos )
#define ADC_CSR_JEOGMST                         ( ADC_CSR_JEOGMST_Msk )

#define ADC_CSR_JEOCMST_Pos                     ( 5U )
#define ADC_CSR_JEOCMST_Msk                     ( 0x1UL << ADC_CSR_JEOCMST_Pos )
#define ADC_CSR_JEOCMST                         ( ADC_CSR_JEOCMST_Msk )

#define ADC_CSR_OVERFMST_Pos                    ( 4U )
#define ADC_CSR_OVERFMST_Msk                    ( 0x1UL << ADC_CSR_OVERFMST_Pos )
#define ADC_CSR_OVERFMST                        ( ADC_CSR_OVERFMST_Msk )

#define ADC_CSR_EOGMST_Pos                      ( 3U )
#define ADC_CSR_EOGMST_Msk                      ( 0x1UL << ADC_CSR_EOGMST_Pos )
#define ADC_CSR_EOGMST                          ( ADC_CSR_EOGMST_Msk )

#define ADC_CSR_EOCMST_Pos                      ( 2U )
#define ADC_CSR_EOCMST_Msk                      ( 0x1UL << ADC_CSR_EOCMST_Pos )
#define ADC_CSR_EOCMST                          ( ADC_CSR_EOCMST_Msk )

#define ADC_CSR_EOSMPMST_Pos                    ( 1U )
#define ADC_CSR_EOSMPMST_Msk                    ( 0x1UL << ADC_CSR_EOSMPMST_Pos )
#define ADC_CSR_EOSMPMST                        ( ADC_CSR_EOSMPMST_Msk )

#define ADC_CSR_ADRDYMST_Pos                    ( 0U )
#define ADC_CSR_ADRDYMST_Msk                    ( 0x1UL << ADC_CSR_ADRDYMST_Pos )
#define ADC_CSR_ADRDYMST                        ( ADC_CSR_ADRDYMST_Msk )


/***************  Bits definition for ADC_CCR register  **********************/

#define ADC_CCR_ADCDIV_Pos                      ( 16U )
#define ADC_CCR_ADCDIV_Msk                      ( 0xFUL << ADC_CCR_ADCDIV_Pos )
#define ADC_CCR_ADCDIV                          ( ADC_CCR_ADCDIV_Msk )
#define ADC_CCR_ADCDIV_0                        ( 0x1UL << ADC_CCR_ADCDIV_Msk )
#define ADC_CCR_ADCDIV_1                        ( 0x2UL << ADC_CCR_ADCDIV_Msk )
#define ADC_CCR_ADCDIV_2                        ( 0x4UL << ADC_CCR_ADCDIV_Msk )
#define ADC_CCR_ADCDIV_3                        ( 0x8UL << ADC_CCR_ADCDIV_Msk )

#define ADC_CCR_DMADUAL_Pos                     ( 14U )
#define ADC_CCR_DMADUAL_Msk                     ( 0x3UL << ADC_CCR_DMADUAL_Pos )
#define ADC_CCR_DMADUAL                         ( ADC_CCR_DMADUAL_Msk )
#define ADC_CCR_DMADUAL_0                       ( 0x1UL << ADC_CCR_DMADUAL_Msk )
#define ADC_CCR_DMADUAL_1                       ( 0x2UL << ADC_CCR_DMADUAL_Msk )

#define ADC_CCR_DELAY_Pos                       ( 8U )
#define ADC_CCR_DELAY_Msk                       ( 0xFUL << ADC_CCR_DELAY_Pos )
#define ADC_CCR_DELAY                           ( ADC_CCR_DELAY_Msk )
#define ADC_CCR_DELAY_0                         ( 0x1UL << ADC_CCR_DELAY_Msk )
#define ADC_CCR_DELAY_1                         ( 0x2UL << ADC_CCR_DELAY_Msk )
#define ADC_CCR_DELAY_2                         ( 0x4UL << ADC_CCR_DELAY_Msk )
#define ADC_CCR_DELAY_3                         ( 0x8UL << ADC_CCR_DELAY_Msk )

#define ADC_CCR_DUALMOD_Pos                     ( 0U )
#define ADC_CCR_DUALMOD_Msk                     ( 0x1FUL << ADC_CCR_DUALMOD_Pos )
#define ADC_CCR_DUALMOD                         ( ADC_CCR_DUALMOD_Msk )
#define ADC_CCR_DUALMOD_0                       ( 0x1UL << ADC_CCR_DUALMOD_Msk )
#define ADC_CCR_DUALMOD_1                       ( 0x2UL << ADC_CCR_DUALMOD_Msk )
#define ADC_CCR_DUALMOD_2                       ( 0x4UL << ADC_CCR_DUALMOD_Msk )
#define ADC_CCR_DUALMOD_3                       ( 0x8UL << ADC_CCR_DUALMOD_Msk )
#define ADC_CCR_DUALMOD_4                       ( 0x10UL << ADC_CCR_DUALMOD_Msk )


/***************  Bits definition for ADC_CDR register  **********************/

#define ADC_CDR_DATA2_Pos                       ( 16U )
#define ADC_CDR_DATA2_Msk                       ( 0xFFFFUL << ADC_CDR_DATA2_Pos )
#define ADC_CDR_DATA2                           ( ADC_CDR_DATA2_Msk )

#define ADC_CDR_DATA1_Pos                       ( 0U )
#define ADC_CDR_DATA1_Msk                       ( 0xFFFFUL << ADC_CDR_DATA1_Pos )
#define ADC_CDR_DATA1                           ( ADC_CDR_DATA1_Msk )


/***************  Bits definition for ADC_TSREF register  ********************/

#define ADC_TSREF_HIZEN_Pos                     ( 27U )
#define ADC_TSREF_HIZEN_Msk                     ( 0x1UL << ADC_TSREF_HIZEN_Pos )
#define ADC_TSREF_HIZEN                         ( ADC_TSREF_HIZEN_Msk )

#define ADC_TSREF_VREFBISEL_Pos                 ( 25U )
#define ADC_TSREF_VREFBISEL_Msk                 ( 0x3UL << ADC_TSREF_VREFBISEL_Pos )
#define ADC_TSREF_VREFBISEL                     ( ADC_TSREF_VREFBISEL_Msk )
#define ADC_TSREF_VREFBISEL_0                   ( 0x1UL << ADC_TSREF_VREFBISEL_Msk )
#define ADC_TSREF_VREFBISEL_1                   ( 0x2UL << ADC_TSREF_VREFBISEL_Msk )

#define ADC_TSREF_VREFBIEN_Pos                  ( 24U )
#define ADC_TSREF_VREFBIEN_Msk                  ( 0x1UL << ADC_TSREF_VREFBIEN_Pos )
#define ADC_TSREF_VREFBIEN                      ( ADC_TSREF_VREFBIEN_Msk )

#define ADC_TSREF_VTRIM_Pos                     ( 19U )
#define ADC_TSREF_VTRIM_Msk                     ( 0x1FUL << ADC_TSREF_VTRIM_Pos )
#define ADC_TSREF_VTRIM                         ( ADC_TSREF_VTRIM_Msk )
#define ADC_TSREF_VTRIM_0                       ( 0x1UL << ADC_TSREF_VTRIM_Msk )
#define ADC_TSREF_VTRIM_1                       ( 0x2UL << ADC_TSREF_VTRIM_Msk )
#define ADC_TSREF_VTRIM_2                       ( 0x4UL << ADC_TSREF_VTRIM_Msk )
#define ADC_TSREF_VTRIM_3                       ( 0x8UL << ADC_TSREF_VTRIM_Msk )
#define ADC_TSREF_VTRIM_4                       ( 0x10UL << ADC_TSREF_VTRIM_Msk )

#define ADC_TSREF_TTRIM_Pos                     ( 15U )
#define ADC_TSREF_TTRIM_Msk                     ( 0xFUL << ADC_TSREF_TTRIM_Pos )
#define ADC_TSREF_TTRIM                         ( ADC_TSREF_TTRIM_Msk )
#define ADC_TSREF_TTRIM_0                       ( 0x1UL << ADC_TSREF_TTRIM_Msk )
#define ADC_TSREF_TTRIM_1                       ( 0x2UL << ADC_TSREF_TTRIM_Msk )
#define ADC_TSREF_TTRIM_2                       ( 0x4UL << ADC_TSREF_TTRIM_Msk )
#define ADC_TSREF_TTRIM_3                       ( 0x8UL << ADC_TSREF_TTRIM_Msk )

#define ADC_TSREF_VREXEN_Pos                    ( 12U )
#define ADC_TSREF_VREXEN_Msk                    ( 0x1UL << ADC_TSREF_VREXEN_Pos )
#define ADC_TSREF_VREXEN                        ( ADC_TSREF_VREXEN_Msk )

#define ADC_TSREF_VBATEN_Pos                    ( 11U )
#define ADC_TSREF_VBATEN_Msk                    ( 0x1UL << ADC_TSREF_VBATEN_Pos )
#define ADC_TSREF_VBATEN                        ( ADC_TSREF_VBATEN_Msk )

#define ADC_TSREF_BUFADDR_Pos                   ( 9U )
#define ADC_TSREF_BUFADDR_Msk                   ( 0x3UL << ADC_TSREF_BUFADDR_Pos )
#define ADC_TSREF_BUFADDR                       ( ADC_TSREF_BUFADDR_Msk )
#define ADC_TSREF_BUFADDR_0                     ( 0x1UL << ADC_TSREF_BUFADDR_Msk )
#define ADC_TSREF_BUFADDR_1                     ( 0x2UL << ADC_TSREF_BUFADDR_Msk )

#define ADC_TSREF_ADJTDOS_Pos                   ( 5U )
#define ADC_TSREF_ADJTDOS_Msk                   ( 0xFUL << ADC_TSREF_ADJTDOS_Pos )
#define ADC_TSREF_ADJTDOS                       ( ADC_TSREF_ADJTDOS_Msk )
#define ADC_TSREF_ADJTDOS_0                     ( 0x1UL << ADC_TSREF_ADJTDOS_Msk )
#define ADC_TSREF_ADJTDOS_1                     ( 0x2UL << ADC_TSREF_ADJTDOS_Msk )
#define ADC_TSREF_ADJTDOS_2                     ( 0x4UL << ADC_TSREF_ADJTDOS_Msk )
#define ADC_TSREF_ADJTDOS_3                     ( 0x8UL << ADC_TSREF_ADJTDOS_Msk )

#define ADC_TSREF_ADJTDGA_Pos                   ( 1U )
#define ADC_TSREF_ADJTDGA_Msk                   ( 0xFUL << ADC_TSREF_ADJTDGA_Pos )
#define ADC_TSREF_ADJTDGA                       ( ADC_TSREF_ADJTDGA_Msk )
#define ADC_TSREF_ADJTDGA_0                     ( 0x1UL << ADC_TSREF_ADJTDGA_Msk )
#define ADC_TSREF_ADJTDGA_1                     ( 0x2UL << ADC_TSREF_ADJTDGA_Msk )
#define ADC_TSREF_ADJTDGA_2                     ( 0x4UL << ADC_TSREF_ADJTDGA_Msk )
#define ADC_TSREF_ADJTDGA_3                     ( 0x8UL << ADC_TSREF_ADJTDGA_Msk )

#define ADC_TSREF_ENTS_Pos                      ( 0U )
#define ADC_TSREF_ENTS_Msk                      ( 0x1UL << ADC_TSREF_ENTS_Pos )
#define ADC_TSREF_ENTS                          ( ADC_TSREF_ENTS_Msk )


#define ADC_CH_MASK                             (BIT4|BIT3|BIT2|BIT1|BIT0)
#define ADC_COMMON_REGISTER(__HANDLE__)         ADC12_COMMON


/**************** Enable the specified ADC. **************************/
#define __HAL_ADC_ENABLE(__HANDLE__)                                           \
  (SET_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADCEN)))
    
/**************** Disable the specified ADC. **************************/
#define __HAL_ADC_DISABLE(__HANDLE__)                                          \
  (CLEAR_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADCEN)))
    
/**************** Enable the specified ADC interrupt source. **************************/
#define __HAL_ADC_ENABLE_IT(__HANDLE__, __INTERRUPT__)                         \
  (SET_BIT((__HANDLE__)->Instance->IE, (__INTERRUPT__)))
    
/**************** Disable the specified ADC interrupt source. **************************/
#define __HAL_ADC_DISABLE_IT(__HANDLE__, __INTERRUPT__)                        \
  (CLEAR_BIT((__HANDLE__)->Instance->IE, (__INTERRUPT__)))
  
/**************** Checks if the specified ADC interrupt source is enabled or disabled. **************************/
#define __HAL_ADC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)                     \
  (((__HANDLE__)->Instance->IE & (__INTERRUPT__)) == (__INTERRUPT__))

/**************** Get the selected ADC's flag status. **************************/
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__)                               \
  ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__))
    
/**************** Clear the selected ADC's flag status. **************************/
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__)                             \
  (SET_BIT((__HANDLE__)->Instance->SR, (__FLAG__)))

/**************** Checks if the ADC regular group trig source is the specified source. **************************/
#define __HAL_ADC_CHECK_TRIG_REGULAR(__HANDLE__, __TRIGSOURCE__)                     \
  ((((__HANDLE__)->Instance->CR1 & ADC_CR1_EXTSEL_Msk) >> ADC_CR1_EXTSEL_Pos) == (__TRIGSOURCE__))


#define ADC_IS_SOFTWARE_START_INJECTED(__HANDLE__)                             \
  (((__HANDLE__)->Instance->JSQR & ADC_JSQR_JEXTEN) == 0)
  
#define ADC_IS_SOFTWARE_START_REGULAR(__HANDLE__)                              \
  (((__HANDLE__)->Instance->CR1 & ADC_CR1_EXTEN_Msk) == 0)
  

/** 
  * @brief  ADC ExTigger structure definition
  */
typedef struct
{
    uint32_t ExTrigSel;                     /*!< Configures the regular channel trig mode. */
    uint32_t JExTrigSel;                    /*!< Configures the inject channel trig mode. */
}ADC_ExTrigTypeDef;

/** 
  * @brief  ADC group regular oversampling structure definition
  */
typedef struct
{
    uint32_t Ratio;                         /*!< Configures the oversampling ratio.
                                               This parameter can be a value of @ref ADC_CR2_OVSR_2X*/

    uint32_t RightBitShift;                 /*!< Configures the division coefficient for the Oversampler.
                                               This parameter can be a value of @ref ADC_CR2_OVSS_0 */

    uint32_t TriggeredMode;                 /*!< Selects the regular triggered oversampling mode.
                                               This parameter can be a value of 
                                               0 : trig 1 time; other: trig N times, N refer to the oversampling Ratio*/
}ADC_OversamplingTypeDef;


/******************************** ADC Init mode define *******************************/
/******************************** ConConvMode define *******************************/
#define  ADC_CONCONVMODE_DISABLE                (0)
#define  ADC_CONCONVMODE_ENABLE                 (1)

/******************************** JChannelMode define *******************************/
#define  ADC_JCHANNELMODE_DISABLE               (0)
#define  ADC_JCHANNELMODE_ENABLE                (1)

/******************************** DiffMode define *******************************/
#define  ADC_DIFFMODE_DISABLE                   (0)
#define  ADC_DIFFMODE_ENABLE                    (1)

/******************************** DMAMode define *******************************/
#define  ADC_DMAMODE_DISABLE                    (0)
#define  ADC_DMAMODE_ENABLE                     (1)

/******************************** OverMode define *******************************/
#define  ADC_OVERMODE_DISABLE                   (0)
#define  ADC_OVERMODE_ENABLE                    (1)

/******************************** OverSampMode define *******************************/
#define  ADC_OVERSAMPMODE_DISABLE               (0)
#define  ADC_OVERSAMPMODE_ENABLE                (1)

/******************************** AnalogWDGEn define *******************************/
#define  ADC_ANALOGWDGEN_DISABLE                (0)
#define  ADC_ANALOGWDGEN_ENABLE                 (1)

/**
  * @brief  ADC Configuration Structure definition
  */
typedef struct
{
    uint32_t ClockPrescaler;              /*!< Specify the ADC clock div from the PCLK. 
                                      This parameter can be set to ADC_CLOCK_DIV1 | ADC_CLOCK_DIV2 |... ADC_CLOCK_DIV16 */

    uint32_t Resolution;            /*!< Configure the ADC resolution.
                                       This parameter can be a value of @ref ADC_HAL_EC_RESOLUTION */

    uint32_t DataAlign;             /*!< Specify ADC data alignment in conversion data register (right or left).
                                       Refer to reference manual for alignments formats versus resolutions.
                                       This parameter can be a value of @ref ADC_HAL_EC_DATA_ALIGN */
    FunctionalState ConConvMode;           /*!< Specify whether the conversion is performed in single mode (one conversion) or continuous mode for ADC group regular,
                                       after the first ADC conversion start trigger occurred (software start or external trigger).
                                       This parameter can be set to ADC_CONCONVMODE_DISABLE or ADC_CONCONVMODE_ENABLE. */	
    FunctionalState DiscontinuousConvMode; /*!< Specifies whether the conversions sequence of regular group is performed in Complete-sequence/Discontinuous-sequence (main sequence subdivided in successive parts).
                                              Discontinuous mode is used only if sequencer is enabled (parameter 'ScanConvMode'). If sequencer is disabled, this parameter is discarded.
                                              Discontinuous mode can be enabled only if continuous mode is disabled. If continuous mode is enabled, this parameter setting is discarded.
                                              This parameter can be set to ENABLE or DISABLE. */
    uint32_t NbrOfDiscConversion;              /*!< Specifies the number of ranks that will be converted within the regular group sequencer.
                                              To use regular group sequencer and convert several ranks, parameter 'ScanConvMode' must be enabled.
                                              This parameter must be a number between Min_Data = 1 and Max_Data = 16. */
    uint32_t ExternalTrigConv;             /*!< Selects the external event used to trigger the conversion start of regular group.
                                              If set to ADC_SOFTWARE_START, external triggers are disabled.
                                              If set to external trigger source, triggering is on event rising edge by default.
                                              This parameter can be a value of @ref ADC_External_trigger_Source_Regular */
    uint32_t ExternalTrigConvEdge;         /*!< Selects the external trigger edge of regular group.
                                              If trigger is set to ADC_SOFTWARE_START, this parameter is discarded.
                                              This parameter can be a value of @ref ADC_External_trigger_edge_Regular */

    uint32_t ChannelEn;             /*!< Specify the enable ADC channels. 
                                       This parameter can be set to ADC_CHANNEL_0_EN | ADC_CHANNEL_1_EN |... ADC_CHANNEL_15_EN*/

                                                                                                
    uint32_t DMAMode;                /*!< Specify whether the DMA requests are performed in one shot mode (DMA transfer stops when number of conversions is reached)
                                       or in continuous mode (DMA transfer unlimited, whatever number of conversions).
                                       This parameter can be set to ADC_DMAMODE_ENABLE or ADC_DMAMODE_DISABLE.
                                       Note: In continuous mode, DMA must be configured in circular mode. Otherwise an overrun will be triggered when DMA buffer maximum pointer is reached. */

    uint32_t OverMode;               /*!<  ADC_OVERMODE_DISABLE,ADC_OVERMODE_ENABLE*/

    uint32_t OverSampMode;          /*!< Specify whether the oversampling feature is enabled or disabled.
                                           This parameter can be set to ADC_OVERSAMPMODE_ENABLE or ADC_OVERSAMPMODE_DISABLE.
                                           Note: This parameter can be modified only if there is no conversion is ongoing on ADC group regular. */
    ADC_OversamplingTypeDef Oversampling;   /*!< Specify ADC group regular oversampling structure. */

    uint32_t AnalogWDGEn;
	
											  
	 
}ADC_InitTypeDef;


typedef struct
{
    uint32_t Channel;               /*!< Specify the channel to configure into ADC regular group.
                                        This parameter can be a value of @ref ADC_CHANNEL_0
                                        Note: Depending on devices and ADC instances, some channels may not be available on device package pins. Refer to device datasheet for channels availability. */

    uint32_t Sq;                    /*!< Add or remove the channel from ADC regular group sequencer and specify its conversion rank.
                                        This parameter is dependent on ScanConvMode:
                                        - sequencer configured to fully configurable:
                                          Channels ordering into each rank of scan sequence:
                                          whatever channel can be placed into whatever rank.
                                        - sequencer configured to not fully configurable:
                                          rank of each channel is fixed by channel HW number.
                                          (channel 0 fixed on rank 0, channel 1 fixed on rank1, ...).
                                          Despite the channel rank is fixed, this parameter allow an additional possibility: to remove the selected rank (selected channel) from sequencer.
                                        This parameter can be a value of @ref ADC_SEQUENCE_SQ1 */

    uint32_t Smp;                    /*!< Sampling time value to be set for the selected channel.
                                        Unit: ADC clock cycles 
                                        This parameter can be a value of @ref ADC_SMP_CLOCK_3 */
    uint32_t SingleDiff;             /*!< Select single-ended or differential input.
                                        In differential mode: Differential measurement is carried out between the selected channel 'i' (positive input) and channel 'i+1' (negative input).
                                                              Only channel 'i' has to be configured, channel 'i+1' is configured automatically.
                                        This parameter must be a value of @ref ADC_HAL_EC_CHANNEL_SINGLE_DIFF_ENDING
                                        Caution: This parameter applies to a channel that can be used in a regular and/or injected group.
                                                 It overwrites the last setting.
                                        Note: Refer to Reference Manual to ensure the selected channel is available in differential mode.
                                        Note: When configuring a channel 'i' in differential mode, the channel 'i+1' is not usable separately.
                                        Note: This parameter must be modified when ADC is disabled (before ADC start conversion or after ADC stop conversion).
                                              If ADC is enabled, this parameter setting is bypassed without error reporting (as it can be the expected behavior in case
                                        of another parameter update on the fly) */
    uint32_t OffsetNumber;           /*!< Select the offset number
                                        This parameter can be a value of @ref ADC_HAL_EC_OFFSET_NB
                                        Caution: Only one offset is allowed per channel. This parameter overwrites the last setting. */

    uint32_t Offset;                 /*!< Define the offset to be applied on the raw converted data.
                                        Offset value must be a positive number.
                                        Depending of ADC resolution selected (12, 10, 8 or 6 bits), this parameter must be a number between Min_Data = 0x000 and Max_Data = 0xFFF,
                                        0x3FF, 0xFF or 0x3F respectively.
                                        Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled
                                              without continuous mode or external trigger that could launch a conversion). */

    uint32_t OffsetSign;                /*!< Define if the offset should be substracted (negative sign) or added (positive sign) from or to the raw converted data.
                                        This parameter can be a value of @ref ADCEx_OffsetSign.
                                        Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled
                                              without continuous mode or external trigger that could launch a conversion). */
    uint32_t OffsetSaturation;   /*!< Define if the offset should be saturated upon under or over flow.
                                        This parameter value can be ENABLE or DISABLE.
                                        Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled
                                              without continuous mode or external trigger that could launch a conversion). */
}ADC_ChannelConfTypeDef;

typedef struct
{
    uint32_t WatchdogMode;      /*!< Configure the ADC analog watchdog mode: single/all/none channels.
                                   For Analog Watchdog 1: Configure the ADC analog watchdog mode: single channel or all channels, ADC group regular.
                                   For Analog Watchdog 2 and 3: Several channels can be monitored by applying successively the AWD init structure.
                                   This parameter can be a value of @ref ADC_ANALOGWATCHDOG_RCH_ALL. */

    uint32_t Channel;           /*!< Select which ADC channel to monitor by analog watchdog.
                                   For Analog Watchdog 1: this parameter has an effect only if parameter 'WatchdogMode' is configured on single channel (only 1 channel can be monitored).
                                   For Analog Watchdog 2 and 3: Several channels can be monitored. To use this feature, call successively the function HAL_ADC_AnalogWDGConfig() for each channel to be added (or removed with value 'ADC_ANALOGWATCHDOG_NONE').
                                   This parameter can be a value of @ref ADC_CHANNEL_0. */

    uint32_t ITMode;            /*!< Specify whether the analog watchdog is configured in interrupt or polling mode.
                                   This parameter can be set to ENABLE or DISABLE */

    uint32_t HighThreshold;     /*!< Configure the ADC analog watchdog High threshold value. */

    uint32_t LowThreshold;      /*!< Configures the ADC analog watchdog Low threshold value. */

    uint32_t SingleDiff;             /*!< Select single-ended or differential input.
                                        In differential mode: Differential measurement is carried out between the selected channel 'i' (positive input) and channel 'i+1' (negative input).
                                                              Only channel 'i' has to be configured, channel 'i+1' is configured automatically.
                                        This parameter must be a value of @ref ADC_HAL_EC_CHANNEL_SINGLE_DIFF_ENDING
                                        Caution: This parameter applies to a channel that can be used in a regular and/or injected group.
                                                 It overwrites the last setting.
                                        Note: Refer to Reference Manual to ensure the selected channel is available in differential mode.
                                        Note: When configuring a channel 'i' in differential mode, the channel 'i+1' is not usable separately.
                                        Note: This parameter must be modified when ADC is disabled (before ADC start conversion or after ADC stop conversion).
                                              If ADC is enabled, this parameter setting is bypassed without error reporting (as it can be the expected behavior in case
                                        of another parameter update on the fly) */
}ADC_AnalogWDGConfTypeDef;

/**
  * @brief  ADC Injected Conversion Oversampling structure definition
  */
typedef struct
{
    uint32_t Ratio;                         /*!< Configures the oversampling ratio.
                                               This parameter can be a value of @ref ADC_HAL_EC_OVS_RATIO */

    uint32_t RightBitShift;                 /*!< Configures the division coefficient for the Oversampler.
                                               This parameter can be a value of @ref ADC_HAL_EC_OVS_SHIFT */
} ADC_InjOversamplingTypeDef;


typedef struct 
{
    uint32_t InjectedChannel;                      /*!< Selection of ADC channel to configure
                                                      This parameter can be a value of @ref ADC_channels
                                                      Note: Depending on devices, some channels may not be available on package pins. Refer to device datasheet for channels availability. */
    uint32_t InjectedRank;                         /*!< Rank in the injected group sequencer
                                                      This parameter must be a value of @ref ADCEx_injected_rank
                                                      Note: In case of need to disable a channel or change order of conversion sequencer, rank containing a previous channel setting can be overwritten by the new channel setting (or parameter number of conversions can be adjusted) */
    uint32_t InjectedSamplingTime;                 /*!< Sampling time value to be set for the selected channel.
                                                      Unit: ADC clock cycles
                                                      Conversion time is the addition of sampling time and processing time (12 ADC clock cycles at ADC resolution 12 bits, 11 cycles at 10 bits, 9 cycles at 8 bits, 7 cycles at 6 bits).
                                                      This parameter can be a value of @ref ADC_sampling_times
                                                      Caution: This parameter updates the parameter property of the channel, that can be used into regular and/or injected groups.
                                                               If this same channel has been previously configured in the other group (regular/injected), it will be updated to last setting.
                                                      Note: In case of usage of internal measurement channels (VrefInt/Vbat/TempSensor),
                                                            sampling time constraints must be respected (sampling time can be adjusted in function of ADC clock frequency and sampling time setting)
                                                            Refer to device datasheet for timings values, parameters TS_vrefint, TS_temp (values rough order: 4us min). */
    uint32_t InjectedSingleDiff;            /*!< Selection of single-ended or differential input.
                                               In differential mode: Differential measurement is between the selected channel 'i' (positive input) and channel 'i+1' (negative input).
                                               Only channel 'i' has to be configured, channel 'i+1' is configured automatically.
                                               This parameter must be a value of @ref ADC_HAL_EC_CHANNEL_SINGLE_DIFF_ENDING.
                                               Caution: This parameter applies to a channel that can be used in a regular and/or injected group.
                                                        It overwrites the last setting.
                                               Note: Refer to Reference Manual to ensure the selected channel is available in differential mode.
                                               Note: When configuring a channel 'i' in differential mode, the channel 'i+1' is not usable separately.
                                               Note: This parameter must be modified when ADC is disabled (before ADC start conversion or after ADC stop conversion).
                                               If ADC is enabled, this parameter setting is bypassed without error reporting (as it can be the expected behavior in case
                                               of another parameter update on the fly) */

    uint32_t InjectedOffsetNumber;          /*!< Selects the offset number.
                                               This parameter can be a value of @ref ADC_HAL_EC_OFFSET_NB.
                                               Caution: Only one offset is allowed per channel. This parameter overwrites the last setting. */

    uint32_t InjectedOffset;                /*!< Defines the offset to be applied on the raw converted data.
                                               Offset value must be a positive number.
                                               Depending of ADC resolution selected (12, 10, 8 or 6 bits), this parameter must be a number
                                               between Min_Data = 0x000 and Max_Data = 0xFFF,  0x3FF, 0xFF or 0x3F respectively.
                                               Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled
                                               without continuous mode or external trigger that could launch a conversion). */

    uint32_t InjectedOffsetSign;                /*!< Define if the offset should be substracted (negative sign) or added (positive sign) from or to the raw converted data.
                                               This parameter can be a value of @ref ADCEx_OffsetSign.
                                               Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled without continuous mode or external trigger that could launch a conversion). */
    uint32_t InjectedOffsetSaturation;   /*!< Define if the offset should be saturated upon under or over flow.
                                               This parameter value can be ENABLE or DISABLE.
                                               Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled without continuous mode or external trigger that could launch a conversion). */
                                                     
    uint32_t InjectedNbrOfConversion;              /*!< Specifies the number of ranks that will be converted within the injected group sequencer.
                                                      To use the injected group sequencer and convert several ranks, parameter 'ScanConvMode' must be enabled.
                                                      This parameter must be a number between Min_Data = 1 and Max_Data = 4.
                                                      Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to 
                                                               configure a channel on injected group can impact the configuration of other channels previously set. */
    FunctionalState InjectedDiscontinuousConvMode; /*!< Specifies whether the conversions sequence of injected group is performed in Complete-sequence/Discontinuous-sequence (main sequence subdivided in successive parts).
                                                      Discontinuous mode is used only if sequencer is enabled (parameter 'ScanConvMode'). If sequencer is disabled, this parameter is discarded.
                                                      Discontinuous mode can be enabled only if continuous mode is disabled. If continuous mode is enabled, this parameter setting is discarded.
                                                      This parameter can be set to ENABLE or DISABLE.
                                                      Note: For injected group, number of discontinuous ranks increment is fixed to one-by-one.
                                                      Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to 
                                                               configure a channel on injected group can impact the configuration of other channels previously set. */
    FunctionalState AutoInjectedConv;              /*!< Enables or disables the selected ADC automatic injected group conversion after regular one
                                                      This parameter can be set to ENABLE or DISABLE.      
                                                      Note: To use Automatic injected conversion, discontinuous mode must be disabled ('DiscontinuousConvMode' and 'InjectedDiscontinuousConvMode' set to DISABLE)
                                                      Note: To use Automatic injected conversion, injected group external triggers must be disabled ('ExternalTrigInjecConv' set to ADC_SOFTWARE_START)
                                                      Note: In case of DMA used with regular group: if DMA configured in normal mode (single shot) JAUTO will be stopped upon DMA transfer complete.
                                                            To maintain JAUTO always enabled, DMA must be configured in circular mode.
                                                      Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                               configure a channel on injected group can impact the configuration of other channels previously set. */
    uint32_t ExternalTrigInjecConv;                /*!< Selects the external event used to trigger the conversion start of injected group.
                                                      If set to ADC_INJECTED_SOFTWARE_START, external triggers are disabled.
                                                      If set to external trigger source, triggering is on event rising edge.
                                                      This parameter can be a value of @ref ADCEx_External_trigger_Source_Injected
                                                      Note: This parameter must be modified when ADC is disabled (before ADC start conversion or after ADC stop conversion).
                                                            If ADC is enabled, this parameter setting is bypassed without error reporting (as it can be the expected behaviour in case of another parameter update on the fly)
                                                      Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                               configure a channel on injected group can impact the configuration of other channels previously set. */
    uint32_t ExternalTrigInjecConvEdge;            /*!< Selects the external trigger edge of injected group.
                                                      This parameter can be a value of @ref ADCEx_External_trigger_edge_Injected.
                                                      If trigger is set to ADC_INJECTED_SOFTWARE_START, this parameter is discarded.
                                                      Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to 
                                                               configure a channel on injected group can impact the configuration of other channels previously set. */
                                                               
    FunctionalState InjecOversamplingMode;         /*!< Specifies whether the oversampling feature is enabled or disabled.
                                                      This parameter can be set to ENABLE or DISABLE.
                                                      Note: This parameter can be modified only if there is no conversion is ongoing (both ADSTART and JADSTART cleared). */

    ADC_InjOversamplingTypeDef  InjecOversampling; /*!< Specifies the Oversampling parameters.
                                                      Caution: this setting overwrites the previous oversampling configuration if oversampling already enabled.
                                                      Note: This parameter can be modified only if there is no conversion is ongoing (both ADSTART and JADSTART cleared). */															   
															  
}ADC_InjectionConfTypeDef; 

/** 
  * @brief ADC Configuration multi-mode structure definition  
  */ 
typedef struct
{
    uint32_t Mode;              /*!< Configures the ADC to operate in independent or multi mode. 
                                   This parameter can be a value of @ref ADCEx_Common_mode */
    uint32_t DMAAccessMode;     /*!< Configures the Direct memory access mode for multi ADC mode.
                                   This parameter can be a value of @ref ADCEx_Direct_memory_access_mode_for_multi_mode */
    uint32_t TwoSamplingDelay;  /*!< Configures the Delay between 2 sampling phases.
                                   This parameter can be a value of @ref ADC_delay_between_2_sampling_phases */
}ADC_MultiModeTypeDef;

/**
  * @brief  ADC handle Structure definition
  */
typedef struct __ADC_HandleTypeDef
{
    ADC_TypeDef                     *Instance;                              /*!< Register base address */
    ADC_InitTypeDef                 Init;                                   /*!< ADC initialization parameters and regular conversions setting */
    DMA_HandleTypeDef               *DMA_Handle;                            /*!< Pointer DMA Handler */
    uint32_t                        ChannelNum;                             /*!< Total enable regular group channel number*/
    uint32_t                        *AdcResults;                            /*!< Point to the convert results*/
    void (*ConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);             /*!< ADC conversion complete callback */
    void (*GroupCpltCallback)(struct __ADC_HandleTypeDef *hadc);            /*!< ADC regular group conversion complete callback */
    void (*InjectedConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);     /*!< ADC injected conversion complete callback */
    void (*InjectedGroupConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);     /*!< ADC injected Group conversion complete callback */
    void (*LevelOutOfWindowCallback)(struct __ADC_HandleTypeDef *hadc);     /*!< ADC analog watchdog callback */
}ADC_HandleTypeDef;

/** @defgroup ADC_External_trigger_edge_Regular ADC External Trigger Edge Regular
  * @{
  */ 
#define ADC_EXTERNALTRIGCONVEDGE_NONE           (0x00U)
#define ADC_EXTERNALTRIGCONVEDGE_RISING         (0x1U)
#define ADC_EXTERNALTRIGCONVEDGE_FALLING        (0x2U)
#define ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING  (0x3U)

/**
  * @}
  */ 

/** @defgroup ADC_Data_align ADC Data Align
  * @{
  */ 
#define ADC_DATAALIGN_RIGHT      0x00000000U
#define ADC_DATAALIGN_LEFT       ((uint32_t)ADC_CR2_ALIGN)


/**
  * @}
  */ 
  
/** @defgroup ADC_HAL_EC_RESOLUTION  ADC instance - Resolution
  * @{
  */
#define ADC_RESOLUTION_12B                 (0x00000000)   /*!< ADC resolution 12 bits */
#define ADC_RESOLUTION_10B                 (0x00000010)   /*!< ADC resolution 10 bits */
#define ADC_RESOLUTION_8B                  (0x00000020)   /*!< ADC resolution  8 bits */
#define ADC_RESOLUTION_6B                  (0x00000030)   /*!< ADC resolution  6 bits */
/**
  * @}
  */
  

/** @defgroup ADC_HAL_EC_OFFSET_NB  ADC instance - Offset number
  * @{
  */
#define ADC_OFFSET_NONE              (ADC_OFFSET_4 + 1U) /*!< ADC offset disabled: no offset correction for the selected ADC channel */
#define ADC_OFFSET_1                 (0x00000000UL) /*!< ADC offset number 1: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define ADC_OFFSET_2                 (0x00000001UL) /*!< ADC offset number 2: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define ADC_OFFSET_3                 (0x00000002UL) /*!< ADC offset number 3: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define ADC_OFFSET_4                 (0x00000003UL) /*!< ADC offset number 4: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
/**
  * @}
  */
  
 
 /** @defgroup ADC_HAL_EC_CHANNEL_SINGLE_DIFF_ENDING  Channel - Single or differential ending
  * @{
  */
#define ADC_SINGLE_ENDED                (0x00)         /*!< ADC channel ending set to single ended (literal also used to set calibration mode) */
#define ADC_DIFFERENTIAL_ENDED          (0x01)   /*!< ADC channel ending set to differential (literal also used to set calibration mode) */
/**
  * @}
  */
  

/** @defgroup OFFSET_SATURATION ADC instance - Offset saturation mode
  * @{
  */
#define ADC_OFFSET_SATURATION_DISABLE   (0x00000000UL)                  /*!< ADC offset saturation is disabled (among ADC selected offset number 1, 2, 3 or 4) */
#define ADC_OFFSET_SATURATION_ENABLE    (1U<<ADC_OFR_OFFSETx_STA_POS)   /*!< ADC offset saturation is enabled (among ADC selected offset number 1, 2, 3 or 4) */
/**
  * @}
  */
  
 
/** @defgroup ADCEx_OffsetSign ADC Extended Offset Sign
  * @{
  */
#define ADC_OFFSET_SIGN_NEGATIVE      (0x00000000UL)                 /*!< Offset sign negative, offset is substracted */
#define ADC_OFFSET_SIGN_POSITIVE      (1U<<ADC_OFR_OFFSETx_POS_POS)  /*!< Offset sign positive, offset is added  */
/**
  * @}
  */
  





/** @defgroup ADC_HAL_EC_OVS_SHIFT  Oversampling - Data shift
  * @{
  */
#define ADC_RIGHTBITSHIFT_NONE             (0U)    /*!< ADC oversampling no shift (sum of the ADC conversions data is not divided to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_1                (1U) /*!< ADC oversampling shift of 1 (sum of the ADC conversions data is divided by 2 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_2                (2U) /*!< ADC oversampling shift of 2 (sum of the ADC conversions data is divided by 4 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_3                (3U) /*!< ADC oversampling shift of 3 (sum of the ADC conversions data is divided by 8 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_4                (4U) /*!< ADC oversampling shift of 4 (sum of the ADC conversions data is divided by 16 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_5                (5U) /*!< ADC oversampling shift of 5 (sum of the ADC conversions data is divided by 32 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_6                (6U) /*!< ADC oversampling shift of 6 (sum of the ADC conversions data is divided by 64 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_7                (7U) /*!< ADC oversampling shift of 7 (sum of the ADC conversions data is divided by 128 to result as the ADC oversampling conversion data) */
#define ADC_RIGHTBITSHIFT_8                (8U) /*!< ADC oversampling shift of 8 (sum of the ADC conversions data is divided by 256 to result as the ADC oversampling conversion data) */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_OVS_RATIO  Oversampling - Ratio
  * @{
  */
#define ADC_OVERSAMPLING_RATIO_2           (0U)   /*!< ADC oversampling ratio of 2 (2 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_4           (1U)   /*!< ADC oversampling ratio of 4 (4 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_8           (2U)   /*!< ADC oversampling ratio of 8 (8 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_16          (3U)  /*!< ADC oversampling ratio of 16 (16 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_32          (4U)  /*!< ADC oversampling ratio of 32 (32 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_64          (5U)  /*!< ADC oversampling ratio of 64 (64 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_128         (6U)  /*!< ADC oversampling ratio of 128 (128 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define ADC_OVERSAMPLING_RATIO_256         (7U)  /*!< ADC oversampling ratio of 256 (256 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
/**
  * @}
  */
  

/** @defgroup 
  * @{
  */
#define ADC_SMP_CLOCK_1                 (0U)
#define ADC_SMP_CLOCK_3                 (1U)
#define ADC_SMP_CLOCK_5                 (2U)
#define ADC_SMP_CLOCK_7                 (3U)
#define ADC_SMP_CLOCK_10                (4U)
#define ADC_SMP_CLOCK_13                (5U)
#define ADC_SMP_CLOCK_16                (6U)
#define ADC_SMP_CLOCK_20                (7U)
#define ADC_SMP_CLOCK_30                (8U)
#define ADC_SMP_CLOCK_60                (9U)
#define ADC_SMP_CLOCK_80                (10U)
#define ADC_SMP_CLOCK_100               (11U)
#define ADC_SMP_CLOCK_120               (12U)
#define ADC_SMP_CLOCK_160               (13U)
#define ADC_SMP_CLOCK_320               (14U)
#define ADC_SMP_CLOCK_480               (15U)
/**
  * @}
  */
  
  

/******************************** ADC ClockPrescale define *******************************/
#define  ADC_CLOCK_DIV1                              (0U)    
#define  ADC_CLOCK_DIV2                              (1U)    
#define  ADC_CLOCK_DIV3                              (2U)    
#define  ADC_CLOCK_DIV4                              (3U)    
#define  ADC_CLOCK_DIV5                              (4U)    
#define  ADC_CLOCK_DIV6                              (5U)    
#define  ADC_CLOCK_DIV7                              (6U)    
#define  ADC_CLOCK_DIV8                              (7U)    
#define  ADC_CLOCK_DIV9                              (8U)    
#define  ADC_CLOCK_DIV10                             (9U)    
#define  ADC_CLOCK_DIV11                             (10U)    
#define  ADC_CLOCK_DIV12                             (11U)    
#define  ADC_CLOCK_DIV13                             (12U)    
#define  ADC_CLOCK_DIV14                             (13U)    
#define  ADC_CLOCK_DIV15                             (14U)    
#define  ADC_CLOCK_DIV16                             (15U) 

/************************ADC_AnalogWDGConfTypeDef->WatchdogMode define********************/
#define  ADC_ANALOGWATCHDOG_RCH_ALL                 (1U)   //All regular channels
#define  ADC_ANALOGWATCHDOG_JCH_ALL                 (2U)   //All inject channels
#define  ADC_ANALOGWATCHDOG_RCH_AND_JCH_ALL         (3U)   //All regular and inject channels
#define  ADC_ANALOGWATCHDOG_RCH_SINGLE              (4U)   //Single regular channel
#define  ADC_ANALOGWATCHDOG_JCH_SINGLE              (5U)   //Single Inject channel
#define  ADC_ANALOGWATCHDOG_RCH_OR_JCH_SINGLE       (6U)   //Regular or inject channel

/******************************** ADC sequence number define *******************************/
#define  ADC_SEQUENCE_SQ1                           (1U)
#define  ADC_SEQUENCE_SQ2                           (2U)
#define  ADC_SEQUENCE_SQ3                           (3U)
#define  ADC_SEQUENCE_SQ4                           (4U)
#define  ADC_SEQUENCE_SQ5                           (5U)
#define  ADC_SEQUENCE_SQ6                           (6U)
#define  ADC_SEQUENCE_SQ7                           (7U)
#define  ADC_SEQUENCE_SQ8                           (8U)
#define  ADC_SEQUENCE_SQ9                           (9U)
#define  ADC_SEQUENCE_SQ10                          (10U)
#define  ADC_SEQUENCE_SQ11                          (11U)
#define  ADC_SEQUENCE_SQ12                          (12U)
#define  ADC_SEQUENCE_SQ13                          (13U)
#define  ADC_SEQUENCE_SQ14                          (14U)
#define  ADC_SEQUENCE_SQ15                          (15U)
#define  ADC_SEQUENCE_SQ16                          (16U)


/******************************** ADC channel number define *******************************/
#define  ADC_CHANNEL_0                              (0U)    
#define  ADC_CHANNEL_1                              (1U)    
#define  ADC_CHANNEL_2                              (2U)    
#define  ADC_CHANNEL_3                              (3U)    
#define  ADC_CHANNEL_4                              (4U)    
#define  ADC_CHANNEL_5                              (5U)    
#define  ADC_CHANNEL_6                              (6U)    
#define  ADC_CHANNEL_7                              (7U)    
#define  ADC_CHANNEL_8                              (8U)    
#define  ADC_CHANNEL_9                              (9U)    
#define  ADC_CHANNEL_10                             (10U)    
#define  ADC_CHANNEL_11                             (11U)    
#define  ADC_CHANNEL_12                             (12U)    
#define  ADC_CHANNEL_13                             (13U)    
#define  ADC_CHANNEL_14                             (14U)    
#define  ADC_CHANNEL_15                             (15U)    
#define  ADC_CHANNEL_TEMP                           (16U)
#define  ADC_CHANNEL_VBGR                           (17U)     
#define  ADC_CHANNEL_VBAT                           (18U)       
#define  ADC_CHANNEL_EXT2                           (19U)    
#define  ADC_CHANNEL_EXT3                           (20U)    

/******************************** ADC channel enable define *******************************/
#define  ADC_CHANNEL_0_EN                              (BIT0)    
#define  ADC_CHANNEL_1_EN                              (BIT1)    
#define  ADC_CHANNEL_2_EN                              (BIT2)    
#define  ADC_CHANNEL_3_EN                              (BIT3)    
#define  ADC_CHANNEL_4_EN                              (BIT4)    
#define  ADC_CHANNEL_5_EN                              (BIT5)    
#define  ADC_CHANNEL_6_EN                              (BIT6)    
#define  ADC_CHANNEL_7_EN                              (BIT7)    
#define  ADC_CHANNEL_8_EN                              (BIT8)    
#define  ADC_CHANNEL_9_EN                              (BIT9)    
#define  ADC_CHANNEL_10_EN                             (BIT10)    
#define  ADC_CHANNEL_11_EN                             (BIT11)    
#define  ADC_CHANNEL_12_EN                             (BIT12)    
#define  ADC_CHANNEL_13_EN                             (BIT13)    
#define  ADC_CHANNEL_14_EN                             (BIT14)    
#define  ADC_CHANNEL_15_EN                             (BIT15)    
#define  ADC_CHANNEL_TEMP_EN                           (BIT16)
#define  ADC_CHANNEL_VBGR_EN                           (BIT17)    
#define  ADC_CHANNEL_VBAT_EN                           (BIT18)      
#define  ADC_CHANNEL_EXT2_EN                           (BIT19)    
#define  ADC_CHANNEL_EXT3_EN                           (BIT20)    

/******************************** ADC Trig source define*******************************
 *  |     Trig Source           |      Regular           |        Inject           | * 
 *  |     ADC_EXTERNAL_TIG0     |     TIM1_CC1           |      TIM1_TRGO          | *
 *  |     ADC_EXTERNAL_TIG1     |     TIM1_CC2           |      TIM1_CC4           | *
 *  |     ADC_EXTERNAL_TIG2     |     TIM1_CC3           |      TIM2_TRGO          | *
 *  |     ADC_EXTERNAL_TIG3     |     TIM2_CC2           |      TIM2_CC1           | *
 *  |     ADC_EXTERNAL_TIG4     |     TIM3_TRGO          |      TIM3_CC4           | *
 *  |     ADC_EXTERNAL_TIG5     |     TIM4_CC4           |      TIM4_TRGO          | *
 *  |     ADC_EXTERNAL_TIG6     |     EXTi Line 11       |      EXTi Line 15       | *
 *  |     ADC_EXTERNAL_TIG7     |     TIM8_TRGO          |      TIM8_CC4           | *
 *  |     ADC_EXTERNAL_TIG8     |     TIM8_TRGO2         |      TIM1_TRGO          | *
 *  |     ADC_EXTERNAL_TIG9     |     TIM1_TRGO          |      TIM8_TRGO          | *
 *  |     ADC_EXTERNAL_TIG10    |     TIM1_TRGO2         |      TIM8_TRGO2         | *
 *  |     ADC_EXTERNAL_TIG11    |     TIM2_TRGO          |      TIM3_CC3           | *
 *  |     ADC_EXTERNAL_TIG12    |     TIM4_TRGO          |      TIM3_TRGO          | *
 *  |     ADC_EXTERNAL_TIG13    |     TIM6_TRGO          |      TIM3_CC1           | *
 *  |     ADC_EXTERNAL_TIG14    |     TIM15_TRGO         |      TIM6_TRGO          | *
 *  |     ADC_EXTERNAL_TIG15    |     TIM3_CC4           |      TIM15_TRGO         | *
 *  |     ADC_EXTERNAL_TIG16    |     TIM1_CC4           |      TIM16_CC1          | *
 *  |     ADC_EXTERNAL_TIG17    |     LPTIM_OUT          |      LPTIM_OUT          | *
 *  |     ADC_EXTERNAL_TIG18    |     TIM7_TRGO          |      TIM7_TRGO          | * 
 *  |     ADC_EXTERNAL_TIG19    |     TIM8_CC4           |      TIM17_CC1          | */
  
  
#define  ADC_EXTERNAL_TIG0                            (0U)
#define  ADC_EXTERNAL_TIG1                            (1U)
#define  ADC_EXTERNAL_TIG2                            (2U)
#define  ADC_EXTERNAL_TIG3                            (3U)
#define  ADC_EXTERNAL_TIG4                            (4U)
#define  ADC_EXTERNAL_TIG5                            (5U)
#define  ADC_EXTERNAL_TIG6                            (6U)
#define  ADC_EXTERNAL_TIG7                            (7U)
#define  ADC_EXTERNAL_TIG8                            (8U)
#define  ADC_EXTERNAL_TIG9                            (9U)
#define  ADC_EXTERNAL_TIG10                           (10U)
#define  ADC_EXTERNAL_TIG11                           (11U)
#define  ADC_EXTERNAL_TIG12                           (12U)
#define  ADC_EXTERNAL_TIG13                           (13U)
#define  ADC_EXTERNAL_TIG14                           (14U)
#define  ADC_EXTERNAL_TIG15                           (15U)
#define  ADC_EXTERNAL_TIG16                           (16U)
#define  ADC_EXTERNAL_TIG17                           (17U)
#define  ADC_EXTERNAL_TIG18                           (18U)
#define  ADC_EXTERNAL_TIG19                           (19U)
#define  ADC_SOFTWARE_START                           (32U)

/******************************** ADC results flag define for HAL level*******************************/
#define HAL_ADC_EOC_FLAG            0x80000000
#define HAL_ADC_JEOC_FLAG           0x40000000
#define HAL_ADC_AWD_FLAG            0x20000000



/******************************** ADC Instances *******************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE)    (((INSTANCE) == ADC1) || ((INSTANCE) == ADC2))
#define IS_ADC_ALL_CONCONVMODE(CONCONVMODE)     (((CONCONVMODE) == ADC_CONCONVMODE_DISABLE) || \
                                                 ((CONCONVMODE) == ADC_CONCONVMODE_ENABLE))

#define IS_ADC_ALL_JCHANNELMODE(JCHANNELMODE)    (((JCHANNELMODE) == ADC_JCHANNELMODE_DISABLE) || \
                                                  ((JCHANNELMODE) == ADC_JCHANNELMODE_ENABLE))

#define IS_ADC_ALL_DIFFMODE(DIFFMODE)            (((DIFFMODE) == ADC_DIFFMODE_DISABLE) || \
                                                  ((DIFFMODE) == ADC_DIFFMODE_ENABLE))

#define IS_ADC_ALL_DMAMODE(DMAMODE)              (((DMAMODE) == ADC_DMAMODE_DISABLE) || \
                                                  ((DMAMODE) == ADC_DMAMODE_ENABLE))

#define IS_ADC_ALL_OVERMODE(OVERMODE)            (((OVERMODE) == ADC_OVERMODE_DISABLE) || \
                                                  ((OVERMODE) == ADC_OVERMODE_ENABLE))

#define IS_ADC_ALL_OVERSAMPMODE(OVERSAMPMODE)    (((OVERSAMPMODE) == ADC_OVERSAMPMODE_DISABLE) || \
                                                  ((OVERSAMPMODE) == ADC_OVERSAMPMODE_ENABLE))
                                                  
#define IS_ADC_ALL_OVSS(_OVSS)             (((_OVSS) == ADC_CR2_OVSS_0) || \
                                            ((_OVSS) == ADC_CR2_OVSS_1) || \
                                            ((_OVSS) == ADC_CR2_OVSS_2) || \
                                            ((_OVSS) == ADC_CR2_OVSS_3) || \
                                            ((_OVSS) == ADC_CR2_OVSS_4) || \
                                            ((_OVSS) == ADC_CR2_OVSS_5) || \
                                            ((_OVSS) == ADC_CR2_OVSS_6) || \
                                            ((_OVSS) == ADC_CR2_OVSS_7) || \
                                            ((_OVSS) == ADC_CR2_OVSS_8))
                                            
#define IS_ADC_ALL_OVSR(_OVSR)             (((_OVSR) == ADC_CR2_OVSR_2X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_4X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_8X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_16X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_32X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_64X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_128X) || \
                                            ((_OVSR) == ADC_CR2_OVSR_256X))
                                            
#define IS_ADC_ALL_ANALOGWDGEN(ANALOGWDGEN)      (((ANALOGWDGEN) == ADC_ANALOGWDGEN_DISABLE) || \
                                                  ((ANALOGWDGEN) == ADC_ANALOGWDGEN_ENABLE))

#define IS_ADC_ALL_CLOCKDIV(CLOCKDIV)      (((CLOCKDIV) == ADC_CLOCK_DIV1) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV2) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV3) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV4) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV5) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV6) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV7) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV8) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV9) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV10) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV11) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV12) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV13) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV14) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV15) || \
                                            ((CLOCKDIV) == ADC_CLOCK_DIV16))

#define IS_ADC_ALL_SEQUENCE(SEQUENCE)      (((SEQUENCE) == ADC_SEQUENCE_SQ1) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ2) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ3) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ4) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ5) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ6) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ7) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ8) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ9) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ10) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ11) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ12) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ13) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ14) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ15) || \
                                            ((SEQUENCE) == ADC_SEQUENCE_SQ16))

#define IS_ADC_ALL_CHANNEL(CHANNEL)        (((CHANNEL) == ADC_CHANNEL_0) || \
                                            ((CHANNEL) == ADC_CHANNEL_1) || \
                                            ((CHANNEL) == ADC_CHANNEL_2) || \
                                            ((CHANNEL) == ADC_CHANNEL_3) || \
                                            ((CHANNEL) == ADC_CHANNEL_4) || \
                                            ((CHANNEL) == ADC_CHANNEL_5) || \
                                            ((CHANNEL) == ADC_CHANNEL_6) || \
                                            ((CHANNEL) == ADC_CHANNEL_7) || \
                                            ((CHANNEL) == ADC_CHANNEL_8) || \
                                            ((CHANNEL) == ADC_CHANNEL_9) || \
                                            ((CHANNEL) == ADC_CHANNEL_10) || \
                                            ((CHANNEL) == ADC_CHANNEL_11) || \
                                            ((CHANNEL) == ADC_CHANNEL_12) || \
                                            ((CHANNEL) == ADC_CHANNEL_13) || \
                                            ((CHANNEL) == ADC_CHANNEL_14) || \
                                            ((CHANNEL) == ADC_CHANNEL_15) || \
                                            ((CHANNEL) == ADC_CHANNEL_TEMP) || \
                                            ((CHANNEL) == ADC_CHANNEL_VBAT) || \
                                            ((CHANNEL) == ADC_CHANNEL_VBGR) || \
                                            ((CHANNEL) == ADC_CHANNEL_EXT2) || \
                                            ((CHANNEL) == ADC_CHANNEL_EXT3))

#define IS_ADC_ALL_CHANNELEN(CHANNELEN)    ((CHANNELEN) <= 0x1FFFFF)

#define IS_ADC_ALL_SMPCLOCK(SMPCLOCK)      (((SMPCLOCK) == ADC_SMP_CLOCK_3) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_5) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_7) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_10) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_13) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_16) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_20) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_30) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_60) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_80) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_100) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_120) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_160) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_320) || \
                                            ((SMPCLOCK) == ADC_SMP_CLOCK_480) 

                                            
#define IS_ADC_ALL_TRIG(_TRIG)             (((_TRIG) == ADC_SOFTWARE_START) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG1) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG2) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG3) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG4) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG5) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG6) || \
                                            ((_TRIG) == ADC_EXTERNAL_TIG7))

#define IS_ADC_EVENT_TYPE(_EVENT)          (((_EVENT) == ADC_SR_AWD) || \
                                            ((_EVENT) == ADC_SR_OVERF) || \
                                            ((_EVENT) == ADC_SR_EOG) || \
                                            ((_EVENT) == ADC_SR_JEOC) || \
                                            ((_EVENT) == ADC_SR_EOC))
                                            
                                           

/** @defgroup ADCEx_External_trigger_edge_Injected ADC External Trigger Edge Injected
  * @{
  */ 
#define ADC_EXTERNALTRIGINJECCONVEDGE_NONE           (0x00U)
#define ADC_EXTERNALTRIGINJECCONVEDGE_RISING         (0x01U)
#define ADC_EXTERNALTRIGINJECCONVEDGE_FALLING        (0x02U)
#define ADC_EXTERNALTRIGINJECCONVEDGE_RISINGFALLING  (0x03U)
/**
  * @}
  */ 

/** @defgroup ADCEx_injected_rank ADC Injected Rank
  * @{
  */ 
#define ADC_INJECTED_RANK_1    0x00000001U
#define ADC_INJECTED_RANK_2    0x00000002U
#define ADC_INJECTED_RANK_3    0x00000003U
#define ADC_INJECTED_RANK_4    0x00000004U
/**
  * @}
  */
  
/** @defgroup ADC_HAL Multimode - Mode
  * @{
  */
#define ADC_MODE_INDEPENDENT               (0x0000)                                          /*!< ADC dual mode disabled (ADC independent mode) */
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT (0x0001) /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected simultaneous */
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG   (0x0002) /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected alternate trigger */
#define ADC_DUALMODE_REGINTERL_INJECSIMULT (0x0003) /*!< ADC dual mode enabled: Combined group regular interleaved + group injected simultaneous */
#define ADC_DUALMODE_INJECSIMULT           (0x0005) /*!< ADC dual mode enabled: group injected simultaneous */
#define ADC_DUALMODE_REGSIMULT             (0x0006) /*!< ADC dual mode enabled: group regular simultaneous */
#define ADC_DUALMODE_INTERL                (0x0007) /*!< ADC dual mode enabled: Combined group regular interleaved */
#define ADC_DUALMODE_ALTERTRIG             (0x0009) /*!< ADC dual mode enabled: group injected alternate trigger. Works only with external triggers (not internal SW start) */
/**
  * @}
  */
  
/** @defgroup ADC_HAL_ Multimode - DMA transfer mode depending on ADC resolution
  * @{
  */
#define ADC_DMAACCESSMODE_DISABLED      (0x00000000UL)     /*!< DMA multimode disabled: each ADC uses its own DMA channel */
#define ADC_DMAACCESSMODE_12_10_BITS    (0x02)   /*!< DMA multimode enabled (one DMA channel for both ADC, DMA of ADC master) for 12 and 10 bits resolution */
#define ADC_DMAACCESSMODE_8_6_BITS      (0x03)     /*!< DMA multimode enabled (one DMA channel for both ADC, DMA of ADC master) for 8 and 6 bits resolution */
/**
  * @}
  */
  
/** @defgroup ADC_delay_between_2_sampling_phases ADC Delay Between 2 Sampling Phases
  * @{
  */ 
#define ADC_TWOSAMPLINGDELAY_5CYCLES    (0x0000U)
#define ADC_TWOSAMPLINGDELAY_6CYCLES    (0x0001U)
#define ADC_TWOSAMPLINGDELAY_7CYCLES    (0x0002U)
#define ADC_TWOSAMPLINGDELAY_8CYCLES    (0x0003U)
#define ADC_TWOSAMPLINGDELAY_9CYCLES    (0x0004U)
#define ADC_TWOSAMPLINGDELAY_10CYCLES   (0x0005U)
#define ADC_TWOSAMPLINGDELAY_11CYCLES   (0x0006U)
#define ADC_TWOSAMPLINGDELAY_12CYCLES   (0x0007U)
#define ADC_TWOSAMPLINGDELAY_13CYCLES   (0x0008U)
#define ADC_TWOSAMPLINGDELAY_14CYCLES   (0x0009U)
#define ADC_TWOSAMPLINGDELAY_15CYCLES   (0x000AU)
#define ADC_TWOSAMPLINGDELAY_16CYCLES   (0x000BU)
#define ADC_TWOSAMPLINGDELAY_17CYCLES   (0x000CU)
#define ADC_TWOSAMPLINGDELAY_18CYCLES   (0x000DU)
#define ADC_TWOSAMPLINGDELAY_19CYCLES   (0x000EU)
#define ADC_TWOSAMPLINGDELAY_20CYCLES   (0x000FU)
/**
  * @}
  */


/**
  * @brief  Set the selected injected Channel rank.
  * @param  _CHANNELNB_ Channel number.
  * @param  _RANKNB_ Rank number. 
  * @param  _JSQR_JL_ Sequence length.
  * @retval None
  */
#define   ADC_JSQR(_CHANNELNB_, _RANKNB_, _JSQR_JL_)  (((uint32_t)((uint16_t)(_CHANNELNB_))) << (5U * (uint8_t)(((_RANKNB_) + 3U) - (_JSQR_JL_))))


void HAL_ADC_IRQHandler(void);

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);

HAL_StatusTypeDef HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig);

HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);

HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);

uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef *hadc);

HAL_StatusTypeDef HAL_ADC_PollForEvent(ADC_HandleTypeDef *hadc, uint32_t EventType, uint32_t Timeout);

HAL_StatusTypeDef HAL_ADC_InjectedStart_IT(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_InjectedStop_IT(ADC_HandleTypeDef* hadc);

uint32_t HAL_ADC_InjectedGetValue(ADC_HandleTypeDef *hadc);

HAL_StatusTypeDef HAL_ADC_Polling(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length, uint32_t Timeout);

HAL_StatusTypeDef HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc, ADC_InjectionConfTypeDef* sConfigInjected);

HAL_StatusTypeDef HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_InjectedStop(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_InjectedStart_IT(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_InjectedStop_IT(ADC_HandleTypeDef* hadc);

uint32_t HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank);

#endif





