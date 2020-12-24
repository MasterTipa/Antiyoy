#include "ScoreToWin.h"
#include <QFont>
#include "Game.h"

extern Game * game;

ScoreToWin::ScoreToWin(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Score to Win: ") + QString::number(score));
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("times",16));
}

int ScoreToWin::setScore(int scr)
{
    score=scr;
    setPlainText(QString("Score to Win: ") + QString::number(score));
    return score;
}
