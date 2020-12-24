#include "RedPerson.h"
#include "Game.h"
#include <QtMath>

extern Game * game;

RedPerson::RedPerson(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
   // setPos(500,500);
    setPixmap(QPixmap(":/worriar/RedPerson.png"));//текстура
    setTransformOriginPoint(50,50);//размер
    setRotation(0);//поворот

};
