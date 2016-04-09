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
 * C/C++ source code generated on : Fri Apr 08 11:18:23 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorTest_h_
#define RTW_HEADER_MotorTest_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MotorTest_COMMON_INCLUDES_
# define MotorTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* MotorTest_COMMON_INCLUDES_ */

#include "MotorTest_types.h"

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
  real_T Add1;                         /* '<Root>/Add1' */
  real32_T conversion13;               /* '<S4>/conversion13' */
  real32_T conversion2;                /* '<S4>/conversion2' */
  real32_T conversion8;                /* '<S8>/conversion8' */
  real32_T SFunction1_o1;              /* '<S8>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S8>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S8>/S-Function1' */
  real32_T conversion4;                /* '<S4>/conversion4' */
  real32_T conversion5;                /* '<S4>/conversion5' */
  real32_T conversion6;                /* '<S4>/conversion6' */
  real32_T conversion7;                /* '<S4>/conversion7' */
  int32_T SFunction;                   /* '<S6>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S3>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S3>/S-Function2' */
  boolean_T conversion1;               /* '<S4>/conversion1' */
  boolean_T conversion3;               /* '<S4>/conversion3' */
  boolean_T conversion9;               /* '<S4>/conversion9' */
  boolean_T conversion10;              /* '<S4>/conversion10' */
  boolean_T SFunction_d;               /* '<S5>/S-Function' */
  boolean_T LogicalOperator;           /* '<S8>/Logical Operator' */
} B_MotorTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S3>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S6>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S8>/S-Function1' */
  real_T SFunction_DSTATE_l;           /* '<S4>/S-Function' */
  real_T SFunction1_DSTATE_f;          /* '<S3>/S-Function1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_MotorTest_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T ZeroPole_CSTATE[2];           /* '<Root>/Zero-Pole' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} X_MotorTest_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T ZeroPole_CSTATE[2];           /* '<Root>/Zero-Pole' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} XDot_MotorTest_T;

/* State disabled  */
typedef struct {
  boolean_T ZeroPole_CSTATE[2];        /* '<Root>/Zero-Pole' */
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
} XDis_MotorTest_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_MotorTest_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_f;  /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<Root>/Constant1'
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
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T ZeroPole_A[2];                /* Computed Parameter: ZeroPole_A
                                        * Referenced by: '<Root>/Zero-Pole'
                                        */
  real_T ZeroPole_B;                   /* Computed Parameter: ZeroPole_B
                                        * Referenced by: '<Root>/Zero-Pole'
                                        */
  real_T ZeroPole_C[2];                /* Computed Parameter: ZeroPole_C
                                        * Referenced by: '<Root>/Zero-Pole'
                                        */
  real_T ZeroPole_D;                   /* Computed Parameter: ZeroPole_D
                                        * Referenced by: '<Root>/Zero-Pole'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S4>/S-Function'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S8>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S8>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S5>/S-Function'
                                        */
  uint32_T SFunction_p1_l;             /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S7>/S-Function'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S8>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S4>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MotorTest_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_MotorTest_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[4];
    real_T odeF[3][4];
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
extern P_MotorTest_T MotorTest_P;

/* Block signals (auto storage) */
extern B_MotorTest_T MotorTest_B;

/* Continuous states (auto storage) */
extern X_MotorTest_T MotorTest_X;

/* Block states (auto storage) */
extern DW_MotorTest_T MotorTest_DW;

/* External data declarations for dependent source files */
extern const boolean_T MotorTest_BGND; /* boolean_T ground */

/* Model entry point functions */
extern void MotorTest_initialize(void);
extern void MotorTest_output(void);
extern void MotorTest_update(void);
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
 * '<S1>'   : 'MotorTest/Encoder '
 * '<S2>'   : 'MotorTest/Motor'
 * '<S3>'   : 'MotorTest/PoliArd Init'
 * '<S4>'   : 'MotorTest/Transmission'
 * '<S5>'   : 'MotorTest/Encoder /Digital Input'
 * '<S6>'   : 'MotorTest/Encoder /Encoder'
 * '<S7>'   : 'MotorTest/Motor/Digital Input1'
 * '<S8>'   : 'MotorTest/Motor/Motor'
 * '<S9>'   : 'MotorTest/PoliArd Init/Digital Output1'
 * '<S10>'  : 'MotorTest/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_MotorTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
