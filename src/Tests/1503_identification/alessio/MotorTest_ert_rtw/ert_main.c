/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'MotorTest'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Tue Mar 15 13:21:20 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorTest.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  interrupts();
  MotorTest_step();

  /* Get model outputs here */
  noInterrupts();
  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.01;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(MotorTest_M, 0);
  MotorTest_initialize();
  configureArduinoARMTimer();
  runModel =
    rtmGetErrorStatus(MotorTest_M) == (NULL);
  interrupts();
  interrupts();
  while (runModel) {
    runModel =
      rtmGetErrorStatus(MotorTest_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  MotorTest_terminate();
  noInterrupts();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
