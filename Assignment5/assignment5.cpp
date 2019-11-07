//============================================================================
// Name        : assignment5.cpp
// Author      : Onkar Deshpande(21315)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Problem Statement :- You have a business with several offices; you want to lease phone lines to connect
 * 	them up with each other; and the phone company charges different amounts of
 *	money to connect different pairs of cities. You want a set of lines that connects all
 *	your offices with a minimum total cost. Solve the problem by using adjacency
 *	matrix. (solve using prims Or kruskal both)
 *
 */

#include <iostream>
#include <stdlib.h>
using namespace std;


class Connect
{
	int totalOffices;  //total number of offices
	int cost[10][10];			//adjacent matrix
	string officeName[10]; //string array which contain office names
public:
	Connect()
{
		totalOffices=-1;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				cost[i][j]=0;
}
	void addOffice()
	{
		cout<<endl<<"Enter the name of new office- "<<endl;
		string office;
		cin>>ws;
		getline(cin,office);
		for(int i=0;i<=totalOffices;i++)
		{
			if(officeName[i]==office)
			{
				cout<<endl<<"Office already existing!"<<endl;
				return;
			}
		}
		totalOffices++;
		officeName[totalOffices]=office;
		cout<<endl<<"NEW OFFICE "<<office<<" ADDED!"<<endl;
	}
	void addConnection()
	{
		string source;
		string destination;
		cout<<endl<<"Enter the source office- "<<endl;
		cin>>ws;
		getline(cin,source);
		int i,sourceIndex,destinationIndex;
		for(i=0;i<=totalOffices;i++)
			if(officeName[i]==source)
			{
				sourceIndex=i;
				break;
			}
		if(i==totalOffices+1)
		{
			cout<<endl<<"NO such office found!"<<endl;
			return;
		}
		cout<<endl<<"ENter the destination office-"<<endl;
		cin>>ws;
		getline(cin,destination);
		for(i=0;i<=totalOffices;i++)
			if(officeName[i]==destination)
			{
				destinationIndex=i;
				break;
			}
		if(i==totalOffices+1)
		{
			cout<<endl<<"NO such office found!"<<endl;
			return;
		}
		int x;
		cout<<endl<<"Enter the cost to set up the connection"<<endl;
		cin>>x;
		cost[sourceIndex][destinationIndex]=x;
		cost[destinationIndex][sourceIndex]=x;
		cout<<endl<<"CONNECTION ADDED SUCCESSFULLY!!!"<<endl;
	}


	void Prims()
	{
		int G[totalOffices+1][totalOffices+1],result[totalOffices+1][totalOffices+1];
		int father[totalOffices+1];  //to check cycling;
		int array[totalOffices+1];
		for(int i=0;i<=totalOffices;i++)
			for(int j=0;j<=totalOffices;j++)
			{
				G[i][j]=cost[i][j];
				result[i][j]=0;
			}

		for(int i=0;i<=totalOffices;i++)
		{
			father[i]=-1;
			array[i]=-1;
		}

		int count=0,count1=0,min=9999,v1,v2,wt_tree=0;
		int temp,temp1,root_temp1,root_temp,t,t1;

		//count1++;

		while(count<totalOffices)    //as actual total=totalOffices+1
		{
			min=9999;
			for(v1=1;v1<count1;v1++)
				for(v2=1;v2<=totalOffices;v2++)
					if(G[array[v1]][v2]!=0)
						if(G[array[v1]][v2]<min)
						{
							min=G[array[v1]][v2];
							temp=array[v1];
							temp1=v2;
						}

			t=temp;
			t1=temp1;
			G[temp][temp1]=G[temp1][temp]=0;
			while(temp>-1)
			{
				root_temp=temp;
				temp=father[temp];
			}
			while(temp1>-1)
			{
				root_temp1=temp1;
				temp1=father[temp1];
			}

			if(root_temp!=temp1)
			{
				result[t][t1]=result[t1][t]=min;
				wt_tree+=min;
				father[root_temp1]=root_temp;
				count++;
				array[count1]=t1;
				count1++;
			}
		}

		cout<<endl<<"The prims is- "<<endl<<endl;
		for(int i=0;i<=totalOffices;i++)
		{
			for(int j=0;j<=totalOffices;j++)
			{
				cout<<" "<<G[i][j];
			}
			cout<<endl;
		}


	}


	void kruskals(int ch)
	{
		int G[totalOffices+1][totalOffices+1],result[totalOffices+1][totalOffices+1];
		for(int i=0;i<=totalOffices;i++)
		{
			for(int j=0;j<=totalOffices;j++)
			{
				G[i][j]=cost[i][j];
				result[i][j]=0;
			}
		}
		int min=60000,wt=0,count=0,temp,temp1,root_temp,root_temp1,t,t1;
		int father[totalOffices+1];
		for(int i=0;i<=totalOffices;i++)
		{
			father[i]=-1;
		}

		while(count<totalOffices)
		{
			min=60000;
			for(int i=0;i<=totalOffices;i++)
			{
				for(int j=0;j<=totalOffices;j++)
				{
					if(min>G[i][j] && G[i][j]!=0)
					{
						min=G[i][j];
						temp=i;
						temp1=j;
					}

				}
			}

			t=temp;
			t1=temp1;
			G[temp][temp1]=G[temp1][temp]=0;
			while(temp>-1)
			{
				root_temp=temp;
				temp=father[temp];
			}
			while(temp1>-1)
			{
				root_temp1=temp1;
				temp1=father[temp1];
			}
			if(root_temp!=root_temp1)
			{
				result[t][t1]=result[t1][t]=min;
				wt+=min;
				father[root_temp1]=root_temp;
				count++;
			}
		}

		if(ch==1)
		{
			cout<<endl<<endl<<"The kruskal's matrix is- "<<endl;
			for(int i=0;i<=totalOffices;i++)
			{
				for(int j=0;j<=totalOffices;j++)
					cout<<"\t"<<result[i][j];
				cout<<endl;
			}
		}
		else
		{
			cout<<endl<<"THE EDGES IN THE SPANNING TREE ARE- "<<endl;
			for(int i=0;i<=totalOffices;i++)
			{
				for(int j=0;j<=totalOffices;j++){
					if(result[i][j]!=0)
					{
						cout<<endl<<officeName[i]<<"\t->\t"<<officeName[j]<<"\t cost-"<<result[i][j];
						result[i][j]=result[i][j]=0;
					}
				}
			}
		}

	}
};
int main() {
	Connect pict;
	//pict.show();

	int choice;
	do
	{
		cout<<endl<<"**** PICT TELEPHONE CONNECTIONS ****"<<endl<<" \t'-connecting people since 1983!' "<<endl<<endl;
		cout<<"1. Add office"<<endl<<"2.Add connection"<<endl<<"3.Show spanning tree connection matrix"<<endl<<"4.Show spanning tree edges"<<endl<<"0.exit"<<endl;
		cout<<"Choose one- ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			pict.addOffice();
			break;
		case 2:
			pict.addConnection();
			break;
		case 3:
			//pict.show();
			choice=1;
			pict.kruskals(1);
			break;
		case 4:
			choice=0;
			pict.kruskals(0);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout<<"wrong choicce "<<endl;
			break;
		}
	}while(1);
	return 0;
}
/*
OUTPUT:
*	Sample INPUT: vertices =7
 *   		{{0, 28, 0, 0, 0,10,0},
            {28,0,16,0,0,0,14},
            {0,16,0,12,0,0,0},
            {0,0,12,0,22,0,18},
            {0,0,0,22,0,25,24},
            {10,0,0,0,25,0,0},
            {0,14,0,18,24,0,0},
           };
           Minimum Cost: 99
*/
