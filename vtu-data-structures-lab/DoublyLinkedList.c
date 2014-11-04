/***************************************************************************
 *File		: DoublyLinkedList.c
 *Description	: Design, develop, and execute a program in C to implement
		  a doubly linked list where each node consists of integers.
		  The program should support following operations:
		  i)  Create a doubly Linked list by adding each node at front
		  ii) Insert a new element to the left of the node whose key
		      value is read as an input
		  iii) Delete the node of a given if it is found otherwise
		       display appropriate message.
		  iv) Display contents of the list

 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next, *prev;
};

typedef struct node *DLLNode;

DLLNode start = NULL;

DLLNode newNode(int val)
{
	DLLNode nptr = (DLLNode) malloc (sizeof(struct node));
	nptr -> data = val;
	nptr -> next = NULL;
	nptr -> prev = NULL;
	return nptr;
}

void insertAtFront(int val)
{
	if (start == NULL)
		start = newNode(val);
	else
	{
		DLLNode nptr = newNode(val);
		nptr -> next = start;
		start -> prev = nptr;
		start = nptr;
	}
}

void insertToLeftOf(int val, int left)
{
	DLLNode ptr = start;
	if (ptr -> data == left)
		insertAtFront(val);
	else
	{
		while (ptr != NULL && ptr -> data != left)
			ptr = ptr -> next;
		if (ptr == NULL)
			printf("%d key not found\n", left);
		else
		{
			DLLNode nptr = newNode(val);
			nptr -> next = ptr;
			nptr -> prev = ptr -> prev;
			ptr -> prev -> next = nptr;
			ptr -> prev = nptr;
		}
	}
}

void delete(int val)
{
	DLLNode ptr = start;

	/* check if starting element */
	if (ptr -> data == val)
	{
		/* check if starting element and only element of DLL */
		if (start -> next != NULL)
		{
			start = start -> next;
			start -> prev = NULL;
		}
		else
			start = NULL;

		printf("%d element deleted\n", val);
		free(ptr);
		return;
	}

	/* iterate till node with val value found */
	while (ptr != NULL && ptr -> data != val)
		ptr = ptr -> next;

	/* end of list - no such element found */
	if (ptr == NULL)
		printf("%d not found\n", val);
	else
	{
		/* check if not last element only then use ptr -> next */
		if (ptr -> next != NULL)
			ptr -> next -> prev = ptr -> prev;
		ptr -> prev -> next = ptr -> next;
		printf("%d element deleted\n", val);
		free(ptr);
	}
}

void display()
{
	printf("Doubly Linked List : ");
	DLLNode ptr = start;
	while (ptr != NULL)
	{
		printf("%d ", ptr -> data);
		ptr = ptr -> next;
	}
	printf("\n");
}

int main(void)
{
	printf("Doubly Linked List Test\n");

	int val, left, choice;

	while (1)
    	{
        	printf("\nDoubly Linked List Operations : \n" );
        	printf("1. insert at front\n2. insert to left of \n3. delete\n4. display\n5. Quit\n" );
        	scanf("%d", &choice);
        	switch (choice)
        	{
        	case 1:
            		printf("Enter element to insert\n");
            		scanf("%d", &val);
            		insertAtFront(val);
            		break;
		case 2:
			printf("Enter element to delete and left of element \n");
			scanf("%d %d", &val, &left);
			insertToLeftOf(val, left);
			break;
        	case 3:
			printf("Enter element to delete\n");
            		scanf("%d", &val);
            		delete(val);
            		break;
        	case 4:
            		display();
            		break;
        	case 5:
            		exit(0);
        	default :
            		printf("Wrong entry : \n");
        	}
    	}

	return 0;
}




/* Output :


Doubly Linked List Test

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
1
Enter element to insert
2

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
1
Enter element to insert
4

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
2
Enter element to delete and left of element
0 4

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
2
Enter element to delete and left of element
6 0

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
4
Doubly Linked List : 6 0 4 2

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
2
Enter element to delete and left of element
28 4

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
4
Doubly Linked List : 6 0 28 4 2

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
3
Enter element to delete
6
6 element deleted

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
3
Enter element to delete
2
2 element deleted

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
3
Enter element to delete
0
0 element deleted

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
4
Doubly Linked List : 28 4

Doubly Linked List Operations :
1. insert at front
2. insert to left of
3. delete
4. display
5. Quit
5


*/















