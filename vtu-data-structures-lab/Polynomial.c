/***************************************************************************
 *File		: Polynomial.c
 *Description	: Using circular representation for a polynomial,
		  design, develop, and execute a program in C to accept
		  two polynomials, add them, and
                  then print the resulting polynomial.
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 19 August 2013
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int exp, cof;
	struct node *next;
};

typedef struct node *LinkedNode;

LinkedNode start, end, p1, p2, result, f1, f2;

LinkedNode newNode(int c, int e)
{
	LinkedNode ptr = (LinkedNode) malloc (sizeof(struct node));
	ptr -> exp = e;
	ptr -> cof = c;
	ptr -> next = NULL;
	return ptr;
}

void create()
{
	start = NULL;
	end = NULL;
}

void insert(int c, int e)
{
	if (start == NULL)
	{
		end = newNode(c, e);
		start = end;
	}
	else
	{
		end -> next = newNode(c, e);
		end = end -> next;
	}
}

void display()
{
	printf("\nFinal polynomial = ");
	LinkedNode ptr = result;
	while (ptr != NULL)
	{
		if (ptr -> next == NULL)
		{
			if (ptr -> exp != 0)
				printf("%dx^%d", ptr -> cof, ptr -> exp);
			else
				printf("%d", ptr -> cof);
		}
		else
		{
			if (ptr -> exp != 0)
				printf("%dx^%d + ", ptr -> cof, ptr -> exp);
			else
				printf("%d ", ptr -> cof);
		}
		ptr = ptr -> next;
	}
	printf("\n");
}

void circularLink()
{
	end -> next = start;
}

int main(void)
{
	int n1, n2, i, c, e, s1, s2;
	create();

	printf("\nEnter number of terms in polynomial 1\n");
	scanf("%d", &n1);
	printf("\nEnter %d coefficients and exponents\n", n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%d%d", &c, &e);
		insert(c, e);
	}
	// add dummy values before cirlcular link
	insert(0, 0);

	circularLink();
	p1 = start;
	create();

	printf("\nEnter number of terms in polynomial 2\n");
	scanf("%d", &n2);
	printf("\nEnter %d coefficients and exponents\n", n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%d%d", &c, &e);
		insert(c, e);
	}
	// add dummy values before cirlcular link
	insert(0, 0);

	circularLink();
	p2 = start;
	create();

	f1 = p1;
	f2 = p2;

	while ( p1 -> next != f1 && p2 -> next != f2)
	{
		if ( p1 -> exp == p2 -> exp)
		{
			c = p1 -> cof + p2 -> cof;
			if ( c != 0 )
			{
				insert(c, p1 -> exp);
			}
			p2 = p2 -> next;
			p1 = p1 -> next;
		}
		else if ( p1 -> exp > p2 -> exp)
		{
			insert(p1 -> cof, p1 -> exp);
			p1 = p1 -> next;
		}
		else if ( p1 -> exp < p2 -> exp)
		{
			insert(p2 -> cof, p2 -> exp);
			p2 = p2 -> next;
		}
	}

	while (p1 -> next != f1)
	{
		insert(p1 -> cof, p1 -> exp);
		p1 = p1 -> next;
	}

	while (p2 -> next != f2)
	{
		insert(p2 -> cof, p2 -> exp);
		p2 = p2 -> next;
	}

	result = start;
	display();

	return 0;
}

/*
Enter number of terms in polynomial 1
5

Enter 5 coefficients and exponents
19 250
28 63
6 24
7 14
5 0

Enter number of terms in polynomial 2
4

Enter 4 coefficients and exponents
5 250
17 97
18 24
7 0

Final polynomial = 24x^250 + 17x^97 + 28x^63 + 24x^24 + 7x^14 + 12

*/









