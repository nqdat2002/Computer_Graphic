#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

inline long Round(double a){
	return (long) (a + 0.5);
}

inline void plot(int xc, int yc, int x, int y, int color){
	putpixel(xc + x, yc + y, color);
	putpixel(xc - x, yc + y, color);
	putpixel(xc + x, yc - y, color);
	putpixel(xc - x, yc - y, color);
}

void Ellipse_MidPoint(int xc, int yc, int a, int b, int color){
	long x = 0, y = b, a2 = a * a, b2 = b * b, fx = 0, fy = 2 * a2 * y;
	plot(xc, yc, x, y, color);
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
		
		// print
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		
		plot(xc, yc, x, y, color);
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
		// print
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		
		plot(xc, yc, x, y, color);
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	Ellipse_MidPoint(getmaxx() / 2, getmaxy() / 2, 150, 80, 255);
	getch();
	closegraph(); 
}
