/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>
 
#define MAX 50
/*typedef struct queue
{
	int *queue_array;
	int rear;
	int front;
	int capacity;
	int size;
}queue;*/

 
void insert();
void delete();
void display();
/*queue* init(int max)
{
	queue *q=malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	q->array=NULL;
	return q;
}*/
int main()
{
    int max;
    int choice;
    //scanf("%d", &max);
    //queue *q=init(max);
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } /* End of switch */
    } 
    return 0; /* End of while */
} /* End of main() */
 

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /* End of insert() */
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /* End of delete() */
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /* End of display() */
