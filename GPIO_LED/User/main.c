#include "stm32f10x.h"
#include "./led/bsp_led.h"

#define SOFT_DELAY Delay(0x0FFFFF)

void Delay(__IO u32 nCount);


int main(void)
{
    LED_GPIO_Config();
    
    while(1){
        LED1_ON;
        SOFT_DELAY;
        LED1_OFF;
        
        LED2_ON;
        SOFT_DELAY;
        LED2_OFF;
        
        LED3_ON;
        SOFT_DELAY;
        LED3_OFF;
        
    }
}

void Delay(__IO u32 nCount)
{
    for(;nCount != 0;nCount--);
}