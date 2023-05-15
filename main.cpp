#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat pA[3] = { 0.2, 0.2, +0.2 };
GLfloat pB[3] = { -0.2, 0.2, +0.2 };
GLfloat pC[3] = { -0.2, -0.2, +0.2 };
GLfloat pD[3] = { 0.2, -0.2, +0.2 };
GLfloat pE[3] = { 0.2, 0.2, -0.2 };
GLfloat pF[3] = { -0.2, 0.2, -0.2 };
GLfloat pG[3] = { -0.2, -0.2, -0.2 };
GLfloat pH[3] = { 0.2, -0.2, -0.2 };

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
// Axis
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();

    // 전면
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3fv(pA);
    glVertex3fv(pB);
    glVertex3fv(pC);
    glVertex3fv(pD);
    glEnd();

// 후면 - Counter Clockwise
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3fv(pF);
    glVertex3fv(pE);
    glVertex3fv(pH);
    glVertex3fv(pG);
    glEnd();
    // 후면 - Clockwise
    /* glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); // Green
    glEnd(); */
    // 상판
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3fv(pF);
    glVertex3fv(pB);
    glVertex3fv(pA);
    glVertex3fv(pE);
    glEnd();

    //좌
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3fv(pA);
    glVertex3fv(pD);
    glVertex3fv(pH);
    glVertex3fv(pE);
    glEnd();

    //우
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3fv(pB);
    glVertex3fv(pF);
    glVertex3fv(pG);
    glVertex3fv(pC);
    glEnd();

    //하
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3fv(pG);
    glVertex3fv(pH);
    glVertex3fv(pD);
    glVertex3fv(pC);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");
// Projection Setting
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     //glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 30.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0.7, 30.0); //부분절단(후면표시)
 //glEnable(GL_CULL_FACE);
// glFrontFace(GL_CCW); // Counter Clockwise
// glFrontFace(GL_CW); // Clockwise
// Culling
 //glCullFace(GL_FRONT); // Frontface (전면제거)
 //glCullFace(GL_BACK); // Backface (후면제거)
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}