
#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

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

void drawMidpoint(float cx, float cy, float r1)
{
	float x, y, p;
	
	p = 5/4 - r1;
	x = 0;
	y = r1;
	
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
		
		plot(x+cx, y+cy);
		plot(x+cx,-y+cy);
		plot(-x+cx,y+cy);
		plot(-x+cx,-y+cy);
		plot(y+cx,x+cy);
		plot(-y+cx,x+cy);
		plot(y+cx,-x+cy);
		plot(-y+cx,-x+cy);
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
	drawMidpoint(-140,0,100);
	drawMidpoint(140,0,100);
	drawlineDDA(-40,0,40,0);	
	drawlineDDA(-240,0,40,120);	
	drawlineDDA(240,0,520,120);	
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Spectacles");
	init();
	glutDisplayFunc(displayMidpoint);
	glutMainLoop();

	return 0;
}
