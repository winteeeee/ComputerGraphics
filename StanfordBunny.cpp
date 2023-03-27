/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"

void MyDisplay() {
    const int FACE_INDICES_LENGTH = 16301;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    for (int i = 0; i < FACE_INDICES_LENGTH; i++) {
        int x = face_indicies[i][0];
        int y = face_indicies[i][1];
        int z = face_indicies[i][2];

        glVertex3fv(vertices[x]);
        glVertex3fv(vertices[y]);
        glVertex3fv(vertices[z]);
        glVertex3fv(vertices[y]);
        glVertex3fv(vertices[z]);
        glVertex3fv(vertices[x]);
    }
    glEnd();
    glFlush(); }
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Example");
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0; }*/
