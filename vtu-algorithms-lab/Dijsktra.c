#include <stdio.h>

#define MAX_SIZE 100
#define INF 9999
#define NIL -1
#define TRUE 1
#define FALSE 0

void dijsktra(int cost[MAX_SIZE][MAX_SIZE], int N, int source) {
	int dist[MAX_SIZE], predecessor[MAX_SIZE], visited[MAX_SIZE];
	int i, count;
	for (i = 0; i < N; i++) {
		dist[i] = INF;
		predecessor[i] = NIL;
		visited[i] = FALSE; 
	}
	dist[source] = 0;
	predecessor[source] = source;
	
	count = 0;
	while (count <= N) {
		int min = INF, u = 0;
		for (i = 0; i < N; i++) {
			if (dist[i] < min && !visited[i]) {
				min = dist[i];
				u = i;		
			}		
		}
		visited[u] = TRUE;
		for (i = 0; i < N; i++) {
			if (dist[u] + cost[u][i] < dist[i] && !visited[i]) {
				dist[i] = dist[u] + cost[u][i];
				predecessor[i] = u;			
			}		
		}	
		count++;
	}

	for (i = 0; i < N; i++) {
		if (i != source) {
			printf ("Path %d to %d : cost : %d : Path : ", source, i, dist[i]);
			int path[MAX_SIZE] = {0}, top = -1, j = i;
			path[++top] = i;
			while (predecessor[j] != source) {
				j = predecessor[j];
				path[++top] = j;			
			}
			path[++top] = source;			
			while (top != -1) {
				printf ("%d ", path[top--]);
				if (top != -1)	printf ("-> ");				
			}
			printf ("\n");
		}
	}	
}

int main() {
	
	printf ("Dijsktra Algorithm\n");
	
	int adj[MAX_SIZE][MAX_SIZE], N, source;
	int i, j;
	
	printf ("Enter number of vertices\n");	
	scanf ("%d", &N);

	printf ("Enter %d X %d adj matrix\n", N, N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf ("%d", &adj[i][j]);

	printf ("Enter source\n");	
	scanf ("%d", &source);

	dijsktra(adj, N, source);
	
	return 0;
}
