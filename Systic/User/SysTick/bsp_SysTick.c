#include "bsp_SysTick.h"
#include "core_cm3.h"
#include "misc.h"

static __IO u32 TimingDelay;

void SysTick_Init(void)
{
    /* SystemFrequency / 1000       1ms  中断一次
     * SystemFrequency / 100000     10μs 中端一次
     * SystemFrequency / 1000000    1μ   中断一次     
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

//中断复位函数
void SysTick_Handler(void)
{
    TimingDelay_Decrement();
}

