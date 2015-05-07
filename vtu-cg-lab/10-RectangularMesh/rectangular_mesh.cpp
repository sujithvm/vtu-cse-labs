#include <GL/glut.h>

#define X_MAX 50
#define Y_MAX 50
#define dx 5
#define dy 5

GLfloat x[X_MAX] = {0.0};
GLfloat y[X_MAX] = {0.0};
GLfloat x_start = 50, y_start = 50;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < X_MAX; i++) x[i] = x_start + i * dx;
	for (int i = 0; i < Y_MAX; i++) y[i] = y_start + i * dy;

	for (int i = 0; i < X_MAX - 1; i++)
	{
		for (int j = 0; j < Y_MAX - 1; j++)
		{
			glBegin(GL_LINE_LOOP);
				glVertex2f(x[i], y[j]);
                glVertex2f(x[i], y[j + 1]);
                glVertex2f(x[i + 1], y[j + 1]);
                glVertex2f(x[i + 1], y[j]);			
			glEnd();
		}
	}

	glFlush();
}

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);	
	glutPostRedisplay();
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
