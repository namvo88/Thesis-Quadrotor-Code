/* Include files */

#include "QRLsim_sfun.h"
#include "QRLsim_sfun_debug_macros.h"
#include "c7_QRLsim.h"
#include "c13_QRLsim.h"
#include "c15_QRLsim.h"
#include "c30_QRLsim.h"
#include "c31_QRLsim.h"
#include "c32_QRLsim.h"
#include "c40_QRLsim.h"
#include "c41_QRLsim.h"
#include "c42_QRLsim.h"
#include "c43_QRLsim.h"
#include "c44_QRLsim.h"
#include "c46_QRLsim.h"
#include "c47_QRLsim.h"
#include "c48_QRLsim.h"

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
  if (chartFileNumber==7) {
    c7_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_QRLsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_QRLsim_method_dispatcher(simstructPtr, method, data);
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

  if (chartFileNumber==48) {
    c48_QRLsim_method_dispatcher(simstructPtr, method, data);
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(22167241U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(467379915U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2490538095U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(365374804U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 7:
        {
          extern void sf_c7_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c7_QRLsim_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c13_QRLsim_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c15_QRLsim_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c30_QRLsim_get_check_sum(plhs);
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

       case 48:
        {
          extern void sf_c48_QRLsim_get_check_sum(mxArray *plhs[]);
          sf_c48_QRLsim_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1504481777U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2094077154U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2307665857U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2530135838U);
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

     case 13:
      {
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
          extern mxArray *sf_c13_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c13_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "XE0UzH1xSoNiyjuupQ50rB") == 0) {
          extern mxArray *sf_c15_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c15_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "q2CqQe92rdVzXTlgmCJdpB") == 0) {
          extern mxArray *sf_c30_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c30_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "T5XyUBGgYcqzNknuqehrqB") == 0) {
          extern mxArray *sf_c31_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c31_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 32:
      {
        if (strcmp(aiChksum, "gU3nFU9ufPORqNAfLSOUkD") == 0) {
          extern mxArray *sf_c32_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c32_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "EDvui38t87jwvXy6ogThYF") == 0) {
          extern mxArray *sf_c40_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c40_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "umTfsP2JVkPamggh6ppIAB") == 0) {
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
        if (strcmp(aiChksum, "tJaXHGp0g3AsQX61QVa2jC") == 0) {
          extern mxArray *sf_c43_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c43_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "R5l3DC8Wj6XVPFowYZX7zC") == 0) {
          extern mxArray *sf_c44_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c44_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 46:
      {
        if (strcmp(aiChksum, "SwfdjqFfd30TAxl6C4iMp") == 0) {
          extern mxArray *sf_c46_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c46_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 47:
      {
        if (strcmp(aiChksum, "nxm0CElSkVHKvzMgtLIRNB") == 0) {
          extern mxArray *sf_c47_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c47_QRLsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 48:
      {
        if (strcmp(aiChksum, "zzNhvphFCYfGjhleEDUc7D") == 0) {
          extern mxArray *sf_c48_QRLsim_get_autoinheritance_info(void);
          plhs[0] = sf_c48_QRLsim_get_autoinheritance_info();
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
     case 7:
      {
        extern const mxArray *sf_c7_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_QRLsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray *sf_c30_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_QRLsim_get_eml_resolved_functions_info();
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

     case 48:
      {
        extern const mxArray *sf_c48_QRLsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c48_QRLsim_get_eml_resolved_functions_info();
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
     case 7:
      {
        if (strcmp(tpChksum, "1oVMqUtTvZjNFmQW2uHhwE") == 0) {
          extern mxArray *sf_c7_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c7_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c13_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c13_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c15_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c15_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "ckEYUW0PQXLSZxjIAFietG") == 0) {
          extern mxArray *sf_c30_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c30_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "Qy0xF8EFVTA43oMIRadA7G") == 0) {
          extern mxArray *sf_c31_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c31_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "vhufjY3TQliyrJJxwjRHWG") == 0) {
          extern mxArray *sf_c32_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c32_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "p0erjV8sfhzGCVMLBDd5RH") == 0) {
          extern mxArray *sf_c40_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c40_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "daXPARzSBKqy9WBAGSnxV") == 0) {
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
        if (strcmp(tpChksum, "kjOlkxjhUEHXezAj0Wyr6") == 0) {
          extern mxArray *sf_c43_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c43_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "vTKiRwRbg6ybhdyCZZAMrB") == 0) {
          extern mxArray *sf_c44_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c44_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "ZEpz2UZaypRyqKErmiBTF") == 0) {
          extern mxArray *sf_c46_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c46_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "42rCzBXAYzjuf3ZL23zk0C") == 0) {
          extern mxArray *sf_c47_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c47_QRLsim_third_party_uses_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "b2MEIFZEwqqISnA3FbHayD") == 0) {
          extern mxArray *sf_c48_QRLsim_third_party_uses_info(void);
          plhs[0] = sf_c48_QRLsim_third_party_uses_info();
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
     case 7:
      {
        if (strcmp(tpChksum, "1oVMqUtTvZjNFmQW2uHhwE") == 0) {
          extern mxArray *sf_c7_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c13_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c15_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "ckEYUW0PQXLSZxjIAFietG") == 0) {
          extern mxArray *sf_c30_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "Qy0xF8EFVTA43oMIRadA7G") == 0) {
          extern mxArray *sf_c31_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "vhufjY3TQliyrJJxwjRHWG") == 0) {
          extern mxArray *sf_c32_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c32_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "p0erjV8sfhzGCVMLBDd5RH") == 0) {
          extern mxArray *sf_c40_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c40_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "daXPARzSBKqy9WBAGSnxV") == 0) {
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
        if (strcmp(tpChksum, "kjOlkxjhUEHXezAj0Wyr6") == 0) {
          extern mxArray *sf_c43_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "vTKiRwRbg6ybhdyCZZAMrB") == 0) {
          extern mxArray *sf_c44_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c44_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "ZEpz2UZaypRyqKErmiBTF") == 0) {
          extern mxArray *sf_c46_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c46_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "42rCzBXAYzjuf3ZL23zk0C") == 0) {
          extern mxArray *sf_c47_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c47_QRLsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "b2MEIFZEwqqISnA3FbHayD") == 0) {
          extern mxArray *sf_c48_QRLsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c48_QRLsim_updateBuildInfo_args_info();
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
    "sfun",0,14,0,0,0);
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
