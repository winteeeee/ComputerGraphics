/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;
void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // 시점 변경
    //gluLookAt(0, 0, 1,  0, 0, 0,  0, 1, 0);
    glRotatef(xValue, 1.0, 0.0, 0.0);
    glRotatef(yValue, 0.0, 1.0, 0.0);
    glRotatef(zValue, 0.0, 0.0, 1.0);

    glBegin(GL_LINES);
    glColor3f(1, 0, 0); // X
    glVertex3f(-1, 0, 0); glVertex3f(1, 0, 0);
    glColor3f(0, 1, 0); // Y
    glVertex3f(0, -1, 0); glVertex3f(0, 1, 0);
    glColor3f(0, 0, 1); // Z
    glVertex3f(0, 0, -1); glVertex3f(0, 0, 1);
    glEnd();

    glColor3f(1, 1, 0);
    glutWireTeapot(0.3);

    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
    switch (KeyPressed){
        case 'X':
        case 'x': xValue += 1;
            if (xValue > 360) xValue -= 360;
            break;
        case 'Y':
        case 'y': yValue += 1;
            if (yValue > 360) yValue -= 360;
            break;
        case 'Z':
        case 'z': zValue += 1;
            if (zValue > 360) zValue -= 360;
            break;
        case 'q': exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0); // 시점과 거리설정 -2.0~ 2.0
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}*/
