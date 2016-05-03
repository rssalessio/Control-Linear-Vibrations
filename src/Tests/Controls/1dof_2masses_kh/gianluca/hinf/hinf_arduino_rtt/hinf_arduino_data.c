/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hinf_arduino_data.c
 *
 * Code generated for Simulink model 'hinf_arduino'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue May 03 15:04:05 2016
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
                                        * Referenced by: '<S19>/S-Function'
                                        */

  { { 0UL, 0x300UL } },                /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S13>/Constant'
                                        */

  { { 0UL, 0xFFFFFD00UL } },           /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  0,                                   /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S8>/Delay Input1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_p
                                        * Referenced by: '<S15>/Digital Output'
                                        */

  /*  Computed Parameter: HINFINITY_A
   * Referenced by: '<S2>/H INFINITY'
   */
  { -0.082167417866213843, -912.96501485140459, -1350.2584866957773,
    5.5374548588824757, -710.20295841319319, -4688.2051968652622,
    -14587.925947558242, -430.27084545656567, -3288.0892255892254,
    -114.12062685642557, 371.73874919215456, 0.69218185736030946,
    -154.53294555922491, -612.80384826135639, -1850.2064684026927,
    -4.0748870664604395E-17, 32.0, -3.4024825829091207E-16,
    -5.7078211207281059E-36, -7.727242583451224E-17, 32.0,
    -6.5060346421319894E-16 },

  /*  Computed Parameter: HINFINITY_B
   * Referenced by: '<S2>/H INFINITY'
   */
  { 51.142053356583759, -4.2157125872990978E-18, -6.6658905879390645E-19,
    -4.8489677507717324E-19, 4.2130062030722961E-19 },

  /*  Computed Parameter: HINFINITY_C
   * Referenced by: '<S2>/H INFINITY'
   */
  { -0.13946524846774444, 0.45429681249821541, 0.00084590592762052443,
    -0.10849115841941048, -0.716173886197605, -2.2284629572978831 },
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
                                        * Referenced by: '<S6>/S-Function'
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
  0,                                   /* Computed Parameter: Memory2_X0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S18>/S-Function'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1_c
                                        * Referenced by: '<S20>/S-Function'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm_Gain
                                        * Referenced by: '<S9>/encoder-to-cm'
                                        */
  1963413621,                          /* Computed Parameter: encodertocm_Gain_j
                                        * Referenced by: '<Root>/encoder-to-cm'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S19>/S-Function'
                                        */
  2U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S21>/S-Function1'
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
