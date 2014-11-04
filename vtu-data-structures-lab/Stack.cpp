/***************************************************************************
 *File	    	: Stack.cpp
 *Description   : Design, develop, and execute a program in C++ to create 
		  a class called STACK using an array of integers and 
		  to implement the following operations by overloading 
		  the operators + and -. 
		  I) s1 = s1 + element where s1 is an object of 
		     class STACK and the element is an integer 
		     to be pushed on top of the stack. 
		  II) s1 = s1- where s1 is an object of class STACK 
	             and – operator pops off the top element.
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/

#include <iostream>
#include <stdlib.h>

#define STACK_SIZE 100

using namespace std;

class Stack
{    
    	private:
        	int top;
        	int arr[STACK_SIZE];

    	public:
        	Stack()
        	{
            		top = -1;            
        	}        
        	void operator +(int data);
        	int operator -();
        	bool isEmpty();
        	bool isFull();
        	friend ostream & operator << (ostream &ptr, Stack stack);            
};

void Stack :: operator +(int data)
{
	if (isFull())
        {
        	cout << "Overflow exception" << endl;
        	return;
      	}
	arr[++top] = data;
}
int Stack :: operator -()
{
	if (isEmpty())
        {
		cout << "Underflow exception" << endl;
		return -1;
	}
	return arr[top--];
}        
bool Stack :: isEmpty()
{
	return top == -1;
}
bool Stack :: isFull()
{
	return top + 1 == STACK_SIZE;
}

ostream & operator << (ostream &ptr, Stack stack)
{
    	int i;            
    	ptr << "Stack = ";
    	for (i = stack.top; i >= 0; i--)
        	ptr << stack.arr[i] << " ";
    	ptr << "\n" << endl;
    	return ptr;
}       

int main()
{
    	cout << "\nStack Test\n\n";
    
    	Stack stack;
    	int val, choice;
    	char ch;
    	while (1)
    	{
        	cout << "\nStack Operations : \n" << endl;
        	cout << "1. push\n2. pop\n3. display\n4. Quit\n" << endl; 
        	cin >> choice;
        	switch (choice)
        	{
        	case 1 :
            		cout << "Enter element to insert\n";
            		cin >> val;
            		stack + val;
            		break;
        	case 2:
            		val = -stack ;
            		cout << "Popped Value : " << val << endl;
            		break;
        	case 3:
            		cout << stack;
            		break;
        	case 4:
            		exit(0);
        	default :
            		cout << "Wrong entry : \n" << endl;
        	}        
    	} 
    
    	return 0; 
}    

/* 

Stack Test


Stack Operations :

1. push
2. pop
3. display
4. Quit

1
Enter element to insert
4

Stack Operations :

1. push
2. pop
3. display
4. Quit

1
Enter element to insert
8

Stack Operations :

1. push
2. pop
3. display
4. Quit

1
Enter element to insert
6

Stack Operations :

1. push
2. pop
3. display
4. Quit

1
Enter element to insert
2

Stack Operations :

1. push
2. pop
3. display
4. Quit

1
Enter element to insert
5

Stack Operations :

1. push
2. pop
3. display
4. Quit

3
Stack = 5 2 6 8 4


Stack Operations :

1. push
2. pop
3. display
4. Quit

2
Popped Value : 5

Stack Operations :

1. push
2. pop
3. display
4. Quit

2
Popped Value : 2

Stack Operations :

1. push
2. pop
3. display
4. Quit

2
Popped Value : 6

Stack Operations :

1. push
2. pop
3. display
4. Quit

2
Popped Value : 8

Stack Operations :

1. push
2. pop
3. display
4. Quit

2
Popped Value : 4

Stack Operations :

1. push
2. pop
3. display
4. Quit

2
Underflow exception
Popped Value : -1

Stack Operations :

1. push
2. pop
3. display
4. Quit

4

*/