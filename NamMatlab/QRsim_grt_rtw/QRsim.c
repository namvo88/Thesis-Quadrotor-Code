/*
 * QRsim.c
 *
 * Code generation for model "QRsim".
 *
 * Model version              : 1.240
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Thu Apr 06 15:12:38 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "QRsim.h"
#include "QRsim_private.h"

/* Block signals (auto storage) */
B_QRsim_T QRsim_B;

/* Continuous states */
X_QRsim_T QRsim_X;

/* Block states (auto storage) */
DW_QRsim_T QRsim_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_QRsim_T QRsim_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_QRsim_T QRsim_Y;

/* Real-time model */
RT_MODEL_QRsim_T QRsim_M_;
RT_MODEL_QRsim_T *const QRsim_M = &QRsim_M_;

/* Forward declaration for local functions */
static real_T QRsim_dot(const real_T a[3], const real_T b[3]);

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
  int_T nXc = 24;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  QRsim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  QRsim_step();
  QRsim_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  QRsim_step();
  QRsim_derivatives();

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

/* Function for MATLAB Function: '<S3>/dxL block' */
static real_T QRsim_dot(const real_T a[3], const real_T b[3])
{
  return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2];
}

/* Model step function */
void QRsim_step(void)
{
  /* local block i/o variables */
  real_T rtb_dRdesTR[9];
  real_T rtb_dRc[9];
  real_T rtb_R[9];
  real_T rtb_TmpSignalConversionAtToWork[9];
  real_T rtb_simout[27];
  real_T rtb_TmpSignalConversionAtToWo_e[6];
  int8_T I[9];
  real_T Omegadhat[9];
  real_T scale;
  real_T absxk;
  real_T A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T c;
  real_T s;
  int32_T b_ix;
  int32_T iy;
  int32_T ijA;
  real_T rtb_Product_n[3];
  int32_T idxStart;
  int32_T idx;
  real_T rtb_MathFunction1;
  real_T rtb_Switch[4];
  real_T rtb_Elementproduct[6];
  real_T rtb_fi[4];
  real_T rtb_MathFunction[3];
  int32_T i;
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T tmp_2[3];
  real_T tmp_3[9];
  real_T tmp_4[9];
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* set solver stop time */
    if (!(QRsim_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QRsim_M->solverInfo, ((QRsim_M->Timing.clockTickH0
        + 1) * QRsim_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QRsim_M->solverInfo, ((QRsim_M->Timing.clockTick0 +
        1) * QRsim_M->Timing.stepSize0 + QRsim_M->Timing.clockTickH0 *
        QRsim_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QRsim_M)) {
    QRsim_M->Timing.t[0] = rtsiGetT(&QRsim_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Inport: '<Root>/In1'
     */
    QRsim_Y.Out1 = QRsim_U.In1;

    /* Constant: '<S63>/Constant1' */
    memcpy(&QRsim_B.Constant1[0], &QRsim_P.Constant1_Value_j[0], 9U * sizeof
           (real_T));
  }

  /* Integrator: '<S63>/Integrator' */
  if (QRsim_DW.Integrator_IWORK.IcNeedsLoading) {
    {
      int_T i1;
      real_T *xc = &QRsim_X.R[0];
      const real_T *u1 = &QRsim_B.Constant1[0];
      for (i1=0; i1 < 9; i1++) {
        xc[i1] = u1[i1];
      }
    }
  }

  {
    int_T i1;
    real_T *y0 = &rtb_R[0];
    real_T *xc = &QRsim_X.R[0];
    for (i1=0; i1 < 9; i1++) {
      y0[i1] = xc[i1];
    }
  }

  /* Saturate: '<S63>/Saturation' */
  for (i = 0; i < 9; i++) {
    if (rtb_R[i] >= QRsim_P.Saturation_UpperSat) {
      QRsim_B.R_L[i] = QRsim_P.Saturation_UpperSat;
    } else if (rtb_R[i] <= QRsim_P.Saturation_LowerSat) {
      QRsim_B.R_L[i] = QRsim_P.Saturation_LowerSat;
    } else {
      QRsim_B.R_L[i] = rtb_R[i];
    }
  }

  /* End of Saturate: '<S63>/Saturation' */

  /* Gain: '<S6>/e3 ' */
  for (i = 0; i < 3; i++) {
    QRsim_B.e3[i] = 0.0;
    QRsim_B.e3[i] += QRsim_B.R_L[i] * QRsim_P.e3_Gain[0];
    QRsim_B.e3[i] += QRsim_B.R_L[i + 3] * QRsim_P.e3_Gain[1];
    QRsim_B.e3[i] += QRsim_B.R_L[i + 6] * QRsim_P.e3_Gain[2];
  }

  /* End of Gain: '<S6>/e3 ' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* ToWorkspace: '<S6>/To Workspace' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace_PWORK.LoggedData, &locTime,
                            &QRsim_B.e3[0]);
    }
  }

  /* Derivative: '<S9>/Derivative' */
  {
    real_T t = QRsim_M->Timing.t[0];
    real_T timeStampA = QRsim_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = QRsim_DW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &QRsim_DW.Derivative_RWORK.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      QRsim_B.dxd[0] = 0.0;
      QRsim_B.dxd[1] = 0.0;
      QRsim_B.dxd[2] = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &QRsim_DW.Derivative_RWORK.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &QRsim_DW.Derivative_RWORK.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;
      QRsim_B.dxd[0] = (QRsim_P.xdes_Value[0] - *lastU++) / deltaT;
      QRsim_B.dxd[1] = (QRsim_P.xdes_Value[1] - *lastU++) / deltaT;
      QRsim_B.dxd[2] = (QRsim_P.xdes_Value[2] - *lastU++) / deltaT;
    }
  }

  /* Derivative: '<S9>/Derivative1' */
  {
    real_T t = QRsim_M->Timing.t[0];
    real_T timeStampA = QRsim_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = QRsim_DW.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &QRsim_DW.Derivative1_RWORK.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      QRsim_B.ddxd[0] = 0.0;
      QRsim_B.ddxd[1] = 0.0;
      QRsim_B.ddxd[2] = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &QRsim_DW.Derivative1_RWORK.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;
      QRsim_B.ddxd[0] = (QRsim_B.dxd[0] - *lastU++) / deltaT;
      QRsim_B.ddxd[1] = (QRsim_B.dxd[1] - *lastU++) / deltaT;
      QRsim_B.ddxd[2] = (QRsim_B.dxd[2] - *lastU++) / deltaT;
    }
  }

  /* Gain: '<S9>/mQ' */
  QRsim_B.mQ[0] = QRsim_P.mQ_Gain * QRsim_B.ddxd[0];
  QRsim_B.mQ[1] = QRsim_P.mQ_Gain * QRsim_B.ddxd[1];
  QRsim_B.mQ[2] = QRsim_P.mQ_Gain * QRsim_B.ddxd[2];
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Constant: '<S61>/xL0' */
    QRsim_B.xL0 = QRsim_P.xL0_Value;

    /* Constant: '<S61>/yL0' */
    QRsim_B.yL0 = QRsim_P.yL0_Value;

    /* Constant: '<S61>/zL0' */
    QRsim_B.zL0 = QRsim_P.zL0_Value;
  }

  /* Integrator: '<S3>/Position' */
  if (QRsim_DW.Position_IWORK.IcNeedsLoading) {
    QRsim_X.position[0] = QRsim_B.xL0;
    QRsim_X.position[1] = QRsim_B.yL0;
    QRsim_X.position[2] = QRsim_B.zL0;
  }

  QRsim_B.states[0] = QRsim_X.position[0];
  QRsim_B.states[1] = QRsim_X.position[1];
  QRsim_B.states[2] = QRsim_X.position[2];

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<Root>/xdes'
   */
  QRsim_B.ex[0] = QRsim_B.states[0] - QRsim_P.xdes_Value[0];
  QRsim_B.ex[1] = QRsim_B.states[1] - QRsim_P.xdes_Value[1];
  QRsim_B.ex[2] = QRsim_B.states[2] - QRsim_P.xdes_Value[2];

  /* Gain: '<S9>/kx' */
  QRsim_B.kx[0] = QRsim_P.kx_Gain * QRsim_B.ex[0];
  QRsim_B.kx[1] = QRsim_P.kx_Gain * QRsim_B.ex[1];
  QRsim_B.kx[2] = QRsim_P.kx_Gain * QRsim_B.ex[2];
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Constant: '<S62>/dx0' */
    QRsim_B.dx0 = QRsim_P.dx0_Value;

    /* Constant: '<S62>/dy0' */
    QRsim_B.dy0 = QRsim_P.dy0_Value;

    /* Constant: '<S62>/dz0' */
    QRsim_B.dz0 = QRsim_P.dz0_Value;

    /* Constant: '<S62>/p0' */
    QRsim_B.p0 = QRsim_P.p0_Value;

    /* Constant: '<S62>/q0' */
    QRsim_B.q0 = QRsim_P.q0_Value;

    /* Constant: '<S62>/r0' */
    QRsim_B.r0 = QRsim_P.r0_Value;
  }

  /* Integrator: '<S3>/Velocity' */
  if (QRsim_DW.Velocity_IWORK.IcNeedsLoading) {
    QRsim_X.velocity[0] = QRsim_B.dx0;
    QRsim_X.velocity[1] = QRsim_B.dy0;
    QRsim_X.velocity[2] = QRsim_B.dz0;
    QRsim_X.velocity[3] = QRsim_B.p0;
    QRsim_X.velocity[4] = QRsim_B.q0;
    QRsim_X.velocity[5] = QRsim_B.r0;
  }

  {
    int_T i1;
    real_T *y0 = &QRsim_B.statesdot[0];
    real_T *xc = &QRsim_X.velocity[0];
    for (i1=0; i1 < 6; i1++) {
      y0[i1] = xc[i1];
    }
  }

  /* Sum: '<S9>/Sum1' */
  QRsim_B.ev[0] = QRsim_B.statesdot[0] - QRsim_B.dxd[0];
  QRsim_B.ev[1] = QRsim_B.statesdot[1] - QRsim_B.dxd[1];
  QRsim_B.ev[2] = QRsim_B.statesdot[2] - QRsim_B.dxd[2];

  /* Gain: '<S9>/kv' */
  QRsim_B.kv[0] = QRsim_P.kv_Gain * QRsim_B.ev[0];
  QRsim_B.kv[1] = QRsim_P.kv_Gain * QRsim_B.ev[1];
  QRsim_B.kv[2] = QRsim_P.kv_Gain * QRsim_B.ev[2];

  /* Gain: '<S6>/Gain5' incorporates:
   *  Constant: '<S9>/constant'
   *  Gain: '<S8>/Gain5'
   *  Product: '<S8>/Divide'
   *  Sum: '<S8>/Add'
   */
  QRsim_B.fatt = (((QRsim_B.mQ[2] - QRsim_B.kx[2]) - QRsim_B.kv[2]) -
                  QRsim_P.constant_Value[2]) * QRsim_P.Gain5_Gain / QRsim_B.e3[2]
    * QRsim_P.Gain5_Gain_n;

  /* Sum: '<S10>/Add' incorporates:
   *  Constant: '<S9>/constant'
   */
  QRsim_B.trackingconstant[0] = ((QRsim_B.mQ[0] - QRsim_B.kx[0]) - QRsim_B.kv[0])
    - QRsim_P.constant_Value[0];
  QRsim_B.trackingconstant[1] = ((QRsim_B.mQ[1] - QRsim_B.kx[1]) - QRsim_B.kv[1])
    - QRsim_P.constant_Value[1];
  QRsim_B.trackingconstant[2] = ((QRsim_B.mQ[2] - QRsim_B.kx[2]) - QRsim_B.kv[2])
    - QRsim_P.constant_Value[2];

  /* DotProduct: '<S10>/Dot Product' incorporates:
   *  Gain: '<S10>/Gain1'
   */
  QRsim_B.fpos = (QRsim_P.Gain1_Gain * QRsim_B.trackingconstant[0] * QRsim_B.e3
                  [0] + QRsim_P.Gain1_Gain * QRsim_B.trackingconstant[1] *
                  QRsim_B.e3[1]) + QRsim_P.Gain1_Gain *
    QRsim_B.trackingconstant[2] * QRsim_B.e3[2];
  if (rtmIsMajorTimeStep(QRsim_M)) {
  }

  /* S-Function (sdsp2norm2): '<S10>/Normalization' */
  s = 1.0 / (sqrt((QRsim_B.trackingconstant[0] * QRsim_B.trackingconstant[0] +
                   QRsim_B.trackingconstant[1] * QRsim_B.trackingconstant[1]) +
                  QRsim_B.trackingconstant[2] * QRsim_B.trackingconstant[2]) +
             QRsim_P.Normalization_BIAS);
  QRsim_B.Normalization[0] = QRsim_B.trackingconstant[0] * s;
  QRsim_B.Normalization[1] = QRsim_B.trackingconstant[1] * s;
  QRsim_B.Normalization[2] = QRsim_B.trackingconstant[2] * s;

  /* Gain: '<S6>/Gain1' incorporates:
   *  Gain: '<S10>/Gain3'
   */
  QRsim_B.b3cd[0] = QRsim_P.Gain3_Gain * QRsim_B.Normalization[0] *
    QRsim_P.Gain1_Gain_c;
  QRsim_B.b3cd[1] = QRsim_P.Gain3_Gain * QRsim_B.Normalization[1] *
    QRsim_P.Gain1_Gain_c;
  QRsim_B.b3cd[2] = QRsim_P.Gain3_Gain * QRsim_B.Normalization[2] *
    QRsim_P.Gain1_Gain_c;
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* SignalConversion: '<S9>/TmpSignal ConversionAtTo Workspace1Inport1' incorporates:
     *  Constant: '<Root>/xdes'
     */
    rtb_TmpSignalConversionAtToWork[0] = QRsim_P.xdes_Value[0];
    rtb_TmpSignalConversionAtToWork[1] = QRsim_P.xdes_Value[1];
    rtb_TmpSignalConversionAtToWork[2] = QRsim_P.xdes_Value[2];
    rtb_TmpSignalConversionAtToWork[3] = QRsim_B.dxd[0];
    rtb_TmpSignalConversionAtToWork[4] = QRsim_B.dxd[1];
    rtb_TmpSignalConversionAtToWork[5] = QRsim_B.dxd[2];
    rtb_TmpSignalConversionAtToWork[6] = QRsim_B.ddxd[0];
    rtb_TmpSignalConversionAtToWork[7] = QRsim_B.ddxd[1];
    rtb_TmpSignalConversionAtToWork[8] = QRsim_B.ddxd[2];

    /* ToWorkspace: '<S9>/To Workspace1' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace1_PWORK.LoggedData, &locTime,
                            &rtb_TmpSignalConversionAtToWork[0]);
    }
  }

  /* Math: '<S11>/Math Function' */
  rtb_MathFunction[0] = QRsim_B.trackingconstant[0] * QRsim_B.trackingconstant[0];
  rtb_MathFunction[1] = QRsim_B.trackingconstant[1] * QRsim_B.trackingconstant[1];
  rtb_MathFunction[2] = QRsim_B.trackingconstant[2] * QRsim_B.trackingconstant[2];

  /* Sum: '<S11>/Sum of Elements' */
  rtb_MathFunction1 = (rtb_MathFunction[0] + rtb_MathFunction[1]) +
    rtb_MathFunction[2];

  /* Math: '<S11>/Math Function1'
   *
   * About '<S11>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1 < 0.0) {
    rtb_MathFunction1 = -sqrt(fabs(rtb_MathFunction1));
  } else {
    rtb_MathFunction1 = sqrt(rtb_MathFunction1);
  }

  /* End of Math: '<S11>/Math Function1' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Product: '<S11>/Product'
   */
  if (rtb_MathFunction1 > QRsim_P.Switch_Threshold) {
    rtb_Switch[0] = QRsim_B.trackingconstant[0];
    rtb_Switch[1] = QRsim_B.trackingconstant[1];
    rtb_Switch[2] = QRsim_B.trackingconstant[2];
    rtb_Switch[3] = rtb_MathFunction1;
  } else {
    rtb_Switch[0] = QRsim_B.trackingconstant[0] * 0.0;
    rtb_Switch[1] = QRsim_B.trackingconstant[1] * 0.0;
    rtb_Switch[2] = QRsim_B.trackingconstant[2] * 0.0;
    rtb_Switch[3] = QRsim_P.Constant_Value_d;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Product: '<S11>/Divide' */
  QRsim_B.Divide[0] = rtb_Switch[0] / rtb_Switch[3];
  QRsim_B.Divide[1] = rtb_Switch[1] / rtb_Switch[3];
  QRsim_B.Divide[2] = rtb_Switch[2] / rtb_Switch[3];
  if (rtmIsMajorTimeStep(QRsim_M)) {
  }

  /* MATLAB Function: '<S12>/Rdes block' incorporates:
   *  Constant: '<Root>/b1d'
   */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010/Rdes block': '<S16>:1' */
  /*  */
  /* '<S16>:1:3' */
  QRsim_B.b2d[0] = QRsim_B.b3cd[1] * QRsim_P.b1d_Value[2] - QRsim_B.b3cd[2] *
    QRsim_P.b1d_Value[1];
  QRsim_B.b2d[1] = QRsim_B.b3cd[2] * QRsim_P.b1d_Value[0] - QRsim_B.b3cd[0] *
    QRsim_P.b1d_Value[2];
  QRsim_B.b2d[2] = QRsim_B.b3cd[0] * QRsim_P.b1d_Value[1] - QRsim_B.b3cd[1] *
    QRsim_P.b1d_Value[0];

  /* '<S16>:1:4' */
  QRsim_B.Rdes[0] = QRsim_P.b1d_Value[0];
  QRsim_B.Rdes[1] = QRsim_P.b1d_Value[1];
  QRsim_B.Rdes[2] = QRsim_P.b1d_Value[2];
  QRsim_B.Rdes[3] = QRsim_B.b2d[0];
  QRsim_B.Rdes[4] = QRsim_B.b2d[1];
  QRsim_B.Rdes[5] = QRsim_B.b2d[2];
  QRsim_B.Rdes[6] = QRsim_B.b3cd[0];
  QRsim_B.Rdes[7] = QRsim_B.b3cd[1];
  QRsim_B.Rdes[8] = QRsim_B.b3cd[2];

  /* MATLAB Function: '<S12>/errorfunction block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010/errorfunction block': '<S20>:1' */
  /* '<S20>:1:3' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      Omegadhat[i + 3 * j] = (real_T)I[3 * j + i] - ((QRsim_B.Rdes[3 * i + 1] *
        QRsim_B.R_L[3 * j + 1] + QRsim_B.Rdes[3 * i] * QRsim_B.R_L[3 * j]) +
        QRsim_B.Rdes[3 * i + 2] * QRsim_B.R_L[3 * j + 2]);
    }
  }

  QRsim_B.error_j = ((Omegadhat[0] + Omegadhat[4]) + Omegadhat[8]) * 0.5;

  /* End of MATLAB Function: '<S12>/errorfunction block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* ToWorkspace: '<S12>/To Workspace' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace_PWORK_e.LoggedData, &locTime,
                            &QRsim_B.error_j);
    }

    /* ToWorkspace: '<S12>/To Workspace1' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace1_PWORK_p.LoggedData, &locTime,
                            &QRsim_B.Rdes[0]);
    }
  }

  /* Derivative: '<S15>/Derivative' */
  {
    real_T t = QRsim_M->Timing.t[0];
    real_T timeStampA = QRsim_DW.Derivative_RWORK_g.TimeStampA;
    real_T timeStampB = QRsim_DW.Derivative_RWORK_g.TimeStampB;
    real_T *lastU = &QRsim_DW.Derivative_RWORK_g.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      {
        int_T i1;
        real_T *y0 = &rtb_dRdesTR[0];
        for (i1=0; i1 < 9; i1++) {
          y0[i1] = 0.0;
        }
      }
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &QRsim_DW.Derivative_RWORK_g.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &QRsim_DW.Derivative_RWORK_g.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;

      {
        int_T i1;
        const real_T *u0 = &QRsim_B.Rdes[0];
        real_T *y0 = &rtb_dRdesTR[0];
        for (i1=0; i1 < 9; i1++) {
          y0[i1] = (u0[i1] - *lastU++) / deltaT;
        }
      }
    }
  }

  /* MATLAB Function: '<S15>/Omegac block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010/Mterm Omegad/Omegac block': '<S21>:1' */
  /* '<S21>:1:3' */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      Omegadhat[i + 3 * j] = 0.0;
      Omegadhat[i + 3 * j] += QRsim_B.Rdes[3 * i] * rtb_dRdesTR[3 * j];
      Omegadhat[i + 3 * j] += QRsim_B.Rdes[3 * i + 1] * rtb_dRdesTR[3 * j + 1];
      Omegadhat[i + 3 * j] += QRsim_B.Rdes[3 * i + 2] * rtb_dRdesTR[3 * j + 2];
    }
  }

  /* '<S21>:1:4' */
  QRsim_B.Omegad[0] = Omegadhat[5];
  QRsim_B.Omegad[1] = -Omegadhat[2];
  QRsim_B.Omegad[2] = Omegadhat[1];

  /* End of MATLAB Function: '<S15>/Omegac block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* ToWorkspace: '<S12>/To Workspace2' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace2_PWORK.LoggedData, &locTime,
                            &QRsim_B.Omegad[0]);
    }
  }

  /* MATLAB Function: '<S12>/eRhat block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010/eRhat block': '<S19>:1' */
  /*  Z-X-Y psi-phi-theta */
  /* '<S19>:1:4' */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += QRsim_B.Rdes[3 * i] * QRsim_B.R_L[3 * j];
      tmp[i + 3 * j] += QRsim_B.Rdes[3 * i + 1] * QRsim_B.R_L[3 * j + 1];
      tmp[i + 3 * j] += QRsim_B.Rdes[3 * i + 2] * QRsim_B.R_L[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp_0[i + 3 * j] = 0.0;
      tmp_0[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rdes[3 * j];
      tmp_0[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rdes[3 * j + 1];
      tmp_0[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rdes[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    Omegadhat[3 * i] = tmp[3 * i] - tmp_0[3 * i];
    Omegadhat[1 + 3 * i] = tmp[3 * i + 1] - tmp_0[3 * i + 1];
    Omegadhat[2 + 3 * i] = tmp[3 * i + 2] - tmp_0[3 * i + 2];
  }

  /* '<S19>:1:6' */
  QRsim_B.eR_o[0] = 0.5 * Omegadhat[5];
  QRsim_B.eR_o[1] = 0.5 * -Omegadhat[2];
  QRsim_B.eR_o[2] = 0.5 * Omegadhat[1];

  /* End of MATLAB Function: '<S12>/eRhat block' */

  /* MATLAB Function: '<S12>/eOmega block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010/eOmega block': '<S18>:1' */
  /*  Z-X-Y psi-phi-theta */
  /* '<S18>:1:4' */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rdes[3 * j];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rdes[3 * j + 1];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rdes[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    QRsim_B.eOmega_f[i] = QRsim_B.statesdot[3 + i] - ((tmp[i + 3] *
      QRsim_B.Omegad[1] + tmp[i] * QRsim_B.Omegad[0]) + tmp[i + 6] *
      QRsim_B.Omegad[2]);
  }

  /* End of MATLAB Function: '<S12>/eOmega block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* SignalConversion: '<S12>/TmpSignal ConversionAtTo Workspace3Inport1' */
    rtb_TmpSignalConversionAtToWo_e[0] = QRsim_B.eR_o[0];
    rtb_TmpSignalConversionAtToWo_e[1] = QRsim_B.eR_o[1];
    rtb_TmpSignalConversionAtToWo_e[2] = QRsim_B.eR_o[2];
    rtb_TmpSignalConversionAtToWo_e[3] = QRsim_B.eOmega_f[0];
    rtb_TmpSignalConversionAtToWo_e[4] = QRsim_B.eOmega_f[1];
    rtb_TmpSignalConversionAtToWo_e[5] = QRsim_B.eOmega_f[2];

    /* ToWorkspace: '<S12>/To Workspace3' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace3_PWORK.LoggedData, &locTime,
                            &rtb_TmpSignalConversionAtToWo_e[0]);
    }
  }

  /* Gain: '<S17>/I' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction[i] = QRsim_P.I_Gain[i + 6] * QRsim_B.statesdot[5] +
      (QRsim_P.I_Gain[i + 3] * QRsim_B.statesdot[4] + QRsim_P.I_Gain[i] *
       QRsim_B.statesdot[3]);
  }

  /* End of Gain: '<S17>/I' */

  /* Product: '<S24>/Element product' */
  rtb_Elementproduct[0] = QRsim_B.statesdot[4] * rtb_MathFunction[2];
  rtb_Elementproduct[1] = QRsim_B.statesdot[5] * rtb_MathFunction[0];
  rtb_Elementproduct[2] = QRsim_B.statesdot[3] * rtb_MathFunction[1];
  rtb_Elementproduct[3] = QRsim_B.statesdot[5] * rtb_MathFunction[1];
  rtb_Elementproduct[4] = QRsim_B.statesdot[3] * rtb_MathFunction[2];
  rtb_Elementproduct[5] = QRsim_B.statesdot[4] * rtb_MathFunction[0];

  /* Derivative: '<S22>/Derivative1' */
  {
    real_T t = QRsim_M->Timing.t[0];
    real_T timeStampA = QRsim_DW.Derivative1_RWORK_l.TimeStampA;
    real_T timeStampB = QRsim_DW.Derivative1_RWORK_l.TimeStampB;
    real_T *lastU = &QRsim_DW.Derivative1_RWORK_l.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      QRsim_B.dOmegad[0] = 0.0;
      QRsim_B.dOmegad[1] = 0.0;
      QRsim_B.dOmegad[2] = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK_l.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &QRsim_DW.Derivative1_RWORK_l.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;
      QRsim_B.dOmegad[0] = (QRsim_B.Omegad[0] - *lastU++) / deltaT;
      QRsim_B.dOmegad[1] = (QRsim_B.Omegad[1] - *lastU++) / deltaT;
      QRsim_B.dOmegad[2] = (QRsim_B.Omegad[2] - *lastU++) / deltaT;
    }
  }

  /* MATLAB Function: '<S22>/M term block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010/Mterm Omegad/Subsystem/M term block': '<S23>:1' */
  /*  Z-X-Y psi-phi-theta */
  /* '<S23>:1:4' */
  /* '<S23>:1:5' */
  /* '<S23>:1:6' */
  /* '<S23>:1:8' */
  /* '<S23>:1:12' */
  /* '<S23>:1:13' */
  /* '<S23>:1:14' */
  tmp_1[0] = 0.0;
  tmp_1[3] = -QRsim_B.statesdot[5];
  tmp_1[6] = QRsim_B.statesdot[4];
  tmp_1[1] = QRsim_B.statesdot[5];
  tmp_1[4] = 0.0;
  tmp_1[7] = -QRsim_B.statesdot[3];
  tmp_1[2] = -QRsim_B.statesdot[4];
  tmp_1[5] = QRsim_B.statesdot[3];
  tmp_1[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += tmp_1[i] * QRsim_B.R_L[j];
      tmp[i + 3 * j] += tmp_1[i + 3] * QRsim_B.R_L[j + 3];
      tmp[i + 3 * j] += tmp_1[i + 6] * QRsim_B.R_L[j + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp_0[i + 3 * j] = 0.0;
      tmp_0[i + 3 * j] += QRsim_B.Rdes[3 * j] * tmp[i];
      tmp_0[i + 3 * j] += QRsim_B.Rdes[3 * j + 1] * tmp[i + 3];
      tmp_0[i + 3 * j] += QRsim_B.Rdes[3 * j + 2] * tmp[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    QRsim_B.Out1_o[i] = 0.0;
    QRsim_B.Out1_o[i] += tmp_0[i] * QRsim_B.Omegad[0];
    QRsim_B.Out1_o[i] += tmp_0[i + 3] * QRsim_B.Omegad[1];
    QRsim_B.Out1_o[i] += tmp_0[i + 6] * QRsim_B.Omegad[2];
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rdes[3 * j];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rdes[3 * j + 1];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rdes[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    QRsim_B.Out2_m[i] = 0.0;
    QRsim_B.Out2_m[i] += tmp[i] * QRsim_B.dOmegad[0];
    QRsim_B.Out2_m[i] += tmp[i + 3] * QRsim_B.dOmegad[1];
    QRsim_B.Out2_m[i] += tmp[i + 6] * QRsim_B.dOmegad[2];
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      QRsim_B.Out3_f[i + 3 * j] = 0.0;
      QRsim_B.Out3_f[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rdes[3 * j];
      QRsim_B.Out3_f[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rdes[3 * j +
        1];
      QRsim_B.Out3_f[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rdes[3 * j +
        2];
    }
  }

  /* End of MATLAB Function: '<S22>/M term block' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S15>/Gain1'
   *  Gain: '<S15>/I'
   */
  s = QRsim_P.Gain1_Gain_l * QRsim_B.Out1_o[0] - QRsim_P.Gain_Gain_m *
    QRsim_B.Out2_m[0];
  rtb_MathFunction1 = QRsim_P.Gain1_Gain_l * QRsim_B.Out1_o[1] -
    QRsim_P.Gain_Gain_m * QRsim_B.Out2_m[1];
  scale = QRsim_P.Gain1_Gain_l * QRsim_B.Out1_o[2] - QRsim_P.Gain_Gain_m *
    QRsim_B.Out2_m[2];

  /* Gain: '<S15>/I' */
  for (i = 0; i < 3; i++) {
    QRsim_B.Mterm[i] = 0.0;
    QRsim_B.Mterm[i] += QRsim_P.I_Gain_p[i] * s;
    QRsim_B.Mterm[i] += QRsim_P.I_Gain_p[i + 3] * rtb_MathFunction1;
    QRsim_B.Mterm[i] += QRsim_P.I_Gain_p[i + 6] * scale;
  }

  /* Gain: '<S12>/kOmega' incorporates:
   *  Gain: '<S12>/Gain'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = QRsim_P.kOmega_Gain[i + 6] * QRsim_B.eOmega_f[2] +
      (QRsim_P.kOmega_Gain[i + 3] * QRsim_B.eOmega_f[1] + QRsim_P.kOmega_Gain[i]
       * QRsim_B.eOmega_f[0]);
  }

  /* End of Gain: '<S12>/kOmega' */

  /* Sum: '<S12>/Add' incorporates:
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/M term'
   *  Gain: '<S12>/kR'
   *  Sum: '<S24>/Add3'
   */
  for (i = 0; i < 3; i++) {
    QRsim_B.MNL[i] = (((rtb_Elementproduct[i] - rtb_Elementproduct[3 + i]) -
                       ((QRsim_P.kR_Gain[i + 3] * QRsim_B.eR_o[1] +
                         QRsim_P.kR_Gain[i] * QRsim_B.eR_o[0]) +
                        QRsim_P.kR_Gain[i + 6] * QRsim_B.eR_o[2])) -
                      QRsim_P.Gain_Gain * tmp_2[i]) - QRsim_P.Mterm_Gain *
      QRsim_B.Mterm[i];
  }

  /* End of Sum: '<S12>/Add' */

  /* Sum: '<S12>/Add1' */
  QRsim_B.MNLlastMterm[0] = QRsim_B.MNL[0] - QRsim_B.Mterm[0];
  QRsim_B.MNLlastMterm[1] = QRsim_B.MNL[1] - QRsim_B.Mterm[1];
  QRsim_B.MNLlastMterm[2] = QRsim_B.MNL[2] - QRsim_B.Mterm[2];
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Scope: '<S12>/scope Omega Omegad' */
    if (rtmIsMajorTimeStep(QRsim_M)) {
      StructLogVar *svar = (StructLogVar *)
        QRsim_DW.scopeOmegaOmegad_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((QRsim_M->Timing.clockTick1+
                            QRsim_M->Timing.clockTickH1* 4294967296.0)) * 0.01);
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[3];
        up0[0] = QRsim_B.statesdot[3];
        up0[1] = QRsim_B.statesdot[4];
        up0[2] = QRsim_B.statesdot[5];
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[3];
        up1[0] = QRsim_B.Omegad[0];
        up1[1] = QRsim_B.Omegad[1];
        up1[2] = QRsim_B.Omegad[2];
        rt_UpdateLogVar((LogVar *)var, up1, 0);
      }
    }

    /* Scope: '<S12>/scope errorfcn' */
    if (rtmIsMajorTimeStep(QRsim_M)) {
      StructLogVar *svar = (StructLogVar *)
        QRsim_DW.scopeerrorfcn_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((QRsim_M->Timing.clockTick1+
                            QRsim_M->Timing.clockTickH1* 4294967296.0)) * 0.01);
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = QRsim_B.error_j;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* MATLAB Function: '<S13>/Rc block' incorporates:
   *  Constant: '<Root>/b1d'
   */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010c/Rc block': '<S28>:1' */
  /*  */
  /* '<S28>:1:3' */
  scale = 2.2250738585072014E-308;
  absxk = fabs(QRsim_B.b3cd[1] * QRsim_P.b1d_Value[2] - QRsim_B.b3cd[2] *
               QRsim_P.b1d_Value[1]);
  if (absxk > 2.2250738585072014E-308) {
    s = 1.0;
    scale = absxk;
  } else {
    rtb_MathFunction1 = absxk / 2.2250738585072014E-308;
    s = rtb_MathFunction1 * rtb_MathFunction1;
  }

  absxk = fabs(QRsim_B.b3cd[2] * QRsim_P.b1d_Value[0] - QRsim_B.b3cd[0] *
               QRsim_P.b1d_Value[2]);
  if (absxk > scale) {
    rtb_MathFunction1 = scale / absxk;
    s = s * rtb_MathFunction1 * rtb_MathFunction1 + 1.0;
    scale = absxk;
  } else {
    rtb_MathFunction1 = absxk / scale;
    s += rtb_MathFunction1 * rtb_MathFunction1;
  }

  absxk = fabs(QRsim_B.b3cd[0] * QRsim_P.b1d_Value[1] - QRsim_B.b3cd[1] *
               QRsim_P.b1d_Value[0]);
  if (absxk > scale) {
    rtb_MathFunction1 = scale / absxk;
    s = s * rtb_MathFunction1 * rtb_MathFunction1 + 1.0;
    scale = absxk;
  } else {
    rtb_MathFunction1 = absxk / scale;
    s += rtb_MathFunction1 * rtb_MathFunction1;
  }

  s = scale * sqrt(s);
  rtb_MathFunction[0] = (QRsim_B.b3cd[1] * QRsim_P.b1d_Value[2] - QRsim_B.b3cd[2]
    * QRsim_P.b1d_Value[1]) / s;
  rtb_MathFunction[1] = (QRsim_B.b3cd[2] * QRsim_P.b1d_Value[0] - QRsim_B.b3cd[0]
    * QRsim_P.b1d_Value[2]) / s;
  rtb_MathFunction[2] = (QRsim_B.b3cd[0] * QRsim_P.b1d_Value[1] - QRsim_B.b3cd[1]
    * QRsim_P.b1d_Value[0]) / s;
  QRsim_B.b1c[0] = -(QRsim_B.b3cd[1] * rtb_MathFunction[2] - QRsim_B.b3cd[2] *
                     rtb_MathFunction[1]);
  QRsim_B.b1c[1] = -(QRsim_B.b3cd[2] * rtb_MathFunction[0] - QRsim_B.b3cd[0] *
                     rtb_MathFunction[2]);
  QRsim_B.b1c[2] = -(QRsim_B.b3cd[0] * rtb_MathFunction[1] - QRsim_B.b3cd[1] *
                     rtb_MathFunction[0]);

  /*  b1c = -cross(b3c,normc(cross(b3c,b1d))); */
  /* '<S28>:1:5' */
  QRsim_B.b2c[0] = QRsim_B.b3cd[1] * QRsim_B.b1c[2] - QRsim_B.b3cd[2] *
    QRsim_B.b1c[1];
  QRsim_B.b2c[1] = QRsim_B.b3cd[2] * QRsim_B.b1c[0] - QRsim_B.b3cd[0] *
    QRsim_B.b1c[2];
  QRsim_B.b2c[2] = QRsim_B.b3cd[0] * QRsim_B.b1c[1] - QRsim_B.b3cd[1] *
    QRsim_B.b1c[0];

  /* '<S28>:1:6' */
  QRsim_B.Rc[0] = QRsim_B.b1c[0];
  QRsim_B.Rc[1] = QRsim_B.b1c[1];
  QRsim_B.Rc[2] = QRsim_B.b1c[2];
  QRsim_B.Rc[3] = QRsim_B.b2c[0];
  QRsim_B.Rc[4] = QRsim_B.b2c[1];
  QRsim_B.Rc[5] = QRsim_B.b2c[2];
  QRsim_B.Rc[6] = QRsim_B.b3cd[0];
  QRsim_B.Rc[7] = QRsim_B.b3cd[1];
  QRsim_B.Rc[8] = QRsim_B.b3cd[2];

  /* End of MATLAB Function: '<S13>/Rc block' */

  /* MATLAB Function: '<S13>/errorfunction block' */
  /*  Rc = Rc.'; */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010c/errorfunction block': '<S32>:1' */
  /* '<S32>:1:3' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      Omegadhat[i + 3 * j] = (real_T)I[3 * j + i] - ((QRsim_B.Rc[3 * i + 1] *
        QRsim_B.R_L[3 * j + 1] + QRsim_B.Rc[3 * i] * QRsim_B.R_L[3 * j]) +
        QRsim_B.Rc[3 * i + 2] * QRsim_B.R_L[3 * j + 2]);
    }
  }

  QRsim_B.error = ((Omegadhat[0] + Omegadhat[4]) + Omegadhat[8]) * 0.5;

  /* End of MATLAB Function: '<S13>/errorfunction block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* ToWorkspace: '<S13>/To Workspace' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace_PWORK_ex.LoggedData, &locTime,
                            &QRsim_B.error);
    }

    /* ToWorkspace: '<S13>/To Workspace1' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace1_PWORK_l.LoggedData, &locTime,
                            &QRsim_B.Rc[0]);
    }
  }

  /* Derivative: '<S27>/Derivative' */
  {
    real_T t = QRsim_M->Timing.t[0];
    real_T timeStampA = QRsim_DW.Derivative_RWORK_m.TimeStampA;
    real_T timeStampB = QRsim_DW.Derivative_RWORK_m.TimeStampB;
    real_T *lastU = &QRsim_DW.Derivative_RWORK_m.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      {
        int_T i1;
        real_T *y0 = &rtb_dRc[0];
        for (i1=0; i1 < 9; i1++) {
          y0[i1] = 0.0;
        }
      }
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &QRsim_DW.Derivative_RWORK_m.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &QRsim_DW.Derivative_RWORK_m.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;

      {
        int_T i1;
        const real_T *u0 = &QRsim_B.Rc[0];
        real_T *y0 = &rtb_dRc[0];
        for (i1=0; i1 < 9; i1++) {
          y0[i1] = (u0[i1] - *lastU++) / deltaT;
        }
      }
    }
  }

  /* MATLAB Function: '<S27>/Omegac block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010c/Mterm Omegac/Omegac block': '<S36>:1' */
  /* '<S36>:1:3' */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      Omegadhat[i + 3 * j] = 0.0;
      Omegadhat[i + 3 * j] += QRsim_B.Rc[3 * i] * rtb_dRc[3 * j];
      Omegadhat[i + 3 * j] += QRsim_B.Rc[3 * i + 1] * rtb_dRc[3 * j + 1];
      Omegadhat[i + 3 * j] += QRsim_B.Rc[3 * i + 2] * rtb_dRc[3 * j + 2];
    }
  }

  /* '<S36>:1:4' */
  QRsim_B.Omegac[0] = Omegadhat[5];
  QRsim_B.Omegac[1] = -Omegadhat[2];
  QRsim_B.Omegac[2] = Omegadhat[1];

  /* End of MATLAB Function: '<S27>/Omegac block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* ToWorkspace: '<S13>/To Workspace2' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace2_PWORK_i.LoggedData, &locTime,
                            &QRsim_B.Omegac[0]);
    }
  }

  /* MATLAB Function: '<S13>/eRhat block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010c/eRhat block': '<S31>:1' */
  /*  Z-X-Y psi-phi-theta */
  /* '<S31>:1:4' */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += QRsim_B.Rc[3 * i] * QRsim_B.R_L[3 * j];
      tmp[i + 3 * j] += QRsim_B.Rc[3 * i + 1] * QRsim_B.R_L[3 * j + 1];
      tmp[i + 3 * j] += QRsim_B.Rc[3 * i + 2] * QRsim_B.R_L[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp_0[i + 3 * j] = 0.0;
      tmp_0[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rc[3 * j];
      tmp_0[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rc[3 * j + 1];
      tmp_0[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rc[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    Omegadhat[3 * i] = tmp[3 * i] - tmp_0[3 * i];
    Omegadhat[1 + 3 * i] = tmp[3 * i + 1] - tmp_0[3 * i + 1];
    Omegadhat[2 + 3 * i] = tmp[3 * i + 2] - tmp_0[3 * i + 2];
  }

  /* '<S31>:1:5' */
  QRsim_B.eR[0] = 0.5 * Omegadhat[5];
  QRsim_B.eR[1] = 0.5 * -Omegadhat[2];
  QRsim_B.eR[2] = 0.5 * Omegadhat[1];

  /* End of MATLAB Function: '<S13>/eRhat block' */

  /* MATLAB Function: '<S13>/eOmega block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010c/eOmega block': '<S30>:1' */
  /*  Z-X-Y psi-phi-theta */
  /* '<S30>:1:4' */
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rc[3 * j];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rc[3 * j + 1];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rc[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    QRsim_B.eOmega[i] = QRsim_B.statesdot[3 + i] - ((tmp[i + 3] *
      QRsim_B.Omegac[1] + tmp[i] * QRsim_B.Omegac[0]) + tmp[i + 6] *
      QRsim_B.Omegac[2]);
  }

  /* End of MATLAB Function: '<S13>/eOmega block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* SignalConversion: '<S13>/TmpSignal ConversionAtTo Workspace3Inport1' */
    rtb_TmpSignalConversionAtToWo_e[0] = QRsim_B.eR[0];
    rtb_TmpSignalConversionAtToWo_e[1] = QRsim_B.eR[1];
    rtb_TmpSignalConversionAtToWo_e[2] = QRsim_B.eR[2];
    rtb_TmpSignalConversionAtToWo_e[3] = QRsim_B.eOmega[0];
    rtb_TmpSignalConversionAtToWo_e[4] = QRsim_B.eOmega[1];
    rtb_TmpSignalConversionAtToWo_e[5] = QRsim_B.eOmega[2];

    /* ToWorkspace: '<S13>/To Workspace3' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace3_PWORK_b.LoggedData, &locTime,
                            &rtb_TmpSignalConversionAtToWo_e[0]);
    }
  }

  /* Gain: '<S29>/I' */
  for (i = 0; i < 3; i++) {
    rtb_Product_n[i] = QRsim_P.I_Gain_f[i + 6] * QRsim_B.statesdot[5] +
      (QRsim_P.I_Gain_f[i + 3] * QRsim_B.statesdot[4] + QRsim_P.I_Gain_f[i] *
       QRsim_B.statesdot[3]);
  }

  /* End of Gain: '<S29>/I' */

  /* Product: '<S39>/Element product' */
  rtb_Elementproduct[0] = QRsim_B.statesdot[4] * rtb_Product_n[2];
  rtb_Elementproduct[1] = QRsim_B.statesdot[5] * rtb_Product_n[0];
  rtb_Elementproduct[2] = QRsim_B.statesdot[3] * rtb_Product_n[1];
  rtb_Elementproduct[3] = QRsim_B.statesdot[5] * rtb_Product_n[1];
  rtb_Elementproduct[4] = QRsim_B.statesdot[3] * rtb_Product_n[2];
  rtb_Elementproduct[5] = QRsim_B.statesdot[4] * rtb_Product_n[0];

  /* Derivative: '<S37>/Derivative1' */
  {
    real_T t = QRsim_M->Timing.t[0];
    real_T timeStampA = QRsim_DW.Derivative1_RWORK_p.TimeStampA;
    real_T timeStampB = QRsim_DW.Derivative1_RWORK_p.TimeStampB;
    real_T *lastU = &QRsim_DW.Derivative1_RWORK_p.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      QRsim_B.dOmegac[0] = 0.0;
      QRsim_B.dOmegac[1] = 0.0;
      QRsim_B.dOmegac[2] = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK_p.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &QRsim_DW.Derivative1_RWORK_p.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;
      QRsim_B.dOmegac[0] = (QRsim_B.Omegac[0] - *lastU++) / deltaT;
      QRsim_B.dOmegac[1] = (QRsim_B.Omegac[1] - *lastU++) / deltaT;
      QRsim_B.dOmegac[2] = (QRsim_B.Omegac[2] - *lastU++) / deltaT;
    }
  }

  /* MATLAB Function: '<S37>/M term block' */
  /* MATLAB Function 'Control/Moment Controller/M NL Lee2010c/Mterm Omegac/Subsystem/M term block': '<S38>:1' */
  /*  Z-X-Y psi-phi-theta */
  /* '<S38>:1:4' */
  /* '<S38>:1:5' */
  /* '<S38>:1:6' */
  /* '<S38>:1:8' */
  /* '<S38>:1:12' */
  /* '<S38>:1:13' */
  /* '<S38>:1:14' */
  tmp_3[0] = 0.0;
  tmp_3[3] = -QRsim_B.statesdot[5];
  tmp_3[6] = QRsim_B.statesdot[4];
  tmp_3[1] = QRsim_B.statesdot[5];
  tmp_3[4] = 0.0;
  tmp_3[7] = -QRsim_B.statesdot[3];
  tmp_3[2] = -QRsim_B.statesdot[4];
  tmp_3[5] = QRsim_B.statesdot[3];
  tmp_3[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += tmp_3[i] * QRsim_B.R_L[j];
      tmp[i + 3 * j] += tmp_3[i + 3] * QRsim_B.R_L[j + 3];
      tmp[i + 3 * j] += tmp_3[i + 6] * QRsim_B.R_L[j + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp_0[i + 3 * j] = 0.0;
      tmp_0[i + 3 * j] += QRsim_B.Rc[3 * j] * tmp[i];
      tmp_0[i + 3 * j] += QRsim_B.Rc[3 * j + 1] * tmp[i + 3];
      tmp_0[i + 3 * j] += QRsim_B.Rc[3 * j + 2] * tmp[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    QRsim_B.Out1[i] = 0.0;
    QRsim_B.Out1[i] += tmp_0[i] * QRsim_B.Omegac[0];
    QRsim_B.Out1[i] += tmp_0[i + 3] * QRsim_B.Omegac[1];
    QRsim_B.Out1[i] += tmp_0[i + 6] * QRsim_B.Omegac[2];
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tmp[i + 3 * j] = 0.0;
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rc[3 * j];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rc[3 * j + 1];
      tmp[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rc[3 * j + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    QRsim_B.Out2[i] = 0.0;
    QRsim_B.Out2[i] += tmp[i] * QRsim_B.dOmegac[0];
    QRsim_B.Out2[i] += tmp[i + 3] * QRsim_B.dOmegac[1];
    QRsim_B.Out2[i] += tmp[i + 6] * QRsim_B.dOmegac[2];
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      QRsim_B.Out3[i + 3 * j] = 0.0;
      QRsim_B.Out3[i + 3 * j] += QRsim_B.R_L[3 * i] * QRsim_B.Rc[3 * j];
      QRsim_B.Out3[i + 3 * j] += QRsim_B.R_L[3 * i + 1] * QRsim_B.Rc[3 * j + 1];
      QRsim_B.Out3[i + 3 * j] += QRsim_B.R_L[3 * i + 2] * QRsim_B.Rc[3 * j + 2];
    }
  }

  /* End of MATLAB Function: '<S37>/M term block' */

  /* Sum: '<S27>/Sum' incorporates:
   *  Gain: '<S27>/Gain'
   *  Gain: '<S27>/Gain1'
   *  Gain: '<S27>/I'
   */
  s = QRsim_P.Gain1_Gain_b * QRsim_B.Out1[0] - QRsim_P.Gain_Gain_d *
    QRsim_B.Out2[0];
  rtb_MathFunction1 = QRsim_P.Gain1_Gain_b * QRsim_B.Out1[1] -
    QRsim_P.Gain_Gain_d * QRsim_B.Out2[1];
  scale = QRsim_P.Gain1_Gain_b * QRsim_B.Out1[2] - QRsim_P.Gain_Gain_d *
    QRsim_B.Out2[2];

  /* Gain: '<S27>/I' */
  for (i = 0; i < 3; i++) {
    QRsim_B.Mterm_c[i] = 0.0;
    QRsim_B.Mterm_c[i] += QRsim_P.I_Gain_i[i] * s;
    QRsim_B.Mterm_c[i] += QRsim_P.I_Gain_i[i + 3] * rtb_MathFunction1;
    QRsim_B.Mterm_c[i] += QRsim_P.I_Gain_i[i + 6] * scale;
  }

  /* Gain: '<S13>/kOmega' incorporates:
   *  Gain: '<S13>/Gain'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = QRsim_P.kOmega_Gain_e[i + 6] * QRsim_B.eOmega[2] +
      (QRsim_P.kOmega_Gain_e[i + 3] * QRsim_B.eOmega[1] +
       QRsim_P.kOmega_Gain_e[i] * QRsim_B.eOmega[0]);
  }

  /* End of Gain: '<S13>/kOmega' */

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/M term'
   *  Gain: '<S13>/kR'
   *  Sum: '<S39>/Add3'
   */
  for (i = 0; i < 3; i++) {
    QRsim_B.MNL_f[i] = (((rtb_Elementproduct[i] - rtb_Elementproduct[3 + i]) -
                         ((QRsim_P.kR_Gain_d[i + 3] * QRsim_B.eR[1] +
      QRsim_P.kR_Gain_d[i] * QRsim_B.eR[0]) + QRsim_P.kR_Gain_d[i + 6] *
                          QRsim_B.eR[2])) - QRsim_P.Gain_Gain_ma * tmp_2[i]) -
      QRsim_P.Mterm_Gain_f * QRsim_B.Mterm_c[i];
  }

  /* End of Sum: '<S13>/Add' */

  /* Sum: '<S13>/Add1' */
  QRsim_B.MNLlastMterm_f[0] = QRsim_B.MNL_f[0] - QRsim_B.Mterm_c[0];
  QRsim_B.MNLlastMterm_f[1] = QRsim_B.MNL_f[1] - QRsim_B.Mterm_c[1];
  QRsim_B.MNLlastMterm_f[2] = QRsim_B.MNL_f[2] - QRsim_B.Mterm_c[2];
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Scope: '<S13>/scope Omega Omegac' */
    if (rtmIsMajorTimeStep(QRsim_M)) {
      StructLogVar *svar = (StructLogVar *)
        QRsim_DW.scopeOmegaOmegac_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((QRsim_M->Timing.clockTick1+
                            QRsim_M->Timing.clockTickH1* 4294967296.0)) * 0.01);
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[3];
        up0[0] = QRsim_B.statesdot[3];
        up0[1] = QRsim_B.statesdot[4];
        up0[2] = QRsim_B.statesdot[5];
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[3];
        up1[0] = QRsim_B.Omegac[0];
        up1[1] = QRsim_B.Omegac[1];
        up1[2] = QRsim_B.Omegac[2];
        rt_UpdateLogVar((LogVar *)var, up1, 0);
      }
    }
  }

  /* Gain: '<S72>/I' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction[i] = QRsim_P.I_Gain_n[i + 6] * QRsim_B.statesdot[5] +
      (QRsim_P.I_Gain_n[i + 3] * QRsim_B.statesdot[4] + QRsim_P.I_Gain_n[i] *
       QRsim_B.statesdot[3]);
  }

  /* End of Gain: '<S72>/I' */

  /* Sum: '<S66>/Add' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<S66>/Gain'
   *  Product: '<S74>/Element product'
   *  Sum: '<S74>/Add3'
   */
  s = QRsim_P.Constant1_Value[0] - (QRsim_B.statesdot[4] * rtb_MathFunction[2] -
    QRsim_B.statesdot[5] * rtb_MathFunction[1]);
  rtb_MathFunction1 = QRsim_P.Constant1_Value[1] - (QRsim_B.statesdot[5] *
    rtb_MathFunction[0] - QRsim_B.statesdot[3] * rtb_MathFunction[2]);
  scale = QRsim_P.Constant1_Value[2] - (QRsim_B.statesdot[3] * rtb_MathFunction
    [1] - QRsim_B.statesdot[4] * rtb_MathFunction[0]);

  /* Gain: '<S66>/Gain' */
  for (i = 0; i < 3; i++) {
    QRsim_B.Gain[i] = 0.0;
    QRsim_B.Gain[i] += QRsim_P.Gain_Gain_f[i] * s;
    QRsim_B.Gain[i] += QRsim_P.Gain_Gain_f[i + 3] * rtb_MathFunction1;
    QRsim_B.Gain[i] += QRsim_P.Gain_Gain_f[i + 6] * scale;
  }

  if (rtmIsMajorTimeStep(QRsim_M)) {
  }

  /* Integrator: '<S70>/Velocity1' */
  QRsim_B.qvec[0] = QRsim_X.velocity_k[0];
  QRsim_B.qvec[1] = QRsim_X.velocity_k[1];
  QRsim_B.qvec[2] = QRsim_X.velocity_k[2];

  /* MATLAB Function: '<S3>/dxL block' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S64>/Cable length'
   *  Constant: '<S64>/Gravity Constant'
   *  Constant: '<S64>/Mass Load'
   *  Constant: '<S64>/Mass QR'
   *  SignalConversion: '<S67>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'QR-Load Subsystem/dxL block': '<S67>:1' */
  /* '<S67>:1:3' */
  /* '<S67>:1:4' */
  /* '<S67>:1:5' */
  /* '<S67>:1:6' */
  /* '<S67>:1:12' */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = QRsim_B.R_L[i + 6] * QRsim_P.Constant_Value + (QRsim_B.R_L[i + 3]
      * QRsim_P.Constant_Value * 0.0 + QRsim_P.Constant_Value * QRsim_B.R_L[i] *
      0.0);
  }

  rtb_MathFunction1 = -QRsim_dot(QRsim_B.qvec, tmp_2) - QRsim_P.MassQR_Value *
    QRsim_P.Cablelength_Value * QRsim_dot(QRsim_B.qvec, QRsim_B.qvec);
  s = QRsim_P.MassQR_Value + QRsim_P.MassLoad_Value;
  QRsim_B.ddxL[0] = rtb_MathFunction1 * QRsim_B.qvec[0] / s +
    QRsim_P.GravityConstant_Value * 0.0;
  QRsim_B.ddxL[1] = rtb_MathFunction1 * QRsim_B.qvec[1] / s +
    QRsim_P.GravityConstant_Value * 0.0;
  QRsim_B.ddxL[2] = rtb_MathFunction1 * QRsim_B.qvec[2] / s +
    QRsim_P.GravityConstant_Value;

  /* End of MATLAB Function: '<S3>/dxL block' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* MATLAB Function: '<S69>/fcnomega' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S65>/Arm length'
     *  Constant: '<S65>/Drag Factor'
     *  Constant: '<S65>/Thrust Factor'
     *  SignalConversion: '<S79>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'QR-Load Subsystem/omegarot block/fcnomega': '<S79>:1' */
    /* omega = [omega_1^2;omega_2^2;omega_3^2;omega_4^2] */
    /* '<S79>:1:4' */
    /* '<S79>:1:5' */
    /* '<S79>:1:6' */
    /* check if Gamma is invertible? */
    /* '<S79>:1:9' */
    /* '<S79>:1:11' */
    /* '<S79>:1:13' */
    A[0] = QRsim_P.ThrustFactor_Value;
    A[4] = QRsim_P.ThrustFactor_Value;
    A[8] = QRsim_P.ThrustFactor_Value;
    A[12] = QRsim_P.ThrustFactor_Value;
    A[1] = 0.0;
    A[5] = -QRsim_P.Armlength_Value * QRsim_P.ThrustFactor_Value;
    A[9] = 0.0;
    A[13] = QRsim_P.Armlength_Value * QRsim_P.ThrustFactor_Value;
    A[2] = QRsim_P.Armlength_Value * QRsim_P.ThrustFactor_Value;
    A[6] = 0.0;
    A[10] = -QRsim_P.Armlength_Value * QRsim_P.ThrustFactor_Value;
    A[14] = 0.0;
    A[3] = -QRsim_P.DragFactor_Value;
    A[7] = QRsim_P.DragFactor_Value;
    A[11] = -QRsim_P.DragFactor_Value;
    A[15] = QRsim_P.DragFactor_Value;
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    for (j = 0; j < 3; j++) {
      c = j * 5;
      iy = 0;
      i = c;
      rtb_MathFunction1 = fabs(A[c]);
      for (b_ix = 2; b_ix <= 4 - j; b_ix++) {
        i++;
        s = fabs(A[i]);
        if (s > rtb_MathFunction1) {
          iy = b_ix - 1;
          rtb_MathFunction1 = s;
        }
      }

      if (A[c + iy] != 0.0) {
        if (iy != 0) {
          ipiv[j] = (int8_T)((j + iy) + 1);
          iy += j;
          rtb_MathFunction1 = A[j];
          A[j] = A[iy];
          A[iy] = rtb_MathFunction1;
          b_ix = j + 4;
          iy += 4;
          rtb_MathFunction1 = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = rtb_MathFunction1;
          b_ix += 4;
          iy += 4;
          rtb_MathFunction1 = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = rtb_MathFunction1;
          b_ix += 4;
          iy += 4;
          rtb_MathFunction1 = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = rtb_MathFunction1;
        }

        idxStart = (c - j) + 4;
        for (i = c + 1; i + 1 <= idxStart; i++) {
          A[i] /= A[c];
        }
      }

      iy = c;
      idxStart = c + 4;
      for (i = 1; i <= 3 - j; i++) {
        rtb_MathFunction1 = A[idxStart];
        if (A[idxStart] != 0.0) {
          b_ix = c + 1;
          idx = (iy - j) + 8;
          for (ijA = 5 + iy; ijA + 1 <= idx; ijA++) {
            A[ijA] += A[b_ix] * -rtb_MathFunction1;
            b_ix++;
          }
        }

        idxStart += 4;
        iy += 4;
      }
    }

    rtb_Switch[0] = QRsim_P.Constant_Value;
    rtb_Switch[1] = QRsim_P.Constant1_Value[0];
    rtb_Switch[2] = QRsim_P.Constant1_Value[1];
    rtb_Switch[3] = QRsim_P.Constant1_Value[2];
    if (ipiv[0] != 1) {
      rtb_Switch[0] = rtb_Switch[ipiv[0] - 1];
      rtb_Switch[ipiv[0] - 1] = QRsim_P.Constant_Value;
    }

    if (ipiv[1] != 2) {
      rtb_MathFunction1 = rtb_Switch[1];
      rtb_Switch[1] = rtb_Switch[ipiv[1] - 1];
      rtb_Switch[ipiv[1] - 1] = rtb_MathFunction1;
    }

    if (ipiv[2] != 3) {
      rtb_MathFunction1 = rtb_Switch[2];
      rtb_Switch[2] = rtb_Switch[ipiv[2] - 1];
      rtb_Switch[ipiv[2] - 1] = rtb_MathFunction1;
    }

    if (rtb_Switch[0] != 0.0) {
      for (iy = 2; iy < 5; iy++) {
        rtb_Switch[iy - 1] -= A[iy - 1] * rtb_Switch[0];
      }
    }

    if (rtb_Switch[1] != 0.0) {
      for (iy = 3; iy < 5; iy++) {
        rtb_Switch[iy - 1] -= A[iy + 3] * rtb_Switch[1];
      }
    }

    if (rtb_Switch[2] != 0.0) {
      iy = 4;
      while (iy < 5) {
        rtb_Switch[3] -= rtb_Switch[2] * A[11];
        iy = 5;
      }
    }

    if (rtb_Switch[3] != 0.0) {
      rtb_Switch[3] /= A[15];
      for (iy = 0; iy + 1 < 4; iy++) {
        rtb_Switch[iy] -= A[iy + 12] * rtb_Switch[3];
      }
    }

    if (rtb_Switch[2] != 0.0) {
      rtb_Switch[2] /= A[10];
      for (iy = 0; iy + 1 < 3; iy++) {
        rtb_Switch[iy] -= A[iy + 8] * rtb_Switch[2];
      }
    }

    if (rtb_Switch[1] != 0.0) {
      rtb_Switch[1] /= A[5];
      for (iy = 0; iy + 1 < 2; iy++) {
        rtb_Switch[iy] -= A[iy + 4] * rtb_Switch[1];
      }
    }

    if (rtb_Switch[0] != 0.0) {
      rtb_Switch[0] /= A[0];
    }

    /* End of MATLAB Function: '<S69>/fcnomega' */

    /* MATLAB Function: '<S68>/fcnf' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S65>/Arm length'
     *  Constant: '<S65>/ctauf'
     *  SignalConversion: '<S78>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'QR-Load Subsystem/fi block/fcnf': '<S78>:1' */
    /* omega = [omega_1^2;omega_2^2;omega_3^2;omega_4^2] */
    /* '<S78>:1:4' */
    /* '<S78>:1:5' */
    /* check if Gamma is invertible? */
    /* '<S78>:1:8' */
    /* '<S78>:1:10' */
    /* '<S78>:1:12' */
    A[0] = 1.0;
    A[4] = 1.0;
    A[8] = 1.0;
    A[12] = 1.0;
    A[1] = 0.0;
    A[5] = -QRsim_P.Armlength_Value;
    A[9] = 0.0;
    A[13] = QRsim_P.Armlength_Value;
    A[2] = QRsim_P.Armlength_Value;
    A[6] = 0.0;
    A[10] = -QRsim_P.Armlength_Value;
    A[14] = 0.0;
    A[3] = -QRsim_P.ctauf_Value;
    A[7] = QRsim_P.ctauf_Value;
    A[11] = -QRsim_P.ctauf_Value;
    A[15] = QRsim_P.ctauf_Value;
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    for (j = 0; j < 3; j++) {
      c = j * 5;
      iy = 0;
      i = c;
      rtb_MathFunction1 = fabs(A[c]);
      for (b_ix = 2; b_ix <= 4 - j; b_ix++) {
        i++;
        s = fabs(A[i]);
        if (s > rtb_MathFunction1) {
          iy = b_ix - 1;
          rtb_MathFunction1 = s;
        }
      }

      if (A[c + iy] != 0.0) {
        if (iy != 0) {
          ipiv[j] = (int8_T)((j + iy) + 1);
          iy += j;
          rtb_MathFunction1 = A[j];
          A[j] = A[iy];
          A[iy] = rtb_MathFunction1;
          b_ix = j + 4;
          iy += 4;
          rtb_MathFunction1 = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = rtb_MathFunction1;
          b_ix += 4;
          iy += 4;
          rtb_MathFunction1 = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = rtb_MathFunction1;
          b_ix += 4;
          iy += 4;
          rtb_MathFunction1 = A[b_ix];
          A[b_ix] = A[iy];
          A[iy] = rtb_MathFunction1;
        }

        idxStart = (c - j) + 4;
        for (i = c + 1; i + 1 <= idxStart; i++) {
          A[i] /= A[c];
        }
      }

      iy = c;
      idxStart = c + 4;
      for (i = 1; i <= 3 - j; i++) {
        rtb_MathFunction1 = A[idxStart];
        if (A[idxStart] != 0.0) {
          b_ix = c + 1;
          idx = (iy - j) + 8;
          for (ijA = 5 + iy; ijA + 1 <= idx; ijA++) {
            A[ijA] += A[b_ix] * -rtb_MathFunction1;
            b_ix++;
          }
        }

        idxStart += 4;
        iy += 4;
      }
    }

    rtb_fi[0] = QRsim_P.Constant_Value;
    rtb_fi[1] = QRsim_P.Constant1_Value[0];
    rtb_fi[2] = QRsim_P.Constant1_Value[1];
    rtb_fi[3] = QRsim_P.Constant1_Value[2];
    if (ipiv[0] != 1) {
      rtb_fi[0] = rtb_fi[ipiv[0] - 1];
      rtb_fi[ipiv[0] - 1] = QRsim_P.Constant_Value;
    }

    if (ipiv[1] != 2) {
      rtb_MathFunction1 = rtb_fi[1];
      rtb_fi[1] = rtb_fi[ipiv[1] - 1];
      rtb_fi[ipiv[1] - 1] = rtb_MathFunction1;
    }

    if (ipiv[2] != 3) {
      rtb_MathFunction1 = rtb_fi[2];
      rtb_fi[2] = rtb_fi[ipiv[2] - 1];
      rtb_fi[ipiv[2] - 1] = rtb_MathFunction1;
    }

    if (rtb_fi[0] != 0.0) {
      for (iy = 2; iy < 5; iy++) {
        rtb_fi[iy - 1] -= A[iy - 1] * rtb_fi[0];
      }
    }

    if (rtb_fi[1] != 0.0) {
      for (iy = 3; iy < 5; iy++) {
        rtb_fi[iy - 1] -= A[iy + 3] * rtb_fi[1];
      }
    }

    if (rtb_fi[2] != 0.0) {
      iy = 4;
      while (iy < 5) {
        rtb_fi[3] -= rtb_fi[2] * A[11];
        iy = 5;
      }
    }

    if (rtb_fi[3] != 0.0) {
      rtb_fi[3] /= A[15];
      for (iy = 0; iy + 1 < 4; iy++) {
        rtb_fi[iy] -= A[iy + 12] * rtb_fi[3];
      }
    }

    if (rtb_fi[2] != 0.0) {
      rtb_fi[2] /= A[10];
      for (iy = 0; iy + 1 < 3; iy++) {
        rtb_fi[iy] -= A[iy + 8] * rtb_fi[2];
      }
    }

    if (rtb_fi[1] != 0.0) {
      rtb_fi[1] /= A[5];
      for (iy = 0; iy + 1 < 2; iy++) {
        rtb_fi[iy] -= A[iy + 4] * rtb_fi[1];
      }
    }

    if (rtb_fi[0] != 0.0) {
      rtb_fi[0] /= A[0];
    }

    /* End of MATLAB Function: '<S68>/fcnf' */

    /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     */
    rtb_simout[0] = QRsim_B.states[0];
    rtb_simout[1] = QRsim_B.states[1];
    rtb_simout[2] = QRsim_B.states[2];
    rtb_simout[3] = QRsim_B.statesdot[0];
    rtb_simout[4] = QRsim_B.statesdot[1];
    rtb_simout[5] = QRsim_B.statesdot[2];
    rtb_simout[6] = QRsim_B.ddxL[0];
    rtb_simout[7] = QRsim_B.ddxL[1];
    rtb_simout[8] = QRsim_B.ddxL[2];
    rtb_simout[9] = QRsim_B.statesdot[3];
    rtb_simout[10] = QRsim_B.statesdot[4];
    rtb_simout[11] = QRsim_B.statesdot[5];
    rtb_simout[12] = QRsim_B.Gain[0];
    rtb_simout[13] = QRsim_B.Gain[1];
    rtb_simout[14] = QRsim_B.Gain[2];
    rtb_simout[15] = QRsim_P.Constant_Value;
    rtb_simout[16] = QRsim_P.Constant1_Value[0];
    rtb_simout[17] = QRsim_P.Constant1_Value[1];
    rtb_simout[18] = QRsim_P.Constant1_Value[2];

    /* Saturate: '<S69>/Saturation' */
    if (rtb_Switch[0] >= QRsim_P.Saturation_UpperSat_o) {
      s = QRsim_P.Saturation_UpperSat_o;
    } else if (rtb_Switch[0] <= QRsim_P.Saturation_LowerSat_m) {
      s = QRsim_P.Saturation_LowerSat_m;
    } else {
      s = rtb_Switch[0];
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
     *  Saturate: '<S69>/Saturation'
     *  Sqrt: '<S69>/Sqrt'
     */
    rtb_simout[19] = sqrt(s);

    /* Saturate: '<S69>/Saturation' */
    if (rtb_Switch[1] >= QRsim_P.Saturation_UpperSat_o) {
      s = QRsim_P.Saturation_UpperSat_o;
    } else if (rtb_Switch[1] <= QRsim_P.Saturation_LowerSat_m) {
      s = QRsim_P.Saturation_LowerSat_m;
    } else {
      s = rtb_Switch[1];
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
     *  Saturate: '<S69>/Saturation'
     *  Sqrt: '<S69>/Sqrt'
     */
    rtb_simout[20] = sqrt(s);

    /* Saturate: '<S69>/Saturation' */
    if (rtb_Switch[2] >= QRsim_P.Saturation_UpperSat_o) {
      s = QRsim_P.Saturation_UpperSat_o;
    } else if (rtb_Switch[2] <= QRsim_P.Saturation_LowerSat_m) {
      s = QRsim_P.Saturation_LowerSat_m;
    } else {
      s = rtb_Switch[2];
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
     *  Saturate: '<S69>/Saturation'
     *  Sqrt: '<S69>/Sqrt'
     */
    rtb_simout[21] = sqrt(s);

    /* Saturate: '<S69>/Saturation' */
    if (rtb_Switch[3] >= QRsim_P.Saturation_UpperSat_o) {
      s = QRsim_P.Saturation_UpperSat_o;
    } else if (rtb_Switch[3] <= QRsim_P.Saturation_LowerSat_m) {
      s = QRsim_P.Saturation_LowerSat_m;
    } else {
      s = rtb_Switch[3];
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
     *  Saturate: '<S69>/Saturation'
     *  Sqrt: '<S69>/Sqrt'
     */
    rtb_simout[22] = sqrt(s);

    /* Saturate: '<S68>/Saturation' */
    if (rtb_fi[0] >= QRsim_P.Saturation_UpperSat_l) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[23] = QRsim_P.Saturation_UpperSat_l;
    } else if (rtb_fi[0] <= QRsim_P.Saturation_LowerSat_p) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[23] = QRsim_P.Saturation_LowerSat_p;
    } else {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[23] = rtb_fi[0];
    }

    if (rtb_fi[1] >= QRsim_P.Saturation_UpperSat_l) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[24] = QRsim_P.Saturation_UpperSat_l;
    } else if (rtb_fi[1] <= QRsim_P.Saturation_LowerSat_p) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[24] = QRsim_P.Saturation_LowerSat_p;
    } else {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[24] = rtb_fi[1];
    }

    if (rtb_fi[2] >= QRsim_P.Saturation_UpperSat_l) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[25] = QRsim_P.Saturation_UpperSat_l;
    } else if (rtb_fi[2] <= QRsim_P.Saturation_LowerSat_p) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[25] = QRsim_P.Saturation_LowerSat_p;
    } else {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[25] = rtb_fi[2];
    }

    if (rtb_fi[3] >= QRsim_P.Saturation_UpperSat_l) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[26] = QRsim_P.Saturation_UpperSat_l;
    } else if (rtb_fi[3] <= QRsim_P.Saturation_LowerSat_p) {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[26] = QRsim_P.Saturation_LowerSat_p;
    } else {
      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      rtb_simout[26] = rtb_fi[3];
    }

    /* End of Saturate: '<S68>/Saturation' */

    /* ToWorkspace: '<S3>/To Workspace' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace_PWORK_e5.LoggedData, &locTime,
                            &rtb_simout[0]);
    }

    /* ToWorkspace: '<S63>/To Workspace4' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace4_PWORK.LoggedData, &locTime,
                            &QRsim_B.R_L[0]);
    }
  }

  /* MATLAB Function: '<S63>/dR block' */
  /* MATLAB Function 'QR-Load Subsystem/R block/dR block': '<S71>:1' */
  /* '<S71>:1:3' */
  /* '<S71>:1:4' */
  /* '<S71>:1:5' */
  /* '<S71>:1:7' */
  /* '<S71>:1:11' */
  tmp_4[0] = 0.0;
  tmp_4[3] = -QRsim_B.statesdot[5];
  tmp_4[6] = QRsim_B.statesdot[4];
  tmp_4[1] = QRsim_B.statesdot[5];
  tmp_4[4] = 0.0;
  tmp_4[7] = -QRsim_B.statesdot[3];
  tmp_4[2] = -QRsim_B.statesdot[4];
  tmp_4[5] = QRsim_B.statesdot[3];
  tmp_4[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      QRsim_B.dR[i + 3 * j] = 0.0;
      QRsim_B.dR[i + 3 * j] += tmp_4[3 * j] * QRsim_B.R_L[i];
      QRsim_B.dR[i + 3 * j] += tmp_4[3 * j + 1] * QRsim_B.R_L[i + 3];
      QRsim_B.dR[i + 3 * j] += tmp_4[3 * j + 2] * QRsim_B.R_L[i + 6];
    }
  }

  /* End of MATLAB Function: '<S63>/dR block' */
  /*  R1 = R; */
  /* MATLAB Function 'QR-Load Subsystem/dOmega block/Subsystem2/fcnhat1': '<S76>:1' */
  /* '<S76>:1:3' */
  /* '<S76>:1:4' */
  /* '<S76>:1:5' */
  /* '<S76>:1:6' */
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* MATLAB Function 'QR-Load Subsystem/dOmega block/Subsystem2/fcnomega': '<S77>:1' */
    /* '<S77>:1:3' */

    /* ToWorkspace: '<S70>/To Workspace1' */
    {
      double locTime = (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
                          4294967296.0)) * 0.01);
      rt_UpdateStructLogVar((StructLogVar *)
                            QRsim_DW.ToWorkspace1_PWORK_c.LoggedData, &locTime,
                            &QRsim_B.qvec[0]);
    }
  }

  /* Gain: '<S70>/Gain1' */
  rtb_MathFunction[0] = QRsim_P.Gain1_Gain_m * QRsim_B.qvec[0];
  rtb_MathFunction[1] = QRsim_P.Gain1_Gain_m * QRsim_B.qvec[1];
  rtb_MathFunction[2] = QRsim_P.Gain1_Gain_m * QRsim_B.qvec[2];

  /* Gain: '<S70>/Gain' incorporates:
   *  Product: '<S70>/Product'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = QRsim_B.R_L[i + 6] * QRsim_P.Gain_Gain_mg[2] + (QRsim_B.R_L[i + 3]
      * QRsim_P.Gain_Gain_mg[1] + QRsim_B.R_L[i] * QRsim_P.Gain_Gain_mg[0]);
  }

  /* End of Gain: '<S70>/Gain' */

  /* Product: '<S70>/Product' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Product_n[0] = tmp_2[0] * QRsim_P.Constant_Value;
  rtb_Product_n[1] = tmp_2[1] * QRsim_P.Constant_Value;
  rtb_Product_n[2] = tmp_2[2] * QRsim_P.Constant_Value;

  /* Gain: '<S70>/1//(mQ*lL)' incorporates:
   *  Product: '<S81>/Element product'
   *  Sum: '<S81>/Add3'
   */
  QRsim_B.domega[0] = (rtb_MathFunction[1] * rtb_Product_n[2] -
                       rtb_MathFunction[2] * rtb_Product_n[1]) *
    QRsim_P.mQlL_Gain;
  QRsim_B.domega[1] = (rtb_MathFunction[2] * rtb_Product_n[0] -
                       rtb_MathFunction[0] * rtb_Product_n[2]) *
    QRsim_P.mQlL_Gain;
  QRsim_B.domega[2] = (rtb_MathFunction[0] * rtb_Product_n[1] -
                       rtb_MathFunction[1] * rtb_Product_n[0]) *
    QRsim_P.mQlL_Gain;

  /* Sum: '<S80>/Add3' incorporates:
   *  Integrator: '<S70>/Velocity2'
   *  Product: '<S80>/Element product'
   */
  QRsim_B.Add3[0] = QRsim_X.velocity_n[1] * QRsim_B.qvec[2] -
    QRsim_X.velocity_n[2] * QRsim_B.qvec[1];
  QRsim_B.Add3[1] = QRsim_X.velocity_n[2] * QRsim_B.qvec[0] -
    QRsim_X.velocity_n[0] * QRsim_B.qvec[2];
  QRsim_B.Add3[2] = QRsim_X.velocity_n[0] * QRsim_B.qvec[1] -
    QRsim_X.velocity_n[1] * QRsim_B.qvec[0];
  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(QRsim_M->rtwLogInfo, (QRsim_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* Update for Integrator: '<S63>/Integrator' */
    QRsim_DW.Integrator_IWORK.IcNeedsLoading = 0;

    /* Update for Derivative: '<S9>/Derivative' */
    {
      real_T timeStampA = QRsim_DW.Derivative_RWORK.TimeStampA;
      real_T timeStampB = QRsim_DW.Derivative_RWORK.TimeStampB;
      real_T* lastTime = &QRsim_DW.Derivative_RWORK.TimeStampA;
      real_T* lastU = &QRsim_DW.Derivative_RWORK.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &QRsim_DW.Derivative_RWORK.TimeStampB;
          lastU = &QRsim_DW.Derivative_RWORK.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime = &QRsim_DW.Derivative_RWORK.TimeStampB;
          lastU = &QRsim_DW.Derivative_RWORK.LastUAtTimeB[0];
        }
      }

      *lastTime = QRsim_M->Timing.t[0];
      *lastU++ = QRsim_P.xdes_Value[0];
      *lastU++ = QRsim_P.xdes_Value[1];
      *lastU++ = QRsim_P.xdes_Value[2];
    }

    /* Update for Derivative: '<S9>/Derivative1' */
    {
      real_T timeStampA = QRsim_DW.Derivative1_RWORK.TimeStampA;
      real_T timeStampB = QRsim_DW.Derivative1_RWORK.TimeStampB;
      real_T* lastTime = &QRsim_DW.Derivative1_RWORK.TimeStampA;
      real_T* lastU = &QRsim_DW.Derivative1_RWORK.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &QRsim_DW.Derivative1_RWORK.TimeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime = &QRsim_DW.Derivative1_RWORK.TimeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK.LastUAtTimeB[0];
        }
      }

      *lastTime = QRsim_M->Timing.t[0];
      *lastU++ = QRsim_B.dxd[0];
      *lastU++ = QRsim_B.dxd[1];
      *lastU++ = QRsim_B.dxd[2];
    }

    /* Update for Integrator: '<S3>/Position' */
    QRsim_DW.Position_IWORK.IcNeedsLoading = 0;

    /* Update for Integrator: '<S3>/Velocity' */
    QRsim_DW.Velocity_IWORK.IcNeedsLoading = 0;

    /* Update for Derivative: '<S15>/Derivative' */
    {
      real_T timeStampA = QRsim_DW.Derivative_RWORK_g.TimeStampA;
      real_T timeStampB = QRsim_DW.Derivative_RWORK_g.TimeStampB;
      real_T* lastTime = &QRsim_DW.Derivative_RWORK_g.TimeStampA;
      real_T* lastU = &QRsim_DW.Derivative_RWORK_g.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &QRsim_DW.Derivative_RWORK_g.TimeStampB;
          lastU = &QRsim_DW.Derivative_RWORK_g.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime = &QRsim_DW.Derivative_RWORK_g.TimeStampB;
          lastU = &QRsim_DW.Derivative_RWORK_g.LastUAtTimeB[0];
        }
      }

      *lastTime = QRsim_M->Timing.t[0];

      {
        int_T i1;
        const real_T *u0 = &QRsim_B.Rdes[0];
        for (i1=0; i1 < 9; i1++) {
          *lastU++ = u0[i1];
        }
      }
    }

    /* Update for Derivative: '<S22>/Derivative1' */
    {
      real_T timeStampA = QRsim_DW.Derivative1_RWORK_l.TimeStampA;
      real_T timeStampB = QRsim_DW.Derivative1_RWORK_l.TimeStampB;
      real_T* lastTime = &QRsim_DW.Derivative1_RWORK_l.TimeStampA;
      real_T* lastU = &QRsim_DW.Derivative1_RWORK_l.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &QRsim_DW.Derivative1_RWORK_l.TimeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK_l.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime = &QRsim_DW.Derivative1_RWORK_l.TimeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK_l.LastUAtTimeB[0];
        }
      }

      *lastTime = QRsim_M->Timing.t[0];
      *lastU++ = QRsim_B.Omegad[0];
      *lastU++ = QRsim_B.Omegad[1];
      *lastU++ = QRsim_B.Omegad[2];
    }

    /* Update for Derivative: '<S27>/Derivative' */
    {
      real_T timeStampA = QRsim_DW.Derivative_RWORK_m.TimeStampA;
      real_T timeStampB = QRsim_DW.Derivative_RWORK_m.TimeStampB;
      real_T* lastTime = &QRsim_DW.Derivative_RWORK_m.TimeStampA;
      real_T* lastU = &QRsim_DW.Derivative_RWORK_m.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &QRsim_DW.Derivative_RWORK_m.TimeStampB;
          lastU = &QRsim_DW.Derivative_RWORK_m.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime = &QRsim_DW.Derivative_RWORK_m.TimeStampB;
          lastU = &QRsim_DW.Derivative_RWORK_m.LastUAtTimeB[0];
        }
      }

      *lastTime = QRsim_M->Timing.t[0];

      {
        int_T i1;
        const real_T *u0 = &QRsim_B.Rc[0];
        for (i1=0; i1 < 9; i1++) {
          *lastU++ = u0[i1];
        }
      }
    }

    /* Update for Derivative: '<S37>/Derivative1' */
    {
      real_T timeStampA = QRsim_DW.Derivative1_RWORK_p.TimeStampA;
      real_T timeStampB = QRsim_DW.Derivative1_RWORK_p.TimeStampB;
      real_T* lastTime = &QRsim_DW.Derivative1_RWORK_p.TimeStampA;
      real_T* lastU = &QRsim_DW.Derivative1_RWORK_p.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &QRsim_DW.Derivative1_RWORK_p.TimeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK_p.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime = &QRsim_DW.Derivative1_RWORK_p.TimeStampB;
          lastU = &QRsim_DW.Derivative1_RWORK_p.LastUAtTimeB[0];
        }
      }

      *lastTime = QRsim_M->Timing.t[0];
      *lastU++ = QRsim_B.Omegac[0];
      *lastU++ = QRsim_B.Omegac[1];
      *lastU++ = QRsim_B.Omegac[2];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(QRsim_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(QRsim_M)!=-1) &&
          !((rtmGetTFinal(QRsim_M)-(((QRsim_M->Timing.clockTick1+
               QRsim_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((QRsim_M->Timing.clockTick1+QRsim_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(QRsim_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&QRsim_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++QRsim_M->Timing.clockTick0)) {
      ++QRsim_M->Timing.clockTickH0;
    }

    QRsim_M->Timing.t[0] = rtsiGetSolverStopTime(&QRsim_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      QRsim_M->Timing.clockTick1++;
      if (!QRsim_M->Timing.clockTick1) {
        QRsim_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void QRsim_derivatives(void)
{
  XDot_QRsim_T *_rtXdot;
  _rtXdot = ((XDot_QRsim_T *) QRsim_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S63>/Integrator' */
  {
    {
      int_T i1;
      const real_T *u0 = &QRsim_B.dR[0];
      real_T *xdot = &((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->R[0];
      for (i1=0; i1 < 9; i1++) {
        xdot[i1] = u0[i1];
      }
    }
  }

  /* Derivatives for Integrator: '<S3>/Position' */
  {
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->position[0] =
      QRsim_B.statesdot[0];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->position[1] =
      QRsim_B.statesdot[1];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->position[2] =
      QRsim_B.statesdot[2];
  }

  /* Derivatives for Integrator: '<S3>/Velocity' */
  {
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->velocity[0] = QRsim_B.ddxL[0];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->velocity[1] = QRsim_B.ddxL[1];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->velocity[2] = QRsim_B.ddxL[2];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->velocity[3] = QRsim_B.Gain[0];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->velocity[4] = QRsim_B.Gain[1];
    ((XDot_QRsim_T *) QRsim_M->ModelData.derivs)->velocity[5] = QRsim_B.Gain[2];
  }

  /* Derivatives for Integrator: '<S70>/Velocity1' */
  _rtXdot->velocity_k[0] = QRsim_B.Add3[0];
  _rtXdot->velocity_k[1] = QRsim_B.Add3[1];
  _rtXdot->velocity_k[2] = QRsim_B.Add3[2];

  /* Derivatives for Integrator: '<S70>/Velocity2' */
  _rtXdot->velocity_n[0] = QRsim_B.domega[0];
  _rtXdot->velocity_n[1] = QRsim_B.domega[1];
  _rtXdot->velocity_n[2] = QRsim_B.domega[2];
}

/* Model initialize function */
void QRsim_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  QRsim_P.Saturation_UpperSat_o = rtInf;
  QRsim_P.Saturation_UpperSat_l = rtInf;
  QRsim_P.Saturation_LowerSat_p = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)QRsim_M, 0,
                sizeof(RT_MODEL_QRsim_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QRsim_M->solverInfo, &QRsim_M->Timing.simTimeStep);
    rtsiSetTPtr(&QRsim_M->solverInfo, &rtmGetTPtr(QRsim_M));
    rtsiSetStepSizePtr(&QRsim_M->solverInfo, &QRsim_M->Timing.stepSize0);
    rtsiSetdXPtr(&QRsim_M->solverInfo, &QRsim_M->ModelData.derivs);
    rtsiSetContStatesPtr(&QRsim_M->solverInfo, (real_T **)
                         &QRsim_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&QRsim_M->solverInfo, &QRsim_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&QRsim_M->solverInfo, (&rtmGetErrorStatus(QRsim_M)));
    rtsiSetRTModelPtr(&QRsim_M->solverInfo, QRsim_M);
  }

  rtsiSetSimTimeStep(&QRsim_M->solverInfo, MAJOR_TIME_STEP);
  QRsim_M->ModelData.intgData.y = QRsim_M->ModelData.odeY;
  QRsim_M->ModelData.intgData.f[0] = QRsim_M->ModelData.odeF[0];
  QRsim_M->ModelData.intgData.f[1] = QRsim_M->ModelData.odeF[1];
  QRsim_M->ModelData.intgData.f[2] = QRsim_M->ModelData.odeF[2];
  QRsim_M->ModelData.contStates = ((X_QRsim_T *) &QRsim_X);
  rtsiSetSolverData(&QRsim_M->solverInfo, (void *)&QRsim_M->ModelData.intgData);
  rtsiSetSolverName(&QRsim_M->solverInfo,"ode3");
  rtmSetTPtr(QRsim_M, &QRsim_M->Timing.tArray[0]);
  rtmSetTFinal(QRsim_M, 10.0);
  QRsim_M->Timing.stepSize0 = 0.01;
  rtmSetFirstInitCond(QRsim_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    QRsim_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(QRsim_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(QRsim_M->rtwLogInfo, (NULL));
    rtliSetLogT(QRsim_M->rtwLogInfo, "tout");
    rtliSetLogX(QRsim_M->rtwLogInfo, "");
    rtliSetLogXFinal(QRsim_M->rtwLogInfo, "");
    rtliSetSigLog(QRsim_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(QRsim_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(QRsim_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(QRsim_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(QRsim_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &QRsim_Y.Out1
      };

      rtliSetLogYSignalPtrs(QRsim_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "QRsim/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(QRsim_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(QRsim_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) memset(((void *) &QRsim_B), 0,
                sizeof(B_QRsim_T));

  /* states (continuous) */
  {
    (void) memset((void *)&QRsim_X, 0,
                  sizeof(X_QRsim_T));
  }

  /* states (dwork) */
  (void) memset((void *)&QRsim_DW, 0,
                sizeof(DW_QRsim_T));

  /* external inputs */
  QRsim_U.In1 = 0.0;

  /* external outputs */
  QRsim_Y.Out1 = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(QRsim_M->rtwLogInfo, 0.0, rtmGetTFinal
    (QRsim_M), QRsim_M->Timing.stepSize0, (&rtmGetErrorStatus(QRsim_M)));

  /* Start for Constant: '<S63>/Constant1' */
  memcpy(&QRsim_B.Constant1[0], &QRsim_P.Constant1_Value_j[0], 9U * sizeof
         (real_T));

  /* Start for ToWorkspace: '<S6>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 3, 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Force Controller/To Workspace";
    QRsim_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "Re3",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Constant: '<S61>/xL0' */
  QRsim_B.xL0 = QRsim_P.xL0_Value;

  /* Start for Constant: '<S61>/yL0' */
  QRsim_B.yL0 = QRsim_P.yL0_Value;

  /* Start for Constant: '<S61>/zL0' */
  QRsim_B.zL0 = QRsim_P.zL0_Value;

  /* Start for Constant: '<S62>/dx0' */
  QRsim_B.dx0 = QRsim_P.dx0_Value;

  /* Start for Constant: '<S62>/dy0' */
  QRsim_B.dy0 = QRsim_P.dy0_Value;

  /* Start for Constant: '<S62>/dz0' */
  QRsim_B.dz0 = QRsim_P.dz0_Value;

  /* Start for Constant: '<S62>/p0' */
  QRsim_B.p0 = QRsim_P.p0_Value;

  /* Start for Constant: '<S62>/q0' */
  QRsim_B.q0 = QRsim_P.q0_Value;

  /* Start for Constant: '<S62>/r0' */
  QRsim_B.r0 = QRsim_P.r0_Value;

  /* Start for ToWorkspace: '<S9>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 9, 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Force Controller/Subsystem1/To Workspace1";
    QRsim_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simposd",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S12>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010/To Workspace";
    QRsim_DW.ToWorkspace_PWORK_e.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simouterror",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace_PWORK_e.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S12>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 3, 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "Rd" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010/To Workspace1";
    QRsim_DW.ToWorkspace1_PWORK_p.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "Rdes",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace1_PWORK_p.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S12>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "Omegad" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010/To Workspace2";
    QRsim_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simOmegad",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S12>/To Workspace3' */
  {
    static int_T rt_ToWksWidths[] = { 6 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 6 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010/To Workspace3";
    QRsim_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simrotationerror",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S12>/scope Omega Omegad' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 3, 3 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 3, 3 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "Omega",
      "Omegad" };

    static char_T rt_ScopeSignalTitles[] = "OmegaOmegad";
    static int_T rt_ScopeSignalTitleLengths[] = { 5, 6 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0, 0, 0, 0, 0 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010/scope Omega Omegad";
    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    QRsim_DW.scopeOmegaOmegad_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "scopeOmega",
      1,
      5000,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (QRsim_DW.scopeOmegaOmegad_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S12>/scope errorfcn' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0 };

    BuiltInDTypeId dTypes[1] = { SS_DOUBLE };

    static char_T rt_ScopeBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010/scope errorfcn";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    QRsim_DW.scopeerrorfcn_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "scopeerrorfnc",
      1,
      5000,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (QRsim_DW.scopeerrorfcn_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S13>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010c/To Workspace";
    QRsim_DW.ToWorkspace_PWORK_ex.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simouterrorA",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace_PWORK_ex.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S13>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 3, 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "Rc" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010c/To Workspace1";
    QRsim_DW.ToWorkspace1_PWORK_l.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "Rc",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace1_PWORK_l.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S13>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "Omegac" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010c/To Workspace2";
    QRsim_DW.ToWorkspace2_PWORK_i.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simOmegac",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace2_PWORK_i.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S13>/To Workspace3' */
  {
    static int_T rt_ToWksWidths[] = { 6 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 6 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010c/To Workspace3";
    QRsim_DW.ToWorkspace3_PWORK_b.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simrotationcerror",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace3_PWORK_b.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S13>/scope Omega Omegac' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 3, 3 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 3, 3 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "Omega",
      "Omegac" };

    static char_T rt_ScopeSignalTitles[] = "OmegaOmegac";
    static int_T rt_ScopeSignalTitleLengths[] = { 5, 6 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0, 0, 0, 0, 0 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] =
      "QRsim/Control/Moment Controller/M NL Lee2010c/scope Omega Omegac";
    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    QRsim_DW.scopeOmegaOmegac_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "scopeOmegac",
      1,
      5000,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (QRsim_DW.scopeOmegaOmegac_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 27 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 27, 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "simout" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/QR-Load Subsystem/To Workspace";
    QRsim_DW.ToWorkspace_PWORK_e5.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "simoutL",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace_PWORK_e5.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S63>/To Workspace4' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 3, 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "R_L" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/QR-Load Subsystem/R block/To Workspace4";
    QRsim_DW.ToWorkspace4_PWORK.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "R_L",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S70>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static const char_T *rt_ToWksLabels[] = { "qvec" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "QRsim/QR-Load Subsystem/qvec block/To Workspace1";
    QRsim_DW.ToWorkspace1_PWORK_c.LoggedData = rt_CreateStructLogVar(
      QRsim_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(QRsim_M),
      QRsim_M->Timing.stepSize0,
      (&rtmGetErrorStatus(QRsim_M)),
      "qvec",
      1,
      0,
      1,
      0.01,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (QRsim_DW.ToWorkspace1_PWORK_c.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S63>/Integrator' */
  if (rtmIsFirstInitCond(QRsim_M)) {
    QRsim_X.R[0] = 1.0;
    QRsim_X.R[1] = 0.0;
    QRsim_X.R[2] = 0.0;
    QRsim_X.R[3] = 0.0;
    QRsim_X.R[4] = 1.0;
    QRsim_X.R[5] = 0.0;
    QRsim_X.R[6] = 0.0;
    QRsim_X.R[7] = 0.0;
    QRsim_X.R[8] = 1.0;
  }

  QRsim_DW.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Derivative: '<S9>/Derivative' */
  QRsim_DW.Derivative_RWORK.TimeStampA = rtInf;
  QRsim_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Derivative: '<S9>/Derivative1' */
  QRsim_DW.Derivative1_RWORK.TimeStampA = rtInf;
  QRsim_DW.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S3>/Position' */
  if (rtmIsFirstInitCond(QRsim_M)) {
    QRsim_X.position[0] = 0.0;
    QRsim_X.position[1] = 0.0;
    QRsim_X.position[2] = 0.0;
  }

  QRsim_DW.Position_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S3>/Velocity' */
  if (rtmIsFirstInitCond(QRsim_M)) {
    QRsim_X.velocity[0] = 0.0;
    QRsim_X.velocity[1] = 0.0;
    QRsim_X.velocity[2] = 0.0;
    QRsim_X.velocity[3] = 0.0;
    QRsim_X.velocity[4] = 0.0;
    QRsim_X.velocity[5] = 0.0;
  }

  QRsim_DW.Velocity_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Derivative: '<S15>/Derivative' */
  QRsim_DW.Derivative_RWORK_g.TimeStampA = rtInf;
  QRsim_DW.Derivative_RWORK_g.TimeStampB = rtInf;

  /* InitializeConditions for Derivative: '<S22>/Derivative1' */
  QRsim_DW.Derivative1_RWORK_l.TimeStampA = rtInf;
  QRsim_DW.Derivative1_RWORK_l.TimeStampB = rtInf;

  /* InitializeConditions for Derivative: '<S27>/Derivative' */
  QRsim_DW.Derivative_RWORK_m.TimeStampA = rtInf;
  QRsim_DW.Derivative_RWORK_m.TimeStampB = rtInf;

  /* InitializeConditions for Derivative: '<S37>/Derivative1' */
  QRsim_DW.Derivative1_RWORK_p.TimeStampA = rtInf;
  QRsim_DW.Derivative1_RWORK_p.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S70>/Velocity1' */
  QRsim_X.velocity_k[0] = QRsim_P.Velocity1_IC[0];
  QRsim_X.velocity_k[1] = QRsim_P.Velocity1_IC[1];
  QRsim_X.velocity_k[2] = QRsim_P.Velocity1_IC[2];

  /* InitializeConditions for Integrator: '<S70>/Velocity2' */
  QRsim_X.velocity_n[0] = QRsim_P.Velocity2_IC[0];
  QRsim_X.velocity_n[1] = QRsim_P.Velocity2_IC[1];
  QRsim_X.velocity_n[2] = QRsim_P.Velocity2_IC[2];

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(QRsim_M)) {
    rtmSetFirstInitCond(QRsim_M, 0);
  }
}

/* Model terminate function */
void QRsim_terminate(void)
{
  /* (no terminate code required) */
}
