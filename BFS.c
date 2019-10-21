#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int front, rear, size, capacity;
	int* array;
}Queue;

struct Queue* createQueue(int capacity)
{
	struct Queue* queue=(struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity=capacity;
	queue->front=-1;
	queue->rear=-1;
	queue->size=0;
	queue->array=(int*) malloc(queue->capacity*sizeof(int));
	return queue;
}

int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
int ** creategraph(int n)
{
	int **a;
	a=calloc(sizeof(int*),n);
	for(i=0;i<n;i++)
	{
		a[i]=malloc(sizeof(int)*n);
	}
	return a;
}

void readgraph(int **ad_mat, int n)
{
	int i, j;
	while(1)
	{
		printf("Enter start and end vertex:\n");
		scanf("%d", &i);
		scanf("%d", &j);
		if(i==-1 && j==-1)
			break;
		ad_mat[i][j]=ad_mat[j][i]=1; //second part won't come for directed graph
	}
}

void bfs(int src, int **ad_mat, int n, int *visited)// to traverse all connected elements, i.e, takes care even if graph is not connected in the middle
{
	int current_v;
	visited[src]=1;
	queue *pq=createQueue(n);
	enqueue(pq, src); 
	while(!isEmpty(pq))
	{
		current_v=dequeue(pq);
		for(int i=0; i<n; i++)
		{	
			if(ad_mat[src][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				enqueue(pq,i);
			}
		}
	}s
}

int BFS(int src, int **ad_mat, int n, int *visited)
{
	bfs(src,ad_mat,n,visited);
	for(int i=0; i<n; i++)
	{
		if(visited[i]==0)
		{
			bfs(i,ad_mat,n,visited);
		}
	}
}

int main()
{
	int **ad_mat,n,c,src,*visited;
	scanf("%d", &n); //no. of vertices
	ad_mat=creategraph(n);
	readgraph(ad_mat, n);
	visited=calloc(sizeof(int),n); // array to know whether the vertex is visited or not
	printf("Enter the source:\n");
	scanf("%d", &src);
	BFS(src, ad_mat, n, visited);
	return 0;
}
