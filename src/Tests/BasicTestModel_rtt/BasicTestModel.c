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
 * C/C++ source code generated on : Fri May 06 11:24:56 2016
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
void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real32_T y;
  int32_T i;
  int32_T exp_1;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0F;
  exp_1 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= (real32_T)ldexp((real32_T)cb, exp_1);
      cb = (uint32_T)(cb < u1i);
      exp_1 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += (real32_T)ldexp((real32_T)u1[i], exp_1);
      exp_1 += 32;
    }
  }

  return y;
}

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
  int_T nXc = 13;
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
  boolean_T rtb_SFunction_0;
  real_T SineWave;
  uint32_T tmp;
  uint32_T tmp_0;
  int64m_T tmp_1;
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
    /* S-Function (signals): '<S3>/S-Function2' */
    signals_Outputs_wrapper( &BasicTestModel_B.SFunction2_o1,
      &BasicTestModel_B.SFunction2_o2, &BasicTestModel_DW.SFunction2_DSTATE);

    /* DataTypeConversion: '<S6>/conversion1' */
    BasicTestModel_B.conversion1 = false;

    /* DataTypeConversion: '<S6>/conversion3' */
    BasicTestModel_B.conversion3 = false;

    /* DataTypeConversion: '<S6>/conversion9' */
    BasicTestModel_B.conversion9 = false;

    /* DataTypeConversion: '<S6>/conversion10' */
    BasicTestModel_B.conversion10 = false;

    /* DataTypeConversion: '<S6>/conversion13' */
    BasicTestModel_B.conversion13 = 0.0F;
  }

  /* Sin: '<Root>/Sine Wave' */
  SineWave = sin(BasicTestModel_P.SineWave_Freq * BasicTestModel_M->Timing.t[0]
                 + BasicTestModel_P.SineWave_Phase) *
    BasicTestModel_P.SineWave_Amp + BasicTestModel_P.SineWave_Bias;
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* DataTypeConversion: '<S6>/conversion2' */
    BasicTestModel_B.conversion2 = (real32_T)SineWave;

    /* S-Function (arduinodigitalinput_sfcn): '<S7>/S-Function' */
    BasicTestModel_B.SFunction_d = MW_digitalRead(BasicTestModel_P.SFunction_p1);

    /* S-Function (sfcn_encoder): '<S8>/S-Function' */
    sfcn_encoder_Outputs_wrapper(&BasicTestModel_B.SFunction_d,
      &BasicTestModel_B.SFunction, &BasicTestModel_DW.SFunction_DSTATE,
      &BasicTestModel_P.SFunction_P1_h, 1, &BasicTestModel_P.Encoder_dt_enc, 1);

    /* Gain: '<Root>/Gain2' */
    tmp = (uint32_T)BasicTestModel_P.Gain2_Gain;
    tmp_0 = (uint32_T)BasicTestModel_B.SFunction;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_1.chunks[0U], 2);
    BasicTestModel_B.Gain2 = tmp_1;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  BasicTestModel_B.Add = BasicTestModel_P.Gain1_Gain * SineWave -
    sMultiWord2Double(&BasicTestModel_B.Gain2.chunks[0U], 2, 0) *
    9.0949470177292824E-13;

  /* DataTypeConversion: '<S10>/conversion8' incorporates:
   *  ZeroPole: '<Root>/Zero-Pole'
   */
  BasicTestModel_B.conversion8 = (real32_T)((BasicTestModel_P.ZeroPole_C[0] *
    BasicTestModel_X.ZeroPole_CSTATE[0] + BasicTestModel_P.ZeroPole_C[1] *
    BasicTestModel_X.ZeroPole_CSTATE[1]) + BasicTestModel_P.ZeroPole_D *
    BasicTestModel_B.Add);
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S9>/S-Function' */
    rtb_SFunction_0 = MW_digitalRead(BasicTestModel_P.SFunction_p1_l);

    /* Logic: '<S10>/Logical Operator' incorporates:
     *  S-Function (arduinodigitalinput_sfcn): '<S9>/S-Function'
     */
    BasicTestModel_B.LogicalOperator = (rtb_SFunction_0 &&
      BasicTestModel_B.SFunction2_o1);
  }

  /* S-Function (sfcn_motor_new): '<S10>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&BasicTestModel_B.conversion8,
    &BasicTestModel_B.LogicalOperator, &BasicTestModel_B.SFunction1_o1,
    &BasicTestModel_B.SFunction1_o2, &BasicTestModel_B.SFunction1_o3,
    &BasicTestModel_DW.SFunction1_DSTATE, &BasicTestModel_P.SFunction1_P1, 1,
    &BasicTestModel_P.SFunction1_P2, 1, &BasicTestModel_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* DataTypeConversion: '<S6>/conversion4' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion1'
     */
    BasicTestModel_B.conversion4 = BasicTestModel_B.SFunction1_o1;

    /* DataTypeConversion: '<S6>/conversion5' */
    BasicTestModel_B.conversion5 = 0.0F;

    /* DataTypeConversion: '<S6>/conversion6' */
    BasicTestModel_B.conversion6 = 0.0F;

    /* DataTypeConversion: '<S6>/conversion7' */
    BasicTestModel_B.conversion7 = sMultiWord2Single
      (&BasicTestModel_B.Gain2.chunks[0U], 2, 0) * 9.09494702E-13F;

    /* S-Function (SerialTx): '<S6>/S-Function' */
    SerialTx_Outputs_wrapper(&BasicTestModel_B.SFunction2_o1, (boolean_T*)
      &BasicTestModel_BGND, (boolean_T*)&BasicTestModel_BGND, (boolean_T*)
      &BasicTestModel_BGND, &BasicTestModel_B.conversion1,
      &BasicTestModel_B.conversion3, &BasicTestModel_B.conversion9,
      &BasicTestModel_B.conversion10, &BasicTestModel_B.conversion13,
      &BasicTestModel_B.conversion2, &BasicTestModel_B.conversion4,
      &BasicTestModel_B.conversion5, &BasicTestModel_B.conversion6,
      &BasicTestModel_B.conversion7, &BasicTestModel_DW.SFunction_DSTATE_l,
      &BasicTestModel_P.SFunction_P1, 1, &BasicTestModel_P.SFunction_P2, 1);

    /* S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
    MW_digitalRead(BasicTestModel_P.SFunction_p1_m);

    /* S-Function (arduinodigitalinput_sfcn): '<S16>/S-Function' */
    MW_digitalRead(BasicTestModel_P.SFunction_p1_h);

    /* S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     */
    MW_digitalWrite(BasicTestModel_P.DigitalOutput_pinNumber, (uint8_T)
                    BasicTestModel_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     */
    MW_digitalWrite(BasicTestModel_P.DigitalOutput_pinNumber_f, (uint8_T)
                    BasicTestModel_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &BasicTestModel_DW.SFunction1_DSTATE_f);
  }
}

/* Model update function */
void BasicTestModel_update(void)
{
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
    signals_Update_wrapper( &BasicTestModel_B.SFunction2_o1,
      &BasicTestModel_B.SFunction2_o2, &BasicTestModel_DW.SFunction2_DSTATE);

    /* S-Function "sfcn_encoder_wrapper" Block: <S8>/S-Function */
    sfcn_encoder_Update_wrapper(&BasicTestModel_B.SFunction_d,
      &BasicTestModel_B.SFunction, &BasicTestModel_DW.SFunction_DSTATE,
      &BasicTestModel_P.SFunction_P1_h, 1, &BasicTestModel_P.Encoder_dt_enc, 1);
  }

  /* S-Function "sfcn_motor_new_wrapper" Block: <S10>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&BasicTestModel_B.conversion8,
    &BasicTestModel_B.LogicalOperator, &BasicTestModel_B.SFunction1_o1,
    &BasicTestModel_B.SFunction1_o2, &BasicTestModel_B.SFunction1_o3,
    &BasicTestModel_DW.SFunction1_DSTATE, &BasicTestModel_P.SFunction1_P1, 1,
    &BasicTestModel_P.SFunction1_P2, 1, &BasicTestModel_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(BasicTestModel_M)) {
    /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
    SerialTx_Update_wrapper(&BasicTestModel_B.SFunction2_o1, (boolean_T*)
      &BasicTestModel_BGND, (boolean_T*)&BasicTestModel_BGND, (boolean_T*)
      &BasicTestModel_BGND, &BasicTestModel_B.conversion1,
      &BasicTestModel_B.conversion3, &BasicTestModel_B.conversion9,
      &BasicTestModel_B.conversion10, &BasicTestModel_B.conversion13,
      &BasicTestModel_B.conversion2, &BasicTestModel_B.conversion4,
      &BasicTestModel_B.conversion5, &BasicTestModel_B.conversion6,
      &BasicTestModel_B.conversion7, &BasicTestModel_DW.SFunction_DSTATE_l,
      &BasicTestModel_P.SFunction_P1, 1, &BasicTestModel_P.SFunction_P2, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&BasicTestModel_DW.SFunction1_DSTATE_f);
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

  /* Derivatives for ZeroPole: '<Root>/Zero-Pole' */
  _rtXdot->ZeroPole_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole_CSTATE[0] += BasicTestModel_P.ZeroPole_A[0] *
    BasicTestModel_X.ZeroPole_CSTATE[0];
  _rtXdot->ZeroPole_CSTATE[1] += BasicTestModel_P.ZeroPole_A[1] *
    BasicTestModel_X.ZeroPole_CSTATE[0];
  _rtXdot->ZeroPole_CSTATE[0] += BasicTestModel_P.ZeroPole_B *
    BasicTestModel_B.Add;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += BasicTestModel_P.TransferFcn1_A *
    BasicTestModel_X.TransferFcn1_CSTATE;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += BasicTestModel_P.TransferFcn_A[0] *
    BasicTestModel_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += BasicTestModel_P.TransferFcn_A[1] *
    BasicTestModel_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += BasicTestModel_X.TransferFcn_CSTATE[0];

  /* Derivatives for ZeroPole: '<Root>/Zero-Pole1' */
  _rtXdot->ZeroPole1_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole1_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole1_CSTATE[0] += BasicTestModel_P.ZeroPole1_A[0] *
    BasicTestModel_X.ZeroPole1_CSTATE[0];
  _rtXdot->ZeroPole1_CSTATE[1] += BasicTestModel_P.ZeroPole1_A[1] *
    BasicTestModel_X.ZeroPole1_CSTATE[0];
  _rtXdot->ZeroPole1_CSTATE[0] += BasicTestModel_P.ZeroPole1_B * 0.0;

  /* Derivatives for ZeroPole: '<Root>/Zero-Pole2' */
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

  /* Derivatives for ZeroPole: '<Root>/Zero-Pole4' */
  _rtXdot->ZeroPole4_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole4_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole4_CSTATE[0] += BasicTestModel_P.ZeroPole4_A[0] *
    BasicTestModel_X.ZeroPole4_CSTATE[0];
  _rtXdot->ZeroPole4_CSTATE[1] += BasicTestModel_P.ZeroPole4_A[1] *
    BasicTestModel_X.ZeroPole4_CSTATE[0];
  _rtXdot->ZeroPole4_CSTATE[0] += BasicTestModel_P.ZeroPole4_B * 0.0;
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

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S7>/S-Function' */
  MW_pinModeInput(BasicTestModel_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S9>/S-Function' */
  MW_pinModeInput(BasicTestModel_P.SFunction_p1_l);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
  MW_pinModeInput(BasicTestModel_P.SFunction_p1_m);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S16>/S-Function' */
  MW_pinModeInput(BasicTestModel_P.SFunction_p1_h);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' */
  MW_pinModeOutput(BasicTestModel_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_pinModeOutput(BasicTestModel_P.DigitalOutput_pinNumber_f);

  /* S-Function Block: <S3>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S8>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for ZeroPole: '<Root>/Zero-Pole' */
  BasicTestModel_X.ZeroPole_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole_CSTATE[1] = 0.0;

  /* S-Function Block: <S10>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  BasicTestModel_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  BasicTestModel_X.TransferFcn_CSTATE[0] = 0.0;
  BasicTestModel_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for ZeroPole: '<Root>/Zero-Pole1' */
  BasicTestModel_X.ZeroPole1_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole1_CSTATE[1] = 0.0;

  /* InitializeConditions for ZeroPole: '<Root>/Zero-Pole2' */
  BasicTestModel_X.ZeroPole2_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole2_CSTATE[1] = 0.0;
  BasicTestModel_X.ZeroPole2_CSTATE[2] = 0.0;
  BasicTestModel_X.ZeroPole2_CSTATE[3] = 0.0;

  /* InitializeConditions for ZeroPole: '<Root>/Zero-Pole4' */
  BasicTestModel_X.ZeroPole4_CSTATE[0] = 0.0;
  BasicTestModel_X.ZeroPole4_CSTATE[1] = 0.0;

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BasicTestModel_DW.SFunction1_DSTATE_f = initVector[0];
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
