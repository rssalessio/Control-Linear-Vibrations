

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
void sfcn_encoder_Outputs_wrapper(const boolean_T *reset,
			int32_T *pos,
			const real_T *xD,
			const uint8_T  *enc, const int_T  p_width0,
			const real_T  *sample_t_enc, const int_T  p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* wait until after initialization is done */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE
    
        /* Reset encoder position */
        if (reset[0])
            Enc[enc[0]-1].pos = 0;

        /* Get encoder position and set is as output */
        pos[0] = Enc[enc[0]-1].pos;

    # endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void sfcn_encoder_Update_wrapper(const boolean_T *reset,
			const int32_T *pos,
			real_T *xD,
			const uint8_T  *enc,  const int_T  p_width0,
			const real_T  *sample_t_enc,  const int_T  p_width1)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE

    # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
