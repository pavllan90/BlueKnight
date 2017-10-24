#include "ground.h"
#include <time.h>

Ground::Ground(int i, int j)
{
    ground = new QImage("ground.png");
    *pic = QGLWidget::convertToGLFormat(*ground);
    vx = 0;
    vy = 0;
    x = i;
    //srand(time(NULL));
    y = -90+20*(rand()%2);
    h = 5;
    w = 10;
    col_h = h;
    col_w = w;
}

type Ground::getType()
{
    return ground_t;
}
