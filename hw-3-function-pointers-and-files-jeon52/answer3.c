#include <stdio.h>
#include <stdbool.h>
#include "hw3.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable particial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  //local variables
  int count;

  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  for (count = 0; count < (* intrg).intervals; count++)
  {
    if (count == 0)
    {
      (* intrg).answer = (* intrg).func((* intrg).lowerlimit);
    }
    else
    {
      (* intrg).answer += (* intrg).func((* intrg).lowerlimit + count * ((* intrg).upperlimit - (* intrg).lowerlimit) / (* intrg).intervals);
    }
  }
    (* intrg).answer *= (((* intrg).upperlimit - (* intrg).lowerlimit) / (* intrg).intervals);
    return;
}
 #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  //Local Variables:
  int count;
  // open the input file name for reading
  // if fopen fails, return false
  FILE * fptr = fopen(infilename, "r");
   if (fptr == NULL)
    {
      return false;
    }
  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  Integration intrg;
  int ret = 0;
  ret = fscanf(fptr, "%lf", &intrg.lowerlimit);  
  if (ret != 1)
  {
    fclose(fptr);
    fptr = NULL;
    return false;
  }
  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  ret = 0; 
  ret = fscanf(fptr, "%lf", &intrg.upperlimit); 
  if (ret != 1)
  {
    fclose(fptr);
    fptr = NULL;
    return false;
  }
  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  ret = 0;
  ret = fscanf(fptr, "%d", &intrg.intervals);  
  if (ret != 1)
  {
    fclose(fptr);
    fptr = NULL;
    return false;
  }

  // close the input file
  fclose(fptr);
  fptr = NULL;

  // open the output file for writing
  // if fopen fails, return false
  FILE * fp = fopen(outfilename, "w");
  if (fp == NULL)
    {
      return false;
    }

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
  funcptr funcs[5] = {func1, func2, func3, func4, func5}; //do we need to put func1.c? or func1??

  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
  for (count = 0; count < 5; count++)
  {
    intrg.func = funcs[0 + count];
    integrate(&intrg); 

    ret = 0;
    ret = fprintf(fp, "%lf\n", intrg.answer);
    if (ret < 1)
    {
      fclose(fp);
      fp = NULL; 
      return false;
    }
  }
  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false

  // after going through all functions in funcs
  // close the output file

  // if the function reaches here, return true
  fclose(fp);
  fp = NULL;
  return true;
}
#endif // RUN_INTEGRATE
