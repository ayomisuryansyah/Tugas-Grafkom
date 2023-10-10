#include <GL/glut.h>
#include <cmath>

GLfloat light_position[] = { 2.0, 2.0, 1.0, 1.0 }; // Posisi cahaya
GLfloat light_position2[] = { -2.0, 2.0, -1.0, 1.0 }; // Posisi cahaya
GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 }; // Warna cahaya putih
GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // Warna ambient light

int lastX = 0;
int lastY = 0;
bool leftMouseButtonDown = false;
bool middleMouseButtonDown = false;
bool rightMouseButtonDown = false;

float rotateX = 0.0;
float rotateY = 0.0;
float translateX = 0.0;
float translateY = -0.7;
float translateZ = -6.0; // Jarak awal kamera dari objek


void drawVertex()
{
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, 5.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.0f, 0.0f, -0.2f);
    glVertex3f(-0.2f, 5.0f, -0.2f);
    glVertex3f(1.0f, 0.0f, -0.2f);
    glVertex3f(0.2f, 5.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, -0.2f);
    glVertex3f(-1.0f, 0.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, 5.0f, 0.0f);
    glVertex3f(0.2f, 5.0f, -0.2f);
    glVertex3f(1.0f, 0.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.2f, 5.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, -0.2f);
    glVertex3f(0.2f, 5.0f, -0.2f);
    glVertex3f(0.2f, 5.0f, 0.0f);
    
    glEnd();


}

void drawCustomCube(float x, float y, float z, float scaleX, float scaleY, float scaleZ) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scaleX, scaleY, scaleZ);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawTorus( float innerRadius, float outerRadius, int sides, int rings) {
    glPushMatrix();
    glutSolidTorus(innerRadius, outerRadius, sides, rings);
    glPopMatrix();
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(translateX, translateY, translateZ);

    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);

    // Menetapkan pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white_light);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white_light);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50.0);

    //kaki tv
    glPushMatrix();
    glTranslatef(1.0, 0.53, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.3, 0.05, 0.3);
    drawVertex();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, 0.53, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.3, 0.05, 0.3);
    drawVertex();
    glPopMatrix();

    // Gambar papan meja
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.8);
    drawCustomCube(0.0, 0.515, 0.0, 2.5, 0.05, 1.35);
    drawCustomCube(0.0, -0.02, -0.5, 2.3, 0.9, 0.05);
    glColor3f(1.3, 1.3, 1.3);
    drawCustomCube(0.0, 0.47, 0.4, 2.4, 0.05, 0.05);
    drawCustomCube(0.0, 0.47, -0.4, 2.4, 0.05, 0.05);
    glPopMatrix();

    // Gambar Kaki meja
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    drawCustomCube(1.17, -0.175, 0.5, 0.1, 1.25, 0.07);
    drawCustomCube(1.17, -0.175, -0.5, 0.1, 1.25, 0.07);
    drawCustomCube(1.17, 0.415, 0.0, 0.1, 0.07, 1.0);
    drawCustomCube(1.17, -0.765, 0.0, 0.1, 0.07, 1.0);
    glColor3f(1.0, 1.0, 0.8);
    drawCustomCube(1.17, -0.2, 0.0, 0.03, 1.2, 0.5);
    glPopMatrix();

    // Gambar Kaki meja yang satunya
    glPushMatrix();
    glScalef(-1.0, 1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    drawCustomCube(1.17, -0.175, 0.5, 0.1, 1.25, 0.07);
    drawCustomCube(1.17, -0.175, -0.5, 0.1, 1.25, 0.07);
    drawCustomCube(1.17, 0.415, 0.0, 0.1, 0.07, 1.0);
    drawCustomCube(1.17, -0.765, 0.0, 0.1, 0.07, 1.0);
    glColor3f(1.0, 1.0, 0.8);
    drawCustomCube(1.17, -0.2, 0.0, 0.03, 1.2, 0.5);
    glPopMatrix();

    // Gambar laci meja
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    drawCustomCube(0.63, -0.021, 0.0, 1.0, 0.9, 0.9);
    glColor3f(1.0, 1.0, 0.8);
    drawCustomCube(0.63, 0.08, 0.46, 1.0, 0.36, 0.04);
    drawCustomCube(0.63, -0.3, 0.46, 1.0, 0.36, 0.04);
    drawCustomCube(0.63, 0.35, 0.46, 1.0, 0.15, 0.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.63, -0.2, 0.45);
    glRotatef(90.0, 1.0, .0, 0.0);  
    glScalef(1.0, 0.9, 1.2);
    glutSolidTorus( 0.01, 0.10, 30, 30); 
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.63, 0.18, 0.45);
    glRotatef(90.0, 1.0, .0, 0.0);
    glScalef(1.0, 0.9, 1.2);
    glutSolidTorus(0.01, 0.10, 30, 30);
    glPopMatrix();

    // Gambar papan meja
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    drawCustomCube(0.0, 1.45, 0.0, 2.3, 1.35, 0.05);
    glPopMatrix();



    glDisable(GL_LIGHTING);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    lastX = x;
    lastY = y;

    if (button == GLUT_LEFT_BUTTON) {
        leftMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_MIDDLE_BUTTON) {
        middleMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        rightMouseButtonDown = (state == GLUT_DOWN);
    }
}

void motion(int x, int y) {
    int deltaX = x - lastX;
    int deltaY = y - lastY;

    if (leftMouseButtonDown) {
        rotateX += deltaY * 0.5;
        rotateY += deltaX * 0.5;

        if (rotateX > 360.0) rotateX = 360.0;
        if (rotateX < -360.0) rotateX = -360.0;
    }
    else if (middleMouseButtonDown) {
        translateX += deltaX * 0.01;
        translateY -= deltaY * 0.01;
    }
    else if (rightMouseButtonDown) {
        translateZ += deltaY * 0.03;
    }

    lastX = x;
    lastY = y;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(720, 720);
    glutCreateWindow("OpenGL 3D Cylinder Example with Blender-like Camera");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutMainLoop();
    return 0;
}
`