#include<bits/stdc++.h>
#include "graph.cpp"

using namespace std;

class facebook
{
	graph g;
     public:
     	void createProfile();
     	void displayProfile();
     	void displayAll();
     	void befriend();
     	void birthdays();
     	void maxComments();
     	void minComments();
};

void facebook::createProfile()
{
	node profile;
	
	cout<<"\n*****CREATE YOUR PROFILE*****"<<endl;
	cout<<"\nEnter your name :"<<endl;
	cin>>profile.name;
	cout<<"\nEnter your birth date(dd<space>mm<space>yyyy) :"<<endl;
	cin>>profile.birthday.date>>profile.birthday.month>>profile.birthday.year;
	cout<<"\nEnter the number of comments you've made :"<<endl;
	cin>>profile.comments;
	
	g.createNode(profile.name,profile.birthday.date,profile.birthday.month,profile.birthday.year,profile.comments);
	cout<<"\nProfile created successfully! Welcome to facebook."<<endl;
}

void facebook::displayAll()
{
	if(g.isEmpty())
		cout<<"\nNo network yet."<<endl;
		
	else
	{
		cout<<"\n-------------FACEBOOK USERS-------------"<<endl;
		g.display();
		cout<<"----------------------------------------"<<endl;
	}
}

void facebook::displayProfile()
{
	char user[25];
	
	cout<<"\nEnter name :"<<endl;
	cin>>user;
	g.displayNode(user);
}

void facebook::befriend()
{
	char user1[25], user2[25];
	
	cout<<"\nEnter your name :"<<endl;
	cin>>user1;
	cout<<"\nEnter the name of your new friend :"<<endl;
	cin>>user2;
	g.makeFriend(user1,user2);
}

void facebook::birthdays()
{
	int month;
	char monthc[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "Decemeber"};
	cout<<"\nEnter the month :"<<endl;
	cin>>month;
	cout<<"\n-----Birthdays in "<<monthc[month-1]<<"-----"<<endl;
	g.dfs(month);
	cout<<"----------------------------"<<endl;
}

int main()
{
	int choice, data;
	facebook f;
	
	do
	{
		cout<<"\n*****FACEBOOK*****\n1)Create new profile\n2)See who's on facebook\n3)Add Friends\n4)View Profile\n5)See who is most social\n6)See who is most / least active\n7)Birthdays in the month\n8)Logout"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			f.createProfile();
			break;
		case 2:
			f.displayAll();
			break;
		case 3:
			f.befriend();
			break;
		case 4:
			f.displayProfile();
			break;
		case 7:
			f.birthdays();
			break;
		case 8:
			exit(0);
		}
	}while(1);
	
	return 0;
}
