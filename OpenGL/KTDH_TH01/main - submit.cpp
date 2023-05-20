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

void Line_MidPoint1(int x1, int y1, int x2, int y2){
	//	0 < dy/dx < 1
	int y = y1, dx = x2 - x1, dy = y2 - y1;
	int p = dy - dx / 2;
	for (int x = x1; x <= x2; ++x){
		glVertex2i(x, y);
		if (p < 0){
			p += dy;
		}
		else{
			p += dy - dx;
			y ++;
		}
	}
}

void Line_MidPoint2(int x1, int y1, int x2, int y2){
	//	dy/dx > 1
	int x = x1, dx = x2 - x1, dy = y2 - y1;
	int p = dy / 2 - dx;
	for (int y = y1; y <= y2; ++y){
		glVertex2i(x, y);
		
		if (p > 0){
			p += -dx;
		}
		else{
			p += dy - dx;
			x ++;

		}
	}
}

void Line_MidPoint3(int x1, int y1, int x2, int y2){
	int y = y1, dx = x2 - x1, dy = y2 - y1;
	int p = dy + dx / 2;
	for (int x = x1; x <= x2; ++x){
		glVertex2i(x, y);
		if (p <= 0){
			p += (dy + dx);
			y --;
		}
		else{
			p += dy;
		}
	}
}

void Line_MidPoint4(int x1, int y1, int x2, int y2){
	// dy/dx < -1
	int x = x1, dx = x2 - x1, dy = y2 - y1;
	int p = - dy / 2 - dx;
	for (int y = y1; y <= y2; ++y){
		glVertex2i(x, y);
		if (p >= 0){
			p += -(dy + dx);
			x --;
		}
		else{
			p += -dx;
		}
	}
}

inline void putVertex(int xc, int yc, int x, int y){
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc - x);
}

void Circle_MidPoint(int xc, int yc, int Radius){
	int x = 0, y = Radius, p = 1 - Radius;
	putVertex(xc, yc, Radius, 0);
	while (x < y){
		glVertex2i(x, y);
		if (p < 0){
			p += 2 * x + 3;
		}
		else{
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;  
		putVertex(xc, yc, x, y);
		putVertex(xc, yc, y, x);
	}
	putVertex(xc, yc, y, y);
}
inline void plotVertex(int xc, int yc, int x, int y){
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
}

long Round(int a){
	return (long)(a + 0.5);
}
void Ellipse_MidPoint(int xc, int yc, int a, int b){
	long x = 0, y = b, a2 = a * a, b2 = b * b, fx = 0, fy = 2 * a2 * y;
	plotVertex(xc, yc, x, y);
	long p = Round(b2 - (a2 * b) + 0.5 * a);

	while(fx < fy){
		x++;
		fx += 2 * b2;
		if(p < 0){
			p += b2 * (2 * x + 3);
//			p += fx + b2; // same
		}
		else{
			y--;
			p += b2 * (2 * x + 3) + a2 * (-2 * y + 2);
//			p += fx + b2 - fy; // same
			fy -= 2 * a2;
		}
		plotVertex(xc, yc, x, y);
	}
	
	p = Round(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);
	
	while(y > 0){
		y--;
		fy -= 2 * a2;
		if (p >= 0){
			p += a2 * (3 - 2 * y);
//			p -= fy + a2; // same
		}
		else{
			x++;
			fx += 2 * b2;
			p += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
//			p += fx - fy + a2; // same
		}    
		plotVertex(xc, yc, x, y);
	}
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
	
	glLineWidth(2.0);
	glPointSize(2.0);
	
//	TH1: 0 < dy/dx < 1
	glBegin(GL_POINTS);
	Line_MidPoint1(100, -70, -20, -100);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(-20, -100);
	glVertex2i(100, -70);
	glEnd();
	
//	TH2: dy/dx > 1
	glBegin(GL_POINTS);
	Line_MidPoint2(20, 20, 60, 200);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(20, 20);
	glVertex2i(60, 200);
	glEnd();
	
//	TH3: -1 < dy/dx < 0
	glBegin(GL_POINTS);
	Line_MidPoint3(-20, -100, 100, -120);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(-20, -100);
	glVertex2i(100, -120);
	glEnd();
	
//	TH4: dy/dx < -1
	glBegin(GL_POINTS);
	Line_MidPoint4(40, -300, 20, -50);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(20, -50);
	glVertex2i(40, -300);
	glEnd();

	// CIRCLE using Midpoint Algorithm
	glBegin(GL_POINTS);
	Circle_MidPoint(0, 0, 70);
	glEnd();

	// ElLIPSE using Midpoint Algorithm
	glBegin(GL_POINTS);
	Ellipse_MidPoint(0, 0, 150, 80);
	glEnd();
	
	glFlush();
}

// Main method
int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Line Tutorial");
	
	init();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
