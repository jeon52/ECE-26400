//create Node type
typedef struct Node {
    float val;
    struct Node * next;
} Node;

//header function 
typedef struct Stack {
    Node * top; //top of the stack. If it points to NULL, the stack is empty
} Stack;

//Initialize a stack(header)
Stack * initialize();

//add node function 
Node * addfirst (float val, Node * list);

//remove node function
Node * removefirst (Node * list);

//check if the stack is empty
bool isEmpty(Stack * head);

//push the returned value 
void push(Stack * head, float val);

//pop the first value
float pop(Stack * head, FILE * fptr);

//free stack
void freeStack(Stack * head, FILE * fptr);

//peek into the first value of the node 
float peek(Stack * head);

//does arithetric operations!
float arithmeticoperation (char * operand, Stack * head, FILE * fptr);
