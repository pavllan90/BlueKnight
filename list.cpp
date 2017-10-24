#include "list.h"
#include <stdio.h>

List::List()
{
    first=last=NULL;
}

List::List(Item *a)
{
    push_front(a);
}

List::List(const List &a) : first(a.first) , last(a.last) { }

List::~List()
{
    DynItem* a = first;
    for(; a!=last; a=a->next) delete a->prev;
    delete a;
}

bool List::isEmpty()
{
    if(this->first)
    {
        std::cout<<"Not empty"<<std::endl;
        return false;
    }
    else
    {
        std::cout<<"Empty"<<std::endl;
        return true;
    }
}
int List::size()
{
    DynItem* temp = first;
    int count = 0;
    while(temp)
    {
        count+=1;
        temp = temp->next;
    }
    //std::cout<<"Size is "<<count<<std::endl;
    return count;
}

void List::del_back()
{
    if(last)
    {
        DynItem* temp = last;
        if(last->prev)
        {
            last = last->prev;
            delete temp;
            last->next = NULL;
        }
        else delete last, last = first = NULL;
    }
}

void List::del_front()
{
    if(first)
    {
        DynItem* temp = first;
        if(first->next)
        {
            first = first->next;
            delete temp;
            first->prev = NULL;
        }
        else delete first, last = first = NULL;
    }
}

DynItem List::operator [](int i)
{
    DynItem *temp = first;
    for(int j = 0; j<i; j++) temp = temp->next;
    return *temp;
}

void List::push_front(Item *a)
{
    DynItem *temp = new DynItem;
    temp->data = a;
    if(!(this->first))
    {
        qDebug("Here");
        this->first = this->last = temp;
    }
    else
    {
        qDebug("there");
        temp->next=first;
        first->prev = temp;
        first=temp;
    }
}

void List::push_back(Item *a)
{
    DynItem *temp = new DynItem;
    temp->data = a;
    if(!(this->last))
    {
        this->first = this->last = temp;
    }
    else
    {
        temp->prev=last;
        last->next = temp;
        last=temp;
    }
}

DynItem* List::pop_front()
{
    return this->first;
}

DynItem* List::pop_back()
{
    return this->last;
}

List List::collidingItems(Item *a, type mode, int side)
{
    List result;
    float a_left = a->x-a->col_h, a_right = a->x+a->col_h, a_top = a->y+a->col_w, a_bottom = a->y-a->col_w;
    for(DynItem* i = first; i; i=i->next)
    {
        float b_left = i->data->x - i->data->col_h;
        float b_right = i->data->x + i->data->col_h;
        float b_top = i->data->y+i->data->col_w;
        float b_bottom = i->data->y-i->data->col_w;
        if(!(a_left>b_right||
        a_right<b_left
        ||a_top<b_bottom
             ||a_bottom>b_top)&&i->data->getType() == mode && (a->side(a, (i->data))==side ))
        {
            result.push_back(i->data);
        }
    }
    return result;
}
