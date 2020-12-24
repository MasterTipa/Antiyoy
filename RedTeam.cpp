#include "RedTeam.h"
#include "Game.h"
#include <QtMath>

extern Game * game;

RedTeam::RedTeam(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/squads/Red.png"));
    setTransformOriginPoint(50,50);
    setRotation(0);
};
