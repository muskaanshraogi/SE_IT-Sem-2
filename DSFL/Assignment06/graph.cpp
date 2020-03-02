#include<bits/stdc++.h>
#include "graph.h"

using namespace std;

static int maximum = 1;

graph::graph()
{
	head = NULL;
}

void graph::createNode(char name[25], int date, int month, int year, int comments)
{
	node *temp;
	node *current = new node;
	current->id = maximum++;
	strcpy(current->name,name);
	current->birthday.date = date;
	current->birthday.month = month;
	current->birthday.year = year;
	current->comments = comments;
	current->friends = NULL;
	current->next = NULL;
	
	if(head == NULL)
		head = current;
	
	else
	{
		temp = head;
		while(temp->next !=NULL)
			temp = temp->next;
		temp->next = current;
	}
}

int graph::isEmpty()
{
	if(head == NULL)
		return 1;
	return 0;
}

void graph::display()
{
	node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->id<<". "<<temp->name<<endl;
		temp = temp->next;
	}	
}

void graph::makeFriend(char name1[25], char name2[25])
{
	node temp = head;
	node *user1, *user2;
	friendNode *newfriend1 = new friendNode;
	friendNode *newfriend2 = new friendNode;
	
	while(temp != NULL && strcmp(temp->name,name1) != 0)
		temp = temp->next;
	user1 = temp;
	
	while(temp != NULL && strcmp(temp->name,name2) != 0)
		temp = temp->next;
	user2 = temp;
	
	if(user1 == NULL || user2 == NULL)
	{
		cout<<"\nUser does not exist."<<endl;
		return;
	}
	else
	{
		newfriend1->friendAddress = user1;
		newfriend1->next = NULL;
		newfriend1->friendAddress = user2;
		newfriend1->next = NULL;
	}
	
	if(user1->friends == NULL)
		user1->friends = newfriend1;
	else
	{
		temp = user1->friends;
		while(temp->next != NULL)
			temp = temp->next;
		 temp->next = newfriend1;
	}
	
	if(user2->friends == NULL)
		user2->friends = newfriend2;
	else
	{
		temp = user2->friends;
		while(temp->next != NULL)
			temp = temp->next;
		 temp->next = newfriend2;
	}
	
	cout<<"\n"<<user1->name<<" is now friends with "<<user2->name<<"."<<endl;
}
