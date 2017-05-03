/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c49_QRLsim.h"
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
static const char * c49_debug_family_names[6] = { "Tsim_end", "omega", "nargin",
  "nargout", "t", "qd" };

/* Function Declarations */
static void initialize_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c49_QRLsim(SFc49_QRLsimInstanceStruct
  *chartInstance);
static void enable_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance);
static void disable_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance);
static void c49_update_debugger_state_c49_QRLsim(SFc49_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c49_QRLsim(SFc49_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_st);
static void finalize_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance);
static void sf_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c49_machineNumber, uint32_T
  c49_chartNumber);
static const mxArray *c49_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static void c49_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_qd, const char_T *c49_identifier, real_T c49_y[3]);
static void c49_b_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId, real_T c49_y[3]);
static void c49_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_b_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static real_T c49_c_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void c49_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static void c49_info_helper(const mxArray **c49_info);
static const mxArray *c49_emlrt_marshallOut(char * c49_u);
static const mxArray *c49_b_emlrt_marshallOut(uint32_T c49_u);
static const mxArray *c49_c_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static int32_T c49_d_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void c49_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static uint8_T c49_e_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_b_is_active_c49_QRLsim, const char_T *c49_identifier);
static uint8_T c49_f_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void init_dsm_address_info(SFc49_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c49_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c49_is_active_c49_QRLsim = 0U;
}

static void initialize_params_c49_QRLsim(SFc49_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c49_update_debugger_state_c49_QRLsim(SFc49_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c49_QRLsim(SFc49_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c49_st;
  const mxArray *c49_y = NULL;
  int32_T c49_i0;
  real_T c49_u[3];
  const mxArray *c49_b_y = NULL;
  uint8_T c49_hoistedGlobal;
  uint8_T c49_b_u;
  const mxArray *c49_c_y = NULL;
  real_T (*c49_qd)[3];
  c49_qd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c49_st = NULL;
  c49_st = NULL;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_createcellarray(2), FALSE);
  for (c49_i0 = 0; c49_i0 < 3; c49_i0++) {
    c49_u[c49_i0] = (*c49_qd)[c49_i0];
  }

  c49_b_y = NULL;
  sf_mex_assign(&c49_b_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c49_y, 0, c49_b_y);
  c49_hoistedGlobal = chartInstance->c49_is_active_c49_QRLsim;
  c49_b_u = c49_hoistedGlobal;
  c49_c_y = NULL;
  sf_mex_assign(&c49_c_y, sf_mex_create("y", &c49_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c49_y, 1, c49_c_y);
  sf_mex_assign(&c49_st, c49_y, FALSE);
  return c49_st;
}

static void set_sim_state_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_st)
{
  const mxArray *c49_u;
  real_T c49_dv0[3];
  int32_T c49_i1;
  real_T (*c49_qd)[3];
  c49_qd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c49_doneDoubleBufferReInit = TRUE;
  c49_u = sf_mex_dup(c49_st);
  c49_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c49_u, 0)), "qd",
                       c49_dv0);
  for (c49_i1 = 0; c49_i1 < 3; c49_i1++) {
    (*c49_qd)[c49_i1] = c49_dv0[c49_i1];
  }

  chartInstance->c49_is_active_c49_QRLsim = c49_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c49_u, 1)), "is_active_c49_QRLsim");
  sf_mex_destroy(&c49_u);
  c49_update_debugger_state_c49_QRLsim(chartInstance);
  sf_mex_destroy(&c49_st);
}

static void finalize_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance)
{
  int32_T c49_i2;
  real_T c49_hoistedGlobal;
  real_T c49_t;
  uint32_T c49_debug_family_var_map[6];
  real_T c49_Tsim_end;
  real_T c49_omega;
  real_T c49_nargin = 1.0;
  real_T c49_nargout = 1.0;
  real_T c49_qd[3];
  int32_T c49_i3;
  static real_T c49_dv1[3] = { 0.0, 0.0, -1.0 };

  real_T c49_b;
  real_T c49_y;
  real_T c49_x;
  real_T c49_b_x;
  real_T c49_b_b;
  real_T c49_b_y;
  real_T c49_c_x;
  real_T c49_d_x;
  real_T c49_e_x;
  real_T c49_f_x;
  real_T c49_c_y;
  int32_T c49_i4;
  int32_T c49_i5;
  real_T *c49_b_t;
  real_T (*c49_b_qd)[3];
  boolean_T guard1 = FALSE;
  c49_b_qd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c49_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c49_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c49_b_t, 0U);
  for (c49_i2 = 0; c49_i2 < 3; c49_i2++) {
    _SFD_DATA_RANGE_CHECK((*c49_b_qd)[c49_i2], 1U);
  }

  chartInstance->c49_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c49_sfEvent);
  c49_hoistedGlobal = *c49_b_t;
  c49_t = c49_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c49_debug_family_names,
    c49_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c49_Tsim_end, 0U, c49_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c49_omega, 1U, c49_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_nargin, 2U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_nargout, 3U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c49_t, 4U, c49_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_qd, 5U, c49_sf_marshallOut,
    c49_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 4);
  c49_Tsim_end = 15.0;
  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 6);
  c49_omega = 0.43332312463307493;
  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 9);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c49_t <= 0.5)) {
    guard1 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, c49_t > 12.0)) {
    guard1 = TRUE;
  } else {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 12);
    c49_b = c49_t - 0.5;
    c49_y = 0.43332312463307493 * c49_b;
    c49_x = c49_y;
    c49_b_x = c49_x;
    c49_b_x = muDoubleScalarSin(c49_b_x);
    c49_b_b = c49_t - 0.5;
    c49_b_y = 0.43332312463307493 * c49_b_b;
    c49_c_x = c49_b_y;
    c49_d_x = c49_c_x;
    c49_d_x = muDoubleScalarCos(c49_d_x);
    c49_e_x = c49_d_x;
    c49_f_x = c49_e_x;
    c49_c_y = muDoubleScalarAbs(c49_f_x);
    c49_qd[0] = 0.0;
    c49_qd[1] = c49_b_x;
    c49_qd[2] = -c49_c_y - 0.15;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 10);
    for (c49_i3 = 0; c49_i3 < 3; c49_i3++) {
      c49_qd[c49_i3] = c49_dv1[c49_i3];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 15);
  if (CV_EML_IF(0, 1, 1, c49_qd[1] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 16);
    for (c49_i4 = 0; c49_i4 < 3; c49_i4++) {
      c49_qd[c49_i4] = c49_dv1[c49_i4];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c49_i5 = 0; c49_i5 < 3; c49_i5++) {
    (*c49_b_qd)[c49_i5] = c49_qd[c49_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c49_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc49_QRLsim(SFc49_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c49_machineNumber, uint32_T
  c49_chartNumber)
{
}

static const mxArray *c49_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_i6;
  real_T c49_b_inData[3];
  int32_T c49_i7;
  real_T c49_u[3];
  const mxArray *c49_y = NULL;
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  for (c49_i6 = 0; c49_i6 < 3; c49_i6++) {
    c49_b_inData[c49_i6] = (*(real_T (*)[3])c49_inData)[c49_i6];
  }

  for (c49_i7 = 0; c49_i7 < 3; c49_i7++) {
    c49_u[c49_i7] = c49_b_inData[c49_i7];
  }

  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, FALSE);
  return c49_mxArrayOutData;
}

static void c49_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_qd, const char_T *c49_identifier, real_T c49_y[3])
{
  emlrtMsgIdentifier c49_thisId;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_qd), &c49_thisId, c49_y);
  sf_mex_destroy(&c49_qd);
}

static void c49_b_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId, real_T c49_y[3])
{
  real_T c49_dv2[3];
  int32_T c49_i8;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c49_i8 = 0; c49_i8 < 3; c49_i8++) {
    c49_y[c49_i8] = c49_dv2[c49_i8];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_qd;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y[3];
  int32_T c49_i9;
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)chartInstanceVoid;
  c49_qd = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_qd), &c49_thisId, c49_y);
  sf_mex_destroy(&c49_qd);
  for (c49_i9 = 0; c49_i9 < 3; c49_i9++) {
    (*(real_T (*)[3])c49_outData)[c49_i9] = c49_y[c49_i9];
  }

  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_b_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  real_T c49_u;
  const mxArray *c49_y = NULL;
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  c49_u = *(real_T *)c49_inData;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, FALSE);
  return c49_mxArrayOutData;
}

static real_T c49_c_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  real_T c49_y;
  real_T c49_d0;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_d0, 1, 0, 0U, 0, 0U, 0);
  c49_y = c49_d0;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void c49_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_nargout;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y;
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)chartInstanceVoid;
  c49_nargout = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_nargout),
    &c49_thisId);
  sf_mex_destroy(&c49_nargout);
  *(real_T *)c49_outData = c49_y;
  sf_mex_destroy(&c49_mxArrayInData);
}

const mxArray *sf_c49_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c49_nameCaptureInfo = NULL;
  c49_nameCaptureInfo = NULL;
  sf_mex_assign(&c49_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                FALSE);
  c49_info_helper(&c49_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c49_nameCaptureInfo);
  return c49_nameCaptureInfo;
}

static void c49_info_helper(const mxArray **c49_info)
{
  const mxArray *c49_rhs0 = NULL;
  const mxArray *c49_lhs0 = NULL;
  const mxArray *c49_rhs1 = NULL;
  const mxArray *c49_lhs1 = NULL;
  const mxArray *c49_rhs2 = NULL;
  const mxArray *c49_lhs2 = NULL;
  const mxArray *c49_rhs3 = NULL;
  const mxArray *c49_lhs3 = NULL;
  const mxArray *c49_rhs4 = NULL;
  const mxArray *c49_lhs4 = NULL;
  const mxArray *c49_rhs5 = NULL;
  const mxArray *c49_lhs5 = NULL;
  const mxArray *c49_rhs6 = NULL;
  const mxArray *c49_lhs6 = NULL;
  const mxArray *c49_rhs7 = NULL;
  const mxArray *c49_lhs7 = NULL;
  const mxArray *c49_rhs8 = NULL;
  const mxArray *c49_lhs8 = NULL;
  const mxArray *c49_rhs9 = NULL;
  const mxArray *c49_lhs9 = NULL;
  const mxArray *c49_rhs10 = NULL;
  const mxArray *c49_lhs10 = NULL;
  const mxArray *c49_rhs11 = NULL;
  const mxArray *c49_lhs11 = NULL;
  const mxArray *c49_rhs12 = NULL;
  const mxArray *c49_lhs12 = NULL;
  const mxArray *c49_rhs13 = NULL;
  const mxArray *c49_lhs13 = NULL;
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c49_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c49_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("mrdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c49_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c49_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c49_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c49_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c49_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("sin"), "name", "name", 7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c49_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c49_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("cos"), "name", "name", 9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c49_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c49_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("abs"), "name", "name", 11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c49_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c49_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c49_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c49_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c49_rhs0);
  sf_mex_destroy(&c49_lhs0);
  sf_mex_destroy(&c49_rhs1);
  sf_mex_destroy(&c49_lhs1);
  sf_mex_destroy(&c49_rhs2);
  sf_mex_destroy(&c49_lhs2);
  sf_mex_destroy(&c49_rhs3);
  sf_mex_destroy(&c49_lhs3);
  sf_mex_destroy(&c49_rhs4);
  sf_mex_destroy(&c49_lhs4);
  sf_mex_destroy(&c49_rhs5);
  sf_mex_destroy(&c49_lhs5);
  sf_mex_destroy(&c49_rhs6);
  sf_mex_destroy(&c49_lhs6);
  sf_mex_destroy(&c49_rhs7);
  sf_mex_destroy(&c49_lhs7);
  sf_mex_destroy(&c49_rhs8);
  sf_mex_destroy(&c49_lhs8);
  sf_mex_destroy(&c49_rhs9);
  sf_mex_destroy(&c49_lhs9);
  sf_mex_destroy(&c49_rhs10);
  sf_mex_destroy(&c49_lhs10);
  sf_mex_destroy(&c49_rhs11);
  sf_mex_destroy(&c49_lhs11);
  sf_mex_destroy(&c49_rhs12);
  sf_mex_destroy(&c49_lhs12);
  sf_mex_destroy(&c49_rhs13);
  sf_mex_destroy(&c49_lhs13);
}

static const mxArray *c49_emlrt_marshallOut(char * c49_u)
{
  const mxArray *c49_y = NULL;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c49_u)), FALSE);
  return c49_y;
}

static const mxArray *c49_b_emlrt_marshallOut(uint32_T c49_u)
{
  const mxArray *c49_y = NULL;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c49_y;
}

static const mxArray *c49_c_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_u;
  const mxArray *c49_y = NULL;
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  c49_u = *(int32_T *)c49_inData;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, FALSE);
  return c49_mxArrayOutData;
}

static int32_T c49_d_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  int32_T c49_y;
  int32_T c49_i10;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_i10, 1, 6, 0U, 0, 0U, 0);
  c49_y = c49_i10;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void c49_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_sfEvent;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  int32_T c49_y;
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)chartInstanceVoid;
  c49_b_sfEvent = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_sfEvent),
    &c49_thisId);
  sf_mex_destroy(&c49_b_sfEvent);
  *(int32_T *)c49_outData = c49_y;
  sf_mex_destroy(&c49_mxArrayInData);
}

static uint8_T c49_e_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_b_is_active_c49_QRLsim, const char_T *c49_identifier)
{
  uint8_T c49_y;
  emlrtMsgIdentifier c49_thisId;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c49_b_is_active_c49_QRLsim), &c49_thisId);
  sf_mex_destroy(&c49_b_is_active_c49_QRLsim);
  return c49_y;
}

static uint8_T c49_f_emlrt_marshallIn(SFc49_QRLsimInstanceStruct *chartInstance,
  const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  uint8_T c49_y;
  uint8_T c49_u0;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_u0, 1, 3, 0U, 0, 0U, 0);
  c49_y = c49_u0;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void init_dsm_address_info(SFc49_QRLsimInstanceStruct *chartInstance)
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

void sf_c49_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3902828582U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2396181617U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3922144266U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2669714988U);
}

mxArray *sf_c49_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RqFWPdbaQUXvHtOk3XKJPB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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

mxArray *sf_c49_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c49_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c49_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"qd\",},{M[8],M[0],T\"is_active_c49_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c49_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc49_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc49_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           49,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"qd");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",30,-1,542);
        _SFD_CV_INIT_EML_IF(0,1,0,147,168,188,256);
        _SFD_CV_INIT_EML_IF(0,1,1,258,270,-1,293);

        {
          static int condStart[] = { 151, 161 };

          static int condEnd[] = { 157, 167 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,151,167,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c49_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_sf_marshallOut,(MexInFcnForType)
            c49_sf_marshallIn);
        }

        {
          real_T *c49_t;
          real_T (*c49_qd)[3];
          c49_qd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c49_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c49_t);
          _SFD_SET_DATA_VALUE_PTR(1U, *c49_qd);
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
  return "PFU1Rs6cd9KEOkah9hlKiE";
}

static void sf_opaque_initialize_c49_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc49_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c49_QRLsim(void *chartInstanceVar)
{
  enable_c49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c49_QRLsim(void *chartInstanceVar)
{
  disable_c49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c49_QRLsim(void *chartInstanceVar)
{
  sf_c49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c49_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c49_QRLsim((SFc49_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c49_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c49_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c49_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c49_QRLsim((SFc49_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c49_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c49_QRLsim(S);
}

static void sf_opaque_set_sim_state_c49_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c49_QRLsim(S, st);
}

static void sf_opaque_terminate_c49_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc49_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc49_QRLsim((SFc49_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c49_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c49_QRLsim((SFc49_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c49_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      49);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,49,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,49,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,49);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,49,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,49,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,49);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2656356255U));
  ssSetChecksum1(S,(1020037813U));
  ssSetChecksum2(S,(623077918U));
  ssSetChecksum3(S,(3072846530U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c49_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c49_QRLsim(SimStruct *S)
{
  SFc49_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc49_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc49_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc49_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c49_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c49_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c49_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c49_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c49_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c49_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c49_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c49_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c49_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c49_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c49_QRLsim;
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

void c49_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c49_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c49_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c49_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c49_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
