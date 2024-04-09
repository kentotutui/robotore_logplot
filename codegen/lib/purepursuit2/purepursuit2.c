/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: purepursuit2.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 24-Feb-2024 18:18:03
 */

/* Include Files */
#include "purepursuit2.h"
#include "closestPointOnLine.h"
#include "purepursuit2_data.h"
#include "purepursuit2_initialize.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int i;
  int i1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      i = 1;
    } else {
      i = -1;
    }
    if (u1 > 0.0) {
      i1 = 1;
    } else {
      i1 = -1;
    }
    y = atan2(i, i1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

/*
 * ロボットの初期位置と速度
 *
 * Arguments    : void
 * Return Type  : void
 */
void purepursuit2(void)
{
  static const signed char waypts[6] = {2, 4, 6, 2, 4, 2};
  double robotPose[3];
  double controller_ProjectionPoint[2];
  double lookaheadStartPt[2];
  double x[2];
  double absxk;
  double alpha;
  double dist;
  double lookaheadEndPt_idx_1;
  double minDistance;
  double overshootDist;
  double scale;
  double t;
  double y;
  int absxk_tmp;
  int absxk_tmp_tmp;
  int b_absxk;
  int b_absxk_tmp;
  int controller_ProjectionLineIndex;
  int controller_isInitialized;
  int idx;
  int lookaheadIdx;
  int lookaheadStartPt_tmp_tmp_tmp;
  signed char tmp_data[3];
  boolean_T exitg1;
  boolean_T searchFlag;
  if (!isInitialized_purepursuit2) {
    purepursuit2_initialize();
  }
  /*  初期位置 [x, y, theta] */
  /*  初期速度 [m/s] */
  /*  経路の定義 */
  /*  経路の各点の座標 [x, y] */
  /*  Pure Pursuitコントローラの作成 */
  controller_isInitialized = 0;
  /*  シミュレーションの設定 */
  /*  ロボットの状態の初期化 */
  robotPose[0] = 0.0;
  robotPose[1] = 0.0;
  robotPose[2] = 0.0;
  /*  シミュレーションループ */
  tmp_data[0] = 0;
  tmp_data[1] = 1;
  tmp_data[2] = 2;
  for (idx = 0; idx < 101; idx++) {
    /*  Pure Pursuitコントローラを使用して、次のステアリング角を計算 */
    if (controller_isInitialized != 1) {
      controller_isInitialized = 1;
      controller_ProjectionPoint[0] = rtNaN;
      controller_ProjectionPoint[1] = rtNaN;
      controller_ProjectionLineIndex = 0;
    }
    searchFlag = false;
    if (controller_ProjectionLineIndex == 0) {
      searchFlag = true;
      controller_ProjectionPoint[0] = 2.0;
      controller_ProjectionPoint[1] = 2.0;
      controller_ProjectionLineIndex = 1;
    }
    lookaheadIdx = waypts[tmp_data[controller_ProjectionLineIndex]];
    lookaheadStartPt[0] = lookaheadIdx;
    lookaheadStartPt_tmp_tmp_tmp =
        waypts[tmp_data[controller_ProjectionLineIndex] + 3];
    lookaheadStartPt[1] = lookaheadStartPt_tmp_tmp_tmp;
    minDistance = closestPointOnLine(controller_ProjectionPoint,
                                     lookaheadStartPt, &robotPose[0]);
    scale = 3.3121686421112381E-170;
    controller_ProjectionPoint[0] = lookaheadStartPt[0];
    absxk = fabs(lookaheadStartPt[0] - (double)lookaheadIdx);
    if (absxk > 3.3121686421112381E-170) {
      dist = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      dist = t * t;
    }
    controller_ProjectionPoint[1] = lookaheadStartPt[1];
    absxk = fabs(lookaheadStartPt[1] - (double)lookaheadStartPt_tmp_tmp_tmp);
    if (absxk > scale) {
      t = scale / absxk;
      dist = dist * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      dist += t * t;
    }
    dist = scale * sqrt(dist);
    overshootDist = (double)controller_ProjectionLineIndex + 1.0;
    lookaheadIdx = 0;
    exitg1 = false;
    while ((!exitg1) &&
           (lookaheadIdx <= (int)((1.0 - overshootDist) + 2.0) - 1)) {
      alpha = overshootDist + (double)lookaheadIdx;
      if ((!searchFlag) && (dist > 1.0)) {
        exitg1 = true;
      } else {
        scale = 3.3121686421112381E-170;
        lookaheadStartPt_tmp_tmp_tmp = tmp_data[(int)alpha];
        absxk_tmp = waypts[lookaheadStartPt_tmp_tmp_tmp];
        absxk_tmp_tmp = tmp_data[(int)alpha - 1];
        b_absxk_tmp = waypts[absxk_tmp_tmp];
        b_absxk = (int)fabs((double)(b_absxk_tmp - absxk_tmp));
        if (b_absxk > 3.3121686421112381E-170) {
          t = 3.3121686421112381E-170 / (double)b_absxk;
          y = 0.0 * t * t + 1.0;
          scale = b_absxk;
        } else {
          t = (double)b_absxk / 3.3121686421112381E-170;
          y = t * t;
        }
        lookaheadStartPt[0] = absxk_tmp;
        x[0] = b_absxk_tmp;
        absxk_tmp = waypts[lookaheadStartPt_tmp_tmp_tmp + 3];
        b_absxk_tmp = waypts[absxk_tmp_tmp + 3];
        b_absxk = (int)fabs((double)(b_absxk_tmp - absxk_tmp));
        if (b_absxk > scale) {
          t = scale / (double)b_absxk;
          y = y * t * t + 1.0;
          scale = b_absxk;
        } else {
          t = (double)b_absxk / scale;
          y += t * t;
        }
        lookaheadStartPt[1] = absxk_tmp;
        x[1] = b_absxk_tmp;
        y = scale * sqrt(y);
        dist += y;
        absxk = closestPointOnLine(x, lookaheadStartPt, &robotPose[0]);
        if (absxk < minDistance) {
          minDistance = absxk;
          controller_ProjectionPoint[0] = lookaheadStartPt[0];
          controller_ProjectionPoint[1] = lookaheadStartPt[1];
          controller_ProjectionLineIndex = (int)alpha;
        }
        lookaheadIdx++;
      }
    }
    scale = 3.3121686421112381E-170;
    absxk_tmp = waypts[tmp_data[controller_ProjectionLineIndex]];
    absxk = fabs(controller_ProjectionPoint[0] - (double)absxk_tmp);
    if (absxk > 3.3121686421112381E-170) {
      dist = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      dist = t * t;
    }
    b_absxk_tmp = waypts[tmp_data[controller_ProjectionLineIndex] + 3];
    absxk = fabs(controller_ProjectionPoint[1] - (double)b_absxk_tmp);
    if (absxk > scale) {
      t = scale / absxk;
      dist = dist * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      dist += t * t;
    }
    dist = scale * sqrt(dist);
    lookaheadStartPt[0] = controller_ProjectionPoint[0];
    minDistance = absxk_tmp;
    lookaheadStartPt[1] = controller_ProjectionPoint[1];
    lookaheadEndPt_idx_1 = b_absxk_tmp;
    overshootDist = dist - 1.0;
    lookaheadIdx = controller_ProjectionLineIndex;
    while ((overshootDist < 0.0) && (lookaheadIdx < 2)) {
      lookaheadIdx = 2;
      lookaheadStartPt[0] = 4.0;
      minDistance = 6.0;
      lookaheadStartPt[1] = 4.0;
      lookaheadEndPt_idx_1 = 2.0;
      dist += 2.8284271247461903;
      overshootDist = dist - 1.0;
    }
    scale = 3.3121686421112381E-170;
    absxk = fabs(lookaheadStartPt[0] - minDistance);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(lookaheadStartPt[1] - lookaheadEndPt_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    alpha = overshootDist / y;
    if (alpha > 0.0) {
      minDistance = alpha * lookaheadStartPt[0] + (1.0 - alpha) * minDistance;
      lookaheadEndPt_idx_1 =
          alpha * lookaheadStartPt[1] + (1.0 - alpha) * lookaheadEndPt_idx_1;
    }
    alpha = rt_atan2d_snf(lookaheadEndPt_idx_1 - robotPose[1],
                          minDistance - robotPose[0]) -
            robotPose[2];
    if (fabs(alpha) > 3.1415926535897931) {
      if (rtIsNaN(alpha + 3.1415926535897931) ||
          rtIsInf(alpha + 3.1415926535897931)) {
        absxk = rtNaN;
      } else if (alpha + 3.1415926535897931 == 0.0) {
        absxk = 0.0;
      } else {
        absxk = fmod(alpha + 3.1415926535897931, 6.2831853071795862);
        searchFlag = (absxk == 0.0);
        if (!searchFlag) {
          overshootDist =
              fabs((alpha + 3.1415926535897931) / 6.2831853071795862);
          searchFlag = !(fabs(overshootDist - floor(overshootDist + 0.5)) >
                         2.2204460492503131E-16 * overshootDist);
        }
        if (searchFlag) {
          absxk = 0.0;
        } else if (alpha + 3.1415926535897931 < 0.0) {
          absxk += 6.2831853071795862;
        }
      }
      if ((absxk == 0.0) && (alpha + 3.1415926535897931 > 0.0)) {
        absxk = 6.2831853071795862;
      }
      alpha = absxk - 3.1415926535897931;
    }
    absxk = 2.0 * sin(alpha);
    if ((fabs(fabs(alpha) - 3.1415926535897931) < 1.4901161193847656E-8) &&
        (!rtIsNaN(absxk))) {
      if (absxk < 0.0) {
        absxk = -1.0;
      } else {
        absxk = (absxk > 0.0);
      }
    }
    /*  ロボットの状態を更新 */
    overshootDist = robotPose[0] + cos(robotPose[2]) * 0.1;
    alpha = robotPose[1] + sin(robotPose[2]) * 0.1;
    absxk = robotPose[2] + absxk * 0.1;
    robotPose[0] = overshootDist;
    robotPose[1] = alpha;
    robotPose[2] = absxk;
    /*  ロボットの位置を描画 */
  }
}

/*
 * File trailer for purepursuit2.c
 *
 * [EOF]
 */
