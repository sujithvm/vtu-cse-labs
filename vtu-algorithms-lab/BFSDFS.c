#include <stdio.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

int visited[MAX_SIZE] = {0};

void bfs(int adj[MAX_SIZE][MAX_SIZE], int V) {

	int queue[MAX_SIZE] = {0};
	int front = -1, rear = -1, i;
	
	queue[++rear] = 0;
	visited[0] = TRUE;
	
	while (front != rear) {
		int u = queue[++front];
		for (i = 0; i < V; i++) {
			if (adj[u][i] != 0 && !visited[i]) {
				visited[i] = TRUE; 
				queue[++rear] = i;	
			}			
		}
	}	
	for (i = 0; i < V; i++)
		printf ("%d ", queue[i]);
}

void dfs(int adj[MAX_SIZE][MAX_SIZE], int V, int v) {
	visited[v] = TRUE;
	printf ("%d ", v);
	int i;
	for (i = 0; i < V; i++) {
		if (adj[v][i] != 0 && !visited[i]) {
			dfs(adj, V, i);		
		}	
	}
}

int main() {

	int arr[MAX_SIZE][MAX_SIZE];
	printf ("BFS and DFS\n");
	int V, i, j;

	printf ("Enter number of vertices\n");
	scanf ("%d", &V);

	printf ("Enter %d X %d cost matrix\n", V, V);
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			scanf ("%d", &arr[i][j]);
	
	printf ("BFS : ");
	bfs(arr, V);
	
	printf ("\n");
	for (i = 0; i < V; i++) visited[i] = FALSE;
	
	printf ("DFS : ");
	dfs(arr, V, 0);
	
	printf ("\n");
	return 0;
}
