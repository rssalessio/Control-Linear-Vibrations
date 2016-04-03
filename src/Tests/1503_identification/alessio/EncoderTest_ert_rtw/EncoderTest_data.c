/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EncoderTest_data.c
 *
 * Code generated for Simulink model 'EncoderTest'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Tue Mar 15 13:25:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EncoderTest.h"
#include "EncoderTest_private.h"

/* Block parameters (auto storage) */
P_EncoderTest_T EncoderTest_P = {
  -1.0,                                /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S2>/S-Function'
                                        */
  -1.0,                                /* Mask Parameter: Encoder1_dt_enc
                                        * Referenced by: '<S3>/S-Function'
                                        */
  -1.0,                                /* Mask Parameter: Encoder2_dt_enc
                                        * Referenced by: '<S4>/S-Function'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S2>/S-Function'
                                        */
  4U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S3>/S-Function'
                                        */
  3U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S4>/S-Function'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
