#ifndef __c42_QRLsim_h__
#define __c42_QRLsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc42_QRLsimInstanceStruct
#define typedef_SFc42_QRLsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c42_sfEvent;
  boolean_T c42_isStable;
  boolean_T c42_doneDoubleBufferReInit;
  uint8_T c42_is_active_c42_QRLsim;
} SFc42_QRLsimInstanceStruct;

#endif                                 /*typedef_SFc42_QRLsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c42_QRLsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c42_QRLsim_get_check_sum(mxArray *plhs[]);
extern void c42_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
