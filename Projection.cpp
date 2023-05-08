/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#include "BunnyModel.h"

GLuint g_stanfordBunnyID = -1;

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

GLint clickDown = 0;
GLint fixX = 0;
GLint fixY = 0;

GLint zDistance = -2; // increase & decrease + / -

GLint GenerateCallList()
{
    unsigned int i;
    GLint lid = glGenLists(1);
    glNewList(lid, GL_COMPILE);
    for (i = 0; i<(sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
    {
        int vi;
        glBegin(GL_LINES);
        vi = face_indicies[i][0];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][1];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][1];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][2];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][2];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        vi = face_indicies[i][0];
        glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
        glEnd();
    }
    glEndList();
    return lid;
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Projection Matrix Setting
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Orthogonal Proj.
    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);

    // Modeling Matrix Setting
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 0.0f, 0.0f);

    gluLookAt(0.0, 0.0, zDistance, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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
    glLineWidth(1);
    glColor3f(1.0f, 1.0f, 1.0f);
    glCallList(g_stanfordBunnyID);

    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
    switch (KeyPressed){
        case 'X':
        case 'x':
            xValue += 1;
            if (xValue > 360) xValue -= 360;
            break;
        case 'Y':
        case 'y':
            yValue += 1;
            if (yValue > 360) yValue -= 360;
            break;
        case 'Z':
        case 'z':
            zValue += 1;
            if (zValue > 360) zValue -= 360;
            break;
        case 'Q':
        case 'q': exit(0); break;
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
        case 43: // +
            zDistance += 1;
            printf("zDistance: %d\n", zDistance);
            break;
        case 95: // -
            zDistance -= 1;
            printf("zDistance: %d\n", zDistance);
            break;
    }
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y)
{
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN){
        fixX = X;
        fixY = Y;
        clickDown = 1;
    }
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP){
        clickDown = 0;
    }
}

void MyMouseMove(GLint X, GLint Y)
{
    if (clickDown == 1)
    {
        yValue = yValue + (fixX - X);
        xValue = xValue + (fixY - Y);
        fixX = X;
        fixY = Y;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");

    g_stanfordBunnyID = GenerateCallList();

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutMainLoop();

    return 0;
}
*/
