#include "hero.h"
#include <math.h>

Hero::Hero() : MoovableObjects()
{
    run[0] = new QImage("i0.png");
    run[1] = new QImage("i1.png");
    run[2] = new QImage("i2.png");
    run[3] = new QImage("i3.png");
    run[4] = new QImage("i4.png");
    run[5] = new QImage("i5.png");
    run[6] = new QImage("i6.png");
    run[7] = new QImage("i7.png");
    run[8] = new QImage("i8.png");
    run[9] = new QImage("i9.png");

    idle[0] = new QImage("h0.png");
    idle[1] = new QImage("h1.png");
    idle[2] = new QImage("h2.png");
    idle[3] = new QImage("h3.png");
    idle[4] = new QImage("h4.png");
    idle[5] = new QImage("h5.png");
    idle[6] = new QImage("h6.png");
    idle[7] = new QImage("h7.png");
    idle[8] = new QImage("h8.png");
    idle[9] = new QImage("h9.png");
    //idle[10] = new QImage("h10.png");

    jumping[0] = new QImage("j0.png");
    jumping[1] = new QImage("j1.png");
    jumping[2] = new QImage("j2.png");
    jumping[3] = new QImage("j3.png");
    jumping[4] = new QImage("j4.png");
    jumping[5] = new QImage("j5.png");
    jumping[6] = new QImage("j6.png");
    jumping[7] = new QImage("j7.png");
    jumping[8] = new QImage("j8.png");
    jumping[9] = new QImage("j9.png");

    for(int i  = 0; i<10; i++) *run[i] = QGLWidget::convertToGLFormat(*run[i]);
    for(int i  = 0; i<10; i++) *idle[i] = QGLWidget::convertToGLFormat(*idle[i]);
    for(int i  = 0; i<10; i++) *jumping[i] = QGLWidget::convertToGLFormat(*jumping[i]);
    rightBound = leftBound = false;
    //pic = new QImage();
    pic  = run[0];
    isJumping = false;
    jumpTimer = new QTimer();
    t = new QTimer();
    t->start(10);
    anim = new QTimer();
    anim->start(50);
    x = 0;
    y = -4.3;
    speedX = 1;
    speedY = 0.1;
    vx = 1;
    vy = 0;
    h = 10;
    col_h = h/2-0.1;
    w = 20;
    col_w = w;
    i = 0;
    ground_level = -6-w;
    accel = 0.0002;
    vect = -1;
    ti = 0;
    isGround = false;
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(move()));
    QObject::connect(anim, SIGNAL(timeout()), this, SLOT(animator()));
    QObject::connect(jumpTimer, SIGNAL(timeout()), this, SLOT(jump()));
    //QObject::connect(t, SIGNAL(timeout()), this, SLOT(gravity()));
}

type Hero::getType()
{
    return hero_t;
}

void Hero::actions()
{

}



void Hero::animator()
{
    if(state == 0)
        if(i<9) i+=1, pic = run[i]; else i = 0, pic = run[0];
    else if(state == 1)
        if(i<9) i+=1, pic = idle[i]; else i = 0, pic = idle[0];
    else if(state == 2)
        if(i<9) i+=1, pic = jumping[i]; else i = 0, pic = jumping[0];
 }

void Hero::jump()
{
    printf("\nD %f, %f", y+(vy*ti - accel*ti*ti/2), ground_level);
    if(!isGround && y+(vy*ti - accel*ti*ti/2)+0.3>=ground_level)
    {
        isJumping = true;
        ti+=0.7;
        state = 2;
        float dy = vy*ti - accel*ti*ti/2;
        y = y + dy;
        vy-=accel*ti;
        printf("\n\n\nAAAAAA\n\n\n");
        jumpTimer->start(5);
    }
    else
    {
       // printf("\n\n\nAAAAAA\n\n\n");
        //isGround = true;
        isJumping = false;
        jumpTimer->stop();
        ti = 0;
        vy = 0;
        y = ground_level;
        state = 0;

    }
}


void Hero::move()
{
    if(GetAsyncKeyState(VK_LEFT)&&!leftBound) x = x-vx, vect = -1, state = 1;
    else
    if(GetAsyncKeyState(VK_RIGHT)&&!rightBound) x = x+vx, vect = 1, state = 1;
    else state = 0;
    if(GetAsyncKeyState((VK_SPACE))&& isGround)vy = speedY, isGround=false, isJumping = true, jump();
    if(vect*isLeft>0) reverse(), isLeft = -isLeft;
    gravity();
    t->start(5);
    //animator();
}

void Hero::reverse()
{
    for (int i = 0; i<10; i++) *run[i] = run[i]->mirrored(true, false);
    for (int i = 0; i<10; i++) *idle[i] = idle[i]->mirrored(true, false);
    for (int i = 0; i<10; i++) *jumping[i] = jumping[i]->mirrored(true, false);
}
