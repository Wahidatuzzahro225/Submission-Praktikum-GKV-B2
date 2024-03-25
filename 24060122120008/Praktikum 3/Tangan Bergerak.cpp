////  TugasPraktikum3_TanganBergerak..cpp
////  Pertemuan 3
///
////  Nama    : Wahidatuzzahro Febria Fithrurrahmah
////  NIM       : 24060122120008
////  Lab        : B2


#include <GLUT/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;
static int palmRotation = 0;
static int finger1 = 0, finger2 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Gambar telapak tangan
    glTranslatef(1.2, 0.0, 0.0);
    glRotatef((GLfloat)palmRotation, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.5, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Gambar jari-jari
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
    glTranslatef(-0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
        elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'p':
        palmRotation = (palmRotation + 5) % 360; // Rotasi telapak tangan
        glutPostRedisplay();
        break;
    case 'P':
        palmRotation = (palmRotation - 5) % 360; // Rotasi telapak tangan
        glutPostRedisplay();
        break;
    case '1':
        finger1 = (finger1 + 5) % 360;
        glutPostRedisplay();
        break;
    case '!':
        finger1 = (finger1 - 5) % 360;
        glutPostRedisplay();
        break;
    case '2':
        finger2 = (finger2 + 5) % 360;
        glutPostRedisplay();
        break;
    case '@':
        finger2 = (finger2 - 5) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
