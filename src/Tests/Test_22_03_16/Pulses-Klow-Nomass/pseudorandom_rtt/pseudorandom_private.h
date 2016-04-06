/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pseudorandom_private.h
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

#ifndef RTW_HEADER_pseudorandom_private_h_
#define RTW_HEADER_pseudorandom_private_h_
#include "rtwtypes.h"

extern void signals_Outputs_wrapper(boolean_T *signal_enable,
  boolean_T *signal_alarm,
  const real_T *xD);
extern void signals_Update_wrapper(const boolean_T *signal_enable,
  const boolean_T *signal_alarm,
  real_T *xD);
extern void sfcn_motor_new_Outputs_wrapper(const real32_T *V_mot,
  const boolean_T *Motor_en,
  real32_T *Current,
  real32_T *Debug1,
  real32_T *Debug2,
  const real_T *xD,
  const uint8_T *mot, const int_T p_width0,
  const real32_T *DC_bus, const int_T p_width1,
  const real32_T *sample_t_mot, const int_T p_width2);
extern void sfcn_motor_new_Update_wrapper(const real32_T *V_mot,
  const boolean_T *Motor_en,
  const real32_T *Current,
  const real32_T *Debug1,
  const real32_T *Debug2,
  real_T *xD,
  const uint8_T *mot, const int_T p_width0,
  const real32_T *DC_bus, const int_T p_width1,
  const real32_T *sample_t_mot, const int_T p_width2);
extern void sfcn_encoder_Outputs_wrapper(const boolean_T *reset,
  int32_T *pos,
  const real_T *xD,
  const uint8_T *enc, const int_T p_width0,
  const real_T *sample_t_enc, const int_T p_width1);
extern void sfcn_encoder_Update_wrapper(const boolean_T *reset,
  const int32_T *pos,
  real_T *xD,
  const uint8_T *enc, const int_T p_width0,
  const real_T *sample_t_enc, const int_T p_width1);
extern void SerialTx_Outputs_wrapper(const boolean_T *C1,
  const boolean_T *C2,
  const boolean_T *C3,
  const boolean_T *C4,
  const boolean_T *C5,
  const boolean_T *C6,
  const boolean_T *C7,
  const boolean_T *C8,
  const real32_T *S1,
  const real32_T *S2,
  const real32_T *S3,
  const real32_T *S4,
  const real32_T *S5,
  const real32_T *S6,
  const real_T *xD,
  const real_T *sample_tx, const int_T p_width0,
  const uint16_T *Samples, const int_T p_width1);
extern void SerialTx_Update_wrapper(const boolean_T *C1,
  const boolean_T *C2,
  const boolean_T *C3,
  const boolean_T *C4,
  const boolean_T *C5,
  const boolean_T *C6,
  const boolean_T *C7,
  const boolean_T *C8,
  const real32_T *S1,
  const real32_T *S2,
  const real32_T *S3,
  const real32_T *S4,
  const real32_T *S5,
  const real32_T *S6,
  real_T *xD,
  const real_T *sample_tx, const int_T p_width0,
  const uint16_T *Samples, const int_T p_width1);
extern void data_struct_init_Outputs_wrapper(const real_T *xD);
extern void data_struct_init_Update_wrapper(real_T *xD);
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);

#endif                                 /* RTW_HEADER_pseudorandom_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
