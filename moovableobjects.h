#ifndef MOOVABLEOBJECTS_H
#define MOOVABLEOBJECTS_H
#include "item.h"

class MoovableObjects : public Item
{
public:
    MoovableObjects();
    int vect, Health, Power;
    bool alive;
    QTimer *anim;
    int isLeft;
    bool isGround, leftBound, rightBound, isJumping;
    float ground_level, speedX, speedY,  vx, vy;
    void gravity();
    void setGroundLevel(Item *a);
};

#endif // MOOVABLEOBJECTS_H
