#include "stm32f10x.h"
#include "./uart/bsp_usart.h"

int main(void)
{
    USART_Config();
    Usart_SendString(DEBUG_USARTx,"这是一个串口中断接收回显实验\n");
    
    while(1){
    }
}

