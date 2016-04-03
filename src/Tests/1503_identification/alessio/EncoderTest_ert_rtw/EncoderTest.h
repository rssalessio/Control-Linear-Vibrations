/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EncoderTest.h
 *
 * Code generated for Simulink model 'EncoderTest'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Tue Mar 15 13:25:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EncoderTest_h_
#define RTW_HEADER_EncoderTest_h_
#include <stddef.h>
#include <string.h>
#ifndef EncoderTest_COMMON_INCLUDES_
# define EncoderTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* EncoderTest_COMMON_INCLUDES_ */

#include "EncoderTest_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T conversion13;               /* '<S6>/conversion13' */
  real32_T conversion2;                /* '<S6>/conversion2' */
  real32_T conversion4;                /* '<S6>/conversion4' */
  real32_T conversion5;                /* '<S6>/conversion5' */
  real32_T conversion6;                /* '<S6>/conversion6' */
  real32_T conversion7;                /* '<S6>/conversion7' */
  int32_T SFunction;                   /* '<S2>/S-Function' */
  int32_T SFunction_l;                 /* '<S3>/S-Function' */
  int32_T SFunction_f;                 /* '<S4>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S5>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S5>/S-Function2' */
  boolean_T conversion1;               /* '<S6>/conversion1' */
  boolean_T conversion3;               /* '<S6>/conversion3' */
  boolean_T conversion9;               /* '<S6>/conversion9' */
  boolean_T conversion10;              /* '<S6>/conversion10' */
  boolean_T SFunction_h;               /* '<S1>/S-Function' */
} B_EncoderTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S5>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S2>/S-Function' */
  real_T SFunction_DSTATE_p;           /* '<S3>/S-Function' */
  real_T SFunction_DSTATE_m;           /* '<S4>/S-Function' */
  real_T SFunction_DSTATE_l;           /* '<S6>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S5>/S-Function1' */
} DW_EncoderTest_T;

/* Parameters (auto storage) */
struct P_EncoderTest_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T Encoder1_dt_enc;              /* Mask Parameter: Encoder1_dt_enc
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T Encoder2_dt_enc;              /* Mask Parameter: Encoder2_dt_enc
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_e;  /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_P1_hv;             /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint8_T SFunction_P1_n;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_EncoderTest_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_EncoderTest_T EncoderTest_P;

/* Block signals (auto storage) */
extern B_EncoderTest_T EncoderTest_B;

/* Block states (auto storage) */
extern DW_EncoderTest_T EncoderTest_DW;

/* External data declarations for dependent source files */
extern const boolean_T EncoderTest_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void EncoderTest_initialize(void);
extern void EncoderTest_step(void);
extern void EncoderTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_EncoderTest_T *const EncoderTest_M;

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
 * '<Root>' : 'EncoderTest'
 * '<S1>'   : 'EncoderTest/Digital Input'
 * '<S2>'   : 'EncoderTest/Encoder'
 * '<S3>'   : 'EncoderTest/Encoder1'
 * '<S4>'   : 'EncoderTest/Encoder2'
 * '<S5>'   : 'EncoderTest/PoliArd Init'
 * '<S6>'   : 'EncoderTest/Transmission'
 * '<S7>'   : 'EncoderTest/PoliArd Init/Digital Output1'
 * '<S8>'   : 'EncoderTest/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_EncoderTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
