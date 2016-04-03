/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EncoderTest.c
 *
 * Code generated for Simulink model 'EncoderTest'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Tue Mar 15 13:25:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EncoderTest.h"
#include "EncoderTest_private.h"

const boolean_T EncoderTest_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_EncoderTest_T EncoderTest_B;

/* Block states (auto storage) */
DW_EncoderTest_T EncoderTest_DW;

/* Real-time model */
RT_MODEL_EncoderTest_T EncoderTest_M_;
RT_MODEL_EncoderTest_T *const EncoderTest_M = &EncoderTest_M_;

/* Model step function */
void EncoderTest_step(void)
{
  /* S-Function (signals): '<S5>/S-Function2' */
  signals_Outputs_wrapper( &EncoderTest_B.SFunction2_o1,
    &EncoderTest_B.SFunction2_o2, &EncoderTest_DW.SFunction2_DSTATE);

  /* DataTypeConversion: '<S6>/conversion1' */
  EncoderTest_B.conversion1 = false;

  /* DataTypeConversion: '<S6>/conversion3' */
  EncoderTest_B.conversion3 = false;

  /* DataTypeConversion: '<S6>/conversion9' */
  EncoderTest_B.conversion9 = false;

  /* DataTypeConversion: '<S6>/conversion10' */
  EncoderTest_B.conversion10 = false;

  /* DataTypeConversion: '<S6>/conversion13' */
  EncoderTest_B.conversion13 = 0.0F;

  /* DataTypeConversion: '<S6>/conversion2' */
  EncoderTest_B.conversion2 = 0.0F;

  /* DataTypeConversion: '<S6>/conversion4' */
  EncoderTest_B.conversion4 = 0.0F;

  /* S-Function (arduinodigitalinput_sfcn): '<S1>/S-Function' */
  EncoderTest_B.SFunction_h = MW_digitalRead(EncoderTest_P.SFunction_p1);

  /* S-Function (sfcn_encoder): '<S2>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&EncoderTest_B.SFunction_h,
    &EncoderTest_B.SFunction, &EncoderTest_DW.SFunction_DSTATE,
    &EncoderTest_P.SFunction_P1_h, 1, &EncoderTest_P.Encoder_dt_enc, 1);

  /* DataTypeConversion: '<S6>/conversion5' */
  EncoderTest_B.conversion5 = (real32_T)EncoderTest_B.SFunction;

  /* S-Function (sfcn_encoder): '<S3>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&EncoderTest_B.SFunction_h,
    &EncoderTest_B.SFunction_l, &EncoderTest_DW.SFunction_DSTATE_p,
    &EncoderTest_P.SFunction_P1_hv, 1, &EncoderTest_P.Encoder1_dt_enc, 1);

  /* DataTypeConversion: '<S6>/conversion6' */
  EncoderTest_B.conversion6 = (real32_T)EncoderTest_B.SFunction_l;

  /* S-Function (sfcn_encoder): '<S4>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&EncoderTest_B.SFunction_h,
    &EncoderTest_B.SFunction_f, &EncoderTest_DW.SFunction_DSTATE_m,
    &EncoderTest_P.SFunction_P1_n, 1, &EncoderTest_P.Encoder2_dt_enc, 1);

  /* DataTypeConversion: '<S6>/conversion7' */
  EncoderTest_B.conversion7 = (real32_T)EncoderTest_B.SFunction_f;

  /* S-Function (SerialTx): '<S6>/S-Function' */
  SerialTx_Outputs_wrapper(&EncoderTest_B.SFunction2_o1, (boolean_T*)
    &EncoderTest_BGND, (boolean_T*)&EncoderTest_BGND, (boolean_T*)
    &EncoderTest_BGND, &EncoderTest_B.conversion1, &EncoderTest_B.conversion3,
    &EncoderTest_B.conversion9, &EncoderTest_B.conversion10,
    &EncoderTest_B.conversion13, &EncoderTest_B.conversion2,
    &EncoderTest_B.conversion4, &EncoderTest_B.conversion5,
    &EncoderTest_B.conversion6, &EncoderTest_B.conversion7,
    &EncoderTest_DW.SFunction_DSTATE_l, &EncoderTest_P.SFunction_P1, 1,
    &EncoderTest_P.SFunction_P2, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  MW_digitalWrite(EncoderTest_P.DigitalOutput_pinNumber, (uint8_T)
                  EncoderTest_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  MW_digitalWrite(EncoderTest_P.DigitalOutput_pinNumber_e, (uint8_T)
                  EncoderTest_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S5>/S-Function1' */
  data_struct_init_Outputs_wrapper( &EncoderTest_DW.SFunction1_DSTATE);

  /* S-Function "signals_wrapper" Block: <S5>/S-Function2 */
  signals_Update_wrapper( &EncoderTest_B.SFunction2_o1,
    &EncoderTest_B.SFunction2_o2, &EncoderTest_DW.SFunction2_DSTATE);

  /* S-Function "sfcn_encoder_wrapper" Block: <S2>/S-Function */
  sfcn_encoder_Update_wrapper(&EncoderTest_B.SFunction_h,
    &EncoderTest_B.SFunction, &EncoderTest_DW.SFunction_DSTATE,
    &EncoderTest_P.SFunction_P1_h, 1, &EncoderTest_P.Encoder_dt_enc, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S3>/S-Function */
  sfcn_encoder_Update_wrapper(&EncoderTest_B.SFunction_h,
    &EncoderTest_B.SFunction_l, &EncoderTest_DW.SFunction_DSTATE_p,
    &EncoderTest_P.SFunction_P1_hv, 1, &EncoderTest_P.Encoder1_dt_enc, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S4>/S-Function */
  sfcn_encoder_Update_wrapper(&EncoderTest_B.SFunction_h,
    &EncoderTest_B.SFunction_f, &EncoderTest_DW.SFunction_DSTATE_m,
    &EncoderTest_P.SFunction_P1_n, 1, &EncoderTest_P.Encoder2_dt_enc, 1);

  /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
  SerialTx_Update_wrapper(&EncoderTest_B.SFunction2_o1, (boolean_T*)
    &EncoderTest_BGND, (boolean_T*)&EncoderTest_BGND, (boolean_T*)
    &EncoderTest_BGND, &EncoderTest_B.conversion1, &EncoderTest_B.conversion3,
    &EncoderTest_B.conversion9, &EncoderTest_B.conversion10,
    &EncoderTest_B.conversion13, &EncoderTest_B.conversion2,
    &EncoderTest_B.conversion4, &EncoderTest_B.conversion5,
    &EncoderTest_B.conversion6, &EncoderTest_B.conversion7,
    &EncoderTest_DW.SFunction_DSTATE_l, &EncoderTest_P.SFunction_P1, 1,
    &EncoderTest_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S5>/S-Function1 */
  data_struct_init_Update_wrapper(&EncoderTest_DW.SFunction1_DSTATE);
}

/* Model initialize function */
void EncoderTest_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(EncoderTest_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &EncoderTest_B), 0,
                sizeof(B_EncoderTest_T));

  /* states (dwork) */
  (void) memset((void *)&EncoderTest_DW, 0,
                sizeof(DW_EncoderTest_T));

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S1>/S-Function' */
  MW_pinModeInput(EncoderTest_P.SFunction_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' */
  MW_pinModeOutput(EncoderTest_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_pinModeOutput(EncoderTest_P.DigitalOutput_pinNumber_e);

  /* S-Function Block: <S5>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        EncoderTest_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S2>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        EncoderTest_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        EncoderTest_DW.SFunction_DSTATE_p = initVector[0];
      }
    }
  }

  /* S-Function Block: <S4>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        EncoderTest_DW.SFunction_DSTATE_m = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        EncoderTest_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S5>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        EncoderTest_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void EncoderTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
