
#include "stack.cpp"
#include<cstring>

void expressionConv();
void infixToPostfix(char String[100]);
int prec(char c);


int main()
{
	Stack s;
	int choice;
	char data;
	
	do
	{
		cout<<"\n*****STACK MENU*****\n1)Push data\n2)Pop data\n3)Display stack\n4)Expression conversion\n5)Expression evaluation\n6)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the data to be pushed:"<<endl;
			cin>>data;
			s.push(data);
			break;
			
		case 2:
			if(!s.isEmpty())
				cout<<endl<<s.pop()<<" has been popped."<<endl;
			else
				cout<<"\nStack is empty."<<endl;
			break;
			
		case 3:
			cout<<"\nThe stack is:"<<endl;
			s.displayStack();
			break;
		
		case 4:
			expressionConv();
			break;
		
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}


void expressionConv()
{
	int choice;
	char infix[100];
	
	
	cout<<"\nEnter the infix expression"<<endl;
	cin>>infix;
	
	infixToPostfix(infix);
}

void infixToPostfix(char String[100])
{
	Stack s;
	char postfix[100],data;
	int i,j=0;
	
	for(i=0;i!=strlen(String);i++)
	{
		if(prec(String[i])==-1)
			postfix[j++]=String[i];
	
		else if(String[i]=='(')
			s.push(String[i]);
			
		else if(String[i]==')')
		{
			while(s.isTop()!='(')
				postfix[j++]=s.pop();
			s.pop();
		}
		else
		{
		try
		{
			if(!s.isEmpty() && ((prec(s.isTop())>=prec(String[i])) && prec(String[i])!=3) || ((prec(s.isTop())>=prec(String[i])) && prec(String[i])!=3))
				postfix[j++]=s.pop();
			
			else
				s.push(String[i]);
		}
		catch(...){}
		}
		
	}
	
	
	while(!s.isEmpty())
		postfix[j++]=s.pop();
	postfix[j++]='\0';
	
	
	cout<<"\nPostfix expression is: "<<postfix<<endl;
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
	case '(':
		return 0;
	case ')':
		return 0;
	default:
		return -1;
	}
}
