/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: loop_shaping.h
 *
 * Code generated for Simulink model 'loop_shaping'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Apr 08 10:45:53 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_loop_shaping_h_
#define RTW_HEADER_loop_shaping_h_
#include <string.h>
#include <stddef.h>
#ifndef loop_shaping_COMMON_INCLUDES_
# define loop_shaping_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* loop_shaping_COMMON_INCLUDES_ */

#include "loop_shaping_types.h"

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
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real32_T conversion13;               /* '<S6>/conversion13' */
  real32_T conversion8;                /* '<S4>/conversion8' */
  real32_T SFunction1_o1;              /* '<S4>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S4>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S4>/S-Function1' */
  real32_T conversion2;                /* '<S6>/conversion2' */
  real32_T conversion4;                /* '<S6>/conversion4' */
  real32_T conversion5;                /* '<S6>/conversion5' */
  real32_T conversion6;                /* '<S6>/conversion6' */
  real32_T conversion7;                /* '<S6>/conversion7' */
  int32_T SFunction;                   /* '<S3>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S5>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S5>/S-Function2' */
  boolean_T conversion1;               /* '<S6>/conversion1' */
  boolean_T conversion3;               /* '<S6>/conversion3' */
  boolean_T conversion9;               /* '<S6>/conversion9' */
  boolean_T conversion10;              /* '<S6>/conversion10' */
  boolean_T SFunction_f;               /* '<S1>/S-Function' */
  boolean_T LogicalOperator;           /* '<S4>/Logical Operator' */
} B_loop_shaping_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S5>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S3>/S-Function' */
  real_T SFunction1_DSTATE;            /* '<S4>/S-Function1' */
  real_T SFunction_DSTATE_d;           /* '<S6>/S-Function' */
  real_T SFunction1_DSTATE_f;          /* '<S5>/S-Function1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_loop_shaping_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T ZeroPole1_CSTATE[2];          /* '<Root>/Zero-Pole1' */
} X_loop_shaping_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T ZeroPole1_CSTATE[2];          /* '<Root>/Zero-Pole1' */
} XDot_loop_shaping_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T ZeroPole1_CSTATE[2];       /* '<Root>/Zero-Pole1' */
} XDis_loop_shaping_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_loop_shaping_T_ {
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_e;  /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 300
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
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
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
  real_T Gain_Gain;                    /* Expression: 10
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint32_T SFunction_p1_p;             /* Computed Parameter: SFunction_p1_p
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S3>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S6>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_loop_shaping_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_loop_shaping_T *contStates;
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
extern P_loop_shaping_T loop_shaping_P;

/* Block signals (auto storage) */
extern B_loop_shaping_T loop_shaping_B;

/* Continuous states (auto storage) */
extern X_loop_shaping_T loop_shaping_X;

/* Block states (auto storage) */
extern DW_loop_shaping_T loop_shaping_DW;

/* External data declarations for dependent source files */
extern const boolean_T loop_shaping_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void loop_shaping_initialize(void);
extern void loop_shaping_output(void);
extern void loop_shaping_update(void);
extern void loop_shaping_terminate(void);

/* Real-time Model object */
extern RT_MODEL_loop_shaping_T *const loop_shaping_M;

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
 * '<Root>' : 'loop_shaping'
 * '<S1>'   : 'loop_shaping/Digital Input'
 * '<S2>'   : 'loop_shaping/Digital Input1'
 * '<S3>'   : 'loop_shaping/Encoder'
 * '<S4>'   : 'loop_shaping/Motor'
 * '<S5>'   : 'loop_shaping/PoliArd Init'
 * '<S6>'   : 'loop_shaping/Transmission'
 * '<S7>'   : 'loop_shaping/PoliArd Init/Digital Output1'
 * '<S8>'   : 'loop_shaping/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_loop_shaping_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
