#include <GL/glut.h>

float x1, y1, x2, y2, x3, y3, x4, y4;

void draw_pixel(int x, int y)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void edge_detect(float x1, float y1, float x2, float y2, int *le, int *re)
{
	float mx, temp;
	if (y2 < y1)
	{
		temp = x1; x1 = x2; x2 = temp; 
		temp = y1; y1 = y2; y2 = temp; 
	}
	if (y1 != y2) mx = (x2 - x1) / (y2 - y1);
	else mx = (x2 - x1);

	float x = x1;
	for (int i = y1; i <= y2; i++)
	{
		if (x < (float) le[i]) le[i] = (int) x;
		if (x > (float) re[i]) re[i] = (int) x;
		
		x += mx;
	} 
}

void scanfill()
{
	int le[500], re[500];
	for (int i = 0; i < 500; i++)
	{
		le[i] = 500;
		re[i] = 0;
	}

	edge_detect(x1, y1, x2, y2, le, re);
	edge_detect(x2, y2, x3, y3, le, re);
	edge_detect(x3, y3, x4, y4, le, re);
	edge_detect(x4, y4, x1, y1, le, re);	

	for (int y = 0; y < 500; y++)
	{
		if (le[y] <= re[y])
		{
			for (int i = (int) le[y] ; i < (int) re[y]; i++)
				draw_pixel(i, y);
		}
	}
}

void display()
{
	x1 = 100; y1 = 100;
	x2 = 300; y2 = 100;
	x3 = 300; y3 = 400;
	x4 = 100; y4 = 400;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);	
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
	glEnd();			

	scanfill();

	glFlush(); 
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 499.0, 0, 499.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Scan Line");	
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;	
}
