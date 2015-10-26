#include <graphics.h>
#include <math.h>
// sx sy ex sy are the x and y of the two point, and r is the angle, len is the lenth of arrow's front part
void draw_arrow(float sx, float sy,
                float ex, float ey,
                float r, float len) {
    float c = cos(r), s = sin(r);
    float dx = sx - ex, dy = sy - ey;
    ege_line(sx, sy, ex, ey);//draw the line
    // calculate the coords of the three point
    ege_point points[3] = {
        ex, ey,
        len * (dx * c + dy * s) + ex,
        len * (-dx * s + dy * c) + ey,
        len * (dx * c - dy * s) + ex,
        len * (dx * s + dy * c) + ey
    };
    ege_fillpoly(3, points);//draw the front part
}

int main( void ) {
    // initialize
    initgraph(640, 480);
    ege_enable_aa(true);
    setcolor(EGEARGB(0xff, 0xff, 0xff, 0xff));
    setfillcolor(EGEARGB(0xff, 0xff, 0x0, 0xff));
    setlinewidth(2.0f);
    draw_arrow(100.0f, 100.0f, 300.0f, 150.0f,
               (float)(PI / 8), 0.2f);
    getch();
    return 0;
}

