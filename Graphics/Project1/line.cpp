#include <graphics.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	line(20, 50, 100, 90);
//	line(150, 200, 450, 200);
//	line(150, 250, 450, 250);

	getch();
	closegraph();
	return 0;
}

