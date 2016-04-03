/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorTest.c
 *
 * Code generated for Simulink model 'MotorTest'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Mar 22 17:04:47 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorTest.h"
#include "MotorTest_private.h"

const boolean_T MotorTest_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_MotorTest_T MotorTest_B;

/* Block states (auto storage) */
DW_MotorTest_T MotorTest_DW;

/* Real-time model */
RT_MODEL_MotorTest_T MotorTest_M_;
RT_MODEL_MotorTest_T *const MotorTest_M = &MotorTest_M_;
static void rate_monotonic_scheduler(void);

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MotorTest_M->Timing.TaskCounters.TID[2])++;
  if ((MotorTest_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    MotorTest_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void MotorTest_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  boolean_T rtb_SFunction_f_0;
  real_T rtb_Sum;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function' */
  MW_analogRead(MotorTest_P.SFunction_p1);

  /* S-Function (signals): '<S8>/S-Function2' */
  signals_Outputs_wrapper( &MotorTest_B.SFunction2_o1,
    &MotorTest_B.SFunction2_o2, &MotorTest_DW.SFunction2_DSTATE);

  /* DataTypeConversion: '<S9>/conversion1' */
  MotorTest_B.conversion1 = false;

  /* DataTypeConversion: '<S9>/conversion3' */
  MotorTest_B.conversion3 = false;

  /* DataTypeConversion: '<S9>/conversion9' */
  MotorTest_B.conversion9 = false;

  /* DataTypeConversion: '<S9>/conversion10' */
  MotorTest_B.conversion10 = false;

  /* DataTypeConversion: '<S9>/conversion13' */
  MotorTest_B.conversion13 = 0.0F;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Sum = (MotorTest_DW.clockTickCounter < MotorTest_P.PulseGenerator_Duty) &&
    (MotorTest_DW.clockTickCounter >= 0) ? MotorTest_P.PulseGenerator_Amp : 0.0;
  if (MotorTest_DW.clockTickCounter >= MotorTest_P.PulseGenerator_Period - 1.0)
  {
    MotorTest_DW.clockTickCounter = 0;
  } else {
    MotorTest_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Sum -= MotorTest_P.Constant1_Value;

  /* DataTypeConversion: '<S9>/conversion2' */
  MotorTest_B.conversion2 = (real32_T)rtb_Sum;

  /* DataTypeConversion: '<S7>/conversion8' */
  MotorTest_B.conversion8 = (real32_T)rtb_Sum;

  /* S-Function (arduinodigitalinput_sfcn): '<S5>/S-Function' */
  rtb_SFunction_f_0 = MW_digitalRead(MotorTest_P.SFunction_p1_l);

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  S-Function (arduinodigitalinput_sfcn): '<S5>/S-Function'
   */
  MotorTest_B.LogicalOperator = (rtb_SFunction_f_0 && MotorTest_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S7>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&MotorTest_B.conversion8,
    &MotorTest_B.LogicalOperator, &MotorTest_B.SFunction1_o1,
    &MotorTest_B.SFunction1_o2, &MotorTest_B.SFunction1_o3,
    &MotorTest_DW.SFunction1_DSTATE, &MotorTest_P.SFunction1_P1, 1,
    &MotorTest_P.SFunction1_P2, 1, &MotorTest_P.SFunction1_P3, 1);

  /* S-Function (arduinodigitalinput_sfcn): '<S4>/S-Function' */
  MotorTest_B.SFunction_d = MW_digitalRead(MotorTest_P.SFunction_p1_l0);

  /* S-Function (sfcn_encoder): '<S6>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&MotorTest_B.SFunction_d, &MotorTest_B.SFunction,
    &MotorTest_DW.SFunction_DSTATE, &MotorTest_P.SFunction_P1_h, 1,
    &MotorTest_P.Encoder_dt_enc, 1);

  /* DataTypeConversion: '<S9>/conversion5' */
  MotorTest_B.conversion5 = (real32_T)MotorTest_B.SFunction;

  /* DataTypeConversion: '<S9>/conversion6' */
  MotorTest_B.conversion6 = 0.0F;

  /* DataTypeConversion: '<S9>/conversion7' */
  MotorTest_B.conversion7 = (real32_T)MotorTest_B.SFunction;

  /* S-Function (SerialTx): '<S9>/S-Function' */
  SerialTx_Outputs_wrapper(&MotorTest_B.SFunction2_o1, (boolean_T*)
    &MotorTest_BGND, (boolean_T*)&MotorTest_BGND, (boolean_T*)&MotorTest_BGND,
    &MotorTest_B.conversion1, &MotorTest_B.conversion3, &MotorTest_B.conversion9,
    &MotorTest_B.conversion10, &MotorTest_B.conversion13,
    &MotorTest_B.conversion2, &MotorTest_B.SFunction1_o1,
    &MotorTest_B.conversion5, &MotorTest_B.conversion6, &MotorTest_B.conversion7,
    &MotorTest_DW.SFunction_DSTATE_l, &MotorTest_P.SFunction_P1, 1,
    &MotorTest_P.SFunction_P2, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   */
  MW_digitalWrite(MotorTest_P.DigitalOutput_pinNumber, (uint8_T)
                  MotorTest_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   */
  MW_digitalWrite(MotorTest_P.DigitalOutput_pinNumber_f, (uint8_T)
                  MotorTest_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S8>/S-Function1' */
  data_struct_init_Outputs_wrapper( &MotorTest_DW.SFunction1_DSTATE_f);
}

/* Model update function for TID0 */
void MotorTest_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* S-Function "signals_wrapper" Block: <S8>/S-Function2 */
  signals_Update_wrapper( &MotorTest_B.SFunction2_o1, &MotorTest_B.SFunction2_o2,
    &MotorTest_DW.SFunction2_DSTATE);

  /* S-Function "sfcn_motor_new_wrapper" Block: <S7>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&MotorTest_B.conversion8,
    &MotorTest_B.LogicalOperator, &MotorTest_B.SFunction1_o1,
    &MotorTest_B.SFunction1_o2, &MotorTest_B.SFunction1_o3,
    &MotorTest_DW.SFunction1_DSTATE, &MotorTest_P.SFunction1_P1, 1,
    &MotorTest_P.SFunction1_P2, 1, &MotorTest_P.SFunction1_P3, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S6>/S-Function */
  sfcn_encoder_Update_wrapper(&MotorTest_B.SFunction_d, &MotorTest_B.SFunction,
    &MotorTest_DW.SFunction_DSTATE, &MotorTest_P.SFunction_P1_h, 1,
    &MotorTest_P.Encoder_dt_enc, 1);

  /* S-Function "SerialTx_wrapper" Block: <S9>/S-Function */
  SerialTx_Update_wrapper(&MotorTest_B.SFunction2_o1, (boolean_T*)
    &MotorTest_BGND, (boolean_T*)&MotorTest_BGND, (boolean_T*)&MotorTest_BGND,
    &MotorTest_B.conversion1, &MotorTest_B.conversion3, &MotorTest_B.conversion9,
    &MotorTest_B.conversion10, &MotorTest_B.conversion13,
    &MotorTest_B.conversion2, &MotorTest_B.SFunction1_o1,
    &MotorTest_B.conversion5, &MotorTest_B.conversion6, &MotorTest_B.conversion7,
    &MotorTest_DW.SFunction_DSTATE_l, &MotorTest_P.SFunction_P1, 1,
    &MotorTest_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S8>/S-Function1 */
  data_struct_init_Update_wrapper(&MotorTest_DW.SFunction1_DSTATE_f);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  MotorTest_M->Timing.t[0] =
    (++MotorTest_M->Timing.clockTick0) * MotorTest_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  MotorTest_M->Timing.clockTick1++;
}

/* Model output function for TID2 */
void MotorTest_output2(void)           /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void MotorTest_update2(void)           /* Sample time: [0.1s, 0.0s] */
{
  /* (no update code required) */
}

/* Model initialize function */
void MotorTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MotorTest_M, 0,
                sizeof(RT_MODEL_MotorTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MotorTest_M->solverInfo,
                          &MotorTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&MotorTest_M->solverInfo, &rtmGetTPtr(MotorTest_M));
    rtsiSetStepSizePtr(&MotorTest_M->solverInfo, &MotorTest_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MotorTest_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(MotorTest_M))));
    rtsiSetRTModelPtr(&MotorTest_M->solverInfo, MotorTest_M);
  }

  rtsiSetSimTimeStep(&MotorTest_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&MotorTest_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(MotorTest_M, &MotorTest_M->Timing.tArray[0]);
  MotorTest_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &MotorTest_B), 0,
                sizeof(B_MotorTest_T));

  /* states (dwork) */
  (void) memset((void *)&MotorTest_DW, 0,
                sizeof(DW_MotorTest_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/S-Function' */
  MW_pinModeAnalogInput(MotorTest_P.SFunction_p1);

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  MotorTest_DW.clockTickCounter = 0;

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S5>/S-Function' */
  MW_pinModeInput(MotorTest_P.SFunction_p1_l);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S4>/S-Function' */
  MW_pinModeInput(MotorTest_P.SFunction_p1_l0);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' */
  MW_pinModeOutput(MotorTest_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' */
  MW_pinModeOutput(MotorTest_P.DigitalOutput_pinNumber_f);

  /* S-Function Block: <S8>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        MotorTest_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S7>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        MotorTest_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        MotorTest_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S9>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        MotorTest_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S8>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        MotorTest_DW.SFunction1_DSTATE_f = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void MotorTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
