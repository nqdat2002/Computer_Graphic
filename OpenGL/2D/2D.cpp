#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
using namespace std;

float triangle[3][3] = {{200, 300, 400}, {100, 300, 100}, {1, 1, 1}};
float rot_mat[3][3] = {{0}, {0}, {0}};
float scale_mat[3][3] = {{0}, {0}, {0}};
float translate_mat[3][3] = {{0}, {0}, {0}};
float deform_mat[3][3] = {{0}, {0}, {0}};
float symmetry_mat[3][3] = {{0}, {0}, {0}};
float result[3][3] = {{0}, {0}, {0}};

void multiply(float mat[][3], float triangle[][3], float result[][3]){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			result[i][j] = 0;
			for (int k = 0; k < 3; ++k) result[i][j] += mat[i][k] * triangle[k][j];
		}
	}
}

void copy(float mat1[][3], float mat2[][3]){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j) mat1[i][j] = mat2[i][j];
	}
}

void reset(){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j) result[i][j] = 0;
	}
}

void rotate(float alpha){
	alpha = ((3.14 / 180) * alpha);
	rot_mat[0][0] = cos(alpha);
	rot_mat[0][1] = -sin(alpha);
	rot_mat[0][2] = 0;
	rot_mat[1][0] = sin(alpha);
	rot_mat[1][1] = cos(alpha);
	rot_mat[1][2] = 0;
	rot_mat[2][0] = 0;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = 1;
//	multiply(rot_mat);
}

void scale(float Sx, float Sy){
	scale_mat[0][0] = Sx;
	scale_mat[0][1] = 0;
	scale_mat[0][2] = 0;
	scale_mat[1][0] = 0;
	scale_mat[1][1] = Sy;
	scale_mat[1][2] = 0;
	scale_mat[2][0] = 0;
	scale_mat[2][1] = 0;
	scale_mat[2][2] = 1;
//	multiply(scale_mat);
}

void translate(float dx, float dy){
	translate_mat[0][0] = 1;
	translate_mat[0][1] = 0;
	translate_mat[0][2] = dx;
	translate_mat[1][0] = 0;
	translate_mat[1][1] = 1;
	translate_mat[1][2] = dy;
	translate_mat[2][0] = 0;
	translate_mat[2][1] = 0;
	translate_mat[2][2] = 1;
//	multiply(translate_mat);
}

void deform(float b, float c){
	deform_mat[0][0] = 1;
	deform_mat[0][1] = c;
	deform_mat[0][2] = 0;
	deform_mat[1][0] = b;
	deform_mat[1][1] = 1;
	deform_mat[1][2] = 0;
	deform_mat[2][0] = 0;
	deform_mat[2][1] = 0;
	deform_mat[2][2] = 1;
//	multiply(deform_mat);
}

void symmetry_Ox(){
	symmetry_mat[0][0] = 1;
	symmetry_mat[0][1] = 0;
	symmetry_mat[0][2] = 0;
	symmetry_mat[1][0] = 0;
	symmetry_mat[1][1] = -1;
	symmetry_mat[1][2] = 0;
	symmetry_mat[2][0] = 0;
	symmetry_mat[2][1] = 0;
	symmetry_mat[2][2] = 1;
//	multiply(symmetry_mat);
}

void symmetry_Oy(){
	symmetry_mat[0][0] = -1;
	symmetry_mat[0][1] = 0;
	symmetry_mat[0][2] = 0;
	symmetry_mat[1][0] = 0;
	symmetry_mat[1][1] = 1;
	symmetry_mat[1][2] = 0;
	symmetry_mat[2][0] = 0;
	symmetry_mat[2][1] = 0;
	symmetry_mat[2][2] = 1;
//	multiply(symmetry_mat);
}

void symmetry_O(){
	symmetry_mat[0][0] = -1;
	symmetry_mat[0][1] = 0;
	symmetry_mat[0][2] = 0;
	symmetry_mat[1][0] = 0;
	symmetry_mat[1][1] = -1;
	symmetry_mat[1][2] = 0;
	symmetry_mat[2][0] = 0;
	symmetry_mat[2][1] = 0;
	symmetry_mat[2][2] = 1;
//	multiply(symmetry_mat);
}

void drawtriangle(){
	glBegin(GL_TRIANGLES);
		glVertex2f(triangle[0][0], triangle[1][0]);
		glVertex2f(triangle[0][1], triangle[1][1]);
		glVertex2f(triangle[0][2], triangle[1][2]);
	glEnd();
}

void drawresulttriangle(){
	glBegin(GL_TRIANGLES);
		glVertex2f(result[0][0], result[1][0]);
		glVertex2f(result[0][1], result[1][1]);
		glVertex2f(result[0][2], result[1][2]);
	glEnd();
}

void display(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
		glVertex2f(0, 0);
	glEnd();
	glColor3f(1, 0, 0);
	
	drawtriangle();
	float tmp[3][3];
	
	translate(150, 100);
	multiply(translate_mat, triangle, result);
	copy(tmp, result);
	reset();
	
	rotate(30);
	multiply(rot_mat, tmp, result);
	copy(tmp, result);
	reset();
	
	scale(1.5, 1.5);
	multiply(scale_mat, tmp, result);
	copy(tmp, result);
	reset();
	
	symmetry_O();
	multiply(symmetry_mat, tmp, result);
	glColor3f(0, 1, 0);
	
	drawresulttriangle();
	glFlush();
}

void init(){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1000, 1000, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("2D Transformations");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
