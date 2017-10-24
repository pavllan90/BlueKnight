#include "dynitem.h"
#include <stdio.h>
#include <iostream>

DynItem::DynItem()
{
    next = NULL;
    prev = NULL;
}

DynItem::DynItem(Item *a)
{
    data = a;
}

DynItem::DynItem(const DynItem &a)
{
    data = a.data;
    next = a.next;
    prev = a.prev;
}

DynItem::~DynItem()
{

}
