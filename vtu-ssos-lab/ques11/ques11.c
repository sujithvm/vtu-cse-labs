#include <stdio.h>
#include <omp.h>

int main() 
{
	int n, a[100], i;
	
	omp_set_num_threads(5);

	printf ("Enter n\n");
	scanf ("%d", &n);

	a[0] = 0;
	a[1] = 1;

	#pragma omp parallel 
	{
		#pragma omp single
		{
			for (i = 2; i < n; i++) 
			{
				a[i] = a[i - 1] + a[i - 2];
				printf ("Computation thread id = %d,\tfib num = %d\n", omp_get_thread_num(), i + 1);
			}
		}
	}

	printf ("\nFibonacci Series\n");
	
	#pragma omp barrier
	#pragma omp single
	{
		printf ("Fibonacci series : \n");
		for (i = 0; i < n; i++) 
		{
			printf ("%d - thread id, Fib num = %d \n", omp_get_thread_num(), a[i]); 
		}
	}

	return 0;
}
