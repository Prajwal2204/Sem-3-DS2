#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int top;
	int *arr;
	int cap;
}stack;

stack* createstack(int cap)
{
	stack* s;
	s=(stack*)malloc(sizeof(stack));
	s->cap=cap;
	s->top=-1;
	s->arr=(int*)malloc((s->cap)*sizeof(int));
	return s;
}

int isFull(stack** s, int cap)
{
	if(((*s)->top)==(cap-1))
		return 1;
	else
		return 0;
}

int isEmpty(stack** s, int cap)
{
	if(((*s)->top)==-1)
		return 1;
	else
		return 0;
}

void push(stack** ps, int ele, int cap)
{
	if(!isFull(ps,cap))
	{
		(*ps)->top=((*ps)->top)+1;
		(*ps)->arr[(*ps)->top]=ele;	
	}
	else
	{
		printf("Stack full\n");
		return;
	}
}

void pop(stack** ps, int cap)
{
	if(!isEmpty(ps,cap))
	{
		(*ps)->top=(*ps)->top-1;
	}
	else
	{
		printf("Stack empty\n");
		return;
	}
}
	
void display(stack* ps)
{
	int i;
	if((ps->top)>0)
	{
		for(i=(ps->top); i>=0; i--)
		{
			printf("%d\n", (ps->arr[i]));
		}
	}
	else
	{
		printf("Empty stack\n");
	}
}		
	
int main()
{
	stack* s;
	int choice, cap, data;
	printf("Enter the capacity of the stack:\n");
	scanf("%d", &cap); 
	s=createstack(cap);
	do
	{	printf("Enter the choice:\n");
		printf("1.Push \n2.Pop \n3.Dislpay\n4.Exit\n");
		scanf("%d", &choice); 
		switch(choice)
		{
			case 1: printf("Enter the element you want to push:\n");
				scanf("%d", &data);
				push(&s, data, cap);
				break;
			
			case 2:	pop(&s, cap);
				break;
		
			case 3: display(s);
				break;
			
			case 4: exit(1);
				break;
	
			default: printf("Enter a valid choice\n"); 
		}
	}
	while(choice!=4);
	return 0;
}
