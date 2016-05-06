/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: porcoilclero_data.c
 *
 * Code generated for Simulink model 'porcoilclero'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:44:14 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "porcoilclero.h"
#include "porcoilclero_private.h"

/* Block parameters (auto storage) */
P_porcoilclero_T porcoilclero_P = {
  /*  Variable: Aref
   * Referenced by: '<S13>/Gain'
   */
  { 0.0, -986.96044010893581, 1.0, -62.831853071795862 },

  /*  Variable: Bref
   * Referenced by: '<S13>/Gain1'
   */
  { 0.0, 986.96044010893581 },
  900.0,                               /* Variable: GammaR
                                        * Referenced by: '<S2>/Gain3'
                                        */

  /*  Variable: GammaX
   * Referenced by: '<S2>/Gain'
   */
  { 50.0, 0.0, 0.0, 50.0 },
  3.0,                                 /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  -3.0,                                /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.005,                               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S19>/S-Function'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_i
                                        * Referenced by: '<S15>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  0.0017857142857142857,               /* Expression: 1/560
                                        * Referenced by: '<S8>/encoder-to-cm'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator4'
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
                                        * Referenced by: '<S9>/Saturation'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S5>/S-Function'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */

  /*  Expression: P*B
   * Referenced by: '<S2>/Constant'
   */
  { -0.2876003772257848, -4.5221934634774232 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory3'
                                        */
  0.0017857142857142857,               /* Expression: 1/560
                                        * Referenced by: '<S4>/Gain'
                                        */

  /*  Computed Parameter: ZeroPole_A
   * Referenced by: '<S4>/Zero-Pole'
   */
  { -250.0, -122.4744871391589, 122.47448713915891 },
  1.0,                                 /* Computed Parameter: ZeroPole_B
                                        * Referenced by: '<S4>/Zero-Pole'
                                        */
  15000.0,                             /* Computed Parameter: ZeroPole_C
                                        * Referenced by: '<S4>/Zero-Pole'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  0.005F,                              /* Expression: single(dt_mot)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S20>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_o
                                        * Referenced by: '<S18>/S-Function'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  6U,                                  /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S5>/S-Function'
                                        */
  1U                                   /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S19>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */