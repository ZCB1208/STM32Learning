#ifndef __STM32F10X_H
#define __STM32F10X_H

/*片上外设基地址*/
#if 0
#define PERIPH_BASE         ((unsigned int)0x40000000)
    
#define APB2PERIPH_BASE     (PERIPH_BASE +0x10000)

#define AHBPERIPH_BASE      (PERIPH_BASE +0x20000)

#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)

//#define GPIOB_CRL           *(unsigned int *)(GPIOB_BASE+0x00) 
//#define GPIOB_CRH           *(unsigned int *)(GPIOB_BASE+0x04) 
//#define GPIOB_IDR           *(unsigned int *)(GPIOB_BASE+0x08) 
//#define GPIOB_ODR           *(unsigned int *)(GPIOB_BASE+0x0C) 
//#define GPIOB_BSRR          *(unsigned int *)(GPIOB_BASE+0x10) 
//#define GPIOB_BRR           *(unsigned int *)(GPIOB_BASE+0x14) 
//#define GPIOB_LCKR          *(unsigned int *)(GPIOB_BASE+0x18)


#define RCC_BASE            (AHBPERIPH_BASE + 0x1000)
#define RCC_APB2ENR         *(unsigned int*)(RCC_BASE + 0x18)
        
#elif 1
#define __IO  volatile
typedef unsigned int  uint32_t;
typedef unsigned int  uint16_t;

#define PERIPH_BASE         ((unsigned int)0x40000000)
#define APB2PERIPH_BASE     (PERIPH_BASE +0x10000)
#define AHBPERIPH_BASE      (PERIPH_BASE +0x20000)

#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)

#define RCC_BASE            (AHBPERIPH_BASE + 0x1000)
#define RCC_APB2ENR         *(unsigned int*)(RCC_BASE + 0x18)

typedef struct 
{
    __IO uint32_t CRL;
    __IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
    uint16_t GPIO_Pin;
    uint16_t GPIO_Speed;
    uint16_t GPIO_Mode;
} GPIO_InitTypeDef;
typedef enum 
{
    GPIOB_Speed_10MHz = 1,
    GPIOB_Speed_2MHz,
    GPIOB_Speed_50MHz
}GPIOSpeed_TypeDef;

typedef enum
{
    GPIO_Mode_AIN = 0x00,
    GPIO_Mode_IN_FLOATING = 0x04,
    GPIO_Mode_IPD = 0x28,
    GPIO_Mode_IPU = 0x48,
    
    GPIO_Mode_Out_OD = 0x14,
    GPIO_Mode_Out_PP = 0x10,
    GPIO_Mode_AF_OD = 0x1C,
    GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;

#endif

#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)

#endif

