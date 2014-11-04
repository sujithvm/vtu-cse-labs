#include <stdio.h>

#define MAX_SIZE 100

void warshall(int arr[MAX_SIZE][MAX_SIZE], int N) {
	int i, j, k;
	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
}

void display(int arr[MAX_SIZE][MAX_SIZE], int N) {
	printf ("\nMatrix : \n");
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf ("%d ", arr[i][j]);
		printf ("\n");	
	}
}		

int main() {
	
	printf ("Warshall Algorithm\n");
	
	int arr[MAX_SIZE][MAX_SIZE], N;
	int i, j;
	
	printf ("Enter number of vertices\n");	
	scanf ("%d", &N);

	printf ("Enter %d X %d adj matrix\n", N, N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf ("%d", &arr[i][j]);

	warshall(arr, N);
	
	display(arr, N);
	
	return 0;
}
