#ifndef __c46_QRLsim_h__
#define __c46_QRLsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc46_QRLsimInstanceStruct
#define typedef_SFc46_QRLsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c46_sfEvent;
  boolean_T c46_isStable;
  boolean_T c46_doneDoubleBufferReInit;
  uint8_T c46_is_active_c46_QRLsim;
} SFc46_QRLsimInstanceStruct;

#endif                                 /*typedef_SFc46_QRLsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c46_QRLsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c46_QRLsim_get_check_sum(mxArray *plhs[]);
extern void c46_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
