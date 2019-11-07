/* Create an inordered threaded binary tree and perform inorder and preorder traversals.
 * Analyze time and space complexity of the algorithm
 */

#include <iostream>
using namespace std;

// ===== ===== ===== ===== ===== =====

class TreeNode
{
private:
	int data;
	bool leftBit, rightBit;
	TreeNode *left, *right;
	friend class Tree;

public:
	TreeNode();
};

// Default Constructor
TreeNode::TreeNode()
{
	data = 0;
	leftBit = rightBit = false;
	left = right = NULL;
}

// ===== ===== ===== ===== ===== =====

class Tree
{
private:
	TreeNode dummy;

public:
	Tree();
	TreeNode * getRoot();
	void insert();
	void inorder_traversal();
	void preorder_traversal(TreeNode *r);
	TreeNode * getSuccessor(TreeNode *r);
};

Tree::Tree()
{
	dummy.data = 0;

	dummy.rightBit = true;
	dummy.leftBit = false;

	dummy.right = &dummy;
	dummy.left = &dummy;
}

TreeNode * Tree::getRoot()
{
	return dummy.left;
}

void Tree::insert()
{
	TreeNode *newNode = new TreeNode();
	TreeNode *current;

	cout << "Enter data : ";
	cin >> newNode->data;

	if(dummy.leftBit == 0)
	{
		dummy.left = newNode;
		dummy.leftBit = true;

		newNode->left = newNode->right = &dummy;

		return;
	}

	current = dummy.left;

	while(1)
	{
		if(current->data == newNode->data)
		{
			cout << "Element already present";
			return;
		}

		if(current->data > newNode->data)
		{
			if(current->leftBit == false)
			{
				newNode->left = current->left;
				current->left = newNode;
				current->leftBit = true;
				newNode->right = current;

				return;
			}
			else
				current = current->left;

		}

		if(current->data < newNode->data)
		{
			if(current->rightBit == false)
			{
				newNode->right = current->right;
				current->right = newNode;
				current->rightBit = true;
				newNode->left = current;

				return;
			}
			else
				current = current->right;

		}
	}
}

TreeNode * Tree::getSuccessor(TreeNode *r)
{
	TreeNode *successor = r;

	if(r->rightBit == false)
		successor = r->right;

	else if(r->right->leftBit == false)
		successor = r->right;

	else
	{
		successor = r->right;

		while(successor->leftBit != false)
			successor = successor->left;
	}

	return successor;
}

void Tree::inorder_traversal()
{
	TreeNode *current = dummy.left;

	while(current->leftBit != false)
		current = current->left;

	while(current != &dummy)
	{
		cout << current->data << " ";
		current = getSuccessor(current);
	}
}

void Tree::preorder_traversal(TreeNode *r)
{
	cout << r->data << " ";

	if(r->leftBit != 0)
		preorder_traversal(r->left);
	if(r->rightBit != 0)
		preorder_traversal(r->right);
}

// ===== ===== ===== ===== ===== =====

int main()
{
	Tree t;
	int choice;

	while(1)
	{
		cout << endl << endl << "===== ===== ===== Threaded Binary Tree Operations ===== ===== =====" << endl << endl;

		cout << "1. Insert" << endl;
		cout << "2. Inorder Traversal" << endl;
		cout << "3. Preorder Traversal" << endl;
		cout << "4. Exit" << endl << endl;

		cout << "Enter your choice : ";
		cin >> choice;

		switch(choice)
		{
		case 1:
			t.insert();
			break;

		case 2:
			t.inorder_traversal();
			break;

		case 3:
			t.preorder_traversal(t.getRoot());
			break;

		case 4:
			return 0;

		default:
			cout << "Invalid choice";
		}
	}
}

/* 
===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 10


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 50


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 40


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 30


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 90


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 70


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 20


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 1
Enter data : 80


===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 2
10 20 30 40 50 70 80 90

===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 3
10 50 40 30 20 90 70 80

===== ===== ===== Threaded Binary Tree Operations ===== ===== =====

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Exit

Enter your choice : 4
*/
