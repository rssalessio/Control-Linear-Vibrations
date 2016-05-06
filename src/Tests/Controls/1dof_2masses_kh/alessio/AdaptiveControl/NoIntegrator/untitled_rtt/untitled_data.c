/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:35:37 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block parameters (auto storage) */
P_untitled_T untitled_P = {
  3.0,                                 /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  -3.0,                                /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S6>/Delay Input1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_i
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  0.0017857142857142857,               /* Expression: 1/560
                                        * Referenced by: '<S7>/encoder-to-cm'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S9>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S9>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  2000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S4>/S-Function'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S4>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
