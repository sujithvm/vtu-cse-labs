#include <stdio.h>

#define MAX_SIZE 100

void display(int arr[MAX_SIZE], int N) {
	printf ("\nSort : \n");
	int i;
	for (i = 0; i < N; i++) {
		printf ("%d ", arr[i]);
	}
}		

void topological_sort(int adj[MAX_SIZE][MAX_SIZE], int N) {
	int indegree[MAX_SIZE] = {0}, sort[MAX_SIZE], stack[MAX_SIZE];
	int i, j, k, v, top;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (adj[i][j] == 1)
				indegree[j]++;
	top = -1, k = 0;
	while (1) {
		for (i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				indegree[i] = -1;
				stack[++top] = i;			
			}		
		}
		if (top == -1) break;
		
		v = stack[top--];
		printf ("%d \n", v);
		sort[k++] = v; 
		for (i = 0; i < N; i++)
			if (adj[v][i] == 1)
				indegree[i]--;	
	}
	display(sort, N);
}

int main() {
	
	printf ("Topological Sort Algorithm\n");
	
	int arr[MAX_SIZE][MAX_SIZE], N;
	int i, j;
	
	printf ("Enter number of vertices\n");	
	scanf ("%d", &N);

	printf ("Enter %d X %d adj matrix\n", N, N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf ("%d", &arr[i][j]);

	topological_sort(arr, N);
	
	return 0;
}
