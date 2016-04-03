/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pseudorandom.h
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

#ifndef RTW_HEADER_pseudorandom_h_
#define RTW_HEADER_pseudorandom_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef pseudorandom_COMMON_INCLUDES_
# define pseudorandom_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* pseudorandom_COMMON_INCLUDES_ */

#include "pseudorandom_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T conversion13;               /* '<S7>/conversion13' */
  real32_T conversion8;                /* '<S4>/conversion8' */
  real32_T SFunction1_o1;              /* '<S4>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S4>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S4>/S-Function1' */
  real32_T conversion4;                /* '<S7>/conversion4' */
  real32_T conversion5;                /* '<S7>/conversion5' */
  real32_T conversion6;                /* '<S7>/conversion6' */
  real32_T conversion7;                /* '<S7>/conversion7' */
  int32_T SFunction;                   /* '<S2>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S6>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S6>/S-Function2' */
  boolean_T conversion1;               /* '<S7>/conversion1' */
  boolean_T conversion3;               /* '<S7>/conversion3' */
  boolean_T conversion9;               /* '<S7>/conversion9' */
  boolean_T conversion10;              /* '<S7>/conversion10' */
  boolean_T LogicalOperator;           /* '<S4>/Logical Operator' */
  boolean_T SFunction_b;               /* '<S3>/S-Function' */
} B_pseudorandom_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S6>/S-Function2' */
  real_T SFunction1_DSTATE;            /* '<S4>/S-Function1' */
  real_T SFunction_DSTATE;             /* '<S2>/S-Function' */
  real_T SFunction_DSTATE_d;           /* '<S7>/S-Function' */
  real_T SFunction1_DSTATE_d;          /* '<S6>/S-Function1' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
} DW_pseudorandom_T;

/* Parameters (auto storage) */
struct P_pseudorandom_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_j;  /* Mask Parameter: DigitalOutput_pinNumber_j
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: seed
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T Output_Gain;                  /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S1>/Output'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S7>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S5>/S-Function'
                                        */
  uint32_T SFunction_p1_f;             /* Computed Parameter: SFunction_p1_f
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S7>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pseudorandom_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_pseudorandom_T pseudorandom_P;

/* Block signals (auto storage) */
extern B_pseudorandom_T pseudorandom_B;

/* Block states (auto storage) */
extern DW_pseudorandom_T pseudorandom_DW;

/* External data declarations for dependent source files */
extern const boolean_T pseudorandom_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void pseudorandom_initialize(void);
extern void pseudorandom_output(void);
extern void pseudorandom_update(void);
extern void pseudorandom_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pseudorandom_T *const pseudorandom_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pseudorandom'
 * '<S1>'   : 'pseudorandom/Band-Limited White Noise'
 * '<S2>'   : 'pseudorandom/Encoder'
 * '<S3>'   : 'pseudorandom/Encoder Enable'
 * '<S4>'   : 'pseudorandom/Motor'
 * '<S5>'   : 'pseudorandom/Motor enable'
 * '<S6>'   : 'pseudorandom/PoliArd Init'
 * '<S7>'   : 'pseudorandom/Transmission'
 * '<S8>'   : 'pseudorandom/PoliArd Init/Digital Output1'
 * '<S9>'   : 'pseudorandom/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_pseudorandom_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
