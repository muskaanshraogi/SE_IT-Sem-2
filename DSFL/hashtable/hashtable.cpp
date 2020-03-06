#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	int flag;
	int chain;
};

class hashtable
{
	node h[10];
    public:
    	hashtable();
    	void insert(int n, int data);
    	void display();
};

hashtable::hashtable()
{
	for(int i=0;i<10;i++)
	{
		h[i].flag = 0;
		h[i].chain = -1;
	}
}

void hashtable::insert(int n,int key)
{
	int loc, i,j;
	loc = key % n;
	i = 0;
	j = loc;
	
	if(h[loc].flag != 1)
	{
		h[loc].flag = 1;
		h[loc].data = key;
	}
	
	else if(h[loc].flag == 1)
	{
		while(h[j].flag == 1 && i<n)
		{
			j = (j+1)%n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full."<<endl;
			return;
		}
		
		h[loc].chain = j;
		loc = j;
		h[loc].flag = 1;
		h[loc].data = key;
	}
	cout<<"\nData inserted successfully"<<endl;
}

void hashtable::display()
{
	for(int i=0;i<10;i++)
	{
		cout<<h[i].data<<"\t"<<h[i].flag<<"\t"<<h[i].chain<<endl;
	}
}

int main()
{
	hashtable h;
	int choice, data;
	
	do
	{
		cout<<"\n*****ENTER YOUR CHOICE*****\n1)Insert value\n2)Display table\n3)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the data :";
			cin>>data;
			h.insert(10,data);
			break;
		case 2:
			h.display();
			break;
		case 3:
			exit(0);
		}
	}while(1);
}
