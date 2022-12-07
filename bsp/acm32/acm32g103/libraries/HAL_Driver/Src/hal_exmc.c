/******************************************************************************
* @file      : HAL_EXMC.c
* @version   : 1.0
* @date      : 2022.10.25
* @brief     : EXMC HAL module driver
*   
* @history   :	
*   2022.10.25    lwq    create
*   
******************************************************************************/
#include "hal.h"

/******************************************************************************
* @brief : Initialize the EXMC MSP.
* @param : hexmc : pointer to a EXMC_HandleTypeDef structure that contains
*                 the configuration information for EXMC module.
* @return: none
******************************************************************************/
__weak void HAL_EXMC_MspInit(EXMC_HandleTypeDef *hexmc)
{
    
    /* Prevent unused argument(s) compilation warning */
    UNUSED(hexmc);

    /* NOTE: This function Should not be modified, when the callback is needed,
    the HAL_SDRAM_MspInit could be implemented in the user file
    */ 
}


/******************************************************************************
* @brief : Initialize the EXMC peripheral.
* @param : hexmc: Pointer to a EXMC_HandleTypeDef structure that contains
*                the configuration information for the specified EXMC module.
* @return: HAL status
******************************************************************************/
HAL_StatusTypeDef  HAL_EXMC_Init(EXMC_HandleTypeDef *hexmc)
{ 
    uint32_t flashaccess,TEMP;
    uint32_t index=hexmc->Init.NSBank;
    HAL_EXMC_MspInit(hexmc);
    /* Disable NORSRAM Device */
    hexmc->Instance->SNCTLCFG[index] &=~ EXMC_SNCTLX_NRBKEN;

    /* Set NORSRAM device control parameters */
    if (hexmc->Init.MemoryType == EXMC_MEMORY_TYPE_NOR)
    {
        flashaccess = EXMC_NORSRAM_FLASH_ACCESS_ENABLE;//EXMC_NORSRAM_FLASH_ACCESS_ENABLE
    }
    else
    {
        flashaccess = EXMC_NORSRAM_FLASH_ACCESS_DISABLE;
    }

    hexmc->Instance->SNCTLCFG[index]=(  flashaccess | \
                                        hexmc->Init.DataAddressMux | \
                                        hexmc->Init.MemoryType | \
                                        hexmc->Init.MemoryDataWidth | \
                                        hexmc->Init.BurstAccessMode | \
                                        hexmc->Init.NwaitSignalPolarity | \
                                        hexmc->Init.WrapMode | \
                                        hexmc->Init.SynchronousNwaitCfg | \
                                        hexmc->Init.WriteEN | \
                                        hexmc->Init.NwaitEN | \
                                        hexmc->Init.ExtendedMode | \
                                        hexmc->Init.AsynchronousWait | \
                                        hexmc->Init.WriteMode | \
                                        hexmc->Init.PageSize);           
    /* Set FSMC_NORSRAM device timing parameters */
    hexmc->Instance->SNCTLCFG[index+1]=(    hexmc->Timing.AddressSetupTime | \
                                            ((hexmc->Timing.AddressHoldTime) << EXMC_SNTCFGX_AHLD_Pos) | \
                                            ((hexmc->Timing.DataSetupTime) << EXMC_SNTCFGX_DSET_Pos) | \
                                            ((hexmc->Timing.BusTurnAroundDuration) << EXMC_SNTCFGX_BUSLAT_Pos) | \
                                            (((hexmc->Timing.CLKDivision)) << EXMC_SNTCFGX_CKDIV_Pos) | \
                                            (((hexmc->Timing.DataLatency)) < EXMC_SNTCFGX_DLAT_Pos) | \
                                            (hexmc->Timing.AccessMode));


    if(hexmc->Init.ExtendedMode == EXMC_EXTENDED_MODE_ENABLE)
    {

        hexmc->Instance_EX->SNWTCFG[index]=(    hexmc->WTiming.AddressSetupTime | \
                                                ((hexmc->WTiming.AddressHoldTime) << EXMC_SNWTCFGX_WAHLD_Pos) | \
                                                ((hexmc->WTiming.DataSetupTime) << EXMC_SNWTCFGX_WDSET_Pos) | \
                                                ((hexmc->WTiming.BusTurnAroundDuration) << EXMC_SNWTCFGX_WBUSLAT_Pos) | \
                                                (((hexmc->WTiming.CLKDivision)) << EXMC_SNTCFGX_CKDIV_Pos) | \
                                                (((hexmc->WTiming.DataLatency)) << EXMC_SNWTCFGX_DLAT_Pos) | \
                                                (hexmc->WTiming.AccessMode));
    }

    hexmc->Instance->SNCTLCFG[index]|= EXMC_SNCTLX_NRBKEN; 
    return HAL_OK;

}