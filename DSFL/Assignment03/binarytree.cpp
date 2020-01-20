
#include<bits/stdc++.h>
#include "binarytree.h"

using namespace std;

binaryTree::binaryTree()
{
	root = NULL;
}

int binaryTree::isEmpty()
{
	if( root == NULL)
		return 1;
	return 0;
}

node *binaryTree::makeTree()
{
	char choice;
	node *temp = new node;
	
	cout<<"\nEnter the value for the node :"<<endl;
	cin>>temp->data;
	
	cout<<"\nDo you want to enter the left child for "<<temp->data<<" ?(y/n)"<<endl;
	cin>>choice;
	if(choice == 'y' || choice == 'Y')
		temp->left = makeTree();
		
	cout<<"\nDo you want to enter the right child for "<<temp->data<<" ?(y/n)"<<endl;
	cin>>choice;
	if(choice == 'y' || choice == 'Y')
		temp->right = makeTree();
		
	return temp;
}

void binaryTree::display(node *Tnode)
{
	if(Tnode != NULL)
	{
		display(Tnode->left);
		cout<<setw(3)<<Tnode->data;
		display(Tnode->right);
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

void binaryTree::create()
{
	root = makeTree();
}

int binaryTree::depth(node *Tnode)
{
	int depthLeft,depthRight;
	if(Tnode == NULL)
		return 0;
	
	depthLeft = depth(Tnode->left+1);
	depthRight = depth(Tnode->right+1);
	
	return(max(depthLeft,depthRight));
}

node *binaryTree::getRoot()
{
	return root;
}

void binaryTree::displayLeaf(node *Tnode)
{
	if(Tnode != NULL)
	{
		displayLeaf(Tnode->left);
		if(Tnode->left == NULL && Tnode->right == NULL)
			cout<<setw(3)<<Tnode->data;
		displayLeaf(Tnode->right);
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

node *binaryTree::copyTree(node *Tnode)
{
	node *temp = NULL;
	if(Tnode != NULL)
	{
		temp = new node;
		temp->data = Tnode->data;
		temp->left = copyTree(Tnode->left);
		temp->right = copyTree(Tnode->right);
	}
	return temp;	
}
