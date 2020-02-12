#include<bits/stdc++.h>
#include "expressiontree.h"

using namespace std;

expressionTree::expressionTree()
{
	root = NULL;
}

int expressionTree::isEmpty()
{
	if(root == NULL)
		return 1;
	return 0;
}

node *expressionTree::getRoot()
{
	return root;
}

void expressionTree::create(char expression[50])
{
	root = createTree(expression);
}

node *expressionTree::createTree(char expression[50])
{
	stack<node *>s;
	node *temp;
	
	for(int i=0; i<strlen(expression); i++)
	{
		if(isalnum(expression[i]))
		{
			temp = new node;
			temp->data = expression[i];
			temp->left = NULL;
			temp->right = NULL;
			s.push(temp);		
		}
		else if((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*') || (expression[i] == '/') || (expression[i] == '^'))
		{
			temp = new node;
			temp->data = expression[i];
			temp->right = s.top();
			s.pop();
			temp->left = s.top();
			s.pop();
			s.push(temp);

		}
	}
	
	return temp;
}

void expressionTree::inOrderRec(node *Tnode)
{
	if(Tnode != NULL)
	{
		inOrderRec(Tnode->left);
		cout<<Tnode->data;
		inOrderRec(Tnode->right);
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

void expressionTree::preOrderRec(node *Tnode)
{
	if(Tnode != NULL)
	{
		cout<<Tnode->data;
		preOrderRec(Tnode->left);
		preOrderRec(Tnode->right);
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

void expressionTree::postOrderRec(node *Tnode)
{
	if(Tnode != NULL)
	{
		postOrderRec(Tnode->left);
		postOrderRec(Tnode->right);
		cout<<Tnode->data;
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

void expressionTree::inOrder(node *temp)
{
	stack<node *>s;
	cout<<"\nThe inorder traversal is : ";
	
	while(1)
	{
		while(temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
	
		if(s.empty())
			return;
		temp = s.top();
		s.pop();
		cout<<temp->data;
		temp = temp->right;
	}
}

void expressionTree::preOrder(node *temp)
{
	stack<node *>s;
	cout<<"\nThe preorder traversal is : ";
	
	while(1)
	{
		while(temp != NULL)
		{
			cout<<temp->data;
			s.push(temp);
			temp = temp->left;
		}
	
		if(s.empty())
			return;
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
}

void expressionTree::postOrder(node *temp)
{
	stack<node *>s1, s2;
	cout<<"\nThe postorder traversal is : ";
	
	s1.push(temp);
	while(!s1.empty())
	{
		node *temp = s1.top();
		s1.pop();
		s2.push(temp);
		
		if(temp->left != NULL)
			s1.push(temp->left);
		
		if(temp->right != NULL)
			s1.push(temp->right);
	}
	
	while(!s2.empty())
	{
		temp = s2.top();
		s2.pop();
		cout<<temp->data;
	}
}
