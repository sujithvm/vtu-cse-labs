#include <stdio.h>
#include <omp.h>
#include <sys/time.h>

#define min(a, b) ((a<b)?(a):(b))

#define MAX_SIZE 100

void floyd(int arr[MAX_SIZE][MAX_SIZE], int N) {
	int i, j, k;
	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
}

void floyd_parallel(int arr[MAX_SIZE][MAX_SIZE], int N) {
	int i, j, k;
	for (k = 0; k < N; k++) {
		#pragma omp parallel for shared(arr)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);	
	}		
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
	
	printf ("Floyds Algorithm\n");
	
	int arr[MAX_SIZE][MAX_SIZE], arr1[MAX_SIZE][MAX_SIZE], N;
	int i, j;
	struct timeval t;
	
	printf ("Enter number of vertices\n");	
	scanf ("%d", &N);

	printf ("Enter %d X %d adj matrix\n", N, N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf ("%d", &arr[i][j]);
			arr1[i][j] = arr[i][j];		
		}				
	}
	
	gettimeofday(&t, NULL);
	double start1 = t.tv_sec + t.tv_usec/1000000.0;
	floyd(arr, N);
	gettimeofday(&t, NULL);
	double end1 = t.tv_sec + t.tv_usec/1000000.0;

	gettimeofday(&t, NULL);
	double start2 = t.tv_sec + t.tv_usec/1000000.0;
	floyd_parallel(arr1, N);
	gettimeofday(&t, NULL);
	double end2 = t.tv_sec + t.tv_usec/1000000.0;
	
	printf ("Solution\n");	
	display(arr, N);

	double time1 = (1.0 * (end1 - start1));
	double time2 = (1.0 * (end2 - start2));
	double speed_up = time2 / time1;
	printf ("Non-parallel Floyd time : %lf \n", time1);
	printf ("Parallel Floyd time : %lf \n", time2);
	printf ("Speed up : %lf \n", speed_up);
	return 0;
}
