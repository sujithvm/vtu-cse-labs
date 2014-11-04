/***************************************************************************
 *File		: MaxHeap.c
 *Description	: Design, develop, and execute a program in C to create 
		  a max heap of integers by accepting one element at a 
		  time and by inserting it immediately in to the heap. 
		  Use the array representation for the heap. 
		  Display the array at the end of insertion phase. 
		  	
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 4 November 2013
***************************************************************************/

#include <stdio.h>

#define MAX_SIZE 100000

int heapSize = 0;
int heap[MAX_SIZE];

void insert(int ele)
{
	heap[++heapSize] = ele;
	int pos = heapSize;
	while (pos != 1 && ele > heap[pos/2])
	{
		heap[pos] = heap[pos/2];
		pos /=2;
	}
	heap[pos] = ele;	
}

void display()
{
	printf("\nMax Heap : ");
	int i;
	for (i = 1; i <= heapSize; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

int main(void)
{
	printf("Max Heap Test\n");
	int i, n, ele;
	printf("\nEnter number of elements to insert\n");
	scanf("%d", &n);
	printf("Enter %d elements\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		insert(ele);
	}
	display();
	
	return 0;
}

/*

Max Heap Test

Enter number of elements to insert
7
Enter 7 elements
7 3 2 5 8 1 9

Max Heap : 9 7 8 3 5 1 2

*/








