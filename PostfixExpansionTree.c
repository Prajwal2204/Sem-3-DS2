#include<stdio.h>
#include<stdlib.h>

typedef struct btnode
{
	int data;
	struct btnode *llink;
	struct btnode *rlink;
}btnode;

typedef struct stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}stack; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
stack* createStack(unsigned capacity) 
{ 
    stack* stack = (stack*)malloc(sizeof(stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
// Function to return the top from stack without removing it 
int peek(stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

int isOperand(char ch)
{
	if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
		return 1;
	else
		return 0;
}

int isOperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
		return 1;
	else
		return 0;
}

void postfixtree(btnode *root, stack s)
{
	if(root==NULL)
	{
		root=pop(s);
	}
	while(!isEmpty(s))
	{
		if(root->llink==NULL)
		{
			root=pop(s);
		}


		if(isOperator(peek(s)))
		{
			root->llink->data=pop(s);
		}
		else if(isOperand(peek(s)))
		{
			
		


