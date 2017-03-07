#ifndef __c13_QRsim_h__
#define __c13_QRsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sMB5GaXc40ozYzvPFeCX3Q
#define struct_sMB5GaXc40ozYzvPFeCX3Q

struct sMB5GaXc40ozYzvPFeCX3Q
{
  int32_T dummy;
};

#endif                                 /*struct_sMB5GaXc40ozYzvPFeCX3Q*/

#ifndef typedef_c13_coder_internal_cell_2
#define typedef_c13_coder_internal_cell_2

typedef struct sMB5GaXc40ozYzvPFeCX3Q c13_coder_internal_cell_2;

#endif                                 /*typedef_c13_coder_internal_cell_2*/

#ifndef typedef_SFc13_QRsimInstanceStruct
#define typedef_SFc13_QRsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_QRsim;
} SFc13_QRsimInstanceStruct;

#endif                                 /*typedef_SFc13_QRsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_QRsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_QRsim_get_check_sum(mxArray *plhs[]);
extern void c13_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
