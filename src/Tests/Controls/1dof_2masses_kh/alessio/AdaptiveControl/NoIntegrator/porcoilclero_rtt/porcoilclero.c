/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: porcoilclero.c
 *
 * Code generated for Simulink model 'porcoilclero'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:44:14 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "porcoilclero.h"
#include "porcoilclero_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define porcoilclero_IN_ALERT          ((uint8_T)1U)
#define porcoilclero_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define porcoilclero_IN_OK             ((uint8_T)2U)
#define porcoilclero_IN_RESTORE        ((uint8_T)3U)

const boolean_T porcoilclero_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_porcoilclero_T porcoilclero_B;

/* Continuous states */
X_porcoilclero_T porcoilclero_X;

/* Block states (auto storage) */
DW_porcoilclero_T porcoilclero_DW;

/* Real-time model */
RT_MODEL_porcoilclero_T porcoilclero_M_;
RT_MODEL_porcoilclero_T *const porcoilclero_M = &porcoilclero_M_;

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
  porcoilclero_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  porcoilclero_output();
  porcoilclero_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  porcoilclero_output();
  porcoilclero_derivatives();

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
void porcoilclero_output(void)
{
  real_T *lastU;
  real_T rtb_Saturation;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_FixPtRelationalOperator;
  real_T Saturation;
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&porcoilclero_M->solverInfo,
                          ((porcoilclero_M->Timing.clockTick0+1)*
      porcoilclero_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(porcoilclero_M)) {
    porcoilclero_M->Timing.t[0] = rtsiGetT(&porcoilclero_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* S-Function (signals): '<S3>/S-Function2' */
    signals_Outputs_wrapper( &porcoilclero_B.SFunction2_o1,
      &porcoilclero_B.SFunction2_o2, &porcoilclero_DW.SFunction2_DSTATE);

    /* Gain: '<S8>/encoder-to-cm' incorporates:
     *  Memory: '<S1>/Memory2'
     */
    rtb_Saturation = porcoilclero_P.encodertocm_Gain *
      porcoilclero_DW.Memory2_PreviousInput;

    /* Logic: '<S8>/Logical Operator' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S12>/Compare'
     */
    rtb_LogicalOperator = ((rtb_Saturation >=
      porcoilclero_P.UpperThreshold_const) || (rtb_Saturation <=
      porcoilclero_P.LowerThreshold_const));

    /* Memory: '<S4>/Memory' */
    porcoilclero_B.Memory = porcoilclero_DW.Memory_PreviousInput;

    /* RelationalOperator: '<S7>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S7>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = (porcoilclero_B.Memory !=
      porcoilclero_DW.DelayInput1_DSTATE);
  }

  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    rtb_Saturation = (porcoilclero_DW.clockTickCounter <
                      porcoilclero_P.PulseGenerator_Duty) &&
      (porcoilclero_DW.clockTickCounter >= 0) ?
      porcoilclero_P.PulseGenerator_Amp : 0.0;
    if (porcoilclero_DW.clockTickCounter >= porcoilclero_P.PulseGenerator_Period
        - 1.0) {
      porcoilclero_DW.clockTickCounter = 0;
    } else {
      porcoilclero_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Saturate: '<S9>/Saturation' */
    if (rtb_Saturation > porcoilclero_P.Saturation_UpperSat) {
      rtb_Saturation = porcoilclero_P.Saturation_UpperSat;
    } else {
      if (rtb_Saturation < porcoilclero_P.Saturation_LowerSat) {
        rtb_Saturation = porcoilclero_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S9>/Saturation' */

    /* Product: '<S1>/Product' incorporates:
     *  Logic: '<S1>/Motor Enabler'
     *  Memory: '<S1>/Memory1'
     */
    porcoilclero_B.Product = (real_T)!(porcoilclero_DW.Memory1_PreviousInput !=
      0.0) * rtb_Saturation;

    /* Memory: '<S2>/Memory' */
    porcoilclero_B.Memory_i = porcoilclero_DW.Memory_PreviousInput_o;
  }

  /* Sum: '<S2>/Add3' incorporates:
   *  Integrator: '<S2>/Integrator4'
   *  Product: '<S2>/Product3'
   */
  rtb_Saturation = porcoilclero_X.Integrator4_CSTATE * porcoilclero_B.Product +
    porcoilclero_B.Memory_i;

  /* Saturate: '<S10>/Saturation' */
  if (rtb_Saturation > porcoilclero_P.Saturation_UpperSat_i) {
    Saturation = porcoilclero_P.Saturation_UpperSat_i;
  } else if (rtb_Saturation < porcoilclero_P.Saturation_LowerSat_e) {
    Saturation = porcoilclero_P.Saturation_LowerSat_e;
  } else {
    Saturation = rtb_Saturation;
  }

  /* End of Saturate: '<S10>/Saturation' */
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* Chart: '<S1>/Chart' */
    /* Gateway: Condom/Chart */
    /* During: Condom/Chart */
    if (porcoilclero_DW.is_active_c3_porcoilclero == 0U) {
      /* Entry: Condom/Chart */
      porcoilclero_DW.is_active_c3_porcoilclero = 1U;

      /* Entry Internal: Condom/Chart */
      /* Transition: '<S6>:4' */
      porcoilclero_DW.is_c3_porcoilclero = porcoilclero_IN_OK;

      /* Entry 'OK': '<S6>:1' */
      porcoilclero_B.MD = 0.0;
      porcoilclero_B.ER = 0.0;
    } else {
      switch (porcoilclero_DW.is_c3_porcoilclero) {
       case porcoilclero_IN_ALERT:
        /* During 'ALERT': '<S6>:2' */
        if (!rtb_FixPtRelationalOperator) {
          /* Transition: '<S6>:11' */
          porcoilclero_DW.is_c3_porcoilclero = porcoilclero_IN_RESTORE;

          /* Entry 'RESTORE': '<S6>:10' */
          porcoilclero_B.MD = 1.0;
          porcoilclero_B.ER = 1.0;
        }
        break;

       case porcoilclero_IN_OK:
        /* During 'OK': '<S6>:1' */
        if (rtb_LogicalOperator) {
          /* Transition: '<S6>:3' */
          porcoilclero_DW.is_c3_porcoilclero = porcoilclero_IN_ALERT;

          /* Entry 'ALERT': '<S6>:2' */
          porcoilclero_B.MD = 1.0;
        }
        break;

       default:
        /* During 'RESTORE': '<S6>:10' */
        if (Saturation == 0.0) {
          /* Transition: '<S6>:12' */
          porcoilclero_DW.is_c3_porcoilclero = porcoilclero_IN_OK;

          /* Entry 'OK': '<S6>:1' */
          porcoilclero_B.MD = 0.0;
          porcoilclero_B.ER = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<S1>/Chart' */

    /* DataTypeConversion: '<S5>/conversion1' */
    porcoilclero_B.conversion1 = (porcoilclero_B.MD != 0.0);

    /* DataTypeConversion: '<S5>/conversion3' */
    porcoilclero_B.conversion3 = false;

    /* DataTypeConversion: '<S5>/conversion9' */
    porcoilclero_B.conversion9 = false;

    /* DataTypeConversion: '<S5>/conversion10' */
    porcoilclero_B.conversion10 = false;

    /* DataTypeConversion: '<S5>/conversion13' */
    porcoilclero_B.conversion13 = (real32_T)porcoilclero_B.Product;

    /* DataTypeConversion: '<S5>/conversion2' */
    porcoilclero_B.conversion2 = (real32_T)rtb_Saturation;
  }

  /* DataTypeConversion: '<S21>/conversion8' */
  porcoilclero_B.conversion8 = (real32_T)Saturation;
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S20>/S-Function' */
    rtb_LogicalOperator = MW_digitalRead(porcoilclero_P.SFunction_p1);

    /* Logic: '<S21>/Logical Operator' incorporates:
     *  Logic: '<Root>/Logical Operator'
     *  Logic: '<S17>/Logical Operator'
     *  S-Function (arduinodigitalinput_sfcn): '<S20>/S-Function'
     */
    porcoilclero_B.LogicalOperator = (rtb_LogicalOperator &&
      (!(porcoilclero_B.MD != 0.0)) && porcoilclero_B.SFunction2_o1);
  }

  /* S-Function (sfcn_motor_new): '<S21>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&porcoilclero_B.conversion8,
    &porcoilclero_B.LogicalOperator, &porcoilclero_B.SFunction1_o1,
    &porcoilclero_B.SFunction1_o2, &porcoilclero_B.SFunction1_o3,
    &porcoilclero_DW.SFunction1_DSTATE, &porcoilclero_P.SFunction1_P1, 1,
    &porcoilclero_P.SFunction1_P2, 1, &porcoilclero_P.SFunction1_P3, 1);
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* DataTypeConversion: '<S5>/conversion4' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     */
    porcoilclero_B.conversion4 = porcoilclero_B.SFunction1_o1;

    /* DataTypeConversion: '<S5>/conversion5' */
    porcoilclero_B.conversion5 = (real32_T)porcoilclero_B.Memory;
  }

  /* Derivative: '<S4>/Derivative' */
  if ((porcoilclero_DW.TimeStampA >= porcoilclero_M->Timing.t[0]) &&
      (porcoilclero_DW.TimeStampB >= porcoilclero_M->Timing.t[0])) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = porcoilclero_DW.TimeStampA;
    lastU = &porcoilclero_DW.LastUAtTimeA;
    if (porcoilclero_DW.TimeStampA < porcoilclero_DW.TimeStampB) {
      if (porcoilclero_DW.TimeStampB < porcoilclero_M->Timing.t[0]) {
        rtb_Saturation = porcoilclero_DW.TimeStampB;
        lastU = &porcoilclero_DW.LastUAtTimeB;
      }
    } else {
      if (porcoilclero_DW.TimeStampA >= porcoilclero_M->Timing.t[0]) {
        rtb_Saturation = porcoilclero_DW.TimeStampB;
        lastU = &porcoilclero_DW.LastUAtTimeB;
      }
    }

    rtb_Saturation = (porcoilclero_B.Memory - *lastU) /
      (porcoilclero_M->Timing.t[0] - rtb_Saturation);
  }

  /* End of Derivative: '<S4>/Derivative' */
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* DataTypeConversion: '<S5>/conversion6' */
    porcoilclero_B.conversion6 = (real32_T)rtb_Saturation;

    /* DataTypeConversion: '<S5>/conversion7' */
    porcoilclero_B.conversion7 = 0.0F;

    /* S-Function (SerialTx): '<S5>/S-Function' */
    SerialTx_Outputs_wrapper(&porcoilclero_B.SFunction2_o1, (boolean_T*)
      &porcoilclero_BGND, (boolean_T*)&porcoilclero_BGND, (boolean_T*)
      &porcoilclero_BGND, &porcoilclero_B.conversion1,
      &porcoilclero_B.conversion3, &porcoilclero_B.conversion9,
      &porcoilclero_B.conversion10, &porcoilclero_B.conversion13,
      &porcoilclero_B.conversion2, &porcoilclero_B.conversion4,
      &porcoilclero_B.conversion5, &porcoilclero_B.conversion6,
      &porcoilclero_B.conversion7, &porcoilclero_DW.SFunction_DSTATE,
      &porcoilclero_P.SFunction_P1, 1, &porcoilclero_P.SFunction_P2, 1);
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  Integrator: '<S13>/Integrator'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport1'
   *  Sum: '<S2>/Add1'
   */
  Saturation = (porcoilclero_B.Memory - porcoilclero_X.Integrator_CSTATE[0]) *
    porcoilclero_P.Constant_Value[0] + (rtb_Saturation -
    porcoilclero_X.Integrator_CSTATE[1]) * porcoilclero_P.Constant_Value[1];

  /* Gain: '<S2>/Gain' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport1'
   */
  porcoilclero_B.Gain[0] = 0.0;
  porcoilclero_B.Gain[0] += porcoilclero_B.Memory * Saturation *
    -porcoilclero_P.GammaX[0];
  porcoilclero_B.Gain[0] += rtb_Saturation * Saturation *
    -porcoilclero_P.GammaX[2];
  porcoilclero_B.Gain[1] = 0.0;
  porcoilclero_B.Gain[1] += porcoilclero_B.Memory * Saturation *
    -porcoilclero_P.GammaX[1];
  porcoilclero_B.Gain[1] += rtb_Saturation * Saturation *
    -porcoilclero_P.GammaX[3];

  /* Gain: '<S2>/Gain3' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product8'
   */
  porcoilclero_B.Gain3 = porcoilclero_B.Product * Saturation *
    -porcoilclero_P.GammaR;
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* Memory: '<S2>/Memory2' */
    porcoilclero_B.Memory2[0] = porcoilclero_DW.Memory2_PreviousInput_b[0];
    porcoilclero_B.Memory2[1] = porcoilclero_DW.Memory2_PreviousInput_b[1];

    /* Memory: '<S2>/Memory3' */
    porcoilclero_B.Memory3 = porcoilclero_DW.Memory3_PreviousInput;
  }

  /* Product: '<S2>/Product4' incorporates:
   *  Integrator: '<S2>/Integrator1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport1'
   */
  porcoilclero_B.Product4 = porcoilclero_X.Integrator1_CSTATE[0] *
    porcoilclero_B.Memory + porcoilclero_X.Integrator1_CSTATE[1] *
    rtb_Saturation;
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* Gain: '<S13>/Gain1' */
    porcoilclero_B.Gain1[0] = porcoilclero_P.Bref[0] * porcoilclero_B.Product;
    porcoilclero_B.Gain1[1] = porcoilclero_P.Bref[1] * porcoilclero_B.Product;
  }

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain'
   *  Integrator: '<S13>/Integrator'
   */
  porcoilclero_B.Add[0] = (porcoilclero_P.Aref[0] *
    porcoilclero_X.Integrator_CSTATE[0] + porcoilclero_P.Aref[2] *
    porcoilclero_X.Integrator_CSTATE[1]) + porcoilclero_B.Gain1[0];
  porcoilclero_B.Add[1] = (porcoilclero_P.Aref[1] *
    porcoilclero_X.Integrator_CSTATE[0] + porcoilclero_P.Aref[3] *
    porcoilclero_X.Integrator_CSTATE[1]) + porcoilclero_B.Gain1[1];
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* S-Function (arduinodigitalinput_sfcn): '<S18>/S-Function' */
    rtb_LogicalOperator = MW_digitalRead(porcoilclero_P.SFunction_p1_o);

    /* Logic: '<S16>/Logical Operator' incorporates:
     *  S-Function (arduinodigitalinput_sfcn): '<S18>/S-Function'
     */
    porcoilclero_B.LogicalOperator_g = (rtb_LogicalOperator ||
      (porcoilclero_B.ER != 0.0));

    /* S-Function (sfcn_encoder): '<S19>/S-Function' */
    sfcn_encoder_Outputs_wrapper(&porcoilclero_B.LogicalOperator_g,
      &porcoilclero_B.SFunction, &porcoilclero_DW.SFunction_DSTATE_m,
      &porcoilclero_P.SFunction_P1_g, 1, &porcoilclero_P.Encoder_dt_enc, 1);

    /* Gain: '<S4>/Gain' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     */
    porcoilclero_B.Gain_b = porcoilclero_P.Gain_Gain * (real_T)
      porcoilclero_B.SFunction;

    /* S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion'
     */
    MW_digitalWrite(porcoilclero_P.DigitalOutput_pinNumber, (uint8_T)
                    porcoilclero_B.SFunction2_o1);

    /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     */
    MW_digitalWrite(porcoilclero_P.DigitalOutput_pinNumber_i, (uint8_T)
                    porcoilclero_B.SFunction2_o2);

    /* S-Function (data_struct_init): '<S3>/S-Function1' */
    data_struct_init_Outputs_wrapper( &porcoilclero_DW.SFunction1_DSTATE_g);
  }
}

/* Model update function */
void porcoilclero_update(void)
{
  real_T *lastU;
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* S-Function "signals_wrapper" Block: <S3>/S-Function2 */
    signals_Update_wrapper( &porcoilclero_B.SFunction2_o1,
      &porcoilclero_B.SFunction2_o2, &porcoilclero_DW.SFunction2_DSTATE);

    /* Update for Memory: '<S1>/Memory2' */
    porcoilclero_DW.Memory2_PreviousInput = porcoilclero_B.Memory;

    /* Update for Memory: '<S4>/Memory' */
    porcoilclero_DW.Memory_PreviousInput = porcoilclero_B.Gain_b;

    /* Update for UnitDelay: '<S7>/Delay Input1' */
    porcoilclero_DW.DelayInput1_DSTATE = porcoilclero_B.Memory;

    /* Update for Memory: '<S1>/Memory1' */
    porcoilclero_DW.Memory1_PreviousInput = porcoilclero_B.MD;

    /* Update for Memory: '<S2>/Memory' */
    porcoilclero_DW.Memory_PreviousInput_o = porcoilclero_B.Product4;
  }

  /* S-Function "sfcn_motor_new_wrapper" Block: <S21>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&porcoilclero_B.conversion8,
    &porcoilclero_B.LogicalOperator, &porcoilclero_B.SFunction1_o1,
    &porcoilclero_B.SFunction1_o2, &porcoilclero_B.SFunction1_o3,
    &porcoilclero_DW.SFunction1_DSTATE, &porcoilclero_P.SFunction1_P1, 1,
    &porcoilclero_P.SFunction1_P2, 1, &porcoilclero_P.SFunction1_P3, 1);

  /* Update for Derivative: '<S4>/Derivative' */
  if (porcoilclero_DW.TimeStampA == (rtInf)) {
    porcoilclero_DW.TimeStampA = porcoilclero_M->Timing.t[0];
    lastU = &porcoilclero_DW.LastUAtTimeA;
  } else if (porcoilclero_DW.TimeStampB == (rtInf)) {
    porcoilclero_DW.TimeStampB = porcoilclero_M->Timing.t[0];
    lastU = &porcoilclero_DW.LastUAtTimeB;
  } else if (porcoilclero_DW.TimeStampA < porcoilclero_DW.TimeStampB) {
    porcoilclero_DW.TimeStampA = porcoilclero_M->Timing.t[0];
    lastU = &porcoilclero_DW.LastUAtTimeA;
  } else {
    porcoilclero_DW.TimeStampB = porcoilclero_M->Timing.t[0];
    lastU = &porcoilclero_DW.LastUAtTimeB;
  }

  *lastU = porcoilclero_B.Memory;

  /* End of Update for Derivative: '<S4>/Derivative' */
  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    /* S-Function "SerialTx_wrapper" Block: <S5>/S-Function */
    SerialTx_Update_wrapper(&porcoilclero_B.SFunction2_o1, (boolean_T*)
      &porcoilclero_BGND, (boolean_T*)&porcoilclero_BGND, (boolean_T*)
      &porcoilclero_BGND, &porcoilclero_B.conversion1,
      &porcoilclero_B.conversion3, &porcoilclero_B.conversion9,
      &porcoilclero_B.conversion10, &porcoilclero_B.conversion13,
      &porcoilclero_B.conversion2, &porcoilclero_B.conversion4,
      &porcoilclero_B.conversion5, &porcoilclero_B.conversion6,
      &porcoilclero_B.conversion7, &porcoilclero_DW.SFunction_DSTATE,
      &porcoilclero_P.SFunction_P1, 1, &porcoilclero_P.SFunction_P2, 1);

    /* Update for Memory: '<S2>/Memory2' */
    porcoilclero_DW.Memory2_PreviousInput_b[0] = porcoilclero_B.Gain[0];
    porcoilclero_DW.Memory2_PreviousInput_b[1] = porcoilclero_B.Gain[1];

    /* Update for Memory: '<S2>/Memory3' */
    porcoilclero_DW.Memory3_PreviousInput = porcoilclero_B.Gain3;

    /* S-Function "sfcn_encoder_wrapper" Block: <S19>/S-Function */
    sfcn_encoder_Update_wrapper(&porcoilclero_B.LogicalOperator_g,
      &porcoilclero_B.SFunction, &porcoilclero_DW.SFunction_DSTATE_m,
      &porcoilclero_P.SFunction_P1_g, 1, &porcoilclero_P.Encoder_dt_enc, 1);

    /* S-Function "data_struct_init_wrapper" Block: <S3>/S-Function1 */
    data_struct_init_Update_wrapper(&porcoilclero_DW.SFunction1_DSTATE_g);
  }

  if (rtmIsMajorTimeStep(porcoilclero_M)) {
    rt_ertODEUpdateContinuousStates(&porcoilclero_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++porcoilclero_M->Timing.clockTick0;
  porcoilclero_M->Timing.t[0] = rtsiGetSolverStopTime
    (&porcoilclero_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    porcoilclero_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void porcoilclero_derivatives(void)
{
  XDot_porcoilclero_T *_rtXdot;
  _rtXdot = ((XDot_porcoilclero_T *) porcoilclero_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = porcoilclero_B.Memory3;

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = porcoilclero_B.Add[0];
  _rtXdot->Integrator_CSTATE[1] = porcoilclero_B.Add[1];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = porcoilclero_B.Memory2[0];
  _rtXdot->Integrator1_CSTATE[1] = porcoilclero_B.Memory2[1];

  /* Derivatives for ZeroPole: '<S4>/Zero-Pole' */
  _rtXdot->ZeroPole_CSTATE[0] = 0.0;
  _rtXdot->ZeroPole_CSTATE[1] = 0.0;
  _rtXdot->ZeroPole_CSTATE[0] += porcoilclero_P.ZeroPole_A[0] *
    porcoilclero_X.ZeroPole_CSTATE[0];
  _rtXdot->ZeroPole_CSTATE[0] += porcoilclero_P.ZeroPole_A[1] *
    porcoilclero_X.ZeroPole_CSTATE[1];
  _rtXdot->ZeroPole_CSTATE[1] += porcoilclero_P.ZeroPole_A[2] *
    porcoilclero_X.ZeroPole_CSTATE[0];
  _rtXdot->ZeroPole_CSTATE[0] += porcoilclero_P.ZeroPole_B * 0.0;
}

/* Model initialize function */
void porcoilclero_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)porcoilclero_M, 0,
                sizeof(RT_MODEL_porcoilclero_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&porcoilclero_M->solverInfo,
                          &porcoilclero_M->Timing.simTimeStep);
    rtsiSetTPtr(&porcoilclero_M->solverInfo, &rtmGetTPtr(porcoilclero_M));
    rtsiSetStepSizePtr(&porcoilclero_M->solverInfo,
                       &porcoilclero_M->Timing.stepSize0);
    rtsiSetdXPtr(&porcoilclero_M->solverInfo, &porcoilclero_M->ModelData.derivs);
    rtsiSetContStatesPtr(&porcoilclero_M->solverInfo, (real_T **)
                         &porcoilclero_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&porcoilclero_M->solverInfo,
      &porcoilclero_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&porcoilclero_M->solverInfo, (&rtmGetErrorStatus
      (porcoilclero_M)));
    rtsiSetRTModelPtr(&porcoilclero_M->solverInfo, porcoilclero_M);
  }

  rtsiSetSimTimeStep(&porcoilclero_M->solverInfo, MAJOR_TIME_STEP);
  porcoilclero_M->ModelData.intgData.y = porcoilclero_M->ModelData.odeY;
  porcoilclero_M->ModelData.intgData.f[0] = porcoilclero_M->ModelData.odeF[0];
  porcoilclero_M->ModelData.intgData.f[1] = porcoilclero_M->ModelData.odeF[1];
  porcoilclero_M->ModelData.intgData.f[2] = porcoilclero_M->ModelData.odeF[2];
  porcoilclero_M->ModelData.contStates = ((X_porcoilclero_T *) &porcoilclero_X);
  rtsiSetSolverData(&porcoilclero_M->solverInfo, (void *)
                    &porcoilclero_M->ModelData.intgData);
  rtsiSetSolverName(&porcoilclero_M->solverInfo,"ode3");
  rtmSetTPtr(porcoilclero_M, &porcoilclero_M->Timing.tArray[0]);
  porcoilclero_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &porcoilclero_B), 0,
                sizeof(B_porcoilclero_T));

  /* states (continuous) */
  {
    (void) memset((void *)&porcoilclero_X, 0,
                  sizeof(X_porcoilclero_T));
  }

  /* states (dwork) */
  (void) memset((void *)&porcoilclero_DW, 0,
                sizeof(DW_porcoilclero_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  porcoilclero_DW.clockTickCounter = -1000;

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S20>/S-Function' */
  MW_pinModeInput(porcoilclero_P.SFunction_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S18>/S-Function' */
  MW_pinModeInput(porcoilclero_P.SFunction_p1_o);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_pinModeOutput(porcoilclero_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
  MW_pinModeOutput(porcoilclero_P.DigitalOutput_pinNumber_i);

  /* S-Function Block: <S3>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        porcoilclero_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  porcoilclero_DW.Memory2_PreviousInput = porcoilclero_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  porcoilclero_DW.Memory_PreviousInput = porcoilclero_P.Memory_X0;

  /* InitializeConditions for UnitDelay: '<S7>/Delay Input1' */
  porcoilclero_DW.DelayInput1_DSTATE = porcoilclero_P.DetectChange_vinit;

  /* InitializeConditions for Integrator: '<S2>/Integrator4' */
  porcoilclero_X.Integrator4_CSTATE = porcoilclero_P.Integrator4_IC;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  porcoilclero_DW.Memory1_PreviousInput = porcoilclero_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  porcoilclero_DW.Memory_PreviousInput_o = porcoilclero_P.Memory_X0_i;

  /* InitializeConditions for Chart: '<S1>/Chart' */
  porcoilclero_DW.is_active_c3_porcoilclero = 0U;
  porcoilclero_DW.is_c3_porcoilclero = porcoilclero_IN_NO_ACTIVE_CHILD;

  /* S-Function Block: <S21>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        porcoilclero_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  porcoilclero_DW.TimeStampA = (rtInf);
  porcoilclero_DW.TimeStampB = (rtInf);

  /* S-Function Block: <S5>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        porcoilclero_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  porcoilclero_X.Integrator_CSTATE[0] = porcoilclero_P.Integrator_IC;
  porcoilclero_X.Integrator_CSTATE[1] = porcoilclero_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  porcoilclero_X.Integrator1_CSTATE[0] = porcoilclero_P.Integrator1_IC;
  porcoilclero_X.Integrator1_CSTATE[1] = porcoilclero_P.Integrator1_IC;

  /* InitializeConditions for Memory: '<S2>/Memory2' */
  porcoilclero_DW.Memory2_PreviousInput_b[0] = porcoilclero_P.Memory2_X0_n;
  porcoilclero_DW.Memory2_PreviousInput_b[1] = porcoilclero_P.Memory2_X0_n;

  /* InitializeConditions for Memory: '<S2>/Memory3' */
  porcoilclero_DW.Memory3_PreviousInput = porcoilclero_P.Memory3_X0;

  /* S-Function Block: <S19>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        porcoilclero_DW.SFunction_DSTATE_m = initVector[0];
      }
    }
  }

  /* InitializeConditions for ZeroPole: '<S4>/Zero-Pole' */
  porcoilclero_X.ZeroPole_CSTATE[0] = 0.0;
  porcoilclero_X.ZeroPole_CSTATE[1] = 0.0;

  /* S-Function Block: <S3>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        porcoilclero_DW.SFunction1_DSTATE_g = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void porcoilclero_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
