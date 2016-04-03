/* Arduino Due Multi tasking  - Context Switch Handlers. 
 * 
 * Copyright 2014 The MathWorks, Inc.
 */

#include "arduinodue_wrapper.h"
#include "Arduino.h"

__attribute__ ((naked)) void arm_cortex_m_call_thread_with_context_switch(void (*isr_routine_ptr)(void))
{

    __asm volatile
    (
    "   push {r0, r1}                               \n"  /* r0 represents the isr_routing_ptr. While switching between */
                                                         /* Thread mode to Handler mode, the register r0 will get filled with */
                                                         /* 0x0000. So, r0 is pushed to stack before doing a context switch. */
														 /* R1 is pushed as dummy to maintain double word stack alignment. */
    "   SUB SP, SP , #0x20                          \n"  /* Reserve 8 words for dummy stack frame for return */
    "   LDR R0,=Call_isr_routine_in_thread_mode     \n"  /* Program counter */
    "   STR R0,[SP, #24]                            \n" \
    "   LDR R0,=0x01000000                          \n"  /* xPSR */
    "   STR R0,[SP, #28]                            \n" \
    "   LDR R0,=0xFFFFFFF9                          \n" /* Return to Thread with Main Stack, 8 word stack frame */
    "   MOV LR, R0                                  \n" \
    "   BX LR                                       \n" /* Change to Thread mode with Main stack */
    "Call_isr_routine_in_thread_mode:               \n" /* Thread mode start point */
    "   pop {r0, r1}                                \n" /* pop isr_routine_ptr */
    "   BLX R0                                      \n" /* call isr_routine_ptr */
    "   MOV R0, %0                               	\n" /* Priority level of interrupts to be disabled */
    "   MSR BASEPRI, R0                             \n" /* Disable interrupts with priority (((0x1 to 0xFF) << (8 - __NVIC_PRIO_BITS)) & 0xff) */
    "   ISB                                         \n" \
    "   SVC 0                                       \n" /* Use SVC to return to original Thread */
    "   B .                                         \n" /* Should not return here */
    ::"i" ((0x1 << (8 - __NVIC_PRIO_BITS)) & 0xff));
}

__attribute__ ((naked)) void svcHook(void)
{

    __asm volatile 
    (
    "   MOVS R0, #0x0                               \n" /* Priority level of interrupts to be enabled */
    "   MSR BASEPRI, R0                             \n" /* Enable interrupts with priority (((0x1 to 0xFF) << (8 - __NVIC_PRIO_BITS)) & 0xff) */
    /* Extract SVC number */
    "   TST LR, #0x4                                \n" /* Test EXC_RETURN bit 2 */
    "   ITE EQ                                      \n" /* if zero then */
    "   MRSEQ R0, MSP                               \n" /* Get correct stack pointer to R0 */
    "   MRSNE R0, PSP                               \n" \
    "   LDR R1, [R0, #24]                           \n" /* Get stacked PC */
    "   LDRB.W R0, [R1, #-2]                        \n" /* Get SVC parameter at stacked PC minus 2 */
    "   CBZ R0, svc_service_0                       \n" /* if zero, branch to SVC service 0 */
    "   B Unknown_SVC_Request                       \n" \
    "svc_service_0:                                 \n" \
    /* Reentrant code finished, we can discard the current stack frame *
     * and restore the original stack frame. However, the current      *
     * stack frame could be 8 words or 26 words(FPU).                       */
    /*"   TST LR, #0x10                               \n"*/ /* Test EXC_RETURN bit 4 */
    /*"   ITE EQ                                      \n"*/ \
    /*"   ADDEQ SP, SP, #104                          \n"*/ /* LR Bit 4 was 0, 26 words in stack frame */
    "   ADD SP, SP, #32                           \n" /* LR Bit 4 was 1, 8 words in stack frame */
    "   POP {R0, R1}                                \n" \
    "   MSR PSR, R0                                 \n" \
    "   BX R1                                       \n" \
    "Unknown_SVC_Request:                           \n" \
    "   B .                                         \n"
    );    
}