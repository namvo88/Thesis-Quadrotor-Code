/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c46_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c46_debug_family_names[21] = { "kq", "komega", "mQ", "L",
  "qhat", "inprod", "nargin", "nargout", "varF", "A", "mode", "q", "dq", "qc",
  "dqc", "ddqc", "Fn", "Fpd", "Fff", "eq", "edq" };

/* Function Declarations */
static void initialize_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c46_QRLsim(SFc46_QRLsimInstanceStruct
  *chartInstance);
static void enable_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void disable_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void c46_update_debugger_state_c46_QRLsim(SFc46_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c46_QRLsim(SFc46_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_st);
static void finalize_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void sf_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void c46_chartstep_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c46_machineNumber, uint32_T
  c46_chartNumber);
static const mxArray *c46_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static void c46_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_edq, const char_T *c46_identifier, real_T c46_y[3]);
static void c46_b_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId, real_T c46_y[3]);
static void c46_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static const mxArray *c46_b_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static const mxArray *c46_c_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static const mxArray *c46_d_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static real_T c46_c_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static const mxArray *c46_e_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static void c46_d_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId, real_T c46_y[9]);
static void c46_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static void c46_info_helper(const mxArray **c46_info);
static const mxArray *c46_emlrt_marshallOut(char * c46_u);
static const mxArray *c46_b_emlrt_marshallOut(uint32_T c46_u);
static real_T c46_dot(SFc46_QRLsimInstanceStruct *chartInstance, real_T c46_a[3],
                      real_T c46_b[3]);
static void c46_eml_scalar_eg(SFc46_QRLsimInstanceStruct *chartInstance);
static void c46_matrix_to_integer_power(SFc46_QRLsimInstanceStruct
  *chartInstance, real_T c46_a[9], real_T c46_c[9]);
static void c46_b_eml_scalar_eg(SFc46_QRLsimInstanceStruct *chartInstance);
static void c46_c_eml_scalar_eg(SFc46_QRLsimInstanceStruct *chartInstance);
static void c46_cross(SFc46_QRLsimInstanceStruct *chartInstance, real_T c46_a[3],
                      real_T c46_b[3], real_T c46_c[3]);
static const mxArray *c46_f_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static int32_T c46_e_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static uint8_T c46_f_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_b_is_active_c46_QRLsim, const char_T *c46_identifier);
static uint8_T c46_g_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId);
static void init_dsm_address_info(SFc46_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c46_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c46_is_active_c46_QRLsim = 0U;
}

static void initialize_params_c46_QRLsim(SFc46_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c46_update_debugger_state_c46_QRLsim(SFc46_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c46_QRLsim(SFc46_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c46_st;
  const mxArray *c46_y = NULL;
  int32_T c46_i0;
  real_T c46_u[3];
  const mxArray *c46_b_y = NULL;
  int32_T c46_i1;
  real_T c46_b_u[3];
  const mxArray *c46_c_y = NULL;
  int32_T c46_i2;
  real_T c46_c_u[3];
  const mxArray *c46_d_y = NULL;
  int32_T c46_i3;
  real_T c46_d_u[3];
  const mxArray *c46_e_y = NULL;
  int32_T c46_i4;
  real_T c46_e_u[3];
  const mxArray *c46_f_y = NULL;
  uint8_T c46_hoistedGlobal;
  uint8_T c46_f_u;
  const mxArray *c46_g_y = NULL;
  real_T (*c46_eq)[3];
  real_T (*c46_edq)[3];
  real_T (*c46_Fpd)[3];
  real_T (*c46_Fn)[3];
  real_T (*c46_Fff)[3];
  c46_edq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c46_eq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c46_Fff = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c46_Fpd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c46_Fn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c46_st = NULL;
  c46_st = NULL;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_createcellarray(6), FALSE);
  for (c46_i0 = 0; c46_i0 < 3; c46_i0++) {
    c46_u[c46_i0] = (*c46_Fff)[c46_i0];
  }

  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", c46_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c46_y, 0, c46_b_y);
  for (c46_i1 = 0; c46_i1 < 3; c46_i1++) {
    c46_b_u[c46_i1] = (*c46_Fn)[c46_i1];
  }

  c46_c_y = NULL;
  sf_mex_assign(&c46_c_y, sf_mex_create("y", c46_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c46_y, 1, c46_c_y);
  for (c46_i2 = 0; c46_i2 < 3; c46_i2++) {
    c46_c_u[c46_i2] = (*c46_Fpd)[c46_i2];
  }

  c46_d_y = NULL;
  sf_mex_assign(&c46_d_y, sf_mex_create("y", c46_c_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c46_y, 2, c46_d_y);
  for (c46_i3 = 0; c46_i3 < 3; c46_i3++) {
    c46_d_u[c46_i3] = (*c46_edq)[c46_i3];
  }

  c46_e_y = NULL;
  sf_mex_assign(&c46_e_y, sf_mex_create("y", c46_d_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c46_y, 3, c46_e_y);
  for (c46_i4 = 0; c46_i4 < 3; c46_i4++) {
    c46_e_u[c46_i4] = (*c46_eq)[c46_i4];
  }

  c46_f_y = NULL;
  sf_mex_assign(&c46_f_y, sf_mex_create("y", c46_e_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c46_y, 4, c46_f_y);
  c46_hoistedGlobal = chartInstance->c46_is_active_c46_QRLsim;
  c46_f_u = c46_hoistedGlobal;
  c46_g_y = NULL;
  sf_mex_assign(&c46_g_y, sf_mex_create("y", &c46_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c46_y, 5, c46_g_y);
  sf_mex_assign(&c46_st, c46_y, FALSE);
  return c46_st;
}

static void set_sim_state_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_st)
{
  const mxArray *c46_u;
  real_T c46_dv0[3];
  int32_T c46_i5;
  real_T c46_dv1[3];
  int32_T c46_i6;
  real_T c46_dv2[3];
  int32_T c46_i7;
  real_T c46_dv3[3];
  int32_T c46_i8;
  real_T c46_dv4[3];
  int32_T c46_i9;
  real_T (*c46_Fff)[3];
  real_T (*c46_Fn)[3];
  real_T (*c46_Fpd)[3];
  real_T (*c46_edq)[3];
  real_T (*c46_eq)[3];
  c46_edq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c46_eq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c46_Fff = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c46_Fpd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c46_Fn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c46_doneDoubleBufferReInit = TRUE;
  c46_u = sf_mex_dup(c46_st);
  c46_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_u, 0)),
                       "Fff", c46_dv0);
  for (c46_i5 = 0; c46_i5 < 3; c46_i5++) {
    (*c46_Fff)[c46_i5] = c46_dv0[c46_i5];
  }

  c46_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_u, 1)), "Fn",
                       c46_dv1);
  for (c46_i6 = 0; c46_i6 < 3; c46_i6++) {
    (*c46_Fn)[c46_i6] = c46_dv1[c46_i6];
  }

  c46_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_u, 2)),
                       "Fpd", c46_dv2);
  for (c46_i7 = 0; c46_i7 < 3; c46_i7++) {
    (*c46_Fpd)[c46_i7] = c46_dv2[c46_i7];
  }

  c46_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_u, 3)),
                       "edq", c46_dv3);
  for (c46_i8 = 0; c46_i8 < 3; c46_i8++) {
    (*c46_edq)[c46_i8] = c46_dv3[c46_i8];
  }

  c46_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_u, 4)), "eq",
                       c46_dv4);
  for (c46_i9 = 0; c46_i9 < 3; c46_i9++) {
    (*c46_eq)[c46_i9] = c46_dv4[c46_i9];
  }

  chartInstance->c46_is_active_c46_QRLsim = c46_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c46_u, 5)), "is_active_c46_QRLsim");
  sf_mex_destroy(&c46_u);
  c46_update_debugger_state_c46_QRLsim(chartInstance);
  sf_mex_destroy(&c46_st);
}

static void finalize_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
  int32_T c46_i10;
  int32_T c46_i11;
  int32_T c46_i12;
  int32_T c46_i13;
  int32_T c46_i14;
  int32_T c46_i15;
  int32_T c46_i16;
  int32_T c46_i17;
  int32_T c46_i18;
  int32_T c46_i19;
  int32_T c46_i20;
  int32_T c46_i21;
  real_T *c46_mode;
  real_T (*c46_edq)[3];
  real_T (*c46_eq)[3];
  real_T (*c46_Fff)[3];
  real_T (*c46_Fpd)[3];
  real_T (*c46_ddqc)[3];
  real_T (*c46_dqc)[3];
  real_T (*c46_qc)[3];
  real_T (*c46_dq)[3];
  real_T (*c46_Fn)[3];
  real_T (*c46_q)[3];
  real_T (*c46_A)[3];
  real_T (*c46_varF)[4];
  c46_edq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c46_eq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c46_Fff = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c46_Fpd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c46_ddqc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
  c46_dqc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c46_qc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c46_dq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c46_Fn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c46_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c46_mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c46_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c46_varF = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c46_sfEvent);
  for (c46_i10 = 0; c46_i10 < 4; c46_i10++) {
    _SFD_DATA_RANGE_CHECK((*c46_varF)[c46_i10], 0U);
  }

  for (c46_i11 = 0; c46_i11 < 3; c46_i11++) {
    _SFD_DATA_RANGE_CHECK((*c46_A)[c46_i11], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c46_mode, 2U);
  for (c46_i12 = 0; c46_i12 < 3; c46_i12++) {
    _SFD_DATA_RANGE_CHECK((*c46_q)[c46_i12], 3U);
  }

  for (c46_i13 = 0; c46_i13 < 3; c46_i13++) {
    _SFD_DATA_RANGE_CHECK((*c46_Fn)[c46_i13], 4U);
  }

  for (c46_i14 = 0; c46_i14 < 3; c46_i14++) {
    _SFD_DATA_RANGE_CHECK((*c46_dq)[c46_i14], 5U);
  }

  for (c46_i15 = 0; c46_i15 < 3; c46_i15++) {
    _SFD_DATA_RANGE_CHECK((*c46_qc)[c46_i15], 6U);
  }

  for (c46_i16 = 0; c46_i16 < 3; c46_i16++) {
    _SFD_DATA_RANGE_CHECK((*c46_dqc)[c46_i16], 7U);
  }

  for (c46_i17 = 0; c46_i17 < 3; c46_i17++) {
    _SFD_DATA_RANGE_CHECK((*c46_ddqc)[c46_i17], 8U);
  }

  for (c46_i18 = 0; c46_i18 < 3; c46_i18++) {
    _SFD_DATA_RANGE_CHECK((*c46_Fpd)[c46_i18], 9U);
  }

  for (c46_i19 = 0; c46_i19 < 3; c46_i19++) {
    _SFD_DATA_RANGE_CHECK((*c46_Fff)[c46_i19], 10U);
  }

  for (c46_i20 = 0; c46_i20 < 3; c46_i20++) {
    _SFD_DATA_RANGE_CHECK((*c46_eq)[c46_i20], 11U);
  }

  for (c46_i21 = 0; c46_i21 < 3; c46_i21++) {
    _SFD_DATA_RANGE_CHECK((*c46_edq)[c46_i21], 12U);
  }

  chartInstance->c46_sfEvent = CALL_EVENT;
  c46_chartstep_c46_QRLsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c46_chartstep_c46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
  real_T c46_hoistedGlobal;
  int32_T c46_i22;
  real_T c46_varF[4];
  int32_T c46_i23;
  real_T c46_A[3];
  real_T c46_mode;
  int32_T c46_i24;
  real_T c46_q[3];
  int32_T c46_i25;
  real_T c46_dq[3];
  int32_T c46_i26;
  real_T c46_qc[3];
  int32_T c46_i27;
  real_T c46_dqc[3];
  int32_T c46_i28;
  real_T c46_ddqc[3];
  uint32_T c46_debug_family_var_map[21];
  real_T c46_kq;
  real_T c46_komega;
  real_T c46_mQ;
  real_T c46_L;
  real_T c46_qhat[9];
  real_T c46_inprod;
  real_T c46_nargin = 8.0;
  real_T c46_nargout = 5.0;
  real_T c46_Fn[3];
  real_T c46_Fpd[3];
  real_T c46_Fff[3];
  real_T c46_eq[3];
  real_T c46_edq[3];
  int32_T c46_i29;
  real_T c46_b_A[3];
  int32_T c46_i30;
  real_T c46_b_q[3];
  real_T c46_a;
  int32_T c46_i31;
  real_T c46_b[3];
  int32_T c46_i32;
  int32_T c46_i33;
  real_T c46_b_a[9];
  int32_T c46_i34;
  real_T c46_c_a[9];
  int32_T c46_i35;
  int32_T c46_i36;
  int32_T c46_i37;
  int32_T c46_i38;
  real_T c46_C[3];
  int32_T c46_i39;
  int32_T c46_i40;
  int32_T c46_i41;
  int32_T c46_i42;
  int32_T c46_i43;
  int32_T c46_i44;
  int32_T c46_i45;
  real_T c46_b_qc[3];
  int32_T c46_i46;
  real_T c46_b_dqc[3];
  int32_T c46_i47;
  real_T c46_b_C[3];
  int32_T c46_i48;
  real_T c46_c_q[3];
  int32_T c46_i49;
  real_T c46_d_a;
  int32_T c46_i50;
  int32_T c46_i51;
  real_T c46_e_a;
  int32_T c46_i52;
  int32_T c46_i53;
  int32_T c46_i54;
  int32_T c46_i55;
  real_T c46_c_qc[3];
  int32_T c46_i56;
  real_T c46_c_dqc[3];
  int32_T c46_i57;
  real_T c46_d_q[3];
  int32_T c46_i58;
  real_T c46_c_C[3];
  real_T c46_f_a;
  real_T c46_b_b;
  real_T c46_y;
  real_T c46_g_a;
  real_T c46_c_b;
  real_T c46_b_y;
  real_T c46_h_a;
  int32_T c46_i59;
  real_T c46_e_q[3];
  int32_T c46_i60;
  real_T c46_b_dq[3];
  int32_T c46_i61;
  real_T c46_i_a;
  real_T c46_d_b;
  real_T c46_c_y;
  real_T c46_j_a;
  int32_T c46_i62;
  real_T c46_d_qc[3];
  int32_T c46_i63;
  real_T c46_b_ddqc[3];
  int32_T c46_i64;
  real_T c46_d_C[3];
  int32_T c46_i65;
  real_T c46_f_q[3];
  int32_T c46_i66;
  int32_T c46_i67;
  int32_T c46_i68;
  int32_T c46_i69;
  int32_T c46_i70;
  int32_T c46_i71;
  int32_T c46_i72;
  real_T c46_k_a;
  real_T c46_e_qc[3];
  real_T c46_g_q[3];
  int32_T c46_i73;
  int32_T c46_i74;
  int32_T c46_i75;
  int32_T c46_i76;
  real_T *c46_b_mode;
  real_T (*c46_b_Fn)[3];
  real_T (*c46_b_Fpd)[3];
  real_T (*c46_b_Fff)[3];
  real_T (*c46_b_eq)[3];
  real_T (*c46_b_edq)[3];
  real_T (*c46_c_ddqc)[3];
  real_T (*c46_d_dqc)[3];
  real_T (*c46_f_qc)[3];
  real_T (*c46_c_dq)[3];
  real_T (*c46_h_q)[3];
  real_T (*c46_c_A)[3];
  real_T (*c46_b_varF)[4];
  c46_b_edq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c46_b_eq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c46_b_Fff = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c46_b_Fpd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c46_c_ddqc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
  c46_d_dqc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c46_f_qc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c46_c_dq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c46_b_Fn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c46_h_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c46_b_mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c46_c_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c46_b_varF = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c46_sfEvent);
  c46_hoistedGlobal = *c46_b_mode;
  for (c46_i22 = 0; c46_i22 < 4; c46_i22++) {
    c46_varF[c46_i22] = (*c46_b_varF)[c46_i22];
  }

  for (c46_i23 = 0; c46_i23 < 3; c46_i23++) {
    c46_A[c46_i23] = (*c46_c_A)[c46_i23];
  }

  c46_mode = c46_hoistedGlobal;
  for (c46_i24 = 0; c46_i24 < 3; c46_i24++) {
    c46_q[c46_i24] = (*c46_h_q)[c46_i24];
  }

  for (c46_i25 = 0; c46_i25 < 3; c46_i25++) {
    c46_dq[c46_i25] = (*c46_c_dq)[c46_i25];
  }

  for (c46_i26 = 0; c46_i26 < 3; c46_i26++) {
    c46_qc[c46_i26] = (*c46_f_qc)[c46_i26];
  }

  for (c46_i27 = 0; c46_i27 < 3; c46_i27++) {
    c46_dqc[c46_i27] = (*c46_d_dqc)[c46_i27];
  }

  for (c46_i28 = 0; c46_i28 < 3; c46_i28++) {
    c46_ddqc[c46_i28] = (*c46_c_ddqc)[c46_i28];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c46_debug_family_names,
    c46_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_kq, 0U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_komega, 1U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_mQ, 2U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_L, 3U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_qhat, 4U, c46_e_sf_marshallOut,
    c46_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_inprod, 5U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargin, 6U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargout, 7U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_varF, 8U, c46_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_A, 9U, c46_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c46_mode, 10U, c46_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_q, 11U, c46_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_dq, 12U, c46_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_qc, 13U, c46_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_dqc, 14U, c46_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c46_ddqc, 15U, c46_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_Fn, 16U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_Fpd, 17U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_Fff, 18U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_eq, 19U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_edq, 20U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 2);
  c46_kq = c46_varF[0];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 3);
  c46_komega = c46_varF[1];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 4);
  c46_mQ = c46_varF[2];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 5);
  c46_L = c46_varF[3];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 7);
  switch ((int32_T)_SFD_INTEGER_CHECK("mode", c46_mode)) {
   case 4:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 9);
    for (c46_i29 = 0; c46_i29 < 3; c46_i29++) {
      c46_b_A[c46_i29] = c46_A[c46_i29];
    }

    for (c46_i30 = 0; c46_i30 < 3; c46_i30++) {
      c46_b_q[c46_i30] = c46_q[c46_i30];
    }

    c46_a = c46_dot(chartInstance, c46_b_A, c46_b_q);
    for (c46_i31 = 0; c46_i31 < 3; c46_i31++) {
      c46_b[c46_i31] = c46_q[c46_i31];
    }

    for (c46_i32 = 0; c46_i32 < 3; c46_i32++) {
      c46_Fn[c46_i32] = c46_a * c46_b[c46_i32];
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 11);
    for (c46_i73 = 0; c46_i73 < 3; c46_i73++) {
      c46_e_qc[c46_i73] = c46_qc[c46_i73];
    }

    for (c46_i74 = 0; c46_i74 < 3; c46_i74++) {
      c46_g_q[c46_i74] = c46_q[c46_i74];
    }

    c46_k_a = -c46_dot(chartInstance, c46_e_qc, c46_g_q);
    for (c46_i75 = 0; c46_i75 < 3; c46_i75++) {
      c46_b[c46_i75] = c46_q[c46_i75];
    }

    for (c46_i76 = 0; c46_i76 < 3; c46_i76++) {
      c46_Fn[c46_i76] = c46_k_a * c46_b[c46_i76];
    }
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 14);
  c46_qhat[0] = 0.0;
  c46_qhat[3] = -c46_q[2];
  c46_qhat[6] = c46_q[1];
  c46_qhat[1] = c46_q[2];
  c46_qhat[4] = 0.0;
  c46_qhat[7] = -c46_q[0];
  c46_qhat[2] = -c46_q[1];
  c46_qhat[5] = c46_q[0];
  c46_qhat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 18);
  for (c46_i33 = 0; c46_i33 < 9; c46_i33++) {
    c46_b_a[c46_i33] = c46_qhat[c46_i33];
  }

  for (c46_i34 = 0; c46_i34 < 9; c46_i34++) {
    c46_c_a[c46_i34] = c46_b_a[c46_i34];
  }

  c46_matrix_to_integer_power(chartInstance, c46_c_a, c46_b_a);
  for (c46_i35 = 0; c46_i35 < 3; c46_i35++) {
    c46_b[c46_i35] = c46_qc[c46_i35];
  }

  c46_c_eml_scalar_eg(chartInstance);
  c46_c_eml_scalar_eg(chartInstance);
  for (c46_i36 = 0; c46_i36 < 3; c46_i36++) {
    c46_eq[c46_i36] = 0.0;
  }

  for (c46_i37 = 0; c46_i37 < 3; c46_i37++) {
    c46_eq[c46_i37] = 0.0;
  }

  for (c46_i38 = 0; c46_i38 < 3; c46_i38++) {
    c46_C[c46_i38] = c46_eq[c46_i38];
  }

  for (c46_i39 = 0; c46_i39 < 3; c46_i39++) {
    c46_eq[c46_i39] = c46_C[c46_i39];
  }

  for (c46_i40 = 0; c46_i40 < 3; c46_i40++) {
    c46_C[c46_i40] = c46_eq[c46_i40];
  }

  for (c46_i41 = 0; c46_i41 < 3; c46_i41++) {
    c46_eq[c46_i41] = c46_C[c46_i41];
  }

  for (c46_i42 = 0; c46_i42 < 3; c46_i42++) {
    c46_eq[c46_i42] = 0.0;
    c46_i43 = 0;
    for (c46_i44 = 0; c46_i44 < 3; c46_i44++) {
      c46_eq[c46_i42] += c46_b_a[c46_i43 + c46_i42] * c46_b[c46_i44];
      c46_i43 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 19);
  for (c46_i45 = 0; c46_i45 < 3; c46_i45++) {
    c46_b_qc[c46_i45] = c46_qc[c46_i45];
  }

  for (c46_i46 = 0; c46_i46 < 3; c46_i46++) {
    c46_b_dqc[c46_i46] = c46_dqc[c46_i46];
  }

  c46_cross(chartInstance, c46_b_qc, c46_b_dqc, c46_C);
  for (c46_i47 = 0; c46_i47 < 3; c46_i47++) {
    c46_b_C[c46_i47] = c46_C[c46_i47];
  }

  for (c46_i48 = 0; c46_i48 < 3; c46_i48++) {
    c46_c_q[c46_i48] = c46_q[c46_i48];
  }

  c46_cross(chartInstance, c46_b_C, c46_c_q, c46_C);
  for (c46_i49 = 0; c46_i49 < 3; c46_i49++) {
    c46_edq[c46_i49] = c46_dq[c46_i49] - c46_C[c46_i49];
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 21);
  c46_d_a = -c46_kq;
  for (c46_i50 = 0; c46_i50 < 3; c46_i50++) {
    c46_b[c46_i50] = c46_eq[c46_i50];
  }

  for (c46_i51 = 0; c46_i51 < 3; c46_i51++) {
    c46_b[c46_i51] *= c46_d_a;
  }

  c46_e_a = c46_komega;
  for (c46_i52 = 0; c46_i52 < 3; c46_i52++) {
    c46_C[c46_i52] = c46_edq[c46_i52];
  }

  for (c46_i53 = 0; c46_i53 < 3; c46_i53++) {
    c46_C[c46_i53] *= c46_e_a;
  }

  for (c46_i54 = 0; c46_i54 < 3; c46_i54++) {
    c46_Fpd[c46_i54] = c46_b[c46_i54] - c46_C[c46_i54];
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 24);
  for (c46_i55 = 0; c46_i55 < 3; c46_i55++) {
    c46_c_qc[c46_i55] = c46_qc[c46_i55];
  }

  for (c46_i56 = 0; c46_i56 < 3; c46_i56++) {
    c46_c_dqc[c46_i56] = c46_dqc[c46_i56];
  }

  c46_cross(chartInstance, c46_c_qc, c46_c_dqc, c46_C);
  for (c46_i57 = 0; c46_i57 < 3; c46_i57++) {
    c46_d_q[c46_i57] = c46_q[c46_i57];
  }

  for (c46_i58 = 0; c46_i58 < 3; c46_i58++) {
    c46_c_C[c46_i58] = c46_C[c46_i58];
  }

  c46_inprod = c46_dot(chartInstance, c46_d_q, c46_c_C);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 26);
  c46_f_a = c46_mQ;
  c46_b_b = c46_L;
  c46_y = c46_f_a * c46_b_b;
  c46_g_a = c46_y;
  c46_c_b = c46_inprod;
  c46_b_y = c46_g_a * c46_c_b;
  c46_h_a = c46_b_y;
  for (c46_i59 = 0; c46_i59 < 3; c46_i59++) {
    c46_e_q[c46_i59] = c46_q[c46_i59];
  }

  for (c46_i60 = 0; c46_i60 < 3; c46_i60++) {
    c46_b_dq[c46_i60] = c46_dq[c46_i60];
  }

  c46_cross(chartInstance, c46_e_q, c46_b_dq, c46_b);
  for (c46_i61 = 0; c46_i61 < 3; c46_i61++) {
    c46_b[c46_i61] *= c46_h_a;
  }

  c46_i_a = c46_mQ;
  c46_d_b = c46_L;
  c46_c_y = c46_i_a * c46_d_b;
  c46_j_a = c46_c_y;
  for (c46_i62 = 0; c46_i62 < 3; c46_i62++) {
    c46_d_qc[c46_i62] = c46_qc[c46_i62];
  }

  for (c46_i63 = 0; c46_i63 < 3; c46_i63++) {
    c46_b_ddqc[c46_i63] = c46_ddqc[c46_i63];
  }

  c46_cross(chartInstance, c46_d_qc, c46_b_ddqc, c46_C);
  for (c46_i64 = 0; c46_i64 < 3; c46_i64++) {
    c46_d_C[c46_i64] = c46_C[c46_i64];
  }

  for (c46_i65 = 0; c46_i65 < 3; c46_i65++) {
    c46_f_q[c46_i65] = c46_q[c46_i65];
  }

  c46_cross(chartInstance, c46_d_C, c46_f_q, c46_C);
  for (c46_i66 = 0; c46_i66 < 3; c46_i66++) {
    c46_C[c46_i66] *= c46_j_a;
  }

  for (c46_i67 = 0; c46_i67 < 3; c46_i67++) {
    c46_Fff[c46_i67] = c46_b[c46_i67] + c46_C[c46_i67];
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  for (c46_i68 = 0; c46_i68 < 3; c46_i68++) {
    (*c46_b_Fn)[c46_i68] = c46_Fn[c46_i68];
  }

  for (c46_i69 = 0; c46_i69 < 3; c46_i69++) {
    (*c46_b_Fpd)[c46_i69] = c46_Fpd[c46_i69];
  }

  for (c46_i70 = 0; c46_i70 < 3; c46_i70++) {
    (*c46_b_Fff)[c46_i70] = c46_Fff[c46_i70];
  }

  for (c46_i71 = 0; c46_i71 < 3; c46_i71++) {
    (*c46_b_eq)[c46_i71] = c46_eq[c46_i71];
  }

  for (c46_i72 = 0; c46_i72 < 3; c46_i72++) {
    (*c46_b_edq)[c46_i72] = c46_edq[c46_i72];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c46_sfEvent);
}

static void initSimStructsc46_QRLsim(SFc46_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c46_machineNumber, uint32_T
  c46_chartNumber)
{
}

static const mxArray *c46_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i77;
  real_T c46_b_inData[3];
  int32_T c46_i78;
  real_T c46_u[3];
  const mxArray *c46_y = NULL;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  for (c46_i77 = 0; c46_i77 < 3; c46_i77++) {
    c46_b_inData[c46_i77] = (*(real_T (*)[3])c46_inData)[c46_i77];
  }

  for (c46_i78 = 0; c46_i78 < 3; c46_i78++) {
    c46_u[c46_i78] = c46_b_inData[c46_i78];
  }

  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", c46_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, FALSE);
  return c46_mxArrayOutData;
}

static void c46_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_edq, const char_T *c46_identifier, real_T c46_y[3])
{
  emlrtMsgIdentifier c46_thisId;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_edq), &c46_thisId, c46_y);
  sf_mex_destroy(&c46_edq);
}

static void c46_b_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId, real_T c46_y[3])
{
  real_T c46_dv5[3];
  int32_T c46_i79;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), c46_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c46_i79 = 0; c46_i79 < 3; c46_i79++) {
    c46_y[c46_i79] = c46_dv5[c46_i79];
  }

  sf_mex_destroy(&c46_u);
}

static void c46_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_edq;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  real_T c46_y[3];
  int32_T c46_i80;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_edq = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_edq), &c46_thisId, c46_y);
  sf_mex_destroy(&c46_edq);
  for (c46_i80 = 0; c46_i80 < 3; c46_i80++) {
    (*(real_T (*)[3])c46_outData)[c46_i80] = c46_y[c46_i80];
  }

  sf_mex_destroy(&c46_mxArrayInData);
}

static const mxArray *c46_b_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i81;
  real_T c46_b_inData[3];
  int32_T c46_i82;
  real_T c46_u[3];
  const mxArray *c46_y = NULL;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  for (c46_i81 = 0; c46_i81 < 3; c46_i81++) {
    c46_b_inData[c46_i81] = (*(real_T (*)[3])c46_inData)[c46_i81];
  }

  for (c46_i82 = 0; c46_i82 < 3; c46_i82++) {
    c46_u[c46_i82] = c46_b_inData[c46_i82];
  }

  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", c46_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, FALSE);
  return c46_mxArrayOutData;
}

static const mxArray *c46_c_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  real_T c46_u;
  const mxArray *c46_y = NULL;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_u = *(real_T *)c46_inData;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", &c46_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, FALSE);
  return c46_mxArrayOutData;
}

static const mxArray *c46_d_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i83;
  real_T c46_b_inData[4];
  int32_T c46_i84;
  real_T c46_u[4];
  const mxArray *c46_y = NULL;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  for (c46_i83 = 0; c46_i83 < 4; c46_i83++) {
    c46_b_inData[c46_i83] = (*(real_T (*)[4])c46_inData)[c46_i83];
  }

  for (c46_i84 = 0; c46_i84 < 4; c46_i84++) {
    c46_u[c46_i84] = c46_b_inData[c46_i84];
  }

  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", c46_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, FALSE);
  return c46_mxArrayOutData;
}

static real_T c46_c_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  real_T c46_y;
  real_T c46_d0;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_d0, 1, 0, 0U, 0, 0U, 0);
  c46_y = c46_d0;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void c46_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_nargout;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  real_T c46_y;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_nargout = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_nargout),
    &c46_thisId);
  sf_mex_destroy(&c46_nargout);
  *(real_T *)c46_outData = c46_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

static const mxArray *c46_e_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i85;
  int32_T c46_i86;
  int32_T c46_i87;
  real_T c46_b_inData[9];
  int32_T c46_i88;
  int32_T c46_i89;
  int32_T c46_i90;
  real_T c46_u[9];
  const mxArray *c46_y = NULL;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_i85 = 0;
  for (c46_i86 = 0; c46_i86 < 3; c46_i86++) {
    for (c46_i87 = 0; c46_i87 < 3; c46_i87++) {
      c46_b_inData[c46_i87 + c46_i85] = (*(real_T (*)[9])c46_inData)[c46_i87 +
        c46_i85];
    }

    c46_i85 += 3;
  }

  c46_i88 = 0;
  for (c46_i89 = 0; c46_i89 < 3; c46_i89++) {
    for (c46_i90 = 0; c46_i90 < 3; c46_i90++) {
      c46_u[c46_i90 + c46_i88] = c46_b_inData[c46_i90 + c46_i88];
    }

    c46_i88 += 3;
  }

  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", c46_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, FALSE);
  return c46_mxArrayOutData;
}

static void c46_d_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId, real_T c46_y[9])
{
  real_T c46_dv6[9];
  int32_T c46_i91;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), c46_dv6, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c46_i91 = 0; c46_i91 < 9; c46_i91++) {
    c46_y[c46_i91] = c46_dv6[c46_i91];
  }

  sf_mex_destroy(&c46_u);
}

static void c46_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_qhat;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  real_T c46_y[9];
  int32_T c46_i92;
  int32_T c46_i93;
  int32_T c46_i94;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_qhat = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_qhat), &c46_thisId, c46_y);
  sf_mex_destroy(&c46_qhat);
  c46_i92 = 0;
  for (c46_i93 = 0; c46_i93 < 3; c46_i93++) {
    for (c46_i94 = 0; c46_i94 < 3; c46_i94++) {
      (*(real_T (*)[9])c46_outData)[c46_i94 + c46_i92] = c46_y[c46_i94 + c46_i92];
    }

    c46_i92 += 3;
  }

  sf_mex_destroy(&c46_mxArrayInData);
}

const mxArray *sf_c46_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c46_nameCaptureInfo = NULL;
  c46_nameCaptureInfo = NULL;
  sf_mex_assign(&c46_nameCaptureInfo, sf_mex_createstruct("structure", 2, 43, 1),
                FALSE);
  c46_info_helper(&c46_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c46_nameCaptureInfo);
  return c46_nameCaptureInfo;
}

static void c46_info_helper(const mxArray **c46_info)
{
  const mxArray *c46_rhs0 = NULL;
  const mxArray *c46_lhs0 = NULL;
  const mxArray *c46_rhs1 = NULL;
  const mxArray *c46_lhs1 = NULL;
  const mxArray *c46_rhs2 = NULL;
  const mxArray *c46_lhs2 = NULL;
  const mxArray *c46_rhs3 = NULL;
  const mxArray *c46_lhs3 = NULL;
  const mxArray *c46_rhs4 = NULL;
  const mxArray *c46_lhs4 = NULL;
  const mxArray *c46_rhs5 = NULL;
  const mxArray *c46_lhs5 = NULL;
  const mxArray *c46_rhs6 = NULL;
  const mxArray *c46_lhs6 = NULL;
  const mxArray *c46_rhs7 = NULL;
  const mxArray *c46_lhs7 = NULL;
  const mxArray *c46_rhs8 = NULL;
  const mxArray *c46_lhs8 = NULL;
  const mxArray *c46_rhs9 = NULL;
  const mxArray *c46_lhs9 = NULL;
  const mxArray *c46_rhs10 = NULL;
  const mxArray *c46_lhs10 = NULL;
  const mxArray *c46_rhs11 = NULL;
  const mxArray *c46_lhs11 = NULL;
  const mxArray *c46_rhs12 = NULL;
  const mxArray *c46_lhs12 = NULL;
  const mxArray *c46_rhs13 = NULL;
  const mxArray *c46_lhs13 = NULL;
  const mxArray *c46_rhs14 = NULL;
  const mxArray *c46_lhs14 = NULL;
  const mxArray *c46_rhs15 = NULL;
  const mxArray *c46_lhs15 = NULL;
  const mxArray *c46_rhs16 = NULL;
  const mxArray *c46_lhs16 = NULL;
  const mxArray *c46_rhs17 = NULL;
  const mxArray *c46_lhs17 = NULL;
  const mxArray *c46_rhs18 = NULL;
  const mxArray *c46_lhs18 = NULL;
  const mxArray *c46_rhs19 = NULL;
  const mxArray *c46_lhs19 = NULL;
  const mxArray *c46_rhs20 = NULL;
  const mxArray *c46_lhs20 = NULL;
  const mxArray *c46_rhs21 = NULL;
  const mxArray *c46_lhs21 = NULL;
  const mxArray *c46_rhs22 = NULL;
  const mxArray *c46_lhs22 = NULL;
  const mxArray *c46_rhs23 = NULL;
  const mxArray *c46_lhs23 = NULL;
  const mxArray *c46_rhs24 = NULL;
  const mxArray *c46_lhs24 = NULL;
  const mxArray *c46_rhs25 = NULL;
  const mxArray *c46_lhs25 = NULL;
  const mxArray *c46_rhs26 = NULL;
  const mxArray *c46_lhs26 = NULL;
  const mxArray *c46_rhs27 = NULL;
  const mxArray *c46_lhs27 = NULL;
  const mxArray *c46_rhs28 = NULL;
  const mxArray *c46_lhs28 = NULL;
  const mxArray *c46_rhs29 = NULL;
  const mxArray *c46_lhs29 = NULL;
  const mxArray *c46_rhs30 = NULL;
  const mxArray *c46_lhs30 = NULL;
  const mxArray *c46_rhs31 = NULL;
  const mxArray *c46_lhs31 = NULL;
  const mxArray *c46_rhs32 = NULL;
  const mxArray *c46_lhs32 = NULL;
  const mxArray *c46_rhs33 = NULL;
  const mxArray *c46_lhs33 = NULL;
  const mxArray *c46_rhs34 = NULL;
  const mxArray *c46_lhs34 = NULL;
  const mxArray *c46_rhs35 = NULL;
  const mxArray *c46_lhs35 = NULL;
  const mxArray *c46_rhs36 = NULL;
  const mxArray *c46_lhs36 = NULL;
  const mxArray *c46_rhs37 = NULL;
  const mxArray *c46_lhs37 = NULL;
  const mxArray *c46_rhs38 = NULL;
  const mxArray *c46_lhs38 = NULL;
  const mxArray *c46_rhs39 = NULL;
  const mxArray *c46_lhs39 = NULL;
  const mxArray *c46_rhs40 = NULL;
  const mxArray *c46_lhs40 = NULL;
  const mxArray *c46_rhs41 = NULL;
  const mxArray *c46_lhs41 = NULL;
  const mxArray *c46_rhs42 = NULL;
  const mxArray *c46_lhs42 = NULL;
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("dot"), "name", "name", 0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1360282354U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c46_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c46_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c46_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c46_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c46_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c46_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c46_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot"), "context",
                  "context", 7);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  7);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c46_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 8);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c46_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_xdot"), "name", "name",
                  9);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c46_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 10);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c46_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold"),
                  "context", "context", 11);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("length"), "name", "name", 11);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1303146206U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c46_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c46_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 13);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1299076772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c46_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 14);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c46_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 15);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c46_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 16);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c46_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 17);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c46_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 18);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("intmax"), "name", "name", 18);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c46_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 19);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c46_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 20);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c46_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 21);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 21);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c46_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c46_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 23);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 23);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c46_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c46_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("mtimes"), "name", "name", 25);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c46_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 26);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c46_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("mpower"), "name", "name", 27);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c46_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c46_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("ismatrix"), "name", "name",
                  29);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c46_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c46_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 31);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c46_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 32);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("mtimes"), "name", "name", 32);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c46_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 33);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c46_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 34);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c46_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  35);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c46_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 36);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c46_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 37);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("mtimes"), "name", "name", 37);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c46_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 38);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c46_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 39);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c46_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 40);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c46_rhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "context", "context", 41);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("cross"), "name", "name", 41);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c46_rhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("mtimes"), "name", "name", 42);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c46_rhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c46_lhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs42), "lhs", "lhs",
                  42);
  sf_mex_destroy(&c46_rhs0);
  sf_mex_destroy(&c46_lhs0);
  sf_mex_destroy(&c46_rhs1);
  sf_mex_destroy(&c46_lhs1);
  sf_mex_destroy(&c46_rhs2);
  sf_mex_destroy(&c46_lhs2);
  sf_mex_destroy(&c46_rhs3);
  sf_mex_destroy(&c46_lhs3);
  sf_mex_destroy(&c46_rhs4);
  sf_mex_destroy(&c46_lhs4);
  sf_mex_destroy(&c46_rhs5);
  sf_mex_destroy(&c46_lhs5);
  sf_mex_destroy(&c46_rhs6);
  sf_mex_destroy(&c46_lhs6);
  sf_mex_destroy(&c46_rhs7);
  sf_mex_destroy(&c46_lhs7);
  sf_mex_destroy(&c46_rhs8);
  sf_mex_destroy(&c46_lhs8);
  sf_mex_destroy(&c46_rhs9);
  sf_mex_destroy(&c46_lhs9);
  sf_mex_destroy(&c46_rhs10);
  sf_mex_destroy(&c46_lhs10);
  sf_mex_destroy(&c46_rhs11);
  sf_mex_destroy(&c46_lhs11);
  sf_mex_destroy(&c46_rhs12);
  sf_mex_destroy(&c46_lhs12);
  sf_mex_destroy(&c46_rhs13);
  sf_mex_destroy(&c46_lhs13);
  sf_mex_destroy(&c46_rhs14);
  sf_mex_destroy(&c46_lhs14);
  sf_mex_destroy(&c46_rhs15);
  sf_mex_destroy(&c46_lhs15);
  sf_mex_destroy(&c46_rhs16);
  sf_mex_destroy(&c46_lhs16);
  sf_mex_destroy(&c46_rhs17);
  sf_mex_destroy(&c46_lhs17);
  sf_mex_destroy(&c46_rhs18);
  sf_mex_destroy(&c46_lhs18);
  sf_mex_destroy(&c46_rhs19);
  sf_mex_destroy(&c46_lhs19);
  sf_mex_destroy(&c46_rhs20);
  sf_mex_destroy(&c46_lhs20);
  sf_mex_destroy(&c46_rhs21);
  sf_mex_destroy(&c46_lhs21);
  sf_mex_destroy(&c46_rhs22);
  sf_mex_destroy(&c46_lhs22);
  sf_mex_destroy(&c46_rhs23);
  sf_mex_destroy(&c46_lhs23);
  sf_mex_destroy(&c46_rhs24);
  sf_mex_destroy(&c46_lhs24);
  sf_mex_destroy(&c46_rhs25);
  sf_mex_destroy(&c46_lhs25);
  sf_mex_destroy(&c46_rhs26);
  sf_mex_destroy(&c46_lhs26);
  sf_mex_destroy(&c46_rhs27);
  sf_mex_destroy(&c46_lhs27);
  sf_mex_destroy(&c46_rhs28);
  sf_mex_destroy(&c46_lhs28);
  sf_mex_destroy(&c46_rhs29);
  sf_mex_destroy(&c46_lhs29);
  sf_mex_destroy(&c46_rhs30);
  sf_mex_destroy(&c46_lhs30);
  sf_mex_destroy(&c46_rhs31);
  sf_mex_destroy(&c46_lhs31);
  sf_mex_destroy(&c46_rhs32);
  sf_mex_destroy(&c46_lhs32);
  sf_mex_destroy(&c46_rhs33);
  sf_mex_destroy(&c46_lhs33);
  sf_mex_destroy(&c46_rhs34);
  sf_mex_destroy(&c46_lhs34);
  sf_mex_destroy(&c46_rhs35);
  sf_mex_destroy(&c46_lhs35);
  sf_mex_destroy(&c46_rhs36);
  sf_mex_destroy(&c46_lhs36);
  sf_mex_destroy(&c46_rhs37);
  sf_mex_destroy(&c46_lhs37);
  sf_mex_destroy(&c46_rhs38);
  sf_mex_destroy(&c46_lhs38);
  sf_mex_destroy(&c46_rhs39);
  sf_mex_destroy(&c46_lhs39);
  sf_mex_destroy(&c46_rhs40);
  sf_mex_destroy(&c46_lhs40);
  sf_mex_destroy(&c46_rhs41);
  sf_mex_destroy(&c46_lhs41);
  sf_mex_destroy(&c46_rhs42);
  sf_mex_destroy(&c46_lhs42);
}

static const mxArray *c46_emlrt_marshallOut(char * c46_u)
{
  const mxArray *c46_y = NULL;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", c46_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c46_u)), FALSE);
  return c46_y;
}

static const mxArray *c46_b_emlrt_marshallOut(uint32_T c46_u)
{
  const mxArray *c46_y = NULL;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", &c46_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c46_y;
}

static real_T c46_dot(SFc46_QRLsimInstanceStruct *chartInstance, real_T c46_a[3],
                      real_T c46_b[3])
{
  real_T c46_c;
  int32_T c46_k;
  int32_T c46_b_k;
  c46_eml_scalar_eg(chartInstance);
  c46_eml_scalar_eg(chartInstance);
  c46_c = 0.0;
  for (c46_k = 1; c46_k < 4; c46_k++) {
    c46_b_k = c46_k;
    c46_c += c46_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c46_b_k), 1, 3, 1, 0) - 1] * c46_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c46_b_k), 1, 3, 1, 0) - 1];
  }

  return c46_c;
}

static void c46_eml_scalar_eg(SFc46_QRLsimInstanceStruct *chartInstance)
{
}

static void c46_matrix_to_integer_power(SFc46_QRLsimInstanceStruct
  *chartInstance, real_T c46_a[9], real_T c46_c[9])
{
  int32_T c46_i95;
  int32_T c46_i96;
  int32_T c46_i97;
  int32_T c46_i98;
  int32_T c46_i99;
  c46_b_eml_scalar_eg(chartInstance);
  c46_b_eml_scalar_eg(chartInstance);
  for (c46_i95 = 0; c46_i95 < 3; c46_i95++) {
    c46_i96 = 0;
    for (c46_i97 = 0; c46_i97 < 3; c46_i97++) {
      c46_c[c46_i96 + c46_i95] = 0.0;
      c46_i98 = 0;
      for (c46_i99 = 0; c46_i99 < 3; c46_i99++) {
        c46_c[c46_i96 + c46_i95] += c46_a[c46_i98 + c46_i95] * c46_a[c46_i99 +
          c46_i96];
        c46_i98 += 3;
      }

      c46_i96 += 3;
    }
  }
}

static void c46_b_eml_scalar_eg(SFc46_QRLsimInstanceStruct *chartInstance)
{
}

static void c46_c_eml_scalar_eg(SFc46_QRLsimInstanceStruct *chartInstance)
{
}

static void c46_cross(SFc46_QRLsimInstanceStruct *chartInstance, real_T c46_a[3],
                      real_T c46_b[3], real_T c46_c[3])
{
  real_T c46_b_a;
  real_T c46_b_b;
  real_T c46_y;
  real_T c46_c_a;
  real_T c46_c_b;
  real_T c46_b_y;
  real_T c46_c1;
  real_T c46_d_a;
  real_T c46_d_b;
  real_T c46_c_y;
  real_T c46_e_a;
  real_T c46_e_b;
  real_T c46_d_y;
  real_T c46_c2;
  real_T c46_f_a;
  real_T c46_f_b;
  real_T c46_e_y;
  real_T c46_g_a;
  real_T c46_g_b;
  real_T c46_f_y;
  real_T c46_c3;
  c46_b_a = c46_a[1];
  c46_b_b = c46_b[2];
  c46_y = c46_b_a * c46_b_b;
  c46_c_a = c46_a[2];
  c46_c_b = c46_b[1];
  c46_b_y = c46_c_a * c46_c_b;
  c46_c1 = c46_y - c46_b_y;
  c46_d_a = c46_a[2];
  c46_d_b = c46_b[0];
  c46_c_y = c46_d_a * c46_d_b;
  c46_e_a = c46_a[0];
  c46_e_b = c46_b[2];
  c46_d_y = c46_e_a * c46_e_b;
  c46_c2 = c46_c_y - c46_d_y;
  c46_f_a = c46_a[0];
  c46_f_b = c46_b[1];
  c46_e_y = c46_f_a * c46_f_b;
  c46_g_a = c46_a[1];
  c46_g_b = c46_b[0];
  c46_f_y = c46_g_a * c46_g_b;
  c46_c3 = c46_e_y - c46_f_y;
  c46_c[0] = c46_c1;
  c46_c[1] = c46_c2;
  c46_c[2] = c46_c3;
}

static const mxArray *c46_f_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_u;
  const mxArray *c46_y = NULL;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_u = *(int32_T *)c46_inData;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", &c46_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, FALSE);
  return c46_mxArrayOutData;
}

static int32_T c46_e_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  int32_T c46_y;
  int32_T c46_i100;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_i100, 1, 6, 0U, 0, 0U, 0);
  c46_y = c46_i100;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void c46_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_b_sfEvent;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  int32_T c46_y;
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)chartInstanceVoid;
  c46_b_sfEvent = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_b_sfEvent),
    &c46_thisId);
  sf_mex_destroy(&c46_b_sfEvent);
  *(int32_T *)c46_outData = c46_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

static uint8_T c46_f_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_b_is_active_c46_QRLsim, const char_T *c46_identifier)
{
  uint8_T c46_y;
  emlrtMsgIdentifier c46_thisId;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c46_b_is_active_c46_QRLsim), &c46_thisId);
  sf_mex_destroy(&c46_b_is_active_c46_QRLsim);
  return c46_y;
}

static uint8_T c46_g_emlrt_marshallIn(SFc46_QRLsimInstanceStruct *chartInstance,
  const mxArray *c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  uint8_T c46_y;
  uint8_T c46_u0;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_u0, 1, 3, 0U, 0, 0U, 0);
  c46_y = c46_u0;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void init_dsm_address_info(SFc46_QRLsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c46_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4087375772U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2122179342U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2548326878U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1027651483U);
}

mxArray *sf_c46_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("krM8Y33xFdY4UTEbKBCClE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c46_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c46_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c46_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[11],T\"Fff\",},{M[1],M[5],T\"Fn\",},{M[1],M[10],T\"Fpd\",},{M[1],M[14],T\"edq\",},{M[1],M[13],T\"eq\",},{M[8],M[0],T\"is_active_c46_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c46_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc46_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc46_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           46,
           1,
           1,
           13,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QRLsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_QRLsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _QRLsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"varF");
          _SFD_SET_DATA_PROPS(1,1,1,0,"A");
          _SFD_SET_DATA_PROPS(2,1,1,0,"mode");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Fn");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(6,1,1,0,"qc");
          _SFD_SET_DATA_PROPS(7,1,1,0,"dqc");
          _SFD_SET_DATA_PROPS(8,1,1,0,"ddqc");
          _SFD_SET_DATA_PROPS(9,2,0,1,"Fpd");
          _SFD_SET_DATA_PROPS(10,2,0,1,"Fff");
          _SFD_SET_DATA_PROPS(11,2,0,1,"eq");
          _SFD_SET_DATA_PROPS(12,2,0,1,"edq");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,574);

        {
          static int caseStart[] = { 178, 142 };

          static int caseExprEnd[] = { 187, 148 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,126,138,218,2,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)
            c46_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)
            c46_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)
            c46_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)
            c46_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)
            c46_sf_marshallIn);
        }

        {
          real_T *c46_mode;
          real_T (*c46_varF)[4];
          real_T (*c46_A)[3];
          real_T (*c46_q)[3];
          real_T (*c46_Fn)[3];
          real_T (*c46_dq)[3];
          real_T (*c46_qc)[3];
          real_T (*c46_dqc)[3];
          real_T (*c46_ddqc)[3];
          real_T (*c46_Fpd)[3];
          real_T (*c46_Fff)[3];
          real_T (*c46_eq)[3];
          real_T (*c46_edq)[3];
          c46_edq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
          c46_eq = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
          c46_Fff = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c46_Fpd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c46_ddqc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
          c46_dqc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
          c46_qc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c46_dq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c46_Fn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c46_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c46_mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c46_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c46_varF = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c46_varF);
          _SFD_SET_DATA_VALUE_PTR(1U, *c46_A);
          _SFD_SET_DATA_VALUE_PTR(2U, c46_mode);
          _SFD_SET_DATA_VALUE_PTR(3U, *c46_q);
          _SFD_SET_DATA_VALUE_PTR(4U, *c46_Fn);
          _SFD_SET_DATA_VALUE_PTR(5U, *c46_dq);
          _SFD_SET_DATA_VALUE_PTR(6U, *c46_qc);
          _SFD_SET_DATA_VALUE_PTR(7U, *c46_dqc);
          _SFD_SET_DATA_VALUE_PTR(8U, *c46_ddqc);
          _SFD_SET_DATA_VALUE_PTR(9U, *c46_Fpd);
          _SFD_SET_DATA_VALUE_PTR(10U, *c46_Fff);
          _SFD_SET_DATA_VALUE_PTR(11U, *c46_eq);
          _SFD_SET_DATA_VALUE_PTR(12U, *c46_edq);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _QRLsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "nYYlsqQqt1ClMp0nvwwJ6E";
}

static void sf_opaque_initialize_c46_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc46_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c46_QRLsim(void *chartInstanceVar)
{
  enable_c46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c46_QRLsim(void *chartInstanceVar)
{
  disable_c46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c46_QRLsim(void *chartInstanceVar)
{
  sf_c46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c46_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c46_QRLsim((SFc46_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c46_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c46_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c46_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c46_QRLsim((SFc46_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c46_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c46_QRLsim(S);
}

static void sf_opaque_set_sim_state_c46_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c46_QRLsim(S, st);
}

static void sf_opaque_terminate_c46_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc46_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc46_QRLsim((SFc46_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c46_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c46_QRLsim((SFc46_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c46_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      46);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,46,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,46,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,46);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,46,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,46,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,46);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2493619664U));
  ssSetChecksum1(S,(3718286802U));
  ssSetChecksum2(S,(1014047080U));
  ssSetChecksum3(S,(3280925037U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c46_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c46_QRLsim(SimStruct *S)
{
  SFc46_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc46_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc46_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc46_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c46_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c46_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c46_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c46_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c46_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c46_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c46_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c46_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c46_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c46_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c46_QRLsim;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c46_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c46_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c46_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c46_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c46_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
