/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dynamic.h
 *
 * Code generated for Simulink model 'dynamic'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 16:17:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dynamic_h_
#define RTW_HEADER_dynamic_h_
#include <string.h>
#include <stddef.h>
#ifndef dynamic_COMMON_INCLUDES_
# define dynamic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* dynamic_COMMON_INCLUDES_ */

#include "dynamic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T RateTransition5;              /* '<S6>/Rate Transition5' */
  real_T Sum;                          /* '<Root>/Sum' */
  real32_T conversion13;               /* '<S6>/conversion13' */
  real32_T RateTransition6;            /* '<S6>/Rate Transition6' */
  real32_T conversion4;                /* '<S6>/conversion4' */
  real32_T conversion5;                /* '<S6>/conversion5' */
  real32_T conversion6;                /* '<S6>/conversion6' */
  real32_T conversion7;                /* '<S6>/conversion7' */
  real32_T conversion8;                /* '<S3>/conversion8' */
  real32_T SFunction1_o1;              /* '<S3>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S3>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S3>/S-Function1' */
  int32_T SFunction;                   /* '<S1>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S5>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S5>/S-Function2' */
  boolean_T conversion1;               /* '<S6>/conversion1' */
  boolean_T conversion3;               /* '<S6>/conversion3' */
  boolean_T conversion9;               /* '<S6>/conversion9' */
  boolean_T conversion10;              /* '<S6>/conversion10' */
  boolean_T SFunction_b;               /* '<S2>/S-Function' */
  boolean_T RateTransition;            /* '<S3>/Rate Transition' */
  boolean_T LogicalOperator;           /* '<S3>/Logical Operator' */
} B_dynamic_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S5>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S1>/S-Function' */
  real_T SFunction_DSTATE_d;           /* '<S6>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S3>/S-Function1' */
  real_T SFunction1_DSTATE_d;          /* '<S5>/S-Function1' */
  real_T RateTransition5_Buffer0;      /* '<S6>/Rate Transition5' */
  real32_T RateTransition6_Buffer0;    /* '<S6>/Rate Transition6' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_dynamic_T;

/* Parameters (auto storage) */
struct P_dynamic_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_j;  /* Mask Parameter: DigitalOutput_pinNumber_j
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  real_T RateTransition5_X0;           /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition5'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 2*2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real32_T RateTransition6_X0;         /* Computed Parameter: RateTransition6_X0
                                        * Referenced by: '<S6>/Rate Transition6'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S3>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S3>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint32_T SFunction_p1_n;             /* Computed Parameter: SFunction_p1_n
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S3>/S-Function1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_dynamic_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_dynamic_T dynamic_P;

/* Block signals (auto storage) */
extern B_dynamic_T dynamic_B;

/* Block states (auto storage) */
extern DW_dynamic_T dynamic_DW;

/* External data declarations for dependent source files */
extern const boolean_T dynamic_BGND;   /* boolean_T ground */

/* Model entry point functions */
extern void dynamic_initialize(void);
extern void dynamic_output0(void);
extern void dynamic_update0(void);
extern void dynamic_output1(void);
extern void dynamic_update1(void);
extern void dynamic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dynamic_T *const dynamic_M;

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
 * '<Root>' : 'dynamic'
 * '<S1>'   : 'dynamic/Encoder'
 * '<S2>'   : 'dynamic/Encoder Enable'
 * '<S3>'   : 'dynamic/Motor'
 * '<S4>'   : 'dynamic/Motor enable'
 * '<S5>'   : 'dynamic/PoliArd Init'
 * '<S6>'   : 'dynamic/Transmission'
 * '<S7>'   : 'dynamic/PoliArd Init/Digital Output1'
 * '<S8>'   : 'dynamic/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_dynamic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
