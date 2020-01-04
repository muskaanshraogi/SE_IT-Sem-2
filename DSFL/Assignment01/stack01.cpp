



#include<iostream>

using namespace std;

class node
{
    public:
	char data;
	node *next;
};

class stack
{
	node *top;
	node *n;
    public:
    	stack(){ top=NULL;}
    	void push(char data);
    	char pop();
    	int isEmpty();
    	char isTop();
    	void displayStack();
    	void reverse();
};

class expression
{
	char infix[100],pfix[100];
	stack s;
    public:
    	void inputExp();
    	void infixToPostfix();
    	void infixToPrefix();
};

int stack::isEmpty()
{
	if(top==NULL)
		return 1;
	return 0;
}

char stack::isTop()
{
	return top->data;
}

void stack::push(char data)
{
	node *current=new node;
	current->data=data;
	
	if(isEmpty())
	{
		current->next=NULL;
		top=current;
	}
	else
	{
		current->next=top;
		top=current;
	}
}

char stack::pop()
{
	char data;
	node *current;
	
	data=top->data;
	current=top;
	top=top->next;
	delete(current);
	return data;
}

void stack::displayStack()
{
	node *current=top;
	
	if(isEmpty())
		cout<<"\nStack is empty."<<endl;
	else
	{
		cout<<"\nThe stack is:"<<endl;
		while(current!=NULL)
		{
			cout<<current->data<<endl;
			current=current->next;
		}
	}
		
}

void stack::reverse()
{
	node *current,*result,*temp;
	current=top;
	result=NULL;
	temp=NULL;
	while(current!=NULL)
	{
		temp=current->next;
		current->next=result;
		result=current;
		current=temp;
	}
	top=result;
}

void expressionConv()
{
	int choice;
	
	do
	{
		cout<<"\n***EXPRESSION MENU***\n1)Enter expression\n2)Infix to prefix\n3)Infix to postfix\n4)Back"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 4:
			return;
		}
	}while(1);
}

int prec(char c)
{
	switch(c)
	{
	case '^':
		return 3;
	case '*':
		return 2;
	case '/':
		return 2;
	case '+':
		return 1;
	case '-':
		return 1;
	default:
		return -1;
	}
}

int main()
{
	stack s;
	int choice;
	char data;
	
	do
	{
		cout<<"\n*****STACK MENU*****\n1)Push data\n2)Pop data\n3)Display stack\n4)Expression conversions\n5)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the data to be pushed:"<<endl;
			cin>>data;
			s.push(data);
			break;
			
		case 2:
			if(!isEmpty())
				cout<<endl<<s.pop()<<" has been popped."<<endl;
			else
				cout<<"\nStack is empty."<<endl;
			break;
			
		case 3:
			s.displayStack();
			break;
		
		case 4:
			expressionConv();
			break;
		
		case 5:
			exit(0);
		}
	}while(1);
	
	return 0;
}
