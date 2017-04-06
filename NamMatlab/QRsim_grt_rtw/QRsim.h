/*
 * QRsim.h
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
#ifndef RTW_HEADER_QRsim_h_
#define RTW_HEADER_QRsim_h_
#ifndef QRsim_COMMON_INCLUDES_
# define QRsim_COMMON_INCLUDES_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#endif                                 /* QRsim_COMMON_INCLUDES_ */

#include "QRsim_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Constant1[9];                 /* '<S63>/Constant1' */
  real_T R_L[9];                       /* '<S63>/Saturation' */
  real_T e3[3];                        /* '<S6>/e3 ' */
  real_T dxd[3];                       /* '<S9>/Derivative' */
  real_T ddxd[3];                      /* '<S9>/Derivative1' */
  real_T mQ[3];                        /* '<S9>/mQ' */
  real_T xL0;                          /* '<S61>/xL0' */
  real_T yL0;                          /* '<S61>/yL0' */
  real_T zL0;                          /* '<S61>/zL0' */
  real_T states[3];                    /* '<S3>/Position' */
  real_T ex[3];                        /* '<S9>/Sum' */
  real_T kx[3];                        /* '<S9>/kx' */
  real_T dx0;                          /* '<S62>/dx0' */
  real_T dy0;                          /* '<S62>/dy0' */
  real_T dz0;                          /* '<S62>/dz0' */
  real_T p0;                           /* '<S62>/p0' */
  real_T q0;                           /* '<S62>/q0' */
  real_T r0;                           /* '<S62>/r0' */
  real_T statesdot[6];                 /* '<S3>/Velocity' */
  real_T ev[3];                        /* '<S9>/Sum1' */
  real_T kv[3];                        /* '<S9>/kv' */
  real_T fatt;                         /* '<S6>/Gain5' */
  real_T trackingconstant[3];          /* '<S10>/Add' */
  real_T fpos;                         /* '<S10>/Dot Product' */
  real_T Normalization[3];             /* '<S10>/Normalization' */
  real_T b3cd[3];                      /* '<S6>/Gain1' */
  real_T Divide[3];                    /* '<S11>/Divide' */
  real_T dOmegad[3];                   /* '<S22>/Derivative1' */
  real_T Mterm[3];                     /* '<S15>/I' */
  real_T MNL[3];                       /* '<S12>/Add' */
  real_T MNLlastMterm[3];              /* '<S12>/Add1' */
  real_T dOmegac[3];                   /* '<S37>/Derivative1' */
  real_T Mterm_c[3];                   /* '<S27>/I' */
  real_T MNL_f[3];                     /* '<S13>/Add' */
  real_T MNLlastMterm_f[3];            /* '<S13>/Add1' */
  real_T Gain[3];                      /* '<S66>/Gain' */
  real_T qvec[3];                      /* '<S70>/Velocity1' */
  real_T domega[3];                    /* '<S70>/1//(mQ*lL)' */
  real_T Add3[3];                      /* '<S80>/Add3' */
  real_T ddxL[3];                      /* '<S3>/dxL block' */
  real_T dR[9];                        /* '<S63>/dR block' */
  real_T error;                        /* '<S13>/errorfunction block' */
  real_T eR[3];                        /* '<S13>/eRhat block' */
  real_T eOmega[3];                    /* '<S13>/eOmega block' */
  real_T b1c[3];                       /* '<S13>/Rc block' */
  real_T b2c[3];                       /* '<S13>/Rc block' */
  real_T Rc[9];                        /* '<S13>/Rc block' */
  real_T Out1[3];                      /* '<S37>/M term block' */
  real_T Out2[3];                      /* '<S37>/M term block' */
  real_T Out3[9];                      /* '<S37>/M term block' */
  real_T Omegac[3];                    /* '<S27>/Omegac block' */
  real_T error_j;                      /* '<S12>/errorfunction block' */
  real_T eR_o[3];                      /* '<S12>/eRhat block' */
  real_T eOmega_f[3];                  /* '<S12>/eOmega block' */
  real_T b2d[3];                       /* '<S12>/Rdes block' */
  real_T Rdes[9];                      /* '<S12>/Rdes block' */
  real_T Out1_o[3];                    /* '<S22>/M term block' */
  real_T Out2_m[3];                    /* '<S22>/M term block' */
  real_T Out3_f[9];                    /* '<S22>/M term block' */
  real_T Omegad[3];                    /* '<S15>/Omegac block' */
} B_QRsim_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative_RWORK;                  /* '<S9>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative1_RWORK;                 /* '<S9>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[9];
    real_T TimeStampB;
    real_T LastUAtTimeB[9];
  } Derivative_RWORK_g;                /* '<S15>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative1_RWORK_l;               /* '<S22>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[9];
    real_T TimeStampB;
    real_T LastUAtTimeB[9];
  } Derivative_RWORK_m;                /* '<S27>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative1_RWORK_p;               /* '<S37>/Derivative1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S6>/To Workspace' */

  struct {
    void *LoggedData;
  } scopefattfpos1_PWORK;              /* '<S6>/scope fatt fpos1' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S9>/To Workspace1' */

  struct {
    void *LoggedData;
  } scopeexev_PWORK;                   /* '<S9>/scope ex ev' */

  struct {
    void *LoggedData;
  } scopetrackingconstantterms_PWOR;   /* '<S9>/scope tracking constant terms' */

  struct {
    void *LoggedData;
  } scopeb3cnormaldiff_PWORK;          /* '<S10>/scope b3c normal diff' */

  struct {
    void *LoggedData;
  } scopetrackingconstant_PWORK;       /* '<S10>/scope tracking constant' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_e;               /* '<S12>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_p;              /* '<S12>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S12>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S12>/To Workspace3' */

  struct {
    void *LoggedData;
  } scopeMtermstest_PWORK;             /* '<S12>/scope Mterms test' */

  struct {
    void *LoggedData;
  } scopeOmegaOmegad_PWORK;            /* '<S12>/scope Omega Omegad' */

  struct {
    void *LoggedData;
  } scopeRRdes_PWORK;                  /* '<S12>/scope R Rdes' */

  struct {
    void *LoggedData;
  } scopeb1db2db3d_PWORK;              /* '<S12>/scope b1d b2d b3d' */

  struct {
    void *LoggedData;
  } scopeeReOmega_PWORK;               /* '<S12>/scope eR eOmega' */

  struct {
    void *LoggedData;
  } scopeerrorfcn_PWORK;               /* '<S12>/scope errorfcn' */

  struct {
    void *LoggedData;
  } scopeOmegaOmegad_PWORK_c;          /* '<S15>/scope Omega Omegad' */

  struct {
    void *LoggedData;
  } ScopeMterms_PWORK;                 /* '<S22>/Scope Mterms' */

  struct {
    void *LoggedData;
  } ScopeOmegaOmegad_PWORK;            /* '<S22>/Scope Omega Omegad' */

  struct {
    void *LoggedData;
  } ScopeOmegaddOmegad_PWORK;          /* '<S22>/Scope Omegad dOmegad' */

  struct {
    void *LoggedData;
  } ScopeRRd_PWORK;                    /* '<S22>/Scope R Rd' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_ex;              /* '<S13>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_l;              /* '<S13>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_i;              /* '<S13>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK_b;              /* '<S13>/To Workspace3' */

  struct {
    void *LoggedData;
  } scopeMtermstest_PWORK_i;           /* '<S13>/scope Mterms test' */

  struct {
    void *LoggedData;
  } scopeOmegaOmegac_PWORK;            /* '<S13>/scope Omega Omegac' */

  struct {
    void *LoggedData;
  } scopeRRc_PWORK;                    /* '<S13>/scope R Rc' */

  struct {
    void *LoggedData;
  } scopeb1cb2cb3c_PWORK;              /* '<S13>/scope b1c b2c b3c' */

  struct {
    void *LoggedData;
  } scopeeRceOmegac_PWORK;             /* '<S13>/scope eRc eOmegac' */

  struct {
    void *LoggedData;
  } scopeerrorfcn_PWORK_o;             /* '<S13>/scope errorfcn' */

  struct {
    void *LoggedData;
  } scopeOmegaOmegac_PWORK_g;          /* '<S27>/scope Omega Omegac' */

  struct {
    void *LoggedData;
  } ScopeMterms_PWORK_p;               /* '<S37>/Scope Mterms' */

  struct {
    void *LoggedData;
  } ScopeOmegaOmegac_PWORK;            /* '<S37>/Scope Omega Omegac' */

  struct {
    void *LoggedData;
  } ScopeOmegacdOmegac_PWORK;          /* '<S37>/Scope Omegac dOmegac' */

  struct {
    void *LoggedData;
  } ScopeRRdes_PWORK;                  /* '<S37>/Scope R Rdes' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S3>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_e5;              /* '<S3>/To Workspace' */

  struct {
    void *LoggedData;
  } scopexva_PWORK;                    /* '<S3>/scope x v a' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S63>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_c;              /* '<S70>/To Workspace1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S63>/Integrator' */

  struct {
    int_T IcNeedsLoading;
  } Position_IWORK;                    /* '<S3>/Position' */

  struct {
    int_T IcNeedsLoading;
  } Velocity_IWORK;                    /* '<S3>/Velocity' */
} DW_QRsim_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T R[9];                         /* '<S63>/Integrator' */
  real_T position[3];                  /* '<S3>/Position' */
  real_T velocity[6];                  /* '<S3>/Velocity' */
  real_T velocity_k[3];                /* '<S70>/Velocity1' */
  real_T velocity_n[3];                /* '<S70>/Velocity2' */
} X_QRsim_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T R[9];                         /* '<S63>/Integrator' */
  real_T position[3];                  /* '<S3>/Position' */
  real_T velocity[6];                  /* '<S3>/Velocity' */
  real_T velocity_k[3];                /* '<S70>/Velocity1' */
  real_T velocity_n[3];                /* '<S70>/Velocity2' */
} XDot_QRsim_T;

/* State disabled  */
typedef struct {
  boolean_T R[9];                      /* '<S63>/Integrator' */
  boolean_T position[3];               /* '<S3>/Position' */
  boolean_T velocity[6];               /* '<S3>/Velocity' */
  boolean_T velocity_k[3];             /* '<S70>/Velocity1' */
  boolean_T velocity_n[3];             /* '<S70>/Velocity2' */
} XDis_QRsim_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_QRsim_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_QRsim_T;

/* Parameters (auto storage) */
struct P_QRsim_T_ {
  real_T Constant_Value;               /* Expression: (mQ+mL)*g
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value[3];           /* Expression: [0;0;0]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant1_Value_j[9];         /* Expression: Rinit
                                        * Referenced by: '<S63>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S63>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S63>/Saturation'
                                        */
  real_T e3_Gain[3];                   /* Expression: e3
                                        * Referenced by: '<S6>/e3 '
                                        */
  real_T xdes_Value[3];                /* Expression: xdes
                                        * Referenced by: '<Root>/xdes'
                                        */
  real_T mQ_Gain;                      /* Expression: mQ
                                        * Referenced by: '<S9>/mQ'
                                        */
  real_T xL0_Value;                    /* Expression: x0
                                        * Referenced by: '<S61>/xL0'
                                        */
  real_T yL0_Value;                    /* Expression: y0
                                        * Referenced by: '<S61>/yL0'
                                        */
  real_T zL0_Value;                    /* Expression: z0
                                        * Referenced by: '<S61>/zL0'
                                        */
  real_T kx_Gain;                      /* Expression: kx
                                        * Referenced by: '<S9>/kx'
                                        */
  real_T dx0_Value;                    /* Expression: dx0
                                        * Referenced by: '<S62>/dx0'
                                        */
  real_T dy0_Value;                    /* Expression: dy0
                                        * Referenced by: '<S62>/dy0'
                                        */
  real_T dz0_Value;                    /* Expression: dz0
                                        * Referenced by: '<S62>/dz0'
                                        */
  real_T p0_Value;                     /* Expression: p0
                                        * Referenced by: '<S62>/p0'
                                        */
  real_T q0_Value;                     /* Expression: q0
                                        * Referenced by: '<S62>/q0'
                                        */
  real_T r0_Value;                     /* Expression: r0
                                        * Referenced by: '<S62>/r0'
                                        */
  real_T kv_Gain;                      /* Expression: kv
                                        * Referenced by: '<S9>/kv'
                                        */
  real_T constant_Value[3];            /* Expression: mQ*g*e3
                                        * Referenced by: '<S9>/constant'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S8>/Gain5'
                                        */
  real_T Gain5_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain5'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Normalization_BIAS;           /* Expression: Bias
                                        * Referenced by: '<S10>/Normalization'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: maxzero
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T b1d_Value[3];                 /* Expression: b1d
                                        * Referenced by: '<Root>/b1d'
                                        */
  real_T kR_Gain[9];                   /* Expression: kR
                                        * Referenced by: '<S12>/kR'
                                        */
  real_T kOmega_Gain[9];               /* Expression: kOmega
                                        * Referenced by: '<S12>/kOmega'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T I_Gain[9];                    /* Expression: I
                                        * Referenced by: '<S17>/I'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T I_Gain_p[9];                  /* Expression: I
                                        * Referenced by: '<S15>/I'
                                        */
  real_T Mterm_Gain;                   /* Expression: 1
                                        * Referenced by: '<S12>/M term'
                                        */
  real_T kR_Gain_d[9];                 /* Expression: kR
                                        * Referenced by: '<S13>/kR'
                                        */
  real_T kOmega_Gain_e[9];             /* Expression: kOmega
                                        * Referenced by: '<S13>/kOmega'
                                        */
  real_T Gain_Gain_ma;                 /* Expression: 1
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T I_Gain_f[9];                  /* Expression: I
                                        * Referenced by: '<S29>/I'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T I_Gain_i[9];                  /* Expression: I
                                        * Referenced by: '<S27>/I'
                                        */
  real_T Mterm_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S13>/M term'
                                        */
  real_T I_Gain_n[9];                  /* Expression: I
                                        * Referenced by: '<S72>/I'
                                        */
  real_T Gain_Gain_f[9];               /* Expression: inv(I)
                                        * Referenced by: '<S66>/Gain'
                                        */
  real_T MassQR_Value;                 /* Expression: mQ
                                        * Referenced by: '<S64>/Mass QR'
                                        */
  real_T GravityConstant_Value;        /* Expression: g
                                        * Referenced by: '<S64>/Gravity Constant'
                                        */
  real_T MassLoad_Value;               /* Expression: mL
                                        * Referenced by: '<S64>/Mass Load'
                                        */
  real_T Cablelength_Value;            /* Expression: lL
                                        * Referenced by: '<S64>/Cable length'
                                        */
  real_T Velocity1_IC[3];              /* Expression: qvec0
                                        * Referenced by: '<S70>/Velocity1'
                                        */
  real_T ThrustFactor_Value;           /* Expression: b
                                        * Referenced by: '<S65>/Thrust Factor'
                                        */
  real_T DragFactor_Value;             /* Expression: d
                                        * Referenced by: '<S65>/Drag Factor'
                                        */
  real_T Armlength_Value;              /* Expression: l
                                        * Referenced by: '<S65>/Arm length'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: inf
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 0
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T ctauf_Value;                  /* Expression: ctauf
                                        * Referenced by: '<S65>/ctauf'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: inf
                                        * Referenced by: '<S68>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -inf
                                        * Referenced by: '<S68>/Saturation'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S70>/Gain1'
                                        */
  real_T Gain_Gain_mg[3];              /* Expression: e3
                                        * Referenced by: '<S70>/Gain'
                                        */
  real_T mQlL_Gain;                    /* Expression: 1/(mQ*lL)
                                        * Referenced by: '<S70>/1//(mQ*lL)'
                                        */
  real_T Velocity2_IC[3];              /* Expression: omega0
                                        * Referenced by: '<S70>/Velocity2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_QRsim_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_QRsim_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[24];
    real_T odeF[3][24];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_QRsim_T QRsim_P;

/* Block signals (auto storage) */
extern B_QRsim_T QRsim_B;

/* Continuous states (auto storage) */
extern X_QRsim_T QRsim_X;

/* Block states (auto storage) */
extern DW_QRsim_T QRsim_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_QRsim_T QRsim_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_QRsim_T QRsim_Y;

/* Model entry point functions */
extern void QRsim_initialize(void);
extern void QRsim_step(void);
extern void QRsim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_QRsim_T *const QRsim_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'QRsim'
 * '<S1>'   : 'QRsim/Control'
 * '<S2>'   : 'QRsim/QR Subsystem'
 * '<S3>'   : 'QRsim/QR-Load Subsystem'
 * '<S4>'   : 'QRsim/Sensors'
 * '<S5>'   : 'QRsim/State Estimation'
 * '<S6>'   : 'QRsim/Control/Force Controller'
 * '<S7>'   : 'QRsim/Control/Moment Controller'
 * '<S8>'   : 'QRsim/Control/Force Controller/Subsystem'
 * '<S9>'   : 'QRsim/Control/Force Controller/Subsystem1'
 * '<S10>'  : 'QRsim/Control/Force Controller/Subsystem2'
 * '<S11>'  : 'QRsim/Control/Force Controller/Subsystem2/Normalize Vector'
 * '<S12>'  : 'QRsim/Control/Moment Controller/M NL Lee2010'
 * '<S13>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c'
 * '<S14>'  : 'QRsim/Control/Moment Controller/M lin'
 * '<S15>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Mterm Omegad'
 * '<S16>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Rdes block'
 * '<S17>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Subsystem1'
 * '<S18>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/eOmega block'
 * '<S19>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/eRhat block'
 * '<S20>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/errorfunction block'
 * '<S21>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Mterm Omegad/Omegac block'
 * '<S22>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Mterm Omegad/Subsystem'
 * '<S23>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Mterm Omegad/Subsystem/M term block'
 * '<S24>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Subsystem1/Cross Product'
 * '<S25>'  : 'QRsim/Control/Moment Controller/M NL Lee2010/Subsystem1/fcnhat'
 * '<S26>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Algebraic loop'
 * '<S27>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Mterm Omegac'
 * '<S28>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Rc block'
 * '<S29>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Subsystem1'
 * '<S30>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/eOmega block'
 * '<S31>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/eRhat block'
 * '<S32>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/errorfunction block'
 * '<S33>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Algebraic loop/M term block'
 * '<S34>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Algebraic loop/R block'
 * '<S35>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Algebraic loop/R block/v block'
 * '<S36>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Mterm Omegac/Omegac block'
 * '<S37>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Mterm Omegac/Subsystem'
 * '<S38>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Mterm Omegac/Subsystem/M term block'
 * '<S39>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Subsystem1/Cross Product'
 * '<S40>'  : 'QRsim/Control/Moment Controller/M NL Lee2010c/Subsystem1/fcnhat'
 * '<S41>'  : 'QRsim/Control/Moment Controller/M lin/eR lin block'
 * '<S42>'  : 'QRsim/QR Subsystem/Initial position'
 * '<S43>'  : 'QRsim/QR Subsystem/Initial velocity'
 * '<S44>'  : 'QRsim/QR Subsystem/R block'
 * '<S45>'  : 'QRsim/QR Subsystem/VarL'
 * '<S46>'  : 'QRsim/QR Subsystem/VarQ'
 * '<S47>'  : 'QRsim/QR Subsystem/dOmega block'
 * '<S48>'  : 'QRsim/QR Subsystem/ddr block'
 * '<S49>'  : 'QRsim/QR Subsystem/fi block'
 * '<S50>'  : 'QRsim/QR Subsystem/omegarot block'
 * '<S51>'  : 'QRsim/QR Subsystem/R block/MATLAB Function1'
 * '<S52>'  : 'QRsim/QR Subsystem/R block/dR block'
 * '<S53>'  : 'QRsim/QR Subsystem/dOmega block/Subsystem1'
 * '<S54>'  : 'QRsim/QR Subsystem/dOmega block/Subsystem2'
 * '<S55>'  : 'QRsim/QR Subsystem/dOmega block/Subsystem1/Cross Product'
 * '<S56>'  : 'QRsim/QR Subsystem/dOmega block/Subsystem1/fcnhat'
 * '<S57>'  : 'QRsim/QR Subsystem/dOmega block/Subsystem2/fcnhat1'
 * '<S58>'  : 'QRsim/QR Subsystem/dOmega block/Subsystem2/fcnomega'
 * '<S59>'  : 'QRsim/QR Subsystem/fi block/fcnf'
 * '<S60>'  : 'QRsim/QR Subsystem/omegarot block/fcnomega'
 * '<S61>'  : 'QRsim/QR-Load Subsystem/Initial position'
 * '<S62>'  : 'QRsim/QR-Load Subsystem/Initial velocity'
 * '<S63>'  : 'QRsim/QR-Load Subsystem/R block'
 * '<S64>'  : 'QRsim/QR-Load Subsystem/Var ddxL'
 * '<S65>'  : 'QRsim/QR-Load Subsystem/VarQ'
 * '<S66>'  : 'QRsim/QR-Load Subsystem/dOmega block'
 * '<S67>'  : 'QRsim/QR-Load Subsystem/dxL block'
 * '<S68>'  : 'QRsim/QR-Load Subsystem/fi block'
 * '<S69>'  : 'QRsim/QR-Load Subsystem/omegarot block'
 * '<S70>'  : 'QRsim/QR-Load Subsystem/qvec block'
 * '<S71>'  : 'QRsim/QR-Load Subsystem/R block/dR block'
 * '<S72>'  : 'QRsim/QR-Load Subsystem/dOmega block/Subsystem1'
 * '<S73>'  : 'QRsim/QR-Load Subsystem/dOmega block/Subsystem2'
 * '<S74>'  : 'QRsim/QR-Load Subsystem/dOmega block/Subsystem1/Cross Product'
 * '<S75>'  : 'QRsim/QR-Load Subsystem/dOmega block/Subsystem1/fcnhat'
 * '<S76>'  : 'QRsim/QR-Load Subsystem/dOmega block/Subsystem2/fcnhat1'
 * '<S77>'  : 'QRsim/QR-Load Subsystem/dOmega block/Subsystem2/fcnomega'
 * '<S78>'  : 'QRsim/QR-Load Subsystem/fi block/fcnf'
 * '<S79>'  : 'QRsim/QR-Load Subsystem/omegarot block/fcnomega'
 * '<S80>'  : 'QRsim/QR-Load Subsystem/qvec block/Cross Product'
 * '<S81>'  : 'QRsim/QR-Load Subsystem/qvec block/Cross Product1'
 */
#endif                                 /* RTW_HEADER_QRsim_h_ */
