/* User LEDs on PG13 and PG14 */

#include <stdint.h>
#include "../include/cortexm4.h"
#include "../include/STM32F429.h"
void delay(uint32_t dly)
{
    while(dly--);
}
int main()
{

    RCC->AHB1ENR |= (1 << 6); // turn on the clock for GPIOG
    GPIOG->MODER |= (1 << 26); // Make bit 13 an output
    GPIOG->MODER &= ~(1 << 27);
    GPIOG->MODER |= (1 << 28); // Make bit 14 an output
    GPIOG->MODER &= ~(1 << 29);
    while(1)
    {
        GPIOG->ODR |= (1 << 13); // bit high
        GPIOG->ODR &= ~(1 << 14); // bit low
        delay(1000000);
        GPIOG->ODR &= ~(1 << 13); // bit low
        GPIOG->ODR |= (1 << 14); // bit high
        delay(1000000);
    }
}
    
