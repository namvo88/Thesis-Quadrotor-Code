/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c16_QRsim.h"
<<<<<<< HEAD
#include "mwmathutil.h"
=======
>>>>>>> developErrorAngularVelocity
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
static const char * c16_debug_family_names[7] = { "phi", "theta", "psi",
  "nargin", "nargout", "u", "R" };
=======
static const char * c16_debug_family_names[9] = { "p", "q", "r", "Omegahat",
  "nargin", "nargout", "R", "Omega", "dR" };
>>>>>>> developErrorAngularVelocity

/* Function Declarations */
static void initialize_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void initialize_params_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void enable_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void disable_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_QRsim(SFc16_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c16_QRsim(SFc16_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_st);
static void finalize_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void sf_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void c16_chartstep_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void initSimStructsc16_QRsim(SFc16_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c16_R, const char_T *c16_identifier, real_T c16_y[9]);
=======
  mxArray *c16_dR, const char_T *c16_identifier, real_T c16_y[9]);
>>>>>>> developErrorAngularVelocity
static void c16_b_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[9]);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_c_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(uint32_T c16_u);
<<<<<<< HEAD
=======
static void c16_eml_scalar_eg(SFc16_QRsimInstanceStruct *chartInstance);
>>>>>>> developErrorAngularVelocity
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_d_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_e_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_b_is_active_c16_QRsim, const char_T *c16_identifier);
static uint8_T c16_f_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_QRsim = 0U;
}

static void initialize_params_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_QRsim(SFc16_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c16_QRsim(SFc16_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[9];
  const mxArray *c16_b_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
<<<<<<< HEAD
  real_T (*c16_R)[9];
  c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
=======
  real_T (*c16_dR)[9];
  c16_dR = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
>>>>>>> developErrorAngularVelocity
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(2), FALSE);
  for (c16_i0 = 0; c16_i0 < 9; c16_i0++) {
<<<<<<< HEAD
    c16_u[c16_i0] = (*c16_R)[c16_i0];
=======
    c16_u[c16_i0] = (*c16_dR)[c16_i0];
>>>>>>> developErrorAngularVelocity
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_hoistedGlobal = chartInstance->c16_is_active_c16_QRsim;
  c16_b_u = c16_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y, FALSE);
  return c16_st;
}

static void set_sim_state_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[9];
  int32_T c16_i1;
<<<<<<< HEAD
  real_T (*c16_R)[9];
  c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)), "R",
                       c16_dv0);
  for (c16_i1 = 0; c16_i1 < 9; c16_i1++) {
    (*c16_R)[c16_i1] = c16_dv0[c16_i1];
=======
  real_T (*c16_dR)[9];
  c16_dR = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)), "dR",
                       c16_dv0);
  for (c16_i1 = 0; c16_i1 < 9; c16_i1++) {
    (*c16_dR)[c16_i1] = c16_dv0[c16_i1];
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c16_is_active_c16_QRsim = c16_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c16_u, 1)), "is_active_c16_QRsim");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_QRsim(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
  int32_T c16_i2;
  int32_T c16_i3;
<<<<<<< HEAD
  real_T (*c16_R)[9];
  real_T (*c16_u)[3];
  c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i2 = 0; c16_i2 < 3; c16_i2++) {
    _SFD_DATA_RANGE_CHECK((*c16_u)[c16_i2], 0U);
  }

  for (c16_i3 = 0; c16_i3 < 9; c16_i3++) {
    _SFD_DATA_RANGE_CHECK((*c16_R)[c16_i3], 1U);
=======
  int32_T c16_i4;
  real_T (*c16_Omega)[3];
  real_T (*c16_dR)[9];
  real_T (*c16_R)[9];
  c16_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c16_dR = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i2 = 0; c16_i2 < 9; c16_i2++) {
    _SFD_DATA_RANGE_CHECK((*c16_R)[c16_i2], 0U);
  }

  for (c16_i3 = 0; c16_i3 < 9; c16_i3++) {
    _SFD_DATA_RANGE_CHECK((*c16_dR)[c16_i3], 1U);
  }

  for (c16_i4 = 0; c16_i4 < 3; c16_i4++) {
    _SFD_DATA_RANGE_CHECK((*c16_Omega)[c16_i4], 2U);
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c16_chartstep_c16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
<<<<<<< HEAD
  int32_T c16_i4;
  real_T c16_u[3];
  uint32_T c16_debug_family_var_map[7];
  real_T c16_phi;
  real_T c16_theta;
  real_T c16_psi;
  real_T c16_nargin = 1.0;
  real_T c16_nargout = 1.0;
  real_T c16_R[9];
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_c_x;
  real_T c16_d_x;
  real_T c16_a;
  real_T c16_b;
  real_T c16_y;
  real_T c16_e_x;
  real_T c16_f_x;
  real_T c16_g_x;
  real_T c16_h_x;
  real_T c16_b_a;
  real_T c16_b_b;
  real_T c16_b_y;
  real_T c16_i_x;
  real_T c16_j_x;
  real_T c16_c_a;
  real_T c16_c_b;
  real_T c16_c_y;
  real_T c16_k_x;
  real_T c16_l_x;
  real_T c16_m_x;
  real_T c16_n_x;
  real_T c16_d_a;
  real_T c16_d_b;
  real_T c16_d_y;
  real_T c16_o_x;
  real_T c16_p_x;
  real_T c16_q_x;
  real_T c16_r_x;
  real_T c16_e_a;
  real_T c16_e_b;
  real_T c16_e_y;
  real_T c16_s_x;
  real_T c16_t_x;
  real_T c16_u_x;
  real_T c16_v_x;
  real_T c16_f_a;
  real_T c16_f_b;
  real_T c16_f_y;
  real_T c16_w_x;
  real_T c16_x_x;
  real_T c16_g_a;
  real_T c16_g_b;
  real_T c16_g_y;
  real_T c16_y_x;
  real_T c16_ab_x;
  real_T c16_bb_x;
  real_T c16_cb_x;
  real_T c16_h_a;
  real_T c16_h_b;
  real_T c16_h_y;
  real_T c16_db_x;
  real_T c16_eb_x;
  real_T c16_fb_x;
  real_T c16_gb_x;
  real_T c16_i_a;
  real_T c16_i_b;
  real_T c16_i_y;
  real_T c16_hb_x;
  real_T c16_ib_x;
  real_T c16_j_a;
  real_T c16_j_b;
  real_T c16_j_y;
  real_T c16_jb_x;
  real_T c16_kb_x;
  real_T c16_lb_x;
  real_T c16_mb_x;
  real_T c16_k_a;
  real_T c16_k_b;
  real_T c16_k_y;
  real_T c16_nb_x;
  real_T c16_ob_x;
  real_T c16_pb_x;
  real_T c16_qb_x;
  real_T c16_l_a;
  real_T c16_l_b;
  real_T c16_l_y;
  real_T c16_rb_x;
  real_T c16_sb_x;
  real_T c16_tb_x;
  real_T c16_ub_x;
  real_T c16_m_a;
  real_T c16_m_b;
  real_T c16_m_y;
  real_T c16_vb_x;
  real_T c16_wb_x;
  real_T c16_n_a;
  real_T c16_n_b;
  real_T c16_n_y;
  real_T c16_xb_x;
  real_T c16_yb_x;
  real_T c16_ac_x;
  real_T c16_bc_x;
  real_T c16_o_a;
  real_T c16_o_b;
  real_T c16_o_y;
  real_T c16_cc_x;
  real_T c16_dc_x;
  real_T c16_ec_x;
  real_T c16_fc_x;
  real_T c16_gc_x;
  real_T c16_hc_x;
  real_T c16_p_a;
  real_T c16_p_b;
  real_T c16_p_y;
  int32_T c16_i5;
  real_T (*c16_b_R)[9];
  real_T (*c16_b_u)[3];
  c16_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i4 = 0; c16_i4 < 3; c16_i4++) {
    c16_u[c16_i4] = (*c16_b_u)[c16_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_phi, 0U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta, 1U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_psi, 2U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 3U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 4U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_u, 5U, c16_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_R, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_phi = c16_u[0];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 8);
  c16_theta = c16_u[1];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
  c16_psi = c16_u[2];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  c16_x = c16_psi;
  c16_b_x = c16_x;
  c16_b_x = muDoubleScalarCos(c16_b_x);
  c16_c_x = c16_theta;
  c16_d_x = c16_c_x;
  c16_d_x = muDoubleScalarCos(c16_d_x);
  c16_a = c16_b_x;
  c16_b = c16_d_x;
  c16_y = c16_a * c16_b;
  c16_e_x = c16_phi;
  c16_f_x = c16_e_x;
  c16_f_x = muDoubleScalarSin(c16_f_x);
  c16_g_x = c16_psi;
  c16_h_x = c16_g_x;
  c16_h_x = muDoubleScalarSin(c16_h_x);
  c16_b_a = c16_f_x;
  c16_b_b = c16_h_x;
  c16_b_y = c16_b_a * c16_b_b;
  c16_i_x = c16_theta;
  c16_j_x = c16_i_x;
  c16_j_x = muDoubleScalarSin(c16_j_x);
  c16_c_a = c16_b_y;
  c16_c_b = c16_j_x;
  c16_c_y = c16_c_a * c16_c_b;
  c16_k_x = c16_phi;
  c16_l_x = c16_k_x;
  c16_l_x = muDoubleScalarCos(c16_l_x);
  c16_m_x = c16_psi;
  c16_n_x = c16_m_x;
  c16_n_x = muDoubleScalarSin(c16_n_x);
  c16_d_a = -c16_l_x;
  c16_d_b = c16_n_x;
  c16_d_y = c16_d_a * c16_d_b;
  c16_o_x = c16_psi;
  c16_p_x = c16_o_x;
  c16_p_x = muDoubleScalarCos(c16_p_x);
  c16_q_x = c16_theta;
  c16_r_x = c16_q_x;
  c16_r_x = muDoubleScalarSin(c16_r_x);
  c16_e_a = c16_p_x;
  c16_e_b = c16_r_x;
  c16_e_y = c16_e_a * c16_e_b;
  c16_s_x = c16_theta;
  c16_t_x = c16_s_x;
  c16_t_x = muDoubleScalarCos(c16_t_x);
  c16_u_x = c16_phi;
  c16_v_x = c16_u_x;
  c16_v_x = muDoubleScalarSin(c16_v_x);
  c16_f_a = c16_t_x;
  c16_f_b = c16_v_x;
  c16_f_y = c16_f_a * c16_f_b;
  c16_w_x = c16_psi;
  c16_x_x = c16_w_x;
  c16_x_x = muDoubleScalarSin(c16_x_x);
  c16_g_a = c16_f_y;
  c16_g_b = c16_x_x;
  c16_g_y = c16_g_a * c16_g_b;
  c16_y_x = c16_theta;
  c16_ab_x = c16_y_x;
  c16_ab_x = muDoubleScalarCos(c16_ab_x);
  c16_bb_x = c16_psi;
  c16_cb_x = c16_bb_x;
  c16_cb_x = muDoubleScalarSin(c16_cb_x);
  c16_h_a = c16_ab_x;
  c16_h_b = c16_cb_x;
  c16_h_y = c16_h_a * c16_h_b;
  c16_db_x = c16_psi;
  c16_eb_x = c16_db_x;
  c16_eb_x = muDoubleScalarCos(c16_eb_x);
  c16_fb_x = c16_phi;
  c16_gb_x = c16_fb_x;
  c16_gb_x = muDoubleScalarSin(c16_gb_x);
  c16_i_a = c16_eb_x;
  c16_i_b = c16_gb_x;
  c16_i_y = c16_i_a * c16_i_b;
  c16_hb_x = c16_theta;
  c16_ib_x = c16_hb_x;
  c16_ib_x = muDoubleScalarSin(c16_ib_x);
  c16_j_a = c16_i_y;
  c16_j_b = c16_ib_x;
  c16_j_y = c16_j_a * c16_j_b;
  c16_jb_x = c16_phi;
  c16_kb_x = c16_jb_x;
  c16_kb_x = muDoubleScalarCos(c16_kb_x);
  c16_lb_x = c16_psi;
  c16_mb_x = c16_lb_x;
  c16_mb_x = muDoubleScalarCos(c16_mb_x);
  c16_k_a = c16_kb_x;
  c16_k_b = c16_mb_x;
  c16_k_y = c16_k_a * c16_k_b;
  c16_nb_x = c16_psi;
  c16_ob_x = c16_nb_x;
  c16_ob_x = muDoubleScalarSin(c16_ob_x);
  c16_pb_x = c16_theta;
  c16_qb_x = c16_pb_x;
  c16_qb_x = muDoubleScalarSin(c16_qb_x);
  c16_l_a = c16_ob_x;
  c16_l_b = c16_qb_x;
  c16_l_y = c16_l_a * c16_l_b;
  c16_rb_x = c16_psi;
  c16_sb_x = c16_rb_x;
  c16_sb_x = muDoubleScalarCos(c16_sb_x);
  c16_tb_x = c16_theta;
  c16_ub_x = c16_tb_x;
  c16_ub_x = muDoubleScalarCos(c16_ub_x);
  c16_m_a = c16_sb_x;
  c16_m_b = c16_ub_x;
  c16_m_y = c16_m_a * c16_m_b;
  c16_vb_x = c16_phi;
  c16_wb_x = c16_vb_x;
  c16_wb_x = muDoubleScalarSin(c16_wb_x);
  c16_n_a = c16_m_y;
  c16_n_b = c16_wb_x;
  c16_n_y = c16_n_a * c16_n_b;
  c16_xb_x = c16_phi;
  c16_yb_x = c16_xb_x;
  c16_yb_x = muDoubleScalarCos(c16_yb_x);
  c16_ac_x = c16_theta;
  c16_bc_x = c16_ac_x;
  c16_bc_x = muDoubleScalarSin(c16_bc_x);
  c16_o_a = -c16_yb_x;
  c16_o_b = c16_bc_x;
  c16_o_y = c16_o_a * c16_o_b;
  c16_cc_x = c16_phi;
  c16_dc_x = c16_cc_x;
  c16_dc_x = muDoubleScalarSin(c16_dc_x);
  c16_ec_x = c16_phi;
  c16_fc_x = c16_ec_x;
  c16_fc_x = muDoubleScalarCos(c16_fc_x);
  c16_gc_x = c16_theta;
  c16_hc_x = c16_gc_x;
  c16_hc_x = muDoubleScalarCos(c16_hc_x);
  c16_p_a = c16_fc_x;
  c16_p_b = c16_hc_x;
  c16_p_y = c16_p_a * c16_p_b;
  c16_R[0] = c16_y - c16_c_y;
  c16_R[3] = c16_d_y;
  c16_R[6] = c16_e_y + c16_g_y;
  c16_R[1] = c16_h_y + c16_j_y;
  c16_R[4] = c16_k_y;
  c16_R[7] = c16_l_y - c16_n_y;
  c16_R[2] = c16_o_y;
  c16_R[5] = c16_dc_x;
  c16_R[8] = c16_p_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c16_i5 = 0; c16_i5 < 9; c16_i5++) {
    (*c16_b_R)[c16_i5] = c16_R[c16_i5];
=======
  int32_T c16_i5;
  real_T c16_R[9];
  int32_T c16_i6;
  real_T c16_Omega[3];
  uint32_T c16_debug_family_var_map[9];
  real_T c16_p;
  real_T c16_q;
  real_T c16_r;
  real_T c16_Omegahat[9];
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  real_T c16_dR[9];
  int32_T c16_i7;
  real_T c16_a[9];
  int32_T c16_i8;
  real_T c16_b[9];
  int32_T c16_i9;
  int32_T c16_i10;
  int32_T c16_i11;
  real_T c16_C[9];
  int32_T c16_i12;
  int32_T c16_i13;
  int32_T c16_i14;
  int32_T c16_i15;
  int32_T c16_i16;
  int32_T c16_i17;
  int32_T c16_i18;
  int32_T c16_i19;
  int32_T c16_i20;
  real_T (*c16_b_dR)[9];
  real_T (*c16_b_Omega)[3];
  real_T (*c16_b_R)[9];
  c16_b_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_dR = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i5 = 0; c16_i5 < 9; c16_i5++) {
    c16_R[c16_i5] = (*c16_b_R)[c16_i5];
  }

  for (c16_i6 = 0; c16_i6 < 3; c16_i6++) {
    c16_Omega[c16_i6] = (*c16_b_Omega)[c16_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_p, 0U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_q, 1U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_r, 2U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_Omegahat, 3U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 4U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 5U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_R, 6U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_Omega, 7U, c16_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_dR, 8U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 3);
  c16_p = c16_Omega[0];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 4);
  c16_q = c16_Omega[1];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 5);
  c16_r = c16_Omega[2];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_Omegahat[0] = 0.0;
  c16_Omegahat[3] = -c16_r;
  c16_Omegahat[6] = c16_q;
  c16_Omegahat[1] = c16_r;
  c16_Omegahat[4] = 0.0;
  c16_Omegahat[7] = -c16_p;
  c16_Omegahat[2] = -c16_q;
  c16_Omegahat[5] = c16_p;
  c16_Omegahat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  for (c16_i7 = 0; c16_i7 < 9; c16_i7++) {
    c16_a[c16_i7] = c16_R[c16_i7];
  }

  for (c16_i8 = 0; c16_i8 < 9; c16_i8++) {
    c16_b[c16_i8] = c16_Omegahat[c16_i8];
  }

  c16_eml_scalar_eg(chartInstance);
  c16_eml_scalar_eg(chartInstance);
  for (c16_i9 = 0; c16_i9 < 9; c16_i9++) {
    c16_dR[c16_i9] = 0.0;
  }

  for (c16_i10 = 0; c16_i10 < 9; c16_i10++) {
    c16_dR[c16_i10] = 0.0;
  }

  for (c16_i11 = 0; c16_i11 < 9; c16_i11++) {
    c16_C[c16_i11] = c16_dR[c16_i11];
  }

  for (c16_i12 = 0; c16_i12 < 9; c16_i12++) {
    c16_dR[c16_i12] = c16_C[c16_i12];
  }

  for (c16_i13 = 0; c16_i13 < 9; c16_i13++) {
    c16_C[c16_i13] = c16_dR[c16_i13];
  }

  for (c16_i14 = 0; c16_i14 < 9; c16_i14++) {
    c16_dR[c16_i14] = c16_C[c16_i14];
  }

  for (c16_i15 = 0; c16_i15 < 3; c16_i15++) {
    c16_i16 = 0;
    for (c16_i17 = 0; c16_i17 < 3; c16_i17++) {
      c16_dR[c16_i16 + c16_i15] = 0.0;
      c16_i18 = 0;
      for (c16_i19 = 0; c16_i19 < 3; c16_i19++) {
        c16_dR[c16_i16 + c16_i15] += c16_a[c16_i18 + c16_i15] * c16_b[c16_i19 +
          c16_i16];
        c16_i18 += 3;
      }

      c16_i16 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c16_i20 = 0; c16_i20 < 9; c16_i20++) {
    (*c16_b_dR)[c16_i20] = c16_dR[c16_i20];
>>>>>>> developErrorAngularVelocity
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_QRsim(SFc16_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c16_i6;
  int32_T c16_i7;
  int32_T c16_i8;
  real_T c16_b_inData[9];
  int32_T c16_i9;
  int32_T c16_i10;
  int32_T c16_i11;
=======
  int32_T c16_i21;
  int32_T c16_i22;
  int32_T c16_i23;
  real_T c16_b_inData[9];
  int32_T c16_i24;
  int32_T c16_i25;
  int32_T c16_i26;
>>>>>>> developErrorAngularVelocity
  real_T c16_u[9];
  const mxArray *c16_y = NULL;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
<<<<<<< HEAD
  c16_i6 = 0;
  for (c16_i7 = 0; c16_i7 < 3; c16_i7++) {
    for (c16_i8 = 0; c16_i8 < 3; c16_i8++) {
      c16_b_inData[c16_i8 + c16_i6] = (*(real_T (*)[9])c16_inData)[c16_i8 +
        c16_i6];
    }

    c16_i6 += 3;
  }

  c16_i9 = 0;
  for (c16_i10 = 0; c16_i10 < 3; c16_i10++) {
    for (c16_i11 = 0; c16_i11 < 3; c16_i11++) {
      c16_u[c16_i11 + c16_i9] = c16_b_inData[c16_i11 + c16_i9];
    }

    c16_i9 += 3;
=======
  c16_i21 = 0;
  for (c16_i22 = 0; c16_i22 < 3; c16_i22++) {
    for (c16_i23 = 0; c16_i23 < 3; c16_i23++) {
      c16_b_inData[c16_i23 + c16_i21] = (*(real_T (*)[9])c16_inData)[c16_i23 +
        c16_i21];
    }

    c16_i21 += 3;
  }

  c16_i24 = 0;
  for (c16_i25 = 0; c16_i25 < 3; c16_i25++) {
    for (c16_i26 = 0; c16_i26 < 3; c16_i26++) {
      c16_u[c16_i26 + c16_i24] = c16_b_inData[c16_i26 + c16_i24];
    }

    c16_i24 += 3;
>>>>>>> developErrorAngularVelocity
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c16_R, const char_T *c16_identifier, real_T c16_y[9])
=======
  mxArray *c16_dR, const char_T *c16_identifier, real_T c16_y[9])
>>>>>>> developErrorAngularVelocity
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
<<<<<<< HEAD
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_R), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_R);
=======
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_dR), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_dR);
>>>>>>> developErrorAngularVelocity
}

static void c16_b_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[9])
{
  real_T c16_dv1[9];
<<<<<<< HEAD
  int32_T c16_i12;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c16_i12 = 0; c16_i12 < 9; c16_i12++) {
    c16_y[c16_i12] = c16_dv1[c16_i12];
=======
  int32_T c16_i27;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c16_i27 = 0; c16_i27 < 9; c16_i27++) {
    c16_y[c16_i27] = c16_dv1[c16_i27];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c16_u);
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
<<<<<<< HEAD
  const mxArray *c16_R;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[9];
  int32_T c16_i13;
  int32_T c16_i14;
  int32_T c16_i15;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_R = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_R), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_R);
  c16_i13 = 0;
  for (c16_i14 = 0; c16_i14 < 3; c16_i14++) {
    for (c16_i15 = 0; c16_i15 < 3; c16_i15++) {
      (*(real_T (*)[9])c16_outData)[c16_i15 + c16_i13] = c16_y[c16_i15 + c16_i13];
    }

    c16_i13 += 3;
=======
  const mxArray *c16_dR;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[9];
  int32_T c16_i28;
  int32_T c16_i29;
  int32_T c16_i30;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_dR = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_dR), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_dR);
  c16_i28 = 0;
  for (c16_i29 = 0; c16_i29 < 3; c16_i29++) {
    for (c16_i30 = 0; c16_i30 < 3; c16_i30++) {
      (*(real_T (*)[9])c16_outData)[c16_i30 + c16_i28] = c16_y[c16_i30 + c16_i28];
    }

    c16_i28 += 3;
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c16_i16;
  real_T c16_b_inData[3];
  int32_T c16_i17;
=======
  int32_T c16_i31;
  real_T c16_b_inData[3];
  int32_T c16_i32;
>>>>>>> developErrorAngularVelocity
  real_T c16_u[3];
  const mxArray *c16_y = NULL;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
<<<<<<< HEAD
  for (c16_i16 = 0; c16_i16 < 3; c16_i16++) {
    c16_b_inData[c16_i16] = (*(real_T (*)[3])c16_inData)[c16_i16];
  }

  for (c16_i17 = 0; c16_i17 < 3; c16_i17++) {
    c16_u[c16_i17] = c16_b_inData[c16_i17];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
=======
  for (c16_i31 = 0; c16_i31 < 3; c16_i31++) {
    c16_b_inData[c16_i31] = (*(real_T (*)[3])c16_inData)[c16_i31];
  }

  for (c16_i32 = 0; c16_i32 < 3; c16_i32++) {
    c16_u[c16_i32] = c16_b_inData[c16_i32];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
>>>>>>> developErrorAngularVelocity
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static real_T c16_c_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
<<<<<<< HEAD
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
=======
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
>>>>>>> developErrorAngularVelocity
                FALSE);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  const mxArray *c16_rhs4 = NULL;
  const mxArray *c16_lhs4 = NULL;
  const mxArray *c16_rhs5 = NULL;
  const mxArray *c16_lhs5 = NULL;
<<<<<<< HEAD
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
=======
  const mxArray *c16_rhs6 = NULL;
  const mxArray *c16_lhs6 = NULL;
  const mxArray *c16_rhs7 = NULL;
  const mxArray *c16_lhs7 = NULL;
  const mxArray *c16_rhs8 = NULL;
  const mxArray *c16_lhs8 = NULL;
  const mxArray *c16_rhs9 = NULL;
  const mxArray *c16_lhs9 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
<<<<<<< HEAD
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
=======
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
<<<<<<< HEAD
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mtimes"), "name", "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
=======
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
<<<<<<< HEAD
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
=======
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
<<<<<<< HEAD
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
=======
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c16_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
<<<<<<< HEAD
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
=======
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
>>>>>>> developErrorAngularVelocity
                  "fileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c16_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs5), "lhs", "lhs",
                  5);
<<<<<<< HEAD
=======
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c16_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c16_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c16_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c16_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs9), "lhs", "lhs",
                  9);
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
  sf_mex_destroy(&c16_rhs4);
  sf_mex_destroy(&c16_lhs4);
  sf_mex_destroy(&c16_rhs5);
  sf_mex_destroy(&c16_lhs5);
<<<<<<< HEAD
=======
  sf_mex_destroy(&c16_rhs6);
  sf_mex_destroy(&c16_lhs6);
  sf_mex_destroy(&c16_rhs7);
  sf_mex_destroy(&c16_lhs7);
  sf_mex_destroy(&c16_rhs8);
  sf_mex_destroy(&c16_lhs8);
  sf_mex_destroy(&c16_rhs9);
  sf_mex_destroy(&c16_lhs9);
>>>>>>> developErrorAngularVelocity
}

static const mxArray *c16_emlrt_marshallOut(char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), FALSE);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c16_y;
}

<<<<<<< HEAD
=======
static void c16_eml_scalar_eg(SFc16_QRsimInstanceStruct *chartInstance)
{
}

>>>>>>> developErrorAngularVelocity
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static int32_T c16_d_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
<<<<<<< HEAD
  int32_T c16_i18;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i18, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i18;
=======
  int32_T c16_i33;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i33, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i33;
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_e_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_b_is_active_c16_QRsim, const char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_QRsim), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_QRsim);
  return c16_y;
}

static uint8_T c16_f_emlrt_marshallIn(SFc16_QRsimInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_QRsimInstanceStruct *chartInstance)
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

void sf_c16_QRsim_get_check_sum(mxArray *plhs[])
{
<<<<<<< HEAD
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(820885817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3489915080U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2181857650U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3733255706U);
=======
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1423948415U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1375587083U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3967187243U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2538390176U);
>>>>>>> developErrorAngularVelocity
}

mxArray *sf_c16_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("d1Re7gAfZivS1IxfXG0JMH");
=======
    mxArray *mxChecksum = mxCreateString("hwuV911QRLnaYzh0oISSH");
>>>>>>> developErrorAngularVelocity
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

<<<<<<< HEAD
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
=======
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
>>>>>>> developErrorAngularVelocity

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
<<<<<<< HEAD
      pr[1] = (double)(1);
=======
      pr[1] = (double)(3);
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
=======

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
>>>>>>> developErrorAngularVelocity
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

mxArray *sf_c16_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c16_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
<<<<<<< HEAD
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"R\",},{M[8],M[0],T\"is_active_c16_QRsim\",}}"
=======
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dR\",},{M[8],M[0],T\"is_active_c16_QRsim\",}}"
>>>>>>> developErrorAngularVelocity
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc16_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           16,
           1,
           1,
<<<<<<< HEAD
           2,
=======
           3,
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"R");
=======
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dR");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Omega");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,162);
>>>>>>> developErrorAngularVelocity

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
<<<<<<< HEAD
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
=======
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
>>>>>>> developErrorAngularVelocity
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)
            c16_sf_marshallIn);
        }

        {
<<<<<<< HEAD
          real_T (*c16_u)[3];
          real_T (*c16_R)[9];
          c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c16_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c16_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_R);
=======
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c16_R)[9];
          real_T (*c16_dR)[9];
          real_T (*c16_Omega)[3];
          c16_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c16_dR = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c16_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c16_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_dR);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_Omega);
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
  return "1oVMqUtTvZjNFmQW2uHhwE";
>>>>>>> developErrorAngularVelocity
}

static void sf_opaque_initialize_c16_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_QRsim(void *chartInstanceVar)
{
  enable_c16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_QRsim(void *chartInstanceVar)
{
  disable_c16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_QRsim(void *chartInstanceVar)
{
  sf_c16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_QRsim((SFc16_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c16_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_QRsim((SFc16_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c16_QRsim(S);
}

static void sf_opaque_set_sim_state_c16_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c16_QRsim(S, st);
}

static void sf_opaque_terminate_c16_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_QRsim((SFc16_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_QRsim((SFc16_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,16,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
<<<<<<< HEAD
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
=======
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,2);
>>>>>>> developErrorAngularVelocity
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
<<<<<<< HEAD
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
=======
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
>>>>>>> developErrorAngularVelocity
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
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
  ssSetChecksum0(S,(3894304129U));
  ssSetChecksum1(S,(1574841944U));
  ssSetChecksum2(S,(2799782877U));
  ssSetChecksum3(S,(50608510U));
>>>>>>> developErrorAngularVelocity
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_QRsim(SimStruct *S)
{
  SFc16_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc16_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc16_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c16_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c16_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c16_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c16_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c16_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c16_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c16_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c16_QRsim;
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

void c16_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
