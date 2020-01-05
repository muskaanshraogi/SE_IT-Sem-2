#include<iostream>
#include "linkedlist.h"

using namespace std;

template<class T>
linkedList<T>::linkedList()
{
	head=NULL;
}

template<class T>
void linkedList<T>::insertNode(T data,int pos)
{
	node<T>*current=new node<T>;
	node<T>*temp;
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

template<class T>
T linkedList<T>::deleteNode(int pos)
{
	node<T>*current,*temp;
	T data;
	
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

template<class T>
void linkedList<T>::displayList()
{
	node<T>*temp=head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

