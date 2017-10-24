#ifndef CLOUD_H
#define CLOUD_H

#include "moovableobjects.h"

class Cloud : public MoovableObjects
{
    Q_OBJECT
public:
    Cloud();
    QImage* cloud;
    type getType();
public slots:
    void move();
};

#endif // CLOUD_H
