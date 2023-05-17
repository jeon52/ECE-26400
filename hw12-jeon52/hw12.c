#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calc.h"
#include "stack.c"

int main (int argc, char ** argv) 
{
	if (argc != 2) //because ./hw12 ./inputs/test1
	{
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}
	// open the file to read
  	FILE * fptr;
  	fptr = fopen(argv[1], "r");
  	if (fptr == NULL)
    {
		printf("cannot read input file");
		return EXIT_FAILURE;
    }

	//count number of elements
	int count = 0; 
	float floattemp;
	char chartemp[10];


	while (!feof(fptr)) //count the number!!
	{
		if (fscanf(fptr, "%s", chartemp) > 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	int i = 0; 
	rewind(fptr); //resetting necessary values

	float result; //store the result of your calculation here.
	Stack * head = NULL;
	head = initialize(); //initialization of a header*/
	
	while (i < count)
	{
		if(fscanf(fptr, "%s", chartemp) > 0) //read values
		{	
			floattemp = atof(chartemp);
			if (floattemp != 0) //not an operator 
			{
				push(head, floattemp);
			}
			else
			{	
				result = arithmeticoperation(chartemp, head, fptr);
				if(result == EXIT_FAILURE)
				{
					fclose(fptr);
					freeStack(head, fptr);
					return EXIT_FAILURE;
				}
			}
		}
		else
		{
			fclose(fptr);
			freeStack(head, fptr);
			return EXIT_FAILURE;
		}
		i++;
	}
	//how to account when no more operator can be found?
	int loopcount = 0;
	Node * temp = NULL;
	temp = head -> top;
	while(temp != NULL)
	{
		loopcount++;
		temp  = temp -> next; 
	}
	if (loopcount != 1)
	{
		fclose(fptr);
		freeStack(head, fptr);
		return EXIT_FAILURE;
	}

	fclose(fptr);
	freeStack(head, fptr);
	printf("%f\n", result);
	return EXIT_SUCCESS;
}
