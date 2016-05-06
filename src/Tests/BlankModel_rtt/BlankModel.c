/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BlankModel.c
 *
 * Code generated for Simulink model 'BlankModel'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 12:54:17 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BlankModel.h"
#include "BlankModel_private.h"

/* Named constants for Chart: '<S7>/Alert Manager' */
#define BlankModel_IN_ALERT            ((uint8_T)1U)
#define BlankModel_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define BlankModel_IN_OK               ((uint8_T)2U)

/* Named constants for Chart: '<S7>/Init Manager' */
#define BlankModel_IN_INIT             ((uint8_T)1U)
#define BlankModel_IN_OPERATIVE        ((uint8_T)2U)
#define BlankModel_IN_STOP             ((uint8_T)3U)

const boolean_T BlankModel_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_BlankModel_T BlankModel_B;

/* Continuous states */
X_BlankModel_T BlankModel_X;

/* Block states (auto storage) */
DW_BlankModel_T BlankModel_DW;

/* Real-time model */
RT_MODEL_BlankModel_T BlankModel_M_;
RT_MODEL_BlankModel_T *const BlankModel_M = &BlankModel_M_;
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  BlankModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  BlankModel_output();
  BlankModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  BlankModel_output();
  BlankModel_derivatives();

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
void BlankModel_output(void)
{
  boolean_T rtb_SFunction_0;
  real_T rtb_Saturation;
  int64m_T rtb_encodertocm;
  uint32_T tmp;
  uint32_T tmp_0;
  int64m_T tmp_1;
  real_T u0;
  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&BlankModel_M->solverInfo,
                          ((BlankModel_M->Timing.clockTick0+1)*
      BlankModel_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BlankModel_M)) {
    BlankModel_M->Timing.t[0] = rtsiGetT(&BlankModel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* S-Function (signals): '<S3>/S-Function2' */
    signals_Outputs_wrapper( &BlankModel_B.SFunction2_o1,
      &BlankModel_B.SFunction2_o2, &BlankModel_DW.SFunction2_DSTATE);

    /* S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
    rtb_SFunction_0 = MW_digitalRead(BlankModel_P.SFunction_p1);

    /* Chart: '<S7>/Init Manager' incorporates:
     *  S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function'
     */
    if (BlankModel_DW.temporalCounter_i1 < 1023U) {
      BlankModel_DW.temporalCounter_i1++;
    }

    /* Gateway: Condom/Manager/Init
       Manager */
    /* During: Condom/Manager/Init
       Manager */
    if (BlankModel_DW.is_active_c1_BlankModel == 0U) {
      /* Entry: Condom/Manager/Init
         Manager */
      BlankModel_DW.is_active_c1_BlankModel = 1U;

      /* Entry Internal: Condom/Manager/Init
         Manager */
      /* Transition: '<S12>:7' */
      BlankModel_DW.is_c1_BlankModel = BlankModel_IN_STOP;

      /* Entry 'STOP': '<S12>:1' */
      BlankModel_B.MD = 1.0;
      BlankModel_B.ER = 1.0;
    } else {
      switch (BlankModel_DW.is_c1_BlankModel) {
       case BlankModel_IN_INIT:
        /* During 'INIT': '<S12>:2' */
        if (BlankModel_DW.temporalCounter_i1 >= 600U) {
          /* Transition: '<S12>:9' */
          BlankModel_DW.is_c1_BlankModel = BlankModel_IN_OPERATIVE;

          /* Entry 'OPERATIVE': '<S12>:4' */
          BlankModel_B.MD = 0.0;
          BlankModel_B.ER = 0.0;
        }
        break;

       case BlankModel_IN_OPERATIVE:
        /* During 'OPERATIVE': '<S12>:4' */
        if (!rtb_SFunction_0) {
          /* Transition: '<S12>:10' */
          BlankModel_DW.is_c1_BlankModel = BlankModel_IN_STOP;

          /* Entry 'STOP': '<S12>:1' */
          BlankModel_B.MD = 1.0;
          BlankModel_B.ER = 1.0;
        }
        break;

       default:
        /* During 'STOP': '<S12>:1' */
        if (rtb_SFunction_0) {
          /* Transition: '<S12>:8' */
          BlankModel_DW.is_c1_BlankModel = BlankModel_IN_INIT;
          BlankModel_DW.temporalCounter_i1 = 0U;

          /* Entry 'INIT': '<S12>:2' */
          BlankModel_B.MD = 1.0;
          BlankModel_B.ER = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<S7>/Init Manager' */

    /* Gain: '<S8>/encoder-to-cm' incorporates:
     *  Memory: '<S8>/Memory'
     */
    tmp = (uint32_T)BlankModel_P.encodertocm_Gain;
    tmp_0 = (uint32_T)BlankModel_DW.Memory_PreviousInput;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_encodertocm.chunks[0U], 2);

    /* Saturate: '<S10>/Saturation' incorporates:
     *  Memory: '<S10>/Memory1'
     */
    if (BlankModel_DW.Memory1_PreviousInput > BlankModel_P.Saturation_UpperSat)
    {
      rtb_Saturation = BlankModel_P.Saturation_UpperSat;
    } else if (BlankModel_DW.Memory1_PreviousInput <
               BlankModel_P.Saturation_LowerSat) {
      rtb_Saturation = BlankModel_P.Saturation_LowerSat;
    } else {
      rtb_Saturation = BlankModel_DW.Memory1_PreviousInput;
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Chart: '<S7>/Alert Manager' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S15>/Constant'
     *  Logic: '<S8>/Logical Operator'
     *  RelationalOperator: '<S14>/Compare'
     *  RelationalOperator: '<S15>/Compare'
     */
    /* Gateway: Condom/Manager/Alert
       Manager */
    /* During: Condom/Manager/Alert
       Manager */
    if (BlankModel_DW.is_active_c3_BlankModel == 0U) {
      /* Entry: Condom/Manager/Alert
         Manager */
      BlankModel_DW.is_active_c3_BlankModel = 1U;

      /* Entry Internal: Condom/Manager/Alert
         Manager */
      /* Transition: '<S11>:2' */
      BlankModel_DW.is_c3_BlankModel = BlankModel_IN_OK;

      /* Entry 'OK': '<S11>:5' */
      BlankModel_B.MD_d = 0.0;
      BlankModel_B.ER_h = 0.0;
    } else if (BlankModel_DW.is_c3_BlankModel == BlankModel_IN_ALERT) {
      /* During 'ALERT': '<S11>:4' */
      if (fabs(rtb_Saturation) < 0.3) {
        /* Transition: '<S11>:3' */
        BlankModel_DW.is_c3_BlankModel = BlankModel_IN_OK;

        /* Entry 'OK': '<S11>:5' */
        BlankModel_B.MD_d = 0.0;
        BlankModel_B.ER_h = 0.0;
      }
    } else {
      /* During 'OK': '<S11>:5' */
      if (sMultiWordGe(&rtb_encodertocm.chunks[0U],
                       &BlankModel_P.UpperThreshold_const_i.chunks[0U], 2) ||
          sMultiWordLe(&rtb_encodertocm.chunks[0U],
                       &BlankModel_P.LowerThreshold_const_a.chunks[0U], 2)) {
        /* Transition: '<S11>:1' */
        BlankModel_DW.is_c3_BlankModel = BlankModel_IN_ALERT;

        /* Entry 'ALERT': '<S11>:4' */
        BlankModel_B.MD_d = 1.0;
        BlankModel_B.ER_h = 1.0;
      }
    }

    /* End of Chart: '<S7>/Alert Manager' */

    /* Logic: '<S7>/Motor Detector' */
    BlankModel_B.MotorDetector = ((BlankModel_B.MD != 0.0) || (BlankModel_B.MD_d
      != 0.0));

    /* Logic: '<S7>/Encoder Detector' */
    BlankModel_B.EncoderDetector = ((BlankModel_B.ER != 0.0) ||
      (BlankModel_B.ER_h != 0.0));

    /* Logic: '<S10>/Logical Operator' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S16>/Compare'
     *  RelationalOperator: '<S17>/Compare'
     */
    BlankModel_B.LogicalOperator = ((rtb_Saturation >=
      BlankModel_P.UpperThreshold_const) || (rtb_Saturation <=
      BlankModel_P.LowerThreshold_const));

    /* DataTypeConversion: '<S6>/conversion10' */
    BlankModel_B.conversion10 = false;

    /* Logic: '<S9>/Motor Enabler' incorporates:
     *  Memory: '<S9>/Memory1'
     */
    BlankModel_B.MotorEnabler = !BlankModel_DW.Memory1_PreviousInput_m;
  }

  /* Sin: '<Root>/Sine Wave' */
  u0 = sin(BlankModel_P.SineWave_Freq * BlankModel_M->Timing.t[0] +
           BlankModel_P.SineWave_Phase) * BlankModel_P.SineWave_Amp +
    BlankModel_P.SineWave_Bias;

  /* Saturate: '<S9>/Saturation' */
  if (u0 > BlankModel_P.Saturation_UpperSat_i) {
    u0 = BlankModel_P.Saturation_UpperSat_i;
  } else {
    if (u0 < BlankModel_P.Saturation_LowerSat_n) {
      u0 = BlankModel_P.Saturation_LowerSat_n;
    }
  }

  /* Product: '<S9>/Product' incorporates:
   *  Saturate: '<S9>/Saturation'
   */
  BlankModel_B.Product = u0 * BlankModel_B.MotorEnabler;
  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* DataTypeConversion: '<S6>/conversion13' */
    BlankModel_B.conversion13 = (real32_T)BlankModel_B.Product;

    /* S-Function (sfcn_encoder): '<S22>/S-Function' */
    sfcn_encoder_Outputs_wrapper(&BlankModel_B.EncoderDetector,
      &BlankModel_B.SFunction, &BlankModel_DW.SFunction_DSTATE,
      &BlankModel_P.SFunction_P1_d, 1, &BlankModel_P.Encoder_dt_enc, 1);
  }

  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* Logic: '<Root>/Logical Operator' */
    BlankModel_B.LogicalOperator_c = !BlankModel_B.LogicalOperator;

    /* Outputs for Enabled SubSystem: '<Root>/Controller' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (rtmIsMajorTimeStep(BlankModel_M)) {
      if (BlankModel_B.LogicalOperator_c) {
        if (!BlankModel_DW.Controller_MODE) {
          BlankModel_DW.Controller_MODE = true;
        }
      } else {
        if (BlankModel_DW.Controller_MODE) {
          BlankModel_DW.Controller_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Controller' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Controller' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (BlankModel_DW.Controller_MODE) {
    /* StateSpace: '<S2>/H INFINITY' */
    BlankModel_B.HINFINITY = 0.0;
    BlankModel_B.HINFINITY += BlankModel_P.HINFINITY_C[0] *
      BlankModel_X.HINFINITY_CSTATE[0];
    BlankModel_B.HINFINITY += BlankModel_P.HINFINITY_C[1] *
      BlankModel_X.HINFINITY_CSTATE[1];
    BlankModel_B.HINFINITY += BlankModel_P.HINFINITY_C[2] *
      BlankModel_X.HINFINITY_CSTATE[2];

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (BlankModel_B.MotorDetector) {
      u0 = BlankModel_B.HINFINITY;
    } else {
      u0 = BlankModel_P.Constant_Value;
    }

    /* End of Switch: '<S2>/Switch' */

    /* Sum: '<S2>/Sum' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S5>/cm-to-encoder'
     *  Sum: '<S5>/Sum'
     */
    BlankModel_B.Sum = (BlankModel_P.cmtoencoder_Gain * BlankModel_B.Product -
                        (real_T)BlankModel_B.SFunction) - BlankModel_P.Gain_Gain
      * u0;
  }

  /* End of Outputs for SubSystem: '<Root>/Controller' */
  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* DataTypeConversion: '<S6>/conversion2' */
    BlankModel_B.conversion2 = (real32_T)BlankModel_B.HINFINITY;

    /* DataTypeConversion: '<S23>/conversion8' */
    BlankModel_B.conversion8 = (real32_T)rtb_Saturation;

    /* Logic: '<S23>/Logical Operator' incorporates:
     *  Logic: '<S21>/Logical Operator'
     */
    BlankModel_B.LogicalOperator_n = ((!BlankModel_B.MotorDetector) &&
      BlankModel_B.SFunction2_o1);

    /* S-Function (sfcn_motor_new): '<S23>/S-Function1' */
    sfcn_motor_new_Outputs_wrapper(&BlankModel_B.conversion8,
      &BlankModel_B.LogicalOperator_n, &BlankModel_B.SFunction1_o1,
      &BlankModel_B.SFunction1_o2, &BlankModel_B.SFunction1_o3,
      &BlankModel_DW.SFunction1_DSTATE, &BlankModel_P.SFunction1_P1, 1,
      &BlankModel_P.SFunction1_P2, 1, &BlankModel_P.SFunction1_P3, 1);

    /* DataTypeConversion: '<S6>/conversion4' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion1'
     */
    BlankModel_B.conversion4 = BlankModel_B.SFunction1_o1;

    /* Gain: '<Root>/encoder-to-cm' */
    tmp = (uint32_T)BlankModel_P.encodertocm_Gain_j;
    tmp_0 = (uint32_T)BlankModel_B.SFunction;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &tmp_1.chunks[0U], 2);

    /* DataTypeConversion: '<S6>/conversion5' */
    BlankModel_B.conversion5 = sMultiWord2Single(&tmp_1.chunks[0U], 2, 0) *
      9.09494702E-13F;

    /* DataTypeConversion: '<S6>/conversion6' */
    BlankModel_B.conversion6 = 0.0F;

    /* DataTypeConversion: '<S6>/conversion7' */
    BlankModel_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S6>/S-Function' */
    SerialTx_Outputs_wrapper(&BlankModel_B.SFunction2_o1, (boolean_T*)
      &BlankModel_BGND, (boolean_T*)&BlankModel_BGND, (boolean_T*)
      &BlankModel_BGND, &BlankModel_B.MotorDetector,
      &BlankModel_B.EncoderDetector, &BlankModel_B.LogicalOperator,
      &BlankModel_B.conversion10, &BlankModel_B.conversion13,
      &BlankModel_B.conversion2, &BlankModel_B.conversion4,
      &BlankModel_B.conversion5, &BlankModel_B.conversion6,
      &BlankModel_B.conversion7, &BlankModel_DW.SFunction_DSTATE_l,
      &BlankModel_P.SFunction_P1, 1, &BlankModel_P.SFunction_P2, 1);
  }

  /* S-Function (sfun_tstart): '<S4>/startTime' */

  /* S-Function Block (sfun_tstart): <S4>/startTime */
  BlankModel_B.startTime = (0.0);
  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S18>/Digital Output' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion'
     */
    MW_digitalWrite(BlankModel_P.DigitalOutput_pinNumber, (uint8_T)
                    BlankModel_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S19>/Digital Output' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion'
     */
    MW_digitalWrite(BlankModel_P.DigitalOutput_pinNumber_l, (uint8_T)
                    BlankModel_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &BlankModel_DW.SFunction1_DSTATE_b);
  }
}

/* Model update function */
void BlankModel_update(void)
{
  if (rtmIsMajorTimeStep(BlankModel_M)) {
    /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
    signals_Update_wrapper( &BlankModel_B.SFunction2_o1,
      &BlankModel_B.SFunction2_o2, &BlankModel_DW.SFunction2_DSTATE);

    /* Update for Memory: '<S8>/Memory' */
    BlankModel_DW.Memory_PreviousInput = BlankModel_B.SFunction;

    /* Update for Memory: '<S10>/Memory1' */
    BlankModel_DW.Memory1_PreviousInput = BlankModel_B.HINFINITY;

    /* Update for Memory: '<S9>/Memory1' */
    BlankModel_DW.Memory1_PreviousInput_m = BlankModel_B.MotorDetector;

    /* S-Function "sfcn_encoder_wrapper" Block: <S22>/S-Function */
    sfcn_encoder_Update_wrapper(&BlankModel_B.EncoderDetector,
      &BlankModel_B.SFunction, &BlankModel_DW.SFunction_DSTATE,
      &BlankModel_P.SFunction_P1_d, 1, &BlankModel_P.Encoder_dt_enc, 1);

    /* S-Function "sfcn_motor_new_wrapper" Block: <S23>/S-Function1 */
    sfcn_motor_new_Update_wrapper(&BlankModel_B.conversion8,
      &BlankModel_B.LogicalOperator_n, &BlankModel_B.SFunction1_o1,
      &BlankModel_B.SFunction1_o2, &BlankModel_B.SFunction1_o3,
      &BlankModel_DW.SFunction1_DSTATE, &BlankModel_P.SFunction1_P1, 1,
      &BlankModel_P.SFunction1_P2, 1, &BlankModel_P.SFunction1_P3, 1);

    /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
    SerialTx_Update_wrapper(&BlankModel_B.SFunction2_o1, (boolean_T*)
      &BlankModel_BGND, (boolean_T*)&BlankModel_BGND, (boolean_T*)
      &BlankModel_BGND, &BlankModel_B.MotorDetector,
      &BlankModel_B.EncoderDetector, &BlankModel_B.LogicalOperator,
      &BlankModel_B.conversion10, &BlankModel_B.conversion13,
      &BlankModel_B.conversion2, &BlankModel_B.conversion4,
      &BlankModel_B.conversion5, &BlankModel_B.conversion6,
      &BlankModel_B.conversion7, &BlankModel_DW.SFunction_DSTATE_l,
      &BlankModel_P.SFunction_P1, 1, &BlankModel_P.SFunction_P2, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&BlankModel_DW.SFunction1_DSTATE_b);
  }

  if (rtmIsMajorTimeStep(BlankModel_M)) {
    rt_ertODEUpdateContinuousStates(&BlankModel_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++BlankModel_M->Timing.clockTick0;
  BlankModel_M->Timing.t[0] = rtsiGetSolverStopTime(&BlankModel_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    BlankModel_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void BlankModel_derivatives(void)
{
  XDot_BlankModel_T *_rtXdot;
  _rtXdot = ((XDot_BlankModel_T *) BlankModel_M->ModelData.derivs);

  /* Derivatives for Enabled SubSystem: '<Root>/Controller' */
  if (BlankModel_DW.Controller_MODE) {
    /* Derivatives for StateSpace: '<S2>/H INFINITY' */
    _rtXdot->HINFINITY_CSTATE[0] = 0.0;
    _rtXdot->HINFINITY_CSTATE[1] = 0.0;
    _rtXdot->HINFINITY_CSTATE[2] = 0.0;
    _rtXdot->HINFINITY_CSTATE[0] += BlankModel_P.HINFINITY_A[0] *
      BlankModel_X.HINFINITY_CSTATE[0];
    _rtXdot->HINFINITY_CSTATE[0] += BlankModel_P.HINFINITY_A[1] *
      BlankModel_X.HINFINITY_CSTATE[1];
    _rtXdot->HINFINITY_CSTATE[0] += BlankModel_P.HINFINITY_A[2] *
      BlankModel_X.HINFINITY_CSTATE[2];
    _rtXdot->HINFINITY_CSTATE[1] += BlankModel_P.HINFINITY_A[3] *
      BlankModel_X.HINFINITY_CSTATE[0];
    _rtXdot->HINFINITY_CSTATE[1] += BlankModel_P.HINFINITY_A[4] *
      BlankModel_X.HINFINITY_CSTATE[1];
    _rtXdot->HINFINITY_CSTATE[1] += BlankModel_P.HINFINITY_A[5] *
      BlankModel_X.HINFINITY_CSTATE[2];
    _rtXdot->HINFINITY_CSTATE[2] += BlankModel_P.HINFINITY_A[6] *
      BlankModel_X.HINFINITY_CSTATE[0];
    _rtXdot->HINFINITY_CSTATE[2] += BlankModel_P.HINFINITY_A[7] *
      BlankModel_X.HINFINITY_CSTATE[1];
    _rtXdot->HINFINITY_CSTATE[2] += BlankModel_P.HINFINITY_A[8] *
      BlankModel_X.HINFINITY_CSTATE[2];
    _rtXdot->HINFINITY_CSTATE[0] += BlankModel_P.HINFINITY_B[0] *
      BlankModel_B.Sum;
    _rtXdot->HINFINITY_CSTATE[1] += BlankModel_P.HINFINITY_B[1] *
      BlankModel_B.Sum;
    _rtXdot->HINFINITY_CSTATE[2] += BlankModel_P.HINFINITY_B[2] *
      BlankModel_B.Sum;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_BlankModel_T *) BlankModel_M->ModelData.derivs)
             ->HINFINITY_CSTATE[0]);
      for (i=0; i < 3; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/Controller' */
}

/* Model initialize function */
void BlankModel_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BlankModel_M, 0,
                sizeof(RT_MODEL_BlankModel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BlankModel_M->solverInfo,
                          &BlankModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&BlankModel_M->solverInfo, &rtmGetTPtr(BlankModel_M));
    rtsiSetStepSizePtr(&BlankModel_M->solverInfo,
                       &BlankModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&BlankModel_M->solverInfo, &BlankModel_M->ModelData.derivs);
    rtsiSetContStatesPtr(&BlankModel_M->solverInfo, (real_T **)
                         &BlankModel_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&BlankModel_M->solverInfo,
      &BlankModel_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&BlankModel_M->solverInfo, (&rtmGetErrorStatus
      (BlankModel_M)));
    rtsiSetRTModelPtr(&BlankModel_M->solverInfo, BlankModel_M);
  }

  rtsiSetSimTimeStep(&BlankModel_M->solverInfo, MAJOR_TIME_STEP);
  BlankModel_M->ModelData.intgData.y = BlankModel_M->ModelData.odeY;
  BlankModel_M->ModelData.intgData.f[0] = BlankModel_M->ModelData.odeF[0];
  BlankModel_M->ModelData.intgData.f[1] = BlankModel_M->ModelData.odeF[1];
  BlankModel_M->ModelData.intgData.f[2] = BlankModel_M->ModelData.odeF[2];
  BlankModel_M->ModelData.contStates = ((X_BlankModel_T *) &BlankModel_X);
  rtsiSetSolverData(&BlankModel_M->solverInfo, (void *)
                    &BlankModel_M->ModelData.intgData);
  rtsiSetSolverName(&BlankModel_M->solverInfo,"ode3");
  rtmSetTPtr(BlankModel_M, &BlankModel_M->Timing.tArray[0]);
  BlankModel_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &BlankModel_B), 0,
                sizeof(B_BlankModel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&BlankModel_X, 0,
                  sizeof(X_BlankModel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&BlankModel_DW, 0,
                sizeof(DW_BlankModel_T));

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S13>/S-Function' */
  MW_pinModeInput(BlankModel_P.SFunction_p1);

  /* InitializeConditions for Enabled SubSystem: '<Root>/Controller' */
  /* InitializeConditions for StateSpace: '<S2>/H INFINITY' */
  BlankModel_X.HINFINITY_CSTATE[0] = BlankModel_P.HINFINITY_X0;
  BlankModel_X.HINFINITY_CSTATE[1] = BlankModel_P.HINFINITY_X0;
  BlankModel_X.HINFINITY_CSTATE[2] = BlankModel_P.HINFINITY_X0;

  /* End of InitializeConditions for SubSystem: '<Root>/Controller' */

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S18>/Digital Output' */
  MW_pinModeOutput(BlankModel_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S19>/Digital Output' */
  MW_pinModeOutput(BlankModel_P.DigitalOutput_pinNumber_l);

  /* S-Function Block: <S3>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BlankModel_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Chart: '<S7>/Init Manager' */
  BlankModel_DW.temporalCounter_i1 = 0U;
  BlankModel_DW.is_active_c1_BlankModel = 0U;
  BlankModel_DW.is_c1_BlankModel = BlankModel_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Memory: '<S8>/Memory' */
  BlankModel_DW.Memory_PreviousInput = BlankModel_P.Memory_X0;

  /* InitializeConditions for Memory: '<S10>/Memory1' */
  BlankModel_DW.Memory1_PreviousInput = BlankModel_P.Memory1_X0;

  /* InitializeConditions for Chart: '<S7>/Alert Manager' */
  BlankModel_DW.is_active_c3_BlankModel = 0U;
  BlankModel_DW.is_c3_BlankModel = BlankModel_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Memory: '<S9>/Memory1' */
  BlankModel_DW.Memory1_PreviousInput_m = BlankModel_P.Memory1_X0_p;

  /* S-Function Block: <S22>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BlankModel_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S23>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BlankModel_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BlankModel_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BlankModel_DW.SFunction1_DSTATE_b = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void BlankModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
