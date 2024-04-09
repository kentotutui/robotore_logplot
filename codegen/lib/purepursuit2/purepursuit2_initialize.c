/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: purepursuit2_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 24-Feb-2024 18:18:03
 */

/* Include Files */
#include "purepursuit2_initialize.h"
#include "purepursuit2_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void purepursuit2_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_purepursuit2 = true;
}

/*
 * File trailer for purepursuit2_initialize.c
 *
 * [EOF]
 */
