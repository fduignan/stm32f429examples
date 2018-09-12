/* User LEDs on PG13 and PG14 */

#include <stdint.h>
#include "../include/cortexm4.h"
#include "../include/STM32F429.h"
void delay(uint32_t dly)
{
    while(dly--);
}
uint32_t Test=0;
void init_clocks()
{
    // push the clock speed up to 180MHz.  
    // According to the reference manual, only 5 wait states are required
    // if the operating voltage is between 2.7 and 3.6V (which it is on the Discovery board)
    // Will also enable the instruction and data caches as well as the prefetch system
    FLASH->ACR |= (1 << 10) + (1 << 9) + (1 << 8) + 5;
    /*
        The maximum frequency of the AHB domain is 180 MHz. The maximum allowed frequency of 
        the high-speed APB2 domain is 90 MHz. The maximum allowed frequency of the low-speed 
        APB1 domain is 45 MHz (ref: Reference manual RM0090
    */
    // Initialize the clock system to a higher speed.
	// The HSI clock is 16MHz
	// There is an 8MHz crystal on the Discovery board
	// Will use the HSI 16MHz clock for the moment.
	// Now need to calculate multiplier N, and divisors P,Q and R
	// The VCO output is PLL_INPUT_CLOCK * N and must be <= 432MHz
	// PLL_INPUT_CLOCK is derived from HSI and is divided by 2 at least (divisor M)
	// PLL output Q must be 48MHz
	// The P divisor can have values of 2,4,6 or 8.   == 180MHz
	// The Q divisor can have values between 2 and 15 == 48MHz
	// The R divisor can have values betweeen 2 and 7 <= 180MHz
	// Let N = 45.  VCO Output will then be 360MHz
	// Let P = 2.   Main clock (HCLK) will then be 180MHz
	// Let Q=8.  Q output will then be 48MHz
	// Let R=2.  R output will then be 180MHz 
	// PLL_SRC (Bit 22) = 0 (HSI Clock)
	RCC->CR &= ~BIT24; // Make sure PLL is off
	RCC->PLLCFGR = (8 << 24) + (45 << 6) + 2;
    RCC->CR |= BIT24; // Turn PLL on
	while( (RCC->CR & BIT25)== 0); // Wait for PLL to be ready
    // need to configure the divisors for APB1 and APB2
    // APB1 <= 45MHz.  168MHz / 4 = 42MHz
    // APB2 <= 90MHz.  168MHz / 2 = 84MHz
    RCC->CFGR = BIT15 + BIT12 + BIT10;
    RCC->CFGR |= BIT1; // Select PLL as system clock
    Test = RCC->CFGR;
}
void SysTick_Handler(void)
{
    static uint32_t TickCount=0;
    TickCount++;
    if (TickCount > 1000)
    {
        TickCount = 0;
        GPIOG->ODR ^= (1 << 13); // toggle bit
    }
}
void initSysTick()
{   
    SysTick->CTRL |= ( BIT2 | BIT1 | BIT0); // enable systick, source = cpu clock, enable interrupt
    SysTick->LOAD=180000; // SysTick clock is 180MHz so divide by 180000 to get a 1ms timebase
    SysTick->VAL = 1; // don't want long wait for counter to count down from initial high unknown value
}
void configurePins()
{
    RCC->AHB1ENR |= (1 << 6); // turn on the clock for GPIOG
    GPIOG->MODER |= (1 << 26); // Make bit 13 an output
    GPIOG->MODER &= ~(1 << 27);
    GPIOG->MODER |= (1 << 28); // Make bit 14 an output
    GPIOG->MODER &= ~(1 << 29);
}
int main()
{
    init_clocks();
    configurePins();
    initSysTick();
    enable_interrupts();
    while(1)
    {
       asm(" wfi ");
    }
}
    
