/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: porcoilclero.h
 *
 * Code generated for Simulink model 'porcoilclero'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:44:14 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_porcoilclero_h_
#define RTW_HEADER_porcoilclero_h_
#include <string.h>
#include <stddef.h>
#ifndef porcoilclero_COMMON_INCLUDES_
# define porcoilclero_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* porcoilclero_COMMON_INCLUDES_ */

#include "porcoilclero_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

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
  real_T Memory;                       /* '<S4>/Memory' */
  real_T Product;                      /* '<S1>/Product' */
  real_T Memory_i;                     /* '<S2>/Memory' */
  real_T Gain[2];                      /* '<S2>/Gain' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Memory2[2];                   /* '<S2>/Memory2' */
  real_T Memory3;                      /* '<S2>/Memory3' */
  real_T Product4;                     /* '<S2>/Product4' */
  real_T Gain1[2];                     /* '<S13>/Gain1' */
  real_T Add[2];                       /* '<S13>/Add' */
  real_T Gain_b;                       /* '<S4>/Gain' */
  real_T MD;                           /* '<S1>/Chart' */
  real_T ER;                           /* '<S1>/Chart' */
  real32_T conversion13;               /* '<S5>/conversion13' */
  real32_T conversion2;                /* '<S5>/conversion2' */
  real32_T conversion8;                /* '<S21>/conversion8' */
  real32_T SFunction1_o1;              /* '<S21>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S21>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S21>/S-Function1' */
  real32_T conversion4;                /* '<S5>/conversion4' */
  real32_T conversion5;                /* '<S5>/conversion5' */
  real32_T conversion6;                /* '<S5>/conversion6' */
  real32_T conversion7;                /* '<S5>/conversion7' */
  int32_T SFunction;                   /* '<S19>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S3>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S3>/S-Function2' */
  boolean_T conversion1;               /* '<S5>/conversion1' */
  boolean_T conversion3;               /* '<S5>/conversion3' */
  boolean_T conversion9;               /* '<S5>/conversion9' */
  boolean_T conversion10;              /* '<S5>/conversion10' */
  boolean_T LogicalOperator;           /* '<S21>/Logical Operator' */
  boolean_T LogicalOperator_g;         /* '<S16>/Logical Operator' */
} B_porcoilclero_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S3>/S-Function2' */
  real_T DelayInput1_DSTATE;           /* '<S7>/Delay Input1' */
  real_T SFunction1_DSTATE;            /* '<S21>/S-Function1' */
  real_T SFunction_DSTATE;             /* '<S5>/S-Function' */
  real_T SFunction_DSTATE_m;           /* '<S19>/S-Function' */
  real_T SFunction1_DSTATE_g;          /* '<S3>/S-Function1' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T Memory_PreviousInput;         /* '<S4>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S1>/Memory1' */
  real_T Memory_PreviousInput_o;       /* '<S2>/Memory' */
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S4>/Derivative' */
  real_T Memory2_PreviousInput_b[2];   /* '<S2>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S2>/Memory3' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint8_T is_active_c3_porcoilclero;   /* '<S1>/Chart' */
  uint8_T is_c3_porcoilclero;          /* '<S1>/Chart' */
} DW_porcoilclero_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator_CSTATE[2];         /* '<S13>/Integrator' */
  real_T Integrator1_CSTATE[2];        /* '<S2>/Integrator1' */
  real_T ZeroPole_CSTATE[2];           /* '<S4>/Zero-Pole' */
} X_porcoilclero_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator_CSTATE[2];         /* '<S13>/Integrator' */
  real_T Integrator1_CSTATE[2];        /* '<S2>/Integrator1' */
  real_T ZeroPole_CSTATE[2];           /* '<S4>/Zero-Pole' */
} XDot_porcoilclero_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator4_CSTATE;        /* '<S2>/Integrator4' */
  boolean_T Integrator_CSTATE[2];      /* '<S13>/Integrator' */
  boolean_T Integrator1_CSTATE[2];     /* '<S2>/Integrator1' */
  boolean_T ZeroPole_CSTATE[2];        /* '<S4>/Zero-Pole' */
} XDis_porcoilclero_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_porcoilclero_T_ {
  real_T Aref[4];                      /* Variable: Aref
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Bref[2];                      /* Variable: Bref
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T GammaR;                       /* Variable: GammaR
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T GammaX[4];                    /* Variable: GammaX
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T UpperThreshold_const;         /* Mask Parameter: UpperThreshold_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T LowerThreshold_const;         /* Mask Parameter: LowerThreshold_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Encoder_dt_enc;               /* Mask Parameter: Encoder_dt_enc
                                        * Referenced by: '<S19>/S-Function'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_i;  /* Mask Parameter: DigitalOutput_pinNumber_i
                                        * Referenced by: '<S15>/Digital Output'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T encodertocm_Gain;             /* Expression: 1/560
                                        * Referenced by: '<S8>/encoder-to-cm'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator4'
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
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T Memory_X0_i;                  /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -5
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S5>/S-Function'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Constant_Value[2];            /* Expression: P*B
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S2>/Memory3'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/560
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T ZeroPole_A[3];                /* Computed Parameter: ZeroPole_A
                                        * Referenced by: '<S4>/Zero-Pole'
                                        */
  real_T ZeroPole_B;                   /* Computed Parameter: ZeroPole_B
                                        * Referenced by: '<S4>/Zero-Pole'
                                        */
  real_T ZeroPole_C;                   /* Computed Parameter: ZeroPole_C
                                        * Referenced by: '<S4>/Zero-Pole'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S20>/S-Function'
                                        */
  uint32_T SFunction_p1_o;             /* Computed Parameter: SFunction_p1_o
                                        * Referenced by: '<S18>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S5>/S-Function'
                                        */
  uint8_T SFunction_P1_g;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S19>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_porcoilclero_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_porcoilclero_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[7];
    real_T odeF[3][7];
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
extern P_porcoilclero_T porcoilclero_P;

/* Block signals (auto storage) */
extern B_porcoilclero_T porcoilclero_B;

/* Continuous states (auto storage) */
extern X_porcoilclero_T porcoilclero_X;

/* Block states (auto storage) */
extern DW_porcoilclero_T porcoilclero_DW;

/* External data declarations for dependent source files */
extern const boolean_T porcoilclero_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void porcoilclero_initialize(void);
extern void porcoilclero_output(void);
extern void porcoilclero_update(void);
extern void porcoilclero_terminate(void);

/* Real-time Model object */
extern RT_MODEL_porcoilclero_T *const porcoilclero_M;

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
 * '<Root>' : 'porcoilclero'
 * '<S1>'   : 'porcoilclero/Condom'
 * '<S2>'   : 'porcoilclero/Controller'
 * '<S3>'   : 'porcoilclero/PoliArd Init'
 * '<S4>'   : 'porcoilclero/System '
 * '<S5>'   : 'porcoilclero/Transmission'
 * '<S6>'   : 'porcoilclero/Condom/Chart'
 * '<S7>'   : 'porcoilclero/Condom/Detect Change'
 * '<S8>'   : 'porcoilclero/Condom/Ovrshoot Travel Protection'
 * '<S9>'   : 'porcoilclero/Condom/Reference Overshoot'
 * '<S10>'  : 'porcoilclero/Condom/Voltage Protection'
 * '<S11>'  : 'porcoilclero/Condom/Ovrshoot Travel Protection/Lower Threshold'
 * '<S12>'  : 'porcoilclero/Condom/Ovrshoot Travel Protection/Upper Threshold'
 * '<S13>'  : 'porcoilclero/Controller/Ref sys'
 * '<S14>'  : 'porcoilclero/PoliArd Init/Digital Output1'
 * '<S15>'  : 'porcoilclero/PoliArd Init/Digital Output3'
 * '<S16>'  : 'porcoilclero/System /Encoder '
 * '<S17>'  : 'porcoilclero/System /Motor'
 * '<S18>'  : 'porcoilclero/System /Encoder /Digital Input'
 * '<S19>'  : 'porcoilclero/System /Encoder /Encoder'
 * '<S20>'  : 'porcoilclero/System /Motor/Digital Input1'
 * '<S21>'  : 'porcoilclero/System /Motor/Motor'
 */
#endif                                 /* RTW_HEADER_porcoilclero_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
