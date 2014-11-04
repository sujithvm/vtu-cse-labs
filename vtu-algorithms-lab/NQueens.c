#include <stdio.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

int arr[MAX_SIZE][MAX_SIZE] = {0};
int N;

int check(int row, int col) {
	int r, c;
	for (c = 0; c < col; c++) if (arr[row][c] == 1) return FALSE;
	for (r = row, c = col; r >= 0 && c >= 0; r--, c--) if (arr[r][c] == 1) return FALSE;
	for (r = row, c = col; r < N && c >= 0; r++, c--) if (arr[r][c] == 1) return FALSE;
	return TRUE;
}

int nqueens(int col) {
		
	if (col == N) return TRUE;

	int row;
	for (row = 0; row < N; row++) {
		if (check(row, col)) {
			arr[row][col] = 1;
			if (nqueens(col + 1)) return TRUE;
			arr[row][col] = 0; 		
		}	
	}
	return FALSE; 
}

int main() {
	
	printf ("N Queens problem \n");
	
	printf ("Enter N\n");
	scanf ("%d", &N);

	nqueens(0);

	int i, j;
	printf ("Solution\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (arr[i][j] == 1) printf ("Q ");
			else printf (". ");		
		}	
		printf ("\n");
	} 
	
	return 0;
}
