#include "ScoreB.h"
#include <QFont>
#include "Game.h"

extern Game * game;

ScoreB::ScoreB(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 1;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("times",16));
}

void ScoreB::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    if (score>=game->lands/2)
    {
        setPlainText(QString("Score: Wictory"));
        game->gameover=true;
    }
}

void ScoreB::decrease()
{
    score--;
    setPlainText(QString("Score: ") + QString::number(score));
}

int ScoreB::getScore(){
    return score;
}
