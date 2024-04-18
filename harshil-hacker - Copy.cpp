#include <iostream>

#include <stdio.h>
using namespace std; 

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = getmaxx() / 2; // get the x-coordinate of the center of the screen
    int y = getmaxy() / 2; // get the y-coordinate of the center of the screen

    int white_bar_height = getmaxy() / 3; // height of the white bar
    int green_bar_height = white_bar_height / 2; // height of the green bar
    int orange_bar_height = white_bar_height / 2; // height of the orange bar

    setcolor(WHITE);
    rectangle(x - white_bar_height * 3 / 10, y - white_bar_height / 2, x + white_bar_height * 3 / 10, y + white_bar_height / 2); // draw the white bar

    setfillstyle(SOLID_FILL, GREEN);
    bar(x - white_bar_height * 3 / 10, y - white_bar_height / 2, x + white_bar_height * 3 / 10, y - white_bar_height / 2 + green_bar_height); // draw the green bar

    setfillstyle(SOLID_FILL, ORANGE);
    bar(x - white_bar_height * 3 / 10, y + white_bar_height / 2 - orange_bar_height, x + white_bar_height * 3 / 10, y + white_bar_height / 2); // draw the orange bar

    setcolor(BLUE);
    circle(x, y, white_bar_height / 5); // draw the blue circle in the center of the flag

    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x, y, BLUE); // fill the blue circle with blue color

    getch();
    closegraph();
    return 0;
}
