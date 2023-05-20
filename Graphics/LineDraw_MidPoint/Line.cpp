#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void Line_MidPoint1(int x1, int y1, int x2, int y2, int c){
	//	0 < dy/dx < 1
	int y = y1, dx = x2 - x1, dy = y2 - y1;
	int p = dy - dx / 2;
	for (int x = x1; x <= x2; ++x){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		
		if (p < 0){
			p += dy;
		}
		else{
			p += dy - dx;
			y ++;
		}
	}
}

void Line_MidPoint2(int x1, int y1, int x2, int y2, int c){
	//	dy/dx > 1
	int x = x1, dx = x2 - x1, dy = y2 - y1;
	int p = dy / 2 - dx;
	for (int y = y1; y <= y2; ++y){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		
		if (p > 0){
			p += -dx;
			x++;
		}
		else{
			p += dy - dx;
		}
	}
}


void Line_MidPoint3(int x1, int y1, int x2, int y2, int c){
	// -1 < dy/dx < 0
	int y = y1, dx = x2 - x1, dy = y2 - y1;
	int p = dy + dx / 2;
	for (int x = x1; x <= x2; ++x){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		if (p <= 0){
			p += (dy + dx);
			y --;
		}
		else{
			p += dy;
		}
	}
}

void Line_MidPoint4(int x1, int y1, int x2, int y2, int c){
	// dy/dx < -1
	int x = x1, dx = x2 - x1, dy = y2 - y1;
	int p = - dy / 2 - dx;
	for (int y = y1; y <= y2; ++y){
		putpixel(x, y, c);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		if (p >= 0){
			p += -(dy + dx);
			x --;
		}
		else{
			p += -dx;
		}
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
//	Line_MidPoint1(20, 50, 100, 90, 255);
//	Line_MidPoint2(20, 20, 150, 400, 255);
	Line_MidPoint3(200, 500, 1000, 100, 255);
//	Line_MidPoint4(100, 200, 50, 500, 255);
	getch();
	closegraph();
}
