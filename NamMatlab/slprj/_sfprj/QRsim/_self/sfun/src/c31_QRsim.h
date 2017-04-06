#ifndef __c31_QRsim_h__
#define __c31_QRsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc31_QRsimInstanceStruct
#define typedef_SFc31_QRsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c31_sfEvent;
  boolean_T c31_isStable;
  boolean_T c31_doneDoubleBufferReInit;
  uint8_T c31_is_active_c31_QRsim;
} SFc31_QRsimInstanceStruct;

#endif                                 /*typedef_SFc31_QRsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c31_QRsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_QRsim_get_check_sum(mxArray *plhs[]);
extern void c31_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
