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
static const char * c13_debug_family_names[7] = { "phi", "theta", "psi",
  "nargin", "nargout", "u", "R" };

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
  mxArray *c13_R, const char_T *c13_identifier, real_T c13_y[9]);
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
  real_T (*c13_R)[9];
  c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2), FALSE);
  for (c13_i0 = 0; c13_i0 < 9; c13_i0++) {
    c13_u[c13_i0] = (*c13_R)[c13_i0];
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
  real_T (*c13_R)[9];
  c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)), "R",
                       c13_dv0);
  for (c13_i1 = 0; c13_i1 < 9; c13_i1++) {
    (*c13_R)[c13_i1] = c13_dv0[c13_i1];
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
  real_T (*c13_R)[9];
  real_T (*c13_u)[3];
  c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c13_sfEvent);
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    _SFD_DATA_RANGE_CHECK((*c13_u)[c13_i2], 0U);
  }

  for (c13_i3 = 0; c13_i3 < 9; c13_i3++) {
    _SFD_DATA_RANGE_CHECK((*c13_R)[c13_i3], 1U);
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
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_phi, 0U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_theta, 1U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_psi, 2U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 3U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 4U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_u, 5U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_R, 6U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
  c13_phi = c13_u[0];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
  c13_theta = c13_u[1];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 9);
  c13_psi = c13_u[2];
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
  int32_T c13_i6;
  int32_T c13_i7;
  int32_T c13_i8;
  real_T c13_b_inData[9];
  int32_T c13_i9;
  int32_T c13_i10;
  int32_T c13_i11;
  real_T c13_u[9];
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
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
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance, const
  mxArray *c13_R, const char_T *c13_identifier, real_T c13_y[9])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_R), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_R);
}

static void c13_b_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[9])
{
  real_T c13_dv1[9];
  int32_T c13_i12;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c13_i12 = 0; c13_i12 < 9; c13_i12++) {
    c13_y[c13_i12] = c13_dv1[c13_i12];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
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
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i16;
  real_T c13_b_inData[3];
  int32_T c13_i17;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i16 = 0; c13_i16 < 3; c13_i16++) {
    c13_b_inData[c13_i16] = (*(real_T (*)[3])c13_inData)[c13_i16];
  }

  for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
    c13_u[c13_i17] = c13_b_inData[c13_i17];
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
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
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
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
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
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
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
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 3);
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
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
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
  int32_T c13_i18;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i18, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i18;
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(820885817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3489915080U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2181857650U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3733255706U);
}

mxArray *sf_c13_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("d1Re7gAfZivS1IxfXG0JMH");
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
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"R\",},{M[8],M[0],T\"is_active_c13_QRsim\",}}"
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"R");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,522);

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
          real_T (*c13_R)[9];
          c13_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_R);
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
  return "lzUjFRIZ7vGzn9QGQzxgHH";
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
  ssSetChecksum0(S,(2503289984U));
  ssSetChecksum1(S,(2503898944U));
  ssSetChecksum2(S,(791019644U));
  ssSetChecksum3(S,(4171950133U));
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
