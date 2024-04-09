/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: closestPointOnLine.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 24-Feb-2024 18:18:03
 */

/* Include Files */
#include "closestPointOnLine.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double pt1[2]
 *                double pt2[2]
 *                const double refPt[2]
 * Return Type  : double
 */
double closestPointOnLine(const double pt1[2], double pt2[2],
                          const double refPt[2])
{
  double absxk;
  double alpha;
  double distance;
  double t;
  double v12;
  int k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(pt1[k] == pt2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (p) {
    alpha = 3.3121686421112381E-170;
    pt2[0] = pt1[0];
    absxk = fabs(refPt[0] - pt1[0]);
    if (absxk > 3.3121686421112381E-170) {
      distance = 1.0;
      alpha = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      distance = t * t;
    }
    pt2[1] = pt1[1];
    absxk = fabs(refPt[1] - pt1[1]);
    if (absxk > alpha) {
      t = alpha / absxk;
      distance = distance * t * t + 1.0;
      alpha = absxk;
    } else {
      t = absxk / alpha;
      distance += t * t;
    }
    distance = alpha * sqrt(distance);
  } else {
    alpha = pt2[0];
    absxk = alpha - pt1[0];
    t = absxk * (alpha - refPt[0]);
    v12 = absxk * absxk;
    alpha = pt2[1];
    absxk = alpha - pt1[1];
    t += absxk * (alpha - refPt[1]);
    v12 += absxk * absxk;
    alpha = t / v12;
    if (alpha > 1.0) {
      pt2[0] = pt1[0];
      pt2[1] = pt1[1];
    } else if (!(alpha < 0.0)) {
      pt2[0] = alpha * pt1[0] + (1.0 - alpha) * pt2[0];
      pt2[1] = alpha * pt1[1] + (1.0 - alpha) * pt2[1];
    }
    alpha = 3.3121686421112381E-170;
    absxk = fabs(refPt[0] - pt2[0]);
    if (absxk > 3.3121686421112381E-170) {
      distance = 1.0;
      alpha = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      distance = t * t;
    }
    absxk = fabs(refPt[1] - pt2[1]);
    if (absxk > alpha) {
      t = alpha / absxk;
      distance = distance * t * t + 1.0;
      alpha = absxk;
    } else {
      t = absxk / alpha;
      distance += t * t;
    }
    distance = alpha * sqrt(distance);
  }
  return distance;
}

/*
 * File trailer for closestPointOnLine.c
 *
 * [EOF]
 */
