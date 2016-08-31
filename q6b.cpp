#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,50.0,0.0,50.0);
}

void setPixel(GLint x,GLint y)
{
	cout<<x<<", "<<y<<endl;
  	glBegin(GL_POINTS);
	glVertex2i(x,y);
  	glEnd();
}

void line_draw_bresenham(int x0, int y0, int xn, int yn)
{
	// Converting inverted co-ordinates of line if necessary.
	if(xn <= x0 && yn <= y0)
	{
		swap(xn,x0);
		swap(yn,y0);
	}
	else if(xn <= x0 && yn >= y0)
	{
		swap(xn,x0);
		swap(yn,y0);
	}

	int dy = abs(yn - y0);
	int dx = abs(xn - x0);
	int x = x0;
	int y = y0;
	int iny = y0 < yn ? 1 : -1;
	int inx = x0 < xn ? 1 : -1;
	
	cout<<"Drawing Line from "<<x0<<", "<<y0<<" to "<<xn<<", "<<yn<<endl;
	setPixel(x,y);

	if(dy <= dx)
	{
		int twody = 2*dy;
		int twodydx = 2*(dy - dx);
		int pk = 2*dy - dx;
		while(x != xn)
		{
			if(pk < 0)
			{
				pk = pk + twody;
			}
			else
			{
				y+=iny;
				pk = pk + twodydx;
			}
			x+=inx;
			setPixel(x,y);
		}
	}
	else{
		int twodx = 2*dx;
		int twodxdy = 2*(dx - dy);
		int pk = 2*dx - dy;
		while(y != yn)
		{
			if(pk < 0)
			{
				pk = pk + twodx;
			}
			else
			{
				x+=inx;
				pk = pk + twodxdy;
			}
			y+=iny;
			setPixel(x,y);
		}
	}
}

void update()
{
	glTranslatef(8,8,0);

	glClear(GL_COLOR_BUFFER_BIT);

	// Marking Origin
	glColor3f( 0 ,1, 0);  
	setPixel(0,0);

	glColor3f( 1 ,0, 0);  
	glPointSize(5.0f);
	line_draw_bresenham(-8,0,0,8);
	line_draw_bresenham(0,8,8,0);
	line_draw_bresenham(8,0,0,-8);
	line_draw_bresenham(0,-8,-8,0);
	
	glFlush();
}
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Tutorial-1 Q6b");
	init();
	glutDisplayFunc( update );
	glutMainLoop();
	return 0;
}