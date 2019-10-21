#include<stdio.h>
#include<stdlib.h>

int ** creategraph(int n)
{
	int **a;
	a=calloc(sizeof(int*),n);
	for(int i=0;i<n;i++)
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
		{
			break;
		}
		ad_mat[i][j]=ad_mat[j][i]=1; //second part won't come for directed graph
	}
}

void dfs(int src, int **ad_mat, int n, int *visited)// to traverse one connected element
{
	visited[src]=1; //to mark it as 1 means that it is visited
	printf("%d", src);
	for(int i=0; i<n; i++) //adjacency matrix check(to check whether elements are neighbour to the source or not)
	{
		if(ad_mat[src][i]==1 && visited[i]==0) //neighbour
			dfs(i, ad_mat, n, visited);
	}
}					

int DFS(int src, int **ad_mat, int n, int *visited)// to traverse all connected elements, i.e, takes care even if graph is not connected in the middle
{
	int count=0; //no. of times dfs was called, i.e, no. of connected components
	int i;
	for(i=0; i<n; i++)
	{
		if(visited[i]==0)
		{	dfs(i, ad_mat, n, visited);
			count++;
		}
	}
	return count;
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
	//dfs(src,ad_mat,n,visited);
	c=DFS(src,ad_mat,n,visited);
	return 0;
}
	
