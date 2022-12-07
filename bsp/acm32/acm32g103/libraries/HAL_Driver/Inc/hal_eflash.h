
/******************************************************************************
*@file  : hal_eflash.h
*@brief : EFlash HAL module driver header file.
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#ifndef __HAL_EFLASH_H__
#define __HAL_EFLASH_H__

#include "acm32g103_hal_conf.h"

//#define EFLASH_BASE_ADDR            (0UL)

#define EFLASH_PAGE_SIZE                    (512UL)

#define EFLASH_MAIN_ADDR                    EFLASH_BASE_ADDR
#define EFLASH_MAIN_SIZE                    (0x50000UL)

#define EFLASH_NVR_ADDR                     (EFLASH_BASE_ADDR+0x80000)
#define EFLASH_NVR_SIZE                     (EFLASH_PAGE_SIZE * 8)

#define EFLASH_NVR1_ADDR                    (EFLASH_NVR_ADDR+0x00000)
#define EFLASH_NVR2_ADDR                    (EFLASH_NVR_ADDR+0x00200)
#define EFLASH_NVR3_ADDR                    (EFLASH_NVR_ADDR+0x00400)
#define EFLASH_NVR4_ADDR                    (EFLASH_NVR_ADDR+0x00600)
#define EFLASH_NVR5_ADDR                    (EFLASH_NVR_ADDR+0x00800)
#define EFLASH_NVR6_ADDR                    (EFLASH_NVR_ADDR+0x00a00)
#define EFLASH_NVR7_ADDR                    (EFLASH_NVR_ADDR+0x00c00)
#define EFLASH_NVR8_ADDR                    (EFLASH_NVR_ADDR+0x00e00)


/***************  addr definition for EFLASH NVR region  *******************/

#define EFLASH_NVR2_BUSCRYPTEN_ADDR         (EFLASH_NVR2_ADDR+0x0004)
#define EFLASH_NVR2_UID0_ADDR               (EFLASH_NVR2_ADDR+0x0008)
#define EFLASH_NVR2_UID1_ADDR               (EFLASH_NVR2_ADDR+0x000C)
#define EFLASH_NVR2_UID2_ADDR               (EFLASH_NVR2_ADDR+0x0010)
#define EFLASH_NVR2_UID3_ADDR               (EFLASH_NVR2_ADDR+0x0014)
#define EFLASH_NVR2_RC64M_TRIM_ADDR         (EFLASH_NVR2_ADDR+0x0028)
#define EFLASH_NVR2_RC64M_VAL_ADDR          (EFLASH_NVR2_ADDR+0x002C)
#define EFLASH_NVR2_RC32K_VAL_ADDR          (EFLASH_NVR2_ADDR+0x0030)
#define EFLASH_NVR2_RC32K_TRIM_ADDR         (EFLASH_NVR2_ADDR+0x003C)
#define EFLASH_NVR2_ADC_12V_VAL_ADDR        (EFLASH_NVR2_ADDR+0x0040)
#define EFLASH_NVR2_ADC_VREFBI_VTRIM_ADDR   (EFLASH_NVR2_ADDR+0x0044)
#define EFLASH_NVR2_DAC_CAL_OS_ADDR         (EFLASH_NVR2_ADDR+0x0048)
#define EFLASH_NVR2_OPA1_CAL_OSPN_ADDR      (EFLASH_NVR2_ADDR+0x004C)
#define EFLASH_NVR2_OPA2_CAL_OSPN_ADDR      (EFLASH_NVR2_ADDR+0x0050)
#define EFLASH_NVR2_OPA3_CAL_OSPN_ADDR      (EFLASH_NVR2_ADDR+0x0054)
#define EFLASH_NVR2_CHIP_VER_ADDR           (EFLASH_NVR2_ADDR+0x0068)
#define EFLASH_NVR2_CHIP_IDH_ADDR           (EFLASH_NVR2_ADDR+0x00D0)
#define EFLASH_NVR2_CHIP_IDL_ADDR           (EFLASH_NVR2_ADDR+0x00D4)

#define EFLASH_NVR3_REMAP_ADDR              (EFLASH_NVR3_ADDR+0x0000)
#define EFLASH_NVR3_JTAG_DIS_ADDR           (EFLASH_NVR3_ADDR+0x001C)
#define EFLASH_NVR3_CODE_CRC16_ADDR         (EFLASH_NVR3_ADDR+0x0058)
#define EFLASH_NVR3_CODE_LEN_ADDR           (EFLASH_NVR3_ADDR+0x005C)
#define EFLASH_NVR3_CODE_START_ADDR         (EFLASH_NVR3_ADDR+0x0060)
#define EFLASH_NVR3_CODE_VALID_ADDR         (EFLASH_NVR3_ADDR+0x0078)

#define EFLASH_NVR4_PCROP_EN_ADDR           (EFLASH_NVR4_ADDR+0x0000)
#define EFLASH_NVR4_PCROP_AREAA_ADDR        (EFLASH_NVR4_ADDR+0x0004)
#define EFLASH_NVR4_PCROP_AREAB_ADDR        (EFLASH_NVR4_ADDR+0x0008)
#define EFLASH_NVR4_WRP_EN_ADDR             (EFLASH_NVR4_ADDR+0x0020)
#define EFLASH_NVR4_WRP_AREAA_ADDR          (EFLASH_NVR4_ADDR+0x0024)
#define EFLASH_NVR4_WRP_AREAB_ADDR          (EFLASH_NVR4_ADDR+0x0028)
#define EFLASH_NVR4_SECSIZE_VALID_ADDR      (EFLASH_NVR4_ADDR+0x0040)
#define EFLASH_NVR4_SECSIZE_EN_ADDR         (EFLASH_NVR4_ADDR+0x0044)
#define EFLASH_NVR4_RDP1_EN_ADDR            (EFLASH_NVR4_ADDR+0x0060)


#define EFLASH_RDWAIT_0WS                       ( 0U ) 
#define EFLASH_RDWAIT_1WS                       ( 1U ) 
#define EFLASH_RDWAIT_2WS                       ( 2U ) 
#define EFLASH_RDWAIT_3WS                       ( 3U ) 
#define EFLASH_RDWAIT_4WS                       ( 4U ) 
#define EFLASH_RDWAIT_5WS                       ( 5U ) 
#define EFLASH_RDWAIT_6WS                       ( 6U ) 
#define EFLASH_RDWAIT_7WS                       ( 7U ) 
#define EFLASH_RDWAIT_8WS                       ( 8U ) 
#define EFLASH_RDWAIT_ENSURE_OK                 ( EFLASH_RDWAIT_8WS )

#define HAL_EFLASH_SET_RDWAIT(wait)             {EFC->CTRL   = (EFC->CTRL & ~(EFC_CTRL_RDWAIT_Msk)) | (wait << EFC_CTRL_RDWAIT_Pos);}  

#define HAL_EFLASH_READ_WORD(Addr)              (*(volatile uint32_t *)(Addr))    // Read By Word
#define HAL_EFLASH_READ_HALFWORD(Addr)          (*(volatile uint16_t *)(Addr))    // Read By Half Word
#define HAL_EFLASH_READ_BYTE(Addr)              (*(volatile uint8_t *)(Addr))     // Read By Byte

/******************************************************************************
*@brief : Configure eflash parameter by system core clock freq.
*@param : sysClkFreq: system clock freq.
*@return: none
******************************************************************************/
__STATIC_INLINE void HAL_EFLASH_SetRdwaitBySysCoreClock(uint32_t sysCoreClkFreq)
{
    uint32_t rdWait;  

    if(sysCoreClkFreq > 120000000)
    {
        rdWait = 6;   
    }    
    else if(sysCoreClkFreq > 100000000)
    {
        rdWait = 5;   
    }  
    else if(sysCoreClkFreq > 80000000)
    {
        rdWait = 4;   
    }  
    else if(sysCoreClkFreq > 60000000) 
    {
        rdWait = 3;   
    }  
    else if(sysCoreClkFreq > 40000000) 
    {
        rdWait = 2;   
    }  
    else if(sysCoreClkFreq > 20000000) 
    {
        rdWait = 1;
    } 
    else
    {
       rdWait = 6;
    }

    HAL_EFLASH_SET_RDWAIT(rdWait);
}


HAL_StatusTypeDef HAL_EFLASH_ErasePage(uint32_t addr);
HAL_StatusTypeDef HAL_EFLASH_ErasePages(uint32_t addr,uint32_t pageNnum);
HAL_StatusTypeDef HAL_EFLASH_ProgramWord(uint32_t addrAlign4, uint32_t dat);
HAL_StatusTypeDef HAL_EFLASH_ProgramWords(uint32_t addrAlign4, void *buff, uint32_t wordNum);
HAL_StatusTypeDef HAL_EFLASH_Read(uint32_t addr, void *buff, uint32_t byteNum);
HAL_StatusTypeDef HAL_EFLASH_BackupEraseProgram(uint32_t addr, void *buff, uint32_t byteNum);

#endif
