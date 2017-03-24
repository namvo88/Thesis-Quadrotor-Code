/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c8_QRsim.h"
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
static const char * c8_debug_family_names[5] = { "nargin", "nargout", "R",
  "Rdes", "eRhat" };
=======
static const char * c8_debug_family_names[6] = { "eRhat", "nargin", "nargout",
  "R", "Rdes", "eR" };
>>>>>>> developErrorAngularVelocity

/* Function Declarations */
static void initialize_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void initialize_params_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void enable_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void disable_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_QRsim(SFc8_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c8_QRsim(SFc8_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_st);
static void finalize_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void sf_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void c8_chartstep_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void initSimStructsc8_QRsim(SFc8_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c8_eRhat, const char_T *c8_identifier, real_T c8_y[9]);
=======
  mxArray *c8_eR, const char_T *c8_identifier, real_T c8_y[3]);
>>>>>>> developErrorAngularVelocity
static void c8_b_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance, const
  mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[3]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
<<<<<<< HEAD
=======
static void c8_d_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance, const
  mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[9]);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
>>>>>>> developErrorAngularVelocity
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(uint32_T c8_u);
static void c8_eml_scalar_eg(SFc8_QRsimInstanceStruct *chartInstance);
<<<<<<< HEAD
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
=======
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
>>>>>>> developErrorAngularVelocity
  *c8_inData);
static int32_T c8_e_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_f_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_QRsim, const char_T *c8_identifier);
static uint8_T c8_g_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_QRsim = 0U;
}

static void initialize_params_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_QRsim(SFc8_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c8_QRsim(SFc8_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[3];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
<<<<<<< HEAD
  real_T (*c8_eRhat)[9];
  c8_eRhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
=======
  real_T (*c8_eR)[3];
  c8_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
>>>>>>> developErrorAngularVelocity
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2), FALSE);
<<<<<<< HEAD
  for (c8_i0 = 0; c8_i0 < 9; c8_i0++) {
    c8_u[c8_i0] = (*c8_eRhat)[c8_i0];
=======
  for (c8_i0 = 0; c8_i0 < 3; c8_i0++) {
    c8_u[c8_i0] = (*c8_eR)[c8_i0];
>>>>>>> developErrorAngularVelocity
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_QRsim;
  c8_b_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[3];
  int32_T c8_i1;
<<<<<<< HEAD
  real_T (*c8_eRhat)[9];
  c8_eRhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                      "eRhat", c8_dv0);
  for (c8_i1 = 0; c8_i1 < 9; c8_i1++) {
    (*c8_eRhat)[c8_i1] = c8_dv0[c8_i1];
=======
  real_T (*c8_eR)[3];
  c8_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)), "eR",
                      c8_dv0);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    (*c8_eR)[c8_i1] = c8_dv0[c8_i1];
>>>>>>> developErrorAngularVelocity
  }

  chartInstance->c8_is_active_c8_QRsim = c8_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 1)), "is_active_c8_QRsim");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_QRsim(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
  int32_T c8_i2;
  int32_T c8_i3;
  int32_T c8_i4;
<<<<<<< HEAD
  real_T (*c8_eRhat)[9];
  real_T (*c8_Rdes)[9];
  real_T (*c8_R)[9];
  c8_eRhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
=======
  real_T (*c8_eR)[3];
  real_T (*c8_Rdes)[9];
  real_T (*c8_R)[9];
  c8_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
>>>>>>> developErrorAngularVelocity
  c8_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c8_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  for (c8_i2 = 0; c8_i2 < 9; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((*c8_R)[c8_i2], 0U);
  }

  for (c8_i3 = 0; c8_i3 < 9; c8_i3++) {
    _SFD_DATA_RANGE_CHECK((*c8_Rdes)[c8_i3], 1U);
<<<<<<< HEAD
  }

  for (c8_i4 = 0; c8_i4 < 9; c8_i4++) {
    _SFD_DATA_RANGE_CHECK((*c8_eRhat)[c8_i4], 2U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_chartstep_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
  int32_T c8_i5;
  real_T c8_R[9];
  int32_T c8_i6;
  real_T c8_Rdes[9];
  uint32_T c8_debug_family_var_map[5];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  real_T c8_eRhat[9];
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  int32_T c8_i10;
  real_T c8_a[9];
  int32_T c8_i11;
  real_T c8_b[9];
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  real_T c8_y[9];
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  int32_T c8_i23;
  int32_T c8_i24;
  real_T c8_b_y[9];
  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  int32_T c8_i28;
  int32_T c8_i29;
  real_T (*c8_b_eRhat)[9];
  real_T (*c8_b_Rdes)[9];
  real_T (*c8_b_R)[9];
  c8_b_eRhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  for (c8_i5 = 0; c8_i5 < 9; c8_i5++) {
    c8_R[c8_i5] = (*c8_b_R)[c8_i5];
  }

  for (c8_i6 = 0; c8_i6 < 9; c8_i6++) {
    c8_Rdes[c8_i6] = (*c8_b_Rdes)[c8_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_R, 2U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_Rdes, 3U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_eRhat, 4U, c8_sf_marshallOut,
=======
  }

  for (c8_i4 = 0; c8_i4 < 3; c8_i4++) {
    _SFD_DATA_RANGE_CHECK((*c8_eR)[c8_i4], 2U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_chartstep_c8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
  int32_T c8_i5;
  real_T c8_R[9];
  int32_T c8_i6;
  real_T c8_Rdes[9];
  uint32_T c8_debug_family_var_map[6];
  real_T c8_eRhat[9];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  real_T c8_eR[3];
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  int32_T c8_i10;
  real_T c8_a[9];
  int32_T c8_i11;
  real_T c8_b[9];
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  real_T c8_y[9];
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  int32_T c8_i23;
  int32_T c8_i24;
  real_T c8_b_y[9];
  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  int32_T c8_i28;
  int32_T c8_i29;
  real_T (*c8_b_eR)[3];
  real_T (*c8_b_Rdes)[9];
  real_T (*c8_b_R)[9];
  c8_b_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  for (c8_i5 = 0; c8_i5 < 9; c8_i5++) {
    c8_R[c8_i5] = (*c8_b_R)[c8_i5];
  }

  for (c8_i6 = 0; c8_i6 < 9; c8_i6++) {
    c8_Rdes[c8_i6] = (*c8_b_Rdes)[c8_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_eRhat, 0U, c8_b_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 1U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 2U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_R, 3U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_Rdes, 4U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_eR, 5U, c8_sf_marshallOut,
>>>>>>> developErrorAngularVelocity
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_i7 = 0;
  for (c8_i8 = 0; c8_i8 < 3; c8_i8++) {
    c8_i9 = 0;
    for (c8_i10 = 0; c8_i10 < 3; c8_i10++) {
      c8_a[c8_i10 + c8_i7] = c8_Rdes[c8_i9 + c8_i8];
      c8_i9 += 3;
    }

    c8_i7 += 3;
  }

  for (c8_i11 = 0; c8_i11 < 9; c8_i11++) {
    c8_b[c8_i11] = c8_R[c8_i11];
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i12 = 0; c8_i12 < 3; c8_i12++) {
    c8_i13 = 0;
    for (c8_i14 = 0; c8_i14 < 3; c8_i14++) {
      c8_y[c8_i13 + c8_i12] = 0.0;
      c8_i15 = 0;
      for (c8_i16 = 0; c8_i16 < 3; c8_i16++) {
        c8_y[c8_i13 + c8_i12] += c8_a[c8_i15 + c8_i12] * c8_b[c8_i16 + c8_i13];
        c8_i15 += 3;
      }

      c8_i13 += 3;
    }
  }

  c8_i17 = 0;
  for (c8_i18 = 0; c8_i18 < 3; c8_i18++) {
    c8_i19 = 0;
    for (c8_i20 = 0; c8_i20 < 3; c8_i20++) {
      c8_a[c8_i20 + c8_i17] = c8_R[c8_i19 + c8_i18];
      c8_i19 += 3;
    }

    c8_i17 += 3;
<<<<<<< HEAD
  }

  for (c8_i21 = 0; c8_i21 < 9; c8_i21++) {
    c8_b[c8_i21] = c8_Rdes[c8_i21];
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
    c8_i23 = 0;
    for (c8_i24 = 0; c8_i24 < 3; c8_i24++) {
      c8_b_y[c8_i23 + c8_i22] = 0.0;
      c8_i25 = 0;
      for (c8_i26 = 0; c8_i26 < 3; c8_i26++) {
        c8_b_y[c8_i23 + c8_i22] += c8_a[c8_i25 + c8_i22] * c8_b[c8_i26 + c8_i23];
        c8_i25 += 3;
      }

      c8_i23 += 3;
    }
  }

  for (c8_i27 = 0; c8_i27 < 9; c8_i27++) {
    c8_y[c8_i27] -= c8_b_y[c8_i27];
  }

  for (c8_i28 = 0; c8_i28 < 9; c8_i28++) {
    c8_eRhat[c8_i28] = 0.5 * c8_y[c8_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_i29 = 0; c8_i29 < 9; c8_i29++) {
    (*c8_b_eRhat)[c8_i29] = c8_eRhat[c8_i29];
  }

=======
  }

  for (c8_i21 = 0; c8_i21 < 9; c8_i21++) {
    c8_b[c8_i21] = c8_Rdes[c8_i21];
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
    c8_i23 = 0;
    for (c8_i24 = 0; c8_i24 < 3; c8_i24++) {
      c8_b_y[c8_i23 + c8_i22] = 0.0;
      c8_i25 = 0;
      for (c8_i26 = 0; c8_i26 < 3; c8_i26++) {
        c8_b_y[c8_i23 + c8_i22] += c8_a[c8_i25 + c8_i22] * c8_b[c8_i26 + c8_i23];
        c8_i25 += 3;
      }

      c8_i23 += 3;
    }
  }

  for (c8_i27 = 0; c8_i27 < 9; c8_i27++) {
    c8_y[c8_i27] -= c8_b_y[c8_i27];
  }

  for (c8_i28 = 0; c8_i28 < 9; c8_i28++) {
    c8_eRhat[c8_i28] = 0.5 * c8_y[c8_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_eR[0] = c8_eRhat[5];
  c8_eR[1] = -c8_eRhat[2];
  c8_eR[2] = c8_eRhat[1];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_i29 = 0; c8_i29 < 3; c8_i29++) {
    (*c8_b_eR)[c8_i29] = c8_eR[c8_i29];
  }

>>>>>>> developErrorAngularVelocity
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_QRsim(SFc8_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i30;
<<<<<<< HEAD
  int32_T c8_i31;
  int32_T c8_i32;
  real_T c8_b_inData[9];
  int32_T c8_i33;
  int32_T c8_i34;
  int32_T c8_i35;
  real_T c8_u[9];
=======
  real_T c8_b_inData[3];
  int32_T c8_i31;
  real_T c8_u[3];
>>>>>>> developErrorAngularVelocity
  const mxArray *c8_y = NULL;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
<<<<<<< HEAD
  c8_i30 = 0;
  for (c8_i31 = 0; c8_i31 < 3; c8_i31++) {
    for (c8_i32 = 0; c8_i32 < 3; c8_i32++) {
      c8_b_inData[c8_i32 + c8_i30] = (*(real_T (*)[9])c8_inData)[c8_i32 + c8_i30];
    }

    c8_i30 += 3;
  }

  c8_i33 = 0;
  for (c8_i34 = 0; c8_i34 < 3; c8_i34++) {
    for (c8_i35 = 0; c8_i35 < 3; c8_i35++) {
      c8_u[c8_i35 + c8_i33] = c8_b_inData[c8_i35 + c8_i33];
    }

    c8_i33 += 3;
=======
  for (c8_i30 = 0; c8_i30 < 3; c8_i30++) {
    c8_b_inData[c8_i30] = (*(real_T (*)[3])c8_inData)[c8_i30];
  }

  for (c8_i31 = 0; c8_i31 < 3; c8_i31++) {
    c8_u[c8_i31] = c8_b_inData[c8_i31];
>>>>>>> developErrorAngularVelocity
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance, const
<<<<<<< HEAD
  mxArray *c8_eRhat, const char_T *c8_identifier, real_T c8_y[9])
=======
  mxArray *c8_eR, const char_T *c8_identifier, real_T c8_y[3])
>>>>>>> developErrorAngularVelocity
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
<<<<<<< HEAD
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_eRhat), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_eRhat);
=======
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_eR), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_eR);
>>>>>>> developErrorAngularVelocity
}

static void c8_b_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance, const
  mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[3])
{
<<<<<<< HEAD
  real_T c8_dv1[9];
  int32_T c8_i36;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c8_i36 = 0; c8_i36 < 9; c8_i36++) {
    c8_y[c8_i36] = c8_dv1[c8_i36];
=======
  real_T c8_dv1[3];
  int32_T c8_i32;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_i32 = 0; c8_i32 < 3; c8_i32++) {
    c8_y[c8_i32] = c8_dv1[c8_i32];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
<<<<<<< HEAD
  const mxArray *c8_eRhat;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[9];
  int32_T c8_i37;
  int32_T c8_i38;
  int32_T c8_i39;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_eRhat = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_eRhat), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_eRhat);
  c8_i37 = 0;
  for (c8_i38 = 0; c8_i38 < 3; c8_i38++) {
    for (c8_i39 = 0; c8_i39 < 3; c8_i39++) {
      (*(real_T (*)[9])c8_outData)[c8_i39 + c8_i37] = c8_y[c8_i39 + c8_i37];
    }

    c8_i37 += 3;
=======
  const mxArray *c8_eR;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[3];
  int32_T c8_i33;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_eR = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_eR), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_eR);
  for (c8_i33 = 0; c8_i33 < 3; c8_i33++) {
    (*(real_T (*)[3])c8_outData)[c8_i33] = c8_y[c8_i33];
>>>>>>> developErrorAngularVelocity
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
<<<<<<< HEAD
=======
  int32_T c8_i34;
  int32_T c8_i35;
  int32_T c8_i36;
  real_T c8_b_inData[9];
  int32_T c8_i37;
  int32_T c8_i38;
  int32_T c8_i39;
  real_T c8_u[9];
  const mxArray *c8_y = NULL;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i34 = 0;
  for (c8_i35 = 0; c8_i35 < 3; c8_i35++) {
    for (c8_i36 = 0; c8_i36 < 3; c8_i36++) {
      c8_b_inData[c8_i36 + c8_i34] = (*(real_T (*)[9])c8_inData)[c8_i36 + c8_i34];
    }

    c8_i34 += 3;
  }

  c8_i37 = 0;
  for (c8_i38 = 0; c8_i38 < 3; c8_i38++) {
    for (c8_i39 = 0; c8_i39 < 3; c8_i39++) {
      c8_u[c8_i39 + c8_i37] = c8_b_inData[c8_i39 + c8_i37];
    }

    c8_i37 += 3;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
>>>>>>> developErrorAngularVelocity
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static void c8_d_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance, const
  mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[9])
{
  real_T c8_dv2[9];
  int32_T c8_i40;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c8_i40 = 0; c8_i40 < 9; c8_i40++) {
    c8_y[c8_i40] = c8_dv2[c8_i40];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_eRhat;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[9];
  int32_T c8_i41;
  int32_T c8_i42;
  int32_T c8_i43;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_eRhat = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_eRhat), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_eRhat);
  c8_i41 = 0;
  for (c8_i42 = 0; c8_i42 < 3; c8_i42++) {
    for (c8_i43 = 0; c8_i43 < 3; c8_i43++) {
      (*(real_T (*)[9])c8_outData)[c8_i43 + c8_i41] = c8_y[c8_i43 + c8_i41];
    }

    c8_i41 += 3;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c8_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  const mxArray *c8_rhs1 = NULL;
  const mxArray *c8_lhs1 = NULL;
  const mxArray *c8_rhs2 = NULL;
  const mxArray *c8_lhs2 = NULL;
  const mxArray *c8_rhs3 = NULL;
  const mxArray *c8_lhs3 = NULL;
  const mxArray *c8_rhs4 = NULL;
  const mxArray *c8_lhs4 = NULL;
  const mxArray *c8_rhs5 = NULL;
  const mxArray *c8_lhs5 = NULL;
  const mxArray *c8_rhs6 = NULL;
  const mxArray *c8_lhs6 = NULL;
  const mxArray *c8_rhs7 = NULL;
  const mxArray *c8_lhs7 = NULL;
  const mxArray *c8_rhs8 = NULL;
  const mxArray *c8_lhs8 = NULL;
  const mxArray *c8_rhs9 = NULL;
  const mxArray *c8_lhs9 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c8_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c8_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c8_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_xgemm"), "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c8_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c8_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c8_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c8_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c8_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c8_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs9), "lhs", "lhs", 9);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
  sf_mex_destroy(&c8_rhs1);
  sf_mex_destroy(&c8_lhs1);
  sf_mex_destroy(&c8_rhs2);
  sf_mex_destroy(&c8_lhs2);
  sf_mex_destroy(&c8_rhs3);
  sf_mex_destroy(&c8_lhs3);
  sf_mex_destroy(&c8_rhs4);
  sf_mex_destroy(&c8_lhs4);
  sf_mex_destroy(&c8_rhs5);
  sf_mex_destroy(&c8_lhs5);
  sf_mex_destroy(&c8_rhs6);
  sf_mex_destroy(&c8_lhs6);
  sf_mex_destroy(&c8_rhs7);
  sf_mex_destroy(&c8_lhs7);
  sf_mex_destroy(&c8_rhs8);
  sf_mex_destroy(&c8_lhs8);
  sf_mex_destroy(&c8_rhs9);
  sf_mex_destroy(&c8_lhs9);
}

static const mxArray *c8_emlrt_marshallOut(char * c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_u)), FALSE);
  return c8_y;
}

static const mxArray *c8_b_emlrt_marshallOut(uint32_T c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c8_y;
}

static void c8_eml_scalar_eg(SFc8_QRsimInstanceStruct *chartInstance)
{
}

<<<<<<< HEAD
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
=======
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
>>>>>>> developErrorAngularVelocity
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_e_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
<<<<<<< HEAD
  int32_T c8_i40;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i40, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i40;
=======
  int32_T c8_i44;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i44, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i44;
>>>>>>> developErrorAngularVelocity
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_f_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_QRsim, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_is_active_c8_QRsim),
    &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_QRsim);
  return c8_y;
}

static uint8_T c8_g_emlrt_marshallIn(SFc8_QRsimInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_QRsimInstanceStruct *chartInstance)
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

void sf_c8_QRsim_get_check_sum(mxArray *plhs[])
{
<<<<<<< HEAD
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1106642733U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2406439138U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1307378627U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(497198902U);
=======
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4068905142U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3735649276U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3409327905U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3537632909U);
>>>>>>> developErrorAngularVelocity
}

mxArray *sf_c8_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("ToVYVlH9MCPFjCBpDNpGy");
=======
    mxArray *mxChecksum = mxCreateString("Yy0W3THrOD9uS9dWolN2dC");
>>>>>>> developErrorAngularVelocity
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray *sf_c8_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
<<<<<<< HEAD
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"eRhat\",},{M[8],M[0],T\"is_active_c8_QRsim\",}}"
=======
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"eR\",},{M[8],M[0],T\"is_active_c8_QRsim\",}}"
>>>>>>> developErrorAngularVelocity
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc8_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           8,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rdes");
<<<<<<< HEAD
          _SFD_SET_DATA_PROPS(2,2,0,1,"eRhat");
=======
          _SFD_SET_DATA_PROPS(2,2,0,1,"eR");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,83);
=======
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,119);
>>>>>>> developErrorAngularVelocity

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
<<<<<<< HEAD
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
=======
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
>>>>>>> developErrorAngularVelocity
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
<<<<<<< HEAD
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
=======
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
>>>>>>> developErrorAngularVelocity
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          real_T (*c8_R)[9];
          real_T (*c8_Rdes)[9];
<<<<<<< HEAD
          real_T (*c8_eRhat)[9];
          c8_eRhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
=======
          real_T (*c8_eR)[3];
          c8_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
>>>>>>> developErrorAngularVelocity
          c8_Rdes = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c8_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c8_Rdes);
<<<<<<< HEAD
          _SFD_SET_DATA_VALUE_PTR(2U, *c8_eRhat);
=======
          _SFD_SET_DATA_VALUE_PTR(2U, *c8_eR);
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
  return "sqjYtjXr1EoFOzitj8rqEG";
=======
  return "A0vZR1HzgANzIAOSkik6cD";
>>>>>>> developErrorAngularVelocity
}

static void sf_opaque_initialize_c8_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_QRsimInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_QRsim(void *chartInstanceVar)
{
  enable_c8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_QRsim(void *chartInstanceVar)
{
  disable_c8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_QRsim(void *chartInstanceVar)
{
  sf_c8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_QRsim((SFc8_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c8_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_QRsim((SFc8_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_QRsim(S);
}

static void sf_opaque_set_sim_state_c8_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_QRsim(S, st);
}

static void sf_opaque_terminate_c8_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_QRsim((SFc8_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_QRsim((SFc8_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
<<<<<<< HEAD
  ssSetChecksum0(S,(1484493681U));
  ssSetChecksum1(S,(2544931212U));
  ssSetChecksum2(S,(737766880U));
  ssSetChecksum3(S,(2224359053U));
=======
  ssSetChecksum0(S,(3764185951U));
  ssSetChecksum1(S,(1785435689U));
  ssSetChecksum2(S,(478338766U));
  ssSetChecksum3(S,(866102973U));
>>>>>>> developErrorAngularVelocity
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_QRsim(SimStruct *S)
{
  SFc8_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc8_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc8_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_QRsim;
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

void c8_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
