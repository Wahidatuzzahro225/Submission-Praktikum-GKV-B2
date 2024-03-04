////
//  TugasPraktikum2_Mobil2D.cpp
//  Pertemuan 2
//
//  Created by wahidatuzzahro febria fithrurrahmah on 04/03/24.
//  Inspired by https://www.youtube.com/@muhamadazrinogustalika1899
//  Nama    : Wahidatuzzahro Febria Fithrurrahmah
//  NIM     : 24060122120008
//  Lab     : B2
//  Tanggal : Senin, 26 Februari 2024



#include <GLUT/glut.h>
#include <math.h>

//lingkarang
const double PI = 3.142857143;
int i,radius,jumlah_titik,x_tengah,y_tengah;

//auto
bool atas = true;
int gerak = 0;


void car()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef( gerak, 0,0);
    
    //atap mobil
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.0,1.0);
    glVertex2f(1.5,0.0);
    glVertex2f(1.5,-1.0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(-0.7,1.0);
    glEnd();
    glFlush();
    
    //depan mobil
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5,0.0);
    glVertex2f(2.75,0.0);
    glVertex2f(2.75,-1.0);
    glVertex2f(1.5,-1.0);
    glEnd();
    glFlush();
    
    
    //belakang mobil
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.5,-1.0);
    glVertex2f(-1.5,0.0);
    glVertex2f(-1.0,0.0);
    glEnd();
    glFlush();
    
    
    //ban depan
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    
    radius = 40;
    jumlah_titik = 60;
    x_tengah = 190;
    y_tengah = -90;
    
    for (i=0;i<=360;i++)
    {
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
        glVertex2f(x/100,y/100);
    }
    glEnd();
    glFlush();
    
    //ban belakang
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    
    radius = 40;
    jumlah_titik = 60;
    x_tengah = -90;
    y_tengah = -90;
    
    for (i=0;i<=360;i++)
    {
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
        glVertex2f(x/100,y/100);
    }
    
    glEnd();
    glFlush();
    glPopMatrix();
    
    
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize (640, 480);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat");
    glutDisplayFunc (car);
    gluOrtho2D(-10.0, 20.0, -10.0, 20.0);
    glClearColor (1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
