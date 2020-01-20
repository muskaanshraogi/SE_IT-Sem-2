
#include<bits.stdc++.h>

using namespace std;

void createTree();
void traversals();

int main()
{
	int choice;
	
	do
	{
		cout<<"\n*****EXPRESSION TREE MENU******\n1)Create expression tree\n2)Perform traversals\n3)Exit"<<endl;
		cin>>choice;
	
		switch(choice)
		{
		case 1:
			createTree();
			break;
			
		case 2:
			cout<<"\n***TRAVERSALS***\n1)Recursive\n2)Non-recursive"<<endl;
		
		case 3:
			exit(0);
		}	
	}while(1);
}

void createTree()
{
	int choice;
	char expression[50];
	
	cout<<"\n***CREATE EXPRESSION TREE***\n1)Enter prefix expression\n2)Enter postfix expression\n3)Back"<<endl;
	cin>>ch;
	
	switch(choice)
	{
	case 1:
		cout<<"\nEnter prefix expression :"<<endl;
		cin>>expression;
		break;
	
	case 2:
		cout<<"\nEnter postfix expression :"<<endl;
		cin>>expression;
		break;
	
	case 3:
		return;
	}
	
}


