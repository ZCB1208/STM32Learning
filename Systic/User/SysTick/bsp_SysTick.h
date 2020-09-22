#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__
#include "stm32f10x.h"

void SysTick_Init(void);
void Delay_us(__IO u32 nTime);


#endif

