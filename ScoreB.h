#ifndef SCOREB_H
#define SCOREB_H

#include <QGraphicsTextItem>
#include "GameOver.h"
class ScoreB: public QGraphicsTextItem{
public:
    ScoreB(QGraphicsItem * parent=0);
    void increase();
    void decrease();
    int getScore();
    GameOver * gameOver;
private:
    int score;
};

#endif // SCOREB_H
