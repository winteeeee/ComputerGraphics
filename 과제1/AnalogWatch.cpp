#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <ctime>
#include <cmath>

const double RADIUS = 0.9;
const double HOUR_HAND_LENGTH = 0.5;
const double MINUTE_HAND_LENGTH = 0.7;
const double SECOND_HAND_LENGTH = 0.8;
double hour = 0;
double minute = 0;
double second = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5.0);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_LOOP);  //원 그리기
        for (int i = 0; i < 360; i++) {
            double angle = i * M_PI / 180;
            glVertex2d(RADIUS * cos(angle), RADIUS * sin(angle));
        }
    glEnd();

    time_t cur = time(nullptr);
    struct tm* time = localtime(&cur);
    hour = -time->tm_hour;  //시간이 지날 수록 각도가 줄어들어야 하므로 음수화
    minute = -time->tm_min;
    second = -time->tm_sec;
    double secondAngle = (second + 15) * 6 * M_PI / 180;    //60초당 360도를 돌아야하므로 1초당 6도 배정.
    double minuteAngle = (minute + 15) * 6 * M_PI / 180 + secondAngle / 60; //마찬가지로 1분당 6도 배정. 이후 6도의 범위 내에서 초의 영향을 360/6만큼 받는다.
    double hourAngle = (hour + 3) * 30 * M_PI / 180 + minuteAngle / 12; //12시당 360도를 돌아야하므로 1시당 30도 배정. 이후 30도의 범위 내에서 분의 영향을 360/30만큼 받는다.

    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(HOUR_HAND_LENGTH * cos(hourAngle), HOUR_HAND_LENGTH * sin(hourAngle));
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(MINUTE_HAND_LENGTH * cos(minuteAngle), MINUTE_HAND_LENGTH * sin(minuteAngle));
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(SECOND_HAND_LENGTH * cos(secondAngle), SECOND_HAND_LENGTH * sin(secondAngle));
    glEnd();

    glFlush();
}

void MyTimer(int val) {
    glutPostRedisplay();
    glutTimerFunc(1000, MyTimer, 1);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL Example");

    glutDisplayFunc(MyDisplay);
    glutTimerFunc(1000, MyTimer, 1);
    glutMainLoop();

    return 0;
}