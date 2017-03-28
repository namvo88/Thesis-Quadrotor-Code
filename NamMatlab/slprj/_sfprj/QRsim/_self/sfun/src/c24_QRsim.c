/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c24_QRsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c24_debug_family_names[14] = { "p", "q", "r", "Omegahat",
  "nargin", "nargout", "R", "Rc", "Omega", "Omegac", "dOmegac", "Out1", "Out2",
  "Out3" };

/* Function Declarations */
static void initialize_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void initialize_params_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void enable_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void disable_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_QRsim(SFc24_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c24_QRsim(SFc24_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_st);
static void finalize_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void sf_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void c24_chartstep_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void initSimStructsc24_QRsim(SFc24_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance, const
  mxArray *c24_Out3, const char_T *c24_identifier, real_T c24_y[9]);
static void c24_b_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[9]);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_c_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_Out2, const char_T *c24_identifier, real_T c24_y[3]);
static void c24_d_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[3]);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_e_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_info_helper(const mxArray **c24_info);
static const mxArray *c24_emlrt_marshallOut(char * c24_u);
static const mxArray *c24_b_emlrt_marshallOut(uint32_T c24_u);
static void c24_eml_scalar_eg(SFc24_QRsimInstanceStruct *chartInstance);
static void c24_b_eml_scalar_eg(SFc24_QRsimInstanceStruct *chartInstance);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_f_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_g_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_b_is_active_c24_QRsim, const char_T *c24_identifier);
static uint8_T c24_h_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c24_is_active_c24_QRsim = 0U;
}

static void initialize_params_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c24_update_debugger_state_c24_QRsim(SFc24_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c24_QRsim(SFc24_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  int32_T c24_i0;
  real_T c24_u[3];
  const mxArray *c24_b_y = NULL;
  int32_T c24_i1;
  real_T c24_b_u[3];
  const mxArray *c24_c_y = NULL;
  int32_T c24_i2;
  real_T c24_c_u[9];
  const mxArray *c24_d_y = NULL;
  uint8_T c24_hoistedGlobal;
  uint8_T c24_d_u;
  const mxArray *c24_e_y = NULL;
  real_T (*c24_Out3)[9];
  real_T (*c24_Out2)[3];
  real_T (*c24_Out1)[3];
  c24_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c24_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c24_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellarray(4), FALSE);
  for (c24_i0 = 0; c24_i0 < 3; c24_i0++) {
    c24_u[c24_i0] = (*c24_Out1)[c24_i0];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  for (c24_i1 = 0; c24_i1 < 3; c24_i1++) {
    c24_b_u[c24_i1] = (*c24_Out2)[c24_i1];
  }

  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", c24_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  for (c24_i2 = 0; c24_i2 < 9; c24_i2++) {
    c24_c_u[c24_i2] = (*c24_Out3)[c24_i2];
  }

  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", c24_c_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c24_y, 2, c24_d_y);
  c24_hoistedGlobal = chartInstance->c24_is_active_c24_QRsim;
  c24_d_u = c24_hoistedGlobal;
  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", &c24_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 3, c24_e_y);
  sf_mex_assign(&c24_st, c24_y, FALSE);
  return c24_st;
}

static void set_sim_state_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_st)
{
  const mxArray *c24_u;
  real_T c24_dv0[3];
  int32_T c24_i3;
  real_T c24_dv1[3];
  int32_T c24_i4;
  real_T c24_dv2[9];
  int32_T c24_i5;
  real_T (*c24_Out1)[3];
  real_T (*c24_Out2)[3];
  real_T (*c24_Out3)[9];
  c24_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c24_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c24_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c24_doneDoubleBufferReInit = TRUE;
  c24_u = sf_mex_dup(c24_st);
  c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 0)),
    "Out1", c24_dv0);
  for (c24_i3 = 0; c24_i3 < 3; c24_i3++) {
    (*c24_Out1)[c24_i3] = c24_dv0[c24_i3];
  }

  c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 1)),
    "Out2", c24_dv1);
  for (c24_i4 = 0; c24_i4 < 3; c24_i4++) {
    (*c24_Out2)[c24_i4] = c24_dv1[c24_i4];
  }

  c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 2)),
                       "Out3", c24_dv2);
  for (c24_i5 = 0; c24_i5 < 9; c24_i5++) {
    (*c24_Out3)[c24_i5] = c24_dv2[c24_i5];
  }

  chartInstance->c24_is_active_c24_QRsim = c24_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c24_u, 3)), "is_active_c24_QRsim");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_QRsim(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
  int32_T c24_i6;
  int32_T c24_i7;
  int32_T c24_i8;
  int32_T c24_i9;
  int32_T c24_i10;
  int32_T c24_i11;
  int32_T c24_i12;
  int32_T c24_i13;
  real_T (*c24_Out3)[9];
  real_T (*c24_Out2)[3];
  real_T (*c24_dOmegac)[3];
  real_T (*c24_Omegac)[3];
  real_T (*c24_Omega)[3];
  real_T (*c24_Out1)[3];
  real_T (*c24_Rc)[9];
  real_T (*c24_R)[9];
  c24_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c24_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c24_dOmegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c24_Omegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c24_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c24_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c24_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c24_sfEvent);
  for (c24_i6 = 0; c24_i6 < 9; c24_i6++) {
    _SFD_DATA_RANGE_CHECK((*c24_R)[c24_i6], 0U);
  }

  for (c24_i7 = 0; c24_i7 < 9; c24_i7++) {
    _SFD_DATA_RANGE_CHECK((*c24_Rc)[c24_i7], 1U);
  }

  for (c24_i8 = 0; c24_i8 < 3; c24_i8++) {
    _SFD_DATA_RANGE_CHECK((*c24_Out1)[c24_i8], 2U);
  }

  for (c24_i9 = 0; c24_i9 < 3; c24_i9++) {
    _SFD_DATA_RANGE_CHECK((*c24_Omega)[c24_i9], 3U);
  }

  for (c24_i10 = 0; c24_i10 < 3; c24_i10++) {
    _SFD_DATA_RANGE_CHECK((*c24_Omegac)[c24_i10], 4U);
  }

  for (c24_i11 = 0; c24_i11 < 3; c24_i11++) {
    _SFD_DATA_RANGE_CHECK((*c24_dOmegac)[c24_i11], 5U);
  }

  for (c24_i12 = 0; c24_i12 < 3; c24_i12++) {
    _SFD_DATA_RANGE_CHECK((*c24_Out2)[c24_i12], 6U);
  }

  for (c24_i13 = 0; c24_i13 < 9; c24_i13++) {
    _SFD_DATA_RANGE_CHECK((*c24_Out3)[c24_i13], 7U);
  }

  chartInstance->c24_sfEvent = CALL_EVENT;
  c24_chartstep_c24_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c24_chartstep_c24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
  int32_T c24_i14;
  real_T c24_R[9];
  int32_T c24_i15;
  real_T c24_Rc[9];
  int32_T c24_i16;
  real_T c24_Omega[3];
  int32_T c24_i17;
  real_T c24_Omegac[3];
  int32_T c24_i18;
  real_T c24_dOmegac[3];
  uint32_T c24_debug_family_var_map[14];
  real_T c24_p;
  real_T c24_q;
  real_T c24_r;
  real_T c24_Omegahat[9];
  real_T c24_nargin = 5.0;
  real_T c24_nargout = 3.0;
  real_T c24_Out1[3];
  real_T c24_Out2[3];
  real_T c24_Out3[9];
  int32_T c24_i19;
  real_T c24_a[9];
  int32_T c24_i20;
  int32_T c24_i21;
  int32_T c24_i22;
  int32_T c24_i23;
  real_T c24_b[9];
  int32_T c24_i24;
  int32_T c24_i25;
  int32_T c24_i26;
  real_T c24_y[9];
  int32_T c24_i27;
  int32_T c24_i28;
  int32_T c24_i29;
  int32_T c24_i30;
  int32_T c24_i31;
  int32_T c24_i32;
  real_T c24_b_y[9];
  int32_T c24_i33;
  int32_T c24_i34;
  int32_T c24_i35;
  real_T c24_b_b[3];
  int32_T c24_i36;
  int32_T c24_i37;
  int32_T c24_i38;
  real_T c24_C[3];
  int32_T c24_i39;
  int32_T c24_i40;
  int32_T c24_i41;
  int32_T c24_i42;
  int32_T c24_i43;
  int32_T c24_i44;
  int32_T c24_i45;
  int32_T c24_i46;
  int32_T c24_i47;
  int32_T c24_i48;
  int32_T c24_i49;
  int32_T c24_i50;
  int32_T c24_i51;
  int32_T c24_i52;
  int32_T c24_i53;
  int32_T c24_i54;
  int32_T c24_i55;
  int32_T c24_i56;
  int32_T c24_i57;
  int32_T c24_i58;
  int32_T c24_i59;
  int32_T c24_i60;
  int32_T c24_i61;
  int32_T c24_i62;
  int32_T c24_i63;
  int32_T c24_i64;
  int32_T c24_i65;
  int32_T c24_i66;
  int32_T c24_i67;
  int32_T c24_i68;
  int32_T c24_i69;
  int32_T c24_i70;
  int32_T c24_i71;
  int32_T c24_i72;
  int32_T c24_i73;
  int32_T c24_i74;
  int32_T c24_i75;
  int32_T c24_i76;
  int32_T c24_i77;
  int32_T c24_i78;
  int32_T c24_i79;
  int32_T c24_i80;
  int32_T c24_i81;
  int32_T c24_i82;
  int32_T c24_i83;
  real_T (*c24_b_Out1)[3];
  real_T (*c24_b_Out2)[3];
  real_T (*c24_b_Out3)[9];
  real_T (*c24_b_dOmegac)[3];
  real_T (*c24_b_Omegac)[3];
  real_T (*c24_b_Omega)[3];
  real_T (*c24_b_Rc)[9];
  real_T (*c24_b_R)[9];
  c24_b_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c24_b_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c24_b_dOmegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c24_b_Omegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c24_b_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c24_b_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c24_sfEvent);
  for (c24_i14 = 0; c24_i14 < 9; c24_i14++) {
    c24_R[c24_i14] = (*c24_b_R)[c24_i14];
  }

  for (c24_i15 = 0; c24_i15 < 9; c24_i15++) {
    c24_Rc[c24_i15] = (*c24_b_Rc)[c24_i15];
  }

  for (c24_i16 = 0; c24_i16 < 3; c24_i16++) {
    c24_Omega[c24_i16] = (*c24_b_Omega)[c24_i16];
  }

  for (c24_i17 = 0; c24_i17 < 3; c24_i17++) {
    c24_Omegac[c24_i17] = (*c24_b_Omegac)[c24_i17];
  }

  for (c24_i18 = 0; c24_i18 < 3; c24_i18++) {
    c24_dOmegac[c24_i18] = (*c24_b_dOmegac)[c24_i18];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c24_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_p, 0U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_q, 1U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_r, 2U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_Omegahat, 3U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 4U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 5U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_R, 6U, c24_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_Rc, 7U, c24_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_Omega, 8U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_Omegac, 9U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_dOmegac, 10U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_Out1, 11U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_Out2, 12U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_Out3, 13U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 4);
  c24_p = c24_Omega[0];
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 5);
  c24_q = c24_Omega[1];
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 6);
  c24_r = c24_Omega[2];
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 8);
  c24_Omegahat[0] = 0.0;
  c24_Omegahat[3] = -c24_r;
  c24_Omegahat[6] = c24_q;
  c24_Omegahat[1] = c24_r;
  c24_Omegahat[4] = 0.0;
  c24_Omegahat[7] = -c24_p;
  c24_Omegahat[2] = -c24_q;
  c24_Omegahat[5] = c24_p;
  c24_Omegahat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 12);
  for (c24_i19 = 0; c24_i19 < 9; c24_i19++) {
    c24_a[c24_i19] = c24_Omegahat[c24_i19];
  }

  c24_i20 = 0;
  for (c24_i21 = 0; c24_i21 < 3; c24_i21++) {
    c24_i22 = 0;
    for (c24_i23 = 0; c24_i23 < 3; c24_i23++) {
      c24_b[c24_i23 + c24_i20] = c24_R[c24_i22 + c24_i21];
      c24_i22 += 3;
    }

    c24_i20 += 3;
  }

  c24_eml_scalar_eg(chartInstance);
  c24_eml_scalar_eg(chartInstance);
  for (c24_i24 = 0; c24_i24 < 3; c24_i24++) {
    c24_i25 = 0;
    for (c24_i26 = 0; c24_i26 < 3; c24_i26++) {
      c24_y[c24_i25 + c24_i24] = 0.0;
      c24_i27 = 0;
      for (c24_i28 = 0; c24_i28 < 3; c24_i28++) {
        c24_y[c24_i25 + c24_i24] += c24_a[c24_i27 + c24_i24] * c24_b[c24_i28 +
          c24_i25];
        c24_i27 += 3;
      }

      c24_i25 += 3;
    }
  }

  for (c24_i29 = 0; c24_i29 < 9; c24_i29++) {
    c24_b[c24_i29] = c24_Rc[c24_i29];
  }

  c24_eml_scalar_eg(chartInstance);
  c24_eml_scalar_eg(chartInstance);
  for (c24_i30 = 0; c24_i30 < 3; c24_i30++) {
    c24_i31 = 0;
    for (c24_i32 = 0; c24_i32 < 3; c24_i32++) {
      c24_b_y[c24_i31 + c24_i30] = 0.0;
      c24_i33 = 0;
      for (c24_i34 = 0; c24_i34 < 3; c24_i34++) {
        c24_b_y[c24_i31 + c24_i30] += c24_y[c24_i33 + c24_i30] * c24_b[c24_i34 +
          c24_i31];
        c24_i33 += 3;
      }

      c24_i31 += 3;
    }
  }

  for (c24_i35 = 0; c24_i35 < 3; c24_i35++) {
    c24_b_b[c24_i35] = c24_Omegac[c24_i35];
  }

  c24_b_eml_scalar_eg(chartInstance);
  c24_b_eml_scalar_eg(chartInstance);
  for (c24_i36 = 0; c24_i36 < 3; c24_i36++) {
    c24_Out1[c24_i36] = 0.0;
  }

  for (c24_i37 = 0; c24_i37 < 3; c24_i37++) {
    c24_Out1[c24_i37] = 0.0;
  }

  for (c24_i38 = 0; c24_i38 < 3; c24_i38++) {
    c24_C[c24_i38] = c24_Out1[c24_i38];
  }

  for (c24_i39 = 0; c24_i39 < 3; c24_i39++) {
    c24_Out1[c24_i39] = c24_C[c24_i39];
  }

  for (c24_i40 = 0; c24_i40 < 3; c24_i40++) {
    c24_C[c24_i40] = c24_Out1[c24_i40];
  }

  for (c24_i41 = 0; c24_i41 < 3; c24_i41++) {
    c24_Out1[c24_i41] = c24_C[c24_i41];
  }

  for (c24_i42 = 0; c24_i42 < 3; c24_i42++) {
    c24_Out1[c24_i42] = 0.0;
    c24_i43 = 0;
    for (c24_i44 = 0; c24_i44 < 3; c24_i44++) {
      c24_Out1[c24_i42] += c24_b_y[c24_i43 + c24_i42] * c24_b_b[c24_i44];
      c24_i43 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 13);
  c24_i45 = 0;
  for (c24_i46 = 0; c24_i46 < 3; c24_i46++) {
    c24_i47 = 0;
    for (c24_i48 = 0; c24_i48 < 3; c24_i48++) {
      c24_a[c24_i48 + c24_i45] = c24_R[c24_i47 + c24_i46];
      c24_i47 += 3;
    }

    c24_i45 += 3;
  }

  for (c24_i49 = 0; c24_i49 < 9; c24_i49++) {
    c24_b[c24_i49] = c24_Rc[c24_i49];
  }

  c24_eml_scalar_eg(chartInstance);
  c24_eml_scalar_eg(chartInstance);
  for (c24_i50 = 0; c24_i50 < 3; c24_i50++) {
    c24_i51 = 0;
    for (c24_i52 = 0; c24_i52 < 3; c24_i52++) {
      c24_y[c24_i51 + c24_i50] = 0.0;
      c24_i53 = 0;
      for (c24_i54 = 0; c24_i54 < 3; c24_i54++) {
        c24_y[c24_i51 + c24_i50] += c24_a[c24_i53 + c24_i50] * c24_b[c24_i54 +
          c24_i51];
        c24_i53 += 3;
      }

      c24_i51 += 3;
    }
  }

  for (c24_i55 = 0; c24_i55 < 3; c24_i55++) {
    c24_b_b[c24_i55] = c24_dOmegac[c24_i55];
  }

  c24_b_eml_scalar_eg(chartInstance);
  c24_b_eml_scalar_eg(chartInstance);
  for (c24_i56 = 0; c24_i56 < 3; c24_i56++) {
    c24_Out2[c24_i56] = 0.0;
  }

  for (c24_i57 = 0; c24_i57 < 3; c24_i57++) {
    c24_Out2[c24_i57] = 0.0;
  }

  for (c24_i58 = 0; c24_i58 < 3; c24_i58++) {
    c24_C[c24_i58] = c24_Out2[c24_i58];
  }

  for (c24_i59 = 0; c24_i59 < 3; c24_i59++) {
    c24_Out2[c24_i59] = c24_C[c24_i59];
  }

  for (c24_i60 = 0; c24_i60 < 3; c24_i60++) {
    c24_C[c24_i60] = c24_Out2[c24_i60];
  }

  for (c24_i61 = 0; c24_i61 < 3; c24_i61++) {
    c24_Out2[c24_i61] = c24_C[c24_i61];
  }

  for (c24_i62 = 0; c24_i62 < 3; c24_i62++) {
    c24_Out2[c24_i62] = 0.0;
    c24_i63 = 0;
    for (c24_i64 = 0; c24_i64 < 3; c24_i64++) {
      c24_Out2[c24_i62] += c24_y[c24_i63 + c24_i62] * c24_b_b[c24_i64];
      c24_i63 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 14);
  c24_i65 = 0;
  for (c24_i66 = 0; c24_i66 < 3; c24_i66++) {
    c24_i67 = 0;
    for (c24_i68 = 0; c24_i68 < 3; c24_i68++) {
      c24_a[c24_i68 + c24_i65] = c24_R[c24_i67 + c24_i66];
      c24_i67 += 3;
    }

    c24_i65 += 3;
  }

  for (c24_i69 = 0; c24_i69 < 9; c24_i69++) {
    c24_b[c24_i69] = c24_Rc[c24_i69];
  }

  c24_eml_scalar_eg(chartInstance);
  c24_eml_scalar_eg(chartInstance);
  for (c24_i70 = 0; c24_i70 < 9; c24_i70++) {
    c24_Out3[c24_i70] = 0.0;
  }

  for (c24_i71 = 0; c24_i71 < 9; c24_i71++) {
    c24_Out3[c24_i71] = 0.0;
  }

  for (c24_i72 = 0; c24_i72 < 9; c24_i72++) {
    c24_b_y[c24_i72] = c24_Out3[c24_i72];
  }

  for (c24_i73 = 0; c24_i73 < 9; c24_i73++) {
    c24_Out3[c24_i73] = c24_b_y[c24_i73];
  }

  for (c24_i74 = 0; c24_i74 < 9; c24_i74++) {
    c24_b_y[c24_i74] = c24_Out3[c24_i74];
  }

  for (c24_i75 = 0; c24_i75 < 9; c24_i75++) {
    c24_Out3[c24_i75] = c24_b_y[c24_i75];
  }

  for (c24_i76 = 0; c24_i76 < 3; c24_i76++) {
    c24_i77 = 0;
    for (c24_i78 = 0; c24_i78 < 3; c24_i78++) {
      c24_Out3[c24_i77 + c24_i76] = 0.0;
      c24_i79 = 0;
      for (c24_i80 = 0; c24_i80 < 3; c24_i80++) {
        c24_Out3[c24_i77 + c24_i76] += c24_a[c24_i79 + c24_i76] * c24_b[c24_i80
          + c24_i77];
        c24_i79 += 3;
      }

      c24_i77 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c24_i81 = 0; c24_i81 < 3; c24_i81++) {
    (*c24_b_Out1)[c24_i81] = c24_Out1[c24_i81];
  }

  for (c24_i82 = 0; c24_i82 < 3; c24_i82++) {
    (*c24_b_Out2)[c24_i82] = c24_Out2[c24_i82];
  }

  for (c24_i83 = 0; c24_i83 < 9; c24_i83++) {
    (*c24_b_Out3)[c24_i83] = c24_Out3[c24_i83];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c24_sfEvent);
}

static void initSimStructsc24_QRsim(SFc24_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber)
{
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i84;
  int32_T c24_i85;
  int32_T c24_i86;
  real_T c24_b_inData[9];
  int32_T c24_i87;
  int32_T c24_i88;
  int32_T c24_i89;
  real_T c24_u[9];
  const mxArray *c24_y = NULL;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i84 = 0;
  for (c24_i85 = 0; c24_i85 < 3; c24_i85++) {
    for (c24_i86 = 0; c24_i86 < 3; c24_i86++) {
      c24_b_inData[c24_i86 + c24_i84] = (*(real_T (*)[9])c24_inData)[c24_i86 +
        c24_i84];
    }

    c24_i84 += 3;
  }

  c24_i87 = 0;
  for (c24_i88 = 0; c24_i88 < 3; c24_i88++) {
    for (c24_i89 = 0; c24_i89 < 3; c24_i89++) {
      c24_u[c24_i89 + c24_i87] = c24_b_inData[c24_i89 + c24_i87];
    }

    c24_i87 += 3;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static void c24_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance, const
  mxArray *c24_Out3, const char_T *c24_identifier, real_T c24_y[9])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Out3), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_Out3);
}

static void c24_b_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[9])
{
  real_T c24_dv3[9];
  int32_T c24_i90;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c24_i90 = 0; c24_i90 < 9; c24_i90++) {
    c24_y[c24_i90] = c24_dv3[c24_i90];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_Out3;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[9];
  int32_T c24_i91;
  int32_T c24_i92;
  int32_T c24_i93;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_Out3 = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Out3), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_Out3);
  c24_i91 = 0;
  for (c24_i92 = 0; c24_i92 < 3; c24_i92++) {
    for (c24_i93 = 0; c24_i93 < 3; c24_i93++) {
      (*(real_T (*)[9])c24_outData)[c24_i93 + c24_i91] = c24_y[c24_i93 + c24_i91];
    }

    c24_i91 += 3;
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i94;
  real_T c24_b_inData[3];
  int32_T c24_i95;
  real_T c24_u[3];
  const mxArray *c24_y = NULL;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i94 = 0; c24_i94 < 3; c24_i94++) {
    c24_b_inData[c24_i94] = (*(real_T (*)[3])c24_inData)[c24_i94];
  }

  for (c24_i95 = 0; c24_i95 < 3; c24_i95++) {
    c24_u[c24_i95] = c24_b_inData[c24_i95];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static void c24_c_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_Out2, const char_T *c24_identifier, real_T c24_y[3])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Out2), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_Out2);
}

static void c24_d_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[3])
{
  real_T c24_dv4[3];
  int32_T c24_i96;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c24_i96 = 0; c24_i96 < 3; c24_i96++) {
    c24_y[c24_i96] = c24_dv4[c24_i96];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_Out2;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[3];
  int32_T c24_i97;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_Out2 = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Out2), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_Out2);
  for (c24_i97 = 0; c24_i97 < 3; c24_i97++) {
    (*(real_T (*)[3])c24_outData)[c24_i97] = c24_y[c24_i97];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static real_T c24_e_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_nargout;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_nargout = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_nargout),
    &c24_thisId);
  sf_mex_destroy(&c24_nargout);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c24_info_helper(&c24_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c24_nameCaptureInfo);
  return c24_nameCaptureInfo;
}

static void c24_info_helper(const mxArray **c24_info)
{
  const mxArray *c24_rhs0 = NULL;
  const mxArray *c24_lhs0 = NULL;
  const mxArray *c24_rhs1 = NULL;
  const mxArray *c24_lhs1 = NULL;
  const mxArray *c24_rhs2 = NULL;
  const mxArray *c24_lhs2 = NULL;
  const mxArray *c24_rhs3 = NULL;
  const mxArray *c24_lhs3 = NULL;
  const mxArray *c24_rhs4 = NULL;
  const mxArray *c24_lhs4 = NULL;
  const mxArray *c24_rhs5 = NULL;
  const mxArray *c24_lhs5 = NULL;
  const mxArray *c24_rhs6 = NULL;
  const mxArray *c24_lhs6 = NULL;
  const mxArray *c24_rhs7 = NULL;
  const mxArray *c24_lhs7 = NULL;
  const mxArray *c24_rhs8 = NULL;
  const mxArray *c24_lhs8 = NULL;
  const mxArray *c24_rhs9 = NULL;
  const mxArray *c24_lhs9 = NULL;
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c24_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c24_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c24_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c24_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c24_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c24_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c24_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c24_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c24_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c24_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c24_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c24_rhs0);
  sf_mex_destroy(&c24_lhs0);
  sf_mex_destroy(&c24_rhs1);
  sf_mex_destroy(&c24_lhs1);
  sf_mex_destroy(&c24_rhs2);
  sf_mex_destroy(&c24_lhs2);
  sf_mex_destroy(&c24_rhs3);
  sf_mex_destroy(&c24_lhs3);
  sf_mex_destroy(&c24_rhs4);
  sf_mex_destroy(&c24_lhs4);
  sf_mex_destroy(&c24_rhs5);
  sf_mex_destroy(&c24_lhs5);
  sf_mex_destroy(&c24_rhs6);
  sf_mex_destroy(&c24_lhs6);
  sf_mex_destroy(&c24_rhs7);
  sf_mex_destroy(&c24_lhs7);
  sf_mex_destroy(&c24_rhs8);
  sf_mex_destroy(&c24_lhs8);
  sf_mex_destroy(&c24_rhs9);
  sf_mex_destroy(&c24_lhs9);
}

static const mxArray *c24_emlrt_marshallOut(char * c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c24_u)), FALSE);
  return c24_y;
}

static const mxArray *c24_b_emlrt_marshallOut(uint32_T c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c24_y;
}

static void c24_eml_scalar_eg(SFc24_QRsimInstanceStruct *chartInstance)
{
}

static void c24_b_eml_scalar_eg(SFc24_QRsimInstanceStruct *chartInstance)
{
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static int32_T c24_f_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i98;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i98, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i98;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_g_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_b_is_active_c24_QRsim, const char_T *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_QRsim), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_QRsim);
  return c24_y;
}

static uint8_T c24_h_emlrt_marshallIn(SFc24_QRsimInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_QRsimInstanceStruct *chartInstance)
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

void sf_c24_QRsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(617896165U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3635043606U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(183624646U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3281393969U);
}

mxArray *sf_c24_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("R5l3DC8Wj6XVPFowYZX7zC");
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
      pr[1] = (double)(3);
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

mxArray *sf_c24_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c24_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c24_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Out1\",},{M[1],M[13],T\"Out2\",},{M[1],M[14],T\"Out3\",},{M[8],M[0],T\"is_active_c24_QRsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc24_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           24,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Out1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Omega");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Omegac");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dOmegac");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Out2");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Out3");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,263);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)
            c24_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)
            c24_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)
            c24_sf_marshallIn);
        }

        {
          real_T (*c24_R)[9];
          real_T (*c24_Rc)[9];
          real_T (*c24_Out1)[3];
          real_T (*c24_Omega)[3];
          real_T (*c24_Omegac)[3];
          real_T (*c24_dOmegac)[3];
          real_T (*c24_Out2)[3];
          real_T (*c24_Out3)[9];
          c24_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
          c24_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c24_dOmegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c24_Omegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c24_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c24_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c24_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c24_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c24_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c24_Rc);
          _SFD_SET_DATA_VALUE_PTR(2U, *c24_Out1);
          _SFD_SET_DATA_VALUE_PTR(3U, *c24_Omega);
          _SFD_SET_DATA_VALUE_PTR(4U, *c24_Omegac);
          _SFD_SET_DATA_VALUE_PTR(5U, *c24_dOmegac);
          _SFD_SET_DATA_VALUE_PTR(6U, *c24_Out2);
          _SFD_SET_DATA_VALUE_PTR(7U, *c24_Out3);
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
  return "vTKiRwRbg6ybhdyCZZAMrB";
}

static void sf_opaque_initialize_c24_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_QRsim(void *chartInstanceVar)
{
  enable_c24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c24_QRsim(void *chartInstanceVar)
{
  disable_c24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c24_QRsim(void *chartInstanceVar)
{
  sf_c24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_QRsim((SFc24_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c24_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_QRsim((SFc24_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c24_QRsim(S);
}

static void sf_opaque_set_sim_state_c24_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c24_QRsim(S, st);
}

static void sf_opaque_terminate_c24_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_QRsim((SFc24_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c24_QRsim((SFc24_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,24,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,24);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,24,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,24,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2215708521U));
  ssSetChecksum1(S,(2506716582U));
  ssSetChecksum2(S,(1993066233U));
  ssSetChecksum3(S,(1911737586U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c24_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_QRsim(SimStruct *S)
{
  SFc24_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc24_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc24_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c24_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c24_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c24_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c24_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c24_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c24_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c24_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c24_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c24_QRsim;
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

void c24_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
