/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: loop_shaping.c
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

#include "loop_shaping.h"
#include "loop_shaping_private.h"

const boolean_T loop_shaping_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_loop_shaping_T loop_shaping_B;

/* Continuous states */
X_loop_shaping_T loop_shaping_X;

/* Block states (auto storage) */
DW_loop_shaping_T loop_shaping_DW;

/* Real-time model */
RT_MODEL_loop_shaping_T loop_shaping_M_;
RT_MODEL_loop_shaping_T *const loop_shaping_M = &loop_shaping_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  loop_shaping_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  loop_shaping_output();
  loop_shaping_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  loop_shaping_output();
  loop_shaping_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void loop_shaping_output(void)
{
  boolean_T rtb_SFunction_0;
  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&loop_shaping_M->solverInfo,
                          ((loop_shaping_M->Timing.clockTick0+1)*
      loop_shaping_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(loop_shaping_M)) {
    loop_shaping_M->Timing.t[0] = rtsiGetT(&loop_shaping_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    /* S-Function (signals): '<S5>/S-Function2' */
    signals_Outputs_wrapper( &loop_shaping_B.SFunction2_o1,
      &loop_shaping_B.SFunction2_o2, &loop_shaping_DW.SFunction2_DSTATE);

    /* DataTypeConversion: '<S6>/conversion1' */
    loop_shaping_B.conversion1 = false;

    /* DataTypeConversion: '<S6>/conversion3' */
    loop_shaping_B.conversion3 = false;

    /* DataTypeConversion: '<S6>/conversion9' */
    loop_shaping_B.conversion9 = false;

    /* DataTypeConversion: '<S6>/conversion10' */
    loop_shaping_B.conversion10 = false;

    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    loop_shaping_B.PulseGenerator = (loop_shaping_DW.clockTickCounter <
      loop_shaping_P.PulseGenerator_Duty) && (loop_shaping_DW.clockTickCounter >=
      0) ? loop_shaping_P.PulseGenerator_Amp : 0.0;
    if (loop_shaping_DW.clockTickCounter >= loop_shaping_P.PulseGenerator_Period
        - 1.0) {
      loop_shaping_DW.clockTickCounter = 0;
    } else {
      loop_shaping_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* DataTypeConversion: '<S6>/conversion13' */
    loop_shaping_B.conversion13 = (real32_T)loop_shaping_B.PulseGenerator;
  }

  /* S-Function (arduinodigitalinput_sfcn): '<S1>/S-Function' */
  loop_shaping_B.SFunction_f = MW_digitalRead(loop_shaping_P.SFunction_p1);

  /* S-Function (sfcn_encoder): '<S3>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&loop_shaping_B.SFunction_f,
    &loop_shaping_B.SFunction, &loop_shaping_DW.SFunction_DSTATE,
    &loop_shaping_P.SFunction_P1_h, 1, &loop_shaping_P.Encoder_dt_enc, 1);

  /* Sum: '<Root>/Sum' */
  loop_shaping_B.Sum = loop_shaping_B.PulseGenerator - (real_T)
    loop_shaping_B.SFunction;

  /* DataTypeConversion: '<S4>/conversion8' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum2'
   *  TransferFcn: '<Root>/Transfer Fcn'
   *  ZeroPole: '<Root>/Zero-Pole1'
   */
  loop_shaping_B.conversion8 = (real32_T)((((loop_shaping_P.ZeroPole1_C[0] *
    loop_shaping_X.ZeroPole1_CSTATE[0] + loop_shaping_P.ZeroPole1_C[1] *
    loop_shaping_X.ZeroPole1_CSTATE[1]) + loop_shaping_P.ZeroPole1_D *
    loop_shaping_B.Sum) - loop_shaping_P.TransferFcn_C *
    loop_shaping_X.TransferFcn_CSTATE) * loop_shaping_P.Gain_Gain);

  /* S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function' */
  rtb_SFunction_0 = MW_digitalRead(loop_shaping_P.SFunction_p1_p);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function'
   */
  loop_shaping_B.LogicalOperator = (rtb_SFunction_0 &&
    loop_shaping_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S4>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&loop_shaping_B.conversion8,
    &loop_shaping_B.LogicalOperator, &loop_shaping_B.SFunction1_o1,
    &loop_shaping_B.SFunction1_o2, &loop_shaping_B.SFunction1_o3,
    &loop_shaping_DW.SFunction1_DSTATE, &loop_shaping_P.SFunction1_P1, 1,
    &loop_shaping_P.SFunction1_P2, 1, &loop_shaping_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    /* DataTypeConversion: '<S6>/conversion2' */
    loop_shaping_B.conversion2 = loop_shaping_B.SFunction1_o1;

    /* DataTypeConversion: '<S6>/conversion4' */
    loop_shaping_B.conversion4 = (real32_T)loop_shaping_B.SFunction;

    /* DataTypeConversion: '<S6>/conversion5' */
    loop_shaping_B.conversion5 = 0.0F;

    /* DataTypeConversion: '<S6>/conversion6' */
    loop_shaping_B.conversion6 = 0.0F;

    /* DataTypeConversion: '<S6>/conversion7' */
    loop_shaping_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S6>/S-Function' */
    SerialTx_Outputs_wrapper(&loop_shaping_B.SFunction2_o1, (boolean_T*)
      &loop_shaping_BGND, (boolean_T*)&loop_shaping_BGND, (boolean_T*)
      &loop_shaping_BGND, &loop_shaping_B.conversion1,
      &loop_shaping_B.conversion3, &loop_shaping_B.conversion9,
      &loop_shaping_B.conversion10, &loop_shaping_B.conversion13,
      &loop_shaping_B.conversion2, &loop_shaping_B.conversion4,
      &loop_shaping_B.conversion5, &loop_shaping_B.conversion6,
      &loop_shaping_B.conversion7, &loop_shaping_DW.SFunction_DSTATE_d,
      &loop_shaping_P.SFunction_P1, 1, &loop_shaping_P.SFunction_P2, 1);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  loop_shaping_B.DataTypeConversion = loop_shaping_B.SFunction1_o1;
  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     */
    MW_digitalWrite(loop_shaping_P.DigitalOutput_pinNumber, (uint8_T)
                    loop_shaping_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     */
    MW_digitalWrite(loop_shaping_P.DigitalOutput_pinNumber_e, (uint8_T)
                    loop_shaping_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S5>/S-Function1' */
    data_struct_init_Outputs_wrapper( &loop_shaping_DW.SFunction1_DSTATE_f);
  }
}

/* Model update function */
void loop_shaping_update(void)
{
  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    /* S-Function "signals_wrapper" Block: <S5>/S-Function2 */
    signals_Update_wrapper( &loop_shaping_B.SFunction2_o1,
      &loop_shaping_B.SFunction2_o2, &loop_shaping_DW.SFunction2_DSTATE);
  }

  /* S-Function "sfcn_encoder_wrapper" Block: <S3>/S-Function */
  sfcn_encoder_Update_wrapper(&loop_shaping_B.SFunction_f,
    &loop_shaping_B.SFunction, &loop_shaping_DW.SFunction_DSTATE,
    &loop_shaping_P.SFunction_P1_h, 1, &loop_shaping_P.Encoder_dt_enc, 1);

  /* S-Function "sfcn_motor_new_wrapper" Block: <S4>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&loop_shaping_B.conversion8,
    &loop_shaping_B.LogicalOperator, &loop_shaping_B.SFunction1_o1,
    &loop_shaping_B.SFunction1_o2, &loop_shaping_B.SFunction1_o3,
    &loop_shaping_DW.SFunction1_DSTATE, &loop_shaping_P.SFunction1_P1, 1,
    &loop_shaping_P.SFunction1_P2, 1, &loop_shaping_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
    SerialTx_Update_wrapper(&loop_shaping_B.SFunction2_o1, (boolean_T*)
      &loop_shaping_BGND, (boolean_T*)&loop_shaping_BGND, (boolean_T*)
      &loop_shaping_BGND, &loop_shaping_B.conversion1,
      &loop_shaping_B.conversion3, &loop_shaping_B.conversion9,
      &loop_shaping_B.conversion10, &loop_shaping_B.conversion13,
      &loop_shaping_B.conversion2, &loop_shaping_B.conversion4,
      &loop_shaping_B.conversion5, &loop_shaping_B.conversion6,
      &loop_shaping_B.conversion7, &loop_shaping_DW.SFunction_DSTATE_d,
      &loop_shaping_P.SFunction_P1, 1, &loop_shaping_P.SFunction_P2, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S5>/S-Function1 */
    data_struct_init_Update_wrapper(&loop_shaping_DW.SFunction1_DSTATE_f);
  }

  if (rtmIsMajorTimeStep(loop_shaping_M)) {
    rt_ertODEUpdateContinuousStates(&loop_shaping_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++loop_shaping_M->Timing.clockTick0;
  loop_shaping_M->Timing.t[0] = rtsiGetSolverStopTime
    (&loop_shaping_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    loop_shaping_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void loop_shaping_derivatives(void)
{
  XDot_loop_shaping_T *_rtXdot;
  _rtXdot = ((XDot_loop_shaping_T *) loop_shaping_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += loop_shaping_P.TransferFcn_A *
    loop_shaping_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += loop_shaping_B.DataTypeConversion;

  /* Derivatives for ZeroPole: '<Root>/Zero-Pole1' */
  _rtXdot->ZeroPole1_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole1_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole1_CSTATE[0] += loop_shaping_P.ZeroPole1_A[0] *
    loop_shaping_X.ZeroPole1_CSTATE[0];
  _rtXdot->ZeroPole1_CSTATE[1] += loop_shaping_P.ZeroPole1_A[1] *
    loop_shaping_X.ZeroPole1_CSTATE[0];
  _rtXdot->ZeroPole1_CSTATE[0] += loop_shaping_P.ZeroPole1_B *
    loop_shaping_B.Sum;
}

/* Model initialize function */
void loop_shaping_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)loop_shaping_M, 0,
                sizeof(RT_MODEL_loop_shaping_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&loop_shaping_M->solverInfo,
                          &loop_shaping_M->Timing.simTimeStep);
    rtsiSetTPtr(&loop_shaping_M->solverInfo, &rtmGetTPtr(loop_shaping_M));
    rtsiSetStepSizePtr(&loop_shaping_M->solverInfo,
                       &loop_shaping_M->Timing.stepSize0);
    rtsiSetdXPtr(&loop_shaping_M->solverInfo, &loop_shaping_M->ModelData.derivs);
    rtsiSetContStatesPtr(&loop_shaping_M->solverInfo, (real_T **)
                         &loop_shaping_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&loop_shaping_M->solverInfo,
      &loop_shaping_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&loop_shaping_M->solverInfo, (&rtmGetErrorStatus
      (loop_shaping_M)));
    rtsiSetRTModelPtr(&loop_shaping_M->solverInfo, loop_shaping_M);
  }

  rtsiSetSimTimeStep(&loop_shaping_M->solverInfo, MAJOR_TIME_STEP);
  loop_shaping_M->ModelData.intgData.y = loop_shaping_M->ModelData.odeY;
  loop_shaping_M->ModelData.intgData.f[0] = loop_shaping_M->ModelData.odeF[0];
  loop_shaping_M->ModelData.intgData.f[1] = loop_shaping_M->ModelData.odeF[1];
  loop_shaping_M->ModelData.intgData.f[2] = loop_shaping_M->ModelData.odeF[2];
  loop_shaping_M->ModelData.contStates = ((X_loop_shaping_T *) &loop_shaping_X);
  rtsiSetSolverData(&loop_shaping_M->solverInfo, (void *)
                    &loop_shaping_M->ModelData.intgData);
  rtsiSetSolverName(&loop_shaping_M->solverInfo,"ode3");
  rtmSetTPtr(loop_shaping_M, &loop_shaping_M->Timing.tArray[0]);
  loop_shaping_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &loop_shaping_B), 0,
                sizeof(B_loop_shaping_T));

  /* states (continuous) */
  {
    (void) memset((void *)&loop_shaping_X, 0,
                  sizeof(X_loop_shaping_T));
  }

  /* states (dwork) */
  (void) memset((void *)&loop_shaping_DW, 0,
                sizeof(DW_loop_shaping_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  loop_shaping_DW.clockTickCounter = 0;

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S1>/S-Function' */
  MW_pinModeInput(loop_shaping_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function' */
  MW_pinModeInput(loop_shaping_P.SFunction_p1_p);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' */
  MW_pinModeOutput(loop_shaping_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_pinModeOutput(loop_shaping_P.DigitalOutput_pinNumber_e);

  /* S-Function Block: <S5>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        loop_shaping_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  loop_shaping_X.TransferFcn_CSTATE = 0.0;

  /* S-Function Block: <S3>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        loop_shaping_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for ZeroPole: '<Root>/Zero-Pole1' */
  loop_shaping_X.ZeroPole1_CSTATE[0] = 0.0;
  loop_shaping_X.ZeroPole1_CSTATE[1] = 0.0;

  /* S-Function Block: <S4>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        loop_shaping_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        loop_shaping_DW.SFunction_DSTATE_d = initVector[0];
      }
    }
  }

  /* S-Function Block: <S5>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        loop_shaping_DW.SFunction1_DSTATE_f = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void loop_shaping_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
