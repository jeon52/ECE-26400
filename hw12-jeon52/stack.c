
float arithmeticoperation (char * operand, Stack * head, FILE * fptr)
{
	float firstoperand;
	float secondoperand;
	float result;
	
	firstoperand = pop(head, fptr);
	secondoperand = pop(head, fptr);
	
	//43 = +   42 = *    47 = /   45 = -
	if (*operand == 43)
	{
		result = firstoperand + secondoperand;
		push(head, result); 
		return result;
	}
	else if (*operand == 42)
	{
		result = firstoperand * secondoperand;
		push(head, result);
		return result;
	}
	else if (*operand == 47)
	{
		result = secondoperand / firstoperand;
		push(head, result); 
		return result;
	}
	else if (*operand == 45)
	{
		result = secondoperand - firstoperand ;
		push(head, result); 
		return result;
	}
	else
	{
		return EXIT_FAILURE;
	}
}

//adds at the top of the stack //note that the header is not updated!!
Node * addfirst(float val, Node * list)
{
	//Allocate the new node
    Node * newNode = NULL;
	newNode = malloc(sizeof(Node));
    //Set up the value
    newNode -> val = val;
    newNode -> next = list;
    return newNode;
}

//removes at the top of the stack //note that the header is not updated!!
Node * removefirst (Node * list)
{
	if (list == NULL) 
	{
		return NULL; //empty list; nothing to remove
	}

    Node * restofnode = NULL;
	restofnode = list -> next; 
    free(list); //free       
    return restofnode;
}

//create stack (header)
Stack * initialize() 
{
    Stack * head = NULL; 
    head = malloc (sizeof(Stack));
    head -> top = NULL;
    return head;
}

//check if the stack is empty or not
bool isEmpty(Stack * head) 
{
    return head -> top == NULL;
}

//push into the stack
void push(Stack * head, float val) 
{
    head -> top = addfirst(val, head -> top);
}

//peaking into the first value
float peek(Stack * head) {
    if (isEmpty(head)) 
	{
        exit(EXIT_FAILURE);
    }
    
    return head -> top -> val;
}

float pop(Stack * head, FILE * fptr) {
    if (isEmpty(head)) 
	{
		free(head);
		fclose(fptr);
    	exit(EXIT_FAILURE);
    }
    
    float retval = peek(head);
    head -> top = removefirst(head -> top);
    
    return retval;
}

//free stacks
void freeStack(Stack * head, FILE * fptr) 
{
    while (!isEmpty(head)) 
	{
        pop(head, fptr);
    }
    free(head);
}


