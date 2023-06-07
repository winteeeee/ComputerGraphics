#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat light0pos[] = { 0.0, 0.0, 2.0, 1.0 }; // 0번광원위치
GLfloat light0ambient[] = { 1.0, 0.0, 0.0, 1.0 }; // 0번광원특성 - 주변광
GLfloat light0diffuse[] = { 0.0, 1.0, 0.0, 1.0 }; // - 확산광
GLfloat light0specular[] = { 0.0, 0.0, 1.0, 1.0 }; // - 경면광

GLfloat light1position[] = { 1.0, 1.0, 1.0, 1.0 }; // 1번광원위치
GLfloat light1ambient[] = { 1.0, 0.0, 0.0, 1.0 }; // 1번광원특성 - 주변광
GLfloat light1diffuse[] = { 0.0, 0.0, 1.0, 1.0 }; // - 확산광
GLfloat light1specular[] = { 0.0, 1.0, 0.0, 1.0 }; // - 경면광
GLfloat light1direction[] = { -0.5, -1.0, -1.0 }; // 1번광원방향
GLfloat spotangle1[] = { 20.0 }; // 1번광원각도

GLfloat material0ambient[] = { 0.3, 0.3, 0.3, 1.0 }; // 물체특성 - 주변광
GLfloat material0diffuse[] = { 0.6, 0.6, 0.0, 1.0 }; // - 확산광
GLfloat material0specular[] = { 0.0, 0.0, 1.0, 1.0 }; // - 경면광
GLfloat material0shininess[] = { 30.0 };

void MyLightInit() {
    glShadeModel(GL_SMOOTH); // 구로셰이딩 (GL_SMOOTH)
    glEnable(GL_DEPTH_TEST); // 깊이버퍼활성화
    glEnable(GL_LIGHTING); // 조명활성화
    glEnable(GL_LIGHT0); // 0번광원활성화

    glLightfv(GL_LIGHT0, GL_AMBIENT,light0ambient); // 0번광원특성할당
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0specular);

    glEnable(GL_LIGHT1); // 1번광원활성화
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1ambient); // 1번광원특성할당
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1specular);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, material0diffuse); // 물체특성할당
    glMaterialfv(GL_FRONT, GL_SPECULAR, material0specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material0ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material0shininess);
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0); // 시점변환
    glTranslatef(0.3, 0.3, 0.0); // 모델변환

    glLightfv(GL_LIGHT0, GL_POSITION, light0pos); // 위치성광원

    glLightfv(GL_LIGHT1, GL_POSITION, light1position); // 스포트라이트
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1direction); // 방향
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, spotangle1); // 각도
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0); // 코사인승수

    glutSolidTorus(0.3, 0.6, 120, 360); // 원환체정의

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");
    glClearColor(0.35f, 0.53f, 0.7f, 1.0f);

// Projection Setting
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -3.0, 3.0);

    MyLightInit();

    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}