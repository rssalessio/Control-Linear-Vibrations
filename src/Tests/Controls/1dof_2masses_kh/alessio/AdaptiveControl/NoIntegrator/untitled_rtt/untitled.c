/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri May 06 10:35:37 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define untitled_IN_ALERT              ((uint8_T)1U)
#define untitled_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define untitled_IN_OK                 ((uint8_T)2U)
#define untitled_IN_RESTORE            ((uint8_T)3U)

const boolean_T untitled_BGND = false; /* boolean_T ground */

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Block states (auto storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model output function */
void untitled_output(void)
{
  real_T rtb_Saturation_c;

  /* S-Function (signals): '<S2>/S-Function2' */
  signals_Outputs_wrapper( &untitled_B.SFunction2_o1, &untitled_B.SFunction2_o2,
    &untitled_DW.SFunction2_DSTATE);

  /* Gain: '<S7>/encoder-to-cm' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  rtb_Saturation_c = untitled_P.encodertocm_Gain *
    untitled_DW.Memory2_PreviousInput;

  /* Chart: '<S1>/Chart' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S6>/FixPt Relational Operator'
   *  Saturate: '<S9>/Saturation'
   *  UnitDelay: '<S6>/Delay Input1'
   */
  /* Gateway: Condom/Chart */
  /* During: Condom/Chart */
  if (untitled_DW.is_active_c3_untitled == 0U) {
    /* Entry: Condom/Chart */
    untitled_DW.is_active_c3_untitled = 1U;

    /* Entry Internal: Condom/Chart */
    /* Transition: '<S5>:4' */
    untitled_DW.is_c3_untitled = untitled_IN_OK;

    /* Entry 'OK': '<S5>:1' */
    untitled_B.MD = 0.0;
  } else {
    switch (untitled_DW.is_c3_untitled) {
     case untitled_IN_ALERT:
      /* During 'ALERT': '<S5>:2' */
      if (!(0.0 != untitled_DW.DelayInput1_DSTATE)) {
        /* Transition: '<S5>:11' */
        untitled_DW.is_c3_untitled = untitled_IN_RESTORE;

        /* Entry 'RESTORE': '<S5>:10' */
        untitled_B.MD = 1.0;
      }
      break;

     case untitled_IN_OK:
      /* During 'OK': '<S5>:1' */
      if ((rtb_Saturation_c >= untitled_P.UpperThreshold_const) ||
          (rtb_Saturation_c <= untitled_P.LowerThreshold_const)) {
        /* Transition: '<S5>:3' */
        untitled_DW.is_c3_untitled = untitled_IN_ALERT;

        /* Entry 'ALERT': '<S5>:2' */
        untitled_B.MD = 1.0;
      }
      break;

     default:
      /* Saturate: '<S9>/Saturation' */
      /* During 'RESTORE': '<S5>:10' */
      if (0.0 > untitled_P.Saturation_UpperSat) {
        rtb_Saturation_c = untitled_P.Saturation_UpperSat;
      } else if (0.0 < untitled_P.Saturation_LowerSat) {
        rtb_Saturation_c = untitled_P.Saturation_LowerSat;
      } else {
        rtb_Saturation_c = 0.0;
      }

      if (rtb_Saturation_c == 0.0) {
        /* Transition: '<S5>:12' */
        untitled_DW.is_c3_untitled = untitled_IN_OK;

        /* Entry 'OK': '<S5>:1' */
        untitled_B.MD = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* DataTypeConversion: '<S4>/conversion1' */
  untitled_B.conversion1 = (untitled_B.MD != 0.0);

  /* DataTypeConversion: '<S4>/conversion3' */
  untitled_B.conversion3 = false;

  /* DataTypeConversion: '<S4>/conversion9' */
  untitled_B.conversion9 = false;

  /* DataTypeConversion: '<S4>/conversion10' */
  untitled_B.conversion10 = false;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Saturation_c = (untitled_DW.clockTickCounter <
                      untitled_P.PulseGenerator_Duty) &&
    (untitled_DW.clockTickCounter >= 0) ? untitled_P.PulseGenerator_Amp : 0.0;
  if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator_Period - 1.0) {
    untitled_DW.clockTickCounter = 0;
  } else {
    untitled_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Saturation_c > untitled_P.Saturation_UpperSat_l) {
    rtb_Saturation_c = untitled_P.Saturation_UpperSat_l;
  } else {
    if (rtb_Saturation_c < untitled_P.Saturation_LowerSat_o) {
      rtb_Saturation_c = untitled_P.Saturation_LowerSat_o;
    }
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* DataTypeConversion: '<S4>/conversion13' incorporates:
   *  Logic: '<S1>/Motor Enabler'
   *  Memory: '<S1>/Memory1'
   *  Product: '<S1>/Product'
   */
  untitled_B.conversion13 = (real32_T)((real_T)
    !(untitled_DW.Memory1_PreviousInput != 0.0) * rtb_Saturation_c);

  /* DataTypeConversion: '<S4>/conversion2' */
  untitled_B.conversion2 = 0.0F;

  /* DataTypeConversion: '<S4>/conversion4' */
  untitled_B.conversion4 = 0.0F;

  /* DataTypeConversion: '<S4>/conversion5' */
  untitled_B.conversion5 = 0.0F;

  /* DataTypeConversion: '<S4>/conversion6' */
  untitled_B.conversion6 = 0.0F;

  /* DataTypeConversion: '<S4>/conversion7' */
  untitled_B.conversion7 = 0.0F;

  /* S-Function (SerialTx): '<S4>/S-Function' */
  SerialTx_Outputs_wrapper(&untitled_B.SFunction2_o1, (boolean_T*)&untitled_BGND,
    (boolean_T*)&untitled_BGND, (boolean_T*)&untitled_BGND,
    &untitled_B.conversion1, &untitled_B.conversion3, &untitled_B.conversion9,
    &untitled_B.conversion10, &untitled_B.conversion13, &untitled_B.conversion2,
    &untitled_B.conversion4, &untitled_B.conversion5, &untitled_B.conversion6,
    &untitled_B.conversion7, &untitled_DW.SFunction_DSTATE,
    &untitled_P.SFunction_P1, 1, &untitled_P.SFunction_P2, 1);

  /* S-Function (sfun_tstart): '<S3>/startTime' */

  /* S-Function Block (sfun_tstart): <S3>/startTime */
  untitled_B.startTime = (0.0);

  /* S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   */
  MW_digitalWrite(untitled_P.DigitalOutput_pinNumber, (uint8_T)
                  untitled_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  MW_digitalWrite(untitled_P.DigitalOutput_pinNumber_i, (uint8_T)
                  untitled_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S2>/S-Function1' */
  data_struct_init_Outputs_wrapper( &untitled_DW.SFunction1_DSTATE);
}

/* Model update function */
void untitled_update(void)
{
  /* S-Function "signals_wrapper" Block: <S2>/S-Function2 */
  signals_Update_wrapper( &untitled_B.SFunction2_o1, &untitled_B.SFunction2_o2,
    &untitled_DW.SFunction2_DSTATE);

  /* Update for Memory: '<S1>/Memory2' */
  untitled_DW.Memory2_PreviousInput = 0.0;

  /* Update for UnitDelay: '<S6>/Delay Input1' */
  untitled_DW.DelayInput1_DSTATE = 0.0;

  /* Update for Memory: '<S1>/Memory1' */
  untitled_DW.Memory1_PreviousInput = untitled_B.MD;

  /* S-Function "SerialTx_wrapper" Block: <S4>/S-Function */
  SerialTx_Update_wrapper(&untitled_B.SFunction2_o1, (boolean_T*)&untitled_BGND,
    (boolean_T*)&untitled_BGND, (boolean_T*)&untitled_BGND,
    &untitled_B.conversion1, &untitled_B.conversion3, &untitled_B.conversion9,
    &untitled_B.conversion10, &untitled_B.conversion13, &untitled_B.conversion2,
    &untitled_B.conversion4, &untitled_B.conversion5, &untitled_B.conversion6,
    &untitled_B.conversion7, &untitled_DW.SFunction_DSTATE,
    &untitled_P.SFunction_P1, 1, &untitled_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S2>/S-Function1 */
  data_struct_init_Update_wrapper(&untitled_DW.SFunction1_DSTATE);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.t[0] =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(untitled_M))));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  untitled_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  untitled_DW.clockTickCounter = -1000;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_pinModeOutput(untitled_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' */
  MW_pinModeOutput(untitled_P.DigitalOutput_pinNumber_i);

  /* S-Function Block: <S2>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        untitled_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  untitled_DW.Memory2_PreviousInput = untitled_P.Memory2_X0;

  /* InitializeConditions for UnitDelay: '<S6>/Delay Input1' */
  untitled_DW.DelayInput1_DSTATE = untitled_P.DetectChange_vinit;

  /* InitializeConditions for Chart: '<S1>/Chart' */
  untitled_DW.is_active_c3_untitled = 0U;
  untitled_DW.is_c3_untitled = untitled_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  untitled_DW.Memory1_PreviousInput = untitled_P.Memory1_X0;

  /* S-Function Block: <S4>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        untitled_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S2>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        untitled_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
