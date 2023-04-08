/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <ctime>
#include <cmath>

const double RADIUS = 0.95;
const double HOUR_HAND_LENGTH = 0.4;
const double MINUTE_HAND_LENGTH = 0.6;
const double SECOND_HAND_LENGTH = 0.7;
const double NUMBER_RADIUS = RADIUS - 0.15;
const double NUMBER_SIZE = 0.05;
double hour = 0;
double minute = 0;
double second = 0;

void drawNumber(double x, double y, double size, int num) {
    glBegin(GL_LINES);
        switch (num) {
            case 1:
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                break;

            case 2:
                glVertex2d(x, y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x, y -size);
                glVertex2d(x, y -2 * size);
                glVertex2d(x, y -2 * size);
                glVertex2d(x + size, y -2 * size);
                break;

            case 3:
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x , y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x , y -2 * size);
                glVertex2d(x + size, y -2 * size);
                break;

            case 4:
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                glVertex2d(x , y -size);
                glVertex2d(x + size, y -size);
                break;

            case 5:
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                glVertex2d(x , y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x , y -2 * size);
                glVertex2d(x + size, y -2 * size);
                break;

            case 6:
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                glVertex2d(x , y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x , y -2 * size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x, y -size);
                glVertex2d(x, y -2 * size);
                break;

            case 7:
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                break;

            case 8:
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x , y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x, y -size);
                glVertex2d(x, y -2 * size);
                glVertex2d(x , y -2 * size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                break;

            case 9:
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x , y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x , y -2 * size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                break;

            case 0:
                glVertex2d(x , y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y);
                glVertex2d(x + size, y -size);
                glVertex2d(x, y -size);
                glVertex2d(x, y -2 * size);
                glVertex2d(x , y -2 * size);
                glVertex2d(x + size, y -2 * size);
                glVertex2d(x, y);
                glVertex2d(x, y -size);
                glVertex2d(x + size, y -size);
                glVertex2d(x + size, y -2 * size);
                break;
        }
    glEnd();
}

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

    for (int i = 1; i <= 12; i++) { //숫자 그리기
        double angle = -(i * 30) * M_PI / 180;

        if (i < 10) {
            drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2), NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, i);
        } else {
            if (i == 10) {
                drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2) - 2 * NUMBER_SIZE, NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, 1);
                drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2), NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, 0);
            } else if (i == 11) {
                drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2) - NUMBER_SIZE, NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, 1);
                drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2), NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, 1);
            } else {
                drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2) - 2 * NUMBER_SIZE, NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, 1);
                drawNumber(NUMBER_RADIUS * cos(angle + M_PI / 2), NUMBER_RADIUS * sin(angle + M_PI / 2) + NUMBER_SIZE, NUMBER_SIZE, 2);
            }
        }
    }


    time_t cur = time(nullptr);
    struct tm* time = localtime(&cur);
    hour = -time->tm_hour;  //시간이 지날 수록 각도가 줄어들어야 하므로 음수화
    minute = -time->tm_min;
    second = -time->tm_sec;
    double secondAngle = second * 6 * M_PI / 180;    //60초당 360도를 돌아야하므로 1초당 6도 배정.
    double minuteAngle = minute * 6 * M_PI / 180 + secondAngle / 60; //마찬가지로 1분당 6도 배정. 이후 6도의 범위 내에서 초의 영향을 360/6만큼 받는다.
    double hourAngle = hour * 30 * M_PI / 180 + minuteAngle / 12; //12시당 360도를 돌아야하므로 1시당 30도 배정. 이후 30도의 범위 내에서 분의 영향을 360/30만큼 받는다.

    //시, 분, 초 모두 12시를 기준으로 해야한다. 각도를 그냥 사용하면 0(초/분/시)일 때 3시 방향을 가리키게 되므로(cos이 1, sin이 0)
    //삼각 함수를 -PI / 2만큼 평행이동하여 0(초/분/시)일 때 12시 방향을 가리키게 만들어준다.
    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(HOUR_HAND_LENGTH * cos(hourAngle + M_PI / 2), HOUR_HAND_LENGTH * sin(hourAngle + M_PI / 2));
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(MINUTE_HAND_LENGTH * cos(minuteAngle + M_PI / 2), MINUTE_HAND_LENGTH * sin(minuteAngle + M_PI / 2));
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(SECOND_HAND_LENGTH * cos(secondAngle + M_PI / 2), SECOND_HAND_LENGTH * sin(secondAngle + M_PI / 2));
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
    glutCreateWindow("과제1 아날로그 시계");

    glutDisplayFunc(MyDisplay);
    glutTimerFunc(1000, MyTimer, 1);
    glutMainLoop();

    return 0;
}*/
