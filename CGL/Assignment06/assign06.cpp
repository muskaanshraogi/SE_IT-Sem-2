
/*--------------------------------------------------------------------------------------------------------------
Roll no : 23255
Batch : H10
Problem Statement :
        Implement translation, sheer, rotation and scaling transformations on equilateral triangle and rhombus.
Date : 
-----------------------------------------------------------------------------------------------------------------*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<GL/glut.h>
#define PI 3.1415926535

using namespace std;

void displayResultT();
void displayResultR();

int choice;
float xx1, yy1, len, angle, t[3][3], r[4][3], m[3][2], result[10][10];

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780,780,-420,420);
}

void multiplyT()
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			result[i][j]=0;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
				result[i][j]+=t[i][k]*m[k][j];
		}
	}
	displayResultT();
}

void multiplyR()
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
			result[i][j]=0;
	}
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
				result[i][j]+=r[i][k]*m[k][j];
		}
	}
	displayResultR();
}

void displayResultT()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	
	glPointSize(2.0);
	glBegin(GL_LINES);	
	glVertex2d(-1000,0);
	glVertex2d(1000,0);
	glVertex2d(0,-1000);
	glVertex2d(0,1000);
	glEnd();
	
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<3;i++)
	{
		glVertex2f(result[i][0],result[i][1]);
	}
	glEnd();
	glFlush();
}

void displayResultR()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	
	glPointSize(2.0);
	glBegin(GL_LINES);	
	glVertex2d(-1000,0);
	glVertex2d(1000,0);
	glVertex2d(0,-1000);
	glVertex2d(0,1000);
	glEnd();
	
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{
		glVertex2f(result[i][0],result[i][1]);
	}
	glEnd();
	glFlush();
}

void displayTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	
	glPointSize(2.0);
	glBegin(GL_LINES);	
	glVertex2d(-1000,0);
	glVertex2d(1000,0);
	glVertex2d(0,-1000);
	glVertex2d(0,1000);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<3;i++)
	{
		glVertex2d(t[i][0],t[i][1]);
	}
	glEnd();
	
	glFlush();	
}

void displayRhombus()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	
	glPointSize(2.0);
	glBegin(GL_LINES);	
	glVertex2d(-1000,0);
	glVertex2d(1000,0);
	glVertex2d(0,-1000);
	glVertex2d(0,1000);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{
		glVertex2d(r[i][0],r[i][1]);
	}
	glEnd();
	
	glFlush();
}

void rotateTriangle()
{
	int ang;
	
	cout<<"\nEnter the angle of rotation :"<<endl;
	cin>>ang;
	
	ang = ang * (PI/180);
	
	m[0][0] = cos(ang);
	m[0][1] = sin(ang);
	m[0][2] = 0;
	m[1][0] = -sin(ang);
	m[1][1] = cos(ang);
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	
	if(choice == 1)
		multiplyT();
	else
		multiplyR();
}

void scaleTriangle()
{
	float sx, sy;
	
	cout<<"\nEnter the scaling factor in x direction :"<<endl;
	cin>>sx;
	cout<<"\nEnter the scaling factor in y direction :"<<endl;
	cin>>sy;
	
	m[0][0] = sx;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = sy;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	
	if(choice == 1)
		multiplyT();
	else
		multiplyR();
}

void translateTriangle()
{
	float tx, ty;
	
	cout<<"\nEnter the translation factor in x direction :"<<endl;
	cin>>tx;
	cout<<"\nEnter the translation factor in y direction :"<<endl;
	cin>>ty;
	
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = tx;
	m[2][1] = ty;
	m[2][2] = 1;
	
	if(choice == 1)
		multiplyT();
	else
		multiplyR();
}

void sheerTriangle()
{
	float x, y;
	
	cout<<"\nEnter the sheer factor in x direction :"<<endl;
	cin>>x;
	cout<<"\nEnter the sheer factor in y direction :"<<endl;
	cin>>y;
	
	m[0][0] = 1;
	m[0][1] = y;
	m[0][2] = 0;
	m[1][0] = x;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	
	if(choice == 1)
		multiplyT();
	else
		multiplyR();
}

void menu(int item)
{
	switch(item)
	{
	case 1:
		scaleTriangle();
		break;
	case 2:
		sheerTriangle();
		break;
	case 3:
		rotateTriangle();
		break;
	case 4:
		translateTriangle();
		break;
	case 5:
		exit(0);
	}
}

int main(int argc, char **argv)
{
	cout<<"\n****TRANSFORMATION MENU*****\n1)Traingle\n2)Rhombus\n3)Exit"<<endl;
	cin>>choice;
	
	if(choice != 3)
	{
		cout<<"\nEnter the initial vertex :"<<endl;
		cin>>xx1>>yy1;
		cout<<"\nEnter the length :"<<endl;
		cin>>len;
		
		if(choice == 2)
		{
			cout<<"\nEnter the angle :"<<endl;
			cin>>angle;
			angle = angle * (PI/180);
			
			r[0][0] = xx1;
			r[0][1] = yy1;
			r[0][2] = 1;
			r[1][0] = xx1;
			r[1][1] = yy1 + len;
			r[1][2] = 1;
			r[2][0] = xx1 + len*sin(angle);
			r[2][1] = yy1 + len + len*cos(angle);
			r[2][2] = 1;
			r[3][0] = xx1 + len*sin(angle);
			r[3][1] = yy1 + len*cos(angle);
			r[3][2] = 1;
			
		}
		else
		{
			t[0][0] = xx1;
			t[0][1] = yy1;
			t[0][2] = 1;
			t[1][0] = xx1 + len;
			t[1][1] = yy1;
			t[1][2] = 1;
			t[2][0] = xx1 + len/2;
			t[2][1] = yy1 + (sqrt(3)/2)*len;
			t[2][2] = 1;
		}
	}
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366,768);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Transformation");
	init();
	
	switch(choice)
	{
	case 1:
		glutDisplayFunc(displayTriangle);
		break;
	case 2:
		glutDisplayFunc(displayRhombus);
		break;
	case 3:
		exit(0);
	}
	
	glutCreateMenu(menu);
	glutAddMenuEntry("Scale",1);
	glutAddMenuEntry("Sheer",2);
	glutAddMenuEntry("Rotate",3);
	glutAddMenuEntry("Translate",4);
	glutAddMenuEntry("Exit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutMainLoop();
	
	return 0;
}
