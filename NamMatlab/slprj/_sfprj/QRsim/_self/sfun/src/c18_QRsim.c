/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c18_QRsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c18_debug_family_names[7] = { "a", "b", "c", "nargin",
  "nargout", "A", "fcnhat" };

/* Function Declarations */
static void initialize_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void initialize_params_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void enable_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void disable_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_QRsim(SFc18_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c18_QRsim(SFc18_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_st);
static void finalize_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void sf_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void initSimStructsc18_QRsim(SFc18_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance, const
  mxArray *c18_fcnhat, const char_T *c18_identifier, real_T c18_y[9]);
static void c18_b_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[9]);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_c_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_d_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_e_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_b_is_active_c18_QRsim, const char_T *c18_identifier);
static uint8_T c18_f_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info(SFc18_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c18_is_active_c18_QRsim = 0U;
}

static void initialize_params_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c18_update_debugger_state_c18_QRsim(SFc18_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c18_QRsim(SFc18_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  real_T c18_u[9];
  const mxArray *c18_b_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  real_T (*c18_fcnhat)[9];
  c18_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellarray(2), FALSE);
  for (c18_i0 = 0; c18_i0 < 9; c18_i0++) {
    c18_u[c18_i0] = (*c18_fcnhat)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_hoistedGlobal = chartInstance->c18_is_active_c18_QRsim;
  c18_b_u = c18_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, FALSE);
  return c18_st;
}

static void set_sim_state_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T c18_dv0[9];
  int32_T c18_i1;
  real_T (*c18_fcnhat)[9];
  c18_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c18_doneDoubleBufferReInit = TRUE;
  c18_u = sf_mex_dup(c18_st);
  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)),
                       "fcnhat", c18_dv0);
  for (c18_i1 = 0; c18_i1 < 9; c18_i1++) {
    (*c18_fcnhat)[c18_i1] = c18_dv0[c18_i1];
  }

  chartInstance->c18_is_active_c18_QRsim = c18_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c18_u, 1)), "is_active_c18_QRsim");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_QRsim(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
  int32_T c18_i2;
  int32_T c18_i3;
  int32_T c18_i4;
  real_T c18_A[3];
  uint32_T c18_debug_family_var_map[7];
  real_T c18_a;
  real_T c18_b;
  real_T c18_c;
  real_T c18_nargin = 1.0;
  real_T c18_nargout = 1.0;
  real_T c18_fcnhat[9];
  int32_T c18_i5;
  real_T (*c18_b_fcnhat)[9];
  real_T (*c18_b_A)[3];
  c18_b_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_b_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  for (c18_i2 = 0; c18_i2 < 3; c18_i2++) {
    _SFD_DATA_RANGE_CHECK((*c18_b_A)[c18_i2], 0U);
  }

  for (c18_i3 = 0; c18_i3 < 9; c18_i3++) {
    _SFD_DATA_RANGE_CHECK((*c18_b_fcnhat)[c18_i3], 1U);
  }

  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  for (c18_i4 = 0; c18_i4 < 3; c18_i4++) {
    c18_A[c18_i4] = (*c18_b_A)[c18_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_a, 0U, c18_c_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b, 1U, c18_c_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_c, 2U, c18_c_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 3U, c18_c_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 4U, c18_c_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_A, 5U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_fcnhat, 6U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_a = c18_A[0];
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 4);
  c18_b = c18_A[1];
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 5);
  c18_c = c18_A[2];
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 6);
  c18_fcnhat[0] = 0.0;
  c18_fcnhat[3] = -c18_c;
  c18_fcnhat[6] = c18_b;
  c18_fcnhat[1] = c18_c;
  c18_fcnhat[4] = 0.0;
  c18_fcnhat[7] = -c18_a;
  c18_fcnhat[2] = -c18_b;
  c18_fcnhat[5] = c18_a;
  c18_fcnhat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c18_i5 = 0; c18_i5 < 9; c18_i5++) {
    (*c18_b_fcnhat)[c18_i5] = c18_fcnhat[c18_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc18_QRsim(SFc18_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber)
{
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i6;
  int32_T c18_i7;
  int32_T c18_i8;
  real_T c18_b_inData[9];
  int32_T c18_i9;
  int32_T c18_i10;
  int32_T c18_i11;
  real_T c18_u[9];
  const mxArray *c18_y = NULL;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i6 = 0;
  for (c18_i7 = 0; c18_i7 < 3; c18_i7++) {
    for (c18_i8 = 0; c18_i8 < 3; c18_i8++) {
      c18_b_inData[c18_i8 + c18_i6] = (*(real_T (*)[9])c18_inData)[c18_i8 +
        c18_i6];
    }

    c18_i6 += 3;
  }

  c18_i9 = 0;
  for (c18_i10 = 0; c18_i10 < 3; c18_i10++) {
    for (c18_i11 = 0; c18_i11 < 3; c18_i11++) {
      c18_u[c18_i11 + c18_i9] = c18_b_inData[c18_i11 + c18_i9];
    }

    c18_i9 += 3;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static void c18_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance, const
  mxArray *c18_fcnhat, const char_T *c18_identifier, real_T c18_y[9])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_fcnhat), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_fcnhat);
}

static void c18_b_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[9])
{
  real_T c18_dv1[9];
  int32_T c18_i12;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c18_i12 = 0; c18_i12 < 9; c18_i12++) {
    c18_y[c18_i12] = c18_dv1[c18_i12];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_fcnhat;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[9];
  int32_T c18_i13;
  int32_T c18_i14;
  int32_T c18_i15;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_fcnhat = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_fcnhat), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_fcnhat);
  c18_i13 = 0;
  for (c18_i14 = 0; c18_i14 < 3; c18_i14++) {
    for (c18_i15 = 0; c18_i15 < 3; c18_i15++) {
      (*(real_T (*)[9])c18_outData)[c18_i15 + c18_i13] = c18_y[c18_i15 + c18_i13];
    }

    c18_i13 += 3;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i16;
  real_T c18_b_inData[3];
  int32_T c18_i17;
  real_T c18_u[3];
  const mxArray *c18_y = NULL;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i16 = 0; c18_i16 < 3; c18_i16++) {
    c18_b_inData[c18_i16] = (*(real_T (*)[3])c18_inData)[c18_i16];
  }

  for (c18_i17 = 0; c18_i17 < 3; c18_i17++) {
    c18_u[c18_i17] = c18_b_inData[c18_i17];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static real_T c18_c_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nargout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_nargout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_nargout),
    &c18_thisId);
  sf_mex_destroy(&c18_nargout);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static int32_T c18_d_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i18;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i18, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i18;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_e_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_b_is_active_c18_QRsim, const char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_QRsim), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_QRsim);
  return c18_y;
}

static uint8_T c18_f_emlrt_marshallIn(SFc18_QRsimInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info(SFc18_QRsimInstanceStruct *chartInstance)
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

void sf_c18_QRsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4131461561U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2773855065U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3367629386U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1329840116U);
}

mxArray *sf_c18_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OkOaE7PIG6hStSXjKfx8dC");
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

mxArray *sf_c18_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c18_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fcnhat\",},{M[8],M[0],T\"is_active_c18_QRsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc18_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           18,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,2,0,1,"fcnhat");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,112);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)
            c18_sf_marshallIn);
        }

        {
          real_T (*c18_A)[3];
          real_T (*c18_fcnhat)[9];
          c18_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c18_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c18_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c18_fcnhat);
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
  return "GfIs82lQvdn1MFOTGXJ1UF";
}

static void sf_opaque_initialize_c18_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_QRsim(void *chartInstanceVar)
{
  enable_c18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_QRsim(void *chartInstanceVar)
{
  disable_c18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_QRsim(void *chartInstanceVar)
{
  sf_c18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c18_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_QRsim((SFc18_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c18_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_QRsim((SFc18_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c18_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c18_QRsim(S);
}

static void sf_opaque_set_sim_state_c18_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c18_QRsim(S, st);
}

static void sf_opaque_terminate_c18_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_QRsim((SFc18_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c18_QRsim((SFc18_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,18,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1502744395U));
  ssSetChecksum1(S,(1388126807U));
  ssSetChecksum2(S,(2128390740U));
  ssSetChecksum3(S,(815326924U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_QRsim(SimStruct *S)
{
  SFc18_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc18_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc18_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c18_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c18_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c18_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c18_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c18_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c18_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c18_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c18_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c18_QRsim;
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

void c18_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
