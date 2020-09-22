#include "stm32f10x_it.h"
#include "./uart/bsp_usart.h"

void DEBUG_USART_IRQHandler(void)
{
    uint8_t ucTemp;
    if(USART_GetITStatus(DEBUG_USARTx,USART_IT_RXNE) != RESET){
        ucTemp = USART_ReceiveData(DEBUG_USARTx);
        USART_SendData(DEBUG_USARTx,ucTemp);
    }
}

