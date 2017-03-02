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
static const char * c13_debug_family_names[10] = { "phi", "theta", "psi", "Rx",
  "Ry", "Rz", "nargin", "nargout", "u", "Rzxy" };

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
  mxArray *c13_Rzxy, const char_T *c13_identifier, real_T c13_y[9]);
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
static void c13_eml_scalar_eg(SFc13_QRsimInstanceStruct *chartInstance);
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
  real_T (*c13_Rzxy)[9];
  c13_Rzxy = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2), FALSE);
  for (c13_i0 = 0; c13_i0 < 9; c13_i0++) {
    c13_u[c13_i0] = (*c13_Rzxy)[c13_i0];
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
  real_T (*c13_Rzxy)[9];
  c13_Rzxy = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)),
                       "Rzxy", c13_dv0);
  for (c13_i1 = 0; c13_i1 < 9; c13_i1++) {
    (*c13_Rzxy)[c13_i1] = c13_dv0[c13_i1];
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
  real_T (*c13_Rzxy)[9];
  real_T (*c13_u)[3];
  c13_Rzxy = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    _SFD_DATA_RANGE_CHECK((*c13_u)[c13_i2], 0U);
  }

  for (c13_i3 = 0; c13_i3 < 9; c13_i3++) {
    _SFD_DATA_RANGE_CHECK((*c13_Rzxy)[c13_i3], 1U);
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
  uint32_T c13_debug_family_var_map[10];
  real_T c13_phi;
  real_T c13_theta;
  real_T c13_psi;
  real_T c13_Rx[9];
  real_T c13_Ry[9];
  real_T c13_Rz[9];
  real_T c13_nargin = 1.0;
  real_T c13_nargout = 1.0;
  real_T c13_Rzxy[9];
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_e_x;
  real_T c13_f_x;
  real_T c13_g_x;
  real_T c13_h_x;
  int32_T c13_i5;
  int32_T c13_i6;
  static real_T c13_dv1[3] = { 1.0, 0.0, 0.0 };

  real_T c13_i_x;
  real_T c13_j_x;
  real_T c13_k_x;
  real_T c13_l_x;
  real_T c13_m_x;
  real_T c13_n_x;
  real_T c13_o_x;
  real_T c13_p_x;
  int32_T c13_i7;
  int32_T c13_i8;
  static real_T c13_dv2[3] = { 0.0, 1.0, 0.0 };

  real_T c13_q_x;
  real_T c13_r_x;
  real_T c13_s_x;
  real_T c13_t_x;
  real_T c13_u_x;
  real_T c13_v_x;
  real_T c13_w_x;
  real_T c13_x_x;
  int32_T c13_i9;
  int32_T c13_i10;
  static real_T c13_dv3[3] = { 0.0, 0.0, 1.0 };

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
  real_T (*c13_b_Rzxy)[9];
  real_T (*c13_b_u)[3];
  c13_b_Rzxy = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    c13_u[c13_i4] = (*c13_b_u)[c13_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_phi, 0U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_theta, 1U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_psi, 2U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Rx, 3U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Ry, 4U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Rz, 5U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 6U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 7U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_u, 8U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_Rzxy, 9U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
  c13_phi = c13_u[0];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
  c13_theta = c13_u[1];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 9);
  c13_psi = c13_u[2];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 11);
  c13_x = c13_phi;
  c13_b_x = c13_x;
  c13_b_x = muDoubleScalarCos(c13_b_x);
  c13_c_x = c13_phi;
  c13_d_x = c13_c_x;
  c13_d_x = muDoubleScalarSin(c13_d_x);
  c13_e_x = c13_phi;
  c13_f_x = c13_e_x;
  c13_f_x = muDoubleScalarSin(c13_f_x);
  c13_g_x = c13_phi;
  c13_h_x = c13_g_x;
  c13_h_x = muDoubleScalarCos(c13_h_x);
  c13_i5 = 0;
  for (c13_i6 = 0; c13_i6 < 3; c13_i6++) {
    c13_Rx[c13_i5] = c13_dv1[c13_i6];
    c13_i5 += 3;
  }

  c13_Rx[1] = 0.0;
  c13_Rx[4] = c13_b_x;
  c13_Rx[7] = c13_d_x;
  c13_Rx[2] = 0.0;
  c13_Rx[5] = -c13_f_x;
  c13_Rx[8] = c13_h_x;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
  c13_i_x = c13_theta;
  c13_j_x = c13_i_x;
  c13_j_x = muDoubleScalarCos(c13_j_x);
  c13_k_x = c13_theta;
  c13_l_x = c13_k_x;
  c13_l_x = muDoubleScalarSin(c13_l_x);
  c13_m_x = c13_theta;
  c13_n_x = c13_m_x;
  c13_n_x = muDoubleScalarSin(c13_n_x);
  c13_o_x = c13_theta;
  c13_p_x = c13_o_x;
  c13_p_x = muDoubleScalarCos(c13_p_x);
  c13_Ry[0] = c13_j_x;
  c13_Ry[3] = 0.0;
  c13_Ry[6] = -c13_l_x;
  c13_i7 = 0;
  for (c13_i8 = 0; c13_i8 < 3; c13_i8++) {
    c13_Ry[c13_i7 + 1] = c13_dv2[c13_i8];
    c13_i7 += 3;
  }

  c13_Ry[2] = c13_n_x;
  c13_Ry[5] = 0.0;
  c13_Ry[8] = c13_p_x;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 19);
  c13_q_x = c13_psi;
  c13_r_x = c13_q_x;
  c13_r_x = muDoubleScalarCos(c13_r_x);
  c13_s_x = c13_psi;
  c13_t_x = c13_s_x;
  c13_t_x = muDoubleScalarSin(c13_t_x);
  c13_u_x = c13_psi;
  c13_v_x = c13_u_x;
  c13_v_x = muDoubleScalarSin(c13_v_x);
  c13_w_x = c13_psi;
  c13_x_x = c13_w_x;
  c13_x_x = muDoubleScalarCos(c13_x_x);
  c13_Rz[0] = c13_r_x;
  c13_Rz[3] = c13_t_x;
  c13_Rz[6] = 0.0;
  c13_Rz[1] = -c13_v_x;
  c13_Rz[4] = c13_x_x;
  c13_Rz[7] = 0.0;
  c13_i9 = 0;
  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    c13_Rz[c13_i9 + 2] = c13_dv3[c13_i10];
    c13_i9 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 23);
  for (c13_i11 = 0; c13_i11 < 9; c13_i11++) {
    c13_a[c13_i11] = c13_Rz[c13_i11];
  }

  for (c13_i12 = 0; c13_i12 < 9; c13_i12++) {
    c13_b[c13_i12] = c13_Rx[c13_i12];
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
    c13_b[c13_i18] = c13_Ry[c13_i18];
  }

  c13_eml_scalar_eg(chartInstance);
  c13_eml_scalar_eg(chartInstance);
  for (c13_i19 = 0; c13_i19 < 3; c13_i19++) {
    c13_i20 = 0;
    for (c13_i21 = 0; c13_i21 < 3; c13_i21++) {
      c13_a[c13_i20 + c13_i19] = 0.0;
      c13_i22 = 0;
      for (c13_i23 = 0; c13_i23 < 3; c13_i23++) {
        c13_a[c13_i20 + c13_i19] += c13_y[c13_i22 + c13_i19] * c13_b[c13_i23 +
          c13_i20];
        c13_i22 += 3;
      }

      c13_i20 += 3;
    }
  }

  c13_i24 = 0;
  for (c13_i25 = 0; c13_i25 < 3; c13_i25++) {
    c13_i26 = 0;
    for (c13_i27 = 0; c13_i27 < 3; c13_i27++) {
      c13_Rzxy[c13_i27 + c13_i24] = c13_a[c13_i26 + c13_i25];
      c13_i26 += 3;
    }

    c13_i24 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -23);
  _SFD_SYMBOL_SCOPE_POP();
  for (c13_i28 = 0; c13_i28 < 9; c13_i28++) {
    (*c13_b_Rzxy)[c13_i28] = c13_Rzxy[c13_i28];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
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
  int32_T c13_i29;
  int32_T c13_i30;
  int32_T c13_i31;
  real_T c13_b_inData[9];
  int32_T c13_i32;
  int32_T c13_i33;
  int32_T c13_i34;
  real_T c13_u[9];
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_i29 = 0;
  for (c13_i30 = 0; c13_i30 < 3; c13_i30++) {
    for (c13_i31 = 0; c13_i31 < 3; c13_i31++) {
      c13_b_inData[c13_i31 + c13_i29] = (*(real_T (*)[9])c13_inData)[c13_i31 +
        c13_i29];
    }

    c13_i29 += 3;
  }

  c13_i32 = 0;
  for (c13_i33 = 0; c13_i33 < 3; c13_i33++) {
    for (c13_i34 = 0; c13_i34 < 3; c13_i34++) {
      c13_u[c13_i34 + c13_i32] = c13_b_inData[c13_i34 + c13_i32];
    }

    c13_i32 += 3;
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance, const
  mxArray *c13_Rzxy, const char_T *c13_identifier, real_T c13_y[9])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_Rzxy), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_Rzxy);
}

static void c13_b_emlrt_marshallIn(SFc13_QRsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[9])
{
  real_T c13_dv4[9];
  int32_T c13_i35;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c13_i35 = 0; c13_i35 < 9; c13_i35++) {
    c13_y[c13_i35] = c13_dv4[c13_i35];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_Rzxy;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[9];
  int32_T c13_i36;
  int32_T c13_i37;
  int32_T c13_i38;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_Rzxy = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_Rzxy), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_Rzxy);
  c13_i36 = 0;
  for (c13_i37 = 0; c13_i37 < 3; c13_i37++) {
    for (c13_i38 = 0; c13_i38 < 3; c13_i38++) {
      (*(real_T (*)[9])c13_outData)[c13_i38 + c13_i36] = c13_y[c13_i38 + c13_i36];
    }

    c13_i36 += 3;
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i39;
  real_T c13_b_inData[3];
  int32_T c13_i40;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i39 = 0; c13_i39 < 3; c13_i39++) {
    c13_b_inData[c13_i39] = (*(real_T (*)[3])c13_inData)[c13_i39];
  }

  for (c13_i40 = 0; c13_i40 < 3; c13_i40++) {
    c13_u[c13_i40] = c13_b_inData[c13_i40];
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
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
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
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
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
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
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
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mtimes"), "name", "name", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
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

static void c13_eml_scalar_eg(SFc13_QRsimInstanceStruct *chartInstance)
{
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
  int32_T c13_i41;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i41, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i41;
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2992231388U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3879553303U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2427716840U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2796159153U);
}

mxArray *sf_c13_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2WIdDrQkqEzBA4plBRPlw");
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
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Rzxy\",},{M[8],M[0],T\"is_active_c13_QRsim\",}}"
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"Rzxy");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,387);

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
          real_T (*c13_Rzxy)[9];
          c13_Rzxy = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c13_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_Rzxy);
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
  return "oMllpqHb3SmmScSANeghW";
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
  ssSetChecksum0(S,(1502027055U));
  ssSetChecksum1(S,(3494336051U));
  ssSetChecksum2(S,(261016921U));
  ssSetChecksum3(S,(1342153484U));
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
