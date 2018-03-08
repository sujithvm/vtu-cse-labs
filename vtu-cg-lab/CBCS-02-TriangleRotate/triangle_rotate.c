#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

GLfloat triangle[3][3] = {
    {100.0, 175.0, 250.0}, 
    {100.0, 250.0, 100.0}, 
    {1.0, 1.0, 1.0}
};

GLfloat rotmat[3][3] = {{0}, {0}, {0}};
GLfloat result[3][3] = {{0}, {0}, {0}};
GLfloat h;
GLfloat k;
GLfloat theta;

void multiply() {
    int i, j, l;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++){
            result[i][j] = 0;
            for (l = 0; l < 3; l++)
                result[i][j] = result[i][j] + rotmat[i][l] * triangle[l][j];
        }
}

void rotate() {
    GLfloat m, n;
    m = -h * (cos(theta) - 1) + k * (sin(theta));
    n = -k * (cos(theta) - 1) - h * (sin(theta));

    rotmat[0][0] = cos(theta);
    rotmat[0][1] = -sin(theta);
    rotmat[0][2] = m;
    rotmat[1][0] = sin(theta);
    rotmat[1][1] = cos(theta);
    rotmat[1][2] = n;
    rotmat[2][0] = 0;
    rotmat[2][1] = 0;
    rotmat[2][2] = 1;
    multiply();
}

void drawtriangle() {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(triangle[0][0], triangle[1][0]);
    glVertex2f(triangle[0][1], triangle[1][1]);
    glVertex2f(triangle[0][2], triangle[1][2]);
    glEnd();
}

void drawrottriangle() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(result[0][0], result[1][0]);
    glVertex2f(result[0][1], result[1][1]);
    glVertex2f(result[0][2], result[1][2]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawtriangle();
    rotate();
    drawrottriangle();
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void main(int argc, char **argv) {
    printf("Enter the value of theta: ");
    scanf("%f", &theta);
    printf("Enter the fixed point: ");
    scanf("%f %f", &h, &k);
    theta = (theta * 3.1459) / 180;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotation");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}