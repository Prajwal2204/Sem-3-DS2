//single ended circular queue
#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int front, rear, capacity;
	int *array;
}queue;

void init(queue* q)
{
	q->front=-1;
	q->rear=-1;
}

int isempty(queue* q)
{
	return(q->front==-1);	
}

int isfull(queue* q)
{
	return(((q->rear+1)%(q->capacity))==q->front);
		
}
	
void enqueueR(queue* q, int ele)//insert from right
{
	if(!isfull(q))
	{
		if(isempty(q))
			q->front=0;
		
		q->rear=((q->rear)+1)%(q->capacity);
		q->array[q->rear]=ele;
	}
	else
	{
		printf("Queue full\n");
		return;
	}
}
	
int dequeueF(queue* q)//delete from left
{
	if(!isempty(q))
	{
		int element=q->array[q->front];
		if(q->front==q->rear)
			init(q);
		else
			((q->front)++)%(q->capacity);
	}
	else
		return -9999;
}

void enqueueL(queue* q, int ele)//insert from left
{
	if(!isfull(q))
	{
		if(isempty(q))
		{	q->rear=q->front=0;
			q->array[q->front]=ele;
		}	
		q->front=((q->front)-1)%(q->capacity);
		q->array[q->rear]=ele;
	}
	else
	{
		printf("Queue full\n");
		return;
	}
}

int dequeueF(queue* q)//delete from right
{
	if(!isempty(q))
	{
		int element=q->array[q->front];
		if(q->front==q->rear)
			init(q);
		else
			((q->front)++)%(q->capacity);
	}
	else
		return -9999;
}

int main()
{
	queue *q=malloc(sizeof(queue));
	init(q);
	scanf("%d", &capacity);
	q->capacity=capacity;
	q->array=malloc(sizeof(int)*(q->capacity));
}
