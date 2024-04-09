/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_purepursuit2_mex.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 24-Feb-2024 18:18:03
 */

#ifndef _CODER_PUREPURSUIT2_MEX_H
#define _CODER_PUREPURSUIT2_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_purepursuit2_mexFunction(int32_T nlhs, int32_T nrhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_purepursuit2_mex.h
 *
 * [EOF]
 */
