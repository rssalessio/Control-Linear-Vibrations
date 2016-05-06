/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BlankModel.h
 *
 * Code generated for Simulink model 'BlankModel'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 12:54:17 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BlankModel_h_
#define RTW_HEADER_BlankModel_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef BlankModel_COMMON_INCLUDES_
# define BlankModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* BlankModel_COMMON_INCLUDES_ */

#include "BlankModel_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T MotorEnabler;                 /* '<S9>/Motor Enabler' */
  real_T Product;                      /* '<S9>/Product' */
  real_T startTime;                    /* '<S4>/startTime' */
  real_T HINFINITY;                    /* '<S2>/H INFINITY' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T MD;                           /* '<S7>/Init Manager' */
  real_T ER;                           /* '<S7>/Init Manager' */
  real_T MD_d;                         /* '<S7>/Alert Manager' */
  real_T ER_h;                         /* '<S7>/Alert Manager' */
  real32_T conversion13;               /* '<S6>/conversion13' */
  real32_T conversion2;                /* '<S6>/conversion2' */
  real32_T conversion8;                /* '<S23>/conversion8' */
  real32_T SFunction1_o1;              /* '<S23>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S23>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S23>/S-Function1' */
  real32_T conversion4;                /* '<S6>/conversion4' */
  real32_T conversion5;                /* '<S6>/conversion5' */
  real32_T conversion6;                /* '<S6>/conversion6' */
  real32_T conversion7;                /* '<S6>/conversion7' */
  int32_T SFunction;                   /* '<S22>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S3>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S3>/S-Function2' */
  boolean_T MotorDetector;             /* '<S7>/Motor Detector' */
  boolean_T EncoderDetector;           /* '<S7>/Encoder Detector' */
  boolean_T LogicalOperator;           /* '<S10>/Logical Operator' */
  boolean_T conversion10;              /* '<S6>/conversion10' */
  boolean_T LogicalOperator_c;         /* '<Root>/Logical Operator' */
  boolean_T LogicalOperator_n;         /* '<S23>/Logical Operator' */
} B_BlankModel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S3>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S22>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S23>/S-Function1' */
  real_T SFunction_DSTATE_l;           /* '<S6>/S-Function' */
  real_T SFunction1_DSTATE_b;          /* '<S3>/S-Function1' */
  real_T Memory1_PreviousInput;        /* '<S10>/Memory1' */
  int32_T Memory_PreviousInput;        /* '<S8>/Memory' */
  uint16_T temporalCounter_i1;         /* '<S7>/Init Manager' */
  uint8_T is_active_c1_BlankModel;     /* '<S7>/Init Manager' */
  uint8_T is_c1_BlankModel;            /* '<S7>/Init Manager' */
  uint8_T is_active_c3_BlankModel;     /* '<S7>/Alert Manager' */
  uint8_T is_c3_BlankModel;            /* '<S7>/Alert Manager' */
  boolean_T Memory1_PreviousInput_m;   /* '<S9>/Memory1' */
  boolean_T Controller_MODE;           /* '<Root>/Controller' */
} DW_BlankModel_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T HINFINITY_CSTATE[3];          /* '<S2>/H INFINITY' */
} X_BlankModel_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T HINFINITY_CSTATE[3];          /* '<S2>/H INFINITY' */
} XDot_BlankModel_T;

/* State disabled  */
typedef struct {
  boolean_T HINFINITY_CSTATE[3];       /* '<S2>/H INFINITY' */
} XDis_BlankModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_BlankModel_T_ {
  real_T UpperThreshold_const;         /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T LowerThreshold_const;         /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S22>/S-Function'
                                        */
  int64m_T UpperThreshold_const_i;     /* Mask Parameter: UpperThreshold_const_i
                                        * Referenced by: '<S15>/Constant'
                                        */
  int64m_T LowerThreshold_const_a;     /* Mask Parameter: LowerThreshold_const_a
                                        * Referenced by: '<S14>/Constant'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S18>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_l;  /* Mask Parameter: DigitalOutput_pinNumber_l
                                        * Referenced by: '<S19>/Digital Output'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T HINFINITY_A[9];               /* Computed Parameter: HINFINITY_A
                                        * Referenced by: '<S2>/H INFINITY'
                                        */
  real_T HINFINITY_B[3];               /* Computed Parameter: HINFINITY_B
                                        * Referenced by: '<S2>/H INFINITY'
                                        */
  real_T HINFINITY_C[3];               /* Computed Parameter: HINFINITY_C
                                        * Referenced by: '<S2>/H INFINITY'
                                        */
  real_T HINFINITY_X0;                 /* Expression: 0
                                        * Referenced by: '<S2>/H INFINITY'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S10>/Memory1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0.5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2*pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: -3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T cmtoencoder_Gain;             /* Expression: 560
                                        * Referenced by: '<S5>/cm-to-encoder'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  int32_T Memory_X0;                   /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S8>/Memory'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S13>/S-Function'
                                        */
  int32_T encodertocm_Gain;            /* Computed Parameter: encodertocm_Gain
                                        * Referenced by: '<S8>/encoder-to-cm'
                                        */
  int32_T encodertocm_Gain_j;          /* Computed Parameter: encodertocm_Gain_j
                                        * Referenced by: '<Root>/encoder-to-cm'
                                        */
  uint8_T SFunction_P1_d;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S22>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  boolean_T Memory1_X0_p;              /* Computed Parameter: Memory1_X0_p
                                        * Referenced by: '<S9>/Memory1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BlankModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_BlankModel_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[3];
    real_T odeF[3][3];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_BlankModel_T BlankModel_P;

/* Block signals (auto storage) */
extern B_BlankModel_T BlankModel_B;

/* Continuous states (auto storage) */
extern X_BlankModel_T BlankModel_X;

/* Block states (auto storage) */
extern DW_BlankModel_T BlankModel_DW;

/* External data declarations for dependent source files */
extern const boolean_T BlankModel_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void BlankModel_initialize(void);
extern void BlankModel_output(void);
extern void BlankModel_update(void);
extern void BlankModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BlankModel_T *const BlankModel_M;

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
 * '<Root>' : 'BlankModel'
 * '<S1>'   : 'BlankModel/Condom'
 * '<S2>'   : 'BlankModel/Controller'
 * '<S3>'   : 'BlankModel/PoliArd Init'
 * '<S4>'   : 'BlankModel/Repeating Sequence'
 * '<S5>'   : 'BlankModel/System '
 * '<S6>'   : 'BlankModel/Transmission'
 * '<S7>'   : 'BlankModel/Condom/Manager'
 * '<S8>'   : 'BlankModel/Condom/Overshoot Travel Protection'
 * '<S9>'   : 'BlankModel/Condom/Reference  Protection'
 * '<S10>'  : 'BlankModel/Condom/Voltage Protection'
 * '<S11>'  : 'BlankModel/Condom/Manager/Alert Manager'
 * '<S12>'  : 'BlankModel/Condom/Manager/Init Manager'
 * '<S13>'  : 'BlankModel/Condom/Manager/Second Switch'
 * '<S14>'  : 'BlankModel/Condom/Overshoot Travel Protection/Lower Threshold'
 * '<S15>'  : 'BlankModel/Condom/Overshoot Travel Protection/Upper Threshold'
 * '<S16>'  : 'BlankModel/Condom/Voltage Protection/Lower Threshold'
 * '<S17>'  : 'BlankModel/Condom/Voltage Protection/Upper Threshold'
 * '<S18>'  : 'BlankModel/PoliArd Init/Digital Output1'
 * '<S19>'  : 'BlankModel/PoliArd Init/Digital Output3'
 * '<S20>'  : 'BlankModel/System /Encoder '
 * '<S21>'  : 'BlankModel/System /Motor'
 * '<S22>'  : 'BlankModel/System /Encoder /Encoder'
 * '<S23>'  : 'BlankModel/System /Motor/Motor'
 */
#endif                                 /* RTW_HEADER_BlankModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
