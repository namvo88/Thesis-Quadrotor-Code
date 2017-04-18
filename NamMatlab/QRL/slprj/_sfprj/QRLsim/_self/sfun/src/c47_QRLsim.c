/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c47_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c47_debug_family_names[5] = { "nargin", "nargout", "q", "qd",
  "Psiq" };

/* Function Declarations */
static void initialize_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c47_QRLsim(SFc47_QRLsimInstanceStruct
  *chartInstance);
static void enable_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance);
static void disable_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance);
static void c47_update_debugger_state_c47_QRLsim(SFc47_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c47_QRLsim(SFc47_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_st);
static void finalize_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance);
static void sf_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber);
static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static real_T c47_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_Psiq, const char_T *c47_identifier);
static real_T c47_b_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static void c47_info_helper(const mxArray **c47_info);
static const mxArray *c47_emlrt_marshallOut(char * c47_u);
static const mxArray *c47_b_emlrt_marshallOut(uint32_T c47_u);
static void c47_eml_scalar_eg(SFc47_QRLsimInstanceStruct *chartInstance);
static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static int32_T c47_c_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static uint8_T c47_d_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_b_is_active_c47_QRLsim, const char_T *c47_identifier);
static uint8_T c47_e_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void init_dsm_address_info(SFc47_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c47_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c47_is_active_c47_QRLsim = 0U;
}

static void initialize_params_c47_QRLsim(SFc47_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c47_update_debugger_state_c47_QRLsim(SFc47_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c47_QRLsim(SFc47_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c47_st;
  const mxArray *c47_y = NULL;
  real_T c47_hoistedGlobal;
  real_T c47_u;
  const mxArray *c47_b_y = NULL;
  uint8_T c47_b_hoistedGlobal;
  uint8_T c47_b_u;
  const mxArray *c47_c_y = NULL;
  real_T *c47_Psiq;
  c47_Psiq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c47_st = NULL;
  c47_st = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_createcellarray(2), FALSE);
  c47_hoistedGlobal = *c47_Psiq;
  c47_u = c47_hoistedGlobal;
  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c47_y, 0, c47_b_y);
  c47_b_hoistedGlobal = chartInstance->c47_is_active_c47_QRLsim;
  c47_b_u = c47_b_hoistedGlobal;
  c47_c_y = NULL;
  sf_mex_assign(&c47_c_y, sf_mex_create("y", &c47_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c47_y, 1, c47_c_y);
  sf_mex_assign(&c47_st, c47_y, FALSE);
  return c47_st;
}

static void set_sim_state_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_st)
{
  const mxArray *c47_u;
  real_T *c47_Psiq;
  c47_Psiq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c47_doneDoubleBufferReInit = TRUE;
  c47_u = sf_mex_dup(c47_st);
  *c47_Psiq = c47_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c47_u, 0)), "Psiq");
  chartInstance->c47_is_active_c47_QRLsim = c47_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c47_u, 1)), "is_active_c47_QRLsim");
  sf_mex_destroy(&c47_u);
  c47_update_debugger_state_c47_QRLsim(chartInstance);
  sf_mex_destroy(&c47_st);
}

static void finalize_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance)
{
  int32_T c47_i0;
  int32_T c47_i1;
  int32_T c47_i2;
  real_T c47_q[3];
  int32_T c47_i3;
  real_T c47_qd[3];
  uint32_T c47_debug_family_var_map[5];
  real_T c47_nargin = 2.0;
  real_T c47_nargout = 1.0;
  real_T c47_Psiq;
  int32_T c47_i4;
  real_T c47_a[3];
  int32_T c47_i5;
  real_T c47_b[3];
  real_T c47_y;
  int32_T c47_k;
  int32_T c47_b_k;
  real_T *c47_b_Psiq;
  real_T (*c47_b_qd)[3];
  real_T (*c47_b_q)[3];
  c47_b_qd = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c47_b_Psiq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c47_b_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c47_sfEvent);
  for (c47_i0 = 0; c47_i0 < 3; c47_i0++) {
    _SFD_DATA_RANGE_CHECK((*c47_b_q)[c47_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c47_b_Psiq, 1U);
  for (c47_i1 = 0; c47_i1 < 3; c47_i1++) {
    _SFD_DATA_RANGE_CHECK((*c47_b_qd)[c47_i1], 2U);
  }

  chartInstance->c47_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c47_sfEvent);
  for (c47_i2 = 0; c47_i2 < 3; c47_i2++) {
    c47_q[c47_i2] = (*c47_b_q)[c47_i2];
  }

  for (c47_i3 = 0; c47_i3 < 3; c47_i3++) {
    c47_qd[c47_i3] = (*c47_b_qd)[c47_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c47_debug_family_names,
    c47_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargin, 0U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargout, 1U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c47_q, 2U, c47_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c47_qd, 3U, c47_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_Psiq, 4U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 3);
  for (c47_i4 = 0; c47_i4 < 3; c47_i4++) {
    c47_a[c47_i4] = c47_qd[c47_i4];
  }

  for (c47_i5 = 0; c47_i5 < 3; c47_i5++) {
    c47_b[c47_i5] = c47_q[c47_i5];
  }

  c47_eml_scalar_eg(chartInstance);
  c47_eml_scalar_eg(chartInstance);
  c47_y = 0.0;
  for (c47_k = 1; c47_k < 4; c47_k++) {
    c47_b_k = c47_k;
    c47_y += c47_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c47_b_k), 1, 3, 1, 0) - 1] * c47_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c47_b_k), 1, 3, 1, 0) - 1];
  }

  c47_Psiq = 1.0 - c47_y;
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  *c47_b_Psiq = c47_Psiq;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c47_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc47_QRLsim(SFc47_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber)
{
}

static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  real_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(real_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, FALSE);
  return c47_mxArrayOutData;
}

static real_T c47_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_Psiq, const char_T *c47_identifier)
{
  real_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_Psiq),
    &c47_thisId);
  sf_mex_destroy(&c47_Psiq);
  return c47_y;
}

static real_T c47_b_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  real_T c47_y;
  real_T c47_d0;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_d0, 1, 0, 0U, 0, 0U, 0);
  c47_y = c47_d0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_Psiq;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y;
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)chartInstanceVoid;
  c47_Psiq = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_Psiq),
    &c47_thisId);
  sf_mex_destroy(&c47_Psiq);
  *(real_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_i6;
  real_T c47_b_inData[3];
  int32_T c47_i7;
  real_T c47_u[3];
  const mxArray *c47_y = NULL;
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  for (c47_i6 = 0; c47_i6 < 3; c47_i6++) {
    c47_b_inData[c47_i6] = (*(real_T (*)[3])c47_inData)[c47_i6];
  }

  for (c47_i7 = 0; c47_i7 < 3; c47_i7++) {
    c47_u[c47_i7] = c47_b_inData[c47_i7];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, FALSE);
  return c47_mxArrayOutData;
}

static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_i8;
  real_T c47_b_inData[3];
  int32_T c47_i9;
  real_T c47_u[3];
  const mxArray *c47_y = NULL;
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  for (c47_i8 = 0; c47_i8 < 3; c47_i8++) {
    c47_b_inData[c47_i8] = (*(real_T (*)[3])c47_inData)[c47_i8];
  }

  for (c47_i9 = 0; c47_i9 < 3; c47_i9++) {
    c47_u[c47_i9] = c47_b_inData[c47_i9];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, FALSE);
  return c47_mxArrayOutData;
}

const mxArray *sf_c47_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c47_nameCaptureInfo = NULL;
  c47_nameCaptureInfo = NULL;
  sf_mex_assign(&c47_nameCaptureInfo, sf_mex_createstruct("structure", 2, 21, 1),
                FALSE);
  c47_info_helper(&c47_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c47_nameCaptureInfo);
  return c47_nameCaptureInfo;
}

static void c47_info_helper(const mxArray **c47_info)
{
  const mxArray *c47_rhs0 = NULL;
  const mxArray *c47_lhs0 = NULL;
  const mxArray *c47_rhs1 = NULL;
  const mxArray *c47_lhs1 = NULL;
  const mxArray *c47_rhs2 = NULL;
  const mxArray *c47_lhs2 = NULL;
  const mxArray *c47_rhs3 = NULL;
  const mxArray *c47_lhs3 = NULL;
  const mxArray *c47_rhs4 = NULL;
  const mxArray *c47_lhs4 = NULL;
  const mxArray *c47_rhs5 = NULL;
  const mxArray *c47_lhs5 = NULL;
  const mxArray *c47_rhs6 = NULL;
  const mxArray *c47_lhs6 = NULL;
  const mxArray *c47_rhs7 = NULL;
  const mxArray *c47_lhs7 = NULL;
  const mxArray *c47_rhs8 = NULL;
  const mxArray *c47_lhs8 = NULL;
  const mxArray *c47_rhs9 = NULL;
  const mxArray *c47_lhs9 = NULL;
  const mxArray *c47_rhs10 = NULL;
  const mxArray *c47_lhs10 = NULL;
  const mxArray *c47_rhs11 = NULL;
  const mxArray *c47_lhs11 = NULL;
  const mxArray *c47_rhs12 = NULL;
  const mxArray *c47_lhs12 = NULL;
  const mxArray *c47_rhs13 = NULL;
  const mxArray *c47_lhs13 = NULL;
  const mxArray *c47_rhs14 = NULL;
  const mxArray *c47_lhs14 = NULL;
  const mxArray *c47_rhs15 = NULL;
  const mxArray *c47_lhs15 = NULL;
  const mxArray *c47_rhs16 = NULL;
  const mxArray *c47_lhs16 = NULL;
  const mxArray *c47_rhs17 = NULL;
  const mxArray *c47_lhs17 = NULL;
  const mxArray *c47_rhs18 = NULL;
  const mxArray *c47_lhs18 = NULL;
  const mxArray *c47_rhs19 = NULL;
  const mxArray *c47_lhs19 = NULL;
  const mxArray *c47_rhs20 = NULL;
  const mxArray *c47_lhs20 = NULL;
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c47_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c47_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c47_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c47_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c47_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c47_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_xdot"), "name", "name",
                  6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c47_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c47_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c47_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1299076772U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c47_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c47_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c47_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c47_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c47_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c47_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c47_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c47_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c47_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c47_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c47_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmax"), "name", "name", 20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c47_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c47_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs20), "lhs", "lhs",
                  20);
  sf_mex_destroy(&c47_rhs0);
  sf_mex_destroy(&c47_lhs0);
  sf_mex_destroy(&c47_rhs1);
  sf_mex_destroy(&c47_lhs1);
  sf_mex_destroy(&c47_rhs2);
  sf_mex_destroy(&c47_lhs2);
  sf_mex_destroy(&c47_rhs3);
  sf_mex_destroy(&c47_lhs3);
  sf_mex_destroy(&c47_rhs4);
  sf_mex_destroy(&c47_lhs4);
  sf_mex_destroy(&c47_rhs5);
  sf_mex_destroy(&c47_lhs5);
  sf_mex_destroy(&c47_rhs6);
  sf_mex_destroy(&c47_lhs6);
  sf_mex_destroy(&c47_rhs7);
  sf_mex_destroy(&c47_lhs7);
  sf_mex_destroy(&c47_rhs8);
  sf_mex_destroy(&c47_lhs8);
  sf_mex_destroy(&c47_rhs9);
  sf_mex_destroy(&c47_lhs9);
  sf_mex_destroy(&c47_rhs10);
  sf_mex_destroy(&c47_lhs10);
  sf_mex_destroy(&c47_rhs11);
  sf_mex_destroy(&c47_lhs11);
  sf_mex_destroy(&c47_rhs12);
  sf_mex_destroy(&c47_lhs12);
  sf_mex_destroy(&c47_rhs13);
  sf_mex_destroy(&c47_lhs13);
  sf_mex_destroy(&c47_rhs14);
  sf_mex_destroy(&c47_lhs14);
  sf_mex_destroy(&c47_rhs15);
  sf_mex_destroy(&c47_lhs15);
  sf_mex_destroy(&c47_rhs16);
  sf_mex_destroy(&c47_lhs16);
  sf_mex_destroy(&c47_rhs17);
  sf_mex_destroy(&c47_lhs17);
  sf_mex_destroy(&c47_rhs18);
  sf_mex_destroy(&c47_lhs18);
  sf_mex_destroy(&c47_rhs19);
  sf_mex_destroy(&c47_lhs19);
  sf_mex_destroy(&c47_rhs20);
  sf_mex_destroy(&c47_lhs20);
}

static const mxArray *c47_emlrt_marshallOut(char * c47_u)
{
  const mxArray *c47_y = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c47_u)), FALSE);
  return c47_y;
}

static const mxArray *c47_b_emlrt_marshallOut(uint32_T c47_u)
{
  const mxArray *c47_y = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c47_y;
}

static void c47_eml_scalar_eg(SFc47_QRLsimInstanceStruct *chartInstance)
{
}

static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(int32_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, FALSE);
  return c47_mxArrayOutData;
}

static int32_T c47_c_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  int32_T c47_y;
  int32_T c47_i10;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_i10, 1, 6, 0U, 0, 0U, 0);
  c47_y = c47_i10;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_sfEvent;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  int32_T c47_y;
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)chartInstanceVoid;
  c47_b_sfEvent = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_sfEvent),
    &c47_thisId);
  sf_mex_destroy(&c47_b_sfEvent);
  *(int32_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static uint8_T c47_d_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_b_is_active_c47_QRLsim, const char_T *c47_identifier)
{
  uint8_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_is_active_c47_QRLsim), &c47_thisId);
  sf_mex_destroy(&c47_b_is_active_c47_QRLsim);
  return c47_y;
}

static uint8_T c47_e_emlrt_marshallIn(SFc47_QRLsimInstanceStruct *chartInstance,
  const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  uint8_T c47_y;
  uint8_T c47_u0;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_u0, 1, 3, 0U, 0, 0U, 0);
  c47_y = c47_u0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void init_dsm_address_info(SFc47_QRLsimInstanceStruct *chartInstance)
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

void sf_c47_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3103699739U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3204043425U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3900886677U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3655723054U);
}

mxArray *sf_c47_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nxm0CElSkVHKvzMgtLIRNB");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c47_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c47_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c47_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Psiq\",},{M[8],M[0],T\"is_active_c47_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c47_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc47_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc47_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           47,
           1,
           1,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Psiq");
          _SFD_SET_DATA_PROPS(2,1,1,0,"qd");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,44);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c47_Psiq;
          real_T (*c47_q)[3];
          real_T (*c47_qd)[3];
          c47_qd = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c47_Psiq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c47_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c47_q);
          _SFD_SET_DATA_VALUE_PTR(1U, c47_Psiq);
          _SFD_SET_DATA_VALUE_PTR(2U, *c47_qd);
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
  return "42rCzBXAYzjuf3ZL23zk0C";
}

static void sf_opaque_initialize_c47_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc47_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c47_QRLsim(void *chartInstanceVar)
{
  enable_c47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c47_QRLsim(void *chartInstanceVar)
{
  disable_c47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c47_QRLsim(void *chartInstanceVar)
{
  sf_c47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c47_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c47_QRLsim((SFc47_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c47_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c47_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c47_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c47_QRLsim((SFc47_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c47_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c47_QRLsim(S);
}

static void sf_opaque_set_sim_state_c47_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c47_QRLsim(S, st);
}

static void sf_opaque_terminate_c47_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc47_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc47_QRLsim((SFc47_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c47_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c47_QRLsim((SFc47_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c47_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      47);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,47,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,47,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,47);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,47,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,47,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,47);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2455171122U));
  ssSetChecksum1(S,(3482695591U));
  ssSetChecksum2(S,(2124484568U));
  ssSetChecksum3(S,(2838181717U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c47_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c47_QRLsim(SimStruct *S)
{
  SFc47_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc47_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc47_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc47_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c47_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c47_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c47_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c47_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c47_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c47_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c47_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c47_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c47_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c47_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c47_QRLsim;
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

void c47_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c47_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c47_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c47_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c47_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
