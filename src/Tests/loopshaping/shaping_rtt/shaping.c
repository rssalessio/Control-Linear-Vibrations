/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: shaping.c
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

#include "shaping.h"
#include "shaping_private.h"

const boolean_T shaping_BGND = false;  /* boolean_T ground */

/* Block signals (auto storage) */
B_shaping_T shaping_B;

/* Continuous states */
X_shaping_T shaping_X;

/* Block states (auto storage) */
DW_shaping_T shaping_DW;

/* Real-time model */
RT_MODEL_shaping_T shaping_M_;
RT_MODEL_shaping_T *const shaping_M = &shaping_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  shaping_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  shaping_output();
  shaping_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  shaping_output();
  shaping_derivatives();

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
void shaping_output(void)
{
  boolean_T rtb_SFunction_0;
  real_T rtb_Saturation;
  if (rtmIsMajorTimeStep(shaping_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&shaping_M->solverInfo,((shaping_M->Timing.clockTick0+
      1)*shaping_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(shaping_M)) {
    shaping_M->Timing.t[0] = rtsiGetT(&shaping_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(shaping_M)) {
    /* S-Function (signals): '<S3>/S-Function2' */
    signals_Outputs_wrapper( &shaping_B.SFunction2_o1, &shaping_B.SFunction2_o2,
      &shaping_DW.SFunction2_DSTATE);

    /* Logic: '<S1>/Logical Operator' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S9>/Constant'
     *  Logic: '<S6>/Logical Operator'
     *  Logic: '<S7>/Logical Operator'
     *  Memory: '<S1>/Memory'
     *  Memory: '<S1>/Memory1'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S9>/Compare'
     */
    shaping_B.LogicalOperator = ((shaping_DW.Memory_PreviousInput >=
      shaping_P.UpperThreshold_const) || (shaping_DW.Memory_PreviousInput <=
      shaping_P.LowerThreshold_const) || ((shaping_DW.Memory1_PreviousInput >=
      shaping_P.UpperThreshold_const_e) || (shaping_DW.Memory1_PreviousInput <=
      shaping_P.LowerThreshold_const_f)));

    /* DataTypeConversion: '<S5>/conversion3' */
    shaping_B.conversion3 = false;

    /* DataTypeConversion: '<S5>/conversion9' */
    shaping_B.conversion9 = false;

    /* DataTypeConversion: '<S5>/conversion10' */
    shaping_B.conversion10 = false;

    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    rtb_Saturation = (shaping_DW.clockTickCounter <
                      shaping_P.PulseGenerator_Duty) &&
      (shaping_DW.clockTickCounter >= 0) ? shaping_P.PulseGenerator_Amp : 0.0;
    if (shaping_DW.clockTickCounter >= shaping_P.PulseGenerator_Period - 1.0) {
      shaping_DW.clockTickCounter = 0;
    } else {
      shaping_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Saturate: '<S8>/Saturation' */
    if (rtb_Saturation > shaping_P.Saturation_UpperSat) {
      rtb_Saturation = shaping_P.Saturation_UpperSat;
    } else {
      if (rtb_Saturation < shaping_P.Saturation_LowerSat) {
        rtb_Saturation = shaping_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S8>/Saturation' */

    /* DataTypeConversion: '<S5>/conversion13' */
    shaping_B.conversion13 = (real32_T)rtb_Saturation;

    /* S-Function (arduinodigitalinput_sfcn): '<S17>/S-Function' */
    shaping_B.SFunction_d = MW_digitalRead(shaping_P.SFunction_p1);

    /* S-Function (sfcn_encoder): '<S18>/S-Function' */
    sfcn_encoder_Outputs_wrapper(&shaping_B.SFunction_d, &shaping_B.SFunction,
      &shaping_DW.SFunction_DSTATE, &shaping_P.SFunction_P1_d, 1,
      &shaping_P.Encoder_dt_enc, 1);

    /* Sum: '<S4>/Sum' incorporates:
     *  Gain: '<S4>/cm-to-encoder'
     */
    shaping_B.Sum = shaping_P.cmtoencoder_Gain * rtb_Saturation - (real_T)
      shaping_B.SFunction;
  }

  /* ZeroPole: '<S2>/loopshaping' */
  shaping_B.loopshaping = 0.0;
  shaping_B.loopshaping += shaping_P.loopshaping_C[0] *
    shaping_X.loopshaping_CSTATE[0];
  shaping_B.loopshaping += shaping_P.loopshaping_C[1] *
    shaping_X.loopshaping_CSTATE[1];
  shaping_B.loopshaping += shaping_P.loopshaping_D * shaping_B.Sum;
  if (rtmIsMajorTimeStep(shaping_M)) {
    /* DataTypeConversion: '<S5>/conversion2' */
    shaping_B.conversion2 = (real32_T)shaping_B.loopshaping;
  }

  /* DataTypeConversion: '<S20>/conversion8' */
  shaping_B.conversion8 = (real32_T)shaping_B.loopshaping;
  if (rtmIsMajorTimeStep(shaping_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S19>/S-Function' */
    rtb_SFunction_0 = MW_digitalRead(shaping_P.SFunction_p1_d);

    /* Logic: '<S20>/Logical Operator' incorporates:
     *  Logic: '<Root>/Logical Operator'
     *  Logic: '<S16>/Logical Operator'
     *  S-Function (arduinodigitalinput_sfcn): '<S19>/S-Function'
     */
    shaping_B.LogicalOperator_n = (rtb_SFunction_0 &&
      (!shaping_B.LogicalOperator) && shaping_B.SFunction2_o1);
  }

  /* S-Function (sfcn_motor_new): '<S20>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&shaping_B.conversion8,
    &shaping_B.LogicalOperator_n, &shaping_B.SFunction1_o1,
    &shaping_B.SFunction1_o2, &shaping_B.SFunction1_o3,
    &shaping_DW.SFunction1_DSTATE, &shaping_P.SFunction1_P1, 1,
    &shaping_P.SFunction1_P2, 1, &shaping_P.SFunction1_P3, 1);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  shaping_B.DataTypeConversion1 = shaping_B.SFunction1_o1;
  if (rtmIsMajorTimeStep(shaping_M)) {
    /* DataTypeConversion: '<S5>/conversion4' */
    shaping_B.conversion4 = (real32_T)shaping_B.DataTypeConversion1;

    /* DataTypeConversion: '<S5>/conversion5' */
    shaping_B.conversion5 = (real32_T)shaping_B.SFunction;

    /* DataTypeConversion: '<S5>/conversion6' incorporates:
     *  Constant: '<Root>/Constant'
     */
    shaping_B.conversion6 = (real32_T)shaping_P.Constant_Value;

    /* DataTypeConversion: '<S5>/conversion7' */
    shaping_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S5>/S-Function' */
    SerialTx_Outputs_wrapper(&shaping_B.SFunction2_o1, (boolean_T*)&shaping_BGND,
      (boolean_T*)&shaping_BGND, (boolean_T*)&shaping_BGND,
      &shaping_B.LogicalOperator, &shaping_B.conversion3, &shaping_B.conversion9,
      &shaping_B.conversion10, &shaping_B.conversion13, &shaping_B.conversion2,
      &shaping_B.conversion4, &shaping_B.conversion5, &shaping_B.conversion6,
      &shaping_B.conversion7, &shaping_DW.SFunction_DSTATE_l,
      &shaping_P.SFunction_P1, 1, &shaping_P.SFunction_P2, 1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     */
    MW_digitalWrite(shaping_P.DigitalOutput_pinNumber, (uint8_T)
                    shaping_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion'
     */
    MW_digitalWrite(shaping_P.DigitalOutput_pinNumber_l, (uint8_T)
                    shaping_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &shaping_DW.SFunction1_DSTATE_b);
  }
}

/* Model update function */
void shaping_update(void)
{
  if (rtmIsMajorTimeStep(shaping_M)) {
    /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
    signals_Update_wrapper( &shaping_B.SFunction2_o1, &shaping_B.SFunction2_o2,
      &shaping_DW.SFunction2_DSTATE);

    /* Update for Memory: '<S1>/Memory' */
    shaping_DW.Memory_PreviousInput = shaping_B.DataTypeConversion1;

    /* Update for Memory: '<S1>/Memory1' */
    shaping_DW.Memory1_PreviousInput = shaping_B.loopshaping;

    /* S-Function "sfcn_encoder_wrapper" Block: <S18>/S-Function */
    sfcn_encoder_Update_wrapper(&shaping_B.SFunction_d, &shaping_B.SFunction,
      &shaping_DW.SFunction_DSTATE, &shaping_P.SFunction_P1_d, 1,
      &shaping_P.Encoder_dt_enc, 1);
  }

  /* S-Function "sfcn_motor_new_wrapper" Block: <S20>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&shaping_B.conversion8,
    &shaping_B.LogicalOperator_n, &shaping_B.SFunction1_o1,
    &shaping_B.SFunction1_o2, &shaping_B.SFunction1_o3,
    &shaping_DW.SFunction1_DSTATE, &shaping_P.SFunction1_P1, 1,
    &shaping_P.SFunction1_P2, 1, &shaping_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(shaping_M)) {
    /* S-Function "SerialTx_wrapper" Block: <S5>/S-Function */
    SerialTx_Update_wrapper(&shaping_B.SFunction2_o1, (boolean_T*)&shaping_BGND,
      (boolean_T*)&shaping_BGND, (boolean_T*)&shaping_BGND,
      &shaping_B.LogicalOperator, &shaping_B.conversion3, &shaping_B.conversion9,
      &shaping_B.conversion10, &shaping_B.conversion13, &shaping_B.conversion2,
      &shaping_B.conversion4, &shaping_B.conversion5, &shaping_B.conversion6,
      &shaping_B.conversion7, &shaping_DW.SFunction_DSTATE_l,
      &shaping_P.SFunction_P1, 1, &shaping_P.SFunction_P2, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&shaping_DW.SFunction1_DSTATE_b);
  }

  if (rtmIsMajorTimeStep(shaping_M)) {
    rt_ertODEUpdateContinuousStates(&shaping_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++shaping_M->Timing.clockTick0;
  shaping_M->Timing.t[0] = rtsiGetSolverStopTime(&shaping_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    shaping_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void shaping_derivatives(void)
{
  XDot_shaping_T *_rtXdot;
  _rtXdot = ((XDot_shaping_T *) shaping_M->ModelData.derivs);

  /* Derivatives for ZeroPole: '<S2>/loopshaping' */
  _rtXdot->loopshaping_CSTATE[0] = 0.0;
  _rtXdot->loopshaping_CSTATE[1] = 0.0;
  _rtXdot->loopshaping_CSTATE[0] += shaping_P.loopshaping_A[0] *
    shaping_X.loopshaping_CSTATE[0];
  _rtXdot->loopshaping_CSTATE[1] += shaping_P.loopshaping_A[1] *
    shaping_X.loopshaping_CSTATE[0];
  _rtXdot->loopshaping_CSTATE[0] += shaping_P.loopshaping_B * shaping_B.Sum;
}

/* Model initialize function */
void shaping_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)shaping_M, 0,
                sizeof(RT_MODEL_shaping_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&shaping_M->solverInfo, &shaping_M->Timing.simTimeStep);
    rtsiSetTPtr(&shaping_M->solverInfo, &rtmGetTPtr(shaping_M));
    rtsiSetStepSizePtr(&shaping_M->solverInfo, &shaping_M->Timing.stepSize0);
    rtsiSetdXPtr(&shaping_M->solverInfo, &shaping_M->ModelData.derivs);
    rtsiSetContStatesPtr(&shaping_M->solverInfo, (real_T **)
                         &shaping_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&shaping_M->solverInfo,
      &shaping_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&shaping_M->solverInfo, (&rtmGetErrorStatus(shaping_M)));
    rtsiSetRTModelPtr(&shaping_M->solverInfo, shaping_M);
  }

  rtsiSetSimTimeStep(&shaping_M->solverInfo, MAJOR_TIME_STEP);
  shaping_M->ModelData.intgData.y = shaping_M->ModelData.odeY;
  shaping_M->ModelData.intgData.f[0] = shaping_M->ModelData.odeF[0];
  shaping_M->ModelData.intgData.f[1] = shaping_M->ModelData.odeF[1];
  shaping_M->ModelData.intgData.f[2] = shaping_M->ModelData.odeF[2];
  shaping_M->ModelData.contStates = ((X_shaping_T *) &shaping_X);
  rtsiSetSolverData(&shaping_M->solverInfo, (void *)
                    &shaping_M->ModelData.intgData);
  rtsiSetSolverName(&shaping_M->solverInfo,"ode3");
  rtmSetTPtr(shaping_M, &shaping_M->Timing.tArray[0]);
  shaping_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &shaping_B), 0,
                sizeof(B_shaping_T));

  /* states (continuous) */
  {
    (void) memset((void *)&shaping_X, 0,
                  sizeof(X_shaping_T));
  }

  /* states (dwork) */
  (void) memset((void *)&shaping_DW, 0,
                sizeof(DW_shaping_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  shaping_DW.clockTickCounter = -1000;

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S17>/S-Function' */
  MW_pinModeInput(shaping_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S19>/S-Function' */
  MW_pinModeInput(shaping_P.SFunction_p1_d);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' */
  MW_pinModeOutput(shaping_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_pinModeOutput(shaping_P.DigitalOutput_pinNumber_l);

  /* S-Function Block: <S3>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        shaping_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Memory: '<S1>/Memory' */
  shaping_DW.Memory_PreviousInput = shaping_P.Memory_X0;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  shaping_DW.Memory1_PreviousInput = shaping_P.Memory1_X0;

  /* S-Function Block: <S18>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        shaping_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for ZeroPole: '<S2>/loopshaping' */
  shaping_X.loopshaping_CSTATE[0] = 0.0;
  shaping_X.loopshaping_CSTATE[1] = 0.0;

  /* S-Function Block: <S20>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        shaping_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S5>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        shaping_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        shaping_DW.SFunction1_DSTATE_b = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void shaping_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
