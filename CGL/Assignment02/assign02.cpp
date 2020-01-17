
#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

float r;

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780,780,-420,420);
}

void drawMidpoint(float r1)
{
	float x, y, p;
	
	p = 5/4 - r1;
	x = 0;
	y = r1;
	plot(x,y);
	
	while(x <= y)
	{
		if(p<0)
		{
			p += 2*x+3;
			x += 1;
		}
		else if(p >=0)
		{
			p += 2*(x-y)+5;
			x += 1;
			y -= 1;
		}
		
		plot(x,y);
		plot(x,-y);
		plot(-x,y);
		plot(-x,-y);
		plot(y,x);
		plot(-y,x);
		plot(y,-x);
		plot(-y,-x);
	}
	
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


void displayMidpoint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(1.0);
	glColor3f(1.0,1.0,1.0);
	drawlineDDA(-800,0,800,0);
	drawlineDDA(0,-800,0,800);
	
	glColor3f(1.0,0.0,0.0);
	drawMidpoint(r);
	
	glColor3f(0.0,1.0,0.0);
	drawlineDDA(0, 2*r, -sqrt(3)*r, -r);
	drawlineDDA(0, 2*r, sqrt(3)*r, -r);
	drawlineDDA(sqrt(3)*r, -r, -sqrt(3)*r, -r);
	
	glColor3f(0.0,0.0,1.0);
	drawMidpoint(2*r);
	glFlush();
}

int main(int argc,char **argv)
{
	int choice;
	
	cout<<"Enter the radius of the circle :\n"<<endl;
	cin>>r;
	
	cout<<"******MENU******\n1)Midpoint Circle Drawing Algorithm\n2)Breshenham's Circle Drawing Algorithm\n3)Exit"<<endl;
	cin>>choice;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(100,100);
	
	switch(choice)
	{
	case 1:
		glutCreateWindow("Midpoint Circle");
		init();
		glutDisplayFunc(displayMidpoint);
		glutMainLoop();
		break;

	case 2:
		glutCreateWindow("Bresenham's Circle");
		init();
		//glutDisplayFunc(displayBresenham);
		glutMainLoop();
		break;
			
	case 3:
		exit(0);
	}
	
	
	return 0;
}
