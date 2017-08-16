/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c3_QRLsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[18] = { "b2c", "db3c", "db2c", "db1c",
  "ddb3c", "ddb2c", "ddb1c", "nargin", "nargout", "C", "dC", "ddC", "b3c", "F",
  "dF", "ddF", "dRc", "ddRc" };

/* Function Declarations */
static void initialize_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void enable_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void disable_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_QRLsim(SFc3_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_QRLsim(SFc3_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void sf_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void c3_chartstep_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance, const
  mxArray *c3_ddRc, const char_T *c3_identifier, real_T c3_y[9]);
static void c3_b_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_d_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(uint32_T c3_u);
static real_T c3_norm(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_x[3]);
static real_T c3_dot(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3]);
static void c3_eml_scalar_eg(SFc3_QRLsimInstanceStruct *chartInstance);
static real_T c3_mpower(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a);
static void c3_b_eml_scalar_eg(SFc3_QRLsimInstanceStruct *chartInstance);
static void c3_cross(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3], real_T c3_c[3]);
static real_T c3_b_mpower(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a);
static real_T c3_c_mpower(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_QRLsim, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_QRLsim = 0U;
}

static void initialize_params_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
}

static void enable_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_QRLsim(SFc3_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_QRLsim(SFc3_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[9];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i1;
  real_T c3_b_u[9];
  const mxArray *c3_c_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T (*c3_ddRc)[9];
  real_T (*c3_dRc)[9];
  c3_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
    c3_u[c3_i0] = (*c3_dRc)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i1 = 0; c3_i1 < 9; c3_i1++) {
    c3_b_u[c3_i1] = (*c3_ddRc)[c3_i1];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_QRLsim;
  c3_c_u = c3_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[9];
  int32_T c3_i2;
  real_T c3_dv1[9];
  int32_T c3_i3;
  real_T (*c3_dRc)[9];
  real_T (*c3_ddRc)[9];
  c3_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "dRc",
                      c3_dv0);
  for (c3_i2 = 0; c3_i2 < 9; c3_i2++) {
    (*c3_dRc)[c3_i2] = c3_dv0[c3_i2];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)), "ddRc",
                      c3_dv1);
  for (c3_i3 = 0; c3_i3 < 9; c3_i3++) {
    (*c3_ddRc)[c3_i3] = c3_dv1[c3_i3];
  }

  chartInstance->c3_is_active_c3_QRLsim = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "is_active_c3_QRLsim");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_QRLsim(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T (*c3_ddRc)[9];
  real_T (*c3_ddF)[3];
  real_T (*c3_dF)[3];
  real_T (*c3_F)[3];
  real_T (*c3_b3c)[3];
  real_T (*c3_ddC)[3];
  real_T (*c3_dC)[3];
  real_T (*c3_dRc)[9];
  real_T (*c3_C)[3];
  c3_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_ddF = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c3_dF = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c3_F = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c3_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c3_ddC = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c3_dC = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_C = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_C)[c3_i4], 0U);
  }

  for (c3_i5 = 0; c3_i5 < 9; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*c3_dRc)[c3_i5], 1U);
  }

  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    _SFD_DATA_RANGE_CHECK((*c3_dC)[c3_i6], 2U);
  }

  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    _SFD_DATA_RANGE_CHECK((*c3_ddC)[c3_i7], 3U);
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    _SFD_DATA_RANGE_CHECK((*c3_b3c)[c3_i8], 4U);
  }

  for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
    _SFD_DATA_RANGE_CHECK((*c3_F)[c3_i9], 5U);
  }

  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    _SFD_DATA_RANGE_CHECK((*c3_dF)[c3_i10], 6U);
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    _SFD_DATA_RANGE_CHECK((*c3_ddF)[c3_i11], 7U);
  }

  for (c3_i12 = 0; c3_i12 < 9; c3_i12++) {
    _SFD_DATA_RANGE_CHECK((*c3_ddRc)[c3_i12], 8U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_QRLsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
  int32_T c3_i13;
  real_T c3_C[3];
  int32_T c3_i14;
  real_T c3_dC[3];
  int32_T c3_i15;
  real_T c3_ddC[3];
  int32_T c3_i16;
  real_T c3_b3c[3];
  int32_T c3_i17;
  real_T c3_F[3];
  int32_T c3_i18;
  real_T c3_dF[3];
  int32_T c3_i19;
  real_T c3_ddF[3];
  uint32_T c3_debug_family_var_map[18];
  real_T c3_b2c[3];
  real_T c3_db3c[3];
  real_T c3_db2c[3];
  real_T c3_db1c[3];
  real_T c3_ddb3c[3];
  real_T c3_ddb2c[3];
  real_T c3_ddb1c[3];
  real_T c3_nargin = 7.0;
  real_T c3_nargout = 2.0;
  real_T c3_dRc[9];
  real_T c3_ddRc[9];
  int32_T c3_i20;
  real_T c3_A[3];
  int32_T c3_i21;
  real_T c3_b_C[3];
  real_T c3_B;
  real_T c3_y;
  real_T c3_b_y;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_b_F[3];
  real_T c3_b_B;
  real_T c3_c_y;
  real_T c3_d_y;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_c_F[3];
  int32_T c3_i27;
  real_T c3_b_dF[3];
  real_T c3_a;
  int32_T c3_i28;
  real_T c3_b[3];
  int32_T c3_i29;
  int32_T c3_i30;
  real_T c3_d_F[3];
  real_T c3_c_B;
  real_T c3_e_y;
  real_T c3_f_y;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  real_T c3_c_C[3];
  real_T c3_d_B;
  real_T c3_g_y;
  real_T c3_h_y;
  int32_T c3_i35;
  int32_T c3_i36;
  real_T c3_d_C[3];
  int32_T c3_i37;
  real_T c3_b_dC[3];
  real_T c3_b_a;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  real_T c3_e_C[3];
  real_T c3_e_B;
  real_T c3_i_y;
  real_T c3_j_y;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  real_T c3_b_db2c[3];
  int32_T c3_i44;
  real_T c3_b_b3c[3];
  int32_T c3_i45;
  real_T c3_b_b2c[3];
  int32_T c3_i46;
  real_T c3_b_db3c[3];
  real_T c3_b_b[3];
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  real_T c3_e_F[3];
  real_T c3_f_B;
  real_T c3_k_y;
  real_T c3_l_y;
  int32_T c3_i53;
  int32_T c3_i54;
  real_T c3_f_F[3];
  int32_T c3_i55;
  real_T c3_c_dF[3];
  real_T c3_c_b;
  real_T c3_m_y;
  real_T c3_c_a;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  real_T c3_g_F[3];
  real_T c3_g_B;
  real_T c3_n_y;
  real_T c3_o_y;
  int32_T c3_i59;
  int32_T c3_i60;
  real_T c3_d_dF[3];
  int32_T c3_i61;
  real_T c3_h_F[3];
  int32_T c3_i62;
  real_T c3_b_ddF[3];
  real_T c3_d_a;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  real_T c3_i_F[3];
  real_T c3_h_B;
  real_T c3_p_y;
  real_T c3_q_y;
  int32_T c3_i66;
  int32_T c3_i67;
  real_T c3_j_F[3];
  int32_T c3_i68;
  real_T c3_e_dF[3];
  real_T c3_d_b;
  real_T c3_r_y;
  real_T c3_e_a;
  int32_T c3_i69;
  real_T c3_e_b[3];
  int32_T c3_i70;
  int32_T c3_i71;
  real_T c3_k_F[3];
  real_T c3_i_B;
  real_T c3_s_y;
  real_T c3_t_y;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  real_T c3_f_C[3];
  real_T c3_j_B;
  real_T c3_u_y;
  real_T c3_v_y;
  int32_T c3_i76;
  int32_T c3_i77;
  real_T c3_g_C[3];
  int32_T c3_i78;
  real_T c3_c_dC[3];
  real_T c3_f_b;
  real_T c3_w_y;
  real_T c3_f_a;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  real_T c3_h_C[3];
  real_T c3_k_B;
  real_T c3_x_y;
  real_T c3_y_y;
  int32_T c3_i82;
  int32_T c3_i83;
  real_T c3_d_dC[3];
  int32_T c3_i84;
  real_T c3_i_C[3];
  int32_T c3_i85;
  real_T c3_b_ddC[3];
  real_T c3_g_a;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  real_T c3_j_C[3];
  real_T c3_l_B;
  real_T c3_ab_y;
  real_T c3_bb_y;
  int32_T c3_i89;
  int32_T c3_i90;
  real_T c3_k_C[3];
  int32_T c3_i91;
  real_T c3_e_dC[3];
  real_T c3_g_b;
  real_T c3_cb_y;
  real_T c3_h_a;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  real_T c3_l_C[3];
  real_T c3_m_B;
  real_T c3_db_y;
  real_T c3_eb_y;
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  real_T c3_c_db2c[3];
  int32_T c3_i98;
  real_T c3_c_db3c[3];
  int32_T c3_i99;
  int32_T c3_i100;
  real_T c3_b_ddb2c[3];
  int32_T c3_i101;
  real_T c3_c_b3c[3];
  int32_T c3_i102;
  real_T c3_c_b2c[3];
  int32_T c3_i103;
  real_T c3_b_ddb3c[3];
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  real_T (*c3_b_dRc)[9];
  real_T (*c3_b_ddRc)[9];
  real_T (*c3_c_ddF)[3];
  real_T (*c3_f_dF)[3];
  real_T (*c3_l_F)[3];
  real_T (*c3_d_b3c)[3];
  real_T (*c3_c_ddC)[3];
  real_T (*c3_f_dC)[3];
  real_T (*c3_m_C)[3];
  c3_b_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_c_ddF = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c3_f_dF = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c3_l_F = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c3_d_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c3_c_ddC = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c3_f_dC = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_m_C = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    c3_C[c3_i13] = (*c3_m_C)[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    c3_dC[c3_i14] = (*c3_f_dC)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_ddC[c3_i15] = (*c3_c_ddC)[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    c3_b3c[c3_i16] = (*c3_d_b3c)[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    c3_F[c3_i17] = (*c3_l_F)[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
    c3_dF[c3_i18] = (*c3_f_dF)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
    c3_ddF[c3_i19] = (*c3_c_ddF)[c3_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b2c, 0U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_db3c, 1U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_db2c, 2U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_db1c, 3U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_ddb3c, 4U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_ddb2c, 5U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_ddb1c, 6U, c3_b_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 7U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 8U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_C, 9U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_dC, 10U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_ddC, 11U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b3c, 12U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_F, 13U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_dF, 14U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_ddF, 15U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_dRc, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_ddRc, 17U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
    c3_A[c3_i20] = c3_C[c3_i20];
  }

  for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
    c3_b_C[c3_i21] = c3_C[c3_i21];
  }

  c3_B = c3_norm(chartInstance, c3_b_C);
  c3_y = c3_B;
  c3_b_y = c3_y;
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    c3_b2c[c3_i22] = c3_A[c3_i22] / c3_b_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
    c3_A[c3_i23] = c3_dF[c3_i23];
  }

  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    c3_b_F[c3_i24] = c3_F[c3_i24];
  }

  c3_b_B = c3_norm(chartInstance, c3_b_F);
  c3_c_y = c3_b_B;
  c3_d_y = c3_c_y;
  for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
    c3_A[c3_i25] /= c3_d_y;
  }

  for (c3_i26 = 0; c3_i26 < 3; c3_i26++) {
    c3_c_F[c3_i26] = c3_F[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
    c3_b_dF[c3_i27] = c3_dF[c3_i27];
  }

  c3_a = c3_dot(chartInstance, c3_c_F, c3_b_dF);
  for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
    c3_b[c3_i28] = c3_F[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 3; c3_i29++) {
    c3_b[c3_i29] *= c3_a;
  }

  for (c3_i30 = 0; c3_i30 < 3; c3_i30++) {
    c3_d_F[c3_i30] = c3_F[c3_i30];
  }

  c3_c_B = c3_mpower(chartInstance, c3_norm(chartInstance, c3_d_F));
  c3_e_y = c3_c_B;
  c3_f_y = c3_e_y;
  for (c3_i31 = 0; c3_i31 < 3; c3_i31++) {
    c3_b[c3_i31] /= c3_f_y;
  }

  for (c3_i32 = 0; c3_i32 < 3; c3_i32++) {
    c3_db3c[c3_i32] = c3_A[c3_i32] + c3_b[c3_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  for (c3_i33 = 0; c3_i33 < 3; c3_i33++) {
    c3_A[c3_i33] = c3_dC[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 3; c3_i34++) {
    c3_c_C[c3_i34] = c3_C[c3_i34];
  }

  c3_d_B = c3_norm(chartInstance, c3_c_C);
  c3_g_y = c3_d_B;
  c3_h_y = c3_g_y;
  for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
    c3_A[c3_i35] /= c3_h_y;
  }

  for (c3_i36 = 0; c3_i36 < 3; c3_i36++) {
    c3_d_C[c3_i36] = c3_C[c3_i36];
  }

  for (c3_i37 = 0; c3_i37 < 3; c3_i37++) {
    c3_b_dC[c3_i37] = c3_dC[c3_i37];
  }

  c3_b_a = c3_dot(chartInstance, c3_d_C, c3_b_dC);
  for (c3_i38 = 0; c3_i38 < 3; c3_i38++) {
    c3_b[c3_i38] = c3_C[c3_i38];
  }

  for (c3_i39 = 0; c3_i39 < 3; c3_i39++) {
    c3_b[c3_i39] *= c3_b_a;
  }

  for (c3_i40 = 0; c3_i40 < 3; c3_i40++) {
    c3_e_C[c3_i40] = c3_C[c3_i40];
  }

  c3_e_B = c3_mpower(chartInstance, c3_norm(chartInstance, c3_e_C));
  c3_i_y = c3_e_B;
  c3_j_y = c3_i_y;
  for (c3_i41 = 0; c3_i41 < 3; c3_i41++) {
    c3_b[c3_i41] /= c3_j_y;
  }

  for (c3_i42 = 0; c3_i42 < 3; c3_i42++) {
    c3_db2c[c3_i42] = c3_A[c3_i42] + c3_b[c3_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i43 = 0; c3_i43 < 3; c3_i43++) {
    c3_b_db2c[c3_i43] = c3_db2c[c3_i43];
  }

  for (c3_i44 = 0; c3_i44 < 3; c3_i44++) {
    c3_b_b3c[c3_i44] = c3_b3c[c3_i44];
  }

  c3_cross(chartInstance, c3_b_db2c, c3_b_b3c, c3_A);
  for (c3_i45 = 0; c3_i45 < 3; c3_i45++) {
    c3_b_b2c[c3_i45] = c3_b2c[c3_i45];
  }

  for (c3_i46 = 0; c3_i46 < 3; c3_i46++) {
    c3_b_db3c[c3_i46] = c3_db3c[c3_i46];
  }

  c3_cross(chartInstance, c3_b_b2c, c3_b_db3c, c3_b_b);
  for (c3_i47 = 0; c3_i47 < 3; c3_i47++) {
    c3_db1c[c3_i47] = c3_A[c3_i47] + c3_b_b[c3_i47];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i48 = 0; c3_i48 < 3; c3_i48++) {
    c3_dRc[c3_i48] = c3_db1c[c3_i48];
  }

  for (c3_i49 = 0; c3_i49 < 3; c3_i49++) {
    c3_dRc[c3_i49 + 3] = c3_db2c[c3_i49];
  }

  for (c3_i50 = 0; c3_i50 < 3; c3_i50++) {
    c3_dRc[c3_i50 + 6] = c3_db3c[c3_i50];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i51 = 0; c3_i51 < 3; c3_i51++) {
    c3_A[c3_i51] = c3_ddF[c3_i51];
  }

  for (c3_i52 = 0; c3_i52 < 3; c3_i52++) {
    c3_e_F[c3_i52] = c3_F[c3_i52];
  }

  c3_f_B = c3_norm(chartInstance, c3_e_F);
  c3_k_y = c3_f_B;
  c3_l_y = c3_k_y;
  for (c3_i53 = 0; c3_i53 < 3; c3_i53++) {
    c3_A[c3_i53] /= c3_l_y;
  }

  for (c3_i54 = 0; c3_i54 < 3; c3_i54++) {
    c3_f_F[c3_i54] = c3_F[c3_i54];
  }

  for (c3_i55 = 0; c3_i55 < 3; c3_i55++) {
    c3_c_dF[c3_i55] = c3_dF[c3_i55];
  }

  c3_c_b = c3_dot(chartInstance, c3_f_F, c3_c_dF);
  c3_m_y = 2.0 * c3_c_b;
  c3_c_a = c3_m_y;
  for (c3_i56 = 0; c3_i56 < 3; c3_i56++) {
    c3_b[c3_i56] = c3_dF[c3_i56];
  }

  for (c3_i57 = 0; c3_i57 < 3; c3_i57++) {
    c3_b[c3_i57] *= c3_c_a;
  }

  for (c3_i58 = 0; c3_i58 < 3; c3_i58++) {
    c3_g_F[c3_i58] = c3_F[c3_i58];
  }

  c3_g_B = c3_mpower(chartInstance, c3_norm(chartInstance, c3_g_F));
  c3_n_y = c3_g_B;
  c3_o_y = c3_n_y;
  for (c3_i59 = 0; c3_i59 < 3; c3_i59++) {
    c3_b[c3_i59] /= c3_o_y;
  }

  for (c3_i60 = 0; c3_i60 < 3; c3_i60++) {
    c3_d_dF[c3_i60] = c3_dF[c3_i60];
  }

  for (c3_i61 = 0; c3_i61 < 3; c3_i61++) {
    c3_h_F[c3_i61] = c3_F[c3_i61];
  }

  for (c3_i62 = 0; c3_i62 < 3; c3_i62++) {
    c3_b_ddF[c3_i62] = c3_ddF[c3_i62];
  }

  c3_d_a = c3_b_mpower(chartInstance, c3_norm(chartInstance, c3_d_dF)) + c3_dot
    (chartInstance, c3_h_F, c3_b_ddF);
  for (c3_i63 = 0; c3_i63 < 3; c3_i63++) {
    c3_b_b[c3_i63] = c3_F[c3_i63];
  }

  for (c3_i64 = 0; c3_i64 < 3; c3_i64++) {
    c3_b_b[c3_i64] *= c3_d_a;
  }

  for (c3_i65 = 0; c3_i65 < 3; c3_i65++) {
    c3_i_F[c3_i65] = c3_F[c3_i65];
  }

  c3_h_B = c3_mpower(chartInstance, c3_norm(chartInstance, c3_i_F));
  c3_p_y = c3_h_B;
  c3_q_y = c3_p_y;
  for (c3_i66 = 0; c3_i66 < 3; c3_i66++) {
    c3_b_b[c3_i66] /= c3_q_y;
  }

  for (c3_i67 = 0; c3_i67 < 3; c3_i67++) {
    c3_j_F[c3_i67] = c3_F[c3_i67];
  }

  for (c3_i68 = 0; c3_i68 < 3; c3_i68++) {
    c3_e_dF[c3_i68] = c3_dF[c3_i68];
  }

  c3_d_b = c3_b_mpower(chartInstance, c3_dot(chartInstance, c3_j_F, c3_e_dF));
  c3_r_y = 3.0 * c3_d_b;
  c3_e_a = c3_r_y;
  for (c3_i69 = 0; c3_i69 < 3; c3_i69++) {
    c3_e_b[c3_i69] = c3_F[c3_i69];
  }

  for (c3_i70 = 0; c3_i70 < 3; c3_i70++) {
    c3_e_b[c3_i70] *= c3_e_a;
  }

  for (c3_i71 = 0; c3_i71 < 3; c3_i71++) {
    c3_k_F[c3_i71] = c3_F[c3_i71];
  }

  c3_i_B = c3_c_mpower(chartInstance, c3_norm(chartInstance, c3_k_F));
  c3_s_y = c3_i_B;
  c3_t_y = c3_s_y;
  for (c3_i72 = 0; c3_i72 < 3; c3_i72++) {
    c3_e_b[c3_i72] /= c3_t_y;
  }

  for (c3_i73 = 0; c3_i73 < 3; c3_i73++) {
    c3_ddb3c[c3_i73] = ((c3_A[c3_i73] + c3_b[c3_i73]) + c3_b_b[c3_i73]) -
      c3_e_b[c3_i73];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  for (c3_i74 = 0; c3_i74 < 3; c3_i74++) {
    c3_A[c3_i74] = c3_ddC[c3_i74];
  }

  for (c3_i75 = 0; c3_i75 < 3; c3_i75++) {
    c3_f_C[c3_i75] = c3_C[c3_i75];
  }

  c3_j_B = c3_norm(chartInstance, c3_f_C);
  c3_u_y = c3_j_B;
  c3_v_y = c3_u_y;
  for (c3_i76 = 0; c3_i76 < 3; c3_i76++) {
    c3_A[c3_i76] /= c3_v_y;
  }

  for (c3_i77 = 0; c3_i77 < 3; c3_i77++) {
    c3_g_C[c3_i77] = c3_C[c3_i77];
  }

  for (c3_i78 = 0; c3_i78 < 3; c3_i78++) {
    c3_c_dC[c3_i78] = c3_dC[c3_i78];
  }

  c3_f_b = c3_dot(chartInstance, c3_g_C, c3_c_dC);
  c3_w_y = 2.0 * c3_f_b;
  c3_f_a = c3_w_y;
  for (c3_i79 = 0; c3_i79 < 3; c3_i79++) {
    c3_b[c3_i79] = c3_dC[c3_i79];
  }

  for (c3_i80 = 0; c3_i80 < 3; c3_i80++) {
    c3_b[c3_i80] *= c3_f_a;
  }

  for (c3_i81 = 0; c3_i81 < 3; c3_i81++) {
    c3_h_C[c3_i81] = c3_C[c3_i81];
  }

  c3_k_B = c3_mpower(chartInstance, c3_norm(chartInstance, c3_h_C));
  c3_x_y = c3_k_B;
  c3_y_y = c3_x_y;
  for (c3_i82 = 0; c3_i82 < 3; c3_i82++) {
    c3_b[c3_i82] /= c3_y_y;
  }

  for (c3_i83 = 0; c3_i83 < 3; c3_i83++) {
    c3_d_dC[c3_i83] = c3_dC[c3_i83];
  }

  for (c3_i84 = 0; c3_i84 < 3; c3_i84++) {
    c3_i_C[c3_i84] = c3_C[c3_i84];
  }

  for (c3_i85 = 0; c3_i85 < 3; c3_i85++) {
    c3_b_ddC[c3_i85] = c3_ddC[c3_i85];
  }

  c3_g_a = c3_b_mpower(chartInstance, c3_norm(chartInstance, c3_d_dC)) + c3_dot
    (chartInstance, c3_i_C, c3_b_ddC);
  for (c3_i86 = 0; c3_i86 < 3; c3_i86++) {
    c3_b_b[c3_i86] = c3_C[c3_i86];
  }

  for (c3_i87 = 0; c3_i87 < 3; c3_i87++) {
    c3_b_b[c3_i87] *= c3_g_a;
  }

  for (c3_i88 = 0; c3_i88 < 3; c3_i88++) {
    c3_j_C[c3_i88] = c3_C[c3_i88];
  }

  c3_l_B = c3_mpower(chartInstance, c3_norm(chartInstance, c3_j_C));
  c3_ab_y = c3_l_B;
  c3_bb_y = c3_ab_y;
  for (c3_i89 = 0; c3_i89 < 3; c3_i89++) {
    c3_b_b[c3_i89] /= c3_bb_y;
  }

  for (c3_i90 = 0; c3_i90 < 3; c3_i90++) {
    c3_k_C[c3_i90] = c3_C[c3_i90];
  }

  for (c3_i91 = 0; c3_i91 < 3; c3_i91++) {
    c3_e_dC[c3_i91] = c3_dC[c3_i91];
  }

  c3_g_b = c3_b_mpower(chartInstance, c3_dot(chartInstance, c3_k_C, c3_e_dC));
  c3_cb_y = 3.0 * c3_g_b;
  c3_h_a = c3_cb_y;
  for (c3_i92 = 0; c3_i92 < 3; c3_i92++) {
    c3_e_b[c3_i92] = c3_C[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 3; c3_i93++) {
    c3_e_b[c3_i93] *= c3_h_a;
  }

  for (c3_i94 = 0; c3_i94 < 3; c3_i94++) {
    c3_l_C[c3_i94] = c3_C[c3_i94];
  }

  c3_m_B = c3_c_mpower(chartInstance, c3_norm(chartInstance, c3_l_C));
  c3_db_y = c3_m_B;
  c3_eb_y = c3_db_y;
  for (c3_i95 = 0; c3_i95 < 3; c3_i95++) {
    c3_e_b[c3_i95] /= c3_eb_y;
  }

  for (c3_i96 = 0; c3_i96 < 3; c3_i96++) {
    c3_ddb2c[c3_i96] = ((c3_A[c3_i96] + c3_b[c3_i96]) + c3_b_b[c3_i96]) -
      c3_e_b[c3_i96];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  for (c3_i97 = 0; c3_i97 < 3; c3_i97++) {
    c3_c_db2c[c3_i97] = c3_db2c[c3_i97];
  }

  for (c3_i98 = 0; c3_i98 < 3; c3_i98++) {
    c3_c_db3c[c3_i98] = c3_db3c[c3_i98];
  }

  c3_cross(chartInstance, c3_c_db2c, c3_c_db3c, c3_b);
  for (c3_i99 = 0; c3_i99 < 3; c3_i99++) {
    c3_b[c3_i99] *= 2.0;
  }

  for (c3_i100 = 0; c3_i100 < 3; c3_i100++) {
    c3_b_ddb2c[c3_i100] = c3_ddb2c[c3_i100];
  }

  for (c3_i101 = 0; c3_i101 < 3; c3_i101++) {
    c3_c_b3c[c3_i101] = c3_b3c[c3_i101];
  }

  c3_cross(chartInstance, c3_b_ddb2c, c3_c_b3c, c3_A);
  for (c3_i102 = 0; c3_i102 < 3; c3_i102++) {
    c3_c_b2c[c3_i102] = c3_b2c[c3_i102];
  }

  for (c3_i103 = 0; c3_i103 < 3; c3_i103++) {
    c3_b_ddb3c[c3_i103] = c3_ddb3c[c3_i103];
  }

  c3_cross(chartInstance, c3_c_b2c, c3_b_ddb3c, c3_b_b);
  for (c3_i104 = 0; c3_i104 < 3; c3_i104++) {
    c3_ddb1c[c3_i104] = (c3_A[c3_i104] + c3_b[c3_i104]) + c3_b_b[c3_i104];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  for (c3_i105 = 0; c3_i105 < 3; c3_i105++) {
    c3_ddRc[c3_i105] = c3_ddb1c[c3_i105];
  }

  for (c3_i106 = 0; c3_i106 < 3; c3_i106++) {
    c3_ddRc[c3_i106 + 3] = c3_ddb2c[c3_i106];
  }

  for (c3_i107 = 0; c3_i107 < 3; c3_i107++) {
    c3_ddRc[c3_i107 + 6] = c3_ddb3c[c3_i107];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i108 = 0; c3_i108 < 9; c3_i108++) {
    (*c3_b_dRc)[c3_i108] = c3_dRc[c3_i108];
  }

  for (c3_i109 = 0; c3_i109 < 9; c3_i109++) {
    (*c3_b_ddRc)[c3_i109] = c3_ddRc[c3_i109];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_QRLsim(SFc3_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  real_T c3_b_inData[9];
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i110 = 0;
  for (c3_i111 = 0; c3_i111 < 3; c3_i111++) {
    for (c3_i112 = 0; c3_i112 < 3; c3_i112++) {
      c3_b_inData[c3_i112 + c3_i110] = (*(real_T (*)[9])c3_inData)[c3_i112 +
        c3_i110];
    }

    c3_i110 += 3;
  }

  c3_i113 = 0;
  for (c3_i114 = 0; c3_i114 < 3; c3_i114++) {
    for (c3_i115 = 0; c3_i115 < 3; c3_i115++) {
      c3_u[c3_i115 + c3_i113] = c3_b_inData[c3_i115 + c3_i113];
    }

    c3_i113 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance, const
  mxArray *c3_ddRc, const char_T *c3_identifier, real_T c3_y[9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ddRc), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_ddRc);
}

static void c3_b_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9])
{
  real_T c3_dv2[9];
  int32_T c3_i116;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i116 = 0; c3_i116 < 9; c3_i116++) {
    c3_y[c3_i116] = c3_dv2[c3_i116];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_ddRc;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i117;
  int32_T c3_i118;
  int32_T c3_i119;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_ddRc = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ddRc), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_ddRc);
  c3_i117 = 0;
  for (c3_i118 = 0; c3_i118 < 3; c3_i118++) {
    for (c3_i119 = 0; c3_i119 < 3; c3_i119++) {
      (*(real_T (*)[9])c3_outData)[c3_i119 + c3_i117] = c3_y[c3_i119 + c3_i117];
    }

    c3_i117 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i120;
  real_T c3_b_inData[3];
  int32_T c3_i121;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i120 = 0; c3_i120 < 3; c3_i120++) {
    c3_b_inData[c3_i120] = (*(real_T (*)[3])c3_inData)[c3_i120];
  }

  for (c3_i121 = 0; c3_i121 < 3; c3_i121++) {
    c3_u[c3_i121] = c3_b_inData[c3_i121];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i122;
  real_T c3_b_inData[3];
  int32_T c3_i123;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i122 = 0; c3_i122 < 3; c3_i122++) {
    c3_b_inData[c3_i122] = (*(real_T (*)[3])c3_inData)[c3_i122];
  }

  for (c3_i123 = 0; c3_i123 < 3; c3_i123++) {
    c3_u[c3_i123] = c3_b_inData[c3_i123];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_d_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv3[3];
  int32_T c3_i124;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i124 = 0; c3_i124 < 3; c3_i124++) {
    c3_y[c3_i124] = c3_dv3[c3_i124];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_ddb1c;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i125;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_ddb1c = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ddb1c), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_ddb1c);
  for (c3_i125 = 0; c3_i125 < 3; c3_i125++) {
    (*(real_T (*)[3])c3_outData)[c3_i125] = c3_y[c3_i125];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 64, 1),
                FALSE);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  const mxArray *c3_rhs39 = NULL;
  const mxArray *c3_lhs39 = NULL;
  const mxArray *c3_rhs40 = NULL;
  const mxArray *c3_lhs40 = NULL;
  const mxArray *c3_rhs41 = NULL;
  const mxArray *c3_lhs41 = NULL;
  const mxArray *c3_rhs42 = NULL;
  const mxArray *c3_lhs42 = NULL;
  const mxArray *c3_rhs43 = NULL;
  const mxArray *c3_lhs43 = NULL;
  const mxArray *c3_rhs44 = NULL;
  const mxArray *c3_lhs44 = NULL;
  const mxArray *c3_rhs45 = NULL;
  const mxArray *c3_lhs45 = NULL;
  const mxArray *c3_rhs46 = NULL;
  const mxArray *c3_lhs46 = NULL;
  const mxArray *c3_rhs47 = NULL;
  const mxArray *c3_lhs47 = NULL;
  const mxArray *c3_rhs48 = NULL;
  const mxArray *c3_lhs48 = NULL;
  const mxArray *c3_rhs49 = NULL;
  const mxArray *c3_lhs49 = NULL;
  const mxArray *c3_rhs50 = NULL;
  const mxArray *c3_lhs50 = NULL;
  const mxArray *c3_rhs51 = NULL;
  const mxArray *c3_lhs51 = NULL;
  const mxArray *c3_rhs52 = NULL;
  const mxArray *c3_lhs52 = NULL;
  const mxArray *c3_rhs53 = NULL;
  const mxArray *c3_lhs53 = NULL;
  const mxArray *c3_rhs54 = NULL;
  const mxArray *c3_lhs54 = NULL;
  const mxArray *c3_rhs55 = NULL;
  const mxArray *c3_lhs55 = NULL;
  const mxArray *c3_rhs56 = NULL;
  const mxArray *c3_lhs56 = NULL;
  const mxArray *c3_rhs57 = NULL;
  const mxArray *c3_lhs57 = NULL;
  const mxArray *c3_rhs58 = NULL;
  const mxArray *c3_lhs58 = NULL;
  const mxArray *c3_rhs59 = NULL;
  const mxArray *c3_lhs59 = NULL;
  const mxArray *c3_rhs60 = NULL;
  const mxArray *c3_lhs60 = NULL;
  const mxArray *c3_rhs61 = NULL;
  const mxArray *c3_lhs61 = NULL;
  const mxArray *c3_rhs62 = NULL;
  const mxArray *c3_lhs62 = NULL;
  const mxArray *c3_rhs63 = NULL;
  const mxArray *c3_lhs63 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("norm"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_xnrm2"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713872U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_refblas_xnrm2"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1299076784U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("realmin"), "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_realmin"), "name", "name",
                  8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("intmax"), "name", "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("dot"), "name", "name", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1360282354U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isequal"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnan"), "name", "name", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot"), "context",
                  "context", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_xdot"), "name", "name", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold"),
                  "context", "context", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("length"), "name", "name", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1303146206U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c3_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1299076772U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c3_rhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c3_rhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c3_rhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c3_rhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c3_rhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c3_rhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c3_rhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c3_rhs47, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs47, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mtimes"), "name", "name", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c3_rhs48, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs48, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c3_rhs49, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs49, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mpower"), "name", "name", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c3_rhs50, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs50, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c3_rhs51, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs51, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("ismatrix"), "name", "name", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c3_rhs52, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs52, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("power"), "name", "name", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c3_rhs53, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs53, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c3_rhs54, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs54, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c3_rhs55, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs55, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1358186140U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c3_rhs56, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs56, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("floor"), "name", "name", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c3_rhs57, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs57, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c3_rhs58, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs58, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c3_rhs59, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs59, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c3_rhs60, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs60, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cross"), "name", "name", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c3_rhs61, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs61, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mtimes"), "name", "name", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c3_rhs62, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs62, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mtimes"), "name", "name", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c3_rhs63, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs63, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
  sf_mex_destroy(&c3_rhs39);
  sf_mex_destroy(&c3_lhs39);
  sf_mex_destroy(&c3_rhs40);
  sf_mex_destroy(&c3_lhs40);
  sf_mex_destroy(&c3_rhs41);
  sf_mex_destroy(&c3_lhs41);
  sf_mex_destroy(&c3_rhs42);
  sf_mex_destroy(&c3_lhs42);
  sf_mex_destroy(&c3_rhs43);
  sf_mex_destroy(&c3_lhs43);
  sf_mex_destroy(&c3_rhs44);
  sf_mex_destroy(&c3_lhs44);
  sf_mex_destroy(&c3_rhs45);
  sf_mex_destroy(&c3_lhs45);
  sf_mex_destroy(&c3_rhs46);
  sf_mex_destroy(&c3_lhs46);
  sf_mex_destroy(&c3_rhs47);
  sf_mex_destroy(&c3_lhs47);
  sf_mex_destroy(&c3_rhs48);
  sf_mex_destroy(&c3_lhs48);
  sf_mex_destroy(&c3_rhs49);
  sf_mex_destroy(&c3_lhs49);
  sf_mex_destroy(&c3_rhs50);
  sf_mex_destroy(&c3_lhs50);
  sf_mex_destroy(&c3_rhs51);
  sf_mex_destroy(&c3_lhs51);
  sf_mex_destroy(&c3_rhs52);
  sf_mex_destroy(&c3_lhs52);
  sf_mex_destroy(&c3_rhs53);
  sf_mex_destroy(&c3_lhs53);
  sf_mex_destroy(&c3_rhs54);
  sf_mex_destroy(&c3_lhs54);
  sf_mex_destroy(&c3_rhs55);
  sf_mex_destroy(&c3_lhs55);
  sf_mex_destroy(&c3_rhs56);
  sf_mex_destroy(&c3_lhs56);
  sf_mex_destroy(&c3_rhs57);
  sf_mex_destroy(&c3_lhs57);
  sf_mex_destroy(&c3_rhs58);
  sf_mex_destroy(&c3_lhs58);
  sf_mex_destroy(&c3_rhs59);
  sf_mex_destroy(&c3_lhs59);
  sf_mex_destroy(&c3_rhs60);
  sf_mex_destroy(&c3_lhs60);
  sf_mex_destroy(&c3_rhs61);
  sf_mex_destroy(&c3_lhs61);
  sf_mex_destroy(&c3_rhs62);
  sf_mex_destroy(&c3_lhs62);
  sf_mex_destroy(&c3_rhs63);
  sf_mex_destroy(&c3_lhs63);
}

static const mxArray *c3_emlrt_marshallOut(char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), FALSE);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c3_y;
}

static real_T c3_norm(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_x[3])
{
  real_T c3_y;
  real_T c3_scale;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_absxk;
  real_T c3_t;
  c3_y = 0.0;
  c3_scale = 2.2250738585072014E-308;
  for (c3_k = 1; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_b_x = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 3, 1, 0) - 1];
    c3_c_x = c3_b_x;
    c3_absxk = muDoubleScalarAbs(c3_c_x);
    if (c3_absxk > c3_scale) {
      c3_t = c3_scale / c3_absxk;
      c3_y = 1.0 + c3_y * c3_t * c3_t;
      c3_scale = c3_absxk;
    } else {
      c3_t = c3_absxk / c3_scale;
      c3_y += c3_t * c3_t;
    }
  }

  return c3_scale * muDoubleScalarSqrt(c3_y);
}

static real_T c3_dot(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3])
{
  real_T c3_c;
  int32_T c3_k;
  int32_T c3_b_k;
  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  c3_c = 0.0;
  for (c3_k = 1; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_c += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 3, 1, 0) - 1] * c3_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 1, 0) - 1];
  }

  return c3_c;
}

static void c3_eml_scalar_eg(SFc3_QRLsimInstanceStruct *chartInstance)
{
}

static real_T c3_mpower(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_ar;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_b_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_b_eml_scalar_eg(chartInstance);
  c3_ar = c3_d_a;
  return muDoubleScalarPower(c3_ar, 3.0);
}

static void c3_b_eml_scalar_eg(SFc3_QRLsimInstanceStruct *chartInstance)
{
}

static void c3_cross(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3], real_T c3_c[3])
{
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_y;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_b_y;
  real_T c3_c1;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_c_y;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_d_y;
  real_T c3_c2;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_e_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_f_y;
  real_T c3_c3;
  c3_b_a = c3_a[1];
  c3_b_b = c3_b[2];
  c3_y = c3_b_a * c3_b_b;
  c3_c_a = c3_a[2];
  c3_c_b = c3_b[1];
  c3_b_y = c3_c_a * c3_c_b;
  c3_c1 = c3_y - c3_b_y;
  c3_d_a = c3_a[2];
  c3_d_b = c3_b[0];
  c3_c_y = c3_d_a * c3_d_b;
  c3_e_a = c3_a[0];
  c3_e_b = c3_b[2];
  c3_d_y = c3_e_a * c3_e_b;
  c3_c2 = c3_c_y - c3_d_y;
  c3_f_a = c3_a[0];
  c3_f_b = c3_b[1];
  c3_e_y = c3_f_a * c3_f_b;
  c3_g_a = c3_a[1];
  c3_g_b = c3_b[0];
  c3_f_y = c3_g_a * c3_g_b;
  c3_c3 = c3_e_y - c3_f_y;
  c3_c[0] = c3_c1;
  c3_c[1] = c3_c2;
  c3_c[2] = c3_c3;
}

static real_T c3_b_mpower(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_e_a;
  real_T c3_b;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_b_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_b_eml_scalar_eg(chartInstance);
  c3_e_a = c3_d_a;
  c3_b = c3_d_a;
  return c3_e_a * c3_b;
}

static real_T c3_c_mpower(SFc3_QRLsimInstanceStruct *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_ar;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_b_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_b_eml_scalar_eg(chartInstance);
  c3_ar = c3_d_a;
  return muDoubleScalarPower(c3_ar, 5.0);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i126;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i126, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i126;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_QRLsim, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_QRLsim), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_QRLsim);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_QRLsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_QRLsimInstanceStruct *chartInstance)
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

void sf_c3_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1215270746U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3589914014U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1985289818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1991024754U);
}

mxArray *sf_c3_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tcOfltySusmLHSqmXxi1B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"dRc\",},{M[1],M[14],T\"ddRc\",},{M[8],M[0],T\"is_active_c3_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc3_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           3,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"C");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dRc");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dC");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ddC");
          _SFD_SET_DATA_PROPS(4,1,1,0,"b3c");
          _SFD_SET_DATA_PROPS(5,1,1,0,"F");
          _SFD_SET_DATA_PROPS(6,1,1,0,"dF");
          _SFD_SET_DATA_PROPS(7,1,1,0,"ddF");
          _SFD_SET_DATA_PROPS(8,2,0,1,"ddRc");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,553);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          real_T (*c3_C)[3];
          real_T (*c3_dRc)[9];
          real_T (*c3_dC)[3];
          real_T (*c3_ddC)[3];
          real_T (*c3_b3c)[3];
          real_T (*c3_F)[3];
          real_T (*c3_dF)[3];
          real_T (*c3_ddF)[3];
          real_T (*c3_ddRc)[9];
          c3_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c3_ddF = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
          c3_dF = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c3_F = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c3_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c3_ddC = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c3_dC = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c3_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_C = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_C);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_dRc);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_dC);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_ddC);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_b3c);
          _SFD_SET_DATA_VALUE_PTR(5U, *c3_F);
          _SFD_SET_DATA_VALUE_PTR(6U, *c3_dF);
          _SFD_SET_DATA_VALUE_PTR(7U, *c3_ddF);
          _SFD_SET_DATA_VALUE_PTR(8U, *c3_ddRc);
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
  return "R5FpYRCZlh573fOKKOjGNH";
}

static void sf_opaque_initialize_c3_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_QRLsim(void *chartInstanceVar)
{
  enable_c3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_QRLsim(void *chartInstanceVar)
{
  disable_c3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_QRLsim(void *chartInstanceVar)
{
  sf_c3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_QRLsim((SFc3_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c3_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_QRLsim((SFc3_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_QRLsim(S);
}

static void sf_opaque_set_sim_state_c3_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_QRLsim(S, st);
}

static void sf_opaque_terminate_c3_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_QRLsim((SFc3_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_QRLsim((SFc3_QRLsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2739609294U));
  ssSetChecksum1(S,(2699854462U));
  ssSetChecksum2(S,(1815726006U));
  ssSetChecksum3(S,(2560850093U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_QRLsim(SimStruct *S)
{
  SFc3_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc3_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_QRLsim;
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

void c3_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
