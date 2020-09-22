#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

int main(void)
{
#if 0
    RCC_APB2ENR |= (1<<3);


    GPIOB_CRL &= ~(0x0F << (4*0));
    GPIOB_CRL |= (1 << (4*0));
    
    GPIOB_ODR |= (0<<0);
    while(1);
    
#elif 0
    RCC_APB2ENR |= (1<<3);
    
    GPIOB->CRL &= ~(0x0F << (4*0));
    GPIOB->CRL |= (1 << (4*0));
    
    GPIOB->ODR |= (1<<0);
    while(1);
    
 #elif 0
    
    RCC_APB2ENR |= (1<<3);
    
    GPIOB->CRL &= ~(0x0F << (4*0));
    GPIOB->CRL |= (1 << (4*0));
    
    GPIO_SetBits(GPIOB,GPIO_Pin_0);
//    GPIO_ResetBits(GPIOB,GPIO_Pin_0);
#elif 1
    RCC_APB2ENR |= (1<<3);
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIOB_Speed_50MHz;
   
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    GPIO_ResetBits(GPIOB,GPIO_Pin_0);
    GPIO_SetBits(GPIOB,GPIO_Pin_0);
    
#endif
    
    

}

void SystemInit(void)
{
    
}
