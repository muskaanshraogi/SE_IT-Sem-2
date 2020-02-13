
#include<dos.h>
#include<stdio.h>
#include<conio.h>

void createDirectory();
void deleteDirectory();
union REGS inreg, outreg;	//i/o registers
struct SREGS segreg;		//segment register


void main()
{
	int choice;
	
	clrscr();
	
	do
	{
		printf("\n***FILE MENU***\n1)Create a directory\n2)Delete file\n3)Copy file\n4)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			createDirectory();
			break;
		case 2:
			deleteDirectory();
			break;
		case 4:
			exit(0);
		}
	}while(1);
}

void createDirectory()
{
	char dirname[20];
	
	printf("\nEnter a name for the new directory :\n");
	scanf("%s",dirname);
	
	inreg.h.ah = 0x39; //create sub-directory
	inreg.x.dx = FP_OFF(dirname);
	segreg.ds = FP_SEG(dirname);
	
	int86x(0x21, &inreg, &outreg, &segreg);
	if(outreg.x.cflag)
		printf("\nError! Could not create directory.\n");
	else
		printf("\nDirectory created successfully.\n");
}

void deleteDirectory()
{
	char filename[20];
	
	printf("\nEnter the name of the file to be deleted :\n");
	scanf("%s",filename)
	
	inreg.h.ah = 0x41;
	inreg.x.dx = FP_OFF(filename);
	
	int86(0x21, &inreg, &outreg);
	if(outreg.x.cflag)
		printf("\nError! File could not be deleted.\n");
	else
		printf("\nFile deleted successfully.\n");
}
