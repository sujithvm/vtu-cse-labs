#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

#define MAX 100
#define STEPS 100

void generate_random_array(int arr[MAX], int N) {
	int i;
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 1000;
	}
}

void merge_sort(int arr[MAX], int low, int high) {

	int N = high - low;
	int mid = low + N/2;

	if (N <= 1) return;
	
	#pragma omp parallel sections 
	{
		#pragma omp section
		merge_sort(arr, low, mid);
		#pragma omp section
		merge_sort(arr, mid, high);
	}

	int temp[N], i = low, j = mid, k;
	for (k = 0; k < N; k++) {
		if (j == high) temp[k] = arr[i++];
		else if (i == mid) temp[k] = arr[j++];
		else if (arr[i] < arr[j]) temp[k] = arr[i++];
		else temp[k] = arr[j++];	
	}
	
	for (k = 0; k < N; k++)
		arr[low + k] = temp[k];
}

int main() {
	
	printf ("Merge sort algorithm\n");

	omp_set_num_threads(5);
	
	int i, j;
	int arr[MAX];
	
	for (i = 100; i <= MAX; i += STEPS) {
		printf ("\nGenerating random array of size %d \n", i);
		generate_random_array(arr, i);

		printf ("\nSorting\n");
		merge_sort(arr, 0, i);
		
		for (j = 0; j < i; j++)
			printf ("%d ", arr[j]);
		printf ("\n");	
	}	
	return 0;
}
