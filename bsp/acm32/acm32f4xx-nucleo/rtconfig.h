#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Project Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 100
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_HOOK_USING_FUNC_PTR
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 512

/* kservice optimization */

#define RT_DEBUG

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_SMALL_MEM_AS_HEAP
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_DEVICE_OPS
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 256
#define RT_CONSOLE_DEVICE_NAME "uart2"
#define RT_VER_NUM 0x40100

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 2048
#define RT_MAIN_THREAD_PRIORITY 10
#define RT_USING_MSH
#define RT_USING_FINSH
#define FINSH_USING_MSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_CMD_SIZE 256
#define MSH_USING_BUILT_IN_COMMANDS
#define FINSH_USING_DESCRIPTION
#define FINSH_ARG_MAX 10

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SERIAL
#define RT_USING_SERIAL_V1
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_CAN
#define RT_USING_HWTIMER
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_ADC
#define RT_USING_DAC
#define RT_USING_PWM
#define RT_USING_RTC
#define RT_USING_ALARM
#define RT_USING_SPI
#define RT_USING_SFUD
#define RT_SFUD_USING_SFDP
#define RT_SFUD_USING_FLASH_INFO_TABLE
#define RT_SFUD_SPI_MAX_HZ 20000000
#define RT_USING_AUDIO
#define RT_AUDIO_REPLAY_MP_BLOCK_SIZE 4096
#define RT_AUDIO_REPLAY_MP_BLOCK_COUNT 2
#define RT_AUDIO_RECORD_PIPE_SIZE 2048
#define RT_USING_HWCRYPTO
#define RT_HWCRYPTO_DEFAULT_NAME "hwcryto"
#define RT_HWCRYPTO_IV_MAX_SIZE 16
#define RT_HWCRYPTO_KEYBIT_MAX_SIZE 256
#define RT_HWCRYPTO_USING_AES
#define RT_HWCRYPTO_USING_AES_ECB
#define RT_HWCRYPTO_USING_AES_CBC
#define RT_HWCRYPTO_USING_SHA1
#define RT_HWCRYPTO_USING_SHA2
#define RT_HWCRYPTO_USING_SHA2_256
#define RT_HWCRYPTO_USING_RNG
#define RT_HWCRYPTO_USING_CRC
#define RT_HWCRYPTO_USING_CRC_07
#define RT_HWCRYPTO_USING_CRC_8005
#define RT_HWCRYPTO_USING_CRC_1021
#define RT_HWCRYPTO_USING_CRC_3D65
#define RT_HWCRYPTO_USING_CRC_04C11DB7

/* Using USB */

#define RT_USING_USB
#define RT_USING_USB_DEVICE
#define RT_USBD_THREAD_STACK_SZ 4096
#define USB_VENDOR_ID 0x0FFE
#define USB_PRODUCT_ID 0x0002
#define RT_USB_DEVICE_COMPOSITE
#define RT_USB_DEVICE_CDC
#define RT_USB_DEVICE_NONE
#define RT_USB_DEVICE_MSTORAGE
#define RT_VCOM_TASK_STK_SIZE 512
#define RT_CDC_RX_BUFSIZE 128
#define RT_VCOM_SERNO "32021919830108"
#define RT_VCOM_SER_LEN 14
#define RT_VCOM_TX_TIMEOUT 1000
#define RT_USB_MSTORAGE_DISK_NAME "norflash"

/* C/C++ and POSIX layer */

#define RT_LIBC_DEFAULT_TIMEZONE 8

/* POSIX (Portable Operating System Interface) layer */


/* Interprocess Communication (IPC) */


/* Socket is in the 'Network' category */


/* Network */


/* Utilities */

#define RT_USING_ULOG
#define ULOG_OUTPUT_LVL_D
#define ULOG_OUTPUT_LVL 7
#define ULOG_USING_ISR_LOG
#define ULOG_ASSERT_ENABLE
#define ULOG_LINE_BUF_SIZE 128

/* log format */

#define ULOG_USING_COLOR
#define ULOG_OUTPUT_TIME
#define ULOG_OUTPUT_LEVEL
#define ULOG_OUTPUT_TAG
#define ULOG_BACKEND_USING_CONSOLE

/* RT-Thread Utestcases */


/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */

/* JSON: JavaScript Object Notation, a lightweight data-interchange format */


/* XML: Extensible Markup Language */


/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */


/* u8g2: a monochrome graphic library */

#define PKG_USING_WAVPLAYER
#define PKG_WP_USING_PLAY
#define PKG_WP_PLAY_DEVICE "sound0"
#define PKG_WP_USING_RECORD
#define PKG_WP_RECORD_DEVICE "sound0"
#define PKG_USING_WAVPLAYER_LATEST_VERSION

/* PainterEngine: A cross-platform graphics application framework written in C language */


/* tools packages */


/* system packages */

/* enhanced kernel services */


/* acceleration: Assembly language or algorithmic acceleration packages */


/* CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */


/* Micrium: Micrium software products porting for RT-Thread */


/* peripheral libraries and drivers */


/* AI packages */


/* miscellaneous packages */

/* project laboratory */

/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */

#define PKG_USING_OPTPARSE
#define PKG_USING_OPTPARSE_LATEST_VERSION

/* Hardware Drivers Config */

#define SOC_ACM32F403RET7
#define SOC_SRAM_START_ADDR 0x20000000
#define SOC_FLASH_START_ADDR 0x00000000
#define SOC_PACKAGE_LQFP64
#define SOC_SRAM_SIZE 0xC0
#define SOC_FLASH_SIZE 0x200

/* Onboard Peripheral Drivers */

/* On-chip Peripheral Drivers */

/* Hardware GPIO */

#define BSP_USING_GPIO1
#define BSP_USING_GPIO2
#define BSP_USING_GPIO3

/* Hardware UART */

#define BSP_USING_UART1
#define BSP_USING_UART2
#define BSP_USING_RTC
#define BSP_USING_ALARM

/* Hardware I2C */


/* Hardware I2S */


/* Hardware CAN */


/* Hardware TIMER */


/* Hardware WDT */


/* Hardware SPI */

#define BSP_USING_SPI1
#define BSP_USING_SPI3

/* Hardware CRYPTO */

#define BSP_USING_CRC
#define BSP_USING_AES
#define BSP_USING_HRNG
#define BSP_USING_SHA1
#define BSP_USING_SHA256
#define BSP_USING_USBD

/* Board extended module Drivers */


#endif
