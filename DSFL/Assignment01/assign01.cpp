
#include "stack.cpp"
#include<iostream>
#include<cstring>

using namespace std;

void postfix();
void prefix();
int priority(char c);

int main()
{

	int choice;
	
	do
	{
		cout<<"\n*****STACK MENU*****\n1)Convert infix expression to postfix\n"
						"2)Convert infix expression to prefix\n"
						"3)Evaluate prefix expression\n"
						"4)Evaluate postfix expression\n"
						"6)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			postfix();
			break;	
		case 2:
			prefix();
			break;	
		case 3:
			
			break;
		
		case 4:
			
			break;
		
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}

void postfix()
{
	Stack s;
	char infix[20], postfix[20];
	int i, j=0;
	
	cout<<"\nEnter the infix expression:"<<endl;
	cin>>infix;
	
	for(i=0; i<strlen(infix); i++)
	{
		if(priority(infix[i]) == -1)
			postfix[j++] = infix[i];
		
		else if(s.isEmpty() || infix[i] == '(')
			s.push(infix[i]);
			
		else if(infix[i] == ')')
		{
			while(s.isTop() != '(')
				postfix[j++] = s.pop();
			s.pop();
		}
		
		else if(!s.isEmpty() && (priority(infix[i]) != 3 && priority(s.isTop()) >= priority(infix[i])))
		{
			postfix[j++] = s.pop();
			s.push(infix[i]);
		}
		
		else if(!s.isEmpty() && (priority(infix[i]) == 3 && priority(s.isTop()) > priority(infix[i])))
		{
			postfix[j++] = s.pop();
			s.push(infix[i]);
		}
			
		else
			s.push(infix[i]);
	}
	
	while(!s.isEmpty())
		postfix[j++] = s.pop();
	postfix[j] = '\0';
	
	cout<<"\nThe postfix expression is : "<<postfix<<endl;
}

void prefix()
{
	char infix[20],prefix[20];
	
	cout<<"\nEnter the infix expression:"<<endl;
	cin>>infix;	
	
}

int priority(char c)
{
	if(c == '^')
		return 3;
	else if(c == '/' || c == '*' || c =='%')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else if(c == '(' || c == ')')
		return 0;
	return -1;
}

