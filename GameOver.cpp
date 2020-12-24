#include "GameOver.h"
#include "Game.h"
#include <QtMath>

extern Game * game;

GameOver::GameOver(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/background/GameOver.jpg"));
    setTransformOriginPoint(1050,1050);
    setRotation(0);
};
