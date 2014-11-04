#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

void subset_sum(int arr[MAX_SIZE], int N, int D) {

	int i, j, k, limit = pow(2, N) ;
	for (i = 1; i < limit; i++) {

		int n = i, k = 0, temp_sum = 0;
		int bit_pattern[MAX_SIZE] = {0};
				
		while (n != 0) {
			if (n % 2 == 1) {
				temp_sum += arr[k];	
				bit_pattern[k] = 1;
			}
			k++;
			n /= 2;			
		}
		
		if (temp_sum == D) {
			printf ("Subset : ");
			for (j = 0; j < N; j++) {
				if (bit_pattern[j] == 1)
					printf ("%d ", arr[j]); 			
			}		
			printf ("\n");
		}	
	}	
}

int main() {
	
	printf ("\nSubset sum \n");

	int arr[MAX_SIZE], N, D;
	int i;

	printf ("Enter the number of elements\n");
	scanf ("%d", &N);
	
	printf ("Enter %d elements\n", N);
	for (i = 0; i < N; i++) 
		scanf ("%d", &arr[i]);

	printf ("Enter the required sum\n");
	scanf ("%d", &D);

	subset_sum(arr, N, D);

	return 0;
}
