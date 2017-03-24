/* Include files */

#include "QRsim_sfun.h"
#include "QRsim_sfun_debug_macros.h"
#include "c1_QRsim.h"
#include "c2_QRsim.h"
#include "c3_QRsim.h"
#include "c4_QRsim.h"
#include "c5_QRsim.h"
#include "c6_QRsim.h"
#include "c7_QRsim.h"
#include "c8_QRsim.h"
#include "c9_QRsim.h"
#include "c10_QRsim.h"
#include "c11_QRsim.h"
#include "c12_QRsim.h"
#include "c13_QRsim.h"
#include "c14_QRsim.h"
#include "c15_QRsim.h"
#include "c16_QRsim.h"
#include "c17_QRsim.h"
#include "c18_QRsim.h"
<<<<<<< HEAD
#include "c19_QRsim.h"
=======
>>>>>>> developErrorAngularVelocity
#include "c20_QRsim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QRsimMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void QRsim_initializer(void)
{
}

void QRsim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_QRsim_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

<<<<<<< HEAD
  if (chartFileNumber==19) {
    c19_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

=======
>>>>>>> developErrorAngularVelocity
  if (chartFileNumber==20) {
    c20_QRsim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_QRsim_process_check_sum_call( int nlhs, mxArray * plhs[], int
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1623234187U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1684837124U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(442540559U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1785824120U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
<<<<<<< HEAD
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(618174246U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1202421632U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2587932227U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1019231470U);
=======
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(72021423U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(367679022U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3089598308U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3906796078U);
>>>>>>> developErrorAngularVelocity
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c1_QRsim_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c2_QRsim_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c3_QRsim_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c4_QRsim_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c5_QRsim_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c6_QRsim_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c7_QRsim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c8_QRsim_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c9_QRsim_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c10_QRsim_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c11_QRsim_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c12_QRsim_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c13_QRsim_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c14_QRsim_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c15_QRsim_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c16_QRsim_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c17_QRsim_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c18_QRsim_get_check_sum(plhs);
          break;
        }

<<<<<<< HEAD
       case 19:
        {
          extern void sf_c19_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c19_QRsim_get_check_sum(plhs);
          break;
        }

=======
>>>>>>> developErrorAngularVelocity
       case 20:
        {
          extern void sf_c20_QRsim_get_check_sum(mxArray *plhs[]);
          sf_c20_QRsim_get_check_sum(plhs);
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
<<<<<<< HEAD
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(637548817U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3982588726U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2540277369U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2811128320U);
=======
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(806337758U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3625033391U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(157663528U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1345463290U);
>>>>>>> developErrorAngularVelocity
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QRsim_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "kpxX2wnhj6kPKBNuj8kCxF") == 0) {
          extern mxArray *sf_c1_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c1_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "Guqa1A5ojhbuQIwbZENkrC") == 0) {
=======
        if (strcmp(aiChksum, "q2CqQe92rdVzXTlgmCJdpB") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c2_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c2_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "6uhouoROx8vzRVp6pApgCE") == 0) {
=======
        if (strcmp(aiChksum, "e3QD7bg9ImFj4TkrkmCvwD") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c3_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c3_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "KJW0a06Qzm6uXFKwTBut6") == 0) {
          extern mxArray *sf_c4_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c4_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "K9ui59ddFLFeQX7s8eEri") == 0) {
=======
        if (strcmp(aiChksum, "0gVztOl6bY4pn06vHipu3D") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c5_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c5_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "XE0UzH1xSoNiyjuupQ50rB") == 0) {
          extern mxArray *sf_c6_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c6_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
=======
        if (strcmp(aiChksum, "fOPTWL7bXp7yHxE20LXTCF") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c7_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c7_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "ToVYVlH9MCPFjCBpDNpGy") == 0) {
=======
        if (strcmp(aiChksum, "Yy0W3THrOD9uS9dWolN2dC") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c8_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c8_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "Yb2340o0Th03RdfNNWKBoE") == 0) {
=======
        if (strcmp(aiChksum, "unB6Ok083ujEdpPh5Oox9D") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c9_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c9_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "yKgYgJuXpg8WZJa1YMEvjB") == 0) {
          extern mxArray *sf_c10_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c10_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "daoeJafIg1hFbfD9yKt2OH") == 0) {
=======
        if (strcmp(aiChksum, "GBO8dKuO9MMCmbqBu6JeBE") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c11_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c11_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "LNnM0QnAvlVArKn1T5VrgG") == 0) {
          extern mxArray *sf_c12_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c12_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "d1Re7gAfZivS1IxfXG0JMH") == 0) {
=======
        if (strcmp(aiChksum, "DeDS61mwAqCGDMgUWF5kH") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c13_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c13_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "Yb2340o0Th03RdfNNWKBoE") == 0) {
=======
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c14_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c14_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "KJW0a06Qzm6uXFKwTBut6") == 0) {
          extern mxArray *sf_c15_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c15_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "d1Re7gAfZivS1IxfXG0JMH") == 0) {
=======
        if (strcmp(aiChksum, "hwuV911QRLnaYzh0oISSH") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c16_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c16_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "HUEj4L4IBqQ9QNVzDJBLzB") == 0) {
=======
        if (strcmp(aiChksum, "koZV9gpTVk2tf9BAfSyrFB") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c17_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c17_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "OkOaE7PIG6hStSXjKfx8dC") == 0) {
          extern mxArray *sf_c18_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c18_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

<<<<<<< HEAD
     case 19:
      {
        if (strcmp(aiChksum, "KJW0a06Qzm6uXFKwTBut6") == 0) {
          extern mxArray *sf_c19_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c19_QRsim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "ULzsTicfXEgDNGqubyEAb") == 0) {
=======
     case 20:
      {
        if (strcmp(aiChksum, "xaNOrYffsWwIZTSFjQvxcH") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c20_QRsim_get_autoinheritance_info(void);
          plhs[0] = sf_c20_QRsim_get_autoinheritance_info();
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

unsigned int sf_QRsim_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

<<<<<<< HEAD
     case 19:
      {
        extern const mxArray *sf_c19_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_QRsim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

=======
>>>>>>> developErrorAngularVelocity
     case 20:
      {
        extern const mxArray *sf_c20_QRsim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_QRsim_get_eml_resolved_functions_info();
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

unsigned int sf_QRsim_third_party_uses_info( int nlhs, mxArray * plhs[], int
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
<<<<<<< HEAD
        if (strcmp(tpChksum, "9uiZrMBIXzk9c1mO3CPuID") == 0) {
=======
        if (strcmp(tpChksum, "jC4JUoXphJ4BgYyuu3Ok6") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c1_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c1_QRsim_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "16clhUYxhnHQYLKaOrnvKF") == 0) {
=======
        if (strcmp(tpChksum, "ckEYUW0PQXLSZxjIAFietG") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c2_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c2_QRsim_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "9YkhpdbfueXfrLzNfDCo6F") == 0) {
=======
        if (strcmp(tpChksum, "Pw0ZTWjpl3e1PUcwABpmJC") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c3_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c3_QRsim_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c4_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c4_QRsim_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "IFMCcRpINhqNYKUUq3z4O") == 0) {
=======
        if (strcmp(tpChksum, "Xm8g1Gf7YbhQk71BryHoIH") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c5_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c5_QRsim_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c6_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c6_QRsim_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
=======
        if (strcmp(tpChksum, "UjSRlyz2gmSyzAb9WXg4kF") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c7_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c7_QRsim_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "sqjYtjXr1EoFOzitj8rqEG") == 0) {
=======
        if (strcmp(tpChksum, "A0vZR1HzgANzIAOSkik6cD") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c8_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c8_QRsim_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "Eepk4XO5TUYL950TJLhgBD") == 0) {
=======
        if (strcmp(tpChksum, "8e3DSPRioc2UAafNk6DuzB") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c9_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c9_QRsim_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "QuXeb76Hw6ybYUvYaUWRbB") == 0) {
          extern mxArray *sf_c10_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c10_QRsim_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "YAC4FvAf5FLvHoYw2ExpQC") == 0) {
=======
        if (strcmp(tpChksum, "ZdPqCgH04eRlZknJXZ3ITC") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c11_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c11_QRsim_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3DeAe7C3wpw3PJdKGpTuhC") == 0) {
          extern mxArray *sf_c12_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c12_QRsim_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "lzUjFRIZ7vGzn9QGQzxgHH") == 0) {
=======
        if (strcmp(tpChksum, "Na5piELXZly8g0Jak6tH9B") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c13_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c13_QRsim_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "Eepk4XO5TUYL950TJLhgBD") == 0) {
=======
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c14_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c14_QRsim_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c15_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c15_QRsim_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "lzUjFRIZ7vGzn9QGQzxgHH") == 0) {
=======
        if (strcmp(tpChksum, "1oVMqUtTvZjNFmQW2uHhwE") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c16_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c16_QRsim_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "1d5KOMYPWDYeK19lX5AcOC") == 0) {
=======
        if (strcmp(tpChksum, "rND7nIzQLBNfTHSQ2BAZkD") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c17_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c17_QRsim_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c18_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c18_QRsim_third_party_uses_info();
          break;
        }
      }

<<<<<<< HEAD
     case 19:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c19_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c19_QRsim_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "QHO9Vjm8ylvnGXlbWUf1UC") == 0) {
=======
     case 20:
      {
        if (strcmp(tpChksum, "BICTXeL6icsdBQ1PtnhyoB") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c20_QRsim_third_party_uses_info(void);
          plhs[0] = sf_c20_QRsim_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_QRsim_updateBuildInfo_args_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
<<<<<<< HEAD
        if (strcmp(tpChksum, "9uiZrMBIXzk9c1mO3CPuID") == 0) {
=======
        if (strcmp(tpChksum, "jC4JUoXphJ4BgYyuu3Ok6") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c1_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "16clhUYxhnHQYLKaOrnvKF") == 0) {
=======
        if (strcmp(tpChksum, "ckEYUW0PQXLSZxjIAFietG") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c2_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "9YkhpdbfueXfrLzNfDCo6F") == 0) {
=======
        if (strcmp(tpChksum, "Pw0ZTWjpl3e1PUcwABpmJC") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c3_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c4_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "IFMCcRpINhqNYKUUq3z4O") == 0) {
=======
        if (strcmp(tpChksum, "Xm8g1Gf7YbhQk71BryHoIH") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c5_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "5fG48LlpigQQ6lDSldJr8E") == 0) {
          extern mxArray *sf_c6_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
=======
        if (strcmp(tpChksum, "UjSRlyz2gmSyzAb9WXg4kF") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c7_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "sqjYtjXr1EoFOzitj8rqEG") == 0) {
=======
        if (strcmp(tpChksum, "A0vZR1HzgANzIAOSkik6cD") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c8_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "Eepk4XO5TUYL950TJLhgBD") == 0) {
=======
        if (strcmp(tpChksum, "8e3DSPRioc2UAafNk6DuzB") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c9_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "QuXeb76Hw6ybYUvYaUWRbB") == 0) {
          extern mxArray *sf_c10_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "YAC4FvAf5FLvHoYw2ExpQC") == 0) {
=======
        if (strcmp(tpChksum, "ZdPqCgH04eRlZknJXZ3ITC") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c11_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3DeAe7C3wpw3PJdKGpTuhC") == 0) {
          extern mxArray *sf_c12_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "lzUjFRIZ7vGzn9QGQzxgHH") == 0) {
=======
        if (strcmp(tpChksum, "Na5piELXZly8g0Jak6tH9B") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c13_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "Eepk4XO5TUYL950TJLhgBD") == 0) {
=======
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c14_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c15_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "lzUjFRIZ7vGzn9QGQzxgHH") == 0) {
=======
        if (strcmp(tpChksum, "1oVMqUtTvZjNFmQW2uHhwE") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c16_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
<<<<<<< HEAD
        if (strcmp(tpChksum, "1d5KOMYPWDYeK19lX5AcOC") == 0) {
=======
        if (strcmp(tpChksum, "rND7nIzQLBNfTHSQ2BAZkD") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c17_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "GfIs82lQvdn1MFOTGXJ1UF") == 0) {
          extern mxArray *sf_c18_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

<<<<<<< HEAD
     case 19:
      {
        if (strcmp(tpChksum, "P5D4fG9U0m1Ji5BX3Zagy") == 0) {
          extern mxArray *sf_c19_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "QHO9Vjm8ylvnGXlbWUf1UC") == 0) {
=======
     case 20:
      {
        if (strcmp(tpChksum, "BICTXeL6icsdBQ1PtnhyoB") == 0) {
>>>>>>> developErrorAngularVelocity
          extern mxArray *sf_c20_QRsim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_QRsim_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void QRsim_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _QRsimMachineNumber_ = sf_debug_initialize_machine(debugInstance,"QRsim",
<<<<<<< HEAD
    "sfun",0,20,0,0,0);
=======
    "sfun",0,19,0,0,0);
>>>>>>> developErrorAngularVelocity
  sf_debug_set_machine_event_thresholds(debugInstance,_QRsimMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_QRsimMachineNumber_,0);
}

void QRsim_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_QRsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("QRsim", "QRsim");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_QRsim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
