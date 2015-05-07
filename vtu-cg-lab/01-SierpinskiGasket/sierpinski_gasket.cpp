#include <iostream>
#include <GL/glut.h>

using namespace std;

typedef float point[3];

point v[] = {
				{0.0, 0.0, 1.0},
				{0.0, 0.942809, -0.333333},
				{-0.816497, -0.471405, -0.333333},
				{0.816497, -0.471405, -0.333333}
			};

int N = 0;

void triangle(point a, point b, point c)
{
	glBegin(GL_POLYGON);
		glNormal3fv(a);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();
}

void divide_triangle(point a, point b, point c, int m)
{
	point v1, v2, v3;
	if (m > 0)
	{
		for (int i = 0; i < 3; i++) 
		{
			v1[i] = (a[i] + b[i]) / 2;
			v2[i] = (a[i] + c[i]) / 2;
			v3[i] = (b[i] + c[i]) / 2;
		}
		divide_triangle(a, v1, v2, m - 1);
		divide_triangle(c, v2, v3, m - 1);
		divide_triangle(b, v3, v1, m - 1);
	}
	else
	{
		triangle(a, b, c);
	}
}

void tetrahedron(int m)
{
	glColor3f(1.0, 0.0, 0.0);
	divide_triangle(v[0], v[1], v[2], m);

	glColor3f(0.0, 1.0, 0.0);
	divide_triangle(v[3], v[2], v[1], m);

	glColor3f(0.0, 0.0, 1.0);
	divide_triangle(v[0], v[3], v[1], m);
	
	glColor3f(0.0, 0.0, 0.0);
	divide_triangle(v[0], v[2], v[3], m);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();

	tetrahedron(N);

	glFlush(); 
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);  
	else
		glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	cout << "Enter number of recursive steps " << endl;
	cin >> N;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinski Gasket");
	glutFullScreen();  
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return 0;	
}
