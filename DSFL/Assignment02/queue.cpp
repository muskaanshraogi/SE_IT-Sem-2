
#include<iostream>
#include<cstring>
#include "queue.h"

priorityQueue::priorityQueue()
{
	front = ll.head;
	rear = ll.tail;
}

void priorityQueue::enQueue(int id, char name[20], int age, char disease[20], int priority)
{
	ll.insertNode(id, name, age, disease, priority);
}


node priorityQueue::deQueue()
{
		return ll.deleteNode(1);
}

int priorityQueue::isEmpty()
{
	if(ll.head == NULL && ll.tail == NULL)
		return 1;
	return 0;
}

void priorityQueue::displayQueue()
{
	ll.displayList();
}

