#include <windows.h>
#include <bits/stdc++.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

typedef long long ll;

using namespace std;

void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}
// mydisplay method
void mydisplay(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(1.0);
	
	// Draw OXY
	glBegin(GL_LINES);
	glVertex2i(-300, 0);
	glVertex2i(300, 0);
	glVertex2i(0, 300);
	glVertex2i(0, -300);
	glEnd();
	
	glColor3f(1.0, 0.75, 0.0);
	GLfloat r, phi;
	GLfloat step = M_PI / 5.0;
	glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 10; ++i){
			r = (i % 2 == 0 ? 70 : 150);
			phi = i * step - M_PI / 2.0;
			glVertex3f(r * cos(phi), r * sin(phi), 0.0);
		}
	glEnd();
	
	glFlush();
}

// Main method
int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Star Drawing Tutorial");
	
	init();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
