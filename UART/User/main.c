#include "stm32f10x.h"
#include "./uart/bsp_usart.h"

int main(void)
{
    USART_Config();
    Usart_SendString(DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\n");
    
    while(1){
    }
}

