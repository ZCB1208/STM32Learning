#include "stm32f10x.h"

#include "./SysTick/bsp_SysTick.h"
#include "./LED/bsp_led.h"


int main(void)
{
    LED_GPIO_Config();
    SysTick_Init();
    
    while(1){
        LED1_ON;
        Delay_us(100000);
        LED1_OFF;
        
        LED2_ON;
        Delay_us(100000);
        LED2_OFF;
        
        LED3_ON;
        Delay_us(100000);
        LED3_OFF;
        
    }
}

