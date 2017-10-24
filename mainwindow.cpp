#include "mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SingleBuffer),parent)
{
    //background = new QImage("back.png");

    background = new Back;
    scene.push_back(background);
    Knight = new Hero;
    scene.push_back(Knight);
    groundAssetCurr = new List;
    groundAssetPrev = new List;
    groundAssetNext = new List;
    for(int i = -100; i<=400; i+=10)  groundAssetCurr->push_back(new Ground(i,i));
   // for(int i = -300; i<=-100; i+=10)  groundAssetPrev->push_back(new Ground(i,i));
    //for(int i = 100; i<=300; i+=10)  groundAssetNext->push_back(new Ground(i,i));
    for (int i = 0; i<6; i++) scene.push_back(new Cloud);
    printf("((%d))", Knight->vect);
    enemy = new Enemy(Knight);
    scene.push_back(enemy);
    t = new QTimer();
    t->start(1);
    intersect_timer = new QTimer();
    intersect_timer->start(1);
    bul_i = 0;
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(update()));
    QObject::connect(intersect_timer, SIGNAL(timeout()), this, SLOT(interaction()));
    //bullet = NULL;
    QObject::connect(this, SIGNAL(enemyDeath()), enemy, SLOT(die()));

}

MainWindow::~MainWindow()
{
    
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //shoot();
}

void MainWindow::shoot()
{
    bullet[bul_i] = new Bullet(Knight->x, enemy, Knight->vect);
    scene.push_back(bullet[bul_i]);
    bul_i+=1;
}

void MainWindow::genGroundAsset()
{
//    if(Knight->x-groundAssetCurr->first->data->x<=0)
//    {
//        delete groundAssetPrev;
//        groundAssetPrev = new List(*groundAssetCurr);
//        delete groundAssetCurr;
//        groundAssetCurr = new List(*groundAssetNext);
//        delete groundAssetNext;
//        groundAssetNext = NULL;
//        for(int i = groundAssetCurr->last->data->x; i<=groundAssetCurr->last->data->x+100; i+=10) groundAssetNext->push_back(new Ground(i,i));
//    }
}

void MainWindow::interaction()
{
//    if(GetAsyncKeyState(VK_LEFT)&&!Knight->leftBound)
//    {
//        for(DynItem* temp = groundAssetCurr->first; temp; temp = temp->next)
//            if(temp->data->getType()!=hero_t&&temp->data->getType()!=back_t)
//            {
//                temp->data->x+=Knight->vx;
//            }
//        for(DynItem* temp = scene.first; temp; temp = temp->next)
//            if(temp->data->getType()!=hero_t&&temp->data->getType()!=back_t)
//            {
//                temp->data->x+=Knight->vx;
//            }

//        Knight->vect = -1, Knight->state = 1;
//    }
//    else if(GetAsyncKeyState(VK_RIGHT)&&!Knight->rightBound)
//    {
//        for(DynItem* temp =  groundAssetCurr->first; temp; temp = temp->next)
//            if(temp->data->getType()!=hero_t&&temp->data->getType()!=back_t)
//            {
//                temp->data->x-=Knight->vx;
//            }
//        for(DynItem* temp = scene.first; temp; temp = temp->next)
//            if(temp->data->getType()!=hero_t&&temp->data->getType()!=back_t)
//            {
//                temp->data->x-=Knight->vx;
//            }
//        Knight->vect = 1, Knight->state = 1;
//    }
//    else Knight->state = 0;

//    if(GetAsyncKeyState(VK_RIGHT)&&!Knight->rightBound) x = x+vx, vect = 1, state = 1;
//    else state = 0;
       //glOrtho(-100.0+Knight->x, 100.0+Knight->x, -100.0, 100.0, -10.0, 10.0);
    List downGroundHero = groundAssetCurr->collidingItems(Knight, ground_t, 0);
    List leftGroundHero = groundAssetCurr->collidingItems(Knight, ground_t, 1);
    List rightGroundHero = groundAssetCurr->collidingItems(Knight, ground_t, 2);
    //if(downGroundHero.size()==0) Knight->isGround = false;
    if(leftGroundHero.size()>0) Knight->leftBound = true;
    else Knight->leftBound = false;
    if(rightGroundHero.size()>0) Knight->rightBound = true;
    else Knight->rightBound = false;
    if(downGroundHero.size()>0) Knight->isGround = true, Knight->setGroundLevel(downGroundHero.first->data);
    else Knight->isGround = false;
    List downGroundEnemy = groundAssetCurr->collidingItems(enemy, ground_t, 0);
    List leftGroundEnemy = groundAssetCurr->collidingItems(enemy, ground_t, 1);
    List rightGroundEnemy = groundAssetCurr->collidingItems(enemy, ground_t, 2);
    if(leftGroundEnemy.size()>0) enemy->leftBound = true;
    else enemy->leftBound = false;
    if(rightGroundEnemy.size()>0) enemy->rightBound = true;
    else enemy->rightBound = false;
    if(downGroundEnemy.size()>0) enemy->isGround = true, enemy->setGroundLevel(downGroundEnemy.first->data);
    else enemy->isGround = false;

    intersect_timer->start(1);
}

void MainWindow::initializeGL()
{
    glClearColor(0.1, 0.5, 0.7, 1.0);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glLoadIdentity();

}

void MainWindow::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -10.0, 10.0);
    glViewport(0, 0, (GLint)w, (GLint)h);
}
void MainWindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //genGroundAsset();
//    background->drawItem();
//    //for(int i = 0; i<20; i++) ground[i]->drawItem();
//    for(int i = 0; i<6; i++) cloud[i]->drawItem();
//    Knight->drawItem();
//    for(int i = 0; i<bul_i; i++){bullet[i]=ifShot(bullet[i]); if(bullet[i]) bullet[i]->drawItem();}
    for(DynItem *temp = scene.first; temp; temp = temp->next) temp->data->drawItem();
    for(DynItem *temp = groundAssetCurr->first; temp; temp = temp->next) temp->data->drawItem();
            //gluLookAt(Knight->x, 0, 10, 0, 0,0, 0,1,0);
}

Bullet* MainWindow::ifShot(Bullet* b)
{
//    if(b&&enemy&&abs(enemy->x-b->x)<0.5)
//    {
//        enemy->Health-=1;
//        b->vx=0;
//        delete b;
//        b = 0;
//        printf("  FUCK  ");
//        if(enemy->Health == 0) emit enemyDeath();

//    }
//    if(b)
//    if(b->x<-10 || b->x>10){
//        //delete mass[j];
//        //for(int j = i; i<bul_i-1; j++) delete mass[j], mass[j] = mass[j+1];
//        delete b;
//        b = NULL;
//        bul_i--;
//    }
//    return b;


}
