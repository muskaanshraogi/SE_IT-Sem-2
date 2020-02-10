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
	Stack s;
	node *current;
	
	for(int i=0; i<strlen(expression); i++)
	{
		if((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z'))
		{
			node *temp = new node;
			temp->data = expression[i];
			temp->left = NULL;
			temp->right = NULL;
			s.push(temp);		
		}
		else if((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*') || (expression[i] == '/') || (expression[i] == '^'))
		{
			node *temp = new node;
			temp->data = expression[i];
			temp->right = s.pop();
			temp->left = s.pop();
			current= temp;
			s.push(temp);
		}
	}
	
	return current;
}

void expressionTree::inOrderRec(node *Tnode)
{
	if(Tnode != NULL)
	{
		inOrderRec(Tnode->left);
		cout<<setw(3)<<Tnode->data;
		inOrderRec(Tnode->right);
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

void expressionTree::preOrderRec(node *Tnode)
{
	if(Tnode != NULL)
	{
		cout<<setw(3)<<Tnode->data;
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
		cout<<setw(3)<<Tnode->data;
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

void expressionTree::inOrder(node *Tnode)
{
	node *temp = root;
	stack<char>s;
	
	while(temp!=NULL)
	{
		s.push(temp->data);
		temp = temp->left;
	}
	
	if(s.empty())
		return;
	temp->data = s.top();
	s.pop();
	cout<<setw(3)<<temp->data;
	temp = temp->right;
}

Stack::Stack()
{
	top = NULL;
}

int Stack::isEmpty()
{
	if(top == NULL)
		return 1;
	return 0;
}

void Stack::push(node *data)
{
	Snode *current = new Snode;
	current->data = data;
	
	if(isEmpty())
	{
		current->next =NULL;
		top = current;
	}
	else
	{
		current->next = top;
		top = current;
	}
	
}

node *Stack::pop()
{
	node *data;
	Snode *temp = top;
	
	data = temp->data;
	top = temp->next;
	delete(temp);
	return data;	
}
