/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c30_QRLsim.h"
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
static const char * c30_debug_family_names[10] = { "l", "ctauf", "Gamma",
  "QRinput", "nargin", "nargout", "var", "M", "f", "fi" };

/* Function Declarations */
static void initialize_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c30_QRLsim(SFc30_QRLsimInstanceStruct
  *chartInstance);
static void enable_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance);
static void disable_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance);
static void c30_update_debugger_state_c30_QRLsim(SFc30_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c30_QRLsim(SFc30_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_st);
static void finalize_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance);
static void sf_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_fi, const char_T *c30_identifier, real_T c30_y[4]);
static void c30_b_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[4]);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_c_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_e_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_d_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[16]);
static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static void c30_info_helper(const mxArray **c30_info);
static const mxArray *c30_emlrt_marshallOut(char * c30_u);
static const mxArray *c30_b_emlrt_marshallOut(uint32_T c30_u);
static void c30_b_info_helper(const mxArray **c30_info);
static void c30_realmin(SFc30_QRLsimInstanceStruct *chartInstance);
static void c30_eps(SFc30_QRLsimInstanceStruct *chartInstance);
static void c30_eml_matlab_zgetrf(SFc30_QRLsimInstanceStruct *chartInstance,
  real_T c30_A[16], real_T c30_b_A[16], int32_T c30_ipiv[4], int32_T *c30_info);
static int32_T c30_eml_ixamax(SFc30_QRLsimInstanceStruct *chartInstance, int32_T
  c30_n, real_T c30_x[16], int32_T c30_ix0);
static void c30_check_forloop_overflow_error(SFc30_QRLsimInstanceStruct
  *chartInstance, boolean_T c30_overflow);
static void c30_eml_xger(SFc30_QRLsimInstanceStruct *chartInstance, int32_T
  c30_m, int32_T c30_n, real_T c30_alpha1, int32_T c30_ix0, int32_T c30_iy0,
  real_T c30_A[16], int32_T c30_ia0, real_T c30_b_A[16]);
static void c30_eml_warning(SFc30_QRLsimInstanceStruct *chartInstance);
static void c30_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4], real_T c30_b_B[4]);
static void c30_below_threshold(SFc30_QRLsimInstanceStruct *chartInstance);
static void c30_eml_scalar_eg(SFc30_QRLsimInstanceStruct *chartInstance);
static void c30_b_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4], real_T c30_b_B[4]);
static const mxArray *c30_f_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_e_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_f_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_b_is_active_c30_QRLsim, const char_T *c30_identifier);
static uint8_T c30_g_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_eml_matlab_zgetrf(SFc30_QRLsimInstanceStruct *chartInstance,
  real_T c30_A[16], int32_T c30_ipiv[4], int32_T *c30_info);
static void c30_b_eml_xger(SFc30_QRLsimInstanceStruct *chartInstance, int32_T
  c30_m, int32_T c30_n, real_T c30_alpha1, int32_T c30_ix0, int32_T c30_iy0,
  real_T c30_A[16], int32_T c30_ia0);
static void c30_c_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4]);
static void c30_d_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4]);
static void init_dsm_address_info(SFc30_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c30_is_active_c30_QRLsim = 0U;
}

static void initialize_params_c30_QRLsim(SFc30_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c30_update_debugger_state_c30_QRLsim(SFc30_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c30_QRLsim(SFc30_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  int32_T c30_i0;
  real_T c30_u[4];
  const mxArray *c30_b_y = NULL;
  uint8_T c30_hoistedGlobal;
  uint8_T c30_b_u;
  const mxArray *c30_c_y = NULL;
  real_T (*c30_fi)[4];
  c30_fi = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellarray(2), FALSE);
  for (c30_i0 = 0; c30_i0 < 4; c30_i0++) {
    c30_u[c30_i0] = (*c30_fi)[c30_i0];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_hoistedGlobal = chartInstance->c30_is_active_c30_QRLsim;
  c30_b_u = c30_hoistedGlobal;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  sf_mex_assign(&c30_st, c30_y, FALSE);
  return c30_st;
}

static void set_sim_state_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_st)
{
  const mxArray *c30_u;
  real_T c30_dv0[4];
  int32_T c30_i1;
  real_T (*c30_fi)[4];
  c30_fi = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c30_doneDoubleBufferReInit = TRUE;
  c30_u = sf_mex_dup(c30_st);
  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 0)), "fi",
                       c30_dv0);
  for (c30_i1 = 0; c30_i1 < 4; c30_i1++) {
    (*c30_fi)[c30_i1] = c30_dv0[c30_i1];
  }

  chartInstance->c30_is_active_c30_QRLsim = c30_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c30_u, 1)), "is_active_c30_QRLsim");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_QRLsim(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance)
{
  int32_T c30_i2;
  int32_T c30_i3;
  int32_T c30_i4;
  real_T c30_hoistedGlobal;
  int32_T c30_i5;
  real_T c30_var[2];
  int32_T c30_i6;
  real_T c30_M[3];
  real_T c30_f;
  uint32_T c30_debug_family_var_map[10];
  real_T c30_l;
  real_T c30_ctauf;
  real_T c30_Gamma[16];
  real_T c30_QRinput[4];
  real_T c30_nargin = 3.0;
  real_T c30_nargout = 1.0;
  real_T c30_fi[4];
  int32_T c30_i7;
  int32_T c30_i8;
  int32_T c30_i9;
  int32_T c30_i10;
  real_T c30_A[16];
  int32_T c30_i11;
  real_T c30_B[4];
  int32_T c30_info;
  int32_T c30_ipiv[4];
  int32_T c30_b_info;
  int32_T c30_c_info;
  int32_T c30_d_info;
  int32_T c30_i12;
  int32_T c30_i;
  int32_T c30_b_i;
  int32_T c30_ip;
  real_T c30_temp;
  int32_T c30_i13;
  real_T c30_dv1[16];
  int32_T c30_i14;
  real_T c30_dv2[16];
  int32_T c30_i15;
  real_T c30_dv3[16];
  int32_T c30_i16;
  real_T c30_dv4[16];
  int32_T c30_i17;
  real_T (*c30_b_fi)[4];
  real_T *c30_b_f;
  real_T (*c30_b_M)[3];
  real_T (*c30_b_var)[2];
  c30_b_fi = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c30_b_M = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c30_b_var = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c30_sfEvent);
  for (c30_i2 = 0; c30_i2 < 2; c30_i2++) {
    _SFD_DATA_RANGE_CHECK((*c30_b_var)[c30_i2], 0U);
  }

  for (c30_i3 = 0; c30_i3 < 3; c30_i3++) {
    _SFD_DATA_RANGE_CHECK((*c30_b_M)[c30_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c30_b_f, 2U);
  for (c30_i4 = 0; c30_i4 < 4; c30_i4++) {
    _SFD_DATA_RANGE_CHECK((*c30_b_fi)[c30_i4], 3U);
  }

  chartInstance->c30_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c30_sfEvent);
  c30_hoistedGlobal = *c30_b_f;
  for (c30_i5 = 0; c30_i5 < 2; c30_i5++) {
    c30_var[c30_i5] = (*c30_b_var)[c30_i5];
  }

  for (c30_i6 = 0; c30_i6 < 3; c30_i6++) {
    c30_M[c30_i6] = (*c30_b_M)[c30_i6];
  }

  c30_f = c30_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_l, 0U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_ctauf, 1U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_Gamma, 2U, c30_e_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_QRinput, 3U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 4U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 5U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_var, 6U, c30_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_M, 7U, c30_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_f, 8U, c30_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_fi, 9U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 4);
  c30_l = c30_var[0];
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 5);
  c30_ctauf = c30_var[1];
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 8);
  c30_i7 = 0;
  for (c30_i8 = 0; c30_i8 < 4; c30_i8++) {
    c30_Gamma[c30_i7] = 1.0;
    c30_i7 += 4;
  }

  c30_Gamma[1] = 0.0;
  c30_Gamma[5] = -c30_l;
  c30_Gamma[9] = 0.0;
  c30_Gamma[13] = c30_l;
  c30_Gamma[2] = c30_l;
  c30_Gamma[6] = 0.0;
  c30_Gamma[10] = -c30_l;
  c30_Gamma[14] = 0.0;
  c30_Gamma[3] = -c30_ctauf;
  c30_Gamma[7] = c30_ctauf;
  c30_Gamma[11] = -c30_ctauf;
  c30_Gamma[15] = c30_ctauf;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 10);
  c30_QRinput[0] = c30_f;
  for (c30_i9 = 0; c30_i9 < 3; c30_i9++) {
    c30_QRinput[c30_i9 + 1] = c30_M[c30_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 12);
  for (c30_i10 = 0; c30_i10 < 16; c30_i10++) {
    c30_A[c30_i10] = c30_Gamma[c30_i10];
  }

  for (c30_i11 = 0; c30_i11 < 4; c30_i11++) {
    c30_B[c30_i11] = c30_QRinput[c30_i11];
  }

  c30_b_eml_matlab_zgetrf(chartInstance, c30_A, c30_ipiv, &c30_info);
  c30_b_info = c30_info;
  c30_c_info = c30_b_info;
  c30_d_info = c30_c_info;
  if (c30_d_info > 0) {
    c30_eml_warning(chartInstance);
  }

  for (c30_i12 = 0; c30_i12 < 4; c30_i12++) {
    c30_fi[c30_i12] = c30_B[c30_i12];
  }

  for (c30_i = 1; c30_i < 5; c30_i++) {
    c30_b_i = c30_i;
    if (c30_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_b_i), 1, 4, 1, 0) - 1] != c30_b_i) {
      c30_ip = c30_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c30_b_i), 1, 4, 1, 0) - 1];
      c30_temp = c30_fi[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c30_b_i), 1, 4, 1, 0) - 1];
      c30_fi[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c30_b_i), 1, 4, 1, 0) - 1] = c30_fi[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c30_ip), 1, 4, 1, 0) - 1];
      c30_fi[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c30_ip), 1, 4, 1, 0) - 1] = c30_temp;
    }
  }

  for (c30_i13 = 0; c30_i13 < 16; c30_i13++) {
    c30_dv1[c30_i13] = c30_A[c30_i13];
  }

  for (c30_i14 = 0; c30_i14 < 16; c30_i14++) {
    c30_dv2[c30_i14] = c30_dv1[c30_i14];
  }

  c30_c_eml_xtrsm(chartInstance, c30_dv2, c30_fi);
  for (c30_i15 = 0; c30_i15 < 16; c30_i15++) {
    c30_dv3[c30_i15] = c30_A[c30_i15];
  }

  for (c30_i16 = 0; c30_i16 < 16; c30_i16++) {
    c30_dv4[c30_i16] = c30_dv3[c30_i16];
  }

  c30_d_eml_xtrsm(chartInstance, c30_dv4, c30_fi);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c30_i17 = 0; c30_i17 < 4; c30_i17++) {
    (*c30_b_fi)[c30_i17] = c30_fi[c30_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c30_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc30_QRLsim(SFc30_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber)
{
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i18;
  real_T c30_b_inData[4];
  int32_T c30_i19;
  real_T c30_u[4];
  const mxArray *c30_y = NULL;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  for (c30_i18 = 0; c30_i18 < 4; c30_i18++) {
    c30_b_inData[c30_i18] = (*(real_T (*)[4])c30_inData)[c30_i18];
  }

  for (c30_i19 = 0; c30_i19 < 4; c30_i19++) {
    c30_u[c30_i19] = c30_b_inData[c30_i19];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static void c30_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_fi, const char_T *c30_identifier, real_T c30_y[4])
{
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_fi), &c30_thisId, c30_y);
  sf_mex_destroy(&c30_fi);
}

static void c30_b_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[4])
{
  real_T c30_dv5[4];
  int32_T c30_i20;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv5, 1, 0, 0U, 1, 0U, 1, 4);
  for (c30_i20 = 0; c30_i20 < 4; c30_i20++) {
    c30_y[c30_i20] = c30_dv5[c30_i20];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_fi;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y[4];
  int32_T c30_i21;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_fi = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_fi), &c30_thisId, c30_y);
  sf_mex_destroy(&c30_fi);
  for (c30_i21 = 0; c30_i21 < 4; c30_i21++) {
    (*(real_T (*)[4])c30_outData)[c30_i21] = c30_y[c30_i21];
  }

  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i22;
  real_T c30_b_inData[3];
  int32_T c30_i23;
  real_T c30_u[3];
  const mxArray *c30_y = NULL;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  for (c30_i22 = 0; c30_i22 < 3; c30_i22++) {
    c30_b_inData[c30_i22] = (*(real_T (*)[3])c30_inData)[c30_i22];
  }

  for (c30_i23 = 0; c30_i23 < 3; c30_i23++) {
    c30_u[c30_i23] = c30_b_inData[c30_i23];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i24;
  real_T c30_b_inData[2];
  int32_T c30_i25;
  real_T c30_u[2];
  const mxArray *c30_y = NULL;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  for (c30_i24 = 0; c30_i24 < 2; c30_i24++) {
    c30_b_inData[c30_i24] = (*(real_T (*)[2])c30_inData)[c30_i24];
  }

  for (c30_i25 = 0; c30_i25 < 2; c30_i25++) {
    c30_u[c30_i25] = c30_b_inData[c30_i25];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static real_T c30_c_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d0, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_nargout;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_nargout = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_nargout),
    &c30_thisId);
  sf_mex_destroy(&c30_nargout);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_e_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i26;
  int32_T c30_i27;
  int32_T c30_i28;
  real_T c30_b_inData[16];
  int32_T c30_i29;
  int32_T c30_i30;
  int32_T c30_i31;
  real_T c30_u[16];
  const mxArray *c30_y = NULL;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_i26 = 0;
  for (c30_i27 = 0; c30_i27 < 4; c30_i27++) {
    for (c30_i28 = 0; c30_i28 < 4; c30_i28++) {
      c30_b_inData[c30_i28 + c30_i26] = (*(real_T (*)[16])c30_inData)[c30_i28 +
        c30_i26];
    }

    c30_i26 += 4;
  }

  c30_i29 = 0;
  for (c30_i30 = 0; c30_i30 < 4; c30_i30++) {
    for (c30_i31 = 0; c30_i31 < 4; c30_i31++) {
      c30_u[c30_i31 + c30_i29] = c30_b_inData[c30_i31 + c30_i29];
    }

    c30_i29 += 4;
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static void c30_d_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[16])
{
  real_T c30_dv6[16];
  int32_T c30_i32;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv6, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c30_i32 = 0; c30_i32 < 16; c30_i32++) {
    c30_y[c30_i32] = c30_dv6[c30_i32];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_Gamma;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y[16];
  int32_T c30_i33;
  int32_T c30_i34;
  int32_T c30_i35;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_Gamma = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_Gamma), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_Gamma);
  c30_i33 = 0;
  for (c30_i34 = 0; c30_i34 < 4; c30_i34++) {
    for (c30_i35 = 0; c30_i35 < 4; c30_i35++) {
      (*(real_T (*)[16])c30_outData)[c30_i35 + c30_i33] = c30_y[c30_i35 +
        c30_i33];
    }

    c30_i33 += 4;
  }

  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_createstruct("structure", 2, 114, 1),
                FALSE);
  c30_info_helper(&c30_nameCaptureInfo);
  c30_b_info_helper(&c30_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c30_nameCaptureInfo);
  return c30_nameCaptureInfo;
}

static void c30_info_helper(const mxArray **c30_info)
{
  const mxArray *c30_rhs0 = NULL;
  const mxArray *c30_lhs0 = NULL;
  const mxArray *c30_rhs1 = NULL;
  const mxArray *c30_lhs1 = NULL;
  const mxArray *c30_rhs2 = NULL;
  const mxArray *c30_lhs2 = NULL;
  const mxArray *c30_rhs3 = NULL;
  const mxArray *c30_lhs3 = NULL;
  const mxArray *c30_rhs4 = NULL;
  const mxArray *c30_lhs4 = NULL;
  const mxArray *c30_rhs5 = NULL;
  const mxArray *c30_lhs5 = NULL;
  const mxArray *c30_rhs6 = NULL;
  const mxArray *c30_lhs6 = NULL;
  const mxArray *c30_rhs7 = NULL;
  const mxArray *c30_lhs7 = NULL;
  const mxArray *c30_rhs8 = NULL;
  const mxArray *c30_lhs8 = NULL;
  const mxArray *c30_rhs9 = NULL;
  const mxArray *c30_lhs9 = NULL;
  const mxArray *c30_rhs10 = NULL;
  const mxArray *c30_lhs10 = NULL;
  const mxArray *c30_rhs11 = NULL;
  const mxArray *c30_lhs11 = NULL;
  const mxArray *c30_rhs12 = NULL;
  const mxArray *c30_lhs12 = NULL;
  const mxArray *c30_rhs13 = NULL;
  const mxArray *c30_lhs13 = NULL;
  const mxArray *c30_rhs14 = NULL;
  const mxArray *c30_lhs14 = NULL;
  const mxArray *c30_rhs15 = NULL;
  const mxArray *c30_lhs15 = NULL;
  const mxArray *c30_rhs16 = NULL;
  const mxArray *c30_lhs16 = NULL;
  const mxArray *c30_rhs17 = NULL;
  const mxArray *c30_lhs17 = NULL;
  const mxArray *c30_rhs18 = NULL;
  const mxArray *c30_lhs18 = NULL;
  const mxArray *c30_rhs19 = NULL;
  const mxArray *c30_lhs19 = NULL;
  const mxArray *c30_rhs20 = NULL;
  const mxArray *c30_lhs20 = NULL;
  const mxArray *c30_rhs21 = NULL;
  const mxArray *c30_lhs21 = NULL;
  const mxArray *c30_rhs22 = NULL;
  const mxArray *c30_lhs22 = NULL;
  const mxArray *c30_rhs23 = NULL;
  const mxArray *c30_lhs23 = NULL;
  const mxArray *c30_rhs24 = NULL;
  const mxArray *c30_lhs24 = NULL;
  const mxArray *c30_rhs25 = NULL;
  const mxArray *c30_lhs25 = NULL;
  const mxArray *c30_rhs26 = NULL;
  const mxArray *c30_lhs26 = NULL;
  const mxArray *c30_rhs27 = NULL;
  const mxArray *c30_lhs27 = NULL;
  const mxArray *c30_rhs28 = NULL;
  const mxArray *c30_lhs28 = NULL;
  const mxArray *c30_rhs29 = NULL;
  const mxArray *c30_lhs29 = NULL;
  const mxArray *c30_rhs30 = NULL;
  const mxArray *c30_lhs30 = NULL;
  const mxArray *c30_rhs31 = NULL;
  const mxArray *c30_lhs31 = NULL;
  const mxArray *c30_rhs32 = NULL;
  const mxArray *c30_lhs32 = NULL;
  const mxArray *c30_rhs33 = NULL;
  const mxArray *c30_lhs33 = NULL;
  const mxArray *c30_rhs34 = NULL;
  const mxArray *c30_lhs34 = NULL;
  const mxArray *c30_rhs35 = NULL;
  const mxArray *c30_lhs35 = NULL;
  const mxArray *c30_rhs36 = NULL;
  const mxArray *c30_lhs36 = NULL;
  const mxArray *c30_rhs37 = NULL;
  const mxArray *c30_lhs37 = NULL;
  const mxArray *c30_rhs38 = NULL;
  const mxArray *c30_lhs38 = NULL;
  const mxArray *c30_rhs39 = NULL;
  const mxArray *c30_lhs39 = NULL;
  const mxArray *c30_rhs40 = NULL;
  const mxArray *c30_lhs40 = NULL;
  const mxArray *c30_rhs41 = NULL;
  const mxArray *c30_lhs41 = NULL;
  const mxArray *c30_rhs42 = NULL;
  const mxArray *c30_lhs42 = NULL;
  const mxArray *c30_rhs43 = NULL;
  const mxArray *c30_lhs43 = NULL;
  const mxArray *c30_rhs44 = NULL;
  const mxArray *c30_lhs44 = NULL;
  const mxArray *c30_rhs45 = NULL;
  const mxArray *c30_lhs45 = NULL;
  const mxArray *c30_rhs46 = NULL;
  const mxArray *c30_lhs46 = NULL;
  const mxArray *c30_rhs47 = NULL;
  const mxArray *c30_lhs47 = NULL;
  const mxArray *c30_rhs48 = NULL;
  const mxArray *c30_lhs48 = NULL;
  const mxArray *c30_rhs49 = NULL;
  const mxArray *c30_lhs49 = NULL;
  const mxArray *c30_rhs50 = NULL;
  const mxArray *c30_lhs50 = NULL;
  const mxArray *c30_rhs51 = NULL;
  const mxArray *c30_lhs51 = NULL;
  const mxArray *c30_rhs52 = NULL;
  const mxArray *c30_lhs52 = NULL;
  const mxArray *c30_rhs53 = NULL;
  const mxArray *c30_lhs53 = NULL;
  const mxArray *c30_rhs54 = NULL;
  const mxArray *c30_lhs54 = NULL;
  const mxArray *c30_rhs55 = NULL;
  const mxArray *c30_lhs55 = NULL;
  const mxArray *c30_rhs56 = NULL;
  const mxArray *c30_lhs56 = NULL;
  const mxArray *c30_rhs57 = NULL;
  const mxArray *c30_lhs57 = NULL;
  const mxArray *c30_rhs58 = NULL;
  const mxArray *c30_lhs58 = NULL;
  const mxArray *c30_rhs59 = NULL;
  const mxArray *c30_lhs59 = NULL;
  const mxArray *c30_rhs60 = NULL;
  const mxArray *c30_lhs60 = NULL;
  const mxArray *c30_rhs61 = NULL;
  const mxArray *c30_lhs61 = NULL;
  const mxArray *c30_rhs62 = NULL;
  const mxArray *c30_lhs62 = NULL;
  const mxArray *c30_rhs63 = NULL;
  const mxArray *c30_lhs63 = NULL;
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("mldivide"), "name", "name",
                  0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c30_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_lusolve"), "name",
                  "name", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1309451196U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c30_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c30_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c30_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818806U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c30_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818810U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c30_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1302688994U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c30_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("realmin"), "name", "name", 7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c30_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c30_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c30_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eps"), "name", "name", 10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c30_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c30_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_eps"), "name", "name",
                  12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c30_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c30_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("min"), "name", "name", 14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c30_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c30_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c30_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1358186140U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c30_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c30_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c30_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c30_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("colon"), "name", "name", 21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1366162242U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c30_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("colon"), "name", "name", 22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1366162242U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c30_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c30_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c30_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("floor"), "name", "name", 25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c30_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c30_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 27);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c30_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 28);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmin"), "name", "name", 28);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c30_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 29);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmax"), "name", "name", 29);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c30_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 30);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmin"), "name", "name", 30);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c30_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 31);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmax"), "name", "name", 31);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c30_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 32);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 32);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 32);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818784U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c30_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 33);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 33);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170580U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c30_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 34);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c30_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 35);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c30_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 36);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmax"), "name", "name", 36);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c30_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 37);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 37);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818784U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c30_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 38);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 38);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c30_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c30_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 40);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 40);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c30_rhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 41);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmax"), "name", "name", 41);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c30_rhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 42);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c30_rhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 43);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c30_rhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 44);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c30_rhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 45);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c30_rhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 46);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c30_rhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 47);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c30_rhs47, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs47, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 48);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c30_rhs48, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs48, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 49);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c30_rhs49, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs49, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 50);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c30_rhs50, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs50, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  51);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c30_rhs51, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs51, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 52);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c30_rhs52, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs52, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold"),
                  "context", "context", 53);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("length"), "name", "name", 53);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1303146206U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c30_rhs53, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs53, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 54);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 54);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c30_rhs54, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs54, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"),
                  "context", "context", 55);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 55);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c30_rhs55, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs55, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_refblas_ixamax"), "name",
                  "name", 56);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076770U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c30_rhs56, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs56, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m"),
                  "context", "context", 57);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 57);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c30_rhs57, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs57, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  58);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818706U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c30_rhs58, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs58, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("abs"), "name", "name", 59);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c30_rhs59, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs59, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 60);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c30_rhs60, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs60, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 61);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c30_rhs61, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs61, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 62);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c30_rhs62, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs62, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 63);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 63);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c30_rhs63, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs63, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c30_rhs0);
  sf_mex_destroy(&c30_lhs0);
  sf_mex_destroy(&c30_rhs1);
  sf_mex_destroy(&c30_lhs1);
  sf_mex_destroy(&c30_rhs2);
  sf_mex_destroy(&c30_lhs2);
  sf_mex_destroy(&c30_rhs3);
  sf_mex_destroy(&c30_lhs3);
  sf_mex_destroy(&c30_rhs4);
  sf_mex_destroy(&c30_lhs4);
  sf_mex_destroy(&c30_rhs5);
  sf_mex_destroy(&c30_lhs5);
  sf_mex_destroy(&c30_rhs6);
  sf_mex_destroy(&c30_lhs6);
  sf_mex_destroy(&c30_rhs7);
  sf_mex_destroy(&c30_lhs7);
  sf_mex_destroy(&c30_rhs8);
  sf_mex_destroy(&c30_lhs8);
  sf_mex_destroy(&c30_rhs9);
  sf_mex_destroy(&c30_lhs9);
  sf_mex_destroy(&c30_rhs10);
  sf_mex_destroy(&c30_lhs10);
  sf_mex_destroy(&c30_rhs11);
  sf_mex_destroy(&c30_lhs11);
  sf_mex_destroy(&c30_rhs12);
  sf_mex_destroy(&c30_lhs12);
  sf_mex_destroy(&c30_rhs13);
  sf_mex_destroy(&c30_lhs13);
  sf_mex_destroy(&c30_rhs14);
  sf_mex_destroy(&c30_lhs14);
  sf_mex_destroy(&c30_rhs15);
  sf_mex_destroy(&c30_lhs15);
  sf_mex_destroy(&c30_rhs16);
  sf_mex_destroy(&c30_lhs16);
  sf_mex_destroy(&c30_rhs17);
  sf_mex_destroy(&c30_lhs17);
  sf_mex_destroy(&c30_rhs18);
  sf_mex_destroy(&c30_lhs18);
  sf_mex_destroy(&c30_rhs19);
  sf_mex_destroy(&c30_lhs19);
  sf_mex_destroy(&c30_rhs20);
  sf_mex_destroy(&c30_lhs20);
  sf_mex_destroy(&c30_rhs21);
  sf_mex_destroy(&c30_lhs21);
  sf_mex_destroy(&c30_rhs22);
  sf_mex_destroy(&c30_lhs22);
  sf_mex_destroy(&c30_rhs23);
  sf_mex_destroy(&c30_lhs23);
  sf_mex_destroy(&c30_rhs24);
  sf_mex_destroy(&c30_lhs24);
  sf_mex_destroy(&c30_rhs25);
  sf_mex_destroy(&c30_lhs25);
  sf_mex_destroy(&c30_rhs26);
  sf_mex_destroy(&c30_lhs26);
  sf_mex_destroy(&c30_rhs27);
  sf_mex_destroy(&c30_lhs27);
  sf_mex_destroy(&c30_rhs28);
  sf_mex_destroy(&c30_lhs28);
  sf_mex_destroy(&c30_rhs29);
  sf_mex_destroy(&c30_lhs29);
  sf_mex_destroy(&c30_rhs30);
  sf_mex_destroy(&c30_lhs30);
  sf_mex_destroy(&c30_rhs31);
  sf_mex_destroy(&c30_lhs31);
  sf_mex_destroy(&c30_rhs32);
  sf_mex_destroy(&c30_lhs32);
  sf_mex_destroy(&c30_rhs33);
  sf_mex_destroy(&c30_lhs33);
  sf_mex_destroy(&c30_rhs34);
  sf_mex_destroy(&c30_lhs34);
  sf_mex_destroy(&c30_rhs35);
  sf_mex_destroy(&c30_lhs35);
  sf_mex_destroy(&c30_rhs36);
  sf_mex_destroy(&c30_lhs36);
  sf_mex_destroy(&c30_rhs37);
  sf_mex_destroy(&c30_lhs37);
  sf_mex_destroy(&c30_rhs38);
  sf_mex_destroy(&c30_lhs38);
  sf_mex_destroy(&c30_rhs39);
  sf_mex_destroy(&c30_lhs39);
  sf_mex_destroy(&c30_rhs40);
  sf_mex_destroy(&c30_lhs40);
  sf_mex_destroy(&c30_rhs41);
  sf_mex_destroy(&c30_lhs41);
  sf_mex_destroy(&c30_rhs42);
  sf_mex_destroy(&c30_lhs42);
  sf_mex_destroy(&c30_rhs43);
  sf_mex_destroy(&c30_lhs43);
  sf_mex_destroy(&c30_rhs44);
  sf_mex_destroy(&c30_lhs44);
  sf_mex_destroy(&c30_rhs45);
  sf_mex_destroy(&c30_lhs45);
  sf_mex_destroy(&c30_rhs46);
  sf_mex_destroy(&c30_lhs46);
  sf_mex_destroy(&c30_rhs47);
  sf_mex_destroy(&c30_lhs47);
  sf_mex_destroy(&c30_rhs48);
  sf_mex_destroy(&c30_lhs48);
  sf_mex_destroy(&c30_rhs49);
  sf_mex_destroy(&c30_lhs49);
  sf_mex_destroy(&c30_rhs50);
  sf_mex_destroy(&c30_lhs50);
  sf_mex_destroy(&c30_rhs51);
  sf_mex_destroy(&c30_lhs51);
  sf_mex_destroy(&c30_rhs52);
  sf_mex_destroy(&c30_lhs52);
  sf_mex_destroy(&c30_rhs53);
  sf_mex_destroy(&c30_lhs53);
  sf_mex_destroy(&c30_rhs54);
  sf_mex_destroy(&c30_lhs54);
  sf_mex_destroy(&c30_rhs55);
  sf_mex_destroy(&c30_lhs55);
  sf_mex_destroy(&c30_rhs56);
  sf_mex_destroy(&c30_lhs56);
  sf_mex_destroy(&c30_rhs57);
  sf_mex_destroy(&c30_lhs57);
  sf_mex_destroy(&c30_rhs58);
  sf_mex_destroy(&c30_lhs58);
  sf_mex_destroy(&c30_rhs59);
  sf_mex_destroy(&c30_lhs59);
  sf_mex_destroy(&c30_rhs60);
  sf_mex_destroy(&c30_lhs60);
  sf_mex_destroy(&c30_rhs61);
  sf_mex_destroy(&c30_lhs61);
  sf_mex_destroy(&c30_rhs62);
  sf_mex_destroy(&c30_lhs62);
  sf_mex_destroy(&c30_rhs63);
  sf_mex_destroy(&c30_lhs63);
}

static const mxArray *c30_emlrt_marshallOut(char * c30_u)
{
  const mxArray *c30_y = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c30_u)), FALSE);
  return c30_y;
}

static const mxArray *c30_b_emlrt_marshallOut(uint32_T c30_u)
{
  const mxArray *c30_y = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c30_y;
}

static void c30_b_info_helper(const mxArray **c30_info)
{
  const mxArray *c30_rhs64 = NULL;
  const mxArray *c30_lhs64 = NULL;
  const mxArray *c30_rhs65 = NULL;
  const mxArray *c30_lhs65 = NULL;
  const mxArray *c30_rhs66 = NULL;
  const mxArray *c30_lhs66 = NULL;
  const mxArray *c30_rhs67 = NULL;
  const mxArray *c30_lhs67 = NULL;
  const mxArray *c30_rhs68 = NULL;
  const mxArray *c30_lhs68 = NULL;
  const mxArray *c30_rhs69 = NULL;
  const mxArray *c30_lhs69 = NULL;
  const mxArray *c30_rhs70 = NULL;
  const mxArray *c30_lhs70 = NULL;
  const mxArray *c30_rhs71 = NULL;
  const mxArray *c30_lhs71 = NULL;
  const mxArray *c30_rhs72 = NULL;
  const mxArray *c30_lhs72 = NULL;
  const mxArray *c30_rhs73 = NULL;
  const mxArray *c30_lhs73 = NULL;
  const mxArray *c30_rhs74 = NULL;
  const mxArray *c30_lhs74 = NULL;
  const mxArray *c30_rhs75 = NULL;
  const mxArray *c30_lhs75 = NULL;
  const mxArray *c30_rhs76 = NULL;
  const mxArray *c30_lhs76 = NULL;
  const mxArray *c30_rhs77 = NULL;
  const mxArray *c30_lhs77 = NULL;
  const mxArray *c30_rhs78 = NULL;
  const mxArray *c30_lhs78 = NULL;
  const mxArray *c30_rhs79 = NULL;
  const mxArray *c30_lhs79 = NULL;
  const mxArray *c30_rhs80 = NULL;
  const mxArray *c30_lhs80 = NULL;
  const mxArray *c30_rhs81 = NULL;
  const mxArray *c30_lhs81 = NULL;
  const mxArray *c30_rhs82 = NULL;
  const mxArray *c30_lhs82 = NULL;
  const mxArray *c30_rhs83 = NULL;
  const mxArray *c30_lhs83 = NULL;
  const mxArray *c30_rhs84 = NULL;
  const mxArray *c30_lhs84 = NULL;
  const mxArray *c30_rhs85 = NULL;
  const mxArray *c30_lhs85 = NULL;
  const mxArray *c30_rhs86 = NULL;
  const mxArray *c30_lhs86 = NULL;
  const mxArray *c30_rhs87 = NULL;
  const mxArray *c30_lhs87 = NULL;
  const mxArray *c30_rhs88 = NULL;
  const mxArray *c30_lhs88 = NULL;
  const mxArray *c30_rhs89 = NULL;
  const mxArray *c30_lhs89 = NULL;
  const mxArray *c30_rhs90 = NULL;
  const mxArray *c30_lhs90 = NULL;
  const mxArray *c30_rhs91 = NULL;
  const mxArray *c30_lhs91 = NULL;
  const mxArray *c30_rhs92 = NULL;
  const mxArray *c30_lhs92 = NULL;
  const mxArray *c30_rhs93 = NULL;
  const mxArray *c30_lhs93 = NULL;
  const mxArray *c30_rhs94 = NULL;
  const mxArray *c30_lhs94 = NULL;
  const mxArray *c30_rhs95 = NULL;
  const mxArray *c30_lhs95 = NULL;
  const mxArray *c30_rhs96 = NULL;
  const mxArray *c30_lhs96 = NULL;
  const mxArray *c30_rhs97 = NULL;
  const mxArray *c30_lhs97 = NULL;
  const mxArray *c30_rhs98 = NULL;
  const mxArray *c30_lhs98 = NULL;
  const mxArray *c30_rhs99 = NULL;
  const mxArray *c30_lhs99 = NULL;
  const mxArray *c30_rhs100 = NULL;
  const mxArray *c30_lhs100 = NULL;
  const mxArray *c30_rhs101 = NULL;
  const mxArray *c30_lhs101 = NULL;
  const mxArray *c30_rhs102 = NULL;
  const mxArray *c30_lhs102 = NULL;
  const mxArray *c30_rhs103 = NULL;
  const mxArray *c30_lhs103 = NULL;
  const mxArray *c30_rhs104 = NULL;
  const mxArray *c30_lhs104 = NULL;
  const mxArray *c30_rhs105 = NULL;
  const mxArray *c30_lhs105 = NULL;
  const mxArray *c30_rhs106 = NULL;
  const mxArray *c30_lhs106 = NULL;
  const mxArray *c30_rhs107 = NULL;
  const mxArray *c30_lhs107 = NULL;
  const mxArray *c30_rhs108 = NULL;
  const mxArray *c30_lhs108 = NULL;
  const mxArray *c30_rhs109 = NULL;
  const mxArray *c30_lhs109 = NULL;
  const mxArray *c30_rhs110 = NULL;
  const mxArray *c30_lhs110 = NULL;
  const mxArray *c30_rhs111 = NULL;
  const mxArray *c30_lhs111 = NULL;
  const mxArray *c30_rhs112 = NULL;
  const mxArray *c30_lhs112 = NULL;
  const mxArray *c30_rhs113 = NULL;
  const mxArray *c30_lhs113 = NULL;
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_xswap"), "name", "name",
                  64);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713874U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c30_rhs64, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs64, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 65);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c30_rhs65, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs65, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 66);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c30_rhs66, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs66, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_refblas_xswap"), "name",
                  "name", 67);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076786U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c30_rhs67, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs67, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m"),
                  "context", "context", 68);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 68);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c30_rhs68, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs68, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m"),
                  "context", "context", 69);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("abs"), "name", "name", 69);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 69);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c30_rhs69, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs69, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 70);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 70);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c30_rhs70, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs70, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 71);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 71);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c30_rhs71, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs71, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m"),
                  "context", "context", 72);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 72);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c30_rhs72, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs72, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m"),
                  "context", "context", 73);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 73);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 73);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c30_rhs73, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs73, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 74);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_div"), "name", "name",
                  74);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c30_rhs74, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs74, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 75);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  75);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713872U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c30_rhs75, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs75, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 76);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c30_rhs76, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs76, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_xger"), "name", "name",
                  77);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c30_rhs77, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs77, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 78);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c30_rhs78, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs78, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold"),
                  "context", "context", 79);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmax"), "name", "name", 79);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c30_rhs79, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs79, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold"),
                  "context", "context", 80);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("min"), "name", "name", 80);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c30_rhs80, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs80, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 81);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 81);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c30_rhs81, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs81, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 82);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 82);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1358186140U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c30_rhs82, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs82, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 83);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 83);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c30_rhs83, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs83, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 84);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 84);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c30_rhs84, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs84, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold"),
                  "context", "context", 85);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("mtimes"), "name", "name", 85);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c30_rhs85, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs85, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 86);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 86);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c30_rhs86, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs86, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 87);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c30_rhs87, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs87, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"),
                  "context", "context", 88);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_refblas_xger"), "name",
                  "name", 88);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076776U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c30_rhs88, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs88, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m"),
                  "context", "context", 89);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_refblas_xgerx"), "name",
                  "name", 89);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1360282352U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c30_rhs89, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs89, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 90);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c30_rhs90, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs90, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "context", "context", 91);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("abs"), "name", "name", 91);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 91);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c30_rhs91, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs91, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "context", "context", 92);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 92);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c30_rhs92, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs92, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "context", "context", 93);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 93);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c30_rhs93, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs93, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "context", "context", 94);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 94);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c30_rhs94, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs94, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"),
                  "context", "context", 95);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 95);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 95);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c30_rhs95, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs95, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 96);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_warning"), "name",
                  "name", 96);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 96);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818802U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c30_rhs96, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs96, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 97);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 97);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 97);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c30_rhs97, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs97, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 98);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 98);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c30_rhs98, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs98, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 99);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  99);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076778U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c30_rhs99, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs99, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 100);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 100);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c30_rhs100, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs100, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold"),
                  "context", "context", 101);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("mtimes"), "name", "name",
                  101);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c30_rhs101, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs101, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"),
                  "context", "context", 102);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 102);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c30_rhs102, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs102, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"),
                  "context", "context", 103);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 103);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 103);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c30_rhs103, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs103, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"),
                  "context", "context", 104);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_refblas_xtrsm"), "name",
                  "name", 104);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1360282352U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c30_rhs104, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs104, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 105);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 105);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c30_rhs105, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs105, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 106);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 106);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c30_rhs106, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs106, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 107);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 107);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c30_rhs107, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs107, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 108);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 108);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 108);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c30_rhs108, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs108, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 109);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 109);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 109);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c30_rhs109, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs109, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 110);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 110);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c30_rhs110, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs110, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 111);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 111);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c30_rhs111, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs111, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 112);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("intmin"), "name", "name",
                  112);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c30_rhs112, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs112, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"),
                  "context", "context", 113);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_div"), "name", "name",
                  113);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 113);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c30_rhs113, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c30_lhs113, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_destroy(&c30_rhs64);
  sf_mex_destroy(&c30_lhs64);
  sf_mex_destroy(&c30_rhs65);
  sf_mex_destroy(&c30_lhs65);
  sf_mex_destroy(&c30_rhs66);
  sf_mex_destroy(&c30_lhs66);
  sf_mex_destroy(&c30_rhs67);
  sf_mex_destroy(&c30_lhs67);
  sf_mex_destroy(&c30_rhs68);
  sf_mex_destroy(&c30_lhs68);
  sf_mex_destroy(&c30_rhs69);
  sf_mex_destroy(&c30_lhs69);
  sf_mex_destroy(&c30_rhs70);
  sf_mex_destroy(&c30_lhs70);
  sf_mex_destroy(&c30_rhs71);
  sf_mex_destroy(&c30_lhs71);
  sf_mex_destroy(&c30_rhs72);
  sf_mex_destroy(&c30_lhs72);
  sf_mex_destroy(&c30_rhs73);
  sf_mex_destroy(&c30_lhs73);
  sf_mex_destroy(&c30_rhs74);
  sf_mex_destroy(&c30_lhs74);
  sf_mex_destroy(&c30_rhs75);
  sf_mex_destroy(&c30_lhs75);
  sf_mex_destroy(&c30_rhs76);
  sf_mex_destroy(&c30_lhs76);
  sf_mex_destroy(&c30_rhs77);
  sf_mex_destroy(&c30_lhs77);
  sf_mex_destroy(&c30_rhs78);
  sf_mex_destroy(&c30_lhs78);
  sf_mex_destroy(&c30_rhs79);
  sf_mex_destroy(&c30_lhs79);
  sf_mex_destroy(&c30_rhs80);
  sf_mex_destroy(&c30_lhs80);
  sf_mex_destroy(&c30_rhs81);
  sf_mex_destroy(&c30_lhs81);
  sf_mex_destroy(&c30_rhs82);
  sf_mex_destroy(&c30_lhs82);
  sf_mex_destroy(&c30_rhs83);
  sf_mex_destroy(&c30_lhs83);
  sf_mex_destroy(&c30_rhs84);
  sf_mex_destroy(&c30_lhs84);
  sf_mex_destroy(&c30_rhs85);
  sf_mex_destroy(&c30_lhs85);
  sf_mex_destroy(&c30_rhs86);
  sf_mex_destroy(&c30_lhs86);
  sf_mex_destroy(&c30_rhs87);
  sf_mex_destroy(&c30_lhs87);
  sf_mex_destroy(&c30_rhs88);
  sf_mex_destroy(&c30_lhs88);
  sf_mex_destroy(&c30_rhs89);
  sf_mex_destroy(&c30_lhs89);
  sf_mex_destroy(&c30_rhs90);
  sf_mex_destroy(&c30_lhs90);
  sf_mex_destroy(&c30_rhs91);
  sf_mex_destroy(&c30_lhs91);
  sf_mex_destroy(&c30_rhs92);
  sf_mex_destroy(&c30_lhs92);
  sf_mex_destroy(&c30_rhs93);
  sf_mex_destroy(&c30_lhs93);
  sf_mex_destroy(&c30_rhs94);
  sf_mex_destroy(&c30_lhs94);
  sf_mex_destroy(&c30_rhs95);
  sf_mex_destroy(&c30_lhs95);
  sf_mex_destroy(&c30_rhs96);
  sf_mex_destroy(&c30_lhs96);
  sf_mex_destroy(&c30_rhs97);
  sf_mex_destroy(&c30_lhs97);
  sf_mex_destroy(&c30_rhs98);
  sf_mex_destroy(&c30_lhs98);
  sf_mex_destroy(&c30_rhs99);
  sf_mex_destroy(&c30_lhs99);
  sf_mex_destroy(&c30_rhs100);
  sf_mex_destroy(&c30_lhs100);
  sf_mex_destroy(&c30_rhs101);
  sf_mex_destroy(&c30_lhs101);
  sf_mex_destroy(&c30_rhs102);
  sf_mex_destroy(&c30_lhs102);
  sf_mex_destroy(&c30_rhs103);
  sf_mex_destroy(&c30_lhs103);
  sf_mex_destroy(&c30_rhs104);
  sf_mex_destroy(&c30_lhs104);
  sf_mex_destroy(&c30_rhs105);
  sf_mex_destroy(&c30_lhs105);
  sf_mex_destroy(&c30_rhs106);
  sf_mex_destroy(&c30_lhs106);
  sf_mex_destroy(&c30_rhs107);
  sf_mex_destroy(&c30_lhs107);
  sf_mex_destroy(&c30_rhs108);
  sf_mex_destroy(&c30_lhs108);
  sf_mex_destroy(&c30_rhs109);
  sf_mex_destroy(&c30_lhs109);
  sf_mex_destroy(&c30_rhs110);
  sf_mex_destroy(&c30_lhs110);
  sf_mex_destroy(&c30_rhs111);
  sf_mex_destroy(&c30_lhs111);
  sf_mex_destroy(&c30_rhs112);
  sf_mex_destroy(&c30_lhs112);
  sf_mex_destroy(&c30_rhs113);
  sf_mex_destroy(&c30_lhs113);
}

static void c30_realmin(SFc30_QRLsimInstanceStruct *chartInstance)
{
}

static void c30_eps(SFc30_QRLsimInstanceStruct *chartInstance)
{
}

static void c30_eml_matlab_zgetrf(SFc30_QRLsimInstanceStruct *chartInstance,
  real_T c30_A[16], real_T c30_b_A[16], int32_T c30_ipiv[4], int32_T *c30_info)
{
  int32_T c30_i36;
  for (c30_i36 = 0; c30_i36 < 16; c30_i36++) {
    c30_b_A[c30_i36] = c30_A[c30_i36];
  }

  c30_b_eml_matlab_zgetrf(chartInstance, c30_b_A, c30_ipiv, c30_info);
}

static int32_T c30_eml_ixamax(SFc30_QRLsimInstanceStruct *chartInstance, int32_T
  c30_n, real_T c30_x[16], int32_T c30_ix0)
{
  int32_T c30_idxmax;
  int32_T c30_b_n;
  int32_T c30_b_ix0;
  int32_T c30_c_n;
  int32_T c30_c_ix0;
  int32_T c30_ix;
  real_T c30_b_x;
  real_T c30_c_x;
  real_T c30_d_x;
  real_T c30_y;
  real_T c30_e_x;
  real_T c30_f_x;
  real_T c30_b_y;
  real_T c30_smax;
  int32_T c30_d_n;
  int32_T c30_b;
  int32_T c30_b_b;
  boolean_T c30_overflow;
  int32_T c30_k;
  int32_T c30_b_k;
  int32_T c30_a;
  real_T c30_g_x;
  real_T c30_h_x;
  real_T c30_i_x;
  real_T c30_c_y;
  real_T c30_j_x;
  real_T c30_k_x;
  real_T c30_d_y;
  real_T c30_s;
  c30_b_n = c30_n;
  c30_b_ix0 = c30_ix0;
  c30_c_n = c30_b_n;
  c30_c_ix0 = c30_b_ix0;
  if (c30_c_n < 1) {
    c30_idxmax = 0;
  } else {
    c30_idxmax = 1;
    if (c30_c_n > 1) {
      c30_ix = c30_c_ix0;
      c30_b_x = c30_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c30_ix), 1, 16, 1, 0) - 1];
      c30_c_x = c30_b_x;
      c30_d_x = c30_c_x;
      c30_y = muDoubleScalarAbs(c30_d_x);
      c30_e_x = 0.0;
      c30_f_x = c30_e_x;
      c30_b_y = muDoubleScalarAbs(c30_f_x);
      c30_smax = c30_y + c30_b_y;
      c30_d_n = c30_c_n;
      c30_b = c30_d_n;
      c30_b_b = c30_b;
      if (2 > c30_b_b) {
        c30_overflow = FALSE;
      } else {
        c30_overflow = (c30_b_b > 2147483646);
      }

      if (c30_overflow) {
        c30_check_forloop_overflow_error(chartInstance, c30_overflow);
      }

      for (c30_k = 2; c30_k <= c30_d_n; c30_k++) {
        c30_b_k = c30_k;
        c30_a = c30_ix + 1;
        c30_ix = c30_a;
        c30_g_x = c30_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c30_ix), 1, 16, 1, 0) - 1];
        c30_h_x = c30_g_x;
        c30_i_x = c30_h_x;
        c30_c_y = muDoubleScalarAbs(c30_i_x);
        c30_j_x = 0.0;
        c30_k_x = c30_j_x;
        c30_d_y = muDoubleScalarAbs(c30_k_x);
        c30_s = c30_c_y + c30_d_y;
        if (c30_s > c30_smax) {
          c30_idxmax = c30_b_k;
          c30_smax = c30_s;
        }
      }
    }
  }

  return c30_idxmax;
}

static void c30_check_forloop_overflow_error(SFc30_QRLsimInstanceStruct
  *chartInstance, boolean_T c30_overflow)
{
  int32_T c30_i37;
  static char_T c30_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c30_u[34];
  const mxArray *c30_y = NULL;
  int32_T c30_i38;
  static char_T c30_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c30_b_u[23];
  const mxArray *c30_b_y = NULL;
  if (!c30_overflow) {
  } else {
    for (c30_i37 = 0; c30_i37 < 34; c30_i37++) {
      c30_u[c30_i37] = c30_cv0[c30_i37];
    }

    c30_y = NULL;
    sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c30_i38 = 0; c30_i38 < 23; c30_i38++) {
      c30_b_u[c30_i38] = c30_cv1[c30_i38];
    }

    c30_b_y = NULL;
    sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c30_y, 14, c30_b_y));
  }
}

static void c30_eml_xger(SFc30_QRLsimInstanceStruct *chartInstance, int32_T
  c30_m, int32_T c30_n, real_T c30_alpha1, int32_T c30_ix0, int32_T c30_iy0,
  real_T c30_A[16], int32_T c30_ia0, real_T c30_b_A[16])
{
  int32_T c30_i39;
  for (c30_i39 = 0; c30_i39 < 16; c30_i39++) {
    c30_b_A[c30_i39] = c30_A[c30_i39];
  }

  c30_b_eml_xger(chartInstance, c30_m, c30_n, c30_alpha1, c30_ix0, c30_iy0,
                 c30_b_A, c30_ia0);
}

static void c30_eml_warning(SFc30_QRLsimInstanceStruct *chartInstance)
{
  int32_T c30_i40;
  static char_T c30_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c30_u[27];
  const mxArray *c30_y = NULL;
  for (c30_i40 = 0; c30_i40 < 27; c30_i40++) {
    c30_u[c30_i40] = c30_varargin_1[c30_i40];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c30_y));
}

static void c30_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4], real_T c30_b_B[4])
{
  int32_T c30_i41;
  int32_T c30_i42;
  real_T c30_b_A[16];
  for (c30_i41 = 0; c30_i41 < 4; c30_i41++) {
    c30_b_B[c30_i41] = c30_B[c30_i41];
  }

  for (c30_i42 = 0; c30_i42 < 16; c30_i42++) {
    c30_b_A[c30_i42] = c30_A[c30_i42];
  }

  c30_c_eml_xtrsm(chartInstance, c30_b_A, c30_b_B);
}

static void c30_below_threshold(SFc30_QRLsimInstanceStruct *chartInstance)
{
}

static void c30_eml_scalar_eg(SFc30_QRLsimInstanceStruct *chartInstance)
{
}

static void c30_b_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4], real_T c30_b_B[4])
{
  int32_T c30_i43;
  int32_T c30_i44;
  real_T c30_b_A[16];
  for (c30_i43 = 0; c30_i43 < 4; c30_i43++) {
    c30_b_B[c30_i43] = c30_B[c30_i43];
  }

  for (c30_i44 = 0; c30_i44 < 16; c30_i44++) {
    c30_b_A[c30_i44] = c30_A[c30_i44];
  }

  c30_d_eml_xtrsm(chartInstance, c30_b_A, c30_b_B);
}

static const mxArray *c30_f_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static int32_T c30_e_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i45;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i45, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i45;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_f_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_b_is_active_c30_QRLsim, const char_T *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_QRLsim), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_QRLsim);
  return c30_y;
}

static uint8_T c30_g_emlrt_marshallIn(SFc30_QRLsimInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_eml_matlab_zgetrf(SFc30_QRLsimInstanceStruct *chartInstance,
  real_T c30_A[16], int32_T c30_ipiv[4], int32_T *c30_info)
{
  int32_T c30_i46;
  int32_T c30_j;
  int32_T c30_b_j;
  int32_T c30_a;
  int32_T c30_jm1;
  int32_T c30_b;
  int32_T c30_mmj;
  int32_T c30_b_a;
  int32_T c30_c;
  int32_T c30_b_b;
  int32_T c30_jj;
  int32_T c30_c_a;
  int32_T c30_jp1j;
  int32_T c30_d_a;
  int32_T c30_b_c;
  int32_T c30_i47;
  int32_T c30_i48;
  int32_T c30_i49;
  real_T c30_b_A[16];
  int32_T c30_e_a;
  int32_T c30_jpiv_offset;
  int32_T c30_f_a;
  int32_T c30_c_b;
  int32_T c30_jpiv;
  int32_T c30_g_a;
  int32_T c30_d_b;
  int32_T c30_c_c;
  int32_T c30_e_b;
  int32_T c30_jrow;
  int32_T c30_h_a;
  int32_T c30_f_b;
  int32_T c30_jprow;
  int32_T c30_ix0;
  int32_T c30_iy0;
  int32_T c30_b_ix0;
  int32_T c30_b_iy0;
  int32_T c30_c_ix0;
  int32_T c30_c_iy0;
  int32_T c30_ix;
  int32_T c30_iy;
  int32_T c30_k;
  real_T c30_temp;
  int32_T c30_i_a;
  int32_T c30_j_a;
  int32_T c30_b_jp1j;
  int32_T c30_k_a;
  int32_T c30_d_c;
  int32_T c30_l_a;
  int32_T c30_g_b;
  int32_T c30_i50;
  int32_T c30_m_a;
  int32_T c30_h_b;
  int32_T c30_n_a;
  int32_T c30_i_b;
  boolean_T c30_overflow;
  int32_T c30_i;
  int32_T c30_b_i;
  real_T c30_x;
  real_T c30_y;
  real_T c30_z;
  int32_T c30_j_b;
  int32_T c30_e_c;
  int32_T c30_o_a;
  int32_T c30_f_c;
  int32_T c30_p_a;
  int32_T c30_g_c;
  int32_T c30_m;
  int32_T c30_n;
  int32_T c30_d_ix0;
  int32_T c30_d_iy0;
  int32_T c30_ia0;
  real_T c30_d1;
  c30_realmin(chartInstance);
  c30_eps(chartInstance);
  for (c30_i46 = 0; c30_i46 < 4; c30_i46++) {
    c30_ipiv[c30_i46] = 1 + c30_i46;
  }

  *c30_info = 0;
  for (c30_j = 1; c30_j < 4; c30_j++) {
    c30_b_j = c30_j;
    c30_a = c30_b_j - 1;
    c30_jm1 = c30_a;
    c30_b = c30_b_j;
    c30_mmj = 4 - c30_b;
    c30_b_a = c30_jm1;
    c30_c = c30_b_a * 5;
    c30_b_b = c30_c + 1;
    c30_jj = c30_b_b;
    c30_c_a = c30_jj + 1;
    c30_jp1j = c30_c_a;
    c30_d_a = c30_mmj;
    c30_b_c = c30_d_a;
    c30_i47 = 0;
    for (c30_i48 = 0; c30_i48 < 4; c30_i48++) {
      for (c30_i49 = 0; c30_i49 < 4; c30_i49++) {
        c30_b_A[c30_i49 + c30_i47] = c30_A[c30_i49 + c30_i47];
      }

      c30_i47 += 4;
    }

    c30_e_a = c30_eml_ixamax(chartInstance, c30_b_c + 1, c30_b_A, c30_jj) - 1;
    c30_jpiv_offset = c30_e_a;
    c30_f_a = c30_jj;
    c30_c_b = c30_jpiv_offset;
    c30_jpiv = c30_f_a + c30_c_b;
    if (c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if (c30_jpiv_offset != 0) {
        c30_g_a = c30_b_j;
        c30_d_b = c30_jpiv_offset;
        c30_c_c = c30_g_a + c30_d_b;
        c30_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_b_j), 1, 4, 1, 0) - 1] = c30_c_c;
        c30_e_b = c30_jm1 + 1;
        c30_jrow = c30_e_b;
        c30_h_a = c30_jrow;
        c30_f_b = c30_jpiv_offset;
        c30_jprow = c30_h_a + c30_f_b;
        c30_ix0 = c30_jrow;
        c30_iy0 = c30_jprow;
        c30_b_ix0 = c30_ix0;
        c30_b_iy0 = c30_iy0;
        c30_c_ix0 = c30_b_ix0;
        c30_c_iy0 = c30_b_iy0;
        c30_ix = c30_c_ix0;
        c30_iy = c30_c_iy0;
        for (c30_k = 1; c30_k < 5; c30_k++) {
          c30_temp = c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c30_ix), 1, 16, 1, 0) - 1];
          c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c30_ix), 1, 16, 1, 0) - 1] =
            c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c30_iy), 1, 16, 1, 0) - 1];
          c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c30_iy), 1, 16, 1, 0) - 1] = c30_temp;
          c30_i_a = c30_ix + 4;
          c30_ix = c30_i_a;
          c30_j_a = c30_iy + 4;
          c30_iy = c30_j_a;
        }
      }

      c30_b_jp1j = c30_jp1j;
      c30_k_a = c30_mmj;
      c30_d_c = c30_k_a;
      c30_l_a = c30_jp1j;
      c30_g_b = c30_d_c - 1;
      c30_i50 = c30_l_a + c30_g_b;
      c30_m_a = c30_b_jp1j;
      c30_h_b = c30_i50;
      c30_n_a = c30_m_a;
      c30_i_b = c30_h_b;
      if (c30_n_a > c30_i_b) {
        c30_overflow = FALSE;
      } else {
        c30_overflow = (c30_i_b > 2147483646);
      }

      if (c30_overflow) {
        c30_check_forloop_overflow_error(chartInstance, c30_overflow);
      }

      for (c30_i = c30_b_jp1j; c30_i <= c30_i50; c30_i++) {
        c30_b_i = c30_i;
        c30_x = c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c30_b_i), 1, 16, 1, 0) - 1];
        c30_y = c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c30_jj), 1, 16, 1, 0) - 1];
        c30_z = c30_x / c30_y;
        c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_b_i), 1, 16, 1, 0) - 1] = c30_z;
      }
    } else {
      *c30_info = c30_b_j;
    }

    c30_j_b = c30_b_j;
    c30_e_c = 4 - c30_j_b;
    c30_o_a = c30_jj;
    c30_f_c = c30_o_a;
    c30_p_a = c30_jj;
    c30_g_c = c30_p_a;
    c30_m = c30_mmj;
    c30_n = c30_e_c;
    c30_d_ix0 = c30_jp1j;
    c30_d_iy0 = c30_f_c + 4;
    c30_ia0 = c30_g_c + 5;
    c30_d1 = -1.0;
    c30_b_eml_xger(chartInstance, c30_m, c30_n, c30_d1, c30_d_ix0, c30_d_iy0,
                   c30_A, c30_ia0);
  }

  if (*c30_info == 0) {
    if (!(c30_A[15] != 0.0)) {
      *c30_info = 4;
    }
  }
}

static void c30_b_eml_xger(SFc30_QRLsimInstanceStruct *chartInstance, int32_T
  c30_m, int32_T c30_n, real_T c30_alpha1, int32_T c30_ix0, int32_T c30_iy0,
  real_T c30_A[16], int32_T c30_ia0)
{
  int32_T c30_b_m;
  int32_T c30_b_n;
  real_T c30_b_alpha1;
  int32_T c30_b_ix0;
  int32_T c30_b_iy0;
  int32_T c30_b_ia0;
  int32_T c30_c_m;
  int32_T c30_c_n;
  real_T c30_c_alpha1;
  int32_T c30_c_ix0;
  int32_T c30_c_iy0;
  int32_T c30_c_ia0;
  int32_T c30_d_m;
  int32_T c30_d_n;
  real_T c30_d_alpha1;
  int32_T c30_d_ix0;
  int32_T c30_d_iy0;
  int32_T c30_d_ia0;
  int32_T c30_ixstart;
  int32_T c30_a;
  int32_T c30_jA;
  int32_T c30_jy;
  int32_T c30_e_n;
  int32_T c30_b;
  int32_T c30_b_b;
  boolean_T c30_overflow;
  int32_T c30_j;
  real_T c30_yjy;
  real_T c30_temp;
  int32_T c30_ix;
  int32_T c30_c_b;
  int32_T c30_i51;
  int32_T c30_b_a;
  int32_T c30_d_b;
  int32_T c30_i52;
  int32_T c30_c_a;
  int32_T c30_e_b;
  int32_T c30_d_a;
  int32_T c30_f_b;
  boolean_T c30_b_overflow;
  int32_T c30_ijA;
  int32_T c30_b_ijA;
  int32_T c30_e_a;
  int32_T c30_f_a;
  int32_T c30_g_a;
  c30_b_m = c30_m;
  c30_b_n = c30_n;
  c30_b_alpha1 = c30_alpha1;
  c30_b_ix0 = c30_ix0;
  c30_b_iy0 = c30_iy0;
  c30_b_ia0 = c30_ia0;
  c30_c_m = c30_b_m;
  c30_c_n = c30_b_n;
  c30_c_alpha1 = c30_b_alpha1;
  c30_c_ix0 = c30_b_ix0;
  c30_c_iy0 = c30_b_iy0;
  c30_c_ia0 = c30_b_ia0;
  c30_d_m = c30_c_m;
  c30_d_n = c30_c_n;
  c30_d_alpha1 = c30_c_alpha1;
  c30_d_ix0 = c30_c_ix0;
  c30_d_iy0 = c30_c_iy0;
  c30_d_ia0 = c30_c_ia0;
  if (c30_d_alpha1 == 0.0) {
  } else {
    c30_ixstart = c30_d_ix0;
    c30_a = c30_d_ia0 - 1;
    c30_jA = c30_a;
    c30_jy = c30_d_iy0;
    c30_e_n = c30_d_n;
    c30_b = c30_e_n;
    c30_b_b = c30_b;
    if (1 > c30_b_b) {
      c30_overflow = FALSE;
    } else {
      c30_overflow = (c30_b_b > 2147483646);
    }

    if (c30_overflow) {
      c30_check_forloop_overflow_error(chartInstance, c30_overflow);
    }

    for (c30_j = 1; c30_j <= c30_e_n; c30_j++) {
      c30_yjy = c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c30_jy), 1, 16, 1, 0) - 1];
      if (c30_yjy != 0.0) {
        c30_temp = c30_yjy * c30_d_alpha1;
        c30_ix = c30_ixstart;
        c30_c_b = c30_jA + 1;
        c30_i51 = c30_c_b;
        c30_b_a = c30_d_m;
        c30_d_b = c30_jA;
        c30_i52 = c30_b_a + c30_d_b;
        c30_c_a = c30_i51;
        c30_e_b = c30_i52;
        c30_d_a = c30_c_a;
        c30_f_b = c30_e_b;
        if (c30_d_a > c30_f_b) {
          c30_b_overflow = FALSE;
        } else {
          c30_b_overflow = (c30_f_b > 2147483646);
        }

        if (c30_b_overflow) {
          c30_check_forloop_overflow_error(chartInstance, c30_b_overflow);
        }

        for (c30_ijA = c30_i51; c30_ijA <= c30_i52; c30_ijA++) {
          c30_b_ijA = c30_ijA;
          c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c30_b_ijA), 1, 16, 1, 0) - 1] =
            c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c30_b_ijA), 1, 16, 1, 0) - 1] +
            c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c30_ix), 1, 16, 1, 0) - 1] * c30_temp;
          c30_e_a = c30_ix + 1;
          c30_ix = c30_e_a;
        }
      }

      c30_f_a = c30_jy + 4;
      c30_jy = c30_f_a;
      c30_g_a = c30_jA + 4;
      c30_jA = c30_g_a;
    }
  }
}

static void c30_c_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4])
{
  int32_T c30_k;
  int32_T c30_b_k;
  int32_T c30_a;
  int32_T c30_c;
  int32_T c30_b;
  int32_T c30_b_c;
  int32_T c30_b_b;
  int32_T c30_kAcol;
  int32_T c30_b_a;
  int32_T c30_c_c;
  int32_T c30_c_a;
  int32_T c30_i53;
  boolean_T c30_overflow;
  int32_T c30_i;
  int32_T c30_b_i;
  int32_T c30_d_a;
  int32_T c30_d_c;
  int32_T c30_e_a;
  int32_T c30_e_c;
  int32_T c30_f_a;
  int32_T c30_f_c;
  int32_T c30_g_a;
  int32_T c30_c_b;
  int32_T c30_g_c;
  c30_below_threshold(chartInstance);
  c30_eml_scalar_eg(chartInstance);
  for (c30_k = 1; c30_k < 5; c30_k++) {
    c30_b_k = c30_k;
    c30_a = c30_b_k;
    c30_c = c30_a;
    c30_b = c30_c - 1;
    c30_b_c = c30_b << 2;
    c30_b_b = c30_b_c;
    c30_kAcol = c30_b_b;
    c30_b_a = c30_b_k;
    c30_c_c = c30_b_a;
    if (c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_c_c), 1, 4, 1, 0) - 1] != 0.0) {
      c30_c_a = c30_b_k;
      c30_i53 = c30_c_a;
      c30_overflow = FALSE;
      if (c30_overflow) {
        c30_check_forloop_overflow_error(chartInstance, c30_overflow);
      }

      for (c30_i = c30_i53 + 1; c30_i < 5; c30_i++) {
        c30_b_i = c30_i;
        c30_d_a = c30_b_i;
        c30_d_c = c30_d_a;
        c30_e_a = c30_b_i;
        c30_e_c = c30_e_a;
        c30_f_a = c30_b_k;
        c30_f_c = c30_f_a;
        c30_g_a = c30_b_i;
        c30_c_b = c30_kAcol;
        c30_g_c = c30_g_a + c30_c_b;
        c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_d_c), 1, 4, 1, 0) - 1] = c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c30_e_c), 1, 4, 1, 0) - 1]
          - c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_f_c), 1, 4, 1, 0) - 1] * c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c30_g_c), 1, 16, 1, 0) -
          1];
      }
    }
  }
}

static void c30_d_eml_xtrsm(SFc30_QRLsimInstanceStruct *chartInstance, real_T
  c30_A[16], real_T c30_B[4])
{
  int32_T c30_k;
  int32_T c30_b_k;
  int32_T c30_a;
  int32_T c30_c;
  int32_T c30_b;
  int32_T c30_b_c;
  int32_T c30_b_b;
  int32_T c30_kAcol;
  int32_T c30_b_a;
  int32_T c30_c_c;
  int32_T c30_c_a;
  int32_T c30_d_c;
  int32_T c30_d_a;
  int32_T c30_e_c;
  int32_T c30_e_a;
  int32_T c30_c_b;
  int32_T c30_f_c;
  real_T c30_x;
  real_T c30_y;
  real_T c30_z;
  int32_T c30_f_a;
  int32_T c30_i54;
  int32_T c30_d_b;
  int32_T c30_e_b;
  boolean_T c30_overflow;
  int32_T c30_i;
  int32_T c30_b_i;
  int32_T c30_g_a;
  int32_T c30_g_c;
  int32_T c30_h_a;
  int32_T c30_h_c;
  int32_T c30_i_a;
  int32_T c30_i_c;
  int32_T c30_j_a;
  int32_T c30_f_b;
  int32_T c30_j_c;
  c30_below_threshold(chartInstance);
  c30_eml_scalar_eg(chartInstance);
  for (c30_k = 4; c30_k > 0; c30_k--) {
    c30_b_k = c30_k;
    c30_a = c30_b_k;
    c30_c = c30_a;
    c30_b = c30_c - 1;
    c30_b_c = c30_b << 2;
    c30_b_b = c30_b_c;
    c30_kAcol = c30_b_b;
    c30_b_a = c30_b_k;
    c30_c_c = c30_b_a;
    if (c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_c_c), 1, 4, 1, 0) - 1] != 0.0) {
      c30_c_a = c30_b_k;
      c30_d_c = c30_c_a;
      c30_d_a = c30_b_k;
      c30_e_c = c30_d_a;
      c30_e_a = c30_b_k;
      c30_c_b = c30_kAcol;
      c30_f_c = c30_e_a + c30_c_b;
      c30_x = c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c30_e_c), 1, 4, 1, 0) - 1];
      c30_y = c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c30_f_c), 1, 16, 1, 0) - 1];
      c30_z = c30_x / c30_y;
      c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c30_d_c), 1, 4, 1, 0) - 1] = c30_z;
      c30_f_a = c30_b_k - 1;
      c30_i54 = c30_f_a;
      c30_d_b = c30_i54;
      c30_e_b = c30_d_b;
      if (1 > c30_e_b) {
        c30_overflow = FALSE;
      } else {
        c30_overflow = (c30_e_b > 2147483646);
      }

      if (c30_overflow) {
        c30_check_forloop_overflow_error(chartInstance, c30_overflow);
      }

      for (c30_i = 1; c30_i <= c30_i54; c30_i++) {
        c30_b_i = c30_i;
        c30_g_a = c30_b_i;
        c30_g_c = c30_g_a;
        c30_h_a = c30_b_i;
        c30_h_c = c30_h_a;
        c30_i_a = c30_b_k;
        c30_i_c = c30_i_a;
        c30_j_a = c30_b_i;
        c30_f_b = c30_kAcol;
        c30_j_c = c30_j_a + c30_f_b;
        c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_g_c), 1, 4, 1, 0) - 1] = c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c30_h_c), 1, 4, 1, 0) - 1]
          - c30_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c30_i_c), 1, 4, 1, 0) - 1] * c30_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c30_j_c), 1, 16, 1, 0) -
          1];
      }
    }
  }
}

static void init_dsm_address_info(SFc30_QRLsimInstanceStruct *chartInstance)
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

void sf_c30_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1088589834U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2095696544U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3852442086U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(892516349U);
}

mxArray *sf_c30_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("q2CqQe92rdVzXTlgmCJdpB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c30_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c30_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c30_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fi\",},{M[8],M[0],T\"is_active_c30_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc30_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           30,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"M");
          _SFD_SET_DATA_PROPS(2,1,1,0,"f");
          _SFD_SET_DATA_PROPS(3,2,0,1,"fi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,241);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        {
          real_T *c30_f;
          real_T (*c30_var)[2];
          real_T (*c30_M)[3];
          real_T (*c30_fi)[4];
          c30_fi = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c30_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c30_M = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c30_var = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c30_var);
          _SFD_SET_DATA_VALUE_PTR(1U, *c30_M);
          _SFD_SET_DATA_VALUE_PTR(2U, c30_f);
          _SFD_SET_DATA_VALUE_PTR(3U, *c30_fi);
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
  return "ckEYUW0PQXLSZxjIAFietG";
}

static void sf_opaque_initialize_c30_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c30_QRLsim(void *chartInstanceVar)
{
  enable_c30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c30_QRLsim(void *chartInstanceVar)
{
  disable_c30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c30_QRLsim(void *chartInstanceVar)
{
  sf_c30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c30_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c30_QRLsim((SFc30_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c30_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c30_QRLsim((SFc30_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c30_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c30_QRLsim(S);
}

static void sf_opaque_set_sim_state_c30_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c30_QRLsim(S, st);
}

static void sf_opaque_terminate_c30_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc30_QRLsim((SFc30_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c30_QRLsim((SFc30_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,30,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,30);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,30,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,30,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3327867329U));
  ssSetChecksum1(S,(4058504374U));
  ssSetChecksum2(S,(139416767U));
  ssSetChecksum3(S,(1726048436U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c30_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_QRLsim(SimStruct *S)
{
  SFc30_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc30_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc30_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c30_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c30_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c30_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c30_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c30_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c30_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c30_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c30_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c30_QRLsim;
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

void c30_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
