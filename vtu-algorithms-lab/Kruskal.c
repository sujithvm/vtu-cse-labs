#include <stdio.h>

#define MAX_SIZE 100
#define INF 9999
#define NIL -1

void kruskal(int adj[MAX_SIZE][MAX_SIZE], int N) {
	int parent[MAX_SIZE] ;	
	int i, j, count = 0;

	for (i = 0; i < N; i++) parent[i] = i;
	
	printf ("Minimum Spanning Tree : \n");	
	
	while (count < N) {
		int min = INF, u = NIL, v = NIL;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (adj[i][j] < min) {
					min = adj[i][j];
					u = i;
					v = j;				
				}	
			}		
		}
		int p1 = u, p2 = v;
		while (parent[p1] != p1) p1 = parent[p1];
		while (parent[p2] != p2) p2 = parent[p2];
		
		if (p1 != p2) {
			printf ("%d - %d\n", (u + 1), (v + 1));
			adj[u][v] = INF;
			adj[v][u] = INF;
			if (u < v) parent[u] = v;
			else parent[v] = u;		
		}
		count++;		
	}	
}

int main() {
	
	printf ("Kruskal Algorithm\n");
	
	int arr[MAX_SIZE][MAX_SIZE], N;
	int i, j;
	
	printf ("Enter number of vertices\n");	
	scanf ("%d", &N);

	printf ("Enter %d X %d adj matrix\n", N, N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf ("%d", &arr[i][j]);

	kruskal(arr, N);
	
	return 0;
}
