/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:35:37 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <string.h>
#include <stddef.h>
#ifndef untitled_COMMON_INCLUDES_
# define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T startTime;                    /* '<S3>/startTime' */
  real_T MD;                           /* '<S1>/Chart' */
  real32_T conversion13;               /* '<S4>/conversion13' */
  real32_T conversion2;                /* '<S4>/conversion2' */
  real32_T conversion4;                /* '<S4>/conversion4' */
  real32_T conversion5;                /* '<S4>/conversion5' */
  real32_T conversion6;                /* '<S4>/conversion6' */
  real32_T conversion7;                /* '<S4>/conversion7' */
  boolean_T SFunction2_o1;             /* '<S2>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S2>/S-Function2' */
  boolean_T conversion1;               /* '<S4>/conversion1' */
  boolean_T conversion3;               /* '<S4>/conversion3' */
  boolean_T conversion9;               /* '<S4>/conversion9' */
  boolean_T conversion10;              /* '<S4>/conversion10' */
} B_untitled_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S2>/S-Function2' */
  real_T DelayInput1_DSTATE;           /* '<S6>/Delay Input1' */
  real_T SFunction_DSTATE;             /* '<S4>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S2>/S-Function1' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S1>/Memory1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint8_T is_active_c3_untitled;       /* '<S1>/Chart' */
  uint8_T is_c3_untitled;              /* '<S1>/Chart' */
} DW_untitled_T;

/* Parameters (auto storage) */
struct P_untitled_T_ {
  real_T UpperThreshold_const;         /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T LowerThreshold_const;         /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S6>/Delay Input1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_i;  /* Mask Parameter: DigitalOutput_pinNumber_i
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T encodertocm_Gain;             /* Expression: 1/560
                                        * Referenced by: '<S7>/encoder-to-cm'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S4>/S-Function'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S4>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
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
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_untitled_T untitled_P;

/* Block signals (auto storage) */
extern B_untitled_T untitled_B;

/* Block states (auto storage) */
extern DW_untitled_T untitled_DW;

/* External data declarations for dependent source files */
extern const boolean_T untitled_BGND;  /* boolean_T ground */

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_output(void);
extern void untitled_update(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;

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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Condom'
 * '<S2>'   : 'untitled/PoliArd Init'
 * '<S3>'   : 'untitled/Repeating Sequence'
 * '<S4>'   : 'untitled/Transmission'
 * '<S5>'   : 'untitled/Condom/Chart'
 * '<S6>'   : 'untitled/Condom/Detect Change'
 * '<S7>'   : 'untitled/Condom/Ovrshoot Travel Protection'
 * '<S8>'   : 'untitled/Condom/Reference Overshoot'
 * '<S9>'   : 'untitled/Condom/Voltage Protection'
 * '<S10>'  : 'untitled/Condom/Ovrshoot Travel Protection/Lower Threshold'
 * '<S11>'  : 'untitled/Condom/Ovrshoot Travel Protection/Upper Threshold'
 * '<S12>'  : 'untitled/PoliArd Init/Digital Output1'
 * '<S13>'  : 'untitled/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
