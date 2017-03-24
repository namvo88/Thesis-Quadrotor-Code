/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c13_QRsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
<<<<<<< HEAD
static const char * c13_debug_family_names[7] = { "phi", "theta", "psi",
  "nargin", "nargout", "u", "R" };
=======
static const char * c13_debug_family_names[10] = { "phi", "theta", "psi", "Rz",
  "Ry", "Rx", "u", "nargin", "nargout", "Rzyx" };
>>>>>>> developErrorAngularVelocity

/* Function Declarations */
static void initialize_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void initialize_params_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void enable_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void disable_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_QRsim(SFc13_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c13_QRsim(SFc13_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_st);
static void finalize_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void sf_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void c13_chartstep_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void initSimStructsc13_QRsim(SFc13_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c13_R, const char_T *c13_identifier, real_T c13_y[9]);
=======
  mxArray *c13_Rzyx, const char_T *c13_identifier, real_T c13_y[9]);
>>>>>>> developErrorAngularVelocity
static void c13_b_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[9]);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_info_helper(const mxArray **c13_info);
static const mxArray *c13_emlrt_marshallOut(char * c13_u);
static const mxArray *c13_b_emlrt_marshallOut(uint32_T c13_u);
<<<<<<< HEAD
=======
static real_T c13_cosd(SFc13_QRsimInstanceStruct *chartInstance, real_T c13_x);
static boolean_T c13_isfinite(SFc13_QRsimInstanceStruct *chartInstance, real_T
  c13_x);
static real_T c13_sind(SFc13_QRsimInstanceStruct *chartInstance, real_T c13_x);
static void c13_eml_scalar_eg(SFc13_QRsimInstanceStruct *chartInstance);
>>>>>>> developErrorAngularVelocity
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_d_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_e_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_b_is_active_c13_QRsim, const char_T *c13_identifier);
static uint8_T c13_f_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
<<<<<<< HEAD
=======
static void c13_b_cosd(SFc13_QRsimInstanceStruct *chartInstance, real_T *c13_x);
static void c13_b_sind(SFc13_QRsimInstanceStruct *chartInstance, real_T *c13_x);
>>>>>>> developErrorAngularVelocity
static void init_dsm_address_info(SFc13_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_is_active_c13_QRsim = 0U;
}

static void initialize_params_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_QRsim(SFc13_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c13_QRsim(SFc13_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  int32_T c13_i0;
  real_T c13_u[9];
  const mxArray *c13_b_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
<<<<<<< HEAD
  real_T (*c13_R)[9];
  c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
=======
  real_T (*c13_Rzyx)[9];
  c13_Rzyx = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
>>>>>>> developErrorAngularVelocity
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2), FALSE);
  for (c13_i0 = 0; c13_i0 < 9; c13_i0++) {
<<<<<<< HEAD
    c13_u[c13_i0] = (*c13_R)[c13_i0];
=======
    c13_u[c13_i0] = (*c13_Rzyx)[c13_i0];
>>>>>>> developErrorAngularVelocity
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_hoistedGlobal = chartInstance->c13_is_active_c13_QRsim;
  c13_b_u = c13_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T c13_dv0[9];
  int32_T c13_i1;
<<<<<<< HEAD
  real_T (*c13_R)[9];
  c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)), "R",
                       c13_dv0);
  for (c13_i1 = 0; c13_i1 < 9; c13_i1++) {
    (*c13_R)[c13_i1] = c13_dv0[c13_i1];
=======
  real_T (*c13_Rzyx)[9];
  c13_Rzyx = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)),
                       "Rzyx", c13_dv0);
  for (c13_i1 = 0; c13_i1 < 9; c13_i1++) {
    (*c13_Rzyx)[c13_i1] = c13_dv0[c13_i1];
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c13_is_active_c13_QRsim = c13_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 1)), "is_active_c13_QRsim");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_QRsim(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
  int32_T c13_i2;
  int32_T c13_i3;
<<<<<<< HEAD
  real_T (*c13_R)[9];
  real_T (*c13_u)[3];
  c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c13_sfEvent);
=======
  real_T (*c13_Rzyx)[9];
  real_T (*c13_u)[3];
  c13_Rzyx = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
>>>>>>> developErrorAngularVelocity
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    _SFD_DATA_RANGE_CHECK((*c13_u)[c13_i2], 0U);
  }

  for (c13_i3 = 0; c13_i3 < 9; c13_i3++) {
<<<<<<< HEAD
    _SFD_DATA_RANGE_CHECK((*c13_R)[c13_i3], 1U);
=======
    _SFD_DATA_RANGE_CHECK((*c13_Rzyx)[c13_i3], 1U);
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c13_sfEvent = CALL_EVENT;
  c13_chartstep_c13_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c13_chartstep_c13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
  int32_T c13_i4;
  real_T c13_u[3];
<<<<<<< HEAD
  uint32_T c13_debug_family_var_map[7];
  real_T c13_phi;
  real_T c13_theta;
  real_T c13_psi;
  real_T c13_nargin = 1.0;
  real_T c13_nargout = 1.0;
  real_T c13_R[9];
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_a;
  real_T c13_b;
  real_T c13_y;
  real_T c13_e_x;
  real_T c13_f_x;
  real_T c13_g_x;
  real_T c13_h_x;
  real_T c13_b_a;
  real_T c13_b_b;
  real_T c13_b_y;
  real_T c13_i_x;
  real_T c13_j_x;
  real_T c13_c_a;
  real_T c13_c_b;
  real_T c13_c_y;
  real_T c13_k_x;
  real_T c13_l_x;
  real_T c13_m_x;
  real_T c13_n_x;
  real_T c13_d_a;
  real_T c13_d_b;
  real_T c13_d_y;
  real_T c13_o_x;
  real_T c13_p_x;
  real_T c13_q_x;
  real_T c13_r_x;
  real_T c13_e_a;
  real_T c13_e_b;
  real_T c13_e_y;
  real_T c13_s_x;
  real_T c13_t_x;
  real_T c13_u_x;
  real_T c13_v_x;
  real_T c13_f_a;
  real_T c13_f_b;
  real_T c13_f_y;
  real_T c13_w_x;
  real_T c13_x_x;
  real_T c13_g_a;
  real_T c13_g_b;
  real_T c13_g_y;
  real_T c13_y_x;
  real_T c13_ab_x;
  real_T c13_bb_x;
  real_T c13_cb_x;
  real_T c13_h_a;
  real_T c13_h_b;
  real_T c13_h_y;
  real_T c13_db_x;
  real_T c13_eb_x;
  real_T c13_fb_x;
  real_T c13_gb_x;
  real_T c13_i_a;
  real_T c13_i_b;
  real_T c13_i_y;
  real_T c13_hb_x;
  real_T c13_ib_x;
  real_T c13_j_a;
  real_T c13_j_b;
  real_T c13_j_y;
  real_T c13_jb_x;
  real_T c13_kb_x;
  real_T c13_lb_x;
  real_T c13_mb_x;
  real_T c13_k_a;
  real_T c13_k_b;
  real_T c13_k_y;
  real_T c13_nb_x;
  real_T c13_ob_x;
  real_T c13_pb_x;
  real_T c13_qb_x;
  real_T c13_l_a;
  real_T c13_l_b;
  real_T c13_l_y;
  real_T c13_rb_x;
  real_T c13_sb_x;
  real_T c13_tb_x;
  real_T c13_ub_x;
  real_T c13_m_a;
  real_T c13_m_b;
  real_T c13_m_y;
  real_T c13_vb_x;
  real_T c13_wb_x;
  real_T c13_n_a;
  real_T c13_n_b;
  real_T c13_n_y;
  real_T c13_xb_x;
  real_T c13_yb_x;
  real_T c13_ac_x;
  real_T c13_bc_x;
  real_T c13_o_a;
  real_T c13_o_b;
  real_T c13_o_y;
  real_T c13_cc_x;
  real_T c13_dc_x;
  real_T c13_ec_x;
  real_T c13_fc_x;
  real_T c13_gc_x;
  real_T c13_hc_x;
  real_T c13_p_a;
  real_T c13_p_b;
  real_T c13_p_y;
  int32_T c13_i5;
  real_T (*c13_b_R)[9];
  real_T (*c13_b_u)[3];
  c13_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c13_sfEvent);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    c13_u[c13_i4] = (*c13_b_u)[c13_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c13_debug_family_names,
=======
  uint32_T c13_debug_family_var_map[10];
  real_T c13_phi;
  real_T c13_theta;
  real_T c13_psi;
  real_T c13_Rz[9];
  real_T c13_Ry[9];
  real_T c13_Rx[9];
  real_T c13_b_u;
  real_T c13_nargin = 1.0;
  real_T c13_nargout = 1.0;
  real_T c13_Rzyx[9];
  real_T c13_d0;
  real_T c13_d1;
  real_T c13_d2;
  real_T c13_d3;
  int32_T c13_i5;
  int32_T c13_i6;
  static real_T c13_dv1[3] = { 0.0, 0.0, 1.0 };

  real_T c13_d4;
  real_T c13_d5;
  real_T c13_d6;
  real_T c13_d7;
  int32_T c13_i7;
  int32_T c13_i8;
  static real_T c13_dv2[3] = { 0.0, 1.0, 0.0 };

  real_T c13_d8;
  real_T c13_d9;
  real_T c13_d10;
  real_T c13_d11;
  int32_T c13_i9;
  int32_T c13_i10;
  static real_T c13_dv3[3] = { 1.0, 0.0, 0.0 };

  int32_T c13_i11;
  real_T c13_a[9];
  int32_T c13_i12;
  real_T c13_b[9];
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  real_T c13_y[9];
  int32_T c13_i16;
  int32_T c13_i17;
  int32_T c13_i18;
  int32_T c13_i19;
  int32_T c13_i20;
  int32_T c13_i21;
  int32_T c13_i22;
  int32_T c13_i23;
  int32_T c13_i24;
  int32_T c13_i25;
  int32_T c13_i26;
  int32_T c13_i27;
  int32_T c13_i28;
  int32_T c13_i29;
  int32_T c13_i30;
  real_T (*c13_b_Rzyx)[9];
  real_T (*c13_c_u)[3];
  c13_b_Rzyx = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_c_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    c13_u[c13_i4] = (*c13_c_u)[c13_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 11U, c13_debug_family_names,
>>>>>>> developErrorAngularVelocity
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_phi, 0U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_theta, 1U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_psi, 2U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
<<<<<<< HEAD
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 3U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 4U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_u, 5U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_R, 6U, c13_sf_marshallOut,
=======
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Rz, 3U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Ry, 4U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Rx, 5U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_u, MAX_uint32_T,
    c13_c_sf_marshallOut, c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 7U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 8U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_u, 6U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Rzyx, 9U, c13_sf_marshallOut,
>>>>>>> developErrorAngularVelocity
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
  c13_phi = c13_u[0];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
  c13_theta = c13_u[1];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 9);
  c13_psi = c13_u[2];
<<<<<<< HEAD
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 11);
  c13_x = c13_psi;
  c13_b_x = c13_x;
  c13_b_x = muDoubleScalarCos(c13_b_x);
  c13_c_x = c13_theta;
  c13_d_x = c13_c_x;
  c13_d_x = muDoubleScalarCos(c13_d_x);
  c13_a = c13_b_x;
  c13_b = c13_d_x;
  c13_y = c13_a * c13_b;
  c13_e_x = c13_phi;
  c13_f_x = c13_e_x;
  c13_f_x = muDoubleScalarSin(c13_f_x);
  c13_g_x = c13_psi;
  c13_h_x = c13_g_x;
  c13_h_x = muDoubleScalarSin(c13_h_x);
  c13_b_a = c13_f_x;
  c13_b_b = c13_h_x;
  c13_b_y = c13_b_a * c13_b_b;
  c13_i_x = c13_theta;
  c13_j_x = c13_i_x;
  c13_j_x = muDoubleScalarSin(c13_j_x);
  c13_c_a = c13_b_y;
  c13_c_b = c13_j_x;
  c13_c_y = c13_c_a * c13_c_b;
  c13_k_x = c13_phi;
  c13_l_x = c13_k_x;
  c13_l_x = muDoubleScalarCos(c13_l_x);
  c13_m_x = c13_psi;
  c13_n_x = c13_m_x;
  c13_n_x = muDoubleScalarSin(c13_n_x);
  c13_d_a = -c13_l_x;
  c13_d_b = c13_n_x;
  c13_d_y = c13_d_a * c13_d_b;
  c13_o_x = c13_psi;
  c13_p_x = c13_o_x;
  c13_p_x = muDoubleScalarCos(c13_p_x);
  c13_q_x = c13_theta;
  c13_r_x = c13_q_x;
  c13_r_x = muDoubleScalarSin(c13_r_x);
  c13_e_a = c13_p_x;
  c13_e_b = c13_r_x;
  c13_e_y = c13_e_a * c13_e_b;
  c13_s_x = c13_theta;
  c13_t_x = c13_s_x;
  c13_t_x = muDoubleScalarCos(c13_t_x);
  c13_u_x = c13_phi;
  c13_v_x = c13_u_x;
  c13_v_x = muDoubleScalarSin(c13_v_x);
  c13_f_a = c13_t_x;
  c13_f_b = c13_v_x;
  c13_f_y = c13_f_a * c13_f_b;
  c13_w_x = c13_psi;
  c13_x_x = c13_w_x;
  c13_x_x = muDoubleScalarSin(c13_x_x);
  c13_g_a = c13_f_y;
  c13_g_b = c13_x_x;
  c13_g_y = c13_g_a * c13_g_b;
  c13_y_x = c13_theta;
  c13_ab_x = c13_y_x;
  c13_ab_x = muDoubleScalarCos(c13_ab_x);
  c13_bb_x = c13_psi;
  c13_cb_x = c13_bb_x;
  c13_cb_x = muDoubleScalarSin(c13_cb_x);
  c13_h_a = c13_ab_x;
  c13_h_b = c13_cb_x;
  c13_h_y = c13_h_a * c13_h_b;
  c13_db_x = c13_psi;
  c13_eb_x = c13_db_x;
  c13_eb_x = muDoubleScalarCos(c13_eb_x);
  c13_fb_x = c13_phi;
  c13_gb_x = c13_fb_x;
  c13_gb_x = muDoubleScalarSin(c13_gb_x);
  c13_i_a = c13_eb_x;
  c13_i_b = c13_gb_x;
  c13_i_y = c13_i_a * c13_i_b;
  c13_hb_x = c13_theta;
  c13_ib_x = c13_hb_x;
  c13_ib_x = muDoubleScalarSin(c13_ib_x);
  c13_j_a = c13_i_y;
  c13_j_b = c13_ib_x;
  c13_j_y = c13_j_a * c13_j_b;
  c13_jb_x = c13_phi;
  c13_kb_x = c13_jb_x;
  c13_kb_x = muDoubleScalarCos(c13_kb_x);
  c13_lb_x = c13_psi;
  c13_mb_x = c13_lb_x;
  c13_mb_x = muDoubleScalarCos(c13_mb_x);
  c13_k_a = c13_kb_x;
  c13_k_b = c13_mb_x;
  c13_k_y = c13_k_a * c13_k_b;
  c13_nb_x = c13_psi;
  c13_ob_x = c13_nb_x;
  c13_ob_x = muDoubleScalarSin(c13_ob_x);
  c13_pb_x = c13_theta;
  c13_qb_x = c13_pb_x;
  c13_qb_x = muDoubleScalarSin(c13_qb_x);
  c13_l_a = c13_ob_x;
  c13_l_b = c13_qb_x;
  c13_l_y = c13_l_a * c13_l_b;
  c13_rb_x = c13_psi;
  c13_sb_x = c13_rb_x;
  c13_sb_x = muDoubleScalarCos(c13_sb_x);
  c13_tb_x = c13_theta;
  c13_ub_x = c13_tb_x;
  c13_ub_x = muDoubleScalarCos(c13_ub_x);
  c13_m_a = c13_sb_x;
  c13_m_b = c13_ub_x;
  c13_m_y = c13_m_a * c13_m_b;
  c13_vb_x = c13_phi;
  c13_wb_x = c13_vb_x;
  c13_wb_x = muDoubleScalarSin(c13_wb_x);
  c13_n_a = c13_m_y;
  c13_n_b = c13_wb_x;
  c13_n_y = c13_n_a * c13_n_b;
  c13_xb_x = c13_phi;
  c13_yb_x = c13_xb_x;
  c13_yb_x = muDoubleScalarCos(c13_yb_x);
  c13_ac_x = c13_theta;
  c13_bc_x = c13_ac_x;
  c13_bc_x = muDoubleScalarSin(c13_bc_x);
  c13_o_a = -c13_yb_x;
  c13_o_b = c13_bc_x;
  c13_o_y = c13_o_a * c13_o_b;
  c13_cc_x = c13_phi;
  c13_dc_x = c13_cc_x;
  c13_dc_x = muDoubleScalarSin(c13_dc_x);
  c13_ec_x = c13_phi;
  c13_fc_x = c13_ec_x;
  c13_fc_x = muDoubleScalarCos(c13_fc_x);
  c13_gc_x = c13_theta;
  c13_hc_x = c13_gc_x;
  c13_hc_x = muDoubleScalarCos(c13_hc_x);
  c13_p_a = c13_fc_x;
  c13_p_b = c13_hc_x;
  c13_p_y = c13_p_a * c13_p_b;
  c13_R[0] = c13_y - c13_c_y;
  c13_R[3] = c13_d_y;
  c13_R[6] = c13_e_y + c13_g_y;
  c13_R[1] = c13_h_y + c13_j_y;
  c13_R[4] = c13_k_y;
  c13_R[7] = c13_l_y - c13_n_y;
  c13_R[2] = c13_o_y;
  c13_R[5] = c13_dc_x;
  c13_R[8] = c13_p_y;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c13_i5 = 0; c13_i5 < 9; c13_i5++) {
    (*c13_b_R)[c13_i5] = c13_R[c13_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c13_sfEvent);
=======
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 17);
  c13_b_u = c13_psi;
  _SFD_SYMBOL_SWITCH(6U, 6U);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 18);
  c13_d0 = c13_b_u;
  c13_b_cosd(chartInstance, &c13_d0);
  c13_d1 = c13_b_u;
  c13_b_sind(chartInstance, &c13_d1);
  c13_d2 = c13_b_u;
  c13_b_sind(chartInstance, &c13_d2);
  c13_d3 = c13_b_u;
  c13_b_cosd(chartInstance, &c13_d3);
  c13_Rz[0] = c13_d0;
  c13_Rz[3] = c13_d1;
  c13_Rz[6] = 0.0;
  c13_Rz[1] = -c13_d2;
  c13_Rz[4] = c13_d3;
  c13_Rz[7] = 0.0;
  c13_i5 = 0;
  for (c13_i6 = 0; c13_i6 < 3; c13_i6++) {
    c13_Rz[c13_i5 + 2] = c13_dv1[c13_i6];
    c13_i5 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
  c13_b_u = c13_phi;
  _SFD_SYMBOL_SWITCH(6U, 6U);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 22);
  c13_d4 = c13_b_u;
  c13_b_cosd(chartInstance, &c13_d4);
  c13_d5 = c13_b_u;
  c13_b_sind(chartInstance, &c13_d5);
  c13_d6 = c13_b_u;
  c13_b_sind(chartInstance, &c13_d6);
  c13_d7 = c13_b_u;
  c13_b_cosd(chartInstance, &c13_d7);
  c13_Ry[0] = c13_d4;
  c13_Ry[3] = 0.0;
  c13_Ry[6] = -c13_d5;
  c13_i7 = 0;
  for (c13_i8 = 0; c13_i8 < 3; c13_i8++) {
    c13_Ry[c13_i7 + 1] = c13_dv2[c13_i8];
    c13_i7 += 3;
  }

  c13_Ry[2] = c13_d6;
  c13_Ry[5] = 0.0;
  c13_Ry[8] = c13_d7;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 25);
  c13_b_u = c13_theta;
  _SFD_SYMBOL_SWITCH(6U, 6U);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 26);
  c13_d8 = c13_b_u;
  c13_b_cosd(chartInstance, &c13_d8);
  c13_d9 = c13_b_u;
  c13_b_sind(chartInstance, &c13_d9);
  c13_d10 = c13_b_u;
  c13_b_sind(chartInstance, &c13_d10);
  c13_d11 = c13_b_u;
  c13_b_cosd(chartInstance, &c13_d11);
  c13_i9 = 0;
  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    c13_Rx[c13_i9] = c13_dv3[c13_i10];
    c13_i9 += 3;
  }

  c13_Rx[1] = 0.0;
  c13_Rx[4] = c13_d8;
  c13_Rx[7] = c13_d9;
  c13_Rx[2] = 0.0;
  c13_Rx[5] = -c13_d10;
  c13_Rx[8] = c13_d11;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 30);
  for (c13_i11 = 0; c13_i11 < 9; c13_i11++) {
    c13_a[c13_i11] = c13_Rz[c13_i11];
  }

  for (c13_i12 = 0; c13_i12 < 9; c13_i12++) {
    c13_b[c13_i12] = c13_Ry[c13_i12];
  }

  c13_eml_scalar_eg(chartInstance);
  c13_eml_scalar_eg(chartInstance);
  for (c13_i13 = 0; c13_i13 < 3; c13_i13++) {
    c13_i14 = 0;
    for (c13_i15 = 0; c13_i15 < 3; c13_i15++) {
      c13_y[c13_i14 + c13_i13] = 0.0;
      c13_i16 = 0;
      for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
        c13_y[c13_i14 + c13_i13] += c13_a[c13_i16 + c13_i13] * c13_b[c13_i17 +
          c13_i14];
        c13_i16 += 3;
      }

      c13_i14 += 3;
    }
  }

  for (c13_i18 = 0; c13_i18 < 9; c13_i18++) {
    c13_b[c13_i18] = c13_Rx[c13_i18];
  }

  c13_eml_scalar_eg(chartInstance);
  c13_eml_scalar_eg(chartInstance);
  for (c13_i19 = 0; c13_i19 < 9; c13_i19++) {
    c13_Rzyx[c13_i19] = 0.0;
  }

  for (c13_i20 = 0; c13_i20 < 9; c13_i20++) {
    c13_Rzyx[c13_i20] = 0.0;
  }

  for (c13_i21 = 0; c13_i21 < 9; c13_i21++) {
    c13_a[c13_i21] = c13_Rzyx[c13_i21];
  }

  for (c13_i22 = 0; c13_i22 < 9; c13_i22++) {
    c13_Rzyx[c13_i22] = c13_a[c13_i22];
  }

  for (c13_i23 = 0; c13_i23 < 9; c13_i23++) {
    c13_a[c13_i23] = c13_Rzyx[c13_i23];
  }

  for (c13_i24 = 0; c13_i24 < 9; c13_i24++) {
    c13_Rzyx[c13_i24] = c13_a[c13_i24];
  }

  for (c13_i25 = 0; c13_i25 < 3; c13_i25++) {
    c13_i26 = 0;
    for (c13_i27 = 0; c13_i27 < 3; c13_i27++) {
      c13_Rzyx[c13_i26 + c13_i25] = 0.0;
      c13_i28 = 0;
      for (c13_i29 = 0; c13_i29 < 3; c13_i29++) {
        c13_Rzyx[c13_i26 + c13_i25] += c13_y[c13_i28 + c13_i25] * c13_b[c13_i29
          + c13_i26];
        c13_i28 += 3;
      }

      c13_i26 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  for (c13_i30 = 0; c13_i30 < 9; c13_i30++) {
    (*c13_b_Rzyx)[c13_i30] = c13_Rzyx[c13_i30];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
>>>>>>> developErrorAngularVelocity
}

static void initSimStructsc13_QRsim(SFc13_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c13_i6;
  int32_T c13_i7;
  int32_T c13_i8;
  real_T c13_b_inData[9];
  int32_T c13_i9;
  int32_T c13_i10;
  int32_T c13_i11;
=======
  int32_T c13_i31;
  int32_T c13_i32;
  int32_T c13_i33;
  real_T c13_b_inData[9];
  int32_T c13_i34;
  int32_T c13_i35;
  int32_T c13_i36;
>>>>>>> developErrorAngularVelocity
  real_T c13_u[9];
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
<<<<<<< HEAD
  c13_i6 = 0;
  for (c13_i7 = 0; c13_i7 < 3; c13_i7++) {
    for (c13_i8 = 0; c13_i8 < 3; c13_i8++) {
      c13_b_inData[c13_i8 + c13_i6] = (*(real_T (*)[9])c13_inData)[c13_i8 +
        c13_i6];
    }

    c13_i6 += 3;
  }

  c13_i9 = 0;
  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    for (c13_i11 = 0; c13_i11 < 3; c13_i11++) {
      c13_u[c13_i11 + c13_i9] = c13_b_inData[c13_i11 + c13_i9];
    }

    c13_i9 += 3;
=======
  c13_i31 = 0;
  for (c13_i32 = 0; c13_i32 < 3; c13_i32++) {
    for (c13_i33 = 0; c13_i33 < 3; c13_i33++) {
      c13_b_inData[c13_i33 + c13_i31] = (*(real_T (*)[9])c13_inData)[c13_i33 +
        c13_i31];
    }

    c13_i31 += 3;
  }

  c13_i34 = 0;
  for (c13_i35 = 0; c13_i35 < 3; c13_i35++) {
    for (c13_i36 = 0; c13_i36 < 3; c13_i36++) {
      c13_u[c13_i36 + c13_i34] = c13_b_inData[c13_i36 + c13_i34];
    }

    c13_i34 += 3;
>>>>>>> developErrorAngularVelocity
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c13_R, const char_T *c13_identifier, real_T c13_y[9])
=======
  mxArray *c13_Rzyx, const char_T *c13_identifier, real_T c13_y[9])
>>>>>>> developErrorAngularVelocity
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
<<<<<<< HEAD
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_R), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_R);
=======
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_Rzyx), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_Rzyx);
>>>>>>> developErrorAngularVelocity
}

static void c13_b_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[9])
{
<<<<<<< HEAD
  real_T c13_dv1[9];
  int32_T c13_i12;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c13_i12 = 0; c13_i12 < 9; c13_i12++) {
    c13_y[c13_i12] = c13_dv1[c13_i12];
=======
  real_T c13_dv4[9];
  int32_T c13_i37;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c13_i37 = 0; c13_i37 < 9; c13_i37++) {
    c13_y[c13_i37] = c13_dv4[c13_i37];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
<<<<<<< HEAD
  const mxArray *c13_R;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[9];
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_R = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_R), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_R);
  c13_i13 = 0;
  for (c13_i14 = 0; c13_i14 < 3; c13_i14++) {
    for (c13_i15 = 0; c13_i15 < 3; c13_i15++) {
      (*(real_T (*)[9])c13_outData)[c13_i15 + c13_i13] = c13_y[c13_i15 + c13_i13];
    }

    c13_i13 += 3;
=======
  const mxArray *c13_Rzyx;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[9];
  int32_T c13_i38;
  int32_T c13_i39;
  int32_T c13_i40;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_Rzyx = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_Rzyx), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_Rzyx);
  c13_i38 = 0;
  for (c13_i39 = 0; c13_i39 < 3; c13_i39++) {
    for (c13_i40 = 0; c13_i40 < 3; c13_i40++) {
      (*(real_T (*)[9])c13_outData)[c13_i40 + c13_i38] = c13_y[c13_i40 + c13_i38];
    }

    c13_i38 += 3;
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c13_i16;
  real_T c13_b_inData[3];
  int32_T c13_i17;
=======
  int32_T c13_i41;
  real_T c13_b_inData[3];
  int32_T c13_i42;
>>>>>>> developErrorAngularVelocity
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
<<<<<<< HEAD
  for (c13_i16 = 0; c13_i16 < 3; c13_i16++) {
    c13_b_inData[c13_i16] = (*(real_T (*)[3])c13_inData)[c13_i16];
  }

  for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
    c13_u[c13_i17] = c13_b_inData[c13_i17];
=======
  for (c13_i41 = 0; c13_i41 < 3; c13_i41++) {
    c13_b_inData[c13_i41] = (*(real_T (*)[3])c13_inData)[c13_i41];
  }

  for (c13_i42 = 0; c13_i42 < 3; c13_i42++) {
    c13_u[c13_i42] = c13_b_inData[c13_i42];
>>>>>>> developErrorAngularVelocity
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
<<<<<<< HEAD
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
=======
  real_T c13_d12;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d12, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d12;
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
<<<<<<< HEAD
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
=======
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 36, 1),
>>>>>>> developErrorAngularVelocity
                FALSE);
  c13_info_helper(&c13_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs0 = NULL;
  const mxArray *c13_lhs0 = NULL;
  const mxArray *c13_rhs1 = NULL;
  const mxArray *c13_lhs1 = NULL;
  const mxArray *c13_rhs2 = NULL;
  const mxArray *c13_lhs2 = NULL;
  const mxArray *c13_rhs3 = NULL;
  const mxArray *c13_lhs3 = NULL;
  const mxArray *c13_rhs4 = NULL;
  const mxArray *c13_lhs4 = NULL;
  const mxArray *c13_rhs5 = NULL;
  const mxArray *c13_lhs5 = NULL;
<<<<<<< HEAD
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
=======
  const mxArray *c13_rhs6 = NULL;
  const mxArray *c13_lhs6 = NULL;
  const mxArray *c13_rhs7 = NULL;
  const mxArray *c13_lhs7 = NULL;
  const mxArray *c13_rhs8 = NULL;
  const mxArray *c13_lhs8 = NULL;
  const mxArray *c13_rhs9 = NULL;
  const mxArray *c13_lhs9 = NULL;
  const mxArray *c13_rhs10 = NULL;
  const mxArray *c13_lhs10 = NULL;
  const mxArray *c13_rhs11 = NULL;
  const mxArray *c13_lhs11 = NULL;
  const mxArray *c13_rhs12 = NULL;
  const mxArray *c13_lhs12 = NULL;
  const mxArray *c13_rhs13 = NULL;
  const mxArray *c13_lhs13 = NULL;
  const mxArray *c13_rhs14 = NULL;
  const mxArray *c13_lhs14 = NULL;
  const mxArray *c13_rhs15 = NULL;
  const mxArray *c13_lhs15 = NULL;
  const mxArray *c13_rhs16 = NULL;
  const mxArray *c13_lhs16 = NULL;
  const mxArray *c13_rhs17 = NULL;
  const mxArray *c13_lhs17 = NULL;
  const mxArray *c13_rhs18 = NULL;
  const mxArray *c13_lhs18 = NULL;
  const mxArray *c13_rhs19 = NULL;
  const mxArray *c13_lhs19 = NULL;
  const mxArray *c13_rhs20 = NULL;
  const mxArray *c13_lhs20 = NULL;
  const mxArray *c13_rhs21 = NULL;
  const mxArray *c13_lhs21 = NULL;
  const mxArray *c13_rhs22 = NULL;
  const mxArray *c13_lhs22 = NULL;
  const mxArray *c13_rhs23 = NULL;
  const mxArray *c13_lhs23 = NULL;
  const mxArray *c13_rhs24 = NULL;
  const mxArray *c13_lhs24 = NULL;
  const mxArray *c13_rhs25 = NULL;
  const mxArray *c13_lhs25 = NULL;
  const mxArray *c13_rhs26 = NULL;
  const mxArray *c13_lhs26 = NULL;
  const mxArray *c13_rhs27 = NULL;
  const mxArray *c13_lhs27 = NULL;
  const mxArray *c13_rhs28 = NULL;
  const mxArray *c13_lhs28 = NULL;
  const mxArray *c13_rhs29 = NULL;
  const mxArray *c13_lhs29 = NULL;
  const mxArray *c13_rhs30 = NULL;
  const mxArray *c13_lhs30 = NULL;
  const mxArray *c13_rhs31 = NULL;
  const mxArray *c13_lhs31 = NULL;
  const mxArray *c13_rhs32 = NULL;
  const mxArray *c13_lhs32 = NULL;
  const mxArray *c13_rhs33 = NULL;
  const mxArray *c13_lhs33 = NULL;
  const mxArray *c13_rhs34 = NULL;
  const mxArray *c13_lhs34 = NULL;
  const mxArray *c13_rhs35 = NULL;
  const mxArray *c13_lhs35 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
>>>>>>> developErrorAngularVelocity
                  "resolved", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c13_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
<<<<<<< HEAD
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
=======
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830378U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c13_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs1), "lhs", "lhs",
                  1);
<<<<<<< HEAD
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
=======
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c13_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
<<<<<<< HEAD
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 3);
=======
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
>>>>>>> developErrorAngularVelocity
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c13_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs3), "lhs", "lhs",
                  3);
<<<<<<< HEAD
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
=======
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c13_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
<<<<<<< HEAD
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
=======
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c13_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs5), "lhs", "lhs",
                  5);
<<<<<<< HEAD
=======
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c13_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c13_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818776U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c13_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c13_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830378U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c13_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c13_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("rdivide"), "name", "name",
                  12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c13_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c13_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c13_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_div"), "name", "name",
                  15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c13_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("rem"), "name", "name", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c13_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c13_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c13_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1358186140U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c13_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("abs"), "name", "name", 20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c13_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c13_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c13_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c13_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c13_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("sind"), "name", "name", 25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c13_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830378U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c13_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c13_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c13_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c13_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c13_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c13_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c13_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c13_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c13_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c13_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c13_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs35), "lhs", "lhs",
                  35);
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c13_rhs0);
  sf_mex_destroy(&c13_lhs0);
  sf_mex_destroy(&c13_rhs1);
  sf_mex_destroy(&c13_lhs1);
  sf_mex_destroy(&c13_rhs2);
  sf_mex_destroy(&c13_lhs2);
  sf_mex_destroy(&c13_rhs3);
  sf_mex_destroy(&c13_lhs3);
  sf_mex_destroy(&c13_rhs4);
  sf_mex_destroy(&c13_lhs4);
  sf_mex_destroy(&c13_rhs5);
  sf_mex_destroy(&c13_lhs5);
<<<<<<< HEAD
=======
  sf_mex_destroy(&c13_rhs6);
  sf_mex_destroy(&c13_lhs6);
  sf_mex_destroy(&c13_rhs7);
  sf_mex_destroy(&c13_lhs7);
  sf_mex_destroy(&c13_rhs8);
  sf_mex_destroy(&c13_lhs8);
  sf_mex_destroy(&c13_rhs9);
  sf_mex_destroy(&c13_lhs9);
  sf_mex_destroy(&c13_rhs10);
  sf_mex_destroy(&c13_lhs10);
  sf_mex_destroy(&c13_rhs11);
  sf_mex_destroy(&c13_lhs11);
  sf_mex_destroy(&c13_rhs12);
  sf_mex_destroy(&c13_lhs12);
  sf_mex_destroy(&c13_rhs13);
  sf_mex_destroy(&c13_lhs13);
  sf_mex_destroy(&c13_rhs14);
  sf_mex_destroy(&c13_lhs14);
  sf_mex_destroy(&c13_rhs15);
  sf_mex_destroy(&c13_lhs15);
  sf_mex_destroy(&c13_rhs16);
  sf_mex_destroy(&c13_lhs16);
  sf_mex_destroy(&c13_rhs17);
  sf_mex_destroy(&c13_lhs17);
  sf_mex_destroy(&c13_rhs18);
  sf_mex_destroy(&c13_lhs18);
  sf_mex_destroy(&c13_rhs19);
  sf_mex_destroy(&c13_lhs19);
  sf_mex_destroy(&c13_rhs20);
  sf_mex_destroy(&c13_lhs20);
  sf_mex_destroy(&c13_rhs21);
  sf_mex_destroy(&c13_lhs21);
  sf_mex_destroy(&c13_rhs22);
  sf_mex_destroy(&c13_lhs22);
  sf_mex_destroy(&c13_rhs23);
  sf_mex_destroy(&c13_lhs23);
  sf_mex_destroy(&c13_rhs24);
  sf_mex_destroy(&c13_lhs24);
  sf_mex_destroy(&c13_rhs25);
  sf_mex_destroy(&c13_lhs25);
  sf_mex_destroy(&c13_rhs26);
  sf_mex_destroy(&c13_lhs26);
  sf_mex_destroy(&c13_rhs27);
  sf_mex_destroy(&c13_lhs27);
  sf_mex_destroy(&c13_rhs28);
  sf_mex_destroy(&c13_lhs28);
  sf_mex_destroy(&c13_rhs29);
  sf_mex_destroy(&c13_lhs29);
  sf_mex_destroy(&c13_rhs30);
  sf_mex_destroy(&c13_lhs30);
  sf_mex_destroy(&c13_rhs31);
  sf_mex_destroy(&c13_lhs31);
  sf_mex_destroy(&c13_rhs32);
  sf_mex_destroy(&c13_lhs32);
  sf_mex_destroy(&c13_rhs33);
  sf_mex_destroy(&c13_lhs33);
  sf_mex_destroy(&c13_rhs34);
  sf_mex_destroy(&c13_lhs34);
  sf_mex_destroy(&c13_rhs35);
  sf_mex_destroy(&c13_lhs35);
>>>>>>> developErrorAngularVelocity
}

static const mxArray *c13_emlrt_marshallOut(char * c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c13_u)), FALSE);
  return c13_y;
}

static const mxArray *c13_b_emlrt_marshallOut(uint32_T c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c13_y;
}

<<<<<<< HEAD
=======
static real_T c13_cosd(SFc13_QRsimInstanceStruct *chartInstance, real_T c13_x)
{
  real_T c13_b_x;
  c13_b_x = c13_x;
  c13_b_cosd(chartInstance, &c13_b_x);
  return c13_b_x;
}

static boolean_T c13_isfinite(SFc13_QRsimInstanceStruct *chartInstance, real_T
  c13_x)
{
  real_T c13_b_x;
  boolean_T c13_b_b;
  boolean_T c13_b0;
  real_T c13_c_x;
  boolean_T c13_c_b;
  boolean_T c13_b1;
  c13_b_x = c13_x;
  c13_b_b = muDoubleScalarIsInf(c13_b_x);
  c13_b0 = !c13_b_b;
  c13_c_x = c13_x;
  c13_c_b = muDoubleScalarIsNaN(c13_c_x);
  c13_b1 = !c13_c_b;
  return c13_b0 && c13_b1;
}

static real_T c13_sind(SFc13_QRsimInstanceStruct *chartInstance, real_T c13_x)
{
  real_T c13_b_x;
  c13_b_x = c13_x;
  c13_b_sind(chartInstance, &c13_b_x);
  return c13_b_x;
}

static void c13_eml_scalar_eg(SFc13_QRsimInstanceStruct *chartInstance)
{
}

>>>>>>> developErrorAngularVelocity
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_d_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
<<<<<<< HEAD
  int32_T c13_i18;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i18, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i18;
=======
  int32_T c13_i43;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i43, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i43;
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_b_is_active_c13_QRsim, const char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_QRsim), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_QRsim);
  return c13_y;
}

static uint8_T c13_f_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

<<<<<<< HEAD
=======
static void c13_b_cosd(SFc13_QRsimInstanceStruct *chartInstance, real_T *c13_x)
{
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_e_x;
  real_T c13_xk;
  real_T c13_f_x;
  real_T c13_g_x;
  real_T c13_absx;
  real_T c13_h_x;
  real_T c13_i_x;
  real_T c13_b;
  int8_T c13_n;
  real_T c13_b_b;
  real_T c13_c_b;
  real_T c13_d_b;
  real_T c13_e_b;
  int8_T c13_b_n;
  c13_b_x = *c13_x;
  if (!c13_isfinite(chartInstance, c13_b_x)) {
    *c13_x = rtNaN;
  } else {
    c13_c_x = c13_b_x;
    c13_d_x = c13_c_x;
    c13_e_x = c13_d_x;
    c13_xk = c13_e_x;
    c13_d_x = muDoubleScalarRem(c13_xk, 360.0);
    c13_f_x = c13_d_x;
    c13_g_x = c13_f_x;
    c13_absx = muDoubleScalarAbs(c13_g_x);
    if (c13_absx > 180.0) {
      if (c13_d_x > 0.0) {
        c13_d_x -= 360.0;
      } else {
        c13_d_x += 360.0;
      }

      c13_h_x = c13_d_x;
      c13_i_x = c13_h_x;
      c13_absx = muDoubleScalarAbs(c13_i_x);
    }

    if (c13_absx <= 45.0) {
      c13_b = c13_d_x;
      c13_d_x = 0.017453292519943295 * c13_b;
      c13_n = 0;
    } else if (c13_absx <= 135.0) {
      if (c13_d_x > 0.0) {
        c13_b_b = c13_d_x - 90.0;
        c13_d_x = 0.017453292519943295 * c13_b_b;
        c13_n = 1;
      } else {
        c13_c_b = c13_d_x + 90.0;
        c13_d_x = 0.017453292519943295 * c13_c_b;
        c13_n = -1;
      }
    } else if (c13_d_x > 0.0) {
      c13_d_b = c13_d_x - 180.0;
      c13_d_x = 0.017453292519943295 * c13_d_b;
      c13_n = 2;
    } else {
      c13_e_b = c13_d_x + 180.0;
      c13_d_x = 0.017453292519943295 * c13_e_b;
      c13_n = -2;
    }

    c13_b_n = c13_n;
    c13_b_x = c13_d_x;
    if ((real_T)c13_b_n == 0.0) {
      *c13_x = muDoubleScalarCos(c13_b_x);
    } else if ((real_T)c13_b_n == 1.0) {
      *c13_x = -muDoubleScalarSin(c13_b_x);
    } else if ((real_T)c13_b_n == -1.0) {
      *c13_x = muDoubleScalarSin(c13_b_x);
    } else {
      *c13_x = -muDoubleScalarCos(c13_b_x);
    }
  }
}

static void c13_b_sind(SFc13_QRsimInstanceStruct *chartInstance, real_T *c13_x)
{
  real_T c13_b_x;
  real_T c13_d13;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_e_x;
  real_T c13_xk;
  real_T c13_f_x;
  real_T c13_g_x;
  real_T c13_absx;
  real_T c13_h_x;
  real_T c13_i_x;
  real_T c13_b;
  int8_T c13_n;
  real_T c13_b_b;
  real_T c13_c_b;
  real_T c13_d_b;
  real_T c13_e_b;
  int8_T c13_b_n;
  c13_b_x = *c13_x;
  if (!c13_isfinite(chartInstance, c13_b_x)) {
    c13_d13 = rtNaN;
  } else {
    c13_c_x = c13_b_x;
    c13_d_x = c13_c_x;
    c13_e_x = c13_d_x;
    c13_xk = c13_e_x;
    c13_d_x = muDoubleScalarRem(c13_xk, 360.0);
    c13_f_x = c13_d_x;
    c13_g_x = c13_f_x;
    c13_absx = muDoubleScalarAbs(c13_g_x);
    if (c13_absx > 180.0) {
      if (c13_d_x > 0.0) {
        c13_d_x -= 360.0;
      } else {
        c13_d_x += 360.0;
      }

      c13_h_x = c13_d_x;
      c13_i_x = c13_h_x;
      c13_absx = muDoubleScalarAbs(c13_i_x);
    }

    if (c13_absx <= 45.0) {
      c13_b = c13_d_x;
      c13_d_x = 0.017453292519943295 * c13_b;
      c13_n = 0;
    } else if (c13_absx <= 135.0) {
      if (c13_d_x > 0.0) {
        c13_b_b = c13_d_x - 90.0;
        c13_d_x = 0.017453292519943295 * c13_b_b;
        c13_n = 1;
      } else {
        c13_c_b = c13_d_x + 90.0;
        c13_d_x = 0.017453292519943295 * c13_c_b;
        c13_n = -1;
      }
    } else if (c13_d_x > 0.0) {
      c13_d_b = c13_d_x - 180.0;
      c13_d_x = 0.017453292519943295 * c13_d_b;
      c13_n = 2;
    } else {
      c13_e_b = c13_d_x + 180.0;
      c13_d_x = 0.017453292519943295 * c13_e_b;
      c13_n = -2;
    }

    c13_b_n = c13_n;
    c13_b_x = c13_d_x;
    if ((real_T)c13_b_n == 0.0) {
      c13_d13 = muDoubleScalarSin(c13_b_x);
    } else if ((real_T)c13_b_n == 1.0) {
      c13_d13 = muDoubleScalarCos(c13_b_x);
    } else if ((real_T)c13_b_n == -1.0) {
      c13_d13 = -muDoubleScalarCos(c13_b_x);
    } else {
      c13_d13 = -muDoubleScalarSin(c13_b_x);
    }
  }

  *c13_x = c13_d13;
}

>>>>>>> developErrorAngularVelocity
static void init_dsm_address_info(SFc13_QRsimInstanceStruct *chartInstance)
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

void sf_c13_QRsim_get_check_sum(mxArray *plhs[])
{
<<<<<<< HEAD
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(820885817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3489915080U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2181857650U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3733255706U);
=======
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4161303644U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1017397270U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2243362173U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(118713491U);
>>>>>>> developErrorAngularVelocity
}

mxArray *sf_c13_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("d1Re7gAfZivS1IxfXG0JMH");
=======
    mxArray *mxChecksum = mxCreateString("DeDS61mwAqCGDMgUWF5kH");
>>>>>>> developErrorAngularVelocity
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
<<<<<<< HEAD
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"R\",},{M[8],M[0],T\"is_active_c13_QRsim\",}}"
=======
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Rzyx\",},{M[8],M[0],T\"is_active_c13_QRsim\",}}"
>>>>>>> developErrorAngularVelocity
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc13_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           13,
           1,
           1,
           2,
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
          init_script_number_translation(_QRsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_QRsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _QRsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
<<<<<<< HEAD
          _SFD_SET_DATA_PROPS(1,2,0,1,"R");
=======
          _SFD_SET_DATA_PROPS(1,2,0,1,"Rzyx");
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,522);
=======
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,543);
>>>>>>> developErrorAngularVelocity

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          real_T (*c13_u)[3];
<<<<<<< HEAD
          real_T (*c13_R)[9];
          c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_R);
=======
          real_T (*c13_Rzyx)[9];
          c13_Rzyx = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_Rzyx);
>>>>>>> developErrorAngularVelocity
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _QRsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
<<<<<<< HEAD
  return "lzUjFRIZ7vGzn9QGQzxgHH";
=======
  return "Na5piELXZly8g0Jak6tH9B";
>>>>>>> developErrorAngularVelocity
}

static void sf_opaque_initialize_c13_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_QRsim(void *chartInstanceVar)
{
  enable_c13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_QRsim(void *chartInstanceVar)
{
  disable_c13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_QRsim(void *chartInstanceVar)
{
  sf_c13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_QRsim((SFc13_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c13_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_QRsim((SFc13_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c13_QRsim(S);
}

static void sf_opaque_set_sim_state_c13_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c13_QRsim(S, st);
}

static void sf_opaque_terminate_c13_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_QRsim((SFc13_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_QRsim((SFc13_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
<<<<<<< HEAD
  ssSetChecksum0(S,(2503289984U));
  ssSetChecksum1(S,(2503898944U));
  ssSetChecksum2(S,(791019644U));
  ssSetChecksum3(S,(4171950133U));
=======
  ssSetChecksum0(S,(403686400U));
  ssSetChecksum1(S,(2401584399U));
  ssSetChecksum2(S,(1100294042U));
  ssSetChecksum3(S,(197025813U));
>>>>>>> developErrorAngularVelocity
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_QRsim(SimStruct *S)
{
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc13_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c13_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c13_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c13_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c13_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c13_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c13_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c13_QRsim;
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

void c13_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
