/*
To create ADT that implements the SET concept.
a)Add (new Element) -Place a value into the set
b)Remove (element) Remove the value
c) Contains (element) Return true if element is in collection
d)Size () Return number of values in collection ,Iterator () Return an iterator used to
loop over collection
e)Intersection of two sets,
f)Union of two sets,
g) Difference between two sets, h) Subset
*/

#include <iostream>
using namespace std;

#define MAX 25

class Set
{
private:
	int array[MAX];
	int size;

public:
	Set();
	bool isPresent(int num);
	void add(int num);
	void display();
	void fullDisplay();
	int getSize();
	void remove();
	void sort();
	void findIntersection(Set s1, Set s2);
	void findUnion(Set s1, Set s2);
	void findDifference(Set s1, Set s2);
	void subset(Set s);
	void superset(Set s);
	void clear();
};

Set::Set()
{
	for(int i = 0; i < MAX; i++)
		array[i] = 0;

	size = 0;
}

bool Set::isPresent(int num)
{
	bool flag = false;

	for(int i = 0; i < size; i++)
	{
		if(array[i] == num)
		{
			flag = true;
			break;
		}
	}

	return flag;
}

void Set::add(int num)
{
	if(isPresent(num))
	{
		cout << "Element already present in the set";
		return;
	}
	else
	{
		array[size] = num;
		size++;
	}

	sort();
}

void Set::display()
{
	cout << "Set elements are: ";

	for(int i = 0; i < size; i++)
		cout << array[i] << " ";
}

void Set::fullDisplay()
{
	cout << "Set elements are: ";

	for(int i = 0; i < MAX; i++)
		cout << array[i] << " ";
}

int Set::getSize()
{
	return size;
}

void Set::remove()
{
	int num;
	int index;

	cout << "Enter element to be deleted: ";
	cin >> num;

	if(!isPresent(num))
	{
		cout << "Element not present in the set";
		return;
	}
	else
	{
		for(index = 0; index < size; index++)
		{
			if(array[index] == num)
				break;
		}

		for(int i = (index + 1); i < size; i++)
			array[i - 1] = array[i];

		array[size - 1] = 0;

		size--;

		cout << num << " deleted successfully";
	}
}

void Set::sort()
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void Set::findIntersection(Set s1, Set s2)
{
	for(int i = 0; i < s1.size; i++)
	{
		if(s2.isPresent(s1.array[i]))
		{
			add(s1.array[i]);
		}
	}

	sort();
}

void Set::findUnion(Set s1, Set s2)
{
	for(int i = 0; i < s1.size; i++)
		add(s1.array[i]);

	for(int i = 0; i < s2.size; i++)
	{
		if(!s1.isPresent(s2.array[i]))
			add(s2.array[i]);
	}

	sort();
}

void Set::findDifference(Set s1, Set s2)
{
	for(int i = 0; i < s1.size; i++)
	{
		if(!s2.isPresent(s1.array[i]))
			add(s1.array[i]);
	}

	sort();
}

void Set::subset(Set s)
{
	bool flag = true;

	for(int i = 0; i < s.size; i++)
	{
		if(!isPresent(s.array[i]))
		{
			flag = false;
			break;
		}
	}

	if(flag)
		cout << "Passed set is subset of this set";
	else
		cout << "Passed set is not a subset of this set";
}

void Set::superset(Set s)
{
	bool flag = true;

	for(int i = 0; i < size; i++)
	{
		if(!s.isPresent(array[i]))
		{
			flag = false;
			break;
		}
	}

	if(flag)
		cout << "Passed set is superset of this set";
	else
		cout << "Passed set is not a superset of this set";
}

void Set::clear()
{
	for(int i = 0; i < size; i++)
		array[i] = 0;

	size = 0;
}


int main()
{
	Set s;
	Set s1, s2, s3;
	int choice;
	int setChoice = 1;
	int element;

	while(1)
	{
		cout << endl << endl << "===== ===== Set Operations ===== =====" << endl << endl;

		cout << "1. Add element" << endl;
		cout << "2. Delete element" << endl;
		cout << "3. Check if given element is present" << endl;
		cout << "4. Display size of the set" << endl;
		cout << "5. Find intersection of two sets" << endl;
		cout << "6. Find union of two sets" << endl;
		cout << "7. Find difference of two sets" << endl;
		cout << "8. Check for subset" << endl;
		cout << "9. Check for superset" << endl;
		cout << "10. Change set" << endl;
		cout << "11. Display set" << endl;
		cout << "12. Exit" << endl << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch(choice)
		{
		case 1:
			cout << "Enter element: ";
			cin >> element;

			if(setChoice == 1)
				s1.add(element);
			else
				s2.add(element);

			break;

		case 2:
			if(setChoice == 1)
				s1.remove();
			else
				s2.remove();

			break;

		case 3:
			cout << "Enter element to be checked: ";
			cin >> element;

			if(setChoice == 1)
				s1.isPresent(element);
			else
				s2.isPresent(element);

			break;

		case 4:
			if(setChoice == 1)
				cout << "Size of first set is " << s1.getSize();
			else
				cout << "Size of second set is " << s2.getSize();

			break;

		case 5:
			s3.findIntersection(s1, s2);
			cout << "Intersection of given sets is: ";
			s3.display();
			break;

		case 6:
			s3.findUnion(s1, s2);
			cout << "Union of given sets is: ";
			s3.display();
			break;

		case 7:
			s3.findDifference(s1, s2);
			cout << "Difference of given sets is: ";
			s3.display();
			break;

		case 8:
			s1.subset(s2);
			break;

		case 9:
			s1.superset(s2);
			break;

		case 10:
			if(setChoice == 1)
				setChoice = 2;
			else
				setChoice = 1;
			break;

		case 11:
			if(setChoice == 1)
				s1.display();
			else
				s2.display();
			break;

		case 12:
			return 0;
		}
 	}

}

/* 


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 5


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 4


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 3


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 6


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 3
Element already present in the set

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 8


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 7


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 7
Element already present in the set

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 9


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 11
Set elements are: 3 4 5 6 7 8 9

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 2
Enter element to be deleted: 4
4 deleted successfully

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 11
Set elements are: 3 5 6 7 8 9

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 10


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 2
Enter element to be deleted: 1
Element not present in the set

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 2


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 3


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 4


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 5


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 6


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 1
Enter element: 7


===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 11
Set elements are: 2 3 4 5 6 7

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 4
Size of second set is 6

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 5
Intersection of given sets is: Set elements are: 3 5 6 7

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 6
Union of given sets is: Set elements are: 2 3 4 5 6 7 8 9

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 7
Difference of given sets is: Set elements are: 2 3 4 5 6 7 8 9

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 8
Passed set is not a subset of this set

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 9
Passed set is not a superset of this set

===== ===== Set Operations ===== =====

1. Add element
2. Delete element
3. Check if given element is present
4. Display size of the set
5. Find intersection of two sets
6. Find union of two sets
7. Find difference of two sets
8. Check for subset
9. Check for superset
10. Change set
11. Display set
12. Exit

Enter your choice: 12

--------------------------------
*/
