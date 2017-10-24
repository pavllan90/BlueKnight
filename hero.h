#ifndef HERO_H
#define HERO_H
#include "moovableobjects.h"
#include <QTimer>
#include <QKeyEvent>


class Hero : public MoovableObjects
{
    Q_OBJECT
public:
    Hero();
    QImage *run[10], *idle[11], *jumping[10];
    QTimer *jumpTimer;
    int i, state;
    float accel, ti;


public slots:
    void animator();
    void move();
    void jump();
    void reverse();
    void actions();
    type getType();
};

#endif // HERO_H
