#include "WinTextR.h"
#include <QFont>
#include "Game.h"

extern Game * game;

WinTextR::WinTextR(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
     setPlainText(QString("Red player Win"));
     setDefaultTextColor(Qt::red);
     setFont(QFont("times",50));
}
