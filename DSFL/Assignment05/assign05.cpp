#include<bits/stdc++.h>

using namespace std;

int main()
{
	int choice;
	
	do
	{
		cout<<"\n*****BINARY SEARCH TREE*****\n1)Insert node\n2)Delete node\n3)Display tree\n4)Search for a node\n5)Create mirror image\n6)Display level-wise\n7)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 7:
			exit(0);
		}
	}while(1);
	
	return 0;
}
