/* Include files */

#include "QRLsim_sfun.h"
#include "QRLsim_sfun_debug_macros.h"
#include "c1_QRLsim.h"
#include "c2_QRLsim.h"
#include "c3_QRLsim.h"
#include "c4_QRLsim.h"
#include "c5_QRLsim.h"
#include "c6_QRLsim.h"
#include "c7_QRLsim.h"
#include "c8_QRLsim.h"
#include "c31_QRLsim.h"
#include "c32_QRLsim.h"
#include "c39_QRLsim.h"
#include "c40_QRLsim.h"
#include "c41_QRLsim.h"
#include "c42_QRLsim.h"
#include "c43_QRLsim.h"
#include "c44_QRLsim.h"
#include "c46_QRLsim.h"
#include "c47_QRLsim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QRLsimMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void QRLsim_initializer(void)
{
}

void QRLsim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_QRLsim_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==32) {
    c32_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==42) {
    c42_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==46) {
    c46_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==47) {
    c47_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_QRLsim_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(97951330U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(284271044U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3507885626U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3749515464U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(973814211U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2634948029U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3399938055U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4127468592U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c1_QRLsim_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c2_QRLsim_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c3_QRLsim_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c4_QRLsim_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c5_QRLsim_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c6_QRLsim_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c7_QRLsim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c8_QRLsim_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c31_QRLsim_get_check_sum(plhs);
          break;
        }

       case 32:
        {
          extern void sf_c32_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c32_QRLsim_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c39_QRLsim_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c40_QRLsim_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c41_QRLsim_get_check_sum(plhs);
          break;
        }

       case 42:
        {
          extern void sf_c42_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c42_QRLsim_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c43_QRLsim_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c44_QRLsim_get_check_sum(plhs);
          break;
        }

       case 46:
        {
          extern void sf_c46_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c46_QRLsim_get_check_sum(plhs);
          break;
        }

       case 47:
        {
          extern void sf_c47_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c47_QRLsim_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2830263200U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3732402237U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1754533477U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1520524656U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QRLsim_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "pJSuLtFl2FiRfa65tm5LdD") == 0) {
          extern mxArray *sf_c1_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c1_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "jXBZygxvoogr6I8uy7nwqF") == 0) {
          extern mxArray *sf_c2_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c2_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "V05NjLCCv1IYLwn8m5cjLB") == 0) {
          extern mxArray *sf_c3_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c3_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "WODvyurqYXOAluqvfmqfYG") == 0) {
          extern mxArray *sf_c4_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c4_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "QO3uZNZxxuUMTcU41ezIID") == 0) {
          extern mxArray *sf_c5_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c5_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "WNQkqzSqcLegKT3zUFH1NG") == 0) {
          extern mxArray *sf_c6_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c6_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "hwuV911QRLnaYzh0oISSH") == 0) {
          extern mxArray *sf_c7_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c7_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "Jjd5kNP6hwSkWAy5XHHKvB") == 0) {
          extern mxArray *sf_c8_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c8_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "7rkn1IORX1FEVmkkgTSoCE") == 0) {
          extern mxArray *sf_c31_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c31_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 32:
      {
        if (strcmp(aiChksum, "JwYOzATQlQY37ZQMlMbrY") == 0) {
          extern mxArray *sf_c32_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c32_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "H0Ya9KEN3k5U24nQ4uSXvB") == 0) {
          extern mxArray *sf_c39_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c39_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "lMe92e3eI2YEJAjOyG4wFC") == 0) {
          extern mxArray *sf_c40_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c40_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "AsuCNCxsUyA2wQUIlCUgqF") == 0) {
          extern mxArray *sf_c41_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c41_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 42:
      {
        if (strcmp(aiChksum, "rSaPyzSv2TQVl2ExleYRXB") == 0) {
          extern mxArray *sf_c42_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c42_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "2YQflrw4zDx2N5QMkTaPgC") == 0) {
          extern mxArray *sf_c43_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c43_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "5ELcTvzGq8pEcErtGTOlxG") == 0) {
          extern mxArray *sf_c44_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c44_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 46:
      {
        if (strcmp(aiChksum, "krM8Y33xFdY4UTEbKBCClE") == 0) {
          extern mxArray *sf_c46_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c46_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 47:
      {
        if (strcmp(aiChksum, "XqUgm1L6ye9zMzQsRgQhlG") == 0) {
          extern mxArray *sf_c47_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c47_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QRLsim_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray *sf_c31_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 32:
      {
        extern const mxArray *sf_c32_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c32_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray *sf_c39_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray *sf_c40_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray *sf_c41_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 42:
      {
        extern const mxArray *sf_c42_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c42_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray *sf_c43_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray *sf_c44_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 46:
      {
        extern const mxArray *sf_c46_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c46_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 47:
      {
        extern const mxArray *sf_c47_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c47_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QRLsim_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "BpfzkAM6oqCK0tEzStBtqC") == 0) {
          extern mxArray *sf_c1_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c1_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "1ZB2974u6Oj65fYhQW3kIC") == 0) {
          extern mxArray *sf_c2_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c2_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "lat0PKJuRTnl0zOxHBNbj") == 0) {
          extern mxArray *sf_c3_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c3_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "J4hmVkgZl6gtnoVxLehffB") == 0) {
          extern mxArray *sf_c4_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c4_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "Wqf9b3zIofah56QjL0JzVH") == 0) {
          extern mxArray *sf_c5_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c5_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "eK2Pd5UzzYlpK4pHydlzV") == 0) {
          extern mxArray *sf_c6_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c6_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "1oVMqUtTvZjNFmQW2uHhwE") == 0) {
          extern mxArray *sf_c7_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c7_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "O0tt6HSb2MqiURUdffQ19G") == 0) {
          extern mxArray *sf_c8_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c8_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "QtSQHKDxTLBPuI0FVEpxOG") == 0) {
          extern mxArray *sf_c31_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c31_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "D4Y0cnZfoYam2H9h5rf9oG") == 0) {
          extern mxArray *sf_c32_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c32_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "L1k8Z35f9IGfDCXSjeWeqC") == 0) {
          extern mxArray *sf_c39_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c39_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "UegtduoJ3SloKaMtNSCjpF") == 0) {
          extern mxArray *sf_c40_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c40_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "8HTr5yjoYTrP77QPkFRLW") == 0) {
          extern mxArray *sf_c41_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c41_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "nVARRS0Y25NNuFHSQMNhEG") == 0) {
          extern mxArray *sf_c42_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c42_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "RzPEIy4sCsfB46mZ8ovIQC") == 0) {
          extern mxArray *sf_c43_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c43_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "mKIMeA4a9X2YewRUtY08eE") == 0) {
          extern mxArray *sf_c44_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c44_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "nYYlsqQqt1ClMp0nvwwJ6E") == 0) {
          extern mxArray *sf_c46_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c46_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "8V3bGfcrc4J4kpUrpIM4CD") == 0) {
          extern mxArray *sf_c47_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c47_QRLsim_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_QRLsim_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "BpfzkAM6oqCK0tEzStBtqC") == 0) {
          extern mxArray *sf_c1_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "1ZB2974u6Oj65fYhQW3kIC") == 0) {
          extern mxArray *sf_c2_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "lat0PKJuRTnl0zOxHBNbj") == 0) {
          extern mxArray *sf_c3_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "J4hmVkgZl6gtnoVxLehffB") == 0) {
          extern mxArray *sf_c4_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "Wqf9b3zIofah56QjL0JzVH") == 0) {
          extern mxArray *sf_c5_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "eK2Pd5UzzYlpK4pHydlzV") == 0) {
          extern mxArray *sf_c6_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "1oVMqUtTvZjNFmQW2uHhwE") == 0) {
          extern mxArray *sf_c7_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "O0tt6HSb2MqiURUdffQ19G") == 0) {
          extern mxArray *sf_c8_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "QtSQHKDxTLBPuI0FVEpxOG") == 0) {
          extern mxArray *sf_c31_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "D4Y0cnZfoYam2H9h5rf9oG") == 0) {
          extern mxArray *sf_c32_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c32_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "L1k8Z35f9IGfDCXSjeWeqC") == 0) {
          extern mxArray *sf_c39_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "UegtduoJ3SloKaMtNSCjpF") == 0) {
          extern mxArray *sf_c40_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c40_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "8HTr5yjoYTrP77QPkFRLW") == 0) {
          extern mxArray *sf_c41_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c41_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "nVARRS0Y25NNuFHSQMNhEG") == 0) {
          extern mxArray *sf_c42_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c42_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "RzPEIy4sCsfB46mZ8ovIQC") == 0) {
          extern mxArray *sf_c43_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "mKIMeA4a9X2YewRUtY08eE") == 0) {
          extern mxArray *sf_c44_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c44_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "nYYlsqQqt1ClMp0nvwwJ6E") == 0) {
          extern mxArray *sf_c46_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c46_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "8V3bGfcrc4J4kpUrpIM4CD") == 0) {
          extern mxArray *sf_c47_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c47_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void QRLsim_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _QRLsimMachineNumber_ = sf_debug_initialize_machine(debugInstance,"QRLsim",
    "sfun",0,18,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_QRLsimMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_QRLsimMachineNumber_,0);
}

void QRLsim_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_QRLsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("QRLsim",
      "QRLsim");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_QRLsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
