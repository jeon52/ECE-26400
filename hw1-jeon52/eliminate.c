#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
void eliminate(int n, int k)
{
  //Local Variables
  int count; //Integer data type variable for counting loops
  int numberofelim; //Integer data type variable for the number of eliminated arrays
  int indexnumber; //Integer data type variable for indexnumber of the array

  //Statements
  int * arr = malloc(sizeof(* arr) * n); // allocate an array of n elements
  if (arr == NULL)   // check whether memory allocation succeeds. If allocation fails, stop
  {
    fprintf(stderr, "malloc fail\n");
    return;
  }

  indexnumber = 0;
  while(indexnumber < n)
  {
    *(arr + indexnumber) = 1;
    indexnumber++;
  }

  indexnumber = 0; //initialization of indexnumber as 0 
  numberofelim = 0; //initialization of number of eliminated arrays as 0 
  count = 1;
  while (numberofelim != (n - 1))
  {
    if (count == k)
    {
      *(arr + indexnumber) = 0; //eliminate the following array 
      count = 0; //reset count
      numberofelim++; //increase the number of eliminated array
      printf("%d\n", indexnumber);
    }

    indexnumber++;
    if (indexnumber != n)
    {
      while(*(arr + indexnumber) == 0)
      {
        indexnumber++;
        if (indexnumber == n)
        {
          indexnumber = 0;
        }
      }
    }
    else //indexnumber = n after increase
    {
      indexnumber = 0;
      while(*(arr + indexnumber) == 0)
      {
        indexnumber++;
      }
    }
    count++;
  } 

  indexnumber = 0; //resetting the indexnumber to initial
  while(*(arr + indexnumber) == 0) //find the location of the indexnumber where the array has not been eliminated. 
  {
    indexnumber++;
  }
  printf("%d\n", indexnumber);
  free (arr);  // release the memory of the array
  return;
}
#endif
