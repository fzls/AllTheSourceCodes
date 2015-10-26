#include <graphics.h>
#include <ege/fps.h>
#include <math.h>

#define myrand(m)                 ((float)random(10000) * m / 10000.0f)
#define IsCrash(a, b)             ((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y) < (a.r + b.r)*(a.r + b.r))
#define IsWEdge(a)               (a.x < a.r || a.x >= 640-a.r)
#define IsHEdge(a)               (a.y < a.r || a.y >= 480-a.r)
#define IsEdge(a)                 (IsWEdge(a) || IsHEdge(a))
#define Distance(x1, y1, x2, y2) (((x1) - (x2))*((x1) - (x2)) + ((y1) - (y2))*((y1) - (y2)))


typedef struct {
    float x, y;
    float vx, vy;
    int r;
    int color;
} Obj;


//定义一个AniObj类
class AniObj {
public:
    bool resmouse(mouse_msg mouse, double dx, double dy)
    {
        double f = 0.9;
        if (mouse.msg == mouse_msg_down)
        {
            if ( isCrash(mouse.x, mouse.y) ) //如果鼠标的位置在圆内。。
            {
                this->vx = 0;
                vy = 0;
                x = mouse.x;
                y = mouse.y;
                goon = 0;
                return 1;
            }
        }
        else if (mouse.msg == mouse_msg_up)
        {
            goon = 1;
            return 0;
        }
        else if (mouse.msg == mouse_msg_move)
        {
            if (dx * dx + dy * dy > vx * vx + vy * vy)
            {
                vx = dx;
                vy = dy;
            }
            else
            {
                vx *= f;
                vy *= f;
            }
            x = mouse.x;
            y = mouse.y;
            goon = 0;
            return 1;
        }
        else if (! goon)
        {
            vx *= f;
            vy *= f;
        }
        return 0;
    }

bool isCrash(int _x, int _y)
        {
            double dx = _x - this->x, dy = _y - this->y;
            return dx * dx + dy * dy < r * r;
        }    

    void dealMouse(Obj* ball)
    {
        static int iCapture = -1, mx, my;
        int i;
        mouse_msg mouse = {0};
        while (mousemsg())
        {
            double dx, dy;
            mouse = getmouse();
            dx = (mouse.x - mx) * 1.0f;
            dy = (mouse.y - my) * 1.0f;
            mx = mouse.x;
            my = mouse.y;

            if (iCapture == -1 && mouse.msg == mouse_msg_down)
            {
                for (i = 20 - 1; i > -1; --i)
                    if (ball[i].resmouse(mouse, dx, dy))
                    {
                        iCapture = i;
                        break;
                    }
            }
            else if (iCapture >= 0 && (mouse.msg == mouse_msg_up || mouse.msg == mouse_msg_move) )
            {
                if (ball[iCapture].resmouse(mouse, dx, dy) == 0)
                    iCapture = -1;
            }
        }
        if (iCapture >= 0)
        {
            mouse.msg = (mouse_msg_e)0;
            ball[iCapture].resmouse(mouse, 0, 0);
        }
    }






    AniObj() {
        n = 8;
        int i, j;
        bool goon;
        for ( i = 0; i < n; i++ ) {
            do {
                goon = false;
                obj[i].x = ( float )random( getwidth() );
                obj[i].y = ( float )random( getheight() );
                obj[i].r = random( 40 ) + 20;
                if ( IsEdge( obj[i] ) )
                    goon = true;
                else if ( i != 0 )
                    for ( j = i - 1; j >= 0; j-- )
                        if ( IsCrash( obj[i], obj[j] ) ) {
                            goon = true;
                            break;
                        }
            } while ( goon );
            obj[i].vx = obj[i].vy = 0.0f;
            obj[i].color = EGEAGRAY( 0xff, HSVtoRGB( myrand( 360.0f ), 1.0f, 1.0f ) );
        }
    }

    //更新位置等相关属性
    void updateobj() {
        dealMouse(obj);
        int i, j;
        for ( i = 0; i < n; i++ ) {
            // update the vx ,x , y
            obj[i].vy += 0.05f;
            obj[i].x += obj[i].vx;
            obj[i].y += obj[i].vy;
            // if the ball is out of area, turn direction
            if ( obj[i].y >= 480 - obj[i].r && obj[i].vy > 0 ) {
                obj[i].y -= obj[i].vy;
                obj[i].vy = - obj[i].vy;
            }
            if ( obj[i].x < obj[i].r && obj[i].vx < 0 ) obj[i].vx = - obj[i].vx;
            if ( obj[i].x >= 640 - obj[i].r && obj[i].vx > 0 ) obj[i].vx = - obj[i].vx;
        }
        for ( i = 1; i < n; i++ )
            for ( j = i - 1; j >= 0; j-- )//if two ball crashed and is moving toward each other,then they crashed.
                if ( IsCrash( obj[i], obj[j] ) &&
                        ( Distance( obj[i].x, obj[i].y, obj[j].x, obj[j].y ) >
                          Distance( obj[i].x + obj[i].vx, obj[i].y + obj[i].vy, obj[j].x + obj[j].vx, obj[j].y + obj[j].vy )
                        )
                   )
                    Crash( obj[i], obj[j] );
    }

    //根据属性值绘画
    void drawobj() {
        for ( int i = 0; i < n; i++ ) {
            setfillcolor( obj[i].color );
            ege_fillellipse( obj[i].x - obj[i].r, obj[i].y - obj[i].r,
                             obj[i].r * 2, obj[i].r * 2 );
        }
    }

    ~AniObj() {
    }

private:
    void Crash( Obj &a, Obj &b ) {
        //using physical knowledge to sove this problem
        float ma = a.r * a.r, mb = b.r * b.r;

        float sx = a.x - b.x;
        float sy = a.y - b.y;
        float s1x = sx / sqrt( sx * sx + sy * sy );
        float s1y = sy / sqrt( sx * sx + sy * sy );
        float t1x = -s1y;
        float t1y = s1x;
        //calculate the component velocity of the two ball in the direction of the line between two center of balls and the vertical direction to the previous direction
        float vas = a.vx * s1x + a.vy * s1y;
        float vat = a.vx * t1x + a.vy * t1y;
        float vbs = b.vx * s1x + b.vy * s1y;
        float vbt = b.vx * t1x + b.vy * t1y;
        // the below might be the process of calculating the final velocity of the balls after they crashed.
        float vasf = ( 2 * mb * vbs + vas * ( ma - mb ) ) / ( ma + mb );
        float vbsf = ( 2 * ma * vas - vbs * ( ma - mb ) ) / ( ma + mb );

        float nsx = vasf * s1x;
        float nsy = vasf * s1y;
        float ntx = vat * t1x;
        float nty = vat * t1y;

        a.vx = nsx + ntx;
        a.vy = nsy + nty;

        nsx = vbsf * s1x;
        nsy = vbsf * s1y;
        ntx = vbt * t1x;
        nty = vbt * t1y;

        b.vx = nsx + ntx;
        b.vy = nsy + nty;
    }

private:
    Obj obj[20];
    int n;
};

int main() {
    setinitmode( INIT_ANIMATION );
    initgraph( 640, 480 );
    randomize(); //初始化随机种子

    AniObj aniobj; //定义对象
    fps f;
    ege_enable_aa( true );

    for ( ; is_run(); delay_fps( 120 ) ) {
        aniobj.updateobj(); //更新位置
        cleardevice();
        aniobj.drawobj(); //绘画
    }

    closegraph();
    return 0;
}

