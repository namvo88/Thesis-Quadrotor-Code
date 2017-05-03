#ifndef __c50_QRLsim_h__
#define __c50_QRLsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc50_QRLsimInstanceStruct
#define typedef_SFc50_QRLsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  boolean_T c50_isStable;
  boolean_T c50_doneDoubleBufferReInit;
  uint8_T c50_is_active_c50_QRLsim;
} SFc50_QRLsimInstanceStruct;

#endif                                 /*typedef_SFc50_QRLsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c50_QRLsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c50_QRLsim_get_check_sum(mxArray *plhs[]);
extern void c50_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
