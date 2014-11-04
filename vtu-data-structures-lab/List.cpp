/***************************************************************************
 *File		: List.cpp
 *Description	: Design, develop, and execute a program in C++ to create a 
		  class called LIST with member functions to insert an
		  element at front of the list as well as to delete an
		  element at front of the list. Demonstrate all the 
		  operations after creating a list object.
		  	
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 4 November 2013
***************************************************************************/


#include <iostream>
#include <stdlib.h>

using namespace std;

class LIST
{
	private :
		struct node
		{
			int data;
			struct node *next;
		};
		typedef struct node *LinkedNode;
		
		LinkedNode start;
		
		LinkedNode newNode(int val)
		{
			LinkedNode nptr = (LinkedNode) malloc (sizeof(struct node));
			nptr -> data = val;
			nptr -> next = NULL;
			return nptr;
		}
	
	public :
		LIST()
		{
			start = NULL;
		}
		void insertAtFront(int val);		
		void deleteAtFront();
		void display();
};

void LIST :: insertAtFront(int val)
{
	if (start == NULL)
		start = newNode(val);
	else
	{
		LinkedNode nptr = newNode(val);
		nptr -> next = start;
		start = nptr;
	}				
}

void LIST :: deleteAtFront()
{
	if (start == NULL)
		cout << "Underflow Exception" << endl;
	else
	{
		LinkedNode ptr = start;
		cout << ptr -> data << " element deleted" << endl;
		start = start -> next;
		free(ptr);
	}			
}

void LIST :: display()
{
	cout << "\nList : ";
	LinkedNode ptr = start;
	while (ptr != NULL)
	{
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
	cout << endl;
}	

int main(void)
{
	cout << "List Test " << endl;

	LIST list;
	int val, choice;
	
	while (1)
	{	
		cout << "\nList Operations : " << endl;
		cout << "1. insert at front\n2. delete at front\n3. display\n4. Quit" << endl;
		cin >> choice;
		switch(choice)
		{
        	case 1:
            		cout << "Enter element to insert" << endl;
            		cin >> val;
            		list.insertAtFront(val);
            		break;
        	case 2:
            		list.deleteAtFront();
            		break;
        	case 3:
            		list.display();
            		break;
		case 4:
            		exit(0);        	
        	default :
            		cout << "Wrong entry " << endl;
        	}    
	}

	return 0;
}

/*

List Test

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
1
Enter element to insert
28

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
1
Enter element to insert
5

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
1
Enter element to insert
19

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
1
Enter element to insert
63

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
3

List : 63 19 5 28

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
2
63 element deleted

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
2
19 element deleted

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
3

List : 5 28

List Operations :
1. insert at front
2. delete at front
3. display
4. Quit
4

*/















