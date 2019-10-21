#include<stdio.h>
#include<stdlib.h>

typedef struct graphnode
{
	int v;
	struct graphnode *link;
}graphnode;

struct graph
{
	int noofver;
	int noofedges;
	graphnode **a;
};

void creategraph(graph *pg, int n)
{
	
	pg->noofver=n;
	pg->noofedges=0;
	pg->a=calloc(sizeof(graphnode *),n);
}

void insert(graph *pg, int i, int j)
{
	temp=malloc(sizeof(graphnode));
	temp->v=j;
	temp->link=NULL;
	//start=pg->a[i]; start address of ith linked list
	temp->link=pg->a[i];
	pg->a[i]=temp;
	pg->noofedges++;
}

void readgraph(graph *pg)
{
	int i,j;
	graphnode *temp;
	while(1)
	{
		scanf("%d %d", &i, &j);
		if(i==-1 && j==-1)
			break;
		insert(pg, i, j);
	}
}

void dfs(graph *pg, int src, int *visited) //visit only one component
{
	visited[src]=1;
	printf("%d", src);
	start=pg->a[src];
	for(start=pg->a[src]; start!=NULL; start=start->link)
	{
		w=start->v; //neighbour of source
		if(visited[w]==0)
			dfs(pg,w,visited);
	}
}

int DFS(int src, int n, int *visited)// to traverse all connected elements, i.e, takes care even if graph is not connected in the middle
{
	int count=0; //no. of times dfs was called, i.e, no. of connected components
	int i;
	for(i=0; i<n; i++)
	{
		if(visited[i]==0)
		{	dfs(i, n, visited);
			count++;
		}
	}
	return count;
}

void destroygraph(graph *pg)
{
	for(int i=0; i<n; i++)
	{	start=pg->a[i];
		while(start!=NULL)
		{
			temp=start;
			start=start->link;
			free(temp);
		}	
	}
	free(pg->a);
	free(pg);
}
		

int main()
{
	graph *pg;
	int *visited;
	int n, src;
	scanf("%d", &n);
	pg=malloc(sizeof(graph));
	createnode(pg,n);
	readgraph(pg);
	visited=calloc(sizeof(int),n);
	scanf("%d", &src);
	
	return 0;
}
