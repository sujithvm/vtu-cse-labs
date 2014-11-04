#include <stdio.h>

#define MAX_SIZE 100

void knapsack(int profit[MAX_SIZE], int weight[MAX_SIZE], int N, int W) {
	int opt[MAX_SIZE][MAX_SIZE] = {0}, sol[MAX_SIZE][MAX_SIZE] = {0};
	int n, w;
	for (n = 0; n <= N; n++) {
		for (w = 0; w <= W; w++) {
			if (n == 0 || w == 0) continue;
			int option1 = opt[n - 1][w];
			int option2 = -1;
			if (w - weight[n] >= 0)	option2 = profit[n] + opt[n - 1][w - weight[n]];
			opt[n][w] = option1 > option2 ? option1 : option2;
			sol[n][w] = option2 > option1 ? 1 : 0;	
		}		
	}
	for (n = 0; n <= N; n++) {
		for (w = 0; w <= W; w++) {
			printf ("%d ", opt[n][w]);	
		}	
		printf ("\n");
	}
	printf ("Select objects \n");
	for (n = N, w = W; n > 0; n--) {
		if (sol[n][w] == 1) {
			printf ("%d \n", n);
			w = w - weight[n];
		}	
	}	
}

int main() {
	
	printf ("Knapsack 01 Algorithm\n");
	
	int profit[MAX_SIZE], weight[MAX_SIZE], N, W;
	int i, j;
	
	printf ("Enter number of objects\n");	
	scanf ("%d", &N);

	printf ("Enter %d profit-weight pairs\n", N);
	for (i = 1; i <= N; i++)
		scanf("%d %d", &profit[i], &weight[i]);

	printf ("Enter weight of bag \n");
	scanf ("%d", &W);

	knapsack(profit, weight, N, W);
	
	return 0;
}
