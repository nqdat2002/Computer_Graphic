#include <graphics.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, NULL);
    circle(300,300,110);
    getch();
    closegraph();
    return 0;
}

