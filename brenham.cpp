// brenham.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<GL/glut.h>
#include<stdio.h>
int x1,y1,x2,y2;
void draw_pixel(int x,int y)
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void brenhams_line_draw(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1,dy=y2-y1;
	int p=2*dy-dx;
	int x=x1,y=y1;
	if(dx<0)
	{
		x=x2;
		y=y2;x2=x1;
	}
	draw_pixel(x,y);
	for(int i=0;i<=dx-1;i++)
	{
		x++;
		if(p<0)
			p+=2*dy;
		else
		{
			y++;
			p+=(2*dy)-(2*dx);
		}
		draw_pixel(x,y);
	}
}
void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	brenhams_line_draw(x1,y1,x2,y2);
	glFlush();
}
void main()
{
	printf("Enter the start point(x1,y1)\n");
	scanf("%d %d",&x1,&y1);
	printf("Enter the end point(x2,y2)\n");
	scanf("%d %d",&x2,&y2);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Brenham's line Drawing");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}