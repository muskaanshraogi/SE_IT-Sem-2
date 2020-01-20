
#include<bits/stdc++.h>
#include "binarytree.cpp"

using namespace std;

int main()
{
	binaryTree t;
	node *copy;
	int choice, d;
	
	do
	{
		cout<<"\n*****BINARY TREE MENU*****\n1)Create binary tree\n2)Display tree\n3)Calculate depth of tree\n4)Display leaf nodes\n5)Create a copy of the tree\n6)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			t.create();
			break;
		
		case 2:
			cout<<"\nThe binary tree in inorder form is : "<<endl;
			t.display(t.getRoot());
			cout<<endl;
			break;
		
		case 3:
			d = t.depth(t.getRoot());
			cout<<"\nThe depth of the tree is "<<d<<endl;
			break;
		case 4:
			cout<<"\nThe leaf nodes are :"<<endl;
			t.displayLeaf(t.getRoot());
			cout<<endl;
			break;
		
		case 5:
			copy = t.copyTree(t.getRoot());
			cout<<"\nThe tree has been successfully copied!"<<endl;
			cout<<"\nThe copied tree is :"<<endl;
			t.display(copy);
			cout<<endl;
			break; 
			
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}
