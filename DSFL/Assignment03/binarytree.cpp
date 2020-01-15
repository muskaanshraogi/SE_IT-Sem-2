
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

node binaryTree::createBTree()
{
	int data;
	node *TNode;
	cin>>data;
	
	if(data != -1)
	{
		TNode = new node;
		TNode->data = data;
		cout<<"\nEnter left child of '"<<data<<"' (-1 for NULL) :"<<endl;
		TNode->left = createBTree();
		cout<<"\nEnter right child of '"<<data<<"' (-1 for NULL) :"<<endl;
		TNode->right = createBTree();
	}
	else
		return TNode;
}

void binaryTree::displayBTree(node *TNode)
{
	while(TNode->left != NULL)
		TNode = TNode->left;
}
