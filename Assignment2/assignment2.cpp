//============================================================================
// Name        : assignment2.cpp
// Author      : Onkar Deshpande(21315)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

 /* Problem Statement- A Dictionary stores keywords & its meanings. Provide facility for adding
new keywords, deleting keywords, updating values of any entry, assign a
given tree into another tree (=). Provide facility to display whole data
sorted in ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword. Use Binary Search
Tree for implementation.
  *
  *
  *
  */

#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Tree;
class TreeNode
{
	string word;
	string meaning;
	TreeNode *lchild,*rchild;
	friend class Tree;
public:
	TreeNode(string w,string m)
	{
		word=w;
		meaning=m;
		lchild=rchild=NULL;
	}
};

class Tree
{
	TreeNode *root;
public:
	Tree()
	{
		root=NULL;
	}


	void insert()
	{
		cout<<endl<<"ENTER THE WORD:- ";
		string tempWord,tempMeaning;
		cin>>ws;
		getline(cin,tempWord);
		cout<<endl<<"ENTER THE MEANING:- ";
		cin>>ws;
		getline(cin,tempMeaning);

		TreeNode* T=root;

		if(T==NULL)
		{
			root=new TreeNode(tempWord,tempMeaning);
			return;
		}
		int compareResult;  //this will avoid the number of time comapre is executed
		while(1)
		{
			compareResult=compareStrings(tempWord,T->word);
			if(compareResult==0)
			{
				cout<<endl<<"Word already exist!"<<endl;
				return;
			}
			if(compareResult==-1)
			{
				if(T->lchild==NULL)
				{
					T->lchild=new TreeNode(tempWord,tempMeaning);
					return;
				}
				if(T->lchild!=NULL)
					T=T->lchild;
			}
			else if(compareResult==1)
			{
				if(T->rchild==NULL)
				{
					T->rchild=new TreeNode(tempWord,tempMeaning);
					return;
				}
				else
					T=T->rchild;
			}
		}
	}

	void convertUpperToLower(char &a)
	{
		a+=32;
	}
	int compareStrings(string a,string b) //a=to be entered,b=node's word(data)
	{
		int i=0;
		while(a[i]!='\0' && b[i]!='\0')
		{

			/*whatever we comparing,both should be on lower case*/

			if(a[i]>=65 && a[i]<=90)//convert a[i] to lower case
			{
				convertUpperToLower(a[i]);
			}

			if(b[i]>=65 && b[i]<=90)//convert b[i] to lower case
			{
				convertUpperToLower(b[i]);
			}
			if(a[i]==b[i])
			{
				i++;
				continue;
			}
			else if(a[i]<b[i])
				return -1;
			else
				return 1;
		}
		if(a[i]=='\0' && b[i]=='\0')
			return 0;
		if(a[i]=='\0' || b[i]!='\0')
			return -1;
		if(a[i]!='\0' || b[i]=='\0')
			return 1;
		//else
		return 0;  //this case will never occur,just to avoid the warning
	}


	void search()
	{
		cout<<endl<<"Enter the word to be searched- ";
		string key;
		int comparisons=0;
		cin>>ws;
		getline(cin,key);
		TreeNode* T=root;
		while(T)
		{
			comparisons++;
			if(compareStrings(key,T->word)==0)  //if word is found on T
			{
				cout<<endl<<"Word Found-"<<endl;
				cout<<endl<<endl<<"\t "<<T->word<<"- "<<T->meaning<<endl<<endl;
				cout<<endl<<"Total number of comparisons- "<<comparisons<<endl;
				return;
			}
			if(compareStrings(key,T->word)==-1)   //if key < T->word
				T=T->lchild;
			else if(compareStrings(key,T->word)==1)   //if key > T->word
				T=T->rchild;


		}

		cout<<endl<<"The Word is not present in my dictionary!! "<<endl;

	}


	void DataAcscending()
	{
		cout<<endl<<"The list of words on dictionary- "<<endl;
		AscendingWordsReccursive(root);
	}

	void AscendingWordsReccursive(TreeNode* T)
	{
		if(T!=NULL)
		{
			AscendingWordsReccursive(T->lchild);
			cout<<endl<<"\t "<<T->word<<" -\t"<<T->meaning;
			AscendingWordsReccursive(T->rchild);
		}
	}


	void DataDescending()
		{
			cout<<endl<<"The list of words on dictionary- "<<endl;
			DescendingWordsReccursive(root);
		}

	void DescendingWordsReccursive(TreeNode* T)
	{
		if(T!=NULL)
		{
			DescendingWordsReccursive(T->rchild);
			cout<<endl<<"\t "<<T->word<<" -\t"<<T->meaning;
			DescendingWordsReccursive(T->lchild);
		}
	}

	void updateWord()
	{
		cout<<endl<<"Enter the word to be updated- ";
		string key;
		cin>>ws;
		getline(cin,key);
		TreeNode* T=root;
		int compareResult;
		while(T)
		{
			compareResult=compareStrings(key,T->word);
			if(compareResult==0)
			{
				cout<<endl<<"Enter the Updatation:\n \t Enter the word- ";
				cin>>ws;
				getline(cin,T->word);
				cout<<endl<<"\t Enter the meaning- ";
				cin>>ws;
				getline(cin,T->meaning);
				cout<<endl<<"UPDATE SUCCESSFULL"<<endl;
				return;
			}
			if(compareResult==-1)
			{
				T=T->lchild;
				continue;
			}
			else
			{
				T=T->rchild;
				continue;
			}
		}
		cout<<endl<<"WORD NOT FOUND IN MY DICTIONARY!!"<<endl;
	}




		void AI_DATA_INPUT()
		{

		}
};
int main() {
	Tree dictionary;
	do
	{
		cout<<endl<<"*** WELCOME TO MINDPALACE ***"<<endl<<endl;

		int n;   //for case 2
		cout<<endl<<"1.Add word and its meaning(Non-case-sensitive)"<<endl<<"2.Add many words at a time"<<endl<<"3.Search for a word and get its comparisons(Non-case-sensitive)"<<endl<<"4.Delete Word"<<endl<<"5.Show all words in ascending order"<<endl<<"6.Show all words in descending order"<<endl<<"7.Update a word & meaning"<<endl<<"0.Exit"<<endl<<"choose one-";
		int choice;
		cin>>choice;

		switch(choice)
		{
		case 1:
			dictionary.insert();
			break;
		case 2:
			cout<<endl<<"Enter the number of words to be entered- ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				dictionary.insert();
			}
			break;
		case 3:
			dictionary.search();
			break;
		case 4:
			break;
		case 5:
			dictionary.DataAcscending();
			break;
		case 6:
			dictionary.DataDescending();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout<<endl<<"Wrong choice entered!!"<<endl;
			break;
		}
	}while(1);


}


/* OUTPUT:
	===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : distress
Enter meaning : trouble


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : portion
Enter meaning : part
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : idle
Enter meaning : lazy
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : stout
Enter meaning : fat
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : disclose
Enter meaning : reveal
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : glum
Enter meaning : moody
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : loathe
Enter meaning : hate
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 1
Enter word : stop
Enter meaning : end
Word inserted


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 5
disclose : reveal
distress : trouble
glum : moody
idle : lazy
loathe : hate
portion : part
stop : end
stout : fat


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 6
stout : fat
stop : end
portion : part
loathe : hate
idle : lazy
glum : moody
distress : trouble
disclose : reveal


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 3
Enter word to be searched : glum
Word found
Meaning of glum is moody

===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 4
Enter word to be updated : portion
Enter new meaning of portion : piece


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 5
disclose : reveal
distress : trouble
glum : moody
idle : lazy
loathe : hate
portion : piece
stop : end
stout : fat


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 6
stout : fat
stop : end
portion : piece
loathe : hate
idle : lazy
glum : moody
distress : trouble
disclose : reveal


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 7
Original dictionary
disclose : reveal
distress : trouble
glum : moody
idle : lazy
loathe : hate
portion : piece
stop : end
stout : fat
Cloned dictionary
disclose : reveal
distress : trouble
glum : moody
idle : lazy
loathe : hate
portion : piece
stop : end
stout : fat


===== ===== ===== Dictionary ===== ===== =====

1. Insert a word
3. Search a word
4. Update a word
5. Print dictionary
6. Print reverse dictionary
7. Copy one dictionary into other
10. Exit

Enter your choice : 10
*/