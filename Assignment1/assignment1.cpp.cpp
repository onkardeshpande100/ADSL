//============================================================================
// Name        : assi1.cpp
// Author      : Onkar Deshpande(21315)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;
class Queue;

class TreeNode
{
	char data;
	TreeNode* lchild;
	TreeNode* rchild;
public:
	friend class Tree;
	friend class Queue;
	TreeNode(char x)
{
		data=x;
		lchild=NULL;
		rchild=NULL;
}
};

class QueueNode
{
	TreeNode *dataQueue;
	QueueNode *next;
public:
	friend class Queue;
	friend class Tree;
	QueueNode(TreeNode *temp)
{
		dataQueue=temp;
		next=NULL;
}
};
class Queue
{
	QueueNode *front;
	QueueNode *rear;
public:
	Queue()
{
		front=NULL;
		rear=NULL;
}
	int empty()
	{
		if(front==NULL||rear==NULL)
			return 1;
		return 0;
	}

	void enqueue(TreeNode *AddressOfTreeNode)
	{
		if(empty())
		{
			front=new QueueNode(AddressOfTreeNode);
			rear=front;
			return;
		}
		QueueNode *temp=new QueueNode(AddressOfTreeNode);
		rear->next=temp;
		rear=rear->next;
	}

	TreeNode* dequeue()
	{
		if(empty())
		{
			cout<<endl<<"QUEUE EMPTY"<<endl;
			return NULL;
		}
		if(rear==front)
		{
			TreeNode* temp=front->dataQueue;
			QueueNode* ptr=front;
			delete ptr;
			rear=NULL;
			front=NULL;
			return temp;
		}
		TreeNode* temp=front->dataQueue;
		QueueNode* ptr=front;
		front=front->next;
		delete ptr;
		return temp;
	}


};

class Tree
{
	TreeNode* root;
	Queue q;
	TreeNode* makeTree()
	{
		cout<<endl<<"ENTER THE DATA- ";
		char temp_data;
		cin>>temp_data;
		TreeNode *ptr;
		ptr=new TreeNode(temp_data);
		q.enqueue(ptr);
		return ptr;
	}
public:
	Tree()      //creation of tree in constructor itself
{
		root=makeTree();

}

	void setLeft(TreeNode *p)
	{
		if(p->lchild!=NULL)
		{
			cout<<endl<<"INVALID INSERTION"<<endl;
			return;
		}
		p->lchild=makeTree();
	}

	void setRight(TreeNode *p)
		{
			if(p->rchild!=NULL)
			{
				cout<<endl<<"INVALID INSERTION"<<endl;
				return;
			}
			p->rchild=makeTree();
		}

	

	void insert()
	{
		while(!q.empty())
		{

			TreeNode* p=q.dequeue();
			cout<<endl<<"Do you want to set left child for parent '"<<p->data<<"'?(1/0)"<<endl;
			int ch;
			cin>>ch;
			if(ch==1)
				setLeft(p);

			cout<<endl<<"Do you want to set right child for parent '"<<p->data<<"'?(1/0)"<<endl;
			cin>>ch;
			if(ch==1)
				setRight(p);

		}
	}

	void inorder()
	{
		TreeNode* stack[10];
		int i=0;            //i=0 will be return condition.start stack from i=1
		TreeNode* T=root;   //Node to be travel
		while(1)
		{
			while(T)
			{
				i++;
				stack[i]=T;
				T=T->lchild;
			}
			if(i==0)
				return;

			T=stack[i];
			i--;
			cout<<"-"<<T->data;
			T=T->rchild;
		}
	}

	void preorder()
	{
		TreeNode* stack[10];
		int i=0;            //i=0 will be return condition.start stack from i=1
		TreeNode* T=root;   //Node to be travel
		while(1)
		{

			while(T)
			{
				cout<<"-"<<T->data;
				if(T->rchild!=NULL)
				{
					i++;
					stack[i]=T->rchild;
				}
				T=T->lchild;
			}
			if(i==0)
				return;

			T=stack[i];
			i--;
		}
	}

	void postorder()
	{
		int i=0;
		TreeNode* stack[10];
		TreeNode* T=root;
		while(1)
		{
			i++;
			stack[i]=T;
			if(T->rchild!=NULL)
			{
				i++;
				stack[i]=T->rchild;
				i++;
				stack[i]=NULL;
			}
			if(i==0)
				return;
			while(stack[i]!=NULL && i!=0)
			{
				T=stack[i];
				cout<<"-"<<T->data;
				i--;
			}
			if(i!=0)
				i--;
			if(i==0)
				return;
			T=stack[i];
			i--;
		}
	}
	void PostOrder()
		{
			Post_order(root);
		}
		void Post_order(TreeNode* T)
		{
			if(T!=NULL)
			{
				Post_order(T->lchild);
				Post_order(T->rchild);
				cout<<"-"<<T->data<<"-";
			}
		}
		void Get_Height()
		{
			cout<<endl<<"The Height of the tree is "<<height(root)<<endl;
		}

		int height(TreeNode* T)
		{
			int x=0,y=0;
			if(T==NULL)
				return -1;
			if(T!=NULL)
			{
				x=height(T->lchild);
				y=height(T->rchild);
				if(x>y)
					return x+1;
				else
					return y+1;
			}
			return 0;   //this will never get executed just to avoid warning
		}
	};

	int main() {
		Tree t;
		t.insert();

		do
		{
			cout<<endl<<"1.Postorder traversal"<<endl<<"2.preorder travelsal"<<endl<<"3.Inorder traversal"<<endl<<"4.Mirror Image of tree"<<endl<<"5.Height of tree"<<endl<<"0.Exit"<<endl;
			cout<<endl<<"Choose one-";
			int choice;
			cin>>choice;

			switch(choice)
			{
			case 1:
				cout<<endl<<"The postorder traversal will be-"<<endl<<"\t";
				t.PostOrder();
				break;
			case 2:
				cout<<endl<<"The preorder traversal will be-"<<endl<<"\t";
				t.preorder();
				break;
			case 3:
				cout<<endl<<"The inorder traversal will be-"<<endl<<"\t";
				t.inorder();
				break;
			case 0:
				exit(0);
				break;
			case 5:
				t.Get_Height();
				break;
			default:
				cout<<endl<<"Wrong choice"<<endl;
				break;
			}
		}while(1);
	}

//OUTPUT-

/* ===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 1
Enter root data : 1
Do you want to enter left child of 1? (1/0) 1
Enter data : 2
Do you want to enter right child of 1? (1/0) 1
Enter data : 3
Do you want to enter left child of 2? (1/0) 1
Enter data : 4
Do you want to enter right child of 2? (1/0) 1
Enter data : 5
Do you want to enter left child of 3? (1/0) 1
Enter data : 6
Do you want to enter right child of 3? (1/0) 1
Enter data : 7
Do you want to enter left child of 4? (1/0) 1
Enter data : 8
Do you want to enter right child of 4? (1/0) 0
Do you want to enter left child of 5? (1/0) 0
Do you want to enter right child of 5? (1/0) 0
Do you want to enter left child of 6? (1/0) 1
Enter data : 9
Do you want to enter right child of 6? (1/0) 0
Do you want to enter left child of 7? (1/0) 0
Do you want to enter right child of 7? (1/0) 0
Do you want to enter left child of 8? (1/0) 0
Do you want to enter right child of 8? (1/0) 0
Do you want to enter left child of 9? (1/0) 0
Do you want to enter right child of 9? (1/0) 0


===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 2
1 2 4 8 5 3 6 9 7

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 3
8 4 2 5 1 9 6 3 7

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 4
8 4 5 2 9 6 7 3 1

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 5
Height = 4

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 6
Number of leaves = 4

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 7
Number of internal nodes = 5

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 10
Inorder traversal of original tree - 8 4 2 5 1 9 6 3 7
Inorder traversal of copied tree - 8 4 2 5 1 9 6 3 7

===== ===== ===== Tree Operations ===== ===== =====

1. Create Binary Tree
2. Pre-Order Traversal
3. In-Order Traversal
4. Post-Order Traversal
5. Find height of the tree
6. Find the number of leaves
7. Find the number of internal nodes
8. Find mirror image of the tree
9. Delete entire tree
10. Copy one tree into another
20. Exit
Enter your choice : 20 */




