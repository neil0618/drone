#include <stdint.h>
#include "stm32f446xx.h"

// External variables defined in the linker script
extern uint32_t _sdata, _edata, _sidata;
extern uint32_t _sbss, _ebss;
extern uint32_t _estack;

// Function prototypes
extern int main(void);
void Reset_Handler(void);
void Default_Handler(void);

// Reset_Handler is the entry point after power on or reset
void Reset_Handler(void){
    // Enables prefetch buffer, instruction cache, data cache, and sets flash latency to 5 wait states for 180 MHz operation
    FLASH->ACR |= FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS;

    // Enables the Floating Point Unit (FPU)
    SCB->CPACR |= (0xF << 20);

    // Copies .data from FLASH to SRAM1
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while(dst < &_edata){
        *dst++ = *src++;
    }

    // Initializes .bss section to zero
    dst = &_sbss;
    while(dst < &_ebss){
        *dst++ = 0;
    }

    // Calls the main function
    main();

    // If main returns, enter an infinite loop
    while(1);
}

// Default_Handler enters an infinite loop on an unhandled interrupt
void Default_Handler(void){
    while(1);
}

// Default all unimplemented interrupt handlers to Default_Handler, can be overridden by user-defined handlers
__attribute__((weak, alias("Default_Handler"))) void NMI_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void HardFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void MemManage_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void BusFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void UsageFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SVC_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void DebugMon_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void PendSV_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SysTick_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void WWDG_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void PVD_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TAMP_STAMP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RTC_WKUP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void FLASH_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RCC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream5_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream6_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void ADC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN1_TX_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN1_RX0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN1_RX1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN1_SCE_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI9_5_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM1_BRK_TIM9_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM1_UP_TIM10_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM1_TRG_COM_TIM11_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM1_CC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2C1_EV_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2C1_ER_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2C2_EV_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2C2_ER_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPI1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPI2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void USART1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void USART2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void USART3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void EXTI15_10_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RTC_Alarm_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void OTG_FS_WKUP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM8_BRK_TIM12_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM8_UP_TIM13_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM8_TRG_COM_TIM14_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM8_CC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA1_Stream7_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void FMC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SDIO_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM5_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPI3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void UART4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void UART5_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM6_DAC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIM7_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void ETH_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void ETH_WKUP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN2_TX_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN2_RX0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN2_RX1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CAN2_SCE_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void OTG_FS_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream5_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream6_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DMA2_Stream7_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void USART6_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2C3_EV_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2C3_ER_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void OTG_HS_EP1_OUT_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void OTG_HS_EP1_IN_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void OTG_HS_WKUP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void OTG_HS_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void DCMI_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void FPU_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPI4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SAI1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SAI2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void QUADSPI_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CEC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPDIF_RX_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void FMPI2C1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void FMPI2C1_error_IRQHandler(void);

// Vector table to be placed at the start of FLASH
__attribute__((section(".isr_vector")))
uint32_t g_pfnVectors[] = {
    (uint32_t)&_estack,                         // Initial stack pointer
    (uint32_t)&Reset_Handler,                   // Reset
    (uint32_t)&NMI_Handler,                     // NMI
    (uint32_t)&HardFault_Handler,               // Hard fault
    (uint32_t)&MemManage_Handler,               // Memory management
    (uint32_t)&BusFault_Handler,                // Bus fault
    (uint32_t)&UsageFault_Handler,              // Usage fault
    0,                                          // Reserved
    0,                                          // Reserved
    0,                                          // Reserved
    0,                                          // Reserved
    (uint32_t)&SVC_Handler,                     // SVCall
    (uint32_t)&DebugMon_Handler,                // Debug monitor
    0,                                          // Reserved
    (uint32_t)&PendSV_Handler,                  // PendSV
    (uint32_t)&SysTick_Handler,                 // SysTick
    (uint32_t)&WWDG_IRQHandler,                 // Window watchdog
    (uint32_t)&PVD_IRQHandler,                  // PVD via EXTI
    (uint32_t)&TAMP_STAMP_IRQHandler,           // Tamper and timestamp
    (uint32_t)&RTC_WKUP_IRQHandler,             // RTC wakeup
    (uint32_t)&FLASH_IRQHandler,                // Flash
    (uint32_t)&RCC_IRQHandler,                  // RCC
    (uint32_t)&EXTI0_IRQHandler,                // EXTI line 0
    (uint32_t)&EXTI1_IRQHandler,                // EXTI line 1
    (uint32_t)&EXTI2_IRQHandler,                // EXTI line 2
    (uint32_t)&EXTI3_IRQHandler,                // EXTI line 3
    (uint32_t)&EXTI4_IRQHandler,                // EXTI line 4
    (uint32_t)&DMA1_Stream0_IRQHandler,         // DMA1 stream 0
    (uint32_t)&DMA1_Stream1_IRQHandler,         // DMA1 stream 1
    (uint32_t)&DMA1_Stream2_IRQHandler,         // DMA1 stream 2
    (uint32_t)&DMA1_Stream3_IRQHandler,         // DMA1 stream 3
    (uint32_t)&DMA1_Stream4_IRQHandler,         // DMA1 stream 4
    (uint32_t)&DMA1_Stream5_IRQHandler,         // DMA1 stream 5
    (uint32_t)&DMA1_Stream6_IRQHandler,         // DMA1 stream 6
    (uint32_t)&ADC_IRQHandler,                  // ADC
    (uint32_t)&CAN1_TX_IRQHandler,              // CAN1 TX
    (uint32_t)&CAN1_RX0_IRQHandler,             // CAN1 RX0
    (uint32_t)&CAN1_RX1_IRQHandler,             // CAN1 RX1
    (uint32_t)&CAN1_SCE_IRQHandler,             // CAN1 SCE
    (uint32_t)&EXTI9_5_IRQHandler,              // EXTI lines 9-5
    (uint32_t)&TIM1_BRK_TIM9_IRQHandler,        // TIM1 break and TIM9
    (uint32_t)&TIM1_UP_TIM10_IRQHandler,        // TIM1 update and TIM10
    (uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,   // TIM1 trigger and TIM11
    (uint32_t)&TIM1_CC_IRQHandler,              // TIM1 capture compare
    (uint32_t)&TIM2_IRQHandler,                 // TIM2
    (uint32_t)&TIM3_IRQHandler,                 // TIM3
    (uint32_t)&TIM4_IRQHandler,                 // TIM4
    (uint32_t)&I2C1_EV_IRQHandler,              // I2C1 event
    (uint32_t)&I2C1_ER_IRQHandler,              // I2C1 error
    (uint32_t)&I2C2_EV_IRQHandler,              // I2C2 event
    (uint32_t)&I2C2_ER_IRQHandler,              // I2C2 error
    (uint32_t)&SPI1_IRQHandler,                 // SPI1
    (uint32_t)&SPI2_IRQHandler,                 // SPI2
    (uint32_t)&USART1_IRQHandler,               // USART1
    (uint32_t)&USART2_IRQHandler,               // USART2
    (uint32_t)&USART3_IRQHandler,               // USART3
    (uint32_t)&EXTI15_10_IRQHandler,            // EXTI lines 15-10
    (uint32_t)&RTC_Alarm_IRQHandler,            // RTC alarm
    (uint32_t)&OTG_FS_WKUP_IRQHandler,          // USB OTG FS wakeup
    (uint32_t)&TIM8_BRK_TIM12_IRQHandler,       // TIM8 break and TIM12
    (uint32_t)&TIM8_UP_TIM13_IRQHandler,        // TIM8 update and TIM13
    (uint32_t)&TIM8_TRG_COM_TIM14_IRQHandler,   // TIM8 trigger and TIM14
    (uint32_t)&TIM8_CC_IRQHandler,              // TIM8 capture compare
    (uint32_t)&DMA1_Stream7_IRQHandler,         // DMA1 stream 7
    (uint32_t)&FMC_IRQHandler,                  // FMC
    (uint32_t)&SDIO_IRQHandler,                 // SDIO
    (uint32_t)&TIM5_IRQHandler,                 // TIM5
    (uint32_t)&SPI3_IRQHandler,                 // SPI3
    (uint32_t)&UART4_IRQHandler,                // UART4
    (uint32_t)&UART5_IRQHandler,                // UART5
    (uint32_t)&TIM6_DAC_IRQHandler,             // TIM6 and DAC
    (uint32_t)&TIM7_IRQHandler,                 // TIM7
    (uint32_t)&DMA2_Stream0_IRQHandler,         // DMA2 stream 0
    (uint32_t)&DMA2_Stream1_IRQHandler,         // DMA2 stream 1
    (uint32_t)&DMA2_Stream2_IRQHandler,         // DMA2 stream 2
    (uint32_t)&DMA2_Stream3_IRQHandler,         // DMA2 stream 3
    (uint32_t)&DMA2_Stream4_IRQHandler,         // DMA2 stream 4
    (uint32_t)&ETH_IRQHandler,                  // Ethernet
    (uint32_t)&ETH_WKUP_IRQHandler,             // Ethernet wakeup
    (uint32_t)&CAN2_TX_IRQHandler,              // CAN2 TX
    (uint32_t)&CAN2_RX0_IRQHandler,             // CAN2 RX0
    (uint32_t)&CAN2_RX1_IRQHandler,             // CAN2 RX1
    (uint32_t)&CAN2_SCE_IRQHandler,             // CAN2 SCE
    (uint32_t)&OTG_FS_IRQHandler,               // USB OTG FS
    (uint32_t)&DMA2_Stream5_IRQHandler,         // DMA2 stream 5
    (uint32_t)&DMA2_Stream6_IRQHandler,         // DMA2 stream 6
    (uint32_t)&DMA2_Stream7_IRQHandler,         // DMA2 stream 7
    (uint32_t)&USART6_IRQHandler,               // USART6
    (uint32_t)&I2C3_EV_IRQHandler,              // I2C3 event
    (uint32_t)&I2C3_ER_IRQHandler,              // I2C3 error
    (uint32_t)&OTG_HS_EP1_OUT_IRQHandler,       // USB OTG HS EP1 OUT
    (uint32_t)&OTG_HS_EP1_IN_IRQHandler,        // USB OTG HS EP1 IN
    (uint32_t)&OTG_HS_WKUP_IRQHandler,          // USB OTG HS wakeup
    (uint32_t)&OTG_HS_IRQHandler,               // USB OTG HS
    (uint32_t)&DCMI_IRQHandler,                 // DCMI
    0,                                          // Reserved
    0,                                          // Reserved
    (uint32_t)&FPU_IRQHandler,                  // FPU
    0,                                          // Reserved
    0,                                          // Reserved
    (uint32_t)&SPI4_IRQHandler,                 // SPI4
    0,                                          // Reserved
    0,                                          // Reserved
    (uint32_t)&SAI1_IRQHandler,                 // SAI1
    0,                                          // Reserved
    0,                                          // Reserved
    0,                                          // Reserved
    (uint32_t)&SAI2_IRQHandler,                 // SAI2
    (uint32_t)&QUADSPI_IRQHandler,              // QuadSPI
    (uint32_t)&CEC_IRQHandler,                  // HDMI-CEC
    (uint32_t)&SPDIF_RX_IRQHandler,             // SPDIF-RX
    (uint32_t)&FMPI2C1_IRQHandler,              // FMPI2C1 event
    (uint32_t)&FMPI2C1_error_IRQHandler,        // FMPI2C1 error
};