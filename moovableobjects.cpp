#include "moovableobjects.h"

MoovableObjects::MoovableObjects()
{
    isLeft = 1;
}

void MoovableObjects::gravity()
{
    if(!isGround&&!isJumping) y-=0.6, vx = speedX;
    else if(!isJumping) y = ground_level;
}

void MoovableObjects::setGroundLevel(Item *a)
{
    ground_level = a->y+a->w+w;
}
