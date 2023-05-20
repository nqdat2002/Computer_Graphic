#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

//float obj[4][5] = {{30, 90, 90, 0, 45},
//					{20, 20, 20, 20, 90},
//					{30, 30, -30, -30, 0},
//					{1, 1, 1, 1, 1}}; 

//float obj[4][5] = {{0.3f, 0.9f, 0.9f, 0.0f, 0.45f},
//					{0.2f, 0.2f, 0.2f, 0.2f, 0.9f},
//					{0.3f, 0.3f, -0.3f, -0.3f, 0.0f},
//					{1, 1, 1, 1, 1}};
					
float obj[4][5] = {{-0.3f, 0.3f, 0.3f, -0.3f, 0.0f},
					{0.3f, 0.3f, 0.3f, 0.3f, 0.9f},
					{0.3f, 0.3f, -0.3f, -0.3f, 0.0f},
					{1, 1, 1, 1, 1}
};
										
float rot_mat[4][4] = {{0}, {0}, {0}, {0}};
float scale_mat[4][4] = {{0}, {0}, {0}, {0}};
float translate_mat[4][4] = {{0}, {0}, {0}, {0}};
float deform_mat[4][4] = {{0}, {0}, {0}, {0}};
float symmetry_mat[4][4] = {{0}, {0}, {0}, {0}};
float res[4][4] = {{0}, {0}, {0}, {0}};

float result[4][5]  = {{0}, {0}, {0}, {0}};
float inverse_mat[4][4] = {{0}, {0}, {0}, {0}}; 

float result1[4][4] = {{0}, {0}, {0}, {0}};
float result2[4][4] = {{0}, {0}, {0}, {0}};

void copy(float mat1[][4], float mat2[][4]){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j) mat1[i][j] = mat2[i][j];
	}
}

void reset1(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j) res[i][j] = 0;
	}
}

void reset2(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 5; ++j) result[i][j] = 0;
	}
}

void translate(float dx, float dy, float dz){
  	translate_mat[0][0] = 1;
	translate_mat[0][1] = 0;
	translate_mat[0][2] = 0;
	translate_mat[0][3] = dx;
	
  	translate_mat[1][0] = 0;
	translate_mat[1][1] = 1;
	translate_mat[1][2] = 0;
	translate_mat[1][3] = dy;
	
  	translate_mat[2][0] = 0;
	translate_mat[2][1] = 0;
	translate_mat[2][2] = 1;
	translate_mat[2][3] = dz;
	
	translate_mat[3][0] = 0;
	translate_mat[3][1] = 0;
	translate_mat[3][2] = 0;
	translate_mat[3][3] = 1;
		
}

void deform(float a, float b, float c, float d, float e, float f){
	
  	deform_mat[0][0] = 1;
	deform_mat[0][1] = c;
	deform_mat[0][2] = e;
	deform_mat[0][3] = 0;
	
  	deform_mat[1][0] = a;
	deform_mat[1][1] = 1;
	deform_mat[1][2] = f;
	deform_mat[1][3] = 0;
	
  	deform_mat[2][0] = b;
	deform_mat[2][1] = d;
	deform_mat[2][2] = 1;
	deform_mat[2][3] = 0;
	
  	deform_mat[3][0] = 0;
	deform_mat[3][1] = 0;
	deform_mat[3][2] = 0;
	deform_mat[3][3] = 1;
}

void symmetry_O(){
	symmetry_mat[0][0] = -1;
	symmetry_mat[0][1] = 0;
	symmetry_mat[0][2] = 0;
	symmetry_mat[0][3] = 0;
	
	symmetry_mat[1][0] = 0;
	symmetry_mat[1][1] = -1;
	symmetry_mat[1][2] = 0;
	symmetry_mat[1][3] = 0;
	
	symmetry_mat[2][0] = 0;
	symmetry_mat[2][1] = 0;
	symmetry_mat[2][2] = -1;
	symmetry_mat[2][3] = 0;
	
	symmetry_mat[3][0] = 0;
	symmetry_mat[3][1] = 0;
	symmetry_mat[3][2] = 0;
	symmetry_mat[3][3] = 1;
}

void symmetry_Ox(){
	symmetry_mat[0][0] = 1;
	symmetry_mat[0][1] = 0;
	symmetry_mat[0][2] = 0;
	symmetry_mat[0][3] = 0;
	
	symmetry_mat[1][0] = 0;
	symmetry_mat[1][1] = -1;
	symmetry_mat[1][2] = 0;
	symmetry_mat[1][3] = 0;
	
	symmetry_mat[2][0] = 0;
	symmetry_mat[2][1] = 0;
	symmetry_mat[2][2] = -1;
	symmetry_mat[2][3] = 0;
	
	symmetry_mat[3][0] = 0;
	symmetry_mat[3][1] = 0;
	symmetry_mat[3][2] = 0;
	symmetry_mat[3][3] = 1;
}

void symmetry_xOy(){
	symmetry_mat[0][0] = 1;
	symmetry_mat[0][1] = 0;
	symmetry_mat[0][2] = 0;
	symmetry_mat[0][3] = 0;
	
	symmetry_mat[1][0] = 0;
	symmetry_mat[1][1] = 1;
	symmetry_mat[1][2] = 0;
	symmetry_mat[1][3] = 0;
	
	symmetry_mat[2][0] = 0;
	symmetry_mat[2][1] = 0;
	symmetry_mat[2][2] = -1;
	symmetry_mat[2][3] = 0;
	
	symmetry_mat[3][0] = 0;
	symmetry_mat[3][1] = 0;
	symmetry_mat[3][2] = 0;
	symmetry_mat[3][3] = 1;
}

void scale(float Sx, float Sy, float Sz){
	scale_mat[0][0] = Sx;
	scale_mat[0][1] = 0;
	scale_mat[0][2] = 0;
	scale_mat[0][3] = 0;
	
	scale_mat[0][0] = 0;
	scale_mat[0][1] = Sy;
	scale_mat[0][2] = 0;
	scale_mat[0][3] = 0;
	
	scale_mat[0][0] = 0;
	scale_mat[0][1] = 0;
	scale_mat[0][2] = Sz;
	scale_mat[0][3] = 0;
	
	scale_mat[0][0] = 0;
	scale_mat[0][1] = 0;
	scale_mat[0][2] = 0;
	scale_mat[0][3] = 1;

}

void RotateX(float alpha){
	alpha = ((M_PI / 180) * alpha);
	
	rot_mat[0][0] = 1;
	rot_mat[0][1] = 0;
	rot_mat[0][2] = 0;
	rot_mat[0][3] = 0;
	
	rot_mat[1][0] = 0;
	rot_mat[1][1] = cos(alpha);
	rot_mat[1][2] = -sin(alpha);
	rot_mat[1][3] = 0;
	
	rot_mat[2][0] = 0;
	rot_mat[2][1] = sin(alpha);
	rot_mat[2][2] = cos(alpha);
	rot_mat[2][3] = 0;
	
	rot_mat[3][0] = 0;
	rot_mat[3][1] = 0;
	rot_mat[3][2] = 0;
	rot_mat[3][3] = 1;
}

void RotateY(float alpha){
	alpha = ((M_PI / 180) * alpha);
		
	rot_mat[0][0] = cos(alpha);
	rot_mat[0][1] = 0;
	rot_mat[0][2] = sin(alpha);
	rot_mat[0][3] = 0;
	
	rot_mat[1][0] = 0;
	rot_mat[1][1] = 1;
	rot_mat[1][2] = 0;
	rot_mat[1][3] = 0;
	
	rot_mat[2][0] = -sin(alpha);
	rot_mat[2][1] = 0;
	rot_mat[2][2] = cos(alpha);
	rot_mat[2][3] = 0;
	
	rot_mat[3][0] = 0;
	rot_mat[3][1] = 0;
	rot_mat[3][2] = 0;
	rot_mat[3][3] = 1;
}

void RotateZ(float alpha){
	alpha = ((M_PI / 180) * alpha);
	
	rot_mat[0][0] = cos(alpha);
	rot_mat[0][1] = -sin(alpha);
	rot_mat[0][2] = 0;
	rot_mat[0][3] = 0;
	
	rot_mat[1][0] = sin(alpha);
	rot_mat[1][1] = cos(alpha);
	rot_mat[1][2] = 0;
	rot_mat[1][3] = 0;
	
	rot_mat[2][0] = 0;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = 1;
	rot_mat[2][3] = 0;
	
	rot_mat[3][0] = 0;
	rot_mat[3][1] = 0;
	rot_mat[3][2] = 0;
	rot_mat[3][3] = 1;	
	
}

void multiply1(float mat1[][4], float mat2[][4], float res[][4]){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			res[i][j] = 0;
			for (int k = 0; k < 4; ++k) res[i][j] += mat1[i][k] * mat2[k][j];
		}
	}
}

void multiply2(float mat[][4], float obj[][5], float result[][5]){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 5; ++j){
			result[i][j] = 0;
			for (int k = 0; k < 4; ++k) result[i][j] += mat[i][k] * obj[k][j];
		}
	}
}
void Rotate_random(float alpha, float beta) {
	float tmp1[4][4];
	float tmp2[4][4];
	alpha = ((M_PI / 180) * alpha);
	RotateY(-alpha);
	copy(tmp1, rot_mat);
	RotateX(beta);
	multiply1(rot_mat, tmp1, result1);
	copy(tmp2,rot_mat);
	
	tmp1[0][2]  = -sin(alpha);
	tmp1[2][0]  = sin(alpha);
	
	tmp2[1][2] = sin(beta);
	tmp2[2][1] = -sin(beta);
	
	multiply1(tmp1, tmp2, result2);
}

void Axes(){
  	glColor3f(1.0, 0.0, 0.0);
  	glBegin(GL_LINES); // Plotting X-Axis
	  	glVertex3f(-1000, 0, 0);
	  	glVertex3f(1000, 0, 0);
  	glEnd();
  	glColor3f(1.0, 0.0, 0.0);
  	glBegin(GL_LINES); // Plotting Y-Axis
	  	glVertex3f(0, -1000, 0);
	  	glVertex3f(0, 1000, 0);
  	glEnd();
  	glColor3f(1.0, 0.0, 0.0);
  	glBegin(GL_LINES); // Plotting Z-Axis
	  	glVertex3f(0, 0, -1000);
	  	glVertex3f(0, 0, 1000);
  	glEnd();
}

void draw(float a[4][5]){
  	glBegin(GL_QUADS);
  	glColor3f(0.7, 0.4, 0.5); //bottom
  	glVertex3f(a[0][0],a[1][0],a[2][0]);
  	glVertex3f(a[0][1],a[1][1],a[2][1]);
  	glVertex3f(a[0][2],a[1][2],a[2][2]);
  	glVertex3f(a[0][3],a[1][3],a[2][3]);
  	
  	glBegin(GL_QUADS);
  	glColor3f(0.8, 0.2, 0.4); //behind
  	glVertex3f(a[0][2],a[1][2],a[2][2]);
  	glVertex3f(a[0][3],a[1][3],a[2][3]);
  	glVertex3f(a[0][4],a[1][4],a[2][4]);

	glBegin(GL_QUADS);	
  	glColor3f(0.3, 0.6, 0.2); //right
  	glVertex3f(a[0][2],a[1][2],a[2][2]);
  	glVertex3f(a[0][4],a[1][4],a[2][4]);
  	glVertex3f(a[0][1],a[1][1],a[2][1]);
  	
  	glBegin(GL_QUADS);
  	glColor3f(0, 0, 0.4); //left
  	glVertex3f(a[0][3],a[1][3],a[2][3]);
  	glVertex3f(a[0][4],a[1][4],a[2][4]);
  	glVertex3f(a[0][0],a[1][0],a[2][0]);
  	
  	glBegin(GL_QUADS);
  	glColor3f(0.6, 0.6, 0.2); //front
  	glVertex3f(a[0][0],a[1][0],a[2][0]);
  	glVertex3f(a[0][1],a[1][1],a[2][1]);
  	glVertex3f(a[0][4],a[1][4],a[2][4]);
  	
  	glEnd();
}
void print(float a[][5]){
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 5; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}	
}
void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);                 
   	glEnable(GL_DEPTH_TEST);  
   	glDepthFunc(GL_LEQUAL);   
   	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	Axes(); // draw OXYZ
	
	// object first one
  	draw(obj);
  	print(obj);
  	
// quay quanh truc OY
//  	RotateY(90);
//	translate(-0.8f, 0, 0);
//	multiply1(translate_mat, rot_mat, res);
//	multiply2(res, obj, result);
//	draw(result);
//	print(result);

// Quay quanh duong thang di qua diem // 0Z
//	glBegin(GL_POINTS);
//	glVertex3f(0.5f, 0.5f, 0.5f);
//	glLineWidth(2.0);
//	glColor3f(0.6, 0.6, 0.9);
//  	glEnd();
//	translate(0.0f, 0.0f, -0.5f);
//	RotateZ(-90);
//	multiply1(rot_mat, translate_mat, res);
//	translate(0.0f, 0.0f, 0.5f);
//	float tmp[4][4];
//	copy(tmp, res);
//	reset1();
//	multiply1(translate_mat, tmp, res);
//	multiply2(res, obj, result);
//	draw(result);
//	reset2();

	float tmp[4][4];
  	float tmp2[4][4];
  	float tmp3[4][4];
  	
	glBegin(GL_POINTS);
  		glVertex3f(0.2f, 0.3f, 0.4f);
  		glColor3f(0.9, 0.6, 0.1);
  	glEnd();
	translate(-0.2f,-0.3f,-0.4f);
	Rotate_random(90);
	multiply1(result1,translate_mat,tmp);
	RotateZ(90);
	multiply1(rot_mat,tmp,tmp2);
	multiply1(result2,tmp2,tmp3);
	translate(0.2f, 0.3f, 0.4f);
	multiply1(translate_mat,tmp3,res);
	multiply2(res,obj,result);
	draw(result);
	reset2();
	
	glutSwapBuffers();
	glFlush();
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1080, 780); 
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
