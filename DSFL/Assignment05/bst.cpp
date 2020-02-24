#include<bits/stdc++.h>
#include "bst.h"

using namespace std;	

bst::bst()
{
	root = NULL;
}

int bst::isEmpty()
{
	if(root == NULL)
		return 1;
	return 0;
}

void bst::insertNode()
{
	node *current = new node;
	node *temp;
	cout<<"\nEnter the number to be added to the tree :"<<endl;
	cin>>current->data;
	current->left = NULL;
	current->right = NULL;
	
	if(isEmpty())
		root = current;
	else
	{
		temp = root;
		while(1)
		{
			if(temp->data == current->data)
			{
				cout<<"\nNode already exsists."<<endl;
				return;
			}
			
			else if(temp->data > current->data)
			{
				if(temp->left == NULL)
				{
					temp->left = current;
					break;
				}
				else
					temp = temp->left;
			}
			
			else if(temp->data < current->data)
			{
				if(temp->right == NULL)
				{
					temp->right = current;
					break;
				}
				else
					temp = temp->right;
			}	
		}
	}
	
	cout<<"\nThe node has been inserted successfully!"<<endl;
}

void bst::display(node *Tnode)
{
	if(Tnode)
	{
		display(Tnode->left);
		cout<<setw(3)<<Tnode->data;
		display(Tnode->right);
	}
	
}

node* bst::getRoot()
{
	return root;	
}

void bst::deleteNode()
{
	int data;
	node *current, *temp;
	
	cout<<"\nEnter the number do be deleted from the tree : "<<endl;
	cin>>data;
	current = searchNode(root,data);
	
	if(current == NULL)
	{
		cout<<"\nNode does not exist."<<endl;
		return;
	}
	else
	{
		if(current->left == NULL && current->right == NULL)
		{
			delete current;
		}
		else if(current->left == NULL && current->right != NULL)
		{
			current->data = current->right->data;
			delete(current->right);
		}
		else if(current->left != NULL && current->right == NULL)
		{
			current->data = current->left->data;
			delete(current->left);
		}
		else
		{
			temp = current->left;
			while(temp->right != NULL)
				temp = temp->right;
			temp->right = current->right;
			current = current->left;
		}
	}
	
	cout<<"\nThe node has been deleted sucessfully!"<<endl;
}

node *bst::searchNode(node *Tnode, int data)
{
	if(Tnode != NULL)
	{
		if(Tnode->data == data)
			return Tnode;
		else if(Tnode->data > data)
			return searchNode(Tnode->left,data);
		else if(Tnode->data < data)
			return searchNode(Tnode->right,data);
	}
	return NULL;
}

void bst::displayLevel()
{
	queue<node *>q;
	node *temp;
	
	if(root == NULL)
		return;
	
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout<<setw(3)<<temp->data;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	
}

void bst::mirrorImage(node *Tnode)
{
	node *temp;
	if(Tnode == NULL)
		return;
	else
	{
		temp = Tnode->left;
		Tnode->left = Tnode->right;
		Tnode->right = temp;
	}
	
	mirrorImage(Tnode->left);
	mirrorImage(Tnode->right);
}

