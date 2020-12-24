#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWidget>
#include <QGraphicsScene>
#include <QString>
#include "CreateWorriarR.h"
#include "CreateWorriarB.h"
#include "ScoreR.h"
#include "ScoreB.h"
#include "ScoreToWin.h"
#include "RandomMap.h"
#include "RedTeam.h"
#include "BlueTeam.h"
#include "CreateWorriarR.h"
#include "GameOver.h"
#include "WinTextR.h"
#include "WinTextB.h"

class Game: public QGraphicsView
{
  public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    CreateWorriarR * buildR;
    CreateWorriarB * buildB;
    WinTextR * winTextR;
    WinTextB * winTextB;
    ScoreR * scoreR;
    ScoreB * scoreB;
    ScoreToWin * scoreToWin;
    GameOver * gameOver;
    bool way=false;
    bool gameover=false;
    char** maps;
    int coordinate[4];
    int lands=0;
    virtual void setCursor(QString filename);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent *event);
    void random_map();
    void set_start_position_red(int m_dot,int n_dot);
    void set_start_position_blue(int m_dot,int n_dot);
private:
    int sch1=1;
    int sch2=1;


};


#endif // WINDOW_H
