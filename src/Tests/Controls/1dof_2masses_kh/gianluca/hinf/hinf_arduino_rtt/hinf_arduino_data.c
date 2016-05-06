/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hinf_arduino_data.c
 *
 * Code generated for Simulink model 'hinf_arduino'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 12:09:03 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hinf_arduino.h"
#include "hinf_arduino_private.h"

/* Block parameters (auto storage) */
P_hinf_arduino_T hinf_arduino_P = {
  0.005,                               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S20>/S-Function'
                                        */

  { { 0UL, 0x300UL } },                /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S15>/Constant'
                                        */

  { { 0UL, 0xFFFFFD00UL } },           /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S14>/Constant'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S16>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_l
                                        * Referenced by: '<S17>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */

  /*  Computed Parameter: HINFINITY_A
   * Referenced by: '<S2>/H INFINITY'
   */
  { -0.27246818752443869, 0.073742005420695492, -0.83145126362794652,
    -0.073744323744129356, -0.26062585013882072, 38.4205477807178,
    -0.83144358794202344, -38.420547354604764, -42.134458844499555 },

  /*  Computed Parameter: HINFINITY_B
   * Referenced by: '<S2>/H INFINITY'
   */
  { 0.19240929866912657, 0.025556992083233015, 0.29813137395530942 },

  /*  Computed Parameter: HINFINITY_C
   * Referenced by: '<S2>/H INFINITY'
   */
  { -0.192409262177062, 0.025556992389839217, -0.29813137791865685 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/H INFINITY'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  560.0,                               /* Expression: 560
                                        * Referenced by: '<S5>/cm-to-encoder'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  0.005F,                              /* Expression: single(dt_mot)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_k
                                        * Referenced by: '<S8>/Memory'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S13>/S-Function'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm_Gain
                                        * Referenced by: '<Root>/encoder-to-cm'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm_Gain_g
                                        * Referenced by: '<S8>/encoder-to-cm'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S20>/S-Function'
                                        */
  6U,                                  /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  0                                    /* Computed Parameter: Memory_X0_g
                                        * Referenced by: '<S7>/Memory'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
