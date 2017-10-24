#ifndef BACK_H
#define BACK_H
#include "item.h"

class Back : public Item
{
public:
    Back();
    QImage* back;
    type getType();
};

#endif // BACK_H
