#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 7
#define MAX_RESOURCES 5

int claim[MAX_PROCESSES][MAX_RESOURCES] = {0};		// claim matrix
int req[MAX_PROCESSES][MAX_RESOURCES] = {0};		// requirement matrix
int alloc[MAX_PROCESSES][MAX_RESOURCES] = {0};		// allocated resource matrix

int comp[MAX_PROCESSES] = {0};		// computed process array
int flag[MAX_PROCESSES] = {0};		// computed process flag array
int safe[MAX_PROCESSES] = {0};		// safe sequence array

int rsrc[MAX_RESOURCES] = {0};		// resource array
int avail[MAX_RESOURCES] = {0};		// available resource array
int work[MAX_RESOURCES] = {0};		// work resource array

int p; 		// number of processes
int r; 		// number of resources

int i, j, count = 0, k = 0, x = 0;


int main() 
{
	printf ("\n\nBankers algorithm\n\n");

	printf ("Enter the number of processes\n");
	scanf ("%d", &p);

	printf ("Enter the number of resources\n");
	scanf ("%d", &r);

	printf ("Enter the claim matrix\n");
	for (i = 0; i < p; i++) 
		for (j = 0; j < r; j++)
			scanf ("%d", &claim[i][j]);

	printf ("Enter the allocation matrix\n");
	for (i = 0; i < p; i++) 
		for (j = 0; j < r; j++)
			scanf ("%d", &alloc[i][j]);

	printf ("Enter total number of instances of each resource\n");
	for (j = 0; j < r; j++) 
		scanf ("%d", &rsrc[j]);

	for (j = 0; j < r; j++) 
	{
		int total = 0;		

		for (i = 0; i < p; i++)
			total += alloc[i][j];

		avail[j] = rsrc[j] - total;
		work[j] = avail[j];
	}
	
	for (i = 0; i < p; i++) 
		for (j = 0; j < r; j++)
			req[i][j] = claim[i][j] - alloc[i][j];

	
	printf ("\nClaim matrix\t\tAllocation matrix\tNeed matrix\n");
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < r; j++)
			printf ("%d ", claim[i][j]);
		printf ("\t\t");
		for (j = 0; j < r; j++)
			printf ("%d ", alloc[i][j]);
		printf ("\t\t");
		for (j = 0; j < r; j++)
			printf ("%d ", req[i][j]);
		printf ("\n");
	}

	do 
	{
		k++;
		for (i = 0; i < p; i++)
			flag[i] = 0;
		
		for (i = 0; i < p; i++)
		{
			if (comp[i] == 0)
			{
				for (j = 0; j < r; j++)
				{
					if (req[i][j] > work[j])
					{
						flag[i] = 1;
						break;
					}
				}
				if (flag[i] == 0)
				{
					for (j = 0; j < r; j++)
					{
						work[j] += alloc[i][j];
						alloc[i][j] = claim[i][j] = 0;
					}
					comp[i] = 1;
					count++;
					safe[x] = i;
					x++;
				}
			}
		}
		
	} while (count != p && k < p);	

	if (count == p)
	{
		printf ("\nThe system is in safe state\n");
		printf ("Safe sequence : ");
		for (i = 0; i < p; i++)
			printf ("%d ", safe[i]);
		printf ("\n");
	} 
	else 
	{
		printf ("\nThe system is in unsafe state\n");
	}
	
	return 0;
}




