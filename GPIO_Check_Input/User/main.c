#include "stm32f10x.h"
#include "./LED/bsp_led.h"
#include "./KEY/bsp_key.h"

int main(void)
{
    LED_GPIO_Config();
    Key_GPIO_Config();
    
    while(1){
        if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON ){
            LED1_TOGGLE;
        }
        if(Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON ){
            LED2_TOGGLE;
        }
    }    
}

