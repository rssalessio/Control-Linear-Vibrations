/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pseudorandom_data.c
 *
 * Code generated for Simulink model 'pseudorandom'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 17:39:15 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pseudorandom.h"
#include "pseudorandom_private.h"

/* Block parameters (auto storage) */
P_pseudorandom_T pseudorandom_P = {
  -1.0,                                /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S2>/S-Function'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_j
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  61292.0,                             /* Expression: seed
                                        * Referenced by: '<S1>/White Noise'
                                        */
  4.47213595499958,                    /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S1>/Output'
                                        */
  1.5,                                 /* Expression: 1.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.5,                                /* Expression: -1.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S7>/S-Function'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  -1.0F,                               /* Expression: single(dt_mot)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S5>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_f
                                        * Referenced by: '<S3>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S2>/S-Function'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S7>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
