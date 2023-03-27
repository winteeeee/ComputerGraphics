#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"
int xRotate = 0;
void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity(); // 현재 변환 행렬 초기화
    glRotatef(xRotate, 1.0, 0.0, 0.0); // X축 회전 (차후 설명)
// BunnyModel 그리는 코드
    unsigned int i;
    for(i=0; i<(sizeof(face_indicies)/sizeof(face_indicies[0])); i++)
    {
        int vi;
        glBegin(GL_LINES);
        vi=face_indicies[i][0]; glVertex3fv(vertices[vi]);
        vi=face_indicies[i][1]; glVertex3fv(vertices[vi]);
        vi=face_indicies[i][1]; glVertex3fv(vertices[vi]);
        vi=face_indicies[i][2]; glVertex3fv(vertices[vi]);
        vi=face_indicies[i][2]; glVertex3fv(vertices[vi]);
        vi=face_indicies[i][0]; glVertex3fv(vertices[vi]);
        glEnd ();
    }
    glFlush();
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
    switch (KeyPressed){
        case 'Q':
            exit(0); break;
        case 'q':
            exit(0); break;
        case 'X':
            xRotate -= 1;
            break;
        case 'x':
            xRotate += 1;
            break;
    }
    glutPostRedisplay(); // 화면 다시 그리기
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Example");
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}