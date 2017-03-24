/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c5_QRsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
<<<<<<< HEAD
static const char * c5_debug_family_names[5] = { "nargin", "nargout", "Rdes",
  "dRdes", "Omegadeshat" };
=======
static const char * c5_debug_family_names[11] = { "eOmegahat", "ep", "eq", "er",
  "eOmega", "nargin", "nargout", "RdesTR", "dRdesTR", "Omega", "Omegades" };
>>>>>>> developErrorAngularVelocity

/* Function Declarations */
static void initialize_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void initialize_params_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void enable_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void disable_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_QRsim(SFc5_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_QRsim(SFc5_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void sf_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void c5_chartstep_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void initSimStructsc5_QRsim(SFc5_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c5_Omegadeshat, const char_T *c5_identifier, real_T c5_y[9]);
static void c5_b_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9]);
=======
  mxArray *c5_Omegades, const char_T *c5_identifier, real_T c5_y[3]);
static void c5_b_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3]);
>>>>>>> developErrorAngularVelocity
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
<<<<<<< HEAD
=======
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
>>>>>>> developErrorAngularVelocity
static real_T c5_c_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
<<<<<<< HEAD
=======
static void c5_d_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
>>>>>>> developErrorAngularVelocity
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(uint32_T c5_u);
static void c5_eml_scalar_eg(SFc5_QRsimInstanceStruct *chartInstance);
<<<<<<< HEAD
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_QRsim, const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
=======
static void c5_b_eml_scalar_eg(SFc5_QRsimInstanceStruct *chartInstance);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_QRsim, const char_T *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
>>>>>>> developErrorAngularVelocity
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_QRsim = 0U;
}

static void initialize_params_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_QRsim(SFc5_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_QRsim(SFc5_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
<<<<<<< HEAD
  real_T c5_u[9];
=======
  real_T c5_u[3];
>>>>>>> developErrorAngularVelocity
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
<<<<<<< HEAD
  real_T (*c5_Omegadeshat)[9];
  c5_Omegadeshat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
=======
  real_T (*c5_Omegades)[3];
  c5_Omegades = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
>>>>>>> developErrorAngularVelocity
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
<<<<<<< HEAD
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    c5_u[c5_i0] = (*c5_Omegadeshat)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
=======
  for (c5_i0 = 0; c5_i0 < 3; c5_i0++) {
    c5_u[c5_i0] = (*c5_Omegades)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
>>>>>>> developErrorAngularVelocity
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_QRsim;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
<<<<<<< HEAD
  real_T c5_dv0[9];
  int32_T c5_i1;
  real_T (*c5_Omegadeshat)[9];
  c5_Omegadeshat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "Omegadeshat", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    (*c5_Omegadeshat)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_QRsim = c5_e_emlrt_marshallIn(chartInstance,
=======
  real_T c5_dv0[3];
  int32_T c5_i1;
  real_T (*c5_Omegades)[3];
  c5_Omegades = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "Omegades", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    (*c5_Omegades)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_QRsim = c5_f_emlrt_marshallIn(chartInstance,
>>>>>>> developErrorAngularVelocity
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_active_c5_QRsim");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_QRsim(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
<<<<<<< HEAD
  real_T (*c5_Omegadeshat)[9];
  real_T (*c5_dRdes)[9];
  real_T (*c5_Rdes)[9];
  c5_Omegadeshat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_dRdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c5_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
=======
  int32_T c5_i5;
  real_T (*c5_Omega)[3];
  real_T (*c5_Omegades)[3];
  real_T (*c5_dRdesTR)[9];
  real_T (*c5_RdesTR)[9];
  c5_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c5_Omegades = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_dRdesTR = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c5_RdesTR = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
>>>>>>> developErrorAngularVelocity
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
<<<<<<< HEAD
    _SFD_DATA_RANGE_CHECK((*c5_Rdes)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 9; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_dRdes)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_Omegadeshat)[c5_i4], 2U);
=======
    _SFD_DATA_RANGE_CHECK((*c5_RdesTR)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 9; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_dRdesTR)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_Omegades)[c5_i4], 2U);
  }

  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_Omega)[c5_i5], 3U);
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
<<<<<<< HEAD
  int32_T c5_i5;
  real_T c5_Rdes[9];
  int32_T c5_i6;
  real_T c5_dRdes[9];
  uint32_T c5_debug_family_var_map[5];
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  real_T c5_Omegadeshat[9];
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  real_T c5_a[9];
  int32_T c5_i11;
  real_T c5_b[9];
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  real_T c5_C[9];
  int32_T c5_i15;
  int32_T c5_i16;
=======
  int32_T c5_i6;
  real_T c5_RdesTR[9];
  int32_T c5_i7;
  real_T c5_dRdesTR[9];
  int32_T c5_i8;
  real_T c5_Omega[3];
  uint32_T c5_debug_family_var_map[11];
  real_T c5_eOmegahat[9];
  real_T c5_ep;
  real_T c5_eq;
  real_T c5_er;
  real_T c5_eOmega[3];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_Omegades[3];
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  real_T c5_a[9];
  int32_T c5_i13;
  real_T c5_b[9];
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  real_T c5_C[9];
>>>>>>> developErrorAngularVelocity
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
<<<<<<< HEAD
  real_T (*c5_b_Omegadeshat)[9];
  real_T (*c5_b_dRdes)[9];
  real_T (*c5_b_Rdes)[9];
  c5_b_Omegadeshat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_dRdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i5 = 0; c5_i5 < 9; c5_i5++) {
    c5_Rdes[c5_i5] = (*c5_b_Rdes)[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 9; c5_i6++) {
    c5_dRdes[c5_i6] = (*c5_b_dRdes)[c5_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_Rdes, 2U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_dRdes, 3U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Omegadeshat, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_i7 = 0;
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_i9 = 0;
    for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
      c5_a[c5_i10 + c5_i7] = c5_Rdes[c5_i9 + c5_i8];
      c5_i9 += 3;
    }

    c5_i7 += 3;
  }

  for (c5_i11 = 0; c5_i11 < 9; c5_i11++) {
    c5_b[c5_i11] = c5_dRdes[c5_i11];
=======
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  real_T c5_b_b[3];
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  real_T c5_b_C[3];
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  real_T (*c5_b_Omegades)[3];
  real_T (*c5_b_Omega)[3];
  real_T (*c5_b_dRdesTR)[9];
  real_T (*c5_b_RdesTR)[9];
  c5_b_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_Omegades = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_dRdesTR = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_RdesTR = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i6 = 0; c5_i6 < 9; c5_i6++) {
    c5_RdesTR[c5_i6] = (*c5_b_RdesTR)[c5_i6];
  }

  for (c5_i7 = 0; c5_i7 < 9; c5_i7++) {
    c5_dRdesTR[c5_i7] = (*c5_b_dRdesTR)[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_Omega[c5_i8] = (*c5_b_Omega)[c5_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_eOmegahat, 0U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_ep, 1U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_eq, 2U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_er, 3U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_eOmega, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 5U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 6U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_RdesTR, 7U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_dRdesTR, 8U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_Omega, 9U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Omegades, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_i9 = 0;
  for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
    c5_i11 = 0;
    for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
      c5_a[c5_i12 + c5_i9] = c5_RdesTR[c5_i11 + c5_i10];
      c5_i11 += 3;
    }

    c5_i9 += 3;
  }

  for (c5_i13 = 0; c5_i13 < 9; c5_i13++) {
    c5_b[c5_i13] = c5_dRdesTR[c5_i13];
>>>>>>> developErrorAngularVelocity
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
<<<<<<< HEAD
  for (c5_i12 = 0; c5_i12 < 9; c5_i12++) {
    c5_Omegadeshat[c5_i12] = 0.0;
  }

  for (c5_i13 = 0; c5_i13 < 9; c5_i13++) {
    c5_Omegadeshat[c5_i13] = 0.0;
  }

  for (c5_i14 = 0; c5_i14 < 9; c5_i14++) {
    c5_C[c5_i14] = c5_Omegadeshat[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 9; c5_i15++) {
    c5_Omegadeshat[c5_i15] = c5_C[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 9; c5_i16++) {
    c5_C[c5_i16] = c5_Omegadeshat[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 9; c5_i17++) {
    c5_Omegadeshat[c5_i17] = c5_C[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_i19 = 0;
    for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
      c5_Omegadeshat[c5_i19 + c5_i18] = 0.0;
      c5_i21 = 0;
      for (c5_i22 = 0; c5_i22 < 3; c5_i22++) {
        c5_Omegadeshat[c5_i19 + c5_i18] += c5_a[c5_i21 + c5_i18] * c5_b[c5_i22 +
          c5_i19];
        c5_i21 += 3;
      }

      c5_i19 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i23 = 0; c5_i23 < 9; c5_i23++) {
    (*c5_b_Omegadeshat)[c5_i23] = c5_Omegadeshat[c5_i23];
=======
  for (c5_i14 = 0; c5_i14 < 9; c5_i14++) {
    c5_eOmegahat[c5_i14] = 0.0;
  }

  for (c5_i15 = 0; c5_i15 < 9; c5_i15++) {
    c5_eOmegahat[c5_i15] = 0.0;
  }

  for (c5_i16 = 0; c5_i16 < 9; c5_i16++) {
    c5_C[c5_i16] = c5_eOmegahat[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 9; c5_i17++) {
    c5_eOmegahat[c5_i17] = c5_C[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 9; c5_i18++) {
    c5_C[c5_i18] = c5_eOmegahat[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 9; c5_i19++) {
    c5_eOmegahat[c5_i19] = c5_C[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
    c5_i21 = 0;
    for (c5_i22 = 0; c5_i22 < 3; c5_i22++) {
      c5_eOmegahat[c5_i21 + c5_i20] = 0.0;
      c5_i23 = 0;
      for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
        c5_eOmegahat[c5_i21 + c5_i20] += c5_a[c5_i23 + c5_i20] * c5_b[c5_i24 +
          c5_i21];
        c5_i23 += 3;
      }

      c5_i21 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_ep = c5_eOmegahat[5];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_eq = -c5_eOmegahat[2];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_er = c5_eOmegahat[1];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_eOmega[0] = c5_ep;
  c5_eOmega[1] = c5_eq;
  c5_eOmega[2] = c5_er;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i25 = 0; c5_i25 < 9; c5_i25++) {
    c5_a[c5_i25] = -c5_RdesTR[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
    c5_b_b[c5_i26] = c5_eOmega[c5_i26] - c5_Omega[c5_i26];
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i27 = 0; c5_i27 < 3; c5_i27++) {
    c5_Omegades[c5_i27] = 0.0;
  }

  for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
    c5_Omegades[c5_i28] = 0.0;
  }

  for (c5_i29 = 0; c5_i29 < 3; c5_i29++) {
    c5_b_C[c5_i29] = c5_Omegades[c5_i29];
  }

  for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
    c5_Omegades[c5_i30] = c5_b_C[c5_i30];
  }

  for (c5_i31 = 0; c5_i31 < 3; c5_i31++) {
    c5_b_C[c5_i31] = c5_Omegades[c5_i31];
  }

  for (c5_i32 = 0; c5_i32 < 3; c5_i32++) {
    c5_Omegades[c5_i32] = c5_b_C[c5_i32];
  }

  for (c5_i33 = 0; c5_i33 < 3; c5_i33++) {
    c5_Omegades[c5_i33] = 0.0;
    c5_i34 = 0;
    for (c5_i35 = 0; c5_i35 < 3; c5_i35++) {
      c5_Omegades[c5_i33] += c5_a[c5_i34 + c5_i33] * c5_b_b[c5_i35];
      c5_i34 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i36 = 0; c5_i36 < 3; c5_i36++) {
    (*c5_b_Omegades)[c5_i36] = c5_Omegades[c5_i36];
>>>>>>> developErrorAngularVelocity
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_QRsim(SFc5_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  real_T c5_b_inData[9];
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  real_T c5_u[9];
=======
  int32_T c5_i37;
  real_T c5_b_inData[3];
  int32_T c5_i38;
  real_T c5_u[3];
>>>>>>> developErrorAngularVelocity
  const mxArray *c5_y = NULL;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
<<<<<<< HEAD
  c5_i24 = 0;
  for (c5_i25 = 0; c5_i25 < 3; c5_i25++) {
    for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
      c5_b_inData[c5_i26 + c5_i24] = (*(real_T (*)[9])c5_inData)[c5_i26 + c5_i24];
    }

    c5_i24 += 3;
  }

  c5_i27 = 0;
  for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
    for (c5_i29 = 0; c5_i29 < 3; c5_i29++) {
      c5_u[c5_i29 + c5_i27] = c5_b_inData[c5_i29 + c5_i27];
    }

    c5_i27 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
=======
  for (c5_i37 = 0; c5_i37 < 3; c5_i37++) {
    c5_b_inData[c5_i37] = (*(real_T (*)[3])c5_inData)[c5_i37];
  }

  for (c5_i38 = 0; c5_i38 < 3; c5_i38++) {
    c5_u[c5_i38] = c5_b_inData[c5_i38];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
>>>>>>> developErrorAngularVelocity
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c5_Omegadeshat, const char_T *c5_identifier, real_T c5_y[9])
=======
  mxArray *c5_Omegades, const char_T *c5_identifier, real_T c5_y[3])
>>>>>>> developErrorAngularVelocity
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
<<<<<<< HEAD
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Omegadeshat), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_Omegadeshat);
}

static void c5_b_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9])
{
  real_T c5_dv1[9];
  int32_T c5_i30;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i30 = 0; c5_i30 < 9; c5_i30++) {
    c5_y[c5_i30] = c5_dv1[c5_i30];
=======
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Omegades), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Omegades);
}

static void c5_b_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3])
{
  real_T c5_dv1[3];
  int32_T c5_i39;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i39 = 0; c5_i39 < 3; c5_i39++) {
    c5_y[c5_i39] = c5_dv1[c5_i39];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
<<<<<<< HEAD
  const mxArray *c5_Omegadeshat;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_Omegadeshat = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Omegadeshat), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_Omegadeshat);
  c5_i31 = 0;
  for (c5_i32 = 0; c5_i32 < 3; c5_i32++) {
    for (c5_i33 = 0; c5_i33 < 3; c5_i33++) {
      (*(real_T (*)[9])c5_outData)[c5_i33 + c5_i31] = c5_y[c5_i33 + c5_i31];
    }

    c5_i31 += 3;
=======
  const mxArray *c5_Omegades;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i40;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_Omegades = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Omegades), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Omegades);
  for (c5_i40 = 0; c5_i40 < 3; c5_i40++) {
    (*(real_T (*)[3])c5_outData)[c5_i40] = c5_y[c5_i40];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
<<<<<<< HEAD
=======
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  real_T c5_b_inData[9];
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i41 = 0;
  for (c5_i42 = 0; c5_i42 < 3; c5_i42++) {
    for (c5_i43 = 0; c5_i43 < 3; c5_i43++) {
      c5_b_inData[c5_i43 + c5_i41] = (*(real_T (*)[9])c5_inData)[c5_i43 + c5_i41];
    }

    c5_i41 += 3;
  }

  c5_i44 = 0;
  for (c5_i45 = 0; c5_i45 < 3; c5_i45++) {
    for (c5_i46 = 0; c5_i46 < 3; c5_i46++) {
      c5_u[c5_i46 + c5_i44] = c5_b_inData[c5_i46 + c5_i44];
    }

    c5_i44 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
>>>>>>> developErrorAngularVelocity
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

<<<<<<< HEAD
=======
static void c5_d_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9])
{
  real_T c5_dv2[9];
  int32_T c5_i47;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i47 = 0; c5_i47 < 9; c5_i47++) {
    c5_y[c5_i47] = c5_dv2[c5_i47];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_eOmegahat;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_eOmegahat = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_eOmegahat), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_eOmegahat);
  c5_i48 = 0;
  for (c5_i49 = 0; c5_i49 < 3; c5_i49++) {
    for (c5_i50 = 0; c5_i50 < 3; c5_i50++) {
      (*(real_T (*)[9])c5_outData)[c5_i50 + c5_i48] = c5_y[c5_i50 + c5_i48];
    }

    c5_i48 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

>>>>>>> developErrorAngularVelocity
const mxArray *sf_c5_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xgemm"), "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
}

static const mxArray *c5_emlrt_marshallOut(char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), FALSE);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c5_y;
}

static void c5_eml_scalar_eg(SFc5_QRsimInstanceStruct *chartInstance)
{
}

<<<<<<< HEAD
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
=======
static void c5_b_eml_scalar_eg(SFc5_QRsimInstanceStruct *chartInstance)
{
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
>>>>>>> developErrorAngularVelocity
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

<<<<<<< HEAD
static int32_T c5_d_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i34;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i34, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i34;
=======
static int32_T c5_e_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i51;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i51, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i51;
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c5_u);
  return c5_y;
}

<<<<<<< HEAD
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
=======
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
>>>>>>> developErrorAngularVelocity
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
<<<<<<< HEAD
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
=======
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
>>>>>>> developErrorAngularVelocity
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

<<<<<<< HEAD
static uint8_T c5_e_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
=======
static uint8_T c5_f_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
>>>>>>> developErrorAngularVelocity
  const mxArray *c5_b_is_active_c5_QRsim, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
<<<<<<< HEAD
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_is_active_c5_QRsim),
=======
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_is_active_c5_QRsim),
>>>>>>> developErrorAngularVelocity
    &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_QRsim);
  return c5_y;
}

<<<<<<< HEAD
static uint8_T c5_f_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
=======
static uint8_T c5_g_emlrt_marshallIn(SFc5_QRsimInstanceStruct *chartInstance,
>>>>>>> developErrorAngularVelocity
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_QRsimInstanceStruct *chartInstance)
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

void sf_c5_QRsim_get_check_sum(mxArray *plhs[])
{
<<<<<<< HEAD
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(286620627U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3850572239U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3430121990U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3748439711U);
=======
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1021709142U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(615898448U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1804500372U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3450363590U);
>>>>>>> developErrorAngularVelocity
}

mxArray *sf_c5_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("K9ui59ddFLFeQX7s8eEri");
=======
    mxArray *mxChecksum = mxCreateString("0gVztOl6bY4pn06vHipu3D");
>>>>>>> developErrorAngularVelocity
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

<<<<<<< HEAD
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
=======
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
>>>>>>> developErrorAngularVelocity

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
<<<<<<< HEAD
=======

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
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
      pr[1] = (double)(3);
=======
      pr[1] = (double)(1);
>>>>>>> developErrorAngularVelocity
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

mxArray *sf_c5_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
<<<<<<< HEAD
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"Omegadeshat\",},{M[8],M[0],T\"is_active_c5_QRsim\",}}"
=======
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"Omegades\",},{M[8],M[0],T\"is_active_c5_QRsim\",}}"
>>>>>>> developErrorAngularVelocity
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc5_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           5,
           1,
           1,
<<<<<<< HEAD
           3,
=======
           4,
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
          _SFD_SET_DATA_PROPS(0,1,1,0,"Rdes");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dRdes");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Omegadeshat");
=======
          _SFD_SET_DATA_PROPS(0,1,1,0,"RdesTR");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dRdesTR");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Omegades");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Omega");
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,96);
=======
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,196);
>>>>>>> developErrorAngularVelocity

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
<<<<<<< HEAD
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
=======
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
>>>>>>> developErrorAngularVelocity
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
<<<<<<< HEAD
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
=======
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
>>>>>>> developErrorAngularVelocity
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
<<<<<<< HEAD
          real_T (*c5_Rdes)[9];
          real_T (*c5_dRdes)[9];
          real_T (*c5_Omegadeshat)[9];
          c5_Omegadeshat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S,
            1);
          c5_dRdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c5_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_Rdes);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_dRdes);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_Omegadeshat);
=======
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c5_RdesTR)[9];
          real_T (*c5_dRdesTR)[9];
          real_T (*c5_Omegades)[3];
          real_T (*c5_Omega)[3];
          c5_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c5_Omegades = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_dRdesTR = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c5_RdesTR = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_RdesTR);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_dRdesTR);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_Omegades);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_Omega);
>>>>>>> developErrorAngularVelocity
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
<<<<<<< HEAD
  return "IFMCcRpINhqNYKUUq3z4O";
=======
  return "Xm8g1Gf7YbhQk71BryHoIH";
>>>>>>> developErrorAngularVelocity
}

static void sf_opaque_initialize_c5_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_QRsimInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_QRsim(void *chartInstanceVar)
{
  enable_c5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_QRsim(void *chartInstanceVar)
{
  disable_c5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_QRsim(void *chartInstanceVar)
{
  sf_c5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_QRsim((SFc5_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c5_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_QRsim((SFc5_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_QRsim(S);
}

static void sf_opaque_set_sim_state_c5_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_QRsim(S, st);
}

static void sf_opaque_terminate_c5_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_QRsim((SFc5_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_QRsim((SFc5_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
<<<<<<< HEAD
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
=======
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
>>>>>>> developErrorAngularVelocity
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
<<<<<<< HEAD
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
=======
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
>>>>>>> developErrorAngularVelocity
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
<<<<<<< HEAD
  ssSetChecksum0(S,(3248184531U));
  ssSetChecksum1(S,(1234170867U));
  ssSetChecksum2(S,(888783763U));
  ssSetChecksum3(S,(1504973636U));
=======
  ssSetChecksum0(S,(3722036607U));
  ssSetChecksum1(S,(2027232529U));
  ssSetChecksum2(S,(2873726516U));
  ssSetChecksum3(S,(653851591U));
>>>>>>> developErrorAngularVelocity
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_QRsim(SimStruct *S)
{
  SFc5_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc5_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_QRsim;
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

void c5_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
