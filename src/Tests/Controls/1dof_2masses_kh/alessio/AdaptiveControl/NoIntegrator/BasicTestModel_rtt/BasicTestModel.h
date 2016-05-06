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
 * C/C++ source code generated on : Fri May 06 10:52:10 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BasicTestModel_h_
#define RTW_HEADER_BasicTestModel_h_
#include <string.h>
#include <stddef.h>
#ifndef BasicTestModel_COMMON_INCLUDES_
# define BasicTestModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* BasicTestModel_COMMON_INCLUDES_ */

#include "BasicTestModel_types.h"

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
  real32_T conversion13;               /* '<S3>/conversion13' */
  real32_T conversion2;                /* '<S3>/conversion2' */
  real32_T conversion4;                /* '<S3>/conversion4' */
  real32_T conversion5;                /* '<S3>/conversion5' */
  real32_T conversion6;                /* '<S3>/conversion6' */
  real32_T conversion7;                /* '<S3>/conversion7' */
  boolean_T SFunction2_o1;             /* '<S2>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S2>/S-Function2' */
  boolean_T conversion1;               /* '<S3>/conversion1' */
  boolean_T conversion3;               /* '<S3>/conversion3' */
  boolean_T conversion9;               /* '<S3>/conversion9' */
  boolean_T conversion10;              /* '<S3>/conversion10' */
} B_BasicTestModel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S2>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S3>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S2>/S-Function1' */
} DW_BasicTestModel_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T ZeroPole2_CSTATE[4];          /* '<S1>/Zero-Pole2' */
  real_T ZeroPole4_CSTATE[2];          /* '<S1>/Zero-Pole4' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE[2];        /* '<S1>/Transfer Fcn' */
  real_T ZeroPole1_CSTATE[2];          /* '<S1>/Zero-Pole1' */
} X_BasicTestModel_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T ZeroPole2_CSTATE[4];          /* '<S1>/Zero-Pole2' */
  real_T ZeroPole4_CSTATE[2];          /* '<S1>/Zero-Pole4' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE[2];        /* '<S1>/Transfer Fcn' */
  real_T ZeroPole1_CSTATE[2];          /* '<S1>/Zero-Pole1' */
} XDot_BasicTestModel_T;

/* State disabled  */
typedef struct {
  boolean_T ZeroPole2_CSTATE[4];       /* '<S1>/Zero-Pole2' */
  boolean_T ZeroPole4_CSTATE[2];       /* '<S1>/Zero-Pole4' */
  boolean_T TransferFcn1_CSTATE;       /* '<S1>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE[2];     /* '<S1>/Transfer Fcn' */
  boolean_T ZeroPole1_CSTATE[2];       /* '<S1>/Zero-Pole1' */
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
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S4>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_f;  /* Mask Parameter: DigitalOutput_pinNumber_f
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  real_T ZeroPole2_A[7];               /* Computed Parameter: ZeroPole2_A
                                        * Referenced by: '<S1>/Zero-Pole2'
                                        */
  real_T ZeroPole2_B[2];               /* Computed Parameter: ZeroPole2_B
                                        * Referenced by: '<S1>/Zero-Pole2'
                                        */
  real_T ZeroPole2_C[4];               /* Computed Parameter: ZeroPole2_C
                                        * Referenced by: '<S1>/Zero-Pole2'
                                        */
  real_T ZeroPole2_D;                  /* Computed Parameter: ZeroPole2_D
                                        * Referenced by: '<S1>/Zero-Pole2'
                                        */
  real_T ZeroPole4_A[2];               /* Computed Parameter: ZeroPole4_A
                                        * Referenced by: '<S1>/Zero-Pole4'
                                        */
  real_T ZeroPole4_B;                  /* Computed Parameter: ZeroPole4_B
                                        * Referenced by: '<S1>/Zero-Pole4'
                                        */
  real_T ZeroPole4_C[2];               /* Computed Parameter: ZeroPole4_C
                                        * Referenced by: '<S1>/Zero-Pole4'
                                        */
  real_T ZeroPole4_D;                  /* Computed Parameter: ZeroPole4_D
                                        * Referenced by: '<S1>/Zero-Pole4'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn_A[2];             /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_C[2];             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T ZeroPole1_A[2];               /* Computed Parameter: ZeroPole1_A
                                        * Referenced by: '<S1>/Zero-Pole1'
                                        */
  real_T ZeroPole1_B;                  /* Computed Parameter: ZeroPole1_B
                                        * Referenced by: '<S1>/Zero-Pole1'
                                        */
  real_T ZeroPole1_C[2];               /* Computed Parameter: ZeroPole1_C
                                        * Referenced by: '<S1>/Zero-Pole1'
                                        */
  real_T ZeroPole1_D;                  /* Computed Parameter: ZeroPole1_D
                                        * Referenced by: '<S1>/Zero-Pole1'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S3>/S-Function'
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
    real_T odeY[11];
    real_T odeF[3][11];
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
 * '<S1>'   : 'BasicTestModel/Good Old Controls'
 * '<S2>'   : 'BasicTestModel/PoliArd Init'
 * '<S3>'   : 'BasicTestModel/Transmission'
 * '<S4>'   : 'BasicTestModel/PoliArd Init/Digital Output1'
 * '<S5>'   : 'BasicTestModel/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_BasicTestModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
