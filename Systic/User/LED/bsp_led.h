// R-红色
#define LED1_GPIO_PORT          GPIOB
#define LED1_GPIO_CLK           RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN           GPIO_Pin_5

//G-绿色
#define LED2_GPIO_PORT          GPIOB
#define LED2_GPIO_CLK           RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN           GPIO_Pin_0

//B-蓝色
#define LED3_GPIO_PORT          GPIOB
#define LED3_GPIO_CLK           RCC_APB2Periph_GPIOB
#define LED3_GPIO_PIN           GPIO_Pin_1


/*直接操作寄存器的方法控制IO*/

#define digitalHi(p,i)          {p->BSRR=i;}    //输出高电平
#define digitalLo(p,i)          {p->BRR=i;}     //输出低电平
#define digitalToggle(p,i)      {p->ODR ^=i;}    //输出反转状态

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

