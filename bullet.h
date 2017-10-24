#ifndef BULLET_H
#define BULLET_H
#include "item.h"
#include "enemy.h"

class Bullet : public Item
{
    Q_OBJECT
public:
    Bullet(float l, Enemy *e, int v);
    QImage *bullet;
    Enemy* enemy;
    Hero* hero;
    int vect;
    type getType();

public slots:
    void move();

};

#endif // BULLET_H
