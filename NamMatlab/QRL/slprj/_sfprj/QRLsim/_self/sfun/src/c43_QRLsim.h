#ifndef __c43_QRLsim_h__
#define __c43_QRLsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_QRLsimInstanceStruct
#define typedef_SFc43_QRLsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c43_sfEvent;
  boolean_T c43_isStable;
  boolean_T c43_doneDoubleBufferReInit;
  uint8_T c43_is_active_c43_QRLsim;
} SFc43_QRLsimInstanceStruct;

#endif                                 /*typedef_SFc43_QRLsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c43_QRLsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c43_QRLsim_get_check_sum(mxArray *plhs[]);
extern void c43_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
