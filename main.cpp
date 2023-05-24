#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
// 위치 조정
GLfloat light_position[] = { 0, 0, 3, 0 }; // 1
// GLfloat light_position[] = { 3, 0, 0, 0 }; // 2
// GLfloat light_position[] = { 0, 3, 0, 0 }; // 3
// 조명 색상 조정
// GLfloat light_diffuse[] = { 1, 1, 1, 1 }; // 4
// GLfloat light_diffuse[] = { 1, 0, 0, 1 }; // 5
GLfloat light_diffuse[] = { 1, 1, 0, 1 }; // 6
void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutSolidTeapot(0.5);
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
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 30.0);
// Lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    //glShadeModel(GL_SMOOTH);
    glShadeModel(GL_FLAT);

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}