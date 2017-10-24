#include "bullet.h"


Bullet::Bullet(float l, Enemy *e, int v)
{
    bullet = new QImage("bullet.png");
    *bullet = QGLWidget::convertToGLFormat(*bullet);
    pic = bullet;
    enemy = e;
    //hero = h1;
    x = l;
    y = -5;
    vect = v;//(enemy->x-hero->x)/abs(enemy->x-hero->x);
    vx = 0.1;
    //printf("________ %d __________", v);
    h = 4;
    w = 4;
    col_h = h;
    col_w = w;
    t = new QTimer();
    t->start(5);
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(move()));

}

type Bullet::getType()
{
    return bullet_t;
}

void Bullet::move()
{
    x+=vx*vect;
   // printf("   MOVES  %f %f %d", x, vx, vect);
}
