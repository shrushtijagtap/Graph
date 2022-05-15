#include<iostream>
using namespace std;

class g_matrix
{
int graph[10][10];
int n;
public:
g_matrix()
{
	cout<<"Enter number of vertices"<<endl;
	cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				graph[i][j]=0;

}
void construct()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j>i && j<n;j++)
		{
			cout<<"Enter cost of edge between  "<<i<<" and "<<j<<endl;
			cout<<"If there is no edge enter 0"<<endl;
			cin>>graph[i][j];
			graph[j][i]=graph[i][j];
		}
	}
}
void display()
{
	cout<<"The adjacency matrix is :"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void minimum_cost()
{
	int i,j,k,min,mincost=0,v1,v2;
	int visit[n];

	for(int m=0;m<n;m++)
		visit[m]=0;

	visit[0]=1;
	for(k=0;k<n-1;k++)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			if(visit[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(visit[j]==0 && graph[i][j]!=0)
					{
						if(graph[i][j]<min)
						{
							min=graph[i][j];
							v1=j;
							v2=i;
						}
					}
				}
			}
		}
		visit[v1]=1;
		mincost=mincost+min;
		cout<<v2<<"-->"<<v1<<"="<<min<<endl;
	}
	cout<<"Minimum cost is "<<mincost<<endl;
}
};

int main()
{
	g_matrix g;
	int choice;
	char ans;
	while(1)
	{
		cout<<"Enter your choice\n1.Construct   2.Display   3.Minimum cost tree   4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: g.construct();break;
			case 2: g.display();break;
			case 3: g.minimum_cost();break;
			case 4: break;
			default: break;
		}
		cout<<"Do you want to continue ? y or n"<<endl;
		cin>>ans;
		if(ans!='y')
			break;
	}
	return 0;
}
