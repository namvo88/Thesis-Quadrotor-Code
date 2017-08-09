/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c43_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c43_debug_family_names[9] = { "Omegachat", "dOmegachat",
  "nargin", "nargout", "Rc", "dRc", "ddRc", "Omegac", "dOmegac" };

/* Function Declarations */
static void initialize_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c43_QRLsim(SFc43_QRLsimInstanceStruct
  *chartInstance);
static void enable_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void disable_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void c43_update_debugger_state_c43_QRLsim(SFc43_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c43_QRLsim(SFc43_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_st);
static void finalize_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void sf_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void c43_chartstep_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber);
static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static void c43_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_dOmegac, const char_T *c43_identifier, real_T c43_y[3]);
static void c43_b_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[3]);
static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static real_T c43_c_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static void c43_d_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[9]);
static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static void c43_info_helper(const mxArray **c43_info);
static const mxArray *c43_emlrt_marshallOut(char * c43_u);
static const mxArray *c43_b_emlrt_marshallOut(uint32_T c43_u);
static void c43_eml_scalar_eg(SFc43_QRLsimInstanceStruct *chartInstance);
static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static int32_T c43_e_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static uint8_T c43_f_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_b_is_active_c43_QRLsim, const char_T *c43_identifier);
static uint8_T c43_g_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void init_dsm_address_info(SFc43_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c43_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c43_is_active_c43_QRLsim = 0U;
}

static void initialize_params_c43_QRLsim(SFc43_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c43_update_debugger_state_c43_QRLsim(SFc43_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c43_QRLsim(SFc43_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c43_st;
  const mxArray *c43_y = NULL;
  int32_T c43_i0;
  real_T c43_u[3];
  const mxArray *c43_b_y = NULL;
  int32_T c43_i1;
  real_T c43_b_u[3];
  const mxArray *c43_c_y = NULL;
  uint8_T c43_hoistedGlobal;
  uint8_T c43_c_u;
  const mxArray *c43_d_y = NULL;
  real_T (*c43_dOmegac)[3];
  real_T (*c43_Omegac)[3];
  c43_dOmegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_Omegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c43_st = NULL;
  c43_st = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_createcellarray(3), FALSE);
  for (c43_i0 = 0; c43_i0 < 3; c43_i0++) {
    c43_u[c43_i0] = (*c43_Omegac)[c43_i0];
  }

  c43_b_y = NULL;
  sf_mex_assign(&c43_b_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c43_y, 0, c43_b_y);
  for (c43_i1 = 0; c43_i1 < 3; c43_i1++) {
    c43_b_u[c43_i1] = (*c43_dOmegac)[c43_i1];
  }

  c43_c_y = NULL;
  sf_mex_assign(&c43_c_y, sf_mex_create("y", c43_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c43_y, 1, c43_c_y);
  c43_hoistedGlobal = chartInstance->c43_is_active_c43_QRLsim;
  c43_c_u = c43_hoistedGlobal;
  c43_d_y = NULL;
  sf_mex_assign(&c43_d_y, sf_mex_create("y", &c43_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c43_y, 2, c43_d_y);
  sf_mex_assign(&c43_st, c43_y, FALSE);
  return c43_st;
}

static void set_sim_state_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_st)
{
  const mxArray *c43_u;
  real_T c43_dv0[3];
  int32_T c43_i2;
  real_T c43_dv1[3];
  int32_T c43_i3;
  real_T (*c43_Omegac)[3];
  real_T (*c43_dOmegac)[3];
  c43_dOmegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_Omegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c43_doneDoubleBufferReInit = TRUE;
  c43_u = sf_mex_dup(c43_st);
  c43_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 0)),
                       "Omegac", c43_dv0);
  for (c43_i2 = 0; c43_i2 < 3; c43_i2++) {
    (*c43_Omegac)[c43_i2] = c43_dv0[c43_i2];
  }

  c43_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 1)),
                       "dOmegac", c43_dv1);
  for (c43_i3 = 0; c43_i3 < 3; c43_i3++) {
    (*c43_dOmegac)[c43_i3] = c43_dv1[c43_i3];
  }

  chartInstance->c43_is_active_c43_QRLsim = c43_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 2)), "is_active_c43_QRLsim");
  sf_mex_destroy(&c43_u);
  c43_update_debugger_state_c43_QRLsim(chartInstance);
  sf_mex_destroy(&c43_st);
}

static void finalize_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
  int32_T c43_i4;
  int32_T c43_i5;
  int32_T c43_i6;
  int32_T c43_i7;
  int32_T c43_i8;
  real_T (*c43_dOmegac)[3];
  real_T (*c43_ddRc)[9];
  real_T (*c43_Omegac)[3];
  real_T (*c43_dRc)[9];
  real_T (*c43_Rc)[9];
  c43_dOmegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_ddRc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c43_Omegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c43_dRc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c43_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c43_sfEvent);
  for (c43_i4 = 0; c43_i4 < 9; c43_i4++) {
    _SFD_DATA_RANGE_CHECK((*c43_Rc)[c43_i4], 0U);
  }

  for (c43_i5 = 0; c43_i5 < 9; c43_i5++) {
    _SFD_DATA_RANGE_CHECK((*c43_dRc)[c43_i5], 1U);
  }

  for (c43_i6 = 0; c43_i6 < 3; c43_i6++) {
    _SFD_DATA_RANGE_CHECK((*c43_Omegac)[c43_i6], 2U);
  }

  for (c43_i7 = 0; c43_i7 < 9; c43_i7++) {
    _SFD_DATA_RANGE_CHECK((*c43_ddRc)[c43_i7], 3U);
  }

  for (c43_i8 = 0; c43_i8 < 3; c43_i8++) {
    _SFD_DATA_RANGE_CHECK((*c43_dOmegac)[c43_i8], 4U);
  }

  chartInstance->c43_sfEvent = CALL_EVENT;
  c43_chartstep_c43_QRLsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c43_chartstep_c43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
  int32_T c43_i9;
  real_T c43_Rc[9];
  int32_T c43_i10;
  real_T c43_dRc[9];
  int32_T c43_i11;
  real_T c43_ddRc[9];
  uint32_T c43_debug_family_var_map[9];
  real_T c43_Omegachat[9];
  real_T c43_dOmegachat[9];
  real_T c43_nargin = 3.0;
  real_T c43_nargout = 2.0;
  real_T c43_Omegac[3];
  real_T c43_dOmegac[3];
  int32_T c43_i12;
  int32_T c43_i13;
  int32_T c43_i14;
  int32_T c43_i15;
  real_T c43_a[9];
  int32_T c43_i16;
  real_T c43_b[9];
  int32_T c43_i17;
  int32_T c43_i18;
  int32_T c43_i19;
  real_T c43_C[9];
  int32_T c43_i20;
  int32_T c43_i21;
  int32_T c43_i22;
  int32_T c43_i23;
  int32_T c43_i24;
  int32_T c43_i25;
  int32_T c43_i26;
  int32_T c43_i27;
  int32_T c43_i28;
  int32_T c43_i29;
  int32_T c43_i30;
  int32_T c43_i31;
  int32_T c43_i32;
  int32_T c43_i33;
  int32_T c43_i34;
  int32_T c43_i35;
  int32_T c43_i36;
  int32_T c43_i37;
  int32_T c43_i38;
  int32_T c43_i39;
  int32_T c43_i40;
  int32_T c43_i41;
  int32_T c43_i42;
  real_T c43_y[9];
  int32_T c43_i43;
  int32_T c43_i44;
  int32_T c43_i45;
  int32_T c43_i46;
  int32_T c43_i47;
  real_T (*c43_b_Omegac)[3];
  real_T (*c43_b_dOmegac)[3];
  real_T (*c43_b_ddRc)[9];
  real_T (*c43_b_dRc)[9];
  real_T (*c43_b_Rc)[9];
  c43_b_dOmegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_b_ddRc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c43_b_Omegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c43_b_dRc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c43_b_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c43_sfEvent);
  for (c43_i9 = 0; c43_i9 < 9; c43_i9++) {
    c43_Rc[c43_i9] = (*c43_b_Rc)[c43_i9];
  }

  for (c43_i10 = 0; c43_i10 < 9; c43_i10++) {
    c43_dRc[c43_i10] = (*c43_b_dRc)[c43_i10];
  }

  for (c43_i11 = 0; c43_i11 < 9; c43_i11++) {
    c43_ddRc[c43_i11] = (*c43_b_ddRc)[c43_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c43_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_Omegachat, 0U, c43_b_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_dOmegachat, 1U, c43_b_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 2U, c43_c_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 3U, c43_c_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c43_Rc, 4U, c43_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c43_dRc, 5U, c43_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c43_ddRc, 6U, c43_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_Omegac, 7U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_dOmegac, 8U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 3);
  c43_i12 = 0;
  for (c43_i13 = 0; c43_i13 < 3; c43_i13++) {
    c43_i14 = 0;
    for (c43_i15 = 0; c43_i15 < 3; c43_i15++) {
      c43_a[c43_i15 + c43_i12] = c43_Rc[c43_i14 + c43_i13];
      c43_i14 += 3;
    }

    c43_i12 += 3;
  }

  for (c43_i16 = 0; c43_i16 < 9; c43_i16++) {
    c43_b[c43_i16] = c43_dRc[c43_i16];
  }

  c43_eml_scalar_eg(chartInstance);
  c43_eml_scalar_eg(chartInstance);
  for (c43_i17 = 0; c43_i17 < 9; c43_i17++) {
    c43_Omegachat[c43_i17] = 0.0;
  }

  for (c43_i18 = 0; c43_i18 < 9; c43_i18++) {
    c43_Omegachat[c43_i18] = 0.0;
  }

  for (c43_i19 = 0; c43_i19 < 9; c43_i19++) {
    c43_C[c43_i19] = c43_Omegachat[c43_i19];
  }

  for (c43_i20 = 0; c43_i20 < 9; c43_i20++) {
    c43_Omegachat[c43_i20] = c43_C[c43_i20];
  }

  for (c43_i21 = 0; c43_i21 < 9; c43_i21++) {
    c43_C[c43_i21] = c43_Omegachat[c43_i21];
  }

  for (c43_i22 = 0; c43_i22 < 9; c43_i22++) {
    c43_Omegachat[c43_i22] = c43_C[c43_i22];
  }

  for (c43_i23 = 0; c43_i23 < 3; c43_i23++) {
    c43_i24 = 0;
    for (c43_i25 = 0; c43_i25 < 3; c43_i25++) {
      c43_Omegachat[c43_i24 + c43_i23] = 0.0;
      c43_i26 = 0;
      for (c43_i27 = 0; c43_i27 < 3; c43_i27++) {
        c43_Omegachat[c43_i24 + c43_i23] += c43_a[c43_i26 + c43_i23] *
          c43_b[c43_i27 + c43_i24];
        c43_i26 += 3;
      }

      c43_i24 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 4);
  c43_Omegac[0] = c43_Omegachat[5];
  c43_Omegac[1] = -c43_Omegachat[2];
  c43_Omegac[2] = c43_Omegachat[1];
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 6);
  for (c43_i28 = 0; c43_i28 < 9; c43_i28++) {
    c43_a[c43_i28] = -c43_Omegachat[c43_i28];
  }

  for (c43_i29 = 0; c43_i29 < 9; c43_i29++) {
    c43_b[c43_i29] = c43_Omegachat[c43_i29];
  }

  c43_eml_scalar_eg(chartInstance);
  c43_eml_scalar_eg(chartInstance);
  for (c43_i30 = 0; c43_i30 < 3; c43_i30++) {
    c43_i31 = 0;
    for (c43_i32 = 0; c43_i32 < 3; c43_i32++) {
      c43_C[c43_i31 + c43_i30] = 0.0;
      c43_i33 = 0;
      for (c43_i34 = 0; c43_i34 < 3; c43_i34++) {
        c43_C[c43_i31 + c43_i30] += c43_a[c43_i33 + c43_i30] * c43_b[c43_i34 +
          c43_i31];
        c43_i33 += 3;
      }

      c43_i31 += 3;
    }
  }

  c43_i35 = 0;
  for (c43_i36 = 0; c43_i36 < 3; c43_i36++) {
    c43_i37 = 0;
    for (c43_i38 = 0; c43_i38 < 3; c43_i38++) {
      c43_a[c43_i38 + c43_i35] = c43_Rc[c43_i37 + c43_i36];
      c43_i37 += 3;
    }

    c43_i35 += 3;
  }

  for (c43_i39 = 0; c43_i39 < 9; c43_i39++) {
    c43_b[c43_i39] = c43_ddRc[c43_i39];
  }

  c43_eml_scalar_eg(chartInstance);
  c43_eml_scalar_eg(chartInstance);
  for (c43_i40 = 0; c43_i40 < 3; c43_i40++) {
    c43_i41 = 0;
    for (c43_i42 = 0; c43_i42 < 3; c43_i42++) {
      c43_y[c43_i41 + c43_i40] = 0.0;
      c43_i43 = 0;
      for (c43_i44 = 0; c43_i44 < 3; c43_i44++) {
        c43_y[c43_i41 + c43_i40] += c43_a[c43_i43 + c43_i40] * c43_b[c43_i44 +
          c43_i41];
        c43_i43 += 3;
      }

      c43_i41 += 3;
    }
  }

  for (c43_i45 = 0; c43_i45 < 9; c43_i45++) {
    c43_dOmegachat[c43_i45] = c43_C[c43_i45] + c43_y[c43_i45];
  }

  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 7);
  c43_dOmegac[0] = c43_dOmegachat[5];
  c43_dOmegac[1] = -c43_dOmegachat[2];
  c43_dOmegac[2] = c43_dOmegachat[1];
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  for (c43_i46 = 0; c43_i46 < 3; c43_i46++) {
    (*c43_b_Omegac)[c43_i46] = c43_Omegac[c43_i46];
  }

  for (c43_i47 = 0; c43_i47 < 3; c43_i47++) {
    (*c43_b_dOmegac)[c43_i47] = c43_dOmegac[c43_i47];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c43_sfEvent);
}

static void initSimStructsc43_QRLsim(SFc43_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber)
{
}

static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i48;
  real_T c43_b_inData[3];
  int32_T c43_i49;
  real_T c43_u[3];
  const mxArray *c43_y = NULL;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i48 = 0; c43_i48 < 3; c43_i48++) {
    c43_b_inData[c43_i48] = (*(real_T (*)[3])c43_inData)[c43_i48];
  }

  for (c43_i49 = 0; c43_i49 < 3; c43_i49++) {
    c43_u[c43_i49] = c43_b_inData[c43_i49];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static void c43_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_dOmegac, const char_T *c43_identifier, real_T c43_y[3])
{
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_dOmegac), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_dOmegac);
}

static void c43_b_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[3])
{
  real_T c43_dv2[3];
  int32_T c43_i50;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c43_i50 = 0; c43_i50 < 3; c43_i50++) {
    c43_y[c43_i50] = c43_dv2[c43_i50];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_dOmegac;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[3];
  int32_T c43_i51;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_dOmegac = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_dOmegac), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_dOmegac);
  for (c43_i51 = 0; c43_i51 < 3; c43_i51++) {
    (*(real_T (*)[3])c43_outData)[c43_i51] = c43_y[c43_i51];
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i52;
  int32_T c43_i53;
  int32_T c43_i54;
  real_T c43_b_inData[9];
  int32_T c43_i55;
  int32_T c43_i56;
  int32_T c43_i57;
  real_T c43_u[9];
  const mxArray *c43_y = NULL;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_i52 = 0;
  for (c43_i53 = 0; c43_i53 < 3; c43_i53++) {
    for (c43_i54 = 0; c43_i54 < 3; c43_i54++) {
      c43_b_inData[c43_i54 + c43_i52] = (*(real_T (*)[9])c43_inData)[c43_i54 +
        c43_i52];
    }

    c43_i52 += 3;
  }

  c43_i55 = 0;
  for (c43_i56 = 0; c43_i56 < 3; c43_i56++) {
    for (c43_i57 = 0; c43_i57 < 3; c43_i57++) {
      c43_u[c43_i57 + c43_i55] = c43_b_inData[c43_i57 + c43_i55];
    }

    c43_i55 += 3;
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(real_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static real_T c43_c_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  real_T c43_y;
  real_T c43_d0;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_d0, 1, 0, 0U, 0, 0U, 0);
  c43_y = c43_d0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_nargout;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_nargout = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_nargout),
    &c43_thisId);
  sf_mex_destroy(&c43_nargout);
  *(real_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static void c43_d_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[9])
{
  real_T c43_dv3[9];
  int32_T c43_i58;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c43_i58 = 0; c43_i58 < 9; c43_i58++) {
    c43_y[c43_i58] = c43_dv3[c43_i58];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_dOmegachat;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[9];
  int32_T c43_i59;
  int32_T c43_i60;
  int32_T c43_i61;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_dOmegachat = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_dOmegachat), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_dOmegachat);
  c43_i59 = 0;
  for (c43_i60 = 0; c43_i60 < 3; c43_i60++) {
    for (c43_i61 = 0; c43_i61 < 3; c43_i61++) {
      (*(real_T (*)[9])c43_outData)[c43_i61 + c43_i59] = c43_y[c43_i61 + c43_i59];
    }

    c43_i59 += 3;
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

const mxArray *sf_c43_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c43_nameCaptureInfo = NULL;
  c43_nameCaptureInfo = NULL;
  sf_mex_assign(&c43_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c43_info_helper(&c43_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c43_nameCaptureInfo);
  return c43_nameCaptureInfo;
}

static void c43_info_helper(const mxArray **c43_info)
{
  const mxArray *c43_rhs0 = NULL;
  const mxArray *c43_lhs0 = NULL;
  const mxArray *c43_rhs1 = NULL;
  const mxArray *c43_lhs1 = NULL;
  const mxArray *c43_rhs2 = NULL;
  const mxArray *c43_lhs2 = NULL;
  const mxArray *c43_rhs3 = NULL;
  const mxArray *c43_lhs3 = NULL;
  const mxArray *c43_rhs4 = NULL;
  const mxArray *c43_lhs4 = NULL;
  const mxArray *c43_rhs5 = NULL;
  const mxArray *c43_lhs5 = NULL;
  const mxArray *c43_rhs6 = NULL;
  const mxArray *c43_lhs6 = NULL;
  const mxArray *c43_rhs7 = NULL;
  const mxArray *c43_lhs7 = NULL;
  const mxArray *c43_rhs8 = NULL;
  const mxArray *c43_lhs8 = NULL;
  const mxArray *c43_rhs9 = NULL;
  const mxArray *c43_lhs9 = NULL;
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c43_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c43_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c43_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c43_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c43_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c43_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c43_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c43_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c43_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c43_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c43_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c43_rhs0);
  sf_mex_destroy(&c43_lhs0);
  sf_mex_destroy(&c43_rhs1);
  sf_mex_destroy(&c43_lhs1);
  sf_mex_destroy(&c43_rhs2);
  sf_mex_destroy(&c43_lhs2);
  sf_mex_destroy(&c43_rhs3);
  sf_mex_destroy(&c43_lhs3);
  sf_mex_destroy(&c43_rhs4);
  sf_mex_destroy(&c43_lhs4);
  sf_mex_destroy(&c43_rhs5);
  sf_mex_destroy(&c43_lhs5);
  sf_mex_destroy(&c43_rhs6);
  sf_mex_destroy(&c43_lhs6);
  sf_mex_destroy(&c43_rhs7);
  sf_mex_destroy(&c43_lhs7);
  sf_mex_destroy(&c43_rhs8);
  sf_mex_destroy(&c43_lhs8);
  sf_mex_destroy(&c43_rhs9);
  sf_mex_destroy(&c43_lhs9);
}

static const mxArray *c43_emlrt_marshallOut(char * c43_u)
{
  const mxArray *c43_y = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c43_u)), FALSE);
  return c43_y;
}

static const mxArray *c43_b_emlrt_marshallOut(uint32_T c43_u)
{
  const mxArray *c43_y = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c43_y;
}

static void c43_eml_scalar_eg(SFc43_QRLsimInstanceStruct *chartInstance)
{
}

static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(int32_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static int32_T c43_e_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  int32_T c43_y;
  int32_T c43_i62;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_i62, 1, 6, 0U, 0, 0U, 0);
  c43_y = c43_i62;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_sfEvent;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  int32_T c43_y;
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)chartInstanceVoid;
  c43_b_sfEvent = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_sfEvent),
    &c43_thisId);
  sf_mex_destroy(&c43_b_sfEvent);
  *(int32_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static uint8_T c43_f_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_b_is_active_c43_QRLsim, const char_T *c43_identifier)
{
  uint8_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_is_active_c43_QRLsim), &c43_thisId);
  sf_mex_destroy(&c43_b_is_active_c43_QRLsim);
  return c43_y;
}

static uint8_T c43_g_emlrt_marshallIn(SFc43_QRLsimInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  uint8_T c43_y;
  uint8_T c43_u0;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_u0, 1, 3, 0U, 0, 0U, 0);
  c43_y = c43_u0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void init_dsm_address_info(SFc43_QRLsimInstanceStruct *chartInstance)
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

void sf_c43_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1835083612U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(928894702U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3345726901U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(387087164U);
}

mxArray *sf_c43_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2YQflrw4zDx2N5QMkTaPgC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

mxArray *sf_c43_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c43_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c43_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[7],T\"Omegac\",},{M[1],M[10],T\"dOmegac\",},{M[8],M[0],T\"is_active_c43_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c43_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc43_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc43_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           43,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"dRc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Omegac");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ddRc");
          _SFD_SET_DATA_PROPS(4,2,0,1,"dOmegac");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,238);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)
            c43_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)
            c43_sf_marshallIn);
        }

        {
          real_T (*c43_Rc)[9];
          real_T (*c43_dRc)[9];
          real_T (*c43_Omegac)[3];
          real_T (*c43_ddRc)[9];
          real_T (*c43_dOmegac)[3];
          c43_dOmegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c43_ddRc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
          c43_Omegac = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c43_dRc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c43_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c43_Rc);
          _SFD_SET_DATA_VALUE_PTR(1U, *c43_dRc);
          _SFD_SET_DATA_VALUE_PTR(2U, *c43_Omegac);
          _SFD_SET_DATA_VALUE_PTR(3U, *c43_ddRc);
          _SFD_SET_DATA_VALUE_PTR(4U, *c43_dOmegac);
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
  return "RzPEIy4sCsfB46mZ8ovIQC";
}

static void sf_opaque_initialize_c43_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc43_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c43_QRLsim(void *chartInstanceVar)
{
  enable_c43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c43_QRLsim(void *chartInstanceVar)
{
  disable_c43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c43_QRLsim(void *chartInstanceVar)
{
  sf_c43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c43_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c43_QRLsim((SFc43_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c43_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c43_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c43_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c43_QRLsim((SFc43_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c43_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c43_QRLsim(S);
}

static void sf_opaque_set_sim_state_c43_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c43_QRLsim(S, st);
}

static void sf_opaque_terminate_c43_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc43_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc43_QRLsim((SFc43_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c43_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c43_QRLsim((SFc43_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c43_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      43);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,43,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,43,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,43);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,43,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,43,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,43);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2080793896U));
  ssSetChecksum1(S,(2092763123U));
  ssSetChecksum2(S,(1111276871U));
  ssSetChecksum3(S,(1654159984U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c43_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c43_QRLsim(SimStruct *S)
{
  SFc43_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc43_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc43_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc43_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c43_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c43_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c43_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c43_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c43_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c43_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c43_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c43_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c43_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c43_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c43_QRLsim;
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

void c43_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c43_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c43_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c43_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c43_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
