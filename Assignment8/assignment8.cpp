//============================================================================
// Name        : assignment8.cpp
// Author      : Onkar Deshpande(21315)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class AVL;
class AVLnode
{
	string word;
	string meaning;
	AVLnode *left,*right;
	friend class AVL;
public:
	AVLnode(string tempWord,string tempMeaning)
	{
		word=tempWord;
		meaning=tempMeaning;
		left=right=NULL;
	}
};

class AVL
{
	AVLnode *root;
public:
	AVL()
	{
		root=NULL;
	}

	void DataAcscending()
	{
		cout<<endl<<"The list of words on dictionary- "<<endl;
		AscendingWordsReccursive(root);
	}

	void AscendingWordsReccursive(AVLnode* T)
	{
		if(T!=NULL)
		{
			AscendingWordsReccursive(T->left);
			cout<<endl<<"\t "<<T->word<<" -\t"<<T->meaning;
			AscendingWordsReccursive(T->right);
		}
	}

	void insertCall()
	{
		string tempWord;
		cout<<endl<<"Enter the word- ";
		cin>>ws;
		getline(cin,tempWord);
		root=insert(root,tempWord);
	}
	AVLnode* insert(AVLnode* T,string tempWord)
	{
		string tempMeaning;
		if(T==NULL)
		{
			cout<<endl<<"Enter the meaning-";
			cin>>ws;
			getline(cin,tempMeaning);
			T=new AVLnode(tempWord,tempMeaning);
			return T;
		}
		int compareStringResult=compareStrings(tempWord,T->word);
			// The above variable is toa avoid repetative comparisons & store the result of the comparison
			// =0  -> strings equal
			// =1  -> tempWord is greater than word at T node (non-case sensitive)
			// =-1 -> tempWord is less than word at T node (non-case sensitive)=
		if(compareStringResult == -1)
		{
			T->left=insert(T->left,tempWord);
			if( balanceFactor(T) == 2 ||  balanceFactor(T) == -2 )
			{
				if(compareStrings(tempWord,T->left->word) == -1) //left is lesser
					T=LL(T);
				else
					T=LR(T);
			}
			return T;
		}
		else if(compareStringResult == 1)
		{
			T->right=insert(T->right,tempWord);
			if(balanceFactor(T) == 2 || balanceFactor(T) == -2)
			{
				if(compareStrings(tempWord,T->right->word) == 1)
					T=RR(T);
				else
					T=RL(T);
			}
			return T;
		}
		else  //=0
		{
			cout<<endl<<"The Word Already existed"<<endl;
			return T;
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


	AVLnode* LL(AVLnode* T)
	{
		AVLnode* Y;
		Y=T->left;
		T->left=Y->right;
		Y->right=T;
		return Y;
	}

	AVLnode* RR(AVLnode* T)
	{
		AVLnode* Y;
		Y=T->right;
		T->right=Y->left;
		Y->left=T;
		return Y;
	}

	AVLnode* LR(AVLnode* T)
	{
		AVLnode *P,*Y;
		Y=T->left;
		P=Y->right;
		Y->right=P->left;
		P->left=Y;
		T=LL(T);
		return T;
	}

	AVLnode* RL(AVLnode* T)
	{
		AVLnode *P,*Y;
		Y=T->right;
		P=Y->left;
		Y->left=P->right;
		P->right=Y;
		T=RR(T);
		return T;
	}

	int height(AVLnode *T)
	{
		int h1,h2;
		if(T==NULL)
			return -1;
		h1=height(T->left);
		h2=height(T->right);
		if(h1>h2)
			return (h1+1);
		else
			return (h2+1);
		//(h1>h2) ? return (h1+1):return (h2+1);
	}
	int balanceFactor(AVLnode *T)
	{
		int hl=0,hr=0;
		if(T->left!=NULL)
			hl=1+height(T->left);
		if(T->right!=NULL)
			hr=1+height(T->right);
		return (hl-hr);
	}

	void deleteCall()
	{
		string tempWord;
		cout<<endl<<"Enter the word to delete- ";
		cin>>ws;
		getline(cin,tempWord);
		root=deleteWord(root,tempWord);


	}

	AVLnode* deleteWord(AVLnode* T,string tempWord)
	{
		if(T==NULL)
		{
			cout<<endl<<"No Such Word found in my dictionary1"<<endl;
			return T;
		}

		int compareStringResult=compareStrings(tempWord,T->word);
		// The above variable is toa avoid repetative comparisons & store the result of the comparison
					// =0  -> strings equal
					// =1  -> tempWord is greater than word at T node (non-case sensitive)
					// =-1 -> tempWord is less than word at T node (non-case sensitive)=
		if(compareStringResult == -1)
		{
			T->left=deleteWord(T->left,tempWord);
			if(balanceFactor(T) == -2)
			{
				if(balanceFactor(T->right) <= 0)
					T=LL(T);
				else
					T=LR(T);
			}
			return T;
		}
		if(compareStringResult == 1)
		{
			T->right=deleteWord(T->right,tempWord);
			if(balanceFactor(T) == 2)
			{
				if(balanceFactor(T->left) >= 0)
					T=RR(T);
				else
					T=RL(T);
			}
			return T;
		}

		//now the actual deletion after getting the word with all cases
		if(T->left == NULL && T->right == NULL)
		{
			delete T;
			return NULL;
		}
		if(T->right == NULL)
		{
			AVLnode* P=T->left;
			delete T;
			return P;
		}
		if(T->left == NULL)
		{
			AVLnode* P=T->right;
			delete T;
			return P;
		}
		AVLnode* P;
		P=T->right;
		while(P->left!=NULL){
			P=P->left;
		}
		T->word=P->word;
		T->right=deleteWord(T->right,P->word);
		if(balanceFactor(T)==2)
		{
			if(balanceFactor(T->left)>=0)
				T=LL(T);
			else
				T=LR(T);
		}
		return T;
	}
	//return T;
};
int main() {
	AVL dictionary;
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
			dictionary.insertCall();
			break;
		case 2:
			cout<<endl<<"Enter the number of words to be entered- ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				dictionary.insertCall();
			}
			break;
		/*case 3:
			dictionary.search();
			break;*/
		case 4:
			dictionary.deleteCall();
			break;
		case 5:
			dictionary.DataAcscending();
			break;
		/*case 6:
			dictionary.DataDescending();
			break;
		case 7:
			dictionary.updateWord();
				break;*/
		case 0:
			exit(0);
			break;
		default:
			cout<<endl<<"Wrong choice entered!!"<<endl;
			break;
		}
	}while(1);


}
