#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtOpenGL/QtOpenGL>
//#include "item.h"
#include "hero.h"
#include "back.h"
#include "ground.h"
#include "cloud.h"
#include "enemy.h"
#include "bullet.h"
#include "list.h"

class MainWindow : public QGLWidget
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QImage *background;
    QTimer* t, *intersect_timer;
    GLuint back_tex;
    float groundLevel;
    int bul_i;
    Hero* Knight;
    Back* background;
    Ground* ground[20];
    Cloud* cloud[6];
    Enemy *enemy;
    Bullet* bullet[20];
    List scene, *groundAssetCurr, *groundAssetPrev, *groundAssetNext;


private:
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);
    void timeMove();
    void shoot();
    void mousePressEvent(QMouseEvent *event);
    Bullet* ifShot(Bullet* b);
    void genGroundAsset();
private slots:
    void interaction();
signals:
    void enemyDeath();
};

#endif // MAINWINDOW_H
