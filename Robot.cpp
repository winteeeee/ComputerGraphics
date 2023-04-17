#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
void drawLeftArm();
void drawRightArm();
void drawLeftLeg();
void drawRightLeg();
void drawHead();
void drawBody();
void MyDisplay();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 20.0);
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
// Test Enable or Disable
// 카메라 셋팅(시점조절관련 간단히 타이핑해볼것).
    gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
// Axis
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();
// 몸통
    glPushMatrix();
    drawBody();
// 머리
    glPopMatrix();
    glPushMatrix();
    drawHead();
// 팔
    glPopMatrix();
    glPushMatrix();
    drawLeftArm();
    glPopMatrix();
    glPushMatrix();
    drawRightArm();
// 다리
    glPopMatrix();
    glPushMatrix();
    drawLeftLeg();
    glPopMatrix();
    glPushMatrix();
    drawRightLeg();
    glFlush();
}

void drawHead()
{
    glTranslatef(0, 2.8, 0);
    glRotatef(270, 0, 1, 0);
    glColor3f(1, 0, 0);
    glutSolidTeapot(0.8);
}
void drawBody()
{
    glTranslatef(0, 1, 0);
    glScalef(2, 2, 1);
    glColor3f(0, 0, 1);
    glutSolidCube(1);
}
void drawLeftArm()
{
    glTranslatef(-1.5, 1, 0);
    glScalef(0.5, 2, 1);
    glColor3f(1, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5, -0.4, 0);
    glColor3f(0, 0, 0);
    glScalef(0.4, 0.4, 0.4);
    glutSolidSphere(0.8, 18, 18);
}
void drawRightArm()
{
    glTranslatef(1.5, 1, 0);
    glScalef(0.5, 2, 1);
    glColor3f(0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5, -0.4, 0);
    glColor3f(0, 0, 0);
    glScalef(0.4, 0.4, 0.4);
    glutSolidSphere(0.8, 18, 18);
}
void drawLeftLeg()
{
    glTranslatef(-0.5, -2, 0);
    glScalef(0.6, 4, 1);
    glColor3f(0, 1, 1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.5, -4.5, 0.25);
    glColor3f(0, 0, 0);
    glScalef(0.5, 0.5, 1.5);
    glutSolidCube(1);
}
void drawRightLeg()
{
    glTranslatef(0.5, -2, 0);
    glScalef(0.6, 4, 1);
    glColor3f(0, 1, 1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, -4.5, 0.25);
    glColor3f(0, 0, 0);
    glScalef(0.5, 0.5, 1.5);
    glutSolidCube(1);
}