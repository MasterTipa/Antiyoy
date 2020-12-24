#include "WinTextB.h"
#include <QFont>
#include "Game.h"

extern Game * game;

WinTextB::WinTextB(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("Blue player Win"));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("times",50));
}
