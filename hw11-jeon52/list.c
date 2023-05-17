#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() { //all this does is making pathLL pointer 
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
	//Allocate and initialize an empty Path linked list
}

void freePaths(PathLL * p) 
{
	PathNode * temp = NULL; 
	PathNode * temp2 = NULL;
	temp = p -> head; 
	while (temp != NULL) 
	{	
		temp2 = temp; 
		temp = temp -> next; //move to the next node
		freeNode(temp2);
	}
	free(p);
	return;
}

PathNode * buildNode(char * path) {
	PathNode * retval = NULL;
	int count; 

	retval = malloc(sizeof(PathNode));
	retval -> next = NULL;

	count = strlen(path);
	retval -> path = malloc(sizeof(char) * (count + 1)); //+1 for the NULL space
	strcpy(retval -> path, path);
	return retval; 
}

void freeNode(PathNode * p) {
	free(p -> path);
	p -> next = NULL;
	free(p);
	return;
}

int turncount(char * path) //helper function for counting turns!
{
	int count = 0; //count number of turns
	int loop = 0; //count loop number
	while (loop < (strlen(path) - 1)) //-1 because we are comparing! 
	{
		if (path[loop] != path[loop + 1])
		{
			count++;
		}
		loop++; //increment
	}
	return count; 
}

bool addNode(PathLL * paths, char * path) 
{
	int pathlen; 
	int count = 0; 
	PathNode * current = NULL;
	PathNode * previous = NULL;
	PathNode * insertnode = NULL;
	current = paths -> head;
	pathlen = strlen(path); //this should be a constant!

	if (paths -> head == NULL) //when its empty
	{
		paths -> head = buildNode(path);
		return true; 
	}

	while(current != NULL)
	{	
		if (count == 0) //when the insert must be done before the first node!! (checking just once!)
		{
			if (strlen(current -> path) > pathlen) //smaller 
			{
				insertnode = buildNode(path); //make this new node!
				insertnode -> next = current; //need to relink
				paths -> head = insertnode; //need to relink the head
				return true; 
			}
			if (strlen(current -> path) == pathlen) //two values are same? next criteria 
			{
				if (turncount(current -> path) > turncount(path)) //number of turns!!
				{
					insertnode = buildNode(path); //make this new node!
					insertnode -> next = current; //need to relink
					paths -> head = insertnode; //need to relink the head
					return true;
				}
				if (turncount(current -> path) == turncount(path)) //number of turns are same? next criteria
				{
					if (strcmp(current -> path, path) > 0) //check alphabetical order 
					{
						insertnode = buildNode(path); //make this new node!
						insertnode -> next = current; //need to relink
						paths -> head = insertnode; //need to relink the head
						return true; //we want current -> path to be smaller than path!! 
					}
				}
			}
		}
		else 
		{
			if (strlen(current -> path) > pathlen) //smaller 
			{
				insertnode = buildNode(path); //make this new node!
				previous -> next = insertnode; //need to relink //this is not possible when 1st node...
				insertnode -> next = current; //need to relink
				return true; 
			}
			if (strlen(current -> path) == pathlen) //two values are same? next criteria 
			{
				if (turncount(current -> path) > turncount(path)) //number of turns!!
				{
					insertnode = buildNode(path); //make this new node!
					previous -> next = insertnode; //need to relink
					insertnode -> next = current; //need to relink
					return true;
				}
				if (turncount(current -> path) == turncount(path)) //number of turns are same? next criteria
				{
					if (strcmp(current -> path, path) > 0) //check alphabetical order 
					{
						insertnode = buildNode(path); //make this new node!
						previous -> next = insertnode; //need to relink
						insertnode -> next = current; //need to relink
						return true; //we want current -> path to be smaller than path!! 
					}
				}
			}
		}
		//None of the criteria is met? move on to the next node and check!!
		previous = current; //previous value is set! (this is after the 1st node)
		current = current -> next; //next 
		count++;
	}
	//put at the end! 
	insertnode = buildNode(path);
	previous -> next = insertnode; 
	return true;
}

bool removeNode(PathLL * paths, char * path)
{
	if (containsNode(paths, path) == true)
	{
		PathNode * temp = NULL;
		PathNode * temp2 = NULL;
		temp = paths -> head;
		while(temp != NULL)
		{
			if ((strcmp(temp -> next -> next -> path, path) == 0)) //find the location of the exact path
			{
				temp = temp -> next; //move 1 before the to be removed node. 
				temp2 = temp; //store this value 
				temp = temp -> next; //move the temp to the node to be removed
				temp2 -> next = temp -> next; //link temp2 and the node next to temp
				freeNode(temp); //remove node
				return true; 
			}
			else
			{
				temp = temp -> next; //incrementation
			}
		} 
	}
	return false; //nothing to remove
	
}

bool containsNode(PathLL * paths, char * path) 
{
	PathNode * temp = NULL;
	temp = paths -> head; 
	while(temp != NULL)
	{
		if (strcmp(temp -> path, path) == 0) //compare the path
		{
			return true; 
		}
		else
		{
			temp = temp -> next; //move to next node
		}
	}
	return false; //the end is reached
}

void printPaths(PathLL * paths, FILE * fptr) {
	PathNode * curr = paths->head;
	int i = 0;
	while (curr != NULL) {
		fprintf(fptr, "Path %2d: %s\n", i, curr->path);
		i++;
		curr = curr->next;
	}
}
