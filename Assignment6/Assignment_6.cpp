/*
 * Implement all the functions of a dictionary (ADT) OR directory of phonebook using
 * hashing. Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
 * comparable, Keys must be unique Standard Operations: Insert(key, value),
 * Find(key), Delete(key) (use linear probing with replacement and without
 * replacement)
 */

#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;
class Word
	{
		string w,m;
		public:
		friend class Dictionary;
		void operator =(Word w1)
		{
			w=w1.w;
			m=w1.m;
		}	
		void printWord()
		{
			cout<<w<<"\t"<<m<<endl;
		}	
	};
	
class Dictionary
{
 Word s[26];
 bool rf;
 public:
	void create();
	void addWord();
	void search();
	void del();
	int hash(char);
	void printTable();
};

void Dictionary::printTable()
{
	int i;
	for(i=0;i<26;i++)
	{
		cout<<i<<"\t";
		s[i].printWord();
	}
}
	
	
void Dictionary::create()
{
	Word N;
	N.w=N.m='\0';
	int i;
	for(i=0;i<26;i++)
	{
		s[i]=N;
	}
	cout<<"Enter 1 for hashing with replacement, 0 for hashing without replacement."<<endl;
	cin>>rf;
}
int Dictionary::hash(char c)
{
	if(c>=97)
	{
		return(c-97);
	}
	return(c-65);
}
void Dictionary::addWord()
{
	Word a,a1;
	int b,i=0;
	cout<<"Enter Word."<<endl;
	cin.ignore();
	getline(cin,a.w);
	cout<<"Enter meaning."<<endl;
	getline(cin,a.m);
	b=hash(a.w[0]);
	if(rf&&hash(s[b].w[0])!=b)
	{
		a1=s[b];
		s[b]=a;
		a=a1;
		i=1;
	}
	
	for(;s[b+i].w[0]!='\0';)
	{
		if((b+i)==25)
			i=-1-b;
		i++;
		if(i==0)
		{
			cout<<"Full. Cannot add new Word."<<endl;
			return;
		}	
	}
	s[b+i]=a;
	
}
void Dictionary::search()
{
	string s1;
	cout<<"Enter Word to be searched."<<endl;
	
	cin.ignore();
	getline(cin,s1);
	int i,b;
	b=hash(s1[0]);
	for(i=0;s[b+i].w!=s1;)
	{
		if((b+i)==25)
			i=-b-1;
		i++;
		if(i==0)
		{
			cout<<"Word not found."<<endl;
			return;
		}
	}
	cout<<"Meaning : "<<s[b+i].m<<endl;
}
void Dictionary::del()
{
	Word N;
	N.w=N.m='\0';
	string s1;
	cout<<"Enter Word to be deleted."<<endl;
	
	cin.ignore();
	getline(cin,s1);
	int i,b;
	b=hash(s1[0]);
	for(i=0;s[b+i].w!=s1;)
	{
		if((b+i)==25)
			i=-b-1;
		i++;
		if(i==0)
		{
			cout<<"Word not found.Cannot delete."<<endl;
			return;
		}
	}
	s[i+b]=N;
}

int main()
{
	Dictionary d;
	int op;
	d.create();
	cout<<"Options.\n1.Enter a new Word.\n2.Search meaning of a Word.\n3.Delete a Word.\n4.Print all Words of Dictionary.\n5.Exit."<<endl;
	do
	{
		cout<<"Select an option."<<endl;
		cin>>op;
		switch(op)
		{
			case 1:d.addWord();
			break;
			
			case 2:d.search();
			break;
			
			case 3:d.del();
			break;
			
			case 4:d.printTable();
			break;
			
			case 5:break;
			
			default:cout<<"Enter valid option."<<endl;
			
		}
	}while(op!=5);
	
	return 0;
}

/*
Enter 1 for hashing with replacement, 0 for hashing without replacement.
1
Options.
1.Enter a new Word.
2.Search meaning of a Word.
3.Delete a Word.
4.Print all Words of Dictionary.
5.Exit.
Select an option.
1
Enter Word.
idle
Enter meaning.
lazy
Select an option.
1
Enter Word.
stout
Enter meaning.
fat
Select an option.
1
Enter Word.
show
Enter meaning.
display
Select an option.
1
Enter Word.
dull
Enter meaning.
boring
Select an option.
1
Enter Word.
eager
Enter meaning.
keen
Select an option.
4
0
1
2
3       dull    boring
4       eager   keen
5
6
7
8       idle    lazy
9
10
11
12
13
14
15
16
17
18      stout   fat
19      show    display
20
21
22
23
24
25
Select an option.
1
Enter Word.
end
Enter meaning.
stop
Select an option.
4
0
1
2
3       dull    boring
4       eager   keen
5       end     stop
6
7
8       idle    lazy
9
10
11
12
13
14
15
16
17
18      stout   fat
19      show    display
20
21
22
23
24
25
Select an option.
2
Enter Word to be searched.
end
Meaning : stop
Select an option.
3
Enter Word to be deleted.
end
Select an option.
4
0
1
2
3       dull    boring
4       eager   keen
5
6
7
8       idle    lazy
9
10
11
12
13
14
15
16
17
18      stout   fat
19      show    display
20
21
22
23
24
25
Select an option.
5
*/
