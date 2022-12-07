
/******************************************************************************
*@file  : hal_eflash.c
*@brief : EFlash HAL module driver.
*@ver   : 1.0.0
*@date  : 2022.10.20
******************************************************************************/

#include "hal.h"

#define EFLASH_BASE_FUNC_IN_ROM 

#ifdef EFLASH_BASE_FUNC_IN_ROM
    //ֱ�ӵ���ROM�д���
    #define HAL_EFLASH_ErasePage_InRom     ((void (*)(uint32_t addr))(0x12000629)) 
    #define HAL_EFLASH_ProgramWord_InRom   ((void (*)(uint32_t addrAlign4, uint32_t dat))(0x1200068D))
#else
    //��Ѵ���hal_eflash_sram.c���빤�̣����Ѵ������ӵ�SRAM�ռ�
    void HAL_EFLASH_ErasePage_InSram(uint32_t addr);
    void HAL_EFLASH_ProgramWord_InSram(uint32_t addrAlign4, uint32_t dat);
#endif


uint32_t HAL_EFLASH_EnterCritical(void)
{
    uint32_t sr;
    sr = __get_PRIMASK();      
    __set_PRIMASK(1);
    SCB->ICSR = BIT25;   // clear systick pending bit     
    return sr;
}

void HAL_EFLASH_ExitCritical(uint32_t sr)
{
    __set_PRIMASK(sr&0x01);
}


/******************************************************************************
*@brief : erase flash page.
*@param : addr: addr in the page.
*@return: status
******************************************************************************/
HAL_StatusTypeDef HAL_EFLASH_ErasePage(uint32_t addr)
{
    uint32_t sr;
    
    assert_param( ((addr>=EFLASH_MAIN_ADDR) && (addr < EFLASH_MAIN_ADDR+EFLASH_MAIN_SIZE)) 
               || ((addr >= EFLASH_NVR_ADDR) && (addr < EFLASH_NVR_ADDR+EFLASH_NVR_SIZE)) );
      
    addr = addr & (~(EFLASH_PAGE_SIZE-1));  //page�׵�ַ
    

    sr = HAL_EFLASH_EnterCritical();
    
#ifdef EFLASH_BASE_FUNC_IN_ROM    
    HAL_EFLASH_ErasePage_InRom(addr);    
#else  
    HAL_EFLASH_ErasePage_InSram(addr);  
#endif    
       
#if (DATA_ACCELERATE_ENABLE == 1)     
    System_InvalidateDAccelerate_by_Addr((uint32_t *)addr, EFLASH_PAGE_SIZE); 
#endif 
    
    HAL_EFLASH_ExitCritical(sr);
    
    return HAL_OK;

}


/******************************************************************************
*@brief : eflash ��ҳ����
*@param : addr: ��ʼ��ַ
*@param : pageNnum: Ҫ������ҳ����Ŀ
*@return: status
******************************************************************************/
HAL_StatusTypeDef HAL_EFLASH_ErasePages(uint32_t addr,uint32_t pageNnum)
{
    HAL_StatusTypeDef ret;
    while(pageNnum--)
    {
		ret = HAL_EFLASH_ErasePage(addr);
        if(ret!=HAL_OK)
        {
            return ret;
        }
		addr += EFLASH_PAGE_SIZE;
    }
    
	return HAL_OK;
}



/******************************************************************************
*@brief : program eflash word(32bit).
*@param : addr: program addr, must align 4
*@param : dat: program data.
*@return: status
******************************************************************************/
HAL_StatusTypeDef HAL_EFLASH_ProgramWord(uint32_t addrAlign4, uint32_t dat)
{   
    uint32_t sr;
    
    assert_param( ((addrAlign4>=EFLASH_MAIN_ADDR) && (addrAlign4 < EFLASH_MAIN_ADDR+EFLASH_MAIN_SIZE)) 
               || ((addrAlign4 >= EFLASH_NVR_ADDR) && (addrAlign4 < EFLASH_NVR_ADDR+EFLASH_NVR_SIZE)) );
    
    if (addrAlign4 & 0x03)
    {
        return HAL_ERROR; 
    }
    
    sr = HAL_EFLASH_EnterCritical();
    
#ifdef EFLASH_BASE_FUNC_IN_ROM
    HAL_EFLASH_ProgramWord_InRom(addrAlign4,dat);
#else    
    HAL_EFLASH_ProgramWord_InSram(addrAlign4,dat);
#endif    

    HAL_EFLASH_ExitCritical(sr);
    
    return HAL_OK;

}

/******************************************************************************
*@brief : eflash���WORD���ݡ����ñ�����ǰ�����Ȳ���FLASH���ݡ�
*@param : addrAlign4:  ��ʼ��ַ������4�ֽڶ�׼
*@param : buff: ���ݻ��棬����Ҫ4�ֽڶ�׼�������ȱ���4�ֽڵı���
*@param : wordNum: д���32bit word ��Ŀ
*@return: status
******************************************************************************/
HAL_StatusTypeDef HAL_EFLASH_ProgramWords(uint32_t addrAlign4, void *buff, uint32_t wordNum)
{
    static volatile uint32_t count=0;
    uint32_t dat;
    uint8_t *byteptr;
    uint32_t *wordptr; 
    HAL_StatusTypeDef ret;	

    if((uint32_t)buff & 0x03)  //��������ָ��4�ֽڶ�׼
    {
        byteptr=(uint8_t *)buff;
        while(wordNum--)
        {
            memcpy(&dat,byteptr,4);
            ret = HAL_EFLASH_ProgramWord(addrAlign4,dat);          
            addrAlign4 += 4;
            byteptr += 4;        
            if(ret!=HAL_OK)
            {
                return ret;
            }
        }
    }
    else
    {
        wordptr=(uint32_t *)buff;
        while(wordNum--)
        {
            ret = HAL_EFLASH_ProgramWord(addrAlign4,*wordptr++);  
            addrAlign4 += 4;   
            if(ret!=HAL_OK)
            {
                return ret;
            } 
        }        
    }

	return HAL_OK; 
}

/******************************************************************************
*@brief : flash���������ַ��buff�����ȶ���4�ֽڶ�׼�����ڲ��Զ���WORD��ȡ�����Ч�ʡ������ֽڶ���
*@param : addr: ��ʼ��ַ
*@param : buff: ���ݻ���
*@param : byteNum: Ҫ��ȡ���ֽ���Ŀ
*@return: status
******************************************************************************/
HAL_StatusTypeDef HAL_EFLASH_Read(uint32_t addr, void *buff, uint32_t byteNum)
{
	uint32_t i,len;
	uint8_t *bptrFlash,*bptrBuff;
	uint32_t *wptrFlash,*wptrBuff;

    if((addr&0x03) || (byteNum&0x03) || ((uint32_t)buff & 0x03))   //���ֽڶ�
    {   
        bptrFlash = (uint8_t *)addr;
        bptrBuff =  (uint8_t *)buff;

        for (i = 0; i < byteNum; i++)
        {
            *bptrBuff++ = *bptrFlash++;
        }
    }
    else   //��WORD��
    {
        wptrFlash = (uint32_t *)addr;
        wptrBuff =  (uint32_t *)buff;
        
        len = byteNum >> 2;

        for (i = 0; i < len; i++)
        {
            *wptrBuff++ = *wptrFlash++;
        }         
    }
    
	return HAL_OK; 
}

/******************************************************************************
*@brief : eflash����ֽ����ݡ�
*           ������ҳ�������Զ��������ٱ�̡�
*           ���ڷ���ҳ�������Զ�����page���ݣ��������ٱ�̡�
*@param : addr: ��ʼ��ַ��
*@param : buff: ���ݻ��棬������uint8_t,uint16_t,uint32_t����
*@param : byteLen: Ҫ��̵��ֽ���Ŀ
*@return: status
******************************************************************************/
HAL_StatusTypeDef HAL_EFLASH_BackupEraseProgram(uint32_t addr, void *buff, uint32_t byteNum)
{
    uint16_t offset; 
    uint16_t writeLen;
    uint32_t writeAddr;
    uint8_t *writePtr;    
    uint32_t  flash_buff[EFLASH_PAGE_SIZE/4];
    uint8_t *ptrBuff = (uint8_t *)buff;

    
    offset = (addr & (EFLASH_PAGE_SIZE-1));	//��ҳ��ƫ��
    writeAddr = addr - offset;              //ҳ��ʼ��ַ

    while(byteNum>0)
    {
        //����д�볤��
        if(byteNum <= (EFLASH_PAGE_SIZE - offset))//д�����ݲ�����ҳ��ʣ��ռ䣬û�г���ҳ��Χ
        {
            writeLen = byteNum;
        }
        else
        {
            writeLen = EFLASH_PAGE_SIZE - offset;
        } 
        
        if(writeLen != EFLASH_PAGE_SIZE)//������ҳд��
        {
            HAL_EFLASH_Read(writeAddr, flash_buff, EFLASH_PAGE_SIZE);//������ҳ������
            memcpy(flash_buff+offset,ptrBuff,writeLen);
            
            writePtr = (uint8_t *)flash_buff;
        }
        else//��ҳд��
        {
            writePtr = ptrBuff;
        }
        
        //�Ȳ�����д��1������
        if(HAL_EFLASH_ErasePage(writeAddr)!=HAL_OK)
        {
            return HAL_ERROR;
        }
        
        if(HAL_EFLASH_ProgramWords(writeAddr,writePtr,EFLASH_PAGE_SIZE/4)!= HAL_OK)  
        {        
            return  HAL_ERROR;
        }  
        offset = 0;				            //ƫ��λ��Ϊ0 
        writeAddr += EFLASH_PAGE_SIZE;	    //д��ַƫ��        
        ptrBuff += writeLen;  	            //ָ��ƫ��
        byteNum -= writeLen;	            //�ֽ����ݼ�
    }
	return HAL_OK; 
}


