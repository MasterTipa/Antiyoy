#ifndef SCORER_H
#define SCORER_H

#include <QGraphicsTextItem>
#include "GameOver.h"
class ScoreR: public QGraphicsTextItem{
public:
    ScoreR(QGraphicsItem * parent=0);
    void increase();
    void decrease();
    int getScore();
    GameOver * gameOver;
private:
    int score;
};

#endif // SCORER_H
