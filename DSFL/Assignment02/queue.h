
#include "linkedlist.cpp"

class priorityQueue
{
	linkedList ll;
	node *front, *rear;
    public:
    	priorityQueue();
    	void enQueue(int id, char name[20], int age, char disease[20],int priority);
    	node deQueue();
    	int isEmpty();
    	void displayQueue();
};
