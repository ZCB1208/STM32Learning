// R-��ɫ
#define LED1_GPIO_PORT          GPIOB
#define LED1_GPIO_CLK           RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN           GPIO_Pin_5

//G-��ɫ
#define LED2_GPIO_PORT          GPIOB
#define LED2_GPIO_CLK           RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN           GPIO_Pin_0

//B-��ɫ
#define LED3_GPIO_PORT          GPIOB
#define LED3_GPIO_CLK           RCC_APB2Periph_GPIOB
#define LED3_GPIO_PIN           GPIO_Pin_1


/*ֱ�Ӳ����Ĵ����ķ�������IO*/

#define digitalHi(p,i)          {p->BSRR=i;}    //����ߵ�ƽ
#define digitalLo(p,i)          {p->BRR=i;}     //����͵�ƽ
#define digitalToggle(p,i)      {p->ODR ^=i;}    //�����ת״̬

#define LED1_TOGGLE             digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON                 digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF                digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE             digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON                 digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF                digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_TOGGLE             digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON                 digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF                digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

#define LED_RED                 \
                                LED1_ON;\
                                LED2_OFF;\
                                LED3_OFF
#define LED_GREEN               \
                                LED1_OFF;\
                                LED2_ON;\
                                LED3_OFF;
#define LED_BLUE                \
                                LED1_OFF;\
                                LED2_OFF;\
                                LED3_ON;     
          

void LED_GPIO_Config(void);

