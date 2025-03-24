#include <math.h>
 #include <GL/glut.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 // Al Vanza Aries Rahmatsyah
 // 24060123140169
 
 
 // Camera movement variables
 float angle = 0.0, deltaAngle = 0.0, ratio;
 float x = 0.0f, y = 1.75f, z = 15.0f;  // Initial camera position
 float lx = 0.0f, ly = 0.0f, lz = -1.0f; // Camera direction
 int deltaMove = 0, h, w;
 int bitmapHeight = 12;
 
 // Reshape function to handle window resizing
 void Reshape(int w1, int h1) {
     if (h1 == 0) h1 = 1;
     w = w1;
     h = h1;
     ratio = 1.0f * w / h;
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glViewport(0, 0, w, h);
     gluPerspective(45, ratio, 0.1, 1000);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
 }
 
 // Function to rotate the camera direction
 void orientMe(float ang) {
     lx = sin(ang);
     lz = -cos(ang);
     glLoadIdentity();
     gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
 }
 
 // Adjusted movement speed factor
 const float movementSpeed = 0.005f;
 
 // Function to move the camera forward/backward with slower movement
 void moveMeFlat(int i) {
     x += i * (lx) * movementSpeed;
     z += i * (lz) * movementSpeed;
     glLoadIdentity();
     gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
 }
 
 // Function to draw a grid on the ground
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
 
 // Function to draw a wooden box (cube) with modified color
 void KotakKayu() {
     // Ubah warna kubus menjadi kuning
     glColor3ub(180, 200, 30);
     
     // Front face
     glPushMatrix();
     glTranslatef(0, 0, 3);
     glBegin(GL_QUADS);
     glVertex3f(-3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, 3.0f, 0.0f);
     glVertex3f(-3.0f, 3.0f, 0.0f);
     glEnd();
     glPopMatrix();
 
     // Top face
     glPushMatrix();
     glRotated(-90, 1, 0, 0);
     glTranslatef(0, 0, 3);
     glBegin(GL_QUADS);
     glVertex3f(-3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, 3.0f, 0.0f);
     glVertex3f(-3.0f, 3.0f, 0.0f);
     glEnd();
     glPopMatrix();
 
     // Back face
     glPushMatrix();
     glRotated(-180, 1, 0, 0);
     glTranslatef(0, 0, 3);
     glBegin(GL_QUADS);
     glTexCoord2f(0.0f, 0.0f); 
     glVertex3f(-3.0f, -3.0f, 0.0f);
     glTexCoord2f(1.0f, 0.0f); 
     glVertex3f(3.0f, -3.0f, 0.0f);
     glTexCoord2f(1.0f, 1.0f); 
     glVertex3f(3.0f, 3.0f, 0.0f);
     glTexCoord2f(0.0f, 1.0f); 
     glVertex3f(-3.0f, 3.0f, 0.0f);
     glEnd();
     glPopMatrix();
 
     // Bottom face
     glPushMatrix();
     glRotated(90, 1, 0, 0);
     glTranslatef(0, 0, 3);
     glBegin(GL_QUADS);
     glTexCoord2f(0.0f, 0.0f);
     glVertex3f(-3.0f, -3.0f, 0.0f);
     glTexCoord2f(1.0f, 0.0f);
     glVertex3f(3.0f, -3.0f, 0.0f);
     glTexCoord2f(1.0f, 1.0f);
     glVertex3f(3.0f, 3.0f, 0.0f);
     glTexCoord2f(0.0f, 1.0f);
     glVertex3f(-3.0f, 3.0f, 0.0f);
     glEnd();
     glPopMatrix();
 
     // Left face
     glPushMatrix();
     glRotated(-90, 0, 1, 0);
     glTranslatef(0, 0, 3);
     glBegin(GL_QUADS);
     glVertex3f(-3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, 3.0f, 0.0f);
     glVertex3f(-3.0f, 3.0f, 0.0f);
     glEnd();
     glPopMatrix();
 
     // Right face
     glPushMatrix();
     glRotated(90, 0, 1, 0);
     glTranslatef(0, 0, 3);
     glBegin(GL_QUADS);
     glVertex3f(-3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, -3.0f, 0.0f);
     glVertex3f(3.0f, 3.0f, 0.0f);
     glVertex3f(-3.0f, 3.0f, 0.0f);
     glEnd();
     glPopMatrix();
 }
 
 // Display function to render the scene
 void display() {
     if (deltaMove)
         moveMeFlat(deltaMove);
     
     if (deltaAngle) {
         angle += deltaAngle;
         orientMe(angle);
     }
 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
     // Draw the grid and object
     Grid();
     KotakKayu();
 
     glutSwapBuffers();
     glFlush();
 }
 
 // Function to handle key press events for camera movement
 void pressKey(int key, int x, int y) {
     switch (key) {
         case GLUT_KEY_LEFT:
             // Perubahan: kecepatan rotasi lebih lambat
             deltaAngle = -0.0005f;
             break;
         case GLUT_KEY_RIGHT:
             deltaAngle = 0.0005f;
             break;
         case GLUT_KEY_UP:
             deltaMove = 1;
             break;
         case GLUT_KEY_DOWN:
             deltaMove = -1;
             break;
     }
 }
 
 // Function to handle key release events
 void releaseKey(int key, int x, int y) {
     switch (key) {
         case GLUT_KEY_LEFT:
             if (deltaAngle < 0.0f)
                 deltaAngle = 0.0f;
             break;
         case GLUT_KEY_RIGHT:
             if (deltaAngle > 0.0f)
                 deltaAngle = 0.0f;
             break;
         case GLUT_KEY_UP:
             if (deltaMove > 0)
                 deltaMove = 0;
             break;
         case GLUT_KEY_DOWN:
             if (deltaMove < 0)
                 deltaMove = 0;
             break;
     }
 }
 
 // Modified Lighting properties for nuansa yang lebih lembut dan realistis
 const GLfloat light_ambient[] =  { 0.3f, 0.3f, 0.3f, 1.0f };  // Ambient light
 const GLfloat light_diffuse[] =  { 0.8f, 0.8f, 0.8f, 1.0f };  // Diffuse light
 const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Specular light
 const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f }; // Light position
 
 // Modified Material properties dengan warna yang lebih hangat
 const GLfloat mat_ambient[] =   { 0.2f, 0.2f, 0.2f, 1.0f };    // Material ambient
 const GLfloat mat_diffuse[] =   { 0.6f, 0.3f, 0.3f, 1.0f };    // Material diffuse (nuansa merah)
 const GLfloat mat_specular[] =  { 1.0f, 1.0f, 1.0f, 1.0f };    // Material specular
 const GLfloat high_shininess[] = { 50.0f };                    // Material shininess
 
 // Lighting setup function
 void lighting() {
     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);
     glEnable(GL_LIGHT0);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_LIGHTING);
 
     glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
     glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);
 
     glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
     glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
 }
 
 // OpenGL initialization function
 void init(void) {
     glEnable(GL_DEPTH_TEST);
     glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
 }
 
 int main(int argc, char **argv) {
     printf("stb_image.h berhasil dimuat!\n");
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
     glutInitWindowPosition(100, 100);
     glutInitWindowSize(640, 480);
     glutCreateWindow("3D Lighting");
 
     glutIgnoreKeyRepeat(1);  // Ignore key repeat
     glutSpecialFunc(pressKey);
     glutSpecialUpFunc(releaseKey);
     glutDisplayFunc(display);
     glutIdleFunc(display);  // Continuously call display
     glutReshapeFunc(Reshape);
 
     lighting();
     init();
 
     glutMainLoop();
     return 0;
 }
