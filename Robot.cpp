/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

double time = 0;
GLfloat headAngle = 0.0f;
GLfloat armAngleL = 0.0f;
GLfloat armAngleR = 0.0f;
GLfloat legAngleL = 0.0f;
GLfloat legAngleR = 0.0f;
GLfloat globalRot = 0.0f;

void drawLeftArm();
void drawRightArm();
void drawLeftLeg();
void drawRightLeg();
void drawHead();
void drawBody();
void MyDisplay();
void timeFunction(int);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, -15.0, 15.0, -20.0, 20.0);
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(22, timeFunction, 1);
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

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(9.0f, 0.0f, 9.0f);
    glVertex3f(9.0f, 0.0f, -9.0f);
    glVertex3f(-9.0f, 0.0f, -9.0f);
    glVertex3f(-9.0f, 0.0f, 9.0f);
    glEnd();
    glPopMatrix();

    glTranslatef(0, 5, 0);
// Axis
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();

    //모델 전체 회전(Y축)
    glRotatef(globalRot, 0, 1, 0);

    //Robot의 이동
    glTranslatef(5, 0, 0);


// 몸통
    drawBody();
// 머리
    drawHead();
// 팔
    drawLeftArm();
    drawRightArm();
// 다리
    drawLeftLeg();
    drawRightLeg();
    glFlush();
}

void drawHead()
{
    glPushMatrix();
    glRotated(headAngle, 0, 1, 0);
    glTranslatef(0, 2.8, 0);
    glRotatef(270, 0, 1, 0);
    glColor3f(1, 0, 0);
    glutSolidTeapot(0.8);
    glPopMatrix();
}
void drawBody()
{
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScalef(2, 2, 1);
    glColor3f(0, 0, 1);
    glutSolidCube(1);
    glPopMatrix();
}
void drawLeftArm()
{
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotated(sin(armAngleL * M_PI / 180) * 30 + 180, 1, 0, 0);
    glTranslatef(-1.5, 1, 0);
    glScalef(0.5, 2, 1);
    glColor3f(1, 1, 0);
    glutSolidCube(1);

    glScalef(2, 0.5, 1);
    glTranslatef(0, 1.5, 0);
    glColor3f(0, 0, 0);
    glScalef(0.4, 0.4, 0.4);
    glutSolidSphere(0.8, 18, 18);
    glPopMatrix();
}
void drawRightArm()
{
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotated(sin(armAngleR * M_PI / 180) * 30 + 180, 1, 0, 0);
    glTranslatef(1.5, 1, 0);
    glScalef(0.5, 2, 1);
    glColor3f(0, 1, 0);
    glutSolidCube(1);

    glScalef(2, 0.5, 1);
    glTranslatef(0, 1.5, 0);
    glColor3f(0, 0, 0);
    glScalef(0.4, 0.4, 0.4);
    glutSolidSphere(0.8, 18, 18);
    glPopMatrix();
}
void drawLeftLeg()
{
    glPushMatrix();
    glRotated(sin(legAngleL * M_PI / 180) * 30, 1, 0, 0);
    glTranslatef(-0.5, -2.5, 0);
    glScalef(0.6, 4, 1);
    glColor3f(0, 1, 1);
    glutSolidCube(1);

    glScalef(1/0.6, 0.25, 1);
    glTranslatef(0, -2.5, 0.25);
    glColor3f(0, 0, 0);
    glScalef(0.5, 0.5, 1.5);
    glutSolidCube(1);
    glPopMatrix();
}
void drawRightLeg()
{
    glPushMatrix();
    glRotated(sin(legAngleR * M_PI / 180) * 30, 1, 0, 0);
    glTranslatef(0.5, -2.5, 0);
    glScalef(0.6, 4, 1);
    glColor3f(0, 1, 1);
    glutSolidCube(1);

    glScalef(1/0.6, 0.25, 1);
    glTranslatef(0, -2.5, 0.25);
    glColor3f(0, 0, 0);
    glScalef(0.5, 0.5, 1.5);
    glutSolidCube(1);
    glPopMatrix();
}

void timeFunction(int val) {
    time += 0.1;

    headAngle += 5;
    if (headAngle >= 360) {
        headAngle -= 360;
    }

    armAngleL += 5;
    armAngleR -= 5;
    legAngleR += 5;
    legAngleL -= 5;
    globalRot -= 1;

    glutPostRedisplay();
    glutTimerFunc(22, timeFunction, 1);
}*/
