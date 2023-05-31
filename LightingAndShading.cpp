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

GLfloat light0_position[] = { 0, 0, 3, 0 };
GLfloat light0_diffuse[] = { 1, 1, 0, 1 };
GLfloat light0_ambient[] = { 1, 0, 0, 1 };
GLfloat light0_specular[] = { 0, 0, 1, 1 };


GLint GenerateCallList()
{
    GLint lid = glGenLists(1);

    glNewList(lid, GL_COMPILE);
    glColor3f(1.0f, 1.0f, 1.0f);

    unsigned int i;
    for (i = 0; i<(sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
    {
        int vi;
        int ni;
        glBegin(GL_POLYGON);

        ni = face_indicies[i][3];
        vi = face_indicies[i][0];
        glNormal3fv(normals[ni]);
        glVertex3fv(vertices[vi]);  //법석 벡터를 먼저 지정 해야함

        ni = face_indicies[i][4];
        vi = face_indicies[i][1];
        glNormal3fv(normals[ni]);
        glVertex3fv(vertices[vi]);

        ni = face_indicies[i][5];
        vi = face_indicies[i][2];
        glNormal3fv(normals[ni]);
        glVertex3fv(vertices[vi]);

        glEnd();
        //법석 벡터 지정하지 않으면 입체감이 살아나지 않음
    }
    glEndList();

    return lid;
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 6, 0, 0, 0, 0, 1, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
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

    // Light Position
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(light0_position[0], light0_position[1], light0_position[2]);
    glutSolidSphere(0.1, 36, 36);
    glPopMatrix();

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position); //0번 광원 위치

    // display Call Lists
    glEnable(GL_LIGHTING);
    glCallList(g_stanfordBunnyID);
    glDisable(GL_LIGHTING);
    //glutSolidTeapot(0.5);
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
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");

    g_stanfordBunnyID = GenerateCallList();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 30);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

    //glShadeModel(GL_SMOOTH);
    glShadeModel(GL_FLAT);

    glutDisplayFunc(MyDisplay);

    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);

    glutMainLoop();
    return 0;
}
