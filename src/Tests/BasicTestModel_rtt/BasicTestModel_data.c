/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BasicTestModel_data.c
 *
 * Code generated for Simulink model 'BasicTestModel'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 11:24:56 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BasicTestModel.h"
#include "BasicTestModel_private.h"

/* Block parameters (auto storage) */
P_BasicTestModel_T BasicTestModel_P = {
  -1.0,                                /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S8>/S-Function'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S11>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  18.849555921538759,                  /* Expression: 2*pi*3
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */

  /*  Computed Parameter: ZeroPole_A
   * Referenced by: '<Root>/Zero-Pole'
   */
  { -200.0, 1.0 },
  1.0,                                 /* Computed Parameter: ZeroPole_B
                                        * Referenced by: '<Root>/Zero-Pole'
                                        */

  /*  Computed Parameter: ZeroPole_C
   * Referenced by: '<Root>/Zero-Pole'
   */
  { 4466.41824272, -3641.18472869508 },
  -21.67312,                           /* Computed Parameter: ZeroPole_D
                                        * Referenced by: '<Root>/Zero-Pole'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  -0.0,                                /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  -1808.0,                             /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  -63.29,                              /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */

  /*  Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { -3.5714285714285712, -0.0 },

  /*  Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { -1597.3979591836733, -4725.0 },
  -15.428571428571429,                 /* Computed Parameter: TransferFcn_D
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
  { 2.6999999999999997, -15.27 },
  -0.03,                               /* Computed Parameter: ZeroPole1_D
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */

  /*  Computed Parameter: ZeroPole2_A
   * Referenced by: '<Root>/Zero-Pole2'
   */
  { -1132.0, -567.84195864694607, 567.84195864694607, -1015.2,
    -561.33280597917349, -111.0, 1.0 },

  /*  Computed Parameter: ZeroPole2_B
   * Referenced by: '<Root>/Zero-Pole2'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: ZeroPole2_C
   * Referenced by: '<Root>/Zero-Pole2'
   */
  { 4448.0988, 2459.4796893977486, -8.3248500000000245, -11573.206470000001 },
  -4.3815,                             /* Computed Parameter: ZeroPole2_D
                                        * Referenced by: '<Root>/Zero-Pole2'
                                        */

  /*  Computed Parameter: ZeroPole4_A
   * Referenced by: '<Root>/Zero-Pole4'
   */
  { -100.0, 1.0 },
  1.0,                                 /* Computed Parameter: ZeroPole4_B
                                        * Referenced by: '<Root>/Zero-Pole4'
                                        */

  /*  Computed Parameter: ZeroPole4_C
   * Referenced by: '<Root>/Zero-Pole4'
   */
  { 1.9639219199999998, -1.659962768 },
  -0.016498,                           /* Computed Parameter: ZeroPole4_D
                                        * Referenced by: '<Root>/Zero-Pole4'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S10>/S-Function1'
                                        */
  0.005F,                              /* Expression: single(dt_mot)
                                        * Referenced by: '<S10>/S-Function1'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S7>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S9>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_m
                                        * Referenced by: '<S13>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_h
                                        * Referenced by: '<S16>/S-Function'
                                        */
  1963413621,                          /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S8>/S-Function'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S10>/S-Function1'
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
