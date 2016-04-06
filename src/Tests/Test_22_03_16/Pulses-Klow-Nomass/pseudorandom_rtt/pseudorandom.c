/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pseudorandom.c
 *
 * Code generated for Simulink model 'pseudorandom'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 17:39:15 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pseudorandom.h"
#include "pseudorandom_private.h"

const boolean_T pseudorandom_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_pseudorandom_T pseudorandom_B;

/* Block states (auto storage) */
DW_pseudorandom_T pseudorandom_DW;

/* Real-time model */
RT_MODEL_pseudorandom_T pseudorandom_M_;
RT_MODEL_pseudorandom_T *const pseudorandom_M = &pseudorandom_M_;
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
void pseudorandom_output(void)
{
  boolean_T rtb_SFunction_0;
  real_T rtb_Saturation;

  /* S-Function (signals): '<S6>/S-Function2' */
  signals_Outputs_wrapper( &pseudorandom_B.SFunction2_o1,
    &pseudorandom_B.SFunction2_o2, &pseudorandom_DW.SFunction2_DSTATE);

  /* DataTypeConversion: '<S7>/conversion1' */
  pseudorandom_B.conversion1 = false;

  /* DataTypeConversion: '<S7>/conversion3' */
  pseudorandom_B.conversion3 = false;

  /* DataTypeConversion: '<S7>/conversion9' */
  pseudorandom_B.conversion9 = false;

  /* DataTypeConversion: '<S7>/conversion10' */
  pseudorandom_B.conversion10 = false;

  /* Gain: '<S1>/Output' incorporates:
   *  RandomNumber: '<S1>/White Noise'
   */
  rtb_Saturation = pseudorandom_P.Output_Gain * pseudorandom_DW.NextOutput;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > pseudorandom_P.Saturation_UpperSat) {
    rtb_Saturation = pseudorandom_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < pseudorandom_P.Saturation_LowerSat) {
      rtb_Saturation = pseudorandom_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<S7>/conversion13' */
  pseudorandom_B.conversion13 = (real32_T)rtb_Saturation;

  /* DataTypeConversion: '<S4>/conversion8' */
  pseudorandom_B.conversion8 = (real32_T)rtb_Saturation;

  /* S-Function (arduinodigitalinput_sfcn): '<S5>/S-Function' */
  rtb_SFunction_0 = MW_digitalRead(pseudorandom_P.SFunction_p1);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  S-Function (arduinodigitalinput_sfcn): '<S5>/S-Function'
   */
  pseudorandom_B.LogicalOperator = (rtb_SFunction_0 &&
    pseudorandom_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S4>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&pseudorandom_B.conversion8,
    &pseudorandom_B.LogicalOperator, &pseudorandom_B.SFunction1_o1,
    &pseudorandom_B.SFunction1_o2, &pseudorandom_B.SFunction1_o3,
    &pseudorandom_DW.SFunction1_DSTATE, &pseudorandom_P.SFunction1_P1, 1,
    &pseudorandom_P.SFunction1_P2, 1, &pseudorandom_P.SFunction1_P3, 1);

  /* S-Function (arduinodigitalinput_sfcn): '<S3>/S-Function' */
  pseudorandom_B.SFunction_b = MW_digitalRead(pseudorandom_P.SFunction_p1_f);

  /* S-Function (sfcn_encoder): '<S2>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&pseudorandom_B.SFunction_b,
    &pseudorandom_B.SFunction, &pseudorandom_DW.SFunction_DSTATE,
    &pseudorandom_P.SFunction_P1_h, 1, &pseudorandom_P.Encoder_dt_enc, 1);

  /* DataTypeConversion: '<S7>/conversion4' */
  pseudorandom_B.conversion4 = (real32_T)pseudorandom_B.SFunction;

  /* DataTypeConversion: '<S7>/conversion5' */
  pseudorandom_B.conversion5 = 0.0F;

  /* DataTypeConversion: '<S7>/conversion6' */
  pseudorandom_B.conversion6 = 0.0F;

  /* DataTypeConversion: '<S7>/conversion7' */
  pseudorandom_B.conversion7 = 0.0F;

  /* S-Function (SerialTx): '<S7>/S-Function' */
  SerialTx_Outputs_wrapper(&pseudorandom_B.SFunction2_o1, (boolean_T*)
    &pseudorandom_BGND, (boolean_T*)&pseudorandom_BGND, (boolean_T*)
    &pseudorandom_BGND, &pseudorandom_B.conversion1, &pseudorandom_B.conversion3,
    &pseudorandom_B.conversion9, &pseudorandom_B.conversion10,
    &pseudorandom_B.conversion13, &pseudorandom_B.SFunction1_o1,
    &pseudorandom_B.conversion4, &pseudorandom_B.conversion5,
    &pseudorandom_B.conversion6, &pseudorandom_B.conversion7,
    &pseudorandom_DW.SFunction_DSTATE_d, &pseudorandom_P.SFunction_P1, 1,
    &pseudorandom_P.SFunction_P2, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  MW_digitalWrite(pseudorandom_P.DigitalOutput_pinNumber, (uint8_T)
                  pseudorandom_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  MW_digitalWrite(pseudorandom_P.DigitalOutput_pinNumber_j, (uint8_T)
                  pseudorandom_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S6>/S-Function1' */
  data_struct_init_Outputs_wrapper( &pseudorandom_DW.SFunction1_DSTATE_d);
}

/* Model update function */
void pseudorandom_update(void)
{
  /* S-Function "signals_wrapper" Block: <S6>/S-Function2 */
  signals_Update_wrapper( &pseudorandom_B.SFunction2_o1,
    &pseudorandom_B.SFunction2_o2, &pseudorandom_DW.SFunction2_DSTATE);

  /* Update for RandomNumber: '<S1>/White Noise' */
  pseudorandom_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&pseudorandom_DW.RandSeed) * pseudorandom_P.WhiteNoise_StdDev +
    pseudorandom_P.WhiteNoise_Mean;

  /* S-Function "sfcn_motor_new_wrapper" Block: <S4>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&pseudorandom_B.conversion8,
    &pseudorandom_B.LogicalOperator, &pseudorandom_B.SFunction1_o1,
    &pseudorandom_B.SFunction1_o2, &pseudorandom_B.SFunction1_o3,
    &pseudorandom_DW.SFunction1_DSTATE, &pseudorandom_P.SFunction1_P1, 1,
    &pseudorandom_P.SFunction1_P2, 1, &pseudorandom_P.SFunction1_P3, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S2>/S-Function */
  sfcn_encoder_Update_wrapper(&pseudorandom_B.SFunction_b,
    &pseudorandom_B.SFunction, &pseudorandom_DW.SFunction_DSTATE,
    &pseudorandom_P.SFunction_P1_h, 1, &pseudorandom_P.Encoder_dt_enc, 1);

  /* S-Function "SerialTx_wrapper" Block: <S7>/S-Function */
  SerialTx_Update_wrapper(&pseudorandom_B.SFunction2_o1, (boolean_T*)
    &pseudorandom_BGND, (boolean_T*)&pseudorandom_BGND, (boolean_T*)
    &pseudorandom_BGND, &pseudorandom_B.conversion1, &pseudorandom_B.conversion3,
    &pseudorandom_B.conversion9, &pseudorandom_B.conversion10,
    &pseudorandom_B.conversion13, &pseudorandom_B.SFunction1_o1,
    &pseudorandom_B.conversion4, &pseudorandom_B.conversion5,
    &pseudorandom_B.conversion6, &pseudorandom_B.conversion7,
    &pseudorandom_DW.SFunction_DSTATE_d, &pseudorandom_P.SFunction_P1, 1,
    &pseudorandom_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S6>/S-Function1 */
  data_struct_init_Update_wrapper(&pseudorandom_DW.SFunction1_DSTATE_d);
}

/* Model initialize function */
void pseudorandom_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(pseudorandom_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &pseudorandom_B), 0,
                sizeof(B_pseudorandom_T));

  /* states (dwork) */
  (void) memset((void *)&pseudorandom_DW, 0,
                sizeof(DW_pseudorandom_T));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for S-Function (arduinodigitalinput_sfcn): '<S5>/S-Function' */
    MW_pinModeInput(pseudorandom_P.SFunction_p1);

    /* Start for S-Function (arduinodigitalinput_sfcn): '<S3>/S-Function' */
    MW_pinModeInput(pseudorandom_P.SFunction_p1_f);

    /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
    MW_pinModeOutput(pseudorandom_P.DigitalOutput_pinNumber);

    /* Start for S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' */
    MW_pinModeOutput(pseudorandom_P.DigitalOutput_pinNumber_j);

    /* S-Function Block: <S6>/S-Function2 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          pseudorandom_DW.SFunction2_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(pseudorandom_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    pseudorandom_DW.RandSeed = tseed;
    pseudorandom_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&pseudorandom_DW.RandSeed) * pseudorandom_P.WhiteNoise_StdDev +
      pseudorandom_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* S-Function Block: <S4>/S-Function1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          pseudorandom_DW.SFunction1_DSTATE = initVector[0];
        }
      }
    }

    /* S-Function Block: <S2>/S-Function */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          pseudorandom_DW.SFunction_DSTATE = initVector[0];
        }
      }
    }

    /* S-Function Block: <S7>/S-Function */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          pseudorandom_DW.SFunction_DSTATE_d = initVector[0];
        }
      }
    }

    /* S-Function Block: <S6>/S-Function1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          pseudorandom_DW.SFunction1_DSTATE_d = initVector[0];
        }
      }
    }
  }
}

/* Model terminate function */
void pseudorandom_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
