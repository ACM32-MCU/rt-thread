/*
  ******************************************************************************
  * @file    HAL_EXMC.h
  * @version V1.0.0
  * @date    2022
  * @brief   Header file of EXMC HAL module.
  ******************************************************************************
*/
#ifndef __HAL_EXMC_H__
#define __HAL_EXMC_H__

#include "acm32g103_hal_conf.h"



/***************  Bits definition for EXMC_SNCTLX register  ******************/

#define EXMC_SNCTLX_SYNCWR_Pos                  ( 19U )
#define EXMC_SNCTLX_SYNCWR_Msk                  ( 0x1UL << EXMC_SNCTLX_SYNCWR_Pos )
#define EXMC_SNCTLX_SYNCWR                      ( EXMC_SNCTLX_SYNCWR_Msk )

#define EXMC_SNCTLX__Pos                        ( 16U )
#define EXMC_SNCTLX__Msk                        ( 0x7UL << EXMC_SNCTLX__Pos )
#define EXMC_SNCTLX_                            ( EXMC_SNCTLX__Msk )
#define EXMC_SNCTLX__0                          ( 0x1UL << EXMC_SNCTLX__Msk )
#define EXMC_SNCTLX__1                          ( 0x2UL << EXMC_SNCTLX__Msk )
#define EXMC_SNCTLX__2                          ( 0x4UL << EXMC_SNCTLX__Msk )

#define EXMC_SNCTLX_ASYNCWAIT_Pos               ( 15U )
#define EXMC_SNCTLX_ASYNCWAIT_Msk               ( 0x1UL << EXMC_SNCTLX_ASYNCWAIT_Pos )
#define EXMC_SNCTLX_ASYNCWAIT                   ( EXMC_SNCTLX_ASYNCWAIT_Msk )

#define EXMC_SNCTLX_EXMODEN_Pos                 ( 14U )
#define EXMC_SNCTLX_EXMODEN_Msk                 ( 0x1UL << EXMC_SNCTLX_EXMODEN_Pos )
#define EXMC_SNCTLX_EXMODEN                     ( EXMC_SNCTLX_EXMODEN_Msk )

#define EXMC_SNCTLX_NRWTEN_Pos                  ( 13U )
#define EXMC_SNCTLX_NRWTEN_Msk                  ( 0x1UL << EXMC_SNCTLX_NRWTEN_Pos )
#define EXMC_SNCTLX_NRWTEN                      ( EXMC_SNCTLX_NRWTEN_Msk )

#define EXMC_SNCTLX_WREN_Pos                    ( 12U )
#define EXMC_SNCTLX_WREN_Msk                    ( 0x1UL << EXMC_SNCTLX_WREN_Pos )
#define EXMC_SNCTLX_WREN                        ( EXMC_SNCTLX_WREN_Msk )

#define EXMC_SNCTLX_NRWTCFG_Pos                 ( 11U )
#define EXMC_SNCTLX_NRWTCFG_Msk                 ( 0x1UL << EXMC_SNCTLX_NRWTCFG_Pos )
#define EXMC_SNCTLX_NRWTCFG                     ( EXMC_SNCTLX_NRWTCFG_Msk )

#define EXMC_SNCTLX_WRAPEN_Pos                  ( 10U )
#define EXMC_SNCTLX_WRAPEN_Msk                  ( 0x1UL << EXMC_SNCTLX_WRAPEN_Pos )
#define EXMC_SNCTLX_WRAPEN                      ( EXMC_SNCTLX_WRAPEN_Msk )

#define EXMC_SNCTLX_NRWTPOL_Pos                 ( 9U )
#define EXMC_SNCTLX_NRWTPOL_Msk                 ( 0x1UL << EXMC_SNCTLX_NRWTPOL_Pos )
#define EXMC_SNCTLX_NRWTPOL                     ( EXMC_SNCTLX_NRWTPOL_Msk )

#define EXMC_SNCTLX_SBRSTEN_Pos                 ( 8U )
#define EXMC_SNCTLX_SBRSTEN_Msk                 ( 0x1UL << EXMC_SNCTLX_SBRSTEN_Pos )
#define EXMC_SNCTLX_SBRSTEN                     ( EXMC_SNCTLX_SBRSTEN_Msk )

#define EXMC_SNCTLX_NREN_Pos                    ( 6U )
#define EXMC_SNCTLX_NREN_Msk                    ( 0x1UL << EXMC_SNCTLX_NREN_Pos )
#define EXMC_SNCTLX_NREN                        ( EXMC_SNCTLX_NREN_Msk )

#define EXMC_SNCTLX_NRW_Pos                     ( 4U )
#define EXMC_SNCTLX_NRW_Msk                     ( 0x3UL << EXMC_SNCTLX_NRW_Pos )
#define EXMC_SNCTLX_NRW                         ( EXMC_SNCTLX_NRW_Msk )
#define EXMC_SNCTLX_NRW_0                       ( 0x1UL << EXMC_SNCTLX_NRW_Msk )
#define EXMC_SNCTLX_NRW_1                       ( 0x2UL << EXMC_SNCTLX_NRW_Msk )

#define EXMC_SNCTLX_NRTP_Pos                    ( 2U )
#define EXMC_SNCTLX_NRTP_Msk                    ( 0x3UL << EXMC_SNCTLX_NRTP_Pos )
#define EXMC_SNCTLX_NRTP                        ( EXMC_SNCTLX_NRTP_Msk )
#define EXMC_SNCTLX_NRTP_0                      ( 0x1UL << EXMC_SNCTLX_NRTP_Msk )
#define EXMC_SNCTLX_NRTP_1                      ( 0x2UL << EXMC_SNCTLX_NRTP_Msk )

#define EXMC_SNCTLX_NRMUX_Pos                   ( 1U )
#define EXMC_SNCTLX_NRMUX_Msk                   ( 0x1UL << EXMC_SNCTLX_NRMUX_Pos )
#define EXMC_SNCTLX_NRMUX                       ( EXMC_SNCTLX_NRMUX_Msk )

#define EXMC_SNCTLX_NRBKEN_Pos                  ( 0U )
#define EXMC_SNCTLX_NRBKEN_Msk                  ( 0x1UL << EXMC_SNCTLX_NRBKEN_Pos )
#define EXMC_SNCTLX_NRBKEN                      ( EXMC_SNCTLX_NRBKEN_Msk )


/***************  Bits definition for EXMC_SNTCFGX register  *****************/

#define EXMC_SNTCFGX_ASYNCMOD_Pos               ( 28U )
#define EXMC_SNTCFGX_ASYNCMOD_Msk               ( 0x3UL << EXMC_SNTCFGX_ASYNCMOD_Pos )
#define EXMC_SNTCFGX_ASYNCMOD                   ( EXMC_SNTCFGX_ASYNCMOD_Msk )
#define EXMC_SNTCFGX_ASYNCMOD_0                 ( 0x1UL << EXMC_SNTCFGX_ASYNCMOD_Msk )
#define EXMC_SNTCFGX_ASYNCMOD_1                 ( 0x2UL << EXMC_SNTCFGX_ASYNCMOD_Msk )

#define EXMC_SNTCFGX_DLAT_Pos                   ( 24U )
#define EXMC_SNTCFGX_DLAT_Msk                   ( 0xFUL << EXMC_SNTCFGX_DLAT_Pos )
#define EXMC_SNTCFGX_DLAT                       ( EXMC_SNTCFGX_DLAT_Msk )
#define EXMC_SNTCFGX_DLAT_0                     ( 0x1UL << EXMC_SNTCFGX_DLAT_Msk )
#define EXMC_SNTCFGX_DLAT_1                     ( 0x2UL << EXMC_SNTCFGX_DLAT_Msk )
#define EXMC_SNTCFGX_DLAT_2                     ( 0x4UL << EXMC_SNTCFGX_DLAT_Msk )
#define EXMC_SNTCFGX_DLAT_3                     ( 0x8UL << EXMC_SNTCFGX_DLAT_Msk )

#define EXMC_SNTCFGX_CKDIV_Pos                  ( 20U )
#define EXMC_SNTCFGX_CKDIV_Msk                  ( 0xFUL << EXMC_SNTCFGX_CKDIV_Pos )
#define EXMC_SNTCFGX_CKDIV                      ( EXMC_SNTCFGX_CKDIV_Msk )
#define EXMC_SNTCFGX_CKDIV_0                    ( 0x1UL << EXMC_SNTCFGX_CKDIV_Msk )
#define EXMC_SNTCFGX_CKDIV_1                    ( 0x2UL << EXMC_SNTCFGX_CKDIV_Msk )
#define EXMC_SNTCFGX_CKDIV_2                    ( 0x4UL << EXMC_SNTCFGX_CKDIV_Msk )
#define EXMC_SNTCFGX_CKDIV_3                    ( 0x8UL << EXMC_SNTCFGX_CKDIV_Msk )

#define EXMC_SNTCFGX_BUSLAT_Pos                 ( 16U )
#define EXMC_SNTCFGX_BUSLAT_Msk                 ( 0xFUL << EXMC_SNTCFGX_BUSLAT_Pos )
#define EXMC_SNTCFGX_BUSLAT                     ( EXMC_SNTCFGX_BUSLAT_Msk )
#define EXMC_SNTCFGX_BUSLAT_0                   ( 0x1UL << EXMC_SNTCFGX_BUSLAT_Msk )
#define EXMC_SNTCFGX_BUSLAT_1                   ( 0x2UL << EXMC_SNTCFGX_BUSLAT_Msk )
#define EXMC_SNTCFGX_BUSLAT_2                   ( 0x4UL << EXMC_SNTCFGX_BUSLAT_Msk )
#define EXMC_SNTCFGX_BUSLAT_3                   ( 0x8UL << EXMC_SNTCFGX_BUSLAT_Msk )

#define EXMC_SNTCFGX_DSET_Pos                   ( 8U )
#define EXMC_SNTCFGX_DSET_Msk                   ( 0xFFUL << EXMC_SNTCFGX_DSET_Pos )
#define EXMC_SNTCFGX_DSET                       ( EXMC_SNTCFGX_DSET_Msk )

#define EXMC_SNTCFGX_AHLD_Pos                   ( 4U )
#define EXMC_SNTCFGX_AHLD_Msk                   ( 0xFUL << EXMC_SNTCFGX_AHLD_Pos )
#define EXMC_SNTCFGX_AHLD                       ( EXMC_SNTCFGX_AHLD_Msk )
#define EXMC_SNTCFGX_AHLD_0                     ( 0x1UL << EXMC_SNTCFGX_AHLD_Msk )
#define EXMC_SNTCFGX_AHLD_1                     ( 0x2UL << EXMC_SNTCFGX_AHLD_Msk )
#define EXMC_SNTCFGX_AHLD_2                     ( 0x4UL << EXMC_SNTCFGX_AHLD_Msk )
#define EXMC_SNTCFGX_AHLD_3                     ( 0x8UL << EXMC_SNTCFGX_AHLD_Msk )

#define EXMC_SNTCFGX_ASET_Pos                   ( 0U )
#define EXMC_SNTCFGX_ASET_Msk                   ( 0xFUL << EXMC_SNTCFGX_ASET_Pos )
#define EXMC_SNTCFGX_ASET                       ( EXMC_SNTCFGX_ASET_Msk )
#define EXMC_SNTCFGX_ASET_0                     ( 0x1UL << EXMC_SNTCFGX_ASET_Msk )
#define EXMC_SNTCFGX_ASET_1                     ( 0x2UL << EXMC_SNTCFGX_ASET_Msk )
#define EXMC_SNTCFGX_ASET_2                     ( 0x4UL << EXMC_SNTCFGX_ASET_Msk )
#define EXMC_SNTCFGX_ASET_3                     ( 0x8UL << EXMC_SNTCFGX_ASET_Msk )


/***************  Bits definition for EXMC_SNWTCFGX register  ****************/

#define EXMC_SNWTCFGX_WASYNCMOD_Pos             ( 28U )
#define EXMC_SNWTCFGX_WASYNCMOD_Msk             ( 0x3UL << EXMC_SNWTCFGX_WASYNCMOD_Pos )
#define EXMC_SNWTCFGX_WASYNCMOD                 ( EXMC_SNWTCFGX_WASYNCMOD_Msk )
#define EXMC_SNWTCFGX_WASYNCMOD_0               ( 0x1UL << EXMC_SNWTCFGX_WASYNCMOD_Msk )
#define EXMC_SNWTCFGX_WASYNCMOD_1               ( 0x2UL << EXMC_SNWTCFGX_WASYNCMOD_Msk )

#define EXMC_SNWTCFGX_DLAT_Pos                  ( 24U )
#define EXMC_SNWTCFGX_DLAT_Msk                  ( 0xFUL << EXMC_SNWTCFGX_DLAT_Pos )
#define EXMC_SNWTCFGX_DLAT                      ( EXMC_SNWTCFGX_DLAT_Msk )
#define EXMC_SNWTCFGX_DLAT_0                    ( 0x1UL << EXMC_SNWTCFGX_DLAT_Msk )
#define EXMC_SNWTCFGX_DLAT_1                    ( 0x2UL << EXMC_SNWTCFGX_DLAT_Msk )
#define EXMC_SNWTCFGX_DLAT_2                    ( 0x4UL << EXMC_SNWTCFGX_DLAT_Msk )
#define EXMC_SNWTCFGX_DLAT_3                    ( 0x8UL << EXMC_SNWTCFGX_DLAT_Msk )

#define EXMC_SNWTCFGX_WBUSLAT_Pos               ( 16U )
#define EXMC_SNWTCFGX_WBUSLAT_Msk               ( 0xFUL << EXMC_SNWTCFGX_WBUSLAT_Pos )
#define EXMC_SNWTCFGX_WBUSLAT                   ( EXMC_SNWTCFGX_WBUSLAT_Msk )
#define EXMC_SNWTCFGX_WBUSLAT_0                 ( 0x1UL << EXMC_SNWTCFGX_WBUSLAT_Msk )
#define EXMC_SNWTCFGX_WBUSLAT_1                 ( 0x2UL << EXMC_SNWTCFGX_WBUSLAT_Msk )
#define EXMC_SNWTCFGX_WBUSLAT_2                 ( 0x4UL << EXMC_SNWTCFGX_WBUSLAT_Msk )
#define EXMC_SNWTCFGX_WBUSLAT_3                 ( 0x8UL << EXMC_SNWTCFGX_WBUSLAT_Msk )

#define EXMC_SNWTCFGX_WDSET_Pos                 ( 8U )
#define EXMC_SNWTCFGX_WDSET_Msk                 ( 0xFFUL << EXMC_SNWTCFGX_WDSET_Pos )
#define EXMC_SNWTCFGX_WDSET                     ( EXMC_SNWTCFGX_WDSET_Msk )

#define EXMC_SNWTCFGX_WAHLD_Pos                 ( 4U )
#define EXMC_SNWTCFGX_WAHLD_Msk                 ( 0xFUL << EXMC_SNWTCFGX_WAHLD_Pos )
#define EXMC_SNWTCFGX_WAHLD                     ( EXMC_SNWTCFGX_WAHLD_Msk )
#define EXMC_SNWTCFGX_WAHLD_0                   ( 0x1UL << EXMC_SNWTCFGX_WAHLD_Msk )
#define EXMC_SNWTCFGX_WAHLD_1                   ( 0x2UL << EXMC_SNWTCFGX_WAHLD_Msk )
#define EXMC_SNWTCFGX_WAHLD_2                   ( 0x4UL << EXMC_SNWTCFGX_WAHLD_Msk )
#define EXMC_SNWTCFGX_WAHLD_3                   ( 0x8UL << EXMC_SNWTCFGX_WAHLD_Msk )

#define EXMC_SNWTCFGX_WASET_Pos                 ( 0U )
#define EXMC_SNWTCFGX_WASET_Msk                 ( 0xFUL << EXMC_SNWTCFGX_WASET_Pos )
#define EXMC_SNWTCFGX_WASET                     ( EXMC_SNWTCFGX_WASET_Msk )
#define EXMC_SNWTCFGX_WASET_0                   ( 0x1UL << EXMC_SNWTCFGX_WASET_Msk )
#define EXMC_SNWTCFGX_WASET_1                   ( 0x2UL << EXMC_SNWTCFGX_WASET_Msk )
#define EXMC_SNWTCFGX_WASET_2                   ( 0x4UL << EXMC_SNWTCFGX_WASET_Msk )
#define EXMC_SNWTCFGX_WASET_3                   ( 0x8UL << EXMC_SNWTCFGX_WASET_Msk )



/**
  * @brief  EXMC NORSRAM Configuration Structure definition
  */
typedef struct
{
    uint32_t NSBank;                        /*!< Specifies the NORSRAM memory device that will be used.
                                              This parameter can be a value of @ref EXMC_NORSRAM_Bank                     */

    uint32_t DataAddressMux;                /*!< Specifies whether the address and data values are
                                              multiplexed on the data bus or not.
                                              This parameter can be a value of @ref EXMC_Data_Address_Bus_Multiplexing    */
    uint32_t MemoryType;                    /*!< Specifies the type of external memory attached to
                                              the corresponding memory device.
                                              This parameter can be a value of @ref EXMC_Memory_Type                      */  
    uint32_t MemoryDataWidth;               /*!< Specifies the external memory device width.
                                              This parameter can be a value of @ref EXMC_NORSRAM_Data_Width               */

    uint32_t BurstAccessMode;               /*!< Enables or disables the burst access mode for Flash memory,
                                              valid only with synchronous burst Flash memories.
                                              This parameter can be a value of @ref EXMC_Burst_Access_Mode                */

    uint32_t NwaitSignalPolarity;           /*!< Specifies the wait signal polarity, valid only when accessing
                                              the Flash memory in burst mode.
                                              This parameter can be a value of @ref EXMC_Wait_Signal_Polarity             */

    uint32_t WrapMode;                      /*!< Enables or disables the Wrapped burst access mode for Flash
                                              memory, valid only when accessing Flash memories in burst mode.
                                              This parameter can be a value of @ref EXMC_Wrap_Mode                        */
    uint32_t SynchronousNwaitCfg;             /*!< Enables or disables wait signal during asynchronous transfers,
                                              valid only with asynchronous Flash memories.
                                              This parameter can be a value of @ref EXMC_AsynchronousWait                 */
    uint32_t WriteEN;                       /*!< Enables or disables the write operation in the selected device by the EXMC.
                                              This parameter can be a value of @ref EXMC_Write_Operation                  */
                                              
    uint32_t NwaitEN;                       /*!< Enables or disables the wait state insertion via wait
                                              signal, valid for Flash memory access in burst mode.
                                              This parameter can be a value of @ref EXMC_Wait_Signal                      */                                         
    uint32_t ExtendedMode;                  /*!< Enables or disables the extended mode.
                                              This parameter can be a value of @ref EXMC_Extended_Mode                    */                                          
    uint32_t AsynchronousWait;     

    uint32_t WriteMode;                     /*!< Enables or disables the write burst operation.
                                              This parameter can be a value of @ref EXMC_Write_Burst                      */
                                              
    uint32_t PageSize;                      /*!< Specifies the memory page size.
                                              This parameter can be a value of @ref EXMC_Page_Size                        */    

}EXMC_NORSRAM_InitTypeDef;

/**
  * @brief  EXMC NORSRAM Timing parameters structure definition
  */
typedef struct
{
    uint32_t AddressSetupTime;             /*!< Defines the number of HCLK cycles to configure
                                              the duration of the address setup time.
                                              This parameter can be a value between Min_Data = 0 and Max_Data = 15.
                                              @note This parameter is not used with synchronous NOR Flash memories.      */

    uint32_t AddressHoldTime;              /*!< Defines the number of HCLK cycles to configure
                                              the duration of the address hold time.
                                              This parameter can be a value between Min_Data = 1 and Max_Data = 15.
                                              @note This parameter is not used with synchronous NOR Flash memories.      */

    uint32_t DataSetupTime;                /*!< Defines the number of HCLK cycles to configure
                                              the duration of the data setup time.
                                              This parameter can be a value between Min_Data = 1 and Max_Data = 255.
                                              @note This parameter is used for SRAMs, ROMs and asynchronous multiplexed
                                              NOR Flash memories.                                                        */

    uint32_t BusTurnAroundDuration;        /*!< Defines the number of HCLK cycles to configure
                                              the duration of the bus turnaround.
                                              This parameter can be a value between Min_Data = 0 and Max_Data = 15.
                                              @note This parameter is only used for multiplexed NOR Flash memories.      */

    uint32_t CLKDivision;                  /*!< Defines the period of CLK clock output signal, expressed in number of
                                              HCLK cycles. This parameter can be a value between Min_Data = 2 and Max_Data = 16.
                                              @note This parameter is not used for asynchronous NOR Flash, SRAM or ROM
                                              accesses.                                                                  */

    uint32_t DataLatency;                  /*!< Defines the number of memory clock cycles to issue
                                              to the memory before getting the first data.
                                              The parameter value depends on the memory type as shown below:
                                              - It must be set to 0 in case of a CRAM
                                              - It is don't care in asynchronous NOR, SRAM or ROM accesses
                                              - It may assume a value between Min_Data = 2 and Max_Data = 17 in NOR Flash memories
                                                with synchronous burst mode enable                                       */

    uint32_t AccessMode;                   /*!< Specifies the asynchronous access mode.
                                              This parameter can be a value of @ref EXMC_Access_Mode                      */
}EXMC_NORSRAM_TimingTypeDef;

/**
  * @brief  EXMC handle Structure definition
  */
typedef struct
{
    EXMC_TypeDef                        *Instance;                 /*!< Register base address */
    EXMC_Ex_TypeDef                     *Instance_EX;                 /*!< Register base address */
    EXMC_NORSRAM_InitTypeDef            Init;                      /*!< CAN required parameters */
    EXMC_NORSRAM_TimingTypeDef          Timing;
    EXMC_NORSRAM_TimingTypeDef          WTiming;
} EXMC_HandleTypeDef;


/** @defgroup EXMC_NORSRAM_Bank EXMC NOR/SRAM Bank
  * @{
  */
#define EXMC_NORSRAM_BANK1                       ((uint32_t)0x00000000U)
#define EXMC_NORSRAM_BANK2                       ((uint32_t)0x00000002U)
#define EXMC_NORSRAM_BANK3                       ((uint32_t)0x00000004U)
#define EXMC_NORSRAM_BANK4                       ((uint32_t)0x00000006U)
/**
  * @}
  */

/** @defgroup EXMC_Data_Address_Bus_Multiplexing EXMC Data Address Bus Multiplexing
  * @{
  */
#define EXMC_DATA_ADDRESS_MUX_DISABLE            ((uint32_t)0x00000000U)
#define EXMC_DATA_ADDRESS_MUX_ENABLE             ((uint32_t)0x00000002U)
/**
  * @}
  */

/** @defgroup EXMC_Memory_Type EXMC Memory Type
  * @{
  */
#define EXMC_MEMORY_TYPE_SRAM                    ((uint32_t)0x00000000U)
#define EXMC_MEMORY_TYPE_PSRAM                   ((uint32_t)0x00000004U)
#define EXMC_MEMORY_TYPE_NOR                     ((uint32_t)0x00000008U)
/**
  * @}
  */
/** @defgroup EXMC_NORSRAM_Data_Width EXMC NORSRAM Data Width
  * @{
  */
#define EXMC_NORSRAM_MEM_BUS_WIDTH_8             ((uint32_t)0x00000000U)
#define EXMC_NORSRAM_MEM_BUS_WIDTH_16            ((uint32_t)0x00000010U)
#define EXMC_NORSRAM_MEM_BUS_WIDTH_32            ((uint32_t)0x00000020U)
/**
  * @}
  */

/** @defgroup EXMC_NORSRAM_Flash_Access EXMC NOR/SRAM Flash Access
  * @{
  */
#define EXMC_NORSRAM_FLASH_ACCESS_ENABLE         ((uint32_t)0x00000040U)
#define EXMC_NORSRAM_FLASH_ACCESS_DISABLE        ((uint32_t)0x00000000U)
/**
  * @}
  */

/** @defgroup EXMC_Burst_Access_Mode EXMC Burst Access Mode
  * @{
  */
#define EXMC_NORSRAM_FLASH_ACCESS_DISABLE           ((uint32_t)0x00000000U)
#define EXMC_NORSRAM_FLASH_ACCESS_ENABLE            ((uint32_t)0x00000040U)
/**
  * @}
  */

/** @defgroup EXMC_Burst_Access_Mode EXMC Burst Access Mode
  * @{
  */
#define EXMC_BURST_ACCESS_MODE_DISABLE           ((uint32_t)0x00000000U)
#define EXMC_BURST_ACCESS_MODE_ENABLE            ((uint32_t)0x00000100U)
/**
  * @}
  */
  
/** @defgroup EXMC_Wait_Signal_Polarity EXMC Wait Signal Polarity
  * @{
  */
#define EXMC_WAIT_SIGNAL_POLARITY_LOW            ((uint32_t)0x00000000U)
#define EXMC_WAIT_SIGNAL_POLARITY_HIGH           ((uint32_t)0x00000200U)
/**
  * @}
  */

/** @defgroup EXMC_Wrap_Mode EXMC Wrap Mode 
  * @{
  */
#define EXMC_WRAP_MODE_DISABLE                   ((uint32_t)0x00000000U)
#define EXMC_WRAP_MODE_ENABLE                    ((uint32_t)0x00000400U)
/**
  * @}
  */

/** @defgroup EXMC_Wait_Timing EXMC Wait Timing
  * @{
  */
#define EXMC_WAIT_TIMING_BEFORE_WS               ((uint32_t)0x00000000U)
#define EXMC_WAIT_TIMING_DURING_WS               ((uint32_t)0x00000800U)
/**
  * @}
  */

/** @defgroup EXMC_Write_Operation EXMC Write Operation
  * @{
  */
#define EXMC_WRITE_DISABLE             ((uint32_t)0x00000000U)
#define EXMC_WRITE_ENABLE              ((uint32_t)0x00001000U)
/**
  * @}
  */

/** @defgroup EXMC_Wait_Signal EXMC Wait Signal
  * @{
  */
#define EXMC_WAIT_SIGNAL_DISABLE                 ((uint32_t)0x00000000U)
#define EXMC_WAIT_SIGNAL_ENABLE                  ((uint32_t)0x00002000U)
/**
  * @}
  */

/** @defgroup EXMC_Extended_Mode EXMC Extended Mode
  * @{
  */
#define EXMC_EXTENDED_MODE_DISABLE               ((uint32_t)0x00000000U)
#define EXMC_EXTENDED_MODE_ENABLE                ((uint32_t)0x00004000U)
/**
  * @}
  */

/** @defgroup EXMC_AsynchronousWait EXMC Asynchronous Wait
  * @{
  */
#define EXMC_ASYNCHRONOUS_WAIT_DISABLE           ((uint32_t)0x00000000U)
#define EXMC_ASYNCHRONOUS_WAIT_ENABLE            ((uint32_t)0x00008000U)
/**
  * @}
  */

/** @defgroup EXMC_Page_Size EXMC Page Size
  * @{
  */
#define EXMC_PAGE_SIZE_NONE                      ((uint32_t)0x00000000U)
#define EXMC_PAGE_SIZE_128                       ((uint32_t)0x00010000U)
#define EXMC_PAGE_SIZE_256                       ((uint32_t)0x00020000U)
#define EXMC_PAGE_SIZE_512                       ((uint32_t)0x00030000U)
#define EXMC_PAGE_SIZE_1024                      ((uint32_t)0x00040000U)
/**
  * @}
  */

/** @defgroup EXMC_Write_Burst EXMC Write Burst
  * @{
  */
#define EXMC_WRITE_BURST_DISABLE                 ((uint32_t)0x00000000U)
#define EXMC_WRITE_BURST_ENABLE                  ((uint32_t)0x00080000U)
/**
  * @}
  */

/** @defgroup EXMC_Continous_Clock EXMC Continuous Clock
  * @{
  */
#define EXMC_CONTINUOUS_CLOCK_SYNC_ONLY          ((uint32_t)0x00000000U)
#define EXMC_CONTINUOUS_CLOCK_SYNC_ASYNC         ((uint32_t)0x00100000U)
/**
  * @}
  */

  /** @defgroup EXMC_Access_Mode EXMC Access Mode
  * @{
  */
#define EXMC_ACCESS_MODE_A                       ((uint32_t)0x00000000U)
#define EXMC_ACCESS_MODE_B                       ((uint32_t)0x10000000U)
#define EXMC_ACCESS_MODE_C                       ((uint32_t)0x20000000U)
#define EXMC_ACCESS_MODE_D                       ((uint32_t)0x30000000U)


HAL_StatusTypeDef  HAL_EXMC_Init(EXMC_HandleTypeDef *hexmc);


#endif
