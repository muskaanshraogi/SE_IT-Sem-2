
#include "linkedlist.cpp"

template<class t>
class Stack
{
	linkedList<t>ll;
	node<t>*top;
    public:
    	Stack();
    	void push(t data);
    	t pop();
    	int isEmpty();
    	t isTop();
    	void displayStack();
};


