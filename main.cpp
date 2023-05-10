#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

int WIDTH = 300;
int HEIGHT = 300;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 0, 0);
    glViewport(0, 0, WIDTH / 2, HEIGHT / 2);
    glutWireTeapot(0.5);

    glLoadIdentity();
    glColor3f(0, 1, 0);
    gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);
    glViewport(WIDTH / 2, 0, WIDTH / 2, HEIGHT / 2);
    glutWireTeapot(0.5);

    glLoadIdentity();
    glColor3f(0, 0, 1);
    gluLookAt(0, 1, 0, 0, 0, 0, 1, 0, 0);
    glViewport(0, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
    glutWireTeapot(0.5);

    glLoadIdentity();
    glColor3f(1, 0, 1);
    gluLookAt(0.5, 0, 0.5, 0, 0, 0, 0, 1, 0);
    glViewport(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
    glutWireTeapot(0.5);
    glFlush();
}

void MyReshape(int width, int height) {
    printf("Width %d, Height %d\n", width, height);
    WIDTH = width;
    HEIGHT = height;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Example");

    // Projection Setting
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 30.0);

    // Resize 함수 기능 정의
    glutReshapeFunc(MyReshape);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}