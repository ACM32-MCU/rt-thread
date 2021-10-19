/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-28     AisinoChip   first version
 */

#include "board.h"

#if defined(RT_USING_FAL)
#include "fal.h"

static int fal_flash_read(long offset, rt_uint8_t *buf, size_t size);
static int fal_flash_write(long offset, const rt_uint8_t *buf, size_t size);
static int fal_flash_erase(long offset, size_t size);

struct fal_flash_dev acm32_onchip_flash = { "onchip_flash",
    256*1024, /* 256K */
    256*1024,
    EFLASH_PAGE_SIZE,
    {
        NULL,
        fal_flash_read,
        fal_flash_write,
        fal_flash_erase
    },
    8
};

static inline bool _flash_address_validate(long offset, size_t *size)
{
    if(offset > acm32_onchip_flash.len)
    {
        return false;
    }

    if(offset + *size > acm32_onchip_flash.len)
    {
        *size = acm32_onchip_flash.len - offset;
    }

    return true;
}

static inline bool _flash_write_bytes(uint32_t addr, const uint8_t* buf, size_t size)
{
    uint32_t wordAddr = addr &(~3);
    uint32_t remain = size;
    uint32_t value;
    uint32_t offset = 0;

    if(wordAddr < addr)
    {
        value = HAL_EFLASH_READ_WORD(wordAddr);

        if(wordAddr + 4 > addr + size)
        {
            rt_memcpy(((uint8_t*)&value)+addr-wordAddr, &buf[offset], size);
            remain = 0;
        }
        else
        {
            rt_memcpy(((uint8_t*)&value)+addr-wordAddr, &buf[offset], 4+wordAddr - addr);
            offset += 4 + wordAddr - addr;
            remain -= 4 + wordAddr - addr;
        }

        if(!HAL_EFlash_Program_Word(wordAddr, value))
        {
            return false;
        }
        wordAddr += 4 + wordAddr - addr;
    }

    while(remain >= 4)
    {
        rt_memcpy((uint8_t*)&value, &buf[offset], 4);
        if(!HAL_EFlash_Program_Word(wordAddr, value))
        {
            return false;
        }
        wordAddr += 4;
        remain -= 4;
        offset += 4;
    }

    if(remain > 0)
    {
        value = HAL_EFLASH_READ_WORD(wordAddr);
        rt_memcpy((uint8_t*)&value, &buf[offset], remain);
        if(!HAL_EFlash_Program_Word(wordAddr, value))
        {
            return false;
        }
    }

    return true;
}

static inline void _flash_read_bytes(uint32_t addr, uint8_t* buf, size_t size)
{
    rt_uint8_t *src = (rt_uint8_t*)addr;
    for(int i = 0; i< size; i++)
    {
        *buf++ = *src++;
    }
}

static int fal_flash_read(long offset, rt_uint8_t *buf, size_t size)
{
    if(!_flash_address_validate(offset, &size))
    {
        return 0;
    }

    _flash_read_bytes(acm32_onchip_flash.addr + offset, buf, size);

    return size;
}

static int fal_flash_write(long offset, const rt_uint8_t *buf, size_t size)
{
    if(!_flash_address_validate(offset, &size))
    {
        return 0;
    }
    if(!_flash_write_bytes(acm32_onchip_flash.addr + offset, buf, size))
    {
        return 0;
    }

    return size;
}

static int fal_flash_erase(long offset, size_t size)
{
    if(!_flash_address_validate(offset, &size))
    {
        return 0;
    }

    size_t remain = size;
    uint32_t addr = acm32_onchip_flash.addr + offset;
    rt_uint8_t sector[EFLASH_PAGE_SIZE];
    uint32_t sectorAddr = addr & (~(acm32_onchip_flash.blk_size - 1));
    uint32_t validByteCount = 0;

    if(sectorAddr < addr)
    {
        _flash_read_bytes(sectorAddr, sector, EFLASH_PAGE_SIZE);
        if(!HAL_EFlash_ErasePage(sectorAddr))
        {
            return 0;
        }

        if(!_flash_write_bytes(sectorAddr, sector, addr - sectorAddr))
        {
            return 0;
        }

        if(addr + remain < sectorAddr + EFLASH_PAGE_SIZE)
        {
            if(!_flash_write_bytes(addr + remain, &sector[addr + remain - sectorAddr ],
                        sectorAddr + EFLASH_PAGE_SIZE - addr - remain))
            {
                return 0;
            }
            remain = 0;
        }
        else
        {
            remain -= addr - sectorAddr;
            sectorAddr += EFLASH_PAGE_SIZE;
        }
    }

    while(remain >= EFLASH_PAGE_SIZE)
    {
        if(!HAL_EFlash_ErasePage(sectorAddr))
        {
            return 0;
        }
        sectorAddr += EFLASH_PAGE_SIZE;
        remain -= EFLASH_PAGE_SIZE;
    }

    if(remain > 0)
    {
        _flash_read_bytes(sectorAddr, sector, EFLASH_PAGE_SIZE);
        if(!HAL_EFlash_ErasePage(sectorAddr))
        {
            return 0;
        }

        if(!_flash_write_bytes(sectorAddr+remain, &sector[remain], EFLASH_PAGE_SIZE - remain))
        {
            return 0;
        }
    }

    return size;
}

#endif

