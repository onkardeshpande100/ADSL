//============================================================================
// Name        : assignment4.cpp
// Author      : Onkar Deshpande(21315)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



/*PROBLEM STATEMENT- There are flight paths between cities. If there is a flight between city A and city B
 *	then there is an edge between the cities. The cost of the edge can be the time that
 *	flight takes to reach city B from A, or the amount of fuel used for the journey.
 *	Represent this as a graph. The node can be represented by airport name or name of
 *	the city. Use adjacency list representation of the graph or use adjacency matrix
 *	representation of the graph. Justify the storage representation used.(Operation to be
 *	performed adding and deleting edge, adding and deleting vertices, calculated in-
 *	degree and out-degree for directed graph and degree of a node in undirected graph,
 *	Use any traversal to traverse through the graph)
 */



#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class FlightSystem;
class HeadArrayNode;
class Port
{
	string city;
	int distance;
	Port* next;
	friend class FlightSystem;
	friend class HeadArrayNode;
public:
	Port(string temp,int x)
	{
		city=temp;
		distance=x;
		next=NULL;
	}
};

class HeadArrayNode
{
	string portName;
	Port *link;
	friend class Port;
	friend class FlightSystem;
};
class FlightSystem
{
	HeadArrayNode head[20];
	int totalPorts;
public:
	FlightSystem()
	{
		for(int i=0;i<20;i++)
			head[i].link=NULL;
		totalPorts=-1;   //initially no port will be present.
	}

	void AddCity()
	{
		string tempPort;
		cout<<endl<<"Enter the Name of airport- ";
		cin>>ws;
		getline(cin,tempPort);
		for(int i=0;i<=totalPorts;i++)
		{
			if(tempPort==head[i].portName)
			{
				cout<<endl<<"This airport already exists!!"<<endl;
				return;
			}
		}
		totalPorts++;
		head[totalPorts].portName=tempPort;
		cout<<endl<<"New Airport "<<tempPort<<" created!"<<endl;
	}

	void addFlight()
	{
		cout<<endl<<"Enter the source airport- \n\t";
		string source,destination;
		cin>>ws;
		getline(cin,source);
		for(int i=0;i<=totalPorts;i++)
		{
			if(source==head[i].portName)
			{
				cout<<endl<<"Enter the destination airport- \n\t";
				cin>>ws;
				getline(cin,destination);
				for(int i=0;i<=totalPorts;i++)
				{
					if(destination==head[i].portName)
					{
						Port* T=head[i].link;
						while(T)
						{
							if(T->city==destination)
							{
								cout<<endl<<"Flight already exists!!"<<endl<<endl;
								return;
							}
							T=T->next;
						}
						int distance;
						cout<<endl<<"Enter the distance between the cities- ";
						cin>>distance;
						T=head[i].link;
						Port* P=new Port(destination,distance);
						P->next=T;
						head[i].link=P;
						cout<<endl<<"FLIGHT ADDED SUCCESSFULLY!!!"<<endl<<endl;
						return;
					}

				}
				cout<<endl<<"No such destination airport"
						" found!!"<<endl;
				return;
			}

		}
		cout<<endl<<"No such source airport found!!"<<endl;
		return;

	}

	void showPorts()
	{
		cout<<endl<<"Total Airports connected to us- "<<totalPorts+1<<endl;
		cout<<endl<<"ALL AIRPORTS CONNECTED TO US ARE - \n\t";
		for(int i=-1;i<totalPorts;i++)
		{
			cout<<endl<<i+2<<")"<<head[i+1].portName<<endl<<"\t";
		}


	}

	void showFlights()
	{
		int index=0;
		cout<<endl<<"ALL FLIGHTS AVAILABLE- "<<endl<<"\t";
		for(int i=0;i<=totalPorts;i++)
		{
			Port* T=head[i].link;
			while(T)
			{
				index++;
				cout<<endl<<"\t"<<index<<") "<<head[i].portName<<"\t-->\t"<<T->city<<"\t distance- "<<T->distance<<endl;
				T=T->next;
			}
		}
	}


	void deleteFlight()
	{
		cout<<endl<<"Enter the source of the Flight- "<<endl;
		string source,destinaton;
		cin>>ws;
		getline(cin,source);
		for(int i=0;i<=totalPorts;i++)
		{
			if(head[i].portName==source)
			{
				Port* T=head[i].link;
				Port* P=T;
				cout<<endl<<"Enter the destination -"<<endl;
				cin>>ws;
				getline(cin,destinaton);
				while(T)
				{
					if(destinaton==T->city)
					{
						P->next=T->next;
						delete T;
						return;
					}
					P=T;
					T=T->next;
				}
				cout<<endl<<" NO SUCH FLIGHT FOUND!!"<<endl;
				return;
			}
		}
		cout<<endl<<"NO SUCH FLIGHT FOUND!!"<<endl;
	}

	void deletePort()
	{
		cout<<endl<<"Enter the airport to be deleted- "<<endl;
		string city;
		cin>>ws;
		getline(cin,city);
		for(int i=0;i<=totalPorts;i++)
		{
			if(head[i].portName==city)
			{
				Port* T=head[i].link;
				Port* P;
				while(T)
				{
					T=head[i].link;
					P=T;
					while(T)
					{
						P=T;
						T=T->next;
					}
					if(P)
						delete P;
				}
				head[i].link=head[totalPorts].link;
				head[i].portName=head[totalPorts].portName;
				totalPorts--;
				return;
			}
		}
		cout<<endl<<"No such airport found!!"<<endl;
	}

	void DFS_call()
	{
		int x=totalPorts+1;
		int visited[x];
		for(int i=0;i<x;i++)
			visited[i]=0;

		cout<<endl<<"The Traversal of the flight graph gives these cities as connected-"<<endl<<endl;

		DFS_traversal(0,head[0],visited);
	}
	void DFS_traversal(int i,HeadArrayNode T,int visited[])
	{
		if(visited[i]==0)
		{
			cout<<endl<<"\t"<<head[i].portName<<endl;
			visited[i]++;
			Port* T=head[i].link;
			while(T)
			{
				for(int j=0;j<=totalPorts+1;j++)
				{
					if(T->city==head[j].portName)
						if(visited[j]==0)
							DFS_traversal(j,head[i],visited);
				}
				T=T->next;
			}
		}
		else
		{
			
		}
	}

	void indegreeOfPort()
	{
		cout<<endl<<"Enter the name of airport/city-";
		string cityName;
		cin>>ws;
		getline(cin,cityName);
		cout<<endl<<endl<<"Incoming flights are from following ports with distance- "<<endl;
		int count=0;
		for(int i=0;i<=totalPorts;i++)
		{
			if(head[i].portName!=cityName)
			{
				Port* T=head[i].link;
				while(T)
				{
					if(head[i].portName==cityName)
					{
						cout<<"\t "<<head[i].portName<<" ( "<<T->distance<<" ) "<<endl;
						count++;
					}
					T=T->next;
				}
			}
		}
		cout<<endl<<"No of incoming flights(indegree)= "<<count<<endl;
	}

	void outdegreeOfPort()
	{
		cout<<endl<<"Enter the name of airport/city-";
		string cityName;
		cin>>ws;
		getline(cin,cityName);
		int count=0;
		cout<<endl<<"the outgoing flights from "<<cityName<<" are- "<<endl;
		for(int i=0;i<=totalPorts;i++)
		{
			if(head[i].portName==cityName)
			{
				Port* T=head[i].link;
				while(T)
				{
					cout<<"\t "<<T->city<<" ( "<<T->distance<<" ) "<<endl;
					count++;
					T=T->next;
				}
				cout<<endl<<"the total outgoing flights (outdegree)-"<<count<<endl;
				return;
			}
		}
	}
};
int main() {
	FlightSystem obj;
	int choice;

	do
	{
		cout<<endl<<"\t**** FLIGHT MANAGEMENT SYSTEM ****"<<endl<<endl;;
		cout<<endl<<"1.Add a airport"<<endl<<"2.Add a flight"<<endl<<"3.Show all ports/cities"<<endl<<"4.Show all flights"<<endl<<"5.Delete flight"<<endl<<"6.Delete airport"<<endl<<"7.show the connected airports(DFS traversal)"<<endl<<"8.show Incoming flights of airport(indegree)"<<endl<<"9.show outgoing flights of airport(outdegree)"<<endl<<"0.exit";
		cout<<endl<<"Choose one- ";
		cin>>choice;


		switch(choice)
		{
		case 1:
			obj.AddCity();
			break;
		case 2:
			obj.addFlight();
			break;
		case 3:
			obj.showPorts();
			break;
		case 4:
			obj.showFlights();
			break;
		case 5:
			obj.deleteFlight();
			break;
		case 6:
			obj.deletePort();
			break;
		case 7:
			obj.DFS_call();
			break;
		case 8:
			obj.indegreeOfPort();
			break;
		case 9:
			obj.outdegreeOfPort();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout<<endl<<"Wrong choice entered"<<endl;
			break;
		}
	}while(1);

}


/*
OUTPUT:
Enter 0 for undirected graph and 1 for directed graph : 0


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Pune


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Mumbai


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Delhi


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Chennai


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Kolkata


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Mumbai
Enter distance between the cities : 100
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Chennai
Enter distance between the cities : 200
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Delhi
Enter distance between the cities : 300
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Kolkata
Enter distance between the cities : 400
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Mumbai
Enter name of the second city : Delhi
Enter distance between the cities : 500
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Delhi
Enter name of the second city : Kolkata
Enter distance between the cities : 450
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Kolkata
Enter name of the second city : Chennai
Enter distance between the cities : 560
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Chennai
Enter name of the second city : Mumbai
Enter distance between the cities : 360
Edge inserted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 6
     Pune    Mumbai    Delhi    Chennai    Kolkata
Pune    0    100    300    200    400
Mumbai    100    0    500    360    0
Delhi    300    500    0    0    450
Chennai    200    360    0    0    560
Kolkata    400    0    450    560    0


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 5
City : Pune     Degree : 4
City : Mumbai   Degree : 3
City : Delhi    Degree : 3
City : Chennai  Degree : 3
City : Kolkata  Degree : 3


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 3
Enter the name of the city to be deleted : Pune


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 5
City : Mumbai   Degree : 2
City : Delhi    Degree : 2
City : Chennai  Degree : 2
City : Kolkata  Degree : 2


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 6
     Mumbai    Delhi    Chennai    Kolkata
Mumbai    0    500    360    0
Delhi    500    0    0    450
Chennai    360    0    0    560
Kolkata    0    450    560    0


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 4
Enter name of the first city : Mumbai
Enter name of the second city : Delhi
Edge deleted successfully


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 5
City : Mumbai   Degree : 1
City : Delhi    Degree : 1
City : Chennai  Degree : 2
City : Kolkata  Degree : 2


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 6
     Mumbai    Delhi    Chennai    Kolkata
Mumbai    0    0    360    0
Delhi    0    0    0    450
Chennai    360    0    0    560
Kolkata    0    450    560    0


===== ===== ===== Undirected Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 7
*/

/* 
Enter 0 for undirected graph and 1 for directed graph : 1


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Pune


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Mumbai


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Delhi


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Kolkata


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 1
Enter name of the city : Chennai


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Mumbai
Enter distance between the cities : 100
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Delhi
Enter distance between the cities : 150
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Chennai
Enter distance between the cities : 200
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Pune
Enter name of the second city : Kolkata
Enter distance between the cities : 250
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Mumbai
Enter name of the second city : Delhi
Enter distance between the cities : 300
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Delhi
Enter name of the second city : Kolkata
Enter distance between the cities : 250
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Kolkata
Enter name of the second city : Chennai
Enter distance between the cities : 450
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 2
Enter name of the first city : Chennai
Enter name of the second city : Mumbai
Enter distance between the cities : 780
Edge inserted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 5
City : Pune    In Degree : 0    Out Degree : 4
City : Mumbai    In Degree : 2    Out Degree : 1
City : Delhi    In Degree : 2    Out Degree : 1
City : Kolkata    In Degree : 2    Out Degree : 1
City : Chennai    In Degree : 2    Out Degree : 1


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 6
     Pune    Mumbai    Delhi    Kolkata    Chennai
Pune    0    100    150    250    200
Mumbai    0    0    300    0    0
Delhi    0    0    0    250    0
Kolkata    0    0    0    0    450
Chennai    0    780    0    0    0


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 4
Enter name of the first city : Pune
Enter name of the second city : Mumbai
Edge deleted successfully


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 5
City : Pune    In Degree : 0    Out Degree : 3
City : Mumbai    In Degree : 1    Out Degree : 1
City : Delhi    In Degree : 2    Out Degree : 1
City : Kolkata    In Degree : 2    Out Degree : 1
City : Chennai    In Degree : 2    Out Degree : 1


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 6
     Pune    Mumbai    Delhi    Kolkata    Chennai
Pune    0    0    150    250    200
Mumbai    0    0    300    0    0
Delhi    0    0    0    250    0
Kolkata    0    0    0    0    450
Chennai    0    780    0    0    0


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 3
Enter the name of the city to be deleted : Pune


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 5
City : Mumbai    In Degree : 1    Out Degree : 1
City : Delhi    In Degree : 1    Out Degree : 1
City : Kolkata    In Degree : 1    Out Degree : 1
City : Chennai    In Degree : 1    Out Degree : 1


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 6
     Mumbai    Delhi    Kolkata    Chennai
Mumbai    0    300    0    0
Delhi    0    0    250    0
Kolkata    0    0    0    450
Chennai    780    0    0    0


===== ===== ===== Directed Graph Operations ===== ===== =====

1. Insert city
2. Insert edge
3. Delete city
4. Delete edge
5. Print degrees
6. Traverse graph
7. Exit

Enter your choice : 7
*/