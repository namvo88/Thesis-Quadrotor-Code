#ifndef __c29_QRsim_h__
#define __c29_QRsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc29_QRsimInstanceStruct
#define typedef_SFc29_QRsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c29_sfEvent;
  boolean_T c29_isStable;
  boolean_T c29_doneDoubleBufferReInit;
  uint8_T c29_is_active_c29_QRsim;
} SFc29_QRsimInstanceStruct;

#endif                                 /*typedef_SFc29_QRsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c29_QRsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c29_QRsim_get_check_sum(mxArray *plhs[]);
extern void c29_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
