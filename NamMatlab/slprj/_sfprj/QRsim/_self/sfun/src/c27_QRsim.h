#ifndef __c27_QRsim_h__
#define __c27_QRsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc27_QRsimInstanceStruct
#define typedef_SFc27_QRsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_QRsim;
} SFc27_QRsimInstanceStruct;

#endif                                 /*typedef_SFc27_QRsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c27_QRsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c27_QRsim_get_check_sum(mxArray *plhs[]);
extern void c27_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
