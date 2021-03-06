
#include<dos.h>
#include<stdio.h>
#include<conio.h>

void createDirectory();
void deleteFile();
void copyFile();
union REGS inreg, outreg;	//i/o registers
struct SREGS segreg;		//segment register


void main()
{
	int choice;
	char dirname[20];
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
			deleteFile();
			break;
		case 3:
			copyFile();
			break;
		case 4:
			exit(0);
		}
	}while(1);
}

void createDirectory()
{
	char dirname[20];

	printf("\nEnter a name for the new file :\n");
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

void deleteFile()
{
	char filename[20];

	printf("\nEnter the name of the file to be deleted :\n");
	scanf("%s",filename);

	inreg.h.ah = 0x41;
	inreg.x.dx = FP_OFF(filename);
	int86(0x21, &inreg, &outreg);

	if(outreg.x.cflag)
		printf("\nError! File could not be deleted.\n");
	else
		printf("\nFile deleted successfully.\n");
}

void copyFile()
{
	char far(filename[20]), far(newfile[20]);
	int h1, h2, bytes;
	char far(buffer[512]);

	printf("\nEnter the name of the file to be copied :\n");
	scanf("%s",filename);

	inreg.h.ah = 0x3D;	//open file in read mode
	inreg.x.dx = FP_OFF(filename);
	segreg.ds = FP_SEG(filename);
	inreg.h.al = 0x00;
	int86x(0x21, &inreg, &outreg, &segreg);
	h1 = outreg.x.ax;

	if(outreg.x.cflag)
		printf("\nError! File could not be read.\n",filename);
	
	printf("\nEnter a name for the new file :\n");
	scanf("%s",newfile);

	inreg.h.ah = 0x3C;
	inreg.x.dx = FP_OFF(newfile);
	inreg.x.cx = 0x00;
	int86(0x21, &inreg, &outreg);

	if(!outreg.x.cflag)
		printf("\nNew file created!\n");
		
	inreg.h.ah = 0x3D;	//open file in write mode
	inreg.x.dx = FP_OFF(newfile);
	inreg.h.al = 0x01;
	int86(0x21, &inreg, &outreg);
	h2 = outreg.x.ax;
	
	
	inreg.h.ah = 0x3F;	//read file
	inreg.x.bx = h1;
	inreg.x.cx = 0xFF;
	inreg.x.dx = FP_OFF(buffer);
	segreg.ds = FP_SEG(buffer);
	int86x(0x21, &inreg, &outreg, &segreg);
	bytes = outreg.x.ax;
	
	if(!outreg.x.cflag)
	{
		printf("\nReading file....\n");
		printf("\nReading %u bytes..\n",outreg.x.ax);
	}
	
	inreg.h.ah = 0x40;	//write to file
	inreg.x.bx = h2;
	inreg.x.cx = bytes;
	inreg.x.dx = FP_OFF(buffer);
	segreg.ds = FP_SEG(buffer);
	int86x(0x21, &inreg, &outreg, &segreg);
	
	
	if(outreg.x.cflag)
		printf("\nError copying file!\n");
	else
	{
		printf("\Writing %u bytes..\n",outreg.x.ax);
		printf("\nFile copied successfully!\n");
	}

	inreg.h.ah = 0x3E;	//close file
	inreg.x.dx = h1;
	int86(0x21, &inreg, &outreg);
	
	inreg.h.ah = 0x3E;	//close file
	inreg.x.dx = h2;
	int86(0x21, &inreg, &outreg);
}
