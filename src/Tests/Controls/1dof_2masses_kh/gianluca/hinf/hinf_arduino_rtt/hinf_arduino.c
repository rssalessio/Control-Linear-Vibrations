/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hinf_arduino.c
 *
 * Code generated for Simulink model 'hinf_arduino'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue May 03 15:04:05 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hinf_arduino.h"
#include "hinf_arduino_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define hinf_arduino_IN_ALERT          ((uint8_T)1U)
#define hinf_arduino_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define hinf_arduino_IN_OK             ((uint8_T)2U)
#define hinf_arduino_IN_RESTORE        ((uint8_T)3U)

const boolean_T hinf_arduino_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_hinf_arduino_T hinf_arduino_B;

/* Continuous states */
X_hinf_arduino_T hinf_arduino_X;

/* Block states (auto storage) */
DW_hinf_arduino_T hinf_arduino_DW;

/* Real-time model */
RT_MODEL_hinf_arduino_T hinf_arduino_M_;
RT_MODEL_hinf_arduino_T *const hinf_arduino_M = &hinf_arduino_M_;
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

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0 ? (int32_T)true : (int32_T)false;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T su1;
  uint32_T su2;
  int32_T i;
  su1 = u1[n - 1] & 2147483648U;
  su2 = u2[n - 1] & 2147483648U;
  if ((su1 ^ su2) != 0U) {
    y = su1 != 0U ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      su2 = u2[i];
      if (su1 != su2) {
        y = su1 > su2 ? 1 : -1;
      }
    }
  }

  return y;
}

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0 ? (int32_T)true : (int32_T)false;
}

real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real32_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0F;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= (real32_T)ldexp((real32_T)cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += (real32_T)ldexp((real32_T)u1[i], exp_0);
      exp_0 += 32;
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  hinf_arduino_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  hinf_arduino_output();
  hinf_arduino_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  hinf_arduino_output();
  hinf_arduino_derivatives();

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
void hinf_arduino_output(void)
{
  int_T ci;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_FixPtRelationalOperator;
  real_T rtb_Saturation;
  int64m_T rtb_encodertocm;
  real_T HINFINITY;
  real_T Saturation;
  uint32_T tmp;
  uint32_T tmp_0;
  int64m_T tmp_1;
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&hinf_arduino_M->solverInfo,
                          ((hinf_arduino_M->Timing.clockTick0+1)*
      hinf_arduino_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(hinf_arduino_M)) {
    hinf_arduino_M->Timing.t[0] = rtsiGetT(&hinf_arduino_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* S-Function (signals): '<S3>/S-Function2' */
    signals_Outputs_wrapper( &hinf_arduino_B.SFunction2_o1,
      &hinf_arduino_B.SFunction2_o2, &hinf_arduino_DW.SFunction2_DSTATE);

    /* Gain: '<S9>/encoder-to-cm' incorporates:
     *  Memory: '<S1>/Memory2'
     */
    tmp = (uint32_T)hinf_arduino_P.encodertocm_Gain;
    tmp_0 = (uint32_T)hinf_arduino_DW.Memory2_PreviousInput;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_encodertocm.chunks[0U], 2);

    /* Logic: '<S9>/Logical Operator' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S13>/Constant'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S13>/Compare'
     */
    rtb_LogicalOperator = (sMultiWordGe(&rtb_encodertocm.chunks[0U],
      &hinf_arduino_P.UpperThreshold_const.chunks[0U], 2) || sMultiWordLe
      (&rtb_encodertocm.chunks[0U], &hinf_arduino_P.LowerThreshold_const.chunks
       [0U], 2));

    /* S-Function (arduinodigitalinput_sfcn): '<S18>/S-Function' */
    rtb_FixPtRelationalOperator = MW_digitalRead(hinf_arduino_P.SFunction_p1);

    /* Logic: '<S16>/Logical Operator' incorporates:
     *  S-Function (arduinodigitalinput_sfcn): '<S18>/S-Function'
     */
    hinf_arduino_B.LogicalOperator = rtb_FixPtRelationalOperator;

    /* S-Function (sfcn_encoder): '<S19>/S-Function' */
    sfcn_encoder_Outputs_wrapper(&hinf_arduino_B.LogicalOperator,
      &hinf_arduino_B.SFunction, &hinf_arduino_DW.SFunction_DSTATE,
      &hinf_arduino_P.SFunction_P1_l, 1, &hinf_arduino_P.Encoder_dt_enc, 1);

    /* RelationalOperator: '<S8>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S8>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = (hinf_arduino_B.SFunction !=
      hinf_arduino_DW.DelayInput1_DSTATE);
  }

  /* StateSpace: '<S2>/H INFINITY' */
  HINFINITY = 0.0;
  for (ci = 0; ci < 6; ci++) {
    HINFINITY += hinf_arduino_P.HINFINITY_C[ci] *
      hinf_arduino_X.HINFINITY_CSTATE[ci];
  }

  /* End of StateSpace: '<S2>/H INFINITY' */

  /* Saturate: '<S11>/Saturation' */
  if (HINFINITY > hinf_arduino_P.Saturation_UpperSat) {
    Saturation = hinf_arduino_P.Saturation_UpperSat;
  } else if (HINFINITY < hinf_arduino_P.Saturation_LowerSat) {
    Saturation = hinf_arduino_P.Saturation_LowerSat;
  } else {
    Saturation = HINFINITY;
  }

  /* End of Saturate: '<S11>/Saturation' */
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* Chart: '<S1>/Chart' */
    /* Gateway: Condom/Chart */
    /* During: Condom/Chart */
    if (hinf_arduino_DW.is_active_c3_hinf_arduino == 0U) {
      /* Entry: Condom/Chart */
      hinf_arduino_DW.is_active_c3_hinf_arduino = 1U;

      /* Entry Internal: Condom/Chart */
      /* Transition: '<S7>:4' */
      hinf_arduino_DW.is_c3_hinf_arduino = hinf_arduino_IN_OK;

      /* Entry 'OK': '<S7>:1' */
      hinf_arduino_B.MD = 0.0;
    } else {
      switch (hinf_arduino_DW.is_c3_hinf_arduino) {
       case hinf_arduino_IN_ALERT:
        /* During 'ALERT': '<S7>:2' */
        if (!rtb_FixPtRelationalOperator) {
          /* Transition: '<S7>:11' */
          hinf_arduino_DW.is_c3_hinf_arduino = hinf_arduino_IN_RESTORE;

          /* Entry 'RESTORE': '<S7>:10' */
          hinf_arduino_B.MD = 1.0;
        }
        break;

       case hinf_arduino_IN_OK:
        /* During 'OK': '<S7>:1' */
        if (rtb_LogicalOperator) {
          /* Transition: '<S7>:3' */
          hinf_arduino_DW.is_c3_hinf_arduino = hinf_arduino_IN_ALERT;

          /* Entry 'ALERT': '<S7>:2' */
          hinf_arduino_B.MD = 1.0;
        }
        break;

       default:
        /* During 'RESTORE': '<S7>:10' */
        if (Saturation == 0.0) {
          /* Transition: '<S7>:12' */
          hinf_arduino_DW.is_c3_hinf_arduino = hinf_arduino_IN_OK;

          /* Entry 'OK': '<S7>:1' */
          hinf_arduino_B.MD = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<S1>/Chart' */

    /* DataTypeConversion: '<S6>/conversion1' */
    hinf_arduino_B.conversion1 = (hinf_arduino_B.MD != 0.0);

    /* DataTypeConversion: '<S6>/conversion3' */
    hinf_arduino_B.conversion3 = false;

    /* DataTypeConversion: '<S6>/conversion9' */
    hinf_arduino_B.conversion9 = false;

    /* DataTypeConversion: '<S6>/conversion10' */
    hinf_arduino_B.conversion10 = false;

    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    rtb_Saturation = (hinf_arduino_DW.clockTickCounter <
                      hinf_arduino_P.PulseGenerator_Duty) &&
      (hinf_arduino_DW.clockTickCounter >= 0) ?
      hinf_arduino_P.PulseGenerator_Amp : 0.0;
    if (hinf_arduino_DW.clockTickCounter >= hinf_arduino_P.PulseGenerator_Period
        - 1.0) {
      hinf_arduino_DW.clockTickCounter = 0;
    } else {
      hinf_arduino_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Saturate: '<S10>/Saturation' */
    if (rtb_Saturation > hinf_arduino_P.Saturation_UpperSat_l) {
      rtb_Saturation = hinf_arduino_P.Saturation_UpperSat_l;
    } else {
      if (rtb_Saturation < hinf_arduino_P.Saturation_LowerSat_o) {
        rtb_Saturation = hinf_arduino_P.Saturation_LowerSat_o;
      }
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Product: '<S1>/Product' incorporates:
     *  Logic: '<S1>/Motor Enabler'
     *  Memory: '<S1>/Memory1'
     */
    rtb_Saturation *= (real_T)!(hinf_arduino_DW.Memory1_PreviousInput != 0.0);

    /* DataTypeConversion: '<S6>/conversion13' */
    hinf_arduino_B.conversion13 = (real32_T)rtb_Saturation;

    /* DataTypeConversion: '<S6>/conversion2' */
    hinf_arduino_B.conversion2 = (real32_T)HINFINITY;
  }

  /* DataTypeConversion: '<S21>/conversion8' */
  hinf_arduino_B.conversion8 = (real32_T)Saturation;
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S20>/S-Function' */
    rtb_FixPtRelationalOperator = MW_digitalRead(hinf_arduino_P.SFunction_p1_c);

    /* Logic: '<S21>/Logical Operator' incorporates:
     *  Logic: '<Root>/Logical Operator'
     *  Logic: '<S17>/Logical Operator'
     *  S-Function (arduinodigitalinput_sfcn): '<S20>/S-Function'
     */
    hinf_arduino_B.LogicalOperator_b = (rtb_FixPtRelationalOperator &&
      (!(hinf_arduino_B.MD != 0.0)) && hinf_arduino_B.SFunction2_o1);
  }

  /* S-Function (sfcn_motor_new): '<S21>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&hinf_arduino_B.conversion8,
    &hinf_arduino_B.LogicalOperator_b, &hinf_arduino_B.SFunction1_o1,
    &hinf_arduino_B.SFunction1_o2, &hinf_arduino_B.SFunction1_o3,
    &hinf_arduino_DW.SFunction1_DSTATE, &hinf_arduino_P.SFunction1_P1, 1,
    &hinf_arduino_P.SFunction1_P2, 1, &hinf_arduino_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* DataTypeConversion: '<S6>/conversion4' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     */
    hinf_arduino_B.conversion4 = hinf_arduino_B.SFunction1_o1;

    /* Gain: '<Root>/encoder-to-cm' */
    tmp = (uint32_T)hinf_arduino_P.encodertocm_Gain_j;
    tmp_0 = (uint32_T)hinf_arduino_B.SFunction;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_1.chunks[0U], 2);

    /* DataTypeConversion: '<S6>/conversion5' */
    hinf_arduino_B.conversion5 = sMultiWord2Single(&tmp_1.chunks[0U], 2, 0) *
      9.09494702E-13F;

    /* DataTypeConversion: '<S6>/conversion6' */
    hinf_arduino_B.conversion6 = 0.0F;

    /* DataTypeConversion: '<S6>/conversion7' */
    hinf_arduino_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S6>/S-Function' */
    SerialTx_Outputs_wrapper(&hinf_arduino_B.SFunction2_o1, (boolean_T*)
      &hinf_arduino_BGND, (boolean_T*)&hinf_arduino_BGND, (boolean_T*)
      &hinf_arduino_BGND, &hinf_arduino_B.conversion1,
      &hinf_arduino_B.conversion3, &hinf_arduino_B.conversion9,
      &hinf_arduino_B.conversion10, &hinf_arduino_B.conversion13,
      &hinf_arduino_B.conversion2, &hinf_arduino_B.conversion4,
      &hinf_arduino_B.conversion5, &hinf_arduino_B.conversion6,
      &hinf_arduino_B.conversion7, &hinf_arduino_DW.SFunction_DSTATE_e,
      &hinf_arduino_P.SFunction_P1, 1, &hinf_arduino_P.SFunction_P2, 1);

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/cm-to-encoder'
     */
    hinf_arduino_B.Sum = hinf_arduino_P.cmtoencoder_Gain * rtb_Saturation -
      (real_T)hinf_arduino_B.SFunction;
  }

  /* S-Function (sfun_tstart): '<S4>/startTime' */

  /* S-Function Block (sfun_tstart): <S4>/startTime */
  hinf_arduino_B.startTime = (0.0);
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion'
     */
    MW_digitalWrite(hinf_arduino_P.DigitalOutput_pinNumber, (uint8_T)
                    hinf_arduino_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     */
    MW_digitalWrite(hinf_arduino_P.DigitalOutput_pinNumber_p, (uint8_T)
                    hinf_arduino_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &hinf_arduino_DW.SFunction1_DSTATE_b);
  }
}

/* Model update function */
void hinf_arduino_update(void)
{
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
    signals_Update_wrapper( &hinf_arduino_B.SFunction2_o1,
      &hinf_arduino_B.SFunction2_o2, &hinf_arduino_DW.SFunction2_DSTATE);

    /* Update for Memory: '<S1>/Memory2' */
    hinf_arduino_DW.Memory2_PreviousInput = hinf_arduino_B.SFunction;

    /* S-Function "sfcn_encoder_wrapper" Block: <S19>/S-Function */
    sfcn_encoder_Update_wrapper(&hinf_arduino_B.LogicalOperator,
      &hinf_arduino_B.SFunction, &hinf_arduino_DW.SFunction_DSTATE,
      &hinf_arduino_P.SFunction_P1_l, 1, &hinf_arduino_P.Encoder_dt_enc, 1);

    /* Update for UnitDelay: '<S8>/Delay Input1' */
    hinf_arduino_DW.DelayInput1_DSTATE = hinf_arduino_B.SFunction;

    /* Update for Memory: '<S1>/Memory1' */
    hinf_arduino_DW.Memory1_PreviousInput = hinf_arduino_B.MD;
  }

  /* S-Function "sfcn_motor_new_wrapper" Block: <S21>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&hinf_arduino_B.conversion8,
    &hinf_arduino_B.LogicalOperator_b, &hinf_arduino_B.SFunction1_o1,
    &hinf_arduino_B.SFunction1_o2, &hinf_arduino_B.SFunction1_o3,
    &hinf_arduino_DW.SFunction1_DSTATE, &hinf_arduino_P.SFunction1_P1, 1,
    &hinf_arduino_P.SFunction1_P2, 1, &hinf_arduino_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
    SerialTx_Update_wrapper(&hinf_arduino_B.SFunction2_o1, (boolean_T*)
      &hinf_arduino_BGND, (boolean_T*)&hinf_arduino_BGND, (boolean_T*)
      &hinf_arduino_BGND, &hinf_arduino_B.conversion1,
      &hinf_arduino_B.conversion3, &hinf_arduino_B.conversion9,
      &hinf_arduino_B.conversion10, &hinf_arduino_B.conversion13,
      &hinf_arduino_B.conversion2, &hinf_arduino_B.conversion4,
      &hinf_arduino_B.conversion5, &hinf_arduino_B.conversion6,
      &hinf_arduino_B.conversion7, &hinf_arduino_DW.SFunction_DSTATE_e,
      &hinf_arduino_P.SFunction_P1, 1, &hinf_arduino_P.SFunction_P2, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&hinf_arduino_DW.SFunction1_DSTATE_b);
  }

  if (rtmIsMajorTimeStep(hinf_arduino_M)) {
    rt_ertODEUpdateContinuousStates(&hinf_arduino_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++hinf_arduino_M->Timing.clockTick0;
  hinf_arduino_M->Timing.t[0] = rtsiGetSolverStopTime
    (&hinf_arduino_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    hinf_arduino_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void hinf_arduino_derivatives(void)
{
  int_T is;
  int_T ci;
  static const int8_T ir[7] = { 0, 1, 7, 9, 15, 18, 22 };

  static const int8_T ir_0[7] = { 0, 1, 1, 2, 3, 4, 5 };

  static const int8_T jc[22] = { 0, 0, 1, 2, 3, 4, 5, 2, 5, 0, 1, 2, 3, 4, 5, 2,
    3, 5, 0, 2, 4, 5 };

  XDot_hinf_arduino_T *_rtXdot;
  _rtXdot = ((XDot_hinf_arduino_T *) hinf_arduino_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<S2>/H INFINITY' */
  for (is = 0; is < 6; is++) {
    _rtXdot->HINFINITY_CSTATE[is] = 0.0;
  }

  for (is = 0; is < 6; is++) {
    for (ci = ir[is]; ci < ir[is + 1]; ci++) {
      _rtXdot->HINFINITY_CSTATE[is] += hinf_arduino_P.HINFINITY_A[ci] *
        hinf_arduino_X.HINFINITY_CSTATE[jc[ci]];
    }
  }

  for (is = 0; is < 6; is++) {
    for (ci = ir_0[is]; ci < ir_0[is + 1]; ci++) {
      _rtXdot->HINFINITY_CSTATE[is] += hinf_arduino_P.HINFINITY_B[ci] *
        hinf_arduino_B.Sum;
    }
  }

  /* End of Derivatives for StateSpace: '<S2>/H INFINITY' */
}

/* Model initialize function */
void hinf_arduino_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)hinf_arduino_M, 0,
                sizeof(RT_MODEL_hinf_arduino_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&hinf_arduino_M->solverInfo,
                          &hinf_arduino_M->Timing.simTimeStep);
    rtsiSetTPtr(&hinf_arduino_M->solverInfo, &rtmGetTPtr(hinf_arduino_M));
    rtsiSetStepSizePtr(&hinf_arduino_M->solverInfo,
                       &hinf_arduino_M->Timing.stepSize0);
    rtsiSetdXPtr(&hinf_arduino_M->solverInfo, &hinf_arduino_M->ModelData.derivs);
    rtsiSetContStatesPtr(&hinf_arduino_M->solverInfo, (real_T **)
                         &hinf_arduino_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&hinf_arduino_M->solverInfo,
      &hinf_arduino_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&hinf_arduino_M->solverInfo, (&rtmGetErrorStatus
      (hinf_arduino_M)));
    rtsiSetRTModelPtr(&hinf_arduino_M->solverInfo, hinf_arduino_M);
  }

  rtsiSetSimTimeStep(&hinf_arduino_M->solverInfo, MAJOR_TIME_STEP);
  hinf_arduino_M->ModelData.intgData.y = hinf_arduino_M->ModelData.odeY;
  hinf_arduino_M->ModelData.intgData.f[0] = hinf_arduino_M->ModelData.odeF[0];
  hinf_arduino_M->ModelData.intgData.f[1] = hinf_arduino_M->ModelData.odeF[1];
  hinf_arduino_M->ModelData.intgData.f[2] = hinf_arduino_M->ModelData.odeF[2];
  hinf_arduino_M->ModelData.contStates = ((X_hinf_arduino_T *) &hinf_arduino_X);
  rtsiSetSolverData(&hinf_arduino_M->solverInfo, (void *)
                    &hinf_arduino_M->ModelData.intgData);
  rtsiSetSolverName(&hinf_arduino_M->solverInfo,"ode3");
  rtmSetTPtr(hinf_arduino_M, &hinf_arduino_M->Timing.tArray[0]);
  hinf_arduino_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &hinf_arduino_B), 0,
                sizeof(B_hinf_arduino_T));

  /* states (continuous) */
  {
    (void) memset((void *)&hinf_arduino_X, 0,
                  sizeof(X_hinf_arduino_T));
  }

  /* states (dwork) */
  (void) memset((void *)&hinf_arduino_DW, 0,
                sizeof(DW_hinf_arduino_T));

  {
    int32_T Ns;

    /* Start for S-Function (arduinodigitalinput_sfcn): '<S18>/S-Function' */
    MW_pinModeInput(hinf_arduino_P.SFunction_p1);

    /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
    hinf_arduino_DW.clockTickCounter = -1000;

    /* Start for S-Function (arduinodigitalinput_sfcn): '<S20>/S-Function' */
    MW_pinModeInput(hinf_arduino_P.SFunction_p1_c);

    /* Start for S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
    MW_pinModeOutput(hinf_arduino_P.DigitalOutput_pinNumber);

    /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
    MW_pinModeOutput(hinf_arduino_P.DigitalOutput_pinNumber_p);

    /* S-Function Block: <S3>/S-Function2 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hinf_arduino_DW.SFunction2_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    hinf_arduino_DW.Memory2_PreviousInput = hinf_arduino_P.Memory2_X0;

    /* S-Function Block: <S19>/S-Function */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hinf_arduino_DW.SFunction_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S8>/Delay Input1' */
    hinf_arduino_DW.DelayInput1_DSTATE = hinf_arduino_P.DetectChange_vinit;

    /* InitializeConditions for StateSpace: '<S2>/H INFINITY' */
    for (Ns = 0; Ns < 6; Ns++) {
      hinf_arduino_X.HINFINITY_CSTATE[Ns] = hinf_arduino_P.HINFINITY_X0;
    }

    /* End of InitializeConditions for StateSpace: '<S2>/H INFINITY' */

    /* InitializeConditions for Chart: '<S1>/Chart' */
    hinf_arduino_DW.is_active_c3_hinf_arduino = 0U;
    hinf_arduino_DW.is_c3_hinf_arduino = hinf_arduino_IN_NO_ACTIVE_CHILD;

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    hinf_arduino_DW.Memory1_PreviousInput = hinf_arduino_P.Memory1_X0;

    /* S-Function Block: <S21>/S-Function1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hinf_arduino_DW.SFunction1_DSTATE = initVector[0];
        }
      }
    }

    /* S-Function Block: <S6>/S-Function */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hinf_arduino_DW.SFunction_DSTATE_e = initVector[0];
        }
      }
    }

    /* S-Function Block: <S3>/S-Function1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hinf_arduino_DW.SFunction1_DSTATE_b = initVector[0];
        }
      }
    }
  }
}

/* Model terminate function */
void hinf_arduino_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
