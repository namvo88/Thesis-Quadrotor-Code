/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QR2Dsim_sfun.h"
#include "c20_QR2Dsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QR2Dsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c20_debug_family_names[14] = { "p", "q", "r", "Omegahat",
  "nargin", "nargout", "R", "Rd", "Omega", "Omegad", "dOmegad", "Out1", "Out2",
  "Out3" };

/* Function Declarations */
static void initialize_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void initialize_params_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct
  *chartInstance);
static void enable_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void disable_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct
  *chartInstance);
static void set_sim_state_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_st);
static void finalize_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void sf_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void c20_chartstep_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void initSimStructsc20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_Out3, const char_T *c20_identifier, real_T c20_y[9]);
static void c20_b_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[9]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_c_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_Out2, const char_T *c20_identifier, real_T c20_y[3]);
static void c20_d_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[3]);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_e_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(uint32_T c20_u);
static void c20_eml_scalar_eg(SFc20_QR2DsimInstanceStruct *chartInstance);
static void c20_b_eml_scalar_eg(SFc20_QR2DsimInstanceStruct *chartInstance);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_f_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_g_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_b_is_active_c20_QR2Dsim, const char_T *c20_identifier);
static uint8_T c20_h_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void init_dsm_address_info(SFc20_QR2DsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_QR2Dsim = 0U;
}

static void initialize_params_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct
  *chartInstance)
{
}

static void enable_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct
  *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  real_T c20_u[3];
  const mxArray *c20_b_y = NULL;
  int32_T c20_i1;
  real_T c20_b_u[3];
  const mxArray *c20_c_y = NULL;
  int32_T c20_i2;
  real_T c20_c_u[9];
  const mxArray *c20_d_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  real_T (*c20_Out3)[9];
  real_T (*c20_Out2)[3];
  real_T (*c20_Out1)[3];
  c20_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(4), FALSE);
  for (c20_i0 = 0; c20_i0 < 3; c20_i0++) {
    c20_u[c20_i0] = (*c20_Out1)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  for (c20_i1 = 0; c20_i1 < 3; c20_i1++) {
    c20_b_u[c20_i1] = (*c20_Out2)[c20_i1];
  }

  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", c20_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  for (c20_i2 = 0; c20_i2 < 9; c20_i2++) {
    c20_c_u[c20_i2] = (*c20_Out3)[c20_i2];
  }

  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_hoistedGlobal = chartInstance->c20_is_active_c20_QR2Dsim;
  c20_d_u = c20_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  sf_mex_assign(&c20_st, c20_y, FALSE);
  return c20_st;
}

static void set_sim_state_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv0[3];
  int32_T c20_i3;
  real_T c20_dv1[3];
  int32_T c20_i4;
  real_T c20_dv2[9];
  int32_T c20_i5;
  real_T (*c20_Out1)[3];
  real_T (*c20_Out2)[3];
  real_T (*c20_Out3)[9];
  c20_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)),
    "Out1", c20_dv0);
  for (c20_i3 = 0; c20_i3 < 3; c20_i3++) {
    (*c20_Out1)[c20_i3] = c20_dv0[c20_i3];
  }

  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
    "Out2", c20_dv1);
  for (c20_i4 = 0; c20_i4 < 3; c20_i4++) {
    (*c20_Out2)[c20_i4] = c20_dv1[c20_i4];
  }

  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 2)),
                       "Out3", c20_dv2);
  for (c20_i5 = 0; c20_i5 < 9; c20_i5++) {
    (*c20_Out3)[c20_i5] = c20_dv2[c20_i5];
  }

  chartInstance->c20_is_active_c20_QR2Dsim = c20_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 3)),
     "is_active_c20_QR2Dsim");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_QR2Dsim(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
}

static void sf_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c20_i6;
  int32_T c20_i7;
  int32_T c20_i8;
  int32_T c20_i9;
  int32_T c20_i10;
  int32_T c20_i11;
  int32_T c20_i12;
  int32_T c20_i13;
  real_T (*c20_Out3)[9];
  real_T (*c20_Out2)[3];
  real_T (*c20_dOmegad)[3];
  real_T (*c20_Omegad)[3];
  real_T (*c20_Omega)[3];
  real_T (*c20_Out1)[3];
  real_T (*c20_Rd)[9];
  real_T (*c20_R)[9];
  c20_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_dOmegad = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c20_Omegad = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c20_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c20_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_Rd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c20_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c20_sfEvent);
  for (c20_i6 = 0; c20_i6 < 9; c20_i6++) {
    _SFD_DATA_RANGE_CHECK((*c20_R)[c20_i6], 0U);
  }

  for (c20_i7 = 0; c20_i7 < 9; c20_i7++) {
    _SFD_DATA_RANGE_CHECK((*c20_Rd)[c20_i7], 1U);
  }

  for (c20_i8 = 0; c20_i8 < 3; c20_i8++) {
    _SFD_DATA_RANGE_CHECK((*c20_Out1)[c20_i8], 2U);
  }

  for (c20_i9 = 0; c20_i9 < 3; c20_i9++) {
    _SFD_DATA_RANGE_CHECK((*c20_Omega)[c20_i9], 3U);
  }

  for (c20_i10 = 0; c20_i10 < 3; c20_i10++) {
    _SFD_DATA_RANGE_CHECK((*c20_Omegad)[c20_i10], 4U);
  }

  for (c20_i11 = 0; c20_i11 < 3; c20_i11++) {
    _SFD_DATA_RANGE_CHECK((*c20_dOmegad)[c20_i11], 5U);
  }

  for (c20_i12 = 0; c20_i12 < 3; c20_i12++) {
    _SFD_DATA_RANGE_CHECK((*c20_Out2)[c20_i12], 6U);
  }

  for (c20_i13 = 0; c20_i13 < 9; c20_i13++) {
    _SFD_DATA_RANGE_CHECK((*c20_Out3)[c20_i13], 7U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  c20_chartstep_c20_QR2Dsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QR2DsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c20_chartstep_c20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c20_i14;
  real_T c20_R[9];
  int32_T c20_i15;
  real_T c20_Rd[9];
  int32_T c20_i16;
  real_T c20_Omega[3];
  int32_T c20_i17;
  real_T c20_Omegad[3];
  int32_T c20_i18;
  real_T c20_dOmegad[3];
  uint32_T c20_debug_family_var_map[14];
  real_T c20_p;
  real_T c20_q;
  real_T c20_r;
  real_T c20_Omegahat[9];
  real_T c20_nargin = 5.0;
  real_T c20_nargout = 3.0;
  real_T c20_Out1[3];
  real_T c20_Out2[3];
  real_T c20_Out3[9];
  int32_T c20_i19;
  real_T c20_a[9];
  int32_T c20_i20;
  int32_T c20_i21;
  int32_T c20_i22;
  int32_T c20_i23;
  real_T c20_b[9];
  int32_T c20_i24;
  int32_T c20_i25;
  int32_T c20_i26;
  real_T c20_y[9];
  int32_T c20_i27;
  int32_T c20_i28;
  int32_T c20_i29;
  int32_T c20_i30;
  int32_T c20_i31;
  int32_T c20_i32;
  real_T c20_b_y[9];
  int32_T c20_i33;
  int32_T c20_i34;
  int32_T c20_i35;
  real_T c20_b_b[3];
  int32_T c20_i36;
  int32_T c20_i37;
  int32_T c20_i38;
  real_T c20_C[3];
  int32_T c20_i39;
  int32_T c20_i40;
  int32_T c20_i41;
  int32_T c20_i42;
  int32_T c20_i43;
  int32_T c20_i44;
  int32_T c20_i45;
  int32_T c20_i46;
  int32_T c20_i47;
  int32_T c20_i48;
  int32_T c20_i49;
  int32_T c20_i50;
  int32_T c20_i51;
  int32_T c20_i52;
  int32_T c20_i53;
  int32_T c20_i54;
  int32_T c20_i55;
  int32_T c20_i56;
  int32_T c20_i57;
  int32_T c20_i58;
  int32_T c20_i59;
  int32_T c20_i60;
  int32_T c20_i61;
  int32_T c20_i62;
  int32_T c20_i63;
  int32_T c20_i64;
  int32_T c20_i65;
  int32_T c20_i66;
  int32_T c20_i67;
  int32_T c20_i68;
  int32_T c20_i69;
  int32_T c20_i70;
  int32_T c20_i71;
  int32_T c20_i72;
  int32_T c20_i73;
  int32_T c20_i74;
  int32_T c20_i75;
  int32_T c20_i76;
  int32_T c20_i77;
  int32_T c20_i78;
  int32_T c20_i79;
  int32_T c20_i80;
  int32_T c20_i81;
  int32_T c20_i82;
  int32_T c20_i83;
  real_T (*c20_b_Out1)[3];
  real_T (*c20_b_Out2)[3];
  real_T (*c20_b_Out3)[9];
  real_T (*c20_b_dOmegad)[3];
  real_T (*c20_b_Omegad)[3];
  real_T (*c20_b_Omega)[3];
  real_T (*c20_b_Rd)[9];
  real_T (*c20_b_R)[9];
  c20_b_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_b_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_b_dOmegad = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c20_b_Omegad = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c20_b_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c20_b_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_b_Rd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c20_sfEvent);
  for (c20_i14 = 0; c20_i14 < 9; c20_i14++) {
    c20_R[c20_i14] = (*c20_b_R)[c20_i14];
  }

  for (c20_i15 = 0; c20_i15 < 9; c20_i15++) {
    c20_Rd[c20_i15] = (*c20_b_Rd)[c20_i15];
  }

  for (c20_i16 = 0; c20_i16 < 3; c20_i16++) {
    c20_Omega[c20_i16] = (*c20_b_Omega)[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 3; c20_i17++) {
    c20_Omegad[c20_i17] = (*c20_b_Omegad)[c20_i17];
  }

  for (c20_i18 = 0; c20_i18 < 3; c20_i18++) {
    c20_dOmegad[c20_i18] = (*c20_b_dOmegad)[c20_i18];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_p, 0U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_q, 1U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_r, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Omegahat, 3U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 4U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 5U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_R, 6U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_Rd, 7U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_Omega, 8U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_Omegad, 9U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_dOmegad, 10U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Out1, 11U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Out2, 12U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Out3, 13U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_p = c20_Omega[0];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 5);
  c20_q = c20_Omega[1];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
  c20_r = c20_Omega[2];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_Omegahat[0] = 0.0;
  c20_Omegahat[3] = -c20_r;
  c20_Omegahat[6] = c20_q;
  c20_Omegahat[1] = c20_r;
  c20_Omegahat[4] = 0.0;
  c20_Omegahat[7] = -c20_p;
  c20_Omegahat[2] = -c20_q;
  c20_Omegahat[5] = c20_p;
  c20_Omegahat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 12);
  for (c20_i19 = 0; c20_i19 < 9; c20_i19++) {
    c20_a[c20_i19] = c20_Omegahat[c20_i19];
  }

  c20_i20 = 0;
  for (c20_i21 = 0; c20_i21 < 3; c20_i21++) {
    c20_i22 = 0;
    for (c20_i23 = 0; c20_i23 < 3; c20_i23++) {
      c20_b[c20_i23 + c20_i20] = c20_R[c20_i22 + c20_i21];
      c20_i22 += 3;
    }

    c20_i20 += 3;
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i24 = 0; c20_i24 < 3; c20_i24++) {
    c20_i25 = 0;
    for (c20_i26 = 0; c20_i26 < 3; c20_i26++) {
      c20_y[c20_i25 + c20_i24] = 0.0;
      c20_i27 = 0;
      for (c20_i28 = 0; c20_i28 < 3; c20_i28++) {
        c20_y[c20_i25 + c20_i24] += c20_a[c20_i27 + c20_i24] * c20_b[c20_i28 +
          c20_i25];
        c20_i27 += 3;
      }

      c20_i25 += 3;
    }
  }

  for (c20_i29 = 0; c20_i29 < 9; c20_i29++) {
    c20_b[c20_i29] = c20_Rd[c20_i29];
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i30 = 0; c20_i30 < 3; c20_i30++) {
    c20_i31 = 0;
    for (c20_i32 = 0; c20_i32 < 3; c20_i32++) {
      c20_b_y[c20_i31 + c20_i30] = 0.0;
      c20_i33 = 0;
      for (c20_i34 = 0; c20_i34 < 3; c20_i34++) {
        c20_b_y[c20_i31 + c20_i30] += c20_y[c20_i33 + c20_i30] * c20_b[c20_i34 +
          c20_i31];
        c20_i33 += 3;
      }

      c20_i31 += 3;
    }
  }

  for (c20_i35 = 0; c20_i35 < 3; c20_i35++) {
    c20_b_b[c20_i35] = c20_Omegad[c20_i35];
  }

  c20_b_eml_scalar_eg(chartInstance);
  c20_b_eml_scalar_eg(chartInstance);
  for (c20_i36 = 0; c20_i36 < 3; c20_i36++) {
    c20_Out1[c20_i36] = 0.0;
  }

  for (c20_i37 = 0; c20_i37 < 3; c20_i37++) {
    c20_Out1[c20_i37] = 0.0;
  }

  for (c20_i38 = 0; c20_i38 < 3; c20_i38++) {
    c20_C[c20_i38] = c20_Out1[c20_i38];
  }

  for (c20_i39 = 0; c20_i39 < 3; c20_i39++) {
    c20_Out1[c20_i39] = c20_C[c20_i39];
  }

  for (c20_i40 = 0; c20_i40 < 3; c20_i40++) {
    c20_C[c20_i40] = c20_Out1[c20_i40];
  }

  for (c20_i41 = 0; c20_i41 < 3; c20_i41++) {
    c20_Out1[c20_i41] = c20_C[c20_i41];
  }

  for (c20_i42 = 0; c20_i42 < 3; c20_i42++) {
    c20_Out1[c20_i42] = 0.0;
    c20_i43 = 0;
    for (c20_i44 = 0; c20_i44 < 3; c20_i44++) {
      c20_Out1[c20_i42] += c20_b_y[c20_i43 + c20_i42] * c20_b_b[c20_i44];
      c20_i43 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 13);
  c20_i45 = 0;
  for (c20_i46 = 0; c20_i46 < 3; c20_i46++) {
    c20_i47 = 0;
    for (c20_i48 = 0; c20_i48 < 3; c20_i48++) {
      c20_a[c20_i48 + c20_i45] = c20_R[c20_i47 + c20_i46];
      c20_i47 += 3;
    }

    c20_i45 += 3;
  }

  for (c20_i49 = 0; c20_i49 < 9; c20_i49++) {
    c20_b[c20_i49] = c20_Rd[c20_i49];
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i50 = 0; c20_i50 < 3; c20_i50++) {
    c20_i51 = 0;
    for (c20_i52 = 0; c20_i52 < 3; c20_i52++) {
      c20_y[c20_i51 + c20_i50] = 0.0;
      c20_i53 = 0;
      for (c20_i54 = 0; c20_i54 < 3; c20_i54++) {
        c20_y[c20_i51 + c20_i50] += c20_a[c20_i53 + c20_i50] * c20_b[c20_i54 +
          c20_i51];
        c20_i53 += 3;
      }

      c20_i51 += 3;
    }
  }

  for (c20_i55 = 0; c20_i55 < 3; c20_i55++) {
    c20_b_b[c20_i55] = c20_dOmegad[c20_i55];
  }

  c20_b_eml_scalar_eg(chartInstance);
  c20_b_eml_scalar_eg(chartInstance);
  for (c20_i56 = 0; c20_i56 < 3; c20_i56++) {
    c20_Out2[c20_i56] = 0.0;
  }

  for (c20_i57 = 0; c20_i57 < 3; c20_i57++) {
    c20_Out2[c20_i57] = 0.0;
  }

  for (c20_i58 = 0; c20_i58 < 3; c20_i58++) {
    c20_C[c20_i58] = c20_Out2[c20_i58];
  }

  for (c20_i59 = 0; c20_i59 < 3; c20_i59++) {
    c20_Out2[c20_i59] = c20_C[c20_i59];
  }

  for (c20_i60 = 0; c20_i60 < 3; c20_i60++) {
    c20_C[c20_i60] = c20_Out2[c20_i60];
  }

  for (c20_i61 = 0; c20_i61 < 3; c20_i61++) {
    c20_Out2[c20_i61] = c20_C[c20_i61];
  }

  for (c20_i62 = 0; c20_i62 < 3; c20_i62++) {
    c20_Out2[c20_i62] = 0.0;
    c20_i63 = 0;
    for (c20_i64 = 0; c20_i64 < 3; c20_i64++) {
      c20_Out2[c20_i62] += c20_y[c20_i63 + c20_i62] * c20_b_b[c20_i64];
      c20_i63 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 14);
  c20_i65 = 0;
  for (c20_i66 = 0; c20_i66 < 3; c20_i66++) {
    c20_i67 = 0;
    for (c20_i68 = 0; c20_i68 < 3; c20_i68++) {
      c20_a[c20_i68 + c20_i65] = c20_R[c20_i67 + c20_i66];
      c20_i67 += 3;
    }

    c20_i65 += 3;
  }

  for (c20_i69 = 0; c20_i69 < 9; c20_i69++) {
    c20_b[c20_i69] = c20_Rd[c20_i69];
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i70 = 0; c20_i70 < 9; c20_i70++) {
    c20_Out3[c20_i70] = 0.0;
  }

  for (c20_i71 = 0; c20_i71 < 9; c20_i71++) {
    c20_Out3[c20_i71] = 0.0;
  }

  for (c20_i72 = 0; c20_i72 < 9; c20_i72++) {
    c20_b_y[c20_i72] = c20_Out3[c20_i72];
  }

  for (c20_i73 = 0; c20_i73 < 9; c20_i73++) {
    c20_Out3[c20_i73] = c20_b_y[c20_i73];
  }

  for (c20_i74 = 0; c20_i74 < 9; c20_i74++) {
    c20_b_y[c20_i74] = c20_Out3[c20_i74];
  }

  for (c20_i75 = 0; c20_i75 < 9; c20_i75++) {
    c20_Out3[c20_i75] = c20_b_y[c20_i75];
  }

  for (c20_i76 = 0; c20_i76 < 3; c20_i76++) {
    c20_i77 = 0;
    for (c20_i78 = 0; c20_i78 < 3; c20_i78++) {
      c20_Out3[c20_i77 + c20_i76] = 0.0;
      c20_i79 = 0;
      for (c20_i80 = 0; c20_i80 < 3; c20_i80++) {
        c20_Out3[c20_i77 + c20_i76] += c20_a[c20_i79 + c20_i76] * c20_b[c20_i80
          + c20_i77];
        c20_i79 += 3;
      }

      c20_i77 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i81 = 0; c20_i81 < 3; c20_i81++) {
    (*c20_b_Out1)[c20_i81] = c20_Out1[c20_i81];
  }

  for (c20_i82 = 0; c20_i82 < 3; c20_i82++) {
    (*c20_b_Out2)[c20_i82] = c20_Out2[c20_i82];
  }

  for (c20_i83 = 0; c20_i83 < 9; c20_i83++) {
    (*c20_b_Out3)[c20_i83] = c20_Out3[c20_i83];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c20_sfEvent);
}

static void initSimStructsc20_QR2Dsim(SFc20_QR2DsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i84;
  int32_T c20_i85;
  int32_T c20_i86;
  real_T c20_b_inData[9];
  int32_T c20_i87;
  int32_T c20_i88;
  int32_T c20_i89;
  real_T c20_u[9];
  const mxArray *c20_y = NULL;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i84 = 0;
  for (c20_i85 = 0; c20_i85 < 3; c20_i85++) {
    for (c20_i86 = 0; c20_i86 < 3; c20_i86++) {
      c20_b_inData[c20_i86 + c20_i84] = (*(real_T (*)[9])c20_inData)[c20_i86 +
        c20_i84];
    }

    c20_i84 += 3;
  }

  c20_i87 = 0;
  for (c20_i88 = 0; c20_i88 < 3; c20_i88++) {
    for (c20_i89 = 0; c20_i89 < 3; c20_i89++) {
      c20_u[c20_i89 + c20_i87] = c20_b_inData[c20_i89 + c20_i87];
    }

    c20_i87 += 3;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_Out3, const char_T *c20_identifier, real_T c20_y[9])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Out3), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_Out3);
}

static void c20_b_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[9])
{
  real_T c20_dv3[9];
  int32_T c20_i90;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c20_i90 = 0; c20_i90 < 9; c20_i90++) {
    c20_y[c20_i90] = c20_dv3[c20_i90];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_Out3;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[9];
  int32_T c20_i91;
  int32_T c20_i92;
  int32_T c20_i93;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_Out3 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Out3), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_Out3);
  c20_i91 = 0;
  for (c20_i92 = 0; c20_i92 < 3; c20_i92++) {
    for (c20_i93 = 0; c20_i93 < 3; c20_i93++) {
      (*(real_T (*)[9])c20_outData)[c20_i93 + c20_i91] = c20_y[c20_i93 + c20_i91];
    }

    c20_i91 += 3;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i94;
  real_T c20_b_inData[3];
  int32_T c20_i95;
  real_T c20_u[3];
  const mxArray *c20_y = NULL;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i94 = 0; c20_i94 < 3; c20_i94++) {
    c20_b_inData[c20_i94] = (*(real_T (*)[3])c20_inData)[c20_i94];
  }

  for (c20_i95 = 0; c20_i95 < 3; c20_i95++) {
    c20_u[c20_i95] = c20_b_inData[c20_i95];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_c_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_Out2, const char_T *c20_identifier, real_T c20_y[3])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Out2), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_Out2);
}

static void c20_d_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[3])
{
  real_T c20_dv4[3];
  int32_T c20_i96;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c20_i96 = 0; c20_i96 < 3; c20_i96++) {
    c20_y[c20_i96] = c20_dv4[c20_i96];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_Out2;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[3];
  int32_T c20_i97;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_Out2 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Out2), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_Out2);
  for (c20_i97 = 0; c20_i97 < 3; c20_i97++) {
    (*(real_T (*)[3])c20_outData)[c20_i97] = c20_y[c20_i97];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static real_T c20_e_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_QR2Dsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  const mxArray *c20_rhs3 = NULL;
  const mxArray *c20_lhs3 = NULL;
  const mxArray *c20_rhs4 = NULL;
  const mxArray *c20_lhs4 = NULL;
  const mxArray *c20_rhs5 = NULL;
  const mxArray *c20_lhs5 = NULL;
  const mxArray *c20_rhs6 = NULL;
  const mxArray *c20_lhs6 = NULL;
  const mxArray *c20_rhs7 = NULL;
  const mxArray *c20_lhs7 = NULL;
  const mxArray *c20_rhs8 = NULL;
  const mxArray *c20_lhs8 = NULL;
  const mxArray *c20_rhs9 = NULL;
  const mxArray *c20_lhs9 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c20_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c20_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c20_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c20_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c20_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c20_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c20_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
  sf_mex_destroy(&c20_rhs3);
  sf_mex_destroy(&c20_lhs3);
  sf_mex_destroy(&c20_rhs4);
  sf_mex_destroy(&c20_lhs4);
  sf_mex_destroy(&c20_rhs5);
  sf_mex_destroy(&c20_lhs5);
  sf_mex_destroy(&c20_rhs6);
  sf_mex_destroy(&c20_lhs6);
  sf_mex_destroy(&c20_rhs7);
  sf_mex_destroy(&c20_lhs7);
  sf_mex_destroy(&c20_rhs8);
  sf_mex_destroy(&c20_lhs8);
  sf_mex_destroy(&c20_rhs9);
  sf_mex_destroy(&c20_lhs9);
}

static const mxArray *c20_emlrt_marshallOut(char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), FALSE);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c20_y;
}

static void c20_eml_scalar_eg(SFc20_QR2DsimInstanceStruct *chartInstance)
{
}

static void c20_b_eml_scalar_eg(SFc20_QR2DsimInstanceStruct *chartInstance)
{
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static int32_T c20_f_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i98;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i98, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i98;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_g_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_b_is_active_c20_QR2Dsim, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_QR2Dsim), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_QR2Dsim);
  return c20_y;
}

static uint8_T c20_h_emlrt_marshallIn(SFc20_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void init_dsm_address_info(SFc20_QR2DsimInstanceStruct *chartInstance)
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

void sf_c20_QR2Dsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4161152981U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(430676870U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3222712900U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3921860883U);
}

mxArray *sf_c20_QR2Dsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7pdsIN0pB5iYmJ4qoxjsRB");
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

mxArray *sf_c20_QR2Dsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_QR2Dsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_QR2Dsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Out1\",},{M[1],M[13],T\"Out2\",},{M[1],M[14],T\"Out3\",},{M[8],M[0],T\"is_active_c20_QR2Dsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_QR2Dsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_QR2DsimInstanceStruct *chartInstance;
    chartInstance = (SFc20_QR2DsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QR2DsimMachineNumber_,
           20,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rd");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Out1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Omega");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Omegad");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dOmegad");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,259);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
            c20_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
            c20_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          real_T (*c20_R)[9];
          real_T (*c20_Rd)[9];
          real_T (*c20_Out1)[3];
          real_T (*c20_Omega)[3];
          real_T (*c20_Omegad)[3];
          real_T (*c20_dOmegad)[3];
          real_T (*c20_Out2)[3];
          real_T (*c20_Out3)[9];
          c20_Out3 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
          c20_Out2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c20_dOmegad = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c20_Omegad = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c20_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c20_Out1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c20_Rd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c20_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c20_Rd);
          _SFD_SET_DATA_VALUE_PTR(2U, *c20_Out1);
          _SFD_SET_DATA_VALUE_PTR(3U, *c20_Omega);
          _SFD_SET_DATA_VALUE_PTR(4U, *c20_Omegad);
          _SFD_SET_DATA_VALUE_PTR(5U, *c20_dOmegad);
          _SFD_SET_DATA_VALUE_PTR(6U, *c20_Out2);
          _SFD_SET_DATA_VALUE_PTR(7U, *c20_Out3);
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
  return "LhZo4IwYZJcbqEkHHCnI2";
}

static void sf_opaque_initialize_c20_QR2Dsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_QR2DsimInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
  initialize_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_QR2Dsim(void *chartInstanceVar)
{
  enable_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_QR2Dsim(void *chartInstanceVar)
{
  disable_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_QR2Dsim(void *chartInstanceVar)
{
  sf_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_QR2Dsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_QR2Dsim();/* state var info */
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

extern void sf_internal_set_sim_state_c20_QR2Dsim(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_QR2Dsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_QR2Dsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_QR2Dsim(S);
}

static void sf_opaque_set_sim_state_c20_QR2Dsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c20_QR2Dsim(S, st);
}

static void sf_opaque_terminate_c20_QR2Dsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_QR2DsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QR2Dsim_optimization_info();
    }

    finalize_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_QR2Dsim((SFc20_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_QR2Dsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_QR2Dsim((SFc20_QR2DsimInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QR2Dsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,20,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3473494790U));
  ssSetChecksum1(S,(599298008U));
  ssSetChecksum2(S,(626844460U));
  ssSetChecksum3(S,(717998521U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_QR2Dsim(SimStruct *S)
{
  SFc20_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc20_QR2DsimInstanceStruct *)utMalloc(sizeof
    (SFc20_QR2DsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_QR2DsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c20_QR2Dsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c20_QR2Dsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c20_QR2Dsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_QR2Dsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_QR2Dsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c20_QR2Dsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c20_QR2Dsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c20_QR2Dsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_QR2Dsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_QR2Dsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c20_QR2Dsim;
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

void c20_QR2Dsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_QR2Dsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_QR2Dsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_QR2Dsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_QR2Dsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
