#ifndef ENEMY_H
#define ENEMY_H

#include "moovableobjects.h"
#include "hero.h"

class Enemy : public MoovableObjects
{
    Q_OBJECT
public:
    Enemy(Hero *knight);
    Hero* k;
    QImage *run[16], *idle[12], *fight[12], *dying[20];
    float kx, ky;
    int  j, state;
    type getType();
public slots:
    void move();
    void moveUp();
    void reverse();
    void animator();
    void die();
};

#endif // ENEMY_H
