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
    	void dijkstras(int src);
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
	
	for(int i=0; i<v; i++)
	{
		cout<<setw(5)<<sp[i];
	}
}


void graph::dijkstras(int src)
{
	int j, min, dis = 0;
	
	printf("a\n");
	
	for(int i = 0; i<v; i++)
	{
		visited[src] = 1;
		if(i != src)
		{
			dis = sp[i] + grp[src][i];
			sp[i] = dis < sp[i] ? dis : sp[i];
			printf("b\n");
		}
	}
	
	min = INF;
	for(int i=0; i<v; i++)
	{
		if(i != src && !visited[i] && sp[i] < min)
		{
			min = sp[i];
			src = i;
			printf("c\n");
		}
	}
	
	printf("d\n");
	if(!visited[src])
		dijkstras(src);
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
			g.dijkstras(--s);
			g.displaySP();
			break;
			
		case 4:
			exit(0);
		}
	}while(1);
}

/*

0 		 0
1 		 4
2 		 12
3 		 19
4 		 21
5 		 11
6 		 9
7 		 8
8 		 14


1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7


*/
