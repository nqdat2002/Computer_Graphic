#include <bits/stdc++.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glEnd();
	glFlush();
}

int main(int argc, char ** argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);
	
	glutCreateWindow("New Frame!");
	
	glutDisplayFunc(display);
//	glutIdleFunc(display);
	init();

	glutMainLoop();
}
