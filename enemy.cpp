#include "enemy.h"


Enemy::Enemy(Hero *knight)
{
    idle[0] = new QImage("ei0.png");
    idle[1] = new QImage("ei1.png");
    idle[2] = new QImage("ei2.png");
    idle[3] = new QImage("ei3.png");
    idle[4] = new QImage("ei4.png");
    idle[5] = new QImage("ei5.png");
    idle[6] = new QImage("ei6.png");
    idle[7] = new QImage("ei7.png");
    idle[8] = new QImage("ei8.png");
    idle[9] = new QImage("ei9.png");
    idle[10] = new QImage("ei10.png");
    idle[11] = new QImage("ei11.png");

    run[0] = new QImage("r0.png");
    run[1] = new QImage("r1.png");
    run[2] = new QImage("r2.png");
    run[3] = new QImage("r3.png");
    run[4] = new QImage("r4.png");
    run[5] = new QImage("r5.png");
    run[6] = new QImage("r6.png");
    run[7] = new QImage("r7.png");
    run[8] = new QImage("r8.png");
    run[9] = new QImage("r9.png");
    run[10] = new QImage("r10.png");
    run[11] = new QImage("r11.png");
    run[12] = new QImage("r12.png");
    run[13] = new QImage("r13.png");
    run[14] = new QImage("r14.png");
    run[15] = new QImage("r15.png");

    fight[0] = new QImage("ef0.png");
    fight[1] = new QImage("ef1.png");
    fight[2] = new QImage("ef2.png");
    fight[3] = new QImage("ef3.png");
    fight[4] = new QImage("ef4.png");
    fight[5] = new QImage("ef5.png");
    fight[6] = new QImage("ef6.png");
    fight[7] = new QImage("ef7.png");
    fight[8] = new QImage("ef8.png");
    fight[9] = new QImage("ef9.png");
    fight[10] = new QImage("ef10.png");
    fight[11] = new QImage("ef11.png");

    dying[0] = new QImage("ed0.png");
    dying[1] = new QImage("ed1.png");
    dying[2] = new QImage("ed2.png");
    dying[3] = new QImage("ed3.png");
    dying[4] = new QImage("ed4.png");
    dying[5] = new QImage("ed5.png");
    dying[6] = new QImage("ed6.png");
    dying[7] = new QImage("ed7.png");
    dying[8] = new QImage("ed8.png");
    dying[9] = new QImage("ed9.png");
    dying[10] = new QImage("ed10.png");
    dying[11] = new QImage("ed11.png");
    dying[12] = new QImage("ed12.png");
    dying[13] = new QImage("ed13.png");
    dying[14] = new QImage("ed14.png");
    dying[15] = new QImage("ed15.png");
    dying[16] = new QImage("ed16.png");
    dying[17] = new QImage("ed17.png");
    dying[18] = new QImage("ed18.png");
    dying[19] = new QImage("ed19.png");

    for (int i = 0; i<12; i++) *idle[i] = QGLWidget::convertToGLFormat(*idle[i]);
    for (int i = 0; i<16; i++) *run[i] = QGLWidget::convertToGLFormat(*run[i]);
    for (int i = 0; i<12; i++) *fight[i] = QGLWidget::convertToGLFormat(*fight[i]);
    for (int i = 0; i<20; i++) *dying[i] = QGLWidget::convertToGLFormat(*dying[i]);

    k = new Hero;
    k = knight;
    pic = idle[0];
    x = -7;
    y = -6;
    speedX = 0.1;
    speedY = 0.1;
    vx =0.1;
    vy = 0;
    h = 10;
    w = 18;
    j = 0;
    col_h = 5;
    col_w = 18;
    anim = new QTimer();
    anim->start(50);
    alive = true;
    ground_level = -6-w;
    //kx = x1;
    //ky = y1;
    vect = 1;
    t = new QTimer();
    t->start(20);
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(move()));
    QObject::connect(anim, SIGNAL(timeout()), this, SLOT(animator()));
}

void Enemy::moveUp()
{
    y+=3*speedY;
}


void Enemy::animator()
{
    if(!alive)
    {
        w=3;
        if(j<19) j+=1, pic = dying[j], anim->start(50); else anim->stop();// finalCountdown->start(3000);
    }
    else
    {
        if(state == 0)
            if(j<11) j+=1, pic = idle[j]; else j = 0, pic = idle[0];
        if(state == 1)
            if(j<15) h = 10, w = 18, j+=1, pic = run[j]; else j = 0, pic = run[0];
        if( state==2 )
            if(j<11)h = 18, w = 18, j+=1, pic = fight[j]; else j = 0, pic = fight[0];
        anim->start(50);
    }
}

void Enemy::move()
{
    if(alive){
        if(rightBound||leftBound) moveUp();
        else gravity();
        if(abs(x-k->x)<=0.5) state = 2; else
        if(x<k->x&&!rightBound) x+=vx, vect = 1, state = 1;
        else if(x>k->x&&!leftBound) x-=vx, vect = -1,  state = 1;
    if(vect*isLeft<0&&abs(k->x-x)>0.05) reverse(), isLeft = -isLeft;
    }

}

type Enemy::getType()
{
    return enemy_t;
}

void Enemy::reverse()
{
    if(alive)
    {
        for(int i = 0; i<12; i++) *idle[i] = idle[i]->QImage::mirrored(true, false);
        for(int i = 0; i<16; i++) *run[i] = run[i]->QImage::mirrored(true, false);
        for(int i = 0; i<12; i++) *fight[i] = fight[i]->QImage::mirrored(true, false);
        for(int i = 0; i<20; i++) *dying[i] = dying[i]->QImage::mirrored(true, false);
    }
}

void Enemy::die()
{
    alive = false;
}
