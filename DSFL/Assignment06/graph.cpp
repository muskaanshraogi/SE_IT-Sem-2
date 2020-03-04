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
	node *temp = head;
	friendNode *temp1;
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
		newfriend1->friendAddress = user2;
		newfriend1->next = NULL;
		newfriend2->friendAddress = user1;
		newfriend2->next = NULL;
	}
	
	if(user1->friends == NULL)
		user1->friends = newfriend1;
	else
	{
		temp1 = user1->friends;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		 temp1->next = newfriend1;
	}
	
	if(user2->friends == NULL)
		user2->friends = newfriend2;
	else
	{
		temp1 = user2->friends;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		 temp1->next = newfriend2;
	}
	
	cout<<"\n"<<user1->name<<" is now friends with "<<user2->name<<"."<<endl;
}

void graph:: displayNode(char name[25])
{
	node *temp = head;
	friendNode *temp1;
	
	while(temp != NULL && strcmp(temp->name,name) != 0)
		temp = temp->next;
		
	if(temp)
	{
		temp1 = temp->friends;
		cout<<"\n-----"<<temp->name<<"'s Profile-----"<<endl;
		cout<<"\nBirthday : "<<temp->birthday.date<<"/"<<temp->birthday.month<<"/"<<temp->birthday.year<<endl;
		cout<<"\nComments : "<<temp->comments<<endl;
		if(temp1)
		{
			int i = 1;
			cout<<"\nFriends List :"<<endl;
			while(temp1 != NULL)
			{
				cout<<i++<<". "<<temp1->friendAddress->name<<endl;
				temp1 = temp1->next;
			}
		}
		cout<<endl;
	}
	else
		cout<<"\nUser does not exist."<<endl;
}

void graph:: dfs(int month)
{
	stack<node *>s;
	friendNode *temp1;
	node *temp = head;
	while(temp)
	{
		temp->visited = 0;
		temp = temp->next;
	}
		
	temp = head;
	s.push(temp);
	head->visited = 1;
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		
		if(temp->birthday.month == month)
			cout<<temp->name<<"\t"<<temp->birthday.date<<"/"<<temp->birthday.month<<"/"<<temp->birthday.year<<endl;
			
		temp1 = temp->friends;
		while(temp1)
		{
			if(!temp1->friendAddress->visited)
			{
				temp1->friendAddress->visited = 1;
				s.push(temp1->friendAddress);
			}
			temp1 = temp1->next;
		}	
	}
}
