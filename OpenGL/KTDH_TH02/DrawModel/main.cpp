#include <windows.h>
#include <GL/glut.h>

/* Global variables */
char title[] = "3D Shapes";

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);    

    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
    // Top face (y = 1.0f)
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);

    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    // Back face (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    // Render a pyramid consists of 4 triangles
//    glLoadIdentity();                  // Reset the model-view matrix
//    glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen
//
//    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
//    // Front
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f( 0.0f, 1.0f, 0.0f);
//    glColor3f(0.0f, 1.0f, 0.0f);     // Green
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
//    glVertex3f(1.0f, -1.0f, 1.0f);
//
//    // Right
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f(0.0f, 1.0f, 0.0f);
//    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glColor3f(0.0f, 1.0f, 0.0f);     // Green
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    // Back
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f(0.0f, 1.0f, 0.0f);
//    glColor3f(0.0f, 1.0f, 0.0f);     // Green
//    glVertex3f(1.0f, -1.0f, -1.0f);
//    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//
//    // Left
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f( 0.0f, 1.0f, 0.0f);
//    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glColor3f(0.0f, 1.0f, 0.0f);     // Green
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glEnd();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) { 
    if (height == 0) height = 1; 
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();           
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_SINGLE); 
    glutInitWindowSize(640, 480); 
    glutInitWindowPosition(50, 50); 
    glutCreateWindow(title);    
    initGL(); 
    glutDisplayFunc(display);      
    glutReshapeFunc(reshape);                            
    glutMainLoop();
    return 0;
}

