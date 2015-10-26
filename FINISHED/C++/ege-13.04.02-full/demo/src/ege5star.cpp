#include <graphics.h>
#include <time.h>
#include <math.h>

void paintstar(double x, double y, double r, double a)
{
    int pt[10];
//    calculate the coordinate of the five vertexs by using trigomometric function, and after each loop, the
//    angle will be a little different so that we will see the pentacle rotate a small angle
    for (int n = 0; n < 5; ++n)
    {
        pt[n * 2] = (int)( -cos( PI * 4 / 5 * n + a ) * r + x );//the x of the vertex
        pt[n * 2 + 1] = (int)( sin( PI * 4 / 5 * n + a) * r + y );//the y of the vertex
    }
    fillpoly(5, pt);//use the api to paint the pentacle
}

int main()
{
    // initilize
    initgraph( 640, 480 );
    setcolor( RGB(0xff, 0xff, 0xff) );
    setfillcolor( RGB(0, 0, 0xff) );
    setrendermode(RENDER_MANUAL);
    double r = 0;
    // main loop
    for ( ; is_run(); delay_fps(60) )
    {
        // update
        r += 0.02;
        if (r > PI * 2) r -= PI * 2;//set the angle back to the first quadrant
        // clear canvas
        cleardevice();//before every loop, clear the canvas so that new paint can be drawed
        // render
        paintstar(300, 200, 150, r);
    }
    return 0;
}

