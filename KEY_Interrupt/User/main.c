#include "stm32f10x.h"
#include "./LED/bsp_led.h"
#include "./EXTI/bsp_exti.h"

int main(void)
{
    LED_GPIO_Config();
    EXTI_Key_Config();
    
    while(1){
    }
}

