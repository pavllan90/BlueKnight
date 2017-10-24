#include "back.h"

Back::Back()
{
    back = new QImage("back.png");
    pic = back;
    *pic = QGLWidget::convertToGLFormat(*pic);
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
    h = 100;
    w = 100;
    col_h = h;
    col_w = w;
}

type Back::getType()
{
    return back_t;
}
