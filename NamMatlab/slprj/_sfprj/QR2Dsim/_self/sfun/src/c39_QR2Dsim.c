/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QR2Dsim_sfun.h"
#include "c39_QR2Dsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QR2Dsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c39_debug_family_names[5] = { "phiQ", "nargin", "nargout",
  "angleQ", "R" };

/* Function Declarations */
static void initialize_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance);
static void initialize_params_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct
  *chartInstance);
static void enable_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance);
static void disable_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance);
static void c39_update_debugger_state_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct
  *chartInstance);
static void set_sim_state_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_st);
static void finalize_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance);
static void sf_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance);
static void initSimStructsc39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c39_machineNumber, uint32_T
  c39_chartNumber);
static const mxArray *c39_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static void c39_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_R, const char_T *c39_identifier, real_T c39_y[9]);
static void c39_b_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId, real_T c39_y[9]);
static void c39_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static const mxArray *c39_b_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static const mxArray *c39_c_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static real_T c39_c_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static void c39_info_helper(const mxArray **c39_info);
static const mxArray *c39_emlrt_marshallOut(char * c39_u);
static const mxArray *c39_b_emlrt_marshallOut(uint32_T c39_u);
static const mxArray *c39_d_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static int32_T c39_d_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static uint8_T c39_e_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_b_is_active_c39_QR2Dsim, const char_T *c39_identifier);
static uint8_T c39_f_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void init_dsm_address_info(SFc39_QR2DsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance)
{
  chartInstance->c39_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c39_is_active_c39_QR2Dsim = 0U;
}

static void initialize_params_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct
  *chartInstance)
{
}

static void enable_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c39_update_debugger_state_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct
  *chartInstance)
{
  const mxArray *c39_st;
  const mxArray *c39_y = NULL;
  int32_T c39_i0;
  real_T c39_u[9];
  const mxArray *c39_b_y = NULL;
  uint8_T c39_hoistedGlobal;
  uint8_T c39_b_u;
  const mxArray *c39_c_y = NULL;
  real_T (*c39_R)[9];
  c39_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c39_st = NULL;
  c39_st = NULL;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_createcellarray(2), FALSE);
  for (c39_i0 = 0; c39_i0 < 9; c39_i0++) {
    c39_u[c39_i0] = (*c39_R)[c39_i0];
  }

  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", c39_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c39_y, 0, c39_b_y);
  c39_hoistedGlobal = chartInstance->c39_is_active_c39_QR2Dsim;
  c39_b_u = c39_hoistedGlobal;
  c39_c_y = NULL;
  sf_mex_assign(&c39_c_y, sf_mex_create("y", &c39_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c39_y, 1, c39_c_y);
  sf_mex_assign(&c39_st, c39_y, FALSE);
  return c39_st;
}

static void set_sim_state_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_st)
{
  const mxArray *c39_u;
  real_T c39_dv0[9];
  int32_T c39_i1;
  real_T (*c39_R)[9];
  c39_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c39_doneDoubleBufferReInit = TRUE;
  c39_u = sf_mex_dup(c39_st);
  c39_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c39_u, 0)), "R",
                       c39_dv0);
  for (c39_i1 = 0; c39_i1 < 9; c39_i1++) {
    (*c39_R)[c39_i1] = c39_dv0[c39_i1];
  }

  chartInstance->c39_is_active_c39_QR2Dsim = c39_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c39_u, 1)),
     "is_active_c39_QR2Dsim");
  sf_mex_destroy(&c39_u);
  c39_update_debugger_state_c39_QR2Dsim(chartInstance);
  sf_mex_destroy(&c39_st);
}

static void finalize_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance)
{
}

static void sf_c39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c39_i2;
  int32_T c39_i3;
  int32_T c39_i4;
  real_T c39_angleQ[3];
  uint32_T c39_debug_family_var_map[5];
  real_T c39_phiQ;
  real_T c39_nargin = 1.0;
  real_T c39_nargout = 1.0;
  real_T c39_R[9];
  real_T c39_x;
  real_T c39_b_x;
  real_T c39_c_x;
  real_T c39_d_x;
  real_T c39_e_x;
  real_T c39_f_x;
  real_T c39_g_x;
  real_T c39_h_x;
  int32_T c39_i5;
  int32_T c39_i6;
  static real_T c39_dv1[3] = { 1.0, 0.0, 0.0 };

  int32_T c39_i7;
  real_T (*c39_b_R)[9];
  real_T (*c39_b_angleQ)[3];
  c39_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c39_b_angleQ = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c39_sfEvent);
  for (c39_i2 = 0; c39_i2 < 3; c39_i2++) {
    _SFD_DATA_RANGE_CHECK((*c39_b_angleQ)[c39_i2], 0U);
  }

  for (c39_i3 = 0; c39_i3 < 9; c39_i3++) {
    _SFD_DATA_RANGE_CHECK((*c39_b_R)[c39_i3], 1U);
  }

  chartInstance->c39_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c39_sfEvent);
  for (c39_i4 = 0; c39_i4 < 3; c39_i4++) {
    c39_angleQ[c39_i4] = (*c39_b_angleQ)[c39_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c39_debug_family_names,
    c39_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_phiQ, 0U, c39_c_sf_marshallOut,
    c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargin, 1U, c39_c_sf_marshallOut,
    c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargout, 2U, c39_c_sf_marshallOut,
    c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c39_angleQ, 3U, c39_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c39_R, 4U, c39_sf_marshallOut,
    c39_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, 3);
  c39_phiQ = c39_angleQ[2];
  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, 5);
  c39_x = c39_phiQ;
  c39_b_x = c39_x;
  c39_b_x = muDoubleScalarCos(c39_b_x);
  c39_c_x = c39_phiQ;
  c39_d_x = c39_c_x;
  c39_d_x = muDoubleScalarSin(c39_d_x);
  c39_e_x = c39_phiQ;
  c39_f_x = c39_e_x;
  c39_f_x = muDoubleScalarSin(c39_f_x);
  c39_g_x = c39_phiQ;
  c39_h_x = c39_g_x;
  c39_h_x = muDoubleScalarCos(c39_h_x);
  c39_i5 = 0;
  for (c39_i6 = 0; c39_i6 < 3; c39_i6++) {
    c39_R[c39_i5] = c39_dv1[c39_i6];
    c39_i5 += 3;
  }

  c39_R[1] = 0.0;
  c39_R[4] = c39_b_x;
  c39_R[7] = -c39_d_x;
  c39_R[2] = 0.0;
  c39_R[5] = c39_f_x;
  c39_R[8] = c39_h_x;
  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c39_i7 = 0; c39_i7 < 9; c39_i7++) {
    (*c39_b_R)[c39_i7] = c39_R[c39_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c39_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QR2DsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc39_QR2Dsim(SFc39_QR2DsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c39_machineNumber, uint32_T
  c39_chartNumber)
{
}

static const mxArray *c39_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_i8;
  int32_T c39_i9;
  int32_T c39_i10;
  real_T c39_b_inData[9];
  int32_T c39_i11;
  int32_T c39_i12;
  int32_T c39_i13;
  real_T c39_u[9];
  const mxArray *c39_y = NULL;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_i8 = 0;
  for (c39_i9 = 0; c39_i9 < 3; c39_i9++) {
    for (c39_i10 = 0; c39_i10 < 3; c39_i10++) {
      c39_b_inData[c39_i10 + c39_i8] = (*(real_T (*)[9])c39_inData)[c39_i10 +
        c39_i8];
    }

    c39_i8 += 3;
  }

  c39_i11 = 0;
  for (c39_i12 = 0; c39_i12 < 3; c39_i12++) {
    for (c39_i13 = 0; c39_i13 < 3; c39_i13++) {
      c39_u[c39_i13 + c39_i11] = c39_b_inData[c39_i13 + c39_i11];
    }

    c39_i11 += 3;
  }

  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", c39_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, FALSE);
  return c39_mxArrayOutData;
}

static void c39_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_R, const char_T *c39_identifier, real_T c39_y[9])
{
  emlrtMsgIdentifier c39_thisId;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_R), &c39_thisId, c39_y);
  sf_mex_destroy(&c39_R);
}

static void c39_b_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId, real_T c39_y[9])
{
  real_T c39_dv2[9];
  int32_T c39_i14;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), c39_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c39_i14 = 0; c39_i14 < 9; c39_i14++) {
    c39_y[c39_i14] = c39_dv2[c39_i14];
  }

  sf_mex_destroy(&c39_u);
}

static void c39_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_R;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  real_T c39_y[9];
  int32_T c39_i15;
  int32_T c39_i16;
  int32_T c39_i17;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_R = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_R), &c39_thisId, c39_y);
  sf_mex_destroy(&c39_R);
  c39_i15 = 0;
  for (c39_i16 = 0; c39_i16 < 3; c39_i16++) {
    for (c39_i17 = 0; c39_i17 < 3; c39_i17++) {
      (*(real_T (*)[9])c39_outData)[c39_i17 + c39_i15] = c39_y[c39_i17 + c39_i15];
    }

    c39_i15 += 3;
  }

  sf_mex_destroy(&c39_mxArrayInData);
}

static const mxArray *c39_b_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_i18;
  real_T c39_b_inData[3];
  int32_T c39_i19;
  real_T c39_u[3];
  const mxArray *c39_y = NULL;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  for (c39_i18 = 0; c39_i18 < 3; c39_i18++) {
    c39_b_inData[c39_i18] = (*(real_T (*)[3])c39_inData)[c39_i18];
  }

  for (c39_i19 = 0; c39_i19 < 3; c39_i19++) {
    c39_u[c39_i19] = c39_b_inData[c39_i19];
  }

  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", c39_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, FALSE);
  return c39_mxArrayOutData;
}

static const mxArray *c39_c_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  real_T c39_u;
  const mxArray *c39_y = NULL;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_u = *(real_T *)c39_inData;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, FALSE);
  return c39_mxArrayOutData;
}

static real_T c39_c_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  real_T c39_y;
  real_T c39_d0;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_d0, 1, 0, 0U, 0, 0U, 0);
  c39_y = c39_d0;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void c39_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_nargout;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  real_T c39_y;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_nargout = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_nargout),
    &c39_thisId);
  sf_mex_destroy(&c39_nargout);
  *(real_T *)c39_outData = c39_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

const mxArray *sf_c39_QR2Dsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c39_nameCaptureInfo = NULL;
  c39_nameCaptureInfo = NULL;
  sf_mex_assign(&c39_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                FALSE);
  c39_info_helper(&c39_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c39_nameCaptureInfo);
  return c39_nameCaptureInfo;
}

static void c39_info_helper(const mxArray **c39_info)
{
  const mxArray *c39_rhs0 = NULL;
  const mxArray *c39_lhs0 = NULL;
  const mxArray *c39_rhs1 = NULL;
  const mxArray *c39_lhs1 = NULL;
  const mxArray *c39_rhs2 = NULL;
  const mxArray *c39_lhs2 = NULL;
  const mxArray *c39_rhs3 = NULL;
  const mxArray *c39_lhs3 = NULL;
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c39_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c39_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c39_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c39_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c39_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c39_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c39_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c39_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs3), "lhs", "lhs",
                  3);
  sf_mex_destroy(&c39_rhs0);
  sf_mex_destroy(&c39_lhs0);
  sf_mex_destroy(&c39_rhs1);
  sf_mex_destroy(&c39_lhs1);
  sf_mex_destroy(&c39_rhs2);
  sf_mex_destroy(&c39_lhs2);
  sf_mex_destroy(&c39_rhs3);
  sf_mex_destroy(&c39_lhs3);
}

static const mxArray *c39_emlrt_marshallOut(char * c39_u)
{
  const mxArray *c39_y = NULL;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", c39_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c39_u)), FALSE);
  return c39_y;
}

static const mxArray *c39_b_emlrt_marshallOut(uint32_T c39_u)
{
  const mxArray *c39_y = NULL;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c39_y;
}

static const mxArray *c39_d_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_u;
  const mxArray *c39_y = NULL;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_u = *(int32_T *)c39_inData;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, FALSE);
  return c39_mxArrayOutData;
}

static int32_T c39_d_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  int32_T c39_y;
  int32_T c39_i20;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_i20, 1, 6, 0U, 0, 0U, 0);
  c39_y = c39_i20;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void c39_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_b_sfEvent;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  int32_T c39_y;
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)chartInstanceVoid;
  c39_b_sfEvent = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_b_sfEvent),
    &c39_thisId);
  sf_mex_destroy(&c39_b_sfEvent);
  *(int32_T *)c39_outData = c39_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

static uint8_T c39_e_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_b_is_active_c39_QR2Dsim, const char_T *c39_identifier)
{
  uint8_T c39_y;
  emlrtMsgIdentifier c39_thisId;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c39_b_is_active_c39_QR2Dsim), &c39_thisId);
  sf_mex_destroy(&c39_b_is_active_c39_QR2Dsim);
  return c39_y;
}

static uint8_T c39_f_emlrt_marshallIn(SFc39_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  uint8_T c39_y;
  uint8_T c39_u0;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_u0, 1, 3, 0U, 0, 0U, 0);
  c39_y = c39_u0;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void init_dsm_address_info(SFc39_QR2DsimInstanceStruct *chartInstance)
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

void sf_c39_QR2Dsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1886561664U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1902782232U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1517048561U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1439758019U);
}

mxArray *sf_c39_QR2Dsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6H0mFqdm2QKQ52YVrSQjqB");
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

mxArray *sf_c39_QR2Dsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c39_QR2Dsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c39_QR2Dsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"R\",},{M[8],M[0],T\"is_active_c39_QR2Dsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c39_QR2Dsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc39_QR2DsimInstanceStruct *chartInstance;
    chartInstance = (SFc39_QR2DsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QR2DsimMachineNumber_,
           39,
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
          init_script_number_translation(_QR2DsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_QR2DsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _QR2DsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"angleQ");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,124);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c39_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c39_sf_marshallOut,(MexInFcnForType)
            c39_sf_marshallIn);
        }

        {
          real_T (*c39_angleQ)[3];
          real_T (*c39_R)[9];
          c39_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c39_angleQ = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c39_angleQ);
          _SFD_SET_DATA_VALUE_PTR(1U, *c39_R);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _QR2DsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "VfNy8WQw6bEnRMjGEbTyYB";
}

static void sf_opaque_initialize_c39_QR2Dsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc39_QR2DsimInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
  initialize_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c39_QR2Dsim(void *chartInstanceVar)
{
  enable_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c39_QR2Dsim(void *chartInstanceVar)
{
  disable_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c39_QR2Dsim(void *chartInstanceVar)
{
  sf_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c39_QR2Dsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c39_QR2Dsim();/* state var info */
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

extern void sf_internal_set_sim_state_c39_QR2Dsim(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c39_QR2Dsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c39_QR2Dsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c39_QR2Dsim(S);
}

static void sf_opaque_set_sim_state_c39_QR2Dsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c39_QR2Dsim(S, st);
}

static void sf_opaque_terminate_c39_QR2Dsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc39_QR2DsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QR2Dsim_optimization_info();
    }

    finalize_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc39_QR2Dsim((SFc39_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c39_QR2Dsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c39_QR2Dsim((SFc39_QR2DsimInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c39_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QR2Dsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      39);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,39,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,39,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,39);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,39,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,39,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,39);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2961438529U));
  ssSetChecksum1(S,(2062136436U));
  ssSetChecksum2(S,(1301801842U));
  ssSetChecksum3(S,(2502662579U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c39_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c39_QR2Dsim(SimStruct *S)
{
  SFc39_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc39_QR2DsimInstanceStruct *)utMalloc(sizeof
    (SFc39_QR2DsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc39_QR2DsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c39_QR2Dsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c39_QR2Dsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c39_QR2Dsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c39_QR2Dsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c39_QR2Dsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c39_QR2Dsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c39_QR2Dsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c39_QR2Dsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c39_QR2Dsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c39_QR2Dsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c39_QR2Dsim;
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

void c39_QR2Dsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c39_QR2Dsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c39_QR2Dsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c39_QR2Dsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c39_QR2Dsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
