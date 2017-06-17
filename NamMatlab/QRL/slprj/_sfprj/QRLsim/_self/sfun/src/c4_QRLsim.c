/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c4_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[9] = { "b", "d", "l", "nargin",
  "nargout", "var", "omegarot", "f", "M" };

/* Function Declarations */
static void initialize_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void enable_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void disable_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_QRLsim(SFc4_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_QRLsim(SFc4_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void sf_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void c4_chartstep_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance, const
  mxArray *c4_M, const char_T *c4_identifier, real_T c4_y[3]);
static void c4_b_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_f, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(uint32_T c4_u);
static void c4_eml_scalar_eg(SFc4_QRLsimInstanceStruct *chartInstance);
static void c4_b_eml_scalar_eg(SFc4_QRLsimInstanceStruct *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_f_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_QRLsim, const char_T *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_QRLsim = 0U;
}

static void initialize_params_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
}

static void enable_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_QRLsim(SFc4_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_QRLsim(SFc4_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T *c4_f;
  real_T (*c4_M)[3];
  c4_M = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_f = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(3), FALSE);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    c4_u[c4_i0] = (*c4_M)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = *c4_f;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_active_c4_QRLsim;
  c4_c_u = c4_b_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[3];
  int32_T c4_i1;
  real_T *c4_f;
  real_T (*c4_M)[3];
  c4_M = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_f = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "M",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    (*c4_M)[c4_i1] = c4_dv0[c4_i1];
  }

  *c4_f = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "f");
  chartInstance->c4_is_active_c4_QRLsim = c4_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 2)), "is_active_c4_QRLsim");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_QRLsim(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  real_T *c4_f;
  real_T (*c4_omegarot)[4];
  real_T (*c4_M)[3];
  real_T (*c4_var)[3];
  c4_omegarot = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c4_M = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_f = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_var = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_var)[c4_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_f, 1U);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_M)[c4_i3], 2U);
  }

  for (c4_i4 = 0; c4_i4 < 4; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_omegarot)[c4_i4], 3U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_QRLsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
  int32_T c4_i5;
  real_T c4_var[3];
  int32_T c4_i6;
  real_T c4_omegarot[4];
  uint32_T c4_debug_family_var_map[9];
  real_T c4_b;
  real_T c4_d;
  real_T c4_l;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 2.0;
  real_T c4_f;
  real_T c4_M[3];
  real_T c4_a[4];
  int32_T c4_i7;
  real_T c4_b_b[4];
  int32_T c4_k;
  int32_T c4_b_k;
  real_T c4_b_a;
  real_T c4_c_b;
  real_T c4_y;
  real_T c4_c_a;
  real_T c4_d_b;
  real_T c4_b_y;
  real_T c4_d_a;
  real_T c4_e_b;
  real_T c4_c_y;
  real_T c4_e_a;
  real_T c4_f_b;
  real_T c4_d_y;
  real_T c4_f_a[12];
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  real_T c4_C[3];
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  real_T *c4_b_f;
  real_T (*c4_b_M)[3];
  real_T (*c4_b_omegarot)[4];
  real_T (*c4_b_var)[3];
  c4_b_omegarot = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_M = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_f = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_var = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_var[c4_i5] = (*c4_b_var)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 4; c4_i6++) {
    c4_omegarot[c4_i6] = (*c4_b_omegarot)[c4_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_var, 5U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_omegarot, 6U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_M, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_b = c4_var[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_d = c4_var[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_l = c4_var[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_a[0] = c4_b;
  c4_a[1] = c4_b;
  c4_a[2] = c4_b;
  c4_a[3] = c4_b;
  for (c4_i7 = 0; c4_i7 < 4; c4_i7++) {
    c4_b_b[c4_i7] = c4_omegarot[c4_i7];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  c4_f = 0.0;
  for (c4_k = 1; c4_k < 5; c4_k++) {
    c4_b_k = c4_k;
    c4_f += c4_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c4_b_k), 1, 4, 1, 0) - 1] * c4_b_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c4_b_k), 1, 4, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_b_a = -c4_l;
  c4_c_b = c4_b;
  c4_y = c4_b_a * c4_c_b;
  c4_c_a = c4_l;
  c4_d_b = c4_b;
  c4_b_y = c4_c_a * c4_d_b;
  c4_d_a = c4_l;
  c4_e_b = c4_b;
  c4_c_y = c4_d_a * c4_e_b;
  c4_e_a = -c4_l;
  c4_f_b = c4_b;
  c4_d_y = c4_e_a * c4_f_b;
  c4_f_a[0] = 0.0;
  c4_f_a[3] = c4_y;
  c4_f_a[6] = 0.0;
  c4_f_a[9] = c4_b_y;
  c4_f_a[1] = c4_c_y;
  c4_f_a[4] = 0.0;
  c4_f_a[7] = c4_d_y;
  c4_f_a[10] = 0.0;
  c4_f_a[2] = -c4_d;
  c4_f_a[5] = c4_d;
  c4_f_a[8] = -c4_d;
  c4_f_a[11] = c4_d;
  for (c4_i8 = 0; c4_i8 < 4; c4_i8++) {
    c4_b_b[c4_i8] = c4_omegarot[c4_i8];
  }

  c4_b_eml_scalar_eg(chartInstance);
  c4_b_eml_scalar_eg(chartInstance);
  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_M[c4_i9] = 0.0;
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_M[c4_i10] = 0.0;
  }

  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    c4_C[c4_i11] = c4_M[c4_i11];
  }

  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_M[c4_i12] = c4_C[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_C[c4_i13] = c4_M[c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_M[c4_i14] = c4_C[c4_i14];
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_M[c4_i15] = 0.0;
    c4_i16 = 0;
    for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
      c4_M[c4_i15] += c4_f_a[c4_i16 + c4_i15] * c4_b_b[c4_i17];
      c4_i16 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_b_f = c4_f;
  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    (*c4_b_M)[c4_i18] = c4_M[c4_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i19;
  real_T c4_b_inData[3];
  int32_T c4_i20;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
    c4_b_inData[c4_i19] = (*(real_T (*)[3])c4_inData)[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
    c4_u[c4_i20] = c4_b_inData[c4_i20];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance, const
  mxArray *c4_M, const char_T *c4_identifier, real_T c4_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_M), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_M);
}

static void c4_b_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3])
{
  real_T c4_dv1[3];
  int32_T c4_i21;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i21 = 0; c4_i21 < 3; c4_i21++) {
    c4_y[c4_i21] = c4_dv1[c4_i21];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_M;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i22;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_M = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_M), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_M);
  for (c4_i22 = 0; c4_i22 < 3; c4_i22++) {
    (*(real_T (*)[3])c4_outData)[c4_i22] = c4_y[c4_i22];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_f, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_f), &c4_thisId);
  sf_mex_destroy(&c4_f);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_f;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_f = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_f), &c4_thisId);
  sf_mex_destroy(&c4_f);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i23;
  real_T c4_b_inData[4];
  int32_T c4_i24;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i23 = 0; c4_i23 < 4; c4_i23++) {
    c4_b_inData[c4_i23] = (*(real_T (*)[4])c4_inData)[c4_i23];
  }

  for (c4_i24 = 0; c4_i24 < 4; c4_i24++) {
    c4_u[c4_i24] = c4_b_inData[c4_i24];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 27, 1),
                FALSE);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  const mxArray *c4_rhs11 = NULL;
  const mxArray *c4_lhs11 = NULL;
  const mxArray *c4_rhs12 = NULL;
  const mxArray *c4_lhs12 = NULL;
  const mxArray *c4_rhs13 = NULL;
  const mxArray *c4_lhs13 = NULL;
  const mxArray *c4_rhs14 = NULL;
  const mxArray *c4_lhs14 = NULL;
  const mxArray *c4_rhs15 = NULL;
  const mxArray *c4_lhs15 = NULL;
  const mxArray *c4_rhs16 = NULL;
  const mxArray *c4_lhs16 = NULL;
  const mxArray *c4_rhs17 = NULL;
  const mxArray *c4_lhs17 = NULL;
  const mxArray *c4_rhs18 = NULL;
  const mxArray *c4_lhs18 = NULL;
  const mxArray *c4_rhs19 = NULL;
  const mxArray *c4_lhs19 = NULL;
  const mxArray *c4_rhs20 = NULL;
  const mxArray *c4_lhs20 = NULL;
  const mxArray *c4_rhs21 = NULL;
  const mxArray *c4_lhs21 = NULL;
  const mxArray *c4_rhs22 = NULL;
  const mxArray *c4_lhs22 = NULL;
  const mxArray *c4_rhs23 = NULL;
  const mxArray *c4_lhs23 = NULL;
  const mxArray *c4_rhs24 = NULL;
  const mxArray *c4_lhs24 = NULL;
  const mxArray *c4_rhs25 = NULL;
  const mxArray *c4_lhs25 = NULL;
  const mxArray *c4_rhs26 = NULL;
  const mxArray *c4_lhs26 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_xdotu"), "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_xdot"), "name", "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1299076772U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c4_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c4_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c4_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c4_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c4_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c4_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c4_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c4_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c4_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmax"), "name", "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c4_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c4_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c4_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mtimes"), "name", "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c4_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c4_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c4_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c4_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs26), "lhs", "lhs",
                  26);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
  sf_mex_destroy(&c4_rhs11);
  sf_mex_destroy(&c4_lhs11);
  sf_mex_destroy(&c4_rhs12);
  sf_mex_destroy(&c4_lhs12);
  sf_mex_destroy(&c4_rhs13);
  sf_mex_destroy(&c4_lhs13);
  sf_mex_destroy(&c4_rhs14);
  sf_mex_destroy(&c4_lhs14);
  sf_mex_destroy(&c4_rhs15);
  sf_mex_destroy(&c4_lhs15);
  sf_mex_destroy(&c4_rhs16);
  sf_mex_destroy(&c4_lhs16);
  sf_mex_destroy(&c4_rhs17);
  sf_mex_destroy(&c4_lhs17);
  sf_mex_destroy(&c4_rhs18);
  sf_mex_destroy(&c4_lhs18);
  sf_mex_destroy(&c4_rhs19);
  sf_mex_destroy(&c4_lhs19);
  sf_mex_destroy(&c4_rhs20);
  sf_mex_destroy(&c4_lhs20);
  sf_mex_destroy(&c4_rhs21);
  sf_mex_destroy(&c4_lhs21);
  sf_mex_destroy(&c4_rhs22);
  sf_mex_destroy(&c4_lhs22);
  sf_mex_destroy(&c4_rhs23);
  sf_mex_destroy(&c4_lhs23);
  sf_mex_destroy(&c4_rhs24);
  sf_mex_destroy(&c4_lhs24);
  sf_mex_destroy(&c4_rhs25);
  sf_mex_destroy(&c4_lhs25);
  sf_mex_destroy(&c4_rhs26);
  sf_mex_destroy(&c4_lhs26);
}

static const mxArray *c4_emlrt_marshallOut(char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), FALSE);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c4_y;
}

static void c4_eml_scalar_eg(SFc4_QRLsimInstanceStruct *chartInstance)
{
}

static void c4_b_eml_scalar_eg(SFc4_QRLsimInstanceStruct *chartInstance)
{
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i25;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i25, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i25;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_QRLsim, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_QRLsim), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_QRLsim);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_QRLsimInstanceStruct *chartInstance)
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

void sf_c4_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2539758087U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(898442279U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(394987238U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(739055550U);
}

mxArray *sf_c4_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("syQ5Vh2kSliCm4tyDPKGUG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[0] = (double)(4);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[4],T\"M\",},{M[1],M[6],T\"f\",},{M[8],M[0],T\"is_active_c4_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc4_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           4,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"var");
          _SFD_SET_DATA_PROPS(1,2,0,1,"f");
          _SFD_SET_DATA_PROPS(2,2,0,1,"M");
          _SFD_SET_DATA_PROPS(3,1,1,0,"omegarot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,312);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c4_f;
          real_T (*c4_var)[3];
          real_T (*c4_M)[3];
          real_T (*c4_omegarot)[4];
          c4_omegarot = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c4_M = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_f = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_var = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_var);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_f);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_M);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_omegarot);
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
  return "Tfdav4uPtTAaArjEGVgyE";
}

static void sf_opaque_initialize_c4_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_QRLsim(void *chartInstanceVar)
{
  enable_c4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_QRLsim(void *chartInstanceVar)
{
  disable_c4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_QRLsim(void *chartInstanceVar)
{
  sf_c4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_QRLsim((SFc4_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c4_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_QRLsim((SFc4_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_QRLsim(S);
}

static void sf_opaque_set_sim_state_c4_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_QRLsim(S, st);
}

static void sf_opaque_terminate_c4_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_QRLsim((SFc4_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_QRLsim((SFc4_QRLsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2737148890U));
  ssSetChecksum1(S,(40850406U));
  ssSetChecksum2(S,(3870232238U));
  ssSetChecksum3(S,(4103962197U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_QRLsim(SimStruct *S)
{
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc4_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_QRLsim;
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

void c4_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
