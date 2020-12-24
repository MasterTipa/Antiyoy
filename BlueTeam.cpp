#include "BlueTeam.h"
#include "Game.h"
#include <QtMath>

extern Game * game;

BlueTeam::BlueTeam(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/squads/Blue.png"));
    setTransformOriginPoint(50,50);
    setRotation(0);

};
