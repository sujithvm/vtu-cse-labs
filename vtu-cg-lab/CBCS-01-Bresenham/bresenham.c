#include <stdio.h>
#include <GL/glut.h>

int x0, y0, xn, yn;

void draw_pixel(int x, int y) {

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

}

void draw_line() {

    int dx, dy;
    int i, e;
    int incx, incy;
    int inc1, inc2;
    int x, y;
    dx = xn - x0;
    dy = yn - y0;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (xn < x0)
        incx = -1;
    incy = 1;
    if (yn < y0)
        incy = -1;
    x = x0;
    y = y0;
    if (dx > dy) {

        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++) {

            if (e >= 0) {
                y += incy;
                e += inc1;
            }
            else {
                e += inc2;
            }

            x += incx;
            draw_pixel(x, y);
        }

    } else {

        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;

        for (i = 0; i < dy; i++) {
            if (e >= 0) {

                x += incx;
                e += inc1;
            }
            else {
                e += inc2;
            }
            y += incy;
            draw_pixel(x, y);
        }
        
    }

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.33, 0.47);
    draw_line();
    glFlush();

}

void myInit() {

    glClearColor(1, 1, 1, 1);
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 550.0, -500.0, 550.0);

}

void main(int argc, char **argv) {

    printf("Enter point x0 : ");
    scanf("%d", &x0);
    printf("Enter point y0 : ");
    scanf("%d", &y0);
    printf("Enter point xn : ");
    scanf("%d", &xn);
    printf("Enter point yn : ");
    scanf("%d", &yn);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Line");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}