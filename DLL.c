#include<stdio.h>
#include<stdlib.h>

typedef struct dllnode
{
	int data;
	struct dllnode *prev;
	struct dllnode *next;
}dllnode;

dllnode* createnode(int ele)
{
	dllnode* new_node;
	new_node=(dllnode*)malloc(sizeof(dllnode));
	(new_node->data)=(ele);
	(new_node->prev)=(new_node->next)=NULL;
	return new_node;
}

void insertfront(int ele, dllnode **pstart)
{
	dllnode *new_node;
	new_node=createnode(ele);
	if((*pstart)==NULL)
	{
		(*pstart)=new_node;
	}
	else
	{
		(*pstart)->prev=new_node;
		new_node->next=(*pstart);
		(*pstart)=new_node;
	}
}

void insertend(int ele, dllnode **pstart)
{ 
	dllnode *new_node, *temp;
	new_node=createnode(ele);
	if((*pstart)==NULL)
	{
		(*pstart)=new_node;
	}
	else
	{
		temp=(*pstart);
		while((temp->next)!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->prev=temp;
	}
}	
		
void insertpos(int pos, int ele, dllnode **pstart)
{
	dllnode *new_node, *temp;
	int i=1;
	new_node=createnode(ele);
	if(pos==1)
	{
		insertfront(ele, &(*pstart));
	}
	else
	{
		temp=(*pstart);
		while(i<pos-1)
		{
			temp=temp->next;
		}
		new_node->next=temp->next;
		new_node->prev=temp;
		(temp->next)->prev=new_node;
		temp->next=new_node;
	}
}	

void deletefront(dllnode **pstart)
{
	dllnode *temp;
	if((*pstart)==NULL)
	{
		printf("EMPTY\n");
	}
	else
	{
		temp=(*pstart);
		(*pstart)=(*pstart)->next;
		temp->next=NULL;
		(*pstart)->prev=NULL;
		free(temp);
	}
}

void deleteend(dllnode **pstart)
{
	dllnode *temp;
	if((*pstart)==NULL)
	{
		printf("EMPTY\n");
	}
	else
	{
		temp=(*pstart);
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		(temp->prev)->next=NULL;
		temp->prev=NULL;
		free(temp);
	}
}

void deletepos(int pos, dllnode **pstart)
{
	dllnode *temp;
	int i=1;
	if((*pstart)==NULL)
	{
		printf("EMPTY\n");
	}
	else
	{
		temp=(*pstart);
		while(i<pos && temp!=NULL)
		{
			temp=temp->next;
		}
		if(temp!=NULL)
		{
			if(pos==1)
			{
				(*pstart)=(*pstart)->next;
				temp->next=NULL; //or call deletefront
				(*pstart)->prev=NULL;
				free(temp);
			}
			else if(temp->next==NULL)
			{
				(temp->prev)->next=NULL;
				temp->prev=NULL;
				free(temp);
			}	
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
		}
		else
		{	printf("Invalid deletion\n");
		}
	}
}

void display(dllnode **pstart)
{
	dllnode *temp;
	if((*pstart)==NULL)
	{
		printf("EMPTY\n");
	}
	else
	{
		temp=(*pstart);
		while(temp!=NULL)
		{
			printf("%d", temp->data);
			temp=temp->next;
		}
	}
}

int main()
{
	int choice, val, position;
	dllnode* start;
	start=NULL;
	for( ; ; )
	{
		printf("Enter your choice:\n");
		printf("1. Insert in the beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert at position\n");
		printf("4. Delete in the beginning\n");
		printf("5. Delete at the end\n");
		printf("6. Delete at position\n");
		printf("7. Display List\n");
		printf("8. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: //Insert in the beginning
				printf("Enter the element you want to insert:\n");
				scanf("%d", &val);
				insertfront(val, &start);
				break;

			case 2: //Insert at end
				printf("Enter the element you want to insert:\n");
				scanf("%d", &val);
				insertend(val, &start);
				break;

			case 3: //Insert at position
				printf("Enter the position:\n");
				scanf("%d", &position);
				printf("Enter the element you want to insert:\n");
				scanf("%d", &val);
				insertpos(position, val, &start);
				break;
	
			case 4: //Delete from front
				printf("Deleting the first node....\n");
				deletefront(&start);
				break;
			
			case 5: //Delete at end
				printf("Deleting the last node....\n");
				deleteend(&start);
				break;

			case 6: //Delete at pos
				printf("Enter the position:\n");
				scanf("%d", &position);
				deletepos(position, &start);
				break;
			
			case 7: //Display list
				printf("The list is....\n");
				display(&start);
				break;
			
			case 8: exit(1);
				break;
			
			default: printf("Invalid option\n");
		}
	}
}


		
