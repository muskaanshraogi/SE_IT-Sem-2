#include<bits/stdc++.h>

using namespace std;

class graph
{
	int v, e;
	int **grp;
	int **mst;
	int **selected;
	int *parent;
	int cost;
    public:
    	graph();
    	graph(int v, int e);
    	void initialize();
    	void kruskals();
    	void displayGraph();
    	void displayMST();
    	int findParent(int v);
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
	cost = 0;
	
	this->grp = new int*[v];
	for(int i=0;i <v; i++)
		grp[i] = new int[v];
		
	this->mst = new int*[v];
	for(int i=0;i <v; i++)
		mst[i] = new int[v];
		
	this->selected = new int*[v];
	for(int i=0;i <v; i++)
		selected[i] = new int[v];
}

void graph::initialize()
{
	int s, w, d;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			grp[i][j] = 0;
			selected[i][j] = 0;
		}
		visited[i] = 0;
		parent[i] = i;
	}
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

int graph::findParent(int v)
{
	if(parent[v] == v)
		return v;
	return findParent(parent[v]);
}

void graph::kruskals()
{
	int minw, mins, mind;
	
	for(int k=0; k<v; k++)
	{
		minw = 100;
		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
			{
				if(grp[i][j] != 0 && !selected[i][j] && grp[i][j] < minw)
				{
					minw = grp[i][j];
					mins = i;
					mind = j;
					selected[i][j] = 1;
					selected[j][i] = 1;
				}
			}
		}
	
		if(findParent(mins) != findParent(mind))
		{
			mst[mins][mind] = minw;
			mst[mind][mins] = minw;
			parent[mind] = mins;
			cost += mst[mins][mind];
		}
	}
}

int main()
{
	graph g;
	int choice, e, v;
	
	do
	{
		cout<<"\n*****KRUSKAL'S*****\n1)Input graph\n2)Display graph\n3)Find minimum spanning tree\n4)Exit"<<endl;
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
			g.kruskals();
			g.displayMST();
			break;
			
		case 4:
			exit(0);
		}
	}while(1);
}
