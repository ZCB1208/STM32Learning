#include "./uart/bsp_usart.h"

static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    NVIC_InitStructure.NVIC_IRQChannel  = DEBUG_USART_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//��ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority  = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  
    NVIC_Init(&NVIC_InitStructure);
}

void USART_Config(void)
{
    GPIO_InitTypeDef    GPIO_InitStructure;
    USART_InitTypeDef   USART_InitStructure;
    
    //�򿪴���GPIO��ʱ��
    DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
    //�򿪴��������ʱ��
    DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
    
    //��USART Rx��GPIO����Ϊ���츴��ģʽ
    GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);
    
    //��USART Tx��GPIO ����Ϊ�������ģʽ
    GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);
    
    //���ô��ڵĹ�������
    USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;  //������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //���ݳ���
    USART_InitStructure.USART_StopBits = USART_StopBits_1;      //ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;         //����λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//����Ӳ��������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                //���ù���ģʽ���շ�һ��
    USART_Init(DEBUG_USARTx,&USART_InitStructure);                                 
    
    NVIC_Configuration();
    USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);//ʹ�ܴ��ڽ����ж�
    
    USART_Cmd(DEBUG_USARTx,ENABLE);//ʹ�ܴ���
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



