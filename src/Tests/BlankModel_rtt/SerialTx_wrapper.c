

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
#include <Arduino.h>
#include "C:\MATLAB\SupportPackages\PoliArd\poliard_data.h"
boolean_T alarm_tx;
uint8_T	Signals2Send = 0;
# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
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
void SerialTx_Outputs_wrapper(const boolean_T *C1,
			const boolean_T *C2,
			const boolean_T *C3,
			const boolean_T *C4,
			const boolean_T *C5,
			const boolean_T *C6,
			const boolean_T *C7,
			const boolean_T *C8,
			const real32_T *S1,
			const real32_T *S2,
			const real32_T *S3,
			const real32_T *S4,
			const real32_T *S5,
			const real32_T *S6,
			const real_T *xD,
			const real_T  *sample_tx, const int_T  p_width0,
			const uint8_T  *s_send, const int_T  p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* wait until after initialization is done */
if (xD[0]==1) {
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE
    Signals2Send = s_send[0];
    
    if ((SignalAlarm == 1) || (SignalAlarmStudent == 1))
        alarm_tx = 1;
    else
        alarm_tx = 0;
    
    Data2Send.C = (uint8_T)(C1[0]<<7)+(uint8_T)(0<<6)+(uint8_T)(alarm_tx<<5)+(uint8_T)(C4[0]<<4)+(uint8_T)(C5[0]<<3)+(uint8_T)(C6[0]<<2)+(uint8_T)(C7[0]<<1)+(uint8_T)(C8[0]);

    Data2Send.S1 = S1[0];
    Data2Send.S2 = S2[0];
    Data2Send.S3 = S3[0];
    Data2Send.S4 = S4[0];
    Data2Send.S5 = S5[0];
    Data2Send.S6 = S6[0];

    Config.dataReady_f = 1;
# endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void SerialTx_Update_wrapper(const boolean_T *C1,
			const boolean_T *C2,
			const boolean_T *C3,
			const boolean_T *C4,
			const boolean_T *C5,
			const boolean_T *C6,
			const boolean_T *C7,
			const boolean_T *C8,
			const real32_T *S1,
			const real32_T *S2,
			const real32_T *S3,
			const real32_T *S4,
			const real32_T *S5,
			const real32_T *S6,
			real_T *xD,
			const real_T  *sample_tx,  const int_T  p_width0,
			const uint8_T  *s_send,  const int_T  p_width1)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE
        Signals2Send = s_send[0];
    # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
