#include "item.h"

Item::Item() : QGLWidget()
{
    pic = new QImage();
    t = new QTimer();
    vx = 0;
}

type Item::getType()
{
    return item_t;
}

void Item::genItem()
{

    glBindTexture(GL_TEXTURE_2D, this->tex);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, (GLsizei)this->pic->width(), (GLsizei)this->pic->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, this->pic->bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Item::drawItem()
{
    this->genItem();
    GLfloat cVertexArray[4][3];
    GLubyte cIndexArray[1][4];

    cVertexArray[0][0] = this->x-this->h;
    cVertexArray[0][1] = this->y-this->w;
    cVertexArray[0][2] = 0;

    cVertexArray[1][0] = this->x-this->h;
    cVertexArray[1][1] = this->y+this->w;
    cVertexArray[1][2] = 0;

    cVertexArray[2][0] = this->x+this->h;
    cVertexArray[2][1] = this->y+this->w;
    cVertexArray[2][2] = 0;

    cVertexArray[3][0] = this->x+this->h;
    cVertexArray[3][1] = this->y-this->w;
    cVertexArray[3][2] = 0;

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glBindTexture(GL_TEXTURE_2D, this->tex);

    GLfloat cTextureArray [8][2];

    cTextureArray[3][0] = 1.0;
    cTextureArray[3][1] = 0.0;

    cTextureArray[2][0] = 1.0;
    cTextureArray[2][1] = 1.0;

    cTextureArray[1][0] = 0.0;
    cTextureArray[1][1] = 1.0;

    cTextureArray[0][0] = 0.0;
    cTextureArray[0][1] = 0.0;

    cIndexArray[0][0] = 0;
    cIndexArray[0][1] = 3;
    cIndexArray[0][2] = 2;
    cIndexArray[0][3] = 1;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);
    glDisable(GL_BLEND);

    glBegin(GL_LINE_LOOP);
    glVertex3f(x-col_h, y-col_w, 0);
    glVertex3f(x-col_h, y+col_w, 0);
    glVertex3f(x+col_h, y+col_w, 0);
    glVertex3f(x+col_h, y-col_w, 0);
    glEnd();
}

int Item::side(Item *a, Item *b)
{
    if((a->y-a->col_w>=b->y+b->col_w-2)&&
            ((a->x-a->col_h<b->x+b->col_h)&&(a->x-a->col_h>b->x-b->col_h)||
             (a->x+a->col_h<b->x+b->col_h)&&(a->x+a->col_h>b->x-b->col_h))

            ) return 0;
    if((a->x-a->col_h<b->x+b->col_h)&&(a->x-a->col_h>b->x-b->col_h)) return 1;
    if ((a->x+a->col_h<b->x+b->col_h)&&(a->x+a->col_h>b->x-b->col_h)) return 2;

}
