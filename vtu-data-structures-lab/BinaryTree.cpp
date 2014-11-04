/***************************************************************************
 *File		: BinaryTree.cpp
 *Description	: Design, develop, and execute a program in C++ to create a 
		  class called BIN_TREE that represents a binary tree with
		  member functions to perform inorder, preorder and postorder
		  traversals. Create a BIN_TREE object and demonstrate the
		  traversals.
		  	
 *Author	: Sujith V
 *Compiler	: MinGW (GCC) compiler, Windows 8
 *Date		: 3 November 2013
***************************************************************************/


#include <iostream>
#include <stdlib.h>

using namespace std;

class BIN_TREE
{
	private :
		struct node
		{
			int data;
			struct node *left, *right;
		};
		typedef struct node *BTNode;

		BTNode root;

		BTNode newNode(int val)
		{
			BTNode nptr = (BTNode) malloc (sizeof(struct node));
			nptr -> data = val;
			nptr -> left = NULL;
			nptr -> right = NULL;
		}
	public :
		BIN_TREE()
		{
			root = NULL;
		}		
		void insert(int val);
		BTNode insert(BTNode root, int val);
		void inorder();
		void inorder(BTNode ptr);
		void preorder();
		void preorder(BTNode ptr);
		void postorder();
		void postorder(BTNode ptr);
};

void BIN_TREE :: insert(int val)
{
	root = insert(root, val);
}
BIN_TREE :: BTNode BIN_TREE :: insert(BTNode root, int val)
{
	if (root == NULL)
		root = newNode(val);
	else
	{
		if (val <= root -> data)
			root -> left = insert(root -> left, val);
		else
			root -> right = insert(root -> right, val);
	}
}
void BIN_TREE :: inorder()
{
	cout << "Inorder traversal : ";
	inorder(root);
	cout << endl;
}
void BIN_TREE :: inorder(BTNode ptr)
{
	if (ptr != NULL)
	{
		inorder(ptr -> left);
		cout << ptr -> data << " ";
		inorder(ptr -> right);
	}
}
void BIN_TREE :: preorder()
{
	cout << "Preorder traversal : ";
	preorder(root);
	cout << endl;
}
void BIN_TREE :: preorder(BTNode ptr)
{
	if (ptr != NULL)
	{	
		cout << ptr -> data << " ";
		preorder(ptr -> left);				
		preorder(ptr -> right);
	}
}
void BIN_TREE :: postorder()
{
	cout << "Postorder traversal : ";
	postorder(root);
	cout << endl;
}
void BIN_TREE :: postorder(BTNode ptr)
{
	if (ptr != NULL)
	{					
		postorder(ptr -> left);				
		postorder(ptr -> right);
		cout << ptr -> data << " ";
	}
}

int main(void)
{
	cout << "Binary Tree Test " << endl;

	BIN_TREE bt;
	int val, choice;
	
	while (1)
	{
		cout << "\nBinary Tree Operations : " << endl;
		cout << "1. insert\n2. inorder traversal\n3. preorder traversal\n4. postorder traversal\n5. Quit" << endl;
		cin >> choice;
		switch(choice)
		{
        	case 1:
            		cout << "Enter element to insert" << endl;
            		cin >> val;
            		bt.insert(val);
            		break;
        	case 2:
            		bt.inorder();
            		break;
        	case 3:
            		bt.preorder();
            		break;
		case 4:
            		bt.postorder();
            		break;
        	case 5:
            		exit(0);        	
        	default :
            		cout << "Wrong entry " << endl;
        	}    
	}

	return 0;
}

/* Output :

Binary Tree Test

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
24

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
6

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
19

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
94

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
28

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
5

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
1
Enter element to insert
63

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
2
Inorder traversal : 5 6 19 24 28 63 94

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
3
Preorder traversal : 24 6 5 19 94 28 63

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
4
Postorder traversal : 5 19 6 63 28 94 24

Binary Tree Operations :
1. insert
2. inorder traversal
3. preorder traversal
4. postorder traversal
5. Quit
5

*/












