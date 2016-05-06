/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BasicTestModel.c
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

#include "BasicTestModel.h"
#include "BasicTestModel_private.h"

const boolean_T BasicTestModel_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_BasicTestModel_T BasicTestModel_B;

/* Continuous states */
X_BasicTestModel_T BasicTestModel_X;

/* Block states (auto storage) */
DW_BasicTestModel_T BasicTestModel_DW;

/* Real-time model */
RT_MODEL_BasicTestModel_T BasicTestModel_M_;
RT_MODEL_BasicTestModel_T *const BasicTestModel_M = &BasicTestModel_M_;

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
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  BasicTestModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  BasicTestModel_output();
  BasicTestModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  BasicTestModel_output();
  BasicTestModel_derivatives();

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
void BasicTestModel_output(void)
{
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&BasicTestModel_M->solverInfo,
                          ((BasicTestModel_M->Timing.clockTick0+1)*
      BasicTestModel_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BasicTestModel_M)) {
    BasicTestModel_M->Timing.t[0] = rtsiGetT(&BasicTestModel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* S-Function (signals): '<S2>/S-Function2' */
    signals_Outputs_wrapper( &BasicTestModel_B.SFunction2_o1,
      &BasicTestModel_B.SFunction2_o2, &BasicTestModel_DW.SFunction2_DSTATE);

    /* DataTypeConversion: '<S3>/conversion1' */
    BasicTestModel_B.conversion1 = false;

    /* DataTypeConversion: '<S3>/conversion3' */
    BasicTestModel_B.conversion3 = false;

    /* DataTypeConversion: '<S3>/conversion9' */
    BasicTestModel_B.conversion9 = false;

    /* DataTypeConversion: '<S3>/conversion10' */
    BasicTestModel_B.conversion10 = false;

    /* DataTypeConversion: '<S3>/conversion13' */
    BasicTestModel_B.conversion13 = 0.0F;

    /* DataTypeConversion: '<S3>/conversion2' */
    BasicTestModel_B.conversion2 = 0.0F;

    /* DataTypeConversion: '<S3>/conversion4' */
    BasicTestModel_B.conversion4 = 0.0F;

    /* DataTypeConversion: '<S3>/conversion5' */
    BasicTestModel_B.conversion5 = 0.0F;

    /* DataTypeConversion: '<S3>/conversion6' */
    BasicTestModel_B.conversion6 = 0.0F;

    /* DataTypeConversion: '<S3>/conversion7' */
    BasicTestModel_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S3>/S-Function' */
    SerialTx_Outputs_wrapper(&BasicTestModel_B.SFunction2_o1, (boolean_T*)
      &BasicTestModel_BGND, (boolean_T*)&BasicTestModel_BGND, (boolean_T*)
      &BasicTestModel_BGND, &BasicTestModel_B.conversion1,
      &BasicTestModel_B.conversion3, &BasicTestModel_B.conversion9,
      &BasicTestModel_B.conversion10, &BasicTestModel_B.conversion13,
      &BasicTestModel_B.conversion2, &BasicTestModel_B.conversion4,
      &BasicTestModel_B.conversion5, &BasicTestModel_B.conversion6,
      &BasicTestModel_B.conversion7, &BasicTestModel_DW.SFunction_DSTATE,
      &BasicTestModel_P.SFunction_P1, 1, &BasicTestModel_P.SFunction_P2, 1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     */
    MW_digitalWrite(BasicTestModel_P.DigitalOutput_pinNumber, (uint8_T)
                    BasicTestModel_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     */
    MW_digitalWrite(BasicTestModel_P.DigitalOutput_pinNumber_f, (uint8_T)
                    BasicTestModel_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S2>/S-Function1' */
    data_struct_init_Outputs_wrapper( &BasicTestModel_DW.SFunction1_DSTATE);
  }
}

/* Model update function */
void BasicTestModel_update(void)
{
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* S-Function "signals_wrapper" Block: <S2>/S-Function2 */
    signals_Update_wrapper( &BasicTestModel_B.SFunction2_o1,
      &BasicTestModel_B.SFunction2_o2, &BasicTestModel_DW.SFunction2_DSTATE);

    /* S-Function "SerialTx_wrapper" Block: <S3>/S-Function */
    SerialTx_Update_wrapper(&BasicTestModel_B.SFunction2_o1, (boolean_T*)
      &BasicTestModel_BGND, (boolean_T*)&BasicTestModel_BGND, (boolean_T*)
      &BasicTestModel_BGND, &BasicTestModel_B.conversion1,
      &BasicTestModel_B.conversion3, &BasicTestModel_B.conversion9,
      &BasicTestModel_B.conversion10, &BasicTestModel_B.conversion13,
      &BasicTestModel_B.conversion2, &BasicTestModel_B.conversion4,
      &BasicTestModel_B.conversion5, &BasicTestModel_B.conversion6,
      &BasicTestModel_B.conversion7, &BasicTestModel_DW.SFunction_DSTATE,
      &BasicTestModel_P.SFunction_P1, 1, &BasicTestModel_P.SFunction_P2, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S2>/S-Function1 */
    data_struct_init_Update_wrapper(&BasicTestModel_DW.SFunction1_DSTATE);
  }

  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    rt_ertODEUpdateContinuousStates(&BasicTestModel_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++BasicTestModel_M->Timing.clockTick0;
  BasicTestModel_M->Timing.t[0] = rtsiGetSolverStopTime
    (&BasicTestModel_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    BasicTestModel_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void BasicTestModel_derivatives(void)
{
  XDot_BasicTestModel_T *_rtXdot;
  _rtXdot = ((XDot_BasicTestModel_T *) BasicTestModel_M->ModelData.derivs);

  /* Derivatives for ZeroPole: '<S1>/Zero-Pole2' */
  _rtXdot->ZeroPole2_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole2_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole2_CSTATE[2] = 0.0;
  _rtXdot->ZeroPole2_CSTATE[3] = 0.0;
  _rtXdot->ZeroPole2_CSTATE[0] += BasicTestModel_P.ZeroPole2_A[0] *
    BasicTestModel_X.ZeroPole2_CSTATE[0];
  _rtXdot->ZeroPole2_CSTATE[0] += BasicTestModel_P.ZeroPole2_A[1] *
    BasicTestModel_X.ZeroPole2_CSTATE[1];
  _rtXdot->ZeroPole2_CSTATE[1] += BasicTestModel_P.ZeroPole2_A[2] *
    BasicTestModel_X.ZeroPole2_CSTATE[0];
  _rtXdot->ZeroPole2_CSTATE[2] += BasicTestModel_P.ZeroPole2_A[3] *
    BasicTestModel_X.ZeroPole2_CSTATE[0];
  _rtXdot->ZeroPole2_CSTATE[2] += BasicTestModel_P.ZeroPole2_A[4] *
    BasicTestModel_X.ZeroPole2_CSTATE[1];
  _rtXdot->ZeroPole2_CSTATE[2] += BasicTestModel_P.ZeroPole2_A[5] *
    BasicTestModel_X.ZeroPole2_CSTATE[2];
  _rtXdot->ZeroPole2_CSTATE[3] += BasicTestModel_P.ZeroPole2_A[6] *
    BasicTestModel_X.ZeroPole2_CSTATE[2];
  _rtXdot->ZeroPole2_CSTATE[0] += BasicTestModel_P.ZeroPole2_B[0] * 0.0;
  _rtXdot->ZeroPole2_CSTATE[2] += BasicTestModel_P.ZeroPole2_B[1] * 0.0;

  /* Derivatives for ZeroPole: '<S1>/Zero-Pole4' */
  _rtXdot->ZeroPole4_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole4_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole4_CSTATE[0] += BasicTestModel_P.ZeroPole4_A[0] *
    BasicTestModel_X.ZeroPole4_CSTATE[0];
  _rtXdot->ZeroPole4_CSTATE[1] += BasicTestModel_P.ZeroPole4_A[1] *
    BasicTestModel_X.ZeroPole4_CSTATE[0];
  _rtXdot->ZeroPole4_CSTATE[0] += BasicTestModel_P.ZeroPole4_B * 0.0;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += BasicTestModel_P.TransferFcn1_A *
    BasicTestModel_X.TransferFcn1_CSTATE;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += BasicTestModel_P.TransferFcn_A[0] *
    BasicTestModel_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += BasicTestModel_P.TransferFcn_A[1] *
    BasicTestModel_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += BasicTestModel_X.TransferFcn_CSTATE[0];

  /* Derivatives for ZeroPole: '<S1>/Zero-Pole1' */
  _rtXdot->ZeroPole1_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole1_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole1_CSTATE[0] += BasicTestModel_P.ZeroPole1_A[0] *
    BasicTestModel_X.ZeroPole1_CSTATE[0];
  _rtXdot->ZeroPole1_CSTATE[1] += BasicTestModel_P.ZeroPole1_A[1] *
    BasicTestModel_X.ZeroPole1_CSTATE[0];
  _rtXdot->ZeroPole1_CSTATE[0] += BasicTestModel_P.ZeroPole1_B * 0.0;
}

/* Model initialize function */
void BasicTestModel_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BasicTestModel_M, 0,
                sizeof(RT_MODEL_BasicTestModel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BasicTestModel_M->solverInfo,
                          &BasicTestModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&BasicTestModel_M->solverInfo, &rtmGetTPtr(BasicTestModel_M));
    rtsiSetStepSizePtr(&BasicTestModel_M->solverInfo,
                       &BasicTestModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&BasicTestModel_M->solverInfo,
                 &BasicTestModel_M->ModelData.derivs);
    rtsiSetContStatesPtr(&BasicTestModel_M->solverInfo, (real_T **)
                         &BasicTestModel_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&BasicTestModel_M->solverInfo,
      &BasicTestModel_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&BasicTestModel_M->solverInfo, (&rtmGetErrorStatus
      (BasicTestModel_M)));
    rtsiSetRTModelPtr(&BasicTestModel_M->solverInfo, BasicTestModel_M);
  }

  rtsiSetSimTimeStep(&BasicTestModel_M->solverInfo, MAJOR_TIME_STEP);
  BasicTestModel_M->ModelData.intgData.y = BasicTestModel_M->ModelData.odeY;
  BasicTestModel_M->ModelData.intgData.f[0] = BasicTestModel_M->ModelData.odeF[0];
  BasicTestModel_M->ModelData.intgData.f[1] = BasicTestModel_M->ModelData.odeF[1];
  BasicTestModel_M->ModelData.intgData.f[2] = BasicTestModel_M->ModelData.odeF[2];
  BasicTestModel_M->ModelData.contStates = ((X_BasicTestModel_T *)
    &BasicTestModel_X);
  rtsiSetSolverData(&BasicTestModel_M->solverInfo, (void *)
                    &BasicTestModel_M->ModelData.intgData);
  rtsiSetSolverName(&BasicTestModel_M->solverInfo,"ode3");
  rtmSetTPtr(BasicTestModel_M, &BasicTestModel_M->Timing.tArray[0]);
  BasicTestModel_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &BasicTestModel_B), 0,
                sizeof(B_BasicTestModel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&BasicTestModel_X, 0,
                  sizeof(X_BasicTestModel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&BasicTestModel_DW, 0,
                sizeof(DW_BasicTestModel_T));

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_pinModeOutput(BasicTestModel_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
  MW_pinModeOutput(BasicTestModel_P.DigitalOutput_pinNumber_f);

  /* InitializeConditions for ZeroPole: '<S1>/Zero-Pole2' */
  BasicTestModel_X.ZeroPole2_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole2_CSTATE[1] = 0.0;
  BasicTestModel_X.ZeroPole2_CSTATE[2] = 0.0;
  BasicTestModel_X.ZeroPole2_CSTATE[3] = 0.0;

  /* InitializeConditions for ZeroPole: '<S1>/Zero-Pole4' */
  BasicTestModel_X.ZeroPole4_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole4_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn1' */
  BasicTestModel_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  BasicTestModel_X.TransferFcn_CSTATE[0] = 0.0;
  BasicTestModel_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for ZeroPole: '<S1>/Zero-Pole1' */
  BasicTestModel_X.ZeroPole1_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole1_CSTATE[1] = 0.0;

  /* S-Function Block: <S2>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S2>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void BasicTestModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
