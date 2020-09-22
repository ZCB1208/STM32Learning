#include "stm32f10x.h"

int main(void)
{
    RCC_APB2ENR |= (1<<3);
    
    GPIOB_CRL &= ~(0x0F << (4*0));
    GPIOB_CRL |= (1 << (4*0));
    
    GPIOB_ODR |= (0<<0);
//    GPIOB_ODR &= ~(1<<0);
    
    while(1);

}

void SystemInit(void)
{
    
}
