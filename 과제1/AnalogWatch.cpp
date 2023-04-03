#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h> //현재 시각 구하기 위함
#include <math.h> //삼각함수
// 현재 시간을 각도로 변환 -> 그 각도일 때 좌표값 계산
//(rcos세타, rsin세타)
//시계의 1, 2, 3, 4 등의 숫자를 360도에 매핑

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Example");
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}