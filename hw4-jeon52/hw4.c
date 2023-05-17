// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
  int ret = 0;
  int bin = 0; //temporary storage space to get values from fscanf
  FILE * fptr = fopen(filename, "r");
   if (fptr == NULL)
    {
      return (-1);
    }
  
  while (fscanf(fptr, "%d", &bin) != EOF)
  {
    ret++;
  }

  // remember to fclose if fopen succeeds
  fclose(fptr);
  return(ret);
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  int i = 0;
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
  {
    return false;
  }


  while (fscanf(fptr, "%d", &intArr[i]))
  {
    if (i > size - 1)
    {
      break;
    }
    i++;
  }

  if (i != size)
  {
    return false;
  }
  else
  {
    fclose(fptr);
    return true;
  }
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
const int * ptr1 = (const int *) p1;
const int * ptr2 = (const int *) p2;
int val1 = * ptr1;
int val2 = * ptr2;
if (val1 < val2) 
{ 
  return -1; 
}
if (val1 == val2) 
{
  return 0; 
}
return 1;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  int i = 0;
  FILE * fptr = fopen(filename, "w");
  if (fptr == NULL)
  {
    return false;
  }
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  while (i < size)
  {
    fprintf(fptr, "%d\n", intArr[i]);
    i++;
  }

  // fclose and return true
  fclose(fptr);
  return(true);
}
#endif

