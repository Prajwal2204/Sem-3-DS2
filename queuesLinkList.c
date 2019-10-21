#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;

typedef struct queue
{
	node* front;
	node* rear;
}queue;

queue* create_node(

int isempty(queue *q)
{
	return(q->front==NULL && q->rear==NULL)
}
	
void insert(queue *q, int ele)
{

}

int delete(queue *q)
{
	if(isempty(q))
		return -9999;
	else
	{
		temp=q->front;
		int element=temp->data;
		if((q->front)==(q->rear))
		{
			(q->front)=(q->rear)=NULL;
		else
		{
			q->front=q->front->link;
		}
		free(temp);
	}
	return element;
}
