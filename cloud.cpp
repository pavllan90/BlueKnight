#include "cloud.h"

Cloud::Cloud()
{
    cloud = new QImage("cloud.png");
    *cloud = QGLWidget::convertToGLFormat(*cloud);
    pic = cloud;
    x = rand()%90-90;
    y = rand()%90-20;
    vx = float(rand()%10-10)/100;
    vy = 0;
    h = 10;
    w = 10;
    col_h = h;
    col_w = w;
    t->start(5);
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(move()));
}

void Cloud::move()
{
    if(x<-90 || x>90) vx=-vx;
    x+=vx;
}

type Cloud::getType()
{
    return cloud_t;
}
