/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hinf_arduino_data.c
 *
 * Code generated for Simulink model 'hinf_arduino'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 09:25:11 2016
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
                                        * Referenced by: '<S22>/S-Function'
                                        */
  0.005,                               /* Mask Parameter: Encoder_dt_enc_d
                                        * Referenced by: '<S16>/S-Function'
                                        */

  { { 0UL, 0x300UL } },                /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S13>/Constant'
                                        */

  { { 0UL, 0xFFFFFD00UL } },           /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S17>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S18>/Digital Output'
                                        */

  /*  Computed Parameter: HINFINITY_A
   * Referenced by: '<S2>/H INFINITY'
   */
  { -0.27448820087588793, -0.0660909830003612, -1.7175566825690449,
    0.066089887246841408, -0.091994490949500157, -41.762931565708541,
    -1.7175637657903322, 41.762932294852007, -82.352181696936668 },

  /*  Computed Parameter: HINFINITY_B
   * Referenced by: '<S2>/H INFINITY'
   */
  { 0.11588816963078094, -0.013395531094548472, 0.37524454773358784 },

  /*  Computed Parameter: HINFINITY_C
   * Referenced by: '<S2>/H INFINITY'
   */
  { -0.11588819168021924, -0.013395528345057972, -0.37524454719654926 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/H INFINITY'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S11>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S11>/Saturation'
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
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  0.005,                               /* Expression: sample_time
                                        * Referenced by: '<S7>/S-Function'
                                        */
  560.0,                               /* Expression: 560
                                        * Referenced by: '<S6>/cm-to-encoder'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S24>/S-Function1'
                                        */
  0.005F,                              /* Expression: single(dt_mot)
                                        * Referenced by: '<S24>/S-Function1'
                                        */
  0,                                   /* Computed Parameter: Memory2_X0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S23>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_c
                                        * Referenced by: '<S21>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_k
                                        * Referenced by: '<S15>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_i
                                        * Referenced by: '<S14>/S-Function'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm_Gain
                                        * Referenced by: '<S9>/encoder-to-cm'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm_Gain_n
                                        * Referenced by: '<Root>/encoder-to-cm'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm1_Gain
                                        * Referenced by: '<Root>/encoder-to-cm1'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S24>/S-Function1'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S22>/S-Function'
                                        */
  4U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S16>/S-Function'
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
