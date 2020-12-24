#include "CreateWorriarR.h"
#include "Game.h"

extern Game * game;

CreateWorriarR::CreateWorriarR(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
        setPixmap(QPixmap(":/worriar/RedPerson.png"));
}

void CreateWorriarR::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->buildR){
       if (game->way==false)
        game->scene->removeItem(this);
        game->buildR = new CreateWorriarR();
        game->setCursor(QString(":/worriar/RedPerson.png"));

    }
}
