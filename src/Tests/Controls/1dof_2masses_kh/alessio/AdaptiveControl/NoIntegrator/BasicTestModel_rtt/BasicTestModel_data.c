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
 * C/C++ source code generated on : Fri May 06 10:52:10 2016
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
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S4>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S5>/Digital Output'
                                        */

  /*  Computed Parameter: ZeroPole2_A
   * Referenced by: '<S1>/Zero-Pole2'
   */
  { -1132.0, -567.84195864694607, 567.84195864694607, -1015.2,
    -561.33280597917349, -111.0, 1.0 },

  /*  Computed Parameter: ZeroPole2_B
   * Referenced by: '<S1>/Zero-Pole2'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: ZeroPole2_C
   * Referenced by: '<S1>/Zero-Pole2'
   */
  { 4448.0988, 2459.4796893977486, -8.3248500000000245, -11573.206470000001 },
  -4.3815,                             /* Computed Parameter: ZeroPole2_D
                                        * Referenced by: '<S1>/Zero-Pole2'
                                        */

  /*  Computed Parameter: ZeroPole4_A
   * Referenced by: '<S1>/Zero-Pole4'
   */
  { -100.0, 1.0 },
  1.0,                                 /* Computed Parameter: ZeroPole4_B
                                        * Referenced by: '<S1>/Zero-Pole4'
                                        */

  /*  Computed Parameter: ZeroPole4_C
   * Referenced by: '<S1>/Zero-Pole4'
   */
  { 1.9639219199999998, -1.659962768 },
  -0.016498,                           /* Computed Parameter: ZeroPole4_D
                                        * Referenced by: '<S1>/Zero-Pole4'
                                        */
  -0.0,                                /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  -1808.0,                             /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  -63.29,                              /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */

  /*  Computed Parameter: TransferFcn_A
   * Referenced by: '<S1>/Transfer Fcn'
   */
  { -3.5714285714285712, -0.0 },

  /*  Computed Parameter: TransferFcn_C
   * Referenced by: '<S1>/Transfer Fcn'
   */
  { -1597.3979591836733, -4725.0 },
  -15.428571428571429,                 /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */

  /*  Computed Parameter: ZeroPole1_A
   * Referenced by: '<S1>/Zero-Pole1'
   */
  { -100.0, 1.0 },
  1.0,                                 /* Computed Parameter: ZeroPole1_B
                                        * Referenced by: '<S1>/Zero-Pole1'
                                        */

  /*  Computed Parameter: ZeroPole1_C
   * Referenced by: '<S1>/Zero-Pole1'
   */
  { 2.6999999999999997, -15.27 },
  -0.03,                               /* Computed Parameter: ZeroPole1_D
                                        * Referenced by: '<S1>/Zero-Pole1'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S3>/S-Function'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S3>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
