#ifndef ITEM_H
#define ITEM_H
//#include "list.h"
#include <QtOpenGL/QtOpenGL>
#include <QGLWidget>

enum type{
    item_t, bullet_t, cloud_t, enemy_t, ground_t, hero_t, back_t
};

class Item : public QGLWidget
{
public:
    Item();
    float x, y, h, w;
    float col_h, col_w;
    QTimer *t;
    GLuint tex;
    QImage *pic;
    void drawItem();
    void genItem();
    int side(Item *a, Item *b);
    virtual type getType();
};

#endif // ITEM_H
