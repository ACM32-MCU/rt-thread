;/*****************************************************************************
; * @file:    startup_CM0.s
; * @purpose: CMSIS Cortex-M0 Core Device Startup File 
; *           for the ARM 'Microcontroller Prototyping System' 
; * @version: V1.0
; * @date:    
; *
; *****************************************************************************/
Stack_Size      EQU     0x00000600
Heap_Size       EQU     0x00000000
;__initial_sp    EQU    0x20003000       ;Define SP size

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT __Vectors

__Vectors       
                DCD     __initial_sp                ; Top of Stack
                DCD     Reset_Handler               ; Reset Handler
                DCD     NMI_Handler                 ; NMI Handler
                DCD     HardFault_Handler           ; Hard Fault Handler
                DCD     MemManage_Handler           ; MPU Fault Handler
                DCD     BusFault_Handler            ; Bus Fault Handler
                DCD     UsageFault_Handler          ; Usage Fault Handler
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     SVC_Handler                 ; SVCall Handler,SWI
                DCD     DebugMon_Handler            ; Debug Monitor Handler
                DCD     0                           ; Reserved
                DCD     PendSV_Handler              ; PendSV Handler
                DCD     SysTick_Handler             ; SysTick Handler

                ; External Interrupts
                DCD     WDT_IRQHandler              ; 0:  WDT_IRQHandler 
                DCD     LVD_IRQHandler              ; 1:  LVD_IRQHandler                     
                DCD     RTC_IRQHandler              ; 2:  RTC_IRQHandler
                DCD     RSV1_IRQHandler             ; 3:                    
                DCD     EFC_IRQHandler              ; 4:  EFC_IRQHandler 
                DCD     SRAM_PARITY_IRQHandler      ; 5:  SRAM_PARITY_IRQHandler
                DCD     CLKRDY_IRQHandler           ; 6:  CLKRDY_IRQHandler    
                DCD     EXTI0_IRQHandler            ; 7:  EXTI0_IRQHandler     
                DCD     EXTI1_IRQHandler            ; 8:  EXTI1_IRQHandler     
                DCD     EXTI2_IRQHandler            ; 9:  EXTI2_IRQHandler
                DCD     EXTI3_IRQHandler            ; 10: EXTI3_IRQHandler    
                DCD     EXTI4_IRQHandler            ; 11: EXTI4_IRQHandler    
                DCD     DMA1_IRQHandler             ; 12: DMA1_IRQHandler    
                DCD     DMA2_IRQHandler             ; 13: DMA2_IRQHandler    
                DCD     ADC1_2_IRQHandler           ; 14: ADC1_2_IRQHandler    
                DCD     RSV2_IRQHandler             ; 15:        
                DCD     DAC_IRQHandler              ; 16: DAC_IRQHandler    
                DCD     COMP1_2_IRQHandler          ; 17: COMP1_2_IRQHandler
                DCD     USB_IRQHandler              ; 18: USB_IRQHandler    
                DCD     CAN1_IRQHandler             ; 19: CAN1_IRQHandler
                DCD     CAN2_IRQHandler             ; 20: CAN2_IRQHandler    
                DCD     EXTI9_5_IRQHandler          ; 21: EXTI9_5_IRQHandler    
                DCD     TIM1_BRK_UP_TRG_COM_IRQHandler    ; 22: TIM1_BRK_UP_TRG_COM_IRQHandler
                DCD     TIM1_CC_IRQHandler          ; 23: TIM1_CC_IRQHandler
                DCD     TIM2_IRQHandler             ; 24: TIM2_IRQHandler
                DCD     TIM3_IRQHandler             ; 25: TIM3_IRQHandler 
                DCD     TIM6_IRQHandler             ; 26: TIM6_IRQHandler
                DCD     TIM7_IRQHandler             ; 27: TIM7_IRQHandler
                DCD     TIM8_BRK_UP_TRG_COM_IRQHandler    ; 28: TIM8_BRK_UP_TRG_COM_IRQHandler
                DCD     TIM8_CC_IRQHandler          ; 29: TIM8_CC_IRQHandler
                DCD     TIM15_IRQHandler            ; 30: TIM15_IRQHandler    
                DCD     TIM16_IRQHandler            ; 31: TIM16_IRQHandler
                DCD     TIM17_IRQHandler            ; 32: TIM17_IRQHandler        
                DCD     I2C1_IRQHandler             ; 33: I2C1_IRQHandler     
                DCD     I2C2_IRQHandler             ; 34: I2C2_IRQHandler    
                DCD     SPI1_IRQHandler             ; 35: SPI1_IRQHandler     
                DCD     SPI2_IRQHandler             ; 36: SPI2_IRQHandler    
                DCD     SPI3_IRQHandler             ; 37: SPI3_IRQHandler    
                DCD     I2S1_IRQHandler             ; 38: I2S1_IRQHandler    
                DCD     I2S2_IRQHandler             ; 39: I2S2_IRQHandler
                DCD     UART1_IRQHandler            ; 40: UART1_IRQHandler     
                DCD     UART2_IRQHandler            ; 41: UART2_IRQHandler
                DCD     UART3_IRQHandler            ; 42: UART3_IRQHandler
                DCD     UART4_IRQHandler            ; 43: UART4_IRQHandler
                DCD     EXTI15_10_IRQHandler        ; 44: EXTI15_10_IRQhandler
                DCD     USB_WAKEUP_IRQHandler       ; 45: USB_WAKEUP_IRQHandler
                DCD     LPUART1_IRQHandler          ; 46: LPUART1_IRQHandler
                DCD     LPTIM1_IRQHandler           ; 47: LPTIM1_IRQHandler
                DCD     RSV3_IRQHandler             ; 48:
                DCD     AES_IRQHandler              ; 49: AES_IRQHandler
                DCD     FPU_IRQHandler              ; 50: FPU_IRQHandler
                DCD     RSV4_IRQHandler             ; 51:
                DCD     STOP_RESET_IRQHandler       ; 52: STOP_RESET_IRQHandler        
                DCD     TIM4_IRQHandler             ; 53: TIM4_IRQHandler 
                DCD     COMP3_4_IRQHandler          ; 54: COMP3_4_IRQHandler
                DCD     IWDT_WAKEUP_IRQHandler      ; 55: IWDT_WAKEUP_IRQHandler
                AREA    |.text|, CODE, READONLY

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                IMPORT  main
                IMPORT  SystemInit

                    

                LDR     R0, =SystemInit
                BLX     R0
 
                
                LDR     R0, =__main
                BX      R0                  ;
                ENDP


NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT   WDT_IRQHandler             [WEAK]
                EXPORT   LVD_IRQHandler             [WEAK]
                EXPORT   RTC_IRQHandler             [WEAK]
                EXPORT   RSV1_IRQHandler            [WEAK]                    
                EXPORT   EFC_IRQHandler             [WEAK]
                EXPORT   SRAM_PARITY_IRQHandler     [WEAK]
                EXPORT   CLKRDY_IRQHandler          [WEAK]
                EXPORT   EXTI0_IRQHandler           [WEAK]
                EXPORT   EXTI1_IRQHandler           [WEAK]
                EXPORT   EXTI2_IRQHandler           [WEAK]
                EXPORT   EXTI3_IRQHandler           [WEAK]
                EXPORT   EXTI4_IRQHandler           [WEAK]
                EXPORT   DMA1_IRQHandler            [WEAK]
                EXPORT   DMA2_IRQHandler            [WEAK]
                EXPORT   ADC1_2_IRQHandler          [WEAK]
                EXPORT   RSV2_IRQHandler            [WEAK]
                EXPORT   DAC_IRQHandler             [WEAK]
                EXPORT   COMP1_2_IRQHandler         [WEAK]
                EXPORT   USB_IRQHandler             [WEAK]
                EXPORT   CAN1_IRQHandler            [WEAK]
                EXPORT   CAN2_IRQHandler            [WEAK]
                EXPORT   EXTI9_5_IRQHandler         [WEAK]
                EXPORT   TIM1_BRK_UP_TRG_COM_IRQHandler [WEAK]
                EXPORT   TIM1_CC_IRQHandler         [WEAK]
                EXPORT   TIM2_IRQHandler            [WEAK]
                EXPORT   TIM3_IRQHandler            [WEAK]
                EXPORT   TIM6_IRQHandler            [WEAK]
                EXPORT   TIM7_IRQHandler            [WEAK]
                EXPORT   TIM8_BRK_UP_TRG_COM_IRQHandler [WEAK]
                EXPORT   TIM8_CC_IRQHandler         [WEAK]
                EXPORT   TIM15_IRQHandler           [WEAK]
                EXPORT   TIM16_IRQHandler           [WEAK]    
                EXPORT   TIM17_IRQHandler           [WEAK]    
                EXPORT   I2C1_IRQHandler            [WEAK]
                EXPORT   I2C2_IRQHandler            [WEAK]
                EXPORT   SPI1_IRQHandler            [WEAK]
                EXPORT   SPI2_IRQHandler            [WEAK]
                EXPORT   SPI3_IRQHandler            [WEAK]
                EXPORT   I2S1_IRQHandler            [WEAK]
                EXPORT   I2S2_IRQHandler            [WEAK]
                EXPORT   UART1_IRQHandler           [WEAK]
                EXPORT   UART2_IRQHandler           [WEAK]
                EXPORT   UART3_IRQHandler           [WEAK]
                EXPORT   UART4_IRQHandler           [WEAK]
                EXPORT   EXTI15_10_IRQHandler       [WEAK]
                EXPORT   USB_WAKEUP_IRQHandler      [WEAK]
                EXPORT   LPUART1_IRQHandler         [WEAK]
                EXPORT   LPTIM1_IRQHandler          [WEAK]
                EXPORT   RSV3_IRQHandler            [WEAK]
                EXPORT   AES_IRQHandler             [WEAK]
                EXPORT   FPU_IRQHandler             [WEAK]
                EXPORT   RSV4_IRQHandler            [WEAK]
                EXPORT   STOP_RESET_IRQHandler      [WEAK]    
                EXPORT   TIM4_IRQHandler            [WEAK]
                EXPORT   COMP3_4_IRQHandler         [WEAK]
                EXPORT   IWDT_WAKEUP_IRQHandler     [WEAK]
                
                                        
WDT_IRQHandler
LVD_IRQHandler
RTC_IRQHandler 
RSV1_IRQHandler
EFC_IRQHandler
SRAM_PARITY_IRQHandler
CLKRDY_IRQHandler
EXTI0_IRQHandler
EXTI1_IRQHandler
EXTI2_IRQHandler
EXTI3_IRQHandler
EXTI4_IRQHandler
DMA1_IRQHandler
DMA2_IRQHandler
ADC1_2_IRQHandler
RSV2_IRQHandler
DAC_IRQHandler
COMP1_2_IRQHandler
USB_IRQHandler
CAN1_IRQHandler
CAN2_IRQHandler
EXTI9_5_IRQHandler
TIM1_BRK_UP_TRG_COM_IRQHandler
TIM1_CC_IRQHandler
TIM2_IRQHandler
TIM3_IRQHandler
TIM6_IRQHandler
TIM7_IRQHandler
TIM8_BRK_UP_TRG_COM_IRQHandler
TIM8_CC_IRQHandler
TIM15_IRQHandler
TIM16_IRQHandler
TIM17_IRQHandler
I2C1_IRQHandler
I2C2_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
SPI3_IRQHandler
I2S1_IRQHandler
I2S2_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
UART3_IRQHandler
UART4_IRQHandler
EXTI15_10_IRQHandler
USB_WAKEUP_IRQHandler
LPUART1_IRQHandler
LPTIM1_IRQHandler
RSV3_IRQHandler
AES_IRQHandler
FPU_IRQHandler
RSV4_IRQHandler
STOP_RESET_IRQHandler
TIM4_IRQHandler
COMP3_4_IRQHandler
IWDT_WAKEUP_IRQHandler
                B        .
                ENDP                                                                  
                 
                ALIGN
                                 
; User Initial Stack & Heap
                 
                IF      :DEF:__MICROLIB
                 
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                 
                ELSE
                 
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap
                 
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

                END
