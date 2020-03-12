#include<bits/stdc++.h>
#define INF 10000

using namespace std;

class graph
{
	int v, e;
	int **grp;
	int *sp;
	int *visited;
    public:
    	graph();
    	graph(int v, int e);
    	void initialize(int src);
    	void dijkstras();
    	void displayGraph();
    	void displaySP();
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
	visited = new int[v];
	sp = new int[v];
	
	this->grp = new int*[v];
	for(int i=0;i <v; i++)
		grp[i] = new int[v];
}

void graph::initialize(int src)
{
	int s, w, d;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			grp[i][j] = 0;
		}
		sp[i] = INF;
		visited[i] = 0;
	}
	sp[src-1] = 0;

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

void graph::displaySP()
{
	cout<<"\nThe shortest paths for the source are :"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Vertex\tDistance"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		cout<<i+1<<"\t"<<sp[i]<<endl;
	}
}


void graph::dijkstras()
{
	int min, dis = 0;
	
	for(int k=0; k<v-1; k++)
	{
		min = -1;
		for(int i=0; i<v; i++)
		{
			if(!visited[i] && (min == -1 || sp[i] < sp[min]))
				min = i;
		}
		visited[min] = 1;
		
		for(int j=0; j<v; j++)
		{
			if(grp[min][j] != 0 && !visited[j])
			{
				dis = sp[min] + grp[min][j];
				if(dis < sp[j])
					sp[j] = dis;
			} 
		}
	}
}

int main()
{
	graph g;
	int choice, e, v, s;
	
	do
	{
		cout<<"\n*****KRUSKAL'S*****\n1)Input graph\n2)Display graph\n3)Find shortest path\n4)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the number of vertices :"<<endl;
			cin>>v;
			cout<<"\nEnter the number of edges :"<<endl;
			cin>>e;
			cout<<"\nEnter the source :"<<endl;
			cin>>s;
			g = graph(v,e);
			g.initialize(s);
			break;
		
		case 2:
			g.displayGraph();
			break;
			
		case 3:
			g.dijkstras();
			g.displaySP();
			break;
			
		case 4:
			exit(0);	
		}
	}while(1);
}
