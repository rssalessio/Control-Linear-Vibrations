/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dynamic.c
 *
 * Code generated for Simulink model 'dynamic'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 18:34:38 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dynamic.h"
#include "dynamic_private.h"

const boolean_T dynamic_BGND = false;  /* boolean_T ground */

/* Block signals (auto storage) */
B_dynamic_T dynamic_B;

/* Block states (auto storage) */
DW_dynamic_T dynamic_DW;

/* Real-time model */
RT_MODEL_dynamic_T dynamic_M_;
RT_MODEL_dynamic_T *const dynamic_M = &dynamic_M_;

/* Model output function */
void dynamic_output(void)
{
  boolean_T rtb_SFunction_0;
  real_T rtb_Sum;

  /* S-Function (signals): '<S5>/S-Function2' */
  signals_Outputs_wrapper( &dynamic_B.SFunction2_o1, &dynamic_B.SFunction2_o2,
    &dynamic_DW.SFunction2_DSTATE);

  /* DataTypeConversion: '<S6>/conversion1' */
  dynamic_B.conversion1 = false;

  /* DataTypeConversion: '<S6>/conversion3' */
  dynamic_B.conversion3 = false;

  /* DataTypeConversion: '<S6>/conversion9' */
  dynamic_B.conversion9 = false;

  /* DataTypeConversion: '<S6>/conversion10' */
  dynamic_B.conversion10 = false;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Sum = (dynamic_DW.clockTickCounter < dynamic_P.PulseGenerator_Duty) &&
    (dynamic_DW.clockTickCounter >= 0) ? dynamic_P.PulseGenerator_Amp : 0.0;
  if (dynamic_DW.clockTickCounter >= dynamic_P.PulseGenerator_Period - 1.0) {
    dynamic_DW.clockTickCounter = 0;
  } else {
    dynamic_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum -= dynamic_P.Constant_Value;

  /* DataTypeConversion: '<S6>/conversion13' */
  dynamic_B.conversion13 = (real32_T)rtb_Sum;

  /* DataTypeConversion: '<S3>/conversion8' */
  dynamic_B.conversion8 = (real32_T)rtb_Sum;

  /* S-Function (arduinodigitalinput_sfcn): '<S4>/S-Function' */
  rtb_SFunction_0 = MW_digitalRead(dynamic_P.SFunction_p1);

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  S-Function (arduinodigitalinput_sfcn): '<S4>/S-Function'
   */
  dynamic_B.LogicalOperator = (rtb_SFunction_0 && dynamic_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S3>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&dynamic_B.conversion8,
    &dynamic_B.LogicalOperator, &dynamic_B.SFunction1_o1,
    &dynamic_B.SFunction1_o2, &dynamic_B.SFunction1_o3,
    &dynamic_DW.SFunction1_DSTATE, &dynamic_P.SFunction1_P1, 1,
    &dynamic_P.SFunction1_P2, 1, &dynamic_P.SFunction1_P3, 1);

  /* S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function' */
  dynamic_B.SFunction_b = MW_digitalRead(dynamic_P.SFunction_p1_f);

  /* S-Function (sfcn_encoder): '<S1>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&dynamic_B.SFunction_b, &dynamic_B.SFunction,
    &dynamic_DW.SFunction_DSTATE, &dynamic_P.SFunction_P1_h, 1,
    &dynamic_P.Encoder_dt_enc, 1);

  /* DataTypeConversion: '<S6>/conversion4' */
  dynamic_B.conversion4 = (real32_T)dynamic_B.SFunction;

  /* DataTypeConversion: '<S6>/conversion5' */
  dynamic_B.conversion5 = 0.0F;

  /* DataTypeConversion: '<S6>/conversion6' */
  dynamic_B.conversion6 = 0.0F;

  /* DataTypeConversion: '<S6>/conversion7' */
  dynamic_B.conversion7 = 0.0F;

  /* S-Function (SerialTx): '<S6>/S-Function' */
  SerialTx_Outputs_wrapper(&dynamic_B.SFunction2_o1, (boolean_T*)&dynamic_BGND,
    (boolean_T*)&dynamic_BGND, (boolean_T*)&dynamic_BGND, &dynamic_B.conversion1,
    &dynamic_B.conversion3, &dynamic_B.conversion9, &dynamic_B.conversion10,
    &dynamic_B.conversion13, &dynamic_B.SFunction1_o1, &dynamic_B.conversion4,
    &dynamic_B.conversion5, &dynamic_B.conversion6, &dynamic_B.conversion7,
    &dynamic_DW.SFunction_DSTATE_d, &dynamic_P.SFunction_P1, 1,
    &dynamic_P.SFunction_P2, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  MW_digitalWrite(dynamic_P.DigitalOutput_pinNumber, (uint8_T)
                  dynamic_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  MW_digitalWrite(dynamic_P.DigitalOutput_pinNumber_j, (uint8_T)
                  dynamic_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S5>/S-Function1' */
  data_struct_init_Outputs_wrapper( &dynamic_DW.SFunction1_DSTATE_d);
}

/* Model update function */
void dynamic_update(void)
{
  /* S-Function "signals_wrapper" Block: <S5>/S-Function2 */
  signals_Update_wrapper( &dynamic_B.SFunction2_o1, &dynamic_B.SFunction2_o2,
    &dynamic_DW.SFunction2_DSTATE);

  /* S-Function "sfcn_motor_new_wrapper" Block: <S3>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&dynamic_B.conversion8,
    &dynamic_B.LogicalOperator, &dynamic_B.SFunction1_o1,
    &dynamic_B.SFunction1_o2, &dynamic_B.SFunction1_o3,
    &dynamic_DW.SFunction1_DSTATE, &dynamic_P.SFunction1_P1, 1,
    &dynamic_P.SFunction1_P2, 1, &dynamic_P.SFunction1_P3, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S1>/S-Function */
  sfcn_encoder_Update_wrapper(&dynamic_B.SFunction_b, &dynamic_B.SFunction,
    &dynamic_DW.SFunction_DSTATE, &dynamic_P.SFunction_P1_h, 1,
    &dynamic_P.Encoder_dt_enc, 1);

  /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
  SerialTx_Update_wrapper(&dynamic_B.SFunction2_o1, (boolean_T*)&dynamic_BGND,
    (boolean_T*)&dynamic_BGND, (boolean_T*)&dynamic_BGND, &dynamic_B.conversion1,
    &dynamic_B.conversion3, &dynamic_B.conversion9, &dynamic_B.conversion10,
    &dynamic_B.conversion13, &dynamic_B.SFunction1_o1, &dynamic_B.conversion4,
    &dynamic_B.conversion5, &dynamic_B.conversion6, &dynamic_B.conversion7,
    &dynamic_DW.SFunction_DSTATE_d, &dynamic_P.SFunction_P1, 1,
    &dynamic_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S5>/S-Function1 */
  data_struct_init_Update_wrapper(&dynamic_DW.SFunction1_DSTATE_d);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  dynamic_M->Timing.t[0] =
    (++dynamic_M->Timing.clockTick0) * dynamic_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    dynamic_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void dynamic_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)dynamic_M, 0,
                sizeof(RT_MODEL_dynamic_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dynamic_M->solverInfo, &dynamic_M->Timing.simTimeStep);
    rtsiSetTPtr(&dynamic_M->solverInfo, &rtmGetTPtr(dynamic_M));
    rtsiSetStepSizePtr(&dynamic_M->solverInfo, &dynamic_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&dynamic_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(dynamic_M))));
    rtsiSetRTModelPtr(&dynamic_M->solverInfo, dynamic_M);
  }

  rtsiSetSimTimeStep(&dynamic_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&dynamic_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(dynamic_M, &dynamic_M->Timing.tArray[0]);
  dynamic_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &dynamic_B), 0,
                sizeof(B_dynamic_T));

  /* states (dwork) */
  (void) memset((void *)&dynamic_DW, 0,
                sizeof(DW_dynamic_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  dynamic_DW.clockTickCounter = 0;

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S4>/S-Function' */
  MW_pinModeInput(dynamic_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function' */
  MW_pinModeInput(dynamic_P.SFunction_p1_f);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' */
  MW_pinModeOutput(dynamic_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_pinModeOutput(dynamic_P.DigitalOutput_pinNumber_j);

  /* S-Function Block: <S5>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        dynamic_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        dynamic_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S1>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        dynamic_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        dynamic_DW.SFunction_DSTATE_d = initVector[0];
      }
    }
  }

  /* S-Function Block: <S5>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        dynamic_DW.SFunction1_DSTATE_d = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void dynamic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
