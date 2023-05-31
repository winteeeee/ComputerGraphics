#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"
#include <stdio.h>

GLuint g_stanfordBunnyID = -1;

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

GLint clickDown = 0;
GLint fixX = 0;
GLint fixY = 0;

GLint GenerateCallList()
{
    GLint lid = glGenLists(1);

    glNewList(lid, GL_COMPILE);
    glColor3f(1.0f, 1.0f, 1.0f);

    unsigned int i;
    for (i = 0; i<(sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
    {
        int vi;
        glBegin(GL_POLYGON);
        vi = face_indicies[i][0];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][1];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][2];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        glEnd();
    }
    glEndList();

    return lid;
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    // glScalef( 2.0f, 2.0f, 2.0f );

    glRotatef(xValue, 1.0, 0.0, 0.0);
    glRotatef(yValue, 0.0, 1.0, 0.0);
    glRotatef(zValue, 0.0, 0.0, 1.0);

    // Axis
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();

    // display Call Lists
    glCallList(g_stanfordBunnyID);
    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
    switch (KeyPressed){
        case 'X':
        case 'x':    xValue += 1;
            if (xValue > 360) xValue -= 360;
            break;
        case 'Y':
        case 'y':    yValue += 1;
            if (yValue > 360) yValue -= 360;
            break;
        case 'Z':
        case 'z':    zValue += 1;
            if (zValue > 360) zValue -= 360;
            break;
        case 'Q':
        case 'q':
            exit(0); break;
        case 32: // SPACE key
            xValue = 0;
            yValue = 0;
            zValue = 0;
            break;
        case 27: // ESC key
            exit(0);
            break;
        case 3: // CTRL + C
            exit(0);
            break;
    }
    printf("%d\n", KeyPressed);
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y)
{
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
    {
        fixX = X;
        fixY = Y;
        clickDown = 1;
    }

    if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP)
    {
        clickDown = 0;
    }
}

void MyMouseMove(GLint X, GLint Y)
{
    if (clickDown == 1)
    {
        xValue = xValue + (fixX - X);
        yValue = yValue + (fixY - Y);
        fixX = X;
        fixY = Y;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");

    g_stanfordBunnyID = GenerateCallList();

    glutDisplayFunc(MyDisplay);

    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);

    glutMainLoop();
    return 0;
}
