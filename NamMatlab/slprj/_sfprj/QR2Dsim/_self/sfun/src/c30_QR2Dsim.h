#ifndef __c30_QR2Dsim_h__
#define __c30_QR2Dsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_QR2DsimInstanceStruct
#define typedef_SFc30_QR2DsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_QR2Dsim;
} SFc30_QR2DsimInstanceStruct;

#endif                                 /*typedef_SFc30_QR2DsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_QR2Dsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c30_QR2Dsim_get_check_sum(mxArray *plhs[]);
extern void c30_QR2Dsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
