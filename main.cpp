/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

double b, c, t1, t2, x, y;
double a = 1;
double d = 1;
double scale = 1;
double theta = 0;

void transform(double *X, double *Y) {
    double ix = *X;
    double iy = *Y;

    *X = a * ix + b * iy + t1;
    *Y = c * ix + d * iy + t2;
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);

    x = -0.1; y = -0.1;
    transform(&x, &y);
    glVertex2d(x, y);

    x = -0.1; y = 0.1;
    transform(&x, &y);
    glVertex2d(x, y);

    x = 0.1; y = 0.1;
    transform(&x, &y);
    glVertex2d(x, y);

    x = 0.1; y = -0.1;
    transform(&x, &y);
    glVertex2d(x, y);
    glEnd();
    glFlush();
}

void update() {
    double angle = theta * M_PI / 180;
    a = scale * cos(angle);
    b = -scale * sin(angle);
    c = -b;
    d = a;
}

void MyKeyboard(unsigned char key, int X, int Y) {
    if (key == 's') {
        a += 0.1;
        d += 0.1;
    } else if (key == 'S') {
        a -= 0.1;
        d -= 0.1;
    } else if (key == 't') {
        theta += 1;
        update();
    } else if (key == 'T') {
        theta -= 1;
        update();
    } else if (key == 'r') {

    } else if (key == 'R') {

    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    a = 1;
    d = 1;
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");

    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
*/
