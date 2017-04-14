/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c32_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c32_debug_family_names[13] = { "mQ", "g", "mL", "lL", "e3",
  "nargin", "nargout", "varddxL", "dq", "q", "R", "f", "ddxL" };

/* Function Declarations */
static void initialize_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c32_QRLsim(SFc32_QRLsimInstanceStruct
  *chartInstance);
static void enable_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void disable_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void c32_update_debugger_state_c32_QRLsim(SFc32_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c32_QRLsim(SFc32_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_st);
static void finalize_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void sf_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void c32_chartstep_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber);
static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_ddxL, const char_T *c32_identifier, real_T c32_y[3]);
static void c32_b_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId, real_T c32_y[3]);
static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static const mxArray *c32_e_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static real_T c32_c_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static void c32_info_helper(const mxArray **c32_info);
static const mxArray *c32_emlrt_marshallOut(char * c32_u);
static const mxArray *c32_b_emlrt_marshallOut(uint32_T c32_u);
static void c32_eml_scalar_eg(SFc32_QRLsimInstanceStruct *chartInstance);
static real_T c32_dot(SFc32_QRLsimInstanceStruct *chartInstance, real_T c32_a[3],
                      real_T c32_b[3]);
static void c32_b_eml_scalar_eg(SFc32_QRLsimInstanceStruct *chartInstance);
static const mxArray *c32_f_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static int32_T c32_d_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static uint8_T c32_e_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_b_is_active_c32_QRLsim, const char_T *c32_identifier);
static uint8_T c32_f_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void init_dsm_address_info(SFc32_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c32_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c32_is_active_c32_QRLsim = 0U;
}

static void initialize_params_c32_QRLsim(SFc32_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c32_update_debugger_state_c32_QRLsim(SFc32_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c32_QRLsim(SFc32_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c32_st;
  const mxArray *c32_y = NULL;
  int32_T c32_i0;
  real_T c32_u[3];
  const mxArray *c32_b_y = NULL;
  uint8_T c32_hoistedGlobal;
  uint8_T c32_b_u;
  const mxArray *c32_c_y = NULL;
  real_T (*c32_ddxL)[3];
  c32_ddxL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c32_st = NULL;
  c32_st = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createcellarray(2), FALSE);
  for (c32_i0 = 0; c32_i0 < 3; c32_i0++) {
    c32_u[c32_i0] = (*c32_ddxL)[c32_i0];
  }

  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c32_y, 0, c32_b_y);
  c32_hoistedGlobal = chartInstance->c32_is_active_c32_QRLsim;
  c32_b_u = c32_hoistedGlobal;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c32_y, 1, c32_c_y);
  sf_mex_assign(&c32_st, c32_y, FALSE);
  return c32_st;
}

static void set_sim_state_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_st)
{
  const mxArray *c32_u;
  real_T c32_dv0[3];
  int32_T c32_i1;
  real_T (*c32_ddxL)[3];
  c32_ddxL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c32_doneDoubleBufferReInit = TRUE;
  c32_u = sf_mex_dup(c32_st);
  c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 0)),
                       "ddxL", c32_dv0);
  for (c32_i1 = 0; c32_i1 < 3; c32_i1++) {
    (*c32_ddxL)[c32_i1] = c32_dv0[c32_i1];
  }

  chartInstance->c32_is_active_c32_QRLsim = c32_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c32_u, 1)), "is_active_c32_QRLsim");
  sf_mex_destroy(&c32_u);
  c32_update_debugger_state_c32_QRLsim(chartInstance);
  sf_mex_destroy(&c32_st);
}

static void finalize_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
  int32_T c32_i2;
  int32_T c32_i3;
  int32_T c32_i4;
  int32_T c32_i5;
  int32_T c32_i6;
  real_T *c32_f;
  real_T (*c32_R)[9];
  real_T (*c32_q)[3];
  real_T (*c32_ddxL)[3];
  real_T (*c32_dq)[3];
  real_T (*c32_varddxL)[4];
  c32_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c32_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 3);
  c32_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c32_ddxL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c32_dq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c32_varddxL = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c32_sfEvent);
  for (c32_i2 = 0; c32_i2 < 4; c32_i2++) {
    _SFD_DATA_RANGE_CHECK((*c32_varddxL)[c32_i2], 0U);
  }

  for (c32_i3 = 0; c32_i3 < 3; c32_i3++) {
    _SFD_DATA_RANGE_CHECK((*c32_dq)[c32_i3], 1U);
  }

  for (c32_i4 = 0; c32_i4 < 3; c32_i4++) {
    _SFD_DATA_RANGE_CHECK((*c32_ddxL)[c32_i4], 2U);
  }

  for (c32_i5 = 0; c32_i5 < 3; c32_i5++) {
    _SFD_DATA_RANGE_CHECK((*c32_q)[c32_i5], 3U);
  }

  for (c32_i6 = 0; c32_i6 < 9; c32_i6++) {
    _SFD_DATA_RANGE_CHECK((*c32_R)[c32_i6], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c32_f, 5U);
  chartInstance->c32_sfEvent = CALL_EVENT;
  c32_chartstep_c32_QRLsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c32_chartstep_c32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
  real_T c32_hoistedGlobal;
  int32_T c32_i7;
  real_T c32_varddxL[4];
  int32_T c32_i8;
  real_T c32_dq[3];
  int32_T c32_i9;
  real_T c32_q[3];
  int32_T c32_i10;
  real_T c32_R[9];
  real_T c32_f;
  uint32_T c32_debug_family_var_map[13];
  real_T c32_mQ;
  real_T c32_g;
  real_T c32_mL;
  real_T c32_lL;
  real_T c32_e3[3];
  real_T c32_nargin = 5.0;
  real_T c32_nargout = 1.0;
  real_T c32_ddxL[3];
  int32_T c32_i11;
  static real_T c32_b[3] = { 0.0, 0.0, 1.0 };

  real_T c32_a;
  int32_T c32_i12;
  real_T c32_b_b[9];
  int32_T c32_i13;
  int32_T c32_i14;
  real_T c32_y[3];
  int32_T c32_i15;
  int32_T c32_i16;
  real_T c32_b_a;
  real_T c32_c_b;
  real_T c32_b_y;
  real_T c32_c_a;
  int32_T c32_i17;
  real_T c32_b_dq[3];
  int32_T c32_i18;
  real_T c32_c_dq[3];
  real_T c32_d_b;
  real_T c32_c_y;
  int32_T c32_i19;
  real_T c32_b_q[3];
  int32_T c32_i20;
  real_T c32_d_y[3];
  real_T c32_d_a;
  int32_T c32_i21;
  real_T c32_e_b[3];
  int32_T c32_i22;
  real_T c32_B;
  real_T c32_e_y;
  real_T c32_f_y;
  int32_T c32_i23;
  real_T c32_e_a;
  int32_T c32_i24;
  int32_T c32_i25;
  int32_T c32_i26;
  real_T *c32_b_f;
  real_T (*c32_b_ddxL)[3];
  real_T (*c32_b_R)[9];
  real_T (*c32_c_q)[3];
  real_T (*c32_d_dq)[3];
  real_T (*c32_b_varddxL)[4];
  c32_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c32_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 3);
  c32_c_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c32_b_ddxL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c32_d_dq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c32_b_varddxL = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c32_sfEvent);
  c32_hoistedGlobal = *c32_b_f;
  for (c32_i7 = 0; c32_i7 < 4; c32_i7++) {
    c32_varddxL[c32_i7] = (*c32_b_varddxL)[c32_i7];
  }

  for (c32_i8 = 0; c32_i8 < 3; c32_i8++) {
    c32_dq[c32_i8] = (*c32_d_dq)[c32_i8];
  }

  for (c32_i9 = 0; c32_i9 < 3; c32_i9++) {
    c32_q[c32_i9] = (*c32_c_q)[c32_i9];
  }

  for (c32_i10 = 0; c32_i10 < 9; c32_i10++) {
    c32_R[c32_i10] = (*c32_b_R)[c32_i10];
  }

  c32_f = c32_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c32_debug_family_names,
    c32_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_mQ, 0U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_g, 1U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_mL, 2U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_lL, 3U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_e3, 4U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargin, 5U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargout, 6U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_varddxL, 7U, c32_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_dq, 8U, c32_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_q, 9U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_R, 10U, c32_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_f, 11U, c32_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c32_ddxL, 12U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 3);
  c32_mQ = c32_varddxL[0];
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 4);
  c32_g = c32_varddxL[1];
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 5);
  c32_mL = c32_varddxL[2];
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 6);
  c32_lL = c32_varddxL[3];
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 8);
  for (c32_i11 = 0; c32_i11 < 3; c32_i11++) {
    c32_e3[c32_i11] = c32_b[c32_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 12);
  c32_a = c32_f;
  for (c32_i12 = 0; c32_i12 < 9; c32_i12++) {
    c32_b_b[c32_i12] = c32_R[c32_i12];
  }

  for (c32_i13 = 0; c32_i13 < 9; c32_i13++) {
    c32_b_b[c32_i13] *= c32_a;
  }

  c32_eml_scalar_eg(chartInstance);
  c32_eml_scalar_eg(chartInstance);
  for (c32_i14 = 0; c32_i14 < 3; c32_i14++) {
    c32_y[c32_i14] = 0.0;
    c32_i15 = 0;
    for (c32_i16 = 0; c32_i16 < 3; c32_i16++) {
      c32_y[c32_i14] += c32_b_b[c32_i15 + c32_i14] * c32_b[c32_i16];
      c32_i15 += 3;
    }
  }

  c32_b_a = c32_mQ;
  c32_c_b = c32_lL;
  c32_b_y = c32_b_a * c32_c_b;
  c32_c_a = c32_b_y;
  for (c32_i17 = 0; c32_i17 < 3; c32_i17++) {
    c32_b_dq[c32_i17] = c32_dq[c32_i17];
  }

  for (c32_i18 = 0; c32_i18 < 3; c32_i18++) {
    c32_c_dq[c32_i18] = c32_dq[c32_i18];
  }

  c32_d_b = c32_dot(chartInstance, c32_b_dq, c32_c_dq);
  c32_c_y = c32_c_a * c32_d_b;
  for (c32_i19 = 0; c32_i19 < 3; c32_i19++) {
    c32_b_q[c32_i19] = c32_q[c32_i19];
  }

  for (c32_i20 = 0; c32_i20 < 3; c32_i20++) {
    c32_d_y[c32_i20] = c32_y[c32_i20];
  }

  c32_d_a = c32_dot(chartInstance, c32_b_q, c32_d_y) - c32_c_y;
  for (c32_i21 = 0; c32_i21 < 3; c32_i21++) {
    c32_e_b[c32_i21] = c32_q[c32_i21];
  }

  for (c32_i22 = 0; c32_i22 < 3; c32_i22++) {
    c32_e_b[c32_i22] *= c32_d_a;
  }

  c32_B = c32_mQ + c32_mL;
  c32_e_y = c32_B;
  c32_f_y = c32_e_y;
  for (c32_i23 = 0; c32_i23 < 3; c32_i23++) {
    c32_e_b[c32_i23] /= c32_f_y;
  }

  c32_e_a = c32_g;
  for (c32_i24 = 0; c32_i24 < 3; c32_i24++) {
    c32_y[c32_i24] = c32_e_a * c32_b[c32_i24];
  }

  for (c32_i25 = 0; c32_i25 < 3; c32_i25++) {
    c32_ddxL[c32_i25] = c32_e_b[c32_i25] - c32_y[c32_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c32_i26 = 0; c32_i26 < 3; c32_i26++) {
    (*c32_b_ddxL)[c32_i26] = c32_ddxL[c32_i26];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c32_sfEvent);
}

static void initSimStructsc32_QRLsim(SFc32_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber)
{
}

static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i27;
  real_T c32_b_inData[3];
  int32_T c32_i28;
  real_T c32_u[3];
  const mxArray *c32_y = NULL;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i27 = 0; c32_i27 < 3; c32_i27++) {
    c32_b_inData[c32_i27] = (*(real_T (*)[3])c32_inData)[c32_i27];
  }

  for (c32_i28 = 0; c32_i28 < 3; c32_i28++) {
    c32_u[c32_i28] = c32_b_inData[c32_i28];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static void c32_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_ddxL, const char_T *c32_identifier, real_T c32_y[3])
{
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_ddxL), &c32_thisId, c32_y);
  sf_mex_destroy(&c32_ddxL);
}

static void c32_b_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId, real_T c32_y[3])
{
  real_T c32_dv1[3];
  int32_T c32_i29;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), c32_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c32_i29 = 0; c32_i29 < 3; c32_i29++) {
    c32_y[c32_i29] = c32_dv1[c32_i29];
  }

  sf_mex_destroy(&c32_u);
}

static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_ddxL;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y[3];
  int32_T c32_i30;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_ddxL = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_ddxL), &c32_thisId, c32_y);
  sf_mex_destroy(&c32_ddxL);
  for (c32_i30 = 0; c32_i30 < 3; c32_i30++) {
    (*(real_T (*)[3])c32_outData)[c32_i30] = c32_y[c32_i30];
  }

  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  real_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(real_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i31;
  int32_T c32_i32;
  int32_T c32_i33;
  real_T c32_b_inData[9];
  int32_T c32_i34;
  int32_T c32_i35;
  int32_T c32_i36;
  real_T c32_u[9];
  const mxArray *c32_y = NULL;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_i31 = 0;
  for (c32_i32 = 0; c32_i32 < 3; c32_i32++) {
    for (c32_i33 = 0; c32_i33 < 3; c32_i33++) {
      c32_b_inData[c32_i33 + c32_i31] = (*(real_T (*)[9])c32_inData)[c32_i33 +
        c32_i31];
    }

    c32_i31 += 3;
  }

  c32_i34 = 0;
  for (c32_i35 = 0; c32_i35 < 3; c32_i35++) {
    for (c32_i36 = 0; c32_i36 < 3; c32_i36++) {
      c32_u[c32_i36 + c32_i34] = c32_b_inData[c32_i36 + c32_i34];
    }

    c32_i34 += 3;
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i37;
  real_T c32_b_inData[3];
  int32_T c32_i38;
  real_T c32_u[3];
  const mxArray *c32_y = NULL;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i37 = 0; c32_i37 < 3; c32_i37++) {
    c32_b_inData[c32_i37] = (*(real_T (*)[3])c32_inData)[c32_i37];
  }

  for (c32_i38 = 0; c32_i38 < 3; c32_i38++) {
    c32_u[c32_i38] = c32_b_inData[c32_i38];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static const mxArray *c32_e_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i39;
  real_T c32_b_inData[4];
  int32_T c32_i40;
  real_T c32_u[4];
  const mxArray *c32_y = NULL;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i39 = 0; c32_i39 < 4; c32_i39++) {
    c32_b_inData[c32_i39] = (*(real_T (*)[4])c32_inData)[c32_i39];
  }

  for (c32_i40 = 0; c32_i40 < 4; c32_i40++) {
    c32_u[c32_i40] = c32_b_inData[c32_i40];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static real_T c32_c_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  real_T c32_y;
  real_T c32_d0;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_d0, 1, 0, 0U, 0, 0U, 0);
  c32_y = c32_d0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_nargout;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_nargout = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_nargout),
    &c32_thisId);
  sf_mex_destroy(&c32_nargout);
  *(real_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

const mxArray *sf_c32_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c32_nameCaptureInfo = NULL;
  c32_nameCaptureInfo = NULL;
  sf_mex_assign(&c32_nameCaptureInfo, sf_mex_createstruct("structure", 2, 40, 1),
                FALSE);
  c32_info_helper(&c32_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c32_nameCaptureInfo);
  return c32_nameCaptureInfo;
}

static void c32_info_helper(const mxArray **c32_info)
{
  const mxArray *c32_rhs0 = NULL;
  const mxArray *c32_lhs0 = NULL;
  const mxArray *c32_rhs1 = NULL;
  const mxArray *c32_lhs1 = NULL;
  const mxArray *c32_rhs2 = NULL;
  const mxArray *c32_lhs2 = NULL;
  const mxArray *c32_rhs3 = NULL;
  const mxArray *c32_lhs3 = NULL;
  const mxArray *c32_rhs4 = NULL;
  const mxArray *c32_lhs4 = NULL;
  const mxArray *c32_rhs5 = NULL;
  const mxArray *c32_lhs5 = NULL;
  const mxArray *c32_rhs6 = NULL;
  const mxArray *c32_lhs6 = NULL;
  const mxArray *c32_rhs7 = NULL;
  const mxArray *c32_lhs7 = NULL;
  const mxArray *c32_rhs8 = NULL;
  const mxArray *c32_lhs8 = NULL;
  const mxArray *c32_rhs9 = NULL;
  const mxArray *c32_lhs9 = NULL;
  const mxArray *c32_rhs10 = NULL;
  const mxArray *c32_lhs10 = NULL;
  const mxArray *c32_rhs11 = NULL;
  const mxArray *c32_lhs11 = NULL;
  const mxArray *c32_rhs12 = NULL;
  const mxArray *c32_lhs12 = NULL;
  const mxArray *c32_rhs13 = NULL;
  const mxArray *c32_lhs13 = NULL;
  const mxArray *c32_rhs14 = NULL;
  const mxArray *c32_lhs14 = NULL;
  const mxArray *c32_rhs15 = NULL;
  const mxArray *c32_lhs15 = NULL;
  const mxArray *c32_rhs16 = NULL;
  const mxArray *c32_lhs16 = NULL;
  const mxArray *c32_rhs17 = NULL;
  const mxArray *c32_lhs17 = NULL;
  const mxArray *c32_rhs18 = NULL;
  const mxArray *c32_lhs18 = NULL;
  const mxArray *c32_rhs19 = NULL;
  const mxArray *c32_lhs19 = NULL;
  const mxArray *c32_rhs20 = NULL;
  const mxArray *c32_lhs20 = NULL;
  const mxArray *c32_rhs21 = NULL;
  const mxArray *c32_lhs21 = NULL;
  const mxArray *c32_rhs22 = NULL;
  const mxArray *c32_lhs22 = NULL;
  const mxArray *c32_rhs23 = NULL;
  const mxArray *c32_lhs23 = NULL;
  const mxArray *c32_rhs24 = NULL;
  const mxArray *c32_lhs24 = NULL;
  const mxArray *c32_rhs25 = NULL;
  const mxArray *c32_lhs25 = NULL;
  const mxArray *c32_rhs26 = NULL;
  const mxArray *c32_lhs26 = NULL;
  const mxArray *c32_rhs27 = NULL;
  const mxArray *c32_lhs27 = NULL;
  const mxArray *c32_rhs28 = NULL;
  const mxArray *c32_lhs28 = NULL;
  const mxArray *c32_rhs29 = NULL;
  const mxArray *c32_lhs29 = NULL;
  const mxArray *c32_rhs30 = NULL;
  const mxArray *c32_lhs30 = NULL;
  const mxArray *c32_rhs31 = NULL;
  const mxArray *c32_lhs31 = NULL;
  const mxArray *c32_rhs32 = NULL;
  const mxArray *c32_lhs32 = NULL;
  const mxArray *c32_rhs33 = NULL;
  const mxArray *c32_lhs33 = NULL;
  const mxArray *c32_rhs34 = NULL;
  const mxArray *c32_lhs34 = NULL;
  const mxArray *c32_rhs35 = NULL;
  const mxArray *c32_lhs35 = NULL;
  const mxArray *c32_rhs36 = NULL;
  const mxArray *c32_lhs36 = NULL;
  const mxArray *c32_rhs37 = NULL;
  const mxArray *c32_lhs37 = NULL;
  const mxArray *c32_rhs38 = NULL;
  const mxArray *c32_lhs38 = NULL;
  const mxArray *c32_rhs39 = NULL;
  const mxArray *c32_lhs39 = NULL;
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c32_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c32_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c32_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c32_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c32_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c32_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c32_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c32_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c32_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c32_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("dot"), "name", "name", 10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1360282354U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c32_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("isequal"), "name", "name",
                  11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c32_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c32_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("isnan"), "name", "name", 13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c32_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c32_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c32_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c32_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot"), "context",
                  "context", 17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c32_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c32_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_xdot"), "name", "name",
                  19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c32_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c32_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold"),
                  "context", "context", 21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("length"), "name", "name", 21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1303146206U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c32_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c32_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1299076772U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c32_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c32_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c32_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c32_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c32_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmax"), "name", "name", 28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c32_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c32_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c32_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c32_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c32_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c32_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c32_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("mrdivide"), "name", "name",
                  35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c32_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("rdivide"), "name", "name",
                  36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c32_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c32_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c32_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_div"), "name", "name",
                  39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c32_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c32_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs39), "lhs", "lhs",
                  39);
  sf_mex_destroy(&c32_rhs0);
  sf_mex_destroy(&c32_lhs0);
  sf_mex_destroy(&c32_rhs1);
  sf_mex_destroy(&c32_lhs1);
  sf_mex_destroy(&c32_rhs2);
  sf_mex_destroy(&c32_lhs2);
  sf_mex_destroy(&c32_rhs3);
  sf_mex_destroy(&c32_lhs3);
  sf_mex_destroy(&c32_rhs4);
  sf_mex_destroy(&c32_lhs4);
  sf_mex_destroy(&c32_rhs5);
  sf_mex_destroy(&c32_lhs5);
  sf_mex_destroy(&c32_rhs6);
  sf_mex_destroy(&c32_lhs6);
  sf_mex_destroy(&c32_rhs7);
  sf_mex_destroy(&c32_lhs7);
  sf_mex_destroy(&c32_rhs8);
  sf_mex_destroy(&c32_lhs8);
  sf_mex_destroy(&c32_rhs9);
  sf_mex_destroy(&c32_lhs9);
  sf_mex_destroy(&c32_rhs10);
  sf_mex_destroy(&c32_lhs10);
  sf_mex_destroy(&c32_rhs11);
  sf_mex_destroy(&c32_lhs11);
  sf_mex_destroy(&c32_rhs12);
  sf_mex_destroy(&c32_lhs12);
  sf_mex_destroy(&c32_rhs13);
  sf_mex_destroy(&c32_lhs13);
  sf_mex_destroy(&c32_rhs14);
  sf_mex_destroy(&c32_lhs14);
  sf_mex_destroy(&c32_rhs15);
  sf_mex_destroy(&c32_lhs15);
  sf_mex_destroy(&c32_rhs16);
  sf_mex_destroy(&c32_lhs16);
  sf_mex_destroy(&c32_rhs17);
  sf_mex_destroy(&c32_lhs17);
  sf_mex_destroy(&c32_rhs18);
  sf_mex_destroy(&c32_lhs18);
  sf_mex_destroy(&c32_rhs19);
  sf_mex_destroy(&c32_lhs19);
  sf_mex_destroy(&c32_rhs20);
  sf_mex_destroy(&c32_lhs20);
  sf_mex_destroy(&c32_rhs21);
  sf_mex_destroy(&c32_lhs21);
  sf_mex_destroy(&c32_rhs22);
  sf_mex_destroy(&c32_lhs22);
  sf_mex_destroy(&c32_rhs23);
  sf_mex_destroy(&c32_lhs23);
  sf_mex_destroy(&c32_rhs24);
  sf_mex_destroy(&c32_lhs24);
  sf_mex_destroy(&c32_rhs25);
  sf_mex_destroy(&c32_lhs25);
  sf_mex_destroy(&c32_rhs26);
  sf_mex_destroy(&c32_lhs26);
  sf_mex_destroy(&c32_rhs27);
  sf_mex_destroy(&c32_lhs27);
  sf_mex_destroy(&c32_rhs28);
  sf_mex_destroy(&c32_lhs28);
  sf_mex_destroy(&c32_rhs29);
  sf_mex_destroy(&c32_lhs29);
  sf_mex_destroy(&c32_rhs30);
  sf_mex_destroy(&c32_lhs30);
  sf_mex_destroy(&c32_rhs31);
  sf_mex_destroy(&c32_lhs31);
  sf_mex_destroy(&c32_rhs32);
  sf_mex_destroy(&c32_lhs32);
  sf_mex_destroy(&c32_rhs33);
  sf_mex_destroy(&c32_lhs33);
  sf_mex_destroy(&c32_rhs34);
  sf_mex_destroy(&c32_lhs34);
  sf_mex_destroy(&c32_rhs35);
  sf_mex_destroy(&c32_lhs35);
  sf_mex_destroy(&c32_rhs36);
  sf_mex_destroy(&c32_lhs36);
  sf_mex_destroy(&c32_rhs37);
  sf_mex_destroy(&c32_lhs37);
  sf_mex_destroy(&c32_rhs38);
  sf_mex_destroy(&c32_lhs38);
  sf_mex_destroy(&c32_rhs39);
  sf_mex_destroy(&c32_lhs39);
}

static const mxArray *c32_emlrt_marshallOut(char * c32_u)
{
  const mxArray *c32_y = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c32_u)), FALSE);
  return c32_y;
}

static const mxArray *c32_b_emlrt_marshallOut(uint32_T c32_u)
{
  const mxArray *c32_y = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c32_y;
}

static void c32_eml_scalar_eg(SFc32_QRLsimInstanceStruct *chartInstance)
{
}

static real_T c32_dot(SFc32_QRLsimInstanceStruct *chartInstance, real_T c32_a[3],
                      real_T c32_b[3])
{
  real_T c32_c;
  int32_T c32_k;
  int32_T c32_b_k;
  c32_b_eml_scalar_eg(chartInstance);
  c32_b_eml_scalar_eg(chartInstance);
  c32_c = 0.0;
  for (c32_k = 1; c32_k < 4; c32_k++) {
    c32_b_k = c32_k;
    c32_c += c32_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c32_b_k), 1, 3, 1, 0) - 1] * c32_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c32_b_k), 1, 3, 1, 0) - 1];
  }

  return c32_c;
}

static void c32_b_eml_scalar_eg(SFc32_QRLsimInstanceStruct *chartInstance)
{
}

static const mxArray *c32_f_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(int32_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static int32_T c32_d_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  int32_T c32_y;
  int32_T c32_i41;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_i41, 1, 6, 0U, 0, 0U, 0);
  c32_y = c32_i41;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_sfEvent;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int32_T c32_y;
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)chartInstanceVoid;
  c32_b_sfEvent = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_sfEvent),
    &c32_thisId);
  sf_mex_destroy(&c32_b_sfEvent);
  *(int32_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static uint8_T c32_e_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_b_is_active_c32_QRLsim, const char_T *c32_identifier)
{
  uint8_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c32_b_is_active_c32_QRLsim), &c32_thisId);
  sf_mex_destroy(&c32_b_is_active_c32_QRLsim);
  return c32_y;
}

static uint8_T c32_f_emlrt_marshallIn(SFc32_QRLsimInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  uint8_T c32_y;
  uint8_T c32_u0;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_u0, 1, 3, 0U, 0, 0U, 0);
  c32_y = c32_u0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void init_dsm_address_info(SFc32_QRLsimInstanceStruct *chartInstance)
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

void sf_c32_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(131896297U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(771608736U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(185467520U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(735547247U);
}

mxArray *sf_c32_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4mN4JDiwnDyhKdf9EYpfUB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[1] = (double)(3);
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
      pr[0] = (double)(1);
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

mxArray *sf_c32_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c32_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c32_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ddxL\",},{M[8],M[0],T\"is_active_c32_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c32_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc32_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc32_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           32,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"varddxL");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ddxL");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q");
          _SFD_SET_DATA_PROPS(4,1,1,0,"R");
          _SFD_SET_DATA_PROPS(5,1,1,0,"f");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,198);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)
            c32_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c32_f;
          real_T (*c32_varddxL)[4];
          real_T (*c32_dq)[3];
          real_T (*c32_ddxL)[3];
          real_T (*c32_q)[3];
          real_T (*c32_R)[9];
          c32_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c32_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 3);
          c32_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c32_ddxL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c32_dq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c32_varddxL = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c32_varddxL);
          _SFD_SET_DATA_VALUE_PTR(1U, *c32_dq);
          _SFD_SET_DATA_VALUE_PTR(2U, *c32_ddxL);
          _SFD_SET_DATA_VALUE_PTR(3U, *c32_q);
          _SFD_SET_DATA_VALUE_PTR(4U, *c32_R);
          _SFD_SET_DATA_VALUE_PTR(5U, c32_f);
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
  return "k919jNGyBLReA7SsXduTlD";
}

static void sf_opaque_initialize_c32_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc32_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c32_QRLsim(void *chartInstanceVar)
{
  enable_c32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c32_QRLsim(void *chartInstanceVar)
{
  disable_c32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c32_QRLsim(void *chartInstanceVar)
{
  sf_c32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c32_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c32_QRLsim((SFc32_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c32_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c32_QRLsim((SFc32_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c32_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c32_QRLsim(S);
}

static void sf_opaque_set_sim_state_c32_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c32_QRLsim(S, st);
}

static void sf_opaque_terminate_c32_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc32_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc32_QRLsim((SFc32_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c32_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c32_QRLsim((SFc32_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c32_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      32);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,32,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,32,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,32);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,32,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,32,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,32);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3892861549U));
  ssSetChecksum1(S,(3068556158U));
  ssSetChecksum2(S,(772986855U));
  ssSetChecksum3(S,(1591997454U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c32_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c32_QRLsim(SimStruct *S)
{
  SFc32_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc32_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc32_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc32_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c32_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c32_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c32_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c32_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c32_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c32_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c32_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c32_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c32_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c32_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c32_QRLsim;
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

void c32_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c32_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c32_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c32_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c32_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
