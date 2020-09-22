#include "./uart/bsp_usart.h"

static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    NVIC_InitStructure.NVIC_IRQChannel  = DEBUG_USART_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority  = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  
    NVIC_Init(&NVIC_InitStructure);
}

void USART_Config(void)
{
    GPIO_InitTypeDef    GPIO_InitStructure;
    USART_InitTypeDef   USART_InitStructure;
    
    //打开串口GPIO的时钟
    DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
    //打开串口外设的时钟
    DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
    
    //将USART Rx的GPIO配置为推挽复用模式
    GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);
    
    //将USART Tx的GPIO 配置为推挽服用模式
    GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);
    
    //配置串口的工作参数
    USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;  //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据长度
    USART_InitStructure.USART_StopBits = USART_StopBits_1;      //停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;         //检验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//配置硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                //配置工作模式，收发一起
    USART_Init(DEBUG_USARTx,&USART_InitStructure);                                 
    
    NVIC_Configuration();
    USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);//使能串口接收中断
    
    USART_Cmd(DEBUG_USARTx,ENABLE);//使能串口
}

void Usart_SendByte(USART_TypeDef * pUSARTx, uint8_t ch)
{
    USART_SendData(pUSARTx,ch);
    
    while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET);
}

void Usart_SendString(USART_TypeDef * pUSARTx,char *str)
{
    unsigned int k = 0;
    do{
        Usart_SendByte(pUSARTx,*(str + k));
        k++;
    }while(*(str+k) != '\0');
    
    while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC) == RESET){
    }
}



