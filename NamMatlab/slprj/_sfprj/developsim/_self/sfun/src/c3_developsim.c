/* Include files */

#include <stddef.h>
#include "blas.h"
#include "developsim_sfun.h"
#include "c3_developsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "developsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[7] = { "phi", "theta", "psi", "nargin",
  "nargout", "u", "R" };

/* Function Declarations */
static void initialize_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance);
static void initialize_params_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance);
static void enable_c3_developsim(SFc3_developsimInstanceStruct *chartInstance);
static void disable_c3_developsim(SFc3_developsimInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_developsim(SFc3_developsimInstanceStruct *
  chartInstance);
static void set_sim_state_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_developsim(SFc3_developsimInstanceStruct *chartInstance);
static void sf_c3_developsim(SFc3_developsimInstanceStruct *chartInstance);
static void c3_chartstep_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance);
static void initSimStructsc3_developsim(SFc3_developsimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_developsimInstanceStruct *chartInstance,
  const mxArray *c3_R, const char_T *c3_identifier, real_T c3_y[9]);
static void c3_b_emlrt_marshallIn(SFc3_developsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_developsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(uint32_T c3_u);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_developsim, const char_T
  *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_developsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_developsim = 0U;
}

static void initialize_params_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance)
{
}

static void enable_c3_developsim(SFc3_developsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_developsim(SFc3_developsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_developsim(SFc3_developsimInstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[9];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_R)[9];
  c3_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
    c3_u[c3_i0] = (*c3_R)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_developsim;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[9];
  int32_T c3_i1;
  real_T (*c3_R)[9];
  c3_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "R",
                      c3_dv0);
  for (c3_i1 = 0; c3_i1 < 9; c3_i1++) {
    (*c3_R)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_developsim = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_developsim");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_developsim(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_developsim(SFc3_developsimInstanceStruct *chartInstance)
{
}

static void sf_c3_developsim(SFc3_developsimInstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  real_T (*c3_R)[9];
  real_T (*c3_u)[3];
  c3_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_u)[c3_i2], 0U);
  }

  for (c3_i3 = 0; c3_i3 < 9; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_R)[c3_i3], 1U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_developsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_developsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_developsim(SFc3_developsimInstanceStruct
  *chartInstance)
{
  int32_T c3_i4;
  real_T c3_u[3];
  uint32_T c3_debug_family_var_map[7];
  real_T c3_phi;
  real_T c3_theta;
  real_T c3_psi;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  real_T c3_R[9];
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_a;
  real_T c3_b;
  real_T c3_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_d_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_e_y;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_f_y;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_g_y;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_h_y;
  real_T c3_db_x;
  real_T c3_eb_x;
  real_T c3_fb_x;
  real_T c3_gb_x;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_i_y;
  real_T c3_hb_x;
  real_T c3_ib_x;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_j_y;
  real_T c3_jb_x;
  real_T c3_kb_x;
  real_T c3_lb_x;
  real_T c3_mb_x;
  real_T c3_k_a;
  real_T c3_k_b;
  real_T c3_k_y;
  real_T c3_nb_x;
  real_T c3_ob_x;
  real_T c3_pb_x;
  real_T c3_qb_x;
  real_T c3_l_a;
  real_T c3_l_b;
  real_T c3_l_y;
  real_T c3_rb_x;
  real_T c3_sb_x;
  real_T c3_tb_x;
  real_T c3_ub_x;
  real_T c3_m_a;
  real_T c3_m_b;
  real_T c3_m_y;
  real_T c3_vb_x;
  real_T c3_wb_x;
  real_T c3_n_a;
  real_T c3_n_b;
  real_T c3_n_y;
  real_T c3_xb_x;
  real_T c3_yb_x;
  real_T c3_ac_x;
  real_T c3_bc_x;
  real_T c3_o_a;
  real_T c3_o_b;
  real_T c3_o_y;
  real_T c3_cc_x;
  real_T c3_dc_x;
  real_T c3_ec_x;
  real_T c3_fc_x;
  real_T c3_gc_x;
  real_T c3_hc_x;
  real_T c3_p_a;
  real_T c3_p_b;
  real_T c3_p_y;
  int32_T c3_i5;
  real_T (*c3_b_R)[9];
  real_T (*c3_b_u)[3];
  c3_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_u[c3_i4] = (*c3_b_u)[c3_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_phi, 0U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_theta, 1U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_psi, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_u, 5U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_R, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_phi = c3_u[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_theta = c3_u[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_psi = c3_u[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_x = c3_psi;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarCos(c3_b_x);
  c3_c_x = c3_theta;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_a = c3_b_x;
  c3_b = c3_d_x;
  c3_y = c3_a * c3_b;
  c3_e_x = c3_phi;
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarSin(c3_f_x);
  c3_g_x = c3_psi;
  c3_h_x = c3_g_x;
  c3_h_x = muDoubleScalarSin(c3_h_x);
  c3_b_a = c3_f_x;
  c3_b_b = c3_h_x;
  c3_b_y = c3_b_a * c3_b_b;
  c3_i_x = c3_theta;
  c3_j_x = c3_i_x;
  c3_j_x = muDoubleScalarSin(c3_j_x);
  c3_c_a = c3_b_y;
  c3_c_b = c3_j_x;
  c3_c_y = c3_c_a * c3_c_b;
  c3_k_x = c3_phi;
  c3_l_x = c3_k_x;
  c3_l_x = muDoubleScalarCos(c3_l_x);
  c3_m_x = c3_psi;
  c3_n_x = c3_m_x;
  c3_n_x = muDoubleScalarSin(c3_n_x);
  c3_d_a = -c3_l_x;
  c3_d_b = c3_n_x;
  c3_d_y = c3_d_a * c3_d_b;
  c3_o_x = c3_psi;
  c3_p_x = c3_o_x;
  c3_p_x = muDoubleScalarCos(c3_p_x);
  c3_q_x = c3_theta;
  c3_r_x = c3_q_x;
  c3_r_x = muDoubleScalarSin(c3_r_x);
  c3_e_a = c3_p_x;
  c3_e_b = c3_r_x;
  c3_e_y = c3_e_a * c3_e_b;
  c3_s_x = c3_theta;
  c3_t_x = c3_s_x;
  c3_t_x = muDoubleScalarCos(c3_t_x);
  c3_u_x = c3_phi;
  c3_v_x = c3_u_x;
  c3_v_x = muDoubleScalarSin(c3_v_x);
  c3_f_a = c3_t_x;
  c3_f_b = c3_v_x;
  c3_f_y = c3_f_a * c3_f_b;
  c3_w_x = c3_psi;
  c3_x_x = c3_w_x;
  c3_x_x = muDoubleScalarSin(c3_x_x);
  c3_g_a = c3_f_y;
  c3_g_b = c3_x_x;
  c3_g_y = c3_g_a * c3_g_b;
  c3_y_x = c3_theta;
  c3_ab_x = c3_y_x;
  c3_ab_x = muDoubleScalarCos(c3_ab_x);
  c3_bb_x = c3_psi;
  c3_cb_x = c3_bb_x;
  c3_cb_x = muDoubleScalarSin(c3_cb_x);
  c3_h_a = c3_ab_x;
  c3_h_b = c3_cb_x;
  c3_h_y = c3_h_a * c3_h_b;
  c3_db_x = c3_psi;
  c3_eb_x = c3_db_x;
  c3_eb_x = muDoubleScalarCos(c3_eb_x);
  c3_fb_x = c3_phi;
  c3_gb_x = c3_fb_x;
  c3_gb_x = muDoubleScalarSin(c3_gb_x);
  c3_i_a = c3_eb_x;
  c3_i_b = c3_gb_x;
  c3_i_y = c3_i_a * c3_i_b;
  c3_hb_x = c3_theta;
  c3_ib_x = c3_hb_x;
  c3_ib_x = muDoubleScalarSin(c3_ib_x);
  c3_j_a = c3_i_y;
  c3_j_b = c3_ib_x;
  c3_j_y = c3_j_a * c3_j_b;
  c3_jb_x = c3_phi;
  c3_kb_x = c3_jb_x;
  c3_kb_x = muDoubleScalarCos(c3_kb_x);
  c3_lb_x = c3_psi;
  c3_mb_x = c3_lb_x;
  c3_mb_x = muDoubleScalarCos(c3_mb_x);
  c3_k_a = c3_kb_x;
  c3_k_b = c3_mb_x;
  c3_k_y = c3_k_a * c3_k_b;
  c3_nb_x = c3_psi;
  c3_ob_x = c3_nb_x;
  c3_ob_x = muDoubleScalarSin(c3_ob_x);
  c3_pb_x = c3_theta;
  c3_qb_x = c3_pb_x;
  c3_qb_x = muDoubleScalarSin(c3_qb_x);
  c3_l_a = c3_ob_x;
  c3_l_b = c3_qb_x;
  c3_l_y = c3_l_a * c3_l_b;
  c3_rb_x = c3_psi;
  c3_sb_x = c3_rb_x;
  c3_sb_x = muDoubleScalarCos(c3_sb_x);
  c3_tb_x = c3_theta;
  c3_ub_x = c3_tb_x;
  c3_ub_x = muDoubleScalarCos(c3_ub_x);
  c3_m_a = c3_sb_x;
  c3_m_b = c3_ub_x;
  c3_m_y = c3_m_a * c3_m_b;
  c3_vb_x = c3_phi;
  c3_wb_x = c3_vb_x;
  c3_wb_x = muDoubleScalarSin(c3_wb_x);
  c3_n_a = c3_m_y;
  c3_n_b = c3_wb_x;
  c3_n_y = c3_n_a * c3_n_b;
  c3_xb_x = c3_phi;
  c3_yb_x = c3_xb_x;
  c3_yb_x = muDoubleScalarCos(c3_yb_x);
  c3_ac_x = c3_theta;
  c3_bc_x = c3_ac_x;
  c3_bc_x = muDoubleScalarSin(c3_bc_x);
  c3_o_a = -c3_yb_x;
  c3_o_b = c3_bc_x;
  c3_o_y = c3_o_a * c3_o_b;
  c3_cc_x = c3_phi;
  c3_dc_x = c3_cc_x;
  c3_dc_x = muDoubleScalarSin(c3_dc_x);
  c3_ec_x = c3_phi;
  c3_fc_x = c3_ec_x;
  c3_fc_x = muDoubleScalarCos(c3_fc_x);
  c3_gc_x = c3_theta;
  c3_hc_x = c3_gc_x;
  c3_hc_x = muDoubleScalarCos(c3_hc_x);
  c3_p_a = c3_fc_x;
  c3_p_b = c3_hc_x;
  c3_p_y = c3_p_a * c3_p_b;
  c3_R[0] = c3_y - c3_c_y;
  c3_R[3] = c3_d_y;
  c3_R[6] = c3_e_y + c3_g_y;
  c3_R[1] = c3_h_y + c3_j_y;
  c3_R[4] = c3_k_y;
  c3_R[7] = c3_l_y - c3_n_y;
  c3_R[2] = c3_o_y;
  c3_R[5] = c3_dc_x;
  c3_R[8] = c3_p_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i5 = 0; c3_i5 < 9; c3_i5++) {
    (*c3_b_R)[c3_i5] = c3_R[c3_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_developsim(SFc3_developsimInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  real_T c3_b_inData[9];
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i6 = 0;
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
      c3_b_inData[c3_i8 + c3_i6] = (*(real_T (*)[9])c3_inData)[c3_i8 + c3_i6];
    }

    c3_i6 += 3;
  }

  c3_i9 = 0;
  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
      c3_u[c3_i11 + c3_i9] = c3_b_inData[c3_i11 + c3_i9];
    }

    c3_i9 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_developsimInstanceStruct *chartInstance,
  const mxArray *c3_R, const char_T *c3_identifier, real_T c3_y[9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_R), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_R);
}

static void c3_b_emlrt_marshallIn(SFc3_developsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9])
{
  real_T c3_dv1[9];
  int32_T c3_i12;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i12 = 0; c3_i12 < 9; c3_i12++) {
    c3_y[c3_i12] = c3_dv1[c3_i12];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_R;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_R = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_R), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_R);
  c3_i13 = 0;
  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
      (*(real_T (*)[9])c3_outData)[c3_i15 + c3_i13] = c3_y[c3_i15 + c3_i13];
    }

    c3_i13 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i16;
  real_T c3_b_inData[3];
  int32_T c3_i17;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    c3_b_inData[c3_i16] = (*(real_T (*)[3])c3_inData)[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    c3_u[c3_i17] = c3_b_inData[c3_i17];
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
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_developsimInstanceStruct *chartInstance,
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
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_developsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mtimes"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
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

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i18;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i18, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i18;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_developsim, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_developsim), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_developsim);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_developsimInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_developsimInstanceStruct *chartInstance)
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

void sf_c3_developsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1386915459U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2415316863U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2585673298U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1058802245U);
}

mxArray *sf_c3_developsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yKqTNDAf7eBqwJm5Nnp39F");
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

mxArray *sf_c3_developsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_developsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_developsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"R\",},{M[8],M[0],T\"is_active_c3_developsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_developsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_developsimInstanceStruct *chartInstance;
    chartInstance = (SFc3_developsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _developsimMachineNumber_,
           3,
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
          init_script_number_translation(_developsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_developsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _developsimMachineNumber_,
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
          real_T (*c3_u)[3];
          real_T (*c3_R)[9];
          c3_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_R);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _developsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sf4oErASUjHDiTLbFEY7rB";
}

static void sf_opaque_initialize_c3_developsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_developsimInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_developsim((SFc3_developsimInstanceStruct*)
    chartInstanceVar);
  initialize_c3_developsim((SFc3_developsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_developsim(void *chartInstanceVar)
{
  enable_c3_developsim((SFc3_developsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_developsim(void *chartInstanceVar)
{
  disable_c3_developsim((SFc3_developsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_developsim(void *chartInstanceVar)
{
  sf_c3_developsim((SFc3_developsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_developsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_developsim
    ((SFc3_developsimInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_developsim();/* state var info */
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

extern void sf_internal_set_sim_state_c3_developsim(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_developsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_developsim((SFc3_developsimInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_developsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_developsim(S);
}

static void sf_opaque_set_sim_state_c3_developsim(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_developsim(S, st);
}

static void sf_opaque_terminate_c3_developsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_developsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_developsim_optimization_info();
    }

    finalize_c3_developsim((SFc3_developsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_developsim((SFc3_developsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_developsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_developsim((SFc3_developsimInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_developsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_developsim_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3849840916U));
  ssSetChecksum1(S,(815532908U));
  ssSetChecksum2(S,(2142912338U));
  ssSetChecksum3(S,(3240130204U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_developsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_developsim(SimStruct *S)
{
  SFc3_developsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_developsimInstanceStruct *)utMalloc(sizeof
    (SFc3_developsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_developsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_developsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_developsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_developsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_developsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_developsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_developsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_developsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_developsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_developsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_developsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_developsim;
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

void c3_developsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_developsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_developsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_developsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_developsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
