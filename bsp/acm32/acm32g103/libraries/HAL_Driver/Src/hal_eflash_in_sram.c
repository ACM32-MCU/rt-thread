
/******************************************************************************
*@file  : hal_eflash_insram.c
*@brief : EFlash HAL module driver.these codes must are located in sram
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#include "hal.h"


/******************************************************************************
*@brief : erase flash page.
*@param : addr: addr in the page.
*@return: status
******************************************************************************/
void HAL_EFLASH_ErasePage_InSram(uint32_t addr)
{
    EFC->CTRL |= EFC_CTRL_PAGEERASEMODE;     
    EFC->SEC = 0x55AAAA55;
    *((volatile uint32_t *)addr) = 0;
    while ((EFC->STATUS & 1)==0);
    EFC->CTRL &= ~EFC_CTRL_PAGEERASEMODE;   

}


/******************************************************************************
*@brief : program eflash word(32bit).
*@param : addr: program addr.
*@param : dat: program data.
*@return: void
******************************************************************************/
void HAL_EFLASH_ProgramWord_InSram(uint32_t addrAlign4, uint32_t dat)
{   
  
    EFC->CTRL |= EFC_CTRL_WRITEMODE;
    EFC->SEC = 0x55AAAA55;   
    *((volatile uint32_t *)addrAlign4) = dat;
    while (!(EFC->STATUS & EFC_STATUS_EFLASHREADY));
    EFC->CTRL &= ~EFC_CTRL_WRITEMODE;    
}

