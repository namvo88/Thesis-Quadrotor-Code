/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c50_QRLsim.h"
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
static const char * c50_debug_family_names[9] = { "Tsim_end", "A", "omega",
  "nargin", "nargout", "t", "xLd", "dxLd", "ddxLd" };

/* Function Declarations */
static void initialize_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c50_QRLsim(SFc50_QRLsimInstanceStruct
  *chartInstance);
static void enable_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance);
static void disable_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance);
static void c50_update_debugger_state_c50_QRLsim(SFc50_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c50_QRLsim(SFc50_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_st);
static void finalize_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance);
static void sf_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_ddxLd, const char_T *c50_identifier, real_T c50_y[3]);
static void c50_b_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId, real_T c50_y[3]);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static real_T c50_c_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static void c50_info_helper(const mxArray **c50_info);
static const mxArray *c50_emlrt_marshallOut(char * c50_u);
static const mxArray *c50_b_emlrt_marshallOut(uint32_T c50_u);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int32_T c50_d_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static uint8_T c50_e_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_b_is_active_c50_QRLsim, const char_T *c50_identifier);
static uint8_T c50_f_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void init_dsm_address_info(SFc50_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c50_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c50_is_active_c50_QRLsim = 0U;
}

static void initialize_params_c50_QRLsim(SFc50_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c50_update_debugger_state_c50_QRLsim(SFc50_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c50_QRLsim(SFc50_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c50_st;
  const mxArray *c50_y = NULL;
  int32_T c50_i0;
  real_T c50_u[3];
  const mxArray *c50_b_y = NULL;
  int32_T c50_i1;
  real_T c50_b_u[3];
  const mxArray *c50_c_y = NULL;
  int32_T c50_i2;
  real_T c50_c_u[3];
  const mxArray *c50_d_y = NULL;
  uint8_T c50_hoistedGlobal;
  uint8_T c50_d_u;
  const mxArray *c50_e_y = NULL;
  real_T (*c50_xLd)[3];
  real_T (*c50_dxLd)[3];
  real_T (*c50_ddxLd)[3];
  c50_ddxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c50_dxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c50_xLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c50_st = NULL;
  c50_st = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_createcellarray(4), FALSE);
  for (c50_i0 = 0; c50_i0 < 3; c50_i0++) {
    c50_u[c50_i0] = (*c50_ddxLd)[c50_i0];
  }

  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  for (c50_i1 = 0; c50_i1 < 3; c50_i1++) {
    c50_b_u[c50_i1] = (*c50_dxLd)[c50_i1];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c50_y, 1, c50_c_y);
  for (c50_i2 = 0; c50_i2 < 3; c50_i2++) {
    c50_c_u[c50_i2] = (*c50_xLd)[c50_i2];
  }

  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", c50_c_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c50_y, 2, c50_d_y);
  c50_hoistedGlobal = chartInstance->c50_is_active_c50_QRLsim;
  c50_d_u = c50_hoistedGlobal;
  c50_e_y = NULL;
  sf_mex_assign(&c50_e_y, sf_mex_create("y", &c50_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c50_y, 3, c50_e_y);
  sf_mex_assign(&c50_st, c50_y, FALSE);
  return c50_st;
}

static void set_sim_state_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_st)
{
  const mxArray *c50_u;
  real_T c50_dv0[3];
  int32_T c50_i3;
  real_T c50_dv1[3];
  int32_T c50_i4;
  real_T c50_dv2[3];
  int32_T c50_i5;
  real_T (*c50_ddxLd)[3];
  real_T (*c50_dxLd)[3];
  real_T (*c50_xLd)[3];
  c50_ddxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c50_dxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c50_xLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c50_doneDoubleBufferReInit = TRUE;
  c50_u = sf_mex_dup(c50_st);
  c50_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 0)),
                       "ddxLd", c50_dv0);
  for (c50_i3 = 0; c50_i3 < 3; c50_i3++) {
    (*c50_ddxLd)[c50_i3] = c50_dv0[c50_i3];
  }

  c50_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 1)),
                       "dxLd", c50_dv1);
  for (c50_i4 = 0; c50_i4 < 3; c50_i4++) {
    (*c50_dxLd)[c50_i4] = c50_dv1[c50_i4];
  }

  c50_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 2)),
                       "xLd", c50_dv2);
  for (c50_i5 = 0; c50_i5 < 3; c50_i5++) {
    (*c50_xLd)[c50_i5] = c50_dv2[c50_i5];
  }

  chartInstance->c50_is_active_c50_QRLsim = c50_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 3)), "is_active_c50_QRLsim");
  sf_mex_destroy(&c50_u);
  c50_update_debugger_state_c50_QRLsim(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void finalize_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance)
{
  int32_T c50_i6;
  int32_T c50_i7;
  int32_T c50_i8;
  real_T c50_hoistedGlobal;
  real_T c50_t;
  uint32_T c50_debug_family_var_map[9];
  real_T c50_Tsim_end;
  real_T c50_A;
  real_T c50_omega;
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 3.0;
  real_T c50_xLd[3];
  real_T c50_dxLd[3];
  real_T c50_ddxLd[3];
  real_T c50_b;
  real_T c50_y;
  real_T c50_x;
  real_T c50_b_x;
  real_T c50_b_b;
  real_T c50_b_y;
  real_T c50_c_b;
  real_T c50_c_y;
  real_T c50_c_x;
  real_T c50_d_x;
  real_T c50_d_b;
  real_T c50_d_y;
  real_T c50_e_b;
  real_T c50_e_y;
  real_T c50_e_x;
  real_T c50_f_x;
  real_T c50_f_b;
  real_T c50_f_y;
  real_T c50_a;
  real_T c50_g_y;
  int32_T c50_i9;
  static real_T c50_dv3[3] = { 0.0, -1.0, 0.0 };

  int32_T c50_i10;
  int32_T c50_i11;
  int32_T c50_i12;
  int32_T c50_i13;
  real_T *c50_b_t;
  real_T (*c50_b_xLd)[3];
  real_T (*c50_b_dxLd)[3];
  real_T (*c50_b_ddxLd)[3];
  c50_b_ddxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c50_b_dxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c50_b_xLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c50_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c50_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c50_b_t, 0U);
  for (c50_i6 = 0; c50_i6 < 3; c50_i6++) {
    _SFD_DATA_RANGE_CHECK((*c50_b_xLd)[c50_i6], 1U);
  }

  for (c50_i7 = 0; c50_i7 < 3; c50_i7++) {
    _SFD_DATA_RANGE_CHECK((*c50_b_dxLd)[c50_i7], 2U);
  }

  for (c50_i8 = 0; c50_i8 < 3; c50_i8++) {
    _SFD_DATA_RANGE_CHECK((*c50_b_ddxLd)[c50_i8], 3U);
  }

  chartInstance->c50_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c50_sfEvent);
  c50_hoistedGlobal = *c50_b_t;
  c50_t = c50_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_Tsim_end, 0U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_A, 1U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_omega, 2U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_t, 5U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_xLd, 6U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_dxLd, 7U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_ddxLd, 8U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 3);
  c50_Tsim_end = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_A = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 5);
  c50_omega = 1.2566370614359172;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 11);
  c50_b = c50_t;
  c50_y = 1.2566370614359172 * c50_b;
  c50_x = c50_y + 1.5707963267948966;
  c50_b_x = c50_x;
  c50_b_x = muDoubleScalarSin(c50_b_x);
  c50_b_b = c50_b_x;
  c50_b_y = 0.5 * c50_b_b;
  c50_xLd[0] = 0.0;
  c50_xLd[1] = c50_b_y - c50_A;
  c50_xLd[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 12);
  c50_c_b = c50_t;
  c50_c_y = 1.2566370614359172 * c50_c_b;
  c50_c_x = c50_c_y + 1.5707963267948966;
  c50_d_x = c50_c_x;
  c50_d_x = muDoubleScalarCos(c50_d_x);
  c50_d_b = c50_d_x;
  c50_d_y = 0.62831853071795862 * c50_d_b;
  c50_dxLd[0] = 0.0;
  c50_dxLd[1] = c50_d_y;
  c50_dxLd[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 13);
  c50_e_b = c50_t;
  c50_e_y = 1.2566370614359172 * c50_e_b;
  c50_e_x = c50_e_y + 1.5707963267948966;
  c50_f_x = c50_e_x;
  c50_f_x = muDoubleScalarSin(c50_f_x);
  c50_f_b = -c50_f_x;
  c50_f_y = 0.78956835208714859 * c50_f_b;
  c50_a = c50_f_y;
  c50_g_y = c50_a * 0.0;
  c50_ddxLd[0] = 0.0;
  c50_ddxLd[1] = c50_g_y;
  c50_ddxLd[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 19);
  if (CV_EML_IF(0, 1, 0, c50_t >= 2.5)) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 20);
    for (c50_i9 = 0; c50_i9 < 3; c50_i9++) {
      c50_xLd[c50_i9] = c50_dv3[c50_i9];
    }

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 21);
    for (c50_i10 = 0; c50_i10 < 3; c50_i10++) {
      c50_dxLd[c50_i10] = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c50_i11 = 0; c50_i11 < 3; c50_i11++) {
    (*c50_b_xLd)[c50_i11] = c50_xLd[c50_i11];
  }

  for (c50_i12 = 0; c50_i12 < 3; c50_i12++) {
    (*c50_b_dxLd)[c50_i12] = c50_dxLd[c50_i12];
  }

  for (c50_i13 = 0; c50_i13 < 3; c50_i13++) {
    (*c50_b_ddxLd)[c50_i13] = c50_ddxLd[c50_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c50_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc50_QRLsim(SFc50_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber)
{
}

static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i14;
  real_T c50_b_inData[3];
  int32_T c50_i15;
  real_T c50_u[3];
  const mxArray *c50_y = NULL;
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i14 = 0; c50_i14 < 3; c50_i14++) {
    c50_b_inData[c50_i14] = (*(real_T (*)[3])c50_inData)[c50_i14];
  }

  for (c50_i15 = 0; c50_i15 < 3; c50_i15++) {
    c50_u[c50_i15] = c50_b_inData[c50_i15];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, FALSE);
  return c50_mxArrayOutData;
}

static void c50_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_ddxLd, const char_T *c50_identifier, real_T c50_y[3])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_ddxLd), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_ddxLd);
}

static void c50_b_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId, real_T c50_y[3])
{
  real_T c50_dv4[3];
  int32_T c50_i16;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c50_i16 = 0; c50_i16 < 3; c50_i16++) {
    c50_y[c50_i16] = c50_dv4[c50_i16];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_ddxLd;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[3];
  int32_T c50_i17;
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)chartInstanceVoid;
  c50_ddxLd = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_ddxLd), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_ddxLd);
  for (c50_i17 = 0; c50_i17 < 3; c50_i17++) {
    (*(real_T (*)[3])c50_outData)[c50_i17] = c50_y[c50_i17];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, FALSE);
  return c50_mxArrayOutData;
}

static real_T c50_c_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d0;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d0, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_nargout;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)chartInstanceVoid;
  c50_nargout = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_nargout),
    &c50_thisId);
  sf_mex_destroy(&c50_nargout);
  *(real_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

const mxArray *sf_c50_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_createstruct("structure", 2, 23, 1),
                FALSE);
  c50_info_helper(&c50_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c50_nameCaptureInfo);
  return c50_nameCaptureInfo;
}

static void c50_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs0 = NULL;
  const mxArray *c50_lhs0 = NULL;
  const mxArray *c50_rhs1 = NULL;
  const mxArray *c50_lhs1 = NULL;
  const mxArray *c50_rhs2 = NULL;
  const mxArray *c50_lhs2 = NULL;
  const mxArray *c50_rhs3 = NULL;
  const mxArray *c50_lhs3 = NULL;
  const mxArray *c50_rhs4 = NULL;
  const mxArray *c50_lhs4 = NULL;
  const mxArray *c50_rhs5 = NULL;
  const mxArray *c50_lhs5 = NULL;
  const mxArray *c50_rhs6 = NULL;
  const mxArray *c50_lhs6 = NULL;
  const mxArray *c50_rhs7 = NULL;
  const mxArray *c50_lhs7 = NULL;
  const mxArray *c50_rhs8 = NULL;
  const mxArray *c50_lhs8 = NULL;
  const mxArray *c50_rhs9 = NULL;
  const mxArray *c50_lhs9 = NULL;
  const mxArray *c50_rhs10 = NULL;
  const mxArray *c50_lhs10 = NULL;
  const mxArray *c50_rhs11 = NULL;
  const mxArray *c50_lhs11 = NULL;
  const mxArray *c50_rhs12 = NULL;
  const mxArray *c50_lhs12 = NULL;
  const mxArray *c50_rhs13 = NULL;
  const mxArray *c50_lhs13 = NULL;
  const mxArray *c50_rhs14 = NULL;
  const mxArray *c50_lhs14 = NULL;
  const mxArray *c50_rhs15 = NULL;
  const mxArray *c50_lhs15 = NULL;
  const mxArray *c50_rhs16 = NULL;
  const mxArray *c50_lhs16 = NULL;
  const mxArray *c50_rhs17 = NULL;
  const mxArray *c50_lhs17 = NULL;
  const mxArray *c50_rhs18 = NULL;
  const mxArray *c50_lhs18 = NULL;
  const mxArray *c50_rhs19 = NULL;
  const mxArray *c50_lhs19 = NULL;
  const mxArray *c50_rhs20 = NULL;
  const mxArray *c50_lhs20 = NULL;
  const mxArray *c50_rhs21 = NULL;
  const mxArray *c50_lhs21 = NULL;
  const mxArray *c50_rhs22 = NULL;
  const mxArray *c50_lhs22 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c50_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c50_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mrdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c50_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c50_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c50_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c50_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c50_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("sin"), "name", "name", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c50_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c50_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("cos"), "name", "name", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c50_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c50_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mpower"), "name", "name", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c50_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c50_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("ismatrix"), "name", "name",
                  13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c50_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("power"), "name", "name", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c50_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c50_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c50_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1358186140U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c50_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("floor"), "name", "name", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c50_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c50_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c50_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c50_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mtimes"), "name", "name", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c50_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c50_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs22), "lhs", "lhs",
                  22);
  sf_mex_destroy(&c50_rhs0);
  sf_mex_destroy(&c50_lhs0);
  sf_mex_destroy(&c50_rhs1);
  sf_mex_destroy(&c50_lhs1);
  sf_mex_destroy(&c50_rhs2);
  sf_mex_destroy(&c50_lhs2);
  sf_mex_destroy(&c50_rhs3);
  sf_mex_destroy(&c50_lhs3);
  sf_mex_destroy(&c50_rhs4);
  sf_mex_destroy(&c50_lhs4);
  sf_mex_destroy(&c50_rhs5);
  sf_mex_destroy(&c50_lhs5);
  sf_mex_destroy(&c50_rhs6);
  sf_mex_destroy(&c50_lhs6);
  sf_mex_destroy(&c50_rhs7);
  sf_mex_destroy(&c50_lhs7);
  sf_mex_destroy(&c50_rhs8);
  sf_mex_destroy(&c50_lhs8);
  sf_mex_destroy(&c50_rhs9);
  sf_mex_destroy(&c50_lhs9);
  sf_mex_destroy(&c50_rhs10);
  sf_mex_destroy(&c50_lhs10);
  sf_mex_destroy(&c50_rhs11);
  sf_mex_destroy(&c50_lhs11);
  sf_mex_destroy(&c50_rhs12);
  sf_mex_destroy(&c50_lhs12);
  sf_mex_destroy(&c50_rhs13);
  sf_mex_destroy(&c50_lhs13);
  sf_mex_destroy(&c50_rhs14);
  sf_mex_destroy(&c50_lhs14);
  sf_mex_destroy(&c50_rhs15);
  sf_mex_destroy(&c50_lhs15);
  sf_mex_destroy(&c50_rhs16);
  sf_mex_destroy(&c50_lhs16);
  sf_mex_destroy(&c50_rhs17);
  sf_mex_destroy(&c50_lhs17);
  sf_mex_destroy(&c50_rhs18);
  sf_mex_destroy(&c50_lhs18);
  sf_mex_destroy(&c50_rhs19);
  sf_mex_destroy(&c50_lhs19);
  sf_mex_destroy(&c50_rhs20);
  sf_mex_destroy(&c50_lhs20);
  sf_mex_destroy(&c50_rhs21);
  sf_mex_destroy(&c50_lhs21);
  sf_mex_destroy(&c50_rhs22);
  sf_mex_destroy(&c50_lhs22);
}

static const mxArray *c50_emlrt_marshallOut(char * c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c50_u)), FALSE);
  return c50_y;
}

static const mxArray *c50_b_emlrt_marshallOut(uint32_T c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c50_y;
}

static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, FALSE);
  return c50_mxArrayOutData;
}

static int32_T c50_d_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i18;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i18, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i18;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_sfEvent;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y;
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static uint8_T c50_e_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_b_is_active_c50_QRLsim, const char_T *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_is_active_c50_QRLsim), &c50_thisId);
  sf_mex_destroy(&c50_b_is_active_c50_QRLsim);
  return c50_y;
}

static uint8_T c50_f_emlrt_marshallIn(SFc50_QRLsimInstanceStruct *chartInstance,
  const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void init_dsm_address_info(SFc50_QRLsimInstanceStruct *chartInstance)
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

void sf_c50_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3079429431U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(716786527U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2330404143U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4064187621U);
}

mxArray *sf_c50_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GfDFX52fMPrO3CkkY7rlCH");
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c50_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c50_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[7],T\"ddxLd\",},{M[1],M[6],T\"dxLd\",},{M[1],M[5],T\"xLd\",},{M[8],M[0],T\"is_active_c50_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc50_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           50,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"xLd");
          _SFD_SET_DATA_PROPS(2,2,0,1,"dxLd");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ddxLd");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,543);
        _SFD_CV_INIT_EML_IF(0,1,0,485,494,-1,543);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          real_T *c50_t;
          real_T (*c50_xLd)[3];
          real_T (*c50_dxLd)[3];
          real_T (*c50_ddxLd)[3];
          c50_ddxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c50_dxLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c50_xLd = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c50_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c50_t);
          _SFD_SET_DATA_VALUE_PTR(1U, *c50_xLd);
          _SFD_SET_DATA_VALUE_PTR(2U, *c50_dxLd);
          _SFD_SET_DATA_VALUE_PTR(3U, *c50_ddxLd);
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
  return "NvdwLIblcZKr1ajnvsooDG";
}

static void sf_opaque_initialize_c50_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c50_QRLsim(void *chartInstanceVar)
{
  enable_c50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c50_QRLsim(void *chartInstanceVar)
{
  disable_c50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c50_QRLsim(void *chartInstanceVar)
{
  sf_c50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c50_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c50_QRLsim((SFc50_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c50_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c50_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c50_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c50_QRLsim((SFc50_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c50_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c50_QRLsim(S);
}

static void sf_opaque_set_sim_state_c50_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c50_QRLsim(S, st);
}

static void sf_opaque_terminate_c50_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc50_QRLsim((SFc50_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c50_QRLsim((SFc50_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      50);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,50,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,50,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,50);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,50,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,50,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,50);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1486813070U));
  ssSetChecksum1(S,(145678761U));
  ssSetChecksum2(S,(2284320877U));
  ssSetChecksum3(S,(1763691264U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c50_QRLsim(SimStruct *S)
{
  SFc50_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc50_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc50_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c50_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c50_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c50_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c50_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c50_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c50_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c50_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c50_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c50_QRLsim;
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

void c50_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
