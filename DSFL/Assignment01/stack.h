
#include "linkedlist.cpp"

class underflowException{};

class Stack
{
	linkedList ll;
	node *top;
    public:
    	Stack();
    	void push(char data);
    	char pop();
    	int isEmpty();
    	char isTop();
    	void displayStack();
};


