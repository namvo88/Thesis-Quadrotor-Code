/* Include files */

#include "QR2Dsim_sfun.h"
#include "QR2Dsim_sfun_debug_macros.h"
#include "c7_QR2Dsim.h"
#include "c8_QR2Dsim.h"
#include "c9_QR2Dsim.h"
#include "c11_QR2Dsim.h"
#include "c12_QR2Dsim.h"
#include "c13_QR2Dsim.h"
#include "c14_QR2Dsim.h"
#include "c15_QR2Dsim.h"
#include "c17_QR2Dsim.h"
#include "c20_QR2Dsim.h"
#include "c22_QR2Dsim.h"
#include "c23_QR2Dsim.h"
#include "c24_QR2Dsim.h"
#include "c25_QR2Dsim.h"
#include "c26_QR2Dsim.h"
#include "c27_QR2Dsim.h"
#include "c28_QR2Dsim.h"
#include "c29_QR2Dsim.h"
#include "c30_QR2Dsim.h"
#include "c31_QR2Dsim.h"
#include "c32_QR2Dsim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QR2DsimMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void QR2Dsim_initializer(void)
{
}

void QR2Dsim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_QR2Dsim_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==7) {
    c7_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==32) {
    c32_QR2Dsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_QR2Dsim_process_check_sum_call( int nlhs, mxArray * plhs[], int
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3932979232U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1535672909U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(573342010U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(400519242U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3991638573U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1833161177U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(614152137U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2862497680U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 7:
        {
          extern void sf_c7_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c7_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c8_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c9_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c11_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c12_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c13_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c14_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c15_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c17_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c20_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c22_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c23_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c24_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c25_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c26_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c27_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c28_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c29_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c30_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c31_QR2Dsim_get_check_sum(plhs);
          break;
        }

       case 32:
        {
          extern void sf_c32_QR2Dsim_get_check_sum(mxArray *plhs[]);
          sf_c32_QR2Dsim_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1896439755U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(581926696U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3539775919U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2241745589U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QR2Dsim_autoinheritance_info( int nlhs, mxArray * plhs[], int
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
          extern mxArray *sf_c7_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c7_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "YVRG2W0ommaMw7Vp6YiTgD") == 0) {
          extern mxArray *sf_c8_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c8_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
          extern mxArray *sf_c9_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c9_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "DYNI7M6AXfjayNGcxoZeZE") == 0) {
          extern mxArray *sf_c11_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c11_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "LNnM0QnAvlVArKn1T5VrgG") == 0) {
          extern mxArray *sf_c12_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c12_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "KJW0a06Qzm6uXFKwTBut6") == 0) {
          extern mxArray *sf_c13_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c13_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
          extern mxArray *sf_c14_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c14_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "XE0UzH1xSoNiyjuupQ50rB") == 0) {
          extern mxArray *sf_c15_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c15_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "koZV9gpTVk2tf9BAfSyrFB") == 0) {
          extern mxArray *sf_c17_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c17_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "7pdsIN0pB5iYmJ4qoxjsRB") == 0) {
          extern mxArray *sf_c20_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c20_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "umTfsP2JVkPamggh6ppIAB") == 0) {
          extern mxArray *sf_c22_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c22_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "tJaXHGp0g3AsQX61QVa2jC") == 0) {
          extern mxArray *sf_c23_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c23_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "R5l3DC8Wj6XVPFowYZX7zC") == 0) {
          extern mxArray *sf_c24_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c24_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
          extern mxArray *sf_c25_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c25_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "rSaPyzSv2TQVl2ExleYRXB") == 0) {
          extern mxArray *sf_c26_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c26_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "kFvg6pkEDHAcjswAzNrDKG") == 0) {
          extern mxArray *sf_c27_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c27_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "WBdP6R149RdycZbAMYQH0D") == 0) {
          extern mxArray *sf_c28_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c28_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 29:
      {
        if (strcmp(aiChksum, "S5W2QdE1rF6lIEahi8dkRG") == 0) {
          extern mxArray *sf_c29_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c29_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "q2CqQe92rdVzXTlgmCJdpB") == 0) {
          extern mxArray *sf_c30_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c30_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "T5XyUBGgYcqzNknuqehrqB") == 0) {
          extern mxArray *sf_c31_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c31_QR2Dsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 32:
      {
        if (strcmp(aiChksum, "HsMJffzVhUCgknUkPrPba") == 0) {
          extern mxArray *sf_c32_QR2Dsim_get_autoinheritance_info(void);
          plhs[0] = sf_c32_QR2Dsim_get_autoinheritance_info();
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

unsigned int sf_QR2Dsim_get_eml_resolved_functions_info( int nlhs, mxArray *
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
        extern const mxArray *sf_c7_QR2Dsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_QR2Dsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_QR2Dsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray *sf_c23_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray *sf_c24_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray *sf_c25_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray *sf_c26_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray *sf_c27_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray *sf_c28_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray *sf_c29_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray *sf_c30_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray *sf_c31_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_QR2Dsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 32:
      {
        extern const mxArray *sf_c32_QR2Dsim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c32_QR2Dsim_get_eml_resolved_functions_info();
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

unsigned int sf_QR2Dsim_third_party_uses_info( int nlhs, mxArray * plhs[], int
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
          extern mxArray *sf_c7_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c7_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "bEe1HxTpYJN6PWCsAxFomC") == 0) {
          extern mxArray *sf_c8_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c8_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c9_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c9_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Jl2lwfkNE094G3KnRtg8AB") == 0) {
          extern mxArray *sf_c11_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c11_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3DeAe7C3wpw3PJdKGpTuhC") == 0) {
          extern mxArray *sf_c12_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c12_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c13_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c13_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c14_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c14_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c15_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c15_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "rND7nIzQLBNfTHSQ2BAZkD") == 0) {
          extern mxArray *sf_c17_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c17_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "LhZo4IwYZJcbqEkHHCnI2") == 0) {
          extern mxArray *sf_c20_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c20_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "daXPARzSBKqy9WBAGSnxV") == 0) {
          extern mxArray *sf_c22_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c22_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "kjOlkxjhUEHXezAj0Wyr6") == 0) {
          extern mxArray *sf_c23_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c23_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "vTKiRwRbg6ybhdyCZZAMrB") == 0) {
          extern mxArray *sf_c24_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c24_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c25_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c25_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "nVARRS0Y25NNuFHSQMNhEG") == 0) {
          extern mxArray *sf_c26_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c26_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "zQo4rdINUamZX8VbEUcljB") == 0) {
          extern mxArray *sf_c27_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c27_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "sMILXmDeXfyBVRLDOHDfy") == 0) {
          extern mxArray *sf_c28_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c28_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "w3NHdOk1NHZaFRKoFfb0DH") == 0) {
          extern mxArray *sf_c29_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c29_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "ckEYUW0PQXLSZxjIAFietG") == 0) {
          extern mxArray *sf_c30_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c30_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "Qy0xF8EFVTA43oMIRadA7G") == 0) {
          extern mxArray *sf_c31_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c31_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "3gB0wwUxOwCpskj1T88SwD") == 0) {
          extern mxArray *sf_c32_QR2Dsim_third_party_uses_info(void);
          plhs[0] = sf_c32_QR2Dsim_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_QR2Dsim_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
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
          extern mxArray *sf_c7_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "bEe1HxTpYJN6PWCsAxFomC") == 0) {
          extern mxArray *sf_c8_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c9_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Jl2lwfkNE094G3KnRtg8AB") == 0) {
          extern mxArray *sf_c11_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3DeAe7C3wpw3PJdKGpTuhC") == 0) {
          extern mxArray *sf_c12_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c13_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c14_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c15_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "rND7nIzQLBNfTHSQ2BAZkD") == 0) {
          extern mxArray *sf_c17_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "LhZo4IwYZJcbqEkHHCnI2") == 0) {
          extern mxArray *sf_c20_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "daXPARzSBKqy9WBAGSnxV") == 0) {
          extern mxArray *sf_c22_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "kjOlkxjhUEHXezAj0Wyr6") == 0) {
          extern mxArray *sf_c23_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c23_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "vTKiRwRbg6ybhdyCZZAMrB") == 0) {
          extern mxArray *sf_c24_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c24_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c25_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c25_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "nVARRS0Y25NNuFHSQMNhEG") == 0) {
          extern mxArray *sf_c26_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c26_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "zQo4rdINUamZX8VbEUcljB") == 0) {
          extern mxArray *sf_c27_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c27_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "sMILXmDeXfyBVRLDOHDfy") == 0) {
          extern mxArray *sf_c28_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c28_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "w3NHdOk1NHZaFRKoFfb0DH") == 0) {
          extern mxArray *sf_c29_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c29_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "ckEYUW0PQXLSZxjIAFietG") == 0) {
          extern mxArray *sf_c30_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "Qy0xF8EFVTA43oMIRadA7G") == 0) {
          extern mxArray *sf_c31_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "3gB0wwUxOwCpskj1T88SwD") == 0) {
          extern mxArray *sf_c32_QR2Dsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c32_QR2Dsim_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void QR2Dsim_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _QR2DsimMachineNumber_ = sf_debug_initialize_machine(debugInstance,"QR2Dsim",
    "sfun",0,21,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_QR2DsimMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_QR2DsimMachineNumber_,0);
}

void QR2Dsim_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_QR2Dsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("QR2Dsim",
      "QR2Dsim");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_QR2Dsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}