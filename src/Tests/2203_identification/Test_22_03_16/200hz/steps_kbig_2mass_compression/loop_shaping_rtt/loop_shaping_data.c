/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: loop_shaping_data.c
 *
 * Code generated for Simulink model 'loop_shaping'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Apr 08 10:45:53 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "loop_shaping.h"
#include "loop_shaping_private.h"

/* Block parameters (auto storage) */
P_loop_shaping_T loop_shaping_P = {
  -1.0,                                /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S3>/S-Function'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  300.0,                               /* Expression: 300
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  2000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  -20.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  20.0,                                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */

  /*  Computed Parameter: ZeroPole1_A
   * Referenced by: '<Root>/Zero-Pole1'
   */
  { -100.0, 1.0 },
  1.0,                                 /* Computed Parameter: ZeroPole1_B
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */

  /*  Computed Parameter: ZeroPole1_C
   * Referenced by: '<Root>/Zero-Pole1'
   */
  { 9.6000000000000014, -48.800000000000004 },
  -0.1,                                /* Computed Parameter: ZeroPole1_D
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  -1.0F,                               /* Expression: single(dt_mot)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_p
                                        * Referenced by: '<S2>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S3>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S4>/S-Function1'
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
