#include <stdio.h>

#define MAX_SIZE 100
#define INF 9999
#define NIL -1
#define FALSE 0
#define TRUE 1

void prim(int adj[MAX_SIZE][MAX_SIZE], int N) {
	int visited[MAX_SIZE] = {0};	
	int i, j, count = 0;

	printf ("Minimum Spanning Tree : \n");	
	
	while (count < N - 1) {
		int min = INF, u = NIL, v = NIL;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (adj[i][j] < min && !visited[i]) {
					min = adj[i][j];
					u = i;
					v = j;				
				}	
			}		
		}

		if (visited[u] == FALSE || visited[v] == FALSE) {
			printf ("%d - %d\n", (u + 1), (v + 1));
			adj[u][v] = INF;
			adj[v][u] = INF;
			visited[v] = TRUE;
		}
		count++;		
	}	
}

int main() {
	
	printf ("Prim Algorithm\n");
	
	int arr[MAX_SIZE][MAX_SIZE], N;
	int i, j;
	
	printf ("Enter number of vertices\n");	
	scanf ("%d", &N);

	printf ("Enter %d X %d adj matrix\n", N, N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf ("%d", &arr[i][j]);

	prim(arr, N);
	
	return 0;
}
