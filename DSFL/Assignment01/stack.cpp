#include<iostream>
#include "stack.h"

using namespace std;

template<class t>
Stack<t>::Stack()
{
	top=ll.head;
}

template<class t>
void Stack<t>::push(t data)
{
	ll.insertNode(data,1);
}

template<class t>
t Stack<t>::pop()
{
	if(!isEmpty()) 
		return ll.deleteNode(1);
}

template<class t>
int Stack<t>::isEmpty()
{
	if(ll.head==NULL)
		return 1;
	return 0;
}

template<class t>
void Stack<t>::displayStack()
{
	ll.displayList();
}

template<class t>
t Stack<t>::isTop()
{
	if(!isEmpty()) 
		return top->data;
}
