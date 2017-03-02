/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c12_QRsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[6] = { "nargin", "nargout", "b1d",
  "b3d", "b2d", "Rdes" };

/* Function Declarations */
static void initialize_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void initialize_params_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void enable_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void disable_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_QRsim(SFc12_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c12_QRsim(SFc12_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_st);
static void finalize_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void sf_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void initSimStructsc12_QRsim(SFc12_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance, const
  mxArray *c12_Rdes, const char_T *c12_identifier, real_T c12_y[9]);
static void c12_b_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[9]);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_c_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_b2d, const char_T *c12_identifier, real_T c12_y[3]);
static void c12_d_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3]);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_e_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static void c12_info_helper(const mxArray **c12_info);
static const mxArray *c12_emlrt_marshallOut(char * c12_u);
static const mxArray *c12_b_emlrt_marshallOut(uint32_T c12_u);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_f_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_g_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_b_is_active_c12_QRsim, const char_T *c12_identifier);
static uint8_T c12_h_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_QRsim = 0U;
}

static void initialize_params_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_QRsim(SFc12_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c12_QRsim(SFc12_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  int32_T c12_i0;
  real_T c12_u[9];
  const mxArray *c12_b_y = NULL;
  int32_T c12_i1;
  real_T c12_b_u[3];
  const mxArray *c12_c_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T (*c12_b2d)[3];
  real_T (*c12_Rdes)[9];
  c12_Rdes = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c12_b2d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(3), FALSE);
  for (c12_i0 = 0; c12_i0 < 9; c12_i0++) {
    c12_u[c12_i0] = (*c12_Rdes)[c12_i0];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  for (c12_i1 = 0; c12_i1 < 3; c12_i1++) {
    c12_b_u[c12_i1] = (*c12_b2d)[c12_i1];
  }

  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", c12_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_hoistedGlobal = chartInstance->c12_is_active_c12_QRsim;
  c12_c_u = c12_hoistedGlobal;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 2, c12_d_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T c12_dv0[9];
  int32_T c12_i2;
  real_T c12_dv1[3];
  int32_T c12_i3;
  real_T (*c12_Rdes)[9];
  real_T (*c12_b2d)[3];
  c12_Rdes = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c12_b2d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)),
                       "Rdes", c12_dv0);
  for (c12_i2 = 0; c12_i2 < 9; c12_i2++) {
    (*c12_Rdes)[c12_i2] = c12_dv0[c12_i2];
  }

  c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
    "b2d", c12_dv1);
  for (c12_i3 = 0; c12_i3 < 3; c12_i3++) {
    (*c12_b2d)[c12_i3] = c12_dv1[c12_i3];
  }

  chartInstance->c12_is_active_c12_QRsim = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 2)), "is_active_c12_QRsim");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_QRsim(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
  int32_T c12_i4;
  int32_T c12_i5;
  int32_T c12_i6;
  int32_T c12_i7;
  int32_T c12_i8;
  real_T c12_b1d[3];
  int32_T c12_i9;
  real_T c12_b3d[3];
  uint32_T c12_debug_family_var_map[6];
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 2.0;
  real_T c12_b2d[3];
  real_T c12_Rdes[9];
  int32_T c12_i10;
  real_T c12_a[3];
  int32_T c12_i11;
  real_T c12_b[3];
  real_T c12_b_a;
  real_T c12_b_b;
  real_T c12_y;
  real_T c12_c_a;
  real_T c12_c_b;
  real_T c12_b_y;
  real_T c12_c1;
  real_T c12_d_a;
  real_T c12_d_b;
  real_T c12_c_y;
  real_T c12_e_a;
  real_T c12_e_b;
  real_T c12_d_y;
  real_T c12_c2;
  real_T c12_f_a;
  real_T c12_f_b;
  real_T c12_e_y;
  real_T c12_g_a;
  real_T c12_g_b;
  real_T c12_f_y;
  real_T c12_c3;
  int32_T c12_i12;
  int32_T c12_i13;
  int32_T c12_i14;
  int32_T c12_i15;
  int32_T c12_i16;
  real_T (*c12_b_b2d)[3];
  real_T (*c12_b_Rdes)[9];
  real_T (*c12_b_b3d)[3];
  real_T (*c12_b_b1d)[3];
  c12_b_b3d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c12_b_Rdes = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c12_b_b1d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c12_b_b2d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i4 = 0; c12_i4 < 3; c12_i4++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_b2d)[c12_i4], 0U);
  }

  for (c12_i5 = 0; c12_i5 < 3; c12_i5++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_b1d)[c12_i5], 1U);
  }

  for (c12_i6 = 0; c12_i6 < 9; c12_i6++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_Rdes)[c12_i6], 2U);
  }

  for (c12_i7 = 0; c12_i7 < 3; c12_i7++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_b3d)[c12_i7], 3U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i8 = 0; c12_i8 < 3; c12_i8++) {
    c12_b1d[c12_i8] = (*c12_b_b1d)[c12_i8];
  }

  for (c12_i9 = 0; c12_i9 < 3; c12_i9++) {
    c12_b3d[c12_i9] = (*c12_b_b3d)[c12_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b1d, 2U, c12_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b3d, 3U, c12_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_b2d, 4U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_Rdes, 5U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  for (c12_i10 = 0; c12_i10 < 3; c12_i10++) {
    c12_a[c12_i10] = c12_b3d[c12_i10];
  }

  for (c12_i11 = 0; c12_i11 < 3; c12_i11++) {
    c12_b[c12_i11] = c12_b1d[c12_i11];
  }

  c12_b_a = c12_a[1];
  c12_b_b = c12_b[2];
  c12_y = c12_b_a * c12_b_b;
  c12_c_a = c12_a[2];
  c12_c_b = c12_b[1];
  c12_b_y = c12_c_a * c12_c_b;
  c12_c1 = c12_y - c12_b_y;
  c12_d_a = c12_a[2];
  c12_d_b = c12_b[0];
  c12_c_y = c12_d_a * c12_d_b;
  c12_e_a = c12_a[0];
  c12_e_b = c12_b[2];
  c12_d_y = c12_e_a * c12_e_b;
  c12_c2 = c12_c_y - c12_d_y;
  c12_f_a = c12_a[0];
  c12_f_b = c12_b[1];
  c12_e_y = c12_f_a * c12_f_b;
  c12_g_a = c12_a[1];
  c12_g_b = c12_b[0];
  c12_f_y = c12_g_a * c12_g_b;
  c12_c3 = c12_e_y - c12_f_y;
  c12_b2d[0] = c12_c1;
  c12_b2d[1] = c12_c2;
  c12_b2d[2] = c12_c3;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  for (c12_i12 = 0; c12_i12 < 3; c12_i12++) {
    c12_Rdes[c12_i12] = c12_b1d[c12_i12];
  }

  for (c12_i13 = 0; c12_i13 < 3; c12_i13++) {
    c12_Rdes[c12_i13 + 3] = c12_b2d[c12_i13];
  }

  for (c12_i14 = 0; c12_i14 < 3; c12_i14++) {
    c12_Rdes[c12_i14 + 6] = c12_b3d[c12_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c12_i15 = 0; c12_i15 < 3; c12_i15++) {
    (*c12_b_b2d)[c12_i15] = c12_b2d[c12_i15];
  }

  for (c12_i16 = 0; c12_i16 < 9; c12_i16++) {
    (*c12_b_Rdes)[c12_i16] = c12_Rdes[c12_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_QRsim(SFc12_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i17;
  int32_T c12_i18;
  int32_T c12_i19;
  real_T c12_b_inData[9];
  int32_T c12_i20;
  int32_T c12_i21;
  int32_T c12_i22;
  real_T c12_u[9];
  const mxArray *c12_y = NULL;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_i17 = 0;
  for (c12_i18 = 0; c12_i18 < 3; c12_i18++) {
    for (c12_i19 = 0; c12_i19 < 3; c12_i19++) {
      c12_b_inData[c12_i19 + c12_i17] = (*(real_T (*)[9])c12_inData)[c12_i19 +
        c12_i17];
    }

    c12_i17 += 3;
  }

  c12_i20 = 0;
  for (c12_i21 = 0; c12_i21 < 3; c12_i21++) {
    for (c12_i22 = 0; c12_i22 < 3; c12_i22++) {
      c12_u[c12_i22 + c12_i20] = c12_b_inData[c12_i22 + c12_i20];
    }

    c12_i20 += 3;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance, const
  mxArray *c12_Rdes, const char_T *c12_identifier, real_T c12_y[9])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_Rdes), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_Rdes);
}

static void c12_b_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[9])
{
  real_T c12_dv2[9];
  int32_T c12_i23;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c12_i23 = 0; c12_i23 < 9; c12_i23++) {
    c12_y[c12_i23] = c12_dv2[c12_i23];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_Rdes;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[9];
  int32_T c12_i24;
  int32_T c12_i25;
  int32_T c12_i26;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_Rdes = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_Rdes), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_Rdes);
  c12_i24 = 0;
  for (c12_i25 = 0; c12_i25 < 3; c12_i25++) {
    for (c12_i26 = 0; c12_i26 < 3; c12_i26++) {
      (*(real_T (*)[9])c12_outData)[c12_i26 + c12_i24] = c12_y[c12_i26 + c12_i24];
    }

    c12_i24 += 3;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i27;
  real_T c12_b_inData[3];
  int32_T c12_i28;
  real_T c12_u[3];
  const mxArray *c12_y = NULL;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i27 = 0; c12_i27 < 3; c12_i27++) {
    c12_b_inData[c12_i27] = (*(real_T (*)[3])c12_inData)[c12_i27];
  }

  for (c12_i28 = 0; c12_i28 < 3; c12_i28++) {
    c12_u[c12_i28] = c12_b_inData[c12_i28];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_c_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_b2d, const char_T *c12_identifier, real_T c12_y[3])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b2d), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_b2d);
}

static void c12_d_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3])
{
  real_T c12_dv3[3];
  int32_T c12_i29;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c12_i29 = 0; c12_i29 < 3; c12_i29++) {
    c12_y[c12_i29] = c12_dv3[c12_i29];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b2d;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[3];
  int32_T c12_i30;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_b2d = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b2d), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_b2d);
  for (c12_i30 = 0; c12_i30 < 3; c12_i30++) {
    (*(real_T (*)[3])c12_outData)[c12_i30] = c12_y[c12_i30];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i31;
  real_T c12_b_inData[3];
  int32_T c12_i32;
  real_T c12_u[3];
  const mxArray *c12_y = NULL;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i31 = 0; c12_i31 < 3; c12_i31++) {
    c12_b_inData[c12_i31] = (*(real_T (*)[3])c12_inData)[c12_i31];
  }

  for (c12_i32 = 0; c12_i32 < 3; c12_i32++) {
    c12_u[c12_i32] = c12_b_inData[c12_i32];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_e_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                FALSE);
  c12_info_helper(&c12_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(const mxArray **c12_info)
{
  const mxArray *c12_rhs0 = NULL;
  const mxArray *c12_lhs0 = NULL;
  const mxArray *c12_rhs1 = NULL;
  const mxArray *c12_lhs1 = NULL;
  const mxArray *c12_rhs2 = NULL;
  const mxArray *c12_lhs2 = NULL;
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("cross"), "name", "name", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c12_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c12_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("mtimes"), "name", "name", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c12_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c12_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c12_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c12_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c12_rhs0);
  sf_mex_destroy(&c12_lhs0);
  sf_mex_destroy(&c12_rhs1);
  sf_mex_destroy(&c12_lhs1);
  sf_mex_destroy(&c12_rhs2);
  sf_mex_destroy(&c12_lhs2);
}

static const mxArray *c12_emlrt_marshallOut(char * c12_u)
{
  const mxArray *c12_y = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c12_u)), FALSE);
  return c12_y;
}

static const mxArray *c12_b_emlrt_marshallOut(uint32_T c12_u)
{
  const mxArray *c12_y = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c12_y;
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_f_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i33;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i33, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i33;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_g_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_b_is_active_c12_QRsim, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_QRsim), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_QRsim);
  return c12_y;
}

static uint8_T c12_h_emlrt_marshallIn(SFc12_QRsimInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_QRsimInstanceStruct *chartInstance)
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

void sf_c12_QRsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4044917162U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2662055638U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(242481529U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1624246117U);
}

mxArray *sf_c12_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LNnM0QnAvlVArKn1T5VrgG");
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
      pr[1] = (double)(3);
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

mxArray *sf_c12_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c12_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Rdes\",},{M[1],M[7],T\"b2d\",},{M[8],M[0],T\"is_active_c12_QRsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc12_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           12,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"b2d");
          _SFD_SET_DATA_PROPS(1,1,1,0,"b1d");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Rdes");
          _SFD_SET_DATA_PROPS(3,1,1,0,"b3d");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,84);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
            c12_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)
            c12_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c12_b2d)[3];
          real_T (*c12_b1d)[3];
          real_T (*c12_Rdes)[9];
          real_T (*c12_b3d)[3];
          c12_b3d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c12_Rdes = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c12_b1d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c12_b2d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c12_b2d);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_b1d);
          _SFD_SET_DATA_VALUE_PTR(2U, *c12_Rdes);
          _SFD_SET_DATA_VALUE_PTR(3U, *c12_b3d);
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
  return "3DeAe7C3wpw3PJdKGpTuhC";
}

static void sf_opaque_initialize_c12_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_QRsim(void *chartInstanceVar)
{
  enable_c12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_QRsim(void *chartInstanceVar)
{
  disable_c12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_QRsim(void *chartInstanceVar)
{
  sf_c12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_QRsim((SFc12_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c12_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_QRsim((SFc12_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_QRsim(S);
}

static void sf_opaque_set_sim_state_c12_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c12_QRsim(S, st);
}

static void sf_opaque_terminate_c12_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_QRsim((SFc12_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_QRsim((SFc12_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1211473350U));
  ssSetChecksum1(S,(2480476841U));
  ssSetChecksum2(S,(1369728679U));
  ssSetChecksum3(S,(149477323U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_QRsim(SimStruct *S)
{
  SFc12_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc12_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc12_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c12_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_QRsim;
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

void c12_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
