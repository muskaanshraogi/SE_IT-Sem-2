/*---------------------------------------------------------------------------------------------
Roll no : 23255
Batch : H10
Problem Statement :
        Draw a 4X4 chessboard rotated 45˚ with the horizontal axis. Use Bresenham algorithm to draw all the lines. Use seed fill algorithm to fill black squares of the rotated chessboard.
Date : 
---------------------------------------------------------------------------------------------*/

#include<iostream>
#include<cmath>
#include<GL/glut.h>
#define PI 3.1415926535

using namespace std;

float xx1, yy1, xx2, yy2, len;
int backColor[] = {1,1,1};
int newcolor[] = {0,0,0};

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void drawlineBLA(float x1,float y1,float x2,float y2)
{
	int i;
     float dx,dy,xinc,yinc,inc1,inc2,p,x,y;                  
     dx=x2-x1;
     dy=y2-y1;
    
     if(dx<0)
          dx=-dx;
     if(dy<0)
          dy=-dy;
    
     xinc=1;
     yinc=1;
    
     if(x2<x1)                                    
          xinc=-1;
     if(y2<y1)
          yinc=-1;
    
    x=x1;
    y=y1;
    
     if(dx>dy)
     {
          plot(x*cos(PI/4)-y*sin(PI/4),y*cos(PI/4)+x*sin(PI/4));
          
          p=2*dy-dx;          
          inc1=2*(dy-dx);
          inc2=2*dy;
          for(i=0;i<dx;i++)
          {
    		     if(p>0)
         		{
    			     y+=yinc;
         			p+=inc1;
         		}
    		     else
    			     p+=inc2;
         		x+=xinc;
         		plot(x*cos(PI/4)-y*sin(PI/4),y*cos(PI/4)+x*sin(PI/4));
          }
     }
     else	                                          
     {
	 	plot(x*cos(PI/4)-y*sin(PI/4),y*cos(PI/4)+x*sin(PI/4));
	 	
	 	p=2*dx-dy;
	 	inc1=2*(dx-dy);
	 	inc2=2*dx;
	 	for(i=0;i<dy;i++)
	 	{
	 		if(p>0)
	 		{
				x+=xinc;
				p+=inc1;
			}
			else
				p+=inc2;
			y+=yinc;
			plot(x*cos(PI/4)-y*sin(PI/4),y*cos(PI/4)+x*sin(PI/4));
		}
	}
}

void boundFill(int x, int y)
{
	float color[3];
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&color);
	
	if((color[0]==backColor[0] || color[1]==backColor[1] || color[2]==backColor[2])&&(color[0]!=newcolor[0] || color[1]!=newcolor[1] || color[2]!=newcolor[2]))
	{
		glColor3f(newcolor[0],newcolor[1],newcolor[2]);
		plot(x*cos(PI/4)-y*sin(PI/4),y*cos(PI/4)+x*sin(PI/4));
		glFlush();
		boundFill(x,y+1);
		boundFill(x-1,y);
		boundFill(x,y-1);
		boundFill(x+1,y);
	}
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780,780,-420,420);
}

void displayChessboard()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(2.0);
	glColor3f(0.0,0.0,0.0);
	drawlineBLA(xx1,yy1,xx1,yy2);
	drawlineBLA(xx1,yy1,xx2,yy1);
	drawlineBLA(xx2,yy1,xx2,yy2);
	drawlineBLA(xx1,yy2,xx2,yy2);
	
	drawlineBLA(xx1,yy1+len/4,xx2,yy1+len/4);
	drawlineBLA(xx1,yy1+len/2,xx2,yy1+len/2);
	drawlineBLA(xx1,yy1+3*len/4,xx2,yy1+3*len/4);
	
	drawlineBLA(xx1+len/4,yy1,xx1+len/4,yy2);
	drawlineBLA(xx1+len/2,yy1,xx1+len/2,yy2);
	drawlineBLA(xx1+3*len/4,yy1,xx1+3*len/4,yy2);
	boundFill(xx1+len/8,yy1+len/8);
	glFlush();
}

int main(int argc, char **argv)
{
	cout<<"\nEnter the co-ordinates of the bottom left vertex of the chessboard :"<<endl;
	cin>>xx1>>yy1;
	cout<<"\nEnter the length of the side of the chessboard :"<<endl;
	cin>>len;
	xx2 = xx1 + len;
	yy2 = yy1 + len;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366,768);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Chessboard");
	init();
	glutDisplayFunc(displayChessboard);
	glutMainLoop();
	
	return 0;
}


