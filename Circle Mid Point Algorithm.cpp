#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,100.0,0.0,100.0);
}

void setPixel(GLint x,GLint y)
{
	cout<<x<<", "<<y<<endl;
  	glBegin(GL_POINTS);
	glVertex2i(x,y);
  	glEnd();
}

void plot_circle_points(int xCenter,int yCenter, int x, int y)
{
	cout<<"Oct 1: ";	setPixel(xCenter + y,yCenter + x);
	cout<<"Oct 2: ";	setPixel(xCenter + x,yCenter + y);
	cout<<"Oct 3: ";	setPixel(xCenter - x,yCenter + y);
	cout<<"Oct 4: ";	setPixel(xCenter - y,yCenter + x);
	cout<<"Oct 5: ";	setPixel(xCenter - y,yCenter - x);
	cout<<"Oct 6: ";	setPixel(xCenter - x,yCenter - y);
	cout<<"Oct 7: ";	setPixel(xCenter + x,yCenter - y);
	cout<<"Oct 8: ";	setPixel(xCenter + y,yCenter - x);
}
void circle_draw_mid_point(int xCenter, int yCenter, int radius)
{
	int x = 0;
	int y = radius;
	int p = 1 - radius;

	plot_circle_points(xCenter,yCenter, x,y);

	while(x < y)
	{
		x++;
		if(p < 0)
		{
			p += 2*x + 1;
		}
		else{
			y--;
			p += 2*(x-y) + 1;
		}
		plot_circle_points(xCenter,yCenter,x,y);
	}
}

void update()
{
	glTranslatef(16,16,0);

	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0f);

	// Marking Origin
	glColor3f( 0 ,1, 0);  
	setPixel(0,0);

	glColor3f( 1 ,0, 0);  
	circle_draw_mid_point(0,0,8);
	
	glFlush();
}
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Circle Mid Point Algorithm");
	init();
	glutDisplayFunc( update );
	glutMainLoop();
	return 0;
}