/***************************************************************************
 *File	    	: Queue.c
 *Description   : Design, develop, and execute a program in C to
		  simulate the working of a queue  of integers using
		  an array. Provide following operation.
		  I) Insert II) Delete III) Display.
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

int front = -1, rear = -1;
int arr[QUEUE_SIZE];

int isEmpty()
{
	return front == -1;
}
int isFull()
{
	return front == 0 && rear == QUEUE_SIZE - 1;
}

void insert(int data)
{
	if (rear == -1)
    	{
        	front = rear = 0;
        	arr[rear] = data;
    	}
    	else if (isFull())
        	printf("Overflow exception\n");
    	else
        	arr[++rear] = data;
}

int delete()
{
    	if (isEmpty())
    	{
        	printf("Underflow exception\n");
        	return -1;
    	}
    	else
    	{
        	int ele = arr[front];
        	if (front == rear)
            		front = rear = -1;
        	else
            		front++;
        	return ele;
    	}
}

void display()
{
    int i;
    printf("Queue = ");
    for (i = front; i <= rear; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	printf("\nQueue Test\n\n");
	int val, choice;

    	while (1)
    	{
        	printf("\nQueue Operations : \n" );
        	printf("1. insert\n2. remove\n3. display\n4. Quit\n" );
        	scanf("%d", &choice);
        	switch (choice)
        	{
        	case 1:
            		printf("Enter element to insert\n");
            		scanf("%d", &val);
            		insert(val);
            		break;
        	case 2:
            		val = delete();
            		printf( "Removed Value : %d \n", val );
            		break;
        	case 3:
            		display();
            		break;
        	case 4:
            		exit(0);
        	default :
            		printf("Wrong entry : \n");
        	}
    	}
    	return 0;
}

/* Output :


Queue Test


Queue Operations :
1. insert
2. remove
3. display
4. Quit1
Enter element to insert

Queue Operations :
1. insert
2. remove
3. display
4. Quit^C
E:\c\lab 3>notepad ques1.c

E:\c\lab 3>notepad ques2.c

E:\c\lab 3>notepad ques3.c

E:\c\lab 3>notepad ques4.c

E:\c\lab 3>gcc ques4.c

E:\c\lab 3>a

Queue Test


Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
5

Queue Operations :
1. insert
2. remove
3. display
4. Quit
3
Queue = 5

Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
7

Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
9

Queue Operations :
1. insert
2. remove
3. display
4. Quit
Enter element to insert
^C
E:\c\lab 3>
E:\c\lab 3>a

Queue Test


Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
2

Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
4

Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
0

Queue Operations :
1. insert
2. remove
3. display
4. Quit
1
Enter element to insert
6

Queue Operations :
1. insert
2. remove
3. display
4. Quit
3
Queue = 2 4 0 6

Queue Operations :
1. insert
2. remove
3. display
4. Quit
2
Removed Value : 2

Queue Operations :
1. insert
2. remove
3. display
4. Quit
2
Removed Value : 4

Queue Operations :
1. insert
2. remove
3. display
4. Quit
3
Queue = 0 6

Queue Operations :
1. insert
2. remove
3. display
4. Quit
2
Removed Value : 0

Queue Operations :
1. insert
2. remove
3. display
4. Quit
2
Removed Value : 6

Queue Operations :
1. insert
2. remove
3. display
4. Quit
2
Underflow exception
Removed Value : -1

Queue Operations :
1. insert
2. remove
3. display
4. Quit
4

*/
