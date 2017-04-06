/*
 * QRsim_data.c
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

/* Block parameters (auto storage) */
P_QRsim_T QRsim_P = {
  47.4804,                             /* Expression: (mQ+mL)*g
                                        * Referenced by: '<Root>/Constant'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: Rinit
   * Referenced by: '<S63>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S63>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S63>/Saturation'
                                        */

  /*  Expression: e3
   * Referenced by: '<S6>/e3 '
   */
  { 0.0, 0.0, 1.0 },

  /*  Expression: xdes
   * Referenced by: '<Root>/xdes'
   */
  { 0.0, 0.0, 0.0 },
  4.34,                                /* Expression: mQ
                                        * Referenced by: '<S9>/mQ'
                                        */
  0.0,                                 /* Expression: x0
                                        * Referenced by: '<S61>/xL0'
                                        */
  0.0,                                 /* Expression: y0
                                        * Referenced by: '<S61>/yL0'
                                        */
  0.0,                                 /* Expression: z0
                                        * Referenced by: '<S61>/zL0'
                                        */
  69.44,                               /* Expression: kx
                                        * Referenced by: '<S9>/kx'
                                        */
  0.0,                                 /* Expression: dx0
                                        * Referenced by: '<S62>/dx0'
                                        */
  0.0,                                 /* Expression: dy0
                                        * Referenced by: '<S62>/dy0'
                                        */
  0.0,                                 /* Expression: dz0
                                        * Referenced by: '<S62>/dz0'
                                        */
  0.0,                                 /* Expression: p0
                                        * Referenced by: '<S62>/p0'
                                        */
  0.0,                                 /* Expression: q0
                                        * Referenced by: '<S62>/q0'
                                        */
  0.0,                                 /* Expression: r0
                                        * Referenced by: '<S62>/r0'
                                        */
  24.304,                              /* Expression: kv
                                        * Referenced by: '<S9>/kv'
                                        */

  /*  Expression: mQ*g*e3
   * Referenced by: '<S9>/constant'
   */
  { 0.0, 0.0, 42.5754 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S8>/Gain5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain5'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  1.0E-10,                             /* Expression: Bias
                                        * Referenced by: '<S10>/Normalization'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.0,                                 /* Expression: maxzero
                                        * Referenced by: '<S11>/Switch'
                                        */

  /*  Expression: b1d
   * Referenced by: '<Root>/b1d'
   */
  { 1.0, 0.0, 0.0 },

  /*  Expression: kR
   * Referenced by: '<S12>/kR'
   */
  { 8.81, 0.0, 0.0, 0.0, 8.81, 0.0, 0.0, 0.0, 8.81 },

  /*  Expression: kOmega
   * Referenced by: '<S12>/kOmega'
   */
  { 2.54, 0.0, 0.0, 0.0, 2.54, 0.0, 0.0, 0.0, 2.54 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain'
                                        */

  /*  Expression: I
   * Referenced by: '<S17>/I'
   */
  { 0.082, 0.0, 0.0, 0.0, 0.0845, 0.0, 0.0, 0.0, 0.1377 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain'
                                        */

  /*  Expression: I
   * Referenced by: '<S15>/I'
   */
  { 0.082, 0.0, 0.0, 0.0, 0.0845, 0.0, 0.0, 0.0, 0.1377 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/M term'
                                        */

  /*  Expression: kR
   * Referenced by: '<S13>/kR'
   */
  { 8.81, 0.0, 0.0, 0.0, 8.81, 0.0, 0.0, 0.0, 8.81 },

  /*  Expression: kOmega
   * Referenced by: '<S13>/kOmega'
   */
  { 2.54, 0.0, 0.0, 0.0, 2.54, 0.0, 0.0, 0.0, 2.54 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Gain'
                                        */

  /*  Expression: I
   * Referenced by: '<S29>/I'
   */
  { 0.082, 0.0, 0.0, 0.0, 0.0845, 0.0, 0.0, 0.0, 0.1377 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Gain'
                                        */

  /*  Expression: I
   * Referenced by: '<S27>/I'
   */
  { 0.082, 0.0, 0.0, 0.0, 0.0845, 0.0, 0.0, 0.0, 0.1377 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/M term'
                                        */

  /*  Expression: I
   * Referenced by: '<S72>/I'
   */
  { 0.082, 0.0, 0.0, 0.0, 0.0845, 0.0, 0.0, 0.0, 0.1377 },

  /*  Expression: inv(I)
   * Referenced by: '<S66>/Gain'
   */
  { 12.195121951219512, 0.0, 0.0, 0.0, 11.834319526627219, 0.0, 0.0, 0.0,
    7.2621641249092237 },
  4.34,                                /* Expression: mQ
                                        * Referenced by: '<S64>/Mass QR'
                                        */
  9.81,                                /* Expression: g
                                        * Referenced by: '<S64>/Gravity Constant'
                                        */
  0.5,                                 /* Expression: mL
                                        * Referenced by: '<S64>/Mass Load'
                                        */
  0.5,                                 /* Expression: lL
                                        * Referenced by: '<S64>/Cable length'
                                        */

  /*  Expression: qvec0
   * Referenced by: '<S70>/Velocity1'
   */
  { 0.0, 0.0, 1.0 },
  0.1,                                 /* Expression: b
                                        * Referenced by: '<S65>/Thrust Factor'
                                        */
  0.1,                                 /* Expression: d
                                        * Referenced by: '<S65>/Drag Factor'
                                        */
  0.315,                               /* Expression: l
                                        * Referenced by: '<S65>/Arm length'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S69>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S69>/Saturation'
                                        */
  0.008004,                            /* Expression: ctauf
                                        * Referenced by: '<S65>/ctauf'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S68>/Saturation'
                                        */
  0.0,                                 /* Expression: -inf
                                        * Referenced by: '<S68>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S70>/Gain1'
                                        */

  /*  Expression: e3
   * Referenced by: '<S70>/Gain'
   */
  { 0.0, 0.0, 1.0 },
  0.46082949308755761,                 /* Expression: 1/(mQ*lL)
                                        * Referenced by: '<S70>/1//(mQ*lL)'
                                        */

  /*  Expression: omega0
   * Referenced by: '<S70>/Velocity2'
   */
  { 0.0, 0.0, 0.0 }
};
