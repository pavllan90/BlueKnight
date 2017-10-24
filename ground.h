#ifndef GROUND_H
#define GROUND_H

#include "item.h"

class Ground : public Item
{
public:
    Ground(int i, int j);
    QImage *ground;
    type getType();
};

#endif // GROUND_H
