/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c40_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c40_debug_family_names[7] = { "eRhat", "nargin", "nargout",
  "Rc", "R", "eR", "PsiR" };

/* Function Declarations */
static void initialize_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c40_QRLsim(SFc40_QRLsimInstanceStruct
  *chartInstance);
static void enable_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void disable_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void c40_update_debugger_state_c40_QRLsim(SFc40_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c40_QRLsim(SFc40_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_st);
static void finalize_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void sf_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void c40_chartstep_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c40_machineNumber, uint32_T
  c40_chartNumber);
static const mxArray *c40_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static real_T c40_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_PsiR, const char_T *c40_identifier);
static real_T c40_b_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId);
static void c40_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static const mxArray *c40_b_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static void c40_c_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_eR, const char_T *c40_identifier, real_T c40_y[3]);
static void c40_d_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId, real_T c40_y[3]);
static void c40_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static const mxArray *c40_c_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static void c40_e_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId, real_T c40_y[9]);
static void c40_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static void c40_info_helper(const mxArray **c40_info);
static const mxArray *c40_emlrt_marshallOut(char * c40_u);
static const mxArray *c40_b_emlrt_marshallOut(uint32_T c40_u);
static void c40_eml_scalar_eg(SFc40_QRLsimInstanceStruct *chartInstance);
static const mxArray *c40_d_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static int32_T c40_f_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId);
static void c40_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static uint8_T c40_g_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_b_is_active_c40_QRLsim, const char_T *c40_identifier);
static uint8_T c40_h_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId);
static void init_dsm_address_info(SFc40_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c40_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c40_is_active_c40_QRLsim = 0U;
}

static void initialize_params_c40_QRLsim(SFc40_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c40_update_debugger_state_c40_QRLsim(SFc40_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c40_QRLsim(SFc40_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c40_st;
  const mxArray *c40_y = NULL;
  real_T c40_hoistedGlobal;
  real_T c40_u;
  const mxArray *c40_b_y = NULL;
  int32_T c40_i0;
  real_T c40_b_u[3];
  const mxArray *c40_c_y = NULL;
  uint8_T c40_b_hoistedGlobal;
  uint8_T c40_c_u;
  const mxArray *c40_d_y = NULL;
  real_T *c40_PsiR;
  real_T (*c40_eR)[3];
  c40_PsiR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c40_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c40_st = NULL;
  c40_st = NULL;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_createcellarray(3), FALSE);
  c40_hoistedGlobal = *c40_PsiR;
  c40_u = c40_hoistedGlobal;
  c40_b_y = NULL;
  sf_mex_assign(&c40_b_y, sf_mex_create("y", &c40_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c40_y, 0, c40_b_y);
  for (c40_i0 = 0; c40_i0 < 3; c40_i0++) {
    c40_b_u[c40_i0] = (*c40_eR)[c40_i0];
  }

  c40_c_y = NULL;
  sf_mex_assign(&c40_c_y, sf_mex_create("y", c40_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c40_y, 1, c40_c_y);
  c40_b_hoistedGlobal = chartInstance->c40_is_active_c40_QRLsim;
  c40_c_u = c40_b_hoistedGlobal;
  c40_d_y = NULL;
  sf_mex_assign(&c40_d_y, sf_mex_create("y", &c40_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c40_y, 2, c40_d_y);
  sf_mex_assign(&c40_st, c40_y, FALSE);
  return c40_st;
}

static void set_sim_state_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_st)
{
  const mxArray *c40_u;
  real_T c40_dv0[3];
  int32_T c40_i1;
  real_T *c40_PsiR;
  real_T (*c40_eR)[3];
  c40_PsiR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c40_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c40_doneDoubleBufferReInit = TRUE;
  c40_u = sf_mex_dup(c40_st);
  *c40_PsiR = c40_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c40_u, 0)), "PsiR");
  c40_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c40_u, 1)),
    "eR", c40_dv0);
  for (c40_i1 = 0; c40_i1 < 3; c40_i1++) {
    (*c40_eR)[c40_i1] = c40_dv0[c40_i1];
  }

  chartInstance->c40_is_active_c40_QRLsim = c40_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c40_u, 2)), "is_active_c40_QRLsim");
  sf_mex_destroy(&c40_u);
  c40_update_debugger_state_c40_QRLsim(chartInstance);
  sf_mex_destroy(&c40_st);
}

static void finalize_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
  int32_T c40_i2;
  int32_T c40_i3;
  int32_T c40_i4;
  real_T *c40_PsiR;
  real_T (*c40_eR)[3];
  real_T (*c40_R)[9];
  real_T (*c40_Rc)[9];
  c40_PsiR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c40_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c40_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c40_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c40_sfEvent);
  for (c40_i2 = 0; c40_i2 < 9; c40_i2++) {
    _SFD_DATA_RANGE_CHECK((*c40_Rc)[c40_i2], 0U);
  }

  for (c40_i3 = 0; c40_i3 < 9; c40_i3++) {
    _SFD_DATA_RANGE_CHECK((*c40_R)[c40_i3], 1U);
  }

  for (c40_i4 = 0; c40_i4 < 3; c40_i4++) {
    _SFD_DATA_RANGE_CHECK((*c40_eR)[c40_i4], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c40_PsiR, 3U);
  chartInstance->c40_sfEvent = CALL_EVENT;
  c40_chartstep_c40_QRLsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c40_chartstep_c40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
  int32_T c40_i5;
  real_T c40_Rc[9];
  int32_T c40_i6;
  real_T c40_R[9];
  uint32_T c40_debug_family_var_map[7];
  real_T c40_eRhat[9];
  real_T c40_nargin = 2.0;
  real_T c40_nargout = 2.0;
  real_T c40_eR[3];
  real_T c40_PsiR;
  int32_T c40_i7;
  int32_T c40_i8;
  int32_T c40_i9;
  int32_T c40_i10;
  real_T c40_a[9];
  int32_T c40_i11;
  real_T c40_b[9];
  int32_T c40_i12;
  int32_T c40_i13;
  int32_T c40_i14;
  real_T c40_y[9];
  int32_T c40_i15;
  int32_T c40_i16;
  int32_T c40_i17;
  int32_T c40_i18;
  int32_T c40_i19;
  int32_T c40_i20;
  int32_T c40_i21;
  int32_T c40_i22;
  int32_T c40_i23;
  int32_T c40_i24;
  real_T c40_b_y[9];
  int32_T c40_i25;
  int32_T c40_i26;
  int32_T c40_i27;
  real_T c40_b_b[3];
  int32_T c40_i28;
  int32_T c40_i29;
  int32_T c40_k;
  int32_T c40_b_k;
  int32_T c40_i30;
  int32_T c40_i31;
  int32_T c40_i32;
  int32_T c40_i33;
  int32_T c40_i34;
  int32_T c40_i35;
  int32_T c40_i36;
  int32_T c40_i37;
  int32_T c40_i38;
  int32_T c40_i39;
  int32_T c40_i40;
  real_T c40_t;
  int32_T c40_c_k;
  real_T c40_d_k;
  real_T c40_c_b;
  int32_T c40_i41;
  real_T *c40_b_PsiR;
  real_T (*c40_b_eR)[3];
  real_T (*c40_b_R)[9];
  real_T (*c40_b_Rc)[9];
  c40_b_PsiR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c40_b_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c40_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c40_b_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c40_sfEvent);
  for (c40_i5 = 0; c40_i5 < 9; c40_i5++) {
    c40_Rc[c40_i5] = (*c40_b_Rc)[c40_i5];
  }

  for (c40_i6 = 0; c40_i6 < 9; c40_i6++) {
    c40_R[c40_i6] = (*c40_b_R)[c40_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c40_debug_family_names,
    c40_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c40_eRhat, 0U, c40_c_sf_marshallOut,
    c40_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c40_nargin, 1U, c40_sf_marshallOut,
    c40_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c40_nargout, 2U, c40_sf_marshallOut,
    c40_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c40_Rc, 3U, c40_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c40_R, 4U, c40_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c40_eR, 5U, c40_b_sf_marshallOut,
    c40_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c40_PsiR, 6U, c40_sf_marshallOut,
    c40_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 3);
  c40_i7 = 0;
  for (c40_i8 = 0; c40_i8 < 3; c40_i8++) {
    c40_i9 = 0;
    for (c40_i10 = 0; c40_i10 < 3; c40_i10++) {
      c40_a[c40_i10 + c40_i7] = c40_Rc[c40_i9 + c40_i8];
      c40_i9 += 3;
    }

    c40_i7 += 3;
  }

  for (c40_i11 = 0; c40_i11 < 9; c40_i11++) {
    c40_b[c40_i11] = c40_R[c40_i11];
  }

  c40_eml_scalar_eg(chartInstance);
  c40_eml_scalar_eg(chartInstance);
  for (c40_i12 = 0; c40_i12 < 3; c40_i12++) {
    c40_i13 = 0;
    for (c40_i14 = 0; c40_i14 < 3; c40_i14++) {
      c40_y[c40_i13 + c40_i12] = 0.0;
      c40_i15 = 0;
      for (c40_i16 = 0; c40_i16 < 3; c40_i16++) {
        c40_y[c40_i13 + c40_i12] += c40_a[c40_i15 + c40_i12] * c40_b[c40_i16 +
          c40_i13];
        c40_i15 += 3;
      }

      c40_i13 += 3;
    }
  }

  c40_i17 = 0;
  for (c40_i18 = 0; c40_i18 < 3; c40_i18++) {
    c40_i19 = 0;
    for (c40_i20 = 0; c40_i20 < 3; c40_i20++) {
      c40_a[c40_i20 + c40_i17] = c40_R[c40_i19 + c40_i18];
      c40_i19 += 3;
    }

    c40_i17 += 3;
  }

  for (c40_i21 = 0; c40_i21 < 9; c40_i21++) {
    c40_b[c40_i21] = c40_Rc[c40_i21];
  }

  c40_eml_scalar_eg(chartInstance);
  c40_eml_scalar_eg(chartInstance);
  for (c40_i22 = 0; c40_i22 < 3; c40_i22++) {
    c40_i23 = 0;
    for (c40_i24 = 0; c40_i24 < 3; c40_i24++) {
      c40_b_y[c40_i23 + c40_i22] = 0.0;
      c40_i25 = 0;
      for (c40_i26 = 0; c40_i26 < 3; c40_i26++) {
        c40_b_y[c40_i23 + c40_i22] += c40_a[c40_i25 + c40_i22] * c40_b[c40_i26 +
          c40_i23];
        c40_i25 += 3;
      }

      c40_i23 += 3;
    }
  }

  for (c40_i27 = 0; c40_i27 < 9; c40_i27++) {
    c40_eRhat[c40_i27] = c40_y[c40_i27] - c40_b_y[c40_i27];
  }

  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 4);
  c40_b_b[0] = c40_eRhat[5];
  c40_b_b[1] = -c40_eRhat[2];
  c40_b_b[2] = c40_eRhat[1];
  for (c40_i28 = 0; c40_i28 < 3; c40_i28++) {
    c40_eR[c40_i28] = 0.5 * c40_b_b[c40_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 5);
  for (c40_i29 = 0; c40_i29 < 9; c40_i29++) {
    c40_b_y[c40_i29] = 0.0;
  }

  for (c40_k = 1; c40_k < 4; c40_k++) {
    c40_b_k = c40_k;
    c40_b_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c40_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
               "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c40_b_k), 1, 3, 2, 0)
              - 1)) - 1] = 1.0;
  }

  c40_i30 = 0;
  for (c40_i31 = 0; c40_i31 < 3; c40_i31++) {
    c40_i32 = 0;
    for (c40_i33 = 0; c40_i33 < 3; c40_i33++) {
      c40_a[c40_i33 + c40_i30] = c40_Rc[c40_i32 + c40_i31];
      c40_i32 += 3;
    }

    c40_i30 += 3;
  }

  for (c40_i34 = 0; c40_i34 < 9; c40_i34++) {
    c40_b[c40_i34] = c40_R[c40_i34];
  }

  c40_eml_scalar_eg(chartInstance);
  c40_eml_scalar_eg(chartInstance);
  for (c40_i35 = 0; c40_i35 < 3; c40_i35++) {
    c40_i36 = 0;
    for (c40_i37 = 0; c40_i37 < 3; c40_i37++) {
      c40_y[c40_i36 + c40_i35] = 0.0;
      c40_i38 = 0;
      for (c40_i39 = 0; c40_i39 < 3; c40_i39++) {
        c40_y[c40_i36 + c40_i35] += c40_a[c40_i38 + c40_i35] * c40_b[c40_i39 +
          c40_i36];
        c40_i38 += 3;
      }

      c40_i36 += 3;
    }
  }

  for (c40_i40 = 0; c40_i40 < 9; c40_i40++) {
    c40_b_y[c40_i40] -= c40_y[c40_i40];
  }

  c40_t = 0.0;
  for (c40_c_k = 0; c40_c_k < 3; c40_c_k++) {
    c40_d_k = 1.0 + (real_T)c40_c_k;
    c40_t += c40_b_y[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c40_d_k), 1, 3, 1, 0) + 3 * ((int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c40_d_k),
      1, 3, 2, 0) - 1)) - 1];
  }

  c40_c_b = c40_t;
  c40_PsiR = 0.5 * c40_c_b;
  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c40_i41 = 0; c40_i41 < 3; c40_i41++) {
    (*c40_b_eR)[c40_i41] = c40_eR[c40_i41];
  }

  *c40_b_PsiR = c40_PsiR;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c40_sfEvent);
}

static void initSimStructsc40_QRLsim(SFc40_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c40_machineNumber, uint32_T
  c40_chartNumber)
{
}

static const mxArray *c40_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  real_T c40_u;
  const mxArray *c40_y = NULL;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  c40_u = *(real_T *)c40_inData;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", &c40_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, FALSE);
  return c40_mxArrayOutData;
}

static real_T c40_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_PsiR, const char_T *c40_identifier)
{
  real_T c40_y;
  emlrtMsgIdentifier c40_thisId;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_PsiR),
    &c40_thisId);
  sf_mex_destroy(&c40_PsiR);
  return c40_y;
}

static real_T c40_b_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId)
{
  real_T c40_y;
  real_T c40_d0;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), &c40_d0, 1, 0, 0U, 0, 0U, 0);
  c40_y = c40_d0;
  sf_mex_destroy(&c40_u);
  return c40_y;
}

static void c40_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_PsiR;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  real_T c40_y;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_PsiR = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_PsiR),
    &c40_thisId);
  sf_mex_destroy(&c40_PsiR);
  *(real_T *)c40_outData = c40_y;
  sf_mex_destroy(&c40_mxArrayInData);
}

static const mxArray *c40_b_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  int32_T c40_i42;
  real_T c40_b_inData[3];
  int32_T c40_i43;
  real_T c40_u[3];
  const mxArray *c40_y = NULL;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  for (c40_i42 = 0; c40_i42 < 3; c40_i42++) {
    c40_b_inData[c40_i42] = (*(real_T (*)[3])c40_inData)[c40_i42];
  }

  for (c40_i43 = 0; c40_i43 < 3; c40_i43++) {
    c40_u[c40_i43] = c40_b_inData[c40_i43];
  }

  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", c40_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, FALSE);
  return c40_mxArrayOutData;
}

static void c40_c_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_eR, const char_T *c40_identifier, real_T c40_y[3])
{
  emlrtMsgIdentifier c40_thisId;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_eR), &c40_thisId, c40_y);
  sf_mex_destroy(&c40_eR);
}

static void c40_d_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId, real_T c40_y[3])
{
  real_T c40_dv1[3];
  int32_T c40_i44;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), c40_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c40_i44 = 0; c40_i44 < 3; c40_i44++) {
    c40_y[c40_i44] = c40_dv1[c40_i44];
  }

  sf_mex_destroy(&c40_u);
}

static void c40_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_eR;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  real_T c40_y[3];
  int32_T c40_i45;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_eR = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_eR), &c40_thisId, c40_y);
  sf_mex_destroy(&c40_eR);
  for (c40_i45 = 0; c40_i45 < 3; c40_i45++) {
    (*(real_T (*)[3])c40_outData)[c40_i45] = c40_y[c40_i45];
  }

  sf_mex_destroy(&c40_mxArrayInData);
}

static const mxArray *c40_c_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  int32_T c40_i46;
  int32_T c40_i47;
  int32_T c40_i48;
  real_T c40_b_inData[9];
  int32_T c40_i49;
  int32_T c40_i50;
  int32_T c40_i51;
  real_T c40_u[9];
  const mxArray *c40_y = NULL;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  c40_i46 = 0;
  for (c40_i47 = 0; c40_i47 < 3; c40_i47++) {
    for (c40_i48 = 0; c40_i48 < 3; c40_i48++) {
      c40_b_inData[c40_i48 + c40_i46] = (*(real_T (*)[9])c40_inData)[c40_i48 +
        c40_i46];
    }

    c40_i46 += 3;
  }

  c40_i49 = 0;
  for (c40_i50 = 0; c40_i50 < 3; c40_i50++) {
    for (c40_i51 = 0; c40_i51 < 3; c40_i51++) {
      c40_u[c40_i51 + c40_i49] = c40_b_inData[c40_i51 + c40_i49];
    }

    c40_i49 += 3;
  }

  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", c40_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, FALSE);
  return c40_mxArrayOutData;
}

static void c40_e_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId, real_T c40_y[9])
{
  real_T c40_dv2[9];
  int32_T c40_i52;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), c40_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c40_i52 = 0; c40_i52 < 9; c40_i52++) {
    c40_y[c40_i52] = c40_dv2[c40_i52];
  }

  sf_mex_destroy(&c40_u);
}

static void c40_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_eRhat;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  real_T c40_y[9];
  int32_T c40_i53;
  int32_T c40_i54;
  int32_T c40_i55;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_eRhat = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_eRhat), &c40_thisId,
    c40_y);
  sf_mex_destroy(&c40_eRhat);
  c40_i53 = 0;
  for (c40_i54 = 0; c40_i54 < 3; c40_i54++) {
    for (c40_i55 = 0; c40_i55 < 3; c40_i55++) {
      (*(real_T (*)[9])c40_outData)[c40_i55 + c40_i53] = c40_y[c40_i55 + c40_i53];
    }

    c40_i53 += 3;
  }

  sf_mex_destroy(&c40_mxArrayInData);
}

const mxArray *sf_c40_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c40_nameCaptureInfo = NULL;
  c40_nameCaptureInfo = NULL;
  sf_mex_assign(&c40_nameCaptureInfo, sf_mex_createstruct("structure", 2, 29, 1),
                FALSE);
  c40_info_helper(&c40_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c40_nameCaptureInfo);
  return c40_nameCaptureInfo;
}

static void c40_info_helper(const mxArray **c40_info)
{
  const mxArray *c40_rhs0 = NULL;
  const mxArray *c40_lhs0 = NULL;
  const mxArray *c40_rhs1 = NULL;
  const mxArray *c40_lhs1 = NULL;
  const mxArray *c40_rhs2 = NULL;
  const mxArray *c40_lhs2 = NULL;
  const mxArray *c40_rhs3 = NULL;
  const mxArray *c40_lhs3 = NULL;
  const mxArray *c40_rhs4 = NULL;
  const mxArray *c40_lhs4 = NULL;
  const mxArray *c40_rhs5 = NULL;
  const mxArray *c40_lhs5 = NULL;
  const mxArray *c40_rhs6 = NULL;
  const mxArray *c40_lhs6 = NULL;
  const mxArray *c40_rhs7 = NULL;
  const mxArray *c40_lhs7 = NULL;
  const mxArray *c40_rhs8 = NULL;
  const mxArray *c40_lhs8 = NULL;
  const mxArray *c40_rhs9 = NULL;
  const mxArray *c40_lhs9 = NULL;
  const mxArray *c40_rhs10 = NULL;
  const mxArray *c40_lhs10 = NULL;
  const mxArray *c40_rhs11 = NULL;
  const mxArray *c40_lhs11 = NULL;
  const mxArray *c40_rhs12 = NULL;
  const mxArray *c40_lhs12 = NULL;
  const mxArray *c40_rhs13 = NULL;
  const mxArray *c40_lhs13 = NULL;
  const mxArray *c40_rhs14 = NULL;
  const mxArray *c40_lhs14 = NULL;
  const mxArray *c40_rhs15 = NULL;
  const mxArray *c40_lhs15 = NULL;
  const mxArray *c40_rhs16 = NULL;
  const mxArray *c40_lhs16 = NULL;
  const mxArray *c40_rhs17 = NULL;
  const mxArray *c40_lhs17 = NULL;
  const mxArray *c40_rhs18 = NULL;
  const mxArray *c40_lhs18 = NULL;
  const mxArray *c40_rhs19 = NULL;
  const mxArray *c40_lhs19 = NULL;
  const mxArray *c40_rhs20 = NULL;
  const mxArray *c40_lhs20 = NULL;
  const mxArray *c40_rhs21 = NULL;
  const mxArray *c40_lhs21 = NULL;
  const mxArray *c40_rhs22 = NULL;
  const mxArray *c40_lhs22 = NULL;
  const mxArray *c40_rhs23 = NULL;
  const mxArray *c40_lhs23 = NULL;
  const mxArray *c40_rhs24 = NULL;
  const mxArray *c40_lhs24 = NULL;
  const mxArray *c40_rhs25 = NULL;
  const mxArray *c40_lhs25 = NULL;
  const mxArray *c40_rhs26 = NULL;
  const mxArray *c40_lhs26 = NULL;
  const mxArray *c40_rhs27 = NULL;
  const mxArray *c40_lhs27 = NULL;
  const mxArray *c40_rhs28 = NULL;
  const mxArray *c40_lhs28 = NULL;
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c40_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c40_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c40_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c40_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c40_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c40_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c40_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c40_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c40_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c40_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eye"), "name", "name", 10);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1368183030U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c40_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 11);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1368183030U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c40_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c40_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 13);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("isinf"), "name", "name", 13);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c40_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c40_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 15);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 15);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c40_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 16);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("intmax"), "name", "name", 16);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c40_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 17);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("intmin"), "name", "name", 17);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c40_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 18);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 18);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1326728322U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c40_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 19);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c40_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 20);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c40_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size"),
                  "context", "context", 21);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("mtimes"), "name", "name", 21);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c40_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c40_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c40_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 24);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c40_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 25);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("intmax"), "name", "name", 25);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c40_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(""), "context", "context", 26);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("trace"), "name", "name", 26);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/trace.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c40_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/trace.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c40_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/trace.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 28);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c40_info, c40_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c40_info, c40_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c40_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c40_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c40_info, sf_mex_duplicatearraysafe(&c40_lhs28), "lhs", "lhs",
                  28);
  sf_mex_destroy(&c40_rhs0);
  sf_mex_destroy(&c40_lhs0);
  sf_mex_destroy(&c40_rhs1);
  sf_mex_destroy(&c40_lhs1);
  sf_mex_destroy(&c40_rhs2);
  sf_mex_destroy(&c40_lhs2);
  sf_mex_destroy(&c40_rhs3);
  sf_mex_destroy(&c40_lhs3);
  sf_mex_destroy(&c40_rhs4);
  sf_mex_destroy(&c40_lhs4);
  sf_mex_destroy(&c40_rhs5);
  sf_mex_destroy(&c40_lhs5);
  sf_mex_destroy(&c40_rhs6);
  sf_mex_destroy(&c40_lhs6);
  sf_mex_destroy(&c40_rhs7);
  sf_mex_destroy(&c40_lhs7);
  sf_mex_destroy(&c40_rhs8);
  sf_mex_destroy(&c40_lhs8);
  sf_mex_destroy(&c40_rhs9);
  sf_mex_destroy(&c40_lhs9);
  sf_mex_destroy(&c40_rhs10);
  sf_mex_destroy(&c40_lhs10);
  sf_mex_destroy(&c40_rhs11);
  sf_mex_destroy(&c40_lhs11);
  sf_mex_destroy(&c40_rhs12);
  sf_mex_destroy(&c40_lhs12);
  sf_mex_destroy(&c40_rhs13);
  sf_mex_destroy(&c40_lhs13);
  sf_mex_destroy(&c40_rhs14);
  sf_mex_destroy(&c40_lhs14);
  sf_mex_destroy(&c40_rhs15);
  sf_mex_destroy(&c40_lhs15);
  sf_mex_destroy(&c40_rhs16);
  sf_mex_destroy(&c40_lhs16);
  sf_mex_destroy(&c40_rhs17);
  sf_mex_destroy(&c40_lhs17);
  sf_mex_destroy(&c40_rhs18);
  sf_mex_destroy(&c40_lhs18);
  sf_mex_destroy(&c40_rhs19);
  sf_mex_destroy(&c40_lhs19);
  sf_mex_destroy(&c40_rhs20);
  sf_mex_destroy(&c40_lhs20);
  sf_mex_destroy(&c40_rhs21);
  sf_mex_destroy(&c40_lhs21);
  sf_mex_destroy(&c40_rhs22);
  sf_mex_destroy(&c40_lhs22);
  sf_mex_destroy(&c40_rhs23);
  sf_mex_destroy(&c40_lhs23);
  sf_mex_destroy(&c40_rhs24);
  sf_mex_destroy(&c40_lhs24);
  sf_mex_destroy(&c40_rhs25);
  sf_mex_destroy(&c40_lhs25);
  sf_mex_destroy(&c40_rhs26);
  sf_mex_destroy(&c40_lhs26);
  sf_mex_destroy(&c40_rhs27);
  sf_mex_destroy(&c40_lhs27);
  sf_mex_destroy(&c40_rhs28);
  sf_mex_destroy(&c40_lhs28);
}

static const mxArray *c40_emlrt_marshallOut(char * c40_u)
{
  const mxArray *c40_y = NULL;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", c40_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c40_u)), FALSE);
  return c40_y;
}

static const mxArray *c40_b_emlrt_marshallOut(uint32_T c40_u)
{
  const mxArray *c40_y = NULL;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", &c40_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c40_y;
}

static void c40_eml_scalar_eg(SFc40_QRLsimInstanceStruct *chartInstance)
{
}

static const mxArray *c40_d_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  int32_T c40_u;
  const mxArray *c40_y = NULL;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  c40_u = *(int32_T *)c40_inData;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", &c40_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, FALSE);
  return c40_mxArrayOutData;
}

static int32_T c40_f_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId)
{
  int32_T c40_y;
  int32_T c40_i56;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), &c40_i56, 1, 6, 0U, 0, 0U, 0);
  c40_y = c40_i56;
  sf_mex_destroy(&c40_u);
  return c40_y;
}

static void c40_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_b_sfEvent;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  int32_T c40_y;
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)chartInstanceVoid;
  c40_b_sfEvent = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_b_sfEvent),
    &c40_thisId);
  sf_mex_destroy(&c40_b_sfEvent);
  *(int32_T *)c40_outData = c40_y;
  sf_mex_destroy(&c40_mxArrayInData);
}

static uint8_T c40_g_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_b_is_active_c40_QRLsim, const char_T *c40_identifier)
{
  uint8_T c40_y;
  emlrtMsgIdentifier c40_thisId;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c40_b_is_active_c40_QRLsim), &c40_thisId);
  sf_mex_destroy(&c40_b_is_active_c40_QRLsim);
  return c40_y;
}

static uint8_T c40_h_emlrt_marshallIn(SFc40_QRLsimInstanceStruct *chartInstance,
  const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId)
{
  uint8_T c40_y;
  uint8_T c40_u0;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), &c40_u0, 1, 3, 0U, 0, 0U, 0);
  c40_y = c40_u0;
  sf_mex_destroy(&c40_u);
  return c40_y;
}

static void init_dsm_address_info(SFc40_QRLsimInstanceStruct *chartInstance)
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

void sf_c40_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(839078700U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2008260008U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4171795672U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4244444137U);
}

mxArray *sf_c40_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lMe92e3eI2YEJAjOyG4wFC");
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
      pr[0] = (double)(1);
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

mxArray *sf_c40_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c40_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c40_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"PsiR\",},{M[1],M[9],T\"eR\",},{M[8],M[0],T\"is_active_c40_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c40_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc40_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc40_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           40,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Rc");
          _SFD_SET_DATA_PROPS(1,1,1,0,"R");
          _SFD_SET_DATA_PROPS(2,2,0,1,"eR");
          _SFD_SET_DATA_PROPS(3,2,0,1,"PsiR");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,274);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_b_sf_marshallOut,(MexInFcnForType)
            c40_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c40_sf_marshallOut,(MexInFcnForType)c40_sf_marshallIn);

        {
          real_T *c40_PsiR;
          real_T (*c40_Rc)[9];
          real_T (*c40_R)[9];
          real_T (*c40_eR)[3];
          c40_PsiR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c40_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c40_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c40_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c40_Rc);
          _SFD_SET_DATA_VALUE_PTR(1U, *c40_R);
          _SFD_SET_DATA_VALUE_PTR(2U, *c40_eR);
          _SFD_SET_DATA_VALUE_PTR(3U, c40_PsiR);
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
  return "UegtduoJ3SloKaMtNSCjpF";
}

static void sf_opaque_initialize_c40_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc40_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c40_QRLsim(void *chartInstanceVar)
{
  enable_c40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c40_QRLsim(void *chartInstanceVar)
{
  disable_c40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c40_QRLsim(void *chartInstanceVar)
{
  sf_c40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c40_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c40_QRLsim((SFc40_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c40_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c40_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c40_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c40_QRLsim((SFc40_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c40_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c40_QRLsim(S);
}

static void sf_opaque_set_sim_state_c40_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c40_QRLsim(S, st);
}

static void sf_opaque_terminate_c40_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc40_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc40_QRLsim((SFc40_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c40_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c40_QRLsim((SFc40_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c40_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      40);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,40,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,40,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,40);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,40,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,40,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,40);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2862221152U));
  ssSetChecksum1(S,(1657608510U));
  ssSetChecksum2(S,(3893191543U));
  ssSetChecksum3(S,(1953894905U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c40_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c40_QRLsim(SimStruct *S)
{
  SFc40_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc40_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc40_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc40_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c40_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c40_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c40_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c40_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c40_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c40_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c40_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c40_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c40_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c40_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c40_QRLsim;
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

void c40_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c40_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c40_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c40_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c40_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
