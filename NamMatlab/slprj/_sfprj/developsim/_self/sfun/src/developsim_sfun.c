/* Include files */

#include "developsim_sfun.h"
#include "developsim_sfun_debug_macros.h"
#include "c1_developsim.h"
#include "c2_developsim.h"
#include "c3_developsim.h"
#include "c4_developsim.h"
#include "c5_developsim.h"
#include "c6_developsim.h"
#include "c7_developsim.h"
#include "c8_developsim.h"
#include "c9_developsim.h"
#include "c10_developsim.h"
#include "c11_developsim.h"
#include "c12_developsim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _developsimMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void developsim_initializer(void)
{
}

void developsim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_developsim_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_developsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_developsim_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(484345159U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4052821985U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1730823118U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(916281477U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3824826540U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3267458626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2037249668U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(136676541U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_developsim_get_check_sum(mxArray *plhs[]);
          sf_c1_developsim_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_developsim_get_check_sum(mxArray *plhs[]);
          sf_c2_developsim_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_developsim_get_check_sum(mxArray *plhs[]);
          sf_c3_developsim_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_developsim_get_check_sum(mxArray *plhs[]);
          sf_c4_developsim_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_developsim_get_check_sum(mxArray *plhs[]);
          sf_c5_developsim_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_developsim_get_check_sum(mxArray *plhs[]);
          sf_c6_developsim_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_developsim_get_check_sum(mxArray *plhs[]);
          sf_c7_developsim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_developsim_get_check_sum(mxArray *plhs[]);
          sf_c8_developsim_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_developsim_get_check_sum(mxArray *plhs[]);
          sf_c9_developsim_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_developsim_get_check_sum(mxArray *plhs[]);
          sf_c10_developsim_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_developsim_get_check_sum(mxArray *plhs[]);
          sf_c11_developsim_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_developsim_get_check_sum(mxArray *plhs[]);
          sf_c12_developsim_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1979278144U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3971298062U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1320798666U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2637726819U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_developsim_autoinheritance_info( int nlhs, mxArray * plhs[], int
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
        if (strcmp(aiChksum, "DJjOuyW5VNW7cqerm6jPCC") == 0) {
          extern mxArray *sf_c1_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c1_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "pIm2BFZNhZ0Ri885mUAkCH") == 0) {
          extern mxArray *sf_c2_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c2_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "yKqTNDAf7eBqwJm5Nnp39F") == 0) {
          extern mxArray *sf_c3_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c3_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "KJW0a06Qzm6uXFKwTBut6") == 0) {
          extern mxArray *sf_c4_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c4_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "yKqTNDAf7eBqwJm5Nnp39F") == 0) {
          extern mxArray *sf_c5_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c5_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "XE0UzH1xSoNiyjuupQ50rB") == 0) {
          extern mxArray *sf_c6_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c6_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "KJW0a06Qzm6uXFKwTBut6") == 0) {
          extern mxArray *sf_c7_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c7_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "ToVYVlH9MCPFjCBpDNpGy") == 0) {
          extern mxArray *sf_c8_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c8_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "Yb2340o0Th03RdfNNWKBoE") == 0) {
          extern mxArray *sf_c9_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c9_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Po0wJcHQ5BshxSIAeahMoE") == 0) {
          extern mxArray *sf_c10_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c10_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "daoeJafIg1hFbfD9yKt2OH") == 0) {
          extern mxArray *sf_c11_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c11_developsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "k3dHF4QLp4aOba2LrLFnJD") == 0) {
          extern mxArray *sf_c12_developsim_get_autoinheritance_info(void);
          plhs[0] = sf_c12_developsim_get_autoinheritance_info();
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

unsigned int sf_developsim_get_eml_resolved_functions_info( int nlhs, mxArray *
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
        extern const mxArray *sf_c1_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_developsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_developsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_developsim_get_eml_resolved_functions_info();
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

unsigned int sf_developsim_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "9uiZrMBIXzk9c1mO3CPuID") == 0) {
          extern mxArray *sf_c1_developsim_third_party_uses_info(void);
          plhs[0] = sf_c1_developsim_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "tS1TX0L5S9BViQGZmJEXg") == 0) {
          extern mxArray *sf_c2_developsim_third_party_uses_info(void);
          plhs[0] = sf_c2_developsim_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sf4oErASUjHDiTLbFEY7rB") == 0) {
          extern mxArray *sf_c3_developsim_third_party_uses_info(void);
          plhs[0] = sf_c3_developsim_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c4_developsim_third_party_uses_info(void);
          plhs[0] = sf_c4_developsim_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sf4oErASUjHDiTLbFEY7rB") == 0) {
          extern mxArray *sf_c5_developsim_third_party_uses_info(void);
          plhs[0] = sf_c5_developsim_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c6_developsim_third_party_uses_info(void);
          plhs[0] = sf_c6_developsim_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c7_developsim_third_party_uses_info(void);
          plhs[0] = sf_c7_developsim_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sqjYtjXr1EoFOzitj8rqEG") == 0) {
          extern mxArray *sf_c8_developsim_third_party_uses_info(void);
          plhs[0] = sf_c8_developsim_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "DPkHPUApqpUnAItu89y4gD") == 0) {
          extern mxArray *sf_c9_developsim_third_party_uses_info(void);
          plhs[0] = sf_c9_developsim_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "HkNVqUqRXJmMSAZAYDWI5G") == 0) {
          extern mxArray *sf_c10_developsim_third_party_uses_info(void);
          plhs[0] = sf_c10_developsim_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "pWMmjLX4lYAxgwvRqxSX9E") == 0) {
          extern mxArray *sf_c11_developsim_third_party_uses_info(void);
          plhs[0] = sf_c11_developsim_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "UxmdhIdKmLTrJ28ZhC0V1G") == 0) {
          extern mxArray *sf_c12_developsim_third_party_uses_info(void);
          plhs[0] = sf_c12_developsim_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_developsim_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "9uiZrMBIXzk9c1mO3CPuID") == 0) {
          extern mxArray *sf_c1_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "tS1TX0L5S9BViQGZmJEXg") == 0) {
          extern mxArray *sf_c2_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sf4oErASUjHDiTLbFEY7rB") == 0) {
          extern mxArray *sf_c3_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c4_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sf4oErASUjHDiTLbFEY7rB") == 0) {
          extern mxArray *sf_c5_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c6_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c7_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sqjYtjXr1EoFOzitj8rqEG") == 0) {
          extern mxArray *sf_c8_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "DPkHPUApqpUnAItu89y4gD") == 0) {
          extern mxArray *sf_c9_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "HkNVqUqRXJmMSAZAYDWI5G") == 0) {
          extern mxArray *sf_c10_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "pWMmjLX4lYAxgwvRqxSX9E") == 0) {
          extern mxArray *sf_c11_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "UxmdhIdKmLTrJ28ZhC0V1G") == 0) {
          extern mxArray *sf_c12_developsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_developsim_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void developsim_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _developsimMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "developsim","sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_developsimMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_developsimMachineNumber_,0);
}

void developsim_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_developsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("developsim",
      "developsim");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_developsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
