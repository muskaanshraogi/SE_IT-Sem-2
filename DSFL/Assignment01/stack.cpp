
#include "stack.h"
#include<iostream>

using namespace std;

Stack::Stack()
{
	top=ll.head;
}

void Stack::push(char data)
{
	ll.insertNode(data,1);
}

char Stack::pop()
{
	if(!isEmpty()) 
		return ll.deleteNode(1);
	else throw underflowException();
}

int Stack::isEmpty()
{
	if(ll.head==NULL)
		return 1;
	return 0;
}

void Stack::displayStack()
{
	ll.displayList();
}

char Stack::isTop()
{
	if(!isEmpty()) 
		return top->data;
	else throw underflowException();
}
