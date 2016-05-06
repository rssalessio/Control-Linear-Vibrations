

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
#include "C:\MATLAB\SupportPackages\PoliArd\poliard_data.h"
uint16_T PWM_mot;

uint8_T m6v = 1, m12v = 1, m24v = 1;
uint8_T VoltageSelection;

real32_T Arrigon = 0.0;
real32_T Curr    = 0.0;
real_T   Vmot	 = 0.0;
uint8_T  DCbus;
int16_T Analog;

# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
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
void sfcn_motor_new_Outputs_wrapper(const real32_T *V_mot,
			const boolean_T *Motor_en,
			real32_T *Current,
			real32_T *Debug1,
			real32_T *Debug2,
			const real_T *xD,
			const uint8_T  *mot, const int_T  p_width0,
			const real32_T  *DC_bus, const int_T  p_width1,
			const real32_T  *sample_t_mot, const int_T  p_width2)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* wait until after initialization is done */
if (xD[0] == 1)
{
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE

    /* Get motor voltage from HW */
    m6v  = digitalRead(Motor[mot[0]-1].m6v);
    m12v = digitalRead(Motor[mot[0]-1].m12v);
    m24v = digitalRead(Motor[mot[0]-1].m24v);
    
    if ((m6v == 1) && (m12v == 1) && (m24v == 0))
        VoltageSelection = 24;
    else if ((m6v == 1) && (m12v == 0) && (m24v == 1))
        VoltageSelection = 12;
    else if ((m6v == 0) && (m12v == 1) && (m24v == 1))
        VoltageSelection = 6;
    else
        VoltageSelection = 1;
        
    /* DC_bus[0] indicates combobox item position, not the value */
    if ((DC_bus[0] == 1) && (VoltageSelection == 6))
        DCbus = 6;
    else if ((DC_bus[0] == 2) && (VoltageSelection == 12))
        DCbus = 12;
    else if ((DC_bus[0] == 3) && (VoltageSelection == 24))
        DCbus = 24;
    else 
    {
        /* Bad configuration -> Set low voltage */
        DCbus = 6;
    }
    
    // Controllo valori MAX/MIN
    if (V_mot[0] > DCbus)
        Vmot = DCbus;
    else if (V_mot[0] < -DCbus)
        Vmot = -DCbus;
    else
        Vmot = V_mot[0];

    // Se il motore e' abilitato
    if (Motor_en[0])
    {  
        // Calculate PWM
        Arrigon = (abs(Vmot)/24)*4095;
        PWM_mot = (uint16_T) Arrigon;

        if (Vmot < 0)
        {
            analogWrite(Motor[mot[0]-1].PWM1, PWM_mot);
            analogWrite(Motor[mot[0]-1].PWM2, 0);
        }
        else if (Vmot > 0)
        {
            analogWrite(Motor[mot[0]-1].PWM1, 0);
            analogWrite(Motor[mot[0]-1].PWM2, PWM_mot);
        }
        else
        {
            analogWrite(Motor[mot[0]-1].PWM1, 0);
            analogWrite(Motor[mot[0]-1].PWM2, 0);
        }
        
        // Enable motor
        digitalWrite(Motor[mot[0]-1].enable, HIGH);
    }
    else
    {
        PWM_mot = 0;
        // Disable motor
        digitalWrite(Motor[mot[0]-1].enable, LOW);
        analogWrite(Motor[mot[0]-1].PWM1, 0);
        analogWrite(Motor[mot[0]-1].PWM2, 0);
    }
    
    //ACS712
    Analog = (analogRead(Motor[mot[0]-1].current)-CURRENT_OFFSET_BITS);
    Current[0] = Analog/CURRENT_SENSITIVITY;
    Debug1[0]  = PWM_mot;
    Debug2[0]  = DCbus;
    
    if (Current[0] >= CURRENT_TRESHOLD_ALARM)
        SignalAlarm = 1;
    else
        SignalAlarm = 0;

# endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void sfcn_motor_new_Update_wrapper(const real32_T *V_mot,
			const boolean_T *Motor_en,
			const real32_T *Current,
			const real32_T *Debug1,
			const real32_T *Debug2,
			real_T *xD,
			const uint8_T  *mot,  const int_T  p_width0,
			const real32_T  *DC_bus,  const int_T  p_width1,
			const real32_T  *sample_t_mot,  const int_T  p_width2)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE

        // Select DC bus voltage
        if (DC_bus[0] == 1)
            DCbus = 12;
        else if (DC_bus[0] == 2)
            DCbus = 24;
        else
            DCbus = 12;
    
    # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
