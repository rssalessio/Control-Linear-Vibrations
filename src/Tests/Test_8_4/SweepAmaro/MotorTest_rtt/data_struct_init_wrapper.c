

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
# include <math.h>
#include "C:\MATLAB\SupportPackages\PoliArd\poliard_data.h"

/* Main struct */
Data2Send_T Data2Send;
Config_T    Config;

volatile Encoder_T Enc[4] = {	{PIN_ENC_1A,PIN_ENC_1B, 0, 0}, 
				{PIN_ENC_2A,PIN_ENC_2B, 0, 0},
				{PIN_ENC_3A,PIN_ENC_3B, 0, 0},
				{PIN_ENC_4A,PIN_ENC_4B, 0, 0}
};
   
volatile Motor_T Motor[2] = {	{PIN_M1_ENABLE, PIN_M1_PWM1, PIN_M1_PWM2, PIN_M1_CURRENT, PIN_M1_6V, PIN_M1_12V, PIN_M1_24V}, 
				{PIN_M2_ENABLE, PIN_M2_PWM1, PIN_M2_PWM2, PIN_M2_CURRENT, PIN_M2_6V, PIN_M2_12V, PIN_M2_24V}
};

/* Alarm */
uint8_T SignalAlarm         = 0;
uint8_T SignalAlarmStudent  = 0;
uint8_T SignalEnable        = 0;

boolean_T drA_0, drB_0;
boolean_T drA_1, drB_1;
boolean_T drA_2, drB_2;
boolean_T drA_3, drB_3;


/* auxiliary debouncing function                             */
void debounce(int del) {
  int k;
  for (k=0; k<del; k++)
  {
    /* can't use delay in the ISR so need to waste some time
       perfoming operations, this uses roughly 0.1ms on uno  */
    k = k +0.0 +0.0 -0.0 +3.0 -3.0;
  }
}

/* Interrupt Service Routine: change on pin A for Encoder 0  */
void isrPinAEn0(){

/*
  int drB = digitalRead(Enc[0].pinB);
  int drA = digitalRead(Enc[0].pinA);
*/
  //drA_0 = (PIOA->PIO_PDSR & (1<<14)); // read pin 23 - A.14 - OK
  drA_0 = digitalRead(PIN_ENC_1A);
  drB_0 = (PIOD->PIO_PDSR & (1<<0));  // read pin 25 - D.0 - OK

  if (drA_0)
  {
    if (drB_0 == false)
  	  Enc[0].pos++;
    else
  	  Enc[0].pos--;
  }
  else
  {
    if (drB_0)
  	  Enc[0].pos++;
    else
  	  Enc[0].pos--;
  }
} /* end ISR pin A Encoder 0                                 */

/* Interrupt Service Routine: change on pin A for Encoder 1  */
void isrPinAEn1(){
/*
  int drB = digitalRead(Enc[1].pinB);
  int drA = digitalRead(Enc[1].pinA);
*/
  drA_1 = (PIOD->PIO_PDSR & (1<<2));    // read pin 27 - D.2 - OK
  //drB_1 = (PIOD->PIO_PDSR & (1<<6));    // read pin 29 - D.6 - OK
  drB_1 = digitalRead(PIN_ENC_2B);

  if (drA_1)
  {
    if (drB_1 == false)
      Enc[1].pos++;
    else
      Enc[1].pos--;
  }
  else
  {
    if (drB_1)
      Enc[1].pos++;
    else
      Enc[1].pos--;
  }
} /* end ISR pin A Encoder 1                                 */


/* Interrupt Service Routine: change on pin A for Encoder 2  */
void isrPinAEn2(){
/*
  int drB = digitalRead(Enc[2].pinB);
  int drA = digitalRead(Enc[2].pinA);
*/
  drA_2 = (PIOA->PIO_PDSR & (1<<7));    // read pin 31 - A.7 - OK
  drB_2 = (PIOC->PIO_PDSR & (1<<1));    // read pin 33 - C.1 - OK

  if (drA_2)
  {
    if (drB_2 == false)
  	  Enc[2].pos++;
    else
  	  Enc[2].pos--;
  }
  else
  {
    if (drB_2)
  	  Enc[2].pos++;
    else
  	  Enc[2].pos--;
  }
} /* end ISR pin A Encoder 2                                 */



/* Interrupt Service Routine: change on pin A for Encoder 1  */
void isrPinAEn3(){

/*
  int drB_3 = digitalRead(Enc[3].pinB);
  int drA_3 = digitalRead(Enc[3].pinA);
*/
  drA_3 = (PIOC->PIO_PDSR & (1<<3));    // read pin 35 - C.3 - OK
  drB_3 = (PIOC->PIO_PDSR & (1<<5));    // read pin 37 - C.5 - OK

  if (drA_3)
  {
    if (drB_3 == false)
  	  Enc[3].pos++;
    else
  	  Enc[3].pos--;
  }
  else
  {
    if (drB_3)
  	  Enc[3].pos++;
    else
  	  Enc[3].pos--;
  }
} /* end ISR pin A Encoder 3                                 */

# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 
#define y_width 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void data_struct_init_Outputs_wrapper(const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* wait until after initialization is done */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE


    # endif

}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void data_struct_init_Update_wrapper(real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE
    
        analogWriteResolution(12);
        analogReadResolution(12);

        /* Switch */
        pinMode(PIN_SWITCH1, INPUT);
        pinMode(PIN_SWITCH2, INPUT);
        pinMode(PIN_SWITCH3, INPUT);
        
        /* Setup encoder pins */
        pinMode(PIN_ENC_1A, INPUT);
        pinMode(PIN_ENC_1B, INPUT);
        pinMode(PIN_ENC_2A, INPUT);
        pinMode(PIN_ENC_2B, INPUT);
        pinMode(PIN_ENC_3A, INPUT);
        pinMode(PIN_ENC_3B, INPUT);
        pinMode(PIN_ENC_4A, INPUT);
        pinMode(PIN_ENC_4B, INPUT);
        
        /* Setup motor pins */
        pinMode(PIN_M1_ENABLE, OUTPUT);
        pinMode(PIN_M2_ENABLE, OUTPUT);
        pinMode(PIN_M1_PWM1, OUTPUT);
        pinMode(PIN_M1_PWM2, OUTPUT);
        pinMode(PIN_M2_PWM1, OUTPUT);
        pinMode(PIN_M2_PWM2, OUTPUT);
        
        pinMode(PIN_M1_6V, INPUT);
        pinMode(PIN_M1_12V, INPUT);
        pinMode(PIN_M1_24V, INPUT);
        pinMode(PIN_M2_6V, INPUT);
        pinMode(PIN_M2_12V, INPUT);
        pinMode(PIN_M2_24V, INPUT);
         
        // Init motor pins
        digitalWrite(PIN_M1_ENABLE, LOW);
        digitalWrite(PIN_M2_ENABLE, LOW);
        digitalWrite(PIN_M1_PWM1, LOW);
        digitalWrite(PIN_M1_PWM2, LOW);
        digitalWrite(PIN_M2_PWM1, LOW);
        digitalWrite(PIN_M2_PWM2, LOW);
        
        // Init debug pin
        pinMode(PIN_DEBUG1, OUTPUT);
        pinMode(PIN_DEBUG2, OUTPUT);
        pinMode(PIN_DEBUG3, OUTPUT);
        digitalWrite(PIN_DEBUG1, LOW);
        digitalWrite(PIN_DEBUG2, LOW);
        digitalWrite(PIN_DEBUG3, LOW);
        
        Config.dataReadyCounter = 0;
        Config.dataReady_f      = 0;

        Serial_begin(0, 115200);
        
        // Attach encoder interrupts
        attachInterrupt(PIN_ENC_1A, isrPinAEn0, ENC1_TRIGGER);
        attachInterrupt(PIN_ENC_2A, isrPinAEn1, ENC2_TRIGGER);
        attachInterrupt(PIN_ENC_3A, isrPinAEn2, ENC3_TRIGGER);
        attachInterrupt(PIN_ENC_4A, isrPinAEn3, ENC4_TRIGGER);
        
        pinMode(42, OUTPUT);     
        digitalWrite(42,LOW);
    # endif

    /* initialization done */
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
