#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

inline void pc(int xc, int yc, int x, int y, int color){
	putpixel(xc + x, yc + y, color);
	putpixel(xc - x, yc - y, color);
	putpixel(xc - y, yc + x, color);
	putpixel(xc + y, yc - x, color);
}

void Circle_Half(int xc, int yc, int Radius, int color){
	int x = 0, y = Radius;
	int p = 3 - 2 * Radius;
//	putpixel(xc, yc, color);
//	pc(xc, yc, Radius, 0, color); // Draw 4 points which are speacial
	
	while(x < y){
		putpixel(xc, yc, color);
		cout << p << endl;
		cout << x << " " << y << endl;
		if (p < 0){
			p += 4 * x + 6;
		}
		else{
			p += 4 * (x - y) + 10;
			y --;
		}
		x ++;
//		pc(xc, yc, x, y, color);
	}
//	pc(xc, yc, y, y, color); // Draw 4 points where x = y
}

void Circle_Bre(int xc, int yc, int Radius, int color){
	int x = 0, y = Radius;
	int p = 3 - 2 * Radius;
//	putpixel(xc, yc, color);
	pc(xc, yc, Radius, 0, color); // Draw 4 points which are speacial (-x, 0), (0, y), (x, 0), (0, -y)
	
	while(x < y){
		if (p < 0){
			p += 4 * x + 6;
		}
		else{
			p += 4 * (x - y) + 10;
			y --;
		}
		x ++;
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		pc(xc, yc, x, y, color);
		pc(xc, yc, y, x, color);
	}
	pc(xc, yc, y, y, color); // Draw 4 points where x = y
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	Circle_Bre(200, 200, 200, 255);
	getch();
	closegraph();
}
