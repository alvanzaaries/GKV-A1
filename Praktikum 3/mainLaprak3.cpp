//Nama   : Al Vanza Aries Rahmatsyah
//NIM	 : 24060123140169


#include <GL/glut.h>

static int shoulder = 0, elbow = 0, palm = 0, jempol1 = 0, jempol2 = 0, telunjuk1 = 0, telunjuk2 = 0, telunjuk3 = 0, tengah1 = 0, 
tengah2 = 0, tengah3 = 0, manis1 = 0, manis2 = 0, manis3 = 0, kelingking1 = 0, kelingking2 = 0, kelingking3 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // elbow
    glTranslatef(-3.5, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(1.5, 1.0, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    // palm
    glTranslatef(0.7, 0.0, 0.0);
    glRotatef((GLfloat)palm, 1.0, 0.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 2.0, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
glPushMatrix();
    // jempol
    glTranslatef(-0.2, -1.2, 0.0);
    glRotatef((GLfloat)jempol1, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // jempol2
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)jempol2, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    // telunjuk1
    glTranslatef(0.9, -0.8, 0.0);
    glRotatef((GLfloat)telunjuk1, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // telunjuk2
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)telunjuk2, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    // telunjuk3
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)telunjuk3, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    // tengah1
    glTranslatef(0.95, -0.3, 0.0);
    glRotatef((GLfloat)tengah1, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.9, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // tengah2
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)tengah2, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.9, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    // tengah3
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)tengah3, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.9, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    // manis1
    glTranslatef(0.9, 0.2, 0.0);
    glRotatef((GLfloat)manis1, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // manis2
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)manis2, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    // manis3
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)manis3, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    // kelingking1
    glTranslatef(0.85, 0.8, 0.0);
    glRotatef((GLfloat)kelingking1, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.7, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // kelingking2
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)kelingking2, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.7, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    // kelingking3
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)kelingking3, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.7, 0.4, 0.5);
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
        case '1':
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case '2':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case '3':
            palm = (palm + 5) % 360;
            glutPostRedisplay();
            break;
        case '4':
            palm = (palm - 5) % 360;
            glutPostRedisplay();
            break;
        case 'q':
            jempol1 = (jempol1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Q':
            jempol1 = (jempol1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':
            jempol2 = (jempol2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'W':
            jempol2 = (jempol2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            telunjuk1 = (telunjuk1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            telunjuk1 = (telunjuk1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'r':
            telunjuk2 = (telunjuk2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'R':
            telunjuk2 = (telunjuk2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 't':
            telunjuk3 = (telunjuk3 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'T':
            telunjuk3 = (telunjuk3 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'y':
            tengah1 = (tengah1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            tengah1 = (tengah1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'u':
            tengah2 = (tengah2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'U':
            tengah2 = (tengah2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'i':
            tengah3 = (tengah3 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'I':
            tengah3 = (tengah3 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'o':
            manis1 = (manis1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'O':
            manis1 = (manis1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'p':
            manis2 = (manis2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'P':
            manis2 = (manis2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'a':
            manis3 = (manis3 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'A':
            manis3 = (manis3 - 5) % 360;
            glutPostRedisplay();
            break;
        case 's':
            kelingking1 = (kelingking1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            kelingking1 = (kelingking1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            kelingking2 = (kelingking2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            kelingking2 = (kelingking2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'f':
            kelingking3 = (kelingking3 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            kelingking3 = (kelingking3 - 5) % 360;
            glutPostRedisplay();
            break;
        case 27: // ESC key
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
