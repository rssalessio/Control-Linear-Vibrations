/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorTest.h
 *
 * Code generated for Simulink model 'MotorTest'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 17:04:47 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorTest_h_
#define RTW_HEADER_MotorTest_h_
#include <string.h>
#include <stddef.h>
#ifndef MotorTest_COMMON_INCLUDES_
# define MotorTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* MotorTest_COMMON_INCLUDES_ */

#include "MotorTest_types.h"

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

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T conversion13;               /* '<S9>/conversion13' */
  real32_T conversion2;                /* '<S9>/conversion2' */
  real32_T conversion8;                /* '<S7>/conversion8' */
  real32_T SFunction1_o1;              /* '<S7>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S7>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S7>/S-Function1' */
  real32_T conversion5;                /* '<S9>/conversion5' */
  real32_T conversion6;                /* '<S9>/conversion6' */
  real32_T conversion7;                /* '<S9>/conversion7' */
  int32_T SFunction;                   /* '<S6>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S8>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S8>/S-Function2' */
  boolean_T conversion1;               /* '<S9>/conversion1' */
  boolean_T conversion3;               /* '<S9>/conversion3' */
  boolean_T conversion9;               /* '<S9>/conversion9' */
  boolean_T conversion10;              /* '<S9>/conversion10' */
  boolean_T LogicalOperator;           /* '<S7>/Logical Operator' */
  boolean_T SFunction_d;               /* '<S4>/S-Function' */
} B_MotorTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S8>/S-Function2' */
  real_T SFunction1_DSTATE;            /* '<S7>/S-Function1' */
  real_T SFunction_DSTATE;             /* '<S6>/S-Function' */
  real_T SFunction_DSTATE_l;           /* '<S9>/S-Function' */
  real_T SFunction1_DSTATE_f;          /* '<S8>/S-Function1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_MotorTest_T;

/* Parameters (auto storage) */
struct P_MotorTest_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_f;  /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S11>/Digital Output'
                                        */
  real_T Constant1_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 2*3
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
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S9>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint32_T SFunction_p1_l;             /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S5>/S-Function'
                                        */
  uint32_T SFunction_p1_l0;            /* Computed Parameter: SFunction_p1_l0
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S9>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MotorTest_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_MotorTest_T MotorTest_P;

/* Block signals (auto storage) */
extern B_MotorTest_T MotorTest_B;

/* Block states (auto storage) */
extern DW_MotorTest_T MotorTest_DW;

/* External data declarations for dependent source files */
extern const boolean_T MotorTest_BGND; /* boolean_T ground */

/* Model entry point functions */
extern void MotorTest_initialize(void);
extern void MotorTest_output0(void);
extern void MotorTest_update0(void);
extern void MotorTest_output2(void);
extern void MotorTest_update2(void);
extern void MotorTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorTest_T *const MotorTest_M;

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
 * '<Root>' : 'MotorTest'
 * '<S1>'   : 'MotorTest/Analog Input'
 * '<S2>'   : 'MotorTest/Band-Limited White Noise'
 * '<S3>'   : 'MotorTest/Chirp Signal'
 * '<S4>'   : 'MotorTest/Digital Input'
 * '<S5>'   : 'MotorTest/Digital Input1'
 * '<S6>'   : 'MotorTest/Encoder'
 * '<S7>'   : 'MotorTest/Motor'
 * '<S8>'   : 'MotorTest/PoliArd Init'
 * '<S9>'   : 'MotorTest/Transmission'
 * '<S10>'  : 'MotorTest/PoliArd Init/Digital Output1'
 * '<S11>'  : 'MotorTest/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_MotorTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
