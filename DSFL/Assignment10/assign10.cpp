#include<bits/stdc++.h>

using namespace std;

class graph
{
	int v, e;
	int **grp;
	int **mst;
	int *weight;
	int *visited;
	int *parent;
	int cost;
    public:
    	graph();
    	graph(int v, int e);
    	void initialize();
    	void prims();
    	void displayGraph();
    	void displayMST();
};

graph::graph()
{
	e = 0;
	v = 0;
}

graph::graph(int v, int e)
{
	this->v = v;
	this->e = e;
	parent = new int[v];
	visited = new int[v];
	weight = new int[v];
	cost = 0;
	
	this->grp = new int*[v];
	for(int i=0;i <v; i++)
		grp[i] = new int[v];
		
	this->mst = new int*[v];
	for(int i=0;i <v; i++)
		mst[i] = new int[v];
}

void graph::initialize()
{
	int s, w, d;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			grp[i][j] = 0;
		}
		weight[i] = INT_MAX;
		parent[i] = -1;
		visited[i] = 0;
	}
	weight[0] = 0;
	
	cout<<"\nGraph created."<<endl;
	
	cout<<"\nEnter the source, destination and weight of the edges :"<<endl;
	for(int i=0; i<e; i++)
	{
		cout<<"\nEdge "<<i+1<<" :";
		cin>>s>>d>>w;
		
		if(s != d)
		{
			if(grp[s-1][d-1] == 0 && grp[d-1][s-1] == 0)
			{
				grp[s-1][d-1] = w;
				grp[d-1][s-1] = w;
				cout<<"\nEdge inserted."<<endl;
			}
			else
				cout<<"\nEdge already exists."<<endl;
		}
		else
			cout<<"\nSource and destination cannot be same."<<endl;
	}
}

void graph::displayGraph()
{
	cout<<"\nThe graph is :"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			cout<<setw(5)<<grp[i][j];
		cout<<endl;
	}
}

void graph::displayMST()
{
	cout<<"\nThe minimum spanning tree is :"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			cout<<setw(5)<<mst[i][j];
		cout<<endl;
	}
	cout<<"\nThe cost of the MST is : "<<cost<<endl;
}

void graph::prims()
{
	int k = 1, min;
	
	while(k != v)
	{
		min = -1;
		for(int i=0; i<v; i++)
		{
			if(!visited[i] && (min == -1 || weight[i] < weight[min]))
				min = i;
		}
		visited[min] = 1;
		
		for(int i=0; i<v; i++)
		{
			if(grp[min][i] != 0 && !visited[i] && grp[min][i] < weight[i])
			{
				weight[i] = grp[min][i];
				parent[i] = min;
			}
		}
		k++;
	}
	
	for(int i=0; i<v; i++)
	{
		int j = parent[i];
		if(j != -1)
		{
			mst[j][i] = weight[i];
			mst[i][j] = weight[i];
			cost += weight[i];
		}
	}
}

int main()
{
	graph g;
	int choice, e, v;
	
	do
	{
		cout<<"\n*****PRIM'S*****\n1)Input graph\n2)Display graph\n3)Find minimum spanning tree\n4)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the number of vertices :"<<endl;
			cin>>v;
			cout<<"\nEnter the number of edges :"<<endl;
			cin>>e;
			g = graph(v,e);
			g.initialize();
			break;
		
		case 2:
			g.displayGraph();
			break;
			
		case 3:
			g.prims();
			g.displayMST();
			break;
			
		case 4:
			exit(0);
		}
	}while(1);
}
