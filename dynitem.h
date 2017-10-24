#ifndef DYNITEM_H
#define DYNITEM_H
#include "hero.h"

class DynItem
{
public:
    DynItem();
    DynItem(Item *a);
    DynItem(const DynItem &a);
    ~DynItem();
    DynItem *next, *prev;
    Item *data;
};

#endif // DYNITEM_H
