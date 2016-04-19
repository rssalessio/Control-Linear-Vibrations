/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: shaping.h
 *
 * Code generated for Simulink model 'shaping'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Apr 19 17:28:15 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_shaping_h_
#define RTW_HEADER_shaping_h_
#include <string.h>
#include <stddef.h>
#ifndef shaping_COMMON_INCLUDES_
# define shaping_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* shaping_COMMON_INCLUDES_ */

#include "shaping_types.h"

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
  real_T Sum;                          /* '<S4>/Sum' */
  real_T loopshaping;                  /* '<S2>/loopshaping' */
  real_T DataTypeConversion1;          /* '<S16>/Data Type Conversion1' */
  real32_T conversion13;               /* '<S5>/conversion13' */
  real32_T conversion2;                /* '<S5>/conversion2' */
  real32_T conversion8;                /* '<S20>/conversion8' */
  real32_T SFunction1_o1;              /* '<S20>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S20>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S20>/S-Function1' */
  real32_T conversion4;                /* '<S5>/conversion4' */
  real32_T conversion5;                /* '<S5>/conversion5' */
  real32_T conversion6;                /* '<S5>/conversion6' */
  real32_T conversion7;                /* '<S5>/conversion7' */
  int32_T SFunction;                   /* '<S18>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S3>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S3>/S-Function2' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T conversion3;               /* '<S5>/conversion3' */
  boolean_T conversion9;               /* '<S5>/conversion9' */
  boolean_T conversion10;              /* '<S5>/conversion10' */
  boolean_T SFunction_d;               /* '<S17>/S-Function' */
  boolean_T LogicalOperator_n;         /* '<S20>/Logical Operator' */
} B_shaping_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S3>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S18>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S20>/S-Function1' */
  real_T SFunction_DSTATE_l;           /* '<S5>/S-Function' */
  real_T SFunction1_DSTATE_b;          /* '<S3>/S-Function1' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S1>/Memory1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_shaping_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T loopshaping_CSTATE[2];        /* '<S2>/loopshaping' */
} X_shaping_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T loopshaping_CSTATE[2];        /* '<S2>/loopshaping' */
} XDot_shaping_T;

/* State disabled  */
typedef struct {
  boolean_T loopshaping_CSTATE[2];     /* '<S2>/loopshaping' */
} XDis_shaping_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_shaping_T_ {
  real_T UpperThreshold_const;         /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T LowerThreshold_const;         /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T UpperThreshold_const_e;       /* Mask Parameter: UpperThreshold_const_e
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T LowerThreshold_const_f;       /* Mask Parameter: LowerThreshold_const_f
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S18>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_l;  /* Mask Parameter: DigitalOutput_pinNumber_l
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 2
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
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T cmtoencoder_Gain;             /* Expression: 560
                                        * Referenced by: '<S4>/cm-to-encoder'
                                        */
  real_T loopshaping_A[2];             /* Computed Parameter: loopshaping_A
                                        * Referenced by: '<S2>/loopshaping'
                                        */
  real_T loopshaping_B;                /* Computed Parameter: loopshaping_B
                                        * Referenced by: '<S2>/loopshaping'
                                        */
  real_T loopshaping_C[2];             /* Computed Parameter: loopshaping_C
                                        * Referenced by: '<S2>/loopshaping'
                                        */
  real_T loopshaping_D;                /* Computed Parameter: loopshaping_D
                                        * Referenced by: '<S2>/loopshaping'
                                        */
  real_T Constant_Value;               /* Expression: 323
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S5>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S17>/S-Function'
                                        */
  uint32_T SFunction_p1_d;             /* Computed Parameter: SFunction_p1_d
                                        * Referenced by: '<S19>/S-Function'
                                        */
  uint8_T SFunction_P1_d;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S18>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S5>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_shaping_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_shaping_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[2];
    real_T odeF[3][2];
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
extern P_shaping_T shaping_P;

/* Block signals (auto storage) */
extern B_shaping_T shaping_B;

/* Continuous states (auto storage) */
extern X_shaping_T shaping_X;

/* Block states (auto storage) */
extern DW_shaping_T shaping_DW;

/* External data declarations for dependent source files */
extern const boolean_T shaping_BGND;   /* boolean_T ground */

/* Model entry point functions */
extern void shaping_initialize(void);
extern void shaping_output(void);
extern void shaping_update(void);
extern void shaping_terminate(void);

/* Real-time Model object */
extern RT_MODEL_shaping_T *const shaping_M;

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
 * '<Root>' : 'shaping'
 * '<S1>'   : 'shaping/Condom'
 * '<S2>'   : 'shaping/Controller'
 * '<S3>'   : 'shaping/PoliArd Init'
 * '<S4>'   : 'shaping/System '
 * '<S5>'   : 'shaping/Transmission'
 * '<S6>'   : 'shaping/Condom/Current Operating Zone'
 * '<S7>'   : 'shaping/Condom/Current Operating Zone1'
 * '<S8>'   : 'shaping/Condom/Reference Overshoot'
 * '<S9>'   : 'shaping/Condom/Current Operating Zone/Lower Threshold'
 * '<S10>'  : 'shaping/Condom/Current Operating Zone/Upper Threshold'
 * '<S11>'  : 'shaping/Condom/Current Operating Zone1/Lower Threshold'
 * '<S12>'  : 'shaping/Condom/Current Operating Zone1/Upper Threshold'
 * '<S13>'  : 'shaping/PoliArd Init/Digital Output1'
 * '<S14>'  : 'shaping/PoliArd Init/Digital Output3'
 * '<S15>'  : 'shaping/System /Encoder '
 * '<S16>'  : 'shaping/System /Motor'
 * '<S17>'  : 'shaping/System /Encoder /Digital Input'
 * '<S18>'  : 'shaping/System /Encoder /Encoder'
 * '<S19>'  : 'shaping/System /Motor/Digital Input1'
 * '<S20>'  : 'shaping/System /Motor/Motor'
 */
#endif                                 /* RTW_HEADER_shaping_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
