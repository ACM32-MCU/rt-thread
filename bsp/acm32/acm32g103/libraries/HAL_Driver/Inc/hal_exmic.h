/*
  ******************************************************************************
  * @file    HAL_DMA.h
  * @version V1.0.0
  * @date    2020
  * @brief   Header file of DMA HAL module.
  ******************************************************************************
*/
#ifndef __HAL_EXMC_H__
#define __HAL_EXMC_H__

#include "ACM32Fxx_HAL.h"

/******************************************************************************/
/*                                                                            */
/*                   EXMC                                                     */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for EXMC_SNCTLx (x=1..4) register  **********/
#define EXMC_SNCTLx_MBKEN_Pos                 (0U)                               
#define EXMC_SNCTLx_MBKEN_Msk                 (0x1UL << EXMC_SNCTLx_MBKEN_Pos)      /*!< 0x00000001 */
#define EXMC_SNCTLx_MBKEN                     EXMC_SNCTLx_MBKEN_Msk                /*!< Memory bank enable bit */

#define EXMC_SNCTLx_MUXEN_Pos                 (1U)                               
#define EXMC_SNCTLx_MUXEN_Msk                 (0x1UL << EXMC_SNCTLx_MUXEN_Pos)      /*!< 0x00000002 */
#define EXMC_SNCTLx_MUXEN                     EXMC_SNCTLx_MUXEN_Msk                /*!< Address/data multiplexing enable bit */

#define EXMC_SNCTLx_MTYP_Pos                  (2U)                               
#define EXMC_SNCTLx_MTYP_Msk                  (0x3UL << EXMC_SNCTLx_MTYP_Pos)       /*!< 0x0000000C */
#define EXMC_SNCTLx_MTYP                      EXMC_SNCTLx_MTYP_Msk                 /*!< MTYP[1:0] bits (Memory type) */
#define EXMC_SNCTLx_MTYP_0                    (0x1UL << EXMC_SNCTLx_MTYP_Pos)       /*!< 0x00000004 */
#define EXMC_SNCTLx_MTYP_1                    (0x2UL << EXMC_SNCTLx_MTYP_Pos)       /*!< 0x00000008 */

#define EXMC_SNCTLx_MWID_Pos                  (4U)                               
#define EXMC_SNCTLx_MWID_Msk                  (0x3UL << EXMC_SNCTLx_MWID_Pos)       /*!< 0x00000030 */
#define EXMC_SNCTLx_MWID                      EXMC_SNCTLx_MWID_Msk                 /*!< MWID[1:0] bits (Memory data bus width) */
#define EXMC_SNCTLx_MWID_0                    (0x1UL << EXMC_SNCTLx_MWID_Pos)       /*!< 0x00000010 */
#define EXMC_SNCTLx_MWID_1                    (0x2UL << EXMC_SNCTLx_MWID_Pos)       /*!< 0x00000020 */

#define EXMC_SNCTLx_FACCEN_Pos                (6U)                               
#define EXMC_SNCTLx_FACCEN_Msk                (0x1UL << EXMC_SNCTLx_FACCEN_Pos)     /*!< 0x00000040 */
#define EXMC_SNCTLx_FACCEN                    EXMC_SNCTLx_FACCEN_Msk               /*!< Flash access enable */
#define EXMC_SNCTLx_BURSTEN_Pos               (8U)                               
#define EXMC_SNCTLx_BURSTEN_Msk               (0x1UL << EXMC_SNCTLx_BURSTEN_Pos)    /*!< 0x00000100 */
#define EXMC_SNCTLx_BURSTEN                   EXMC_SNCTLx_BURSTEN_Msk              /*!< Burst enable bit */
#define EXMC_SNCTLx_WAITPOL_Pos               (9U)                               
#define EXMC_SNCTLx_WAITPOL_Msk               (0x1UL << EXMC_SNCTLx_WAITPOL_Pos)    /*!< 0x00000200 */
#define EXMC_SNCTLx_WAITPOL                   EXMC_SNCTLx_WAITPOL_Msk              /*!< Wait signal polarity bit */
#define EXMC_SNCTLx_WRAPMOD_Pos               (10U)                              
#define EXMC_SNCTLx_WRAPMOD_Msk               (0x1UL << EXMC_SNCTLx_WRAPMOD_Pos)    /*!< 0x00000400 */
#define EXMC_SNCTLx_WRAPMOD                   EXMC_SNCTLx_WRAPMOD_Msk              /*!< Wrapped burst mode support */
#define EXMC_SNCTLx_WAITCFG_Pos               (11U)                              
#define EXMC_SNCTLx_WAITCFG_Msk               (0x1UL << EXMC_SNCTLx_WAITCFG_Pos)    /*!< 0x00000800 */
#define EXMC_SNCTLx_WAITCFG                   EXMC_SNCTLx_WAITCFG_Msk              /*!< Wait timing configuration */
#define EXMC_SNCTLx_WREN_Pos                  (12U)                              
#define EXMC_SNCTLx_WREN_Msk                  (0x1UL << EXMC_SNCTLx_WREN_Pos)       /*!< 0x00001000 */
#define EXMC_SNCTLx_WREN                      EXMC_SNCTLx_WREN_Msk                 /*!< Write enable bit */
#define EXMC_SNCTLx_WAITEN_Pos                (13U)                              
#define EXMC_SNCTLx_WAITEN_Msk                (0x1UL << EXMC_SNCTLx_WAITEN_Pos)     /*!< 0x00002000 */
#define EXMC_SNCTLx_WAITEN                    EXMC_SNCTLx_WAITEN_Msk               /*!< Wait enable bit */
#define EXMC_SNCTLx_EXTMOD_Pos                (14U)                              
#define EXMC_SNCTLx_EXTMOD_Msk                (0x1UL << EXMC_SNCTLx_EXTMOD_Pos)     /*!< 0x00004000 */
#define EXMC_SNCTLx_EXTMOD                    EXMC_SNCTLx_EXTMOD_Msk               /*!< Extended mode enable */
#define EXMC_SNCTLx_ASYNCWAIT_Pos             (15U)                              
#define EXMC_SNCTLx_ASYNCWAIT_Msk             (0x1UL << EXMC_SNCTLx_ASYNCWAIT_Pos)  /*!< 0x00008000 */
#define EXMC_SNCTLx_ASYNCWAIT                 EXMC_SNCTLx_ASYNCWAIT_Msk            /*!< Asynchronous wait */

#define EXMC_SNCTLx_CPS_Pos              (16U)                              
#define EXMC_SNCTLx_CPS_Msk              (0x1UL << EXMC_SNCTLx_CBURSTRW_Pos)   /*!< 0x00080000 */
#define EXMC_SNCTLx_CPS                  EXMC_SNCTLx_CBURSTRW_Msk             /*!< Write burst enable */

#define EXMC_SNCTLx_CBURSTRW_Pos              (19U)                              
#define EXMC_SNCTLx_CBURSTRW_Msk              (0x1UL << EXMC_SNCTLx_CBURSTRW_Pos)   /*!< 0x00080000 */
#define EXMC_SNCTLx_CBURSTRW                  EXMC_SNCTLx_CBURSTRW_Msk             /*!< Write burst enable */


/******************  Bit definition for EXMC_SNTCFGx (x=1..4) register  ******/
#define EXMC_SNTCFGx_ADDSET_Pos                (0U)                               
#define EXMC_SNTCFGx_ADDSET_Msk                (0xFUL << EXMC_SNTCFGx_ADDSET_Pos)     /*!< 0x0000000F */
#define EXMC_SNTCFGx_ADDSET                    EXMC_SNTCFGx_ADDSET_Msk               /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define EXMC_SNTCFGx_ADDSET_0                  (0x1UL << EXMC_SNTCFGx_ADDSET_Pos)     /*!< 0x00000001 */
#define EXMC_SNTCFGx_ADDSET_1                  (0x2UL << EXMC_SNTCFGx_ADDSET_Pos)     /*!< 0x00000002 */
#define EXMC_SNTCFGx_ADDSET_2                  (0x4UL << EXMC_SNTCFGx_ADDSET_Pos)     /*!< 0x00000004 */
#define EXMC_SNTCFGx_ADDSET_3                  (0x8UL << EXMC_SNTCFGx_ADDSET_Pos)     /*!< 0x00000008 */

#define EXMC_SNTCFGx_ADDHLD_Pos                (4U)                               
#define EXMC_SNTCFGx_ADDHLD_Msk                (0xFUL << EXMC_SNTCFGx_ADDHLD_Pos)     /*!< 0x000000F0 */
#define EXMC_SNTCFGx_ADDHLD                    EXMC_SNTCFGx_ADDHLD_Msk               /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define EXMC_SNTCFGx_ADDHLD_0                  (0x1UL << EXMC_SNTCFGx_ADDHLD_Pos)     /*!< 0x00000010 */
#define EXMC_SNTCFGx_ADDHLD_1                  (0x2UL << EXMC_SNTCFGx_ADDHLD_Pos)     /*!< 0x00000020 */
#define EXMC_SNTCFGx_ADDHLD_2                  (0x4UL << EXMC_SNTCFGx_ADDHLD_Pos)     /*!< 0x00000040 */
#define EXMC_SNTCFGx_ADDHLD_3                  (0x8UL << EXMC_SNTCFGx_ADDHLD_Pos)     /*!< 0x00000080 */

#define EXMC_SNTCFGx_DATAST_Pos                (8U)                               
#define EXMC_SNTCFGx_DATAST_Msk                (0xFFUL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x0000FF00 */
#define EXMC_SNTCFGx_DATAST                    EXMC_SNTCFGx_DATAST_Msk               /*!< DATAST [3:0] bits (Data-phase duration) */
#define EXMC_SNTCFGx_DATAST_0                  (0x01UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00000100 */
#define EXMC_SNTCFGx_DATAST_1                  (0x02UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00000200 */
#define EXMC_SNTCFGx_DATAST_2                  (0x04UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00000400 */
#define EXMC_SNTCFGx_DATAST_3                  (0x08UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00000800 */
#define EXMC_SNTCFGx_DATAST_4                  (0x10UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00001000 */
#define EXMC_SNTCFGx_DATAST_5                  (0x20UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00002000 */
#define EXMC_SNTCFGx_DATAST_6                  (0x40UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00004000 */
#define EXMC_SNTCFGx_DATAST_7                  (0x80UL << EXMC_SNTCFGx_DATAST_Pos)    /*!< 0x00008000 */

#define EXMC_SNTCFGx_BUSTURN_Pos               (16U)                              
#define EXMC_SNTCFGx_BUSTURN_Msk               (0xFUL << EXMC_SNTCFGx_BUSTURN_Pos)    /*!< 0x000F0000 */
#define EXMC_SNTCFGx_BUSTURN                   EXMC_SNTCFGx_BUSTURN_Msk              /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define EXMC_SNTCFGx_BUSTURN_0                 (0x1UL << EXMC_SNTCFGx_BUSTURN_Pos)    /*!< 0x00010000 */
#define EXMC_SNTCFGx_BUSTURN_1                 (0x2UL << EXMC_SNTCFGx_BUSTURN_Pos)    /*!< 0x00020000 */
#define EXMC_SNTCFGx_BUSTURN_2                 (0x4UL << EXMC_SNTCFGx_BUSTURN_Pos)    /*!< 0x00040000 */
#define EXMC_SNTCFGx_BUSTURN_3                 (0x8UL << EXMC_SNTCFGx_BUSTURN_Pos)    /*!< 0x00080000 */

#define EXMC_SNTCFGx_CLKDIV_Pos                (20U)                              
#define EXMC_SNTCFGx_CLKDIV_Msk                (0xFUL << EXMC_SNTCFGx_CLKDIV_Pos)     /*!< 0x00F00000 */
#define EXMC_SNTCFGx_CLKDIV                    EXMC_SNTCFGx_CLKDIV_Msk               /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define EXMC_SNTCFGx_CLKDIV_0                  (0x1UL << EXMC_SNTCFGx_CLKDIV_Pos)     /*!< 0x00100000 */
#define EXMC_SNTCFGx_CLKDIV_1                  (0x2UL << EXMC_SNTCFGx_CLKDIV_Pos)     /*!< 0x00200000 */
#define EXMC_SNTCFGx_CLKDIV_2                  (0x4UL << EXMC_SNTCFGx_CLKDIV_Pos)     /*!< 0x00400000 */
#define EXMC_SNTCFGx_CLKDIV_3                  (0x8UL << EXMC_SNTCFGx_CLKDIV_Pos)     /*!< 0x00800000 */

#define EXMC_SNTCFGx_DATLAT_Pos                (24U)                              
#define EXMC_SNTCFGx_DATLAT_Msk                (0xFUL << EXMC_SNTCFGx_DATLAT_Pos)     /*!< 0x0F000000 */
#define EXMC_SNTCFGx_DATLAT                    EXMC_SNTCFGx_DATLAT_Msk               /*!< DATLA[3:0] bits (Data latency) */
#define EXMC_SNTCFGx_DATLAT_0                  (0x1UL << EXMC_SNTCFGx_DATLAT_Pos)     /*!< 0x01000000 */
#define EXMC_SNTCFGx_DATLAT_1                  (0x2UL << EXMC_SNTCFGx_DATLAT_Pos)     /*!< 0x02000000 */
#define EXMC_SNTCFGx_DATLAT_2                  (0x4UL << EXMC_SNTCFGx_DATLAT_Pos)     /*!< 0x04000000 */
#define EXMC_SNTCFGx_DATLAT_3                  (0x8UL << EXMC_SNTCFGx_DATLAT_Pos)     /*!< 0x08000000 */

#define EXMC_SNTCFGx_ACCMOD_Pos                (28U)                              
#define EXMC_SNTCFGx_ACCMOD_Msk                (0x3UL << EXMC_SNTCFGx_ACCMOD_Pos)     /*!< 0x30000000 */
#define EXMC_SNTCFGx_ACCMOD                    EXMC_SNTCFGx_ACCMOD_Msk               /*!< ACCMOD[1:0] bits (Access mode) */
#define EXMC_SNTCFGx_ACCMOD_0                  (0x1UL << EXMC_SNTCFGx_ACCMOD_Pos)     /*!< 0x10000000 */
#define EXMC_SNTCFGx_ACCMOD_1                  (0x2UL << EXMC_SNTCFGx_ACCMOD_Pos)     /*!< 0x20000000 */
/**
  * @brief  EXMC NORSRAM Configuration Structure definition
  */
typedef struct
{
    uint32_t NSBank;                       /*!< Specifies the NORSRAM memory device that will be used.
                                              This parameter can be a value of @ref EXMC_NORSRAM_Bank                     */
    
    uint32_t DataAddressMux;               /*!< Specifies whether the address and data values are
                                              multiplexed on the data bus or not.
                                              This parameter can be a value of @ref EXMC_Data_Address_Bus_Multiplexing    */
    uint32_t MemoryType;                   /*!< Specifies the type of external memory attached to
                                              the corresponding memory device.
                                              This parameter can be a value of @ref EXMC_Memory_Type                      */  
    uint32_t MemoryDataWidth;              /*!< Specifies the external memory device width.
                                              This parameter can be a value of @ref EXMC_NORSRAM_Data_Width               */
    
    uint32_t BurstAccessMode;              /*!< Enables or disables the burst access mode for Flash memory,
                                              valid only with synchronous burst Flash memories.
                                              This parameter can be a value of @ref EXMC_Burst_Access_Mode                */
    
    uint32_t NwaitSignalPolarity;           /*!< Specifies the wait signal polarity, valid only when accessing
                                              the Flash memory in burst mode.
                                              This parameter can be a value of @ref EXMC_Wait_Signal_Polarity             */
    
    uint32_t WrapMode;                     /*!< Enables or disables the Wrapped burst access mode for Flash
                                              memory, valid only when accessing Flash memories in burst mode.
                                              This parameter can be a value of @ref EXMC_Wrap_Mode                        */
    uint32_t SynchronousNwaitCfg;             /*!< Enables or disables wait signal during asynchronous transfers,
                                              valid only with asynchronous Flash memories.
                                              This parameter can be a value of @ref EXMC_AsynchronousWait                 */
    uint32_t WriteEN;               /*!< Enables or disables the write operation in the selected device by the EXMC.
                                              This parameter can be a value of @ref EXMC_Write_Operation                  */
                                              
    uint32_t NwaitEN;                   /*!< Enables or disables the wait state insertion via wait
                                              signal, valid for Flash memory access in burst mode.
                                              This parameter can be a value of @ref EXMC_Wait_Signal                      */                                         
    uint32_t ExtendedMode;                 /*!< Enables or disables the extended mode.
                                              This parameter can be a value of @ref EXMC_Extended_Mode                    */                                          
    uint32_t AsynchronousWait;     
    
    uint32_t WriteMode;                   /*!< Enables or disables the write burst operation.
                                              This parameter can be a value of @ref EXMC_Write_Burst                      */
                                              
    uint32_t PageSize;                     /*!< Specifies the memory page size.
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
    EXMC_TypeDef                     *Instance;                 /*!< Register base address */
    EXMC_Ex_TypeDef                 *Instance_EX;                 /*!< Register base address */
    EXMC_NORSRAM_InitTypeDef         Init;                      /*!< CAN required parameters */
    EXMC_NORSRAM_TimingTypeDef      Timing;
    EXMC_NORSRAM_TimingTypeDef       WTiming;
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

//  */
HAL_StatusTypeDef  HAL_EXMC_Init(EXMC_HandleTypeDef *hexmc);
#endif
