/***************************************************************************
 *File		: SparseMatrix.c
 *Description	: Design, develop, and execute a program in C to read a
		  sparse matrix of integer values and to search
		  the sparse matrix for an element specified by the user.
		  Print the result of the search appropriately.
		  Use the triple <row, column, value> to represent
		  an element in the  sparse matrix.
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/

#include <stdio.h>

typedef struct
{
	int row, col, value;
} SparseNode;

SparseNode SparseMatrix[100];

void display()
{
	int i;
	printf("\nSparse Matrix : \n");
	for (i = 0; i <= SparseMatrix[0].value; i++)
		printf("%d %d %d\n", SparseMatrix[i].row, SparseMatrix[i].col, SparseMatrix[i].value);
}

int main()
{
	int i, j, r, c, ctr = 1, val, ele, flag = 0;

	printf("\nEnter numbers of rows and columns\n");
	scanf("%d%d", &r, &c);
	printf("\nEnter elements of sparse matrix\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &val);
			if (val != 0)
			{
				SparseMatrix[ctr].row = i;
				SparseMatrix[ctr].col = j;
				SparseMatrix[ctr].value = val;
				ctr++;
			}
		}
	}
	SparseMatrix[0].row = r;
	SparseMatrix[0].col = c;
	SparseMatrix[0].value = ctr - 1;

	display();

	printf("\nEnter element to search for \n");
	scanf("%d", &ele);

	for (i = 1; i <= SparseMatrix[0].value; i++)
	{
		if (SparseMatrix[i].value == ele)
		{
			printf("%d exists at row %d , column %d in sparse matrix\n", ele, SparseMatrix[i].row, SparseMatrix[i].col);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("%d does not exist in sparse matrix\n", ele);

	return 0;
}


/* Output :


Enter numbers of rows and columns
4 5

Enter elements of sparse matrix
0 0 2 0 0
4 0 0 0 6
0 1 0 9 0
9 0 0 0 4

Sparse Matrix :
4 5 7
0 2 2
1 0 4
1 4 6
2 1 1
2 3 9
3 0 9
3 4 4

Enter element to search for
1
1 exists at row 2 , column 1 in sparse matrix

*/
