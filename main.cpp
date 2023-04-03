/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"

GLuint g_stanfordBunnyID = -1;

GLint GenerateCallList() {
    GLint lid = glGenLists(1);

    glNewList(lid, GL_COMPILE);
    glColor3f(1.0f, 0.0f, 0.0f);

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
    glEndList();

    return lid;
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);

    glCallList(g_stanfordBunnyID);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);

    g_stanfordBunnyID = GenerateCallList();

    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}*/
