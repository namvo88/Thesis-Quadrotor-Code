/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c9_QRsim.h"
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
static const char * c9_debug_family_names[7] = { "a", "b", "c", "nargin",
  "nargout", "A", "fcnv" };
=======
static const char * c9_debug_family_names[13] = { "p", "q", "r", "Omegahat",
  "nargin", "nargout", "R", "Rdes", "Omega", "Omegades", "dOmegades", "Out1",
  "Out2" };
>>>>>>> developErrorAngularVelocity

/* Function Declarations */
static void initialize_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void initialize_params_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void enable_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void disable_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_QRsim(SFc9_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c9_QRsim(SFc9_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_st);
static void finalize_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void sf_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void c9_chartstep_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void initSimStructsc9_QRsim(SFc9_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c9_fcnv, const char_T *c9_identifier, real_T c9_y[3]);
=======
  mxArray *c9_Out2, const char_T *c9_identifier, real_T c9_y[3]);
>>>>>>> developErrorAngularVelocity
static void c9_b_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance, const
  mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_d_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance, const
  mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(uint32_T c9_u);
static void c9_eml_scalar_eg(SFc9_QRsimInstanceStruct *chartInstance);
static void c9_b_eml_scalar_eg(SFc9_QRsimInstanceStruct *chartInstance);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_e_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_f_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_QRsim, const char_T *c9_identifier);
static uint8_T c9_g_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_QRsim = 0U;
}

static void initialize_params_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_QRsim(SFc9_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c9_QRsim(SFc9_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[3];
  const mxArray *c9_b_y = NULL;
  int32_T c9_i1;
  real_T c9_b_u[3];
  const mxArray *c9_c_y = NULL;
<<<<<<< HEAD
  real_T (*c9_fcnv)[3];
  c9_fcnv = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  for (c9_i0 = 0; c9_i0 < 3; c9_i0++) {
    c9_u[c9_i0] = (*c9_fcnv)[c9_i0];
=======
  uint8_T c9_hoistedGlobal;
  uint8_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T (*c9_Out2)[3];
  real_T (*c9_Out1)[3];
  c9_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(3), FALSE);
  for (c9_i0 = 0; c9_i0 < 3; c9_i0++) {
    c9_u[c9_i0] = (*c9_Out1)[c9_i0];
>>>>>>> developErrorAngularVelocity
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i1 = 0; c9_i1 < 3; c9_i1++) {
    c9_b_u[c9_i1] = (*c9_Out2)[c9_i1];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_QRsim;
  c9_c_u = c9_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[3];
<<<<<<< HEAD
  int32_T c9_i1;
  real_T (*c9_fcnv)[3];
  c9_fcnv = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "fcnv",
                      c9_dv0);
  for (c9_i1 = 0; c9_i1 < 3; c9_i1++) {
    (*c9_fcnv)[c9_i1] = c9_dv0[c9_i1];
=======
  int32_T c9_i2;
  real_T c9_dv1[3];
  int32_T c9_i3;
  real_T (*c9_Out1)[3];
  real_T (*c9_Out2)[3];
  c9_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "Out1",
                      c9_dv0);
  for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
    (*c9_Out1)[c9_i2] = c9_dv0[c9_i2];
  }

  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)), "Out2",
                      c9_dv1);
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    (*c9_Out2)[c9_i3] = c9_dv1[c9_i3];
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c9_is_active_c9_QRsim = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 2)), "is_active_c9_QRsim");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_QRsim(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
  int32_T c9_i4;
<<<<<<< HEAD
  real_T c9_A[9];
  uint32_T c9_debug_family_var_map[7];
  real_T c9_a;
  real_T c9_b;
  real_T c9_c;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_fcnv[3];
  int32_T c9_i5;
  real_T (*c9_b_fcnv)[3];
  real_T (*c9_b_A)[9];
  c9_b_fcnv = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 9; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_A)[c9_i2], 0U);
  }

  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_fcnv)[c9_i3], 1U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i4 = 0; c9_i4 < 9; c9_i4++) {
    c9_A[c9_i4] = (*c9_b_A)[c9_i4];
=======
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i10;
  real_T (*c9_Out2)[3];
  real_T (*c9_dOmegades)[3];
  real_T (*c9_Omegades)[3];
  real_T (*c9_Omega)[3];
  real_T (*c9_Out1)[3];
  real_T (*c9_Rdes)[9];
  real_T (*c9_R)[9];
  c9_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_dOmegades = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c9_Omegades = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c9_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c9_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c9_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i4 = 0; c9_i4 < 9; c9_i4++) {
    _SFD_DATA_RANGE_CHECK((*c9_R)[c9_i4], 0U);
  }

  for (c9_i5 = 0; c9_i5 < 9; c9_i5++) {
    _SFD_DATA_RANGE_CHECK((*c9_Rdes)[c9_i5], 1U);
  }

  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    _SFD_DATA_RANGE_CHECK((*c9_Out1)[c9_i6], 2U);
  }

  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    _SFD_DATA_RANGE_CHECK((*c9_Omega)[c9_i7], 3U);
  }

  for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
    _SFD_DATA_RANGE_CHECK((*c9_Omegades)[c9_i8], 4U);
  }

  for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
    _SFD_DATA_RANGE_CHECK((*c9_dOmegades)[c9_i9], 5U);
  }

  for (c9_i10 = 0; c9_i10 < 3; c9_i10++) {
    _SFD_DATA_RANGE_CHECK((*c9_Out2)[c9_i10], 6U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
  int32_T c9_i11;
  real_T c9_R[9];
  int32_T c9_i12;
  real_T c9_Rdes[9];
  int32_T c9_i13;
  real_T c9_Omega[3];
  int32_T c9_i14;
  real_T c9_Omegades[3];
  int32_T c9_i15;
  real_T c9_dOmegades[3];
  uint32_T c9_debug_family_var_map[13];
  real_T c9_p;
  real_T c9_q;
  real_T c9_r;
  real_T c9_Omegahat[9];
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 2.0;
  real_T c9_Out1[3];
  real_T c9_Out2[3];
  int32_T c9_i16;
  real_T c9_a[9];
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i20;
  real_T c9_b[9];
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  real_T c9_y[9];
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  real_T c9_b_b[3];
  int32_T c9_i33;
  int32_T c9_i34;
  int32_T c9_i35;
  real_T c9_C[3];
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  int32_T c9_i41;
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  int32_T c9_i45;
  int32_T c9_i46;
  int32_T c9_i47;
  int32_T c9_i48;
  int32_T c9_i49;
  int32_T c9_i50;
  int32_T c9_i51;
  int32_T c9_i52;
  int32_T c9_i53;
  int32_T c9_i54;
  int32_T c9_i55;
  int32_T c9_i56;
  int32_T c9_i57;
  int32_T c9_i58;
  int32_T c9_i59;
  int32_T c9_i60;
  int32_T c9_i61;
  int32_T c9_i62;
  int32_T c9_i63;
  real_T (*c9_b_Out1)[3];
  real_T (*c9_b_Out2)[3];
  real_T (*c9_b_dOmegades)[3];
  real_T (*c9_b_Omegades)[3];
  real_T (*c9_b_Omega)[3];
  real_T (*c9_b_Rdes)[9];
  real_T (*c9_b_R)[9];
  c9_b_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_dOmegades = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c9_b_Omegades = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i11 = 0; c9_i11 < 9; c9_i11++) {
    c9_R[c9_i11] = (*c9_b_R)[c9_i11];
>>>>>>> developErrorAngularVelocity
  }

  for (c9_i12 = 0; c9_i12 < 9; c9_i12++) {
    c9_Rdes[c9_i12] = (*c9_b_Rdes)[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 3; c9_i13++) {
    c9_Omega[c9_i13] = (*c9_b_Omega)[c9_i13];
  }

  for (c9_i14 = 0; c9_i14 < 3; c9_i14++) {
    c9_Omegades[c9_i14] = (*c9_b_Omegades)[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    c9_dOmegades[c9_i15] = (*c9_b_dOmegades)[c9_i15];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p, 0U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q, 1U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_r, 2U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_Omegahat, 3U, c9_b_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
<<<<<<< HEAD
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_A, 5U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_fcnv, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_a = c9_A[5];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_b = -c9_A[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_c = c9_A[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_fcnv[0] = c9_a;
  c9_fcnv[1] = c9_b;
  c9_fcnv[2] = c9_c;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i5 = 0; c9_i5 < 3; c9_i5++) {
    (*c9_b_fcnv)[c9_i5] = c9_fcnv[c9_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
=======
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_R, 6U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_Rdes, 7U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_Omega, 8U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_Omegades, 9U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_dOmegades, 10U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_Out1, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_Out2, 12U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_p = c9_Omega[0];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_q = c9_Omega[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_r = c9_Omega[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_Omegahat[0] = 0.0;
  c9_Omegahat[3] = -c9_r;
  c9_Omegahat[6] = c9_q;
  c9_Omegahat[1] = c9_r;
  c9_Omegahat[4] = 0.0;
  c9_Omegahat[7] = -c9_p;
  c9_Omegahat[2] = -c9_q;
  c9_Omegahat[5] = c9_p;
  c9_Omegahat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  for (c9_i16 = 0; c9_i16 < 9; c9_i16++) {
    c9_a[c9_i16] = c9_Omegahat[c9_i16];
  }

  c9_i17 = 0;
  for (c9_i18 = 0; c9_i18 < 3; c9_i18++) {
    c9_i19 = 0;
    for (c9_i20 = 0; c9_i20 < 3; c9_i20++) {
      c9_b[c9_i20 + c9_i17] = c9_R[c9_i19 + c9_i18];
      c9_i19 += 3;
    }

    c9_i17 += 3;
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i21 = 0; c9_i21 < 3; c9_i21++) {
    c9_i22 = 0;
    for (c9_i23 = 0; c9_i23 < 3; c9_i23++) {
      c9_y[c9_i22 + c9_i21] = 0.0;
      c9_i24 = 0;
      for (c9_i25 = 0; c9_i25 < 3; c9_i25++) {
        c9_y[c9_i22 + c9_i21] += c9_a[c9_i24 + c9_i21] * c9_b[c9_i25 + c9_i22];
        c9_i24 += 3;
      }

      c9_i22 += 3;
    }
  }

  for (c9_i26 = 0; c9_i26 < 9; c9_i26++) {
    c9_b[c9_i26] = c9_Rdes[c9_i26];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i27 = 0; c9_i27 < 3; c9_i27++) {
    c9_i28 = 0;
    for (c9_i29 = 0; c9_i29 < 3; c9_i29++) {
      c9_a[c9_i28 + c9_i27] = 0.0;
      c9_i30 = 0;
      for (c9_i31 = 0; c9_i31 < 3; c9_i31++) {
        c9_a[c9_i28 + c9_i27] += c9_y[c9_i30 + c9_i27] * c9_b[c9_i31 + c9_i28];
        c9_i30 += 3;
      }

      c9_i28 += 3;
    }
  }

  for (c9_i32 = 0; c9_i32 < 3; c9_i32++) {
    c9_b_b[c9_i32] = c9_Omegades[c9_i32];
  }

  c9_b_eml_scalar_eg(chartInstance);
  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i33 = 0; c9_i33 < 3; c9_i33++) {
    c9_Out1[c9_i33] = 0.0;
  }

  for (c9_i34 = 0; c9_i34 < 3; c9_i34++) {
    c9_Out1[c9_i34] = 0.0;
  }

  for (c9_i35 = 0; c9_i35 < 3; c9_i35++) {
    c9_C[c9_i35] = c9_Out1[c9_i35];
  }

  for (c9_i36 = 0; c9_i36 < 3; c9_i36++) {
    c9_Out1[c9_i36] = c9_C[c9_i36];
  }

  for (c9_i37 = 0; c9_i37 < 3; c9_i37++) {
    c9_C[c9_i37] = c9_Out1[c9_i37];
  }

  for (c9_i38 = 0; c9_i38 < 3; c9_i38++) {
    c9_Out1[c9_i38] = c9_C[c9_i38];
  }

  for (c9_i39 = 0; c9_i39 < 3; c9_i39++) {
    c9_Out1[c9_i39] = 0.0;
    c9_i40 = 0;
    for (c9_i41 = 0; c9_i41 < 3; c9_i41++) {
      c9_Out1[c9_i39] += c9_a[c9_i40 + c9_i39] * c9_b_b[c9_i41];
      c9_i40 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
  c9_i42 = 0;
  for (c9_i43 = 0; c9_i43 < 3; c9_i43++) {
    c9_i44 = 0;
    for (c9_i45 = 0; c9_i45 < 3; c9_i45++) {
      c9_a[c9_i45 + c9_i42] = c9_R[c9_i44 + c9_i43];
      c9_i44 += 3;
    }

    c9_i42 += 3;
  }

  for (c9_i46 = 0; c9_i46 < 9; c9_i46++) {
    c9_b[c9_i46] = c9_Rdes[c9_i46];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i47 = 0; c9_i47 < 3; c9_i47++) {
    c9_i48 = 0;
    for (c9_i49 = 0; c9_i49 < 3; c9_i49++) {
      c9_y[c9_i48 + c9_i47] = 0.0;
      c9_i50 = 0;
      for (c9_i51 = 0; c9_i51 < 3; c9_i51++) {
        c9_y[c9_i48 + c9_i47] += c9_a[c9_i50 + c9_i47] * c9_b[c9_i51 + c9_i48];
        c9_i50 += 3;
      }

      c9_i48 += 3;
    }
  }

  for (c9_i52 = 0; c9_i52 < 3; c9_i52++) {
    c9_b_b[c9_i52] = c9_dOmegades[c9_i52];
  }

  c9_b_eml_scalar_eg(chartInstance);
  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i53 = 0; c9_i53 < 3; c9_i53++) {
    c9_Out2[c9_i53] = 0.0;
  }

  for (c9_i54 = 0; c9_i54 < 3; c9_i54++) {
    c9_Out2[c9_i54] = 0.0;
  }

  for (c9_i55 = 0; c9_i55 < 3; c9_i55++) {
    c9_C[c9_i55] = c9_Out2[c9_i55];
  }

  for (c9_i56 = 0; c9_i56 < 3; c9_i56++) {
    c9_Out2[c9_i56] = c9_C[c9_i56];
  }

  for (c9_i57 = 0; c9_i57 < 3; c9_i57++) {
    c9_C[c9_i57] = c9_Out2[c9_i57];
  }

  for (c9_i58 = 0; c9_i58 < 3; c9_i58++) {
    c9_Out2[c9_i58] = c9_C[c9_i58];
  }

  for (c9_i59 = 0; c9_i59 < 3; c9_i59++) {
    c9_Out2[c9_i59] = 0.0;
    c9_i60 = 0;
    for (c9_i61 = 0; c9_i61 < 3; c9_i61++) {
      c9_Out2[c9_i59] += c9_y[c9_i60 + c9_i59] * c9_b_b[c9_i61];
      c9_i60 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -13);
>>>>>>> developErrorAngularVelocity
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i62 = 0; c9_i62 < 3; c9_i62++) {
    (*c9_b_Out1)[c9_i62] = c9_Out1[c9_i62];
  }

  for (c9_i63 = 0; c9_i63 < 3; c9_i63++) {
    (*c9_b_Out2)[c9_i63] = c9_Out2[c9_i63];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_QRsim(SFc9_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c9_i6;
  real_T c9_b_inData[3];
  int32_T c9_i7;
=======
  int32_T c9_i64;
  real_T c9_b_inData[3];
  int32_T c9_i65;
>>>>>>> developErrorAngularVelocity
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
<<<<<<< HEAD
  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    c9_b_inData[c9_i6] = (*(real_T (*)[3])c9_inData)[c9_i6];
  }

  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    c9_u[c9_i7] = c9_b_inData[c9_i7];
=======
  for (c9_i64 = 0; c9_i64 < 3; c9_i64++) {
    c9_b_inData[c9_i64] = (*(real_T (*)[3])c9_inData)[c9_i64];
  }

  for (c9_i65 = 0; c9_i65 < 3; c9_i65++) {
    c9_u[c9_i65] = c9_b_inData[c9_i65];
>>>>>>> developErrorAngularVelocity
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c9_fcnv, const char_T *c9_identifier, real_T c9_y[3])
=======
  mxArray *c9_Out2, const char_T *c9_identifier, real_T c9_y[3])
>>>>>>> developErrorAngularVelocity
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
<<<<<<< HEAD
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_fcnv), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_fcnv);
=======
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Out2), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Out2);
>>>>>>> developErrorAngularVelocity
}

static void c9_b_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance, const
  mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3])
{
<<<<<<< HEAD
  real_T c9_dv1[3];
  int32_T c9_i8;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
    c9_y[c9_i8] = c9_dv1[c9_i8];
=======
  real_T c9_dv2[3];
  int32_T c9_i66;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c9_i66 = 0; c9_i66 < 3; c9_i66++) {
    c9_y[c9_i66] = c9_dv2[c9_i66];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
<<<<<<< HEAD
  const mxArray *c9_fcnv;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i9;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_fcnv = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_fcnv), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_fcnv);
  for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
    (*(real_T (*)[3])c9_outData)[c9_i9] = c9_y[c9_i9];
=======
  const mxArray *c9_Out2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i67;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_Out2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Out2), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Out2);
  for (c9_i67 = 0; c9_i67 < 3; c9_i67++) {
    (*(real_T (*)[3])c9_outData)[c9_i67] = c9_y[c9_i67];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
<<<<<<< HEAD
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  real_T c9_b_inData[9];
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
=======
  int32_T c9_i68;
  int32_T c9_i69;
  int32_T c9_i70;
  real_T c9_b_inData[9];
  int32_T c9_i71;
  int32_T c9_i72;
  int32_T c9_i73;
>>>>>>> developErrorAngularVelocity
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
<<<<<<< HEAD
  c9_i10 = 0;
  for (c9_i11 = 0; c9_i11 < 3; c9_i11++) {
    for (c9_i12 = 0; c9_i12 < 3; c9_i12++) {
      c9_b_inData[c9_i12 + c9_i10] = (*(real_T (*)[9])c9_inData)[c9_i12 + c9_i10];
    }

    c9_i10 += 3;
  }

  c9_i13 = 0;
  for (c9_i14 = 0; c9_i14 < 3; c9_i14++) {
    for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
      c9_u[c9_i15 + c9_i13] = c9_b_inData[c9_i15 + c9_i13];
    }

    c9_i13 += 3;
=======
  c9_i68 = 0;
  for (c9_i69 = 0; c9_i69 < 3; c9_i69++) {
    for (c9_i70 = 0; c9_i70 < 3; c9_i70++) {
      c9_b_inData[c9_i70 + c9_i68] = (*(real_T (*)[9])c9_inData)[c9_i70 + c9_i68];
    }

    c9_i68 += 3;
  }

  c9_i71 = 0;
  for (c9_i72 = 0; c9_i72 < 3; c9_i72++) {
    for (c9_i73 = 0; c9_i73 < 3; c9_i73++) {
      c9_u[c9_i73 + c9_i71] = c9_b_inData[c9_i73 + c9_i71];
    }

    c9_i71 += 3;
>>>>>>> developErrorAngularVelocity
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_d_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance, const
  mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9])
{
  real_T c9_dv3[9];
  int32_T c9_i74;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i74 = 0; c9_i74 < 9; c9_i74++) {
    c9_y[c9_i74] = c9_dv3[c9_i74];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_Omegahat;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i75;
  int32_T c9_i76;
  int32_T c9_i77;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_Omegahat = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Omegahat), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Omegahat);
  c9_i75 = 0;
  for (c9_i76 = 0; c9_i76 < 3; c9_i76++) {
    for (c9_i77 = 0; c9_i77 < 3; c9_i77++) {
      (*(real_T (*)[9])c9_outData)[c9_i77 + c9_i75] = c9_y[c9_i77 + c9_i75];
    }

    c9_i75 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  const mxArray *c9_rhs4 = NULL;
  const mxArray *c9_lhs4 = NULL;
  const mxArray *c9_rhs5 = NULL;
  const mxArray *c9_lhs5 = NULL;
  const mxArray *c9_rhs6 = NULL;
  const mxArray *c9_lhs6 = NULL;
  const mxArray *c9_rhs7 = NULL;
  const mxArray *c9_lhs7 = NULL;
  const mxArray *c9_rhs8 = NULL;
  const mxArray *c9_lhs8 = NULL;
  const mxArray *c9_rhs9 = NULL;
  const mxArray *c9_lhs9 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_xgemm"), "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c9_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c9_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c9_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c9_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c9_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c9_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs9), "lhs", "lhs", 9);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
  sf_mex_destroy(&c9_rhs4);
  sf_mex_destroy(&c9_lhs4);
  sf_mex_destroy(&c9_rhs5);
  sf_mex_destroy(&c9_lhs5);
  sf_mex_destroy(&c9_rhs6);
  sf_mex_destroy(&c9_lhs6);
  sf_mex_destroy(&c9_rhs7);
  sf_mex_destroy(&c9_lhs7);
  sf_mex_destroy(&c9_rhs8);
  sf_mex_destroy(&c9_lhs8);
  sf_mex_destroy(&c9_rhs9);
  sf_mex_destroy(&c9_lhs9);
}

static const mxArray *c9_emlrt_marshallOut(char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), FALSE);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c9_y;
}

static void c9_eml_scalar_eg(SFc9_QRsimInstanceStruct *chartInstance)
{
}

static void c9_b_eml_scalar_eg(SFc9_QRsimInstanceStruct *chartInstance)
{
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_e_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
<<<<<<< HEAD
  int32_T c9_i16;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i16, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i16;
=======
  int32_T c9_i78;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i78, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i78;
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_QRsim, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_is_active_c9_QRsim),
    &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_QRsim);
  return c9_y;
}

static uint8_T c9_g_emlrt_marshallIn(SFc9_QRsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_QRsimInstanceStruct *chartInstance)
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

void sf_c9_QRsim_get_check_sum(mxArray *plhs[])
{
<<<<<<< HEAD
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1691970018U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2281216908U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3957080737U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3964174320U);
=======
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3604578503U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(55544399U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1996449542U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1434032913U);
>>>>>>> developErrorAngularVelocity
}

mxArray *sf_c9_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("Yb2340o0Th03RdfNNWKBoE");
=======
    mxArray *mxChecksum = mxCreateString("unB6Ok083ujEdpPh5Oox9D");
>>>>>>> developErrorAngularVelocity
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
<<<<<<< HEAD
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fcnv\",},{M[8],M[0],T\"is_active_c9_QRsim\",}}"
=======
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"Out1\",},{M[1],M[13],T\"Out2\",},{M[8],M[0],T\"is_active_c9_QRsim\",}}"
>>>>>>> developErrorAngularVelocity
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc9_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           9,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,2,0,1,"fcnv");
=======
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rdes");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Out1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Omega");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Omegades");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dOmegades");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Out2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,105);
=======
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,253);
>>>>>>> developErrorAngularVelocity

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
<<<<<<< HEAD
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
=======
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
>>>>>>> developErrorAngularVelocity
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
<<<<<<< HEAD
          real_T (*c9_A)[9];
          real_T (*c9_fcnv)[3];
          c9_fcnv = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c9_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_fcnv);
=======
          real_T (*c9_R)[9];
          real_T (*c9_Rdes)[9];
          real_T (*c9_Out1)[3];
          real_T (*c9_Omega)[3];
          real_T (*c9_Omegades)[3];
          real_T (*c9_dOmegades)[3];
          real_T (*c9_Out2)[3];
          c9_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c9_dOmegades = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c9_Omegades = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c9_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c9_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c9_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c9_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_Rdes);
          _SFD_SET_DATA_VALUE_PTR(2U, *c9_Out1);
          _SFD_SET_DATA_VALUE_PTR(3U, *c9_Omega);
          _SFD_SET_DATA_VALUE_PTR(4U, *c9_Omegades);
          _SFD_SET_DATA_VALUE_PTR(5U, *c9_dOmegades);
          _SFD_SET_DATA_VALUE_PTR(6U, *c9_Out2);
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
  return "Eepk4XO5TUYL950TJLhgBD";
=======
  return "8e3DSPRioc2UAafNk6DuzB";
>>>>>>> developErrorAngularVelocity
}

static void sf_opaque_initialize_c9_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_QRsimInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_QRsim(void *chartInstanceVar)
{
  enable_c9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_QRsim(void *chartInstanceVar)
{
  disable_c9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_QRsim(void *chartInstanceVar)
{
  sf_c9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_QRsim((SFc9_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c9_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_QRsim((SFc9_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_QRsim(S);
}

static void sf_opaque_set_sim_state_c9_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c9_QRsim(S, st);
}

static void sf_opaque_terminate_c9_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_QRsim((SFc9_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_QRsim((SFc9_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
<<<<<<< HEAD
  ssSetChecksum0(S,(2255102069U));
  ssSetChecksum1(S,(1137809757U));
  ssSetChecksum2(S,(1266076923U));
  ssSetChecksum3(S,(898103752U));
=======
  ssSetChecksum0(S,(820560314U));
  ssSetChecksum1(S,(217557646U));
  ssSetChecksum2(S,(3091722894U));
  ssSetChecksum3(S,(4112897986U));
>>>>>>> developErrorAngularVelocity
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_QRsim(SimStruct *S)
{
  SFc9_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc9_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c9_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c9_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_QRsim;
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

void c9_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
