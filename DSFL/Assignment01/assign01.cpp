#include<iostream>
#include<cstring>
#include "stack.cpp"


using namespace std;

void postfix();
void prefix();
int priority(char c);
void reverse(char String[20]);
void prefixEvaluate();
void postfixEvaluate();

int main()
{

	int choice;
	
	do
	{
		cout<<"\n*****STACK MENU*****\n1)Convert infix expression to postfix\n"
						"2)Convert infix expression to prefix\n"
						"3)Evaluate prefix expression\n"
						"4)Evaluate postfix expression\n"
						"5)Exit"<<endl;
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
			prefixEvaluate();
			break;
		case 4:
			postfixEvaluate();
			break;
		case 5:
			exit(0);
		}
	}while(1);
	
	return 0;
}

void postfix()
{
	Stack<char>s;
	char infix[20], postfix[20];
	int i, j=0;
	
	cout<<"\nEnter the infix expression:"<<endl;
	cin>>infix;
	cout<<strlen(infix);
	
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
		
		else if(!s.isEmpty() && priority(infix[i]) != 3 && priority(s.isTop()) >= priority(infix[i]))
		{
			postfix[j++] = s.pop();
			s.push(infix[i]);
		}
		
		else if(!s.isEmpty() && priority(infix[i]) == 3 && priority(s.isTop()) > priority(infix[i]))
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
	Stack<char>s;
	char infix[20],prefix[20];
	int i, j=0;
	
	cout<<"\nEnter the infix expression:"<<endl;
	cin>>infix;	
	
	for(i=strlen(infix)-1; i>=0; i--)
	{
		if(priority(infix[i]) == -1)
			prefix[j++] = infix[i];
		
		else if(s.isEmpty() || infix[i] == '(')
			s.push(infix[i]);
			
		else if(infix[i] == ')')
		{
			while(s.isTop() != '(')
				prefix[j++] = s.pop();
			s.pop();
		}
		
		else if(!s.isEmpty() && priority(infix[i]) != 3 && priority(s.isTop()) > priority(infix[i]))
		{
			prefix[j++] = s.pop();
			s.push(infix[i]);
		}
		
		else if(!s.isEmpty() && priority(infix[i]) == 3 && priority(s.isTop()) >= priority(infix[i]))
		{
			prefix[j++] = s.pop();
			s.push(infix[i]);
		}
			
		else
			s.push(infix[i]);
	}
	
	while(!s.isEmpty())
		prefix[j++] = s.pop();
	prefix[j] = '\0';
	
	reverse(prefix);
	cout<<"\nThe prefix expression is : "<<prefix<<endl;
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

void reverse(char String[20])
{
	char rev[20];
	int i;
	strcpy(rev,String);
	
	for(i=0; i<strlen(rev); i++)
	{
		String[i] = rev[strlen(rev)-i-1];
	}
	String[i]='\0';
}

void postfixEvaluate()
{
	Stack<int>s;
	char postfix[20];
	int i,op1,op2,result,value;
	
	cout<<"\nEnter the postfix expression:"<<endl;
	cin>>postfix;
	
	for(i=0; i<strlen(postfix); i++)
	{
		if(priority(postfix[i]) == -1)
		{
			if(isalpha(postfix[i]))
			{
				cout<<"\nEnter the value for "<<postfix[i]<<" :"<<endl;
				cin>>value;
				s.push(value);
			}
			else
				s.push(postfix[i] - 48);
		}
				
		else 
		{
			op2 = s.pop();
			op1 = s.pop();
			
			if(postfix[i] == '*')
				result = op1 * op2;
			else if(postfix[i] == '/')
				result = op1 / op2;
			else if(postfix[i] == '+')
				result = op1 + op2;
			else if(postfix[i] == '-')
				result = op1 - op2;
			
			s.push(result);	
		}
	}
	
	result = s.pop();
	cout<<"\nThe expression value is evaluated to be "<<result<<endl; 
}

void prefixEvaluate()
{
	Stack<int>s;
	char prefix[20];
	int i,op1,op2,result;
	
	cout<<"\nEnter the prefix expression:"<<endl;
	cin>>prefix;
	
	for(i=strlen(prefix)-1; i>=0; i--)
	{
		if(priority(prefix[i]) == -1)
		{
			if(isalpha(prefix[i]))
			{
				cout<<"\nEnter the value for "<<prefix[i]<<" :"<<endl;
				cin>>value;
				s.push(value);
			}
			else
				s.push(prefix[i] - 48);
		}
			
		else 
		{
			op1 = s.pop();
			op2 = s.pop();
			
			if(prefix[i] == '*')
				result = op1 * op2;
			else if(prefix[i] == '/')
				result = op1 / op2;
			else if(prefix[i] == '+')
				result = op1 + op2;
			else if(prefix[i] == '-')
				result = op1 - op2;
			
			s.push(result);	
		}
	}
	
	result = s.pop();
	cout<<"\nThe expression value is evaluated to be "<<result<<endl; 
}
