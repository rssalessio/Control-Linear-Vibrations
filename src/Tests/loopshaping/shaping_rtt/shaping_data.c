/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: shaping_data.c
 *
 * Code generated for Simulink model 'shaping'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Apr 19 17:28:15 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "shaping.h"
#include "shaping_private.h"

/* Block parameters (auto storage) */
P_shaping_T shaping_P = {
  5.0,                                 /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  -5.0,                                /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S9>/Constant'
                                        */
  10.0,                                /* Mask Parameter: UpperThreshold_const_e
                                        * Referenced by: '<S12>/Constant'
                                        */
  -10.0,                               /* Mask Parameter: LowerThreshold_const_f
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.005,                               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S18>/S-Function'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_l
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  500.0,                               /* Computed Parameter: PulseGenerator_Duty
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
  560.0,                               /* Expression: 560
                                        * Referenced by: '<S4>/cm-to-encoder'
                                        */

  /*  Computed Parameter: loopshaping_A
   * Referenced by: '<S2>/loopshaping'
   */
  { -100.0, 1.0 },
  1.0,                                 /* Computed Parameter: loopshaping_B
                                        * Referenced by: '<S2>/loopshaping'
                                        */

  /*  Computed Parameter: loopshaping_C
   * Referenced by: '<S2>/loopshaping'
   */
  { 1.86, -9.925 },
  -0.02,                               /* Computed Parameter: loopshaping_D
                                        * Referenced by: '<S2>/loopshaping'
                                        */
  323.0,                               /* Expression: 323
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S5>/S-Function'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  0.005F,                              /* Expression: single(dt_mot)
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S17>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_d
                                        * Referenced by: '<S19>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S18>/S-Function'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S5>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
