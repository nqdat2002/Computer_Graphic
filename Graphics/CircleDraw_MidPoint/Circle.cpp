#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
//#define pcc(xc,yc,x,y,color){putpixel(xc+x,yc+y,color);putpixel(xc-x,yc-y,color);putpixel(xc-y,yc+x,color);putpixel(xc+y,yc-x,color);}

inline void pc(int xc, int yc, int x, int y, int color){
	putpixel(xc + x, yc + y, color);
	putpixel(xc - x, yc - y, color);
	putpixel(xc - y, yc + x, color);
	putpixel(xc + y, yc - x, color);
}

void Circle_MidPoint(int xc, int yc, int Radius, int color){
	int x = 0, y = Radius, p = 1 - Radius;
	pc(xc, yc, Radius, 0, color);
	while (x < y){
		putpixel(x, y, color);
		cout << "Delta P : " << p << endl;
		cout << "(x, y): " << x << " " << y << endl;
		cout << endl;
		pc(xc, yc, x, y, color);
		pc(xc, yc, y, x, color);
		if (p < 0){
			p += 2 * x + 3;
		}
		else{
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;  
	}
	pc(xc, yc, y, y, color);
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	Circle_MidPoint(90, 90, 10, 255);
	getch();
	closegraph();
}
