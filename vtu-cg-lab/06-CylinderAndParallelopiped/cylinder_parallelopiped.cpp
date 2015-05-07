#include <GL/glut.h>

void draw_pixel(GLint cx, GLint cy)
{   
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_POINTS);
		glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel( x + h,  y + k);
	draw_pixel(-x + h,  y + k);
	draw_pixel( x + h, -y + k);
	draw_pixel(-x + h, -y + k);

	draw_pixel( y + h,  x + k);
	draw_pixel(-y + h,  x + k);
	draw_pixel( y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)  
{
	GLint d = 1 - r, x = 0, y = r;
	while(y > x)
	{
		plotpixels(h, k, x, y);
		if (d < 0) 
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

void draw_cylinder()
{
	GLint xc = 100, yc = 100, r = 50;
	GLint i, n = 50;
	for (i = 0; i < n; i += 3)
	{
		draw_circle(xc, yc + i, r);
	}
}

void draw_rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(2.0);

	glBegin(GL_LINE_LOOP);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
		glVertex2i(x4, y4);
	glEnd();
}
void draw_parallelepiped()
{
	int x1 = 200, y1 = 100;
	int x2 = 300, y2 = 100;
	int x3 = 300, y3 = 175;
	int x4 = 200, y4 = 175;
	
	GLint i, n = 40;
	for (i = 0; i < n; i += 2)
	{
		draw_rectangle( x1 + i, y1 + i, 
						x2 + i, y2 + i, 
						x3 + i, y3 + i, 
						x4 + i, y4 + i
					);
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);

	draw_cylinder();
	draw_parallelepiped();

	glFlush(); 
}

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);	
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rectangular Mesh");
	glutFullScreen();  
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;	
}
