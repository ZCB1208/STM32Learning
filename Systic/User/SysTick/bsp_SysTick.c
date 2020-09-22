#include "bsp_SysTick.h"
#include "core_cm3.h"
#include "misc.h"

static __IO u32 TimingDelay;

void SysTick_Init(void)
{
    /* SystemFrequency / 1000       1ms  �ж�һ��
     * SystemFrequency / 100000     10��s �ж�һ��
     * SystemFrequency / 1000000    1��   �ж�һ��     
     */
    if(SysTick_Config(SystemCoreClock / 100000)){
        while(1);
    }
}

/**
   *  @brief
   *  @param
   *       @arg 
   *  @retval
   */
void Delay_us(__IO u32 nTime)
{
    TimingDelay = nTime;
    
    while(TimingDelay != 0);
}




/**
   *  @brief
   *  @param
   *      @arg 
   *  @retval
   */

void TimingDelay_Decrement(void)
{
    if(TimingDelay != 0x00){
        TimingDelay--;
    }
}

//�жϸ�λ����
void SysTick_Handler(void)
{
    TimingDelay_Decrement();
}

