/* TimerTick scheduler
 * 
 * Copyright 2014 The MathWorks, Inc.
 */
#include "arduinodue_wrapper.h"
#include "baseRateTimer.h"
#include "Arduino.h"
#include "Reset.h"

static void Scheduler_Isr(void)
{
    DISABLE_SCHEDULER_INT();

    /* DSB (Data Synchronization Barrier) operation will complete when all 
     * explicit memory accesses before this instruction have completed.
     * No instructions after the DSB will be executed until the DSB
     * instruction has completed, that is, when all of the pending accesses
     * have completed. */
    __DSB();

    /* ISB (Instruction Synchronization Barrier)flushes the pipeline in
     * the processor, so that all instructions following the ISB are
     * fetched from cache or memory, after the instruction has been
     * completed. It ensures that changes to the system, for example
     * the MPU, take immediate effect.*/
    __ISB();
    
	rt_OneStep();

    ENABLE_SCHEDULER_INT();
}

#if defined(_ARDUINO_DUE_TIMER_6_)
__attribute__ ((naked)) void TC6_Handler(void)
#elif defined(_ARDUINO_DUE_TIMER_7_)
__attribute__ ((naked)) void TC7_Handler(void)
#elif defined(_ARDUINO_DUE_TIMER_8_)
__attribute__ ((naked)) void TC8_Handler(void)
#endif
{
    /* Multi tasking, enable re-entrancy */
    
    /* Naked functions need the following prolog */
    ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR();
    
    /* Needs to be called to reenable the Timer interrupt */
    #if defined(_ARDUINO_DUE_TIMER_6_)
      TC_GetStatus(TC2, 0);
    #elif defined(_ARDUINO_DUE_TIMER_7_) 
      TC_GetStatus(TC2, 1);
    #elif defined(_ARDUINO_DUE_TIMER_8_) 
      TC_GetStatus(TC2, 2);
    #endif
    
    /* Context switch to rt_OneStep() */
    arm_cortex_m_call_thread_with_context_switch(Scheduler_Isr);
}
 
void Setup_TickTimer(Tc *tc, uint32_t channel, uint32_t id, IRQn_Type irqn, uint8_t clockid, uint32_t tickcounter)
{
    pmc_set_writeprotect(false);
    pmc_enable_periph_clk(id);
    
    TC_Configure(tc, channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | clockid);
    
    TC_SetRC(tc, channel, tickcounter);
    
    TC_Start(tc, channel);
    
    tc->TC_CHANNEL[channel].TC_IER=TC_IER_CPCS;
    tc->TC_CHANNEL[channel].TC_IDR=~TC_IER_CPCS;
    
    NVIC_SetPriority(irqn, (1<<__NVIC_PRIO_BITS) - 1);
    NVIC_EnableIRQ(irqn);
}
