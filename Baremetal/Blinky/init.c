void init(void);
void Default_Handler(void);
int main(void);

// The following are 'declared' in the linker script
extern unsigned char  INIT_DATA_VALUES;
extern unsigned char  INIT_DATA_START;
extern unsigned char  INIT_DATA_END;
extern unsigned char  BSS_START;
extern unsigned char  BSS_END;
// the section "vectors" is placed at the beginning of flash 
// by the linker script
const void * Vectors[] __attribute__((section(".vectors"))) ={
    (void *)0x20020000, 	/* Top of stack (128k) */ 
    init,   		     /* Reset Handler */
    Default_Handler,	/* NMI */
    Default_Handler,	/* Hard Fault */
    Default_Handler,	/* MemManage */
    Default_Handler,	/* Bus Fault  */
    Default_Handler,	/* Usage Fault */
    Default_Handler,	/* Reserved */ 
    Default_Handler,	/* Reserved */
    Default_Handler,	/* Reserved */
    Default_Handler,	/* Reserved */
    Default_Handler,	/* SVCall */
    Default_Handler,	/* Reserved */
    Default_Handler,	/* Debug monitor */
    Default_Handler,	/* PendSV */
    Default_Handler,        /* SysTick */	
    /* External interrupt handlers follow */
    Default_Handler, 	/* 0: WWDG */
    Default_Handler, 	/* 1: PVD */
    Default_Handler, 	/* 2: Tamper */
    Default_Handler, 	/* 3: RTC */
    Default_Handler, 	/* 4: Flash */
    Default_Handler, 	/* 5: RCC */
    Default_Handler, 	/* 6: EXTI Line 0 */
    Default_Handler, 	/* 7: EXTI Line 1 */
    Default_Handler, 	/* 8: EXTI Line 2 */
    Default_Handler, 	/* 9: EXTI Line 3 */
    Default_Handler, 	/* 10: EXTI Line 4 */
    Default_Handler, 	/* 11: DMA1 Stream 0 */
    Default_Handler, 	/* 12: DMA1 Stream 1 */
    Default_Handler, 	/* 13: DMA1 Stream 2 */
    Default_Handler, 	/* 14: DMA1 Stream 3 */
    Default_Handler, 	/* 15: DMA1 Stream 4 */
    Default_Handler, 	/* 16: DMA1 Stream 5 */
    Default_Handler, 	/* 17: DMA1 Stream 6 */
    Default_Handler, 	/* 18: ADC  */
    Default_Handler, 	/* 19: CAN1 TX interrupt */
    Default_Handler, 	/* 20: CAN1 RX0 interrupt */
    Default_Handler, 	/* 21: CAN1 RX1 interrupt */
    Default_Handler, 	/* 22: CAN1 SCE interrupt */
    Default_Handler, 	/* 23: EXTI Line[9:5] interrupts */
    Default_Handler, 	/* 24: TIM1 Break interrupt and TIM9 global*/
    Default_Handler, 	/* 25: TIM1 Update interrupt and and TIM10 global*/
    Default_Handler, 	/* 26: TIM1 Trigger and Commutation interrupts */
    Default_Handler, 	/* 27: TIM1 Capture Compare interrupt */
    Default_Handler, 	/* 28: TIM2 global interrupt */
    Default_Handler, 	/* 29: TIM3 global interrupt */
    Default_Handler, 	/* 30: TIM4 global interrupt */
    Default_Handler, 	/* 31: I2C1 event interrupt */
    Default_Handler, 	/* 32: I2C1 error interrupt */
    Default_Handler, 	/* 33: I2C2 event interrupt */
    Default_Handler, 	/* 34: I2C2 error interrupt */
    Default_Handler, 	/* 35: SPI1 global interrupt */
    Default_Handler, 	/* 36: SPI2 global interrupt */
    Default_Handler, 	/* 37: USART1 global interrupt */
    Default_Handler, 	/* 38: USART2 global interrupt */
    Default_Handler, 	/* 39: USART3 global interrupt */
    Default_Handler, 	/* 40: EXTI Line[15:10] interrupts */
    Default_Handler, 	/* 41: RTC Alarms through EXTI line interrupt */
    Default_Handler, 	/* 42: OTG_FS Interrupt */
    Default_Handler, 	/* 43: TIM8 Break interrupt */
    Default_Handler, 	/* 44: TIM8 Update interrupt */
    Default_Handler, 	/* 45: TIM8 Trigger and Commutation interrupts and TIM14 global */
    Default_Handler, 	/* 46: TIM8 Capture Compare interrupt */
    Default_Handler, 	/* 47: DMA1 Stream 7 */
    Default_Handler, 	/* 48: FSMC global interrupt */
    Default_Handler, 	/* 49: SDIO global interrupt */
    Default_Handler, 	/* 50: TIM5 global interrupt */
    Default_Handler, 	/* 51: SPI3 global interrupt */
    Default_Handler, 	/* 52: UART4 global interrupt */
    Default_Handler, 	/* 53: UART5 global interrupt */
    Default_Handler, 	/* 54: TIM6 global interrupt and DAC1,2 underrun error interrupt */
    Default_Handler, 	/* 55: TIM7 global interrupt */
    Default_Handler, 	/* 56: DMA2 stream 0 global interrupt */
    Default_Handler, 	/* 57: DMA2 stream 1 global interrupt */
    Default_Handler, 	/* 58: DMA2 stream 2 global interrupt */
    Default_Handler, 	/* 59: DMA2 stream 3 global interrupt */
    Default_Handler, 	/* 60: DMA2 stream 4 global interrupt */
    Default_Handler, 	/* 61: Ethernet global interrupt */
    Default_Handler, 	/* 62: Ethernet wakeup through EXTI line interrupt */
    Default_Handler, 	/* 63: CAN2 TX interrupt*/
    Default_Handler, 	/* 64: CAN2 RX0 interrupt */
    Default_Handler, 	/* 65: CAN2 RX1 interrupt  */
    Default_Handler, 	/* 66: CAN2 SCE interrupt  */    
    Default_Handler, 	/* 67: OTG_FS global interrupt */
    Default_Handler, 	/* 68: DMA2 stream 5 global interrupt  */    
    Default_Handler, 	/* 69: DMA2 stream 6 global interrupt  */    
    Default_Handler, 	/* 70: DMA2 stream 7 global interrupt  */    
    Default_Handler, 	/* 71: USART6 global interrupt  */    
    Default_Handler, 	/* 72: I2C3 event interrupt  */    
    Default_Handler, 	/* 73: I2C3 error interrupt  */    
    Default_Handler, 	/* 74: USB On The Go HS End Point 1 Out global interrupt   */    
    Default_Handler, 	/* 75: USB On The Go HS End Point 1 In global interrupt */    
    Default_Handler, 	/* 76: USB On The Go HS Wakeup through EXTI interrupt  */    
    Default_Handler, 	/* 77: USB On The Go HS global interrupt  */    
    Default_Handler, 	/* 78: DCMI global interrupt  */    
    Default_Handler, 	/* 79: CRYP crypto global interrupt  */    
    Default_Handler, 	/* 80: Hash and Rng global interrupt  */    
    Default_Handler, 	/* 81: FPU global interrupt  */    
    
    
};
void init()
{
    // do global/static data initialization
    unsigned char *src;
    unsigned char *dest;
    unsigned len;
    src= &INIT_DATA_VALUES;
    dest= &INIT_DATA_START;
    len= &INIT_DATA_END-&INIT_DATA_START;
    while (len--)
        *dest++ = *src++;
    // zero out the uninitialized global/static variables
    dest = &BSS_START;
    len = &BSS_END - &BSS_START;
    while (len--)
        *dest++=0;
    main();
    while(1);
}

void Default_Handler()
{
    while(1);
}
