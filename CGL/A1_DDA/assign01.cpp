

#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

float xx1,yy1,xx2,yy2;

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void drawlineDDA(float x1,float y1,float x2,float y2)
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
          plot(x,y);
          
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
         		plot(x,y);
         	
          }
     }
     else	                                          
     {
	 	plot(x,y);
	 	
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
			plot(x,y);
		}
	}

	
}


void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}



void displayDDA()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(1.0);
	glColor3f(1.0,1.0,1.0);
	drawlineDDA(-100,0,100,0);
	drawlineDDA(0,-100,0,100);
	
	glPointSize(2.0);
	glColor3f(1.0,0.0,0.0);
	drawlineDDA(xx1,yy1,xx1,yy2);
	drawlineDDA(xx1,yy2,xx2,yy2);
	drawlineDDA(xx2,yy2,xx2,yy1);
	drawlineDDA(xx2,yy1,xx1,yy1);
	
	glColor3f(0.5,0.5,0.0);
	drawlineDDA((xx1+xx2)/2,yy1,xx2,(yy1+yy2)/2);
	drawlineDDA(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
	drawlineDDA((xx1+xx2)/2,yy2,xx1,(yy1+yy2)/2);
	drawlineDDA(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
	
	glColor3f(0.0,0.5,0.5);
	drawlineDDA((3*xx1+xx2)/4,(3*yy1+yy2)/4,(xx1+3*xx2)/4,(3*yy1+yy2)/4);
	drawlineDDA((xx1+3*xx2)/4,(3*yy1+yy2)/4,(xx1+3*xx2)/4,(yy1+3*yy2)/4);
	drawlineDDA((xx1+3*xx2)/4,(yy1+3*yy2)/4,(3*xx1+xx2)/4,(yy1+3*yy2)/4);
	drawlineDDA((3*xx1+xx2)/4,(yy1+3*yy2)/4,(3*xx1+xx2)/4,(3*yy1+yy2)/4);
	glFlush();
	
}

void displayBLA()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(1.0);
	glColor3f(1.0,1.0,1.0);
	drawlineBLA(-100,0,100,0);
	drawlineBLA(0,-100,0,100);
	
	glPointSize(2.0);
	glColor3f(1.0,0.0,0.0);
	drawlineBLA(xx1,yy1,xx1,yy2);
	drawlineBLA(xx1,yy2,xx2,yy2);
	drawlineBLA(xx2,yy2,xx2,yy1);
	drawlineBLA(xx2,yy1,xx1,yy1);
	
	glColor3f(0.5,0.5,0.0);
	drawlineBLA((xx1+xx2)/2,yy1,xx2,(yy1+yy2)/2);
	drawlineBLA(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
	drawlineBLA((xx1+xx2)/2,yy2,xx1,(yy1+yy2)/2);
	drawlineBLA(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
	
	glColor3f(0.0,0.5,0.5);
	drawlineBLA((3*xx1+xx2)/4,(3*yy1+yy2)/4,(xx1+3*xx2)/4,(3*yy1+yy2)/4);
	drawlineBLA((xx1+3*xx2)/4,(3*yy1+yy2)/4,(xx1+3*xx2)/4,(yy1+3*yy2)/4);
	drawlineBLA((xx1+3*xx2)/4,(yy1+3*yy2)/4,(3*xx1+xx2)/4,(yy1+3*yy2)/4);
	drawlineBLA((3*xx1+xx2)/4,(yy1+3*yy2)/4,(3*xx1+xx2)/4,(3*yy1+yy2)/4);
	glFlush();
	
}

int main(int argc,char **argv)
{
	int choice;
	
	cout<<"Enter the co-ordinates of point 1:\n"<<endl;
	cin>>xx1>>yy1;
	cout<<"Enter the co-ordinates of point 2:\n"<<endl;
	cin>>xx2>>yy2;
	
	cout<<"******MENU******\n1)DDA\n2)BLA\n3)Exit"<<endl;
	cin>>choice;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	
	switch(choice)
	{
	case 1:
		glutCreateWindow("DDA");
		init();
		glutDisplayFunc(displayDDA);
		glutMainLoop();
		break;
	
	case 2:
		glutCreateWindow("BLA");
		init();
		glutDisplayFunc(displayBLA);
		glutMainLoop();
		break;
			
	case 3:
		exit(0);
	}
	
	
	return 0;
}
