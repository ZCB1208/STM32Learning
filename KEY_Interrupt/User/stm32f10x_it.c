#include "./LED/bsp_led.h"
#include "./EXTI/bsp_exti.h"

void KEY1_IRQHandler(void)
{
    if(EXTI_GetFlagStatus(KEY1_INT_EXTI_LINE) != RESET){
        LED1_TOGGLE;
        EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);
    }
}

void KEY2_IRQHandler(void)
{
    if(EXTI_GetFlagStatus(KEY2_INT_EXTI_LINE) != RESET){
        LED2_TOGGLE;
        EXTI_ClearITPendingBit(KEY2_INT_EXTI_LINE);
    }
}

