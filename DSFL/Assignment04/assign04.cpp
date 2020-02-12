
#include<bits/stdc++.h>
#include "expressiontree.cpp"

using namespace std;

expressionTree createT(expressionTree t);
void traversals(expressionTree t);
void recursive(expressionTree t);
void nonrecursive(expressionTree t);

int main()
{
	expressionTree t;
	int choice;
	
	do
	{
		cout<<"\n*****EXPRESSION TREE MENU******\n1)Create expression tree\n2)Perform traversals\n3)Exit"<<endl;
		cin>>choice;
	
		switch(choice)
		{
		case 1:
			t = createT(t);
			break;
			
		case 2:
			traversals(t);
			break;
		
		case 3:
			exit(0);
		}	
	}while(1);
}

expressionTree createT(expressionTree t)
{
	int choice;
	char postfix[50];
	
	cout<<"\nEnter the postfix expression :"<<endl;
	cin>>postfix;
	t.create(postfix);
	cout<<"\nThe expression tree has been created successfully!"<<endl;
	return t;
}

void traversals(expressionTree t)
{
	int choice;
	
	do
	{
		cout<<"\n***TRAVERSALS***\n1)Recursive\n2)Non-recursive\n3)Back"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			recursive(t);
			break;
			
		case 2:
			nonrecursive(t);
			break;
			
		case 3:
			return;
		}
		
	}while(1);
}

void recursive(expressionTree t)
{
	int choice;
	
	do
	{
		cout<<"\n***RECURSIVE TRAVERSALS***\n1)Preorder\n2)Inorder\n3)Postorder\n4)Back"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nThe preorder traversal is : ";
			t.preOrderRec(t.getRoot());
			cout<<endl;
			break;
			
		case 2:
			cout<<"\nThe inorder traversal is : ";
			t.inOrderRec(t.getRoot());
			cout<<endl;
			break;
		
		case 3:
			cout<<"\nThe postorder traversal is : ";
			t.postOrderRec(t.getRoot());
			cout<<endl;
			break;
		
		case 4:
			return;
		}
		
	}while(1);
}

void nonrecursive(expressionTree t)
{
	int choice;
	
	do
	{
		cout<<"\n\n***NON-RECURSIVE TRAVERSALS***\n1)Preorder\n2)Inorder\n3)Postorder\n4)Back"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			t.preOrder(t.getRoot());
			break;
			
		case 2:
			t.inOrder(t.getRoot());
			break;
		
		case 3:
			t.postOrder(t.getRoot());
			break;
		
		case 4:
			return;
		}
		
	}while(1);
}

