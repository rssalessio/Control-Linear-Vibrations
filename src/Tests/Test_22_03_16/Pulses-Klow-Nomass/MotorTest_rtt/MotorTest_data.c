/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorTest_data.c
 *
 * Code generated for Simulink model 'MotorTest'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 17:04:47 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorTest.h"
#include "MotorTest_private.h"

/* Block parameters (auto storage) */
P_MotorTest_T MotorTest_P = {
  -1.0,                                /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S6>/S-Function'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S11>/Digital Output'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  6.0,                                 /* Expression: 2*3
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  500.0,                               /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S9>/S-Function'
                                        */
  1.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  -1.0F,                               /* Expression: single(dt_mot)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  7U,                                  /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S5>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_l0
                                        * Referenced by: '<S4>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S9>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
