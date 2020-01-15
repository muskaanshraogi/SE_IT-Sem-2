
#include<bits/stdc++.h>
#include "queue.cpp"

using namespace std;

class patient
{
	priorityQueue q;
    public:
    	void addPatient();
    	void servicePatient();
    	void displayAll();
};

int priority(char disease[20]);

void patient::addPatient()
{
	node data;
	cout<<"\n***ADD A NEW PATIENT***"<<endl;
	cout<<"\nEnter patient id : "<<endl;
	cin>>data.id;
	cout<<"\nEnter the name of the patient :"<<endl;
	cin.ignore(1,'\n');
	cin.getline(data.name,20);
	cout<<"\nEnter the patient's age :"<<endl;
	cin>>data.age;
	cout<<"\nEnter the disease/disorder :"<<endl;
	cin.ignore(1,'\n');
	cin.getline(data.disease,20);
	data.priority = priority(data.disease);
	
	q.enQueue(data.id, data.name, data.age, data.disease, data.priority);
	cout<<"\nPatient added to the list successfully."<<endl;
}

void patient::servicePatient()
{
	if(!q.isEmpty())
	{
		node data = q.deQueue();
		cout<<"\nNext patient : "<<data.id<<"\tName : "<<data.name<<" ("<<data.disease<<")\tAge :"<<data.age<<endl;
	}
	else 
		cout<<"\nNo patient available at the moment."<<endl;
}

void patient::displayAll()
{
	cout<<"\n*****PATIENTS' LIST*****"<<endl;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	cout<<setw(5)<<"ID\t"<<setw(15)<<"Name\t"<<setw(2)<<"Age\tDisease/Disorder"<<endl;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	q.displayQueue();
}

int main()
{
	patient p;
	int choice;
	
	do
	{
		cout<<"\n***HOSPITAL MENU***\n"
			"1)Add patient\n"
			"2)Service patient\n"
			"3)Show all patients\n"
			"4)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			p.addPatient();
			break;
		case 2:
			p.servicePatient();
			break;
		case 3:
			p.displayAll();
			break;
		case 4:
			exit(0);
		}
	}while(1);
	
	return 0;
}

int priority(char disease[20])
{
	if(strcmp(disease,"cancer") == 0 || strcmp(disease,"accident") == 0 || strcmp(disease,"heart attack") == 0)
		return 3;
	else if(strcmp(disease,"dengue") == 0 || strcmp(disease,"typhoid") == 0)
		return 2;
	else
		return 1;
}

