#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Variabel pergerakan kamera
float angle = 0.0;                  // Sudut yaw awal
float deltaAngle = 0.0;             // Perubahan yaw
float pitchAngle = 0.0, deltaPitch = 0.0;  // Variabel untuk rotasi atas dan bawah (pitch)
float x = 0.0f, y = 1.75f, z = 15.0f; // Posisi awal kamera

// Arah pandang awal
float lx = 0.0f, ly = 0.0f, lz = -1.0f;

int deltaMove = 0;    // Gerakan maju/mundur
int deltaUp = 0;      // Gerakan naik/turun

const float movementSpeed = 0.005f;   // Kecepatan gerakan

// Fungsi untuk menggambar grid di tanah
void Grid() {
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

// Fungsi untuk menggambar objek tempat sampah
void drawTrashBin() {    
    
    // Body depan
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray
    glScalef(1.0f, 1.5f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Body belakang
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.5f);
    glScalef(1.0f, 1.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Body kiri
    glPushMatrix();
    glTranslatef(-0.5f, 0.0f, -0.25f);
    glScalef(0.1f, 1.5f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Body kanan
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, -0.25f);
    glScalef(0.1f, 1.5f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Roda
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f);
    glTranslatef(0.4f, -0.75f, 0.5f);
    glutSolidSphere(0.1, 20, 20);
    
    glTranslatef(-0.8f, 0.0f, 0.0f);
    glutSolidSphere(0.1, 20, 20);
    
    glTranslatef(0.8f, 0.0f, -1.0f);
    glutSolidSphere(0.1, 20, 20);
    
    glTranslatef(-0.8f, 0.0f, 0.0f);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
    
    // Tutup atas
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(0.0f, 0.75f, 0.0f);
    glScalef(1.2f, 0.1f, 1.2f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void display() {
    // Perbarui posisi kamera berdasarkan input
    if (deltaMove) {
        x += deltaMove * movementSpeed * lx;
        z += deltaMove * movementSpeed * lz;
    }
    if (deltaUp) {
        y += deltaUp * movementSpeed;
    }
    
    // Perbarui nilai yaw dan pitch
    angle += deltaAngle;
    pitchAngle += deltaPitch;
    
    // Hitung kembali vektor pandang berdasarkan yaw dan pitch
    lx = sin(angle) * cos(pitchAngle);
    ly = sin(pitchAngle);
    lz = -cos(angle) * cos(pitchAngle);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
    
    // Gambar grid (diturunkan agar berada di bawah objek)
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    Grid();
    glPopMatrix();
    
    // Gambar objek tempat sampah
    drawTrashBin();
    
    glutSwapBuffers();
    glFlush();
    
    // Minta untuk menggambar ulang
    glutPostRedisplay();
}

// Fungsi untuk menangani input keyboard normal
void pressKey(unsigned char key, int xx, int yy) {
    switch (key) {
        case 'w':
            deltaMove = 1;
            break;
        case 's':
            deltaMove = -1;
            break;
        case 'a':  // Rotasi ke kiri (yaw berkurang)
            deltaAngle = -0.0005f;
            break;
        case 'd':  // Rotasi ke kanan (yaw bertambah)
            deltaAngle = 0.0005f;
            break;
        case 'q':
            deltaPitch = 0.001f;
            break;
        case 'e':
            deltaPitch = -0.001f;
            break;
    }
}

void releaseKey(unsigned char key, int xx, int yy) {
    switch (key) {
        case 'w':
        case 's':
            deltaMove = 0;
            break;
        case 'a':
        case 'd':
            deltaAngle = 0.0f;
            break;
        case 'q':
        case 'e':
            deltaPitch = 0.0f;
            break;
    }
}

// Fungsi untuk menangani input tombol khusus (Page Up/Down)
void specialPressKey(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_PAGE_UP:
            deltaUp = 1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            deltaUp = -1;
            break;
    }
}

void specialReleaseKey(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_PAGE_UP:
        case GLUT_KEY_PAGE_DOWN:
            deltaUp = 0;
            break;
    }
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);  // Jarak pandang diperluas agar grid dan objek tampak jelas
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Trash Bin");
    
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(pressKey);
    glutKeyboardUpFunc(releaseKey);
    glutSpecialFunc(specialPressKey);
    glutSpecialUpFunc(specialReleaseKey);
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    return 0;
}
