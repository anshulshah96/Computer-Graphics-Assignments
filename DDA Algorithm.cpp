#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,30.0,0.0,30.0);
}

void setPixel(GLint x,GLint y)
{
	cout<<x<<", "<<y<<endl;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

float round_value(float v)
{
  return floor(v + 0.5);
}
void line_draw_DDA(int x0, int y0, int xn, int yn)
{
	cout<<"Drawing Line from "<<x0<<", "<<y0<<" to "<<xn<<", "<<yn<<endl;
	double dx=(xn-x0);
	double dy=(yn-y0);
	double steps;
	float x_inc,y_inc,x=x0,y=y0;

	steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	x_inc=dx/(float)steps;
	y_inc=dy/(float)steps;


	setPixel(x,y);
	int k;
	for(k=0;k<steps;k++)
	{
		x+=x_inc;
		y+=y_inc;
		setPixel(round_value(x), round_value(y));
	}
}

void update()
{
	// glTranslatef(8,8,0);

	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0f);
	glColor3f( 1 ,0, 0);  

	line_draw_DDA(1,1,8,7);
	line_draw_DDA(1,1,8,2);

	glFlush();
}
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("DDA Algorithm");
	init();
	glutDisplayFunc( update );
	glutMainLoop();
	return 0;
}