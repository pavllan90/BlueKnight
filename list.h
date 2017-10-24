#ifndef LIST_H
#define LIST_H
#include "dynitem.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

class List
{
public:
    List();
    List(Item *a);
    List(const List &a);
    ~List();
    void push_front(Item *a);
    void push_back(Item *a);
    void del_back();
    void del_front();
    DynItem* pop_front();
    DynItem* pop_back();
    DynItem operator [](int i);
    DynItem *first, *last;
    int size();
    bool isEmpty();
    List collidingItems(Item *a, type mode, int side);
};

#endif // LIST_H
