/*
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <fstream>
using namespace std;
GLfloat xValue = 0.0f;
GLfloat yValue = 0.0f;
GLfloat zValue = 0.0f;
unsigned int MyTextureObject[2];
string fileName1 = "C:\\Users\\Han SeongMin\\Desktop\\cat.bmp";
string fileName2 = "C:\\Users\\Han SeongMin\\Desktop\\fortlee.bmp";

// Struct of bitmap file
struct BitMapFile {
    int sizeX;
    int sizeY;
    unsigned char *data;
};

// Read a bitmap file (무압축 24비트 컬러만 지원)
BitMapFile *getBMPData(string filename)
{
    BitMapFile *bmp = new BitMapFile;
    unsigned int size, offset, headerSize;
// Read filename
    ifstream infile(filename.c_str(), ios::binary);
// Get the starting point of the image data
    infile.seekg(10);
    infile.read((char *)&offset, 4);
// Get the header size
    infile.read((char *)&headerSize, 4);
// Get width and height values
    infile.seekg(18);
    infile.read((char *)&bmp->sizeX, 4);
    infile.read((char *)&bmp->sizeY, 4);
// Allocate buffer
    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];
// Read bitmap data
    infile.seekg(offset);
    infile.read((char *)bmp->data, size);
// Reverse color from bgr to rgb.
    int tmp;
    for (int i = 0; i < size; i += 3)
    {
        tmp = bmp->data[i]; bmp->data[i] = bmp->data[i + 2]; bmp->data[i + 2] = tmp;
    }
    return bmp;
}

// 파일을 읽어서 텍스쳐로 변환
void LoadGLTextures(string szFilePath1, string szFilePath2)
{
    glGenTextures(2, &MyTextureObject[0]); // 텍스쳐 생성 (2개 texture)
// Local storage for bmp image
    BitMapFile *image = NULL;
// Load the texture image
    image = getBMPData(szFilePath1);
// Activate texture index MyTextureObject[0]
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
// Specify an image as the texture to be bound
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->sizeX,
                 image->sizeY,
                 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
// Set texture parameters for wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// Set texture parameters for Minification and Magnification
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// Delete allocated memory
    delete[] image->data;
    delete image;
// Load the texture image
    image = getBMPData(szFilePath2);
// Activate texture index MyTextureObject[1]
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[1]);
// Specify an image as the texture to be bound
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->sizeX,
                 image->sizeY,
                 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
// Set texture parameters for wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// Set texture parameters for Minification and Magnification
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// Delete allocated memory
    delete[] image->data;
    delete image;
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xValue, 1.0f, 0.0f, 0.0f);
    glRotatef(yValue, 0.0f, 1.0f, 0.0f);
    glRotatef(zValue, 0.0f, 0.0f, 1.0f);
// 1번 Texture와 연결
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); //앞면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
*/
/*
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); //앞면 repeat or clamp
glTexCoord2f(3.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
glTexCoord2f(3.0f, 3.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 3.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
*//*

    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // 뒷면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // 윗면
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
// 2번 Texture와 연결
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[1]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // 아랫면
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f); // 우측면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // 좌측면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    glFlush();
}

void MyTimer(int Value) {
    xValue += 0.9f;
    yValue += 0.8f;
    zValue += 1.0f;
    glutPostRedisplay();
    glutTimerFunc(50, MyTimer, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("OpenGL Example");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    LoadGLTextures(fileName1, fileName2);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(50, MyTimer, 1);
    glutMainLoop();
}
*/
