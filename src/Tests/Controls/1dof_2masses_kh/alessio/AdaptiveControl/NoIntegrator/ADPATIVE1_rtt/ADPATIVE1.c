/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADPATIVE1.c
 *
 * Code generated for Simulink model 'ADPATIVE1'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:33:22 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADPATIVE1.h"
#include "ADPATIVE1_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define ADPATIVE1_IN_ALERT             ((uint8_T)1U)
#define ADPATIVE1_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define ADPATIVE1_IN_OK                ((uint8_T)2U)
#define ADPATIVE1_IN_RESTORE           ((uint8_T)3U)

const boolean_T ADPATIVE1_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_ADPATIVE1_T ADPATIVE1_B;

/* Continuous states */
X_ADPATIVE1_T ADPATIVE1_X;

/* Block states (auto storage) */
DW_ADPATIVE1_T ADPATIVE1_DW;

/* Real-time model */
RT_MODEL_ADPATIVE1_T ADPATIVE1_M_;
RT_MODEL_ADPATIVE1_T *const ADPATIVE1_M = &ADPATIVE1_M_;

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
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ADPATIVE1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ADPATIVE1_output();
  ADPATIVE1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ADPATIVE1_output();
  ADPATIVE1_derivatives();

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
void ADPATIVE1_output(void)
{
  real_T *lastU;
  real_T rtb_Saturation;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_FixPtRelationalOperator;
  real_T Saturation;
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ADPATIVE1_M->solverInfo,
                          ((ADPATIVE1_M->Timing.clockTick0+1)*
      ADPATIVE1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ADPATIVE1_M)) {
    ADPATIVE1_M->Timing.t[0] = rtsiGetT(&ADPATIVE1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* S-Function (signals): '<S3>/S-Function2' */
    signals_Outputs_wrapper( &ADPATIVE1_B.SFunction2_o1,
      &ADPATIVE1_B.SFunction2_o2, &ADPATIVE1_DW.SFunction2_DSTATE);

    /* Gain: '<S9>/encoder-to-cm' incorporates:
     *  Memory: '<S1>/Memory2'
     */
    rtb_Saturation = ADPATIVE1_P.encodertocm_Gain *
      ADPATIVE1_DW.Memory2_PreviousInput;

    /* Logic: '<S9>/Logical Operator' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S13>/Constant'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S13>/Compare'
     */
    rtb_LogicalOperator = ((rtb_Saturation >= ADPATIVE1_P.UpperThreshold_const) ||
      (rtb_Saturation <= ADPATIVE1_P.LowerThreshold_const));

    /* Memory: '<S5>/Memory' */
    ADPATIVE1_B.Memory = ADPATIVE1_DW.Memory_PreviousInput;

    /* RelationalOperator: '<S8>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S8>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = (ADPATIVE1_B.Memory !=
      ADPATIVE1_DW.DelayInput1_DSTATE);
  }

  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    rtb_Saturation = (ADPATIVE1_DW.clockTickCounter <
                      ADPATIVE1_P.PulseGenerator_Duty) &&
      (ADPATIVE1_DW.clockTickCounter >= 0) ? ADPATIVE1_P.PulseGenerator_Amp :
      0.0;
    if (ADPATIVE1_DW.clockTickCounter >= ADPATIVE1_P.PulseGenerator_Period - 1.0)
    {
      ADPATIVE1_DW.clockTickCounter = 0;
    } else {
      ADPATIVE1_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Saturate: '<S10>/Saturation' */
    if (rtb_Saturation > ADPATIVE1_P.Saturation_UpperSat) {
      rtb_Saturation = ADPATIVE1_P.Saturation_UpperSat;
    } else {
      if (rtb_Saturation < ADPATIVE1_P.Saturation_LowerSat) {
        rtb_Saturation = ADPATIVE1_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Product: '<S1>/Product' incorporates:
     *  Logic: '<S1>/Motor Enabler'
     *  Memory: '<S1>/Memory1'
     */
    ADPATIVE1_B.Product = (real_T)!(ADPATIVE1_DW.Memory1_PreviousInput != 0.0) *
      rtb_Saturation;

    /* Memory: '<S2>/Memory' */
    ADPATIVE1_B.Memory_j = ADPATIVE1_DW.Memory_PreviousInput_o;
  }

  /* Sum: '<S2>/Add3' incorporates:
   *  Integrator: '<S2>/Integrator4'
   *  Product: '<S2>/Product3'
   */
  rtb_Saturation = ADPATIVE1_X.Integrator4_CSTATE * ADPATIVE1_B.Product +
    ADPATIVE1_B.Memory_j;

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Saturation > ADPATIVE1_P.Saturation_UpperSat_i) {
    Saturation = ADPATIVE1_P.Saturation_UpperSat_i;
  } else if (rtb_Saturation < ADPATIVE1_P.Saturation_LowerSat_e) {
    Saturation = ADPATIVE1_P.Saturation_LowerSat_e;
  } else {
    Saturation = rtb_Saturation;
  }

  /* End of Saturate: '<S11>/Saturation' */
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* Chart: '<S1>/Chart' */
    /* Gateway: Condom/Chart */
    /* During: Condom/Chart */
    if (ADPATIVE1_DW.is_active_c3_ADPATIVE1 == 0U) {
      /* Entry: Condom/Chart */
      ADPATIVE1_DW.is_active_c3_ADPATIVE1 = 1U;

      /* Entry Internal: Condom/Chart */
      /* Transition: '<S7>:4' */
      ADPATIVE1_DW.is_c3_ADPATIVE1 = ADPATIVE1_IN_OK;

      /* Entry 'OK': '<S7>:1' */
      ADPATIVE1_B.MD = 0.0;
      ADPATIVE1_B.ER = 0.0;
    } else {
      switch (ADPATIVE1_DW.is_c3_ADPATIVE1) {
       case ADPATIVE1_IN_ALERT:
        /* During 'ALERT': '<S7>:2' */
        if (!rtb_FixPtRelationalOperator) {
          /* Transition: '<S7>:11' */
          ADPATIVE1_DW.is_c3_ADPATIVE1 = ADPATIVE1_IN_RESTORE;

          /* Entry 'RESTORE': '<S7>:10' */
          ADPATIVE1_B.MD = 1.0;
          ADPATIVE1_B.ER = 1.0;
        }
        break;

       case ADPATIVE1_IN_OK:
        /* During 'OK': '<S7>:1' */
        if (rtb_LogicalOperator) {
          /* Transition: '<S7>:3' */
          ADPATIVE1_DW.is_c3_ADPATIVE1 = ADPATIVE1_IN_ALERT;

          /* Entry 'ALERT': '<S7>:2' */
          ADPATIVE1_B.MD = 1.0;
        }
        break;

       default:
        /* During 'RESTORE': '<S7>:10' */
        if (Saturation == 0.0) {
          /* Transition: '<S7>:12' */
          ADPATIVE1_DW.is_c3_ADPATIVE1 = ADPATIVE1_IN_OK;

          /* Entry 'OK': '<S7>:1' */
          ADPATIVE1_B.MD = 0.0;
          ADPATIVE1_B.ER = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<S1>/Chart' */

    /* DataTypeConversion: '<S6>/conversion1' */
    ADPATIVE1_B.conversion1 = (ADPATIVE1_B.MD != 0.0);

    /* DataTypeConversion: '<S6>/conversion3' */
    ADPATIVE1_B.conversion3 = false;

    /* DataTypeConversion: '<S6>/conversion9' */
    ADPATIVE1_B.conversion9 = false;

    /* DataTypeConversion: '<S6>/conversion10' */
    ADPATIVE1_B.conversion10 = false;

    /* DataTypeConversion: '<S6>/conversion13' */
    ADPATIVE1_B.conversion13 = (real32_T)ADPATIVE1_B.Product;

    /* DataTypeConversion: '<S6>/conversion2' */
    ADPATIVE1_B.conversion2 = (real32_T)rtb_Saturation;
  }

  /* DataTypeConversion: '<S22>/conversion8' */
  ADPATIVE1_B.conversion8 = (real32_T)Saturation;
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S21>/S-Function' */
    rtb_LogicalOperator = MW_digitalRead(ADPATIVE1_P.SFunction_p1);

    /* Logic: '<S22>/Logical Operator' incorporates:
     *  Logic: '<Root>/Logical Operator'
     *  Logic: '<S18>/Logical Operator'
     *  S-Function (arduinodigitalinput_sfcn): '<S21>/S-Function'
     */
    ADPATIVE1_B.LogicalOperator = (rtb_LogicalOperator && (!(ADPATIVE1_B.MD !=
      0.0)) && ADPATIVE1_B.SFunction2_o1);
  }

  /* S-Function (sfcn_motor_new): '<S22>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&ADPATIVE1_B.conversion8,
    &ADPATIVE1_B.LogicalOperator, &ADPATIVE1_B.SFunction1_o1,
    &ADPATIVE1_B.SFunction1_o2, &ADPATIVE1_B.SFunction1_o3,
    &ADPATIVE1_DW.SFunction1_DSTATE, &ADPATIVE1_P.SFunction1_P1, 1,
    &ADPATIVE1_P.SFunction1_P2, 1, &ADPATIVE1_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* DataTypeConversion: '<S6>/conversion4' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion1'
     */
    ADPATIVE1_B.conversion4 = ADPATIVE1_B.SFunction1_o1;

    /* DataTypeConversion: '<S6>/conversion5' */
    ADPATIVE1_B.conversion5 = (real32_T)ADPATIVE1_B.Memory;
  }

  /* Derivative: '<S5>/Derivative' */
  if ((ADPATIVE1_DW.TimeStampA >= ADPATIVE1_M->Timing.t[0]) &&
      (ADPATIVE1_DW.TimeStampB >= ADPATIVE1_M->Timing.t[0])) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = ADPATIVE1_DW.TimeStampA;
    lastU = &ADPATIVE1_DW.LastUAtTimeA;
    if (ADPATIVE1_DW.TimeStampA < ADPATIVE1_DW.TimeStampB) {
      if (ADPATIVE1_DW.TimeStampB < ADPATIVE1_M->Timing.t[0]) {
        rtb_Saturation = ADPATIVE1_DW.TimeStampB;
        lastU = &ADPATIVE1_DW.LastUAtTimeB;
      }
    } else {
      if (ADPATIVE1_DW.TimeStampA >= ADPATIVE1_M->Timing.t[0]) {
        rtb_Saturation = ADPATIVE1_DW.TimeStampB;
        lastU = &ADPATIVE1_DW.LastUAtTimeB;
      }
    }

    rtb_Saturation = (ADPATIVE1_B.Memory - *lastU) / (ADPATIVE1_M->Timing.t[0] -
      rtb_Saturation);
  }

  /* End of Derivative: '<S5>/Derivative' */
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* DataTypeConversion: '<S6>/conversion6' */
    ADPATIVE1_B.conversion6 = (real32_T)rtb_Saturation;

    /* DataTypeConversion: '<S6>/conversion7' */
    ADPATIVE1_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S6>/S-Function' */
    SerialTx_Outputs_wrapper(&ADPATIVE1_B.SFunction2_o1, (boolean_T*)
      &ADPATIVE1_BGND, (boolean_T*)&ADPATIVE1_BGND, (boolean_T*)&ADPATIVE1_BGND,
      &ADPATIVE1_B.conversion1, &ADPATIVE1_B.conversion3,
      &ADPATIVE1_B.conversion9, &ADPATIVE1_B.conversion10,
      &ADPATIVE1_B.conversion13, &ADPATIVE1_B.conversion2,
      &ADPATIVE1_B.conversion4, &ADPATIVE1_B.conversion5,
      &ADPATIVE1_B.conversion6, &ADPATIVE1_B.conversion7,
      &ADPATIVE1_DW.SFunction_DSTATE, &ADPATIVE1_P.SFunction_P1, 1,
      &ADPATIVE1_P.SFunction_P2, 1);
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  Integrator: '<S14>/Integrator'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport1'
   *  Sum: '<S2>/Add1'
   */
  Saturation = (ADPATIVE1_B.Memory - ADPATIVE1_X.Integrator_CSTATE[0]) *
    ADPATIVE1_P.Constant_Value[0] + (rtb_Saturation -
    ADPATIVE1_X.Integrator_CSTATE[1]) * ADPATIVE1_P.Constant_Value[1];

  /* Gain: '<S2>/Gain' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport1'
   */
  ADPATIVE1_B.Gain[0] = 0.0;
  ADPATIVE1_B.Gain[0] += ADPATIVE1_B.Memory * Saturation * -ADPATIVE1_P.GammaX[0];
  ADPATIVE1_B.Gain[0] += rtb_Saturation * Saturation * -ADPATIVE1_P.GammaX[2];
  ADPATIVE1_B.Gain[1] = 0.0;
  ADPATIVE1_B.Gain[1] += ADPATIVE1_B.Memory * Saturation * -ADPATIVE1_P.GammaX[1];
  ADPATIVE1_B.Gain[1] += rtb_Saturation * Saturation * -ADPATIVE1_P.GammaX[3];

  /* Gain: '<S2>/Gain3' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product8'
   */
  ADPATIVE1_B.Gain3 = ADPATIVE1_B.Product * Saturation * -ADPATIVE1_P.GammaR;
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* Memory: '<S2>/Memory2' */
    ADPATIVE1_B.Memory2[0] = ADPATIVE1_DW.Memory2_PreviousInput_g[0];
    ADPATIVE1_B.Memory2[1] = ADPATIVE1_DW.Memory2_PreviousInput_g[1];

    /* Memory: '<S2>/Memory3' */
    ADPATIVE1_B.Memory3 = ADPATIVE1_DW.Memory3_PreviousInput;
  }

  /* Product: '<S2>/Product4' incorporates:
   *  Integrator: '<S2>/Integrator1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport1'
   */
  ADPATIVE1_B.Product4 = ADPATIVE1_X.Integrator1_CSTATE[0] * ADPATIVE1_B.Memory
    + ADPATIVE1_X.Integrator1_CSTATE[1] * rtb_Saturation;

  /* Sum: '<S14>/Add' incorporates:
   *  Gain: '<S14>/Gain'
   *  Gain: '<S14>/Gain1'
   *  Integrator: '<S14>/Integrator'
   */
  ADPATIVE1_B.Add[0] = (ADPATIVE1_P.Aref[0] * ADPATIVE1_X.Integrator_CSTATE[0] +
                        ADPATIVE1_P.Aref[2] * ADPATIVE1_X.Integrator_CSTATE[1])
    + ADPATIVE1_P.Bref[0] * 0.0;
  ADPATIVE1_B.Add[1] = (ADPATIVE1_P.Aref[1] * ADPATIVE1_X.Integrator_CSTATE[0] +
                        ADPATIVE1_P.Aref[3] * ADPATIVE1_X.Integrator_CSTATE[1])
    + ADPATIVE1_P.Bref[1] * 0.0;
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S19>/S-Function' */
    rtb_LogicalOperator = MW_digitalRead(ADPATIVE1_P.SFunction_p1_d);

    /* Logic: '<S17>/Logical Operator' incorporates:
     *  S-Function (arduinodigitalinput_sfcn): '<S19>/S-Function'
     */
    ADPATIVE1_B.LogicalOperator_g = (rtb_LogicalOperator || (ADPATIVE1_B.ER !=
      0.0));

    /* S-Function (sfcn_encoder): '<S20>/S-Function' */
    sfcn_encoder_Outputs_wrapper(&ADPATIVE1_B.LogicalOperator_g,
      &ADPATIVE1_B.SFunction, &ADPATIVE1_DW.SFunction_DSTATE_g,
      &ADPATIVE1_P.SFunction_P1_n, 1, &ADPATIVE1_P.Encoder_dt_enc, 1);

    /* Gain: '<S5>/Gain' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     */
    ADPATIVE1_B.Gain_g = ADPATIVE1_P.Gain_Gain * (real_T)ADPATIVE1_B.SFunction;
  }

  /* S-Function (sfun_tstart): '<S4>/startTime' */

  /* S-Function Block (sfun_tstart): <S4>/startTime */
  ADPATIVE1_B.startTime = (0.0);
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     */
    MW_digitalWrite(ADPATIVE1_P.DigitalOutput_pinNumber, (uint8_T)
                    ADPATIVE1_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     */
    MW_digitalWrite(ADPATIVE1_P.DigitalOutput_pinNumber_m, (uint8_T)
                    ADPATIVE1_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &ADPATIVE1_DW.SFunction1_DSTATE_e);
  }
}

/* Model update function */
void ADPATIVE1_update(void)
{
  real_T *lastU;
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
    signals_Update_wrapper( &ADPATIVE1_B.SFunction2_o1,
      &ADPATIVE1_B.SFunction2_o2, &ADPATIVE1_DW.SFunction2_DSTATE);

    /* Update for Memory: '<S1>/Memory2' */
    ADPATIVE1_DW.Memory2_PreviousInput = ADPATIVE1_B.Memory;

    /* Update for Memory: '<S5>/Memory' */
    ADPATIVE1_DW.Memory_PreviousInput = ADPATIVE1_B.Gain_g;

    /* Update for UnitDelay: '<S8>/Delay Input1' */
    ADPATIVE1_DW.DelayInput1_DSTATE = ADPATIVE1_B.Memory;

    /* Update for Memory: '<S1>/Memory1' */
    ADPATIVE1_DW.Memory1_PreviousInput = ADPATIVE1_B.MD;

    /* Update for Memory: '<S2>/Memory' */
    ADPATIVE1_DW.Memory_PreviousInput_o = ADPATIVE1_B.Product4;
  }

  /* S-Function "sfcn_motor_new_wrapper" Block: <S22>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&ADPATIVE1_B.conversion8,
    &ADPATIVE1_B.LogicalOperator, &ADPATIVE1_B.SFunction1_o1,
    &ADPATIVE1_B.SFunction1_o2, &ADPATIVE1_B.SFunction1_o3,
    &ADPATIVE1_DW.SFunction1_DSTATE, &ADPATIVE1_P.SFunction1_P1, 1,
    &ADPATIVE1_P.SFunction1_P2, 1, &ADPATIVE1_P.SFunction1_P3, 1);

  /* Update for Derivative: '<S5>/Derivative' */
  if (ADPATIVE1_DW.TimeStampA == (rtInf)) {
    ADPATIVE1_DW.TimeStampA = ADPATIVE1_M->Timing.t[0];
    lastU = &ADPATIVE1_DW.LastUAtTimeA;
  } else if (ADPATIVE1_DW.TimeStampB == (rtInf)) {
    ADPATIVE1_DW.TimeStampB = ADPATIVE1_M->Timing.t[0];
    lastU = &ADPATIVE1_DW.LastUAtTimeB;
  } else if (ADPATIVE1_DW.TimeStampA < ADPATIVE1_DW.TimeStampB) {
    ADPATIVE1_DW.TimeStampA = ADPATIVE1_M->Timing.t[0];
    lastU = &ADPATIVE1_DW.LastUAtTimeA;
  } else {
    ADPATIVE1_DW.TimeStampB = ADPATIVE1_M->Timing.t[0];
    lastU = &ADPATIVE1_DW.LastUAtTimeB;
  }

  *lastU = ADPATIVE1_B.Memory;

  /* End of Update for Derivative: '<S5>/Derivative' */
  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    /* S-Function "SerialTx_wrapper" Block: <S6>/S-Function */
    SerialTx_Update_wrapper(&ADPATIVE1_B.SFunction2_o1, (boolean_T*)
      &ADPATIVE1_BGND, (boolean_T*)&ADPATIVE1_BGND, (boolean_T*)&ADPATIVE1_BGND,
      &ADPATIVE1_B.conversion1, &ADPATIVE1_B.conversion3,
      &ADPATIVE1_B.conversion9, &ADPATIVE1_B.conversion10,
      &ADPATIVE1_B.conversion13, &ADPATIVE1_B.conversion2,
      &ADPATIVE1_B.conversion4, &ADPATIVE1_B.conversion5,
      &ADPATIVE1_B.conversion6, &ADPATIVE1_B.conversion7,
      &ADPATIVE1_DW.SFunction_DSTATE, &ADPATIVE1_P.SFunction_P1, 1,
      &ADPATIVE1_P.SFunction_P2, 1);

    /* Update for Memory: '<S2>/Memory2' */
    ADPATIVE1_DW.Memory2_PreviousInput_g[0] = ADPATIVE1_B.Gain[0];
    ADPATIVE1_DW.Memory2_PreviousInput_g[1] = ADPATIVE1_B.Gain[1];

    /* Update for Memory: '<S2>/Memory3' */
    ADPATIVE1_DW.Memory3_PreviousInput = ADPATIVE1_B.Gain3;

    /* S-Function "sfcn_encoder_wrapper" Block: <S20>/S-Function */
    sfcn_encoder_Update_wrapper(&ADPATIVE1_B.LogicalOperator_g,
      &ADPATIVE1_B.SFunction, &ADPATIVE1_DW.SFunction_DSTATE_g,
      &ADPATIVE1_P.SFunction_P1_n, 1, &ADPATIVE1_P.Encoder_dt_enc, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&ADPATIVE1_DW.SFunction1_DSTATE_e);
  }

  if (rtmIsMajorTimeStep(ADPATIVE1_M)) {
    rt_ertODEUpdateContinuousStates(&ADPATIVE1_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++ADPATIVE1_M->Timing.clockTick0;
  ADPATIVE1_M->Timing.t[0] = rtsiGetSolverStopTime(&ADPATIVE1_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ADPATIVE1_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void ADPATIVE1_derivatives(void)
{
  XDot_ADPATIVE1_T *_rtXdot;
  _rtXdot = ((XDot_ADPATIVE1_T *) ADPATIVE1_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = ADPATIVE1_B.Memory3;

  /* Derivatives for Integrator: '<S14>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ADPATIVE1_B.Add[0];
  _rtXdot->Integrator_CSTATE[1] = ADPATIVE1_B.Add[1];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ADPATIVE1_B.Memory2[0];
  _rtXdot->Integrator1_CSTATE[1] = ADPATIVE1_B.Memory2[1];

  /* Derivatives for ZeroPole: '<S5>/Zero-Pole' */
  _rtXdot->ZeroPole_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole_CSTATE[0] += ADPATIVE1_P.ZeroPole_A[0] *
    ADPATIVE1_X.ZeroPole_CSTATE[0];
  _rtXdot->ZeroPole_CSTATE[0] += ADPATIVE1_P.ZeroPole_A[1] *
    ADPATIVE1_X.ZeroPole_CSTATE[1];
  _rtXdot->ZeroPole_CSTATE[1] += ADPATIVE1_P.ZeroPole_A[2] *
    ADPATIVE1_X.ZeroPole_CSTATE[0];
  _rtXdot->ZeroPole_CSTATE[0] += ADPATIVE1_P.ZeroPole_B * 0.0;
}

/* Model initialize function */
void ADPATIVE1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ADPATIVE1_M, 0,
                sizeof(RT_MODEL_ADPATIVE1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ADPATIVE1_M->solverInfo,
                          &ADPATIVE1_M->Timing.simTimeStep);
    rtsiSetTPtr(&ADPATIVE1_M->solverInfo, &rtmGetTPtr(ADPATIVE1_M));
    rtsiSetStepSizePtr(&ADPATIVE1_M->solverInfo, &ADPATIVE1_M->Timing.stepSize0);
    rtsiSetdXPtr(&ADPATIVE1_M->solverInfo, &ADPATIVE1_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ADPATIVE1_M->solverInfo, (real_T **)
                         &ADPATIVE1_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ADPATIVE1_M->solverInfo,
      &ADPATIVE1_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ADPATIVE1_M->solverInfo, (&rtmGetErrorStatus
      (ADPATIVE1_M)));
    rtsiSetRTModelPtr(&ADPATIVE1_M->solverInfo, ADPATIVE1_M);
  }

  rtsiSetSimTimeStep(&ADPATIVE1_M->solverInfo, MAJOR_TIME_STEP);
  ADPATIVE1_M->ModelData.intgData.y = ADPATIVE1_M->ModelData.odeY;
  ADPATIVE1_M->ModelData.intgData.f[0] = ADPATIVE1_M->ModelData.odeF[0];
  ADPATIVE1_M->ModelData.intgData.f[1] = ADPATIVE1_M->ModelData.odeF[1];
  ADPATIVE1_M->ModelData.intgData.f[2] = ADPATIVE1_M->ModelData.odeF[2];
  ADPATIVE1_M->ModelData.contStates = ((X_ADPATIVE1_T *) &ADPATIVE1_X);
  rtsiSetSolverData(&ADPATIVE1_M->solverInfo, (void *)
                    &ADPATIVE1_M->ModelData.intgData);
  rtsiSetSolverName(&ADPATIVE1_M->solverInfo,"ode3");
  rtmSetTPtr(ADPATIVE1_M, &ADPATIVE1_M->Timing.tArray[0]);
  ADPATIVE1_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &ADPATIVE1_B), 0,
                sizeof(B_ADPATIVE1_T));

  /* states (continuous) */
  {
    (void) memset((void *)&ADPATIVE1_X, 0,
                  sizeof(X_ADPATIVE1_T));
  }

  /* states (dwork) */
  (void) memset((void *)&ADPATIVE1_DW, 0,
                sizeof(DW_ADPATIVE1_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  ADPATIVE1_DW.clockTickCounter = -1000;

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S21>/S-Function' */
  MW_pinModeInput(ADPATIVE1_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S19>/S-Function' */
  MW_pinModeInput(ADPATIVE1_P.SFunction_p1_d);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
  MW_pinModeOutput(ADPATIVE1_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output' */
  MW_pinModeOutput(ADPATIVE1_P.DigitalOutput_pinNumber_m);

  /* S-Function Block: <S3>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ADPATIVE1_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  ADPATIVE1_DW.Memory2_PreviousInput = ADPATIVE1_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S5>/Memory' */
  ADPATIVE1_DW.Memory_PreviousInput = ADPATIVE1_P.Memory_X0;

  /* InitializeConditions for UnitDelay: '<S8>/Delay Input1' */
  ADPATIVE1_DW.DelayInput1_DSTATE = ADPATIVE1_P.DetectChange_vinit;

  /* InitializeConditions for Integrator: '<S2>/Integrator4' */
  ADPATIVE1_X.Integrator4_CSTATE = ADPATIVE1_P.Integrator4_IC;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  ADPATIVE1_DW.Memory1_PreviousInput = ADPATIVE1_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  ADPATIVE1_DW.Memory_PreviousInput_o = ADPATIVE1_P.Memory_X0_n;

  /* InitializeConditions for Chart: '<S1>/Chart' */
  ADPATIVE1_DW.is_active_c3_ADPATIVE1 = 0U;
  ADPATIVE1_DW.is_c3_ADPATIVE1 = ADPATIVE1_IN_NO_ACTIVE_CHILD;

  /* S-Function Block: <S22>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ADPATIVE1_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  ADPATIVE1_DW.TimeStampA = (rtInf);
  ADPATIVE1_DW.TimeStampB = (rtInf);

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ADPATIVE1_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Integrator: '<S14>/Integrator' */
  ADPATIVE1_X.Integrator_CSTATE[0] = ADPATIVE1_P.Integrator_IC;
  ADPATIVE1_X.Integrator_CSTATE[1] = ADPATIVE1_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  ADPATIVE1_X.Integrator1_CSTATE[0] = ADPATIVE1_P.Integrator1_IC;
  ADPATIVE1_X.Integrator1_CSTATE[1] = ADPATIVE1_P.Integrator1_IC;

  /* InitializeConditions for Memory: '<S2>/Memory2' */
  ADPATIVE1_DW.Memory2_PreviousInput_g[0] = ADPATIVE1_P.Memory2_X0_k;
  ADPATIVE1_DW.Memory2_PreviousInput_g[1] = ADPATIVE1_P.Memory2_X0_k;

  /* InitializeConditions for Memory: '<S2>/Memory3' */
  ADPATIVE1_DW.Memory3_PreviousInput = ADPATIVE1_P.Memory3_X0;

  /* S-Function Block: <S20>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ADPATIVE1_DW.SFunction_DSTATE_g = initVector[0];
      }
    }
  }

  /* InitializeConditions for ZeroPole: '<S5>/Zero-Pole' */
  ADPATIVE1_X.ZeroPole_CSTATE[0] = 0.0;
  ADPATIVE1_X.ZeroPole_CSTATE[1] = 0.0;

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ADPATIVE1_DW.SFunction1_DSTATE_e = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void ADPATIVE1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
