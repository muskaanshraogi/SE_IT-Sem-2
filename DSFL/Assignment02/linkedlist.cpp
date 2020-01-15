#include<iostream>
#include<cstring>
#include "linkedlist.h"

using namespace std;

linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}

void linkedList::insertNode(int id, char name[20], int age, char disease[20], int priority)
{
	node *current = new node ;
	node *temp = head;
	current->id = id;
	strcpy(current->name, name);
	current->age = age;
	strcpy(current->disease, disease);
	current->priority = priority;
	
	if(head == NULL)
	{
		head = current;
		tail = current;
		current->next = NULL;
	}
		
	else
	{
		if(head->priority < priority)
		{
			current->next = head;
			head = current;
		}
		else
		{
			while(temp->next != NULL && temp->next->priority >= priority)
				temp = temp->next;
	
			current->next = temp->next;
			temp->next = current;
		
			temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp = tail;
		}
	}	
}

node linkedList ::deleteNode(int pos)
{
	node *current,*temp;
	node data;
	
	if(pos==1)
	{
		current = head;
		head = head->next;
	}
	else
	{
		temp = head;
		for(int i=0; i<pos-1; i++)
			temp = temp->next;
	
		current = temp->next;
		temp->next = current->next;
	}
	
	data.id = current->id;
	strcpy(data.name, current->name);
	data.age = current->age;
	strcpy(data.disease, current->disease);
	data.priority = current->priority;
	delete(current);
	
	return data;
}

 
void linkedList ::displayList()
{
	node *temp=head;
	
	while(temp!=NULL)
	{
		cout<<setw(5)<<temp->id<<"\t"<<setw(15)<<temp->name<<"\t"<<setw(2)<<temp->age<<"\t"<<temp->disease<<endl;
		temp=temp->next;
	}
}

