#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void Bre_line1(int x1, int y1, int x2, int y2, int c){
	// 0 < dy/dx < 1
	int y = y1, dx = x2 - x1, dy = y2 - y1;
	int p = 2 * dy - dx;
	for (int x = x1; x <= x2; ++x){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		if (p >= 0){ 
			p += 2 * (dy - dx);
			y++;
		}
		else{
			p += 2 * dy;
		}
	}
}

void Bre_line2(int x1, int y1, int x2, int y2, int c){
	// dy/dx > 1
	int x = x1, dx = x2 - x1, dy = y2 - y1;
	int p = dy - 2 * dx;
	for (int y = y1; y <= y2; ++y){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		if (p <= 0){
			p += 2 * (dy - dx);
		}
		else{
			p += (-2 * dx);
			x++;
		}
	}
}

void Bre_line3(int x1, int y1, int x2, int y2, int c){
	// -1 < dy/dx < 0
	int y = y1, dx = x2 - x1, dy = y2 - y1;
	int p = 2 * dy + dx;
	for (int x = x1; x <= x2; ++x){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		if (p <= 0){
			p += 2 * (dy + dx);
			y --;
		}
		else{
			p += 2 * dy;
		}
	}
}

void Bre_line4(int x1, int y1, int x2, int y2, int c){
	// dy/dx < -1
	int x = x1, dx = x2 - x1, dy = y2 - y1;
	int p = - dy - 2 * dx;
	for (int y = y1; y <= y2; ++y){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		if (p >= 0){
			p += -2 * (dy + dx);
			x --;
		}
		else{
			p += -2 * dx;
		}
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	Bre_line1(20, 50, 100, 90, 255);
	Bre_line2(150, 150, 200, 600, 255);
	Bre_line3(200, 500, 1000, 100, 255);
	Bre_line4(100, 200, 50, 500, 255);
	getch();
	closegraph();
}
