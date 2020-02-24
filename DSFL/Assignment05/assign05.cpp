#include<bits/stdc++.h>
#include "bst.cpp"

using namespace std;

int main()
{
	int choice, data;
	bst b;
	
	do
	{
		cout<<"\n*****BINARY SEARCH TREE*****\n1)Insert node\n2)Delete node\n3)Display tree\n4)Search for a node\n5)Create mirror image\n6)Display level-wise\n7)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			b.insertNode();
			break;
		case 2:
			b.deleteNode();
			break;
		
		case 3:
			if(!b.isEmpty())
			{
				cout<<"\nThe binary search tree is :"<<endl;
				b.display(b.getRoot());
				cout<<endl;
			}
			else
				cout<<"\nTree is empty."<<endl;
			break;
			
		case 4:
			cout<<"\nEnter the number do be searched :	"<<endl;
			cin>>data;
			if(b.searchNode(b.getRoot(),data) != NULL)
				cout<<"\nData found."<<endl;
			else
				cout<<"\nData not found."<<endl;
			break;
		
		case 5:
			b.mirrorImage(b.getRoot());
			cout<<"\nThe mirror image of the tree is :"<<endl;
			b.display(b.getRoot());
			cout<<endl;
			b.mirrorImage(b.getRoot());
			break;
			
		case 6:
			cout<<"\nThe level order traversal of the tree is :"<<endl;
			b.displayLevel();
			cout<<endl;
			break;
		case 7:
			exit(0);
		}
	}while(1);
	
	return 0;
}
