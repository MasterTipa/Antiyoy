#include "CreateWorriarB.h"
#include "Game.h"

extern Game * game;

CreateWorriarB::CreateWorriarB(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
        setPixmap(QPixmap(":/worriar/BluePerson.png"));
}

void CreateWorriarB::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->buildB && game->way){
       if (game->way)
        game->scene->removeItem(this);
        game->buildB = new CreateWorriarB();
        game->setCursor(QString(":/worriar/BluePerson.png"));
    }
}
