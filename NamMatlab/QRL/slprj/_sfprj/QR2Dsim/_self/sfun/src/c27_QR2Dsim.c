/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QR2Dsim_sfun.h"
#include "c27_QR2Dsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QR2Dsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c27_debug_family_names[6] = { "eRhat", "nargin", "nargout",
  "R", "Rc", "eR" };

/* Function Declarations */
static void initialize_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void initialize_params_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct
  *chartInstance);
static void enable_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void disable_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void c27_update_debugger_state_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct
  *chartInstance);
static void set_sim_state_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_st);
static void finalize_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void sf_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void c27_chartstep_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void initSimStructsc27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_eR, const char_T *c27_identifier, real_T c27_y[3]);
static void c27_b_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[3]);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_c_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static void c27_d_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[9]);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(uint32_T c27_u);
static void c27_eml_scalar_eg(SFc27_QR2DsimInstanceStruct *chartInstance);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_e_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_f_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_b_is_active_c27_QR2Dsim, const char_T *c27_identifier);
static uint8_T c27_g_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info(SFc27_QR2DsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c27_is_active_c27_QR2Dsim = 0U;
}

static void initialize_params_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct
  *chartInstance)
{
}

static void enable_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c27_update_debugger_state_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct
  *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  int32_T c27_i0;
  real_T c27_u[3];
  const mxArray *c27_b_y = NULL;
  uint8_T c27_hoistedGlobal;
  uint8_T c27_b_u;
  const mxArray *c27_c_y = NULL;
  real_T (*c27_eR)[3];
  c27_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellarray(2), FALSE);
  for (c27_i0 = 0; c27_i0 < 3; c27_i0++) {
    c27_u[c27_i0] = (*c27_eR)[c27_i0];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_hoistedGlobal = chartInstance->c27_is_active_c27_QR2Dsim;
  c27_b_u = c27_hoistedGlobal;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  sf_mex_assign(&c27_st, c27_y, FALSE);
  return c27_st;
}

static void set_sim_state_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_st)
{
  const mxArray *c27_u;
  real_T c27_dv0[3];
  int32_T c27_i1;
  real_T (*c27_eR)[3];
  c27_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c27_doneDoubleBufferReInit = TRUE;
  c27_u = sf_mex_dup(c27_st);
  c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 0)), "eR",
                       c27_dv0);
  for (c27_i1 = 0; c27_i1 < 3; c27_i1++) {
    (*c27_eR)[c27_i1] = c27_dv0[c27_i1];
  }

  chartInstance->c27_is_active_c27_QR2Dsim = c27_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 1)),
     "is_active_c27_QR2Dsim");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_QR2Dsim(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
}

static void sf_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c27_i2;
  int32_T c27_i3;
  int32_T c27_i4;
  real_T (*c27_eR)[3];
  real_T (*c27_Rc)[9];
  real_T (*c27_R)[9];
  c27_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c27_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c27_sfEvent);
  for (c27_i2 = 0; c27_i2 < 9; c27_i2++) {
    _SFD_DATA_RANGE_CHECK((*c27_R)[c27_i2], 0U);
  }

  for (c27_i3 = 0; c27_i3 < 9; c27_i3++) {
    _SFD_DATA_RANGE_CHECK((*c27_Rc)[c27_i3], 1U);
  }

  for (c27_i4 = 0; c27_i4 < 3; c27_i4++) {
    _SFD_DATA_RANGE_CHECK((*c27_eR)[c27_i4], 2U);
  }

  chartInstance->c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_QR2Dsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QR2DsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c27_chartstep_c27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c27_i5;
  real_T c27_R[9];
  int32_T c27_i6;
  real_T c27_Rc[9];
  uint32_T c27_debug_family_var_map[6];
  real_T c27_eRhat[9];
  real_T c27_nargin = 2.0;
  real_T c27_nargout = 1.0;
  real_T c27_eR[3];
  int32_T c27_i7;
  int32_T c27_i8;
  int32_T c27_i9;
  int32_T c27_i10;
  real_T c27_a[9];
  int32_T c27_i11;
  real_T c27_b[9];
  int32_T c27_i12;
  int32_T c27_i13;
  int32_T c27_i14;
  real_T c27_y[9];
  int32_T c27_i15;
  int32_T c27_i16;
  int32_T c27_i17;
  int32_T c27_i18;
  int32_T c27_i19;
  int32_T c27_i20;
  int32_T c27_i21;
  int32_T c27_i22;
  int32_T c27_i23;
  int32_T c27_i24;
  real_T c27_b_y[9];
  int32_T c27_i25;
  int32_T c27_i26;
  int32_T c27_i27;
  real_T c27_b_b[3];
  int32_T c27_i28;
  int32_T c27_i29;
  real_T (*c27_b_eR)[3];
  real_T (*c27_b_Rc)[9];
  real_T (*c27_b_R)[9];
  c27_b_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_b_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c27_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c27_sfEvent);
  for (c27_i5 = 0; c27_i5 < 9; c27_i5++) {
    c27_R[c27_i5] = (*c27_b_R)[c27_i5];
  }

  for (c27_i6 = 0; c27_i6 < 9; c27_i6++) {
    c27_Rc[c27_i6] = (*c27_b_Rc)[c27_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_eRhat, 0U, c27_b_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 1U, c27_c_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 2U, c27_c_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_R, 3U, c27_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_Rc, 4U, c27_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_eR, 5U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 4);
  c27_i7 = 0;
  for (c27_i8 = 0; c27_i8 < 3; c27_i8++) {
    c27_i9 = 0;
    for (c27_i10 = 0; c27_i10 < 3; c27_i10++) {
      c27_a[c27_i10 + c27_i7] = c27_Rc[c27_i9 + c27_i8];
      c27_i9 += 3;
    }

    c27_i7 += 3;
  }

  for (c27_i11 = 0; c27_i11 < 9; c27_i11++) {
    c27_b[c27_i11] = c27_R[c27_i11];
  }

  c27_eml_scalar_eg(chartInstance);
  c27_eml_scalar_eg(chartInstance);
  for (c27_i12 = 0; c27_i12 < 3; c27_i12++) {
    c27_i13 = 0;
    for (c27_i14 = 0; c27_i14 < 3; c27_i14++) {
      c27_y[c27_i13 + c27_i12] = 0.0;
      c27_i15 = 0;
      for (c27_i16 = 0; c27_i16 < 3; c27_i16++) {
        c27_y[c27_i13 + c27_i12] += c27_a[c27_i15 + c27_i12] * c27_b[c27_i16 +
          c27_i13];
        c27_i15 += 3;
      }

      c27_i13 += 3;
    }
  }

  c27_i17 = 0;
  for (c27_i18 = 0; c27_i18 < 3; c27_i18++) {
    c27_i19 = 0;
    for (c27_i20 = 0; c27_i20 < 3; c27_i20++) {
      c27_a[c27_i20 + c27_i17] = c27_R[c27_i19 + c27_i18];
      c27_i19 += 3;
    }

    c27_i17 += 3;
  }

  for (c27_i21 = 0; c27_i21 < 9; c27_i21++) {
    c27_b[c27_i21] = c27_Rc[c27_i21];
  }

  c27_eml_scalar_eg(chartInstance);
  c27_eml_scalar_eg(chartInstance);
  for (c27_i22 = 0; c27_i22 < 3; c27_i22++) {
    c27_i23 = 0;
    for (c27_i24 = 0; c27_i24 < 3; c27_i24++) {
      c27_b_y[c27_i23 + c27_i22] = 0.0;
      c27_i25 = 0;
      for (c27_i26 = 0; c27_i26 < 3; c27_i26++) {
        c27_b_y[c27_i23 + c27_i22] += c27_a[c27_i25 + c27_i22] * c27_b[c27_i26 +
          c27_i23];
        c27_i25 += 3;
      }

      c27_i23 += 3;
    }
  }

  for (c27_i27 = 0; c27_i27 < 9; c27_i27++) {
    c27_eRhat[c27_i27] = c27_y[c27_i27] - c27_b_y[c27_i27];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 5);
  c27_b_b[0] = c27_eRhat[5];
  c27_b_b[1] = -c27_eRhat[2];
  c27_b_b[2] = c27_eRhat[1];
  for (c27_i28 = 0; c27_i28 < 3; c27_i28++) {
    c27_eR[c27_i28] = 0.5 * c27_b_b[c27_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c27_i29 = 0; c27_i29 < 3; c27_i29++) {
    (*c27_b_eR)[c27_i29] = c27_eR[c27_i29];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c27_sfEvent);
}

static void initSimStructsc27_QR2Dsim(SFc27_QR2DsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber)
{
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i30;
  real_T c27_b_inData[3];
  int32_T c27_i31;
  real_T c27_u[3];
  const mxArray *c27_y = NULL;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i30 = 0; c27_i30 < 3; c27_i30++) {
    c27_b_inData[c27_i30] = (*(real_T (*)[3])c27_inData)[c27_i30];
  }

  for (c27_i31 = 0; c27_i31 < 3; c27_i31++) {
    c27_u[c27_i31] = c27_b_inData[c27_i31];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static void c27_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_eR, const char_T *c27_identifier, real_T c27_y[3])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_eR), &c27_thisId, c27_y);
  sf_mex_destroy(&c27_eR);
}

static void c27_b_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[3])
{
  real_T c27_dv1[3];
  int32_T c27_i32;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c27_i32 = 0; c27_i32 < 3; c27_i32++) {
    c27_y[c27_i32] = c27_dv1[c27_i32];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_eR;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[3];
  int32_T c27_i33;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_eR = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_eR), &c27_thisId, c27_y);
  sf_mex_destroy(&c27_eR);
  for (c27_i33 = 0; c27_i33 < 3; c27_i33++) {
    (*(real_T (*)[3])c27_outData)[c27_i33] = c27_y[c27_i33];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i34;
  int32_T c27_i35;
  int32_T c27_i36;
  real_T c27_b_inData[9];
  int32_T c27_i37;
  int32_T c27_i38;
  int32_T c27_i39;
  real_T c27_u[9];
  const mxArray *c27_y = NULL;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i34 = 0;
  for (c27_i35 = 0; c27_i35 < 3; c27_i35++) {
    for (c27_i36 = 0; c27_i36 < 3; c27_i36++) {
      c27_b_inData[c27_i36 + c27_i34] = (*(real_T (*)[9])c27_inData)[c27_i36 +
        c27_i34];
    }

    c27_i34 += 3;
  }

  c27_i37 = 0;
  for (c27_i38 = 0; c27_i38 < 3; c27_i38++) {
    for (c27_i39 = 0; c27_i39 < 3; c27_i39++) {
      c27_u[c27_i39 + c27_i37] = c27_b_inData[c27_i39 + c27_i37];
    }

    c27_i37 += 3;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static real_T c27_c_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_nargout;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_nargout = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_nargout),
    &c27_thisId);
  sf_mex_destroy(&c27_nargout);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static void c27_d_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[9])
{
  real_T c27_dv2[9];
  int32_T c27_i40;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c27_i40 = 0; c27_i40 < 9; c27_i40++) {
    c27_y[c27_i40] = c27_dv2[c27_i40];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_eRhat;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[9];
  int32_T c27_i41;
  int32_T c27_i42;
  int32_T c27_i43;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_eRhat = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_eRhat), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_eRhat);
  c27_i41 = 0;
  for (c27_i42 = 0; c27_i42 < 3; c27_i42++) {
    for (c27_i43 = 0; c27_i43 < 3; c27_i43++) {
      (*(real_T (*)[9])c27_outData)[c27_i43 + c27_i41] = c27_y[c27_i43 + c27_i41];
    }

    c27_i41 += 3;
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray *sf_c27_QR2Dsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c27_info_helper(&c27_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs0 = NULL;
  const mxArray *c27_lhs0 = NULL;
  const mxArray *c27_rhs1 = NULL;
  const mxArray *c27_lhs1 = NULL;
  const mxArray *c27_rhs2 = NULL;
  const mxArray *c27_lhs2 = NULL;
  const mxArray *c27_rhs3 = NULL;
  const mxArray *c27_lhs3 = NULL;
  const mxArray *c27_rhs4 = NULL;
  const mxArray *c27_lhs4 = NULL;
  const mxArray *c27_rhs5 = NULL;
  const mxArray *c27_lhs5 = NULL;
  const mxArray *c27_rhs6 = NULL;
  const mxArray *c27_lhs6 = NULL;
  const mxArray *c27_rhs7 = NULL;
  const mxArray *c27_lhs7 = NULL;
  const mxArray *c27_rhs8 = NULL;
  const mxArray *c27_lhs8 = NULL;
  const mxArray *c27_rhs9 = NULL;
  const mxArray *c27_lhs9 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c27_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c27_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c27_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c27_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c27_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c27_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c27_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c27_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c27_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c27_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c27_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c27_rhs0);
  sf_mex_destroy(&c27_lhs0);
  sf_mex_destroy(&c27_rhs1);
  sf_mex_destroy(&c27_lhs1);
  sf_mex_destroy(&c27_rhs2);
  sf_mex_destroy(&c27_lhs2);
  sf_mex_destroy(&c27_rhs3);
  sf_mex_destroy(&c27_lhs3);
  sf_mex_destroy(&c27_rhs4);
  sf_mex_destroy(&c27_lhs4);
  sf_mex_destroy(&c27_rhs5);
  sf_mex_destroy(&c27_lhs5);
  sf_mex_destroy(&c27_rhs6);
  sf_mex_destroy(&c27_lhs6);
  sf_mex_destroy(&c27_rhs7);
  sf_mex_destroy(&c27_lhs7);
  sf_mex_destroy(&c27_rhs8);
  sf_mex_destroy(&c27_lhs8);
  sf_mex_destroy(&c27_rhs9);
  sf_mex_destroy(&c27_lhs9);
}

static const mxArray *c27_emlrt_marshallOut(char * c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c27_u)), FALSE);
  return c27_y;
}

static const mxArray *c27_b_emlrt_marshallOut(uint32_T c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c27_y;
}

static void c27_eml_scalar_eg(SFc27_QR2DsimInstanceStruct *chartInstance)
{
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static int32_T c27_e_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i44;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i44, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i44;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_f_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_b_is_active_c27_QR2Dsim, const char_T *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_QR2Dsim), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_QR2Dsim);
  return c27_y;
}

static uint8_T c27_g_emlrt_marshallIn(SFc27_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info(SFc27_QR2DsimInstanceStruct *chartInstance)
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

void sf_c27_QR2Dsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2730778187U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3503168460U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659363575U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1580438123U);
}

mxArray *sf_c27_QR2Dsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kFvg6pkEDHAcjswAzNrDKG");
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

mxArray *sf_c27_QR2Dsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_QR2Dsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c27_QR2Dsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"eR\",},{M[8],M[0],T\"is_active_c27_QR2Dsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_QR2Dsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_QR2DsimInstanceStruct *chartInstance;
    chartInstance = (SFc27_QR2DsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QR2DsimMachineNumber_,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"eR");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,114);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)
            c27_sf_marshallIn);
        }

        {
          real_T (*c27_R)[9];
          real_T (*c27_Rc)[9];
          real_T (*c27_eR)[3];
          c27_eR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c27_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c27_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c27_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c27_Rc);
          _SFD_SET_DATA_VALUE_PTR(2U, *c27_eR);
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
  return "zQo4rdINUamZX8VbEUcljB";
}

static void sf_opaque_initialize_c27_QR2Dsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_QR2DsimInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
  initialize_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c27_QR2Dsim(void *chartInstanceVar)
{
  enable_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c27_QR2Dsim(void *chartInstanceVar)
{
  disable_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c27_QR2Dsim(void *chartInstanceVar)
{
  sf_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c27_QR2Dsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_QR2Dsim();/* state var info */
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

extern void sf_internal_set_sim_state_c27_QR2Dsim(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_QR2Dsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c27_QR2Dsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c27_QR2Dsim(S);
}

static void sf_opaque_set_sim_state_c27_QR2Dsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c27_QR2Dsim(S, st);
}

static void sf_opaque_terminate_c27_QR2Dsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_QR2DsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QR2Dsim_optimization_info();
    }

    finalize_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc27_QR2Dsim((SFc27_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_QR2Dsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c27_QR2Dsim((SFc27_QR2DsimInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QR2Dsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,27,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4187228339U));
  ssSetChecksum1(S,(3620914720U));
  ssSetChecksum2(S,(1369812130U));
  ssSetChecksum3(S,(3273617287U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_QR2Dsim(SimStruct *S)
{
  SFc27_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc27_QR2DsimInstanceStruct *)utMalloc(sizeof
    (SFc27_QR2DsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_QR2DsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c27_QR2Dsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c27_QR2Dsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c27_QR2Dsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c27_QR2Dsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c27_QR2Dsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c27_QR2Dsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c27_QR2Dsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c27_QR2Dsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_QR2Dsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_QR2Dsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c27_QR2Dsim;
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

void c27_QR2Dsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_QR2Dsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_QR2Dsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_QR2Dsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_QR2Dsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
