#include "ScoreR.h"
#include <QFont>
#include "Game.h"

extern Game * game;

ScoreR::ScoreR(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 1;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void ScoreR::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    if (score>=game->lands/2)
        {
            setPlainText(QString("Score: Wictory"));
            game->gameover=true;
        }
}

void ScoreR::decrease()
{
    score--;
    setPlainText(QString("Score: ") + QString::number(score));
}

int ScoreR::getScore(){
    return score;
}
