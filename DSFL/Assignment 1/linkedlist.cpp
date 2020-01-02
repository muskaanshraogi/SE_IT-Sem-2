#include<iostream>
#include "linkedlist.h"

using namespace std;

linkedList::linkedList()
{
	head=NULL;
}

void linkedList::insertNode(char data,int pos)
{
	node *current=new node;
	node *temp;
	current->data=data;
	
	if(head==NULL)
	{
		current->next=NULL;
		head=current;
	}
	else
	{
		if(pos==1)
		{
			current->next=head;
			head=current;
		}
		else
		{
			temp=head;
			for(int i=0;i<pos-1;i++)
				temp=temp->next;
			
			current->next=temp->next;
			temp->next=current;
		}
	}	
}

char linkedList::deleteNode(int pos)
{
	node *current,*temp;
	char data;
	
	if(pos==1)
	{
		current=head;
		head=head->next;
	}
	else
	{
		temp=head;
		for(int i=0;i<pos-1;i++)
			temp=temp->next;
	
		current=temp->next;
		temp->next=current->next;
	}
	
	data=current->data;
	delete(current);
	
	return data;
}

void linkedList::displayList()
{
	node *temp=head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

