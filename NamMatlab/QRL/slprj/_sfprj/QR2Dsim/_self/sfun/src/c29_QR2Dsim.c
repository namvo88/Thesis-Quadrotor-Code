/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QR2Dsim_sfun.h"
#include "c29_QR2Dsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QR2Dsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c29_debug_family_names[6] = { "Omegadhat", "nargin",
  "nargout", "Rd", "dRd", "Omegad" };

/* Function Declarations */
static void initialize_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void initialize_params_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct
  *chartInstance);
static void enable_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void disable_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void c29_update_debugger_state_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct
  *chartInstance);
static void set_sim_state_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_st);
static void finalize_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void sf_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void c29_chartstep_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void initSimStructsc29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber);
static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_Omegad, const char_T *c29_identifier, real_T c29_y[3]);
static void c29_b_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[3]);
static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static real_T c29_c_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static void c29_d_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[9]);
static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static void c29_info_helper(const mxArray **c29_info);
static const mxArray *c29_emlrt_marshallOut(char * c29_u);
static const mxArray *c29_b_emlrt_marshallOut(uint32_T c29_u);
static void c29_eml_scalar_eg(SFc29_QR2DsimInstanceStruct *chartInstance);
static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static int32_T c29_e_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static uint8_T c29_f_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_b_is_active_c29_QR2Dsim, const char_T *c29_identifier);
static uint8_T c29_g_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void init_dsm_address_info(SFc29_QR2DsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
  chartInstance->c29_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c29_is_active_c29_QR2Dsim = 0U;
}

static void initialize_params_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct
  *chartInstance)
{
}

static void enable_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c29_update_debugger_state_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct
  *chartInstance)
{
  const mxArray *c29_st;
  const mxArray *c29_y = NULL;
  int32_T c29_i0;
  real_T c29_u[3];
  const mxArray *c29_b_y = NULL;
  uint8_T c29_hoistedGlobal;
  uint8_T c29_b_u;
  const mxArray *c29_c_y = NULL;
  real_T (*c29_Omegad)[3];
  c29_Omegad = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_st = NULL;
  c29_st = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_createcellarray(2), FALSE);
  for (c29_i0 = 0; c29_i0 < 3; c29_i0++) {
    c29_u[c29_i0] = (*c29_Omegad)[c29_i0];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c29_y, 0, c29_b_y);
  c29_hoistedGlobal = chartInstance->c29_is_active_c29_QR2Dsim;
  c29_b_u = c29_hoistedGlobal;
  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", &c29_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c29_y, 1, c29_c_y);
  sf_mex_assign(&c29_st, c29_y, FALSE);
  return c29_st;
}

static void set_sim_state_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_st)
{
  const mxArray *c29_u;
  real_T c29_dv0[3];
  int32_T c29_i1;
  real_T (*c29_Omegad)[3];
  c29_Omegad = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c29_doneDoubleBufferReInit = TRUE;
  c29_u = sf_mex_dup(c29_st);
  c29_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 0)),
                       "Omegad", c29_dv0);
  for (c29_i1 = 0; c29_i1 < 3; c29_i1++) {
    (*c29_Omegad)[c29_i1] = c29_dv0[c29_i1];
  }

  chartInstance->c29_is_active_c29_QR2Dsim = c29_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 1)),
     "is_active_c29_QR2Dsim");
  sf_mex_destroy(&c29_u);
  c29_update_debugger_state_c29_QR2Dsim(chartInstance);
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
}

static void sf_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c29_i2;
  int32_T c29_i3;
  int32_T c29_i4;
  real_T (*c29_Omegad)[3];
  real_T (*c29_dRd)[9];
  real_T (*c29_Rd)[9];
  c29_Omegad = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_dRd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c29_Rd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c29_sfEvent);
  for (c29_i2 = 0; c29_i2 < 9; c29_i2++) {
    _SFD_DATA_RANGE_CHECK((*c29_Rd)[c29_i2], 0U);
  }

  for (c29_i3 = 0; c29_i3 < 9; c29_i3++) {
    _SFD_DATA_RANGE_CHECK((*c29_dRd)[c29_i3], 1U);
  }

  for (c29_i4 = 0; c29_i4 < 3; c29_i4++) {
    _SFD_DATA_RANGE_CHECK((*c29_Omegad)[c29_i4], 2U);
  }

  chartInstance->c29_sfEvent = CALL_EVENT;
  c29_chartstep_c29_QR2Dsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QR2DsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c29_chartstep_c29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c29_i5;
  real_T c29_Rd[9];
  int32_T c29_i6;
  real_T c29_dRd[9];
  uint32_T c29_debug_family_var_map[6];
  real_T c29_Omegadhat[9];
  real_T c29_nargin = 2.0;
  real_T c29_nargout = 1.0;
  real_T c29_Omegad[3];
  int32_T c29_i7;
  int32_T c29_i8;
  int32_T c29_i9;
  int32_T c29_i10;
  real_T c29_a[9];
  int32_T c29_i11;
  real_T c29_b[9];
  int32_T c29_i12;
  int32_T c29_i13;
  int32_T c29_i14;
  real_T c29_C[9];
  int32_T c29_i15;
  int32_T c29_i16;
  int32_T c29_i17;
  int32_T c29_i18;
  int32_T c29_i19;
  int32_T c29_i20;
  int32_T c29_i21;
  int32_T c29_i22;
  int32_T c29_i23;
  real_T (*c29_b_Omegad)[3];
  real_T (*c29_b_dRd)[9];
  real_T (*c29_b_Rd)[9];
  c29_b_Omegad = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_b_dRd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c29_b_Rd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c29_sfEvent);
  for (c29_i5 = 0; c29_i5 < 9; c29_i5++) {
    c29_Rd[c29_i5] = (*c29_b_Rd)[c29_i5];
  }

  for (c29_i6 = 0; c29_i6 < 9; c29_i6++) {
    c29_dRd[c29_i6] = (*c29_b_dRd)[c29_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c29_debug_family_names,
    c29_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_Omegadhat, 0U, c29_b_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargin, 1U, c29_c_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargout, 2U, c29_c_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c29_Rd, 3U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c29_dRd, 4U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_Omegad, 5U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 3);
  c29_i7 = 0;
  for (c29_i8 = 0; c29_i8 < 3; c29_i8++) {
    c29_i9 = 0;
    for (c29_i10 = 0; c29_i10 < 3; c29_i10++) {
      c29_a[c29_i10 + c29_i7] = c29_Rd[c29_i9 + c29_i8];
      c29_i9 += 3;
    }

    c29_i7 += 3;
  }

  for (c29_i11 = 0; c29_i11 < 9; c29_i11++) {
    c29_b[c29_i11] = c29_dRd[c29_i11];
  }

  c29_eml_scalar_eg(chartInstance);
  c29_eml_scalar_eg(chartInstance);
  for (c29_i12 = 0; c29_i12 < 9; c29_i12++) {
    c29_Omegadhat[c29_i12] = 0.0;
  }

  for (c29_i13 = 0; c29_i13 < 9; c29_i13++) {
    c29_Omegadhat[c29_i13] = 0.0;
  }

  for (c29_i14 = 0; c29_i14 < 9; c29_i14++) {
    c29_C[c29_i14] = c29_Omegadhat[c29_i14];
  }

  for (c29_i15 = 0; c29_i15 < 9; c29_i15++) {
    c29_Omegadhat[c29_i15] = c29_C[c29_i15];
  }

  for (c29_i16 = 0; c29_i16 < 9; c29_i16++) {
    c29_C[c29_i16] = c29_Omegadhat[c29_i16];
  }

  for (c29_i17 = 0; c29_i17 < 9; c29_i17++) {
    c29_Omegadhat[c29_i17] = c29_C[c29_i17];
  }

  for (c29_i18 = 0; c29_i18 < 3; c29_i18++) {
    c29_i19 = 0;
    for (c29_i20 = 0; c29_i20 < 3; c29_i20++) {
      c29_Omegadhat[c29_i19 + c29_i18] = 0.0;
      c29_i21 = 0;
      for (c29_i22 = 0; c29_i22 < 3; c29_i22++) {
        c29_Omegadhat[c29_i19 + c29_i18] += c29_a[c29_i21 + c29_i18] *
          c29_b[c29_i22 + c29_i19];
        c29_i21 += 3;
      }

      c29_i19 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 4);
  c29_Omegad[0] = c29_Omegadhat[5];
  c29_Omegad[1] = -c29_Omegadhat[2];
  c29_Omegad[2] = c29_Omegadhat[1];
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c29_i23 = 0; c29_i23 < 3; c29_i23++) {
    (*c29_b_Omegad)[c29_i23] = c29_Omegad[c29_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c29_sfEvent);
}

static void initSimStructsc29_QR2Dsim(SFc29_QR2DsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber)
{
}

static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i24;
  real_T c29_b_inData[3];
  int32_T c29_i25;
  real_T c29_u[3];
  const mxArray *c29_y = NULL;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i24 = 0; c29_i24 < 3; c29_i24++) {
    c29_b_inData[c29_i24] = (*(real_T (*)[3])c29_inData)[c29_i24];
  }

  for (c29_i25 = 0; c29_i25 < 3; c29_i25++) {
    c29_u[c29_i25] = c29_b_inData[c29_i25];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static void c29_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_Omegad, const char_T *c29_identifier, real_T c29_y[3])
{
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_Omegad), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_Omegad);
}

static void c29_b_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[3])
{
  real_T c29_dv1[3];
  int32_T c29_i26;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c29_i26 = 0; c29_i26 < 3; c29_i26++) {
    c29_y[c29_i26] = c29_dv1[c29_i26];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_Omegad;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[3];
  int32_T c29_i27;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_Omegad = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_Omegad), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_Omegad);
  for (c29_i27 = 0; c29_i27 < 3; c29_i27++) {
    (*(real_T (*)[3])c29_outData)[c29_i27] = c29_y[c29_i27];
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i28;
  int32_T c29_i29;
  int32_T c29_i30;
  real_T c29_b_inData[9];
  int32_T c29_i31;
  int32_T c29_i32;
  int32_T c29_i33;
  real_T c29_u[9];
  const mxArray *c29_y = NULL;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i28 = 0;
  for (c29_i29 = 0; c29_i29 < 3; c29_i29++) {
    for (c29_i30 = 0; c29_i30 < 3; c29_i30++) {
      c29_b_inData[c29_i30 + c29_i28] = (*(real_T (*)[9])c29_inData)[c29_i30 +
        c29_i28];
    }

    c29_i28 += 3;
  }

  c29_i31 = 0;
  for (c29_i32 = 0; c29_i32 < 3; c29_i32++) {
    for (c29_i33 = 0; c29_i33 < 3; c29_i33++) {
      c29_u[c29_i33 + c29_i31] = c29_b_inData[c29_i33 + c29_i31];
    }

    c29_i31 += 3;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  real_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(real_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static real_T c29_c_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  real_T c29_y;
  real_T c29_d0;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_d0, 1, 0, 0U, 0, 0U, 0);
  c29_y = c29_d0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_nargout;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_nargout = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_nargout),
    &c29_thisId);
  sf_mex_destroy(&c29_nargout);
  *(real_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static void c29_d_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[9])
{
  real_T c29_dv2[9];
  int32_T c29_i34;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c29_i34 = 0; c29_i34 < 9; c29_i34++) {
    c29_y[c29_i34] = c29_dv2[c29_i34];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_Omegadhat;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[9];
  int32_T c29_i35;
  int32_T c29_i36;
  int32_T c29_i37;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_Omegadhat = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_Omegadhat), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_Omegadhat);
  c29_i35 = 0;
  for (c29_i36 = 0; c29_i36 < 3; c29_i36++) {
    for (c29_i37 = 0; c29_i37 < 3; c29_i37++) {
      (*(real_T (*)[9])c29_outData)[c29_i37 + c29_i35] = c29_y[c29_i37 + c29_i35];
    }

    c29_i35 += 3;
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

const mxArray *sf_c29_QR2Dsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c29_nameCaptureInfo = NULL;
  c29_nameCaptureInfo = NULL;
  sf_mex_assign(&c29_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c29_info_helper(&c29_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c29_nameCaptureInfo);
  return c29_nameCaptureInfo;
}

static void c29_info_helper(const mxArray **c29_info)
{
  const mxArray *c29_rhs0 = NULL;
  const mxArray *c29_lhs0 = NULL;
  const mxArray *c29_rhs1 = NULL;
  const mxArray *c29_lhs1 = NULL;
  const mxArray *c29_rhs2 = NULL;
  const mxArray *c29_lhs2 = NULL;
  const mxArray *c29_rhs3 = NULL;
  const mxArray *c29_lhs3 = NULL;
  const mxArray *c29_rhs4 = NULL;
  const mxArray *c29_lhs4 = NULL;
  const mxArray *c29_rhs5 = NULL;
  const mxArray *c29_lhs5 = NULL;
  const mxArray *c29_rhs6 = NULL;
  const mxArray *c29_lhs6 = NULL;
  const mxArray *c29_rhs7 = NULL;
  const mxArray *c29_lhs7 = NULL;
  const mxArray *c29_rhs8 = NULL;
  const mxArray *c29_lhs8 = NULL;
  const mxArray *c29_rhs9 = NULL;
  const mxArray *c29_lhs9 = NULL;
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c29_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c29_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c29_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c29_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c29_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c29_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c29_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c29_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c29_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c29_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c29_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c29_rhs0);
  sf_mex_destroy(&c29_lhs0);
  sf_mex_destroy(&c29_rhs1);
  sf_mex_destroy(&c29_lhs1);
  sf_mex_destroy(&c29_rhs2);
  sf_mex_destroy(&c29_lhs2);
  sf_mex_destroy(&c29_rhs3);
  sf_mex_destroy(&c29_lhs3);
  sf_mex_destroy(&c29_rhs4);
  sf_mex_destroy(&c29_lhs4);
  sf_mex_destroy(&c29_rhs5);
  sf_mex_destroy(&c29_lhs5);
  sf_mex_destroy(&c29_rhs6);
  sf_mex_destroy(&c29_lhs6);
  sf_mex_destroy(&c29_rhs7);
  sf_mex_destroy(&c29_lhs7);
  sf_mex_destroy(&c29_rhs8);
  sf_mex_destroy(&c29_lhs8);
  sf_mex_destroy(&c29_rhs9);
  sf_mex_destroy(&c29_lhs9);
}

static const mxArray *c29_emlrt_marshallOut(char * c29_u)
{
  const mxArray *c29_y = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c29_u)), FALSE);
  return c29_y;
}

static const mxArray *c29_b_emlrt_marshallOut(uint32_T c29_u)
{
  const mxArray *c29_y = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c29_y;
}

static void c29_eml_scalar_eg(SFc29_QR2DsimInstanceStruct *chartInstance)
{
}

static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(int32_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static int32_T c29_e_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  int32_T c29_y;
  int32_T c29_i38;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_i38, 1, 6, 0U, 0, 0U, 0);
  c29_y = c29_i38;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_b_sfEvent;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  int32_T c29_y;
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)chartInstanceVoid;
  c29_b_sfEvent = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_sfEvent),
    &c29_thisId);
  sf_mex_destroy(&c29_b_sfEvent);
  *(int32_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static uint8_T c29_f_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_b_is_active_c29_QR2Dsim, const char_T *c29_identifier)
{
  uint8_T c29_y;
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c29_b_is_active_c29_QR2Dsim), &c29_thisId);
  sf_mex_destroy(&c29_b_is_active_c29_QR2Dsim);
  return c29_y;
}

static uint8_T c29_g_emlrt_marshallIn(SFc29_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  uint8_T c29_y;
  uint8_T c29_u0;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_u0, 1, 3, 0U, 0, 0U, 0);
  c29_y = c29_u0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void init_dsm_address_info(SFc29_QR2DsimInstanceStruct *chartInstance)
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

void sf_c29_QR2Dsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(92585303U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2411315216U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1294526032U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(793719263U);
}

mxArray *sf_c29_QR2Dsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("S5W2QdE1rF6lIEahi8dkRG");
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

mxArray *sf_c29_QR2Dsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c29_QR2Dsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c29_QR2Dsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"Omegad\",},{M[8],M[0],T\"is_active_c29_QR2Dsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_QR2Dsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc29_QR2DsimInstanceStruct *chartInstance;
    chartInstance = (SFc29_QR2DsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QR2DsimMachineNumber_,
           29,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Rd");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dRd");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Omegad");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,113);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)
            c29_sf_marshallIn);
        }

        {
          real_T (*c29_Rd)[9];
          real_T (*c29_dRd)[9];
          real_T (*c29_Omegad)[3];
          c29_Omegad = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c29_dRd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c29_Rd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c29_Rd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c29_dRd);
          _SFD_SET_DATA_VALUE_PTR(2U, *c29_Omegad);
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
  return "w3NHdOk1NHZaFRKoFfb0DH";
}

static void sf_opaque_initialize_c29_QR2Dsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc29_QR2DsimInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
  initialize_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c29_QR2Dsim(void *chartInstanceVar)
{
  enable_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c29_QR2Dsim(void *chartInstanceVar)
{
  disable_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c29_QR2Dsim(void *chartInstanceVar)
{
  sf_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c29_QR2Dsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c29_QR2Dsim();/* state var info */
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

extern void sf_internal_set_sim_state_c29_QR2Dsim(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c29_QR2Dsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c29_QR2Dsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c29_QR2Dsim(S);
}

static void sf_opaque_set_sim_state_c29_QR2Dsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c29_QR2Dsim(S, st);
}

static void sf_opaque_terminate_c29_QR2Dsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc29_QR2DsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QR2Dsim_optimization_info();
    }

    finalize_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc29_QR2Dsim((SFc29_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_QR2Dsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c29_QR2Dsim((SFc29_QR2DsimInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c29_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QR2Dsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,29,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,29);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,29,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,29,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3372275117U));
  ssSetChecksum1(S,(3918046983U));
  ssSetChecksum2(S,(2160734186U));
  ssSetChecksum3(S,(343502716U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c29_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_QR2Dsim(SimStruct *S)
{
  SFc29_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc29_QR2DsimInstanceStruct *)utMalloc(sizeof
    (SFc29_QR2DsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc29_QR2DsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c29_QR2Dsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c29_QR2Dsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c29_QR2Dsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c29_QR2Dsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c29_QR2Dsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c29_QR2Dsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c29_QR2Dsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c29_QR2Dsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c29_QR2Dsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c29_QR2Dsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c29_QR2Dsim;
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

void c29_QR2Dsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_QR2Dsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_QR2Dsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_QR2Dsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_QR2Dsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
