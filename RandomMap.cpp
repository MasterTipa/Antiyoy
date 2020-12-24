#include "RandomMap.h"
#include "Game.h"
#include <QtMath>

extern Game * game;

RandomMap::RandomMap(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/squads/sand.jpg"));
    setTransformOriginPoint(50,50);
    setRotation(0);


};
