#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 10000
#define STEPS 100

void generate_random_array(int arr[MAX], int N) {
	int i;
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 1000;
	}
}

void quick_sort(int arr[MAX], int low, int high) {
	int i = low, j = high;
	int pivot = arr[(i + j)/2];

	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}	
	}
	if (low < j) 
		quick_sort(arr, low, j);
	if (i < high) 
		quick_sort(arr, i, high);
}

int main() {
	
	printf ("Quick sort algorithm\n");
	
	int i, j;
	int arr[MAX];
	struct timeval t;
	FILE *fp;

	fp = fopen("exec_time.txt", "w");

	for (i = 100; i <= MAX; i += STEPS) {
		printf ("\nGenerating random array of size %d \n", i);
		generate_random_array(arr, i);

		printf ("\nSorting");
		gettimeofday(&t, NULL);
		double start = t.tv_sec + t.tv_usec/1000000.0;

		quick_sort(arr, 0, i - 1);

		gettimeofday(&t, NULL);
		double end = t.tv_sec + t.tv_usec/1000000.0;

		fprintf(fp, "%d\t%lf\n", i, (end - start));
		//for (j = 0; j < i; j++)
		//	printf ("%d ", arr[j]);
	}
	fclose(fp);
	system("gnuplot");
	
	
	return 0;
}
