#include <stdio.h>

#define MAX_SIZE 100
#define INF 9999
#define TRUE 1
#define FALSE 0

int adj[MAX_SIZE][MAX_SIZE], N;
int exact_path[MAX_SIZE];
int exact_path_cost = INF; 

int approx_path_cost = 0; 
int visited[MAX_SIZE] = {0};

// exact solution by permutation	 
void permute_cities(int cities[MAX_SIZE] , int n) {
	
	int i;
	if (n == 0) {	
			
		int temp_cost = 0;
		cities[N] = cities[0];		
		// printf ("%d ", cities[0]);	
		for (i = 1; i <= N; i++) {
		//	printf ("-> %d ", cities[i]);
			temp_cost += adj[cities[i - 1]][cities[i]];
		}
		// printf (" Cost : %d\n", temp_cost);
		if (temp_cost < exact_path_cost) {			
			exact_path_cost = temp_cost;
			for (i = 0; i <= N; i++) 
				exact_path[i] = cities[i];					
		}
		return;	
	}
	for (i = 0; i < n; i++) {
		int temp = cities[i];
		cities[i] = cities[n - 1];
		cities[n - 1] = temp;
		
		permute_cities(cities, n - 1);
	
		temp = cities[i];
		cities[i] = cities[n - 1];
		cities[n - 1] = temp;		
	}	
}

void tsp_exact() {
	
	int cities[MAX_SIZE], i;
	for (i = 0; i < N; i++) cities[i] = i;	

	exact_path_cost = INF;
	permute_cities(cities, N);

	printf ("\nShortest Path : ");
	printf ("%d ", exact_path[0]);	
	for (i = 1; i <= N; i++) printf ("-> %d ", exact_path[i]);
	printf (" Cost : %d\n", exact_path_cost);	
}

// approximate solution by greedy method 

void tsp_approx() {
	
	printf ("\nApproximate Path : ");
	int u = 0, count = 1;
	visited[0] = TRUE;
	
	printf ("0 ");
	while (count < N) {
		int min = INF, v, i;
		for (i = 0; i < N; i++) {
			if (!visited[i] && adj[u][i] < min) {
				min = adj[u][i];
				v = i;			
			}		
		}
		visited[v] = TRUE;
		approx_path_cost += min;
		u = v;
		printf ("-> %d ", u);
		count++;
	}
	approx_path_cost += adj[u][0];
	printf ("-> 0  ");
	printf ("Cost : %d\n", approx_path_cost);		
}

int main() {

	printf ("\nTravelling Salesperson Problem\n");
		
	int i, j;

	printf ("Enter number of cities\n");
	scanf ("%d", &N);

	printf ("Enter %d X %d cost matrix\n", N, N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf ("%d", &adj[i][j]);	
	
	// exact solution by permutation	
	tsp_exact();
	
	// approximate solution by greedy method
	tsp_approx();

	printf ("\nError units in approximation : %d \n", (approx_path_cost - exact_path_cost));
	printf ("\nAccuracy ratio of approximation : %lf \n", (double)(1.0 * exact_path_cost / approx_path_cost));

	return 0;
}
