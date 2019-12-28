

#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

float xx1,yy1,xx2,yy2;

void plot(float x,float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void drawline(float x1,float y1,float x2,float y2)
{
	float x,y,Xin,Yin,dy,dx,length;
	int i;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>=abs(dy))
		length=abs(dx);
	else
		length=abs(dy);
		
	Xin=dx/length;
	Yin=dy/length;
	x=x1;
	y=y1;
	plot(round(x),round(y));
	
	for(i=0;i<length;i++)
	{
		x=x+Xin;
		y=y+Yin;
		plot(round(x),round(y));
	}
	glFlush();
}


void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(1.0);
	glColor3f(1.0,1.0,1.0);
	drawline(-100,0,100,0);
	drawline(0,-100,0,100);
	
	glPointSize(2.0);
	glColor3f(1.0,0.0,0.0);
	drawline(xx1,yy1,xx1,yy2);
	drawline(xx1,yy2,xx2,yy2);
	drawline(xx2,yy2,xx2,yy1);
	drawline(xx2,yy1,xx1,yy1);
	
	glColor3f(0.5,0.5,0.0);
	drawline((xx1+xx2)/2,yy1,xx2,(yy1+yy2)/2);
	drawline(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
	drawline((xx1+xx2)/2,yy2,xx1,(yy1+yy2)/2);
	drawline(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
	
	glColor3f(0.0,0.5,0.5);
	drawline((3*xx1+xx2)/4,(3*yy1+yy2)/4,(xx1+3*xx2)/4,(3*yy1+yy2)/4);
	drawline((xx1+3*xx2)/4,(3*yy1+yy2)/4,(xx1+3*xx2)/4,(yy1+3*yy2)/4);
	drawline((xx1+3*xx2)/4,(yy1+3*yy2)/4,(3*xx1+xx2)/4,(yy1+3*yy2)/4);
	drawline((3*xx1+xx2)/4,(yy1+3*yy2)/4,(3*xx1+xx2)/4,(3*yy1+yy2)/4);
	glFlush();
	
}

int main(int argc,char **argv)
{
	cout<<"Enter the co-ordinates of point 1:\n"<<endl;
	cin>>xx1>>yy1;
	cout<<"Enter the co-ordinates of point 2:\n"<<endl;
	cin>>xx2>>yy2;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("DDA");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
