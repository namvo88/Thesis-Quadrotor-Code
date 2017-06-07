#ifndef __c41_QRLsim_h__
#define __c41_QRLsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc41_QRLsimInstanceStruct
#define typedef_SFc41_QRLsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c41_sfEvent;
  boolean_T c41_isStable;
  boolean_T c41_doneDoubleBufferReInit;
  uint8_T c41_is_active_c41_QRLsim;
} SFc41_QRLsimInstanceStruct;

#endif                                 /*typedef_SFc41_QRLsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c41_QRLsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c41_QRLsim_get_check_sum(mxArray *plhs[]);
extern void c41_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
