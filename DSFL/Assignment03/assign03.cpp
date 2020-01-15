
#include<bits/stdc++.h>
#include "binarytree.cpp"

using namespace std;

int main()
{
	binaryTree t;
	node *root;
	int choice;
	
	do
	{
		cout<<"\n*****BINARY TREE MENU*****\n1)Insert node\n2)Delete node\n3)Calculate depth of tree\n4)Display leaf nodes\n5)Create a copy of the tree\n6)Display tree\n7)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the root node :"<<endl;
			root = t.createBTree();
			break;
		
		case 2:
			t.displayBTree(root);
			break;
			
		case 7:
			exit(0);
		}
	}while(1);
	
	return 0;
}
