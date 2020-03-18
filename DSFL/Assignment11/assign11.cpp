#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

class student
{
	int roll,marks;
	char name[50];
    public:
    	void accept(int n);
    	void display();
    	void modify();
    	void del();
};

void student::accept(int n)
{
	fstream outfile;
	outfile.open("students.txt",ios::app);
	
	for(int i=0;i<n;i++)
	{
	cout<<"\nEnter the roll no. of the student:"<<endl;
	cin>>roll;
	cout<<"Enter the name of the student:"<<endl;
	cin>>name;
	cout<<"Enter the marks:"<<endl;
	cin>>marks;
	outfile<<roll<<"\t"<<name<<"\t"<<marks<<endl;
	}
	
	outfile.close();
	cout<<"\nRecord(s) written to the file successfully!"<<endl;
}

void student::display()
{
	fstream infile;
	infile.open("students.txt",ios::in);
	
	cout<<"\n-------------------------------------------"<<endl;
	cout<<"Roll no.\tName\t\tMarks"<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	while(infile>>roll>>name>>marks)
	{
		
		cout<<roll<<"\t\t"<<name<<"\t"<<marks<<endl;
	}
	
	infile.close();
}

void student::modify()
{
	int rollno;
	cout<<"\nEnter the roll number whose record has to be modified:"<<endl;
	cin>>rollno;
	
	fstream infile,outfile;
	infile.open("students.txt",ios::in);
	outfile.open("temp.txt",ios::out);
	
	while(infile>>roll>>name>>marks)
	{
	
		if(roll==rollno)
		{
			cout<<"\nEnter the modified marks:"<<endl;
			cin>>marks;
			cout<<"\nModification successful!"<<endl;
		}
		outfile<<roll<<"\t"<<name<<"\t"<<marks<<endl;
	}
	infile.close();
	outfile.close();
}

void student::del()
{
	int rollno;
	cout<<"\nEnter the roll number whose record has to be deleted:"<<endl;
	cin>>rollno;
	
	fstream infile,outfile;
	infile.open("students.txt",ios::in);
	outfile.open("temp.txt",ios::out);
	
	while(infile>>roll>>name>>marks)
	{
	
		if(roll==rollno)
		{
			cout<<"\nRecord deleted successfully!"<<endl;
		}
		else
		{
			outfile<<roll<<"\t"<<name<<"\t"<<marks<<endl;
		}
		
	}
	cout<<"\nRecord deleted successfully!"<<endl;
	infile.close();
	outfile.close();
}

int main()
{
	student s;
	int choice;
	int i,n;
	do
	{
		cout<<"\n***FILE MENU***\n1)Create database\n2)Add a record\n3)Display database\n4)Delete a record\n5)Modify a record\n6)Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the number of records to be added:"<<endl;
			cin>>n;
			s.accept(n);
			break;
		case 2:
			s.accept(1);
			n++;
			break;
		case 3:
			s.display();
			break;
		case 4:
			s.del();
			remove("students.txt");
			rename("temp.txt","students.txt");
			break;
		case 5:
			s.modify();
			remove("students.txt");
			rename("temp.txt","students.txt");
			break;
		case 6:
			exit(0);
		}
	}while(1);
	return 0;
}
