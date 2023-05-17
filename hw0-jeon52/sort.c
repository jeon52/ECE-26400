#include "sort.h"

#ifdef ASCENDING
void ssort(int * arr, int size) 
{
	//local variables
	int temp; //integer data type variable for temporary storage
	int loop; //integer data type variable for count of loops
	int loop2; //integer data type variable for count of second loop
	int smallest; //integer data type variable for smallest value in the array
	int count; //integer data type variable for capturing the location of the smallest

	//Statements
	smallest = * arr; //intializing the first value as the smallest. 
	for (loop = 0; loop <= (size - 2); loop++) //this loop keeps track on the number of sorted list
	{
		smallest = * (arr + loop); //update the initial smallest value
		count = loop; //initialization
		for (loop2 = loop + 1; loop2 < size; loop2++) //this loop updates the smallest value in the array 
		{
			if (smallest > * (arr + loop2))
			{
				smallest = * (arr + loop2);
				count = loop2;
			}
		}
		temp = * (arr + loop); //exchanging/sorting values
		* (arr + loop) = smallest;
		* (arr + count) = temp;
	}
return;
}

#else //Descending
void ssort(int * arr, int size) 
{
	//local variables
	int temp; //integer data type variable for temporary storage
	int loop; //integer data type variable for count of loops
	int loop2; //integer data type variable for count of second loop
	int largest; //integer data type variable for largest value in the array
	int count; //integer data type variable for capturing the location of the smallest

	//Statements
	largest = * arr; //intializing the first value as the largest. 
	for (loop = 0; loop <= (size - 2); loop++) //this loop keeps track on the number of sorted list
	{
		largest = * (arr + loop); //update the initial largest value
		count = loop; //initialization
		for (loop2 = loop + 1; loop2 < size; loop2++) //this loop updates the largest value in the array 
		{
			if (largest < * (arr + loop2))
			{
				largest = * (arr + loop2);
				count = loop2;
			}
		}
		temp = * (arr + loop); //exchanging values 
		* (arr + loop) = largest;
		* (arr + count) = temp;
	}
return;
}
#endif
