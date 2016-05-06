/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BasicTestModel.h
 *
 * Code generated for Simulink model 'BasicTestModel'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 11:24:56 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BasicTestModel_h_
#define RTW_HEADER_BasicTestModel_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef BasicTestModel_COMMON_INCLUDES_
# define BasicTestModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* BasicTestModel_COMMON_INCLUDES_ */

#include "BasicTestModel_types.h"

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
  real_T Add;                          /* '<Root>/Add' */
  int64m_T Gain2;                      /* '<Root>/Gain2' */
  real32_T conversion13;               /* '<S6>/conversion13' */
  real32_T conversion2;                /* '<S6>/conversion2' */
  real32_T conversion8;                /* '<S10>/conversion8' */
  real32_T SFunction1_o1;              /* '<S10>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S10>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S10>/S-Function1' */
  real32_T conversion4;                /* '<S6>/conversion4' */
  real32_T conversion5;                /* '<S6>/conversion5' */
  real32_T conversion6;                /* '<S6>/conversion6' */
  real32_T conversion7;                /* '<S6>/conversion7' */
  int32_T SFunction;                   /* '<S8>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S3>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S3>/S-Function2' */
  boolean_T conversion1;               /* '<S6>/conversion1' */
  boolean_T conversion3;               /* '<S6>/conversion3' */
  boolean_T conversion9;               /* '<S6>/conversion9' */
  boolean_T conversion10;              /* '<S6>/conversion10' */
  boolean_T SFunction_d;               /* '<S7>/S-Function' */
  boolean_T LogicalOperator;           /* '<S10>/Logical Operator' */
} B_BasicTestModel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S3>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S8>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S10>/S-Function1' */
  real_T SFunction_DSTATE_l;           /* '<S6>/S-Function' */
  real_T SFunction1_DSTATE_f;          /* '<S3>/S-Function1' */
} DW_BasicTestModel_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T ZeroPole_CSTATE[2];           /* '<Root>/Zero-Pole' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE[2];        /* '<Root>/Transfer Fcn' */
  real_T ZeroPole1_CSTATE[2];          /* '<Root>/Zero-Pole1' */
  real_T ZeroPole2_CSTATE[4];          /* '<Root>/Zero-Pole2' */
  real_T ZeroPole4_CSTATE[2];          /* '<Root>/Zero-Pole4' */
} X_BasicTestModel_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T ZeroPole_CSTATE[2];           /* '<Root>/Zero-Pole' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE[2];        /* '<Root>/Transfer Fcn' */
  real_T ZeroPole1_CSTATE[2];          /* '<Root>/Zero-Pole1' */
  real_T ZeroPole2_CSTATE[4];          /* '<Root>/Zero-Pole2' */
  real_T ZeroPole4_CSTATE[2];          /* '<Root>/Zero-Pole4' */
} XDot_BasicTestModel_T;

/* State disabled  */
typedef struct {
  boolean_T ZeroPole_CSTATE[2];        /* '<Root>/Zero-Pole' */
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE[2];     /* '<Root>/Transfer Fcn' */
  boolean_T ZeroPole1_CSTATE[2];       /* '<Root>/Zero-Pole1' */
  boolean_T ZeroPole2_CSTATE[4];       /* '<Root>/Zero-Pole2' */
  boolean_T ZeroPole4_CSTATE[2];       /* '<Root>/Zero-Pole4' */
} XDis_BasicTestModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_BasicTestModel_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S8>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S11>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_f;  /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2*pi*3
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
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
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn_A[2];             /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C[2];             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T ZeroPole1_A[2];               /* Computed Parameter: ZeroPole1_A
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */
  real_T ZeroPole1_B;                  /* Computed Parameter: ZeroPole1_B
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */
  real_T ZeroPole1_C[2];               /* Computed Parameter: ZeroPole1_C
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */
  real_T ZeroPole1_D;                  /* Computed Parameter: ZeroPole1_D
                                        * Referenced by: '<Root>/Zero-Pole1'
                                        */
  real_T ZeroPole2_A[7];               /* Computed Parameter: ZeroPole2_A
                                        * Referenced by: '<Root>/Zero-Pole2'
                                        */
  real_T ZeroPole2_B[2];               /* Computed Parameter: ZeroPole2_B
                                        * Referenced by: '<Root>/Zero-Pole2'
                                        */
  real_T ZeroPole2_C[4];               /* Computed Parameter: ZeroPole2_C
                                        * Referenced by: '<Root>/Zero-Pole2'
                                        */
  real_T ZeroPole2_D;                  /* Computed Parameter: ZeroPole2_D
                                        * Referenced by: '<Root>/Zero-Pole2'
                                        */
  real_T ZeroPole4_A[2];               /* Computed Parameter: ZeroPole4_A
                                        * Referenced by: '<Root>/Zero-Pole4'
                                        */
  real_T ZeroPole4_B;                  /* Computed Parameter: ZeroPole4_B
                                        * Referenced by: '<Root>/Zero-Pole4'
                                        */
  real_T ZeroPole4_C[2];               /* Computed Parameter: ZeroPole4_C
                                        * Referenced by: '<Root>/Zero-Pole4'
                                        */
  real_T ZeroPole4_D;                  /* Computed Parameter: ZeroPole4_D
                                        * Referenced by: '<Root>/Zero-Pole4'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S10>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S10>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S7>/S-Function'
                                        */
  uint32_T SFunction_p1_l;             /* Computed Parameter: SFunction_p1_l
                                        * Referenced by: '<S9>/S-Function'
                                        */
  uint32_T SFunction_p1_m;             /* Computed Parameter: SFunction_p1_m
                                        * Referenced by: '<S13>/S-Function'
                                        */
  uint32_T SFunction_p1_h;             /* Computed Parameter: SFunction_p1_h
                                        * Referenced by: '<S16>/S-Function'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S8>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S10>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BasicTestModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_BasicTestModel_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[13];
    real_T odeF[3][13];
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
extern P_BasicTestModel_T BasicTestModel_P;

/* Block signals (auto storage) */
extern B_BasicTestModel_T BasicTestModel_B;

/* Continuous states (auto storage) */
extern X_BasicTestModel_T BasicTestModel_X;

/* Block states (auto storage) */
extern DW_BasicTestModel_T BasicTestModel_DW;

/* External data declarations for dependent source files */
extern const boolean_T BasicTestModel_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void BasicTestModel_initialize(void);
extern void BasicTestModel_output(void);
extern void BasicTestModel_update(void);
extern void BasicTestModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BasicTestModel_T *const BasicTestModel_M;

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
 * '<Root>' : 'BasicTestModel'
 * '<S1>'   : 'BasicTestModel/Encoder '
 * '<S2>'   : 'BasicTestModel/Motor'
 * '<S3>'   : 'BasicTestModel/PoliArd Init'
 * '<S4>'   : 'BasicTestModel/Subsystem'
 * '<S5>'   : 'BasicTestModel/Subsystem1'
 * '<S6>'   : 'BasicTestModel/Transmission'
 * '<S7>'   : 'BasicTestModel/Encoder /Digital Input'
 * '<S8>'   : 'BasicTestModel/Encoder /Encoder'
 * '<S9>'   : 'BasicTestModel/Motor/Digital Input1'
 * '<S10>'  : 'BasicTestModel/Motor/Motor'
 * '<S11>'  : 'BasicTestModel/PoliArd Init/Digital Output1'
 * '<S12>'  : 'BasicTestModel/PoliArd Init/Digital Output3'
 * '<S13>'  : 'BasicTestModel/Subsystem/Digital Input1'
 * '<S14>'  : 'BasicTestModel/Subsystem/RefLogic'
 * '<S15>'  : 'BasicTestModel/Subsystem/RefLogic/Subsystem'
 * '<S16>'  : 'BasicTestModel/Subsystem1/Digital Input1'
 * '<S17>'  : 'BasicTestModel/Subsystem1/RefLogic'
 * '<S18>'  : 'BasicTestModel/Subsystem1/RefLogic/Subsystem'
 */
#endif                                 /* RTW_HEADER_BasicTestModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
