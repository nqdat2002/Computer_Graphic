#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#define maxWD 640
#define maxHT 480
#define thetaSpeed 0.05

void init(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel (GL_FLAT);
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
   	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity();
	
	glBegin(GL_LINES);
		glVertex2i(-300, 0);
		glVertex2i(300, 0);
		glVertex2i(0, 300);
		glVertex2i(0, -300);
	glEnd();	   	
	
   	glBegin(GL_TRIANGLES);              
		glColor3f(0.0f, 0.0f, 0.5f); 
		glVertex2f(0.0f, 0.0f);
		glVertex2f( 0.0f, 0.5f);   
		glVertex2f( 0.7f,  0.0f);
   	glEnd();
	// Translatef base on Oy and Rotatef with phi = 90
   	glTranslatef(0.0f, 0.3f, 0.0f);
   	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
   	
   	glBegin(GL_TRIANGLES);              
		glColor3f(0.0f, 0.0f, 1.0f); 
		glVertex2f(0.0f, 0.0f);
		glVertex2f( 0.0f, 0.5f);   
		glVertex2f( 0.7f,  0.0f);
   	glEnd();
   	
//   	glBegin(GL_TRIANGLES);              
//		glColor3f(0.0f, 0.0f, 0.5f); 
//		glVertex2f(0.0f, 0.0f);
//		glVertex2f( 0.0f, -0.5f);   
//		glVertex2f( -0.7f,  0.0f);
//   	glEnd();
//   	// Symmetry by O and Scalef base on x and y
//	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
//	glScalef(2.0f, 1.0f, 1.0f);
//	glBegin(GL_TRIANGLES);              
//		glColor3f(0.0f, 0.0f, 0.5f); 
//		glVertex2f(0.0f, 0.0f);
//		glVertex2f( 0.0f, -0.5f);   
//		glVertex2f( -0.7f,  0.0f);
//   	glEnd();

    glutSwapBuffers();
   	glFlush();
}

void reshape (int w, int h)
{
   	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   	glMatrixMode (GL_PROJECTION);
   	glLoadIdentity ();
	gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
   	glMatrixMode (GL_MODELVIEW);
}

// main method

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Tranform in 2D!");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

