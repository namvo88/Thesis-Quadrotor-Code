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
static const char * c4_debug_family_names[12] = { "db1c", "ddb1c", "nargin",
  "nargout", "b2c", "db2c", "ddb2c", "b3c", "db3c", "ddb3c", "dRc", "ddRc" };

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
static void initSimStructsc4_QRLsim(SFc4_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance, const
  mxArray *c4_ddRc, const char_T *c4_identifier, real_T c4_y[9]);
static void c4_b_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_d_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(uint32_T c4_u);
static void c4_cross(SFc4_QRLsimInstanceStruct *chartInstance, real_T c4_a[3],
                     real_T c4_b[3], real_T c4_c[3]);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  real_T c4_u[9];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[9];
  const mxArray *c4_c_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T (*c4_ddRc)[9];
  real_T (*c4_dRc)[9];
  c4_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(3), FALSE);
  for (c4_i0 = 0; c4_i0 < 9; c4_i0++) {
    c4_u[c4_i0] = (*c4_dRc)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 9; c4_i1++) {
    c4_b_u[c4_i1] = (*c4_ddRc)[c4_i1];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_QRLsim;
  c4_c_u = c4_hoistedGlobal;
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
  real_T c4_dv0[9];
  int32_T c4_i2;
  real_T c4_dv1[9];
  int32_T c4_i3;
  real_T (*c4_dRc)[9];
  real_T (*c4_ddRc)[9];
  c4_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "dRc",
                      c4_dv0);
  for (c4_i2 = 0; c4_i2 < 9; c4_i2++) {
    (*c4_dRc)[c4_i2] = c4_dv0[c4_i2];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "ddRc",
                      c4_dv1);
  for (c4_i3 = 0; c4_i3 < 9; c4_i3++) {
    (*c4_ddRc)[c4_i3] = c4_dv1[c4_i3];
  }

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
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  real_T c4_b2c[3];
  int32_T c4_i13;
  real_T c4_db2c[3];
  int32_T c4_i14;
  real_T c4_ddb2c[3];
  int32_T c4_i15;
  real_T c4_b3c[3];
  int32_T c4_i16;
  real_T c4_db3c[3];
  int32_T c4_i17;
  real_T c4_ddb3c[3];
  uint32_T c4_debug_family_var_map[12];
  real_T c4_db1c[3];
  real_T c4_ddb1c[3];
  real_T c4_nargin = 6.0;
  real_T c4_nargout = 2.0;
  real_T c4_dRc[9];
  real_T c4_ddRc[9];
  int32_T c4_i18;
  real_T c4_b_db2c[3];
  int32_T c4_i19;
  real_T c4_b_b3c[3];
  real_T c4_dv2[3];
  int32_T c4_i20;
  real_T c4_b_b2c[3];
  int32_T c4_i21;
  real_T c4_b_db3c[3];
  real_T c4_dv3[3];
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  real_T c4_c_db2c[3];
  int32_T c4_i27;
  real_T c4_c_db3c[3];
  real_T c4_b[3];
  int32_T c4_i28;
  int32_T c4_i29;
  real_T c4_b_ddb2c[3];
  int32_T c4_i30;
  real_T c4_c_b3c[3];
  int32_T c4_i31;
  real_T c4_c_b2c[3];
  int32_T c4_i32;
  real_T c4_b_ddb3c[3];
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  real_T (*c4_b_dRc)[9];
  real_T (*c4_b_ddRc)[9];
  real_T (*c4_c_ddb3c)[3];
  real_T (*c4_d_db3c)[3];
  real_T (*c4_d_b3c)[3];
  real_T (*c4_c_ddb2c)[3];
  real_T (*c4_d_db2c)[3];
  real_T (*c4_d_b2c)[3];
  c4_b_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_c_ddb3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c4_d_db3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_d_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c4_c_ddb2c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c4_d_db2c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c4_d_b2c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_d_b2c)[c4_i4], 0U);
  }

  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    _SFD_DATA_RANGE_CHECK((*c4_d_db2c)[c4_i5], 1U);
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_ddb2c)[c4_i6], 2U);
  }

  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    _SFD_DATA_RANGE_CHECK((*c4_d_b3c)[c4_i7], 3U);
  }

  for (c4_i8 = 0; c4_i8 < 9; c4_i8++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_dRc)[c4_i8], 4U);
  }

  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    _SFD_DATA_RANGE_CHECK((*c4_d_db3c)[c4_i9], 5U);
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_ddb3c)[c4_i10], 6U);
  }

  for (c4_i11 = 0; c4_i11 < 9; c4_i11++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_ddRc)[c4_i11], 7U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_b2c[c4_i12] = (*c4_d_b2c)[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_db2c[c4_i13] = (*c4_d_db2c)[c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_ddb2c[c4_i14] = (*c4_c_ddb2c)[c4_i14];
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_b3c[c4_i15] = (*c4_d_b3c)[c4_i15];
  }

  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    c4_db3c[c4_i16] = (*c4_d_db3c)[c4_i16];
  }

  for (c4_i17 = 0; c4_i17 < 3; c4_i17++) {
    c4_ddb3c[c4_i17] = (*c4_c_ddb3c)[c4_i17];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_db1c, 0U, c4_b_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_ddb1c, 1U, c4_b_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 2U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 3U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b2c, 4U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_db2c, 5U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_ddb2c, 6U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b3c, 7U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_db3c, 8U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_ddb3c, 9U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_dRc, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_ddRc, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    c4_b_db2c[c4_i18] = c4_db2c[c4_i18];
  }

  for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
    c4_b_b3c[c4_i19] = c4_b3c[c4_i19];
  }

  c4_cross(chartInstance, c4_b_db2c, c4_b_b3c, c4_dv2);
  for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
    c4_b_b2c[c4_i20] = c4_b2c[c4_i20];
  }

  for (c4_i21 = 0; c4_i21 < 3; c4_i21++) {
    c4_b_db3c[c4_i21] = c4_db3c[c4_i21];
  }

  c4_cross(chartInstance, c4_b_b2c, c4_b_db3c, c4_dv3);
  for (c4_i22 = 0; c4_i22 < 3; c4_i22++) {
    c4_db1c[c4_i22] = c4_dv2[c4_i22] + c4_dv3[c4_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i23 = 0; c4_i23 < 3; c4_i23++) {
    c4_dRc[c4_i23] = c4_db1c[c4_i23];
  }

  for (c4_i24 = 0; c4_i24 < 3; c4_i24++) {
    c4_dRc[c4_i24 + 3] = c4_db2c[c4_i24];
  }

  for (c4_i25 = 0; c4_i25 < 3; c4_i25++) {
    c4_dRc[c4_i25 + 6] = c4_db3c[c4_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  for (c4_i26 = 0; c4_i26 < 3; c4_i26++) {
    c4_c_db2c[c4_i26] = c4_db2c[c4_i26];
  }

  for (c4_i27 = 0; c4_i27 < 3; c4_i27++) {
    c4_c_db3c[c4_i27] = c4_db3c[c4_i27];
  }

  c4_cross(chartInstance, c4_c_db2c, c4_c_db3c, c4_b);
  for (c4_i28 = 0; c4_i28 < 3; c4_i28++) {
    c4_b[c4_i28] *= 2.0;
  }

  for (c4_i29 = 0; c4_i29 < 3; c4_i29++) {
    c4_b_ddb2c[c4_i29] = c4_ddb2c[c4_i29];
  }

  for (c4_i30 = 0; c4_i30 < 3; c4_i30++) {
    c4_c_b3c[c4_i30] = c4_b3c[c4_i30];
  }

  c4_cross(chartInstance, c4_b_ddb2c, c4_c_b3c, c4_dv2);
  for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
    c4_c_b2c[c4_i31] = c4_b2c[c4_i31];
  }

  for (c4_i32 = 0; c4_i32 < 3; c4_i32++) {
    c4_b_ddb3c[c4_i32] = c4_ddb3c[c4_i32];
  }

  c4_cross(chartInstance, c4_c_b2c, c4_b_ddb3c, c4_dv3);
  for (c4_i33 = 0; c4_i33 < 3; c4_i33++) {
    c4_ddb1c[c4_i33] = (c4_dv2[c4_i33] + c4_b[c4_i33]) + c4_dv3[c4_i33];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  for (c4_i34 = 0; c4_i34 < 3; c4_i34++) {
    c4_ddRc[c4_i34] = c4_ddb1c[c4_i34];
  }

  for (c4_i35 = 0; c4_i35 < 3; c4_i35++) {
    c4_ddRc[c4_i35 + 3] = c4_ddb2c[c4_i35];
  }

  for (c4_i36 = 0; c4_i36 < 3; c4_i36++) {
    c4_ddRc[c4_i36 + 6] = c4_ddb3c[c4_i36];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i37 = 0; c4_i37 < 9; c4_i37++) {
    (*c4_b_dRc)[c4_i37] = c4_dRc[c4_i37];
  }

  for (c4_i38 = 0; c4_i38 < 9; c4_i38++) {
    (*c4_b_ddRc)[c4_i38] = c4_ddRc[c4_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
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
  int32_T c4_i39;
  int32_T c4_i40;
  int32_T c4_i41;
  real_T c4_b_inData[9];
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i39 = 0;
  for (c4_i40 = 0; c4_i40 < 3; c4_i40++) {
    for (c4_i41 = 0; c4_i41 < 3; c4_i41++) {
      c4_b_inData[c4_i41 + c4_i39] = (*(real_T (*)[9])c4_inData)[c4_i41 + c4_i39];
    }

    c4_i39 += 3;
  }

  c4_i42 = 0;
  for (c4_i43 = 0; c4_i43 < 3; c4_i43++) {
    for (c4_i44 = 0; c4_i44 < 3; c4_i44++) {
      c4_u[c4_i44 + c4_i42] = c4_b_inData[c4_i44 + c4_i42];
    }

    c4_i42 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance, const
  mxArray *c4_ddRc, const char_T *c4_identifier, real_T c4_y[9])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ddRc), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_ddRc);
}

static void c4_b_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9])
{
  real_T c4_dv4[9];
  int32_T c4_i45;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv4, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i45 = 0; c4_i45 < 9; c4_i45++) {
    c4_y[c4_i45] = c4_dv4[c4_i45];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ddRc;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[9];
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_ddRc = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ddRc), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_ddRc);
  c4_i46 = 0;
  for (c4_i47 = 0; c4_i47 < 3; c4_i47++) {
    for (c4_i48 = 0; c4_i48 < 3; c4_i48++) {
      (*(real_T (*)[9])c4_outData)[c4_i48 + c4_i46] = c4_y[c4_i48 + c4_i46];
    }

    c4_i46 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i49;
  real_T c4_b_inData[3];
  int32_T c4_i50;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i49 = 0; c4_i49 < 3; c4_i49++) {
    c4_b_inData[c4_i49] = (*(real_T (*)[3])c4_inData)[c4_i49];
  }

  for (c4_i50 = 0; c4_i50 < 3; c4_i50++) {
    c4_u[c4_i50] = c4_b_inData[c4_i50];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
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
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static void c4_d_emlrt_marshallIn(SFc4_QRLsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3])
{
  real_T c4_dv5[3];
  int32_T c4_i51;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i51 = 0; c4_i51 < 3; c4_i51++) {
    c4_y[c4_i51] = c4_dv5[c4_i51];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ddb1c;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i52;
  SFc4_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QRLsimInstanceStruct *)chartInstanceVoid;
  c4_ddb1c = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ddb1c), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_ddb1c);
  for (c4_i52 = 0; c4_i52 < 3; c4_i52++) {
    (*(real_T (*)[3])c4_outData)[c4_i52] = c4_y[c4_i52];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("cross"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mtimes"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mtimes"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
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
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
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

static void c4_cross(SFc4_QRLsimInstanceStruct *chartInstance, real_T c4_a[3],
                     real_T c4_b[3], real_T c4_c[3])
{
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_y;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_b_y;
  real_T c4_c1;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_c_y;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_d_y;
  real_T c4_c2;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_e_y;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_f_y;
  real_T c4_c3;
  c4_b_a = c4_a[1];
  c4_b_b = c4_b[2];
  c4_y = c4_b_a * c4_b_b;
  c4_c_a = c4_a[2];
  c4_c_b = c4_b[1];
  c4_b_y = c4_c_a * c4_c_b;
  c4_c1 = c4_y - c4_b_y;
  c4_d_a = c4_a[2];
  c4_d_b = c4_b[0];
  c4_c_y = c4_d_a * c4_d_b;
  c4_e_a = c4_a[0];
  c4_e_b = c4_b[2];
  c4_d_y = c4_e_a * c4_e_b;
  c4_c2 = c4_c_y - c4_d_y;
  c4_f_a = c4_a[0];
  c4_f_b = c4_b[1];
  c4_e_y = c4_f_a * c4_f_b;
  c4_g_a = c4_a[1];
  c4_g_b = c4_b[0];
  c4_f_y = c4_g_a * c4_g_b;
  c4_c3 = c4_e_y - c4_f_y;
  c4_c[0] = c4_c1;
  c4_c[1] = c4_c2;
  c4_c[2] = c4_c3;
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
  int32_T c4_i53;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i53, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i53;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2659236666U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3915877447U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(143250804U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3172606028U);
}

mxArray *sf_c4_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("djZnVMGawVw3CRgsS0NYCD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"dRc\",},{M[1],M[14],T\"ddRc\",},{M[8],M[0],T\"is_active_c4_QRLsim\",}}"
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
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"b2c");
          _SFD_SET_DATA_PROPS(1,1,1,0,"db2c");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ddb2c");
          _SFD_SET_DATA_PROPS(3,1,1,0,"b3c");
          _SFD_SET_DATA_PROPS(4,2,0,1,"dRc");
          _SFD_SET_DATA_PROPS(5,1,1,0,"db3c");
          _SFD_SET_DATA_PROPS(6,1,1,0,"ddb3c");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ddRc");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,574);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real_T (*c4_b2c)[3];
          real_T (*c4_db2c)[3];
          real_T (*c4_ddb2c)[3];
          real_T (*c4_b3c)[3];
          real_T (*c4_dRc)[9];
          real_T (*c4_db3c)[3];
          real_T (*c4_ddb3c)[3];
          real_T (*c4_ddRc)[9];
          c4_ddRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_ddb3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c4_db3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c4_dRc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c4_ddb2c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c4_db2c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c4_b2c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_b2c);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_db2c);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_ddb2c);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_b3c);
          _SFD_SET_DATA_VALUE_PTR(4U, *c4_dRc);
          _SFD_SET_DATA_VALUE_PTR(5U, *c4_db3c);
          _SFD_SET_DATA_VALUE_PTR(6U, *c4_ddb3c);
          _SFD_SET_DATA_VALUE_PTR(7U, *c4_ddRc);
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
  return "o9aGfqOTtMR5orq5qtQpH";
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
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
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
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3487024775U));
  ssSetChecksum1(S,(1358730415U));
  ssSetChecksum2(S,(1430655603U));
  ssSetChecksum3(S,(3889696146U));
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
