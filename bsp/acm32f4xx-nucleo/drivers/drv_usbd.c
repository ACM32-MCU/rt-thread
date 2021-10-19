/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-15     Aisinochip   First version
 */

#include <rtthread.h>
#include <rtdevice.h>

#ifdef BSP_USING_USBD
#include "board.h"
#include <string.h>

#define LOG_TAG              "usbd"
#define LOG_LVL              LOG_LVL_WARNING
#include <rtdbg.h>



struct urequest setup_req;
static struct udcd _acm_udc;
static struct ep_id _ep_pool[] =
{
    {USB_EP0,  USB_EP_ATTR_CONTROL,     USB_DIR_INOUT,  64, ID_ASSIGNED  },

    {USB_EP1,  USB_EP_ATTR_INT,         USB_DIR_IN,     64, ID_UNASSIGNED},
    {USB_EP1,  USB_EP_ATTR_INT,         USB_DIR_OUT,    64, ID_UNASSIGNED},

    {USB_EP2,  USB_EP_ATTR_BULK,        USB_DIR_IN,     64, ID_UNASSIGNED},
    {USB_EP2,  USB_EP_ATTR_BULK,        USB_DIR_OUT,    64, ID_UNASSIGNED},

    {USB_EP3,  USB_EP_ATTR_BULK,        USB_DIR_IN,     64, ID_UNASSIGNED},
    {USB_EP3,  USB_EP_ATTR_BULK,        USB_DIR_OUT,    64, ID_UNASSIGNED},

    {USB_EP4,  USB_EP_ATTR_BULK,        USB_DIR_IN,     64, ID_UNASSIGNED},
    {USB_EP4,  USB_EP_ATTR_BULK,        USB_DIR_OUT,    64, ID_UNASSIGNED},

    {0xFF, USB_EP_ATTR_TYPE_MASK,       USB_DIR_MASK,   0,  ID_ASSIGNED  },
};

static inline void disable_interrupt(uint32_t irq)
{
    CLEAR_BIT(USBINT->INT_EN, irq);
}
static inline void enable_interrupt(uint32_t irq)
{
    SET_BIT(USBINT->INT_EN, irq);
}
static inline void clear_interrupt(uint32_t irq)
{
    SET_BIT(USBINT->INT_CLR, irq);
}
static inline uint32_t get_raw_interrupt(void)
{
    return USBINT->INT_STAT_RAW;
}
static inline uint32_t epx_get_fifo_length(uint8_t epx)
{
    return USBCTRL->EPxCSR[epx] & 0xff;
}
static inline bool epx_validate_out_packet(uint8_t epx)
{
    /* toggle error */
    if (READ_BIT(USBCTRL->EPxCSR[epx], BIT19))
    {
        /* update out toggle want */
        USBCTRL->EPxCSR[epx] ^= BIT17;
        /* update want toggle  */
        SET_BIT(USBCTRL->EPxCSR[epx], BIT18);
        /* set rx ready, wait for a new packet */
        SET_BIT(USBCTRL->EPxCSR[epx], BIT11);

        return false;
    }

    return true;
}
static inline void epx_send_stall(uint8_t epx)
{
    SET_BIT(USBCTRL->EPxCSR[epx], BIT12);
    while (!READ_BIT(USBCTRL->EPxCSR[epx], BIT13));
    SET_BIT(USBCTRL->EPxCSR[epx], BIT13);
}
static inline void epx_clear_stall(uint8_t epx)
{
    /* clear in/out toggle, stall, stall status */
    WRITE_REG(USBCTRL->EPxCSR[epx], BIT8 | BIT13);
    /* enable epx out toggle want and epx in toggle value */
    SET_BIT(USBCTRL->EPxCSR[epx], BIT18 | BIT15);
}
static inline void epx_write_fifo(uint8_t epx, uint32_t offset, uint8_t *buffer, uint32_t size)
{
    uint8_t *dst;

    dst = (uint8_t *)(USB_BASE + 0x200 + (epx << 6) + offset);

    while (size--)
    {
        *dst++ = *buffer++;
    }
}
static inline void epx_read_fifo(uint8_t epx, uint32_t offset, uint8_t *buffer, uint32_t size)
{
    uint8_t *src;

    src = (uint8_t *)(USB_BASE + 0x200 + (epx << 6) + offset);
    while (size--)
    {
        *buffer++ = *src++;
    }
}

static bool epx_transmit(uint8_t epx, uint8_t *buffer, uint32_t size)
{
    /* write data to fifo */
    epx_write_fifo(epx, 0, buffer, size);

    /* set epx send byte count */
    WRITE_REG(USBCTRL->EPxSENDBN[epx], size);

    /* start data transmit */
    SET_BIT(USBCTRL->EPxCSR[epx], BIT10);

    /* query transmit done */
    while (!READ_BIT(USBCTRL->EPxCSR[epx], BIT24));

    return true;
}

static uint32_t epx_receive(uint8_t epx, uint8_t *buffer, uint32_t size)
{
    volatile uint32_t fifo_len;
    volatile uint32_t read_length;

    read_length = size;

    if (0 == READ_BIT(USBCTRL->EPxCSR[epx], BIT20))
    {
        return 0;
    }

    clear_interrupt(MASK_EPX_OUT(epx) | MASK_EPX_ACK(epx));

    /* clear epx out data flag */
    SET_BIT(USBCTRL->EPxCSR[epx], BIT20);

    if (!epx_validate_out_packet(epx))
    {
        return 0;
    }

    fifo_len = epx_get_fifo_length(epx);

    epx_read_fifo(epx, 0, buffer, fifo_len);

    return fifo_len;
}

static rt_err_t _ep_set_stall(rt_uint8_t address)
{
    LOG_D("_ep_set_stall %02X\n", address);
    epx_send_stall(address & USB_EPNO_MASK);
    return RT_EOK;
}

static rt_err_t _ep_clear_stall(rt_uint8_t address)
{
    LOG_D("_ep_clear_stall %02X\n", address);
    epx_clear_stall(address & USB_EPNO_MASK);
    return RT_EOK;
}

static rt_err_t _set_address(rt_uint8_t address)
{
    /* hardware do this */
    LOG_D("_set_address %02X\n", address);
    return RT_EOK;
}

static rt_err_t _set_config(rt_uint8_t address)
{
    LOG_D("_set_config %02X\n", address);
    return RT_EOK;
}

static rt_err_t _ep_enable(uep_t ep)
{
    RT_ASSERT(ep != RT_NULL);
    RT_ASSERT(ep->ep_desc != RT_NULL);

    LOG_D("_ep_enable ep[%02X] dir[%02X]\n", ep->id->addr, ep->id->dir);
    SET_BIT(USBCTRL->EPxCSR[ep->id->addr], BIT8);
    return RT_EOK;
}

static rt_err_t _ep_disable(uep_t ep)
{
    RT_ASSERT(ep != RT_NULL);
    RT_ASSERT(ep->ep_desc != RT_NULL);
    LOG_D("_ep_disable ep[%02X] dir[%02X]\n", ep->id->addr, ep->id->dir);

    CLEAR_BIT(USBCTRL->EPxCSR[ep->id->addr], BIT8);

    return RT_EOK;
}

static rt_size_t _ep_read(rt_uint8_t address, void *buffer)
{
    RT_ASSERT(buffer != RT_NULL);
    LOG_D("_ep_read %02X\n", address);

    return epx_receive(address & USB_EPNO_MASK, buffer, 0);
}

static rt_size_t _ep_read_prepare(rt_uint8_t address, void *buffer, rt_size_t size)
{
    LOG_D("_ep_read_prepare %02X %08X %04X\n", address, (uint32_t)buffer, size);
    /* set rx ready to wait next packet */
    SET_BIT(USBCTRL->EPxCSR[address & USB_EPNO_MASK], BIT11);
    return 0;
}

static rt_size_t _ep_write(rt_uint8_t address, void *buffer, rt_size_t size)
{
    LOG_D("EP%X [%d]-> ", address, size);
    epx_transmit(address & USB_EPNO_MASK, buffer, size);

    if ((address & USB_EPNO_MASK) == 0)
    {
        rt_usbd_ep0_in_handler(&_acm_udc);
    }
    else
    {
        rt_usbd_ep_in_handler(&_acm_udc, address, size);
    }

    return size;
}

static rt_err_t _ep0_send_status(void)
{
    LOG_D("_ep0_send_status\n");
    epx_transmit(USB_EP0, RT_NULL, 0);
    return RT_EOK;
}

static void _resume(void)
{
    LOG_D("_resume\n");
}

static rt_err_t _suspend(void)
{
    LOG_D("_suspend\n");
    return RT_EOK;
}

static rt_err_t _wakeup(void)
{
    LOG_D("_wakeup\n");
    return RT_EOK;
}

static void _bus_reset(void)
{
    LOG_D("_bus_reset\n");

    /* enable suspend interrupt */
    enable_interrupt(USB_SUSPEND);

    CLEAR_BIT(USBCTRL->WORKING_MODE, BIT6);

    /* bus auto reset diabled */
    if (!READ_BIT(USBCTRL->WORKING_MODE, BIT3))
    {
        SET_BIT(USBCTRL->WORKING_MODE, BIT2);
        CLEAR_BIT(USBCTRL->WORKING_MODE, BIT2);
    }

    /* clear in/out toggle,stall,stall status */
    WRITE_REG(USBCTRL->EPxCSR[1], BIT8 | BIT13);
    /* enable ep1 out/in toggle value */
    SET_BIT(USBCTRL->EPxCSR[1], BIT18 | BIT15);

    WRITE_REG(USBCTRL->EPxCSR[2], BIT8 | BIT13);
    /* enable ep2 out/in toggle value */
    SET_BIT(USBCTRL->EPxCSR[2], BIT18 | BIT15);

    WRITE_REG(USBCTRL->EPxCSR[3], BIT8 | BIT13);
    /* enable ep3 out/in toggle value */
    SET_BIT(USBCTRL->EPxCSR[3], BIT18 | BIT15);

    WRITE_REG(USBCTRL->EPxCSR[4], BIT8 | BIT13);
    /* enable ep4 out/in toggle value */
    SET_BIT(USBCTRL->EPxCSR[4], BIT18 | BIT15);

    rt_usbd_reset_handler(&_acm_udc);
}

static rt_err_t _usbd_init(rt_device_t device)
{
    LOG_D("_usbd_init\n");

    System_Module_Reset(RST_USB);
    System_Module_Enable(EN_USB);

    if (HAL_OK != System_USB_PHY_Config())
    {
        return -RT_ERROR;
    }

    /* PA11 --> USBFS_DM */
    SET_BIT(SCU->PABADS, BIT11);
    /* PA12 --> USBFS_DP */
    SET_BIT(SCU->PABADS, BIT12);

    NVIC_ClearPendingIRQ(USB_IRQn);
    NVIC_EnableIRQ(USB_IRQn);

    System_Delay(10);

    /* usb force reset */
    WRITE_REG(USBCTRL->WORKING_MODE, BIT2);
    System_Delay(3000);
    /* full speed | auto reset */
    WRITE_REG(USBCTRL->WORKING_MODE, BIT3 | BIT0);

    SET_BIT(USBCTRL->EPxCSR[0], BIT8);/* enable EP0 */
    SET_BIT(USBCTRL->EPxCSR[1], BIT8);/* enable EP1 */
    SET_BIT(USBCTRL->EPxCSR[2], BIT8);/* enable EP2 */
    SET_BIT(USBCTRL->EPxCSR[3], BIT8);/* enable EP3 */
    SET_BIT(USBCTRL->EPxCSR[4], BIT8);/* enable EP4 */
    WRITE_REG(USBCTRL->EPADDR_CFG, 0x4321);

    /* enable reset/suspend/resume/setup data/ ep1 out/ep2 out/ep3 out/ep4 out interrupt */
    WRITE_REG(USBINT->INT_EN, BIT19 | BIT16 | BIT13 | BIT10 | BIT5 | BIT2 | BIT1 | BIT0 | BIT7);

    /* connect */
    SET_BIT(USBCTRL->WORKING_MODE, BIT4 | BIT6);

    return RT_EOK;
}

const static struct udcd_ops _udc_ops =
{
    _set_address,
    _set_config,
    _ep_set_stall,
    _ep_clear_stall,
    _ep_enable,
    _ep_disable,
    _ep_read_prepare,
    _ep_read,
    _ep_write,
    _ep0_send_status,
    _suspend,
    _wakeup,
};

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops _ops =
{
    _usbd_init,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
};
#endif

int rt_hw_usbd_init(void)
{
    rt_memset((void *)&_acm_udc, 0, sizeof(struct udcd));

    _acm_udc.parent.type = RT_Device_Class_USBDevice;

#ifdef RT_USING_DEVICE_OPS
    _acm_udc.parent.ops = &_ops;
#else
    _acm_udc.parent.init = _init;
#endif

    _acm_udc.parent.user_data = RT_NULL;
    _acm_udc.ops = &_udc_ops;

    /* Register endpoint infomation */
    _acm_udc.ep_pool = _ep_pool;
    _acm_udc.ep0.id = &_ep_pool[0];

    rt_device_register((rt_device_t)&_acm_udc, "usbd", 0);

    rt_usb_device_init();

    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_hw_usbd_init);

static void usbd_isr(void)
{
    volatile uint32_t temp = 0;

    temp = get_raw_interrupt();

    /* ep0 out packet */
    if (temp & USB_EP0_OUT_PACKET)
    {
        rt_usbd_ep0_out_handler(&_acm_udc, USBCTRL->EPxCSR[USB_EP0] & 0x00FF);
        clear_interrupt(USB_EP0_OUT_PACKET);
    }

    /* ep1 out packet  */
    if (temp & USB_EP1_OUT_PACKET)
    {
        /* wait for ACK sent to host */
        while (!(get_raw_interrupt() & MASK_EPX_ACK(USB_EP1))) {};
        clear_interrupt(MASK_EPX_ACK(USB_EP1));

        if (epx_validate_out_packet(USB_EP1))
        {
            rt_usbd_ep_out_handler(&_acm_udc, USB_EP1, 0);
        }
        /* clear in token flag, for Interrupt tranfer type, in token flag may set after sending response */
        clear_interrupt(USB_EP1_OUT_PACKET | USB_EP1_IN);
    }

    /* ep2 out packet  */
    if (temp & USB_EP2_OUT_PACKET)
    {
        /* wait for ACK sent to host */
        while (!(get_raw_interrupt() & MASK_EPX_ACK(USB_EP2))) {};
        clear_interrupt(MASK_EPX_ACK(USB_EP2));

        if (epx_validate_out_packet(USB_EP2))
        {
            rt_usbd_ep_out_handler(&_acm_udc, USB_EP2, 0);
        }

        /* clear in token flag, for Interrupt tranfer type, in token flag may set after sending response */
        clear_interrupt(USB_EP2_OUT_PACKET | USB_EP2_IN);
    }

    /* ep3 out packet  */
    if (temp & USB_EP3_OUT_PACKET)
    {
        /* wait for ACK sent to host */
        while (!(get_raw_interrupt() & MASK_EPX_ACK(USB_EP3))) {};
        clear_interrupt(MASK_EPX_ACK(USB_EP3));

        if (epx_validate_out_packet(USB_EP3))
        {
            rt_usbd_ep_out_handler(&_acm_udc, USB_EP3, 0);
        }

        /* clear in token flag, for Interrupt tranfer type, in token flag may set after sending response */
        clear_interrupt(USB_EP3_OUT_PACKET | USB_EP3_IN);
    }

    /* ep4 out packet  */
    if (temp & USB_EP4_OUT_PACKET)
    {
        /* wait for ACK sent to host */
        while (!(get_raw_interrupt() & MASK_EPX_ACK(USB_EP4))) {};
        clear_interrupt(MASK_EPX_ACK(USB_EP4));

        if (epx_validate_out_packet(USB_EP4))
        {
            rt_usbd_ep_out_handler(&_acm_udc, USB_EP4, 0);
        }

        /* clear in token flag, for Interrupt tranfer type, in token flag may set after sending response */
        clear_interrupt(USB_EP4_OUT_PACKET | USB_EP4_IN);
    }

    /*  set address interrupt */
    if (temp & USB_SETADDR)
    {
        clear_interrupt(USB_SETADDR);
    }

    /* bus reset */
    if (temp & USB_BUS_RESET)
    {
        clear_interrupt(USB_BUS_RESET);
        _bus_reset();
    }

    /* suspend */
    if (temp & USB_SUSPEND)
    {
        clear_interrupt(USB_SUSPEND);
        disable_interrupt(USB_SUSPEND);
        SET_BIT(USBCTRL->WORKING_MODE, BIT6 | BIT4);
    }

    /* resume */
    if (temp & USB_RESUME)
    {
        clear_interrupt(USB_RESUME);
        /* ensable suspend interrupt */
        enable_interrupt(USB_SUSPEND);
        CLEAR_BIT(USBCTRL->WORKING_MODE, BIT6);
    }

    /* ep0 setup packet(SUDAV_RAW) */
    if (temp & USB_EP0_SETUP_PACKET)
    {
        clear_interrupt(USB_EP0_SETUP_PACKET);
        setup_req.request_type = USBCTRL->SETIP_0_3_DATA & 0xff;
        setup_req.bRequest = (USBCTRL->SETIP_0_3_DATA >> 8) & 0xff;
        setup_req.wValue   = (USBCTRL->SETIP_0_3_DATA >> 16) & 0xffff;
        setup_req.wIndex   = USBCTRL->SETIP_4_7_DATA & 0xffff;
        setup_req.wLength  = (USBCTRL->SETIP_4_7_DATA >> 16) & 0xffff;

        rt_usbd_ep0_setup_handler(&_acm_udc, &setup_req);
    }
}

void USB_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    /* interrupt service routine */
    usbd_isr();

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif

